#include "auto.hpp"

// bool SetStat(const char * pchName, int32 nData);
EXTERN int luasteam_userstats_SteamAPI_ISteamUserStats_SetStatInt32(lua_State *L) {
    const char *pchName = luaL_checkstring(L, 1);
    int32 nData = static_cast<int32>(luaL_checkint(L, 2));
    lua_pushboolean(L, SteamUserStats()->SetStat(pchName, nData));
    return 1;
}

// bool SetAchievement(const char * pchName);
EXTERN int luasteam_userstats_SteamAPI_ISteamUserStats_SetAchievement(lua_State *L) {
    const char *pchName = luaL_checkstring(L, 1);
    lua_pushboolean(L, SteamUserStats()->SetAchievement(pchName));
    return 1;
}

// bool ClearAchievement(const char * pchName);
EXTERN int luasteam_userstats_SteamAPI_ISteamUserStats_ClearAchievement(lua_State *L) {
    const char *pchName = luaL_checkstring(L, 1);
    lua_pushboolean(L, SteamUserStats()->ClearAchievement(pchName));
    return 1;
}

// bool StoreStats();
EXTERN int luasteam_userstats_SteamAPI_ISteamUserStats_StoreStats(lua_State *L) {
    lua_pushboolean(L, SteamUserStats()->StoreStats());
    return 1;
}

// int GetAchievementIcon(const char * pchName);
EXTERN int luasteam_userstats_SteamAPI_ISteamUserStats_GetAchievementIcon(lua_State *L) {
    const char *pchName = luaL_checkstring(L, 1);
    lua_pushinteger(L, SteamUserStats()->GetAchievementIcon(pchName));
    return 1;
}

// const char * GetAchievementDisplayAttribute(const char * pchName, const char * pchKey);
EXTERN int luasteam_userstats_SteamAPI_ISteamUserStats_GetAchievementDisplayAttribute(lua_State *L) {
    const char *pchName = luaL_checkstring(L, 1);
    const char *pchKey = luaL_checkstring(L, 2);
    lua_pushstring(L, SteamUserStats()->GetAchievementDisplayAttribute(pchName, pchKey));
    return 1;
}

// bool IndicateAchievementProgress(const char * pchName, uint32 nCurProgress, uint32 nMaxProgress);
EXTERN int luasteam_userstats_SteamAPI_ISteamUserStats_IndicateAchievementProgress(lua_State *L) {
    const char *pchName = luaL_checkstring(L, 1);
    uint32 nCurProgress = static_cast<uint32>(luaL_checkint(L, 2));
    uint32 nMaxProgress = static_cast<uint32>(luaL_checkint(L, 3));
    lua_pushboolean(L, SteamUserStats()->IndicateAchievementProgress(pchName, nCurProgress, nMaxProgress));
    return 1;
}

// uint32 GetNumAchievements();
EXTERN int luasteam_userstats_SteamAPI_ISteamUserStats_GetNumAchievements(lua_State *L) {
    lua_pushinteger(L, SteamUserStats()->GetNumAchievements());
    return 1;
}

// const char * GetAchievementName(uint32 iAchievement);
EXTERN int luasteam_userstats_SteamAPI_ISteamUserStats_GetAchievementName(lua_State *L) {
    uint32 iAchievement = static_cast<uint32>(luaL_checkint(L, 1));
    lua_pushstring(L, SteamUserStats()->GetAchievementName(iAchievement));
    return 1;
}

// SteamAPICall_t RequestUserStats(CSteamID steamIDUser);
EXTERN int luasteam_userstats_SteamAPI_ISteamUserStats_RequestUserStats(lua_State *L) {
    CSteamID steamIDUser(luasteam::checkuint64(L, 1));
    luasteam::pushuint64(L, SteamUserStats()->RequestUserStats(steamIDUser));
    return 1;
}

// bool ResetAllStats(bool bAchievementsToo);
EXTERN int luasteam_userstats_SteamAPI_ISteamUserStats_ResetAllStats(lua_State *L) {
    bool bAchievementsToo = lua_toboolean(L, 1);
    lua_pushboolean(L, SteamUserStats()->ResetAllStats(bAchievementsToo));
    return 1;
}

