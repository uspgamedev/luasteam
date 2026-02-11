#include "auto.hpp"

// int GetFavoriteGameCount();
EXTERN int luasteam_matchmaking_SteamAPI_ISteamMatchmaking_GetFavoriteGameCount(lua_State *L) {
    lua_pushinteger(L, SteamMatchmaking()->GetFavoriteGameCount());
    return 1;
}

// int AddFavoriteGame(AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags, uint32 rTime32LastPlayedOnServer);
EXTERN int luasteam_matchmaking_SteamAPI_ISteamMatchmaking_AddFavoriteGame(lua_State *L) {
    AppId_t nAppID = luaL_checkint(L, 1);
    uint32 nIP = luaL_checkint(L, 2);
    uint16 nConnPort = luaL_checkint(L, 3);
    uint16 nQueryPort = luaL_checkint(L, 4);
    uint32 unFlags = luaL_checkint(L, 5);
    uint32 rTime32LastPlayedOnServer = luaL_checkint(L, 6);
    lua_pushinteger(L, SteamMatchmaking()->AddFavoriteGame(nAppID, nIP, nConnPort, nQueryPort, unFlags, rTime32LastPlayedOnServer));
    return 1;
}

// bool RemoveFavoriteGame(AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags);
EXTERN int luasteam_matchmaking_SteamAPI_ISteamMatchmaking_RemoveFavoriteGame(lua_State *L) {
    AppId_t nAppID = luaL_checkint(L, 1);
    uint32 nIP = luaL_checkint(L, 2);
    uint16 nConnPort = luaL_checkint(L, 3);
    uint16 nQueryPort = luaL_checkint(L, 4);
    uint32 unFlags = luaL_checkint(L, 5);
    lua_pushboolean(L, SteamMatchmaking()->RemoveFavoriteGame(nAppID, nIP, nConnPort, nQueryPort, unFlags));
    return 1;
}

// SteamAPICall_t RequestLobbyList();
EXTERN int luasteam_matchmaking_SteamAPI_ISteamMatchmaking_RequestLobbyList(lua_State *L) {
    luasteam::pushuint64(L, SteamMatchmaking()->RequestLobbyList());
    return 1;
}

// void AddRequestLobbyListNearValueFilter(const char * pchKeyToMatch, int nValueToBeCloseTo);
EXTERN int luasteam_matchmaking_SteamAPI_ISteamMatchmaking_AddRequestLobbyListNearValueFilter(lua_State *L) {
    const char *pchKeyToMatch = luaL_checkstring(L, 1);
    int nValueToBeCloseTo = luaL_checkint(L, 2);
    SteamMatchmaking()->AddRequestLobbyListNearValueFilter(pchKeyToMatch, nValueToBeCloseTo);
    return 0;
}

// void AddRequestLobbyListFilterSlotsAvailable(int nSlotsAvailable);
EXTERN int luasteam_matchmaking_SteamAPI_ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable(lua_State *L) {
    int nSlotsAvailable = luaL_checkint(L, 1);
    SteamMatchmaking()->AddRequestLobbyListFilterSlotsAvailable(nSlotsAvailable);
    return 0;
}

// void AddRequestLobbyListResultCountFilter(int cMaxResults);
EXTERN int luasteam_matchmaking_SteamAPI_ISteamMatchmaking_AddRequestLobbyListResultCountFilter(lua_State *L) {
    int cMaxResults = luaL_checkint(L, 1);
    SteamMatchmaking()->AddRequestLobbyListResultCountFilter(cMaxResults);
    return 0;
}

// void AddRequestLobbyListCompatibleMembersFilter(CSteamID steamIDLobby);
EXTERN int luasteam_matchmaking_SteamAPI_ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    SteamMatchmaking()->AddRequestLobbyListCompatibleMembersFilter(steamIDLobby);
    return 0;
}

// CSteamID GetLobbyByIndex(int iLobby);
EXTERN int luasteam_matchmaking_SteamAPI_ISteamMatchmaking_GetLobbyByIndex(lua_State *L) {
    int iLobby = luaL_checkint(L, 1);
    luasteam::pushuint64(L, (SteamMatchmaking()->GetLobbyByIndex(iLobby)).ConvertToUint64());
    return 1;
}

