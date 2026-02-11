#include "auto.hpp"

namespace luasteam {

int controller_ref = LUA_NOREF;

void init_controller_auto(lua_State *L) {}

void shutdown_controller_auto(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, controller_ref);
    controller_ref = LUA_NOREF;
}


// bool Init();
EXTERN int luasteam_controller_SteamAPI_ISteamController_Init(lua_State *L) {
    lua_pushboolean(L, SteamController()->Init());
    return 1;
}

// bool Shutdown();
EXTERN int luasteam_controller_SteamAPI_ISteamController_Shutdown(lua_State *L) {
    lua_pushboolean(L, SteamController()->Shutdown());
    return 1;
}

// void RunFrame();
EXTERN int luasteam_controller_SteamAPI_ISteamController_RunFrame(lua_State *L) {
    SteamController()->RunFrame();
    return 0;
}

// ControllerActionSetHandle_t GetActionSetHandle(const char * pszActionSetName);
EXTERN int luasteam_controller_SteamAPI_ISteamController_GetActionSetHandle(lua_State *L) {
    const char *pszActionSetName = luaL_checkstring(L, 1);
    luasteam::pushuint64(L, SteamController()->GetActionSetHandle(pszActionSetName));
    return 1;
}

// void ActivateActionSet(ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetHandle);
EXTERN int luasteam_controller_SteamAPI_ISteamController_ActivateActionSet(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    ControllerActionSetHandle_t actionSetHandle = luasteam::checkuint64(L, 2);
    SteamController()->ActivateActionSet(controllerHandle, actionSetHandle);
    return 0;
}

// ControllerActionSetHandle_t GetCurrentActionSet(ControllerHandle_t controllerHandle);
EXTERN int luasteam_controller_SteamAPI_ISteamController_GetCurrentActionSet(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamController()->GetCurrentActionSet(controllerHandle));
    return 1;
}

// void ActivateActionSetLayer(ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetLayerHandle);
EXTERN int luasteam_controller_SteamAPI_ISteamController_ActivateActionSetLayer(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    ControllerActionSetHandle_t actionSetLayerHandle = luasteam::checkuint64(L, 2);
    SteamController()->ActivateActionSetLayer(controllerHandle, actionSetLayerHandle);
    return 0;
}

// void DeactivateActionSetLayer(ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetLayerHandle);
EXTERN int luasteam_controller_SteamAPI_ISteamController_DeactivateActionSetLayer(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    ControllerActionSetHandle_t actionSetLayerHandle = luasteam::checkuint64(L, 2);
    SteamController()->DeactivateActionSetLayer(controllerHandle, actionSetLayerHandle);
    return 0;
}

// void DeactivateAllActionSetLayers(ControllerHandle_t controllerHandle);
EXTERN int luasteam_controller_SteamAPI_ISteamController_DeactivateAllActionSetLayers(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    SteamController()->DeactivateAllActionSetLayers(controllerHandle);
    return 0;
}

// ControllerDigitalActionHandle_t GetDigitalActionHandle(const char * pszActionName);
EXTERN int luasteam_controller_SteamAPI_ISteamController_GetDigitalActionHandle(lua_State *L) {
    const char *pszActionName = luaL_checkstring(L, 1);
    luasteam::pushuint64(L, SteamController()->GetDigitalActionHandle(pszActionName));
    return 1;
}

// ControllerAnalogActionHandle_t GetAnalogActionHandle(const char * pszActionName);
EXTERN int luasteam_controller_SteamAPI_ISteamController_GetAnalogActionHandle(lua_State *L) {
    const char *pszActionName = luaL_checkstring(L, 1);
    luasteam::pushuint64(L, SteamController()->GetAnalogActionHandle(pszActionName));
    return 1;
}

// const char * GetGlyphForActionOrigin(EControllerActionOrigin eOrigin);
EXTERN int luasteam_controller_SteamAPI_ISteamController_GetGlyphForActionOrigin(lua_State *L) {
    EControllerActionOrigin eOrigin = static_cast<EControllerActionOrigin>(luaL_checkint(L, 1));
    lua_pushstring(L, SteamController()->GetGlyphForActionOrigin(eOrigin));
    return 1;
}

// const char * GetStringForActionOrigin(EControllerActionOrigin eOrigin);
EXTERN int luasteam_controller_SteamAPI_ISteamController_GetStringForActionOrigin(lua_State *L) {
    EControllerActionOrigin eOrigin = static_cast<EControllerActionOrigin>(luaL_checkint(L, 1));
    lua_pushstring(L, SteamController()->GetStringForActionOrigin(eOrigin));
    return 1;
}

// void StopAnalogActionMomentum(ControllerHandle_t controllerHandle, ControllerAnalogActionHandle_t eAction);
EXTERN int luasteam_controller_SteamAPI_ISteamController_StopAnalogActionMomentum(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    ControllerAnalogActionHandle_t eAction = luasteam::checkuint64(L, 2);
    SteamController()->StopAnalogActionMomentum(controllerHandle, eAction);
    return 0;
}

