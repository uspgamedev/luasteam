#include "auto.hpp"

namespace luasteam {

int Matchmaking_ref = LUA_NOREF;

namespace {

class CallbackListener {
  private:
    STEAM_CALLBACK(CallbackListener, OnFavoritesListChanged, FavoritesListChanged_t);
    STEAM_CALLBACK(CallbackListener, OnLobbyInvite, LobbyInvite_t);
    STEAM_CALLBACK(CallbackListener, OnLobbyEnter, LobbyEnter_t);
    STEAM_CALLBACK(CallbackListener, OnLobbyDataUpdate, LobbyDataUpdate_t);
    STEAM_CALLBACK(CallbackListener, OnLobbyChatUpdate, LobbyChatUpdate_t);
    STEAM_CALLBACK(CallbackListener, OnLobbyChatMsg, LobbyChatMsg_t);
    STEAM_CALLBACK(CallbackListener, OnLobbyGameCreated, LobbyGameCreated_t);
    STEAM_CALLBACK(CallbackListener, OnLobbyMatchList, LobbyMatchList_t);
    STEAM_CALLBACK(CallbackListener, OnLobbyKicked, LobbyKicked_t);
    STEAM_CALLBACK(CallbackListener, OnLobbyCreated, LobbyCreated_t);
    STEAM_CALLBACK(CallbackListener, OnFavoritesListAccountsUpdated, FavoritesListAccountsUpdated_t);
};

void CallbackListener::OnFavoritesListChanged(FavoritesListChanged_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Matchmaking_ref);
    lua_getfield(L, -1, "onFavoritesListChanged");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 7);
        lua_pushinteger(L, data->m_nIP);
        lua_setfield(L, -2, "iP");
        lua_pushinteger(L, data->m_nQueryPort);
        lua_setfield(L, -2, "queryPort");
        lua_pushinteger(L, data->m_nConnPort);
        lua_setfield(L, -2, "connPort");
        lua_pushinteger(L, data->m_nAppID);
        lua_setfield(L, -2, "appID");
        lua_pushinteger(L, data->m_nFlags);
        lua_setfield(L, -2, "flags");
        lua_pushboolean(L, data->m_bAdd);
        lua_setfield(L, -2, "add");
        lua_pushinteger(L, data->m_unAccountId);
        lua_setfield(L, -2, "accountId");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnLobbyInvite(LobbyInvite_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Matchmaking_ref);
    lua_getfield(L, -1, "onLobbyInvite");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        luasteam::pushuint64(L, data->m_ulSteamIDUser);
        lua_setfield(L, -2, "steamIDUser");
        luasteam::pushuint64(L, data->m_ulSteamIDLobby);
        lua_setfield(L, -2, "steamIDLobby");
        luasteam::pushuint64(L, data->m_ulGameID);
        lua_setfield(L, -2, "gameID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnLobbyEnter(LobbyEnter_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Matchmaking_ref);
    lua_getfield(L, -1, "onLobbyEnter");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        luasteam::pushuint64(L, data->m_ulSteamIDLobby);
        lua_setfield(L, -2, "steamIDLobby");
        lua_pushinteger(L, data->m_rgfChatPermissions);
        lua_setfield(L, -2, "rgfChatPermissions");
        lua_pushboolean(L, data->m_bLocked);
        lua_setfield(L, -2, "locked");
        lua_pushinteger(L, data->m_EChatRoomEnterResponse);
        lua_setfield(L, -2, "eChatRoomEnterResponse");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnLobbyDataUpdate(LobbyDataUpdate_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Matchmaking_ref);
    lua_getfield(L, -1, "onLobbyDataUpdate");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        luasteam::pushuint64(L, data->m_ulSteamIDLobby);
        lua_setfield(L, -2, "steamIDLobby");
        luasteam::pushuint64(L, data->m_ulSteamIDMember);
        lua_setfield(L, -2, "steamIDMember");
        lua_pushboolean(L, data->m_bSuccess);
        lua_setfield(L, -2, "success");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnLobbyChatUpdate(LobbyChatUpdate_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Matchmaking_ref);
    lua_getfield(L, -1, "onLobbyChatUpdate");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        luasteam::pushuint64(L, data->m_ulSteamIDLobby);
        lua_setfield(L, -2, "steamIDLobby");
        luasteam::pushuint64(L, data->m_ulSteamIDUserChanged);
        lua_setfield(L, -2, "steamIDUserChanged");
        luasteam::pushuint64(L, data->m_ulSteamIDMakingChange);
        lua_setfield(L, -2, "steamIDMakingChange");
        lua_pushinteger(L, data->m_rgfChatMemberStateChange);
        lua_setfield(L, -2, "rgfChatMemberStateChange");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnLobbyChatMsg(LobbyChatMsg_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Matchmaking_ref);
    lua_getfield(L, -1, "onLobbyChatMsg");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        luasteam::pushuint64(L, data->m_ulSteamIDLobby);
        lua_setfield(L, -2, "steamIDLobby");
        luasteam::pushuint64(L, data->m_ulSteamIDUser);
        lua_setfield(L, -2, "steamIDUser");
        lua_pushinteger(L, data->m_eChatEntryType);
        lua_setfield(L, -2, "chatEntryType");
        lua_pushinteger(L, data->m_iChatID);
        lua_setfield(L, -2, "iChatID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnLobbyGameCreated(LobbyGameCreated_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Matchmaking_ref);
    lua_getfield(L, -1, "onLobbyGameCreated");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        luasteam::pushuint64(L, data->m_ulSteamIDLobby);
        lua_setfield(L, -2, "steamIDLobby");
        luasteam::pushuint64(L, data->m_ulSteamIDGameServer);
        lua_setfield(L, -2, "steamIDGameServer");
        lua_pushinteger(L, data->m_unIP);
        lua_setfield(L, -2, "iP");
        lua_pushinteger(L, data->m_usPort);
        lua_setfield(L, -2, "usPort");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnLobbyMatchList(LobbyMatchList_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Matchmaking_ref);
    lua_getfield(L, -1, "onLobbyMatchList");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushinteger(L, data->m_nLobbiesMatching);
        lua_setfield(L, -2, "lobbiesMatching");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnLobbyKicked(LobbyKicked_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Matchmaking_ref);
    lua_getfield(L, -1, "onLobbyKicked");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        luasteam::pushuint64(L, data->m_ulSteamIDLobby);
        lua_setfield(L, -2, "steamIDLobby");
        luasteam::pushuint64(L, data->m_ulSteamIDAdmin);
        lua_setfield(L, -2, "steamIDAdmin");
        lua_pushboolean(L, data->m_bKickedDueToDisconnect);
        lua_setfield(L, -2, "kickedDueToDisconnect");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnLobbyCreated(LobbyCreated_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Matchmaking_ref);
    lua_getfield(L, -1, "onLobbyCreated");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_ulSteamIDLobby);
        lua_setfield(L, -2, "steamIDLobby");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnFavoritesListAccountsUpdated(FavoritesListAccountsUpdated_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Matchmaking_ref);
    lua_getfield(L, -1, "onFavoritesListAccountsUpdated");
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

CallbackListener *Matchmaking_listener = nullptr;

} // namespace

void init_Matchmaking_auto(lua_State *L) { Matchmaking_listener = new CallbackListener(); }

void shutdown_Matchmaking_auto(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, Matchmaking_ref);
    Matchmaking_ref = LUA_NOREF;
    delete Matchmaking_listener; Matchmaking_listener = nullptr;
}


