---@class Steam.UserStats
local UserStats = {}

---@param pchName string
---@return boolean
---@return integer -- Value of: pData
function UserStats.GetStatInt32(pchName) end

---@param pchName string
---@return boolean
---@return number -- Value of: pData
function UserStats.GetStatFloat(pchName) end

---@param pchName string
---@param nData integer
---@return boolean
function UserStats.SetStatInt32(pchName, nData) end

---@param pchName string
---@param fData number
---@return boolean
function UserStats.SetStatFloat(pchName, fData) end

---@param pchName string
---@param flCountThisSession number
---@param dSessionLength number
---@return boolean
function UserStats.UpdateAvgRateStat(pchName, flCountThisSession, dSessionLength) end

---@param pchName string
---@return boolean
---@return boolean -- Value of: pbAchieved
function UserStats.GetAchievement(pchName) end

---@param pchName string
---@return boolean
function UserStats.SetAchievement(pchName) end

---@param pchName string
---@return boolean
function UserStats.ClearAchievement(pchName) end

---@param pchName string
---@return boolean
---@return boolean -- Value of: pbAchieved
---@return integer -- Value of: punUnlockTime
function UserStats.GetAchievementAndUnlockTime(pchName) end

---@return boolean
function UserStats.StoreStats() end

---@param pchName string
---@return integer
function UserStats.GetAchievementIcon(pchName) end

---@param pchName string
---@param pchKey string
---@return string
function UserStats.GetAchievementDisplayAttribute(pchName, pchKey) end

---@param pchName string
---@param nCurProgress integer
---@param nMaxProgress integer
---@return boolean
function UserStats.IndicateAchievementProgress(pchName, nCurProgress, nMaxProgress) end

---@return integer
function UserStats.GetNumAchievements() end

---@param iAchievement integer
---@return string
function UserStats.GetAchievementName(iAchievement) end

---@param steamIDUser uint64
---@param callback fun(data: UserStatsReceived_t?, io_fail: boolean)?
---@return uint64
function UserStats.RequestUserStats(steamIDUser, callback) end

---@param steamIDUser uint64
---@param pchName string
---@return boolean
---@return integer -- Value of: pData
function UserStats.GetUserStatInt32(steamIDUser, pchName) end

---@param steamIDUser uint64
---@param pchName string
---@return boolean
---@return number -- Value of: pData
function UserStats.GetUserStatFloat(steamIDUser, pchName) end

---@param steamIDUser uint64
---@param pchName string
---@return boolean
---@return boolean -- Value of: pbAchieved
function UserStats.GetUserAchievement(steamIDUser, pchName) end

---@param steamIDUser uint64
---@param pchName string
---@return boolean
---@return boolean -- Value of: pbAchieved
---@return integer -- Value of: punUnlockTime
function UserStats.GetUserAchievementAndUnlockTime(steamIDUser, pchName) end

---@param bAchievementsToo boolean
---@return boolean
function UserStats.ResetAllStats(bAchievementsToo) end

---@param pchLeaderboardName string
---@param eLeaderboardSortMethod integer
---@param eLeaderboardDisplayType integer
---@param callback fun(data: LeaderboardFindResult_t?, io_fail: boolean)?
---@return uint64
function UserStats.FindOrCreateLeaderboard(pchLeaderboardName, eLeaderboardSortMethod, eLeaderboardDisplayType, callback) end

---@param pchLeaderboardName string
---@param callback fun(data: LeaderboardFindResult_t?, io_fail: boolean)?
---@return uint64
function UserStats.FindLeaderboard(pchLeaderboardName, callback) end

---@param hSteamLeaderboard uint64
---@return string
function UserStats.GetLeaderboardName(hSteamLeaderboard) end

---@param hSteamLeaderboard uint64
---@return integer
function UserStats.GetLeaderboardEntryCount(hSteamLeaderboard) end

---@param hSteamLeaderboard uint64
---@return integer
function UserStats.GetLeaderboardSortMethod(hSteamLeaderboard) end

---@param hSteamLeaderboard uint64
---@return integer
function UserStats.GetLeaderboardDisplayType(hSteamLeaderboard) end

