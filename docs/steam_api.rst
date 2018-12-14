#######################
SteamAPI Core Functions
#######################

List of Functions
-----------------
* :func:`shutdown`
* :func:`runCallbacks`


Function Reference
------------------


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