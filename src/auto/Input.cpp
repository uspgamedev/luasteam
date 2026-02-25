#include "auto.hpp"

namespace luasteam {

int Input_ref = LUA_NOREF;

namespace {
class InputCallbackListener {
private:
	STEAM_CALLBACK(InputCallbackListener, OnSteamInputDeviceConnected, SteamInputDeviceConnected_t);
	STEAM_CALLBACK(InputCallbackListener, OnSteamInputDeviceDisconnected, SteamInputDeviceDisconnected_t);
	STEAM_CALLBACK(InputCallbackListener, OnSteamInputConfigurationLoaded, SteamInputConfigurationLoaded_t);
	STEAM_CALLBACK(InputCallbackListener, OnSteamInputGamepadSlotChange, SteamInputGamepadSlotChange_t);
};
void InputCallbackListener::OnSteamInputDeviceConnected(SteamInputDeviceConnected_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Input_ref);
	lua_getfield(L, -1, "OnSteamInputDeviceConnected");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamInputDeviceConnected_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void InputCallbackListener::OnSteamInputDeviceDisconnected(SteamInputDeviceDisconnected_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Input_ref);
	lua_getfield(L, -1, "OnSteamInputDeviceDisconnected");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamInputDeviceDisconnected_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void InputCallbackListener::OnSteamInputConfigurationLoaded(SteamInputConfigurationLoaded_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Input_ref);
	lua_getfield(L, -1, "OnSteamInputConfigurationLoaded");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamInputConfigurationLoaded_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void InputCallbackListener::OnSteamInputGamepadSlotChange(SteamInputGamepadSlotChange_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Input_ref);
	lua_getfield(L, -1, "OnSteamInputGamepadSlotChange");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamInputGamepadSlotChange_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
InputCallbackListener *Input_listener = nullptr;
} // namespace

void init_Input_auto(lua_State *L) { if (Input_listener != nullptr) return; Input_listener = new InputCallbackListener(); }
void shutdown_Input_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, Input_ref);
	Input_ref = LUA_NOREF;
	delete Input_listener; Input_listener = nullptr;
}

