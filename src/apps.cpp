#include "apps.hpp"
#include <iomanip>


// ============================
// ======== SteamApps =========
// ============================

// const char * GetCurrentGameLanguage();
EXTERN int luasteam_getCurrentGameLanguage(lua_State *L) {
    lua_pushstring(L, SteamApps()->GetCurrentGameLanguage());
    return 1;
}

// bool BIsDlcInstalled( AppId_t appID );
EXTERN int luasteam_isDlcInstalled(lua_State *L) {
    int appID = luaL_checkint(L, 1);
    lua_pushboolean(L, SteamApps()->BIsDlcInstalled(appID));
    return 1;
}

// int GetLaunchCommandLine( char *pszCommandLine, int cubCommandLine );
EXTERN int luasteam_getLaunchCommandLine(lua_State *L) {
    char *pCommandLine = (char*) malloc(1024);
    SteamApps()->GetLaunchCommandLine(pCommandLine, 1024);
    lua_pushstring(L, pCommandLine);
    free(pCommandLine);
    return 1;
}

namespace luasteam {

void add_apps(lua_State *L) {
    lua_createtable(L, 0, 3);
    add_func(L, "getCurrentGameLanguage", luasteam_getCurrentGameLanguage);
    add_func(L, "isDlcInstalled", luasteam_isDlcInstalled);
    add_func(L, "getLaunchCommandLine", luasteam_getLaunchCommandLine);
    lua_setfield(L, -2, "apps");
}

void init_apps(lua_State *L) {}

void shutdown_apps(lua_State *L) {}

} // namespace luasteam
