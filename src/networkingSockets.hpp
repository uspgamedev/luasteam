#ifndef LUASTEAM_NETWORKINGSOCKETS
#define LUASTEAM_NETWORKINGSOCKETS

#include "common.hpp"

namespace luasteam {

// Adds functions from ISteamNetworkingSockets
void add_networkingSockets(lua_State *L);
void init_networkingSockets(lua_State *L);
void init_networkingSockets_server(lua_State *L);
void shutdown_networkingSockets(lua_State *L);
} // namespace luasteam

#endif // LUASTEAM_NETWORKINGSOCKETS
