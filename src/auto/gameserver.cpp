#include "auto.hpp"
#include "../../sdk/public/steam/steam_gameserver.h"

// void SetProduct(const char * pszProduct);
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_SetProduct(lua_State *L) {
    const char *pszProduct = luaL_checkstring(L, 1);
    SteamGameServer()->SetProduct(pszProduct);
    return 0;
}

// void SetGameDescription(const char * pszGameDescription);
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_SetGameDescription(lua_State *L) {
    const char *pszGameDescription = luaL_checkstring(L, 1);
    SteamGameServer()->SetGameDescription(pszGameDescription);
    return 0;
}

// void SetModDir(const char * pszModDir);
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_SetModDir(lua_State *L) {
    const char *pszModDir = luaL_checkstring(L, 1);
    SteamGameServer()->SetModDir(pszModDir);
    return 0;
}

// void SetDedicatedServer(bool bDedicated);
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_SetDedicatedServer(lua_State *L) {
    bool bDedicated = lua_toboolean(L, 1);
    SteamGameServer()->SetDedicatedServer(bDedicated);
    return 0;
}

// void LogOn(const char * pszToken);
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_LogOn(lua_State *L) {
    const char *pszToken = luaL_checkstring(L, 1);
    SteamGameServer()->LogOn(pszToken);
    return 0;
}

// void LogOnAnonymous();
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_LogOnAnonymous(lua_State *L) {
    SteamGameServer()->LogOnAnonymous();
    return 0;
}

// void LogOff();
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_LogOff(lua_State *L) {
    SteamGameServer()->LogOff();
    return 0;
}

// bool BLoggedOn();
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_BLoggedOn(lua_State *L) {
    lua_pushboolean(L, SteamGameServer()->BLoggedOn());
    return 1;
}

// bool BSecure();
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_BSecure(lua_State *L) {
    lua_pushboolean(L, SteamGameServer()->BSecure());
    return 1;
}

// CSteamID GetSteamID();
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_GetSteamID(lua_State *L) {
    luasteam::pushuint64(L, (SteamGameServer()->GetSteamID()).ConvertToUint64());
    return 1;
}

// bool WasRestartRequested();
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_WasRestartRequested(lua_State *L) {
    lua_pushboolean(L, SteamGameServer()->WasRestartRequested());
    return 1;
}

// void SetMaxPlayerCount(int cPlayersMax);
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_SetMaxPlayerCount(lua_State *L) {
    int cPlayersMax = static_cast<int>(luaL_checkint(L, 1));
    SteamGameServer()->SetMaxPlayerCount(cPlayersMax);
    return 0;
}

// void SetBotPlayerCount(int cBotplayers);
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_SetBotPlayerCount(lua_State *L) {
    int cBotplayers = static_cast<int>(luaL_checkint(L, 1));
    SteamGameServer()->SetBotPlayerCount(cBotplayers);
    return 0;
}

// void SetServerName(const char * pszServerName);
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_SetServerName(lua_State *L) {
    const char *pszServerName = luaL_checkstring(L, 1);
    SteamGameServer()->SetServerName(pszServerName);
    return 0;
}

// void SetMapName(const char * pszMapName);
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_SetMapName(lua_State *L) {
    const char *pszMapName = luaL_checkstring(L, 1);
    SteamGameServer()->SetMapName(pszMapName);
    return 0;
}

// void SetPasswordProtected(bool bPasswordProtected);
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_SetPasswordProtected(lua_State *L) {
    bool bPasswordProtected = lua_toboolean(L, 1);
    SteamGameServer()->SetPasswordProtected(bPasswordProtected);
    return 0;
}

// void SetSpectatorPort(uint16 unSpectatorPort);
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_SetSpectatorPort(lua_State *L) {
    uint16 unSpectatorPort = static_cast<uint16>(luaL_checkint(L, 1));
    SteamGameServer()->SetSpectatorPort(unSpectatorPort);
    return 0;
}

// void SetSpectatorServerName(const char * pszSpectatorServerName);
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_SetSpectatorServerName(lua_State *L) {
    const char *pszSpectatorServerName = luaL_checkstring(L, 1);
    SteamGameServer()->SetSpectatorServerName(pszSpectatorServerName);
    return 0;
}

// void ClearAllKeyValues();
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_ClearAllKeyValues(lua_State *L) {
    SteamGameServer()->ClearAllKeyValues();
    return 0;
}

// void SetKeyValue(const char * pKey, const char * pValue);
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_SetKeyValue(lua_State *L) {
    const char *pKey = luaL_checkstring(L, 1);
    const char *pValue = luaL_checkstring(L, 2);
    SteamGameServer()->SetKeyValue(pKey, pValue);
    return 0;
}

