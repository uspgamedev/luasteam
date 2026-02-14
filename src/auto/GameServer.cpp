#include "auto.hpp"

namespace luasteam {

int GameServer_ref = LUA_NOREF;

namespace {

class CallbackListener {
  private:
    STEAM_GAMESERVER_CALLBACK(CallbackListener, OnSteamServersConnected, SteamServersConnected_t);
    STEAM_GAMESERVER_CALLBACK(CallbackListener, OnSteamServerConnectFailure, SteamServerConnectFailure_t);
    STEAM_GAMESERVER_CALLBACK(CallbackListener, OnSteamServersDisconnected, SteamServersDisconnected_t);
    STEAM_GAMESERVER_CALLBACK(CallbackListener, OnValidateAuthTicketResponse, ValidateAuthTicketResponse_t);
    STEAM_GAMESERVER_CALLBACK(CallbackListener, OnGSClientApprove, GSClientApprove_t);
    STEAM_GAMESERVER_CALLBACK(CallbackListener, OnGSClientDeny, GSClientDeny_t);
    STEAM_GAMESERVER_CALLBACK(CallbackListener, OnGSClientKick, GSClientKick_t);
    STEAM_GAMESERVER_CALLBACK(CallbackListener, OnGSClientAchievementStatus, GSClientAchievementStatus_t);
    STEAM_GAMESERVER_CALLBACK(CallbackListener, OnGSPolicyResponse, GSPolicyResponse_t);
    STEAM_GAMESERVER_CALLBACK(CallbackListener, OnGSGameplayStats, GSGameplayStats_t);
    STEAM_GAMESERVER_CALLBACK(CallbackListener, OnGSClientGroupStatus, GSClientGroupStatus_t);
    STEAM_GAMESERVER_CALLBACK(CallbackListener, OnGSReputation, GSReputation_t);
    STEAM_GAMESERVER_CALLBACK(CallbackListener, OnAssociateWithClanResult, AssociateWithClanResult_t);
    STEAM_GAMESERVER_CALLBACK(CallbackListener, OnComputeNewPlayerCompatibilityResult, ComputeNewPlayerCompatibilityResult_t);
};

void CallbackListener::OnSteamServersConnected(SteamServersConnected_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServer_ref);
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
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServer_ref);
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
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServer_ref);
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

void CallbackListener::OnValidateAuthTicketResponse(ValidateAuthTicketResponse_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServer_ref);
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

