---@class Steam.GameServerStats
---@field OnGSStatsReceived? fun(data: GSStatsReceived_t)
---@field OnGSStatsStored? fun(data: GSStatsStored_t)
local GameServerStats = {}

---@param steamIDUser uint64 -- CSteamID
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function GameServerStats.RequestUserStats(steamIDUser, callback) end

---@param steamIDUser uint64 -- CSteamID
---@param pchName string?
---@return boolean
---@return integer -- Value of: pData
function GameServerStats.GetUserStatInt32(steamIDUser, pchName) end

---@param steamIDUser uint64 -- CSteamID
---@param pchName string?
---@return boolean
---@return number -- Value of: pData
function GameServerStats.GetUserStatFloat(steamIDUser, pchName) end

---@param steamIDUser uint64 -- CSteamID
---@param pchName string?
---@return boolean
---@return boolean -- Value of: pbAchieved
function GameServerStats.GetUserAchievement(steamIDUser, pchName) end

---@param steamIDUser uint64 -- CSteamID
---@param pchName string?
---@param nData integer
---@return boolean
function GameServerStats.SetUserStatInt32(steamIDUser, pchName, nData) end

---@param steamIDUser uint64 -- CSteamID
---@param pchName string?
---@param fData number
---@return boolean
function GameServerStats.SetUserStatFloat(steamIDUser, pchName, fData) end

---@param steamIDUser uint64 -- CSteamID
---@param pchName string?
---@param flCountThisSession number
---@param dSessionLength number
---@return boolean
function GameServerStats.UpdateUserAvgRateStat(steamIDUser, pchName, flCountThisSession, dSessionLength) end

---@param steamIDUser uint64 -- CSteamID
---@param pchName string?
---@return boolean
function GameServerStats.SetUserAchievement(steamIDUser, pchName) end

---@param steamIDUser uint64 -- CSteamID
---@param pchName string?
---@return boolean
function GameServerStats.ClearUserAchievement(steamIDUser, pchName) end

---@param steamIDUser uint64 -- CSteamID
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function GameServerStats.StoreUserStats(steamIDUser, callback) end

Steam.GameServerStats = GameServerStats
