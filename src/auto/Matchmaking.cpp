#include "auto.hpp"

namespace luasteam {

int Matchmaking_ref = LUA_NOREF;

namespace {
class MatchmakingCallbackListener {
private:
	STEAM_CALLBACK(MatchmakingCallbackListener, OnFavoritesListChanged, FavoritesListChanged_t);
	STEAM_CALLBACK(MatchmakingCallbackListener, OnLobbyInvite, LobbyInvite_t);
	STEAM_CALLBACK(MatchmakingCallbackListener, OnLobbyEnter, LobbyEnter_t);
	STEAM_CALLBACK(MatchmakingCallbackListener, OnLobbyDataUpdate, LobbyDataUpdate_t);
	STEAM_CALLBACK(MatchmakingCallbackListener, OnLobbyChatUpdate, LobbyChatUpdate_t);
	STEAM_CALLBACK(MatchmakingCallbackListener, OnLobbyChatMsg, LobbyChatMsg_t);
	STEAM_CALLBACK(MatchmakingCallbackListener, OnLobbyGameCreated, LobbyGameCreated_t);
	STEAM_CALLBACK(MatchmakingCallbackListener, OnLobbyMatchList, LobbyMatchList_t);
	STEAM_CALLBACK(MatchmakingCallbackListener, OnLobbyKicked, LobbyKicked_t);
	STEAM_CALLBACK(MatchmakingCallbackListener, OnLobbyCreated, LobbyCreated_t);
	STEAM_CALLBACK(MatchmakingCallbackListener, OnFavoritesListAccountsUpdated, FavoritesListAccountsUpdated_t);
};
void MatchmakingCallbackListener::OnFavoritesListChanged(FavoritesListChanged_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Matchmaking_ref);
	lua_getfield(L, -1, "OnFavoritesListChanged");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_FavoritesListChanged_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void MatchmakingCallbackListener::OnLobbyInvite(LobbyInvite_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Matchmaking_ref);
	lua_getfield(L, -1, "OnLobbyInvite");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_LobbyInvite_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void MatchmakingCallbackListener::OnLobbyEnter(LobbyEnter_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Matchmaking_ref);
	lua_getfield(L, -1, "OnLobbyEnter");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_LobbyEnter_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void MatchmakingCallbackListener::OnLobbyDataUpdate(LobbyDataUpdate_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Matchmaking_ref);
	lua_getfield(L, -1, "OnLobbyDataUpdate");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_LobbyDataUpdate_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void MatchmakingCallbackListener::OnLobbyChatUpdate(LobbyChatUpdate_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Matchmaking_ref);
	lua_getfield(L, -1, "OnLobbyChatUpdate");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_LobbyChatUpdate_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void MatchmakingCallbackListener::OnLobbyChatMsg(LobbyChatMsg_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Matchmaking_ref);
	lua_getfield(L, -1, "OnLobbyChatMsg");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_LobbyChatMsg_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void MatchmakingCallbackListener::OnLobbyGameCreated(LobbyGameCreated_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Matchmaking_ref);
	lua_getfield(L, -1, "OnLobbyGameCreated");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_LobbyGameCreated_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void MatchmakingCallbackListener::OnLobbyMatchList(LobbyMatchList_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Matchmaking_ref);
	lua_getfield(L, -1, "OnLobbyMatchList");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_LobbyMatchList_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void MatchmakingCallbackListener::OnLobbyKicked(LobbyKicked_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Matchmaking_ref);
	lua_getfield(L, -1, "OnLobbyKicked");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_LobbyKicked_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void MatchmakingCallbackListener::OnLobbyCreated(LobbyCreated_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Matchmaking_ref);
	lua_getfield(L, -1, "OnLobbyCreated");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_LobbyCreated_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void MatchmakingCallbackListener::OnFavoritesListAccountsUpdated(FavoritesListAccountsUpdated_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Matchmaking_ref);
	lua_getfield(L, -1, "OnFavoritesListAccountsUpdated");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_FavoritesListAccountsUpdated_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
MatchmakingCallbackListener *Matchmaking_listener = nullptr;
} // namespace

void init_Matchmaking_auto(lua_State *L) { if (Matchmaking_listener != nullptr) return; Matchmaking_listener = new MatchmakingCallbackListener(); }
void shutdown_Matchmaking_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, Matchmaking_ref);
	Matchmaking_ref = LUA_NOREF;
	delete Matchmaking_listener; Matchmaking_listener = nullptr;
}

