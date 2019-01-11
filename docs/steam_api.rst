#######################
SteamAPI Core Functions
#######################

List of Functions
-----------------
* :func:`init`
* :func:`shutdown`
* :func:`runCallbacks`


Function Reference
------------------

.. function:: init()

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

    if not Steam.init() then
        error("Steam couldn't initialize")
    end

.. function:: shutdown()

    :returns: nothing
    :SteamWorks: `SteamAPI_Shutdown <https://partner.steamgames.com/doc/api/steam_api#SteamAPI_Shutdown>`_

    Shuts down the Steamworks API, releases pointers and frees memory.

    You should call this during process shutdown if possible.

    This will not unhook the Steam Overlay from your game as there's no guarantee that your rendering API is done using it.

**Example**::

    function onMyGameClosing()
        Steam.shutdown()
    end

.. function:: runCallbacks()

    :returns: nothing
    :SteamWorks: `SteamAPI_RunCallbacks <https://partner.steamgames.com/doc/api/steam_api#SteamAPI_RunCallbacks>`_

    Dispatches callbacks and call results to all of the registered listeners.

    It's best to call this at >10Hz, the more time between calls, the more potential latency between receiving events or results from the Steamworks API. Most games call this once per render-frame. All registered listener functions will be invoked during this call, in the callers thread context.

    :func:`runCallbacks` is safe to call from multiple threads simultaneously, but if you choose to do this, callback code could be executed on any thread. One alternative is to call :func:`runCallbacks` from the main thread only, and call :func:`releaseCurrentThreadMemory` **(missing)** regularly on other threads.

**Example**::

    function myGameLoop(dt)
        Steam.runCallbacks()
    end
