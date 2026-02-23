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

---@param cubBuffer integer
---@return boolean
---@return string -- Value of: pchBuffer
function User.GetUserDataFolder(cubBuffer) end

function User.StartVoiceRecording() end

function User.StopVoiceRecording() end

---@return integer
---@return integer -- Value of: pcbCompressed
function User.GetAvailableVoice() end

---@param bWantCompressed boolean
---@param cbDestBufferSize integer
---@return integer
---@return string -- Value of: pDestBuffer
---@return integer -- Value of: nBytesWritten
function User.GetVoice(bWantCompressed, cbDestBufferSize) end

---@param pCompressed string
---@param cbCompressed integer
---@param cbDestBufferSize integer
---@param nDesiredSampleRate integer
---@return integer
---@return string -- Value of: pDestBuffer
---@return integer -- Value of: nBytesWritten
function User.DecompressVoice(pCompressed, cbCompressed, cbDestBufferSize, nDesiredSampleRate) end

---@return integer
function User.GetVoiceOptimalSampleRate() end

---@param cbMaxTicket integer
---@param pSteamNetworkingIdentity SteamNetworkingIdentity
---@return integer
---@return string -- Value of: pTicket
---@return integer -- Value of: pcbTicket
function User.GetAuthSessionTicket(cbMaxTicket, pSteamNetworkingIdentity) end

---@param pchIdentity string
---@return integer
function User.GetAuthTicketForWebApi(pchIdentity) end

---@param pAuthTicket string
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

---@param pDataToInclude string
---@param cbDataToInclude integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function User.RequestEncryptedAppTicket(pDataToInclude, cbDataToInclude, callback) end

---@param cbMaxTicket integer
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

---@param pchRedirectURL string
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
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
---@return uint64
function User.GetMarketEligibility(callback) end

---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function User.GetDurationControl(callback) end

---@param eNewState integer
---@return boolean
function User.BSetDurationControlOnlineState(eNewState) end

Steam.User = User
