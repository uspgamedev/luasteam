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
* :func:`networkingSockets.createListenSocketP2P`
* :func:`networkingSockets.connectP2P`
* :func:`networkingSockets.createListenSocketIP`
* :func:`networkingSockets.connectByIPAddress`
* :func:`networkingSockets.acceptConnection`
* :func:`networkingSockets.closeConnection`
* :func:`networkingSockets.closeListenSocket`
* :func:`networkingSockets.sendMessageToConnection`
* :func:`networkingSockets.sendMessages`
* :func:`networkingSockets.flushMessagesOnConnection`
* :func:`networkingSockets.receiveMessagesOnConnection`
* :func:`networkingSockets.initAuthentication`
* :func:`networkingSockets.getAuthenticationStatus`
* :func:`networkingSockets.getConnectionInfo`
* :func:`networkingSockets.getIdentity`
* :func:`networkingSockets.createPollGroup`
* :func:`networkingSockets.destroyPollGroup`
* :func:`networkingSockets.setConnectionPollGroup`
* :func:`networkingSockets.receiveMessagesOnPollGroup`

List of Callbacks
-----------------
* :func:`networkingSockets.onAuthenticationStatus`
* :func:`networkingSockets.onConnectionChanged`

Function Reference
------------------
.. function:: networkingSockets.createListenSocketP2P()

    :param integer virtualPort: The virtual port to bind to. Use 0 if you don't care about any particular port. Use values below 1000.
    :param table options: Table with key value pairs to override default SteamNetworkingSockets options. See the config section at the bottom for possible values
    :returns: (`userdata`) a socket object
    :SteamWorks: `CreateListenSocketP2P <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CreateListenSocketP2P>`_

    Accept P2P connections through the Steam Network. If you want to change any networking settings, you need pass these options on creation. Implement the :func:`networkingSockets.onAuthenticationStatus` callback to be notified about connection events.

**Example**::

    local socket = Steam.networkingSockets.createListenSocketP2P(0)

.. function:: networkingSockets.connectP2P()

    :param uint64 steamID: The steamID of the remote host to connect to. Get it from :func:`Steam.user.getSteamID()` or convert a string with :func:`Steam.extra.parseUint64`.
    :param integer virtualPort: The virtual port to connect to on the server.
    :param table options: Table with key value pairs to override default SteamNetworkingSockets options. See the config section at the bottom for possible values
    :returns: (`int`) a connection id
    :SteamWorks: `CreateListenSocketP2P <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CreateListenSocketP2P>`_

    Accept P2P connections through the Steam Network. If you want to change any networking settings, you need pass these options on creation. Implement the :func:`networkingSockets.onAuthenticationStatus` callback to be notified about connection events.

**Example**::

    local socket = Steam.networkingSockets.connectP2P(Steam.extra.parseUint64("someID"), 0)

.. function:: networkingSockets.createListenSocketIP()

    :param string localAdress: The adress to bind to in string format. E.g. to bind to localhost on port 55556, use **"[::]:55556"**.
    :param table options: Table with key value pairs to override default SteamNetworkingSockets options. See the config section at the bottom for possible values
    :returns: (`userdata`) a socket object
    :SteamWorks: `CreateListenSocketIP <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CreateListenSocketIP>`_

    Bind to an adress and accept connections as a "server". If you want to change any networking settings, you need pass these options on creation. Implement the callback **TODO** to be notified about connection events.

**Example**::

    local socket = Steam.networkingSockets.createListenSocketIP("[::]:55556")

.. function:: networkingSockets.connectByIPAddress()

    :param string localAdress: The adress to connect to in string format. E.g. to bind to localhost on port 55556, use **"127.0.0.1:55556"**.
    :param table options: Table with key value pairs to override default SteamNetworkingSockets options. See the config section at the bottom for possible values
    :returns: (`int`) a connection id
    :SteamWorks: `ConnectByIPAddress <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#ConnectByIPAddress>`_

    Connect to a given adress as a "client". If you want to change any networking settings, you need pass these options on creation. Implement the callback :func:`networkingSockets.onConnectionChanged` to be notified about connection events.