// SteamAPICall_t JoinLobby(CSteamID steamIDLobby);
EXTERN int luasteam_matchmaking_SteamAPI_ISteamMatchmaking_JoinLobby(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    luasteam::pushuint64(L, SteamMatchmaking()->JoinLobby(steamIDLobby));
    return 1;
}

// void LeaveLobby(CSteamID steamIDLobby);
EXTERN int luasteam_matchmaking_SteamAPI_ISteamMatchmaking_LeaveLobby(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    SteamMatchmaking()->LeaveLobby(steamIDLobby);
    return 0;
}

// bool InviteUserToLobby(CSteamID steamIDLobby, CSteamID steamIDInvitee);
EXTERN int luasteam_matchmaking_SteamAPI_ISteamMatchmaking_InviteUserToLobby(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    CSteamID steamIDInvitee(luasteam::checkuint64(L, 2));
    lua_pushboolean(L, SteamMatchmaking()->InviteUserToLobby(steamIDLobby, steamIDInvitee));
    return 1;
}

// int GetNumLobbyMembers(CSteamID steamIDLobby);
EXTERN int luasteam_matchmaking_SteamAPI_ISteamMatchmaking_GetNumLobbyMembers(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    lua_pushinteger(L, SteamMatchmaking()->GetNumLobbyMembers(steamIDLobby));
    return 1;
}

// CSteamID GetLobbyMemberByIndex(CSteamID steamIDLobby, int iMember);
EXTERN int luasteam_matchmaking_SteamAPI_ISteamMatchmaking_GetLobbyMemberByIndex(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    int iMember = luaL_checkint(L, 2);
    luasteam::pushuint64(L, (SteamMatchmaking()->GetLobbyMemberByIndex(steamIDLobby, iMember)).ConvertToUint64());
    return 1;
}

// const char * GetLobbyData(CSteamID steamIDLobby, const char * pchKey);
EXTERN int luasteam_matchmaking_SteamAPI_ISteamMatchmaking_GetLobbyData(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    const char *pchKey = luaL_checkstring(L, 2);
    lua_pushstring(L, SteamMatchmaking()->GetLobbyData(steamIDLobby, pchKey));
    return 1;
}

// bool SetLobbyData(CSteamID steamIDLobby, const char * pchKey, const char * pchValue);
EXTERN int luasteam_matchmaking_SteamAPI_ISteamMatchmaking_SetLobbyData(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    const char *pchKey = luaL_checkstring(L, 2);
    const char *pchValue = luaL_checkstring(L, 3);
    lua_pushboolean(L, SteamMatchmaking()->SetLobbyData(steamIDLobby, pchKey, pchValue));
    return 1;
}

// int GetLobbyDataCount(CSteamID steamIDLobby);
EXTERN int luasteam_matchmaking_SteamAPI_ISteamMatchmaking_GetLobbyDataCount(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    lua_pushinteger(L, SteamMatchmaking()->GetLobbyDataCount(steamIDLobby));
    return 1;
}

// bool DeleteLobbyData(CSteamID steamIDLobby, const char * pchKey);
EXTERN int luasteam_matchmaking_SteamAPI_ISteamMatchmaking_DeleteLobbyData(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    const char *pchKey = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamMatchmaking()->DeleteLobbyData(steamIDLobby, pchKey));
    return 1;
}

// const char * GetLobbyMemberData(CSteamID steamIDLobby, CSteamID steamIDUser, const char * pchKey);
EXTERN int luasteam_matchmaking_SteamAPI_ISteamMatchmaking_GetLobbyMemberData(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    CSteamID steamIDUser(luasteam::checkuint64(L, 2));
    const char *pchKey = luaL_checkstring(L, 3);
    lua_pushstring(L, SteamMatchmaking()->GetLobbyMemberData(steamIDLobby, steamIDUser, pchKey));
    return 1;
}

