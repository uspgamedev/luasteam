#include "auto.hpp"

namespace luasteam {

int User_ref = LUA_NOREF;

namespace {
class CallbackListener {
private:
	STEAM_CALLBACK(CallbackListener, OnSteamServersConnected, SteamServersConnected_t);
	STEAM_CALLBACK(CallbackListener, OnSteamServerConnectFailure, SteamServerConnectFailure_t);
	STEAM_CALLBACK(CallbackListener, OnSteamServersDisconnected, SteamServersDisconnected_t);
	STEAM_CALLBACK(CallbackListener, OnClientGameServerDeny, ClientGameServerDeny_t);
	STEAM_CALLBACK(CallbackListener, OnIPCFailure, IPCFailure_t);
	STEAM_CALLBACK(CallbackListener, OnLicensesUpdated, LicensesUpdated_t);
	STEAM_CALLBACK(CallbackListener, OnValidateAuthTicketResponse, ValidateAuthTicketResponse_t);
	STEAM_CALLBACK(CallbackListener, OnMicroTxnAuthorizationResponse, MicroTxnAuthorizationResponse_t);
	STEAM_CALLBACK(CallbackListener, OnEncryptedAppTicketResponse, EncryptedAppTicketResponse_t);
	STEAM_CALLBACK(CallbackListener, OnGetAuthSessionTicketResponse, GetAuthSessionTicketResponse_t);
	STEAM_CALLBACK(CallbackListener, OnGameWebCallback, GameWebCallback_t);
	STEAM_CALLBACK(CallbackListener, OnStoreAuthURLResponse, StoreAuthURLResponse_t);
	STEAM_CALLBACK(CallbackListener, OnMarketEligibilityResponse, MarketEligibilityResponse_t);
	STEAM_CALLBACK(CallbackListener, OnDurationControl, DurationControl_t);
	STEAM_CALLBACK(CallbackListener, OnGetTicketForWebApiResponse, GetTicketForWebApiResponse_t);
	STEAM_CALLBACK(CallbackListener, OnGSPolicyResponse, GSPolicyResponse_t);
};
void CallbackListener::OnSteamServersConnected(SteamServersConnected_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnSteamServersConnected");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 0);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnSteamServerConnectFailure(SteamServerConnectFailure_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnSteamServerConnectFailure");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 2);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		lua_pushboolean(L, data->m_bStillRetrying);
		lua_setfield(L, -2, "m_bStillRetrying");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnSteamServersDisconnected(SteamServersDisconnected_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnSteamServersDisconnected");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 1);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnClientGameServerDeny(ClientGameServerDeny_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnClientGameServerDeny");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 5);
		lua_pushinteger(L, data->m_uAppID);
		lua_setfield(L, -2, "m_uAppID");
		lua_pushinteger(L, data->m_unGameServerIP);
		lua_setfield(L, -2, "m_unGameServerIP");
		lua_pushinteger(L, data->m_usGameServerPort);
		lua_setfield(L, -2, "m_usGameServerPort");
		lua_pushinteger(L, data->m_bSecure);
		lua_setfield(L, -2, "m_bSecure");
		lua_pushinteger(L, data->m_uReason);
		lua_setfield(L, -2, "m_uReason");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnIPCFailure(IPCFailure_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnIPCFailure");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 1);
		lua_pushinteger(L, data->m_eFailureType);
		lua_setfield(L, -2, "m_eFailureType");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnLicensesUpdated(LicensesUpdated_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnLicensesUpdated");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 0);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnValidateAuthTicketResponse(ValidateAuthTicketResponse_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnValidateAuthTicketResponse");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 3);
		luasteam::pushuint64(L, data->m_SteamID.ConvertToUint64());
		lua_setfield(L, -2, "m_SteamID");
		lua_pushinteger(L, data->m_eAuthSessionResponse);
		lua_setfield(L, -2, "m_eAuthSessionResponse");
		luasteam::pushuint64(L, data->m_OwnerSteamID.ConvertToUint64());
		lua_setfield(L, -2, "m_OwnerSteamID");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnMicroTxnAuthorizationResponse(MicroTxnAuthorizationResponse_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnMicroTxnAuthorizationResponse");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 3);
		lua_pushinteger(L, data->m_unAppID);
		lua_setfield(L, -2, "m_unAppID");
		luasteam::pushuint64(L, data->m_ulOrderID);
		lua_setfield(L, -2, "m_ulOrderID");
		lua_pushinteger(L, data->m_bAuthorized);
		lua_setfield(L, -2, "m_bAuthorized");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnEncryptedAppTicketResponse(EncryptedAppTicketResponse_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnEncryptedAppTicketResponse");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 1);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnGetAuthSessionTicketResponse(GetAuthSessionTicketResponse_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnGetAuthSessionTicketResponse");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 2);
		lua_pushinteger(L, data->m_hAuthTicket);
		lua_setfield(L, -2, "m_hAuthTicket");
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnGameWebCallback(GameWebCallback_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnGameWebCallback");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 1);
		lua_pushstring(L, reinterpret_cast<const char*>(data->m_szURL));
		lua_setfield(L, -2, "m_szURL");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnStoreAuthURLResponse(StoreAuthURLResponse_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnStoreAuthURLResponse");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 1);
		lua_pushstring(L, reinterpret_cast<const char*>(data->m_szURL));
		lua_setfield(L, -2, "m_szURL");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnMarketEligibilityResponse(MarketEligibilityResponse_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnMarketEligibilityResponse");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
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
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnDurationControl(DurationControl_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnDurationControl");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
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
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnGetTicketForWebApiResponse(GetTicketForWebApiResponse_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnGetTicketForWebApiResponse");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 4);
		lua_pushinteger(L, data->m_hAuthTicket);
		lua_setfield(L, -2, "m_hAuthTicket");
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		lua_pushinteger(L, data->m_cubTicket);
		lua_setfield(L, -2, "m_cubTicket");
		lua_pushstring(L, reinterpret_cast<const char*>(data->m_rgubTicket));
		lua_setfield(L, -2, "m_rgubTicket");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnGSPolicyResponse(GSPolicyResponse_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
	lua_getfield(L, -1, "OnGSPolicyResponse");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 1);
		lua_pushinteger(L, data->m_bSecure);
		lua_setfield(L, -2, "m_bSecure");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
CallbackListener *User_listener = nullptr;
} // namespace

void init_User_auto(lua_State *L) { User_listener = new CallbackListener(); }
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
		lua_pushstring(L, reinterpret_cast<const char*>(data->m_szURL));
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
EXTERN int luasteam_User_GetHSteamUser(lua_State *L) {
	HSteamUser __ret = SteamUser()->GetHSteamUser();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool BLoggedOn();
// In Lua:
// bool User.BLoggedOn()
EXTERN int luasteam_User_BLoggedOn(lua_State *L) {
	bool __ret = SteamUser()->BLoggedOn();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// CSteamID GetSteamID();
// In Lua:
// uint64 User.GetSteamID()
EXTERN int luasteam_User_GetSteamID(lua_State *L) {
	CSteamID __ret = SteamUser()->GetSteamID();
	luasteam::pushuint64(L, __ret.ConvertToUint64());
	return 1;
}

// In C++:
// void TrackAppUsageEvent(CGameID gameID, int eAppUsageEvent, const char * pchExtraInfo);
// In Lua:
// User.TrackAppUsageEvent(gameID: uint64, eAppUsageEvent: int, pchExtraInfo: str)
EXTERN int luasteam_User_TrackAppUsageEvent(lua_State *L) {
	CGameID gameID(luasteam::checkuint64(L, 1));
	int eAppUsageEvent = static_cast<int>(luaL_checkint(L, 2));
	const char *pchExtraInfo = luaL_checkstring(L, 3);
	SteamUser()->TrackAppUsageEvent(gameID, eAppUsageEvent, pchExtraInfo);
	return 0;
}

// In C++:
// bool GetUserDataFolder(char * pchBuffer, int cubBuffer);
// In Lua:
// (bool, pchBuffer: str) User.GetUserDataFolder(cubBuffer: int)
EXTERN int luasteam_User_GetUserDataFolder(lua_State *L) {
	int cubBuffer = luaL_checkint(L, 1);
	std::vector<char> pchBuffer(cubBuffer);
	bool __ret = SteamUser()->GetUserDataFolder(pchBuffer.data(), cubBuffer);
	lua_pushboolean(L, __ret);
	lua_pushstring(L, reinterpret_cast<const char*>(pchBuffer.data()));
	return 2;
}

// In C++:
// void StartVoiceRecording();
// In Lua:
// User.StartVoiceRecording()
EXTERN int luasteam_User_StartVoiceRecording(lua_State *L) {
	SteamUser()->StartVoiceRecording();
	return 0;
}

// In C++:
// void StopVoiceRecording();
// In Lua:
// User.StopVoiceRecording()
EXTERN int luasteam_User_StopVoiceRecording(lua_State *L) {
	SteamUser()->StopVoiceRecording();
	return 0;
}

// In C++:
// EVoiceResult GetAvailableVoice(uint32 * pcbCompressed);
// In Lua:
// (int, pcbCompressed: int) User.GetAvailableVoice()
EXTERN int luasteam_User_GetAvailableVoice(lua_State *L) {
	uint32 pcbCompressed;
	EVoiceResult __ret = SteamUser()->GetAvailableVoice(&pcbCompressed);
	lua_pushinteger(L, __ret);
	lua_pushinteger(L, pcbCompressed);
	return 2;
}

// In C++:
// EVoiceResult GetVoice(bool bWantCompressed, void * pDestBuffer, uint32 cbDestBufferSize, uint32 * nBytesWritten);
// In Lua:
// (int, pDestBuffer: str, nBytesWritten: int) User.GetVoice(bWantCompressed: bool, cbDestBufferSize: int)
EXTERN int luasteam_User_GetVoice(lua_State *L) {
	bool bWantCompressed = lua_toboolean(L, 1);
	uint32 cbDestBufferSize = luaL_checkint(L, 2);
	uint32 nBytesWritten = cbDestBufferSize;
	std::vector<unsigned char> pDestBuffer(cbDestBufferSize);
	EVoiceResult __ret = SteamUser()->GetVoice(bWantCompressed, pDestBuffer.data(), cbDestBufferSize, &nBytesWritten);
	lua_pushinteger(L, __ret);
	lua_pushlstring(L, reinterpret_cast<const char*>(pDestBuffer.data()), nBytesWritten);
	lua_pushinteger(L, nBytesWritten);
	return 3;
}

// In C++:
// EVoiceResult DecompressVoice(const void * pCompressed, uint32 cbCompressed, void * pDestBuffer, uint32 cbDestBufferSize, uint32 * nBytesWritten, uint32 nDesiredSampleRate);
// In Lua:
// (int, pDestBuffer: str, nBytesWritten: int) User.DecompressVoice(pCompressed: str, cbCompressed: int, cbDestBufferSize: int, nDesiredSampleRate: int)
EXTERN int luasteam_User_DecompressVoice(lua_State *L) {
	const char *pCompressed = luaL_checkstring(L, 1);
	uint32 cbCompressed = static_cast<uint32>(luaL_checkint(L, 2));
	uint32 cbDestBufferSize = luaL_checkint(L, 3);
	uint32 nBytesWritten = cbDestBufferSize;
	std::vector<unsigned char> pDestBuffer(cbDestBufferSize);
	uint32 nDesiredSampleRate = static_cast<uint32>(luaL_checkint(L, 4));
	EVoiceResult __ret = SteamUser()->DecompressVoice(pCompressed, cbCompressed, pDestBuffer.data(), cbDestBufferSize, &nBytesWritten, nDesiredSampleRate);
	lua_pushinteger(L, __ret);
	lua_pushlstring(L, reinterpret_cast<const char*>(pDestBuffer.data()), nBytesWritten);
	lua_pushinteger(L, nBytesWritten);
	return 3;
}

// In C++:
// uint32 GetVoiceOptimalSampleRate();
// In Lua:
// int User.GetVoiceOptimalSampleRate()
EXTERN int luasteam_User_GetVoiceOptimalSampleRate(lua_State *L) {
	uint32 __ret = SteamUser()->GetVoiceOptimalSampleRate();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// HAuthTicket GetAuthSessionTicket(void * pTicket, int cbMaxTicket, uint32 * pcbTicket, const SteamNetworkingIdentity * pSteamNetworkingIdentity);
// In Lua:
// (int, pTicket: str, pcbTicket: int) User.GetAuthSessionTicket(cbMaxTicket: int, pSteamNetworkingIdentity: SteamNetworkingIdentity)
EXTERN int luasteam_User_GetAuthSessionTicket(lua_State *L) {
	int cbMaxTicket = luaL_checkint(L, 1);
	uint32 pcbTicket = cbMaxTicket;
	std::vector<unsigned char> pTicket(cbMaxTicket);
	SteamNetworkingIdentity pSteamNetworkingIdentity_val;
	if (!lua_isnil(L, 2)) pSteamNetworkingIdentity_val = luasteam::check_SteamNetworkingIdentity(L, 2);
	const SteamNetworkingIdentity *pSteamNetworkingIdentity = lua_isnil(L, 2) ? nullptr : &pSteamNetworkingIdentity_val;
	HAuthTicket __ret = SteamUser()->GetAuthSessionTicket(pTicket.data(), cbMaxTicket, &pcbTicket, pSteamNetworkingIdentity);
	lua_pushinteger(L, __ret);
	lua_pushlstring(L, reinterpret_cast<const char*>(pTicket.data()), pcbTicket);
	lua_pushinteger(L, pcbTicket);
	return 3;
}

// In C++:
// HAuthTicket GetAuthTicketForWebApi(const char * pchIdentity);
// In Lua:
// int User.GetAuthTicketForWebApi(pchIdentity: str)
EXTERN int luasteam_User_GetAuthTicketForWebApi(lua_State *L) {
	const char *pchIdentity = luaL_checkstring(L, 1);
	HAuthTicket __ret = SteamUser()->GetAuthTicketForWebApi(pchIdentity);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// EBeginAuthSessionResult BeginAuthSession(const void * pAuthTicket, int cbAuthTicket, CSteamID steamID);
// In Lua:
// int User.BeginAuthSession(pAuthTicket: str, cbAuthTicket: int, steamID: uint64)
EXTERN int luasteam_User_BeginAuthSession(lua_State *L) {
	const char *pAuthTicket = luaL_checkstring(L, 1);
	int cbAuthTicket = static_cast<int>(luaL_checkint(L, 2));
	CSteamID steamID(luasteam::checkuint64(L, 3));
	EBeginAuthSessionResult __ret = SteamUser()->BeginAuthSession(pAuthTicket, cbAuthTicket, steamID);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// void EndAuthSession(CSteamID steamID);
// In Lua:
// User.EndAuthSession(steamID: uint64)
EXTERN int luasteam_User_EndAuthSession(lua_State *L) {
	CSteamID steamID(luasteam::checkuint64(L, 1));
	SteamUser()->EndAuthSession(steamID);
	return 0;
}

// In C++:
// void CancelAuthTicket(HAuthTicket hAuthTicket);
// In Lua:
// User.CancelAuthTicket(hAuthTicket: int)
EXTERN int luasteam_User_CancelAuthTicket(lua_State *L) {
	HAuthTicket hAuthTicket = static_cast<HAuthTicket>(luaL_checkint(L, 1));
	SteamUser()->CancelAuthTicket(hAuthTicket);
	return 0;
}

// In C++:
// EUserHasLicenseForAppResult UserHasLicenseForApp(CSteamID steamID, AppId_t appID);
// In Lua:
// int User.UserHasLicenseForApp(steamID: uint64, appID: int)
EXTERN int luasteam_User_UserHasLicenseForApp(lua_State *L) {
	CSteamID steamID(luasteam::checkuint64(L, 1));
	AppId_t appID = static_cast<AppId_t>(luaL_checkint(L, 2));
	EUserHasLicenseForAppResult __ret = SteamUser()->UserHasLicenseForApp(steamID, appID);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool BIsBehindNAT();
// In Lua:
// bool User.BIsBehindNAT()
EXTERN int luasteam_User_BIsBehindNAT(lua_State *L) {
	bool __ret = SteamUser()->BIsBehindNAT();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// void AdvertiseGame(CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer);
// In Lua:
// User.AdvertiseGame(steamIDGameServer: uint64, unIPServer: int, usPortServer: int)
EXTERN int luasteam_User_AdvertiseGame(lua_State *L) {
	CSteamID steamIDGameServer(luasteam::checkuint64(L, 1));
	uint32 unIPServer = static_cast<uint32>(luaL_checkint(L, 2));
	uint16 usPortServer = static_cast<uint16>(luaL_checkint(L, 3));
	SteamUser()->AdvertiseGame(steamIDGameServer, unIPServer, usPortServer);
	return 0;
}

// In C++:
// SteamAPICall_t RequestEncryptedAppTicket(const void * pDataToInclude, int cbDataToInclude);
// In Lua:
// uint64 User.RequestEncryptedAppTicket(pDataToInclude: str, cbDataToInclude: int, callback: function)
EXTERN int luasteam_User_RequestEncryptedAppTicket(lua_State *L) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	char *pDataToInclude = const_cast<char*>(luaL_checkstring(L, 1));
	int cbDataToInclude = static_cast<int>(luaL_checkint(L, 2));
	SteamAPICall_t __ret = SteamUser()->RequestEncryptedAppTicket(pDataToInclude, cbDataToInclude);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<EncryptedAppTicketResponse_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<EncryptedAppTicketResponse_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// bool GetEncryptedAppTicket(void * pTicket, int cbMaxTicket, uint32 * pcbTicket);
// In Lua:
// (bool, pTicket: str, pcbTicket: int) User.GetEncryptedAppTicket(cbMaxTicket: int)
EXTERN int luasteam_User_GetEncryptedAppTicket(lua_State *L) {
	int cbMaxTicket = luaL_checkint(L, 1);
	uint32 pcbTicket = cbMaxTicket;
	std::vector<unsigned char> pTicket(cbMaxTicket);
	bool __ret = SteamUser()->GetEncryptedAppTicket(pTicket.data(), cbMaxTicket, &pcbTicket);
	lua_pushboolean(L, __ret);
	lua_pushlstring(L, reinterpret_cast<const char*>(pTicket.data()), pcbTicket);
	lua_pushinteger(L, pcbTicket);
	return 3;
}

// In C++:
// int GetGameBadgeLevel(int nSeries, bool bFoil);
// In Lua:
// int User.GetGameBadgeLevel(nSeries: int, bFoil: bool)
EXTERN int luasteam_User_GetGameBadgeLevel(lua_State *L) {
	int nSeries = static_cast<int>(luaL_checkint(L, 1));
	bool bFoil = lua_toboolean(L, 2);
	int __ret = SteamUser()->GetGameBadgeLevel(nSeries, bFoil);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// int GetPlayerSteamLevel();
// In Lua:
// int User.GetPlayerSteamLevel()
EXTERN int luasteam_User_GetPlayerSteamLevel(lua_State *L) {
	int __ret = SteamUser()->GetPlayerSteamLevel();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t RequestStoreAuthURL(const char * pchRedirectURL);
// In Lua:
// uint64 User.RequestStoreAuthURL(pchRedirectURL: str, callback: function)
EXTERN int luasteam_User_RequestStoreAuthURL(lua_State *L) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	const char *pchRedirectURL = luaL_checkstring(L, 1);
	SteamAPICall_t __ret = SteamUser()->RequestStoreAuthURL(pchRedirectURL);
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
EXTERN int luasteam_User_BIsPhoneVerified(lua_State *L) {
	bool __ret = SteamUser()->BIsPhoneVerified();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool BIsTwoFactorEnabled();
// In Lua:
// bool User.BIsTwoFactorEnabled()
EXTERN int luasteam_User_BIsTwoFactorEnabled(lua_State *L) {
	bool __ret = SteamUser()->BIsTwoFactorEnabled();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool BIsPhoneIdentifying();
// In Lua:
// bool User.BIsPhoneIdentifying()
EXTERN int luasteam_User_BIsPhoneIdentifying(lua_State *L) {
	bool __ret = SteamUser()->BIsPhoneIdentifying();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool BIsPhoneRequiringVerification();
// In Lua:
// bool User.BIsPhoneRequiringVerification()
EXTERN int luasteam_User_BIsPhoneRequiringVerification(lua_State *L) {
	bool __ret = SteamUser()->BIsPhoneRequiringVerification();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t GetMarketEligibility();
// In Lua:
// uint64 User.GetMarketEligibility(callback: function)
EXTERN int luasteam_User_GetMarketEligibility(lua_State *L) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	SteamAPICall_t __ret = SteamUser()->GetMarketEligibility();
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
EXTERN int luasteam_User_GetDurationControl(lua_State *L) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	SteamAPICall_t __ret = SteamUser()->GetDurationControl();
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
EXTERN int luasteam_User_BSetDurationControlOnlineState(lua_State *L) {
	EDurationControlOnlineState eNewState = static_cast<EDurationControlOnlineState>(luaL_checkint(L, 1));
	bool __ret = SteamUser()->BSetDurationControlOnlineState(eNewState);
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
	add_func(L, "DecompressVoice", luasteam_User_DecompressVoice);
	add_func(L, "GetVoiceOptimalSampleRate", luasteam_User_GetVoiceOptimalSampleRate);
	add_func(L, "GetAuthSessionTicket", luasteam_User_GetAuthSessionTicket);
	add_func(L, "GetAuthTicketForWebApi", luasteam_User_GetAuthTicketForWebApi);
	add_func(L, "BeginAuthSession", luasteam_User_BeginAuthSession);
	add_func(L, "EndAuthSession", luasteam_User_EndAuthSession);
	add_func(L, "CancelAuthTicket", luasteam_User_CancelAuthTicket);
	add_func(L, "UserHasLicenseForApp", luasteam_User_UserHasLicenseForApp);
	add_func(L, "BIsBehindNAT", luasteam_User_BIsBehindNAT);
	add_func(L, "AdvertiseGame", luasteam_User_AdvertiseGame);
	add_func(L, "RequestEncryptedAppTicket", luasteam_User_RequestEncryptedAppTicket);
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
	lua_createtable(L, 0, 31);
	register_User_auto(L);
	lua_pushvalue(L, -1);
	User_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "User");
}

} // namespace luasteam
