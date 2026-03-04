---@class Steam.UGC
---@field OnSteamUGCQueryCompleted? fun(data: SteamUGCQueryCompleted_t)
---@field OnSteamUGCRequestUGCDetailsResult? fun(data: SteamUGCRequestUGCDetailsResult_t)
---@field OnCreateItemResult? fun(data: CreateItemResult_t)
---@field OnSubmitItemUpdateResult? fun(data: SubmitItemUpdateResult_t)
---@field OnItemInstalled? fun(data: ItemInstalled_t)
---@field OnDownloadItemResult? fun(data: DownloadItemResult_t)
---@field OnUserFavoriteItemsListChanged? fun(data: UserFavoriteItemsListChanged_t)
---@field OnSetUserItemVoteResult? fun(data: SetUserItemVoteResult_t)
---@field OnGetUserItemVoteResult? fun(data: GetUserItemVoteResult_t)
---@field OnStartPlaytimeTrackingResult? fun(data: StartPlaytimeTrackingResult_t)
---@field OnStopPlaytimeTrackingResult? fun(data: StopPlaytimeTrackingResult_t)
---@field OnAddUGCDependencyResult? fun(data: AddUGCDependencyResult_t)
---@field OnRemoveUGCDependencyResult? fun(data: RemoveUGCDependencyResult_t)
---@field OnAddAppDependencyResult? fun(data: AddAppDependencyResult_t)
---@field OnRemoveAppDependencyResult? fun(data: RemoveAppDependencyResult_t)
---@field OnGetAppDependenciesResult? fun(data: GetAppDependenciesResult_t)
---@field OnDeleteItemResult? fun(data: DeleteItemResult_t)
---@field OnUserSubscribedItemsListChanged? fun(data: UserSubscribedItemsListChanged_t)
---@field OnWorkshopEULAStatus? fun(data: WorkshopEULAStatus_t)
local UGC = {}

---@param unAccountID integer -- AccountID_t
---@param eListType integer -- EUserUGCList
---@param eMatchingUGCType integer -- EUGCMatchingUGCType
---@param eSortOrder integer -- EUserUGCListSortOrder
---@param nCreatorAppID integer -- AppId_t
---@param nConsumerAppID integer -- AppId_t
---@param unPage integer
---@return uint64 -- UGCQueryHandle_t
function UGC.CreateQueryUserUGCRequest(unAccountID, eListType, eMatchingUGCType, eSortOrder, nCreatorAppID, nConsumerAppID, unPage) end

---@param eQueryType integer -- EUGCQuery
---@param eMatchingeMatchingUGCTypeFileType integer -- EUGCMatchingUGCType
---@param nCreatorAppID integer -- AppId_t
---@param nConsumerAppID integer -- AppId_t
---@param unPage integer
---@return uint64 -- UGCQueryHandle_t
function UGC.CreateQueryAllUGCRequestPage(eQueryType, eMatchingeMatchingUGCTypeFileType, nCreatorAppID, nConsumerAppID, unPage) end

---@param eQueryType integer -- EUGCQuery
---@param eMatchingeMatchingUGCTypeFileType integer -- EUGCMatchingUGCType
---@param nCreatorAppID integer -- AppId_t
---@param nConsumerAppID integer -- AppId_t
---@param pchCursor string?
---@return uint64 -- UGCQueryHandle_t
function UGC.CreateQueryAllUGCRequestCursor(eQueryType, eMatchingeMatchingUGCTypeFileType, nCreatorAppID, nConsumerAppID, pchCursor) end

---@param pvecPublishedFileID uint64[]?
---@param unNumPublishedFileIDs integer size of the input array pvecPublishedFileID
---@return uint64 -- UGCQueryHandle_t
function UGC.CreateQueryUGCDetailsRequest(pvecPublishedFileID, unNumPublishedFileIDs) end

---@param handle uint64 -- UGCQueryHandle_t
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function UGC.SendQueryUGCRequest(handle, callback) end

