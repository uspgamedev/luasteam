###############
Getting Started
###############

Installation
============

Download a pre-compiled binary from the `releases page
<https://github.com/uspgamedev/luasteam/releases>`_. Pick the binary for your
platform and rename it to ``luasteam.dll`` (Windows) or ``luasteam.so`` (Linux) or
``luasteam.dylib`` (macOS). Copy it to the same directory as your Lua files so that
``require 'luasteam'`` works.

See the ``mwe/`` directory for a minimal working example.

On Linux you may need ``LD_LIBRARY_PATH=. love ...`` when running with LÖVE. This tells bash to look in the current directory for shared libraries.

.. warning::

    You also need the Steamworks shared library in the same directory. Download the
    SDK from the `Steamworks website <https://partner.steamgames.com/downloads/list>`_
    and copy the file for your platform:

    * Linux 64: ``sdk/redistributable_bin/linux64/libsteam_api.so``
    * Windows 64: ``sdk/redistributable_bin/win64/steam_api64.dll``
    * Windows 32: ``sdk/redistributable_bin/steam_api.dll``
    * macOS: ``sdk/redistributable_bin/osx/libsteam_api.dylib``

    This version of luasteam is guaranteed to work with Steamworks SDK v1.63 and
    likely works with later versions.

When developing, make sure Steam is running and place a ``steam_appid.txt`` file
(containing your App ID, or ``480`` for the Spacewar test app) next to your
executable.

How to Use
=========

luasteam aims to be a **thin wrapper** around the C++ Steamworks API. It tries to follow the C++ API as closely as possible, with only a few adjustments where necessary to fit Lua's semantics. If you're familiar with the C++ API, you should be able to pick up luasteam easily.

Always refer to the official `Steamworks API documentation <https://partner.steamgames.com/doc/api>`_ for details on what each function does, what parameters it takes, and what callbacks it triggers. The reference provided here aims to explain how to call the API from Lua, and make explicit any differences from the C++ API, but it does not explain what the API does.

The rest of the document covers the most important differences and adjustments in luasteam compared to the C++ API.

----

Basic Usage
===========

Naming Conventions
------------------

Every interface name and every method name is **PascalCase**, to match the C++ API as closely as possible. So ``SteamUserStats()->GetAchievement(ach)`` becomes ``Steam.UserStats.GetAchievement(ach)``.

.. code-block:: lua

    Steam.Friends.ActivateGameOverlay("achievements")
    Steam.UserStats.RequestCurrentStats()
    Steam.Apps.BIsDlcInstalled(dlcAppId)

.. code-block:: cpp

    // In C++ this would be:
    SteamFriends()->ActivateGameOverlay("achievements");
    SteamUserStats()->RequestCurrentStats();
    SteamApps()->BIsDlcInstalled(dlcAppId);

The interface is accessed as a sub-table of ``Steam``:

.. code-block:: text

    Steam.<Interface>.<Method>(args)

Examples:

.. code-block:: lua

    Steam.User.GetSteamID()
    Steam.Utils.GetAppID()
    Steam.NetworkingSockets.CreateListenSocketIP(addr, 0)

.. code-block:: cpp

    // In C++ this would be:
    SteamUser()->GetSteamID();
    SteamUtils()->GetAppID();
    SteamNetworkingSockets()->CreateListenSocketIP(&addr, 0);

For overloaded methods, luasteam appends a type suffix:
``GetStatInt32``, ``GetStatFloat``, ``SetStatInt32``, ``SetStatFloat``.

Initialization and Shutdown
----------------------------

.. code-block:: lua

    local Steam = require 'luasteam'

    local ok = Steam.Init()
    if not ok then
        print("Steam initialization failed")
    end
    -- ... game loop ...
    Steam.Shutdown()

.. code-block:: cpp

    // In C++ this would be:
    #include <steam/steam_api.h>
    
    if (!SteamAPI_Init()) {
        printf("Steam initialization failed\n");
    }
    // ... game loop ...
    SteamAPI_Shutdown();

``Steam.Init()`` returns ``true`` on success and ``false`` if Steam is not running or
the app ID is not found. ``Steam.Shutdown()`` must be called when the game closes.

See the `Steamworks overview
<https://partner.steamgames.com/doc/sdk/api#initialization_and_shutdown>`_ for more
details.

Calling Callbacks Every Frame
------------------------------

Both persistent callbacks and one-shot call results are dispatched only when you call:

.. code-block:: lua

    Steam.RunCallbacks()

.. code-block:: cpp

    // In C++ this would be:
    SteamAPI_RunCallbacks();

