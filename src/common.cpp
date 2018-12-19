#include "common.hpp"

namespace {
int uint64Metatable_ref = LUA_NOREF;
} // namespace

namespace luasteam {

lua_State *global_lua_state = nullptr;

void pushuint64(lua_State *L, uint64 v) {
    uint64 *ptr = reinterpret_cast<uint64 *>(lua_newuserdata(L, sizeof(uint64)));
    *ptr = v;
    lua_rawgeti(L, LUA_REGISTRYINDEX, uint64Metatable_ref);
    lua_setmetatable(L, -2);
}

uint64 checkuint64(lua_State *L, int nParam) {
    luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "must be userdata");
    lua_rawgeti(L, LUA_REGISTRYINDEX, uint64Metatable_ref);
    lua_getmetatable(L, nParam);
    luaL_argcheck(L, lua_rawequal(L, -2, -1), nParam, "must be uint64");
    lua_pop(L, 2);
    uint64 *ptr = reinterpret_cast<uint64 *>(lua_touserdata(L, nParam));
    return *ptr;
}

void add_func(lua_State *L, const char *name, lua_CFunction func) {
    lua_pushcfunction(L, func);
    lua_setfield(L, -2, name);
}

void init_common(lua_State *L) {
    global_lua_state = L;
    lua_createtable(L, 0, 0);
    uint64Metatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
}

void shutdown_common(lua_State *L) {
    global_lua_state = nullptr;
    luaL_unref(L, LUA_REGISTRYINDEX, uint64Metatable_ref);
    uint64Metatable_ref = LUA_NOREF;
}

} // namespace luasteam
