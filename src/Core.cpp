#include "Core.hpp"
#include "Client.hpp"
#include "Extra.hpp"
#include "NetworkingSockets.hpp"
#include "NetworkingUtils.hpp"
#include "Utils.hpp"
#include "auto/auto.hpp"

// ========================
// ======= SteamAPI =======
// ========================

// Manually implemented because it's a core initialization function
// bool SteamAPI_Init();
EXTERN int luasteam_init(lua_State *L) {
    bool success = SteamAPI_Init();
    if (success) {
        luasteam::init_Common(L);
        luasteam::init_Client(L);
        luasteam::init_structs_auto(L);
        luasteam::init_callback_interfaces_auto(L);
        luasteam::init_Friends_auto(L);
        luasteam::init_User_auto(L);
        luasteam::init_UserStats_auto(L);
        luasteam::init_Utils(L);
        luasteam::init_UGC_auto(L);
        luasteam::init_extra(L);
        luasteam::init_Apps_auto(L);
        luasteam::init_Input_auto(L);
        luasteam::init_networkingSockets(L);
        luasteam::init_networkingUtils(L);
        luasteam::init_Matchmaking_auto(L);
        luasteam::init_MatchmakingServers_auto(L);
        luasteam::init_Networking_auto(L);
        luasteam::init_Screenshots_auto(L);
        luasteam::init_Music_auto(L);
        luasteam::init_HTTP_auto(L);
        luasteam::init_Controller_auto(L);
        luasteam::init_HTMLSurface_auto(L);
        luasteam::init_Inventory_auto(L);
        luasteam::init_Video_auto(L);
        luasteam::init_ParentalSettings_auto(L);
        luasteam::init_RemotePlay_auto(L);
        luasteam::init_NetworkingMessages_auto(L);
        luasteam::init_Timeline_auto(L);
        luasteam::init_Parties_auto(L);
        luasteam::init_RemoteStorage_auto(L);
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
    luasteam::shutdown_RemoteStorage_auto(L);
    luasteam::shutdown_Parties_auto(L);
    luasteam::shutdown_Timeline_auto(L);
    luasteam::shutdown_NetworkingMessages_auto(L);
    luasteam::shutdown_RemotePlay_auto(L);
    luasteam::shutdown_ParentalSettings_auto(L);
    luasteam::shutdown_Video_auto(L);
    luasteam::shutdown_Inventory_auto(L);
    luasteam::shutdown_HTMLSurface_auto(L);
    luasteam::shutdown_Controller_auto(L);
    luasteam::shutdown_HTTP_auto(L);
    luasteam::shutdown_Music_auto(L);
    luasteam::shutdown_Screenshots_auto(L);
    luasteam::shutdown_Networking_auto(L);
    luasteam::shutdown_MatchmakingServers_auto(L);
    luasteam::shutdown_Matchmaking_auto(L);
    luasteam::shutdown_networkingUtils(L);
    luasteam::shutdown_networkingSockets(L);
    luasteam::shutdown_Input_auto(L);
    luasteam::shutdown_Apps_auto(L);
    luasteam::shutdown_extra(L);
    luasteam::shutdown_UGC_auto(L);
    luasteam::shutdown_Utils(L);
    luasteam::shutdown_User_auto(L);
    luasteam::shutdown_UserStats_auto(L);
    luasteam::shutdown_Friends_auto(L);
    luasteam::shutdown_Client(L);
    luasteam::shutdown_Common(L);
    luasteam::shutdown_structs_auto(L);
    luasteam::shutdown_callback_interfaces_auto(L);
    return 0;
}

// Manually implemented because it's a core function
// void SteamAPI_RunCallbacks();
EXTERN int luasteam_runCallbacks(lua_State *L) {
    SteamAPI_RunCallbacks();
    return 0;
}

namespace luasteam {

void add_Core(lua_State *L) {
    add_func(L, "Init", luasteam_init);
    add_func(L, "Shutdown", luasteam_shutdown);
    add_func(L, "RunCallbacks", luasteam_runCallbacks);
    add_structs_auto(L);
    add_callback_interfaces_auto(L);
}

} // namespace luasteam
