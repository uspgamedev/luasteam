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
    uint32 unTimeout = static_cast<uint32>(luaL_checkint(L, 2));
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

// const char * GetGlyphPNGForActionOrigin(EInputActionOrigin eOrigin, ESteamInputGlyphSize eSize, uint32 unFlags);
EXTERN int luasteam_input_SteamAPI_ISteamInput_GetGlyphPNGForActionOrigin(lua_State *L) {
    EInputActionOrigin eOrigin = static_cast<EInputActionOrigin>(luaL_checkint(L, 1));
    ESteamInputGlyphSize eSize = static_cast<ESteamInputGlyphSize>(luaL_checkint(L, 2));
    uint32 unFlags = static_cast<uint32>(luaL_checkint(L, 3));
    lua_pushstring(L, SteamInput()->GetGlyphPNGForActionOrigin(eOrigin, eSize, unFlags));
    return 1;
}

// const char * GetGlyphSVGForActionOrigin(EInputActionOrigin eOrigin, uint32 unFlags);
EXTERN int luasteam_input_SteamAPI_ISteamInput_GetGlyphSVGForActionOrigin(lua_State *L) {
    EInputActionOrigin eOrigin = static_cast<EInputActionOrigin>(luaL_checkint(L, 1));
    uint32 unFlags = static_cast<uint32>(luaL_checkint(L, 2));
    lua_pushstring(L, SteamInput()->GetGlyphSVGForActionOrigin(eOrigin, unFlags));
    return 1;
}

// const char * GetGlyphForActionOrigin_Legacy(EInputActionOrigin eOrigin);
EXTERN int luasteam_input_SteamAPI_ISteamInput_GetGlyphForActionOrigin_Legacy(lua_State *L) {
    EInputActionOrigin eOrigin = static_cast<EInputActionOrigin>(luaL_checkint(L, 1));
    lua_pushstring(L, SteamInput()->GetGlyphForActionOrigin_Legacy(eOrigin));
    return 1;
}

// const char * GetStringForActionOrigin(EInputActionOrigin eOrigin);
EXTERN int luasteam_input_SteamAPI_ISteamInput_GetStringForActionOrigin(lua_State *L) {
    EInputActionOrigin eOrigin = static_cast<EInputActionOrigin>(luaL_checkint(L, 1));
    lua_pushstring(L, SteamInput()->GetStringForActionOrigin(eOrigin));
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
    unsigned short usLeftSpeed = static_cast<unsigned short>(luaL_checkint(L, 2));
    unsigned short usRightSpeed = static_cast<unsigned short>(luaL_checkint(L, 3));
    SteamInput()->TriggerVibration(inputHandle, usLeftSpeed, usRightSpeed);
    return 0;
}

// void TriggerVibrationExtended(InputHandle_t inputHandle, unsigned short usLeftSpeed, unsigned short usRightSpeed, unsigned short usLeftTriggerSpeed, unsigned short usRightTriggerSpeed);
EXTERN int luasteam_input_SteamAPI_ISteamInput_TriggerVibrationExtended(lua_State *L) {
    InputHandle_t inputHandle = luasteam::checkuint64(L, 1);
    unsigned short usLeftSpeed = static_cast<unsigned short>(luaL_checkint(L, 2));
    unsigned short usRightSpeed = static_cast<unsigned short>(luaL_checkint(L, 3));
    unsigned short usLeftTriggerSpeed = static_cast<unsigned short>(luaL_checkint(L, 4));
    unsigned short usRightTriggerSpeed = static_cast<unsigned short>(luaL_checkint(L, 5));
    SteamInput()->TriggerVibrationExtended(inputHandle, usLeftSpeed, usRightSpeed, usLeftTriggerSpeed, usRightTriggerSpeed);
    return 0;
}

// void SetLEDColor(InputHandle_t inputHandle, uint8 nColorR, uint8 nColorG, uint8 nColorB, unsigned int nFlags);
EXTERN int luasteam_input_SteamAPI_ISteamInput_SetLEDColor(lua_State *L) {
    InputHandle_t inputHandle = luasteam::checkuint64(L, 1);
    uint8 nColorR = static_cast<uint8>(luaL_checkint(L, 2));
    uint8 nColorG = static_cast<uint8>(luaL_checkint(L, 3));
    uint8 nColorB = static_cast<uint8>(luaL_checkint(L, 4));
    unsigned int nFlags = static_cast<unsigned int>(luaL_checkint(L, 5));
    SteamInput()->SetLEDColor(inputHandle, nColorR, nColorG, nColorB, nFlags);
    return 0;
}

