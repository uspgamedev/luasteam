#include "auto.hpp"
#include "../../sdk/public/steam/steam_gameserver.h"

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
    int32 nData = luaL_checkint(L, 3);
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

namespace luasteam {

void add_gameserverstats_auto(lua_State *L) {
    add_func(L, "requestUserStats", luasteam_gameserverstats_SteamAPI_ISteamGameServerStats_RequestUserStats);
    add_func(L, "setUserStat", luasteam_gameserverstats_SteamAPI_ISteamGameServerStats_SetUserStatInt32);
    add_func(L, "setUserAchievement", luasteam_gameserverstats_SteamAPI_ISteamGameServerStats_SetUserAchievement);
    add_func(L, "clearUserAchievement", luasteam_gameserverstats_SteamAPI_ISteamGameServerStats_ClearUserAchievement);
    add_func(L, "storeUserStats", luasteam_gameserverstats_SteamAPI_ISteamGameServerStats_StoreUserStats);
}

} // namespace luasteam
