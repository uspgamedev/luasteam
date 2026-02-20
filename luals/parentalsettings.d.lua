---@class Steam.ParentalSettings
local ParentalSettings = {}

---@return boolean
function ParentalSettings.BIsParentalLockEnabled() end

---@return boolean
function ParentalSettings.BIsParentalLockLocked() end

---@param nAppID integer
---@return boolean
function ParentalSettings.BIsAppBlocked(nAppID) end

---@param nAppID integer
---@return boolean
function ParentalSettings.BIsAppInBlockList(nAppID) end

---@param eFeature integer
---@return boolean
function ParentalSettings.BIsFeatureBlocked(eFeature) end

---@param eFeature integer
---@return boolean
function ParentalSettings.BIsFeatureInBlockList(eFeature) end

Steam.ParentalSettings = ParentalSettings
