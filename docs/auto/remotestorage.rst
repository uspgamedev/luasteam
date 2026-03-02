###################
ISteamRemoteStorage
###################

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✋ require manual implementation.

List of Functions
-----------------

* :func:`RemoteStorage.BeginFileWriteBatch`
* :func:`RemoteStorage.CommitPublishedFileUpdate`
* :func:`RemoteStorage.CreatePublishedFileUpdateRequest`
* :func:`RemoteStorage.DeletePublishedFile`
* :func:`RemoteStorage.EndFileWriteBatch`
* :func:`RemoteStorage.EnumeratePublishedFilesByUserAction`
* :func:`RemoteStorage.EnumeratePublishedWorkshopFiles`
* :func:`RemoteStorage.EnumerateUserPublishedFiles`
* :func:`RemoteStorage.EnumerateUserSharedWorkshopFiles`
* :func:`RemoteStorage.EnumerateUserSubscribedFiles`
* :func:`RemoteStorage.FileDelete`
* :func:`RemoteStorage.FileExists`
* :func:`RemoteStorage.FileForget`
* :func:`RemoteStorage.FilePersisted`
* :func:`RemoteStorage.FileRead`
* :func:`RemoteStorage.FileReadAsync`
* :func:`RemoteStorage.FileReadAsyncComplete`
* :func:`RemoteStorage.FileShare`
* :func:`RemoteStorage.FileWrite`
* :func:`RemoteStorage.FileWriteAsync`
* :func:`RemoteStorage.FileWriteStreamCancel`
* :func:`RemoteStorage.FileWriteStreamClose`
* :func:`RemoteStorage.FileWriteStreamOpen`
* :func:`RemoteStorage.FileWriteStreamWriteChunk`
* :func:`RemoteStorage.GetCachedUGCCount`
* :func:`RemoteStorage.GetCachedUGCHandle`
* :func:`RemoteStorage.GetFileCount`
* :func:`RemoteStorage.GetFileNameAndSize`
* :func:`RemoteStorage.GetFileSize`
* :func:`RemoteStorage.GetFileTimestamp`
* :func:`RemoteStorage.GetLocalFileChange`
* :func:`RemoteStorage.GetLocalFileChangeCount`
* :func:`RemoteStorage.GetPublishedFileDetails`
* :func:`RemoteStorage.GetPublishedItemVoteDetails`
* :func:`RemoteStorage.GetQuota`
* :func:`RemoteStorage.GetSyncPlatforms`
* :func:`RemoteStorage.GetUGCDownloadProgress`
* :func:`RemoteStorage.GetUserPublishedItemVoteDetails`
* :func:`RemoteStorage.IsCloudEnabledForAccount`
* :func:`RemoteStorage.IsCloudEnabledForApp`
* :func:`RemoteStorage.PublishVideo`
* :func:`RemoteStorage.PublishWorkshopFile`
* :func:`RemoteStorage.SetCloudEnabledForApp`
* :func:`RemoteStorage.SetSyncPlatforms`
* :func:`RemoteStorage.SetUserPublishedFileAction`
* :func:`RemoteStorage.SubscribePublishedFile`
* :func:`RemoteStorage.UGCDownload`
* :func:`RemoteStorage.UGCDownloadToLocation`
* :func:`RemoteStorage.UGCRead`
* :func:`RemoteStorage.UnsubscribePublishedFile`
* :func:`RemoteStorage.UpdatePublishedFileDescription`
* :func:`RemoteStorage.UpdatePublishedFileFile`
* :func:`RemoteStorage.UpdatePublishedFilePreviewFile`
* :func:`RemoteStorage.UpdatePublishedFileSetChangeDescription`
* :func:`RemoteStorage.UpdatePublishedFileTags`
* :func:`RemoteStorage.UpdatePublishedFileTitle`
* :func:`RemoteStorage.UpdatePublishedFileVisibility`
* :func:`RemoteStorage.UpdateUserPublishedItemVote`

List of Callbacks
-----------------

* :func:`RemoteStorage.OnRemoteStorageFileShareResult`
* :func:`RemoteStorage.OnRemoteStoragePublishFileResult`
* :func:`RemoteStorage.OnRemoteStorageDeletePublishedFileResult`
* :func:`RemoteStorage.OnRemoteStorageEnumerateUserPublishedFilesResult`
* :func:`RemoteStorage.OnRemoteStorageSubscribePublishedFileResult`
* :func:`RemoteStorage.OnRemoteStorageEnumerateUserSubscribedFilesResult`
* :func:`RemoteStorage.OnRemoteStorageUnsubscribePublishedFileResult`
* :func:`RemoteStorage.OnRemoteStorageUpdatePublishedFileResult`
* :func:`RemoteStorage.OnRemoteStorageDownloadUGCResult`
* :func:`RemoteStorage.OnRemoteStorageGetPublishedFileDetailsResult`
* :func:`RemoteStorage.OnRemoteStorageEnumerateWorkshopFilesResult`
* :func:`RemoteStorage.OnRemoteStorageGetPublishedItemVoteDetailsResult`
* :func:`RemoteStorage.OnRemoteStoragePublishedFileSubscribed`
* :func:`RemoteStorage.OnRemoteStoragePublishedFileUnsubscribed`
* :func:`RemoteStorage.OnRemoteStoragePublishedFileDeleted`
* :func:`RemoteStorage.OnRemoteStorageUpdateUserPublishedItemVoteResult`
* :func:`RemoteStorage.OnRemoteStorageUserVoteDetails`
* :func:`RemoteStorage.OnRemoteStorageEnumerateUserSharedWorkshopFilesResult`
* :func:`RemoteStorage.OnRemoteStorageSetUserPublishedFileActionResult`
* :func:`RemoteStorage.OnRemoteStorageEnumeratePublishedFilesByUserActionResult`
* :func:`RemoteStorage.OnRemoteStoragePublishFileProgress`
* :func:`RemoteStorage.OnRemoteStoragePublishedFileUpdated`
* :func:`RemoteStorage.OnRemoteStorageFileWriteAsyncComplete`
* :func:`RemoteStorage.OnRemoteStorageFileReadAsyncComplete`
* :func:`RemoteStorage.OnRemoteStorageLocalFileChange`

