---@class Steam.UGC
local UGC = {}

---@param unAccountID integer
---@param eListType integer
---@param eMatchingUGCType integer
---@param eSortOrder integer
---@param nCreatorAppID integer
---@param nConsumerAppID integer
---@param unPage integer
---@return uint64
function UGC.CreateQueryUserUGCRequest(unAccountID, eListType, eMatchingUGCType, eSortOrder, nCreatorAppID, nConsumerAppID, unPage) end

---@param eQueryType integer
---@param eMatchingeMatchingUGCTypeFileType integer
---@param nCreatorAppID integer
---@param nConsumerAppID integer
---@param unPage integer
---@return uint64
function UGC.CreateQueryAllUGCRequestPage(eQueryType, eMatchingeMatchingUGCTypeFileType, nCreatorAppID, nConsumerAppID, unPage) end

---@param unNumPublishedFileIDs integer
---@return uint64
---@return uint64 -- Value of: pvecPublishedFileID
function UGC.CreateQueryUGCDetailsRequest(unNumPublishedFileIDs) end

---@param handle uint64
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function UGC.SendQueryUGCRequest(handle, callback) end

---@param handle uint64
---@param index integer
---@return boolean
---@return SteamUGCDetails_t -- Value of: pDetails
function UGC.GetQueryUGCResult(handle, index) end

---@param handle uint64
---@param index integer
---@return integer
function UGC.GetQueryUGCNumTags(handle, index) end

---@param handle uint64
---@param index integer
---@param indexTag integer
---@param cchValueSize integer
---@return boolean
---@return string -- Value of: pchValue
function UGC.GetQueryUGCTag(handle, index, indexTag, cchValueSize) end

---@param handle uint64
---@param index integer
---@param indexTag integer
---@param cchValueSize integer
---@return boolean
---@return string -- Value of: pchValue
function UGC.GetQueryUGCTagDisplayName(handle, index, indexTag, cchValueSize) end

---@param handle uint64
---@param index integer
---@param cchURLSize integer
---@return boolean
---@return string -- Value of: pchURL
function UGC.GetQueryUGCPreviewURL(handle, index, cchURLSize) end

---@param handle uint64
---@param index integer
---@param cchMetadatasize integer
---@return boolean
---@return string -- Value of: pchMetadata
function UGC.GetQueryUGCMetadata(handle, index, cchMetadatasize) end

---@param handle uint64
---@param index integer
---@param cMaxEntries integer
---@return boolean
---@return uint64 -- Value of: pvecPublishedFileID
function UGC.GetQueryUGCChildren(handle, index, cMaxEntries) end

---@param handle uint64
---@param index integer
---@param eStatType integer
---@return boolean
---@return uint64 -- Value of: pStatValue
function UGC.GetQueryUGCStatistic(handle, index, eStatType) end

---@param handle uint64
---@param index integer
---@return integer
function UGC.GetQueryUGCNumAdditionalPreviews(handle, index) end

---@param handle uint64
---@param index integer
---@param previewIndex integer
---@param cchURLSize integer
---@param cchOriginalFileNameSize integer
---@return boolean
---@return string -- Value of: pchURLOrVideoID
---@return string -- Value of: pchOriginalFileName
---@return integer -- Value of: pPreviewType
function UGC.GetQueryUGCAdditionalPreview(handle, index, previewIndex, cchURLSize, cchOriginalFileNameSize) end

---@param handle uint64
---@param index integer
---@return integer
function UGC.GetQueryUGCNumKeyValueTags(handle, index) end

---@param handle uint64
---@param index integer
---@param keyValueTagIndex integer
---@param cchKeySize integer
---@param cchValueSize integer
---@return boolean
---@return string -- Value of: pchKey
---@return string -- Value of: pchValue
function UGC.GetQueryUGCKeyValueTag(handle, index, keyValueTagIndex, cchKeySize, cchValueSize) end

---@param handle uint64
---@param index integer
---@return integer
function UGC.GetNumSupportedGameVersions(handle, index) end

