#include "input.hpp"
#include <array>
#include <map>
#include <string>
#include <vector>

// ==========================
// ======= SteamInput =======
// =========================

namespace {

const char *controller_source_modes[] = {
    "None", "Dpad", "Buttons", "FourButtons", "AbsoluteMouse", "RelativeMouse", "JoystickMove", "JoystickMouse", "JoystickCamera", "ScrollWheel", "Trigger", "TouchMenu", "MouseJoystick", "MouseRegion", "RadialMenu", "SingleButton", "Switches", nullptr,
};

const char *input_action_origins[] = {
    "None", "A", "B", "X", "Y", "LeftBumper", "RightBumper", "LeftGrip", "RightGrip", "Start", "Back", "LeftPad_Touch", "LeftPad_Swipe", "LeftPad_Click", "LeftPad_DPadNorth", "LeftPad_DPadSouth", "LeftPad_DPadWest", "LeftPad_DPadEast", "RightPad_Touch", "RightPad_Swipe", "RightPad_Click", "RightPad_DPadNorth", "RightPad_DPadSouth", "RightPad_DPadWest", "RightPad_DPadEast", "LeftTrigger_Pull", "LeftTrigger_Click", "RightTrigger_Pull", "RightTrigger_Click", "LeftStick_Move", "LeftStick_Click", "LeftStick_DPadNorth", "LeftStick_DPadSouth", "LeftStick_DPadWest", "LeftStick_DPadEast", "Gyro_Move", "Gyro_Pitch", "Gyro_Yaw", "Gyro_Roll", "SteamController_Reserved0", "SteamController_Reserved1", "SteamController_Reserved2", "SteamController_Reserved3", "SteamController_Reserved4", "SteamController_Reserved5", "SteamController_Reserved6", "SteamController_Reserved7", "SteamController_Reserved8", "SteamController_Reserved9", "SteamController_Reserved10", "PS4_X", "PS4_Circle", "PS4_Triangle", "PS4_Square", "PS4_LeftBumper", "PS4_RightBumper", "PS4_Options", "PS4_Share", "PS4_LeftPad_Touch", "PS4_LeftPad_Swipe", "PS4_LeftPad_Click", "PS4_LeftPad_DPadNorth", "PS4_LeftPad_DPadSouth", "PS4_LeftPad_DPadWest", "PS4_LeftPad_DPadEast", "PS4_RightPad_Touch", "PS4_RightPad_Swipe", "PS4_RightPad_Click", "PS4_RightPad_DPadNorth", "PS4_RightPad_DPadSouth", "PS4_RightPad_DPadWest", "PS4_RightPad_DPadEast", "PS4_CenterPad_Touch", "PS4_CenterPad_Swipe", "PS4_CenterPad_Click", "PS4_CenterPad_DPadNorth", "PS4_CenterPad_DPadSouth", "PS4_CenterPad_DPadWest", "PS4_CenterPad_DPadEast", "PS4_LeftTrigger_Pull", "PS4_LeftTrigger_Click", "PS4_RightTrigger_Pull", "PS4_RightTrigger_Click", "PS4_LeftStick_Move", "PS4_LeftStick_Click", "PS4_LeftStick_DPadNorth", "PS4_LeftStick_DPadSouth", "PS4_LeftStick_DPadWest", "PS4_LeftStick_DPadEast", "PS4_RightStick_Move", "PS4_RightStick_Click", "PS4_RightStick_DPadNorth", "PS4_RightStick_DPadSouth", "PS4_RightStick_DPadWest", "PS4_RightStick_DPadEast", "PS4_DPad_North", "PS4_DPad_South", "PS4_DPad_West", "PS4_DPad_East", "PS4_Gyro_Move", "PS4_Gyro_Pitch", "PS4_Gyro_Yaw", "PS4_Gyro_Roll", "PS4_Reserved0", "PS4_Reserved1", "PS4_Reserved2", "PS4_Reserved3", "PS4_Reserved4", "PS4_Reserved5", "PS4_Reserved6", "PS4_Reserved7", "PS4_Reserved8", "PS4_Reserved9", "PS4_Reserved10", "XBoxOne_A", "XBoxOne_B", "XBoxOne_X", "XBoxOne_Y", "XBoxOne_LeftBumper", "XBoxOne_RightBumper", "XBoxOne_Menu", "XBoxOne_View", "XBoxOne_LeftTrigger_Pull", "XBoxOne_LeftTrigger_Click", "XBoxOne_RightTrigger_Pull", "XBoxOne_RightTrigger_Click", "XBoxOne_LeftStick_Move", "XBoxOne_LeftStick_Click", "XBoxOne_LeftStick_DPadNorth", "XBoxOne_LeftStick_DPadSouth", "XBoxOne_LeftStick_DPadWest", "XBoxOne_LeftStick_DPadEast", "XBoxOne_RightStick_Move", "XBoxOne_RightStick_Click", "XBoxOne_RightStick_DPadNorth", "XBoxOne_RightStick_DPadSouth", "XBoxOne_RightStick_DPadWest", "XBoxOne_RightStick_DPadEast", "XBoxOne_DPad_North", "XBoxOne_DPad_South", "XBoxOne_DPad_West", "XBoxOne_DPad_East", "XBoxOne_Reserved0", "XBoxOne_Reserved1", "XBoxOne_Reserved2", "XBoxOne_Reserved3", "XBoxOne_Reserved4", "XBoxOne_Reserved5", "XBoxOne_Reserved6", "XBoxOne_Reserved7", "XBoxOne_Reserved8", "XBoxOne_Reserved9", "XBoxOne_Reserved10", "XBox360_A", "XBox360_B", "XBox360_X", "XBox360_Y", "XBox360_LeftBumper", "XBox360_RightBumper", "XBox360_Start", "XBox360_Back", "XBox360_LeftTrigger_Pull", "XBox360_LeftTrigger_Click", "XBox360_RightTrigger_Pull", "XBox360_RightTrigger_Click", "XBox360_LeftStick_Move", "XBox360_LeftStick_Click", "XBox360_LeftStick_DPadNorth", "XBox360_LeftStick_DPadSouth", "XBox360_LeftStick_DPadWest", "XBox360_LeftStick_DPadEast", "XBox360_RightStick_Move", "XBox360_RightStick_Click", "XBox360_RightStick_DPadNorth", "XBox360_RightStick_DPadSouth", "XBox360_RightStick_DPadWest", "XBox360_RightStick_DPadEast", "XBox360_DPad_North", "XBox360_DPad_South", "XBox360_DPad_West", "XBox360_DPad_East", "XBox360_Reserved0", "XBox360_Reserved1", "XBox360_Reserved2", "XBox360_Reserved3", "XBox360_Reserved4", "XBox360_Reserved5", "XBox360_Reserved6", "XBox360_Reserved7", "XBox360_Reserved8", "XBox360_Reserved9", "XBox360_Reserved10", "Switch_A", "Switch_B", "Switch_X", "Switch_Y", "Switch_LeftBumper", "Switch_RightBumper", "Switch_Plus", "Switch_Minus", "Switch_Capture", "Switch_LeftTrigger_Pull", "Switch_LeftTrigger_Click", "Switch_RightTrigger_Pull", "Switch_RightTrigger_Click", "Switch_LeftStick_Move", "Switch_LeftStick_Click", "Switch_LeftStick_DPadNorth", "Switch_LeftStick_DPadSouth", "Switch_LeftStick_DPadWest", "Switch_LeftStick_DPadEast", "Switch_RightStick_Move", "Switch_RightStick_Click", "Switch_RightStick_DPadNorth", "Switch_RightStick_DPadSouth", "Switch_RightStick_DPadWest", "Switch_RightStick_DPadEast", "Switch_DPad_North", "Switch_DPad_South", "Switch_DPad_West", "Switch_DPad_East", "SwitchProGyro_Move", "SwitchProGyro_Pitch", "SwitchProGyro_Yaw", "SwitchProGyro_Roll", "Switch_Reserved0", "Switch_Reserved1", "Switch_Reserved2", "Switch_Reserved3", "Switch_Reserved4", "Switch_Reserved5", "Switch_Reserved6", "Switch_Reserved7", "Switch_Reserved8", "Switch_Reserved9", "Switch_Reserved10", nullptr,
};

const char *steam_input_types[] = {
    "Unknown", "SteamController", "XBox360Controller", "XBoxOneController", "GenericXInput", "PS4Controller", "AppleMFiController", "AndroidController", "SwitchJoyConPair", "SwitchJoyConSingle", "SwitchProController", "MobileTouch", "PS3Controller", "PS5Controller", "SteamDeckController", nullptr,
};

const char *xbox_origins[] = {
    "A", "B", "X", "Y", "LeftBumper", "RightBumper", "Menu", "View", "LeftTrigger_Pull", "LeftTrigger_Click", "RightTrigger_Pull", "RightTrigger_Click", "LeftStick_Move", "LeftStick_Click", "LeftStick_DPadNorth", "LeftStick_DPadSouth", "LeftStick_DPadWest", "LeftStick_DPadEast", "RightStick_Move", "RightStick_Click", "RightStick_DPadNorth", "RightStick_DPadSouth", "RightStick_DPadWest", "RightStick_DPadEast", "DPad_North", "DPad_South", "DPad_West", "DPad_East", "Count", nullptr,
};

const char *steam_controller_pads[] = {
    "Left",
    "Right",
    nullptr,
};

} // namespace

