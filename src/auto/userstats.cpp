#include "auto.hpp"

namespace luasteam {

int UserStats_ref = LUA_NOREF;

namespace {

class CallbackListener {
  private:
    STEAM_CALLBACK(CallbackListener, OnUserStatsReceived, UserStatsReceived_t);
    STEAM_CALLBACK(CallbackListener, OnUserStatsStored, UserStatsStored_t);
    STEAM_CALLBACK(CallbackListener, OnUserAchievementStored, UserAchievementStored_t);
    STEAM_CALLBACK(CallbackListener, OnLeaderboardFindResult, LeaderboardFindResult_t);
    STEAM_CALLBACK(CallbackListener, OnLeaderboardScoresDownloaded, LeaderboardScoresDownloaded_t);
    STEAM_CALLBACK(CallbackListener, OnLeaderboardScoreUploaded, LeaderboardScoreUploaded_t);
    STEAM_CALLBACK(CallbackListener, OnNumberOfCurrentPlayers, NumberOfCurrentPlayers_t);
    STEAM_CALLBACK(CallbackListener, OnUserStatsUnloaded, UserStatsUnloaded_t);
    STEAM_CALLBACK(CallbackListener, OnUserAchievementIconFetched, UserAchievementIconFetched_t);
    STEAM_CALLBACK(CallbackListener, OnGlobalAchievementPercentagesReady, GlobalAchievementPercentagesReady_t);
    STEAM_CALLBACK(CallbackListener, OnLeaderboardUGCSet, LeaderboardUGCSet_t);
    STEAM_CALLBACK(CallbackListener, OnGlobalStatsReceived, GlobalStatsReceived_t);
    STEAM_CALLBACK(CallbackListener, OnGSStatsUnloaded, GSStatsUnloaded_t);
};

void CallbackListener::OnUserStatsReceived(UserStatsReceived_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UserStats_ref);
    lua_getfield(L, -1, "onUserStatsReceived");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        luasteam::pushuint64(L, data->m_nGameID);
        lua_setfield(L, -2, "gameID");
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_steamIDUser.ConvertToUint64());
        lua_setfield(L, -2, "steamIDUser");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnUserStatsStored(UserStatsStored_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UserStats_ref);
    lua_getfield(L, -1, "onUserStatsStored");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        luasteam::pushuint64(L, data->m_nGameID);
        lua_setfield(L, -2, "gameID");
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnUserAchievementStored(UserAchievementStored_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UserStats_ref);
    lua_getfield(L, -1, "onUserAchievementStored");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 5);
        luasteam::pushuint64(L, data->m_nGameID);
        lua_setfield(L, -2, "gameID");
        lua_pushboolean(L, data->m_bGroupAchievement);
        lua_setfield(L, -2, "groupAchievement");
        lua_pushstring(L, data->m_rgchAchievementName);
        lua_setfield(L, -2, "achievementName");
        lua_pushinteger(L, data->m_nCurProgress);
        lua_setfield(L, -2, "curProgress");
        lua_pushinteger(L, data->m_nMaxProgress);
        lua_setfield(L, -2, "maxProgress");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnLeaderboardFindResult(LeaderboardFindResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UserStats_ref);
    lua_getfield(L, -1, "onLeaderboardFindResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        luasteam::pushuint64(L, data->m_hSteamLeaderboard);
        lua_setfield(L, -2, "steamLeaderboard");
        lua_pushboolean(L, data->m_bLeaderboardFound);
        lua_setfield(L, -2, "leaderboardFound");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnLeaderboardScoresDownloaded(LeaderboardScoresDownloaded_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UserStats_ref);
    lua_getfield(L, -1, "onLeaderboardScoresDownloaded");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        luasteam::pushuint64(L, data->m_hSteamLeaderboard);
        lua_setfield(L, -2, "steamLeaderboard");
        luasteam::pushuint64(L, data->m_hSteamLeaderboardEntries);
        lua_setfield(L, -2, "steamLeaderboardEntries");
        lua_pushinteger(L, data->m_cEntryCount);
        lua_setfield(L, -2, "cEntryCount");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnLeaderboardScoreUploaded(LeaderboardScoreUploaded_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UserStats_ref);
    lua_getfield(L, -1, "onLeaderboardScoreUploaded");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 6);
        lua_pushboolean(L, data->m_bSuccess);
        lua_setfield(L, -2, "success");
        luasteam::pushuint64(L, data->m_hSteamLeaderboard);
        lua_setfield(L, -2, "steamLeaderboard");
        lua_pushinteger(L, data->m_nScore);
        lua_setfield(L, -2, "score");
        lua_pushboolean(L, data->m_bScoreChanged);
        lua_setfield(L, -2, "scoreChanged");
        lua_pushinteger(L, data->m_nGlobalRankNew);
        lua_setfield(L, -2, "globalRankNew");
        lua_pushinteger(L, data->m_nGlobalRankPrevious);
        lua_setfield(L, -2, "globalRankPrevious");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnNumberOfCurrentPlayers(NumberOfCurrentPlayers_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UserStats_ref);
    lua_getfield(L, -1, "onNumberOfCurrentPlayers");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushboolean(L, data->m_bSuccess);
        lua_setfield(L, -2, "success");
        lua_pushinteger(L, data->m_cPlayers);
        lua_setfield(L, -2, "cPlayers");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnUserStatsUnloaded(UserStatsUnloaded_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UserStats_ref);
    lua_getfield(L, -1, "onUserStatsUnloaded");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        luasteam::pushuint64(L, data->m_steamIDUser.ConvertToUint64());
        lua_setfield(L, -2, "steamIDUser");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnUserAchievementIconFetched(UserAchievementIconFetched_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UserStats_ref);
    lua_getfield(L, -1, "onUserAchievementIconFetched");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        luasteam::pushuint64(L, data->m_nGameID.ToUint64());
        lua_setfield(L, -2, "gameID");
        lua_pushstring(L, data->m_rgchAchievementName);
        lua_setfield(L, -2, "achievementName");
        lua_pushboolean(L, data->m_bAchieved);
        lua_setfield(L, -2, "achieved");
        lua_pushinteger(L, data->m_nIconHandle);
        lua_setfield(L, -2, "iconHandle");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGlobalAchievementPercentagesReady(GlobalAchievementPercentagesReady_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UserStats_ref);
    lua_getfield(L, -1, "onGlobalAchievementPercentagesReady");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        luasteam::pushuint64(L, data->m_nGameID);
        lua_setfield(L, -2, "gameID");
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnLeaderboardUGCSet(LeaderboardUGCSet_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UserStats_ref);
    lua_getfield(L, -1, "onLeaderboardUGCSet");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_hSteamLeaderboard);
        lua_setfield(L, -2, "steamLeaderboard");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGlobalStatsReceived(GlobalStatsReceived_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UserStats_ref);
    lua_getfield(L, -1, "onGlobalStatsReceived");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        luasteam::pushuint64(L, data->m_nGameID);
        lua_setfield(L, -2, "gameID");
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGSStatsUnloaded(GSStatsUnloaded_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UserStats_ref);
    lua_getfield(L, -1, "onGSStatsUnloaded");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        luasteam::pushuint64(L, data->m_steamIDUser.ConvertToUint64());
        lua_setfield(L, -2, "steamIDUser");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

