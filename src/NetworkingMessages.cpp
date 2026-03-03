#include "NetworkingMessages.hpp"
#include "SteamNetworkingMessage.hpp"
#include "auto/auto.hpp"

// ========================================
// ======= SteamNetworkingMessages ========
// ========================================

// In C++:
// int ReceiveMessagesOnChannel(int nLocalChannel, SteamNetworkingMessage_t **ppOutMessages, int nMaxMessages)
// In Lua:
// (int, ppOutMessages: SteamNetworkingMessage_t[]) NetworkingMessages.ReceiveMessagesOnChannel(nLocalChannel: int, nMaxMessages: int)
static int luasteam_ReceiveMessagesOnChannel(lua_State *L, ISteamNetworkingMessages *iface) {
    int nLocalChannel = luaL_checkinteger(L, 1);
    int nMaxMessages = luaL_checkinteger(L, 2);

    std::vector<SteamNetworkingMessage_t *> msgs(nMaxMessages);
    int numMessages = iface->ReceiveMessagesOnChannel(nLocalChannel, msgs.data(), nMaxMessages);

    lua_pushinteger(L, numMessages);
    lua_createtable(L, numMessages, 0);
    for (int i = 0; i < numMessages; i++) {
        luasteam::push_SteamNetworkingMessage_t(L, msgs[i]);
        lua_rawseti(L, -2, i + 1);
    }
    return 2;
}

static int luasteam_ReceiveMessagesOnChannel_user(lua_State *L) { return luasteam_ReceiveMessagesOnChannel(L, SteamNetworkingMessages()); }
static int luasteam_ReceiveMessagesOnChannel_gs(lua_State *L) { return luasteam_ReceiveMessagesOnChannel(L, SteamGameServerNetworkingMessages()); }

namespace luasteam {

void add_NetworkingMessages(lua_State *L) {
    lua_createtable(L, 0, luasteam::NetworkingMessages_count + 1);
    register_NetworkingMessages_auto(L, false);
    add_func(L, "ReceiveMessagesOnChannel", luasteam_ReceiveMessagesOnChannel_user);
    lua_pushvalue(L, -1);
    luasteam::NetworkingMessages_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "NetworkingMessages");
}

void add_GameServerNetworkingMessages(lua_State *L) {
    lua_createtable(L, 0, luasteam::GameServerNetworkingMessages_count + 1);
    register_NetworkingMessages_auto(L, true);
    add_func(L, "ReceiveMessagesOnChannel", luasteam_ReceiveMessagesOnChannel_gs);
    lua_pushvalue(L, -1);
    luasteam::GameServerNetworkingMessages_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "GameServerNetworkingMessages");
}

} // namespace luasteam