---@param handle uint64 -- UGCQueryHandle_t
---@param index integer
---@return boolean
---@return SteamUGCDetails_t -- Value of: pDetails
function UGC.GetQueryUGCResult(handle, index) end

---@param handle uint64 -- UGCQueryHandle_t
---@param index integer
---@return integer
function UGC.GetQueryUGCNumTags(handle, index) end

---@param handle uint64 -- UGCQueryHandle_t
---@param index integer
---@param indexTag integer
---@param cchValueSize integer? size of the buffer for pchValue; if nil then the buffer will be NULL
---@return boolean
---@return string -- Value of: pchValue
function UGC.GetQueryUGCTag(handle, index, indexTag, cchValueSize) end

---@param handle uint64 -- UGCQueryHandle_t
---@param index integer
---@param indexTag integer
---@param cchValueSize integer? size of the buffer for pchValue; if nil then the buffer will be NULL
---@return boolean
---@return string -- Value of: pchValue
function UGC.GetQueryUGCTagDisplayName(handle, index, indexTag, cchValueSize) end

---@param handle uint64 -- UGCQueryHandle_t
---@param index integer
---@param cchURLSize integer? size of the buffer for pchURL; if nil then the buffer will be NULL
---@return boolean
---@return string -- Value of: pchURL
function UGC.GetQueryUGCPreviewURL(handle, index, cchURLSize) end

---@param handle uint64 -- UGCQueryHandle_t
---@param index integer
---@param cchMetadatasize integer? size of the buffer for pchMetadata; if nil then the buffer will be NULL
---@return boolean
---@return string -- Value of: pchMetadata
function UGC.GetQueryUGCMetadata(handle, index, cchMetadatasize) end

---@param handle uint64 -- UGCQueryHandle_t
---@param index integer
---@param cMaxEntries integer? size of the buffer for pvecPublishedFileID; if nil then the buffer will be NULL
---@return boolean
---@return uint64[] -- Value of: pvecPublishedFileID
function UGC.GetQueryUGCChildren(handle, index, cMaxEntries) end

---@param handle uint64 -- UGCQueryHandle_t
---@param index integer
---@param eStatType integer -- EItemStatistic
---@return boolean
---@return uint64 -- Value of: pStatValue
function UGC.GetQueryUGCStatistic(handle, index, eStatType) end

---@param handle uint64 -- UGCQueryHandle_t
---@param index integer
---@return integer
function UGC.GetQueryUGCNumAdditionalPreviews(handle, index) end

---@param handle uint64 -- UGCQueryHandle_t
---@param index integer
---@param previewIndex integer
---@param cchURLSize integer? size of the buffer for pchURLOrVideoID; if nil then the buffer will be NULL
---@param cchOriginalFileNameSize integer? size of the buffer for pchOriginalFileName; if nil then the buffer will be NULL
---@return boolean
---@return string -- Value of: pchURLOrVideoID
---@return string -- Value of: pchOriginalFileName
---@return integer -- Value of: pPreviewType
function UGC.GetQueryUGCAdditionalPreview(handle, index, previewIndex, cchURLSize, cchOriginalFileNameSize) end

---@param handle uint64 -- UGCQueryHandle_t
---@param index integer
---@return integer
function UGC.GetQueryUGCNumKeyValueTags(handle, index) end

---@param handle uint64 -- UGCQueryHandle_t
---@param index integer
---@param keyValueTagIndex integer
---@param cchKeySize integer? size of the buffer for pchKey; if nil then the buffer will be NULL
---@param cchValueSize integer? size of the buffer for pchValue; if nil then the buffer will be NULL
---@return boolean
---@return string -- Value of: pchKey
---@return string -- Value of: pchValue
function UGC.GetQueryUGCKeyValueTag(handle, index, keyValueTagIndex, cchKeySize, cchValueSize) end

