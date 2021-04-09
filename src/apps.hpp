#ifndef LUASTEAM_APPS
#define LUASTEAM_APPS

#include "common.hpp"

namespace luasteam {

// Adds functions from ISteamApps
void add_apps(lua_State *L);

void init_apps(lua_State *L);
void shutdown_apps(lua_State *L);

} // namespace luasteam

#endif // LUASTEAM_APPS
