#include "NetworkingUtils.hpp"
#include "auto/auto.hpp"

// ======================================
// ======= SteamNetworkingUtils =========
// ======================================

// Manually implemented because it passes NULL to avoid allocating the output struct
// ESteamNetworkingAvailability GetRelayNetworkStatus( SteamRelayNetworkStatus_t *pDetails )
EXTERN int luasteam_NetworkingUtils_GetRelayNetworkStatus(lua_State *L) {
    ESteamNetworkingAvailability status = SteamNetworkingUtils_SteamAPI()->GetRelayNetworkStatus(NULL);
    lua_pushinteger(L, status);
    return 1;
}

// ======================================
// SetGlobalCallback_* — store a Lua function and pass a trampoline to Steam
// ======================================

namespace {
static int cb_SteamNetConnectionStatusChanged_ref = LUA_NOREF;
static int cb_SteamNetAuthenticationStatusChanged_ref = LUA_NOREF;
static int cb_SteamRelayNetworkStatusChanged_ref = LUA_NOREF;
static int cb_SteamNetworkingFakeIPResult_ref = LUA_NOREF;
static int cb_MessagesSessionRequest_ref = LUA_NOREF;
static int cb_MessagesSessionFailed_ref = LUA_NOREF;

void trampoline_SteamNetConnectionStatusChanged(SteamNetConnectionStatusChangedCallback_t *data) {
    if (cb_SteamNetConnectionStatusChanged_ref == LUA_NOREF) return;
    lua_State *L = luasteam::global_lua_state;
    lua_rawgeti(L, LUA_REGISTRYINDEX, cb_SteamNetConnectionStatusChanged_ref);
    lua_createtable(L, 0, 3);
    lua_pushinteger(L, data->m_hConn);
    lua_setfield(L, -2, "m_hConn");
    luasteam::push_SteamNetConnectionInfo_t(L, data->m_info);
    lua_setfield(L, -2, "m_info");
    lua_pushinteger(L, data->m_eOldState);
    lua_setfield(L, -2, "m_eOldState");
    lua_call(L, 1, 0);
}

void trampoline_SteamNetAuthenticationStatusChanged(SteamNetAuthenticationStatus_t *data) {
    if (cb_SteamNetAuthenticationStatusChanged_ref == LUA_NOREF) return;
    lua_State *L = luasteam::global_lua_state;
    lua_rawgeti(L, LUA_REGISTRYINDEX, cb_SteamNetAuthenticationStatusChanged_ref);
    lua_createtable(L, 0, 2);
    lua_pushinteger(L, data->m_eAvail);
    lua_setfield(L, -2, "m_eAvail");
    lua_pushstring(L, reinterpret_cast<const char *>(data->m_debugMsg));
    lua_setfield(L, -2, "m_debugMsg");
    lua_call(L, 1, 0);
}

void trampoline_SteamRelayNetworkStatusChanged(SteamRelayNetworkStatus_t *data) {
    if (cb_SteamRelayNetworkStatusChanged_ref == LUA_NOREF) return;
    lua_State *L = luasteam::global_lua_state;
    lua_rawgeti(L, LUA_REGISTRYINDEX, cb_SteamRelayNetworkStatusChanged_ref);
    lua_createtable(L, 0, 5);
    lua_pushinteger(L, data->m_eAvail);
    lua_setfield(L, -2, "m_eAvail");
    lua_pushinteger(L, data->m_bPingMeasurementInProgress);
    lua_setfield(L, -2, "m_bPingMeasurementInProgress");
    lua_pushinteger(L, data->m_eAvailNetworkConfig);
    lua_setfield(L, -2, "m_eAvailNetworkConfig");
    lua_pushinteger(L, data->m_eAvailAnyRelay);
    lua_setfield(L, -2, "m_eAvailAnyRelay");
    lua_pushstring(L, reinterpret_cast<const char *>(data->m_debugMsg));
    lua_setfield(L, -2, "m_debugMsg");
    lua_call(L, 1, 0);
}

void trampoline_SteamNetworkingFakeIPResult(SteamNetworkingFakeIPResult_t *data) {
    if (cb_SteamNetworkingFakeIPResult_ref == LUA_NOREF) return;
    lua_State *L = luasteam::global_lua_state;
    lua_rawgeti(L, LUA_REGISTRYINDEX, cb_SteamNetworkingFakeIPResult_ref);
    lua_createtable(L, 0, 3);
    lua_pushinteger(L, data->m_eResult);
    lua_setfield(L, -2, "m_eResult");
    luasteam::push_SteamNetworkingIdentity(L, data->m_identity);
    lua_setfield(L, -2, "m_identity");
    lua_pushinteger(L, data->m_unIP);
    lua_setfield(L, -2, "m_unIP");
    lua_call(L, 1, 0);
}

void trampoline_MessagesSessionRequest(SteamNetworkingMessagesSessionRequest_t *data) {
    if (cb_MessagesSessionRequest_ref == LUA_NOREF) return;
    lua_State *L = luasteam::global_lua_state;
    lua_rawgeti(L, LUA_REGISTRYINDEX, cb_MessagesSessionRequest_ref);
    lua_createtable(L, 0, 1);
    luasteam::push_SteamNetworkingIdentity(L, data->m_identityRemote);
    lua_setfield(L, -2, "m_identityRemote");
    lua_call(L, 1, 0);
}

void trampoline_MessagesSessionFailed(SteamNetworkingMessagesSessionFailed_t *data) {
    if (cb_MessagesSessionFailed_ref == LUA_NOREF) return;
    lua_State *L = luasteam::global_lua_state;
    lua_rawgeti(L, LUA_REGISTRYINDEX, cb_MessagesSessionFailed_ref);
    lua_createtable(L, 0, 1);
    luasteam::push_SteamNetConnectionInfo_t(L, data->m_info);
    lua_setfield(L, -2, "m_info");
    lua_call(L, 1, 0);
}
} // namespace