---@param hSteamLeaderboard uint64
---@param eLeaderboardDataRequest integer
---@param nRangeStart integer
---@param nRangeEnd integer
---@param callback fun(data: LeaderboardScoresDownloaded_t?, io_fail: boolean)?
---@return uint64
function UserStats.DownloadLeaderboardEntries(hSteamLeaderboard, eLeaderboardDataRequest, nRangeStart, nRangeEnd, callback) end

---@param hSteamLeaderboard uint64
---@param cUsers integer
---@param prgUsers uint64[]
---@param callback fun(data: LeaderboardScoresDownloaded_t?, io_fail: boolean)?
---@return uint64
function UserStats.DownloadLeaderboardEntriesForUsers(hSteamLeaderboard, cUsers, prgUsers, callback) end

---@param hSteamLeaderboardEntries uint64
---@param index integer
---@param cDetailsMax integer
---@return boolean
---@return table -- Value of: pLeaderboardEntry
---@return integer[] -- Value of: pDetails
function UserStats.GetDownloadedLeaderboardEntry(hSteamLeaderboardEntries, index, cDetailsMax) end

---@param hSteamLeaderboard uint64
---@param eLeaderboardUploadScoreMethod integer
---@param nScore integer
---@param cScoreDetailsCount integer
---@param pScoreDetails integer[]
---@param callback fun(data: LeaderboardScoreUploaded_t?, io_fail: boolean)?
---@return uint64
function UserStats.UploadLeaderboardScore(hSteamLeaderboard, eLeaderboardUploadScoreMethod, nScore, cScoreDetailsCount, pScoreDetails, callback) end

---@param hSteamLeaderboard uint64
---@param hUGC uint64
---@param callback fun(data: LeaderboardUGCSet_t?, io_fail: boolean)?
---@return uint64
function UserStats.AttachLeaderboardUGC(hSteamLeaderboard, hUGC, callback) end

---@param callback fun(data: NumberOfCurrentPlayers_t?, io_fail: boolean)?
---@return uint64
function UserStats.GetNumberOfCurrentPlayers(callback) end

---@param callback fun(data: GlobalAchievementPercentagesReady_t?, io_fail: boolean)?
---@return uint64
function UserStats.RequestGlobalAchievementPercentages(callback) end

---@param unNameBufLen integer
---@return integer
---@return string -- Value of: pchName
---@return number -- Value of: pflPercent
---@return boolean -- Value of: pbAchieved
function UserStats.GetMostAchievedAchievementInfo(unNameBufLen) end

---@param iIteratorPrevious integer
---@param unNameBufLen integer
---@return integer
---@return string -- Value of: pchName
---@return number -- Value of: pflPercent
---@return boolean -- Value of: pbAchieved
function UserStats.GetNextMostAchievedAchievementInfo(iIteratorPrevious, unNameBufLen) end

---@param pchName string
---@return boolean
---@return number -- Value of: pflPercent
function UserStats.GetAchievementAchievedPercent(pchName) end

---@param nHistoryDays integer
---@param callback fun(data: GlobalStatsReceived_t?, io_fail: boolean)?
---@return uint64
function UserStats.RequestGlobalStats(nHistoryDays, callback) end

---@param pchStatName string
---@return boolean
---@return uint64 -- Value of: pData
function UserStats.GetGlobalStatInt64(pchStatName) end

---@param pchStatName string
---@return boolean
---@return number -- Value of: pData
function UserStats.GetGlobalStatDouble(pchStatName) end

---@param pchStatName string
---@param cubData integer
---@return integer
---@return uint64[] -- Value of: pData
function UserStats.GetGlobalStatHistoryInt64(pchStatName, cubData) end

---@param pchStatName string
---@param cubData integer
---@return integer
---@return number[] -- Value of: pData
function UserStats.GetGlobalStatHistoryDouble(pchStatName, cubData) end

---@param pchName string
---@return boolean
---@return integer -- Value of: pnMinProgress
---@return integer -- Value of: pnMaxProgress
function UserStats.GetAchievementProgressLimitsInt32(pchName) end

---@param pchName string
---@return boolean
---@return number -- Value of: pfMinProgress
---@return number -- Value of: pfMaxProgress
function UserStats.GetAchievementProgressLimitsFloat(pchName) end

Steam.UserStats = UserStats
