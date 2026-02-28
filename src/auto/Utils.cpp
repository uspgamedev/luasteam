#include "auto.hpp"

namespace luasteam {

int Utils_ref = LUA_NOREF;

namespace {
class UtilsCallbackListener {
private:
	STEAM_CALLBACK(UtilsCallbackListener, OnIPCountry, IPCountry_t);
	STEAM_CALLBACK(UtilsCallbackListener, OnLowBatteryPower, LowBatteryPower_t);
	STEAM_CALLBACK(UtilsCallbackListener, OnSteamAPICallCompleted, SteamAPICallCompleted_t);
	STEAM_CALLBACK(UtilsCallbackListener, OnSteamShutdown, SteamShutdown_t);
	STEAM_CALLBACK(UtilsCallbackListener, OnCheckFileSignature, CheckFileSignature_t);
	STEAM_CALLBACK(UtilsCallbackListener, OnGamepadTextInputDismissed, GamepadTextInputDismissed_t);
	STEAM_CALLBACK(UtilsCallbackListener, OnAppResumingFromSuspend, AppResumingFromSuspend_t);
	STEAM_CALLBACK(UtilsCallbackListener, OnFloatingGamepadTextInputDismissed, FloatingGamepadTextInputDismissed_t);
	STEAM_CALLBACK(UtilsCallbackListener, OnFilterTextDictionaryChanged, FilterTextDictionaryChanged_t);
};
void UtilsCallbackListener::OnIPCountry(IPCountry_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Utils_ref);
	lua_getfield(L, -1, "OnIPCountry");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_IPCountry_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UtilsCallbackListener::OnLowBatteryPower(LowBatteryPower_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Utils_ref);
	lua_getfield(L, -1, "OnLowBatteryPower");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_LowBatteryPower_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UtilsCallbackListener::OnSteamAPICallCompleted(SteamAPICallCompleted_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Utils_ref);
	lua_getfield(L, -1, "OnSteamAPICallCompleted");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamAPICallCompleted_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UtilsCallbackListener::OnSteamShutdown(SteamShutdown_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Utils_ref);
	lua_getfield(L, -1, "OnSteamShutdown");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamShutdown_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UtilsCallbackListener::OnCheckFileSignature(CheckFileSignature_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Utils_ref);
	lua_getfield(L, -1, "OnCheckFileSignature");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_CheckFileSignature_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UtilsCallbackListener::OnGamepadTextInputDismissed(GamepadTextInputDismissed_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Utils_ref);
	lua_getfield(L, -1, "OnGamepadTextInputDismissed");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_GamepadTextInputDismissed_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UtilsCallbackListener::OnAppResumingFromSuspend(AppResumingFromSuspend_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Utils_ref);
	lua_getfield(L, -1, "OnAppResumingFromSuspend");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_AppResumingFromSuspend_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UtilsCallbackListener::OnFloatingGamepadTextInputDismissed(FloatingGamepadTextInputDismissed_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Utils_ref);
	lua_getfield(L, -1, "OnFloatingGamepadTextInputDismissed");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_FloatingGamepadTextInputDismissed_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UtilsCallbackListener::OnFilterTextDictionaryChanged(FilterTextDictionaryChanged_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Utils_ref);
	lua_getfield(L, -1, "OnFilterTextDictionaryChanged");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_FilterTextDictionaryChanged_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
UtilsCallbackListener *Utils_listener = nullptr;
} // namespace

void init_Utils_auto(lua_State *L) { if (Utils_listener != nullptr) return; Utils_listener = new UtilsCallbackListener(); }
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
static int luasteam_Utils_GetSecondsSinceAppActive(lua_State *L, ISteamUtils *iface) {
	uint32 __ret = iface->GetSecondsSinceAppActive();
	lua_pushinteger(L, __ret);
	return 1;
}
static int luasteam_Utils_GetSecondsSinceAppActive_user(lua_State *L) { return luasteam_Utils_GetSecondsSinceAppActive(L, SteamUtils()); }
static int luasteam_Utils_GetSecondsSinceAppActive_gs(lua_State *L) { return luasteam_Utils_GetSecondsSinceAppActive(L, SteamGameServerUtils()); }

// In C++:
// uint32 GetSecondsSinceComputerActive();
// In Lua:
// int Utils.GetSecondsSinceComputerActive()
static int luasteam_Utils_GetSecondsSinceComputerActive(lua_State *L, ISteamUtils *iface) {
	uint32 __ret = iface->GetSecondsSinceComputerActive();
	lua_pushinteger(L, __ret);
	return 1;
}
static int luasteam_Utils_GetSecondsSinceComputerActive_user(lua_State *L) { return luasteam_Utils_GetSecondsSinceComputerActive(L, SteamUtils()); }
static int luasteam_Utils_GetSecondsSinceComputerActive_gs(lua_State *L) { return luasteam_Utils_GetSecondsSinceComputerActive(L, SteamGameServerUtils()); }

// In C++:
// EUniverse GetConnectedUniverse();
// In Lua:
// int Utils.GetConnectedUniverse()
static int luasteam_Utils_GetConnectedUniverse(lua_State *L, ISteamUtils *iface) {
	EUniverse __ret = iface->GetConnectedUniverse();
	lua_pushinteger(L, __ret);
	return 1;
}
static int luasteam_Utils_GetConnectedUniverse_user(lua_State *L) { return luasteam_Utils_GetConnectedUniverse(L, SteamUtils()); }
static int luasteam_Utils_GetConnectedUniverse_gs(lua_State *L) { return luasteam_Utils_GetConnectedUniverse(L, SteamGameServerUtils()); }

// In C++:
// uint32 GetServerRealTime();
// In Lua:
// int Utils.GetServerRealTime()
static int luasteam_Utils_GetServerRealTime(lua_State *L, ISteamUtils *iface) {
	uint32 __ret = iface->GetServerRealTime();
	lua_pushinteger(L, __ret);
	return 1;
}
static int luasteam_Utils_GetServerRealTime_user(lua_State *L) { return luasteam_Utils_GetServerRealTime(L, SteamUtils()); }
static int luasteam_Utils_GetServerRealTime_gs(lua_State *L) { return luasteam_Utils_GetServerRealTime(L, SteamGameServerUtils()); }

// In C++:
// const char * GetIPCountry();
// In Lua:
// str Utils.GetIPCountry()
static int luasteam_Utils_GetIPCountry(lua_State *L, ISteamUtils *iface) {
	const char * __ret = iface->GetIPCountry();
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}
static int luasteam_Utils_GetIPCountry_user(lua_State *L) { return luasteam_Utils_GetIPCountry(L, SteamUtils()); }
static int luasteam_Utils_GetIPCountry_gs(lua_State *L) { return luasteam_Utils_GetIPCountry(L, SteamGameServerUtils()); }

// In C++:
// bool GetImageSize(int iImage, uint32 * pnWidth, uint32 * pnHeight);
// In Lua:
// (bool, pnWidth: int, pnHeight: int) Utils.GetImageSize(iImage: int)
static int luasteam_Utils_GetImageSize(lua_State *L, ISteamUtils *iface) {
	int iImage = static_cast<int>(luaL_checkint(L, 1));
	uint32 pnWidth;
	uint32 pnHeight;
	bool __ret = iface->GetImageSize(iImage, &pnWidth, &pnHeight);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pnWidth);
	lua_pushinteger(L, pnHeight);
	return 3;
}
static int luasteam_Utils_GetImageSize_user(lua_State *L) { return luasteam_Utils_GetImageSize(L, SteamUtils()); }
static int luasteam_Utils_GetImageSize_gs(lua_State *L) { return luasteam_Utils_GetImageSize(L, SteamGameServerUtils()); }

