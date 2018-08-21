#include "include/steam_api.h"
#include <cstdio>

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
}

//Table with all our functions
luaL_Reg luasteam_module[2] = {
    {"init",luasteam_init},
    {"shutdown",luasteam_shutdown}
};

extern "C" int luaopen_steam(lua_State *L){
    lua_createtable(L,0,sizeof(luasteam_module));
    luaL_register(L,nullptr,luasteam_module);
    return 1;
}

// g++ luasteam.cxx -o steam.so -shared -fPIC -L./lib/linux64 -lsteam_api -I/usr/include/luajit-2.0 -L/usr/lib/x86_64-linux-gnu -lluajit-5.1 -std=c++11

//LD_LIBRARY_PATH=./lib/linux64 luajit
