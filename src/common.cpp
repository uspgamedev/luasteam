#include "common.hpp"
#include <string>

namespace {
int uint64Metatable_ref = LUA_NOREF;
int steamNetworkingIdentityMetatable_ref = LUA_NOREF;

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

// In C++: bool SteamNetworkingIdentity::ParseString(const char *pszStr)
// identity:ParseString(str) → bool  (parses a string representation into this identity)
static int luasteam_SteamNetworkingIdentity_ParseString(lua_State *L) {
    SteamNetworkingIdentity *identity = reinterpret_cast<SteamNetworkingIdentity *>(lua_touserdata(L, 1));
    const char *str = luaL_checkstring(L, 2);
    lua_pushboolean(L, identity->ParseString(str));
    return 1;
}

// In C++: void SteamNetworkingIdentity::ToString(char *buf, size_t cbBuf) const
// identity:ToString() → str
static int luasteam_SteamNetworkingIdentity_ToString(lua_State *L) {
    SteamNetworkingIdentity *identity = reinterpret_cast<SteamNetworkingIdentity *>(lua_touserdata(L, 1));
    char buf[SteamNetworkingIdentity::k_cchMaxString];
    identity->ToString(buf, sizeof(buf));
    lua_pushstring(L, buf);
    return 1;
}

// identity:SetSteamID(steamID: uint64)
static int luasteam_SteamNetworkingIdentity_SetSteamID(lua_State *L) {
    SteamNetworkingIdentity *identity = reinterpret_cast<SteamNetworkingIdentity *>(lua_touserdata(L, 1));
    identity->SetSteamID(CSteamID(luasteam::checkuint64(L, 2)));
    return 0;
}

// identity:GetSteamID() → uint64 (returns 0 if not a SteamID identity)
static int luasteam_SteamNetworkingIdentity_GetSteamID(lua_State *L) {
    SteamNetworkingIdentity *identity = reinterpret_cast<SteamNetworkingIdentity *>(lua_touserdata(L, 1));
    luasteam::pushuint64(L, identity->GetSteamID().ConvertToUint64());
    return 1;
}

// luasteam.newSteamNetworkingIdentity() → SteamNetworkingIdentity userdata
EXTERN int luasteam_newSteamNetworkingIdentity(lua_State *L) {
    SteamNetworkingIdentity *ptr = reinterpret_cast<SteamNetworkingIdentity *>(lua_newuserdata(L, sizeof(SteamNetworkingIdentity)));
    ptr->Clear();
    lua_rawgeti(L, LUA_REGISTRYINDEX, steamNetworkingIdentityMetatable_ref);
    lua_setmetatable(L, -2);
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

void pushvoid_ptr(lua_State *L, void *v) { lua_pushlightuserdata(L, v); }

void *checkvoid_ptr(lua_State *L, int nParam) {
    luaL_argcheck(L, lua_islightuserdata(L, nParam), nParam, "must be opaque pointer");
    return lua_touserdata(L, nParam);
}

void push_SteamNetworkingIdentity(lua_State *L, SteamNetworkingIdentity val) {
    SteamNetworkingIdentity *ptr = reinterpret_cast<SteamNetworkingIdentity *>(lua_newuserdata(L, sizeof(SteamNetworkingIdentity)));
    *ptr = val;
    lua_rawgeti(L, LUA_REGISTRYINDEX, steamNetworkingIdentityMetatable_ref);
    lua_setmetatable(L, -2);
}

SteamNetworkingIdentity check_SteamNetworkingIdentity(lua_State *L, int nParam) { return *check_SteamNetworkingIdentity_ptr(L, nParam); }

SteamNetworkingIdentity *check_SteamNetworkingIdentity_ptr(lua_State *L, int nParam) {
    luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "must be SteamNetworkingIdentity userdata");
    lua_rawgeti(L, LUA_REGISTRYINDEX, steamNetworkingIdentityMetatable_ref);
    lua_getmetatable(L, nParam);
    luaL_argcheck(L, lua_rawequal(L, -2, -1), nParam, "must be SteamNetworkingIdentity userdata");
    lua_pop(L, 2);
    return reinterpret_cast<SteamNetworkingIdentity *>(lua_touserdata(L, nParam));
}

void add_func(lua_State *L, const char *name, lua_CFunction func) {
    lua_pushcfunction(L, func);
    lua_setfield(L, -2, name);
}

void init_common(lua_State *L) {
    global_lua_state = L;
    // uint64 metatable
    lua_createtable(L, 0, 2);
    add_func(L, "__eq", luasteam_equint64);
    add_func(L, "__tostring", luasteam_uint64ToString);
    uint64Metatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    // SteamNetworkingIdentity metatable
    lua_createtable(L, 0, 4);
    add_func(L, "ParseString", luasteam_SteamNetworkingIdentity_ParseString);
    add_func(L, "ToString", luasteam_SteamNetworkingIdentity_ToString);
    add_func(L, "SetSteamID", luasteam_SteamNetworkingIdentity_SetSteamID);
    add_func(L, "GetSteamID", luasteam_SteamNetworkingIdentity_GetSteamID);
    lua_pushvalue(L, -1);
    lua_setfield(L, -2, "__index");
    steamNetworkingIdentityMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
}

void shutdown_common(lua_State *L) {
    global_lua_state = nullptr;
    luaL_unref(L, LUA_REGISTRYINDEX, uint64Metatable_ref);
    uint64Metatable_ref = LUA_NOREF;
    luaL_unref(L, LUA_REGISTRYINDEX, steamNetworkingIdentityMetatable_ref);
    steamNetworkingIdentityMetatable_ref = LUA_NOREF;
}

} // namespace luasteam
