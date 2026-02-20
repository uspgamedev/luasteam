---@class Steam.Parties
local Parties = {}

---@return integer
function Parties.GetNumActiveBeacons() end

---@param unIndex integer
---@return table
function Parties.GetBeaconByIndex(unIndex) end

---@param ulBeaconID table
---@param pchMetadata string
---@param cchMetadata integer
---@return boolean
---@return uint64
---@return table
function Parties.GetBeaconDetails(ulBeaconID, pchMetadata, cchMetadata) end

---@param ulBeaconID table
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function Parties.JoinParty(ulBeaconID, callback) end

---@return boolean
---@return integer
function Parties.GetNumAvailableBeaconLocations() end

---@param uMaxNumLocations integer
---@return boolean
---@return table
function Parties.GetAvailableBeaconLocations(uMaxNumLocations) end

---@param ulBeacon table
---@param steamIDUser uint64
function Parties.OnReservationCompleted(ulBeacon, steamIDUser) end

---@param ulBeacon table
---@param steamIDUser uint64
function Parties.CancelReservation(ulBeacon, steamIDUser) end

---@param ulBeacon table
---@param unOpenSlots integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function Parties.ChangeNumOpenSlots(ulBeacon, unOpenSlots, callback) end

---@param ulBeacon table
---@return boolean
function Parties.DestroyBeacon(ulBeacon) end

Steam.Parties = Parties