void CallbackListener::OnGSClientApprove(GSClientApprove_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServer_ref);
    lua_getfield(L, -1, "OnGSClientApprove");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        luasteam::pushuint64(L, data->m_SteamID.ConvertToUint64());
        lua_setfield(L, -2, "m_SteamID");
        luasteam::pushuint64(L, data->m_OwnerSteamID.ConvertToUint64());
        lua_setfield(L, -2, "m_OwnerSteamID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGSClientDeny(GSClientDeny_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServer_ref);
    lua_getfield(L, -1, "OnGSClientDeny");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        luasteam::pushuint64(L, data->m_SteamID.ConvertToUint64());
        lua_setfield(L, -2, "m_SteamID");
        lua_pushinteger(L, data->m_eDenyReason);
        lua_setfield(L, -2, "m_eDenyReason");
        lua_pushstring(L, reinterpret_cast<const char*>(data->m_rgchOptionalText));
        lua_setfield(L, -2, "m_rgchOptionalText");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGSClientKick(GSClientKick_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServer_ref);
    lua_getfield(L, -1, "OnGSClientKick");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        luasteam::pushuint64(L, data->m_SteamID.ConvertToUint64());
        lua_setfield(L, -2, "m_SteamID");
        lua_pushinteger(L, data->m_eDenyReason);
        lua_setfield(L, -2, "m_eDenyReason");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGSClientAchievementStatus(GSClientAchievementStatus_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServer_ref);
    lua_getfield(L, -1, "OnGSClientAchievementStatus");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        luasteam::pushuint64(L, data->m_SteamID);
        lua_setfield(L, -2, "m_SteamID");
        lua_pushstring(L, reinterpret_cast<const char*>(data->m_pchAchievement));
        lua_setfield(L, -2, "m_pchAchievement");
        lua_pushboolean(L, data->m_bUnlocked);
        lua_setfield(L, -2, "m_bUnlocked");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGSPolicyResponse(GSPolicyResponse_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServer_ref);
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

void CallbackListener::OnGSGameplayStats(GSGameplayStats_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServer_ref);
    lua_getfield(L, -1, "OnGSGameplayStats");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "m_eResult");
        lua_pushinteger(L, data->m_nRank);
        lua_setfield(L, -2, "m_nRank");
        lua_pushinteger(L, data->m_unTotalConnects);
        lua_setfield(L, -2, "m_unTotalConnects");
        lua_pushinteger(L, data->m_unTotalMinutesPlayed);
        lua_setfield(L, -2, "m_unTotalMinutesPlayed");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGSClientGroupStatus(GSClientGroupStatus_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServer_ref);
    lua_getfield(L, -1, "OnGSClientGroupStatus");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        luasteam::pushuint64(L, data->m_SteamIDUser.ConvertToUint64());
        lua_setfield(L, -2, "m_SteamIDUser");
        luasteam::pushuint64(L, data->m_SteamIDGroup.ConvertToUint64());
        lua_setfield(L, -2, "m_SteamIDGroup");
        lua_pushboolean(L, data->m_bMember);
        lua_setfield(L, -2, "m_bMember");
        lua_pushboolean(L, data->m_bOfficer);
        lua_setfield(L, -2, "m_bOfficer");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGSReputation(GSReputation_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServer_ref);
    lua_getfield(L, -1, "OnGSReputation");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
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
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnAssociateWithClanResult(AssociateWithClanResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServer_ref);
    lua_getfield(L, -1, "OnAssociateWithClanResult");
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

void CallbackListener::OnComputeNewPlayerCompatibilityResult(ComputeNewPlayerCompatibilityResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServer_ref);
    lua_getfield(L, -1, "OnComputeNewPlayerCompatibilityResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
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
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

CallbackListener *GameServer_listener = nullptr;

} // namespace

void init_GameServer_auto(lua_State *L) { GameServer_listener = new CallbackListener(); }

void shutdown_GameServer_auto(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, GameServer_ref);
    GameServer_ref = LUA_NOREF;
    delete GameServer_listener; GameServer_listener = nullptr;
}


// void SetProduct(const char * pszProduct);
EXTERN int luasteam_GameServer_SetProduct(lua_State *L) {
    const char *pszProduct = luaL_checkstring(L, 1);
    SteamGameServer()->SetProduct(pszProduct);
    return 0;
}

// void SetGameDescription(const char * pszGameDescription);
EXTERN int luasteam_GameServer_SetGameDescription(lua_State *L) {
    const char *pszGameDescription = luaL_checkstring(L, 1);
    SteamGameServer()->SetGameDescription(pszGameDescription);
    return 0;
}

// void SetModDir(const char * pszModDir);
EXTERN int luasteam_GameServer_SetModDir(lua_State *L) {
    const char *pszModDir = luaL_checkstring(L, 1);
    SteamGameServer()->SetModDir(pszModDir);
    return 0;
}

// void SetDedicatedServer(bool bDedicated);
EXTERN int luasteam_GameServer_SetDedicatedServer(lua_State *L) {
    bool bDedicated = lua_toboolean(L, 1);
    SteamGameServer()->SetDedicatedServer(bDedicated);
    return 0;
}

// void LogOn(const char * pszToken);
EXTERN int luasteam_GameServer_LogOn(lua_State *L) {
    const char *pszToken = luaL_checkstring(L, 1);
    SteamGameServer()->LogOn(pszToken);
    return 0;
}

