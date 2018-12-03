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

} // namespace

// ==============================
// ======= SteamUserStats =======
// ==============================

namespace {

const char *sort_methods[] = {"Ascending", "Descending", nullptr};
const char *display_types[] = {"Numeric", "TimeSeconds", "TimeMilliSeconds", nullptr};
const char *upload_methods[] = {"KeepBest", "ForceUpdate", nullptr};
char tmp_25[25];

SteamLeaderboard_t checkLeaderboard(lua_State *L, int nParam) {
    uint64 handle = strtoull(luaL_checkstring(L, 1), nullptr, 10);
    luaL_argcheck(L, handle != 0, 1, "must be a valid handle");
    return handle;
}

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
        // This is converted to a string since Lua can't deal with 64 bit integers
        sprintf(tmp_25, "%llu", data->m_hSteamLeaderboard);
        lua_pushstring(L, tmp_25);
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
        sprintf(tmp_25, "%llu", data->m_hSteamLeaderboard);
        lua_pushstring(L, tmp_25);
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

} // namespace

// bool GetUserAchievement(const char *pchName, bool *pbAchieved );
EXTERN int luasteam_getAchievement(lua_State *L) {
    const char *ach_name = luaL_checkstring(L, 1);
    bool achieved = false;
    bool success = SteamUserStats()->GetAchievement(ach_name, &achieved);
    lua_pushboolean(L, success);
    lua_pushboolean(L, achieved);
    return 2;
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
    SteamLeaderboard_t leaderboard = checkLeaderboard(L, 1);
    ELeaderboardDisplayType m = SteamUserStats()->GetLeaderboardDisplayType(leaderboard);
    if (m == k_ELeaderboardDisplayTypeNone)
        lua_pushnil(L);
    else
        lua_pushstring(L, display_types[static_cast<int>(m) - 1]);
    return 1;
}

// ELeaderboardSortMethod GetLeaderboardSortMethod( SteamLeaderboard_t hSteamLeaderboard );
EXTERN int luasteam_getLeaderboardSortMethod(lua_State *L) {
    SteamLeaderboard_t leaderboard = checkLeaderboard(L, 1);
    ELeaderboardSortMethod m = SteamUserStats()->GetLeaderboardSortMethod(leaderboard);
    if (m == k_ELeaderboardSortMethodNone)
        lua_pushnil(L);
    else
        lua_pushstring(L, sort_methods[static_cast<int>(m) - 1]);
    return 1;
}

// ELeaderboardSortMethod GetLeaderboardSortMethod( SteamLeaderboard_t hSteamLeaderboard );
EXTERN int luasteam_getLeaderboardEntryCount(lua_State *L) {
    SteamLeaderboard_t leaderboard = checkLeaderboard(L, 1);
    int count = SteamUserStats()->GetLeaderboardEntryCount(leaderboard);
    lua_pushnumber(L, count);
    return 1;
}

// ELeaderboardSortMethod GetLeaderboardSortMethod( SteamLeaderboard_t hSteamLeaderboard );
EXTERN int luasteam_getLeaderboardName(lua_State *L) {
    SteamLeaderboard_t leaderboard = checkLeaderboard(L, 1);
    const char *name = SteamUserStats()->GetLeaderboardName(leaderboard);
    if (name == nullptr || *name == '\0')
        lua_pushnil(L);
    else
        lua_pushstring(L, name);
    return 1;
}

EXTERN int luasteam_uploadLeaderboardScore(lua_State *L) {
    SteamLeaderboard_t leaderboard = checkLeaderboard(L, 1);
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

// ============================
// ======= SteamFriends =======
// ============================

namespace {

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
        lua_pushboolean(L, data->m_bActive);
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

} // namespace

// void ActivateGameOverlay( const char *pchDialog );
EXTERN int luasteam_activateGameOverlay(lua_State *L) {
    const char *dialog = luaL_checkstring(L, 1);
    SteamFriends()->ActivateGameOverlay(dialog);
    return 0;
}

// void ActivateGameOverlayToWebPage( const char *pchURL );
EXTERN int luasteam_activateGameOverlayToWebPage(lua_State *L) {
    const char *url = luaL_checkstring(L, 1);
    SteamFriends()->ActivateGameOverlayToWebPage(url);
    return 0;
}

// ========================
// ======= SteamAPI =======
// ========================

// bool SteamAPI_Init();
EXTERN int luasteam_init(lua_State *L) {
    lua_pushboolean(L, SteamAPI_Init());
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
    // Not adding this since we call it ourselves
    // add_func(L, "init", luasteam_init);
    add_func(L, "shutdown", luasteam_shutdown);
    add_func(L, "runCallbacks", luasteam_runCallbacks);
}

void add_user_stats(lua_State *L) {
    lua_createtable(L, 0, 12);
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
    lua_pushvalue(L, -1);
    userStats_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    userStats_listener = new SteamUserStatsListener();
    lua_setfield(L, -2, "userStats");
}

void add_friends(lua_State *L) {
    lua_createtable(L, 0, 2);
    add_func(L, "activateGameOverlay", luasteam_activateGameOverlay);
    add_func(L, "activateGameOverlayToWebPage", luasteam_activateGameOverlayToWebPage);
    lua_pushvalue(L, -1);
    friends_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    friends_listener = new SteamFriendsListener();
    lua_setfield(L, -2, "friends");
}

} // namespace

EXTERN int luaopen_luasteam(lua_State *L) {
    if (SteamAPI_Init()) {
        printf("Sucessfully connected to steam!\n");
    } else {
        printf("Couldn't connect to steam...\nDo you have Steam turned on?\nIf not running from steam, do you have a correct steam_appid.txt file?\n");
        lua_pushboolean(L, false);
        return 1;
    }
    global_lua_state = L;
    lua_createtable(L, 0, 4);
    add_base(L);
    add_user_stats(L);
    add_friends(L);
    return 1;
}