// void Legacy_TriggerHapticPulse(InputHandle_t inputHandle, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec);
EXTERN int luasteam_input_SteamAPI_ISteamInput_Legacy_TriggerHapticPulse(lua_State *L) {
    InputHandle_t inputHandle = luasteam::checkuint64(L, 1);
    ESteamControllerPad eTargetPad = static_cast<ESteamControllerPad>(luaL_checkint(L, 2));
    unsigned short usDurationMicroSec = static_cast<unsigned short>(luaL_checkint(L, 3));
    SteamInput()->Legacy_TriggerHapticPulse(inputHandle, eTargetPad, usDurationMicroSec);
    return 0;
}

// void Legacy_TriggerRepeatedHapticPulse(InputHandle_t inputHandle, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec, unsigned short usOffMicroSec, unsigned short unRepeat, unsigned int nFlags);
EXTERN int luasteam_input_SteamAPI_ISteamInput_Legacy_TriggerRepeatedHapticPulse(lua_State *L) {
    InputHandle_t inputHandle = luasteam::checkuint64(L, 1);
    ESteamControllerPad eTargetPad = static_cast<ESteamControllerPad>(luaL_checkint(L, 2));
    unsigned short usDurationMicroSec = static_cast<unsigned short>(luaL_checkint(L, 3));
    unsigned short usOffMicroSec = static_cast<unsigned short>(luaL_checkint(L, 4));
    unsigned short unRepeat = static_cast<unsigned short>(luaL_checkint(L, 5));
    unsigned int nFlags = static_cast<unsigned int>(luaL_checkint(L, 6));
    SteamInput()->Legacy_TriggerRepeatedHapticPulse(inputHandle, eTargetPad, usDurationMicroSec, usOffMicroSec, unRepeat, nFlags);
    return 0;
}

// bool ShowBindingPanel(InputHandle_t inputHandle);
EXTERN int luasteam_input_SteamAPI_ISteamInput_ShowBindingPanel(lua_State *L) {
    InputHandle_t inputHandle = luasteam::checkuint64(L, 1);
    lua_pushboolean(L, SteamInput()->ShowBindingPanel(inputHandle));
    return 1;
}

// ESteamInputType GetInputTypeForHandle(InputHandle_t inputHandle);
EXTERN int luasteam_input_SteamAPI_ISteamInput_GetInputTypeForHandle(lua_State *L) {
    InputHandle_t inputHandle = luasteam::checkuint64(L, 1);
    lua_pushinteger(L, SteamInput()->GetInputTypeForHandle(inputHandle));
    return 1;
}

// InputHandle_t GetControllerForGamepadIndex(int nIndex);
EXTERN int luasteam_input_SteamAPI_ISteamInput_GetControllerForGamepadIndex(lua_State *L) {
    int nIndex = static_cast<int>(luaL_checkint(L, 1));
    luasteam::pushuint64(L, SteamInput()->GetControllerForGamepadIndex(nIndex));
    return 1;
}

// int GetGamepadIndexForController(InputHandle_t ulinputHandle);
EXTERN int luasteam_input_SteamAPI_ISteamInput_GetGamepadIndexForController(lua_State *L) {
    InputHandle_t ulinputHandle = luasteam::checkuint64(L, 1);
    lua_pushinteger(L, SteamInput()->GetGamepadIndexForController(ulinputHandle));
    return 1;
}

// const char * GetStringForXboxOrigin(EXboxOrigin eOrigin);
EXTERN int luasteam_input_SteamAPI_ISteamInput_GetStringForXboxOrigin(lua_State *L) {
    EXboxOrigin eOrigin = static_cast<EXboxOrigin>(luaL_checkint(L, 1));
    lua_pushstring(L, SteamInput()->GetStringForXboxOrigin(eOrigin));
    return 1;
}

// const char * GetGlyphForXboxOrigin(EXboxOrigin eOrigin);
EXTERN int luasteam_input_SteamAPI_ISteamInput_GetGlyphForXboxOrigin(lua_State *L) {
    EXboxOrigin eOrigin = static_cast<EXboxOrigin>(luaL_checkint(L, 1));
    lua_pushstring(L, SteamInput()->GetGlyphForXboxOrigin(eOrigin));
    return 1;
}