// void SetLobbyMemberData(CSteamID steamIDLobby, const char * pchKey, const char * pchValue);
EXTERN int luasteam_matchmaking_SteamAPI_ISteamMatchmaking_SetLobbyMemberData(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    const char *pchKey = luaL_checkstring(L, 2);
    const char *pchValue = luaL_checkstring(L, 3);
    SteamMatchmaking()->SetLobbyMemberData(steamIDLobby, pchKey, pchValue);
    return 0;
}

// bool RequestLobbyData(CSteamID steamIDLobby);
EXTERN int luasteam_matchmaking_SteamAPI_ISteamMatchmaking_RequestLobbyData(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    lua_pushboolean(L, SteamMatchmaking()->RequestLobbyData(steamIDLobby));
    return 1;
}

// void SetLobbyGameServer(CSteamID steamIDLobby, uint32 unGameServerIP, uint16 unGameServerPort, CSteamID steamIDGameServer);
EXTERN int luasteam_matchmaking_SteamAPI_ISteamMatchmaking_SetLobbyGameServer(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    uint32 unGameServerIP = luaL_checkint(L, 2);
    uint16 unGameServerPort = luaL_checkint(L, 3);
    CSteamID steamIDGameServer(luasteam::checkuint64(L, 4));
    SteamMatchmaking()->SetLobbyGameServer(steamIDLobby, unGameServerIP, unGameServerPort, steamIDGameServer);
    return 0;
}

// bool SetLobbyMemberLimit(CSteamID steamIDLobby, int cMaxMembers);
EXTERN int luasteam_matchmaking_SteamAPI_ISteamMatchmaking_SetLobbyMemberLimit(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    int cMaxMembers = luaL_checkint(L, 2);
    lua_pushboolean(L, SteamMatchmaking()->SetLobbyMemberLimit(steamIDLobby, cMaxMembers));
    return 1;
}

// int GetLobbyMemberLimit(CSteamID steamIDLobby);
EXTERN int luasteam_matchmaking_SteamAPI_ISteamMatchmaking_GetLobbyMemberLimit(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    lua_pushinteger(L, SteamMatchmaking()->GetLobbyMemberLimit(steamIDLobby));
    return 1;
}

// bool SetLobbyJoinable(CSteamID steamIDLobby, bool bLobbyJoinable);
EXTERN int luasteam_matchmaking_SteamAPI_ISteamMatchmaking_SetLobbyJoinable(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    bool bLobbyJoinable = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamMatchmaking()->SetLobbyJoinable(steamIDLobby, bLobbyJoinable));
    return 1;
}

// CSteamID GetLobbyOwner(CSteamID steamIDLobby);
EXTERN int luasteam_matchmaking_SteamAPI_ISteamMatchmaking_GetLobbyOwner(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    luasteam::pushuint64(L, (SteamMatchmaking()->GetLobbyOwner(steamIDLobby)).ConvertToUint64());
    return 1;
}

// bool SetLobbyOwner(CSteamID steamIDLobby, CSteamID steamIDNewOwner);
EXTERN int luasteam_matchmaking_SteamAPI_ISteamMatchmaking_SetLobbyOwner(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    CSteamID steamIDNewOwner(luasteam::checkuint64(L, 2));
    lua_pushboolean(L, SteamMatchmaking()->SetLobbyOwner(steamIDLobby, steamIDNewOwner));
    return 1;
}

// bool SetLinkedLobby(CSteamID steamIDLobby, CSteamID steamIDLobbyDependent);
EXTERN int luasteam_matchmaking_SteamAPI_ISteamMatchmaking_SetLinkedLobby(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    CSteamID steamIDLobbyDependent(luasteam::checkuint64(L, 2));
    lua_pushboolean(L, SteamMatchmaking()->SetLinkedLobby(steamIDLobby, steamIDLobbyDependent));
    return 1;
}

