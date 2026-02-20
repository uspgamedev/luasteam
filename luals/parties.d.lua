---@class Steam.Parties
local Parties = {}

---@return integer
function Parties.GetNumActiveBeacons() end

---@param unIndex integer
---@return uint64
function Parties.GetBeaconByIndex(unIndex) end

---@param ulBeaconID uint64
---@param cchMetadata integer
---@return boolean
---@return uint64 -- Value of: pSteamIDBeaconOwner
---@return table -- Value of: pLocation
---@return string -- Value of: pchMetadata
function Parties.GetBeaconDetails(ulBeaconID, cchMetadata) end

---@param ulBeaconID uint64
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function Parties.JoinParty(ulBeaconID, callback) end

---@return boolean
---@return integer -- Value of: puNumLocations
function Parties.GetNumAvailableBeaconLocations() end

---@param uMaxNumLocations integer
---@return boolean
---@return table[] -- Value of: pLocationList
function Parties.GetAvailableBeaconLocations(uMaxNumLocations) end

---@param ulBeacon uint64
---@param steamIDUser uint64
function Parties.OnReservationCompleted(ulBeacon, steamIDUser) end

---@param ulBeacon uint64
---@param steamIDUser uint64
function Parties.CancelReservation(ulBeacon, steamIDUser) end

---@param ulBeacon uint64
---@param unOpenSlots integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function Parties.ChangeNumOpenSlots(ulBeacon, unOpenSlots, callback) end

---@param ulBeacon uint64
---@return boolean
function Parties.DestroyBeacon(ulBeacon) end

Steam.Parties = Parties
