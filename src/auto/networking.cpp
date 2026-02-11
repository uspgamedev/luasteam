#include "auto.hpp"

// bool AcceptP2PSessionWithUser(CSteamID steamIDRemote);
EXTERN int luasteam_networking_SteamAPI_ISteamNetworking_AcceptP2PSessionWithUser(lua_State *L) {
    CSteamID steamIDRemote(luasteam::checkuint64(L, 1));
    lua_pushboolean(L, SteamNetworking()->AcceptP2PSessionWithUser(steamIDRemote));
    return 1;
}

// bool CloseP2PSessionWithUser(CSteamID steamIDRemote);
EXTERN int luasteam_networking_SteamAPI_ISteamNetworking_CloseP2PSessionWithUser(lua_State *L) {
    CSteamID steamIDRemote(luasteam::checkuint64(L, 1));
    lua_pushboolean(L, SteamNetworking()->CloseP2PSessionWithUser(steamIDRemote));
    return 1;
}

// bool CloseP2PChannelWithUser(CSteamID steamIDRemote, int nChannel);
EXTERN int luasteam_networking_SteamAPI_ISteamNetworking_CloseP2PChannelWithUser(lua_State *L) {
    CSteamID steamIDRemote(luasteam::checkuint64(L, 1));
    int nChannel = static_cast<int>(luaL_checkint(L, 2));
    lua_pushboolean(L, SteamNetworking()->CloseP2PChannelWithUser(steamIDRemote, nChannel));
    return 1;
}

// bool AllowP2PPacketRelay(bool bAllow);
EXTERN int luasteam_networking_SteamAPI_ISteamNetworking_AllowP2PPacketRelay(lua_State *L) {
    bool bAllow = lua_toboolean(L, 1);
    lua_pushboolean(L, SteamNetworking()->AllowP2PPacketRelay(bAllow));
    return 1;
}

// SNetSocket_t CreateP2PConnectionSocket(CSteamID steamIDTarget, int nVirtualPort, int nTimeoutSec, bool bAllowUseOfPacketRelay);
EXTERN int luasteam_networking_SteamAPI_ISteamNetworking_CreateP2PConnectionSocket(lua_State *L) {
    CSteamID steamIDTarget(luasteam::checkuint64(L, 1));
    int nVirtualPort = static_cast<int>(luaL_checkint(L, 2));
    int nTimeoutSec = static_cast<int>(luaL_checkint(L, 3));
    bool bAllowUseOfPacketRelay = lua_toboolean(L, 4);
    lua_pushinteger(L, SteamNetworking()->CreateP2PConnectionSocket(steamIDTarget, nVirtualPort, nTimeoutSec, bAllowUseOfPacketRelay));
    return 1;
}

// bool DestroySocket(SNetSocket_t hSocket, bool bNotifyRemoteEnd);
EXTERN int luasteam_networking_SteamAPI_ISteamNetworking_DestroySocket(lua_State *L) {
    SNetSocket_t hSocket = static_cast<SNetSocket_t>(luaL_checkint(L, 1));
    bool bNotifyRemoteEnd = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamNetworking()->DestroySocket(hSocket, bNotifyRemoteEnd));
    return 1;
}

// bool DestroyListenSocket(SNetListenSocket_t hSocket, bool bNotifyRemoteEnd);
EXTERN int luasteam_networking_SteamAPI_ISteamNetworking_DestroyListenSocket(lua_State *L) {
    SNetListenSocket_t hSocket = static_cast<SNetListenSocket_t>(luaL_checkint(L, 1));
    bool bNotifyRemoteEnd = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamNetworking()->DestroyListenSocket(hSocket, bNotifyRemoteEnd));
    return 1;
}

// ESNetSocketConnectionType GetSocketConnectionType(SNetSocket_t hSocket);
EXTERN int luasteam_networking_SteamAPI_ISteamNetworking_GetSocketConnectionType(lua_State *L) {
    SNetSocket_t hSocket = static_cast<SNetSocket_t>(luaL_checkint(L, 1));
    lua_pushinteger(L, SteamNetworking()->GetSocketConnectionType(hSocket));
    return 1;
}

// int GetMaxPacketSize(SNetSocket_t hSocket);
EXTERN int luasteam_networking_SteamAPI_ISteamNetworking_GetMaxPacketSize(lua_State *L) {
    SNetSocket_t hSocket = static_cast<SNetSocket_t>(luaL_checkint(L, 1));
    lua_pushinteger(L, SteamNetworking()->GetMaxPacketSize(hSocket));
    return 1;
}

namespace luasteam {

void add_networking_auto(lua_State *L) {
    add_func(L, "acceptP2PSessionWithUser", luasteam_networking_SteamAPI_ISteamNetworking_AcceptP2PSessionWithUser);
    add_func(L, "closeP2PSessionWithUser", luasteam_networking_SteamAPI_ISteamNetworking_CloseP2PSessionWithUser);
    add_func(L, "closeP2PChannelWithUser", luasteam_networking_SteamAPI_ISteamNetworking_CloseP2PChannelWithUser);
    add_func(L, "allowP2PPacketRelay", luasteam_networking_SteamAPI_ISteamNetworking_AllowP2PPacketRelay);
    add_func(L, "createP2PConnectionSocket", luasteam_networking_SteamAPI_ISteamNetworking_CreateP2PConnectionSocket);
    add_func(L, "destroySocket", luasteam_networking_SteamAPI_ISteamNetworking_DestroySocket);
    add_func(L, "destroyListenSocket", luasteam_networking_SteamAPI_ISteamNetworking_DestroyListenSocket);
    add_func(L, "getSocketConnectionType", luasteam_networking_SteamAPI_ISteamNetworking_GetSocketConnectionType);
    add_func(L, "getMaxPacketSize", luasteam_networking_SteamAPI_ISteamNetworking_GetMaxPacketSize);
}

} // namespace luasteam
