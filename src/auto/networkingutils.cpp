#include "auto.hpp"

// void InitRelayNetworkAccess();
EXTERN int luasteam_networkingutils_SteamAPI_ISteamNetworkingUtils_InitRelayNetworkAccess(lua_State *L) {
    SteamNetworkingUtils()->InitRelayNetworkAccess();
    return 0;
}

// int GetDirectPingToPOP(SteamNetworkingPOPID popID);
EXTERN int luasteam_networkingutils_SteamAPI_ISteamNetworkingUtils_GetDirectPingToPOP(lua_State *L) {
    SteamNetworkingPOPID popID = static_cast<SteamNetworkingPOPID>(luaL_checkint(L, 1));
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
    uint32 nIPv4 = static_cast<uint32>(luaL_checkint(L, 1));
    lua_pushboolean(L, SteamNetworkingUtils()->IsFakeIPv4(nIPv4));
    return 1;
}

// ESteamNetworkingFakeIPType GetIPv4FakeIPType(uint32 nIPv4);
EXTERN int luasteam_networkingutils_SteamAPI_ISteamNetworkingUtils_GetIPv4FakeIPType(lua_State *L) {
    uint32 nIPv4 = static_cast<uint32>(luaL_checkint(L, 1));
    lua_pushinteger(L, SteamNetworkingUtils()->GetIPv4FakeIPType(nIPv4));
    return 1;
}

// bool SetGlobalConfigValueInt32(ESteamNetworkingConfigValue eValue, int32 val);
EXTERN int luasteam_networkingutils_SteamAPI_ISteamNetworkingUtils_SetGlobalConfigValueInt32(lua_State *L) {
    ESteamNetworkingConfigValue eValue = static_cast<ESteamNetworkingConfigValue>(luaL_checkint(L, 1));
    int32 val = static_cast<int32>(luaL_checkint(L, 2));
    lua_pushboolean(L, SteamNetworkingUtils()->SetGlobalConfigValueInt32(eValue, val));
    return 1;
}

// bool SetGlobalConfigValueString(ESteamNetworkingConfigValue eValue, const char * val);
EXTERN int luasteam_networkingutils_SteamAPI_ISteamNetworkingUtils_SetGlobalConfigValueString(lua_State *L) {
    ESteamNetworkingConfigValue eValue = static_cast<ESteamNetworkingConfigValue>(luaL_checkint(L, 1));
    const char *val = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamNetworkingUtils()->SetGlobalConfigValueString(eValue, val));
    return 1;
}

// bool SetConnectionConfigValueInt32(HSteamNetConnection hConn, ESteamNetworkingConfigValue eValue, int32 val);
EXTERN int luasteam_networkingutils_SteamAPI_ISteamNetworkingUtils_SetConnectionConfigValueInt32(lua_State *L) {
    HSteamNetConnection hConn = static_cast<HSteamNetConnection>(luaL_checkint(L, 1));
    ESteamNetworkingConfigValue eValue = static_cast<ESteamNetworkingConfigValue>(luaL_checkint(L, 2));
    int32 val = static_cast<int32>(luaL_checkint(L, 3));
    lua_pushboolean(L, SteamNetworkingUtils()->SetConnectionConfigValueInt32(hConn, eValue, val));
    return 1;
}

// bool SetConnectionConfigValueString(HSteamNetConnection hConn, ESteamNetworkingConfigValue eValue, const char * val);
EXTERN int luasteam_networkingutils_SteamAPI_ISteamNetworkingUtils_SetConnectionConfigValueString(lua_State *L) {
    HSteamNetConnection hConn = static_cast<HSteamNetConnection>(luaL_checkint(L, 1));
    ESteamNetworkingConfigValue eValue = static_cast<ESteamNetworkingConfigValue>(luaL_checkint(L, 2));
    const char *val = luaL_checkstring(L, 3);
    lua_pushboolean(L, SteamNetworkingUtils()->SetConnectionConfigValueString(hConn, eValue, val));
    return 1;
}

// ESteamNetworkingConfigValue IterateGenericEditableConfigValues(ESteamNetworkingConfigValue eCurrent, bool bEnumerateDevVars);
EXTERN int luasteam_networkingutils_SteamAPI_ISteamNetworkingUtils_IterateGenericEditableConfigValues(lua_State *L) {
    ESteamNetworkingConfigValue eCurrent = static_cast<ESteamNetworkingConfigValue>(luaL_checkint(L, 1));
    bool bEnumerateDevVars = lua_toboolean(L, 2);
    lua_pushinteger(L, SteamNetworkingUtils()->IterateGenericEditableConfigValues(eCurrent, bEnumerateDevVars));
    return 1;
}

namespace luasteam {

void add_networkingutils_auto(lua_State *L) {
    add_func(L, "initRelayNetworkAccess", luasteam_networkingutils_SteamAPI_ISteamNetworkingUtils_InitRelayNetworkAccess);
    add_func(L, "getDirectPingToPOP", luasteam_networkingutils_SteamAPI_ISteamNetworkingUtils_GetDirectPingToPOP);
    add_func(L, "getPOPCount", luasteam_networkingutils_SteamAPI_ISteamNetworkingUtils_GetPOPCount);
    add_func(L, "isFakeIPv4", luasteam_networkingutils_SteamAPI_ISteamNetworkingUtils_IsFakeIPv4);
    add_func(L, "getIPv4FakeIPType", luasteam_networkingutils_SteamAPI_ISteamNetworkingUtils_GetIPv4FakeIPType);
    add_func(L, "setGlobalConfigValueInt32", luasteam_networkingutils_SteamAPI_ISteamNetworkingUtils_SetGlobalConfigValueInt32);
    add_func(L, "setGlobalConfigValueString", luasteam_networkingutils_SteamAPI_ISteamNetworkingUtils_SetGlobalConfigValueString);
    add_func(L, "setConnectionConfigValueInt32", luasteam_networkingutils_SteamAPI_ISteamNetworkingUtils_SetConnectionConfigValueInt32);
    add_func(L, "setConnectionConfigValueString", luasteam_networkingutils_SteamAPI_ISteamNetworkingUtils_SetConnectionConfigValueString);
    add_func(L, "iterateGenericEditableConfigValues", luasteam_networkingutils_SteamAPI_ISteamNetworkingUtils_IterateGenericEditableConfigValues);
}

} // namespace luasteam
