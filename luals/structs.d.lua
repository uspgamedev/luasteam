---@class SteamIPAddress_t
---@field m_rgubIPv6 string
---@field m_eType integer
local SteamIPAddress_t = {}

---@return boolean
function SteamIPAddress_t:IsSet() end

---@param table table?
---@return SteamIPAddress_t
function Steam.newSteamIPAddress_t(table) end

---@class FriendGameInfo_t
---@field m_gameID uint64
---@field m_unGameIP integer
---@field m_usGamePort integer
---@field m_usQueryPort integer
---@field m_steamIDLobby uint64
local FriendGameInfo_t = {}

---@param table table?
---@return FriendGameInfo_t
function Steam.newFriendGameInfo_t(table) end

---@class MatchMakingKeyValuePair_t
---@field m_szKey string
---@field m_szValue string
local MatchMakingKeyValuePair_t = {}

---@param table table?
---@return MatchMakingKeyValuePair_t
function Steam.newMatchMakingKeyValuePair_t(table) end

---@class servernetadr_t
local servernetadr_t = {}

---@param ip integer
---@param usQueryPort integer
---@param usConnectionPort integer
function servernetadr_t:Init(ip, usQueryPort, usConnectionPort) end

---@return integer
function servernetadr_t:GetQueryPort() end

---@param usPort integer
function servernetadr_t:SetQueryPort(usPort) end

---@return integer
function servernetadr_t:GetConnectionPort() end

---@param usPort integer
function servernetadr_t:SetConnectionPort(usPort) end

---@return integer
function servernetadr_t:GetIP() end

---@param unIP integer
function servernetadr_t:SetIP(unIP) end

---@return string
function servernetadr_t:GetConnectionAddressString() end

---@return string
function servernetadr_t:GetQueryAddressString() end

---@param table table?
---@return servernetadr_t
function Steam.newservernetadr_t(table) end

---@class gameserveritem_t
---@field m_NetAdr servernetadr_t
---@field m_nPing integer
---@field m_bHadSuccessfulResponse boolean
---@field m_bDoNotRefresh boolean
---@field m_szGameDir string
---@field m_szMap string
---@field m_szGameDescription string
---@field m_nAppID integer
---@field m_nPlayers integer
---@field m_nMaxPlayers integer
---@field m_nBotPlayers integer
---@field m_bPassword boolean
---@field m_bSecure boolean
---@field m_ulTimeLastPlayed integer
---@field m_nServerVersion integer
---@field m_szGameTags string
---@field m_steamID uint64
local gameserveritem_t = {}

---@return string
function gameserveritem_t:GetName() end

---@param pName string
function gameserveritem_t:SetName(pName) end

---@param table table?
---@return gameserveritem_t
function Steam.newgameserveritem_t(table) end

---@class SteamPartyBeaconLocation_t
---@field m_eType integer
---@field m_ulLocationID uint64
local SteamPartyBeaconLocation_t = {}

---@param table table?
---@return SteamPartyBeaconLocation_t
function Steam.newSteamPartyBeaconLocation_t(table) end

---@class SteamParamStringArray_t
---@field m_ppStrings string[]
local SteamParamStringArray_t = {}

---@param table table?
---@return SteamParamStringArray_t
function Steam.newSteamParamStringArray_t(table) end

---@class LeaderboardEntry_t
---@field m_steamIDUser uint64
---@field m_nGlobalRank integer
---@field m_nScore integer
---@field m_cDetails integer
---@field m_hUGC uint64
local LeaderboardEntry_t = {}

---@param table table?
---@return LeaderboardEntry_t
function Steam.newLeaderboardEntry_t(table) end

---@class P2PSessionState_t
---@field m_bConnectionActive integer
---@field m_bConnecting integer
---@field m_eP2PSessionError integer
---@field m_bUsingRelay integer
---@field m_nBytesQueuedForSend integer
---@field m_nPacketsQueuedForSend integer
---@field m_nRemoteIP integer
---@field m_nRemotePort integer
local P2PSessionState_t = {}

---@param table table?
---@return P2PSessionState_t
function Steam.newP2PSessionState_t(table) end

---@class InputAnalogActionData_t
---@field eMode integer
---@field x number
---@field y number
---@field bActive boolean
local InputAnalogActionData_t = {}

---@param table table?
---@return InputAnalogActionData_t
function Steam.newInputAnalogActionData_t(table) end

---@class InputDigitalActionData_t
---@field bState boolean
---@field bActive boolean
local InputDigitalActionData_t = {}

---@param table table?
---@return InputDigitalActionData_t
function Steam.newInputDigitalActionData_t(table) end

---@class InputMotionData_t
---@field rotQuatX number
---@field rotQuatY number
---@field rotQuatZ number
---@field rotQuatW number
---@field posAccelX number
---@field posAccelY number
---@field posAccelZ number
---@field rotVelX number
---@field rotVelY number
---@field rotVelZ number
local InputMotionData_t = {}