#define DEFINE_SET_GLOBAL_CALLBACK(lua_name, fn_type, steam_method, ref_var, trampoline)        \
    EXTERN int lua_name(lua_State *L) {                                                          \
        luaL_unref(L, LUA_REGISTRYINDEX, ref_var);                                              \
        if (lua_isnil(L, 1)) {                                                                   \
            ref_var = LUA_NOREF;                                                                 \
            bool __ret = SteamNetworkingUtils_SteamAPI()->steam_method((fn_type) nullptr);       \
            lua_pushboolean(L, __ret);                                                           \
        } else {                                                                                 \
            luaL_checktype(L, 1, LUA_TFUNCTION);                                                \
            lua_pushvalue(L, 1);                                                                 \
            ref_var = luaL_ref(L, LUA_REGISTRYINDEX);                                           \
            bool __ret = SteamNetworkingUtils_SteamAPI()->steam_method(trampoline);              \
            lua_pushboolean(L, __ret);                                                           \
        }                                                                                        \
        return 1;                                                                                \
    }

DEFINE_SET_GLOBAL_CALLBACK(
    luasteam_NetworkingUtils_SetGlobalCallback_SteamNetConnectionStatusChanged,
    FnSteamNetConnectionStatusChanged,
    SetGlobalCallback_SteamNetConnectionStatusChanged,
    cb_SteamNetConnectionStatusChanged_ref,
    trampoline_SteamNetConnectionStatusChanged)

DEFINE_SET_GLOBAL_CALLBACK(
    luasteam_NetworkingUtils_SetGlobalCallback_SteamNetAuthenticationStatusChanged,
    FnSteamNetAuthenticationStatusChanged,
    SetGlobalCallback_SteamNetAuthenticationStatusChanged,
    cb_SteamNetAuthenticationStatusChanged_ref,
    trampoline_SteamNetAuthenticationStatusChanged)

DEFINE_SET_GLOBAL_CALLBACK(
    luasteam_NetworkingUtils_SetGlobalCallback_SteamRelayNetworkStatusChanged,
    FnSteamRelayNetworkStatusChanged,
    SetGlobalCallback_SteamRelayNetworkStatusChanged,
    cb_SteamRelayNetworkStatusChanged_ref,
    trampoline_SteamRelayNetworkStatusChanged)

DEFINE_SET_GLOBAL_CALLBACK(
    luasteam_NetworkingUtils_SetGlobalCallback_FakeIPResult,
    FnSteamNetworkingFakeIPResult,
    SetGlobalCallback_FakeIPResult,
    cb_SteamNetworkingFakeIPResult_ref,
    trampoline_SteamNetworkingFakeIPResult)

DEFINE_SET_GLOBAL_CALLBACK(
    luasteam_NetworkingUtils_SetGlobalCallback_MessagesSessionRequest,
    FnSteamNetworkingMessagesSessionRequest,
    SetGlobalCallback_MessagesSessionRequest,
    cb_MessagesSessionRequest_ref,
    trampoline_MessagesSessionRequest)

DEFINE_SET_GLOBAL_CALLBACK(
    luasteam_NetworkingUtils_SetGlobalCallback_MessagesSessionFailed,
    FnSteamNetworkingMessagesSessionFailed,
    SetGlobalCallback_MessagesSessionFailed,
    cb_MessagesSessionFailed_ref,
    trampoline_MessagesSessionFailed)

namespace luasteam {

void add_networkingUtils(lua_State *L) {
    lua_createtable(L, 0, 32);
    lua_pushvalue(L, -1);
    NetworkingUtils_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    register_NetworkingUtils_auto(L);
    add_func(L, "GetRelayNetworkStatus", luasteam_NetworkingUtils_GetRelayNetworkStatus);
    add_func(L, "SetGlobalCallback_SteamNetConnectionStatusChanged", luasteam_NetworkingUtils_SetGlobalCallback_SteamNetConnectionStatusChanged);
    add_func(L, "SetGlobalCallback_SteamNetAuthenticationStatusChanged", luasteam_NetworkingUtils_SetGlobalCallback_SteamNetAuthenticationStatusChanged);
    add_func(L, "SetGlobalCallback_SteamRelayNetworkStatusChanged", luasteam_NetworkingUtils_SetGlobalCallback_SteamRelayNetworkStatusChanged);
    add_func(L, "SetGlobalCallback_FakeIPResult", luasteam_NetworkingUtils_SetGlobalCallback_FakeIPResult);
    add_func(L, "SetGlobalCallback_MessagesSessionRequest", luasteam_NetworkingUtils_SetGlobalCallback_MessagesSessionRequest);
    add_func(L, "SetGlobalCallback_MessagesSessionFailed", luasteam_NetworkingUtils_SetGlobalCallback_MessagesSessionFailed);
    lua_setfield(L, -2, "NetworkingUtils");
}

void init_networkingUtils(lua_State *L) {
    init_NetworkingUtils_auto(L);
}

void shutdown_networkingUtils(lua_State *L) {
    shutdown_NetworkingUtils_auto(L);
}

} // namespace luasteam
