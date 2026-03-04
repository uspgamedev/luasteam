#include "Common.hpp"
#include <string>

namespace {
int uint64Metatable_ref = LUA_NOREF;
int readonly_table_Metatable_ref = LUA_NOREF;

static int readonly_table_newindex(lua_State *L) { return luaL_error(L, "array fields are read-only; assign a new table directly to the struct field"); }

void my_assert(lua_State *L, int cond, const char *fmt, va_list list) {
    if (cond) {
        return;
    }
    lua_pushvfstring(L, fmt, list);
    lua_error(L);
}

} // namespace

EXTERN int luasteam_equint64(lua_State *L) { return luasteam::checkuint64(L, 1) == luasteam::checkuint64(L, 2); }

EXTERN int luasteam_uint64ToString(lua_State *L) {
    uint64 x = luasteam::checkuint64(L, 1);
    lua_pushstring(L, std::to_string(x).data());
    return 1;
}

EXTERN int luasteam_uint64ToNumber(lua_State *L) {
    uint64 x = luasteam::checkuint64(L, 1);
    lua_pushnumber(L, (lua_Number)x);
    return 1;
}

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

uint64 assertuint64(lua_State *L, int index, const char *fmt, ...) {
    va_list list;
    va_start(list, fmt);
    my_assert(L, lua_isuserdata(L, index), fmt, list);
    lua_rawgeti(L, LUA_REGISTRYINDEX, uint64Metatable_ref);
    lua_getmetatable(L, index);
    my_assert(L, lua_rawequal(L, -2, -1), fmt, list);
    lua_pop(L, 2);
    uint64 *ptr = reinterpret_cast<uint64 *>(lua_touserdata(L, index));
    return *ptr;
}

void copy_str_into(const char *&dest, const char *src) {
    if (dest != nullptr) {
        delete[] dest;
    }
    char *new_dest = new char[strlen(src) + 1];
    strcpy(new_dest, src);
    dest = new_dest;
}

void set_readonly_table_metatable(lua_State *L) {
    lua_rawgeti(L, LUA_REGISTRYINDEX, readonly_table_Metatable_ref);
    lua_setmetatable(L, -2);
}

void add_func(lua_State *L, const char *name, lua_CFunction func) {
    lua_pushcfunction(L, func);
    lua_setfield(L, -2, name);
}

void init_Common(lua_State *L) {
    if (global_lua_state != nullptr)
        return;
    global_lua_state = L;
    // uint64 metatable
    lua_createtable(L, 0, 6);
    add_func(L, "__eq", luasteam_equint64);
    add_func(L, "__tostring", luasteam_uint64ToString);
    add_func(L, "tostring", luasteam_uint64ToString);
    add_func(L, "__tonumber", luasteam_uint64ToNumber);
    add_func(L, "tonumber", luasteam_uint64ToNumber);
    lua_pushvalue(L, -1); // __index = metatable itself
    lua_setfield(L, -2, "__index");
    uint64Metatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    // read-only table metatable (used for string array field getters)
    lua_createtable(L, 0, 1);
    add_func(L, "__newindex", readonly_table_newindex);
    readonly_table_Metatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
}

void shutdown_Common(lua_State *L) {
    global_lua_state = nullptr;
    luaL_unref(L, LUA_REGISTRYINDEX, uint64Metatable_ref);
    uint64Metatable_ref = LUA_NOREF;
    luaL_unref(L, LUA_REGISTRYINDEX, readonly_table_Metatable_ref);
    readonly_table_Metatable_ref = LUA_NOREF;
}

} // namespace luasteam
