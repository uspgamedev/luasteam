###############
ISteamUserStats
###############

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✍️ are manually implemented and methods marked with ✋ are currently not implemented.

.. note::
   Overloaded Steam methods are exposed as distinct Lua functions using a type suffix (for example ``GetStatInt32`` and ``SetStatFloat``).

List of Functions
-----------------

* :func:`UserStats.AttachLeaderboardUGC`
* :func:`UserStats.ClearAchievement`
* :func:`UserStats.DownloadLeaderboardEntries`
* :func:`UserStats.DownloadLeaderboardEntriesForUsers`
* :func:`UserStats.FindLeaderboard`
* :func:`UserStats.FindOrCreateLeaderboard`
* :func:`UserStats.GetAchievement`
* :func:`UserStats.GetAchievementAchievedPercent`
* :func:`UserStats.GetAchievementAndUnlockTime`
* :func:`UserStats.GetAchievementDisplayAttribute`
* :func:`UserStats.GetAchievementIcon`
* :func:`UserStats.GetAchievementName`
* :func:`UserStats.GetAchievementProgressLimitsFloat`
* :func:`UserStats.GetAchievementProgressLimitsInt32`
* :func:`UserStats.GetDownloadedLeaderboardEntry`
* :func:`UserStats.GetGlobalStatDouble`
* :func:`UserStats.GetGlobalStatHistoryDouble`
* :func:`UserStats.GetGlobalStatHistoryInt64`
* :func:`UserStats.GetGlobalStatInt64`
* :func:`UserStats.GetLeaderboardDisplayType`
* :func:`UserStats.GetLeaderboardEntryCount`
* :func:`UserStats.GetLeaderboardName`
* :func:`UserStats.GetLeaderboardSortMethod`
* :func:`UserStats.GetMostAchievedAchievementInfo`
* :func:`UserStats.GetNextMostAchievedAchievementInfo`
* :func:`UserStats.GetNumAchievements`
* :func:`UserStats.GetNumberOfCurrentPlayers`
* :func:`UserStats.GetStatFloat`
* :func:`UserStats.GetStatInt32`
* :func:`UserStats.GetUserAchievement`
* :func:`UserStats.GetUserAchievementAndUnlockTime`
* :func:`UserStats.GetUserStatFloat`
* :func:`UserStats.GetUserStatInt32`
* :func:`UserStats.IndicateAchievementProgress`
* :func:`UserStats.RequestGlobalAchievementPercentages`
* :func:`UserStats.RequestGlobalStats`
* :func:`UserStats.RequestUserStats`
* :func:`UserStats.ResetAllStats`
* :func:`UserStats.SetAchievement`
* :func:`UserStats.SetStatFloat`
* :func:`UserStats.SetStatInt32`
* :func:`UserStats.StoreStats`
* :func:`UserStats.UpdateAvgRateStat`
* :func:`UserStats.UploadLeaderboardScore`

List of Callbacks
-----------------

* :func:`UserStats.OnUserStatsReceived`
* :func:`UserStats.OnUserStatsStored`
* :func:`UserStats.OnUserAchievementStored`
* :func:`UserStats.OnLeaderboardFindResult`
* :func:`UserStats.OnLeaderboardScoresDownloaded`
* :func:`UserStats.OnLeaderboardScoreUploaded`
* :func:`UserStats.OnNumberOfCurrentPlayers`
* :func:`UserStats.OnUserStatsUnloaded`
* :func:`UserStats.OnUserAchievementIconFetched`
* :func:`UserStats.OnGlobalAchievementPercentagesReady`
* :func:`UserStats.OnLeaderboardUGCSet`
* :func:`UserStats.OnGlobalStatsReceived`
* :func:`UserStats.OnGSStatsUnloaded`

Function Reference
------------------

.. function:: UserStats.AttachLeaderboardUGC(hSteamLeaderboard, hUGC, callback)

    🤖 **Auto-generated binding**

    :param uint64 hSteamLeaderboard:
    :param uint64 hUGC:
    :param function callback: CallResult callback receiving struct :func:`LeaderboardUGCSet_t <UserStats.OnLeaderboardUGCSet>` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `AttachLeaderboardUGC <https://partner.steamgames.com/doc/api/ISteamUserStats#AttachLeaderboardUGC>`_

.. function:: UserStats.ClearAchievement(pchName)

    🤖 **Auto-generated binding**

    :param str? pchName:
    :returns: (bool) Return value
    :SteamWorks: `ClearAchievement <https://partner.steamgames.com/doc/api/ISteamUserStats#ClearAchievement>`_

**Example**::

    Steam.UserStats.ClearAchievement('ach_name')
    Steam.UserStats.StoreStats()

.. function:: UserStats.DownloadLeaderboardEntries(hSteamLeaderboard, eLeaderboardDataRequest, nRangeStart, nRangeEnd, callback)

    🤖 **Auto-generated binding**

    :param uint64 hSteamLeaderboard:
    :param int eLeaderboardDataRequest:
    :param int nRangeStart:
    :param int nRangeEnd:
    :param function callback: CallResult callback receiving struct :func:`LeaderboardScoresDownloaded_t <UserStats.OnLeaderboardScoresDownloaded>` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `DownloadLeaderboardEntries <https://partner.steamgames.com/doc/api/ISteamUserStats#DownloadLeaderboardEntries>`_

