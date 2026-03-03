---@class Steam.NetworkingSockets
---@field OnSteamNetConnectionStatusChangedCallback? fun(data: SteamNetConnectionStatusChangedCallback_t)
---@field OnSteamNetAuthenticationStatus? fun(data: SteamNetAuthenticationStatus_t)
---@field OnSteamNetworkingFakeIPResult? fun(data: SteamNetworkingFakeIPResult_t)
local NetworkingSockets = {}

---@param localAddress SteamNetworkingIPAddr
---@param nOptions integer
---@param pOptions SteamNetworkingConfigValue_t
---@return integer -- HSteamListenSocket
function NetworkingSockets.CreateListenSocketIP(localAddress, nOptions, pOptions) end

---@param address SteamNetworkingIPAddr
---@param nOptions integer
---@param pOptions SteamNetworkingConfigValue_t
---@return integer -- HSteamNetConnection
function NetworkingSockets.ConnectByIPAddress(address, nOptions, pOptions) end

---@param nLocalVirtualPort integer
---@param nOptions integer
---@param pOptions SteamNetworkingConfigValue_t
---@return integer -- HSteamListenSocket
function NetworkingSockets.CreateListenSocketP2P(nLocalVirtualPort, nOptions, pOptions) end

---@param identityRemote SteamNetworkingIdentity
---@param nRemoteVirtualPort integer
---@param nOptions integer
---@param pOptions SteamNetworkingConfigValue_t
---@return integer -- HSteamNetConnection
function NetworkingSockets.ConnectP2P(identityRemote, nRemoteVirtualPort, nOptions, pOptions) end

---@param hConn integer -- HSteamNetConnection
---@return integer -- EResult
function NetworkingSockets.AcceptConnection(hConn) end

---@param hPeer integer -- HSteamNetConnection
---@param nReason integer
---@param pszDebug string?
---@param bEnableLinger boolean
---@return boolean
function NetworkingSockets.CloseConnection(hPeer, nReason, pszDebug, bEnableLinger) end

---@param hSocket integer -- HSteamListenSocket
---@return boolean
function NetworkingSockets.CloseListenSocket(hSocket) end

---@param hPeer integer -- HSteamNetConnection
---@param nUserData uint64
---@return boolean
function NetworkingSockets.SetConnectionUserData(hPeer, nUserData) end

---@param hPeer integer -- HSteamNetConnection
---@return uint64
function NetworkingSockets.GetConnectionUserData(hPeer) end

---@param hPeer integer -- HSteamNetConnection
---@param pszName string?
function NetworkingSockets.SetConnectionName(hPeer, pszName) end

---@param hPeer integer -- HSteamNetConnection
---@param nMaxLen integer? size of the buffer for pszName; if nil then the buffer will be NULL
---@return boolean
---@return string -- Value of: pszName
function NetworkingSockets.GetConnectionName(hPeer, nMaxLen) end

---@param hConn integer -- HSteamNetConnection
---@param pData string?
---@param cbData integer size of the input array pData
---@param nSendFlags integer
---@return integer -- EResult
---@return uint64 -- Value of: pOutMessageNumber
function NetworkingSockets.SendMessageToConnection(hConn, pData, cbData, nSendFlags) end

---@param hConn integer -- HSteamNetConnection
---@return integer -- EResult
function NetworkingSockets.FlushMessagesOnConnection(hConn) end

---@param hConn integer -- HSteamNetConnection
---@return boolean
---@return SteamNetConnectionInfo_t -- Value of: pInfo
function NetworkingSockets.GetConnectionInfo(hConn) end

---@param hConn integer -- HSteamNetConnection
---@param nLanes integer
---@return integer -- EResult
---@return SteamNetConnectionRealTimeStatus_t -- Value of: pStatus
---@return SteamNetConnectionRealTimeLaneStatus_t -- Value of: pLanes
function NetworkingSockets.GetConnectionRealTimeStatus(hConn, nLanes) end

