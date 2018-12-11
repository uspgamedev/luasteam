.. luasteam documentation master file, created by
   sphinx-quickstart on Mon Dec 10 18:07:32 2018.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

**luasteam** - Lua bindings for the SteamWorks API
======================================================

luasteam enables you to use SteamWorks API from Lua, for example (but not limited to) when you're building games with Love2D.

Using luasteam
================

To get started, check the `SteamWorks API Reference <https://partner.steamgames.com/doc/api>`_. The lua bindings are very similar to the C++ API, so for example

.. code-block:: C++

    #include <steam_api.h>
    // ...
    SteamFriends()->ActivateGameOverlay("achievements");

becomes

.. code-block:: Lua

    local Steam = require("luasteam")
    -- ...
    Steam.friends.activateGameOverlay("achievements")

Callbacks work a little different, for example, the ``GameOverlayActivated_t`` callback in ``ISteamUserFriends`` can be used creating a function named ``onGameOverlayActivated`` inside ``userStats``.

Original code:

.. code-block:: C++

    class Listener {
        STEAM_CALLBACK(Listener, OnGameOverlayActivated, GameOverlayActivated_t);
    };

    void Listener::OnGameOverlayActivated(GameOverlayActivated_t* data) {
        if (data->m_bActive)
            printf("Steam overlay now active\n" );
        else
            printf("Steam overlay now inactive\n");
    }

Code using luasteam:

.. code-block:: Lua

    function Steam.userStats.onGameOverlayActivated(data)
        if data.active then
            print("Steam overlay now active")
        else
            print("Steam overlay now inactive")
        end
    end

Using CallResults is also slightly different. Instead of receiving a ``SteamAPICall_t`` and registering to listen to it, you simply pass a function as the last argument to the function. This function receives two arguments: ``data`` is the object returned by the CallResult and ``err`` is a boolean indicating if there was an IO error.

Original code:

.. code-block:: C++

    class Listener {
    public:
        void FindTestLeaderboard(const char *name);

    private:
        void OnLeaderboardFindResult(LeaderboardFindResult_t *data, bool err);
        CCallResult<Listener, LeaderboardFindResult_t> leaderboardFindResult;
    };

    void Listener::OnLeaderboardFindResult(LeaderboardFindResult_t *data, bool err ) {
        if (err || data->m_bLeaderboardFound == 0)
            printf("Leaderboard not found!\n");
        else
            printf("Leaderboard found!\n");
    }

    // Make the request
    void Listener::FindTestLeaderboard() {
        SteamAPICall_t call = SteamUserStats()->FindLeaderboard("test");
        leaderboardFindResult.Set(call, this, &Listener::OnLeaderboardFindResult);
    }

Code in luasteam

.. code-block:: Lua

    Steam.userStats.findLeaderboard("test", function(data, err)
        if err or not data.leaderboardFound then
            print("Leaderboard not found!")
        else
            print("Leaderboard found!")
        end
    end)



.. toctree::
   :maxdepth: 2
   :caption: Contents:

Indices and tables
==================

* :ref:`genindex`
* :ref:`search`
