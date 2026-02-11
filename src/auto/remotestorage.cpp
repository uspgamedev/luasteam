#include "auto.hpp"

// SteamAPICall_t FileReadAsync(const char * pchFile, uint32 nOffset, uint32 cubToRead);
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_FileReadAsync(lua_State *L) {
    const char *pchFile = luaL_checkstring(L, 1);
    uint32 nOffset = luaL_checkint(L, 2);
    uint32 cubToRead = luaL_checkint(L, 3);
    luasteam::pushuint64(L, SteamRemoteStorage()->FileReadAsync(pchFile, nOffset, cubToRead));
    return 1;
}

// bool FileForget(const char * pchFile);
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_FileForget(lua_State *L) {
    const char *pchFile = luaL_checkstring(L, 1);
    lua_pushboolean(L, SteamRemoteStorage()->FileForget(pchFile));
    return 1;
}

// bool FileDelete(const char * pchFile);
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_FileDelete(lua_State *L) {
    const char *pchFile = luaL_checkstring(L, 1);
    lua_pushboolean(L, SteamRemoteStorage()->FileDelete(pchFile));
    return 1;
}

// SteamAPICall_t FileShare(const char * pchFile);
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_FileShare(lua_State *L) {
    const char *pchFile = luaL_checkstring(L, 1);
    luasteam::pushuint64(L, SteamRemoteStorage()->FileShare(pchFile));
    return 1;
}

// UGCFileWriteStreamHandle_t FileWriteStreamOpen(const char * pchFile);
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_FileWriteStreamOpen(lua_State *L) {
    const char *pchFile = luaL_checkstring(L, 1);
    luasteam::pushuint64(L, SteamRemoteStorage()->FileWriteStreamOpen(pchFile));
    return 1;
}

// bool FileWriteStreamClose(UGCFileWriteStreamHandle_t writeHandle);
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_FileWriteStreamClose(lua_State *L) {
    UGCFileWriteStreamHandle_t writeHandle = luasteam::checkuint64(L, 1);
    lua_pushboolean(L, SteamRemoteStorage()->FileWriteStreamClose(writeHandle));
    return 1;
}

// bool FileWriteStreamCancel(UGCFileWriteStreamHandle_t writeHandle);
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_FileWriteStreamCancel(lua_State *L) {
    UGCFileWriteStreamHandle_t writeHandle = luasteam::checkuint64(L, 1);
    lua_pushboolean(L, SteamRemoteStorage()->FileWriteStreamCancel(writeHandle));
    return 1;
}

// bool FileExists(const char * pchFile);
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_FileExists(lua_State *L) {
    const char *pchFile = luaL_checkstring(L, 1);
    lua_pushboolean(L, SteamRemoteStorage()->FileExists(pchFile));
    return 1;
}

// bool FilePersisted(const char * pchFile);
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_FilePersisted(lua_State *L) {
    const char *pchFile = luaL_checkstring(L, 1);
    lua_pushboolean(L, SteamRemoteStorage()->FilePersisted(pchFile));
    return 1;
}

// int32 GetFileSize(const char * pchFile);
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_GetFileSize(lua_State *L) {
    const char *pchFile = luaL_checkstring(L, 1);
    lua_pushinteger(L, SteamRemoteStorage()->GetFileSize(pchFile));
    return 1;
}

// int32 GetFileCount();
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_GetFileCount(lua_State *L) {
    lua_pushinteger(L, SteamRemoteStorage()->GetFileCount());
    return 1;
}

// bool IsCloudEnabledForAccount();
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_IsCloudEnabledForAccount(lua_State *L) {
    lua_pushboolean(L, SteamRemoteStorage()->IsCloudEnabledForAccount());
    return 1;
}

// bool IsCloudEnabledForApp();
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_IsCloudEnabledForApp(lua_State *L) {
    lua_pushboolean(L, SteamRemoteStorage()->IsCloudEnabledForApp());
    return 1;
}

