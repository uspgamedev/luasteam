#include "auto.hpp"

namespace luasteam {

int Controller_ref = LUA_NOREF;

void init_Controller_auto(lua_State *L) {}
void shutdown_Controller_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, Controller_ref);
	Controller_ref = LUA_NOREF;
}

// bool Init();
EXTERN int luasteam_Controller_Init(lua_State *L) {
	bool __ret = SteamController()->Init();
	lua_pushboolean(L, __ret);
	return 1;
}

// bool Shutdown();
EXTERN int luasteam_Controller_Shutdown(lua_State *L) {
	bool __ret = SteamController()->Shutdown();
	lua_pushboolean(L, __ret);
	return 1;
}

// void RunFrame();
EXTERN int luasteam_Controller_RunFrame(lua_State *L) {
	SteamController()->RunFrame();
	return 0;
}

// int GetConnectedControllers(ControllerHandle_t * handlesOut);
EXTERN int luasteam_Controller_GetConnectedControllers(lua_State *L) {
	std::vector<ControllerHandle_t> handlesOut(STEAM_INPUT_MAX_COUNT);
	int __ret = SteamController()->GetConnectedControllers(handlesOut.data());
	lua_pushinteger(L, __ret);
	lua_createtable(L, STEAM_INPUT_MAX_COUNT, 0);
	for(decltype(STEAM_INPUT_MAX_COUNT) i = 0; i < STEAM_INPUT_MAX_COUNT; i++) {
		luasteam::pushuint64(L, handlesOut[i]);
		lua_rawseti(L, -2, i+1);
	}
	return 2;
}

