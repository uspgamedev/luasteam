#include "auto.hpp"

namespace luasteam {

int remoteplay_ref = LUA_NOREF;

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
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::remoteplay_ref);
    lua_getfield(L, -1, "onSteamRemotePlaySessionConnected");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushinteger(L, data->m_unSessionID);
        lua_setfield(L, -2, "sessionID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnSteamRemotePlaySessionDisconnected(SteamRemotePlaySessionDisconnected_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::remoteplay_ref);
    lua_getfield(L, -1, "onSteamRemotePlaySessionDisconnected");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushinteger(L, data->m_unSessionID);
        lua_setfield(L, -2, "sessionID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnSteamRemotePlayTogetherGuestInvite(SteamRemotePlayTogetherGuestInvite_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::remoteplay_ref);
    lua_getfield(L, -1, "onSteamRemotePlayTogetherGuestInvite");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushstring(L, data->m_szConnectURL);
        lua_setfield(L, -2, "connectURL");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

CallbackListener *remoteplay_listener = nullptr;

} // namespace

void init_remoteplay_auto(lua_State *L) { remoteplay_listener = new CallbackListener(); }

void shutdown_remoteplay_auto(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, remoteplay_ref);
    remoteplay_ref = LUA_NOREF;
    delete remoteplay_listener; remoteplay_listener = nullptr;
}


// uint32 GetSessionCount();
EXTERN int luasteam_remoteplay_SteamAPI_ISteamRemotePlay_GetSessionCount(lua_State *L) {
    lua_pushinteger(L, SteamRemotePlay()->GetSessionCount());
    return 1;
}

// RemotePlaySessionID_t GetSessionID(int iSessionIndex);
EXTERN int luasteam_remoteplay_SteamAPI_ISteamRemotePlay_GetSessionID(lua_State *L) {
    int iSessionIndex = static_cast<int>(luaL_checkint(L, 1));
    lua_pushinteger(L, SteamRemotePlay()->GetSessionID(iSessionIndex));
    return 1;
}

// CSteamID GetSessionSteamID(RemotePlaySessionID_t unSessionID);
EXTERN int luasteam_remoteplay_SteamAPI_ISteamRemotePlay_GetSessionSteamID(lua_State *L) {
    RemotePlaySessionID_t unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, 1));
    luasteam::pushuint64(L, (SteamRemotePlay()->GetSessionSteamID(unSessionID)).ConvertToUint64());
    return 1;
}

// const char * GetSessionClientName(RemotePlaySessionID_t unSessionID);
EXTERN int luasteam_remoteplay_SteamAPI_ISteamRemotePlay_GetSessionClientName(lua_State *L) {
    RemotePlaySessionID_t unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, 1));
    lua_pushstring(L, SteamRemotePlay()->GetSessionClientName(unSessionID));
    return 1;
}

// ESteamDeviceFormFactor GetSessionClientFormFactor(RemotePlaySessionID_t unSessionID);
EXTERN int luasteam_remoteplay_SteamAPI_ISteamRemotePlay_GetSessionClientFormFactor(lua_State *L) {
    RemotePlaySessionID_t unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, 1));
    lua_pushinteger(L, SteamRemotePlay()->GetSessionClientFormFactor(unSessionID));
    return 1;
}

// bool ShowRemotePlayTogetherUI();
EXTERN int luasteam_remoteplay_SteamAPI_ISteamRemotePlay_ShowRemotePlayTogetherUI(lua_State *L) {
    lua_pushboolean(L, SteamRemotePlay()->ShowRemotePlayTogetherUI());
    return 1;
}

// bool BSendRemotePlayTogetherInvite(CSteamID steamIDFriend);
EXTERN int luasteam_remoteplay_SteamAPI_ISteamRemotePlay_BSendRemotePlayTogetherInvite(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    lua_pushboolean(L, SteamRemotePlay()->BSendRemotePlayTogetherInvite(steamIDFriend));
    return 1;
}

// bool BEnableRemotePlayTogetherDirectInput();
EXTERN int luasteam_remoteplay_SteamAPI_ISteamRemotePlay_BEnableRemotePlayTogetherDirectInput(lua_State *L) {
    lua_pushboolean(L, SteamRemotePlay()->BEnableRemotePlayTogetherDirectInput());
    return 1;
}

// void DisableRemotePlayTogetherDirectInput();
EXTERN int luasteam_remoteplay_SteamAPI_ISteamRemotePlay_DisableRemotePlayTogetherDirectInput(lua_State *L) {
    SteamRemotePlay()->DisableRemotePlayTogetherDirectInput();
    return 0;
}

// void SetMouseVisibility(RemotePlaySessionID_t unSessionID, bool bVisible);
EXTERN int luasteam_remoteplay_SteamAPI_ISteamRemotePlay_SetMouseVisibility(lua_State *L) {
    RemotePlaySessionID_t unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, 1));
    bool bVisible = lua_toboolean(L, 2);
    SteamRemotePlay()->SetMouseVisibility(unSessionID, bVisible);
    return 0;
}

// void SetMouseCursor(RemotePlaySessionID_t unSessionID, RemotePlayCursorID_t unCursorID);
EXTERN int luasteam_remoteplay_SteamAPI_ISteamRemotePlay_SetMouseCursor(lua_State *L) {
    RemotePlaySessionID_t unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, 1));
    RemotePlayCursorID_t unCursorID = static_cast<RemotePlayCursorID_t>(luaL_checkint(L, 2));
    SteamRemotePlay()->SetMouseCursor(unSessionID, unCursorID);
    return 0;
}

void register_remoteplay_auto(lua_State *L) {
    add_func(L, "getSessionCount", luasteam_remoteplay_SteamAPI_ISteamRemotePlay_GetSessionCount);
    add_func(L, "getSessionID", luasteam_remoteplay_SteamAPI_ISteamRemotePlay_GetSessionID);
    add_func(L, "getSessionSteamID", luasteam_remoteplay_SteamAPI_ISteamRemotePlay_GetSessionSteamID);
    add_func(L, "getSessionClientName", luasteam_remoteplay_SteamAPI_ISteamRemotePlay_GetSessionClientName);
    add_func(L, "getSessionClientFormFactor", luasteam_remoteplay_SteamAPI_ISteamRemotePlay_GetSessionClientFormFactor);
    add_func(L, "showRemotePlayTogetherUI", luasteam_remoteplay_SteamAPI_ISteamRemotePlay_ShowRemotePlayTogetherUI);
    add_func(L, "sendRemotePlayTogetherInvite", luasteam_remoteplay_SteamAPI_ISteamRemotePlay_BSendRemotePlayTogetherInvite);
    add_func(L, "enableRemotePlayTogetherDirectInput", luasteam_remoteplay_SteamAPI_ISteamRemotePlay_BEnableRemotePlayTogetherDirectInput);
    add_func(L, "disableRemotePlayTogetherDirectInput", luasteam_remoteplay_SteamAPI_ISteamRemotePlay_DisableRemotePlayTogetherDirectInput);
    add_func(L, "setMouseVisibility", luasteam_remoteplay_SteamAPI_ISteamRemotePlay_SetMouseVisibility);
    add_func(L, "setMouseCursor", luasteam_remoteplay_SteamAPI_ISteamRemotePlay_SetMouseCursor);
}

void add_remoteplay_auto(lua_State *L) {
    lua_createtable(L, 0, 11);
    register_remoteplay_auto(L);
    lua_pushvalue(L, -1);
    remoteplay_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "remotePlay");
}

} // namespace luasteam
