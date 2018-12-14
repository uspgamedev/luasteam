#include "sdk/public/steam/steam_api.h"
#include <cstdio>
#include <string>

#ifdef _WIN32
#    define EXTERN extern "C" __declspec(dllexport)
#else
#    define EXTERN extern "C"
#endif

extern "C" {
#include <lauxlib.h>
#include <lua.h>
}

namespace {

lua_State *global_lua_state = nullptr;
class SteamFriendsListener;
SteamFriendsListener *friends_listener = nullptr;
int friends_ref = LUA_NOREF;
class SteamUserStatsListener;
SteamUserStatsListener *userStats_listener = nullptr;
int userStats_ref = LUA_NOREF;

int uint64Metatable_ref = LUA_NOREF;

// using userdata since Lua's number can't safely hold 64-bit integers
inline void pushuint64(lua_State *L, uint64 v) {
    uint64 *ptr = reinterpret_cast<uint64 *>(lua_newuserdata(L, 8));
    *ptr = v;
    lua_rawgeti(L, LUA_REGISTRYINDEX, uint64Metatable_ref);
    lua_setmetatable(L, -2);
}

inline uint64 checkuint64(lua_State *L, int nParam) {
    luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "must be userdata");
    lua_rawgeti(L, LUA_REGISTRYINDEX, uint64Metatable_ref);
    lua_getmetatable(L, nParam);
    luaL_argcheck(L, lua_rawequal(L, -2, -1), nParam, "must be uint64");
    lua_pop(L, 2);
    uint64 *ptr = reinterpret_cast<uint64 *>(lua_touserdata(L, nParam));
    return *ptr;
}

} // namespace

// ==============================
// ======= SteamUserStats =======
// ==============================

