#include "user_stats.hpp"
#include "auto/auto.hpp"

// ==============================
// ======= SteamUserStats =======
// ==============================

using luasteam::CallResultListener;

namespace {

} // namespace

// Manually implemented because GetStat is overloaded in the Steam API
// bool GetStat(const char *pchName, int32 *pData);
EXTERN int luasteam_getStatInt(lua_State *L) {
    const char *stat_name = luaL_checkstring(L, 1);
    int stat_value;
    bool success = SteamUserStats()->GetStat(stat_name, &stat_value);
    lua_pushboolean(L, success);
    if (success) {
        lua_pushnumber(L, stat_value);
        return 2;
    } else {
        return 1;
    }
}

// Manually implemented because GetStat is overloaded in the Steam API
// bool GetStat(const char *pchName, float *pData);
EXTERN int luasteam_getStatFloat(lua_State *L) {
    const char *stat_name = luaL_checkstring(L, 1);
    float stat_value;
    bool success = SteamUserStats()->GetStat(stat_name, &stat_value);
    lua_pushboolean(L, success);
    if (success) {
        lua_pushnumber(L, stat_value);
        return 2;
    } else {
        return 1;
    }
}

// Manually implemented because SetStat is overloaded in the Steam API
// bool SetStat(const char *pchName, int32 *pData);
EXTERN int luasteam_setStatInt(lua_State *L) {
    const char *stat_name = luaL_checkstring(L, 1);
    const int stat_value = luaL_checkint(L, 2);
    bool success = SteamUserStats()->SetStat(stat_name, stat_value);
    lua_pushboolean(L, success);
    return 1;
}

// Manually implemented because SetStat is overloaded in the Steam API
// bool SetStat(const char *pchName, float *pData);
EXTERN int luasteam_setStatFloat(lua_State *L) {
    const char *stat_name = luaL_checkstring(L, 1);
    const float stat_value = luaL_checknumber(L, 2);
    bool success = SteamUserStats()->SetStat(stat_name, stat_value);
    lua_pushboolean(L, success);
    return 1;
}

// Manually implemented to handle the output parameter
// bool GetAchievement(const char *pchName, bool *pbAchieved );
EXTERN int luasteam_getAchievement(lua_State *L) {
    const char *ach_name = luaL_checkstring(L, 1);
    bool achieved = false;
    bool success = SteamUserStats()->GetAchievement(ach_name, &achieved);
    lua_pushboolean(L, success);
    if (success) {
        lua_pushboolean(L, achieved);
        return 2;
    } else {
        return 1;
    }
}

// Manually implemented to handle CallResult
// SteamAPICall_t FindLeaderboard( const char *pchLeaderboardName );
EXTERN int luasteam_findLeaderboard(lua_State *L) {
    const char *name = luaL_checkstring(L, 1);
    luaL_checktype(L, 2, LUA_TFUNCTION);
    auto *listener = new CallResultListener<LeaderboardFindResult_t>();
    listener->callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    SteamAPICall_t call = SteamUserStats()->FindLeaderboard(name);
    listener->call_result.Set(call, listener, &CallResultListener<LeaderboardFindResult_t>::Result);
    return 0;
}

// Manually implemented to handle CallResult
// SteamAPICall_t FindOrCreateLeaderboard( const char *pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType );
EXTERN int luasteam_findOrCreateLeaderboard(lua_State *L) {
    const char *name = luaL_checkstring(L, 1);
    ELeaderboardSortMethod sort_method = static_cast<ELeaderboardSortMethod>(luaL_checkint(L, 2));
    ELeaderboardDisplayType display_type = static_cast<ELeaderboardDisplayType>(luaL_checkint(L, 3));
    luaL_checktype(L, 4, LUA_TFUNCTION);
    auto *listener = new CallResultListener<LeaderboardFindResult_t>();
    listener->callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    SteamAPICall_t call = SteamUserStats()->FindOrCreateLeaderboard(name, sort_method, display_type);
    listener->call_result.Set(call, listener, &CallResultListener<LeaderboardFindResult_t>::Result);
    return 0;
}

// Manually implemented to map enum to integer
// ELeaderboardDisplayType GetLeaderboardDisplayType( SteamLeaderboard_t hSteamLeaderboard );
EXTERN int luasteam_getLeaderboardDisplayType(lua_State *L) {
    SteamLeaderboard_t leaderboard = luasteam::checkuint64(L, 1);
    ELeaderboardDisplayType m = SteamUserStats()->GetLeaderboardDisplayType(leaderboard);
    lua_pushinteger(L, m);
    return 1;
}

