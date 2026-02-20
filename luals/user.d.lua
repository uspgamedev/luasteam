---@class Steam.User
local User = {}

---@return integer
function User.GetHSteamUser() end

---@return boolean
function User.BLoggedOn() end

---@return uint64
function User.GetSteamID() end

---@param gameID uint64
---@param eAppUsageEvent integer
---@param pchExtraInfo string
function User.TrackAppUsageEvent(gameID, eAppUsageEvent, pchExtraInfo) end

---@param pchBuffer string
---@param cubBuffer integer
---@return boolean
function User.GetUserDataFolder(pchBuffer, cubBuffer) end

function User.StartVoiceRecording() end

function User.StopVoiceRecording() end

---@return integer
---@return integer
function User.GetAvailableVoice() end

---@param bWantCompressed boolean
---@param pDestBuffer table
---@param cbDestBufferSize integer
---@return integer
---@return integer
function User.GetVoice(bWantCompressed, pDestBuffer, cbDestBufferSize) end

---@param pCompressed table
---@param cbCompressed integer
---@param pDestBuffer table
---@param cbDestBufferSize integer
---@param nDesiredSampleRate integer
---@return integer
---@return integer
function User.DecompressVoice(pCompressed, cbCompressed, pDestBuffer, cbDestBufferSize, nDesiredSampleRate) end

---@return integer
function User.GetVoiceOptimalSampleRate() end

---@param pchIdentity string
---@return integer
function User.GetAuthTicketForWebApi(pchIdentity) end

---@param pAuthTicket table
---@param cbAuthTicket integer
---@param steamID uint64
---@return integer
function User.BeginAuthSession(pAuthTicket, cbAuthTicket, steamID) end

---@param steamID uint64
function User.EndAuthSession(steamID) end

---@param hAuthTicket integer
function User.CancelAuthTicket(hAuthTicket) end

---@param steamID uint64
---@param appID integer
---@return integer
function User.UserHasLicenseForApp(steamID, appID) end

---@return boolean
function User.BIsBehindNAT() end

---@param steamIDGameServer uint64
---@param unIPServer integer
---@param usPortServer integer
function User.AdvertiseGame(steamIDGameServer, unIPServer, usPortServer) end

---@param pDataToInclude table
---@param cbDataToInclude integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function User.RequestEncryptedAppTicket(pDataToInclude, cbDataToInclude, callback) end

---@param pTicket table
---@param cbMaxTicket integer
---@return boolean
---@return integer
function User.GetEncryptedAppTicket(pTicket, cbMaxTicket) end

---@param nSeries integer
---@param bFoil boolean
---@return integer
function User.GetGameBadgeLevel(nSeries, bFoil) end

---@return integer
function User.GetPlayerSteamLevel() end

---@param pchRedirectURL string
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
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
---@return SteamAPICall_t
function User.GetMarketEligibility(callback) end

---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function User.GetDurationControl(callback) end

---@param eNewState integer
---@return boolean
function User.BSetDurationControlOnlineState(eNewState) end

Steam.User = User
