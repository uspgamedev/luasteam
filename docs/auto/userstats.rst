###############
ISteamUserStats
###############

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✋ require manual implementation.

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

* :func:`UserStats.onUserStatsReceived`
* :func:`UserStats.onUserStatsStored`
* :func:`UserStats.onUserAchievementStored`
* :func:`UserStats.onLeaderboardFindResult`
* :func:`UserStats.onLeaderboardScoresDownloaded`
* :func:`UserStats.onLeaderboardScoreUploaded`
* :func:`UserStats.onNumberOfCurrentPlayers`
* :func:`UserStats.onUserStatsUnloaded`
* :func:`UserStats.onUserAchievementIconFetched`
* :func:`UserStats.onGlobalAchievementPercentagesReady`
* :func:`UserStats.onLeaderboardUGCSet`
* :func:`UserStats.onGlobalStatsReceived`
* :func:`UserStats.onGSStatsUnloaded`

Function Reference
------------------

.. function:: UserStats.AttachLeaderboardUGC(hSteamLeaderboard, hUGC, callback)

    🤖 **Auto-generated binding**

    :param uint64 hSteamLeaderboard:
    :param uint64 hUGC:
    :param function callback: CallResult callback receiving struct `LeaderboardUGCSet_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `AttachLeaderboardUGC <https://partner.steamgames.com/doc/api/ISteamUserStats#AttachLeaderboardUGC>`_

.. function:: UserStats.ClearAchievement(pchName)

    🤖 **Auto-generated binding**

    :param str pchName:
    :returns: (bool) Return value
    :SteamWorks: `ClearAchievement <https://partner.steamgames.com/doc/api/ISteamUserStats#ClearAchievement>`_

.. function:: UserStats.DownloadLeaderboardEntries(hSteamLeaderboard, eLeaderboardDataRequest, nRangeStart, nRangeEnd, callback)

    🤖 **Auto-generated binding**

    :param uint64 hSteamLeaderboard:
    :param int eLeaderboardDataRequest:
    :param int nRangeStart:
    :param int nRangeEnd:
    :param function callback: CallResult callback receiving struct `LeaderboardScoresDownloaded_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `DownloadLeaderboardEntries <https://partner.steamgames.com/doc/api/ISteamUserStats#DownloadLeaderboardEntries>`_

.. function:: UserStats.DownloadLeaderboardEntriesForUsers(hSteamLeaderboard, prgUsers, cUsers, callback)

    🤖 **Auto-generated binding**

    :param uint64 hSteamLeaderboard:
    :param uint64[] prgUsers:
    :param int cUsers:
    :param function callback: CallResult callback receiving struct `LeaderboardScoresDownloaded_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `DownloadLeaderboardEntriesForUsers <https://partner.steamgames.com/doc/api/ISteamUserStats#DownloadLeaderboardEntriesForUsers>`_

.. function:: UserStats.FindLeaderboard(pchLeaderboardName, callback)

    🤖 **Auto-generated binding**

    :param str pchLeaderboardName:
    :param function callback: CallResult callback receiving struct `LeaderboardFindResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `FindLeaderboard <https://partner.steamgames.com/doc/api/ISteamUserStats#FindLeaderboard>`_

.. function:: UserStats.FindOrCreateLeaderboard(pchLeaderboardName, eLeaderboardSortMethod, eLeaderboardDisplayType, callback)

    🤖 **Auto-generated binding**

    :param str pchLeaderboardName:
    :param int eLeaderboardSortMethod:
    :param int eLeaderboardDisplayType:
    :param function callback: CallResult callback receiving struct `LeaderboardFindResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `FindOrCreateLeaderboard <https://partner.steamgames.com/doc/api/ISteamUserStats#FindOrCreateLeaderboard>`_

.. function:: UserStats.GetAchievement(pchName)

    🤖 **Auto-generated binding**

    :param str pchName:
    :returns: (bool) Return value
    :returns: (bool) Value for `pbAchieved`
    :SteamWorks: `GetAchievement <https://partner.steamgames.com/doc/api/ISteamUserStats#GetAchievement>`_

    **Signature differences from C++ API:**

    * Parameter ``pbAchieved`` is no longer a paramer, and is instead an additional return value

