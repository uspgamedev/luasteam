#include "matchmaking.hpp"
#include "const.hpp"

// ================================
// ======= SteamMatchmaking =======
// ================================

using luasteam::CallResultListener;

namespace {

class CallbackListener;
CallbackListener *callback_listener = nullptr;
int matchmaking_ref = LUA_NOREF;

static const char *distance_filter[] = {
    "Close", "Default", "Far", "Worldwide", nullptr,
};

static const char *lobby_comparison[] = {
    "EqualToOrLessThan", "LessThan", "Equal", "GreaterThan", "EqualToOrGreaterThan", "NotEqual", nullptr,
};

static const char *lobby_type[] = {
    "Private", "FriendsOnly", "Public", "Invisible", nullptr,
};

class CallbackListener {
  private:
    STEAM_CALLBACK(CallbackListener, OnFavoritesListChanged, FavoritesListChanged_t);
    STEAM_CALLBACK(CallbackListener, OnLobbyChatMsg, LobbyChatMsg_t);
    STEAM_CALLBACK(CallbackListener, OnLobbyChatUpdate, LobbyChatUpdate_t);
    STEAM_CALLBACK(CallbackListener, OnLobbyCreated, LobbyCreated_t);
    STEAM_CALLBACK(CallbackListener, OnLobbyDataUpdate, LobbyDataUpdate_t);
    STEAM_CALLBACK(CallbackListener, OnLobbyEnter, LobbyEnter_t);
    STEAM_CALLBACK(CallbackListener, OnLobbyGameCreated, LobbyGameCreated_t);
    STEAM_CALLBACK(CallbackListener, OnLobbyInvite, LobbyInvite_t);
    STEAM_CALLBACK(CallbackListener, OnLobbyKicked, LobbyKicked_t);
    STEAM_CALLBACK(CallbackListener, OnLobbyMatchList, LobbyMatchList_t);
};

void CallbackListener::OnFavoritesListChanged(FavoritesListChanged_t *data) {
    if (data == nullptr) {
        return;
    }
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) {
        return;
    }
    lua_rawgeti(L, LUA_REGISTRYINDEX, matchmaking_ref);
    lua_getfield(L, -1, "onFavoritesListChanged");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 7);
        lua_pushnumber(L, data->m_nIP);
        lua_setfield(L, -2, "ip");
        lua_pushnumber(L, data->m_nQueryPort);
        lua_setfield(L, -2, "queryPort");
        lua_pushnumber(L, data->m_nConnPort);
        lua_setfield(L, -2, "connPort");
        lua_pushnumber(L, data->m_nAppID);
        lua_setfield(L, -2, "appID");
        lua_pushnumber(L, data->m_nFlags);
        lua_setfield(L, -2, "flags");
        lua_pushboolean(L, data->m_bAdd != 0);
        lua_setfield(L, -2, "add");
        lua_pushnumber(L, data->m_unAccountId);
        lua_setfield(L, -2, "accountId");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnLobbyChatMsg(LobbyChatMsg_t *data) {
    if (data == nullptr) {
        return;
    }
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) {
        return;
    }
    lua_rawgeti(L, LUA_REGISTRYINDEX, matchmaking_ref);
    lua_getfield(L, -1, "onLobbyChatMsg");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        luasteam::pushuint64(L, data->m_ulSteamIDLobby);
        lua_setfield(L, -2, "lobby");
        luasteam::pushuint64(L, data->m_ulSteamIDUser);
        lua_setfield(L, -2, "user");
        lua_pushstring(L, chat_entry_type[data->m_eChatEntryType]);
        lua_setfield(L, -2, "chatEntryType");
        lua_pushnumber(L, data->m_iChatID);
        lua_setfield(L, -2, "chatID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnLobbyChatUpdate(LobbyChatUpdate_t *data) {
    if (data == nullptr) {
        return;
    }
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) {
        return;
    }
    lua_rawgeti(L, LUA_REGISTRYINDEX, matchmaking_ref);
    lua_getfield(L, -1, "onLobbyChatUpdate");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        luasteam::pushuint64(L, data->m_ulSteamIDLobby);
        lua_setfield(L, -2, "lobby");
        luasteam::pushuint64(L, data->m_ulSteamIDUserChanged);
        lua_setfield(L, -2, "userChanged");
        luasteam::pushuint64(L, data->m_ulSteamIDMakingChange);
        lua_setfield(L, -2, "makingChange");
        lua_pushnumber(L, data->m_rgfChatMemberStateChange);
        lua_setfield(L, -2, "chatMemberStateChange");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnLobbyCreated(LobbyCreated_t *data) {
    if (data == nullptr) {
        return;
    }
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) {
        return;
    }
    lua_rawgeti(L, LUA_REGISTRYINDEX, matchmaking_ref);
    lua_getfield(L, -1, "onLobbyCreated");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushstring(L, steam_result_code[data->m_eResult]);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_ulSteamIDLobby);
        lua_setfield(L, -2, "lobby");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnLobbyDataUpdate(LobbyDataUpdate_t *data) {
    if (data == nullptr) {
        return;
    }
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) {
        return;
    }
    lua_rawgeti(L, LUA_REGISTRYINDEX, matchmaking_ref);
    lua_getfield(L, -1, "onLobbyDataUpdate");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        luasteam::pushuint64(L, data->m_ulSteamIDLobby);
        lua_setfield(L, -2, "lobby");
        luasteam::pushuint64(L, data->m_ulSteamIDMember);
        lua_setfield(L, -2, "member");
        lua_pushboolean(L, data->m_bSuccess != 0);
        lua_setfield(L, -2, "succes");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnLobbyEnter(LobbyEnter_t *data) {
    if (data == nullptr) {
        return;
    }
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) {
        return;
    }
    lua_rawgeti(L, LUA_REGISTRYINDEX, matchmaking_ref);
    lua_getfield(L, -1, "onLobbyEnter");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        luasteam::pushuint64(L, data->m_ulSteamIDLobby);
        lua_setfield(L, -2, "lobby");
        lua_pushnumber(L, data->m_rgfChatPermissions);
        lua_setfield(L, -2, "chatPermissions");
        lua_pushboolean(L, data->m_bLocked != 0);
        lua_setfield(L, -2, "locked");
        lua_pushstring(L, chat_room_enter_response[data->m_EChatRoomEnterResponse]);
        lua_setfield(L, -2, "chatRoomEnterResponse");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnLobbyGameCreated(LobbyGameCreated_t *data) {
    if (data == nullptr) {
        return;
    }
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) {
        return;
    }
    lua_rawgeti(L, LUA_REGISTRYINDEX, matchmaking_ref);
    lua_getfield(L, -1, "onLobbyGameCreated");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        luasteam::pushuint64(L, data->m_ulSteamIDLobby);
        lua_setfield(L, -2, "lobby");
        luasteam::pushuint64(L, data->m_ulSteamIDGameServer);
        lua_setfield(L, -2, "gameServer");
        lua_pushnumber(L, data->m_unIP);
        lua_setfield(L, -2, "ip");
        lua_pushnumber(L, data->m_usPort);
        lua_setfield(L, 2, "port");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnLobbyInvite(LobbyInvite_t *data) {
    if (data == nullptr) {
        return;
    }
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) {
        return;
    }
    lua_rawgeti(L, LUA_REGISTRYINDEX, matchmaking_ref);
    lua_getfield(L, -1, "onLobbyInvite");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        luasteam::pushuint64(L, data->m_ulSteamIDUser);
        lua_setfield(L, -2, "user");
        luasteam::pushuint64(L, data->m_ulSteamIDLobby);
        lua_setfield(L, -2, "lobby");
        luasteam::pushuint64(L, data->m_ulGameID);
        lua_setfield(L, -2, "gameID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnLobbyKicked(LobbyKicked_t *data) {
    if (data == nullptr) {
        return;
    }
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) {
        return;
    }
    lua_rawgeti(L, LUA_REGISTRYINDEX, matchmaking_ref);
    lua_getfield(L, -1, "onLobbyKicked");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        luasteam::pushuint64(L, data->m_ulSteamIDLobby);
        lua_setfield(L, -2, "lobby");
        luasteam::pushuint64(L, data->m_ulSteamIDAdmin);
        lua_setfield(L, -2, "admin");
        lua_pushboolean(L, data->m_bKickedDueToDisconnect != 0);
        lua_setfield(L, -2, "kickedDueToDisconnect");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnLobbyMatchList(LobbyMatchList_t *data) {
    if (data == nullptr) {
        return;
    }
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) {
        return;
    }
    lua_rawgeti(L, LUA_REGISTRYINDEX, matchmaking_ref);
    lua_getfield(L, -1, "onLobbyMatchList");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushnumber(L, data->m_nLobbiesMatching);
        lua_setfield(L, -2, "lobbiesMatching");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

} // namespace

