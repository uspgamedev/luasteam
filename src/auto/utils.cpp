#include "auto.hpp"

namespace luasteam {

int Utils_ref = LUA_NOREF;

namespace {

class CallbackListener {
  private:
    STEAM_CALLBACK(CallbackListener, OnIPCountry, IPCountry_t);
    STEAM_CALLBACK(CallbackListener, OnLowBatteryPower, LowBatteryPower_t);
    STEAM_CALLBACK(CallbackListener, OnSteamAPICallCompleted, SteamAPICallCompleted_t);
    STEAM_CALLBACK(CallbackListener, OnSteamShutdown, SteamShutdown_t);
    STEAM_CALLBACK(CallbackListener, OnCheckFileSignature, CheckFileSignature_t);
    STEAM_CALLBACK(CallbackListener, OnGamepadTextInputDismissed, GamepadTextInputDismissed_t);
    STEAM_CALLBACK(CallbackListener, OnAppResumingFromSuspend, AppResumingFromSuspend_t);
    STEAM_CALLBACK(CallbackListener, OnFloatingGamepadTextInputDismissed, FloatingGamepadTextInputDismissed_t);
    STEAM_CALLBACK(CallbackListener, OnFilterTextDictionaryChanged, FilterTextDictionaryChanged_t);
};

void CallbackListener::OnIPCountry(IPCountry_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Utils_ref);
    lua_getfield(L, -1, "OnIPCountry");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 0);
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnLowBatteryPower(LowBatteryPower_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Utils_ref);
    lua_getfield(L, -1, "OnLowBatteryPower");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushinteger(L, data->m_nMinutesBatteryLeft);
        lua_setfield(L, -2, "m_nMinutesBatteryLeft");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnSteamAPICallCompleted(SteamAPICallCompleted_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Utils_ref);
    lua_getfield(L, -1, "OnSteamAPICallCompleted");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        luasteam::pushuint64(L, data->m_hAsyncCall);
        lua_setfield(L, -2, "m_hAsyncCall");
        lua_pushinteger(L, data->m_iCallback);
        lua_setfield(L, -2, "m_iCallback");
        lua_pushinteger(L, data->m_cubParam);
        lua_setfield(L, -2, "m_cubParam");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnSteamShutdown(SteamShutdown_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Utils_ref);
    lua_getfield(L, -1, "OnSteamShutdown");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 0);
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnCheckFileSignature(CheckFileSignature_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Utils_ref);
    lua_getfield(L, -1, "OnCheckFileSignature");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushinteger(L, data->m_eCheckFileSignature);
        lua_setfield(L, -2, "m_eCheckFileSignature");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGamepadTextInputDismissed(GamepadTextInputDismissed_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Utils_ref);
    lua_getfield(L, -1, "OnGamepadTextInputDismissed");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushboolean(L, data->m_bSubmitted);
        lua_setfield(L, -2, "m_bSubmitted");
        lua_pushinteger(L, data->m_unSubmittedText);
        lua_setfield(L, -2, "m_unSubmittedText");
        lua_pushinteger(L, data->m_unAppID);
        lua_setfield(L, -2, "m_unAppID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnAppResumingFromSuspend(AppResumingFromSuspend_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Utils_ref);
    lua_getfield(L, -1, "OnAppResumingFromSuspend");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 0);
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnFloatingGamepadTextInputDismissed(FloatingGamepadTextInputDismissed_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Utils_ref);
    lua_getfield(L, -1, "OnFloatingGamepadTextInputDismissed");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 0);
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnFilterTextDictionaryChanged(FilterTextDictionaryChanged_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Utils_ref);
    lua_getfield(L, -1, "OnFilterTextDictionaryChanged");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushinteger(L, data->m_eLanguage);
        lua_setfield(L, -2, "m_eLanguage");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

CallbackListener *Utils_listener = nullptr;

} // namespace

void init_Utils_auto(lua_State *L) { Utils_listener = new CallbackListener(); }

void shutdown_Utils_auto(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, Utils_ref);
    Utils_ref = LUA_NOREF;
    delete Utils_listener; Utils_listener = nullptr;
}


// uint32 GetSecondsSinceAppActive();
EXTERN int luasteam_Utils_GetSecondsSinceAppActive(lua_State *L) {
    lua_pushinteger(L, SteamUtils()->GetSecondsSinceAppActive());
    return 1;
}