// void ActivateActionSet( InputHandle_t inputHandle, InputActionSetHandle_t actionSetHandle );
EXTERN int luasteam_activateActionSet(lua_State *L) {
    uint64 inputHandle;
    if (lua_isstring(L, 1)) {
        const char *controller = luaL_checkstring(L, 1);
        if (strcmp(controller, "all") == 0)
            inputHandle = STEAM_INPUT_HANDLE_ALL_CONTROLLERS;
        else
            return 0;
    } else {
        inputHandle = luasteam::checkuint64(L, 1);
    }

    uint64 actionSetHandle = luasteam::checkuint64(L, 2);
    SteamInput()->ActivateActionSet(inputHandle, actionSetHandle);
    return 0;
}

// void ActivateActionSetLayer( InputHandle_t inputHandle, InputActionSetHandle_t actionSetLayerHandle );
EXTERN int luasteam_activateActionSetLayer(lua_State *L) {
    uint64 inputHandle = luasteam::checkuint64(L, 1);
    uint64 actionSetLayerHandle = luasteam::checkuint64(L, 2);
    SteamInput()->ActivateActionSetLayer(inputHandle, actionSetLayerHandle);
    return 0;
}

// void DeactivateActionSetLayer( InputHandle_t inputHandle, InputActionSetHandle_t actionSetLayerHandle );
EXTERN int luasteam_deactivateActionSetLayer(lua_State *L) {
    uint64 inputHandle = luasteam::checkuint64(L, 1);
    uint64 actionSetLayerHandle = luasteam::checkuint64(L, 2);
    SteamInput()->DeactivateActionSetLayer(inputHandle, actionSetLayerHandle);
    return 0;
}

