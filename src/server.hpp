#ifndef LUASTEAM_SERVER
#define LUASTEAM_SERVER

#include "common.hpp"

namespace luasteam {

// Adds functions SteamAPI_*
void add_server(lua_State *L);

} // namespace luasteam

#endif // LUASTEAM_SERVER