// void SetGameTags(const char * pchGameTags);
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_SetGameTags(lua_State *L) {
    const char *pchGameTags = luaL_checkstring(L, 1);
    SteamGameServer()->SetGameTags(pchGameTags);
    return 0;
}

// void SetGameData(const char * pchGameData);
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_SetGameData(lua_State *L) {
    const char *pchGameData = luaL_checkstring(L, 1);
    SteamGameServer()->SetGameData(pchGameData);
    return 0;
}

// void SetRegion(const char * pszRegion);
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_SetRegion(lua_State *L) {
    const char *pszRegion = luaL_checkstring(L, 1);
    SteamGameServer()->SetRegion(pszRegion);
    return 0;
}

// void SetAdvertiseServerActive(bool bActive);
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_SetAdvertiseServerActive(lua_State *L) {
    bool bActive = lua_toboolean(L, 1);
    SteamGameServer()->SetAdvertiseServerActive(bActive);
    return 0;
}

// void EndAuthSession(CSteamID steamID);
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_EndAuthSession(lua_State *L) {
    CSteamID steamID(luasteam::checkuint64(L, 1));
    SteamGameServer()->EndAuthSession(steamID);
    return 0;
}

// void CancelAuthTicket(HAuthTicket hAuthTicket);
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_CancelAuthTicket(lua_State *L) {
    HAuthTicket hAuthTicket = static_cast<HAuthTicket>(luaL_checkint(L, 1));
    SteamGameServer()->CancelAuthTicket(hAuthTicket);
    return 0;
}

// EUserHasLicenseForAppResult UserHasLicenseForApp(CSteamID steamID, AppId_t appID);
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_UserHasLicenseForApp(lua_State *L) {
    CSteamID steamID(luasteam::checkuint64(L, 1));
    AppId_t appID = static_cast<AppId_t>(luaL_checkint(L, 2));
    lua_pushinteger(L, SteamGameServer()->UserHasLicenseForApp(steamID, appID));
    return 1;
}

// bool RequestUserGroupStatus(CSteamID steamIDUser, CSteamID steamIDGroup);
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_RequestUserGroupStatus(lua_State *L) {
    CSteamID steamIDUser(luasteam::checkuint64(L, 1));
    CSteamID steamIDGroup(luasteam::checkuint64(L, 2));
    lua_pushboolean(L, SteamGameServer()->RequestUserGroupStatus(steamIDUser, steamIDGroup));
    return 1;
}

// void GetGameplayStats();
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_GetGameplayStats(lua_State *L) {
    SteamGameServer()->GetGameplayStats();
    return 0;
}

// SteamAPICall_t GetServerReputation();
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_GetServerReputation(lua_State *L) {
    luasteam::pushuint64(L, SteamGameServer()->GetServerReputation());
    return 1;
}

// SteamAPICall_t AssociateWithClan(CSteamID steamIDClan);
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_AssociateWithClan(lua_State *L) {
    CSteamID steamIDClan(luasteam::checkuint64(L, 1));
    luasteam::pushuint64(L, SteamGameServer()->AssociateWithClan(steamIDClan));
    return 1;
}

// SteamAPICall_t ComputeNewPlayerCompatibility(CSteamID steamIDNewPlayer);
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_ComputeNewPlayerCompatibility(lua_State *L) {
    CSteamID steamIDNewPlayer(luasteam::checkuint64(L, 1));
    luasteam::pushuint64(L, SteamGameServer()->ComputeNewPlayerCompatibility(steamIDNewPlayer));
    return 1;
}

// CSteamID CreateUnauthenticatedUserConnection();
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_CreateUnauthenticatedUserConnection(lua_State *L) {
    luasteam::pushuint64(L, (SteamGameServer()->CreateUnauthenticatedUserConnection()).ConvertToUint64());
    return 1;
}

// void SendUserDisconnect_DEPRECATED(CSteamID steamIDUser);
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_SendUserDisconnect_DEPRECATED(lua_State *L) {
    CSteamID steamIDUser(luasteam::checkuint64(L, 1));
    SteamGameServer()->SendUserDisconnect_DEPRECATED(steamIDUser);
    return 0;
}

// bool BUpdateUserData(CSteamID steamIDUser, const char * pchPlayerName, uint32 uScore);
EXTERN int luasteam_gameserver_SteamAPI_ISteamGameServer_BUpdateUserData(lua_State *L) {
    CSteamID steamIDUser(luasteam::checkuint64(L, 1));
    const char *pchPlayerName = luaL_checkstring(L, 2);
    uint32 uScore = static_cast<uint32>(luaL_checkint(L, 3));
    lua_pushboolean(L, SteamGameServer()->BUpdateUserData(steamIDUser, pchPlayerName, uScore));
    return 1;
}

