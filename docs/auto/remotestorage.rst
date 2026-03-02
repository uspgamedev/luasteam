###################
ISteamRemoteStorage
###################

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✍️ are manually implemented and methods marked with ✋ are currently not implemented.

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
    :param function callback: CallResult callback receiving struct :func:`RemoteStorageUpdatePublishedFileResult_t <RemoteStorage.OnRemoteStorageUpdatePublishedFileResult>` and a boolean
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
    :param function callback: CallResult callback receiving struct :func:`RemoteStorageDeletePublishedFileResult_t <RemoteStorage.OnRemoteStorageDeletePublishedFileResult>` and a boolean
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
    :param function callback: CallResult callback receiving struct :func:`RemoteStorageEnumeratePublishedFilesByUserActionResult_t <RemoteStorage.OnRemoteStorageEnumeratePublishedFilesByUserActionResult>` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `EnumeratePublishedFilesByUserAction <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#EnumeratePublishedFilesByUserAction>`_

.. function:: RemoteStorage.EnumeratePublishedWorkshopFiles(eEnumerationType, unStartIndex, unCount, unDays, callback)

    🤖 **Auto-generated binding**

    :param int eEnumerationType:
    :param int unStartIndex:
    :param int unCount:
    :param int unDays:
    :param function callback: CallResult callback receiving struct :func:`RemoteStorageEnumerateWorkshopFilesResult_t <RemoteStorage.OnRemoteStorageEnumerateWorkshopFilesResult>` and a boolean
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
    :param function callback: CallResult callback receiving struct :func:`RemoteStorageEnumerateUserPublishedFilesResult_t <RemoteStorage.OnRemoteStorageEnumerateUserPublishedFilesResult>` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `EnumerateUserPublishedFiles <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#EnumerateUserPublishedFiles>`_

.. function:: RemoteStorage.EnumerateUserSharedWorkshopFiles(steamId, unStartIndex, callback)

    🤖 **Auto-generated binding**

    :param uint64 steamId:
    :param int unStartIndex:
    :param function callback: CallResult callback receiving struct :func:`RemoteStorageEnumerateUserPublishedFilesResult_t <RemoteStorage.OnRemoteStorageEnumerateUserPublishedFilesResult>` and a boolean
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
    :param function callback: CallResult callback receiving struct :func:`RemoteStorageEnumerateUserSubscribedFilesResult_t <RemoteStorage.OnRemoteStorageEnumerateUserSubscribedFilesResult>` and a boolean
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
    :param int cubDataToRead: size of the buffer to be allocated to hold the return value ``pvData``
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
    :param function callback: CallResult callback receiving struct :func:`RemoteStorageFileReadAsyncComplete_t <RemoteStorage.OnRemoteStorageFileReadAsyncComplete>` and a boolean
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
    :param int cubToRead: size of the buffer to be allocated to hold the return value ``pvBuffer``
    :returns: (bool) Return value
    :returns: (str) Value for `pvBuffer`
    :SteamWorks: `FileReadAsyncComplete <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#FileReadAsyncComplete>`_

    **Signature differences from C++ API:**

    * Parameter ``pvBuffer`` is no longer a paramer, and is instead an additional return value

.. function:: RemoteStorage.FileShare(pchFile, callback)

    🤖 **Auto-generated binding**

    :param str pchFile:
    :param function callback: CallResult callback receiving struct :func:`RemoteStorageFileShareResult_t <RemoteStorage.OnRemoteStorageFileShareResult>` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `FileShare <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#FileShare>`_

.. function:: RemoteStorage.FileWrite(pchFile, pvData, cubData)

    🤖 **Auto-generated binding**

    :param str pchFile:
    :param str pvData:
    :param int cubData: size of the input array ``pvData``
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
    :param int cubData: size of the input array ``pvData``
    :param function callback: CallResult callback receiving struct :func:`RemoteStorageFileWriteAsyncComplete_t <RemoteStorage.OnRemoteStorageFileWriteAsyncComplete>` and a boolean
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
    :param int cubData: size of the input array ``pvData``
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

    **Notes:**

    * See :func:`RemoteStorage.GetFileCount`'s example.

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
    :param function callback: CallResult callback receiving struct :func:`RemoteStorageGetPublishedFileDetailsResult_t <RemoteStorage.OnRemoteStorageGetPublishedFileDetailsResult>` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `GetPublishedFileDetails <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#GetPublishedFileDetails>`_

