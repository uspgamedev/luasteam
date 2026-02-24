---@class Steam.NetworkingUtils
local NetworkingUtils = {}

function NetworkingUtils.InitRelayNetworkAccess() end

---@param location1 SteamNetworkPingLocation_t
---@param location2 SteamNetworkPingLocation_t
---@return integer
function NetworkingUtils.EstimatePingTimeBetweenTwoLocations(location1, location2) end

---@param remoteLocation SteamNetworkPingLocation_t
---@return integer
function NetworkingUtils.EstimatePingTimeFromLocalHost(remoteLocation) end

---@param location SteamNetworkPingLocation_t
---@param cchBufSize integer
---@return string -- Value of: pszBuf
function NetworkingUtils.ConvertPingLocationToString(location, cchBufSize) end

---@param flMaxAgeSeconds number
---@return boolean
function NetworkingUtils.CheckPingDataUpToDate(flMaxAgeSeconds) end

---@param popID integer
---@return integer
---@return integer -- Value of: pViaRelayPoP
function NetworkingUtils.GetPingToDataCenter(popID) end

---@param popID integer
---@return integer
function NetworkingUtils.GetDirectPingToPOP(popID) end

---@return integer
function NetworkingUtils.GetPOPCount() end

---@param nListSz integer
---@return integer
---@return integer -- Value of: list
function NetworkingUtils.GetPOPList(nListSz) end

---@param nIPv4 integer
---@return boolean
function NetworkingUtils.IsFakeIPv4(nIPv4) end

---@param nIPv4 integer
---@return integer
function NetworkingUtils.GetIPv4FakeIPType(nIPv4) end

---@param fakeIP SteamNetworkingIPAddr
---@return integer
---@return SteamNetworkingIdentity -- Value of: pOutRealIdentity
function NetworkingUtils.GetRealIdentityForFakeIP(fakeIP) end

---@param eValue integer
---@param val integer
---@return boolean
function NetworkingUtils.SetGlobalConfigValueInt32(eValue, val) end

---@param eValue integer
---@param val number
---@return boolean
function NetworkingUtils.SetGlobalConfigValueFloat(eValue, val) end

---@param eValue integer
---@param val string
---@return boolean
function NetworkingUtils.SetGlobalConfigValueString(eValue, val) end

---@param hConn integer
---@param eValue integer
---@param val integer
---@return boolean
function NetworkingUtils.SetConnectionConfigValueInt32(hConn, eValue, val) end

---@param hConn integer
---@param eValue integer
---@param val number
---@return boolean
function NetworkingUtils.SetConnectionConfigValueFloat(hConn, eValue, val) end

---@param hConn integer
---@param eValue integer
---@param val string
---@return boolean
function NetworkingUtils.SetConnectionConfigValueString(hConn, eValue, val) end

---@param eValue integer
---@return string
---@return integer -- Value of: pOutDataType
---@return integer -- Value of: pOutScope
function NetworkingUtils.GetConfigValueInfo(eValue) end

---@param eCurrent integer
---@param bEnumerateDevVars boolean
---@return integer
function NetworkingUtils.IterateGenericEditableConfigValues(eCurrent, bEnumerateDevVars) end

---@param addr SteamNetworkingIPAddr
---@param cbBuf integer
---@param bWithPort boolean
---@return string -- Value of: buf
function NetworkingUtils.SteamNetworkingIPAddr_ToString(addr, cbBuf, bWithPort) end

---@param pszStr string
---@return boolean
---@return SteamNetworkingIPAddr -- Value of: pAddr
function NetworkingUtils.SteamNetworkingIPAddr_ParseString(pszStr) end

---@param addr SteamNetworkingIPAddr
---@return integer
function NetworkingUtils.SteamNetworkingIPAddr_GetFakeIPType(addr) end

---@param identity SteamNetworkingIdentity
---@param cbBuf integer
---@return string -- Value of: buf
function NetworkingUtils.SteamNetworkingIdentity_ToString(identity, cbBuf) end

---@param pszStr string
---@return boolean
---@return SteamNetworkingIdentity -- Value of: pIdentity
function NetworkingUtils.SteamNetworkingIdentity_ParseString(pszStr) end

Steam.NetworkingUtils = NetworkingUtils