namespace luasteam {

template <> void CallResultListener<LobbyCreated_t>::Result(LobbyCreated_t *data, bool io_fail) {
    lua_State *L = luasteam::global_lua_state;
    // getting stored callback function
    lua_rawgeti(L, LUA_REGISTRYINDEX, callback_ref);
    luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);
    // calling function
    if (io_fail) {
        lua_pushnil(L);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushstring(L, steam_result_code[data->m_eResult]);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_ulSteamIDLobby);
        lua_setfield(L, -2, "lobby");
    }
    lua_pushboolean(L, io_fail);
    lua_call(L, 2, 0);
    delete this;
}

template <> void CallResultListener<LobbyEnter_t>::Result(LobbyEnter_t *data, bool io_fail) {
    lua_State *L = luasteam::global_lua_state;
    // getting stored callback function
    lua_rawgeti(L, LUA_REGISTRYINDEX, callback_ref);
    luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);
    // calling function
    if (io_fail) {
        lua_pushnil(L);
    } else {
        lua_createtable(L, 0, 4);
        luasteam::pushuint64(L, data->m_ulSteamIDLobby);
        lua_setfield(L, -2, "lobby");
        lua_pushnumber(L, data->m_rgfChatPermissions);
        lua_setfield(L, -2, "chatPermissions");
        lua_pushboolean(L, data->m_bLocked != 0);
        lua_setfield(L, -2, "locked");
        lua_pushstring(L, chat_room_enter_response[data->m_EChatRoomEnterResponse]);
        lua_setfield(L, -2, "chatRoomEnterResponse");
    }
    lua_pushboolean(L, io_fail);
    lua_call(L, 2, 0);
    delete this;
}

