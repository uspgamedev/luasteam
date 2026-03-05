---@class Steam.Client
local Client = {}

---@param hook fun(severity: integer, message: string)?
function Client.SetWarningMessageHook(hook) end

---@return integer -- HSteamPipe
function Client.CreateSteamPipe() end

---@param hSteamPipe integer -- HSteamPipe
---@return boolean
function Client.BReleaseSteamPipe(hSteamPipe) end

---@param hSteamPipe integer -- HSteamPipe
---@return integer -- HSteamUser
function Client.ConnectToGlobalUser(hSteamPipe) end

---@param eAccountType integer -- EAccountType
---@return integer -- HSteamUser
---@return integer -- Value of: phSteamPipe
function Client.CreateLocalUser(eAccountType) end

---@param hSteamPipe integer -- HSteamPipe
---@param hUser integer -- HSteamUser
function Client.ReleaseUser(hSteamPipe, hUser) end

---@param unIP SteamIPAddress_t
---@param usPort integer
function Client.SetLocalIPBinding(unIP, usPort) end

---@return integer
function Client.GetIPCCallCount() end

---@return boolean
function Client.BShutdownIfAllPipesClosed() end

Steam.Client = Client
Steam.GameServerClient = Client
