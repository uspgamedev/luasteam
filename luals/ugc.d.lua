---@class Steam.UGC
local UGC = {}

---@param unAccountID integer
---@param eListType integer
---@param eMatchingUGCType integer
---@param eSortOrder integer
---@param nCreatorAppID integer
---@param nConsumerAppID integer
---@param unPage integer
---@return table
function UGC.CreateQueryUserUGCRequest(unAccountID, eListType, eMatchingUGCType, eSortOrder, nCreatorAppID, nConsumerAppID, unPage) end

---@param eQueryType integer
---@param eMatchingeMatchingUGCTypeFileType integer
---@param nCreatorAppID integer
---@param nConsumerAppID integer
---@param unPage integer
---@return table
function UGC.CreateQueryAllUGCRequestPage(eQueryType, eMatchingeMatchingUGCTypeFileType, nCreatorAppID, nConsumerAppID, unPage) end

---@param unNumPublishedFileIDs integer
---@return table
---@return table
function UGC.CreateQueryUGCDetailsRequest(unNumPublishedFileIDs) end

---@param handle table
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function UGC.SendQueryUGCRequest(handle, callback) end

---@param handle table
---@param index integer
---@return boolean
---@return table
function UGC.GetQueryUGCResult(handle, index) end

---@param handle table
---@param index integer
---@return integer
function UGC.GetQueryUGCNumTags(handle, index) end

---@param handle table
---@param index integer
---@param indexTag integer
---@param pchValue string
---@param cchValueSize integer
---@return boolean
function UGC.GetQueryUGCTag(handle, index, indexTag, pchValue, cchValueSize) end

---@param handle table
---@param index integer
---@param indexTag integer
---@param pchValue string
---@param cchValueSize integer
---@return boolean
function UGC.GetQueryUGCTagDisplayName(handle, index, indexTag, pchValue, cchValueSize) end

---@param handle table
---@param index integer
---@param pchURL string
---@param cchURLSize integer
---@return boolean
function UGC.GetQueryUGCPreviewURL(handle, index, pchURL, cchURLSize) end

---@param handle table
---@param index integer
---@param pchMetadata string
---@param cchMetadatasize integer
---@return boolean
function UGC.GetQueryUGCMetadata(handle, index, pchMetadata, cchMetadatasize) end

---@param handle table
---@param index integer
---@param cMaxEntries integer
---@return boolean
---@return table
function UGC.GetQueryUGCChildren(handle, index, cMaxEntries) end

---@param handle table
---@param index integer
---@param eStatType integer
---@return boolean
---@return table
function UGC.GetQueryUGCStatistic(handle, index, eStatType) end

---@param handle table
---@param index integer
---@return integer
function UGC.GetQueryUGCNumAdditionalPreviews(handle, index) end

---@param handle table
---@param index integer
---@param previewIndex integer
---@param pchURLOrVideoID string
---@param cchURLSize integer
---@param pchOriginalFileName string
---@param cchOriginalFileNameSize integer
---@return boolean
---@return integer
function UGC.GetQueryUGCAdditionalPreview(handle, index, previewIndex, pchURLOrVideoID, cchURLSize, pchOriginalFileName, cchOriginalFileNameSize) end

---@param handle table
---@param index integer
---@return integer
function UGC.GetQueryUGCNumKeyValueTags(handle, index) end

---@param handle table
---@param index integer
---@param keyValueTagIndex integer
---@param pchKey string
---@param cchKeySize integer
---@param pchValue string
---@param cchValueSize integer
---@return boolean
function UGC.GetQueryUGCKeyValueTag(handle, index, keyValueTagIndex, pchKey, cchKeySize, pchValue, cchValueSize) end

---@param handle table
---@param index integer
---@return integer
function UGC.GetNumSupportedGameVersions(handle, index) end

---@param handle table
---@param index integer
---@param versionIndex integer
---@param pchGameBranchMin string
---@param pchGameBranchMax string
---@param cchGameBranchSize integer
---@return boolean
function UGC.GetSupportedGameVersionData(handle, index, versionIndex, pchGameBranchMin, pchGameBranchMax, cchGameBranchSize) end

---@param handle table
---@param index integer
---@param cMaxEntries integer
---@return integer
---@return integer
function UGC.GetQueryUGCContentDescriptors(handle, index, cMaxEntries) end

---@param handle table
---@return boolean
function UGC.ReleaseQueryUGCRequest(handle) end

---@param handle table
---@param pTagName string
---@return boolean
function UGC.AddRequiredTag(handle, pTagName) end

---@param handle table
---@param pTagName string
---@return boolean
function UGC.AddExcludedTag(handle, pTagName) end

---@param handle table
---@param bReturnOnlyIDs boolean
---@return boolean
function UGC.SetReturnOnlyIDs(handle, bReturnOnlyIDs) end

