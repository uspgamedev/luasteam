#########
ISteamUGC
#########

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✋ require manual implementation.

List of Functions
-----------------

* :func:`UGC.CreateQueryUserUGCRequest`
* :func:`UGC.CreateQueryAllUGCRequestPage`
* :func:`UGC.CreateQueryUGCDetailsRequest`
* :func:`UGC.SendQueryUGCRequest`
* :func:`UGC.GetQueryUGCResult`
* :func:`UGC.GetQueryUGCNumTags`
* :func:`UGC.GetQueryUGCTag`
* :func:`UGC.GetQueryUGCTagDisplayName`
* :func:`UGC.GetQueryUGCPreviewURL`
* :func:`UGC.GetQueryUGCMetadata`
* :func:`UGC.GetQueryUGCChildren`
* :func:`UGC.GetQueryUGCStatistic`
* :func:`UGC.GetQueryUGCNumAdditionalPreviews`
* :func:`UGC.GetQueryUGCAdditionalPreview`
* :func:`UGC.GetQueryUGCNumKeyValueTags`
* :func:`UGC.GetQueryUGCKeyValueTag`
* :func:`UGC.GetNumSupportedGameVersions`
* :func:`UGC.GetSupportedGameVersionData`
* :func:`UGC.GetQueryUGCContentDescriptors`
* :func:`UGC.ReleaseQueryUGCRequest`
* :func:`UGC.AddRequiredTag`
* :func:`UGC.AddRequiredTagGroup`
* :func:`UGC.AddExcludedTag`
* :func:`UGC.SetReturnOnlyIDs`
* :func:`UGC.SetReturnKeyValueTags`
* :func:`UGC.SetReturnLongDescription`
* :func:`UGC.SetReturnMetadata`
* :func:`UGC.SetReturnChildren`
* :func:`UGC.SetReturnAdditionalPreviews`
* :func:`UGC.SetReturnTotalOnly`
* :func:`UGC.SetReturnPlaytimeStats`
* :func:`UGC.SetLanguage`
* :func:`UGC.SetAllowCachedResponse`
* :func:`UGC.SetAdminQuery`
* :func:`UGC.SetCloudFileNameFilter`
* :func:`UGC.SetMatchAnyTag`
* :func:`UGC.SetSearchText`
* :func:`UGC.SetRankedByTrendDays`
* :func:`UGC.SetTimeCreatedDateRange`
* :func:`UGC.SetTimeUpdatedDateRange`
* :func:`UGC.AddRequiredKeyValueTag`
* :func:`UGC.RequestUGCDetails`
* :func:`UGC.CreateItem`
* :func:`UGC.StartItemUpdate`
* :func:`UGC.SetItemTitle`
* :func:`UGC.SetItemDescription`
* :func:`UGC.SetItemUpdateLanguage`
* :func:`UGC.SetItemMetadata`
* :func:`UGC.SetItemVisibility`
* :func:`UGC.SetItemTags`
* :func:`UGC.SetItemContent`
* :func:`UGC.SetItemPreview`
* :func:`UGC.SetAllowLegacyUpload`
* :func:`UGC.RemoveAllItemKeyValueTags`
* :func:`UGC.RemoveItemKeyValueTags`
* :func:`UGC.AddItemKeyValueTag`
* :func:`UGC.AddItemPreviewFile`
* :func:`UGC.AddItemPreviewVideo`
* :func:`UGC.UpdateItemPreviewFile`
* :func:`UGC.UpdateItemPreviewVideo`
* :func:`UGC.RemoveItemPreview`
* :func:`UGC.AddContentDescriptor`
* :func:`UGC.RemoveContentDescriptor`
* :func:`UGC.SetRequiredGameVersions`
* :func:`UGC.SubmitItemUpdate`
* :func:`UGC.GetItemUpdateProgress`
* :func:`UGC.SetUserItemVote`
* :func:`UGC.GetUserItemVote`
* :func:`UGC.AddItemToFavorites`
* :func:`UGC.RemoveItemFromFavorites`
* :func:`UGC.SubscribeItem`
* :func:`UGC.UnsubscribeItem`
* :func:`UGC.GetNumSubscribedItems`
* :func:`UGC.GetSubscribedItems`
* :func:`UGC.GetItemState`
* :func:`UGC.GetItemInstallInfo`
* :func:`UGC.GetItemDownloadInfo`
* :func:`UGC.DownloadItem`
* :func:`UGC.BInitWorkshopForGameServer`
* :func:`UGC.SuspendDownloads`
* :func:`UGC.StartPlaytimeTracking`
* :func:`UGC.StopPlaytimeTracking`
* :func:`UGC.StopPlaytimeTrackingForAllItems`
* :func:`UGC.AddDependency`
* :func:`UGC.RemoveDependency`
* :func:`UGC.AddAppDependency`
* :func:`UGC.RemoveAppDependency`
* :func:`UGC.GetAppDependencies`
* :func:`UGC.DeleteItem`
* :func:`UGC.ShowWorkshopEULA`
* :func:`UGC.GetWorkshopEULAStatus`
* :func:`UGC.GetUserContentDescriptorPreferences`
* :func:`UGC.SetItemsDisabledLocally`
* :func:`UGC.SetSubscriptionsLoadOrder`

List of Callbacks
-----------------

* :func:`UGC.onSteamUGCQueryCompleted`
* :func:`UGC.onSteamUGCRequestUGCDetailsResult`
* :func:`UGC.onCreateItemResult`
* :func:`UGC.onSubmitItemUpdateResult`
* :func:`UGC.onItemInstalled`
* :func:`UGC.onDownloadItemResult`
* :func:`UGC.onUserFavoriteItemsListChanged`
* :func:`UGC.onSetUserItemVoteResult`
* :func:`UGC.onGetUserItemVoteResult`
* :func:`UGC.onStartPlaytimeTrackingResult`
* :func:`UGC.onStopPlaytimeTrackingResult`
* :func:`UGC.onAddUGCDependencyResult`
* :func:`UGC.onRemoveUGCDependencyResult`
* :func:`UGC.onAddAppDependencyResult`
* :func:`UGC.onRemoveAppDependencyResult`
* :func:`UGC.onGetAppDependenciesResult`
* :func:`UGC.onDeleteItemResult`
* :func:`UGC.onUserSubscribedItemsListChanged`
* :func:`UGC.onWorkshopEULAStatus`

