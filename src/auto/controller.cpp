#include "auto.hpp"

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

// void StopAnalogActionMomentum(ControllerHandle_t controllerHandle, ControllerAnalogActionHandle_t eAction);
EXTERN int luasteam_controller_SteamAPI_ISteamController_StopAnalogActionMomentum(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    ControllerAnalogActionHandle_t eAction = luasteam::checkuint64(L, 2);
    SteamController()->StopAnalogActionMomentum(controllerHandle, eAction);
    return 0;
}

// void TriggerVibration(ControllerHandle_t controllerHandle, unsigned short usLeftSpeed, unsigned short usRightSpeed);
EXTERN int luasteam_controller_SteamAPI_ISteamController_TriggerVibration(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    unsigned short usLeftSpeed = luaL_checkint(L, 2);
    unsigned short usRightSpeed = luaL_checkint(L, 3);
    SteamController()->TriggerVibration(controllerHandle, usLeftSpeed, usRightSpeed);
    return 0;
}

// void SetLEDColor(ControllerHandle_t controllerHandle, uint8 nColorR, uint8 nColorG, uint8 nColorB, unsigned int nFlags);
EXTERN int luasteam_controller_SteamAPI_ISteamController_SetLEDColor(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    uint8 nColorR = luaL_checkint(L, 2);
    uint8 nColorG = luaL_checkint(L, 3);
    uint8 nColorB = luaL_checkint(L, 4);
    unsigned int nFlags = luaL_checkint(L, 5);
    SteamController()->SetLEDColor(controllerHandle, nColorR, nColorG, nColorB, nFlags);
    return 0;
}

// bool ShowBindingPanel(ControllerHandle_t controllerHandle);
EXTERN int luasteam_controller_SteamAPI_ISteamController_ShowBindingPanel(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    lua_pushboolean(L, SteamController()->ShowBindingPanel(controllerHandle));
    return 1;
}

// ControllerHandle_t GetControllerForGamepadIndex(int nIndex);
EXTERN int luasteam_controller_SteamAPI_ISteamController_GetControllerForGamepadIndex(lua_State *L) {
    int nIndex = luaL_checkint(L, 1);
    luasteam::pushuint64(L, SteamController()->GetControllerForGamepadIndex(nIndex));
    return 1;
}

// int GetGamepadIndexForController(ControllerHandle_t ulControllerHandle);
EXTERN int luasteam_controller_SteamAPI_ISteamController_GetGamepadIndexForController(lua_State *L) {
    ControllerHandle_t ulControllerHandle = luasteam::checkuint64(L, 1);
    lua_pushinteger(L, SteamController()->GetGamepadIndexForController(ulControllerHandle));
    return 1;
}

namespace luasteam {

void add_controller_auto(lua_State *L) {
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
    add_func(L, "stopAnalogActionMomentum", luasteam_controller_SteamAPI_ISteamController_StopAnalogActionMomentum);
    add_func(L, "triggerVibration", luasteam_controller_SteamAPI_ISteamController_TriggerVibration);
    add_func(L, "setLEDColor", luasteam_controller_SteamAPI_ISteamController_SetLEDColor);
    add_func(L, "showBindingPanel", luasteam_controller_SteamAPI_ISteamController_ShowBindingPanel);
    add_func(L, "getControllerForGamepadIndex", luasteam_controller_SteamAPI_ISteamController_GetControllerForGamepadIndex);
    add_func(L, "getGamepadIndexForController", luasteam_controller_SteamAPI_ISteamController_GetGamepadIndexForController);
}

} // namespace luasteam
