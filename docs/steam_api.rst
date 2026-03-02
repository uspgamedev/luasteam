#######################
SteamAPI Core Functions
#######################

List of Functions
-----------------
* :func:`Init`
* :func:`Shutdown`
* :func:`RunCallbacks`
* :func:`GameServerInit`
* :func:`GameServerShutdown`
* :func:`GameServerRunCallbacks`


Function Reference
------------------

.. function:: Init()

    :returns: (`boolean`)
        **true** indicates that all required interfaces have been acquired and are accessible.
        **false** indicates one of the following conditions:

        * The Steam client isn't running. A running Steam client is required to provide implementations of the various Steamworks interfaces.

        * The Steam client couldn't determine the App ID of game. If you're running your application from the executable or debugger directly then you must have a ``steam_appid.txt`` in your game directory next to the executable, with your app ID in it and nothing else. Steam will look for this file in the current working directory. If you are running your executable from a different directory you may need to relocate the ``steam_appid.txt`` file.

        * Your application is not running under the same OS user context as the Steam client, such as a different user or administration access level.

        * Ensure that you own a license for the App ID on the currently active Steam account. Your game must show up in your Steam library.

        * Your App ID is not completely set up, i.e. in ``Release State: Unavailable``, or it's missing default packages.
    :SteamWorks: `SteamAPI_Init <https://partner.steamgames.com/doc/api/steam_api#SteamAPI_Init>`_

    Initializes the Steamworks API. **Must** be the first thing you call after loading the library, do it before anything else in your game.

    See `Initialization and Shutdown <https://partner.steamgames.com/doc/sdk/api#initialization_and_shutdown>`_ for additional information.

**Example**::

    local Steam = require 'luasteam'

    if not Steam.Init() then
        error("Steam couldn't initialize")
    end

.. function:: Shutdown()

    :returns: nothing
    :SteamWorks: `SteamAPI_Shutdown <https://partner.steamgames.com/doc/api/steam_api#SteamAPI_Shutdown>`_

    Shuts down the Steamworks API, releases pointers and frees memory.

    You should call this during process shutdown if possible.

    This will not unhook the Steam Overlay from your game as there's no guarantee that your rendering API is done using it.

**Example**::

    function onMyGameClosing()
        Steam.Shutdown()
    end

.. function:: RunCallbacks()

    :returns: nothing
    :SteamWorks: `SteamAPI_RunCallbacks <https://partner.steamgames.com/doc/api/steam_api#SteamAPI_RunCallbacks>`_

    Dispatches callbacks and call results to all of the registered listeners.

    It's best to call this at >10Hz, the more time between calls, the more potential latency between receiving events or results from the Steamworks API. Most games call this once per render-frame. All registered listener functions will be invoked during this call, in the callers thread context.

    :func:`RunCallbacks` is safe to call from multiple threads simultaneously, but if you choose to do this, callback code could be executed on any thread. One alternative is to call :func:`RunCallbacks` from the main thread only, and call :func:`ReleaseCurrentThreadMemory` **(missing)** regularly on other threads.

**Example**::

    function myGameLoop(dt)
        Steam.RunCallbacks()
    end

.. function:: GameServerInit(ip, usGamePort, usQueryPort, eServerMode, version)

    :param ip: IP address to bind to (as integer, 0 = all interfaces)
    :type ip: integer
    :param usGamePort: Port that clients will connect to for gameplay
    :type usGamePort: integer
    :param usQueryPort: Port for Steam master server browser queries
    :type usQueryPort: integer
    :param eServerMode: Authentication and VAC mode. Use :data:`EServerMode` constants.
    :type eServerMode: integer
    :param version: String of the form x.x.x.x, where x is a digit, describing the server version
    :type version: string
    :returns: (`boolean`) **true** if the game server was initialized successfully.
    :SteamWorks: `SteamGameServer_Init <https://partner.steamgames.com/doc/api/steam_gameserver#SteamGameServer_Init>`_

    Initializes the Steamworks game server API. Call this before using any Steam game server interfaces.

.. function:: GameServerShutdown()

    :returns: nothing
    :SteamWorks: `SteamGameServer_Shutdown <https://partner.steamgames.com/doc/api/steam_gameserver#SteamGameServer_Shutdown>`_

    Shuts down the Steamworks game server API. Call this when the game server is shutting down.

.. function:: GameServerRunCallbacks()

    :returns: nothing
    :SteamWorks: `SteamGameServer_RunCallbacks <https://partner.steamgames.com/doc/api/steam_gameserver#SteamGameServer_RunCallbacks>`_

    Dispatches callbacks for the game server. Call this regularly (e.g. once per frame) while the game server is running.
