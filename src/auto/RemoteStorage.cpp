#include "auto.hpp"

namespace luasteam {

int RemoteStorage_ref = LUA_NOREF;

namespace {
class RemoteStorageCallbackListener {
private:
	STEAM_CALLBACK(RemoteStorageCallbackListener, OnRemoteStorageFileShareResult, RemoteStorageFileShareResult_t);
	STEAM_CALLBACK(RemoteStorageCallbackListener, OnRemoteStoragePublishFileResult, RemoteStoragePublishFileResult_t);
	STEAM_CALLBACK(RemoteStorageCallbackListener, OnRemoteStorageDeletePublishedFileResult, RemoteStorageDeletePublishedFileResult_t);
	STEAM_CALLBACK(RemoteStorageCallbackListener, OnRemoteStorageEnumerateUserPublishedFilesResult, RemoteStorageEnumerateUserPublishedFilesResult_t);
	STEAM_CALLBACK(RemoteStorageCallbackListener, OnRemoteStorageSubscribePublishedFileResult, RemoteStorageSubscribePublishedFileResult_t);
	STEAM_CALLBACK(RemoteStorageCallbackListener, OnRemoteStorageEnumerateUserSubscribedFilesResult, RemoteStorageEnumerateUserSubscribedFilesResult_t);
	STEAM_CALLBACK(RemoteStorageCallbackListener, OnRemoteStorageUnsubscribePublishedFileResult, RemoteStorageUnsubscribePublishedFileResult_t);
	STEAM_CALLBACK(RemoteStorageCallbackListener, OnRemoteStorageUpdatePublishedFileResult, RemoteStorageUpdatePublishedFileResult_t);
	STEAM_CALLBACK(RemoteStorageCallbackListener, OnRemoteStorageDownloadUGCResult, RemoteStorageDownloadUGCResult_t);
	STEAM_CALLBACK(RemoteStorageCallbackListener, OnRemoteStorageGetPublishedFileDetailsResult, RemoteStorageGetPublishedFileDetailsResult_t);
	STEAM_CALLBACK(RemoteStorageCallbackListener, OnRemoteStorageEnumerateWorkshopFilesResult, RemoteStorageEnumerateWorkshopFilesResult_t);
	STEAM_CALLBACK(RemoteStorageCallbackListener, OnRemoteStorageGetPublishedItemVoteDetailsResult, RemoteStorageGetPublishedItemVoteDetailsResult_t);
	STEAM_CALLBACK(RemoteStorageCallbackListener, OnRemoteStoragePublishedFileSubscribed, RemoteStoragePublishedFileSubscribed_t);
	STEAM_CALLBACK(RemoteStorageCallbackListener, OnRemoteStoragePublishedFileUnsubscribed, RemoteStoragePublishedFileUnsubscribed_t);
	STEAM_CALLBACK(RemoteStorageCallbackListener, OnRemoteStoragePublishedFileDeleted, RemoteStoragePublishedFileDeleted_t);
	STEAM_CALLBACK(RemoteStorageCallbackListener, OnRemoteStorageUpdateUserPublishedItemVoteResult, RemoteStorageUpdateUserPublishedItemVoteResult_t);
	STEAM_CALLBACK(RemoteStorageCallbackListener, OnRemoteStorageUserVoteDetails, RemoteStorageUserVoteDetails_t);
	STEAM_CALLBACK(RemoteStorageCallbackListener, OnRemoteStorageEnumerateUserSharedWorkshopFilesResult, RemoteStorageEnumerateUserSharedWorkshopFilesResult_t);
	STEAM_CALLBACK(RemoteStorageCallbackListener, OnRemoteStorageSetUserPublishedFileActionResult, RemoteStorageSetUserPublishedFileActionResult_t);
	STEAM_CALLBACK(RemoteStorageCallbackListener, OnRemoteStorageEnumeratePublishedFilesByUserActionResult, RemoteStorageEnumeratePublishedFilesByUserActionResult_t);
	STEAM_CALLBACK(RemoteStorageCallbackListener, OnRemoteStoragePublishFileProgress, RemoteStoragePublishFileProgress_t);
	STEAM_CALLBACK(RemoteStorageCallbackListener, OnRemoteStoragePublishedFileUpdated, RemoteStoragePublishedFileUpdated_t);
	STEAM_CALLBACK(RemoteStorageCallbackListener, OnRemoteStorageFileWriteAsyncComplete, RemoteStorageFileWriteAsyncComplete_t);
	STEAM_CALLBACK(RemoteStorageCallbackListener, OnRemoteStorageFileReadAsyncComplete, RemoteStorageFileReadAsyncComplete_t);
	STEAM_CALLBACK(RemoteStorageCallbackListener, OnRemoteStorageLocalFileChange, RemoteStorageLocalFileChange_t);
};
void RemoteStorageCallbackListener::OnRemoteStorageFileShareResult(RemoteStorageFileShareResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageFileShareResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_RemoteStorageFileShareResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void RemoteStorageCallbackListener::OnRemoteStoragePublishFileResult(RemoteStoragePublishFileResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStoragePublishFileResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_RemoteStoragePublishFileResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void RemoteStorageCallbackListener::OnRemoteStorageDeletePublishedFileResult(RemoteStorageDeletePublishedFileResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageDeletePublishedFileResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_RemoteStorageDeletePublishedFileResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void RemoteStorageCallbackListener::OnRemoteStorageEnumerateUserPublishedFilesResult(RemoteStorageEnumerateUserPublishedFilesResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageEnumerateUserPublishedFilesResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_RemoteStorageEnumerateUserPublishedFilesResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void RemoteStorageCallbackListener::OnRemoteStorageSubscribePublishedFileResult(RemoteStorageSubscribePublishedFileResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageSubscribePublishedFileResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_RemoteStorageSubscribePublishedFileResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void RemoteStorageCallbackListener::OnRemoteStorageEnumerateUserSubscribedFilesResult(RemoteStorageEnumerateUserSubscribedFilesResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageEnumerateUserSubscribedFilesResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_RemoteStorageEnumerateUserSubscribedFilesResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void RemoteStorageCallbackListener::OnRemoteStorageUnsubscribePublishedFileResult(RemoteStorageUnsubscribePublishedFileResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageUnsubscribePublishedFileResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_RemoteStorageUnsubscribePublishedFileResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void RemoteStorageCallbackListener::OnRemoteStorageUpdatePublishedFileResult(RemoteStorageUpdatePublishedFileResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageUpdatePublishedFileResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_RemoteStorageUpdatePublishedFileResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void RemoteStorageCallbackListener::OnRemoteStorageDownloadUGCResult(RemoteStorageDownloadUGCResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageDownloadUGCResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_RemoteStorageDownloadUGCResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void RemoteStorageCallbackListener::OnRemoteStorageGetPublishedFileDetailsResult(RemoteStorageGetPublishedFileDetailsResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageGetPublishedFileDetailsResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_RemoteStorageGetPublishedFileDetailsResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void RemoteStorageCallbackListener::OnRemoteStorageEnumerateWorkshopFilesResult(RemoteStorageEnumerateWorkshopFilesResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageEnumerateWorkshopFilesResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_RemoteStorageEnumerateWorkshopFilesResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void RemoteStorageCallbackListener::OnRemoteStorageGetPublishedItemVoteDetailsResult(RemoteStorageGetPublishedItemVoteDetailsResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageGetPublishedItemVoteDetailsResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_RemoteStorageGetPublishedItemVoteDetailsResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void RemoteStorageCallbackListener::OnRemoteStoragePublishedFileSubscribed(RemoteStoragePublishedFileSubscribed_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStoragePublishedFileSubscribed");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_RemoteStoragePublishedFileSubscribed_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void RemoteStorageCallbackListener::OnRemoteStoragePublishedFileUnsubscribed(RemoteStoragePublishedFileUnsubscribed_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStoragePublishedFileUnsubscribed");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_RemoteStoragePublishedFileUnsubscribed_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void RemoteStorageCallbackListener::OnRemoteStoragePublishedFileDeleted(RemoteStoragePublishedFileDeleted_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStoragePublishedFileDeleted");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_RemoteStoragePublishedFileDeleted_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void RemoteStorageCallbackListener::OnRemoteStorageUpdateUserPublishedItemVoteResult(RemoteStorageUpdateUserPublishedItemVoteResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageUpdateUserPublishedItemVoteResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_RemoteStorageUpdateUserPublishedItemVoteResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void RemoteStorageCallbackListener::OnRemoteStorageUserVoteDetails(RemoteStorageUserVoteDetails_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageUserVoteDetails");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_RemoteStorageUserVoteDetails_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void RemoteStorageCallbackListener::OnRemoteStorageEnumerateUserSharedWorkshopFilesResult(RemoteStorageEnumerateUserSharedWorkshopFilesResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageEnumerateUserSharedWorkshopFilesResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_RemoteStorageEnumerateUserSharedWorkshopFilesResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void RemoteStorageCallbackListener::OnRemoteStorageSetUserPublishedFileActionResult(RemoteStorageSetUserPublishedFileActionResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageSetUserPublishedFileActionResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_RemoteStorageSetUserPublishedFileActionResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void RemoteStorageCallbackListener::OnRemoteStorageEnumeratePublishedFilesByUserActionResult(RemoteStorageEnumeratePublishedFilesByUserActionResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageEnumeratePublishedFilesByUserActionResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_RemoteStorageEnumeratePublishedFilesByUserActionResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void RemoteStorageCallbackListener::OnRemoteStoragePublishFileProgress(RemoteStoragePublishFileProgress_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStoragePublishFileProgress");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_RemoteStoragePublishFileProgress_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void RemoteStorageCallbackListener::OnRemoteStoragePublishedFileUpdated(RemoteStoragePublishedFileUpdated_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStoragePublishedFileUpdated");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_RemoteStoragePublishedFileUpdated_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void RemoteStorageCallbackListener::OnRemoteStorageFileWriteAsyncComplete(RemoteStorageFileWriteAsyncComplete_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageFileWriteAsyncComplete");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_RemoteStorageFileWriteAsyncComplete_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void RemoteStorageCallbackListener::OnRemoteStorageFileReadAsyncComplete(RemoteStorageFileReadAsyncComplete_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageFileReadAsyncComplete");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_RemoteStorageFileReadAsyncComplete_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void RemoteStorageCallbackListener::OnRemoteStorageLocalFileChange(RemoteStorageLocalFileChange_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageLocalFileChange");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_RemoteStorageLocalFileChange_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
RemoteStorageCallbackListener *RemoteStorage_listener = nullptr;
} // namespace

void init_RemoteStorage_auto(lua_State *L) { if (RemoteStorage_listener != nullptr) return; RemoteStorage_listener = new RemoteStorageCallbackListener(); }
void shutdown_RemoteStorage_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, RemoteStorage_ref);
	RemoteStorage_ref = LUA_NOREF;
	delete RemoteStorage_listener; RemoteStorage_listener = nullptr;
}

template <> void CallResultListener<RemoteStorageDeletePublishedFileResult_t>::Result(RemoteStorageDeletePublishedFileResult_t *data, bool io_fail) {
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

template <> void CallResultListener<RemoteStorageDownloadUGCResult_t>::Result(RemoteStorageDownloadUGCResult_t *data, bool io_fail) {
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
		luasteam::pushuint64(L, data->m_hFile);
		lua_setfield(L, -2, "m_hFile");
		lua_pushinteger(L, data->m_nAppID);
		lua_setfield(L, -2, "m_nAppID");
		lua_pushinteger(L, data->m_nSizeInBytes);
		lua_setfield(L, -2, "m_nSizeInBytes");
		lua_pushlstring(L, reinterpret_cast<const char*>(data->m_pchFileName), 260);
		lua_setfield(L, -2, "m_pchFileName");
		luasteam::pushuint64(L, data->m_ulSteamIDOwner);
		lua_setfield(L, -2, "m_ulSteamIDOwner");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<RemoteStorageEnumeratePublishedFilesByUserActionResult_t>::Result(RemoteStorageEnumeratePublishedFilesByUserActionResult_t *data, bool io_fail) {
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
		lua_pushinteger(L, data->m_eAction);
		lua_setfield(L, -2, "m_eAction");
		lua_pushinteger(L, data->m_nResultsReturned);
		lua_setfield(L, -2, "m_nResultsReturned");
		lua_pushinteger(L, data->m_nTotalResultCount);
		lua_setfield(L, -2, "m_nTotalResultCount");
		lua_createtable(L, 50, 0);
		for(decltype(50) i = 0; i < 50; i++) {
			luasteam::pushuint64(L, data->m_rgPublishedFileId[i]);
			lua_rawseti(L, -2, i+1);
		}
		lua_setfield(L, -2, "m_rgPublishedFileId");
		lua_createtable(L, 50, 0);
		for(decltype(50) i = 0; i < 50; i++) {
			lua_pushinteger(L, data->m_rgRTimeUpdated[i]);
			lua_rawseti(L, -2, i+1);
		}
		lua_setfield(L, -2, "m_rgRTimeUpdated");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<RemoteStorageEnumerateUserPublishedFilesResult_t>::Result(RemoteStorageEnumerateUserPublishedFilesResult_t *data, bool io_fail) {
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
		lua_pushinteger(L, data->m_nResultsReturned);
		lua_setfield(L, -2, "m_nResultsReturned");
		lua_pushinteger(L, data->m_nTotalResultCount);
		lua_setfield(L, -2, "m_nTotalResultCount");
		lua_createtable(L, 50, 0);
		for(decltype(50) i = 0; i < 50; i++) {
			luasteam::pushuint64(L, data->m_rgPublishedFileId[i]);
			lua_rawseti(L, -2, i+1);
		}
		lua_setfield(L, -2, "m_rgPublishedFileId");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<RemoteStorageEnumerateUserSubscribedFilesResult_t>::Result(RemoteStorageEnumerateUserSubscribedFilesResult_t *data, bool io_fail) {
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
		lua_pushinteger(L, data->m_nResultsReturned);
		lua_setfield(L, -2, "m_nResultsReturned");
		lua_pushinteger(L, data->m_nTotalResultCount);
		lua_setfield(L, -2, "m_nTotalResultCount");
		lua_createtable(L, 50, 0);
		for(decltype(50) i = 0; i < 50; i++) {
			luasteam::pushuint64(L, data->m_rgPublishedFileId[i]);
			lua_rawseti(L, -2, i+1);
		}
		lua_setfield(L, -2, "m_rgPublishedFileId");
		lua_createtable(L, 50, 0);
		for(decltype(50) i = 0; i < 50; i++) {
			lua_pushinteger(L, data->m_rgRTimeSubscribed[i]);
			lua_rawseti(L, -2, i+1);
		}
		lua_setfield(L, -2, "m_rgRTimeSubscribed");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<RemoteStorageEnumerateWorkshopFilesResult_t>::Result(RemoteStorageEnumerateWorkshopFilesResult_t *data, bool io_fail) {
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
		lua_createtable(L, 0, 7);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		lua_pushinteger(L, data->m_nResultsReturned);
		lua_setfield(L, -2, "m_nResultsReturned");
		lua_pushinteger(L, data->m_nTotalResultCount);
		lua_setfield(L, -2, "m_nTotalResultCount");
		lua_createtable(L, 50, 0);
		for(decltype(50) i = 0; i < 50; i++) {
			luasteam::pushuint64(L, data->m_rgPublishedFileId[i]);
			lua_rawseti(L, -2, i+1);
		}
		lua_setfield(L, -2, "m_rgPublishedFileId");
		lua_createtable(L, 50, 0);
		for(decltype(50) i = 0; i < 50; i++) {
			lua_pushnumber(L, data->m_rgScore[i]);
			lua_rawseti(L, -2, i+1);
		}
		lua_setfield(L, -2, "m_rgScore");
		lua_pushinteger(L, data->m_nAppId);
		lua_setfield(L, -2, "m_nAppId");
		lua_pushinteger(L, data->m_unStartIndex);
		lua_setfield(L, -2, "m_unStartIndex");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<RemoteStorageFileReadAsyncComplete_t>::Result(RemoteStorageFileReadAsyncComplete_t *data, bool io_fail) {
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
		luasteam::pushuint64(L, data->m_hFileReadAsync);
		lua_setfield(L, -2, "m_hFileReadAsync");
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		lua_pushinteger(L, data->m_nOffset);
		lua_setfield(L, -2, "m_nOffset");
		lua_pushinteger(L, data->m_cubRead);
		lua_setfield(L, -2, "m_cubRead");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<RemoteStorageFileShareResult_t>::Result(RemoteStorageFileShareResult_t *data, bool io_fail) {
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
		luasteam::pushuint64(L, data->m_hFile);
		lua_setfield(L, -2, "m_hFile");
		lua_pushlstring(L, reinterpret_cast<const char*>(data->m_rgchFilename), 260);
		lua_setfield(L, -2, "m_rgchFilename");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<RemoteStorageFileWriteAsyncComplete_t>::Result(RemoteStorageFileWriteAsyncComplete_t *data, bool io_fail) {
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

template <> void CallResultListener<RemoteStorageGetPublishedFileDetailsResult_t>::Result(RemoteStorageGetPublishedFileDetailsResult_t *data, bool io_fail) {
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
		lua_createtable(L, 0, 21);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		luasteam::pushuint64(L, data->m_nPublishedFileId);
		lua_setfield(L, -2, "m_nPublishedFileId");
		lua_pushinteger(L, data->m_nCreatorAppID);
		lua_setfield(L, -2, "m_nCreatorAppID");
		lua_pushinteger(L, data->m_nConsumerAppID);
		lua_setfield(L, -2, "m_nConsumerAppID");
		lua_pushlstring(L, reinterpret_cast<const char*>(data->m_rgchTitle), 129);
		lua_setfield(L, -2, "m_rgchTitle");
		lua_pushlstring(L, reinterpret_cast<const char*>(data->m_rgchDescription), 8000);
		lua_setfield(L, -2, "m_rgchDescription");
		luasteam::pushuint64(L, data->m_hFile);
		lua_setfield(L, -2, "m_hFile");
		luasteam::pushuint64(L, data->m_hPreviewFile);
		lua_setfield(L, -2, "m_hPreviewFile");
		luasteam::pushuint64(L, data->m_ulSteamIDOwner);
		lua_setfield(L, -2, "m_ulSteamIDOwner");
		lua_pushinteger(L, data->m_rtimeCreated);
		lua_setfield(L, -2, "m_rtimeCreated");
		lua_pushinteger(L, data->m_rtimeUpdated);
		lua_setfield(L, -2, "m_rtimeUpdated");
		lua_pushinteger(L, data->m_eVisibility);
		lua_setfield(L, -2, "m_eVisibility");
		lua_pushboolean(L, data->m_bBanned);
		lua_setfield(L, -2, "m_bBanned");
		lua_pushlstring(L, reinterpret_cast<const char*>(data->m_rgchTags), 1025);
		lua_setfield(L, -2, "m_rgchTags");
		lua_pushboolean(L, data->m_bTagsTruncated);
		lua_setfield(L, -2, "m_bTagsTruncated");
		lua_pushlstring(L, reinterpret_cast<const char*>(data->m_pchFileName), 260);
		lua_setfield(L, -2, "m_pchFileName");
		lua_pushinteger(L, data->m_nFileSize);
		lua_setfield(L, -2, "m_nFileSize");
		lua_pushinteger(L, data->m_nPreviewFileSize);
		lua_setfield(L, -2, "m_nPreviewFileSize");
		lua_pushlstring(L, reinterpret_cast<const char*>(data->m_rgchURL), 256);
		lua_setfield(L, -2, "m_rgchURL");
		lua_pushinteger(L, data->m_eFileType);
		lua_setfield(L, -2, "m_eFileType");
		lua_pushboolean(L, data->m_bAcceptedForUse);
		lua_setfield(L, -2, "m_bAcceptedForUse");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<RemoteStorageGetPublishedItemVoteDetailsResult_t>::Result(RemoteStorageGetPublishedItemVoteDetailsResult_t *data, bool io_fail) {
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
		luasteam::pushuint64(L, data->m_unPublishedFileId);
		lua_setfield(L, -2, "m_unPublishedFileId");
		lua_pushinteger(L, data->m_nVotesFor);
		lua_setfield(L, -2, "m_nVotesFor");
		lua_pushinteger(L, data->m_nVotesAgainst);
		lua_setfield(L, -2, "m_nVotesAgainst");
		lua_pushinteger(L, data->m_nReports);
		lua_setfield(L, -2, "m_nReports");
		lua_pushnumber(L, data->m_fScore);
		lua_setfield(L, -2, "m_fScore");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<RemoteStoragePublishFileProgress_t>::Result(RemoteStoragePublishFileProgress_t *data, bool io_fail) {
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
		lua_pushnumber(L, data->m_dPercentFile);
		lua_setfield(L, -2, "m_dPercentFile");
		lua_pushboolean(L, data->m_bPreview);
		lua_setfield(L, -2, "m_bPreview");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<RemoteStorageSetUserPublishedFileActionResult_t>::Result(RemoteStorageSetUserPublishedFileActionResult_t *data, bool io_fail) {
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
		lua_pushinteger(L, data->m_eAction);
		lua_setfield(L, -2, "m_eAction");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<RemoteStorageSubscribePublishedFileResult_t>::Result(RemoteStorageSubscribePublishedFileResult_t *data, bool io_fail) {
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

template <> void CallResultListener<RemoteStorageUnsubscribePublishedFileResult_t>::Result(RemoteStorageUnsubscribePublishedFileResult_t *data, bool io_fail) {
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

template <> void CallResultListener<RemoteStorageUpdatePublishedFileResult_t>::Result(RemoteStorageUpdatePublishedFileResult_t *data, bool io_fail) {
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

template <> void CallResultListener<RemoteStorageUpdateUserPublishedItemVoteResult_t>::Result(RemoteStorageUpdateUserPublishedItemVoteResult_t *data, bool io_fail) {
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

// In C++:
// bool FileWrite(const char * pchFile, const void * pvData, int32 cubData);
// In Lua:
// bool RemoteStorage.FileWrite(pchFile: str, pvData: str, cubData: int)
static int luasteam_RemoteStorage_FileWrite(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	const char *pchFile = luaL_checkstring(L, 1);
	int32 cubData = luaL_checkint(L, 3);
	size_t _len__tmp94;
	const char *_tmp94 = luaL_checklstring(L, 2, &_len__tmp94);
	const void *pvData = reinterpret_cast<const void *>(_tmp94);
	bool __ret = iface->FileWrite(pchFile, pvData, cubData);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// int32 FileRead(const char * pchFile, void * pvData, int32 cubDataToRead);
// In Lua:
// (int, pvData: str) RemoteStorage.FileRead(pchFile: str, cubDataToRead: int)
static int luasteam_RemoteStorage_FileRead(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	const char *pchFile = luaL_checkstring(L, 1);
	int32 cubDataToRead = luaL_checkint(L, 2);
	std::vector<unsigned char> pvData(cubDataToRead);
	int32 __ret = iface->FileRead(pchFile, pvData.data(), cubDataToRead);
	lua_pushinteger(L, __ret);
	lua_pushlstring(L, reinterpret_cast<const char*>(pvData.data()), __ret);
	return 2;
}

// In C++:
// SteamAPICall_t FileWriteAsync(const char * pchFile, const void * pvData, uint32 cubData);
// In Lua:
// uint64 RemoteStorage.FileWriteAsync(pchFile: str, pvData: str, cubData: int, callback: function)
static int luasteam_RemoteStorage_FileWriteAsync(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	const char *pchFile = luaL_checkstring(L, 1);
	uint32 cubData = luaL_checkint(L, 3);
	size_t _len__tmp95;
	const char *_tmp95 = luaL_checklstring(L, 2, &_len__tmp95);
	const void *pvData = reinterpret_cast<const void *>(_tmp95);
	SteamAPICall_t __ret = iface->FileWriteAsync(pchFile, pvData, cubData);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<RemoteStorageFileWriteAsyncComplete_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<RemoteStorageFileWriteAsyncComplete_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t FileReadAsync(const char * pchFile, uint32 nOffset, uint32 cubToRead);
// In Lua:
// uint64 RemoteStorage.FileReadAsync(pchFile: str, nOffset: int, cubToRead: int, callback: function)
static int luasteam_RemoteStorage_FileReadAsync(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	const char *pchFile = luaL_checkstring(L, 1);
	uint32 nOffset = static_cast<uint32>(luaL_checkint(L, 2));
	uint32 cubToRead = static_cast<uint32>(luaL_checkint(L, 3));
	SteamAPICall_t __ret = iface->FileReadAsync(pchFile, nOffset, cubToRead);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<RemoteStorageFileReadAsyncComplete_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<RemoteStorageFileReadAsyncComplete_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// bool FileReadAsyncComplete(SteamAPICall_t hReadCall, void * pvBuffer, uint32 cubToRead);
// In Lua:
// (bool, pvBuffer: str) RemoteStorage.FileReadAsyncComplete(hReadCall: uint64, cubToRead: int)
static int luasteam_RemoteStorage_FileReadAsyncComplete(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	SteamAPICall_t hReadCall(luasteam::checkuint64(L, 1));
	uint32 cubToRead = luaL_checkint(L, 2);
	std::vector<unsigned char> pvBuffer(cubToRead);
	bool __ret = iface->FileReadAsyncComplete(hReadCall, pvBuffer.data(), cubToRead);
	lua_pushboolean(L, __ret);
	lua_pushlstring(L, reinterpret_cast<const char*>(pvBuffer.data()), cubToRead);
	return 2;
}

// In C++:
// bool FileForget(const char * pchFile);
// In Lua:
// bool RemoteStorage.FileForget(pchFile: str)
static int luasteam_RemoteStorage_FileForget(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	const char *pchFile = luaL_checkstring(L, 1);
	bool __ret = iface->FileForget(pchFile);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool FileDelete(const char * pchFile);
// In Lua:
// bool RemoteStorage.FileDelete(pchFile: str)
static int luasteam_RemoteStorage_FileDelete(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	const char *pchFile = luaL_checkstring(L, 1);
	bool __ret = iface->FileDelete(pchFile);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t FileShare(const char * pchFile);
// In Lua:
// uint64 RemoteStorage.FileShare(pchFile: str, callback: function)
static int luasteam_RemoteStorage_FileShare(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	const char *pchFile = luaL_checkstring(L, 1);
	SteamAPICall_t __ret = iface->FileShare(pchFile);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<RemoteStorageFileShareResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<RemoteStorageFileShareResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// bool SetSyncPlatforms(const char * pchFile, ERemoteStoragePlatform eRemoteStoragePlatform);
// In Lua:
// bool RemoteStorage.SetSyncPlatforms(pchFile: str, eRemoteStoragePlatform: int)
static int luasteam_RemoteStorage_SetSyncPlatforms(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	const char *pchFile = luaL_checkstring(L, 1);
	ERemoteStoragePlatform eRemoteStoragePlatform = static_cast<ERemoteStoragePlatform>(luaL_checkint(L, 2));
	bool __ret = iface->SetSyncPlatforms(pchFile, eRemoteStoragePlatform);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// UGCFileWriteStreamHandle_t FileWriteStreamOpen(const char * pchFile);
// In Lua:
// uint64 RemoteStorage.FileWriteStreamOpen(pchFile: str)
static int luasteam_RemoteStorage_FileWriteStreamOpen(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	const char *pchFile = luaL_checkstring(L, 1);
	UGCFileWriteStreamHandle_t __ret = iface->FileWriteStreamOpen(pchFile);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// bool FileWriteStreamWriteChunk(UGCFileWriteStreamHandle_t writeHandle, const void * pvData, int32 cubData);
// In Lua:
// bool RemoteStorage.FileWriteStreamWriteChunk(writeHandle: uint64, pvData: str, cubData: int)
static int luasteam_RemoteStorage_FileWriteStreamWriteChunk(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	UGCFileWriteStreamHandle_t writeHandle(luasteam::checkuint64(L, 1));
	int32 cubData = luaL_checkint(L, 3);
	size_t _len__tmp96;
	const char *_tmp96 = luaL_checklstring(L, 2, &_len__tmp96);
	const void *pvData = reinterpret_cast<const void *>(_tmp96);
	bool __ret = iface->FileWriteStreamWriteChunk(writeHandle, pvData, cubData);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool FileWriteStreamClose(UGCFileWriteStreamHandle_t writeHandle);
// In Lua:
// bool RemoteStorage.FileWriteStreamClose(writeHandle: uint64)
static int luasteam_RemoteStorage_FileWriteStreamClose(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	UGCFileWriteStreamHandle_t writeHandle(luasteam::checkuint64(L, 1));
	bool __ret = iface->FileWriteStreamClose(writeHandle);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool FileWriteStreamCancel(UGCFileWriteStreamHandle_t writeHandle);
// In Lua:
// bool RemoteStorage.FileWriteStreamCancel(writeHandle: uint64)
static int luasteam_RemoteStorage_FileWriteStreamCancel(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	UGCFileWriteStreamHandle_t writeHandle(luasteam::checkuint64(L, 1));
	bool __ret = iface->FileWriteStreamCancel(writeHandle);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool FileExists(const char * pchFile);
// In Lua:
// bool RemoteStorage.FileExists(pchFile: str)
static int luasteam_RemoteStorage_FileExists(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	const char *pchFile = luaL_checkstring(L, 1);
	bool __ret = iface->FileExists(pchFile);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool FilePersisted(const char * pchFile);
// In Lua:
// bool RemoteStorage.FilePersisted(pchFile: str)
static int luasteam_RemoteStorage_FilePersisted(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	const char *pchFile = luaL_checkstring(L, 1);
	bool __ret = iface->FilePersisted(pchFile);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// int32 GetFileSize(const char * pchFile);
// In Lua:
// int RemoteStorage.GetFileSize(pchFile: str)
static int luasteam_RemoteStorage_GetFileSize(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	const char *pchFile = luaL_checkstring(L, 1);
	int32 __ret = iface->GetFileSize(pchFile);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// int64 GetFileTimestamp(const char * pchFile);
// In Lua:
// uint64 RemoteStorage.GetFileTimestamp(pchFile: str)
static int luasteam_RemoteStorage_GetFileTimestamp(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	const char *pchFile = luaL_checkstring(L, 1);
	int64 __ret = iface->GetFileTimestamp(pchFile);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// ERemoteStoragePlatform GetSyncPlatforms(const char * pchFile);
// In Lua:
// int RemoteStorage.GetSyncPlatforms(pchFile: str)
static int luasteam_RemoteStorage_GetSyncPlatforms(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	const char *pchFile = luaL_checkstring(L, 1);
	ERemoteStoragePlatform __ret = iface->GetSyncPlatforms(pchFile);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// int32 GetFileCount();
// In Lua:
// int RemoteStorage.GetFileCount()
static int luasteam_RemoteStorage_GetFileCount(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	int32 __ret = iface->GetFileCount();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// const char * GetFileNameAndSize(int iFile, int32 * pnFileSizeInBytes);
// In Lua:
// (str, pnFileSizeInBytes: int) RemoteStorage.GetFileNameAndSize(iFile: int)
static int luasteam_RemoteStorage_GetFileNameAndSize(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	int iFile = static_cast<int>(luaL_checkint(L, 1));
	int32 pnFileSizeInBytes;
	const char * __ret = iface->GetFileNameAndSize(iFile, &pnFileSizeInBytes);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	lua_pushinteger(L, pnFileSizeInBytes);
	return 2;
}

// In C++:
// bool GetQuota(uint64 * pnTotalBytes, uint64 * puAvailableBytes);
// In Lua:
// (bool, pnTotalBytes: uint64, puAvailableBytes: uint64) RemoteStorage.GetQuota()
static int luasteam_RemoteStorage_GetQuota(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	uint64 pnTotalBytes;
	uint64 puAvailableBytes;
	bool __ret = iface->GetQuota(&pnTotalBytes, &puAvailableBytes);
	lua_pushboolean(L, __ret);
	luasteam::pushuint64(L, pnTotalBytes);
	luasteam::pushuint64(L, puAvailableBytes);
	return 3;
}

// In C++:
// bool IsCloudEnabledForAccount();
// In Lua:
// bool RemoteStorage.IsCloudEnabledForAccount()
static int luasteam_RemoteStorage_IsCloudEnabledForAccount(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	bool __ret = iface->IsCloudEnabledForAccount();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool IsCloudEnabledForApp();
// In Lua:
// bool RemoteStorage.IsCloudEnabledForApp()
static int luasteam_RemoteStorage_IsCloudEnabledForApp(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	bool __ret = iface->IsCloudEnabledForApp();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// void SetCloudEnabledForApp(bool bEnabled);
// In Lua:
// RemoteStorage.SetCloudEnabledForApp(bEnabled: bool)
static int luasteam_RemoteStorage_SetCloudEnabledForApp(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	bool bEnabled = lua_toboolean(L, 1);
	iface->SetCloudEnabledForApp(bEnabled);
	return 0;
}

// In C++:
// SteamAPICall_t UGCDownload(UGCHandle_t hContent, uint32 unPriority);
// In Lua:
// uint64 RemoteStorage.UGCDownload(hContent: uint64, unPriority: int, callback: function)
static int luasteam_RemoteStorage_UGCDownload(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	UGCHandle_t hContent(luasteam::checkuint64(L, 1));
	uint32 unPriority = static_cast<uint32>(luaL_checkint(L, 2));
	SteamAPICall_t __ret = iface->UGCDownload(hContent, unPriority);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<RemoteStorageDownloadUGCResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<RemoteStorageDownloadUGCResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// bool GetUGCDownloadProgress(UGCHandle_t hContent, int32 * pnBytesDownloaded, int32 * pnBytesExpected);
// In Lua:
// (bool, pnBytesDownloaded: int, pnBytesExpected: int) RemoteStorage.GetUGCDownloadProgress(hContent: uint64)
static int luasteam_RemoteStorage_GetUGCDownloadProgress(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	UGCHandle_t hContent(luasteam::checkuint64(L, 1));
	int32 pnBytesDownloaded;
	int32 pnBytesExpected;
	bool __ret = iface->GetUGCDownloadProgress(hContent, &pnBytesDownloaded, &pnBytesExpected);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pnBytesDownloaded);
	lua_pushinteger(L, pnBytesExpected);
	return 3;
}

// In C++:
// int32 UGCRead(UGCHandle_t hContent, void * pvData, int32 cubDataToRead, uint32 cOffset, EUGCReadAction eAction);
// In Lua:
// (int, pvData: str) RemoteStorage.UGCRead(hContent: uint64, cubDataToRead: int, cOffset: int, eAction: int)
static int luasteam_RemoteStorage_UGCRead(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	UGCHandle_t hContent(luasteam::checkuint64(L, 1));
	int32 cubDataToRead = luaL_checkint(L, 2);
	std::vector<unsigned char> pvData(cubDataToRead);
	uint32 cOffset = static_cast<uint32>(luaL_checkint(L, 3));
	EUGCReadAction eAction = static_cast<EUGCReadAction>(luaL_checkint(L, 4));
	int32 __ret = iface->UGCRead(hContent, pvData.data(), cubDataToRead, cOffset, eAction);
	lua_pushinteger(L, __ret);
	lua_pushlstring(L, reinterpret_cast<const char*>(pvData.data()), cubDataToRead);
	return 2;
}

// In C++:
// int32 GetCachedUGCCount();
// In Lua:
// int RemoteStorage.GetCachedUGCCount()
static int luasteam_RemoteStorage_GetCachedUGCCount(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	int32 __ret = iface->GetCachedUGCCount();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// UGCHandle_t GetCachedUGCHandle(int32 iCachedContent);
// In Lua:
// uint64 RemoteStorage.GetCachedUGCHandle(iCachedContent: int)
static int luasteam_RemoteStorage_GetCachedUGCHandle(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	int32 iCachedContent = static_cast<int32>(luaL_checkint(L, 1));
	UGCHandle_t __ret = iface->GetCachedUGCHandle(iCachedContent);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t PublishWorkshopFile(const char * pchFile, const char * pchPreviewFile, AppId_t nConsumerAppId, const char * pchTitle, const char * pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t * pTags, EWorkshopFileType eWorkshopFileType);
// In Lua:
// (uint64, pTags: SteamParamStringArray_t) RemoteStorage.PublishWorkshopFile(pchFile: str, pchPreviewFile: str, nConsumerAppId: int, pchTitle: str, pchDescription: str, eVisibility: int, eWorkshopFileType: int, callback: function)
static int luasteam_RemoteStorage_PublishWorkshopFile(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	const char *pchFile = luaL_checkstring(L, 1);
	const char *pchPreviewFile = luaL_checkstring(L, 2);
	AppId_t nConsumerAppId = static_cast<AppId_t>(luaL_checkint(L, 3));
	const char *pchTitle = luaL_checkstring(L, 4);
	const char *pchDescription = luaL_checkstring(L, 5);
	ERemoteStoragePublishedFileVisibility eVisibility = static_cast<ERemoteStoragePublishedFileVisibility>(luaL_checkint(L, 6));
	SteamParamStringArray_t pTags;
	EWorkshopFileType eWorkshopFileType = static_cast<EWorkshopFileType>(luaL_checkint(L, 7));
	SteamAPICall_t __ret = iface->PublishWorkshopFile(pchFile, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility, &pTags, eWorkshopFileType);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<RemoteStoragePublishFileProgress_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<RemoteStoragePublishFileProgress_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	luasteam::push_SteamParamStringArray_t(L, pTags);
	return 2;
}

// In C++:
// PublishedFileUpdateHandle_t CreatePublishedFileUpdateRequest(PublishedFileId_t unPublishedFileId);
// In Lua:
// uint64 RemoteStorage.CreatePublishedFileUpdateRequest(unPublishedFileId: uint64)
static int luasteam_RemoteStorage_CreatePublishedFileUpdateRequest(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	PublishedFileId_t unPublishedFileId(luasteam::checkuint64(L, 1));
	PublishedFileUpdateHandle_t __ret = iface->CreatePublishedFileUpdateRequest(unPublishedFileId);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// bool UpdatePublishedFileFile(PublishedFileUpdateHandle_t updateHandle, const char * pchFile);
// In Lua:
// bool RemoteStorage.UpdatePublishedFileFile(updateHandle: uint64, pchFile: str)
static int luasteam_RemoteStorage_UpdatePublishedFileFile(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	PublishedFileUpdateHandle_t updateHandle(luasteam::checkuint64(L, 1));
	const char *pchFile = luaL_checkstring(L, 2);
	bool __ret = iface->UpdatePublishedFileFile(updateHandle, pchFile);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool UpdatePublishedFilePreviewFile(PublishedFileUpdateHandle_t updateHandle, const char * pchPreviewFile);
// In Lua:
// bool RemoteStorage.UpdatePublishedFilePreviewFile(updateHandle: uint64, pchPreviewFile: str)
static int luasteam_RemoteStorage_UpdatePublishedFilePreviewFile(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	PublishedFileUpdateHandle_t updateHandle(luasteam::checkuint64(L, 1));
	const char *pchPreviewFile = luaL_checkstring(L, 2);
	bool __ret = iface->UpdatePublishedFilePreviewFile(updateHandle, pchPreviewFile);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool UpdatePublishedFileTitle(PublishedFileUpdateHandle_t updateHandle, const char * pchTitle);
// In Lua:
// bool RemoteStorage.UpdatePublishedFileTitle(updateHandle: uint64, pchTitle: str)
static int luasteam_RemoteStorage_UpdatePublishedFileTitle(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	PublishedFileUpdateHandle_t updateHandle(luasteam::checkuint64(L, 1));
	const char *pchTitle = luaL_checkstring(L, 2);
	bool __ret = iface->UpdatePublishedFileTitle(updateHandle, pchTitle);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool UpdatePublishedFileDescription(PublishedFileUpdateHandle_t updateHandle, const char * pchDescription);
// In Lua:
// bool RemoteStorage.UpdatePublishedFileDescription(updateHandle: uint64, pchDescription: str)
static int luasteam_RemoteStorage_UpdatePublishedFileDescription(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	PublishedFileUpdateHandle_t updateHandle(luasteam::checkuint64(L, 1));
	const char *pchDescription = luaL_checkstring(L, 2);
	bool __ret = iface->UpdatePublishedFileDescription(updateHandle, pchDescription);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool UpdatePublishedFileVisibility(PublishedFileUpdateHandle_t updateHandle, ERemoteStoragePublishedFileVisibility eVisibility);
// In Lua:
// bool RemoteStorage.UpdatePublishedFileVisibility(updateHandle: uint64, eVisibility: int)
static int luasteam_RemoteStorage_UpdatePublishedFileVisibility(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	PublishedFileUpdateHandle_t updateHandle(luasteam::checkuint64(L, 1));
	ERemoteStoragePublishedFileVisibility eVisibility = static_cast<ERemoteStoragePublishedFileVisibility>(luaL_checkint(L, 2));
	bool __ret = iface->UpdatePublishedFileVisibility(updateHandle, eVisibility);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool UpdatePublishedFileTags(PublishedFileUpdateHandle_t updateHandle, SteamParamStringArray_t * pTags);
// In Lua:
// (bool, pTags: SteamParamStringArray_t) RemoteStorage.UpdatePublishedFileTags(updateHandle: uint64)
static int luasteam_RemoteStorage_UpdatePublishedFileTags(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	PublishedFileUpdateHandle_t updateHandle(luasteam::checkuint64(L, 1));
	SteamParamStringArray_t pTags;
	bool __ret = iface->UpdatePublishedFileTags(updateHandle, &pTags);
	lua_pushboolean(L, __ret);
	luasteam::push_SteamParamStringArray_t(L, pTags);
	return 2;
}

// In C++:
// SteamAPICall_t CommitPublishedFileUpdate(PublishedFileUpdateHandle_t updateHandle);
// In Lua:
// uint64 RemoteStorage.CommitPublishedFileUpdate(updateHandle: uint64, callback: function)
static int luasteam_RemoteStorage_CommitPublishedFileUpdate(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	PublishedFileUpdateHandle_t updateHandle(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = iface->CommitPublishedFileUpdate(updateHandle);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<RemoteStorageUpdatePublishedFileResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<RemoteStorageUpdatePublishedFileResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t GetPublishedFileDetails(PublishedFileId_t unPublishedFileId, uint32 unMaxSecondsOld);
// In Lua:
// uint64 RemoteStorage.GetPublishedFileDetails(unPublishedFileId: uint64, unMaxSecondsOld: int, callback: function)
static int luasteam_RemoteStorage_GetPublishedFileDetails(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	PublishedFileId_t unPublishedFileId(luasteam::checkuint64(L, 1));
	uint32 unMaxSecondsOld = static_cast<uint32>(luaL_checkint(L, 2));
	SteamAPICall_t __ret = iface->GetPublishedFileDetails(unPublishedFileId, unMaxSecondsOld);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<RemoteStorageGetPublishedFileDetailsResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<RemoteStorageGetPublishedFileDetailsResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t DeletePublishedFile(PublishedFileId_t unPublishedFileId);
// In Lua:
// uint64 RemoteStorage.DeletePublishedFile(unPublishedFileId: uint64, callback: function)
static int luasteam_RemoteStorage_DeletePublishedFile(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	PublishedFileId_t unPublishedFileId(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = iface->DeletePublishedFile(unPublishedFileId);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<RemoteStorageDeletePublishedFileResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<RemoteStorageDeletePublishedFileResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t EnumerateUserPublishedFiles(uint32 unStartIndex);
// In Lua:
// uint64 RemoteStorage.EnumerateUserPublishedFiles(unStartIndex: int, callback: function)
static int luasteam_RemoteStorage_EnumerateUserPublishedFiles(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	uint32 unStartIndex = static_cast<uint32>(luaL_checkint(L, 1));
	SteamAPICall_t __ret = iface->EnumerateUserPublishedFiles(unStartIndex);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<RemoteStorageEnumerateUserPublishedFilesResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<RemoteStorageEnumerateUserPublishedFilesResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t SubscribePublishedFile(PublishedFileId_t unPublishedFileId);
// In Lua:
// uint64 RemoteStorage.SubscribePublishedFile(unPublishedFileId: uint64, callback: function)
static int luasteam_RemoteStorage_SubscribePublishedFile(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	PublishedFileId_t unPublishedFileId(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = iface->SubscribePublishedFile(unPublishedFileId);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<RemoteStorageSubscribePublishedFileResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<RemoteStorageSubscribePublishedFileResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t EnumerateUserSubscribedFiles(uint32 unStartIndex);
// In Lua:
// uint64 RemoteStorage.EnumerateUserSubscribedFiles(unStartIndex: int, callback: function)
static int luasteam_RemoteStorage_EnumerateUserSubscribedFiles(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	uint32 unStartIndex = static_cast<uint32>(luaL_checkint(L, 1));
	SteamAPICall_t __ret = iface->EnumerateUserSubscribedFiles(unStartIndex);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<RemoteStorageEnumerateUserSubscribedFilesResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<RemoteStorageEnumerateUserSubscribedFilesResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t UnsubscribePublishedFile(PublishedFileId_t unPublishedFileId);
// In Lua:
// uint64 RemoteStorage.UnsubscribePublishedFile(unPublishedFileId: uint64, callback: function)
static int luasteam_RemoteStorage_UnsubscribePublishedFile(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	PublishedFileId_t unPublishedFileId(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = iface->UnsubscribePublishedFile(unPublishedFileId);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<RemoteStorageUnsubscribePublishedFileResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<RemoteStorageUnsubscribePublishedFileResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// bool UpdatePublishedFileSetChangeDescription(PublishedFileUpdateHandle_t updateHandle, const char * pchChangeDescription);
// In Lua:
// bool RemoteStorage.UpdatePublishedFileSetChangeDescription(updateHandle: uint64, pchChangeDescription: str)
static int luasteam_RemoteStorage_UpdatePublishedFileSetChangeDescription(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	PublishedFileUpdateHandle_t updateHandle(luasteam::checkuint64(L, 1));
	const char *pchChangeDescription = luaL_checkstring(L, 2);
	bool __ret = iface->UpdatePublishedFileSetChangeDescription(updateHandle, pchChangeDescription);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t GetPublishedItemVoteDetails(PublishedFileId_t unPublishedFileId);
// In Lua:
// uint64 RemoteStorage.GetPublishedItemVoteDetails(unPublishedFileId: uint64, callback: function)
static int luasteam_RemoteStorage_GetPublishedItemVoteDetails(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	PublishedFileId_t unPublishedFileId(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = iface->GetPublishedItemVoteDetails(unPublishedFileId);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<RemoteStorageGetPublishedItemVoteDetailsResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<RemoteStorageGetPublishedItemVoteDetailsResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t UpdateUserPublishedItemVote(PublishedFileId_t unPublishedFileId, bool bVoteUp);
// In Lua:
// uint64 RemoteStorage.UpdateUserPublishedItemVote(unPublishedFileId: uint64, bVoteUp: bool, callback: function)
static int luasteam_RemoteStorage_UpdateUserPublishedItemVote(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	PublishedFileId_t unPublishedFileId(luasteam::checkuint64(L, 1));
	bool bVoteUp = lua_toboolean(L, 2);
	SteamAPICall_t __ret = iface->UpdateUserPublishedItemVote(unPublishedFileId, bVoteUp);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<RemoteStorageUpdateUserPublishedItemVoteResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<RemoteStorageUpdateUserPublishedItemVoteResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t GetUserPublishedItemVoteDetails(PublishedFileId_t unPublishedFileId);
// In Lua:
// uint64 RemoteStorage.GetUserPublishedItemVoteDetails(unPublishedFileId: uint64, callback: function)
static int luasteam_RemoteStorage_GetUserPublishedItemVoteDetails(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	PublishedFileId_t unPublishedFileId(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = iface->GetUserPublishedItemVoteDetails(unPublishedFileId);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<RemoteStorageGetPublishedItemVoteDetailsResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<RemoteStorageGetPublishedItemVoteDetailsResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t EnumerateUserSharedWorkshopFiles(CSteamID steamId, uint32 unStartIndex, SteamParamStringArray_t * pRequiredTags, SteamParamStringArray_t * pExcludedTags);
// In Lua:
// (uint64, pRequiredTags: SteamParamStringArray_t, pExcludedTags: SteamParamStringArray_t) RemoteStorage.EnumerateUserSharedWorkshopFiles(steamId: uint64, unStartIndex: int, callback: function)
static int luasteam_RemoteStorage_EnumerateUserSharedWorkshopFiles(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	CSteamID steamId(luasteam::checkuint64(L, 1));
	uint32 unStartIndex = static_cast<uint32>(luaL_checkint(L, 2));
	SteamParamStringArray_t pRequiredTags;
	SteamParamStringArray_t pExcludedTags;
	SteamAPICall_t __ret = iface->EnumerateUserSharedWorkshopFiles(steamId, unStartIndex, &pRequiredTags, &pExcludedTags);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<RemoteStorageEnumerateUserPublishedFilesResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<RemoteStorageEnumerateUserPublishedFilesResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	luasteam::push_SteamParamStringArray_t(L, pRequiredTags);
	luasteam::push_SteamParamStringArray_t(L, pExcludedTags);
	return 3;
}

// In C++:
// SteamAPICall_t PublishVideo(EWorkshopVideoProvider eVideoProvider, const char * pchVideoAccount, const char * pchVideoIdentifier, const char * pchPreviewFile, AppId_t nConsumerAppId, const char * pchTitle, const char * pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t * pTags);
// In Lua:
// (uint64, pTags: SteamParamStringArray_t) RemoteStorage.PublishVideo(eVideoProvider: int, pchVideoAccount: str, pchVideoIdentifier: str, pchPreviewFile: str, nConsumerAppId: int, pchTitle: str, pchDescription: str, eVisibility: int, callback: function)
static int luasteam_RemoteStorage_PublishVideo(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	EWorkshopVideoProvider eVideoProvider = static_cast<EWorkshopVideoProvider>(luaL_checkint(L, 1));
	const char *pchVideoAccount = luaL_checkstring(L, 2);
	const char *pchVideoIdentifier = luaL_checkstring(L, 3);
	const char *pchPreviewFile = luaL_checkstring(L, 4);
	AppId_t nConsumerAppId = static_cast<AppId_t>(luaL_checkint(L, 5));
	const char *pchTitle = luaL_checkstring(L, 6);
	const char *pchDescription = luaL_checkstring(L, 7);
	ERemoteStoragePublishedFileVisibility eVisibility = static_cast<ERemoteStoragePublishedFileVisibility>(luaL_checkint(L, 8));
	SteamParamStringArray_t pTags;
	SteamAPICall_t __ret = iface->PublishVideo(eVideoProvider, pchVideoAccount, pchVideoIdentifier, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility, &pTags);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<RemoteStoragePublishFileProgress_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<RemoteStoragePublishFileProgress_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	luasteam::push_SteamParamStringArray_t(L, pTags);
	return 2;
}

// In C++:
// SteamAPICall_t SetUserPublishedFileAction(PublishedFileId_t unPublishedFileId, EWorkshopFileAction eAction);
// In Lua:
// uint64 RemoteStorage.SetUserPublishedFileAction(unPublishedFileId: uint64, eAction: int, callback: function)
static int luasteam_RemoteStorage_SetUserPublishedFileAction(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	PublishedFileId_t unPublishedFileId(luasteam::checkuint64(L, 1));
	EWorkshopFileAction eAction = static_cast<EWorkshopFileAction>(luaL_checkint(L, 2));
	SteamAPICall_t __ret = iface->SetUserPublishedFileAction(unPublishedFileId, eAction);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<RemoteStorageSetUserPublishedFileActionResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<RemoteStorageSetUserPublishedFileActionResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t EnumeratePublishedFilesByUserAction(EWorkshopFileAction eAction, uint32 unStartIndex);
// In Lua:
// uint64 RemoteStorage.EnumeratePublishedFilesByUserAction(eAction: int, unStartIndex: int, callback: function)
static int luasteam_RemoteStorage_EnumeratePublishedFilesByUserAction(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	EWorkshopFileAction eAction = static_cast<EWorkshopFileAction>(luaL_checkint(L, 1));
	uint32 unStartIndex = static_cast<uint32>(luaL_checkint(L, 2));
	SteamAPICall_t __ret = iface->EnumeratePublishedFilesByUserAction(eAction, unStartIndex);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<RemoteStorageEnumeratePublishedFilesByUserActionResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<RemoteStorageEnumeratePublishedFilesByUserActionResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t EnumeratePublishedWorkshopFiles(EWorkshopEnumerationType eEnumerationType, uint32 unStartIndex, uint32 unCount, uint32 unDays, SteamParamStringArray_t * pTags, SteamParamStringArray_t * pUserTags);
// In Lua:
// (uint64, pTags: SteamParamStringArray_t, pUserTags: SteamParamStringArray_t) RemoteStorage.EnumeratePublishedWorkshopFiles(eEnumerationType: int, unStartIndex: int, unCount: int, unDays: int, callback: function)
static int luasteam_RemoteStorage_EnumeratePublishedWorkshopFiles(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	EWorkshopEnumerationType eEnumerationType = static_cast<EWorkshopEnumerationType>(luaL_checkint(L, 1));
	uint32 unStartIndex = static_cast<uint32>(luaL_checkint(L, 2));
	uint32 unCount = static_cast<uint32>(luaL_checkint(L, 3));
	uint32 unDays = static_cast<uint32>(luaL_checkint(L, 4));
	SteamParamStringArray_t pTags;
	SteamParamStringArray_t pUserTags;
	SteamAPICall_t __ret = iface->EnumeratePublishedWorkshopFiles(eEnumerationType, unStartIndex, unCount, unDays, &pTags, &pUserTags);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<RemoteStorageEnumerateWorkshopFilesResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<RemoteStorageEnumerateWorkshopFilesResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	luasteam::push_SteamParamStringArray_t(L, pTags);
	luasteam::push_SteamParamStringArray_t(L, pUserTags);
	return 3;
}

// In C++:
// SteamAPICall_t UGCDownloadToLocation(UGCHandle_t hContent, const char * pchLocation, uint32 unPriority);
// In Lua:
// uint64 RemoteStorage.UGCDownloadToLocation(hContent: uint64, pchLocation: str, unPriority: int, callback: function)
static int luasteam_RemoteStorage_UGCDownloadToLocation(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	UGCHandle_t hContent(luasteam::checkuint64(L, 1));
	const char *pchLocation = luaL_checkstring(L, 2);
	uint32 unPriority = static_cast<uint32>(luaL_checkint(L, 3));
	SteamAPICall_t __ret = iface->UGCDownloadToLocation(hContent, pchLocation, unPriority);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<RemoteStorageDownloadUGCResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<RemoteStorageDownloadUGCResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// int32 GetLocalFileChangeCount();
// In Lua:
// int RemoteStorage.GetLocalFileChangeCount()
static int luasteam_RemoteStorage_GetLocalFileChangeCount(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	int32 __ret = iface->GetLocalFileChangeCount();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// const char * GetLocalFileChange(int iFile, ERemoteStorageLocalFileChange * pEChangeType, ERemoteStorageFilePathType * pEFilePathType);
// In Lua:
// (str, pEChangeType: int, pEFilePathType: int) RemoteStorage.GetLocalFileChange(iFile: int)
static int luasteam_RemoteStorage_GetLocalFileChange(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	int iFile = static_cast<int>(luaL_checkint(L, 1));
	ERemoteStorageLocalFileChange pEChangeType;
	ERemoteStorageFilePathType pEFilePathType;
	const char * __ret = iface->GetLocalFileChange(iFile, &pEChangeType, &pEFilePathType);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	lua_pushinteger(L, pEChangeType);
	lua_pushinteger(L, pEFilePathType);
	return 3;
}

// In C++:
// bool BeginFileWriteBatch();
// In Lua:
// bool RemoteStorage.BeginFileWriteBatch()
static int luasteam_RemoteStorage_BeginFileWriteBatch(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	bool __ret = iface->BeginFileWriteBatch();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool EndFileWriteBatch();
// In Lua:
// bool RemoteStorage.EndFileWriteBatch()
static int luasteam_RemoteStorage_EndFileWriteBatch(lua_State *L) {
	auto *iface = SteamRemoteStorage();
	bool __ret = iface->EndFileWriteBatch();
	lua_pushboolean(L, __ret);
	return 1;
}

void register_RemoteStorage_auto(lua_State *L) {
	add_func(L, "FileWrite", luasteam_RemoteStorage_FileWrite);
	add_func(L, "FileRead", luasteam_RemoteStorage_FileRead);
	add_func(L, "FileWriteAsync", luasteam_RemoteStorage_FileWriteAsync);
	add_func(L, "FileReadAsync", luasteam_RemoteStorage_FileReadAsync);
	add_func(L, "FileReadAsyncComplete", luasteam_RemoteStorage_FileReadAsyncComplete);
	add_func(L, "FileForget", luasteam_RemoteStorage_FileForget);
	add_func(L, "FileDelete", luasteam_RemoteStorage_FileDelete);
	add_func(L, "FileShare", luasteam_RemoteStorage_FileShare);
	add_func(L, "SetSyncPlatforms", luasteam_RemoteStorage_SetSyncPlatforms);
	add_func(L, "FileWriteStreamOpen", luasteam_RemoteStorage_FileWriteStreamOpen);
	add_func(L, "FileWriteStreamWriteChunk", luasteam_RemoteStorage_FileWriteStreamWriteChunk);
	add_func(L, "FileWriteStreamClose", luasteam_RemoteStorage_FileWriteStreamClose);
	add_func(L, "FileWriteStreamCancel", luasteam_RemoteStorage_FileWriteStreamCancel);
	add_func(L, "FileExists", luasteam_RemoteStorage_FileExists);
	add_func(L, "FilePersisted", luasteam_RemoteStorage_FilePersisted);
	add_func(L, "GetFileSize", luasteam_RemoteStorage_GetFileSize);
	add_func(L, "GetFileTimestamp", luasteam_RemoteStorage_GetFileTimestamp);
	add_func(L, "GetSyncPlatforms", luasteam_RemoteStorage_GetSyncPlatforms);
	add_func(L, "GetFileCount", luasteam_RemoteStorage_GetFileCount);
	add_func(L, "GetFileNameAndSize", luasteam_RemoteStorage_GetFileNameAndSize);
	add_func(L, "GetQuota", luasteam_RemoteStorage_GetQuota);
	add_func(L, "IsCloudEnabledForAccount", luasteam_RemoteStorage_IsCloudEnabledForAccount);
	add_func(L, "IsCloudEnabledForApp", luasteam_RemoteStorage_IsCloudEnabledForApp);
	add_func(L, "SetCloudEnabledForApp", luasteam_RemoteStorage_SetCloudEnabledForApp);
	add_func(L, "UGCDownload", luasteam_RemoteStorage_UGCDownload);
	add_func(L, "GetUGCDownloadProgress", luasteam_RemoteStorage_GetUGCDownloadProgress);
	add_func(L, "UGCRead", luasteam_RemoteStorage_UGCRead);
	add_func(L, "GetCachedUGCCount", luasteam_RemoteStorage_GetCachedUGCCount);
	add_func(L, "GetCachedUGCHandle", luasteam_RemoteStorage_GetCachedUGCHandle);
	add_func(L, "PublishWorkshopFile", luasteam_RemoteStorage_PublishWorkshopFile);
	add_func(L, "CreatePublishedFileUpdateRequest", luasteam_RemoteStorage_CreatePublishedFileUpdateRequest);
	add_func(L, "UpdatePublishedFileFile", luasteam_RemoteStorage_UpdatePublishedFileFile);
	add_func(L, "UpdatePublishedFilePreviewFile", luasteam_RemoteStorage_UpdatePublishedFilePreviewFile);
	add_func(L, "UpdatePublishedFileTitle", luasteam_RemoteStorage_UpdatePublishedFileTitle);
	add_func(L, "UpdatePublishedFileDescription", luasteam_RemoteStorage_UpdatePublishedFileDescription);
	add_func(L, "UpdatePublishedFileVisibility", luasteam_RemoteStorage_UpdatePublishedFileVisibility);
	add_func(L, "UpdatePublishedFileTags", luasteam_RemoteStorage_UpdatePublishedFileTags);
	add_func(L, "CommitPublishedFileUpdate", luasteam_RemoteStorage_CommitPublishedFileUpdate);
	add_func(L, "GetPublishedFileDetails", luasteam_RemoteStorage_GetPublishedFileDetails);
	add_func(L, "DeletePublishedFile", luasteam_RemoteStorage_DeletePublishedFile);
	add_func(L, "EnumerateUserPublishedFiles", luasteam_RemoteStorage_EnumerateUserPublishedFiles);
	add_func(L, "SubscribePublishedFile", luasteam_RemoteStorage_SubscribePublishedFile);
	add_func(L, "EnumerateUserSubscribedFiles", luasteam_RemoteStorage_EnumerateUserSubscribedFiles);
	add_func(L, "UnsubscribePublishedFile", luasteam_RemoteStorage_UnsubscribePublishedFile);
	add_func(L, "UpdatePublishedFileSetChangeDescription", luasteam_RemoteStorage_UpdatePublishedFileSetChangeDescription);
	add_func(L, "GetPublishedItemVoteDetails", luasteam_RemoteStorage_GetPublishedItemVoteDetails);
	add_func(L, "UpdateUserPublishedItemVote", luasteam_RemoteStorage_UpdateUserPublishedItemVote);
	add_func(L, "GetUserPublishedItemVoteDetails", luasteam_RemoteStorage_GetUserPublishedItemVoteDetails);
	add_func(L, "EnumerateUserSharedWorkshopFiles", luasteam_RemoteStorage_EnumerateUserSharedWorkshopFiles);
	add_func(L, "PublishVideo", luasteam_RemoteStorage_PublishVideo);
	add_func(L, "SetUserPublishedFileAction", luasteam_RemoteStorage_SetUserPublishedFileAction);
	add_func(L, "EnumeratePublishedFilesByUserAction", luasteam_RemoteStorage_EnumeratePublishedFilesByUserAction);
	add_func(L, "EnumeratePublishedWorkshopFiles", luasteam_RemoteStorage_EnumeratePublishedWorkshopFiles);
	add_func(L, "UGCDownloadToLocation", luasteam_RemoteStorage_UGCDownloadToLocation);
	add_func(L, "GetLocalFileChangeCount", luasteam_RemoteStorage_GetLocalFileChangeCount);
	add_func(L, "GetLocalFileChange", luasteam_RemoteStorage_GetLocalFileChange);
	add_func(L, "BeginFileWriteBatch", luasteam_RemoteStorage_BeginFileWriteBatch);
	add_func(L, "EndFileWriteBatch", luasteam_RemoteStorage_EndFileWriteBatch);
}

void add_RemoteStorage_auto(lua_State *L) {
	lua_createtable(L, 0, 58);
	register_RemoteStorage_auto(L);
	lua_pushvalue(L, -1);
	RemoteStorage_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "RemoteStorage");
}

} // namespace luasteam