**Example**::

    local connection = Steam.networkingSockets.connectByIPAddress("127.0.0.1:55556")
    
.. function:: networkingSockets.acceptConnection()

    :param int connection: The id of the connection to accept
    :returns: (`string`) result with the possible values ``OK | InvalidParam | InvalidState``
    :SteamWorks: `AcceptConnection <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#AcceptConnection>`_

    Accept a connection that was received via the callback :func:`networkingSockets.onConnectionChanged`. This will move the connection from the ``Connecting`` state to the ``Connected`` state.

    Return values explanation
    
            * **OK** - The connection was accepted
            * **InvalidParam** - The connection id was invalid
            * **InvalidState** - The connection was not in the ``Connecting`` state

**Example**::

    local result = Steam.networkingSockets.acceptConnection(connection)

.. function:: networkingSockets.closeConnection()

    :param int connection: The id of the connection to close
    :param boolean bEnableLinger: If true, attempts to finish delivering any outbound messages. If you set it to true, you need to make sure that you keep calling the Steam callback long enough for this to actually happen.  
    :returns: nothing
    :SteamWorks: `CloseConnection <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CloseConnection>`_

    Disconnects from the remote host and invalidates the connection handle. Any unread data on the connection is discarded.

**Example**::

    Steam.networkingSockets.closeConnection(connection)

.. function:: networkingSockets.closeListenSocket()

    :param userdata socket: The socket object you received when opening a socket with :func:`networkingSockets.createListenSocketIP` or :func:`networkingSockets.connectByIPAddress`
    :returns: nothing
    :SteamWorks: `CloseListenSocket <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CloseListenSocket>`_

    Destroy the given listen socket. All the connections that were accepted on the listen socket are closed ungracefully. You should call this before closing your application for any sockets you created.

**Example**::

    Steam.networkingSockets.closeListenSocket(socket)