// Manually implemented to map enum to integer
// ELeaderboardSortMethod GetLeaderboardSortMethod( SteamLeaderboard_t hSteamLeaderboard );
EXTERN int luasteam_getLeaderboardSortMethod(lua_State *L) {
    SteamLeaderboard_t leaderboard = luasteam::checkuint64(L, 1);
    ELeaderboardSortMethod m = SteamUserStats()->GetLeaderboardSortMethod(leaderboard);
    lua_pushinteger(L, m);
    return 1;
}

// Manually implemented to handle null return value
// const char * GetLeaderboardName( SteamLeaderboard_t hSteamLeaderboard );
EXTERN int luasteam_getLeaderboardName(lua_State *L) {
    SteamLeaderboard_t leaderboard = luasteam::checkuint64(L, 1);
    const char *name = SteamUserStats()->GetLeaderboardName(leaderboard);
    if (name == nullptr || *name == '\0') {
        lua_pushnil(L);
    } else {
        lua_pushstring(L, name);
    }
    return 1;
}

// Manually implemented to handle CallResult and buffer handling
EXTERN int luasteam_uploadLeaderboardScore(lua_State *L) {
    SteamLeaderboard_t leaderboard = luasteam::checkuint64(L, 1);
    ELeaderboardUploadScoreMethod upload_method = static_cast<ELeaderboardUploadScoreMethod>(luaL_checkint(L, 2));
    int32 score = luaL_checkint(L, 3);
    size_t size;
    const char *data = luaL_optlstring(L, 4, nullptr, &size);
    luaL_argcheck(L, data == nullptr || (size % 4) == 0, 3, "length must be multiple of 4");
    luaL_checktype(L, 5, LUA_TFUNCTION);
    auto *listener = new CallResultListener<LeaderboardScoreUploaded_t>();
    listener->callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);

    // We're just using the string as a bunch of ints.
    const int32 *scoreDetails = reinterpret_cast<const int32 *>(data);

    SteamAPICall_t call = SteamUserStats()->UploadLeaderboardScore(leaderboard, upload_method, score, scoreDetails, data != nullptr ? size / 4 : 0);
    listener->call_result.Set(call, listener, &CallResultListener<LeaderboardScoreUploaded_t>::Result);
    return 0;
}

// Manually implemented to handle CallResult
EXTERN int luasteam_downloadLeaderboardEntries(lua_State *L) {
    SteamLeaderboard_t handle = luasteam::checkuint64(L, 1);
    ELeaderboardDataRequest data_request = static_cast<ELeaderboardDataRequest>(luaL_checkint(L, 2));
    int start = 0, end = 0;
    if (data_request != k_ELeaderboardDataRequestFriends) {
        start = luaL_checkint(L, 3);
        end = luaL_checkint(L, 4);
        luaL_checktype(L, 5, LUA_TFUNCTION);
    } else {
        luaL_checktype(L, 3, LUA_TFUNCTION);
    }
    auto *listener = new CallResultListener<LeaderboardScoresDownloaded_t>();
    listener->callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);

    SteamAPICall_t call = SteamUserStats()->DownloadLeaderboardEntries(handle, data_request, start, end);
    listener->call_result.Set(call, listener, &CallResultListener<LeaderboardScoresDownloaded_t>::Result);
    return 0;
}

namespace luasteam {

void add_user_stats(lua_State *L) {
    lua_createtable(L, 0, 11);
    register_UserStats_auto(L);
    add_func(L, "getStatInt", luasteam_getStatInt);
    add_func(L, "getStatFloat", luasteam_getStatFloat);
    add_func(L, "setStatInt", luasteam_setStatInt);
    add_func(L, "setStatFloat", luasteam_setStatFloat);
    add_func(L, "getAchievement", luasteam_getAchievement);
    add_func(L, "findLeaderboard", luasteam_findLeaderboard);
    add_func(L, "findOrCreateLeaderboard", luasteam_findOrCreateLeaderboard);
    add_func(L, "getLeaderboardName", luasteam_getLeaderboardName);
    add_func(L, "getLeaderboardSortMethod", luasteam_getLeaderboardSortMethod);
    add_func(L, "getLeaderboardDisplayType", luasteam_getLeaderboardDisplayType);
    add_func(L, "uploadLeaderboardScore", luasteam_uploadLeaderboardScore);
    add_func(L, "downloadLeaderboardEntries", luasteam_downloadLeaderboardEntries);
    lua_pushvalue(L, -1);
    UserStats_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "userStats");
}

void init_user_stats(lua_State *L) { init_UserStats_auto(L); }

void shutdown_user_stats(lua_State *L) {
    shutdown_UserStats_auto(L);
}

} // namespace luasteam
