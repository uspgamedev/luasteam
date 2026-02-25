#include "auto.hpp"

namespace luasteam {

int MatchmakingServers_ref = LUA_NOREF;

void init_MatchmakingServers_auto(lua_State *L) {}
void shutdown_MatchmakingServers_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, MatchmakingServers_ref);
	MatchmakingServers_ref = LUA_NOREF;
}

// In C++:
// HServerListRequest RequestInternetServerList(AppId_t iApp, MatchMakingKeyValuePair_t ** ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse * pRequestServersResponse);
// In Lua:
// HServerListRequest MatchmakingServers.RequestInternetServerList(iApp: int, ppchFilters: MatchMakingKeyValuePair_t[], pRequestServersResponse: ISteamMatchmakingServerListResponse)
static int luasteam_MatchmakingServers_RequestInternetServerList(lua_State *L) {
	auto *iface = SteamMatchmakingServers();
	AppId_t iApp = static_cast<AppId_t>(luaL_checkint(L, 1));
	int nFilters = (int)lua_objlen(L, 2);
	std::vector<MatchMakingKeyValuePair_t *> ppchFilters_vec(nFilters);
	for (int _i = 0; _i < nFilters; _i++) {
		lua_rawgeti(L, 2, _i + 1);
		ppchFilters_vec[_i] = luasteam::check_MatchMakingKeyValuePair_t_ptr(L, -1);
		lua_pop(L, 1);
	}
	MatchMakingKeyValuePair_t **ppchFilters = ppchFilters_vec.data();
	ISteamMatchmakingServerListResponse *pRequestServersResponse = luasteam::check_ISteamMatchmakingServerListResponse(L, 3);
	HServerListRequest __ret = iface->RequestInternetServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
	lua_pushlightuserdata(L, (void*)__ret);
	return 1;
}

// In C++:
// HServerListRequest RequestLANServerList(AppId_t iApp, ISteamMatchmakingServerListResponse * pRequestServersResponse);
// In Lua:
// HServerListRequest MatchmakingServers.RequestLANServerList(iApp: int, pRequestServersResponse: ISteamMatchmakingServerListResponse)
static int luasteam_MatchmakingServers_RequestLANServerList(lua_State *L) {
	auto *iface = SteamMatchmakingServers();
	AppId_t iApp = static_cast<AppId_t>(luaL_checkint(L, 1));
	ISteamMatchmakingServerListResponse *pRequestServersResponse = luasteam::check_ISteamMatchmakingServerListResponse(L, 2);
	HServerListRequest __ret = iface->RequestLANServerList(iApp, pRequestServersResponse);
	lua_pushlightuserdata(L, (void*)__ret);
	return 1;
}

// In C++:
// HServerListRequest RequestFriendsServerList(AppId_t iApp, MatchMakingKeyValuePair_t ** ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse * pRequestServersResponse);
// In Lua:
// HServerListRequest MatchmakingServers.RequestFriendsServerList(iApp: int, ppchFilters: MatchMakingKeyValuePair_t[], pRequestServersResponse: ISteamMatchmakingServerListResponse)
static int luasteam_MatchmakingServers_RequestFriendsServerList(lua_State *L) {
	auto *iface = SteamMatchmakingServers();
	AppId_t iApp = static_cast<AppId_t>(luaL_checkint(L, 1));
	int nFilters = (int)lua_objlen(L, 2);
	std::vector<MatchMakingKeyValuePair_t *> ppchFilters_vec(nFilters);
	for (int _i = 0; _i < nFilters; _i++) {
		lua_rawgeti(L, 2, _i + 1);
		ppchFilters_vec[_i] = luasteam::check_MatchMakingKeyValuePair_t_ptr(L, -1);
		lua_pop(L, 1);
	}
	MatchMakingKeyValuePair_t **ppchFilters = ppchFilters_vec.data();
	ISteamMatchmakingServerListResponse *pRequestServersResponse = luasteam::check_ISteamMatchmakingServerListResponse(L, 3);
	HServerListRequest __ret = iface->RequestFriendsServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
	lua_pushlightuserdata(L, (void*)__ret);
	return 1;
}