// void SetCloudEnabledForApp(bool bEnabled);
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_SetCloudEnabledForApp(lua_State *L) {
    bool bEnabled = lua_toboolean(L, 1);
    SteamRemoteStorage()->SetCloudEnabledForApp(bEnabled);
    return 0;
}

// SteamAPICall_t UGCDownload(UGCHandle_t hContent, uint32 unPriority);
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_UGCDownload(lua_State *L) {
    UGCHandle_t hContent = luasteam::checkuint64(L, 1);
    uint32 unPriority = luaL_checkint(L, 2);
    luasteam::pushuint64(L, SteamRemoteStorage()->UGCDownload(hContent, unPriority));
    return 1;
}

// int32 GetCachedUGCCount();
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_GetCachedUGCCount(lua_State *L) {
    lua_pushinteger(L, SteamRemoteStorage()->GetCachedUGCCount());
    return 1;
}

// UGCHandle_t GetCachedUGCHandle(int32 iCachedContent);
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_GetCachedUGCHandle(lua_State *L) {
    int32 iCachedContent = luaL_checkint(L, 1);
    luasteam::pushuint64(L, SteamRemoteStorage()->GetCachedUGCHandle(iCachedContent));
    return 1;
}

// PublishedFileUpdateHandle_t CreatePublishedFileUpdateRequest(PublishedFileId_t unPublishedFileId);
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_CreatePublishedFileUpdateRequest(lua_State *L) {
    PublishedFileId_t unPublishedFileId = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamRemoteStorage()->CreatePublishedFileUpdateRequest(unPublishedFileId));
    return 1;
}

// bool UpdatePublishedFileFile(PublishedFileUpdateHandle_t updateHandle, const char * pchFile);
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileFile(lua_State *L) {
    PublishedFileUpdateHandle_t updateHandle = luasteam::checkuint64(L, 1);
    const char *pchFile = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamRemoteStorage()->UpdatePublishedFileFile(updateHandle, pchFile));
    return 1;
}

// bool UpdatePublishedFilePreviewFile(PublishedFileUpdateHandle_t updateHandle, const char * pchPreviewFile);
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_UpdatePublishedFilePreviewFile(lua_State *L) {
    PublishedFileUpdateHandle_t updateHandle = luasteam::checkuint64(L, 1);
    const char *pchPreviewFile = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamRemoteStorage()->UpdatePublishedFilePreviewFile(updateHandle, pchPreviewFile));
    return 1;
}

// bool UpdatePublishedFileTitle(PublishedFileUpdateHandle_t updateHandle, const char * pchTitle);
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTitle(lua_State *L) {
    PublishedFileUpdateHandle_t updateHandle = luasteam::checkuint64(L, 1);
    const char *pchTitle = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamRemoteStorage()->UpdatePublishedFileTitle(updateHandle, pchTitle));
    return 1;
}

// bool UpdatePublishedFileDescription(PublishedFileUpdateHandle_t updateHandle, const char * pchDescription);
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileDescription(lua_State *L) {
    PublishedFileUpdateHandle_t updateHandle = luasteam::checkuint64(L, 1);
    const char *pchDescription = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamRemoteStorage()->UpdatePublishedFileDescription(updateHandle, pchDescription));
    return 1;
}

// SteamAPICall_t CommitPublishedFileUpdate(PublishedFileUpdateHandle_t updateHandle);
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_CommitPublishedFileUpdate(lua_State *L) {
    PublishedFileUpdateHandle_t updateHandle = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamRemoteStorage()->CommitPublishedFileUpdate(updateHandle));
    return 1;
}

// SteamAPICall_t GetPublishedFileDetails(PublishedFileId_t unPublishedFileId, uint32 unMaxSecondsOld);
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_GetPublishedFileDetails(lua_State *L) {
    PublishedFileId_t unPublishedFileId = luasteam::checkuint64(L, 1);
    uint32 unMaxSecondsOld = luaL_checkint(L, 2);
    luasteam::pushuint64(L, SteamRemoteStorage()->GetPublishedFileDetails(unPublishedFileId, unMaxSecondsOld));
    return 1;
}