**Example**::

    -- Download global entries 1-100
    Steam.UserStats.DownloadLeaderboardEntries(handle, 'Global', 1, 100, function(data, err)
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

.. function:: UserStats.DownloadLeaderboardEntriesForUsers(hSteamLeaderboard, prgUsers, cUsers, callback)

    🤖 **Auto-generated binding**

    :param uint64 hSteamLeaderboard:
    :param uint64[]? prgUsers:
    :param int cUsers: size of the input array ``prgUsers``
    :param function callback: CallResult callback receiving struct :func:`LeaderboardScoresDownloaded_t <UserStats.OnLeaderboardScoresDownloaded>` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `DownloadLeaderboardEntriesForUsers <https://partner.steamgames.com/doc/api/ISteamUserStats#DownloadLeaderboardEntriesForUsers>`_

**Example**::

    local friends = {friend1ID, friend2ID}
    Steam.UserStats.DownloadLeaderboardEntriesForUsers(handle, friends, #friends, function(data, err)
        if not err then
            for i = 0, data.m_cEntryCount - 1 do
                local ok, entry = Steam.UserStats.GetDownloadedLeaderboardEntry(data.m_hSteamLeaderboardEntries, i, 0)
                if ok then
                    print(tostring(entry.m_steamIDUser) .. ': ' .. entry.m_nScore)
                end
            end
        end
    end)

.. function:: UserStats.FindLeaderboard(pchLeaderboardName, callback)

    🤖 **Auto-generated binding**

    :param str? pchLeaderboardName:
    :param function callback: CallResult callback receiving struct :func:`LeaderboardFindResult_t <UserStats.OnLeaderboardFindResult>` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `FindLeaderboard <https://partner.steamgames.com/doc/api/ISteamUserStats#FindLeaderboard>`_

    Asynchronously finds a leaderboard by name.

**Example**::

    Steam.UserStats.FindLeaderboard('TopScores', function(data, err)
        if err or data.m_bLeaderboardFound == 0 then
            print('Leaderboard not found')
        else
            uploadScoresHelper(data.m_hSteamLeaderboard)
        end
    end)

.. function:: UserStats.FindOrCreateLeaderboard(pchLeaderboardName, eLeaderboardSortMethod, eLeaderboardDisplayType, callback)

    🤖 **Auto-generated binding**

    :param str? pchLeaderboardName:
    :param int eLeaderboardSortMethod:
    :param int eLeaderboardDisplayType:
    :param function callback: CallResult callback receiving struct :func:`LeaderboardFindResult_t <UserStats.OnLeaderboardFindResult>` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `FindOrCreateLeaderboard <https://partner.steamgames.com/doc/api/ISteamUserStats#FindOrCreateLeaderboard>`_

**Example**::

    Steam.UserStats.FindOrCreateLeaderboard('TopScores', 'Descending', 'Numeric', function(data, err)
        if err or data.m_bLeaderboardFound == 0 then
            print('Something happened')
        else
            uploadScoresHelper(data.m_hSteamLeaderboard)
        end
    end)

.. function:: UserStats.GetAchievement(pchName)

    🤖 **Auto-generated binding**

    :param str? pchName: The 'API Name' of the achievement
    :returns: (bool) Return value
    :returns: (bool) ``pbAchieved``
    :SteamWorks: `GetAchievement <https://partner.steamgames.com/doc/api/ISteamUserStats#GetAchievement>`_

    Gets the unlock status of an Achievement.

    **Signature differences from C++ API:**

    * Parameter ``pbAchieved`` is no longer a parameter, and is instead an additional return value

**Example**::

    local success, achieved = Steam.UserStats.GetAchievement('ach_name')
    if success and achieved then
        print('Yep, you have the achievement')
    end

.. function:: UserStats.GetAchievementAchievedPercent(pchName)

    🤖 **Auto-generated binding**

    :param str? pchName:
    :returns: (bool) Return value
    :returns: (float) ``pflPercent``
    :SteamWorks: `GetAchievementAchievedPercent <https://partner.steamgames.com/doc/api/ISteamUserStats#GetAchievementAchievedPercent>`_

    **Signature differences from C++ API:**

    * Parameter ``pflPercent`` is no longer a parameter, and is instead an additional return value

.. function:: UserStats.GetAchievementAndUnlockTime(pchName)

    🤖 **Auto-generated binding**

    :param str? pchName:
    :returns: (bool) Return value
    :returns: (bool) ``pbAchieved``
    :returns: (int) ``punUnlockTime``
    :SteamWorks: `GetAchievementAndUnlockTime <https://partner.steamgames.com/doc/api/ISteamUserStats#GetAchievementAndUnlockTime>`_

    **Signature differences from C++ API:**

    * Parameter ``pbAchieved`` is no longer a parameter, and is instead an additional return value
    * Parameter ``punUnlockTime`` is no longer a parameter, and is instead an additional return value

**Example**::

    local ok, achieved, unlockTime = Steam.UserStats.GetAchievementAndUnlockTime('ach_name')
    if ok and achieved then
        print('Unlocked at:', unlockTime)
    end

.. function:: UserStats.GetAchievementDisplayAttribute(pchName, pchKey)

    🤖 **Auto-generated binding**

    :param str? pchName:
    :param str? pchKey:
    :returns: (str) Return value
    :SteamWorks: `GetAchievementDisplayAttribute <https://partner.steamgames.com/doc/api/ISteamUserStats#GetAchievementDisplayAttribute>`_

**Example**::

    local name = Steam.UserStats.GetAchievementDisplayAttribute('ach_name', 'name')
    local desc = Steam.UserStats.GetAchievementDisplayAttribute('ach_name', 'desc')
    print(name .. ': ' .. desc)

.. function:: UserStats.GetAchievementIcon(pchName)

    🤖 **Auto-generated binding**

    :param str? pchName:
    :returns: (int) Return value
    :SteamWorks: `GetAchievementIcon <https://partner.steamgames.com/doc/api/ISteamUserStats#GetAchievementIcon>`_

.. function:: UserStats.GetAchievementName(iAchievement)

    🤖 **Auto-generated binding**

    :param int iAchievement:
    :returns: (str) Return value
    :SteamWorks: `GetAchievementName <https://partner.steamgames.com/doc/api/ISteamUserStats#GetAchievementName>`_

    **Notes:**

    * See :func:`UserStats.GetNumAchievements`'s example.

.. function:: UserStats.GetAchievementProgressLimitsFloat(pchName)

    🤖 **Auto-generated binding**

    :param str? pchName:
    :returns: (bool) Return value
    :returns: (float) ``pfMinProgress``
    :returns: (float) ``pfMaxProgress``
    :SteamWorks: `GetAchievementProgressLimits <https://partner.steamgames.com/doc/api/ISteamUserStats#GetAchievementProgressLimits>`_

    **Signature differences from C++ API:**

    * In C++, this is an overloaded method called ``GetAchievementProgressLimits``. luasteam exposes each overload as a distinct function with a type suffix.
    * Parameter ``pfMinProgress`` is no longer a parameter, and is instead an additional return value
    * Parameter ``pfMaxProgress`` is no longer a parameter, and is instead an additional return value

.. function:: UserStats.GetAchievementProgressLimitsInt32(pchName)

    🤖 **Auto-generated binding**

    :param str? pchName:
    :returns: (bool) Return value
    :returns: (int) ``pnMinProgress``
    :returns: (int) ``pnMaxProgress``
    :SteamWorks: `GetAchievementProgressLimits <https://partner.steamgames.com/doc/api/ISteamUserStats#GetAchievementProgressLimits>`_

    **Signature differences from C++ API:**

    * In C++, this is an overloaded method called ``GetAchievementProgressLimits``. luasteam exposes each overload as a distinct function with a type suffix.
    * Parameter ``pnMinProgress`` is no longer a parameter, and is instead an additional return value
    * Parameter ``pnMaxProgress`` is no longer a parameter, and is instead an additional return value

**Example**::

    local ok, minVal, maxVal = Steam.UserStats.GetAchievementProgressLimitsInt32('ach_progress')
    if ok then
        print(string.format('Progress range: %d - %d', minVal, maxVal))
    end

.. function:: UserStats.GetDownloadedLeaderboardEntry(hSteamLeaderboardEntries, index, cDetailsMax)

    🤖 **Auto-generated binding**

    :param uint64 hSteamLeaderboardEntries:
    :param int index:
    :param int? cDetailsMax: size of the buffer to allocate for ``pDetails``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (bool) Return value
    :returns: (:ref:`LeaderboardEntry_t <struct-LeaderboardEntry_t>`) ``pLeaderboardEntry``
    :returns: (int[]) ``pDetails``
    :SteamWorks: `GetDownloadedLeaderboardEntry <https://partner.steamgames.com/doc/api/ISteamUserStats#GetDownloadedLeaderboardEntry>`_

    **Signature differences from C++ API:**

    * Parameter ``pLeaderboardEntry`` is no longer a parameter, and is instead an additional return value
    * Parameter ``pDetails`` is no longer a parameter, and is instead an additional return value

.. function:: UserStats.GetGlobalStatDouble(pchStatName)

    🤖 **Auto-generated binding**

    :param str? pchStatName:
    :returns: (bool) Return value
    :returns: (float) ``pData``
    :SteamWorks: `GetGlobalStat <https://partner.steamgames.com/doc/api/ISteamUserStats#GetGlobalStat>`_

    **Signature differences from C++ API:**

    * In C++, this is an overloaded method called ``GetGlobalStat``. luasteam exposes each overload as a distinct function with a type suffix.
    * Parameter ``pData`` is no longer a parameter, and is instead an additional return value

**Example**::

    local ok, total = Steam.UserStats.GetGlobalStatDouble('total_playtime_hours')
    if ok then
        print('Total playtime hours worldwide:', total)
    end

.. function:: UserStats.GetGlobalStatHistoryDouble(pchStatName, cubData)

    🤖 **Auto-generated binding**

    :param str? pchStatName:
    :param int? cubData: size of the buffer to allocate for ``pData``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (int) Return value
    :returns: (float[]) ``pData``
    :SteamWorks: `GetGlobalStatHistory <https://partner.steamgames.com/doc/api/ISteamUserStats#GetGlobalStatHistory>`_

    **Signature differences from C++ API:**

    * In C++, this is an overloaded method called ``GetGlobalStatHistory``. luasteam exposes each overload as a distinct function with a type suffix.
    * Parameter ``pData`` is no longer a parameter, and is instead an additional return value

.. function:: UserStats.GetGlobalStatHistoryInt64(pchStatName, cubData)

    🤖 **Auto-generated binding**

    :param str? pchStatName:
    :param int? cubData: size of the buffer to allocate for ``pData``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (int) Return value
    :returns: (uint64[]) ``pData``
    :SteamWorks: `GetGlobalStatHistory <https://partner.steamgames.com/doc/api/ISteamUserStats#GetGlobalStatHistory>`_

    **Signature differences from C++ API:**

    * In C++, this is an overloaded method called ``GetGlobalStatHistory``. luasteam exposes each overload as a distinct function with a type suffix.
    * Parameter ``pData`` is no longer a parameter, and is instead an additional return value

.. function:: UserStats.GetGlobalStatInt64(pchStatName)

    🤖 **Auto-generated binding**

    :param str? pchStatName:
    :returns: (bool) Return value
    :returns: (uint64) ``pData``
    :SteamWorks: `GetGlobalStat <https://partner.steamgames.com/doc/api/ISteamUserStats#GetGlobalStat>`_

    **Signature differences from C++ API:**

    * In C++, this is an overloaded method called ``GetGlobalStat``. luasteam exposes each overload as a distinct function with a type suffix.
    * Parameter ``pData`` is no longer a parameter, and is instead an additional return value

**Example**::

    local ok, total = Steam.UserStats.GetGlobalStatInt64('total_kills')
    if ok then
        print('Total kills across all players:', total)
    end

.. function:: UserStats.GetLeaderboardDisplayType(hSteamLeaderboard)

    🤖 **Auto-generated binding**

    :param uint64 hSteamLeaderboard:
    :returns: (int) Return value
    :SteamWorks: `GetLeaderboardDisplayType <https://partner.steamgames.com/doc/api/ISteamUserStats#GetLeaderboardDisplayType>`_

    **Notes:**

    * See :func:`UserStats.GetLeaderboardName`'s example.

.. function:: UserStats.GetLeaderboardEntryCount(hSteamLeaderboard)

    🤖 **Auto-generated binding**

    :param uint64 hSteamLeaderboard:
    :returns: (int) Return value
    :SteamWorks: `GetLeaderboardEntryCount <https://partner.steamgames.com/doc/api/ISteamUserStats#GetLeaderboardEntryCount>`_

    **Notes:**

    * See :func:`UserStats.GetLeaderboardName`'s example.

.. function:: UserStats.GetLeaderboardName(hSteamLeaderboard)

    🤖 **Auto-generated binding**

    :param uint64 hSteamLeaderboard:
    :returns: (str) Return value
    :SteamWorks: `GetLeaderboardName <https://partner.steamgames.com/doc/api/ISteamUserStats#GetLeaderboardName>`_

**Example**::

    local function printLeaderboardInfo(handle)
        print('Leaderboard name: ' .. Steam.UserStats.GetLeaderboardName(handle))
        print('Entries: ' .. Steam.UserStats.GetLeaderboardEntryCount(handle))
        print('Sort Method: ' .. Steam.UserStats.GetLeaderboardSortMethod(handle))
        print('Display Type: ' .. Steam.UserStats.GetLeaderboardDisplayType(handle))
    end

.. function:: UserStats.GetLeaderboardSortMethod(hSteamLeaderboard)

    🤖 **Auto-generated binding**

    :param uint64 hSteamLeaderboard:
    :returns: (int) Return value
    :SteamWorks: `GetLeaderboardSortMethod <https://partner.steamgames.com/doc/api/ISteamUserStats#GetLeaderboardSortMethod>`_

    **Notes:**

    * See :func:`UserStats.GetLeaderboardName`'s example.

.. function:: UserStats.GetMostAchievedAchievementInfo(unNameBufLen)

    🤖 **Auto-generated binding**

    :param int? unNameBufLen: size of the buffer to allocate for ``pchName``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (int) Return value
    :returns: (str) ``pchName``
    :returns: (float) ``pflPercent``
    :returns: (bool) ``pbAchieved``
    :SteamWorks: `GetMostAchievedAchievementInfo <https://partner.steamgames.com/doc/api/ISteamUserStats#GetMostAchievedAchievementInfo>`_

    **Signature differences from C++ API:**

    * Parameter ``pchName`` is no longer a parameter, and is instead an additional return value
    * Parameter ``pflPercent`` is no longer a parameter, and is instead an additional return value
    * Parameter ``pbAchieved`` is no longer a parameter, and is instead an additional return value

**Example**::

    local iter, name, percent, achieved = Steam.UserStats.GetMostAchievedAchievementInfo(256)
    while iter ~= -1 do
        print(string.format('%s: %.1f%%', name, percent))
        iter, name, percent, achieved = Steam.UserStats.GetNextMostAchievedAchievementInfo(iter, 256)
    end

.. function:: UserStats.GetNextMostAchievedAchievementInfo(iIteratorPrevious, unNameBufLen)

    🤖 **Auto-generated binding**

    :param int iIteratorPrevious:
    :param int? unNameBufLen: size of the buffer to allocate for ``pchName``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (int) Return value
    :returns: (str) ``pchName``
    :returns: (float) ``pflPercent``
    :returns: (bool) ``pbAchieved``
    :SteamWorks: `GetNextMostAchievedAchievementInfo <https://partner.steamgames.com/doc/api/ISteamUserStats#GetNextMostAchievedAchievementInfo>`_

    **Signature differences from C++ API:**

    * Parameter ``pchName`` is no longer a parameter, and is instead an additional return value
    * Parameter ``pflPercent`` is no longer a parameter, and is instead an additional return value
    * Parameter ``pbAchieved`` is no longer a parameter, and is instead an additional return value

.. function:: UserStats.GetNumAchievements()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetNumAchievements <https://partner.steamgames.com/doc/api/ISteamUserStats#GetNumAchievements>`_

**Example**::

    local count = Steam.UserStats.GetNumAchievements()
    for i = 0, count - 1 do
        local name = Steam.UserStats.GetAchievementName(i)
        local ok, achieved = Steam.UserStats.GetAchievement(name)
        print(name .. ': ' .. (achieved and 'unlocked' or 'locked'))
    end

.. function:: UserStats.GetNumberOfCurrentPlayers(callback)

    🤖 **Auto-generated binding**

    :param function callback: CallResult callback receiving struct :func:`NumberOfCurrentPlayers_t <UserStats.OnNumberOfCurrentPlayers>` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `GetNumberOfCurrentPlayers <https://partner.steamgames.com/doc/api/ISteamUserStats#GetNumberOfCurrentPlayers>`_

**Example**::

    Steam.UserStats.GetNumberOfCurrentPlayers(function(data, err)
        if not err and data.m_bSuccess ~= 0 then
            print('Players online right now:', data.m_cPlayers)
        end
    end)

.. function:: UserStats.GetStatFloat(pchName)

    🤖 **Auto-generated binding**

    :param str? pchName:
    :returns: (bool) Return value
    :returns: (float) ``pData``
    :SteamWorks: `GetStat <https://partner.steamgames.com/doc/api/ISteamUserStats#GetStat>`_

    **Signature differences from C++ API:**

    * In C++, this is an overloaded method called ``GetStat``. luasteam exposes each overload as a distinct function with a type suffix.
    * Parameter ``pData`` is no longer a parameter, and is instead an additional return value

**Example**::

    local success, value = Steam.UserStats.GetStatFloat('accuracy')
    if success then
        print('Accuracy: ' .. value)
    end

.. function:: UserStats.GetStatInt32(pchName)

    🤖 **Auto-generated binding**

    :param str? pchName:
    :returns: (bool) Return value
    :returns: (int) ``pData``
    :SteamWorks: `GetStat <https://partner.steamgames.com/doc/api/ISteamUserStats#GetStat>`_

    **Signature differences from C++ API:**

    * In C++, this is an overloaded method called ``GetStat``. luasteam exposes each overload as a distinct function with a type suffix.
    * Parameter ``pData`` is no longer a parameter, and is instead an additional return value

**Example**::

    local success, value = Steam.UserStats.GetStatInt32('kills')
    if success then
        print('Kills: ' .. value)
    end

.. function:: UserStats.GetUserAchievement(steamIDUser, pchName)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param str? pchName:
    :returns: (bool) Return value
    :returns: (bool) ``pbAchieved``
    :SteamWorks: `GetUserAchievement <https://partner.steamgames.com/doc/api/ISteamUserStats#GetUserAchievement>`_

    **Signature differences from C++ API:**

    * Parameter ``pbAchieved`` is no longer a parameter, and is instead an additional return value

**Example**::

    local ok, achieved = Steam.UserStats.GetUserAchievement(playerSteamID, 'ach_name')
    if ok then
        print('Achievement status:', achieved)
    end

.. function:: UserStats.GetUserAchievementAndUnlockTime(steamIDUser, pchName)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param str? pchName:
    :returns: (bool) Return value
    :returns: (bool) ``pbAchieved``
    :returns: (int) ``punUnlockTime``
    :SteamWorks: `GetUserAchievementAndUnlockTime <https://partner.steamgames.com/doc/api/ISteamUserStats#GetUserAchievementAndUnlockTime>`_

    **Signature differences from C++ API:**

    * Parameter ``pbAchieved`` is no longer a parameter, and is instead an additional return value
    * Parameter ``punUnlockTime`` is no longer a parameter, and is instead an additional return value

.. function:: UserStats.GetUserStatFloat(steamIDUser, pchName)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param str? pchName:
    :returns: (bool) Return value
    :returns: (float) ``pData``
    :SteamWorks: `GetUserStat <https://partner.steamgames.com/doc/api/ISteamUserStats#GetUserStat>`_

    **Signature differences from C++ API:**

    * In C++, this is an overloaded method called ``GetUserStat``. luasteam exposes each overload as a distinct function with a type suffix.
    * Parameter ``pData`` is no longer a parameter, and is instead an additional return value

.. function:: UserStats.GetUserStatInt32(steamIDUser, pchName)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param str? pchName:
    :returns: (bool) Return value
    :returns: (int) ``pData``
    :SteamWorks: `GetUserStat <https://partner.steamgames.com/doc/api/ISteamUserStats#GetUserStat>`_

    **Signature differences from C++ API:**

    * In C++, this is an overloaded method called ``GetUserStat``. luasteam exposes each overload as a distinct function with a type suffix.
    * Parameter ``pData`` is no longer a parameter, and is instead an additional return value

**Example**::

    local ok, value = Steam.UserStats.GetUserStatInt32(playerSteamID, 'kills')
    if ok then
        print('Player kills:', value)
    end

.. function:: UserStats.IndicateAchievementProgress(pchName, nCurProgress, nMaxProgress)

    🤖 **Auto-generated binding**

    :param str? pchName:
    :param int nCurProgress:
    :param int nMaxProgress:
    :returns: (bool) Return value
    :SteamWorks: `IndicateAchievementProgress <https://partner.steamgames.com/doc/api/ISteamUserStats#IndicateAchievementProgress>`_

**Example**::

    -- Show progress notification without unlocking yet
    Steam.UserStats.IndicateAchievementProgress('ach_kills', currentKills, 100)

.. function:: UserStats.RequestGlobalAchievementPercentages(callback)

    🤖 **Auto-generated binding**

    :param function callback: CallResult callback receiving struct :func:`GlobalAchievementPercentagesReady_t <UserStats.OnGlobalAchievementPercentagesReady>` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `RequestGlobalAchievementPercentages <https://partner.steamgames.com/doc/api/ISteamUserStats#RequestGlobalAchievementPercentages>`_

**Example**::

    Steam.UserStats.RequestGlobalAchievementPercentages(function(data, err)
        if not err and data.m_eResult == Steam.k_EResultOK then
            local ok, pct = Steam.UserStats.GetAchievementAchievedPercent('ach_name')
            print('Worldwide unlock rate:', pct .. '%')
        end
    end)

.. function:: UserStats.RequestGlobalStats(nHistoryDays, callback)

    🤖 **Auto-generated binding**

    :param int nHistoryDays:
    :param function callback: CallResult callback receiving struct :func:`GlobalStatsReceived_t <UserStats.OnGlobalStatsReceived>` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `RequestGlobalStats <https://partner.steamgames.com/doc/api/ISteamUserStats#RequestGlobalStats>`_

**Example**::

    Steam.UserStats.RequestGlobalStats(7, function(data, err)
        if not err and data.m_eResult == Steam.k_EResultOK then
            local ok, total = Steam.UserStats.GetGlobalStatInt64('total_kills')
            print('Global kills (last 7 days):', total)
        end
    end)

.. function:: UserStats.RequestUserStats(steamIDUser, callback)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param function callback: CallResult callback receiving struct :func:`UserStatsReceived_t <UserStats.OnUserStatsReceived>` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `RequestUserStats <https://partner.steamgames.com/doc/api/ISteamUserStats#RequestUserStats>`_

**Example**::

    Steam.UserStats.RequestUserStats(playerSteamID, function(data, err)
        if err or data.m_eResult ~= Steam.k_EResultOK then
            print('Failed to get user stats')
            return
        end
        local ok, kills = Steam.UserStats.GetUserStatInt32(playerSteamID, 'kills')
        print('Player kills:', kills)
    end)

.. function:: UserStats.ResetAllStats(bAchievementsToo)

    🤖 **Auto-generated binding**

    :param bool bAchievementsToo:
    :returns: (bool) Return value
    :SteamWorks: `ResetAllStats <https://partner.steamgames.com/doc/api/ISteamUserStats#ResetAllStats>`_

**Example**::

    if dev_mode and keypressed('f10') then
        Steam.UserStats.ResetAllStats(true)
    end

.. function:: UserStats.SetAchievement(pchName)

    🤖 **Auto-generated binding**

    :param str? pchName: The 'API Name' of the achievement
    :returns: (bool) Return value
    :SteamWorks: `SetAchievement <https://partner.steamgames.com/doc/api/ISteamUserStats#SetAchievement>`_

    Unlocks an achievement. Call StoreStats() to persist.

**Example**::

    if achievementConditionSatisfied() then
        Steam.UserStats.SetAchievement('ach_name')
        Steam.UserStats.StoreStats()  -- shows overlay notification
    end

.. function:: UserStats.SetStatFloat(pchName, fData)

    🤖 **Auto-generated binding**

    :param str? pchName:
    :param float fData:
    :returns: (bool) Return value
    :SteamWorks: `SetStat <https://partner.steamgames.com/doc/api/ISteamUserStats#SetStat>`_

    **Signature differences from C++ API:**

    * In C++, this is an overloaded method called ``SetStat``. luasteam exposes each overload as a distinct function with a type suffix.

**Example**::

    Steam.UserStats.SetStatFloat('accuracy', 0.75)
    Steam.UserStats.StoreStats()

.. function:: UserStats.SetStatInt32(pchName, nData)

    🤖 **Auto-generated binding**

    :param str? pchName:
    :param int nData:
    :returns: (bool) Return value
    :SteamWorks: `SetStat <https://partner.steamgames.com/doc/api/ISteamUserStats#SetStat>`_

    **Signature differences from C++ API:**

    * In C++, this is an overloaded method called ``SetStat``. luasteam exposes each overload as a distinct function with a type suffix.

**Example**::

    Steam.UserStats.SetStatInt32('kills', 43)
    Steam.UserStats.StoreStats()

.. function:: UserStats.StoreStats()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `StoreStats <https://partner.steamgames.com/doc/api/ISteamUserStats#StoreStats>`_

    Stores the current stats and achievements on the server. This will cause a callback when complete.

**Example**::

    Steam.UserStats.SetStatInt32('kills', 100)
    Steam.UserStats.StoreStats()

.. function:: UserStats.UpdateAvgRateStat(pchName, flCountThisSession, dSessionLength)

    🤖 **Auto-generated binding**

    :param str? pchName:
    :param float flCountThisSession:
    :param float dSessionLength:
    :returns: (bool) Return value
    :SteamWorks: `UpdateAvgRateStat <https://partner.steamgames.com/doc/api/ISteamUserStats#UpdateAvgRateStat>`_

**Example**::

    -- Track rolling average of score per session length
    Steam.UserStats.UpdateAvgRateStat('avg_score_per_hour', sessionScore, sessionSeconds / 3600)
    Steam.UserStats.StoreStats()

.. function:: UserStats.UploadLeaderboardScore(hSteamLeaderboard, eLeaderboardUploadScoreMethod, nScore, pScoreDetails, cScoreDetailsCount, callback)

    🤖 **Auto-generated binding**

    :param uint64 hSteamLeaderboard:
    :param int eLeaderboardUploadScoreMethod:
    :param int nScore:
    :param int[]? pScoreDetails:
    :param int cScoreDetailsCount: size of the input array ``pScoreDetails``
    :param function callback: CallResult callback receiving struct :func:`LeaderboardScoreUploaded_t <UserStats.OnLeaderboardScoreUploaded>` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `UploadLeaderboardScore <https://partner.steamgames.com/doc/api/ISteamUserStats#UploadLeaderboardScore>`_

    Uploads a user score to a specified leaderboard.

**Example**::

    local function uploadScoresHelper(handle)
        local score = getScore()
        Steam.UserStats.UploadLeaderboardScore(handle, 'KeepBest', score, nil, function(data, err)
            if err or data.m_bSuccess == 0 then
                print('Upload score failed')
            else
                print('Upload score success. New rank is: ' .. data.m_nGlobalRankNew)
            end
        end)
    end


Callbacks
---------

.. function:: UserStats.OnUserStatsReceived

    Callback for `UserStatsReceived_t <https://partner.steamgames.com/doc/api/ISteamUserStats#UserStatsReceived_t>`_

    **callback(data)** receives:

    * **data.m_nGameID** *(uint64)*
    * **data.m_eResult** *(EResult)*
    * **data.m_steamIDUser** *(uint64)*

**Example**::

    function Steam.UserStats.OnUserStatsReceived(data)
        if data.m_eResult == Steam.k_EResultOK then
            print('Stats loaded for user:', tostring(data.m_steamIDUser))
        end
    end

.. function:: UserStats.OnUserStatsStored

    Callback for `UserStatsStored_t <https://partner.steamgames.com/doc/api/ISteamUserStats#UserStatsStored_t>`_

    **callback(data)** receives:

    * **data.m_nGameID** *(uint64)*
    * **data.m_eResult** *(EResult)*

**Example**::

    function Steam.UserStats.OnUserStatsStored(data)
        if data.m_eResult == Steam.k_EResultOK then
            print('Stats saved successfully')
        else
            print('Stats save failed:', data.m_eResult)
        end
    end

.. function:: UserStats.OnUserAchievementStored

    Callback for `UserAchievementStored_t <https://partner.steamgames.com/doc/api/ISteamUserStats#UserAchievementStored_t>`_

    **callback(data)** receives:

    * **data.m_nGameID** *(uint64)*
    * **data.m_bGroupAchievement** *(bool)*
    * **data.m_rgchAchievementName** *(string)*
    * **data.m_nCurProgress** *(int)*
    * **data.m_nMaxProgress** *(int)*

**Example**::

    function Steam.UserStats.OnUserAchievementStored(data)
        print('Achievement stored:', data.m_rgchAchievementName)
        if data.m_nMaxProgress > 0 then
            print(data.m_nCurProgress .. '/' .. data.m_nMaxProgress)
        end
    end

.. function:: UserStats.OnLeaderboardFindResult

    Callback for `LeaderboardFindResult_t <https://partner.steamgames.com/doc/api/ISteamUserStats#LeaderboardFindResult_t>`_

    **callback(data)** receives:

    * **data.m_hSteamLeaderboard** *(SteamLeaderboard_t)*
    * **data.m_bLeaderboardFound** *(int)*

**Example**::

    function Steam.UserStats.OnLeaderboardFindResult(data)
        if data.m_bLeaderboardFound then
            print('Leaderboard handle:', tostring(data.m_hSteamLeaderboard))
        end
    end

.. function:: UserStats.OnLeaderboardScoresDownloaded

    Callback for `LeaderboardScoresDownloaded_t <https://partner.steamgames.com/doc/api/ISteamUserStats#LeaderboardScoresDownloaded_t>`_

    **callback(data)** receives:

    * **data.m_hSteamLeaderboard** *(SteamLeaderboard_t)*
    * **data.m_hSteamLeaderboardEntries** *(SteamLeaderboardEntries_t)*
    * **data.m_cEntryCount** *(int)*

.. function:: UserStats.OnLeaderboardScoreUploaded

    Callback for `LeaderboardScoreUploaded_t <https://partner.steamgames.com/doc/api/ISteamUserStats#LeaderboardScoreUploaded_t>`_

    **callback(data)** receives:

    * **data.m_bSuccess** *(int)*
    * **data.m_hSteamLeaderboard** *(SteamLeaderboard_t)*
    * **data.m_nScore** *(int)*
    * **data.m_bScoreChanged** *(int)*
    * **data.m_nGlobalRankNew** *(int)*
    * **data.m_nGlobalRankPrevious** *(int)*

**Example**::

    function Steam.UserStats.OnLeaderboardScoreUploaded(data)
        if data.m_bSuccess ~= 0 then
            print('New rank:', data.m_nGlobalRankNew)
        end
    end

.. function:: UserStats.OnNumberOfCurrentPlayers

    Callback for `NumberOfCurrentPlayers_t <https://partner.steamgames.com/doc/api/ISteamUserStats#NumberOfCurrentPlayers_t>`_

    **callback(data)** receives:

    * **data.m_bSuccess** *(int)*
    * **data.m_cPlayers** *(int)*

.. function:: UserStats.OnUserStatsUnloaded

    Callback for `UserStatsUnloaded_t <https://partner.steamgames.com/doc/api/ISteamUserStats#UserStatsUnloaded_t>`_

    **callback(data)** receives:

    * **data.m_steamIDUser** *(uint64)*

.. function:: UserStats.OnUserAchievementIconFetched

    Callback for `UserAchievementIconFetched_t <https://partner.steamgames.com/doc/api/ISteamUserStats#UserAchievementIconFetched_t>`_

    **callback(data)** receives:

    * **data.m_nGameID** *(CGameID)*
    * **data.m_rgchAchievementName** *(string)*
    * **data.m_bAchieved** *(bool)*
    * **data.m_nIconHandle** *(int)*

.. function:: UserStats.OnGlobalAchievementPercentagesReady

    Callback for `GlobalAchievementPercentagesReady_t <https://partner.steamgames.com/doc/api/ISteamUserStats#GlobalAchievementPercentagesReady_t>`_

    **callback(data)** receives:

    * **data.m_nGameID** *(uint64)*
    * **data.m_eResult** *(EResult)*

**Example**::

    function Steam.UserStats.OnGlobalAchievementPercentagesReady(data)
        if data.m_eResult == Steam.k_EResultOK then
            local ok, pct = Steam.UserStats.GetAchievementAchievedPercent('first_kill')
            print('First kill achievement: ' .. pct .. '% of players')
        end
    end

.. function:: UserStats.OnLeaderboardUGCSet

    Callback for `LeaderboardUGCSet_t <https://partner.steamgames.com/doc/api/ISteamUserStats#LeaderboardUGCSet_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(EResult)*
    * **data.m_hSteamLeaderboard** *(SteamLeaderboard_t)*

.. function:: UserStats.OnGlobalStatsReceived

    Callback for `GlobalStatsReceived_t <https://partner.steamgames.com/doc/api/ISteamUserStats#GlobalStatsReceived_t>`_

    **callback(data)** receives:

    * **data.m_nGameID** *(uint64)*
    * **data.m_eResult** *(EResult)*

.. function:: UserStats.OnGSStatsUnloaded

    Callback for `GSStatsUnloaded_t <https://partner.steamgames.com/doc/api/ISteamUserStats#GSStatsUnloaded_t>`_

    **callback(data)** receives:

    * **data.m_steamIDUser** *(uint64)*