// In C++:
// HServerListRequest RequestFavoritesServerList(AppId_t iApp, MatchMakingKeyValuePair_t ** ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse * pRequestServersResponse);
// In Lua:
// HServerListRequest MatchmakingServers.RequestFavoritesServerList(iApp: int, ppchFilters: MatchMakingKeyValuePair_t[], pRequestServersResponse: ISteamMatchmakingServerListResponse)
static int luasteam_MatchmakingServers_RequestFavoritesServerList(lua_State *L) {
	auto *iface = SteamMatchmakingServers();
	AppId_t iApp = static_cast<AppId_t>(luaL_checkint(L, 1));
	int nFilters = (int)lua_objlen(L, 2);
	std::vector<MatchMakingKeyValuePair_t *> ppchFilters_vec(nFilters);
	for (int _i = 0; _i < nFilters; _i++) {
		lua_rawgeti(L, 2, _i + 1);
		ppchFilters_vec[_i] = luasteam::check_MatchMakingKeyValuePair_t_ptr(L, -1);
		lua_pop(L, 1);
	}
	MatchMakingKeyValuePair_t **ppchFilters = ppchFilters_vec.data();
	ISteamMatchmakingServerListResponse *pRequestServersResponse = luasteam::check_ISteamMatchmakingServerListResponse(L, 3);
	HServerListRequest __ret = iface->RequestFavoritesServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
	lua_pushlightuserdata(L, (void*)__ret);
	return 1;
}

// In C++:
// HServerListRequest RequestHistoryServerList(AppId_t iApp, MatchMakingKeyValuePair_t ** ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse * pRequestServersResponse);
// In Lua:
// HServerListRequest MatchmakingServers.RequestHistoryServerList(iApp: int, ppchFilters: MatchMakingKeyValuePair_t[], pRequestServersResponse: ISteamMatchmakingServerListResponse)
static int luasteam_MatchmakingServers_RequestHistoryServerList(lua_State *L) {
	auto *iface = SteamMatchmakingServers();
	AppId_t iApp = static_cast<AppId_t>(luaL_checkint(L, 1));
	int nFilters = (int)lua_objlen(L, 2);
	std::vector<MatchMakingKeyValuePair_t *> ppchFilters_vec(nFilters);
	for (int _i = 0; _i < nFilters; _i++) {
		lua_rawgeti(L, 2, _i + 1);
		ppchFilters_vec[_i] = luasteam::check_MatchMakingKeyValuePair_t_ptr(L, -1);
		lua_pop(L, 1);
	}
	MatchMakingKeyValuePair_t **ppchFilters = ppchFilters_vec.data();
	ISteamMatchmakingServerListResponse *pRequestServersResponse = luasteam::check_ISteamMatchmakingServerListResponse(L, 3);
	HServerListRequest __ret = iface->RequestHistoryServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
	lua_pushlightuserdata(L, (void*)__ret);
	return 1;
}

// In C++:
// HServerListRequest RequestSpectatorServerList(AppId_t iApp, MatchMakingKeyValuePair_t ** ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse * pRequestServersResponse);
// In Lua:
// HServerListRequest MatchmakingServers.RequestSpectatorServerList(iApp: int, ppchFilters: MatchMakingKeyValuePair_t[], pRequestServersResponse: ISteamMatchmakingServerListResponse)
static int luasteam_MatchmakingServers_RequestSpectatorServerList(lua_State *L) {
	auto *iface = SteamMatchmakingServers();
	AppId_t iApp = static_cast<AppId_t>(luaL_checkint(L, 1));
	int nFilters = (int)lua_objlen(L, 2);
	std::vector<MatchMakingKeyValuePair_t *> ppchFilters_vec(nFilters);
	for (int _i = 0; _i < nFilters; _i++) {
		lua_rawgeti(L, 2, _i + 1);
		ppchFilters_vec[_i] = luasteam::check_MatchMakingKeyValuePair_t_ptr(L, -1);
		lua_pop(L, 1);
	}
	MatchMakingKeyValuePair_t **ppchFilters = ppchFilters_vec.data();
	ISteamMatchmakingServerListResponse *pRequestServersResponse = luasteam::check_ISteamMatchmakingServerListResponse(L, 3);
	HServerListRequest __ret = iface->RequestSpectatorServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
	lua_pushlightuserdata(L, (void*)__ret);
	return 1;
}

