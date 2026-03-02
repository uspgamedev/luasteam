#########
ISteamUGC
#########

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✍️ are manually implemented and methods marked with ✋ are currently not implemented.

List of Functions
-----------------

* :func:`UGC.AddAppDependency`
* :func:`UGC.AddContentDescriptor`
* :func:`UGC.AddDependency`
* :func:`UGC.AddExcludedTag`
* :func:`UGC.AddItemKeyValueTag`
* :func:`UGC.AddItemPreviewFile`
* :func:`UGC.AddItemPreviewVideo`
* :func:`UGC.AddItemToFavorites`
* :func:`UGC.AddRequiredKeyValueTag`
* :func:`UGC.AddRequiredTag`
* :func:`UGC.AddRequiredTagGroup`
* :func:`UGC.BInitWorkshopForGameServer`
* :func:`UGC.CreateItem`
* :func:`UGC.CreateQueryAllUGCRequestPage`
* :func:`UGC.CreateQueryUGCDetailsRequest`
* :func:`UGC.CreateQueryUserUGCRequest`
* :func:`UGC.DeleteItem`
* :func:`UGC.DownloadItem`
* :func:`UGC.GetAppDependencies`
* :func:`UGC.GetItemDownloadInfo`
* :func:`UGC.GetItemInstallInfo`
* :func:`UGC.GetItemState`
* :func:`UGC.GetItemUpdateProgress`
* :func:`UGC.GetNumSubscribedItems`
* :func:`UGC.GetNumSupportedGameVersions`
* :func:`UGC.GetQueryUGCAdditionalPreview`
* :func:`UGC.GetQueryUGCChildren`
* :func:`UGC.GetQueryUGCContentDescriptors`
* :func:`UGC.GetQueryUGCKeyValueTag`
* :func:`UGC.GetQueryUGCMetadata`
* :func:`UGC.GetQueryUGCNumAdditionalPreviews`
* :func:`UGC.GetQueryUGCNumKeyValueTags`
* :func:`UGC.GetQueryUGCNumTags`
* :func:`UGC.GetQueryUGCPreviewURL`
* :func:`UGC.GetQueryUGCResult`
* :func:`UGC.GetQueryUGCStatistic`
* :func:`UGC.GetQueryUGCTag`
* :func:`UGC.GetQueryUGCTagDisplayName`
* :func:`UGC.GetSubscribedItems`
* :func:`UGC.GetSupportedGameVersionData`
* :func:`UGC.GetUserContentDescriptorPreferences`
* :func:`UGC.GetUserItemVote`
* :func:`UGC.GetWorkshopEULAStatus`
* :func:`UGC.ReleaseQueryUGCRequest`
* :func:`UGC.RemoveAllItemKeyValueTags`
* :func:`UGC.RemoveAppDependency`
* :func:`UGC.RemoveContentDescriptor`
* :func:`UGC.RemoveDependency`
* :func:`UGC.RemoveItemFromFavorites`
* :func:`UGC.RemoveItemKeyValueTags`
* :func:`UGC.RemoveItemPreview`
* :func:`UGC.RequestUGCDetails`
* :func:`UGC.SendQueryUGCRequest`
* :func:`UGC.SetAdminQuery`
* :func:`UGC.SetAllowCachedResponse`
* :func:`UGC.SetAllowLegacyUpload`
* :func:`UGC.SetCloudFileNameFilter`
* :func:`UGC.SetItemContent`
* :func:`UGC.SetItemDescription`
* :func:`UGC.SetItemMetadata`
* :func:`UGC.SetItemPreview`
* :func:`UGC.SetItemTags`
* :func:`UGC.SetItemTitle`
* :func:`UGC.SetItemUpdateLanguage`
* :func:`UGC.SetItemVisibility`
* :func:`UGC.SetItemsDisabledLocally`
* :func:`UGC.SetLanguage`
* :func:`UGC.SetMatchAnyTag`
* :func:`UGC.SetRankedByTrendDays`
* :func:`UGC.SetRequiredGameVersions`
* :func:`UGC.SetReturnAdditionalPreviews`
* :func:`UGC.SetReturnChildren`
* :func:`UGC.SetReturnKeyValueTags`
* :func:`UGC.SetReturnLongDescription`
* :func:`UGC.SetReturnMetadata`
* :func:`UGC.SetReturnOnlyIDs`
* :func:`UGC.SetReturnPlaytimeStats`
* :func:`UGC.SetReturnTotalOnly`
* :func:`UGC.SetSearchText`
* :func:`UGC.SetSubscriptionsLoadOrder`
* :func:`UGC.SetTimeCreatedDateRange`
* :func:`UGC.SetTimeUpdatedDateRange`
* :func:`UGC.SetUserItemVote`
* :func:`UGC.ShowWorkshopEULA`
* :func:`UGC.StartItemUpdate`
* :func:`UGC.StartPlaytimeTracking`
* :func:`UGC.StopPlaytimeTracking`
* :func:`UGC.StopPlaytimeTrackingForAllItems`
* :func:`UGC.SubmitItemUpdate`
* :func:`UGC.SubscribeItem`
* :func:`UGC.SuspendDownloads`
* :func:`UGC.UnsubscribeItem`
* :func:`UGC.UpdateItemPreviewFile`
* :func:`UGC.UpdateItemPreviewVideo`

List of Callbacks
-----------------

* :func:`UGC.OnSteamUGCQueryCompleted`
* :func:`UGC.OnSteamUGCRequestUGCDetailsResult`
* :func:`UGC.OnCreateItemResult`
* :func:`UGC.OnSubmitItemUpdateResult`
* :func:`UGC.OnItemInstalled`
* :func:`UGC.OnDownloadItemResult`
* :func:`UGC.OnUserFavoriteItemsListChanged`
* :func:`UGC.OnSetUserItemVoteResult`
* :func:`UGC.OnGetUserItemVoteResult`
* :func:`UGC.OnStartPlaytimeTrackingResult`
* :func:`UGC.OnStopPlaytimeTrackingResult`
* :func:`UGC.OnAddUGCDependencyResult`
* :func:`UGC.OnRemoveUGCDependencyResult`
* :func:`UGC.OnAddAppDependencyResult`
* :func:`UGC.OnRemoveAppDependencyResult`
* :func:`UGC.OnGetAppDependenciesResult`
* :func:`UGC.OnDeleteItemResult`
* :func:`UGC.OnUserSubscribedItemsListChanged`
* :func:`UGC.OnWorkshopEULAStatus`

Function Reference
------------------

.. function:: UGC.AddAppDependency(nPublishedFileID, nAppID, callback)

    🤖 **Auto-generated binding**

    :param uint64 nPublishedFileID:
    :param int nAppID:
    :param function callback: CallResult callback receiving struct `AddAppDependencyResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `AddAppDependency <https://partner.steamgames.com/doc/api/ISteamUGC#AddAppDependency>`_

