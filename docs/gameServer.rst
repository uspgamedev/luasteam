################
ISteamGameServer 
################

You can use this interface to connect to steam as a `Game Server <https://partner.steamgames.com/doc/sdk/api#steam_game_servers>`_ and run this library without having to run the steam client in the background.

You need to use luasteam a bit differently. Instead of using ``Steam.init()`` and the other callbacks, do it like this::

    local Steam = require 'luasteam'

    Steam.gameServer.init(0, gamePort, queryPort, Steam.gameServer.mode.NoAuthentication, "0.0.1")
    -- ...
    -- during the update loop
    Steam.gameServer.runCallbacks()
    -- ...
    -- when game is closing
    Steam.gameServer.shutdown()

In this mode, not all modules and functions are usable.

Useable modules:

    * ISteamNetworkingSockets
    * ISteamNetworkingUtils


List of Functions
-----------------
* :func:`gameServer.init`
* :func:`gameServer.shutdown`
* :func:`gameServer.runCallbacks`
* :func:`gameServer.logOn`
* :func:`gameServer.logOnAnonymous`
* :func:`gameServer.logOff`
* :func:`gameServer.bLoggedOn`
* :func:`gameServer.bSecure`
* :func:`gameServer.getSteamID`
* :func:`gameServer.setDedicatedServer`

List of Callbacks
-----------------
* :func:`gameServer.onSteamServersConnected`
* :func:`gameServer.onSteamServersDisconnected`
* :func:`gameServer.onSteamServerConnectFailure`

Function Reference
------------------
.. function:: gameServer.init()

    :param int unIP: The IP address you are going to bind to. (This should be in host order, i.e 127.0.0.1 == 0x7f000001 == 2130706433). You can just use ``0`` to bind to all local IPv4 addresses.
    :param int steamPort: The port clients are going to bind to. Important if you want to connec this server to a game master and show it in a server list.
    :param int queryPort: The port for communicating with a game master server and exchange status information.
    :param int serverMode: The server mode to use. Use constants from ``Steam.gameServer.mode.*``

        * **NoAuthentication** Don't authenticate user logins and don't list on the server list.
        * **Authentication** Authenticate users, list on the server list, don't run VAC on clients that connect.
        * **AuthenticationAndSecure** Authenticate users, list on the server list and VAC protect clients.

    :param string version: The version of your game in the form ``x.x.x.x``. This is used to show the version of the server in the server browser and to block outdated servers from connecting.
    :returns: (`boolean`) success
    :SteamWorks: `SteamGameServer_Init <https://partner.steamgames.com/doc/api/steam_gameserver#SteamGameServer_Init>`_

    Initiate the game server API and allow usage of **ISteamNetworkingSockets** and **ISteamNetworkingUtils**. Add some metadata about the type of server you're running here. Most of this is only relevant if you're planning to make use of Steam's server browser feature.

**Example**::

    local result = Steam.gameServer.init(0, gamePort, queryPort, Steam.gameServer.mode.Authentication, "0.0.0.1")

.. function:: gameServer.shutdown()

    :returns: nothing
    :SteamWorks: `SteamGameServer_Shutdown <https://partner.steamgames.com/doc/api/steam_gameserver#SteamGameServer_Shutdown>`_

    Don't forget this to call it when your game is closing or when you're done using the interface

**Example**::

    Steam.gameServer.shutdown()

.. function:: gameServer.runCallbacks()

    :returns: nothing
    :SteamWorks: `SteamGameServer_RunCallbacks <https://partner.steamgames.com/doc/api/steam_gameserver#SteamGameServer_RunCallbacks>`_

    Run the steam callbacks. This is required to get any callbacks from the steam API. You need to call this regularly, e.g. in your main loop.

**Example**::

    Steam.gameServer.runCallbacks()

.. function:: gameServer.logOn()

    :param string token: The login token for your server
    :returns: nothing
    :SteamWorks: `LogOn <https://partner.steamgames.com/doc/api/ISteamGameServer#LogOn>`_

    Authenticate to steam with a login token. Generate a token through `Steam <https://steamcommunity.com/dev/managegameservers>`_. 
    
    Triggers the callbacks
    
        * :func:`networkingSockets.onSteamServersConnected`
        * :func:`networkingSockets.onSteamServersDisconnected`
        * :func:`networkingSockets.onSteamServerConnectFailure`

**Example**::

    local accessToken = "abcdef123456" -- Access token generated through steam
    Steam.gameServer.logOn(accessToken) 

