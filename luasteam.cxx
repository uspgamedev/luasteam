#include "include/steam_api.h"
#include <cstdio>

extern "C" {
#include <lua.h>
}

extern "C" int luaopen_steam(lua_State *L){
    printf("oi\n");
    return 0;
}

// g++ luasteam.cxx -o steam.so -shared -fPIC -L./lib/linux64 -lsteam_api -I/usr/include/luajit-2.0 -L/usr/lib/x86_64-linux-gnu -lluajit-5.1
