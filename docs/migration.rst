.. _migration-guide:

#################################
Migration Guide from v4 to v5
#################################

v5 is a near-complete rewrite of the Lua bindings. The primary goal is to stay as
close as possible to the C++ Steamworks SDK — if you know the C++ API, the Lua API
should feel immediately familiar. This guide explains the systematic changes and the
patterns that apply across the entire library.

The old API was hand-written and made many convenience choices (camelCase names,
auto-fetching entries, returning custom tables). The new API auto-generates bindings
directly from ``steam_api.json`` and mirrors the C++ signatures as closely as Lua
allows. When in doubt, consult the `Steamworks documentation
<https://partner.steamgames.com/doc/api>`_ alongside this guide.

.. contents:: Contents
   :local:
   :depth: 2

----

.. _migration-naming:

1. Naming: Everything Is PascalCase
=====================================

Every interface name and every function name is PascalCase, matching the C++ class
and method names exactly.

Interface subtables
-------------------

.. list-table::
   :header-rows: 1
   :widths: 40 40

   * - Old
     - New
   * - ``Steam.apps``
     - ``Steam.Apps``
   * - ``Steam.extra``
     - ``Steam.Extra``
   * - ``Steam.friends``
     - ``Steam.Friends``
   * - ``Steam.user``
     - ``Steam.User``
   * - ``Steam.userStats``
     - ``Steam.UserStats``
   * - ``Steam.utils``
     - ``Steam.Utils``

All other interfaces (``Steam.UGC``, ``Steam.NetworkingSockets``, etc.) follow the
same rule.

Top-level lifecycle functions
------------------------------

.. list-table::
   :header-rows: 1
   :widths: 40 40

   * - Old
     - New
   * - ``Steam.init()``
     - ``Steam.Init()``
   * - ``Steam.shutdown()``
     - ``Steam.Shutdown()``
   * - ``Steam.runCallbacks()``
     - ``Steam.RunCallbacks()``

GameServer lifecycle (moved out of the interface)
--------------------------------------------------

``Steam.GameServer.Init`` / ``Shutdown`` / ``RunCallbacks`` were moved to the top
level to mirror ``Steam.Init`` / ``Shutdown`` / ``RunCallbacks``:

.. list-table::
   :header-rows: 1
   :widths: 40 40

   * - Old
     - New
   * - ``Steam.GameServer.Init(...)``
     - ``Steam.GameServerInit(...)``
   * - ``Steam.GameServer.Shutdown()``
     - ``Steam.GameServerShutdown()``
   * - ``Steam.GameServer.RunCallbacks()``
     - ``Steam.GameServerRunCallbacks()``

----

.. _migration-enums:

2. Enums and Constants
========================

All C++ enum constants are exposed as **plain integers** on the ``Steam`` table,
using their exact C++ names with the ``k_`` prefix. There are no grouped sub-tables
like ``Steam.EResult`` — everything is flat.

.. code-block:: lua

    -- Access via Steam.k_<CppConstantName>
    Steam.k_EResultOK                   -- 1
    Steam.k_EItemStateInstalled         -- 4
    Steam.k_ELeaderboardSortMethodDescending
    Steam.k_ESteamNetworkingSend_Reliable

When a function returns or a callback field contains an enum value, it is always a
plain Lua integer. You can compare it directly to the constant:

.. code-block:: lua

    if data.m_eResult ~= Steam.k_EResultOK then
        print("Error:", data.m_eResult)
    end

----

.. _migration-bitflags:

3. Bit Flags
==============

Some API values are **bitmasks** — an integer where each bit represents an independent
boolean flag. ``GetItemState``, ``GetPersonaStateFlags``, and others work this way.

Since luasteam targets **LuaJIT**, use the built-in ``bit`` library for bitwise
operations:

.. code-block:: lua

    local state = Steam.UGC.GetItemState(itemId)

    -- Test a single flag
    if bit.band(state, Steam.k_EItemStateInstalled) ~= 0 then
        print("Item is installed")
    end

    -- Test multiple flags at once
    local ready = bit.band(state, Steam.k_EItemStateInstalled)
    local updating = bit.band(state, Steam.k_EItemStateNeedsUpdate)

----

.. _migration-uint64:

4. 64-bit Integers (uint64)
==============================

Lua's ``number`` type cannot safely represent 64-bit integers. Wherever the Steamworks
API uses ``uint64`` (SteamIDs, item handles, leaderboard handles, etc.), luasteam uses
a **userdata** value.