---@param handle table
---@param bReturnKeyValueTags boolean
---@return boolean
function UGC.SetReturnKeyValueTags(handle, bReturnKeyValueTags) end

---@param handle table
---@param bReturnLongDescription boolean
---@return boolean
function UGC.SetReturnLongDescription(handle, bReturnLongDescription) end

---@param handle table
---@param bReturnMetadata boolean
---@return boolean
function UGC.SetReturnMetadata(handle, bReturnMetadata) end

---@param handle table
---@param bReturnChildren boolean
---@return boolean
function UGC.SetReturnChildren(handle, bReturnChildren) end

---@param handle table
---@param bReturnAdditionalPreviews boolean
---@return boolean
function UGC.SetReturnAdditionalPreviews(handle, bReturnAdditionalPreviews) end

---@param handle table
---@param bReturnTotalOnly boolean
---@return boolean
function UGC.SetReturnTotalOnly(handle, bReturnTotalOnly) end

---@param handle table
---@param unDays integer
---@return boolean
function UGC.SetReturnPlaytimeStats(handle, unDays) end

---@param handle table
---@param pchLanguage string
---@return boolean
function UGC.SetLanguage(handle, pchLanguage) end

---@param handle table
---@param unMaxAgeSeconds integer
---@return boolean
function UGC.SetAllowCachedResponse(handle, unMaxAgeSeconds) end

---@param handle table
---@param bAdminQuery boolean
---@return boolean
function UGC.SetAdminQuery(handle, bAdminQuery) end

---@param handle table
---@param pMatchCloudFileName string
---@return boolean
function UGC.SetCloudFileNameFilter(handle, pMatchCloudFileName) end

---@param handle table
---@param bMatchAnyTag boolean
---@return boolean
function UGC.SetMatchAnyTag(handle, bMatchAnyTag) end

---@param handle table
---@param pSearchText string
---@return boolean
function UGC.SetSearchText(handle, pSearchText) end

---@param handle table
---@param unDays integer
---@return boolean
function UGC.SetRankedByTrendDays(handle, unDays) end

---@param handle table
---@param rtStart integer
---@param rtEnd integer
---@return boolean
function UGC.SetTimeCreatedDateRange(handle, rtStart, rtEnd) end

---@param handle table
---@param rtStart integer
---@param rtEnd integer
---@return boolean
function UGC.SetTimeUpdatedDateRange(handle, rtStart, rtEnd) end

---@param handle table
---@param pKey string
---@param pValue string
---@return boolean
function UGC.AddRequiredKeyValueTag(handle, pKey, pValue) end

---@param nPublishedFileID table
---@param unMaxAgeSeconds integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function UGC.RequestUGCDetails(nPublishedFileID, unMaxAgeSeconds, callback) end

---@param nConsumerAppId integer
---@param eFileType integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function UGC.CreateItem(nConsumerAppId, eFileType, callback) end

---@param nConsumerAppId integer
---@param nPublishedFileID table
---@return table
function UGC.StartItemUpdate(nConsumerAppId, nPublishedFileID) end

---@param handle table
---@param pchTitle string
---@return boolean
function UGC.SetItemTitle(handle, pchTitle) end

---@param handle table
---@param pchDescription string
---@return boolean
function UGC.SetItemDescription(handle, pchDescription) end

---@param handle table
---@param pchLanguage string
---@return boolean
function UGC.SetItemUpdateLanguage(handle, pchLanguage) end

---@param handle table
---@param pchMetaData string
---@return boolean
function UGC.SetItemMetadata(handle, pchMetaData) end

---@param handle table
---@param eVisibility integer
---@return boolean
function UGC.SetItemVisibility(handle, eVisibility) end

---@param handle table
---@param pszContentFolder string
---@return boolean
function UGC.SetItemContent(handle, pszContentFolder) end

---@param handle table
---@param pszPreviewFile string
---@return boolean
function UGC.SetItemPreview(handle, pszPreviewFile) end

---@param handle table
---@param bAllowLegacyUpload boolean
---@return boolean
function UGC.SetAllowLegacyUpload(handle, bAllowLegacyUpload) end

---@param handle table
---@return boolean
function UGC.RemoveAllItemKeyValueTags(handle) end

---@param handle table
---@param pchKey string
---@return boolean
function UGC.RemoveItemKeyValueTags(handle, pchKey) end

---@param handle table
---@param pchKey string
---@param pchValue string
---@return boolean
function UGC.AddItemKeyValueTag(handle, pchKey, pchValue) end

---@param handle table
---@param pszPreviewFile string
---@param type integer
---@return boolean
function UGC.AddItemPreviewFile(handle, pszPreviewFile, type) end

---@param handle table
---@param pszVideoID string
---@return boolean
function UGC.AddItemPreviewVideo(handle, pszVideoID) end

---@param handle table
---@param index integer
---@param pszPreviewFile string
---@return boolean
function UGC.UpdateItemPreviewFile(handle, index, pszPreviewFile) end