Function Reference
------------------

.. function:: UGC.CreateQueryUserUGCRequest(unAccountID, eListType, eMatchingUGCType, eSortOrder, nCreatorAppID, nConsumerAppID, unPage)

    🤖 **Auto-generated binding**

    :param int unAccountID:
    :param int eListType:
    :param int eMatchingUGCType:
    :param int eSortOrder:
    :param int nCreatorAppID:
    :param int nConsumerAppID:
    :param int unPage:
    :returns: (uint64) Return value
    :SteamWorks: `CreateQueryUserUGCRequest <https://partner.steamgames.com/doc/api/ISteamUGC#CreateQueryUserUGCRequest>`_

.. function:: UGC.CreateQueryAllUGCRequestPage(eQueryType, eMatchingeMatchingUGCTypeFileType, nCreatorAppID, nConsumerAppID, unPage)

    🤖 **Auto-generated binding**

    :param int eQueryType:
    :param int eMatchingeMatchingUGCTypeFileType:
    :param int nCreatorAppID:
    :param int nConsumerAppID:
    :param int unPage:
    :returns: (uint64) Return value
    :SteamWorks: `CreateQueryAllUGCRequestPage <https://partner.steamgames.com/doc/api/ISteamUGC#CreateQueryAllUGCRequestPage>`_

.. function:: UGC.CreateQueryUGCDetailsRequest(unNumPublishedFileIDs)

    🤖 **Auto-generated binding**

    :param int unNumPublishedFileIDs:
    :returns: (uint64) Return value
    :returns: (uint64) Value for `pvecPublishedFileID`
    :SteamWorks: `CreateQueryUGCDetailsRequest <https://partner.steamgames.com/doc/api/ISteamUGC#CreateQueryUGCDetailsRequest>`_

    **Signature differences from C++ API:**

    * Parameter ``pvecPublishedFileID`` is returned as an additional return value

.. function:: UGC.SendQueryUGCRequest(handle, callback)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param function callback: CallResult callback receiving struct `SteamUGCQueryCompleted_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `SendQueryUGCRequest <https://partner.steamgames.com/doc/api/ISteamUGC#SendQueryUGCRequest>`_

.. function:: UGC.GetQueryUGCResult(handle, index)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int index:
    :returns: (bool) Return value
    :returns: (:ref:`SteamUGCDetails_t <struct-SteamUGCDetails_t>`) Value for `pDetails`
    :SteamWorks: `GetQueryUGCResult <https://partner.steamgames.com/doc/api/ISteamUGC#GetQueryUGCResult>`_

    **Signature differences from C++ API:**

    * Parameter ``pDetails`` is returned as an additional return value

.. function:: UGC.GetQueryUGCNumTags(handle, index)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int index:
    :returns: (int) Return value
    :SteamWorks: `GetQueryUGCNumTags <https://partner.steamgames.com/doc/api/ISteamUGC#GetQueryUGCNumTags>`_

.. function:: UGC.GetQueryUGCTag(handle, index, indexTag, cchValueSize)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int index:
    :param int indexTag:
    :param int cchValueSize:
    :returns: (bool) Return value
    :returns: (str) Value for `pchValue`
    :SteamWorks: `GetQueryUGCTag <https://partner.steamgames.com/doc/api/ISteamUGC#GetQueryUGCTag>`_

    **Signature differences from C++ API:**

    * Parameter ``pchValue`` is returned as an additional return value

.. function:: UGC.GetQueryUGCTagDisplayName(handle, index, indexTag, cchValueSize)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int index:
    :param int indexTag:
    :param int cchValueSize:
    :returns: (bool) Return value
    :returns: (str) Value for `pchValue`
    :SteamWorks: `GetQueryUGCTagDisplayName <https://partner.steamgames.com/doc/api/ISteamUGC#GetQueryUGCTagDisplayName>`_

    **Signature differences from C++ API:**

    * Parameter ``pchValue`` is returned as an additional return value

.. function:: UGC.GetQueryUGCPreviewURL(handle, index, cchURLSize)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int index:
    :param int cchURLSize:
    :returns: (bool) Return value
    :returns: (str) Value for `pchURL`
    :SteamWorks: `GetQueryUGCPreviewURL <https://partner.steamgames.com/doc/api/ISteamUGC#GetQueryUGCPreviewURL>`_

    **Signature differences from C++ API:**

    * Parameter ``pchURL`` is returned as an additional return value

.. function:: UGC.GetQueryUGCMetadata(handle, index, cchMetadatasize)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int index:
    :param int cchMetadatasize:
    :returns: (bool) Return value
    :returns: (str) Value for `pchMetadata`
    :SteamWorks: `GetQueryUGCMetadata <https://partner.steamgames.com/doc/api/ISteamUGC#GetQueryUGCMetadata>`_

    **Signature differences from C++ API:**

    * Parameter ``pchMetadata`` is returned as an additional return value

.. function:: UGC.GetQueryUGCChildren(handle, index, cMaxEntries)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int index:
    :param int cMaxEntries:
    :returns: (bool) Return value
    :returns: (uint64) Value for `pvecPublishedFileID`
    :SteamWorks: `GetQueryUGCChildren <https://partner.steamgames.com/doc/api/ISteamUGC#GetQueryUGCChildren>`_

    **Signature differences from C++ API:**

    * Parameter ``pvecPublishedFileID`` is returned as an additional return value

.. function:: UGC.GetQueryUGCStatistic(handle, index, eStatType)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int index:
    :param int eStatType:
    :returns: (bool) Return value
    :returns: (uint64) Value for `pStatValue`
    :SteamWorks: `GetQueryUGCStatistic <https://partner.steamgames.com/doc/api/ISteamUGC#GetQueryUGCStatistic>`_

    **Signature differences from C++ API:**

    * Parameter ``pStatValue`` is returned as an additional return value