// In C++:
// bool GetImageRGBA(int iImage, uint8 * pubDest, int nDestBufferSize);
// In Lua:
// (bool, pubDest: str) Utils.GetImageRGBA(iImage: int, nDestBufferSize: int)
static int luasteam_Utils_GetImageRGBA(lua_State *L, ISteamUtils *iface) {
	int iImage = static_cast<int>(luaL_checkint(L, 1));
	int nDestBufferSize = luaL_checkint(L, 2);
	std::vector<uint8> pubDest(nDestBufferSize);
	bool __ret = iface->GetImageRGBA(iImage, pubDest.data(), nDestBufferSize);
	lua_pushboolean(L, __ret);
	lua_pushlstring(L, reinterpret_cast<const char*>(pubDest.data()), nDestBufferSize);
	return 2;
}
static int luasteam_Utils_GetImageRGBA_user(lua_State *L) { return luasteam_Utils_GetImageRGBA(L, SteamUtils()); }
static int luasteam_Utils_GetImageRGBA_gs(lua_State *L) { return luasteam_Utils_GetImageRGBA(L, SteamGameServerUtils()); }

// In C++:
// uint8 GetCurrentBatteryPower();
// In Lua:
// int Utils.GetCurrentBatteryPower()
static int luasteam_Utils_GetCurrentBatteryPower(lua_State *L, ISteamUtils *iface) {
	uint8 __ret = iface->GetCurrentBatteryPower();
	lua_pushinteger(L, __ret);
	return 1;
}
static int luasteam_Utils_GetCurrentBatteryPower_user(lua_State *L) { return luasteam_Utils_GetCurrentBatteryPower(L, SteamUtils()); }
static int luasteam_Utils_GetCurrentBatteryPower_gs(lua_State *L) { return luasteam_Utils_GetCurrentBatteryPower(L, SteamGameServerUtils()); }

// In C++:
// uint32 GetAppID();
// In Lua:
// int Utils.GetAppID()
static int luasteam_Utils_GetAppID(lua_State *L, ISteamUtils *iface) {
	uint32 __ret = iface->GetAppID();
	lua_pushinteger(L, __ret);
	return 1;
}
static int luasteam_Utils_GetAppID_user(lua_State *L) { return luasteam_Utils_GetAppID(L, SteamUtils()); }
static int luasteam_Utils_GetAppID_gs(lua_State *L) { return luasteam_Utils_GetAppID(L, SteamGameServerUtils()); }

// In C++:
// void SetOverlayNotificationPosition(ENotificationPosition eNotificationPosition);
// In Lua:
// Utils.SetOverlayNotificationPosition(eNotificationPosition: int)
static int luasteam_Utils_SetOverlayNotificationPosition(lua_State *L, ISteamUtils *iface) {
	ENotificationPosition eNotificationPosition = static_cast<ENotificationPosition>(luaL_checkint(L, 1));
	iface->SetOverlayNotificationPosition(eNotificationPosition);
	return 0;
}
static int luasteam_Utils_SetOverlayNotificationPosition_user(lua_State *L) { return luasteam_Utils_SetOverlayNotificationPosition(L, SteamUtils()); }
static int luasteam_Utils_SetOverlayNotificationPosition_gs(lua_State *L) { return luasteam_Utils_SetOverlayNotificationPosition(L, SteamGameServerUtils()); }

