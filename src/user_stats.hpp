#ifndef LUASTEAM_USER_STATS
#define LUASTEAM_USER_STATS

#include "common.hpp"

namespace luasteam {

// Adds functions from ISteamUserStats
void add_user_stats(lua_State *L);

void init_user_stats(lua_State *L);
void shutdown_user_stats(lua_State *L);

} // namespace luasteam

#endif // LUASTEAM_USER_STATS