.. function:: UGC.GetQueryUGCNumAdditionalPreviews(handle, index)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int index:
    :returns: (int) Return value
    :SteamWorks: `GetQueryUGCNumAdditionalPreviews <https://partner.steamgames.com/doc/api/ISteamUGC#GetQueryUGCNumAdditionalPreviews>`_

.. function:: UGC.GetQueryUGCAdditionalPreview(handle, index, previewIndex, cchURLSize, cchOriginalFileNameSize)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int index:
    :param int previewIndex:
    :param int cchURLSize:
    :param int cchOriginalFileNameSize:
    :returns: (bool) Return value
    :returns: (str) Value for `pchURLOrVideoID`
    :returns: (str) Value for `pchOriginalFileName`
    :returns: (int) Value for `pPreviewType`
    :SteamWorks: `GetQueryUGCAdditionalPreview <https://partner.steamgames.com/doc/api/ISteamUGC#GetQueryUGCAdditionalPreview>`_

    **Signature differences from C++ API:**

    * Parameter ``pchURLOrVideoID`` is returned as an additional return value
    * Parameter ``pchOriginalFileName`` is returned as an additional return value
    * Parameter ``pPreviewType`` is returned as an additional return value

.. function:: UGC.GetQueryUGCNumKeyValueTags(handle, index)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int index:
    :returns: (int) Return value
    :SteamWorks: `GetQueryUGCNumKeyValueTags <https://partner.steamgames.com/doc/api/ISteamUGC#GetQueryUGCNumKeyValueTags>`_

.. function:: UGC.GetQueryUGCKeyValueTag(handle, index, keyValueTagIndex, cchKeySize, cchValueSize)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int index:
    :param int keyValueTagIndex:
    :param int cchKeySize:
    :param int cchValueSize:
    :returns: (bool) Return value
    :returns: (str) Value for `pchKey`
    :returns: (str) Value for `pchValue`
    :SteamWorks: `GetQueryUGCKeyValueTag <https://partner.steamgames.com/doc/api/ISteamUGC#GetQueryUGCKeyValueTag>`_

    **Signature differences from C++ API:**

    * Parameter ``pchKey`` is returned as an additional return value
    * Parameter ``pchValue`` is returned as an additional return value

.. function:: UGC.GetNumSupportedGameVersions(handle, index)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int index:
    :returns: (int) Return value
    :SteamWorks: `GetNumSupportedGameVersions <https://partner.steamgames.com/doc/api/ISteamUGC#GetNumSupportedGameVersions>`_

.. function:: UGC.GetSupportedGameVersionData(handle, index, versionIndex, cchGameBranchSize)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int index:
    :param int versionIndex:
    :param int cchGameBranchSize:
    :returns: (bool) Return value
    :returns: (str) Value for `pchGameBranchMin`
    :returns: (str) Value for `pchGameBranchMax`
    :SteamWorks: `GetSupportedGameVersionData <https://partner.steamgames.com/doc/api/ISteamUGC#GetSupportedGameVersionData>`_

    **Signature differences from C++ API:**

    * Parameter ``pchGameBranchMin`` is returned as an additional return value
    * Parameter ``pchGameBranchMax`` is returned as an additional return value

.. function:: UGC.GetQueryUGCContentDescriptors(handle, index, cMaxEntries)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int index:
    :param int cMaxEntries:
    :returns: (int) Return value
    :returns: (int) Value for `pvecDescriptors`
    :SteamWorks: `GetQueryUGCContentDescriptors <https://partner.steamgames.com/doc/api/ISteamUGC#GetQueryUGCContentDescriptors>`_

    **Signature differences from C++ API:**

    * Parameter ``pvecDescriptors`` is returned as an additional return value

.. function:: UGC.ReleaseQueryUGCRequest(handle)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :returns: (bool) Return value
    :SteamWorks: `ReleaseQueryUGCRequest <https://partner.steamgames.com/doc/api/ISteamUGC#ReleaseQueryUGCRequest>`_

.. function:: UGC.AddRequiredTag(handle, pTagName)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pTagName:
    :returns: (bool) Return value
    :SteamWorks: `AddRequiredTag <https://partner.steamgames.com/doc/api/ISteamUGC#AddRequiredTag>`_

.. function:: UGC.AddRequiredTagGroup(handle, pTagGroups)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param :ref:`SteamParamStringArray_t <struct-SteamParamStringArray_t>` pTagGroups:
    :returns: (bool) Return value
    :SteamWorks: `AddRequiredTagGroup <https://partner.steamgames.com/doc/api/ISteamUGC#AddRequiredTagGroup>`_

.. function:: UGC.AddExcludedTag(handle, pTagName)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pTagName:
    :returns: (bool) Return value
    :SteamWorks: `AddExcludedTag <https://partner.steamgames.com/doc/api/ISteamUGC#AddExcludedTag>`_

.. function:: UGC.SetReturnOnlyIDs(handle, bReturnOnlyIDs)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param bool bReturnOnlyIDs:
    :returns: (bool) Return value
    :SteamWorks: `SetReturnOnlyIDs <https://partner.steamgames.com/doc/api/ISteamUGC#SetReturnOnlyIDs>`_

.. function:: UGC.SetReturnKeyValueTags(handle, bReturnKeyValueTags)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param bool bReturnKeyValueTags:
    :returns: (bool) Return value
    :SteamWorks: `SetReturnKeyValueTags <https://partner.steamgames.com/doc/api/ISteamUGC#SetReturnKeyValueTags>`_

.. function:: UGC.SetReturnLongDescription(handle, bReturnLongDescription)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param bool bReturnLongDescription:
    :returns: (bool) Return value
    :SteamWorks: `SetReturnLongDescription <https://partner.steamgames.com/doc/api/ISteamUGC#SetReturnLongDescription>`_

.. function:: UGC.SetReturnMetadata(handle, bReturnMetadata)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param bool bReturnMetadata:
    :returns: (bool) Return value
    :SteamWorks: `SetReturnMetadata <https://partner.steamgames.com/doc/api/ISteamUGC#SetReturnMetadata>`_