.. function:: UGC.AddContentDescriptor(handle, descid)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int descid:
    :returns: (bool) Return value
    :SteamWorks: `AddContentDescriptor <https://partner.steamgames.com/doc/api/ISteamUGC#AddContentDescriptor>`_

.. function:: UGC.AddDependency(nParentPublishedFileID, nChildPublishedFileID, callback)

    🤖 **Auto-generated binding**

    :param uint64 nParentPublishedFileID:
    :param uint64 nChildPublishedFileID:
    :param function callback: CallResult callback receiving struct `AddUGCDependencyResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `AddDependency <https://partner.steamgames.com/doc/api/ISteamUGC#AddDependency>`_

.. function:: UGC.AddExcludedTag(handle, pTagName)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pTagName:
    :returns: (bool) Return value
    :SteamWorks: `AddExcludedTag <https://partner.steamgames.com/doc/api/ISteamUGC#AddExcludedTag>`_

**Example**::

    local handle = Steam.UGC.CreateQueryAllUGCRequestPage('RankedByVote', 'Items', appID, appID, 1)
    Steam.UGC.AddExcludedTag(handle, 'deprecated')
    Steam.UGC.SendQueryUGCRequest(handle, function(data, err) end)

.. function:: UGC.AddItemKeyValueTag(handle, pchKey, pchValue)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pchKey:
    :param str pchValue:
    :returns: (bool) Return value
    :SteamWorks: `AddItemKeyValueTag <https://partner.steamgames.com/doc/api/ISteamUGC#AddItemKeyValueTag>`_

**Example**::

    local handle = Steam.UGC.StartItemUpdate(appID, publishedFileID)
    Steam.UGC.AddItemKeyValueTag(handle, 'game_version', '1.5')
    Steam.UGC.SubmitItemUpdate(handle, nil, function(data, err) end)

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

.. function:: UGC.AddItemToFavorites(nAppId, nPublishedFileID, callback)

    🤖 **Auto-generated binding**

    :param int nAppId:
    :param uint64 nPublishedFileID:
    :param function callback: CallResult callback receiving struct `UserFavoriteItemsListChanged_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `AddItemToFavorites <https://partner.steamgames.com/doc/api/ISteamUGC#AddItemToFavorites>`_

**Example**::

    Steam.UGC.AddItemToFavorites(appID, publishedFileID, function(data, err)
        if not err and data.m_eResult == Steam.k_EResultOK then
            print('Added to favorites')
        end
    end)

.. function:: UGC.AddRequiredKeyValueTag(handle, pKey, pValue)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pKey:
    :param str pValue:
    :returns: (bool) Return value
    :SteamWorks: `AddRequiredKeyValueTag <https://partner.steamgames.com/doc/api/ISteamUGC#AddRequiredKeyValueTag>`_

.. function:: UGC.AddRequiredTag(handle, pTagName)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pTagName:
    :returns: (bool) Return value
    :SteamWorks: `AddRequiredTag <https://partner.steamgames.com/doc/api/ISteamUGC#AddRequiredTag>`_

**Example**::

    local handle = Steam.UGC.CreateQueryAllUGCRequestPage('RankedByVote', 'Items', appID, appID, 1)
    Steam.UGC.AddRequiredTag(handle, 'multiplayer')
    Steam.UGC.SendQueryUGCRequest(handle, function(data, err) end)

.. function:: UGC.AddRequiredTagGroup(handle, pTagGroups)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param :ref:`SteamParamStringArray_t <struct-SteamParamStringArray_t>` pTagGroups:
    :returns: (bool) Return value
    :SteamWorks: `AddRequiredTagGroup <https://partner.steamgames.com/doc/api/ISteamUGC#AddRequiredTagGroup>`_

.. function:: UGC.BInitWorkshopForGameServer(unWorkshopDepotID, pszFolder)

    🤖 **Auto-generated binding**

    :param int unWorkshopDepotID:
    :param str pszFolder:
    :returns: (bool) Return value
    :SteamWorks: `BInitWorkshopForGameServer <https://partner.steamgames.com/doc/api/ISteamUGC#BInitWorkshopForGameServer>`_

.. function:: UGC.CreateItem(nConsumerAppId, eFileType, callback)

    🤖 **Auto-generated binding**

    :param int nConsumerAppId:
    :param int eFileType:
    :param function callback: CallResult callback receiving struct `CreateItemResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `CreateItem <https://partner.steamgames.com/doc/api/ISteamUGC#CreateItem>`_

**Example**::

    Steam.UGC.CreateItem(Steam.Utils.GetAppID(), 'Community', function(data, err)
        if err or data.m_eResult ~= Steam.k_EResultOK then
            print('Failure when creating item')
        else
            populateItem(data.m_nPublishedFileId)
        end
    end)

.. function:: UGC.CreateQueryAllUGCRequestPage(eQueryType, eMatchingeMatchingUGCTypeFileType, nCreatorAppID, nConsumerAppID, unPage)

    🤖 **Auto-generated binding**

    :param int eQueryType:
    :param int eMatchingeMatchingUGCTypeFileType:
    :param int nCreatorAppID:
    :param int nConsumerAppID:
    :param int unPage:
    :returns: (uint64) Return value
    :SteamWorks: `CreateQueryAllUGCRequestPage <https://partner.steamgames.com/doc/api/ISteamUGC#CreateQueryAllUGCRequestPage>`_

**Example**::

    local handle = Steam.UGC.CreateQueryAllUGCRequestPage('RankedByVote', 'Items', appID, appID, 1)
    Steam.UGC.SetReturnLongDescription(handle, true)
    Steam.UGC.SetReturnMetadata(handle, true)
    -- Then call SendQueryUGCRequest

.. function:: UGC.CreateQueryUGCDetailsRequest(pvecPublishedFileID, unNumPublishedFileIDs)

    🤖 **Auto-generated binding**

    :param uint64[] pvecPublishedFileID:
    :param int unNumPublishedFileIDs:
    :returns: (uint64) Return value
    :SteamWorks: `CreateQueryUGCDetailsRequest <https://partner.steamgames.com/doc/api/ISteamUGC#CreateQueryUGCDetailsRequest>`_

