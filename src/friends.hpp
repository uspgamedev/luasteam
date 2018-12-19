#ifndef LUASTEAM_FRIENDS
#define LUASTEAM_FRIENDS

#include "common.hpp"

namespace luasteam {

// Adds functions from ISteamFriends
void add_friends(lua_State *L);

void init_friends(lua_State *L);
void shutdown_friends(lua_State *L);

} // namespace luasteam

#endif // LUASTEAM_FRIENDS
