#ifndef LUASTEAM_NETWORKINGSOCKETS
#define LUASTEAM_NETWORKINGSOCKETS

#include "common.hpp"

namespace luasteam {

// Adds functions from ISteamNetworkingSockets
void add_NetworkingSockets(lua_State *L);
void add_GameServerNetworkingSockets(lua_State *L);
} // namespace luasteam

#endif // LUASTEAM_NETWORKINGSOCKETS