// uint32 GetSecondsSinceComputerActive();
EXTERN int luasteam_Utils_GetSecondsSinceComputerActive(lua_State *L) {
    lua_pushinteger(L, SteamUtils()->GetSecondsSinceComputerActive());
    return 1;
}

// EUniverse GetConnectedUniverse();
EXTERN int luasteam_Utils_GetConnectedUniverse(lua_State *L) {
    lua_pushinteger(L, SteamUtils()->GetConnectedUniverse());
    return 1;
}

// uint32 GetServerRealTime();
EXTERN int luasteam_Utils_GetServerRealTime(lua_State *L) {
    lua_pushinteger(L, SteamUtils()->GetServerRealTime());
    return 1;
}

// const char * GetIPCountry();
EXTERN int luasteam_Utils_GetIPCountry(lua_State *L) {
    lua_pushstring(L, SteamUtils()->GetIPCountry());
    return 1;
}

// uint8 GetCurrentBatteryPower();
EXTERN int luasteam_Utils_GetCurrentBatteryPower(lua_State *L) {
    lua_pushinteger(L, SteamUtils()->GetCurrentBatteryPower());
    return 1;
}

// uint32 GetAppID();
EXTERN int luasteam_Utils_GetAppID(lua_State *L) {
    lua_pushinteger(L, SteamUtils()->GetAppID());
    return 1;
}

// void SetOverlayNotificationPosition(ENotificationPosition eNotificationPosition);
EXTERN int luasteam_Utils_SetOverlayNotificationPosition(lua_State *L) {
    ENotificationPosition eNotificationPosition = static_cast<ENotificationPosition>(luaL_checkint(L, 1));
    SteamUtils()->SetOverlayNotificationPosition(eNotificationPosition);
    return 0;
}

// ESteamAPICallFailure GetAPICallFailureReason(SteamAPICall_t hSteamAPICall);
EXTERN int luasteam_Utils_GetAPICallFailureReason(lua_State *L) {
    SteamAPICall_t hSteamAPICall = luasteam::checkuint64(L, 1);
    lua_pushinteger(L, SteamUtils()->GetAPICallFailureReason(hSteamAPICall));
    return 1;
}

// uint32 GetIPCCallCount();
EXTERN int luasteam_Utils_GetIPCCallCount(lua_State *L) {
    lua_pushinteger(L, SteamUtils()->GetIPCCallCount());
    return 1;
}

// bool IsOverlayEnabled();
EXTERN int luasteam_Utils_IsOverlayEnabled(lua_State *L) {
    lua_pushboolean(L, SteamUtils()->IsOverlayEnabled());
    return 1;
}

// bool BOverlayNeedsPresent();
EXTERN int luasteam_Utils_BOverlayNeedsPresent(lua_State *L) {
    lua_pushboolean(L, SteamUtils()->BOverlayNeedsPresent());
    return 1;
}

// SteamAPICall_t CheckFileSignature(const char * szFileName);
EXTERN int luasteam_Utils_CheckFileSignature(lua_State *L) {
    const char *szFileName = luaL_checkstring(L, 1);
    luasteam::pushuint64(L, SteamUtils()->CheckFileSignature(szFileName));
    return 1;
}

// bool ShowGamepadTextInput(EGamepadTextInputMode eInputMode, EGamepadTextInputLineMode eLineInputMode, const char * pchDescription, uint32 unCharMax, const char * pchExistingText);
EXTERN int luasteam_Utils_ShowGamepadTextInput(lua_State *L) {
    EGamepadTextInputMode eInputMode = static_cast<EGamepadTextInputMode>(luaL_checkint(L, 1));
    EGamepadTextInputLineMode eLineInputMode = static_cast<EGamepadTextInputLineMode>(luaL_checkint(L, 2));
    const char *pchDescription = luaL_checkstring(L, 3);
    uint32 unCharMax = static_cast<uint32>(luaL_checkint(L, 4));
    const char *pchExistingText = luaL_checkstring(L, 5);
    lua_pushboolean(L, SteamUtils()->ShowGamepadTextInput(eInputMode, eLineInputMode, pchDescription, unCharMax, pchExistingText));
    return 1;
}

// uint32 GetEnteredGamepadTextLength();
EXTERN int luasteam_Utils_GetEnteredGamepadTextLength(lua_State *L) {
    lua_pushinteger(L, SteamUtils()->GetEnteredGamepadTextLength());
    return 1;
}

