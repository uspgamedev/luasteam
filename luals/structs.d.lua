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

---@param cbBuf integer
---@param bWithPort boolean
function SteamNetworkingIPAddr:ToString(cbBuf, bWithPort) end

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

---@param cbBuf integer
function SteamNetworkingIdentity:ToString(cbBuf) end

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

---@class SteamServersConnected_t
local SteamServersConnected_t = {}

---@param table table?
---@return SteamServersConnected_t
function Steam.newSteamServersConnected_t(table) end

---@class SteamServerConnectFailure_t
---@field m_eResult integer
---@field m_bStillRetrying boolean
local SteamServerConnectFailure_t = {}

---@param table table?
---@return SteamServerConnectFailure_t
function Steam.newSteamServerConnectFailure_t(table) end

---@class SteamServersDisconnected_t
---@field m_eResult integer
local SteamServersDisconnected_t = {}

---@param table table?
---@return SteamServersDisconnected_t
function Steam.newSteamServersDisconnected_t(table) end

---@class ClientGameServerDeny_t
---@field m_uAppID integer
---@field m_unGameServerIP integer
---@field m_usGameServerPort integer
---@field m_bSecure integer
---@field m_uReason integer
local ClientGameServerDeny_t = {}

---@param table table?
---@return ClientGameServerDeny_t
function Steam.newClientGameServerDeny_t(table) end

---@class IPCFailure_t
---@field m_eFailureType integer
local IPCFailure_t = {}

---@param table table?
---@return IPCFailure_t
function Steam.newIPCFailure_t(table) end

---@class LicensesUpdated_t
local LicensesUpdated_t = {}

---@param table table?
---@return LicensesUpdated_t
function Steam.newLicensesUpdated_t(table) end

---@class ValidateAuthTicketResponse_t
---@field m_SteamID uint64
---@field m_eAuthSessionResponse integer
---@field m_OwnerSteamID uint64
local ValidateAuthTicketResponse_t = {}

---@param table table?
---@return ValidateAuthTicketResponse_t
function Steam.newValidateAuthTicketResponse_t(table) end

---@class MicroTxnAuthorizationResponse_t
---@field m_unAppID integer
---@field m_ulOrderID uint64
---@field m_bAuthorized integer
local MicroTxnAuthorizationResponse_t = {}

---@param table table?
---@return MicroTxnAuthorizationResponse_t
function Steam.newMicroTxnAuthorizationResponse_t(table) end

---@class EncryptedAppTicketResponse_t
---@field m_eResult integer
local EncryptedAppTicketResponse_t = {}

---@param table table?
---@return EncryptedAppTicketResponse_t
function Steam.newEncryptedAppTicketResponse_t(table) end

---@class GetAuthSessionTicketResponse_t
---@field m_hAuthTicket integer
---@field m_eResult integer
local GetAuthSessionTicketResponse_t = {}

---@param table table?
---@return GetAuthSessionTicketResponse_t
function Steam.newGetAuthSessionTicketResponse_t(table) end

---@class GameWebCallback_t
---@field m_szURL string
local GameWebCallback_t = {}

---@param table table?
---@return GameWebCallback_t
function Steam.newGameWebCallback_t(table) end

---@class StoreAuthURLResponse_t
---@field m_szURL string
local StoreAuthURLResponse_t = {}

---@param table table?
---@return StoreAuthURLResponse_t
function Steam.newStoreAuthURLResponse_t(table) end

---@class MarketEligibilityResponse_t
---@field m_bAllowed boolean
---@field m_eNotAllowedReason integer
---@field m_rtAllowedAtTime integer
---@field m_cdaySteamGuardRequiredDays integer
---@field m_cdayNewDeviceCooldown integer
local MarketEligibilityResponse_t = {}

---@param table table?
---@return MarketEligibilityResponse_t
function Steam.newMarketEligibilityResponse_t(table) end

---@class DurationControl_t
---@field m_eResult integer
---@field m_appid integer
---@field m_bApplicable boolean
---@field m_csecsLast5h integer
---@field m_progress integer
---@field m_notification integer
---@field m_csecsToday integer
---@field m_csecsRemaining integer
local DurationControl_t = {}

---@param table table?
---@return DurationControl_t
function Steam.newDurationControl_t(table) end

---@class GetTicketForWebApiResponse_t
---@field m_hAuthTicket integer
---@field m_eResult integer
---@field m_cubTicket integer
---@field m_rgubTicket string
local GetTicketForWebApiResponse_t = {}

---@param table table?
---@return GetTicketForWebApiResponse_t
function Steam.newGetTicketForWebApiResponse_t(table) end

---@class PersonaStateChange_t
---@field m_ulSteamID uint64
---@field m_nChangeFlags integer
local PersonaStateChange_t = {}

---@param table table?
---@return PersonaStateChange_t
function Steam.newPersonaStateChange_t(table) end

---@class GameOverlayActivated_t
---@field m_bActive integer
---@field m_bUserInitiated boolean
---@field m_nAppID integer
---@field m_dwOverlayPID integer
local GameOverlayActivated_t = {}

---@param table table?
---@return GameOverlayActivated_t
function Steam.newGameOverlayActivated_t(table) end

---@class GameServerChangeRequested_t
---@field m_rgchServer string
---@field m_rgchPassword string
local GameServerChangeRequested_t = {}

---@param table table?
---@return GameServerChangeRequested_t
function Steam.newGameServerChangeRequested_t(table) end

---@class GameLobbyJoinRequested_t
---@field m_steamIDLobby uint64
---@field m_steamIDFriend uint64
local GameLobbyJoinRequested_t = {}

---@param table table?
---@return GameLobbyJoinRequested_t
function Steam.newGameLobbyJoinRequested_t(table) end

---@class AvatarImageLoaded_t
---@field m_steamID uint64
---@field m_iImage integer
---@field m_iWide integer
---@field m_iTall integer
local AvatarImageLoaded_t = {}

---@param table table?
---@return AvatarImageLoaded_t
function Steam.newAvatarImageLoaded_t(table) end

---@class ClanOfficerListResponse_t
---@field m_steamIDClan uint64
---@field m_cOfficers integer
---@field m_bSuccess integer
local ClanOfficerListResponse_t = {}

---@param table table?
---@return ClanOfficerListResponse_t
function Steam.newClanOfficerListResponse_t(table) end

---@class FriendRichPresenceUpdate_t
---@field m_steamIDFriend uint64
---@field m_nAppID integer
local FriendRichPresenceUpdate_t = {}

---@param table table?
---@return FriendRichPresenceUpdate_t
function Steam.newFriendRichPresenceUpdate_t(table) end

---@class GameRichPresenceJoinRequested_t
---@field m_steamIDFriend uint64
---@field m_rgchConnect string
local GameRichPresenceJoinRequested_t = {}

---@param table table?
---@return GameRichPresenceJoinRequested_t
function Steam.newGameRichPresenceJoinRequested_t(table) end

---@class GameConnectedClanChatMsg_t
---@field m_steamIDClanChat uint64
---@field m_steamIDUser uint64
---@field m_iMessageID integer
local GameConnectedClanChatMsg_t = {}

---@param table table?
---@return GameConnectedClanChatMsg_t
function Steam.newGameConnectedClanChatMsg_t(table) end

---@class GameConnectedChatJoin_t
---@field m_steamIDClanChat uint64
---@field m_steamIDUser uint64
local GameConnectedChatJoin_t = {}

---@param table table?
---@return GameConnectedChatJoin_t
function Steam.newGameConnectedChatJoin_t(table) end

---@class GameConnectedChatLeave_t
---@field m_steamIDClanChat uint64
---@field m_steamIDUser uint64
---@field m_bKicked boolean
---@field m_bDropped boolean
local GameConnectedChatLeave_t = {}

---@param table table?
---@return GameConnectedChatLeave_t
function Steam.newGameConnectedChatLeave_t(table) end

---@class DownloadClanActivityCountsResult_t
---@field m_bSuccess boolean
local DownloadClanActivityCountsResult_t = {}

---@param table table?
---@return DownloadClanActivityCountsResult_t
function Steam.newDownloadClanActivityCountsResult_t(table) end

---@class JoinClanChatRoomCompletionResult_t
---@field m_steamIDClanChat uint64
---@field m_eChatRoomEnterResponse integer
local JoinClanChatRoomCompletionResult_t = {}

---@param table table?
---@return JoinClanChatRoomCompletionResult_t
function Steam.newJoinClanChatRoomCompletionResult_t(table) end

---@class GameConnectedFriendChatMsg_t
---@field m_steamIDUser uint64
---@field m_iMessageID integer
local GameConnectedFriendChatMsg_t = {}

---@param table table?
---@return GameConnectedFriendChatMsg_t
function Steam.newGameConnectedFriendChatMsg_t(table) end

---@class FriendsGetFollowerCount_t
---@field m_eResult integer
---@field m_steamID uint64
---@field m_nCount integer
local FriendsGetFollowerCount_t = {}

---@param table table?
---@return FriendsGetFollowerCount_t
function Steam.newFriendsGetFollowerCount_t(table) end

---@class FriendsIsFollowing_t
---@field m_eResult integer
---@field m_steamID uint64
---@field m_bIsFollowing boolean
local FriendsIsFollowing_t = {}

---@param table table?
---@return FriendsIsFollowing_t
function Steam.newFriendsIsFollowing_t(table) end

---@class FriendsEnumerateFollowingList_t
---@field m_eResult integer
---@field m_rgSteamID uint64[]
---@field m_nResultsReturned integer
---@field m_nTotalResultCount integer
local FriendsEnumerateFollowingList_t = {}

---@param table table?
---@return FriendsEnumerateFollowingList_t
function Steam.newFriendsEnumerateFollowingList_t(table) end

---@class UnreadChatMessagesChanged_t
local UnreadChatMessagesChanged_t = {}

---@param table table?
---@return UnreadChatMessagesChanged_t
function Steam.newUnreadChatMessagesChanged_t(table) end

---@class OverlayBrowserProtocolNavigation_t
---@field rgchURI string
local OverlayBrowserProtocolNavigation_t = {}

---@param table table?
---@return OverlayBrowserProtocolNavigation_t
function Steam.newOverlayBrowserProtocolNavigation_t(table) end

---@class EquippedProfileItemsChanged_t
---@field m_steamID uint64
local EquippedProfileItemsChanged_t = {}

---@param table table?
---@return EquippedProfileItemsChanged_t
function Steam.newEquippedProfileItemsChanged_t(table) end

---@class EquippedProfileItems_t
---@field m_eResult integer
---@field m_steamID uint64
---@field m_bHasAnimatedAvatar boolean
---@field m_bHasAvatarFrame boolean
---@field m_bHasProfileModifier boolean
---@field m_bHasProfileBackground boolean
---@field m_bHasMiniProfileBackground boolean
---@field m_bFromCache boolean
local EquippedProfileItems_t = {}

---@param table table?
---@return EquippedProfileItems_t
function Steam.newEquippedProfileItems_t(table) end

---@class IPCountry_t
local IPCountry_t = {}

---@param table table?
---@return IPCountry_t
function Steam.newIPCountry_t(table) end

---@class LowBatteryPower_t
---@field m_nMinutesBatteryLeft integer
local LowBatteryPower_t = {}

---@param table table?
---@return LowBatteryPower_t
function Steam.newLowBatteryPower_t(table) end

---@class SteamAPICallCompleted_t
---@field m_hAsyncCall uint64
---@field m_iCallback integer
---@field m_cubParam integer
local SteamAPICallCompleted_t = {}

---@param table table?
---@return SteamAPICallCompleted_t
function Steam.newSteamAPICallCompleted_t(table) end

---@class SteamShutdown_t
local SteamShutdown_t = {}

---@param table table?
---@return SteamShutdown_t
function Steam.newSteamShutdown_t(table) end

---@class CheckFileSignature_t
---@field m_eCheckFileSignature integer
local CheckFileSignature_t = {}

---@param table table?
---@return CheckFileSignature_t
function Steam.newCheckFileSignature_t(table) end

---@class GamepadTextInputDismissed_t
---@field m_bSubmitted boolean
---@field m_unSubmittedText integer
---@field m_unAppID integer
local GamepadTextInputDismissed_t = {}

---@param table table?
---@return GamepadTextInputDismissed_t
function Steam.newGamepadTextInputDismissed_t(table) end

---@class AppResumingFromSuspend_t
local AppResumingFromSuspend_t = {}

---@param table table?
---@return AppResumingFromSuspend_t
function Steam.newAppResumingFromSuspend_t(table) end

---@class FloatingGamepadTextInputDismissed_t
local FloatingGamepadTextInputDismissed_t = {}

---@param table table?
---@return FloatingGamepadTextInputDismissed_t
function Steam.newFloatingGamepadTextInputDismissed_t(table) end

---@class FilterTextDictionaryChanged_t
---@field m_eLanguage integer
local FilterTextDictionaryChanged_t = {}

---@param table table?
---@return FilterTextDictionaryChanged_t
function Steam.newFilterTextDictionaryChanged_t(table) end

---@class FavoritesListChanged_t
---@field m_nIP integer
---@field m_nQueryPort integer
---@field m_nConnPort integer
---@field m_nAppID integer
---@field m_nFlags integer
---@field m_bAdd boolean
---@field m_unAccountId integer
local FavoritesListChanged_t = {}

---@param table table?
---@return FavoritesListChanged_t
function Steam.newFavoritesListChanged_t(table) end

---@class LobbyInvite_t
---@field m_ulSteamIDUser uint64
---@field m_ulSteamIDLobby uint64
---@field m_ulGameID uint64
local LobbyInvite_t = {}

---@param table table?
---@return LobbyInvite_t
function Steam.newLobbyInvite_t(table) end

---@class LobbyEnter_t
---@field m_ulSteamIDLobby uint64
---@field m_rgfChatPermissions integer
---@field m_bLocked boolean
---@field m_EChatRoomEnterResponse integer
local LobbyEnter_t = {}

---@param table table?
---@return LobbyEnter_t
function Steam.newLobbyEnter_t(table) end

---@class LobbyDataUpdate_t
---@field m_ulSteamIDLobby uint64
---@field m_ulSteamIDMember uint64
---@field m_bSuccess integer
local LobbyDataUpdate_t = {}

---@param table table?
---@return LobbyDataUpdate_t
function Steam.newLobbyDataUpdate_t(table) end

---@class LobbyChatUpdate_t
---@field m_ulSteamIDLobby uint64
---@field m_ulSteamIDUserChanged uint64
---@field m_ulSteamIDMakingChange uint64
---@field m_rgfChatMemberStateChange integer
local LobbyChatUpdate_t = {}

---@param table table?
---@return LobbyChatUpdate_t
function Steam.newLobbyChatUpdate_t(table) end

---@class LobbyChatMsg_t
---@field m_ulSteamIDLobby uint64
---@field m_ulSteamIDUser uint64
---@field m_eChatEntryType integer
---@field m_iChatID integer
local LobbyChatMsg_t = {}

---@param table table?
---@return LobbyChatMsg_t
function Steam.newLobbyChatMsg_t(table) end

---@class LobbyGameCreated_t
---@field m_ulSteamIDLobby uint64
---@field m_ulSteamIDGameServer uint64
---@field m_unIP integer
---@field m_usPort integer
local LobbyGameCreated_t = {}

---@param table table?
---@return LobbyGameCreated_t
function Steam.newLobbyGameCreated_t(table) end

---@class LobbyMatchList_t
---@field m_nLobbiesMatching integer
local LobbyMatchList_t = {}

---@param table table?
---@return LobbyMatchList_t
function Steam.newLobbyMatchList_t(table) end

---@class LobbyKicked_t
---@field m_ulSteamIDLobby uint64
---@field m_ulSteamIDAdmin uint64
---@field m_bKickedDueToDisconnect integer
local LobbyKicked_t = {}

---@param table table?
---@return LobbyKicked_t
function Steam.newLobbyKicked_t(table) end

---@class LobbyCreated_t
---@field m_eResult integer
---@field m_ulSteamIDLobby uint64
local LobbyCreated_t = {}

---@param table table?
---@return LobbyCreated_t
function Steam.newLobbyCreated_t(table) end

---@class FavoritesListAccountsUpdated_t
---@field m_eResult integer
local FavoritesListAccountsUpdated_t = {}

---@param table table?
---@return FavoritesListAccountsUpdated_t
function Steam.newFavoritesListAccountsUpdated_t(table) end

---@class JoinPartyCallback_t
---@field m_eResult integer
---@field m_ulBeaconID uint64
---@field m_SteamIDBeaconOwner uint64
---@field m_rgchConnectString string
local JoinPartyCallback_t = {}

---@param table table?
---@return JoinPartyCallback_t
function Steam.newJoinPartyCallback_t(table) end

---@class CreateBeaconCallback_t
---@field m_eResult integer
---@field m_ulBeaconID uint64
local CreateBeaconCallback_t = {}

---@param table table?
---@return CreateBeaconCallback_t
function Steam.newCreateBeaconCallback_t(table) end

---@class ReservationNotificationCallback_t
---@field m_ulBeaconID uint64
---@field m_steamIDJoiner uint64
local ReservationNotificationCallback_t = {}

---@param table table?
---@return ReservationNotificationCallback_t
function Steam.newReservationNotificationCallback_t(table) end

---@class ChangeNumOpenSlotsCallback_t
---@field m_eResult integer
local ChangeNumOpenSlotsCallback_t = {}

---@param table table?
---@return ChangeNumOpenSlotsCallback_t
function Steam.newChangeNumOpenSlotsCallback_t(table) end

---@class AvailableBeaconLocationsUpdated_t
local AvailableBeaconLocationsUpdated_t = {}

---@param table table?
---@return AvailableBeaconLocationsUpdated_t
function Steam.newAvailableBeaconLocationsUpdated_t(table) end

---@class ActiveBeaconsUpdated_t
local ActiveBeaconsUpdated_t = {}

---@param table table?
---@return ActiveBeaconsUpdated_t
function Steam.newActiveBeaconsUpdated_t(table) end

---@class RemoteStorageFileShareResult_t
---@field m_eResult integer
---@field m_hFile uint64
---@field m_rgchFilename string
local RemoteStorageFileShareResult_t = {}

---@param table table?
---@return RemoteStorageFileShareResult_t
function Steam.newRemoteStorageFileShareResult_t(table) end

---@class RemoteStoragePublishFileResult_t
---@field m_eResult integer
---@field m_nPublishedFileId uint64
---@field m_bUserNeedsToAcceptWorkshopLegalAgreement boolean
local RemoteStoragePublishFileResult_t = {}

---@param table table?
---@return RemoteStoragePublishFileResult_t
function Steam.newRemoteStoragePublishFileResult_t(table) end

---@class RemoteStorageDeletePublishedFileResult_t
---@field m_eResult integer
---@field m_nPublishedFileId uint64
local RemoteStorageDeletePublishedFileResult_t = {}

---@param table table?
---@return RemoteStorageDeletePublishedFileResult_t
function Steam.newRemoteStorageDeletePublishedFileResult_t(table) end

---@class RemoteStorageEnumerateUserPublishedFilesResult_t
---@field m_eResult integer
---@field m_nResultsReturned integer
---@field m_nTotalResultCount integer
---@field m_rgPublishedFileId uint64[]
local RemoteStorageEnumerateUserPublishedFilesResult_t = {}

---@param table table?
---@return RemoteStorageEnumerateUserPublishedFilesResult_t
function Steam.newRemoteStorageEnumerateUserPublishedFilesResult_t(table) end

---@class RemoteStorageSubscribePublishedFileResult_t
---@field m_eResult integer
---@field m_nPublishedFileId uint64
local RemoteStorageSubscribePublishedFileResult_t = {}

---@param table table?
---@return RemoteStorageSubscribePublishedFileResult_t
function Steam.newRemoteStorageSubscribePublishedFileResult_t(table) end

---@class RemoteStorageEnumerateUserSubscribedFilesResult_t
---@field m_eResult integer
---@field m_nResultsReturned integer
---@field m_nTotalResultCount integer
---@field m_rgPublishedFileId uint64[]
---@field m_rgRTimeSubscribed integer[]
local RemoteStorageEnumerateUserSubscribedFilesResult_t = {}

---@param table table?
---@return RemoteStorageEnumerateUserSubscribedFilesResult_t
function Steam.newRemoteStorageEnumerateUserSubscribedFilesResult_t(table) end

---@class RemoteStorageUnsubscribePublishedFileResult_t
---@field m_eResult integer
---@field m_nPublishedFileId uint64
local RemoteStorageUnsubscribePublishedFileResult_t = {}

---@param table table?
---@return RemoteStorageUnsubscribePublishedFileResult_t
function Steam.newRemoteStorageUnsubscribePublishedFileResult_t(table) end

---@class RemoteStorageUpdatePublishedFileResult_t
---@field m_eResult integer
---@field m_nPublishedFileId uint64
---@field m_bUserNeedsToAcceptWorkshopLegalAgreement boolean
local RemoteStorageUpdatePublishedFileResult_t = {}

---@param table table?
---@return RemoteStorageUpdatePublishedFileResult_t
function Steam.newRemoteStorageUpdatePublishedFileResult_t(table) end

---@class RemoteStorageDownloadUGCResult_t
---@field m_eResult integer
---@field m_hFile uint64
---@field m_nAppID integer
---@field m_nSizeInBytes integer
---@field m_pchFileName string
---@field m_ulSteamIDOwner uint64
local RemoteStorageDownloadUGCResult_t = {}

---@param table table?
---@return RemoteStorageDownloadUGCResult_t
function Steam.newRemoteStorageDownloadUGCResult_t(table) end

---@class RemoteStorageGetPublishedFileDetailsResult_t
---@field m_eResult integer
---@field m_nPublishedFileId uint64
---@field m_nCreatorAppID integer
---@field m_nConsumerAppID integer
---@field m_rgchTitle string
---@field m_rgchDescription string
---@field m_hFile uint64
---@field m_hPreviewFile uint64
---@field m_ulSteamIDOwner uint64
---@field m_rtimeCreated integer
---@field m_rtimeUpdated integer
---@field m_eVisibility integer
---@field m_bBanned boolean
---@field m_rgchTags string
---@field m_bTagsTruncated boolean
---@field m_pchFileName string
---@field m_nFileSize integer
---@field m_nPreviewFileSize integer
---@field m_rgchURL string
---@field m_eFileType integer
---@field m_bAcceptedForUse boolean
local RemoteStorageGetPublishedFileDetailsResult_t = {}

---@param table table?
---@return RemoteStorageGetPublishedFileDetailsResult_t
function Steam.newRemoteStorageGetPublishedFileDetailsResult_t(table) end

---@class RemoteStorageEnumerateWorkshopFilesResult_t
---@field m_eResult integer
---@field m_nResultsReturned integer
---@field m_nTotalResultCount integer
---@field m_rgPublishedFileId uint64[]
---@field m_rgScore number[]
---@field m_nAppId integer
---@field m_unStartIndex integer
local RemoteStorageEnumerateWorkshopFilesResult_t = {}

---@param table table?
---@return RemoteStorageEnumerateWorkshopFilesResult_t
function Steam.newRemoteStorageEnumerateWorkshopFilesResult_t(table) end

---@class RemoteStorageGetPublishedItemVoteDetailsResult_t
---@field m_eResult integer
---@field m_unPublishedFileId uint64
---@field m_nVotesFor integer
---@field m_nVotesAgainst integer
---@field m_nReports integer
---@field m_fScore number
local RemoteStorageGetPublishedItemVoteDetailsResult_t = {}

---@param table table?
---@return RemoteStorageGetPublishedItemVoteDetailsResult_t
function Steam.newRemoteStorageGetPublishedItemVoteDetailsResult_t(table) end

---@class RemoteStoragePublishedFileSubscribed_t
---@field m_nPublishedFileId uint64
---@field m_nAppID integer
local RemoteStoragePublishedFileSubscribed_t = {}

---@param table table?
---@return RemoteStoragePublishedFileSubscribed_t
function Steam.newRemoteStoragePublishedFileSubscribed_t(table) end

---@class RemoteStoragePublishedFileUnsubscribed_t
---@field m_nPublishedFileId uint64
---@field m_nAppID integer
local RemoteStoragePublishedFileUnsubscribed_t = {}

---@param table table?
---@return RemoteStoragePublishedFileUnsubscribed_t
function Steam.newRemoteStoragePublishedFileUnsubscribed_t(table) end

---@class RemoteStoragePublishedFileDeleted_t
---@field m_nPublishedFileId uint64
---@field m_nAppID integer
local RemoteStoragePublishedFileDeleted_t = {}

---@param table table?
---@return RemoteStoragePublishedFileDeleted_t
function Steam.newRemoteStoragePublishedFileDeleted_t(table) end

---@class RemoteStorageUpdateUserPublishedItemVoteResult_t
---@field m_eResult integer
---@field m_nPublishedFileId uint64
local RemoteStorageUpdateUserPublishedItemVoteResult_t = {}

---@param table table?
---@return RemoteStorageUpdateUserPublishedItemVoteResult_t
function Steam.newRemoteStorageUpdateUserPublishedItemVoteResult_t(table) end

---@class RemoteStorageUserVoteDetails_t
---@field m_eResult integer
---@field m_nPublishedFileId uint64
---@field m_eVote integer
local RemoteStorageUserVoteDetails_t = {}

---@param table table?
---@return RemoteStorageUserVoteDetails_t
function Steam.newRemoteStorageUserVoteDetails_t(table) end

---@class RemoteStorageEnumerateUserSharedWorkshopFilesResult_t
---@field m_eResult integer
---@field m_nResultsReturned integer
---@field m_nTotalResultCount integer
---@field m_rgPublishedFileId uint64[]
local RemoteStorageEnumerateUserSharedWorkshopFilesResult_t = {}

---@param table table?
---@return RemoteStorageEnumerateUserSharedWorkshopFilesResult_t
function Steam.newRemoteStorageEnumerateUserSharedWorkshopFilesResult_t(table) end

---@class RemoteStorageSetUserPublishedFileActionResult_t
---@field m_eResult integer
---@field m_nPublishedFileId uint64
---@field m_eAction integer
local RemoteStorageSetUserPublishedFileActionResult_t = {}

---@param table table?
---@return RemoteStorageSetUserPublishedFileActionResult_t
function Steam.newRemoteStorageSetUserPublishedFileActionResult_t(table) end

---@class RemoteStorageEnumeratePublishedFilesByUserActionResult_t
---@field m_eResult integer
---@field m_eAction integer
---@field m_nResultsReturned integer
---@field m_nTotalResultCount integer
---@field m_rgPublishedFileId uint64[]
---@field m_rgRTimeUpdated integer[]
local RemoteStorageEnumeratePublishedFilesByUserActionResult_t = {}

---@param table table?
---@return RemoteStorageEnumeratePublishedFilesByUserActionResult_t
function Steam.newRemoteStorageEnumeratePublishedFilesByUserActionResult_t(table) end

---@class RemoteStoragePublishFileProgress_t
---@field m_dPercentFile number
---@field m_bPreview boolean
local RemoteStoragePublishFileProgress_t = {}

---@param table table?
---@return RemoteStoragePublishFileProgress_t
function Steam.newRemoteStoragePublishFileProgress_t(table) end

---@class RemoteStoragePublishedFileUpdated_t
---@field m_nPublishedFileId uint64
---@field m_nAppID integer
---@field m_ulUnused uint64
local RemoteStoragePublishedFileUpdated_t = {}

---@param table table?
---@return RemoteStoragePublishedFileUpdated_t
function Steam.newRemoteStoragePublishedFileUpdated_t(table) end

---@class RemoteStorageFileWriteAsyncComplete_t
---@field m_eResult integer
local RemoteStorageFileWriteAsyncComplete_t = {}

---@param table table?
---@return RemoteStorageFileWriteAsyncComplete_t
function Steam.newRemoteStorageFileWriteAsyncComplete_t(table) end

---@class RemoteStorageFileReadAsyncComplete_t
---@field m_hFileReadAsync uint64
---@field m_eResult integer
---@field m_nOffset integer
---@field m_cubRead integer
local RemoteStorageFileReadAsyncComplete_t = {}

---@param table table?
---@return RemoteStorageFileReadAsyncComplete_t
function Steam.newRemoteStorageFileReadAsyncComplete_t(table) end

---@class RemoteStorageLocalFileChange_t
local RemoteStorageLocalFileChange_t = {}

---@param table table?
---@return RemoteStorageLocalFileChange_t
function Steam.newRemoteStorageLocalFileChange_t(table) end

---@class UserStatsReceived_t
---@field m_nGameID uint64
---@field m_eResult integer
---@field m_steamIDUser uint64
local UserStatsReceived_t = {}

---@param table table?
---@return UserStatsReceived_t
function Steam.newUserStatsReceived_t(table) end

---@class UserStatsStored_t
---@field m_nGameID uint64
---@field m_eResult integer
local UserStatsStored_t = {}

---@param table table?
---@return UserStatsStored_t
function Steam.newUserStatsStored_t(table) end

---@class UserAchievementStored_t
---@field m_nGameID uint64
---@field m_bGroupAchievement boolean
---@field m_rgchAchievementName string
---@field m_nCurProgress integer
---@field m_nMaxProgress integer
local UserAchievementStored_t = {}

---@param table table?
---@return UserAchievementStored_t
function Steam.newUserAchievementStored_t(table) end

---@class LeaderboardFindResult_t
---@field m_hSteamLeaderboard uint64
---@field m_bLeaderboardFound integer
local LeaderboardFindResult_t = {}

---@param table table?
---@return LeaderboardFindResult_t
function Steam.newLeaderboardFindResult_t(table) end

---@class LeaderboardScoresDownloaded_t
---@field m_hSteamLeaderboard uint64
---@field m_hSteamLeaderboardEntries uint64
---@field m_cEntryCount integer
local LeaderboardScoresDownloaded_t = {}

---@param table table?
---@return LeaderboardScoresDownloaded_t
function Steam.newLeaderboardScoresDownloaded_t(table) end

---@class LeaderboardScoreUploaded_t
---@field m_bSuccess integer
---@field m_hSteamLeaderboard uint64
---@field m_nScore integer
---@field m_bScoreChanged integer
---@field m_nGlobalRankNew integer
---@field m_nGlobalRankPrevious integer
local LeaderboardScoreUploaded_t = {}

---@param table table?
---@return LeaderboardScoreUploaded_t
function Steam.newLeaderboardScoreUploaded_t(table) end

---@class NumberOfCurrentPlayers_t
---@field m_bSuccess integer
---@field m_cPlayers integer
local NumberOfCurrentPlayers_t = {}

---@param table table?
---@return NumberOfCurrentPlayers_t
function Steam.newNumberOfCurrentPlayers_t(table) end

---@class UserStatsUnloaded_t
---@field m_steamIDUser uint64
local UserStatsUnloaded_t = {}

---@param table table?
---@return UserStatsUnloaded_t
function Steam.newUserStatsUnloaded_t(table) end

---@class UserAchievementIconFetched_t
---@field m_nGameID uint64
---@field m_rgchAchievementName string
---@field m_bAchieved boolean
---@field m_nIconHandle integer
local UserAchievementIconFetched_t = {}

---@param table table?
---@return UserAchievementIconFetched_t
function Steam.newUserAchievementIconFetched_t(table) end

---@class GlobalAchievementPercentagesReady_t
---@field m_nGameID uint64
---@field m_eResult integer
local GlobalAchievementPercentagesReady_t = {}

---@param table table?
---@return GlobalAchievementPercentagesReady_t
function Steam.newGlobalAchievementPercentagesReady_t(table) end

---@class LeaderboardUGCSet_t
---@field m_eResult integer
---@field m_hSteamLeaderboard uint64
local LeaderboardUGCSet_t = {}

---@param table table?
---@return LeaderboardUGCSet_t
function Steam.newLeaderboardUGCSet_t(table) end

---@class GlobalStatsReceived_t
---@field m_nGameID uint64
---@field m_eResult integer
local GlobalStatsReceived_t = {}

---@param table table?
---@return GlobalStatsReceived_t
function Steam.newGlobalStatsReceived_t(table) end

---@class DlcInstalled_t
---@field m_nAppID integer
local DlcInstalled_t = {}

---@param table table?
---@return DlcInstalled_t
function Steam.newDlcInstalled_t(table) end

---@class NewUrlLaunchParameters_t
local NewUrlLaunchParameters_t = {}

---@param table table?
---@return NewUrlLaunchParameters_t
function Steam.newNewUrlLaunchParameters_t(table) end

---@class AppProofOfPurchaseKeyResponse_t
---@field m_eResult integer
---@field m_nAppID integer
---@field m_cchKeyLength integer
---@field m_rgchKey string
local AppProofOfPurchaseKeyResponse_t = {}

---@param table table?
---@return AppProofOfPurchaseKeyResponse_t
function Steam.newAppProofOfPurchaseKeyResponse_t(table) end

---@class FileDetailsResult_t
---@field m_eResult integer
---@field m_ulFileSize uint64
---@field m_FileSHA string
---@field m_unFlags integer
local FileDetailsResult_t = {}

---@param table table?
---@return FileDetailsResult_t
function Steam.newFileDetailsResult_t(table) end

---@class TimedTrialStatus_t
---@field m_unAppID integer
---@field m_bIsOffline boolean
---@field m_unSecondsAllowed integer
---@field m_unSecondsPlayed integer
local TimedTrialStatus_t = {}

---@param table table?
---@return TimedTrialStatus_t
function Steam.newTimedTrialStatus_t(table) end

---@class P2PSessionRequest_t
---@field m_steamIDRemote uint64
local P2PSessionRequest_t = {}

---@param table table?
---@return P2PSessionRequest_t
function Steam.newP2PSessionRequest_t(table) end

---@class P2PSessionConnectFail_t
---@field m_steamIDRemote uint64
---@field m_eP2PSessionError integer
local P2PSessionConnectFail_t = {}

---@param table table?
---@return P2PSessionConnectFail_t
function Steam.newP2PSessionConnectFail_t(table) end

---@class SocketStatusCallback_t
---@field m_hSocket integer
---@field m_hListenSocket integer
---@field m_steamIDRemote uint64
---@field m_eSNetSocketState integer
local SocketStatusCallback_t = {}

---@param table table?
---@return SocketStatusCallback_t
function Steam.newSocketStatusCallback_t(table) end

---@class ScreenshotReady_t
---@field m_hLocal integer
---@field m_eResult integer
local ScreenshotReady_t = {}

---@param table table?
---@return ScreenshotReady_t
function Steam.newScreenshotReady_t(table) end

---@class ScreenshotRequested_t
local ScreenshotRequested_t = {}

---@param table table?
---@return ScreenshotRequested_t
function Steam.newScreenshotRequested_t(table) end

---@class PlaybackStatusHasChanged_t
local PlaybackStatusHasChanged_t = {}

---@param table table?
---@return PlaybackStatusHasChanged_t
function Steam.newPlaybackStatusHasChanged_t(table) end

---@class VolumeHasChanged_t
---@field m_flNewVolume number
local VolumeHasChanged_t = {}

---@param table table?
---@return VolumeHasChanged_t
function Steam.newVolumeHasChanged_t(table) end

---@class HTTPRequestCompleted_t
---@field m_hRequest integer
---@field m_ulContextValue uint64
---@field m_bRequestSuccessful boolean
---@field m_eStatusCode integer
---@field m_unBodySize integer
local HTTPRequestCompleted_t = {}

---@param table table?
---@return HTTPRequestCompleted_t
function Steam.newHTTPRequestCompleted_t(table) end

---@class HTTPRequestHeadersReceived_t
---@field m_hRequest integer
---@field m_ulContextValue uint64
local HTTPRequestHeadersReceived_t = {}

---@param table table?
---@return HTTPRequestHeadersReceived_t
function Steam.newHTTPRequestHeadersReceived_t(table) end

---@class HTTPRequestDataReceived_t
---@field m_hRequest integer
---@field m_ulContextValue uint64
---@field m_cOffset integer
---@field m_cBytesReceived integer
local HTTPRequestDataReceived_t = {}

---@param table table?
---@return HTTPRequestDataReceived_t
function Steam.newHTTPRequestDataReceived_t(table) end

---@class SteamInputDeviceConnected_t
---@field m_ulConnectedDeviceHandle uint64
local SteamInputDeviceConnected_t = {}

---@param table table?
---@return SteamInputDeviceConnected_t
function Steam.newSteamInputDeviceConnected_t(table) end

---@class SteamInputDeviceDisconnected_t
---@field m_ulDisconnectedDeviceHandle uint64
local SteamInputDeviceDisconnected_t = {}

---@param table table?
---@return SteamInputDeviceDisconnected_t
function Steam.newSteamInputDeviceDisconnected_t(table) end

---@class SteamInputConfigurationLoaded_t
---@field m_unAppID integer
---@field m_ulDeviceHandle uint64
---@field m_ulMappingCreator uint64
---@field m_unMajorRevision integer
---@field m_unMinorRevision integer
---@field m_bUsesSteamInputAPI boolean
---@field m_bUsesGamepadAPI boolean
local SteamInputConfigurationLoaded_t = {}

---@param table table?
---@return SteamInputConfigurationLoaded_t
function Steam.newSteamInputConfigurationLoaded_t(table) end

---@class SteamInputGamepadSlotChange_t
---@field m_unAppID integer
---@field m_ulDeviceHandle uint64
---@field m_eDeviceType integer
---@field m_nOldGamepadSlot integer
---@field m_nNewGamepadSlot integer
local SteamInputGamepadSlotChange_t = {}

---@param table table?
---@return SteamInputGamepadSlotChange_t
function Steam.newSteamInputGamepadSlotChange_t(table) end

---@class SteamUGCQueryCompleted_t
---@field m_handle uint64
---@field m_eResult integer
---@field m_unNumResultsReturned integer
---@field m_unTotalMatchingResults integer
---@field m_bCachedData boolean
---@field m_rgchNextCursor string
local SteamUGCQueryCompleted_t = {}

---@param table table?
---@return SteamUGCQueryCompleted_t
function Steam.newSteamUGCQueryCompleted_t(table) end

---@class SteamUGCRequestUGCDetailsResult_t
---@field m_details SteamUGCDetails_t
---@field m_bCachedData boolean
local SteamUGCRequestUGCDetailsResult_t = {}

