#include "auto.hpp"

// bool Init(bool bExplicitlyCallRunFrame);
EXTERN int luasteam_input_SteamAPI_ISteamInput_Init(lua_State *L) {
    bool bExplicitlyCallRunFrame = lua_toboolean(L, 1);
    lua_pushboolean(L, SteamInput()->Init(bExplicitlyCallRunFrame));
    return 1;
}

// bool Shutdown();
EXTERN int luasteam_input_SteamAPI_ISteamInput_Shutdown(lua_State *L) {
    lua_pushboolean(L, SteamInput()->Shutdown());
    return 1;
}

// bool SetInputActionManifestFilePath(const char * pchInputActionManifestAbsolutePath);
EXTERN int luasteam_input_SteamAPI_ISteamInput_SetInputActionManifestFilePath(lua_State *L) {
    const char *pchInputActionManifestAbsolutePath = luaL_checkstring(L, 1);
    lua_pushboolean(L, SteamInput()->SetInputActionManifestFilePath(pchInputActionManifestAbsolutePath));
    return 1;
}

// void RunFrame(bool bReservedValue);
EXTERN int luasteam_input_SteamAPI_ISteamInput_RunFrame(lua_State *L) {
    bool bReservedValue = lua_toboolean(L, 1);
    SteamInput()->RunFrame(bReservedValue);
    return 0;
}

// bool BWaitForData(bool bWaitForever, uint32 unTimeout);
EXTERN int luasteam_input_SteamAPI_ISteamInput_BWaitForData(lua_State *L) {
    bool bWaitForever = lua_toboolean(L, 1);
    uint32 unTimeout = luaL_checkint(L, 2);
    lua_pushboolean(L, SteamInput()->BWaitForData(bWaitForever, unTimeout));
    return 1;
}

// bool BNewDataAvailable();
EXTERN int luasteam_input_SteamAPI_ISteamInput_BNewDataAvailable(lua_State *L) {
    lua_pushboolean(L, SteamInput()->BNewDataAvailable());
    return 1;
}

// void EnableDeviceCallbacks();
EXTERN int luasteam_input_SteamAPI_ISteamInput_EnableDeviceCallbacks(lua_State *L) {
    SteamInput()->EnableDeviceCallbacks();
    return 0;
}

// InputActionSetHandle_t GetActionSetHandle(const char * pszActionSetName);
EXTERN int luasteam_input_SteamAPI_ISteamInput_GetActionSetHandle(lua_State *L) {
    const char *pszActionSetName = luaL_checkstring(L, 1);
    luasteam::pushuint64(L, SteamInput()->GetActionSetHandle(pszActionSetName));
    return 1;
}

// void ActivateActionSet(InputHandle_t inputHandle, InputActionSetHandle_t actionSetHandle);
EXTERN int luasteam_input_SteamAPI_ISteamInput_ActivateActionSet(lua_State *L) {
    InputHandle_t inputHandle = luasteam::checkuint64(L, 1);
    InputActionSetHandle_t actionSetHandle = luasteam::checkuint64(L, 2);
    SteamInput()->ActivateActionSet(inputHandle, actionSetHandle);
    return 0;
}

// InputActionSetHandle_t GetCurrentActionSet(InputHandle_t inputHandle);
EXTERN int luasteam_input_SteamAPI_ISteamInput_GetCurrentActionSet(lua_State *L) {
    InputHandle_t inputHandle = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamInput()->GetCurrentActionSet(inputHandle));
    return 1;
}

// void ActivateActionSetLayer(InputHandle_t inputHandle, InputActionSetHandle_t actionSetLayerHandle);
EXTERN int luasteam_input_SteamAPI_ISteamInput_ActivateActionSetLayer(lua_State *L) {
    InputHandle_t inputHandle = luasteam::checkuint64(L, 1);
    InputActionSetHandle_t actionSetLayerHandle = luasteam::checkuint64(L, 2);
    SteamInput()->ActivateActionSetLayer(inputHandle, actionSetLayerHandle);
    return 0;
}

// void DeactivateActionSetLayer(InputHandle_t inputHandle, InputActionSetHandle_t actionSetLayerHandle);
EXTERN int luasteam_input_SteamAPI_ISteamInput_DeactivateActionSetLayer(lua_State *L) {
    InputHandle_t inputHandle = luasteam::checkuint64(L, 1);
    InputActionSetHandle_t actionSetLayerHandle = luasteam::checkuint64(L, 2);
    SteamInput()->DeactivateActionSetLayer(inputHandle, actionSetLayerHandle);
    return 0;
}

// void DeactivateAllActionSetLayers(InputHandle_t inputHandle);
EXTERN int luasteam_input_SteamAPI_ISteamInput_DeactivateAllActionSetLayers(lua_State *L) {
    InputHandle_t inputHandle = luasteam::checkuint64(L, 1);
    SteamInput()->DeactivateAllActionSetLayers(inputHandle);
    return 0;
}

