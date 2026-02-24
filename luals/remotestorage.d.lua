---@class Steam.RemoteStorage
local RemoteStorage = {}

---@param pchFile string
---@param pvData string
---@param cubData integer
---@return boolean
function RemoteStorage.FileWrite(pchFile, pvData, cubData) end

---@param pchFile string
---@param cubDataToRead integer
---@return integer
---@return string -- Value of: pvData
function RemoteStorage.FileRead(pchFile, cubDataToRead) end

---@param pchFile string
---@param pvData string
---@param cubData integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function RemoteStorage.FileWriteAsync(pchFile, pvData, cubData, callback) end

---@param pchFile string
---@param nOffset integer
---@param cubToRead integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function RemoteStorage.FileReadAsync(pchFile, nOffset, cubToRead, callback) end

---@param hReadCall uint64
---@param cubToRead integer
---@return boolean
---@return string -- Value of: pvBuffer
function RemoteStorage.FileReadAsyncComplete(hReadCall, cubToRead) end

---@param pchFile string
---@return boolean
function RemoteStorage.FileForget(pchFile) end

---@param pchFile string
---@return boolean
function RemoteStorage.FileDelete(pchFile) end

---@param pchFile string
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function RemoteStorage.FileShare(pchFile, callback) end

---@param pchFile string
---@param eRemoteStoragePlatform integer
---@return boolean
function RemoteStorage.SetSyncPlatforms(pchFile, eRemoteStoragePlatform) end

---@param pchFile string
---@return uint64
function RemoteStorage.FileWriteStreamOpen(pchFile) end

---@param writeHandle uint64
---@param pvData string
---@param cubData integer
---@return boolean
function RemoteStorage.FileWriteStreamWriteChunk(writeHandle, pvData, cubData) end

---@param writeHandle uint64
---@return boolean
function RemoteStorage.FileWriteStreamClose(writeHandle) end

---@param writeHandle uint64
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
---@return uint64
function RemoteStorage.GetFileTimestamp(pchFile) end

---@param pchFile string
---@return integer
function RemoteStorage.GetSyncPlatforms(pchFile) end

---@return integer
function RemoteStorage.GetFileCount() end

---@param iFile integer
---@return string
---@return integer -- Value of: pnFileSizeInBytes
function RemoteStorage.GetFileNameAndSize(iFile) end

---@return boolean
---@return uint64 -- Value of: pnTotalBytes
---@return uint64 -- Value of: puAvailableBytes
function RemoteStorage.GetQuota() end

---@return boolean
function RemoteStorage.IsCloudEnabledForAccount() end

---@return boolean
function RemoteStorage.IsCloudEnabledForApp() end

---@param bEnabled boolean
function RemoteStorage.SetCloudEnabledForApp(bEnabled) end

---@param hContent uint64
---@param unPriority integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function RemoteStorage.UGCDownload(hContent, unPriority, callback) end

---@param hContent uint64
---@return boolean
---@return integer -- Value of: pnBytesDownloaded
---@return integer -- Value of: pnBytesExpected
function RemoteStorage.GetUGCDownloadProgress(hContent) end

---@param hContent uint64
---@param cubDataToRead integer
---@param cOffset integer
---@param eAction integer
---@return integer
---@return string -- Value of: pvData
function RemoteStorage.UGCRead(hContent, cubDataToRead, cOffset, eAction) end

---@return integer
function RemoteStorage.GetCachedUGCCount() end

---@param iCachedContent integer
---@return uint64
function RemoteStorage.GetCachedUGCHandle(iCachedContent) end

---@param pchFile string
---@param pchPreviewFile string
---@param nConsumerAppId integer
---@param pchTitle string
---@param pchDescription string
---@param eVisibility integer
---@param eWorkshopFileType integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
---@return SteamParamStringArray_t -- Value of: pTags
function RemoteStorage.PublishWorkshopFile(pchFile, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility, eWorkshopFileType, callback) end

---@param unPublishedFileId uint64
---@return uint64
function RemoteStorage.CreatePublishedFileUpdateRequest(unPublishedFileId) end

---@param updateHandle uint64
---@param pchFile string
---@return boolean
function RemoteStorage.UpdatePublishedFileFile(updateHandle, pchFile) end

---@param updateHandle uint64
---@param pchPreviewFile string
---@return boolean
function RemoteStorage.UpdatePublishedFilePreviewFile(updateHandle, pchPreviewFile) end

