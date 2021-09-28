#########
ISteamUGC
#########

List of Functions
-----------------

* :func:`UGC.createItem`
* :func:`UGC.startItemUpdate`
* :func:`UGC.setItemContent`
* :func:`UGC.setItemDescription`
* :func:`UGC.setItemPreview`
* :func:`UGC.setItemTitle`
* :func:`UGC.submitItemUpdateResult`
* :func:`UGC.getNumSubscribedItems`
* :func:`UGC.getSubscribedItems`
* :func:`UGC.getItemState`
* :func:`UGC.getItemInstallInfo`
* :func:`UGC.getItemUpdateProgress`
* :func:`UGC.startPlaytimeTracking`
* :func:`UGC.stopPlaytimeTracking`
* :func:`UGC.stopPlaytimeTrackingForAllItems`
* :func:`UGC.subscribeItem`
* :func:`UGC.unsubscribeItem`

Function Reference
------------------

.. function:: UGC.createItem (consumerAppId, fileType, callback)

    :param number consumerAppId: The App ID that will be using this item.
    :param string fileType: The type of UGC to create. Must be one of 'Community', 'Microtransaction', 'Collection', 'Art', 'Video', 'Screenshot', 'WebGuide', 'IntegratedGuide', 'Merch', 'ControllerBinding', 'SteamVideo' or 'GameManagedItem' (see `EWorkshopFileType <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#EWorkshopFileType>`_).
    :param function callback: Called asynchronously when this function returns. See below.
    :returns: nothing
    :SteamWorks: `CreateItem <https://partner.steamgames.com/doc/api/ISteamUGC#CreateItem>`_

    Creates a new workshop item with no content attached yet.

    **callback(data, err)** receives two arguments:

    * **data** (`table`) -- Similar to `CreateItemResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#CreateItemResult_t>`_, or **nil** if **err** is **true**.

        * **data.result** (`number`) -- The result of the operation. See `EResult <https://partner.steamgames.com/doc/api/steam_api#EResult>`_.

        * **data.publishedFileId** (`uint64`) -- The new items unique ID.

        * **data.userNeedsToAcceptWorkshopLegalAgreement** (`boolean`) -- Does the user need to accept the Steam Workshop legal agreement (**true**) or not (**false**)? See the `Workshop Legal Agreement <https://partner.steamgames.com/doc/features/workshop/implementation#Legal>`_ for more information.

    * **err** (`boolean`): **true** if there was any IO error with the request.

**Example**::

    Steam.UGC.createItem(Steam.utils.getAppID(), "Community", function(data, err)
        if err or data.result ~= 1 then
            print('Failure when creating item')
        else
            populateItem(data.publishedFileId)
        end
    end)

.. function:: UGC.startItemUpdate (consumerAppId, publishedFileId)

    :param number consumerAppId: The App ID that will be using this item.
    :param uint64 publishedFileId: The item to update.
    :returns: (`uint64`) A handle that you can use with future calls to modify the item before finally sending the update.
    :SteamWorks: `StartItemUpdate <https://partner.steamgames.com/doc/api/ISteamUGC#StartItemUpdate>`_

    Starts the item update process.

    This gets you a handle that you can use to modify the item before finally sending off the update to the server with :func:`UGC.submitItemUpdate`.

**Example**::

    local function populateItem(id)
        local handle = Steam.UGC.startItemUpdate(Steam.utils.getAppID(), id)
        Steam.UGC.setItemContent(handle, rootFolder)
        Steam.UGC.setItemTitle(handle, "My Item")
        Steam.UGC.setItemDescription(handle, "A Workshop item")
        Steam.UGC.setItemPreview(handle, rootFolder .. '/preview.png')
        Steam.UGC.submitItemUpdate(handle, "First Revision", function(data, err)
            if err or data.result ~= 1 then
                print('Update failed')
            else
                print('Update successfull')
            end
        end)
    end

.. function:: UGC.setItemContent (updateHandle, contentFolder)

    :param uint64 updateHandle: The workshop item update handle to customize.
    :param string contentFolder: The absolute path to a local folder containing the content for the item.
    :returns: (`boolean`) **true** upon success. **false** if the UGC update handle is invalid.
    :SteamWorks: `SetItemContent <https://partner.steamgames.com/doc/api/ISteamUGC#SetItemContent>`_

    Sets the folder that will be stored as the content for an item.

    For efficient upload and download, files should not be merged or compressed into single files (e.g. zip files).

    .. note::

        This must be set before you submit the UGC update handle using :func:`UGC.submitItemUpdate`.


**Example**:: See :func:`UGC.startItemUpdate`'s example.

