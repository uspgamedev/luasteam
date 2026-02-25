#include "SteamNetworkingMessage.hpp"
#include "auto/auto.hpp"

// =============================================
// ======= SteamNetworkingMessage_t ============
// =============================================
// This binding is written manually for two reasons:
//
// 1. SteamNetworkingMessage_t is NOT in steam_api.json (it's defined in
//    steamnetworkingtypes.h), so the auto-generator never sees it. The methods
//    that deal with it (ReceiveMessages*, SendMessages, AllocateMessage) are also
//    kept manual since they all depend on this type.
//
// 2. SteamNetworkingMessage_t has a protected destructor — it cannot be
//    copied or stack-allocated. push_/check_ therefore
//    work with pointers, unlike every other struct in the codebase.
//    A __gc metamethod calls Release() as a safety net if the Lua user forgets.

static int SteamNetworkingMessage_tMetatable_ref = LUA_NOREF;

namespace luasteam {

void push_SteamNetworkingMessage_t(lua_State *L, SteamNetworkingMessage_t *msg) {
    SteamNetworkingMessage_t **ud = (SteamNetworkingMessage_t **)lua_newuserdata(L, sizeof(SteamNetworkingMessage_t *));
    *ud = msg;
    lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetworkingMessage_tMetatable_ref);
    lua_setmetatable(L, -2);
}

SteamNetworkingMessage_t *check_SteamNetworkingMessage_t(lua_State *L, int nParam) {
    luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamNetworkingMessage_t expected");
    lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetworkingMessage_tMetatable_ref);
    lua_getmetatable(L, nParam);
    bool ok = lua_rawequal(L, -1, -2);
    lua_pop(L, 2);
    luaL_argcheck(L, ok, nParam, "SteamNetworkingMessage_t expected");
    SteamNetworkingMessage_t *msg = *(SteamNetworkingMessage_t **)lua_touserdata(L, nParam);
    luaL_argcheck(L, msg != nullptr, nParam, "SteamNetworkingMessage_t already released");
    return msg;
}

} // namespace luasteam

// ---- Methods ----

static int luasteam_SteamNetworkingMessage_t_Release(lua_State *L) {
    luaL_argcheck(L, lua_isuserdata(L, 1), 1, "SteamNetworkingMessage_t expected");
    SteamNetworkingMessage_t **ud = (SteamNetworkingMessage_t **)lua_touserdata(L, 1);
    if (*ud != nullptr) {
        (*ud)->Release();
        *ud = nullptr;
    }
    return 0;
}

// __gc safety net: Release if the Lua user forgot to call :Release() explicitly.
static int luasteam_SteamNetworkingMessage_t_gc(lua_State *L) {
    SteamNetworkingMessage_t **ud = (SteamNetworkingMessage_t **)lua_touserdata(L, 1);
    if (*ud != nullptr) {
        (*ud)->Release();
        *ud = nullptr;
    }
    return 0;
}

static int luasteam_SteamNetworkingMessage_t_GetSize(lua_State *L) {
    SteamNetworkingMessage_t *self = luasteam::check_SteamNetworkingMessage_t(L, 1);
    lua_pushinteger(L, self->GetSize());
    return 1;
}

static int luasteam_SteamNetworkingMessage_t_GetData(lua_State *L) {
    SteamNetworkingMessage_t *self = luasteam::check_SteamNetworkingMessage_t(L, 1);
    lua_pushlstring(L, (const char *)self->GetData(), self->GetSize());
    return 1;
}

static int luasteam_SteamNetworkingMessage_t_GetChannel(lua_State *L) {
    SteamNetworkingMessage_t *self = luasteam::check_SteamNetworkingMessage_t(L, 1);
    lua_pushinteger(L, self->GetChannel());
    return 1;
}

static int luasteam_SteamNetworkingMessage_t_GetConnection(lua_State *L) {
    SteamNetworkingMessage_t *self = luasteam::check_SteamNetworkingMessage_t(L, 1);
    lua_pushinteger(L, self->GetConnection());
    return 1;
}

static int luasteam_SteamNetworkingMessage_t_GetConnectionUserData(lua_State *L) {
    SteamNetworkingMessage_t *self = luasteam::check_SteamNetworkingMessage_t(L, 1);
    lua_pushinteger(L, self->GetConnectionUserData());
    return 1;
}

static int luasteam_SteamNetworkingMessage_t_GetTimeReceived(lua_State *L) {
    SteamNetworkingMessage_t *self = luasteam::check_SteamNetworkingMessage_t(L, 1);
    lua_pushinteger(L, self->GetTimeReceived());
    return 1;
}

static int luasteam_SteamNetworkingMessage_t_GetMessageNumber(lua_State *L) {
    SteamNetworkingMessage_t *self = luasteam::check_SteamNetworkingMessage_t(L, 1);
    lua_pushinteger(L, self->GetMessageNumber());
    return 1;
}

// ---- __index ----

