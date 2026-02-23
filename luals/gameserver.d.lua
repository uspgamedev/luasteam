---@class Steam.GameServer
local GameServer = {}

---@param pszProduct string
function GameServer.SetProduct(pszProduct) end

---@param pszGameDescription string
function GameServer.SetGameDescription(pszGameDescription) end

---@param pszModDir string
function GameServer.SetModDir(pszModDir) end

---@param bDedicated boolean
function GameServer.SetDedicatedServer(bDedicated) end

---@param pszToken string
function GameServer.LogOn(pszToken) end

function GameServer.LogOnAnonymous() end

function GameServer.LogOff() end

---@return boolean
function GameServer.BLoggedOn() end

---@return boolean
function GameServer.BSecure() end

---@return uint64
function GameServer.GetSteamID() end

---@return boolean
function GameServer.WasRestartRequested() end

---@param cPlayersMax integer
function GameServer.SetMaxPlayerCount(cPlayersMax) end

---@param cBotplayers integer
function GameServer.SetBotPlayerCount(cBotplayers) end

---@param pszServerName string
function GameServer.SetServerName(pszServerName) end

---@param pszMapName string
function GameServer.SetMapName(pszMapName) end

---@param bPasswordProtected boolean
function GameServer.SetPasswordProtected(bPasswordProtected) end

---@param unSpectatorPort integer
function GameServer.SetSpectatorPort(unSpectatorPort) end

---@param pszSpectatorServerName string
function GameServer.SetSpectatorServerName(pszSpectatorServerName) end

function GameServer.ClearAllKeyValues() end

---@param pKey string
---@param pValue string
function GameServer.SetKeyValue(pKey, pValue) end

---@param pchGameTags string
function GameServer.SetGameTags(pchGameTags) end

---@param pchGameData string
function GameServer.SetGameData(pchGameData) end

---@param pszRegion string
function GameServer.SetRegion(pszRegion) end

---@param bActive boolean
function GameServer.SetAdvertiseServerActive(bActive) end

---@param cbMaxTicket integer
---@param pSnid SteamNetworkingIdentity
---@return integer
---@return string -- Value of: pTicket
---@return integer -- Value of: pcbTicket
function GameServer.GetAuthSessionTicket(cbMaxTicket, pSnid) end

---@param pAuthTicket string
---@param cbAuthTicket integer
---@param steamID uint64
---@return integer
function GameServer.BeginAuthSession(pAuthTicket, cbAuthTicket, steamID) end

---@param steamID uint64
function GameServer.EndAuthSession(steamID) end

---@param hAuthTicket integer
function GameServer.CancelAuthTicket(hAuthTicket) end

---@param steamID uint64
---@param appID integer
---@return integer
function GameServer.UserHasLicenseForApp(steamID, appID) end

---@param steamIDUser uint64
---@param steamIDGroup uint64
---@return boolean
function GameServer.RequestUserGroupStatus(steamIDUser, steamIDGroup) end

function GameServer.GetGameplayStats() end

---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function GameServer.GetServerReputation(callback) end

---@return table
function GameServer.GetPublicIP() end

---@param pData string
---@param cbData integer
---@param srcIP integer
---@param srcPort integer
---@return boolean
function GameServer.HandleIncomingPacket(pData, cbData, srcIP, srcPort) end

---@param cbMaxOut integer
---@return integer
---@return string -- Value of: pOut
---@return integer -- Value of: pNetAdr
---@return integer -- Value of: pPort
function GameServer.GetNextOutgoingPacket(cbMaxOut) end

---@param steamIDClan uint64
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function GameServer.AssociateWithClan(steamIDClan, callback) end

---@param steamIDNewPlayer uint64
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function GameServer.ComputeNewPlayerCompatibility(steamIDNewPlayer, callback) end

---@return uint64
function GameServer.CreateUnauthenticatedUserConnection() end

---@param steamIDUser uint64
---@param pchPlayerName string
---@param uScore integer
---@return boolean
function GameServer.BUpdateUserData(steamIDUser, pchPlayerName, uScore) end

Steam.GameServer = GameServer