---@param handle uint64
---@param index integer
---@param versionIndex integer
---@param cchGameBranchSize integer
---@return boolean
---@return string -- Value of: pchGameBranchMin
---@return string -- Value of: pchGameBranchMax
function UGC.GetSupportedGameVersionData(handle, index, versionIndex, cchGameBranchSize) end

---@param handle uint64
---@param index integer
---@param cMaxEntries integer
---@return integer
---@return integer -- Value of: pvecDescriptors
function UGC.GetQueryUGCContentDescriptors(handle, index, cMaxEntries) end

---@param handle uint64
---@return boolean
function UGC.ReleaseQueryUGCRequest(handle) end

---@param handle uint64
---@param pTagName string
---@return boolean
function UGC.AddRequiredTag(handle, pTagName) end

---@param handle uint64
---@param pTagGroups SteamParamStringArray_t
---@return boolean
function UGC.AddRequiredTagGroup(handle, pTagGroups) end

---@param handle uint64
---@param pTagName string
---@return boolean
function UGC.AddExcludedTag(handle, pTagName) end

---@param handle uint64
---@param bReturnOnlyIDs boolean
---@return boolean
function UGC.SetReturnOnlyIDs(handle, bReturnOnlyIDs) end

---@param handle uint64
---@param bReturnKeyValueTags boolean
---@return boolean
function UGC.SetReturnKeyValueTags(handle, bReturnKeyValueTags) end

---@param handle uint64
---@param bReturnLongDescription boolean
---@return boolean
function UGC.SetReturnLongDescription(handle, bReturnLongDescription) end

---@param handle uint64
---@param bReturnMetadata boolean
---@return boolean
function UGC.SetReturnMetadata(handle, bReturnMetadata) end

---@param handle uint64
---@param bReturnChildren boolean
---@return boolean
function UGC.SetReturnChildren(handle, bReturnChildren) end

---@param handle uint64
---@param bReturnAdditionalPreviews boolean
---@return boolean
function UGC.SetReturnAdditionalPreviews(handle, bReturnAdditionalPreviews) end

---@param handle uint64
---@param bReturnTotalOnly boolean
---@return boolean
function UGC.SetReturnTotalOnly(handle, bReturnTotalOnly) end

---@param handle uint64
---@param unDays integer
---@return boolean
function UGC.SetReturnPlaytimeStats(handle, unDays) end

---@param handle uint64
---@param pchLanguage string
---@return boolean
function UGC.SetLanguage(handle, pchLanguage) end

---@param handle uint64
---@param unMaxAgeSeconds integer
---@return boolean
function UGC.SetAllowCachedResponse(handle, unMaxAgeSeconds) end

---@param handle uint64
---@param bAdminQuery boolean
---@return boolean
function UGC.SetAdminQuery(handle, bAdminQuery) end

---@param handle uint64
---@param pMatchCloudFileName string
---@return boolean
function UGC.SetCloudFileNameFilter(handle, pMatchCloudFileName) end

---@param handle uint64
---@param bMatchAnyTag boolean
---@return boolean
function UGC.SetMatchAnyTag(handle, bMatchAnyTag) end

---@param handle uint64
---@param pSearchText string
---@return boolean
function UGC.SetSearchText(handle, pSearchText) end

---@param handle uint64
---@param unDays integer
---@return boolean
function UGC.SetRankedByTrendDays(handle, unDays) end

---@param handle uint64
---@param rtStart integer
---@param rtEnd integer
---@return boolean
function UGC.SetTimeCreatedDateRange(handle, rtStart, rtEnd) end

---@param handle uint64
---@param rtStart integer
---@param rtEnd integer
---@return boolean
function UGC.SetTimeUpdatedDateRange(handle, rtStart, rtEnd) end

---@param handle uint64
---@param pKey string
---@param pValue string
---@return boolean
function UGC.AddRequiredKeyValueTag(handle, pKey, pValue) end

---@param nPublishedFileID uint64
---@param unMaxAgeSeconds integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function UGC.RequestUGCDetails(nPublishedFileID, unMaxAgeSeconds, callback) end

