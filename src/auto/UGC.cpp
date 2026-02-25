#include "auto.hpp"

namespace luasteam {

int UGC_ref = LUA_NOREF;

namespace {
class UGCCallbackListener {
private:
	STEAM_CALLBACK(UGCCallbackListener, OnSteamUGCQueryCompleted, SteamUGCQueryCompleted_t);
	STEAM_CALLBACK(UGCCallbackListener, OnSteamUGCRequestUGCDetailsResult, SteamUGCRequestUGCDetailsResult_t);
	STEAM_CALLBACK(UGCCallbackListener, OnCreateItemResult, CreateItemResult_t);
	STEAM_CALLBACK(UGCCallbackListener, OnSubmitItemUpdateResult, SubmitItemUpdateResult_t);
	STEAM_CALLBACK(UGCCallbackListener, OnItemInstalled, ItemInstalled_t);
	STEAM_CALLBACK(UGCCallbackListener, OnDownloadItemResult, DownloadItemResult_t);
	STEAM_CALLBACK(UGCCallbackListener, OnUserFavoriteItemsListChanged, UserFavoriteItemsListChanged_t);
	STEAM_CALLBACK(UGCCallbackListener, OnSetUserItemVoteResult, SetUserItemVoteResult_t);
	STEAM_CALLBACK(UGCCallbackListener, OnGetUserItemVoteResult, GetUserItemVoteResult_t);
	STEAM_CALLBACK(UGCCallbackListener, OnStartPlaytimeTrackingResult, StartPlaytimeTrackingResult_t);
	STEAM_CALLBACK(UGCCallbackListener, OnStopPlaytimeTrackingResult, StopPlaytimeTrackingResult_t);
	STEAM_CALLBACK(UGCCallbackListener, OnAddUGCDependencyResult, AddUGCDependencyResult_t);
	STEAM_CALLBACK(UGCCallbackListener, OnRemoveUGCDependencyResult, RemoveUGCDependencyResult_t);
	STEAM_CALLBACK(UGCCallbackListener, OnAddAppDependencyResult, AddAppDependencyResult_t);
	STEAM_CALLBACK(UGCCallbackListener, OnRemoveAppDependencyResult, RemoveAppDependencyResult_t);
	STEAM_CALLBACK(UGCCallbackListener, OnGetAppDependenciesResult, GetAppDependenciesResult_t);
	STEAM_CALLBACK(UGCCallbackListener, OnDeleteItemResult, DeleteItemResult_t);
	STEAM_CALLBACK(UGCCallbackListener, OnUserSubscribedItemsListChanged, UserSubscribedItemsListChanged_t);
	STEAM_CALLBACK(UGCCallbackListener, OnWorkshopEULAStatus, WorkshopEULAStatus_t);
};
void UGCCallbackListener::OnSteamUGCQueryCompleted(SteamUGCQueryCompleted_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
	lua_getfield(L, -1, "OnSteamUGCQueryCompleted");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamUGCQueryCompleted_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UGCCallbackListener::OnSteamUGCRequestUGCDetailsResult(SteamUGCRequestUGCDetailsResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
	lua_getfield(L, -1, "OnSteamUGCRequestUGCDetailsResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamUGCRequestUGCDetailsResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UGCCallbackListener::OnCreateItemResult(CreateItemResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
	lua_getfield(L, -1, "OnCreateItemResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_CreateItemResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UGCCallbackListener::OnSubmitItemUpdateResult(SubmitItemUpdateResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
	lua_getfield(L, -1, "OnSubmitItemUpdateResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SubmitItemUpdateResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UGCCallbackListener::OnItemInstalled(ItemInstalled_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
	lua_getfield(L, -1, "OnItemInstalled");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_ItemInstalled_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UGCCallbackListener::OnDownloadItemResult(DownloadItemResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
	lua_getfield(L, -1, "OnDownloadItemResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_DownloadItemResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UGCCallbackListener::OnUserFavoriteItemsListChanged(UserFavoriteItemsListChanged_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
	lua_getfield(L, -1, "OnUserFavoriteItemsListChanged");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_UserFavoriteItemsListChanged_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UGCCallbackListener::OnSetUserItemVoteResult(SetUserItemVoteResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
	lua_getfield(L, -1, "OnSetUserItemVoteResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SetUserItemVoteResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UGCCallbackListener::OnGetUserItemVoteResult(GetUserItemVoteResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
	lua_getfield(L, -1, "OnGetUserItemVoteResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_GetUserItemVoteResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UGCCallbackListener::OnStartPlaytimeTrackingResult(StartPlaytimeTrackingResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
	lua_getfield(L, -1, "OnStartPlaytimeTrackingResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_StartPlaytimeTrackingResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UGCCallbackListener::OnStopPlaytimeTrackingResult(StopPlaytimeTrackingResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
	lua_getfield(L, -1, "OnStopPlaytimeTrackingResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_StopPlaytimeTrackingResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UGCCallbackListener::OnAddUGCDependencyResult(AddUGCDependencyResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
	lua_getfield(L, -1, "OnAddUGCDependencyResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_AddUGCDependencyResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UGCCallbackListener::OnRemoveUGCDependencyResult(RemoveUGCDependencyResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
	lua_getfield(L, -1, "OnRemoveUGCDependencyResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_RemoveUGCDependencyResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UGCCallbackListener::OnAddAppDependencyResult(AddAppDependencyResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
	lua_getfield(L, -1, "OnAddAppDependencyResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_AddAppDependencyResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UGCCallbackListener::OnRemoveAppDependencyResult(RemoveAppDependencyResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
	lua_getfield(L, -1, "OnRemoveAppDependencyResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_RemoveAppDependencyResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UGCCallbackListener::OnGetAppDependenciesResult(GetAppDependenciesResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
	lua_getfield(L, -1, "OnGetAppDependenciesResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_GetAppDependenciesResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UGCCallbackListener::OnDeleteItemResult(DeleteItemResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
	lua_getfield(L, -1, "OnDeleteItemResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_DeleteItemResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UGCCallbackListener::OnUserSubscribedItemsListChanged(UserSubscribedItemsListChanged_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
	lua_getfield(L, -1, "OnUserSubscribedItemsListChanged");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_UserSubscribedItemsListChanged_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void UGCCallbackListener::OnWorkshopEULAStatus(WorkshopEULAStatus_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
	lua_getfield(L, -1, "OnWorkshopEULAStatus");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_WorkshopEULAStatus_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
UGCCallbackListener *UGC_listener = nullptr;
} // namespace

void init_UGC_auto(lua_State *L) { if (UGC_listener != nullptr) return; UGC_listener = new UGCCallbackListener(); }
void shutdown_UGC_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, UGC_ref);
	UGC_ref = LUA_NOREF;
	delete UGC_listener; UGC_listener = nullptr;
}

template <> void CallResultListener<AddAppDependencyResult_t>::Result(AddAppDependencyResult_t *data, bool io_fail) {
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
		luasteam::pushuint64(L, data->m_nPublishedFileId);
		lua_setfield(L, -2, "m_nPublishedFileId");
		lua_pushinteger(L, data->m_nAppID);
		lua_setfield(L, -2, "m_nAppID");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<AddUGCDependencyResult_t>::Result(AddUGCDependencyResult_t *data, bool io_fail) {
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
		luasteam::pushuint64(L, data->m_nPublishedFileId);
		lua_setfield(L, -2, "m_nPublishedFileId");
		luasteam::pushuint64(L, data->m_nChildPublishedFileId);
		lua_setfield(L, -2, "m_nChildPublishedFileId");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<CreateItemResult_t>::Result(CreateItemResult_t *data, bool io_fail) {
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
		luasteam::pushuint64(L, data->m_nPublishedFileId);
		lua_setfield(L, -2, "m_nPublishedFileId");
		lua_pushboolean(L, data->m_bUserNeedsToAcceptWorkshopLegalAgreement);
		lua_setfield(L, -2, "m_bUserNeedsToAcceptWorkshopLegalAgreement");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<DeleteItemResult_t>::Result(DeleteItemResult_t *data, bool io_fail) {
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
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		luasteam::pushuint64(L, data->m_nPublishedFileId);
		lua_setfield(L, -2, "m_nPublishedFileId");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<GetAppDependenciesResult_t>::Result(GetAppDependenciesResult_t *data, bool io_fail) {
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
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		luasteam::pushuint64(L, data->m_nPublishedFileId);
		lua_setfield(L, -2, "m_nPublishedFileId");
		lua_createtable(L, 32, 0);
		for(decltype(32) i = 0; i < 32; i++) {
			lua_pushinteger(L, data->m_rgAppIDs[i]);
			lua_rawseti(L, -2, i+1);
		}
		lua_setfield(L, -2, "m_rgAppIDs");
		lua_pushinteger(L, data->m_nNumAppDependencies);
		lua_setfield(L, -2, "m_nNumAppDependencies");
		lua_pushinteger(L, data->m_nTotalNumAppDependencies);
		lua_setfield(L, -2, "m_nTotalNumAppDependencies");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<GetUserItemVoteResult_t>::Result(GetUserItemVoteResult_t *data, bool io_fail) {
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
		luasteam::pushuint64(L, data->m_nPublishedFileId);
		lua_setfield(L, -2, "m_nPublishedFileId");
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		lua_pushboolean(L, data->m_bVotedUp);
		lua_setfield(L, -2, "m_bVotedUp");
		lua_pushboolean(L, data->m_bVotedDown);
		lua_setfield(L, -2, "m_bVotedDown");
		lua_pushboolean(L, data->m_bVoteSkipped);
		lua_setfield(L, -2, "m_bVoteSkipped");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<RemoveAppDependencyResult_t>::Result(RemoveAppDependencyResult_t *data, bool io_fail) {
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
		luasteam::pushuint64(L, data->m_nPublishedFileId);
		lua_setfield(L, -2, "m_nPublishedFileId");
		lua_pushinteger(L, data->m_nAppID);
		lua_setfield(L, -2, "m_nAppID");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<RemoveUGCDependencyResult_t>::Result(RemoveUGCDependencyResult_t *data, bool io_fail) {
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
		luasteam::pushuint64(L, data->m_nPublishedFileId);
		lua_setfield(L, -2, "m_nPublishedFileId");
		luasteam::pushuint64(L, data->m_nChildPublishedFileId);
		lua_setfield(L, -2, "m_nChildPublishedFileId");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<SetUserItemVoteResult_t>::Result(SetUserItemVoteResult_t *data, bool io_fail) {
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
		luasteam::pushuint64(L, data->m_nPublishedFileId);
		lua_setfield(L, -2, "m_nPublishedFileId");
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		lua_pushboolean(L, data->m_bVoteUp);
		lua_setfield(L, -2, "m_bVoteUp");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<StartPlaytimeTrackingResult_t>::Result(StartPlaytimeTrackingResult_t *data, bool io_fail) {
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

template <> void CallResultListener<SteamUGCQueryCompleted_t>::Result(SteamUGCQueryCompleted_t *data, bool io_fail) {
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
		lua_createtable(L, 0, 6);
		luasteam::pushuint64(L, data->m_handle);
		lua_setfield(L, -2, "m_handle");
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		lua_pushinteger(L, data->m_unNumResultsReturned);
		lua_setfield(L, -2, "m_unNumResultsReturned");
		lua_pushinteger(L, data->m_unTotalMatchingResults);
		lua_setfield(L, -2, "m_unTotalMatchingResults");
		lua_pushboolean(L, data->m_bCachedData);
		lua_setfield(L, -2, "m_bCachedData");
		lua_pushlstring(L, reinterpret_cast<const char*>(data->m_rgchNextCursor), 256);
		lua_setfield(L, -2, "m_rgchNextCursor");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<SteamUGCRequestUGCDetailsResult_t>::Result(SteamUGCRequestUGCDetailsResult_t *data, bool io_fail) {
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
		luasteam::push_SteamUGCDetails_t(L, data->m_details);
		lua_setfield(L, -2, "m_details");
		lua_pushboolean(L, data->m_bCachedData);
		lua_setfield(L, -2, "m_bCachedData");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<StopPlaytimeTrackingResult_t>::Result(StopPlaytimeTrackingResult_t *data, bool io_fail) {
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

template <> void CallResultListener<SubmitItemUpdateResult_t>::Result(SubmitItemUpdateResult_t *data, bool io_fail) {
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
		lua_pushboolean(L, data->m_bUserNeedsToAcceptWorkshopLegalAgreement);
		lua_setfield(L, -2, "m_bUserNeedsToAcceptWorkshopLegalAgreement");
		luasteam::pushuint64(L, data->m_nPublishedFileId);
		lua_setfield(L, -2, "m_nPublishedFileId");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<UserFavoriteItemsListChanged_t>::Result(UserFavoriteItemsListChanged_t *data, bool io_fail) {
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
		luasteam::pushuint64(L, data->m_nPublishedFileId);
		lua_setfield(L, -2, "m_nPublishedFileId");
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		lua_pushboolean(L, data->m_bWasAddRequest);
		lua_setfield(L, -2, "m_bWasAddRequest");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<WorkshopEULAStatus_t>::Result(WorkshopEULAStatus_t *data, bool io_fail) {
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
		lua_createtable(L, 0, 6);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		lua_pushinteger(L, data->m_nAppID);
		lua_setfield(L, -2, "m_nAppID");
		lua_pushinteger(L, data->m_unVersion);
		lua_setfield(L, -2, "m_unVersion");
		lua_pushinteger(L, data->m_rtAction);
		lua_setfield(L, -2, "m_rtAction");
		lua_pushboolean(L, data->m_bAccepted);
		lua_setfield(L, -2, "m_bAccepted");
		lua_pushboolean(L, data->m_bNeedsAction);
		lua_setfield(L, -2, "m_bNeedsAction");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

// In C++:
// UGCQueryHandle_t CreateQueryUserUGCRequest(AccountID_t unAccountID, EUserUGCList eListType, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eSortOrder, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage);
// In Lua:
// uint64 UGC.CreateQueryUserUGCRequest(unAccountID: int, eListType: int, eMatchingUGCType: int, eSortOrder: int, nCreatorAppID: int, nConsumerAppID: int, unPage: int)
static int luasteam_UGC_CreateQueryUserUGCRequest(lua_State *L, ISteamUGC *iface) {
	AccountID_t unAccountID = static_cast<AccountID_t>(luaL_checkint(L, 1));
	EUserUGCList eListType = static_cast<EUserUGCList>(luaL_checkint(L, 2));
	EUGCMatchingUGCType eMatchingUGCType = static_cast<EUGCMatchingUGCType>(luaL_checkint(L, 3));
	EUserUGCListSortOrder eSortOrder = static_cast<EUserUGCListSortOrder>(luaL_checkint(L, 4));
	AppId_t nCreatorAppID = static_cast<AppId_t>(luaL_checkint(L, 5));
	AppId_t nConsumerAppID = static_cast<AppId_t>(luaL_checkint(L, 6));
	uint32 unPage = static_cast<uint32>(luaL_checkint(L, 7));
	UGCQueryHandle_t __ret = iface->CreateQueryUserUGCRequest(unAccountID, eListType, eMatchingUGCType, eSortOrder, nCreatorAppID, nConsumerAppID, unPage);
	luasteam::pushuint64(L, __ret);
	return 1;
}
static int luasteam_UGC_CreateQueryUserUGCRequest_user(lua_State *L) { return luasteam_UGC_CreateQueryUserUGCRequest(L, SteamUGC()); }
static int luasteam_UGC_CreateQueryUserUGCRequest_gs(lua_State *L) { return luasteam_UGC_CreateQueryUserUGCRequest(L, SteamGameServerUGC()); }

// In C++:
// UGCQueryHandle_t CreateQueryAllUGCRequest(EUGCQuery eQueryType, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage);
// In Lua:
// uint64 UGC.CreateQueryAllUGCRequestPage(eQueryType: int, eMatchingeMatchingUGCTypeFileType: int, nCreatorAppID: int, nConsumerAppID: int, unPage: int)
static int luasteam_UGC_CreateQueryAllUGCRequestPage(lua_State *L, ISteamUGC *iface) {
	EUGCQuery eQueryType = static_cast<EUGCQuery>(luaL_checkint(L, 1));
	EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType = static_cast<EUGCMatchingUGCType>(luaL_checkint(L, 2));
	AppId_t nCreatorAppID = static_cast<AppId_t>(luaL_checkint(L, 3));
	AppId_t nConsumerAppID = static_cast<AppId_t>(luaL_checkint(L, 4));
	uint32 unPage = static_cast<uint32>(luaL_checkint(L, 5));
	UGCQueryHandle_t __ret = iface->CreateQueryAllUGCRequest(eQueryType, eMatchingeMatchingUGCTypeFileType, nCreatorAppID, nConsumerAppID, unPage);
	luasteam::pushuint64(L, __ret);
	return 1;
}
static int luasteam_UGC_CreateQueryAllUGCRequestPage_user(lua_State *L) { return luasteam_UGC_CreateQueryAllUGCRequestPage(L, SteamUGC()); }
static int luasteam_UGC_CreateQueryAllUGCRequestPage_gs(lua_State *L) { return luasteam_UGC_CreateQueryAllUGCRequestPage(L, SteamGameServerUGC()); }

// In C++:
// UGCQueryHandle_t CreateQueryUGCDetailsRequest(PublishedFileId_t * pvecPublishedFileID, uint32 unNumPublishedFileIDs);
// In Lua:
// (uint64, pvecPublishedFileID: uint64) UGC.CreateQueryUGCDetailsRequest(unNumPublishedFileIDs: int)
static int luasteam_UGC_CreateQueryUGCDetailsRequest(lua_State *L, ISteamUGC *iface) {
	PublishedFileId_t pvecPublishedFileID;
	uint32 unNumPublishedFileIDs = static_cast<uint32>(luaL_checkint(L, 1));
	UGCQueryHandle_t __ret = iface->CreateQueryUGCDetailsRequest(&pvecPublishedFileID, unNumPublishedFileIDs);
	luasteam::pushuint64(L, __ret);
	luasteam::pushuint64(L, pvecPublishedFileID);
	return 2;
}
static int luasteam_UGC_CreateQueryUGCDetailsRequest_user(lua_State *L) { return luasteam_UGC_CreateQueryUGCDetailsRequest(L, SteamUGC()); }
static int luasteam_UGC_CreateQueryUGCDetailsRequest_gs(lua_State *L) { return luasteam_UGC_CreateQueryUGCDetailsRequest(L, SteamGameServerUGC()); }

// In C++:
// SteamAPICall_t SendQueryUGCRequest(UGCQueryHandle_t handle);
// In Lua:
// uint64 UGC.SendQueryUGCRequest(handle: uint64, callback: function)
static int luasteam_UGC_SendQueryUGCRequest(lua_State *L, ISteamUGC *iface) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = iface->SendQueryUGCRequest(handle);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<SteamUGCQueryCompleted_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<SteamUGCQueryCompleted_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}
static int luasteam_UGC_SendQueryUGCRequest_user(lua_State *L) { return luasteam_UGC_SendQueryUGCRequest(L, SteamUGC()); }
static int luasteam_UGC_SendQueryUGCRequest_gs(lua_State *L) { return luasteam_UGC_SendQueryUGCRequest(L, SteamGameServerUGC()); }

// In C++:
// bool GetQueryUGCResult(UGCQueryHandle_t handle, uint32 index, SteamUGCDetails_t * pDetails);
// In Lua:
// (bool, pDetails: SteamUGCDetails_t) UGC.GetQueryUGCResult(handle: uint64, index: int)
static int luasteam_UGC_GetQueryUGCResult(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
	SteamUGCDetails_t pDetails;
	bool __ret = iface->GetQueryUGCResult(handle, index, &pDetails);
	lua_pushboolean(L, __ret);
	luasteam::push_SteamUGCDetails_t(L, pDetails);
	return 2;
}
static int luasteam_UGC_GetQueryUGCResult_user(lua_State *L) { return luasteam_UGC_GetQueryUGCResult(L, SteamUGC()); }
static int luasteam_UGC_GetQueryUGCResult_gs(lua_State *L) { return luasteam_UGC_GetQueryUGCResult(L, SteamGameServerUGC()); }

// In C++:
// uint32 GetQueryUGCNumTags(UGCQueryHandle_t handle, uint32 index);
// In Lua:
// int UGC.GetQueryUGCNumTags(handle: uint64, index: int)
static int luasteam_UGC_GetQueryUGCNumTags(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
	uint32 __ret = iface->GetQueryUGCNumTags(handle, index);
	lua_pushinteger(L, __ret);
	return 1;
}
static int luasteam_UGC_GetQueryUGCNumTags_user(lua_State *L) { return luasteam_UGC_GetQueryUGCNumTags(L, SteamUGC()); }
static int luasteam_UGC_GetQueryUGCNumTags_gs(lua_State *L) { return luasteam_UGC_GetQueryUGCNumTags(L, SteamGameServerUGC()); }

// In C++:
// bool GetQueryUGCTag(UGCQueryHandle_t handle, uint32 index, uint32 indexTag, char * pchValue, uint32 cchValueSize);
// In Lua:
// (bool, pchValue: str) UGC.GetQueryUGCTag(handle: uint64, index: int, indexTag: int, cchValueSize: int)
static int luasteam_UGC_GetQueryUGCTag(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
	uint32 indexTag = static_cast<uint32>(luaL_checkint(L, 3));
	uint32 cchValueSize = luaL_checkint(L, 4);
	std::vector<char> pchValue(cchValueSize);
	bool __ret = iface->GetQueryUGCTag(handle, index, indexTag, pchValue.data(), cchValueSize);
	lua_pushboolean(L, __ret);
	lua_pushstring(L, reinterpret_cast<const char*>(pchValue.data()));
	return 2;
}
static int luasteam_UGC_GetQueryUGCTag_user(lua_State *L) { return luasteam_UGC_GetQueryUGCTag(L, SteamUGC()); }
static int luasteam_UGC_GetQueryUGCTag_gs(lua_State *L) { return luasteam_UGC_GetQueryUGCTag(L, SteamGameServerUGC()); }

// In C++:
// bool GetQueryUGCTagDisplayName(UGCQueryHandle_t handle, uint32 index, uint32 indexTag, char * pchValue, uint32 cchValueSize);
// In Lua:
// (bool, pchValue: str) UGC.GetQueryUGCTagDisplayName(handle: uint64, index: int, indexTag: int, cchValueSize: int)
static int luasteam_UGC_GetQueryUGCTagDisplayName(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
	uint32 indexTag = static_cast<uint32>(luaL_checkint(L, 3));
	uint32 cchValueSize = luaL_checkint(L, 4);
	std::vector<char> pchValue(cchValueSize);
	bool __ret = iface->GetQueryUGCTagDisplayName(handle, index, indexTag, pchValue.data(), cchValueSize);
	lua_pushboolean(L, __ret);
	lua_pushstring(L, reinterpret_cast<const char*>(pchValue.data()));
	return 2;
}
static int luasteam_UGC_GetQueryUGCTagDisplayName_user(lua_State *L) { return luasteam_UGC_GetQueryUGCTagDisplayName(L, SteamUGC()); }
static int luasteam_UGC_GetQueryUGCTagDisplayName_gs(lua_State *L) { return luasteam_UGC_GetQueryUGCTagDisplayName(L, SteamGameServerUGC()); }

// In C++:
// bool GetQueryUGCPreviewURL(UGCQueryHandle_t handle, uint32 index, char * pchURL, uint32 cchURLSize);
// In Lua:
// (bool, pchURL: str) UGC.GetQueryUGCPreviewURL(handle: uint64, index: int, cchURLSize: int)
static int luasteam_UGC_GetQueryUGCPreviewURL(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
	uint32 cchURLSize = luaL_checkint(L, 3);
	std::vector<char> pchURL(cchURLSize);
	bool __ret = iface->GetQueryUGCPreviewURL(handle, index, pchURL.data(), cchURLSize);
	lua_pushboolean(L, __ret);
	lua_pushstring(L, reinterpret_cast<const char*>(pchURL.data()));
	return 2;
}
static int luasteam_UGC_GetQueryUGCPreviewURL_user(lua_State *L) { return luasteam_UGC_GetQueryUGCPreviewURL(L, SteamUGC()); }
static int luasteam_UGC_GetQueryUGCPreviewURL_gs(lua_State *L) { return luasteam_UGC_GetQueryUGCPreviewURL(L, SteamGameServerUGC()); }

// In C++:
// bool GetQueryUGCMetadata(UGCQueryHandle_t handle, uint32 index, char * pchMetadata, uint32 cchMetadatasize);
// In Lua:
// (bool, pchMetadata: str) UGC.GetQueryUGCMetadata(handle: uint64, index: int, cchMetadatasize: int)
static int luasteam_UGC_GetQueryUGCMetadata(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
	uint32 cchMetadatasize = luaL_checkint(L, 3);
	std::vector<char> pchMetadata(cchMetadatasize);
	bool __ret = iface->GetQueryUGCMetadata(handle, index, pchMetadata.data(), cchMetadatasize);
	lua_pushboolean(L, __ret);
	lua_pushstring(L, reinterpret_cast<const char*>(pchMetadata.data()));
	return 2;
}
static int luasteam_UGC_GetQueryUGCMetadata_user(lua_State *L) { return luasteam_UGC_GetQueryUGCMetadata(L, SteamUGC()); }
static int luasteam_UGC_GetQueryUGCMetadata_gs(lua_State *L) { return luasteam_UGC_GetQueryUGCMetadata(L, SteamGameServerUGC()); }

// In C++:
// bool GetQueryUGCChildren(UGCQueryHandle_t handle, uint32 index, PublishedFileId_t * pvecPublishedFileID, uint32 cMaxEntries);
// In Lua:
// (bool, pvecPublishedFileID: uint64) UGC.GetQueryUGCChildren(handle: uint64, index: int, cMaxEntries: int)
static int luasteam_UGC_GetQueryUGCChildren(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
	PublishedFileId_t pvecPublishedFileID;
	uint32 cMaxEntries = static_cast<uint32>(luaL_checkint(L, 3));
	bool __ret = iface->GetQueryUGCChildren(handle, index, &pvecPublishedFileID, cMaxEntries);
	lua_pushboolean(L, __ret);
	luasteam::pushuint64(L, pvecPublishedFileID);
	return 2;
}
static int luasteam_UGC_GetQueryUGCChildren_user(lua_State *L) { return luasteam_UGC_GetQueryUGCChildren(L, SteamUGC()); }
static int luasteam_UGC_GetQueryUGCChildren_gs(lua_State *L) { return luasteam_UGC_GetQueryUGCChildren(L, SteamGameServerUGC()); }

// In C++:
// bool GetQueryUGCStatistic(UGCQueryHandle_t handle, uint32 index, EItemStatistic eStatType, uint64 * pStatValue);
// In Lua:
// (bool, pStatValue: uint64) UGC.GetQueryUGCStatistic(handle: uint64, index: int, eStatType: int)
static int luasteam_UGC_GetQueryUGCStatistic(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
	EItemStatistic eStatType = static_cast<EItemStatistic>(luaL_checkint(L, 3));
	uint64 pStatValue;
	bool __ret = iface->GetQueryUGCStatistic(handle, index, eStatType, &pStatValue);
	lua_pushboolean(L, __ret);
	luasteam::pushuint64(L, pStatValue);
	return 2;
}
static int luasteam_UGC_GetQueryUGCStatistic_user(lua_State *L) { return luasteam_UGC_GetQueryUGCStatistic(L, SteamUGC()); }
static int luasteam_UGC_GetQueryUGCStatistic_gs(lua_State *L) { return luasteam_UGC_GetQueryUGCStatistic(L, SteamGameServerUGC()); }

// In C++:
// uint32 GetQueryUGCNumAdditionalPreviews(UGCQueryHandle_t handle, uint32 index);
// In Lua:
// int UGC.GetQueryUGCNumAdditionalPreviews(handle: uint64, index: int)
static int luasteam_UGC_GetQueryUGCNumAdditionalPreviews(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
	uint32 __ret = iface->GetQueryUGCNumAdditionalPreviews(handle, index);
	lua_pushinteger(L, __ret);
	return 1;
}
static int luasteam_UGC_GetQueryUGCNumAdditionalPreviews_user(lua_State *L) { return luasteam_UGC_GetQueryUGCNumAdditionalPreviews(L, SteamUGC()); }
static int luasteam_UGC_GetQueryUGCNumAdditionalPreviews_gs(lua_State *L) { return luasteam_UGC_GetQueryUGCNumAdditionalPreviews(L, SteamGameServerUGC()); }

// In C++:
// bool GetQueryUGCAdditionalPreview(UGCQueryHandle_t handle, uint32 index, uint32 previewIndex, char * pchURLOrVideoID, uint32 cchURLSize, char * pchOriginalFileName, uint32 cchOriginalFileNameSize, EItemPreviewType * pPreviewType);
// In Lua:
// (bool, pchURLOrVideoID: str, pchOriginalFileName: str, pPreviewType: int) UGC.GetQueryUGCAdditionalPreview(handle: uint64, index: int, previewIndex: int, cchURLSize: int, cchOriginalFileNameSize: int)
static int luasteam_UGC_GetQueryUGCAdditionalPreview(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
	uint32 previewIndex = static_cast<uint32>(luaL_checkint(L, 3));
	uint32 cchURLSize = luaL_checkint(L, 4);
	std::vector<char> pchURLOrVideoID(cchURLSize);
	uint32 cchOriginalFileNameSize = luaL_checkint(L, 5);
	std::vector<char> pchOriginalFileName(cchOriginalFileNameSize);
	EItemPreviewType pPreviewType;
	bool __ret = iface->GetQueryUGCAdditionalPreview(handle, index, previewIndex, pchURLOrVideoID.data(), cchURLSize, pchOriginalFileName.data(), cchOriginalFileNameSize, &pPreviewType);
	lua_pushboolean(L, __ret);
	lua_pushstring(L, reinterpret_cast<const char*>(pchURLOrVideoID.data()));
	lua_pushstring(L, reinterpret_cast<const char*>(pchOriginalFileName.data()));
	lua_pushinteger(L, pPreviewType);
	return 4;
}
static int luasteam_UGC_GetQueryUGCAdditionalPreview_user(lua_State *L) { return luasteam_UGC_GetQueryUGCAdditionalPreview(L, SteamUGC()); }
static int luasteam_UGC_GetQueryUGCAdditionalPreview_gs(lua_State *L) { return luasteam_UGC_GetQueryUGCAdditionalPreview(L, SteamGameServerUGC()); }

// In C++:
// uint32 GetQueryUGCNumKeyValueTags(UGCQueryHandle_t handle, uint32 index);
// In Lua:
// int UGC.GetQueryUGCNumKeyValueTags(handle: uint64, index: int)
static int luasteam_UGC_GetQueryUGCNumKeyValueTags(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
	uint32 __ret = iface->GetQueryUGCNumKeyValueTags(handle, index);
	lua_pushinteger(L, __ret);
	return 1;
}
static int luasteam_UGC_GetQueryUGCNumKeyValueTags_user(lua_State *L) { return luasteam_UGC_GetQueryUGCNumKeyValueTags(L, SteamUGC()); }
static int luasteam_UGC_GetQueryUGCNumKeyValueTags_gs(lua_State *L) { return luasteam_UGC_GetQueryUGCNumKeyValueTags(L, SteamGameServerUGC()); }

// In C++:
// bool GetQueryUGCKeyValueTag(UGCQueryHandle_t handle, uint32 index, uint32 keyValueTagIndex, char * pchKey, uint32 cchKeySize, char * pchValue, uint32 cchValueSize);
// In Lua:
// (bool, pchKey: str, pchValue: str) UGC.GetQueryUGCKeyValueTag(handle: uint64, index: int, keyValueTagIndex: int, cchKeySize: int, cchValueSize: int)
static int luasteam_UGC_GetQueryUGCKeyValueTag(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
	uint32 keyValueTagIndex = static_cast<uint32>(luaL_checkint(L, 3));
	uint32 cchKeySize = luaL_checkint(L, 4);
	std::vector<char> pchKey(cchKeySize);
	uint32 cchValueSize = luaL_checkint(L, 5);
	std::vector<char> pchValue(cchValueSize);
	bool __ret = iface->GetQueryUGCKeyValueTag(handle, index, keyValueTagIndex, pchKey.data(), cchKeySize, pchValue.data(), cchValueSize);
	lua_pushboolean(L, __ret);
	lua_pushstring(L, reinterpret_cast<const char*>(pchKey.data()));
	lua_pushstring(L, reinterpret_cast<const char*>(pchValue.data()));
	return 3;
}
static int luasteam_UGC_GetQueryUGCKeyValueTag_user(lua_State *L) { return luasteam_UGC_GetQueryUGCKeyValueTag(L, SteamUGC()); }
static int luasteam_UGC_GetQueryUGCKeyValueTag_gs(lua_State *L) { return luasteam_UGC_GetQueryUGCKeyValueTag(L, SteamGameServerUGC()); }

// In C++:
// uint32 GetNumSupportedGameVersions(UGCQueryHandle_t handle, uint32 index);
// In Lua:
// int UGC.GetNumSupportedGameVersions(handle: uint64, index: int)
static int luasteam_UGC_GetNumSupportedGameVersions(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
	uint32 __ret = iface->GetNumSupportedGameVersions(handle, index);
	lua_pushinteger(L, __ret);
	return 1;
}
static int luasteam_UGC_GetNumSupportedGameVersions_user(lua_State *L) { return luasteam_UGC_GetNumSupportedGameVersions(L, SteamUGC()); }
static int luasteam_UGC_GetNumSupportedGameVersions_gs(lua_State *L) { return luasteam_UGC_GetNumSupportedGameVersions(L, SteamGameServerUGC()); }

// In C++:
// bool GetSupportedGameVersionData(UGCQueryHandle_t handle, uint32 index, uint32 versionIndex, char * pchGameBranchMin, char * pchGameBranchMax, uint32 cchGameBranchSize);
// In Lua:
// (bool, pchGameBranchMin: str, pchGameBranchMax: str) UGC.GetSupportedGameVersionData(handle: uint64, index: int, versionIndex: int, cchGameBranchSize: int)
static int luasteam_UGC_GetSupportedGameVersionData(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
	uint32 versionIndex = static_cast<uint32>(luaL_checkint(L, 3));
	uint32 cchGameBranchSize = luaL_checkint(L, 4);
	std::vector<char> pchGameBranchMin(cchGameBranchSize);
	std::vector<char> pchGameBranchMax(cchGameBranchSize);
	bool __ret = iface->GetSupportedGameVersionData(handle, index, versionIndex, pchGameBranchMin.data(), pchGameBranchMax.data(), cchGameBranchSize);
	lua_pushboolean(L, __ret);
	lua_pushstring(L, reinterpret_cast<const char*>(pchGameBranchMin.data()));
	lua_pushstring(L, reinterpret_cast<const char*>(pchGameBranchMax.data()));
	return 3;
}
static int luasteam_UGC_GetSupportedGameVersionData_user(lua_State *L) { return luasteam_UGC_GetSupportedGameVersionData(L, SteamUGC()); }
static int luasteam_UGC_GetSupportedGameVersionData_gs(lua_State *L) { return luasteam_UGC_GetSupportedGameVersionData(L, SteamGameServerUGC()); }

// In C++:
// uint32 GetQueryUGCContentDescriptors(UGCQueryHandle_t handle, uint32 index, EUGCContentDescriptorID * pvecDescriptors, uint32 cMaxEntries);
// In Lua:
// (int, pvecDescriptors: int) UGC.GetQueryUGCContentDescriptors(handle: uint64, index: int, cMaxEntries: int)
static int luasteam_UGC_GetQueryUGCContentDescriptors(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
	EUGCContentDescriptorID pvecDescriptors;
	uint32 cMaxEntries = static_cast<uint32>(luaL_checkint(L, 3));
	uint32 __ret = iface->GetQueryUGCContentDescriptors(handle, index, &pvecDescriptors, cMaxEntries);
	lua_pushinteger(L, __ret);
	lua_pushinteger(L, pvecDescriptors);
	return 2;
}
static int luasteam_UGC_GetQueryUGCContentDescriptors_user(lua_State *L) { return luasteam_UGC_GetQueryUGCContentDescriptors(L, SteamUGC()); }
static int luasteam_UGC_GetQueryUGCContentDescriptors_gs(lua_State *L) { return luasteam_UGC_GetQueryUGCContentDescriptors(L, SteamGameServerUGC()); }

// In C++:
// bool ReleaseQueryUGCRequest(UGCQueryHandle_t handle);
// In Lua:
// bool UGC.ReleaseQueryUGCRequest(handle: uint64)
static int luasteam_UGC_ReleaseQueryUGCRequest(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	bool __ret = iface->ReleaseQueryUGCRequest(handle);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_ReleaseQueryUGCRequest_user(lua_State *L) { return luasteam_UGC_ReleaseQueryUGCRequest(L, SteamUGC()); }
static int luasteam_UGC_ReleaseQueryUGCRequest_gs(lua_State *L) { return luasteam_UGC_ReleaseQueryUGCRequest(L, SteamGameServerUGC()); }

// In C++:
// bool AddRequiredTag(UGCQueryHandle_t handle, const char * pTagName);
// In Lua:
// bool UGC.AddRequiredTag(handle: uint64, pTagName: str)
static int luasteam_UGC_AddRequiredTag(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	const char *pTagName = luaL_checkstring(L, 2);
	bool __ret = iface->AddRequiredTag(handle, pTagName);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_AddRequiredTag_user(lua_State *L) { return luasteam_UGC_AddRequiredTag(L, SteamUGC()); }
static int luasteam_UGC_AddRequiredTag_gs(lua_State *L) { return luasteam_UGC_AddRequiredTag(L, SteamGameServerUGC()); }

// In C++:
// bool AddRequiredTagGroup(UGCQueryHandle_t handle, const SteamParamStringArray_t * pTagGroups);
// In Lua:
// bool UGC.AddRequiredTagGroup(handle: uint64, pTagGroups: SteamParamStringArray_t)
static int luasteam_UGC_AddRequiredTagGroup(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	const SteamParamStringArray_t *pTagGroups = lua_isnil(L, 2) ? nullptr : luasteam::check_SteamParamStringArray_t_ptr(L, 2);
	bool __ret = iface->AddRequiredTagGroup(handle, pTagGroups);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_AddRequiredTagGroup_user(lua_State *L) { return luasteam_UGC_AddRequiredTagGroup(L, SteamUGC()); }
static int luasteam_UGC_AddRequiredTagGroup_gs(lua_State *L) { return luasteam_UGC_AddRequiredTagGroup(L, SteamGameServerUGC()); }

// In C++:
// bool AddExcludedTag(UGCQueryHandle_t handle, const char * pTagName);
// In Lua:
// bool UGC.AddExcludedTag(handle: uint64, pTagName: str)
static int luasteam_UGC_AddExcludedTag(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	const char *pTagName = luaL_checkstring(L, 2);
	bool __ret = iface->AddExcludedTag(handle, pTagName);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_AddExcludedTag_user(lua_State *L) { return luasteam_UGC_AddExcludedTag(L, SteamUGC()); }
static int luasteam_UGC_AddExcludedTag_gs(lua_State *L) { return luasteam_UGC_AddExcludedTag(L, SteamGameServerUGC()); }

// In C++:
// bool SetReturnOnlyIDs(UGCQueryHandle_t handle, bool bReturnOnlyIDs);
// In Lua:
// bool UGC.SetReturnOnlyIDs(handle: uint64, bReturnOnlyIDs: bool)
static int luasteam_UGC_SetReturnOnlyIDs(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	bool bReturnOnlyIDs = lua_toboolean(L, 2);
	bool __ret = iface->SetReturnOnlyIDs(handle, bReturnOnlyIDs);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_SetReturnOnlyIDs_user(lua_State *L) { return luasteam_UGC_SetReturnOnlyIDs(L, SteamUGC()); }
static int luasteam_UGC_SetReturnOnlyIDs_gs(lua_State *L) { return luasteam_UGC_SetReturnOnlyIDs(L, SteamGameServerUGC()); }

// In C++:
// bool SetReturnKeyValueTags(UGCQueryHandle_t handle, bool bReturnKeyValueTags);
// In Lua:
// bool UGC.SetReturnKeyValueTags(handle: uint64, bReturnKeyValueTags: bool)
static int luasteam_UGC_SetReturnKeyValueTags(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	bool bReturnKeyValueTags = lua_toboolean(L, 2);
	bool __ret = iface->SetReturnKeyValueTags(handle, bReturnKeyValueTags);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_SetReturnKeyValueTags_user(lua_State *L) { return luasteam_UGC_SetReturnKeyValueTags(L, SteamUGC()); }
static int luasteam_UGC_SetReturnKeyValueTags_gs(lua_State *L) { return luasteam_UGC_SetReturnKeyValueTags(L, SteamGameServerUGC()); }

// In C++:
// bool SetReturnLongDescription(UGCQueryHandle_t handle, bool bReturnLongDescription);
// In Lua:
// bool UGC.SetReturnLongDescription(handle: uint64, bReturnLongDescription: bool)
static int luasteam_UGC_SetReturnLongDescription(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	bool bReturnLongDescription = lua_toboolean(L, 2);
	bool __ret = iface->SetReturnLongDescription(handle, bReturnLongDescription);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_SetReturnLongDescription_user(lua_State *L) { return luasteam_UGC_SetReturnLongDescription(L, SteamUGC()); }
static int luasteam_UGC_SetReturnLongDescription_gs(lua_State *L) { return luasteam_UGC_SetReturnLongDescription(L, SteamGameServerUGC()); }

// In C++:
// bool SetReturnMetadata(UGCQueryHandle_t handle, bool bReturnMetadata);
// In Lua:
// bool UGC.SetReturnMetadata(handle: uint64, bReturnMetadata: bool)
static int luasteam_UGC_SetReturnMetadata(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	bool bReturnMetadata = lua_toboolean(L, 2);
	bool __ret = iface->SetReturnMetadata(handle, bReturnMetadata);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_SetReturnMetadata_user(lua_State *L) { return luasteam_UGC_SetReturnMetadata(L, SteamUGC()); }
static int luasteam_UGC_SetReturnMetadata_gs(lua_State *L) { return luasteam_UGC_SetReturnMetadata(L, SteamGameServerUGC()); }

// In C++:
// bool SetReturnChildren(UGCQueryHandle_t handle, bool bReturnChildren);
// In Lua:
// bool UGC.SetReturnChildren(handle: uint64, bReturnChildren: bool)
static int luasteam_UGC_SetReturnChildren(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	bool bReturnChildren = lua_toboolean(L, 2);
	bool __ret = iface->SetReturnChildren(handle, bReturnChildren);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_SetReturnChildren_user(lua_State *L) { return luasteam_UGC_SetReturnChildren(L, SteamUGC()); }
static int luasteam_UGC_SetReturnChildren_gs(lua_State *L) { return luasteam_UGC_SetReturnChildren(L, SteamGameServerUGC()); }

// In C++:
// bool SetReturnAdditionalPreviews(UGCQueryHandle_t handle, bool bReturnAdditionalPreviews);
// In Lua:
// bool UGC.SetReturnAdditionalPreviews(handle: uint64, bReturnAdditionalPreviews: bool)
static int luasteam_UGC_SetReturnAdditionalPreviews(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	bool bReturnAdditionalPreviews = lua_toboolean(L, 2);
	bool __ret = iface->SetReturnAdditionalPreviews(handle, bReturnAdditionalPreviews);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_SetReturnAdditionalPreviews_user(lua_State *L) { return luasteam_UGC_SetReturnAdditionalPreviews(L, SteamUGC()); }
static int luasteam_UGC_SetReturnAdditionalPreviews_gs(lua_State *L) { return luasteam_UGC_SetReturnAdditionalPreviews(L, SteamGameServerUGC()); }

// In C++:
// bool SetReturnTotalOnly(UGCQueryHandle_t handle, bool bReturnTotalOnly);
// In Lua:
// bool UGC.SetReturnTotalOnly(handle: uint64, bReturnTotalOnly: bool)
static int luasteam_UGC_SetReturnTotalOnly(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	bool bReturnTotalOnly = lua_toboolean(L, 2);
	bool __ret = iface->SetReturnTotalOnly(handle, bReturnTotalOnly);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_SetReturnTotalOnly_user(lua_State *L) { return luasteam_UGC_SetReturnTotalOnly(L, SteamUGC()); }
static int luasteam_UGC_SetReturnTotalOnly_gs(lua_State *L) { return luasteam_UGC_SetReturnTotalOnly(L, SteamGameServerUGC()); }

// In C++:
// bool SetReturnPlaytimeStats(UGCQueryHandle_t handle, uint32 unDays);
// In Lua:
// bool UGC.SetReturnPlaytimeStats(handle: uint64, unDays: int)
static int luasteam_UGC_SetReturnPlaytimeStats(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	uint32 unDays = static_cast<uint32>(luaL_checkint(L, 2));
	bool __ret = iface->SetReturnPlaytimeStats(handle, unDays);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_SetReturnPlaytimeStats_user(lua_State *L) { return luasteam_UGC_SetReturnPlaytimeStats(L, SteamUGC()); }
static int luasteam_UGC_SetReturnPlaytimeStats_gs(lua_State *L) { return luasteam_UGC_SetReturnPlaytimeStats(L, SteamGameServerUGC()); }

// In C++:
// bool SetLanguage(UGCQueryHandle_t handle, const char * pchLanguage);
// In Lua:
// bool UGC.SetLanguage(handle: uint64, pchLanguage: str)
static int luasteam_UGC_SetLanguage(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	const char *pchLanguage = luaL_checkstring(L, 2);
	bool __ret = iface->SetLanguage(handle, pchLanguage);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_SetLanguage_user(lua_State *L) { return luasteam_UGC_SetLanguage(L, SteamUGC()); }
static int luasteam_UGC_SetLanguage_gs(lua_State *L) { return luasteam_UGC_SetLanguage(L, SteamGameServerUGC()); }

// In C++:
// bool SetAllowCachedResponse(UGCQueryHandle_t handle, uint32 unMaxAgeSeconds);
// In Lua:
// bool UGC.SetAllowCachedResponse(handle: uint64, unMaxAgeSeconds: int)
static int luasteam_UGC_SetAllowCachedResponse(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	uint32 unMaxAgeSeconds = static_cast<uint32>(luaL_checkint(L, 2));
	bool __ret = iface->SetAllowCachedResponse(handle, unMaxAgeSeconds);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_SetAllowCachedResponse_user(lua_State *L) { return luasteam_UGC_SetAllowCachedResponse(L, SteamUGC()); }
static int luasteam_UGC_SetAllowCachedResponse_gs(lua_State *L) { return luasteam_UGC_SetAllowCachedResponse(L, SteamGameServerUGC()); }

// In C++:
// bool SetAdminQuery(UGCUpdateHandle_t handle, bool bAdminQuery);
// In Lua:
// bool UGC.SetAdminQuery(handle: uint64, bAdminQuery: bool)
static int luasteam_UGC_SetAdminQuery(lua_State *L, ISteamUGC *iface) {
	UGCUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	bool bAdminQuery = lua_toboolean(L, 2);
	bool __ret = iface->SetAdminQuery(handle, bAdminQuery);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_SetAdminQuery_user(lua_State *L) { return luasteam_UGC_SetAdminQuery(L, SteamUGC()); }
static int luasteam_UGC_SetAdminQuery_gs(lua_State *L) { return luasteam_UGC_SetAdminQuery(L, SteamGameServerUGC()); }

// In C++:
// bool SetCloudFileNameFilter(UGCQueryHandle_t handle, const char * pMatchCloudFileName);
// In Lua:
// bool UGC.SetCloudFileNameFilter(handle: uint64, pMatchCloudFileName: str)
static int luasteam_UGC_SetCloudFileNameFilter(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	const char *pMatchCloudFileName = luaL_checkstring(L, 2);
	bool __ret = iface->SetCloudFileNameFilter(handle, pMatchCloudFileName);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_SetCloudFileNameFilter_user(lua_State *L) { return luasteam_UGC_SetCloudFileNameFilter(L, SteamUGC()); }
static int luasteam_UGC_SetCloudFileNameFilter_gs(lua_State *L) { return luasteam_UGC_SetCloudFileNameFilter(L, SteamGameServerUGC()); }

// In C++:
// bool SetMatchAnyTag(UGCQueryHandle_t handle, bool bMatchAnyTag);
// In Lua:
// bool UGC.SetMatchAnyTag(handle: uint64, bMatchAnyTag: bool)
static int luasteam_UGC_SetMatchAnyTag(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	bool bMatchAnyTag = lua_toboolean(L, 2);
	bool __ret = iface->SetMatchAnyTag(handle, bMatchAnyTag);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_SetMatchAnyTag_user(lua_State *L) { return luasteam_UGC_SetMatchAnyTag(L, SteamUGC()); }
static int luasteam_UGC_SetMatchAnyTag_gs(lua_State *L) { return luasteam_UGC_SetMatchAnyTag(L, SteamGameServerUGC()); }

// In C++:
// bool SetSearchText(UGCQueryHandle_t handle, const char * pSearchText);
// In Lua:
// bool UGC.SetSearchText(handle: uint64, pSearchText: str)
static int luasteam_UGC_SetSearchText(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	const char *pSearchText = luaL_checkstring(L, 2);
	bool __ret = iface->SetSearchText(handle, pSearchText);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_SetSearchText_user(lua_State *L) { return luasteam_UGC_SetSearchText(L, SteamUGC()); }
static int luasteam_UGC_SetSearchText_gs(lua_State *L) { return luasteam_UGC_SetSearchText(L, SteamGameServerUGC()); }

// In C++:
// bool SetRankedByTrendDays(UGCQueryHandle_t handle, uint32 unDays);
// In Lua:
// bool UGC.SetRankedByTrendDays(handle: uint64, unDays: int)
static int luasteam_UGC_SetRankedByTrendDays(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	uint32 unDays = static_cast<uint32>(luaL_checkint(L, 2));
	bool __ret = iface->SetRankedByTrendDays(handle, unDays);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_SetRankedByTrendDays_user(lua_State *L) { return luasteam_UGC_SetRankedByTrendDays(L, SteamUGC()); }
static int luasteam_UGC_SetRankedByTrendDays_gs(lua_State *L) { return luasteam_UGC_SetRankedByTrendDays(L, SteamGameServerUGC()); }

// In C++:
// bool SetTimeCreatedDateRange(UGCQueryHandle_t handle, RTime32 rtStart, RTime32 rtEnd);
// In Lua:
// bool UGC.SetTimeCreatedDateRange(handle: uint64, rtStart: int, rtEnd: int)
static int luasteam_UGC_SetTimeCreatedDateRange(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	RTime32 rtStart = static_cast<RTime32>(luaL_checkint(L, 2));
	RTime32 rtEnd = static_cast<RTime32>(luaL_checkint(L, 3));
	bool __ret = iface->SetTimeCreatedDateRange(handle, rtStart, rtEnd);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_SetTimeCreatedDateRange_user(lua_State *L) { return luasteam_UGC_SetTimeCreatedDateRange(L, SteamUGC()); }
static int luasteam_UGC_SetTimeCreatedDateRange_gs(lua_State *L) { return luasteam_UGC_SetTimeCreatedDateRange(L, SteamGameServerUGC()); }

// In C++:
// bool SetTimeUpdatedDateRange(UGCQueryHandle_t handle, RTime32 rtStart, RTime32 rtEnd);
// In Lua:
// bool UGC.SetTimeUpdatedDateRange(handle: uint64, rtStart: int, rtEnd: int)
static int luasteam_UGC_SetTimeUpdatedDateRange(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	RTime32 rtStart = static_cast<RTime32>(luaL_checkint(L, 2));
	RTime32 rtEnd = static_cast<RTime32>(luaL_checkint(L, 3));
	bool __ret = iface->SetTimeUpdatedDateRange(handle, rtStart, rtEnd);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_SetTimeUpdatedDateRange_user(lua_State *L) { return luasteam_UGC_SetTimeUpdatedDateRange(L, SteamUGC()); }
static int luasteam_UGC_SetTimeUpdatedDateRange_gs(lua_State *L) { return luasteam_UGC_SetTimeUpdatedDateRange(L, SteamGameServerUGC()); }

// In C++:
// bool AddRequiredKeyValueTag(UGCQueryHandle_t handle, const char * pKey, const char * pValue);
// In Lua:
// bool UGC.AddRequiredKeyValueTag(handle: uint64, pKey: str, pValue: str)
static int luasteam_UGC_AddRequiredKeyValueTag(lua_State *L, ISteamUGC *iface) {
	UGCQueryHandle_t handle(luasteam::checkuint64(L, 1));
	const char *pKey = luaL_checkstring(L, 2);
	const char *pValue = luaL_checkstring(L, 3);
	bool __ret = iface->AddRequiredKeyValueTag(handle, pKey, pValue);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_AddRequiredKeyValueTag_user(lua_State *L) { return luasteam_UGC_AddRequiredKeyValueTag(L, SteamUGC()); }
static int luasteam_UGC_AddRequiredKeyValueTag_gs(lua_State *L) { return luasteam_UGC_AddRequiredKeyValueTag(L, SteamGameServerUGC()); }

// In C++:
// SteamAPICall_t RequestUGCDetails(PublishedFileId_t nPublishedFileID, uint32 unMaxAgeSeconds);
// In Lua:
// uint64 UGC.RequestUGCDetails(nPublishedFileID: uint64, unMaxAgeSeconds: int, callback: function)
static int luasteam_UGC_RequestUGCDetails(lua_State *L, ISteamUGC *iface) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	PublishedFileId_t nPublishedFileID(luasteam::checkuint64(L, 1));
	uint32 unMaxAgeSeconds = static_cast<uint32>(luaL_checkint(L, 2));
	SteamAPICall_t __ret = iface->RequestUGCDetails(nPublishedFileID, unMaxAgeSeconds);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<SteamUGCRequestUGCDetailsResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<SteamUGCRequestUGCDetailsResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}
static int luasteam_UGC_RequestUGCDetails_user(lua_State *L) { return luasteam_UGC_RequestUGCDetails(L, SteamUGC()); }
static int luasteam_UGC_RequestUGCDetails_gs(lua_State *L) { return luasteam_UGC_RequestUGCDetails(L, SteamGameServerUGC()); }

// In C++:
// SteamAPICall_t CreateItem(AppId_t nConsumerAppId, EWorkshopFileType eFileType);
// In Lua:
// uint64 UGC.CreateItem(nConsumerAppId: int, eFileType: int, callback: function)
static int luasteam_UGC_CreateItem(lua_State *L, ISteamUGC *iface) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	AppId_t nConsumerAppId = static_cast<AppId_t>(luaL_checkint(L, 1));
	EWorkshopFileType eFileType = static_cast<EWorkshopFileType>(luaL_checkint(L, 2));
	SteamAPICall_t __ret = iface->CreateItem(nConsumerAppId, eFileType);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<CreateItemResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<CreateItemResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}
static int luasteam_UGC_CreateItem_user(lua_State *L) { return luasteam_UGC_CreateItem(L, SteamUGC()); }
static int luasteam_UGC_CreateItem_gs(lua_State *L) { return luasteam_UGC_CreateItem(L, SteamGameServerUGC()); }

// In C++:
// UGCUpdateHandle_t StartItemUpdate(AppId_t nConsumerAppId, PublishedFileId_t nPublishedFileID);
// In Lua:
// uint64 UGC.StartItemUpdate(nConsumerAppId: int, nPublishedFileID: uint64)
static int luasteam_UGC_StartItemUpdate(lua_State *L, ISteamUGC *iface) {
	AppId_t nConsumerAppId = static_cast<AppId_t>(luaL_checkint(L, 1));
	PublishedFileId_t nPublishedFileID(luasteam::checkuint64(L, 2));
	UGCUpdateHandle_t __ret = iface->StartItemUpdate(nConsumerAppId, nPublishedFileID);
	luasteam::pushuint64(L, __ret);
	return 1;
}
static int luasteam_UGC_StartItemUpdate_user(lua_State *L) { return luasteam_UGC_StartItemUpdate(L, SteamUGC()); }
static int luasteam_UGC_StartItemUpdate_gs(lua_State *L) { return luasteam_UGC_StartItemUpdate(L, SteamGameServerUGC()); }

// In C++:
// bool SetItemTitle(UGCUpdateHandle_t handle, const char * pchTitle);
// In Lua:
// bool UGC.SetItemTitle(handle: uint64, pchTitle: str)
static int luasteam_UGC_SetItemTitle(lua_State *L, ISteamUGC *iface) {
	UGCUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	const char *pchTitle = luaL_checkstring(L, 2);
	bool __ret = iface->SetItemTitle(handle, pchTitle);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_SetItemTitle_user(lua_State *L) { return luasteam_UGC_SetItemTitle(L, SteamUGC()); }
static int luasteam_UGC_SetItemTitle_gs(lua_State *L) { return luasteam_UGC_SetItemTitle(L, SteamGameServerUGC()); }

// In C++:
// bool SetItemDescription(UGCUpdateHandle_t handle, const char * pchDescription);
// In Lua:
// bool UGC.SetItemDescription(handle: uint64, pchDescription: str)
static int luasteam_UGC_SetItemDescription(lua_State *L, ISteamUGC *iface) {
	UGCUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	const char *pchDescription = luaL_checkstring(L, 2);
	bool __ret = iface->SetItemDescription(handle, pchDescription);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_SetItemDescription_user(lua_State *L) { return luasteam_UGC_SetItemDescription(L, SteamUGC()); }
static int luasteam_UGC_SetItemDescription_gs(lua_State *L) { return luasteam_UGC_SetItemDescription(L, SteamGameServerUGC()); }

// In C++:
// bool SetItemUpdateLanguage(UGCUpdateHandle_t handle, const char * pchLanguage);
// In Lua:
// bool UGC.SetItemUpdateLanguage(handle: uint64, pchLanguage: str)
static int luasteam_UGC_SetItemUpdateLanguage(lua_State *L, ISteamUGC *iface) {
	UGCUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	const char *pchLanguage = luaL_checkstring(L, 2);
	bool __ret = iface->SetItemUpdateLanguage(handle, pchLanguage);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_SetItemUpdateLanguage_user(lua_State *L) { return luasteam_UGC_SetItemUpdateLanguage(L, SteamUGC()); }
static int luasteam_UGC_SetItemUpdateLanguage_gs(lua_State *L) { return luasteam_UGC_SetItemUpdateLanguage(L, SteamGameServerUGC()); }

// In C++:
// bool SetItemMetadata(UGCUpdateHandle_t handle, const char * pchMetaData);
// In Lua:
// bool UGC.SetItemMetadata(handle: uint64, pchMetaData: str)
static int luasteam_UGC_SetItemMetadata(lua_State *L, ISteamUGC *iface) {
	UGCUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	const char *pchMetaData = luaL_checkstring(L, 2);
	bool __ret = iface->SetItemMetadata(handle, pchMetaData);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_SetItemMetadata_user(lua_State *L) { return luasteam_UGC_SetItemMetadata(L, SteamUGC()); }
static int luasteam_UGC_SetItemMetadata_gs(lua_State *L) { return luasteam_UGC_SetItemMetadata(L, SteamGameServerUGC()); }

// In C++:
// bool SetItemVisibility(UGCUpdateHandle_t handle, ERemoteStoragePublishedFileVisibility eVisibility);
// In Lua:
// bool UGC.SetItemVisibility(handle: uint64, eVisibility: int)
static int luasteam_UGC_SetItemVisibility(lua_State *L, ISteamUGC *iface) {
	UGCUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	ERemoteStoragePublishedFileVisibility eVisibility = static_cast<ERemoteStoragePublishedFileVisibility>(luaL_checkint(L, 2));
	bool __ret = iface->SetItemVisibility(handle, eVisibility);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_SetItemVisibility_user(lua_State *L) { return luasteam_UGC_SetItemVisibility(L, SteamUGC()); }
static int luasteam_UGC_SetItemVisibility_gs(lua_State *L) { return luasteam_UGC_SetItemVisibility(L, SteamGameServerUGC()); }

// In C++:
// bool SetItemTags(UGCUpdateHandle_t updateHandle, const SteamParamStringArray_t * pTags, bool bAllowAdminTags);
// In Lua:
// bool UGC.SetItemTags(updateHandle: uint64, pTags: SteamParamStringArray_t, bAllowAdminTags: bool)
static int luasteam_UGC_SetItemTags(lua_State *L, ISteamUGC *iface) {
	UGCUpdateHandle_t updateHandle(luasteam::checkuint64(L, 1));
	const SteamParamStringArray_t *pTags = lua_isnil(L, 2) ? nullptr : luasteam::check_SteamParamStringArray_t_ptr(L, 2);
	bool bAllowAdminTags = lua_toboolean(L, 3);
	bool __ret = iface->SetItemTags(updateHandle, pTags, bAllowAdminTags);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_SetItemTags_user(lua_State *L) { return luasteam_UGC_SetItemTags(L, SteamUGC()); }
static int luasteam_UGC_SetItemTags_gs(lua_State *L) { return luasteam_UGC_SetItemTags(L, SteamGameServerUGC()); }

// In C++:
// bool SetItemContent(UGCUpdateHandle_t handle, const char * pszContentFolder);
// In Lua:
// bool UGC.SetItemContent(handle: uint64, pszContentFolder: str)
static int luasteam_UGC_SetItemContent(lua_State *L, ISteamUGC *iface) {
	UGCUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	const char *pszContentFolder = luaL_checkstring(L, 2);
	bool __ret = iface->SetItemContent(handle, pszContentFolder);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_SetItemContent_user(lua_State *L) { return luasteam_UGC_SetItemContent(L, SteamUGC()); }
static int luasteam_UGC_SetItemContent_gs(lua_State *L) { return luasteam_UGC_SetItemContent(L, SteamGameServerUGC()); }

// In C++:
// bool SetItemPreview(UGCUpdateHandle_t handle, const char * pszPreviewFile);
// In Lua:
// bool UGC.SetItemPreview(handle: uint64, pszPreviewFile: str)
static int luasteam_UGC_SetItemPreview(lua_State *L, ISteamUGC *iface) {
	UGCUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	const char *pszPreviewFile = luaL_checkstring(L, 2);
	bool __ret = iface->SetItemPreview(handle, pszPreviewFile);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_SetItemPreview_user(lua_State *L) { return luasteam_UGC_SetItemPreview(L, SteamUGC()); }
static int luasteam_UGC_SetItemPreview_gs(lua_State *L) { return luasteam_UGC_SetItemPreview(L, SteamGameServerUGC()); }

// In C++:
// bool SetAllowLegacyUpload(UGCUpdateHandle_t handle, bool bAllowLegacyUpload);
// In Lua:
// bool UGC.SetAllowLegacyUpload(handle: uint64, bAllowLegacyUpload: bool)
static int luasteam_UGC_SetAllowLegacyUpload(lua_State *L, ISteamUGC *iface) {
	UGCUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	bool bAllowLegacyUpload = lua_toboolean(L, 2);
	bool __ret = iface->SetAllowLegacyUpload(handle, bAllowLegacyUpload);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_SetAllowLegacyUpload_user(lua_State *L) { return luasteam_UGC_SetAllowLegacyUpload(L, SteamUGC()); }
static int luasteam_UGC_SetAllowLegacyUpload_gs(lua_State *L) { return luasteam_UGC_SetAllowLegacyUpload(L, SteamGameServerUGC()); }

// In C++:
// bool RemoveAllItemKeyValueTags(UGCUpdateHandle_t handle);
// In Lua:
// bool UGC.RemoveAllItemKeyValueTags(handle: uint64)
static int luasteam_UGC_RemoveAllItemKeyValueTags(lua_State *L, ISteamUGC *iface) {
	UGCUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	bool __ret = iface->RemoveAllItemKeyValueTags(handle);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_RemoveAllItemKeyValueTags_user(lua_State *L) { return luasteam_UGC_RemoveAllItemKeyValueTags(L, SteamUGC()); }
static int luasteam_UGC_RemoveAllItemKeyValueTags_gs(lua_State *L) { return luasteam_UGC_RemoveAllItemKeyValueTags(L, SteamGameServerUGC()); }

// In C++:
// bool RemoveItemKeyValueTags(UGCUpdateHandle_t handle, const char * pchKey);
// In Lua:
// bool UGC.RemoveItemKeyValueTags(handle: uint64, pchKey: str)
static int luasteam_UGC_RemoveItemKeyValueTags(lua_State *L, ISteamUGC *iface) {
	UGCUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	const char *pchKey = luaL_checkstring(L, 2);
	bool __ret = iface->RemoveItemKeyValueTags(handle, pchKey);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_RemoveItemKeyValueTags_user(lua_State *L) { return luasteam_UGC_RemoveItemKeyValueTags(L, SteamUGC()); }
static int luasteam_UGC_RemoveItemKeyValueTags_gs(lua_State *L) { return luasteam_UGC_RemoveItemKeyValueTags(L, SteamGameServerUGC()); }

// In C++:
// bool AddItemKeyValueTag(UGCUpdateHandle_t handle, const char * pchKey, const char * pchValue);
// In Lua:
// bool UGC.AddItemKeyValueTag(handle: uint64, pchKey: str, pchValue: str)
static int luasteam_UGC_AddItemKeyValueTag(lua_State *L, ISteamUGC *iface) {
	UGCUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	const char *pchKey = luaL_checkstring(L, 2);
	const char *pchValue = luaL_checkstring(L, 3);
	bool __ret = iface->AddItemKeyValueTag(handle, pchKey, pchValue);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_AddItemKeyValueTag_user(lua_State *L) { return luasteam_UGC_AddItemKeyValueTag(L, SteamUGC()); }
static int luasteam_UGC_AddItemKeyValueTag_gs(lua_State *L) { return luasteam_UGC_AddItemKeyValueTag(L, SteamGameServerUGC()); }

// In C++:
// bool AddItemPreviewFile(UGCUpdateHandle_t handle, const char * pszPreviewFile, EItemPreviewType type);
// In Lua:
// bool UGC.AddItemPreviewFile(handle: uint64, pszPreviewFile: str, type: int)
static int luasteam_UGC_AddItemPreviewFile(lua_State *L, ISteamUGC *iface) {
	UGCUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	const char *pszPreviewFile = luaL_checkstring(L, 2);
	EItemPreviewType type = static_cast<EItemPreviewType>(luaL_checkint(L, 3));
	bool __ret = iface->AddItemPreviewFile(handle, pszPreviewFile, type);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_AddItemPreviewFile_user(lua_State *L) { return luasteam_UGC_AddItemPreviewFile(L, SteamUGC()); }
static int luasteam_UGC_AddItemPreviewFile_gs(lua_State *L) { return luasteam_UGC_AddItemPreviewFile(L, SteamGameServerUGC()); }

// In C++:
// bool AddItemPreviewVideo(UGCUpdateHandle_t handle, const char * pszVideoID);
// In Lua:
// bool UGC.AddItemPreviewVideo(handle: uint64, pszVideoID: str)
static int luasteam_UGC_AddItemPreviewVideo(lua_State *L, ISteamUGC *iface) {
	UGCUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	const char *pszVideoID = luaL_checkstring(L, 2);
	bool __ret = iface->AddItemPreviewVideo(handle, pszVideoID);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_AddItemPreviewVideo_user(lua_State *L) { return luasteam_UGC_AddItemPreviewVideo(L, SteamUGC()); }
static int luasteam_UGC_AddItemPreviewVideo_gs(lua_State *L) { return luasteam_UGC_AddItemPreviewVideo(L, SteamGameServerUGC()); }

// In C++:
// bool UpdateItemPreviewFile(UGCUpdateHandle_t handle, uint32 index, const char * pszPreviewFile);
// In Lua:
// bool UGC.UpdateItemPreviewFile(handle: uint64, index: int, pszPreviewFile: str)
static int luasteam_UGC_UpdateItemPreviewFile(lua_State *L, ISteamUGC *iface) {
	UGCUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
	const char *pszPreviewFile = luaL_checkstring(L, 3);
	bool __ret = iface->UpdateItemPreviewFile(handle, index, pszPreviewFile);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_UpdateItemPreviewFile_user(lua_State *L) { return luasteam_UGC_UpdateItemPreviewFile(L, SteamUGC()); }
static int luasteam_UGC_UpdateItemPreviewFile_gs(lua_State *L) { return luasteam_UGC_UpdateItemPreviewFile(L, SteamGameServerUGC()); }

// In C++:
// bool UpdateItemPreviewVideo(UGCUpdateHandle_t handle, uint32 index, const char * pszVideoID);
// In Lua:
// bool UGC.UpdateItemPreviewVideo(handle: uint64, index: int, pszVideoID: str)
static int luasteam_UGC_UpdateItemPreviewVideo(lua_State *L, ISteamUGC *iface) {
	UGCUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
	const char *pszVideoID = luaL_checkstring(L, 3);
	bool __ret = iface->UpdateItemPreviewVideo(handle, index, pszVideoID);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_UpdateItemPreviewVideo_user(lua_State *L) { return luasteam_UGC_UpdateItemPreviewVideo(L, SteamUGC()); }
static int luasteam_UGC_UpdateItemPreviewVideo_gs(lua_State *L) { return luasteam_UGC_UpdateItemPreviewVideo(L, SteamGameServerUGC()); }

// In C++:
// bool RemoveItemPreview(UGCUpdateHandle_t handle, uint32 index);
// In Lua:
// bool UGC.RemoveItemPreview(handle: uint64, index: int)
static int luasteam_UGC_RemoveItemPreview(lua_State *L, ISteamUGC *iface) {
	UGCUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
	bool __ret = iface->RemoveItemPreview(handle, index);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_RemoveItemPreview_user(lua_State *L) { return luasteam_UGC_RemoveItemPreview(L, SteamUGC()); }
static int luasteam_UGC_RemoveItemPreview_gs(lua_State *L) { return luasteam_UGC_RemoveItemPreview(L, SteamGameServerUGC()); }

// In C++:
// bool AddContentDescriptor(UGCUpdateHandle_t handle, EUGCContentDescriptorID descid);
// In Lua:
// bool UGC.AddContentDescriptor(handle: uint64, descid: int)
static int luasteam_UGC_AddContentDescriptor(lua_State *L, ISteamUGC *iface) {
	UGCUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	EUGCContentDescriptorID descid = static_cast<EUGCContentDescriptorID>(luaL_checkint(L, 2));
	bool __ret = iface->AddContentDescriptor(handle, descid);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_AddContentDescriptor_user(lua_State *L) { return luasteam_UGC_AddContentDescriptor(L, SteamUGC()); }
static int luasteam_UGC_AddContentDescriptor_gs(lua_State *L) { return luasteam_UGC_AddContentDescriptor(L, SteamGameServerUGC()); }

// In C++:
// bool RemoveContentDescriptor(UGCUpdateHandle_t handle, EUGCContentDescriptorID descid);
// In Lua:
// bool UGC.RemoveContentDescriptor(handle: uint64, descid: int)
static int luasteam_UGC_RemoveContentDescriptor(lua_State *L, ISteamUGC *iface) {
	UGCUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	EUGCContentDescriptorID descid = static_cast<EUGCContentDescriptorID>(luaL_checkint(L, 2));
	bool __ret = iface->RemoveContentDescriptor(handle, descid);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_RemoveContentDescriptor_user(lua_State *L) { return luasteam_UGC_RemoveContentDescriptor(L, SteamUGC()); }
static int luasteam_UGC_RemoveContentDescriptor_gs(lua_State *L) { return luasteam_UGC_RemoveContentDescriptor(L, SteamGameServerUGC()); }

// In C++:
// bool SetRequiredGameVersions(UGCUpdateHandle_t handle, const char * pszGameBranchMin, const char * pszGameBranchMax);
// In Lua:
// bool UGC.SetRequiredGameVersions(handle: uint64, pszGameBranchMin: str, pszGameBranchMax: str)
static int luasteam_UGC_SetRequiredGameVersions(lua_State *L, ISteamUGC *iface) {
	UGCUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	const char *pszGameBranchMin = luaL_checkstring(L, 2);
	const char *pszGameBranchMax = luaL_checkstring(L, 3);
	bool __ret = iface->SetRequiredGameVersions(handle, pszGameBranchMin, pszGameBranchMax);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_SetRequiredGameVersions_user(lua_State *L) { return luasteam_UGC_SetRequiredGameVersions(L, SteamUGC()); }
static int luasteam_UGC_SetRequiredGameVersions_gs(lua_State *L) { return luasteam_UGC_SetRequiredGameVersions(L, SteamGameServerUGC()); }

// In C++:
// SteamAPICall_t SubmitItemUpdate(UGCUpdateHandle_t handle, const char * pchChangeNote);
// In Lua:
// uint64 UGC.SubmitItemUpdate(handle: uint64, pchChangeNote: str, callback: function)
static int luasteam_UGC_SubmitItemUpdate(lua_State *L, ISteamUGC *iface) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	UGCUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	const char *pchChangeNote = luaL_checkstring(L, 2);
	SteamAPICall_t __ret = iface->SubmitItemUpdate(handle, pchChangeNote);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<SubmitItemUpdateResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<SubmitItemUpdateResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}
static int luasteam_UGC_SubmitItemUpdate_user(lua_State *L) { return luasteam_UGC_SubmitItemUpdate(L, SteamUGC()); }
static int luasteam_UGC_SubmitItemUpdate_gs(lua_State *L) { return luasteam_UGC_SubmitItemUpdate(L, SteamGameServerUGC()); }

// In C++:
// EItemUpdateStatus GetItemUpdateProgress(UGCUpdateHandle_t handle, uint64 * punBytesProcessed, uint64 * punBytesTotal);
// In Lua:
// (int, punBytesProcessed: uint64, punBytesTotal: uint64) UGC.GetItemUpdateProgress(handle: uint64)
static int luasteam_UGC_GetItemUpdateProgress(lua_State *L, ISteamUGC *iface) {
	UGCUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	uint64 punBytesProcessed;
	uint64 punBytesTotal;
	EItemUpdateStatus __ret = iface->GetItemUpdateProgress(handle, &punBytesProcessed, &punBytesTotal);
	lua_pushinteger(L, __ret);
	luasteam::pushuint64(L, punBytesProcessed);
	luasteam::pushuint64(L, punBytesTotal);
	return 3;
}
static int luasteam_UGC_GetItemUpdateProgress_user(lua_State *L) { return luasteam_UGC_GetItemUpdateProgress(L, SteamUGC()); }
static int luasteam_UGC_GetItemUpdateProgress_gs(lua_State *L) { return luasteam_UGC_GetItemUpdateProgress(L, SteamGameServerUGC()); }

// In C++:
// SteamAPICall_t SetUserItemVote(PublishedFileId_t nPublishedFileID, bool bVoteUp);
// In Lua:
// uint64 UGC.SetUserItemVote(nPublishedFileID: uint64, bVoteUp: bool, callback: function)
static int luasteam_UGC_SetUserItemVote(lua_State *L, ISteamUGC *iface) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	PublishedFileId_t nPublishedFileID(luasteam::checkuint64(L, 1));
	bool bVoteUp = lua_toboolean(L, 2);
	SteamAPICall_t __ret = iface->SetUserItemVote(nPublishedFileID, bVoteUp);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<SetUserItemVoteResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<SetUserItemVoteResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}
static int luasteam_UGC_SetUserItemVote_user(lua_State *L) { return luasteam_UGC_SetUserItemVote(L, SteamUGC()); }
static int luasteam_UGC_SetUserItemVote_gs(lua_State *L) { return luasteam_UGC_SetUserItemVote(L, SteamGameServerUGC()); }

// In C++:
// SteamAPICall_t GetUserItemVote(PublishedFileId_t nPublishedFileID);
// In Lua:
// uint64 UGC.GetUserItemVote(nPublishedFileID: uint64, callback: function)
static int luasteam_UGC_GetUserItemVote(lua_State *L, ISteamUGC *iface) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	PublishedFileId_t nPublishedFileID(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = iface->GetUserItemVote(nPublishedFileID);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<GetUserItemVoteResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<GetUserItemVoteResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}
static int luasteam_UGC_GetUserItemVote_user(lua_State *L) { return luasteam_UGC_GetUserItemVote(L, SteamUGC()); }
static int luasteam_UGC_GetUserItemVote_gs(lua_State *L) { return luasteam_UGC_GetUserItemVote(L, SteamGameServerUGC()); }

// In C++:
// SteamAPICall_t AddItemToFavorites(AppId_t nAppId, PublishedFileId_t nPublishedFileID);
// In Lua:
// uint64 UGC.AddItemToFavorites(nAppId: int, nPublishedFileID: uint64, callback: function)
static int luasteam_UGC_AddItemToFavorites(lua_State *L, ISteamUGC *iface) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	AppId_t nAppId = static_cast<AppId_t>(luaL_checkint(L, 1));
	PublishedFileId_t nPublishedFileID(luasteam::checkuint64(L, 2));
	SteamAPICall_t __ret = iface->AddItemToFavorites(nAppId, nPublishedFileID);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<UserFavoriteItemsListChanged_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<UserFavoriteItemsListChanged_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}
static int luasteam_UGC_AddItemToFavorites_user(lua_State *L) { return luasteam_UGC_AddItemToFavorites(L, SteamUGC()); }
static int luasteam_UGC_AddItemToFavorites_gs(lua_State *L) { return luasteam_UGC_AddItemToFavorites(L, SteamGameServerUGC()); }

// In C++:
// SteamAPICall_t RemoveItemFromFavorites(AppId_t nAppId, PublishedFileId_t nPublishedFileID);
// In Lua:
// uint64 UGC.RemoveItemFromFavorites(nAppId: int, nPublishedFileID: uint64, callback: function)
static int luasteam_UGC_RemoveItemFromFavorites(lua_State *L, ISteamUGC *iface) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	AppId_t nAppId = static_cast<AppId_t>(luaL_checkint(L, 1));
	PublishedFileId_t nPublishedFileID(luasteam::checkuint64(L, 2));
	SteamAPICall_t __ret = iface->RemoveItemFromFavorites(nAppId, nPublishedFileID);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<UserFavoriteItemsListChanged_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<UserFavoriteItemsListChanged_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}
static int luasteam_UGC_RemoveItemFromFavorites_user(lua_State *L) { return luasteam_UGC_RemoveItemFromFavorites(L, SteamUGC()); }
static int luasteam_UGC_RemoveItemFromFavorites_gs(lua_State *L) { return luasteam_UGC_RemoveItemFromFavorites(L, SteamGameServerUGC()); }

// In C++:
// SteamAPICall_t SubscribeItem(PublishedFileId_t nPublishedFileID);
// In Lua:
// uint64 UGC.SubscribeItem(nPublishedFileID: uint64, callback: function)
static int luasteam_UGC_SubscribeItem(lua_State *L, ISteamUGC *iface) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	PublishedFileId_t nPublishedFileID(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = iface->SubscribeItem(nPublishedFileID);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<RemoteStorageSubscribePublishedFileResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<RemoteStorageSubscribePublishedFileResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}
static int luasteam_UGC_SubscribeItem_user(lua_State *L) { return luasteam_UGC_SubscribeItem(L, SteamUGC()); }
static int luasteam_UGC_SubscribeItem_gs(lua_State *L) { return luasteam_UGC_SubscribeItem(L, SteamGameServerUGC()); }

// In C++:
// SteamAPICall_t UnsubscribeItem(PublishedFileId_t nPublishedFileID);
// In Lua:
// uint64 UGC.UnsubscribeItem(nPublishedFileID: uint64, callback: function)
static int luasteam_UGC_UnsubscribeItem(lua_State *L, ISteamUGC *iface) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	PublishedFileId_t nPublishedFileID(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = iface->UnsubscribeItem(nPublishedFileID);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<RemoteStorageUnsubscribePublishedFileResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<RemoteStorageUnsubscribePublishedFileResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}
static int luasteam_UGC_UnsubscribeItem_user(lua_State *L) { return luasteam_UGC_UnsubscribeItem(L, SteamUGC()); }
static int luasteam_UGC_UnsubscribeItem_gs(lua_State *L) { return luasteam_UGC_UnsubscribeItem(L, SteamGameServerUGC()); }

// In C++:
// uint32 GetNumSubscribedItems(bool bIncludeLocallyDisabled);
// In Lua:
// int UGC.GetNumSubscribedItems(bIncludeLocallyDisabled: bool)
static int luasteam_UGC_GetNumSubscribedItems(lua_State *L, ISteamUGC *iface) {
	bool bIncludeLocallyDisabled = lua_toboolean(L, 1);
	uint32 __ret = iface->GetNumSubscribedItems(bIncludeLocallyDisabled);
	lua_pushinteger(L, __ret);
	return 1;
}
static int luasteam_UGC_GetNumSubscribedItems_user(lua_State *L) { return luasteam_UGC_GetNumSubscribedItems(L, SteamUGC()); }
static int luasteam_UGC_GetNumSubscribedItems_gs(lua_State *L) { return luasteam_UGC_GetNumSubscribedItems(L, SteamGameServerUGC()); }

// In C++:
// uint32 GetSubscribedItems(PublishedFileId_t * pvecPublishedFileID, uint32 cMaxEntries, bool bIncludeLocallyDisabled);
// In Lua:
// (int, pvecPublishedFileID: uint64[]) UGC.GetSubscribedItems(cMaxEntries: int, bIncludeLocallyDisabled: bool)
static int luasteam_UGC_GetSubscribedItems(lua_State *L, ISteamUGC *iface) {
	uint32 cMaxEntries = luaL_checkint(L, 1);
	std::vector<PublishedFileId_t> pvecPublishedFileID(cMaxEntries);
	bool bIncludeLocallyDisabled = lua_toboolean(L, 2);
	uint32 __ret = iface->GetSubscribedItems(pvecPublishedFileID.data(), cMaxEntries, bIncludeLocallyDisabled);
	lua_pushinteger(L, __ret);
	lua_createtable(L, __ret, 0);
	for(decltype(__ret) i = 0; i < __ret; i++) {
		luasteam::pushuint64(L, pvecPublishedFileID[i]);
		lua_rawseti(L, -2, i+1);
	}
	return 2;
}
static int luasteam_UGC_GetSubscribedItems_user(lua_State *L) { return luasteam_UGC_GetSubscribedItems(L, SteamUGC()); }
static int luasteam_UGC_GetSubscribedItems_gs(lua_State *L) { return luasteam_UGC_GetSubscribedItems(L, SteamGameServerUGC()); }

// In C++:
// uint32 GetItemState(PublishedFileId_t nPublishedFileID);
// In Lua:
// int UGC.GetItemState(nPublishedFileID: uint64)
static int luasteam_UGC_GetItemState(lua_State *L, ISteamUGC *iface) {
	PublishedFileId_t nPublishedFileID(luasteam::checkuint64(L, 1));
	uint32 __ret = iface->GetItemState(nPublishedFileID);
	lua_pushinteger(L, __ret);
	return 1;
}
static int luasteam_UGC_GetItemState_user(lua_State *L) { return luasteam_UGC_GetItemState(L, SteamUGC()); }
static int luasteam_UGC_GetItemState_gs(lua_State *L) { return luasteam_UGC_GetItemState(L, SteamGameServerUGC()); }

// In C++:
// bool GetItemInstallInfo(PublishedFileId_t nPublishedFileID, uint64 * punSizeOnDisk, char * pchFolder, uint32 cchFolderSize, uint32 * punTimeStamp);
// In Lua:
// (bool, punSizeOnDisk: uint64, pchFolder: str, punTimeStamp: int) UGC.GetItemInstallInfo(nPublishedFileID: uint64, cchFolderSize: int)
static int luasteam_UGC_GetItemInstallInfo(lua_State *L, ISteamUGC *iface) {
	PublishedFileId_t nPublishedFileID(luasteam::checkuint64(L, 1));
	uint64 punSizeOnDisk;
	uint32 cchFolderSize = luaL_checkint(L, 2);
	std::vector<char> pchFolder(cchFolderSize);
	uint32 punTimeStamp;
	bool __ret = iface->GetItemInstallInfo(nPublishedFileID, &punSizeOnDisk, pchFolder.data(), cchFolderSize, &punTimeStamp);
	lua_pushboolean(L, __ret);
	luasteam::pushuint64(L, punSizeOnDisk);
	lua_pushstring(L, reinterpret_cast<const char*>(pchFolder.data()));
	lua_pushinteger(L, punTimeStamp);
	return 4;
}
static int luasteam_UGC_GetItemInstallInfo_user(lua_State *L) { return luasteam_UGC_GetItemInstallInfo(L, SteamUGC()); }
static int luasteam_UGC_GetItemInstallInfo_gs(lua_State *L) { return luasteam_UGC_GetItemInstallInfo(L, SteamGameServerUGC()); }

// In C++:
// bool GetItemDownloadInfo(PublishedFileId_t nPublishedFileID, uint64 * punBytesDownloaded, uint64 * punBytesTotal);
// In Lua:
// (bool, punBytesDownloaded: uint64, punBytesTotal: uint64) UGC.GetItemDownloadInfo(nPublishedFileID: uint64)
static int luasteam_UGC_GetItemDownloadInfo(lua_State *L, ISteamUGC *iface) {
	PublishedFileId_t nPublishedFileID(luasteam::checkuint64(L, 1));
	uint64 punBytesDownloaded;
	uint64 punBytesTotal;
	bool __ret = iface->GetItemDownloadInfo(nPublishedFileID, &punBytesDownloaded, &punBytesTotal);
	lua_pushboolean(L, __ret);
	luasteam::pushuint64(L, punBytesDownloaded);
	luasteam::pushuint64(L, punBytesTotal);
	return 3;
}
static int luasteam_UGC_GetItemDownloadInfo_user(lua_State *L) { return luasteam_UGC_GetItemDownloadInfo(L, SteamUGC()); }
static int luasteam_UGC_GetItemDownloadInfo_gs(lua_State *L) { return luasteam_UGC_GetItemDownloadInfo(L, SteamGameServerUGC()); }

// In C++:
// bool DownloadItem(PublishedFileId_t nPublishedFileID, bool bHighPriority);
// In Lua:
// bool UGC.DownloadItem(nPublishedFileID: uint64, bHighPriority: bool)
static int luasteam_UGC_DownloadItem(lua_State *L, ISteamUGC *iface) {
	PublishedFileId_t nPublishedFileID(luasteam::checkuint64(L, 1));
	bool bHighPriority = lua_toboolean(L, 2);
	bool __ret = iface->DownloadItem(nPublishedFileID, bHighPriority);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_DownloadItem_user(lua_State *L) { return luasteam_UGC_DownloadItem(L, SteamUGC()); }
static int luasteam_UGC_DownloadItem_gs(lua_State *L) { return luasteam_UGC_DownloadItem(L, SteamGameServerUGC()); }

// In C++:
// bool BInitWorkshopForGameServer(DepotId_t unWorkshopDepotID, const char * pszFolder);
// In Lua:
// bool UGC.BInitWorkshopForGameServer(unWorkshopDepotID: int, pszFolder: str)
static int luasteam_UGC_BInitWorkshopForGameServer(lua_State *L, ISteamUGC *iface) {
	DepotId_t unWorkshopDepotID = static_cast<DepotId_t>(luaL_checkint(L, 1));
	const char *pszFolder = luaL_checkstring(L, 2);
	bool __ret = iface->BInitWorkshopForGameServer(unWorkshopDepotID, pszFolder);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_BInitWorkshopForGameServer_user(lua_State *L) { return luasteam_UGC_BInitWorkshopForGameServer(L, SteamUGC()); }
static int luasteam_UGC_BInitWorkshopForGameServer_gs(lua_State *L) { return luasteam_UGC_BInitWorkshopForGameServer(L, SteamGameServerUGC()); }

// In C++:
// void SuspendDownloads(bool bSuspend);
// In Lua:
// UGC.SuspendDownloads(bSuspend: bool)
static int luasteam_UGC_SuspendDownloads(lua_State *L, ISteamUGC *iface) {
	bool bSuspend = lua_toboolean(L, 1);
	iface->SuspendDownloads(bSuspend);
	return 0;
}
static int luasteam_UGC_SuspendDownloads_user(lua_State *L) { return luasteam_UGC_SuspendDownloads(L, SteamUGC()); }
static int luasteam_UGC_SuspendDownloads_gs(lua_State *L) { return luasteam_UGC_SuspendDownloads(L, SteamGameServerUGC()); }

// In C++:
// SteamAPICall_t StartPlaytimeTracking(const PublishedFileId_t * pvecPublishedFileID, uint32 unNumPublishedFileIDs);
// In Lua:
// uint64 UGC.StartPlaytimeTracking(pvecPublishedFileID: uint64[], unNumPublishedFileIDs: int, callback: function)
static int luasteam_UGC_StartPlaytimeTracking(lua_State *L, ISteamUGC *iface) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	uint32 unNumPublishedFileIDs = luaL_checkint(L, 2);
	luaL_checktype(L, 1, LUA_TTABLE);
	std::vector<PublishedFileId_t> pvecPublishedFileID(unNumPublishedFileIDs);
	for(decltype(unNumPublishedFileIDs) i = 0; i < unNumPublishedFileIDs; i++) {
		lua_rawgeti(L, 1, i+1);
		pvecPublishedFileID[i] = luasteam::checkuint64(L, -1);
		lua_pop(L, 1);
	}
	SteamAPICall_t __ret = iface->StartPlaytimeTracking(pvecPublishedFileID.data(), unNumPublishedFileIDs);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<StartPlaytimeTrackingResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<StartPlaytimeTrackingResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}
static int luasteam_UGC_StartPlaytimeTracking_user(lua_State *L) { return luasteam_UGC_StartPlaytimeTracking(L, SteamUGC()); }
static int luasteam_UGC_StartPlaytimeTracking_gs(lua_State *L) { return luasteam_UGC_StartPlaytimeTracking(L, SteamGameServerUGC()); }

// In C++:
// SteamAPICall_t StopPlaytimeTracking(const PublishedFileId_t * pvecPublishedFileID, uint32 unNumPublishedFileIDs);
// In Lua:
// uint64 UGC.StopPlaytimeTracking(pvecPublishedFileID: uint64[], unNumPublishedFileIDs: int, callback: function)
static int luasteam_UGC_StopPlaytimeTracking(lua_State *L, ISteamUGC *iface) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	uint32 unNumPublishedFileIDs = luaL_checkint(L, 2);
	luaL_checktype(L, 1, LUA_TTABLE);
	std::vector<PublishedFileId_t> pvecPublishedFileID(unNumPublishedFileIDs);
	for(decltype(unNumPublishedFileIDs) i = 0; i < unNumPublishedFileIDs; i++) {
		lua_rawgeti(L, 1, i+1);
		pvecPublishedFileID[i] = luasteam::checkuint64(L, -1);
		lua_pop(L, 1);
	}
	SteamAPICall_t __ret = iface->StopPlaytimeTracking(pvecPublishedFileID.data(), unNumPublishedFileIDs);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<StopPlaytimeTrackingResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<StopPlaytimeTrackingResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}
static int luasteam_UGC_StopPlaytimeTracking_user(lua_State *L) { return luasteam_UGC_StopPlaytimeTracking(L, SteamUGC()); }
static int luasteam_UGC_StopPlaytimeTracking_gs(lua_State *L) { return luasteam_UGC_StopPlaytimeTracking(L, SteamGameServerUGC()); }

// In C++:
// SteamAPICall_t StopPlaytimeTrackingForAllItems();
// In Lua:
// uint64 UGC.StopPlaytimeTrackingForAllItems(callback: function)
static int luasteam_UGC_StopPlaytimeTrackingForAllItems(lua_State *L, ISteamUGC *iface) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	SteamAPICall_t __ret = iface->StopPlaytimeTrackingForAllItems();
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<StopPlaytimeTrackingResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<StopPlaytimeTrackingResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}
static int luasteam_UGC_StopPlaytimeTrackingForAllItems_user(lua_State *L) { return luasteam_UGC_StopPlaytimeTrackingForAllItems(L, SteamUGC()); }
static int luasteam_UGC_StopPlaytimeTrackingForAllItems_gs(lua_State *L) { return luasteam_UGC_StopPlaytimeTrackingForAllItems(L, SteamGameServerUGC()); }

// In C++:
// SteamAPICall_t AddDependency(PublishedFileId_t nParentPublishedFileID, PublishedFileId_t nChildPublishedFileID);
// In Lua:
// uint64 UGC.AddDependency(nParentPublishedFileID: uint64, nChildPublishedFileID: uint64, callback: function)
static int luasteam_UGC_AddDependency(lua_State *L, ISteamUGC *iface) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	PublishedFileId_t nParentPublishedFileID(luasteam::checkuint64(L, 1));
	PublishedFileId_t nChildPublishedFileID(luasteam::checkuint64(L, 2));
	SteamAPICall_t __ret = iface->AddDependency(nParentPublishedFileID, nChildPublishedFileID);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<AddUGCDependencyResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<AddUGCDependencyResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}
static int luasteam_UGC_AddDependency_user(lua_State *L) { return luasteam_UGC_AddDependency(L, SteamUGC()); }
static int luasteam_UGC_AddDependency_gs(lua_State *L) { return luasteam_UGC_AddDependency(L, SteamGameServerUGC()); }

// In C++:
// SteamAPICall_t RemoveDependency(PublishedFileId_t nParentPublishedFileID, PublishedFileId_t nChildPublishedFileID);
// In Lua:
// uint64 UGC.RemoveDependency(nParentPublishedFileID: uint64, nChildPublishedFileID: uint64, callback: function)
static int luasteam_UGC_RemoveDependency(lua_State *L, ISteamUGC *iface) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	PublishedFileId_t nParentPublishedFileID(luasteam::checkuint64(L, 1));
	PublishedFileId_t nChildPublishedFileID(luasteam::checkuint64(L, 2));
	SteamAPICall_t __ret = iface->RemoveDependency(nParentPublishedFileID, nChildPublishedFileID);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<RemoveUGCDependencyResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<RemoveUGCDependencyResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}
static int luasteam_UGC_RemoveDependency_user(lua_State *L) { return luasteam_UGC_RemoveDependency(L, SteamUGC()); }
static int luasteam_UGC_RemoveDependency_gs(lua_State *L) { return luasteam_UGC_RemoveDependency(L, SteamGameServerUGC()); }

// In C++:
// SteamAPICall_t AddAppDependency(PublishedFileId_t nPublishedFileID, AppId_t nAppID);
// In Lua:
// uint64 UGC.AddAppDependency(nPublishedFileID: uint64, nAppID: int, callback: function)
static int luasteam_UGC_AddAppDependency(lua_State *L, ISteamUGC *iface) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	PublishedFileId_t nPublishedFileID(luasteam::checkuint64(L, 1));
	AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 2));
	SteamAPICall_t __ret = iface->AddAppDependency(nPublishedFileID, nAppID);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<AddAppDependencyResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<AddAppDependencyResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}
static int luasteam_UGC_AddAppDependency_user(lua_State *L) { return luasteam_UGC_AddAppDependency(L, SteamUGC()); }
static int luasteam_UGC_AddAppDependency_gs(lua_State *L) { return luasteam_UGC_AddAppDependency(L, SteamGameServerUGC()); }

// In C++:
// SteamAPICall_t RemoveAppDependency(PublishedFileId_t nPublishedFileID, AppId_t nAppID);
// In Lua:
// uint64 UGC.RemoveAppDependency(nPublishedFileID: uint64, nAppID: int, callback: function)
static int luasteam_UGC_RemoveAppDependency(lua_State *L, ISteamUGC *iface) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	PublishedFileId_t nPublishedFileID(luasteam::checkuint64(L, 1));
	AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 2));
	SteamAPICall_t __ret = iface->RemoveAppDependency(nPublishedFileID, nAppID);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<RemoveAppDependencyResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<RemoveAppDependencyResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}
static int luasteam_UGC_RemoveAppDependency_user(lua_State *L) { return luasteam_UGC_RemoveAppDependency(L, SteamUGC()); }
static int luasteam_UGC_RemoveAppDependency_gs(lua_State *L) { return luasteam_UGC_RemoveAppDependency(L, SteamGameServerUGC()); }

// In C++:
// SteamAPICall_t GetAppDependencies(PublishedFileId_t nPublishedFileID);
// In Lua:
// uint64 UGC.GetAppDependencies(nPublishedFileID: uint64, callback: function)
static int luasteam_UGC_GetAppDependencies(lua_State *L, ISteamUGC *iface) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	PublishedFileId_t nPublishedFileID(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = iface->GetAppDependencies(nPublishedFileID);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<GetAppDependenciesResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<GetAppDependenciesResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}
static int luasteam_UGC_GetAppDependencies_user(lua_State *L) { return luasteam_UGC_GetAppDependencies(L, SteamUGC()); }
static int luasteam_UGC_GetAppDependencies_gs(lua_State *L) { return luasteam_UGC_GetAppDependencies(L, SteamGameServerUGC()); }

// In C++:
// SteamAPICall_t DeleteItem(PublishedFileId_t nPublishedFileID);
// In Lua:
// uint64 UGC.DeleteItem(nPublishedFileID: uint64, callback: function)
static int luasteam_UGC_DeleteItem(lua_State *L, ISteamUGC *iface) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	PublishedFileId_t nPublishedFileID(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = iface->DeleteItem(nPublishedFileID);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<DeleteItemResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<DeleteItemResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}
static int luasteam_UGC_DeleteItem_user(lua_State *L) { return luasteam_UGC_DeleteItem(L, SteamUGC()); }
static int luasteam_UGC_DeleteItem_gs(lua_State *L) { return luasteam_UGC_DeleteItem(L, SteamGameServerUGC()); }

// In C++:
// bool ShowWorkshopEULA();
// In Lua:
// bool UGC.ShowWorkshopEULA()
static int luasteam_UGC_ShowWorkshopEULA(lua_State *L, ISteamUGC *iface) {
	bool __ret = iface->ShowWorkshopEULA();
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_UGC_ShowWorkshopEULA_user(lua_State *L) { return luasteam_UGC_ShowWorkshopEULA(L, SteamUGC()); }
static int luasteam_UGC_ShowWorkshopEULA_gs(lua_State *L) { return luasteam_UGC_ShowWorkshopEULA(L, SteamGameServerUGC()); }

// In C++:
// SteamAPICall_t GetWorkshopEULAStatus();
// In Lua:
// uint64 UGC.GetWorkshopEULAStatus(callback: function)
static int luasteam_UGC_GetWorkshopEULAStatus(lua_State *L, ISteamUGC *iface) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	SteamAPICall_t __ret = iface->GetWorkshopEULAStatus();
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<WorkshopEULAStatus_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<WorkshopEULAStatus_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}
static int luasteam_UGC_GetWorkshopEULAStatus_user(lua_State *L) { return luasteam_UGC_GetWorkshopEULAStatus(L, SteamUGC()); }
static int luasteam_UGC_GetWorkshopEULAStatus_gs(lua_State *L) { return luasteam_UGC_GetWorkshopEULAStatus(L, SteamGameServerUGC()); }

// In C++:
// uint32 GetUserContentDescriptorPreferences(EUGCContentDescriptorID * pvecDescriptors, uint32 cMaxEntries);
// In Lua:
// (int, pvecDescriptors: int) UGC.GetUserContentDescriptorPreferences(cMaxEntries: int)
static int luasteam_UGC_GetUserContentDescriptorPreferences(lua_State *L, ISteamUGC *iface) {
	EUGCContentDescriptorID pvecDescriptors;
	uint32 cMaxEntries = static_cast<uint32>(luaL_checkint(L, 1));
	uint32 __ret = iface->GetUserContentDescriptorPreferences(&pvecDescriptors, cMaxEntries);
	lua_pushinteger(L, __ret);
	lua_pushinteger(L, pvecDescriptors);
	return 2;
}
static int luasteam_UGC_GetUserContentDescriptorPreferences_user(lua_State *L) { return luasteam_UGC_GetUserContentDescriptorPreferences(L, SteamUGC()); }
static int luasteam_UGC_GetUserContentDescriptorPreferences_gs(lua_State *L) { return luasteam_UGC_GetUserContentDescriptorPreferences(L, SteamGameServerUGC()); }

// In C++:
// bool SetItemsDisabledLocally(PublishedFileId_t * pvecPublishedFileIDs, uint32 unNumPublishedFileIDs, bool bDisabledLocally);
// In Lua:
// (bool, pvecPublishedFileIDs: uint64) UGC.SetItemsDisabledLocally(unNumPublishedFileIDs: int, bDisabledLocally: bool)
static int luasteam_UGC_SetItemsDisabledLocally(lua_State *L, ISteamUGC *iface) {
	PublishedFileId_t pvecPublishedFileIDs;
	uint32 unNumPublishedFileIDs = static_cast<uint32>(luaL_checkint(L, 1));
	bool bDisabledLocally = lua_toboolean(L, 2);
	bool __ret = iface->SetItemsDisabledLocally(&pvecPublishedFileIDs, unNumPublishedFileIDs, bDisabledLocally);
	lua_pushboolean(L, __ret);
	luasteam::pushuint64(L, pvecPublishedFileIDs);
	return 2;
}
static int luasteam_UGC_SetItemsDisabledLocally_user(lua_State *L) { return luasteam_UGC_SetItemsDisabledLocally(L, SteamUGC()); }
static int luasteam_UGC_SetItemsDisabledLocally_gs(lua_State *L) { return luasteam_UGC_SetItemsDisabledLocally(L, SteamGameServerUGC()); }

// In C++:
// bool SetSubscriptionsLoadOrder(PublishedFileId_t * pvecPublishedFileIDs, uint32 unNumPublishedFileIDs);
// In Lua:
// (bool, pvecPublishedFileIDs: uint64) UGC.SetSubscriptionsLoadOrder(unNumPublishedFileIDs: int)
static int luasteam_UGC_SetSubscriptionsLoadOrder(lua_State *L, ISteamUGC *iface) {
	PublishedFileId_t pvecPublishedFileIDs;
	uint32 unNumPublishedFileIDs = static_cast<uint32>(luaL_checkint(L, 1));
	bool __ret = iface->SetSubscriptionsLoadOrder(&pvecPublishedFileIDs, unNumPublishedFileIDs);
	lua_pushboolean(L, __ret);
	luasteam::pushuint64(L, pvecPublishedFileIDs);
	return 2;
}
static int luasteam_UGC_SetSubscriptionsLoadOrder_user(lua_State *L) { return luasteam_UGC_SetSubscriptionsLoadOrder(L, SteamUGC()); }
static int luasteam_UGC_SetSubscriptionsLoadOrder_gs(lua_State *L) { return luasteam_UGC_SetSubscriptionsLoadOrder(L, SteamGameServerUGC()); }

void register_UGC_auto(lua_State *L, bool is_gs) {
	add_func(L, "CreateQueryUserUGCRequest", is_gs ? luasteam_UGC_CreateQueryUserUGCRequest_gs : luasteam_UGC_CreateQueryUserUGCRequest_user);
	add_func(L, "CreateQueryAllUGCRequestPage", is_gs ? luasteam_UGC_CreateQueryAllUGCRequestPage_gs : luasteam_UGC_CreateQueryAllUGCRequestPage_user);
	add_func(L, "CreateQueryUGCDetailsRequest", is_gs ? luasteam_UGC_CreateQueryUGCDetailsRequest_gs : luasteam_UGC_CreateQueryUGCDetailsRequest_user);
	add_func(L, "SendQueryUGCRequest", is_gs ? luasteam_UGC_SendQueryUGCRequest_gs : luasteam_UGC_SendQueryUGCRequest_user);
	add_func(L, "GetQueryUGCResult", is_gs ? luasteam_UGC_GetQueryUGCResult_gs : luasteam_UGC_GetQueryUGCResult_user);
	add_func(L, "GetQueryUGCNumTags", is_gs ? luasteam_UGC_GetQueryUGCNumTags_gs : luasteam_UGC_GetQueryUGCNumTags_user);
	add_func(L, "GetQueryUGCTag", is_gs ? luasteam_UGC_GetQueryUGCTag_gs : luasteam_UGC_GetQueryUGCTag_user);
	add_func(L, "GetQueryUGCTagDisplayName", is_gs ? luasteam_UGC_GetQueryUGCTagDisplayName_gs : luasteam_UGC_GetQueryUGCTagDisplayName_user);
	add_func(L, "GetQueryUGCPreviewURL", is_gs ? luasteam_UGC_GetQueryUGCPreviewURL_gs : luasteam_UGC_GetQueryUGCPreviewURL_user);
	add_func(L, "GetQueryUGCMetadata", is_gs ? luasteam_UGC_GetQueryUGCMetadata_gs : luasteam_UGC_GetQueryUGCMetadata_user);
	add_func(L, "GetQueryUGCChildren", is_gs ? luasteam_UGC_GetQueryUGCChildren_gs : luasteam_UGC_GetQueryUGCChildren_user);
	add_func(L, "GetQueryUGCStatistic", is_gs ? luasteam_UGC_GetQueryUGCStatistic_gs : luasteam_UGC_GetQueryUGCStatistic_user);
	add_func(L, "GetQueryUGCNumAdditionalPreviews", is_gs ? luasteam_UGC_GetQueryUGCNumAdditionalPreviews_gs : luasteam_UGC_GetQueryUGCNumAdditionalPreviews_user);
	add_func(L, "GetQueryUGCAdditionalPreview", is_gs ? luasteam_UGC_GetQueryUGCAdditionalPreview_gs : luasteam_UGC_GetQueryUGCAdditionalPreview_user);
	add_func(L, "GetQueryUGCNumKeyValueTags", is_gs ? luasteam_UGC_GetQueryUGCNumKeyValueTags_gs : luasteam_UGC_GetQueryUGCNumKeyValueTags_user);
	add_func(L, "GetQueryUGCKeyValueTag", is_gs ? luasteam_UGC_GetQueryUGCKeyValueTag_gs : luasteam_UGC_GetQueryUGCKeyValueTag_user);
	add_func(L, "GetNumSupportedGameVersions", is_gs ? luasteam_UGC_GetNumSupportedGameVersions_gs : luasteam_UGC_GetNumSupportedGameVersions_user);
	add_func(L, "GetSupportedGameVersionData", is_gs ? luasteam_UGC_GetSupportedGameVersionData_gs : luasteam_UGC_GetSupportedGameVersionData_user);
	add_func(L, "GetQueryUGCContentDescriptors", is_gs ? luasteam_UGC_GetQueryUGCContentDescriptors_gs : luasteam_UGC_GetQueryUGCContentDescriptors_user);
	add_func(L, "ReleaseQueryUGCRequest", is_gs ? luasteam_UGC_ReleaseQueryUGCRequest_gs : luasteam_UGC_ReleaseQueryUGCRequest_user);
	add_func(L, "AddRequiredTag", is_gs ? luasteam_UGC_AddRequiredTag_gs : luasteam_UGC_AddRequiredTag_user);
	add_func(L, "AddRequiredTagGroup", is_gs ? luasteam_UGC_AddRequiredTagGroup_gs : luasteam_UGC_AddRequiredTagGroup_user);
	add_func(L, "AddExcludedTag", is_gs ? luasteam_UGC_AddExcludedTag_gs : luasteam_UGC_AddExcludedTag_user);
	add_func(L, "SetReturnOnlyIDs", is_gs ? luasteam_UGC_SetReturnOnlyIDs_gs : luasteam_UGC_SetReturnOnlyIDs_user);
	add_func(L, "SetReturnKeyValueTags", is_gs ? luasteam_UGC_SetReturnKeyValueTags_gs : luasteam_UGC_SetReturnKeyValueTags_user);
	add_func(L, "SetReturnLongDescription", is_gs ? luasteam_UGC_SetReturnLongDescription_gs : luasteam_UGC_SetReturnLongDescription_user);
	add_func(L, "SetReturnMetadata", is_gs ? luasteam_UGC_SetReturnMetadata_gs : luasteam_UGC_SetReturnMetadata_user);
	add_func(L, "SetReturnChildren", is_gs ? luasteam_UGC_SetReturnChildren_gs : luasteam_UGC_SetReturnChildren_user);
	add_func(L, "SetReturnAdditionalPreviews", is_gs ? luasteam_UGC_SetReturnAdditionalPreviews_gs : luasteam_UGC_SetReturnAdditionalPreviews_user);
	add_func(L, "SetReturnTotalOnly", is_gs ? luasteam_UGC_SetReturnTotalOnly_gs : luasteam_UGC_SetReturnTotalOnly_user);
	add_func(L, "SetReturnPlaytimeStats", is_gs ? luasteam_UGC_SetReturnPlaytimeStats_gs : luasteam_UGC_SetReturnPlaytimeStats_user);
	add_func(L, "SetLanguage", is_gs ? luasteam_UGC_SetLanguage_gs : luasteam_UGC_SetLanguage_user);
	add_func(L, "SetAllowCachedResponse", is_gs ? luasteam_UGC_SetAllowCachedResponse_gs : luasteam_UGC_SetAllowCachedResponse_user);
	add_func(L, "SetAdminQuery", is_gs ? luasteam_UGC_SetAdminQuery_gs : luasteam_UGC_SetAdminQuery_user);
	add_func(L, "SetCloudFileNameFilter", is_gs ? luasteam_UGC_SetCloudFileNameFilter_gs : luasteam_UGC_SetCloudFileNameFilter_user);
	add_func(L, "SetMatchAnyTag", is_gs ? luasteam_UGC_SetMatchAnyTag_gs : luasteam_UGC_SetMatchAnyTag_user);
	add_func(L, "SetSearchText", is_gs ? luasteam_UGC_SetSearchText_gs : luasteam_UGC_SetSearchText_user);
	add_func(L, "SetRankedByTrendDays", is_gs ? luasteam_UGC_SetRankedByTrendDays_gs : luasteam_UGC_SetRankedByTrendDays_user);
	add_func(L, "SetTimeCreatedDateRange", is_gs ? luasteam_UGC_SetTimeCreatedDateRange_gs : luasteam_UGC_SetTimeCreatedDateRange_user);
	add_func(L, "SetTimeUpdatedDateRange", is_gs ? luasteam_UGC_SetTimeUpdatedDateRange_gs : luasteam_UGC_SetTimeUpdatedDateRange_user);
	add_func(L, "AddRequiredKeyValueTag", is_gs ? luasteam_UGC_AddRequiredKeyValueTag_gs : luasteam_UGC_AddRequiredKeyValueTag_user);
	add_func(L, "RequestUGCDetails", is_gs ? luasteam_UGC_RequestUGCDetails_gs : luasteam_UGC_RequestUGCDetails_user);
	add_func(L, "CreateItem", is_gs ? luasteam_UGC_CreateItem_gs : luasteam_UGC_CreateItem_user);
	add_func(L, "StartItemUpdate", is_gs ? luasteam_UGC_StartItemUpdate_gs : luasteam_UGC_StartItemUpdate_user);
	add_func(L, "SetItemTitle", is_gs ? luasteam_UGC_SetItemTitle_gs : luasteam_UGC_SetItemTitle_user);
	add_func(L, "SetItemDescription", is_gs ? luasteam_UGC_SetItemDescription_gs : luasteam_UGC_SetItemDescription_user);
	add_func(L, "SetItemUpdateLanguage", is_gs ? luasteam_UGC_SetItemUpdateLanguage_gs : luasteam_UGC_SetItemUpdateLanguage_user);
	add_func(L, "SetItemMetadata", is_gs ? luasteam_UGC_SetItemMetadata_gs : luasteam_UGC_SetItemMetadata_user);
	add_func(L, "SetItemVisibility", is_gs ? luasteam_UGC_SetItemVisibility_gs : luasteam_UGC_SetItemVisibility_user);
	add_func(L, "SetItemTags", is_gs ? luasteam_UGC_SetItemTags_gs : luasteam_UGC_SetItemTags_user);
	add_func(L, "SetItemContent", is_gs ? luasteam_UGC_SetItemContent_gs : luasteam_UGC_SetItemContent_user);
	add_func(L, "SetItemPreview", is_gs ? luasteam_UGC_SetItemPreview_gs : luasteam_UGC_SetItemPreview_user);
	add_func(L, "SetAllowLegacyUpload", is_gs ? luasteam_UGC_SetAllowLegacyUpload_gs : luasteam_UGC_SetAllowLegacyUpload_user);
	add_func(L, "RemoveAllItemKeyValueTags", is_gs ? luasteam_UGC_RemoveAllItemKeyValueTags_gs : luasteam_UGC_RemoveAllItemKeyValueTags_user);
	add_func(L, "RemoveItemKeyValueTags", is_gs ? luasteam_UGC_RemoveItemKeyValueTags_gs : luasteam_UGC_RemoveItemKeyValueTags_user);
	add_func(L, "AddItemKeyValueTag", is_gs ? luasteam_UGC_AddItemKeyValueTag_gs : luasteam_UGC_AddItemKeyValueTag_user);
	add_func(L, "AddItemPreviewFile", is_gs ? luasteam_UGC_AddItemPreviewFile_gs : luasteam_UGC_AddItemPreviewFile_user);
	add_func(L, "AddItemPreviewVideo", is_gs ? luasteam_UGC_AddItemPreviewVideo_gs : luasteam_UGC_AddItemPreviewVideo_user);
	add_func(L, "UpdateItemPreviewFile", is_gs ? luasteam_UGC_UpdateItemPreviewFile_gs : luasteam_UGC_UpdateItemPreviewFile_user);
	add_func(L, "UpdateItemPreviewVideo", is_gs ? luasteam_UGC_UpdateItemPreviewVideo_gs : luasteam_UGC_UpdateItemPreviewVideo_user);
	add_func(L, "RemoveItemPreview", is_gs ? luasteam_UGC_RemoveItemPreview_gs : luasteam_UGC_RemoveItemPreview_user);
	add_func(L, "AddContentDescriptor", is_gs ? luasteam_UGC_AddContentDescriptor_gs : luasteam_UGC_AddContentDescriptor_user);
	add_func(L, "RemoveContentDescriptor", is_gs ? luasteam_UGC_RemoveContentDescriptor_gs : luasteam_UGC_RemoveContentDescriptor_user);
	add_func(L, "SetRequiredGameVersions", is_gs ? luasteam_UGC_SetRequiredGameVersions_gs : luasteam_UGC_SetRequiredGameVersions_user);
	add_func(L, "SubmitItemUpdate", is_gs ? luasteam_UGC_SubmitItemUpdate_gs : luasteam_UGC_SubmitItemUpdate_user);
	add_func(L, "GetItemUpdateProgress", is_gs ? luasteam_UGC_GetItemUpdateProgress_gs : luasteam_UGC_GetItemUpdateProgress_user);
	add_func(L, "SetUserItemVote", is_gs ? luasteam_UGC_SetUserItemVote_gs : luasteam_UGC_SetUserItemVote_user);
	add_func(L, "GetUserItemVote", is_gs ? luasteam_UGC_GetUserItemVote_gs : luasteam_UGC_GetUserItemVote_user);
	add_func(L, "AddItemToFavorites", is_gs ? luasteam_UGC_AddItemToFavorites_gs : luasteam_UGC_AddItemToFavorites_user);
	add_func(L, "RemoveItemFromFavorites", is_gs ? luasteam_UGC_RemoveItemFromFavorites_gs : luasteam_UGC_RemoveItemFromFavorites_user);
	add_func(L, "SubscribeItem", is_gs ? luasteam_UGC_SubscribeItem_gs : luasteam_UGC_SubscribeItem_user);
	add_func(L, "UnsubscribeItem", is_gs ? luasteam_UGC_UnsubscribeItem_gs : luasteam_UGC_UnsubscribeItem_user);
	add_func(L, "GetNumSubscribedItems", is_gs ? luasteam_UGC_GetNumSubscribedItems_gs : luasteam_UGC_GetNumSubscribedItems_user);
	add_func(L, "GetSubscribedItems", is_gs ? luasteam_UGC_GetSubscribedItems_gs : luasteam_UGC_GetSubscribedItems_user);
	add_func(L, "GetItemState", is_gs ? luasteam_UGC_GetItemState_gs : luasteam_UGC_GetItemState_user);
	add_func(L, "GetItemInstallInfo", is_gs ? luasteam_UGC_GetItemInstallInfo_gs : luasteam_UGC_GetItemInstallInfo_user);
	add_func(L, "GetItemDownloadInfo", is_gs ? luasteam_UGC_GetItemDownloadInfo_gs : luasteam_UGC_GetItemDownloadInfo_user);
	add_func(L, "DownloadItem", is_gs ? luasteam_UGC_DownloadItem_gs : luasteam_UGC_DownloadItem_user);
	add_func(L, "BInitWorkshopForGameServer", is_gs ? luasteam_UGC_BInitWorkshopForGameServer_gs : luasteam_UGC_BInitWorkshopForGameServer_user);
	add_func(L, "SuspendDownloads", is_gs ? luasteam_UGC_SuspendDownloads_gs : luasteam_UGC_SuspendDownloads_user);
	add_func(L, "StartPlaytimeTracking", is_gs ? luasteam_UGC_StartPlaytimeTracking_gs : luasteam_UGC_StartPlaytimeTracking_user);
	add_func(L, "StopPlaytimeTracking", is_gs ? luasteam_UGC_StopPlaytimeTracking_gs : luasteam_UGC_StopPlaytimeTracking_user);
	add_func(L, "StopPlaytimeTrackingForAllItems", is_gs ? luasteam_UGC_StopPlaytimeTrackingForAllItems_gs : luasteam_UGC_StopPlaytimeTrackingForAllItems_user);
	add_func(L, "AddDependency", is_gs ? luasteam_UGC_AddDependency_gs : luasteam_UGC_AddDependency_user);
	add_func(L, "RemoveDependency", is_gs ? luasteam_UGC_RemoveDependency_gs : luasteam_UGC_RemoveDependency_user);
	add_func(L, "AddAppDependency", is_gs ? luasteam_UGC_AddAppDependency_gs : luasteam_UGC_AddAppDependency_user);
	add_func(L, "RemoveAppDependency", is_gs ? luasteam_UGC_RemoveAppDependency_gs : luasteam_UGC_RemoveAppDependency_user);
	add_func(L, "GetAppDependencies", is_gs ? luasteam_UGC_GetAppDependencies_gs : luasteam_UGC_GetAppDependencies_user);
	add_func(L, "DeleteItem", is_gs ? luasteam_UGC_DeleteItem_gs : luasteam_UGC_DeleteItem_user);
	add_func(L, "ShowWorkshopEULA", is_gs ? luasteam_UGC_ShowWorkshopEULA_gs : luasteam_UGC_ShowWorkshopEULA_user);
	add_func(L, "GetWorkshopEULAStatus", is_gs ? luasteam_UGC_GetWorkshopEULAStatus_gs : luasteam_UGC_GetWorkshopEULAStatus_user);
	add_func(L, "GetUserContentDescriptorPreferences", is_gs ? luasteam_UGC_GetUserContentDescriptorPreferences_gs : luasteam_UGC_GetUserContentDescriptorPreferences_user);
	add_func(L, "SetItemsDisabledLocally", is_gs ? luasteam_UGC_SetItemsDisabledLocally_gs : luasteam_UGC_SetItemsDisabledLocally_user);
	add_func(L, "SetSubscriptionsLoadOrder", is_gs ? luasteam_UGC_SetSubscriptionsLoadOrder_gs : luasteam_UGC_SetSubscriptionsLoadOrder_user);
}

void add_UGC_auto(lua_State *L) {
	lua_createtable(L, 0, 94);
	register_UGC_auto(L, false);
	lua_pushvalue(L, -1);
	UGC_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "UGC");
}

int GameServerUGC_ref = LUA_NOREF;

namespace {
class GameServerUGCCallbackListener {
private:
	STEAM_GAMESERVER_CALLBACK(GameServerUGCCallbackListener, OnSteamUGCQueryCompleted, SteamUGCQueryCompleted_t);
	STEAM_GAMESERVER_CALLBACK(GameServerUGCCallbackListener, OnSteamUGCRequestUGCDetailsResult, SteamUGCRequestUGCDetailsResult_t);
	STEAM_GAMESERVER_CALLBACK(GameServerUGCCallbackListener, OnCreateItemResult, CreateItemResult_t);
	STEAM_GAMESERVER_CALLBACK(GameServerUGCCallbackListener, OnSubmitItemUpdateResult, SubmitItemUpdateResult_t);
	STEAM_GAMESERVER_CALLBACK(GameServerUGCCallbackListener, OnItemInstalled, ItemInstalled_t);
	STEAM_GAMESERVER_CALLBACK(GameServerUGCCallbackListener, OnDownloadItemResult, DownloadItemResult_t);
	STEAM_GAMESERVER_CALLBACK(GameServerUGCCallbackListener, OnUserFavoriteItemsListChanged, UserFavoriteItemsListChanged_t);
	STEAM_GAMESERVER_CALLBACK(GameServerUGCCallbackListener, OnSetUserItemVoteResult, SetUserItemVoteResult_t);
	STEAM_GAMESERVER_CALLBACK(GameServerUGCCallbackListener, OnGetUserItemVoteResult, GetUserItemVoteResult_t);
	STEAM_GAMESERVER_CALLBACK(GameServerUGCCallbackListener, OnStartPlaytimeTrackingResult, StartPlaytimeTrackingResult_t);
	STEAM_GAMESERVER_CALLBACK(GameServerUGCCallbackListener, OnStopPlaytimeTrackingResult, StopPlaytimeTrackingResult_t);
	STEAM_GAMESERVER_CALLBACK(GameServerUGCCallbackListener, OnAddUGCDependencyResult, AddUGCDependencyResult_t);
	STEAM_GAMESERVER_CALLBACK(GameServerUGCCallbackListener, OnRemoveUGCDependencyResult, RemoveUGCDependencyResult_t);
	STEAM_GAMESERVER_CALLBACK(GameServerUGCCallbackListener, OnAddAppDependencyResult, AddAppDependencyResult_t);
	STEAM_GAMESERVER_CALLBACK(GameServerUGCCallbackListener, OnRemoveAppDependencyResult, RemoveAppDependencyResult_t);
	STEAM_GAMESERVER_CALLBACK(GameServerUGCCallbackListener, OnGetAppDependenciesResult, GetAppDependenciesResult_t);
	STEAM_GAMESERVER_CALLBACK(GameServerUGCCallbackListener, OnDeleteItemResult, DeleteItemResult_t);
	STEAM_GAMESERVER_CALLBACK(GameServerUGCCallbackListener, OnUserSubscribedItemsListChanged, UserSubscribedItemsListChanged_t);
	STEAM_GAMESERVER_CALLBACK(GameServerUGCCallbackListener, OnWorkshopEULAStatus, WorkshopEULAStatus_t);
};
void GameServerUGCCallbackListener::OnSteamUGCQueryCompleted(SteamUGCQueryCompleted_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerUGC_ref);
	lua_getfield(L, -1, "OnSteamUGCQueryCompleted");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamUGCQueryCompleted_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerUGCCallbackListener::OnSteamUGCRequestUGCDetailsResult(SteamUGCRequestUGCDetailsResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerUGC_ref);
	lua_getfield(L, -1, "OnSteamUGCRequestUGCDetailsResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamUGCRequestUGCDetailsResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerUGCCallbackListener::OnCreateItemResult(CreateItemResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerUGC_ref);
	lua_getfield(L, -1, "OnCreateItemResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_CreateItemResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerUGCCallbackListener::OnSubmitItemUpdateResult(SubmitItemUpdateResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerUGC_ref);
	lua_getfield(L, -1, "OnSubmitItemUpdateResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SubmitItemUpdateResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerUGCCallbackListener::OnItemInstalled(ItemInstalled_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerUGC_ref);
	lua_getfield(L, -1, "OnItemInstalled");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_ItemInstalled_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerUGCCallbackListener::OnDownloadItemResult(DownloadItemResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerUGC_ref);
	lua_getfield(L, -1, "OnDownloadItemResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_DownloadItemResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerUGCCallbackListener::OnUserFavoriteItemsListChanged(UserFavoriteItemsListChanged_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerUGC_ref);
	lua_getfield(L, -1, "OnUserFavoriteItemsListChanged");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_UserFavoriteItemsListChanged_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerUGCCallbackListener::OnSetUserItemVoteResult(SetUserItemVoteResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerUGC_ref);
	lua_getfield(L, -1, "OnSetUserItemVoteResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SetUserItemVoteResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerUGCCallbackListener::OnGetUserItemVoteResult(GetUserItemVoteResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerUGC_ref);
	lua_getfield(L, -1, "OnGetUserItemVoteResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_GetUserItemVoteResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerUGCCallbackListener::OnStartPlaytimeTrackingResult(StartPlaytimeTrackingResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerUGC_ref);
	lua_getfield(L, -1, "OnStartPlaytimeTrackingResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_StartPlaytimeTrackingResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerUGCCallbackListener::OnStopPlaytimeTrackingResult(StopPlaytimeTrackingResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerUGC_ref);
	lua_getfield(L, -1, "OnStopPlaytimeTrackingResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_StopPlaytimeTrackingResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerUGCCallbackListener::OnAddUGCDependencyResult(AddUGCDependencyResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerUGC_ref);
	lua_getfield(L, -1, "OnAddUGCDependencyResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_AddUGCDependencyResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerUGCCallbackListener::OnRemoveUGCDependencyResult(RemoveUGCDependencyResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerUGC_ref);
	lua_getfield(L, -1, "OnRemoveUGCDependencyResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_RemoveUGCDependencyResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerUGCCallbackListener::OnAddAppDependencyResult(AddAppDependencyResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerUGC_ref);
	lua_getfield(L, -1, "OnAddAppDependencyResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_AddAppDependencyResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerUGCCallbackListener::OnRemoveAppDependencyResult(RemoveAppDependencyResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerUGC_ref);
	lua_getfield(L, -1, "OnRemoveAppDependencyResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_RemoveAppDependencyResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerUGCCallbackListener::OnGetAppDependenciesResult(GetAppDependenciesResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerUGC_ref);
	lua_getfield(L, -1, "OnGetAppDependenciesResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_GetAppDependenciesResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerUGCCallbackListener::OnDeleteItemResult(DeleteItemResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerUGC_ref);
	lua_getfield(L, -1, "OnDeleteItemResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_DeleteItemResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerUGCCallbackListener::OnUserSubscribedItemsListChanged(UserSubscribedItemsListChanged_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerUGC_ref);
	lua_getfield(L, -1, "OnUserSubscribedItemsListChanged");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_UserSubscribedItemsListChanged_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerUGCCallbackListener::OnWorkshopEULAStatus(WorkshopEULAStatus_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerUGC_ref);
	lua_getfield(L, -1, "OnWorkshopEULAStatus");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_WorkshopEULAStatus_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
GameServerUGCCallbackListener *GameServerUGC_listener = nullptr;
} // namespace

void init_GameServerUGC_auto(lua_State *L) { if (GameServerUGC_listener != nullptr) return; GameServerUGC_listener = new GameServerUGCCallbackListener(); }
void shutdown_GameServerUGC_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, GameServerUGC_ref);
	GameServerUGC_ref = LUA_NOREF;
	delete GameServerUGC_listener; GameServerUGC_listener = nullptr;
}

void add_GameServerUGC_auto(lua_State *L) {
	lua_createtable(L, 0, 94);
	register_UGC_auto(L, true);
	lua_pushvalue(L, -1);
	GameServerUGC_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "GameServerUGC");
}

} // namespace luasteam
