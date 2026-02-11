#include "networkingUtils.hpp"
#include "auto/auto.hpp"

// ======================================
// ======= SteamNetworkingUtils =========
// ======================================

namespace {

int networkingutils_ref = LUA_NOREF;

} // namespace

// Manually implemented because it passes NULL to the details parameter
// ESteamNetworkingAvailability GetRelayNetworkStatus( SteamRelayNetworkStatus_t *pDetails )
EXTERN int luasteam_getRelayNetworkStatus(lua_State *L) {
    ESteamNetworkingAvailability status = SteamNetworkingUtils()->GetRelayNetworkStatus(NULL);
    lua_pushinteger(L, status);
    return 1;
}

namespace luasteam {

void add_networkingUtils(lua_State *L) {
    lua_createtable(L, 0, 1);
    add_networkingutils_auto(L);
    add_func(L, "getRelayNetworkStatus", luasteam_getRelayNetworkStatus);
    lua_pushvalue(L, -1);
    networkingutils_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "networkingUtils");
}

void init_networkingUtils(lua_State *L) {}

void shutdown_networkingUtils(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, networkingutils_ref);
    networkingutils_ref = LUA_NOREF;
}

} // namespace luasteam
