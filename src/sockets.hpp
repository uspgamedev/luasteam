#ifndef LUASTEAM_SOCKETS
#define LUASTEAM_SOCKETS

#include "common.hpp"

namespace luasteam {

// Adds functions from ISteamNetworkingSockets
void add_sockets(lua_State *L);
void init_sockets(lua_State *L);
void init_sockets_server(lua_State *L);
void shutdown_sockets(lua_State *L);
} // namespace luasteam

#endif // LUASTEAM_SOCKETS

