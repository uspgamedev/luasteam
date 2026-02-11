#include "auto.hpp"

namespace luasteam {

int NetworkingSockets_ref = LUA_NOREF;

namespace {

class CallbackListener {
  private:
    STEAM_CALLBACK(CallbackListener, OnSteamNetConnectionStatusChangedCallback, SteamNetConnectionStatusChangedCallback_t);
    STEAM_CALLBACK(CallbackListener, OnSteamNetAuthenticationStatus, SteamNetAuthenticationStatus_t);
    STEAM_CALLBACK(CallbackListener, OnSteamNetworkingFakeIPResult, SteamNetworkingFakeIPResult_t);
};

void CallbackListener::OnSteamNetConnectionStatusChangedCallback(SteamNetConnectionStatusChangedCallback_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::NetworkingSockets_ref);
    lua_getfield(L, -1, "OnSteamNetConnectionStatusChangedCallback");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->m_hConn);
        lua_setfield(L, -2, "m_hConn");
        // Skip unsupported type: SteamNetConnectionInfo_t
        lua_pushinteger(L, data->m_eOldState);
        lua_setfield(L, -2, "m_eOldState");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnSteamNetAuthenticationStatus(SteamNetAuthenticationStatus_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::NetworkingSockets_ref);
    lua_getfield(L, -1, "OnSteamNetAuthenticationStatus");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->m_eAvail);
        lua_setfield(L, -2, "m_eAvail");
        // Skip unsupported type: char [256]
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnSteamNetworkingFakeIPResult(SteamNetworkingFakeIPResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::NetworkingSockets_ref);
    lua_getfield(L, -1, "OnSteamNetworkingFakeIPResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "m_eResult");
        // Skip unsupported type: SteamNetworkingIdentity
        lua_pushinteger(L, data->m_unIP);
        lua_setfield(L, -2, "m_unIP");
        // Skip unsupported type: uint16 [8]
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

CallbackListener *NetworkingSockets_listener = nullptr;

} // namespace

void init_NetworkingSockets_auto(lua_State *L) { NetworkingSockets_listener = new CallbackListener(); }

void shutdown_NetworkingSockets_auto(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, NetworkingSockets_ref);
    NetworkingSockets_ref = LUA_NOREF;
    delete NetworkingSockets_listener; NetworkingSockets_listener = nullptr;
}


// EResult AcceptConnection(HSteamNetConnection hConn);
EXTERN int luasteam_NetworkingSockets_AcceptConnection(lua_State *L) {
    HSteamNetConnection hConn = static_cast<HSteamNetConnection>(luaL_checkint(L, 1));
    lua_pushinteger(L, SteamNetworkingSockets_SteamAPI()->AcceptConnection(hConn));
    return 1;
}

// bool CloseConnection(HSteamNetConnection hPeer, int nReason, const char * pszDebug, bool bEnableLinger);
EXTERN int luasteam_NetworkingSockets_CloseConnection(lua_State *L) {
    HSteamNetConnection hPeer = static_cast<HSteamNetConnection>(luaL_checkint(L, 1));
    int nReason = static_cast<int>(luaL_checkint(L, 2));
    const char *pszDebug = luaL_checkstring(L, 3);
    bool bEnableLinger = lua_toboolean(L, 4);
    lua_pushboolean(L, SteamNetworkingSockets_SteamAPI()->CloseConnection(hPeer, nReason, pszDebug, bEnableLinger));
    return 1;
}

// bool CloseListenSocket(HSteamListenSocket hSocket);
EXTERN int luasteam_NetworkingSockets_CloseListenSocket(lua_State *L) {
    HSteamListenSocket hSocket = static_cast<HSteamListenSocket>(luaL_checkint(L, 1));
    lua_pushboolean(L, SteamNetworkingSockets_SteamAPI()->CloseListenSocket(hSocket));
    return 1;
}

// bool SetConnectionUserData(HSteamNetConnection hPeer, int64 nUserData);
EXTERN int luasteam_NetworkingSockets_SetConnectionUserData(lua_State *L) {
    HSteamNetConnection hPeer = static_cast<HSteamNetConnection>(luaL_checkint(L, 1));
    int64 nUserData = luasteam::checkuint64(L, 2);
    lua_pushboolean(L, SteamNetworkingSockets_SteamAPI()->SetConnectionUserData(hPeer, nUserData));
    return 1;
}

// int64 GetConnectionUserData(HSteamNetConnection hPeer);
EXTERN int luasteam_NetworkingSockets_GetConnectionUserData(lua_State *L) {
    HSteamNetConnection hPeer = static_cast<HSteamNetConnection>(luaL_checkint(L, 1));
    luasteam::pushuint64(L, SteamNetworkingSockets_SteamAPI()->GetConnectionUserData(hPeer));
    return 1;
}

// void SetConnectionName(HSteamNetConnection hPeer, const char * pszName);
EXTERN int luasteam_NetworkingSockets_SetConnectionName(lua_State *L) {
    HSteamNetConnection hPeer = static_cast<HSteamNetConnection>(luaL_checkint(L, 1));
    const char *pszName = luaL_checkstring(L, 2);
    SteamNetworkingSockets_SteamAPI()->SetConnectionName(hPeer, pszName);
    return 0;
}

