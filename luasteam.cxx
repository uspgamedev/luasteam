#include "include/steam_api.h"
#include <cstdio>
#include <string>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
}

extern "C" {
int luasteam_init(lua_State *L){
    lua_settop(L,0); //Reset lua stack
    lua_pushboolean(L,SteamAPI_Init());
    return 1;
}
int luasteam_shutdown(lua_State *L){
    SteamAPI_Shutdown();
    return 0;
}

//bool GetUserAchievement(const char *pchName, bool *pbAchieved );
int luasteam_getAchievement(lua_State *L){
    lua_settop(L,1);
    if (!lua_isstring(L,1)){
        lua_pushstring(L, "incorrect type for argument2 (string expected)");
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
}

//Table with all our functions
luaL_Reg luasteam_module[3] = {
    {"init",luasteam_init},
    {"shutdown",luasteam_shutdown},
    {"getAchievement", luasteam_getAchievement}
};

extern "C" int luaopen_steam(lua_State *L){
    lua_createtable(L,0,sizeof(luasteam_module));
    luaL_register(L,nullptr,luasteam_module);
    return 1;
}

// Create steam.so (linux)
// g++ luasteam.cxx -o steam.so -shared -fPIC -L./lib/linux64 -lsteam_api -I/usr/include/luajit-2.0 -L/usr/lib/x86_64-linux-gnu -lluajit-5.1 -std=c++11

//Run luajit with proper path to lib (linux)
//LD_LIBRARY_PATH=./lib/linux64 luajit
