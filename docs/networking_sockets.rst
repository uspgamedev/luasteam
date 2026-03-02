#######################
ISteamNetworkingSockets
#######################

This allows using the Steam Networking Sockets API. It's a protocol on top of UDP without the caveats of TCP (very slow) and optimized for the demands of video game traffic. Supports both reliable and unreliable traffic.

There are two ways to use it.

    * Classic Bind/connect to sockets and send/receive data over UDP. You are going to use IPs and ports as expected.
    * P2P using the the steam network. In this case, you are going to connect directly to other steam users. Valve will handle all verification/authentication/encryption/NAT-punching issues for you and carry the traffic through the steam network.

Read more at https://partner.steamgames.com/doc/features/multiplayer/steamdatagramrelay.

For the complete function reference, see :doc:`auto/networkingsockets`.

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