CallbackListener *UserStats_listener = nullptr;

} // namespace

void init_UserStats_auto(lua_State *L) { UserStats_listener = new CallbackListener(); }

void shutdown_UserStats_auto(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, UserStats_ref);
    UserStats_ref = LUA_NOREF;
    delete UserStats_listener; UserStats_listener = nullptr;
}


// bool SetStat(const char * pchName, int32 nData);
EXTERN int luasteam_UserStats_SetStat(lua_State *L) {
    const char *pchName = luaL_checkstring(L, 1);
    int32 nData = static_cast<int32>(luaL_checkint(L, 2));
    lua_pushboolean(L, SteamUserStats()->SetStat(pchName, nData));
    return 1;
}

// bool SetAchievement(const char * pchName);
EXTERN int luasteam_UserStats_SetAchievement(lua_State *L) {
    const char *pchName = luaL_checkstring(L, 1);
    lua_pushboolean(L, SteamUserStats()->SetAchievement(pchName));
    return 1;
}

// bool ClearAchievement(const char * pchName);
EXTERN int luasteam_UserStats_ClearAchievement(lua_State *L) {
    const char *pchName = luaL_checkstring(L, 1);
    lua_pushboolean(L, SteamUserStats()->ClearAchievement(pchName));
    return 1;
}

// bool StoreStats();
EXTERN int luasteam_UserStats_StoreStats(lua_State *L) {
    lua_pushboolean(L, SteamUserStats()->StoreStats());
    return 1;
}

// int GetAchievementIcon(const char * pchName);
EXTERN int luasteam_UserStats_GetAchievementIcon(lua_State *L) {
    const char *pchName = luaL_checkstring(L, 1);
    lua_pushinteger(L, SteamUserStats()->GetAchievementIcon(pchName));
    return 1;
}

// const char * GetAchievementDisplayAttribute(const char * pchName, const char * pchKey);
EXTERN int luasteam_UserStats_GetAchievementDisplayAttribute(lua_State *L) {
    const char *pchName = luaL_checkstring(L, 1);
    const char *pchKey = luaL_checkstring(L, 2);
    lua_pushstring(L, SteamUserStats()->GetAchievementDisplayAttribute(pchName, pchKey));
    return 1;
}

