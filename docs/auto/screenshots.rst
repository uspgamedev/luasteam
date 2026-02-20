#################
ISteamScreenshots
#################

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✋ require manual implementation.

List of Functions
-----------------

* :func:`Screenshots.WriteScreenshot`
* :func:`Screenshots.AddScreenshotToLibrary`
* :func:`Screenshots.TriggerScreenshot`
* :func:`Screenshots.HookScreenshots`
* :func:`Screenshots.SetLocation`
* :func:`Screenshots.TagUser`
* :func:`Screenshots.TagPublishedFile`
* :func:`Screenshots.IsScreenshotsHooked`
* :func:`Screenshots.AddVRScreenshotToLibrary`

List of Callbacks
-----------------

* :func:`Screenshots.onScreenshotReady`
* :func:`Screenshots.onScreenshotRequested`

Function Reference
------------------

.. function:: Screenshots.WriteScreenshot(pubRGB, cubRGB, nWidth, nHeight)

    🤖 **Auto-generated binding**

    :param str pubRGB:
    :param int cubRGB:
    :param int nWidth:
    :param int nHeight:
    :returns: (int) Return value
    :SteamWorks: `WriteScreenshot <https://partner.steamgames.com/doc/api/ISteamScreenshots#WriteScreenshot>`_

.. function:: Screenshots.AddScreenshotToLibrary(pchFilename, pchThumbnailFilename, nWidth, nHeight)

    🤖 **Auto-generated binding**

    :param str pchFilename:
    :param str pchThumbnailFilename:
    :param int nWidth:
    :param int nHeight:
    :returns: (int) Return value
    :SteamWorks: `AddScreenshotToLibrary <https://partner.steamgames.com/doc/api/ISteamScreenshots#AddScreenshotToLibrary>`_

.. function:: Screenshots.TriggerScreenshot()

    🤖 **Auto-generated binding**

    :SteamWorks: `TriggerScreenshot <https://partner.steamgames.com/doc/api/ISteamScreenshots#TriggerScreenshot>`_

.. function:: Screenshots.HookScreenshots(bHook)

    🤖 **Auto-generated binding**

    :param bool bHook:
    :SteamWorks: `HookScreenshots <https://partner.steamgames.com/doc/api/ISteamScreenshots#HookScreenshots>`_

.. function:: Screenshots.SetLocation(hScreenshot, pchLocation)

    🤖 **Auto-generated binding**

    :param int hScreenshot:
    :param str pchLocation:
    :returns: (bool) Return value
    :SteamWorks: `SetLocation <https://partner.steamgames.com/doc/api/ISteamScreenshots#SetLocation>`_

.. function:: Screenshots.TagUser(hScreenshot, steamID)

    🤖 **Auto-generated binding**

    :param int hScreenshot:
    :param uint64 steamID:
    :returns: (bool) Return value
    :SteamWorks: `TagUser <https://partner.steamgames.com/doc/api/ISteamScreenshots#TagUser>`_

.. function:: Screenshots.TagPublishedFile(hScreenshot, unPublishedFileID)

    🤖 **Auto-generated binding**

    :param int hScreenshot:
    :param uint64 unPublishedFileID:
    :returns: (bool) Return value
    :SteamWorks: `TagPublishedFile <https://partner.steamgames.com/doc/api/ISteamScreenshots#TagPublishedFile>`_

.. function:: Screenshots.IsScreenshotsHooked()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `IsScreenshotsHooked <https://partner.steamgames.com/doc/api/ISteamScreenshots#IsScreenshotsHooked>`_

.. function:: Screenshots.AddVRScreenshotToLibrary(eType, pchFilename, pchVRFilename)

    🤖 **Auto-generated binding**

    :param int eType:
    :param str pchFilename:
    :param str pchVRFilename:
    :returns: (int) Return value
    :SteamWorks: `AddVRScreenshotToLibrary <https://partner.steamgames.com/doc/api/ISteamScreenshots#AddVRScreenshotToLibrary>`_


Callbacks
---------

.. function:: Screenshots.onScreenshotReady

    Callback for `ScreenshotReady_t <https://partner.steamgames.com/doc/api/steam_api#ScreenshotReady_t>`_

    **callback(data)** receives:

    * **data.m_hLocal** -- m_hLocal
    * **data.m_eResult** -- m_eResult

.. function:: Screenshots.onScreenshotRequested

    Callback for `ScreenshotRequested_t <https://partner.steamgames.com/doc/api/steam_api#ScreenshotRequested_t>`_

    **callback(data)** receives:


