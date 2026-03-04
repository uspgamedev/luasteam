---@class Steam.User
---@field OnSteamServersConnected? fun(data: SteamServersConnected_t)
---@field OnSteamServerConnectFailure? fun(data: SteamServerConnectFailure_t)
---@field OnSteamServersDisconnected? fun(data: SteamServersDisconnected_t)
---@field OnClientGameServerDeny? fun(data: ClientGameServerDeny_t)
---@field OnIPCFailure? fun(data: IPCFailure_t)
---@field OnLicensesUpdated? fun(data: LicensesUpdated_t)
---@field OnValidateAuthTicketResponse? fun(data: ValidateAuthTicketResponse_t)
---@field OnMicroTxnAuthorizationResponse? fun(data: MicroTxnAuthorizationResponse_t)
---@field OnEncryptedAppTicketResponse? fun(data: EncryptedAppTicketResponse_t)
---@field OnGetAuthSessionTicketResponse? fun(data: GetAuthSessionTicketResponse_t)
---@field OnGameWebCallback? fun(data: GameWebCallback_t)
---@field OnStoreAuthURLResponse? fun(data: StoreAuthURLResponse_t)
---@field OnMarketEligibilityResponse? fun(data: MarketEligibilityResponse_t)
---@field OnDurationControl? fun(data: DurationControl_t)
---@field OnGetTicketForWebApiResponse? fun(data: GetTicketForWebApiResponse_t)
---@field OnGSPolicyResponse? fun(data: GSPolicyResponse_t)
local User = {}

---@return integer -- HSteamUser
function User.GetHSteamUser() end

---@return boolean
function User.BLoggedOn() end

---@return uint64 -- CSteamID
function User.GetSteamID() end

---@param gameID uint64 -- CGameID
---@param eAppUsageEvent integer
---@param pchExtraInfo string?
function User.TrackAppUsageEvent(gameID, eAppUsageEvent, pchExtraInfo) end

---@param cubBuffer integer? size of the buffer for pchBuffer; if nil then the buffer will be NULL
---@return boolean
---@return string -- Value of: pchBuffer
function User.GetUserDataFolder(cubBuffer) end

function User.StartVoiceRecording() end

function User.StopVoiceRecording() end

---@return integer -- EVoiceResult
---@return integer -- Value of: pcbCompressed
function User.GetAvailableVoice() end

---@param bWantCompressed boolean
---@param cbDestBufferSize integer? size of the buffer for pDestBuffer; if nil then the buffer will be NULL
---@return integer -- EVoiceResult
---@return string -- Value of: pDestBuffer
---@return integer -- Value of: nBytesWritten
function User.GetVoice(bWantCompressed, cbDestBufferSize) end

---@param pCompressed string?
---@param cbCompressed integer size of the input array pCompressed
---@param cbDestBufferSize integer? size of the buffer for pDestBuffer; if nil then the buffer will be NULL
---@param nDesiredSampleRate integer
---@return integer -- EVoiceResult
---@return string -- Value of: pDestBuffer
---@return integer -- Value of: nBytesWritten
function User.DecompressVoice(pCompressed, cbCompressed, cbDestBufferSize, nDesiredSampleRate) end

---@return integer
function User.GetVoiceOptimalSampleRate() end

---@param cbMaxTicket integer? size of the buffer for pTicket; if nil then the buffer will be NULL
---@param pSteamNetworkingIdentity SteamNetworkingIdentity
---@return integer -- HAuthTicket
---@return string -- Value of: pTicket
---@return integer -- Value of: pcbTicket
function User.GetAuthSessionTicket(cbMaxTicket, pSteamNetworkingIdentity) end

---@param pchIdentity string?
---@return integer -- HAuthTicket
function User.GetAuthTicketForWebApi(pchIdentity) end

---@param pAuthTicket string?
---@param cbAuthTicket integer size of the input array pAuthTicket
---@param steamID uint64 -- CSteamID
---@return integer -- EBeginAuthSessionResult
function User.BeginAuthSession(pAuthTicket, cbAuthTicket, steamID) end

---@param steamID uint64 -- CSteamID
function User.EndAuthSession(steamID) end

---@param hAuthTicket integer -- HAuthTicket
function User.CancelAuthTicket(hAuthTicket) end

---@param steamID uint64 -- CSteamID
---@param appID integer -- AppId_t
---@return integer -- EUserHasLicenseForAppResult
function User.UserHasLicenseForApp(steamID, appID) end

---@return boolean
function User.BIsBehindNAT() end

---@param steamIDGameServer uint64 -- CSteamID
---@param unIPServer integer
---@param usPortServer integer
function User.AdvertiseGame(steamIDGameServer, unIPServer, usPortServer) end

---@param pDataToInclude string?
---@param cbDataToInclude integer size of the input array pDataToInclude
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function User.RequestEncryptedAppTicket(pDataToInclude, cbDataToInclude, callback) end

---@param cbMaxTicket integer? size of the buffer for pTicket; if nil then the buffer will be NULL
---@return boolean
---@return string -- Value of: pTicket
---@return integer -- Value of: pcbTicket
function User.GetEncryptedAppTicket(cbMaxTicket) end

---@param nSeries integer
---@param bFoil boolean
---@return integer
function User.GetGameBadgeLevel(nSeries, bFoil) end

---@return integer
function User.GetPlayerSteamLevel() end

---@param pchRedirectURL string?
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function User.RequestStoreAuthURL(pchRedirectURL, callback) end

---@return boolean
function User.BIsPhoneVerified() end

---@return boolean
function User.BIsTwoFactorEnabled() end

---@return boolean
function User.BIsPhoneIdentifying() end

---@return boolean
function User.BIsPhoneRequiringVerification() end

---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function User.GetMarketEligibility(callback) end

---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function User.GetDurationControl(callback) end

---@param eNewState integer -- EDurationControlOnlineState
---@return boolean
function User.BSetDurationControlOnlineState(eNewState) end

Steam.User = User
