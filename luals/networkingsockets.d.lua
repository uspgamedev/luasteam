---@class Steam.NetworkingSockets
local NetworkingSockets = {}

---@param localAddress SteamNetworkingIPAddr
---@param nOptions integer
---@param pOptions SteamNetworkingConfigValue_t
---@return integer
function NetworkingSockets.CreateListenSocketIP(localAddress, nOptions, pOptions) end

---@param address SteamNetworkingIPAddr
---@param nOptions integer
---@param pOptions SteamNetworkingConfigValue_t
---@return integer
function NetworkingSockets.ConnectByIPAddress(address, nOptions, pOptions) end

---@param nLocalVirtualPort integer
---@param nOptions integer
---@param pOptions SteamNetworkingConfigValue_t
---@return integer
function NetworkingSockets.CreateListenSocketP2P(nLocalVirtualPort, nOptions, pOptions) end

---@param identityRemote SteamNetworkingIdentity
---@param nRemoteVirtualPort integer
---@param nOptions integer
---@param pOptions SteamNetworkingConfigValue_t
---@return integer
function NetworkingSockets.ConnectP2P(identityRemote, nRemoteVirtualPort, nOptions, pOptions) end

---@param hConn integer
---@return integer
function NetworkingSockets.AcceptConnection(hConn) end

---@param hPeer integer
---@param nReason integer
---@param pszDebug string
---@param bEnableLinger boolean
---@return boolean
function NetworkingSockets.CloseConnection(hPeer, nReason, pszDebug, bEnableLinger) end

---@param hSocket integer
---@return boolean
function NetworkingSockets.CloseListenSocket(hSocket) end

---@param hPeer integer
---@param nUserData uint64
---@return boolean
function NetworkingSockets.SetConnectionUserData(hPeer, nUserData) end

---@param hPeer integer
---@return uint64
function NetworkingSockets.GetConnectionUserData(hPeer) end

---@param hPeer integer
---@param pszName string
function NetworkingSockets.SetConnectionName(hPeer, pszName) end

---@param hPeer integer
---@param nMaxLen integer
---@return boolean
---@return string -- Value of: pszName
function NetworkingSockets.GetConnectionName(hPeer, nMaxLen) end

---@param hConn integer
---@param pData string
---@param cbData integer
---@param nSendFlags integer
---@return integer
---@return uint64 -- Value of: pOutMessageNumber
function NetworkingSockets.SendMessageToConnection(hConn, pData, cbData, nSendFlags) end

---@param hConn integer
---@return integer
function NetworkingSockets.FlushMessagesOnConnection(hConn) end

---@param hConn integer
---@return boolean
---@return SteamNetConnectionInfo_t -- Value of: pInfo
function NetworkingSockets.GetConnectionInfo(hConn) end

---@param hConn integer
---@param nLanes integer
---@return integer
---@return SteamNetConnectionRealTimeStatus_t -- Value of: pStatus
---@return SteamNetConnectionRealTimeLaneStatus_t -- Value of: pLanes
function NetworkingSockets.GetConnectionRealTimeStatus(hConn, nLanes) end

---@param hConn integer
---@param cbBuf integer
---@return integer
---@return string -- Value of: pszBuf
function NetworkingSockets.GetDetailedConnectionStatus(hConn, cbBuf) end

---@param hSocket integer
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

---@return boolean
---@return SteamNetworkingIdentity -- Value of: pIdentity
function NetworkingSockets.GetIdentity() end

---@return integer
function NetworkingSockets.InitAuthentication() end

---@return integer
---@return SteamNetAuthenticationStatus_t -- Value of: pDetails
function NetworkingSockets.GetAuthenticationStatus() end

---@return integer
function NetworkingSockets.CreatePollGroup() end

---@param hPollGroup integer
---@return boolean
function NetworkingSockets.DestroyPollGroup(hPollGroup) end

---@param hConn integer
---@param hPollGroup integer
---@return boolean
function NetworkingSockets.SetConnectionPollGroup(hConn, hPollGroup) end

---@param identityTarget SteamNetworkingIdentity
---@param nRemoteVirtualPort integer
---@param nOptions integer
---@param pOptions SteamNetworkingConfigValue_t
---@return integer
function NetworkingSockets.ConnectToHostedDedicatedServer(identityTarget, nRemoteVirtualPort, nOptions, pOptions) end

---@return integer
function NetworkingSockets.GetHostedDedicatedServerPort() end

---@return integer
function NetworkingSockets.GetHostedDedicatedServerPOPID() end

---@param nLocalVirtualPort integer
---@param nOptions integer
---@param pOptions SteamNetworkingConfigValue_t
---@return integer
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
---@return integer
function NetworkingSockets.CreateListenSocketP2PFakeIP(idxFakePort, nOptions, pOptions) end

---@param hConn integer
---@return integer
---@return SteamNetworkingIPAddr -- Value of: pOutAddr
function NetworkingSockets.GetRemoteFakeIPForConnection(hConn) end

Steam.NetworkingSockets = NetworkingSockets
