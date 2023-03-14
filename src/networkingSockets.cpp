#include "networkingSockets.hpp"
#include "const.hpp"

// ======================================
// ======= SteamNetworkingSockets =======
// ======================================

typedef ISteamNetworkingSockets *(*SteamNetworkingSocketsLib)();
SteamNetworkingSocketsLib steamNetworkingSocketsLib;

namespace {

const char *steam_networking_connection_state[] = {
    "None", "Connecting", "FindingRoute", "Connected", "ClosedByPeer", "ProblemDetectedLocally", nullptr,
};

int sockets_ref = LUA_NOREF;

class CallbackListener;
CallbackListener *sockets_listener = nullptr;

class CallbackListener {
  private:
    STEAM_CALLBACK(CallbackListener, OnConnectionChanged, SteamNetConnectionStatusChangedCallback_t);
    STEAM_CALLBACK(CallbackListener, OnAuthenticationStatus, SteamNetAuthenticationStatus_t);
    STEAM_GAMESERVER_CALLBACK(CallbackListener, OnConnectionChangedServer, SteamNetConnectionStatusChangedCallback_t);
    STEAM_GAMESERVER_CALLBACK(CallbackListener, OnAuthenticationStatusServer, SteamNetAuthenticationStatus_t);
};

void connectionChanged(SteamNetConnectionStatusChangedCallback_t *data) {
    if (data == nullptr) {
        return;
    }
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) {
        return;
    }
    lua_rawgeti(L, LUA_REGISTRYINDEX, sockets_ref);
    lua_getfield(L, -1, "onConnectionChanged");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushstring(L, steam_networking_connection_state[data->m_info.m_eState]);
        lua_setfield(L, -2, "state");
        lua_pushstring(L, steam_networking_connection_state[data->m_eOldState]);
        lua_setfield(L, -2, "state_old");
        lua_pushinteger(L, data->m_info.m_eEndReason);
        lua_setfield(L, -2, "endReason");
        lua_pushstring(L, data->m_info.m_szEndDebug);
        lua_setfield(L, -2, "debug");
        lua_pushinteger(L, data->m_hConn);
        lua_setfield(L, -2, "connection");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnConnectionChangedServer(SteamNetConnectionStatusChangedCallback_t *data) { connectionChanged(data); }

void CallbackListener::OnConnectionChanged(SteamNetConnectionStatusChangedCallback_t *data) { connectionChanged(data); }

void authStatus(SteamNetAuthenticationStatus_t *data) {
    if (data == nullptr) {
        return;
    }
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) {
        return;
    }
    lua_rawgeti(L, LUA_REGISTRYINDEX, sockets_ref);
    lua_getfield(L, -1, "onAuthenticationStatus");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushinteger(L, data->m_eAvail);
        lua_setfield(L, -2, "status");
        lua_pushstring(L, data->m_debugMsg);
        lua_setfield(L, -2, "debugMsg");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnAuthenticationStatus(SteamNetAuthenticationStatus_t *data) { authStatus(data); }

void CallbackListener::OnAuthenticationStatusServer(SteamNetAuthenticationStatus_t *data) { authStatus(data); }

} // namespace