---@param nConsumerAppId integer
---@param eFileType integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function UGC.CreateItem(nConsumerAppId, eFileType, callback) end

---@param nConsumerAppId integer
---@param nPublishedFileID uint64
---@return uint64
function UGC.StartItemUpdate(nConsumerAppId, nPublishedFileID) end

---@param handle uint64
---@param pchTitle string
---@return boolean
function UGC.SetItemTitle(handle, pchTitle) end

---@param handle uint64
---@param pchDescription string
---@return boolean
function UGC.SetItemDescription(handle, pchDescription) end

---@param handle uint64
---@param pchLanguage string
---@return boolean
function UGC.SetItemUpdateLanguage(handle, pchLanguage) end

---@param handle uint64
---@param pchMetaData string
---@return boolean
function UGC.SetItemMetadata(handle, pchMetaData) end

---@param handle uint64
---@param eVisibility integer
---@return boolean
function UGC.SetItemVisibility(handle, eVisibility) end

---@param updateHandle uint64
---@param pTags SteamParamStringArray_t
---@param bAllowAdminTags boolean
---@return boolean
function UGC.SetItemTags(updateHandle, pTags, bAllowAdminTags) end

---@param handle uint64
---@param pszContentFolder string
---@return boolean
function UGC.SetItemContent(handle, pszContentFolder) end

---@param handle uint64
---@param pszPreviewFile string
---@return boolean
function UGC.SetItemPreview(handle, pszPreviewFile) end

---@param handle uint64
---@param bAllowLegacyUpload boolean
---@return boolean
function UGC.SetAllowLegacyUpload(handle, bAllowLegacyUpload) end

---@param handle uint64
---@return boolean
function UGC.RemoveAllItemKeyValueTags(handle) end

---@param handle uint64
---@param pchKey string
---@return boolean
function UGC.RemoveItemKeyValueTags(handle, pchKey) end

---@param handle uint64
---@param pchKey string
---@param pchValue string
---@return boolean
function UGC.AddItemKeyValueTag(handle, pchKey, pchValue) end

---@param handle uint64
---@param pszPreviewFile string
---@param type integer
---@return boolean
function UGC.AddItemPreviewFile(handle, pszPreviewFile, type) end

---@param handle uint64
---@param pszVideoID string
---@return boolean
function UGC.AddItemPreviewVideo(handle, pszVideoID) end

---@param handle uint64
---@param index integer
---@param pszPreviewFile string
---@return boolean
function UGC.UpdateItemPreviewFile(handle, index, pszPreviewFile) end

---@param handle uint64
---@param index integer
---@param pszVideoID string
---@return boolean
function UGC.UpdateItemPreviewVideo(handle, index, pszVideoID) end

---@param handle uint64
---@param index integer
---@return boolean
function UGC.RemoveItemPreview(handle, index) end

---@param handle uint64
---@param descid integer
---@return boolean
function UGC.AddContentDescriptor(handle, descid) end

---@param handle uint64
---@param descid integer
---@return boolean
function UGC.RemoveContentDescriptor(handle, descid) end

---@param handle uint64
---@param pszGameBranchMin string
---@param pszGameBranchMax string
---@return boolean
function UGC.SetRequiredGameVersions(handle, pszGameBranchMin, pszGameBranchMax) end

---@param handle uint64
---@param pchChangeNote string
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function UGC.SubmitItemUpdate(handle, pchChangeNote, callback) end

---@param handle uint64
---@return integer
---@return uint64 -- Value of: punBytesProcessed
---@return uint64 -- Value of: punBytesTotal
function UGC.GetItemUpdateProgress(handle) end

---@param nPublishedFileID uint64
---@param bVoteUp boolean
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function UGC.SetUserItemVote(nPublishedFileID, bVoteUp, callback) end

---@param nPublishedFileID uint64
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function UGC.GetUserItemVote(nPublishedFileID, callback) end

---@param nAppId integer
---@param nPublishedFileID uint64
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function UGC.AddItemToFavorites(nAppId, nPublishedFileID, callback) end

