---@class Steam.Networking
---@field OnP2PSessionRequest? fun(data: P2PSessionRequest_t)
---@field OnP2PSessionConnectFail? fun(data: P2PSessionConnectFail_t)
---@field OnSocketStatusCallback? fun(data: SocketStatusCallback_t)
local Networking = {}

---@param steamIDRemote uint64 -- CSteamID
---@param pubData string?
---@param cubData integer size of the input array pubData
---@param eP2PSendType integer -- EP2PSend
---@param nChannel integer
---@return boolean
function Networking.SendP2PPacket(steamIDRemote, pubData, cubData, eP2PSendType, nChannel) end

---@param nChannel integer
---@return boolean
---@return integer -- Value of: pcubMsgSize
function Networking.IsP2PPacketAvailable(nChannel) end

---@param cubDest integer? size of the buffer for pubDest; if nil then the buffer will be NULL
---@param nChannel integer
---@return boolean
---@return string -- Value of: pubDest
---@return integer -- Value of: pcubMsgSize
---@return uint64 -- Value of: psteamIDRemote
function Networking.ReadP2PPacket(cubDest, nChannel) end

---@param steamIDRemote uint64 -- CSteamID
---@return boolean
function Networking.AcceptP2PSessionWithUser(steamIDRemote) end

---@param steamIDRemote uint64 -- CSteamID
---@return boolean
function Networking.CloseP2PSessionWithUser(steamIDRemote) end

---@param steamIDRemote uint64 -- CSteamID
---@param nChannel integer
---@return boolean
function Networking.CloseP2PChannelWithUser(steamIDRemote, nChannel) end

---@param steamIDRemote uint64 -- CSteamID
---@return boolean
---@return P2PSessionState_t -- Value of: pConnectionState
function Networking.GetP2PSessionState(steamIDRemote) end

---@param bAllow boolean
---@return boolean
function Networking.AllowP2PPacketRelay(bAllow) end

---@param nVirtualP2PPort integer
---@param nIP SteamIPAddress_t -- SteamIPAddress_t
---@param nPort integer
---@param bAllowUseOfPacketRelay boolean
---@return integer -- SNetListenSocket_t
function Networking.CreateListenSocket(nVirtualP2PPort, nIP, nPort, bAllowUseOfPacketRelay) end

---@param steamIDTarget uint64 -- CSteamID
---@param nVirtualPort integer
---@param nTimeoutSec integer
---@param bAllowUseOfPacketRelay boolean
---@return integer -- SNetSocket_t
function Networking.CreateP2PConnectionSocket(steamIDTarget, nVirtualPort, nTimeoutSec, bAllowUseOfPacketRelay) end

---@param nIP SteamIPAddress_t -- SteamIPAddress_t
---@param nPort integer
---@param nTimeoutSec integer
---@return integer -- SNetSocket_t
function Networking.CreateConnectionSocket(nIP, nPort, nTimeoutSec) end

---@param hSocket integer -- SNetSocket_t
---@param bNotifyRemoteEnd boolean
---@return boolean
function Networking.DestroySocket(hSocket, bNotifyRemoteEnd) end

---@param hSocket integer -- SNetListenSocket_t
---@param bNotifyRemoteEnd boolean
---@return boolean
function Networking.DestroyListenSocket(hSocket, bNotifyRemoteEnd) end

---@param hSocket integer -- SNetSocket_t
---@param pubData string?
---@param cubData integer size of the input array pubData
---@param bReliable boolean
---@return boolean
function Networking.SendDataOnSocket(hSocket, pubData, cubData, bReliable) end

---@param hSocket integer -- SNetSocket_t
---@return boolean
---@return integer -- Value of: pcubMsgSize
function Networking.IsDataAvailableOnSocket(hSocket) end

---@param hSocket integer -- SNetSocket_t
---@param cubDest integer? size of the buffer for pubDest; if nil then the buffer will be NULL
---@return boolean
---@return string -- Value of: pubDest
---@return integer -- Value of: pcubMsgSize
function Networking.RetrieveDataFromSocket(hSocket, cubDest) end

---@param hListenSocket integer -- SNetListenSocket_t
---@return boolean
---@return integer -- Value of: pcubMsgSize
---@return integer -- Value of: phSocket
function Networking.IsDataAvailable(hListenSocket) end

---@param hListenSocket integer -- SNetListenSocket_t
---@param cubDest integer? size of the buffer for pubDest; if nil then the buffer will be NULL
---@return boolean
---@return string -- Value of: pubDest
---@return integer -- Value of: pcubMsgSize
---@return integer -- Value of: phSocket
function Networking.RetrieveData(hListenSocket, cubDest) end

---@param hSocket integer -- SNetSocket_t
---@return boolean
---@return uint64 -- Value of: pSteamIDRemote
---@return integer -- Value of: peSocketStatus
---@return SteamIPAddress_t -- Value of: punIPRemote
---@return integer -- Value of: punPortRemote
function Networking.GetSocketInfo(hSocket) end

---@param hListenSocket integer -- SNetListenSocket_t
---@return boolean
---@return SteamIPAddress_t -- Value of: pnIP
---@return integer -- Value of: pnPort
function Networking.GetListenSocketInfo(hListenSocket) end

---@param hSocket integer -- SNetSocket_t
---@return integer -- ESNetSocketConnectionType
function Networking.GetSocketConnectionType(hSocket) end

---@param hSocket integer -- SNetSocket_t
---@return integer
function Networking.GetMaxPacketSize(hSocket) end

Steam.Networking = Networking
