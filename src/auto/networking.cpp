#include "auto.hpp"

namespace luasteam {

int Networking_ref = LUA_NOREF;

namespace {

class CallbackListener {
  private:
    STEAM_CALLBACK(CallbackListener, OnP2PSessionRequest, P2PSessionRequest_t);
    STEAM_CALLBACK(CallbackListener, OnP2PSessionConnectFail, P2PSessionConnectFail_t);
    STEAM_CALLBACK(CallbackListener, OnSocketStatusCallback, SocketStatusCallback_t);
};

void CallbackListener::OnP2PSessionRequest(P2PSessionRequest_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Networking_ref);
    lua_getfield(L, -1, "OnP2PSessionRequest");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        luasteam::pushuint64(L, data->m_steamIDRemote.ConvertToUint64());
        lua_setfield(L, -2, "m_steamIDRemote");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnP2PSessionConnectFail(P2PSessionConnectFail_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Networking_ref);
    lua_getfield(L, -1, "OnP2PSessionConnectFail");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        luasteam::pushuint64(L, data->m_steamIDRemote.ConvertToUint64());
        lua_setfield(L, -2, "m_steamIDRemote");
        lua_pushinteger(L, data->m_eP2PSessionError);
        lua_setfield(L, -2, "m_eP2PSessionError");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnSocketStatusCallback(SocketStatusCallback_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Networking_ref);
    lua_getfield(L, -1, "OnSocketStatusCallback");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        lua_pushinteger(L, data->m_hSocket);
        lua_setfield(L, -2, "m_hSocket");
        lua_pushinteger(L, data->m_hListenSocket);
        lua_setfield(L, -2, "m_hListenSocket");
        luasteam::pushuint64(L, data->m_steamIDRemote.ConvertToUint64());
        lua_setfield(L, -2, "m_steamIDRemote");
        lua_pushinteger(L, data->m_eSNetSocketState);
        lua_setfield(L, -2, "m_eSNetSocketState");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

CallbackListener *Networking_listener = nullptr;

} // namespace

void init_Networking_auto(lua_State *L) { Networking_listener = new CallbackListener(); }

void shutdown_Networking_auto(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, Networking_ref);
    Networking_ref = LUA_NOREF;
    delete Networking_listener; Networking_listener = nullptr;
}


// bool AcceptP2PSessionWithUser(CSteamID steamIDRemote);
EXTERN int luasteam_Networking_AcceptP2PSessionWithUser(lua_State *L) {
    CSteamID steamIDRemote(luasteam::checkuint64(L, 1));
    lua_pushboolean(L, SteamNetworking()->AcceptP2PSessionWithUser(steamIDRemote));
    return 1;
}

// bool CloseP2PSessionWithUser(CSteamID steamIDRemote);
EXTERN int luasteam_Networking_CloseP2PSessionWithUser(lua_State *L) {
    CSteamID steamIDRemote(luasteam::checkuint64(L, 1));
    lua_pushboolean(L, SteamNetworking()->CloseP2PSessionWithUser(steamIDRemote));
    return 1;
}

// bool CloseP2PChannelWithUser(CSteamID steamIDRemote, int nChannel);
EXTERN int luasteam_Networking_CloseP2PChannelWithUser(lua_State *L) {
    CSteamID steamIDRemote(luasteam::checkuint64(L, 1));
    int nChannel = static_cast<int>(luaL_checkint(L, 2));
    lua_pushboolean(L, SteamNetworking()->CloseP2PChannelWithUser(steamIDRemote, nChannel));
    return 1;
}

// bool AllowP2PPacketRelay(bool bAllow);
EXTERN int luasteam_Networking_AllowP2PPacketRelay(lua_State *L) {
    bool bAllow = lua_toboolean(L, 1);
    lua_pushboolean(L, SteamNetworking()->AllowP2PPacketRelay(bAllow));
    return 1;
}

// SNetSocket_t CreateP2PConnectionSocket(CSteamID steamIDTarget, int nVirtualPort, int nTimeoutSec, bool bAllowUseOfPacketRelay);
EXTERN int luasteam_Networking_CreateP2PConnectionSocket(lua_State *L) {
    CSteamID steamIDTarget(luasteam::checkuint64(L, 1));
    int nVirtualPort = static_cast<int>(luaL_checkint(L, 2));
    int nTimeoutSec = static_cast<int>(luaL_checkint(L, 3));
    bool bAllowUseOfPacketRelay = lua_toboolean(L, 4);
    lua_pushinteger(L, SteamNetworking()->CreateP2PConnectionSocket(steamIDTarget, nVirtualPort, nTimeoutSec, bAllowUseOfPacketRelay));
    return 1;
}

