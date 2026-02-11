#include "auto.hpp"

// void InitRelayNetworkAccess();
EXTERN int luasteam_networkingutils_SteamAPI_ISteamNetworkingUtils_InitRelayNetworkAccess(lua_State *L) {
    SteamNetworkingUtils()->InitRelayNetworkAccess();
    return 0;
}

// int GetDirectPingToPOP(SteamNetworkingPOPID popID);
EXTERN int luasteam_networkingutils_SteamAPI_ISteamNetworkingUtils_GetDirectPingToPOP(lua_State *L) {
    SteamNetworkingPOPID popID = luaL_checkint(L, 1);
    lua_pushinteger(L, SteamNetworkingUtils()->GetDirectPingToPOP(popID));
    return 1;
}

// int GetPOPCount();
EXTERN int luasteam_networkingutils_SteamAPI_ISteamNetworkingUtils_GetPOPCount(lua_State *L) {
    lua_pushinteger(L, SteamNetworkingUtils()->GetPOPCount());
    return 1;
}

// bool IsFakeIPv4(uint32 nIPv4);
EXTERN int luasteam_networkingutils_SteamAPI_ISteamNetworkingUtils_IsFakeIPv4(lua_State *L) {
    uint32 nIPv4 = luaL_checkint(L, 1);
    lua_pushboolean(L, SteamNetworkingUtils()->IsFakeIPv4(nIPv4));
    return 1;
}

namespace luasteam {

void add_networkingutils_auto(lua_State *L) {
    add_func(L, "initRelayNetworkAccess", luasteam_networkingutils_SteamAPI_ISteamNetworkingUtils_InitRelayNetworkAccess);
    add_func(L, "getDirectPingToPOP", luasteam_networkingutils_SteamAPI_ISteamNetworkingUtils_GetDirectPingToPOP);
    add_func(L, "getPOPCount", luasteam_networkingutils_SteamAPI_ISteamNetworkingUtils_GetPOPCount);
    add_func(L, "isFakeIPv4", luasteam_networkingutils_SteamAPI_ISteamNetworkingUtils_IsFakeIPv4);
}

} // namespace luasteam