.. function:: UGC.setItemDescription (updateHandle, description)

    :param uint64 updateHandle: The workshop item update handle to customize.
    :param string description: The new description of the item.
    :returns: (`boolean`) **true** upon success. **false** if the UGC update handle is invalid.
    :SteamWorks: `SetItemDescription <https://partner.steamgames.com/doc/api/ISteamUGC#SetItemDescription>`_

    Sets a new description for an item.

    The description must be limited to the length defined by `k_cchPublishedDocumentDescriptionMax <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#k_cchPublishedDocumentDescriptionMax>`_.

    You can set what language this is for by using :func:`UGC.setItemUpdateLanguage` **(missing)**, if no language is set then "english" is assumed.

    .. note::

        This must be set before you submit the UGC update handle using :func:`UGC.submitItemUpdate`.

**Example**:: See :func:`UGC.startItemUpdate`'s example.

.. function:: UGC.setItemPreview (updateHandle, previewFile)

    :param uint64 updateHandle: The workshop item update handle to customize.
    :param string previewFile: The absolute path to a local preview image file for the item.
    :returns: **true** upon success. **false** if the UGC update handle is invalid.
    :SteamWorks: `SetItemPreview <https://partner.steamgames.com/doc/api/ISteamUGC#SetItemPreview>`_

    Sets the primary preview image for the item.

    The format should be one that both the web and the application (if necessary) can render. Suggested formats include JPG, PNG and GIF.

    .. note::

        This must be set before you submit the UGC update handle using :func:`UGC.submitItemUpdate`.

**Example**:: See :func:`UGC.startItemUpdate`'s example.

.. function:: UGC.setItemTitle (updateHandle, title)

    :param uint64 updateHandle: The workshop item update handle to customize.
    :param string title: The new title of the item.
    :returns: (`boolean`) **true** upon success. **false** if the UGC update handle is invalid.
    :SteamWorks: `SetItemTitle <https://partner.steamgames.com/doc/api/ISteamUGC#SetItemTitle>`_

    Sets a new title for an item.

    The title must be limited to the size defined by `k_cchPublishedDocumentTitleMax <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#k_cchPublishedDocumentTitleMax>`_.

    You can set what language this is for by using :func:`UGC.setItemUpdateLanguage`, if no language is set then "english" is assumed.

    .. note::

        This must be set before you submit the UGC update handle using :func:`UGC.submitItemUpdate`.

**Example**:: See :func:`UGC.startItemUpdate`'s example.

.. function:: UGC.submitItemUpdate (updateHandle, changeNote, callback)

    :param uint64 updateHandle: The update handle to submit.
    :param string? changeNote: A brief description of the changes made (Optional, set to **nil** for no change note).
    :param function callback: Called asynchronously when this function returns. See below.
    :returns: nothing
    :SteamWorks: `SubmitItemUpdateResult <https://partner.steamgames.com/doc/api/ISteamUGC#SubmitItemUpdate>`_

    Uploads the changes made to an item to the Steam Workshop.

    You can track the progress of an item update with :func:`UGC.getItemUpdateProgress`.

    **callback(data, err)** receives two arguments:

    * **data** (`table`) -- Similar to `SubmitItemUpdateResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#SubmitItemUpdateResult_t>`_, or **nil** if **err** is **true**.

        * **data.result** (`number`) -- The result of the operation. See `EResult <https://partner.steamgames.com/doc/api/steam_api#EResult>`_.

        * **data.userNeedsToAcceptWorkshopLegalAgreement** (`boolean`) -- Does the user need to accept the Steam Workshop legal agreement (**true**) or not (**false**)? See the `Workshop Legal Agreement <https://partner.steamgames.com/doc/features/workshop/implementation#Legal>`_ for more information.

    * **err** (`boolean`): **true** if there was any IO error with the request.

**Example**:: See :func:`UGC.startItemUpdate`'s example.

.. function:: UGC.getNumSubscribedItems ()

    :returns: (`number`) Total number of subscribed items. **0** if called from a game server.
    :SteamWorks: `GetNumSubscribedItems <https://partner.steamgames.com/doc/api/ISteamUGC#GetNumSubscribedItems>`_

    Gets the total number of items the current user is subscribed to for the game or application.

**Example**::

    print('You are subscribed to ' .. Steam.UGC.getNumSubscribedItems() .. ' items')

.. function:: UGC.getSubscribedItems ()

    :returns: (`table`) An array of `PublishedFileId` (more precisely, `uint64`) for all your subscribed items. Empty if called from a game server.
    :SteamWorks: `GetSubscribedItems <https://partner.steamgames.com/doc/api/ISteamUGC#GetSubscribedItems>`_

    Gets a list of all of the items the current user is subscribed to for the current game.

