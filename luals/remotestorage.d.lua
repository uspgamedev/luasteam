---@class Steam.RemoteStorage
local RemoteStorage = {}

---@param pchFile string
---@param pvData table
---@param cubData integer
---@return boolean
function RemoteStorage.FileWrite(pchFile, pvData, cubData) end

---@param pchFile string
---@param cubDataToRead integer
---@return integer
---@return table
function RemoteStorage.FileRead(pchFile, cubDataToRead) end

---@param pchFile string
---@param pvData table
---@param cubData integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function RemoteStorage.FileWriteAsync(pchFile, pvData, cubData, callback) end

---@param pchFile string
---@param nOffset integer
---@param cubToRead integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function RemoteStorage.FileReadAsync(pchFile, nOffset, cubToRead, callback) end

---@param hReadCall SteamAPICall_t
---@param cubToRead integer
---@return boolean
---@return table
function RemoteStorage.FileReadAsyncComplete(hReadCall, cubToRead) end

---@param pchFile string
---@return boolean
function RemoteStorage.FileForget(pchFile) end

---@param pchFile string
---@return boolean
function RemoteStorage.FileDelete(pchFile) end

---@param pchFile string
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function RemoteStorage.FileShare(pchFile, callback) end

---@param pchFile string
---@param eRemoteStoragePlatform integer
---@return boolean
function RemoteStorage.SetSyncPlatforms(pchFile, eRemoteStoragePlatform) end

---@param pchFile string
---@return table
function RemoteStorage.FileWriteStreamOpen(pchFile) end

---@param writeHandle table
---@param pvData table
---@param cubData integer
---@return boolean
function RemoteStorage.FileWriteStreamWriteChunk(writeHandle, pvData, cubData) end

---@param writeHandle table
---@return boolean
function RemoteStorage.FileWriteStreamClose(writeHandle) end

---@param writeHandle table
---@return boolean
function RemoteStorage.FileWriteStreamCancel(writeHandle) end

---@param pchFile string
---@return boolean
function RemoteStorage.FileExists(pchFile) end

---@param pchFile string
---@return boolean
function RemoteStorage.FilePersisted(pchFile) end

---@param pchFile string
---@return integer
function RemoteStorage.GetFileSize(pchFile) end

---@param pchFile string
---@return table
function RemoteStorage.GetFileTimestamp(pchFile) end

---@param pchFile string
---@return integer
function RemoteStorage.GetSyncPlatforms(pchFile) end

---@return integer
function RemoteStorage.GetFileCount() end

---@param iFile integer
---@return string
---@return integer
function RemoteStorage.GetFileNameAndSize(iFile) end

---@return boolean
---@return table
---@return table
function RemoteStorage.GetQuota() end

---@return boolean
function RemoteStorage.IsCloudEnabledForAccount() end

---@return boolean
function RemoteStorage.IsCloudEnabledForApp() end

---@param bEnabled boolean
function RemoteStorage.SetCloudEnabledForApp(bEnabled) end

---@param hContent table
---@param unPriority integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function RemoteStorage.UGCDownload(hContent, unPriority, callback) end

---@param hContent table
---@return boolean
---@return integer
---@return integer
function RemoteStorage.GetUGCDownloadProgress(hContent) end

---@param hContent table
---@param cubDataToRead integer
---@param cOffset integer
---@param eAction integer
---@return integer
---@return table
function RemoteStorage.UGCRead(hContent, cubDataToRead, cOffset, eAction) end

---@return integer
function RemoteStorage.GetCachedUGCCount() end

---@param iCachedContent integer
---@return table
function RemoteStorage.GetCachedUGCHandle(iCachedContent) end

---@param unPublishedFileId table
---@return table
function RemoteStorage.CreatePublishedFileUpdateRequest(unPublishedFileId) end

---@param updateHandle table
---@param pchFile string
---@return boolean
function RemoteStorage.UpdatePublishedFileFile(updateHandle, pchFile) end

---@param updateHandle table
---@param pchPreviewFile string
---@return boolean
function RemoteStorage.UpdatePublishedFilePreviewFile(updateHandle, pchPreviewFile) end

---@param updateHandle table
---@param pchTitle string
---@return boolean
function RemoteStorage.UpdatePublishedFileTitle(updateHandle, pchTitle) end

---@param updateHandle table
---@param pchDescription string
---@return boolean
function RemoteStorage.UpdatePublishedFileDescription(updateHandle, pchDescription) end

---@param updateHandle table
---@param eVisibility integer
---@return boolean
function RemoteStorage.UpdatePublishedFileVisibility(updateHandle, eVisibility) end

---@param updateHandle table
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function RemoteStorage.CommitPublishedFileUpdate(updateHandle, callback) end

---@param unPublishedFileId table
---@param unMaxSecondsOld integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function RemoteStorage.GetPublishedFileDetails(unPublishedFileId, unMaxSecondsOld, callback) end

---@param unPublishedFileId table
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function RemoteStorage.DeletePublishedFile(unPublishedFileId, callback) end

---@param unStartIndex integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function RemoteStorage.EnumerateUserPublishedFiles(unStartIndex, callback) end

---@param unPublishedFileId table
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function RemoteStorage.SubscribePublishedFile(unPublishedFileId, callback) end

---@param unStartIndex integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function RemoteStorage.EnumerateUserSubscribedFiles(unStartIndex, callback) end

---@param unPublishedFileId table
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function RemoteStorage.UnsubscribePublishedFile(unPublishedFileId, callback) end

---@param updateHandle table
---@param pchChangeDescription string
---@return boolean
function RemoteStorage.UpdatePublishedFileSetChangeDescription(updateHandle, pchChangeDescription) end

---@param unPublishedFileId table
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function RemoteStorage.GetPublishedItemVoteDetails(unPublishedFileId, callback) end

---@param unPublishedFileId table
---@param bVoteUp boolean
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function RemoteStorage.UpdateUserPublishedItemVote(unPublishedFileId, bVoteUp, callback) end

---@param unPublishedFileId table
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function RemoteStorage.GetUserPublishedItemVoteDetails(unPublishedFileId, callback) end

---@param unPublishedFileId table
---@param eAction integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function RemoteStorage.SetUserPublishedFileAction(unPublishedFileId, eAction, callback) end

---@param eAction integer
---@param unStartIndex integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function RemoteStorage.EnumeratePublishedFilesByUserAction(eAction, unStartIndex, callback) end

---@param hContent table
---@param pchLocation string
---@param unPriority integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function RemoteStorage.UGCDownloadToLocation(hContent, pchLocation, unPriority, callback) end

---@return integer
function RemoteStorage.GetLocalFileChangeCount() end

---@param iFile integer
---@return string
---@return integer
---@return integer
function RemoteStorage.GetLocalFileChange(iFile) end

---@return boolean
function RemoteStorage.BeginFileWriteBatch() end

---@return boolean
function RemoteStorage.EndFileWriteBatch() end

Steam.RemoteStorage = RemoteStorage
