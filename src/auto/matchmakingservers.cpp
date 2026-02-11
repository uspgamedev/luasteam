#include "auto.hpp"

namespace luasteam {

int matchmakingservers_ref = LUA_NOREF;

void init_matchmakingservers_auto(lua_State *L) {}

void shutdown_matchmakingservers_auto(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, matchmakingservers_ref);
    matchmakingservers_ref = LUA_NOREF;
}


// void CancelServerQuery(HServerQuery hServerQuery);
EXTERN int luasteam_matchmakingservers_SteamAPI_ISteamMatchmakingServers_CancelServerQuery(lua_State *L) {
    HServerQuery hServerQuery = static_cast<HServerQuery>(luaL_checkint(L, 1));
    SteamMatchmakingServers()->CancelServerQuery(hServerQuery);
    return 0;
}

void register_matchmakingservers_auto(lua_State *L) {
    add_func(L, "cancelServerQuery", luasteam_matchmakingservers_SteamAPI_ISteamMatchmakingServers_CancelServerQuery);
}

void add_matchmakingservers_auto(lua_State *L) {
    lua_createtable(L, 0, 1);
    register_matchmakingservers_auto(L);
    lua_pushvalue(L, -1);
    matchmakingservers_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "matchmakingServers");
}

} // namespace luasteam