namespace {

const char *sort_methods[] = {"Ascending", "Descending", nullptr};
const char *display_types[] = {"Numeric", "TimeSeconds", "TimeMilliSeconds", nullptr};
const char *upload_methods[] = {"KeepBest", "ForceUpdate", nullptr};
const char *data_requests[] = {"Global", "GlobalAroundUser", "Friends", nullptr};

class SteamUserStatsListener {
  public:
    // LeaderboardFindResult
    int leaderboardFindResultCallback_ref = LUA_NOREF;
    void OnLeaderboardFindResult(LeaderboardFindResult_t *data, bool io_fail);
    CCallResult<SteamUserStatsListener, LeaderboardFindResult_t> leaderboardFindResult;
    // LeaderboardScoreUploaded
    int leaderboardScoreUploadedCallback_ref = LUA_NOREF;
    void OnLeaderboardScoreUploaded(LeaderboardScoreUploaded_t *data, bool io_fail);
    CCallResult<SteamUserStatsListener, LeaderboardScoreUploaded_t> leaderboardScoreUploaded;
    // LeaderboardScoresDownloaded
    int leaderboardScoresDownloadedCallback_ref = LUA_NOREF;
    void OnLeaderboardScoresDownloaded(LeaderboardScoresDownloaded_t *data, bool io_fail);
    CCallResult<SteamUserStatsListener, LeaderboardScoresDownloaded_t> leaderboardScoresDownloaded;
};

void SteamUserStatsListener::OnLeaderboardFindResult(LeaderboardFindResult_t *data, bool io_fail) {
    lua_State *L = global_lua_state;
    // getting stored callback function
    lua_rawgeti(L, LUA_REGISTRYINDEX, leaderboardFindResultCallback_ref);
    luaL_unref(L, LUA_REGISTRYINDEX, leaderboardFindResultCallback_ref);
    leaderboardFindResultCallback_ref = LUA_NOREF;
    // calling function
    if (io_fail)
        lua_pushnil(L);
    else {
        lua_createtable(L, 0, 2);
        pushuint64(L, data->m_hSteamLeaderboard);
        lua_setfield(L, -2, "steamLeaderboard");
        lua_pushboolean(L, data->m_bLeaderboardFound != 0);
        lua_setfield(L, -2, "leaderboardFound");
    }
    lua_pushboolean(L, io_fail);
    lua_call(L, 2, 0);
}

void SteamUserStatsListener::OnLeaderboardScoreUploaded(LeaderboardScoreUploaded_t *data, bool io_fail) {
    lua_State *L = global_lua_state;
    // getting stored callback function
    lua_rawgeti(L, LUA_REGISTRYINDEX, leaderboardScoreUploadedCallback_ref);
    luaL_unref(L, LUA_REGISTRYINDEX, leaderboardScoreUploadedCallback_ref);
    leaderboardScoreUploadedCallback_ref = LUA_NOREF;
    // calling function
    if (io_fail)
        lua_pushnil(L);
    else {
        lua_createtable(L, 0, 2);
        lua_pushboolean(L, data->m_bSuccess != 0);
        lua_setfield(L, -2, "success");
        pushuint64(L, data->m_hSteamLeaderboard);
        lua_setfield(L, -2, "steamLeaderboard");
        lua_pushnumber(L, data->m_nScore);
        lua_setfield(L, -2, "score");
        lua_pushboolean(L, data->m_bScoreChanged != 0);
        lua_setfield(L, -2, "scoreChanged");
        lua_pushnumber(L, data->m_nGlobalRankNew);
        lua_setfield(L, -2, "globalRankNew");
        lua_pushnumber(L, data->m_nGlobalRankPrevious);
        lua_setfield(L, -2, "globalRankPrevious");
    }
    lua_pushboolean(L, io_fail);
    lua_call(L, 2, 0);
}

void SteamUserStatsListener::OnLeaderboardScoresDownloaded(LeaderboardScoresDownloaded_t *data, bool io_fail) {
    lua_State *L = global_lua_state;
    // getting store callback function
    lua_rawgeti(L, LUA_REGISTRYINDEX, leaderboardScoresDownloadedCallback_ref);
    luaL_unref(L, LUA_REGISTRYINDEX, leaderboardScoresDownloadedCallback_ref);
    leaderboardScoresDownloadedCallback_ref = LUA_NOREF;
    // calling function
    if (io_fail)
        lua_pushnil(L);
    else {
        lua_createtable(L, data->m_cEntryCount, 0);
        LeaderboardEntry_t entry;
        int32 details[65];
        int count = 0;
        for (int i = 0; i < data->m_cEntryCount; i++) {
            bool success = SteamUserStats()->GetDownloadedLeaderboardEntry(data->m_hSteamLeaderboardEntries, i, &entry, details, 65);
            if (success) {
                lua_createtable(L, 0, 5);
                pushuint64(L, entry.m_steamIDUser.ConvertToUint64());
                lua_setfield(L, -2, "steamIDUser");
                lua_pushnumber(L, entry.m_nGlobalRank);
                lua_setfield(L, -2, "globalRank");
                lua_pushnumber(L, entry.m_nScore);
                lua_setfield(L, -2, "score");
                lua_pushlstring(L, reinterpret_cast<const char *>(details), entry.m_cDetails * 4);
                lua_setfield(L, -2, "details");
                pushuint64(L, entry.m_hUGC);
                lua_setfield(L, -2, "UGC");
                lua_rawseti(L, -2, ++count);
            } else {
                // There really is no reason for this to fail, according to the API
                // But just in case, we ignore the entry
            }
        }
    }
    lua_pushboolean(L, io_fail);
    lua_call(L, 2, 0);
}

} // namespace

// bool GetAchievement(const char *pchName, bool *pbAchieved );
EXTERN int luasteam_getAchievement(lua_State *L) {
    const char *ach_name = luaL_checkstring(L, 1);
    bool achieved = false;
    bool success = SteamUserStats()->GetAchievement(ach_name, &achieved);
    lua_pushboolean(L, success);
    if(success) {
        lua_pushboolean(L, achieved);
        return 2;
    } else
        return 1;
}

// bool SetAchievement( const char *pchName );
EXTERN int luasteam_setAchievement(lua_State *L) {
    const char *ach_name = luaL_checkstring(L, 1);
    bool success = SteamUserStats()->SetAchievement(ach_name);
    lua_pushboolean(L, success);
    return 1;
}

