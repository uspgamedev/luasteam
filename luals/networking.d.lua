---@class Steam.Networking
local Networking = {}

---@param steamIDRemote uint64
---@param pubData string
---@param cubData integer
---@param eP2PSendType integer
---@param nChannel integer
---@return boolean
function Networking.SendP2PPacket(steamIDRemote, pubData, cubData, eP2PSendType, nChannel) end

---@param nChannel integer
---@return boolean
---@return integer -- Value of: pcubMsgSize
function Networking.IsP2PPacketAvailable(nChannel) end

---@param cubDest integer
---@param nChannel integer
---@return boolean
---@return string -- Value of: pubDest
---@return integer -- Value of: pcubMsgSize
---@return uint64 -- Value of: psteamIDRemote
function Networking.ReadP2PPacket(cubDest, nChannel) end

---@param steamIDRemote uint64
---@return boolean
function Networking.AcceptP2PSessionWithUser(steamIDRemote) end

---@param steamIDRemote uint64
---@return boolean
function Networking.CloseP2PSessionWithUser(steamIDRemote) end

---@param steamIDRemote uint64
---@param nChannel integer
---@return boolean
function Networking.CloseP2PChannelWithUser(steamIDRemote, nChannel) end

---@param steamIDRemote uint64
---@return boolean
---@return P2PSessionState_t -- Value of: pConnectionState
function Networking.GetP2PSessionState(steamIDRemote) end

---@param bAllow boolean
---@return boolean
function Networking.AllowP2PPacketRelay(bAllow) end

---@param steamIDTarget uint64
---@param nVirtualPort integer
---@param nTimeoutSec integer
---@param bAllowUseOfPacketRelay boolean
---@return integer
function Networking.CreateP2PConnectionSocket(steamIDTarget, nVirtualPort, nTimeoutSec, bAllowUseOfPacketRelay) end

---@param hSocket integer
---@param bNotifyRemoteEnd boolean
---@return boolean
function Networking.DestroySocket(hSocket, bNotifyRemoteEnd) end

---@param hSocket integer
---@param bNotifyRemoteEnd boolean
---@return boolean
function Networking.DestroyListenSocket(hSocket, bNotifyRemoteEnd) end

---@param hSocket integer
---@param pubData string
---@param cubData integer
---@param bReliable boolean
---@return boolean
function Networking.SendDataOnSocket(hSocket, pubData, cubData, bReliable) end

---@param hSocket integer
---@return boolean
---@return integer -- Value of: pcubMsgSize
function Networking.IsDataAvailableOnSocket(hSocket) end

---@param hSocket integer
---@param cubDest integer
---@return boolean
---@return string -- Value of: pubDest
---@return integer -- Value of: pcubMsgSize
function Networking.RetrieveDataFromSocket(hSocket, cubDest) end

---@param hListenSocket integer
---@return boolean
---@return integer -- Value of: pcubMsgSize
---@return integer -- Value of: phSocket
function Networking.IsDataAvailable(hListenSocket) end

---@param hListenSocket integer
---@param cubDest integer
---@return boolean
---@return string -- Value of: pubDest
---@return integer -- Value of: pcubMsgSize
---@return integer -- Value of: phSocket
function Networking.RetrieveData(hListenSocket, cubDest) end

---@param hSocket integer
---@return boolean
---@return uint64 -- Value of: pSteamIDRemote
---@return integer -- Value of: peSocketStatus
---@return SteamIPAddress_t -- Value of: punIPRemote
---@return integer -- Value of: punPortRemote
function Networking.GetSocketInfo(hSocket) end

---@param hListenSocket integer
---@return boolean
---@return SteamIPAddress_t -- Value of: pnIP
---@return integer -- Value of: pnPort
function Networking.GetListenSocketInfo(hListenSocket) end

---@param hSocket integer
---@return integer
function Networking.GetSocketConnectionType(hSocket) end

---@param hSocket integer
---@return integer
function Networking.GetMaxPacketSize(hSocket) end

Steam.Networking = Networking