// const char * GetSteamUILanguage();
EXTERN int luasteam_Utils_GetSteamUILanguage(lua_State *L) {
    lua_pushstring(L, SteamUtils()->GetSteamUILanguage());
    return 1;
}

// bool IsSteamRunningInVR();
EXTERN int luasteam_Utils_IsSteamRunningInVR(lua_State *L) {
    lua_pushboolean(L, SteamUtils()->IsSteamRunningInVR());
    return 1;
}

// void SetOverlayNotificationInset(int nHorizontalInset, int nVerticalInset);
EXTERN int luasteam_Utils_SetOverlayNotificationInset(lua_State *L) {
    int nHorizontalInset = static_cast<int>(luaL_checkint(L, 1));
    int nVerticalInset = static_cast<int>(luaL_checkint(L, 2));
    SteamUtils()->SetOverlayNotificationInset(nHorizontalInset, nVerticalInset);
    return 0;
}

// bool IsSteamInBigPictureMode();
EXTERN int luasteam_Utils_IsSteamInBigPictureMode(lua_State *L) {
    lua_pushboolean(L, SteamUtils()->IsSteamInBigPictureMode());
    return 1;
}

// void StartVRDashboard();
EXTERN int luasteam_Utils_StartVRDashboard(lua_State *L) {
    SteamUtils()->StartVRDashboard();
    return 0;
}

// bool IsVRHeadsetStreamingEnabled();
EXTERN int luasteam_Utils_IsVRHeadsetStreamingEnabled(lua_State *L) {
    lua_pushboolean(L, SteamUtils()->IsVRHeadsetStreamingEnabled());
    return 1;
}

// void SetVRHeadsetStreamingEnabled(bool bEnabled);
EXTERN int luasteam_Utils_SetVRHeadsetStreamingEnabled(lua_State *L) {
    bool bEnabled = lua_toboolean(L, 1);
    SteamUtils()->SetVRHeadsetStreamingEnabled(bEnabled);
    return 0;
}

// bool IsSteamChinaLauncher();
EXTERN int luasteam_Utils_IsSteamChinaLauncher(lua_State *L) {
    lua_pushboolean(L, SteamUtils()->IsSteamChinaLauncher());
    return 1;
}

// bool InitFilterText(uint32 unFilterOptions);
EXTERN int luasteam_Utils_InitFilterText(lua_State *L) {
    uint32 unFilterOptions = static_cast<uint32>(luaL_checkint(L, 1));
    lua_pushboolean(L, SteamUtils()->InitFilterText(unFilterOptions));
    return 1;
}

// ESteamIPv6ConnectivityState GetIPv6ConnectivityState(ESteamIPv6ConnectivityProtocol eProtocol);
EXTERN int luasteam_Utils_GetIPv6ConnectivityState(lua_State *L) {
    ESteamIPv6ConnectivityProtocol eProtocol = static_cast<ESteamIPv6ConnectivityProtocol>(luaL_checkint(L, 1));
    lua_pushinteger(L, SteamUtils()->GetIPv6ConnectivityState(eProtocol));
    return 1;
}

// bool IsSteamRunningOnSteamDeck();
EXTERN int luasteam_Utils_IsSteamRunningOnSteamDeck(lua_State *L) {
    lua_pushboolean(L, SteamUtils()->IsSteamRunningOnSteamDeck());
    return 1;
}

// bool ShowFloatingGamepadTextInput(EFloatingGamepadTextInputMode eKeyboardMode, int nTextFieldXPosition, int nTextFieldYPosition, int nTextFieldWidth, int nTextFieldHeight);
EXTERN int luasteam_Utils_ShowFloatingGamepadTextInput(lua_State *L) {
    EFloatingGamepadTextInputMode eKeyboardMode = static_cast<EFloatingGamepadTextInputMode>(luaL_checkint(L, 1));
    int nTextFieldXPosition = static_cast<int>(luaL_checkint(L, 2));
    int nTextFieldYPosition = static_cast<int>(luaL_checkint(L, 3));
    int nTextFieldWidth = static_cast<int>(luaL_checkint(L, 4));
    int nTextFieldHeight = static_cast<int>(luaL_checkint(L, 5));
    lua_pushboolean(L, SteamUtils()->ShowFloatingGamepadTextInput(eKeyboardMode, nTextFieldXPosition, nTextFieldYPosition, nTextFieldWidth, nTextFieldHeight));
    return 1;
}