namespace luasteam {

void add_gameserver_auto(lua_State *L) {
    add_func(L, "setProduct", luasteam_gameserver_SteamAPI_ISteamGameServer_SetProduct);
    add_func(L, "setGameDescription", luasteam_gameserver_SteamAPI_ISteamGameServer_SetGameDescription);
    add_func(L, "setModDir", luasteam_gameserver_SteamAPI_ISteamGameServer_SetModDir);
    add_func(L, "setDedicatedServer", luasteam_gameserver_SteamAPI_ISteamGameServer_SetDedicatedServer);
    add_func(L, "logOn", luasteam_gameserver_SteamAPI_ISteamGameServer_LogOn);
    add_func(L, "logOnAnonymous", luasteam_gameserver_SteamAPI_ISteamGameServer_LogOnAnonymous);
    add_func(L, "logOff", luasteam_gameserver_SteamAPI_ISteamGameServer_LogOff);
    add_func(L, "loggedOn", luasteam_gameserver_SteamAPI_ISteamGameServer_BLoggedOn);
    add_func(L, "secure", luasteam_gameserver_SteamAPI_ISteamGameServer_BSecure);
    add_func(L, "getSteamID", luasteam_gameserver_SteamAPI_ISteamGameServer_GetSteamID);
    add_func(L, "wasRestartRequested", luasteam_gameserver_SteamAPI_ISteamGameServer_WasRestartRequested);
    add_func(L, "setMaxPlayerCount", luasteam_gameserver_SteamAPI_ISteamGameServer_SetMaxPlayerCount);
    add_func(L, "setBotPlayerCount", luasteam_gameserver_SteamAPI_ISteamGameServer_SetBotPlayerCount);
    add_func(L, "setServerName", luasteam_gameserver_SteamAPI_ISteamGameServer_SetServerName);
    add_func(L, "setMapName", luasteam_gameserver_SteamAPI_ISteamGameServer_SetMapName);
    add_func(L, "setPasswordProtected", luasteam_gameserver_SteamAPI_ISteamGameServer_SetPasswordProtected);
    add_func(L, "setSpectatorPort", luasteam_gameserver_SteamAPI_ISteamGameServer_SetSpectatorPort);
    add_func(L, "setSpectatorServerName", luasteam_gameserver_SteamAPI_ISteamGameServer_SetSpectatorServerName);
    add_func(L, "clearAllKeyValues", luasteam_gameserver_SteamAPI_ISteamGameServer_ClearAllKeyValues);
    add_func(L, "setKeyValue", luasteam_gameserver_SteamAPI_ISteamGameServer_SetKeyValue);
    add_func(L, "setGameTags", luasteam_gameserver_SteamAPI_ISteamGameServer_SetGameTags);
    add_func(L, "setGameData", luasteam_gameserver_SteamAPI_ISteamGameServer_SetGameData);
    add_func(L, "setRegion", luasteam_gameserver_SteamAPI_ISteamGameServer_SetRegion);
    add_func(L, "setAdvertiseServerActive", luasteam_gameserver_SteamAPI_ISteamGameServer_SetAdvertiseServerActive);
    add_func(L, "endAuthSession", luasteam_gameserver_SteamAPI_ISteamGameServer_EndAuthSession);
    add_func(L, "cancelAuthTicket", luasteam_gameserver_SteamAPI_ISteamGameServer_CancelAuthTicket);
    add_func(L, "userHasLicenseForApp", luasteam_gameserver_SteamAPI_ISteamGameServer_UserHasLicenseForApp);
    add_func(L, "requestUserGroupStatus", luasteam_gameserver_SteamAPI_ISteamGameServer_RequestUserGroupStatus);
    add_func(L, "getGameplayStats", luasteam_gameserver_SteamAPI_ISteamGameServer_GetGameplayStats);
    add_func(L, "getServerReputation", luasteam_gameserver_SteamAPI_ISteamGameServer_GetServerReputation);
    add_func(L, "associateWithClan", luasteam_gameserver_SteamAPI_ISteamGameServer_AssociateWithClan);
    add_func(L, "computeNewPlayerCompatibility", luasteam_gameserver_SteamAPI_ISteamGameServer_ComputeNewPlayerCompatibility);
    add_func(L, "createUnauthenticatedUserConnection", luasteam_gameserver_SteamAPI_ISteamGameServer_CreateUnauthenticatedUserConnection);
    add_func(L, "sendUserDisconnect_DEPRECATED", luasteam_gameserver_SteamAPI_ISteamGameServer_SendUserDisconnect_DEPRECATED);
    add_func(L, "updateUserData", luasteam_gameserver_SteamAPI_ISteamGameServer_BUpdateUserData);
}

} // namespace luasteam
