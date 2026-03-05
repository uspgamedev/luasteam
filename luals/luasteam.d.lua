---@alias uint64 userdata
---@alias SteamAPICall_t userdata
---@alias HServerListRequest userdata

---@class Steam
Steam = {}

---@return boolean
function Steam.Init() end

function Steam.Shutdown() end

function Steam.RunCallbacks() end

---@param unIP integer
---@param usGamePort integer
---@param usQueryPort integer
---@param eServerMode integer
---@param pchVersionString string
---@return boolean
function Steam.GameServerInit(unIP, usGamePort, usQueryPort, eServerMode, pchVersionString) end

function Steam.GameServerShutdown() end

function Steam.GameServerRunCallbacks() end

Steam.Extra = {}

Steam.Client = {}
Steam.User = {}
Steam.Friends = {}
Steam.Utils = {}
Steam.Matchmaking = {}
Steam.MatchmakingServers = {}
Steam.Parties = {}
Steam.RemoteStorage = {}
Steam.UserStats = {}
Steam.Apps = {}
Steam.Networking = {}
Steam.Screenshots = {}
Steam.Music = {}
Steam.HTTP = {}
Steam.Input = {}
Steam.Controller = {}
Steam.UGC = {}
Steam.HTMLSurface = {}
Steam.Inventory = {}
Steam.Timeline = {}
Steam.Video = {}
Steam.ParentalSettings = {}
Steam.RemotePlay = {}
Steam.NetworkingMessages = {}
Steam.NetworkingSockets = {}
Steam.NetworkingUtils = {}
Steam.GameServer = {}
Steam.GameServerStats = {}
Steam.GameServerClient = {}
Steam.GameServerUtils = {}
Steam.GameServerNetworking = {}
Steam.GameServerHTTP = {}
Steam.GameServerUGC = {}
Steam.GameServerInventory = {}
Steam.GameServerNetworkingMessages = {}
Steam.GameServerNetworkingSockets = {}
