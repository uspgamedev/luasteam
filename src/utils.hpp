#ifndef LUASTEAM_UTILS
#define LUASTEAM_UTILS

#include "common.hpp"

namespace luasteam {

// Adds functions from ISteamUtils
void add_utils(lua_State *L);

void init_utils(lua_State *L);
void shutdown_utils(lua_State *L);

} // namespace luasteam

#endif // LUASTEAM_UTILS
