#include "input.hpp"
#include "auto/auto.hpp"
#include <array>
#include <map>
#include <string>
#include <vector>

// ==========================
// ======= SteamInput =======
// =========================

namespace {

} // namespace

// Manually implemented to handle the "all" string constant
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

// Manually implemented to return a table of handles
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

// Manually implemented to return a table/struct
// InputAnalogActionData_t GetAnalogActionData( InputHandle_t inputHandle, InputAnalogActionHandle_t analogActionHandle );
EXTERN int luasteam_getAnalogActionData(lua_State *L) {
    uint64 inputHandle = luasteam::checkuint64(L, 1);
    uint64 analogActionHandle = luasteam::checkuint64(L, 2);
    InputAnalogActionData_t iaad = SteamInput()->GetAnalogActionData(inputHandle, analogActionHandle);

    lua_createtable(L, 0, 4);
    lua_pushinteger(L, iaad.eMode);
    lua_setfield(L, -2, "mode");
    lua_pushnumber(L, iaad.x);
    lua_setfield(L, -2, "x");
    lua_pushnumber(L, iaad.y);
    lua_setfield(L, -2, "y");
    lua_pushboolean(L, iaad.bActive);
    lua_setfield(L, -2, "active");
    return 1;
}

// Manually implemented to return a table of origins
// int GetAnalogActionOrigins( InputHandle_t inputHandle, InputActionSetHandle_t actionSetHandle, InputAnalogActionHandle_t analogActionHandle, EInputActionOrigin *originsOut );
EXTERN int luasteam_getAnalogActionOrigins(lua_State *L) {
    uint64 inputHandle = luasteam::checkuint64(L, 1);
    uint64 actionSetHandle = luasteam::checkuint64(L, 2);
    uint64 analogActionHandle = luasteam::checkuint64(L, 3);

    EInputActionOrigin origins[STEAM_INPUT_MAX_ORIGINS];
    int sz = SteamInput()->GetAnalogActionOrigins(inputHandle, actionSetHandle, analogActionHandle, origins);
    lua_createtable(L, sz, 0);
    for (int i = 0; i < sz; i++) {
        lua_pushinteger(L, origins[i]);
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

// Manually implemented to return a table of handles
// int GetConnectedControllers( InputHandle_t *handlesOut );
EXTERN int luasteam_getConnectedControllers(lua_State *L) {
    InputHandle_t inputHandles[STEAM_INPUT_MAX_COUNT];
    int sz = SteamInput()->GetConnectedControllers(inputHandles);
    lua_createtable(L, sz, 0);
    for (int i = 0; i < sz; i++) {
        luasteam::pushuint64(L, inputHandles[i]);
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

// Manually implemented to return a table/struct
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

// Manually implemented to return a table of origins
// int GetDigitalActionOrigins( InputHandle_t inputHandle, InputActionSetHandle_t actionSetHandle, InputDigitalActionHandle_t digitalActionHandle, EInputActionOrigin *originsOut );
EXTERN int luasteam_getDigitalActionOrigins(lua_State *L) {
    uint64 inputHandle = luasteam::checkuint64(L, 1);
    uint64 actionSetHandle = luasteam::checkuint64(L, 2);
    uint64 digitalActionHandle = luasteam::checkuint64(L, 3);

    EInputActionOrigin origins[STEAM_INPUT_MAX_ORIGINS];
    int sz = SteamInput()->GetDigitalActionOrigins(inputHandle, actionSetHandle, digitalActionHandle, origins);
    lua_createtable(L, sz, 0);
    for (int i = 0; i < sz; i++) {
        lua_pushinteger(L, origins[i]);
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

// Manually implemented to handle multiple output parameters
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

namespace luasteam {

void add_input(lua_State *L) {
    lua_createtable(L, 0, 8);
    register_Input_auto(L);
    add_func(L, "activateActionSet", luasteam_activateActionSet);
    add_func(L, "getActiveActionSetLayers", luasteam_getActiveActionSetLayers);
    add_func(L, "getAnalogActionData", luasteam_getAnalogActionData);
    add_func(L, "getAnalogActionOrigins", luasteam_getAnalogActionOrigins);
    add_func(L, "getConnectedControllers", luasteam_getConnectedControllers);
    add_func(L, "getDigitalActionData", luasteam_getDigitalActionData);
    add_func(L, "getDigitalActionOrigins", luasteam_getDigitalActionOrigins);
    add_func(L, "getDeviceBindingRevision", luasteam_getDeviceBindingRevision);
    lua_pushvalue(L, -1);
    Input_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "input");
}

void init_input(lua_State *L) { init_Input_auto(L); }

void shutdown_input(lua_State *L) {
    shutdown_Input_auto(L);
}

} // namespace luasteam
