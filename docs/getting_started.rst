###############
Getting started
###############

Installation
============

To install luasteam, you can use one of our pre-compiled binaries in our `releases page <https://github.com/uspgamedev/luasteam/releases>`_. Make sure you're using the same version of this documentation as of the release you downloaded.

Download the correct binary for your platform and rename it to simply ``luasteam.ext``. For example, if you're using Windows 32-bits, download ``win32_luasteam.dll`` and rename it to ``luasteam.dll``.
Then copy this file to the same directory as your lua files, and make sure ``require 'luasteam'`` works.

.. warning::

    You also need to copy the correct SteamWorks library to the same directory. This library is not on the luasteam repository, and must be downloaded through the `SteamWorks website <https://partner.steamgames.com/downloads/list>`_. This version of luasteam is guaranteed to work with SteamWorks SDK v1.42, but probably works with future versions.

    After you download the SDK, you should copy the corresponding library for your platform. Here is a cheat-sheet:

    * Linux 32: ``sdk/redistributable_bin/linux32/libsteam_api.so``

    * Linux 64: ``sdk/redistributable_bin/linux64/libsteam_api.so``

    * Windows 32: ``sdk/redistributable_bin/steam_api.dll``

    * Windows 64: ``sdk/redistributable_bin/win64/steam_api64.dll``

    * OSX: ``sdk/redistributable_bin/osx32/libsteam_api.dylib``


Basic Usage
===========

luasteam tries to be very similar to the SteamWorks API, that way you don't need to learn two different APIs. Big differences (other than lua/C++ differences) are documented.

Initialization and Shutdown
---------------------------

Using the usual SteamWorks API, your code will look like:

.. code-block:: C++

    #include <steam_api.h>

    SteamAPI_Init();
    // ...
    // when game is closing
    SteamAPI_Shudown()

Doing this in luasteam should be as easy as::

    local Steam = require 'luasteam'

    Steam.init()
    -- ...
    -- when game is closing
    Steam.shutdown()

Check the `overview <https://partner.steamgames.com/doc/sdk/api#initialization_and_shutdown>`_ for more info on initialization and shutdown. When developing your game, remember to have Steam turned on and use a ``steam_appid.txt`` file.

Server mode
-----------

If you want to use this library in a server context with no steam running in the background, see the ``ISteamGameServer`` section for more info.

Normal functions
----------------

The lua bindings for normal functions are very similar to the C++ API, so for example

.. code-block:: C++

    SteamFriends()->ActivateGameOverlay("achievements");

becomes

.. code-block:: Lua

    Steam.friends.activateGameOverlay("achievements")

Callbacks
---------

Callbacks work a little different, for example, the ``GameOverlayActivated_t`` callback in ``ISteamUserFriends`` can be used creating a function named ``onGameOverlayActivated`` inside ``friends``.

Original code:

.. code-block:: C++

    class Listener {
        STEAM_CALLBACK(Listener, OnGameOverlayActivated, GameOverlayActivated_t);
    };

    void Listener::OnGameOverlayActivated(GameOverlayActivated_t* data) {
        if (data->m_bActive)
            printf("Steam overlay now active\n");
        else
            printf("Steam overlay now inactive\n");
    }

Code using luasteam:

.. code-block:: Lua

    function Steam.friends.onGameOverlayActivated(data)
        if data.active then
            print("Steam overlay now active")
        else
            print("Steam overlay now inactive")
        end
    end

CallResults
-----------

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


.. warning::

    To use Callbacks and Call Results, you **must** constantly call ``Steam.runCallbacks()``, preferably in your game loop.

.. _64-bit-integers:

64-bit integers
---------------

Some identifiers in the SteamWorks API are 64-bit integers (for example, SteamID, Leaderboard Handle, etc.).
In this documentation, these use `uint64` types instead of `number`.

Since Lua 5.1 does not support integers, and doubles (the default number type) can't hold a 64-bit integer with no error, we use userdata to keep such integers (even in Lua versions that support integers).

They can only be compared for equality or converted to strings (using the `tostring` function), since doing any math on them doesn't make any sense. You can use :func:`extra.parseUint64` to parse them from strings.

::

    local original = Steam.user.getSteamID()
    local str = tostring(original)
    print("Your id is " .. str)
    local id = Steam.extra.parseUint64(str)
    -- equality works, even though they are different userdata instances
    assert(id == original)