// void LogOnAnonymous();
EXTERN int luasteam_GameServer_LogOnAnonymous(lua_State *L) {
    SteamGameServer()->LogOnAnonymous();
    return 0;
}

// void LogOff();
EXTERN int luasteam_GameServer_LogOff(lua_State *L) {
    SteamGameServer()->LogOff();
    return 0;
}

// bool BLoggedOn();
EXTERN int luasteam_GameServer_BLoggedOn(lua_State *L) {
    bool __ret = SteamGameServer()->BLoggedOn();
    lua_pushboolean(L, __ret);
    return 1;
}

// bool BSecure();
EXTERN int luasteam_GameServer_BSecure(lua_State *L) {
    bool __ret = SteamGameServer()->BSecure();
    lua_pushboolean(L, __ret);
    return 1;
}

// CSteamID GetSteamID();
EXTERN int luasteam_GameServer_GetSteamID(lua_State *L) {
    CSteamID __ret = SteamGameServer()->GetSteamID();
    luasteam::pushuint64(L, __ret.ConvertToUint64());
    return 1;
}

// bool WasRestartRequested();
EXTERN int luasteam_GameServer_WasRestartRequested(lua_State *L) {
    bool __ret = SteamGameServer()->WasRestartRequested();
    lua_pushboolean(L, __ret);
    return 1;
}

// void SetMaxPlayerCount(int cPlayersMax);
EXTERN int luasteam_GameServer_SetMaxPlayerCount(lua_State *L) {
    int cPlayersMax = static_cast<int>(luaL_checkint(L, 1));
    SteamGameServer()->SetMaxPlayerCount(cPlayersMax);
    return 0;
}

// void SetBotPlayerCount(int cBotplayers);
EXTERN int luasteam_GameServer_SetBotPlayerCount(lua_State *L) {
    int cBotplayers = static_cast<int>(luaL_checkint(L, 1));
    SteamGameServer()->SetBotPlayerCount(cBotplayers);
    return 0;
}

// void SetServerName(const char * pszServerName);
EXTERN int luasteam_GameServer_SetServerName(lua_State *L) {
    const char *pszServerName = luaL_checkstring(L, 1);
    SteamGameServer()->SetServerName(pszServerName);
    return 0;
}

// void SetMapName(const char * pszMapName);
EXTERN int luasteam_GameServer_SetMapName(lua_State *L) {
    const char *pszMapName = luaL_checkstring(L, 1);
    SteamGameServer()->SetMapName(pszMapName);
    return 0;
}

// void SetPasswordProtected(bool bPasswordProtected);
EXTERN int luasteam_GameServer_SetPasswordProtected(lua_State *L) {
    bool bPasswordProtected = lua_toboolean(L, 1);
    SteamGameServer()->SetPasswordProtected(bPasswordProtected);
    return 0;
}

// void SetSpectatorPort(uint16 unSpectatorPort);
EXTERN int luasteam_GameServer_SetSpectatorPort(lua_State *L) {
    uint16 unSpectatorPort = static_cast<uint16>(luaL_checkint(L, 1));
    SteamGameServer()->SetSpectatorPort(unSpectatorPort);
    return 0;
}

// void SetSpectatorServerName(const char * pszSpectatorServerName);
EXTERN int luasteam_GameServer_SetSpectatorServerName(lua_State *L) {
    const char *pszSpectatorServerName = luaL_checkstring(L, 1);
    SteamGameServer()->SetSpectatorServerName(pszSpectatorServerName);
    return 0;
}

// void ClearAllKeyValues();
EXTERN int luasteam_GameServer_ClearAllKeyValues(lua_State *L) {
    SteamGameServer()->ClearAllKeyValues();
    return 0;
}

// void SetKeyValue(const char * pKey, const char * pValue);
EXTERN int luasteam_GameServer_SetKeyValue(lua_State *L) {
    const char *pKey = luaL_checkstring(L, 1);
    const char *pValue = luaL_checkstring(L, 2);
    SteamGameServer()->SetKeyValue(pKey, pValue);
    return 0;
}