// ControllerActionSetHandle_t GetActionSetHandle(const char * pszActionSetName);
EXTERN int luasteam_Controller_GetActionSetHandle(lua_State *L) {
	const char *pszActionSetName = luaL_checkstring(L, 1);
	ControllerActionSetHandle_t __ret = SteamController()->GetActionSetHandle(pszActionSetName);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// void ActivateActionSet(ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetHandle);
EXTERN int luasteam_Controller_ActivateActionSet(lua_State *L) {
	ControllerHandle_t controllerHandle(luasteam::checkuint64(L, 1));
	ControllerActionSetHandle_t actionSetHandle(luasteam::checkuint64(L, 2));
	SteamController()->ActivateActionSet(controllerHandle, actionSetHandle);
	return 0;
}

// ControllerActionSetHandle_t GetCurrentActionSet(ControllerHandle_t controllerHandle);
EXTERN int luasteam_Controller_GetCurrentActionSet(lua_State *L) {
	ControllerHandle_t controllerHandle(luasteam::checkuint64(L, 1));
	ControllerActionSetHandle_t __ret = SteamController()->GetCurrentActionSet(controllerHandle);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// void ActivateActionSetLayer(ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetLayerHandle);
EXTERN int luasteam_Controller_ActivateActionSetLayer(lua_State *L) {
	ControllerHandle_t controllerHandle(luasteam::checkuint64(L, 1));
	ControllerActionSetHandle_t actionSetLayerHandle(luasteam::checkuint64(L, 2));
	SteamController()->ActivateActionSetLayer(controllerHandle, actionSetLayerHandle);
	return 0;
}

// void DeactivateActionSetLayer(ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetLayerHandle);
EXTERN int luasteam_Controller_DeactivateActionSetLayer(lua_State *L) {
	ControllerHandle_t controllerHandle(luasteam::checkuint64(L, 1));
	ControllerActionSetHandle_t actionSetLayerHandle(luasteam::checkuint64(L, 2));
	SteamController()->DeactivateActionSetLayer(controllerHandle, actionSetLayerHandle);
	return 0;
}

// void DeactivateAllActionSetLayers(ControllerHandle_t controllerHandle);
EXTERN int luasteam_Controller_DeactivateAllActionSetLayers(lua_State *L) {
	ControllerHandle_t controllerHandle(luasteam::checkuint64(L, 1));
	SteamController()->DeactivateAllActionSetLayers(controllerHandle);
	return 0;
}

// int GetActiveActionSetLayers(ControllerHandle_t controllerHandle, ControllerActionSetHandle_t * handlesOut);
EXTERN int luasteam_Controller_GetActiveActionSetLayers(lua_State *L) {
	ControllerHandle_t controllerHandle(luasteam::checkuint64(L, 1));
	std::vector<ControllerActionSetHandle_t> handlesOut(STEAM_INPUT_MAX_ACTIVE_LAYERS);
	int __ret = SteamController()->GetActiveActionSetLayers(controllerHandle, handlesOut.data());
	lua_pushinteger(L, __ret);
	lua_createtable(L, STEAM_INPUT_MAX_ACTIVE_LAYERS, 0);
	for(decltype(STEAM_INPUT_MAX_ACTIVE_LAYERS) i = 0; i < STEAM_INPUT_MAX_ACTIVE_LAYERS; i++) {
		luasteam::pushuint64(L, handlesOut[i]);
		lua_rawseti(L, -2, i+1);
	}
	return 2;
}

// ControllerDigitalActionHandle_t GetDigitalActionHandle(const char * pszActionName);
EXTERN int luasteam_Controller_GetDigitalActionHandle(lua_State *L) {
	const char *pszActionName = luaL_checkstring(L, 1);
	ControllerDigitalActionHandle_t __ret = SteamController()->GetDigitalActionHandle(pszActionName);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// InputDigitalActionData_t GetDigitalActionData(ControllerHandle_t controllerHandle, ControllerDigitalActionHandle_t digitalActionHandle);
EXTERN int luasteam_Controller_GetDigitalActionData(lua_State *L) {
	ControllerHandle_t controllerHandle(luasteam::checkuint64(L, 1));
	ControllerDigitalActionHandle_t digitalActionHandle(luasteam::checkuint64(L, 2));
	InputDigitalActionData_t __ret = SteamController()->GetDigitalActionData(controllerHandle, digitalActionHandle);
	push_InputDigitalActionData_t(L, __ret);
	return 1;
}

// int GetDigitalActionOrigins(ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetHandle, ControllerDigitalActionHandle_t digitalActionHandle, EControllerActionOrigin * originsOut);
EXTERN int luasteam_Controller_GetDigitalActionOrigins(lua_State *L) {
	ControllerHandle_t controllerHandle(luasteam::checkuint64(L, 1));
	ControllerActionSetHandle_t actionSetHandle(luasteam::checkuint64(L, 2));
	ControllerDigitalActionHandle_t digitalActionHandle(luasteam::checkuint64(L, 3));
	std::vector<EControllerActionOrigin> originsOut(STEAM_INPUT_MAX_ORIGINS);
	int __ret = SteamController()->GetDigitalActionOrigins(controllerHandle, actionSetHandle, digitalActionHandle, originsOut.data());
	lua_pushinteger(L, __ret);
	lua_createtable(L, STEAM_INPUT_MAX_ORIGINS, 0);
	for(decltype(STEAM_INPUT_MAX_ORIGINS) i = 0; i < STEAM_INPUT_MAX_ORIGINS; i++) {
		lua_pushinteger(L, originsOut[i]);
		lua_rawseti(L, -2, i+1);
	}
	return 2;
}

// ControllerAnalogActionHandle_t GetAnalogActionHandle(const char * pszActionName);
EXTERN int luasteam_Controller_GetAnalogActionHandle(lua_State *L) {
	const char *pszActionName = luaL_checkstring(L, 1);
	ControllerAnalogActionHandle_t __ret = SteamController()->GetAnalogActionHandle(pszActionName);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// InputAnalogActionData_t GetAnalogActionData(ControllerHandle_t controllerHandle, ControllerAnalogActionHandle_t analogActionHandle);
EXTERN int luasteam_Controller_GetAnalogActionData(lua_State *L) {
	ControllerHandle_t controllerHandle(luasteam::checkuint64(L, 1));
	ControllerAnalogActionHandle_t analogActionHandle(luasteam::checkuint64(L, 2));
	InputAnalogActionData_t __ret = SteamController()->GetAnalogActionData(controllerHandle, analogActionHandle);
	push_InputAnalogActionData_t(L, __ret);
	return 1;
}

// int GetAnalogActionOrigins(ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetHandle, ControllerAnalogActionHandle_t analogActionHandle, EControllerActionOrigin * originsOut);
EXTERN int luasteam_Controller_GetAnalogActionOrigins(lua_State *L) {
	ControllerHandle_t controllerHandle(luasteam::checkuint64(L, 1));
	ControllerActionSetHandle_t actionSetHandle(luasteam::checkuint64(L, 2));
	ControllerAnalogActionHandle_t analogActionHandle(luasteam::checkuint64(L, 3));
	std::vector<EControllerActionOrigin> originsOut(STEAM_INPUT_MAX_ORIGINS);
	int __ret = SteamController()->GetAnalogActionOrigins(controllerHandle, actionSetHandle, analogActionHandle, originsOut.data());
	lua_pushinteger(L, __ret);
	lua_createtable(L, STEAM_INPUT_MAX_ORIGINS, 0);
	for(decltype(STEAM_INPUT_MAX_ORIGINS) i = 0; i < STEAM_INPUT_MAX_ORIGINS; i++) {
		lua_pushinteger(L, originsOut[i]);
		lua_rawseti(L, -2, i+1);
	}
	return 2;
}

// const char * GetGlyphForActionOrigin(EControllerActionOrigin eOrigin);
EXTERN int luasteam_Controller_GetGlyphForActionOrigin(lua_State *L) {
	EControllerActionOrigin eOrigin = static_cast<EControllerActionOrigin>(luaL_checkint(L, 1));
	const char * __ret = SteamController()->GetGlyphForActionOrigin(eOrigin);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// const char * GetStringForActionOrigin(EControllerActionOrigin eOrigin);
EXTERN int luasteam_Controller_GetStringForActionOrigin(lua_State *L) {
	EControllerActionOrigin eOrigin = static_cast<EControllerActionOrigin>(luaL_checkint(L, 1));
	const char * __ret = SteamController()->GetStringForActionOrigin(eOrigin);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// void StopAnalogActionMomentum(ControllerHandle_t controllerHandle, ControllerAnalogActionHandle_t eAction);
EXTERN int luasteam_Controller_StopAnalogActionMomentum(lua_State *L) {
	ControllerHandle_t controllerHandle(luasteam::checkuint64(L, 1));
	ControllerAnalogActionHandle_t eAction(luasteam::checkuint64(L, 2));
	SteamController()->StopAnalogActionMomentum(controllerHandle, eAction);
	return 0;
}

// InputMotionData_t GetMotionData(ControllerHandle_t controllerHandle);
EXTERN int luasteam_Controller_GetMotionData(lua_State *L) {
	ControllerHandle_t controllerHandle(luasteam::checkuint64(L, 1));
	InputMotionData_t __ret = SteamController()->GetMotionData(controllerHandle);
	push_InputMotionData_t(L, __ret);
	return 1;
}

// void TriggerHapticPulse(ControllerHandle_t controllerHandle, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec);
EXTERN int luasteam_Controller_TriggerHapticPulse(lua_State *L) {
	ControllerHandle_t controllerHandle(luasteam::checkuint64(L, 1));
	ESteamControllerPad eTargetPad = static_cast<ESteamControllerPad>(luaL_checkint(L, 2));
	unsigned short usDurationMicroSec = static_cast<unsigned short>(luaL_checkint(L, 3));
	SteamController()->TriggerHapticPulse(controllerHandle, eTargetPad, usDurationMicroSec);
	return 0;
}

// void TriggerRepeatedHapticPulse(ControllerHandle_t controllerHandle, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec, unsigned short usOffMicroSec, unsigned short unRepeat, unsigned int nFlags);
EXTERN int luasteam_Controller_TriggerRepeatedHapticPulse(lua_State *L) {
	ControllerHandle_t controllerHandle(luasteam::checkuint64(L, 1));
	ESteamControllerPad eTargetPad = static_cast<ESteamControllerPad>(luaL_checkint(L, 2));
	unsigned short usDurationMicroSec = static_cast<unsigned short>(luaL_checkint(L, 3));
	unsigned short usOffMicroSec = static_cast<unsigned short>(luaL_checkint(L, 4));
	unsigned short unRepeat = static_cast<unsigned short>(luaL_checkint(L, 5));
	unsigned int nFlags = static_cast<unsigned int>(luaL_checkint(L, 6));
	SteamController()->TriggerRepeatedHapticPulse(controllerHandle, eTargetPad, usDurationMicroSec, usOffMicroSec, unRepeat, nFlags);
	return 0;
}

// void TriggerVibration(ControllerHandle_t controllerHandle, unsigned short usLeftSpeed, unsigned short usRightSpeed);
EXTERN int luasteam_Controller_TriggerVibration(lua_State *L) {
	ControllerHandle_t controllerHandle(luasteam::checkuint64(L, 1));
	unsigned short usLeftSpeed = static_cast<unsigned short>(luaL_checkint(L, 2));
	unsigned short usRightSpeed = static_cast<unsigned short>(luaL_checkint(L, 3));
	SteamController()->TriggerVibration(controllerHandle, usLeftSpeed, usRightSpeed);
	return 0;
}

// void SetLEDColor(ControllerHandle_t controllerHandle, uint8 nColorR, uint8 nColorG, uint8 nColorB, unsigned int nFlags);
EXTERN int luasteam_Controller_SetLEDColor(lua_State *L) {
	ControllerHandle_t controllerHandle(luasteam::checkuint64(L, 1));
	uint8 nColorR = static_cast<uint8>(luaL_checkint(L, 2));
	uint8 nColorG = static_cast<uint8>(luaL_checkint(L, 3));
	uint8 nColorB = static_cast<uint8>(luaL_checkint(L, 4));
	unsigned int nFlags = static_cast<unsigned int>(luaL_checkint(L, 5));
	SteamController()->SetLEDColor(controllerHandle, nColorR, nColorG, nColorB, nFlags);
	return 0;
}

// bool ShowBindingPanel(ControllerHandle_t controllerHandle);
EXTERN int luasteam_Controller_ShowBindingPanel(lua_State *L) {
	ControllerHandle_t controllerHandle(luasteam::checkuint64(L, 1));
	bool __ret = SteamController()->ShowBindingPanel(controllerHandle);
	lua_pushboolean(L, __ret);
	return 1;
}

// ESteamInputType GetInputTypeForHandle(ControllerHandle_t controllerHandle);
EXTERN int luasteam_Controller_GetInputTypeForHandle(lua_State *L) {
	ControllerHandle_t controllerHandle(luasteam::checkuint64(L, 1));
	ESteamInputType __ret = SteamController()->GetInputTypeForHandle(controllerHandle);
	lua_pushinteger(L, __ret);
	return 1;
}

// ControllerHandle_t GetControllerForGamepadIndex(int nIndex);
EXTERN int luasteam_Controller_GetControllerForGamepadIndex(lua_State *L) {
	int nIndex = static_cast<int>(luaL_checkint(L, 1));
	ControllerHandle_t __ret = SteamController()->GetControllerForGamepadIndex(nIndex);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// int GetGamepadIndexForController(ControllerHandle_t ulControllerHandle);
EXTERN int luasteam_Controller_GetGamepadIndexForController(lua_State *L) {
	ControllerHandle_t ulControllerHandle(luasteam::checkuint64(L, 1));
	int __ret = SteamController()->GetGamepadIndexForController(ulControllerHandle);
	lua_pushinteger(L, __ret);
	return 1;
}

// const char * GetStringForXboxOrigin(EXboxOrigin eOrigin);
EXTERN int luasteam_Controller_GetStringForXboxOrigin(lua_State *L) {
	EXboxOrigin eOrigin = static_cast<EXboxOrigin>(luaL_checkint(L, 1));
	const char * __ret = SteamController()->GetStringForXboxOrigin(eOrigin);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// const char * GetGlyphForXboxOrigin(EXboxOrigin eOrigin);
EXTERN int luasteam_Controller_GetGlyphForXboxOrigin(lua_State *L) {
	EXboxOrigin eOrigin = static_cast<EXboxOrigin>(luaL_checkint(L, 1));
	const char * __ret = SteamController()->GetGlyphForXboxOrigin(eOrigin);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// EControllerActionOrigin GetActionOriginFromXboxOrigin(ControllerHandle_t controllerHandle, EXboxOrigin eOrigin);
EXTERN int luasteam_Controller_GetActionOriginFromXboxOrigin(lua_State *L) {
	ControllerHandle_t controllerHandle(luasteam::checkuint64(L, 1));
	EXboxOrigin eOrigin = static_cast<EXboxOrigin>(luaL_checkint(L, 2));
	EControllerActionOrigin __ret = SteamController()->GetActionOriginFromXboxOrigin(controllerHandle, eOrigin);
	lua_pushinteger(L, __ret);
	return 1;
}

// EControllerActionOrigin TranslateActionOrigin(ESteamInputType eDestinationInputType, EControllerActionOrigin eSourceOrigin);
EXTERN int luasteam_Controller_TranslateActionOrigin(lua_State *L) {
	ESteamInputType eDestinationInputType = static_cast<ESteamInputType>(luaL_checkint(L, 1));
	EControllerActionOrigin eSourceOrigin = static_cast<EControllerActionOrigin>(luaL_checkint(L, 2));
	EControllerActionOrigin __ret = SteamController()->TranslateActionOrigin(eDestinationInputType, eSourceOrigin);
	lua_pushinteger(L, __ret);
	return 1;
}

// bool GetControllerBindingRevision(ControllerHandle_t controllerHandle, int * pMajor, int * pMinor);
EXTERN int luasteam_Controller_GetControllerBindingRevision(lua_State *L) {
	ControllerHandle_t controllerHandle(luasteam::checkuint64(L, 1));
	int pMajor;
	int pMinor;
	bool __ret = SteamController()->GetControllerBindingRevision(controllerHandle, &pMajor, &pMinor);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pMajor);
	lua_pushinteger(L, pMinor);
	return 3;
}

void register_Controller_auto(lua_State *L) {
	add_func(L, "Init", luasteam_Controller_Init);
	add_func(L, "Shutdown", luasteam_Controller_Shutdown);
	add_func(L, "RunFrame", luasteam_Controller_RunFrame);
	add_func(L, "GetConnectedControllers", luasteam_Controller_GetConnectedControllers);
	add_func(L, "GetActionSetHandle", luasteam_Controller_GetActionSetHandle);
	add_func(L, "ActivateActionSet", luasteam_Controller_ActivateActionSet);
	add_func(L, "GetCurrentActionSet", luasteam_Controller_GetCurrentActionSet);
	add_func(L, "ActivateActionSetLayer", luasteam_Controller_ActivateActionSetLayer);
	add_func(L, "DeactivateActionSetLayer", luasteam_Controller_DeactivateActionSetLayer);
	add_func(L, "DeactivateAllActionSetLayers", luasteam_Controller_DeactivateAllActionSetLayers);
	add_func(L, "GetActiveActionSetLayers", luasteam_Controller_GetActiveActionSetLayers);
	add_func(L, "GetDigitalActionHandle", luasteam_Controller_GetDigitalActionHandle);
	add_func(L, "GetDigitalActionData", luasteam_Controller_GetDigitalActionData);
	add_func(L, "GetDigitalActionOrigins", luasteam_Controller_GetDigitalActionOrigins);
	add_func(L, "GetAnalogActionHandle", luasteam_Controller_GetAnalogActionHandle);
	add_func(L, "GetAnalogActionData", luasteam_Controller_GetAnalogActionData);
	add_func(L, "GetAnalogActionOrigins", luasteam_Controller_GetAnalogActionOrigins);
	add_func(L, "GetGlyphForActionOrigin", luasteam_Controller_GetGlyphForActionOrigin);
	add_func(L, "GetStringForActionOrigin", luasteam_Controller_GetStringForActionOrigin);
	add_func(L, "StopAnalogActionMomentum", luasteam_Controller_StopAnalogActionMomentum);
	add_func(L, "GetMotionData", luasteam_Controller_GetMotionData);
	add_func(L, "TriggerHapticPulse", luasteam_Controller_TriggerHapticPulse);
	add_func(L, "TriggerRepeatedHapticPulse", luasteam_Controller_TriggerRepeatedHapticPulse);
	add_func(L, "TriggerVibration", luasteam_Controller_TriggerVibration);
	add_func(L, "SetLEDColor", luasteam_Controller_SetLEDColor);
	add_func(L, "ShowBindingPanel", luasteam_Controller_ShowBindingPanel);
	add_func(L, "GetInputTypeForHandle", luasteam_Controller_GetInputTypeForHandle);
	add_func(L, "GetControllerForGamepadIndex", luasteam_Controller_GetControllerForGamepadIndex);
	add_func(L, "GetGamepadIndexForController", luasteam_Controller_GetGamepadIndexForController);
	add_func(L, "GetStringForXboxOrigin", luasteam_Controller_GetStringForXboxOrigin);
	add_func(L, "GetGlyphForXboxOrigin", luasteam_Controller_GetGlyphForXboxOrigin);
	add_func(L, "GetActionOriginFromXboxOrigin", luasteam_Controller_GetActionOriginFromXboxOrigin);
	add_func(L, "TranslateActionOrigin", luasteam_Controller_TranslateActionOrigin);
	add_func(L, "GetControllerBindingRevision", luasteam_Controller_GetControllerBindingRevision);
}

void add_Controller_auto(lua_State *L) {
	lua_createtable(L, 0, 34);
	register_Controller_auto(L);
	lua_pushvalue(L, -1);
	Controller_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "Controller");
}

} // namespace luasteam
