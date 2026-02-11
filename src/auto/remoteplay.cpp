#include "auto.hpp"

namespace luasteam {

int RemotePlay_ref = LUA_NOREF;

namespace {

class CallbackListener {
  private:
    STEAM_CALLBACK(CallbackListener, OnSteamRemotePlaySessionConnected, SteamRemotePlaySessionConnected_t);
    STEAM_CALLBACK(CallbackListener, OnSteamRemotePlaySessionDisconnected, SteamRemotePlaySessionDisconnected_t);
    STEAM_CALLBACK(CallbackListener, OnSteamRemotePlayTogetherGuestInvite, SteamRemotePlayTogetherGuestInvite_t);
};

void CallbackListener::OnSteamRemotePlaySessionConnected(SteamRemotePlaySessionConnected_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemotePlay_ref);
    lua_getfield(L, -1, "OnSteamRemotePlaySessionConnected");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushinteger(L, data->m_unSessionID);
        lua_setfield(L, -2, "m_unSessionID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnSteamRemotePlaySessionDisconnected(SteamRemotePlaySessionDisconnected_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemotePlay_ref);
    lua_getfield(L, -1, "OnSteamRemotePlaySessionDisconnected");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushinteger(L, data->m_unSessionID);
        lua_setfield(L, -2, "m_unSessionID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnSteamRemotePlayTogetherGuestInvite(SteamRemotePlayTogetherGuestInvite_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemotePlay_ref);
    lua_getfield(L, -1, "OnSteamRemotePlayTogetherGuestInvite");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        // Skip unsupported type: char [1024]
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

CallbackListener *RemotePlay_listener = nullptr;

} // namespace

void init_RemotePlay_auto(lua_State *L) { RemotePlay_listener = new CallbackListener(); }

void shutdown_RemotePlay_auto(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, RemotePlay_ref);
    RemotePlay_ref = LUA_NOREF;
    delete RemotePlay_listener; RemotePlay_listener = nullptr;
}


// uint32 GetSessionCount();
EXTERN int luasteam_RemotePlay_GetSessionCount(lua_State *L) {
    lua_pushinteger(L, SteamRemotePlay()->GetSessionCount());
    return 1;
}

// RemotePlaySessionID_t GetSessionID(int iSessionIndex);
EXTERN int luasteam_RemotePlay_GetSessionID(lua_State *L) {
    int iSessionIndex = static_cast<int>(luaL_checkint(L, 1));
    lua_pushinteger(L, SteamRemotePlay()->GetSessionID(iSessionIndex));
    return 1;
}

// CSteamID GetSessionSteamID(RemotePlaySessionID_t unSessionID);
EXTERN int luasteam_RemotePlay_GetSessionSteamID(lua_State *L) {
    RemotePlaySessionID_t unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, 1));
    luasteam::pushuint64(L, SteamRemotePlay()->GetSessionSteamID(unSessionID).ConvertToUint64());
    return 1;
}

// const char * GetSessionClientName(RemotePlaySessionID_t unSessionID);
EXTERN int luasteam_RemotePlay_GetSessionClientName(lua_State *L) {
    RemotePlaySessionID_t unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, 1));
    lua_pushstring(L, SteamRemotePlay()->GetSessionClientName(unSessionID));
    return 1;
}

// ESteamDeviceFormFactor GetSessionClientFormFactor(RemotePlaySessionID_t unSessionID);
EXTERN int luasteam_RemotePlay_GetSessionClientFormFactor(lua_State *L) {
    RemotePlaySessionID_t unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, 1));
    lua_pushinteger(L, SteamRemotePlay()->GetSessionClientFormFactor(unSessionID));
    return 1;
}

// bool ShowRemotePlayTogetherUI();
EXTERN int luasteam_RemotePlay_ShowRemotePlayTogetherUI(lua_State *L) {
    lua_pushboolean(L, SteamRemotePlay()->ShowRemotePlayTogetherUI());
    return 1;
}

