#include "utils.hpp"
#include "auto/auto.hpp"
#include <algorithm>
#include <vector>
// #include <cstdio>

// ==========================
// ======= SteamUtils =======
// ==========================

using luasteam::CallResultListener;

namespace {

class CallbackListener;
CallbackListener *callback_listener = nullptr;
int utils_ref = LUA_NOREF;

constexpr int kMaxGamepadTextLength = 1000000; // clamp to avoid unbounded allocations

const char *input_modes[] = {"Normal", "Password", nullptr};
const char *input_line_modes[] = {"SingleLine", "MultipleLines", nullptr};
const char *floating_input_modes[] = {"SingleLine", "MultipleLines", "Email", "Numeric", nullptr};

class CallbackListener {
  private:
    STEAM_CALLBACK(CallbackListener, OnGamepadTextInputDismissed, GamepadTextInputDismissed_t);
    STEAM_CALLBACK(CallbackListener, OnFloatingGamepadTextInputDismissed, FloatingGamepadTextInputDismissed_t);
};

void CallbackListener::OnGamepadTextInputDismissed(GamepadTextInputDismissed_t *data) {
    if (data == nullptr) {
        return;
    }
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) {
        return;
    }

    lua_rawgeti(L, LUA_REGISTRYINDEX, utils_ref);
    lua_getfield(L, -1, "onGamepadTextInputDismissed");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushboolean(L, data->m_bSubmitted);
        lua_setfield(L, -2, "submitted");
        lua_pushnumber(L, data->m_unSubmittedText);
        lua_setfield(L, -2, "submittedText");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnFloatingGamepadTextInputDismissed(FloatingGamepadTextInputDismissed_t *data) {
    if (data == nullptr) {
        return;
    }
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) {
        return;
    }
    lua_rawgeti(L, LUA_REGISTRYINDEX, utils_ref);
    lua_getfield(L, -1, "onFloatingGamepadTextInputDismissed");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_call(L, 0, 0);
        lua_pop(L, 1);
    }
}

} // namespace

// Manually implemented because it uses a buffer and handles clamping
// bool GetEnteredGamepadTextInput( char *pchText, uint32 cchText );
EXTERN int luasteam_getEnteredGamepadTextInput(lua_State *L) {
    int len = luaL_checkint(L, 1);
    len = std::max(0, std::min(len, kMaxGamepadTextLength));
    std::vector<char> pchText(len + 1);
    SteamUtils()->GetEnteredGamepadTextInput(pchText.data(), len);
    lua_pushstring(L, pchText.data());
    return 1;
}

// Manually implemented to use luaL_checkoption for string constants and handles clamping
// bool ShowGamepadTextInput( EGamepadTextInputMode eInputMode, EGamepadTextInputLineMode eLineInputMode, const char *pchDescription, uint32 unCharMax, const char *pchExistingText );
EXTERN int luasteam_showGamepadTextInput(lua_State *L) {

    int input_mode = luaL_checkoption(L, 1, nullptr, input_modes);
    int input_line_mode = luaL_checkoption(L, 2, nullptr, input_line_modes);
    const char *pchDescription = luaL_checkstring(L, 3);
    int char_max = luaL_checkint(L, 4);
    char_max = std::max(0, std::min(char_max, kMaxGamepadTextLength));
    const char *pchExistingText = luaL_checkstring(L, 5);
    lua_pushboolean(L, SteamUtils()->ShowGamepadTextInput(static_cast<EGamepadTextInputMode>(input_mode), static_cast<EGamepadTextInputLineMode>(input_line_mode), pchDescription, char_max, pchExistingText));
    return 1;
}

// Manually implemented to use luaL_checkoption for string constants
// bool ShowFloatingGamepadTextInput(EFloatingGamepadTextInputMode eKeyboardMode, int nTextFieldXPosition, int nTextFieldYPosition, int nTextFieldWidth, int nTextFieldHeight);
EXTERN int luasteam_showFloatingGamepadTextInput(lua_State *L) {
    int floating_input_mode = luaL_checkoption(L, 1, nullptr, floating_input_modes);
    int nTextFieldXPosition = luaL_checkint(L, 2);
    int nTextFieldYPosition = luaL_checkint(L, 3);
    int nTextFieldWidth = luaL_checkint(L, 4);
    int nTextFieldHeight = luaL_checkint(L, 5);
    lua_pushboolean(L, SteamUtils()->ShowFloatingGamepadTextInput(static_cast<EFloatingGamepadTextInputMode>(floating_input_mode), nTextFieldXPosition, nTextFieldYPosition, nTextFieldWidth, nTextFieldHeight));
    return 1;
}

namespace luasteam {

void add_utils(lua_State *L) {
    lua_createtable(L, 0, 3);
    add_utils_auto(L);
    add_func(L, "getEnteredGamepadTextInput", luasteam_getEnteredGamepadTextInput);
    add_func(L, "showGamepadTextInput", luasteam_showGamepadTextInput);
    add_func(L, "showFloatingGamepadTextInput", luasteam_showFloatingGamepadTextInput);
    lua_pushvalue(L, -1);

    utils_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "utils");
}

void init_utils(lua_State *L) { callback_listener = new CallbackListener(); }

void shutdown_utils(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, utils_ref);
    utils_ref = LUA_NOREF;
    delete callback_listener;
    callback_listener = nullptr;
}

} // namespace luasteam
