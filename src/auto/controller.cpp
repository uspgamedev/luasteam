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
    lua_pushboolean(L, SteamController()->Init());
    return 1;
}

// bool Shutdown();
EXTERN int luasteam_Controller_Shutdown(lua_State *L) {
    lua_pushboolean(L, SteamController()->Shutdown());
    return 1;
}

// void RunFrame();
EXTERN int luasteam_Controller_RunFrame(lua_State *L) {
    SteamController()->RunFrame();
    return 0;
}

// int GetConnectedControllers(ControllerHandle_t * handlesOut);
EXTERN int luasteam_Controller_GetConnectedControllers(lua_State *L) {
    ControllerHandle_t handlesOut;    lua_pushinteger(L, SteamController()->GetConnectedControllers(&handlesOut));
    luasteam::pushuint64(L, handlesOut);
    return 2;
}

// ControllerActionSetHandle_t GetActionSetHandle(const char * pszActionSetName);
EXTERN int luasteam_Controller_GetActionSetHandle(lua_State *L) {
    const char *pszActionSetName = luaL_checkstring(L, 1);
    luasteam::pushuint64(L, SteamController()->GetActionSetHandle(pszActionSetName));
    return 1;
}

// void ActivateActionSet(ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetHandle);
EXTERN int luasteam_Controller_ActivateActionSet(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    ControllerActionSetHandle_t actionSetHandle = luasteam::checkuint64(L, 2);
    SteamController()->ActivateActionSet(controllerHandle, actionSetHandle);
    return 0;
}

// ControllerActionSetHandle_t GetCurrentActionSet(ControllerHandle_t controllerHandle);
EXTERN int luasteam_Controller_GetCurrentActionSet(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamController()->GetCurrentActionSet(controllerHandle));
    return 1;
}

// void ActivateActionSetLayer(ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetLayerHandle);
EXTERN int luasteam_Controller_ActivateActionSetLayer(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    ControllerActionSetHandle_t actionSetLayerHandle = luasteam::checkuint64(L, 2);
    SteamController()->ActivateActionSetLayer(controllerHandle, actionSetLayerHandle);
    return 0;
}

// void DeactivateActionSetLayer(ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetLayerHandle);
EXTERN int luasteam_Controller_DeactivateActionSetLayer(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    ControllerActionSetHandle_t actionSetLayerHandle = luasteam::checkuint64(L, 2);
    SteamController()->DeactivateActionSetLayer(controllerHandle, actionSetLayerHandle);
    return 0;
}

// void DeactivateAllActionSetLayers(ControllerHandle_t controllerHandle);
EXTERN int luasteam_Controller_DeactivateAllActionSetLayers(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    SteamController()->DeactivateAllActionSetLayers(controllerHandle);
    return 0;
}

// int GetActiveActionSetLayers(ControllerHandle_t controllerHandle, ControllerActionSetHandle_t * handlesOut);
EXTERN int luasteam_Controller_GetActiveActionSetLayers(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    ControllerActionSetHandle_t handlesOut;    lua_pushinteger(L, SteamController()->GetActiveActionSetLayers(controllerHandle, &handlesOut));
    luasteam::pushuint64(L, handlesOut);
    return 2;
}

// ControllerDigitalActionHandle_t GetDigitalActionHandle(const char * pszActionName);
EXTERN int luasteam_Controller_GetDigitalActionHandle(lua_State *L) {
    const char *pszActionName = luaL_checkstring(L, 1);
    luasteam::pushuint64(L, SteamController()->GetDigitalActionHandle(pszActionName));
    return 1;
}

// int GetDigitalActionOrigins(ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetHandle, ControllerDigitalActionHandle_t digitalActionHandle, EControllerActionOrigin * originsOut);
EXTERN int luasteam_Controller_GetDigitalActionOrigins(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    ControllerActionSetHandle_t actionSetHandle = luasteam::checkuint64(L, 2);
    ControllerDigitalActionHandle_t digitalActionHandle = luasteam::checkuint64(L, 3);
    EControllerActionOrigin originsOut;    lua_pushinteger(L, SteamController()->GetDigitalActionOrigins(controllerHandle, actionSetHandle, digitalActionHandle, &originsOut));
    lua_pushinteger(L, originsOut);
    return 2;
}