template <> void CallResultListener<LobbyMatchList_t>::Result(LobbyMatchList_t *data, bool io_fail) {
    lua_State *L = luasteam::global_lua_state;
    // getting stored callback function
    lua_rawgeti(L, LUA_REGISTRYINDEX, callback_ref);
    luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);
    // calling function
    if (io_fail) {
        lua_pushnil(L);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushnumber(L, data->m_nLobbiesMatching);
        lua_setfield(L, -2, "lobbiesMatching");
    }
    lua_pushboolean(L, io_fail);
    lua_call(L, 2, 0);
}

} // namespace luasteam

// int AddFavoriteGame( AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags, uint32 rTime32LastPlayedOnServer );
EXTERN int luasteam_addFavoriteGame(lua_State *L) {
    AppId_t appID = luaL_checkinteger(L, 1);
    uint32 ip = luaL_checkinteger(L, 2);
    uint16 connPort = luaL_checkinteger(L, 3);
    uint16 queryPort = luaL_checkinteger(L, 4);
    uint32 flags = luaL_checkinteger(L, 5);
    uint32 lastPlayedOnServer = luaL_checkinteger(L, 6);
    int result = SteamMatchmaking()->AddFavoriteGame(appID, ip, connPort, queryPort, flags, lastPlayedOnServer);
    lua_pushnumber(L, result);
    return 1;
}

// void AddRequestLobbyListCompatibleMembersFilter( CSteamID steamIDLobby );
EXTERN int luasteam_addRequestLobbyListCompatibleMembersFilter(lua_State *L) {
    CSteamID lobby(luasteam::checkuint64(L, 1));
    SteamMatchmaking()->AddRequestLobbyListCompatibleMembersFilter(lobby);
    return 0;
}

// void AddRequestLobbyListDistanceFilter( ELobbyDistanceFilter eLobbyDistanceFilter );
EXTERN int luasteam_addRequestLobbyListDistanceFilter(lua_State *L) {
    ELobbyDistanceFilter lobbyDistanceFilter = static_cast<ELobbyDistanceFilter>(luaL_checkoption(L, 1, NULL, distance_filter));
    SteamMatchmaking()->AddRequestLobbyListDistanceFilter(lobbyDistanceFilter);
    return 0;
}

// void AddRequestLobbyListFilterSlotsAvailable( int nSlotsAvailable );
EXTERN int luasteam_addRequestLobbyListFilterSlotsAvailable(lua_State *L) {
    int slotsAvailable = luaL_checkinteger(L, 1);
    SteamMatchmaking()->AddRequestLobbyListFilterSlotsAvailable(slotsAvailable);
    return 0;
}

