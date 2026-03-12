.. _migration-guide:

#################################
Migration Guide from v4 to v5
#################################

v5 is a near-complete rewrite of the Lua bindings. The primary goal is to stay as
close as possible to the C++ Steamworks SDK. This guide explains what changed since v4, and is useful to port your code, as it will require some manual work. It is recommended to read the :doc:`getting_started` section as well.

The old API was hand-written and made many convenience choices (renaming fields, auto-dealing with buffer sizes). The new API auto-generates bindings
directly from the API and mirrors the C++ signatures as closely as Lua
allows. This may be less ergonomic to use, however, it scales better, we can support many more functions much more quickly. Implementing each function in v4 took a lot of work to analyze precisely what it does and how to make it as ergonomic as possible in Lua.

.. list-table::
  :header-rows: 0
  :widths: 50

  * - **BENEFITS:**
  * - **More functions supported:** The first release of v5 supported over 800 hundred Steam API functions (over 90% of all Steam API functions), while v4 supported only XXX.
  * - **Less mental overhead:** Now the API works almost exactly the same as the Steam API, so you can just read that documentation and follow it, instead of having to constantly look up two distinct documentations.
  * - **DRAWBACKS:**
  * - **Less ergonomic:** Sometimes you have to deal with buffer sizes, bitmasks, and other C++-isms manually.


.. contents:: Contents
   :local:
   :depth: 2

----

.. _migration-naming:

Naming: Everything Is PascalCase
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

Fields in returned tables (structs in C++) now also use their exact C++ names, instead of the simplified ones from v4. For example, ``entry.m_nGlobalRank`` rather than ``entry.globalRank`` for ``LeaderboardEntry_t``.

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

Parameter, Function and Return Value Changes
======================

Many functions now take a different number of parameters, or parameters of different sizes. Luasteam v4 aimed for ergonomics, so many useless parameters were removed (such as passing a table and also its size), while in v5 all parameters are required, so the conversion can be done automatically. The function return values might also be different, double check when migrating.

For example, ``UGC.getSubscribedItems()`` returned a table with the ids in v4, while ``UGC.GetSubscribedItems(cMaxEntries, bIncludeLocallyDisabled)`` in v5 takes a ``cMaxEntries`` integer with the size of the array to be allocated, which can be obtained from ``UGC.GetNumSubscribedItems(bIncludeLocallyDisabled)``, as well as taking an extra parameter ``bIncludeLocallyDisabled`` which took a default value in v4. Furthermore, it returns an integer as its first returned value (the size of the returned table), which was ommitted in v4.

.. code:: lua

    ---- In v5 ----
    local sz = Steam.UGC.GetNumSubscribedItems(false)
    local _, items = Steam.UGC.GetSubscribedItems(sz, false)
    registerItems(items)

    ---- In v4 ----
    local items = Steam.UGC.getSubscribedItems()
    registerItems(items)

In other times, some functions were fully ommitted in v4, and used automatically under the hood, while in v5 they must be manually used. As an example, ``userStats.downloadLeaderboardEntries`` automatically called ``GetDownloadedLeaderboardEntry`` for you in v4, while in v5 you must call it manually.

