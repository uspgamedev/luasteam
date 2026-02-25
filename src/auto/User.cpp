#include "auto.hpp"

namespace luasteam {

int User_ref = LUA_NOREF;

namespace {
class UserCallbackListener {
private:
	STEAM_CALLBACK(UserCallbackListener, OnSteamServersConnected, SteamServersConnected_t);
	STEAM_CALLBACK(UserCallbackListener, OnSteamServerConnectFailure, SteamServerConnectFailure_t);
	STEAM_CALLBACK(UserCallbackListener, OnSteamServersDisconnected, SteamServersDisconnected_t);
	STEAM_CALLBACK(UserCallbackListener, OnClientGameServerDeny, ClientGameServerDeny_t);
	STEAM_CALLBACK(UserCallbackListener, OnIPCFailure, IPCFailure_t);
	STEAM_CALLBACK(UserCallbackListener, OnLicensesUpdated, LicensesUpdated_t);
	STEAM_CALLBACK(UserCallbackListener, OnValidateAuthTicketResponse, ValidateAuthTicketResponse_t);
	STEAM_CALLBACK(UserCallbackListener, OnMicroTxnAuthorizationResponse, MicroTxnAuthorizationResponse_t);
	STEAM_CALLBACK(UserCallbackListener, OnEncryptedAppTicketResponse, EncryptedAppTicketResponse_t);
	STEAM_CALLBACK(UserCallbackListener, OnGetAuthSessionTicketResponse, GetAuthSessionTicketResponse_t);
	STEAM_CALLBACK(UserCallbackListener, OnGameWebCallback, GameWebCallback_t);
	STEAM_CALLBACK(UserCallbackListener, OnStoreAuthURLResponse, StoreAuthURLResponse_t);
	STEAM_CALLBACK(UserCallbackListener, OnMarketEligibilityResponse, MarketEligibilityResponse_t);
	STEAM_CALLBACK(UserCallbackListener, OnDurationControl, DurationControl_t);
	STEAM_CALLBACK(UserCallbackListener, OnGetTicketForWebApiResponse, GetTicketForWebApiResponse_t);
	STEAM_CALLBACK(UserCallbackListener, OnGSPolicyResponse, GSPolicyResponse_t);
};
void UserCallbackListener::OnSteamServersConnected(SteamServersConnected_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnSteamServersConnected");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamServersConnected_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UserCallbackListener::OnSteamServerConnectFailure(SteamServerConnectFailure_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnSteamServerConnectFailure");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamServerConnectFailure_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UserCallbackListener::OnSteamServersDisconnected(SteamServersDisconnected_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnSteamServersDisconnected");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamServersDisconnected_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UserCallbackListener::OnClientGameServerDeny(ClientGameServerDeny_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnClientGameServerDeny");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_ClientGameServerDeny_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UserCallbackListener::OnIPCFailure(IPCFailure_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnIPCFailure");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_IPCFailure_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UserCallbackListener::OnLicensesUpdated(LicensesUpdated_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnLicensesUpdated");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_LicensesUpdated_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UserCallbackListener::OnValidateAuthTicketResponse(ValidateAuthTicketResponse_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnValidateAuthTicketResponse");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_ValidateAuthTicketResponse_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UserCallbackListener::OnMicroTxnAuthorizationResponse(MicroTxnAuthorizationResponse_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnMicroTxnAuthorizationResponse");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_MicroTxnAuthorizationResponse_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UserCallbackListener::OnEncryptedAppTicketResponse(EncryptedAppTicketResponse_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnEncryptedAppTicketResponse");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_EncryptedAppTicketResponse_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UserCallbackListener::OnGetAuthSessionTicketResponse(GetAuthSessionTicketResponse_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnGetAuthSessionTicketResponse");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_GetAuthSessionTicketResponse_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UserCallbackListener::OnGameWebCallback(GameWebCallback_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnGameWebCallback");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_GameWebCallback_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UserCallbackListener::OnStoreAuthURLResponse(StoreAuthURLResponse_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnStoreAuthURLResponse");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_StoreAuthURLResponse_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UserCallbackListener::OnMarketEligibilityResponse(MarketEligibilityResponse_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnMarketEligibilityResponse");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_MarketEligibilityResponse_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UserCallbackListener::OnDurationControl(DurationControl_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnDurationControl");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_DurationControl_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UserCallbackListener::OnGetTicketForWebApiResponse(GetTicketForWebApiResponse_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnGetTicketForWebApiResponse");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_GetTicketForWebApiResponse_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UserCallbackListener::OnGSPolicyResponse(GSPolicyResponse_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnGSPolicyResponse");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_GSPolicyResponse_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
UserCallbackListener *User_listener = nullptr;
} // namespace

void init_User_auto(lua_State *L) { if (User_listener != nullptr) return; User_listener = new UserCallbackListener(); }
void shutdown_User_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, User_ref);
	User_ref = LUA_NOREF;
	delete User_listener; User_listener = nullptr;
}