- Print with ``tostring(id)``
- Compare with ``id1 == id2``
- Convert a string or number to uint64 with ``Steam.Extra.ParseUint64(str)``

.. code-block:: lua

    local myId = Steam.User.GetSteamID()      -- returns uint64 userdata
    print(tostring(myId))                      -- "76561198000000000"

    local parsed = Steam.Extra.ParseUint64("76561198000000000")
    print(parsed == myId)                      -- true

----

.. _migration-structs:

5. Structs
============

Many Steamworks functions take or return C++ structs. luasteam exposes these as Lua
**userdata** with field access via metamethods.

Constructors
------------

Every struct has a constructor at ``Steam.newStructName([table])``. You can pass an
optional table to initialize fields:

.. code-block:: lua

    local addr = Steam.newSteamNetworkingIPAddr()
    addr.m_port = 27015

    -- Or initialize inline:
    local addr = Steam.newSteamNetworkingIPAddr({ m_port = 27015 })

Field access
------------

Struct fields are read and written directly using their C++ names (always ``m_``
prefix):

.. code-block:: lua

    local entry = -- received from GetDownloadedLeaderboardEntry
    print(entry.m_nGlobalRank)
    print(entry.m_nScore)
    print(tostring(entry.m_steamIDUser))

Fields are **mutable** — you can write to them directly:

.. code-block:: lua

    local msg = Steam.newSteamNetworkingMessage_t()
    msg.m_conn = connHandle
    msg.m_nChannel = 0

Structs as output
-----------------

When a C++ function fills a struct via an output pointer, luasteam returns it as an
extra return value (see :ref:`migration-output-params`):

.. code-block:: lua

    local ok, entry, details = Steam.UserStats.GetDownloadedLeaderboardEntry(
        data.m_hSteamLeaderboardEntries, i, 0)
    -- entry is a LeaderboardEntry_t struct

----

.. _migration-luals:

6. IDE Autocompletion (LuaLS)
================================

luasteam ships a ``luals/`` directory containing ``.d.lua`` type definitions for the
entire API. Point the `Lua Language Server <https://github.com/LuaLS/lua-language-server>`_
at this directory and your editor will offer autocompletion, inline docs, and type
checking for every function, callback, and constant.

Add to your ``.luarc.json`` (in the project root):

.. code-block:: json

    {
      "workspace.library": ["path/to/luasteam/luals"]
    }

If you use the bundled ``luals/.luarc.json`` directly via ``--configpath``, no extra
setup is needed.

----

.. _migration-callbacks:

7. Callbacks and CallResults
==============================

Both patterns require ``Steam.RunCallbacks()`` to be called every frame to dispatch
them.

Persistent Callbacks
--------------------

Some Steam events fire spontaneously (overlay opened, persona name changed, stats
received). These are **persistent callbacks** — you register them once by assigning a
function to a field on the interface table:

.. code-block:: lua

    function Steam.UserStats.OnUserStatsReceived(data)
        -- data is a UserStatsReceived_t struct
        if data.m_eResult == Steam.k_EResultOK then
            print("Stats loaded for:", tostring(data.m_steamIDUser))
        end
    end

    function Steam.Friends.OnGameOverlayActivated(data)
        if data.m_bActive ~= 0 then
            print("Overlay opened — pause the game")
        end
    end

The field name is always ``On`` + the C++ callback struct name with the ``_t``
stripped (e.g. ``GameOverlayActivated_t`` → ``OnGameOverlayActivated``).

Callbacks **cannot be unregistered** — once set they fire for the lifetime of the
Steam session.

Notification-only callbacks (no data fields)
---------------------------------------------

Some callbacks are pure notifications — they signal that something happened but carry
no payload. For example, ``SteamServersConnected_t`` fires when the client connects to
Steam but has no fields. The ``data`` table will be empty; do not attempt to read
fields from it:

.. code-block:: lua

    function Steam.User.OnSteamServersConnected(data)
        -- data has no fields — this is just a notification
        print("Connected to Steam")
    end

Boolean fields may be ``uint8``, not Lua booleans
--------------------------------------------------

Several callback struct fields that are conceptually boolean (e.g. ``m_bActive``,
``m_bSecure``) are typed as ``uint8`` in the C++ headers, not ``bool``. They arrive
in Lua as integers (``0`` or ``1``), not as Lua booleans. Always compare with
``~= 0``:

.. code-block:: lua

    -- Correct:
    if data.m_bActive ~= 0 then ... end

    -- Wrong (m_bActive is 1, not true):
    if data.m_bActive then ... end

