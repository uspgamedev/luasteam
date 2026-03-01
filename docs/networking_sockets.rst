#######################
ISteamNetworkingSockets
#######################

This allows using the Steam Networking Sockets API. It's a protocol on top of UDP without the caveats of TCP (very slow) and optimized for the demands of video game traffic. Supports both reliable and unreliable traffic.

There are two ways to use it.

    * Classic Bind/connect to sockets and send/receive data over UDP. You are going to use IPs and ports as expected.
    * P2P using the the steam network. In this case, you are going to connect directly to other steam users. Valve will handle all verification/authentication/encryption/NAT-punching issues for you and carry the traffic through the steam network.

Read more at https://partner.steamgames.com/doc/features/multiplayer/steamdatagramrelay.

List of Functions
-----------------
* :func:`NetworkingSockets.SendMessages`
* :func:`NetworkingSockets.ReceiveMessagesOnPollGroup`

Function Reference
------------------
.. function:: NetworkingSockets.SendMessages()

    :param int n: The number of messages you are going to send
    :param table messages: A number indexed table with all messages you want to send. Indices from 1..n need to exist. Each message is a table with the following keys:
        
            * **conn** - The id of the connection to send a message to
            * **msg** - The message to send. Can be any length (up to configured SendBufferSize), splitting will be handled by the library
            * **flag** - A flag to specify how the message should be sent. See :func:`NetworkingSockets.SendMessageToConnection` for details

    :returns: (`table`) Result table with ``true`` or ``false`` for each message, indexed 1..n, e.g. ``{ 1 = true, 2 = false }``
    :SteamWorks: `SendMessages <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#SendMessages>`_

    This is a more efficient way to send out messages. E.g. you could gather all messages generated in an update cycle and then send them out all in one go using this method instead of dispatching them individually with :func:`NetworkingSockets.SendMessageToConnection`.

**Example**::

    local messages = {}
    messages[1] = { conn = connection1, msg = "Hello!", flag = Steam.NetworkingSockets.flags.Send_Reliable }
    messages[2] = { conn = connection2, msg = "World", flag = Steam.NetworkingSockets.flags.Send_Reliable }
    local result = Steam.NetworkingSockets.SendMessages(#messages, messages)

.. function:: NetworkingSockets.ReceiveMessagesOnPollGroup()

    :param int pollGroup: The poll group to receive messages from
    :returns: (`int`, `table`) Returns two parameters

        * **n** - The number of messages received. ``-1`` if the passed poll group id is invalid (the table is nil in this case).
        * **messages** - A 1..n index table of messages. Reliable messages are in order in relation to each other. Unreliable messages might be in any order inside the table. Each message is a table with a ``conn`` and a ``msg`` field.

    :SteamWorks: `ReceiveMessagesOnPollGroup <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#ReceiveMessagesOnPollGroup>`_

    This is the poll group equivalent to :func:`NetworkingSockets.ReceiveMessagesOnConnection`. The advantage of this version is that you can just get all messages to any connection assigned. If you expect larger number of connections, it's much more efficient to create one or more poll groups and just poll the group instead of having to check messages for every connection individually.

    Receive all the messages that are waiting on the given poll group **up to 32**. Call this repeatedly until ``n < 32``

    A result table might look like this: ``{ 1 = { conn = 5235, msg = "A message" }, 2 = { conn = 5235, msg = "Another message" }, 3 = { conn = 5678, msg = "Yet another message" } }``
    
    Iterate with ipairs to retain the order any reliable messages were received in.

**Example**::

    local n, messages = Steam.NetworkingSockets.ReceiveMessagesOnPollGroup(pollGroup)


Examples
--------

These examples should run with any version of lua >= 5.1 or Löve

**Sockets Client**::

    local Steam = require 'luasteam'

    local connection = nil

    Steam.Init()
    Steam.NetworkingSockets.InitAuthentication()

    function Steam.NetworkingSockets.onConnectionChanged(data)
        print ('Connection changed', data.connection, data.state, data.state_old, data.endReason, data.debug)
    end

    function Steam.NetworkingSockets.onAuthenticationStatus(data)
        if data.status == 100 and not connection then
            connection = Steam.NetworkingSockets.ConnectByIPAddress("127.0.0.1:55556")
        end
    end

    local run = true
    local counter = 0
    local msg_rec = false
    while run do
        Steam.RunCallbacks()

        if connection then
            local n, messages = Steam.NetworkingSockets.ReceiveMessagesOnConnection(connection)

            if n > 0 then
                for j,m in ipairs(messages) do
                    print("received message", j, m, "from connection", connection, type(j))
                    Steam.NetworkingSockets.SendMessageToConnection(connection, "Hello server! This is the client! Thank you!", Steam.NetworkingSockets.flags.Send_Reliable)
                    msg_rec = true
                end
            end
        end

        if msg_rec then
            counter = counter + 1
            if counter > 10000 then -- you might have to increase this if the client shuts down faster than the message can be sent
                run = false
            end
        end
    end

    if connection then
        Steam.NetworkingSockets.CloseConnection(connection)
    end
    Steam.Shutdown()

**Sockets Server**::

    local Steam = require 'luasteam'

    local connections = {}
    local server = nil

    Steam.Init()

    Steam.NetworkingSockets.InitAuthentication()

    function Steam.NetworkingSockets.onConnectionChanged(data)
        print ('Connection changed', data.connection, data.state, data.state_old, data.endReason, data.debug)
        if data.state == "Connecting" then
            Steam.NetworkingSockets.AcceptConnection(data.connection)
        end
        if  data.state == "Connected" then
            connections[data.connection] = true
            Steam.NetworkingSockets.SendMessageToConnection(data.connection, "Hello client! This is the server! Welcome!", Steam.NetworkingSockets.flags.Send_Reliable)
        end
        if data.state == "ClosedByPeer" or data.state == "ProblemDetectedLocally" then
            print(data.connection, data.state, data.endReason, data.debug)
            Steam.NetworkingSockets.CloseConnection(data.connection)
            connections[data.connection] = nil
        end
    end

    function Steam.NetworkingSockets.onAuthenticationStatus(data)
        if data.status == 100 and not connection then
            server = Steam.NetworkingSockets.CreateListenSocketIP("[::]:55556")
            print("Listening on port 55556")
        end
    end

    local run = true

    while run do
        Steam.RunCallbacks()

        for conn,_ in pairs(connections) do
            local n, messages = Steam.NetworkingSockets.ReceiveMessagesOnConnection(conn)
            if n > 0 then
                for j,m in ipairs(messages) do
                    print("received message", j, m, "from connection", conn, type(j))
                    run = false
                end
            end
        end
    end

    for conn,_ in pairs(connections) do
        Steam.NetworkingSockets.CloseConnection(conn)
    end
    Steam.Shutdown()