Call this once per frame (e.g. in your game loop or ``love.update``). Without it,
no callbacks will fire.

----

IDE Autocompletion
==================

The ``luals/`` directory contains ``.d.lua`` type definitions for the entire API.
Point the `Lua Language Server <https://github.com/LuaLS/lua-language-server>`_ at
it for autocompletion, inline docs, and type checking in your editor.

Add to ``.luarc.json``:

.. code-block:: json

    {
      "workspace.library": ["path/to/luasteam/luals"]
    }

----

Enums and Constants
===================

All C++ enum constants are flat on the ``Steam`` table under their exact C++ names
(including the ``k_`` prefix). There are no grouped sub-tables:

.. code-block:: lua

    Steam.k_EResultOK
    Steam.k_EItemStateInstalled
    Steam.k_ELeaderboardSortMethodDescending
    Steam.k_ESteamNetworkingSend_Reliable

Compare return values and callback fields against these constants directly:

.. code-block:: lua

    if data.m_eResult ~= Steam.k_EResultOK then
        print("Error:", data.m_eResult)
    end

.. code-block:: cpp

    // In C++ this would be:
    if (data.m_eResult != k_EResultOK) {
        printf("Error: %d\n", data.m_eResult);
    }

Bit Flags
---------

Some values are bitmasks. Use the LuaJIT ``bit`` library for bitwise tests:

.. code-block:: lua

    local state = Steam.UGC.GetItemState(itemId)
    if bit.band(state, Steam.k_EItemStateInstalled) ~= 0 then
        print("Installed!")
    end

.. code-block:: cpp

    // In C++ this would be:
    EItemState state = (EItemState)SteamUGC()->GetItemState(itemId);
    if (state & k_EItemStateInstalled) {
        printf("Installed!\n");
    }

----

.. _64-bit-integers:

64-bit Integers
===============

Lua numbers cannot safely represent 64-bit integers. Wherever the Steamworks API uses
``uint64`` (SteamIDs, leaderboard handles, item handles, etc.), luasteam uses a
**userdata** value.

- Convert to string with ``tostring(id)`` or ``id:tostring()``
- Compare with ``id1 == id2``
- Convert to a Lua number with ``id:tonumber()``
- Parse from a string or number with ``Steam.Extra.ParseUint64(str)``

.. code-block:: lua

    local myId = Steam.User.GetSteamID()   -- uint64 userdata
    print(tostring(myId))                  -- "76561198000000000"

    local parsed = Steam.Extra.ParseUint64("76561198000000000")
    assert(parsed == myId)                 -- true

.. code-block:: cpp

    // In C++ this would be:
    CSteamID myId = SteamUser()->GetSteamID();
    printf("%llu\n", myId.ConvertToUint64());

    CSteamID parsed(76561198000000000ULL);
    assert(parsed == myId);

.. note ::

    Arithmetic and comparison operators are **not** supported. Convert to a number first if you need to do math -- use ``x:tonumber()`` (``tonumber(x)`` is not supported). This conversion is lossy for values above 2^53, so be careful.


----

.. _getting_started-structs:

Structs
=======

Many functions take or return C++ structs, exposed as Lua userdata. They can be built with ``Steam.newStructName { field = value, ... }`` or by setting fields after construction. Structs returned by Steam methods can be read directly. Some examples:

.. code-block:: lua

    -- Constructing a struct:
    local addr = Steam.newSteamNetworkingIPAddr()
    addr.m_port = 27015

    -- Or inline:
    local addr = Steam.newSteamNetworkingIPAddr { m_port = 27015 }

    -- Reading struct fields returned by a function:
    local ok, entry, details = Steam.UserStats.GetDownloadedLeaderboardEntry(h, i, 0)
    print(entry.m_nGlobalRank, entry.m_nScore)

.. code-block:: cpp

    // In C++ this would be:
    SteamNetworkingIPAddr addr;
    addr.Clear();
    addr.m_port = 27015;

    LeaderboardEntry_t entry;
    int details[1];
    SteamUserStats()->GetDownloadedLeaderboardEntry(h, i, &entry, details, 0);
    printf("%d %d\n", entry.m_nGlobalRank, entry.m_nScore);



Special: SteamNetworkingMessage_t
==================================