---@param table table?
---@return InputMotionData_t
function Steam.newInputMotionData_t(table) end

---@class SteamInputActionEvent_t
---@field controllerHandle uint64
---@field eEventType integer
local SteamInputActionEvent_t = {}

---@param table table?
---@return SteamInputActionEvent_t
function Steam.newSteamInputActionEvent_t(table) end

---@class SteamUGCDetails_t
---@field m_nPublishedFileId uint64
---@field m_eResult integer
---@field m_eFileType integer
---@field m_nCreatorAppID integer
---@field m_nConsumerAppID integer
---@field m_rgchTitle string
---@field m_rgchDescription string
---@field m_ulSteamIDOwner uint64
---@field m_rtimeCreated integer
---@field m_rtimeUpdated integer
---@field m_rtimeAddedToUserList integer
---@field m_eVisibility integer
---@field m_bBanned boolean
---@field m_bAcceptedForUse boolean
---@field m_bTagsTruncated boolean
---@field m_rgchTags string
---@field m_hFile uint64
---@field m_hPreviewFile uint64
---@field m_pchFileName string
---@field m_nFileSize integer
---@field m_nPreviewFileSize integer
---@field m_rgchURL string
---@field m_unVotesUp integer
---@field m_unVotesDown integer
---@field m_flScore number
---@field m_unNumChildren integer
---@field m_ulTotalFilesSize uint64
local SteamUGCDetails_t = {}

---@param table table?
---@return SteamUGCDetails_t
function Steam.newSteamUGCDetails_t(table) end

---@class SteamItemDetails_t
---@field m_itemId uint64
---@field m_iDefinition integer
---@field m_unQuantity integer
---@field m_unFlags integer
local SteamItemDetails_t = {}

---@param table table?
---@return SteamItemDetails_t
function Steam.newSteamItemDetails_t(table) end

---@class RemotePlayInputMouseMotion_t
---@field m_bAbsolute boolean
---@field m_flNormalizedX number
---@field m_flNormalizedY number
---@field m_nDeltaX integer
---@field m_nDeltaY integer
local RemotePlayInputMouseMotion_t = {}

---@param table table?
---@return RemotePlayInputMouseMotion_t
function Steam.newRemotePlayInputMouseMotion_t(table) end

---@class RemotePlayInputMouseWheel_t
---@field m_eDirection integer
---@field m_flAmount number
local RemotePlayInputMouseWheel_t = {}

---@param table table?
---@return RemotePlayInputMouseWheel_t
function Steam.newRemotePlayInputMouseWheel_t(table) end

---@class RemotePlayInputKey_t
---@field m_eScancode integer
---@field m_unModifiers integer
---@field m_unKeycode integer
local RemotePlayInputKey_t = {}

---@param table table?
---@return RemotePlayInputKey_t
function Steam.newRemotePlayInputKey_t(table) end

---@class RemotePlayInput_t
---@field m_unSessionID integer
---@field m_eType integer
---@field padding string
local RemotePlayInput_t = {}

---@param table table?
---@return RemotePlayInput_t
function Steam.newRemotePlayInput_t(table) end

---@class SteamNetworkingIPAddr
---@field m_ipv6 string
---@field m_port integer
local SteamNetworkingIPAddr = {}

function SteamNetworkingIPAddr:Clear() end

---@return boolean
function SteamNetworkingIPAddr:IsIPv6AllZeros() end

---@param ipv6 string
---@param nPort integer
function SteamNetworkingIPAddr:SetIPv6(ipv6, nPort) end

---@param nIP integer
---@param nPort integer
function SteamNetworkingIPAddr:SetIPv4(nIP, nPort) end

---@return boolean
function SteamNetworkingIPAddr:IsIPv4() end

---@return integer
function SteamNetworkingIPAddr:GetIPv4() end

---@param nPort integer
function SteamNetworkingIPAddr:SetIPv6LocalHost(nPort) end

---@return boolean
function SteamNetworkingIPAddr:IsLocalHost() end

---@param pszStr string
---@return boolean
function SteamNetworkingIPAddr:ParseString(pszStr) end

---@return integer
function SteamNetworkingIPAddr:GetFakeIPType() end

---@return boolean
function SteamNetworkingIPAddr:IsFakeIP() end

---@param table table?
---@return SteamNetworkingIPAddr
function Steam.newSteamNetworkingIPAddr(table) end

---@class SteamNetworkingIdentity
local SteamNetworkingIdentity = {}

function SteamNetworkingIdentity:Clear() end

---@return boolean
function SteamNetworkingIdentity:IsInvalid() end

---@param steamID uint64
function SteamNetworkingIdentity:SetSteamID(steamID) end

