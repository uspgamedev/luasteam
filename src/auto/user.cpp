#include "auto.hpp"

// HSteamUser GetHSteamUser();
EXTERN int luasteam_user_SteamAPI_ISteamUser_GetHSteamUser(lua_State *L) {
    lua_pushinteger(L, SteamUser()->GetHSteamUser());
    return 1;
}

// bool BLoggedOn();
EXTERN int luasteam_user_SteamAPI_ISteamUser_BLoggedOn(lua_State *L) {
    lua_pushboolean(L, SteamUser()->BLoggedOn());
    return 1;
}

// CSteamID GetSteamID();
EXTERN int luasteam_user_SteamAPI_ISteamUser_GetSteamID(lua_State *L) {
    luasteam::pushuint64(L, (SteamUser()->GetSteamID()).ConvertToUint64());
    return 1;
}

// void TerminateGameConnection_DEPRECATED(uint32 unIPServer, uint16 usPortServer);
EXTERN int luasteam_user_SteamAPI_ISteamUser_TerminateGameConnection_DEPRECATED(lua_State *L) {
    uint32 unIPServer = static_cast<uint32>(luaL_checkint(L, 1));
    uint16 usPortServer = static_cast<uint16>(luaL_checkint(L, 2));
    SteamUser()->TerminateGameConnection_DEPRECATED(unIPServer, usPortServer);
    return 0;
}

// void TrackAppUsageEvent(CGameID gameID, int eAppUsageEvent, const char * pchExtraInfo);
EXTERN int luasteam_user_SteamAPI_ISteamUser_TrackAppUsageEvent(lua_State *L) {
    CGameID gameID(luasteam::checkuint64(L, 1));
    int eAppUsageEvent = static_cast<int>(luaL_checkint(L, 2));
    const char *pchExtraInfo = luaL_checkstring(L, 3);
    SteamUser()->TrackAppUsageEvent(gameID, eAppUsageEvent, pchExtraInfo);
    return 0;
}

// void StartVoiceRecording();
EXTERN int luasteam_user_SteamAPI_ISteamUser_StartVoiceRecording(lua_State *L) {
    SteamUser()->StartVoiceRecording();
    return 0;
}

// void StopVoiceRecording();
EXTERN int luasteam_user_SteamAPI_ISteamUser_StopVoiceRecording(lua_State *L) {
    SteamUser()->StopVoiceRecording();
    return 0;
}

// uint32 GetVoiceOptimalSampleRate();
EXTERN int luasteam_user_SteamAPI_ISteamUser_GetVoiceOptimalSampleRate(lua_State *L) {
    lua_pushinteger(L, SteamUser()->GetVoiceOptimalSampleRate());
    return 1;
}

// HAuthTicket GetAuthTicketForWebApi(const char * pchIdentity);
EXTERN int luasteam_user_SteamAPI_ISteamUser_GetAuthTicketForWebApi(lua_State *L) {
    const char *pchIdentity = luaL_checkstring(L, 1);
    lua_pushinteger(L, SteamUser()->GetAuthTicketForWebApi(pchIdentity));
    return 1;
}

// void EndAuthSession(CSteamID steamID);
EXTERN int luasteam_user_SteamAPI_ISteamUser_EndAuthSession(lua_State *L) {
    CSteamID steamID(luasteam::checkuint64(L, 1));
    SteamUser()->EndAuthSession(steamID);
    return 0;
}

// void CancelAuthTicket(HAuthTicket hAuthTicket);
EXTERN int luasteam_user_SteamAPI_ISteamUser_CancelAuthTicket(lua_State *L) {
    HAuthTicket hAuthTicket = static_cast<HAuthTicket>(luaL_checkint(L, 1));
    SteamUser()->CancelAuthTicket(hAuthTicket);
    return 0;
}

// EUserHasLicenseForAppResult UserHasLicenseForApp(CSteamID steamID, AppId_t appID);
EXTERN int luasteam_user_SteamAPI_ISteamUser_UserHasLicenseForApp(lua_State *L) {
    CSteamID steamID(luasteam::checkuint64(L, 1));
    AppId_t appID = static_cast<AppId_t>(luaL_checkint(L, 2));
    lua_pushinteger(L, SteamUser()->UserHasLicenseForApp(steamID, appID));
    return 1;
}

// bool BIsBehindNAT();
EXTERN int luasteam_user_SteamAPI_ISteamUser_BIsBehindNAT(lua_State *L) {
    lua_pushboolean(L, SteamUser()->BIsBehindNAT());
    return 1;
}

// void AdvertiseGame(CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer);
EXTERN int luasteam_user_SteamAPI_ISteamUser_AdvertiseGame(lua_State *L) {
    CSteamID steamIDGameServer(luasteam::checkuint64(L, 1));
    uint32 unIPServer = static_cast<uint32>(luaL_checkint(L, 2));
    uint16 usPortServer = static_cast<uint16>(luaL_checkint(L, 3));
    SteamUser()->AdvertiseGame(steamIDGameServer, unIPServer, usPortServer);
    return 0;
}

// int GetGameBadgeLevel(int nSeries, bool bFoil);
EXTERN int luasteam_user_SteamAPI_ISteamUser_GetGameBadgeLevel(lua_State *L) {
    int nSeries = static_cast<int>(luaL_checkint(L, 1));
    bool bFoil = lua_toboolean(L, 2);
    lua_pushinteger(L, SteamUser()->GetGameBadgeLevel(nSeries, bFoil));
    return 1;
}

// int GetPlayerSteamLevel();
EXTERN int luasteam_user_SteamAPI_ISteamUser_GetPlayerSteamLevel(lua_State *L) {
    lua_pushinteger(L, SteamUser()->GetPlayerSteamLevel());
    return 1;
}