// void TriggerHapticPulse(ControllerHandle_t controllerHandle, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec);
EXTERN int luasteam_controller_SteamAPI_ISteamController_TriggerHapticPulse(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    ESteamControllerPad eTargetPad = static_cast<ESteamControllerPad>(luaL_checkint(L, 2));
    unsigned short usDurationMicroSec = static_cast<unsigned short>(luaL_checkint(L, 3));
    SteamController()->TriggerHapticPulse(controllerHandle, eTargetPad, usDurationMicroSec);
    return 0;
}

// void TriggerRepeatedHapticPulse(ControllerHandle_t controllerHandle, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec, unsigned short usOffMicroSec, unsigned short unRepeat, unsigned int nFlags);
EXTERN int luasteam_controller_SteamAPI_ISteamController_TriggerRepeatedHapticPulse(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    ESteamControllerPad eTargetPad = static_cast<ESteamControllerPad>(luaL_checkint(L, 2));
    unsigned short usDurationMicroSec = static_cast<unsigned short>(luaL_checkint(L, 3));
    unsigned short usOffMicroSec = static_cast<unsigned short>(luaL_checkint(L, 4));
    unsigned short unRepeat = static_cast<unsigned short>(luaL_checkint(L, 5));
    unsigned int nFlags = static_cast<unsigned int>(luaL_checkint(L, 6));
    SteamController()->TriggerRepeatedHapticPulse(controllerHandle, eTargetPad, usDurationMicroSec, usOffMicroSec, unRepeat, nFlags);
    return 0;
}

// void TriggerVibration(ControllerHandle_t controllerHandle, unsigned short usLeftSpeed, unsigned short usRightSpeed);
EXTERN int luasteam_controller_SteamAPI_ISteamController_TriggerVibration(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    unsigned short usLeftSpeed = static_cast<unsigned short>(luaL_checkint(L, 2));
    unsigned short usRightSpeed = static_cast<unsigned short>(luaL_checkint(L, 3));
    SteamController()->TriggerVibration(controllerHandle, usLeftSpeed, usRightSpeed);
    return 0;
}

// void SetLEDColor(ControllerHandle_t controllerHandle, uint8 nColorR, uint8 nColorG, uint8 nColorB, unsigned int nFlags);
EXTERN int luasteam_controller_SteamAPI_ISteamController_SetLEDColor(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    uint8 nColorR = static_cast<uint8>(luaL_checkint(L, 2));
    uint8 nColorG = static_cast<uint8>(luaL_checkint(L, 3));
    uint8 nColorB = static_cast<uint8>(luaL_checkint(L, 4));
    unsigned int nFlags = static_cast<unsigned int>(luaL_checkint(L, 5));
    SteamController()->SetLEDColor(controllerHandle, nColorR, nColorG, nColorB, nFlags);
    return 0;
}

// bool ShowBindingPanel(ControllerHandle_t controllerHandle);
EXTERN int luasteam_controller_SteamAPI_ISteamController_ShowBindingPanel(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    lua_pushboolean(L, SteamController()->ShowBindingPanel(controllerHandle));
    return 1;
}

// ESteamInputType GetInputTypeForHandle(ControllerHandle_t controllerHandle);
EXTERN int luasteam_controller_SteamAPI_ISteamController_GetInputTypeForHandle(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    lua_pushinteger(L, SteamController()->GetInputTypeForHandle(controllerHandle));
    return 1;
}

// ControllerHandle_t GetControllerForGamepadIndex(int nIndex);
EXTERN int luasteam_controller_SteamAPI_ISteamController_GetControllerForGamepadIndex(lua_State *L) {
    int nIndex = static_cast<int>(luaL_checkint(L, 1));
    luasteam::pushuint64(L, SteamController()->GetControllerForGamepadIndex(nIndex));
    return 1;
}

// int GetGamepadIndexForController(ControllerHandle_t ulControllerHandle);
EXTERN int luasteam_controller_SteamAPI_ISteamController_GetGamepadIndexForController(lua_State *L) {
    ControllerHandle_t ulControllerHandle = luasteam::checkuint64(L, 1);
    lua_pushinteger(L, SteamController()->GetGamepadIndexForController(ulControllerHandle));
    return 1;
}

// const char * GetStringForXboxOrigin(EXboxOrigin eOrigin);
EXTERN int luasteam_controller_SteamAPI_ISteamController_GetStringForXboxOrigin(lua_State *L) {
    EXboxOrigin eOrigin = static_cast<EXboxOrigin>(luaL_checkint(L, 1));
    lua_pushstring(L, SteamController()->GetStringForXboxOrigin(eOrigin));
    return 1;
}

// const char * GetGlyphForXboxOrigin(EXboxOrigin eOrigin);
EXTERN int luasteam_controller_SteamAPI_ISteamController_GetGlyphForXboxOrigin(lua_State *L) {
    EXboxOrigin eOrigin = static_cast<EXboxOrigin>(luaL_checkint(L, 1));
    lua_pushstring(L, SteamController()->GetGlyphForXboxOrigin(eOrigin));
    return 1;
}