.. function:: UGC.SetReturnChildren(handle, bReturnChildren)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param bool bReturnChildren:
    :returns: (bool) Return value
    :SteamWorks: `SetReturnChildren <https://partner.steamgames.com/doc/api/ISteamUGC#SetReturnChildren>`_

.. function:: UGC.SetReturnAdditionalPreviews(handle, bReturnAdditionalPreviews)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param bool bReturnAdditionalPreviews:
    :returns: (bool) Return value
    :SteamWorks: `SetReturnAdditionalPreviews <https://partner.steamgames.com/doc/api/ISteamUGC#SetReturnAdditionalPreviews>`_

.. function:: UGC.SetReturnTotalOnly(handle, bReturnTotalOnly)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param bool bReturnTotalOnly:
    :returns: (bool) Return value
    :SteamWorks: `SetReturnTotalOnly <https://partner.steamgames.com/doc/api/ISteamUGC#SetReturnTotalOnly>`_

.. function:: UGC.SetReturnPlaytimeStats(handle, unDays)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int unDays:
    :returns: (bool) Return value
    :SteamWorks: `SetReturnPlaytimeStats <https://partner.steamgames.com/doc/api/ISteamUGC#SetReturnPlaytimeStats>`_

.. function:: UGC.SetLanguage(handle, pchLanguage)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pchLanguage:
    :returns: (bool) Return value
    :SteamWorks: `SetLanguage <https://partner.steamgames.com/doc/api/ISteamUGC#SetLanguage>`_

.. function:: UGC.SetAllowCachedResponse(handle, unMaxAgeSeconds)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int unMaxAgeSeconds:
    :returns: (bool) Return value
    :SteamWorks: `SetAllowCachedResponse <https://partner.steamgames.com/doc/api/ISteamUGC#SetAllowCachedResponse>`_

.. function:: UGC.SetAdminQuery(handle, bAdminQuery)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param bool bAdminQuery:
    :returns: (bool) Return value
    :SteamWorks: `SetAdminQuery <https://partner.steamgames.com/doc/api/ISteamUGC#SetAdminQuery>`_

.. function:: UGC.SetCloudFileNameFilter(handle, pMatchCloudFileName)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pMatchCloudFileName:
    :returns: (bool) Return value
    :SteamWorks: `SetCloudFileNameFilter <https://partner.steamgames.com/doc/api/ISteamUGC#SetCloudFileNameFilter>`_

.. function:: UGC.SetMatchAnyTag(handle, bMatchAnyTag)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param bool bMatchAnyTag:
    :returns: (bool) Return value
    :SteamWorks: `SetMatchAnyTag <https://partner.steamgames.com/doc/api/ISteamUGC#SetMatchAnyTag>`_

.. function:: UGC.SetSearchText(handle, pSearchText)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pSearchText:
    :returns: (bool) Return value
    :SteamWorks: `SetSearchText <https://partner.steamgames.com/doc/api/ISteamUGC#SetSearchText>`_

.. function:: UGC.SetRankedByTrendDays(handle, unDays)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int unDays:
    :returns: (bool) Return value
    :SteamWorks: `SetRankedByTrendDays <https://partner.steamgames.com/doc/api/ISteamUGC#SetRankedByTrendDays>`_

.. function:: UGC.SetTimeCreatedDateRange(handle, rtStart, rtEnd)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int rtStart:
    :param int rtEnd:
    :returns: (bool) Return value
    :SteamWorks: `SetTimeCreatedDateRange <https://partner.steamgames.com/doc/api/ISteamUGC#SetTimeCreatedDateRange>`_

.. function:: UGC.SetTimeUpdatedDateRange(handle, rtStart, rtEnd)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int rtStart:
    :param int rtEnd:
    :returns: (bool) Return value
    :SteamWorks: `SetTimeUpdatedDateRange <https://partner.steamgames.com/doc/api/ISteamUGC#SetTimeUpdatedDateRange>`_

.. function:: UGC.AddRequiredKeyValueTag(handle, pKey, pValue)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pKey:
    :param str pValue:
    :returns: (bool) Return value
    :SteamWorks: `AddRequiredKeyValueTag <https://partner.steamgames.com/doc/api/ISteamUGC#AddRequiredKeyValueTag>`_

.. function:: UGC.RequestUGCDetails(nPublishedFileID, unMaxAgeSeconds, callback)

    🤖 **Auto-generated binding**

    :param uint64 nPublishedFileID:
    :param int unMaxAgeSeconds:
    :param function callback: CallResult callback receiving struct `SteamUGCRequestUGCDetailsResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `RequestUGCDetails <https://partner.steamgames.com/doc/api/ISteamUGC#RequestUGCDetails>`_

.. function:: UGC.CreateItem(nConsumerAppId, eFileType, callback)

    🤖 **Auto-generated binding**

    :param int nConsumerAppId:
    :param int eFileType:
    :param function callback: CallResult callback receiving struct `CreateItemResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `CreateItem <https://partner.steamgames.com/doc/api/ISteamUGC#CreateItem>`_

.. function:: UGC.StartItemUpdate(nConsumerAppId, nPublishedFileID)

    🤖 **Auto-generated binding**

    :param int nConsumerAppId:
    :param uint64 nPublishedFileID:
    :returns: (uint64) Return value
    :SteamWorks: `StartItemUpdate <https://partner.steamgames.com/doc/api/ISteamUGC#StartItemUpdate>`_

.. function:: UGC.SetItemTitle(handle, pchTitle)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pchTitle:
    :returns: (bool) Return value
    :SteamWorks: `SetItemTitle <https://partner.steamgames.com/doc/api/ISteamUGC#SetItemTitle>`_

.. function:: UGC.SetItemDescription(handle, pchDescription)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pchDescription:
    :returns: (bool) Return value
    :SteamWorks: `SetItemDescription <https://partner.steamgames.com/doc/api/ISteamUGC#SetItemDescription>`_

.. function:: UGC.SetItemUpdateLanguage(handle, pchLanguage)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pchLanguage:
    :returns: (bool) Return value
    :SteamWorks: `SetItemUpdateLanguage <https://partner.steamgames.com/doc/api/ISteamUGC#SetItemUpdateLanguage>`_