// bool ResetAllStats( bool bAchievementsToo );
EXTERN int luasteam_resetAllStats(lua_State *L) {
    bool achievements_too = lua_toboolean(L, 1);
    bool success = SteamUserStats()->ResetAllStats(achievements_too);
    lua_pushboolean(L, success);
    return 1;
}

// bool StoreStats();
EXTERN int luasteam_storeStats(lua_State *L) {
    bool success = SteamUserStats()->StoreStats();
    lua_pushboolean(L, success);
    return 1;
}

// bool RequestCurrentStats();
EXTERN int luasteam_requestCurrentStats(lua_State *L) {
    bool success = SteamUserStats()->RequestCurrentStats();
    lua_pushboolean(L, success);
    return 1;
}

EXTERN int luasteam_findLeaderboard(lua_State *L) {
    const char *name = luaL_checkstring(L, 1);
    luaL_checktype(L, 2, LUA_TFUNCTION);
    luaL_unref(L, LUA_REGISTRYINDEX, userStats_listener->leaderboardFindResultCallback_ref);
    userStats_listener->leaderboardFindResultCallback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    SteamAPICall_t call = SteamUserStats()->FindLeaderboard(name);
    userStats_listener->leaderboardFindResult.Set(call, userStats_listener, &SteamUserStatsListener::OnLeaderboardFindResult);
    return 0;
}

// SteamAPICall_t FindOrCreateLeaderboard( const char *pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType );
EXTERN int luasteam_findOrCreateLeaderboard(lua_State *L) {
    const char *name = luaL_checkstring(L, 1);
    int sort_method = luaL_checkoption(L, 2, nullptr, sort_methods) + 1;
    int display_type = luaL_checkoption(L, 3, nullptr, display_types) + 1;
    luaL_checktype(L, 4, LUA_TFUNCTION);
    luaL_unref(L, LUA_REGISTRYINDEX, userStats_listener->leaderboardFindResultCallback_ref);
    userStats_listener->leaderboardFindResultCallback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    SteamAPICall_t call = SteamUserStats()->FindOrCreateLeaderboard(name, static_cast<ELeaderboardSortMethod>(sort_method), static_cast<ELeaderboardDisplayType>(display_type));
    userStats_listener->leaderboardFindResult.Set(call, userStats_listener, &SteamUserStatsListener::OnLeaderboardFindResult);
    return 0;
}

// ELeaderboardSortMethod GetLeaderboardSortMethod( SteamLeaderboard_t hSteamLeaderboard );
EXTERN int luasteam_getLeaderboardDisplayType(lua_State *L) {
    SteamLeaderboard_t leaderboard = checkuint64(L, 1);
    ELeaderboardDisplayType m = SteamUserStats()->GetLeaderboardDisplayType(leaderboard);
    if (m == k_ELeaderboardDisplayTypeNone)
        lua_pushnil(L);
    else
        lua_pushstring(L, display_types[static_cast<int>(m) - 1]);
    return 1;
}

// ELeaderboardSortMethod GetLeaderboardSortMethod( SteamLeaderboard_t hSteamLeaderboard );
EXTERN int luasteam_getLeaderboardSortMethod(lua_State *L) {
    SteamLeaderboard_t leaderboard = checkuint64(L, 1);
    ELeaderboardSortMethod m = SteamUserStats()->GetLeaderboardSortMethod(leaderboard);
    if (m == k_ELeaderboardSortMethodNone)
        lua_pushnil(L);
    else
        lua_pushstring(L, sort_methods[static_cast<int>(m) - 1]);
    return 1;
}

// ELeaderboardSortMethod GetLeaderboardSortMethod( SteamLeaderboard_t hSteamLeaderboard );
EXTERN int luasteam_getLeaderboardEntryCount(lua_State *L) {
    SteamLeaderboard_t leaderboard = checkuint64(L, 1);
    int count = SteamUserStats()->GetLeaderboardEntryCount(leaderboard);
    lua_pushnumber(L, count);
    return 1;
}

