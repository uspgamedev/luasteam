#ifndef LUASTEAM_GAMESERVER
#define LUASTEAM_GAMESERVER

#include "common.hpp"

namespace luasteam {

// Adds functions SteamAPI_*
void add_gameServer(lua_State *L);

} // namespace luasteam

#endif // LUASTEAM_GAMESERVER
