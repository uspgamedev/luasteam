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



//Table with all our functions
luaL_Reg luasteam_module[] = {
    {"init",luasteam_init},
    {"shutdown",luasteam_shutdown},
    {"getAchievement", luasteam_getAchievement},
    {"setAchievement", luasteam_setAchievement},
    {"resetAllStats", luasteam_resetAllStats},
    {"storeStats", luasteam_storeStats},
    {"requestCurrentStats", luasteam_requestCurrentStats},
    { nullptr, nullptr }
};

EXTERN int luaopen_luasteam(lua_State *L){
    lua_createtable(L,0,sizeof(luasteam_module));
    luaL_register(L,nullptr,luasteam_module);
    if (SteamAPI_Init()) {
        printf("Sucessfully connected to steam!\n");
    }else{
        printf("Couldn't connect to steam...\nDo you have Steam turned on?\nIf not running from steam, do you have a correct steam_appid.txt file?\n");
        lua_settop(L,0);
        lua_pushboolean(L,false);
    }
    return 1;
}