Fields that are actually typed ``bool`` in C++ (e.g. ``m_bLeaderboardFound``) do
behave as Lua booleans. When in doubt, check the Steamworks SDK header or use
``~= 0``.

One-Shot CallResults
--------------------

Async operations (finding a leaderboard, uploading a score, creating a UGC item) take
a **callback function as their last parameter**. It fires exactly once when the
operation completes:

.. code-block:: lua

    Steam.UserStats.FindOrCreateLeaderboard("TopScores", "Descending", "Numeric",
        function(data, err)
            if err then
                print("IO error")
            elseif not data.m_bLeaderboardFound then
                print("Leaderboard not found")
            else
                local handle = data.m_hSteamLeaderboard
                -- use handle...
            end
        end)

The callback always receives **two arguments**:

1. ``data`` — the result struct (with ``m_`` fields), or nil on IO failure
2. ``err`` — ``true`` if there was an IO-level failure (Steam disconnected, etc.)

Always check ``err`` first before accessing ``data`` fields.

----

.. _migration-output-params:

8. Output Parameters Become Return Values
==========================================

In C++, many functions write results into pointer parameters passed by the caller.
In luasteam, you **do not pass these parameters** — instead they are returned as
additional values after the normal return value.

.. code-block:: cpp

    // C++ signature:
    bool GetAchievement(const char *pchName, bool *pbAchieved);

.. code-block:: lua

    -- Lua: bool, bool pbAchieved = UserStats.GetAchievement(pchName)
    local ok, achieved = Steam.UserStats.GetAchievement("MY_ACHIEVEMENT")

.. code-block:: cpp

    // C++ signature:
    bool GetDownloadedLeaderboardEntry(SteamLeaderboardEntries_t h,
        int index, LeaderboardEntry_t *pLeaderboardEntry,
        int32 *pDetails, int cDetailsMax);

.. code-block:: lua

    -- Lua: bool, LeaderboardEntry_t, int[] = GetDownloadedLeaderboardEntry(h, index, cDetailsMax)
    local ok, entry, details = Steam.UserStats.GetDownloadedLeaderboardEntry(
        entriesHandle, i, 0)

----

.. _migration-input-arrays:

9. Input Arrays: Pass Table and Count Separately
=================================================

When C++ takes ``(T *pArray, int count)``, Lua takes a table of values **and** the
count as two separate arguments:

.. code-block:: cpp

    // C++ signature:
    SteamAPICall_t DownloadLeaderboardEntriesForUsers(
        SteamLeaderboard_t h, const CSteamID *prgUsers, int cUsers);