// bool BSendRemotePlayTogetherInvite(CSteamID steamIDFriend);
EXTERN int luasteam_RemotePlay_BSendRemotePlayTogetherInvite(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    lua_pushboolean(L, SteamRemotePlay()->BSendRemotePlayTogetherInvite(steamIDFriend));
    return 1;
}

// bool BEnableRemotePlayTogetherDirectInput();
EXTERN int luasteam_RemotePlay_BEnableRemotePlayTogetherDirectInput(lua_State *L) {
    lua_pushboolean(L, SteamRemotePlay()->BEnableRemotePlayTogetherDirectInput());
    return 1;
}

// void DisableRemotePlayTogetherDirectInput();
EXTERN int luasteam_RemotePlay_DisableRemotePlayTogetherDirectInput(lua_State *L) {
    SteamRemotePlay()->DisableRemotePlayTogetherDirectInput();
    return 0;
}

// void SetMouseVisibility(RemotePlaySessionID_t unSessionID, bool bVisible);
EXTERN int luasteam_RemotePlay_SetMouseVisibility(lua_State *L) {
    RemotePlaySessionID_t unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, 1));
    bool bVisible = lua_toboolean(L, 2);
    SteamRemotePlay()->SetMouseVisibility(unSessionID, bVisible);
    return 0;
}

// void SetMousePosition(RemotePlaySessionID_t unSessionID, float flNormalizedX, float flNormalizedY);
EXTERN int luasteam_RemotePlay_SetMousePosition(lua_State *L) {
    RemotePlaySessionID_t unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, 1));
    float flNormalizedX = luaL_checknumber(L, 2);
    float flNormalizedY = luaL_checknumber(L, 3);
    SteamRemotePlay()->SetMousePosition(unSessionID, flNormalizedX, flNormalizedY);
    return 0;
}

// void SetMouseCursor(RemotePlaySessionID_t unSessionID, RemotePlayCursorID_t unCursorID);
EXTERN int luasteam_RemotePlay_SetMouseCursor(lua_State *L) {
    RemotePlaySessionID_t unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, 1));
    RemotePlayCursorID_t unCursorID = static_cast<RemotePlayCursorID_t>(luaL_checkint(L, 2));
    SteamRemotePlay()->SetMouseCursor(unSessionID, unCursorID);
    return 0;
}

void register_RemotePlay_auto(lua_State *L) {
    add_func(L, "GetSessionCount", luasteam_RemotePlay_GetSessionCount);
    add_func(L, "GetSessionID", luasteam_RemotePlay_GetSessionID);
    add_func(L, "GetSessionSteamID", luasteam_RemotePlay_GetSessionSteamID);
    add_func(L, "GetSessionClientName", luasteam_RemotePlay_GetSessionClientName);
    add_func(L, "GetSessionClientFormFactor", luasteam_RemotePlay_GetSessionClientFormFactor);
    add_func(L, "ShowRemotePlayTogetherUI", luasteam_RemotePlay_ShowRemotePlayTogetherUI);
    add_func(L, "BSendRemotePlayTogetherInvite", luasteam_RemotePlay_BSendRemotePlayTogetherInvite);
    add_func(L, "BEnableRemotePlayTogetherDirectInput", luasteam_RemotePlay_BEnableRemotePlayTogetherDirectInput);
    add_func(L, "DisableRemotePlayTogetherDirectInput", luasteam_RemotePlay_DisableRemotePlayTogetherDirectInput);
    add_func(L, "SetMouseVisibility", luasteam_RemotePlay_SetMouseVisibility);
    add_func(L, "SetMousePosition", luasteam_RemotePlay_SetMousePosition);
    add_func(L, "SetMouseCursor", luasteam_RemotePlay_SetMouseCursor);
}

void add_RemotePlay_auto(lua_State *L) {
    lua_createtable(L, 0, 12);
    register_RemotePlay_auto(L);
    lua_pushvalue(L, -1);
    RemotePlay_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "RemotePlay");
}

} // namespace luasteam