int parseConfig(lua_State *L, SteamNetworkingConfigValue_t **pOptions) {

    if (!lua_istable(L, -1)) {
        return 0;
    }

    int count = 0;
    lua_pushnil(L);
    while (lua_next(L, -2)) {
        count++;
        lua_pop(L, 1);
    }

    *pOptions = new SteamNetworkingConfigValue_t[count];
    lua_pushnil(L);
    int current = 0;
    while (lua_next(L, -2)) {

        const char *key = luaL_checkstring(L, -2);
        int value = luaL_checkinteger(L, -1);

        if (strcmp(key, "TimeoutInitial") == 0) {
            (*pOptions)[current].SetInt32(ESteamNetworkingConfigValue::k_ESteamNetworkingConfig_TimeoutInitial, value);
            current++;
        } else if (strcmp(key, "TimeoutConnected") == 0) {
            (*pOptions)[current].SetInt32(ESteamNetworkingConfigValue::k_ESteamNetworkingConfig_TimeoutConnected, value);
            current++;
        } else if (strcmp(key, "SendBufferSize") == 0) {
            (*pOptions)[current].SetInt32(ESteamNetworkingConfigValue::k_ESteamNetworkingConfig_SendBufferSize, value);
            current++;
        } else if (strcmp(key, "SendRateMin") == 0) {
            (*pOptions)[current].SetInt32(ESteamNetworkingConfigValue::k_ESteamNetworkingConfig_SendRateMin, value);
            current++;
        } else if (strcmp(key, "SendRateMax") == 0) {
            (*pOptions)[current].SetInt32(ESteamNetworkingConfigValue::k_ESteamNetworkingConfig_SendRateMax, value);
            current++;
        } else if (strcmp(key, "NagleTime") == 0) {
            (*pOptions)[current].SetInt32(ESteamNetworkingConfigValue::k_ESteamNetworkingConfig_NagleTime, value);
            current++;
        } else if (strcmp(key, "IP_AllowWithoutAuth") == 0) {
            (*pOptions)[current].SetInt32(ESteamNetworkingConfigValue::k_ESteamNetworkingConfig_IP_AllowWithoutAuth, value);
            current++;
        } else if (strcmp(key, "MTU_PacketSize") == 0) {
            (*pOptions)[current].SetInt32(ESteamNetworkingConfigValue::k_ESteamNetworkingConfig_MTU_PacketSize, value);
            current++;
        } else if (strcmp(key, "Unencrypted") == 0) {
            (*pOptions)[current].SetInt32(ESteamNetworkingConfigValue::k_ESteamNetworkingConfig_Unencrypted, value);
            current++;
        } else if (strcmp(key, "SymmetricConnect") == 0) {
            (*pOptions)[current].SetInt32(ESteamNetworkingConfigValue::k_ESteamNetworkingConfig_SymmetricConnect, value);
            current++;
        } else if (strcmp(key, "LocalVirtualPort") == 0) {
            (*pOptions)[current].SetInt32(ESteamNetworkingConfigValue::k_ESteamNetworkingConfig_LocalVirtualPort, value);
            current++;
        } else {
            fprintf(stderr, "Unsupported/Unknown config option [ %s = %d ]\n", key, value);
        }

        lua_pop(L, 1);
    }
    return current;
}

// HSteamListenSocket CreateListenSocketIP( const SteamNetworkingIPAddr &localAddress, int nOptions, const SteamNetworkingConfigValue_t *pOptions )
EXTERN int luasteam_createListenSocketIP(lua_State *L) {
    SteamNetworkingIPAddr localAdress;
    localAdress.ParseString(luaL_checkstring(L, 1));
    SteamNetworkingConfigValue_t *pOptions = nullptr;
    int nOptions = parseConfig(L, &pOptions);
    HSteamListenSocket connectingSocket = steamNetworkingSocketsLib()->CreateListenSocketIP(localAdress, nOptions, pOptions);
    lua_pushlightuserdata(L, &connectingSocket);
    return 1;
}

// HSteamNetConnection ConnectByIPAddress( const SteamNetworkingIPAddr &address, int nOptions, const SteamNetworkingConfigValue_t *pOptions )
EXTERN int luasteam_connectByIPAddress(lua_State *L) {
    SteamNetworkingIPAddr address;
    address.ParseString(luaL_checkstring(L, 1));
    SteamNetworkingConfigValue_t *pOptions = nullptr;
    int nOptions = parseConfig(L, &pOptions);
    HSteamNetConnection connection = steamNetworkingSocketsLib()->ConnectByIPAddress(address, nOptions, pOptions);
    lua_pushinteger(L, connection);
    return 1;
}

// HSteamListenSocket CreateListenSocketP2P( int nVirtualPort, int nOptions, const SteamNetworkingConfigValue_t *pOptions )
EXTERN int luasteam_createListenSocketP2P(lua_State *L) {
    int nVirtualPort = luaL_checkinteger(L, 1);
    SteamNetworkingConfigValue_t *pOptions = nullptr;
    int nOptions = parseConfig(L, &pOptions);
    HSteamListenSocket connectingSocket = steamNetworkingSocketsLib()->CreateListenSocketP2P(nVirtualPort, nOptions, pOptions);
    lua_pushlightuserdata(L, &connectingSocket);
    return 1;
}

