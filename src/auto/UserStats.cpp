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

template <> void CallResultListener<GlobalAchievementPercentagesReady_t>::Result(GlobalAchievementPercentagesReady_t *data, bool io_fail) {
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) {
		luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);
		delete this;
		return;
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, callback_ref);
	luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);
	if (io_fail || data == nullptr) {
		lua_pushnil(L);
	} else {
		lua_createtable(L, 0, 2);
		luasteam::pushuint64(L, data->m_nGameID);
		lua_setfield(L, -2, "m_nGameID");
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<GlobalStatsReceived_t>::Result(GlobalStatsReceived_t *data, bool io_fail) {
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) {
		luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);
		delete this;
		return;
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, callback_ref);
	luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);
	if (io_fail || data == nullptr) {
		lua_pushnil(L);
	} else {
		lua_createtable(L, 0, 2);
		luasteam::pushuint64(L, data->m_nGameID);
		lua_setfield(L, -2, "m_nGameID");
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<LeaderboardFindResult_t>::Result(LeaderboardFindResult_t *data, bool io_fail) {
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) {
		luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);
		delete this;
		return;
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, callback_ref);
	luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);
	if (io_fail || data == nullptr) {
		lua_pushnil(L);
	} else {
		lua_createtable(L, 0, 2);
		luasteam::pushuint64(L, data->m_hSteamLeaderboard);
		lua_setfield(L, -2, "m_hSteamLeaderboard");
		lua_pushinteger(L, data->m_bLeaderboardFound);
		lua_setfield(L, -2, "m_bLeaderboardFound");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<LeaderboardScoreUploaded_t>::Result(LeaderboardScoreUploaded_t *data, bool io_fail) {
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) {
		luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);
		delete this;
		return;
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, callback_ref);
	luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);
	if (io_fail || data == nullptr) {
		lua_pushnil(L);
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
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<LeaderboardScoresDownloaded_t>::Result(LeaderboardScoresDownloaded_t *data, bool io_fail) {
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) {
		luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);
		delete this;
		return;
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, callback_ref);
	luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);
	if (io_fail || data == nullptr) {
		lua_pushnil(L);
	} else {
		lua_createtable(L, 0, 3);
		luasteam::pushuint64(L, data->m_hSteamLeaderboard);
		lua_setfield(L, -2, "m_hSteamLeaderboard");
		luasteam::pushuint64(L, data->m_hSteamLeaderboardEntries);
		lua_setfield(L, -2, "m_hSteamLeaderboardEntries");
		lua_pushinteger(L, data->m_cEntryCount);
		lua_setfield(L, -2, "m_cEntryCount");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<LeaderboardUGCSet_t>::Result(LeaderboardUGCSet_t *data, bool io_fail) {
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) {
		luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);
		delete this;
		return;
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, callback_ref);
	luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);
	if (io_fail || data == nullptr) {
		lua_pushnil(L);
	} else {
		lua_createtable(L, 0, 2);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		luasteam::pushuint64(L, data->m_hSteamLeaderboard);
		lua_setfield(L, -2, "m_hSteamLeaderboard");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<NumberOfCurrentPlayers_t>::Result(NumberOfCurrentPlayers_t *data, bool io_fail) {
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) {
		luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);
		delete this;
		return;
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, callback_ref);
	luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);
	if (io_fail || data == nullptr) {
		lua_pushnil(L);
	} else {
		lua_createtable(L, 0, 2);
		lua_pushinteger(L, data->m_bSuccess);
		lua_setfield(L, -2, "m_bSuccess");
		lua_pushinteger(L, data->m_cPlayers);
		lua_setfield(L, -2, "m_cPlayers");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<UserStatsReceived_t>::Result(UserStatsReceived_t *data, bool io_fail) {
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) {
		luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);
		delete this;
		return;
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, callback_ref);
	luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);
	if (io_fail || data == nullptr) {
		lua_pushnil(L);
	} else {
		lua_createtable(L, 0, 3);
		luasteam::pushuint64(L, data->m_nGameID);
		lua_setfield(L, -2, "m_nGameID");
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		luasteam::pushuint64(L, data->m_steamIDUser.ConvertToUint64());
		lua_setfield(L, -2, "m_steamIDUser");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

// In C++:
// bool GetStat(const char * pchName, int32 * pData);
// In Lua:
// (bool, pData: int) UserStats.GetStatInt32(pchName: str)
EXTERN int luasteam_UserStats_GetStatInt32(lua_State *L) {
	const char *pchName = luaL_checkstring(L, 1);
	int32 pData;
	bool __ret = SteamUserStats()->GetStat(pchName, &pData);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pData);
	return 2;
}