template <> void CallResultListener<DurationControl_t>::Result(DurationControl_t *data, bool io_fail) {
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
		lua_createtable(L, 0, 8);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		lua_pushinteger(L, data->m_appid);
		lua_setfield(L, -2, "m_appid");
		lua_pushboolean(L, data->m_bApplicable);
		lua_setfield(L, -2, "m_bApplicable");
		lua_pushinteger(L, data->m_csecsLast5h);
		lua_setfield(L, -2, "m_csecsLast5h");
		lua_pushinteger(L, data->m_progress);
		lua_setfield(L, -2, "m_progress");
		lua_pushinteger(L, data->m_notification);
		lua_setfield(L, -2, "m_notification");
		lua_pushinteger(L, data->m_csecsToday);
		lua_setfield(L, -2, "m_csecsToday");
		lua_pushinteger(L, data->m_csecsRemaining);
		lua_setfield(L, -2, "m_csecsRemaining");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<EncryptedAppTicketResponse_t>::Result(EncryptedAppTicketResponse_t *data, bool io_fail) {
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

template <> void CallResultListener<MarketEligibilityResponse_t>::Result(MarketEligibilityResponse_t *data, bool io_fail) {
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
		lua_pushboolean(L, data->m_bAllowed);
		lua_setfield(L, -2, "m_bAllowed");
		lua_pushinteger(L, data->m_eNotAllowedReason);
		lua_setfield(L, -2, "m_eNotAllowedReason");
		lua_pushinteger(L, data->m_rtAllowedAtTime);
		lua_setfield(L, -2, "m_rtAllowedAtTime");
		lua_pushinteger(L, data->m_cdaySteamGuardRequiredDays);
		lua_setfield(L, -2, "m_cdaySteamGuardRequiredDays");
		lua_pushinteger(L, data->m_cdayNewDeviceCooldown);
		lua_setfield(L, -2, "m_cdayNewDeviceCooldown");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<StoreAuthURLResponse_t>::Result(StoreAuthURLResponse_t *data, bool io_fail) {
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
		lua_pushlstring(L, reinterpret_cast<const char*>(data->m_szURL), 512);
		lua_setfield(L, -2, "m_szURL");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

// In C++:
// HSteamUser GetHSteamUser();
// In Lua:
// int User.GetHSteamUser()
static int luasteam_User_GetHSteamUser(lua_State *L) {
	auto *iface = SteamUser();
	HSteamUser __ret = iface->GetHSteamUser();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool BLoggedOn();
// In Lua:
// bool User.BLoggedOn()
static int luasteam_User_BLoggedOn(lua_State *L) {
	auto *iface = SteamUser();
	bool __ret = iface->BLoggedOn();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// CSteamID GetSteamID();
// In Lua:
// uint64 User.GetSteamID()
static int luasteam_User_GetSteamID(lua_State *L) {
	auto *iface = SteamUser();
	CSteamID __ret = iface->GetSteamID();
	luasteam::pushuint64(L, __ret.ConvertToUint64());
	return 1;
}

// In C++:
// void TrackAppUsageEvent(CGameID gameID, int eAppUsageEvent, const char * pchExtraInfo);
// In Lua:
// User.TrackAppUsageEvent(gameID: uint64, eAppUsageEvent: int, pchExtraInfo: str)
static int luasteam_User_TrackAppUsageEvent(lua_State *L) {
	auto *iface = SteamUser();
	CGameID gameID(luasteam::checkuint64(L, 1));
	int eAppUsageEvent = static_cast<int>(luaL_checkint(L, 2));
	const char *pchExtraInfo = luaL_checkstring(L, 3);
	iface->TrackAppUsageEvent(gameID, eAppUsageEvent, pchExtraInfo);
	return 0;
}

// In C++:
// bool GetUserDataFolder(char * pchBuffer, int cubBuffer);
// In Lua:
// (bool, pchBuffer: str) User.GetUserDataFolder(cubBuffer: int)
static int luasteam_User_GetUserDataFolder(lua_State *L) {
	auto *iface = SteamUser();
	int cubBuffer = luaL_checkint(L, 1);
	std::vector<char> pchBuffer(cubBuffer);
	bool __ret = iface->GetUserDataFolder(pchBuffer.data(), cubBuffer);
	lua_pushboolean(L, __ret);
	lua_pushstring(L, reinterpret_cast<const char*>(pchBuffer.data()));
	return 2;
}

// In C++:
// void StartVoiceRecording();
// In Lua:
// User.StartVoiceRecording()
static int luasteam_User_StartVoiceRecording(lua_State *L) {
	auto *iface = SteamUser();
	iface->StartVoiceRecording();
	return 0;
}

// In C++:
// void StopVoiceRecording();
// In Lua:
// User.StopVoiceRecording()
static int luasteam_User_StopVoiceRecording(lua_State *L) {
	auto *iface = SteamUser();
	iface->StopVoiceRecording();
	return 0;
}

// In C++:
// EVoiceResult GetAvailableVoice(uint32 * pcbCompressed);
// In Lua:
// (int, pcbCompressed: int) User.GetAvailableVoice()
static int luasteam_User_GetAvailableVoice(lua_State *L) {
	auto *iface = SteamUser();
	uint32 pcbCompressed;
	EVoiceResult __ret = iface->GetAvailableVoice(&pcbCompressed);
	lua_pushinteger(L, __ret);
	lua_pushinteger(L, pcbCompressed);
	return 2;
}

// In C++:
// EVoiceResult GetVoice(bool bWantCompressed, void * pDestBuffer, uint32 cbDestBufferSize, uint32 * nBytesWritten);
// In Lua:
// (int, pDestBuffer: str, nBytesWritten: int) User.GetVoice(bWantCompressed: bool, cbDestBufferSize: int)
static int luasteam_User_GetVoice(lua_State *L) {
	auto *iface = SteamUser();
	bool bWantCompressed = lua_toboolean(L, 1);
	uint32 cbDestBufferSize = luaL_checkint(L, 2);
	uint32 nBytesWritten = cbDestBufferSize;
	std::vector<unsigned char> pDestBuffer(cbDestBufferSize);
	EVoiceResult __ret = iface->GetVoice(bWantCompressed, pDestBuffer.data(), cbDestBufferSize, &nBytesWritten);
	lua_pushinteger(L, __ret);
	lua_pushlstring(L, reinterpret_cast<const char*>(pDestBuffer.data()), nBytesWritten);
	lua_pushinteger(L, nBytesWritten);
	return 3;
}

// In C++:
// uint32 GetVoiceOptimalSampleRate();
// In Lua:
// int User.GetVoiceOptimalSampleRate()
static int luasteam_User_GetVoiceOptimalSampleRate(lua_State *L) {
	auto *iface = SteamUser();
	uint32 __ret = iface->GetVoiceOptimalSampleRate();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// HAuthTicket GetAuthSessionTicket(void * pTicket, int cbMaxTicket, uint32 * pcbTicket, const SteamNetworkingIdentity * pSteamNetworkingIdentity);
// In Lua:
// (int, pTicket: str, pcbTicket: int) User.GetAuthSessionTicket(cbMaxTicket: int, pSteamNetworkingIdentity: SteamNetworkingIdentity)
static int luasteam_User_GetAuthSessionTicket(lua_State *L) {
	auto *iface = SteamUser();
	int cbMaxTicket = luaL_checkint(L, 1);
	uint32 pcbTicket = cbMaxTicket;
	std::vector<unsigned char> pTicket(cbMaxTicket);
	const SteamNetworkingIdentity *pSteamNetworkingIdentity = lua_isnil(L, 2) ? nullptr : luasteam::check_SteamNetworkingIdentity_ptr(L, 2);
	HAuthTicket __ret = iface->GetAuthSessionTicket(pTicket.data(), cbMaxTicket, &pcbTicket, pSteamNetworkingIdentity);
	lua_pushinteger(L, __ret);
	lua_pushlstring(L, reinterpret_cast<const char*>(pTicket.data()), pcbTicket);
	lua_pushinteger(L, pcbTicket);
	return 3;
}

// In C++:
// HAuthTicket GetAuthTicketForWebApi(const char * pchIdentity);
// In Lua:
// int User.GetAuthTicketForWebApi(pchIdentity: str)
static int luasteam_User_GetAuthTicketForWebApi(lua_State *L) {
	auto *iface = SteamUser();
	const char *pchIdentity = luaL_checkstring(L, 1);
	HAuthTicket __ret = iface->GetAuthTicketForWebApi(pchIdentity);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// void EndAuthSession(CSteamID steamID);
// In Lua:
// User.EndAuthSession(steamID: uint64)
static int luasteam_User_EndAuthSession(lua_State *L) {
	auto *iface = SteamUser();
	CSteamID steamID(luasteam::checkuint64(L, 1));
	iface->EndAuthSession(steamID);
	return 0;
}

// In C++:
// void CancelAuthTicket(HAuthTicket hAuthTicket);
// In Lua:
// User.CancelAuthTicket(hAuthTicket: int)
static int luasteam_User_CancelAuthTicket(lua_State *L) {
	auto *iface = SteamUser();
	HAuthTicket hAuthTicket = static_cast<HAuthTicket>(luaL_checkint(L, 1));
	iface->CancelAuthTicket(hAuthTicket);
	return 0;
}

// In C++:
// EUserHasLicenseForAppResult UserHasLicenseForApp(CSteamID steamID, AppId_t appID);
// In Lua:
// int User.UserHasLicenseForApp(steamID: uint64, appID: int)
static int luasteam_User_UserHasLicenseForApp(lua_State *L) {
	auto *iface = SteamUser();
	CSteamID steamID(luasteam::checkuint64(L, 1));
	AppId_t appID = static_cast<AppId_t>(luaL_checkint(L, 2));
	EUserHasLicenseForAppResult __ret = iface->UserHasLicenseForApp(steamID, appID);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool BIsBehindNAT();
// In Lua:
// bool User.BIsBehindNAT()
static int luasteam_User_BIsBehindNAT(lua_State *L) {
	auto *iface = SteamUser();
	bool __ret = iface->BIsBehindNAT();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// void AdvertiseGame(CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer);
// In Lua:
// User.AdvertiseGame(steamIDGameServer: uint64, unIPServer: int, usPortServer: int)
static int luasteam_User_AdvertiseGame(lua_State *L) {
	auto *iface = SteamUser();
	CSteamID steamIDGameServer(luasteam::checkuint64(L, 1));
	uint32 unIPServer = static_cast<uint32>(luaL_checkint(L, 2));
	uint16 usPortServer = static_cast<uint16>(luaL_checkint(L, 3));
	iface->AdvertiseGame(steamIDGameServer, unIPServer, usPortServer);
	return 0;
}

// In C++:
// bool GetEncryptedAppTicket(void * pTicket, int cbMaxTicket, uint32 * pcbTicket);
// In Lua:
// (bool, pTicket: str, pcbTicket: int) User.GetEncryptedAppTicket(cbMaxTicket: int)
static int luasteam_User_GetEncryptedAppTicket(lua_State *L) {
	auto *iface = SteamUser();
	int cbMaxTicket = luaL_checkint(L, 1);
	uint32 pcbTicket = cbMaxTicket;
	std::vector<unsigned char> pTicket(cbMaxTicket);
	bool __ret = iface->GetEncryptedAppTicket(pTicket.data(), cbMaxTicket, &pcbTicket);
	lua_pushboolean(L, __ret);
	lua_pushlstring(L, reinterpret_cast<const char*>(pTicket.data()), pcbTicket);
	lua_pushinteger(L, pcbTicket);
	return 3;
}

// In C++:
// int GetGameBadgeLevel(int nSeries, bool bFoil);
// In Lua:
// int User.GetGameBadgeLevel(nSeries: int, bFoil: bool)
static int luasteam_User_GetGameBadgeLevel(lua_State *L) {
	auto *iface = SteamUser();
	int nSeries = static_cast<int>(luaL_checkint(L, 1));
	bool bFoil = lua_toboolean(L, 2);
	int __ret = iface->GetGameBadgeLevel(nSeries, bFoil);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// int GetPlayerSteamLevel();
// In Lua:
// int User.GetPlayerSteamLevel()
static int luasteam_User_GetPlayerSteamLevel(lua_State *L) {
	auto *iface = SteamUser();
	int __ret = iface->GetPlayerSteamLevel();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t RequestStoreAuthURL(const char * pchRedirectURL);
// In Lua:
// uint64 User.RequestStoreAuthURL(pchRedirectURL: str, callback: function)
static int luasteam_User_RequestStoreAuthURL(lua_State *L) {
	auto *iface = SteamUser();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	const char *pchRedirectURL = luaL_checkstring(L, 1);
	SteamAPICall_t __ret = iface->RequestStoreAuthURL(pchRedirectURL);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<StoreAuthURLResponse_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<StoreAuthURLResponse_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// bool BIsPhoneVerified();
// In Lua:
// bool User.BIsPhoneVerified()
static int luasteam_User_BIsPhoneVerified(lua_State *L) {
	auto *iface = SteamUser();
	bool __ret = iface->BIsPhoneVerified();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool BIsTwoFactorEnabled();
// In Lua:
// bool User.BIsTwoFactorEnabled()
static int luasteam_User_BIsTwoFactorEnabled(lua_State *L) {
	auto *iface = SteamUser();
	bool __ret = iface->BIsTwoFactorEnabled();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool BIsPhoneIdentifying();
// In Lua:
// bool User.BIsPhoneIdentifying()
static int luasteam_User_BIsPhoneIdentifying(lua_State *L) {
	auto *iface = SteamUser();
	bool __ret = iface->BIsPhoneIdentifying();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool BIsPhoneRequiringVerification();
// In Lua:
// bool User.BIsPhoneRequiringVerification()
static int luasteam_User_BIsPhoneRequiringVerification(lua_State *L) {
	auto *iface = SteamUser();
	bool __ret = iface->BIsPhoneRequiringVerification();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t GetMarketEligibility();
// In Lua:
// uint64 User.GetMarketEligibility(callback: function)
static int luasteam_User_GetMarketEligibility(lua_State *L) {
	auto *iface = SteamUser();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	SteamAPICall_t __ret = iface->GetMarketEligibility();
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<MarketEligibilityResponse_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<MarketEligibilityResponse_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t GetDurationControl();
// In Lua:
// uint64 User.GetDurationControl(callback: function)
static int luasteam_User_GetDurationControl(lua_State *L) {
	auto *iface = SteamUser();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	SteamAPICall_t __ret = iface->GetDurationControl();
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<DurationControl_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<DurationControl_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// bool BSetDurationControlOnlineState(EDurationControlOnlineState eNewState);
// In Lua:
// bool User.BSetDurationControlOnlineState(eNewState: int)
static int luasteam_User_BSetDurationControlOnlineState(lua_State *L) {
	auto *iface = SteamUser();
	EDurationControlOnlineState eNewState = static_cast<EDurationControlOnlineState>(luaL_checkint(L, 1));
	bool __ret = iface->BSetDurationControlOnlineState(eNewState);
	lua_pushboolean(L, __ret);
	return 1;
}

void register_User_auto(lua_State *L) {
	add_func(L, "GetHSteamUser", luasteam_User_GetHSteamUser);
	add_func(L, "BLoggedOn", luasteam_User_BLoggedOn);
	add_func(L, "GetSteamID", luasteam_User_GetSteamID);
	add_func(L, "TrackAppUsageEvent", luasteam_User_TrackAppUsageEvent);
	add_func(L, "GetUserDataFolder", luasteam_User_GetUserDataFolder);
	add_func(L, "StartVoiceRecording", luasteam_User_StartVoiceRecording);
	add_func(L, "StopVoiceRecording", luasteam_User_StopVoiceRecording);
	add_func(L, "GetAvailableVoice", luasteam_User_GetAvailableVoice);
	add_func(L, "GetVoice", luasteam_User_GetVoice);
	add_func(L, "GetVoiceOptimalSampleRate", luasteam_User_GetVoiceOptimalSampleRate);
	add_func(L, "GetAuthSessionTicket", luasteam_User_GetAuthSessionTicket);
	add_func(L, "GetAuthTicketForWebApi", luasteam_User_GetAuthTicketForWebApi);
	add_func(L, "EndAuthSession", luasteam_User_EndAuthSession);
	add_func(L, "CancelAuthTicket", luasteam_User_CancelAuthTicket);
	add_func(L, "UserHasLicenseForApp", luasteam_User_UserHasLicenseForApp);
	add_func(L, "BIsBehindNAT", luasteam_User_BIsBehindNAT);
	add_func(L, "AdvertiseGame", luasteam_User_AdvertiseGame);
	add_func(L, "GetEncryptedAppTicket", luasteam_User_GetEncryptedAppTicket);
	add_func(L, "GetGameBadgeLevel", luasteam_User_GetGameBadgeLevel);
	add_func(L, "GetPlayerSteamLevel", luasteam_User_GetPlayerSteamLevel);
	add_func(L, "RequestStoreAuthURL", luasteam_User_RequestStoreAuthURL);
	add_func(L, "BIsPhoneVerified", luasteam_User_BIsPhoneVerified);
	add_func(L, "BIsTwoFactorEnabled", luasteam_User_BIsTwoFactorEnabled);
	add_func(L, "BIsPhoneIdentifying", luasteam_User_BIsPhoneIdentifying);
	add_func(L, "BIsPhoneRequiringVerification", luasteam_User_BIsPhoneRequiringVerification);
	add_func(L, "GetMarketEligibility", luasteam_User_GetMarketEligibility);
	add_func(L, "GetDurationControl", luasteam_User_GetDurationControl);
	add_func(L, "BSetDurationControlOnlineState", luasteam_User_BSetDurationControlOnlineState);
}

void add_User_auto(lua_State *L) {
	lua_createtable(L, 0, 28);
	register_User_auto(L);
	lua_pushvalue(L, -1);
	User_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "User");
}

} // namespace luasteam