.. function:: UserStats.GetAchievementAchievedPercent(pchName)

    🤖 **Auto-generated binding**

    :param str pchName:
    :returns: (bool) Return value
    :returns: (float) Value for `pflPercent`
    :SteamWorks: `GetAchievementAchievedPercent <https://partner.steamgames.com/doc/api/ISteamUserStats#GetAchievementAchievedPercent>`_

    **Signature differences from C++ API:**

    * Parameter ``pflPercent`` is no longer a paramer, and is instead an additional return value

.. function:: UserStats.GetAchievementAndUnlockTime(pchName)

    🤖 **Auto-generated binding**

    :param str pchName:
    :returns: (bool) Return value
    :returns: (bool) Value for `pbAchieved`
    :returns: (int) Value for `punUnlockTime`
    :SteamWorks: `GetAchievementAndUnlockTime <https://partner.steamgames.com/doc/api/ISteamUserStats#GetAchievementAndUnlockTime>`_

    **Signature differences from C++ API:**

    * Parameter ``pbAchieved`` is no longer a paramer, and is instead an additional return value
    * Parameter ``punUnlockTime`` is no longer a paramer, and is instead an additional return value

.. function:: UserStats.GetAchievementDisplayAttribute(pchName, pchKey)

    🤖 **Auto-generated binding**

    :param str pchName:
    :param str pchKey:
    :returns: (str) Return value
    :SteamWorks: `GetAchievementDisplayAttribute <https://partner.steamgames.com/doc/api/ISteamUserStats#GetAchievementDisplayAttribute>`_

.. function:: UserStats.GetAchievementIcon(pchName)

    🤖 **Auto-generated binding**

    :param str pchName:
    :returns: (int) Return value
    :SteamWorks: `GetAchievementIcon <https://partner.steamgames.com/doc/api/ISteamUserStats#GetAchievementIcon>`_

.. function:: UserStats.GetAchievementName(iAchievement)

    🤖 **Auto-generated binding**

    :param int iAchievement:
    :returns: (str) Return value
    :SteamWorks: `GetAchievementName <https://partner.steamgames.com/doc/api/ISteamUserStats#GetAchievementName>`_

.. function:: UserStats.GetAchievementProgressLimitsFloat(pchName)

    🤖 **Auto-generated binding**

    :param str pchName:
    :returns: (bool) Return value
    :returns: (float) Value for `pfMinProgress`
    :returns: (float) Value for `pfMaxProgress`
    :SteamWorks: `GetAchievementProgressLimitsFloat <https://partner.steamgames.com/doc/api/ISteamUserStats#GetAchievementProgressLimitsFloat>`_

    **Signature differences from C++ API:**

    * Parameter ``pfMinProgress`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pfMaxProgress`` is no longer a paramer, and is instead an additional return value

.. function:: UserStats.GetAchievementProgressLimitsInt32(pchName)

    🤖 **Auto-generated binding**

    :param str pchName:
    :returns: (bool) Return value
    :returns: (int) Value for `pnMinProgress`
    :returns: (int) Value for `pnMaxProgress`
    :SteamWorks: `GetAchievementProgressLimitsInt32 <https://partner.steamgames.com/doc/api/ISteamUserStats#GetAchievementProgressLimitsInt32>`_

    **Signature differences from C++ API:**

    * Parameter ``pnMinProgress`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pnMaxProgress`` is no longer a paramer, and is instead an additional return value

.. function:: UserStats.GetDownloadedLeaderboardEntry(hSteamLeaderboardEntries, index, cDetailsMax)

    🤖 **Auto-generated binding**

    :param uint64 hSteamLeaderboardEntries:
    :param int index:
    :param int cDetailsMax:
    :returns: (bool) Return value
    :returns: (:ref:`LeaderboardEntry_t <struct-LeaderboardEntry_t>`) Value for `pLeaderboardEntry`
    :returns: (int[]) Value for `pDetails`
    :SteamWorks: `GetDownloadedLeaderboardEntry <https://partner.steamgames.com/doc/api/ISteamUserStats#GetDownloadedLeaderboardEntry>`_

    **Signature differences from C++ API:**

    * Parameter ``pLeaderboardEntry`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pDetails`` is no longer a paramer, and is instead an additional return value

.. function:: UserStats.GetGlobalStatDouble(pchStatName)

    🤖 **Auto-generated binding**

    :param str pchStatName:
    :returns: (bool) Return value
    :returns: (float) Value for `pData`
    :SteamWorks: `GetGlobalStatDouble <https://partner.steamgames.com/doc/api/ISteamUserStats#GetGlobalStatDouble>`_

    **Signature differences from C++ API:**

    * Parameter ``pData`` is no longer a paramer, and is instead an additional return value

