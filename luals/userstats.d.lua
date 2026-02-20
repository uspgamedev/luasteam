---@class Steam.UserStats
local UserStats = {}

---@param pchName string
---@return boolean
---@return integer
function UserStats.GetStatInt32(pchName) end

---@param pchName string
---@return boolean
---@return number
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
---@return boolean
function UserStats.GetAchievement(pchName) end

---@param pchName string
---@return boolean
function UserStats.SetAchievement(pchName) end

---@param pchName string
---@return boolean
function UserStats.ClearAchievement(pchName) end

---@param pchName string
---@return boolean
---@return boolean
---@return integer
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
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function UserStats.RequestUserStats(steamIDUser, callback) end

---@param steamIDUser uint64
---@param pchName string
---@return boolean
---@return integer
function UserStats.GetUserStatInt32(steamIDUser, pchName) end

---@param steamIDUser uint64
---@param pchName string
---@return boolean
---@return number
function UserStats.GetUserStatFloat(steamIDUser, pchName) end

---@param steamIDUser uint64
---@param pchName string
---@return boolean
---@return boolean
function UserStats.GetUserAchievement(steamIDUser, pchName) end

---@param steamIDUser uint64
---@param pchName string
---@return boolean
---@return boolean
---@return integer
function UserStats.GetUserAchievementAndUnlockTime(steamIDUser, pchName) end

---@param bAchievementsToo boolean
---@return boolean
function UserStats.ResetAllStats(bAchievementsToo) end

---@param pchLeaderboardName string
---@param eLeaderboardSortMethod integer
---@param eLeaderboardDisplayType integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function UserStats.FindOrCreateLeaderboard(pchLeaderboardName, eLeaderboardSortMethod, eLeaderboardDisplayType, callback) end

---@param pchLeaderboardName string
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function UserStats.FindLeaderboard(pchLeaderboardName, callback) end

---@param hSteamLeaderboard table
---@return string
function UserStats.GetLeaderboardName(hSteamLeaderboard) end

---@param hSteamLeaderboard table
---@return integer
function UserStats.GetLeaderboardEntryCount(hSteamLeaderboard) end

---@param hSteamLeaderboard table
---@return integer
function UserStats.GetLeaderboardSortMethod(hSteamLeaderboard) end

---@param hSteamLeaderboard table
---@return integer
function UserStats.GetLeaderboardDisplayType(hSteamLeaderboard) end

---@param hSteamLeaderboard table
---@param eLeaderboardDataRequest integer
---@param nRangeStart integer
---@param nRangeEnd integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function UserStats.DownloadLeaderboardEntries(hSteamLeaderboard, eLeaderboardDataRequest, nRangeStart, nRangeEnd, callback) end

---@param hSteamLeaderboard table
---@param prgUsers table
---@param cUsers integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function UserStats.DownloadLeaderboardEntriesForUsers(hSteamLeaderboard, prgUsers, cUsers, callback) end

---@param hSteamLeaderboardEntries table
---@param index integer
---@param cDetailsMax integer
---@return boolean
---@return table
---@return integer
function UserStats.GetDownloadedLeaderboardEntry(hSteamLeaderboardEntries, index, cDetailsMax) end

---@param hSteamLeaderboard table
---@param eLeaderboardUploadScoreMethod integer
---@param nScore integer
---@param pScoreDetails table
---@param cScoreDetailsCount integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function UserStats.UploadLeaderboardScore(hSteamLeaderboard, eLeaderboardUploadScoreMethod, nScore, pScoreDetails, cScoreDetailsCount, callback) end

---@param hSteamLeaderboard table
---@param hUGC table
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function UserStats.AttachLeaderboardUGC(hSteamLeaderboard, hUGC, callback) end

---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function UserStats.GetNumberOfCurrentPlayers(callback) end

---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function UserStats.RequestGlobalAchievementPercentages(callback) end

---@param pchName string
---@param unNameBufLen integer
---@return integer
---@return number
---@return boolean
function UserStats.GetMostAchievedAchievementInfo(pchName, unNameBufLen) end

---@param iIteratorPrevious integer
---@param pchName string
---@param unNameBufLen integer
---@return integer
---@return number
---@return boolean
function UserStats.GetNextMostAchievedAchievementInfo(iIteratorPrevious, pchName, unNameBufLen) end

---@param pchName string
---@return boolean
---@return number
function UserStats.GetAchievementAchievedPercent(pchName) end

---@param nHistoryDays integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function UserStats.RequestGlobalStats(nHistoryDays, callback) end

---@param pchStatName string
---@return boolean
---@return table
function UserStats.GetGlobalStatInt64(pchStatName) end

---@param pchStatName string
---@return boolean
---@return number
function UserStats.GetGlobalStatDouble(pchStatName) end

---@param pchStatName string
---@param pData table
---@param cubData integer
---@return integer
function UserStats.GetGlobalStatHistoryInt64(pchStatName, pData, cubData) end

---@param pchStatName string
---@param pData table
---@param cubData integer
---@return integer
function UserStats.GetGlobalStatHistoryDouble(pchStatName, pData, cubData) end

---@param pchName string
---@return boolean
---@return integer
---@return integer
function UserStats.GetAchievementProgressLimitsInt32(pchName) end

---@param pchName string
---@return boolean
---@return number
---@return number
function UserStats.GetAchievementProgressLimitsFloat(pchName) end

Steam.UserStats = UserStats
