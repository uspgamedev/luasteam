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

    Connect to a given adress as a "client". If you want to change any networking settings, you need pass these options on creation. Implement the callback **TODO** to be notified about connection events.

**Example**::

    Steam.sockets.connectByIPAddress("127.0.0.1:55556")
    
.. function:: sockets.acceptConnection()

    :param int connection: The id of the connection to accept
    :returns: (`string`) result with the possible values ``OK | InvalidParam | InvalidState``
    :SteamWorks: `AcceptConnection <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#AcceptConnection>`_

    Accept a connection that was received via the callback **TODO**. This will move the connection from the "connecting" state to the "connected" state.

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