---@param nAppId integer
---@param nPublishedFileID uint64
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function UGC.RemoveItemFromFavorites(nAppId, nPublishedFileID, callback) end

---@param nPublishedFileID uint64
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function UGC.SubscribeItem(nPublishedFileID, callback) end

---@param nPublishedFileID uint64
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function UGC.UnsubscribeItem(nPublishedFileID, callback) end

---@param bIncludeLocallyDisabled boolean
---@return integer
function UGC.GetNumSubscribedItems(bIncludeLocallyDisabled) end

---@param cMaxEntries integer
---@param bIncludeLocallyDisabled boolean
---@return integer
---@return uint64[] -- Value of: pvecPublishedFileID
function UGC.GetSubscribedItems(cMaxEntries, bIncludeLocallyDisabled) end

---@param nPublishedFileID uint64
---@return integer
function UGC.GetItemState(nPublishedFileID) end

---@param nPublishedFileID uint64
---@param cchFolderSize integer
---@return boolean
---@return uint64 -- Value of: punSizeOnDisk
---@return string -- Value of: pchFolder
---@return integer -- Value of: punTimeStamp
function UGC.GetItemInstallInfo(nPublishedFileID, cchFolderSize) end

---@param nPublishedFileID uint64
---@return boolean
---@return uint64 -- Value of: punBytesDownloaded
---@return uint64 -- Value of: punBytesTotal
function UGC.GetItemDownloadInfo(nPublishedFileID) end

---@param nPublishedFileID uint64
---@param bHighPriority boolean
---@return boolean
function UGC.DownloadItem(nPublishedFileID, bHighPriority) end

---@param unWorkshopDepotID integer
---@param pszFolder string
---@return boolean
function UGC.BInitWorkshopForGameServer(unWorkshopDepotID, pszFolder) end

---@param bSuspend boolean
function UGC.SuspendDownloads(bSuspend) end

---@param pvecPublishedFileID uint64[]
---@param unNumPublishedFileIDs integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function UGC.StartPlaytimeTracking(pvecPublishedFileID, unNumPublishedFileIDs, callback) end

---@param pvecPublishedFileID uint64[]
---@param unNumPublishedFileIDs integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function UGC.StopPlaytimeTracking(pvecPublishedFileID, unNumPublishedFileIDs, callback) end

---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function UGC.StopPlaytimeTrackingForAllItems(callback) end

---@param nParentPublishedFileID uint64
---@param nChildPublishedFileID uint64
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function UGC.AddDependency(nParentPublishedFileID, nChildPublishedFileID, callback) end

---@param nParentPublishedFileID uint64
---@param nChildPublishedFileID uint64
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function UGC.RemoveDependency(nParentPublishedFileID, nChildPublishedFileID, callback) end

---@param nPublishedFileID uint64
---@param nAppID integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function UGC.AddAppDependency(nPublishedFileID, nAppID, callback) end

---@param nPublishedFileID uint64
---@param nAppID integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function UGC.RemoveAppDependency(nPublishedFileID, nAppID, callback) end

---@param nPublishedFileID uint64
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function UGC.GetAppDependencies(nPublishedFileID, callback) end

---@param nPublishedFileID uint64
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function UGC.DeleteItem(nPublishedFileID, callback) end

---@return boolean
function UGC.ShowWorkshopEULA() end

---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function UGC.GetWorkshopEULAStatus(callback) end

---@param cMaxEntries integer
---@return integer
---@return integer -- Value of: pvecDescriptors
function UGC.GetUserContentDescriptorPreferences(cMaxEntries) end

---@param unNumPublishedFileIDs integer
---@param bDisabledLocally boolean
---@return boolean
---@return uint64 -- Value of: pvecPublishedFileIDs
function UGC.SetItemsDisabledLocally(unNumPublishedFileIDs, bDisabledLocally) end

---@param unNumPublishedFileIDs integer
---@return boolean
---@return uint64 -- Value of: pvecPublishedFileIDs
function UGC.SetSubscriptionsLoadOrder(unNumPublishedFileIDs) end

Steam.UGC = UGC
