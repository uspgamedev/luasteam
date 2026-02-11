#include "user.hpp"
#include "auto/auto.hpp"
#include <iomanip>
#include <sstream>

// ============================
// ======== SteamUser =========
// ============================

std::string bufferToHex(const void *buffer, size_t bufferLength) {
    const unsigned char *pBuffer = static_cast<const unsigned char *>(buffer);
    std::ostringstream oss;
    oss << std::hex << std::setfill('0');
    for (size_t i = 0; i < bufferLength; ++i) {
        oss << std::setw(2) << static_cast<int>(pBuffer[i]);
    }
    return oss.str();
}

namespace {

} // namespace

// Manually implemented because it uses a buffer for the ticket and handles hex conversion
// HAuthTicket GetAuthSessionTicket( void *pTicket, int cbMaxTicket, uint32 *pcbTicket, const SteamNetworkingIdentity *pIdentityRemote );
EXTERN int luasteam_getAuthSessionTicket(lua_State *L) {
    uint32 pcbTicket = 0;
    char pTicket[1024];
    SteamNetworkingIdentity identityRemote;
    identityRemote.ParseString(luaL_checkstring(L, 1));
    HAuthTicket ticket = SteamUser()->GetAuthSessionTicket(pTicket, 1024, &pcbTicket, &identityRemote);

    identityRemote.Clear();

    if (ticket != k_HAuthTicketInvalid) {
        std::string hexTicket = bufferToHex(pTicket, pcbTicket);
        lua_newtable(L);
        lua_pushinteger(L, ticket);
        lua_setfield(L, -2, "ticket");
        lua_pushstring(L, hexTicket.c_str());
        lua_setfield(L, -2, "hexTicket");
        return 1;
    }
    lua_pushnil(L);
    return 1;
}

namespace luasteam {

void add_user(lua_State *L) {
    lua_createtable(L, 0, 1);
    register_User_auto(L);
    add_func(L, "getAuthSessionTicket", luasteam_getAuthSessionTicket);
    lua_pushvalue(L, -1);
    User_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "user");
}

void init_user(lua_State *L) { init_User_auto(L); }

void shutdown_user(lua_State *L) {
    shutdown_User_auto(L);
}

} // namespace luasteam
