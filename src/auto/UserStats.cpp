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
    lua_getfield(L, -1, "OnUserStatsReceived");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        luasteam::pushuint64(L, data->m_nGameID);
        lua_setfield(L, -2, "m_nGameID");
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "m_eResult");
        luasteam::pushuint64(L, data->m_steamIDUser.ConvertToUint64());
        lua_setfield(L, -2, "m_steamIDUser");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnUserStatsStored(UserStatsStored_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UserStats_ref);
    lua_getfield(L, -1, "OnUserStatsStored");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        luasteam::pushuint64(L, data->m_nGameID);
        lua_setfield(L, -2, "m_nGameID");
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "m_eResult");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnUserAchievementStored(UserAchievementStored_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UserStats_ref);
    lua_getfield(L, -1, "OnUserAchievementStored");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 5);
        luasteam::pushuint64(L, data->m_nGameID);
        lua_setfield(L, -2, "m_nGameID");
        lua_pushboolean(L, data->m_bGroupAchievement);
        lua_setfield(L, -2, "m_bGroupAchievement");
        lua_pushstring(L, reinterpret_cast<const char*>(data->m_rgchAchievementName));
        lua_setfield(L, -2, "m_rgchAchievementName");
        lua_pushinteger(L, data->m_nCurProgress);
        lua_setfield(L, -2, "m_nCurProgress");
        lua_pushinteger(L, data->m_nMaxProgress);
        lua_setfield(L, -2, "m_nMaxProgress");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnLeaderboardFindResult(LeaderboardFindResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UserStats_ref);
    lua_getfield(L, -1, "OnLeaderboardFindResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        luasteam::pushuint64(L, data->m_hSteamLeaderboard);
        lua_setfield(L, -2, "m_hSteamLeaderboard");
        lua_pushinteger(L, data->m_bLeaderboardFound);
        lua_setfield(L, -2, "m_bLeaderboardFound");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnLeaderboardScoresDownloaded(LeaderboardScoresDownloaded_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UserStats_ref);
    lua_getfield(L, -1, "OnLeaderboardScoresDownloaded");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        luasteam::pushuint64(L, data->m_hSteamLeaderboard);
        lua_setfield(L, -2, "m_hSteamLeaderboard");
        luasteam::pushuint64(L, data->m_hSteamLeaderboardEntries);
        lua_setfield(L, -2, "m_hSteamLeaderboardEntries");
        lua_pushinteger(L, data->m_cEntryCount);
        lua_setfield(L, -2, "m_cEntryCount");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnLeaderboardScoreUploaded(LeaderboardScoreUploaded_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UserStats_ref);
    lua_getfield(L, -1, "OnLeaderboardScoreUploaded");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 6);
        lua_pushinteger(L, data->m_bSuccess);
        lua_setfield(L, -2, "m_bSuccess");
        luasteam::pushuint64(L, data->m_hSteamLeaderboard);
        lua_setfield(L, -2, "m_hSteamLeaderboard");
        lua_pushinteger(L, data->m_nScore);
        lua_setfield(L, -2, "m_nScore");
        lua_pushinteger(L, data->m_bScoreChanged);
        lua_setfield(L, -2, "m_bScoreChanged");
        lua_pushinteger(L, data->m_nGlobalRankNew);
        lua_setfield(L, -2, "m_nGlobalRankNew");
        lua_pushinteger(L, data->m_nGlobalRankPrevious);
        lua_setfield(L, -2, "m_nGlobalRankPrevious");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnNumberOfCurrentPlayers(NumberOfCurrentPlayers_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UserStats_ref);
    lua_getfield(L, -1, "OnNumberOfCurrentPlayers");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->m_bSuccess);
        lua_setfield(L, -2, "m_bSuccess");
        lua_pushinteger(L, data->m_cPlayers);
        lua_setfield(L, -2, "m_cPlayers");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnUserStatsUnloaded(UserStatsUnloaded_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UserStats_ref);
    lua_getfield(L, -1, "OnUserStatsUnloaded");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        luasteam::pushuint64(L, data->m_steamIDUser.ConvertToUint64());
        lua_setfield(L, -2, "m_steamIDUser");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnUserAchievementIconFetched(UserAchievementIconFetched_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UserStats_ref);
    lua_getfield(L, -1, "OnUserAchievementIconFetched");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        luasteam::pushuint64(L, data->m_nGameID.ToUint64());
        lua_setfield(L, -2, "m_nGameID");
        lua_pushstring(L, reinterpret_cast<const char*>(data->m_rgchAchievementName));
        lua_setfield(L, -2, "m_rgchAchievementName");
        lua_pushboolean(L, data->m_bAchieved);
        lua_setfield(L, -2, "m_bAchieved");
        lua_pushinteger(L, data->m_nIconHandle);
        lua_setfield(L, -2, "m_nIconHandle");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGlobalAchievementPercentagesReady(GlobalAchievementPercentagesReady_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UserStats_ref);
    lua_getfield(L, -1, "OnGlobalAchievementPercentagesReady");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        luasteam::pushuint64(L, data->m_nGameID);
        lua_setfield(L, -2, "m_nGameID");
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "m_eResult");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnLeaderboardUGCSet(LeaderboardUGCSet_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UserStats_ref);
    lua_getfield(L, -1, "OnLeaderboardUGCSet");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "m_eResult");
        luasteam::pushuint64(L, data->m_hSteamLeaderboard);
        lua_setfield(L, -2, "m_hSteamLeaderboard");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGlobalStatsReceived(GlobalStatsReceived_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UserStats_ref);
    lua_getfield(L, -1, "OnGlobalStatsReceived");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        luasteam::pushuint64(L, data->m_nGameID);
        lua_setfield(L, -2, "m_nGameID");
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "m_eResult");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGSStatsUnloaded(GSStatsUnloaded_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UserStats_ref);
    lua_getfield(L, -1, "OnGSStatsUnloaded");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        luasteam::pushuint64(L, data->m_steamIDUser.ConvertToUint64());
        lua_setfield(L, -2, "m_steamIDUser");
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