.. warning::

    This function is slightly different from the SteamWorks API. You don't need to send the array, it is returned by the function.

**Example**::

    for _, id in ipairs(Steam.UGC.getSubscribedItems()) do
        local flag = Steam.UGC.getItemState(id)
        if flag.installed then
            print('Subscribed item is installed!')
            local success, sizeOnDisk, folder = Steam.UGC.getItemInstallInfo(id)
            print('Install location: ' .. folder)
            print('Install size: ' .. sizeOnDisk)
        elseif flag.downloading then
            print('Subscribed item is downloading!')
        else
            print('Subscribed item is doing something')
        end
    end

.. function:: UGC.getItemState (publishedFileId)

    :param uint64 publishedFileId: The workshop item to get the state for.
    :returns: (`table`) A table with flags for the item state, or nil if the item is not tracked on client. All flags are boolean values.

        * **subscribed** -- The current user is subscribed to this item. Not just cached.

        * **legacyItem** -- The item was created with the old workshop functions in ISteamRemoteStorage.

        * **installed** -- Item is installed and usable (but maybe out of date).

        * **needsUpdate** -- The items needs an update. Either because it's not installed yet or creator updated the content.

        * **downloading** -- The item update is currently downloading.

        * **downloadPending** -- :func:`UGC.downloadItem` **(missing)** was called for this item, the content isn't available until the callback is fired.

    :SteamWorks: `GetItemState <https://partner.steamgames.com/doc/api/ISteamUGC#GetItemState>`_

    Gets the current state of a workshop item on this client.

**Example**:: See :func:`UGC.getSubscribedItems`'s example.

.. function:: UGC.getItemInstallInfo (id)

    :returns: (`boolean`) **true** if the operation is successfull. **false** in the following cases:

        * cchFolderSize is 0.

        * The workshop item has no content.

        * The workshop item is not installed.

        If this value is **false**, nothing else is returned. Otherwise:

    :returns: (`number`) Returns the size of the workshop item in bytes.
    :returns: (`string`) Returns the absolute path to the folder containing the content.
    :returns: (`number`) Returns the time when the workshop item was last updated.
    :SteamWorks: `GetItemInstallInfo <https://partner.steamgames.com/doc/api/ISteamUGC#GetItemInstallInfo>`_

    Gets info about currently installed content on the disc for workshop items that have ``installed`` set.

    Calling this sets the "used" flag on the workshop item for the current player and adds it to their ``usedOrPlayed`` list.

    If ``legacyItem`` is set then folder contains the path to the legacy file itself, not a folder.

**Example**:: See :func:`UGC.getSubscribedItems`'s example.

.. function:: UGC.getItemUpdateProgress (handle)

    :param uint64 handle: The update handle to get the progress for.
    :returns: (`string`) The current status. One of 'Invalid', 'PreparingConfig', 'PreparingContent', 'UploadingContent', 'UploadingPreviewFile', 'CommittingChanges'. See `EItemUpdateStatus <https://partner.steamgames.com/doc/api/ISteamUGC#EItemUpdateStatus>`_.
    :returns: (`number`) The current number of bytes uploaded.
    :returns: (`number`) The total number of bytes that will be uploaded.
    :SteamWorks: `GetItemUpdateProgress <https://partner.steamgames.com/doc/api/ISteamUGC#GetItemUpdateProgress>`_

    Gets the progress of an item update.

**Example**::

    local rev = {
        PreparingConfig = 0,
        PreparingContent = 1,
        UploadingContent = 2,
        UploadingPreviewFile = 3,
        CommittingChanges = 4,
        Invalid = 5, -- also Invalid when the job is finished
    }
    local function get_progress(handle)
        local st, uploaded, total = Steam.UGC.getItemUpdateProgress(handle)
        local p = rev[st] / 5
        -- total may be 0 depending on the status
        if total ~= 0 then
            p = p + 0.2 * (uploaded / total)
        end
        return p
    end

.. function:: UGC.startPlaytimeTracking (vec, callback)

    :param table vec: The array of workshop items (`PublishedFileId`, more precisely `uint64`) you want to start tracking. (Maximum of 100 items.)
    :param function callback: Called asynchronously when this function returns. It is only called if you send between 1 and 100 items. See below.
    :returns: nothing
    :SteamWorks: `StartPlaytimeTracking <https://partner.steamgames.com/doc/api/ISteamUGC#StartPlaytimeTracking>`_

    Start tracking playtime on a set of workshop items.

    When your app shuts down, playtime tracking will automatically stop.
    **callback(data, err)** receives two arguments:

    * **data** (`table`) -- Similar to `StartPlaytimeTrackingResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#StartPlaytimeTrackingResult_t>`_, or **nil** if **err** is **true**.

        * **data.result** (`number`) -- The result of the operation. See `EResult <https://partner.steamgames.com/doc/api/steam_api#EResult>`_.

    * **err** (`boolean`): **true** if there was any IO error with the request.

