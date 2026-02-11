#include "apps.hpp"
#include "auto/auto.hpp"

// ============================
// ======== SteamApps =========
// ============================

namespace {

} // namespace

// Manually implemented because it uses a fixed-size buffer for output
// int GetLaunchCommandLine( char *pszCommandLine, int cubCommandLine );
EXTERN int luasteam_getLaunchCommandLine(lua_State *L) {
    char pCommandLine[1024];
    SteamApps()->GetLaunchCommandLine(pCommandLine, 1024);
    lua_pushstring(L, pCommandLine);
    return 1;
}

namespace luasteam {

void add_apps(lua_State *L) {
    lua_createtable(L, 0, 1);
    register_Apps_auto(L);
    add_func(L, "getLaunchCommandLine", luasteam_getLaunchCommandLine);
    lua_pushvalue(L, -1);
    Apps_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "apps");
}

void init_apps(lua_State *L) { init_Apps_auto(L); }

void shutdown_apps(lua_State *L) {
    shutdown_Apps_auto(L);
}

} // namespace luasteam