// void AddRequestLobbyListNearValueFilter( const char *pchKeyToMatch, int nValueToBeCloseTo );
EXTERN int luasteam_addRequestLobbyListNearValueFilter(lua_State *L) {
    const char *keyToMatch = luaL_checkstring(L, 1);
    int valueToBeCloseTo = luaL_checkinteger(L, 2);
    SteamMatchmaking()->AddRequestLobbyListNearValueFilter(keyToMatch, valueToBeCloseTo);
    return 0;
}

// void AddRequestLobbyListNumericalFilter( const char *pchKeyToMatch, int nValueToMatch, ELobbyComparison eComparisonType );
EXTERN int luasteam_addRequestLobbyListNumericalFilter(lua_State *L) {
    const char *keyToMatch = luaL_checkstring(L, 1);
    int valueToMatch = luaL_checkinteger(L, 2);
    ELobbyComparison comparisonType = static_cast<ELobbyComparison>(luaL_checkoption(L, 3, NULL, lobby_comparison) - 2);
    SteamMatchmaking()->AddRequestLobbyListNumericalFilter(keyToMatch, valueToMatch, comparisonType);
    return 0;
}

// void AddRequestLobbyListResultCountFilter( int cMaxResults );
EXTERN int luasteam_addRequestLobbyListResultCountFilter(lua_State *L) {
    int maxResults = luaL_checkinteger(L, 1);
    SteamMatchmaking()->AddRequestLobbyListResultCountFilter(maxResults);
    return 0;
}

// void AddRequestLobbyListStringFilter( const char *pchKeyToMatch, const char *pchValueToMatch, ELobbyComparison eComparisonType );
EXTERN int luasteam_addRequestLobbyListStringFilter(lua_State *L) {
    const char *keyToMatch = luaL_checkstring(L, 1);
    const char *valueToMatch = luaL_checkstring(L, 2);
    ELobbyComparison comparisonType = static_cast<ELobbyComparison>(luaL_checkoption(L, 3, NULL, lobby_comparison) - 2);
    SteamMatchmaking()->AddRequestLobbyListStringFilter(keyToMatch, valueToMatch, comparisonType);
    return 0;
}

// SteamAPICall_t CreateLobby( ELobbyType eLobbyType, int cMaxMembers );
EXTERN int luasteam_createLobby(lua_State *L) {
    ELobbyType lobbyType = static_cast<ELobbyType>(luaL_checkoption(L, 1, NULL, lobby_type));
    int maxMembers = luaL_checkinteger(L, 2);
    luaL_checktype(L, 3, LUA_TFUNCTION);
    auto *listener = new CallResultListener<LobbyCreated_t>();
    listener->callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    SteamAPICall_t call = SteamMatchmaking()->CreateLobby(lobbyType, maxMembers);
    listener->call_result.Set(call, listener, &CallResultListener<LobbyCreated_t>::Result);
    return 0;
}

// bool DeleteLobbyData( CSteamID steamIDLobby, const char *pchKey );
EXTERN int luasteam_deleteLobbyData(lua_State *L) {
    CSteamID lobby(luasteam::checkuint64(L, 1));
    const char *key = luaL_checkstring(L, 2);
    bool success = SteamMatchmaking()->DeleteLobbyData(lobby, key);
    lua_pushboolean(L, success);
    return 1;
}

// bool GetFavoriteGame( int iGame, AppId_t *pnAppID, uint32 *pnIP, uint16 *pnConnPort, uint16 *pnQueryPort, uint32 *punFlags, uint32 *pRTime32LastPlayedOnServer );
EXTERN int luasteam_getFavoriteGame(lua_State *L) {
    int game = luaL_checkinteger(L, 1);
    AppId_t appID;
    uint32 ip;
    uint16 connPort;
    uint16 queryPort;
    uint32 flags;
    uint32 lastPlayedOnServer;
    bool success = SteamMatchmaking()->GetFavoriteGame(game, &appID, &ip, &connPort, &queryPort, &flags, &lastPlayedOnServer);
    if (success) {
        lua_createtable(L, 0, 6);
        lua_pushnumber(L, appID);
        lua_setfield(L, -2, "appID");
        lua_pushnumber(L, ip);
        lua_setfield(L, -2, "ip");
        lua_pushnumber(L, connPort);
        lua_setfield(L, -2, "connPort");
        lua_pushnumber(L, queryPort);
        lua_setfield(L, -2, "queryPort");
        lua_pushnumber(L, flags);
        lua_setfield(L, -2, "flags");
        lua_pushnumber(L, lastPlayedOnServer);
        lua_setfield(L, -2, "lastPlayedOnSesrver");
    } else {
        lua_pushnil(L);
    }
    return 1;
}

