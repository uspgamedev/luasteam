---@class Steam.NetworkingMessages
local NetworkingMessages = {}

---@param identityRemote SteamNetworkingIdentity
---@return boolean
function NetworkingMessages.AcceptSessionWithUser(identityRemote) end

---@param identityRemote SteamNetworkingIdentity
---@return boolean
function NetworkingMessages.CloseSessionWithUser(identityRemote) end

---@param identityRemote SteamNetworkingIdentity
---@param nLocalChannel integer
---@return boolean
function NetworkingMessages.CloseChannelWithUser(identityRemote, nLocalChannel) end

---@param identityRemote SteamNetworkingIdentity
---@return integer
---@return SteamNetConnectionInfo_t -- Value of: pConnectionInfo
---@return SteamNetConnectionRealTimeStatus_t -- Value of: pQuickStatus
function NetworkingMessages.GetSessionConnectionInfo(identityRemote) end

Steam.NetworkingMessages = NetworkingMessages