// SteamAPICall_t FindOrCreateLeaderboard(const char * pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType);
EXTERN int luasteam_userstats_SteamAPI_ISteamUserStats_FindOrCreateLeaderboard(lua_State *L) {
    const char *pchLeaderboardName = luaL_checkstring(L, 1);
    ELeaderboardSortMethod eLeaderboardSortMethod = static_cast<ELeaderboardSortMethod>(luaL_checkint(L, 2));
    ELeaderboardDisplayType eLeaderboardDisplayType = static_cast<ELeaderboardDisplayType>(luaL_checkint(L, 3));
    luasteam::pushuint64(L, SteamUserStats()->FindOrCreateLeaderboard(pchLeaderboardName, eLeaderboardSortMethod, eLeaderboardDisplayType));
    return 1;
}

// SteamAPICall_t FindLeaderboard(const char * pchLeaderboardName);
EXTERN int luasteam_userstats_SteamAPI_ISteamUserStats_FindLeaderboard(lua_State *L) {
    const char *pchLeaderboardName = luaL_checkstring(L, 1);
    luasteam::pushuint64(L, SteamUserStats()->FindLeaderboard(pchLeaderboardName));
    return 1;
}

// const char * GetLeaderboardName(SteamLeaderboard_t hSteamLeaderboard);
EXTERN int luasteam_userstats_SteamAPI_ISteamUserStats_GetLeaderboardName(lua_State *L) {
    SteamLeaderboard_t hSteamLeaderboard = luasteam::checkuint64(L, 1);
    lua_pushstring(L, SteamUserStats()->GetLeaderboardName(hSteamLeaderboard));
    return 1;
}

// int GetLeaderboardEntryCount(SteamLeaderboard_t hSteamLeaderboard);
EXTERN int luasteam_userstats_SteamAPI_ISteamUserStats_GetLeaderboardEntryCount(lua_State *L) {
    SteamLeaderboard_t hSteamLeaderboard = luasteam::checkuint64(L, 1);
    lua_pushinteger(L, SteamUserStats()->GetLeaderboardEntryCount(hSteamLeaderboard));
    return 1;
}

// ELeaderboardSortMethod GetLeaderboardSortMethod(SteamLeaderboard_t hSteamLeaderboard);
EXTERN int luasteam_userstats_SteamAPI_ISteamUserStats_GetLeaderboardSortMethod(lua_State *L) {
    SteamLeaderboard_t hSteamLeaderboard = luasteam::checkuint64(L, 1);
    lua_pushinteger(L, SteamUserStats()->GetLeaderboardSortMethod(hSteamLeaderboard));
    return 1;
}

// ELeaderboardDisplayType GetLeaderboardDisplayType(SteamLeaderboard_t hSteamLeaderboard);
EXTERN int luasteam_userstats_SteamAPI_ISteamUserStats_GetLeaderboardDisplayType(lua_State *L) {
    SteamLeaderboard_t hSteamLeaderboard = luasteam::checkuint64(L, 1);
    lua_pushinteger(L, SteamUserStats()->GetLeaderboardDisplayType(hSteamLeaderboard));
    return 1;
}

// SteamAPICall_t DownloadLeaderboardEntries(SteamLeaderboard_t hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, int nRangeStart, int nRangeEnd);
EXTERN int luasteam_userstats_SteamAPI_ISteamUserStats_DownloadLeaderboardEntries(lua_State *L) {
    SteamLeaderboard_t hSteamLeaderboard = luasteam::checkuint64(L, 1);
    ELeaderboardDataRequest eLeaderboardDataRequest = static_cast<ELeaderboardDataRequest>(luaL_checkint(L, 2));
    int nRangeStart = static_cast<int>(luaL_checkint(L, 3));
    int nRangeEnd = static_cast<int>(luaL_checkint(L, 4));
    luasteam::pushuint64(L, SteamUserStats()->DownloadLeaderboardEntries(hSteamLeaderboard, eLeaderboardDataRequest, nRangeStart, nRangeEnd));
    return 1;
}

// SteamAPICall_t AttachLeaderboardUGC(SteamLeaderboard_t hSteamLeaderboard, UGCHandle_t hUGC);
EXTERN int luasteam_userstats_SteamAPI_ISteamUserStats_AttachLeaderboardUGC(lua_State *L) {
    SteamLeaderboard_t hSteamLeaderboard = luasteam::checkuint64(L, 1);
    UGCHandle_t hUGC = luasteam::checkuint64(L, 2);
    luasteam::pushuint64(L, SteamUserStats()->AttachLeaderboardUGC(hSteamLeaderboard, hUGC));
    return 1;
}

