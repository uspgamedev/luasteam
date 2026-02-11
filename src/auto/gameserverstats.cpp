#include "auto.hpp"

namespace luasteam {

int gameserverstats_ref = LUA_NOREF;

namespace {

class CallbackListener {
  private:
    STEAM_GAMESERVER_CALLBACK(CallbackListener, OnGSStatsReceived, GSStatsReceived_t);
    STEAM_GAMESERVER_CALLBACK(CallbackListener, OnGSStatsStored, GSStatsStored_t);
};

void CallbackListener::OnGSStatsReceived(GSStatsReceived_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::gameserverstats_ref);
    lua_getfield(L, -1, "onGSStatsReceived");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_steamIDUser.ConvertToUint64());
        lua_setfield(L, -2, "steamIDUser");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGSStatsStored(GSStatsStored_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::gameserverstats_ref);
    lua_getfield(L, -1, "onGSStatsStored");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_steamIDUser.ConvertToUint64());
        lua_setfield(L, -2, "steamIDUser");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

CallbackListener *gameserverstats_listener = nullptr;

} // namespace

void init_gameserverstats_auto(lua_State *L) { gameserverstats_listener = new CallbackListener(); }

void shutdown_gameserverstats_auto(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, gameserverstats_ref);
    gameserverstats_ref = LUA_NOREF;
    delete gameserverstats_listener; gameserverstats_listener = nullptr;
}


// SteamAPICall_t RequestUserStats(CSteamID steamIDUser);
EXTERN int luasteam_gameserverstats_SteamAPI_ISteamGameServerStats_RequestUserStats(lua_State *L) {
    CSteamID steamIDUser(luasteam::checkuint64(L, 1));
    luasteam::pushuint64(L, SteamGameServerStats()->RequestUserStats(steamIDUser));
    return 1;
}

// bool SetUserStat(CSteamID steamIDUser, const char * pchName, int32 nData);
EXTERN int luasteam_gameserverstats_SteamAPI_ISteamGameServerStats_SetUserStatInt32(lua_State *L) {
    CSteamID steamIDUser(luasteam::checkuint64(L, 1));
    const char *pchName = luaL_checkstring(L, 2);
    int32 nData = static_cast<int32>(luaL_checkint(L, 3));
    lua_pushboolean(L, SteamGameServerStats()->SetUserStat(steamIDUser, pchName, nData));
    return 1;
}

// bool SetUserAchievement(CSteamID steamIDUser, const char * pchName);
EXTERN int luasteam_gameserverstats_SteamAPI_ISteamGameServerStats_SetUserAchievement(lua_State *L) {
    CSteamID steamIDUser(luasteam::checkuint64(L, 1));
    const char *pchName = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamGameServerStats()->SetUserAchievement(steamIDUser, pchName));
    return 1;
}

// bool ClearUserAchievement(CSteamID steamIDUser, const char * pchName);
EXTERN int luasteam_gameserverstats_SteamAPI_ISteamGameServerStats_ClearUserAchievement(lua_State *L) {
    CSteamID steamIDUser(luasteam::checkuint64(L, 1));
    const char *pchName = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamGameServerStats()->ClearUserAchievement(steamIDUser, pchName));
    return 1;
}

// SteamAPICall_t StoreUserStats(CSteamID steamIDUser);
EXTERN int luasteam_gameserverstats_SteamAPI_ISteamGameServerStats_StoreUserStats(lua_State *L) {
    CSteamID steamIDUser(luasteam::checkuint64(L, 1));
    luasteam::pushuint64(L, SteamGameServerStats()->StoreUserStats(steamIDUser));
    return 1;
}

void register_gameserverstats_auto(lua_State *L) {
    add_func(L, "requestUserStats", luasteam_gameserverstats_SteamAPI_ISteamGameServerStats_RequestUserStats);
    add_func(L, "setUserStat", luasteam_gameserverstats_SteamAPI_ISteamGameServerStats_SetUserStatInt32);
    add_func(L, "setUserAchievement", luasteam_gameserverstats_SteamAPI_ISteamGameServerStats_SetUserAchievement);
    add_func(L, "clearUserAchievement", luasteam_gameserverstats_SteamAPI_ISteamGameServerStats_ClearUserAchievement);
    add_func(L, "storeUserStats", luasteam_gameserverstats_SteamAPI_ISteamGameServerStats_StoreUserStats);
}

void add_gameserverstats_auto(lua_State *L) {
    lua_createtable(L, 0, 5);
    register_gameserverstats_auto(L);
    lua_pushvalue(L, -1);
    gameserverstats_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "gameServerStats");
}

} // namespace luasteam