---@param table table?
---@return SteamUGCRequestUGCDetailsResult_t
function Steam.newSteamUGCRequestUGCDetailsResult_t(table) end

---@class CreateItemResult_t
---@field m_eResult integer
---@field m_nPublishedFileId uint64
---@field m_bUserNeedsToAcceptWorkshopLegalAgreement boolean
local CreateItemResult_t = {}

---@param table table?
---@return CreateItemResult_t
function Steam.newCreateItemResult_t(table) end

---@class SubmitItemUpdateResult_t
---@field m_eResult integer
---@field m_bUserNeedsToAcceptWorkshopLegalAgreement boolean
---@field m_nPublishedFileId uint64
local SubmitItemUpdateResult_t = {}

---@param table table?
---@return SubmitItemUpdateResult_t
function Steam.newSubmitItemUpdateResult_t(table) end

---@class ItemInstalled_t
---@field m_unAppID integer
---@field m_nPublishedFileId uint64
---@field m_hLegacyContent uint64
---@field m_unManifestID uint64
local ItemInstalled_t = {}

---@param table table?
---@return ItemInstalled_t
function Steam.newItemInstalled_t(table) end

---@class DownloadItemResult_t
---@field m_unAppID integer
---@field m_nPublishedFileId uint64
---@field m_eResult integer
local DownloadItemResult_t = {}

---@param table table?
---@return DownloadItemResult_t
function Steam.newDownloadItemResult_t(table) end

---@class UserFavoriteItemsListChanged_t
---@field m_nPublishedFileId uint64
---@field m_eResult integer
---@field m_bWasAddRequest boolean
local UserFavoriteItemsListChanged_t = {}

---@param table table?
---@return UserFavoriteItemsListChanged_t
function Steam.newUserFavoriteItemsListChanged_t(table) end

---@class SetUserItemVoteResult_t
---@field m_nPublishedFileId uint64
---@field m_eResult integer
---@field m_bVoteUp boolean
local SetUserItemVoteResult_t = {}

---@param table table?
---@return SetUserItemVoteResult_t
function Steam.newSetUserItemVoteResult_t(table) end

---@class GetUserItemVoteResult_t
---@field m_nPublishedFileId uint64
---@field m_eResult integer
---@field m_bVotedUp boolean
---@field m_bVotedDown boolean
---@field m_bVoteSkipped boolean
local GetUserItemVoteResult_t = {}

---@param table table?
---@return GetUserItemVoteResult_t
function Steam.newGetUserItemVoteResult_t(table) end

---@class StartPlaytimeTrackingResult_t
---@field m_eResult integer
local StartPlaytimeTrackingResult_t = {}

---@param table table?
---@return StartPlaytimeTrackingResult_t
function Steam.newStartPlaytimeTrackingResult_t(table) end

---@class StopPlaytimeTrackingResult_t
---@field m_eResult integer
local StopPlaytimeTrackingResult_t = {}

---@param table table?
---@return StopPlaytimeTrackingResult_t
function Steam.newStopPlaytimeTrackingResult_t(table) end

---@class AddUGCDependencyResult_t
---@field m_eResult integer
---@field m_nPublishedFileId uint64
---@field m_nChildPublishedFileId uint64
local AddUGCDependencyResult_t = {}

---@param table table?
---@return AddUGCDependencyResult_t
function Steam.newAddUGCDependencyResult_t(table) end

---@class RemoveUGCDependencyResult_t
---@field m_eResult integer
---@field m_nPublishedFileId uint64
---@field m_nChildPublishedFileId uint64
local RemoveUGCDependencyResult_t = {}

---@param table table?
---@return RemoveUGCDependencyResult_t
function Steam.newRemoveUGCDependencyResult_t(table) end

---@class AddAppDependencyResult_t
---@field m_eResult integer
---@field m_nPublishedFileId uint64
---@field m_nAppID integer
local AddAppDependencyResult_t = {}

---@param table table?
---@return AddAppDependencyResult_t
function Steam.newAddAppDependencyResult_t(table) end

---@class RemoveAppDependencyResult_t
---@field m_eResult integer
---@field m_nPublishedFileId uint64
---@field m_nAppID integer
local RemoveAppDependencyResult_t = {}

---@param table table?
---@return RemoveAppDependencyResult_t
function Steam.newRemoveAppDependencyResult_t(table) end

---@class GetAppDependenciesResult_t
---@field m_eResult integer
---@field m_nPublishedFileId uint64
---@field m_rgAppIDs integer[]
---@field m_nNumAppDependencies integer
---@field m_nTotalNumAppDependencies integer
local GetAppDependenciesResult_t = {}

---@param table table?
---@return GetAppDependenciesResult_t
function Steam.newGetAppDependenciesResult_t(table) end

---@class DeleteItemResult_t
---@field m_eResult integer
---@field m_nPublishedFileId uint64
local DeleteItemResult_t = {}

---@param table table?
---@return DeleteItemResult_t
function Steam.newDeleteItemResult_t(table) end

---@class UserSubscribedItemsListChanged_t
---@field m_nAppID integer
local UserSubscribedItemsListChanged_t = {}

---@param table table?
---@return UserSubscribedItemsListChanged_t
function Steam.newUserSubscribedItemsListChanged_t(table) end

---@class WorkshopEULAStatus_t
---@field m_eResult integer
---@field m_nAppID integer
---@field m_unVersion integer
---@field m_rtAction integer
---@field m_bAccepted boolean
---@field m_bNeedsAction boolean
local WorkshopEULAStatus_t = {}

---@param table table?
---@return WorkshopEULAStatus_t
function Steam.newWorkshopEULAStatus_t(table) end

---@class HTML_BrowserReady_t
---@field unBrowserHandle integer
local HTML_BrowserReady_t = {}

---@param table table?
---@return HTML_BrowserReady_t
function Steam.newHTML_BrowserReady_t(table) end

---@class HTML_NeedsPaint_t
---@field unBrowserHandle integer
---@field pBGRA string
---@field unWide integer
---@field unTall integer
---@field unUpdateX integer
---@field unUpdateY integer
---@field unUpdateWide integer
---@field unUpdateTall integer
---@field unScrollX integer
---@field unScrollY integer
---@field flPageScale number
---@field unPageSerial integer
local HTML_NeedsPaint_t = {}

---@param table table?
---@return HTML_NeedsPaint_t
function Steam.newHTML_NeedsPaint_t(table) end

---@class HTML_StartRequest_t
---@field unBrowserHandle integer
---@field pchURL string
---@field pchTarget string
---@field pchPostData string
---@field bIsRedirect boolean
local HTML_StartRequest_t = {}

---@param table table?
---@return HTML_StartRequest_t
function Steam.newHTML_StartRequest_t(table) end

---@class HTML_CloseBrowser_t
---@field unBrowserHandle integer
local HTML_CloseBrowser_t = {}

---@param table table?
---@return HTML_CloseBrowser_t
function Steam.newHTML_CloseBrowser_t(table) end

---@class HTML_URLChanged_t
---@field unBrowserHandle integer
---@field pchURL string
---@field pchPostData string
---@field bIsRedirect boolean
---@field pchPageTitle string
---@field bNewNavigation boolean
local HTML_URLChanged_t = {}

---@param table table?
---@return HTML_URLChanged_t
function Steam.newHTML_URLChanged_t(table) end

---@class HTML_FinishedRequest_t
---@field unBrowserHandle integer
---@field pchURL string
---@field pchPageTitle string
local HTML_FinishedRequest_t = {}

---@param table table?
---@return HTML_FinishedRequest_t
function Steam.newHTML_FinishedRequest_t(table) end

---@class HTML_OpenLinkInNewTab_t
---@field unBrowserHandle integer
---@field pchURL string
local HTML_OpenLinkInNewTab_t = {}

