#ifndef LUASTEAM_USER
#define LUASTEAM_USER

#include "common.hpp"

namespace luasteam {

// Adds functions from ISteamUser
void add_user(lua_State *L);

void init_user(lua_State *L);
void shutdown_user(lua_State *L);

} // namespace luasteam

#endif // LUASTEAM_USER
