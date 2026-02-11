#include "core.hpp"
#include "UGC.hpp"
#include "apps.hpp"
#include "extra.hpp"
#include "friends.hpp"
#include "input.hpp"
#include "networkingSockets.hpp"
#include "networkingUtils.hpp"
#include "user.hpp"
#include "user_stats.hpp"
#include "utils.hpp"
#include "auto/auto.hpp"

// ========================
// ======= SteamAPI =======
// ========================

// Manually implemented because it's a core initialization function
// bool SteamAPI_Init();
EXTERN int luasteam_init(lua_State *L) {
    bool success = SteamAPI_Init();
    if (success) {
        luasteam::init_common(L);
        luasteam::init_friends(L);
        luasteam::init_user(L);
        luasteam::init_user_stats(L);
        luasteam::init_utils(L);
        luasteam::init_UGC(L);
        luasteam::init_extra(L);
        luasteam::init_apps(L);
        luasteam::init_input(L);
        luasteam::init_networkingSockets(L);
        luasteam::init_networkingUtils(L);
        luasteam::init_matchmaking_auto(L);
        luasteam::init_matchmakingservers_auto(L);
        luasteam::init_networking_auto(L);
        luasteam::init_screenshots_auto(L);
        luasteam::init_music_auto(L);
        luasteam::init_http_auto(L);
        luasteam::init_controller_auto(L);
        luasteam::init_htmlsurface_auto(L);
        luasteam::init_inventory_auto(L);
        luasteam::init_video_auto(L);
        luasteam::init_parentalsettings_auto(L);
        luasteam::init_remoteplay_auto(L);
        luasteam::init_networkingmessages_auto(L);
        luasteam::init_gameserverstats_auto(L);
        luasteam::init_timeline_auto(L);
        luasteam::init_parties_auto(L);
        luasteam::init_remotestorage_auto(L);
    } else {
        fprintf(stderr, "Couldn't connect to steam...\nPlease ensure that the following conditions are met:\n* Do you have Steam turned on?\n* If not running from steam, do you have a correct steam_appid.txt file?\n* Is the application running under the same user context as steam?\n* Is a license for the App ID present in your active steam account?\n* Is your App ID correctly set up, i.e. not in ``Release State: Unavailable`` and not missing default packages?\n");
    }
    lua_pushboolean(L, success);
    return 1;
}

// Manually implemented because it's a core shutdown function
// void SteamAPI_Shutdown();
EXTERN int luasteam_shutdown(lua_State *L) {
    SteamAPI_Shutdown();
    // Cleaning up
    luasteam::shutdown_remotestorage_auto(L);
    luasteam::shutdown_parties_auto(L);
    luasteam::shutdown_timeline_auto(L);
    luasteam::shutdown_gameserverstats_auto(L);
    luasteam::shutdown_networkingmessages_auto(L);
    luasteam::shutdown_remoteplay_auto(L);
    luasteam::shutdown_parentalsettings_auto(L);
    luasteam::shutdown_video_auto(L);
    luasteam::shutdown_inventory_auto(L);
    luasteam::shutdown_htmlsurface_auto(L);
    luasteam::shutdown_controller_auto(L);
    luasteam::shutdown_http_auto(L);
    luasteam::shutdown_music_auto(L);
    luasteam::shutdown_screenshots_auto(L);
    luasteam::shutdown_networking_auto(L);
    luasteam::shutdown_matchmakingservers_auto(L);
    luasteam::shutdown_matchmaking_auto(L);
    luasteam::shutdown_networkingUtils(L);
    luasteam::shutdown_networkingSockets(L);
    luasteam::shutdown_input(L);
    luasteam::shutdown_apps(L);
    luasteam::shutdown_extra(L);
    luasteam::shutdown_UGC(L);
    luasteam::shutdown_utils(L);
    luasteam::shutdown_user(L);
    luasteam::shutdown_user_stats(L);
    luasteam::shutdown_friends(L);
    luasteam::shutdown_common(L);
    return 0;
}

// Manually implemented because it's a core function
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
