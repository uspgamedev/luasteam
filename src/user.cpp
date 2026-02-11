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

class CallbackListener;
CallbackListener *user_listener = nullptr;
int user_ref = LUA_NOREF;

class CallbackListener {
  private:
    STEAM_CALLBACK(CallbackListener, OnAuthSessionTicketResponse, GetAuthSessionTicketResponse_t);
};

void CallbackListener::OnAuthSessionTicketResponse(GetAuthSessionTicketResponse_t *data) {
    if (data == nullptr) {
        return;
    }
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) {
        return;
    }
    lua_rawgeti(L, LUA_REGISTRYINDEX, user_ref);
    lua_getfield(L, -1, "onAuthSessionTicketResponse");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushinteger(L, data->m_hAuthTicket);
        lua_setfield(L, -2, "handle");
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

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
    add_user_auto(L);
    add_func(L, "getAuthSessionTicket", luasteam_getAuthSessionTicket);
    lua_pushvalue(L, -1);
    user_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "user");
}

void init_user(lua_State *L) { user_listener = new CallbackListener(); }

void shutdown_user(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, user_ref);
    user_ref = LUA_NOREF;
    delete user_listener;
    user_listener = nullptr;
}

} // namespace luasteam