Function Reference
------------------

.. function:: RemoteStorage.BeginFileWriteBatch()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BeginFileWriteBatch <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#BeginFileWriteBatch>`_

**Example**::

    Steam.RemoteStorage.BeginFileWriteBatch()
    Steam.RemoteStorage.FileWrite('config.dat', configData, #configData)
    Steam.RemoteStorage.FileWrite('progress.dat', progressData, #progressData)
    Steam.RemoteStorage.EndFileWriteBatch()

.. function:: RemoteStorage.CommitPublishedFileUpdate(updateHandle, callback)

    🤖 **Auto-generated binding**

    :param uint64 updateHandle:
    :param function callback: CallResult callback receiving struct `RemoteStorageUpdatePublishedFileResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `CommitPublishedFileUpdate <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#CommitPublishedFileUpdate>`_

.. function:: RemoteStorage.CreatePublishedFileUpdateRequest(unPublishedFileId)

    🤖 **Auto-generated binding**

    :param uint64 unPublishedFileId:
    :returns: (uint64) Return value
    :SteamWorks: `CreatePublishedFileUpdateRequest <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#CreatePublishedFileUpdateRequest>`_

.. function:: RemoteStorage.DeletePublishedFile(unPublishedFileId, callback)

    🤖 **Auto-generated binding**

    :param uint64 unPublishedFileId:
    :param function callback: CallResult callback receiving struct `RemoteStorageDeletePublishedFileResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `DeletePublishedFile <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#DeletePublishedFile>`_

.. function:: RemoteStorage.EndFileWriteBatch()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `EndFileWriteBatch <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#EndFileWriteBatch>`_

.. function:: RemoteStorage.EnumeratePublishedFilesByUserAction(eAction, unStartIndex, callback)

    🤖 **Auto-generated binding**

    :param int eAction:
    :param int unStartIndex:
    :param function callback: CallResult callback receiving struct `RemoteStorageEnumeratePublishedFilesByUserActionResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `EnumeratePublishedFilesByUserAction <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#EnumeratePublishedFilesByUserAction>`_

.. function:: RemoteStorage.EnumeratePublishedWorkshopFiles(eEnumerationType, unStartIndex, unCount, unDays, callback)

    🤖 **Auto-generated binding**

    :param int eEnumerationType:
    :param int unStartIndex:
    :param int unCount:
    :param int unDays:
    :param function callback: CallResult callback receiving struct `RemoteStorageEnumerateWorkshopFilesResult_t` and a boolean
    :returns: (uint64) Return value
    :returns: (:ref:`SteamParamStringArray_t <struct-SteamParamStringArray_t>`) Value for `pTags`
    :returns: (:ref:`SteamParamStringArray_t <struct-SteamParamStringArray_t>`) Value for `pUserTags`
    :SteamWorks: `EnumeratePublishedWorkshopFiles <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#EnumeratePublishedWorkshopFiles>`_

    **Signature differences from C++ API:**

    * Parameter ``pTags`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pUserTags`` is no longer a paramer, and is instead an additional return value

.. function:: RemoteStorage.EnumerateUserPublishedFiles(unStartIndex, callback)

    🤖 **Auto-generated binding**

    :param int unStartIndex:
    :param function callback: CallResult callback receiving struct `RemoteStorageEnumerateUserPublishedFilesResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `EnumerateUserPublishedFiles <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#EnumerateUserPublishedFiles>`_

.. function:: RemoteStorage.EnumerateUserSharedWorkshopFiles(steamId, unStartIndex, callback)

    🤖 **Auto-generated binding**

    :param uint64 steamId:
    :param int unStartIndex:
    :param function callback: CallResult callback receiving struct `RemoteStorageEnumerateUserPublishedFilesResult_t` and a boolean
    :returns: (uint64) Return value
    :returns: (:ref:`SteamParamStringArray_t <struct-SteamParamStringArray_t>`) Value for `pRequiredTags`
    :returns: (:ref:`SteamParamStringArray_t <struct-SteamParamStringArray_t>`) Value for `pExcludedTags`
    :SteamWorks: `EnumerateUserSharedWorkshopFiles <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#EnumerateUserSharedWorkshopFiles>`_

    **Signature differences from C++ API:**

    * Parameter ``pRequiredTags`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pExcludedTags`` is no longer a paramer, and is instead an additional return value

.. function:: RemoteStorage.EnumerateUserSubscribedFiles(unStartIndex, callback)

    🤖 **Auto-generated binding**

    :param int unStartIndex:
    :param function callback: CallResult callback receiving struct `RemoteStorageEnumerateUserSubscribedFilesResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `EnumerateUserSubscribedFiles <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#EnumerateUserSubscribedFiles>`_

.. function:: RemoteStorage.FileDelete(pchFile)

    🤖 **Auto-generated binding**

    :param str pchFile:
    :returns: (bool) Return value
    :SteamWorks: `FileDelete <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#FileDelete>`_

**Example**::

    if Steam.RemoteStorage.FileDelete('old_save.txt') then
        print('Cloud file deleted')
    end

.. function:: RemoteStorage.FileExists(pchFile)

    🤖 **Auto-generated binding**

    :param str pchFile:
    :returns: (bool) Return value
    :SteamWorks: `FileExists <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#FileExists>`_

**Example**::

    if Steam.RemoteStorage.FileExists('savegame.txt') then
        loadCloudSave()
    else
        createNewSave()
    end

.. function:: RemoteStorage.FileForget(pchFile)

    🤖 **Auto-generated binding**

    :param str pchFile:
    :returns: (bool) Return value
    :SteamWorks: `FileForget <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#FileForget>`_

.. function:: RemoteStorage.FilePersisted(pchFile)

    🤖 **Auto-generated binding**

    :param str pchFile:
    :returns: (bool) Return value
    :SteamWorks: `FilePersisted <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#FilePersisted>`_

**Example**::

    if Steam.RemoteStorage.FilePersisted('savegame.txt') then
        print('File is synchronized to the cloud')
    end

.. function:: RemoteStorage.FileRead(pchFile, cubDataToRead)

    🤖 **Auto-generated binding**

    :param str pchFile:
    :param int cubDataToRead:
    :returns: (int) Return value
    :returns: (str) Value for `pvData`
    :SteamWorks: `FileRead <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#FileRead>`_

    **Signature differences from C++ API:**

    * Parameter ``pvData`` is no longer a paramer, and is instead an additional return value

**Example**::

    local size = Steam.RemoteStorage.GetFileSize('savegame.txt')
    local data = Steam.RemoteStorage.FileRead('savegame.txt', size)
    if data then
        loadSaveData(data)
    end

.. function:: RemoteStorage.FileReadAsync(pchFile, nOffset, cubToRead, callback)

    🤖 **Auto-generated binding**

    :param str pchFile:
    :param int nOffset:
    :param int cubToRead:
    :param function callback: CallResult callback receiving struct `RemoteStorageFileReadAsyncComplete_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `FileReadAsync <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#FileReadAsync>`_

**Example**::

    Steam.RemoteStorage.FileReadAsync('savegame.dat', 0, fileSize, function(data, err)
        if not err and data.m_eResult == Steam.k_EResultOK then
            local fileData = Steam.RemoteStorage.FileReadAsyncComplete(data.m_hFileReadAsync, fileSize)
            loadSaveData(fileData)
        end
    end)

.. function:: RemoteStorage.FileReadAsyncComplete(hReadCall, cubToRead)

    🤖 **Auto-generated binding**

    :param uint64 hReadCall:
    :param int cubToRead:
    :returns: (bool) Return value
    :returns: (str) Value for `pvBuffer`
    :SteamWorks: `FileReadAsyncComplete <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#FileReadAsyncComplete>`_

    **Signature differences from C++ API:**

    * Parameter ``pvBuffer`` is no longer a paramer, and is instead an additional return value

.. function:: RemoteStorage.FileShare(pchFile, callback)

    🤖 **Auto-generated binding**

    :param str pchFile:
    :param function callback: CallResult callback receiving struct `RemoteStorageFileShareResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `FileShare <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#FileShare>`_

.. function:: RemoteStorage.FileWrite(pchFile, pvData, cubData)

    🤖 **Auto-generated binding**

    :param str pchFile:
    :param str pvData:
    :param int cubData:
    :returns: (bool) Return value
    :SteamWorks: `FileWrite <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#FileWrite>`_

**Example**::

    local data = 'player_name=Alice
    level=42
    '
    local ok = Steam.RemoteStorage.FileWrite('savegame.txt', data, #data)
    if not ok then
        print('Failed to write cloud save')
    end

.. function:: RemoteStorage.FileWriteAsync(pchFile, pvData, cubData, callback)

    🤖 **Auto-generated binding**

    :param str pchFile:
    :param str pvData:
    :param int cubData:
    :param function callback: CallResult callback receiving struct `RemoteStorageFileWriteAsyncComplete_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `FileWriteAsync <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#FileWriteAsync>`_

**Example**::

    Steam.RemoteStorage.FileWriteAsync('autosave.dat', saveData, #saveData, function(data, err)
        if err or data.m_eResult ~= Steam.k_EResultOK then
            print('Async write failed')
        else
            print('Cloud save written asynchronously')
        end
    end)

.. function:: RemoteStorage.FileWriteStreamCancel(writeHandle)

    🤖 **Auto-generated binding**

    :param uint64 writeHandle:
    :returns: (bool) Return value
    :SteamWorks: `FileWriteStreamCancel <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#FileWriteStreamCancel>`_

.. function:: RemoteStorage.FileWriteStreamClose(writeHandle)

    🤖 **Auto-generated binding**

    :param uint64 writeHandle:
    :returns: (bool) Return value
    :SteamWorks: `FileWriteStreamClose <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#FileWriteStreamClose>`_

.. function:: RemoteStorage.FileWriteStreamOpen(pchFile)

    🤖 **Auto-generated binding**

    :param str pchFile:
    :returns: (uint64) Return value
    :SteamWorks: `FileWriteStreamOpen <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#FileWriteStreamOpen>`_

.. function:: RemoteStorage.FileWriteStreamWriteChunk(writeHandle, pvData, cubData)

    🤖 **Auto-generated binding**

    :param uint64 writeHandle:
    :param str pvData:
    :param int cubData:
    :returns: (bool) Return value
    :SteamWorks: `FileWriteStreamWriteChunk <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#FileWriteStreamWriteChunk>`_

.. function:: RemoteStorage.GetCachedUGCCount()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetCachedUGCCount <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#GetCachedUGCCount>`_

.. function:: RemoteStorage.GetCachedUGCHandle(iCachedContent)

    🤖 **Auto-generated binding**

    :param int iCachedContent:
    :returns: (uint64) Return value
    :SteamWorks: `GetCachedUGCHandle <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#GetCachedUGCHandle>`_

.. function:: RemoteStorage.GetFileCount()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetFileCount <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#GetFileCount>`_

**Example**::

    local count = Steam.RemoteStorage.GetFileCount()
    for i = 0, count - 1 do
        local name, size = Steam.RemoteStorage.GetFileNameAndSize(i)
        print(name .. ' (' .. size .. ' bytes)')
    end

.. function:: RemoteStorage.GetFileNameAndSize(iFile)

    🤖 **Auto-generated binding**

    :param int iFile:
    :returns: (str) Return value
    :returns: (int) Value for `pnFileSizeInBytes`
    :SteamWorks: `GetFileNameAndSize <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#GetFileNameAndSize>`_

    **Signature differences from C++ API:**

    * Parameter ``pnFileSizeInBytes`` is no longer a paramer, and is instead an additional return value

**Example**::

    See :func:`RemoteStorage.GetFileCount`'s example.

.. function:: RemoteStorage.GetFileSize(pchFile)

    🤖 **Auto-generated binding**

    :param str pchFile:
    :returns: (int) Return value
    :SteamWorks: `GetFileSize <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#GetFileSize>`_

**Example**::

    local size = Steam.RemoteStorage.GetFileSize('savegame.txt')
    print('Save file size: ' .. size .. ' bytes')

.. function:: RemoteStorage.GetFileTimestamp(pchFile)

    🤖 **Auto-generated binding**

    :param str pchFile:
    :returns: (uint64) Return value
    :SteamWorks: `GetFileTimestamp <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#GetFileTimestamp>`_

**Example**::

    local timestamp = Steam.RemoteStorage.GetFileTimestamp('savegame.txt')
    print('Last modified: ' .. os.date('%c', timestamp))

.. function:: RemoteStorage.GetLocalFileChange(iFile)

    🤖 **Auto-generated binding**

    :param int iFile:
    :returns: (str) Return value
    :returns: (int) Value for `pEChangeType`
    :returns: (int) Value for `pEFilePathType`
    :SteamWorks: `GetLocalFileChange <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#GetLocalFileChange>`_

    **Signature differences from C++ API:**

    * Parameter ``pEChangeType`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pEFilePathType`` is no longer a paramer, and is instead an additional return value

.. function:: RemoteStorage.GetLocalFileChangeCount()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetLocalFileChangeCount <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#GetLocalFileChangeCount>`_

**Example**::

    -- Check for external changes (e.g. from another PC)
    local count = Steam.RemoteStorage.GetLocalFileChangeCount()
    for i = 0, count - 1 do
        local name, changeType = Steam.RemoteStorage.GetLocalFileChange(i)
        print('Cloud file changed:', name, changeType)
    end

.. function:: RemoteStorage.GetPublishedFileDetails(unPublishedFileId, unMaxSecondsOld, callback)

    🤖 **Auto-generated binding**

    :param uint64 unPublishedFileId:
    :param int unMaxSecondsOld:
    :param function callback: CallResult callback receiving struct `RemoteStorageGetPublishedFileDetailsResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `GetPublishedFileDetails <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#GetPublishedFileDetails>`_

.. function:: RemoteStorage.GetPublishedItemVoteDetails(unPublishedFileId, callback)

    🤖 **Auto-generated binding**

    :param uint64 unPublishedFileId:
    :param function callback: CallResult callback receiving struct `RemoteStorageGetPublishedItemVoteDetailsResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `GetPublishedItemVoteDetails <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#GetPublishedItemVoteDetails>`_

.. function:: RemoteStorage.GetQuota()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :returns: (uint64) Value for `pnTotalBytes`
    :returns: (uint64) Value for `puAvailableBytes`
    :SteamWorks: `GetQuota <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#GetQuota>`_

    **Signature differences from C++ API:**

    * Parameter ``pnTotalBytes`` is no longer a paramer, and is instead an additional return value
    * Parameter ``puAvailableBytes`` is no longer a paramer, and is instead an additional return value

**Example**::

    local total, available = Steam.RemoteStorage.GetQuota()
    print(string.format('Cloud storage: %d/%d bytes used', total - available, total))

.. function:: RemoteStorage.GetSyncPlatforms(pchFile)

    🤖 **Auto-generated binding**

    :param str pchFile:
    :returns: (int) Return value
    :SteamWorks: `GetSyncPlatforms <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#GetSyncPlatforms>`_

.. function:: RemoteStorage.GetUGCDownloadProgress(hContent)

    🤖 **Auto-generated binding**

    :param uint64 hContent:
    :returns: (bool) Return value
    :returns: (int) Value for `pnBytesDownloaded`
    :returns: (int) Value for `pnBytesExpected`
    :SteamWorks: `GetUGCDownloadProgress <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#GetUGCDownloadProgress>`_

    **Signature differences from C++ API:**

    * Parameter ``pnBytesDownloaded`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pnBytesExpected`` is no longer a paramer, and is instead an additional return value

.. function:: RemoteStorage.GetUserPublishedItemVoteDetails(unPublishedFileId, callback)

    🤖 **Auto-generated binding**

    :param uint64 unPublishedFileId:
    :param function callback: CallResult callback receiving struct `RemoteStorageGetPublishedItemVoteDetailsResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `GetUserPublishedItemVoteDetails <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#GetUserPublishedItemVoteDetails>`_

.. function:: RemoteStorage.IsCloudEnabledForAccount()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `IsCloudEnabledForAccount <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#IsCloudEnabledForAccount>`_

.. function:: RemoteStorage.IsCloudEnabledForApp()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `IsCloudEnabledForApp <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#IsCloudEnabledForApp>`_

**Example**::

    if Steam.RemoteStorage.IsCloudEnabledForApp() then
        syncCloudSaves()
    end

.. function:: RemoteStorage.PublishVideo(eVideoProvider, pchVideoAccount, pchVideoIdentifier, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility, callback)

    🤖 **Auto-generated binding**

    :param int eVideoProvider:
    :param str pchVideoAccount:
    :param str pchVideoIdentifier:
    :param str pchPreviewFile:
    :param int nConsumerAppId:
    :param str pchTitle:
    :param str pchDescription:
    :param int eVisibility:
    :param function callback: CallResult callback receiving struct `RemoteStoragePublishFileProgress_t` and a boolean
    :returns: (uint64) Return value
    :returns: (:ref:`SteamParamStringArray_t <struct-SteamParamStringArray_t>`) Value for `pTags`
    :SteamWorks: `PublishVideo <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#PublishVideo>`_

    **Signature differences from C++ API:**

    * Parameter ``pTags`` is no longer a paramer, and is instead an additional return value

.. function:: RemoteStorage.PublishWorkshopFile(pchFile, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility, eWorkshopFileType, callback)

    🤖 **Auto-generated binding**

    :param str pchFile:
    :param str pchPreviewFile:
    :param int nConsumerAppId:
    :param str pchTitle:
    :param str pchDescription:
    :param int eVisibility:
    :param int eWorkshopFileType:
    :param function callback: CallResult callback receiving struct `RemoteStoragePublishFileProgress_t` and a boolean
    :returns: (uint64) Return value
    :returns: (:ref:`SteamParamStringArray_t <struct-SteamParamStringArray_t>`) Value for `pTags`
    :SteamWorks: `PublishWorkshopFile <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#PublishWorkshopFile>`_

    **Signature differences from C++ API:**

    * Parameter ``pTags`` is no longer a paramer, and is instead an additional return value

.. function:: RemoteStorage.SetCloudEnabledForApp(bEnabled)

    🤖 **Auto-generated binding**

    :param bool bEnabled:
    :SteamWorks: `SetCloudEnabledForApp <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#SetCloudEnabledForApp>`_

**Example**::

    -- Allow user to toggle cloud saves
    Steam.RemoteStorage.SetCloudEnabledForApp(userWantsCloud)

.. function:: RemoteStorage.SetSyncPlatforms(pchFile, eRemoteStoragePlatform)

    🤖 **Auto-generated binding**

    :param str pchFile:
    :param int eRemoteStoragePlatform:
    :returns: (bool) Return value
    :SteamWorks: `SetSyncPlatforms <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#SetSyncPlatforms>`_

.. function:: RemoteStorage.SetUserPublishedFileAction(unPublishedFileId, eAction, callback)

    🤖 **Auto-generated binding**

    :param uint64 unPublishedFileId:
    :param int eAction:
    :param function callback: CallResult callback receiving struct `RemoteStorageSetUserPublishedFileActionResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `SetUserPublishedFileAction <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#SetUserPublishedFileAction>`_

.. function:: RemoteStorage.SubscribePublishedFile(unPublishedFileId, callback)

    🤖 **Auto-generated binding**

    :param uint64 unPublishedFileId:
    :param function callback: CallResult callback receiving struct `RemoteStorageSubscribePublishedFileResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `SubscribePublishedFile <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#SubscribePublishedFile>`_

.. function:: RemoteStorage.UGCDownload(hContent, unPriority, callback)

    🤖 **Auto-generated binding**

    :param uint64 hContent:
    :param int unPriority:
    :param function callback: CallResult callback receiving struct `RemoteStorageDownloadUGCResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `UGCDownload <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#UGCDownload>`_

.. function:: RemoteStorage.UGCDownloadToLocation(hContent, pchLocation, unPriority, callback)

    🤖 **Auto-generated binding**

    :param uint64 hContent:
    :param str pchLocation:
    :param int unPriority:
    :param function callback: CallResult callback receiving struct `RemoteStorageDownloadUGCResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `UGCDownloadToLocation <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#UGCDownloadToLocation>`_

.. function:: RemoteStorage.UGCRead(hContent, cubDataToRead, cOffset, eAction)

    🤖 **Auto-generated binding**

    :param uint64 hContent:
    :param int cubDataToRead:
    :param int cOffset:
    :param int eAction:
    :returns: (int) Return value
    :returns: (str) Value for `pvData`
    :SteamWorks: `UGCRead <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#UGCRead>`_

    **Signature differences from C++ API:**

    * Parameter ``pvData`` is no longer a paramer, and is instead an additional return value

.. function:: RemoteStorage.UnsubscribePublishedFile(unPublishedFileId, callback)

    🤖 **Auto-generated binding**

    :param uint64 unPublishedFileId:
    :param function callback: CallResult callback receiving struct `RemoteStorageUnsubscribePublishedFileResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `UnsubscribePublishedFile <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#UnsubscribePublishedFile>`_

.. function:: RemoteStorage.UpdatePublishedFileDescription(updateHandle, pchDescription)

    🤖 **Auto-generated binding**

    :param uint64 updateHandle:
    :param str pchDescription:
    :returns: (bool) Return value
    :SteamWorks: `UpdatePublishedFileDescription <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#UpdatePublishedFileDescription>`_

.. function:: RemoteStorage.UpdatePublishedFileFile(updateHandle, pchFile)

    🤖 **Auto-generated binding**

    :param uint64 updateHandle:
    :param str pchFile:
    :returns: (bool) Return value
    :SteamWorks: `UpdatePublishedFileFile <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#UpdatePublishedFileFile>`_

.. function:: RemoteStorage.UpdatePublishedFilePreviewFile(updateHandle, pchPreviewFile)

    🤖 **Auto-generated binding**

    :param uint64 updateHandle:
    :param str pchPreviewFile:
    :returns: (bool) Return value
    :SteamWorks: `UpdatePublishedFilePreviewFile <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#UpdatePublishedFilePreviewFile>`_

.. function:: RemoteStorage.UpdatePublishedFileSetChangeDescription(updateHandle, pchChangeDescription)

    🤖 **Auto-generated binding**

    :param uint64 updateHandle:
    :param str pchChangeDescription:
    :returns: (bool) Return value
    :SteamWorks: `UpdatePublishedFileSetChangeDescription <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#UpdatePublishedFileSetChangeDescription>`_

.. function:: RemoteStorage.UpdatePublishedFileTags(updateHandle)

    🤖 **Auto-generated binding**

    :param uint64 updateHandle:
    :returns: (bool) Return value
    :returns: (:ref:`SteamParamStringArray_t <struct-SteamParamStringArray_t>`) Value for `pTags`
    :SteamWorks: `UpdatePublishedFileTags <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#UpdatePublishedFileTags>`_

    **Signature differences from C++ API:**

    * Parameter ``pTags`` is no longer a paramer, and is instead an additional return value

.. function:: RemoteStorage.UpdatePublishedFileTitle(updateHandle, pchTitle)

    🤖 **Auto-generated binding**

    :param uint64 updateHandle:
    :param str pchTitle:
    :returns: (bool) Return value
    :SteamWorks: `UpdatePublishedFileTitle <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#UpdatePublishedFileTitle>`_

.. function:: RemoteStorage.UpdatePublishedFileVisibility(updateHandle, eVisibility)

    🤖 **Auto-generated binding**

    :param uint64 updateHandle:
    :param int eVisibility:
    :returns: (bool) Return value
    :SteamWorks: `UpdatePublishedFileVisibility <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#UpdatePublishedFileVisibility>`_

.. function:: RemoteStorage.UpdateUserPublishedItemVote(unPublishedFileId, bVoteUp, callback)

    🤖 **Auto-generated binding**

    :param uint64 unPublishedFileId:
    :param bool bVoteUp:
    :param function callback: CallResult callback receiving struct `RemoteStorageUpdateUserPublishedItemVoteResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `UpdateUserPublishedItemVote <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#UpdateUserPublishedItemVote>`_


Unimplemented Methods
---------------------

.. function:: RemoteStorage.getUGCDetails

    ✋ **Not implemented** - blocklist: char** output semantics unclear
    
    :SteamWorks: `GetUGCDetails <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#GetUGCDetails>`_


Callbacks
---------

.. function:: RemoteStorage.OnRemoteStorageFileShareResult

    Callback for `RemoteStorageFileShareResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageFileShareResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_hFile** -- m_hFile
    * **data.m_rgchFilename** -- m_rgchFilename

.. function:: RemoteStorage.OnRemoteStoragePublishFileResult

    Callback for `RemoteStoragePublishFileResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStoragePublishFileResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_bUserNeedsToAcceptWorkshopLegalAgreement** -- m_bUserNeedsToAcceptWorkshopLegalAgreement

.. function:: RemoteStorage.OnRemoteStorageDeletePublishedFileResult

    Callback for `RemoteStorageDeletePublishedFileResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageDeletePublishedFileResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nPublishedFileId** -- m_nPublishedFileId

.. function:: RemoteStorage.OnRemoteStorageEnumerateUserPublishedFilesResult

    Callback for `RemoteStorageEnumerateUserPublishedFilesResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageEnumerateUserPublishedFilesResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nResultsReturned** -- m_nResultsReturned
    * **data.m_nTotalResultCount** -- m_nTotalResultCount
    * **data.m_rgPublishedFileId** -- m_rgPublishedFileId

.. function:: RemoteStorage.OnRemoteStorageSubscribePublishedFileResult

    Callback for `RemoteStorageSubscribePublishedFileResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageSubscribePublishedFileResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nPublishedFileId** -- m_nPublishedFileId

.. function:: RemoteStorage.OnRemoteStorageEnumerateUserSubscribedFilesResult

    Callback for `RemoteStorageEnumerateUserSubscribedFilesResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageEnumerateUserSubscribedFilesResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nResultsReturned** -- m_nResultsReturned
    * **data.m_nTotalResultCount** -- m_nTotalResultCount
    * **data.m_rgPublishedFileId** -- m_rgPublishedFileId
    * **data.m_rgRTimeSubscribed** -- m_rgRTimeSubscribed

.. function:: RemoteStorage.OnRemoteStorageUnsubscribePublishedFileResult

    Callback for `RemoteStorageUnsubscribePublishedFileResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageUnsubscribePublishedFileResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nPublishedFileId** -- m_nPublishedFileId

.. function:: RemoteStorage.OnRemoteStorageUpdatePublishedFileResult

    Callback for `RemoteStorageUpdatePublishedFileResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageUpdatePublishedFileResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_bUserNeedsToAcceptWorkshopLegalAgreement** -- m_bUserNeedsToAcceptWorkshopLegalAgreement

.. function:: RemoteStorage.OnRemoteStorageDownloadUGCResult

    Callback for `RemoteStorageDownloadUGCResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageDownloadUGCResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_hFile** -- m_hFile
    * **data.m_nAppID** -- m_nAppID
    * **data.m_nSizeInBytes** -- m_nSizeInBytes
    * **data.m_pchFileName** -- m_pchFileName
    * **data.m_ulSteamIDOwner** -- m_ulSteamIDOwner

.. function:: RemoteStorage.OnRemoteStorageGetPublishedFileDetailsResult

    Callback for `RemoteStorageGetPublishedFileDetailsResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageGetPublishedFileDetailsResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_nCreatorAppID** -- m_nCreatorAppID
    * **data.m_nConsumerAppID** -- m_nConsumerAppID
    * **data.m_rgchTitle** -- m_rgchTitle
    * **data.m_rgchDescription** -- m_rgchDescription
    * **data.m_hFile** -- m_hFile
    * **data.m_hPreviewFile** -- m_hPreviewFile
    * **data.m_ulSteamIDOwner** -- m_ulSteamIDOwner
    * **data.m_rtimeCreated** -- m_rtimeCreated
    * **data.m_rtimeUpdated** -- m_rtimeUpdated
    * **data.m_eVisibility** -- m_eVisibility
    * **data.m_bBanned** -- m_bBanned
    * **data.m_rgchTags** -- m_rgchTags
    * **data.m_bTagsTruncated** -- m_bTagsTruncated
    * **data.m_pchFileName** -- m_pchFileName
    * **data.m_nFileSize** -- m_nFileSize
    * **data.m_nPreviewFileSize** -- m_nPreviewFileSize
    * **data.m_rgchURL** -- m_rgchURL
    * **data.m_eFileType** -- m_eFileType
    * **data.m_bAcceptedForUse** -- m_bAcceptedForUse

.. function:: RemoteStorage.OnRemoteStorageEnumerateWorkshopFilesResult

    Callback for `RemoteStorageEnumerateWorkshopFilesResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageEnumerateWorkshopFilesResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nResultsReturned** -- m_nResultsReturned
    * **data.m_nTotalResultCount** -- m_nTotalResultCount
    * **data.m_rgPublishedFileId** -- m_rgPublishedFileId
    * **data.m_rgScore** -- m_rgScore
    * **data.m_nAppId** -- m_nAppId
    * **data.m_unStartIndex** -- m_unStartIndex

.. function:: RemoteStorage.OnRemoteStorageGetPublishedItemVoteDetailsResult

    Callback for `RemoteStorageGetPublishedItemVoteDetailsResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageGetPublishedItemVoteDetailsResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_unPublishedFileId** -- m_unPublishedFileId
    * **data.m_nVotesFor** -- m_nVotesFor
    * **data.m_nVotesAgainst** -- m_nVotesAgainst
    * **data.m_nReports** -- m_nReports
    * **data.m_fScore** -- m_fScore

.. function:: RemoteStorage.OnRemoteStoragePublishedFileSubscribed

    Callback for `RemoteStoragePublishedFileSubscribed_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStoragePublishedFileSubscribed_t>`_

    **callback(data)** receives:

    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_nAppID** -- m_nAppID

.. function:: RemoteStorage.OnRemoteStoragePublishedFileUnsubscribed

    Callback for `RemoteStoragePublishedFileUnsubscribed_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStoragePublishedFileUnsubscribed_t>`_

    **callback(data)** receives:

    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_nAppID** -- m_nAppID

.. function:: RemoteStorage.OnRemoteStoragePublishedFileDeleted

    Callback for `RemoteStoragePublishedFileDeleted_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStoragePublishedFileDeleted_t>`_

    **callback(data)** receives:

    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_nAppID** -- m_nAppID

.. function:: RemoteStorage.OnRemoteStorageUpdateUserPublishedItemVoteResult

    Callback for `RemoteStorageUpdateUserPublishedItemVoteResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageUpdateUserPublishedItemVoteResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nPublishedFileId** -- m_nPublishedFileId

.. function:: RemoteStorage.OnRemoteStorageUserVoteDetails

    Callback for `RemoteStorageUserVoteDetails_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageUserVoteDetails_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_eVote** -- m_eVote

.. function:: RemoteStorage.OnRemoteStorageEnumerateUserSharedWorkshopFilesResult

    Callback for `RemoteStorageEnumerateUserSharedWorkshopFilesResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageEnumerateUserSharedWorkshopFilesResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nResultsReturned** -- m_nResultsReturned
    * **data.m_nTotalResultCount** -- m_nTotalResultCount
    * **data.m_rgPublishedFileId** -- m_rgPublishedFileId

.. function:: RemoteStorage.OnRemoteStorageSetUserPublishedFileActionResult

    Callback for `RemoteStorageSetUserPublishedFileActionResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageSetUserPublishedFileActionResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_eAction** -- m_eAction

.. function:: RemoteStorage.OnRemoteStorageEnumeratePublishedFilesByUserActionResult

    Callback for `RemoteStorageEnumeratePublishedFilesByUserActionResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageEnumeratePublishedFilesByUserActionResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_eAction** -- m_eAction
    * **data.m_nResultsReturned** -- m_nResultsReturned
    * **data.m_nTotalResultCount** -- m_nTotalResultCount
    * **data.m_rgPublishedFileId** -- m_rgPublishedFileId
    * **data.m_rgRTimeUpdated** -- m_rgRTimeUpdated

.. function:: RemoteStorage.OnRemoteStoragePublishFileProgress

    Callback for `RemoteStoragePublishFileProgress_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStoragePublishFileProgress_t>`_

    **callback(data)** receives:

    * **data.m_dPercentFile** -- m_dPercentFile
    * **data.m_bPreview** -- m_bPreview

.. function:: RemoteStorage.OnRemoteStoragePublishedFileUpdated

    Callback for `RemoteStoragePublishedFileUpdated_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStoragePublishedFileUpdated_t>`_

    **callback(data)** receives:

    * **data.m_nPublishedFileId** -- m_nPublishedFileId
    * **data.m_nAppID** -- m_nAppID
    * **data.m_ulUnused** -- m_ulUnused

.. function:: RemoteStorage.OnRemoteStorageFileWriteAsyncComplete

    Callback for `RemoteStorageFileWriteAsyncComplete_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageFileWriteAsyncComplete_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult

.. function:: RemoteStorage.OnRemoteStorageFileReadAsyncComplete

    Callback for `RemoteStorageFileReadAsyncComplete_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageFileReadAsyncComplete_t>`_

    **callback(data)** receives:

    * **data.m_hFileReadAsync** -- m_hFileReadAsync
    * **data.m_eResult** -- m_eResult
    * **data.m_nOffset** -- m_nOffset
    * **data.m_cubRead** -- m_cubRead

.. function:: RemoteStorage.OnRemoteStorageLocalFileChange

    Callback for `RemoteStorageLocalFileChange_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageLocalFileChange_t>`_

    **callback(data)** receives:


**Example**::

    function Steam.RemoteStorage.OnRemoteStorageLocalFileChange()
        local count = Steam.RemoteStorage.GetLocalFileChangeCount()
        print('Cloud file changes detected:', count)
        reloadCloudSaves()
    end

