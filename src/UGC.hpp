#ifndef LUASTEAM_UGC
#define LUASTEAM_UGC

#include "common.hpp"

namespace luasteam {

// Adds functions from ISteamUGC
void add_UGC(lua_State *L);

void init_UGC(lua_State *L);
void shutdown_UGC(lua_State *L);

} // namespace luasteam

#endif // LUASTEAM_UGC