// HSteamNetConnection ConnectP2P( const SteamNetworkingIdentity &identityRemote, int nVirtualPort, int nOptions, const SteamNetworkingConfigValue_t *pOptions )
EXTERN int luasteam_connectP2P(lua_State *L) {
    SteamNetworkingIdentity identityRemote;
    CSteamID id(luasteam::checkuint64(L, 1));
    identityRemote.SetSteamID(id);
    int nVirtualPort = luaL_checkinteger(L, 2);
    SteamNetworkingConfigValue_t *pOptions = nullptr;
    int nOptions = parseConfig(L, &pOptions);
    HSteamNetConnection connection = steamNetworkingSocketsLib()->ConnectP2P(identityRemote, nVirtualPort, nOptions, pOptions);
    lua_pushinteger(L, connection);
    return 1;
}

// EResult AcceptConnection( HSteamNetConnection hConn )
EXTERN int luasteam_acceptConnection(lua_State *L) {
    HSteamNetConnection hConn = luaL_checkinteger(L, 1);
    EResult result = steamNetworkingSocketsLib()->AcceptConnection(hConn);
    lua_pushstring(L, steam_result_code[result]);
    return 1;
}

// CloseConnection( HSteamNetConnection hPeer, int nReason, const char *pszDebug, bool bEnableLinger )
EXTERN int luasteam_closeConnection(lua_State *L) {
    HSteamNetConnection hConn = luaL_checkinteger(L, 1);
    bool bEnableLinger = lua_toboolean(L, 2);
    steamNetworkingSocketsLib()->CloseConnection(hConn, 0, nullptr, bEnableLinger);
    return 0;
}

// CloseListenSocket( HSteamListenSocket hSocket )
EXTERN int luasteam_closeListenSocket(lua_State *L) {
    bool is_user_data = lua_islightuserdata(L, 1) == 1;
    if (is_user_data) {
        HSteamListenSocket *connectingSocket = (HSteamListenSocket *)lua_touserdata(L, 1);
        steamNetworkingSocketsLib()->CloseListenSocket(*connectingSocket);
    }
    return 0;
}

// SendMessageToConnection( HSteamNetConnection hConn, const void *pData, uint32 cbData, int nSendFlags, int64 *pOutMessageNumber )
EXTERN int luasteam_sendMessageToConnection(lua_State *L) {
    HSteamNetConnection hConn = luaL_checkinteger(L, 1);
    size_t len;
    const char *data = luaL_checklstring(L, 2, &len);
    int nSendFlags = luaL_checkinteger(L, 3);
    EResult result = steamNetworkingSocketsLib()->SendMessageToConnection(hConn, data, len, nSendFlags, nullptr);
    lua_pushstring(L, steam_result_code[result]);
    return 1;
}

// ReceiveMessagesOnConnection( HSteamNetConnection hConn, SteamNetworkingMessage_t **ppOutMessages, int nMaxMessages )
EXTERN int luasteam_receiveMessagesOnConnection(lua_State *L) {
    HSteamNetConnection hConn = luaL_checkinteger(L, 1);

    SteamNetworkingMessage_t *msgs[32];
    int numMessages = steamNetworkingSocketsLib()->ReceiveMessagesOnConnection(hConn, msgs, 32);

    lua_createtable(L, 0, numMessages);
    if (numMessages > 0) {
        int current = 1;
        for (int i = 0; i < numMessages; i++) {
            SteamNetworkingMessage_t *message = msgs[i];
            uint32 messageSize = message->GetSize();

            if (messageSize > 0) {
                lua_pushlstring(L, (char *)message->GetData(), messageSize);
                lua_rawseti(L, -2, current);
                current++;
            }
            message->Release();
        }
    }
    return 1;
}

// ESteamNetworkingAvailability InitAuthentication()
EXTERN int luasteam_initAuthentication(lua_State *L) {
    ESteamNetworkingAvailability result = steamNetworkingSocketsLib()->InitAuthentication();
    lua_pushinteger(L, result);
    return 1;
}

// ESteamNetworkingAvailability GetAuthenticationStatus( SteamNetAuthenticationStatus_t *pDetails )
EXTERN int luasteam_getAuthenticationStatus(lua_State *L) {
    SteamNetAuthenticationStatus_t *pDetails = new SteamNetAuthenticationStatus_t();
    ESteamNetworkingAvailability result = steamNetworkingSocketsLib()->GetAuthenticationStatus(pDetails);
    lua_pushinteger(L, result);
    lua_pushstring(L, pDetails->m_debugMsg);
    return 2;
}

