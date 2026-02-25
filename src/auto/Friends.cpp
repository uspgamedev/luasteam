#include "auto.hpp"

namespace luasteam {

int Friends_ref = LUA_NOREF;

namespace {
class FriendsCallbackListener {
private:
	STEAM_CALLBACK(FriendsCallbackListener, OnPersonaStateChange, PersonaStateChange_t);
	STEAM_CALLBACK(FriendsCallbackListener, OnGameOverlayActivated, GameOverlayActivated_t);
	STEAM_CALLBACK(FriendsCallbackListener, OnGameServerChangeRequested, GameServerChangeRequested_t);
	STEAM_CALLBACK(FriendsCallbackListener, OnGameLobbyJoinRequested, GameLobbyJoinRequested_t);
	STEAM_CALLBACK(FriendsCallbackListener, OnAvatarImageLoaded, AvatarImageLoaded_t);
	STEAM_CALLBACK(FriendsCallbackListener, OnClanOfficerListResponse, ClanOfficerListResponse_t);
	STEAM_CALLBACK(FriendsCallbackListener, OnFriendRichPresenceUpdate, FriendRichPresenceUpdate_t);
	STEAM_CALLBACK(FriendsCallbackListener, OnGameRichPresenceJoinRequested, GameRichPresenceJoinRequested_t);
	STEAM_CALLBACK(FriendsCallbackListener, OnGameConnectedClanChatMsg, GameConnectedClanChatMsg_t);
	STEAM_CALLBACK(FriendsCallbackListener, OnGameConnectedChatJoin, GameConnectedChatJoin_t);
	STEAM_CALLBACK(FriendsCallbackListener, OnGameConnectedChatLeave, GameConnectedChatLeave_t);
	STEAM_CALLBACK(FriendsCallbackListener, OnDownloadClanActivityCountsResult, DownloadClanActivityCountsResult_t);
	STEAM_CALLBACK(FriendsCallbackListener, OnJoinClanChatRoomCompletionResult, JoinClanChatRoomCompletionResult_t);
	STEAM_CALLBACK(FriendsCallbackListener, OnGameConnectedFriendChatMsg, GameConnectedFriendChatMsg_t);
	STEAM_CALLBACK(FriendsCallbackListener, OnFriendsGetFollowerCount, FriendsGetFollowerCount_t);
	STEAM_CALLBACK(FriendsCallbackListener, OnFriendsIsFollowing, FriendsIsFollowing_t);
	STEAM_CALLBACK(FriendsCallbackListener, OnFriendsEnumerateFollowingList, FriendsEnumerateFollowingList_t);
	STEAM_CALLBACK(FriendsCallbackListener, OnUnreadChatMessagesChanged, UnreadChatMessagesChanged_t);
	STEAM_CALLBACK(FriendsCallbackListener, OnOverlayBrowserProtocolNavigation, OverlayBrowserProtocolNavigation_t);
	STEAM_CALLBACK(FriendsCallbackListener, OnEquippedProfileItemsChanged, EquippedProfileItemsChanged_t);
	STEAM_CALLBACK(FriendsCallbackListener, OnEquippedProfileItems, EquippedProfileItems_t);
};
void FriendsCallbackListener::OnPersonaStateChange(PersonaStateChange_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
	lua_getfield(L, -1, "OnPersonaStateChange");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_PersonaStateChange_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void FriendsCallbackListener::OnGameOverlayActivated(GameOverlayActivated_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
	lua_getfield(L, -1, "OnGameOverlayActivated");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_GameOverlayActivated_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void FriendsCallbackListener::OnGameServerChangeRequested(GameServerChangeRequested_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
	lua_getfield(L, -1, "OnGameServerChangeRequested");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_GameServerChangeRequested_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void FriendsCallbackListener::OnGameLobbyJoinRequested(GameLobbyJoinRequested_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
	lua_getfield(L, -1, "OnGameLobbyJoinRequested");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_GameLobbyJoinRequested_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void FriendsCallbackListener::OnAvatarImageLoaded(AvatarImageLoaded_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
	lua_getfield(L, -1, "OnAvatarImageLoaded");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_AvatarImageLoaded_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void FriendsCallbackListener::OnClanOfficerListResponse(ClanOfficerListResponse_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
	lua_getfield(L, -1, "OnClanOfficerListResponse");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_ClanOfficerListResponse_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void FriendsCallbackListener::OnFriendRichPresenceUpdate(FriendRichPresenceUpdate_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
	lua_getfield(L, -1, "OnFriendRichPresenceUpdate");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_FriendRichPresenceUpdate_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void FriendsCallbackListener::OnGameRichPresenceJoinRequested(GameRichPresenceJoinRequested_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
	lua_getfield(L, -1, "OnGameRichPresenceJoinRequested");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_GameRichPresenceJoinRequested_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void FriendsCallbackListener::OnGameConnectedClanChatMsg(GameConnectedClanChatMsg_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
	lua_getfield(L, -1, "OnGameConnectedClanChatMsg");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_GameConnectedClanChatMsg_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void FriendsCallbackListener::OnGameConnectedChatJoin(GameConnectedChatJoin_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
	lua_getfield(L, -1, "OnGameConnectedChatJoin");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_GameConnectedChatJoin_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void FriendsCallbackListener::OnGameConnectedChatLeave(GameConnectedChatLeave_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
	lua_getfield(L, -1, "OnGameConnectedChatLeave");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_GameConnectedChatLeave_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void FriendsCallbackListener::OnDownloadClanActivityCountsResult(DownloadClanActivityCountsResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
	lua_getfield(L, -1, "OnDownloadClanActivityCountsResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_DownloadClanActivityCountsResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void FriendsCallbackListener::OnJoinClanChatRoomCompletionResult(JoinClanChatRoomCompletionResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
	lua_getfield(L, -1, "OnJoinClanChatRoomCompletionResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_JoinClanChatRoomCompletionResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void FriendsCallbackListener::OnGameConnectedFriendChatMsg(GameConnectedFriendChatMsg_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
	lua_getfield(L, -1, "OnGameConnectedFriendChatMsg");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_GameConnectedFriendChatMsg_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void FriendsCallbackListener::OnFriendsGetFollowerCount(FriendsGetFollowerCount_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
	lua_getfield(L, -1, "OnFriendsGetFollowerCount");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_FriendsGetFollowerCount_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void FriendsCallbackListener::OnFriendsIsFollowing(FriendsIsFollowing_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
	lua_getfield(L, -1, "OnFriendsIsFollowing");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_FriendsIsFollowing_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void FriendsCallbackListener::OnFriendsEnumerateFollowingList(FriendsEnumerateFollowingList_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
	lua_getfield(L, -1, "OnFriendsEnumerateFollowingList");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_FriendsEnumerateFollowingList_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void FriendsCallbackListener::OnUnreadChatMessagesChanged(UnreadChatMessagesChanged_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
	lua_getfield(L, -1, "OnUnreadChatMessagesChanged");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_UnreadChatMessagesChanged_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void FriendsCallbackListener::OnOverlayBrowserProtocolNavigation(OverlayBrowserProtocolNavigation_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
	lua_getfield(L, -1, "OnOverlayBrowserProtocolNavigation");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_OverlayBrowserProtocolNavigation_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void FriendsCallbackListener::OnEquippedProfileItemsChanged(EquippedProfileItemsChanged_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
	lua_getfield(L, -1, "OnEquippedProfileItemsChanged");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_EquippedProfileItemsChanged_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void FriendsCallbackListener::OnEquippedProfileItems(EquippedProfileItems_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Friends_ref);
	lua_getfield(L, -1, "OnEquippedProfileItems");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_EquippedProfileItems_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
FriendsCallbackListener *Friends_listener = nullptr;
} // namespace

void init_Friends_auto(lua_State *L) { if (Friends_listener != nullptr) return; Friends_listener = new FriendsCallbackListener(); }
void shutdown_Friends_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, Friends_ref);
	Friends_ref = LUA_NOREF;
	delete Friends_listener; Friends_listener = nullptr;
}

template <> void CallResultListener<ClanOfficerListResponse_t>::Result(ClanOfficerListResponse_t *data, bool io_fail) {
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
		lua_createtable(L, 0, 3);
		luasteam::pushuint64(L, data->m_steamIDClan.ConvertToUint64());
		lua_setfield(L, -2, "m_steamIDClan");
		lua_pushinteger(L, data->m_cOfficers);
		lua_setfield(L, -2, "m_cOfficers");
		lua_pushinteger(L, data->m_bSuccess);
		lua_setfield(L, -2, "m_bSuccess");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<DownloadClanActivityCountsResult_t>::Result(DownloadClanActivityCountsResult_t *data, bool io_fail) {
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
		lua_pushboolean(L, data->m_bSuccess);
		lua_setfield(L, -2, "m_bSuccess");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<EquippedProfileItems_t>::Result(EquippedProfileItems_t *data, bool io_fail) {
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
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<FriendsEnumerateFollowingList_t>::Result(FriendsEnumerateFollowingList_t *data, bool io_fail) {
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
		lua_createtable(L, 0, 4);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		lua_createtable(L, 50, 0);
		for(decltype(50) i = 0; i < 50; i++) {
			luasteam::pushuint64(L, data->m_rgSteamID[i].ConvertToUint64());
			lua_rawseti(L, -2, i+1);
		}
		lua_setfield(L, -2, "m_rgSteamID");
		lua_pushinteger(L, data->m_nResultsReturned);
		lua_setfield(L, -2, "m_nResultsReturned");
		lua_pushinteger(L, data->m_nTotalResultCount);
		lua_setfield(L, -2, "m_nTotalResultCount");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<FriendsGetFollowerCount_t>::Result(FriendsGetFollowerCount_t *data, bool io_fail) {
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
		lua_createtable(L, 0, 3);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		luasteam::pushuint64(L, data->m_steamID.ConvertToUint64());
		lua_setfield(L, -2, "m_steamID");
		lua_pushinteger(L, data->m_nCount);
		lua_setfield(L, -2, "m_nCount");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<FriendsIsFollowing_t>::Result(FriendsIsFollowing_t *data, bool io_fail) {
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
		lua_createtable(L, 0, 3);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		luasteam::pushuint64(L, data->m_steamID.ConvertToUint64());
		lua_setfield(L, -2, "m_steamID");
		lua_pushboolean(L, data->m_bIsFollowing);
		lua_setfield(L, -2, "m_bIsFollowing");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<JoinClanChatRoomCompletionResult_t>::Result(JoinClanChatRoomCompletionResult_t *data, bool io_fail) {
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
		lua_createtable(L, 0, 2);
		luasteam::pushuint64(L, data->m_steamIDClanChat.ConvertToUint64());
		lua_setfield(L, -2, "m_steamIDClanChat");
		lua_pushinteger(L, data->m_eChatRoomEnterResponse);
		lua_setfield(L, -2, "m_eChatRoomEnterResponse");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

// In C++:
// const char * GetPersonaName();
// In Lua:
// str Friends.GetPersonaName()
static int luasteam_Friends_GetPersonaName(lua_State *L) {
	auto *iface = SteamFriends();
	const char * __ret = iface->GetPersonaName();
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// EPersonaState GetPersonaState();
// In Lua:
// int Friends.GetPersonaState()
static int luasteam_Friends_GetPersonaState(lua_State *L) {
	auto *iface = SteamFriends();
	EPersonaState __ret = iface->GetPersonaState();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// int GetFriendCount(int iFriendFlags);
// In Lua:
// int Friends.GetFriendCount(iFriendFlags: int)
static int luasteam_Friends_GetFriendCount(lua_State *L) {
	auto *iface = SteamFriends();
	int iFriendFlags = static_cast<int>(luaL_checkint(L, 1));
	int __ret = iface->GetFriendCount(iFriendFlags);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// CSteamID GetFriendByIndex(int iFriend, int iFriendFlags);
// In Lua:
// uint64 Friends.GetFriendByIndex(iFriend: int, iFriendFlags: int)
static int luasteam_Friends_GetFriendByIndex(lua_State *L) {
	auto *iface = SteamFriends();
	int iFriend = static_cast<int>(luaL_checkint(L, 1));
	int iFriendFlags = static_cast<int>(luaL_checkint(L, 2));
	CSteamID __ret = iface->GetFriendByIndex(iFriend, iFriendFlags);
	luasteam::pushuint64(L, __ret.ConvertToUint64());
	return 1;
}

// In C++:
// EFriendRelationship GetFriendRelationship(CSteamID steamIDFriend);
// In Lua:
// int Friends.GetFriendRelationship(steamIDFriend: uint64)
static int luasteam_Friends_GetFriendRelationship(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
	EFriendRelationship __ret = iface->GetFriendRelationship(steamIDFriend);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// EPersonaState GetFriendPersonaState(CSteamID steamIDFriend);
// In Lua:
// int Friends.GetFriendPersonaState(steamIDFriend: uint64)
static int luasteam_Friends_GetFriendPersonaState(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
	EPersonaState __ret = iface->GetFriendPersonaState(steamIDFriend);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// const char * GetFriendPersonaName(CSteamID steamIDFriend);
// In Lua:
// str Friends.GetFriendPersonaName(steamIDFriend: uint64)
static int luasteam_Friends_GetFriendPersonaName(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
	const char * __ret = iface->GetFriendPersonaName(steamIDFriend);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// bool GetFriendGamePlayed(CSteamID steamIDFriend, FriendGameInfo_t * pFriendGameInfo);
// In Lua:
// (bool, pFriendGameInfo: FriendGameInfo_t) Friends.GetFriendGamePlayed(steamIDFriend: uint64)
static int luasteam_Friends_GetFriendGamePlayed(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
	FriendGameInfo_t pFriendGameInfo;
	bool __ret = iface->GetFriendGamePlayed(steamIDFriend, &pFriendGameInfo);
	lua_pushboolean(L, __ret);
	luasteam::push_FriendGameInfo_t(L, pFriendGameInfo);
	return 2;
}

// In C++:
// const char * GetFriendPersonaNameHistory(CSteamID steamIDFriend, int iPersonaName);
// In Lua:
// str Friends.GetFriendPersonaNameHistory(steamIDFriend: uint64, iPersonaName: int)
static int luasteam_Friends_GetFriendPersonaNameHistory(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
	int iPersonaName = static_cast<int>(luaL_checkint(L, 2));
	const char * __ret = iface->GetFriendPersonaNameHistory(steamIDFriend, iPersonaName);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// int GetFriendSteamLevel(CSteamID steamIDFriend);
// In Lua:
// int Friends.GetFriendSteamLevel(steamIDFriend: uint64)
static int luasteam_Friends_GetFriendSteamLevel(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
	int __ret = iface->GetFriendSteamLevel(steamIDFriend);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// const char * GetPlayerNickname(CSteamID steamIDPlayer);
// In Lua:
// str Friends.GetPlayerNickname(steamIDPlayer: uint64)
static int luasteam_Friends_GetPlayerNickname(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDPlayer(luasteam::checkuint64(L, 1));
	const char * __ret = iface->GetPlayerNickname(steamIDPlayer);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// int GetFriendsGroupCount();
// In Lua:
// int Friends.GetFriendsGroupCount()
static int luasteam_Friends_GetFriendsGroupCount(lua_State *L) {
	auto *iface = SteamFriends();
	int __ret = iface->GetFriendsGroupCount();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// FriendsGroupID_t GetFriendsGroupIDByIndex(int iFG);
// In Lua:
// int Friends.GetFriendsGroupIDByIndex(iFG: int)
static int luasteam_Friends_GetFriendsGroupIDByIndex(lua_State *L) {
	auto *iface = SteamFriends();
	int iFG = static_cast<int>(luaL_checkint(L, 1));
	FriendsGroupID_t __ret = iface->GetFriendsGroupIDByIndex(iFG);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// const char * GetFriendsGroupName(FriendsGroupID_t friendsGroupID);
// In Lua:
// str Friends.GetFriendsGroupName(friendsGroupID: int)
static int luasteam_Friends_GetFriendsGroupName(lua_State *L) {
	auto *iface = SteamFriends();
	FriendsGroupID_t friendsGroupID = static_cast<FriendsGroupID_t>(luaL_checkint(L, 1));
	const char * __ret = iface->GetFriendsGroupName(friendsGroupID);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// int GetFriendsGroupMembersCount(FriendsGroupID_t friendsGroupID);
// In Lua:
// int Friends.GetFriendsGroupMembersCount(friendsGroupID: int)
static int luasteam_Friends_GetFriendsGroupMembersCount(lua_State *L) {
	auto *iface = SteamFriends();
	FriendsGroupID_t friendsGroupID = static_cast<FriendsGroupID_t>(luaL_checkint(L, 1));
	int __ret = iface->GetFriendsGroupMembersCount(friendsGroupID);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// void GetFriendsGroupMembersList(FriendsGroupID_t friendsGroupID, CSteamID * pOutSteamIDMembers, int nMembersCount);
// In Lua:
// pOutSteamIDMembers: uint64[] Friends.GetFriendsGroupMembersList(friendsGroupID: int, nMembersCount: int)
static int luasteam_Friends_GetFriendsGroupMembersList(lua_State *L) {
	auto *iface = SteamFriends();
	FriendsGroupID_t friendsGroupID = static_cast<FriendsGroupID_t>(luaL_checkint(L, 1));
	int nMembersCount = luaL_checkint(L, 2);
	std::vector<CSteamID> pOutSteamIDMembers(nMembersCount);
	iface->GetFriendsGroupMembersList(friendsGroupID, pOutSteamIDMembers.data(), nMembersCount);
	lua_createtable(L, nMembersCount, 0);
	for(decltype(nMembersCount) i = 0; i < nMembersCount; i++) {
		luasteam::pushuint64(L, pOutSteamIDMembers[i].ConvertToUint64());
		lua_rawseti(L, -2, i+1);
	}
	return 1;
}

// In C++:
// bool HasFriend(CSteamID steamIDFriend, int iFriendFlags);
// In Lua:
// bool Friends.HasFriend(steamIDFriend: uint64, iFriendFlags: int)
static int luasteam_Friends_HasFriend(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
	int iFriendFlags = static_cast<int>(luaL_checkint(L, 2));
	bool __ret = iface->HasFriend(steamIDFriend, iFriendFlags);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// int GetClanCount();
// In Lua:
// int Friends.GetClanCount()
static int luasteam_Friends_GetClanCount(lua_State *L) {
	auto *iface = SteamFriends();
	int __ret = iface->GetClanCount();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// CSteamID GetClanByIndex(int iClan);
// In Lua:
// uint64 Friends.GetClanByIndex(iClan: int)
static int luasteam_Friends_GetClanByIndex(lua_State *L) {
	auto *iface = SteamFriends();
	int iClan = static_cast<int>(luaL_checkint(L, 1));
	CSteamID __ret = iface->GetClanByIndex(iClan);
	luasteam::pushuint64(L, __ret.ConvertToUint64());
	return 1;
}

// In C++:
// const char * GetClanName(CSteamID steamIDClan);
// In Lua:
// str Friends.GetClanName(steamIDClan: uint64)
static int luasteam_Friends_GetClanName(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDClan(luasteam::checkuint64(L, 1));
	const char * __ret = iface->GetClanName(steamIDClan);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// const char * GetClanTag(CSteamID steamIDClan);
// In Lua:
// str Friends.GetClanTag(steamIDClan: uint64)
static int luasteam_Friends_GetClanTag(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDClan(luasteam::checkuint64(L, 1));
	const char * __ret = iface->GetClanTag(steamIDClan);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// bool GetClanActivityCounts(CSteamID steamIDClan, int * pnOnline, int * pnInGame, int * pnChatting);
// In Lua:
// (bool, pnOnline: int, pnInGame: int, pnChatting: int) Friends.GetClanActivityCounts(steamIDClan: uint64)
static int luasteam_Friends_GetClanActivityCounts(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDClan(luasteam::checkuint64(L, 1));
	int pnOnline;
	int pnInGame;
	int pnChatting;
	bool __ret = iface->GetClanActivityCounts(steamIDClan, &pnOnline, &pnInGame, &pnChatting);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pnOnline);
	lua_pushinteger(L, pnInGame);
	lua_pushinteger(L, pnChatting);
	return 4;
}

// In C++:
// SteamAPICall_t DownloadClanActivityCounts(CSteamID * psteamIDClans, int cClansToRequest);
// In Lua:
// (uint64, psteamIDClans: uint64[]) Friends.DownloadClanActivityCounts(cClansToRequest: int, callback: function)
static int luasteam_Friends_DownloadClanActivityCounts(lua_State *L) {
	auto *iface = SteamFriends();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	int cClansToRequest = luaL_checkint(L, 1);
	std::vector<CSteamID> psteamIDClans(cClansToRequest);
	SteamAPICall_t __ret = iface->DownloadClanActivityCounts(psteamIDClans.data(), cClansToRequest);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<DownloadClanActivityCountsResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<DownloadClanActivityCountsResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	lua_createtable(L, cClansToRequest, 0);
	for(decltype(cClansToRequest) i = 0; i < cClansToRequest; i++) {
		luasteam::pushuint64(L, psteamIDClans[i].ConvertToUint64());
		lua_rawseti(L, -2, i+1);
	}
	return 2;
}

// In C++:
// int GetFriendCountFromSource(CSteamID steamIDSource);
// In Lua:
// int Friends.GetFriendCountFromSource(steamIDSource: uint64)
static int luasteam_Friends_GetFriendCountFromSource(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDSource(luasteam::checkuint64(L, 1));
	int __ret = iface->GetFriendCountFromSource(steamIDSource);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// CSteamID GetFriendFromSourceByIndex(CSteamID steamIDSource, int iFriend);
// In Lua:
// uint64 Friends.GetFriendFromSourceByIndex(steamIDSource: uint64, iFriend: int)
static int luasteam_Friends_GetFriendFromSourceByIndex(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDSource(luasteam::checkuint64(L, 1));
	int iFriend = static_cast<int>(luaL_checkint(L, 2));
	CSteamID __ret = iface->GetFriendFromSourceByIndex(steamIDSource, iFriend);
	luasteam::pushuint64(L, __ret.ConvertToUint64());
	return 1;
}

// In C++:
// bool IsUserInSource(CSteamID steamIDUser, CSteamID steamIDSource);
// In Lua:
// bool Friends.IsUserInSource(steamIDUser: uint64, steamIDSource: uint64)
static int luasteam_Friends_IsUserInSource(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDUser(luasteam::checkuint64(L, 1));
	CSteamID steamIDSource(luasteam::checkuint64(L, 2));
	bool __ret = iface->IsUserInSource(steamIDUser, steamIDSource);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// void SetInGameVoiceSpeaking(CSteamID steamIDUser, bool bSpeaking);
// In Lua:
// Friends.SetInGameVoiceSpeaking(steamIDUser: uint64, bSpeaking: bool)
static int luasteam_Friends_SetInGameVoiceSpeaking(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDUser(luasteam::checkuint64(L, 1));
	bool bSpeaking = lua_toboolean(L, 2);
	iface->SetInGameVoiceSpeaking(steamIDUser, bSpeaking);
	return 0;
}

// In C++:
// void ActivateGameOverlay(const char * pchDialog);
// In Lua:
// Friends.ActivateGameOverlay(pchDialog: str)
static int luasteam_Friends_ActivateGameOverlay(lua_State *L) {
	auto *iface = SteamFriends();
	const char *pchDialog = luaL_checkstring(L, 1);
	iface->ActivateGameOverlay(pchDialog);
	return 0;
}

// In C++:
// void ActivateGameOverlayToUser(const char * pchDialog, CSteamID steamID);
// In Lua:
// Friends.ActivateGameOverlayToUser(pchDialog: str, steamID: uint64)
static int luasteam_Friends_ActivateGameOverlayToUser(lua_State *L) {
	auto *iface = SteamFriends();
	const char *pchDialog = luaL_checkstring(L, 1);
	CSteamID steamID(luasteam::checkuint64(L, 2));
	iface->ActivateGameOverlayToUser(pchDialog, steamID);
	return 0;
}

// In C++:
// void ActivateGameOverlayToWebPage(const char * pchURL, EActivateGameOverlayToWebPageMode eMode);
// In Lua:
// Friends.ActivateGameOverlayToWebPage(pchURL: str, eMode: int)
static int luasteam_Friends_ActivateGameOverlayToWebPage(lua_State *L) {
	auto *iface = SteamFriends();
	const char *pchURL = luaL_checkstring(L, 1);
	EActivateGameOverlayToWebPageMode eMode = static_cast<EActivateGameOverlayToWebPageMode>(luaL_checkint(L, 2));
	iface->ActivateGameOverlayToWebPage(pchURL, eMode);
	return 0;
}

// In C++:
// void ActivateGameOverlayToStore(AppId_t nAppID, EOverlayToStoreFlag eFlag);
// In Lua:
// Friends.ActivateGameOverlayToStore(nAppID: int, eFlag: int)
static int luasteam_Friends_ActivateGameOverlayToStore(lua_State *L) {
	auto *iface = SteamFriends();
	AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
	EOverlayToStoreFlag eFlag = static_cast<EOverlayToStoreFlag>(luaL_checkint(L, 2));
	iface->ActivateGameOverlayToStore(nAppID, eFlag);
	return 0;
}

// In C++:
// void SetPlayedWith(CSteamID steamIDUserPlayedWith);
// In Lua:
// Friends.SetPlayedWith(steamIDUserPlayedWith: uint64)
static int luasteam_Friends_SetPlayedWith(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDUserPlayedWith(luasteam::checkuint64(L, 1));
	iface->SetPlayedWith(steamIDUserPlayedWith);
	return 0;
}

// In C++:
// void ActivateGameOverlayInviteDialog(CSteamID steamIDLobby);
// In Lua:
// Friends.ActivateGameOverlayInviteDialog(steamIDLobby: uint64)
static int luasteam_Friends_ActivateGameOverlayInviteDialog(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
	iface->ActivateGameOverlayInviteDialog(steamIDLobby);
	return 0;
}

// In C++:
// int GetSmallFriendAvatar(CSteamID steamIDFriend);
// In Lua:
// int Friends.GetSmallFriendAvatar(steamIDFriend: uint64)
static int luasteam_Friends_GetSmallFriendAvatar(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
	int __ret = iface->GetSmallFriendAvatar(steamIDFriend);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// int GetMediumFriendAvatar(CSteamID steamIDFriend);
// In Lua:
// int Friends.GetMediumFriendAvatar(steamIDFriend: uint64)
static int luasteam_Friends_GetMediumFriendAvatar(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
	int __ret = iface->GetMediumFriendAvatar(steamIDFriend);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// int GetLargeFriendAvatar(CSteamID steamIDFriend);
// In Lua:
// int Friends.GetLargeFriendAvatar(steamIDFriend: uint64)
static int luasteam_Friends_GetLargeFriendAvatar(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
	int __ret = iface->GetLargeFriendAvatar(steamIDFriend);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool RequestUserInformation(CSteamID steamIDUser, bool bRequireNameOnly);
// In Lua:
// bool Friends.RequestUserInformation(steamIDUser: uint64, bRequireNameOnly: bool)
static int luasteam_Friends_RequestUserInformation(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDUser(luasteam::checkuint64(L, 1));
	bool bRequireNameOnly = lua_toboolean(L, 2);
	bool __ret = iface->RequestUserInformation(steamIDUser, bRequireNameOnly);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t RequestClanOfficerList(CSteamID steamIDClan);
// In Lua:
// uint64 Friends.RequestClanOfficerList(steamIDClan: uint64, callback: function)
static int luasteam_Friends_RequestClanOfficerList(lua_State *L) {
	auto *iface = SteamFriends();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	CSteamID steamIDClan(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = iface->RequestClanOfficerList(steamIDClan);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<ClanOfficerListResponse_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<ClanOfficerListResponse_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// CSteamID GetClanOwner(CSteamID steamIDClan);
// In Lua:
// uint64 Friends.GetClanOwner(steamIDClan: uint64)
static int luasteam_Friends_GetClanOwner(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDClan(luasteam::checkuint64(L, 1));
	CSteamID __ret = iface->GetClanOwner(steamIDClan);
	luasteam::pushuint64(L, __ret.ConvertToUint64());
	return 1;
}

// In C++:
// int GetClanOfficerCount(CSteamID steamIDClan);
// In Lua:
// int Friends.GetClanOfficerCount(steamIDClan: uint64)
static int luasteam_Friends_GetClanOfficerCount(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDClan(luasteam::checkuint64(L, 1));
	int __ret = iface->GetClanOfficerCount(steamIDClan);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// CSteamID GetClanOfficerByIndex(CSteamID steamIDClan, int iOfficer);
// In Lua:
// uint64 Friends.GetClanOfficerByIndex(steamIDClan: uint64, iOfficer: int)
static int luasteam_Friends_GetClanOfficerByIndex(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDClan(luasteam::checkuint64(L, 1));
	int iOfficer = static_cast<int>(luaL_checkint(L, 2));
	CSteamID __ret = iface->GetClanOfficerByIndex(steamIDClan, iOfficer);
	luasteam::pushuint64(L, __ret.ConvertToUint64());
	return 1;
}

// In C++:
// bool SetRichPresence(const char * pchKey, const char * pchValue);
// In Lua:
// bool Friends.SetRichPresence(pchKey: str, pchValue: str)
static int luasteam_Friends_SetRichPresence(lua_State *L) {
	auto *iface = SteamFriends();
	const char *pchKey = luaL_checkstring(L, 1);
	const char *pchValue = luaL_checkstring(L, 2);
	bool __ret = iface->SetRichPresence(pchKey, pchValue);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// void ClearRichPresence();
// In Lua:
// Friends.ClearRichPresence()
static int luasteam_Friends_ClearRichPresence(lua_State *L) {
	auto *iface = SteamFriends();
	iface->ClearRichPresence();
	return 0;
}

// In C++:
// const char * GetFriendRichPresence(CSteamID steamIDFriend, const char * pchKey);
// In Lua:
// str Friends.GetFriendRichPresence(steamIDFriend: uint64, pchKey: str)
static int luasteam_Friends_GetFriendRichPresence(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
	const char *pchKey = luaL_checkstring(L, 2);
	const char * __ret = iface->GetFriendRichPresence(steamIDFriend, pchKey);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// int GetFriendRichPresenceKeyCount(CSteamID steamIDFriend);
// In Lua:
// int Friends.GetFriendRichPresenceKeyCount(steamIDFriend: uint64)
static int luasteam_Friends_GetFriendRichPresenceKeyCount(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
	int __ret = iface->GetFriendRichPresenceKeyCount(steamIDFriend);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// const char * GetFriendRichPresenceKeyByIndex(CSteamID steamIDFriend, int iKey);
// In Lua:
// str Friends.GetFriendRichPresenceKeyByIndex(steamIDFriend: uint64, iKey: int)
static int luasteam_Friends_GetFriendRichPresenceKeyByIndex(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
	int iKey = static_cast<int>(luaL_checkint(L, 2));
	const char * __ret = iface->GetFriendRichPresenceKeyByIndex(steamIDFriend, iKey);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// void RequestFriendRichPresence(CSteamID steamIDFriend);
// In Lua:
// Friends.RequestFriendRichPresence(steamIDFriend: uint64)
static int luasteam_Friends_RequestFriendRichPresence(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
	iface->RequestFriendRichPresence(steamIDFriend);
	return 0;
}

// In C++:
// bool InviteUserToGame(CSteamID steamIDFriend, const char * pchConnectString);
// In Lua:
// bool Friends.InviteUserToGame(steamIDFriend: uint64, pchConnectString: str)
static int luasteam_Friends_InviteUserToGame(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
	const char *pchConnectString = luaL_checkstring(L, 2);
	bool __ret = iface->InviteUserToGame(steamIDFriend, pchConnectString);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// int GetCoplayFriendCount();
// In Lua:
// int Friends.GetCoplayFriendCount()
static int luasteam_Friends_GetCoplayFriendCount(lua_State *L) {
	auto *iface = SteamFriends();
	int __ret = iface->GetCoplayFriendCount();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// CSteamID GetCoplayFriend(int iCoplayFriend);
// In Lua:
// uint64 Friends.GetCoplayFriend(iCoplayFriend: int)
static int luasteam_Friends_GetCoplayFriend(lua_State *L) {
	auto *iface = SteamFriends();
	int iCoplayFriend = static_cast<int>(luaL_checkint(L, 1));
	CSteamID __ret = iface->GetCoplayFriend(iCoplayFriend);
	luasteam::pushuint64(L, __ret.ConvertToUint64());
	return 1;
}

// In C++:
// int GetFriendCoplayTime(CSteamID steamIDFriend);
// In Lua:
// int Friends.GetFriendCoplayTime(steamIDFriend: uint64)
static int luasteam_Friends_GetFriendCoplayTime(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
	int __ret = iface->GetFriendCoplayTime(steamIDFriend);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// AppId_t GetFriendCoplayGame(CSteamID steamIDFriend);
// In Lua:
// int Friends.GetFriendCoplayGame(steamIDFriend: uint64)
static int luasteam_Friends_GetFriendCoplayGame(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
	AppId_t __ret = iface->GetFriendCoplayGame(steamIDFriend);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t JoinClanChatRoom(CSteamID steamIDClan);
// In Lua:
// uint64 Friends.JoinClanChatRoom(steamIDClan: uint64, callback: function)
static int luasteam_Friends_JoinClanChatRoom(lua_State *L) {
	auto *iface = SteamFriends();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	CSteamID steamIDClan(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = iface->JoinClanChatRoom(steamIDClan);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<JoinClanChatRoomCompletionResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<JoinClanChatRoomCompletionResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// bool LeaveClanChatRoom(CSteamID steamIDClan);
// In Lua:
// bool Friends.LeaveClanChatRoom(steamIDClan: uint64)
static int luasteam_Friends_LeaveClanChatRoom(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDClan(luasteam::checkuint64(L, 1));
	bool __ret = iface->LeaveClanChatRoom(steamIDClan);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// int GetClanChatMemberCount(CSteamID steamIDClan);
// In Lua:
// int Friends.GetClanChatMemberCount(steamIDClan: uint64)
static int luasteam_Friends_GetClanChatMemberCount(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDClan(luasteam::checkuint64(L, 1));
	int __ret = iface->GetClanChatMemberCount(steamIDClan);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// CSteamID GetChatMemberByIndex(CSteamID steamIDClan, int iUser);
// In Lua:
// uint64 Friends.GetChatMemberByIndex(steamIDClan: uint64, iUser: int)
static int luasteam_Friends_GetChatMemberByIndex(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDClan(luasteam::checkuint64(L, 1));
	int iUser = static_cast<int>(luaL_checkint(L, 2));
	CSteamID __ret = iface->GetChatMemberByIndex(steamIDClan, iUser);
	luasteam::pushuint64(L, __ret.ConvertToUint64());
	return 1;
}

// In C++:
// bool SendClanChatMessage(CSteamID steamIDClanChat, const char * pchText);
// In Lua:
// bool Friends.SendClanChatMessage(steamIDClanChat: uint64, pchText: str)
static int luasteam_Friends_SendClanChatMessage(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDClanChat(luasteam::checkuint64(L, 1));
	const char *pchText = luaL_checkstring(L, 2);
	bool __ret = iface->SendClanChatMessage(steamIDClanChat, pchText);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// int GetClanChatMessage(CSteamID steamIDClanChat, int iMessage, void * prgchText, int cchTextMax, EChatEntryType * peChatEntryType, CSteamID * psteamidChatter);
// In Lua:
// (int, prgchText: str, peChatEntryType: int, psteamidChatter: uint64) Friends.GetClanChatMessage(steamIDClanChat: uint64, iMessage: int, cchTextMax: int)
static int luasteam_Friends_GetClanChatMessage(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDClanChat(luasteam::checkuint64(L, 1));
	int iMessage = static_cast<int>(luaL_checkint(L, 2));
	int cchTextMax = luaL_checkint(L, 3);
	std::vector<unsigned char> prgchText(cchTextMax);
	EChatEntryType peChatEntryType;
	CSteamID psteamidChatter;
	int __ret = iface->GetClanChatMessage(steamIDClanChat, iMessage, prgchText.data(), cchTextMax, &peChatEntryType, &psteamidChatter);
	lua_pushinteger(L, __ret);
	lua_pushlstring(L, reinterpret_cast<const char*>(prgchText.data()), __ret);
	lua_pushinteger(L, peChatEntryType);
	luasteam::pushuint64(L, psteamidChatter.ConvertToUint64());
	return 4;
}

// In C++:
// bool IsClanChatAdmin(CSteamID steamIDClanChat, CSteamID steamIDUser);
// In Lua:
// bool Friends.IsClanChatAdmin(steamIDClanChat: uint64, steamIDUser: uint64)
static int luasteam_Friends_IsClanChatAdmin(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDClanChat(luasteam::checkuint64(L, 1));
	CSteamID steamIDUser(luasteam::checkuint64(L, 2));
	bool __ret = iface->IsClanChatAdmin(steamIDClanChat, steamIDUser);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool IsClanChatWindowOpenInSteam(CSteamID steamIDClanChat);
// In Lua:
// bool Friends.IsClanChatWindowOpenInSteam(steamIDClanChat: uint64)
static int luasteam_Friends_IsClanChatWindowOpenInSteam(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDClanChat(luasteam::checkuint64(L, 1));
	bool __ret = iface->IsClanChatWindowOpenInSteam(steamIDClanChat);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool OpenClanChatWindowInSteam(CSteamID steamIDClanChat);
// In Lua:
// bool Friends.OpenClanChatWindowInSteam(steamIDClanChat: uint64)
static int luasteam_Friends_OpenClanChatWindowInSteam(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDClanChat(luasteam::checkuint64(L, 1));
	bool __ret = iface->OpenClanChatWindowInSteam(steamIDClanChat);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool CloseClanChatWindowInSteam(CSteamID steamIDClanChat);
// In Lua:
// bool Friends.CloseClanChatWindowInSteam(steamIDClanChat: uint64)
static int luasteam_Friends_CloseClanChatWindowInSteam(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDClanChat(luasteam::checkuint64(L, 1));
	bool __ret = iface->CloseClanChatWindowInSteam(steamIDClanChat);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetListenForFriendsMessages(bool bInterceptEnabled);
// In Lua:
// bool Friends.SetListenForFriendsMessages(bInterceptEnabled: bool)
static int luasteam_Friends_SetListenForFriendsMessages(lua_State *L) {
	auto *iface = SteamFriends();
	bool bInterceptEnabled = lua_toboolean(L, 1);
	bool __ret = iface->SetListenForFriendsMessages(bInterceptEnabled);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool ReplyToFriendMessage(CSteamID steamIDFriend, const char * pchMsgToSend);
// In Lua:
// bool Friends.ReplyToFriendMessage(steamIDFriend: uint64, pchMsgToSend: str)
static int luasteam_Friends_ReplyToFriendMessage(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
	const char *pchMsgToSend = luaL_checkstring(L, 2);
	bool __ret = iface->ReplyToFriendMessage(steamIDFriend, pchMsgToSend);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// int GetFriendMessage(CSteamID steamIDFriend, int iMessageID, void * pvData, int cubData, EChatEntryType * peChatEntryType);
// In Lua:
// (int, pvData: str, peChatEntryType: int) Friends.GetFriendMessage(steamIDFriend: uint64, iMessageID: int, cubData: int)
static int luasteam_Friends_GetFriendMessage(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
	int iMessageID = static_cast<int>(luaL_checkint(L, 2));
	int cubData = luaL_checkint(L, 3);
	std::vector<unsigned char> pvData(cubData);
	EChatEntryType peChatEntryType;
	int __ret = iface->GetFriendMessage(steamIDFriend, iMessageID, pvData.data(), cubData, &peChatEntryType);
	lua_pushinteger(L, __ret);
	lua_pushlstring(L, reinterpret_cast<const char*>(pvData.data()), __ret);
	lua_pushinteger(L, peChatEntryType);
	return 3;
}

// In C++:
// SteamAPICall_t GetFollowerCount(CSteamID steamID);
// In Lua:
// uint64 Friends.GetFollowerCount(steamID: uint64, callback: function)
static int luasteam_Friends_GetFollowerCount(lua_State *L) {
	auto *iface = SteamFriends();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	CSteamID steamID(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = iface->GetFollowerCount(steamID);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<FriendsGetFollowerCount_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<FriendsGetFollowerCount_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t IsFollowing(CSteamID steamID);
// In Lua:
// uint64 Friends.IsFollowing(steamID: uint64, callback: function)
static int luasteam_Friends_IsFollowing(lua_State *L) {
	auto *iface = SteamFriends();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	CSteamID steamID(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = iface->IsFollowing(steamID);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<FriendsIsFollowing_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<FriendsIsFollowing_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t EnumerateFollowingList(uint32 unStartIndex);
// In Lua:
// uint64 Friends.EnumerateFollowingList(unStartIndex: int, callback: function)
static int luasteam_Friends_EnumerateFollowingList(lua_State *L) {
	auto *iface = SteamFriends();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	uint32 unStartIndex = static_cast<uint32>(luaL_checkint(L, 1));
	SteamAPICall_t __ret = iface->EnumerateFollowingList(unStartIndex);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<FriendsEnumerateFollowingList_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<FriendsEnumerateFollowingList_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// bool IsClanPublic(CSteamID steamIDClan);
// In Lua:
// bool Friends.IsClanPublic(steamIDClan: uint64)
static int luasteam_Friends_IsClanPublic(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDClan(luasteam::checkuint64(L, 1));
	bool __ret = iface->IsClanPublic(steamIDClan);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool IsClanOfficialGameGroup(CSteamID steamIDClan);
// In Lua:
// bool Friends.IsClanOfficialGameGroup(steamIDClan: uint64)
static int luasteam_Friends_IsClanOfficialGameGroup(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDClan(luasteam::checkuint64(L, 1));
	bool __ret = iface->IsClanOfficialGameGroup(steamIDClan);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// int GetNumChatsWithUnreadPriorityMessages();
// In Lua:
// int Friends.GetNumChatsWithUnreadPriorityMessages()
static int luasteam_Friends_GetNumChatsWithUnreadPriorityMessages(lua_State *L) {
	auto *iface = SteamFriends();
	int __ret = iface->GetNumChatsWithUnreadPriorityMessages();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// void ActivateGameOverlayRemotePlayTogetherInviteDialog(CSteamID steamIDLobby);
// In Lua:
// Friends.ActivateGameOverlayRemotePlayTogetherInviteDialog(steamIDLobby: uint64)
static int luasteam_Friends_ActivateGameOverlayRemotePlayTogetherInviteDialog(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
	iface->ActivateGameOverlayRemotePlayTogetherInviteDialog(steamIDLobby);
	return 0;
}

// In C++:
// bool RegisterProtocolInOverlayBrowser(const char * pchProtocol);
// In Lua:
// bool Friends.RegisterProtocolInOverlayBrowser(pchProtocol: str)
static int luasteam_Friends_RegisterProtocolInOverlayBrowser(lua_State *L) {
	auto *iface = SteamFriends();
	const char *pchProtocol = luaL_checkstring(L, 1);
	bool __ret = iface->RegisterProtocolInOverlayBrowser(pchProtocol);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// void ActivateGameOverlayInviteDialogConnectString(const char * pchConnectString);
// In Lua:
// Friends.ActivateGameOverlayInviteDialogConnectString(pchConnectString: str)
static int luasteam_Friends_ActivateGameOverlayInviteDialogConnectString(lua_State *L) {
	auto *iface = SteamFriends();
	const char *pchConnectString = luaL_checkstring(L, 1);
	iface->ActivateGameOverlayInviteDialogConnectString(pchConnectString);
	return 0;
}

// In C++:
// SteamAPICall_t RequestEquippedProfileItems(CSteamID steamID);
// In Lua:
// uint64 Friends.RequestEquippedProfileItems(steamID: uint64, callback: function)
static int luasteam_Friends_RequestEquippedProfileItems(lua_State *L) {
	auto *iface = SteamFriends();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	CSteamID steamID(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = iface->RequestEquippedProfileItems(steamID);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<EquippedProfileItems_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<EquippedProfileItems_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// bool BHasEquippedProfileItem(CSteamID steamID, ECommunityProfileItemType itemType);
// In Lua:
// bool Friends.BHasEquippedProfileItem(steamID: uint64, itemType: int)
static int luasteam_Friends_BHasEquippedProfileItem(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamID(luasteam::checkuint64(L, 1));
	ECommunityProfileItemType itemType = static_cast<ECommunityProfileItemType>(luaL_checkint(L, 2));
	bool __ret = iface->BHasEquippedProfileItem(steamID, itemType);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// const char * GetProfileItemPropertyString(CSteamID steamID, ECommunityProfileItemType itemType, ECommunityProfileItemProperty prop);
// In Lua:
// str Friends.GetProfileItemPropertyString(steamID: uint64, itemType: int, prop: int)
static int luasteam_Friends_GetProfileItemPropertyString(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamID(luasteam::checkuint64(L, 1));
	ECommunityProfileItemType itemType = static_cast<ECommunityProfileItemType>(luaL_checkint(L, 2));
	ECommunityProfileItemProperty prop = static_cast<ECommunityProfileItemProperty>(luaL_checkint(L, 3));
	const char * __ret = iface->GetProfileItemPropertyString(steamID, itemType, prop);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// uint32 GetProfileItemPropertyUint(CSteamID steamID, ECommunityProfileItemType itemType, ECommunityProfileItemProperty prop);
// In Lua:
// int Friends.GetProfileItemPropertyUint(steamID: uint64, itemType: int, prop: int)
static int luasteam_Friends_GetProfileItemPropertyUint(lua_State *L) {
	auto *iface = SteamFriends();
	CSteamID steamID(luasteam::checkuint64(L, 1));
	ECommunityProfileItemType itemType = static_cast<ECommunityProfileItemType>(luaL_checkint(L, 2));
	ECommunityProfileItemProperty prop = static_cast<ECommunityProfileItemProperty>(luaL_checkint(L, 3));
	uint32 __ret = iface->GetProfileItemPropertyUint(steamID, itemType, prop);
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
