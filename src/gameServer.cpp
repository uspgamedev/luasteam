
#include "gameServer.hpp"
#include "auto/auto.hpp"
#include "../sdk/public/steam/steam_gameserver.h"
#include "extra.hpp"
#include "networkingSockets.hpp"
#include "networkingUtils.hpp"
#include <sstream>
#include <vector>

// ===============================
// ======= SteamGameServer =======
// ===============================

namespace luasteam {

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

} // namespace luasteam

using luasteam::CallResultListener;

namespace {

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
        luasteam::init_GameServer_auto(L);
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
    luasteam::shutdown_GameServer_auto(L);
    return 0;
}

// Manually implemented because it handles hex conversion for the ticket buffer
// EBeginAuthSessionResult BeginAuthSession( const void *pAuthTicket, int cbAuthTicket, CSteamID steamID )
EXTERN int luasteam_server_beginAuthSession(lua_State *L) {
    const char *hexTicket = luaL_checkstring(L, 1);
    std::vector<unsigned char> authTicketBuffer = luasteam::hexToBuffer(hexTicket);
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

namespace luasteam {

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

void add_gameServer(lua_State *L) {
    lua_createtable(L, 0, 6);
    register_GameServer_auto(L);
    add_func(L, "init", luasteam_init_server);
    add_func(L, "shutdown", luasteam_shutdown_server);
    add_func(L, "runCallbacks", luasteam_runCallbacks_server);
    add_func(L, "beginAuthSession", luasteam_server_beginAuthSession);
    add_func(L, "endAuthSession", luasteam_server_endAuthSession);
    add_gameserver_constants(L);
    lua_pushvalue(L, -1);
    GameServer_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "gameServer");
}

} // namespace luasteam