// int GetFavoriteGameCount();
EXTERN int luasteam_getFavoriteGameCount(lua_State *L) {
    int count = SteamMatchmaking()->GetFavoriteGameCount();
    lua_pushnumber(L, count);
    return 1;
}

// CSteamID GetLobbyByIndex( int iLobby );
EXTERN int luasteam_getLobbyByIndex(lua_State *L) {
    int lobby = luaL_checkinteger(L, 1);
    CSteamID id = SteamMatchmaking()->GetLobbyByIndex(lobby);
    luasteam::pushuint64(L, id.ConvertToUint64());
    return 1;
}

// int GetLobbyChatEntry( CSteamID steamIDLobby, int iChatID, CSteamID *pSteamIDUser, void *pvData, int cubData, EChatEntryType *peChatEntryType );
EXTERN int luasteam_getLobbyChatEntry(lua_State *L) {
    CSteamID lobby(luasteam::checkuint64(L, 1));
    int chatID = luaL_checkinteger(L, 2);
    CSteamID user;
    char data[4 * 1000];
    int bytes = SteamMatchmaking()->GetLobbyChatEntry(lobby, chatID, &user, data, sizeof(data), NULL);
    lua_pushstring(L, data);
    return 1;
}

// const char * GetLobbyData( CSteamID steamIDLobby, const char *pchKey );
EXTERN int luasteam_getLobbyData(lua_State *L) {
    CSteamID lobby(luasteam::checkuint64(L, 1));
    const char *key = luaL_checkstring(L, 2);
    const char *data = SteamMatchmaking()->GetLobbyData(lobby, key);
    lua_pushstring(L, data);
    return 1;
}

// bool GetLobbyDataByIndex( CSteamID steamIDLobby, int iLobbyData, char *pchKey, int cchKeyBufferSize, char *pchValue, int cchValueBufferSize );
EXTERN int luasteam_getLobbyDataByIndex(lua_State *L) {
    CSteamID lobby(luasteam::checkuint64(L, 1));
    int lobbyData = luaL_checkinteger(L, 2);
    char key[k_nMaxLobbyKeyLength];
    char value[k_cubChatMetadataMax];
    bool success = SteamMatchmaking()->GetLobbyDataByIndex(lobby, lobbyData, key, sizeof(key), value, sizeof(value));
    if (success) {
        lua_createtable(L, 0, 2);
        lua_pushstring(L, key);
        lua_setfield(L, -2, "key");
        lua_pushstring(L, value);
        lua_setfield(L, -2, "value");
    } else {
        lua_pushnil(L);
    }
    return 1;
}

// int GetLobbyDataCount( CSteamID steamIDLobby );
EXTERN int luasteam_getLobbyDataCount(lua_State *L) {
    CSteamID lobby(luasteam::checkuint64(L, 1));
    int count = SteamMatchmaking()->GetLobbyDataCount(lobby);
    lua_pushnumber(L, count);
    return 1;
}

// bool GetLobbyGameServer( CSteamID steamIDLobby, uint32 *punGameServerIP, uint16 *punGameServerPort, CSteamID *psteamIDGameServer );
EXTERN int luasteam_getLobbyGameServer(lua_State *L) {
    CSteamID lobby(luasteam::checkuint64(L, 1));
    uint32 gameServerIP;
    uint16 gameServerPort;
    CSteamID gameServer;
    bool success = SteamMatchmaking()->GetLobbyGameServer(lobby, &gameServerIP, &gameServerPort, &gameServer);
    if (success) {
        lua_createtable(L, 0, 3);
        lua_pushnumber(L, gameServerIP);
        lua_setfield(L, -2, "gameServerIP");
        lua_pushnumber(L, gameServerPort);
        lua_setfield(L, -2, "gameServerPort");
        luasteam::pushuint64(L, gameServer.ConvertToUint64());
        lua_setfield(L, -2, "gameServer");
    } else {
        lua_pushnil(L);
    }
    return 1;
}

