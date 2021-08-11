#ifndef LUASTEAM_INPUT
#define LUASTEAM_INPUT

#include "common.hpp"

namespace luasteam {

// Adds functions from ISteamInput
void add_input(lua_State *L);

void init_input(lua_State *L);
void shutdown_input(lua_State *L);

} // namespace luasteam

#endif // LUASTEAM_INPUT