.. function:: UserStats.GetGlobalStatHistoryDouble(pchStatName, cubData)

    🤖 **Auto-generated binding**

    :param str pchStatName:
    :param int cubData:
    :returns: (int) Return value
    :returns: (float[]) Value for `pData`
    :SteamWorks: `GetGlobalStatHistoryDouble <https://partner.steamgames.com/doc/api/ISteamUserStats#GetGlobalStatHistoryDouble>`_

    **Signature differences from C++ API:**

    * Parameter ``pData`` is no longer a paramer, and is instead an additional return value

.. function:: UserStats.GetGlobalStatHistoryInt64(pchStatName, cubData)

    🤖 **Auto-generated binding**

    :param str pchStatName:
    :param int cubData:
    :returns: (int) Return value
    :returns: (uint64[]) Value for `pData`
    :SteamWorks: `GetGlobalStatHistoryInt64 <https://partner.steamgames.com/doc/api/ISteamUserStats#GetGlobalStatHistoryInt64>`_

    **Signature differences from C++ API:**

    * Parameter ``pData`` is no longer a paramer, and is instead an additional return value

.. function:: UserStats.GetGlobalStatInt64(pchStatName)

    🤖 **Auto-generated binding**

    :param str pchStatName:
    :returns: (bool) Return value
    :returns: (uint64) Value for `pData`
    :SteamWorks: `GetGlobalStatInt64 <https://partner.steamgames.com/doc/api/ISteamUserStats#GetGlobalStatInt64>`_

    **Signature differences from C++ API:**

    * Parameter ``pData`` is no longer a paramer, and is instead an additional return value

.. function:: UserStats.GetLeaderboardDisplayType(hSteamLeaderboard)

    🤖 **Auto-generated binding**

    :param uint64 hSteamLeaderboard:
    :returns: (int) Return value
    :SteamWorks: `GetLeaderboardDisplayType <https://partner.steamgames.com/doc/api/ISteamUserStats#GetLeaderboardDisplayType>`_

.. function:: UserStats.GetLeaderboardEntryCount(hSteamLeaderboard)

    🤖 **Auto-generated binding**

    :param uint64 hSteamLeaderboard:
    :returns: (int) Return value
    :SteamWorks: `GetLeaderboardEntryCount <https://partner.steamgames.com/doc/api/ISteamUserStats#GetLeaderboardEntryCount>`_

.. function:: UserStats.GetLeaderboardName(hSteamLeaderboard)

    🤖 **Auto-generated binding**

    :param uint64 hSteamLeaderboard:
    :returns: (str) Return value
    :SteamWorks: `GetLeaderboardName <https://partner.steamgames.com/doc/api/ISteamUserStats#GetLeaderboardName>`_

.. function:: UserStats.GetLeaderboardSortMethod(hSteamLeaderboard)

    🤖 **Auto-generated binding**

    :param uint64 hSteamLeaderboard:
    :returns: (int) Return value
    :SteamWorks: `GetLeaderboardSortMethod <https://partner.steamgames.com/doc/api/ISteamUserStats#GetLeaderboardSortMethod>`_

.. function:: UserStats.GetMostAchievedAchievementInfo(unNameBufLen)

    🤖 **Auto-generated binding**

    :param int unNameBufLen:
    :returns: (int) Return value
    :returns: (str) Value for `pchName`
    :returns: (float) Value for `pflPercent`
    :returns: (bool) Value for `pbAchieved`
    :SteamWorks: `GetMostAchievedAchievementInfo <https://partner.steamgames.com/doc/api/ISteamUserStats#GetMostAchievedAchievementInfo>`_

    **Signature differences from C++ API:**

    * Parameter ``pchName`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pflPercent`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pbAchieved`` is no longer a paramer, and is instead an additional return value