// void SetGameTags(const char * pchGameTags);
EXTERN int luasteam_GameServer_SetGameTags(lua_State *L) {
    const char *pchGameTags = luaL_checkstring(L, 1);
    SteamGameServer()->SetGameTags(pchGameTags);
    return 0;
}

// void SetGameData(const char * pchGameData);
EXTERN int luasteam_GameServer_SetGameData(lua_State *L) {
    const char *pchGameData = luaL_checkstring(L, 1);
    SteamGameServer()->SetGameData(pchGameData);
    return 0;
}

// void SetRegion(const char * pszRegion);
EXTERN int luasteam_GameServer_SetRegion(lua_State *L) {
    const char *pszRegion = luaL_checkstring(L, 1);
    SteamGameServer()->SetRegion(pszRegion);
    return 0;
}

// void SetAdvertiseServerActive(bool bActive);
EXTERN int luasteam_GameServer_SetAdvertiseServerActive(lua_State *L) {
    bool bActive = lua_toboolean(L, 1);
    SteamGameServer()->SetAdvertiseServerActive(bActive);
    return 0;
}

// EBeginAuthSessionResult BeginAuthSession(const void * pAuthTicket, int cbAuthTicket, CSteamID steamID);
EXTERN int luasteam_GameServer_BeginAuthSession(lua_State *L) {
    const char *pAuthTicket = luaL_checkstring(L, 1);
    int cbAuthTicket = static_cast<int>(luaL_checkint(L, 2));
    CSteamID steamID(luasteam::checkuint64(L, 3));
    EBeginAuthSessionResult __ret = SteamGameServer()->BeginAuthSession(pAuthTicket, cbAuthTicket, steamID);
    lua_pushinteger(L, __ret);
    return 1;
}

// void EndAuthSession(CSteamID steamID);
EXTERN int luasteam_GameServer_EndAuthSession(lua_State *L) {
    CSteamID steamID(luasteam::checkuint64(L, 1));
    SteamGameServer()->EndAuthSession(steamID);
    return 0;
}

// void CancelAuthTicket(HAuthTicket hAuthTicket);
EXTERN int luasteam_GameServer_CancelAuthTicket(lua_State *L) {
    HAuthTicket hAuthTicket = static_cast<HAuthTicket>(luaL_checkint(L, 1));
    SteamGameServer()->CancelAuthTicket(hAuthTicket);
    return 0;
}

// EUserHasLicenseForAppResult UserHasLicenseForApp(CSteamID steamID, AppId_t appID);
EXTERN int luasteam_GameServer_UserHasLicenseForApp(lua_State *L) {
    CSteamID steamID(luasteam::checkuint64(L, 1));
    AppId_t appID = static_cast<AppId_t>(luaL_checkint(L, 2));
    EUserHasLicenseForAppResult __ret = SteamGameServer()->UserHasLicenseForApp(steamID, appID);
    lua_pushinteger(L, __ret);
    return 1;
}

// bool RequestUserGroupStatus(CSteamID steamIDUser, CSteamID steamIDGroup);
EXTERN int luasteam_GameServer_RequestUserGroupStatus(lua_State *L) {
    CSteamID steamIDUser(luasteam::checkuint64(L, 1));
    CSteamID steamIDGroup(luasteam::checkuint64(L, 2));
    bool __ret = SteamGameServer()->RequestUserGroupStatus(steamIDUser, steamIDGroup);
    lua_pushboolean(L, __ret);
    return 1;
}

// void GetGameplayStats();
EXTERN int luasteam_GameServer_GetGameplayStats(lua_State *L) {
    SteamGameServer()->GetGameplayStats();
    return 0;
}

