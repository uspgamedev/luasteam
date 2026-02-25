#include "auto.hpp"

namespace luasteam {

int GameServer_ref = LUA_NOREF;

namespace {
class GameServerCallbackListener {
private:
	STEAM_GAMESERVER_CALLBACK(GameServerCallbackListener, OnSteamServersConnected, SteamServersConnected_t);
	STEAM_GAMESERVER_CALLBACK(GameServerCallbackListener, OnSteamServerConnectFailure, SteamServerConnectFailure_t);
	STEAM_GAMESERVER_CALLBACK(GameServerCallbackListener, OnSteamServersDisconnected, SteamServersDisconnected_t);
	STEAM_GAMESERVER_CALLBACK(GameServerCallbackListener, OnValidateAuthTicketResponse, ValidateAuthTicketResponse_t);
	STEAM_GAMESERVER_CALLBACK(GameServerCallbackListener, OnGSClientApprove, GSClientApprove_t);
	STEAM_GAMESERVER_CALLBACK(GameServerCallbackListener, OnGSClientDeny, GSClientDeny_t);
	STEAM_GAMESERVER_CALLBACK(GameServerCallbackListener, OnGSClientKick, GSClientKick_t);
	STEAM_GAMESERVER_CALLBACK(GameServerCallbackListener, OnGSClientAchievementStatus, GSClientAchievementStatus_t);
	STEAM_GAMESERVER_CALLBACK(GameServerCallbackListener, OnGSPolicyResponse, GSPolicyResponse_t);
	STEAM_GAMESERVER_CALLBACK(GameServerCallbackListener, OnGSGameplayStats, GSGameplayStats_t);
	STEAM_GAMESERVER_CALLBACK(GameServerCallbackListener, OnGSClientGroupStatus, GSClientGroupStatus_t);
	STEAM_GAMESERVER_CALLBACK(GameServerCallbackListener, OnGSReputation, GSReputation_t);
	STEAM_GAMESERVER_CALLBACK(GameServerCallbackListener, OnAssociateWithClanResult, AssociateWithClanResult_t);
	STEAM_GAMESERVER_CALLBACK(GameServerCallbackListener, OnComputeNewPlayerCompatibilityResult, ComputeNewPlayerCompatibilityResult_t);
};
void GameServerCallbackListener::OnSteamServersConnected(SteamServersConnected_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServer_ref);
	lua_getfield(L, -1, "OnSteamServersConnected");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamServersConnected_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerCallbackListener::OnSteamServerConnectFailure(SteamServerConnectFailure_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServer_ref);
	lua_getfield(L, -1, "OnSteamServerConnectFailure");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamServerConnectFailure_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerCallbackListener::OnSteamServersDisconnected(SteamServersDisconnected_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServer_ref);
	lua_getfield(L, -1, "OnSteamServersDisconnected");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamServersDisconnected_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerCallbackListener::OnValidateAuthTicketResponse(ValidateAuthTicketResponse_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServer_ref);
	lua_getfield(L, -1, "OnValidateAuthTicketResponse");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_ValidateAuthTicketResponse_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerCallbackListener::OnGSClientApprove(GSClientApprove_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServer_ref);
	lua_getfield(L, -1, "OnGSClientApprove");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_GSClientApprove_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerCallbackListener::OnGSClientDeny(GSClientDeny_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServer_ref);
	lua_getfield(L, -1, "OnGSClientDeny");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_GSClientDeny_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerCallbackListener::OnGSClientKick(GSClientKick_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServer_ref);
	lua_getfield(L, -1, "OnGSClientKick");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_GSClientKick_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerCallbackListener::OnGSClientAchievementStatus(GSClientAchievementStatus_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServer_ref);
	lua_getfield(L, -1, "OnGSClientAchievementStatus");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_GSClientAchievementStatus_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerCallbackListener::OnGSPolicyResponse(GSPolicyResponse_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServer_ref);
	lua_getfield(L, -1, "OnGSPolicyResponse");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_GSPolicyResponse_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerCallbackListener::OnGSGameplayStats(GSGameplayStats_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServer_ref);
	lua_getfield(L, -1, "OnGSGameplayStats");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_GSGameplayStats_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerCallbackListener::OnGSClientGroupStatus(GSClientGroupStatus_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServer_ref);
	lua_getfield(L, -1, "OnGSClientGroupStatus");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_GSClientGroupStatus_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerCallbackListener::OnGSReputation(GSReputation_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServer_ref);
	lua_getfield(L, -1, "OnGSReputation");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_GSReputation_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerCallbackListener::OnAssociateWithClanResult(AssociateWithClanResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServer_ref);
	lua_getfield(L, -1, "OnAssociateWithClanResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_AssociateWithClanResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerCallbackListener::OnComputeNewPlayerCompatibilityResult(ComputeNewPlayerCompatibilityResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServer_ref);
	lua_getfield(L, -1, "OnComputeNewPlayerCompatibilityResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_ComputeNewPlayerCompatibilityResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
GameServerCallbackListener *GameServer_listener = nullptr;
} // namespace

void init_GameServer_auto(lua_State *L) { GameServer_listener = new GameServerCallbackListener(); }
void shutdown_GameServer_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, GameServer_ref);
	GameServer_ref = LUA_NOREF;
	delete GameServer_listener; GameServer_listener = nullptr;
}

template <> void CallResultListener<AssociateWithClanResult_t>::Result(AssociateWithClanResult_t *data, bool io_fail) {
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
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<ComputeNewPlayerCompatibilityResult_t>::Result(ComputeNewPlayerCompatibilityResult_t *data, bool io_fail) {
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
		lua_createtable(L, 0, 5);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		lua_pushinteger(L, data->m_cPlayersThatDontLikeCandidate);
		lua_setfield(L, -2, "m_cPlayersThatDontLikeCandidate");
		lua_pushinteger(L, data->m_cPlayersThatCandidateDoesntLike);
		lua_setfield(L, -2, "m_cPlayersThatCandidateDoesntLike");
		lua_pushinteger(L, data->m_cClanPlayersThatDontLikeCandidate);
		lua_setfield(L, -2, "m_cClanPlayersThatDontLikeCandidate");
		luasteam::pushuint64(L, data->m_SteamIDCandidate.ConvertToUint64());
		lua_setfield(L, -2, "m_SteamIDCandidate");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<GSReputation_t>::Result(GSReputation_t *data, bool io_fail) {
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
		lua_createtable(L, 0, 7);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		lua_pushinteger(L, data->m_unReputationScore);
		lua_setfield(L, -2, "m_unReputationScore");
		lua_pushboolean(L, data->m_bBanned);
		lua_setfield(L, -2, "m_bBanned");
		lua_pushinteger(L, data->m_unBannedIP);
		lua_setfield(L, -2, "m_unBannedIP");
		lua_pushinteger(L, data->m_usBannedPort);
		lua_setfield(L, -2, "m_usBannedPort");
		luasteam::pushuint64(L, data->m_ulBannedGameID);
		lua_setfield(L, -2, "m_ulBannedGameID");
		lua_pushinteger(L, data->m_unBanExpires);
		lua_setfield(L, -2, "m_unBanExpires");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

// In C++:
// void SetProduct(const char * pszProduct);
// In Lua:
// GameServer.SetProduct(pszProduct: str)
static int luasteam_GameServer_SetProduct(lua_State *L) {
	auto *iface = SteamGameServer();
	const char *pszProduct = luaL_checkstring(L, 1);
	iface->SetProduct(pszProduct);
	return 0;
}

// In C++:
// void SetGameDescription(const char * pszGameDescription);
// In Lua:
// GameServer.SetGameDescription(pszGameDescription: str)
static int luasteam_GameServer_SetGameDescription(lua_State *L) {
	auto *iface = SteamGameServer();
	const char *pszGameDescription = luaL_checkstring(L, 1);
	iface->SetGameDescription(pszGameDescription);
	return 0;
}

// In C++:
// void SetModDir(const char * pszModDir);
// In Lua:
// GameServer.SetModDir(pszModDir: str)
static int luasteam_GameServer_SetModDir(lua_State *L) {
	auto *iface = SteamGameServer();
	const char *pszModDir = luaL_checkstring(L, 1);
	iface->SetModDir(pszModDir);
	return 0;
}

// In C++:
// void SetDedicatedServer(bool bDedicated);
// In Lua:
// GameServer.SetDedicatedServer(bDedicated: bool)
static int luasteam_GameServer_SetDedicatedServer(lua_State *L) {
	auto *iface = SteamGameServer();
	bool bDedicated = lua_toboolean(L, 1);
	iface->SetDedicatedServer(bDedicated);
	return 0;
}

// In C++:
// void LogOn(const char * pszToken);
// In Lua:
// GameServer.LogOn(pszToken: str)
static int luasteam_GameServer_LogOn(lua_State *L) {
	auto *iface = SteamGameServer();
	const char *pszToken = luaL_checkstring(L, 1);
	iface->LogOn(pszToken);
	return 0;
}

// In C++:
// void LogOnAnonymous();
// In Lua:
// GameServer.LogOnAnonymous()
static int luasteam_GameServer_LogOnAnonymous(lua_State *L) {
	auto *iface = SteamGameServer();
	iface->LogOnAnonymous();
	return 0;
}

// In C++:
// void LogOff();
// In Lua:
// GameServer.LogOff()
static int luasteam_GameServer_LogOff(lua_State *L) {
	auto *iface = SteamGameServer();
	iface->LogOff();
	return 0;
}

// In C++:
// bool BLoggedOn();
// In Lua:
// bool GameServer.BLoggedOn()
static int luasteam_GameServer_BLoggedOn(lua_State *L) {
	auto *iface = SteamGameServer();
	bool __ret = iface->BLoggedOn();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool BSecure();
// In Lua:
// bool GameServer.BSecure()
static int luasteam_GameServer_BSecure(lua_State *L) {
	auto *iface = SteamGameServer();
	bool __ret = iface->BSecure();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// CSteamID GetSteamID();
// In Lua:
// uint64 GameServer.GetSteamID()
static int luasteam_GameServer_GetSteamID(lua_State *L) {
	auto *iface = SteamGameServer();
	CSteamID __ret = iface->GetSteamID();
	luasteam::pushuint64(L, __ret.ConvertToUint64());
	return 1;
}

// In C++:
// bool WasRestartRequested();
// In Lua:
// bool GameServer.WasRestartRequested()
static int luasteam_GameServer_WasRestartRequested(lua_State *L) {
	auto *iface = SteamGameServer();
	bool __ret = iface->WasRestartRequested();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// void SetMaxPlayerCount(int cPlayersMax);
// In Lua:
// GameServer.SetMaxPlayerCount(cPlayersMax: int)
static int luasteam_GameServer_SetMaxPlayerCount(lua_State *L) {
	auto *iface = SteamGameServer();
	int cPlayersMax = static_cast<int>(luaL_checkint(L, 1));
	iface->SetMaxPlayerCount(cPlayersMax);
	return 0;
}

// In C++:
// void SetBotPlayerCount(int cBotplayers);
// In Lua:
// GameServer.SetBotPlayerCount(cBotplayers: int)
static int luasteam_GameServer_SetBotPlayerCount(lua_State *L) {
	auto *iface = SteamGameServer();
	int cBotplayers = static_cast<int>(luaL_checkint(L, 1));
	iface->SetBotPlayerCount(cBotplayers);
	return 0;
}

// In C++:
// void SetServerName(const char * pszServerName);
// In Lua:
// GameServer.SetServerName(pszServerName: str)
static int luasteam_GameServer_SetServerName(lua_State *L) {
	auto *iface = SteamGameServer();
	const char *pszServerName = luaL_checkstring(L, 1);
	iface->SetServerName(pszServerName);
	return 0;
}

// In C++:
// void SetMapName(const char * pszMapName);
// In Lua:
// GameServer.SetMapName(pszMapName: str)
static int luasteam_GameServer_SetMapName(lua_State *L) {
	auto *iface = SteamGameServer();
	const char *pszMapName = luaL_checkstring(L, 1);
	iface->SetMapName(pszMapName);
	return 0;
}

// In C++:
// void SetPasswordProtected(bool bPasswordProtected);
// In Lua:
// GameServer.SetPasswordProtected(bPasswordProtected: bool)
static int luasteam_GameServer_SetPasswordProtected(lua_State *L) {
	auto *iface = SteamGameServer();
	bool bPasswordProtected = lua_toboolean(L, 1);
	iface->SetPasswordProtected(bPasswordProtected);
	return 0;
}

// In C++:
// void SetSpectatorPort(uint16 unSpectatorPort);
// In Lua:
// GameServer.SetSpectatorPort(unSpectatorPort: int)
static int luasteam_GameServer_SetSpectatorPort(lua_State *L) {
	auto *iface = SteamGameServer();
	uint16 unSpectatorPort = static_cast<uint16>(luaL_checkint(L, 1));
	iface->SetSpectatorPort(unSpectatorPort);
	return 0;
}

// In C++:
// void SetSpectatorServerName(const char * pszSpectatorServerName);
// In Lua:
// GameServer.SetSpectatorServerName(pszSpectatorServerName: str)
static int luasteam_GameServer_SetSpectatorServerName(lua_State *L) {
	auto *iface = SteamGameServer();
	const char *pszSpectatorServerName = luaL_checkstring(L, 1);
	iface->SetSpectatorServerName(pszSpectatorServerName);
	return 0;
}

// In C++:
// void ClearAllKeyValues();
// In Lua:
// GameServer.ClearAllKeyValues()
static int luasteam_GameServer_ClearAllKeyValues(lua_State *L) {
	auto *iface = SteamGameServer();
	iface->ClearAllKeyValues();
	return 0;
}

// In C++:
// void SetKeyValue(const char * pKey, const char * pValue);
// In Lua:
// GameServer.SetKeyValue(pKey: str, pValue: str)
static int luasteam_GameServer_SetKeyValue(lua_State *L) {
	auto *iface = SteamGameServer();
	const char *pKey = luaL_checkstring(L, 1);
	const char *pValue = luaL_checkstring(L, 2);
	iface->SetKeyValue(pKey, pValue);
	return 0;
}

// In C++:
// void SetGameTags(const char * pchGameTags);
// In Lua:
// GameServer.SetGameTags(pchGameTags: str)
static int luasteam_GameServer_SetGameTags(lua_State *L) {
	auto *iface = SteamGameServer();
	const char *pchGameTags = luaL_checkstring(L, 1);
	iface->SetGameTags(pchGameTags);
	return 0;
}

// In C++:
// void SetGameData(const char * pchGameData);
// In Lua:
// GameServer.SetGameData(pchGameData: str)
static int luasteam_GameServer_SetGameData(lua_State *L) {
	auto *iface = SteamGameServer();
	const char *pchGameData = luaL_checkstring(L, 1);
	iface->SetGameData(pchGameData);
	return 0;
}

// In C++:
// void SetRegion(const char * pszRegion);
// In Lua:
// GameServer.SetRegion(pszRegion: str)
static int luasteam_GameServer_SetRegion(lua_State *L) {
	auto *iface = SteamGameServer();
	const char *pszRegion = luaL_checkstring(L, 1);
	iface->SetRegion(pszRegion);
	return 0;
}

// In C++:
// void SetAdvertiseServerActive(bool bActive);
// In Lua:
// GameServer.SetAdvertiseServerActive(bActive: bool)
static int luasteam_GameServer_SetAdvertiseServerActive(lua_State *L) {
	auto *iface = SteamGameServer();
	bool bActive = lua_toboolean(L, 1);
	iface->SetAdvertiseServerActive(bActive);
	return 0;
}

// In C++:
// HAuthTicket GetAuthSessionTicket(void * pTicket, int cbMaxTicket, uint32 * pcbTicket, const SteamNetworkingIdentity * pSnid);
// In Lua:
// (int, pTicket: str, pcbTicket: int) GameServer.GetAuthSessionTicket(cbMaxTicket: int, pSnid: SteamNetworkingIdentity)
static int luasteam_GameServer_GetAuthSessionTicket(lua_State *L) {
	auto *iface = SteamGameServer();
	int cbMaxTicket = luaL_checkint(L, 1);
	uint32 pcbTicket = cbMaxTicket;
	std::vector<unsigned char> pTicket(cbMaxTicket);
	const SteamNetworkingIdentity *pSnid = lua_isnil(L, 2) ? nullptr : luasteam::check_SteamNetworkingIdentity_ptr(L, 2);
	HAuthTicket __ret = iface->GetAuthSessionTicket(pTicket.data(), cbMaxTicket, &pcbTicket, pSnid);
	lua_pushinteger(L, __ret);
	lua_pushlstring(L, reinterpret_cast<const char*>(pTicket.data()), pcbTicket);
	lua_pushinteger(L, pcbTicket);
	return 3;
}

// In C++:
// EBeginAuthSessionResult BeginAuthSession(const void * pAuthTicket, int cbAuthTicket, CSteamID steamID);
// In Lua:
// int GameServer.BeginAuthSession(pAuthTicket: str, cbAuthTicket: int, steamID: uint64)
static int luasteam_GameServer_BeginAuthSession(lua_State *L) {
	auto *iface = SteamGameServer();
	const char *pAuthTicket = luaL_checkstring(L, 1);
	int cbAuthTicket = static_cast<int>(luaL_checkint(L, 2));
	CSteamID steamID(luasteam::checkuint64(L, 3));
	EBeginAuthSessionResult __ret = iface->BeginAuthSession(pAuthTicket, cbAuthTicket, steamID);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// void EndAuthSession(CSteamID steamID);
// In Lua:
// GameServer.EndAuthSession(steamID: uint64)
static int luasteam_GameServer_EndAuthSession(lua_State *L) {
	auto *iface = SteamGameServer();
	CSteamID steamID(luasteam::checkuint64(L, 1));
	iface->EndAuthSession(steamID);
	return 0;
}

// In C++:
// void CancelAuthTicket(HAuthTicket hAuthTicket);
// In Lua:
// GameServer.CancelAuthTicket(hAuthTicket: int)
static int luasteam_GameServer_CancelAuthTicket(lua_State *L) {
	auto *iface = SteamGameServer();
	HAuthTicket hAuthTicket = static_cast<HAuthTicket>(luaL_checkint(L, 1));
	iface->CancelAuthTicket(hAuthTicket);
	return 0;
}

// In C++:
// EUserHasLicenseForAppResult UserHasLicenseForApp(CSteamID steamID, AppId_t appID);
// In Lua:
// int GameServer.UserHasLicenseForApp(steamID: uint64, appID: int)
static int luasteam_GameServer_UserHasLicenseForApp(lua_State *L) {
	auto *iface = SteamGameServer();
	CSteamID steamID(luasteam::checkuint64(L, 1));
	AppId_t appID = static_cast<AppId_t>(luaL_checkint(L, 2));
	EUserHasLicenseForAppResult __ret = iface->UserHasLicenseForApp(steamID, appID);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool RequestUserGroupStatus(CSteamID steamIDUser, CSteamID steamIDGroup);
// In Lua:
// bool GameServer.RequestUserGroupStatus(steamIDUser: uint64, steamIDGroup: uint64)
static int luasteam_GameServer_RequestUserGroupStatus(lua_State *L) {
	auto *iface = SteamGameServer();
	CSteamID steamIDUser(luasteam::checkuint64(L, 1));
	CSteamID steamIDGroup(luasteam::checkuint64(L, 2));
	bool __ret = iface->RequestUserGroupStatus(steamIDUser, steamIDGroup);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// void GetGameplayStats();
// In Lua:
// GameServer.GetGameplayStats()
static int luasteam_GameServer_GetGameplayStats(lua_State *L) {
	auto *iface = SteamGameServer();
	iface->GetGameplayStats();
	return 0;
}

// In C++:
// SteamAPICall_t GetServerReputation();
// In Lua:
// uint64 GameServer.GetServerReputation(callback: function)
static int luasteam_GameServer_GetServerReputation(lua_State *L) {
	auto *iface = SteamGameServer();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	SteamAPICall_t __ret = iface->GetServerReputation();
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<GSReputation_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<GSReputation_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// SteamIPAddress_t GetPublicIP();
// In Lua:
// SteamIPAddress_t GameServer.GetPublicIP()
static int luasteam_GameServer_GetPublicIP(lua_State *L) {
	auto *iface = SteamGameServer();
	SteamIPAddress_t __ret = iface->GetPublicIP();
	luasteam::push_SteamIPAddress_t(L, __ret);
	return 1;
}

// In C++:
// bool HandleIncomingPacket(const void * pData, int cbData, uint32 srcIP, uint16 srcPort);
// In Lua:
// bool GameServer.HandleIncomingPacket(pData: str, cbData: int, srcIP: int, srcPort: int)
static int luasteam_GameServer_HandleIncomingPacket(lua_State *L) {
	auto *iface = SteamGameServer();
	const char *pData = luaL_checkstring(L, 1);
	int cbData = static_cast<int>(luaL_checkint(L, 2));
	uint32 srcIP = static_cast<uint32>(luaL_checkint(L, 3));
	uint16 srcPort = static_cast<uint16>(luaL_checkint(L, 4));
	bool __ret = iface->HandleIncomingPacket(pData, cbData, srcIP, srcPort);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// int GetNextOutgoingPacket(void * pOut, int cbMaxOut, uint32 * pNetAdr, uint16 * pPort);
// In Lua:
// (int, pOut: str, pNetAdr: int, pPort: int) GameServer.GetNextOutgoingPacket(cbMaxOut: int)
static int luasteam_GameServer_GetNextOutgoingPacket(lua_State *L) {
	auto *iface = SteamGameServer();
	int cbMaxOut = luaL_checkint(L, 1);
	std::vector<unsigned char> pOut(cbMaxOut);
	uint32 pNetAdr;
	uint16 pPort;
	int __ret = iface->GetNextOutgoingPacket(pOut.data(), cbMaxOut, &pNetAdr, &pPort);
	lua_pushinteger(L, __ret);
	lua_pushlstring(L, reinterpret_cast<const char*>(pOut.data()), cbMaxOut);
	lua_pushinteger(L, pNetAdr);
	lua_pushinteger(L, pPort);
	return 4;
}

// In C++:
// SteamAPICall_t AssociateWithClan(CSteamID steamIDClan);
// In Lua:
// uint64 GameServer.AssociateWithClan(steamIDClan: uint64, callback: function)
static int luasteam_GameServer_AssociateWithClan(lua_State *L) {
	auto *iface = SteamGameServer();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	CSteamID steamIDClan(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = iface->AssociateWithClan(steamIDClan);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<AssociateWithClanResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<AssociateWithClanResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t ComputeNewPlayerCompatibility(CSteamID steamIDNewPlayer);
// In Lua:
// uint64 GameServer.ComputeNewPlayerCompatibility(steamIDNewPlayer: uint64, callback: function)
static int luasteam_GameServer_ComputeNewPlayerCompatibility(lua_State *L) {
	auto *iface = SteamGameServer();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	CSteamID steamIDNewPlayer(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = iface->ComputeNewPlayerCompatibility(steamIDNewPlayer);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<ComputeNewPlayerCompatibilityResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<ComputeNewPlayerCompatibilityResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// CSteamID CreateUnauthenticatedUserConnection();
// In Lua:
// uint64 GameServer.CreateUnauthenticatedUserConnection()
static int luasteam_GameServer_CreateUnauthenticatedUserConnection(lua_State *L) {
	auto *iface = SteamGameServer();
	CSteamID __ret = iface->CreateUnauthenticatedUserConnection();
	luasteam::pushuint64(L, __ret.ConvertToUint64());
	return 1;
}

// In C++:
// bool BUpdateUserData(CSteamID steamIDUser, const char * pchPlayerName, uint32 uScore);
// In Lua:
// bool GameServer.BUpdateUserData(steamIDUser: uint64, pchPlayerName: str, uScore: int)
static int luasteam_GameServer_BUpdateUserData(lua_State *L) {
	auto *iface = SteamGameServer();
	CSteamID steamIDUser(luasteam::checkuint64(L, 1));
	const char *pchPlayerName = luaL_checkstring(L, 2);
	uint32 uScore = static_cast<uint32>(luaL_checkint(L, 3));
	bool __ret = iface->BUpdateUserData(steamIDUser, pchPlayerName, uScore);
	lua_pushboolean(L, __ret);
	return 1;
}

void register_GameServer_auto(lua_State *L) {
	add_func(L, "SetProduct", luasteam_GameServer_SetProduct);
	add_func(L, "SetGameDescription", luasteam_GameServer_SetGameDescription);
	add_func(L, "SetModDir", luasteam_GameServer_SetModDir);
	add_func(L, "SetDedicatedServer", luasteam_GameServer_SetDedicatedServer);
	add_func(L, "LogOn", luasteam_GameServer_LogOn);
	add_func(L, "LogOnAnonymous", luasteam_GameServer_LogOnAnonymous);
	add_func(L, "LogOff", luasteam_GameServer_LogOff);
	add_func(L, "BLoggedOn", luasteam_GameServer_BLoggedOn);
	add_func(L, "BSecure", luasteam_GameServer_BSecure);
	add_func(L, "GetSteamID", luasteam_GameServer_GetSteamID);
	add_func(L, "WasRestartRequested", luasteam_GameServer_WasRestartRequested);
	add_func(L, "SetMaxPlayerCount", luasteam_GameServer_SetMaxPlayerCount);
	add_func(L, "SetBotPlayerCount", luasteam_GameServer_SetBotPlayerCount);
	add_func(L, "SetServerName", luasteam_GameServer_SetServerName);
	add_func(L, "SetMapName", luasteam_GameServer_SetMapName);
	add_func(L, "SetPasswordProtected", luasteam_GameServer_SetPasswordProtected);
	add_func(L, "SetSpectatorPort", luasteam_GameServer_SetSpectatorPort);
	add_func(L, "SetSpectatorServerName", luasteam_GameServer_SetSpectatorServerName);
	add_func(L, "ClearAllKeyValues", luasteam_GameServer_ClearAllKeyValues);
	add_func(L, "SetKeyValue", luasteam_GameServer_SetKeyValue);
	add_func(L, "SetGameTags", luasteam_GameServer_SetGameTags);
	add_func(L, "SetGameData", luasteam_GameServer_SetGameData);
	add_func(L, "SetRegion", luasteam_GameServer_SetRegion);
	add_func(L, "SetAdvertiseServerActive", luasteam_GameServer_SetAdvertiseServerActive);
	add_func(L, "GetAuthSessionTicket", luasteam_GameServer_GetAuthSessionTicket);
	add_func(L, "BeginAuthSession", luasteam_GameServer_BeginAuthSession);
	add_func(L, "EndAuthSession", luasteam_GameServer_EndAuthSession);
	add_func(L, "CancelAuthTicket", luasteam_GameServer_CancelAuthTicket);
	add_func(L, "UserHasLicenseForApp", luasteam_GameServer_UserHasLicenseForApp);
	add_func(L, "RequestUserGroupStatus", luasteam_GameServer_RequestUserGroupStatus);
	add_func(L, "GetGameplayStats", luasteam_GameServer_GetGameplayStats);
	add_func(L, "GetServerReputation", luasteam_GameServer_GetServerReputation);
	add_func(L, "GetPublicIP", luasteam_GameServer_GetPublicIP);
	add_func(L, "HandleIncomingPacket", luasteam_GameServer_HandleIncomingPacket);
	add_func(L, "GetNextOutgoingPacket", luasteam_GameServer_GetNextOutgoingPacket);
	add_func(L, "AssociateWithClan", luasteam_GameServer_AssociateWithClan);
	add_func(L, "ComputeNewPlayerCompatibility", luasteam_GameServer_ComputeNewPlayerCompatibility);
	add_func(L, "CreateUnauthenticatedUserConnection", luasteam_GameServer_CreateUnauthenticatedUserConnection);
	add_func(L, "BUpdateUserData", luasteam_GameServer_BUpdateUserData);
}

void add_GameServer_auto(lua_State *L) {
	lua_createtable(L, 0, 39);
	register_GameServer_auto(L);
	lua_pushvalue(L, -1);
	GameServer_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "GameServer");
}

} // namespace luasteam