.. function:: UserStats.GetNextMostAchievedAchievementInfo(iIteratorPrevious, unNameBufLen)

    🤖 **Auto-generated binding**

    :param int iIteratorPrevious:
    :param int unNameBufLen:
    :returns: (int) Return value
    :returns: (str) Value for `pchName`
    :returns: (float) Value for `pflPercent`
    :returns: (bool) Value for `pbAchieved`
    :SteamWorks: `GetNextMostAchievedAchievementInfo <https://partner.steamgames.com/doc/api/ISteamUserStats#GetNextMostAchievedAchievementInfo>`_

    **Signature differences from C++ API:**

    * Parameter ``pchName`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pflPercent`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pbAchieved`` is no longer a paramer, and is instead an additional return value

.. function:: UserStats.GetNumAchievements()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetNumAchievements <https://partner.steamgames.com/doc/api/ISteamUserStats#GetNumAchievements>`_

.. function:: UserStats.GetNumberOfCurrentPlayers(callback)

    🤖 **Auto-generated binding**

    :param function callback: CallResult callback receiving struct `NumberOfCurrentPlayers_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `GetNumberOfCurrentPlayers <https://partner.steamgames.com/doc/api/ISteamUserStats#GetNumberOfCurrentPlayers>`_

.. function:: UserStats.GetStatFloat(pchName)

    🤖 **Auto-generated binding**

    :param str pchName:
    :returns: (bool) Return value
    :returns: (float) Value for `pData`
    :SteamWorks: `GetStatFloat <https://partner.steamgames.com/doc/api/ISteamUserStats#GetStatFloat>`_

    **Signature differences from C++ API:**

    * Parameter ``pData`` is no longer a paramer, and is instead an additional return value

.. function:: UserStats.GetStatInt32(pchName)

    🤖 **Auto-generated binding**

    :param str pchName:
    :returns: (bool) Return value
    :returns: (int) Value for `pData`
    :SteamWorks: `GetStatInt32 <https://partner.steamgames.com/doc/api/ISteamUserStats#GetStatInt32>`_

    **Signature differences from C++ API:**

    * Parameter ``pData`` is no longer a paramer, and is instead an additional return value

.. function:: UserStats.GetUserAchievement(steamIDUser, pchName)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param str pchName:
    :returns: (bool) Return value
    :returns: (bool) Value for `pbAchieved`
    :SteamWorks: `GetUserAchievement <https://partner.steamgames.com/doc/api/ISteamUserStats#GetUserAchievement>`_

    **Signature differences from C++ API:**

    * Parameter ``pbAchieved`` is no longer a paramer, and is instead an additional return value

.. function:: UserStats.GetUserAchievementAndUnlockTime(steamIDUser, pchName)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param str pchName:
    :returns: (bool) Return value
    :returns: (bool) Value for `pbAchieved`
    :returns: (int) Value for `punUnlockTime`
    :SteamWorks: `GetUserAchievementAndUnlockTime <https://partner.steamgames.com/doc/api/ISteamUserStats#GetUserAchievementAndUnlockTime>`_

    **Signature differences from C++ API:**

    * Parameter ``pbAchieved`` is no longer a paramer, and is instead an additional return value
    * Parameter ``punUnlockTime`` is no longer a paramer, and is instead an additional return value

.. function:: UserStats.GetUserStatFloat(steamIDUser, pchName)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param str pchName:
    :returns: (bool) Return value
    :returns: (float) Value for `pData`
    :SteamWorks: `GetUserStatFloat <https://partner.steamgames.com/doc/api/ISteamUserStats#GetUserStatFloat>`_

    **Signature differences from C++ API:**

    * Parameter ``pData`` is no longer a paramer, and is instead an additional return value

.. function:: UserStats.GetUserStatInt32(steamIDUser, pchName)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param str pchName:
    :returns: (bool) Return value
    :returns: (int) Value for `pData`
    :SteamWorks: `GetUserStatInt32 <https://partner.steamgames.com/doc/api/ISteamUserStats#GetUserStatInt32>`_

    **Signature differences from C++ API:**

    * Parameter ``pData`` is no longer a paramer, and is instead an additional return value

.. function:: UserStats.IndicateAchievementProgress(pchName, nCurProgress, nMaxProgress)

    🤖 **Auto-generated binding**

    :param str pchName:
    :param int nCurProgress:
    :param int nMaxProgress:
    :returns: (bool) Return value
    :SteamWorks: `IndicateAchievementProgress <https://partner.steamgames.com/doc/api/ISteamUserStats#IndicateAchievementProgress>`_