// In C++:
// bool IsAPICallCompleted(SteamAPICall_t hSteamAPICall, bool * pbFailed);
// In Lua:
// (bool, pbFailed: bool) Utils.IsAPICallCompleted(hSteamAPICall: uint64)
static int luasteam_Utils_IsAPICallCompleted(lua_State *L, ISteamUtils *iface) {
	SteamAPICall_t hSteamAPICall = luasteam::checkuint64(L, 1);
	bool pbFailed;
	bool __ret = iface->IsAPICallCompleted(hSteamAPICall, &pbFailed);
	lua_pushboolean(L, __ret);
	lua_pushboolean(L, pbFailed);
	return 2;
}
static int luasteam_Utils_IsAPICallCompleted_user(lua_State *L) { return luasteam_Utils_IsAPICallCompleted(L, SteamUtils()); }
static int luasteam_Utils_IsAPICallCompleted_gs(lua_State *L) { return luasteam_Utils_IsAPICallCompleted(L, SteamGameServerUtils()); }

// In C++:
// ESteamAPICallFailure GetAPICallFailureReason(SteamAPICall_t hSteamAPICall);
// In Lua:
// int Utils.GetAPICallFailureReason(hSteamAPICall: uint64)
static int luasteam_Utils_GetAPICallFailureReason(lua_State *L, ISteamUtils *iface) {
	SteamAPICall_t hSteamAPICall = luasteam::checkuint64(L, 1);
	ESteamAPICallFailure __ret = iface->GetAPICallFailureReason(hSteamAPICall);
	lua_pushinteger(L, __ret);
	return 1;
}
static int luasteam_Utils_GetAPICallFailureReason_user(lua_State *L) { return luasteam_Utils_GetAPICallFailureReason(L, SteamUtils()); }
static int luasteam_Utils_GetAPICallFailureReason_gs(lua_State *L) { return luasteam_Utils_GetAPICallFailureReason(L, SteamGameServerUtils()); }

// In C++:
// bool GetAPICallResult(SteamAPICall_t hSteamAPICall, void * pCallback, int cubCallback, int iCallbackExpected, bool * pbFailed);
// In Lua:
// (bool, pCallback: str, pbFailed: bool) Utils.GetAPICallResult(hSteamAPICall: uint64, cubCallback: int, iCallbackExpected: int)
static int luasteam_Utils_GetAPICallResult(lua_State *L, ISteamUtils *iface) {
	SteamAPICall_t hSteamAPICall = luasteam::checkuint64(L, 1);
	int cubCallback = luaL_checkint(L, 2);
	std::vector<unsigned char> pCallback(cubCallback);
	int iCallbackExpected = static_cast<int>(luaL_checkint(L, 3));
	bool pbFailed;
	bool __ret = iface->GetAPICallResult(hSteamAPICall, pCallback.data(), cubCallback, iCallbackExpected, &pbFailed);
	lua_pushboolean(L, __ret);
	lua_pushlstring(L, reinterpret_cast<const char*>(pCallback.data()), cubCallback);
	lua_pushboolean(L, pbFailed);
	return 3;
}
static int luasteam_Utils_GetAPICallResult_user(lua_State *L) { return luasteam_Utils_GetAPICallResult(L, SteamUtils()); }
static int luasteam_Utils_GetAPICallResult_gs(lua_State *L) { return luasteam_Utils_GetAPICallResult(L, SteamGameServerUtils()); }

// In C++:
// uint32 GetIPCCallCount();
// In Lua:
// int Utils.GetIPCCallCount()
static int luasteam_Utils_GetIPCCallCount(lua_State *L, ISteamUtils *iface) {
	uint32 __ret = iface->GetIPCCallCount();
	lua_pushinteger(L, __ret);
	return 1;
}
static int luasteam_Utils_GetIPCCallCount_user(lua_State *L) { return luasteam_Utils_GetIPCCallCount(L, SteamUtils()); }
static int luasteam_Utils_GetIPCCallCount_gs(lua_State *L) { return luasteam_Utils_GetIPCCallCount(L, SteamGameServerUtils()); }