// CSteamID GetLobbyMemberByIndex( CSteamID steamIDLobby, int iMember );
EXTERN int luasteam_getLobbyMemberByIndex(lua_State *L) {
    CSteamID lobby(luasteam::checkuint64(L, 1));
    int index = luaL_checkinteger(L, 2);
    CSteamID member = SteamMatchmaking()->GetLobbyMemberByIndex(lobby, index);
    luasteam::pushuint64(L, member.ConvertToUint64());
    return 1;
}

// const char * GetLobbyMemberData( CSteamID steamIDLobby, CSteamID steamIDUser, const char *pchKey );
EXTERN int luasteam_getLobbyMemberData(lua_State *L) {
    CSteamID lobby(luasteam::checkuint64(L, 1));
    CSteamID user(luasteam::checkuint64(L, 2));
    const char *key = luaL_checkstring(L, 3);
    const char *data = SteamMatchmaking()->GetLobbyMemberData(lobby, user, key);
    lua_pushstring(L, data);
    return 1;
}

// int GetLobbyMemberLimit( CSteamID steamIDLobby );
EXTERN int luasteam_getLobbyMemberLimit(lua_State *L) {
    CSteamID lobby(luasteam::checkuint64(L, 1));
    int limit = SteamMatchmaking()->GetLobbyMemberLimit(lobby);
    lua_pushnumber(L, limit);
    return 1;
}

// CSteamID GetLobbyOwner( CSteamID steamIDLobby );
EXTERN int luasteam_getLobbyOwner(lua_State *L) {
    CSteamID lobby(luasteam::checkuint64(L, 1));
    CSteamID owner = SteamMatchmaking()->GetLobbyOwner(lobby);
    luasteam::pushuint64(L, owner.ConvertToUint64());
    return 1;
}

// int GetNumLobbyMembers( CSteamID steamIDLobby );
EXTERN int luasteam_getNumLobbyMembers(lua_State *L) {
    CSteamID lobby(luasteam::checkuint64(L, 1));
    int members = SteamMatchmaking()->GetNumLobbyMembers(lobby);
    lua_pushnumber(L, members);
    return 1;
}

// bool InviteUserToLobby( CSteamID steamIDLobby, CSteamID steamIDInvitee );
EXTERN int luasteam_inviteUserToLobby(lua_State *L) {
    CSteamID lobby(luasteam::checkuint64(L, 1));
    CSteamID invitee(luasteam::checkuint64(L, 2));
    bool success = SteamMatchmaking()->InviteUserToLobby(lobby, invitee);
    lua_pushboolean(L, success);
    return 1;
}

// SteamAPICall_t JoinLobby( CSteamID steamIDLobby );
EXTERN int luasteam_joinLobby(lua_State *L) {
    CSteamID lobby(luasteam::checkuint64(L, 1));
    luaL_checktype(L, 2, LUA_TFUNCTION);
    auto *listener = new CallResultListener<LobbyEnter_t>();
    listener->callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    SteamAPICall_t call = SteamMatchmaking()->JoinLobby(lobby);
    listener->call_result.Set(call, listener, &CallResultListener<LobbyEnter_t>::Result);
    return 0;
}

// void LeaveLobby( CSteamID steamIDLobby );
EXTERN int luasteam_leaveLobby(lua_State *L) {
    CSteamID lobby(luasteam::checkuint64(L, 1));
    SteamMatchmaking()->LeaveLobby(lobby);
    return 0;
}

// bool RemoveFavoriteGame( AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags );
EXTERN int luasteam_removeFavoriteGame(lua_State *L) {
    AppId_t appID = static_cast<AppId_t>(luaL_checkinteger(L, 1));
    uint32 ip = luaL_checkinteger(L, 2);
    uint16 connPort = luaL_checkinteger(L, 3);
    uint16 queryPort = luaL_checkinteger(L, 4);
    uint32 flags = luaL_checkinteger(L, 5);
    bool success = SteamMatchmaking()->RemoveFavoriteGame(appID, ip, connPort, queryPort, flags);
    lua_pushboolean(L, success);
    return 1;
}

// bool RequestLobbyData( CSteamID steamIDLobby );
EXTERN int luasteam_requestLobbyData(lua_State *L) {
    CSteamID lobby(luasteam::checkuint64(L, 1));
    bool success = SteamMatchmaking()->RequestLobbyData(lobby);
    lua_pushboolean(L, success);
    return 1;
}