// bool DestroySocket(SNetSocket_t hSocket, bool bNotifyRemoteEnd);
EXTERN int luasteam_Networking_DestroySocket(lua_State *L) {
    SNetSocket_t hSocket = static_cast<SNetSocket_t>(luaL_checkint(L, 1));
    bool bNotifyRemoteEnd = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamNetworking()->DestroySocket(hSocket, bNotifyRemoteEnd));
    return 1;
}

// bool DestroyListenSocket(SNetListenSocket_t hSocket, bool bNotifyRemoteEnd);
EXTERN int luasteam_Networking_DestroyListenSocket(lua_State *L) {
    SNetListenSocket_t hSocket = static_cast<SNetListenSocket_t>(luaL_checkint(L, 1));
    bool bNotifyRemoteEnd = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamNetworking()->DestroyListenSocket(hSocket, bNotifyRemoteEnd));
    return 1;
}

// bool IsDataAvailableOnSocket(SNetSocket_t hSocket, uint32 * pcubMsgSize);
EXTERN int luasteam_Networking_IsDataAvailableOnSocket(lua_State *L) {
    SNetSocket_t hSocket = static_cast<SNetSocket_t>(luaL_checkint(L, 1));
    uint32 pcubMsgSize;    lua_pushboolean(L, SteamNetworking()->IsDataAvailableOnSocket(hSocket, &pcubMsgSize));
    lua_pushinteger(L, pcubMsgSize);
    return 2;
}

// bool IsDataAvailable(SNetListenSocket_t hListenSocket, uint32 * pcubMsgSize, SNetSocket_t * phSocket);
EXTERN int luasteam_Networking_IsDataAvailable(lua_State *L) {
    SNetListenSocket_t hListenSocket = static_cast<SNetListenSocket_t>(luaL_checkint(L, 1));
    uint32 pcubMsgSize;    SNetSocket_t phSocket;    lua_pushboolean(L, SteamNetworking()->IsDataAvailable(hListenSocket, &pcubMsgSize, &phSocket));
    lua_pushinteger(L, pcubMsgSize);
    lua_pushinteger(L, phSocket);
    return 3;
}

// ESNetSocketConnectionType GetSocketConnectionType(SNetSocket_t hSocket);
EXTERN int luasteam_Networking_GetSocketConnectionType(lua_State *L) {
    SNetSocket_t hSocket = static_cast<SNetSocket_t>(luaL_checkint(L, 1));
    lua_pushinteger(L, SteamNetworking()->GetSocketConnectionType(hSocket));
    return 1;
}

// int GetMaxPacketSize(SNetSocket_t hSocket);
EXTERN int luasteam_Networking_GetMaxPacketSize(lua_State *L) {
    SNetSocket_t hSocket = static_cast<SNetSocket_t>(luaL_checkint(L, 1));
    lua_pushinteger(L, SteamNetworking()->GetMaxPacketSize(hSocket));
    return 1;
}

void register_Networking_auto(lua_State *L) {
    add_func(L, "AcceptP2PSessionWithUser", luasteam_Networking_AcceptP2PSessionWithUser);
    add_func(L, "CloseP2PSessionWithUser", luasteam_Networking_CloseP2PSessionWithUser);
    add_func(L, "CloseP2PChannelWithUser", luasteam_Networking_CloseP2PChannelWithUser);
    add_func(L, "AllowP2PPacketRelay", luasteam_Networking_AllowP2PPacketRelay);
    add_func(L, "CreateP2PConnectionSocket", luasteam_Networking_CreateP2PConnectionSocket);
    add_func(L, "DestroySocket", luasteam_Networking_DestroySocket);
    add_func(L, "DestroyListenSocket", luasteam_Networking_DestroyListenSocket);
    add_func(L, "IsDataAvailableOnSocket", luasteam_Networking_IsDataAvailableOnSocket);
    add_func(L, "IsDataAvailable", luasteam_Networking_IsDataAvailable);
    add_func(L, "GetSocketConnectionType", luasteam_Networking_GetSocketConnectionType);
    add_func(L, "GetMaxPacketSize", luasteam_Networking_GetMaxPacketSize);
}

void add_Networking_auto(lua_State *L) {
    lua_createtable(L, 0, 11);
    register_Networking_auto(L);
    lua_pushvalue(L, -1);
    Networking_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "Networking");
}

} // namespace luasteam