This struct works a little differently than the rest. It must be **explicitly released** after use. Furthermore, it can never be explicitly built (there's no ``newSteamNetworkingMessage_t`` method), and must acquired using Steam methods. Different than other structs, the Lua userdata just carries a pointer to it, not its value. Example usage:

.. code-block:: lua

    local count, msgs = Steam.NetworkingSockets.ReceiveMessagesOnConnection(conn, 32)
    for i = 1, count do
        local msg = msgs[i]
        print(msg.m_pData)   -- payload as a Lua string
        msg:Release()        -- REQUIRED
    end

.. code-block:: cpp

    // In C++ this would be:
    SteamNetworkingMessage_t *msgs[32];
    int count = SteamNetworkingSockets()->ReceiveMessagesOnConnection(conn, msgs, 32);
    for (int i = 0; i < count; i++) {
        printf("%s\n",  (char *)msgs[i]->m_pData);
        msgs[i]->Release();
    }

----

Callbacks
=========

Persistent Callbacks
--------------------

Steam events (overlay opened, stats received, etc.) are handled by assigning a
function to a field on the interface table. The field name is ``On`` + the C++
callback struct name with ``_t`` stripped:

.. code-block:: lua

    -- GameOverlayActivated_t  →  OnGameOverlayActivated
    function Steam.Friends.OnGameOverlayActivated(data)
        if data.m_bActive ~= 0 then
            print("Overlay opened")
        end
    end

    -- UserStatsReceived_t  →  OnUserStatsReceived
    function Steam.UserStats.OnUserStatsReceived(data)
        if data.m_eResult == Steam.k_EResultOK then
            print("Stats ready!")
        end
    end

.. code-block:: cpp

    // In C++ this would be:
    class CallbackListener {
        private:
        STEAM_CALLBACK(CallbackListener, OnGameOverlayActivated, GameOverlayActivated_t);
    };

    void CallbackListener::OnGameOverlayActivated(GameOverlayActivated_t *data) {
        if (data->m_bActive) {
            printf("Overlay opened\n");
        }
    }
    
    // OnUserStatsReceived skipped for brevity...

.. note::

    Some ``m_b*`` boolean fields (e.g. ``m_bActive``, ``m_bSecure``) are typed as
    ``uint8`` in the C++ headers and arrive as integers in Lua.

Some callbacks carry no data — they are pure notifications:

.. code-block:: lua

    function Steam.User.OnSteamServersConnected(data)
        -- data has no fields
        print("Connected to Steam servers")
    end

CallResults
-----------

Async operations accept a callback function as their **last** argument. It fires once:

.. code-block:: lua
    
    Steam.UserStats.FindLeaderboard("HighScores", function(data, err)
        if err then
            print("IO error")
        elseif not data.m_bLeaderboardFound then
            print("Not found")
        else
            print("Handle:", tostring(data.m_hSteamLeaderboard))
        end
    end)

.. code-block:: cpp

    // In C++ this would be:
    class Listener {
        public:
        void FindLeaderboard(const char *name);

        private:
        void OnLeaderboardFindResult(LeaderboardFindResult_t *data, bool err);
        CCallResult<Listener, LeaderboardFindResult_t> leaderboardFindResult;
    };

    void Listener::OnLeaderboardFindResult(LeaderboardFindResult_t *data, bool err ) {
        if (err)
            printf("IO error\n");
        else if (!data->m_bLeaderboardFound)
            printf("Not found\n");
        else
            printf("Handle: %llu\n", data->m_hSteamLeaderboard.ConvertToUint64());
    }

    // Make the request
    void Listener::FindLeaderboard() {
        SteamAPICall_t call = SteamUserStats()->FindLeaderboard("HighScores");
        leaderboardFindResult.Set(call, this, &Listener::OnLeaderboardFindResult);
    }

The callback receives ``(data, err)`` where ``err`` is ``true`` on IO failure. Always
check ``err`` before accessing ``data``.

----

Output Parameters
=================

C++ output pointer parameters are **not passed** in Lua — they become additional
return values:

.. code-block:: lua

    local ok, achieved = Steam.UserStats.GetAchievement("MY_ACH")

.. code-block:: cpp

    // In C++ this would be:
    bool achieved;
    bool ok = SteamUserStats()->GetAchievement("MY_ACH", &achieved);

----

Arrays
======

Input arrays
------------

When C++ takes ``(T *arr, int count)``, pass a table **and** the size:

.. code-block:: lua

    local users = { id1, id2, id3 }
    Steam.UserStats.DownloadLeaderboardEntriesForUsers(handle, users, #users, callback)

.. code-block:: cpp

    // In C++ this would be:
    CSteamID users[] = { id1, id2, id3 };
    SteamAPICall_t call = SteamUserStats()->DownloadLeaderboardEntriesForUsers(handle, users, 3);
    // set up call result callback...

Output arrays
-------------

When C++ writes into a caller-provided array, pass only the **size of the buffer**.
luasteam allocates the array with that size, then returns a table with the content:

.. code-block:: lua

    local ok, ids, count = Steam.Inventory.GetItemDefinitionIDs(256)
    for i = 1, count do print(ids[i]) end

.. code-block:: cpp

    // In C++ this would be:
    SteamItemDef_t ids[256];
    uint32 count = 256;
    SteamInventory()->GetItemDefinitionIDs(ids, &count);
    for (uint32 i = 0; i < count; i++) { printf("%d\n", ids[i]); }

The way to recover the size of the returned array depends on the API. Some return it as an additional return value (like the example above), but there are other ways. Always check the documentation for the specific API you're using.
The same pattern applies to output string buffers — pass the max byte size, receive a
string:

.. code-block:: lua

    local ok, value, len = Steam.Inventory.GetItemDefinitionProperty(def, "name", 256)

.. code-block:: cpp

    // In C++ this would be:
    char value[256];
    uint32 len = sizeof(value);
    SteamInventory()->GetItemDefinitionProperty(def, "name", value, &len);

Some APIs use ``void *`` for buffers that can be either input or output. These also use lua strings, which might have a ``\0`` byte in the middle.

Passing ``nil``
-------------------------

Input arrays and string parameters marked ``?`` accept ``nil``,
which maps to a C++ ``NULL``. Some Steam APIs treat ``NULL`` s differently, like `Inventory::GetItemDefinitionProperty <https://partner.steamgames.com/doc/api/ISteamInventory#GetItemDefinitionProperty>`_ which returns a comma-separated list of all the available property names instead of a value. Example usage:

.. code-block:: lua

    local _, pchValueBuffer, punValueBufferSizeOut = Steam.Inventory.GetItemDefinitionProperty(iDef, nil, 1024)

    print(pchValueBuffer) -- a comma-separated list of all the available property names

.. code-block:: cpp

    // In C++ this would be:
    char pchValueBuffer[1024];
    uint32 size = sizeof(pchValueBuffer);
    SteamInventory()->GetItemDefinitionProperty(iDef, "name", pchValueBuffer, &size);

For output arrays or strings, wherever a size or count is marked ``?`` in the documentation (e.g. ``int?``), you may
pass ``nil`` instead of a number, so that luasteam sends a ``NULL`` output array or string. Some Steam APIs treat ``NULL`` s differently, like `GetItemDefinitionIDs <https://partner.steamgames.com/doc/api/ISteamInventory#GetItemDefinitionIDs>`_ which doesn't populate the array but returns the correct array size in ``punItemDefIDsArraySize``. Example usage:

.. code-block:: lua

    -- After SteamInventoryDefinitionUpdate_t callback
    -- First call: pass nil to find out the size we need
    local _, _, punItemDefIDsArraySize = Steam.Inventory.GetItemDefinitionIDs(nil)

    -- Second call: allocate the right size and get the actual data
    local _, items, _ = Steam.Inventory.GetItemDefinitionIDs(punItemDefIDsArraySize)
    print(items)

.. code-block:: cpp

    // In C++ this would be:
    uint32 count = 0;
    SteamInventory()->GetItemDefinitionIDs(nullptr, &count);

    // Second call: allocate and populate
    SteamItemDef_t *items = new SteamItemDef_t[count];
    SteamInventory()->GetItemDefinitionIDs(items, &count);


----

GameServer Variants
===================

Some interfaces have a ``GameServer`` variant for dedicated servers. See the `Steam Documentation <https://partner.steamgames.com/doc/sdk/api#steam_game_servers>`_.

.. code-block:: lua

    -- Initialize the game server session
    Steam.GameServerInit(unIP, usSteamPort, usGamePort, usQueryPort,
                         eServerMode, pchVersionString)

    -- Tick every frame
    Steam.GameServerRunCallbacks()

    -- GameServer interface variants:
    Steam.GameServerUtils          -- instead of Steam.Utils
    Steam.GameServerNetworkingSockets
    Steam.GameServerUGC
    -- etc.

    Steam.GameServerShutdown()

.. code-block:: cpp

    // In C++ this would be:
    SteamGameServer_Init(unIP, usSteamPort, usGamePort, usQueryPort,
                         eServerMode, pchVersionString);
    SteamGameServer_RunCallbacks();
    SteamGameServerUtils()->...        // instead of SteamUtils()
    SteamGameServerNetworkingSockets()->...
    SteamGameServerUGC()->...
    SteamGameServer_Shutdown();

----

Migrating from v4
=================

If you are upgrading from luasteam v4, see the :doc:`migration` for a complete list
of breaking changes and a quick-reference table.

