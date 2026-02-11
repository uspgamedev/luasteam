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

constexpr int kMaxGamepadTextLength = 1000000; // clamp to avoid unbounded allocations

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

// Manually implemented to handle clamping
// bool ShowGamepadTextInput( EGamepadTextInputMode eInputMode, EGamepadTextInputLineMode eLineInputMode, const char *pchDescription, uint32 unCharMax, const char *pchExistingText );
EXTERN int luasteam_showGamepadTextInput(lua_State *L) {

    int input_mode = luaL_checkint(L, 1);
    int input_line_mode = luaL_checkint(L, 2);
    const char *pchDescription = luaL_checkstring(L, 3);
    int char_max = luaL_checkint(L, 4);
    char_max = std::max(0, std::min(char_max, kMaxGamepadTextLength));
    const char *pchExistingText = luaL_checkstring(L, 5);
    lua_pushboolean(L, SteamUtils()->ShowGamepadTextInput(static_cast<EGamepadTextInputMode>(input_mode), static_cast<EGamepadTextInputLineMode>(input_line_mode), pchDescription, char_max, pchExistingText));
    return 1;
}

// Manually implemented to handle clamping
// bool ShowFloatingGamepadTextInput(EFloatingGamepadTextInputMode eKeyboardMode, int nTextFieldXPosition, int nTextFieldYPosition, int nTextFieldWidth, int nTextFieldHeight);
EXTERN int luasteam_showFloatingGamepadTextInput(lua_State *L) {
    int floating_input_mode = luaL_checkint(L, 1);
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
    register_Utils_auto(L);
    add_func(L, "getEnteredGamepadTextInput", luasteam_getEnteredGamepadTextInput);
    add_func(L, "showGamepadTextInput", luasteam_showGamepadTextInput);
    add_func(L, "showFloatingGamepadTextInput", luasteam_showFloatingGamepadTextInput);
    lua_pushvalue(L, -1);

    Utils_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "utils");
}

void init_utils(lua_State *L) { init_Utils_auto(L); }

void shutdown_utils(lua_State *L) {
    shutdown_Utils_auto(L);
}

} // namespace luasteam