// int GetFavoriteGameCount();
EXTERN int luasteam_Matchmaking_GetFavoriteGameCount(lua_State *L) {
    lua_pushinteger(L, SteamMatchmaking()->GetFavoriteGameCount());
    return 1;
}

// int AddFavoriteGame(AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags, uint32 rTime32LastPlayedOnServer);
EXTERN int luasteam_Matchmaking_AddFavoriteGame(lua_State *L) {
    AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
    uint32 nIP = static_cast<uint32>(luaL_checkint(L, 2));
    uint16 nConnPort = static_cast<uint16>(luaL_checkint(L, 3));
    uint16 nQueryPort = static_cast<uint16>(luaL_checkint(L, 4));
    uint32 unFlags = static_cast<uint32>(luaL_checkint(L, 5));
    uint32 rTime32LastPlayedOnServer = static_cast<uint32>(luaL_checkint(L, 6));
    lua_pushinteger(L, SteamMatchmaking()->AddFavoriteGame(nAppID, nIP, nConnPort, nQueryPort, unFlags, rTime32LastPlayedOnServer));
    return 1;
}

// bool RemoveFavoriteGame(AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags);
EXTERN int luasteam_Matchmaking_RemoveFavoriteGame(lua_State *L) {
    AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
    uint32 nIP = static_cast<uint32>(luaL_checkint(L, 2));
    uint16 nConnPort = static_cast<uint16>(luaL_checkint(L, 3));
    uint16 nQueryPort = static_cast<uint16>(luaL_checkint(L, 4));
    uint32 unFlags = static_cast<uint32>(luaL_checkint(L, 5));
    lua_pushboolean(L, SteamMatchmaking()->RemoveFavoriteGame(nAppID, nIP, nConnPort, nQueryPort, unFlags));
    return 1;
}