.. function:: RemoteStorage.GetPublishedItemVoteDetails(unPublishedFileId, callback)

    🤖 **Auto-generated binding**

    :param uint64 unPublishedFileId:
    :param function callback: CallResult callback receiving struct :func:`RemoteStorageGetPublishedItemVoteDetailsResult_t <RemoteStorage.OnRemoteStorageGetPublishedItemVoteDetailsResult>` and a boolean
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
    :param function callback: CallResult callback receiving struct :func:`RemoteStorageGetPublishedItemVoteDetailsResult_t <RemoteStorage.OnRemoteStorageGetPublishedItemVoteDetailsResult>` and a boolean
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
    :param function callback: CallResult callback receiving struct :func:`RemoteStoragePublishFileProgress_t <RemoteStorage.OnRemoteStoragePublishFileProgress>` and a boolean
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
    :param function callback: CallResult callback receiving struct :func:`RemoteStoragePublishFileProgress_t <RemoteStorage.OnRemoteStoragePublishFileProgress>` and a boolean
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
    :param function callback: CallResult callback receiving struct :func:`RemoteStorageSetUserPublishedFileActionResult_t <RemoteStorage.OnRemoteStorageSetUserPublishedFileActionResult>` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `SetUserPublishedFileAction <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#SetUserPublishedFileAction>`_

.. function:: RemoteStorage.SubscribePublishedFile(unPublishedFileId, callback)

    🤖 **Auto-generated binding**

    :param uint64 unPublishedFileId:
    :param function callback: CallResult callback receiving struct :func:`RemoteStorageSubscribePublishedFileResult_t <RemoteStorage.OnRemoteStorageSubscribePublishedFileResult>` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `SubscribePublishedFile <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#SubscribePublishedFile>`_

.. function:: RemoteStorage.UGCDownload(hContent, unPriority, callback)

    🤖 **Auto-generated binding**

    :param uint64 hContent:
    :param int unPriority:
    :param function callback: CallResult callback receiving struct :func:`RemoteStorageDownloadUGCResult_t <RemoteStorage.OnRemoteStorageDownloadUGCResult>` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `UGCDownload <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#UGCDownload>`_

.. function:: RemoteStorage.UGCDownloadToLocation(hContent, pchLocation, unPriority, callback)

    🤖 **Auto-generated binding**

    :param uint64 hContent:
    :param str pchLocation:
    :param int unPriority:
    :param function callback: CallResult callback receiving struct :func:`RemoteStorageDownloadUGCResult_t <RemoteStorage.OnRemoteStorageDownloadUGCResult>` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `UGCDownloadToLocation <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#UGCDownloadToLocation>`_

.. function:: RemoteStorage.UGCRead(hContent, cubDataToRead, cOffset, eAction)

    🤖 **Auto-generated binding**

    :param uint64 hContent:
    :param int cubDataToRead: size of the buffer to be allocated to hold the return value ``pvData``
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
    :param function callback: CallResult callback receiving struct :func:`RemoteStorageUnsubscribePublishedFileResult_t <RemoteStorage.OnRemoteStorageUnsubscribePublishedFileResult>` and a boolean
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
    :param function callback: CallResult callback receiving struct :func:`RemoteStorageUpdateUserPublishedItemVoteResult_t <RemoteStorage.OnRemoteStorageUpdateUserPublishedItemVoteResult>` and a boolean
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

    * **data.m_eResult** *(EResult)*
    * **data.m_hFile** *(UGCHandle_t)*
    * **data.m_rgchFilename** *(string)*

.. function:: RemoteStorage.OnRemoteStoragePublishFileResult

    Callback for `RemoteStoragePublishFileResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStoragePublishFileResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(EResult)*
    * **data.m_nPublishedFileId** *(PublishedFileId_t)*
    * **data.m_bUserNeedsToAcceptWorkshopLegalAgreement** *(bool)*

.. function:: RemoteStorage.OnRemoteStorageDeletePublishedFileResult

    Callback for `RemoteStorageDeletePublishedFileResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageDeletePublishedFileResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(EResult)*
    * **data.m_nPublishedFileId** *(PublishedFileId_t)*

.. function:: RemoteStorage.OnRemoteStorageEnumerateUserPublishedFilesResult

    Callback for `RemoteStorageEnumerateUserPublishedFilesResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageEnumerateUserPublishedFilesResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(EResult)*
    * **data.m_nResultsReturned** *(int)*
    * **data.m_nTotalResultCount** *(int)*
    * **data.m_rgPublishedFileId** *(PublishedFileId_t)*

.. function:: RemoteStorage.OnRemoteStorageSubscribePublishedFileResult

    Callback for `RemoteStorageSubscribePublishedFileResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageSubscribePublishedFileResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(EResult)*
    * **data.m_nPublishedFileId** *(PublishedFileId_t)*