// bool IndicateAchievementProgress(const char * pchName, uint32 nCurProgress, uint32 nMaxProgress);
EXTERN int luasteam_UserStats_IndicateAchievementProgress(lua_State *L) {
    const char *pchName = luaL_checkstring(L, 1);
    uint32 nCurProgress = static_cast<uint32>(luaL_checkint(L, 2));
    uint32 nMaxProgress = static_cast<uint32>(luaL_checkint(L, 3));
    lua_pushboolean(L, SteamUserStats()->IndicateAchievementProgress(pchName, nCurProgress, nMaxProgress));
    return 1;
}

// uint32 GetNumAchievements();
EXTERN int luasteam_UserStats_GetNumAchievements(lua_State *L) {
    lua_pushinteger(L, SteamUserStats()->GetNumAchievements());
    return 1;
}

// const char * GetAchievementName(uint32 iAchievement);
EXTERN int luasteam_UserStats_GetAchievementName(lua_State *L) {
    uint32 iAchievement = static_cast<uint32>(luaL_checkint(L, 1));
    lua_pushstring(L, SteamUserStats()->GetAchievementName(iAchievement));
    return 1;
}

// SteamAPICall_t RequestUserStats(CSteamID steamIDUser);
EXTERN int luasteam_UserStats_RequestUserStats(lua_State *L) {
    CSteamID steamIDUser(luasteam::checkuint64(L, 1));
    luasteam::pushuint64(L, SteamUserStats()->RequestUserStats(steamIDUser));
    return 1;
}

// bool ResetAllStats(bool bAchievementsToo);
EXTERN int luasteam_UserStats_ResetAllStats(lua_State *L) {
    bool bAchievementsToo = lua_toboolean(L, 1);
    lua_pushboolean(L, SteamUserStats()->ResetAllStats(bAchievementsToo));
    return 1;
}

// SteamAPICall_t FindOrCreateLeaderboard(const char * pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType);
EXTERN int luasteam_UserStats_FindOrCreateLeaderboard(lua_State *L) {
    const char *pchLeaderboardName = luaL_checkstring(L, 1);
    ELeaderboardSortMethod eLeaderboardSortMethod = static_cast<ELeaderboardSortMethod>(luaL_checkint(L, 2));
    ELeaderboardDisplayType eLeaderboardDisplayType = static_cast<ELeaderboardDisplayType>(luaL_checkint(L, 3));
    luasteam::pushuint64(L, SteamUserStats()->FindOrCreateLeaderboard(pchLeaderboardName, eLeaderboardSortMethod, eLeaderboardDisplayType));
    return 1;
}

// SteamAPICall_t FindLeaderboard(const char * pchLeaderboardName);
EXTERN int luasteam_UserStats_FindLeaderboard(lua_State *L) {
    const char *pchLeaderboardName = luaL_checkstring(L, 1);
    luasteam::pushuint64(L, SteamUserStats()->FindLeaderboard(pchLeaderboardName));
    return 1;
}

// const char * GetLeaderboardName(SteamLeaderboard_t hSteamLeaderboard);
EXTERN int luasteam_UserStats_GetLeaderboardName(lua_State *L) {
    SteamLeaderboard_t hSteamLeaderboard = luasteam::checkuint64(L, 1);
    lua_pushstring(L, SteamUserStats()->GetLeaderboardName(hSteamLeaderboard));
    return 1;
}

// int GetLeaderboardEntryCount(SteamLeaderboard_t hSteamLeaderboard);
EXTERN int luasteam_UserStats_GetLeaderboardEntryCount(lua_State *L) {
    SteamLeaderboard_t hSteamLeaderboard = luasteam::checkuint64(L, 1);
    lua_pushinteger(L, SteamUserStats()->GetLeaderboardEntryCount(hSteamLeaderboard));
    return 1;
}

// ELeaderboardSortMethod GetLeaderboardSortMethod(SteamLeaderboard_t hSteamLeaderboard);
EXTERN int luasteam_UserStats_GetLeaderboardSortMethod(lua_State *L) {
    SteamLeaderboard_t hSteamLeaderboard = luasteam::checkuint64(L, 1);
    lua_pushinteger(L, SteamUserStats()->GetLeaderboardSortMethod(hSteamLeaderboard));
    return 1;
}

// ELeaderboardDisplayType GetLeaderboardDisplayType(SteamLeaderboard_t hSteamLeaderboard);
EXTERN int luasteam_UserStats_GetLeaderboardDisplayType(lua_State *L) {
    SteamLeaderboard_t hSteamLeaderboard = luasteam::checkuint64(L, 1);
    lua_pushinteger(L, SteamUserStats()->GetLeaderboardDisplayType(hSteamLeaderboard));
    return 1;
}