// ELeaderboardSortMethod GetLeaderboardSortMethod( SteamLeaderboard_t hSteamLeaderboard );
EXTERN int luasteam_getLeaderboardName(lua_State *L) {
    SteamLeaderboard_t leaderboard = checkuint64(L, 1);
    const char *name = SteamUserStats()->GetLeaderboardName(leaderboard);
    if (name == nullptr || *name == '\0')
        lua_pushnil(L);
    else
        lua_pushstring(L, name);
    return 1;
}

EXTERN int luasteam_uploadLeaderboardScore(lua_State *L) {
    SteamLeaderboard_t leaderboard = checkuint64(L, 1);
    ELeaderboardUploadScoreMethod upload_method = static_cast<ELeaderboardUploadScoreMethod>(luaL_checkoption(L, 2, nullptr, upload_methods) + 1);
    int32 score = luaL_checkint(L, 3);
    size_t size;
    const char *data = luaL_optlstring(L, 4, nullptr, &size);
    luaL_argcheck(L, data == nullptr || (size % 4) == 0, 3, "length must be multiple of 4");
    luaL_checktype(L, 5, LUA_TFUNCTION);
    luaL_unref(L, LUA_REGISTRYINDEX, userStats_listener->leaderboardScoreUploadedCallback_ref);
    userStats_listener->leaderboardScoreUploadedCallback_ref = luaL_ref(L, LUA_REGISTRYINDEX);

    // We're just using the string as a bunch of ints.
    const int32 *scoreDetails = reinterpret_cast<const int32 *>(data);

    SteamAPICall_t call = SteamUserStats()->UploadLeaderboardScore(leaderboard, upload_method, score, scoreDetails, data != nullptr ? size / 4 : 0);
    userStats_listener->leaderboardScoreUploaded.Set(call, userStats_listener, &SteamUserStatsListener::OnLeaderboardScoreUploaded);
    return 0;
}

EXTERN int luasteam_downloadLeaderboardEntries(lua_State *L) {
    SteamLeaderboard_t handle = checkuint64(L, 1);
    ELeaderboardDataRequest data_request = static_cast<ELeaderboardDataRequest>(luaL_checkoption(L, 2, nullptr, data_requests));
    int start = 0, end = 0;
    if (data_request != k_ELeaderboardDataRequestFriends) {
        start = luaL_checkint(L, 3);
        end = luaL_checkint(L, 4);
        luaL_checktype(L, 5, LUA_TFUNCTION);
    } else
        luaL_checktype(L, 3, LUA_TFUNCTION);
    luaL_unref(L, LUA_REGISTRYINDEX, userStats_listener->leaderboardScoresDownloadedCallback_ref);
    userStats_listener->leaderboardScoresDownloadedCallback_ref = luaL_ref(L, LUA_REGISTRYINDEX);

    SteamAPICall_t call = SteamUserStats()->DownloadLeaderboardEntries(handle, data_request, start, end);
    userStats_listener->leaderboardScoresDownloaded.Set(call, userStats_listener, &SteamUserStatsListener::OnLeaderboardScoresDownloaded);
    return 0;
}

// ============================
// ======= SteamFriends =======
// ============================

namespace {

const char *dialog_types[] = {"friends", "community", "players", "settings", "officialgamegroup", "stats", "achievements", NULL};

class SteamFriendsListener {
  private:
    STEAM_CALLBACK(SteamFriendsListener, OnGameOverlayActivated, GameOverlayActivated_t);
};

void SteamFriendsListener::OnGameOverlayActivated(GameOverlayActivated_t *data) {
    lua_State *L = global_lua_state;
    if (!lua_checkstack(L, 3))
        return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, friends_ref);
    lua_getfield(L, -1, "onGameOverlayActivated");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushboolean(L, data->m_bActive);
        lua_setfield(L, -2, "active");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

} // namespace

// void ActivateGameOverlay( const char *pchDialog );
EXTERN int luasteam_activateGameOverlay(lua_State *L) {
    const char *dialog = dialog_types[luaL_checkoption(L, 1, NULL, dialog_types)];
    SteamFriends()->ActivateGameOverlay(dialog);
    return 0;
}

// void ActivateGameOverlayToWebPage( const char *pchURL );
EXTERN int luasteam_activateGameOverlayToWebPage(lua_State *L) {
    const char *url = luaL_checkstring(L, 1);
    SteamFriends()->ActivateGameOverlayToWebPage(url);
    return 0;
}