// In C++:
// void ReleaseRequest(HServerListRequest hServerListRequest);
// In Lua:
// MatchmakingServers.ReleaseRequest(hServerListRequest: HServerListRequest)
static int luasteam_MatchmakingServers_ReleaseRequest(lua_State *L) {
	auto *iface = SteamMatchmakingServers();
	HServerListRequest hServerListRequest = (HServerListRequest)lua_touserdata(L, 1);
	iface->ReleaseRequest(hServerListRequest);
	return 0;
}

// In C++:
// void CancelQuery(HServerListRequest hRequest);
// In Lua:
// MatchmakingServers.CancelQuery(hRequest: HServerListRequest)
static int luasteam_MatchmakingServers_CancelQuery(lua_State *L) {
	auto *iface = SteamMatchmakingServers();
	HServerListRequest hRequest = (HServerListRequest)lua_touserdata(L, 1);
	iface->CancelQuery(hRequest);
	return 0;
}

// In C++:
// void RefreshQuery(HServerListRequest hRequest);
// In Lua:
// MatchmakingServers.RefreshQuery(hRequest: HServerListRequest)
static int luasteam_MatchmakingServers_RefreshQuery(lua_State *L) {
	auto *iface = SteamMatchmakingServers();
	HServerListRequest hRequest = (HServerListRequest)lua_touserdata(L, 1);
	iface->RefreshQuery(hRequest);
	return 0;
}