// In C++:
// bool IsOverlayEnabled();
// In Lua:
// bool Utils.IsOverlayEnabled()
static int luasteam_Utils_IsOverlayEnabled(lua_State *L, ISteamUtils *iface) {
	bool __ret = iface->IsOverlayEnabled();
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_Utils_IsOverlayEnabled_user(lua_State *L) { return luasteam_Utils_IsOverlayEnabled(L, SteamUtils()); }
static int luasteam_Utils_IsOverlayEnabled_gs(lua_State *L) { return luasteam_Utils_IsOverlayEnabled(L, SteamGameServerUtils()); }

// In C++:
// bool BOverlayNeedsPresent();
// In Lua:
// bool Utils.BOverlayNeedsPresent()
static int luasteam_Utils_BOverlayNeedsPresent(lua_State *L, ISteamUtils *iface) {
	bool __ret = iface->BOverlayNeedsPresent();
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_Utils_BOverlayNeedsPresent_user(lua_State *L) { return luasteam_Utils_BOverlayNeedsPresent(L, SteamUtils()); }
static int luasteam_Utils_BOverlayNeedsPresent_gs(lua_State *L) { return luasteam_Utils_BOverlayNeedsPresent(L, SteamGameServerUtils()); }

// In C++:
// SteamAPICall_t CheckFileSignature(const char * szFileName);
// In Lua:
// uint64 Utils.CheckFileSignature(szFileName: str, callback: function)
static int luasteam_Utils_CheckFileSignature(lua_State *L, ISteamUtils *iface) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	const char *szFileName = luaL_checkstring(L, 1);
	SteamAPICall_t __ret = iface->CheckFileSignature(szFileName);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<CheckFileSignature_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<CheckFileSignature_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}
static int luasteam_Utils_CheckFileSignature_user(lua_State *L) { return luasteam_Utils_CheckFileSignature(L, SteamUtils()); }
static int luasteam_Utils_CheckFileSignature_gs(lua_State *L) { return luasteam_Utils_CheckFileSignature(L, SteamGameServerUtils()); }

// In C++:
// bool ShowGamepadTextInput(EGamepadTextInputMode eInputMode, EGamepadTextInputLineMode eLineInputMode, const char * pchDescription, uint32 unCharMax, const char * pchExistingText);
// In Lua:
// bool Utils.ShowGamepadTextInput(eInputMode: int, eLineInputMode: int, pchDescription: str, unCharMax: int, pchExistingText: str)
static int luasteam_Utils_ShowGamepadTextInput(lua_State *L, ISteamUtils *iface) {
	EGamepadTextInputMode eInputMode = static_cast<EGamepadTextInputMode>(luaL_checkint(L, 1));
	EGamepadTextInputLineMode eLineInputMode = static_cast<EGamepadTextInputLineMode>(luaL_checkint(L, 2));
	const char *pchDescription = luaL_checkstring(L, 3);
	uint32 unCharMax = static_cast<uint32>(luaL_checkint(L, 4));
	const char *pchExistingText = luaL_checkstring(L, 5);
	bool __ret = iface->ShowGamepadTextInput(eInputMode, eLineInputMode, pchDescription, unCharMax, pchExistingText);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_Utils_ShowGamepadTextInput_user(lua_State *L) { return luasteam_Utils_ShowGamepadTextInput(L, SteamUtils()); }
static int luasteam_Utils_ShowGamepadTextInput_gs(lua_State *L) { return luasteam_Utils_ShowGamepadTextInput(L, SteamGameServerUtils()); }

// In C++:
// uint32 GetEnteredGamepadTextLength();
// In Lua:
// int Utils.GetEnteredGamepadTextLength()
static int luasteam_Utils_GetEnteredGamepadTextLength(lua_State *L, ISteamUtils *iface) {
	uint32 __ret = iface->GetEnteredGamepadTextLength();
	lua_pushinteger(L, __ret);
	return 1;
}
static int luasteam_Utils_GetEnteredGamepadTextLength_user(lua_State *L) { return luasteam_Utils_GetEnteredGamepadTextLength(L, SteamUtils()); }
static int luasteam_Utils_GetEnteredGamepadTextLength_gs(lua_State *L) { return luasteam_Utils_GetEnteredGamepadTextLength(L, SteamGameServerUtils()); }

// In C++:
// bool GetEnteredGamepadTextInput(char * pchText, uint32 cchText);
// In Lua:
// (bool, pchText: str) Utils.GetEnteredGamepadTextInput(cchText: int)
static int luasteam_Utils_GetEnteredGamepadTextInput(lua_State *L, ISteamUtils *iface) {
	uint32 cchText = luaL_checkint(L, 1);
	std::vector<char> pchText(cchText);
	bool __ret = iface->GetEnteredGamepadTextInput(pchText.data(), cchText);
	lua_pushboolean(L, __ret);
	lua_pushstring(L, reinterpret_cast<const char*>(pchText.data()));
	return 2;
}
static int luasteam_Utils_GetEnteredGamepadTextInput_user(lua_State *L) { return luasteam_Utils_GetEnteredGamepadTextInput(L, SteamUtils()); }
static int luasteam_Utils_GetEnteredGamepadTextInput_gs(lua_State *L) { return luasteam_Utils_GetEnteredGamepadTextInput(L, SteamGameServerUtils()); }

// In C++:
// const char * GetSteamUILanguage();
// In Lua:
// str Utils.GetSteamUILanguage()
static int luasteam_Utils_GetSteamUILanguage(lua_State *L, ISteamUtils *iface) {
	const char * __ret = iface->GetSteamUILanguage();
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}
static int luasteam_Utils_GetSteamUILanguage_user(lua_State *L) { return luasteam_Utils_GetSteamUILanguage(L, SteamUtils()); }
static int luasteam_Utils_GetSteamUILanguage_gs(lua_State *L) { return luasteam_Utils_GetSteamUILanguage(L, SteamGameServerUtils()); }

// In C++:
// bool IsSteamRunningInVR();
// In Lua:
// bool Utils.IsSteamRunningInVR()
static int luasteam_Utils_IsSteamRunningInVR(lua_State *L, ISteamUtils *iface) {
	bool __ret = iface->IsSteamRunningInVR();
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_Utils_IsSteamRunningInVR_user(lua_State *L) { return luasteam_Utils_IsSteamRunningInVR(L, SteamUtils()); }
static int luasteam_Utils_IsSteamRunningInVR_gs(lua_State *L) { return luasteam_Utils_IsSteamRunningInVR(L, SteamGameServerUtils()); }

// In C++:
// void SetOverlayNotificationInset(int nHorizontalInset, int nVerticalInset);
// In Lua:
// Utils.SetOverlayNotificationInset(nHorizontalInset: int, nVerticalInset: int)
static int luasteam_Utils_SetOverlayNotificationInset(lua_State *L, ISteamUtils *iface) {
	int nHorizontalInset = static_cast<int>(luaL_checkint(L, 1));
	int nVerticalInset = static_cast<int>(luaL_checkint(L, 2));
	iface->SetOverlayNotificationInset(nHorizontalInset, nVerticalInset);
	return 0;
}
static int luasteam_Utils_SetOverlayNotificationInset_user(lua_State *L) { return luasteam_Utils_SetOverlayNotificationInset(L, SteamUtils()); }
static int luasteam_Utils_SetOverlayNotificationInset_gs(lua_State *L) { return luasteam_Utils_SetOverlayNotificationInset(L, SteamGameServerUtils()); }

// In C++:
// bool IsSteamInBigPictureMode();
// In Lua:
// bool Utils.IsSteamInBigPictureMode()
static int luasteam_Utils_IsSteamInBigPictureMode(lua_State *L, ISteamUtils *iface) {
	bool __ret = iface->IsSteamInBigPictureMode();
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_Utils_IsSteamInBigPictureMode_user(lua_State *L) { return luasteam_Utils_IsSteamInBigPictureMode(L, SteamUtils()); }
static int luasteam_Utils_IsSteamInBigPictureMode_gs(lua_State *L) { return luasteam_Utils_IsSteamInBigPictureMode(L, SteamGameServerUtils()); }

// In C++:
// void StartVRDashboard();
// In Lua:
// Utils.StartVRDashboard()
static int luasteam_Utils_StartVRDashboard(lua_State *L, ISteamUtils *iface) {
	iface->StartVRDashboard();
	return 0;
}
static int luasteam_Utils_StartVRDashboard_user(lua_State *L) { return luasteam_Utils_StartVRDashboard(L, SteamUtils()); }
static int luasteam_Utils_StartVRDashboard_gs(lua_State *L) { return luasteam_Utils_StartVRDashboard(L, SteamGameServerUtils()); }

// In C++:
// bool IsVRHeadsetStreamingEnabled();
// In Lua:
// bool Utils.IsVRHeadsetStreamingEnabled()
static int luasteam_Utils_IsVRHeadsetStreamingEnabled(lua_State *L, ISteamUtils *iface) {
	bool __ret = iface->IsVRHeadsetStreamingEnabled();
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_Utils_IsVRHeadsetStreamingEnabled_user(lua_State *L) { return luasteam_Utils_IsVRHeadsetStreamingEnabled(L, SteamUtils()); }
static int luasteam_Utils_IsVRHeadsetStreamingEnabled_gs(lua_State *L) { return luasteam_Utils_IsVRHeadsetStreamingEnabled(L, SteamGameServerUtils()); }

// In C++:
// void SetVRHeadsetStreamingEnabled(bool bEnabled);
// In Lua:
// Utils.SetVRHeadsetStreamingEnabled(bEnabled: bool)
static int luasteam_Utils_SetVRHeadsetStreamingEnabled(lua_State *L, ISteamUtils *iface) {
	bool bEnabled = lua_toboolean(L, 1);
	iface->SetVRHeadsetStreamingEnabled(bEnabled);
	return 0;
}
static int luasteam_Utils_SetVRHeadsetStreamingEnabled_user(lua_State *L) { return luasteam_Utils_SetVRHeadsetStreamingEnabled(L, SteamUtils()); }
static int luasteam_Utils_SetVRHeadsetStreamingEnabled_gs(lua_State *L) { return luasteam_Utils_SetVRHeadsetStreamingEnabled(L, SteamGameServerUtils()); }

// In C++:
// bool IsSteamChinaLauncher();
// In Lua:
// bool Utils.IsSteamChinaLauncher()
static int luasteam_Utils_IsSteamChinaLauncher(lua_State *L, ISteamUtils *iface) {
	bool __ret = iface->IsSteamChinaLauncher();
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_Utils_IsSteamChinaLauncher_user(lua_State *L) { return luasteam_Utils_IsSteamChinaLauncher(L, SteamUtils()); }
static int luasteam_Utils_IsSteamChinaLauncher_gs(lua_State *L) { return luasteam_Utils_IsSteamChinaLauncher(L, SteamGameServerUtils()); }

// In C++:
// bool InitFilterText(uint32 unFilterOptions);
// In Lua:
// bool Utils.InitFilterText(unFilterOptions: int)
static int luasteam_Utils_InitFilterText(lua_State *L, ISteamUtils *iface) {
	uint32 unFilterOptions = static_cast<uint32>(luaL_checkint(L, 1));
	bool __ret = iface->InitFilterText(unFilterOptions);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_Utils_InitFilterText_user(lua_State *L) { return luasteam_Utils_InitFilterText(L, SteamUtils()); }
static int luasteam_Utils_InitFilterText_gs(lua_State *L) { return luasteam_Utils_InitFilterText(L, SteamGameServerUtils()); }

// In C++:
// int FilterText(ETextFilteringContext eContext, CSteamID sourceSteamID, const char * pchInputMessage, char * pchOutFilteredText, uint32 nByteSizeOutFilteredText);
// In Lua:
// (int, pchOutFilteredText: str) Utils.FilterText(eContext: int, sourceSteamID: uint64, pchInputMessage: str, nByteSizeOutFilteredText: int)
static int luasteam_Utils_FilterText(lua_State *L, ISteamUtils *iface) {
	ETextFilteringContext eContext = static_cast<ETextFilteringContext>(luaL_checkint(L, 1));
	CSteamID sourceSteamID = CSteamID(luasteam::checkuint64(L, 2));
	const char *pchInputMessage = luaL_checkstring(L, 3);
	uint32 nByteSizeOutFilteredText = luaL_checkint(L, 4);
	std::vector<char> pchOutFilteredText(nByteSizeOutFilteredText);
	int __ret = iface->FilterText(eContext, sourceSteamID, pchInputMessage, pchOutFilteredText.data(), nByteSizeOutFilteredText);
	lua_pushinteger(L, __ret);
	lua_pushstring(L, reinterpret_cast<const char*>(pchOutFilteredText.data()));
	return 2;
}
static int luasteam_Utils_FilterText_user(lua_State *L) { return luasteam_Utils_FilterText(L, SteamUtils()); }
static int luasteam_Utils_FilterText_gs(lua_State *L) { return luasteam_Utils_FilterText(L, SteamGameServerUtils()); }

// In C++:
// ESteamIPv6ConnectivityState GetIPv6ConnectivityState(ESteamIPv6ConnectivityProtocol eProtocol);
// In Lua:
// int Utils.GetIPv6ConnectivityState(eProtocol: int)
static int luasteam_Utils_GetIPv6ConnectivityState(lua_State *L, ISteamUtils *iface) {
	ESteamIPv6ConnectivityProtocol eProtocol = static_cast<ESteamIPv6ConnectivityProtocol>(luaL_checkint(L, 1));
	ESteamIPv6ConnectivityState __ret = iface->GetIPv6ConnectivityState(eProtocol);
	lua_pushinteger(L, __ret);
	return 1;
}
static int luasteam_Utils_GetIPv6ConnectivityState_user(lua_State *L) { return luasteam_Utils_GetIPv6ConnectivityState(L, SteamUtils()); }
static int luasteam_Utils_GetIPv6ConnectivityState_gs(lua_State *L) { return luasteam_Utils_GetIPv6ConnectivityState(L, SteamGameServerUtils()); }

// In C++:
// bool IsSteamRunningOnSteamDeck();
// In Lua:
// bool Utils.IsSteamRunningOnSteamDeck()
static int luasteam_Utils_IsSteamRunningOnSteamDeck(lua_State *L, ISteamUtils *iface) {
	bool __ret = iface->IsSteamRunningOnSteamDeck();
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_Utils_IsSteamRunningOnSteamDeck_user(lua_State *L) { return luasteam_Utils_IsSteamRunningOnSteamDeck(L, SteamUtils()); }
static int luasteam_Utils_IsSteamRunningOnSteamDeck_gs(lua_State *L) { return luasteam_Utils_IsSteamRunningOnSteamDeck(L, SteamGameServerUtils()); }

// In C++:
// bool ShowFloatingGamepadTextInput(EFloatingGamepadTextInputMode eKeyboardMode, int nTextFieldXPosition, int nTextFieldYPosition, int nTextFieldWidth, int nTextFieldHeight);
// In Lua:
// bool Utils.ShowFloatingGamepadTextInput(eKeyboardMode: int, nTextFieldXPosition: int, nTextFieldYPosition: int, nTextFieldWidth: int, nTextFieldHeight: int)
static int luasteam_Utils_ShowFloatingGamepadTextInput(lua_State *L, ISteamUtils *iface) {
	EFloatingGamepadTextInputMode eKeyboardMode = static_cast<EFloatingGamepadTextInputMode>(luaL_checkint(L, 1));
	int nTextFieldXPosition = static_cast<int>(luaL_checkint(L, 2));
	int nTextFieldYPosition = static_cast<int>(luaL_checkint(L, 3));
	int nTextFieldWidth = static_cast<int>(luaL_checkint(L, 4));
	int nTextFieldHeight = static_cast<int>(luaL_checkint(L, 5));
	bool __ret = iface->ShowFloatingGamepadTextInput(eKeyboardMode, nTextFieldXPosition, nTextFieldYPosition, nTextFieldWidth, nTextFieldHeight);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_Utils_ShowFloatingGamepadTextInput_user(lua_State *L) { return luasteam_Utils_ShowFloatingGamepadTextInput(L, SteamUtils()); }
static int luasteam_Utils_ShowFloatingGamepadTextInput_gs(lua_State *L) { return luasteam_Utils_ShowFloatingGamepadTextInput(L, SteamGameServerUtils()); }

// In C++:
// void SetGameLauncherMode(bool bLauncherMode);
// In Lua:
// Utils.SetGameLauncherMode(bLauncherMode: bool)
static int luasteam_Utils_SetGameLauncherMode(lua_State *L, ISteamUtils *iface) {
	bool bLauncherMode = lua_toboolean(L, 1);
	iface->SetGameLauncherMode(bLauncherMode);
	return 0;
}
static int luasteam_Utils_SetGameLauncherMode_user(lua_State *L) { return luasteam_Utils_SetGameLauncherMode(L, SteamUtils()); }
static int luasteam_Utils_SetGameLauncherMode_gs(lua_State *L) { return luasteam_Utils_SetGameLauncherMode(L, SteamGameServerUtils()); }

// In C++:
// bool DismissFloatingGamepadTextInput();
// In Lua:
// bool Utils.DismissFloatingGamepadTextInput()
static int luasteam_Utils_DismissFloatingGamepadTextInput(lua_State *L, ISteamUtils *iface) {
	bool __ret = iface->DismissFloatingGamepadTextInput();
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_Utils_DismissFloatingGamepadTextInput_user(lua_State *L) { return luasteam_Utils_DismissFloatingGamepadTextInput(L, SteamUtils()); }
static int luasteam_Utils_DismissFloatingGamepadTextInput_gs(lua_State *L) { return luasteam_Utils_DismissFloatingGamepadTextInput(L, SteamGameServerUtils()); }

// In C++:
// bool DismissGamepadTextInput();
// In Lua:
// bool Utils.DismissGamepadTextInput()
static int luasteam_Utils_DismissGamepadTextInput(lua_State *L, ISteamUtils *iface) {
	bool __ret = iface->DismissGamepadTextInput();
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_Utils_DismissGamepadTextInput_user(lua_State *L) { return luasteam_Utils_DismissGamepadTextInput(L, SteamUtils()); }
static int luasteam_Utils_DismissGamepadTextInput_gs(lua_State *L) { return luasteam_Utils_DismissGamepadTextInput(L, SteamGameServerUtils()); }

void register_Utils_auto(lua_State *L, bool is_gs) {
	add_func(L, "GetSecondsSinceAppActive", is_gs ? luasteam_Utils_GetSecondsSinceAppActive_gs : luasteam_Utils_GetSecondsSinceAppActive_user);
	add_func(L, "GetSecondsSinceComputerActive", is_gs ? luasteam_Utils_GetSecondsSinceComputerActive_gs : luasteam_Utils_GetSecondsSinceComputerActive_user);
	add_func(L, "GetConnectedUniverse", is_gs ? luasteam_Utils_GetConnectedUniverse_gs : luasteam_Utils_GetConnectedUniverse_user);
	add_func(L, "GetServerRealTime", is_gs ? luasteam_Utils_GetServerRealTime_gs : luasteam_Utils_GetServerRealTime_user);
	add_func(L, "GetIPCountry", is_gs ? luasteam_Utils_GetIPCountry_gs : luasteam_Utils_GetIPCountry_user);
	add_func(L, "GetImageSize", is_gs ? luasteam_Utils_GetImageSize_gs : luasteam_Utils_GetImageSize_user);
	add_func(L, "GetImageRGBA", is_gs ? luasteam_Utils_GetImageRGBA_gs : luasteam_Utils_GetImageRGBA_user);
	add_func(L, "GetCurrentBatteryPower", is_gs ? luasteam_Utils_GetCurrentBatteryPower_gs : luasteam_Utils_GetCurrentBatteryPower_user);
	add_func(L, "GetAppID", is_gs ? luasteam_Utils_GetAppID_gs : luasteam_Utils_GetAppID_user);
	add_func(L, "SetOverlayNotificationPosition", is_gs ? luasteam_Utils_SetOverlayNotificationPosition_gs : luasteam_Utils_SetOverlayNotificationPosition_user);
	add_func(L, "IsAPICallCompleted", is_gs ? luasteam_Utils_IsAPICallCompleted_gs : luasteam_Utils_IsAPICallCompleted_user);
	add_func(L, "GetAPICallFailureReason", is_gs ? luasteam_Utils_GetAPICallFailureReason_gs : luasteam_Utils_GetAPICallFailureReason_user);
	add_func(L, "GetAPICallResult", is_gs ? luasteam_Utils_GetAPICallResult_gs : luasteam_Utils_GetAPICallResult_user);
	add_func(L, "GetIPCCallCount", is_gs ? luasteam_Utils_GetIPCCallCount_gs : luasteam_Utils_GetIPCCallCount_user);
	add_func(L, "IsOverlayEnabled", is_gs ? luasteam_Utils_IsOverlayEnabled_gs : luasteam_Utils_IsOverlayEnabled_user);
	add_func(L, "BOverlayNeedsPresent", is_gs ? luasteam_Utils_BOverlayNeedsPresent_gs : luasteam_Utils_BOverlayNeedsPresent_user);
	add_func(L, "CheckFileSignature", is_gs ? luasteam_Utils_CheckFileSignature_gs : luasteam_Utils_CheckFileSignature_user);
	add_func(L, "ShowGamepadTextInput", is_gs ? luasteam_Utils_ShowGamepadTextInput_gs : luasteam_Utils_ShowGamepadTextInput_user);
	add_func(L, "GetEnteredGamepadTextLength", is_gs ? luasteam_Utils_GetEnteredGamepadTextLength_gs : luasteam_Utils_GetEnteredGamepadTextLength_user);
	add_func(L, "GetEnteredGamepadTextInput", is_gs ? luasteam_Utils_GetEnteredGamepadTextInput_gs : luasteam_Utils_GetEnteredGamepadTextInput_user);
	add_func(L, "GetSteamUILanguage", is_gs ? luasteam_Utils_GetSteamUILanguage_gs : luasteam_Utils_GetSteamUILanguage_user);
	add_func(L, "IsSteamRunningInVR", is_gs ? luasteam_Utils_IsSteamRunningInVR_gs : luasteam_Utils_IsSteamRunningInVR_user);
	add_func(L, "SetOverlayNotificationInset", is_gs ? luasteam_Utils_SetOverlayNotificationInset_gs : luasteam_Utils_SetOverlayNotificationInset_user);
	add_func(L, "IsSteamInBigPictureMode", is_gs ? luasteam_Utils_IsSteamInBigPictureMode_gs : luasteam_Utils_IsSteamInBigPictureMode_user);
	add_func(L, "StartVRDashboard", is_gs ? luasteam_Utils_StartVRDashboard_gs : luasteam_Utils_StartVRDashboard_user);
	add_func(L, "IsVRHeadsetStreamingEnabled", is_gs ? luasteam_Utils_IsVRHeadsetStreamingEnabled_gs : luasteam_Utils_IsVRHeadsetStreamingEnabled_user);
	add_func(L, "SetVRHeadsetStreamingEnabled", is_gs ? luasteam_Utils_SetVRHeadsetStreamingEnabled_gs : luasteam_Utils_SetVRHeadsetStreamingEnabled_user);
	add_func(L, "IsSteamChinaLauncher", is_gs ? luasteam_Utils_IsSteamChinaLauncher_gs : luasteam_Utils_IsSteamChinaLauncher_user);
	add_func(L, "InitFilterText", is_gs ? luasteam_Utils_InitFilterText_gs : luasteam_Utils_InitFilterText_user);
	add_func(L, "FilterText", is_gs ? luasteam_Utils_FilterText_gs : luasteam_Utils_FilterText_user);
	add_func(L, "GetIPv6ConnectivityState", is_gs ? luasteam_Utils_GetIPv6ConnectivityState_gs : luasteam_Utils_GetIPv6ConnectivityState_user);
	add_func(L, "IsSteamRunningOnSteamDeck", is_gs ? luasteam_Utils_IsSteamRunningOnSteamDeck_gs : luasteam_Utils_IsSteamRunningOnSteamDeck_user);
	add_func(L, "ShowFloatingGamepadTextInput", is_gs ? luasteam_Utils_ShowFloatingGamepadTextInput_gs : luasteam_Utils_ShowFloatingGamepadTextInput_user);
	add_func(L, "SetGameLauncherMode", is_gs ? luasteam_Utils_SetGameLauncherMode_gs : luasteam_Utils_SetGameLauncherMode_user);
	add_func(L, "DismissFloatingGamepadTextInput", is_gs ? luasteam_Utils_DismissFloatingGamepadTextInput_gs : luasteam_Utils_DismissFloatingGamepadTextInput_user);
	add_func(L, "DismissGamepadTextInput", is_gs ? luasteam_Utils_DismissGamepadTextInput_gs : luasteam_Utils_DismissGamepadTextInput_user);
}

void add_Utils_auto(lua_State *L) {
	lua_createtable(L, 0, 36);
	register_Utils_auto(L, false);
	lua_pushvalue(L, -1);
	Utils_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "Utils");
}

int GameServerUtils_ref = LUA_NOREF;

namespace {
class GameServerUtilsCallbackListener {
private:
	STEAM_GAMESERVER_CALLBACK(GameServerUtilsCallbackListener, OnIPCountry, IPCountry_t);
	STEAM_GAMESERVER_CALLBACK(GameServerUtilsCallbackListener, OnLowBatteryPower, LowBatteryPower_t);
	STEAM_GAMESERVER_CALLBACK(GameServerUtilsCallbackListener, OnSteamAPICallCompleted, SteamAPICallCompleted_t);
	STEAM_GAMESERVER_CALLBACK(GameServerUtilsCallbackListener, OnSteamShutdown, SteamShutdown_t);
	STEAM_GAMESERVER_CALLBACK(GameServerUtilsCallbackListener, OnCheckFileSignature, CheckFileSignature_t);
	STEAM_GAMESERVER_CALLBACK(GameServerUtilsCallbackListener, OnGamepadTextInputDismissed, GamepadTextInputDismissed_t);
	STEAM_GAMESERVER_CALLBACK(GameServerUtilsCallbackListener, OnAppResumingFromSuspend, AppResumingFromSuspend_t);
	STEAM_GAMESERVER_CALLBACK(GameServerUtilsCallbackListener, OnFloatingGamepadTextInputDismissed, FloatingGamepadTextInputDismissed_t);
	STEAM_GAMESERVER_CALLBACK(GameServerUtilsCallbackListener, OnFilterTextDictionaryChanged, FilterTextDictionaryChanged_t);
};
void GameServerUtilsCallbackListener::OnIPCountry(IPCountry_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerUtils_ref);
	lua_getfield(L, -1, "OnIPCountry");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_IPCountry_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerUtilsCallbackListener::OnLowBatteryPower(LowBatteryPower_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerUtils_ref);
	lua_getfield(L, -1, "OnLowBatteryPower");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_LowBatteryPower_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerUtilsCallbackListener::OnSteamAPICallCompleted(SteamAPICallCompleted_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerUtils_ref);
	lua_getfield(L, -1, "OnSteamAPICallCompleted");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamAPICallCompleted_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerUtilsCallbackListener::OnSteamShutdown(SteamShutdown_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerUtils_ref);
	lua_getfield(L, -1, "OnSteamShutdown");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamShutdown_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerUtilsCallbackListener::OnCheckFileSignature(CheckFileSignature_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerUtils_ref);
	lua_getfield(L, -1, "OnCheckFileSignature");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_CheckFileSignature_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerUtilsCallbackListener::OnGamepadTextInputDismissed(GamepadTextInputDismissed_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerUtils_ref);
	lua_getfield(L, -1, "OnGamepadTextInputDismissed");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_GamepadTextInputDismissed_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerUtilsCallbackListener::OnAppResumingFromSuspend(AppResumingFromSuspend_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerUtils_ref);
	lua_getfield(L, -1, "OnAppResumingFromSuspend");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_AppResumingFromSuspend_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerUtilsCallbackListener::OnFloatingGamepadTextInputDismissed(FloatingGamepadTextInputDismissed_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerUtils_ref);
	lua_getfield(L, -1, "OnFloatingGamepadTextInputDismissed");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_FloatingGamepadTextInputDismissed_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerUtilsCallbackListener::OnFilterTextDictionaryChanged(FilterTextDictionaryChanged_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerUtils_ref);
	lua_getfield(L, -1, "OnFilterTextDictionaryChanged");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_FilterTextDictionaryChanged_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
GameServerUtilsCallbackListener *GameServerUtils_listener = nullptr;
} // namespace

void init_GameServerUtils_auto(lua_State *L) { if (GameServerUtils_listener != nullptr) return; GameServerUtils_listener = new GameServerUtilsCallbackListener(); }
void shutdown_GameServerUtils_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, GameServerUtils_ref);
	GameServerUtils_ref = LUA_NOREF;
	delete GameServerUtils_listener; GameServerUtils_listener = nullptr;
}

void add_GameServerUtils_auto(lua_State *L) {
	lua_createtable(L, 0, 36);
	register_Utils_auto(L, true);
	lua_pushvalue(L, -1);
	GameServerUtils_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "GameServerUtils");
}

} // namespace luasteam
