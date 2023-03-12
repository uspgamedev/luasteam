
#include "../sdk/public/steam/steam_gameserver.h"
#include "extra.hpp"
#include "networkingSockets.hpp"
#include "networkingUtils.hpp"
#include "const.hpp"

// ===============================
// ======= SteamGameServer =======
// ===============================

using luasteam::CallResultListener;

namespace {

class CallbackListener;
CallbackListener *server_listener = nullptr;
int gameServer_ref = LUA_NOREF;

class CallbackListener {
  private:
    STEAM_GAMESERVER_CALLBACK(CallbackListener, OnSteamServersConnected, SteamServersConnected_t);
    STEAM_GAMESERVER_CALLBACK(CallbackListener, OnSteamServersDisconnected, SteamServersDisconnected_t);
    STEAM_GAMESERVER_CALLBACK(CallbackListener, OnSteamServerConnectFailure, SteamServerConnectFailure_t);
};

void CallbackListener::OnSteamServersConnected(SteamServersConnected_t *data) {
    if (data == nullptr) {
        return;
    }
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) {
        return;
    }
    lua_rawgeti(L, LUA_REGISTRYINDEX, gameServer_ref);
    lua_getfield(L, -1, "onSteamServersConnected");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 0);
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnSteamServersDisconnected(SteamServersDisconnected_t *data) {
    if (data == nullptr) {
        return;
    }
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) {
        return;
    }
    lua_rawgeti(L, LUA_REGISTRYINDEX, gameServer_ref);
    lua_getfield(L, -1, "onSteamServersDisconnected");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushstring(L, steam_result_code[data->m_eResult]);
        lua_setfield(L, -2, "result");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnSteamServerConnectFailure(SteamServerConnectFailure_t *data) {
    if (data == nullptr) {
        return;
    }
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) {
        return;
    }
    lua_rawgeti(L, LUA_REGISTRYINDEX, gameServer_ref);
    lua_getfield(L, -1, "onSteamServerConnectFailure");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushstring(L, steam_result_code[data->m_eResult]);
        lua_setfield(L, -2, "result");
        lua_pushboolean(L, data->m_bStillRetrying);
        lua_setfield(L, -2, "stillRetrying");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

} // namespace

// bool SteamGameServer_Init()
EXTERN int luasteam_init_server(lua_State *L) {
    uint32 ip = luaL_checkinteger(L, 1);
    uint16 usGamePort = luaL_checkinteger(L, 2);
    uint16 usQueryPort = luaL_checkinteger(L, 3);
    EServerMode eServerMode = static_cast<EServerMode>(luaL_checkinteger(L, 4));
    const char *version = (char *)luaL_checkstring(L, 5);
    bool success = SteamGameServer_Init(ip, usGamePort, usQueryPort, eServerMode, version);
    if (success) {
        luasteam::init_common(L);
        luasteam::init_extra(L);
        luasteam::init_networkingSockets_server(L);
        luasteam::init_networkingUtils(L);
        server_listener = new CallbackListener();
    } else {
        fprintf(stderr, "Couldn't init game server...\nDo you have a correct steam_appid.txt file?\n");
    }
    lua_pushboolean(L, success);
    return 1;
}

// void SteamGameServer_RunCallbacks()
EXTERN int luasteam_runCallbacks_server(lua_State *L) {
    SteamGameServer_RunCallbacks();
    return 0;
}

// void SteamGameServer_Shutdown()
EXTERN int luasteam_shutdown_server(lua_State *L) {
    SteamGameServer_Shutdown();
    // Cleaning up
    luasteam::shutdown_networkingUtils(L);
    luasteam::shutdown_networkingSockets(L);
    luasteam::shutdown_extra(L);
    luasteam::shutdown_common(L);
    luaL_unref(L, LUA_REGISTRYINDEX, gameServer_ref);
    gameServer_ref = LUA_NOREF;
    delete server_listener;
    server_listener = nullptr;
    return 0;
}

// void LogOn( const char *pszToken )
EXTERN int luasteam_server_logOn(lua_State *L) {
    const char *token = (char *)luaL_checkstring(L, 1);
    SteamGameServer()->LogOn(token);
    return 0;
}

// void void LogOnAnonymous()
EXTERN int luasteam_server_logOnAnonymous(lua_State *L) {
    SteamGameServer()->LogOnAnonymous();
    return 0;
}

// void void LogOff()
EXTERN int luasteam_server_logOff(lua_State *L) {
    SteamGameServer()->LogOff();
    return 0;
}

// bool BLoggedOn()
EXTERN int luasteam_server_bLoggedOn(lua_State *L) {
    lua_pushboolean(L, SteamGameServer()->BLoggedOn());
    return 1;
}

// bool BSecure()
EXTERN int luasteam_server_bSecure(lua_State *L) {
    lua_pushboolean(L, SteamGameServer()->BSecure());
    return 1;
}

// CSteamID GetSteamID()
EXTERN int luasteam_server_getSteamID(lua_State *L) {
    CSteamID steamID = SteamGameServer()->GetSteamID();
    luasteam::pushuint64(L, steamID.ConvertToUint64());
    return 1;
}

// SetDedicatedServer( bool bDedicated )
EXTERN int luasteam_server_setDedicatedServer(lua_State *L) {
    bool bDedicated = lua_toboolean(L, 1);
    SteamGameServer()->SetDedicatedServer(bDedicated);
    return 0;
}

void add_gameserver_constants(lua_State *L) {
    lua_createtable(L, 0, 3);
    lua_pushnumber(L, EServerMode::eServerModeNoAuthentication);
    lua_setfield(L, -2, "NoAuthentication");
    lua_pushnumber(L, EServerMode::eServerModeAuthentication);
    lua_setfield(L, -2, "Authentication");
    lua_pushnumber(L, EServerMode::eServerModeAuthenticationAndSecure);
    lua_setfield(L, -2, "AuthenticationAndSecure");
    lua_setfield(L, -2, "mode");
}

namespace luasteam {

void add_gameServer(lua_State *L) {
    lua_createtable(L, 0, 10);
    add_func(L, "init", luasteam_init_server);
    add_func(L, "shutdown", luasteam_shutdown_server);
    add_func(L, "runCallbacks", luasteam_runCallbacks_server);
    add_func(L, "logOn", luasteam_server_logOn);
    add_func(L, "logOnAnonymous", luasteam_server_logOnAnonymous);
    add_func(L, "logOff", luasteam_server_logOff);
    add_func(L, "bLoggedOn", luasteam_server_bLoggedOn);
    add_func(L, "bSecure", luasteam_server_bSecure);
    add_func(L, "getSteamID", luasteam_server_getSteamID);
    add_func(L, "setDedicatedServer", luasteam_server_setDedicatedServer);
    add_gameserver_constants(L);
    lua_pushvalue(L, -1);
    gameServer_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "gameServer");
}

} // namespace luasteam