// SteamAPICall_t RequestLobbyList();
EXTERN int luasteam_requestLobbyList(lua_State *L) {
    luaL_checktype(L, 1, LUA_TFUNCTION);
    auto *listener = new CallResultListener<LobbyMatchList_t>();
    listener->callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    SteamAPICall_t call = SteamMatchmaking()->RequestLobbyList();
    listener->call_result.Set(call, listener, &CallResultListener<LobbyMatchList_t>::Result);
    return 0;
}

// bool SendLobbyChatMsg( CSteamID steamIDLobby, const void *pvMsgBody, int cubMsgBody );
EXTERN int luasteam_sendLobbyChatMsg(lua_State *L) {
    CSteamID lobby(luasteam::checkuint64(L, 1));
    const char *msgBody = luaL_checkstring(L, 2);
    int msgBodyLength = strlen(msgBody);
    bool success = SteamMatchmaking()->SendLobbyChatMsg(lobby, msgBody, msgBodyLength);
    lua_pushboolean(L, success);
    return 1;
}

// bool SetLinkedLobby( CSteamID steamIDLobby, CSteamID steamIDLobbyDependent );
EXTERN int luasteam_setLinkedLobby(lua_State *L) {
    CSteamID lobby(luasteam::checkuint64(L, 1));
    CSteamID lobbyDependent(luasteam::checkuint64(L, 2));
    bool success = SteamMatchmaking()->SetLinkedLobby(lobby, lobbyDependent);
    lua_pushboolean(L, success);
    return 1;
}

// bool SetLobbyData( CSteamID steamIDLobby, const char *pchKey, const char *pchValue );
EXTERN int luasteam_setLobbyData(lua_State *L) {
    CSteamID lobby(luasteam::checkuint64(L, 1));
    const char *key = luaL_checkstring(L, 2);
    const char *value = luaL_checkstring(L, 3);
    bool success = SteamMatchmaking()->SetLobbyData(lobby, key, value);
    lua_pushboolean(L, success);
    return 1;
}

// void SetLobbyGameServer( CSteamID steamIDLobby, uint32 unGameServerIP, uint16 unGameServerPort, CSteamID steamIDGameServer );
EXTERN int luasteam_setLobbyGameServer(lua_State *L) {
    CSteamID lobby(luasteam::checkuint64(L, 1));
    uint32 gameServerIP = luaL_checkinteger(L, 2);
    uint16 gameServerPort = luaL_checkinteger(L, 3);
    CSteamID gameServer(luasteam::checkuint64(L, 4));
    SteamMatchmaking()->SetLobbyGameServer(lobby, gameServerIP, gameServerPort, gameServer);
    return 0;
}

// bool SetLobbyJoinable( CSteamID steamIDLobby, bool bLobbyJoinable );
EXTERN int luasteam_setLobbyJoinable(lua_State *L) {
    CSteamID lobby(luasteam::checkuint64(L, 1));
    bool joinable = lua_toboolean(L, 2);
    bool success = SteamMatchmaking()->SetLobbyJoinable(lobby, joinable);
    lua_pushboolean(L, success);
    return 1;
}

// void SetLobbyMemberData( CSteamID steamIDLobby, const char *pchKey, const char *pchValue );
EXTERN int luasteam_setLobbyMemberData(lua_State *L) {
    CSteamID lobby(luasteam::checkuint64(L, 1));
    const char *key = luaL_checkstring(L, 2);
    const char *value = luaL_checkstring(L, 3);
    SteamMatchmaking()->SetLobbyMemberData(lobby, key, value);
    return 0;
}

// bool SetLobbyMemberLimit( CSteamID steamIDLobby, int cMaxMembers );
EXTERN int luasteam_setLobbyMemberLimit(lua_State *L) {
    CSteamID lobby(luasteam::checkuint64(L, 1));
    int maxMembers = luaL_checkinteger(L, 2);
    bool success = SteamMatchmaking()->SetLobbyMemberLimit(lobby, maxMembers);
    lua_pushboolean(L, success);
    return 1;
}

// bool SetLobbyOwner( CSteamID steamIDLobby, CSteamID steamIDNewOwner );
EXTERN int luasteam_setLobbyOwner(lua_State *L) {
    CSteamID lobby(luasteam::checkuint64(L, 1));
    CSteamID newOwner(luasteam::checkuint64(L, 2));
    bool success = SteamMatchmaking()->SetLobbyOwner(lobby, newOwner);
    lua_pushboolean(L, success);
    return 1;
}