template <> void CallResultListener<LobbyCreated_t>::Result(LobbyCreated_t *data, bool io_fail) {
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
		luasteam::pushuint64(L, data->m_ulSteamIDLobby);
		lua_setfield(L, -2, "m_ulSteamIDLobby");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<LobbyEnter_t>::Result(LobbyEnter_t *data, bool io_fail) {
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
		lua_createtable(L, 0, 4);
		luasteam::pushuint64(L, data->m_ulSteamIDLobby);
		lua_setfield(L, -2, "m_ulSteamIDLobby");
		lua_pushinteger(L, data->m_rgfChatPermissions);
		lua_setfield(L, -2, "m_rgfChatPermissions");
		lua_pushboolean(L, data->m_bLocked);
		lua_setfield(L, -2, "m_bLocked");
		lua_pushinteger(L, data->m_EChatRoomEnterResponse);
		lua_setfield(L, -2, "m_EChatRoomEnterResponse");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<LobbyMatchList_t>::Result(LobbyMatchList_t *data, bool io_fail) {
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
		lua_createtable(L, 0, 1);
		lua_pushinteger(L, data->m_nLobbiesMatching);
		lua_setfield(L, -2, "m_nLobbiesMatching");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

// In C++:
// int GetFavoriteGameCount();
// In Lua:
// int Matchmaking.GetFavoriteGameCount()
static int luasteam_Matchmaking_GetFavoriteGameCount(lua_State *L) {
	auto *iface = SteamMatchmaking();
	int __ret = iface->GetFavoriteGameCount();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool GetFavoriteGame(int iGame, AppId_t * pnAppID, uint32 * pnIP, uint16 * pnConnPort, uint16 * pnQueryPort, uint32 * punFlags, uint32 * pRTime32LastPlayedOnServer);
// In Lua:
// (bool, pnAppID: int, pnIP: int, pnConnPort: int, pnQueryPort: int, punFlags: int, pRTime32LastPlayedOnServer: int) Matchmaking.GetFavoriteGame(iGame: int)
static int luasteam_Matchmaking_GetFavoriteGame(lua_State *L) {
	auto *iface = SteamMatchmaking();
	int iGame = static_cast<int>(luaL_checkint(L, 1));
	AppId_t pnAppID;
	uint32 pnIP;
	uint16 pnConnPort;
	uint16 pnQueryPort;
	uint32 punFlags;
	uint32 pRTime32LastPlayedOnServer;
	bool __ret = iface->GetFavoriteGame(iGame, &pnAppID, &pnIP, &pnConnPort, &pnQueryPort, &punFlags, &pRTime32LastPlayedOnServer);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pnAppID);
	lua_pushinteger(L, pnIP);
	lua_pushinteger(L, pnConnPort);
	lua_pushinteger(L, pnQueryPort);
	lua_pushinteger(L, punFlags);
	lua_pushinteger(L, pRTime32LastPlayedOnServer);
	return 7;
}

// In C++:
// int AddFavoriteGame(AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags, uint32 rTime32LastPlayedOnServer);
// In Lua:
// int Matchmaking.AddFavoriteGame(nAppID: int, nIP: int, nConnPort: int, nQueryPort: int, unFlags: int, rTime32LastPlayedOnServer: int)
static int luasteam_Matchmaking_AddFavoriteGame(lua_State *L) {
	auto *iface = SteamMatchmaking();
	AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
	uint32 nIP = static_cast<uint32>(luaL_checkint(L, 2));
	uint16 nConnPort = static_cast<uint16>(luaL_checkint(L, 3));
	uint16 nQueryPort = static_cast<uint16>(luaL_checkint(L, 4));
	uint32 unFlags = static_cast<uint32>(luaL_checkint(L, 5));
	uint32 rTime32LastPlayedOnServer = static_cast<uint32>(luaL_checkint(L, 6));
	int __ret = iface->AddFavoriteGame(nAppID, nIP, nConnPort, nQueryPort, unFlags, rTime32LastPlayedOnServer);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool RemoveFavoriteGame(AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags);
// In Lua:
// bool Matchmaking.RemoveFavoriteGame(nAppID: int, nIP: int, nConnPort: int, nQueryPort: int, unFlags: int)
static int luasteam_Matchmaking_RemoveFavoriteGame(lua_State *L) {
	auto *iface = SteamMatchmaking();
	AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
	uint32 nIP = static_cast<uint32>(luaL_checkint(L, 2));
	uint16 nConnPort = static_cast<uint16>(luaL_checkint(L, 3));
	uint16 nQueryPort = static_cast<uint16>(luaL_checkint(L, 4));
	uint32 unFlags = static_cast<uint32>(luaL_checkint(L, 5));
	bool __ret = iface->RemoveFavoriteGame(nAppID, nIP, nConnPort, nQueryPort, unFlags);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t RequestLobbyList();
// In Lua:
// uint64 Matchmaking.RequestLobbyList(callback: function)
static int luasteam_Matchmaking_RequestLobbyList(lua_State *L) {
	auto *iface = SteamMatchmaking();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	SteamAPICall_t __ret = iface->RequestLobbyList();
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<LobbyMatchList_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<LobbyMatchList_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// void AddRequestLobbyListStringFilter(const char * pchKeyToMatch, const char * pchValueToMatch, ELobbyComparison eComparisonType);
// In Lua:
// Matchmaking.AddRequestLobbyListStringFilter(pchKeyToMatch: str, pchValueToMatch: str, eComparisonType: int)
static int luasteam_Matchmaking_AddRequestLobbyListStringFilter(lua_State *L) {
	auto *iface = SteamMatchmaking();
	const char *pchKeyToMatch = luaL_checkstring(L, 1);
	const char *pchValueToMatch = luaL_checkstring(L, 2);
	ELobbyComparison eComparisonType = static_cast<ELobbyComparison>(luaL_checkint(L, 3));
	iface->AddRequestLobbyListStringFilter(pchKeyToMatch, pchValueToMatch, eComparisonType);
	return 0;
}

// In C++:
// void AddRequestLobbyListNumericalFilter(const char * pchKeyToMatch, int nValueToMatch, ELobbyComparison eComparisonType);
// In Lua:
// Matchmaking.AddRequestLobbyListNumericalFilter(pchKeyToMatch: str, nValueToMatch: int, eComparisonType: int)
static int luasteam_Matchmaking_AddRequestLobbyListNumericalFilter(lua_State *L) {
	auto *iface = SteamMatchmaking();
	const char *pchKeyToMatch = luaL_checkstring(L, 1);
	int nValueToMatch = static_cast<int>(luaL_checkint(L, 2));
	ELobbyComparison eComparisonType = static_cast<ELobbyComparison>(luaL_checkint(L, 3));
	iface->AddRequestLobbyListNumericalFilter(pchKeyToMatch, nValueToMatch, eComparisonType);
	return 0;
}

// In C++:
// void AddRequestLobbyListNearValueFilter(const char * pchKeyToMatch, int nValueToBeCloseTo);
// In Lua:
// Matchmaking.AddRequestLobbyListNearValueFilter(pchKeyToMatch: str, nValueToBeCloseTo: int)
static int luasteam_Matchmaking_AddRequestLobbyListNearValueFilter(lua_State *L) {
	auto *iface = SteamMatchmaking();
	const char *pchKeyToMatch = luaL_checkstring(L, 1);
	int nValueToBeCloseTo = static_cast<int>(luaL_checkint(L, 2));
	iface->AddRequestLobbyListNearValueFilter(pchKeyToMatch, nValueToBeCloseTo);
	return 0;
}

// In C++:
// void AddRequestLobbyListFilterSlotsAvailable(int nSlotsAvailable);
// In Lua:
// Matchmaking.AddRequestLobbyListFilterSlotsAvailable(nSlotsAvailable: int)
static int luasteam_Matchmaking_AddRequestLobbyListFilterSlotsAvailable(lua_State *L) {
	auto *iface = SteamMatchmaking();
	int nSlotsAvailable = static_cast<int>(luaL_checkint(L, 1));
	iface->AddRequestLobbyListFilterSlotsAvailable(nSlotsAvailable);
	return 0;
}

// In C++:
// void AddRequestLobbyListDistanceFilter(ELobbyDistanceFilter eLobbyDistanceFilter);
// In Lua:
// Matchmaking.AddRequestLobbyListDistanceFilter(eLobbyDistanceFilter: int)
static int luasteam_Matchmaking_AddRequestLobbyListDistanceFilter(lua_State *L) {
	auto *iface = SteamMatchmaking();
	ELobbyDistanceFilter eLobbyDistanceFilter = static_cast<ELobbyDistanceFilter>(luaL_checkint(L, 1));
	iface->AddRequestLobbyListDistanceFilter(eLobbyDistanceFilter);
	return 0;
}

// In C++:
// void AddRequestLobbyListResultCountFilter(int cMaxResults);
// In Lua:
// Matchmaking.AddRequestLobbyListResultCountFilter(cMaxResults: int)
static int luasteam_Matchmaking_AddRequestLobbyListResultCountFilter(lua_State *L) {
	auto *iface = SteamMatchmaking();
	int cMaxResults = static_cast<int>(luaL_checkint(L, 1));
	iface->AddRequestLobbyListResultCountFilter(cMaxResults);
	return 0;
}

// In C++:
// void AddRequestLobbyListCompatibleMembersFilter(CSteamID steamIDLobby);
// In Lua:
// Matchmaking.AddRequestLobbyListCompatibleMembersFilter(steamIDLobby: uint64)
static int luasteam_Matchmaking_AddRequestLobbyListCompatibleMembersFilter(lua_State *L) {
	auto *iface = SteamMatchmaking();
	CSteamID steamIDLobby = CSteamID(luasteam::checkuint64(L, 1));
	iface->AddRequestLobbyListCompatibleMembersFilter(steamIDLobby);
	return 0;
}

// In C++:
// CSteamID GetLobbyByIndex(int iLobby);
// In Lua:
// uint64 Matchmaking.GetLobbyByIndex(iLobby: int)
static int luasteam_Matchmaking_GetLobbyByIndex(lua_State *L) {
	auto *iface = SteamMatchmaking();
	int iLobby = static_cast<int>(luaL_checkint(L, 1));
	CSteamID __ret = iface->GetLobbyByIndex(iLobby);
	luasteam::pushuint64(L, __ret.ConvertToUint64());
	return 1;
}

// In C++:
// SteamAPICall_t CreateLobby(ELobbyType eLobbyType, int cMaxMembers);
// In Lua:
// uint64 Matchmaking.CreateLobby(eLobbyType: int, cMaxMembers: int, callback: function)
static int luasteam_Matchmaking_CreateLobby(lua_State *L) {
	auto *iface = SteamMatchmaking();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	ELobbyType eLobbyType = static_cast<ELobbyType>(luaL_checkint(L, 1));
	int cMaxMembers = static_cast<int>(luaL_checkint(L, 2));
	SteamAPICall_t __ret = iface->CreateLobby(eLobbyType, cMaxMembers);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<LobbyCreated_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<LobbyCreated_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t JoinLobby(CSteamID steamIDLobby);
// In Lua:
// uint64 Matchmaking.JoinLobby(steamIDLobby: uint64, callback: function)
static int luasteam_Matchmaking_JoinLobby(lua_State *L) {
	auto *iface = SteamMatchmaking();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	CSteamID steamIDLobby = CSteamID(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = iface->JoinLobby(steamIDLobby);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<LobbyEnter_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<LobbyEnter_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// void LeaveLobby(CSteamID steamIDLobby);
// In Lua:
// Matchmaking.LeaveLobby(steamIDLobby: uint64)
static int luasteam_Matchmaking_LeaveLobby(lua_State *L) {
	auto *iface = SteamMatchmaking();
	CSteamID steamIDLobby = CSteamID(luasteam::checkuint64(L, 1));
	iface->LeaveLobby(steamIDLobby);
	return 0;
}

// In C++:
// bool InviteUserToLobby(CSteamID steamIDLobby, CSteamID steamIDInvitee);
// In Lua:
// bool Matchmaking.InviteUserToLobby(steamIDLobby: uint64, steamIDInvitee: uint64)
static int luasteam_Matchmaking_InviteUserToLobby(lua_State *L) {
	auto *iface = SteamMatchmaking();
	CSteamID steamIDLobby = CSteamID(luasteam::checkuint64(L, 1));
	CSteamID steamIDInvitee = CSteamID(luasteam::checkuint64(L, 2));
	bool __ret = iface->InviteUserToLobby(steamIDLobby, steamIDInvitee);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// int GetNumLobbyMembers(CSteamID steamIDLobby);
// In Lua:
// int Matchmaking.GetNumLobbyMembers(steamIDLobby: uint64)
static int luasteam_Matchmaking_GetNumLobbyMembers(lua_State *L) {
	auto *iface = SteamMatchmaking();
	CSteamID steamIDLobby = CSteamID(luasteam::checkuint64(L, 1));
	int __ret = iface->GetNumLobbyMembers(steamIDLobby);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// CSteamID GetLobbyMemberByIndex(CSteamID steamIDLobby, int iMember);
// In Lua:
// uint64 Matchmaking.GetLobbyMemberByIndex(steamIDLobby: uint64, iMember: int)
static int luasteam_Matchmaking_GetLobbyMemberByIndex(lua_State *L) {
	auto *iface = SteamMatchmaking();
	CSteamID steamIDLobby = CSteamID(luasteam::checkuint64(L, 1));
	int iMember = static_cast<int>(luaL_checkint(L, 2));
	CSteamID __ret = iface->GetLobbyMemberByIndex(steamIDLobby, iMember);
	luasteam::pushuint64(L, __ret.ConvertToUint64());
	return 1;
}

// In C++:
// const char * GetLobbyData(CSteamID steamIDLobby, const char * pchKey);
// In Lua:
// str Matchmaking.GetLobbyData(steamIDLobby: uint64, pchKey: str)
static int luasteam_Matchmaking_GetLobbyData(lua_State *L) {
	auto *iface = SteamMatchmaking();
	CSteamID steamIDLobby = CSteamID(luasteam::checkuint64(L, 1));
	const char *pchKey = luaL_checkstring(L, 2);
	const char * __ret = iface->GetLobbyData(steamIDLobby, pchKey);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// bool SetLobbyData(CSteamID steamIDLobby, const char * pchKey, const char * pchValue);
// In Lua:
// bool Matchmaking.SetLobbyData(steamIDLobby: uint64, pchKey: str, pchValue: str)
static int luasteam_Matchmaking_SetLobbyData(lua_State *L) {
	auto *iface = SteamMatchmaking();
	CSteamID steamIDLobby = CSteamID(luasteam::checkuint64(L, 1));
	const char *pchKey = luaL_checkstring(L, 2);
	const char *pchValue = luaL_checkstring(L, 3);
	bool __ret = iface->SetLobbyData(steamIDLobby, pchKey, pchValue);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// int GetLobbyDataCount(CSteamID steamIDLobby);
// In Lua:
// int Matchmaking.GetLobbyDataCount(steamIDLobby: uint64)
static int luasteam_Matchmaking_GetLobbyDataCount(lua_State *L) {
	auto *iface = SteamMatchmaking();
	CSteamID steamIDLobby = CSteamID(luasteam::checkuint64(L, 1));
	int __ret = iface->GetLobbyDataCount(steamIDLobby);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool GetLobbyDataByIndex(CSteamID steamIDLobby, int iLobbyData, char * pchKey, int cchKeyBufferSize, char * pchValue, int cchValueBufferSize);
// In Lua:
// (bool, pchKey: str, pchValue: str) Matchmaking.GetLobbyDataByIndex(steamIDLobby: uint64, iLobbyData: int, cchKeyBufferSize: int, cchValueBufferSize: int)
static int luasteam_Matchmaking_GetLobbyDataByIndex(lua_State *L) {
	auto *iface = SteamMatchmaking();
	CSteamID steamIDLobby = CSteamID(luasteam::checkuint64(L, 1));
	int iLobbyData = static_cast<int>(luaL_checkint(L, 2));
	int cchKeyBufferSize = luaL_checkint(L, 3);
	std::vector<char> pchKey(cchKeyBufferSize);
	int cchValueBufferSize = luaL_checkint(L, 4);
	std::vector<char> pchValue(cchValueBufferSize);
	bool __ret = iface->GetLobbyDataByIndex(steamIDLobby, iLobbyData, pchKey.data(), cchKeyBufferSize, pchValue.data(), cchValueBufferSize);
	lua_pushboolean(L, __ret);
	lua_pushstring(L, reinterpret_cast<const char*>(pchKey.data()));
	lua_pushstring(L, reinterpret_cast<const char*>(pchValue.data()));
	return 3;
}

// In C++:
// bool DeleteLobbyData(CSteamID steamIDLobby, const char * pchKey);
// In Lua:
// bool Matchmaking.DeleteLobbyData(steamIDLobby: uint64, pchKey: str)
static int luasteam_Matchmaking_DeleteLobbyData(lua_State *L) {
	auto *iface = SteamMatchmaking();
	CSteamID steamIDLobby = CSteamID(luasteam::checkuint64(L, 1));
	const char *pchKey = luaL_checkstring(L, 2);
	bool __ret = iface->DeleteLobbyData(steamIDLobby, pchKey);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// const char * GetLobbyMemberData(CSteamID steamIDLobby, CSteamID steamIDUser, const char * pchKey);
// In Lua:
// str Matchmaking.GetLobbyMemberData(steamIDLobby: uint64, steamIDUser: uint64, pchKey: str)
static int luasteam_Matchmaking_GetLobbyMemberData(lua_State *L) {
	auto *iface = SteamMatchmaking();
	CSteamID steamIDLobby = CSteamID(luasteam::checkuint64(L, 1));
	CSteamID steamIDUser = CSteamID(luasteam::checkuint64(L, 2));
	const char *pchKey = luaL_checkstring(L, 3);
	const char * __ret = iface->GetLobbyMemberData(steamIDLobby, steamIDUser, pchKey);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// void SetLobbyMemberData(CSteamID steamIDLobby, const char * pchKey, const char * pchValue);
// In Lua:
// Matchmaking.SetLobbyMemberData(steamIDLobby: uint64, pchKey: str, pchValue: str)
static int luasteam_Matchmaking_SetLobbyMemberData(lua_State *L) {
	auto *iface = SteamMatchmaking();
	CSteamID steamIDLobby = CSteamID(luasteam::checkuint64(L, 1));
	const char *pchKey = luaL_checkstring(L, 2);
	const char *pchValue = luaL_checkstring(L, 3);
	iface->SetLobbyMemberData(steamIDLobby, pchKey, pchValue);
	return 0;
}

// In C++:
// bool SendLobbyChatMsg(CSteamID steamIDLobby, const void * pvMsgBody, int cubMsgBody);
// In Lua:
// bool Matchmaking.SendLobbyChatMsg(steamIDLobby: uint64, pvMsgBody: str, cubMsgBody: int)
static int luasteam_Matchmaking_SendLobbyChatMsg(lua_State *L) {
	auto *iface = SteamMatchmaking();
	CSteamID steamIDLobby = CSteamID(luasteam::checkuint64(L, 1));
	int cubMsgBody = luaL_checkint(L, 3);
	size_t _len__tmp0;
	const char *_tmp0 = luaL_checklstring(L, 2, &_len__tmp0);
	const void *pvMsgBody = reinterpret_cast<const void *>(_tmp0);
	bool __ret = iface->SendLobbyChatMsg(steamIDLobby, pvMsgBody, cubMsgBody);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// int GetLobbyChatEntry(CSteamID steamIDLobby, int iChatID, CSteamID * pSteamIDUser, void * pvData, int cubData, EChatEntryType * peChatEntryType);
// In Lua:
// (int, pSteamIDUser: uint64, pvData: str, peChatEntryType: int) Matchmaking.GetLobbyChatEntry(steamIDLobby: uint64, iChatID: int, cubData: int)
static int luasteam_Matchmaking_GetLobbyChatEntry(lua_State *L) {
	auto *iface = SteamMatchmaking();
	CSteamID steamIDLobby = CSteamID(luasteam::checkuint64(L, 1));
	int iChatID = static_cast<int>(luaL_checkint(L, 2));
	CSteamID pSteamIDUser;
	int cubData = luaL_checkint(L, 3);
	std::vector<unsigned char> pvData(cubData);
	EChatEntryType peChatEntryType;
	int __ret = iface->GetLobbyChatEntry(steamIDLobby, iChatID, &pSteamIDUser, pvData.data(), cubData, &peChatEntryType);
	lua_pushinteger(L, __ret);
	luasteam::pushuint64(L, pSteamIDUser.ConvertToUint64());
	lua_pushlstring(L, reinterpret_cast<const char*>(pvData.data()), __ret);
	lua_pushinteger(L, peChatEntryType);
	return 4;
}

// In C++:
// bool RequestLobbyData(CSteamID steamIDLobby);
// In Lua:
// bool Matchmaking.RequestLobbyData(steamIDLobby: uint64)
static int luasteam_Matchmaking_RequestLobbyData(lua_State *L) {
	auto *iface = SteamMatchmaking();
	CSteamID steamIDLobby = CSteamID(luasteam::checkuint64(L, 1));
	bool __ret = iface->RequestLobbyData(steamIDLobby);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// void SetLobbyGameServer(CSteamID steamIDLobby, uint32 unGameServerIP, uint16 unGameServerPort, CSteamID steamIDGameServer);
// In Lua:
// Matchmaking.SetLobbyGameServer(steamIDLobby: uint64, unGameServerIP: int, unGameServerPort: int, steamIDGameServer: uint64)
static int luasteam_Matchmaking_SetLobbyGameServer(lua_State *L) {
	auto *iface = SteamMatchmaking();
	CSteamID steamIDLobby = CSteamID(luasteam::checkuint64(L, 1));
	uint32 unGameServerIP = static_cast<uint32>(luaL_checkint(L, 2));
	uint16 unGameServerPort = static_cast<uint16>(luaL_checkint(L, 3));
	CSteamID steamIDGameServer = CSteamID(luasteam::checkuint64(L, 4));
	iface->SetLobbyGameServer(steamIDLobby, unGameServerIP, unGameServerPort, steamIDGameServer);
	return 0;
}

// In C++:
// bool GetLobbyGameServer(CSteamID steamIDLobby, uint32 * punGameServerIP, uint16 * punGameServerPort, CSteamID * psteamIDGameServer);
// In Lua:
// (bool, punGameServerIP: int, punGameServerPort: int, psteamIDGameServer: uint64) Matchmaking.GetLobbyGameServer(steamIDLobby: uint64)
static int luasteam_Matchmaking_GetLobbyGameServer(lua_State *L) {
	auto *iface = SteamMatchmaking();
	CSteamID steamIDLobby = CSteamID(luasteam::checkuint64(L, 1));
	uint32 punGameServerIP;
	uint16 punGameServerPort;
	CSteamID psteamIDGameServer;
	bool __ret = iface->GetLobbyGameServer(steamIDLobby, &punGameServerIP, &punGameServerPort, &psteamIDGameServer);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, punGameServerIP);
	lua_pushinteger(L, punGameServerPort);
	luasteam::pushuint64(L, psteamIDGameServer.ConvertToUint64());
	return 4;
}

// In C++:
// bool SetLobbyMemberLimit(CSteamID steamIDLobby, int cMaxMembers);
// In Lua:
// bool Matchmaking.SetLobbyMemberLimit(steamIDLobby: uint64, cMaxMembers: int)
static int luasteam_Matchmaking_SetLobbyMemberLimit(lua_State *L) {
	auto *iface = SteamMatchmaking();
	CSteamID steamIDLobby = CSteamID(luasteam::checkuint64(L, 1));
	int cMaxMembers = static_cast<int>(luaL_checkint(L, 2));
	bool __ret = iface->SetLobbyMemberLimit(steamIDLobby, cMaxMembers);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// int GetLobbyMemberLimit(CSteamID steamIDLobby);
// In Lua:
// int Matchmaking.GetLobbyMemberLimit(steamIDLobby: uint64)
static int luasteam_Matchmaking_GetLobbyMemberLimit(lua_State *L) {
	auto *iface = SteamMatchmaking();
	CSteamID steamIDLobby = CSteamID(luasteam::checkuint64(L, 1));
	int __ret = iface->GetLobbyMemberLimit(steamIDLobby);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool SetLobbyType(CSteamID steamIDLobby, ELobbyType eLobbyType);
// In Lua:
// bool Matchmaking.SetLobbyType(steamIDLobby: uint64, eLobbyType: int)
static int luasteam_Matchmaking_SetLobbyType(lua_State *L) {
	auto *iface = SteamMatchmaking();
	CSteamID steamIDLobby = CSteamID(luasteam::checkuint64(L, 1));
	ELobbyType eLobbyType = static_cast<ELobbyType>(luaL_checkint(L, 2));
	bool __ret = iface->SetLobbyType(steamIDLobby, eLobbyType);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetLobbyJoinable(CSteamID steamIDLobby, bool bLobbyJoinable);
// In Lua:
// bool Matchmaking.SetLobbyJoinable(steamIDLobby: uint64, bLobbyJoinable: bool)
static int luasteam_Matchmaking_SetLobbyJoinable(lua_State *L) {
	auto *iface = SteamMatchmaking();
	CSteamID steamIDLobby = CSteamID(luasteam::checkuint64(L, 1));
	bool bLobbyJoinable = lua_toboolean(L, 2);
	bool __ret = iface->SetLobbyJoinable(steamIDLobby, bLobbyJoinable);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// CSteamID GetLobbyOwner(CSteamID steamIDLobby);
// In Lua:
// uint64 Matchmaking.GetLobbyOwner(steamIDLobby: uint64)
static int luasteam_Matchmaking_GetLobbyOwner(lua_State *L) {
	auto *iface = SteamMatchmaking();
	CSteamID steamIDLobby = CSteamID(luasteam::checkuint64(L, 1));
	CSteamID __ret = iface->GetLobbyOwner(steamIDLobby);
	luasteam::pushuint64(L, __ret.ConvertToUint64());
	return 1;
}

// In C++:
// bool SetLobbyOwner(CSteamID steamIDLobby, CSteamID steamIDNewOwner);
// In Lua:
// bool Matchmaking.SetLobbyOwner(steamIDLobby: uint64, steamIDNewOwner: uint64)
static int luasteam_Matchmaking_SetLobbyOwner(lua_State *L) {
	auto *iface = SteamMatchmaking();
	CSteamID steamIDLobby = CSteamID(luasteam::checkuint64(L, 1));
	CSteamID steamIDNewOwner = CSteamID(luasteam::checkuint64(L, 2));
	bool __ret = iface->SetLobbyOwner(steamIDLobby, steamIDNewOwner);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetLinkedLobby(CSteamID steamIDLobby, CSteamID steamIDLobbyDependent);
// In Lua:
// bool Matchmaking.SetLinkedLobby(steamIDLobby: uint64, steamIDLobbyDependent: uint64)
static int luasteam_Matchmaking_SetLinkedLobby(lua_State *L) {
	auto *iface = SteamMatchmaking();
	CSteamID steamIDLobby = CSteamID(luasteam::checkuint64(L, 1));
	CSteamID steamIDLobbyDependent = CSteamID(luasteam::checkuint64(L, 2));
	bool __ret = iface->SetLinkedLobby(steamIDLobby, steamIDLobbyDependent);
	lua_pushboolean(L, __ret);
	return 1;
}

void register_Matchmaking_auto(lua_State *L) {
	add_func(L, "GetFavoriteGameCount", luasteam_Matchmaking_GetFavoriteGameCount);
	add_func(L, "GetFavoriteGame", luasteam_Matchmaking_GetFavoriteGame);
	add_func(L, "AddFavoriteGame", luasteam_Matchmaking_AddFavoriteGame);
	add_func(L, "RemoveFavoriteGame", luasteam_Matchmaking_RemoveFavoriteGame);
	add_func(L, "RequestLobbyList", luasteam_Matchmaking_RequestLobbyList);
	add_func(L, "AddRequestLobbyListStringFilter", luasteam_Matchmaking_AddRequestLobbyListStringFilter);
	add_func(L, "AddRequestLobbyListNumericalFilter", luasteam_Matchmaking_AddRequestLobbyListNumericalFilter);
	add_func(L, "AddRequestLobbyListNearValueFilter", luasteam_Matchmaking_AddRequestLobbyListNearValueFilter);
	add_func(L, "AddRequestLobbyListFilterSlotsAvailable", luasteam_Matchmaking_AddRequestLobbyListFilterSlotsAvailable);
	add_func(L, "AddRequestLobbyListDistanceFilter", luasteam_Matchmaking_AddRequestLobbyListDistanceFilter);
	add_func(L, "AddRequestLobbyListResultCountFilter", luasteam_Matchmaking_AddRequestLobbyListResultCountFilter);
	add_func(L, "AddRequestLobbyListCompatibleMembersFilter", luasteam_Matchmaking_AddRequestLobbyListCompatibleMembersFilter);
	add_func(L, "GetLobbyByIndex", luasteam_Matchmaking_GetLobbyByIndex);
	add_func(L, "CreateLobby", luasteam_Matchmaking_CreateLobby);
	add_func(L, "JoinLobby", luasteam_Matchmaking_JoinLobby);
	add_func(L, "LeaveLobby", luasteam_Matchmaking_LeaveLobby);
	add_func(L, "InviteUserToLobby", luasteam_Matchmaking_InviteUserToLobby);
	add_func(L, "GetNumLobbyMembers", luasteam_Matchmaking_GetNumLobbyMembers);
	add_func(L, "GetLobbyMemberByIndex", luasteam_Matchmaking_GetLobbyMemberByIndex);
	add_func(L, "GetLobbyData", luasteam_Matchmaking_GetLobbyData);
	add_func(L, "SetLobbyData", luasteam_Matchmaking_SetLobbyData);
	add_func(L, "GetLobbyDataCount", luasteam_Matchmaking_GetLobbyDataCount);
	add_func(L, "GetLobbyDataByIndex", luasteam_Matchmaking_GetLobbyDataByIndex);
	add_func(L, "DeleteLobbyData", luasteam_Matchmaking_DeleteLobbyData);
	add_func(L, "GetLobbyMemberData", luasteam_Matchmaking_GetLobbyMemberData);
	add_func(L, "SetLobbyMemberData", luasteam_Matchmaking_SetLobbyMemberData);
	add_func(L, "SendLobbyChatMsg", luasteam_Matchmaking_SendLobbyChatMsg);
	add_func(L, "GetLobbyChatEntry", luasteam_Matchmaking_GetLobbyChatEntry);
	add_func(L, "RequestLobbyData", luasteam_Matchmaking_RequestLobbyData);
	add_func(L, "SetLobbyGameServer", luasteam_Matchmaking_SetLobbyGameServer);
	add_func(L, "GetLobbyGameServer", luasteam_Matchmaking_GetLobbyGameServer);
	add_func(L, "SetLobbyMemberLimit", luasteam_Matchmaking_SetLobbyMemberLimit);
	add_func(L, "GetLobbyMemberLimit", luasteam_Matchmaking_GetLobbyMemberLimit);
	add_func(L, "SetLobbyType", luasteam_Matchmaking_SetLobbyType);
	add_func(L, "SetLobbyJoinable", luasteam_Matchmaking_SetLobbyJoinable);
	add_func(L, "GetLobbyOwner", luasteam_Matchmaking_GetLobbyOwner);
	add_func(L, "SetLobbyOwner", luasteam_Matchmaking_SetLobbyOwner);
	add_func(L, "SetLinkedLobby", luasteam_Matchmaking_SetLinkedLobby);
}

void add_Matchmaking_auto(lua_State *L) {
	lua_createtable(L, 0, 38);
	register_Matchmaking_auto(L);
	lua_pushvalue(L, -1);
	Matchmaking_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "Matchmaking");
}

} // namespace luasteam