.. function:: gameServer.logOnAnonymous()

    :returns: nothing
    :SteamWorks: `LogOnAnonymous <https://partner.steamgames.com/doc/api/ISteamGameServer#LogOnAnonymous>`_

    Log in into a generic, anonymous Steam account.

    Triggers the callbacks
    
        * :func:`networkingSockets.onSteamServersConnected`
        * :func:`networkingSockets.onSteamServersDisconnected`
        * :func:`networkingSockets.onSteamServerConnectFailure`

**Example**::

    Steam.gameServer.logOnAnonymous()

.. function:: gameServer.logOff()

    :returns: nothing
    :SteamWorks: `LogOff <https://partner.steamgames.com/doc/api/ISteamGameServer#LogOff>`_

    Begin process of logging the game server out of steam.

    Triggers the callbacks
    
        * :func:`networkingSockets.onSteamServersConnected`
        * :func:`networkingSockets.onSteamServersDisconnected`
        * :func:`networkingSockets.onSteamServerConnectFailure`

**Example**::

    Steam.gameServer.logOff()

.. function:: gameServer.bLoggedOn()

    :returns: (`boolean`) true if logged on
    :SteamWorks: `BLoggedOn <https://partner.steamgames.com/doc/api/ISteamGameServer#BLoggedOn>`_

    Checks if the game server is logged on.

**Example**::

    local loggedOn = Steam.gameServer.bLoggedOn()

.. function:: gameServer.bSecure()

    :returns: (`boolean`) true if logged on
    :SteamWorks: `BSecure <https://partner.steamgames.com/doc/api/ISteamGameServer#BSecure>`_

    Checks whether the game server is in "Secure" mode.

**Example**::

    local secure = Steam.gameServer.bSecure()

.. function:: gameServer.getSteamID()

    :returns: (`uint64`) The SteamID of the server.
    :SteamWorks: `GetSteamID <https://partner.steamgames.com/doc/api/ISteamGameServer#GetSteamID>`_

    Gets the Steam ID of the game server.

**Example**::

    local steam_id = Steam.gameServer.getSteamID()

.. function:: gameServer.setDedicatedServer()

    :param boolean bDedicated: Is this a dedicated server (true) or a listen server (false)?
    :returns: nothing
    :SteamWorks: `SetDedicatedServer <https://partner.steamgames.com/doc/api/ISteamGameServer#SetDedicatedServer>`_

    Sets the whether this is a dedicated server or a listen server. The default is listen server.

    **NOTE:** This can **only be set before** calling :func:`networkingSockets.LogOn` or :func:`networkingSockets.LogOnAnonymous`.

**Example**::

    Steam.gameServer.setDedicatedServer(true)

Callbacks Reference
-------------------

.. warning::

    Remember callbacks are functions that you should override in order to receive the events, and not call directly.

    Also, you **must** constantly call ``Steam.gameServer.runCallbacks()`` (preferably in your game loop) in order for your callbacks to be called.

.. function:: gameServer.onSteamServersConnected()

    :returns: nothing
    :SteamWorks: `SteamServersConnected_t  <https://partner.steamgames.com/doc/api/ISteamUser#SteamServersConnected_t>`_

    Called when a connections to the Steam back-end has been established. This is in response to a call to :func:`networkingSockets.LogOn` or :func:`networkingSockets.LogOnAnonymous` or after loosing a connection.
    
    This means the Steam client now has a working connection to the Steam servers.

**Example**::

    function Steam.gameServer.onSteamServersConnected()
        print("SteamServersConnected")
    end

.. function:: gameServer.onSteamServersDisconnected(data)

    :param table data: A result table

		* **data.result** (`string`) An error message with the reason for the disconnect.

    :returns: nothing
    :SteamWorks: `SteamServersDisconnected_t <https://partner.steamgames.com/doc/api/ISteamUser#SteamServersDisconnected_t>`_

    Called if the client has lost connection to the Steam servers.

**Example**::

    function Steam.gameServer.onSteamServersDisconnected(data)
        print("onSteamServersDisconnected", data.result)
    end

.. function:: gameServer.onSteamServerConnectFailure(data)

    :param table data: A result table

		* **data.result** (`string`) An error message with the reason for the disconnect.
		* **data.stillRetrying** (`boolean`) ``True`` if another connection attempt will be made, ``False`` if we have given up.

    :returns: nothing
    :SteamWorks: `SteamServerConnectFailure_t <https://partner.steamgames.com/doc/api/ISteamUser#SteamServerConnectFailure_t>`_

    Called when a connection attempt has failed.

    This will occur periodically if the Steam client is not connected, and has failed when retrying to establish a connection.

**Example**::

    function Steam.gameServer.onSteamServerConnectFailure(data)
        print("onSteamServerConnectFailure", data.result, data.stillRetrying)
    end