---@param table table?
---@return HTML_OpenLinkInNewTab_t
function Steam.newHTML_OpenLinkInNewTab_t(table) end

---@class HTML_ChangedTitle_t
---@field unBrowserHandle integer
---@field pchTitle string
local HTML_ChangedTitle_t = {}

---@param table table?
---@return HTML_ChangedTitle_t
function Steam.newHTML_ChangedTitle_t(table) end

---@class HTML_SearchResults_t
---@field unBrowserHandle integer
---@field unResults integer
---@field unCurrentMatch integer
local HTML_SearchResults_t = {}

---@param table table?
---@return HTML_SearchResults_t
function Steam.newHTML_SearchResults_t(table) end

---@class HTML_CanGoBackAndForward_t
---@field unBrowserHandle integer
---@field bCanGoBack boolean
---@field bCanGoForward boolean
local HTML_CanGoBackAndForward_t = {}

---@param table table?
---@return HTML_CanGoBackAndForward_t
function Steam.newHTML_CanGoBackAndForward_t(table) end

---@class HTML_HorizontalScroll_t
---@field unBrowserHandle integer
---@field unScrollMax integer
---@field unScrollCurrent integer
---@field flPageScale number
---@field bVisible boolean
---@field unPageSize integer
local HTML_HorizontalScroll_t = {}

---@param table table?
---@return HTML_HorizontalScroll_t
function Steam.newHTML_HorizontalScroll_t(table) end

---@class HTML_VerticalScroll_t
---@field unBrowserHandle integer
---@field unScrollMax integer
---@field unScrollCurrent integer
---@field flPageScale number
---@field bVisible boolean
---@field unPageSize integer
local HTML_VerticalScroll_t = {}

---@param table table?
---@return HTML_VerticalScroll_t
function Steam.newHTML_VerticalScroll_t(table) end

---@class HTML_LinkAtPosition_t
---@field unBrowserHandle integer
---@field x integer
---@field y integer
---@field pchURL string
---@field bInput boolean
---@field bLiveLink boolean
local HTML_LinkAtPosition_t = {}

---@param table table?
---@return HTML_LinkAtPosition_t
function Steam.newHTML_LinkAtPosition_t(table) end

---@class HTML_JSAlert_t
---@field unBrowserHandle integer
---@field pchMessage string
local HTML_JSAlert_t = {}

---@param table table?
---@return HTML_JSAlert_t
function Steam.newHTML_JSAlert_t(table) end

---@class HTML_JSConfirm_t
---@field unBrowserHandle integer
---@field pchMessage string
local HTML_JSConfirm_t = {}

---@param table table?
---@return HTML_JSConfirm_t
function Steam.newHTML_JSConfirm_t(table) end

---@class HTML_FileOpenDialog_t
---@field unBrowserHandle integer
---@field pchTitle string
---@field pchInitialFile string
local HTML_FileOpenDialog_t = {}

---@param table table?
---@return HTML_FileOpenDialog_t
function Steam.newHTML_FileOpenDialog_t(table) end

---@class HTML_NewWindow_t
---@field unBrowserHandle integer
---@field pchURL string
---@field unX integer
---@field unY integer
---@field unWide integer
---@field unTall integer
---@field unNewWindow_BrowserHandle_IGNORE integer
local HTML_NewWindow_t = {}

---@param table table?
---@return HTML_NewWindow_t
function Steam.newHTML_NewWindow_t(table) end

---@class HTML_SetCursor_t
---@field unBrowserHandle integer
---@field eMouseCursor integer
local HTML_SetCursor_t = {}

---@param table table?
---@return HTML_SetCursor_t
function Steam.newHTML_SetCursor_t(table) end

---@class HTML_StatusText_t
---@field unBrowserHandle integer
---@field pchMsg string
local HTML_StatusText_t = {}

---@param table table?
---@return HTML_StatusText_t
function Steam.newHTML_StatusText_t(table) end

---@class HTML_ShowToolTip_t
---@field unBrowserHandle integer
---@field pchMsg string
local HTML_ShowToolTip_t = {}

---@param table table?
---@return HTML_ShowToolTip_t
function Steam.newHTML_ShowToolTip_t(table) end

---@class HTML_UpdateToolTip_t
---@field unBrowserHandle integer
---@field pchMsg string
local HTML_UpdateToolTip_t = {}

---@param table table?
---@return HTML_UpdateToolTip_t
function Steam.newHTML_UpdateToolTip_t(table) end

---@class HTML_HideToolTip_t
---@field unBrowserHandle integer
local HTML_HideToolTip_t = {}

---@param table table?
---@return HTML_HideToolTip_t
function Steam.newHTML_HideToolTip_t(table) end

---@class HTML_BrowserRestarted_t
---@field unBrowserHandle integer
---@field unOldBrowserHandle integer
local HTML_BrowserRestarted_t = {}

---@param table table?
---@return HTML_BrowserRestarted_t
function Steam.newHTML_BrowserRestarted_t(table) end

---@class SteamInventoryResultReady_t
---@field m_handle integer
---@field m_result integer
local SteamInventoryResultReady_t = {}

---@param table table?
---@return SteamInventoryResultReady_t
function Steam.newSteamInventoryResultReady_t(table) end

---@class SteamInventoryFullUpdate_t
---@field m_handle integer
local SteamInventoryFullUpdate_t = {}

---@param table table?
---@return SteamInventoryFullUpdate_t
function Steam.newSteamInventoryFullUpdate_t(table) end

---@class SteamInventoryDefinitionUpdate_t
local SteamInventoryDefinitionUpdate_t = {}

---@param table table?
---@return SteamInventoryDefinitionUpdate_t
function Steam.newSteamInventoryDefinitionUpdate_t(table) end

---@class SteamInventoryEligiblePromoItemDefIDs_t
---@field m_result integer
---@field m_steamID uint64
---@field m_numEligiblePromoItemDefs integer
---@field m_bCachedData boolean
local SteamInventoryEligiblePromoItemDefIDs_t = {}

---@param table table?
---@return SteamInventoryEligiblePromoItemDefIDs_t
function Steam.newSteamInventoryEligiblePromoItemDefIDs_t(table) end

---@class SteamInventoryStartPurchaseResult_t
---@field m_result integer
---@field m_ulOrderID uint64
---@field m_ulTransID uint64
local SteamInventoryStartPurchaseResult_t = {}

---@param table table?
---@return SteamInventoryStartPurchaseResult_t
function Steam.newSteamInventoryStartPurchaseResult_t(table) end

---@class SteamInventoryRequestPricesResult_t
---@field m_result integer
---@field m_rgchCurrency string
local SteamInventoryRequestPricesResult_t = {}

---@param table table?
---@return SteamInventoryRequestPricesResult_t
function Steam.newSteamInventoryRequestPricesResult_t(table) end

---@class SteamTimelineGamePhaseRecordingExists_t
---@field m_rgchPhaseID string
---@field m_ulRecordingMS uint64
---@field m_ulLongestClipMS uint64
---@field m_unClipCount integer
---@field m_unScreenshotCount integer
local SteamTimelineGamePhaseRecordingExists_t = {}

---@param table table?
---@return SteamTimelineGamePhaseRecordingExists_t
function Steam.newSteamTimelineGamePhaseRecordingExists_t(table) end

---@class SteamTimelineEventRecordingExists_t
---@field m_ulEventID uint64
---@field m_bRecordingExists boolean
local SteamTimelineEventRecordingExists_t = {}

---@param table table?
---@return SteamTimelineEventRecordingExists_t
function Steam.newSteamTimelineEventRecordingExists_t(table) end

---@class GetVideoURLResult_t
---@field m_eResult integer
---@field m_unVideoAppID integer
---@field m_rgchURL string
local GetVideoURLResult_t = {}

---@param table table?
---@return GetVideoURLResult_t
function Steam.newGetVideoURLResult_t(table) end