// InputDigitalActionHandle_t GetDigitalActionHandle(const char * pszActionName);
EXTERN int luasteam_input_SteamAPI_ISteamInput_GetDigitalActionHandle(lua_State *L) {
    const char *pszActionName = luaL_checkstring(L, 1);
    luasteam::pushuint64(L, SteamInput()->GetDigitalActionHandle(pszActionName));
    return 1;
}

// const char * GetStringForDigitalActionName(InputDigitalActionHandle_t eActionHandle);
EXTERN int luasteam_input_SteamAPI_ISteamInput_GetStringForDigitalActionName(lua_State *L) {
    InputDigitalActionHandle_t eActionHandle = luasteam::checkuint64(L, 1);
    lua_pushstring(L, SteamInput()->GetStringForDigitalActionName(eActionHandle));
    return 1;
}

// InputAnalogActionHandle_t GetAnalogActionHandle(const char * pszActionName);
EXTERN int luasteam_input_SteamAPI_ISteamInput_GetAnalogActionHandle(lua_State *L) {
    const char *pszActionName = luaL_checkstring(L, 1);
    luasteam::pushuint64(L, SteamInput()->GetAnalogActionHandle(pszActionName));
    return 1;
}

// const char * GetStringForAnalogActionName(InputAnalogActionHandle_t eActionHandle);
EXTERN int luasteam_input_SteamAPI_ISteamInput_GetStringForAnalogActionName(lua_State *L) {
    InputAnalogActionHandle_t eActionHandle = luasteam::checkuint64(L, 1);
    lua_pushstring(L, SteamInput()->GetStringForAnalogActionName(eActionHandle));
    return 1;
}

// void StopAnalogActionMomentum(InputHandle_t inputHandle, InputAnalogActionHandle_t eAction);
EXTERN int luasteam_input_SteamAPI_ISteamInput_StopAnalogActionMomentum(lua_State *L) {
    InputHandle_t inputHandle = luasteam::checkuint64(L, 1);
    InputAnalogActionHandle_t eAction = luasteam::checkuint64(L, 2);
    SteamInput()->StopAnalogActionMomentum(inputHandle, eAction);
    return 0;
}

// void TriggerVibration(InputHandle_t inputHandle, unsigned short usLeftSpeed, unsigned short usRightSpeed);
EXTERN int luasteam_input_SteamAPI_ISteamInput_TriggerVibration(lua_State *L) {
    InputHandle_t inputHandle = luasteam::checkuint64(L, 1);
    unsigned short usLeftSpeed = luaL_checkint(L, 2);
    unsigned short usRightSpeed = luaL_checkint(L, 3);
    SteamInput()->TriggerVibration(inputHandle, usLeftSpeed, usRightSpeed);
    return 0;
}

// void TriggerVibrationExtended(InputHandle_t inputHandle, unsigned short usLeftSpeed, unsigned short usRightSpeed, unsigned short usLeftTriggerSpeed, unsigned short usRightTriggerSpeed);
EXTERN int luasteam_input_SteamAPI_ISteamInput_TriggerVibrationExtended(lua_State *L) {
    InputHandle_t inputHandle = luasteam::checkuint64(L, 1);
    unsigned short usLeftSpeed = luaL_checkint(L, 2);
    unsigned short usRightSpeed = luaL_checkint(L, 3);
    unsigned short usLeftTriggerSpeed = luaL_checkint(L, 4);
    unsigned short usRightTriggerSpeed = luaL_checkint(L, 5);
    SteamInput()->TriggerVibrationExtended(inputHandle, usLeftSpeed, usRightSpeed, usLeftTriggerSpeed, usRightTriggerSpeed);
    return 0;
}

// void SetLEDColor(InputHandle_t inputHandle, uint8 nColorR, uint8 nColorG, uint8 nColorB, unsigned int nFlags);
EXTERN int luasteam_input_SteamAPI_ISteamInput_SetLEDColor(lua_State *L) {
    InputHandle_t inputHandle = luasteam::checkuint64(L, 1);
    uint8 nColorR = luaL_checkint(L, 2);
    uint8 nColorG = luaL_checkint(L, 3);
    uint8 nColorB = luaL_checkint(L, 4);
    unsigned int nFlags = luaL_checkint(L, 5);
    SteamInput()->SetLEDColor(inputHandle, nColorR, nColorG, nColorB, nFlags);
    return 0;
}

// bool ShowBindingPanel(InputHandle_t inputHandle);
EXTERN int luasteam_input_SteamAPI_ISteamInput_ShowBindingPanel(lua_State *L) {
    InputHandle_t inputHandle = luasteam::checkuint64(L, 1);
    lua_pushboolean(L, SteamInput()->ShowBindingPanel(inputHandle));
    return 1;
}