// void SetGameLauncherMode(bool bLauncherMode);
EXTERN int luasteam_Utils_SetGameLauncherMode(lua_State *L) {
    bool bLauncherMode = lua_toboolean(L, 1);
    SteamUtils()->SetGameLauncherMode(bLauncherMode);
    return 0;
}

// bool DismissFloatingGamepadTextInput();
EXTERN int luasteam_Utils_DismissFloatingGamepadTextInput(lua_State *L) {
    lua_pushboolean(L, SteamUtils()->DismissFloatingGamepadTextInput());
    return 1;
}

// bool DismissGamepadTextInput();
EXTERN int luasteam_Utils_DismissGamepadTextInput(lua_State *L) {
    lua_pushboolean(L, SteamUtils()->DismissGamepadTextInput());
    return 1;
}

void register_Utils_auto(lua_State *L) {
    add_func(L, "GetSecondsSinceAppActive", luasteam_Utils_GetSecondsSinceAppActive);
    add_func(L, "GetSecondsSinceComputerActive", luasteam_Utils_GetSecondsSinceComputerActive);
    add_func(L, "GetConnectedUniverse", luasteam_Utils_GetConnectedUniverse);
    add_func(L, "GetServerRealTime", luasteam_Utils_GetServerRealTime);
    add_func(L, "GetIPCountry", luasteam_Utils_GetIPCountry);
    add_func(L, "GetCurrentBatteryPower", luasteam_Utils_GetCurrentBatteryPower);
    add_func(L, "GetAppID", luasteam_Utils_GetAppID);
    add_func(L, "SetOverlayNotificationPosition", luasteam_Utils_SetOverlayNotificationPosition);
    add_func(L, "GetAPICallFailureReason", luasteam_Utils_GetAPICallFailureReason);
    add_func(L, "GetIPCCallCount", luasteam_Utils_GetIPCCallCount);
    add_func(L, "IsOverlayEnabled", luasteam_Utils_IsOverlayEnabled);
    add_func(L, "BOverlayNeedsPresent", luasteam_Utils_BOverlayNeedsPresent);
    add_func(L, "CheckFileSignature", luasteam_Utils_CheckFileSignature);
    add_func(L, "ShowGamepadTextInput", luasteam_Utils_ShowGamepadTextInput);
    add_func(L, "GetEnteredGamepadTextLength", luasteam_Utils_GetEnteredGamepadTextLength);
    add_func(L, "GetSteamUILanguage", luasteam_Utils_GetSteamUILanguage);
    add_func(L, "IsSteamRunningInVR", luasteam_Utils_IsSteamRunningInVR);
    add_func(L, "SetOverlayNotificationInset", luasteam_Utils_SetOverlayNotificationInset);
    add_func(L, "IsSteamInBigPictureMode", luasteam_Utils_IsSteamInBigPictureMode);
    add_func(L, "StartVRDashboard", luasteam_Utils_StartVRDashboard);
    add_func(L, "IsVRHeadsetStreamingEnabled", luasteam_Utils_IsVRHeadsetStreamingEnabled);
    add_func(L, "SetVRHeadsetStreamingEnabled", luasteam_Utils_SetVRHeadsetStreamingEnabled);
    add_func(L, "IsSteamChinaLauncher", luasteam_Utils_IsSteamChinaLauncher);
    add_func(L, "InitFilterText", luasteam_Utils_InitFilterText);
    add_func(L, "GetIPv6ConnectivityState", luasteam_Utils_GetIPv6ConnectivityState);
    add_func(L, "IsSteamRunningOnSteamDeck", luasteam_Utils_IsSteamRunningOnSteamDeck);
    add_func(L, "ShowFloatingGamepadTextInput", luasteam_Utils_ShowFloatingGamepadTextInput);
    add_func(L, "SetGameLauncherMode", luasteam_Utils_SetGameLauncherMode);
    add_func(L, "DismissFloatingGamepadTextInput", luasteam_Utils_DismissFloatingGamepadTextInput);
    add_func(L, "DismissGamepadTextInput", luasteam_Utils_DismissGamepadTextInput);
}

void add_Utils_auto(lua_State *L) {
    lua_createtable(L, 0, 30);
    register_Utils_auto(L);
    lua_pushvalue(L, -1);
    Utils_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "Utils");
}

} // namespace luasteam
