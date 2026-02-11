#include "auto.hpp"

namespace luasteam {

int NetworkingMessages_ref = LUA_NOREF;

namespace {

class CallbackListener {
  private:
    STEAM_CALLBACK(CallbackListener, OnSteamNetworkingMessagesSessionRequest, SteamNetworkingMessagesSessionRequest_t);
    STEAM_CALLBACK(CallbackListener, OnSteamNetworkingMessagesSessionFailed, SteamNetworkingMessagesSessionFailed_t);
};

void CallbackListener::OnSteamNetworkingMessagesSessionRequest(SteamNetworkingMessagesSessionRequest_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::NetworkingMessages_ref);
    lua_getfield(L, -1, "OnSteamNetworkingMessagesSessionRequest");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        // Skip unsupported type: SteamNetworkingIdentity
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnSteamNetworkingMessagesSessionFailed(SteamNetworkingMessagesSessionFailed_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::NetworkingMessages_ref);
    lua_getfield(L, -1, "OnSteamNetworkingMessagesSessionFailed");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        // Skip unsupported type: SteamNetConnectionInfo_t
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

CallbackListener *NetworkingMessages_listener = nullptr;

} // namespace

void init_NetworkingMessages_auto(lua_State *L) { NetworkingMessages_listener = new CallbackListener(); }

void shutdown_NetworkingMessages_auto(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, NetworkingMessages_ref);
    NetworkingMessages_ref = LUA_NOREF;
    delete NetworkingMessages_listener; NetworkingMessages_listener = nullptr;
}


void register_NetworkingMessages_auto(lua_State *L) {
}

void add_NetworkingMessages_auto(lua_State *L) {
    lua_createtable(L, 0, 0);
    register_NetworkingMessages_auto(L);
    lua_pushvalue(L, -1);
    NetworkingMessages_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "NetworkingMessages");
}

} // namespace luasteam