---@param handle uint64 -- UGCQueryHandle_t
---@param index integer
---@return integer
function UGC.GetNumSupportedGameVersions(handle, index) end

---@param handle uint64 -- UGCQueryHandle_t
---@param index integer
---@param versionIndex integer
---@param cchGameBranchSize integer? size of the buffer for pchGameBranchMin, pchGameBranchMax; if nil then the buffer will be NULL
---@return boolean
---@return string -- Value of: pchGameBranchMin
---@return string -- Value of: pchGameBranchMax
function UGC.GetSupportedGameVersionData(handle, index, versionIndex, cchGameBranchSize) end

---@param handle uint64 -- UGCQueryHandle_t
---@param index integer
---@param cMaxEntries integer? size of the buffer for pvecDescriptors; if nil then the buffer will be NULL
---@return integer
---@return integer[] -- Value of: pvecDescriptors
function UGC.GetQueryUGCContentDescriptors(handle, index, cMaxEntries) end

---@param handle uint64 -- UGCQueryHandle_t
---@return boolean
function UGC.ReleaseQueryUGCRequest(handle) end

---@param handle uint64 -- UGCQueryHandle_t
---@param pTagName string?
---@return boolean
function UGC.AddRequiredTag(handle, pTagName) end

---@param handle uint64 -- UGCQueryHandle_t
---@param pTagGroups SteamParamStringArray_t
---@return boolean
function UGC.AddRequiredTagGroup(handle, pTagGroups) end

---@param handle uint64 -- UGCQueryHandle_t
---@param pTagName string?
---@return boolean
function UGC.AddExcludedTag(handle, pTagName) end

---@param handle uint64 -- UGCQueryHandle_t
---@param bReturnOnlyIDs boolean
---@return boolean
function UGC.SetReturnOnlyIDs(handle, bReturnOnlyIDs) end

---@param handle uint64 -- UGCQueryHandle_t
---@param bReturnKeyValueTags boolean
---@return boolean
function UGC.SetReturnKeyValueTags(handle, bReturnKeyValueTags) end

---@param handle uint64 -- UGCQueryHandle_t
---@param bReturnLongDescription boolean
---@return boolean
function UGC.SetReturnLongDescription(handle, bReturnLongDescription) end

---@param handle uint64 -- UGCQueryHandle_t
---@param bReturnMetadata boolean
---@return boolean
function UGC.SetReturnMetadata(handle, bReturnMetadata) end

---@param handle uint64 -- UGCQueryHandle_t
---@param bReturnChildren boolean
---@return boolean
function UGC.SetReturnChildren(handle, bReturnChildren) end

---@param handle uint64 -- UGCQueryHandle_t
---@param bReturnAdditionalPreviews boolean
---@return boolean
function UGC.SetReturnAdditionalPreviews(handle, bReturnAdditionalPreviews) end

---@param handle uint64 -- UGCQueryHandle_t
---@param bReturnTotalOnly boolean
---@return boolean
function UGC.SetReturnTotalOnly(handle, bReturnTotalOnly) end

---@param handle uint64 -- UGCQueryHandle_t
---@param unDays integer
---@return boolean
function UGC.SetReturnPlaytimeStats(handle, unDays) end

---@param handle uint64 -- UGCQueryHandle_t
---@param pchLanguage string?
---@return boolean
function UGC.SetLanguage(handle, pchLanguage) end

---@param handle uint64 -- UGCQueryHandle_t
---@param unMaxAgeSeconds integer
---@return boolean
function UGC.SetAllowCachedResponse(handle, unMaxAgeSeconds) end

---@param handle uint64 -- UGCUpdateHandle_t
---@param bAdminQuery boolean
---@return boolean
function UGC.SetAdminQuery(handle, bAdminQuery) end

---@param handle uint64 -- UGCQueryHandle_t
---@param pMatchCloudFileName string?
---@return boolean
function UGC.SetCloudFileNameFilter(handle, pMatchCloudFileName) end