// EResult FlushMessagesOnConnection(HSteamNetConnection hConn);
EXTERN int luasteam_NetworkingSockets_FlushMessagesOnConnection(lua_State *L) {
    HSteamNetConnection hConn = static_cast<HSteamNetConnection>(luaL_checkint(L, 1));
    lua_pushinteger(L, SteamNetworkingSockets_SteamAPI()->FlushMessagesOnConnection(hConn));
    return 1;
}

// ESteamNetworkingAvailability InitAuthentication();
EXTERN int luasteam_NetworkingSockets_InitAuthentication(lua_State *L) {
    lua_pushinteger(L, SteamNetworkingSockets_SteamAPI()->InitAuthentication());
    return 1;
}

// HSteamNetPollGroup CreatePollGroup();
EXTERN int luasteam_NetworkingSockets_CreatePollGroup(lua_State *L) {
    lua_pushinteger(L, SteamNetworkingSockets_SteamAPI()->CreatePollGroup());
    return 1;
}

// bool DestroyPollGroup(HSteamNetPollGroup hPollGroup);
EXTERN int luasteam_NetworkingSockets_DestroyPollGroup(lua_State *L) {
    HSteamNetPollGroup hPollGroup = static_cast<HSteamNetPollGroup>(luaL_checkint(L, 1));
    lua_pushboolean(L, SteamNetworkingSockets_SteamAPI()->DestroyPollGroup(hPollGroup));
    return 1;
}

// bool SetConnectionPollGroup(HSteamNetConnection hConn, HSteamNetPollGroup hPollGroup);
EXTERN int luasteam_NetworkingSockets_SetConnectionPollGroup(lua_State *L) {
    HSteamNetConnection hConn = static_cast<HSteamNetConnection>(luaL_checkint(L, 1));
    HSteamNetPollGroup hPollGroup = static_cast<HSteamNetPollGroup>(luaL_checkint(L, 2));
    lua_pushboolean(L, SteamNetworkingSockets_SteamAPI()->SetConnectionPollGroup(hConn, hPollGroup));
    return 1;
}

// uint16 GetHostedDedicatedServerPort();
EXTERN int luasteam_NetworkingSockets_GetHostedDedicatedServerPort(lua_State *L) {
    lua_pushinteger(L, SteamNetworkingSockets_SteamAPI()->GetHostedDedicatedServerPort());
    return 1;
}

// SteamNetworkingPOPID GetHostedDedicatedServerPOPID();
EXTERN int luasteam_NetworkingSockets_GetHostedDedicatedServerPOPID(lua_State *L) {
    lua_pushinteger(L, SteamNetworkingSockets_SteamAPI()->GetHostedDedicatedServerPOPID());
    return 1;
}

// void RunCallbacks();
EXTERN int luasteam_NetworkingSockets_RunCallbacks(lua_State *L) {
    SteamNetworkingSockets_SteamAPI()->RunCallbacks();
    return 0;
}

// bool BeginAsyncRequestFakeIP(int nNumPorts);
EXTERN int luasteam_NetworkingSockets_BeginAsyncRequestFakeIP(lua_State *L) {
    int nNumPorts = static_cast<int>(luaL_checkint(L, 1));
    lua_pushboolean(L, SteamNetworkingSockets_SteamAPI()->BeginAsyncRequestFakeIP(nNumPorts));
    return 1;
}

void register_NetworkingSockets_auto(lua_State *L) {
    add_func(L, "AcceptConnection", luasteam_NetworkingSockets_AcceptConnection);
    add_func(L, "CloseConnection", luasteam_NetworkingSockets_CloseConnection);
    add_func(L, "CloseListenSocket", luasteam_NetworkingSockets_CloseListenSocket);
    add_func(L, "SetConnectionUserData", luasteam_NetworkingSockets_SetConnectionUserData);
    add_func(L, "GetConnectionUserData", luasteam_NetworkingSockets_GetConnectionUserData);
    add_func(L, "SetConnectionName", luasteam_NetworkingSockets_SetConnectionName);
    add_func(L, "FlushMessagesOnConnection", luasteam_NetworkingSockets_FlushMessagesOnConnection);
    add_func(L, "InitAuthentication", luasteam_NetworkingSockets_InitAuthentication);
    add_func(L, "CreatePollGroup", luasteam_NetworkingSockets_CreatePollGroup);
    add_func(L, "DestroyPollGroup", luasteam_NetworkingSockets_DestroyPollGroup);
    add_func(L, "SetConnectionPollGroup", luasteam_NetworkingSockets_SetConnectionPollGroup);
    add_func(L, "GetHostedDedicatedServerPort", luasteam_NetworkingSockets_GetHostedDedicatedServerPort);
    add_func(L, "GetHostedDedicatedServerPOPID", luasteam_NetworkingSockets_GetHostedDedicatedServerPOPID);
    add_func(L, "RunCallbacks", luasteam_NetworkingSockets_RunCallbacks);
    add_func(L, "BeginAsyncRequestFakeIP", luasteam_NetworkingSockets_BeginAsyncRequestFakeIP);
}

void add_NetworkingSockets_auto(lua_State *L) {
    lua_createtable(L, 0, 15);
    register_NetworkingSockets_auto(L);
    lua_pushvalue(L, -1);
    NetworkingSockets_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "NetworkingSockets");
}

} // namespace luasteam
