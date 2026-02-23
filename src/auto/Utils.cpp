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

template <> void CallResultListener<CheckFileSignature_t>::Result(CheckFileSignature_t *data, bool io_fail) {
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) {
		luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);
		delete this;
		return;
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, callback_ref);
	luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);
	if (io_fail || data == nullptr) {
		lua_pushnil(L);
	} else {
		lua_createtable(L, 0, 1);
		lua_pushinteger(L, data->m_eCheckFileSignature);
		lua_setfield(L, -2, "m_eCheckFileSignature");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

// In C++:
// uint32 GetSecondsSinceAppActive();
// In Lua:
// int Utils.GetSecondsSinceAppActive()
EXTERN int luasteam_Utils_GetSecondsSinceAppActive(lua_State *L) {
	uint32 __ret = SteamUtils()->GetSecondsSinceAppActive();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// uint32 GetSecondsSinceComputerActive();
// In Lua:
// int Utils.GetSecondsSinceComputerActive()
EXTERN int luasteam_Utils_GetSecondsSinceComputerActive(lua_State *L) {
	uint32 __ret = SteamUtils()->GetSecondsSinceComputerActive();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// EUniverse GetConnectedUniverse();
// In Lua:
// int Utils.GetConnectedUniverse()
EXTERN int luasteam_Utils_GetConnectedUniverse(lua_State *L) {
	EUniverse __ret = SteamUtils()->GetConnectedUniverse();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// uint32 GetServerRealTime();
// In Lua:
// int Utils.GetServerRealTime()
EXTERN int luasteam_Utils_GetServerRealTime(lua_State *L) {
	uint32 __ret = SteamUtils()->GetServerRealTime();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// const char * GetIPCountry();
// In Lua:
// str Utils.GetIPCountry()
EXTERN int luasteam_Utils_GetIPCountry(lua_State *L) {
	const char * __ret = SteamUtils()->GetIPCountry();
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// bool GetImageSize(int iImage, uint32 * pnWidth, uint32 * pnHeight);
// In Lua:
// (bool, pnWidth: int, pnHeight: int) Utils.GetImageSize(iImage: int)
EXTERN int luasteam_Utils_GetImageSize(lua_State *L) {
	int iImage = static_cast<int>(luaL_checkint(L, 1));
	uint32 pnWidth;
	uint32 pnHeight;
	bool __ret = SteamUtils()->GetImageSize(iImage, &pnWidth, &pnHeight);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pnWidth);
	lua_pushinteger(L, pnHeight);
	return 3;
}

// In C++:
// bool GetImageRGBA(int iImage, uint8 * pubDest, int nDestBufferSize);
// In Lua:
// (bool, pubDest: str) Utils.GetImageRGBA(iImage: int, nDestBufferSize: int)
EXTERN int luasteam_Utils_GetImageRGBA(lua_State *L) {
	int iImage = static_cast<int>(luaL_checkint(L, 1));
	int nDestBufferSize = luaL_checkint(L, 2);
	std::vector<uint8> pubDest(nDestBufferSize);
	bool __ret = SteamUtils()->GetImageRGBA(iImage, pubDest.data(), nDestBufferSize);
	lua_pushboolean(L, __ret);
	lua_pushlstring(L, reinterpret_cast<const char*>(pubDest.data()), nDestBufferSize);
	return 2;
}

// In C++:
// uint8 GetCurrentBatteryPower();
// In Lua:
// int Utils.GetCurrentBatteryPower()
EXTERN int luasteam_Utils_GetCurrentBatteryPower(lua_State *L) {
	uint8 __ret = SteamUtils()->GetCurrentBatteryPower();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// uint32 GetAppID();
// In Lua:
// int Utils.GetAppID()
EXTERN int luasteam_Utils_GetAppID(lua_State *L) {
	uint32 __ret = SteamUtils()->GetAppID();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// void SetOverlayNotificationPosition(ENotificationPosition eNotificationPosition);
// In Lua:
// Utils.SetOverlayNotificationPosition(eNotificationPosition: int)
EXTERN int luasteam_Utils_SetOverlayNotificationPosition(lua_State *L) {
	ENotificationPosition eNotificationPosition = static_cast<ENotificationPosition>(luaL_checkint(L, 1));
	SteamUtils()->SetOverlayNotificationPosition(eNotificationPosition);
	return 0;
}

// In C++:
// bool IsAPICallCompleted(SteamAPICall_t hSteamAPICall, bool * pbFailed);
// In Lua:
// (bool, pbFailed: bool) Utils.IsAPICallCompleted(hSteamAPICall: uint64)
EXTERN int luasteam_Utils_IsAPICallCompleted(lua_State *L) {
	SteamAPICall_t hSteamAPICall(luasteam::checkuint64(L, 1));
	bool pbFailed;
	bool __ret = SteamUtils()->IsAPICallCompleted(hSteamAPICall, &pbFailed);
	lua_pushboolean(L, __ret);
	lua_pushboolean(L, pbFailed);
	return 2;
}

// In C++:
// ESteamAPICallFailure GetAPICallFailureReason(SteamAPICall_t hSteamAPICall);
// In Lua:
// int Utils.GetAPICallFailureReason(hSteamAPICall: uint64)
EXTERN int luasteam_Utils_GetAPICallFailureReason(lua_State *L) {
	SteamAPICall_t hSteamAPICall(luasteam::checkuint64(L, 1));
	ESteamAPICallFailure __ret = SteamUtils()->GetAPICallFailureReason(hSteamAPICall);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool GetAPICallResult(SteamAPICall_t hSteamAPICall, void * pCallback, int cubCallback, int iCallbackExpected, bool * pbFailed);
// In Lua:
// (bool, pCallback: str, pbFailed: bool) Utils.GetAPICallResult(hSteamAPICall: uint64, cubCallback: int, iCallbackExpected: int)
EXTERN int luasteam_Utils_GetAPICallResult(lua_State *L) {
	SteamAPICall_t hSteamAPICall(luasteam::checkuint64(L, 1));
	int cubCallback = luaL_checkint(L, 2);
	std::vector<unsigned char> pCallback(cubCallback);
	int iCallbackExpected = static_cast<int>(luaL_checkint(L, 3));
	bool pbFailed;
	bool __ret = SteamUtils()->GetAPICallResult(hSteamAPICall, pCallback.data(), cubCallback, iCallbackExpected, &pbFailed);
	lua_pushboolean(L, __ret);
	lua_pushlstring(L, reinterpret_cast<const char*>(pCallback.data()), cubCallback);
	lua_pushboolean(L, pbFailed);
	return 3;
}

// In C++:
// uint32 GetIPCCallCount();
// In Lua:
// int Utils.GetIPCCallCount()
EXTERN int luasteam_Utils_GetIPCCallCount(lua_State *L) {
	uint32 __ret = SteamUtils()->GetIPCCallCount();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool IsOverlayEnabled();
// In Lua:
// bool Utils.IsOverlayEnabled()
EXTERN int luasteam_Utils_IsOverlayEnabled(lua_State *L) {
	bool __ret = SteamUtils()->IsOverlayEnabled();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool BOverlayNeedsPresent();
// In Lua:
// bool Utils.BOverlayNeedsPresent()
EXTERN int luasteam_Utils_BOverlayNeedsPresent(lua_State *L) {
	bool __ret = SteamUtils()->BOverlayNeedsPresent();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t CheckFileSignature(const char * szFileName);
// In Lua:
// uint64 Utils.CheckFileSignature(szFileName: str, callback: function)
EXTERN int luasteam_Utils_CheckFileSignature(lua_State *L) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	const char *szFileName = luaL_checkstring(L, 1);
	SteamAPICall_t __ret = SteamUtils()->CheckFileSignature(szFileName);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<CheckFileSignature_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<CheckFileSignature_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// bool ShowGamepadTextInput(EGamepadTextInputMode eInputMode, EGamepadTextInputLineMode eLineInputMode, const char * pchDescription, uint32 unCharMax, const char * pchExistingText);
// In Lua:
// bool Utils.ShowGamepadTextInput(eInputMode: int, eLineInputMode: int, pchDescription: str, unCharMax: int, pchExistingText: str)
EXTERN int luasteam_Utils_ShowGamepadTextInput(lua_State *L) {
	EGamepadTextInputMode eInputMode = static_cast<EGamepadTextInputMode>(luaL_checkint(L, 1));
	EGamepadTextInputLineMode eLineInputMode = static_cast<EGamepadTextInputLineMode>(luaL_checkint(L, 2));
	const char *pchDescription = luaL_checkstring(L, 3);
	uint32 unCharMax = static_cast<uint32>(luaL_checkint(L, 4));
	const char *pchExistingText = luaL_checkstring(L, 5);
	bool __ret = SteamUtils()->ShowGamepadTextInput(eInputMode, eLineInputMode, pchDescription, unCharMax, pchExistingText);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// uint32 GetEnteredGamepadTextLength();
// In Lua:
// int Utils.GetEnteredGamepadTextLength()
EXTERN int luasteam_Utils_GetEnteredGamepadTextLength(lua_State *L) {
	uint32 __ret = SteamUtils()->GetEnteredGamepadTextLength();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool GetEnteredGamepadTextInput(char * pchText, uint32 cchText);
// In Lua:
// (bool, pchText: str) Utils.GetEnteredGamepadTextInput(cchText: int)
EXTERN int luasteam_Utils_GetEnteredGamepadTextInput(lua_State *L) {
	uint32 cchText = luaL_checkint(L, 1);
	std::vector<char> pchText(cchText);
	bool __ret = SteamUtils()->GetEnteredGamepadTextInput(pchText.data(), cchText);
	lua_pushboolean(L, __ret);
	lua_pushstring(L, reinterpret_cast<const char*>(pchText.data()));
	return 2;
}

// In C++:
// const char * GetSteamUILanguage();
// In Lua:
// str Utils.GetSteamUILanguage()
EXTERN int luasteam_Utils_GetSteamUILanguage(lua_State *L) {
	const char * __ret = SteamUtils()->GetSteamUILanguage();
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// bool IsSteamRunningInVR();
// In Lua:
// bool Utils.IsSteamRunningInVR()
EXTERN int luasteam_Utils_IsSteamRunningInVR(lua_State *L) {
	bool __ret = SteamUtils()->IsSteamRunningInVR();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// void SetOverlayNotificationInset(int nHorizontalInset, int nVerticalInset);
// In Lua:
// Utils.SetOverlayNotificationInset(nHorizontalInset: int, nVerticalInset: int)
EXTERN int luasteam_Utils_SetOverlayNotificationInset(lua_State *L) {
	int nHorizontalInset = static_cast<int>(luaL_checkint(L, 1));
	int nVerticalInset = static_cast<int>(luaL_checkint(L, 2));
	SteamUtils()->SetOverlayNotificationInset(nHorizontalInset, nVerticalInset);
	return 0;
}

// In C++:
// bool IsSteamInBigPictureMode();
// In Lua:
// bool Utils.IsSteamInBigPictureMode()
EXTERN int luasteam_Utils_IsSteamInBigPictureMode(lua_State *L) {
	bool __ret = SteamUtils()->IsSteamInBigPictureMode();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// void StartVRDashboard();
// In Lua:
// Utils.StartVRDashboard()
EXTERN int luasteam_Utils_StartVRDashboard(lua_State *L) {
	SteamUtils()->StartVRDashboard();
	return 0;
}

// In C++:
// bool IsVRHeadsetStreamingEnabled();
// In Lua:
// bool Utils.IsVRHeadsetStreamingEnabled()
EXTERN int luasteam_Utils_IsVRHeadsetStreamingEnabled(lua_State *L) {
	bool __ret = SteamUtils()->IsVRHeadsetStreamingEnabled();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// void SetVRHeadsetStreamingEnabled(bool bEnabled);
// In Lua:
// Utils.SetVRHeadsetStreamingEnabled(bEnabled: bool)
EXTERN int luasteam_Utils_SetVRHeadsetStreamingEnabled(lua_State *L) {
	bool bEnabled = lua_toboolean(L, 1);
	SteamUtils()->SetVRHeadsetStreamingEnabled(bEnabled);
	return 0;
}

// In C++:
// bool IsSteamChinaLauncher();
// In Lua:
// bool Utils.IsSteamChinaLauncher()
EXTERN int luasteam_Utils_IsSteamChinaLauncher(lua_State *L) {
	bool __ret = SteamUtils()->IsSteamChinaLauncher();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool InitFilterText(uint32 unFilterOptions);
// In Lua:
// bool Utils.InitFilterText(unFilterOptions: int)
EXTERN int luasteam_Utils_InitFilterText(lua_State *L) {
	uint32 unFilterOptions = static_cast<uint32>(luaL_checkint(L, 1));
	bool __ret = SteamUtils()->InitFilterText(unFilterOptions);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// int FilterText(ETextFilteringContext eContext, CSteamID sourceSteamID, const char * pchInputMessage, char * pchOutFilteredText, uint32 nByteSizeOutFilteredText);
// In Lua:
// (int, pchOutFilteredText: str) Utils.FilterText(eContext: int, sourceSteamID: uint64, pchInputMessage: str, nByteSizeOutFilteredText: int)
EXTERN int luasteam_Utils_FilterText(lua_State *L) {
	ETextFilteringContext eContext = static_cast<ETextFilteringContext>(luaL_checkint(L, 1));
	CSteamID sourceSteamID(luasteam::checkuint64(L, 2));
	const char *pchInputMessage = luaL_checkstring(L, 3);
	uint32 nByteSizeOutFilteredText = luaL_checkint(L, 4);
	std::vector<char> pchOutFilteredText(nByteSizeOutFilteredText);
	int __ret = SteamUtils()->FilterText(eContext, sourceSteamID, pchInputMessage, pchOutFilteredText.data(), nByteSizeOutFilteredText);
	lua_pushinteger(L, __ret);
	lua_pushstring(L, reinterpret_cast<const char*>(pchOutFilteredText.data()));
	return 2;
}

// In C++:
// ESteamIPv6ConnectivityState GetIPv6ConnectivityState(ESteamIPv6ConnectivityProtocol eProtocol);
// In Lua:
// int Utils.GetIPv6ConnectivityState(eProtocol: int)
EXTERN int luasteam_Utils_GetIPv6ConnectivityState(lua_State *L) {
	ESteamIPv6ConnectivityProtocol eProtocol = static_cast<ESteamIPv6ConnectivityProtocol>(luaL_checkint(L, 1));
	ESteamIPv6ConnectivityState __ret = SteamUtils()->GetIPv6ConnectivityState(eProtocol);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool IsSteamRunningOnSteamDeck();
// In Lua:
// bool Utils.IsSteamRunningOnSteamDeck()
EXTERN int luasteam_Utils_IsSteamRunningOnSteamDeck(lua_State *L) {
	bool __ret = SteamUtils()->IsSteamRunningOnSteamDeck();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool ShowFloatingGamepadTextInput(EFloatingGamepadTextInputMode eKeyboardMode, int nTextFieldXPosition, int nTextFieldYPosition, int nTextFieldWidth, int nTextFieldHeight);
// In Lua:
// bool Utils.ShowFloatingGamepadTextInput(eKeyboardMode: int, nTextFieldXPosition: int, nTextFieldYPosition: int, nTextFieldWidth: int, nTextFieldHeight: int)
EXTERN int luasteam_Utils_ShowFloatingGamepadTextInput(lua_State *L) {
	EFloatingGamepadTextInputMode eKeyboardMode = static_cast<EFloatingGamepadTextInputMode>(luaL_checkint(L, 1));
	int nTextFieldXPosition = static_cast<int>(luaL_checkint(L, 2));
	int nTextFieldYPosition = static_cast<int>(luaL_checkint(L, 3));
	int nTextFieldWidth = static_cast<int>(luaL_checkint(L, 4));
	int nTextFieldHeight = static_cast<int>(luaL_checkint(L, 5));
	bool __ret = SteamUtils()->ShowFloatingGamepadTextInput(eKeyboardMode, nTextFieldXPosition, nTextFieldYPosition, nTextFieldWidth, nTextFieldHeight);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// void SetGameLauncherMode(bool bLauncherMode);
// In Lua:
// Utils.SetGameLauncherMode(bLauncherMode: bool)
EXTERN int luasteam_Utils_SetGameLauncherMode(lua_State *L) {
	bool bLauncherMode = lua_toboolean(L, 1);
	SteamUtils()->SetGameLauncherMode(bLauncherMode);
	return 0;
}

// In C++:
// bool DismissFloatingGamepadTextInput();
// In Lua:
// bool Utils.DismissFloatingGamepadTextInput()
EXTERN int luasteam_Utils_DismissFloatingGamepadTextInput(lua_State *L) {
	bool __ret = SteamUtils()->DismissFloatingGamepadTextInput();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool DismissGamepadTextInput();
// In Lua:
// bool Utils.DismissGamepadTextInput()
EXTERN int luasteam_Utils_DismissGamepadTextInput(lua_State *L) {
	bool __ret = SteamUtils()->DismissGamepadTextInput();
	lua_pushboolean(L, __ret);
	return 1;
}

void register_Utils_auto(lua_State *L) {
	add_func(L, "GetSecondsSinceAppActive", luasteam_Utils_GetSecondsSinceAppActive);
	add_func(L, "GetSecondsSinceComputerActive", luasteam_Utils_GetSecondsSinceComputerActive);
	add_func(L, "GetConnectedUniverse", luasteam_Utils_GetConnectedUniverse);
	add_func(L, "GetServerRealTime", luasteam_Utils_GetServerRealTime);
	add_func(L, "GetIPCountry", luasteam_Utils_GetIPCountry);
	add_func(L, "GetImageSize", luasteam_Utils_GetImageSize);
	add_func(L, "GetImageRGBA", luasteam_Utils_GetImageRGBA);
	add_func(L, "GetCurrentBatteryPower", luasteam_Utils_GetCurrentBatteryPower);
	add_func(L, "GetAppID", luasteam_Utils_GetAppID);
	add_func(L, "SetOverlayNotificationPosition", luasteam_Utils_SetOverlayNotificationPosition);
	add_func(L, "IsAPICallCompleted", luasteam_Utils_IsAPICallCompleted);
	add_func(L, "GetAPICallFailureReason", luasteam_Utils_GetAPICallFailureReason);
	add_func(L, "GetAPICallResult", luasteam_Utils_GetAPICallResult);
	add_func(L, "GetIPCCallCount", luasteam_Utils_GetIPCCallCount);
	add_func(L, "IsOverlayEnabled", luasteam_Utils_IsOverlayEnabled);
	add_func(L, "BOverlayNeedsPresent", luasteam_Utils_BOverlayNeedsPresent);
	add_func(L, "CheckFileSignature", luasteam_Utils_CheckFileSignature);
	add_func(L, "ShowGamepadTextInput", luasteam_Utils_ShowGamepadTextInput);
	add_func(L, "GetEnteredGamepadTextLength", luasteam_Utils_GetEnteredGamepadTextLength);
	add_func(L, "GetEnteredGamepadTextInput", luasteam_Utils_GetEnteredGamepadTextInput);
	add_func(L, "GetSteamUILanguage", luasteam_Utils_GetSteamUILanguage);
	add_func(L, "IsSteamRunningInVR", luasteam_Utils_IsSteamRunningInVR);
	add_func(L, "SetOverlayNotificationInset", luasteam_Utils_SetOverlayNotificationInset);
	add_func(L, "IsSteamInBigPictureMode", luasteam_Utils_IsSteamInBigPictureMode);
	add_func(L, "StartVRDashboard", luasteam_Utils_StartVRDashboard);
	add_func(L, "IsVRHeadsetStreamingEnabled", luasteam_Utils_IsVRHeadsetStreamingEnabled);
	add_func(L, "SetVRHeadsetStreamingEnabled", luasteam_Utils_SetVRHeadsetStreamingEnabled);
	add_func(L, "IsSteamChinaLauncher", luasteam_Utils_IsSteamChinaLauncher);
	add_func(L, "InitFilterText", luasteam_Utils_InitFilterText);
	add_func(L, "FilterText", luasteam_Utils_FilterText);
	add_func(L, "GetIPv6ConnectivityState", luasteam_Utils_GetIPv6ConnectivityState);
	add_func(L, "IsSteamRunningOnSteamDeck", luasteam_Utils_IsSteamRunningOnSteamDeck);
	add_func(L, "ShowFloatingGamepadTextInput", luasteam_Utils_ShowFloatingGamepadTextInput);
	add_func(L, "SetGameLauncherMode", luasteam_Utils_SetGameLauncherMode);
	add_func(L, "DismissFloatingGamepadTextInput", luasteam_Utils_DismissFloatingGamepadTextInput);
	add_func(L, "DismissGamepadTextInput", luasteam_Utils_DismissGamepadTextInput);
}

void add_Utils_auto(lua_State *L) {
	lua_createtable(L, 0, 36);
	register_Utils_auto(L);
	lua_pushvalue(L, -1);
	Utils_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "Utils");
}

} // namespace luasteam
