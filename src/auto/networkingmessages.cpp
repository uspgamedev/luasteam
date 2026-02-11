#include "auto.hpp"

namespace luasteam {

int networkingmessages_ref = LUA_NOREF;

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
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::networkingmessages_ref);
    lua_getfield(L, -1, "onSteamNetworkingMessagesSessionRequest");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnSteamNetworkingMessagesSessionFailed(SteamNetworkingMessagesSessionFailed_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::networkingmessages_ref);
    lua_getfield(L, -1, "onSteamNetworkingMessagesSessionFailed");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

CallbackListener *networkingmessages_listener = nullptr;

} // namespace

void init_networkingmessages_auto(lua_State *L) { networkingmessages_listener = new CallbackListener(); }

void shutdown_networkingmessages_auto(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, networkingmessages_ref);
    networkingmessages_ref = LUA_NOREF;
    delete networkingmessages_listener; networkingmessages_listener = nullptr;
}


void register_networkingmessages_auto(lua_State *L) {
}

void add_networkingmessages_auto(lua_State *L) {
    lua_createtable(L, 0, 0);
    register_networkingmessages_auto(L);
    lua_pushvalue(L, -1);
    networkingmessages_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "networkingMessages");
}

} // namespace luasteam