.. code:: lua

    ---- In v5 ----
    Steam.UserStats.DownloadLeaderboardEntries(handle, Steam.k_ELeaderboardDataRequestGlobal, 1, 1000, function(data, err)
        if err then
            print('Error happened')
        else
            for i = 0, data.m_cEntryCount - 1 do
                local ok, entry = Steam.UserStats.GetDownloadedLeaderboardEntry(data.m_hSteamLeaderboardEntries, i, 0)
                if ok then
                    local name = Steam.Friends.GetFriendPersonaName(entry.m_steamIDUser)
                    print('Rank #' .. entry.m_nGlobalRank .. ': ' .. name .. ' - ' .. entry.m_nScore)
                end
            end
        end
    end)

    ---- In v4 ----
    Steam.userStats.downloadLeaderboardEntries(handle, 'Global', 1, 1000, function(data, err)
        if err then
            print('Error happened')
        else
            for _, user in ipairs(data) do
                local name = Steam.friends.getFriendPersoneName(user.steamIDUser)
                print('Rank #' .. user.globalRank .. ': ' .. name .. ' - ' .. user.score)
            end
        end
    end

.. _migration-enums:

Enums and Constants
========================

All C++ enum constants are exposed as **plain integers** on the ``Steam`` table,
using their exact C++ names. Thus, they can be accessed by using ``Steam.<CppConstantName>``.

In v4, the enum values were not exposed anywhere, and functions that received enums often used strings with the enum name, now, they receive integers directly.

.. list-table::
   :header-rows: 1
   :widths: 30 50 10

   * - Old
     - New
     - Value
   * - ``'Installed'``
     - ``Steam.k_EItemStateInstalled``
     - 4
   * - ``'Descending'``
     - ``Steam.k_ELeaderboardSortMethodDescending``
     - 2
   * - ``'Reliable'``
     - ``Steam.k_ESteamNetworkingSend_Reliable``
     - 8

When a function returns or a callback field contains an enum value, it is always a
plain Lua integer. You can compare it directly to the constant:

.. code-block:: lua

    if data.m_eResult ~= Steam.k_EResultOK then
        print("Error:", data.m_eResult)
    end

----

.. _migration-bitflags:

Bit Flags
=============

Some API values are **bitmasks** — an integer where each bit repreLsents an independent
boolean flag. ``GetItemState``, ``GetPersonaStateFlags``, and others work this way, either to receive bitmask parameter or return bitmask values.

In v4, these values were returned as tables with many booleans, while in v5 they follow the C++ format exactly and return integers. In **LuaJIT**, use the built-in ``bit`` library for bitwise
operations:

.. code-block:: lua

    ---- In v5 ----
    local state = Steam.UGC.GetItemState(itemId)
    -- state is an integer

    local installed = bit.band(state, Steam.k_EItemStateInstalled) ~= 0
    local needsUpdate = bit.band(state, Steam.k_EItemStateNeedsUpdate) ~= 0

    ---- In v4 ----
    local state = Steam.UGC.getItemState(itemId)
    -- state is a table with boolean fields subscribed, legacyItem, ...

    local installed = state.installed
    local needsUpdate = state.needsUpdate

----

.. _migration-structs:

Structs
============

Many Steamworks functions take or return C++ structs. luasteam v5 exposes these as Lua
**userdata** with field access via metamethods, while v4 used different methods, tables or strings depending on which API method. See :ref:`getting_started-structs` on how to build and use them.

.. code:: lua

    ---- In v5 ----
    local addr = Steam.newSteamNetworkingIPAddr {}
    addr:ParseString("127.0.0.1:55556")
    let opt1 = Steam.newSteamNetworkingConfigValue_t()
    op1:SetInt32(Steam.k_ESteamNetworkingConfig_TimeoutInitial, 1000)
    local id = Steam.NetworkingSockets.ConnectByIPAddress(addr, 1, {opt1})

    ---- In v4 ----
    local id = Steam.networkingSockets.connectByIPAddress("127.0.0.1:55556", {TimeoutInitial = 1000})
    -- Note many types of options were not supported in v4 while all are in v5

----

.. _migration-callbacks:

Callbacks and CallResults
==============================

Callbacks and CallResults work very similar to v4, except for the names (and possibly types) of the fields in the callback structs, which now fully match the C++ name (e.g. ``m_eResult`` instead of ``result``).

----

.. _migration-gameserver:

GameServer Variants
========================

The initialization and shutdown of gameserver moved to be next to the core functions, so change ``Steam.gameServer.init(...)`` in v4 to ``Steam.GameServerInit(...)`` in v5. Also, now the interfaces that have a gameserver variant use acessors with the same name as in the C++ Steam API, so you can use ``Steam.GameServerUtils.XXX`` for the gameserver variant of ``Steam.Utils.XXX``, for example.

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
   * - Lifecycle
     - ``Steam.gameServer.init()``
     - ``Steam.GameServerInit()``
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
     - must pass ``0, 0`` for range (parameters not omitted)
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
     - Used as strings
     - flat on ``Steam`` table as ``Steam.k_*`` integers
