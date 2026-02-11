#include "auto.hpp"

// bool BIsParentalLockEnabled();
EXTERN int luasteam_parentalsettings_SteamAPI_ISteamParentalSettings_BIsParentalLockEnabled(lua_State *L) {
    lua_pushboolean(L, SteamParentalSettings()->BIsParentalLockEnabled());
    return 1;
}

// bool BIsParentalLockLocked();
EXTERN int luasteam_parentalsettings_SteamAPI_ISteamParentalSettings_BIsParentalLockLocked(lua_State *L) {
    lua_pushboolean(L, SteamParentalSettings()->BIsParentalLockLocked());
    return 1;
}

// bool BIsAppBlocked(AppId_t nAppID);
EXTERN int luasteam_parentalsettings_SteamAPI_ISteamParentalSettings_BIsAppBlocked(lua_State *L) {
    AppId_t nAppID = luaL_checkint(L, 1);
    lua_pushboolean(L, SteamParentalSettings()->BIsAppBlocked(nAppID));
    return 1;
}

// bool BIsAppInBlockList(AppId_t nAppID);
EXTERN int luasteam_parentalsettings_SteamAPI_ISteamParentalSettings_BIsAppInBlockList(lua_State *L) {
    AppId_t nAppID = luaL_checkint(L, 1);
    lua_pushboolean(L, SteamParentalSettings()->BIsAppInBlockList(nAppID));
    return 1;
}

namespace luasteam {

void add_parentalsettings_auto(lua_State *L) {
    add_func(L, "isParentalLockEnabled", luasteam_parentalsettings_SteamAPI_ISteamParentalSettings_BIsParentalLockEnabled);
    add_func(L, "isParentalLockLocked", luasteam_parentalsettings_SteamAPI_ISteamParentalSettings_BIsParentalLockLocked);
    add_func(L, "isAppBlocked", luasteam_parentalsettings_SteamAPI_ISteamParentalSettings_BIsAppBlocked);
    add_func(L, "isAppInBlockList", luasteam_parentalsettings_SteamAPI_ISteamParentalSettings_BIsAppInBlockList);
}

} // namespace luasteam