---@param handle table
---@param index integer
---@param pszVideoID string
---@return boolean
function UGC.UpdateItemPreviewVideo(handle, index, pszVideoID) end

---@param handle table
---@param index integer
---@return boolean
function UGC.RemoveItemPreview(handle, index) end

---@param handle table
---@param descid integer
---@return boolean
function UGC.AddContentDescriptor(handle, descid) end

---@param handle table
---@param descid integer
---@return boolean
function UGC.RemoveContentDescriptor(handle, descid) end

---@param handle table
---@param pszGameBranchMin string
---@param pszGameBranchMax string
---@return boolean
function UGC.SetRequiredGameVersions(handle, pszGameBranchMin, pszGameBranchMax) end

---@param handle table
---@param pchChangeNote string
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function UGC.SubmitItemUpdate(handle, pchChangeNote, callback) end

---@param handle table
---@return integer
---@return table
---@return table
function UGC.GetItemUpdateProgress(handle) end

---@param nPublishedFileID table
---@param bVoteUp boolean
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function UGC.SetUserItemVote(nPublishedFileID, bVoteUp, callback) end

---@param nPublishedFileID table
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function UGC.GetUserItemVote(nPublishedFileID, callback) end

---@param nAppId integer
---@param nPublishedFileID table
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function UGC.AddItemToFavorites(nAppId, nPublishedFileID, callback) end

---@param nAppId integer
---@param nPublishedFileID table
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function UGC.RemoveItemFromFavorites(nAppId, nPublishedFileID, callback) end

---@param nPublishedFileID table
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function UGC.SubscribeItem(nPublishedFileID, callback) end

---@param nPublishedFileID table
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function UGC.UnsubscribeItem(nPublishedFileID, callback) end

---@param bIncludeLocallyDisabled boolean
---@return integer
function UGC.GetNumSubscribedItems(bIncludeLocallyDisabled) end

---@param cMaxEntries integer
---@param bIncludeLocallyDisabled boolean
---@return integer
---@return table
function UGC.GetSubscribedItems(cMaxEntries, bIncludeLocallyDisabled) end

---@param nPublishedFileID table
---@return integer
function UGC.GetItemState(nPublishedFileID) end

---@param nPublishedFileID table
---@param pchFolder string
---@param cchFolderSize integer
---@return boolean
---@return table
---@return integer
function UGC.GetItemInstallInfo(nPublishedFileID, pchFolder, cchFolderSize) end

---@param nPublishedFileID table
---@return boolean
---@return table
---@return table
function UGC.GetItemDownloadInfo(nPublishedFileID) end

---@param nPublishedFileID table
---@param bHighPriority boolean
---@return boolean
function UGC.DownloadItem(nPublishedFileID, bHighPriority) end

---@param unWorkshopDepotID integer
---@param pszFolder string
---@return boolean
function UGC.BInitWorkshopForGameServer(unWorkshopDepotID, pszFolder) end

---@param bSuspend boolean
function UGC.SuspendDownloads(bSuspend) end

---@param unNumPublishedFileIDs integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
---@return table
function UGC.StartPlaytimeTracking(unNumPublishedFileIDs, callback) end

---@param unNumPublishedFileIDs integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
---@return table
function UGC.StopPlaytimeTracking(unNumPublishedFileIDs, callback) end

---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function UGC.StopPlaytimeTrackingForAllItems(callback) end

---@param nParentPublishedFileID table
---@param nChildPublishedFileID table
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function UGC.AddDependency(nParentPublishedFileID, nChildPublishedFileID, callback) end

---@param nParentPublishedFileID table
---@param nChildPublishedFileID table
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function UGC.RemoveDependency(nParentPublishedFileID, nChildPublishedFileID, callback) end

---@param nPublishedFileID table
---@param nAppID integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function UGC.AddAppDependency(nPublishedFileID, nAppID, callback) end

---@param nPublishedFileID table
---@param nAppID integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function UGC.RemoveAppDependency(nPublishedFileID, nAppID, callback) end

---@param nPublishedFileID table
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function UGC.GetAppDependencies(nPublishedFileID, callback) end

---@param nPublishedFileID table
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function UGC.DeleteItem(nPublishedFileID, callback) end

---@return boolean
function UGC.ShowWorkshopEULA() end

---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function UGC.GetWorkshopEULAStatus(callback) end

---@param cMaxEntries integer
---@return integer
---@return integer
function UGC.GetUserContentDescriptorPreferences(cMaxEntries) end

---@param unNumPublishedFileIDs integer
---@param bDisabledLocally boolean
---@return boolean
---@return table
function UGC.SetItemsDisabledLocally(unNumPublishedFileIDs, bDisabledLocally) end

---@param unNumPublishedFileIDs integer
---@return boolean
---@return table
function UGC.SetSubscriptionsLoadOrder(unNumPublishedFileIDs) end

Steam.UGC = UGC
