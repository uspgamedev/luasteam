#include "auto.hpp"

namespace luasteam {

int GameServerStats_ref = LUA_NOREF;

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
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerStats_ref);
	lua_getfield(L, -1, "OnGSStatsReceived");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_GSStatsReceived_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnGSStatsStored(GSStatsStored_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerStats_ref);
	lua_getfield(L, -1, "OnGSStatsStored");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_GSStatsStored_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
CallbackListener *GameServerStats_listener = nullptr;
} // namespace

void init_GameServerStats_auto(lua_State *L) { GameServerStats_listener = new CallbackListener(); }
void shutdown_GameServerStats_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, GameServerStats_ref);
	GameServerStats_ref = LUA_NOREF;
	delete GameServerStats_listener; GameServerStats_listener = nullptr;
}

template <> void CallResultListener<GSStatsReceived_t>::Result(GSStatsReceived_t *data, bool io_fail) {
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
		luasteam::pushuint64(L, data->m_steamIDUser.ConvertToUint64());
		lua_setfield(L, -2, "m_steamIDUser");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<GSStatsStored_t>::Result(GSStatsStored_t *data, bool io_fail) {
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
		luasteam::pushuint64(L, data->m_steamIDUser.ConvertToUint64());
		lua_setfield(L, -2, "m_steamIDUser");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

// In C++:
// SteamAPICall_t RequestUserStats(CSteamID steamIDUser);
// In Lua:
// uint64 GameServerStats.RequestUserStats(steamIDUser: uint64, callback: function)
EXTERN int luasteam_GameServerStats_RequestUserStats(lua_State *L) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	CSteamID steamIDUser(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = SteamGameServerStats()->RequestUserStats(steamIDUser);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<GSStatsReceived_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<GSStatsReceived_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// bool GetUserStat(CSteamID steamIDUser, const char * pchName, int32 * pData);
// In Lua:
// (bool, pData: int) GameServerStats.GetUserStatInt32(steamIDUser: uint64, pchName: str)
EXTERN int luasteam_GameServerStats_GetUserStatInt32(lua_State *L) {
	CSteamID steamIDUser(luasteam::checkuint64(L, 1));
	const char *pchName = luaL_checkstring(L, 2);
	int32 pData;
	bool __ret = SteamGameServerStats()->GetUserStat(steamIDUser, pchName, &pData);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pData);
	return 2;
}

// In C++:
// bool GetUserStat(CSteamID steamIDUser, const char * pchName, float * pData);
// In Lua:
// (bool, pData: float) GameServerStats.GetUserStatFloat(steamIDUser: uint64, pchName: str)
EXTERN int luasteam_GameServerStats_GetUserStatFloat(lua_State *L) {
	CSteamID steamIDUser(luasteam::checkuint64(L, 1));
	const char *pchName = luaL_checkstring(L, 2);
	float pData;
	bool __ret = SteamGameServerStats()->GetUserStat(steamIDUser, pchName, &pData);
	lua_pushboolean(L, __ret);
	lua_pushnumber(L, pData);
	return 2;
}

// In C++:
// bool GetUserAchievement(CSteamID steamIDUser, const char * pchName, bool * pbAchieved);
// In Lua:
// (bool, pbAchieved: bool) GameServerStats.GetUserAchievement(steamIDUser: uint64, pchName: str)
EXTERN int luasteam_GameServerStats_GetUserAchievement(lua_State *L) {
	CSteamID steamIDUser(luasteam::checkuint64(L, 1));
	const char *pchName = luaL_checkstring(L, 2);
	bool pbAchieved;
	bool __ret = SteamGameServerStats()->GetUserAchievement(steamIDUser, pchName, &pbAchieved);
	lua_pushboolean(L, __ret);
	lua_pushboolean(L, pbAchieved);
	return 2;
}

// In C++:
// bool SetUserStat(CSteamID steamIDUser, const char * pchName, int32 nData);
// In Lua:
// bool GameServerStats.SetUserStatInt32(steamIDUser: uint64, pchName: str, nData: int)
EXTERN int luasteam_GameServerStats_SetUserStatInt32(lua_State *L) {
	CSteamID steamIDUser(luasteam::checkuint64(L, 1));
	const char *pchName = luaL_checkstring(L, 2);
	int32 nData = static_cast<int32>(luaL_checkint(L, 3));
	bool __ret = SteamGameServerStats()->SetUserStat(steamIDUser, pchName, nData);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetUserStat(CSteamID steamIDUser, const char * pchName, float fData);
// In Lua:
// bool GameServerStats.SetUserStatFloat(steamIDUser: uint64, pchName: str, fData: float)
EXTERN int luasteam_GameServerStats_SetUserStatFloat(lua_State *L) {
	CSteamID steamIDUser(luasteam::checkuint64(L, 1));
	const char *pchName = luaL_checkstring(L, 2);
	float fData = luaL_checknumber(L, 3);
	bool __ret = SteamGameServerStats()->SetUserStat(steamIDUser, pchName, fData);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool UpdateUserAvgRateStat(CSteamID steamIDUser, const char * pchName, float flCountThisSession, double dSessionLength);
// In Lua:
// bool GameServerStats.UpdateUserAvgRateStat(steamIDUser: uint64, pchName: str, flCountThisSession: float, dSessionLength: float)
EXTERN int luasteam_GameServerStats_UpdateUserAvgRateStat(lua_State *L) {
	CSteamID steamIDUser(luasteam::checkuint64(L, 1));
	const char *pchName = luaL_checkstring(L, 2);
	float flCountThisSession = luaL_checknumber(L, 3);
	double dSessionLength = luaL_checknumber(L, 4);
	bool __ret = SteamGameServerStats()->UpdateUserAvgRateStat(steamIDUser, pchName, flCountThisSession, dSessionLength);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetUserAchievement(CSteamID steamIDUser, const char * pchName);
// In Lua:
// bool GameServerStats.SetUserAchievement(steamIDUser: uint64, pchName: str)
EXTERN int luasteam_GameServerStats_SetUserAchievement(lua_State *L) {
	CSteamID steamIDUser(luasteam::checkuint64(L, 1));
	const char *pchName = luaL_checkstring(L, 2);
	bool __ret = SteamGameServerStats()->SetUserAchievement(steamIDUser, pchName);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool ClearUserAchievement(CSteamID steamIDUser, const char * pchName);
// In Lua:
// bool GameServerStats.ClearUserAchievement(steamIDUser: uint64, pchName: str)
EXTERN int luasteam_GameServerStats_ClearUserAchievement(lua_State *L) {
	CSteamID steamIDUser(luasteam::checkuint64(L, 1));
	const char *pchName = luaL_checkstring(L, 2);
	bool __ret = SteamGameServerStats()->ClearUserAchievement(steamIDUser, pchName);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t StoreUserStats(CSteamID steamIDUser);
// In Lua:
// uint64 GameServerStats.StoreUserStats(steamIDUser: uint64, callback: function)
EXTERN int luasteam_GameServerStats_StoreUserStats(lua_State *L) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	CSteamID steamIDUser(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = SteamGameServerStats()->StoreUserStats(steamIDUser);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<GSStatsStored_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<GSStatsStored_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

void register_GameServerStats_auto(lua_State *L) {
	add_func(L, "RequestUserStats", luasteam_GameServerStats_RequestUserStats);
	add_func(L, "GetUserStatInt32", luasteam_GameServerStats_GetUserStatInt32);
	add_func(L, "GetUserStatFloat", luasteam_GameServerStats_GetUserStatFloat);
	add_func(L, "GetUserAchievement", luasteam_GameServerStats_GetUserAchievement);
	add_func(L, "SetUserStatInt32", luasteam_GameServerStats_SetUserStatInt32);
	add_func(L, "SetUserStatFloat", luasteam_GameServerStats_SetUserStatFloat);
	add_func(L, "UpdateUserAvgRateStat", luasteam_GameServerStats_UpdateUserAvgRateStat);
	add_func(L, "SetUserAchievement", luasteam_GameServerStats_SetUserAchievement);
	add_func(L, "ClearUserAchievement", luasteam_GameServerStats_ClearUserAchievement);
	add_func(L, "StoreUserStats", luasteam_GameServerStats_StoreUserStats);
}

void add_GameServerStats_auto(lua_State *L) {
	lua_createtable(L, 0, 10);
	register_GameServerStats_auto(L);
	lua_pushvalue(L, -1);
	GameServerStats_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "GameServerStats");
}

} // namespace luasteam