.. function:: UserStats.RequestGlobalAchievementPercentages(callback)

    🤖 **Auto-generated binding**

    :param function callback: CallResult callback receiving struct `GlobalAchievementPercentagesReady_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `RequestGlobalAchievementPercentages <https://partner.steamgames.com/doc/api/ISteamUserStats#RequestGlobalAchievementPercentages>`_

.. function:: UserStats.RequestGlobalStats(nHistoryDays, callback)

    🤖 **Auto-generated binding**

    :param int nHistoryDays:
    :param function callback: CallResult callback receiving struct `GlobalStatsReceived_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `RequestGlobalStats <https://partner.steamgames.com/doc/api/ISteamUserStats#RequestGlobalStats>`_

.. function:: UserStats.RequestUserStats(steamIDUser, callback)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param function callback: CallResult callback receiving struct `UserStatsReceived_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `RequestUserStats <https://partner.steamgames.com/doc/api/ISteamUserStats#RequestUserStats>`_

.. function:: UserStats.ResetAllStats(bAchievementsToo)

    🤖 **Auto-generated binding**

    :param bool bAchievementsToo:
    :returns: (bool) Return value
    :SteamWorks: `ResetAllStats <https://partner.steamgames.com/doc/api/ISteamUserStats#ResetAllStats>`_

.. function:: UserStats.SetAchievement(pchName)

    🤖 **Auto-generated binding**

    :param str pchName:
    :returns: (bool) Return value
    :SteamWorks: `SetAchievement <https://partner.steamgames.com/doc/api/ISteamUserStats#SetAchievement>`_

.. function:: UserStats.SetStatFloat(pchName, fData)

    🤖 **Auto-generated binding**

    :param str pchName:
    :param float fData:
    :returns: (bool) Return value
    :SteamWorks: `SetStatFloat <https://partner.steamgames.com/doc/api/ISteamUserStats#SetStatFloat>`_

.. function:: UserStats.SetStatInt32(pchName, nData)

    🤖 **Auto-generated binding**

    :param str pchName:
    :param int nData:
    :returns: (bool) Return value
    :SteamWorks: `SetStatInt32 <https://partner.steamgames.com/doc/api/ISteamUserStats#SetStatInt32>`_

.. function:: UserStats.StoreStats()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `StoreStats <https://partner.steamgames.com/doc/api/ISteamUserStats#StoreStats>`_

.. function:: UserStats.UpdateAvgRateStat(pchName, flCountThisSession, dSessionLength)

    🤖 **Auto-generated binding**

    :param str pchName:
    :param float flCountThisSession:
    :param float dSessionLength:
    :returns: (bool) Return value
    :SteamWorks: `UpdateAvgRateStat <https://partner.steamgames.com/doc/api/ISteamUserStats#UpdateAvgRateStat>`_

.. function:: UserStats.UploadLeaderboardScore(hSteamLeaderboard, eLeaderboardUploadScoreMethod, nScore, pScoreDetails, cScoreDetailsCount, callback)

    🤖 **Auto-generated binding**

    :param uint64 hSteamLeaderboard:
    :param int eLeaderboardUploadScoreMethod:
    :param int nScore:
    :param int[] pScoreDetails:
    :param int cScoreDetailsCount:
    :param function callback: CallResult callback receiving struct `LeaderboardScoreUploaded_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `UploadLeaderboardScore <https://partner.steamgames.com/doc/api/ISteamUserStats#UploadLeaderboardScore>`_


Callbacks
---------

.. function:: UserStats.onUserStatsReceived

    Callback for `UserStatsReceived_t <https://partner.steamgames.com/doc/api/ISteamUserStats#UserStatsReceived_t>`_

    **callback(data)** receives:

    * **data.m_nGameID** -- m_nGameID
    * **data.m_eResult** -- m_eResult
    * **data.m_steamIDUser** -- m_steamIDUser

.. function:: UserStats.onUserStatsStored

    Callback for `UserStatsStored_t <https://partner.steamgames.com/doc/api/ISteamUserStats#UserStatsStored_t>`_

    **callback(data)** receives:

    * **data.m_nGameID** -- m_nGameID
    * **data.m_eResult** -- m_eResult

