#include "NetworkingSockets.hpp"
#include "SteamNetworkingMessage.hpp"
#include "auto/auto.hpp"

// ======================================
// ======= SteamNetworkingSockets =======
// ======================================
// The methods are manually implemented because they use SteamNetworkingMessage_t, which is manually implemented and different from all other structs in the codebase.

// In C++:
// int ReceiveMessagesOnConnection( HSteamNetConnection hConn, SteamNetworkingMessage_t **ppOutMessages, int nMaxMessages )
// In Lua:
// (int, ppOutMessages: SteamNetworkingMessage_t[]) NetworkingSockets.ReceiveMessagesOnConnection(hConn: int, nMaxMessages: int)
int luasteam_ReceiveMessagesOnConnection(lua_State *L, ISteamNetworkingSockets *iface) {
    HSteamNetConnection hConn = luaL_checkinteger(L, 1);
    int nMaxMessages = luaL_checkinteger(L, 2);

    std::vector<SteamNetworkingMessage_t *> msgs(nMaxMessages);
    int numMessages = iface->ReceiveMessagesOnConnection(hConn, msgs.data(), nMaxMessages);

    lua_pushinteger(L, numMessages);
    lua_createtable(L, numMessages, 0);
    for (int i = 0; i < numMessages; i++) {
        luasteam::push_SteamNetworkingMessage_t(L, msgs[i]);
        lua_rawseti(L, -2, i + 1);
    }
    return 2;
}

EXTERN int luasteam_ReceiveMessagesOnConnection_user(lua_State *L) { return luasteam_ReceiveMessagesOnConnection(L, SteamNetworkingSockets()); }
EXTERN int luasteam_ReceiveMessagesOnConnection_gameserver(lua_State *L) { return luasteam_ReceiveMessagesOnConnection(L, SteamGameServerNetworkingSockets()); }

// In C++:
// int ReceiveMessagesOnPollGroup( HSteamNetPollGroup hPollGroup, SteamNetworkingMessage_t **ppOutMessages, int nMaxMessages )
// In Lua:
// (int, ppOutMessages: SteamNetworkingMessage_t[]) NetworkingSockets.ReceiveMessagesOnPollGroup(hPollGroup: int, nMaxMessages: int)
int luasteam_ReceiveMessagesOnPollGroup(lua_State *L, ISteamNetworkingSockets *iface) {
    HSteamNetPollGroup hPollGroup = luaL_checkinteger(L, 1);
    int nMaxMessages = luaL_checkinteger(L, 2);

    std::vector<SteamNetworkingMessage_t *> msgs(nMaxMessages);
    int numMessages = iface->ReceiveMessagesOnPollGroup(hPollGroup, msgs.data(), nMaxMessages);

    lua_pushinteger(L, numMessages);
    lua_createtable(L, numMessages, 0);
    for (int i = 0; i < numMessages; i++) {
        luasteam::push_SteamNetworkingMessage_t(L, msgs[i]);
        lua_rawseti(L, -2, i + 1);
    }
    return 2;
}

EXTERN int luasteam_ReceiveMessagesOnPollGroup_user(lua_State *L) { return luasteam_ReceiveMessagesOnPollGroup(L, SteamNetworkingSockets()); }
EXTERN int luasteam_ReceiveMessagesOnPollGroup_gameserver(lua_State *L) { return luasteam_ReceiveMessagesOnPollGroup(L, SteamGameServerNetworkingSockets()); }

// In C++:
// void SendMessages( int nMessages, SteamNetworkingMessage_t *const *pMessages, int64 *pOutMessageNumberOrResult )
// In Lua:
// int[] NetworkingSockets.SendMessages(nMessages: int, pMessages: SteamNetworkingMessage_t[])
int luasteam_SendMessages(lua_State *L, ISteamNetworkingSockets *iface) {
    int nMessages = luaL_checkinteger(L, 1);
    luaL_checktype(L, 2, LUA_TTABLE);
    std::vector<int64> pOutMessageNumberOrResult(nMessages);
    std::vector<SteamNetworkingMessage_t *> pMessages(nMessages);
    for (int i = 0; i < nMessages; i++) {
        lua_rawgeti(L, 2, i + 1);
        pMessages[i] = luasteam::check_SteamNetworkingMessage_t(L, -1);
        lua_pop(L, 1);
    }
    iface->SendMessages(nMessages, pMessages.data(), pOutMessageNumberOrResult.data());
    lua_createtable(L, nMessages, 0);
    for (int i = 0; i < nMessages; i++) {
        lua_pushinteger(L, pOutMessageNumberOrResult[i]);
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

EXTERN int luasteam_SendMessages_user(lua_State *L) { return luasteam_SendMessages(L, SteamNetworkingSockets()); }
EXTERN int luasteam_SendMessages_gameserver(lua_State *L) { return luasteam_SendMessages(L, SteamGameServerNetworkingSockets()); }

namespace luasteam {

void add_NetworkingSockets(lua_State *L) {
    lua_createtable(L, 0, 20);
    register_NetworkingSockets_auto(L, false);
    add_func(L, "ReceiveMessagesOnConnection", luasteam_ReceiveMessagesOnConnection_user);
    add_func(L, "ReceiveMessagesOnPollGroup", luasteam_ReceiveMessagesOnPollGroup_user);
    add_func(L, "SendMessages", luasteam_SendMessages_user);
    lua_setfield(L, -2, "NetworkingSockets");
}

void add_GameServerNetworkingSockets(lua_State *L) {
    lua_createtable(L, 0, 20);
    register_NetworkingSockets_auto(L, true);
    add_func(L, "ReceiveMessagesOnConnection", luasteam_ReceiveMessagesOnConnection_gameserver);
    add_func(L, "ReceiveMessagesOnPollGroup", luasteam_ReceiveMessagesOnPollGroup_gameserver);
    add_func(L, "SendMessages", luasteam_SendMessages_gameserver);
    lua_setfield(L, -2, "NetworkingSockets");
}

} // namespace luasteam
