###############
ISteamNetworkingSockets
###############


List of Functions
-----------------
* :func:`sockets.createListenSocketIP`
* :func:`sockets.connectByIPAddress`
* :func:`sockets.acceptConnection`
* :func:`sockets.closeConnection`
* :func:`sockets.closeListenSocket`
* :func:`sockets.sendMessageToConnection`
* :func:`sockets.receiveMessagesOnConnection`

List of Callbacks
-----------------

* :func:`sockets.onConnectionChanged`

Function Reference
------------------

.. function:: sockets.createListenSocketIP()

    :param string localAdress: The adress to bind to in string format. E.g. to bind to localhost on port 55556, use **"[::]:55556"**.
    :param table options: Table with key value pairs to override default SteamNetworkingSockets options. **NOT IMPLEMENTED YET**
    :returns: (`userdata`) a socket object
    :SteamWorks: `CreateListenSocketIP <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CreateListenSocketIP>`_

    Bind to an adress and accept connections as a "server". If you want to change any networking settings, you need pass these options on creation. Implement the callback **TODO** to be notified about connection events.

**Example**::

    Steam.sockets.createListenSocketIP("[::]:55556")

.. function:: sockets.connectByIPAddress()

    :param string localAdress: The adress to connect to in string format. E.g. to bind to localhost on port 55556, use **"127.0.0.1:55556"**.
    :param table options: Table with key value pairs to override default SteamNetworkingSockets options. **NOT IMPLEMENTED YET**
    :returns: (`userdata`) a socket object
    :SteamWorks: `ConnectByIPAddress <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#ConnectByIPAddress>`_

    Connect to a given adress as a "client". If you want to change any networking settings, you need pass these options on creation. Implement the callback :func:`sockets.onConnectionChanged` to be notified about connection events.

**Example**::

    Steam.sockets.connectByIPAddress("127.0.0.1:55556")
    
.. function:: sockets.acceptConnection()

    :param int connection: The id of the connection to accept
    :returns: (`string`) result with the possible values ``OK | InvalidParam | InvalidState``
    :SteamWorks: `AcceptConnection <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#AcceptConnection>`_

    Accept a connection that was received via the callback :func:`sockets.onConnectionChanged`. This will move the connection from the ``Connecting`` state to the ``Connected`` state.

    Return values explanation
    
            * **OK** - The connection was accepted
            * **InvalidParam** - The connection id was invalid
            * **InvalidState** - The connection was not in the ``Connecting`` state

**Example**::

    local result = Steam.sockets.acceptConnection(connection)

.. function:: sockets.closeConnection()

    :param int connection: The id of the connection to close
    :param boolean bEnableLinger: If true, attempts to finish delivering any outbound messages. If you set it to true, you need to make sure that you keep calling the Steam callback long enough for this to actually happen.  
    :returns: nothing
    :SteamWorks: `CloseConnection <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CloseConnection>`_

    Disconnects from the remote host and invalidates the connection handle. Any unread data on the connection is discarded.

**Example**::

    Steam.sockets.closeConnection(connection)

.. function:: sockets.closeListenSocket()

    :param userdata socket: The socket object you received when opening a socket with :func:`sockets.createListenSocketIP` or :func:`sockets.connectByIPAddress`
    :returns: nothing
    :SteamWorks: `CloseListenSocket <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CloseListenSocket>`_

    Destroy the given listen socket. All the connections that were accepted on the listen socket are closed ungracefully. You should call this before closing your application for any sockets you created.

**Example**::

    Steam.sockets.closeListenSocket(socket)

.. function:: sockets.sendMessageToConnection()

    :param int connection: The id of the connection to send a message to
    :param string message: The message to send. Can be any length (up to configured SendBufferSize), splitting will be handled by the library
    :param int flag: A flag to specify how the message should be sent. See below for explanation
    :returns: (`string`) result with the possible values ``OK | InvalidParam | InvalidState | NoConnection | Ignored | LimitExceeded``
    :SteamWorks: `SendMessageToConnection <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#SendMessageToConnection>`_

    Send a string message to the specified connection. Delivery method depends on the flag you pass. See <https://partner.steamgames.com/doc/api/steamnetworkingtypes> in the section **Flags used for message sending** for a detailed explanation

        * **Steam.sockets.flags.Send_Reliable** - Message will be sent reliably (resend if necessary until acknowledged) and in order with other reliable messages
        * **Steam.sockets.flags.Send_ReliableNoNagle** - Reliable without Nagle algorithm (don't wait a short while for more messages before sending). As a rule of thumb, don't use this unless you're sure you know what you're doing. Use :func:`sockets.flushMessagesOnConnection` instead
        * **Steam.sockets.flags.Send_Unreliable** - Message will be sent once only, might get lost on the way and arrive in any order
        * **Steam.sockets.flags.Send_UnreliableNoNagle** - Unreliable without Nagle algorithm
        * **Steam.sockets.flags.Send_UnreliableNoDelay** - Send unreliable and only if the message can be sent right now. If there is any delay in sending the message (bottleneck, network hiccup, ...) this message will be dropped

    Return values explanation
    
            * **OK** - The message was sent
            * **InvalidParam** - The connection id was invalid
            * **InvalidState** - The connection was not in the ``Connected`` state
            * **NoConnection** - The connection has ended
            * **Ignored** - The message was ignored because you used ``Send_UnreliableNoDelay`` and it wasn't possible to send the message right now
            * **LimitExceeded** - The message was too large to send and or there are too many outgoing messages crowding the send buffer

**Example**::

    local result = Steam.sockets.sendMessageToConnection(connection, "Ping", Steam.sockets.flags.Reliable)

.. function:: sockets.receiveMessagesOnConnection()

    :param int connection: The id of the connection to receive messages from
    :returns: (`table`) a table with all n messages received, indexed 1..n. Reliable messages are in order in relation to each other. Unreliable messages might be in any order inside the table
    :SteamWorks: `ReceiveMessagesOnConnection <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#ReceiveMessagesOnConnection>`_

    Receive all the messages that are waiting on the given connection up to 32. Call this repeatedly until ``#return < 32``

    A result table might look like this: ``{ 1 = "Some message", 2 = "Another message", 3 = "Yet another message" }``

**Example**::

    local messages Steam.sockets.receiveMessagesOnConnection(socket)

Callbacks Reference
-------------------

.. warning::

    Remember callbacks are functions that you should override in order to receive the events, and not call directly.

    Also, you **must** constantly call ``Steam.runCallbacks()`` (preferably in your game loop) in order for your callbacks to be called.

.. function:: sockets.onConnectionChanged(data)

    :param table data: Basic information about the changing connection

		* **data.connection** (`string`)  a unique id representing this connection
		* **data.state** (`string`)  the state this connection is now in
		* **data.state_old** (`int`)  the previous state this connection was in
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

    function Steam.sockets.onConnectionChanged(data)
        print ('A connection has changed', data.connection, data.state, data.state_old)
    end