// SteamAPICall_t DeletePublishedFile(PublishedFileId_t unPublishedFileId);
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_DeletePublishedFile(lua_State *L) {
    PublishedFileId_t unPublishedFileId = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamRemoteStorage()->DeletePublishedFile(unPublishedFileId));
    return 1;
}

// SteamAPICall_t EnumerateUserPublishedFiles(uint32 unStartIndex);
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_EnumerateUserPublishedFiles(lua_State *L) {
    uint32 unStartIndex = luaL_checkint(L, 1);
    luasteam::pushuint64(L, SteamRemoteStorage()->EnumerateUserPublishedFiles(unStartIndex));
    return 1;
}

// SteamAPICall_t SubscribePublishedFile(PublishedFileId_t unPublishedFileId);
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_SubscribePublishedFile(lua_State *L) {
    PublishedFileId_t unPublishedFileId = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamRemoteStorage()->SubscribePublishedFile(unPublishedFileId));
    return 1;
}

// SteamAPICall_t EnumerateUserSubscribedFiles(uint32 unStartIndex);
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_EnumerateUserSubscribedFiles(lua_State *L) {
    uint32 unStartIndex = luaL_checkint(L, 1);
    luasteam::pushuint64(L, SteamRemoteStorage()->EnumerateUserSubscribedFiles(unStartIndex));
    return 1;
}

// SteamAPICall_t UnsubscribePublishedFile(PublishedFileId_t unPublishedFileId);
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_UnsubscribePublishedFile(lua_State *L) {
    PublishedFileId_t unPublishedFileId = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamRemoteStorage()->UnsubscribePublishedFile(unPublishedFileId));
    return 1;
}

// bool UpdatePublishedFileSetChangeDescription(PublishedFileUpdateHandle_t updateHandle, const char * pchChangeDescription);
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileSetChangeDescription(lua_State *L) {
    PublishedFileUpdateHandle_t updateHandle = luasteam::checkuint64(L, 1);
    const char *pchChangeDescription = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamRemoteStorage()->UpdatePublishedFileSetChangeDescription(updateHandle, pchChangeDescription));
    return 1;
}

// SteamAPICall_t GetPublishedItemVoteDetails(PublishedFileId_t unPublishedFileId);
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_GetPublishedItemVoteDetails(lua_State *L) {
    PublishedFileId_t unPublishedFileId = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamRemoteStorage()->GetPublishedItemVoteDetails(unPublishedFileId));
    return 1;
}

// SteamAPICall_t UpdateUserPublishedItemVote(PublishedFileId_t unPublishedFileId, bool bVoteUp);
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_UpdateUserPublishedItemVote(lua_State *L) {
    PublishedFileId_t unPublishedFileId = luasteam::checkuint64(L, 1);
    bool bVoteUp = lua_toboolean(L, 2);
    luasteam::pushuint64(L, SteamRemoteStorage()->UpdateUserPublishedItemVote(unPublishedFileId, bVoteUp));
    return 1;
}

// SteamAPICall_t GetUserPublishedItemVoteDetails(PublishedFileId_t unPublishedFileId);
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_GetUserPublishedItemVoteDetails(lua_State *L) {
    PublishedFileId_t unPublishedFileId = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamRemoteStorage()->GetUserPublishedItemVoteDetails(unPublishedFileId));
    return 1;
}

// SteamAPICall_t UGCDownloadToLocation(UGCHandle_t hContent, const char * pchLocation, uint32 unPriority);
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_UGCDownloadToLocation(lua_State *L) {
    UGCHandle_t hContent = luasteam::checkuint64(L, 1);
    const char *pchLocation = luaL_checkstring(L, 2);
    uint32 unPriority = luaL_checkint(L, 3);
    luasteam::pushuint64(L, SteamRemoteStorage()->UGCDownloadToLocation(hContent, pchLocation, unPriority));
    return 1;
}

