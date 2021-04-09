#include "apps.hpp"

// ============================
// ======== SteamApps =========
// ============================

// const char * GetCurrentGameLanguage();
EXTERN int luasteam_getCurrentGameLanguage(lua_State *L) {
  lua_pushstring(L, SteamApps()->GetCurrentGameLanguage());
  return 1;
}

namespace luasteam {

void add_apps(lua_State *L) {
    lua_createtable(L, 0, 1);
    add_func(L, "getCurrentGameLanguage", luasteam_getCurrentGameLanguage);
    lua_setfield(L, -2, "apps");
}

void init_apps(lua_State *L) {}

void shutdown_apps(lua_State *L) {}

} // namespace luasteam
