#include "extra.hpp"
#include <cstdlib>

// Returns 0 if string is invalid
EXTERN int luasteam_parseUint64(lua_State *L) {
    const char *str = luaL_checkstring(L, 1);
    // strto* are safer than ato*
    uint64 x = strtoull(str, nullptr, 10);
    luasteam::pushuint64(L, x);
    return 1;
}

namespace luasteam {

void add_extra(lua_State *L) {
    lua_createtable(L, 0, 1);
    add_func(L, "parseUint64", luasteam_parseUint64);
    lua_setfield(L, -2, "extra");
}

void init_extra(lua_State *L) {}

void shutdown_extra(lua_State *L) {}

} // namespace luasteam