// bool GetAchievement(const char * pchName, bool * pbAchieved);
EXTERN int luasteam_UserStats_GetAchievement(lua_State *L) {
    const char *pchName = luaL_checkstring(L, 1);
    bool pbAchieved;    bool __ret = SteamUserStats()->GetAchievement(pchName, &pbAchieved);
    lua_pushboolean(L, __ret);
    lua_pushboolean(L, pbAchieved);
    return 2;
}

// bool SetAchievement(const char * pchName);
EXTERN int luasteam_UserStats_SetAchievement(lua_State *L) {
    const char *pchName = luaL_checkstring(L, 1);
    bool __ret = SteamUserStats()->SetAchievement(pchName);
    lua_pushboolean(L, __ret);
    return 1;
}

// bool ClearAchievement(const char * pchName);
EXTERN int luasteam_UserStats_ClearAchievement(lua_State *L) {
    const char *pchName = luaL_checkstring(L, 1);
    bool __ret = SteamUserStats()->ClearAchievement(pchName);
    lua_pushboolean(L, __ret);
    return 1;
}

// bool GetAchievementAndUnlockTime(const char * pchName, bool * pbAchieved, uint32 * punUnlockTime);
EXTERN int luasteam_UserStats_GetAchievementAndUnlockTime(lua_State *L) {
    const char *pchName = luaL_checkstring(L, 1);
    bool pbAchieved;    uint32 punUnlockTime;    bool __ret = SteamUserStats()->GetAchievementAndUnlockTime(pchName, &pbAchieved, &punUnlockTime);
    lua_pushboolean(L, __ret);
    lua_pushboolean(L, pbAchieved);
    lua_pushinteger(L, punUnlockTime);
    return 3;
}

// bool StoreStats();
EXTERN int luasteam_UserStats_StoreStats(lua_State *L) {
    bool __ret = SteamUserStats()->StoreStats();
    lua_pushboolean(L, __ret);
    return 1;
}

// int GetAchievementIcon(const char * pchName);
EXTERN int luasteam_UserStats_GetAchievementIcon(lua_State *L) {
    const char *pchName = luaL_checkstring(L, 1);
    int __ret = SteamUserStats()->GetAchievementIcon(pchName);
    lua_pushinteger(L, __ret);
    return 1;
}

// const char * GetAchievementDisplayAttribute(const char * pchName, const char * pchKey);
EXTERN int luasteam_UserStats_GetAchievementDisplayAttribute(lua_State *L) {
    const char *pchName = luaL_checkstring(L, 1);
    const char *pchKey = luaL_checkstring(L, 2);
    const char * __ret = SteamUserStats()->GetAchievementDisplayAttribute(pchName, pchKey);
    lua_pushstring(L, reinterpret_cast<const char*>(__ret));
    return 1;
}