// int32 GetLocalFileChangeCount();
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_GetLocalFileChangeCount(lua_State *L) {
    lua_pushinteger(L, SteamRemoteStorage()->GetLocalFileChangeCount());
    return 1;
}

// bool BeginFileWriteBatch();
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_BeginFileWriteBatch(lua_State *L) {
    lua_pushboolean(L, SteamRemoteStorage()->BeginFileWriteBatch());
    return 1;
}

// bool EndFileWriteBatch();
EXTERN int luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_EndFileWriteBatch(lua_State *L) {
    lua_pushboolean(L, SteamRemoteStorage()->EndFileWriteBatch());
    return 1;
}

namespace luasteam {

void add_remotestorage_auto(lua_State *L) {
    add_func(L, "fileReadAsync", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_FileReadAsync);
    add_func(L, "fileForget", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_FileForget);
    add_func(L, "fileDelete", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_FileDelete);
    add_func(L, "fileShare", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_FileShare);
    add_func(L, "fileWriteStreamOpen", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_FileWriteStreamOpen);
    add_func(L, "fileWriteStreamClose", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_FileWriteStreamClose);
    add_func(L, "fileWriteStreamCancel", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_FileWriteStreamCancel);
    add_func(L, "fileExists", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_FileExists);
    add_func(L, "filePersisted", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_FilePersisted);
    add_func(L, "getFileSize", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_GetFileSize);
    add_func(L, "getFileCount", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_GetFileCount);
    add_func(L, "isCloudEnabledForAccount", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_IsCloudEnabledForAccount);
    add_func(L, "isCloudEnabledForApp", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_IsCloudEnabledForApp);
    add_func(L, "setCloudEnabledForApp", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_SetCloudEnabledForApp);
    add_func(L, "uGCDownload", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_UGCDownload);
    add_func(L, "getCachedUGCCount", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_GetCachedUGCCount);
    add_func(L, "getCachedUGCHandle", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_GetCachedUGCHandle);
    add_func(L, "createPublishedFileUpdateRequest", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_CreatePublishedFileUpdateRequest);
    add_func(L, "updatePublishedFileFile", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileFile);
    add_func(L, "updatePublishedFilePreviewFile", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_UpdatePublishedFilePreviewFile);
    add_func(L, "updatePublishedFileTitle", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileTitle);
    add_func(L, "updatePublishedFileDescription", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileDescription);
    add_func(L, "commitPublishedFileUpdate", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_CommitPublishedFileUpdate);
    add_func(L, "getPublishedFileDetails", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_GetPublishedFileDetails);
    add_func(L, "deletePublishedFile", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_DeletePublishedFile);
    add_func(L, "enumerateUserPublishedFiles", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_EnumerateUserPublishedFiles);
    add_func(L, "subscribePublishedFile", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_SubscribePublishedFile);
    add_func(L, "enumerateUserSubscribedFiles", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_EnumerateUserSubscribedFiles);
    add_func(L, "unsubscribePublishedFile", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_UnsubscribePublishedFile);
    add_func(L, "updatePublishedFileSetChangeDescription", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_UpdatePublishedFileSetChangeDescription);
    add_func(L, "getPublishedItemVoteDetails", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_GetPublishedItemVoteDetails);
    add_func(L, "updateUserPublishedItemVote", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_UpdateUserPublishedItemVote);
    add_func(L, "getUserPublishedItemVoteDetails", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_GetUserPublishedItemVoteDetails);
    add_func(L, "uGCDownloadToLocation", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_UGCDownloadToLocation);
    add_func(L, "getLocalFileChangeCount", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_GetLocalFileChangeCount);
    add_func(L, "beginFileWriteBatch", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_BeginFileWriteBatch);
    add_func(L, "endFileWriteBatch", luasteam_remotestorage_SteamAPI_ISteamRemoteStorage_EndFileWriteBatch);
}

} // namespace luasteam
