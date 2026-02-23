#include "auto.hpp"

namespace luasteam {

int MatchmakingServers_ref = LUA_NOREF;

void init_MatchmakingServers_auto(lua_State *L) {}
void shutdown_MatchmakingServers_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, MatchmakingServers_ref);
	MatchmakingServers_ref = LUA_NOREF;
}

// In C++:
// void CancelServerQuery(HServerQuery hServerQuery);
// In Lua:
// MatchmakingServers.CancelServerQuery(hServerQuery: int)
EXTERN int luasteam_MatchmakingServers_CancelServerQuery(lua_State *L) {
	HServerQuery hServerQuery = static_cast<HServerQuery>(luaL_checkint(L, 1));
	SteamMatchmakingServers()->CancelServerQuery(hServerQuery);
	return 0;
}

void register_MatchmakingServers_auto(lua_State *L) {
	add_func(L, "CancelServerQuery", luasteam_MatchmakingServers_CancelServerQuery);
}

void add_MatchmakingServers_auto(lua_State *L) {
	lua_createtable(L, 0, 1);
	register_MatchmakingServers_auto(L);
	lua_pushvalue(L, -1);
	MatchmakingServers_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "MatchmakingServers");
}

} // namespace luasteam