// GetConnectionInfo( HSteamNetConnection hConn, SteamNetConnectionInfo_t *pInfo )
EXTERN int luasteam_getConnectionInfo(lua_State *L) {
    HSteamNetConnection hConn = luaL_checkinteger(L, 1);
    SteamNetConnectionInfo_t *pInfo = new SteamNetConnectionInfo_t();
    bool result = steamNetworkingSocketsLib()->GetConnectionInfo(hConn, pInfo);
    lua_pushstring(L, steam_result_code[result]);
    lua_pushstring(L, pInfo->m_szConnectionDescription);
    return 2;
}

// bool GetIdentity( SteamNetworkingIdentity *pIdentity )
EXTERN int luasteam_getIdentity(lua_State *L) {
    SteamNetworkingIdentity *pIdentity = new SteamNetworkingIdentity();
    bool result = steamNetworkingSocketsLib()->GetIdentity(pIdentity);
    if (!result || pIdentity->m_eType != ESteamNetworkingIdentityType::k_ESteamNetworkingIdentityType_SteamID) {
        return 0;
    }
    luasteam::pushuint64(L, pIdentity->GetSteamID().ConvertToUint64());
    return 1;
}

// HSteamNetPollGroup CreatePollGroup()
EXTERN int luasteam_createPollGroup(lua_State *L) {
    HSteamNetPollGroup pollGroup = steamNetworkingSocketsLib()->CreatePollGroup();
    lua_pushinteger(L, pollGroup);
    return 1;
}

// DestroyPollGroup( HSteamNetPollGroup hPollGroup )
EXTERN int luasteam_destroyPollGroup(lua_State *L) {
    HSteamNetPollGroup hPollGroup = luaL_checkinteger(L, 1);
    bool result = steamNetworkingSocketsLib()->DestroyPollGroup(hPollGroup);
    lua_pushboolean(L, result);
    return 1;
}

// SetConnectionPollGroup( HSteamNetConnection hConn, HSteamNetPollGroup hPollGroup )
EXTERN int luasteam_setConnectionPollGroup(lua_State *L) {
    HSteamNetConnection hConn = luaL_checkinteger(L, 1);
    HSteamNetPollGroup hPollGroup = luaL_checkinteger(L, 2);
    bool result = steamNetworkingSocketsLib()->SetConnectionPollGroup(hConn, hPollGroup);
    lua_pushboolean(L, result);
    return 1;
}

// int ReceiveMessagesOnPollGroup( HSteamNetPollGroup hPollGroup, SteamNetworkingMessage_t **ppOutMessages, int nMaxMessages )
EXTERN int luasteam_receiveMessagesOnPollGroup(lua_State *L) {
    HSteamNetPollGroup hPollGroup = luaL_checkinteger(L, 1);

    SteamNetworkingMessage_t *msgs[32];
    int numMessages = steamNetworkingSocketsLib()->ReceiveMessagesOnPollGroup(hPollGroup, msgs, 32);

    lua_createtable(L, 0, numMessages);
    if (numMessages > 0) {
        int current = 1;
        for (int i = 0; i < numMessages; i++) {
            SteamNetworkingMessage_t *message = msgs[i];
            uint32 messageSize = message->GetSize();

            if (messageSize > 0) {
                lua_createtable(L, 0, 2);
                lua_pushlstring(L, (char *)message->GetData(), messageSize);
                lua_setfield(L, -2, "msg");
                lua_pushinteger(L, message->m_conn);
                lua_setfield(L, -2, "conn");
                lua_rawseti(L, -2, current);
                current++;
            }
            message->Release();
        }
    }
    return 1;
}

// FlushMessagesOnConnection( HSteamNetConnection hConn )
EXTERN int luasteam_flushMessagesOnConnection(lua_State *L) {
    HSteamNetConnection hConn = luaL_checkinteger(L, 1);
    EResult result = steamNetworkingSocketsLib()->FlushMessagesOnConnection(hConn);
    lua_pushstring(L, steam_result_code[result]);
    return 1;
}