// SteamAPICall_t GetNumberOfCurrentPlayers();
EXTERN int luasteam_userstats_SteamAPI_ISteamUserStats_GetNumberOfCurrentPlayers(lua_State *L) {
    luasteam::pushuint64(L, SteamUserStats()->GetNumberOfCurrentPlayers());
    return 1;
}

// SteamAPICall_t RequestGlobalAchievementPercentages();
EXTERN int luasteam_userstats_SteamAPI_ISteamUserStats_RequestGlobalAchievementPercentages(lua_State *L) {
    luasteam::pushuint64(L, SteamUserStats()->RequestGlobalAchievementPercentages());
    return 1;
}

// SteamAPICall_t RequestGlobalStats(int nHistoryDays);
EXTERN int luasteam_userstats_SteamAPI_ISteamUserStats_RequestGlobalStats(lua_State *L) {
    int nHistoryDays = static_cast<int>(luaL_checkint(L, 1));
    luasteam::pushuint64(L, SteamUserStats()->RequestGlobalStats(nHistoryDays));
    return 1;
}

namespace luasteam {

void add_userstats_auto(lua_State *L) {
    add_func(L, "setStat", luasteam_userstats_SteamAPI_ISteamUserStats_SetStatInt32);
    add_func(L, "setAchievement", luasteam_userstats_SteamAPI_ISteamUserStats_SetAchievement);
    add_func(L, "clearAchievement", luasteam_userstats_SteamAPI_ISteamUserStats_ClearAchievement);
    add_func(L, "storeStats", luasteam_userstats_SteamAPI_ISteamUserStats_StoreStats);
    add_func(L, "getAchievementIcon", luasteam_userstats_SteamAPI_ISteamUserStats_GetAchievementIcon);
    add_func(L, "getAchievementDisplayAttribute", luasteam_userstats_SteamAPI_ISteamUserStats_GetAchievementDisplayAttribute);
    add_func(L, "indicateAchievementProgress", luasteam_userstats_SteamAPI_ISteamUserStats_IndicateAchievementProgress);
    add_func(L, "getNumAchievements", luasteam_userstats_SteamAPI_ISteamUserStats_GetNumAchievements);
    add_func(L, "getAchievementName", luasteam_userstats_SteamAPI_ISteamUserStats_GetAchievementName);
    add_func(L, "requestUserStats", luasteam_userstats_SteamAPI_ISteamUserStats_RequestUserStats);
    add_func(L, "resetAllStats", luasteam_userstats_SteamAPI_ISteamUserStats_ResetAllStats);
    add_func(L, "findOrCreateLeaderboard", luasteam_userstats_SteamAPI_ISteamUserStats_FindOrCreateLeaderboard);
    add_func(L, "findLeaderboard", luasteam_userstats_SteamAPI_ISteamUserStats_FindLeaderboard);
    add_func(L, "getLeaderboardName", luasteam_userstats_SteamAPI_ISteamUserStats_GetLeaderboardName);
    add_func(L, "getLeaderboardEntryCount", luasteam_userstats_SteamAPI_ISteamUserStats_GetLeaderboardEntryCount);
    add_func(L, "getLeaderboardSortMethod", luasteam_userstats_SteamAPI_ISteamUserStats_GetLeaderboardSortMethod);
    add_func(L, "getLeaderboardDisplayType", luasteam_userstats_SteamAPI_ISteamUserStats_GetLeaderboardDisplayType);
    add_func(L, "downloadLeaderboardEntries", luasteam_userstats_SteamAPI_ISteamUserStats_DownloadLeaderboardEntries);
    add_func(L, "attachLeaderboardUGC", luasteam_userstats_SteamAPI_ISteamUserStats_AttachLeaderboardUGC);
    add_func(L, "getNumberOfCurrentPlayers", luasteam_userstats_SteamAPI_ISteamUserStats_GetNumberOfCurrentPlayers);
    add_func(L, "requestGlobalAchievementPercentages", luasteam_userstats_SteamAPI_ISteamUserStats_RequestGlobalAchievementPercentages);
    add_func(L, "requestGlobalStats", luasteam_userstats_SteamAPI_ISteamUserStats_RequestGlobalStats);
}

} // namespace luasteam
