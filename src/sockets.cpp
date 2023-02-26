#include "sockets.hpp"

// ======================================
// ======= SteamNetworkingSockets =======
// ======================================

namespace {

HSteamListenSocket listenSocket;

class CallbackListener;
CallbackListener *connection_listener = nullptr;
int sockets_ref = LUA_NOREF;

class CallbackListener {
  private:
    STEAM_CALLBACK(CallbackListener, OnConnectionChanged, SteamNetConnectionStatusChangedCallback_t);
};

void CallbackListener::OnConnectionChanged(SteamNetConnectionStatusChangedCallback_t *data) {
    if (data == nullptr) {
        return;
    }
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) {
        return;
    }
    lua_rawgeti(L, LUA_REGISTRYINDEX, sockets_ref);
    lua_getfield(L, -1, "onGameOverlayActivated");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        CSteamID steamID = data->m_info.m_identityRemote.GetSteamID()
        if (steamID.is_Valid()) {
            lua_pushinteger(L, steamID.ConvertToUint64());
        } else {
            lua_pushinteger(L, -1);
        }
        lua_setfield(L, -2, "steam_id");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

} // namespace

// HSteamListenSocket CreateListenSocketIP( const SteamNetworkingIPAddr &localAddress, int nOptions, const SteamNetworkingConfigValue_t *pOptions )
EXTERN int luasteam_createListenSocketIP(lua_State *L) {
    fprintf(stderr, "Adding sockets %s\n", luaL_checkstring(L, 1));
    SteamNetworkingIPAddr localAdress;
    localAdress.ParseString(luaL_checkstring(L, 1));

    // TODO read the options table { max = 5, min = 3}
    // int options = luaL_checkint(L, 2);
    listenSocket = SteamNetworkingSockets()->CreateListenSocketIP(localAdress, 0, nullptr);

    size_t cbBuf = 64;
    char *connectionString = new char[cbBuf];
    localAdress.ToString(connectionString, cbBuf, true);
    lua_pushstring(L, connectionString);

    // lua_createtable(L, 0, 1);
    // lua_pushstring(L, connectionString);
    // lua_setfield(L, -2, "connection");
    return 1;
}

namespace luasteam {

void add_sockets(lua_State *L) {
    fprintf(stderr, "Adding sockets\n");
    lua_createtable(L, 0, 1);
    add_func(L, "createListenSocketIP", luasteam_createListenSocketIP);
    lua_pushvalue(L, -1);
    sockets_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "sockets");
}

void init_sockets(lua_State *L) { fprintf(stderr, "Initiating sockets\n"); }

void shutdown_sockets(lua_State *L) { 
    luaL_unref(L, LUA_REGISTRYINDEX, sockets_ref);
    sockets_ref = LUA_NOREF;
    fprintf(stderr, "Shutting down sockets\n"); }

} // namespace luasteam