// void SendMessages( int nMessages, SteamNetworkingMessage_t *const *pMessages, int64 *pOutMessageNumberOrResult )
EXTERN int luasteam_sendMessages(lua_State *L) {
    int nMessages = luaL_checkinteger(L, 1);
    int64 *pOutMessageNumberOrResult = new int64[nMessages];
    SteamNetworkingMessage_t **pMessages = new SteamNetworkingMessage_t *[nMessages];
    for (int i = 0; i < nMessages; i++) {
        lua_rawgeti(L, 2, i + 1);

        lua_getfield(L, -1, "conn");
        HSteamNetConnection hConn = luaL_checkinteger(L, -1);
        lua_pop(L, 1);

        lua_getfield(L, -1, "flag");
        int sendType = luaL_checkinteger(L, -1);
        lua_pop(L, 1);

        lua_getfield(L, -1, "msg");
        size_t len = 0;
        const char *msg = lua_tolstring(L, -1, &len);

        pMessages[i] = SteamNetworkingUtils()->AllocateMessage(len);
        memcpy(pMessages[i]->m_pData, msg, len);
        pMessages[i]->m_conn = hConn;
        pMessages[i]->m_nFlags = sendType;
        lua_pop(L, 1);
    }
    steamNetworkingSocketsLib()->SendMessages(nMessages, pMessages, pOutMessageNumberOrResult);
    lua_createtable(L, 0, nMessages);
    for (int i = 0; i < nMessages; i++) {
        lua_pushboolean(L, pOutMessageNumberOrResult[i] > 0);
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

namespace luasteam {

void add_constants(lua_State *L) {
    lua_createtable(L, 0, 5);
    lua_pushnumber(L, k_nSteamNetworkingSend_Unreliable);
    lua_setfield(L, -2, "Send_Unreliable");
    lua_pushnumber(L, k_nSteamNetworkingSend_UnreliableNoNagle);
    lua_setfield(L, -2, "Send_UnreliableNoNagle");
    lua_pushnumber(L, k_nSteamNetworkingSend_UnreliableNoDelay);
    lua_setfield(L, -2, "Send_UnreliableNoDelay");
    lua_pushnumber(L, k_nSteamNetworkingSend_Reliable);
    lua_setfield(L, -2, "Send_Reliable");
    lua_pushnumber(L, k_nSteamNetworkingSend_ReliableNoNagle);
    lua_setfield(L, -2, "Send_ReliableNoNagle");
    lua_setfield(L, -2, "flags");
}

void add_networkingSockets(lua_State *L) {
    lua_createtable(L, 0, 20);
    add_func(L, "createListenSocketIP", luasteam_createListenSocketIP);
    add_func(L, "createListenSocketP2P", luasteam_createListenSocketP2P);
    add_func(L, "connectByIPAddress", luasteam_connectByIPAddress);
    add_func(L, "connectP2P", luasteam_connectP2P);
    add_func(L, "acceptConnection", luasteam_acceptConnection);
    add_func(L, "closeConnection", luasteam_closeConnection);
    add_func(L, "closeListenSocket", luasteam_closeListenSocket);
    add_func(L, "sendMessageToConnection", luasteam_sendMessageToConnection);
    add_func(L, "receiveMessagesOnConnection", luasteam_receiveMessagesOnConnection);
    add_func(L, "initAuthentication", luasteam_initAuthentication);
    add_func(L, "getAuthenticationStatus", luasteam_getAuthenticationStatus);
    add_func(L, "getConnectionInfo", luasteam_getConnectionInfo);
    add_func(L, "getIdentity", luasteam_getIdentity);
    add_func(L, "createPollGroup", luasteam_createPollGroup);
    add_func(L, "destroyPollGroup", luasteam_destroyPollGroup);
    add_func(L, "setConnectionPollGroup", luasteam_setConnectionPollGroup);
    add_func(L, "receiveMessagesOnPollGroup", luasteam_receiveMessagesOnPollGroup);
    add_func(L, "flushMessagesOnConnection", luasteam_flushMessagesOnConnection);
    add_func(L, "sendMessages", luasteam_sendMessages);
    add_constants(L);
    lua_pushvalue(L, -1);
    sockets_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "networkingSockets");
}

void init_networkingSockets(lua_State *L) {
    steamNetworkingSocketsLib = &SteamNetworkingSockets;
    sockets_listener = new CallbackListener();
}

void init_networkingSockets_server(lua_State *L) {
    steamNetworkingSocketsLib = &SteamGameServerNetworkingSockets;
    sockets_listener = new CallbackListener();
}

void shutdown_networkingSockets(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, sockets_ref);
    sockets_ref = LUA_NOREF;

    delete sockets_listener;
    sockets_listener = nullptr;
}

} // namespace luasteam
