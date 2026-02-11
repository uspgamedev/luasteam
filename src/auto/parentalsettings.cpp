#include "auto.hpp"

namespace luasteam {

int ParentalSettings_ref = LUA_NOREF;

namespace {

class CallbackListener {
  private:
    STEAM_CALLBACK(CallbackListener, OnSteamParentalSettingsChanged, SteamParentalSettingsChanged_t);
};

void CallbackListener::OnSteamParentalSettingsChanged(SteamParentalSettingsChanged_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::ParentalSettings_ref);
    lua_getfield(L, -1, "onSteamParentalSettingsChanged");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 0);
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

CallbackListener *ParentalSettings_listener = nullptr;

} // namespace

void init_ParentalSettings_auto(lua_State *L) { ParentalSettings_listener = new CallbackListener(); }

void shutdown_ParentalSettings_auto(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, ParentalSettings_ref);
    ParentalSettings_ref = LUA_NOREF;
    delete ParentalSettings_listener; ParentalSettings_listener = nullptr;
}


// bool BIsParentalLockEnabled();
EXTERN int luasteam_ParentalSettings_BIsParentalLockEnabled(lua_State *L) {
    lua_pushboolean(L, SteamParentalSettings()->BIsParentalLockEnabled());
    return 1;
}

// bool BIsParentalLockLocked();
EXTERN int luasteam_ParentalSettings_BIsParentalLockLocked(lua_State *L) {
    lua_pushboolean(L, SteamParentalSettings()->BIsParentalLockLocked());
    return 1;
}

// bool BIsAppBlocked(AppId_t nAppID);
EXTERN int luasteam_ParentalSettings_BIsAppBlocked(lua_State *L) {
    AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
    lua_pushboolean(L, SteamParentalSettings()->BIsAppBlocked(nAppID));
    return 1;
}

// bool BIsAppInBlockList(AppId_t nAppID);
EXTERN int luasteam_ParentalSettings_BIsAppInBlockList(lua_State *L) {
    AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
    lua_pushboolean(L, SteamParentalSettings()->BIsAppInBlockList(nAppID));
    return 1;
}

// bool BIsFeatureBlocked(EParentalFeature eFeature);
EXTERN int luasteam_ParentalSettings_BIsFeatureBlocked(lua_State *L) {
    EParentalFeature eFeature = static_cast<EParentalFeature>(luaL_checkint(L, 1));
    lua_pushboolean(L, SteamParentalSettings()->BIsFeatureBlocked(eFeature));
    return 1;
}

// bool BIsFeatureInBlockList(EParentalFeature eFeature);
EXTERN int luasteam_ParentalSettings_BIsFeatureInBlockList(lua_State *L) {
    EParentalFeature eFeature = static_cast<EParentalFeature>(luaL_checkint(L, 1));
    lua_pushboolean(L, SteamParentalSettings()->BIsFeatureInBlockList(eFeature));
    return 1;
}

void register_ParentalSettings_auto(lua_State *L) {
    add_func(L, "BIsParentalLockEnabled", luasteam_ParentalSettings_BIsParentalLockEnabled);
    add_func(L, "BIsParentalLockLocked", luasteam_ParentalSettings_BIsParentalLockLocked);
    add_func(L, "BIsAppBlocked", luasteam_ParentalSettings_BIsAppBlocked);
    add_func(L, "BIsAppInBlockList", luasteam_ParentalSettings_BIsAppInBlockList);
    add_func(L, "BIsFeatureBlocked", luasteam_ParentalSettings_BIsFeatureBlocked);
    add_func(L, "BIsFeatureInBlockList", luasteam_ParentalSettings_BIsFeatureInBlockList);
}

void add_ParentalSettings_auto(lua_State *L) {
    lua_createtable(L, 0, 6);
    register_ParentalSettings_auto(L);
    lua_pushvalue(L, -1);
    ParentalSettings_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "ParentalSettings");
}

} // namespace luasteam