**Example**::

    -- Tracks all subscribed items (you probably shouldn't do this)
    Steam.UGC.startPlaytimeTracking(Steam.UGC.getSubscribedItems(), function(data, err)
        if not err and data.result == 1 then
            print('Tracking succeded')
        end
    end)

.. function:: UGC.stopPlaytimeTracking (vec, callback)

    :param table vec: The array of workshop items (`PublishedFileId`, more precisely `uint64`) you want to stop tracking. (Maximum of 100 items.)
    :param function callback: Called asynchronously when this function returns. It is only called if you send between 1 and 100 items. See below.
    :returns: nothing
    :SteamWorks: `StopPlaytimeTracking <https://partner.steamgames.com/doc/api/ISteamUGC#StopPlaytimeTracking>`_

    Stop tracking playtime on a set of workshop items.

    When your app shuts down, playtime tracking will automatically stop.

    **callback(data, err)** receives two arguments:

    * **data** (`table`) -- Similar to `StopPlaytimeTrackingResult_t <https://partner.steamgames.com/doc/api/ISteamUGC#StopPlaytimeTrackingResult_t>`_, or **nil** if **err** is **true**.

        * **data.result** (`number`) -- The result of the operation. See `EResult <https://partner.steamgames.com/doc/api/steam_api#EResult>`_.

    * **err** (`boolean`): **true** if there was any IO error with the request.

**Example**::

    local function stopTracking(...)
        Steam.UGC.stopPlaytimeTracking({...}, function(data, err)
            if not err and data.result == 1 then
                print('Tracking successfully stopped')
            end
        end)
    end


.. function:: UGC.stopPlaytimeTrackingForAllItems (callback)

    :param function callback: Called asynchronously when this function returns. It must be of the same type as the callback in :func:`UGC.stopPlaytimeTracking`.
    :returns: nothing
    :SteamWorks: `StopPlaytimeTracking <https://partner.steamgames.com/doc/api/ISteamUGC#StopPlaytimeTracking>`_

    Stop tracking playtime of all workshop items.

    When your app shuts down, playtime tracking will automatically stop.

**Example**::

    Steam.UGC.stopPlaytimeTrackingForAllItems(function(data, err)
        if not err and data.result == 1 then
            print('Tracking successfully stopped for all items')
        end
    end)


.. function:: UGC.subscribeItem (itemId, callback)

    :param uint64 itemId: The workshop item to subscribe to.
    :param function callback: Called asynchronously when this function returns. See below.
    :returns: nothing
    :SteamWorks: `SubscribeItem <https://partner.steamgames.com/doc/api/ISteamUGC#SubscribeItem>`_

    Subscribe to a workshop item. It will be downloaded and installed as soon as possible.

    **callback(data, err)** receives two arguments:

    * **data** (`table`) -- Similar to `RemoteStorageSubscribePublishedFileResult_t <https://partner.steamgames.com/doc/api/ISteamRemoteStorage#RemoteStorageSubscribePublishedFileResult_t>`_, or **nil** if **err** is **true**.

        * **data.result** (`number`) -- The result of the operation. See `EResult <https://partner.steamgames.com/doc/api/steam_api#EResult>`_.

        * **data.publishedFileId** (`uint64`) -- The workshop item that the user subscribed to.

    * **err** (`boolean`): **true** if there was any IO error with the request.

**Example**::

    -- Note: itemID is uint64, not a standard Lua number!
    Steam.UGC.subscribeItem(itemID, function(data, err)
        if not err and data.result == 1 then
            print('Successfully subscribed to ' .. itemID .. '!')
        end
    end)


.. function:: UGC.unsubscribeItem (itemId, callback)

    :param uint64 itemId: The workshop item to unsubscribe from.
    :param function callback: Called asynchronously when this function returns. It must be of the same type as the callback in :func:`UGC.subscribeItem`.
    :returns: nothing
    :SteamWorks: `UnsubscribeItem <https://partner.steamgames.com/doc/api/ISteamUGC#UnsubscribeItem>`_

    Unsubscribe from a workshop item. This will result in the item being removed after the game quits.

**Example**:: See :func:`UGC.subscribeItem`'s example.