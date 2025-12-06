#ifndef LUASTEAM_NETWORKINGUTILS
#define LUASTEAM_NETWORKINGUTILS

#include "common.hpp"

namespace luasteam {

// Adds functions from ISteamNetworkingSockets
void add_networkingUtils(lua_State *L);
void init_networkingUtils(lua_State *L);
void shutdown_networkingUtils(lua_State *L);
} // namespace luasteam

#endif // LUASTEAM_NETWORKINGUTILS