.. function:: UGC.SetItemMetadata(handle, pchMetaData)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pchMetaData:
    :returns: (bool) Return value
    :SteamWorks: `SetItemMetadata <https://partner.steamgames.com/doc/api/ISteamUGC#SetItemMetadata>`_

.. function:: UGC.SetItemVisibility(handle, eVisibility)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int eVisibility:
    :returns: (bool) Return value
    :SteamWorks: `SetItemVisibility <https://partner.steamgames.com/doc/api/ISteamUGC#SetItemVisibility>`_

.. function:: UGC.SetItemTags(updateHandle, pTags, bAllowAdminTags)

    🤖 **Auto-generated binding**

    :param uint64 updateHandle:
    :param :ref:`SteamParamStringArray_t <struct-SteamParamStringArray_t>` pTags:
    :param bool bAllowAdminTags:
    :returns: (bool) Return value
    :SteamWorks: `SetItemTags <https://partner.steamgames.com/doc/api/ISteamUGC#SetItemTags>`_

.. function:: UGC.SetItemContent(handle, pszContentFolder)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pszContentFolder:
    :returns: (bool) Return value
    :SteamWorks: `SetItemContent <https://partner.steamgames.com/doc/api/ISteamUGC#SetItemContent>`_

.. function:: UGC.SetItemPreview(handle, pszPreviewFile)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pszPreviewFile:
    :returns: (bool) Return value
    :SteamWorks: `SetItemPreview <https://partner.steamgames.com/doc/api/ISteamUGC#SetItemPreview>`_

.. function:: UGC.SetAllowLegacyUpload(handle, bAllowLegacyUpload)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param bool bAllowLegacyUpload:
    :returns: (bool) Return value
    :SteamWorks: `SetAllowLegacyUpload <https://partner.steamgames.com/doc/api/ISteamUGC#SetAllowLegacyUpload>`_

.. function:: UGC.RemoveAllItemKeyValueTags(handle)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :returns: (bool) Return value
    :SteamWorks: `RemoveAllItemKeyValueTags <https://partner.steamgames.com/doc/api/ISteamUGC#RemoveAllItemKeyValueTags>`_

.. function:: UGC.RemoveItemKeyValueTags(handle, pchKey)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pchKey:
    :returns: (bool) Return value
    :SteamWorks: `RemoveItemKeyValueTags <https://partner.steamgames.com/doc/api/ISteamUGC#RemoveItemKeyValueTags>`_

.. function:: UGC.AddItemKeyValueTag(handle, pchKey, pchValue)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pchKey:
    :param str pchValue:
    :returns: (bool) Return value
    :SteamWorks: `AddItemKeyValueTag <https://partner.steamgames.com/doc/api/ISteamUGC#AddItemKeyValueTag>`_

.. function:: UGC.AddItemPreviewFile(handle, pszPreviewFile, type)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pszPreviewFile:
    :param int type:
    :returns: (bool) Return value
    :SteamWorks: `AddItemPreviewFile <https://partner.steamgames.com/doc/api/ISteamUGC#AddItemPreviewFile>`_

.. function:: UGC.AddItemPreviewVideo(handle, pszVideoID)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pszVideoID:
    :returns: (bool) Return value
    :SteamWorks: `AddItemPreviewVideo <https://partner.steamgames.com/doc/api/ISteamUGC#AddItemPreviewVideo>`_

.. function:: UGC.UpdateItemPreviewFile(handle, index, pszPreviewFile)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int index:
    :param str pszPreviewFile:
    :returns: (bool) Return value
    :SteamWorks: `UpdateItemPreviewFile <https://partner.steamgames.com/doc/api/ISteamUGC#UpdateItemPreviewFile>`_

.. function:: UGC.UpdateItemPreviewVideo(handle, index, pszVideoID)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int index:
    :param str pszVideoID:
    :returns: (bool) Return value
    :SteamWorks: `UpdateItemPreviewVideo <https://partner.steamgames.com/doc/api/ISteamUGC#UpdateItemPreviewVideo>`_

.. function:: UGC.RemoveItemPreview(handle, index)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int index:
    :returns: (bool) Return value
    :SteamWorks: `RemoveItemPreview <https://partner.steamgames.com/doc/api/ISteamUGC#RemoveItemPreview>`_

.. function:: UGC.AddContentDescriptor(handle, descid)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int descid:
    :returns: (bool) Return value
    :SteamWorks: `AddContentDescriptor <https://partner.steamgames.com/doc/api/ISteamUGC#AddContentDescriptor>`_

.. function:: UGC.RemoveContentDescriptor(handle, descid)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int descid:
    :returns: (bool) Return value
    :SteamWorks: `RemoveContentDescriptor <https://partner.steamgames.com/doc/api/ISteamUGC#RemoveContentDescriptor>`_

.. function:: UGC.SetRequiredGameVersions(handle, pszGameBranchMin, pszGameBranchMax)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pszGameBranchMin:
    :param str pszGameBranchMax:
    :returns: (bool) Return value
    :SteamWorks: `SetRequiredGameVersions <https://partner.steamgames.com/doc/api/ISteamUGC#SetRequiredGameVersions>`_

.. function:: UGC.SubmitItemUpdate(handle, pchChangeNote, callback)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pchChangeNote:
    :param function callback: CallResult callback receiving struct `SubmitItemUpdateResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `SubmitItemUpdate <https://partner.steamgames.com/doc/api/ISteamUGC#SubmitItemUpdate>`_

.. function:: UGC.GetItemUpdateProgress(handle)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :returns: (int) Return value
    :returns: (uint64) Value for `punBytesProcessed`
    :returns: (uint64) Value for `punBytesTotal`
    :SteamWorks: `GetItemUpdateProgress <https://partner.steamgames.com/doc/api/ISteamUGC#GetItemUpdateProgress>`_

    **Signature differences from C++ API:**

    * Parameter ``punBytesProcessed`` is returned as an additional return value
    * Parameter ``punBytesTotal`` is returned as an additional return value

