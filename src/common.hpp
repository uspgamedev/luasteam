#ifndef LUASTEAM_COMMON
#define LUASTEAM_COMMON

#include "../sdk/public/steam/steam_api.h"
#include "../sdk/public/steam/steam_gameserver.h"
#include "../sdk/public/steam/steamnetworkingfakeip.h"
extern "C" {
#include <lauxlib.h>
#include <lua.h>
}

#ifdef _WIN32
#    define EXTERN extern "C" __declspec(dllexport)
#else
#    define EXTERN extern "C"
#endif

namespace luasteam {

// Use this with care. Should only be used for Callbacks and CallResults.
extern lua_State *global_lua_state;

// using userdata since Lua's number can't safely hold 64-bit integers
void pushuint64(lua_State *L, uint64 v);
uint64 checkuint64(lua_State *L, int nParam);
uint64 assertuint64(lua_State *L, int index, const char *fmt, ...);

// using lightuserdata for opaque pointers (void*, HServerListRequest, etc.)
void pushvoid_ptr(lua_State *L, void *v);
void *checkvoid_ptr(lua_State *L, int nParam);

// SteamNetworkingIdentity userdata — stores the struct value inside Lua userdata.
// Lua API: luasteam.newSteamNetworkingIdentity(), identity:ParseString(str), identity:ToString()
void push_SteamNetworkingIdentity(lua_State *L, SteamNetworkingIdentity val);
SteamNetworkingIdentity check_SteamNetworkingIdentity(lua_State *L, int nParam);
// Returns a pointer directly into the userdata storage — avoids a copy for const pointer/reference params.
SteamNetworkingIdentity *check_SteamNetworkingIdentity_ptr(lua_State *L, int nParam);

// Adds a C function to the table on top of the stack, with given name
void add_func(lua_State *L, const char *name, lua_CFunction func);

template <typename T> class CallResultListener {
  public:
    int callback_ref = LUA_NOREF;
    void Result(T *data, bool io_fail);
    CCallResult<CallResultListener, T> call_result;
};

void init_common(lua_State *L);
void shutdown_common(lua_State *L);

} // namespace luasteam

// luasteam.newSteamNetworkingIdentity() constructor — exposed for registration in luaopen_luasteam
EXTERN int luasteam_newSteamNetworkingIdentity(lua_State *L);

#endif // LUASTEAM_COMMON
