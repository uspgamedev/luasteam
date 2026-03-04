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

On Linux you may need ``LD_LIBRARY_PATH=. love ...`` when running with LÖVE.

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

----

Basic Usage
===========

Initialization and Shutdown
----------------------------

.. code-block:: lua

    local Steam = require 'luasteam'

    Steam.Init()
    -- ... game loop ...
    Steam.Shutdown()

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

Call this once per frame (e.g. in your game loop or ``love.update``). Without it,
no callbacks will fire.

----

Naming Conventions
==================

Every interface name and every method name is **PascalCase**, matching the C++ API
exactly:

.. code-block:: lua

    Steam.Friends.ActivateGameOverlay("achievements")
    Steam.UserStats.RequestCurrentStats()
    Steam.Apps.BIsDlcInstalled(dlcAppId)

The interface is accessed as a sub-table of ``Steam``:

.. code-block:: text

    Steam.<Interface>.<Method>(args)

Examples:

.. code-block:: lua

    Steam.User.GetSteamID()
    Steam.Utils.GetAppID()
    Steam.NetworkingSockets.CreateListenSocketIP(addr, 0)

For overloaded methods, luasteam appends a type suffix:
``GetStatInt32``, ``GetStatFloat``, ``SetStatInt32``, ``SetStatFloat``.

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

Bit Flags
---------

Some values are bitmasks. Use the LuaJIT ``bit`` library for bitwise tests:

.. code-block:: lua

    local state = Steam.UGC.GetItemState(itemId)
    if bit.band(state, Steam.k_EItemStateInstalled) ~= 0 then
        print("Installed!")
    end

----

.. _64-bit-integers:

64-bit Integers
===============

Lua numbers cannot safely represent 64-bit integers. Wherever the Steamworks API uses
``uint64`` (SteamIDs, leaderboard handles, item handles, etc.), luasteam uses a
**userdata** value.

- Print with ``tostring(id)``
- Compare with ``id1 == id2``
- Parse from a string with ``Steam.Extra.ParseUint64(str)``

Arithmetic operators (``+``, ``-``, ``*``, ``/``, ``%``) and comparison operators
(``<``, ``<=``) are supported. Both operands may be uint64 userdata or plain Lua
numbers; the result is always a plain Lua number (``lua_Number`` / double). This means
IEEE 754 rules apply: dividing by zero returns ``inf`` or ``-inf``, and
``0 / 0`` or ``x % 0`` returns ``nan``.

.. code-block:: lua

    local myId = Steam.User.GetSteamID()   -- uint64 userdata
    print(tostring(myId))                  -- "76561198000000000"

    local parsed = Steam.Extra.ParseUint64("76561198000000000")
    assert(parsed == myId)                 -- true

----

Structs
=======

Many functions take or return C++ structs, exposed as Lua userdata with ``m_``-prefixed
field names:

.. code-block:: lua

    -- Constructing a struct:
    local addr = Steam.newSteamNetworkingIPAddr()
    addr.m_port = 27015

    -- Or inline:
    local addr = Steam.newSteamNetworkingIPAddr({ m_port = 27015 })

    -- Reading struct fields returned by a function:
    local ok, entry, details = Steam.UserStats.GetDownloadedLeaderboardEntry(h, i, 0)
    print(entry.m_nGlobalRank, entry.m_nScore)

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

.. note::

    Some ``m_b*`` boolean fields (e.g. ``m_bActive``, ``m_bSecure``) are typed as
    ``uint8`` in the C++ headers and arrive as integers in Lua. Always use ``~= 0``
    rather than checking truthiness directly.

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

The callback receives ``(data, err)`` where ``err`` is ``true`` on IO failure. Always
check ``err`` before accessing ``data``.

----

Output Parameters
=================

C++ output pointer parameters are **not passed** in Lua — they become additional
return values:

.. code-block:: lua

    -- C++: bool GetAchievement(const char *name, bool *achieved)
    local ok, achieved = Steam.UserStats.GetAchievement("MY_ACH")

----

Arrays
======

Input arrays
------------

When C++ takes ``(T *arr, int count)``, pass a table **and** the count:

.. code-block:: lua

    local users = { id1, id2, id3 }
    Steam.UserStats.DownloadLeaderboardEntriesForUsers(handle, users, #users, cb)

Output arrays
-------------

When C++ writes into a caller-provided array, pass only the **maximum count**.
luasteam returns a table and the actual count:

.. code-block:: lua

    local ok, ids, count = Steam.Inventory.GetItemDefinitionIDs(256)
    for i = 1, count do print(ids[i]) end

The same pattern applies to output string buffers — pass the max byte size, receive a
string:

.. code-block:: lua

    local ok, value, len = Steam.Inventory.GetItemDefinitionProperty(def, "name", 256)

Passing ``nil``
-------------------------

Input arrays and ``const char*`` parameters marked ``?`` accept ``nil``,
which maps to a C++ ``NULL``. Some Steam APIs treat ``NULL``s differently, like `Inventory::GetItemDefinitionProperty <https://partner.steamgames.com/doc/api/ISteamInventory#GetItemDefinitionProperty>`_ which returns a comma-separated list of all the available property names instead of a value. Example usage:

.. code-block:: lua

    -- First call: pass nil to find out how many bytes we need
    local _, pchValueBuffer, punValueBufferSizeOut = Steam.Inventory.GetItemDefinitionProperty(iDef, nil, 1024)

    print(pchValueBuffer) -- a comma-separated list of all the available property names

For output arrays or strings, wherever a size or count is marked ``?`` in the documentation (e.g. ``int?``), you may
pass ``nil`` instead of a number, so that luasteam sends a ``NULL`` output array or string. Some Steam APIs treat ``NULL``s differently, like `GetItemDefinitionIDs <https://partner.steamgames.com/doc/api/ISteamInventory#GetItemDefinitionIDs>`_ which doesn't populate the array but returns the correct array size in ``punItemDefIDsArraySize``. Example usage:

.. code-block:: lua

    -- After SteamInventoryDefinitionUpdate_t callback
    -- First call: pass nil to find out the size we need
    local _, _, punItemDefIDsArraySize = Steam.Inventory.GetItemDefinitionIDs(nil)

    -- Second call: allocate the right size and get the actual data
    local _, items, _ = Steam.Inventory.GetItemDefinitionIDs(punItemDefIDsArraySize)
    print(items)


----

Special: SteamNetworkingMessage_t
==================================

This struct works a little differently than the rest. It must be **explicitly released** after use. Furthermore, it can never be explicitly built (there's no ``newSteamNetworkingMessage_t`` method), and must just be passed around using Steam methods. Different than other structs, the Lua userdata just carries a pointer to it, not its value. Example usage:

.. code-block:: lua

    local count, msgs = Steam.NetworkingSockets.ReceiveMessagesOnConnection(conn, 32)
    for i = 1, count do
        local msg = msgs[i]
        print(msg.m_pData)   -- payload as a Lua string
        msg:Release()        -- REQUIRED
    end

----

GameServer Variants
===================

Most interfaces have a ``GameServer`` variant for dedicated servers:

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

Migrating from v4
=================

If you are upgrading from luasteam v4, see the :doc:`migration` for a complete list
of breaking changes and a quick-reference table.