.. function:: UGC.SetUserItemVote(nPublishedFileID, bVoteUp, callback)

    🤖 **Auto-generated binding**

    :param uint64 nPublishedFileID:
    :param bool bVoteUp:
    :param function callback: CallResult callback receiving struct `SetUserItemVoteResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `SetUserItemVote <https://partner.steamgames.com/doc/api/ISteamUGC#SetUserItemVote>`_

.. function:: UGC.GetUserItemVote(nPublishedFileID, callback)

    🤖 **Auto-generated binding**

    :param uint64 nPublishedFileID:
    :param function callback: CallResult callback receiving struct `GetUserItemVoteResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `GetUserItemVote <https://partner.steamgames.com/doc/api/ISteamUGC#GetUserItemVote>`_

.. function:: UGC.AddItemToFavorites(nAppId, nPublishedFileID, callback)

    🤖 **Auto-generated binding**

    :param int nAppId:
    :param uint64 nPublishedFileID:
    :param function callback: CallResult callback receiving struct `UserFavoriteItemsListChanged_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `AddItemToFavorites <https://partner.steamgames.com/doc/api/ISteamUGC#AddItemToFavorites>`_

.. function:: UGC.RemoveItemFromFavorites(nAppId, nPublishedFileID, callback)

    🤖 **Auto-generated binding**

    :param int nAppId:
    :param uint64 nPublishedFileID:
    :param function callback: CallResult callback receiving struct `UserFavoriteItemsListChanged_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `RemoveItemFromFavorites <https://partner.steamgames.com/doc/api/ISteamUGC#RemoveItemFromFavorites>`_

.. function:: UGC.SubscribeItem(nPublishedFileID, callback)

    🤖 **Auto-generated binding**

    :param uint64 nPublishedFileID:
    :param function callback: CallResult callback receiving struct `RemoteStorageSubscribePublishedFileResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `SubscribeItem <https://partner.steamgames.com/doc/api/ISteamUGC#SubscribeItem>`_

.. function:: UGC.UnsubscribeItem(nPublishedFileID, callback)

    🤖 **Auto-generated binding**

    :param uint64 nPublishedFileID:
    :param function callback: CallResult callback receiving struct `RemoteStorageUnsubscribePublishedFileResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `UnsubscribeItem <https://partner.steamgames.com/doc/api/ISteamUGC#UnsubscribeItem>`_

.. function:: UGC.GetNumSubscribedItems(bIncludeLocallyDisabled)

    🤖 **Auto-generated binding**

    :param bool bIncludeLocallyDisabled:
    :returns: (int) Return value
    :SteamWorks: `GetNumSubscribedItems <https://partner.steamgames.com/doc/api/ISteamUGC#GetNumSubscribedItems>`_

.. function:: UGC.GetSubscribedItems(cMaxEntries, bIncludeLocallyDisabled)

    🤖 **Auto-generated binding**

    :param int cMaxEntries:
    :param bool bIncludeLocallyDisabled:
    :returns: (int) Return value
    :returns: (uint64[]) Value for `pvecPublishedFileID`
    :SteamWorks: `GetSubscribedItems <https://partner.steamgames.com/doc/api/ISteamUGC#GetSubscribedItems>`_

    **Signature differences from C++ API:**

    * Parameter ``pvecPublishedFileID`` is returned as an additional return value

.. function:: UGC.GetItemState(nPublishedFileID)

    🤖 **Auto-generated binding**

    :param uint64 nPublishedFileID:
    :returns: (int) Return value
    :SteamWorks: `GetItemState <https://partner.steamgames.com/doc/api/ISteamUGC#GetItemState>`_

.. function:: UGC.GetItemInstallInfo(nPublishedFileID, cchFolderSize)

    🤖 **Auto-generated binding**

    :param uint64 nPublishedFileID:
    :param int cchFolderSize:
    :returns: (bool) Return value
    :returns: (uint64) Value for `punSizeOnDisk`
    :returns: (str) Value for `pchFolder`
    :returns: (int) Value for `punTimeStamp`
    :SteamWorks: `GetItemInstallInfo <https://partner.steamgames.com/doc/api/ISteamUGC#GetItemInstallInfo>`_

    **Signature differences from C++ API:**

    * Parameter ``punSizeOnDisk`` is returned as an additional return value
    * Parameter ``pchFolder`` is returned as an additional return value
    * Parameter ``punTimeStamp`` is returned as an additional return value

.. function:: UGC.GetItemDownloadInfo(nPublishedFileID)

    🤖 **Auto-generated binding**

    :param uint64 nPublishedFileID:
    :returns: (bool) Return value
    :returns: (uint64) Value for `punBytesDownloaded`
    :returns: (uint64) Value for `punBytesTotal`
    :SteamWorks: `GetItemDownloadInfo <https://partner.steamgames.com/doc/api/ISteamUGC#GetItemDownloadInfo>`_

    **Signature differences from C++ API:**

    * Parameter ``punBytesDownloaded`` is returned as an additional return value
    * Parameter ``punBytesTotal`` is returned as an additional return value

.. function:: UGC.DownloadItem(nPublishedFileID, bHighPriority)

    🤖 **Auto-generated binding**

    :param uint64 nPublishedFileID:
    :param bool bHighPriority:
    :returns: (bool) Return value
    :SteamWorks: `DownloadItem <https://partner.steamgames.com/doc/api/ISteamUGC#DownloadItem>`_

.. function:: UGC.BInitWorkshopForGameServer(unWorkshopDepotID, pszFolder)

    🤖 **Auto-generated binding**

    :param int unWorkshopDepotID:
    :param str pszFolder:
    :returns: (bool) Return value
    :SteamWorks: `BInitWorkshopForGameServer <https://partner.steamgames.com/doc/api/ISteamUGC#BInitWorkshopForGameServer>`_

.. function:: UGC.SuspendDownloads(bSuspend)

    🤖 **Auto-generated binding**

    :param bool bSuspend:
    :SteamWorks: `SuspendDownloads <https://partner.steamgames.com/doc/api/ISteamUGC#SuspendDownloads>`_