// In C++:
// bool GetStat(const char * pchName, float * pData);
// In Lua:
// (bool, pData: float) UserStats.GetStatFloat(pchName: str)
EXTERN int luasteam_UserStats_GetStatFloat(lua_State *L) {
	const char *pchName = luaL_checkstring(L, 1);
	float pData;
	bool __ret = SteamUserStats()->GetStat(pchName, &pData);
	lua_pushboolean(L, __ret);
	lua_pushnumber(L, pData);
	return 2;
}

// In C++:
// bool SetStat(const char * pchName, int32 nData);
// In Lua:
// bool UserStats.SetStatInt32(pchName: str, nData: int)
EXTERN int luasteam_UserStats_SetStatInt32(lua_State *L) {
	const char *pchName = luaL_checkstring(L, 1);
	int32 nData = static_cast<int32>(luaL_checkint(L, 2));
	bool __ret = SteamUserStats()->SetStat(pchName, nData);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetStat(const char * pchName, float fData);
// In Lua:
// bool UserStats.SetStatFloat(pchName: str, fData: float)
EXTERN int luasteam_UserStats_SetStatFloat(lua_State *L) {
	const char *pchName = luaL_checkstring(L, 1);
	float fData = luaL_checknumber(L, 2);
	bool __ret = SteamUserStats()->SetStat(pchName, fData);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool UpdateAvgRateStat(const char * pchName, float flCountThisSession, double dSessionLength);
// In Lua:
// bool UserStats.UpdateAvgRateStat(pchName: str, flCountThisSession: float, dSessionLength: float)
EXTERN int luasteam_UserStats_UpdateAvgRateStat(lua_State *L) {
	const char *pchName = luaL_checkstring(L, 1);
	float flCountThisSession = luaL_checknumber(L, 2);
	double dSessionLength = luaL_checknumber(L, 3);
	bool __ret = SteamUserStats()->UpdateAvgRateStat(pchName, flCountThisSession, dSessionLength);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool GetAchievement(const char * pchName, bool * pbAchieved);
// In Lua:
// (bool, pbAchieved: bool) UserStats.GetAchievement(pchName: str)
EXTERN int luasteam_UserStats_GetAchievement(lua_State *L) {
	const char *pchName = luaL_checkstring(L, 1);
	bool pbAchieved;
	bool __ret = SteamUserStats()->GetAchievement(pchName, &pbAchieved);
	lua_pushboolean(L, __ret);
	lua_pushboolean(L, pbAchieved);
	return 2;
}

// In C++:
// bool SetAchievement(const char * pchName);
// In Lua:
// bool UserStats.SetAchievement(pchName: str)
EXTERN int luasteam_UserStats_SetAchievement(lua_State *L) {
	const char *pchName = luaL_checkstring(L, 1);
	bool __ret = SteamUserStats()->SetAchievement(pchName);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool ClearAchievement(const char * pchName);
// In Lua:
// bool UserStats.ClearAchievement(pchName: str)
EXTERN int luasteam_UserStats_ClearAchievement(lua_State *L) {
	const char *pchName = luaL_checkstring(L, 1);
	bool __ret = SteamUserStats()->ClearAchievement(pchName);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool GetAchievementAndUnlockTime(const char * pchName, bool * pbAchieved, uint32 * punUnlockTime);
// In Lua:
// (bool, pbAchieved: bool, punUnlockTime: int) UserStats.GetAchievementAndUnlockTime(pchName: str)
EXTERN int luasteam_UserStats_GetAchievementAndUnlockTime(lua_State *L) {
	const char *pchName = luaL_checkstring(L, 1);
	bool pbAchieved;
	uint32 punUnlockTime;
	bool __ret = SteamUserStats()->GetAchievementAndUnlockTime(pchName, &pbAchieved, &punUnlockTime);
	lua_pushboolean(L, __ret);
	lua_pushboolean(L, pbAchieved);
	lua_pushinteger(L, punUnlockTime);
	return 3;
}

// In C++:
// bool StoreStats();
// In Lua:
// bool UserStats.StoreStats()
EXTERN int luasteam_UserStats_StoreStats(lua_State *L) {
	bool __ret = SteamUserStats()->StoreStats();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// int GetAchievementIcon(const char * pchName);
// In Lua:
// int UserStats.GetAchievementIcon(pchName: str)
EXTERN int luasteam_UserStats_GetAchievementIcon(lua_State *L) {
	const char *pchName = luaL_checkstring(L, 1);
	int __ret = SteamUserStats()->GetAchievementIcon(pchName);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// const char * GetAchievementDisplayAttribute(const char * pchName, const char * pchKey);
// In Lua:
// str UserStats.GetAchievementDisplayAttribute(pchName: str, pchKey: str)
EXTERN int luasteam_UserStats_GetAchievementDisplayAttribute(lua_State *L) {
	const char *pchName = luaL_checkstring(L, 1);
	const char *pchKey = luaL_checkstring(L, 2);
	const char * __ret = SteamUserStats()->GetAchievementDisplayAttribute(pchName, pchKey);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// bool IndicateAchievementProgress(const char * pchName, uint32 nCurProgress, uint32 nMaxProgress);
// In Lua:
// bool UserStats.IndicateAchievementProgress(pchName: str, nCurProgress: int, nMaxProgress: int)
EXTERN int luasteam_UserStats_IndicateAchievementProgress(lua_State *L) {
	const char *pchName = luaL_checkstring(L, 1);
	uint32 nCurProgress = static_cast<uint32>(luaL_checkint(L, 2));
	uint32 nMaxProgress = static_cast<uint32>(luaL_checkint(L, 3));
	bool __ret = SteamUserStats()->IndicateAchievementProgress(pchName, nCurProgress, nMaxProgress);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// uint32 GetNumAchievements();
// In Lua:
// int UserStats.GetNumAchievements()
EXTERN int luasteam_UserStats_GetNumAchievements(lua_State *L) {
	uint32 __ret = SteamUserStats()->GetNumAchievements();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// const char * GetAchievementName(uint32 iAchievement);
// In Lua:
// str UserStats.GetAchievementName(iAchievement: int)
EXTERN int luasteam_UserStats_GetAchievementName(lua_State *L) {
	uint32 iAchievement = static_cast<uint32>(luaL_checkint(L, 1));
	const char * __ret = SteamUserStats()->GetAchievementName(iAchievement);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// SteamAPICall_t RequestUserStats(CSteamID steamIDUser);
// In Lua:
// uint64 UserStats.RequestUserStats(steamIDUser: uint64, callback: function)
EXTERN int luasteam_UserStats_RequestUserStats(lua_State *L) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	CSteamID steamIDUser(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = SteamUserStats()->RequestUserStats(steamIDUser);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<UserStatsReceived_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<UserStatsReceived_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// bool GetUserStat(CSteamID steamIDUser, const char * pchName, int32 * pData);
// In Lua:
// (bool, pData: int) UserStats.GetUserStatInt32(steamIDUser: uint64, pchName: str)
EXTERN int luasteam_UserStats_GetUserStatInt32(lua_State *L) {
	CSteamID steamIDUser(luasteam::checkuint64(L, 1));
	const char *pchName = luaL_checkstring(L, 2);
	int32 pData;
	bool __ret = SteamUserStats()->GetUserStat(steamIDUser, pchName, &pData);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pData);
	return 2;
}

// In C++:
// bool GetUserStat(CSteamID steamIDUser, const char * pchName, float * pData);
// In Lua:
// (bool, pData: float) UserStats.GetUserStatFloat(steamIDUser: uint64, pchName: str)
EXTERN int luasteam_UserStats_GetUserStatFloat(lua_State *L) {
	CSteamID steamIDUser(luasteam::checkuint64(L, 1));
	const char *pchName = luaL_checkstring(L, 2);
	float pData;
	bool __ret = SteamUserStats()->GetUserStat(steamIDUser, pchName, &pData);
	lua_pushboolean(L, __ret);
	lua_pushnumber(L, pData);
	return 2;
}

// In C++:
// bool GetUserAchievement(CSteamID steamIDUser, const char * pchName, bool * pbAchieved);
// In Lua:
// (bool, pbAchieved: bool) UserStats.GetUserAchievement(steamIDUser: uint64, pchName: str)
EXTERN int luasteam_UserStats_GetUserAchievement(lua_State *L) {
	CSteamID steamIDUser(luasteam::checkuint64(L, 1));
	const char *pchName = luaL_checkstring(L, 2);
	bool pbAchieved;
	bool __ret = SteamUserStats()->GetUserAchievement(steamIDUser, pchName, &pbAchieved);
	lua_pushboolean(L, __ret);
	lua_pushboolean(L, pbAchieved);
	return 2;
}

// In C++:
// bool GetUserAchievementAndUnlockTime(CSteamID steamIDUser, const char * pchName, bool * pbAchieved, uint32 * punUnlockTime);
// In Lua:
// (bool, pbAchieved: bool, punUnlockTime: int) UserStats.GetUserAchievementAndUnlockTime(steamIDUser: uint64, pchName: str)
EXTERN int luasteam_UserStats_GetUserAchievementAndUnlockTime(lua_State *L) {
	CSteamID steamIDUser(luasteam::checkuint64(L, 1));
	const char *pchName = luaL_checkstring(L, 2);
	bool pbAchieved;
	uint32 punUnlockTime;
	bool __ret = SteamUserStats()->GetUserAchievementAndUnlockTime(steamIDUser, pchName, &pbAchieved, &punUnlockTime);
	lua_pushboolean(L, __ret);
	lua_pushboolean(L, pbAchieved);
	lua_pushinteger(L, punUnlockTime);
	return 3;
}

// In C++:
// bool ResetAllStats(bool bAchievementsToo);
// In Lua:
// bool UserStats.ResetAllStats(bAchievementsToo: bool)
EXTERN int luasteam_UserStats_ResetAllStats(lua_State *L) {
	bool bAchievementsToo = lua_toboolean(L, 1);
	bool __ret = SteamUserStats()->ResetAllStats(bAchievementsToo);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t FindOrCreateLeaderboard(const char * pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType);
// In Lua:
// uint64 UserStats.FindOrCreateLeaderboard(pchLeaderboardName: str, eLeaderboardSortMethod: int, eLeaderboardDisplayType: int, callback: function)
EXTERN int luasteam_UserStats_FindOrCreateLeaderboard(lua_State *L) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	const char *pchLeaderboardName = luaL_checkstring(L, 1);
	ELeaderboardSortMethod eLeaderboardSortMethod = static_cast<ELeaderboardSortMethod>(luaL_checkint(L, 2));
	ELeaderboardDisplayType eLeaderboardDisplayType = static_cast<ELeaderboardDisplayType>(luaL_checkint(L, 3));
	SteamAPICall_t __ret = SteamUserStats()->FindOrCreateLeaderboard(pchLeaderboardName, eLeaderboardSortMethod, eLeaderboardDisplayType);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<LeaderboardFindResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<LeaderboardFindResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t FindLeaderboard(const char * pchLeaderboardName);
// In Lua:
// uint64 UserStats.FindLeaderboard(pchLeaderboardName: str, callback: function)
EXTERN int luasteam_UserStats_FindLeaderboard(lua_State *L) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	const char *pchLeaderboardName = luaL_checkstring(L, 1);
	SteamAPICall_t __ret = SteamUserStats()->FindLeaderboard(pchLeaderboardName);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<LeaderboardFindResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<LeaderboardFindResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// const char * GetLeaderboardName(SteamLeaderboard_t hSteamLeaderboard);
// In Lua:
// str UserStats.GetLeaderboardName(hSteamLeaderboard: uint64)
EXTERN int luasteam_UserStats_GetLeaderboardName(lua_State *L) {
	SteamLeaderboard_t hSteamLeaderboard(luasteam::checkuint64(L, 1));
	const char * __ret = SteamUserStats()->GetLeaderboardName(hSteamLeaderboard);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// int GetLeaderboardEntryCount(SteamLeaderboard_t hSteamLeaderboard);
// In Lua:
// int UserStats.GetLeaderboardEntryCount(hSteamLeaderboard: uint64)
EXTERN int luasteam_UserStats_GetLeaderboardEntryCount(lua_State *L) {
	SteamLeaderboard_t hSteamLeaderboard(luasteam::checkuint64(L, 1));
	int __ret = SteamUserStats()->GetLeaderboardEntryCount(hSteamLeaderboard);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// ELeaderboardSortMethod GetLeaderboardSortMethod(SteamLeaderboard_t hSteamLeaderboard);
// In Lua:
// int UserStats.GetLeaderboardSortMethod(hSteamLeaderboard: uint64)
EXTERN int luasteam_UserStats_GetLeaderboardSortMethod(lua_State *L) {
	SteamLeaderboard_t hSteamLeaderboard(luasteam::checkuint64(L, 1));
	ELeaderboardSortMethod __ret = SteamUserStats()->GetLeaderboardSortMethod(hSteamLeaderboard);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// ELeaderboardDisplayType GetLeaderboardDisplayType(SteamLeaderboard_t hSteamLeaderboard);
// In Lua:
// int UserStats.GetLeaderboardDisplayType(hSteamLeaderboard: uint64)
EXTERN int luasteam_UserStats_GetLeaderboardDisplayType(lua_State *L) {
	SteamLeaderboard_t hSteamLeaderboard(luasteam::checkuint64(L, 1));
	ELeaderboardDisplayType __ret = SteamUserStats()->GetLeaderboardDisplayType(hSteamLeaderboard);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t DownloadLeaderboardEntries(SteamLeaderboard_t hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, int nRangeStart, int nRangeEnd);
// In Lua:
// uint64 UserStats.DownloadLeaderboardEntries(hSteamLeaderboard: uint64, eLeaderboardDataRequest: int, nRangeStart: int, nRangeEnd: int, callback: function)
EXTERN int luasteam_UserStats_DownloadLeaderboardEntries(lua_State *L) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	SteamLeaderboard_t hSteamLeaderboard(luasteam::checkuint64(L, 1));
	ELeaderboardDataRequest eLeaderboardDataRequest = static_cast<ELeaderboardDataRequest>(luaL_checkint(L, 2));
	int nRangeStart = static_cast<int>(luaL_checkint(L, 3));
	int nRangeEnd = static_cast<int>(luaL_checkint(L, 4));
	SteamAPICall_t __ret = SteamUserStats()->DownloadLeaderboardEntries(hSteamLeaderboard, eLeaderboardDataRequest, nRangeStart, nRangeEnd);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<LeaderboardScoresDownloaded_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<LeaderboardScoresDownloaded_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t DownloadLeaderboardEntriesForUsers(SteamLeaderboard_t hSteamLeaderboard, const CSteamID * prgUsers, int cUsers);
// In Lua:
// uint64 UserStats.DownloadLeaderboardEntriesForUsers(hSteamLeaderboard: uint64, cUsers: int, prgUsers: uint64[], callback: function)
EXTERN int luasteam_UserStats_DownloadLeaderboardEntriesForUsers(lua_State *L) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	SteamLeaderboard_t hSteamLeaderboard(luasteam::checkuint64(L, 1));
	int cUsers = luaL_checkint(L, 3);
	luaL_checktype(L, 2, LUA_TTABLE);
	std::vector<CSteamID> prgUsers(cUsers);
	for(decltype(cUsers) i = 0; i < cUsers; i++) {
		lua_rawgeti(L, -1, i+1);
		prgUsers[i] = CSteamID(luasteam::checkuint64(L, -1));
		lua_pop(L, 1);
	}
	SteamAPICall_t __ret = SteamUserStats()->DownloadLeaderboardEntriesForUsers(hSteamLeaderboard, prgUsers.data(), cUsers);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<LeaderboardScoresDownloaded_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<LeaderboardScoresDownloaded_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// bool GetDownloadedLeaderboardEntry(SteamLeaderboardEntries_t hSteamLeaderboardEntries, int index, LeaderboardEntry_t * pLeaderboardEntry, int32 * pDetails, int cDetailsMax);
// In Lua:
// (bool, pLeaderboardEntry: table, pDetails: int[]) UserStats.GetDownloadedLeaderboardEntry(hSteamLeaderboardEntries: uint64, index: int, cDetailsMax: int)
EXTERN int luasteam_UserStats_GetDownloadedLeaderboardEntry(lua_State *L) {
	SteamLeaderboardEntries_t hSteamLeaderboardEntries(luasteam::checkuint64(L, 1));
	int index = static_cast<int>(luaL_checkint(L, 2));
	LeaderboardEntry_t pLeaderboardEntry;
	int cDetailsMax = luaL_checkint(L, 3);
	std::vector<int32> pDetails(cDetailsMax);
	bool __ret = SteamUserStats()->GetDownloadedLeaderboardEntry(hSteamLeaderboardEntries, index, &pLeaderboardEntry, pDetails.data(), cDetailsMax);
	lua_pushboolean(L, __ret);
	push_LeaderboardEntry_t(L, pLeaderboardEntry);
	lua_createtable(L, cDetailsMax, 0);
	for(decltype(cDetailsMax) i = 0; i < cDetailsMax; i++) {
		lua_pushinteger(L, pDetails[i]);
		lua_rawseti(L, -2, i+1);
	}
	return 3;
}

// In C++:
// SteamAPICall_t UploadLeaderboardScore(SteamLeaderboard_t hSteamLeaderboard, ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod, int32 nScore, const int32 * pScoreDetails, int cScoreDetailsCount);
// In Lua:
// uint64 UserStats.UploadLeaderboardScore(hSteamLeaderboard: uint64, eLeaderboardUploadScoreMethod: int, nScore: int, cScoreDetailsCount: int, pScoreDetails: int[], callback: function)
EXTERN int luasteam_UserStats_UploadLeaderboardScore(lua_State *L) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	SteamLeaderboard_t hSteamLeaderboard(luasteam::checkuint64(L, 1));
	ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod = static_cast<ELeaderboardUploadScoreMethod>(luaL_checkint(L, 2));
	int32 nScore = static_cast<int32>(luaL_checkint(L, 3));
	int cScoreDetailsCount = luaL_checkint(L, 5);
	luaL_checktype(L, 4, LUA_TTABLE);
	std::vector<int32> pScoreDetails(cScoreDetailsCount);
	for(decltype(cScoreDetailsCount) i = 0; i < cScoreDetailsCount; i++) {
		lua_rawgeti(L, -1, i+1);
		pScoreDetails[i] = static_cast<int32>(luaL_checkint(L, -1));
		lua_pop(L, 1);
	}
	SteamAPICall_t __ret = SteamUserStats()->UploadLeaderboardScore(hSteamLeaderboard, eLeaderboardUploadScoreMethod, nScore, pScoreDetails.data(), cScoreDetailsCount);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<LeaderboardScoreUploaded_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<LeaderboardScoreUploaded_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t AttachLeaderboardUGC(SteamLeaderboard_t hSteamLeaderboard, UGCHandle_t hUGC);
// In Lua:
// uint64 UserStats.AttachLeaderboardUGC(hSteamLeaderboard: uint64, hUGC: uint64, callback: function)
EXTERN int luasteam_UserStats_AttachLeaderboardUGC(lua_State *L) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	SteamLeaderboard_t hSteamLeaderboard(luasteam::checkuint64(L, 1));
	UGCHandle_t hUGC(luasteam::checkuint64(L, 2));
	SteamAPICall_t __ret = SteamUserStats()->AttachLeaderboardUGC(hSteamLeaderboard, hUGC);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<LeaderboardUGCSet_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<LeaderboardUGCSet_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t GetNumberOfCurrentPlayers();
// In Lua:
// uint64 UserStats.GetNumberOfCurrentPlayers(callback: function)
EXTERN int luasteam_UserStats_GetNumberOfCurrentPlayers(lua_State *L) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	SteamAPICall_t __ret = SteamUserStats()->GetNumberOfCurrentPlayers();
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<NumberOfCurrentPlayers_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<NumberOfCurrentPlayers_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t RequestGlobalAchievementPercentages();
// In Lua:
// uint64 UserStats.RequestGlobalAchievementPercentages(callback: function)
EXTERN int luasteam_UserStats_RequestGlobalAchievementPercentages(lua_State *L) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	SteamAPICall_t __ret = SteamUserStats()->RequestGlobalAchievementPercentages();
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<GlobalAchievementPercentagesReady_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<GlobalAchievementPercentagesReady_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// int GetMostAchievedAchievementInfo(char * pchName, uint32 unNameBufLen, float * pflPercent, bool * pbAchieved);
// In Lua:
// (int, pchName: str, pflPercent: float, pbAchieved: bool) UserStats.GetMostAchievedAchievementInfo(unNameBufLen: int)
EXTERN int luasteam_UserStats_GetMostAchievedAchievementInfo(lua_State *L) {
	uint32 unNameBufLen = luaL_checkint(L, 1);
	std::vector<char> pchName(unNameBufLen);
	float pflPercent;
	bool pbAchieved;
	int __ret = SteamUserStats()->GetMostAchievedAchievementInfo(pchName.data(), unNameBufLen, &pflPercent, &pbAchieved);
	lua_pushinteger(L, __ret);
	lua_pushstring(L, reinterpret_cast<const char*>(pchName.data()));
	lua_pushnumber(L, pflPercent);
	lua_pushboolean(L, pbAchieved);
	return 4;
}

// In C++:
// int GetNextMostAchievedAchievementInfo(int iIteratorPrevious, char * pchName, uint32 unNameBufLen, float * pflPercent, bool * pbAchieved);
// In Lua:
// (int, pchName: str, pflPercent: float, pbAchieved: bool) UserStats.GetNextMostAchievedAchievementInfo(iIteratorPrevious: int, unNameBufLen: int)
EXTERN int luasteam_UserStats_GetNextMostAchievedAchievementInfo(lua_State *L) {
	int iIteratorPrevious = static_cast<int>(luaL_checkint(L, 1));
	uint32 unNameBufLen = luaL_checkint(L, 2);
	std::vector<char> pchName(unNameBufLen);
	float pflPercent;
	bool pbAchieved;
	int __ret = SteamUserStats()->GetNextMostAchievedAchievementInfo(iIteratorPrevious, pchName.data(), unNameBufLen, &pflPercent, &pbAchieved);
	lua_pushinteger(L, __ret);
	lua_pushstring(L, reinterpret_cast<const char*>(pchName.data()));
	lua_pushnumber(L, pflPercent);
	lua_pushboolean(L, pbAchieved);
	return 4;
}

// In C++:
// bool GetAchievementAchievedPercent(const char * pchName, float * pflPercent);
// In Lua:
// (bool, pflPercent: float) UserStats.GetAchievementAchievedPercent(pchName: str)
EXTERN int luasteam_UserStats_GetAchievementAchievedPercent(lua_State *L) {
	const char *pchName = luaL_checkstring(L, 1);
	float pflPercent;
	bool __ret = SteamUserStats()->GetAchievementAchievedPercent(pchName, &pflPercent);
	lua_pushboolean(L, __ret);
	lua_pushnumber(L, pflPercent);
	return 2;
}

// In C++:
// SteamAPICall_t RequestGlobalStats(int nHistoryDays);
// In Lua:
// uint64 UserStats.RequestGlobalStats(nHistoryDays: int, callback: function)
EXTERN int luasteam_UserStats_RequestGlobalStats(lua_State *L) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	int nHistoryDays = static_cast<int>(luaL_checkint(L, 1));
	SteamAPICall_t __ret = SteamUserStats()->RequestGlobalStats(nHistoryDays);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<GlobalStatsReceived_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<GlobalStatsReceived_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// bool GetGlobalStat(const char * pchStatName, int64 * pData);
// In Lua:
// (bool, pData: uint64) UserStats.GetGlobalStatInt64(pchStatName: str)
EXTERN int luasteam_UserStats_GetGlobalStatInt64(lua_State *L) {
	const char *pchStatName = luaL_checkstring(L, 1);
	int64 pData;
	bool __ret = SteamUserStats()->GetGlobalStat(pchStatName, &pData);
	lua_pushboolean(L, __ret);
	luasteam::pushuint64(L, pData);
	return 2;
}

// In C++:
// bool GetGlobalStat(const char * pchStatName, double * pData);
// In Lua:
// (bool, pData: float) UserStats.GetGlobalStatDouble(pchStatName: str)
EXTERN int luasteam_UserStats_GetGlobalStatDouble(lua_State *L) {
	const char *pchStatName = luaL_checkstring(L, 1);
	double pData;
	bool __ret = SteamUserStats()->GetGlobalStat(pchStatName, &pData);
	lua_pushboolean(L, __ret);
	lua_pushnumber(L, pData);
	return 2;
}

// In C++:
// int32 GetGlobalStatHistory(const char * pchStatName, int64 * pData, uint32 cubData);
// In Lua:
// (int, pData: uint64[]) UserStats.GetGlobalStatHistoryInt64(pchStatName: str, cubData: int)
EXTERN int luasteam_UserStats_GetGlobalStatHistoryInt64(lua_State *L) {
	const char *pchStatName = luaL_checkstring(L, 1);
	uint32 cubData = luaL_checkint(L, 2);
	std::vector<int64> pData(cubData);
	int32 __ret = SteamUserStats()->GetGlobalStatHistory(pchStatName, pData.data(), cubData);
	lua_pushinteger(L, __ret);
	lua_createtable(L, __ret, 0);
	for(decltype(__ret) i = 0; i < __ret; i++) {
		luasteam::pushuint64(L, pData[i]);
		lua_rawseti(L, -2, i+1);
	}
	return 2;
}

// In C++:
// int32 GetGlobalStatHistory(const char * pchStatName, double * pData, uint32 cubData);
// In Lua:
// (int, pData: float[]) UserStats.GetGlobalStatHistoryDouble(pchStatName: str, cubData: int)
EXTERN int luasteam_UserStats_GetGlobalStatHistoryDouble(lua_State *L) {
	const char *pchStatName = luaL_checkstring(L, 1);
	uint32 cubData = luaL_checkint(L, 2);
	std::vector<double> pData(cubData);
	int32 __ret = SteamUserStats()->GetGlobalStatHistory(pchStatName, pData.data(), cubData);
	lua_pushinteger(L, __ret);
	lua_createtable(L, __ret, 0);
	for(decltype(__ret) i = 0; i < __ret; i++) {
		lua_pushnumber(L, pData[i]);
		lua_rawseti(L, -2, i+1);
	}
	return 2;
}

// In C++:
// bool GetAchievementProgressLimits(const char * pchName, int32 * pnMinProgress, int32 * pnMaxProgress);
// In Lua:
// (bool, pnMinProgress: int, pnMaxProgress: int) UserStats.GetAchievementProgressLimitsInt32(pchName: str)
EXTERN int luasteam_UserStats_GetAchievementProgressLimitsInt32(lua_State *L) {
	const char *pchName = luaL_checkstring(L, 1);
	int32 pnMinProgress;
	int32 pnMaxProgress;
	bool __ret = SteamUserStats()->GetAchievementProgressLimits(pchName, &pnMinProgress, &pnMaxProgress);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pnMinProgress);
	lua_pushinteger(L, pnMaxProgress);
	return 3;
}

// In C++:
// bool GetAchievementProgressLimits(const char * pchName, float * pfMinProgress, float * pfMaxProgress);
// In Lua:
// (bool, pfMinProgress: float, pfMaxProgress: float) UserStats.GetAchievementProgressLimitsFloat(pchName: str)
EXTERN int luasteam_UserStats_GetAchievementProgressLimitsFloat(lua_State *L) {
	const char *pchName = luaL_checkstring(L, 1);
	float pfMinProgress;
	float pfMaxProgress;
	bool __ret = SteamUserStats()->GetAchievementProgressLimits(pchName, &pfMinProgress, &pfMaxProgress);
	lua_pushboolean(L, __ret);
	lua_pushnumber(L, pfMinProgress);
	lua_pushnumber(L, pfMaxProgress);
	return 3;
}

void register_UserStats_auto(lua_State *L) {
	add_func(L, "GetStatInt32", luasteam_UserStats_GetStatInt32);
	add_func(L, "GetStatFloat", luasteam_UserStats_GetStatFloat);
	add_func(L, "SetStatInt32", luasteam_UserStats_SetStatInt32);
	add_func(L, "SetStatFloat", luasteam_UserStats_SetStatFloat);
	add_func(L, "UpdateAvgRateStat", luasteam_UserStats_UpdateAvgRateStat);
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
	add_func(L, "GetUserStatInt32", luasteam_UserStats_GetUserStatInt32);
	add_func(L, "GetUserStatFloat", luasteam_UserStats_GetUserStatFloat);
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
	add_func(L, "DownloadLeaderboardEntriesForUsers", luasteam_UserStats_DownloadLeaderboardEntriesForUsers);
	add_func(L, "GetDownloadedLeaderboardEntry", luasteam_UserStats_GetDownloadedLeaderboardEntry);
	add_func(L, "UploadLeaderboardScore", luasteam_UserStats_UploadLeaderboardScore);
	add_func(L, "AttachLeaderboardUGC", luasteam_UserStats_AttachLeaderboardUGC);
	add_func(L, "GetNumberOfCurrentPlayers", luasteam_UserStats_GetNumberOfCurrentPlayers);
	add_func(L, "RequestGlobalAchievementPercentages", luasteam_UserStats_RequestGlobalAchievementPercentages);
	add_func(L, "GetMostAchievedAchievementInfo", luasteam_UserStats_GetMostAchievedAchievementInfo);
	add_func(L, "GetNextMostAchievedAchievementInfo", luasteam_UserStats_GetNextMostAchievedAchievementInfo);
	add_func(L, "GetAchievementAchievedPercent", luasteam_UserStats_GetAchievementAchievedPercent);
	add_func(L, "RequestGlobalStats", luasteam_UserStats_RequestGlobalStats);
	add_func(L, "GetGlobalStatInt64", luasteam_UserStats_GetGlobalStatInt64);
	add_func(L, "GetGlobalStatDouble", luasteam_UserStats_GetGlobalStatDouble);
	add_func(L, "GetGlobalStatHistoryInt64", luasteam_UserStats_GetGlobalStatHistoryInt64);
	add_func(L, "GetGlobalStatHistoryDouble", luasteam_UserStats_GetGlobalStatHistoryDouble);
	add_func(L, "GetAchievementProgressLimitsInt32", luasteam_UserStats_GetAchievementProgressLimitsInt32);
	add_func(L, "GetAchievementProgressLimitsFloat", luasteam_UserStats_GetAchievementProgressLimitsFloat);
}

void add_UserStats_auto(lua_State *L) {
	lua_createtable(L, 0, 44);
	register_UserStats_auto(L);
	lua_pushvalue(L, -1);
	UserStats_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "UserStats");
}

} // namespace luasteam
