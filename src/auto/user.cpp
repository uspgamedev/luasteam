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
    lua_getfield(L, -1, "onSteamServersConnected");
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
    lua_getfield(L, -1, "onSteamServerConnectFailure");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        lua_pushboolean(L, data->m_bStillRetrying);
        lua_setfield(L, -2, "stillRetrying");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnSteamServersDisconnected(SteamServersDisconnected_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
    lua_getfield(L, -1, "onSteamServersDisconnected");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnClientGameServerDeny(ClientGameServerDeny_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
    lua_getfield(L, -1, "onClientGameServerDeny");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 5);
        lua_pushinteger(L, data->m_uAppID);
        lua_setfield(L, -2, "uAppID");
        lua_pushinteger(L, data->m_unGameServerIP);
        lua_setfield(L, -2, "gameServerIP");
        lua_pushinteger(L, data->m_usGameServerPort);
        lua_setfield(L, -2, "usGameServerPort");
        lua_pushboolean(L, data->m_bSecure);
        lua_setfield(L, -2, "secure");
        lua_pushinteger(L, data->m_uReason);
        lua_setfield(L, -2, "uReason");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnIPCFailure(IPCFailure_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
    lua_getfield(L, -1, "onIPCFailure");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushinteger(L, data->m_eFailureType);
        lua_setfield(L, -2, "failureType");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnLicensesUpdated(LicensesUpdated_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
    lua_getfield(L, -1, "onLicensesUpdated");
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
    lua_getfield(L, -1, "onValidateAuthTicketResponse");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        luasteam::pushuint64(L, data->m_SteamID.ConvertToUint64());
        lua_setfield(L, -2, "steamID");
        lua_pushinteger(L, data->m_eAuthSessionResponse);
        lua_setfield(L, -2, "authSessionResponse");
        luasteam::pushuint64(L, data->m_OwnerSteamID.ConvertToUint64());
        lua_setfield(L, -2, "ownerSteamID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnMicroTxnAuthorizationResponse(MicroTxnAuthorizationResponse_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
    lua_getfield(L, -1, "onMicroTxnAuthorizationResponse");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->m_unAppID);
        lua_setfield(L, -2, "appID");
        luasteam::pushuint64(L, data->m_ulOrderID);
        lua_setfield(L, -2, "orderID");
        lua_pushboolean(L, data->m_bAuthorized);
        lua_setfield(L, -2, "authorized");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnEncryptedAppTicketResponse(EncryptedAppTicketResponse_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
    lua_getfield(L, -1, "onEncryptedAppTicketResponse");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGetAuthSessionTicketResponse(GetAuthSessionTicketResponse_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
    lua_getfield(L, -1, "onGetAuthSessionTicketResponse");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->m_hAuthTicket);
        lua_setfield(L, -2, "authTicket");
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGameWebCallback(GameWebCallback_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
    lua_getfield(L, -1, "onGameWebCallback");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushstring(L, data->m_szURL);
        lua_setfield(L, -2, "uRL");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnStoreAuthURLResponse(StoreAuthURLResponse_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
    lua_getfield(L, -1, "onStoreAuthURLResponse");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushstring(L, data->m_szURL);
        lua_setfield(L, -2, "uRL");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnMarketEligibilityResponse(MarketEligibilityResponse_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
    lua_getfield(L, -1, "onMarketEligibilityResponse");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 5);
        lua_pushboolean(L, data->m_bAllowed);
        lua_setfield(L, -2, "allowed");
        lua_pushinteger(L, data->m_eNotAllowedReason);
        lua_setfield(L, -2, "notAllowedReason");
        lua_pushinteger(L, data->m_rtAllowedAtTime);
        lua_setfield(L, -2, "rtAllowedAtTime");
        lua_pushinteger(L, data->m_cdaySteamGuardRequiredDays);
        lua_setfield(L, -2, "cdaySteamGuardRequiredDays");
        lua_pushinteger(L, data->m_cdayNewDeviceCooldown);
        lua_setfield(L, -2, "cdayNewDeviceCooldown");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnDurationControl(DurationControl_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
    lua_getfield(L, -1, "onDurationControl");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 8);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        lua_pushinteger(L, data->m_appid);
        lua_setfield(L, -2, "appid");
        lua_pushboolean(L, data->m_bApplicable);
        lua_setfield(L, -2, "applicable");
        lua_pushinteger(L, data->m_csecsLast5h);
        lua_setfield(L, -2, "csecsLast5h");
        lua_pushinteger(L, data->m_progress);
        lua_setfield(L, -2, "progress");
        lua_pushinteger(L, data->m_notification);
        lua_setfield(L, -2, "notification");
        lua_pushinteger(L, data->m_csecsToday);
        lua_setfield(L, -2, "csecsToday");
        lua_pushinteger(L, data->m_csecsRemaining);
        lua_setfield(L, -2, "csecsRemaining");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGetTicketForWebApiResponse(GetTicketForWebApiResponse_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
    lua_getfield(L, -1, "onGetTicketForWebApiResponse");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        lua_pushinteger(L, data->m_hAuthTicket);
        lua_setfield(L, -2, "authTicket");
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        lua_pushinteger(L, data->m_cubTicket);
        lua_setfield(L, -2, "cubTicket");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGSPolicyResponse(GSPolicyResponse_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::User_ref);
    lua_getfield(L, -1, "onGSPolicyResponse");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushboolean(L, data->m_bSecure);
        lua_setfield(L, -2, "secure");
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


// HSteamUser GetHSteamUser();
EXTERN int luasteam_User_GetHSteamUser(lua_State *L) {
    lua_pushinteger(L, SteamUser()->GetHSteamUser());
    return 1;
}

// bool BLoggedOn();
EXTERN int luasteam_User_BLoggedOn(lua_State *L) {
    lua_pushboolean(L, SteamUser()->BLoggedOn());
    return 1;
}

// CSteamID GetSteamID();
EXTERN int luasteam_User_GetSteamID(lua_State *L) {
    luasteam::pushuint64(L, (SteamUser()->GetSteamID()).ConvertToUint64());
    return 1;
}

// void TerminateGameConnection_DEPRECATED(uint32 unIPServer, uint16 usPortServer);
EXTERN int luasteam_User_TerminateGameConnection_DEPRECATED(lua_State *L) {
    uint32 unIPServer = static_cast<uint32>(luaL_checkint(L, 1));
    uint16 usPortServer = static_cast<uint16>(luaL_checkint(L, 2));
    SteamUser()->TerminateGameConnection_DEPRECATED(unIPServer, usPortServer);
    return 0;
}

// void TrackAppUsageEvent(CGameID gameID, int eAppUsageEvent, const char * pchExtraInfo);
EXTERN int luasteam_User_TrackAppUsageEvent(lua_State *L) {
    CGameID gameID(luasteam::checkuint64(L, 1));
    int eAppUsageEvent = static_cast<int>(luaL_checkint(L, 2));
    const char *pchExtraInfo = luaL_checkstring(L, 3);
    SteamUser()->TrackAppUsageEvent(gameID, eAppUsageEvent, pchExtraInfo);
    return 0;
}

// void StartVoiceRecording();
EXTERN int luasteam_User_StartVoiceRecording(lua_State *L) {
    SteamUser()->StartVoiceRecording();
    return 0;
}

// void StopVoiceRecording();
EXTERN int luasteam_User_StopVoiceRecording(lua_State *L) {
    SteamUser()->StopVoiceRecording();
    return 0;
}

// uint32 GetVoiceOptimalSampleRate();
EXTERN int luasteam_User_GetVoiceOptimalSampleRate(lua_State *L) {
    lua_pushinteger(L, SteamUser()->GetVoiceOptimalSampleRate());
    return 1;
}

// HAuthTicket GetAuthTicketForWebApi(const char * pchIdentity);
EXTERN int luasteam_User_GetAuthTicketForWebApi(lua_State *L) {
    const char *pchIdentity = luaL_checkstring(L, 1);
    lua_pushinteger(L, SteamUser()->GetAuthTicketForWebApi(pchIdentity));
    return 1;
}

// void EndAuthSession(CSteamID steamID);
EXTERN int luasteam_User_EndAuthSession(lua_State *L) {
    CSteamID steamID(luasteam::checkuint64(L, 1));
    SteamUser()->EndAuthSession(steamID);
    return 0;
}

// void CancelAuthTicket(HAuthTicket hAuthTicket);
EXTERN int luasteam_User_CancelAuthTicket(lua_State *L) {
    HAuthTicket hAuthTicket = static_cast<HAuthTicket>(luaL_checkint(L, 1));
    SteamUser()->CancelAuthTicket(hAuthTicket);
    return 0;
}

// EUserHasLicenseForAppResult UserHasLicenseForApp(CSteamID steamID, AppId_t appID);
EXTERN int luasteam_User_UserHasLicenseForApp(lua_State *L) {
    CSteamID steamID(luasteam::checkuint64(L, 1));
    AppId_t appID = static_cast<AppId_t>(luaL_checkint(L, 2));
    lua_pushinteger(L, SteamUser()->UserHasLicenseForApp(steamID, appID));
    return 1;
}

// bool BIsBehindNAT();
EXTERN int luasteam_User_BIsBehindNAT(lua_State *L) {
    lua_pushboolean(L, SteamUser()->BIsBehindNAT());
    return 1;
}

// void AdvertiseGame(CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer);
EXTERN int luasteam_User_AdvertiseGame(lua_State *L) {
    CSteamID steamIDGameServer(luasteam::checkuint64(L, 1));
    uint32 unIPServer = static_cast<uint32>(luaL_checkint(L, 2));
    uint16 usPortServer = static_cast<uint16>(luaL_checkint(L, 3));
    SteamUser()->AdvertiseGame(steamIDGameServer, unIPServer, usPortServer);
    return 0;
}

// int GetGameBadgeLevel(int nSeries, bool bFoil);
EXTERN int luasteam_User_GetGameBadgeLevel(lua_State *L) {
    int nSeries = static_cast<int>(luaL_checkint(L, 1));
    bool bFoil = lua_toboolean(L, 2);
    lua_pushinteger(L, SteamUser()->GetGameBadgeLevel(nSeries, bFoil));
    return 1;
}

// int GetPlayerSteamLevel();
EXTERN int luasteam_User_GetPlayerSteamLevel(lua_State *L) {
    lua_pushinteger(L, SteamUser()->GetPlayerSteamLevel());
    return 1;
}

// SteamAPICall_t RequestStoreAuthURL(const char * pchRedirectURL);
EXTERN int luasteam_User_RequestStoreAuthURL(lua_State *L) {
    const char *pchRedirectURL = luaL_checkstring(L, 1);
    luasteam::pushuint64(L, SteamUser()->RequestStoreAuthURL(pchRedirectURL));
    return 1;
}

// bool BIsPhoneVerified();
EXTERN int luasteam_User_BIsPhoneVerified(lua_State *L) {
    lua_pushboolean(L, SteamUser()->BIsPhoneVerified());
    return 1;
}

// bool BIsTwoFactorEnabled();
EXTERN int luasteam_User_BIsTwoFactorEnabled(lua_State *L) {
    lua_pushboolean(L, SteamUser()->BIsTwoFactorEnabled());
    return 1;
}

// bool BIsPhoneIdentifying();
EXTERN int luasteam_User_BIsPhoneIdentifying(lua_State *L) {
    lua_pushboolean(L, SteamUser()->BIsPhoneIdentifying());
    return 1;
}

// bool BIsPhoneRequiringVerification();
EXTERN int luasteam_User_BIsPhoneRequiringVerification(lua_State *L) {
    lua_pushboolean(L, SteamUser()->BIsPhoneRequiringVerification());
    return 1;
}

// SteamAPICall_t GetMarketEligibility();
EXTERN int luasteam_User_GetMarketEligibility(lua_State *L) {
    luasteam::pushuint64(L, SteamUser()->GetMarketEligibility());
    return 1;
}

// SteamAPICall_t GetDurationControl();
EXTERN int luasteam_User_GetDurationControl(lua_State *L) {
    luasteam::pushuint64(L, SteamUser()->GetDurationControl());
    return 1;
}

// bool BSetDurationControlOnlineState(EDurationControlOnlineState eNewState);
EXTERN int luasteam_User_BSetDurationControlOnlineState(lua_State *L) {
    EDurationControlOnlineState eNewState = static_cast<EDurationControlOnlineState>(luaL_checkint(L, 1));
    lua_pushboolean(L, SteamUser()->BSetDurationControlOnlineState(eNewState));
    return 1;
}

void register_User_auto(lua_State *L) {
    add_func(L, "GetHSteamUser", luasteam_User_GetHSteamUser);
    add_func(L, "BLoggedOn", luasteam_User_BLoggedOn);
    add_func(L, "GetSteamID", luasteam_User_GetSteamID);
    add_func(L, "TerminateGameConnection_DEPRECATED", luasteam_User_TerminateGameConnection_DEPRECATED);
    add_func(L, "TrackAppUsageEvent", luasteam_User_TrackAppUsageEvent);
    add_func(L, "StartVoiceRecording", luasteam_User_StartVoiceRecording);
    add_func(L, "StopVoiceRecording", luasteam_User_StopVoiceRecording);
    add_func(L, "GetVoiceOptimalSampleRate", luasteam_User_GetVoiceOptimalSampleRate);
    add_func(L, "GetAuthTicketForWebApi", luasteam_User_GetAuthTicketForWebApi);
    add_func(L, "EndAuthSession", luasteam_User_EndAuthSession);
    add_func(L, "CancelAuthTicket", luasteam_User_CancelAuthTicket);
    add_func(L, "UserHasLicenseForApp", luasteam_User_UserHasLicenseForApp);
    add_func(L, "BIsBehindNAT", luasteam_User_BIsBehindNAT);
    add_func(L, "AdvertiseGame", luasteam_User_AdvertiseGame);
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
    lua_createtable(L, 0, 24);
    register_User_auto(L);
    lua_pushvalue(L, -1);
    User_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "User");
}

} // namespace luasteam
