#include "auto.hpp"

namespace luasteam {

int NetworkingUtils_ref = LUA_NOREF;

namespace {

class CallbackListener {
  private:
    STEAM_CALLBACK(CallbackListener, OnSteamRelayNetworkStatus, SteamRelayNetworkStatus_t);
};

void CallbackListener::OnSteamRelayNetworkStatus(SteamRelayNetworkStatus_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::NetworkingUtils_ref);
    lua_getfield(L, -1, "onSteamRelayNetworkStatus");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 5);
        lua_pushinteger(L, data->m_eAvail);
        lua_setfield(L, -2, "avail");
        lua_pushboolean(L, data->m_bPingMeasurementInProgress);
        lua_setfield(L, -2, "pingMeasurementInProgress");
        lua_pushinteger(L, data->m_eAvailNetworkConfig);
        lua_setfield(L, -2, "availNetworkConfig");
        lua_pushinteger(L, data->m_eAvailAnyRelay);
        lua_setfield(L, -2, "availAnyRelay");
        lua_pushstring(L, data->m_debugMsg);
        lua_setfield(L, -2, "debugMsg");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

CallbackListener *NetworkingUtils_listener = nullptr;

} // namespace

void init_NetworkingUtils_auto(lua_State *L) { NetworkingUtils_listener = new CallbackListener(); }

void shutdown_NetworkingUtils_auto(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, NetworkingUtils_ref);
    NetworkingUtils_ref = LUA_NOREF;
    delete NetworkingUtils_listener; NetworkingUtils_listener = nullptr;
}


// void InitRelayNetworkAccess();
EXTERN int luasteam_NetworkingUtils_InitRelayNetworkAccess(lua_State *L) {
    SteamNetworkingUtils_SteamAPI()->InitRelayNetworkAccess();
    return 0;
}

// int GetDirectPingToPOP(SteamNetworkingPOPID popID);
EXTERN int luasteam_NetworkingUtils_GetDirectPingToPOP(lua_State *L) {
    SteamNetworkingPOPID popID = static_cast<SteamNetworkingPOPID>(luaL_checkint(L, 1));
    lua_pushinteger(L, SteamNetworkingUtils_SteamAPI()->GetDirectPingToPOP(popID));
    return 1;
}

// int GetPOPCount();
EXTERN int luasteam_NetworkingUtils_GetPOPCount(lua_State *L) {
    lua_pushinteger(L, SteamNetworkingUtils_SteamAPI()->GetPOPCount());
    return 1;
}

// bool IsFakeIPv4(uint32 nIPv4);
EXTERN int luasteam_NetworkingUtils_IsFakeIPv4(lua_State *L) {
    uint32 nIPv4 = static_cast<uint32>(luaL_checkint(L, 1));
    lua_pushboolean(L, SteamNetworkingUtils_SteamAPI()->IsFakeIPv4(nIPv4));
    return 1;
}

// ESteamNetworkingFakeIPType GetIPv4FakeIPType(uint32 nIPv4);
EXTERN int luasteam_NetworkingUtils_GetIPv4FakeIPType(lua_State *L) {
    uint32 nIPv4 = static_cast<uint32>(luaL_checkint(L, 1));
    lua_pushinteger(L, SteamNetworkingUtils_SteamAPI()->GetIPv4FakeIPType(nIPv4));
    return 1;
}

// bool SetGlobalConfigValueInt32(ESteamNetworkingConfigValue eValue, int32 val);
EXTERN int luasteam_NetworkingUtils_SetGlobalConfigValueInt32(lua_State *L) {
    ESteamNetworkingConfigValue eValue = static_cast<ESteamNetworkingConfigValue>(luaL_checkint(L, 1));
    int32 val = static_cast<int32>(luaL_checkint(L, 2));
    lua_pushboolean(L, SteamNetworkingUtils_SteamAPI()->SetGlobalConfigValueInt32(eValue, val));
    return 1;
}