---@param handle uint64 -- UGCQueryHandle_t
---@param bMatchAnyTag boolean
---@return boolean
function UGC.SetMatchAnyTag(handle, bMatchAnyTag) end

---@param handle uint64 -- UGCQueryHandle_t
---@param pSearchText string?
---@return boolean
function UGC.SetSearchText(handle, pSearchText) end

---@param handle uint64 -- UGCQueryHandle_t
---@param unDays integer
---@return boolean
function UGC.SetRankedByTrendDays(handle, unDays) end

---@param handle uint64 -- UGCQueryHandle_t
---@param rtStart integer -- RTime32
---@param rtEnd integer -- RTime32
---@return boolean
function UGC.SetTimeCreatedDateRange(handle, rtStart, rtEnd) end

---@param handle uint64 -- UGCQueryHandle_t
---@param rtStart integer -- RTime32
---@param rtEnd integer -- RTime32
---@return boolean
function UGC.SetTimeUpdatedDateRange(handle, rtStart, rtEnd) end

---@param handle uint64 -- UGCQueryHandle_t
---@param pKey string?
---@param pValue string?
---@return boolean
function UGC.AddRequiredKeyValueTag(handle, pKey, pValue) end

---@param nPublishedFileID uint64 -- PublishedFileId_t
---@param unMaxAgeSeconds integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function UGC.RequestUGCDetails(nPublishedFileID, unMaxAgeSeconds, callback) end

---@param nConsumerAppId integer -- AppId_t
---@param eFileType integer -- EWorkshopFileType
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function UGC.CreateItem(nConsumerAppId, eFileType, callback) end

---@param nConsumerAppId integer -- AppId_t
---@param nPublishedFileID uint64 -- PublishedFileId_t
---@return uint64 -- UGCUpdateHandle_t
function UGC.StartItemUpdate(nConsumerAppId, nPublishedFileID) end

---@param handle uint64 -- UGCUpdateHandle_t
---@param pchTitle string?
---@return boolean
function UGC.SetItemTitle(handle, pchTitle) end

---@param handle uint64 -- UGCUpdateHandle_t
---@param pchDescription string?
---@return boolean
function UGC.SetItemDescription(handle, pchDescription) end

---@param handle uint64 -- UGCUpdateHandle_t
---@param pchLanguage string?
---@return boolean
function UGC.SetItemUpdateLanguage(handle, pchLanguage) end

---@param handle uint64 -- UGCUpdateHandle_t
---@param pchMetaData string?
---@return boolean
function UGC.SetItemMetadata(handle, pchMetaData) end

---@param handle uint64 -- UGCUpdateHandle_t
---@param eVisibility integer -- ERemoteStoragePublishedFileVisibility
---@return boolean
function UGC.SetItemVisibility(handle, eVisibility) end

---@param updateHandle uint64 -- UGCUpdateHandle_t
---@param pTags SteamParamStringArray_t
---@param bAllowAdminTags boolean
---@return boolean
function UGC.SetItemTags(updateHandle, pTags, bAllowAdminTags) end

---@param handle uint64 -- UGCUpdateHandle_t
---@param pszContentFolder string?
---@return boolean
function UGC.SetItemContent(handle, pszContentFolder) end

---@param handle uint64 -- UGCUpdateHandle_t
---@param pszPreviewFile string?
---@return boolean
function UGC.SetItemPreview(handle, pszPreviewFile) end

---@param handle uint64 -- UGCUpdateHandle_t
---@param bAllowLegacyUpload boolean
---@return boolean
function UGC.SetAllowLegacyUpload(handle, bAllowLegacyUpload) end

---@param handle uint64 -- UGCUpdateHandle_t
---@return boolean
function UGC.RemoveAllItemKeyValueTags(handle) end

---@param handle uint64 -- UGCUpdateHandle_t
---@param pchKey string?
---@return boolean
function UGC.RemoveItemKeyValueTags(handle, pchKey) end

