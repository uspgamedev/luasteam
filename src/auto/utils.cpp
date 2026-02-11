#include "auto.hpp"

// uint32 GetSecondsSinceAppActive();
EXTERN int luasteam_utils_SteamAPI_ISteamUtils_GetSecondsSinceAppActive(lua_State *L) {
    lua_pushinteger(L, SteamUtils()->GetSecondsSinceAppActive());
    return 1;
}

// uint32 GetSecondsSinceComputerActive();
EXTERN int luasteam_utils_SteamAPI_ISteamUtils_GetSecondsSinceComputerActive(lua_State *L) {
    lua_pushinteger(L, SteamUtils()->GetSecondsSinceComputerActive());
    return 1;
}

// uint32 GetServerRealTime();
EXTERN int luasteam_utils_SteamAPI_ISteamUtils_GetServerRealTime(lua_State *L) {
    lua_pushinteger(L, SteamUtils()->GetServerRealTime());
    return 1;
}

// const char * GetIPCountry();
EXTERN int luasteam_utils_SteamAPI_ISteamUtils_GetIPCountry(lua_State *L) {
    lua_pushstring(L, SteamUtils()->GetIPCountry());
    return 1;
}

// uint8 GetCurrentBatteryPower();
EXTERN int luasteam_utils_SteamAPI_ISteamUtils_GetCurrentBatteryPower(lua_State *L) {
    lua_pushinteger(L, SteamUtils()->GetCurrentBatteryPower());
    return 1;
}

// uint32 GetAppID();
EXTERN int luasteam_utils_SteamAPI_ISteamUtils_GetAppID(lua_State *L) {
    lua_pushinteger(L, SteamUtils()->GetAppID());
    return 1;
}

// uint32 GetIPCCallCount();
EXTERN int luasteam_utils_SteamAPI_ISteamUtils_GetIPCCallCount(lua_State *L) {
    lua_pushinteger(L, SteamUtils()->GetIPCCallCount());
    return 1;
}

// bool IsOverlayEnabled();
EXTERN int luasteam_utils_SteamAPI_ISteamUtils_IsOverlayEnabled(lua_State *L) {
    lua_pushboolean(L, SteamUtils()->IsOverlayEnabled());
    return 1;
}

// bool BOverlayNeedsPresent();
EXTERN int luasteam_utils_SteamAPI_ISteamUtils_BOverlayNeedsPresent(lua_State *L) {
    lua_pushboolean(L, SteamUtils()->BOverlayNeedsPresent());
    return 1;
}

// SteamAPICall_t CheckFileSignature(const char * szFileName);
EXTERN int luasteam_utils_SteamAPI_ISteamUtils_CheckFileSignature(lua_State *L) {
    const char *szFileName = luaL_checkstring(L, 1);
    luasteam::pushuint64(L, SteamUtils()->CheckFileSignature(szFileName));
    return 1;
}

// uint32 GetEnteredGamepadTextLength();
EXTERN int luasteam_utils_SteamAPI_ISteamUtils_GetEnteredGamepadTextLength(lua_State *L) {
    lua_pushinteger(L, SteamUtils()->GetEnteredGamepadTextLength());
    return 1;
}

// const char * GetSteamUILanguage();
EXTERN int luasteam_utils_SteamAPI_ISteamUtils_GetSteamUILanguage(lua_State *L) {
    lua_pushstring(L, SteamUtils()->GetSteamUILanguage());
    return 1;
}

// bool IsSteamRunningInVR();
EXTERN int luasteam_utils_SteamAPI_ISteamUtils_IsSteamRunningInVR(lua_State *L) {
    lua_pushboolean(L, SteamUtils()->IsSteamRunningInVR());
    return 1;
}

// void SetOverlayNotificationInset(int nHorizontalInset, int nVerticalInset);
EXTERN int luasteam_utils_SteamAPI_ISteamUtils_SetOverlayNotificationInset(lua_State *L) {
    int nHorizontalInset = luaL_checkint(L, 1);
    int nVerticalInset = luaL_checkint(L, 2);
    SteamUtils()->SetOverlayNotificationInset(nHorizontalInset, nVerticalInset);
    return 0;
}

// bool IsSteamInBigPictureMode();
EXTERN int luasteam_utils_SteamAPI_ISteamUtils_IsSteamInBigPictureMode(lua_State *L) {
    lua_pushboolean(L, SteamUtils()->IsSteamInBigPictureMode());
    return 1;
}

// void StartVRDashboard();
EXTERN int luasteam_utils_SteamAPI_ISteamUtils_StartVRDashboard(lua_State *L) {
    SteamUtils()->StartVRDashboard();
    return 0;
}

// bool IsVRHeadsetStreamingEnabled();
EXTERN int luasteam_utils_SteamAPI_ISteamUtils_IsVRHeadsetStreamingEnabled(lua_State *L) {
    lua_pushboolean(L, SteamUtils()->IsVRHeadsetStreamingEnabled());
    return 1;
}

// void SetVRHeadsetStreamingEnabled(bool bEnabled);
EXTERN int luasteam_utils_SteamAPI_ISteamUtils_SetVRHeadsetStreamingEnabled(lua_State *L) {
    bool bEnabled = lua_toboolean(L, 1);
    SteamUtils()->SetVRHeadsetStreamingEnabled(bEnabled);
    return 0;
}

