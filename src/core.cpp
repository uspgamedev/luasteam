#include "core.hpp"
#include "UGC.hpp"
#include "extra.hpp"
#include "friends.hpp"
#include "user_stats.hpp"
#include "utils.hpp"

// ========================
// ======= SteamAPI =======
// ========================

// bool SteamAPI_Init();
EXTERN int luasteam_init(lua_State *L) {
    bool success = SteamAPI_Init();
    if (success) {
        luasteam::init_common(L);
        luasteam::init_friends(L);
        luasteam::init_user_stats(L);
        luasteam::init_utils(L);
        luasteam::init_UGC(L);
        luasteam::init_extra(L);
    } else {
        fprintf(stderr, "Couldn't connect to steam...\nDo you have Steam turned on?\nIf not running from steam, do you have a correct steam_appid.txt file?\n");
    }
    lua_pushboolean(L, success);
    return 1;
}

// void SteamAPI_Shutdown();
EXTERN int luasteam_shutdown(lua_State *L) {
    SteamAPI_Shutdown();
    // Cleaning up
    luasteam::shutdown_extra(L);
    luasteam::shutdown_UGC(L);
    luasteam::shutdown_utils(L);
    luasteam::shutdown_user_stats(L);
    luasteam::shutdown_friends(L);
    luasteam::shutdown_common(L);
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