---@param updateHandle uint64
---@param pchTitle string
---@return boolean
function RemoteStorage.UpdatePublishedFileTitle(updateHandle, pchTitle) end

---@param updateHandle uint64
---@param pchDescription string
---@return boolean
function RemoteStorage.UpdatePublishedFileDescription(updateHandle, pchDescription) end

---@param updateHandle uint64
---@param eVisibility integer
---@return boolean
function RemoteStorage.UpdatePublishedFileVisibility(updateHandle, eVisibility) end

---@param updateHandle uint64
---@return boolean
---@return SteamParamStringArray_t -- Value of: pTags
function RemoteStorage.UpdatePublishedFileTags(updateHandle) end

---@param updateHandle uint64
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function RemoteStorage.CommitPublishedFileUpdate(updateHandle, callback) end

---@param unPublishedFileId uint64
---@param unMaxSecondsOld integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function RemoteStorage.GetPublishedFileDetails(unPublishedFileId, unMaxSecondsOld, callback) end

---@param unPublishedFileId uint64
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function RemoteStorage.DeletePublishedFile(unPublishedFileId, callback) end

---@param unStartIndex integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function RemoteStorage.EnumerateUserPublishedFiles(unStartIndex, callback) end

---@param unPublishedFileId uint64
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function RemoteStorage.SubscribePublishedFile(unPublishedFileId, callback) end

---@param unStartIndex integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function RemoteStorage.EnumerateUserSubscribedFiles(unStartIndex, callback) end

---@param unPublishedFileId uint64
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function RemoteStorage.UnsubscribePublishedFile(unPublishedFileId, callback) end

---@param updateHandle uint64
---@param pchChangeDescription string
---@return boolean
function RemoteStorage.UpdatePublishedFileSetChangeDescription(updateHandle, pchChangeDescription) end

---@param unPublishedFileId uint64
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function RemoteStorage.GetPublishedItemVoteDetails(unPublishedFileId, callback) end

---@param unPublishedFileId uint64
---@param bVoteUp boolean
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function RemoteStorage.UpdateUserPublishedItemVote(unPublishedFileId, bVoteUp, callback) end

---@param unPublishedFileId uint64
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function RemoteStorage.GetUserPublishedItemVoteDetails(unPublishedFileId, callback) end

---@param steamId uint64
---@param unStartIndex integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
---@return SteamParamStringArray_t -- Value of: pRequiredTags
---@return SteamParamStringArray_t -- Value of: pExcludedTags
function RemoteStorage.EnumerateUserSharedWorkshopFiles(steamId, unStartIndex, callback) end

---@param eVideoProvider integer
---@param pchVideoAccount string
---@param pchVideoIdentifier string
---@param pchPreviewFile string
---@param nConsumerAppId integer
---@param pchTitle string
---@param pchDescription string
---@param eVisibility integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
---@return SteamParamStringArray_t -- Value of: pTags
function RemoteStorage.PublishVideo(eVideoProvider, pchVideoAccount, pchVideoIdentifier, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility, callback) end

---@param unPublishedFileId uint64
---@param eAction integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function RemoteStorage.SetUserPublishedFileAction(unPublishedFileId, eAction, callback) end

---@param eAction integer
---@param unStartIndex integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function RemoteStorage.EnumeratePublishedFilesByUserAction(eAction, unStartIndex, callback) end

---@param eEnumerationType integer
---@param unStartIndex integer
---@param unCount integer
---@param unDays integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
---@return SteamParamStringArray_t -- Value of: pTags
---@return SteamParamStringArray_t -- Value of: pUserTags
function RemoteStorage.EnumeratePublishedWorkshopFiles(eEnumerationType, unStartIndex, unCount, unDays, callback) end

---@param hContent uint64
---@param pchLocation string
---@param unPriority integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function RemoteStorage.UGCDownloadToLocation(hContent, pchLocation, unPriority, callback) end

---@return integer
function RemoteStorage.GetLocalFileChangeCount() end

---@param iFile integer
---@return string
---@return integer -- Value of: pEChangeType
---@return integer -- Value of: pEFilePathType
function RemoteStorage.GetLocalFileChange(iFile) end

---@return boolean
function RemoteStorage.BeginFileWriteBatch() end

---@return boolean
function RemoteStorage.EndFileWriteBatch() end

Steam.RemoteStorage = RemoteStorage