// SteamAPICall_t RequestLobbyList();
EXTERN int luasteam_Matchmaking_RequestLobbyList(lua_State *L) {
    luasteam::pushuint64(L, SteamMatchmaking()->RequestLobbyList());
    return 1;
}

// void AddRequestLobbyListStringFilter(const char * pchKeyToMatch, const char * pchValueToMatch, ELobbyComparison eComparisonType);
EXTERN int luasteam_Matchmaking_AddRequestLobbyListStringFilter(lua_State *L) {
    const char *pchKeyToMatch = luaL_checkstring(L, 1);
    const char *pchValueToMatch = luaL_checkstring(L, 2);
    ELobbyComparison eComparisonType = static_cast<ELobbyComparison>(luaL_checkint(L, 3));
    SteamMatchmaking()->AddRequestLobbyListStringFilter(pchKeyToMatch, pchValueToMatch, eComparisonType);
    return 0;
}

// void AddRequestLobbyListNumericalFilter(const char * pchKeyToMatch, int nValueToMatch, ELobbyComparison eComparisonType);
EXTERN int luasteam_Matchmaking_AddRequestLobbyListNumericalFilter(lua_State *L) {
    const char *pchKeyToMatch = luaL_checkstring(L, 1);
    int nValueToMatch = static_cast<int>(luaL_checkint(L, 2));
    ELobbyComparison eComparisonType = static_cast<ELobbyComparison>(luaL_checkint(L, 3));
    SteamMatchmaking()->AddRequestLobbyListNumericalFilter(pchKeyToMatch, nValueToMatch, eComparisonType);
    return 0;
}

// void AddRequestLobbyListNearValueFilter(const char * pchKeyToMatch, int nValueToBeCloseTo);
EXTERN int luasteam_Matchmaking_AddRequestLobbyListNearValueFilter(lua_State *L) {
    const char *pchKeyToMatch = luaL_checkstring(L, 1);
    int nValueToBeCloseTo = static_cast<int>(luaL_checkint(L, 2));
    SteamMatchmaking()->AddRequestLobbyListNearValueFilter(pchKeyToMatch, nValueToBeCloseTo);
    return 0;
}

// void AddRequestLobbyListFilterSlotsAvailable(int nSlotsAvailable);
EXTERN int luasteam_Matchmaking_AddRequestLobbyListFilterSlotsAvailable(lua_State *L) {
    int nSlotsAvailable = static_cast<int>(luaL_checkint(L, 1));
    SteamMatchmaking()->AddRequestLobbyListFilterSlotsAvailable(nSlotsAvailable);
    return 0;
}

// void AddRequestLobbyListDistanceFilter(ELobbyDistanceFilter eLobbyDistanceFilter);
EXTERN int luasteam_Matchmaking_AddRequestLobbyListDistanceFilter(lua_State *L) {
    ELobbyDistanceFilter eLobbyDistanceFilter = static_cast<ELobbyDistanceFilter>(luaL_checkint(L, 1));
    SteamMatchmaking()->AddRequestLobbyListDistanceFilter(eLobbyDistanceFilter);
    return 0;
}

// void AddRequestLobbyListResultCountFilter(int cMaxResults);
EXTERN int luasteam_Matchmaking_AddRequestLobbyListResultCountFilter(lua_State *L) {
    int cMaxResults = static_cast<int>(luaL_checkint(L, 1));
    SteamMatchmaking()->AddRequestLobbyListResultCountFilter(cMaxResults);
    return 0;
}

// void AddRequestLobbyListCompatibleMembersFilter(CSteamID steamIDLobby);
EXTERN int luasteam_Matchmaking_AddRequestLobbyListCompatibleMembersFilter(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    SteamMatchmaking()->AddRequestLobbyListCompatibleMembersFilter(steamIDLobby);
    return 0;
}

// CSteamID GetLobbyByIndex(int iLobby);
EXTERN int luasteam_Matchmaking_GetLobbyByIndex(lua_State *L) {
    int iLobby = static_cast<int>(luaL_checkint(L, 1));
    luasteam::pushuint64(L, (SteamMatchmaking()->GetLobbyByIndex(iLobby)).ConvertToUint64());
    return 1;
}

// SteamAPICall_t CreateLobby(ELobbyType eLobbyType, int cMaxMembers);
EXTERN int luasteam_Matchmaking_CreateLobby(lua_State *L) {
    ELobbyType eLobbyType = static_cast<ELobbyType>(luaL_checkint(L, 1));
    int cMaxMembers = static_cast<int>(luaL_checkint(L, 2));
    luasteam::pushuint64(L, SteamMatchmaking()->CreateLobby(eLobbyType, cMaxMembers));
    return 1;
}