---@class GetOPFSettingsResult_t
---@field m_eResult integer
---@field m_unVideoAppID integer
local GetOPFSettingsResult_t = {}

---@param table table?
---@return GetOPFSettingsResult_t
function Steam.newGetOPFSettingsResult_t(table) end

---@class BroadcastUploadStart_t
---@field m_bIsRTMP boolean
local BroadcastUploadStart_t = {}

---@param table table?
---@return BroadcastUploadStart_t
function Steam.newBroadcastUploadStart_t(table) end

---@class BroadcastUploadStop_t
---@field m_eResult integer
local BroadcastUploadStop_t = {}

---@param table table?
---@return BroadcastUploadStop_t
function Steam.newBroadcastUploadStop_t(table) end

---@class SteamParentalSettingsChanged_t
local SteamParentalSettingsChanged_t = {}

---@param table table?
---@return SteamParentalSettingsChanged_t
function Steam.newSteamParentalSettingsChanged_t(table) end

---@class SteamRemotePlaySessionConnected_t
---@field m_unSessionID integer
local SteamRemotePlaySessionConnected_t = {}

---@param table table?
---@return SteamRemotePlaySessionConnected_t
function Steam.newSteamRemotePlaySessionConnected_t(table) end

---@class SteamRemotePlaySessionDisconnected_t
---@field m_unSessionID integer
local SteamRemotePlaySessionDisconnected_t = {}

---@param table table?
---@return SteamRemotePlaySessionDisconnected_t
function Steam.newSteamRemotePlaySessionDisconnected_t(table) end

---@class SteamRemotePlayTogetherGuestInvite_t
---@field m_szConnectURL string
local SteamRemotePlayTogetherGuestInvite_t = {}

---@param table table?
---@return SteamRemotePlayTogetherGuestInvite_t
function Steam.newSteamRemotePlayTogetherGuestInvite_t(table) end

---@class SteamNetworkingMessagesSessionRequest_t
---@field m_identityRemote SteamNetworkingIdentity
local SteamNetworkingMessagesSessionRequest_t = {}

---@param table table?
---@return SteamNetworkingMessagesSessionRequest_t
function Steam.newSteamNetworkingMessagesSessionRequest_t(table) end

---@class SteamNetworkingMessagesSessionFailed_t
---@field m_info SteamNetConnectionInfo_t
local SteamNetworkingMessagesSessionFailed_t = {}

---@param table table?
---@return SteamNetworkingMessagesSessionFailed_t
function Steam.newSteamNetworkingMessagesSessionFailed_t(table) end

---@class SteamNetConnectionStatusChangedCallback_t
---@field m_hConn integer
---@field m_info SteamNetConnectionInfo_t
---@field m_eOldState integer
local SteamNetConnectionStatusChangedCallback_t = {}

---@param table table?
---@return SteamNetConnectionStatusChangedCallback_t
function Steam.newSteamNetConnectionStatusChangedCallback_t(table) end

---@class SteamNetAuthenticationStatus_t
---@field m_eAvail integer
---@field m_debugMsg string
local SteamNetAuthenticationStatus_t = {}

---@param table table?
---@return SteamNetAuthenticationStatus_t
function Steam.newSteamNetAuthenticationStatus_t(table) end

---@class SteamRelayNetworkStatus_t
---@field m_eAvail integer
---@field m_bPingMeasurementInProgress integer
---@field m_eAvailNetworkConfig integer
---@field m_eAvailAnyRelay integer
---@field m_debugMsg string
local SteamRelayNetworkStatus_t = {}

---@param table table?
---@return SteamRelayNetworkStatus_t
function Steam.newSteamRelayNetworkStatus_t(table) end

---@class GSClientApprove_t
---@field m_SteamID uint64
---@field m_OwnerSteamID uint64
local GSClientApprove_t = {}

---@param table table?
---@return GSClientApprove_t
function Steam.newGSClientApprove_t(table) end

---@class GSClientDeny_t
---@field m_SteamID uint64
---@field m_eDenyReason integer
---@field m_rgchOptionalText string
local GSClientDeny_t = {}

---@param table table?
---@return GSClientDeny_t
function Steam.newGSClientDeny_t(table) end

---@class GSClientKick_t
---@field m_SteamID uint64
---@field m_eDenyReason integer
local GSClientKick_t = {}

---@param table table?
---@return GSClientKick_t
function Steam.newGSClientKick_t(table) end

---@class GSClientAchievementStatus_t
---@field m_SteamID uint64
---@field m_pchAchievement string
---@field m_bUnlocked boolean
local GSClientAchievementStatus_t = {}

---@param table table?
---@return GSClientAchievementStatus_t
function Steam.newGSClientAchievementStatus_t(table) end

---@class GSPolicyResponse_t
---@field m_bSecure integer
local GSPolicyResponse_t = {}

---@param table table?
---@return GSPolicyResponse_t
function Steam.newGSPolicyResponse_t(table) end

---@class GSGameplayStats_t
---@field m_eResult integer
---@field m_nRank integer
---@field m_unTotalConnects integer
---@field m_unTotalMinutesPlayed integer
local GSGameplayStats_t = {}

---@param table table?
---@return GSGameplayStats_t
function Steam.newGSGameplayStats_t(table) end

---@class GSClientGroupStatus_t
---@field m_SteamIDUser uint64
---@field m_SteamIDGroup uint64
---@field m_bMember boolean
---@field m_bOfficer boolean
local GSClientGroupStatus_t = {}

---@param table table?
---@return GSClientGroupStatus_t
function Steam.newGSClientGroupStatus_t(table) end

---@class GSReputation_t
---@field m_eResult integer
---@field m_unReputationScore integer
---@field m_bBanned boolean
---@field m_unBannedIP integer
---@field m_usBannedPort integer
---@field m_ulBannedGameID uint64
---@field m_unBanExpires integer
local GSReputation_t = {}

---@param table table?
---@return GSReputation_t
function Steam.newGSReputation_t(table) end

---@class AssociateWithClanResult_t
---@field m_eResult integer
local AssociateWithClanResult_t = {}

---@param table table?
---@return AssociateWithClanResult_t
function Steam.newAssociateWithClanResult_t(table) end

---@class ComputeNewPlayerCompatibilityResult_t
---@field m_eResult integer
---@field m_cPlayersThatDontLikeCandidate integer
---@field m_cPlayersThatCandidateDoesntLike integer
---@field m_cClanPlayersThatDontLikeCandidate integer
---@field m_SteamIDCandidate uint64
local ComputeNewPlayerCompatibilityResult_t = {}

---@param table table?
---@return ComputeNewPlayerCompatibilityResult_t
function Steam.newComputeNewPlayerCompatibilityResult_t(table) end

---@class GSStatsReceived_t
---@field m_eResult integer
---@field m_steamIDUser uint64
local GSStatsReceived_t = {}

---@param table table?
---@return GSStatsReceived_t
function Steam.newGSStatsReceived_t(table) end

---@class GSStatsStored_t
---@field m_eResult integer
---@field m_steamIDUser uint64
local GSStatsStored_t = {}

---@param table table?
---@return GSStatsStored_t
function Steam.newGSStatsStored_t(table) end

---@class GSStatsUnloaded_t
---@field m_steamIDUser uint64
local GSStatsUnloaded_t = {}

---@param table table?
---@return GSStatsUnloaded_t
function Steam.newGSStatsUnloaded_t(table) end

---@class SteamNetworkingFakeIPResult_t
---@field m_eResult integer
---@field m_identity SteamNetworkingIdentity
---@field m_unIP integer
---@field m_unPorts integer[]
local SteamNetworkingFakeIPResult_t = {}

---@param table table?
---@return SteamNetworkingFakeIPResult_t
function Steam.newSteamNetworkingFakeIPResult_t(table) end