// bool IsSteamChinaLauncher();
EXTERN int luasteam_utils_SteamAPI_ISteamUtils_IsSteamChinaLauncher(lua_State *L) {
    lua_pushboolean(L, SteamUtils()->IsSteamChinaLauncher());
    return 1;
}

// bool InitFilterText(uint32 unFilterOptions);
EXTERN int luasteam_utils_SteamAPI_ISteamUtils_InitFilterText(lua_State *L) {
    uint32 unFilterOptions = luaL_checkint(L, 1);
    lua_pushboolean(L, SteamUtils()->InitFilterText(unFilterOptions));
    return 1;
}

// bool IsSteamRunningOnSteamDeck();
EXTERN int luasteam_utils_SteamAPI_ISteamUtils_IsSteamRunningOnSteamDeck(lua_State *L) {
    lua_pushboolean(L, SteamUtils()->IsSteamRunningOnSteamDeck());
    return 1;
}

// void SetGameLauncherMode(bool bLauncherMode);
EXTERN int luasteam_utils_SteamAPI_ISteamUtils_SetGameLauncherMode(lua_State *L) {
    bool bLauncherMode = lua_toboolean(L, 1);
    SteamUtils()->SetGameLauncherMode(bLauncherMode);
    return 0;
}

// bool DismissFloatingGamepadTextInput();
EXTERN int luasteam_utils_SteamAPI_ISteamUtils_DismissFloatingGamepadTextInput(lua_State *L) {
    lua_pushboolean(L, SteamUtils()->DismissFloatingGamepadTextInput());
    return 1;
}

// bool DismissGamepadTextInput();
EXTERN int luasteam_utils_SteamAPI_ISteamUtils_DismissGamepadTextInput(lua_State *L) {
    lua_pushboolean(L, SteamUtils()->DismissGamepadTextInput());
    return 1;
}

namespace luasteam {

void add_utils_auto(lua_State *L) {
    add_func(L, "getSecondsSinceAppActive", luasteam_utils_SteamAPI_ISteamUtils_GetSecondsSinceAppActive);
    add_func(L, "getSecondsSinceComputerActive", luasteam_utils_SteamAPI_ISteamUtils_GetSecondsSinceComputerActive);
    add_func(L, "getServerRealTime", luasteam_utils_SteamAPI_ISteamUtils_GetServerRealTime);
    add_func(L, "getIPCountry", luasteam_utils_SteamAPI_ISteamUtils_GetIPCountry);
    add_func(L, "getCurrentBatteryPower", luasteam_utils_SteamAPI_ISteamUtils_GetCurrentBatteryPower);
    add_func(L, "getAppID", luasteam_utils_SteamAPI_ISteamUtils_GetAppID);
    add_func(L, "getIPCCallCount", luasteam_utils_SteamAPI_ISteamUtils_GetIPCCallCount);
    add_func(L, "isOverlayEnabled", luasteam_utils_SteamAPI_ISteamUtils_IsOverlayEnabled);
    add_func(L, "overlayNeedsPresent", luasteam_utils_SteamAPI_ISteamUtils_BOverlayNeedsPresent);
    add_func(L, "checkFileSignature", luasteam_utils_SteamAPI_ISteamUtils_CheckFileSignature);
    add_func(L, "getEnteredGamepadTextLength", luasteam_utils_SteamAPI_ISteamUtils_GetEnteredGamepadTextLength);
    add_func(L, "getSteamUILanguage", luasteam_utils_SteamAPI_ISteamUtils_GetSteamUILanguage);
    add_func(L, "isSteamRunningInVR", luasteam_utils_SteamAPI_ISteamUtils_IsSteamRunningInVR);
    add_func(L, "setOverlayNotificationInset", luasteam_utils_SteamAPI_ISteamUtils_SetOverlayNotificationInset);
    add_func(L, "isSteamInBigPictureMode", luasteam_utils_SteamAPI_ISteamUtils_IsSteamInBigPictureMode);
    add_func(L, "startVRDashboard", luasteam_utils_SteamAPI_ISteamUtils_StartVRDashboard);
    add_func(L, "isVRHeadsetStreamingEnabled", luasteam_utils_SteamAPI_ISteamUtils_IsVRHeadsetStreamingEnabled);
    add_func(L, "setVRHeadsetStreamingEnabled", luasteam_utils_SteamAPI_ISteamUtils_SetVRHeadsetStreamingEnabled);
    add_func(L, "isSteamChinaLauncher", luasteam_utils_SteamAPI_ISteamUtils_IsSteamChinaLauncher);
    add_func(L, "initFilterText", luasteam_utils_SteamAPI_ISteamUtils_InitFilterText);
    add_func(L, "isSteamRunningOnSteamDeck", luasteam_utils_SteamAPI_ISteamUtils_IsSteamRunningOnSteamDeck);
    add_func(L, "setGameLauncherMode", luasteam_utils_SteamAPI_ISteamUtils_SetGameLauncherMode);
    add_func(L, "dismissFloatingGamepadTextInput", luasteam_utils_SteamAPI_ISteamUtils_DismissFloatingGamepadTextInput);
    add_func(L, "dismissGamepadTextInput", luasteam_utils_SteamAPI_ISteamUtils_DismissGamepadTextInput);
}

} // namespace luasteam