// EControllerActionOrigin GetActionOriginFromXboxOrigin(ControllerHandle_t controllerHandle, EXboxOrigin eOrigin);
EXTERN int luasteam_controller_SteamAPI_ISteamController_GetActionOriginFromXboxOrigin(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    EXboxOrigin eOrigin = static_cast<EXboxOrigin>(luaL_checkint(L, 2));
    lua_pushinteger(L, SteamController()->GetActionOriginFromXboxOrigin(controllerHandle, eOrigin));
    return 1;
}

// EControllerActionOrigin TranslateActionOrigin(ESteamInputType eDestinationInputType, EControllerActionOrigin eSourceOrigin);
EXTERN int luasteam_controller_SteamAPI_ISteamController_TranslateActionOrigin(lua_State *L) {
    ESteamInputType eDestinationInputType = static_cast<ESteamInputType>(luaL_checkint(L, 1));
    EControllerActionOrigin eSourceOrigin = static_cast<EControllerActionOrigin>(luaL_checkint(L, 2));
    lua_pushinteger(L, SteamController()->TranslateActionOrigin(eDestinationInputType, eSourceOrigin));
    return 1;
}

void register_controller_auto(lua_State *L) {
    add_func(L, "init", luasteam_controller_SteamAPI_ISteamController_Init);
    add_func(L, "shutdown", luasteam_controller_SteamAPI_ISteamController_Shutdown);
    add_func(L, "runFrame", luasteam_controller_SteamAPI_ISteamController_RunFrame);
    add_func(L, "getActionSetHandle", luasteam_controller_SteamAPI_ISteamController_GetActionSetHandle);
    add_func(L, "activateActionSet", luasteam_controller_SteamAPI_ISteamController_ActivateActionSet);
    add_func(L, "getCurrentActionSet", luasteam_controller_SteamAPI_ISteamController_GetCurrentActionSet);
    add_func(L, "activateActionSetLayer", luasteam_controller_SteamAPI_ISteamController_ActivateActionSetLayer);
    add_func(L, "deactivateActionSetLayer", luasteam_controller_SteamAPI_ISteamController_DeactivateActionSetLayer);
    add_func(L, "deactivateAllActionSetLayers", luasteam_controller_SteamAPI_ISteamController_DeactivateAllActionSetLayers);
    add_func(L, "getDigitalActionHandle", luasteam_controller_SteamAPI_ISteamController_GetDigitalActionHandle);
    add_func(L, "getAnalogActionHandle", luasteam_controller_SteamAPI_ISteamController_GetAnalogActionHandle);
    add_func(L, "getGlyphForActionOrigin", luasteam_controller_SteamAPI_ISteamController_GetGlyphForActionOrigin);
    add_func(L, "getStringForActionOrigin", luasteam_controller_SteamAPI_ISteamController_GetStringForActionOrigin);
    add_func(L, "stopAnalogActionMomentum", luasteam_controller_SteamAPI_ISteamController_StopAnalogActionMomentum);
    add_func(L, "triggerHapticPulse", luasteam_controller_SteamAPI_ISteamController_TriggerHapticPulse);
    add_func(L, "triggerRepeatedHapticPulse", luasteam_controller_SteamAPI_ISteamController_TriggerRepeatedHapticPulse);
    add_func(L, "triggerVibration", luasteam_controller_SteamAPI_ISteamController_TriggerVibration);
    add_func(L, "setLEDColor", luasteam_controller_SteamAPI_ISteamController_SetLEDColor);
    add_func(L, "showBindingPanel", luasteam_controller_SteamAPI_ISteamController_ShowBindingPanel);
    add_func(L, "getInputTypeForHandle", luasteam_controller_SteamAPI_ISteamController_GetInputTypeForHandle);
    add_func(L, "getControllerForGamepadIndex", luasteam_controller_SteamAPI_ISteamController_GetControllerForGamepadIndex);
    add_func(L, "getGamepadIndexForController", luasteam_controller_SteamAPI_ISteamController_GetGamepadIndexForController);
    add_func(L, "getStringForXboxOrigin", luasteam_controller_SteamAPI_ISteamController_GetStringForXboxOrigin);
    add_func(L, "getGlyphForXboxOrigin", luasteam_controller_SteamAPI_ISteamController_GetGlyphForXboxOrigin);
    add_func(L, "getActionOriginFromXboxOrigin", luasteam_controller_SteamAPI_ISteamController_GetActionOriginFromXboxOrigin);
    add_func(L, "translateActionOrigin", luasteam_controller_SteamAPI_ISteamController_TranslateActionOrigin);
}

void add_controller_auto(lua_State *L) {
    lua_createtable(L, 0, 26);
    register_controller_auto(L);
    lua_pushvalue(L, -1);
    controller_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "controller");
}

} // namespace luasteam
