#include "NetworkingSockets.hpp"
#include "auto/auto.hpp"

// ======================================
// ======= SteamNetworkingSockets =======
// ======================================
// This interface is manually implemented because it's a complex API with many custom structs,
// pointers, and callback-heavy logic that doesn't map easily to the current auto-generator.

typedef ISteamNetworkingSockets *(*SteamNetworkingSocketsLib)();
SteamNetworkingSocketsLib steamNetworkingSocketsLib;

// TODO: see what to do
// ReceiveMessagesOnConnection( HSteamNetConnection hConn, SteamNetworkingMessage_t **ppOutMessages, int nMaxMessages )
EXTERN int luasteam_receiveMessagesOnConnection(lua_State *L) {
    HSteamNetConnection hConn = luaL_checkinteger(L, 1);

    SteamNetworkingMessage_t *msgs[32];
    int numMessages = steamNetworkingSocketsLib()->ReceiveMessagesOnConnection(hConn, msgs, 32);

    lua_pushinteger(L, numMessages);
    if (numMessages >= 0) {
        lua_createtable(L, 0, numMessages);
        for (int i = 0; i < numMessages; i++) {
            SteamNetworkingMessage_t *message = msgs[i];
            uint32 messageSize = message->GetSize();
            if (messageSize > 0) {
                lua_pushlstring(L, (char *)message->GetData(), messageSize);
            } else {
                lua_pushstring(L, "");
            }
            lua_rawseti(L, -2, i + 1);
            message->Release();
        }
        return 2;
    }
    return 1;
}

// int ReceiveMessagesOnPollGroup( HSteamNetPollGroup hPollGroup, SteamNetworkingMessage_t **ppOutMessages, int nMaxMessages )
EXTERN int luasteam_receiveMessagesOnPollGroup(lua_State *L) {
    HSteamNetPollGroup hPollGroup = luaL_checkinteger(L, 1);

    SteamNetworkingMessage_t *msgs[32];
    int numMessages = steamNetworkingSocketsLib()->ReceiveMessagesOnPollGroup(hPollGroup, msgs, 32);

    lua_pushinteger(L, numMessages);
    if (numMessages >= 0) {
        lua_createtable(L, 0, numMessages);
        for (int i = 0; i < numMessages; i++) {
            SteamNetworkingMessage_t *message = msgs[i];
            uint32 messageSize = message->GetSize();

            lua_createtable(L, 0, 2);
            if (messageSize > 0) {
                lua_pushlstring(L, (char *)message->GetData(), messageSize);
            } else {
                lua_pushstring(L, "");
            }
            lua_setfield(L, -2, "msg");
            lua_pushinteger(L, message->m_conn);
            lua_setfield(L, -2, "conn");
            lua_rawseti(L, -2, i + 1);
            message->Release();
        }
        return 2;
    }
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

void add_NetworkingSockets(lua_State *L) {
    lua_createtable(L, 0, 20);
    register_NetworkingSockets_auto(L, &SteamNetworkingSockets);
    add_func(L, "ReceiveMessagesOnConnection", luasteam_receiveMessagesOnConnection);
    add_func(L, "ReceiveMessagesOnPollGroup", luasteam_receiveMessagesOnPollGroup);
    add_func(L, "SendMessages", luasteam_sendMessages);
    lua_setfield(L, -2, "NetworkingSockets");
}

void add_GameServerNetworkingSockets(lua_State *L) {
    lua_createtable(L, 0, 20);
    register_NetworkingSockets_auto(L, &SteamGameServerNetworkingSockets);
    // TODO: fix these to use Gameserver
    add_func(L, "ReceiveMessagesOnConnection", luasteam_receiveMessagesOnConnection);
    add_func(L, "ReceiveMessagesOnPollGroup", luasteam_receiveMessagesOnPollGroup);
    add_func(L, "SendMessages", luasteam_sendMessages);
    lua_setfield(L, -2, "NetworkingSockets");
}

} // namespace luasteam