---@return uint64
function SteamNetworkingIdentity:GetSteamID() end

---@param steamID uint64
function SteamNetworkingIdentity:SetSteamID64(steamID) end

---@return uint64
function SteamNetworkingIdentity:GetSteamID64() end

---@param pszString string
---@return boolean
function SteamNetworkingIdentity:SetXboxPairwiseID(pszString) end

---@return string
function SteamNetworkingIdentity:GetXboxPairwiseID() end

---@param id uint64
function SteamNetworkingIdentity:SetPSNID(id) end

---@return uint64
function SteamNetworkingIdentity:GetPSNID() end

---@param addr SteamNetworkingIPAddr
function SteamNetworkingIdentity:SetIPAddr(addr) end

---@return SteamNetworkingIPAddr
function SteamNetworkingIdentity:GetIPAddr() end

---@param nIPv4 integer
---@param nPort integer
function SteamNetworkingIdentity:SetIPv4Addr(nIPv4, nPort) end

---@return integer
function SteamNetworkingIdentity:GetIPv4() end

---@return integer
function SteamNetworkingIdentity:GetFakeIPType() end

---@return boolean
function SteamNetworkingIdentity:IsFakeIP() end

function SteamNetworkingIdentity:SetLocalHost() end

---@return boolean
function SteamNetworkingIdentity:IsLocalHost() end

---@param pszString string
---@return boolean
function SteamNetworkingIdentity:SetGenericString(pszString) end

---@return string
function SteamNetworkingIdentity:GetGenericString() end

---@param data string
---@param cbLen integer
---@return boolean
function SteamNetworkingIdentity:SetGenericBytes(data, cbLen) end

---@param pszStr string
---@return boolean
function SteamNetworkingIdentity:ParseString(pszStr) end

---@param table table?
---@return SteamNetworkingIdentity
function Steam.newSteamNetworkingIdentity(table) end

---@class SteamNetConnectionInfo_t
---@field m_identityRemote SteamNetworkingIdentity
---@field m_nUserData uint64
---@field m_hListenSocket integer
---@field m_addrRemote SteamNetworkingIPAddr
---@field m__pad1 integer
---@field m_idPOPRemote integer
---@field m_idPOPRelay integer
---@field m_eState integer
---@field m_eEndReason integer
---@field m_szEndDebug string
---@field m_szConnectionDescription string
---@field m_nFlags integer
---@field reserved integer[]
local SteamNetConnectionInfo_t = {}

---@param table table?
---@return SteamNetConnectionInfo_t
function Steam.newSteamNetConnectionInfo_t(table) end

---@class SteamNetConnectionRealTimeStatus_t
---@field m_eState integer
---@field m_nPing integer
---@field m_flConnectionQualityLocal number
---@field m_flConnectionQualityRemote number
---@field m_flOutPacketsPerSec number
---@field m_flOutBytesPerSec number
---@field m_flInPacketsPerSec number
---@field m_flInBytesPerSec number
---@field m_nSendRateBytesPerSecond integer
---@field m_cbPendingUnreliable integer
---@field m_cbPendingReliable integer
---@field m_cbSentUnackedReliable integer
---@field reserved integer[]
local SteamNetConnectionRealTimeStatus_t = {}

---@param table table?
---@return SteamNetConnectionRealTimeStatus_t
function Steam.newSteamNetConnectionRealTimeStatus_t(table) end

---@class SteamNetConnectionRealTimeLaneStatus_t
---@field m_cbPendingUnreliable integer
---@field m_cbPendingReliable integer
---@field m_cbSentUnackedReliable integer
---@field _reservePad1 integer
---@field reserved integer[]
local SteamNetConnectionRealTimeLaneStatus_t = {}

---@param table table?
---@return SteamNetConnectionRealTimeLaneStatus_t
function Steam.newSteamNetConnectionRealTimeLaneStatus_t(table) end

---@class SteamNetworkPingLocation_t
---@field m_data string
local SteamNetworkPingLocation_t = {}

---@param table table?
---@return SteamNetworkPingLocation_t
function Steam.newSteamNetworkPingLocation_t(table) end

---@class SteamNetworkingConfigValue_t
---@field m_eValue integer
---@field m_eDataType integer
---@field m_val.m_int64 uint64
local SteamNetworkingConfigValue_t = {}

---@param eVal integer
---@param data uint64
function SteamNetworkingConfigValue_t:SetInt64(eVal, data) end

---@param eVal integer
---@param data number
function SteamNetworkingConfigValue_t:SetFloat(eVal, data) end

---@param eVal integer
---@param data string
function SteamNetworkingConfigValue_t:SetString(eVal, data) end

---@param table table?
---@return SteamNetworkingConfigValue_t
function Steam.newSteamNetworkingConfigValue_t(table) end

