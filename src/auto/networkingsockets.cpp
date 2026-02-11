#include "auto.hpp"

// bool CloseConnection(HSteamNetConnection hPeer, int nReason, const char * pszDebug, bool bEnableLinger);
EXTERN int luasteam_networkingsockets_SteamAPI_ISteamNetworkingSockets_CloseConnection(lua_State *L) {
    HSteamNetConnection hPeer = luaL_checkint(L, 1);
    int nReason = luaL_checkint(L, 2);
    const char *pszDebug = luaL_checkstring(L, 3);
    bool bEnableLinger = lua_toboolean(L, 4);
    lua_pushboolean(L, SteamNetworkingSockets()->CloseConnection(hPeer, nReason, pszDebug, bEnableLinger));
    return 1;
}

// bool CloseListenSocket(HSteamListenSocket hSocket);
EXTERN int luasteam_networkingsockets_SteamAPI_ISteamNetworkingSockets_CloseListenSocket(lua_State *L) {
    HSteamListenSocket hSocket = luaL_checkint(L, 1);
    lua_pushboolean(L, SteamNetworkingSockets()->CloseListenSocket(hSocket));
    return 1;
}

// void SetConnectionName(HSteamNetConnection hPeer, const char * pszName);
EXTERN int luasteam_networkingsockets_SteamAPI_ISteamNetworkingSockets_SetConnectionName(lua_State *L) {
    HSteamNetConnection hPeer = luaL_checkint(L, 1);
    const char *pszName = luaL_checkstring(L, 2);
    SteamNetworkingSockets()->SetConnectionName(hPeer, pszName);
    return 0;
}

// HSteamNetPollGroup CreatePollGroup();
EXTERN int luasteam_networkingsockets_SteamAPI_ISteamNetworkingSockets_CreatePollGroup(lua_State *L) {
    lua_pushinteger(L, SteamNetworkingSockets()->CreatePollGroup());
    return 1;
}

// bool DestroyPollGroup(HSteamNetPollGroup hPollGroup);
EXTERN int luasteam_networkingsockets_SteamAPI_ISteamNetworkingSockets_DestroyPollGroup(lua_State *L) {
    HSteamNetPollGroup hPollGroup = luaL_checkint(L, 1);
    lua_pushboolean(L, SteamNetworkingSockets()->DestroyPollGroup(hPollGroup));
    return 1;
}

// bool SetConnectionPollGroup(HSteamNetConnection hConn, HSteamNetPollGroup hPollGroup);
EXTERN int luasteam_networkingsockets_SteamAPI_ISteamNetworkingSockets_SetConnectionPollGroup(lua_State *L) {
    HSteamNetConnection hConn = luaL_checkint(L, 1);
    HSteamNetPollGroup hPollGroup = luaL_checkint(L, 2);
    lua_pushboolean(L, SteamNetworkingSockets()->SetConnectionPollGroup(hConn, hPollGroup));
    return 1;
}

// uint16 GetHostedDedicatedServerPort();
EXTERN int luasteam_networkingsockets_SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerPort(lua_State *L) {
    lua_pushinteger(L, SteamNetworkingSockets()->GetHostedDedicatedServerPort());
    return 1;
}

// SteamNetworkingPOPID GetHostedDedicatedServerPOPID();
EXTERN int luasteam_networkingsockets_SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerPOPID(lua_State *L) {
    lua_pushinteger(L, SteamNetworkingSockets()->GetHostedDedicatedServerPOPID());
    return 1;
}

// void RunCallbacks();
EXTERN int luasteam_networkingsockets_SteamAPI_ISteamNetworkingSockets_RunCallbacks(lua_State *L) {
    SteamNetworkingSockets()->RunCallbacks();
    return 0;
}

// bool BeginAsyncRequestFakeIP(int nNumPorts);
EXTERN int luasteam_networkingsockets_SteamAPI_ISteamNetworkingSockets_BeginAsyncRequestFakeIP(lua_State *L) {
    int nNumPorts = luaL_checkint(L, 1);
    lua_pushboolean(L, SteamNetworkingSockets()->BeginAsyncRequestFakeIP(nNumPorts));
    return 1;
}

namespace luasteam {

void add_networkingsockets_auto(lua_State *L) {
    add_func(L, "closeConnection", luasteam_networkingsockets_SteamAPI_ISteamNetworkingSockets_CloseConnection);
    add_func(L, "closeListenSocket", luasteam_networkingsockets_SteamAPI_ISteamNetworkingSockets_CloseListenSocket);
    add_func(L, "setConnectionName", luasteam_networkingsockets_SteamAPI_ISteamNetworkingSockets_SetConnectionName);
    add_func(L, "createPollGroup", luasteam_networkingsockets_SteamAPI_ISteamNetworkingSockets_CreatePollGroup);
    add_func(L, "destroyPollGroup", luasteam_networkingsockets_SteamAPI_ISteamNetworkingSockets_DestroyPollGroup);
    add_func(L, "setConnectionPollGroup", luasteam_networkingsockets_SteamAPI_ISteamNetworkingSockets_SetConnectionPollGroup);
    add_func(L, "getHostedDedicatedServerPort", luasteam_networkingsockets_SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerPort);
    add_func(L, "getHostedDedicatedServerPOPID", luasteam_networkingsockets_SteamAPI_ISteamNetworkingSockets_GetHostedDedicatedServerPOPID);
    add_func(L, "runCallbacks", luasteam_networkingsockets_SteamAPI_ISteamNetworkingSockets_RunCallbacks);
    add_func(L, "beginAsyncRequestFakeIP", luasteam_networkingsockets_SteamAPI_ISteamNetworkingSockets_BeginAsyncRequestFakeIP);
}

} // namespace luasteam