.. function:: RemoteStorage.OnRemoteStorageEnumerateUserSubscribedFilesResult

    Callback for `RemoteStorageEnumerateUserSubscribedFilesResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageEnumerateUserSubscribedFilesResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(EResult)*
    * **data.m_nResultsReturned** *(int)*
    * **data.m_nTotalResultCount** *(int)*
    * **data.m_rgPublishedFileId** *(PublishedFileId_t)*
    * **data.m_rgRTimeSubscribed** *(int)*

.. function:: RemoteStorage.OnRemoteStorageUnsubscribePublishedFileResult

    Callback for `RemoteStorageUnsubscribePublishedFileResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageUnsubscribePublishedFileResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(EResult)*
    * **data.m_nPublishedFileId** *(PublishedFileId_t)*

.. function:: RemoteStorage.OnRemoteStorageUpdatePublishedFileResult

    Callback for `RemoteStorageUpdatePublishedFileResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageUpdatePublishedFileResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(EResult)*
    * **data.m_nPublishedFileId** *(PublishedFileId_t)*
    * **data.m_bUserNeedsToAcceptWorkshopLegalAgreement** *(bool)*

.. function:: RemoteStorage.OnRemoteStorageDownloadUGCResult

    Callback for `RemoteStorageDownloadUGCResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageDownloadUGCResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(EResult)*
    * **data.m_hFile** *(UGCHandle_t)*
    * **data.m_nAppID** *(AppId_t)*
    * **data.m_nSizeInBytes** *(int)*
    * **data.m_pchFileName** *(string)*
    * **data.m_ulSteamIDOwner** *(uint64)*

.. function:: RemoteStorage.OnRemoteStorageGetPublishedFileDetailsResult

    Callback for `RemoteStorageGetPublishedFileDetailsResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageGetPublishedFileDetailsResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(EResult)*
    * **data.m_nPublishedFileId** *(PublishedFileId_t)*
    * **data.m_nCreatorAppID** *(AppId_t)*
    * **data.m_nConsumerAppID** *(AppId_t)*
    * **data.m_rgchTitle** *(string)*
    * **data.m_rgchDescription** *(string)*
    * **data.m_hFile** *(UGCHandle_t)*
    * **data.m_hPreviewFile** *(UGCHandle_t)*
    * **data.m_ulSteamIDOwner** *(uint64)*
    * **data.m_rtimeCreated** *(int)*
    * **data.m_rtimeUpdated** *(int)*
    * **data.m_eVisibility** *(ERemoteStoragePublishedFileVisibility)*
    * **data.m_bBanned** *(bool)*
    * **data.m_rgchTags** *(string)*
    * **data.m_bTagsTruncated** *(bool)*
    * **data.m_pchFileName** *(string)*
    * **data.m_nFileSize** *(int)*
    * **data.m_nPreviewFileSize** *(int)*
    * **data.m_rgchURL** *(string)*
    * **data.m_eFileType** *(EWorkshopFileType)*
    * **data.m_bAcceptedForUse** *(bool)*

.. function:: RemoteStorage.OnRemoteStorageEnumerateWorkshopFilesResult

    Callback for `RemoteStorageEnumerateWorkshopFilesResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageEnumerateWorkshopFilesResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(EResult)*
    * **data.m_nResultsReturned** *(int)*
    * **data.m_nTotalResultCount** *(int)*
    * **data.m_rgPublishedFileId** *(PublishedFileId_t)*
    * **data.m_rgScore** *(float)*
    * **data.m_nAppId** *(AppId_t)*
    * **data.m_unStartIndex** *(int)*

