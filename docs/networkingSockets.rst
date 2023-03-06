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
* :func:`networkingSockets.receiveMessagesOnConnection`
* :func:`networkingSockets.initAuthentication`
* :func:`networkingSockets.getAuthenticationStatus`
* :func:`networkingSockets.getConnectionInfo`

List of Callbacks
-----------------
* :func:`networkingSockets.onAuthenticationStatus`
* :func:`networkingSockets.onConnectionChanged`

Function Reference
------------------
.. function:: networkingSockets.createListenSocketP2P()

    :param integer virtualPort: The virtual port to bind to. Use 0 if you don't care about any particular port. Use values below 1000.
    :param table options: Table with key value pairs to override default SteamNetworkingSockets options. **NOT IMPLEMENTED YET**
    :returns: (`userdata`) a socket object
    :SteamWorks: `CreateListenSocketP2P <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CreateListenSocketP2P>`_

    Accept P2P connections through the Steam Network. If you want to change any networking settings, you need pass these options on creation. Implement the callback **TODO** to be notified about connection events.

**Example**::

    Steam.networkingSockets.createListenSocketP2P(0)

.. function:: networkingSockets.connectP2P()

    :param uint64 steamID: The steamID of the remote host to connect to. Use :func:`Steam.extra.parseUint64('12345abcded')` to parse a steamID string
    :param integer virtualPort: The virtual port to connect to on the server.
    :param table options: Table with key value pairs to override default SteamNetworkingSockets options. **NOT IMPLEMENTED YET**
    :returns: (`userdata`) a socket object
    :SteamWorks: `CreateListenSocketP2P <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CreateListenSocketP2P>`_

    Accept P2P connections through the Steam Network. If you want to change any networking settings, you need pass these options on creation. Implement the callback **TODO** to be notified about connection events.

**Example**::

    Steam.networkingSockets.connectP2P(0)

.. function:: networkingSockets.createListenSocketIP()

    :param string localAdress: The adress to bind to in string format. E.g. to bind to localhost on port 55556, use **"[::]:55556"**.
    :param table options: Table with key value pairs to override default SteamNetworkingSockets options. **NOT IMPLEMENTED YET**
    :returns: (`userdata`) a socket object
    :SteamWorks: `CreateListenSocketIP <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CreateListenSocketIP>`_

    Bind to an adress and accept connections as a "server". If you want to change any networking settings, you need pass these options on creation. Implement the callback **TODO** to be notified about connection events.

**Example**::

    Steam.networkingSockets.createListenSocketIP("[::]:55556")

.. function:: networkingSockets.connectByIPAddress()

    :param string localAdress: The adress to connect to in string format. E.g. to bind to localhost on port 55556, use **"127.0.0.1:55556"**.
    :param table options: Table with key value pairs to override default SteamNetworkingSockets options. **NOT IMPLEMENTED YET**
    :returns: (`userdata`) a socket object
    :SteamWorks: `ConnectByIPAddress <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#ConnectByIPAddress>`_

    Connect to a given adress as a "client". If you want to change any networking settings, you need pass these options on creation. Implement the callback :func:`networkingSockets.onConnectionChanged` to be notified about connection events.

**Example**::

    Steam.networkingSockets.connectByIPAddress("127.0.0.1:55556")
    
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

.. function:: networkingSockets.receiveMessagesOnConnection()

    :param int connection: The id of the connection to receive messages from
    :returns: (`table`) a table with all n messages received, indexed 1..n. Reliable messages are in order in relation to each other. Unreliable messages might be in any order inside the table
    :SteamWorks: `ReceiveMessagesOnConnection <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#ReceiveMessagesOnConnection>`_

    Receive all the messages that are waiting on the given connection up to 32. Call this repeatedly until ``#return < 32``

    A result table might look like this: ``{ 1 = "Some message", 2 = "Another message", 3 = "Yet another message" }``

**Example**::

    local messages = Steam.networkingSockets.receiveMessagesOnConnection(socket)

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
