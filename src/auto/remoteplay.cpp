#include "auto.hpp"

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

namespace luasteam {

void add_remoteplay_auto(lua_State *L) {
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

} // namespace luasteam