.. function:: UserStats.onUserAchievementStored

    Callback for `UserAchievementStored_t <https://partner.steamgames.com/doc/api/ISteamUserStats#UserAchievementStored_t>`_

    **callback(data)** receives:

    * **data.m_nGameID** -- m_nGameID
    * **data.m_bGroupAchievement** -- m_bGroupAchievement
    * **data.m_rgchAchievementName** -- m_rgchAchievementName
    * **data.m_nCurProgress** -- m_nCurProgress
    * **data.m_nMaxProgress** -- m_nMaxProgress

.. function:: UserStats.onLeaderboardFindResult

    Callback for `LeaderboardFindResult_t <https://partner.steamgames.com/doc/api/ISteamUserStats#LeaderboardFindResult_t>`_

    **callback(data)** receives:

    * **data.m_hSteamLeaderboard** -- m_hSteamLeaderboard
    * **data.m_bLeaderboardFound** -- m_bLeaderboardFound

.. function:: UserStats.onLeaderboardScoresDownloaded

    Callback for `LeaderboardScoresDownloaded_t <https://partner.steamgames.com/doc/api/ISteamUserStats#LeaderboardScoresDownloaded_t>`_

    **callback(data)** receives:

    * **data.m_hSteamLeaderboard** -- m_hSteamLeaderboard
    * **data.m_hSteamLeaderboardEntries** -- m_hSteamLeaderboardEntries
    * **data.m_cEntryCount** -- m_cEntryCount

.. function:: UserStats.onLeaderboardScoreUploaded

    Callback for `LeaderboardScoreUploaded_t <https://partner.steamgames.com/doc/api/ISteamUserStats#LeaderboardScoreUploaded_t>`_

    **callback(data)** receives:

    * **data.m_bSuccess** -- m_bSuccess
    * **data.m_hSteamLeaderboard** -- m_hSteamLeaderboard
    * **data.m_nScore** -- m_nScore
    * **data.m_bScoreChanged** -- m_bScoreChanged
    * **data.m_nGlobalRankNew** -- m_nGlobalRankNew
    * **data.m_nGlobalRankPrevious** -- m_nGlobalRankPrevious

.. function:: UserStats.onNumberOfCurrentPlayers

    Callback for `NumberOfCurrentPlayers_t <https://partner.steamgames.com/doc/api/ISteamUserStats#NumberOfCurrentPlayers_t>`_

    **callback(data)** receives:

    * **data.m_bSuccess** -- m_bSuccess
    * **data.m_cPlayers** -- m_cPlayers

.. function:: UserStats.onUserStatsUnloaded

    Callback for `UserStatsUnloaded_t <https://partner.steamgames.com/doc/api/ISteamUserStats#UserStatsUnloaded_t>`_

    **callback(data)** receives:

    * **data.m_steamIDUser** -- m_steamIDUser

.. function:: UserStats.onUserAchievementIconFetched

    Callback for `UserAchievementIconFetched_t <https://partner.steamgames.com/doc/api/ISteamUserStats#UserAchievementIconFetched_t>`_

    **callback(data)** receives:

    * **data.m_nGameID** -- m_nGameID
    * **data.m_rgchAchievementName** -- m_rgchAchievementName
    * **data.m_bAchieved** -- m_bAchieved
    * **data.m_nIconHandle** -- m_nIconHandle

.. function:: UserStats.onGlobalAchievementPercentagesReady

    Callback for `GlobalAchievementPercentagesReady_t <https://partner.steamgames.com/doc/api/ISteamUserStats#GlobalAchievementPercentagesReady_t>`_

    **callback(data)** receives:

    * **data.m_nGameID** -- m_nGameID
    * **data.m_eResult** -- m_eResult

.. function:: UserStats.onLeaderboardUGCSet

    Callback for `LeaderboardUGCSet_t <https://partner.steamgames.com/doc/api/ISteamUserStats#LeaderboardUGCSet_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_hSteamLeaderboard** -- m_hSteamLeaderboard

.. function:: UserStats.onGlobalStatsReceived

    Callback for `GlobalStatsReceived_t <https://partner.steamgames.com/doc/api/ISteamUserStats#GlobalStatsReceived_t>`_

    **callback(data)** receives:

    * **data.m_nGameID** -- m_nGameID
    * **data.m_eResult** -- m_eResult

.. function:: UserStats.onGSStatsUnloaded

    Callback for `GSStatsUnloaded_t <https://partner.steamgames.com/doc/api/ISteamUserStats#GSStatsUnloaded_t>`_

    **callback(data)** receives:

    * **data.m_steamIDUser** -- m_steamIDUser

