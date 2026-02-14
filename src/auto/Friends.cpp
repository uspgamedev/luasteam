#include "auto.hpp"

namespace luasteam {

int Friends_ref = LUA_NOREF;

namespace {

class CallbackListener {
  private:
    STEAM_CALLBACK(CallbackListener, OnPersonaStateChange, PersonaStateChange_t);
    STEAM_CALLBACK(CallbackListener, OnGameOverlayActivated, GameOverlayActivated_t);
    STEAM_CALLBACK(CallbackListener, OnGameServerChangeRequested, GameServerChangeRequested_t);
    STEAM_CALLBACK(CallbackListener, OnGameLobbyJoinRequested, GameLobbyJoinRequested_t);
    STEAM_CALLBACK(CallbackListener, OnAvatarImageLoaded, AvatarImageLoaded_t);
    STEAM_CALLBACK(CallbackListener, OnClanOfficerListResponse, ClanOfficerListResponse_t);
    STEAM_CALLBACK(CallbackListener, OnFriendRichPresenceUpdate, FriendRichPresenceUpdate_t);
    STEAM_CALLBACK(CallbackListener, OnGameRichPresenceJoinRequested, GameRichPresenceJoinRequested_t);
    STEAM_CALLBACK(CallbackListener, OnGameConnectedClanChatMsg, GameConnectedClanChatMsg_t);
    STEAM_CALLBACK(CallbackListener, OnGameConnectedChatJoin, GameConnectedChatJoin_t);
    STEAM_CALLBACK(CallbackListener, OnGameConnectedChatLeave, GameConnectedChatLeave_t);
    STEAM_CALLBACK(CallbackListener, OnDownloadClanActivityCountsResult, DownloadClanActivityCountsResult_t);
    STEAM_CALLBACK(CallbackListener, OnJoinClanChatRoomCompletionResult, JoinClanChatRoomCompletionResult_t);
    STEAM_CALLBACK(CallbackListener, OnGameConnectedFriendChatMsg, GameConnectedFriendChatMsg_t);
    STEAM_CALLBACK(CallbackListener, OnFriendsGetFollowerCount, FriendsGetFollowerCount_t);
    STEAM_CALLBACK(CallbackListener, OnFriendsIsFollowing, FriendsIsFollowing_t);
    STEAM_CALLBACK(CallbackListener, OnFriendsEnumerateFollowingList, FriendsEnumerateFollowingList_t);
    STEAM_CALLBACK(CallbackListener, OnUnreadChatMessagesChanged, UnreadChatMessagesChanged_t);
    STEAM_CALLBACK(CallbackListener, OnOverlayBrowserProtocolNavigation, OverlayBrowserProtocolNavigation_t);
    STEAM_CALLBACK(CallbackListener, OnEquippedProfileItemsChanged, EquippedProfileItemsChanged_t);
    STEAM_CALLBACK(CallbackListener, OnEquippedProfileItems, EquippedProfileItems_t);
};

void CallbackListener::OnPersonaStateChange(PersonaStateChange_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
    lua_getfield(L, -1, "OnPersonaStateChange");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        luasteam::pushuint64(L, data->m_ulSteamID);
        lua_setfield(L, -2, "m_ulSteamID");
        lua_pushinteger(L, data->m_nChangeFlags);
        lua_setfield(L, -2, "m_nChangeFlags");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGameOverlayActivated(GameOverlayActivated_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
    lua_getfield(L, -1, "OnGameOverlayActivated");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        lua_pushinteger(L, data->m_bActive);
        lua_setfield(L, -2, "m_bActive");
        lua_pushboolean(L, data->m_bUserInitiated);
        lua_setfield(L, -2, "m_bUserInitiated");
        lua_pushinteger(L, data->m_nAppID);
        lua_setfield(L, -2, "m_nAppID");
        lua_pushinteger(L, data->m_dwOverlayPID);
        lua_setfield(L, -2, "m_dwOverlayPID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGameServerChangeRequested(GameServerChangeRequested_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
    lua_getfield(L, -1, "OnGameServerChangeRequested");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushstring(L, reinterpret_cast<const char*>(data->m_rgchServer));
        lua_setfield(L, -2, "m_rgchServer");
        lua_pushstring(L, reinterpret_cast<const char*>(data->m_rgchPassword));
        lua_setfield(L, -2, "m_rgchPassword");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGameLobbyJoinRequested(GameLobbyJoinRequested_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
    lua_getfield(L, -1, "OnGameLobbyJoinRequested");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        luasteam::pushuint64(L, data->m_steamIDLobby.ConvertToUint64());
        lua_setfield(L, -2, "m_steamIDLobby");
        luasteam::pushuint64(L, data->m_steamIDFriend.ConvertToUint64());
        lua_setfield(L, -2, "m_steamIDFriend");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnAvatarImageLoaded(AvatarImageLoaded_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
    lua_getfield(L, -1, "OnAvatarImageLoaded");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        luasteam::pushuint64(L, data->m_steamID.ConvertToUint64());
        lua_setfield(L, -2, "m_steamID");
        lua_pushinteger(L, data->m_iImage);
        lua_setfield(L, -2, "m_iImage");
        lua_pushinteger(L, data->m_iWide);
        lua_setfield(L, -2, "m_iWide");
        lua_pushinteger(L, data->m_iTall);
        lua_setfield(L, -2, "m_iTall");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnClanOfficerListResponse(ClanOfficerListResponse_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
    lua_getfield(L, -1, "OnClanOfficerListResponse");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        luasteam::pushuint64(L, data->m_steamIDClan.ConvertToUint64());
        lua_setfield(L, -2, "m_steamIDClan");
        lua_pushinteger(L, data->m_cOfficers);
        lua_setfield(L, -2, "m_cOfficers");
        lua_pushinteger(L, data->m_bSuccess);
        lua_setfield(L, -2, "m_bSuccess");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnFriendRichPresenceUpdate(FriendRichPresenceUpdate_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
    lua_getfield(L, -1, "OnFriendRichPresenceUpdate");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        luasteam::pushuint64(L, data->m_steamIDFriend.ConvertToUint64());
        lua_setfield(L, -2, "m_steamIDFriend");
        lua_pushinteger(L, data->m_nAppID);
        lua_setfield(L, -2, "m_nAppID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGameRichPresenceJoinRequested(GameRichPresenceJoinRequested_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
    lua_getfield(L, -1, "OnGameRichPresenceJoinRequested");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        luasteam::pushuint64(L, data->m_steamIDFriend.ConvertToUint64());
        lua_setfield(L, -2, "m_steamIDFriend");
        lua_pushstring(L, reinterpret_cast<const char*>(data->m_rgchConnect));
        lua_setfield(L, -2, "m_rgchConnect");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGameConnectedClanChatMsg(GameConnectedClanChatMsg_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
    lua_getfield(L, -1, "OnGameConnectedClanChatMsg");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        luasteam::pushuint64(L, data->m_steamIDClanChat.ConvertToUint64());
        lua_setfield(L, -2, "m_steamIDClanChat");
        luasteam::pushuint64(L, data->m_steamIDUser.ConvertToUint64());
        lua_setfield(L, -2, "m_steamIDUser");
        lua_pushinteger(L, data->m_iMessageID);
        lua_setfield(L, -2, "m_iMessageID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGameConnectedChatJoin(GameConnectedChatJoin_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
    lua_getfield(L, -1, "OnGameConnectedChatJoin");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        luasteam::pushuint64(L, data->m_steamIDClanChat.ConvertToUint64());
        lua_setfield(L, -2, "m_steamIDClanChat");
        luasteam::pushuint64(L, data->m_steamIDUser.ConvertToUint64());
        lua_setfield(L, -2, "m_steamIDUser");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGameConnectedChatLeave(GameConnectedChatLeave_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
    lua_getfield(L, -1, "OnGameConnectedChatLeave");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        luasteam::pushuint64(L, data->m_steamIDClanChat.ConvertToUint64());
        lua_setfield(L, -2, "m_steamIDClanChat");
        luasteam::pushuint64(L, data->m_steamIDUser.ConvertToUint64());
        lua_setfield(L, -2, "m_steamIDUser");
        lua_pushboolean(L, data->m_bKicked);
        lua_setfield(L, -2, "m_bKicked");
        lua_pushboolean(L, data->m_bDropped);
        lua_setfield(L, -2, "m_bDropped");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnDownloadClanActivityCountsResult(DownloadClanActivityCountsResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
    lua_getfield(L, -1, "OnDownloadClanActivityCountsResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushboolean(L, data->m_bSuccess);
        lua_setfield(L, -2, "m_bSuccess");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnJoinClanChatRoomCompletionResult(JoinClanChatRoomCompletionResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
    lua_getfield(L, -1, "OnJoinClanChatRoomCompletionResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        luasteam::pushuint64(L, data->m_steamIDClanChat.ConvertToUint64());
        lua_setfield(L, -2, "m_steamIDClanChat");
        lua_pushinteger(L, data->m_eChatRoomEnterResponse);
        lua_setfield(L, -2, "m_eChatRoomEnterResponse");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGameConnectedFriendChatMsg(GameConnectedFriendChatMsg_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
    lua_getfield(L, -1, "OnGameConnectedFriendChatMsg");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        luasteam::pushuint64(L, data->m_steamIDUser.ConvertToUint64());
        lua_setfield(L, -2, "m_steamIDUser");
        lua_pushinteger(L, data->m_iMessageID);
        lua_setfield(L, -2, "m_iMessageID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnFriendsGetFollowerCount(FriendsGetFollowerCount_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
    lua_getfield(L, -1, "OnFriendsGetFollowerCount");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "m_eResult");
        luasteam::pushuint64(L, data->m_steamID.ConvertToUint64());
        lua_setfield(L, -2, "m_steamID");
        lua_pushinteger(L, data->m_nCount);
        lua_setfield(L, -2, "m_nCount");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnFriendsIsFollowing(FriendsIsFollowing_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
    lua_getfield(L, -1, "OnFriendsIsFollowing");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "m_eResult");
        luasteam::pushuint64(L, data->m_steamID.ConvertToUint64());
        lua_setfield(L, -2, "m_steamID");
        lua_pushboolean(L, data->m_bIsFollowing);
        lua_setfield(L, -2, "m_bIsFollowing");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnFriendsEnumerateFollowingList(FriendsEnumerateFollowingList_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
    lua_getfield(L, -1, "OnFriendsEnumerateFollowingList");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "m_eResult");
            lua_createtable(L, 50, 0);
    for(int i=0;i<50;i++){
    luasteam::pushuint64(L, data->m_rgSteamID[i].ConvertToUint64());
    lua_rawseti(L, -2, i+1);
    }

        lua_setfield(L, -2, "m_rgSteamID");
        lua_pushinteger(L, data->m_nResultsReturned);
        lua_setfield(L, -2, "m_nResultsReturned");
        lua_pushinteger(L, data->m_nTotalResultCount);
        lua_setfield(L, -2, "m_nTotalResultCount");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnUnreadChatMessagesChanged(UnreadChatMessagesChanged_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
    lua_getfield(L, -1, "OnUnreadChatMessagesChanged");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 0);
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnOverlayBrowserProtocolNavigation(OverlayBrowserProtocolNavigation_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
    lua_getfield(L, -1, "OnOverlayBrowserProtocolNavigation");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushstring(L, reinterpret_cast<const char*>(data->rgchURI));
        lua_setfield(L, -2, "rgchURI");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnEquippedProfileItemsChanged(EquippedProfileItemsChanged_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
    lua_getfield(L, -1, "OnEquippedProfileItemsChanged");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        luasteam::pushuint64(L, data->m_steamID.ConvertToUint64());
        lua_setfield(L, -2, "m_steamID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnEquippedProfileItems(EquippedProfileItems_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
    lua_getfield(L, -1, "OnEquippedProfileItems");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 8);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "m_eResult");
        luasteam::pushuint64(L, data->m_steamID.ConvertToUint64());
        lua_setfield(L, -2, "m_steamID");
        lua_pushboolean(L, data->m_bHasAnimatedAvatar);
        lua_setfield(L, -2, "m_bHasAnimatedAvatar");
        lua_pushboolean(L, data->m_bHasAvatarFrame);
        lua_setfield(L, -2, "m_bHasAvatarFrame");
        lua_pushboolean(L, data->m_bHasProfileModifier);
        lua_setfield(L, -2, "m_bHasProfileModifier");
        lua_pushboolean(L, data->m_bHasProfileBackground);
        lua_setfield(L, -2, "m_bHasProfileBackground");
        lua_pushboolean(L, data->m_bHasMiniProfileBackground);
        lua_setfield(L, -2, "m_bHasMiniProfileBackground");
        lua_pushboolean(L, data->m_bFromCache);
        lua_setfield(L, -2, "m_bFromCache");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

CallbackListener *Friends_listener = nullptr;

} // namespace

void init_Friends_auto(lua_State *L) { Friends_listener = new CallbackListener(); }

void shutdown_Friends_auto(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, Friends_ref);
    Friends_ref = LUA_NOREF;
    delete Friends_listener; Friends_listener = nullptr;
}


// const char * GetPersonaName();
EXTERN int luasteam_Friends_GetPersonaName(lua_State *L) {
    const char * __ret = SteamFriends()->GetPersonaName();
    lua_pushstring(L, reinterpret_cast<const char*>(__ret));
    return 1;
}

// EPersonaState GetPersonaState();
EXTERN int luasteam_Friends_GetPersonaState(lua_State *L) {
    EPersonaState __ret = SteamFriends()->GetPersonaState();
    lua_pushinteger(L, __ret);
    return 1;
}

// int GetFriendCount(int iFriendFlags);
EXTERN int luasteam_Friends_GetFriendCount(lua_State *L) {
    int iFriendFlags = static_cast<int>(luaL_checkint(L, 1));
    int __ret = SteamFriends()->GetFriendCount(iFriendFlags);
    lua_pushinteger(L, __ret);
    return 1;
}

// CSteamID GetFriendByIndex(int iFriend, int iFriendFlags);
EXTERN int luasteam_Friends_GetFriendByIndex(lua_State *L) {
    int iFriend = static_cast<int>(luaL_checkint(L, 1));
    int iFriendFlags = static_cast<int>(luaL_checkint(L, 2));
    CSteamID __ret = SteamFriends()->GetFriendByIndex(iFriend, iFriendFlags);
    luasteam::pushuint64(L, __ret.ConvertToUint64());
    return 1;
}

// EFriendRelationship GetFriendRelationship(CSteamID steamIDFriend);
EXTERN int luasteam_Friends_GetFriendRelationship(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    EFriendRelationship __ret = SteamFriends()->GetFriendRelationship(steamIDFriend);
    lua_pushinteger(L, __ret);
    return 1;
}

// EPersonaState GetFriendPersonaState(CSteamID steamIDFriend);
EXTERN int luasteam_Friends_GetFriendPersonaState(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    EPersonaState __ret = SteamFriends()->GetFriendPersonaState(steamIDFriend);
    lua_pushinteger(L, __ret);
    return 1;
}

// const char * GetFriendPersonaName(CSteamID steamIDFriend);
EXTERN int luasteam_Friends_GetFriendPersonaName(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    const char * __ret = SteamFriends()->GetFriendPersonaName(steamIDFriend);
    lua_pushstring(L, reinterpret_cast<const char*>(__ret));
    return 1;
}

// bool GetFriendGamePlayed(CSteamID steamIDFriend, FriendGameInfo_t * pFriendGameInfo);
EXTERN int luasteam_Friends_GetFriendGamePlayed(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    FriendGameInfo_t pFriendGameInfo;    bool __ret = SteamFriends()->GetFriendGamePlayed(steamIDFriend, &pFriendGameInfo);
    lua_pushboolean(L, __ret);
    push_FriendGameInfo_t(L, pFriendGameInfo);
    return 2;
}

// const char * GetFriendPersonaNameHistory(CSteamID steamIDFriend, int iPersonaName);
EXTERN int luasteam_Friends_GetFriendPersonaNameHistory(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    int iPersonaName = static_cast<int>(luaL_checkint(L, 2));
    const char * __ret = SteamFriends()->GetFriendPersonaNameHistory(steamIDFriend, iPersonaName);
    lua_pushstring(L, reinterpret_cast<const char*>(__ret));
    return 1;
}

// int GetFriendSteamLevel(CSteamID steamIDFriend);
EXTERN int luasteam_Friends_GetFriendSteamLevel(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    int __ret = SteamFriends()->GetFriendSteamLevel(steamIDFriend);
    lua_pushinteger(L, __ret);
    return 1;
}

// const char * GetPlayerNickname(CSteamID steamIDPlayer);
EXTERN int luasteam_Friends_GetPlayerNickname(lua_State *L) {
    CSteamID steamIDPlayer(luasteam::checkuint64(L, 1));
    const char * __ret = SteamFriends()->GetPlayerNickname(steamIDPlayer);
    lua_pushstring(L, reinterpret_cast<const char*>(__ret));
    return 1;
}

// int GetFriendsGroupCount();
EXTERN int luasteam_Friends_GetFriendsGroupCount(lua_State *L) {
    int __ret = SteamFriends()->GetFriendsGroupCount();
    lua_pushinteger(L, __ret);
    return 1;
}

// FriendsGroupID_t GetFriendsGroupIDByIndex(int iFG);
EXTERN int luasteam_Friends_GetFriendsGroupIDByIndex(lua_State *L) {
    int iFG = static_cast<int>(luaL_checkint(L, 1));
    FriendsGroupID_t __ret = SteamFriends()->GetFriendsGroupIDByIndex(iFG);
    lua_pushinteger(L, __ret);
    return 1;
}

// const char * GetFriendsGroupName(FriendsGroupID_t friendsGroupID);
EXTERN int luasteam_Friends_GetFriendsGroupName(lua_State *L) {
    FriendsGroupID_t friendsGroupID = static_cast<FriendsGroupID_t>(luaL_checkint(L, 1));
    const char * __ret = SteamFriends()->GetFriendsGroupName(friendsGroupID);
    lua_pushstring(L, reinterpret_cast<const char*>(__ret));
    return 1;
}

// int GetFriendsGroupMembersCount(FriendsGroupID_t friendsGroupID);
EXTERN int luasteam_Friends_GetFriendsGroupMembersCount(lua_State *L) {
    FriendsGroupID_t friendsGroupID = static_cast<FriendsGroupID_t>(luaL_checkint(L, 1));
    int __ret = SteamFriends()->GetFriendsGroupMembersCount(friendsGroupID);
    lua_pushinteger(L, __ret);
    return 1;
}

// void GetFriendsGroupMembersList(FriendsGroupID_t friendsGroupID, CSteamID * pOutSteamIDMembers, int nMembersCount);
EXTERN int luasteam_Friends_GetFriendsGroupMembersList(lua_State *L) {
    FriendsGroupID_t friendsGroupID = static_cast<FriendsGroupID_t>(luaL_checkint(L, 1));
    int nMembersCount = luaL_checkint(L, 2);
    std::vector<CSteamID> pOutSteamIDMembers(nMembersCount);
    SteamFriends()->GetFriendsGroupMembersList(friendsGroupID, pOutSteamIDMembers.data(), nMembersCount);
    lua_createtable(L, nMembersCount, 0);
    for(int i=0;i<nMembersCount;i++){
    luasteam::pushuint64(L, pOutSteamIDMembers[i].ConvertToUint64());
    lua_rawseti(L, -2, i+1);
    }
    return 0;
}

// bool HasFriend(CSteamID steamIDFriend, int iFriendFlags);
EXTERN int luasteam_Friends_HasFriend(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    int iFriendFlags = static_cast<int>(luaL_checkint(L, 2));
    bool __ret = SteamFriends()->HasFriend(steamIDFriend, iFriendFlags);
    lua_pushboolean(L, __ret);
    return 1;
}

// int GetClanCount();
EXTERN int luasteam_Friends_GetClanCount(lua_State *L) {
    int __ret = SteamFriends()->GetClanCount();
    lua_pushinteger(L, __ret);
    return 1;
}

// CSteamID GetClanByIndex(int iClan);
EXTERN int luasteam_Friends_GetClanByIndex(lua_State *L) {
    int iClan = static_cast<int>(luaL_checkint(L, 1));
    CSteamID __ret = SteamFriends()->GetClanByIndex(iClan);
    luasteam::pushuint64(L, __ret.ConvertToUint64());
    return 1;
}

// const char * GetClanName(CSteamID steamIDClan);
EXTERN int luasteam_Friends_GetClanName(lua_State *L) {
    CSteamID steamIDClan(luasteam::checkuint64(L, 1));
    const char * __ret = SteamFriends()->GetClanName(steamIDClan);
    lua_pushstring(L, reinterpret_cast<const char*>(__ret));
    return 1;
}

// const char * GetClanTag(CSteamID steamIDClan);
EXTERN int luasteam_Friends_GetClanTag(lua_State *L) {
    CSteamID steamIDClan(luasteam::checkuint64(L, 1));
    const char * __ret = SteamFriends()->GetClanTag(steamIDClan);
    lua_pushstring(L, reinterpret_cast<const char*>(__ret));
    return 1;
}

// bool GetClanActivityCounts(CSteamID steamIDClan, int * pnOnline, int * pnInGame, int * pnChatting);
EXTERN int luasteam_Friends_GetClanActivityCounts(lua_State *L) {
    CSteamID steamIDClan(luasteam::checkuint64(L, 1));
    int pnOnline;    int pnInGame;    int pnChatting;    bool __ret = SteamFriends()->GetClanActivityCounts(steamIDClan, &pnOnline, &pnInGame, &pnChatting);
    lua_pushboolean(L, __ret);
    lua_pushinteger(L, pnOnline);
    lua_pushinteger(L, pnInGame);
    lua_pushinteger(L, pnChatting);
    return 4;
}

// SteamAPICall_t DownloadClanActivityCounts(CSteamID * psteamIDClans, int cClansToRequest);
EXTERN int luasteam_Friends_DownloadClanActivityCounts(lua_State *L) {
    int cClansToRequest = luaL_checkint(L, 1);
    std::vector<CSteamID> psteamIDClans(cClansToRequest);
    SteamAPICall_t __ret = SteamFriends()->DownloadClanActivityCounts(psteamIDClans.data(), cClansToRequest);
    luasteam::pushuint64(L, __ret);
    lua_createtable(L, cClansToRequest, 0);
    for(int i=0;i<cClansToRequest;i++){
    luasteam::pushuint64(L, psteamIDClans[i].ConvertToUint64());
    lua_rawseti(L, -2, i+1);
    }
    return 1;
}

// int GetFriendCountFromSource(CSteamID steamIDSource);
EXTERN int luasteam_Friends_GetFriendCountFromSource(lua_State *L) {
    CSteamID steamIDSource(luasteam::checkuint64(L, 1));
    int __ret = SteamFriends()->GetFriendCountFromSource(steamIDSource);
    lua_pushinteger(L, __ret);
    return 1;
}

// CSteamID GetFriendFromSourceByIndex(CSteamID steamIDSource, int iFriend);
EXTERN int luasteam_Friends_GetFriendFromSourceByIndex(lua_State *L) {
    CSteamID steamIDSource(luasteam::checkuint64(L, 1));
    int iFriend = static_cast<int>(luaL_checkint(L, 2));
    CSteamID __ret = SteamFriends()->GetFriendFromSourceByIndex(steamIDSource, iFriend);
    luasteam::pushuint64(L, __ret.ConvertToUint64());
    return 1;
}

// bool IsUserInSource(CSteamID steamIDUser, CSteamID steamIDSource);
EXTERN int luasteam_Friends_IsUserInSource(lua_State *L) {
    CSteamID steamIDUser(luasteam::checkuint64(L, 1));
    CSteamID steamIDSource(luasteam::checkuint64(L, 2));
    bool __ret = SteamFriends()->IsUserInSource(steamIDUser, steamIDSource);
    lua_pushboolean(L, __ret);
    return 1;
}

// void SetInGameVoiceSpeaking(CSteamID steamIDUser, bool bSpeaking);
EXTERN int luasteam_Friends_SetInGameVoiceSpeaking(lua_State *L) {
    CSteamID steamIDUser(luasteam::checkuint64(L, 1));
    bool bSpeaking = lua_toboolean(L, 2);
    SteamFriends()->SetInGameVoiceSpeaking(steamIDUser, bSpeaking);
    return 0;
}

// void ActivateGameOverlay(const char * pchDialog);
EXTERN int luasteam_Friends_ActivateGameOverlay(lua_State *L) {
    const char *pchDialog = luaL_checkstring(L, 1);
    SteamFriends()->ActivateGameOverlay(pchDialog);
    return 0;
}

// void ActivateGameOverlayToUser(const char * pchDialog, CSteamID steamID);
EXTERN int luasteam_Friends_ActivateGameOverlayToUser(lua_State *L) {
    const char *pchDialog = luaL_checkstring(L, 1);
    CSteamID steamID(luasteam::checkuint64(L, 2));
    SteamFriends()->ActivateGameOverlayToUser(pchDialog, steamID);
    return 0;
}

// void ActivateGameOverlayToWebPage(const char * pchURL, EActivateGameOverlayToWebPageMode eMode);
EXTERN int luasteam_Friends_ActivateGameOverlayToWebPage(lua_State *L) {
    const char *pchURL = luaL_checkstring(L, 1);
    EActivateGameOverlayToWebPageMode eMode = static_cast<EActivateGameOverlayToWebPageMode>(luaL_checkint(L, 2));
    SteamFriends()->ActivateGameOverlayToWebPage(pchURL, eMode);
    return 0;
}

// void ActivateGameOverlayToStore(AppId_t nAppID, EOverlayToStoreFlag eFlag);
EXTERN int luasteam_Friends_ActivateGameOverlayToStore(lua_State *L) {
    AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
    EOverlayToStoreFlag eFlag = static_cast<EOverlayToStoreFlag>(luaL_checkint(L, 2));
    SteamFriends()->ActivateGameOverlayToStore(nAppID, eFlag);
    return 0;
}

// void SetPlayedWith(CSteamID steamIDUserPlayedWith);
EXTERN int luasteam_Friends_SetPlayedWith(lua_State *L) {
    CSteamID steamIDUserPlayedWith(luasteam::checkuint64(L, 1));
    SteamFriends()->SetPlayedWith(steamIDUserPlayedWith);
    return 0;
}

// void ActivateGameOverlayInviteDialog(CSteamID steamIDLobby);
EXTERN int luasteam_Friends_ActivateGameOverlayInviteDialog(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    SteamFriends()->ActivateGameOverlayInviteDialog(steamIDLobby);
    return 0;
}

// int GetSmallFriendAvatar(CSteamID steamIDFriend);
EXTERN int luasteam_Friends_GetSmallFriendAvatar(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    int __ret = SteamFriends()->GetSmallFriendAvatar(steamIDFriend);
    lua_pushinteger(L, __ret);
    return 1;
}

// int GetMediumFriendAvatar(CSteamID steamIDFriend);
EXTERN int luasteam_Friends_GetMediumFriendAvatar(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    int __ret = SteamFriends()->GetMediumFriendAvatar(steamIDFriend);
    lua_pushinteger(L, __ret);
    return 1;
}

// int GetLargeFriendAvatar(CSteamID steamIDFriend);
EXTERN int luasteam_Friends_GetLargeFriendAvatar(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    int __ret = SteamFriends()->GetLargeFriendAvatar(steamIDFriend);
    lua_pushinteger(L, __ret);
    return 1;
}

// bool RequestUserInformation(CSteamID steamIDUser, bool bRequireNameOnly);
EXTERN int luasteam_Friends_RequestUserInformation(lua_State *L) {
    CSteamID steamIDUser(luasteam::checkuint64(L, 1));
    bool bRequireNameOnly = lua_toboolean(L, 2);
    bool __ret = SteamFriends()->RequestUserInformation(steamIDUser, bRequireNameOnly);
    lua_pushboolean(L, __ret);
    return 1;
}

// SteamAPICall_t RequestClanOfficerList(CSteamID steamIDClan);
EXTERN int luasteam_Friends_RequestClanOfficerList(lua_State *L) {
    CSteamID steamIDClan(luasteam::checkuint64(L, 1));
    SteamAPICall_t __ret = SteamFriends()->RequestClanOfficerList(steamIDClan);
    luasteam::pushuint64(L, __ret);
    return 1;
}

// CSteamID GetClanOwner(CSteamID steamIDClan);
EXTERN int luasteam_Friends_GetClanOwner(lua_State *L) {
    CSteamID steamIDClan(luasteam::checkuint64(L, 1));
    CSteamID __ret = SteamFriends()->GetClanOwner(steamIDClan);
    luasteam::pushuint64(L, __ret.ConvertToUint64());
    return 1;
}

// int GetClanOfficerCount(CSteamID steamIDClan);
EXTERN int luasteam_Friends_GetClanOfficerCount(lua_State *L) {
    CSteamID steamIDClan(luasteam::checkuint64(L, 1));
    int __ret = SteamFriends()->GetClanOfficerCount(steamIDClan);
    lua_pushinteger(L, __ret);
    return 1;
}

// CSteamID GetClanOfficerByIndex(CSteamID steamIDClan, int iOfficer);
EXTERN int luasteam_Friends_GetClanOfficerByIndex(lua_State *L) {
    CSteamID steamIDClan(luasteam::checkuint64(L, 1));
    int iOfficer = static_cast<int>(luaL_checkint(L, 2));
    CSteamID __ret = SteamFriends()->GetClanOfficerByIndex(steamIDClan, iOfficer);
    luasteam::pushuint64(L, __ret.ConvertToUint64());
    return 1;
}

// bool SetRichPresence(const char * pchKey, const char * pchValue);
EXTERN int luasteam_Friends_SetRichPresence(lua_State *L) {
    const char *pchKey = luaL_checkstring(L, 1);
    const char *pchValue = luaL_checkstring(L, 2);
    bool __ret = SteamFriends()->SetRichPresence(pchKey, pchValue);
    lua_pushboolean(L, __ret);
    return 1;
}

// void ClearRichPresence();
EXTERN int luasteam_Friends_ClearRichPresence(lua_State *L) {
    SteamFriends()->ClearRichPresence();
    return 0;
}

// const char * GetFriendRichPresence(CSteamID steamIDFriend, const char * pchKey);
EXTERN int luasteam_Friends_GetFriendRichPresence(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    const char *pchKey = luaL_checkstring(L, 2);
    const char * __ret = SteamFriends()->GetFriendRichPresence(steamIDFriend, pchKey);
    lua_pushstring(L, reinterpret_cast<const char*>(__ret));
    return 1;
}

// int GetFriendRichPresenceKeyCount(CSteamID steamIDFriend);
EXTERN int luasteam_Friends_GetFriendRichPresenceKeyCount(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    int __ret = SteamFriends()->GetFriendRichPresenceKeyCount(steamIDFriend);
    lua_pushinteger(L, __ret);
    return 1;
}

// const char * GetFriendRichPresenceKeyByIndex(CSteamID steamIDFriend, int iKey);
EXTERN int luasteam_Friends_GetFriendRichPresenceKeyByIndex(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    int iKey = static_cast<int>(luaL_checkint(L, 2));
    const char * __ret = SteamFriends()->GetFriendRichPresenceKeyByIndex(steamIDFriend, iKey);
    lua_pushstring(L, reinterpret_cast<const char*>(__ret));
    return 1;
}

// void RequestFriendRichPresence(CSteamID steamIDFriend);
EXTERN int luasteam_Friends_RequestFriendRichPresence(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    SteamFriends()->RequestFriendRichPresence(steamIDFriend);
    return 0;
}

// bool InviteUserToGame(CSteamID steamIDFriend, const char * pchConnectString);
EXTERN int luasteam_Friends_InviteUserToGame(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    const char *pchConnectString = luaL_checkstring(L, 2);
    bool __ret = SteamFriends()->InviteUserToGame(steamIDFriend, pchConnectString);
    lua_pushboolean(L, __ret);
    return 1;
}

// int GetCoplayFriendCount();
EXTERN int luasteam_Friends_GetCoplayFriendCount(lua_State *L) {
    int __ret = SteamFriends()->GetCoplayFriendCount();
    lua_pushinteger(L, __ret);
    return 1;
}

// CSteamID GetCoplayFriend(int iCoplayFriend);
EXTERN int luasteam_Friends_GetCoplayFriend(lua_State *L) {
    int iCoplayFriend = static_cast<int>(luaL_checkint(L, 1));
    CSteamID __ret = SteamFriends()->GetCoplayFriend(iCoplayFriend);
    luasteam::pushuint64(L, __ret.ConvertToUint64());
    return 1;
}

// int GetFriendCoplayTime(CSteamID steamIDFriend);
EXTERN int luasteam_Friends_GetFriendCoplayTime(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    int __ret = SteamFriends()->GetFriendCoplayTime(steamIDFriend);
    lua_pushinteger(L, __ret);
    return 1;
}

// AppId_t GetFriendCoplayGame(CSteamID steamIDFriend);
EXTERN int luasteam_Friends_GetFriendCoplayGame(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    AppId_t __ret = SteamFriends()->GetFriendCoplayGame(steamIDFriend);
    lua_pushinteger(L, __ret);
    return 1;
}

// SteamAPICall_t JoinClanChatRoom(CSteamID steamIDClan);
EXTERN int luasteam_Friends_JoinClanChatRoom(lua_State *L) {
    CSteamID steamIDClan(luasteam::checkuint64(L, 1));
    SteamAPICall_t __ret = SteamFriends()->JoinClanChatRoom(steamIDClan);
    luasteam::pushuint64(L, __ret);
    return 1;
}

// bool LeaveClanChatRoom(CSteamID steamIDClan);
EXTERN int luasteam_Friends_LeaveClanChatRoom(lua_State *L) {
    CSteamID steamIDClan(luasteam::checkuint64(L, 1));
    bool __ret = SteamFriends()->LeaveClanChatRoom(steamIDClan);
    lua_pushboolean(L, __ret);
    return 1;
}

// int GetClanChatMemberCount(CSteamID steamIDClan);
EXTERN int luasteam_Friends_GetClanChatMemberCount(lua_State *L) {
    CSteamID steamIDClan(luasteam::checkuint64(L, 1));
    int __ret = SteamFriends()->GetClanChatMemberCount(steamIDClan);
    lua_pushinteger(L, __ret);
    return 1;
}

// CSteamID GetChatMemberByIndex(CSteamID steamIDClan, int iUser);
EXTERN int luasteam_Friends_GetChatMemberByIndex(lua_State *L) {
    CSteamID steamIDClan(luasteam::checkuint64(L, 1));
    int iUser = static_cast<int>(luaL_checkint(L, 2));
    CSteamID __ret = SteamFriends()->GetChatMemberByIndex(steamIDClan, iUser);
    luasteam::pushuint64(L, __ret.ConvertToUint64());
    return 1;
}

// bool SendClanChatMessage(CSteamID steamIDClanChat, const char * pchText);
EXTERN int luasteam_Friends_SendClanChatMessage(lua_State *L) {
    CSteamID steamIDClanChat(luasteam::checkuint64(L, 1));
    const char *pchText = luaL_checkstring(L, 2);
    bool __ret = SteamFriends()->SendClanChatMessage(steamIDClanChat, pchText);
    lua_pushboolean(L, __ret);
    return 1;
}

// int GetClanChatMessage(CSteamID steamIDClanChat, int iMessage, void * prgchText, int cchTextMax, EChatEntryType * peChatEntryType, CSteamID * psteamidChatter);
EXTERN int luasteam_Friends_GetClanChatMessage(lua_State *L) {
    CSteamID steamIDClanChat(luasteam::checkuint64(L, 1));
    int iMessage = static_cast<int>(luaL_checkint(L, 2));
    int cchTextMax = luaL_checkint(L, 3);
    std::vector<unsigned char> prgchText(cchTextMax);
    EChatEntryType peChatEntryType;    CSteamID psteamidChatter;    int __ret = SteamFriends()->GetClanChatMessage(steamIDClanChat, iMessage, prgchText.data(), cchTextMax, &peChatEntryType, &psteamidChatter);
    lua_pushinteger(L, __ret);
    lua_pushlstring(L, reinterpret_cast<const char*>(prgchText.data()), __ret);
    lua_pushinteger(L, peChatEntryType);
    luasteam::pushuint64(L, psteamidChatter.ConvertToUint64());
    return 3;
}

// bool IsClanChatAdmin(CSteamID steamIDClanChat, CSteamID steamIDUser);
EXTERN int luasteam_Friends_IsClanChatAdmin(lua_State *L) {
    CSteamID steamIDClanChat(luasteam::checkuint64(L, 1));
    CSteamID steamIDUser(luasteam::checkuint64(L, 2));
    bool __ret = SteamFriends()->IsClanChatAdmin(steamIDClanChat, steamIDUser);
    lua_pushboolean(L, __ret);
    return 1;
}

// bool IsClanChatWindowOpenInSteam(CSteamID steamIDClanChat);
EXTERN int luasteam_Friends_IsClanChatWindowOpenInSteam(lua_State *L) {
    CSteamID steamIDClanChat(luasteam::checkuint64(L, 1));
    bool __ret = SteamFriends()->IsClanChatWindowOpenInSteam(steamIDClanChat);
    lua_pushboolean(L, __ret);
    return 1;
}

// bool OpenClanChatWindowInSteam(CSteamID steamIDClanChat);
EXTERN int luasteam_Friends_OpenClanChatWindowInSteam(lua_State *L) {
    CSteamID steamIDClanChat(luasteam::checkuint64(L, 1));
    bool __ret = SteamFriends()->OpenClanChatWindowInSteam(steamIDClanChat);
    lua_pushboolean(L, __ret);
    return 1;
}

// bool CloseClanChatWindowInSteam(CSteamID steamIDClanChat);
EXTERN int luasteam_Friends_CloseClanChatWindowInSteam(lua_State *L) {
    CSteamID steamIDClanChat(luasteam::checkuint64(L, 1));
    bool __ret = SteamFriends()->CloseClanChatWindowInSteam(steamIDClanChat);
    lua_pushboolean(L, __ret);
    return 1;
}

// bool SetListenForFriendsMessages(bool bInterceptEnabled);
EXTERN int luasteam_Friends_SetListenForFriendsMessages(lua_State *L) {
    bool bInterceptEnabled = lua_toboolean(L, 1);
    bool __ret = SteamFriends()->SetListenForFriendsMessages(bInterceptEnabled);
    lua_pushboolean(L, __ret);
    return 1;
}

// bool ReplyToFriendMessage(CSteamID steamIDFriend, const char * pchMsgToSend);
EXTERN int luasteam_Friends_ReplyToFriendMessage(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    const char *pchMsgToSend = luaL_checkstring(L, 2);
    bool __ret = SteamFriends()->ReplyToFriendMessage(steamIDFriend, pchMsgToSend);
    lua_pushboolean(L, __ret);
    return 1;
}

// int GetFriendMessage(CSteamID steamIDFriend, int iMessageID, void * pvData, int cubData, EChatEntryType * peChatEntryType);
EXTERN int luasteam_Friends_GetFriendMessage(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    int iMessageID = static_cast<int>(luaL_checkint(L, 2));
    int cubData = luaL_checkint(L, 3);
    std::vector<unsigned char> pvData(cubData);
    EChatEntryType peChatEntryType;    int __ret = SteamFriends()->GetFriendMessage(steamIDFriend, iMessageID, pvData.data(), cubData, &peChatEntryType);
    lua_pushinteger(L, __ret);
    lua_pushlstring(L, reinterpret_cast<const char*>(pvData.data()), __ret);
    lua_pushinteger(L, peChatEntryType);
    return 2;
}

// SteamAPICall_t GetFollowerCount(CSteamID steamID);
EXTERN int luasteam_Friends_GetFollowerCount(lua_State *L) {
    CSteamID steamID(luasteam::checkuint64(L, 1));
    SteamAPICall_t __ret = SteamFriends()->GetFollowerCount(steamID);
    luasteam::pushuint64(L, __ret);
    return 1;
}

// SteamAPICall_t IsFollowing(CSteamID steamID);
EXTERN int luasteam_Friends_IsFollowing(lua_State *L) {
    CSteamID steamID(luasteam::checkuint64(L, 1));
    SteamAPICall_t __ret = SteamFriends()->IsFollowing(steamID);
    luasteam::pushuint64(L, __ret);
    return 1;
}

// SteamAPICall_t EnumerateFollowingList(uint32 unStartIndex);
EXTERN int luasteam_Friends_EnumerateFollowingList(lua_State *L) {
    uint32 unStartIndex = static_cast<uint32>(luaL_checkint(L, 1));
    SteamAPICall_t __ret = SteamFriends()->EnumerateFollowingList(unStartIndex);
    luasteam::pushuint64(L, __ret);
    return 1;
}

// bool IsClanPublic(CSteamID steamIDClan);
EXTERN int luasteam_Friends_IsClanPublic(lua_State *L) {
    CSteamID steamIDClan(luasteam::checkuint64(L, 1));
    bool __ret = SteamFriends()->IsClanPublic(steamIDClan);
    lua_pushboolean(L, __ret);
    return 1;
}

// bool IsClanOfficialGameGroup(CSteamID steamIDClan);
EXTERN int luasteam_Friends_IsClanOfficialGameGroup(lua_State *L) {
    CSteamID steamIDClan(luasteam::checkuint64(L, 1));
    bool __ret = SteamFriends()->IsClanOfficialGameGroup(steamIDClan);
    lua_pushboolean(L, __ret);
    return 1;
}

// int GetNumChatsWithUnreadPriorityMessages();
EXTERN int luasteam_Friends_GetNumChatsWithUnreadPriorityMessages(lua_State *L) {
    int __ret = SteamFriends()->GetNumChatsWithUnreadPriorityMessages();
    lua_pushinteger(L, __ret);
    return 1;
}

// void ActivateGameOverlayRemotePlayTogetherInviteDialog(CSteamID steamIDLobby);
EXTERN int luasteam_Friends_ActivateGameOverlayRemotePlayTogetherInviteDialog(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    SteamFriends()->ActivateGameOverlayRemotePlayTogetherInviteDialog(steamIDLobby);
    return 0;
}

// bool RegisterProtocolInOverlayBrowser(const char * pchProtocol);
EXTERN int luasteam_Friends_RegisterProtocolInOverlayBrowser(lua_State *L) {
    const char *pchProtocol = luaL_checkstring(L, 1);
    bool __ret = SteamFriends()->RegisterProtocolInOverlayBrowser(pchProtocol);
    lua_pushboolean(L, __ret);
    return 1;
}

// void ActivateGameOverlayInviteDialogConnectString(const char * pchConnectString);
EXTERN int luasteam_Friends_ActivateGameOverlayInviteDialogConnectString(lua_State *L) {
    const char *pchConnectString = luaL_checkstring(L, 1);
    SteamFriends()->ActivateGameOverlayInviteDialogConnectString(pchConnectString);
    return 0;
}

// SteamAPICall_t RequestEquippedProfileItems(CSteamID steamID);
EXTERN int luasteam_Friends_RequestEquippedProfileItems(lua_State *L) {
    CSteamID steamID(luasteam::checkuint64(L, 1));
    SteamAPICall_t __ret = SteamFriends()->RequestEquippedProfileItems(steamID);
    luasteam::pushuint64(L, __ret);
    return 1;
}

// bool BHasEquippedProfileItem(CSteamID steamID, ECommunityProfileItemType itemType);
EXTERN int luasteam_Friends_BHasEquippedProfileItem(lua_State *L) {
    CSteamID steamID(luasteam::checkuint64(L, 1));
    ECommunityProfileItemType itemType = static_cast<ECommunityProfileItemType>(luaL_checkint(L, 2));
    bool __ret = SteamFriends()->BHasEquippedProfileItem(steamID, itemType);
    lua_pushboolean(L, __ret);
    return 1;
}

// const char * GetProfileItemPropertyString(CSteamID steamID, ECommunityProfileItemType itemType, ECommunityProfileItemProperty prop);
EXTERN int luasteam_Friends_GetProfileItemPropertyString(lua_State *L) {
    CSteamID steamID(luasteam::checkuint64(L, 1));
    ECommunityProfileItemType itemType = static_cast<ECommunityProfileItemType>(luaL_checkint(L, 2));
    ECommunityProfileItemProperty prop = static_cast<ECommunityProfileItemProperty>(luaL_checkint(L, 3));
    const char * __ret = SteamFriends()->GetProfileItemPropertyString(steamID, itemType, prop);
    lua_pushstring(L, reinterpret_cast<const char*>(__ret));
    return 1;
}

// uint32 GetProfileItemPropertyUint(CSteamID steamID, ECommunityProfileItemType itemType, ECommunityProfileItemProperty prop);
EXTERN int luasteam_Friends_GetProfileItemPropertyUint(lua_State *L) {
    CSteamID steamID(luasteam::checkuint64(L, 1));
    ECommunityProfileItemType itemType = static_cast<ECommunityProfileItemType>(luaL_checkint(L, 2));
    ECommunityProfileItemProperty prop = static_cast<ECommunityProfileItemProperty>(luaL_checkint(L, 3));
    uint32 __ret = SteamFriends()->GetProfileItemPropertyUint(steamID, itemType, prop);
    lua_pushinteger(L, __ret);
    return 1;
}

void register_Friends_auto(lua_State *L) {
    add_func(L, "GetPersonaName", luasteam_Friends_GetPersonaName);
    add_func(L, "GetPersonaState", luasteam_Friends_GetPersonaState);
    add_func(L, "GetFriendCount", luasteam_Friends_GetFriendCount);
    add_func(L, "GetFriendByIndex", luasteam_Friends_GetFriendByIndex);
    add_func(L, "GetFriendRelationship", luasteam_Friends_GetFriendRelationship);
    add_func(L, "GetFriendPersonaState", luasteam_Friends_GetFriendPersonaState);
    add_func(L, "GetFriendPersonaName", luasteam_Friends_GetFriendPersonaName);
    add_func(L, "GetFriendGamePlayed", luasteam_Friends_GetFriendGamePlayed);
    add_func(L, "GetFriendPersonaNameHistory", luasteam_Friends_GetFriendPersonaNameHistory);
    add_func(L, "GetFriendSteamLevel", luasteam_Friends_GetFriendSteamLevel);
    add_func(L, "GetPlayerNickname", luasteam_Friends_GetPlayerNickname);
    add_func(L, "GetFriendsGroupCount", luasteam_Friends_GetFriendsGroupCount);
    add_func(L, "GetFriendsGroupIDByIndex", luasteam_Friends_GetFriendsGroupIDByIndex);
    add_func(L, "GetFriendsGroupName", luasteam_Friends_GetFriendsGroupName);
    add_func(L, "GetFriendsGroupMembersCount", luasteam_Friends_GetFriendsGroupMembersCount);
    add_func(L, "GetFriendsGroupMembersList", luasteam_Friends_GetFriendsGroupMembersList);
    add_func(L, "HasFriend", luasteam_Friends_HasFriend);
    add_func(L, "GetClanCount", luasteam_Friends_GetClanCount);
    add_func(L, "GetClanByIndex", luasteam_Friends_GetClanByIndex);
    add_func(L, "GetClanName", luasteam_Friends_GetClanName);
    add_func(L, "GetClanTag", luasteam_Friends_GetClanTag);
    add_func(L, "GetClanActivityCounts", luasteam_Friends_GetClanActivityCounts);
    add_func(L, "DownloadClanActivityCounts", luasteam_Friends_DownloadClanActivityCounts);
    add_func(L, "GetFriendCountFromSource", luasteam_Friends_GetFriendCountFromSource);
    add_func(L, "GetFriendFromSourceByIndex", luasteam_Friends_GetFriendFromSourceByIndex);
    add_func(L, "IsUserInSource", luasteam_Friends_IsUserInSource);
    add_func(L, "SetInGameVoiceSpeaking", luasteam_Friends_SetInGameVoiceSpeaking);
    add_func(L, "ActivateGameOverlay", luasteam_Friends_ActivateGameOverlay);
    add_func(L, "ActivateGameOverlayToUser", luasteam_Friends_ActivateGameOverlayToUser);
    add_func(L, "ActivateGameOverlayToWebPage", luasteam_Friends_ActivateGameOverlayToWebPage);
    add_func(L, "ActivateGameOverlayToStore", luasteam_Friends_ActivateGameOverlayToStore);
    add_func(L, "SetPlayedWith", luasteam_Friends_SetPlayedWith);
    add_func(L, "ActivateGameOverlayInviteDialog", luasteam_Friends_ActivateGameOverlayInviteDialog);
    add_func(L, "GetSmallFriendAvatar", luasteam_Friends_GetSmallFriendAvatar);
    add_func(L, "GetMediumFriendAvatar", luasteam_Friends_GetMediumFriendAvatar);
    add_func(L, "GetLargeFriendAvatar", luasteam_Friends_GetLargeFriendAvatar);
    add_func(L, "RequestUserInformation", luasteam_Friends_RequestUserInformation);
    add_func(L, "RequestClanOfficerList", luasteam_Friends_RequestClanOfficerList);
    add_func(L, "GetClanOwner", luasteam_Friends_GetClanOwner);
    add_func(L, "GetClanOfficerCount", luasteam_Friends_GetClanOfficerCount);
    add_func(L, "GetClanOfficerByIndex", luasteam_Friends_GetClanOfficerByIndex);
    add_func(L, "SetRichPresence", luasteam_Friends_SetRichPresence);
    add_func(L, "ClearRichPresence", luasteam_Friends_ClearRichPresence);
    add_func(L, "GetFriendRichPresence", luasteam_Friends_GetFriendRichPresence);
    add_func(L, "GetFriendRichPresenceKeyCount", luasteam_Friends_GetFriendRichPresenceKeyCount);
    add_func(L, "GetFriendRichPresenceKeyByIndex", luasteam_Friends_GetFriendRichPresenceKeyByIndex);
    add_func(L, "RequestFriendRichPresence", luasteam_Friends_RequestFriendRichPresence);
    add_func(L, "InviteUserToGame", luasteam_Friends_InviteUserToGame);
    add_func(L, "GetCoplayFriendCount", luasteam_Friends_GetCoplayFriendCount);
    add_func(L, "GetCoplayFriend", luasteam_Friends_GetCoplayFriend);
    add_func(L, "GetFriendCoplayTime", luasteam_Friends_GetFriendCoplayTime);
    add_func(L, "GetFriendCoplayGame", luasteam_Friends_GetFriendCoplayGame);
    add_func(L, "JoinClanChatRoom", luasteam_Friends_JoinClanChatRoom);
    add_func(L, "LeaveClanChatRoom", luasteam_Friends_LeaveClanChatRoom);
    add_func(L, "GetClanChatMemberCount", luasteam_Friends_GetClanChatMemberCount);
    add_func(L, "GetChatMemberByIndex", luasteam_Friends_GetChatMemberByIndex);
    add_func(L, "SendClanChatMessage", luasteam_Friends_SendClanChatMessage);
    add_func(L, "GetClanChatMessage", luasteam_Friends_GetClanChatMessage);
    add_func(L, "IsClanChatAdmin", luasteam_Friends_IsClanChatAdmin);
    add_func(L, "IsClanChatWindowOpenInSteam", luasteam_Friends_IsClanChatWindowOpenInSteam);
    add_func(L, "OpenClanChatWindowInSteam", luasteam_Friends_OpenClanChatWindowInSteam);
    add_func(L, "CloseClanChatWindowInSteam", luasteam_Friends_CloseClanChatWindowInSteam);
    add_func(L, "SetListenForFriendsMessages", luasteam_Friends_SetListenForFriendsMessages);
    add_func(L, "ReplyToFriendMessage", luasteam_Friends_ReplyToFriendMessage);
    add_func(L, "GetFriendMessage", luasteam_Friends_GetFriendMessage);
    add_func(L, "GetFollowerCount", luasteam_Friends_GetFollowerCount);
    add_func(L, "IsFollowing", luasteam_Friends_IsFollowing);
    add_func(L, "EnumerateFollowingList", luasteam_Friends_EnumerateFollowingList);
    add_func(L, "IsClanPublic", luasteam_Friends_IsClanPublic);
    add_func(L, "IsClanOfficialGameGroup", luasteam_Friends_IsClanOfficialGameGroup);
    add_func(L, "GetNumChatsWithUnreadPriorityMessages", luasteam_Friends_GetNumChatsWithUnreadPriorityMessages);
    add_func(L, "ActivateGameOverlayRemotePlayTogetherInviteDialog", luasteam_Friends_ActivateGameOverlayRemotePlayTogetherInviteDialog);
    add_func(L, "RegisterProtocolInOverlayBrowser", luasteam_Friends_RegisterProtocolInOverlayBrowser);
    add_func(L, "ActivateGameOverlayInviteDialogConnectString", luasteam_Friends_ActivateGameOverlayInviteDialogConnectString);
    add_func(L, "RequestEquippedProfileItems", luasteam_Friends_RequestEquippedProfileItems);
    add_func(L, "BHasEquippedProfileItem", luasteam_Friends_BHasEquippedProfileItem);
    add_func(L, "GetProfileItemPropertyString", luasteam_Friends_GetProfileItemPropertyString);
    add_func(L, "GetProfileItemPropertyUint", luasteam_Friends_GetProfileItemPropertyUint);
}

void add_Friends_auto(lua_State *L) {
    lua_createtable(L, 0, 78);
    register_Friends_auto(L);
    lua_pushvalue(L, -1);
    Friends_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "Friends");
}

} // namespace luasteam
