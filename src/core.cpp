#include "core.hpp"

// ========================
// ======= SteamAPI =======
// ========================

// bool SteamAPI_Init();
EXTERN int luasteam_init(lua_State *L) {
    bool success = SteamAPI_Init();
    if (!success) {
        fprintf(stderr, "Couldn't connect to steam...\nDo you have Steam turned on?\nIf not running from steam, do you have a correct steam_appid.txt file?\n");
    }
    lua_pushboolean(L, success);
    return 1;
}

// void SteamAPI_Shutdown();
EXTERN int luasteam_shutdown(lua_State *L) {
    SteamAPI_Shutdown();
    // Cleaning up
    // global_lua_state = nullptr;
    // luaL_unref(L, LUA_REGISTRYINDEX, friends_ref);
    // friends_ref = LUA_NOREF;
    // delete friends_listener;
    // friends_listener = nullptr;
    // luaL_unref(L, LUA_REGISTRYINDEX, uint64Metatable_ref);
    // uint64Metatable_ref = LUA_NOREF;
    return 0;
}

// void SteamAPI_RunCallbacks();
EXTERN int luasteam_runCallbacks(lua_State *L) {
    SteamAPI_RunCallbacks();
    return 0;
}

namespace luasteam {

void add_core(lua_State *L) {
    add_func(L, "init", luasteam_init);
    add_func(L, "shutdown", luasteam_shutdown);
    add_func(L, "runCallbacks", luasteam_runCallbacks);
}

} // namespace luasteam
