---@class Steam.ParentalSettings
---@field OnSteamParentalSettingsChanged? fun(data: SteamParentalSettingsChanged_t)
local ParentalSettings = {}

---@return boolean
function ParentalSettings.BIsParentalLockEnabled() end

---@return boolean
function ParentalSettings.BIsParentalLockLocked() end

---@param nAppID integer -- AppId_t
---@return boolean
function ParentalSettings.BIsAppBlocked(nAppID) end

---@param nAppID integer -- AppId_t
---@return boolean
function ParentalSettings.BIsAppInBlockList(nAppID) end

---@param eFeature integer -- EParentalFeature
---@return boolean
function ParentalSettings.BIsFeatureBlocked(eFeature) end

---@param eFeature integer -- EParentalFeature
---@return boolean
function ParentalSettings.BIsFeatureInBlockList(eFeature) end

Steam.ParentalSettings = ParentalSettings