// SteamAPICall_t DownloadLeaderboardEntries(SteamLeaderboard_t hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, int nRangeStart, int nRangeEnd);
EXTERN int luasteam_UserStats_DownloadLeaderboardEntries(lua_State *L) {
    SteamLeaderboard_t hSteamLeaderboard = luasteam::checkuint64(L, 1);
    ELeaderboardDataRequest eLeaderboardDataRequest = static_cast<ELeaderboardDataRequest>(luaL_checkint(L, 2));
    int nRangeStart = static_cast<int>(luaL_checkint(L, 3));
    int nRangeEnd = static_cast<int>(luaL_checkint(L, 4));
    luasteam::pushuint64(L, SteamUserStats()->DownloadLeaderboardEntries(hSteamLeaderboard, eLeaderboardDataRequest, nRangeStart, nRangeEnd));
    return 1;
}

// SteamAPICall_t AttachLeaderboardUGC(SteamLeaderboard_t hSteamLeaderboard, UGCHandle_t hUGC);
EXTERN int luasteam_UserStats_AttachLeaderboardUGC(lua_State *L) {
    SteamLeaderboard_t hSteamLeaderboard = luasteam::checkuint64(L, 1);
    UGCHandle_t hUGC = luasteam::checkuint64(L, 2);
    luasteam::pushuint64(L, SteamUserStats()->AttachLeaderboardUGC(hSteamLeaderboard, hUGC));
    return 1;
}

// SteamAPICall_t GetNumberOfCurrentPlayers();
EXTERN int luasteam_UserStats_GetNumberOfCurrentPlayers(lua_State *L) {
    luasteam::pushuint64(L, SteamUserStats()->GetNumberOfCurrentPlayers());
    return 1;
}

// SteamAPICall_t RequestGlobalAchievementPercentages();
EXTERN int luasteam_UserStats_RequestGlobalAchievementPercentages(lua_State *L) {
    luasteam::pushuint64(L, SteamUserStats()->RequestGlobalAchievementPercentages());
    return 1;
}

// SteamAPICall_t RequestGlobalStats(int nHistoryDays);
EXTERN int luasteam_UserStats_RequestGlobalStats(lua_State *L) {
    int nHistoryDays = static_cast<int>(luaL_checkint(L, 1));
    luasteam::pushuint64(L, SteamUserStats()->RequestGlobalStats(nHistoryDays));
    return 1;
}

void register_UserStats_auto(lua_State *L) {
    add_func(L, "SetStat", luasteam_UserStats_SetStat);
    add_func(L, "SetAchievement", luasteam_UserStats_SetAchievement);
    add_func(L, "ClearAchievement", luasteam_UserStats_ClearAchievement);
    add_func(L, "StoreStats", luasteam_UserStats_StoreStats);
    add_func(L, "GetAchievementIcon", luasteam_UserStats_GetAchievementIcon);
    add_func(L, "GetAchievementDisplayAttribute", luasteam_UserStats_GetAchievementDisplayAttribute);
    add_func(L, "IndicateAchievementProgress", luasteam_UserStats_IndicateAchievementProgress);
    add_func(L, "GetNumAchievements", luasteam_UserStats_GetNumAchievements);
    add_func(L, "GetAchievementName", luasteam_UserStats_GetAchievementName);
    add_func(L, "RequestUserStats", luasteam_UserStats_RequestUserStats);
    add_func(L, "ResetAllStats", luasteam_UserStats_ResetAllStats);
    add_func(L, "FindOrCreateLeaderboard", luasteam_UserStats_FindOrCreateLeaderboard);
    add_func(L, "FindLeaderboard", luasteam_UserStats_FindLeaderboard);
    add_func(L, "GetLeaderboardName", luasteam_UserStats_GetLeaderboardName);
    add_func(L, "GetLeaderboardEntryCount", luasteam_UserStats_GetLeaderboardEntryCount);
    add_func(L, "GetLeaderboardSortMethod", luasteam_UserStats_GetLeaderboardSortMethod);
    add_func(L, "GetLeaderboardDisplayType", luasteam_UserStats_GetLeaderboardDisplayType);
    add_func(L, "DownloadLeaderboardEntries", luasteam_UserStats_DownloadLeaderboardEntries);
    add_func(L, "AttachLeaderboardUGC", luasteam_UserStats_AttachLeaderboardUGC);
    add_func(L, "GetNumberOfCurrentPlayers", luasteam_UserStats_GetNumberOfCurrentPlayers);
    add_func(L, "RequestGlobalAchievementPercentages", luasteam_UserStats_RequestGlobalAchievementPercentages);
    add_func(L, "RequestGlobalStats", luasteam_UserStats_RequestGlobalStats);
}

void add_UserStats_auto(lua_State *L) {
    lua_createtable(L, 0, 22);
    register_UserStats_auto(L);
    lua_pushvalue(L, -1);
    UserStats_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "UserStats");
}

} // namespace luasteam
