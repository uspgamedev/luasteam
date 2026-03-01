#include "Extra.hpp"
#include <cstdlib>

// Manually implemented as a utility function to parse uint64 from a string or number
// Returns 0 if string is invalid
EXTERN int luasteam_parseUint64(lua_State *L) {
    uint64 x;
    if (lua_isstring(L, 1)) {
        const char *str = luaL_checkstring(L, 1);
        // strto* are safer than ato*
        x = strtoull(str, nullptr, 10);
    } else {
        x = luaL_checkinteger(L, 1);
    }
    luasteam::pushuint64(L, x);
    return 1;
}

namespace luasteam {

void add_Extra(lua_State *L) {
    lua_createtable(L, 0, 1);
    add_func(L, "ParseUint64", luasteam_parseUint64);
    lua_setfield(L, -2, "Extra");
}

void init_extra(lua_State *L) {}

void shutdown_extra(lua_State *L) {}

} // namespace luasteam