---@param hConn integer -- HSteamNetConnection
---@param cbBuf integer? size of the buffer for pszBuf; if nil then the buffer will be NULL
---@return integer
---@return string -- Value of: pszBuf
function NetworkingSockets.GetDetailedConnectionStatus(hConn, cbBuf) end

---@param hSocket integer -- HSteamListenSocket
---@return boolean
---@return SteamNetworkingIPAddr -- Value of: address
function NetworkingSockets.GetListenSocketAddress(hSocket) end

---@param bUseNetworkLoopback boolean
---@param pIdentity1 SteamNetworkingIdentity
---@param pIdentity2 SteamNetworkingIdentity
---@return boolean
---@return integer -- Value of: pOutConnection1
---@return integer -- Value of: pOutConnection2
function NetworkingSockets.CreateSocketPair(bUseNetworkLoopback, pIdentity1, pIdentity2) end

---@param hConn integer -- HSteamNetConnection
---@param nNumLanes integer size of the input arrays pLanePriorities and pLaneWeights
---@param pLanePriorities integer[]?
---@param pLaneWeights integer[]?
---@return integer -- EResult
function NetworkingSockets.ConfigureConnectionLanes(hConn, nNumLanes, pLanePriorities, pLaneWeights) end

---@return boolean
---@return SteamNetworkingIdentity -- Value of: pIdentity
function NetworkingSockets.GetIdentity() end

---@return integer -- ESteamNetworkingAvailability
function NetworkingSockets.InitAuthentication() end

---@return integer -- ESteamNetworkingAvailability
---@return SteamNetAuthenticationStatus_t -- Value of: pDetails
function NetworkingSockets.GetAuthenticationStatus() end

---@return integer -- HSteamNetPollGroup
function NetworkingSockets.CreatePollGroup() end

---@param hPollGroup integer -- HSteamNetPollGroup
---@return boolean
function NetworkingSockets.DestroyPollGroup(hPollGroup) end

---@param hConn integer -- HSteamNetConnection
---@param hPollGroup integer -- HSteamNetPollGroup
---@return boolean
function NetworkingSockets.SetConnectionPollGroup(hConn, hPollGroup) end

---@param identityTarget SteamNetworkingIdentity
---@param nRemoteVirtualPort integer
---@param nOptions integer
---@param pOptions SteamNetworkingConfigValue_t
---@return integer -- HSteamNetConnection
function NetworkingSockets.ConnectToHostedDedicatedServer(identityTarget, nRemoteVirtualPort, nOptions, pOptions) end

---@return integer
function NetworkingSockets.GetHostedDedicatedServerPort() end

---@return integer -- SteamNetworkingPOPID
function NetworkingSockets.GetHostedDedicatedServerPOPID() end

---@param nLocalVirtualPort integer
---@param nOptions integer
---@param pOptions SteamNetworkingConfigValue_t
---@return integer -- HSteamListenSocket
function NetworkingSockets.CreateHostedDedicatedServerListenSocket(nLocalVirtualPort, nOptions, pOptions) end

---@param pIdentity SteamNetworkingIdentity
function NetworkingSockets.ResetIdentity(pIdentity) end

function NetworkingSockets.RunCallbacks() end

---@param nNumPorts integer
---@return boolean
function NetworkingSockets.BeginAsyncRequestFakeIP(nNumPorts) end

---@param idxFirstPort integer
---@return SteamNetworkingFakeIPResult_t -- Value of: pInfo
function NetworkingSockets.GetFakeIP(idxFirstPort) end

---@param idxFakePort integer
---@param nOptions integer
---@param pOptions SteamNetworkingConfigValue_t
---@return integer -- HSteamListenSocket
function NetworkingSockets.CreateListenSocketP2PFakeIP(idxFakePort, nOptions, pOptions) end

---@param hConn integer -- HSteamNetConnection
---@return integer -- EResult
---@return SteamNetworkingIPAddr -- Value of: pOutAddr
function NetworkingSockets.GetRemoteFakeIPForConnection(hConn) end

Steam.NetworkingSockets = NetworkingSockets
