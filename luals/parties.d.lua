---@class Steam.Parties
---@field OnJoinPartyCallback? fun(data: JoinPartyCallback_t)
---@field OnCreateBeaconCallback? fun(data: CreateBeaconCallback_t)
---@field OnReservationNotificationCallback? fun(data: ReservationNotificationCallback_t)
---@field OnChangeNumOpenSlotsCallback? fun(data: ChangeNumOpenSlotsCallback_t)
---@field OnAvailableBeaconLocationsUpdated? fun(data: AvailableBeaconLocationsUpdated_t)
---@field OnActiveBeaconsUpdated? fun(data: ActiveBeaconsUpdated_t)
local Parties = {}

---@return integer
function Parties.GetNumActiveBeacons() end

---@param unIndex integer
---@return uint64 -- PartyBeaconID_t
function Parties.GetBeaconByIndex(unIndex) end

---@param ulBeaconID uint64 -- PartyBeaconID_t
---@param cchMetadata integer? size of the buffer for pchMetadata; if nil then the buffer will be NULL
---@return boolean
---@return uint64 -- Value of: pSteamIDBeaconOwner
---@return SteamPartyBeaconLocation_t -- Value of: pLocation
---@return string -- Value of: pchMetadata
function Parties.GetBeaconDetails(ulBeaconID, cchMetadata) end

---@param ulBeaconID uint64 -- PartyBeaconID_t
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function Parties.JoinParty(ulBeaconID, callback) end

---@return boolean
---@return integer -- Value of: puNumLocations
function Parties.GetNumAvailableBeaconLocations() end

---@param uMaxNumLocations integer? size of the buffer for pLocationList; if nil then the buffer will be NULL
---@return boolean
---@return SteamPartyBeaconLocation_t[] -- Value of: pLocationList
function Parties.GetAvailableBeaconLocations(uMaxNumLocations) end

---@param unOpenSlots integer
---@param pBeaconLocation SteamPartyBeaconLocation_t
---@param pchConnectString string?
---@param pchMetadata string?
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function Parties.CreateBeacon(unOpenSlots, pBeaconLocation, pchConnectString, pchMetadata, callback) end

---@param ulBeacon uint64 -- PartyBeaconID_t
---@param steamIDUser uint64 -- CSteamID
function Parties.OnReservationCompleted(ulBeacon, steamIDUser) end

---@param ulBeacon uint64 -- PartyBeaconID_t
---@param steamIDUser uint64 -- CSteamID
function Parties.CancelReservation(ulBeacon, steamIDUser) end

---@param ulBeacon uint64 -- PartyBeaconID_t
---@param unOpenSlots integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function Parties.ChangeNumOpenSlots(ulBeacon, unOpenSlots, callback) end

---@param ulBeacon uint64 -- PartyBeaconID_t
---@return boolean
function Parties.DestroyBeacon(ulBeacon) end

---@param BeaconLocation SteamPartyBeaconLocation_t -- SteamPartyBeaconLocation_t
---@param eData integer -- ESteamPartyBeaconLocationData
---@param cchDataStringOut integer? size of the buffer for pchDataStringOut; if nil then the buffer will be NULL
---@return boolean
---@return string -- Value of: pchDataStringOut
function Parties.GetBeaconLocationData(BeaconLocation, eData, cchDataStringOut) end

Steam.Parties = Parties