static int SteamNetworkingMessage_t_index(lua_State *L) {
    // Check metatable first (methods registered there)
    lua_getmetatable(L, 1);
    lua_pushvalue(L, 2);
    lua_rawget(L, -2);
    if (!lua_isnil(L, -1))
        return 1;
    lua_pop(L, 2);

    if (lua_type(L, 2) != LUA_TSTRING) {
        lua_pushnil(L);
        return 1;
    }
    const char *key = lua_tostring(L, 2);
    SteamNetworkingMessage_t *self = luasteam::check_SteamNetworkingMessage_t(L, 1);

    if (strcmp(key, "m_pData") == 0) {
        if (self->m_pData != nullptr && self->m_cbSize > 0) {
            lua_pushlstring(L, (const char *)self->m_pData, self->m_cbSize);
        } else {
            lua_pushstring(L, "");
        }
        return 1;
    }
    if (strcmp(key, "m_cbSize") == 0) {
        lua_pushinteger(L, self->m_cbSize);
        return 1;
    }
    if (strcmp(key, "m_conn") == 0) {
        lua_pushinteger(L, self->m_conn);
        return 1;
    }
    if (strcmp(key, "m_identityPeer") == 0) {
        luasteam::push_SteamNetworkingIdentity(L, self->m_identityPeer);
        return 1;
    }
    if (strcmp(key, "m_nConnUserData") == 0) {
        lua_pushinteger(L, self->m_nConnUserData);
        return 1;
    }
    if (strcmp(key, "m_usecTimeReceived") == 0) {
        lua_pushinteger(L, self->m_usecTimeReceived);
        return 1;
    }
    if (strcmp(key, "m_nMessageNumber") == 0) {
        lua_pushinteger(L, self->m_nMessageNumber);
        return 1;
    }
    if (strcmp(key, "m_nChannel") == 0) {
        lua_pushinteger(L, self->m_nChannel);
        return 1;
    }
    if (strcmp(key, "m_nFlags") == 0) {
        lua_pushinteger(L, self->m_nFlags);
        return 1;
    }
    if (strcmp(key, "m_nUserData") == 0) {
        lua_pushinteger(L, self->m_nUserData);
        return 1;
    }
    if (strcmp(key, "m_idxLane") == 0) {
        lua_pushinteger(L, self->m_idxLane);
        return 1;
    }
    lua_pushnil(L);
    return 1;
}

// ---- __newindex ----

static int SteamNetworkingMessage_t_newindex(lua_State *L) {
    if (lua_type(L, 2) != LUA_TSTRING)
        return 0;
    const char *key = lua_tostring(L, 2);
    SteamNetworkingMessage_t *self = luasteam::check_SteamNetworkingMessage_t(L, 1);

    if (strcmp(key, "m_pData") == 0) {
        size_t len;
        const char *data = luaL_checklstring(L, 3, &len);
        luaL_argcheck(L, (int)len <= self->m_cbSize, 3, "string too long for pre-allocated buffer (use AllocateMessage with the correct size)");
        memcpy(self->m_pData, data, len);
        self->m_cbSize = (int)len;
        return 0;
    }
    if (strcmp(key, "m_cbSize") == 0) {
        self->m_cbSize = (int)luaL_checkinteger(L, 3);
        return 0;
    }
    if (strcmp(key, "m_conn") == 0) {
        self->m_conn = (HSteamNetConnection)luaL_checkinteger(L, 3);
        return 0;
    }
    if (strcmp(key, "m_identityPeer") == 0) {
        self->m_identityPeer = luasteam::check_SteamNetworkingIdentity(L, 3);
        return 0;
    }
    if (strcmp(key, "m_nConnUserData") == 0) {
        self->m_nConnUserData = (int64)luaL_checkinteger(L, 3);
        return 0;
    }
    if (strcmp(key, "m_nChannel") == 0) {
        self->m_nChannel = (int)luaL_checkinteger(L, 3);
        return 0;
    }
    if (strcmp(key, "m_nFlags") == 0) {
        self->m_nFlags = (int)luaL_checkinteger(L, 3);
        return 0;
    }
    if (strcmp(key, "m_nUserData") == 0) {
        self->m_nUserData = (int64)luaL_checkinteger(L, 3);
        return 0;
    }
    if (strcmp(key, "m_idxLane") == 0) {
        self->m_idxLane = (uint16)luaL_checkinteger(L, 3);
        return 0;
    }
    return luaL_error(L, "SteamNetworkingMessage_t has no writable field '%s'", key);
}

namespace luasteam {

void init_SteamNetworkingMessage_t(lua_State *L) {
    lua_newtable(L);
    lua_pushcfunction(L, SteamNetworkingMessage_t_index);
    lua_setfield(L, -2, "__index");
    lua_pushcfunction(L, SteamNetworkingMessage_t_newindex);
    lua_setfield(L, -2, "__newindex");
    // Register methods into the metatable
    lua_pushcfunction(L, luasteam_SteamNetworkingMessage_t_gc);
    lua_setfield(L, -2, "__gc");
    lua_pushcfunction(L, luasteam_SteamNetworkingMessage_t_Release);
    lua_setfield(L, -2, "Release");
    lua_pushcfunction(L, luasteam_SteamNetworkingMessage_t_GetSize);
    lua_setfield(L, -2, "GetSize");
    lua_pushcfunction(L, luasteam_SteamNetworkingMessage_t_GetData);
    lua_setfield(L, -2, "GetData");
    lua_pushcfunction(L, luasteam_SteamNetworkingMessage_t_GetChannel);
    lua_setfield(L, -2, "GetChannel");
    lua_pushcfunction(L, luasteam_SteamNetworkingMessage_t_GetConnection);
    lua_setfield(L, -2, "GetConnection");
    lua_pushcfunction(L, luasteam_SteamNetworkingMessage_t_GetConnectionUserData);
    lua_setfield(L, -2, "GetConnectionUserData");
    lua_pushcfunction(L, luasteam_SteamNetworkingMessage_t_GetTimeReceived);
    lua_setfield(L, -2, "GetTimeReceived");
    lua_pushcfunction(L, luasteam_SteamNetworkingMessage_t_GetMessageNumber);
    lua_setfield(L, -2, "GetMessageNumber");
    SteamNetworkingMessage_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
}

void shutdown_SteamNetworkingMessage_t(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, SteamNetworkingMessage_tMetatable_ref);
    SteamNetworkingMessage_tMetatable_ref = LUA_NOREF;
}

} // namespace luasteam