// bool IndicateAchievementProgress(const char * pchName, uint32 nCurProgress, uint32 nMaxProgress);
EXTERN int luasteam_UserStats_IndicateAchievementProgress(lua_State *L) {
    const char *pchName = luaL_checkstring(L, 1);
    uint32 nCurProgress = static_cast<uint32>(luaL_checkint(L, 2));
    uint32 nMaxProgress = static_cast<uint32>(luaL_checkint(L, 3));
    bool __ret = SteamUserStats()->IndicateAchievementProgress(pchName, nCurProgress, nMaxProgress);
    lua_pushboolean(L, __ret);
    return 1;
}

// uint32 GetNumAchievements();
EXTERN int luasteam_UserStats_GetNumAchievements(lua_State *L) {
    uint32 __ret = SteamUserStats()->GetNumAchievements();
    lua_pushinteger(L, __ret);
    return 1;
}

// const char * GetAchievementName(uint32 iAchievement);
EXTERN int luasteam_UserStats_GetAchievementName(lua_State *L) {
    uint32 iAchievement = static_cast<uint32>(luaL_checkint(L, 1));
    const char * __ret = SteamUserStats()->GetAchievementName(iAchievement);
    lua_pushstring(L, reinterpret_cast<const char*>(__ret));
    return 1;
}

// SteamAPICall_t RequestUserStats(CSteamID steamIDUser);
EXTERN int luasteam_UserStats_RequestUserStats(lua_State *L) {
    CSteamID steamIDUser(luasteam::checkuint64(L, 1));
    SteamAPICall_t __ret = SteamUserStats()->RequestUserStats(steamIDUser);
    luasteam::pushuint64(L, __ret);
    return 1;
}

// bool GetUserAchievement(CSteamID steamIDUser, const char * pchName, bool * pbAchieved);
EXTERN int luasteam_UserStats_GetUserAchievement(lua_State *L) {
    CSteamID steamIDUser(luasteam::checkuint64(L, 1));
    const char *pchName = luaL_checkstring(L, 2);
    bool pbAchieved;    bool __ret = SteamUserStats()->GetUserAchievement(steamIDUser, pchName, &pbAchieved);
    lua_pushboolean(L, __ret);
    lua_pushboolean(L, pbAchieved);
    return 2;
}

// bool GetUserAchievementAndUnlockTime(CSteamID steamIDUser, const char * pchName, bool * pbAchieved, uint32 * punUnlockTime);
EXTERN int luasteam_UserStats_GetUserAchievementAndUnlockTime(lua_State *L) {
    CSteamID steamIDUser(luasteam::checkuint64(L, 1));
    const char *pchName = luaL_checkstring(L, 2);
    bool pbAchieved;    uint32 punUnlockTime;    bool __ret = SteamUserStats()->GetUserAchievementAndUnlockTime(steamIDUser, pchName, &pbAchieved, &punUnlockTime);
    lua_pushboolean(L, __ret);
    lua_pushboolean(L, pbAchieved);
    lua_pushinteger(L, punUnlockTime);
    return 3;
}

// bool ResetAllStats(bool bAchievementsToo);
EXTERN int luasteam_UserStats_ResetAllStats(lua_State *L) {
    bool bAchievementsToo = lua_toboolean(L, 1);
    bool __ret = SteamUserStats()->ResetAllStats(bAchievementsToo);
    lua_pushboolean(L, __ret);
    return 1;
}

// SteamAPICall_t FindOrCreateLeaderboard(const char * pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType);
EXTERN int luasteam_UserStats_FindOrCreateLeaderboard(lua_State *L) {
    const char *pchLeaderboardName = luaL_checkstring(L, 1);
    ELeaderboardSortMethod eLeaderboardSortMethod = static_cast<ELeaderboardSortMethod>(luaL_checkint(L, 2));
    ELeaderboardDisplayType eLeaderboardDisplayType = static_cast<ELeaderboardDisplayType>(luaL_checkint(L, 3));
    SteamAPICall_t __ret = SteamUserStats()->FindOrCreateLeaderboard(pchLeaderboardName, eLeaderboardSortMethod, eLeaderboardDisplayType);
    luasteam::pushuint64(L, __ret);
    return 1;
}

// SteamAPICall_t FindLeaderboard(const char * pchLeaderboardName);
EXTERN int luasteam_UserStats_FindLeaderboard(lua_State *L) {
    const char *pchLeaderboardName = luaL_checkstring(L, 1);
    SteamAPICall_t __ret = SteamUserStats()->FindLeaderboard(pchLeaderboardName);
    luasteam::pushuint64(L, __ret);
    return 1;
}

