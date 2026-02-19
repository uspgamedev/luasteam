#include "auto.hpp"

namespace luasteam {

int RemoteStorage_ref = LUA_NOREF;

namespace {
class CallbackListener {
private:
	STEAM_CALLBACK(CallbackListener, OnRemoteStorageFileShareResult, RemoteStorageFileShareResult_t);
	STEAM_CALLBACK(CallbackListener, OnRemoteStoragePublishFileResult, RemoteStoragePublishFileResult_t);
	STEAM_CALLBACK(CallbackListener, OnRemoteStorageDeletePublishedFileResult, RemoteStorageDeletePublishedFileResult_t);
	STEAM_CALLBACK(CallbackListener, OnRemoteStorageEnumerateUserPublishedFilesResult, RemoteStorageEnumerateUserPublishedFilesResult_t);
	STEAM_CALLBACK(CallbackListener, OnRemoteStorageSubscribePublishedFileResult, RemoteStorageSubscribePublishedFileResult_t);
	STEAM_CALLBACK(CallbackListener, OnRemoteStorageEnumerateUserSubscribedFilesResult, RemoteStorageEnumerateUserSubscribedFilesResult_t);
	STEAM_CALLBACK(CallbackListener, OnRemoteStorageUnsubscribePublishedFileResult, RemoteStorageUnsubscribePublishedFileResult_t);
	STEAM_CALLBACK(CallbackListener, OnRemoteStorageUpdatePublishedFileResult, RemoteStorageUpdatePublishedFileResult_t);
	STEAM_CALLBACK(CallbackListener, OnRemoteStorageDownloadUGCResult, RemoteStorageDownloadUGCResult_t);
	STEAM_CALLBACK(CallbackListener, OnRemoteStorageGetPublishedFileDetailsResult, RemoteStorageGetPublishedFileDetailsResult_t);
	STEAM_CALLBACK(CallbackListener, OnRemoteStorageEnumerateWorkshopFilesResult, RemoteStorageEnumerateWorkshopFilesResult_t);
	STEAM_CALLBACK(CallbackListener, OnRemoteStorageGetPublishedItemVoteDetailsResult, RemoteStorageGetPublishedItemVoteDetailsResult_t);
	STEAM_CALLBACK(CallbackListener, OnRemoteStoragePublishedFileSubscribed, RemoteStoragePublishedFileSubscribed_t);
	STEAM_CALLBACK(CallbackListener, OnRemoteStoragePublishedFileUnsubscribed, RemoteStoragePublishedFileUnsubscribed_t);
	STEAM_CALLBACK(CallbackListener, OnRemoteStoragePublishedFileDeleted, RemoteStoragePublishedFileDeleted_t);
	STEAM_CALLBACK(CallbackListener, OnRemoteStorageUpdateUserPublishedItemVoteResult, RemoteStorageUpdateUserPublishedItemVoteResult_t);
	STEAM_CALLBACK(CallbackListener, OnRemoteStorageUserVoteDetails, RemoteStorageUserVoteDetails_t);
	STEAM_CALLBACK(CallbackListener, OnRemoteStorageEnumerateUserSharedWorkshopFilesResult, RemoteStorageEnumerateUserSharedWorkshopFilesResult_t);
	STEAM_CALLBACK(CallbackListener, OnRemoteStorageSetUserPublishedFileActionResult, RemoteStorageSetUserPublishedFileActionResult_t);
	STEAM_CALLBACK(CallbackListener, OnRemoteStorageEnumeratePublishedFilesByUserActionResult, RemoteStorageEnumeratePublishedFilesByUserActionResult_t);
	STEAM_CALLBACK(CallbackListener, OnRemoteStoragePublishFileProgress, RemoteStoragePublishFileProgress_t);
	STEAM_CALLBACK(CallbackListener, OnRemoteStoragePublishedFileUpdated, RemoteStoragePublishedFileUpdated_t);
	STEAM_CALLBACK(CallbackListener, OnRemoteStorageFileWriteAsyncComplete, RemoteStorageFileWriteAsyncComplete_t);
	STEAM_CALLBACK(CallbackListener, OnRemoteStorageFileReadAsyncComplete, RemoteStorageFileReadAsyncComplete_t);
	STEAM_CALLBACK(CallbackListener, OnRemoteStorageLocalFileChange, RemoteStorageLocalFileChange_t);
};
void CallbackListener::OnRemoteStorageFileShareResult(RemoteStorageFileShareResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageFileShareResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 3);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		luasteam::pushuint64(L, data->m_hFile);
		lua_setfield(L, -2, "m_hFile");
		lua_pushstring(L, reinterpret_cast<const char*>(data->m_rgchFilename));
		lua_setfield(L, -2, "m_rgchFilename");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnRemoteStoragePublishFileResult(RemoteStoragePublishFileResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStoragePublishFileResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 3);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		luasteam::pushuint64(L, data->m_nPublishedFileId);
		lua_setfield(L, -2, "m_nPublishedFileId");
		lua_pushboolean(L, data->m_bUserNeedsToAcceptWorkshopLegalAgreement);
		lua_setfield(L, -2, "m_bUserNeedsToAcceptWorkshopLegalAgreement");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnRemoteStorageDeletePublishedFileResult(RemoteStorageDeletePublishedFileResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageDeletePublishedFileResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 2);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		luasteam::pushuint64(L, data->m_nPublishedFileId);
		lua_setfield(L, -2, "m_nPublishedFileId");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnRemoteStorageEnumerateUserPublishedFilesResult(RemoteStorageEnumerateUserPublishedFilesResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageEnumerateUserPublishedFilesResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 4);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		lua_pushinteger(L, data->m_nResultsReturned);
		lua_setfield(L, -2, "m_nResultsReturned");
		lua_pushinteger(L, data->m_nTotalResultCount);
		lua_setfield(L, -2, "m_nTotalResultCount");
		lua_createtable(L, 50, 0);
		for(decltype(50) i=0;i<50;i++){
			luasteam::pushuint64(L, data->m_rgPublishedFileId[i]);
			lua_rawseti(L, -2, i+1);
		}
		lua_setfield(L, -2, "m_rgPublishedFileId");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnRemoteStorageSubscribePublishedFileResult(RemoteStorageSubscribePublishedFileResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageSubscribePublishedFileResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 2);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		luasteam::pushuint64(L, data->m_nPublishedFileId);
		lua_setfield(L, -2, "m_nPublishedFileId");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnRemoteStorageEnumerateUserSubscribedFilesResult(RemoteStorageEnumerateUserSubscribedFilesResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageEnumerateUserSubscribedFilesResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 5);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		lua_pushinteger(L, data->m_nResultsReturned);
		lua_setfield(L, -2, "m_nResultsReturned");
		lua_pushinteger(L, data->m_nTotalResultCount);
		lua_setfield(L, -2, "m_nTotalResultCount");
		lua_createtable(L, 50, 0);
		for(decltype(50) i=0;i<50;i++){
			luasteam::pushuint64(L, data->m_rgPublishedFileId[i]);
			lua_rawseti(L, -2, i+1);
		}
		lua_setfield(L, -2, "m_rgPublishedFileId");
		lua_createtable(L, 50, 0);
		for(decltype(50) i=0;i<50;i++){
			lua_pushinteger(L, data->m_rgRTimeSubscribed[i]);
			lua_rawseti(L, -2, i+1);
		}
		lua_setfield(L, -2, "m_rgRTimeSubscribed");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnRemoteStorageUnsubscribePublishedFileResult(RemoteStorageUnsubscribePublishedFileResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageUnsubscribePublishedFileResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 2);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		luasteam::pushuint64(L, data->m_nPublishedFileId);
		lua_setfield(L, -2, "m_nPublishedFileId");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnRemoteStorageUpdatePublishedFileResult(RemoteStorageUpdatePublishedFileResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageUpdatePublishedFileResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 3);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		luasteam::pushuint64(L, data->m_nPublishedFileId);
		lua_setfield(L, -2, "m_nPublishedFileId");
		lua_pushboolean(L, data->m_bUserNeedsToAcceptWorkshopLegalAgreement);
		lua_setfield(L, -2, "m_bUserNeedsToAcceptWorkshopLegalAgreement");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnRemoteStorageDownloadUGCResult(RemoteStorageDownloadUGCResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageDownloadUGCResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
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
		lua_pushstring(L, reinterpret_cast<const char*>(data->m_pchFileName));
		lua_setfield(L, -2, "m_pchFileName");
		luasteam::pushuint64(L, data->m_ulSteamIDOwner);
		lua_setfield(L, -2, "m_ulSteamIDOwner");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnRemoteStorageGetPublishedFileDetailsResult(RemoteStorageGetPublishedFileDetailsResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageGetPublishedFileDetailsResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
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
		lua_pushstring(L, reinterpret_cast<const char*>(data->m_rgchTitle));
		lua_setfield(L, -2, "m_rgchTitle");
		lua_pushstring(L, reinterpret_cast<const char*>(data->m_rgchDescription));
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
		lua_pushstring(L, reinterpret_cast<const char*>(data->m_rgchTags));
		lua_setfield(L, -2, "m_rgchTags");
		lua_pushboolean(L, data->m_bTagsTruncated);
		lua_setfield(L, -2, "m_bTagsTruncated");
		lua_pushstring(L, reinterpret_cast<const char*>(data->m_pchFileName));
		lua_setfield(L, -2, "m_pchFileName");
		lua_pushinteger(L, data->m_nFileSize);
		lua_setfield(L, -2, "m_nFileSize");
		lua_pushinteger(L, data->m_nPreviewFileSize);
		lua_setfield(L, -2, "m_nPreviewFileSize");
		lua_pushstring(L, reinterpret_cast<const char*>(data->m_rgchURL));
		lua_setfield(L, -2, "m_rgchURL");
		lua_pushinteger(L, data->m_eFileType);
		lua_setfield(L, -2, "m_eFileType");
		lua_pushboolean(L, data->m_bAcceptedForUse);
		lua_setfield(L, -2, "m_bAcceptedForUse");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnRemoteStorageEnumerateWorkshopFilesResult(RemoteStorageEnumerateWorkshopFilesResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageEnumerateWorkshopFilesResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 7);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		lua_pushinteger(L, data->m_nResultsReturned);
		lua_setfield(L, -2, "m_nResultsReturned");
		lua_pushinteger(L, data->m_nTotalResultCount);
		lua_setfield(L, -2, "m_nTotalResultCount");
		lua_createtable(L, 50, 0);
		for(decltype(50) i=0;i<50;i++){
			luasteam::pushuint64(L, data->m_rgPublishedFileId[i]);
			lua_rawseti(L, -2, i+1);
		}
		lua_setfield(L, -2, "m_rgPublishedFileId");
		lua_createtable(L, 50, 0);
		for(decltype(50) i=0;i<50;i++){
			lua_pushnumber(L, data->m_rgScore[i]);
			lua_rawseti(L, -2, i+1);
		}
		lua_setfield(L, -2, "m_rgScore");
		lua_pushinteger(L, data->m_nAppId);
		lua_setfield(L, -2, "m_nAppId");
		lua_pushinteger(L, data->m_unStartIndex);
		lua_setfield(L, -2, "m_unStartIndex");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnRemoteStorageGetPublishedItemVoteDetailsResult(RemoteStorageGetPublishedItemVoteDetailsResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageGetPublishedItemVoteDetailsResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
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
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnRemoteStoragePublishedFileSubscribed(RemoteStoragePublishedFileSubscribed_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStoragePublishedFileSubscribed");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 2);
		luasteam::pushuint64(L, data->m_nPublishedFileId);
		lua_setfield(L, -2, "m_nPublishedFileId");
		lua_pushinteger(L, data->m_nAppID);
		lua_setfield(L, -2, "m_nAppID");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnRemoteStoragePublishedFileUnsubscribed(RemoteStoragePublishedFileUnsubscribed_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStoragePublishedFileUnsubscribed");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 2);
		luasteam::pushuint64(L, data->m_nPublishedFileId);
		lua_setfield(L, -2, "m_nPublishedFileId");
		lua_pushinteger(L, data->m_nAppID);
		lua_setfield(L, -2, "m_nAppID");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnRemoteStoragePublishedFileDeleted(RemoteStoragePublishedFileDeleted_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStoragePublishedFileDeleted");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 2);
		luasteam::pushuint64(L, data->m_nPublishedFileId);
		lua_setfield(L, -2, "m_nPublishedFileId");
		lua_pushinteger(L, data->m_nAppID);
		lua_setfield(L, -2, "m_nAppID");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnRemoteStorageUpdateUserPublishedItemVoteResult(RemoteStorageUpdateUserPublishedItemVoteResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageUpdateUserPublishedItemVoteResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 2);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		luasteam::pushuint64(L, data->m_nPublishedFileId);
		lua_setfield(L, -2, "m_nPublishedFileId");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnRemoteStorageUserVoteDetails(RemoteStorageUserVoteDetails_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageUserVoteDetails");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 3);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		luasteam::pushuint64(L, data->m_nPublishedFileId);
		lua_setfield(L, -2, "m_nPublishedFileId");
		lua_pushinteger(L, data->m_eVote);
		lua_setfield(L, -2, "m_eVote");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnRemoteStorageEnumerateUserSharedWorkshopFilesResult(RemoteStorageEnumerateUserSharedWorkshopFilesResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageEnumerateUserSharedWorkshopFilesResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 4);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		lua_pushinteger(L, data->m_nResultsReturned);
		lua_setfield(L, -2, "m_nResultsReturned");
		lua_pushinteger(L, data->m_nTotalResultCount);
		lua_setfield(L, -2, "m_nTotalResultCount");
		lua_createtable(L, 50, 0);
		for(decltype(50) i=0;i<50;i++){
			luasteam::pushuint64(L, data->m_rgPublishedFileId[i]);
			lua_rawseti(L, -2, i+1);
		}
		lua_setfield(L, -2, "m_rgPublishedFileId");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnRemoteStorageSetUserPublishedFileActionResult(RemoteStorageSetUserPublishedFileActionResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageSetUserPublishedFileActionResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 3);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		luasteam::pushuint64(L, data->m_nPublishedFileId);
		lua_setfield(L, -2, "m_nPublishedFileId");
		lua_pushinteger(L, data->m_eAction);
		lua_setfield(L, -2, "m_eAction");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnRemoteStorageEnumeratePublishedFilesByUserActionResult(RemoteStorageEnumeratePublishedFilesByUserActionResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageEnumeratePublishedFilesByUserActionResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
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
		for(decltype(50) i=0;i<50;i++){
			luasteam::pushuint64(L, data->m_rgPublishedFileId[i]);
			lua_rawseti(L, -2, i+1);
		}
		lua_setfield(L, -2, "m_rgPublishedFileId");
		lua_createtable(L, 50, 0);
		for(decltype(50) i=0;i<50;i++){
			lua_pushinteger(L, data->m_rgRTimeUpdated[i]);
			lua_rawseti(L, -2, i+1);
		}
		lua_setfield(L, -2, "m_rgRTimeUpdated");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnRemoteStoragePublishFileProgress(RemoteStoragePublishFileProgress_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStoragePublishFileProgress");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 2);
		lua_pushnumber(L, data->m_dPercentFile);
		lua_setfield(L, -2, "m_dPercentFile");
		lua_pushboolean(L, data->m_bPreview);
		lua_setfield(L, -2, "m_bPreview");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnRemoteStoragePublishedFileUpdated(RemoteStoragePublishedFileUpdated_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStoragePublishedFileUpdated");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 3);
		luasteam::pushuint64(L, data->m_nPublishedFileId);
		lua_setfield(L, -2, "m_nPublishedFileId");
		lua_pushinteger(L, data->m_nAppID);
		lua_setfield(L, -2, "m_nAppID");
		luasteam::pushuint64(L, data->m_ulUnused);
		lua_setfield(L, -2, "m_ulUnused");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnRemoteStorageFileWriteAsyncComplete(RemoteStorageFileWriteAsyncComplete_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageFileWriteAsyncComplete");
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
void CallbackListener::OnRemoteStorageFileReadAsyncComplete(RemoteStorageFileReadAsyncComplete_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageFileReadAsyncComplete");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
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
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnRemoteStorageLocalFileChange(RemoteStorageLocalFileChange_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
	lua_getfield(L, -1, "OnRemoteStorageLocalFileChange");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 0);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
CallbackListener *RemoteStorage_listener = nullptr;
} // namespace

void init_RemoteStorage_auto(lua_State *L) { RemoteStorage_listener = new CallbackListener(); }
void shutdown_RemoteStorage_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, RemoteStorage_ref);
	RemoteStorage_ref = LUA_NOREF;
	delete RemoteStorage_listener; RemoteStorage_listener = nullptr;
}

// bool FileWrite(const char * pchFile, const void * pvData, int32 cubData);
EXTERN int luasteam_RemoteStorage_FileWrite(lua_State *L) {
	const char *pchFile = luaL_checkstring(L, 1);
	const char *pvData = luaL_checkstring(L, 2);
	int32 cubData = static_cast<int32>(luaL_checkint(L, 3));
	bool __ret = SteamRemoteStorage()->FileWrite(pchFile, pvData, cubData);
	lua_pushboolean(L, __ret);
	return 1;
}

// int32 FileRead(const char * pchFile, void * pvData, int32 cubDataToRead);
EXTERN int luasteam_RemoteStorage_FileRead(lua_State *L) {
	const char *pchFile = luaL_checkstring(L, 1);
	int32 cubDataToRead = luaL_checkint(L, 2);
	std::vector<unsigned char> pvData(cubDataToRead);
	int32 __ret = SteamRemoteStorage()->FileRead(pchFile, pvData.data(), cubDataToRead);
	lua_pushinteger(L, __ret);
	lua_pushlstring(L, reinterpret_cast<const char*>(pvData.data()), __ret);
	return 1;
}

// SteamAPICall_t FileWriteAsync(const char * pchFile, const void * pvData, uint32 cubData);
EXTERN int luasteam_RemoteStorage_FileWriteAsync(lua_State *L) {
	const char *pchFile = luaL_checkstring(L, 1);
	const char *pvData = luaL_checkstring(L, 2);
	uint32 cubData = static_cast<uint32>(luaL_checkint(L, 3));
	SteamAPICall_t __ret = SteamRemoteStorage()->FileWriteAsync(pchFile, pvData, cubData);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// SteamAPICall_t FileReadAsync(const char * pchFile, uint32 nOffset, uint32 cubToRead);
EXTERN int luasteam_RemoteStorage_FileReadAsync(lua_State *L) {
	const char *pchFile = luaL_checkstring(L, 1);
	uint32 nOffset = static_cast<uint32>(luaL_checkint(L, 2));
	uint32 cubToRead = static_cast<uint32>(luaL_checkint(L, 3));
	SteamAPICall_t __ret = SteamRemoteStorage()->FileReadAsync(pchFile, nOffset, cubToRead);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// bool FileReadAsyncComplete(SteamAPICall_t hReadCall, void * pvBuffer, uint32 cubToRead);
EXTERN int luasteam_RemoteStorage_FileReadAsyncComplete(lua_State *L) {
	SteamAPICall_t hReadCall(luasteam::checkuint64(L, 1));
	uint32 cubToRead = luaL_checkint(L, 2);
	std::vector<unsigned char> pvBuffer(cubToRead);
	bool __ret = SteamRemoteStorage()->FileReadAsyncComplete(hReadCall, pvBuffer.data(), cubToRead);
	lua_pushboolean(L, __ret);
	lua_pushlstring(L, reinterpret_cast<const char*>(pvBuffer.data()), cubToRead);
	return 1;
}

// bool FileForget(const char * pchFile);
EXTERN int luasteam_RemoteStorage_FileForget(lua_State *L) {
	const char *pchFile = luaL_checkstring(L, 1);
	bool __ret = SteamRemoteStorage()->FileForget(pchFile);
	lua_pushboolean(L, __ret);
	return 1;
}

// bool FileDelete(const char * pchFile);
EXTERN int luasteam_RemoteStorage_FileDelete(lua_State *L) {
	const char *pchFile = luaL_checkstring(L, 1);
	bool __ret = SteamRemoteStorage()->FileDelete(pchFile);
	lua_pushboolean(L, __ret);
	return 1;
}

// SteamAPICall_t FileShare(const char * pchFile);
EXTERN int luasteam_RemoteStorage_FileShare(lua_State *L) {
	const char *pchFile = luaL_checkstring(L, 1);
	SteamAPICall_t __ret = SteamRemoteStorage()->FileShare(pchFile);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// bool SetSyncPlatforms(const char * pchFile, ERemoteStoragePlatform eRemoteStoragePlatform);
EXTERN int luasteam_RemoteStorage_SetSyncPlatforms(lua_State *L) {
	const char *pchFile = luaL_checkstring(L, 1);
	ERemoteStoragePlatform eRemoteStoragePlatform = static_cast<ERemoteStoragePlatform>(luaL_checkint(L, 2));
	bool __ret = SteamRemoteStorage()->SetSyncPlatforms(pchFile, eRemoteStoragePlatform);
	lua_pushboolean(L, __ret);
	return 1;
}

// UGCFileWriteStreamHandle_t FileWriteStreamOpen(const char * pchFile);
EXTERN int luasteam_RemoteStorage_FileWriteStreamOpen(lua_State *L) {
	const char *pchFile = luaL_checkstring(L, 1);
	UGCFileWriteStreamHandle_t __ret = SteamRemoteStorage()->FileWriteStreamOpen(pchFile);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// bool FileWriteStreamWriteChunk(UGCFileWriteStreamHandle_t writeHandle, const void * pvData, int32 cubData);
EXTERN int luasteam_RemoteStorage_FileWriteStreamWriteChunk(lua_State *L) {
	UGCFileWriteStreamHandle_t writeHandle(luasteam::checkuint64(L, 1));
	const char *pvData = luaL_checkstring(L, 2);
	int32 cubData = static_cast<int32>(luaL_checkint(L, 3));
	bool __ret = SteamRemoteStorage()->FileWriteStreamWriteChunk(writeHandle, pvData, cubData);
	lua_pushboolean(L, __ret);
	return 1;
}

// bool FileWriteStreamClose(UGCFileWriteStreamHandle_t writeHandle);
EXTERN int luasteam_RemoteStorage_FileWriteStreamClose(lua_State *L) {
	UGCFileWriteStreamHandle_t writeHandle(luasteam::checkuint64(L, 1));
	bool __ret = SteamRemoteStorage()->FileWriteStreamClose(writeHandle);
	lua_pushboolean(L, __ret);
	return 1;
}

// bool FileWriteStreamCancel(UGCFileWriteStreamHandle_t writeHandle);
EXTERN int luasteam_RemoteStorage_FileWriteStreamCancel(lua_State *L) {
	UGCFileWriteStreamHandle_t writeHandle(luasteam::checkuint64(L, 1));
	bool __ret = SteamRemoteStorage()->FileWriteStreamCancel(writeHandle);
	lua_pushboolean(L, __ret);
	return 1;
}

// bool FileExists(const char * pchFile);
EXTERN int luasteam_RemoteStorage_FileExists(lua_State *L) {
	const char *pchFile = luaL_checkstring(L, 1);
	bool __ret = SteamRemoteStorage()->FileExists(pchFile);
	lua_pushboolean(L, __ret);
	return 1;
}

// bool FilePersisted(const char * pchFile);
EXTERN int luasteam_RemoteStorage_FilePersisted(lua_State *L) {
	const char *pchFile = luaL_checkstring(L, 1);
	bool __ret = SteamRemoteStorage()->FilePersisted(pchFile);
	lua_pushboolean(L, __ret);
	return 1;
}

// int32 GetFileSize(const char * pchFile);
EXTERN int luasteam_RemoteStorage_GetFileSize(lua_State *L) {
	const char *pchFile = luaL_checkstring(L, 1);
	int32 __ret = SteamRemoteStorage()->GetFileSize(pchFile);
	lua_pushinteger(L, __ret);
	return 1;
}

// int64 GetFileTimestamp(const char * pchFile);
EXTERN int luasteam_RemoteStorage_GetFileTimestamp(lua_State *L) {
	const char *pchFile = luaL_checkstring(L, 1);
	int64 __ret = SteamRemoteStorage()->GetFileTimestamp(pchFile);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// ERemoteStoragePlatform GetSyncPlatforms(const char * pchFile);
EXTERN int luasteam_RemoteStorage_GetSyncPlatforms(lua_State *L) {
	const char *pchFile = luaL_checkstring(L, 1);
	ERemoteStoragePlatform __ret = SteamRemoteStorage()->GetSyncPlatforms(pchFile);
	lua_pushinteger(L, __ret);
	return 1;
}

// int32 GetFileCount();
EXTERN int luasteam_RemoteStorage_GetFileCount(lua_State *L) {
	int32 __ret = SteamRemoteStorage()->GetFileCount();
	lua_pushinteger(L, __ret);
	return 1;
}

// const char * GetFileNameAndSize(int iFile, int32 * pnFileSizeInBytes);
EXTERN int luasteam_RemoteStorage_GetFileNameAndSize(lua_State *L) {
	int iFile = static_cast<int>(luaL_checkint(L, 1));
	int32 pnFileSizeInBytes;
	const char * __ret = SteamRemoteStorage()->GetFileNameAndSize(iFile, &pnFileSizeInBytes);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	lua_pushinteger(L, pnFileSizeInBytes);
	return 2;
}

// bool GetQuota(uint64 * pnTotalBytes, uint64 * puAvailableBytes);
EXTERN int luasteam_RemoteStorage_GetQuota(lua_State *L) {
	uint64 pnTotalBytes;
	uint64 puAvailableBytes;
	bool __ret = SteamRemoteStorage()->GetQuota(&pnTotalBytes, &puAvailableBytes);
	lua_pushboolean(L, __ret);
	luasteam::pushuint64(L, pnTotalBytes);
	luasteam::pushuint64(L, puAvailableBytes);
	return 3;
}

// bool IsCloudEnabledForAccount();
EXTERN int luasteam_RemoteStorage_IsCloudEnabledForAccount(lua_State *L) {
	bool __ret = SteamRemoteStorage()->IsCloudEnabledForAccount();
	lua_pushboolean(L, __ret);
	return 1;
}

// bool IsCloudEnabledForApp();
EXTERN int luasteam_RemoteStorage_IsCloudEnabledForApp(lua_State *L) {
	bool __ret = SteamRemoteStorage()->IsCloudEnabledForApp();
	lua_pushboolean(L, __ret);
	return 1;
}

// void SetCloudEnabledForApp(bool bEnabled);
EXTERN int luasteam_RemoteStorage_SetCloudEnabledForApp(lua_State *L) {
	bool bEnabled = lua_toboolean(L, 1);
	SteamRemoteStorage()->SetCloudEnabledForApp(bEnabled);
	return 0;
}

// SteamAPICall_t UGCDownload(UGCHandle_t hContent, uint32 unPriority);
EXTERN int luasteam_RemoteStorage_UGCDownload(lua_State *L) {
	UGCHandle_t hContent(luasteam::checkuint64(L, 1));
	uint32 unPriority = static_cast<uint32>(luaL_checkint(L, 2));
	SteamAPICall_t __ret = SteamRemoteStorage()->UGCDownload(hContent, unPriority);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// bool GetUGCDownloadProgress(UGCHandle_t hContent, int32 * pnBytesDownloaded, int32 * pnBytesExpected);
EXTERN int luasteam_RemoteStorage_GetUGCDownloadProgress(lua_State *L) {
	UGCHandle_t hContent(luasteam::checkuint64(L, 1));
	int32 pnBytesDownloaded;
	int32 pnBytesExpected;
	bool __ret = SteamRemoteStorage()->GetUGCDownloadProgress(hContent, &pnBytesDownloaded, &pnBytesExpected);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pnBytesDownloaded);
	lua_pushinteger(L, pnBytesExpected);
	return 3;
}

// int32 UGCRead(UGCHandle_t hContent, void * pvData, int32 cubDataToRead, uint32 cOffset, EUGCReadAction eAction);
EXTERN int luasteam_RemoteStorage_UGCRead(lua_State *L) {
	UGCHandle_t hContent(luasteam::checkuint64(L, 1));
	int32 cubDataToRead = luaL_checkint(L, 2);
	std::vector<unsigned char> pvData(cubDataToRead);
	uint32 cOffset = static_cast<uint32>(luaL_checkint(L, 3));
	EUGCReadAction eAction = static_cast<EUGCReadAction>(luaL_checkint(L, 4));
	int32 __ret = SteamRemoteStorage()->UGCRead(hContent, pvData.data(), cubDataToRead, cOffset, eAction);
	lua_pushinteger(L, __ret);
	lua_pushlstring(L, reinterpret_cast<const char*>(pvData.data()), cubDataToRead);
	return 1;
}

// int32 GetCachedUGCCount();
EXTERN int luasteam_RemoteStorage_GetCachedUGCCount(lua_State *L) {
	int32 __ret = SteamRemoteStorage()->GetCachedUGCCount();
	lua_pushinteger(L, __ret);
	return 1;
}

// UGCHandle_t GetCachedUGCHandle(int32 iCachedContent);
EXTERN int luasteam_RemoteStorage_GetCachedUGCHandle(lua_State *L) {
	int32 iCachedContent = static_cast<int32>(luaL_checkint(L, 1));
	UGCHandle_t __ret = SteamRemoteStorage()->GetCachedUGCHandle(iCachedContent);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// PublishedFileUpdateHandle_t CreatePublishedFileUpdateRequest(PublishedFileId_t unPublishedFileId);
EXTERN int luasteam_RemoteStorage_CreatePublishedFileUpdateRequest(lua_State *L) {
	PublishedFileId_t unPublishedFileId(luasteam::checkuint64(L, 1));
	PublishedFileUpdateHandle_t __ret = SteamRemoteStorage()->CreatePublishedFileUpdateRequest(unPublishedFileId);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// bool UpdatePublishedFileFile(PublishedFileUpdateHandle_t updateHandle, const char * pchFile);
EXTERN int luasteam_RemoteStorage_UpdatePublishedFileFile(lua_State *L) {
	PublishedFileUpdateHandle_t updateHandle(luasteam::checkuint64(L, 1));
	const char *pchFile = luaL_checkstring(L, 2);
	bool __ret = SteamRemoteStorage()->UpdatePublishedFileFile(updateHandle, pchFile);
	lua_pushboolean(L, __ret);
	return 1;
}

// bool UpdatePublishedFilePreviewFile(PublishedFileUpdateHandle_t updateHandle, const char * pchPreviewFile);
EXTERN int luasteam_RemoteStorage_UpdatePublishedFilePreviewFile(lua_State *L) {
	PublishedFileUpdateHandle_t updateHandle(luasteam::checkuint64(L, 1));
	const char *pchPreviewFile = luaL_checkstring(L, 2);
	bool __ret = SteamRemoteStorage()->UpdatePublishedFilePreviewFile(updateHandle, pchPreviewFile);
	lua_pushboolean(L, __ret);
	return 1;
}

// bool UpdatePublishedFileTitle(PublishedFileUpdateHandle_t updateHandle, const char * pchTitle);
EXTERN int luasteam_RemoteStorage_UpdatePublishedFileTitle(lua_State *L) {
	PublishedFileUpdateHandle_t updateHandle(luasteam::checkuint64(L, 1));
	const char *pchTitle = luaL_checkstring(L, 2);
	bool __ret = SteamRemoteStorage()->UpdatePublishedFileTitle(updateHandle, pchTitle);
	lua_pushboolean(L, __ret);
	return 1;
}

// bool UpdatePublishedFileDescription(PublishedFileUpdateHandle_t updateHandle, const char * pchDescription);
EXTERN int luasteam_RemoteStorage_UpdatePublishedFileDescription(lua_State *L) {
	PublishedFileUpdateHandle_t updateHandle(luasteam::checkuint64(L, 1));
	const char *pchDescription = luaL_checkstring(L, 2);
	bool __ret = SteamRemoteStorage()->UpdatePublishedFileDescription(updateHandle, pchDescription);
	lua_pushboolean(L, __ret);
	return 1;
}

// bool UpdatePublishedFileVisibility(PublishedFileUpdateHandle_t updateHandle, ERemoteStoragePublishedFileVisibility eVisibility);
EXTERN int luasteam_RemoteStorage_UpdatePublishedFileVisibility(lua_State *L) {
	PublishedFileUpdateHandle_t updateHandle(luasteam::checkuint64(L, 1));
	ERemoteStoragePublishedFileVisibility eVisibility = static_cast<ERemoteStoragePublishedFileVisibility>(luaL_checkint(L, 2));
	bool __ret = SteamRemoteStorage()->UpdatePublishedFileVisibility(updateHandle, eVisibility);
	lua_pushboolean(L, __ret);
	return 1;
}

// SteamAPICall_t CommitPublishedFileUpdate(PublishedFileUpdateHandle_t updateHandle);
EXTERN int luasteam_RemoteStorage_CommitPublishedFileUpdate(lua_State *L) {
	PublishedFileUpdateHandle_t updateHandle(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = SteamRemoteStorage()->CommitPublishedFileUpdate(updateHandle);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// SteamAPICall_t GetPublishedFileDetails(PublishedFileId_t unPublishedFileId, uint32 unMaxSecondsOld);
EXTERN int luasteam_RemoteStorage_GetPublishedFileDetails(lua_State *L) {
	PublishedFileId_t unPublishedFileId(luasteam::checkuint64(L, 1));
	uint32 unMaxSecondsOld = static_cast<uint32>(luaL_checkint(L, 2));
	SteamAPICall_t __ret = SteamRemoteStorage()->GetPublishedFileDetails(unPublishedFileId, unMaxSecondsOld);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// SteamAPICall_t DeletePublishedFile(PublishedFileId_t unPublishedFileId);
EXTERN int luasteam_RemoteStorage_DeletePublishedFile(lua_State *L) {
	PublishedFileId_t unPublishedFileId(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = SteamRemoteStorage()->DeletePublishedFile(unPublishedFileId);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// SteamAPICall_t EnumerateUserPublishedFiles(uint32 unStartIndex);
EXTERN int luasteam_RemoteStorage_EnumerateUserPublishedFiles(lua_State *L) {
	uint32 unStartIndex = static_cast<uint32>(luaL_checkint(L, 1));
	SteamAPICall_t __ret = SteamRemoteStorage()->EnumerateUserPublishedFiles(unStartIndex);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// SteamAPICall_t SubscribePublishedFile(PublishedFileId_t unPublishedFileId);
EXTERN int luasteam_RemoteStorage_SubscribePublishedFile(lua_State *L) {
	PublishedFileId_t unPublishedFileId(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = SteamRemoteStorage()->SubscribePublishedFile(unPublishedFileId);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// SteamAPICall_t EnumerateUserSubscribedFiles(uint32 unStartIndex);
EXTERN int luasteam_RemoteStorage_EnumerateUserSubscribedFiles(lua_State *L) {
	uint32 unStartIndex = static_cast<uint32>(luaL_checkint(L, 1));
	SteamAPICall_t __ret = SteamRemoteStorage()->EnumerateUserSubscribedFiles(unStartIndex);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// SteamAPICall_t UnsubscribePublishedFile(PublishedFileId_t unPublishedFileId);
EXTERN int luasteam_RemoteStorage_UnsubscribePublishedFile(lua_State *L) {
	PublishedFileId_t unPublishedFileId(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = SteamRemoteStorage()->UnsubscribePublishedFile(unPublishedFileId);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// bool UpdatePublishedFileSetChangeDescription(PublishedFileUpdateHandle_t updateHandle, const char * pchChangeDescription);
EXTERN int luasteam_RemoteStorage_UpdatePublishedFileSetChangeDescription(lua_State *L) {
	PublishedFileUpdateHandle_t updateHandle(luasteam::checkuint64(L, 1));
	const char *pchChangeDescription = luaL_checkstring(L, 2);
	bool __ret = SteamRemoteStorage()->UpdatePublishedFileSetChangeDescription(updateHandle, pchChangeDescription);
	lua_pushboolean(L, __ret);
	return 1;
}

// SteamAPICall_t GetPublishedItemVoteDetails(PublishedFileId_t unPublishedFileId);
EXTERN int luasteam_RemoteStorage_GetPublishedItemVoteDetails(lua_State *L) {
	PublishedFileId_t unPublishedFileId(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = SteamRemoteStorage()->GetPublishedItemVoteDetails(unPublishedFileId);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// SteamAPICall_t UpdateUserPublishedItemVote(PublishedFileId_t unPublishedFileId, bool bVoteUp);
EXTERN int luasteam_RemoteStorage_UpdateUserPublishedItemVote(lua_State *L) {
	PublishedFileId_t unPublishedFileId(luasteam::checkuint64(L, 1));
	bool bVoteUp = lua_toboolean(L, 2);
	SteamAPICall_t __ret = SteamRemoteStorage()->UpdateUserPublishedItemVote(unPublishedFileId, bVoteUp);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// SteamAPICall_t GetUserPublishedItemVoteDetails(PublishedFileId_t unPublishedFileId);
EXTERN int luasteam_RemoteStorage_GetUserPublishedItemVoteDetails(lua_State *L) {
	PublishedFileId_t unPublishedFileId(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = SteamRemoteStorage()->GetUserPublishedItemVoteDetails(unPublishedFileId);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// SteamAPICall_t SetUserPublishedFileAction(PublishedFileId_t unPublishedFileId, EWorkshopFileAction eAction);
EXTERN int luasteam_RemoteStorage_SetUserPublishedFileAction(lua_State *L) {
	PublishedFileId_t unPublishedFileId(luasteam::checkuint64(L, 1));
	EWorkshopFileAction eAction = static_cast<EWorkshopFileAction>(luaL_checkint(L, 2));
	SteamAPICall_t __ret = SteamRemoteStorage()->SetUserPublishedFileAction(unPublishedFileId, eAction);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// SteamAPICall_t EnumeratePublishedFilesByUserAction(EWorkshopFileAction eAction, uint32 unStartIndex);
EXTERN int luasteam_RemoteStorage_EnumeratePublishedFilesByUserAction(lua_State *L) {
	EWorkshopFileAction eAction = static_cast<EWorkshopFileAction>(luaL_checkint(L, 1));
	uint32 unStartIndex = static_cast<uint32>(luaL_checkint(L, 2));
	SteamAPICall_t __ret = SteamRemoteStorage()->EnumeratePublishedFilesByUserAction(eAction, unStartIndex);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// SteamAPICall_t UGCDownloadToLocation(UGCHandle_t hContent, const char * pchLocation, uint32 unPriority);
EXTERN int luasteam_RemoteStorage_UGCDownloadToLocation(lua_State *L) {
	UGCHandle_t hContent(luasteam::checkuint64(L, 1));
	const char *pchLocation = luaL_checkstring(L, 2);
	uint32 unPriority = static_cast<uint32>(luaL_checkint(L, 3));
	SteamAPICall_t __ret = SteamRemoteStorage()->UGCDownloadToLocation(hContent, pchLocation, unPriority);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// int32 GetLocalFileChangeCount();
EXTERN int luasteam_RemoteStorage_GetLocalFileChangeCount(lua_State *L) {
	int32 __ret = SteamRemoteStorage()->GetLocalFileChangeCount();
	lua_pushinteger(L, __ret);
	return 1;
}

// const char * GetLocalFileChange(int iFile, ERemoteStorageLocalFileChange * pEChangeType, ERemoteStorageFilePathType * pEFilePathType);
EXTERN int luasteam_RemoteStorage_GetLocalFileChange(lua_State *L) {
	int iFile = static_cast<int>(luaL_checkint(L, 1));
	ERemoteStorageLocalFileChange pEChangeType;
	ERemoteStorageFilePathType pEFilePathType;
	const char * __ret = SteamRemoteStorage()->GetLocalFileChange(iFile, &pEChangeType, &pEFilePathType);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	lua_pushinteger(L, pEChangeType);
	lua_pushinteger(L, pEFilePathType);
	return 3;
}

// bool BeginFileWriteBatch();
EXTERN int luasteam_RemoteStorage_BeginFileWriteBatch(lua_State *L) {
	bool __ret = SteamRemoteStorage()->BeginFileWriteBatch();
	lua_pushboolean(L, __ret);
	return 1;
}

// bool EndFileWriteBatch();
EXTERN int luasteam_RemoteStorage_EndFileWriteBatch(lua_State *L) {
	bool __ret = SteamRemoteStorage()->EndFileWriteBatch();
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
	add_func(L, "CreatePublishedFileUpdateRequest", luasteam_RemoteStorage_CreatePublishedFileUpdateRequest);
	add_func(L, "UpdatePublishedFileFile", luasteam_RemoteStorage_UpdatePublishedFileFile);
	add_func(L, "UpdatePublishedFilePreviewFile", luasteam_RemoteStorage_UpdatePublishedFilePreviewFile);
	add_func(L, "UpdatePublishedFileTitle", luasteam_RemoteStorage_UpdatePublishedFileTitle);
	add_func(L, "UpdatePublishedFileDescription", luasteam_RemoteStorage_UpdatePublishedFileDescription);
	add_func(L, "UpdatePublishedFileVisibility", luasteam_RemoteStorage_UpdatePublishedFileVisibility);
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
	add_func(L, "SetUserPublishedFileAction", luasteam_RemoteStorage_SetUserPublishedFileAction);
	add_func(L, "EnumeratePublishedFilesByUserAction", luasteam_RemoteStorage_EnumeratePublishedFilesByUserAction);
	add_func(L, "UGCDownloadToLocation", luasteam_RemoteStorage_UGCDownloadToLocation);
	add_func(L, "GetLocalFileChangeCount", luasteam_RemoteStorage_GetLocalFileChangeCount);
	add_func(L, "GetLocalFileChange", luasteam_RemoteStorage_GetLocalFileChange);
	add_func(L, "BeginFileWriteBatch", luasteam_RemoteStorage_BeginFileWriteBatch);
	add_func(L, "EndFileWriteBatch", luasteam_RemoteStorage_EndFileWriteBatch);
}

void add_RemoteStorage_auto(lua_State *L) {
	lua_createtable(L, 0, 53);
	register_RemoteStorage_auto(L);
	lua_pushvalue(L, -1);
	RemoteStorage_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "RemoteStorage");
}

} // namespace luasteam
