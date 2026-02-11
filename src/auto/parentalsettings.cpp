#include "auto.hpp"

namespace luasteam {

int parentalsettings_ref = LUA_NOREF;

namespace {

class CallbackListener {
  private:
    STEAM_CALLBACK(CallbackListener, OnSteamParentalSettingsChanged, SteamParentalSettingsChanged_t);
};

void CallbackListener::OnSteamParentalSettingsChanged(SteamParentalSettingsChanged_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::parentalsettings_ref);
    lua_getfield(L, -1, "onSteamParentalSettingsChanged");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 0);
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

CallbackListener *parentalsettings_listener = nullptr;

} // namespace

void init_parentalsettings_auto(lua_State *L) { parentalsettings_listener = new CallbackListener(); }

void shutdown_parentalsettings_auto(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, parentalsettings_ref);
    parentalsettings_ref = LUA_NOREF;
    delete parentalsettings_listener; parentalsettings_listener = nullptr;
}


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
    AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
    lua_pushboolean(L, SteamParentalSettings()->BIsAppBlocked(nAppID));
    return 1;
}

// bool BIsAppInBlockList(AppId_t nAppID);
EXTERN int luasteam_parentalsettings_SteamAPI_ISteamParentalSettings_BIsAppInBlockList(lua_State *L) {
    AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
    lua_pushboolean(L, SteamParentalSettings()->BIsAppInBlockList(nAppID));
    return 1;
}

// bool BIsFeatureBlocked(EParentalFeature eFeature);
EXTERN int luasteam_parentalsettings_SteamAPI_ISteamParentalSettings_BIsFeatureBlocked(lua_State *L) {
    EParentalFeature eFeature = static_cast<EParentalFeature>(luaL_checkint(L, 1));
    lua_pushboolean(L, SteamParentalSettings()->BIsFeatureBlocked(eFeature));
    return 1;
}

// bool BIsFeatureInBlockList(EParentalFeature eFeature);
EXTERN int luasteam_parentalsettings_SteamAPI_ISteamParentalSettings_BIsFeatureInBlockList(lua_State *L) {
    EParentalFeature eFeature = static_cast<EParentalFeature>(luaL_checkint(L, 1));
    lua_pushboolean(L, SteamParentalSettings()->BIsFeatureInBlockList(eFeature));
    return 1;
}

void register_parentalsettings_auto(lua_State *L) {
    add_func(L, "isParentalLockEnabled", luasteam_parentalsettings_SteamAPI_ISteamParentalSettings_BIsParentalLockEnabled);
    add_func(L, "isParentalLockLocked", luasteam_parentalsettings_SteamAPI_ISteamParentalSettings_BIsParentalLockLocked);
    add_func(L, "isAppBlocked", luasteam_parentalsettings_SteamAPI_ISteamParentalSettings_BIsAppBlocked);
    add_func(L, "isAppInBlockList", luasteam_parentalsettings_SteamAPI_ISteamParentalSettings_BIsAppInBlockList);
    add_func(L, "isFeatureBlocked", luasteam_parentalsettings_SteamAPI_ISteamParentalSettings_BIsFeatureBlocked);
    add_func(L, "isFeatureInBlockList", luasteam_parentalsettings_SteamAPI_ISteamParentalSettings_BIsFeatureInBlockList);
}

void add_parentalsettings_auto(lua_State *L) {
    lua_createtable(L, 0, 6);
    register_parentalsettings_auto(L);
    lua_pushvalue(L, -1);
    parentalsettings_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "parentalSettings");
}

} // namespace luasteam