// const char * GetLeaderboardName(SteamLeaderboard_t hSteamLeaderboard);
EXTERN int luasteam_UserStats_GetLeaderboardName(lua_State *L) {
    SteamLeaderboard_t hSteamLeaderboard(luasteam::checkuint64(L, 1));
    const char * __ret = SteamUserStats()->GetLeaderboardName(hSteamLeaderboard);
    lua_pushstring(L, reinterpret_cast<const char*>(__ret));
    return 1;
}

// int GetLeaderboardEntryCount(SteamLeaderboard_t hSteamLeaderboard);
EXTERN int luasteam_UserStats_GetLeaderboardEntryCount(lua_State *L) {
    SteamLeaderboard_t hSteamLeaderboard(luasteam::checkuint64(L, 1));
    int __ret = SteamUserStats()->GetLeaderboardEntryCount(hSteamLeaderboard);
    lua_pushinteger(L, __ret);
    return 1;
}

// ELeaderboardSortMethod GetLeaderboardSortMethod(SteamLeaderboard_t hSteamLeaderboard);
EXTERN int luasteam_UserStats_GetLeaderboardSortMethod(lua_State *L) {
    SteamLeaderboard_t hSteamLeaderboard(luasteam::checkuint64(L, 1));
    ELeaderboardSortMethod __ret = SteamUserStats()->GetLeaderboardSortMethod(hSteamLeaderboard);
    lua_pushinteger(L, __ret);
    return 1;
}

// ELeaderboardDisplayType GetLeaderboardDisplayType(SteamLeaderboard_t hSteamLeaderboard);
EXTERN int luasteam_UserStats_GetLeaderboardDisplayType(lua_State *L) {
    SteamLeaderboard_t hSteamLeaderboard(luasteam::checkuint64(L, 1));
    ELeaderboardDisplayType __ret = SteamUserStats()->GetLeaderboardDisplayType(hSteamLeaderboard);
    lua_pushinteger(L, __ret);
    return 1;
}

// SteamAPICall_t DownloadLeaderboardEntries(SteamLeaderboard_t hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, int nRangeStart, int nRangeEnd);
EXTERN int luasteam_UserStats_DownloadLeaderboardEntries(lua_State *L) {
    SteamLeaderboard_t hSteamLeaderboard(luasteam::checkuint64(L, 1));
    ELeaderboardDataRequest eLeaderboardDataRequest = static_cast<ELeaderboardDataRequest>(luaL_checkint(L, 2));
    int nRangeStart = static_cast<int>(luaL_checkint(L, 3));
    int nRangeEnd = static_cast<int>(luaL_checkint(L, 4));
    SteamAPICall_t __ret = SteamUserStats()->DownloadLeaderboardEntries(hSteamLeaderboard, eLeaderboardDataRequest, nRangeStart, nRangeEnd);
    luasteam::pushuint64(L, __ret);
    return 1;
}

// SteamAPICall_t AttachLeaderboardUGC(SteamLeaderboard_t hSteamLeaderboard, UGCHandle_t hUGC);
EXTERN int luasteam_UserStats_AttachLeaderboardUGC(lua_State *L) {
    SteamLeaderboard_t hSteamLeaderboard(luasteam::checkuint64(L, 1));
    UGCHandle_t hUGC(luasteam::checkuint64(L, 2));
    SteamAPICall_t __ret = SteamUserStats()->AttachLeaderboardUGC(hSteamLeaderboard, hUGC);
    luasteam::pushuint64(L, __ret);
    return 1;
}

// SteamAPICall_t GetNumberOfCurrentPlayers();
EXTERN int luasteam_UserStats_GetNumberOfCurrentPlayers(lua_State *L) {
    SteamAPICall_t __ret = SteamUserStats()->GetNumberOfCurrentPlayers();
    luasteam::pushuint64(L, __ret);
    return 1;
}

// SteamAPICall_t RequestGlobalAchievementPercentages();
EXTERN int luasteam_UserStats_RequestGlobalAchievementPercentages(lua_State *L) {
    SteamAPICall_t __ret = SteamUserStats()->RequestGlobalAchievementPercentages();
    luasteam::pushuint64(L, __ret);
    return 1;
}