// bool SetGlobalConfigValueString(ESteamNetworkingConfigValue eValue, const char * val);
EXTERN int luasteam_NetworkingUtils_SetGlobalConfigValueString(lua_State *L) {
    ESteamNetworkingConfigValue eValue = static_cast<ESteamNetworkingConfigValue>(luaL_checkint(L, 1));
    const char *val = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamNetworkingUtils_SteamAPI()->SetGlobalConfigValueString(eValue, val));
    return 1;
}

// bool SetConnectionConfigValueInt32(HSteamNetConnection hConn, ESteamNetworkingConfigValue eValue, int32 val);
EXTERN int luasteam_NetworkingUtils_SetConnectionConfigValueInt32(lua_State *L) {
    HSteamNetConnection hConn = static_cast<HSteamNetConnection>(luaL_checkint(L, 1));
    ESteamNetworkingConfigValue eValue = static_cast<ESteamNetworkingConfigValue>(luaL_checkint(L, 2));
    int32 val = static_cast<int32>(luaL_checkint(L, 3));
    lua_pushboolean(L, SteamNetworkingUtils_SteamAPI()->SetConnectionConfigValueInt32(hConn, eValue, val));
    return 1;
}

// bool SetConnectionConfigValueString(HSteamNetConnection hConn, ESteamNetworkingConfigValue eValue, const char * val);
EXTERN int luasteam_NetworkingUtils_SetConnectionConfigValueString(lua_State *L) {
    HSteamNetConnection hConn = static_cast<HSteamNetConnection>(luaL_checkint(L, 1));
    ESteamNetworkingConfigValue eValue = static_cast<ESteamNetworkingConfigValue>(luaL_checkint(L, 2));
    const char *val = luaL_checkstring(L, 3);
    lua_pushboolean(L, SteamNetworkingUtils_SteamAPI()->SetConnectionConfigValueString(hConn, eValue, val));
    return 1;
}

// ESteamNetworkingConfigValue IterateGenericEditableConfigValues(ESteamNetworkingConfigValue eCurrent, bool bEnumerateDevVars);
EXTERN int luasteam_NetworkingUtils_IterateGenericEditableConfigValues(lua_State *L) {
    ESteamNetworkingConfigValue eCurrent = static_cast<ESteamNetworkingConfigValue>(luaL_checkint(L, 1));
    bool bEnumerateDevVars = lua_toboolean(L, 2);
    lua_pushinteger(L, SteamNetworkingUtils_SteamAPI()->IterateGenericEditableConfigValues(eCurrent, bEnumerateDevVars));
    return 1;
}

void register_NetworkingUtils_auto(lua_State *L) {
    add_func(L, "InitRelayNetworkAccess", luasteam_NetworkingUtils_InitRelayNetworkAccess);
    add_func(L, "GetDirectPingToPOP", luasteam_NetworkingUtils_GetDirectPingToPOP);
    add_func(L, "GetPOPCount", luasteam_NetworkingUtils_GetPOPCount);
    add_func(L, "IsFakeIPv4", luasteam_NetworkingUtils_IsFakeIPv4);
    add_func(L, "GetIPv4FakeIPType", luasteam_NetworkingUtils_GetIPv4FakeIPType);
    add_func(L, "SetGlobalConfigValueInt32", luasteam_NetworkingUtils_SetGlobalConfigValueInt32);
    add_func(L, "SetGlobalConfigValueString", luasteam_NetworkingUtils_SetGlobalConfigValueString);
    add_func(L, "SetConnectionConfigValueInt32", luasteam_NetworkingUtils_SetConnectionConfigValueInt32);
    add_func(L, "SetConnectionConfigValueString", luasteam_NetworkingUtils_SetConnectionConfigValueString);
    add_func(L, "IterateGenericEditableConfigValues", luasteam_NetworkingUtils_IterateGenericEditableConfigValues);
}

void add_NetworkingUtils_auto(lua_State *L) {
    lua_createtable(L, 0, 10);
    register_NetworkingUtils_auto(L);
    lua_pushvalue(L, -1);
    NetworkingUtils_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "NetworkingUtils");
}

} // namespace luasteam