// SteamAPICall_t JoinLobby(CSteamID steamIDLobby);
EXTERN int luasteam_Matchmaking_JoinLobby(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    luasteam::pushuint64(L, SteamMatchmaking()->JoinLobby(steamIDLobby));
    return 1;
}

// void LeaveLobby(CSteamID steamIDLobby);
EXTERN int luasteam_Matchmaking_LeaveLobby(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    SteamMatchmaking()->LeaveLobby(steamIDLobby);
    return 0;
}

// bool InviteUserToLobby(CSteamID steamIDLobby, CSteamID steamIDInvitee);
EXTERN int luasteam_Matchmaking_InviteUserToLobby(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    CSteamID steamIDInvitee(luasteam::checkuint64(L, 2));
    lua_pushboolean(L, SteamMatchmaking()->InviteUserToLobby(steamIDLobby, steamIDInvitee));
    return 1;
}

// int GetNumLobbyMembers(CSteamID steamIDLobby);
EXTERN int luasteam_Matchmaking_GetNumLobbyMembers(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    lua_pushinteger(L, SteamMatchmaking()->GetNumLobbyMembers(steamIDLobby));
    return 1;
}

// CSteamID GetLobbyMemberByIndex(CSteamID steamIDLobby, int iMember);
EXTERN int luasteam_Matchmaking_GetLobbyMemberByIndex(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    int iMember = static_cast<int>(luaL_checkint(L, 2));
    luasteam::pushuint64(L, (SteamMatchmaking()->GetLobbyMemberByIndex(steamIDLobby, iMember)).ConvertToUint64());
    return 1;
}

// const char * GetLobbyData(CSteamID steamIDLobby, const char * pchKey);
EXTERN int luasteam_Matchmaking_GetLobbyData(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    const char *pchKey = luaL_checkstring(L, 2);
    lua_pushstring(L, SteamMatchmaking()->GetLobbyData(steamIDLobby, pchKey));
    return 1;
}

// bool SetLobbyData(CSteamID steamIDLobby, const char * pchKey, const char * pchValue);
EXTERN int luasteam_Matchmaking_SetLobbyData(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    const char *pchKey = luaL_checkstring(L, 2);
    const char *pchValue = luaL_checkstring(L, 3);
    lua_pushboolean(L, SteamMatchmaking()->SetLobbyData(steamIDLobby, pchKey, pchValue));
    return 1;
}

// int GetLobbyDataCount(CSteamID steamIDLobby);
EXTERN int luasteam_Matchmaking_GetLobbyDataCount(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    lua_pushinteger(L, SteamMatchmaking()->GetLobbyDataCount(steamIDLobby));
    return 1;
}

// bool DeleteLobbyData(CSteamID steamIDLobby, const char * pchKey);
EXTERN int luasteam_Matchmaking_DeleteLobbyData(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    const char *pchKey = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamMatchmaking()->DeleteLobbyData(steamIDLobby, pchKey));
    return 1;
}

// const char * GetLobbyMemberData(CSteamID steamIDLobby, CSteamID steamIDUser, const char * pchKey);
EXTERN int luasteam_Matchmaking_GetLobbyMemberData(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    CSteamID steamIDUser(luasteam::checkuint64(L, 2));
    const char *pchKey = luaL_checkstring(L, 3);
    lua_pushstring(L, SteamMatchmaking()->GetLobbyMemberData(steamIDLobby, steamIDUser, pchKey));
    return 1;
}

// void SetLobbyMemberData(CSteamID steamIDLobby, const char * pchKey, const char * pchValue);
EXTERN int luasteam_Matchmaking_SetLobbyMemberData(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    const char *pchKey = luaL_checkstring(L, 2);
    const char *pchValue = luaL_checkstring(L, 3);
    SteamMatchmaking()->SetLobbyMemberData(steamIDLobby, pchKey, pchValue);
    return 0;
}

// bool RequestLobbyData(CSteamID steamIDLobby);
EXTERN int luasteam_Matchmaking_RequestLobbyData(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    lua_pushboolean(L, SteamMatchmaking()->RequestLobbyData(steamIDLobby));
    return 1;
}