.. function:: networkingSockets.sendMessageToConnection()

    :param int connection: The id of the connection to send a message to
    :param string message: The message to send. Can be any length (up to configured SendBufferSize), splitting will be handled by the library
    :param int flag: A flag to specify how the message should be sent. See below for explanation
    :returns: (`string`) result with the possible values ``OK | InvalidParam | InvalidState | NoConnection | Ignored | LimitExceeded``
    :SteamWorks: `SendMessageToConnection <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#SendMessageToConnection>`_

    Send a string message to the specified connection. Delivery method depends on the flag you pass. See <https://partner.steamgames.com/doc/api/steamnetworkingtypes> in the section **Flags used for message sending** for a detailed explanation

        * **Steam.networkingSockets.flags.Send_Reliable** - Message will be sent reliably (resend if necessary until acknowledged) and in order with other reliable messages
        * **Steam.networkingSockets.flags.Send_ReliableNoNagle** - Reliable without Nagle algorithm (don't wait a short while for more messages before sending). As a rule of thumb, don't use this unless you're sure you know what you're doing. Use :func:`networkingSockets.flushMessagesOnConnection` instead
        * **Steam.networkingSockets.flags.Send_Unreliable** - Message will be sent once only, might get lost on the way and arrive in any order
        * **Steam.networkingSockets.flags.Send_UnreliableNoNagle** - Unreliable without Nagle algorithm
        * **Steam.networkingSockets.flags.Send_UnreliableNoDelay** - Send unreliable and only if the message can be sent right now. If there is any delay in sending the message (bottleneck, network hiccup, ...) this message will be dropped

    Return values explanation
    
            * **OK** - The message was sent
            * **InvalidParam** - The connection id was invalid
            * **InvalidState** - The connection was not in the ``Connected`` state
            * **NoConnection** - The connection has ended
            * **Ignored** - The message was ignored because you used ``Send_UnreliableNoDelay`` and it wasn't possible to send the message right now
            * **LimitExceeded** - The message was too large to send and or there are too many outgoing messages crowding the send buffer

**Example**::

    local result = Steam.networkingSockets.sendMessageToConnection(connection, "Ping", Steam.networkingSockets.flags.Reliable)

.. function:: networkingSockets.sendMessages()

    :param int n: The number of messages you are going to send
    :param table messages: A number indexed table with all messages you want to send. Indices from 1..n need to exist. Each message is a table with the following keys:
        
            * **conn** - The id of the connection to send a message to
            * **msg** - The message to send. Can be any length (up to configured SendBufferSize), splitting will be handled by the library
            * **flag** - A flag to specify how the message should be sent. See :func:`networkingSockets.sendMessageToConnection` for details

    :returns: (`table`) Result table with ``true`` or ``false`` for each message, indexed 1..n, e.g. ``{ 1 = true, 2 = false }``
    :SteamWorks: `SendMessages <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#SendMessages>`_

    This is a more efficient way to send out messages. E.g. you could gather all messages generated in an update cycle and then send them out all in one go using this method instead of dispatching them individually with :func:`networkingSockets.sendMessageToConnection`.

**Example**::

    local messages = {}
    messages[1] = { conn = connection1, msg = "Hello!", flag = Steam.networkingSockets.flags.Send_Reliable }
    messages[2] = { conn = connection2, msg = "World", flag = Steam.networkingSockets.flags.Send_Reliable }
    local result = Steam.networkingSockets.sendMessages(#messages, messages)

.. function:: networkingSockets.flushMessagesOnConnection()

    :param int connection: The id of the connection to flush messages for
    :returns: (`string`) The result. See the return value of :func:`networkingSockets.sendMessageToConnection` for a detailed description.
    :SteamWorks: `FlushMessagesOnConnection <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#FlushMessagesOnConnection>`_

    Flush out all messages left in the send buffer of the given connection and don't wait for the nagle timer. You only ever want to do this at the end of your update cycle if you know that you are not going to send any more messages for a while. Calling this may improve **or degrade** your networking performance depending on your use case.

**Example**::

    local result = Steam.networkingSockets.flushMessagesOnConnection()


.. function:: networkingSockets.receiveMessagesOnConnection()

    :param int connection: The id of the connection to receive messages from
    :returns: (`int`, `table`) Returns two parameters

        * **n** - The number of messages received. ``-1`` if the passed poll group id is invalid (the table is nil in this case).
        * **messages** - A 1..n index table of messages. Reliable messages are in order in relation to each other. Unreliable messages might be in any order inside the table

    :SteamWorks: `ReceiveMessagesOnConnection <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#ReceiveMessagesOnConnection>`_

    Receive all the messages that are waiting on the given connection **up to 32**. Call this repeatedly until ``n < 32``

    A result table might look like this: ``{ 1 = "Some message", 2 = "Another message", 3 = "Yet another message" }``

    Iterate with ipairs to retain the order any reliable messages were received in.

**Example**::

    local n, messages = Steam.networkingSockets.receiveMessagesOnConnection(connection)

.. function:: networkingSockets.initAuthentication()

    :returns: (`int`) The possible values are same as ``data.status`` in :func:`networkingSockets.onAuthenticationStatus`
    :SteamWorks: `InitAuthentication <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#InitAuthentication>`_

    Indicate our desire to be ready participate in authenticated communications.

**Example**::

    local result = Steam.networkingSockets.initAuthentication()

.. function:: networkingSockets.getAuthenticationStatus()

    :returns: (`int`, `string`)

        * status: The possible values are same as ``data.status`` in :func:`networkingSockets.onAuthenticationStatus`
        * msg: A human readable message for the current status
        
    :SteamWorks: `GetAuthenticationStatus <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetAuthenticationStatus>`_

    Get the curren status of authentication

**Example**::

    local result, msg = Steam.networkingSockets.getAuthenticationStatus()

.. function:: networkingSockets.getConnectionInfo()

    :param int connection: The connection to get info about
    :returns: (`code`, `info`) 

        * **code** See the return values of :func:`networkingSockets.connectByIPAddress` for code meanings. 

        * **info** Connection detail string
    :SteamWorks: `GetConnectionInfo <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetConnectionInfo>`_

    Get basic information about the status of a connection.

**Example**::

    local code, info = Steam.networkingSockets.getConnectionInfo(connection)

.. function:: networkingSockets.createPollGroup()

    :returns: (`int`) id of the poll group
    :SteamWorks: `CreatePollGroup <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CreatePollGroup>`_

    Create a new poll group. You can use this to receive messages from multiple connections at once. You need to delete this if you don't need it anymore with :func:`networkingSockets.destroyPollGroup`.

**Example**::

    local pollGroup = Steam.networkingSockets.createPollGroup()

.. function:: networkingSockets.destroyPollGroup()

    :param int pollGroup: The poll group to destroy
    :returns: (`boolean`) ``true`` if it was successful
    :SteamWorks: `DestroyPollGroup <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#DestroyPollGroup>`_

    Destroy a poll group. Do this before you shut down.

**Example**::

    local success = Steam.networkingSockets.destroyPollGroup(pollGroup)

.. function:: networkingSockets.setConnectionPollGroup()

    :param int connection: The connection to add to the poll group
    :param int pollGroup: The poll group
    :returns: (`boolean`) ``true`` if it was successful
    :SteamWorks: `SetConnectionPollGroup <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#SetConnectionPollGroup>`_

    Assign a connection to a poll group. After that you can poll this connections messages through the poll group with :func:`networkingSockets.receiveMessagesOnPollGroup`.

**Example**::

    local success = Steam.networkingSockets.setConnectionPollGroup(connection, pollGroup)

.. function:: networkingSockets.receiveMessagesOnPollGroup()

    :param int pollGroup: The poll group to receive messages from
    :returns: (`int`, `table`) Returns two parameters

        * **n** - The number of messages received. ``-1`` if the passed poll group id is invalid (the table is nil in this case).
        * **messages** - A 1..n index table of messages. Reliable messages are in order in relation to each other. Unreliable messages might be in any order inside the table. Each message is a table with a ``conn`` and a ``msg`` field.

    :SteamWorks: `ReceiveMessagesOnPollGroup <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#ReceiveMessagesOnPollGroup>`_

    This is the poll group equivalent to :func:`networkingSockets.receiveMessagesOnConnection`. The advantage of this version is that you can just get all messages to any connection assigned. If you expect larger number of connections, it's much more efficient to create one or more poll groups and just poll the group instead of having to check messages for every connection individually.

    Receive all the messages that are waiting on the given poll group **up to 32**. Call this repeatedly until ``n < 32``

    A result table might look like this: ``{ 1 = { conn = 5235, msg = "A message" }, 2 = { conn = 5235, msg = "Another message" }, 3 = { conn = 5678, msg = "Yet another message" } }``
    
    Iterate with ipairs to retain the order any reliable messages were received in.

**Example**::

    local n, messages = Steam.networkingSockets.receiveMessagesOnPollGroup(pollGroup)

Callbacks Reference
-------------------

.. warning::

    Remember callbacks are functions that you should override in order to receive the events, and not call directly.

    Also, you **must** constantly call ``Steam.runCallbacks()`` (preferably in your game loop) in order for your callbacks to be called.

.. function:: networkingSockets.onAuthenticationStatus(data)

    :param table data: Basic information about the steam authentication state

		* **data.status** (`string`)  a unique id representing this connection
		* **data.debugMsg** (`string`) Detailed human readable information in case of problems
    :returns: nothing
    :SteamWorks: `SteamNetAuthenticationStatus_t <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#SteamNetAuthenticationStatus_t>`_

    Posted whenever the authentication status with the Steam back-end changes.
    Possible values for **data.status** are

        * **-102 (CannotTry):** A dependent resource is missing, so this service is unavailable (e.g. we cannot talk to routers because Internet is down or we don't have the network config).
        * **-101 (Availability_Failed):** We have tried for enough time that we would expect to have been successful by now.  We have never been successful.
        * **-100 (Availability_Previously):** We tried and were successful at one time, but now it looks like we have a problem.
        * **-10 (Retrying):** We previously failed and are currently retrying.
        * **1 (NeverTried):** We don't know because we haven't ever checked/tried.
        * **2 (Waiting):** We're waiting on a dependent resource to be acquired (e.g. we cannot obtain a cert until we are logged into Steam.  We cannot measure latency to relays until we have the network config).
        * **3 (Attempting):** We're actively trying now, but are not yet successful.
        * **100 (Current):** Resource is online/available.

**Example**::

    function Steam.networkingSockets.onAuthenticationStatus(data)
        print ('Authentication status has changed', data.status, data.debugMsg)
    end

.. function:: networkingSockets.onConnectionChanged(data)

    :param table data: Basic information about the changing connection

		* **data.connection** (`string`)  a unique id representing this connection
		* **data.state** (`string`)  the state this connection is now in
		* **data.state_old** (`int`)  the previous state this connection was in
		* **data.endReason** (`int`)  end reason error code
		* **data.debug** (`string`)  humand readable debug information string
    :returns: nothing
    :SteamWorks: `SteamNetConnectionStatusChangedCallback_t <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#SteamNetConnectionStatusChangedCallback_t>`_

    Posted whenever the state of a connection changes. For example
        * a client attempts a new connection
        * a server receives a new connection
        * a connection is established successfully (client or server)
        * a connection is closed (client or server)

    Possible values for **data.state** are:
        * None
        * Connecting
        * FindingRoute
        * Connected
        * ClosedByPeer
        * ProblemDetectedLocally

**Example**::

    function Steam.networkingSockets.onConnectionChanged(data)
        print ('Connection changed', data.connection, data.state, data.state_old, data.endReason, data.debug)
    end

.. function:: networkingSockets.getIdentity()

    :returns: (`uint64`) The SteamID of the current user/server or ``nil`` if not available (should only happen with a server that is not logged in yet).
    :SteamWorks: `GetIdentity <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetIdentity>`_

    Get the current identity. Will either return the SteamID or null. Useful mostly if you want to write code that works identically on server and client side.

**Example**::

    local steamID = Steam.networkingSockets.getConnectionInfo(connection)

List of Config Options
----------------------

.. _config:

The following network options can be passed as a table when initiating connections. Example::

    { Unencrypted = 2, IP_AllowWithoutAuth = 1, NagleTime = 0}

Be careful with the values and only change things if you know what you are doing. All values are integers.

    * **TimeoutInitial:** Timeout value (in ms) to use when first connecting
    * **TimeoutConnected:** Timeout value (in ms) to use after connection is established
    * **SendBufferSize:** Upper limit of buffered pending bytes to be sent, if this is reached SendMessage will return k_EResultLimitExceeded Default is 512k (524288 bytes)
    * **SendRateMin:** Minimum/maximum send rate clamp. Default is 0 (no-limit). This value will control the min/max allowed sending rate that bandwidth estimation is allowed to reach.
    * **SendRateMax:** See SendRateMin
    * **NagleTime:** Nagle time, in microseconds (how long to wait with send small packets to facilitate grouping). Default is 5000us (5ms)
    * **IP_AllowWithoutAuth:** Don't automatically fail IP connections that don't have strong auth. 
        
        On clients, this means we will attempt the connection even if we don't know our identity or can't get a cert. 
        
        On the server, it means that we won't automatically reject a connection due to a failure to authenticate. (You can examine the incoming connection and decide whether to accept it.) This is a dev configuration value, and you should not let users modify it in production.
    * **MTU_PacketSize:** Do not send UDP packets with a payload of larger than N bytes. If you set this, k_ESteamNetworkingConfig_MTU_DataSize is automatically adjusted
    * **Unencrypted:** Allow unencrypted (and unauthenticated) communication. 
    
        0: Not allowed (the default)

        1: Allowed, but prefer encrypted

        2: Allowed, and preferred

        3: Required.  (Fail the connection if the peer requires encryption.)
        
        This is a dev configuration value, since its purpose is to disable encryption. You should not let users modify it in production.  (But note that it requires the peer to also modify their value in order for encryption to be disabled.)
    * **SymmetricConnect:** Set this to 1 on outbound connections and listen sockets, to enable "symmetric connect mode", which is useful in the following common peer-to-peer use case: The two peers are "equal" to each other.  (Neither is clearly the "client" or "server".) 
        
        1. Either peer may initiate the connection, and indeed they may do this at the same time
        
        2. The peers only desire a single connection to each other, and if both peers initiate connections simultaneously, a protocol is needed for them to resolve the conflict, so that we end up with a single connection.

    * **LocalVirtualPort:** For connection types that use "virtual ports", this can be used to assign a local virtual port The local port is only relevant for symmetric connections, when determining if two connections "match."  In this case, if you need the local and remote port to differ, you can set this value.


Examples
--------

These examples should run with any version of lua >= 5.1 or Löve

**Sockets Client**::

    local Steam = require 'luasteam'

    local connection = nil

    Steam.init()
    Steam.networkingSockets.initAuthentication()

    function Steam.networkingSockets.onConnectionChanged(data)
        print ('Connection changed', data.connection, data.state, data.state_old, data.endReason, data.debug)
    end

    function Steam.networkingSockets.onAuthenticationStatus(data)
        if data.status == 100 and not connection then
            connection = Steam.networkingSockets.connectByIPAddress("127.0.0.1:55556")
        end
    end

    local run = true
    local counter = 0
    local msg_rec = false
    while run do
        Steam.runCallbacks()

        if connection then
            local n, messages = Steam.networkingSockets.receiveMessagesOnConnection(connection)

            if n > 0 then
                for j,m in ipairs(messages) do
                    print("received message", j, m, "from connection", connection, type(j))
                    Steam.networkingSockets.sendMessageToConnection(connection, "Hello server! This is the client! Thank you!", Steam.networkingSockets.flags.Send_Reliable)
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
        Steam.networkingSockets.closeConnection(connection)
    end
    Steam.shutdown()

**Sockets Server**::

    local Steam = require 'luasteam'

    local connections = {}
    local server = nil

    Steam.init()

    Steam.networkingSockets.initAuthentication()

    function Steam.networkingSockets.onConnectionChanged(data)
        print ('Connection changed', data.connection, data.state, data.state_old, data.endReason, data.debug)
        if data.state == "Connecting" then
            Steam.networkingSockets.acceptConnection(data.connection)
        end
        if  data.state == "Connected" then
            connections[data.connection] = true
            Steam.networkingSockets.sendMessageToConnection(data.connection, "Hello client! This is the server! Welcome!", Steam.networkingSockets.flags.Send_Reliable)
        end
        if data.state == "ClosedByPeer" or data.state == "ProblemDetectedLocally" then
            print(data.connection, data.state, data.endReason, data.debug)
            Steam.networkingSockets.closeConnection(data.connection)
            connections[data.connection] = nil
        end
    end

    function Steam.networkingSockets.onAuthenticationStatus(data)
        if data.status == 100 and not connection then
            server = Steam.networkingSockets.createListenSocketIP("[::]:55556")
            print("Listening on port 55556")
        end
    end

    local run = true

    while run do
        Steam.runCallbacks()

        for conn,_ in pairs(connections) do
            local n, messages = Steam.networkingSockets.receiveMessagesOnConnection(conn)
            if n > 0 then
                for j,m in ipairs(messages) do
                    print("received message", j, m, "from connection", conn, type(j))
                    run = false
                end
            end
        end
    end

    for conn,_ in pairs(connections) do
        Steam.networkingSockets.closeConnection(conn)
    end
    Steam.shutdown()
