#include "apps.hpp"
#include "auto/auto.hpp"

// ============================
// ======== SteamApps =========
// ============================

class CallbackListener;
CallbackListener *apps_listener = nullptr;
int apps_ref = LUA_NOREF;

class CallbackListener {
  private:
    STEAM_CALLBACK(CallbackListener, OnNewUrlLaunchParameters, NewUrlLaunchParameters_t);
};

void CallbackListener::OnNewUrlLaunchParameters(NewUrlLaunchParameters_t *data) {
    if (data == nullptr) {
        return;
    }
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) {
        return;
    }
    lua_rawgeti(L, LUA_REGISTRYINDEX, apps_ref);
    lua_getfield(L, -1, "onNewUrlLaunchParameters");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_call(L, 0, 0);
        lua_pop(L, 1);
    }
}

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
    add_apps_auto(L);
    add_func(L, "getLaunchCommandLine", luasteam_getLaunchCommandLine);
    lua_pushvalue(L, -1);
    apps_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "apps");
}

void init_apps(lua_State *L) { apps_listener = new CallbackListener(); }

void shutdown_apps(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, apps_ref);
    apps_ref = LUA_NOREF;
    delete apps_listener;
    apps_listener = nullptr;
}

} // namespace luasteam
