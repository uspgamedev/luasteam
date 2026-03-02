#################
ISteamScreenshots
#################

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✍️ are manually implemented and methods marked with ✋ are currently not implemented.

List of Functions
-----------------

* :func:`Screenshots.AddScreenshotToLibrary`
* :func:`Screenshots.AddVRScreenshotToLibrary`
* :func:`Screenshots.HookScreenshots`
* :func:`Screenshots.IsScreenshotsHooked`
* :func:`Screenshots.SetLocation`
* :func:`Screenshots.TagPublishedFile`
* :func:`Screenshots.TagUser`
* :func:`Screenshots.TriggerScreenshot`
* :func:`Screenshots.WriteScreenshot`

List of Callbacks
-----------------

* :func:`Screenshots.OnScreenshotReady`
* :func:`Screenshots.OnScreenshotRequested`

Function Reference
------------------

.. function:: Screenshots.AddScreenshotToLibrary(pchFilename, pchThumbnailFilename, nWidth, nHeight)

    🤖 **Auto-generated binding**

    :param str pchFilename:
    :param str pchThumbnailFilename:
    :param int nWidth:
    :param int nHeight:
    :returns: (int) Return value
    :SteamWorks: `AddScreenshotToLibrary <https://partner.steamgames.com/doc/api/ISteamScreenshots#AddScreenshotToLibrary>`_

**Example**::

    local handle = Steam.Screenshots.AddScreenshotToLibrary('screenshot.png', nil, 1920, 1080)
    if handle ~= 0 then
        Steam.Screenshots.SetLocation(handle, 'Main Menu')
    end

.. function:: Screenshots.AddVRScreenshotToLibrary(eType, pchFilename, pchVRFilename)

    🤖 **Auto-generated binding**

    :param int eType:
    :param str pchFilename:
    :param str pchVRFilename:
    :returns: (int) Return value
    :SteamWorks: `AddVRScreenshotToLibrary <https://partner.steamgames.com/doc/api/ISteamScreenshots#AddVRScreenshotToLibrary>`_

.. function:: Screenshots.HookScreenshots(bHook)

    🤖 **Auto-generated binding**

    :param bool bHook:
    :SteamWorks: `HookScreenshots <https://partner.steamgames.com/doc/api/ISteamScreenshots#HookScreenshots>`_

**Example**::

    -- Intercept F12 screenshots to add game UI before saving
    Steam.Screenshots.HookScreenshots(true)

.. function:: Screenshots.IsScreenshotsHooked()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `IsScreenshotsHooked <https://partner.steamgames.com/doc/api/ISteamScreenshots#IsScreenshotsHooked>`_

.. function:: Screenshots.SetLocation(hScreenshot, pchLocation)

    🤖 **Auto-generated binding**

    :param int hScreenshot:
    :param str pchLocation:
    :returns: (bool) Return value
    :SteamWorks: `SetLocation <https://partner.steamgames.com/doc/api/ISteamScreenshots#SetLocation>`_

**Example**::

    Steam.Screenshots.SetLocation(screenshotHandle, 'Boss Arena Level 5')

.. function:: Screenshots.TagPublishedFile(hScreenshot, unPublishedFileID)

    🤖 **Auto-generated binding**

    :param int hScreenshot:
    :param uint64 unPublishedFileID:
    :returns: (bool) Return value
    :SteamWorks: `TagPublishedFile <https://partner.steamgames.com/doc/api/ISteamScreenshots#TagPublishedFile>`_

.. function:: Screenshots.TagUser(hScreenshot, steamID)

    🤖 **Auto-generated binding**

    :param int hScreenshot:
    :param uint64 steamID:
    :returns: (bool) Return value
    :SteamWorks: `TagUser <https://partner.steamgames.com/doc/api/ISteamScreenshots#TagUser>`_

.. function:: Screenshots.TriggerScreenshot()

    🤖 **Auto-generated binding**

    :SteamWorks: `TriggerScreenshot <https://partner.steamgames.com/doc/api/ISteamScreenshots#TriggerScreenshot>`_

**Example**::

    -- Programmatically take a Steam screenshot
    Steam.Screenshots.TriggerScreenshot()

.. function:: Screenshots.WriteScreenshot(pubRGB, cubRGB, nWidth, nHeight)

    🤖 **Auto-generated binding**

    :param str pubRGB:
    :param int cubRGB:
    :param int nWidth:
    :param int nHeight:
    :returns: (int) Return value
    :SteamWorks: `WriteScreenshot <https://partner.steamgames.com/doc/api/ISteamScreenshots#WriteScreenshot>`_

**Example**::

    -- Capture the current framebuffer and add to Steam library
    local rgbData = captureFramebuffer()
    local handle = Steam.Screenshots.WriteScreenshot(rgbData, #rgbData, screenWidth, screenHeight)


Callbacks
---------

.. function:: Screenshots.OnScreenshotReady

    Callback for `ScreenshotReady_t <https://partner.steamgames.com/doc/api/ISteamScreenshots#ScreenshotReady_t>`_

    **callback(data)** receives:

    * **data.m_hLocal** -- m_hLocal
    * **data.m_eResult** -- m_eResult

**Example**::

    function Steam.Screenshots.OnScreenshotReady(data)
        if data.m_eResult == Steam.k_EResultOK then
            print('Screenshot saved, handle:', data.m_hLocal)
        end
    end

.. function:: Screenshots.OnScreenshotRequested

    Callback for `ScreenshotRequested_t <https://partner.steamgames.com/doc/api/ISteamScreenshots#ScreenshotRequested_t>`_

    **callback(data)** receives:


**Example**::

    function Steam.Screenshots.OnScreenshotRequested()
        -- User pressed F12; capture game state and submit
        local rgbData = captureFramebuffer()
        Steam.Screenshots.WriteScreenshot(rgbData, #rgbData, screenWidth, screenHeight)
    end

