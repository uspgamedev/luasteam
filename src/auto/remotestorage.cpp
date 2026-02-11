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
    lua_getfield(L, -1, "onRemoteStorageFileShareResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_hFile);
        lua_setfield(L, -2, "file");
        lua_pushstring(L, data->m_rgchFilename);
        lua_setfield(L, -2, "filename");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnRemoteStoragePublishFileResult(RemoteStoragePublishFileResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
    lua_getfield(L, -1, "onRemoteStoragePublishFileResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "publishedFileId");
        lua_pushboolean(L, data->m_bUserNeedsToAcceptWorkshopLegalAgreement);
        lua_setfield(L, -2, "userNeedsToAcceptWorkshopLegalAgreement");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnRemoteStorageDeletePublishedFileResult(RemoteStorageDeletePublishedFileResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
    lua_getfield(L, -1, "onRemoteStorageDeletePublishedFileResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "publishedFileId");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnRemoteStorageEnumerateUserPublishedFilesResult(RemoteStorageEnumerateUserPublishedFilesResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
    lua_getfield(L, -1, "onRemoteStorageEnumerateUserPublishedFilesResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        lua_pushinteger(L, data->m_nResultsReturned);
        lua_setfield(L, -2, "resultsReturned");
        lua_pushinteger(L, data->m_nTotalResultCount);
        lua_setfield(L, -2, "totalResultCount");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnRemoteStorageSubscribePublishedFileResult(RemoteStorageSubscribePublishedFileResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
    lua_getfield(L, -1, "onRemoteStorageSubscribePublishedFileResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "publishedFileId");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnRemoteStorageEnumerateUserSubscribedFilesResult(RemoteStorageEnumerateUserSubscribedFilesResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
    lua_getfield(L, -1, "onRemoteStorageEnumerateUserSubscribedFilesResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 5);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        lua_pushinteger(L, data->m_nResultsReturned);
        lua_setfield(L, -2, "resultsReturned");
        lua_pushinteger(L, data->m_nTotalResultCount);
        lua_setfield(L, -2, "totalResultCount");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnRemoteStorageUnsubscribePublishedFileResult(RemoteStorageUnsubscribePublishedFileResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
    lua_getfield(L, -1, "onRemoteStorageUnsubscribePublishedFileResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "publishedFileId");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnRemoteStorageUpdatePublishedFileResult(RemoteStorageUpdatePublishedFileResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
    lua_getfield(L, -1, "onRemoteStorageUpdatePublishedFileResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "publishedFileId");
        lua_pushboolean(L, data->m_bUserNeedsToAcceptWorkshopLegalAgreement);
        lua_setfield(L, -2, "userNeedsToAcceptWorkshopLegalAgreement");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnRemoteStorageDownloadUGCResult(RemoteStorageDownloadUGCResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
    lua_getfield(L, -1, "onRemoteStorageDownloadUGCResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 6);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_hFile);
        lua_setfield(L, -2, "file");
        lua_pushinteger(L, data->m_nAppID);
        lua_setfield(L, -2, "appID");
        lua_pushinteger(L, data->m_nSizeInBytes);
        lua_setfield(L, -2, "sizeInBytes");
        lua_pushstring(L, data->m_pchFileName);
        lua_setfield(L, -2, "pchFileName");
        luasteam::pushuint64(L, data->m_ulSteamIDOwner);
        lua_setfield(L, -2, "steamIDOwner");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnRemoteStorageGetPublishedFileDetailsResult(RemoteStorageGetPublishedFileDetailsResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
    lua_getfield(L, -1, "onRemoteStorageGetPublishedFileDetailsResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 21);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "publishedFileId");
        lua_pushinteger(L, data->m_nCreatorAppID);
        lua_setfield(L, -2, "creatorAppID");
        lua_pushinteger(L, data->m_nConsumerAppID);
        lua_setfield(L, -2, "consumerAppID");
        lua_pushstring(L, data->m_rgchTitle);
        lua_setfield(L, -2, "title");
        lua_pushstring(L, data->m_rgchDescription);
        lua_setfield(L, -2, "description");
        luasteam::pushuint64(L, data->m_hFile);
        lua_setfield(L, -2, "file");
        luasteam::pushuint64(L, data->m_hPreviewFile);
        lua_setfield(L, -2, "previewFile");
        luasteam::pushuint64(L, data->m_ulSteamIDOwner);
        lua_setfield(L, -2, "steamIDOwner");
        lua_pushinteger(L, data->m_rtimeCreated);
        lua_setfield(L, -2, "rtimeCreated");
        lua_pushinteger(L, data->m_rtimeUpdated);
        lua_setfield(L, -2, "rtimeUpdated");
        lua_pushinteger(L, data->m_eVisibility);
        lua_setfield(L, -2, "visibility");
        lua_pushboolean(L, data->m_bBanned);
        lua_setfield(L, -2, "banned");
        lua_pushstring(L, data->m_rgchTags);
        lua_setfield(L, -2, "tags");
        lua_pushboolean(L, data->m_bTagsTruncated);
        lua_setfield(L, -2, "tagsTruncated");
        lua_pushstring(L, data->m_pchFileName);
        lua_setfield(L, -2, "pchFileName");
        lua_pushinteger(L, data->m_nFileSize);
        lua_setfield(L, -2, "fileSize");
        lua_pushinteger(L, data->m_nPreviewFileSize);
        lua_setfield(L, -2, "previewFileSize");
        lua_pushstring(L, data->m_rgchURL);
        lua_setfield(L, -2, "uRL");
        lua_pushinteger(L, data->m_eFileType);
        lua_setfield(L, -2, "fileType");
        lua_pushboolean(L, data->m_bAcceptedForUse);
        lua_setfield(L, -2, "acceptedForUse");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnRemoteStorageEnumerateWorkshopFilesResult(RemoteStorageEnumerateWorkshopFilesResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
    lua_getfield(L, -1, "onRemoteStorageEnumerateWorkshopFilesResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 7);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        lua_pushinteger(L, data->m_nResultsReturned);
        lua_setfield(L, -2, "resultsReturned");
        lua_pushinteger(L, data->m_nTotalResultCount);
        lua_setfield(L, -2, "totalResultCount");
        lua_pushinteger(L, data->m_nAppId);
        lua_setfield(L, -2, "appId");
        lua_pushinteger(L, data->m_unStartIndex);
        lua_setfield(L, -2, "startIndex");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnRemoteStorageGetPublishedItemVoteDetailsResult(RemoteStorageGetPublishedItemVoteDetailsResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
    lua_getfield(L, -1, "onRemoteStorageGetPublishedItemVoteDetailsResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 6);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_unPublishedFileId);
        lua_setfield(L, -2, "publishedFileId");
        lua_pushinteger(L, data->m_nVotesFor);
        lua_setfield(L, -2, "votesFor");
        lua_pushinteger(L, data->m_nVotesAgainst);
        lua_setfield(L, -2, "votesAgainst");
        lua_pushinteger(L, data->m_nReports);
        lua_setfield(L, -2, "reports");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnRemoteStoragePublishedFileSubscribed(RemoteStoragePublishedFileSubscribed_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
    lua_getfield(L, -1, "onRemoteStoragePublishedFileSubscribed");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "publishedFileId");
        lua_pushinteger(L, data->m_nAppID);
        lua_setfield(L, -2, "appID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnRemoteStoragePublishedFileUnsubscribed(RemoteStoragePublishedFileUnsubscribed_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
    lua_getfield(L, -1, "onRemoteStoragePublishedFileUnsubscribed");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "publishedFileId");
        lua_pushinteger(L, data->m_nAppID);
        lua_setfield(L, -2, "appID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnRemoteStoragePublishedFileDeleted(RemoteStoragePublishedFileDeleted_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
    lua_getfield(L, -1, "onRemoteStoragePublishedFileDeleted");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "publishedFileId");
        lua_pushinteger(L, data->m_nAppID);
        lua_setfield(L, -2, "appID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnRemoteStorageUpdateUserPublishedItemVoteResult(RemoteStorageUpdateUserPublishedItemVoteResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
    lua_getfield(L, -1, "onRemoteStorageUpdateUserPublishedItemVoteResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "publishedFileId");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnRemoteStorageUserVoteDetails(RemoteStorageUserVoteDetails_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
    lua_getfield(L, -1, "onRemoteStorageUserVoteDetails");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "publishedFileId");
        lua_pushinteger(L, data->m_eVote);
        lua_setfield(L, -2, "vote");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnRemoteStorageEnumerateUserSharedWorkshopFilesResult(RemoteStorageEnumerateUserSharedWorkshopFilesResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
    lua_getfield(L, -1, "onRemoteStorageEnumerateUserSharedWorkshopFilesResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        lua_pushinteger(L, data->m_nResultsReturned);
        lua_setfield(L, -2, "resultsReturned");
        lua_pushinteger(L, data->m_nTotalResultCount);
        lua_setfield(L, -2, "totalResultCount");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnRemoteStorageSetUserPublishedFileActionResult(RemoteStorageSetUserPublishedFileActionResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
    lua_getfield(L, -1, "onRemoteStorageSetUserPublishedFileActionResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "publishedFileId");
        lua_pushinteger(L, data->m_eAction);
        lua_setfield(L, -2, "action");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnRemoteStorageEnumeratePublishedFilesByUserActionResult(RemoteStorageEnumeratePublishedFilesByUserActionResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
    lua_getfield(L, -1, "onRemoteStorageEnumeratePublishedFilesByUserActionResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 6);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        lua_pushinteger(L, data->m_eAction);
        lua_setfield(L, -2, "action");
        lua_pushinteger(L, data->m_nResultsReturned);
        lua_setfield(L, -2, "resultsReturned");
        lua_pushinteger(L, data->m_nTotalResultCount);
        lua_setfield(L, -2, "totalResultCount");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnRemoteStoragePublishFileProgress(RemoteStoragePublishFileProgress_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
    lua_getfield(L, -1, "onRemoteStoragePublishFileProgress");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushboolean(L, data->m_bPreview);
        lua_setfield(L, -2, "preview");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnRemoteStoragePublishedFileUpdated(RemoteStoragePublishedFileUpdated_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
    lua_getfield(L, -1, "onRemoteStoragePublishedFileUpdated");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "publishedFileId");
        lua_pushinteger(L, data->m_nAppID);
        lua_setfield(L, -2, "appID");
        luasteam::pushuint64(L, data->m_ulUnused);
        lua_setfield(L, -2, "unused");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnRemoteStorageFileWriteAsyncComplete(RemoteStorageFileWriteAsyncComplete_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
    lua_getfield(L, -1, "onRemoteStorageFileWriteAsyncComplete");
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

void CallbackListener::OnRemoteStorageFileReadAsyncComplete(RemoteStorageFileReadAsyncComplete_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
    lua_getfield(L, -1, "onRemoteStorageFileReadAsyncComplete");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        luasteam::pushuint64(L, data->m_hFileReadAsync);
        lua_setfield(L, -2, "fileReadAsync");
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        lua_pushinteger(L, data->m_nOffset);
        lua_setfield(L, -2, "offset");
        lua_pushinteger(L, data->m_cubRead);
        lua_setfield(L, -2, "cubRead");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnRemoteStorageLocalFileChange(RemoteStorageLocalFileChange_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemoteStorage_ref);
    lua_getfield(L, -1, "onRemoteStorageLocalFileChange");
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


// SteamAPICall_t FileReadAsync(const char * pchFile, uint32 nOffset, uint32 cubToRead);
EXTERN int luasteam_RemoteStorage_FileReadAsync(lua_State *L) {
    const char *pchFile = luaL_checkstring(L, 1);
    uint32 nOffset = static_cast<uint32>(luaL_checkint(L, 2));
    uint32 cubToRead = static_cast<uint32>(luaL_checkint(L, 3));
    luasteam::pushuint64(L, SteamRemoteStorage()->FileReadAsync(pchFile, nOffset, cubToRead));
    return 1;
}

// bool FileForget(const char * pchFile);
EXTERN int luasteam_RemoteStorage_FileForget(lua_State *L) {
    const char *pchFile = luaL_checkstring(L, 1);
    lua_pushboolean(L, SteamRemoteStorage()->FileForget(pchFile));
    return 1;
}

// bool FileDelete(const char * pchFile);
EXTERN int luasteam_RemoteStorage_FileDelete(lua_State *L) {
    const char *pchFile = luaL_checkstring(L, 1);
    lua_pushboolean(L, SteamRemoteStorage()->FileDelete(pchFile));
    return 1;
}

// SteamAPICall_t FileShare(const char * pchFile);
EXTERN int luasteam_RemoteStorage_FileShare(lua_State *L) {
    const char *pchFile = luaL_checkstring(L, 1);
    luasteam::pushuint64(L, SteamRemoteStorage()->FileShare(pchFile));
    return 1;
}

// bool SetSyncPlatforms(const char * pchFile, ERemoteStoragePlatform eRemoteStoragePlatform);
EXTERN int luasteam_RemoteStorage_SetSyncPlatforms(lua_State *L) {
    const char *pchFile = luaL_checkstring(L, 1);
    ERemoteStoragePlatform eRemoteStoragePlatform = static_cast<ERemoteStoragePlatform>(luaL_checkint(L, 2));
    lua_pushboolean(L, SteamRemoteStorage()->SetSyncPlatforms(pchFile, eRemoteStoragePlatform));
    return 1;
}

// UGCFileWriteStreamHandle_t FileWriteStreamOpen(const char * pchFile);
EXTERN int luasteam_RemoteStorage_FileWriteStreamOpen(lua_State *L) {
    const char *pchFile = luaL_checkstring(L, 1);
    luasteam::pushuint64(L, SteamRemoteStorage()->FileWriteStreamOpen(pchFile));
    return 1;
}

// bool FileWriteStreamClose(UGCFileWriteStreamHandle_t writeHandle);
EXTERN int luasteam_RemoteStorage_FileWriteStreamClose(lua_State *L) {
    UGCFileWriteStreamHandle_t writeHandle = luasteam::checkuint64(L, 1);
    lua_pushboolean(L, SteamRemoteStorage()->FileWriteStreamClose(writeHandle));
    return 1;
}

// bool FileWriteStreamCancel(UGCFileWriteStreamHandle_t writeHandle);
EXTERN int luasteam_RemoteStorage_FileWriteStreamCancel(lua_State *L) {
    UGCFileWriteStreamHandle_t writeHandle = luasteam::checkuint64(L, 1);
    lua_pushboolean(L, SteamRemoteStorage()->FileWriteStreamCancel(writeHandle));
    return 1;
}

// bool FileExists(const char * pchFile);
EXTERN int luasteam_RemoteStorage_FileExists(lua_State *L) {
    const char *pchFile = luaL_checkstring(L, 1);
    lua_pushboolean(L, SteamRemoteStorage()->FileExists(pchFile));
    return 1;
}

// bool FilePersisted(const char * pchFile);
EXTERN int luasteam_RemoteStorage_FilePersisted(lua_State *L) {
    const char *pchFile = luaL_checkstring(L, 1);
    lua_pushboolean(L, SteamRemoteStorage()->FilePersisted(pchFile));
    return 1;
}

// int32 GetFileSize(const char * pchFile);
EXTERN int luasteam_RemoteStorage_GetFileSize(lua_State *L) {
    const char *pchFile = luaL_checkstring(L, 1);
    lua_pushinteger(L, SteamRemoteStorage()->GetFileSize(pchFile));
    return 1;
}

// ERemoteStoragePlatform GetSyncPlatforms(const char * pchFile);
EXTERN int luasteam_RemoteStorage_GetSyncPlatforms(lua_State *L) {
    const char *pchFile = luaL_checkstring(L, 1);
    lua_pushinteger(L, SteamRemoteStorage()->GetSyncPlatforms(pchFile));
    return 1;
}

// int32 GetFileCount();
EXTERN int luasteam_RemoteStorage_GetFileCount(lua_State *L) {
    lua_pushinteger(L, SteamRemoteStorage()->GetFileCount());
    return 1;
}

// bool IsCloudEnabledForAccount();
EXTERN int luasteam_RemoteStorage_IsCloudEnabledForAccount(lua_State *L) {
    lua_pushboolean(L, SteamRemoteStorage()->IsCloudEnabledForAccount());
    return 1;
}

// bool IsCloudEnabledForApp();
EXTERN int luasteam_RemoteStorage_IsCloudEnabledForApp(lua_State *L) {
    lua_pushboolean(L, SteamRemoteStorage()->IsCloudEnabledForApp());
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
    UGCHandle_t hContent = luasteam::checkuint64(L, 1);
    uint32 unPriority = static_cast<uint32>(luaL_checkint(L, 2));
    luasteam::pushuint64(L, SteamRemoteStorage()->UGCDownload(hContent, unPriority));
    return 1;
}

// int32 GetCachedUGCCount();
EXTERN int luasteam_RemoteStorage_GetCachedUGCCount(lua_State *L) {
    lua_pushinteger(L, SteamRemoteStorage()->GetCachedUGCCount());
    return 1;
}

// UGCHandle_t GetCachedUGCHandle(int32 iCachedContent);
EXTERN int luasteam_RemoteStorage_GetCachedUGCHandle(lua_State *L) {
    int32 iCachedContent = static_cast<int32>(luaL_checkint(L, 1));
    luasteam::pushuint64(L, SteamRemoteStorage()->GetCachedUGCHandle(iCachedContent));
    return 1;
}

// PublishedFileUpdateHandle_t CreatePublishedFileUpdateRequest(PublishedFileId_t unPublishedFileId);
EXTERN int luasteam_RemoteStorage_CreatePublishedFileUpdateRequest(lua_State *L) {
    PublishedFileId_t unPublishedFileId = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamRemoteStorage()->CreatePublishedFileUpdateRequest(unPublishedFileId));
    return 1;
}

// bool UpdatePublishedFileFile(PublishedFileUpdateHandle_t updateHandle, const char * pchFile);
EXTERN int luasteam_RemoteStorage_UpdatePublishedFileFile(lua_State *L) {
    PublishedFileUpdateHandle_t updateHandle = luasteam::checkuint64(L, 1);
    const char *pchFile = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamRemoteStorage()->UpdatePublishedFileFile(updateHandle, pchFile));
    return 1;
}

// bool UpdatePublishedFilePreviewFile(PublishedFileUpdateHandle_t updateHandle, const char * pchPreviewFile);
EXTERN int luasteam_RemoteStorage_UpdatePublishedFilePreviewFile(lua_State *L) {
    PublishedFileUpdateHandle_t updateHandle = luasteam::checkuint64(L, 1);
    const char *pchPreviewFile = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamRemoteStorage()->UpdatePublishedFilePreviewFile(updateHandle, pchPreviewFile));
    return 1;
}

// bool UpdatePublishedFileTitle(PublishedFileUpdateHandle_t updateHandle, const char * pchTitle);
EXTERN int luasteam_RemoteStorage_UpdatePublishedFileTitle(lua_State *L) {
    PublishedFileUpdateHandle_t updateHandle = luasteam::checkuint64(L, 1);
    const char *pchTitle = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamRemoteStorage()->UpdatePublishedFileTitle(updateHandle, pchTitle));
    return 1;
}

// bool UpdatePublishedFileDescription(PublishedFileUpdateHandle_t updateHandle, const char * pchDescription);
EXTERN int luasteam_RemoteStorage_UpdatePublishedFileDescription(lua_State *L) {
    PublishedFileUpdateHandle_t updateHandle = luasteam::checkuint64(L, 1);
    const char *pchDescription = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamRemoteStorage()->UpdatePublishedFileDescription(updateHandle, pchDescription));
    return 1;
}

// bool UpdatePublishedFileVisibility(PublishedFileUpdateHandle_t updateHandle, ERemoteStoragePublishedFileVisibility eVisibility);
EXTERN int luasteam_RemoteStorage_UpdatePublishedFileVisibility(lua_State *L) {
    PublishedFileUpdateHandle_t updateHandle = luasteam::checkuint64(L, 1);
    ERemoteStoragePublishedFileVisibility eVisibility = static_cast<ERemoteStoragePublishedFileVisibility>(luaL_checkint(L, 2));
    lua_pushboolean(L, SteamRemoteStorage()->UpdatePublishedFileVisibility(updateHandle, eVisibility));
    return 1;
}

// SteamAPICall_t CommitPublishedFileUpdate(PublishedFileUpdateHandle_t updateHandle);
EXTERN int luasteam_RemoteStorage_CommitPublishedFileUpdate(lua_State *L) {
    PublishedFileUpdateHandle_t updateHandle = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamRemoteStorage()->CommitPublishedFileUpdate(updateHandle));
    return 1;
}

// SteamAPICall_t GetPublishedFileDetails(PublishedFileId_t unPublishedFileId, uint32 unMaxSecondsOld);
EXTERN int luasteam_RemoteStorage_GetPublishedFileDetails(lua_State *L) {
    PublishedFileId_t unPublishedFileId = luasteam::checkuint64(L, 1);
    uint32 unMaxSecondsOld = static_cast<uint32>(luaL_checkint(L, 2));
    luasteam::pushuint64(L, SteamRemoteStorage()->GetPublishedFileDetails(unPublishedFileId, unMaxSecondsOld));
    return 1;
}

// SteamAPICall_t DeletePublishedFile(PublishedFileId_t unPublishedFileId);
EXTERN int luasteam_RemoteStorage_DeletePublishedFile(lua_State *L) {
    PublishedFileId_t unPublishedFileId = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamRemoteStorage()->DeletePublishedFile(unPublishedFileId));
    return 1;
}

// SteamAPICall_t EnumerateUserPublishedFiles(uint32 unStartIndex);
EXTERN int luasteam_RemoteStorage_EnumerateUserPublishedFiles(lua_State *L) {
    uint32 unStartIndex = static_cast<uint32>(luaL_checkint(L, 1));
    luasteam::pushuint64(L, SteamRemoteStorage()->EnumerateUserPublishedFiles(unStartIndex));
    return 1;
}

// SteamAPICall_t SubscribePublishedFile(PublishedFileId_t unPublishedFileId);
EXTERN int luasteam_RemoteStorage_SubscribePublishedFile(lua_State *L) {
    PublishedFileId_t unPublishedFileId = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamRemoteStorage()->SubscribePublishedFile(unPublishedFileId));
    return 1;
}

// SteamAPICall_t EnumerateUserSubscribedFiles(uint32 unStartIndex);
EXTERN int luasteam_RemoteStorage_EnumerateUserSubscribedFiles(lua_State *L) {
    uint32 unStartIndex = static_cast<uint32>(luaL_checkint(L, 1));
    luasteam::pushuint64(L, SteamRemoteStorage()->EnumerateUserSubscribedFiles(unStartIndex));
    return 1;
}

// SteamAPICall_t UnsubscribePublishedFile(PublishedFileId_t unPublishedFileId);
EXTERN int luasteam_RemoteStorage_UnsubscribePublishedFile(lua_State *L) {
    PublishedFileId_t unPublishedFileId = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamRemoteStorage()->UnsubscribePublishedFile(unPublishedFileId));
    return 1;
}

// bool UpdatePublishedFileSetChangeDescription(PublishedFileUpdateHandle_t updateHandle, const char * pchChangeDescription);
EXTERN int luasteam_RemoteStorage_UpdatePublishedFileSetChangeDescription(lua_State *L) {
    PublishedFileUpdateHandle_t updateHandle = luasteam::checkuint64(L, 1);
    const char *pchChangeDescription = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamRemoteStorage()->UpdatePublishedFileSetChangeDescription(updateHandle, pchChangeDescription));
    return 1;
}

// SteamAPICall_t GetPublishedItemVoteDetails(PublishedFileId_t unPublishedFileId);
EXTERN int luasteam_RemoteStorage_GetPublishedItemVoteDetails(lua_State *L) {
    PublishedFileId_t unPublishedFileId = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamRemoteStorage()->GetPublishedItemVoteDetails(unPublishedFileId));
    return 1;
}

// SteamAPICall_t UpdateUserPublishedItemVote(PublishedFileId_t unPublishedFileId, bool bVoteUp);
EXTERN int luasteam_RemoteStorage_UpdateUserPublishedItemVote(lua_State *L) {
    PublishedFileId_t unPublishedFileId = luasteam::checkuint64(L, 1);
    bool bVoteUp = lua_toboolean(L, 2);
    luasteam::pushuint64(L, SteamRemoteStorage()->UpdateUserPublishedItemVote(unPublishedFileId, bVoteUp));
    return 1;
}

// SteamAPICall_t GetUserPublishedItemVoteDetails(PublishedFileId_t unPublishedFileId);
EXTERN int luasteam_RemoteStorage_GetUserPublishedItemVoteDetails(lua_State *L) {
    PublishedFileId_t unPublishedFileId = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamRemoteStorage()->GetUserPublishedItemVoteDetails(unPublishedFileId));
    return 1;
}

// SteamAPICall_t SetUserPublishedFileAction(PublishedFileId_t unPublishedFileId, EWorkshopFileAction eAction);
EXTERN int luasteam_RemoteStorage_SetUserPublishedFileAction(lua_State *L) {
    PublishedFileId_t unPublishedFileId = luasteam::checkuint64(L, 1);
    EWorkshopFileAction eAction = static_cast<EWorkshopFileAction>(luaL_checkint(L, 2));
    luasteam::pushuint64(L, SteamRemoteStorage()->SetUserPublishedFileAction(unPublishedFileId, eAction));
    return 1;
}

// SteamAPICall_t EnumeratePublishedFilesByUserAction(EWorkshopFileAction eAction, uint32 unStartIndex);
EXTERN int luasteam_RemoteStorage_EnumeratePublishedFilesByUserAction(lua_State *L) {
    EWorkshopFileAction eAction = static_cast<EWorkshopFileAction>(luaL_checkint(L, 1));
    uint32 unStartIndex = static_cast<uint32>(luaL_checkint(L, 2));
    luasteam::pushuint64(L, SteamRemoteStorage()->EnumeratePublishedFilesByUserAction(eAction, unStartIndex));
    return 1;
}

// SteamAPICall_t UGCDownloadToLocation(UGCHandle_t hContent, const char * pchLocation, uint32 unPriority);
EXTERN int luasteam_RemoteStorage_UGCDownloadToLocation(lua_State *L) {
    UGCHandle_t hContent = luasteam::checkuint64(L, 1);
    const char *pchLocation = luaL_checkstring(L, 2);
    uint32 unPriority = static_cast<uint32>(luaL_checkint(L, 3));
    luasteam::pushuint64(L, SteamRemoteStorage()->UGCDownloadToLocation(hContent, pchLocation, unPriority));
    return 1;
}

// int32 GetLocalFileChangeCount();
EXTERN int luasteam_RemoteStorage_GetLocalFileChangeCount(lua_State *L) {
    lua_pushinteger(L, SteamRemoteStorage()->GetLocalFileChangeCount());
    return 1;
}

// bool BeginFileWriteBatch();
EXTERN int luasteam_RemoteStorage_BeginFileWriteBatch(lua_State *L) {
    lua_pushboolean(L, SteamRemoteStorage()->BeginFileWriteBatch());
    return 1;
}

// bool EndFileWriteBatch();
EXTERN int luasteam_RemoteStorage_EndFileWriteBatch(lua_State *L) {
    lua_pushboolean(L, SteamRemoteStorage()->EndFileWriteBatch());
    return 1;
}

void register_RemoteStorage_auto(lua_State *L) {
    add_func(L, "FileReadAsync", luasteam_RemoteStorage_FileReadAsync);
    add_func(L, "FileForget", luasteam_RemoteStorage_FileForget);
    add_func(L, "FileDelete", luasteam_RemoteStorage_FileDelete);
    add_func(L, "FileShare", luasteam_RemoteStorage_FileShare);
    add_func(L, "SetSyncPlatforms", luasteam_RemoteStorage_SetSyncPlatforms);
    add_func(L, "FileWriteStreamOpen", luasteam_RemoteStorage_FileWriteStreamOpen);
    add_func(L, "FileWriteStreamClose", luasteam_RemoteStorage_FileWriteStreamClose);
    add_func(L, "FileWriteStreamCancel", luasteam_RemoteStorage_FileWriteStreamCancel);
    add_func(L, "FileExists", luasteam_RemoteStorage_FileExists);
    add_func(L, "FilePersisted", luasteam_RemoteStorage_FilePersisted);
    add_func(L, "GetFileSize", luasteam_RemoteStorage_GetFileSize);
    add_func(L, "GetSyncPlatforms", luasteam_RemoteStorage_GetSyncPlatforms);
    add_func(L, "GetFileCount", luasteam_RemoteStorage_GetFileCount);
    add_func(L, "IsCloudEnabledForAccount", luasteam_RemoteStorage_IsCloudEnabledForAccount);
    add_func(L, "IsCloudEnabledForApp", luasteam_RemoteStorage_IsCloudEnabledForApp);
    add_func(L, "SetCloudEnabledForApp", luasteam_RemoteStorage_SetCloudEnabledForApp);
    add_func(L, "UGCDownload", luasteam_RemoteStorage_UGCDownload);
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
    add_func(L, "BeginFileWriteBatch", luasteam_RemoteStorage_BeginFileWriteBatch);
    add_func(L, "EndFileWriteBatch", luasteam_RemoteStorage_EndFileWriteBatch);
}

void add_RemoteStorage_auto(lua_State *L) {
    lua_createtable(L, 0, 42);
    register_RemoteStorage_auto(L);
    lua_pushvalue(L, -1);
    RemoteStorage_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "RemoteStorage");
}

} // namespace luasteam
