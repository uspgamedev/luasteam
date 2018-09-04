#include "include/steam_api.h"
#include <cstdio>
#include <string>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

extern "C" {
//GENERAL FUNCTIONS

int luasteam_init(lua_State *L){
    lua_settop(L,0); //Reset lua stack
    lua_pushboolean(L,SteamAPI_Init());
    return 1;
}

int luasteam_shutdown(lua_State *L){
    SteamAPI_Shutdown();
    return 0;
}

//ACHIEVEMENTS FUNCTIONS

//bool GetUserAchievement(const char *pchName, bool *pbAchieved );
int luasteam_getAchievement(lua_State *L){
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
int luasteam_setAchievement(lua_State *L){
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
int luasteam_resetAllStats(lua_State *L){
    lua_settop(L,1);
    bool achievements_too = lua_toboolean(L,1);
    lua_settop(L,0);
    bool success = SteamUserStats()->ResetAllStats(achievements_too);
    lua_pushboolean(L,success);
    return 1;
}

//bool StoreStats();
int luasteam_storeStats(lua_State *L){
    lua_settop(L,0);
    bool success = SteamUserStats()->StoreStats();
    lua_pushboolean(L,success);
    return 1;
}

//bool RequestCurrentStats();
int luasteam_requestCurrentStats(lua_State *L){
    lua_settop(L,0);
    bool success = SteamUserStats()->RequestCurrentStats();
    lua_pushboolean(L,success);
    return 1;
}


} // extern "C"


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

extern "C" int luaopen_steam(lua_State *L){
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

// Create steam.so (linux)
// g++ luasteam.cxx -o steam.so -shared -fPIC -L./lib/linux64 -lsteam_api -I/usr/include/luajit-2.0 -L/usr/lib/x86_64-linux-gnu -lluajit-5.1 -std=c++11

//Run luajit with proper path to lib (linux)
//LD_LIBRARY_PATH=./lib/linux64 luajit