namespace luasteam {

void add_matchmaking_auto(lua_State *L) {
    add_func(L, "getFavoriteGameCount", luasteam_matchmaking_SteamAPI_ISteamMatchmaking_GetFavoriteGameCount);
    add_func(L, "addFavoriteGame", luasteam_matchmaking_SteamAPI_ISteamMatchmaking_AddFavoriteGame);
    add_func(L, "removeFavoriteGame", luasteam_matchmaking_SteamAPI_ISteamMatchmaking_RemoveFavoriteGame);
    add_func(L, "requestLobbyList", luasteam_matchmaking_SteamAPI_ISteamMatchmaking_RequestLobbyList);
    add_func(L, "addRequestLobbyListNearValueFilter", luasteam_matchmaking_SteamAPI_ISteamMatchmaking_AddRequestLobbyListNearValueFilter);
    add_func(L, "addRequestLobbyListFilterSlotsAvailable", luasteam_matchmaking_SteamAPI_ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable);
    add_func(L, "addRequestLobbyListResultCountFilter", luasteam_matchmaking_SteamAPI_ISteamMatchmaking_AddRequestLobbyListResultCountFilter);
    add_func(L, "addRequestLobbyListCompatibleMembersFilter", luasteam_matchmaking_SteamAPI_ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter);
    add_func(L, "getLobbyByIndex", luasteam_matchmaking_SteamAPI_ISteamMatchmaking_GetLobbyByIndex);
    add_func(L, "joinLobby", luasteam_matchmaking_SteamAPI_ISteamMatchmaking_JoinLobby);
    add_func(L, "leaveLobby", luasteam_matchmaking_SteamAPI_ISteamMatchmaking_LeaveLobby);
    add_func(L, "inviteUserToLobby", luasteam_matchmaking_SteamAPI_ISteamMatchmaking_InviteUserToLobby);
    add_func(L, "getNumLobbyMembers", luasteam_matchmaking_SteamAPI_ISteamMatchmaking_GetNumLobbyMembers);
    add_func(L, "getLobbyMemberByIndex", luasteam_matchmaking_SteamAPI_ISteamMatchmaking_GetLobbyMemberByIndex);
    add_func(L, "getLobbyData", luasteam_matchmaking_SteamAPI_ISteamMatchmaking_GetLobbyData);
    add_func(L, "setLobbyData", luasteam_matchmaking_SteamAPI_ISteamMatchmaking_SetLobbyData);
    add_func(L, "getLobbyDataCount", luasteam_matchmaking_SteamAPI_ISteamMatchmaking_GetLobbyDataCount);
    add_func(L, "deleteLobbyData", luasteam_matchmaking_SteamAPI_ISteamMatchmaking_DeleteLobbyData);
    add_func(L, "getLobbyMemberData", luasteam_matchmaking_SteamAPI_ISteamMatchmaking_GetLobbyMemberData);
    add_func(L, "setLobbyMemberData", luasteam_matchmaking_SteamAPI_ISteamMatchmaking_SetLobbyMemberData);
    add_func(L, "requestLobbyData", luasteam_matchmaking_SteamAPI_ISteamMatchmaking_RequestLobbyData);
    add_func(L, "setLobbyGameServer", luasteam_matchmaking_SteamAPI_ISteamMatchmaking_SetLobbyGameServer);
    add_func(L, "setLobbyMemberLimit", luasteam_matchmaking_SteamAPI_ISteamMatchmaking_SetLobbyMemberLimit);
    add_func(L, "getLobbyMemberLimit", luasteam_matchmaking_SteamAPI_ISteamMatchmaking_GetLobbyMemberLimit);
    add_func(L, "setLobbyJoinable", luasteam_matchmaking_SteamAPI_ISteamMatchmaking_SetLobbyJoinable);
    add_func(L, "getLobbyOwner", luasteam_matchmaking_SteamAPI_ISteamMatchmaking_GetLobbyOwner);
    add_func(L, "setLobbyOwner", luasteam_matchmaking_SteamAPI_ISteamMatchmaking_SetLobbyOwner);
    add_func(L, "setLinkedLobby", luasteam_matchmaking_SteamAPI_ISteamMatchmaking_SetLinkedLobby);
}

} // namespace luasteam