// SteamAPICall_t RequestStoreAuthURL(const char * pchRedirectURL);
EXTERN int luasteam_user_SteamAPI_ISteamUser_RequestStoreAuthURL(lua_State *L) {
    const char *pchRedirectURL = luaL_checkstring(L, 1);
    luasteam::pushuint64(L, SteamUser()->RequestStoreAuthURL(pchRedirectURL));
    return 1;
}

// bool BIsPhoneVerified();
EXTERN int luasteam_user_SteamAPI_ISteamUser_BIsPhoneVerified(lua_State *L) {
    lua_pushboolean(L, SteamUser()->BIsPhoneVerified());
    return 1;
}

// bool BIsTwoFactorEnabled();
EXTERN int luasteam_user_SteamAPI_ISteamUser_BIsTwoFactorEnabled(lua_State *L) {
    lua_pushboolean(L, SteamUser()->BIsTwoFactorEnabled());
    return 1;
}

// bool BIsPhoneIdentifying();
EXTERN int luasteam_user_SteamAPI_ISteamUser_BIsPhoneIdentifying(lua_State *L) {
    lua_pushboolean(L, SteamUser()->BIsPhoneIdentifying());
    return 1;
}

// bool BIsPhoneRequiringVerification();
EXTERN int luasteam_user_SteamAPI_ISteamUser_BIsPhoneRequiringVerification(lua_State *L) {
    lua_pushboolean(L, SteamUser()->BIsPhoneRequiringVerification());
    return 1;
}

// SteamAPICall_t GetMarketEligibility();
EXTERN int luasteam_user_SteamAPI_ISteamUser_GetMarketEligibility(lua_State *L) {
    luasteam::pushuint64(L, SteamUser()->GetMarketEligibility());
    return 1;
}

// SteamAPICall_t GetDurationControl();
EXTERN int luasteam_user_SteamAPI_ISteamUser_GetDurationControl(lua_State *L) {
    luasteam::pushuint64(L, SteamUser()->GetDurationControl());
    return 1;
}

// bool BSetDurationControlOnlineState(EDurationControlOnlineState eNewState);
EXTERN int luasteam_user_SteamAPI_ISteamUser_BSetDurationControlOnlineState(lua_State *L) {
    EDurationControlOnlineState eNewState = static_cast<EDurationControlOnlineState>(luaL_checkint(L, 1));
    lua_pushboolean(L, SteamUser()->BSetDurationControlOnlineState(eNewState));
    return 1;
}

namespace luasteam {

void add_user_auto(lua_State *L) {
    add_func(L, "getHSteamUser", luasteam_user_SteamAPI_ISteamUser_GetHSteamUser);
    add_func(L, "loggedOn", luasteam_user_SteamAPI_ISteamUser_BLoggedOn);
    add_func(L, "getSteamID", luasteam_user_SteamAPI_ISteamUser_GetSteamID);
    add_func(L, "terminateGameConnection_DEPRECATED", luasteam_user_SteamAPI_ISteamUser_TerminateGameConnection_DEPRECATED);
    add_func(L, "trackAppUsageEvent", luasteam_user_SteamAPI_ISteamUser_TrackAppUsageEvent);
    add_func(L, "startVoiceRecording", luasteam_user_SteamAPI_ISteamUser_StartVoiceRecording);
    add_func(L, "stopVoiceRecording", luasteam_user_SteamAPI_ISteamUser_StopVoiceRecording);
    add_func(L, "getVoiceOptimalSampleRate", luasteam_user_SteamAPI_ISteamUser_GetVoiceOptimalSampleRate);
    add_func(L, "getAuthTicketForWebApi", luasteam_user_SteamAPI_ISteamUser_GetAuthTicketForWebApi);
    add_func(L, "endAuthSession", luasteam_user_SteamAPI_ISteamUser_EndAuthSession);
    add_func(L, "cancelAuthTicket", luasteam_user_SteamAPI_ISteamUser_CancelAuthTicket);
    add_func(L, "userHasLicenseForApp", luasteam_user_SteamAPI_ISteamUser_UserHasLicenseForApp);
    add_func(L, "isBehindNAT", luasteam_user_SteamAPI_ISteamUser_BIsBehindNAT);
    add_func(L, "advertiseGame", luasteam_user_SteamAPI_ISteamUser_AdvertiseGame);
    add_func(L, "getGameBadgeLevel", luasteam_user_SteamAPI_ISteamUser_GetGameBadgeLevel);
    add_func(L, "getPlayerSteamLevel", luasteam_user_SteamAPI_ISteamUser_GetPlayerSteamLevel);
    add_func(L, "requestStoreAuthURL", luasteam_user_SteamAPI_ISteamUser_RequestStoreAuthURL);
    add_func(L, "isPhoneVerified", luasteam_user_SteamAPI_ISteamUser_BIsPhoneVerified);
    add_func(L, "isTwoFactorEnabled", luasteam_user_SteamAPI_ISteamUser_BIsTwoFactorEnabled);
    add_func(L, "isPhoneIdentifying", luasteam_user_SteamAPI_ISteamUser_BIsPhoneIdentifying);
    add_func(L, "isPhoneRequiringVerification", luasteam_user_SteamAPI_ISteamUser_BIsPhoneRequiringVerification);
    add_func(L, "getMarketEligibility", luasteam_user_SteamAPI_ISteamUser_GetMarketEligibility);
    add_func(L, "getDurationControl", luasteam_user_SteamAPI_ISteamUser_GetDurationControl);
    add_func(L, "setDurationControlOnlineState", luasteam_user_SteamAPI_ISteamUser_BSetDurationControlOnlineState);
}

} // namespace luasteam
