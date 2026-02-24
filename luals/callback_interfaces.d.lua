---@class ISteamMatchmakingServerListResponse
---@field ServerResponded fun(hRequest: HServerListRequest, iServer: integer)
---@field ServerFailedToRespond fun(hRequest: HServerListRequest, iServer: integer)
---@field RefreshComplete fun(hRequest: HServerListRequest, response: integer)
local ISteamMatchmakingServerListResponse = {}

---@param callbacks ISteamMatchmakingServerListResponse
---@return ISteamMatchmakingServerListResponse
function Steam.newISteamMatchmakingServerListResponse(callbacks) end

---@class ISteamMatchmakingPingResponse
---@field ServerResponded fun(server: gameserveritem_t)
---@field ServerFailedToRespond fun()
local ISteamMatchmakingPingResponse = {}

---@param callbacks ISteamMatchmakingPingResponse
---@return ISteamMatchmakingPingResponse
function Steam.newISteamMatchmakingPingResponse(callbacks) end

---@class ISteamMatchmakingPlayersResponse
---@field AddPlayerToList fun(pchName: string, nScore: integer, flTimePlayed: number)
---@field PlayersFailedToRespond fun()
---@field PlayersRefreshComplete fun()
local ISteamMatchmakingPlayersResponse = {}

---@param callbacks ISteamMatchmakingPlayersResponse
---@return ISteamMatchmakingPlayersResponse
function Steam.newISteamMatchmakingPlayersResponse(callbacks) end

---@class ISteamMatchmakingRulesResponse
---@field RulesResponded fun(pchRule: string, pchValue: string)
---@field RulesFailedToRespond fun()
---@field RulesRefreshComplete fun()
local ISteamMatchmakingRulesResponse = {}

---@param callbacks ISteamMatchmakingRulesResponse
---@return ISteamMatchmakingRulesResponse
function Steam.newISteamMatchmakingRulesResponse(callbacks) end