**Example**::

    local fileIDs = {id1, id2, id3}
    local handle = Steam.UGC.CreateQueryUGCDetailsRequest(fileIDs, #fileIDs)
    Steam.UGC.SendQueryUGCRequest(handle, function(data, err)
        if not err then
            local details = Steam.UGC.GetQueryUGCResult(handle, 0)
            print('Title:', details.m_rgchTitle)
        end
        Steam.UGC.ReleaseQueryUGCRequest(handle)
    end)

.. function:: UGC.CreateQueryUserUGCRequest(unAccountID, eListType, eMatchingUGCType, eSortOrder, nCreatorAppID, nConsumerAppID, unPage)

    🤖 **Auto-generated binding**

    :param int unAccountID: The account ID to query
    :param int eListType: The type of list to query
    :param int eMatchingUGCType: The type of UGC to match
    :param int eSortOrder: How to sort the results
    :param int nCreatorAppID: The app that created the items
    :param int nConsumerAppID: The app that will consume the items
    :param int unPage: The page number of results to retrieve (starts at 1)
    :returns: (uint64) Return value
    :SteamWorks: `CreateQueryUserUGCRequest <https://partner.steamgames.com/doc/api/ISteamUGC#CreateQueryUserUGCRequest>`_

    Creates a query to retrieve the details for user-generated content (UGC).

**Example**::

    local appID = Steam.Utils.GetAppID()
    local myAccountID = Steam.User.GetSteamID()
    local handle = Steam.UGC.CreateQueryUserUGCRequest(myAccountID, 'Published', 'Items', 'CreationOrderDesc', appID, appID, 1)
    Steam.UGC.SendQueryUGCRequest(handle, function(data, err)
        if not err and data.m_eResultCode == Steam.k_EResultOK then
            for i = 0, data.m_unNumResultsReturned - 1 do
                local details = Steam.UGC.GetQueryUGCResult(handle, i)
                print('My item:', details.m_rgchTitle)
            end
        end
        Steam.UGC.ReleaseQueryUGCRequest(handle)
    end)

.. function:: UGC.DeleteItem(nPublishedFileID, callback)

    🤖 **Auto-generated binding**

    :param uint64 nPublishedFileID:
    :param function callback: CallResult callback receiving struct `DeleteItemResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `DeleteItem <https://partner.steamgames.com/doc/api/ISteamUGC#DeleteItem>`_

**Example**::

    Steam.UGC.DeleteItem(publishedFileID, function(data, err)
        if not err and data.m_eResult == Steam.k_EResultOK then
            print('Item deleted')
        end
    end)

.. function:: UGC.DownloadItem(nPublishedFileID, bHighPriority)

    🤖 **Auto-generated binding**

    :param uint64 nPublishedFileID:
    :param bool bHighPriority:
    :returns: (bool) Return value
    :SteamWorks: `DownloadItem <https://partner.steamgames.com/doc/api/ISteamUGC#DownloadItem>`_

**Example**::

    local queued = Steam.UGC.DownloadItem(publishedFileID, true)
    if queued then
        print('Download queued with high priority')
    end

.. function:: UGC.GetAppDependencies(nPublishedFileID, callback)

    🤖 **Auto-generated binding**

    :param uint64 nPublishedFileID:
    :param function callback: CallResult callback receiving struct `GetAppDependenciesResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `GetAppDependencies <https://partner.steamgames.com/doc/api/ISteamUGC#GetAppDependencies>`_

.. function:: UGC.GetItemDownloadInfo(nPublishedFileID)

    🤖 **Auto-generated binding**

    :param uint64 nPublishedFileID:
    :returns: (bool) Return value
    :returns: (uint64) Value for `punBytesDownloaded`
    :returns: (uint64) Value for `punBytesTotal`
    :SteamWorks: `GetItemDownloadInfo <https://partner.steamgames.com/doc/api/ISteamUGC#GetItemDownloadInfo>`_

    **Signature differences from C++ API:**

    * Parameter ``punBytesDownloaded`` is no longer a paramer, and is instead an additional return value
    * Parameter ``punBytesTotal`` is no longer a paramer, and is instead an additional return value

**Example**::

    local ok, downloaded, total = Steam.UGC.GetItemDownloadInfo(publishedFileID)
    if ok and total > 0 then
        print(string.format('Download: %.0f%%', downloaded / total * 100))
    end

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

    * Parameter ``punSizeOnDisk`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pchFolder`` is no longer a paramer, and is instead an additional return value
    * Parameter ``punTimeStamp`` is no longer a paramer, and is instead an additional return value

**Example**::

    local success, sizeOnDisk, folder, timestamp = Steam.UGC.GetItemInstallInfo(item_id, 512)
    if success then
        print('Item installed at:', folder)
        loadMod(folder)
    end

.. function:: UGC.GetItemState(nPublishedFileID)

    🤖 **Auto-generated binding**

    :param uint64 nPublishedFileID:
    :returns: (int) Return value
    :SteamWorks: `GetItemState <https://partner.steamgames.com/doc/api/ISteamUGC#GetItemState>`_

**Example**::

    local state = Steam.UGC.GetItemState(item_id)
    local installed = bit.band(state, Steam.k_EItemStateInstalled) ~= 0

.. function:: UGC.GetItemUpdateProgress(handle)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :returns: (int) Return value
    :returns: (uint64) Value for `punBytesProcessed`
    :returns: (uint64) Value for `punBytesTotal`
    :SteamWorks: `GetItemUpdateProgress <https://partner.steamgames.com/doc/api/ISteamUGC#GetItemUpdateProgress>`_

    **Signature differences from C++ API:**

    * Parameter ``punBytesProcessed`` is no longer a paramer, and is instead an additional return value
    * Parameter ``punBytesTotal`` is no longer a paramer, and is instead an additional return value

**Example**::

    local status, processed, total = Steam.UGC.GetItemUpdateProgress(updateHandle)
    if total > 0 then
        print(string.format('Download progress: %.1f%%', processed / total * 100))
    end

.. function:: UGC.GetNumSubscribedItems(bIncludeLocallyDisabled)

    🤖 **Auto-generated binding**

    :param bool bIncludeLocallyDisabled:
    :returns: (int) Return value
    :SteamWorks: `GetNumSubscribedItems <https://partner.steamgames.com/doc/api/ISteamUGC#GetNumSubscribedItems>`_

**Example**::

    local count = Steam.UGC.GetNumSubscribedItems(false)
    print('You are subscribed to ' .. count .. ' workshop items')

.. function:: UGC.GetNumSupportedGameVersions(handle, index)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int index:
    :returns: (int) Return value
    :SteamWorks: `GetNumSupportedGameVersions <https://partner.steamgames.com/doc/api/ISteamUGC#GetNumSupportedGameVersions>`_

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

    * Parameter ``pchURLOrVideoID`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pchOriginalFileName`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pPreviewType`` is no longer a paramer, and is instead an additional return value

.. function:: UGC.GetQueryUGCChildren(handle, index, cMaxEntries)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int index:
    :param int cMaxEntries:
    :returns: (bool) Return value
    :returns: (uint64) Value for `pvecPublishedFileID`
    :SteamWorks: `GetQueryUGCChildren <https://partner.steamgames.com/doc/api/ISteamUGC#GetQueryUGCChildren>`_

    **Signature differences from C++ API:**

    * Parameter ``pvecPublishedFileID`` is no longer a paramer, and is instead an additional return value

.. function:: UGC.GetQueryUGCContentDescriptors(handle, index, cMaxEntries)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int index:
    :param int cMaxEntries:
    :returns: (int) Return value
    :returns: (int) Value for `pvecDescriptors`
    :SteamWorks: `GetQueryUGCContentDescriptors <https://partner.steamgames.com/doc/api/ISteamUGC#GetQueryUGCContentDescriptors>`_

    **Signature differences from C++ API:**

    * Parameter ``pvecDescriptors`` is no longer a paramer, and is instead an additional return value

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

    * Parameter ``pchKey`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pchValue`` is no longer a paramer, and is instead an additional return value

.. function:: UGC.GetQueryUGCMetadata(handle, index, cchMetadatasize)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int index:
    :param int cchMetadatasize:
    :returns: (bool) Return value
    :returns: (str) Value for `pchMetadata`
    :SteamWorks: `GetQueryUGCMetadata <https://partner.steamgames.com/doc/api/ISteamUGC#GetQueryUGCMetadata>`_

    **Signature differences from C++ API:**

    * Parameter ``pchMetadata`` is no longer a paramer, and is instead an additional return value

.. function:: UGC.GetQueryUGCNumAdditionalPreviews(handle, index)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int index:
    :returns: (int) Return value
    :SteamWorks: `GetQueryUGCNumAdditionalPreviews <https://partner.steamgames.com/doc/api/ISteamUGC#GetQueryUGCNumAdditionalPreviews>`_

.. function:: UGC.GetQueryUGCNumKeyValueTags(handle, index)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int index:
    :returns: (int) Return value
    :SteamWorks: `GetQueryUGCNumKeyValueTags <https://partner.steamgames.com/doc/api/ISteamUGC#GetQueryUGCNumKeyValueTags>`_

.. function:: UGC.GetQueryUGCNumTags(handle, index)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int index:
    :returns: (int) Return value
    :SteamWorks: `GetQueryUGCNumTags <https://partner.steamgames.com/doc/api/ISteamUGC#GetQueryUGCNumTags>`_

.. function:: UGC.GetQueryUGCPreviewURL(handle, index, cchURLSize)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int index:
    :param int cchURLSize:
    :returns: (bool) Return value
    :returns: (str) Value for `pchURL`
    :SteamWorks: `GetQueryUGCPreviewURL <https://partner.steamgames.com/doc/api/ISteamUGC#GetQueryUGCPreviewURL>`_

    **Signature differences from C++ API:**

    * Parameter ``pchURL`` is no longer a paramer, and is instead an additional return value

**Example**::

    local ok, url = Steam.UGC.GetQueryUGCPreviewURL(handle, index, 512)
    if ok then
        downloadPreviewImage(url)
    end

.. function:: UGC.GetQueryUGCResult(handle, index)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int index:
    :returns: (bool) Return value
    :returns: (:ref:`SteamUGCDetails_t <struct-SteamUGCDetails_t>`) Value for `pDetails`
    :SteamWorks: `GetQueryUGCResult <https://partner.steamgames.com/doc/api/ISteamUGC#GetQueryUGCResult>`_

    **Signature differences from C++ API:**

    * Parameter ``pDetails`` is no longer a paramer, and is instead an additional return value

**Example**::

    See :func:`UGC.SendQueryUGCRequest`'s example.

.. function:: UGC.GetQueryUGCStatistic(handle, index, eStatType)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int index:
    :param int eStatType:
    :returns: (bool) Return value
    :returns: (uint64) Value for `pStatValue`
    :SteamWorks: `GetQueryUGCStatistic <https://partner.steamgames.com/doc/api/ISteamUGC#GetQueryUGCStatistic>`_

    **Signature differences from C++ API:**

    * Parameter ``pStatValue`` is no longer a paramer, and is instead an additional return value

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

    * Parameter ``pchValue`` is no longer a paramer, and is instead an additional return value

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

    * Parameter ``pchValue`` is no longer a paramer, and is instead an additional return value

.. function:: UGC.GetSubscribedItems(cMaxEntries, bIncludeLocallyDisabled)

    🤖 **Auto-generated binding**

    :param int cMaxEntries:
    :param bool bIncludeLocallyDisabled:
    :returns: (int) Return value
    :returns: (uint64[]) Value for `pvecPublishedFileID`
    :SteamWorks: `GetSubscribedItems <https://partner.steamgames.com/doc/api/ISteamUGC#GetSubscribedItems>`_

    **Signature differences from C++ API:**

    * Parameter ``pvecPublishedFileID`` is no longer a paramer, and is instead an additional return value

**Example**::

    local count = Steam.UGC.GetNumSubscribedItems(false)
    local items = Steam.UGC.GetSubscribedItems(count, false)
    for _, item_id in ipairs(items) do
        print('Subscribed item:', tostring(item_id))
    end

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

    * Parameter ``pchGameBranchMin`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pchGameBranchMax`` is no longer a paramer, and is instead an additional return value

.. function:: UGC.GetUserContentDescriptorPreferences(cMaxEntries)

    🤖 **Auto-generated binding**

    :param int cMaxEntries:
    :returns: (int) Return value
    :returns: (int) Value for `pvecDescriptors`
    :SteamWorks: `GetUserContentDescriptorPreferences <https://partner.steamgames.com/doc/api/ISteamUGC#GetUserContentDescriptorPreferences>`_

    **Signature differences from C++ API:**

    * Parameter ``pvecDescriptors`` is no longer a paramer, and is instead an additional return value

.. function:: UGC.GetUserItemVote(nPublishedFileID, callback)

    🤖 **Auto-generated binding**

    :param uint64 nPublishedFileID:
    :param function callback: CallResult callback receiving struct `GetUserItemVoteResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `GetUserItemVote <https://partner.steamgames.com/doc/api/ISteamUGC#GetUserItemVote>`_

**Example**::

    Steam.UGC.GetUserItemVote(publishedFileID, function(data, err)
        if not err then
            print('Voted up:', data.m_bVotedUp ~= 0)
            print('Voted down:', data.m_bVotedDown ~= 0)
        end
    end)

.. function:: UGC.GetWorkshopEULAStatus(callback)

    🤖 **Auto-generated binding**

    :param function callback: CallResult callback receiving struct `WorkshopEULAStatus_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `GetWorkshopEULAStatus <https://partner.steamgames.com/doc/api/ISteamUGC#GetWorkshopEULAStatus>`_

.. function:: UGC.ReleaseQueryUGCRequest(handle)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :returns: (bool) Return value
    :SteamWorks: `ReleaseQueryUGCRequest <https://partner.steamgames.com/doc/api/ISteamUGC#ReleaseQueryUGCRequest>`_

**Example**::

    See :func:`UGC.SendQueryUGCRequest`'s example.

.. function:: UGC.RemoveAllItemKeyValueTags(handle)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :returns: (bool) Return value
    :SteamWorks: `RemoveAllItemKeyValueTags <https://partner.steamgames.com/doc/api/ISteamUGC#RemoveAllItemKeyValueTags>`_

.. function:: UGC.RemoveAppDependency(nPublishedFileID, nAppID, callback)

    🤖 **Auto-generated binding**

    :param uint64 nPublishedFileID:
    :param int nAppID:
    :param function callback: CallResult callback receiving struct `RemoveAppDependencyResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `RemoveAppDependency <https://partner.steamgames.com/doc/api/ISteamUGC#RemoveAppDependency>`_

.. function:: UGC.RemoveContentDescriptor(handle, descid)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int descid:
    :returns: (bool) Return value
    :SteamWorks: `RemoveContentDescriptor <https://partner.steamgames.com/doc/api/ISteamUGC#RemoveContentDescriptor>`_

.. function:: UGC.RemoveDependency(nParentPublishedFileID, nChildPublishedFileID, callback)

    🤖 **Auto-generated binding**

    :param uint64 nParentPublishedFileID:
    :param uint64 nChildPublishedFileID:
    :param function callback: CallResult callback receiving struct `RemoveUGCDependencyResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `RemoveDependency <https://partner.steamgames.com/doc/api/ISteamUGC#RemoveDependency>`_

.. function:: UGC.RemoveItemFromFavorites(nAppId, nPublishedFileID, callback)

    🤖 **Auto-generated binding**

    :param int nAppId:
    :param uint64 nPublishedFileID:
    :param function callback: CallResult callback receiving struct `UserFavoriteItemsListChanged_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `RemoveItemFromFavorites <https://partner.steamgames.com/doc/api/ISteamUGC#RemoveItemFromFavorites>`_

**Example**::

    Steam.UGC.RemoveItemFromFavorites(appID, publishedFileID, function(data, err)
        if not err and data.m_eResult == Steam.k_EResultOK then
            print('Removed from favorites')
        end
    end)

.. function:: UGC.RemoveItemKeyValueTags(handle, pchKey)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pchKey:
    :returns: (bool) Return value
    :SteamWorks: `RemoveItemKeyValueTags <https://partner.steamgames.com/doc/api/ISteamUGC#RemoveItemKeyValueTags>`_

.. function:: UGC.RemoveItemPreview(handle, index)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int index:
    :returns: (bool) Return value
    :SteamWorks: `RemoveItemPreview <https://partner.steamgames.com/doc/api/ISteamUGC#RemoveItemPreview>`_

.. function:: UGC.RequestUGCDetails(nPublishedFileID, unMaxAgeSeconds, callback)

    🤖 **Auto-generated binding**

    :param uint64 nPublishedFileID:
    :param int unMaxAgeSeconds:
    :param function callback: CallResult callback receiving struct `SteamUGCRequestUGCDetailsResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `RequestUGCDetails <https://partner.steamgames.com/doc/api/ISteamUGC#RequestUGCDetails>`_

**Example**::

    Steam.UGC.RequestUGCDetails(publishedFileID, 0, function(data, err)
        if not err and data.m_eResult == Steam.k_EResultOK then
            print('Title:', data.m_details.m_rgchTitle)
        end
    end)

.. function:: UGC.SendQueryUGCRequest(handle, callback)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param function callback: CallResult callback receiving struct `SteamUGCQueryCompleted_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `SendQueryUGCRequest <https://partner.steamgames.com/doc/api/ISteamUGC#SendQueryUGCRequest>`_

**Example**::

    Steam.UGC.SendQueryUGCRequest(queryHandle, function(data, err)
        if err or data.m_eResultCode ~= Steam.k_EResultOK then
            print('Query failed')
            Steam.UGC.ReleaseQueryUGCRequest(queryHandle)
            return
        end
        for i = 0, data.m_unNumResultsReturned - 1 do
            local details = Steam.UGC.GetQueryUGCResult(queryHandle, i)
            print('Item:', tostring(details.m_nPublishedFileId), details.m_rgchTitle)
        end
        Steam.UGC.ReleaseQueryUGCRequest(queryHandle)
    end)

.. function:: UGC.SetAdminQuery(handle, bAdminQuery)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param bool bAdminQuery:
    :returns: (bool) Return value
    :SteamWorks: `SetAdminQuery <https://partner.steamgames.com/doc/api/ISteamUGC#SetAdminQuery>`_

.. function:: UGC.SetAllowCachedResponse(handle, unMaxAgeSeconds)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int unMaxAgeSeconds:
    :returns: (bool) Return value
    :SteamWorks: `SetAllowCachedResponse <https://partner.steamgames.com/doc/api/ISteamUGC#SetAllowCachedResponse>`_

.. function:: UGC.SetAllowLegacyUpload(handle, bAllowLegacyUpload)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param bool bAllowLegacyUpload:
    :returns: (bool) Return value
    :SteamWorks: `SetAllowLegacyUpload <https://partner.steamgames.com/doc/api/ISteamUGC#SetAllowLegacyUpload>`_

.. function:: UGC.SetCloudFileNameFilter(handle, pMatchCloudFileName)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pMatchCloudFileName:
    :returns: (bool) Return value
    :SteamWorks: `SetCloudFileNameFilter <https://partner.steamgames.com/doc/api/ISteamUGC#SetCloudFileNameFilter>`_

.. function:: UGC.SetItemContent(handle, pszContentFolder)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pszContentFolder:
    :returns: (bool) Return value
    :SteamWorks: `SetItemContent <https://partner.steamgames.com/doc/api/ISteamUGC#SetItemContent>`_

**Example**::

    See :func:`UGC.StartItemUpdate`'s example.

.. function:: UGC.SetItemDescription(handle, pchDescription)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pchDescription:
    :returns: (bool) Return value
    :SteamWorks: `SetItemDescription <https://partner.steamgames.com/doc/api/ISteamUGC#SetItemDescription>`_

**Example**::

    See :func:`UGC.StartItemUpdate`'s example.

.. function:: UGC.SetItemMetadata(handle, pchMetaData)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pchMetaData:
    :returns: (bool) Return value
    :SteamWorks: `SetItemMetadata <https://partner.steamgames.com/doc/api/ISteamUGC#SetItemMetadata>`_

**Example**::

    local handle = Steam.UGC.StartItemUpdate(appID, publishedFileID)
    Steam.UGC.SetItemMetadata(handle, '{"version":"1.2","requires":"dlc1"}')
    Steam.UGC.SubmitItemUpdate(handle, nil, function(data, err) end)

.. function:: UGC.SetItemPreview(handle, pszPreviewFile)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pszPreviewFile:
    :returns: (bool) Return value
    :SteamWorks: `SetItemPreview <https://partner.steamgames.com/doc/api/ISteamUGC#SetItemPreview>`_

**Example**::

    See :func:`UGC.StartItemUpdate`'s example.

.. function:: UGC.SetItemTags(updateHandle, pTags, bAllowAdminTags)

    🤖 **Auto-generated binding**

    :param uint64 updateHandle:
    :param :ref:`SteamParamStringArray_t <struct-SteamParamStringArray_t>` pTags:
    :param bool bAllowAdminTags:
    :returns: (bool) Return value
    :SteamWorks: `SetItemTags <https://partner.steamgames.com/doc/api/ISteamUGC#SetItemTags>`_

**Example**::

    local handle = Steam.UGC.StartItemUpdate(appID, publishedFileID)
    Steam.UGC.SetItemTags(handle, {'rpg', 'adventure', 'fantasy'}, false)
    Steam.UGC.SubmitItemUpdate(handle, 'Updated tags', function(data, err) end)

.. function:: UGC.SetItemTitle(handle, pchTitle)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pchTitle:
    :returns: (bool) Return value
    :SteamWorks: `SetItemTitle <https://partner.steamgames.com/doc/api/ISteamUGC#SetItemTitle>`_

**Example**::

    See :func:`UGC.StartItemUpdate`'s example.

.. function:: UGC.SetItemUpdateLanguage(handle, pchLanguage)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pchLanguage:
    :returns: (bool) Return value
    :SteamWorks: `SetItemUpdateLanguage <https://partner.steamgames.com/doc/api/ISteamUGC#SetItemUpdateLanguage>`_

**Example**::

    local handle = Steam.UGC.StartItemUpdate(appID, publishedFileID)
    Steam.UGC.SetItemUpdateLanguage(handle, 'english')
    Steam.UGC.SubmitItemUpdate(handle, nil, function(data, err) end)

.. function:: UGC.SetItemVisibility(handle, eVisibility)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int eVisibility:
    :returns: (bool) Return value
    :SteamWorks: `SetItemVisibility <https://partner.steamgames.com/doc/api/ISteamUGC#SetItemVisibility>`_

**Example**::

    local handle = Steam.UGC.StartItemUpdate(appID, publishedFileID)
    Steam.UGC.SetItemVisibility(handle, 'Public')
    Steam.UGC.SubmitItemUpdate(handle, nil, function(data, err) end)

.. function:: UGC.SetItemsDisabledLocally(pvecPublishedFileIDs, unNumPublishedFileIDs, bDisabledLocally)

    🤖 **Auto-generated binding**

    :param uint64[] pvecPublishedFileIDs:
    :param int unNumPublishedFileIDs:
    :param bool bDisabledLocally:
    :returns: (bool) Return value
    :SteamWorks: `SetItemsDisabledLocally <https://partner.steamgames.com/doc/api/ISteamUGC#SetItemsDisabledLocally>`_

.. function:: UGC.SetLanguage(handle, pchLanguage)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pchLanguage:
    :returns: (bool) Return value
    :SteamWorks: `SetLanguage <https://partner.steamgames.com/doc/api/ISteamUGC#SetLanguage>`_

.. function:: UGC.SetMatchAnyTag(handle, bMatchAnyTag)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param bool bMatchAnyTag:
    :returns: (bool) Return value
    :SteamWorks: `SetMatchAnyTag <https://partner.steamgames.com/doc/api/ISteamUGC#SetMatchAnyTag>`_

.. function:: UGC.SetRankedByTrendDays(handle, unDays)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int unDays:
    :returns: (bool) Return value
    :SteamWorks: `SetRankedByTrendDays <https://partner.steamgames.com/doc/api/ISteamUGC#SetRankedByTrendDays>`_

**Example**::

    -- Query items trending in the last 7 days
    local handle = Steam.UGC.CreateQueryAllUGCRequestPage('RankedByTrend', 'Items', appID, appID, 1)
    Steam.UGC.SetRankedByTrendDays(handle, 7)
    Steam.UGC.SendQueryUGCRequest(handle, function(data, err) end)

.. function:: UGC.SetRequiredGameVersions(handle, pszGameBranchMin, pszGameBranchMax)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pszGameBranchMin:
    :param str pszGameBranchMax:
    :returns: (bool) Return value
    :SteamWorks: `SetRequiredGameVersions <https://partner.steamgames.com/doc/api/ISteamUGC#SetRequiredGameVersions>`_

.. function:: UGC.SetReturnAdditionalPreviews(handle, bReturnAdditionalPreviews)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param bool bReturnAdditionalPreviews:
    :returns: (bool) Return value
    :SteamWorks: `SetReturnAdditionalPreviews <https://partner.steamgames.com/doc/api/ISteamUGC#SetReturnAdditionalPreviews>`_

.. function:: UGC.SetReturnChildren(handle, bReturnChildren)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param bool bReturnChildren:
    :returns: (bool) Return value
    :SteamWorks: `SetReturnChildren <https://partner.steamgames.com/doc/api/ISteamUGC#SetReturnChildren>`_

.. function:: UGC.SetReturnKeyValueTags(handle, bReturnKeyValueTags)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param bool bReturnKeyValueTags:
    :returns: (bool) Return value
    :SteamWorks: `SetReturnKeyValueTags <https://partner.steamgames.com/doc/api/ISteamUGC#SetReturnKeyValueTags>`_

**Example**::

    local handle = Steam.UGC.CreateQueryUGCDetailsRequest({publishedFileID}, 1)
    Steam.UGC.SetReturnKeyValueTags(handle, true)
    Steam.UGC.SendQueryUGCRequest(handle, function(data, err)
        if not err then
            local count = Steam.UGC.GetQueryUGCNumKeyValueTags(handle, 0)
            for i = 0, count - 1 do
                local ok, k, v = Steam.UGC.GetQueryUGCKeyValueTag(handle, 0, i, 64, 256)
                if ok then print(k .. '=' .. v) end
            end
        end
        Steam.UGC.ReleaseQueryUGCRequest(handle)
    end)

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

**Example**::

    local handle = Steam.UGC.CreateQueryAllUGCRequestPage('RankedByVote', 'Items', appID, appID, 1)
    Steam.UGC.SetReturnMetadata(handle, true)
    Steam.UGC.SendQueryUGCRequest(handle, function(data, err)
        if not err then
            local meta = Steam.UGC.GetQueryUGCMetadata(handle, 0, 256)
            print('Metadata:', meta)
        end
        Steam.UGC.ReleaseQueryUGCRequest(handle)
    end)

.. function:: UGC.SetReturnOnlyIDs(handle, bReturnOnlyIDs)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param bool bReturnOnlyIDs:
    :returns: (bool) Return value
    :SteamWorks: `SetReturnOnlyIDs <https://partner.steamgames.com/doc/api/ISteamUGC#SetReturnOnlyIDs>`_

.. function:: UGC.SetReturnPlaytimeStats(handle, unDays)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param int unDays:
    :returns: (bool) Return value
    :SteamWorks: `SetReturnPlaytimeStats <https://partner.steamgames.com/doc/api/ISteamUGC#SetReturnPlaytimeStats>`_

.. function:: UGC.SetReturnTotalOnly(handle, bReturnTotalOnly)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param bool bReturnTotalOnly:
    :returns: (bool) Return value
    :SteamWorks: `SetReturnTotalOnly <https://partner.steamgames.com/doc/api/ISteamUGC#SetReturnTotalOnly>`_

.. function:: UGC.SetSearchText(handle, pSearchText)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pSearchText:
    :returns: (bool) Return value
    :SteamWorks: `SetSearchText <https://partner.steamgames.com/doc/api/ISteamUGC#SetSearchText>`_

**Example**::

    local handle = Steam.UGC.CreateQueryAllUGCRequestPage('RankedByVote', 'Items', appID, appID, 1)
    Steam.UGC.SetSearchText(handle, 'dungeon')
    Steam.UGC.SendQueryUGCRequest(handle, function(data, err) end)

.. function:: UGC.SetSubscriptionsLoadOrder(pvecPublishedFileIDs, unNumPublishedFileIDs)

    🤖 **Auto-generated binding**

    :param uint64[] pvecPublishedFileIDs:
    :param int unNumPublishedFileIDs:
    :returns: (bool) Return value
    :SteamWorks: `SetSubscriptionsLoadOrder <https://partner.steamgames.com/doc/api/ISteamUGC#SetSubscriptionsLoadOrder>`_

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

.. function:: UGC.SetUserItemVote(nPublishedFileID, bVoteUp, callback)

    🤖 **Auto-generated binding**

    :param uint64 nPublishedFileID:
    :param bool bVoteUp:
    :param function callback: CallResult callback receiving struct `SetUserItemVoteResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `SetUserItemVote <https://partner.steamgames.com/doc/api/ISteamUGC#SetUserItemVote>`_

**Example**::

    Steam.UGC.SetUserItemVote(publishedFileID, true, function(data, err)
        if not err and data.m_eResult == Steam.k_EResultOK then
            print('Vote recorded')
        end
    end)

.. function:: UGC.ShowWorkshopEULA()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `ShowWorkshopEULA <https://partner.steamgames.com/doc/api/ISteamUGC#ShowWorkshopEULA>`_

.. function:: UGC.StartItemUpdate(nConsumerAppId, nPublishedFileID)

    🤖 **Auto-generated binding**

    :param int nConsumerAppId:
    :param uint64 nPublishedFileID:
    :returns: (uint64) Return value
    :SteamWorks: `StartItemUpdate <https://partner.steamgames.com/doc/api/ISteamUGC#StartItemUpdate>`_

**Example**::

    local function populateItem(id)
        local handle = Steam.UGC.StartItemUpdate(Steam.Utils.GetAppID(), id)
        Steam.UGC.SetItemContent(handle, rootFolder)
        Steam.UGC.SetItemTitle(handle, 'My Item')
        Steam.UGC.SetItemDescription(handle, 'A Workshop item')
        Steam.UGC.SetItemPreview(handle, rootFolder .. '/preview.png')
        Steam.UGC.SubmitItemUpdate(handle, 'First Revision', function(data, err)
            if err or data.m_eResult ~= Steam.k_EResultOK then
                print('Failure when submitting item')
            else
                print('Item submitted successfully:', tostring(data.m_nPublishedFileId))
            end
        end)
    end

.. function:: UGC.StartPlaytimeTracking(pvecPublishedFileID, unNumPublishedFileIDs, callback)

    🤖 **Auto-generated binding**

    :param uint64[] pvecPublishedFileID:
    :param int unNumPublishedFileIDs:
    :param function callback: CallResult callback receiving struct `StartPlaytimeTrackingResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `StartPlaytimeTracking <https://partner.steamgames.com/doc/api/ISteamUGC#StartPlaytimeTracking>`_

**Example**::

    local ids = {mod1ID, mod2ID}
    Steam.UGC.StartPlaytimeTracking(ids, #ids, function(data, err)
        print('Playtime tracking started')
    end)

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

**Example**::

    Steam.UGC.StopPlaytimeTrackingForAllItems(function(data, err)
        print('Playtime tracking stopped for all items')
    end)

.. function:: UGC.SubmitItemUpdate(handle, pchChangeNote, callback)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param str pchChangeNote:
    :param function callback: CallResult callback receiving struct `SubmitItemUpdateResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `SubmitItemUpdate <https://partner.steamgames.com/doc/api/ISteamUGC#SubmitItemUpdate>`_

**Example**::

    See :func:`UGC.StartItemUpdate`'s example.

.. function:: UGC.SubscribeItem(nPublishedFileID, callback)

    🤖 **Auto-generated binding**

    :param uint64 nPublishedFileID:
    :param function callback: CallResult callback receiving struct `RemoteStorageSubscribePublishedFileResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `SubscribeItem <https://partner.steamgames.com/doc/api/ISteamUGC#SubscribeItem>`_

**Example**::

    Steam.UGC.SubscribeItem(publishedFileID, function(data, err)
        if err or data.m_eResult ~= Steam.k_EResultOK then
            print('Subscribe failed')
        else
            print('Subscribed to item:', tostring(data.m_nPublishedFileId))
        end
    end)

.. function:: UGC.SuspendDownloads(bSuspend)

    🤖 **Auto-generated binding**

    :param bool bSuspend:
    :SteamWorks: `SuspendDownloads <https://partner.steamgames.com/doc/api/ISteamUGC#SuspendDownloads>`_

**Example**::

    -- Pause all workshop downloads during gameplay
    Steam.UGC.SuspendDownloads(true)
    -- Resume when at main menu
    Steam.UGC.SuspendDownloads(false)

.. function:: UGC.UnsubscribeItem(nPublishedFileID, callback)

    🤖 **Auto-generated binding**

    :param uint64 nPublishedFileID:
    :param function callback: CallResult callback receiving struct `RemoteStorageUnsubscribePublishedFileResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `UnsubscribeItem <https://partner.steamgames.com/doc/api/ISteamUGC#UnsubscribeItem>`_

**Example**::

    Steam.UGC.UnsubscribeItem(publishedFileID, function(data, err)
        if not err and data.m_eResult == Steam.k_EResultOK then
            print('Unsubscribed from item')
        end
    end)

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


Unimplemented Methods
---------------------

.. function:: UGC.createQueryAllUGCRequest

    ✋ **Not implemented** - blocklist: cursor method is not used
    
    :SteamWorks: `CreateQueryAllUGCRequest <https://partner.steamgames.com/doc/api/ISteamUGC#CreateQueryAllUGCRequest>`_

.. function:: UGC.getQueryUGCKeyValueTag

    ✋ **Not implemented** - blocklist: unused, not even in API Reference
    
    :SteamWorks: `GetQueryUGCKeyValueTag <https://partner.steamgames.com/doc/api/ISteamUGC#GetQueryUGCKeyValueTag>`_


Callbacks
---------

.. function:: UGC.OnSteamUGCQueryCompleted

    Callback for `SteamUGCQueryCompleted_t <https://partner.steamgames.com/doc/api/ISteamUGC#SteamUGCQueryCompleted_t>`_

    **callback(data)** receives:

    * **data.m_handle** -- m_handle
    * **data.m_eResult** -- m_eResult
    * **data.m_unNumResultsReturned** -- m_unNumResultsReturned
    * **data.m_unTotalMatchingResults** -- m_unTotalMatchingResults
    * **data.m_bCachedData** -- m_bCachedData
    * **data.m_rgchNextCursor** -- m_rgchNextCursor

**Example**::

    function Steam.UGC.OnSteamUGCQueryCompleted(data)
        if data.m_eResultCode == Steam.k_EResultOK then
            print('Query returned', data.m_unNumResultsReturned, 'results')
        end
    end

.. function:: UGC.OnSteamUGCRequestUGCDetailsResult

    Callback for `SteamUGCRequestUGCDetailsResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#SteamUGCRequestUGCDetailsResult_t>`_

    **callback(data)** receives:

    * **data.m_details** -- m_details
    * **data.m_bCachedData** -- m_bCachedData

.. function:: UGC.OnCreateItemResult

    Callback for `CreateItemResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#CreateItemResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_bUserNeedsToAcceptWorkshopLegalAgreement** -- m_bUserNeedsToAcceptWorkshopLegalAgreement

.. function:: UGC.OnSubmitItemUpdateResult

    Callback for `SubmitItemUpdateResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#SubmitItemUpdateResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_bUserNeedsToAcceptWorkshopLegalAgreement** -- m_bUserNeedsToAcceptWorkshopLegalAgreement
    * **data.m_nPublishedFileId** -- m_nPublishedFileId

.. function:: UGC.OnItemInstalled

    Callback for `ItemInstalled_t <https://partner.steamgames.com/doc/api/ISteamUGC#ItemInstalled_t>`_

    **callback(data)** receives:

    * **data.m_unAppID** -- m_unAppID
    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_hLegacyContent** -- m_hLegacyContent
    * **data.m_unManifestID** -- m_unManifestID

**Example**::

    function Steam.UGC.OnItemInstalled(data)
        local ok, size, folder, ts = Steam.UGC.GetItemInstallInfo(data.m_nPublishedFileId, 512)
        if ok then
            print('Mod installed at:', folder)
            loadMod(folder)
        end
    end

.. function:: UGC.OnDownloadItemResult

    Callback for `DownloadItemResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#DownloadItemResult_t>`_

    **callback(data)** receives:

    * **data.m_unAppID** -- m_unAppID
    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_eResult** -- m_eResult

**Example**::

    function Steam.UGC.OnDownloadItemResult(data)
        if data.m_eResult == Steam.k_EResultOK then
            print('Item downloaded:', tostring(data.m_nPublishedFileId))
        else
            print('Download failed:', data.m_eResult)
        end
    end

.. function:: UGC.OnUserFavoriteItemsListChanged

    Callback for `UserFavoriteItemsListChanged_t <https://partner.steamgames.com/doc/api/ISteamUGC#UserFavoriteItemsListChanged_t>`_

    **callback(data)** receives:

    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_eResult** -- m_eResult
    * **data.m_bWasAddRequest** -- m_bWasAddRequest

.. function:: UGC.OnSetUserItemVoteResult

    Callback for `SetUserItemVoteResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#SetUserItemVoteResult_t>`_

    **callback(data)** receives:

    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_eResult** -- m_eResult
    * **data.m_bVoteUp** -- m_bVoteUp

.. function:: UGC.OnGetUserItemVoteResult

    Callback for `GetUserItemVoteResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#GetUserItemVoteResult_t>`_

    **callback(data)** receives:

    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_eResult** -- m_eResult
    * **data.m_bVotedUp** -- m_bVotedUp
    * **data.m_bVotedDown** -- m_bVotedDown
    * **data.m_bVoteSkipped** -- m_bVoteSkipped

.. function:: UGC.OnStartPlaytimeTrackingResult

    Callback for `StartPlaytimeTrackingResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#StartPlaytimeTrackingResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult

.. function:: UGC.OnStopPlaytimeTrackingResult

    Callback for `StopPlaytimeTrackingResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#StopPlaytimeTrackingResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult

.. function:: UGC.OnAddUGCDependencyResult

    Callback for `AddUGCDependencyResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#AddUGCDependencyResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_nChildPublishedFileId** -- m_nChildPublishedFileId

.. function:: UGC.OnRemoveUGCDependencyResult

    Callback for `RemoveUGCDependencyResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#RemoveUGCDependencyResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_nChildPublishedFileId** -- m_nChildPublishedFileId

.. function:: UGC.OnAddAppDependencyResult

    Callback for `AddAppDependencyResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#AddAppDependencyResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_nAppID** -- m_nAppID

.. function:: UGC.OnRemoveAppDependencyResult

    Callback for `RemoveAppDependencyResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#RemoveAppDependencyResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_nAppID** -- m_nAppID

.. function:: UGC.OnGetAppDependenciesResult

    Callback for `GetAppDependenciesResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#GetAppDependenciesResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_rgAppIDs** -- m_rgAppIDs
    * **data.m_nNumAppDependencies** -- m_nNumAppDependencies
    * **data.m_nTotalNumAppDependencies** -- m_nTotalNumAppDependencies

.. function:: UGC.OnDeleteItemResult

    Callback for `DeleteItemResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#DeleteItemResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nPublishedFileId** -- m_nPublishedFileId

.. function:: UGC.OnUserSubscribedItemsListChanged

    Callback for `UserSubscribedItemsListChanged_t <https://partner.steamgames.com/doc/api/ISteamUGC#UserSubscribedItemsListChanged_t>`_

    **callback(data)** receives:

    * **data.m_nAppID** -- m_nAppID

.. function:: UGC.OnWorkshopEULAStatus

    Callback for `WorkshopEULAStatus_t <https://partner.steamgames.com/doc/api/ISteamUGC#WorkshopEULAStatus_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nAppID** -- m_nAppID
    * **data.m_unVersion** -- m_unVersion
    * **data.m_rtAction** -- m_rtAction
    * **data.m_bAccepted** -- m_bAccepted
    * **data.m_bNeedsAction** -- m_bNeedsAction