// EInputActionOrigin GetActionOriginFromXboxOrigin(InputHandle_t inputHandle, EXboxOrigin eOrigin);
EXTERN int luasteam_input_SteamAPI_ISteamInput_GetActionOriginFromXboxOrigin(lua_State *L) {
    InputHandle_t inputHandle = luasteam::checkuint64(L, 1);
    EXboxOrigin eOrigin = static_cast<EXboxOrigin>(luaL_checkint(L, 2));
    lua_pushinteger(L, SteamInput()->GetActionOriginFromXboxOrigin(inputHandle, eOrigin));
    return 1;
}

// EInputActionOrigin TranslateActionOrigin(ESteamInputType eDestinationInputType, EInputActionOrigin eSourceOrigin);
EXTERN int luasteam_input_SteamAPI_ISteamInput_TranslateActionOrigin(lua_State *L) {
    ESteamInputType eDestinationInputType = static_cast<ESteamInputType>(luaL_checkint(L, 1));
    EInputActionOrigin eSourceOrigin = static_cast<EInputActionOrigin>(luaL_checkint(L, 2));
    lua_pushinteger(L, SteamInput()->TranslateActionOrigin(eDestinationInputType, eSourceOrigin));
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
    add_func(L, "getGlyphPNGForActionOrigin", luasteam_input_SteamAPI_ISteamInput_GetGlyphPNGForActionOrigin);
    add_func(L, "getGlyphSVGForActionOrigin", luasteam_input_SteamAPI_ISteamInput_GetGlyphSVGForActionOrigin);
    add_func(L, "getGlyphForActionOrigin_Legacy", luasteam_input_SteamAPI_ISteamInput_GetGlyphForActionOrigin_Legacy);
    add_func(L, "getStringForActionOrigin", luasteam_input_SteamAPI_ISteamInput_GetStringForActionOrigin);
    add_func(L, "getStringForAnalogActionName", luasteam_input_SteamAPI_ISteamInput_GetStringForAnalogActionName);
    add_func(L, "stopAnalogActionMomentum", luasteam_input_SteamAPI_ISteamInput_StopAnalogActionMomentum);
    add_func(L, "triggerVibration", luasteam_input_SteamAPI_ISteamInput_TriggerVibration);
    add_func(L, "triggerVibrationExtended", luasteam_input_SteamAPI_ISteamInput_TriggerVibrationExtended);
    add_func(L, "setLEDColor", luasteam_input_SteamAPI_ISteamInput_SetLEDColor);
    add_func(L, "legacy_TriggerHapticPulse", luasteam_input_SteamAPI_ISteamInput_Legacy_TriggerHapticPulse);
    add_func(L, "legacy_TriggerRepeatedHapticPulse", luasteam_input_SteamAPI_ISteamInput_Legacy_TriggerRepeatedHapticPulse);
    add_func(L, "showBindingPanel", luasteam_input_SteamAPI_ISteamInput_ShowBindingPanel);
    add_func(L, "getInputTypeForHandle", luasteam_input_SteamAPI_ISteamInput_GetInputTypeForHandle);
    add_func(L, "getControllerForGamepadIndex", luasteam_input_SteamAPI_ISteamInput_GetControllerForGamepadIndex);
    add_func(L, "getGamepadIndexForController", luasteam_input_SteamAPI_ISteamInput_GetGamepadIndexForController);
    add_func(L, "getStringForXboxOrigin", luasteam_input_SteamAPI_ISteamInput_GetStringForXboxOrigin);
    add_func(L, "getGlyphForXboxOrigin", luasteam_input_SteamAPI_ISteamInput_GetGlyphForXboxOrigin);
    add_func(L, "getActionOriginFromXboxOrigin", luasteam_input_SteamAPI_ISteamInput_GetActionOriginFromXboxOrigin);
    add_func(L, "translateActionOrigin", luasteam_input_SteamAPI_ISteamInput_TranslateActionOrigin);
    add_func(L, "getRemotePlaySessionID", luasteam_input_SteamAPI_ISteamInput_GetRemotePlaySessionID);
    add_func(L, "getSessionInputConfigurationSettings", luasteam_input_SteamAPI_ISteamInput_GetSessionInputConfigurationSettings);
}

} // namespace luasteam