// const char * GetFriendPersonaName( CSteamID steamIDFriend );
EXTERN int luasteam_getFriendPersonaName(lua_State *L) {
    CSteamID id(checkuint64(L, 1));
    const char *name = SteamFriends()->GetFriendPersonaName(id);
    lua_pushstring(L, name);
    return 1;
}

// ========================
// ======= SteamAPI =======
// ========================

// bool SteamAPI_Init();
EXTERN int luasteam_init(lua_State *L) {
    bool success = SteamAPI_Init();
    if(!success)
        fprintf(stderr, "Couldn't connect to steam...\nDo you have Steam turned on?\nIf not running from steam, do you have a correct steam_appid.txt file?\n");
    lua_pushboolean(L, success);
    return 1;
}

// void SteamAPI_Shutdown();
EXTERN int luasteam_shutdown(lua_State *L) {
    SteamAPI_Shutdown();
    // Cleaning up
    global_lua_state = nullptr;
    luaL_unref(L, LUA_REGISTRYINDEX, friends_ref);
    friends_ref = LUA_NOREF;
    delete friends_listener;
    friends_listener = nullptr;
    luaL_unref(L, LUA_REGISTRYINDEX, uint64Metatable_ref);
    uint64Metatable_ref = LUA_NOREF;
    return 0;
}

// void SteamAPI_RunCallbacks();
EXTERN int luasteam_runCallbacks(lua_State *L) {
    SteamAPI_RunCallbacks();
    return 0;
}

// ====================================
// ======= End of API functions =======
// ====================================

namespace {

void add_func(lua_State *L, const char *name, lua_CFunction func) {
    lua_pushcfunction(L, func);
    lua_setfield(L, -2, name);
}

void add_base(lua_State *L) {
    add_func(L, "init", luasteam_init);
    add_func(L, "shutdown", luasteam_shutdown);
    add_func(L, "runCallbacks", luasteam_runCallbacks);
}

void add_user_stats(lua_State *L) {
    lua_createtable(L, 0, 13);
    add_func(L, "getAchievement", luasteam_getAchievement);
    add_func(L, "setAchievement", luasteam_setAchievement);
    add_func(L, "resetAllStats", luasteam_resetAllStats);
    add_func(L, "storeStats", luasteam_storeStats);
    add_func(L, "requestCurrentStats", luasteam_requestCurrentStats);
    add_func(L, "findLeaderboard", luasteam_findLeaderboard);
    add_func(L, "findOrCreateLeaderboard", luasteam_findOrCreateLeaderboard);
    add_func(L, "getLeaderboardEntryCount", luasteam_getLeaderboardEntryCount);
    add_func(L, "getLeaderboardName", luasteam_getLeaderboardName);
    add_func(L, "getLeaderboardSortMethod", luasteam_getLeaderboardSortMethod);
    add_func(L, "getLeaderboardDisplayType", luasteam_getLeaderboardDisplayType);
    add_func(L, "uploadLeaderboardScore", luasteam_uploadLeaderboardScore);
    add_func(L, "downloadLeaderboardEntries", luasteam_downloadLeaderboardEntries);
    lua_pushvalue(L, -1);
    userStats_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    userStats_listener = new SteamUserStatsListener();
    lua_setfield(L, -2, "userStats");
}

void add_friends(lua_State *L) {
    lua_createtable(L, 0, 3);
    add_func(L, "activateGameOverlay", luasteam_activateGameOverlay);
    add_func(L, "activateGameOverlayToWebPage", luasteam_activateGameOverlayToWebPage);
    add_func(L, "getFriendPersonaName", luasteam_getFriendPersonaName);
    lua_pushvalue(L, -1);
    friends_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    friends_listener = new SteamFriendsListener();
    lua_setfield(L, -2, "friends");
}

} // namespace

EXTERN int luaopen_luasteam(lua_State *L) {
    global_lua_state = L;
    lua_createtable(L, 0, 0);
    uint64Metatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_createtable(L, 0, 5);
    add_base(L);
    add_user_stats(L);
    add_friends(L);
    return 1;
}
