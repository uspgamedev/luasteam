#include "Client.hpp"
#include "Common.hpp"
#include "Core.hpp"
#include "Extra.hpp"
#include "SteamNetworkingMessage.hpp"
#include "auto/auto.hpp"

// Creates and returns a table with all functions
EXTERN int luaopen_luasteam(lua_State *L) {
    lua_createtable(L, 0, 0);
    luasteam::add_Core(L);
    luasteam::add_Common(L);
    luasteam::add_Extra(L);
    luasteam::add_enums_auto(L);
    luasteam::add_consts_auto(L);
    luasteam::add_structs_auto(L);
    luasteam::add_callback_interfaces_auto(L);
    luasteam::add_SteamNetworkingMessage_t(L, {});
    luasteam::add_interface_placeholders(L);

    luasteam::set_steam_table(L, -1);
    return 1;
}