// ControllerAnalogActionHandle_t GetAnalogActionHandle(const char * pszActionName);
EXTERN int luasteam_Controller_GetAnalogActionHandle(lua_State *L) {
    const char *pszActionName = luaL_checkstring(L, 1);
    luasteam::pushuint64(L, SteamController()->GetAnalogActionHandle(pszActionName));
    return 1;
}

// int GetAnalogActionOrigins(ControllerHandle_t controllerHandle, ControllerActionSetHandle_t actionSetHandle, ControllerAnalogActionHandle_t analogActionHandle, EControllerActionOrigin * originsOut);
EXTERN int luasteam_Controller_GetAnalogActionOrigins(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    ControllerActionSetHandle_t actionSetHandle = luasteam::checkuint64(L, 2);
    ControllerAnalogActionHandle_t analogActionHandle = luasteam::checkuint64(L, 3);
    EControllerActionOrigin originsOut;    lua_pushinteger(L, SteamController()->GetAnalogActionOrigins(controllerHandle, actionSetHandle, analogActionHandle, &originsOut));
    lua_pushinteger(L, originsOut);
    return 2;
}

// const char * GetGlyphForActionOrigin(EControllerActionOrigin eOrigin);
EXTERN int luasteam_Controller_GetGlyphForActionOrigin(lua_State *L) {
    EControllerActionOrigin eOrigin = static_cast<EControllerActionOrigin>(luaL_checkint(L, 1));
    lua_pushstring(L, SteamController()->GetGlyphForActionOrigin(eOrigin));
    return 1;
}

// const char * GetStringForActionOrigin(EControllerActionOrigin eOrigin);
EXTERN int luasteam_Controller_GetStringForActionOrigin(lua_State *L) {
    EControllerActionOrigin eOrigin = static_cast<EControllerActionOrigin>(luaL_checkint(L, 1));
    lua_pushstring(L, SteamController()->GetStringForActionOrigin(eOrigin));
    return 1;
}

// void StopAnalogActionMomentum(ControllerHandle_t controllerHandle, ControllerAnalogActionHandle_t eAction);
EXTERN int luasteam_Controller_StopAnalogActionMomentum(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    ControllerAnalogActionHandle_t eAction = luasteam::checkuint64(L, 2);
    SteamController()->StopAnalogActionMomentum(controllerHandle, eAction);
    return 0;
}

// void TriggerHapticPulse(ControllerHandle_t controllerHandle, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec);
EXTERN int luasteam_Controller_TriggerHapticPulse(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    ESteamControllerPad eTargetPad = static_cast<ESteamControllerPad>(luaL_checkint(L, 2));
    unsigned short usDurationMicroSec = static_cast<unsigned short>(luaL_checkint(L, 3));
    SteamController()->TriggerHapticPulse(controllerHandle, eTargetPad, usDurationMicroSec);
    return 0;
}

