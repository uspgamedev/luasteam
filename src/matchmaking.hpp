#ifndef LUASTEAM_MATCHMAKING
#define LUASTEAM_MATCHMAKING

#include "common.hpp"

namespace luasteam {

// Adds functions from ISteamMatchmaking
void add_matchmaking(lua_State *L);

void init_matchmaking(lua_State *L);
void shutdown_matchmaking(lua_State *L);

} // namespace luasteam

#endif // LUASTEAM_MATCHMAKING
