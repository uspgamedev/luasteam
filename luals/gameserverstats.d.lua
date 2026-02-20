---@class Steam.GameServerStats
local GameServerStats = {}

---@param steamIDUser uint64
---@param callback fun(data: GSStatsReceived_t?, io_fail: boolean)?
---@return uint64
function GameServerStats.RequestUserStats(steamIDUser, callback) end

---@param steamIDUser uint64
---@param pchName string
---@return boolean
---@return integer -- Value of: pData
function GameServerStats.GetUserStatInt32(steamIDUser, pchName) end

---@param steamIDUser uint64
---@param pchName string
---@return boolean
---@return number -- Value of: pData
function GameServerStats.GetUserStatFloat(steamIDUser, pchName) end

---@param steamIDUser uint64
---@param pchName string
---@return boolean
---@return boolean -- Value of: pbAchieved
function GameServerStats.GetUserAchievement(steamIDUser, pchName) end

---@param steamIDUser uint64
---@param pchName string
---@param nData integer
---@return boolean
function GameServerStats.SetUserStatInt32(steamIDUser, pchName, nData) end

---@param steamIDUser uint64
---@param pchName string
---@param fData number
---@return boolean
function GameServerStats.SetUserStatFloat(steamIDUser, pchName, fData) end

---@param steamIDUser uint64
---@param pchName string
---@param flCountThisSession number
---@param dSessionLength number
---@return boolean
function GameServerStats.UpdateUserAvgRateStat(steamIDUser, pchName, flCountThisSession, dSessionLength) end

---@param steamIDUser uint64
---@param pchName string
---@return boolean
function GameServerStats.SetUserAchievement(steamIDUser, pchName) end

---@param steamIDUser uint64
---@param pchName string
---@return boolean
function GameServerStats.ClearUserAchievement(steamIDUser, pchName) end

---@param steamIDUser uint64
---@param callback fun(data: GSStatsStored_t?, io_fail: boolean)?
---@return uint64
function GameServerStats.StoreUserStats(steamIDUser, callback) end

Steam.GameServerStats = GameServerStats