// In C++:
// bool Init(bool bExplicitlyCallRunFrame);
// In Lua:
// bool Input.Init(bExplicitlyCallRunFrame: bool)
static int luasteam_Input_Init(lua_State *L) {
	auto *iface = SteamInput();
	bool bExplicitlyCallRunFrame = lua_toboolean(L, 1);
	bool __ret = iface->Init(bExplicitlyCallRunFrame);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool Shutdown();
// In Lua:
// bool Input.Shutdown()
static int luasteam_Input_Shutdown(lua_State *L) {
	auto *iface = SteamInput();
	bool __ret = iface->Shutdown();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetInputActionManifestFilePath(const char * pchInputActionManifestAbsolutePath);
// In Lua:
// bool Input.SetInputActionManifestFilePath(pchInputActionManifestAbsolutePath: str)
static int luasteam_Input_SetInputActionManifestFilePath(lua_State *L) {
	auto *iface = SteamInput();
	const char *pchInputActionManifestAbsolutePath = luaL_checkstring(L, 1);
	bool __ret = iface->SetInputActionManifestFilePath(pchInputActionManifestAbsolutePath);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// void RunFrame(bool bReservedValue);
// In Lua:
// Input.RunFrame(bReservedValue: bool)
static int luasteam_Input_RunFrame(lua_State *L) {
	auto *iface = SteamInput();
	bool bReservedValue = lua_toboolean(L, 1);
	iface->RunFrame(bReservedValue);
	return 0;
}

// In C++:
// bool BWaitForData(bool bWaitForever, uint32 unTimeout);
// In Lua:
// bool Input.BWaitForData(bWaitForever: bool, unTimeout: int)
static int luasteam_Input_BWaitForData(lua_State *L) {
	auto *iface = SteamInput();
	bool bWaitForever = lua_toboolean(L, 1);
	uint32 unTimeout = static_cast<uint32>(luaL_checkint(L, 2));
	bool __ret = iface->BWaitForData(bWaitForever, unTimeout);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool BNewDataAvailable();
// In Lua:
// bool Input.BNewDataAvailable()
static int luasteam_Input_BNewDataAvailable(lua_State *L) {
	auto *iface = SteamInput();
	bool __ret = iface->BNewDataAvailable();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// int GetConnectedControllers(InputHandle_t * handlesOut);
// In Lua:
// (int, handlesOut: uint64[]) Input.GetConnectedControllers()
static int luasteam_Input_GetConnectedControllers(lua_State *L) {
	auto *iface = SteamInput();
	std::vector<InputHandle_t> handlesOut(STEAM_INPUT_MAX_COUNT);
	int __ret = iface->GetConnectedControllers(handlesOut.data());
	lua_pushinteger(L, __ret);
	lua_createtable(L, __ret, 0);
	for(decltype(__ret) i = 0; i < __ret; i++) {
		luasteam::pushuint64(L, handlesOut[i]);
		lua_rawseti(L, -2, i+1);
	}
	return 2;
}

// In C++:
// void EnableDeviceCallbacks();
// In Lua:
// Input.EnableDeviceCallbacks()
static int luasteam_Input_EnableDeviceCallbacks(lua_State *L) {
	auto *iface = SteamInput();
	iface->EnableDeviceCallbacks();
	return 0;
}

// In C++:
// InputActionSetHandle_t GetActionSetHandle(const char * pszActionSetName);
// In Lua:
// uint64 Input.GetActionSetHandle(pszActionSetName: str)
static int luasteam_Input_GetActionSetHandle(lua_State *L) {
	auto *iface = SteamInput();
	const char *pszActionSetName = luaL_checkstring(L, 1);
	InputActionSetHandle_t __ret = iface->GetActionSetHandle(pszActionSetName);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// void ActivateActionSet(InputHandle_t inputHandle, InputActionSetHandle_t actionSetHandle);
// In Lua:
// Input.ActivateActionSet(inputHandle: uint64, actionSetHandle: uint64)
static int luasteam_Input_ActivateActionSet(lua_State *L) {
	auto *iface = SteamInput();
	InputHandle_t inputHandle(luasteam::checkuint64(L, 1));
	InputActionSetHandle_t actionSetHandle(luasteam::checkuint64(L, 2));
	iface->ActivateActionSet(inputHandle, actionSetHandle);
	return 0;
}

// In C++:
// InputActionSetHandle_t GetCurrentActionSet(InputHandle_t inputHandle);
// In Lua:
// uint64 Input.GetCurrentActionSet(inputHandle: uint64)
static int luasteam_Input_GetCurrentActionSet(lua_State *L) {
	auto *iface = SteamInput();
	InputHandle_t inputHandle(luasteam::checkuint64(L, 1));
	InputActionSetHandle_t __ret = iface->GetCurrentActionSet(inputHandle);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// void ActivateActionSetLayer(InputHandle_t inputHandle, InputActionSetHandle_t actionSetLayerHandle);
// In Lua:
// Input.ActivateActionSetLayer(inputHandle: uint64, actionSetLayerHandle: uint64)
static int luasteam_Input_ActivateActionSetLayer(lua_State *L) {
	auto *iface = SteamInput();
	InputHandle_t inputHandle(luasteam::checkuint64(L, 1));
	InputActionSetHandle_t actionSetLayerHandle(luasteam::checkuint64(L, 2));
	iface->ActivateActionSetLayer(inputHandle, actionSetLayerHandle);
	return 0;
}

// In C++:
// void DeactivateActionSetLayer(InputHandle_t inputHandle, InputActionSetHandle_t actionSetLayerHandle);
// In Lua:
// Input.DeactivateActionSetLayer(inputHandle: uint64, actionSetLayerHandle: uint64)
static int luasteam_Input_DeactivateActionSetLayer(lua_State *L) {
	auto *iface = SteamInput();
	InputHandle_t inputHandle(luasteam::checkuint64(L, 1));
	InputActionSetHandle_t actionSetLayerHandle(luasteam::checkuint64(L, 2));
	iface->DeactivateActionSetLayer(inputHandle, actionSetLayerHandle);
	return 0;
}

// In C++:
// void DeactivateAllActionSetLayers(InputHandle_t inputHandle);
// In Lua:
// Input.DeactivateAllActionSetLayers(inputHandle: uint64)
static int luasteam_Input_DeactivateAllActionSetLayers(lua_State *L) {
	auto *iface = SteamInput();
	InputHandle_t inputHandle(luasteam::checkuint64(L, 1));
	iface->DeactivateAllActionSetLayers(inputHandle);
	return 0;
}

// In C++:
// int GetActiveActionSetLayers(InputHandle_t inputHandle, InputActionSetHandle_t * handlesOut);
// In Lua:
// (int, handlesOut: uint64[]) Input.GetActiveActionSetLayers(inputHandle: uint64)
static int luasteam_Input_GetActiveActionSetLayers(lua_State *L) {
	auto *iface = SteamInput();
	InputHandle_t inputHandle(luasteam::checkuint64(L, 1));
	std::vector<InputActionSetHandle_t> handlesOut(STEAM_INPUT_MAX_ACTIVE_LAYERS);
	int __ret = iface->GetActiveActionSetLayers(inputHandle, handlesOut.data());
	lua_pushinteger(L, __ret);
	lua_createtable(L, __ret, 0);
	for(decltype(__ret) i = 0; i < __ret; i++) {
		luasteam::pushuint64(L, handlesOut[i]);
		lua_rawseti(L, -2, i+1);
	}
	return 2;
}

// In C++:
// InputDigitalActionHandle_t GetDigitalActionHandle(const char * pszActionName);
// In Lua:
// uint64 Input.GetDigitalActionHandle(pszActionName: str)
static int luasteam_Input_GetDigitalActionHandle(lua_State *L) {
	auto *iface = SteamInput();
	const char *pszActionName = luaL_checkstring(L, 1);
	InputDigitalActionHandle_t __ret = iface->GetDigitalActionHandle(pszActionName);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// InputDigitalActionData_t GetDigitalActionData(InputHandle_t inputHandle, InputDigitalActionHandle_t digitalActionHandle);
// In Lua:
// InputDigitalActionData_t Input.GetDigitalActionData(inputHandle: uint64, digitalActionHandle: uint64)
static int luasteam_Input_GetDigitalActionData(lua_State *L) {
	auto *iface = SteamInput();
	InputHandle_t inputHandle(luasteam::checkuint64(L, 1));
	InputDigitalActionHandle_t digitalActionHandle(luasteam::checkuint64(L, 2));
	InputDigitalActionData_t __ret = iface->GetDigitalActionData(inputHandle, digitalActionHandle);
	luasteam::push_InputDigitalActionData_t(L, __ret);
	return 1;
}

// In C++:
// int GetDigitalActionOrigins(InputHandle_t inputHandle, InputActionSetHandle_t actionSetHandle, InputDigitalActionHandle_t digitalActionHandle, EInputActionOrigin * originsOut);
// In Lua:
// (int, originsOut: int[]) Input.GetDigitalActionOrigins(inputHandle: uint64, actionSetHandle: uint64, digitalActionHandle: uint64)
static int luasteam_Input_GetDigitalActionOrigins(lua_State *L) {
	auto *iface = SteamInput();
	InputHandle_t inputHandle(luasteam::checkuint64(L, 1));
	InputActionSetHandle_t actionSetHandle(luasteam::checkuint64(L, 2));
	InputDigitalActionHandle_t digitalActionHandle(luasteam::checkuint64(L, 3));
	std::vector<EInputActionOrigin> originsOut(STEAM_INPUT_MAX_ORIGINS);
	int __ret = iface->GetDigitalActionOrigins(inputHandle, actionSetHandle, digitalActionHandle, originsOut.data());
	lua_pushinteger(L, __ret);
	lua_createtable(L, __ret, 0);
	for(decltype(__ret) i = 0; i < __ret; i++) {
		lua_pushinteger(L, originsOut[i]);
		lua_rawseti(L, -2, i+1);
	}
	return 2;
}

// In C++:
// const char * GetStringForDigitalActionName(InputDigitalActionHandle_t eActionHandle);
// In Lua:
// str Input.GetStringForDigitalActionName(eActionHandle: uint64)
static int luasteam_Input_GetStringForDigitalActionName(lua_State *L) {
	auto *iface = SteamInput();
	InputDigitalActionHandle_t eActionHandle(luasteam::checkuint64(L, 1));
	const char * __ret = iface->GetStringForDigitalActionName(eActionHandle);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// InputAnalogActionHandle_t GetAnalogActionHandle(const char * pszActionName);
// In Lua:
// uint64 Input.GetAnalogActionHandle(pszActionName: str)
static int luasteam_Input_GetAnalogActionHandle(lua_State *L) {
	auto *iface = SteamInput();
	const char *pszActionName = luaL_checkstring(L, 1);
	InputAnalogActionHandle_t __ret = iface->GetAnalogActionHandle(pszActionName);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// InputAnalogActionData_t GetAnalogActionData(InputHandle_t inputHandle, InputAnalogActionHandle_t analogActionHandle);
// In Lua:
// InputAnalogActionData_t Input.GetAnalogActionData(inputHandle: uint64, analogActionHandle: uint64)
static int luasteam_Input_GetAnalogActionData(lua_State *L) {
	auto *iface = SteamInput();
	InputHandle_t inputHandle(luasteam::checkuint64(L, 1));
	InputAnalogActionHandle_t analogActionHandle(luasteam::checkuint64(L, 2));
	InputAnalogActionData_t __ret = iface->GetAnalogActionData(inputHandle, analogActionHandle);
	luasteam::push_InputAnalogActionData_t(L, __ret);
	return 1;
}

// In C++:
// int GetAnalogActionOrigins(InputHandle_t inputHandle, InputActionSetHandle_t actionSetHandle, InputAnalogActionHandle_t analogActionHandle, EInputActionOrigin * originsOut);
// In Lua:
// (int, originsOut: int[]) Input.GetAnalogActionOrigins(inputHandle: uint64, actionSetHandle: uint64, analogActionHandle: uint64)
static int luasteam_Input_GetAnalogActionOrigins(lua_State *L) {
	auto *iface = SteamInput();
	InputHandle_t inputHandle(luasteam::checkuint64(L, 1));
	InputActionSetHandle_t actionSetHandle(luasteam::checkuint64(L, 2));
	InputAnalogActionHandle_t analogActionHandle(luasteam::checkuint64(L, 3));
	std::vector<EInputActionOrigin> originsOut(STEAM_INPUT_MAX_ORIGINS);
	int __ret = iface->GetAnalogActionOrigins(inputHandle, actionSetHandle, analogActionHandle, originsOut.data());
	lua_pushinteger(L, __ret);
	lua_createtable(L, __ret, 0);
	for(decltype(__ret) i = 0; i < __ret; i++) {
		lua_pushinteger(L, originsOut[i]);
		lua_rawseti(L, -2, i+1);
	}
	return 2;
}

// In C++:
// const char * GetGlyphPNGForActionOrigin(EInputActionOrigin eOrigin, ESteamInputGlyphSize eSize, uint32 unFlags);
// In Lua:
// str Input.GetGlyphPNGForActionOrigin(eOrigin: int, eSize: int, unFlags: int)
static int luasteam_Input_GetGlyphPNGForActionOrigin(lua_State *L) {
	auto *iface = SteamInput();
	EInputActionOrigin eOrigin = static_cast<EInputActionOrigin>(luaL_checkint(L, 1));
	ESteamInputGlyphSize eSize = static_cast<ESteamInputGlyphSize>(luaL_checkint(L, 2));
	uint32 unFlags = static_cast<uint32>(luaL_checkint(L, 3));
	const char * __ret = iface->GetGlyphPNGForActionOrigin(eOrigin, eSize, unFlags);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// const char * GetGlyphSVGForActionOrigin(EInputActionOrigin eOrigin, uint32 unFlags);
// In Lua:
// str Input.GetGlyphSVGForActionOrigin(eOrigin: int, unFlags: int)
static int luasteam_Input_GetGlyphSVGForActionOrigin(lua_State *L) {
	auto *iface = SteamInput();
	EInputActionOrigin eOrigin = static_cast<EInputActionOrigin>(luaL_checkint(L, 1));
	uint32 unFlags = static_cast<uint32>(luaL_checkint(L, 2));
	const char * __ret = iface->GetGlyphSVGForActionOrigin(eOrigin, unFlags);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// const char * GetGlyphForActionOrigin_Legacy(EInputActionOrigin eOrigin);
// In Lua:
// str Input.GetGlyphForActionOrigin_Legacy(eOrigin: int)
static int luasteam_Input_GetGlyphForActionOrigin_Legacy(lua_State *L) {
	auto *iface = SteamInput();
	EInputActionOrigin eOrigin = static_cast<EInputActionOrigin>(luaL_checkint(L, 1));
	const char * __ret = iface->GetGlyphForActionOrigin_Legacy(eOrigin);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// const char * GetStringForActionOrigin(EInputActionOrigin eOrigin);
// In Lua:
// str Input.GetStringForActionOrigin(eOrigin: int)
static int luasteam_Input_GetStringForActionOrigin(lua_State *L) {
	auto *iface = SteamInput();
	EInputActionOrigin eOrigin = static_cast<EInputActionOrigin>(luaL_checkint(L, 1));
	const char * __ret = iface->GetStringForActionOrigin(eOrigin);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// const char * GetStringForAnalogActionName(InputAnalogActionHandle_t eActionHandle);
// In Lua:
// str Input.GetStringForAnalogActionName(eActionHandle: uint64)
static int luasteam_Input_GetStringForAnalogActionName(lua_State *L) {
	auto *iface = SteamInput();
	InputAnalogActionHandle_t eActionHandle(luasteam::checkuint64(L, 1));
	const char * __ret = iface->GetStringForAnalogActionName(eActionHandle);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// void StopAnalogActionMomentum(InputHandle_t inputHandle, InputAnalogActionHandle_t eAction);
// In Lua:
// Input.StopAnalogActionMomentum(inputHandle: uint64, eAction: uint64)
static int luasteam_Input_StopAnalogActionMomentum(lua_State *L) {
	auto *iface = SteamInput();
	InputHandle_t inputHandle(luasteam::checkuint64(L, 1));
	InputAnalogActionHandle_t eAction(luasteam::checkuint64(L, 2));
	iface->StopAnalogActionMomentum(inputHandle, eAction);
	return 0;
}

// In C++:
// InputMotionData_t GetMotionData(InputHandle_t inputHandle);
// In Lua:
// InputMotionData_t Input.GetMotionData(inputHandle: uint64)
static int luasteam_Input_GetMotionData(lua_State *L) {
	auto *iface = SteamInput();
	InputHandle_t inputHandle(luasteam::checkuint64(L, 1));
	InputMotionData_t __ret = iface->GetMotionData(inputHandle);
	luasteam::push_InputMotionData_t(L, __ret);
	return 1;
}

// In C++:
// void TriggerVibration(InputHandle_t inputHandle, unsigned short usLeftSpeed, unsigned short usRightSpeed);
// In Lua:
// Input.TriggerVibration(inputHandle: uint64, usLeftSpeed: int, usRightSpeed: int)
static int luasteam_Input_TriggerVibration(lua_State *L) {
	auto *iface = SteamInput();
	InputHandle_t inputHandle(luasteam::checkuint64(L, 1));
	unsigned short usLeftSpeed = static_cast<unsigned short>(luaL_checkint(L, 2));
	unsigned short usRightSpeed = static_cast<unsigned short>(luaL_checkint(L, 3));
	iface->TriggerVibration(inputHandle, usLeftSpeed, usRightSpeed);
	return 0;
}

// In C++:
// void TriggerVibrationExtended(InputHandle_t inputHandle, unsigned short usLeftSpeed, unsigned short usRightSpeed, unsigned short usLeftTriggerSpeed, unsigned short usRightTriggerSpeed);
// In Lua:
// Input.TriggerVibrationExtended(inputHandle: uint64, usLeftSpeed: int, usRightSpeed: int, usLeftTriggerSpeed: int, usRightTriggerSpeed: int)
static int luasteam_Input_TriggerVibrationExtended(lua_State *L) {
	auto *iface = SteamInput();
	InputHandle_t inputHandle(luasteam::checkuint64(L, 1));
	unsigned short usLeftSpeed = static_cast<unsigned short>(luaL_checkint(L, 2));
	unsigned short usRightSpeed = static_cast<unsigned short>(luaL_checkint(L, 3));
	unsigned short usLeftTriggerSpeed = static_cast<unsigned short>(luaL_checkint(L, 4));
	unsigned short usRightTriggerSpeed = static_cast<unsigned short>(luaL_checkint(L, 5));
	iface->TriggerVibrationExtended(inputHandle, usLeftSpeed, usRightSpeed, usLeftTriggerSpeed, usRightTriggerSpeed);
	return 0;
}

// In C++:
// void TriggerSimpleHapticEvent(InputHandle_t inputHandle, EControllerHapticLocation eHapticLocation, uint8 nIntensity, char nGainDB, uint8 nOtherIntensity, char nOtherGainDB);
// In Lua:
// Input.TriggerSimpleHapticEvent(inputHandle: uint64, eHapticLocation: int, nIntensity: int, nGainDB: str, nOtherIntensity: int, nOtherGainDB: str)
static int luasteam_Input_TriggerSimpleHapticEvent(lua_State *L) {
	auto *iface = SteamInput();
	InputHandle_t inputHandle(luasteam::checkuint64(L, 1));
	EControllerHapticLocation eHapticLocation = static_cast<EControllerHapticLocation>(luaL_checkint(L, 2));
	uint8 nIntensity = static_cast<uint8>(luaL_checkint(L, 3));
	char nGainDB = luaL_checkstring(L, 4)[0];
	uint8 nOtherIntensity = static_cast<uint8>(luaL_checkint(L, 5));
	char nOtherGainDB = luaL_checkstring(L, 6)[0];
	iface->TriggerSimpleHapticEvent(inputHandle, eHapticLocation, nIntensity, nGainDB, nOtherIntensity, nOtherGainDB);
	return 0;
}

// In C++:
// void SetLEDColor(InputHandle_t inputHandle, uint8 nColorR, uint8 nColorG, uint8 nColorB, unsigned int nFlags);
// In Lua:
// Input.SetLEDColor(inputHandle: uint64, nColorR: int, nColorG: int, nColorB: int, nFlags: int)
static int luasteam_Input_SetLEDColor(lua_State *L) {
	auto *iface = SteamInput();
	InputHandle_t inputHandle(luasteam::checkuint64(L, 1));
	uint8 nColorR = static_cast<uint8>(luaL_checkint(L, 2));
	uint8 nColorG = static_cast<uint8>(luaL_checkint(L, 3));
	uint8 nColorB = static_cast<uint8>(luaL_checkint(L, 4));
	unsigned int nFlags = static_cast<unsigned int>(luaL_checkint(L, 5));
	iface->SetLEDColor(inputHandle, nColorR, nColorG, nColorB, nFlags);
	return 0;
}

// In C++:
// void Legacy_TriggerHapticPulse(InputHandle_t inputHandle, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec);
// In Lua:
// Input.Legacy_TriggerHapticPulse(inputHandle: uint64, eTargetPad: int, usDurationMicroSec: int)
static int luasteam_Input_Legacy_TriggerHapticPulse(lua_State *L) {
	auto *iface = SteamInput();
	InputHandle_t inputHandle(luasteam::checkuint64(L, 1));
	ESteamControllerPad eTargetPad = static_cast<ESteamControllerPad>(luaL_checkint(L, 2));
	unsigned short usDurationMicroSec = static_cast<unsigned short>(luaL_checkint(L, 3));
	iface->Legacy_TriggerHapticPulse(inputHandle, eTargetPad, usDurationMicroSec);
	return 0;
}

// In C++:
// void Legacy_TriggerRepeatedHapticPulse(InputHandle_t inputHandle, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec, unsigned short usOffMicroSec, unsigned short unRepeat, unsigned int nFlags);
// In Lua:
// Input.Legacy_TriggerRepeatedHapticPulse(inputHandle: uint64, eTargetPad: int, usDurationMicroSec: int, usOffMicroSec: int, unRepeat: int, nFlags: int)
static int luasteam_Input_Legacy_TriggerRepeatedHapticPulse(lua_State *L) {
	auto *iface = SteamInput();
	InputHandle_t inputHandle(luasteam::checkuint64(L, 1));
	ESteamControllerPad eTargetPad = static_cast<ESteamControllerPad>(luaL_checkint(L, 2));
	unsigned short usDurationMicroSec = static_cast<unsigned short>(luaL_checkint(L, 3));
	unsigned short usOffMicroSec = static_cast<unsigned short>(luaL_checkint(L, 4));
	unsigned short unRepeat = static_cast<unsigned short>(luaL_checkint(L, 5));
	unsigned int nFlags = static_cast<unsigned int>(luaL_checkint(L, 6));
	iface->Legacy_TriggerRepeatedHapticPulse(inputHandle, eTargetPad, usDurationMicroSec, usOffMicroSec, unRepeat, nFlags);
	return 0;
}

// In C++:
// bool ShowBindingPanel(InputHandle_t inputHandle);
// In Lua:
// bool Input.ShowBindingPanel(inputHandle: uint64)
static int luasteam_Input_ShowBindingPanel(lua_State *L) {
	auto *iface = SteamInput();
	InputHandle_t inputHandle(luasteam::checkuint64(L, 1));
	bool __ret = iface->ShowBindingPanel(inputHandle);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// ESteamInputType GetInputTypeForHandle(InputHandle_t inputHandle);
// In Lua:
// int Input.GetInputTypeForHandle(inputHandle: uint64)
static int luasteam_Input_GetInputTypeForHandle(lua_State *L) {
	auto *iface = SteamInput();
	InputHandle_t inputHandle(luasteam::checkuint64(L, 1));
	ESteamInputType __ret = iface->GetInputTypeForHandle(inputHandle);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// InputHandle_t GetControllerForGamepadIndex(int nIndex);
// In Lua:
// uint64 Input.GetControllerForGamepadIndex(nIndex: int)
static int luasteam_Input_GetControllerForGamepadIndex(lua_State *L) {
	auto *iface = SteamInput();
	int nIndex = static_cast<int>(luaL_checkint(L, 1));
	InputHandle_t __ret = iface->GetControllerForGamepadIndex(nIndex);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// int GetGamepadIndexForController(InputHandle_t ulinputHandle);
// In Lua:
// int Input.GetGamepadIndexForController(ulinputHandle: uint64)
static int luasteam_Input_GetGamepadIndexForController(lua_State *L) {
	auto *iface = SteamInput();
	InputHandle_t ulinputHandle(luasteam::checkuint64(L, 1));
	int __ret = iface->GetGamepadIndexForController(ulinputHandle);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// const char * GetStringForXboxOrigin(EXboxOrigin eOrigin);
// In Lua:
// str Input.GetStringForXboxOrigin(eOrigin: int)
static int luasteam_Input_GetStringForXboxOrigin(lua_State *L) {
	auto *iface = SteamInput();
	EXboxOrigin eOrigin = static_cast<EXboxOrigin>(luaL_checkint(L, 1));
	const char * __ret = iface->GetStringForXboxOrigin(eOrigin);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// const char * GetGlyphForXboxOrigin(EXboxOrigin eOrigin);
// In Lua:
// str Input.GetGlyphForXboxOrigin(eOrigin: int)
static int luasteam_Input_GetGlyphForXboxOrigin(lua_State *L) {
	auto *iface = SteamInput();
	EXboxOrigin eOrigin = static_cast<EXboxOrigin>(luaL_checkint(L, 1));
	const char * __ret = iface->GetGlyphForXboxOrigin(eOrigin);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// EInputActionOrigin GetActionOriginFromXboxOrigin(InputHandle_t inputHandle, EXboxOrigin eOrigin);
// In Lua:
// int Input.GetActionOriginFromXboxOrigin(inputHandle: uint64, eOrigin: int)
static int luasteam_Input_GetActionOriginFromXboxOrigin(lua_State *L) {
	auto *iface = SteamInput();
	InputHandle_t inputHandle(luasteam::checkuint64(L, 1));
	EXboxOrigin eOrigin = static_cast<EXboxOrigin>(luaL_checkint(L, 2));
	EInputActionOrigin __ret = iface->GetActionOriginFromXboxOrigin(inputHandle, eOrigin);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// EInputActionOrigin TranslateActionOrigin(ESteamInputType eDestinationInputType, EInputActionOrigin eSourceOrigin);
// In Lua:
// int Input.TranslateActionOrigin(eDestinationInputType: int, eSourceOrigin: int)
static int luasteam_Input_TranslateActionOrigin(lua_State *L) {
	auto *iface = SteamInput();
	ESteamInputType eDestinationInputType = static_cast<ESteamInputType>(luaL_checkint(L, 1));
	EInputActionOrigin eSourceOrigin = static_cast<EInputActionOrigin>(luaL_checkint(L, 2));
	EInputActionOrigin __ret = iface->TranslateActionOrigin(eDestinationInputType, eSourceOrigin);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool GetDeviceBindingRevision(InputHandle_t inputHandle, int * pMajor, int * pMinor);
// In Lua:
// (bool, pMajor: int, pMinor: int) Input.GetDeviceBindingRevision(inputHandle: uint64)
static int luasteam_Input_GetDeviceBindingRevision(lua_State *L) {
	auto *iface = SteamInput();
	InputHandle_t inputHandle(luasteam::checkuint64(L, 1));
	int pMajor;
	int pMinor;
	bool __ret = iface->GetDeviceBindingRevision(inputHandle, &pMajor, &pMinor);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pMajor);
	lua_pushinteger(L, pMinor);
	return 3;
}

// In C++:
// uint32 GetRemotePlaySessionID(InputHandle_t inputHandle);
// In Lua:
// int Input.GetRemotePlaySessionID(inputHandle: uint64)
static int luasteam_Input_GetRemotePlaySessionID(lua_State *L) {
	auto *iface = SteamInput();
	InputHandle_t inputHandle(luasteam::checkuint64(L, 1));
	uint32 __ret = iface->GetRemotePlaySessionID(inputHandle);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// uint16 GetSessionInputConfigurationSettings();
// In Lua:
// int Input.GetSessionInputConfigurationSettings()
static int luasteam_Input_GetSessionInputConfigurationSettings(lua_State *L) {
	auto *iface = SteamInput();
	uint16 __ret = iface->GetSessionInputConfigurationSettings();
	lua_pushinteger(L, __ret);
	return 1;
}

void register_Input_auto(lua_State *L) {
	add_func(L, "Init", luasteam_Input_Init);
	add_func(L, "Shutdown", luasteam_Input_Shutdown);
	add_func(L, "SetInputActionManifestFilePath", luasteam_Input_SetInputActionManifestFilePath);
	add_func(L, "RunFrame", luasteam_Input_RunFrame);
	add_func(L, "BWaitForData", luasteam_Input_BWaitForData);
	add_func(L, "BNewDataAvailable", luasteam_Input_BNewDataAvailable);
	add_func(L, "GetConnectedControllers", luasteam_Input_GetConnectedControllers);
	add_func(L, "EnableDeviceCallbacks", luasteam_Input_EnableDeviceCallbacks);
	add_func(L, "GetActionSetHandle", luasteam_Input_GetActionSetHandle);
	add_func(L, "ActivateActionSet", luasteam_Input_ActivateActionSet);
	add_func(L, "GetCurrentActionSet", luasteam_Input_GetCurrentActionSet);
	add_func(L, "ActivateActionSetLayer", luasteam_Input_ActivateActionSetLayer);
	add_func(L, "DeactivateActionSetLayer", luasteam_Input_DeactivateActionSetLayer);
	add_func(L, "DeactivateAllActionSetLayers", luasteam_Input_DeactivateAllActionSetLayers);
	add_func(L, "GetActiveActionSetLayers", luasteam_Input_GetActiveActionSetLayers);
	add_func(L, "GetDigitalActionHandle", luasteam_Input_GetDigitalActionHandle);
	add_func(L, "GetDigitalActionData", luasteam_Input_GetDigitalActionData);
	add_func(L, "GetDigitalActionOrigins", luasteam_Input_GetDigitalActionOrigins);
	add_func(L, "GetStringForDigitalActionName", luasteam_Input_GetStringForDigitalActionName);
	add_func(L, "GetAnalogActionHandle", luasteam_Input_GetAnalogActionHandle);
	add_func(L, "GetAnalogActionData", luasteam_Input_GetAnalogActionData);
	add_func(L, "GetAnalogActionOrigins", luasteam_Input_GetAnalogActionOrigins);
	add_func(L, "GetGlyphPNGForActionOrigin", luasteam_Input_GetGlyphPNGForActionOrigin);
	add_func(L, "GetGlyphSVGForActionOrigin", luasteam_Input_GetGlyphSVGForActionOrigin);
	add_func(L, "GetGlyphForActionOrigin_Legacy", luasteam_Input_GetGlyphForActionOrigin_Legacy);
	add_func(L, "GetStringForActionOrigin", luasteam_Input_GetStringForActionOrigin);
	add_func(L, "GetStringForAnalogActionName", luasteam_Input_GetStringForAnalogActionName);
	add_func(L, "StopAnalogActionMomentum", luasteam_Input_StopAnalogActionMomentum);
	add_func(L, "GetMotionData", luasteam_Input_GetMotionData);
	add_func(L, "TriggerVibration", luasteam_Input_TriggerVibration);
	add_func(L, "TriggerVibrationExtended", luasteam_Input_TriggerVibrationExtended);
	add_func(L, "TriggerSimpleHapticEvent", luasteam_Input_TriggerSimpleHapticEvent);
	add_func(L, "SetLEDColor", luasteam_Input_SetLEDColor);
	add_func(L, "Legacy_TriggerHapticPulse", luasteam_Input_Legacy_TriggerHapticPulse);
	add_func(L, "Legacy_TriggerRepeatedHapticPulse", luasteam_Input_Legacy_TriggerRepeatedHapticPulse);
	add_func(L, "ShowBindingPanel", luasteam_Input_ShowBindingPanel);
	add_func(L, "GetInputTypeForHandle", luasteam_Input_GetInputTypeForHandle);
	add_func(L, "GetControllerForGamepadIndex", luasteam_Input_GetControllerForGamepadIndex);
	add_func(L, "GetGamepadIndexForController", luasteam_Input_GetGamepadIndexForController);
	add_func(L, "GetStringForXboxOrigin", luasteam_Input_GetStringForXboxOrigin);
	add_func(L, "GetGlyphForXboxOrigin", luasteam_Input_GetGlyphForXboxOrigin);
	add_func(L, "GetActionOriginFromXboxOrigin", luasteam_Input_GetActionOriginFromXboxOrigin);
	add_func(L, "TranslateActionOrigin", luasteam_Input_TranslateActionOrigin);
	add_func(L, "GetDeviceBindingRevision", luasteam_Input_GetDeviceBindingRevision);
	add_func(L, "GetRemotePlaySessionID", luasteam_Input_GetRemotePlaySessionID);
	add_func(L, "GetSessionInputConfigurationSettings", luasteam_Input_GetSessionInputConfigurationSettings);
}

void add_Input_auto(lua_State *L) {
	lua_createtable(L, 0, 46);
	register_Input_auto(L);
	lua_pushvalue(L, -1);
	Input_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "Input");
}

} // namespace luasteam