// InputHandle_t GetControllerForGamepadIndex(int nIndex);
EXTERN int luasteam_input_SteamAPI_ISteamInput_GetControllerForGamepadIndex(lua_State *L) {
    int nIndex = luaL_checkint(L, 1);
    luasteam::pushuint64(L, SteamInput()->GetControllerForGamepadIndex(nIndex));
    return 1;
}

// int GetGamepadIndexForController(InputHandle_t ulinputHandle);
EXTERN int luasteam_input_SteamAPI_ISteamInput_GetGamepadIndexForController(lua_State *L) {
    InputHandle_t ulinputHandle = luasteam::checkuint64(L, 1);
    lua_pushinteger(L, SteamInput()->GetGamepadIndexForController(ulinputHandle));
    return 1;
}

// uint32 GetRemotePlaySessionID(InputHandle_t inputHandle);
EXTERN int luasteam_input_SteamAPI_ISteamInput_GetRemotePlaySessionID(lua_State *L) {
    InputHandle_t inputHandle = luasteam::checkuint64(L, 1);
    lua_pushinteger(L, SteamInput()->GetRemotePlaySessionID(inputHandle));
    return 1;
}

// uint16 GetSessionInputConfigurationSettings();
EXTERN int luasteam_input_SteamAPI_ISteamInput_GetSessionInputConfigurationSettings(lua_State *L) {
    lua_pushinteger(L, SteamInput()->GetSessionInputConfigurationSettings());
    return 1;
}

namespace luasteam {

void add_input_auto(lua_State *L) {
    add_func(L, "init", luasteam_input_SteamAPI_ISteamInput_Init);
    add_func(L, "shutdown", luasteam_input_SteamAPI_ISteamInput_Shutdown);
    add_func(L, "setInputActionManifestFilePath", luasteam_input_SteamAPI_ISteamInput_SetInputActionManifestFilePath);
    add_func(L, "runFrame", luasteam_input_SteamAPI_ISteamInput_RunFrame);
    add_func(L, "waitForData", luasteam_input_SteamAPI_ISteamInput_BWaitForData);
    add_func(L, "newDataAvailable", luasteam_input_SteamAPI_ISteamInput_BNewDataAvailable);
    add_func(L, "enableDeviceCallbacks", luasteam_input_SteamAPI_ISteamInput_EnableDeviceCallbacks);
    add_func(L, "getActionSetHandle", luasteam_input_SteamAPI_ISteamInput_GetActionSetHandle);
    add_func(L, "activateActionSet", luasteam_input_SteamAPI_ISteamInput_ActivateActionSet);
    add_func(L, "getCurrentActionSet", luasteam_input_SteamAPI_ISteamInput_GetCurrentActionSet);
    add_func(L, "activateActionSetLayer", luasteam_input_SteamAPI_ISteamInput_ActivateActionSetLayer);
    add_func(L, "deactivateActionSetLayer", luasteam_input_SteamAPI_ISteamInput_DeactivateActionSetLayer);
    add_func(L, "deactivateAllActionSetLayers", luasteam_input_SteamAPI_ISteamInput_DeactivateAllActionSetLayers);
    add_func(L, "getDigitalActionHandle", luasteam_input_SteamAPI_ISteamInput_GetDigitalActionHandle);
    add_func(L, "getStringForDigitalActionName", luasteam_input_SteamAPI_ISteamInput_GetStringForDigitalActionName);
    add_func(L, "getAnalogActionHandle", luasteam_input_SteamAPI_ISteamInput_GetAnalogActionHandle);
    add_func(L, "getStringForAnalogActionName", luasteam_input_SteamAPI_ISteamInput_GetStringForAnalogActionName);
    add_func(L, "stopAnalogActionMomentum", luasteam_input_SteamAPI_ISteamInput_StopAnalogActionMomentum);
    add_func(L, "triggerVibration", luasteam_input_SteamAPI_ISteamInput_TriggerVibration);
    add_func(L, "triggerVibrationExtended", luasteam_input_SteamAPI_ISteamInput_TriggerVibrationExtended);
    add_func(L, "setLEDColor", luasteam_input_SteamAPI_ISteamInput_SetLEDColor);
    add_func(L, "showBindingPanel", luasteam_input_SteamAPI_ISteamInput_ShowBindingPanel);
    add_func(L, "getControllerForGamepadIndex", luasteam_input_SteamAPI_ISteamInput_GetControllerForGamepadIndex);
    add_func(L, "getGamepadIndexForController", luasteam_input_SteamAPI_ISteamInput_GetGamepadIndexForController);
    add_func(L, "getRemotePlaySessionID", luasteam_input_SteamAPI_ISteamInput_GetRemotePlaySessionID);
    add_func(L, "getSessionInputConfigurationSettings", luasteam_input_SteamAPI_ISteamInput_GetSessionInputConfigurationSettings);
}

} // namespace luasteam
