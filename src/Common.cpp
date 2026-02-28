#include "Common.hpp"
#include <string>

namespace {
int uint64Metatable_ref = LUA_NOREF;

void my_assert(lua_State *L, int cond, const char *fmt, va_list list) {
    if (cond) {
        return;
    }
    lua_pushvfstring(L, fmt, list);
    lua_error(L);
}

// Returns the uint64 value of a stack slot, accepting both uint64 userdata and Lua numbers.
bool get_uint64_coerce(lua_State *L, int idx, uint64 &out) {
    if (lua_isuserdata(L, idx)) {
        lua_rawgeti(L, LUA_REGISTRYINDEX, uint64Metatable_ref);
        lua_getmetatable(L, idx);
        bool ok = lua_rawequal(L, -2, -1) != 0;
        lua_pop(L, 2);
        if (ok) {
            out = *reinterpret_cast<uint64 *>(lua_touserdata(L, idx));
            return true;
        }
    } else if (lua_isnumber(L, idx)) {
        out = (uint64)lua_tonumber(L, idx);
        return true;
    }
    return false;
}

} // namespace

EXTERN int luasteam_equint64(lua_State *L) { return luasteam::checkuint64(L, 1) == luasteam::checkuint64(L, 2); }

EXTERN int luasteam_uint64ToString(lua_State *L) {
    uint64 x = luasteam::checkuint64(L, 1);
    lua_pushstring(L, std::to_string(x).data());
    return 1;
}

EXTERN int luasteam_ltuint64(lua_State *L) {
    uint64 a, b;
    if (!get_uint64_coerce(L, 1, a) || !get_uint64_coerce(L, 2, b))
        return luaL_error(L, "uint64: operands must be uint64 or number");
    lua_pushboolean(L, a < b);
    return 1;
}

EXTERN int luasteam_leuint64(lua_State *L) {
    uint64 a, b;
    if (!get_uint64_coerce(L, 1, a) || !get_uint64_coerce(L, 2, b))
        return luaL_error(L, "uint64: operands must be uint64 or number");
    lua_pushboolean(L, a <= b);
    return 1;
}

EXTERN int luasteam_adduint64(lua_State *L) {
    uint64 a, b;
    if (!get_uint64_coerce(L, 1, a) || !get_uint64_coerce(L, 2, b))
        return luaL_error(L, "uint64: operands must be uint64 or number");
    luasteam::pushuint64(L, a + b);
    return 1;
}

EXTERN int luasteam_subuint64(lua_State *L) {
    uint64 a, b;
    if (!get_uint64_coerce(L, 1, a) || !get_uint64_coerce(L, 2, b))
        return luaL_error(L, "uint64: operands must be uint64 or number");
    luasteam::pushuint64(L, a - b);
    return 1;
}

EXTERN int luasteam_muluint64(lua_State *L) {
    uint64 a, b;
    if (!get_uint64_coerce(L, 1, a) || !get_uint64_coerce(L, 2, b))
        return luaL_error(L, "uint64: operands must be uint64 or number");
    luasteam::pushuint64(L, a * b);
    return 1;
}

EXTERN int luasteam_divuint64(lua_State *L) {
    uint64 a, b;
    if (!get_uint64_coerce(L, 1, a) || !get_uint64_coerce(L, 2, b))
        return luaL_error(L, "uint64: operands must be uint64 or number");
    if (b == 0)
        return luaL_error(L, "uint64: division by zero");
    luasteam::pushuint64(L, a / b);
    return 1;
}

EXTERN int luasteam_moduint64(lua_State *L) {
    uint64 a, b;
    if (!get_uint64_coerce(L, 1, a) || !get_uint64_coerce(L, 2, b))
        return luaL_error(L, "uint64: operands must be uint64 or number");
    if (b == 0)
        return luaL_error(L, "uint64: modulo by zero");
    luasteam::pushuint64(L, a % b);
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

void add_func(lua_State *L, const char *name, lua_CFunction func) {
    lua_pushcfunction(L, func);
    lua_setfield(L, -2, name);
}

void init_Common(lua_State *L) {
    if (global_lua_state != nullptr)
        return;
    global_lua_state = L;
    // uint64 metatable
    lua_createtable(L, 0, 10);
    add_func(L, "__eq", luasteam_equint64);
    add_func(L, "__lt", luasteam_ltuint64);
    add_func(L, "__le", luasteam_leuint64);
    add_func(L, "__add", luasteam_adduint64);
    add_func(L, "__sub", luasteam_subuint64);
    add_func(L, "__mul", luasteam_muluint64);
    add_func(L, "__div", luasteam_divuint64);
    add_func(L, "__mod", luasteam_moduint64);
    add_func(L, "__tostring", luasteam_uint64ToString);
    uint64Metatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
}

void shutdown_Common(lua_State *L) {
    global_lua_state = nullptr;
    luaL_unref(L, LUA_REGISTRYINDEX, uint64Metatable_ref);
    uint64Metatable_ref = LUA_NOREF;
}

} // namespace luasteam