.. function:: UGC.StartPlaytimeTracking(pvecPublishedFileID, unNumPublishedFileIDs, callback)

    🤖 **Auto-generated binding**

    :param uint64[] pvecPublishedFileID:
    :param int unNumPublishedFileIDs:
    :param function callback: CallResult callback receiving struct `StartPlaytimeTrackingResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `StartPlaytimeTracking <https://partner.steamgames.com/doc/api/ISteamUGC#StartPlaytimeTracking>`_

.. function:: UGC.StopPlaytimeTracking(pvecPublishedFileID, unNumPublishedFileIDs, callback)

    🤖 **Auto-generated binding**

    :param uint64[] pvecPublishedFileID:
    :param int unNumPublishedFileIDs:
    :param function callback: CallResult callback receiving struct `StopPlaytimeTrackingResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `StopPlaytimeTracking <https://partner.steamgames.com/doc/api/ISteamUGC#StopPlaytimeTracking>`_

.. function:: UGC.StopPlaytimeTrackingForAllItems(callback)

    🤖 **Auto-generated binding**

    :param function callback: CallResult callback receiving struct `StopPlaytimeTrackingResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `StopPlaytimeTrackingForAllItems <https://partner.steamgames.com/doc/api/ISteamUGC#StopPlaytimeTrackingForAllItems>`_

.. function:: UGC.AddDependency(nParentPublishedFileID, nChildPublishedFileID, callback)

    🤖 **Auto-generated binding**

    :param uint64 nParentPublishedFileID:
    :param uint64 nChildPublishedFileID:
    :param function callback: CallResult callback receiving struct `AddUGCDependencyResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `AddDependency <https://partner.steamgames.com/doc/api/ISteamUGC#AddDependency>`_

.. function:: UGC.RemoveDependency(nParentPublishedFileID, nChildPublishedFileID, callback)

    🤖 **Auto-generated binding**

    :param uint64 nParentPublishedFileID:
    :param uint64 nChildPublishedFileID:
    :param function callback: CallResult callback receiving struct `RemoveUGCDependencyResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `RemoveDependency <https://partner.steamgames.com/doc/api/ISteamUGC#RemoveDependency>`_

.. function:: UGC.AddAppDependency(nPublishedFileID, nAppID, callback)

    🤖 **Auto-generated binding**

    :param uint64 nPublishedFileID:
    :param int nAppID:
    :param function callback: CallResult callback receiving struct `AddAppDependencyResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `AddAppDependency <https://partner.steamgames.com/doc/api/ISteamUGC#AddAppDependency>`_

.. function:: UGC.RemoveAppDependency(nPublishedFileID, nAppID, callback)

    🤖 **Auto-generated binding**

    :param uint64 nPublishedFileID:
    :param int nAppID:
    :param function callback: CallResult callback receiving struct `RemoveAppDependencyResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `RemoveAppDependency <https://partner.steamgames.com/doc/api/ISteamUGC#RemoveAppDependency>`_

.. function:: UGC.GetAppDependencies(nPublishedFileID, callback)

    🤖 **Auto-generated binding**

    :param uint64 nPublishedFileID:
    :param function callback: CallResult callback receiving struct `GetAppDependenciesResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `GetAppDependencies <https://partner.steamgames.com/doc/api/ISteamUGC#GetAppDependencies>`_

.. function:: UGC.DeleteItem(nPublishedFileID, callback)

    🤖 **Auto-generated binding**

    :param uint64 nPublishedFileID:
    :param function callback: CallResult callback receiving struct `DeleteItemResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `DeleteItem <https://partner.steamgames.com/doc/api/ISteamUGC#DeleteItem>`_

.. function:: UGC.ShowWorkshopEULA()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `ShowWorkshopEULA <https://partner.steamgames.com/doc/api/ISteamUGC#ShowWorkshopEULA>`_

.. function:: UGC.GetWorkshopEULAStatus(callback)

    🤖 **Auto-generated binding**

    :param function callback: CallResult callback receiving struct `WorkshopEULAStatus_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `GetWorkshopEULAStatus <https://partner.steamgames.com/doc/api/ISteamUGC#GetWorkshopEULAStatus>`_

.. function:: UGC.GetUserContentDescriptorPreferences(cMaxEntries)

    🤖 **Auto-generated binding**

    :param int cMaxEntries:
    :returns: (int) Return value
    :returns: (int) Value for `pvecDescriptors`
    :SteamWorks: `GetUserContentDescriptorPreferences <https://partner.steamgames.com/doc/api/ISteamUGC#GetUserContentDescriptorPreferences>`_

    **Signature differences from C++ API:**

    * Parameter ``pvecDescriptors`` is returned as an additional return value

.. function:: UGC.SetItemsDisabledLocally(unNumPublishedFileIDs, bDisabledLocally)

    🤖 **Auto-generated binding**

    :param int unNumPublishedFileIDs:
    :param bool bDisabledLocally:
    :returns: (bool) Return value
    :returns: (uint64) Value for `pvecPublishedFileIDs`
    :SteamWorks: `SetItemsDisabledLocally <https://partner.steamgames.com/doc/api/ISteamUGC#SetItemsDisabledLocally>`_

    **Signature differences from C++ API:**

    * Parameter ``pvecPublishedFileIDs`` is returned as an additional return value

.. function:: UGC.SetSubscriptionsLoadOrder(unNumPublishedFileIDs)

    🤖 **Auto-generated binding**

    :param int unNumPublishedFileIDs:
    :returns: (bool) Return value
    :returns: (uint64) Value for `pvecPublishedFileIDs`
    :SteamWorks: `SetSubscriptionsLoadOrder <https://partner.steamgames.com/doc/api/ISteamUGC#SetSubscriptionsLoadOrder>`_

    **Signature differences from C++ API:**

    * Parameter ``pvecPublishedFileIDs`` is returned as an additional return value


Unimplemented Methods
---------------------