---@param handle uint64 -- UGCUpdateHandle_t
---@param pchKey string?
---@param pchValue string?
---@return boolean
function UGC.AddItemKeyValueTag(handle, pchKey, pchValue) end

---@param handle uint64 -- UGCUpdateHandle_t
---@param pszPreviewFile string?
---@param type integer -- EItemPreviewType
---@return boolean
function UGC.AddItemPreviewFile(handle, pszPreviewFile, type) end

---@param handle uint64 -- UGCUpdateHandle_t
---@param pszVideoID string?
---@return boolean
function UGC.AddItemPreviewVideo(handle, pszVideoID) end

---@param handle uint64 -- UGCUpdateHandle_t
---@param index integer
---@param pszPreviewFile string?
---@return boolean
function UGC.UpdateItemPreviewFile(handle, index, pszPreviewFile) end

---@param handle uint64 -- UGCUpdateHandle_t
---@param index integer
---@param pszVideoID string?
---@return boolean
function UGC.UpdateItemPreviewVideo(handle, index, pszVideoID) end

---@param handle uint64 -- UGCUpdateHandle_t
---@param index integer
---@return boolean
function UGC.RemoveItemPreview(handle, index) end

---@param handle uint64 -- UGCUpdateHandle_t
---@param descid integer -- EUGCContentDescriptorID
---@return boolean
function UGC.AddContentDescriptor(handle, descid) end

---@param handle uint64 -- UGCUpdateHandle_t
---@param descid integer -- EUGCContentDescriptorID
---@return boolean
function UGC.RemoveContentDescriptor(handle, descid) end

---@param handle uint64 -- UGCUpdateHandle_t
---@param pszGameBranchMin string?
---@param pszGameBranchMax string?
---@return boolean
function UGC.SetRequiredGameVersions(handle, pszGameBranchMin, pszGameBranchMax) end

---@param handle uint64 -- UGCUpdateHandle_t
---@param pchChangeNote string?
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function UGC.SubmitItemUpdate(handle, pchChangeNote, callback) end

---@param handle uint64 -- UGCUpdateHandle_t
---@return integer -- EItemUpdateStatus
---@return uint64 -- Value of: punBytesProcessed
---@return uint64 -- Value of: punBytesTotal
function UGC.GetItemUpdateProgress(handle) end

---@param nPublishedFileID uint64 -- PublishedFileId_t
---@param bVoteUp boolean
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function UGC.SetUserItemVote(nPublishedFileID, bVoteUp, callback) end

---@param nPublishedFileID uint64 -- PublishedFileId_t
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function UGC.GetUserItemVote(nPublishedFileID, callback) end

---@param nAppId integer -- AppId_t
---@param nPublishedFileID uint64 -- PublishedFileId_t
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function UGC.AddItemToFavorites(nAppId, nPublishedFileID, callback) end

---@param nAppId integer -- AppId_t
---@param nPublishedFileID uint64 -- PublishedFileId_t
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function UGC.RemoveItemFromFavorites(nAppId, nPublishedFileID, callback) end

---@param nPublishedFileID uint64 -- PublishedFileId_t
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function UGC.SubscribeItem(nPublishedFileID, callback) end

---@param nPublishedFileID uint64 -- PublishedFileId_t
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function UGC.UnsubscribeItem(nPublishedFileID, callback) end

---@param bIncludeLocallyDisabled boolean
---@return integer
function UGC.GetNumSubscribedItems(bIncludeLocallyDisabled) end

---@param cMaxEntries integer? size of the buffer for pvecPublishedFileID; if nil then the buffer will be NULL
---@param bIncludeLocallyDisabled boolean
---@return integer
---@return uint64[] -- Value of: pvecPublishedFileID
function UGC.GetSubscribedItems(cMaxEntries, bIncludeLocallyDisabled) end

---@param nPublishedFileID uint64 -- PublishedFileId_t
---@return integer
function UGC.GetItemState(nPublishedFileID) end