// bool SetLobbyType( CSteamID steamIDLobby, ELobbyType eLobbyType );
EXTERN int luasteam_setLobbyType(lua_State *L) {
    CSteamID lobby(luasteam::checkuint64(L, 1));
    ELobbyType lobbyType = static_cast<ELobbyType>(luaL_checkoption(L, 2, NULL, lobby_type));
    bool success = SteamMatchmaking()->SetLobbyType(lobby, lobbyType);
    lua_pushboolean(L, success);
    return 1;
}

namespace luasteam {

void add_matchmaking(lua_State *L) {
    lua_createtable(L, 0, 13);

    add_func(L, "addFavoriteGame", luasteam_addFavoriteGame);
    add_func(L, "addRequestLobbyListCompatibleMembersFilter", luasteam_addRequestLobbyListCompatibleMembersFilter);
    add_func(L, "addRequestLobbyListDistanceFilter", luasteam_addRequestLobbyListDistanceFilter);
    add_func(L, "addRequestLobbyListFilterSlotsAvailable", luasteam_addRequestLobbyListFilterSlotsAvailable);
    add_func(L, "addRequestLobbyListNearValueFilter", luasteam_addRequestLobbyListNearValueFilter);
    add_func(L, "addRequestLobbyListNumericalFilter", luasteam_addRequestLobbyListNumericalFilter);
    add_func(L, "addRequestLobbyListResultCountFilter", luasteam_addRequestLobbyListResultCountFilter);
    add_func(L, "addRequestLobbyListStringFilter", luasteam_addRequestLobbyListStringFilter);
    add_func(L, "createLobby", luasteam_createLobby);
    add_func(L, "deleteLobbyData", luasteam_deleteLobbyData);
    add_func(L, "getFavoriteGame", luasteam_getFavoriteGame);
    add_func(L, "getFavoriteGameCount", luasteam_getFavoriteGameCount);
    add_func(L, "getLobbyByIndex", luasteam_getLobbyByIndex);
    add_func(L, "getLobbyChatEntry", luasteam_getLobbyChatEntry);
    add_func(L, "getLobbyData", luasteam_getLobbyData);
    add_func(L, "getLobbyDataByIndex", luasteam_getLobbyDataByIndex);
    add_func(L, "getLobbyDataCount", luasteam_getLobbyDataCount);
    add_func(L, "getLobbyGameServer", luasteam_getLobbyGameServer);
    add_func(L, "getLobbyMemberByIndex", luasteam_getLobbyMemberByIndex);
    add_func(L, "getLobbyMemberData", luasteam_getLobbyMemberData);
    add_func(L, "getLobbyMemberLimit", luasteam_getLobbyMemberLimit);
    add_func(L, "getLobbyOwner", luasteam_getLobbyOwner);
    add_func(L, "getNumLobbyMembers", luasteam_getNumLobbyMembers);
    add_func(L, "inviteUserToLobby", luasteam_inviteUserToLobby);
    add_func(L, "joinLobby", luasteam_joinLobby);
    add_func(L, "leaveLobby", luasteam_leaveLobby);
    add_func(L, "removeFavoriteGame", luasteam_removeFavoriteGame);
    add_func(L, "requestLobbyData", luasteam_requestLobbyData);
    add_func(L, "requestLobbyList", luasteam_requestLobbyList);
    add_func(L, "sendLobbyChatMsg", luasteam_sendLobbyChatMsg);
    add_func(L, "setLinkedLobby", luasteam_setLinkedLobby);
    add_func(L, "setLobbyData", luasteam_setLobbyData);
    add_func(L, "setLobbyGameServer", luasteam_setLobbyGameServer);
    add_func(L, "setLobbyJoinable", luasteam_setLobbyJoinable);
    add_func(L, "setLobbyMemberData", luasteam_setLobbyMemberData);
    add_func(L, "setLobbyMemberLimit", luasteam_setLobbyMemberLimit);
    add_func(L, "setLobbyOwner", luasteam_setLobbyOwner);
    add_func(L, "setLobbyType", luasteam_setLobbyType);

    lua_pushvalue(L, -1);
    matchmaking_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "matchmaking");
}

void init_matchmaking(lua_State *L) { callback_listener = new CallbackListener(); }

void shutdown_matchmaking(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, matchmaking_ref);
    matchmaking_ref = LUA_NOREF;
    delete callback_listener;
    callback_listener = nullptr;
}

} // namespace luasteam