// void DeactivateAllActionSetLayers( InputHandle_t inputHandle );
EXTERN int luasteam_deactivateAllActionSetLayers(lua_State *L) {
    uint64 inputHandle = luasteam::checkuint64(L, 1);
    SteamInput()->DeactivateAllActionSetLayers(inputHandle);
    return 0;
}

// int GetActiveActionSetLayers( InputHandle_t inputHandle, InputActionSetHandle_t *handlesOut );
EXTERN int luasteam_getActiveActionSetLayers(lua_State *L) {
    uint64 inputHandle = luasteam::checkuint64(L, 1);
    int sz = STEAM_INPUT_MAX_COUNT;
    std::vector<InputActionSetHandle_t> handlesOut(sz);
    sz = SteamInput()->GetActiveActionSetLayers(inputHandle, handlesOut.data());
    lua_createtable(L, sz, 0);
    for (int i = 0; i < sz; i++) {
        luasteam::pushuint64(L, handlesOut[i]);
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

// InputActionSetHandle_t GetActionSetHandle( const char *pszActionSetName );
EXTERN int luasteam_getActionSetHandle(lua_State *L) {
    const char *pszActionSetName = luaL_checkstring(L, 1);
    luasteam::pushuint64(L, SteamInput()->GetActionSetHandle(pszActionSetName));
    return 1;
}

// InputAnalogActionData_t GetAnalogActionData( InputHandle_t inputHandle, InputAnalogActionHandle_t analogActionHandle );
EXTERN int luasteam_getAnalogActionData(lua_State *L) {
    uint64 inputHandle = luasteam::checkuint64(L, 1);
    uint64 analogActionHandle = luasteam::checkuint64(L, 2);
    InputAnalogActionData_t iaad = SteamInput()->GetAnalogActionData(inputHandle, analogActionHandle);

    lua_createtable(L, 0, 4);
    lua_pushstring(L, controller_source_modes[iaad.eMode]);
    lua_setfield(L, -2, "mode");
    lua_pushnumber(L, iaad.x);
    lua_setfield(L, -2, "x");
    lua_pushnumber(L, iaad.y);
    lua_setfield(L, -2, "y");
    lua_pushboolean(L, iaad.bActive);
    lua_setfield(L, -2, "active");
    return 1;
}

// InputAnalogActionHandle_t GetAnalogActionHandle( const char *pszActionName );
EXTERN int luasteam_getAnalogActionHandle(lua_State *L) {
    const char *pszActionName = luaL_checkstring(L, 1);
    luasteam::pushuint64(L, SteamInput()->GetAnalogActionHandle(pszActionName));
    return 1;
}

// int GetAnalogActionOrigins( InputHandle_t inputHandle, InputActionSetHandle_t actionSetHandle, InputAnalogActionHandle_t analogActionHandle, EInputActionOrigin *originsOut );
EXTERN int luasteam_getAnalogActionOrigins(lua_State *L) {
    uint64 inputHandle = luasteam::checkuint64(L, 1);
    uint64 actionSetHandle = luasteam::checkuint64(L, 2);
    uint64 analogActionHandle = luasteam::checkuint64(L, 3);

    EInputActionOrigin *origins = new EInputActionOrigin[STEAM_INPUT_MAX_ORIGINS];
    int sz = SteamInput()->GetAnalogActionOrigins(inputHandle, actionSetHandle, analogActionHandle, origins);
    lua_createtable(L, sz, 0);
    for (int i = 0; i < sz; i++) {
        lua_pushstring(L, input_action_origins[origins[i]]);
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

// int GetConnectedControllers( InputHandle_t *handlesOut );
EXTERN int luasteam_getConnectedControllers(lua_State *L) {
    InputHandle_t *inputHandles = new InputHandle_t[STEAM_INPUT_MAX_COUNT];
    int sz = SteamInput()->GetConnectedControllers(inputHandles);
    lua_createtable(L, sz, 0);
    for (int i = 0; i < sz; i++) {
        luasteam::pushuint64(L, inputHandles[i]);
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

// InputHandle_t GetControllerForGamepadIndex( int nIndex );
EXTERN int luasteam_getControllerForGamepadIndex(lua_State *L) {
    int nIndex = luaL_checkint(L, 1);
    luasteam::pushuint64(L, SteamInput()->GetControllerForGamepadIndex(nIndex));
    return 1;
}

// InputActionSetHandle_t GetCurrentActionSet( InputHandle_t inputHandle );
EXTERN int luasteam_getCurrentActionSet(lua_State *L) {
    uint64 inputHandle = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamInput()->GetCurrentActionSet(inputHandle));
    return 1;
}

// InputDigitalActionData_t GetDigitalActionData( InputHandle_t inputHandle, InputDigitalActionHandle_t digitalActionHandle );
EXTERN int luasteam_getDigitalActionData(lua_State *L) {
    uint64 inputHandle = luasteam::checkuint64(L, 1);
    uint64 digitalActionHandle = luasteam::checkuint64(L, 2);
    InputDigitalActionData_t idad = SteamInput()->GetDigitalActionData(inputHandle, digitalActionHandle);
    lua_createtable(L, 0, 2);
    lua_pushboolean(L, idad.bState);
    lua_setfield(L, -2, "state");
    lua_pushboolean(L, idad.bActive);
    lua_setfield(L, -2, "active");
    return 1;
}

// InputDigitalActionHandle_t GetDigitalActionHandle( const char *pszActionName );
EXTERN int luasteam_getDigitalActionHandle(lua_State *L) {
    const char *pszActionName = luaL_checkstring(L, 1);
    luasteam::pushuint64(L, SteamInput()->GetDigitalActionHandle(pszActionName));
    return 1;
}

// int GetDigitalActionOrigins( InputHandle_t inputHandle, InputActionSetHandle_t actionSetHandle, InputDigitalActionHandle_t digitalActionHandle, EInputActionOrigin *originsOut );
EXTERN int luasteam_getDigitalActionOrigins(lua_State *L) {
    uint64 inputHandle = luasteam::checkuint64(L, 1);
    uint64 actionSetHandle = luasteam::checkuint64(L, 2);
    uint64 digitalActionHandle = luasteam::checkuint64(L, 3);

    EInputActionOrigin *origins = new EInputActionOrigin[STEAM_INPUT_MAX_ORIGINS];
    int sz = SteamInput()->GetDigitalActionOrigins(inputHandle, actionSetHandle, digitalActionHandle, origins);
    lua_createtable(L, sz, 0);
    for (int i = 0; i < sz; i++) {
        lua_pushstring(L, input_action_origins[origins[i]]);
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

// int GetGamepadIndexForController( InputHandle_t ulControllerHandle );
EXTERN int luasteam_getGamepadIndexForController(lua_State *L) {
    uint64 ulControllerHandle = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamInput()->GetGamepadIndexForController(ulControllerHandle));
    return 1;
}

// const char * GetGlyphForActionOrigin_Legacy( EInputActionOrigin eOrigin );
EXTERN int luasteam_getGlyphForActionOrigin_Legacy(lua_State *L) {
    EInputActionOrigin inputActionOrigin = static_cast<EInputActionOrigin>(luaL_checkoption(L, 1, nullptr, input_action_origins));
    lua_pushstring(L, SteamInput()->GetGlyphForActionOrigin_Legacy(inputActionOrigin));
    return 1;
}

// ESteamInputType GetInputTypeForHandle( InputHandle_t inputHandle );
EXTERN int luasteam_getInputTypeForHandle(lua_State *L) {
    uint64 inputHandle = luasteam::checkuint64(L, 1);
    lua_pushstring(L, steam_input_types[SteamInput()->GetInputTypeForHandle(inputHandle)]);
    return 1;
}

// InputMotionData_t GetMotionData( InputHandle_t inputHandle );
EXTERN int luasteam_getMotionData(lua_State *L) {
    uint64 inputHandle = luasteam::checkuint64(L, 1);
    InputMotionData_t mot = SteamInput()->GetMotionData(inputHandle);
    lua_createtable(L, 0, 10);
    lua_pushnumber(L, mot.rotQuatX);
    lua_setfield(L, -2, "rotQuatX");
    lua_pushnumber(L, mot.rotQuatY);
    lua_setfield(L, -2, "rotQuatY");
    lua_pushnumber(L, mot.rotQuatZ);
    lua_setfield(L, -2, "rotQuatZ");
    lua_pushnumber(L, mot.rotQuatW);
    lua_setfield(L, -2, "rotQuatW");
    lua_pushnumber(L, mot.posAccelX);
    lua_setfield(L, -2, "posAccelX");
    lua_pushnumber(L, mot.posAccelY);
    lua_setfield(L, -2, "posAccelY");
    lua_pushnumber(L, mot.posAccelZ);
    lua_setfield(L, -2, "posAccelZ");
    lua_pushnumber(L, mot.rotVelX);
    lua_setfield(L, -2, "rotVelX");
    lua_pushnumber(L, mot.rotVelY);
    lua_setfield(L, -2, "rotVelY");
    lua_pushnumber(L, mot.rotVelZ);
    lua_setfield(L, -2, "rotVelZ");
    return 1;
}

// const char * GetStringForActionOrigin( EInputActionOrigin eOrigin );
EXTERN int luasteam_getStringForActionOrigin(lua_State *L) {
    EInputActionOrigin eOrigin = static_cast<EInputActionOrigin>(luaL_checkoption(L, 1, nullptr, input_action_origins));
    lua_pushstring(L, SteamInput()->GetStringForActionOrigin(eOrigin));
    return 1;
}

// void RunFrame();
EXTERN int luasteam_runFrame(lua_State *L) {
    SteamInput()->RunFrame();
    return 0;
}

// void SetLEDColor( InputHandle_t inputHandle, uint8 nColorR, uint8 nColorG, uint8 nColorB, unsigned int nFlags );
EXTERN int luasteam_setLEDColor(lua_State *L) {
    uint64 inputHandle = luasteam::checkuint64(L, 1);
    uint8 nColorR = luaL_checkint(L, 2);
    uint8 nColorG = luaL_checkint(L, 3);
    uint8 nColorB = luaL_checkint(L, 4);
    bool resetColor = lua_toboolean(L, 5);
    SteamInput()->SetLEDColor(inputHandle, nColorR, nColorG, nColorB, resetColor ? k_ESteamControllerLEDFlag_RestoreUserDefault : k_ESteamControllerLEDFlag_SetColor);
    return 0;
}

// bool ShowBindingPanel( InputHandle_t inputHandle );
EXTERN int luasteam_showBindingPanel(lua_State *L) {
    uint64 inputHandle = luasteam::checkuint64(L, 1);
    lua_pushboolean(L, SteamInput()->ShowBindingPanel(inputHandle));
    return 1;
}

// void StopAnalogActionMomentum( InputHandle_t inputHandle, InputAnalogActionHandle_t eAction );
EXTERN int luasteam_stopAnalogActionMomentum(lua_State *L) {
    uint64 inputHandle = luasteam::checkuint64(L, 1);
    uint64 eAction = luasteam::checkuint64(L, 2);
    SteamInput()->StopAnalogActionMomentum(inputHandle, eAction);
    return 0;
}

// void Legacy_TriggerHapticPulse( InputHandle_t inputHandle, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec );
EXTERN int luasteam_legacy_triggerHapticPulse(lua_State *L) {
    uint64 inputHandle = luasteam::checkuint64(L, 1);
    ESteamControllerPad eTargetPad = static_cast<ESteamControllerPad>(luaL_checkoption(L, 2, nullptr, steam_controller_pads));
    unsigned short usDurationMicroSec = luaL_checkint(L, 3);
    SteamInput()->Legacy_TriggerHapticPulse(inputHandle, eTargetPad, usDurationMicroSec);
    return 0;
}

// void Legacy_TriggerRepeatedHapticPulse( InputHandle_t inputHandle, ESteamControllerPad eTargetPad, unsigned short usDurationMicroSec, unsigned short usOffMicroSec, unsigned short unRepeat, unsigned int nFlags );
EXTERN int luasteam_legacy_triggerRepeatedHapticPulse(lua_State *L) {
    uint64 inputHandle = luasteam::checkuint64(L, 1);
    ESteamControllerPad eTargetPad = static_cast<ESteamControllerPad>(luaL_checkoption(L, 2, nullptr, steam_controller_pads));
    unsigned short usDurationMicroSec = luaL_checkint(L, 3);
    unsigned short usOffMicroSec = luaL_checkint(L, 4);
    unsigned short unRepeat = luaL_checkint(L, 5);
    SteamInput()->Legacy_TriggerRepeatedHapticPulse(inputHandle, eTargetPad, usDurationMicroSec, usOffMicroSec, unRepeat, 0);
    return 0;
}

// void TriggerVibration( InputHandle_t inputHandle, unsigned short usLeftSpeed, unsigned short usRightSpeed );
EXTERN int luasteam_triggerVibration(lua_State *L) {
    uint64 inputHandle = luasteam::checkuint64(L, 1);
    unsigned short usLeftSpeed = luaL_checkint(L, 2);
    unsigned short usRightSpeed = luaL_checkint(L, 3);
    SteamInput()->TriggerVibration(inputHandle, usLeftSpeed, usRightSpeed);
    return 0;
}

// EInputActionOrigin GetActionOriginFromXboxOrigin( InputHandle_t inputHandle, EXboxOrigin eOrigin );
EXTERN int luasteam_getActionOriginFromXboxOrigin(lua_State *L) {
    uint64 inputHandle = luasteam::checkuint64(L, 1);
    EXboxOrigin eOrigin = static_cast<EXboxOrigin>(luaL_checkoption(L, 2, nullptr, xbox_origins));
    lua_pushstring(L, input_action_origins[SteamInput()->GetActionOriginFromXboxOrigin(inputHandle, eOrigin)]);
    return 1;
}

// EInputActionOrigin TranslateActionOrigin( ESteamInputType eDestinationInputType, EInputActionOrigin eSourceOrigin );
EXTERN int luasteam_translateActionOrigin(lua_State *L) {
    ESteamInputType eDestinationInputType = static_cast<ESteamInputType>(luaL_checkoption(L, 1, nullptr, steam_input_types));
    EInputActionOrigin eSourceOrigin = static_cast<EInputActionOrigin>(luaL_checkoption(L, 2, nullptr, input_action_origins));
    lua_pushstring(L, input_action_origins[SteamInput()->TranslateActionOrigin(eDestinationInputType, eSourceOrigin)]);
    return 1;
}

// bool GetDeviceBindingRevision( InputHandle_t inputHandle, int *pMajor, int *pMinor );
EXTERN int luasteam_getDeviceBindingRevision(lua_State *L) {
    uint64 inputHandle = luasteam::checkuint64(L, 1);
    int nMajorRevision = -1;
    int nMinorRevision = -1;
    bool success = SteamInput()->GetDeviceBindingRevision(inputHandle, &nMajorRevision, &nMinorRevision);

    lua_pushboolean(L, success);
    if (success) {
        lua_pushnumber(L, nMajorRevision);
        lua_pushnumber(L, nMinorRevision);
        return 3;
    }
    return 1;
}

// uint32 GetRemotePlaySessionID( InputHandle_t inputHandle );
EXTERN int luasteam_getRemotePlaySessionID(lua_State *L) {
    uint64 inputHandle = luasteam::checkuint64(L, 1);
    lua_pushnumber(L, SteamInput()->GetRemotePlaySessionID(inputHandle));
    return 1;
}

EXTERN int luasteam_input_init(lua_State *L) {
    bool explicitlyCallRunFrame = lua_toboolean(L, 1);
    bool success = SteamInput()->Init(explicitlyCallRunFrame);
    lua_pushboolean(L, success);
    return 1;
}

EXTERN int luasteam_input_shutdown(lua_State *L) {
    bool success = SteamInput()->Shutdown();
    lua_pushboolean(L, success);
    return 1;
}

namespace luasteam {

void add_input(lua_State *L) {
    lua_createtable(L, 0, 33);
    add_func(L, "activateActionSet", luasteam_activateActionSet);
    add_func(L, "activateActionSetLayer", luasteam_activateActionSetLayer);
    add_func(L, "deactivateActionSetLayer", luasteam_deactivateActionSetLayer);
    add_func(L, "deactivateAllActionSetLayers", luasteam_deactivateAllActionSetLayers);
    add_func(L, "getActiveActionSetLayers", luasteam_getActiveActionSetLayers);
    add_func(L, "getActionSetHandle", luasteam_getActionSetHandle);
    add_func(L, "getAnalogActionData", luasteam_getAnalogActionData);
    add_func(L, "getAnalogActionHandle", luasteam_getAnalogActionHandle);
    add_func(L, "getAnalogActionOrigins", luasteam_getAnalogActionOrigins);
    add_func(L, "getConnectedControllers", luasteam_getConnectedControllers);
    add_func(L, "getControllerForGamepadIndex", luasteam_getControllerForGamepadIndex);
    add_func(L, "getCurrentActionSet", luasteam_getCurrentActionSet);
    add_func(L, "getDigitalActionData", luasteam_getDigitalActionData);
    add_func(L, "getDigitalActionHandle", luasteam_getDigitalActionHandle);
    add_func(L, "getDigitalActionOrigins", luasteam_getDigitalActionOrigins);
    add_func(L, "getGamepadIndexForController", luasteam_getGamepadIndexForController);
    add_func(L, "getGlyphForActionOrigin_Legacy", luasteam_getGlyphForActionOrigin_Legacy);
    add_func(L, "getInputTypeForHandle", luasteam_getInputTypeForHandle);
    add_func(L, "getMotionData", luasteam_getMotionData);
    add_func(L, "getStringForActionOrigin", luasteam_getStringForActionOrigin);
    add_func(L, "runFrame", luasteam_runFrame);
    add_func(L, "setLEDColor", luasteam_setLEDColor);
    add_func(L, "showBindingPanel", luasteam_showBindingPanel);
    add_func(L, "stopAnalogActionMomentum", luasteam_stopAnalogActionMomentum);
    add_func(L, "legacy_triggerHapticPulse", luasteam_legacy_triggerHapticPulse);
    add_func(L, "legacy_triggerRepeatedHapticPulse", luasteam_legacy_triggerRepeatedHapticPulse);
    add_func(L, "triggerVibration", luasteam_triggerVibration);
    add_func(L, "getActionOriginFromXboxOrigin", luasteam_getActionOriginFromXboxOrigin);
    add_func(L, "translateActionOrigin", luasteam_translateActionOrigin);
    add_func(L, "getDeviceBindingRevision", luasteam_getDeviceBindingRevision);
    add_func(L, "getRemotePlaySessionID", luasteam_getRemotePlaySessionID);
    add_func(L, "init", luasteam_input_init);
    add_func(L, "shutdown", luasteam_input_shutdown);
    lua_setfield(L, -2, "input");
}

void init_input(lua_State *L) {}

void shutdown_input(lua_State *L) {}

} // namespace luasteam