---@param nPublishedFileID uint64 -- PublishedFileId_t
---@param cchFolderSize integer? size of the buffer for pchFolder; if nil then the buffer will be NULL
---@return boolean
---@return uint64 -- Value of: punSizeOnDisk
---@return string -- Value of: pchFolder
---@return integer -- Value of: punTimeStamp
function UGC.GetItemInstallInfo(nPublishedFileID, cchFolderSize) end

---@param nPublishedFileID uint64 -- PublishedFileId_t
---@return boolean
---@return uint64 -- Value of: punBytesDownloaded
---@return uint64 -- Value of: punBytesTotal
function UGC.GetItemDownloadInfo(nPublishedFileID) end

---@param nPublishedFileID uint64 -- PublishedFileId_t
---@param bHighPriority boolean
---@return boolean
function UGC.DownloadItem(nPublishedFileID, bHighPriority) end

---@param unWorkshopDepotID integer -- DepotId_t
---@param pszFolder string?
---@return boolean
function UGC.BInitWorkshopForGameServer(unWorkshopDepotID, pszFolder) end

---@param bSuspend boolean
function UGC.SuspendDownloads(bSuspend) end

---@param pvecPublishedFileID uint64[]?
---@param unNumPublishedFileIDs integer size of the input array pvecPublishedFileID
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function UGC.StartPlaytimeTracking(pvecPublishedFileID, unNumPublishedFileIDs, callback) end

---@param pvecPublishedFileID uint64[]?
---@param unNumPublishedFileIDs integer size of the input array pvecPublishedFileID
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function UGC.StopPlaytimeTracking(pvecPublishedFileID, unNumPublishedFileIDs, callback) end

---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function UGC.StopPlaytimeTrackingForAllItems(callback) end

---@param nParentPublishedFileID uint64 -- PublishedFileId_t
---@param nChildPublishedFileID uint64 -- PublishedFileId_t
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function UGC.AddDependency(nParentPublishedFileID, nChildPublishedFileID, callback) end

---@param nParentPublishedFileID uint64 -- PublishedFileId_t
---@param nChildPublishedFileID uint64 -- PublishedFileId_t
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function UGC.RemoveDependency(nParentPublishedFileID, nChildPublishedFileID, callback) end

---@param nPublishedFileID uint64 -- PublishedFileId_t
---@param nAppID integer -- AppId_t
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function UGC.AddAppDependency(nPublishedFileID, nAppID, callback) end

---@param nPublishedFileID uint64 -- PublishedFileId_t
---@param nAppID integer -- AppId_t
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function UGC.RemoveAppDependency(nPublishedFileID, nAppID, callback) end

---@param nPublishedFileID uint64 -- PublishedFileId_t
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function UGC.GetAppDependencies(nPublishedFileID, callback) end

---@param nPublishedFileID uint64 -- PublishedFileId_t
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function UGC.DeleteItem(nPublishedFileID, callback) end

---@return boolean
function UGC.ShowWorkshopEULA() end

---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function UGC.GetWorkshopEULAStatus(callback) end

---@param cMaxEntries integer? size of the buffer for pvecDescriptors; if nil then the buffer will be NULL
---@return integer
---@return integer[] -- Value of: pvecDescriptors
function UGC.GetUserContentDescriptorPreferences(cMaxEntries) end

---@param pvecPublishedFileIDs uint64[]?
---@param unNumPublishedFileIDs integer size of the input array pvecPublishedFileIDs
---@param bDisabledLocally boolean
---@return boolean
function UGC.SetItemsDisabledLocally(pvecPublishedFileIDs, unNumPublishedFileIDs, bDisabledLocally) end

---@param pvecPublishedFileIDs uint64[]?
---@param unNumPublishedFileIDs integer size of the input array pvecPublishedFileIDs
---@return boolean
function UGC.SetSubscriptionsLoadOrder(pvecPublishedFileIDs, unNumPublishedFileIDs) end

Steam.UGC = UGC
