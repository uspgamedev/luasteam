---@class Steam.Client
local Client = {}

---@return integer
function Client.CreateSteamPipe() end

---@param hSteamPipe integer
---@return boolean
function Client.BReleaseSteamPipe(hSteamPipe) end

---@param hSteamPipe integer
---@return integer
function Client.ConnectToGlobalUser(hSteamPipe) end

---@param eAccountType integer
---@return integer
---@return integer -- Value of: phSteamPipe
function Client.CreateLocalUser(eAccountType) end

---@param hSteamPipe integer
---@param hUser integer
function Client.ReleaseUser(hSteamPipe, hUser) end

---@param unIP SteamIPAddress_t
---@param usPort integer
function Client.SetLocalIPBinding(unIP, usPort) end

---@param hSteamUser integer
---@param hSteamPipe integer
---@param pchVersion string
---@return string
function Client.GetISteamGenericInterface(hSteamUser, hSteamPipe, pchVersion) end

---@return integer
function Client.GetIPCCallCount() end

---@return boolean
function Client.BShutdownIfAllPipesClosed() end

Steam.Client = Client