// void SetLobbyGameServer(CSteamID steamIDLobby, uint32 unGameServerIP, uint16 unGameServerPort, CSteamID steamIDGameServer);
EXTERN int luasteam_Matchmaking_SetLobbyGameServer(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    uint32 unGameServerIP = static_cast<uint32>(luaL_checkint(L, 2));
    uint16 unGameServerPort = static_cast<uint16>(luaL_checkint(L, 3));
    CSteamID steamIDGameServer(luasteam::checkuint64(L, 4));
    SteamMatchmaking()->SetLobbyGameServer(steamIDLobby, unGameServerIP, unGameServerPort, steamIDGameServer);
    return 0;
}

// bool SetLobbyMemberLimit(CSteamID steamIDLobby, int cMaxMembers);
EXTERN int luasteam_Matchmaking_SetLobbyMemberLimit(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    int cMaxMembers = static_cast<int>(luaL_checkint(L, 2));
    lua_pushboolean(L, SteamMatchmaking()->SetLobbyMemberLimit(steamIDLobby, cMaxMembers));
    return 1;
}

// int GetLobbyMemberLimit(CSteamID steamIDLobby);
EXTERN int luasteam_Matchmaking_GetLobbyMemberLimit(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    lua_pushinteger(L, SteamMatchmaking()->GetLobbyMemberLimit(steamIDLobby));
    return 1;
}

// bool SetLobbyType(CSteamID steamIDLobby, ELobbyType eLobbyType);
EXTERN int luasteam_Matchmaking_SetLobbyType(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    ELobbyType eLobbyType = static_cast<ELobbyType>(luaL_checkint(L, 2));
    lua_pushboolean(L, SteamMatchmaking()->SetLobbyType(steamIDLobby, eLobbyType));
    return 1;
}

// bool SetLobbyJoinable(CSteamID steamIDLobby, bool bLobbyJoinable);
EXTERN int luasteam_Matchmaking_SetLobbyJoinable(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    bool bLobbyJoinable = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamMatchmaking()->SetLobbyJoinable(steamIDLobby, bLobbyJoinable));
    return 1;
}

// CSteamID GetLobbyOwner(CSteamID steamIDLobby);
EXTERN int luasteam_Matchmaking_GetLobbyOwner(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    luasteam::pushuint64(L, (SteamMatchmaking()->GetLobbyOwner(steamIDLobby)).ConvertToUint64());
    return 1;
}

// bool SetLobbyOwner(CSteamID steamIDLobby, CSteamID steamIDNewOwner);
EXTERN int luasteam_Matchmaking_SetLobbyOwner(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    CSteamID steamIDNewOwner(luasteam::checkuint64(L, 2));
    lua_pushboolean(L, SteamMatchmaking()->SetLobbyOwner(steamIDLobby, steamIDNewOwner));
    return 1;
}

// bool SetLinkedLobby(CSteamID steamIDLobby, CSteamID steamIDLobbyDependent);
EXTERN int luasteam_Matchmaking_SetLinkedLobby(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    CSteamID steamIDLobbyDependent(luasteam::checkuint64(L, 2));
    lua_pushboolean(L, SteamMatchmaking()->SetLinkedLobby(steamIDLobby, steamIDLobbyDependent));
    return 1;
}

void register_Matchmaking_auto(lua_State *L) {
    add_func(L, "GetFavoriteGameCount", luasteam_Matchmaking_GetFavoriteGameCount);
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
    add_func(L, "DeleteLobbyData", luasteam_Matchmaking_DeleteLobbyData);
    add_func(L, "GetLobbyMemberData", luasteam_Matchmaking_GetLobbyMemberData);
    add_func(L, "SetLobbyMemberData", luasteam_Matchmaking_SetLobbyMemberData);
    add_func(L, "RequestLobbyData", luasteam_Matchmaking_RequestLobbyData);
    add_func(L, "SetLobbyGameServer", luasteam_Matchmaking_SetLobbyGameServer);
    add_func(L, "SetLobbyMemberLimit", luasteam_Matchmaking_SetLobbyMemberLimit);
    add_func(L, "GetLobbyMemberLimit", luasteam_Matchmaking_GetLobbyMemberLimit);
    add_func(L, "SetLobbyType", luasteam_Matchmaking_SetLobbyType);
    add_func(L, "SetLobbyJoinable", luasteam_Matchmaking_SetLobbyJoinable);
    add_func(L, "GetLobbyOwner", luasteam_Matchmaking_GetLobbyOwner);
    add_func(L, "SetLobbyOwner", luasteam_Matchmaking_SetLobbyOwner);
    add_func(L, "SetLinkedLobby", luasteam_Matchmaking_SetLinkedLobby);
}

void add_Matchmaking_auto(lua_State *L) {
    lua_createtable(L, 0, 33);
    register_Matchmaking_auto(L);
    lua_pushvalue(L, -1);
    Matchmaking_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "Matchmaking");
}

} // namespace luasteam
