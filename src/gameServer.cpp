
#include "gameServer.hpp"
#include "auto/auto.hpp"
#include "../sdk/public/steam/steam_gameserver.h"
#include "const.hpp"
#include "extra.hpp"
#include "networkingSockets.hpp"
#include "networkingUtils.hpp"
#include <sstream>
#include <vector>

// ===============================
// ======= SteamGameServer =======
// ===============================

static const char *steam_auth_session_response[] = {
    "OK", "UserNotConnectedToSteam", "NoLicenseOrExpired", "VACBanned", "LoggedInElseWhere", "VACCheckTimedOut", "AuthTicketCanceled", "AuthTicketInvalidAlreadyUsed", "AuthTicketInvalid", "PublisherIssuedBan", nullptr,
};

std::vector<unsigned char> hexToBuffer(const std::string &hexString) {
    std::vector<unsigned char> buffer;
    buffer.reserve(hexString.size() / 2);
    for (size_t i = 0; i < hexString.size(); i += 2) {
        unsigned int byte;
        std::istringstream iss(hexString.substr(i, 2));
        iss >> std::hex >> byte;
        buffer.push_back(static_cast<unsigned char>(byte));
    }
    return buffer;
}

using luasteam::CallResultListener;

namespace {

class CallbackListener;
CallbackListener *server_listener = nullptr;
int gameServer_ref = LUA_NOREF;

class CallbackListener {
  private:
    STEAM_GAMESERVER_CALLBACK(CallbackListener, OnValidateAuthTicketResponse, ValidateAuthTicketResponse_t);
    STEAM_GAMESERVER_CALLBACK(CallbackListener, OnSteamServersConnected, SteamServersConnected_t);
    STEAM_GAMESERVER_CALLBACK(CallbackListener, OnSteamServersDisconnected, SteamServersDisconnected_t);
    STEAM_GAMESERVER_CALLBACK(CallbackListener, OnSteamServerConnectFailure, SteamServerConnectFailure_t);
};

// void SetValidateAuthTicketResponseCallback( function callback )
void CallbackListener::OnValidateAuthTicketResponse(ValidateAuthTicketResponse_t *data) {
    if (data == nullptr) {
        return;
    }
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) {
        return;
    }
    lua_rawgeti(L, LUA_REGISTRYINDEX, gameServer_ref);
    lua_getfield(L, -1, "onValidateAuthTicketResponse");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        luasteam::pushuint64(L, data->m_SteamID.ConvertToUint64());
        lua_setfield(L, -2, "steam_id");
        luasteam::pushuint64(L, data->m_OwnerSteamID.ConvertToUint64());
        lua_setfield(L, -2, "owner_steam_id");
        lua_pushstring(L, steam_auth_session_response[data->m_eAuthSessionResponse]);
        lua_setfield(L, -2, "response");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

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

// Manually implemented because it's a core initialization function
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

// Manually implemented because it's a core function
// void SteamGameServer_RunCallbacks()
EXTERN int luasteam_runCallbacks_server(lua_State *L) {
    SteamGameServer_RunCallbacks();
    return 0;
}

// Manually implemented because it's a core shutdown function
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

// Manually implemented because it handles hex conversion for the ticket buffer
// EBeginAuthSessionResult BeginAuthSession( const void *pAuthTicket, int cbAuthTicket, CSteamID steamID )
EXTERN int luasteam_server_beginAuthSession(lua_State *L) {
    const char *hexTicket = luaL_checkstring(L, 1);
    std::vector<unsigned char> authTicketBuffer = hexToBuffer(hexTicket);
    const void *authTicket = authTicketBuffer.data();
    int cbAuthTicket = authTicketBuffer.size();

    CSteamID steamID(luasteam::checkuint64(L, 2));
    EBeginAuthSessionResult result = SteamGameServer()->BeginAuthSession(authTicket, cbAuthTicket, steamID);
    lua_pushinteger(L, result);
    return 1;
}

// Manually implemented because it uses CSteamID
// void EndAuthSession( CSteamID steamID );
EXTERN int luasteam_server_endAuthSession(lua_State *L) {
    CSteamID steamID(luasteam::checkuint64(L, 1));
    SteamGameServer()->EndAuthSession(steamID);
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
    lua_createtable(L, 0, 6);
    add_gameserver_auto(L);
    add_func(L, "init", luasteam_init_server);
    add_func(L, "shutdown", luasteam_shutdown_server);
    add_func(L, "runCallbacks", luasteam_runCallbacks_server);
    add_func(L, "beginAuthSession", luasteam_server_beginAuthSession);
    add_func(L, "endAuthSession", luasteam_server_endAuthSession);
    add_gameserver_constants(L);
    lua_pushvalue(L, -1);
    gameServer_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "gameServer");
}

} // namespace luasteam