.. code-block:: lua

    local users = { id1, id2, id3 }
    Steam.UserStats.DownloadLeaderboardEntriesForUsers(handle, users, #users, callback)

----

.. _migration-output-arrays:

10. Output Arrays: Pass Buffer Size, Receive Table
===================================================

When C++ writes results into a caller-provided array (e.g. ``T *pOut, uint32 size``),
you pass only the **desired maximum count**. luasteam allocates the buffer internally
and returns a Lua table:

.. code-block:: cpp

    // C++ signature:
    bool GetItemDefinitionIDs(SteamItemDef_t *pItemDefIDs, uint32 *punItemDefIDsArraySize);

.. code-block:: lua

    -- Lua: bool, int[] pItemDefIDs, int actualCount = GetItemDefinitionIDs(maxCount)
    local ok, ids, count = Steam.Inventory.GetItemDefinitionIDs(256)
    for i = 1, count do
        print(ids[i])
    end

The same applies to **output string buffers** — pass the maximum size (in bytes),
receive a string:

.. code-block:: cpp

    // C++ signature:
    bool GetItemDefinitionProperty(SteamItemDef_t iDef, const char *name,
        char *pchValueBuffer, uint32 *punValueBufferSizeOut);

.. code-block:: lua

    -- Lua: bool, str value, int actualLen = GetItemDefinitionProperty(def, name, bufSize)
    local ok, value, len = Steam.Inventory.GetItemDefinitionProperty(def, "name", 256)

.. tip::

    If the result is truncated (the returned size equals your requested size), call
    again with a larger buffer.

----

.. _migration-networking-message:

11. ``SteamNetworkingMessage_t`` — Special Case
================================================

``SteamNetworkingMessage_t`` is the only struct that must be **explicitly released**
after use. It has a protected destructor in C++ and cannot be copied, so luasteam
stores a pointer rather than a value.

.. code-block:: lua

    local count, msgs = Steam.NetworkingSockets.ReceiveMessagesOnConnection(conn, 32)
    for i = 1, count do
        local msg = msgs[i]
        local data    = msg.m_pData    -- payload as a Lua string
        local size    = msg.m_cbSize
        local channel = msg.m_nChannel
        msg:Release()   -- REQUIRED: free the message back to Steam
        -- Do not access msg after Release()
    end

A ``__gc`` metamethod will call ``Release()`` if you forget, but relying on that
delays the release until Lua's garbage collector runs — which can cause memory
pressure in high-throughput networking code. Always release explicitly.

----

.. _migration-gameserver:

12. GameServer Variants
========================

When running a dedicated server, most interfaces have a **GameServer variant** that
calls ``SteamGameServer*()`` instead of ``Steam*()`` internally. The methods are
identical; only the table name differs:

.. list-table::
   :header-rows: 1
   :widths: 40 40

   * - Client
     - GameServer
   * - ``Steam.Utils``
     - ``Steam.GameServerUtils``
   * - ``Steam.UGC``
     - ``Steam.GameServerUGC``
   * - ``Steam.NetworkingSockets``
     - ``Steam.GameServerNetworkingSockets``
   * - ``Steam.NetworkingMessages``
     - ``Steam.GameServerNetworkingMessages``
   * - ``Steam.Networking``
     - ``Steam.GameServerNetworking``
   * - ``Steam.HTTP``
     - ``Steam.GameServerHTTP``
   * - ``Steam.Inventory``
     - ``Steam.GameServerInventory``
   * - ``Steam.Client``
     - ``Steam.GameServerClient``

Some interfaces exist only in the GameServer context:

- ``Steam.GameServer`` — server lifecycle (``LogOn``, ``SetMapName``, etc.)
- ``Steam.GameServerStats`` — per-user stat tracking for the server

Initialize the GameServer session with ``Steam.GameServerInit(...)`` and tick it each
frame with ``Steam.GameServerRunCallbacks()``.

----

Quick-Reference: Breaking Changes from v4
==========================================

.. list-table::
   :header-rows: 1
   :widths: 20 35 35

   * - Area
     - Old
     - New
   * - Lifecycle
     - ``Steam.init()``
     - ``Steam.Init()``
   * - Lifecycle
     - ``Steam.runCallbacks()``
     - ``Steam.RunCallbacks()``
   * - Lifecycle
     - ``Steam.shutdown()``
     - ``Steam.Shutdown()``
   * - Interfaces
     - ``Steam.userStats``
     - ``Steam.UserStats`` (all PascalCase)
   * - Methods
     - ``requestCurrentStats()``
     - ``RequestCurrentStats()`` (all PascalCase)
   * - Methods
     - ``apps.isDlcInstalled``
     - ``Apps.BIsDlcInstalled`` (exact C++ name)
   * - Extra
     - ``Steam.extra.parseUint64``
     - ``Steam.Extra.ParseUint64``
   * - Callback fields
     - ``data.result``, ``data.success``, …
     - ``data.m_eResult``, ``data.m_bSuccess``, … (exact C++ struct field names)
   * - Leaderboard entries
     - ``downloadLeaderboardEntries`` returned ready-made array
     - Returns ``LeaderboardScoresDownloaded_t``; call ``GetDownloadedLeaderboardEntry(handle, i, 0)`` per entry (0-based index)
   * - ``DownloadLeaderboardEntries`` "Friends"
     - no range args
     - must pass ``0, 0`` for range
   * - ``GetSubscribedItems``
     - ``getSubscribedItems()``
     - ``GetSubscribedItems(GetNumSubscribedItems(false), false)``
   * - ``GetItemState``
     - returned table with ``.installed`` etc.
     - returns integer bitmask; check with ``bit.band(state, Steam.k_EItemStateInstalled) ~= 0``
   * - ``GetItemUpdateProgress``
     - returned status as string
     - returns integer ``EItemUpdateStatus``; compare to ``Steam.k_EItemUpdateStatus*``
   * - ``GetItemInstallInfo``
     - ``getItemInstallInfo(id)``
     - ``GetItemInstallInfo(id, bufferSize)``
   * - Enums
     - grouped sub-tables
     - flat on ``Steam`` table as ``Steam.k_*`` integers
   * - GameServer init
     - ``Steam.GameServer.Init(...)``
     - ``Steam.GameServerInit(...)``
