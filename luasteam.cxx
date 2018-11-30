#include "sdk/public/steam/steam_api.h"
#include <cstdio>
#include <string>

#ifdef _WIN32
	#define EXTERN extern "C" __declspec( dllexport )
#else
	#define EXTERN extern "C"
#endif

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

//GENERAL FUNCTIONS
EXTERN int luasteam_init(lua_State *L){
    lua_settop(L,0); //Reset lua stack
    lua_pushboolean(L,SteamAPI_Init());
    return 1;
}

EXTERN int luasteam_shutdown(lua_State *L){
    SteamAPI_Shutdown();
    return 0;
}

//ACHIEVEMENTS FUNCTIONS

//bool GetUserAchievement(const char *pchName, bool *pbAchieved );
EXTERN int luasteam_getAchievement(lua_State *L){
    lua_settop(L,1);
    if (!lua_isstring(L,1)){
        lua_pushstring(L, "incorrect type for argument1 (string expected)");
        return lua_error(L);
    }
    std::string ach_name = lua_tostring(L,1);
    lua_settop(L,0);
    bool achieved = false;
    bool success = SteamUserStats()->GetAchievement(ach_name.c_str(),&achieved);
    lua_pushboolean(L,success);
    lua_pushboolean(L,achieved);
    return 2;
}

//bool SetAchievement( const char *pchName );
EXTERN int luasteam_setAchievement(lua_State *L){
    lua_settop(L,1);
    if (!lua_isstring(L,1)){
        lua_pushstring(L, "incorrect type for argument1 (string expected)");
        return lua_error(L);
    }
    std::string ach_name = lua_tostring(L,1);
    lua_settop(L,0);
    bool success = SteamUserStats()->SetAchievement(ach_name.c_str());
    lua_pushboolean(L,success);
    return 1;
}

//bool ResetAllStats( bool bAchievementsToo );
EXTERN int luasteam_resetAllStats(lua_State *L){
    lua_settop(L,1);
    bool achievements_too = lua_toboolean(L,1);
    lua_settop(L,0);
    bool success = SteamUserStats()->ResetAllStats(achievements_too);
    lua_pushboolean(L,success);
    return 1;
}

//bool StoreStats();
EXTERN int luasteam_storeStats(lua_State *L){
    lua_settop(L,0);
    bool success = SteamUserStats()->StoreStats();
    lua_pushboolean(L,success);
    return 1;
}

//bool RequestCurrentStats();
EXTERN int luasteam_requestCurrentStats(lua_State *L){
    lua_settop(L,0);
    bool success = SteamUserStats()->RequestCurrentStats();
    lua_pushboolean(L,success);
    return 1;
}

EXTERN int luasteam_activateGameOverlay(lua_State *L) {
    const char *dialog = lua_tostring(L, 1);
    printf("Activating overlay with %s\n", dialog);
    SteamFriends()->ActivateGameOverlay(dialog);
    return 0;
}


void add_func(lua_State *L, const char *name, lua_CFunction func) {
    lua_pushstring(L, name);
    lua_pushcfunction(L, func);
    lua_rawset(L, -3);
}

void add_user_stats(lua_State *L) {
    lua_createtable(L, 0, 5);
    add_func(L, "getAchievement", luasteam_getAchievement);
    add_func(L, "setAchievement", luasteam_setAchievement);
    add_func(L, "resetAllStats", luasteam_resetAllStats);
    add_func(L, "storeStats", luasteam_storeStats);
    add_func(L, "requestCurrentStats", luasteam_requestCurrentStats);
    lua_pushstring(L, "userStats");
    lua_insert(L, -2); // swap string and table
    lua_rawset(L, -3);
}

void add_friends(lua_State *L) {
    lua_createtable(L, 0, 1);
    add_func(L, "activateGameOverlay", luasteam_activateGameOverlay);
    lua_pushstring(L, "friends");
    lua_insert(L, -2); // swap string and table
    lua_rawset(L, -3);
}

EXTERN int luaopen_luasteam(lua_State *L){
    lua_createtable(L, 0, 4);
    add_func(L, "init", &luasteam_init);
    add_func(L, "shutdown", &luasteam_shutdown);
    add_user_stats(L);
    add_friends(L);
    if (SteamAPI_Init()) {
        printf("Sucessfully connected to steam!\n");
    }else{
        printf("Couldn't connect to steam...\nDo you have Steam turned on?\nIf not running from steam, do you have a correct steam_appid.txt file?\n");
        lua_pushboolean(L,false);
    }
    return 1;
}
