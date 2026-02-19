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
		lua_createtable(L, 0, 2);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		luasteam::pushuint64(L, data->m_steamIDUser.ConvertToUint64());
		lua_setfield(L, -2, "m_steamIDUser");
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
		lua_createtable(L, 0, 2);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		luasteam::pushuint64(L, data->m_steamIDUser.ConvertToUint64());
		lua_setfield(L, -2, "m_steamIDUser");
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

// SteamAPICall_t RequestUserStats(CSteamID steamIDUser);
EXTERN int luasteam_GameServerStats_RequestUserStats(lua_State *L) {
	CSteamID steamIDUser(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = SteamGameServerStats()->RequestUserStats(steamIDUser);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// bool GetUserAchievement(CSteamID steamIDUser, const char * pchName, bool * pbAchieved);
EXTERN int luasteam_GameServerStats_GetUserAchievement(lua_State *L) {
	CSteamID steamIDUser(luasteam::checkuint64(L, 1));
	const char *pchName = luaL_checkstring(L, 2);
	bool pbAchieved;
	bool __ret = SteamGameServerStats()->GetUserAchievement(steamIDUser, pchName, &pbAchieved);
	lua_pushboolean(L, __ret);
	lua_pushboolean(L, pbAchieved);
	return 2;
}

// bool UpdateUserAvgRateStat(CSteamID steamIDUser, const char * pchName, float flCountThisSession, double dSessionLength);
EXTERN int luasteam_GameServerStats_UpdateUserAvgRateStat(lua_State *L) {
	CSteamID steamIDUser(luasteam::checkuint64(L, 1));
	const char *pchName = luaL_checkstring(L, 2);
	float flCountThisSession = luaL_checknumber(L, 3);
	double dSessionLength = luaL_checknumber(L, 4);
	bool __ret = SteamGameServerStats()->UpdateUserAvgRateStat(steamIDUser, pchName, flCountThisSession, dSessionLength);
	lua_pushboolean(L, __ret);
	return 1;
}

// bool SetUserAchievement(CSteamID steamIDUser, const char * pchName);
EXTERN int luasteam_GameServerStats_SetUserAchievement(lua_State *L) {
	CSteamID steamIDUser(luasteam::checkuint64(L, 1));
	const char *pchName = luaL_checkstring(L, 2);
	bool __ret = SteamGameServerStats()->SetUserAchievement(steamIDUser, pchName);
	lua_pushboolean(L, __ret);
	return 1;
}

// bool ClearUserAchievement(CSteamID steamIDUser, const char * pchName);
EXTERN int luasteam_GameServerStats_ClearUserAchievement(lua_State *L) {
	CSteamID steamIDUser(luasteam::checkuint64(L, 1));
	const char *pchName = luaL_checkstring(L, 2);
	bool __ret = SteamGameServerStats()->ClearUserAchievement(steamIDUser, pchName);
	lua_pushboolean(L, __ret);
	return 1;
}

// SteamAPICall_t StoreUserStats(CSteamID steamIDUser);
EXTERN int luasteam_GameServerStats_StoreUserStats(lua_State *L) {
	CSteamID steamIDUser(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = SteamGameServerStats()->StoreUserStats(steamIDUser);
	luasteam::pushuint64(L, __ret);
	return 1;
}

void register_GameServerStats_auto(lua_State *L) {
	add_func(L, "RequestUserStats", luasteam_GameServerStats_RequestUserStats);
	add_func(L, "GetUserAchievement", luasteam_GameServerStats_GetUserAchievement);
	add_func(L, "UpdateUserAvgRateStat", luasteam_GameServerStats_UpdateUserAvgRateStat);
	add_func(L, "SetUserAchievement", luasteam_GameServerStats_SetUserAchievement);
	add_func(L, "ClearUserAchievement", luasteam_GameServerStats_ClearUserAchievement);
	add_func(L, "StoreUserStats", luasteam_GameServerStats_StoreUserStats);
}

void add_GameServerStats_auto(lua_State *L) {
	lua_createtable(L, 0, 6);
	register_GameServerStats_auto(L);
	lua_pushvalue(L, -1);
	GameServerStats_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "GameServerStats");
}

} // namespace luasteam