// SteamAPICall_t GetServerReputation();
EXTERN int luasteam_GameServer_GetServerReputation(lua_State *L) {
    SteamAPICall_t __ret = SteamGameServer()->GetServerReputation();
    luasteam::pushuint64(L, __ret);
    return 1;
}

// SteamIPAddress_t GetPublicIP();
EXTERN int luasteam_GameServer_GetPublicIP(lua_State *L) {
    SteamIPAddress_t __ret = SteamGameServer()->GetPublicIP();
    push_SteamIPAddress_t(L, __ret);
    return 1;
}

// bool HandleIncomingPacket(const void * pData, int cbData, uint32 srcIP, uint16 srcPort);
EXTERN int luasteam_GameServer_HandleIncomingPacket(lua_State *L) {
    const char *pData = luaL_checkstring(L, 1);
    int cbData = static_cast<int>(luaL_checkint(L, 2));
    uint32 srcIP = static_cast<uint32>(luaL_checkint(L, 3));
    uint16 srcPort = static_cast<uint16>(luaL_checkint(L, 4));
    bool __ret = SteamGameServer()->HandleIncomingPacket(pData, cbData, srcIP, srcPort);
    lua_pushboolean(L, __ret);
    return 1;
}

// int GetNextOutgoingPacket(void * pOut, int cbMaxOut, uint32 * pNetAdr, uint16 * pPort);
EXTERN int luasteam_GameServer_GetNextOutgoingPacket(lua_State *L) {
    int cbMaxOut = luaL_checkint(L, 1);
    std::vector<unsigned char> pOut(cbMaxOut);
    uint32 pNetAdr;    uint16 pPort;    int __ret = SteamGameServer()->GetNextOutgoingPacket(pOut.data(), cbMaxOut, &pNetAdr, &pPort);
    lua_pushinteger(L, __ret);
    lua_pushlstring(L, reinterpret_cast<const char*>(pOut.data()), cbMaxOut);
    lua_pushinteger(L, pNetAdr);
    lua_pushinteger(L, pPort);
    return 3;
}

// SteamAPICall_t AssociateWithClan(CSteamID steamIDClan);
EXTERN int luasteam_GameServer_AssociateWithClan(lua_State *L) {
    CSteamID steamIDClan(luasteam::checkuint64(L, 1));
    SteamAPICall_t __ret = SteamGameServer()->AssociateWithClan(steamIDClan);
    luasteam::pushuint64(L, __ret);
    return 1;
}

// SteamAPICall_t ComputeNewPlayerCompatibility(CSteamID steamIDNewPlayer);
EXTERN int luasteam_GameServer_ComputeNewPlayerCompatibility(lua_State *L) {
    CSteamID steamIDNewPlayer(luasteam::checkuint64(L, 1));
    SteamAPICall_t __ret = SteamGameServer()->ComputeNewPlayerCompatibility(steamIDNewPlayer);
    luasteam::pushuint64(L, __ret);
    return 1;
}

// CSteamID CreateUnauthenticatedUserConnection();
EXTERN int luasteam_GameServer_CreateUnauthenticatedUserConnection(lua_State *L) {
    CSteamID __ret = SteamGameServer()->CreateUnauthenticatedUserConnection();
    luasteam::pushuint64(L, __ret.ConvertToUint64());
    return 1;
}

// bool BUpdateUserData(CSteamID steamIDUser, const char * pchPlayerName, uint32 uScore);
EXTERN int luasteam_GameServer_BUpdateUserData(lua_State *L) {
    CSteamID steamIDUser(luasteam::checkuint64(L, 1));
    const char *pchPlayerName = luaL_checkstring(L, 2);
    uint32 uScore = static_cast<uint32>(luaL_checkint(L, 3));
    bool __ret = SteamGameServer()->BUpdateUserData(steamIDUser, pchPlayerName, uScore);
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
    lua_createtable(L, 0, 38);
    register_GameServer_auto(L);
    lua_pushvalue(L, -1);
    GameServer_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "GameServer");
}

} // namespace luasteam