.. function:: RemoteStorage.OnRemoteStorageGetPublishedItemVoteDetailsResult

    Callback for `RemoteStorageGetPublishedItemVoteDetailsResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageGetPublishedItemVoteDetailsResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(EResult)*
    * **data.m_unPublishedFileId** *(PublishedFileId_t)*
    * **data.m_nVotesFor** *(int)*
    * **data.m_nVotesAgainst** *(int)*
    * **data.m_nReports** *(int)*
    * **data.m_fScore** *(float)*

.. function:: RemoteStorage.OnRemoteStoragePublishedFileSubscribed

    Callback for `RemoteStoragePublishedFileSubscribed_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStoragePublishedFileSubscribed_t>`_

    **callback(data)** receives:

    * **data.m_nPublishedFileId** *(PublishedFileId_t)*
    * **data.m_nAppID** *(AppId_t)*

.. function:: RemoteStorage.OnRemoteStoragePublishedFileUnsubscribed

    Callback for `RemoteStoragePublishedFileUnsubscribed_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStoragePublishedFileUnsubscribed_t>`_

    **callback(data)** receives:

    * **data.m_nPublishedFileId** *(PublishedFileId_t)*
    * **data.m_nAppID** *(AppId_t)*

.. function:: RemoteStorage.OnRemoteStoragePublishedFileDeleted

    Callback for `RemoteStoragePublishedFileDeleted_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStoragePublishedFileDeleted_t>`_

    **callback(data)** receives:

    * **data.m_nPublishedFileId** *(PublishedFileId_t)*
    * **data.m_nAppID** *(AppId_t)*

.. function:: RemoteStorage.OnRemoteStorageUpdateUserPublishedItemVoteResult

    Callback for `RemoteStorageUpdateUserPublishedItemVoteResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageUpdateUserPublishedItemVoteResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(EResult)*
    * **data.m_nPublishedFileId** *(PublishedFileId_t)*

.. function:: RemoteStorage.OnRemoteStorageUserVoteDetails

    Callback for `RemoteStorageUserVoteDetails_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageUserVoteDetails_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(EResult)*
    * **data.m_nPublishedFileId** *(PublishedFileId_t)*
    * **data.m_eVote** *(EWorkshopVote)*

.. function:: RemoteStorage.OnRemoteStorageEnumerateUserSharedWorkshopFilesResult

    Callback for `RemoteStorageEnumerateUserSharedWorkshopFilesResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageEnumerateUserSharedWorkshopFilesResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(EResult)*
    * **data.m_nResultsReturned** *(int)*
    * **data.m_nTotalResultCount** *(int)*
    * **data.m_rgPublishedFileId** *(PublishedFileId_t)*

.. function:: RemoteStorage.OnRemoteStorageSetUserPublishedFileActionResult

    Callback for `RemoteStorageSetUserPublishedFileActionResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageSetUserPublishedFileActionResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(EResult)*
    * **data.m_nPublishedFileId** *(PublishedFileId_t)*
    * **data.m_eAction** *(EWorkshopFileAction)*

.. function:: RemoteStorage.OnRemoteStorageEnumeratePublishedFilesByUserActionResult

    Callback for `RemoteStorageEnumeratePublishedFilesByUserActionResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageEnumeratePublishedFilesByUserActionResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(EResult)*
    * **data.m_eAction** *(EWorkshopFileAction)*
    * **data.m_nResultsReturned** *(int)*
    * **data.m_nTotalResultCount** *(int)*
    * **data.m_rgPublishedFileId** *(PublishedFileId_t)*
    * **data.m_rgRTimeUpdated** *(int)*

.. function:: RemoteStorage.OnRemoteStoragePublishFileProgress

    Callback for `RemoteStoragePublishFileProgress_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStoragePublishFileProgress_t>`_

    **callback(data)** receives:

    * **data.m_dPercentFile** *(float)*
    * **data.m_bPreview** *(bool)*

.. function:: RemoteStorage.OnRemoteStoragePublishedFileUpdated

    Callback for `RemoteStoragePublishedFileUpdated_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStoragePublishedFileUpdated_t>`_

    **callback(data)** receives:

    * **data.m_nPublishedFileId** *(PublishedFileId_t)*
    * **data.m_nAppID** *(AppId_t)*
    * **data.m_ulUnused** *(uint64)*

.. function:: RemoteStorage.OnRemoteStorageFileWriteAsyncComplete

    Callback for `RemoteStorageFileWriteAsyncComplete_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageFileWriteAsyncComplete_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(EResult)*

.. function:: RemoteStorage.OnRemoteStorageFileReadAsyncComplete

    Callback for `RemoteStorageFileReadAsyncComplete_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageFileReadAsyncComplete_t>`_

    **callback(data)** receives:

    * **data.m_hFileReadAsync** *(SteamAPICall_t)*
    * **data.m_eResult** *(EResult)*
    * **data.m_nOffset** *(int)*
    * **data.m_cubRead** *(int)*

.. function:: RemoteStorage.OnRemoteStorageLocalFileChange

    Callback for `RemoteStorageLocalFileChange_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageLocalFileChange_t>`_

    **callback(data)** receives no fields (notification only).

**Example**::

    function Steam.RemoteStorage.OnRemoteStorageLocalFileChange()
        local count = Steam.RemoteStorage.GetLocalFileChangeCount()
        print('Cloud file changes detected:', count)
        reloadCloudSaves()
    end