.. function:: UGC.createQueryAllUGCRequest

    ✋ **Not implemented** - manual: cursor method is not used
    
    :SteamWorks: `CreateQueryAllUGCRequest <https://partner.steamgames.com/doc/api/ISteamUGC#CreateQueryAllUGCRequest>`_

.. function:: UGC.getQueryUGCKeyValueTag

    ✋ **Not implemented** - manual: unused, not even in API Reference
    
    :SteamWorks: `GetQueryUGCKeyValueTag <https://partner.steamgames.com/doc/api/ISteamUGC#GetQueryUGCKeyValueTag>`_


Callbacks
---------

.. function:: UGC.onSteamUGCQueryCompleted

    Callback for `SteamUGCQueryCompleted_t <https://partner.steamgames.com/doc/api/ISteamUGC#SteamUGCQueryCompleted_t>`_

    **callback(data)** receives:

    * **data.m_handle** -- m_handle
    * **data.m_eResult** -- m_eResult
    * **data.m_unNumResultsReturned** -- m_unNumResultsReturned
    * **data.m_unTotalMatchingResults** -- m_unTotalMatchingResults
    * **data.m_bCachedData** -- m_bCachedData
    * **data.m_rgchNextCursor** -- m_rgchNextCursor

.. function:: UGC.onSteamUGCRequestUGCDetailsResult

    Callback for `SteamUGCRequestUGCDetailsResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#SteamUGCRequestUGCDetailsResult_t>`_

    **callback(data)** receives:

    * **data.m_details** -- m_details
    * **data.m_bCachedData** -- m_bCachedData

.. function:: UGC.onCreateItemResult

    Callback for `CreateItemResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#CreateItemResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_bUserNeedsToAcceptWorkshopLegalAgreement** -- m_bUserNeedsToAcceptWorkshopLegalAgreement

.. function:: UGC.onSubmitItemUpdateResult

    Callback for `SubmitItemUpdateResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#SubmitItemUpdateResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_bUserNeedsToAcceptWorkshopLegalAgreement** -- m_bUserNeedsToAcceptWorkshopLegalAgreement
    * **data.m_nPublishedFileId** -- m_nPublishedFileId

.. function:: UGC.onItemInstalled

    Callback for `ItemInstalled_t <https://partner.steamgames.com/doc/api/ISteamUGC#ItemInstalled_t>`_

    **callback(data)** receives:

    * **data.m_unAppID** -- m_unAppID
    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_hLegacyContent** -- m_hLegacyContent
    * **data.m_unManifestID** -- m_unManifestID

.. function:: UGC.onDownloadItemResult

    Callback for `DownloadItemResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#DownloadItemResult_t>`_

    **callback(data)** receives:

    * **data.m_unAppID** -- m_unAppID
    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_eResult** -- m_eResult

.. function:: UGC.onUserFavoriteItemsListChanged

    Callback for `UserFavoriteItemsListChanged_t <https://partner.steamgames.com/doc/api/ISteamUGC#UserFavoriteItemsListChanged_t>`_

    **callback(data)** receives:

    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_eResult** -- m_eResult
    * **data.m_bWasAddRequest** -- m_bWasAddRequest

.. function:: UGC.onSetUserItemVoteResult

    Callback for `SetUserItemVoteResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#SetUserItemVoteResult_t>`_

    **callback(data)** receives:

    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_eResult** -- m_eResult
    * **data.m_bVoteUp** -- m_bVoteUp

.. function:: UGC.onGetUserItemVoteResult

    Callback for `GetUserItemVoteResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#GetUserItemVoteResult_t>`_

    **callback(data)** receives:

    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_eResult** -- m_eResult
    * **data.m_bVotedUp** -- m_bVotedUp
    * **data.m_bVotedDown** -- m_bVotedDown
    * **data.m_bVoteSkipped** -- m_bVoteSkipped

.. function:: UGC.onStartPlaytimeTrackingResult

    Callback for `StartPlaytimeTrackingResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#StartPlaytimeTrackingResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult

.. function:: UGC.onStopPlaytimeTrackingResult

    Callback for `StopPlaytimeTrackingResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#StopPlaytimeTrackingResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult

.. function:: UGC.onAddUGCDependencyResult

    Callback for `AddUGCDependencyResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#AddUGCDependencyResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_nChildPublishedFileId** -- m_nChildPublishedFileId

.. function:: UGC.onRemoveUGCDependencyResult

    Callback for `RemoveUGCDependencyResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#RemoveUGCDependencyResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_nChildPublishedFileId** -- m_nChildPublishedFileId

.. function:: UGC.onAddAppDependencyResult

    Callback for `AddAppDependencyResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#AddAppDependencyResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_nAppID** -- m_nAppID

.. function:: UGC.onRemoveAppDependencyResult

    Callback for `RemoveAppDependencyResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#RemoveAppDependencyResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_nAppID** -- m_nAppID

.. function:: UGC.onGetAppDependenciesResult

    Callback for `GetAppDependenciesResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#GetAppDependenciesResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_rgAppIDs** -- m_rgAppIDs
    * **data.m_nNumAppDependencies** -- m_nNumAppDependencies
    * **data.m_nTotalNumAppDependencies** -- m_nTotalNumAppDependencies

.. function:: UGC.onDeleteItemResult

    Callback for `DeleteItemResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#DeleteItemResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nPublishedFileId** -- m_nPublishedFileId

.. function:: UGC.onUserSubscribedItemsListChanged

    Callback for `UserSubscribedItemsListChanged_t <https://partner.steamgames.com/doc/api/ISteamUGC#UserSubscribedItemsListChanged_t>`_

    **callback(data)** receives:

    * **data.m_nAppID** -- m_nAppID

.. function:: UGC.onWorkshopEULAStatus

    Callback for `WorkshopEULAStatus_t <https://partner.steamgames.com/doc/api/ISteamUGC#WorkshopEULAStatus_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nAppID** -- m_nAppID
    * **data.m_unVersion** -- m_unVersion
    * **data.m_rtAction** -- m_rtAction
    * **data.m_bAccepted** -- m_bAccepted
    * **data.m_bNeedsAction** -- m_bNeedsAction

