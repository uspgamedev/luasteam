#include "sdk/public/steam/steam_api.h"
#include <cstdio>
#include <string>

#ifdef _WIN32
#    define EXTERN extern "C" __declspec(dllexport)
#else
#    define EXTERN extern "C"
#endif

extern "C" {
#include <lauxlib.h>
#include <lua.h>
}

// ========================
// ======= SteamAPI =======
// ========================

// GENERAL FUNCTIONS
EXTERN int luasteam_init(lua_State *L) {
    lua_settop(L, 0); // Reset lua stack
    lua_pushboolean(L, SteamAPI_Init());
    return 1;
}

EXTERN int luasteam_shutdown(lua_State *L) {
    SteamAPI_Shutdown();
    return 0;
}

EXTERN int luasteam_runCallbacks(lua_State *L) {
    SteamAPI_RunCallbacks();
    return 0;
}

// ==============================
// ======= SteamUserStats =======
// ==============================

// bool GetUserAchievement(const char *pchName, bool *pbAchieved );
EXTERN int luasteam_getAchievement(lua_State *L) {
    lua_settop(L, 1);
    if (!lua_isstring(L, 1)) {
        lua_pushstring(L, "incorrect type for argument1 (string expected)");
        return lua_error(L);
    }
    std::string ach_name = lua_tostring(L, 1);
    lua_settop(L, 0);
    bool achieved = false;
    bool success = SteamUserStats()->GetAchievement(ach_name.c_str(), &achieved);
    lua_pushboolean(L, success);
    lua_pushboolean(L, achieved);
    return 2;
}

// bool SetAchievement( const char *pchName );
EXTERN int luasteam_setAchievement(lua_State *L) {
    lua_settop(L, 1);
    if (!lua_isstring(L, 1)) {
        lua_pushstring(L, "incorrect type for argument1 (string expected)");
        return lua_error(L);
    }
    std::string ach_name = lua_tostring(L, 1);
    lua_settop(L, 0);
    bool success = SteamUserStats()->SetAchievement(ach_name.c_str());
    lua_pushboolean(L, success);
    return 1;
}

// bool ResetAllStats( bool bAchievementsToo );
EXTERN int luasteam_resetAllStats(lua_State *L) {
    lua_settop(L, 1);
    bool achievements_too = lua_toboolean(L, 1);
    lua_settop(L, 0);
    bool success = SteamUserStats()->ResetAllStats(achievements_too);
    lua_pushboolean(L, success);
    return 1;
}

// bool StoreStats();
EXTERN int luasteam_storeStats(lua_State *L) {
    lua_settop(L, 0);
    bool success = SteamUserStats()->StoreStats();
    lua_pushboolean(L, success);
    return 1;
}

// bool RequestCurrentStats();
EXTERN int luasteam_requestCurrentStats(lua_State *L) {
    lua_settop(L, 0);
    bool success = SteamUserStats()->RequestCurrentStats();
    lua_pushboolean(L, success);
    return 1;
}

// ============================
// ======= SteamFriends =======
// ============================

EXTERN int luasteam_activateGameOverlay(lua_State *L) {
    const char *dialog = luaL_checkstring(L, 1);
    SteamFriends()->ActivateGameOverlay(dialog);
    return 0;
}

EXTERN int luasteam_activateGameOverlayToWebPage(lua_State *L) {
    const char *url = luaL_checkstring(L, 1);
    SteamFriends()->ActivateGameOverlayToWebPage(url);
    return 0;
}

class SteamFriendsListener {
  public:
    SteamFriendsListener(lua_State *L_, int ref) : L(L_), friends_ref(ref) {}

  private:
    lua_State *L;
    int friends_ref;
    STEAM_CALLBACK(SteamFriendsListener, OnGameOverlayActivated, GameOverlayActivated_t);
};

void SteamFriendsListener::OnGameOverlayActivated(GameOverlayActivated_t *data) {
    if (!lua_checkstack(L, 3))
        return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, friends_ref);
    lua_getfield(L, -1, "onGameOverlayActivated");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_pushboolean(L, data->m_bActive);
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}
// ====================================
// ======= End of API functions =======
// ====================================

namespace {

void add_func(lua_State *L, const char *name, lua_CFunction func) {
    lua_pushstring(L, name);
    lua_pushcfunction(L, func);
    lua_rawset(L, -3);
}

void add_base(lua_State *L) {
    add_func(L, "init", luasteam_init);
    add_func(L, "shutdown", luasteam_shutdown);
    add_func(L, "runCallbacks", luasteam_runCallbacks);
}

void add_user_stats(lua_State *L) {
    lua_pushstring(L, "userStats"); // name of the table, used in the end of the function
    lua_createtable(L, 0, 5);
    add_func(L, "getAchievement", luasteam_getAchievement);
    add_func(L, "setAchievement", luasteam_setAchievement);
    add_func(L, "resetAllStats", luasteam_resetAllStats);
    add_func(L, "storeStats", luasteam_storeStats);
    add_func(L, "requestCurrentStats", luasteam_requestCurrentStats);
    lua_rawset(L, -3);
}

int add_friends(lua_State *L) {
    lua_pushstring(L, "friends"); // name of the table, used in the end of the function
    lua_createtable(L, 0, 2);
    add_func(L, "activateGameOverlay", luasteam_activateGameOverlay);
    add_func(L, "activateGameOverlayToWebPage", luasteam_activateGameOverlayToWebPage);
    lua_pushvalue(L, -1);                    // copying table
    int id = luaL_ref(L, LUA_REGISTRYINDEX); // used in the listener
    lua_rawset(L, -3);
    return id;
}

} // namespace

EXTERN int luaopen_luasteam(lua_State *L) {
    lua_createtable(L, 0, 5);
    add_base(L);
    add_user_stats(L);
    int friends_ref = add_friends(L);
    if (SteamAPI_Init()) {
        printf("Sucessfully connected to steam!\n");
    } else {
        printf("Couldn't connect to steam...\nDo you have Steam turned on?\nIf not running from steam, do you have a correct steam_appid.txt file?\n");
        lua_pushboolean(L, false);
    }
    new SteamFriendsListener(L, friends_ref);
    return 1;
}
