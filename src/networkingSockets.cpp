#include "networkingSockets.hpp"

// ======================================
// ======= SteamNetworkingSockets =======
// ======================================

typedef ISteamNetworkingSockets *(*SteamNetworkingSocketsLib)();
SteamNetworkingSocketsLib steamNetworkingSocketsLib;

namespace {

// ESteamNetworkingConnectionState
const char *steam_networking_connection_state[] = {
    "None", "Connecting", "FindingRoute", "Connected", "ClosedByPeer", "ProblemDetectedLocally", nullptr,
};

const char *steam_networking_config_scopes[] = {
    "Invalid", "Global", "SocketsInterface", "ListenSocket", "Connection", nullptr,
};

const char *steam_networking_config_datatype[] = {
    "Invalid", "Int32", "Int64", "Float", "String", "Ptr", nullptr,
};

int sockets_ref = LUA_NOREF;

class CallbackListener;
CallbackListener *connection_listener = nullptr;
CallbackListener *auth_listener = nullptr;

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

void CallbackListener::OnConnectionChangedServer(SteamNetConnectionStatusChangedCallback_t *data) {
    connectionChanged(data);
}

void CallbackListener::OnConnectionChanged(SteamNetConnectionStatusChangedCallback_t *data) {
    connectionChanged(data);
}

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

void CallbackListener::OnAuthenticationStatus(SteamNetAuthenticationStatus_t *data) {
    authStatus(data);
}

void CallbackListener::OnAuthenticationStatusServer(SteamNetAuthenticationStatus_t *data) {
    authStatus(data);
}

} // namespace

SteamNetworkingConfigValue_t* parseConfig(lua_State *L) {
    // TODO read options from state
    SteamNetworkingConfigValue_t *pOptions = new SteamNetworkingConfigValue_t[2];
    pOptions[0].SetInt32(ESteamNetworkingConfigValue::k_ESteamNetworkingConfig_IP_AllowWithoutAuth, 1);
    pOptions[1].SetInt32(ESteamNetworkingConfigValue::k_ESteamNetworkingConfig_Unencrypted, 2);
    return pOptions;
}

void printConfig() { // todo clean up and hook up to lua
    ESteamNetworkingConfigValue value = SteamNetworkingUtils()->IterateGenericEditableConfigValues( ESteamNetworkingConfigValue::k_ESteamNetworkingConfig_Invalid, true);
        fprintf(stderr, "### Printing config ###\n");
    while( value != ESteamNetworkingConfigValue::k_ESteamNetworkingConfig_Invalid ) {
        ESteamNetworkingConfigDataType *pOutDataType = new ESteamNetworkingConfigDataType();
		ESteamNetworkingConfigScope *pOutScope = new ESteamNetworkingConfigScope();
        const char * result = SteamNetworkingUtils()->GetConfigValueInfo(value, pOutDataType, pOutScope);
        if (result != NULL) {
            fprintf(stderr, "%s %s %s\n", steam_networking_config_scopes[*pOutScope], result, steam_networking_config_datatype[*pOutDataType]);
        }
        value = SteamNetworkingUtils()->IterateGenericEditableConfigValues(value, true);
    }
}

// HSteamListenSocket CreateListenSocketIP( const SteamNetworkingIPAddr &localAddress, int nOptions, const SteamNetworkingConfigValue_t *pOptions )
EXTERN int luasteam_createListenSocketIP(lua_State *L) {
    SteamNetworkingIPAddr localAdress;
    localAdress.ParseString(luaL_checkstring(L, 1));
    SteamNetworkingConfigValue_t* pOptions = parseConfig(L);
    HSteamListenSocket connectingSocket = steamNetworkingSocketsLib()->CreateListenSocketIP(localAdress, 0, pOptions);

    // DEBUG START disable certificates and encryption
    SteamNetworkingConfigValue_t noauth = SteamNetworkingConfigValue_t();
    noauth.SetInt32(ESteamNetworkingConfigValue::k_ESteamNetworkingConfig_IP_AllowWithoutAuth, 1);    
    SteamNetworkingUtils()->SetConfigValueStruct(noauth, ESteamNetworkingConfigScope::k_ESteamNetworkingConfig_ListenSocket, connectingSocket);

    SteamNetworkingConfigValue_t unencrypted = SteamNetworkingConfigValue_t();
    unencrypted.SetInt32(ESteamNetworkingConfigValue::k_ESteamNetworkingConfig_Unencrypted, 2);    
    SteamNetworkingUtils()->SetConfigValueStruct(unencrypted, ESteamNetworkingConfigScope::k_ESteamNetworkingConfig_ListenSocket, connectingSocket);
    // DEBUG END

    lua_pushlightuserdata(L, &connectingSocket);
    return 1;
}

