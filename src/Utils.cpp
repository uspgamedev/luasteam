#include "Utils.hpp"
#include "Client.hpp"
#include "auto/auto.hpp"

// ======================================
// ======= ISteamUtils ==================
// ======================================

namespace luasteam {

void add_Utils(lua_State *L) {
    // TODO: handle GS Utils
    lua_createtable(L, 0, luasteam::Utils_count + 1);
    register_Utils_auto(L, false);
    add_func(L, "SetWarningMessageHook", luasteam_Client_SetWarningMessageHook);
    lua_setfield(L, -2, "Utils");
}

void add_GameServerUtils(lua_State *L) {
    lua_createtable(L, 0, luasteam::GameServerUtils_count + 1);
    register_Utils_auto(L, true);
    add_func(L, "SetWarningMessageHook", luasteam_GameServerClient_SetWarningMessageHook);
    lua_setfield(L, -2, "GameServerUtils");
}

void init_Utils(lua_State *L) {}

void shutdown_Utils(lua_State *L) {}

} // namespace luasteam
