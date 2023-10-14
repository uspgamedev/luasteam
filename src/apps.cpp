#include "apps.hpp"

// ============================
// ======== SteamApps =========
// ============================

// const char * GetCurrentGameLanguage();
EXTERN int luasteam_getCurrentGameLanguage(lua_State *L) {
  lua_pushstring(L, SteamApps()->GetCurrentGameLanguage());
  return 1;
}

// int GetLaunchCommandLine( char *pszCommandLine, int cubCommandLine );
EXTERN int luasteam_getLaunchCommandLine(lua_State *L) {
  char buffer[256];
  int bytes = SteamApps()->GetLaunchCommandLine(buffer, sizeof(buffer) - 1);
  buffer[bytes] = '\0';
  lua_pushstring(L, buffer);
  return 1;
}

namespace luasteam {

void add_apps(lua_State *L) {
    lua_createtable(L, 0, 1);
    add_func(L, "getCurrentGameLanguage", luasteam_getCurrentGameLanguage);
    add_func(L, "getLaunchCommandLine", luasteam_getLaunchCommandLine);
    lua_setfield(L, -2, "apps");
}

void init_apps(lua_State *L) {}

void shutdown_apps(lua_State *L) {}

} // namespace luasteam
