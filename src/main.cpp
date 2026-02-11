#include "UGC.hpp"
#include "apps.hpp"
#include "common.hpp"
#include "core.hpp"
#include "extra.hpp"
#include "friends.hpp"
#include "gameServer.hpp"
#include "input.hpp"
#include "networkingSockets.hpp"
#include "networkingUtils.hpp"
#include "user.hpp"
#include "user_stats.hpp"
#include "utils.hpp"
#include "auto/auto.hpp"

// Creates and returns a table with all functions
EXTERN int luaopen_luasteam(lua_State *L) {
    lua_createtable(L, 0, 31);
    luasteam::add_core(L);
    luasteam::add_friends(L);
    luasteam::add_user(L);
    luasteam::add_user_stats(L);
    luasteam::add_utils(L);
    luasteam::add_UGC(L);
    luasteam::add_extra(L);
    luasteam::add_apps(L);
    luasteam::add_input(L);
    luasteam::add_networkingSockets(L);
    luasteam::add_networkingUtils(L);
    luasteam::add_gameServer(L);
    luasteam::add_matchmaking_auto(L);
    luasteam::add_matchmakingservers_auto(L);
    luasteam::add_networking_auto(L);
    luasteam::add_screenshots_auto(L);
    luasteam::add_music_auto(L);
    luasteam::add_http_auto(L);
    luasteam::add_controller_auto(L);
    luasteam::add_htmlsurface_auto(L);
    luasteam::add_inventory_auto(L);
    luasteam::add_video_auto(L);
    luasteam::add_parentalsettings_auto(L);
    luasteam::add_remoteplay_auto(L);
    luasteam::add_networkingmessages_auto(L);
    luasteam::add_gameserverstats_auto(L);
    luasteam::add_timeline_auto(L);
    luasteam::add_parties_auto(L);
    luasteam::add_remotestorage_auto(L);
    luasteam::add_enums_auto(L);
    return 1;
}