// void TriggerRepeatedHapticPulse(ControllerHandle_t controllerHandle, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec, unsigned short usOffMicroSec, unsigned short unRepeat, unsigned int nFlags);
EXTERN int luasteam_Controller_TriggerRepeatedHapticPulse(lua_State *L) {
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
EXTERN int luasteam_Controller_TriggerVibration(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    unsigned short usLeftSpeed = static_cast<unsigned short>(luaL_checkint(L, 2));
    unsigned short usRightSpeed = static_cast<unsigned short>(luaL_checkint(L, 3));
    SteamController()->TriggerVibration(controllerHandle, usLeftSpeed, usRightSpeed);
    return 0;
}

// void SetLEDColor(ControllerHandle_t controllerHandle, uint8 nColorR, uint8 nColorG, uint8 nColorB, unsigned int nFlags);
EXTERN int luasteam_Controller_SetLEDColor(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    uint8 nColorR = static_cast<uint8>(luaL_checkint(L, 2));
    uint8 nColorG = static_cast<uint8>(luaL_checkint(L, 3));
    uint8 nColorB = static_cast<uint8>(luaL_checkint(L, 4));
    unsigned int nFlags = static_cast<unsigned int>(luaL_checkint(L, 5));
    SteamController()->SetLEDColor(controllerHandle, nColorR, nColorG, nColorB, nFlags);
    return 0;
}

// bool ShowBindingPanel(ControllerHandle_t controllerHandle);
EXTERN int luasteam_Controller_ShowBindingPanel(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    lua_pushboolean(L, SteamController()->ShowBindingPanel(controllerHandle));
    return 1;
}

// ESteamInputType GetInputTypeForHandle(ControllerHandle_t controllerHandle);
EXTERN int luasteam_Controller_GetInputTypeForHandle(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    lua_pushinteger(L, SteamController()->GetInputTypeForHandle(controllerHandle));
    return 1;
}

// ControllerHandle_t GetControllerForGamepadIndex(int nIndex);
EXTERN int luasteam_Controller_GetControllerForGamepadIndex(lua_State *L) {
    int nIndex = static_cast<int>(luaL_checkint(L, 1));
    luasteam::pushuint64(L, SteamController()->GetControllerForGamepadIndex(nIndex));
    return 1;
}

// int GetGamepadIndexForController(ControllerHandle_t ulControllerHandle);
EXTERN int luasteam_Controller_GetGamepadIndexForController(lua_State *L) {
    ControllerHandle_t ulControllerHandle = luasteam::checkuint64(L, 1);
    lua_pushinteger(L, SteamController()->GetGamepadIndexForController(ulControllerHandle));
    return 1;
}

// const char * GetStringForXboxOrigin(EXboxOrigin eOrigin);
EXTERN int luasteam_Controller_GetStringForXboxOrigin(lua_State *L) {
    EXboxOrigin eOrigin = static_cast<EXboxOrigin>(luaL_checkint(L, 1));
    lua_pushstring(L, SteamController()->GetStringForXboxOrigin(eOrigin));
    return 1;
}

// const char * GetGlyphForXboxOrigin(EXboxOrigin eOrigin);
EXTERN int luasteam_Controller_GetGlyphForXboxOrigin(lua_State *L) {
    EXboxOrigin eOrigin = static_cast<EXboxOrigin>(luaL_checkint(L, 1));
    lua_pushstring(L, SteamController()->GetGlyphForXboxOrigin(eOrigin));
    return 1;
}

// EControllerActionOrigin GetActionOriginFromXboxOrigin(ControllerHandle_t controllerHandle, EXboxOrigin eOrigin);
EXTERN int luasteam_Controller_GetActionOriginFromXboxOrigin(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    EXboxOrigin eOrigin = static_cast<EXboxOrigin>(luaL_checkint(L, 2));
    lua_pushinteger(L, SteamController()->GetActionOriginFromXboxOrigin(controllerHandle, eOrigin));
    return 1;
}

// EControllerActionOrigin TranslateActionOrigin(ESteamInputType eDestinationInputType, EControllerActionOrigin eSourceOrigin);
EXTERN int luasteam_Controller_TranslateActionOrigin(lua_State *L) {
    ESteamInputType eDestinationInputType = static_cast<ESteamInputType>(luaL_checkint(L, 1));
    EControllerActionOrigin eSourceOrigin = static_cast<EControllerActionOrigin>(luaL_checkint(L, 2));
    lua_pushinteger(L, SteamController()->TranslateActionOrigin(eDestinationInputType, eSourceOrigin));
    return 1;
}

// bool GetControllerBindingRevision(ControllerHandle_t controllerHandle, int * pMajor, int * pMinor);
EXTERN int luasteam_Controller_GetControllerBindingRevision(lua_State *L) {
    ControllerHandle_t controllerHandle = luasteam::checkuint64(L, 1);
    int pMajor;    int pMinor;    lua_pushboolean(L, SteamController()->GetControllerBindingRevision(controllerHandle, &pMajor, &pMinor));
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
    add_func(L, "GetDigitalActionOrigins", luasteam_Controller_GetDigitalActionOrigins);
    add_func(L, "GetAnalogActionHandle", luasteam_Controller_GetAnalogActionHandle);
    add_func(L, "GetAnalogActionOrigins", luasteam_Controller_GetAnalogActionOrigins);
    add_func(L, "GetGlyphForActionOrigin", luasteam_Controller_GetGlyphForActionOrigin);
    add_func(L, "GetStringForActionOrigin", luasteam_Controller_GetStringForActionOrigin);
    add_func(L, "StopAnalogActionMomentum", luasteam_Controller_StopAnalogActionMomentum);
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
    lua_createtable(L, 0, 31);
    register_Controller_auto(L);
    lua_pushvalue(L, -1);
    Controller_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "Controller");
}

} // namespace luasteam