// int GetMostAchievedAchievementInfo(char * pchName, uint32 unNameBufLen, float * pflPercent, bool * pbAchieved);
EXTERN int luasteam_UserStats_GetMostAchievedAchievementInfo(lua_State *L) {
    uint32 unNameBufLen = luaL_checkint(L, 1);
    std::vector<char> pchName(unNameBufLen);
    float pflPercent;    bool pbAchieved;    int __ret = SteamUserStats()->GetMostAchievedAchievementInfo(pchName.data(), unNameBufLen, &pflPercent, &pbAchieved);
    lua_pushinteger(L, __ret);
    lua_pushstring(L, reinterpret_cast<const char*>(pchName.data()));
    lua_pushnumber(L, pflPercent);
    lua_pushboolean(L, pbAchieved);
    return 3;
}

// int GetNextMostAchievedAchievementInfo(int iIteratorPrevious, char * pchName, uint32 unNameBufLen, float * pflPercent, bool * pbAchieved);
EXTERN int luasteam_UserStats_GetNextMostAchievedAchievementInfo(lua_State *L) {
    int iIteratorPrevious = static_cast<int>(luaL_checkint(L, 1));
    uint32 unNameBufLen = luaL_checkint(L, 2);
    std::vector<char> pchName(unNameBufLen);
    float pflPercent;    bool pbAchieved;    int __ret = SteamUserStats()->GetNextMostAchievedAchievementInfo(iIteratorPrevious, pchName.data(), unNameBufLen, &pflPercent, &pbAchieved);
    lua_pushinteger(L, __ret);
    lua_pushstring(L, reinterpret_cast<const char*>(pchName.data()));
    lua_pushnumber(L, pflPercent);
    lua_pushboolean(L, pbAchieved);
    return 3;
}

// bool GetAchievementAchievedPercent(const char * pchName, float * pflPercent);
EXTERN int luasteam_UserStats_GetAchievementAchievedPercent(lua_State *L) {
    const char *pchName = luaL_checkstring(L, 1);
    float pflPercent;    bool __ret = SteamUserStats()->GetAchievementAchievedPercent(pchName, &pflPercent);
    lua_pushboolean(L, __ret);
    lua_pushnumber(L, pflPercent);
    return 2;
}

// SteamAPICall_t RequestGlobalStats(int nHistoryDays);
EXTERN int luasteam_UserStats_RequestGlobalStats(lua_State *L) {
    int nHistoryDays = static_cast<int>(luaL_checkint(L, 1));
    SteamAPICall_t __ret = SteamUserStats()->RequestGlobalStats(nHistoryDays);
    luasteam::pushuint64(L, __ret);
    return 1;
}

void register_UserStats_auto(lua_State *L) {
    add_func(L, "GetAchievement", luasteam_UserStats_GetAchievement);
    add_func(L, "SetAchievement", luasteam_UserStats_SetAchievement);
    add_func(L, "ClearAchievement", luasteam_UserStats_ClearAchievement);
    add_func(L, "GetAchievementAndUnlockTime", luasteam_UserStats_GetAchievementAndUnlockTime);
    add_func(L, "StoreStats", luasteam_UserStats_StoreStats);
    add_func(L, "GetAchievementIcon", luasteam_UserStats_GetAchievementIcon);
    add_func(L, "GetAchievementDisplayAttribute", luasteam_UserStats_GetAchievementDisplayAttribute);
    add_func(L, "IndicateAchievementProgress", luasteam_UserStats_IndicateAchievementProgress);
    add_func(L, "GetNumAchievements", luasteam_UserStats_GetNumAchievements);
    add_func(L, "GetAchievementName", luasteam_UserStats_GetAchievementName);
    add_func(L, "RequestUserStats", luasteam_UserStats_RequestUserStats);
    add_func(L, "GetUserAchievement", luasteam_UserStats_GetUserAchievement);
    add_func(L, "GetUserAchievementAndUnlockTime", luasteam_UserStats_GetUserAchievementAndUnlockTime);
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
    add_func(L, "GetMostAchievedAchievementInfo", luasteam_UserStats_GetMostAchievedAchievementInfo);
    add_func(L, "GetNextMostAchievedAchievementInfo", luasteam_UserStats_GetNextMostAchievedAchievementInfo);
    add_func(L, "GetAchievementAchievedPercent", luasteam_UserStats_GetAchievementAchievedPercent);
    add_func(L, "RequestGlobalStats", luasteam_UserStats_RequestGlobalStats);
}

void add_UserStats_auto(lua_State *L) {
    lua_createtable(L, 0, 28);
    register_UserStats_auto(L);
    lua_pushvalue(L, -1);
    UserStats_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "UserStats");
}

} // namespace luasteam
