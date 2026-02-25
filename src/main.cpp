#include "Client.hpp"
#include "Common.hpp"
#include "Core.hpp"
#include "Extra.hpp"
#include "GameServer.hpp"
#include "NetworkingSockets.hpp"
#include "NetworkingUtils.hpp"
#include "Utils.hpp"
#include "auto/auto.hpp"

// Creates and returns a table with all functions
EXTERN int luaopen_luasteam(lua_State *L) {
    lua_createtable(L, 0, 41);
    luasteam::add_Core(L);
    luasteam::add_Client(L);
    luasteam::add_Friends_auto(L);
    luasteam::add_User_auto(L);
    luasteam::add_UserStats_auto(L);
    luasteam::add_Utils(L);
    luasteam::add_GameServerUtils_auto(L);
    luasteam::add_UGC_auto(L);
    luasteam::add_GameServerUGC_auto(L);
    luasteam::add_extra(L);
    luasteam::add_Apps_auto(L);
    luasteam::add_Input_auto(L);
    luasteam::add_NetworkingSockets(L);
    luasteam::add_GameServerNetworkingSockets(L);
    luasteam::add_networkingUtils(L);
    luasteam::add_gameServer(L);
    luasteam::add_Matchmaking_auto(L);
    luasteam::add_MatchmakingServers_auto(L);
    luasteam::add_Networking_auto(L);
    luasteam::add_GameServerNetworking_auto(L);
    luasteam::add_Screenshots_auto(L);
    luasteam::add_Music_auto(L);
    luasteam::add_HTTP_auto(L);
    luasteam::add_GameServerHTTP_auto(L);
    luasteam::add_Controller_auto(L);
    luasteam::add_HTMLSurface_auto(L);
    luasteam::add_Inventory_auto(L);
    luasteam::add_GameServerInventory_auto(L);
    luasteam::add_Video_auto(L);
    luasteam::add_ParentalSettings_auto(L);
    luasteam::add_RemotePlay_auto(L);
    luasteam::add_NetworkingMessages_auto(L);
    luasteam::add_GameServerNetworkingMessages_auto(L);
    luasteam::add_GameServerStats_auto(L);
    luasteam::add_Timeline_auto(L);
    luasteam::add_Parties_auto(L);
    luasteam::add_RemoteStorage_auto(L);
    luasteam::add_enums_auto(L);
    luasteam::add_consts_auto(L);
    return 1;
}
