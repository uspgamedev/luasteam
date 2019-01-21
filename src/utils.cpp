#include "utils.hpp"

// ==========================
// ======= SteamUtils =======
// ==========================

// uint32 GetAppID();
EXTERN int luasteam_getAppID(lua_State *L) {
    lua_pushnumber(L, SteamUtils()->GetAppID());
    return 1;
}

namespace luasteam {

void add_utils(lua_State *L) {
    lua_createtable(L, 0, 1);
    add_func(L, "getAppID", luasteam_getAppID);
    lua_setfield(L, -2, "utils");
}

void init_utils(lua_State *L) {}

void shutdown_utils(lua_State *L) {}

} // namespace luasteam
