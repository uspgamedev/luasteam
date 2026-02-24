---@class Steam.MatchmakingServers
local MatchmakingServers = {}

---@param iApp integer
---@param ppchFilters MatchMakingKeyValuePair_t[]
---@param pRequestServersResponse ISteamMatchmakingServerListResponse
---@return HServerListRequest
function MatchmakingServers.RequestInternetServerList(iApp, ppchFilters, pRequestServersResponse) end

---@param iApp integer
---@param pRequestServersResponse ISteamMatchmakingServerListResponse
---@return HServerListRequest
function MatchmakingServers.RequestLANServerList(iApp, pRequestServersResponse) end

---@param iApp integer
---@param ppchFilters MatchMakingKeyValuePair_t[]
---@param pRequestServersResponse ISteamMatchmakingServerListResponse
---@return HServerListRequest
function MatchmakingServers.RequestFriendsServerList(iApp, ppchFilters, pRequestServersResponse) end

---@param iApp integer
---@param ppchFilters MatchMakingKeyValuePair_t[]
---@param pRequestServersResponse ISteamMatchmakingServerListResponse
---@return HServerListRequest
function MatchmakingServers.RequestFavoritesServerList(iApp, ppchFilters, pRequestServersResponse) end

---@param iApp integer
---@param ppchFilters MatchMakingKeyValuePair_t[]
---@param pRequestServersResponse ISteamMatchmakingServerListResponse
---@return HServerListRequest
function MatchmakingServers.RequestHistoryServerList(iApp, ppchFilters, pRequestServersResponse) end

---@param iApp integer
---@param ppchFilters MatchMakingKeyValuePair_t[]
---@param pRequestServersResponse ISteamMatchmakingServerListResponse
---@return HServerListRequest
function MatchmakingServers.RequestSpectatorServerList(iApp, ppchFilters, pRequestServersResponse) end

---@param hServerListRequest HServerListRequest
function MatchmakingServers.ReleaseRequest(hServerListRequest) end

---@param hRequest HServerListRequest
function MatchmakingServers.CancelQuery(hRequest) end

---@param hRequest HServerListRequest
function MatchmakingServers.RefreshQuery(hRequest) end

---@param hRequest HServerListRequest
---@return boolean
function MatchmakingServers.IsRefreshing(hRequest) end

---@param hRequest HServerListRequest
---@return integer
function MatchmakingServers.GetServerCount(hRequest) end

---@param hRequest HServerListRequest
---@param iServer integer
function MatchmakingServers.RefreshServer(hRequest, iServer) end

---@param unIP integer
---@param usPort integer
---@param pRequestServersResponse ISteamMatchmakingPingResponse
---@return integer
function MatchmakingServers.PingServer(unIP, usPort, pRequestServersResponse) end

---@param unIP integer
---@param usPort integer
---@param pRequestServersResponse ISteamMatchmakingPlayersResponse
---@return integer
function MatchmakingServers.PlayerDetails(unIP, usPort, pRequestServersResponse) end

---@param unIP integer
---@param usPort integer
---@param pRequestServersResponse ISteamMatchmakingRulesResponse
---@return integer
function MatchmakingServers.ServerRules(unIP, usPort, pRequestServersResponse) end

---@param hServerQuery integer
function MatchmakingServers.CancelServerQuery(hServerQuery) end

Steam.MatchmakingServers = MatchmakingServers