// In C++:
// bool IsRefreshing(HServerListRequest hRequest);
// In Lua:
// bool MatchmakingServers.IsRefreshing(hRequest: HServerListRequest)
static int luasteam_MatchmakingServers_IsRefreshing(lua_State *L) {
	auto *iface = SteamMatchmakingServers();
	HServerListRequest hRequest = (HServerListRequest)lua_touserdata(L, 1);
	bool __ret = iface->IsRefreshing(hRequest);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// int GetServerCount(HServerListRequest hRequest);
// In Lua:
// int MatchmakingServers.GetServerCount(hRequest: HServerListRequest)
static int luasteam_MatchmakingServers_GetServerCount(lua_State *L) {
	auto *iface = SteamMatchmakingServers();
	HServerListRequest hRequest = (HServerListRequest)lua_touserdata(L, 1);
	int __ret = iface->GetServerCount(hRequest);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// void RefreshServer(HServerListRequest hRequest, int iServer);
// In Lua:
// MatchmakingServers.RefreshServer(hRequest: HServerListRequest, iServer: int)
static int luasteam_MatchmakingServers_RefreshServer(lua_State *L) {
	auto *iface = SteamMatchmakingServers();
	HServerListRequest hRequest = (HServerListRequest)lua_touserdata(L, 1);
	int iServer = static_cast<int>(luaL_checkint(L, 2));
	iface->RefreshServer(hRequest, iServer);
	return 0;
}

// In C++:
// HServerQuery PingServer(uint32 unIP, uint16 usPort, ISteamMatchmakingPingResponse * pRequestServersResponse);
// In Lua:
// int MatchmakingServers.PingServer(unIP: int, usPort: int, pRequestServersResponse: ISteamMatchmakingPingResponse)
static int luasteam_MatchmakingServers_PingServer(lua_State *L) {
	auto *iface = SteamMatchmakingServers();
	uint32 unIP = static_cast<uint32>(luaL_checkint(L, 1));
	uint16 usPort = static_cast<uint16>(luaL_checkint(L, 2));
	ISteamMatchmakingPingResponse *pRequestServersResponse = luasteam::check_ISteamMatchmakingPingResponse(L, 3);
	HServerQuery __ret = iface->PingServer(unIP, usPort, pRequestServersResponse);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// HServerQuery PlayerDetails(uint32 unIP, uint16 usPort, ISteamMatchmakingPlayersResponse * pRequestServersResponse);
// In Lua:
// int MatchmakingServers.PlayerDetails(unIP: int, usPort: int, pRequestServersResponse: ISteamMatchmakingPlayersResponse)
static int luasteam_MatchmakingServers_PlayerDetails(lua_State *L) {
	auto *iface = SteamMatchmakingServers();
	uint32 unIP = static_cast<uint32>(luaL_checkint(L, 1));
	uint16 usPort = static_cast<uint16>(luaL_checkint(L, 2));
	ISteamMatchmakingPlayersResponse *pRequestServersResponse = luasteam::check_ISteamMatchmakingPlayersResponse(L, 3);
	HServerQuery __ret = iface->PlayerDetails(unIP, usPort, pRequestServersResponse);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// HServerQuery ServerRules(uint32 unIP, uint16 usPort, ISteamMatchmakingRulesResponse * pRequestServersResponse);
// In Lua:
// int MatchmakingServers.ServerRules(unIP: int, usPort: int, pRequestServersResponse: ISteamMatchmakingRulesResponse)
static int luasteam_MatchmakingServers_ServerRules(lua_State *L) {
	auto *iface = SteamMatchmakingServers();
	uint32 unIP = static_cast<uint32>(luaL_checkint(L, 1));
	uint16 usPort = static_cast<uint16>(luaL_checkint(L, 2));
	ISteamMatchmakingRulesResponse *pRequestServersResponse = luasteam::check_ISteamMatchmakingRulesResponse(L, 3);
	HServerQuery __ret = iface->ServerRules(unIP, usPort, pRequestServersResponse);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// void CancelServerQuery(HServerQuery hServerQuery);
// In Lua:
// MatchmakingServers.CancelServerQuery(hServerQuery: int)
static int luasteam_MatchmakingServers_CancelServerQuery(lua_State *L) {
	auto *iface = SteamMatchmakingServers();
	HServerQuery hServerQuery = static_cast<HServerQuery>(luaL_checkint(L, 1));
	iface->CancelServerQuery(hServerQuery);
	return 0;
}

void register_MatchmakingServers_auto(lua_State *L) {
	add_func(L, "RequestInternetServerList", luasteam_MatchmakingServers_RequestInternetServerList);
	add_func(L, "RequestLANServerList", luasteam_MatchmakingServers_RequestLANServerList);
	add_func(L, "RequestFriendsServerList", luasteam_MatchmakingServers_RequestFriendsServerList);
	add_func(L, "RequestFavoritesServerList", luasteam_MatchmakingServers_RequestFavoritesServerList);
	add_func(L, "RequestHistoryServerList", luasteam_MatchmakingServers_RequestHistoryServerList);
	add_func(L, "RequestSpectatorServerList", luasteam_MatchmakingServers_RequestSpectatorServerList);
	add_func(L, "ReleaseRequest", luasteam_MatchmakingServers_ReleaseRequest);
	add_func(L, "CancelQuery", luasteam_MatchmakingServers_CancelQuery);
	add_func(L, "RefreshQuery", luasteam_MatchmakingServers_RefreshQuery);
	add_func(L, "IsRefreshing", luasteam_MatchmakingServers_IsRefreshing);
	add_func(L, "GetServerCount", luasteam_MatchmakingServers_GetServerCount);
	add_func(L, "RefreshServer", luasteam_MatchmakingServers_RefreshServer);
	add_func(L, "PingServer", luasteam_MatchmakingServers_PingServer);
	add_func(L, "PlayerDetails", luasteam_MatchmakingServers_PlayerDetails);
	add_func(L, "ServerRules", luasteam_MatchmakingServers_ServerRules);
	add_func(L, "CancelServerQuery", luasteam_MatchmakingServers_CancelServerQuery);
}

void add_MatchmakingServers_auto(lua_State *L) {
	lua_createtable(L, 0, 16);
	register_MatchmakingServers_auto(L);
	lua_pushvalue(L, -1);
	MatchmakingServers_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "MatchmakingServers");
}

} // namespace luasteam