// HSteamNetConnection ConnectByIPAddress( const SteamNetworkingIPAddr &address, int nOptions, const SteamNetworkingConfigValue_t *pOptions )
EXTERN int luasteam_connectByIPAddress(lua_State *L) {
    SteamNetworkingIPAddr address;
    address.ParseString(luaL_checkstring(L, 1));
    SteamNetworkingConfigValue_t* pOptions = parseConfig(L);
    HSteamListenSocket connectingSocket = steamNetworkingSocketsLib()->ConnectByIPAddress(address, 0, pOptions);

    // DEBUG START disable certificates and encryption
    SteamNetworkingConfigValue_t noauth = SteamNetworkingConfigValue_t();
    noauth.SetInt32(ESteamNetworkingConfigValue::k_ESteamNetworkingConfig_IP_AllowWithoutAuth, 1);    
    SteamNetworkingUtils()->SetConfigValueStruct(noauth, ESteamNetworkingConfigScope::k_ESteamNetworkingConfig_ListenSocket, connectingSocket);

    SteamNetworkingConfigValue_t unencrypted = SteamNetworkingConfigValue_t();
    unencrypted.SetInt32(ESteamNetworkingConfigValue::k_ESteamNetworkingConfig_Unencrypted, 2);    
    SteamNetworkingUtils()->SetConfigValueStruct(unencrypted, ESteamNetworkingConfigScope::k_ESteamNetworkingConfig_ListenSocket, connectingSocket);
    // DEBUG END

    lua_pushlightuserdata(L, &connectingSocket);
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
        for (int i = 0; i < numMessages; i++) {
            SteamNetworkingMessage_t *message = msgs[i];
            uint32 messageSize = message->GetSize();

            if (messageSize > 0) {
                lua_pushlstring(L, (char *)message->GetData(), messageSize);
                lua_rawseti(L, -2, i + 1);
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
    lua_createtable(L, 0, 10);
    add_func(L, "createListenSocketIP", luasteam_createListenSocketIP);
    add_func(L, "connectByIPAddress", luasteam_connectByIPAddress);
    add_func(L, "acceptConnection", luasteam_acceptConnection);
    add_func(L, "closeConnection", luasteam_closeConnection);
    add_func(L, "closeListenSocket", luasteam_closeListenSocket);
    add_func(L, "sendMessageToConnection", luasteam_sendMessageToConnection);
    add_func(L, "receiveMessagesOnConnection", luasteam_receiveMessagesOnConnection);
    add_func(L, "initAuthentication", luasteam_initAuthentication);
    add_func(L, "getAuthenticationStatus", luasteam_getAuthenticationStatus);
    add_func(L, "getConnectionInfo", luasteam_getConnectionInfo);
    add_constants(L);
    lua_pushvalue(L, -1);
    sockets_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "networkingSockets");
}

void init_networkingSockets(lua_State *L) {
    steamNetworkingSocketsLib = &SteamNetworkingSockets;
    connection_listener = new CallbackListener();
    auth_listener = new CallbackListener();
}

void init_networkingSockets_server(lua_State *L) {
    steamNetworkingSocketsLib = &SteamGameServerNetworkingSockets;
    connection_listener = new CallbackListener();
    auth_listener = new CallbackListener();
}

void shutdown_networkingSockets(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, sockets_ref);
    sockets_ref = LUA_NOREF;

    delete connection_listener;
    connection_listener = nullptr;

    delete auth_listener;
    auth_listener = nullptr;
}

} // namespace luasteam
