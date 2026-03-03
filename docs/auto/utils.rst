###########
ISteamUtils
###########

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✍️ are manually implemented and methods marked with ✋ are currently not implemented.

List of Functions
-----------------

* :func:`Utils.BOverlayNeedsPresent`
* :func:`Utils.CheckFileSignature`
* :func:`Utils.DismissFloatingGamepadTextInput`
* :func:`Utils.DismissGamepadTextInput`
* :func:`Utils.FilterText`
* :func:`Utils.GetAPICallFailureReason`
* :func:`Utils.GetAPICallResult`
* :func:`Utils.GetAppID`
* :func:`Utils.GetConnectedUniverse`
* :func:`Utils.GetCurrentBatteryPower`
* :func:`Utils.GetEnteredGamepadTextInput`
* :func:`Utils.GetEnteredGamepadTextLength`
* :func:`Utils.GetIPCCallCount`
* :func:`Utils.GetIPCountry`
* :func:`Utils.GetIPv6ConnectivityState`
* :func:`Utils.GetImageRGBA`
* :func:`Utils.GetImageSize`
* :func:`Utils.GetSecondsSinceAppActive`
* :func:`Utils.GetSecondsSinceComputerActive`
* :func:`Utils.GetServerRealTime`
* :func:`Utils.GetSteamUILanguage`
* :func:`Utils.InitFilterText`
* :func:`Utils.IsAPICallCompleted`
* :func:`Utils.IsOverlayEnabled`
* :func:`Utils.IsSteamChinaLauncher`
* :func:`Utils.IsSteamInBigPictureMode`
* :func:`Utils.IsSteamRunningInVR`
* :func:`Utils.IsSteamRunningOnSteamDeck`
* :func:`Utils.IsVRHeadsetStreamingEnabled`
* :func:`Utils.SetGameLauncherMode`
* :func:`Utils.SetOverlayNotificationInset`
* :func:`Utils.SetOverlayNotificationPosition`
* :func:`Utils.SetVRHeadsetStreamingEnabled`
* :func:`Utils.ShowFloatingGamepadTextInput`
* :func:`Utils.ShowGamepadTextInput`
* :func:`Utils.StartVRDashboard`

List of Callbacks
-----------------

* :func:`Utils.OnIPCountry`
* :func:`Utils.OnLowBatteryPower`
* :func:`Utils.OnSteamAPICallCompleted`
* :func:`Utils.OnSteamShutdown`
* :func:`Utils.OnCheckFileSignature`
* :func:`Utils.OnGamepadTextInputDismissed`
* :func:`Utils.OnAppResumingFromSuspend`
* :func:`Utils.OnFloatingGamepadTextInputDismissed`
* :func:`Utils.OnFilterTextDictionaryChanged`

Function Reference
------------------

.. function:: Utils.BOverlayNeedsPresent()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BOverlayNeedsPresent <https://partner.steamgames.com/doc/api/ISteamUtils#BOverlayNeedsPresent>`_

**Example**::

    -- Call after rendering your frame
    if Steam.Utils.BOverlayNeedsPresent() then
        presentFrame()
    end

.. function:: Utils.CheckFileSignature(szFileName, callback)

    🤖 **Auto-generated binding**

    :param str? szFileName:
    :param function callback: CallResult callback receiving struct :func:`CheckFileSignature_t <Utils.OnCheckFileSignature>` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `CheckFileSignature <https://partner.steamgames.com/doc/api/ISteamUtils#CheckFileSignature>`_

.. function:: Utils.DismissFloatingGamepadTextInput()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `DismissFloatingGamepadTextInput <https://partner.steamgames.com/doc/api/ISteamUtils#DismissFloatingGamepadTextInput>`_

.. function:: Utils.DismissGamepadTextInput()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `DismissGamepadTextInput <https://partner.steamgames.com/doc/api/ISteamUtils#DismissGamepadTextInput>`_

.. function:: Utils.FilterText(eContext, sourceSteamID, pchInputMessage, nByteSizeOutFilteredText)

    🤖 **Auto-generated binding**

    :param int eContext:
    :param uint64 sourceSteamID:
    :param str? pchInputMessage:
    :param int? nByteSizeOutFilteredText: size of the buffer to allocate for ``pchOutFilteredText``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (int) Return value
    :returns: (str) ``pchOutFilteredText``
    :SteamWorks: `FilterText <https://partner.steamgames.com/doc/api/ISteamUtils#FilterText>`_

    **Signature differences from C++ API:**

    * Parameter ``pchOutFilteredText`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    local ok, filtered = Steam.Utils.FilterText('Chat', Steam.User.GetSteamID(), userInput, #userInput + 1)
    if ok then
        displayMessage(filtered)
    end

.. function:: Utils.GetAPICallFailureReason(hSteamAPICall)

    🤖 **Auto-generated binding**

    :param uint64 hSteamAPICall:
    :returns: (int) Return value
    :SteamWorks: `GetAPICallFailureReason <https://partner.steamgames.com/doc/api/ISteamUtils#GetAPICallFailureReason>`_

.. function:: Utils.GetAPICallResult(hSteamAPICall, cubCallback, iCallbackExpected)

    🤖 **Auto-generated binding**

    :param uint64 hSteamAPICall:
    :param int? cubCallback: size of the buffer to allocate for ``pCallback``. If ``nil`` then the buffer will be ``NULL``.
    :param int iCallbackExpected:
    :returns: (bool) Return value
    :returns: (str) ``pCallback``
    :returns: (bool) ``pbFailed``
    :SteamWorks: `GetAPICallResult <https://partner.steamgames.com/doc/api/ISteamUtils#GetAPICallResult>`_

    **Signature differences from C++ API:**

    * Parameter ``pCallback`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.
    * Parameter ``pbFailed`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: Utils.GetAppID()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetAppID <https://partner.steamgames.com/doc/api/ISteamUtils#GetAppID>`_

**Example**::

    print("My app id is " .. Steam.Utils.GetAppID())

.. function:: Utils.GetConnectedUniverse()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetConnectedUniverse <https://partner.steamgames.com/doc/api/ISteamUtils#GetConnectedUniverse>`_

.. function:: Utils.GetCurrentBatteryPower()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetCurrentBatteryPower <https://partner.steamgames.com/doc/api/ISteamUtils#GetCurrentBatteryPower>`_

**Example**::

    local power = Steam.Utils.GetCurrentBatteryPower()
    if power < 20 then
        print('Low battery: ' .. power .. '%')
    end

.. function:: Utils.GetEnteredGamepadTextInput(cchText)

    🤖 **Auto-generated binding**

    :param int? cchText: size of the buffer to allocate for ``pchText``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (bool) Return value
    :returns: (str) ``pchText``
    :SteamWorks: `GetEnteredGamepadTextInput <https://partner.steamgames.com/doc/api/ISteamUtils#GetEnteredGamepadTextInput>`_

    **Signature differences from C++ API:**

    * Parameter ``pchText`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: Utils.GetEnteredGamepadTextLength()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetEnteredGamepadTextLength <https://partner.steamgames.com/doc/api/ISteamUtils#GetEnteredGamepadTextLength>`_

.. function:: Utils.GetIPCCallCount()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetIPCCallCount <https://partner.steamgames.com/doc/api/ISteamUtils#GetIPCCallCount>`_

.. function:: Utils.GetIPCountry()

    🤖 **Auto-generated binding**

    :returns: (str) Return value
    :SteamWorks: `GetIPCountry <https://partner.steamgames.com/doc/api/ISteamUtils#GetIPCountry>`_

**Example**::

    local country = Steam.Utils.GetIPCountry()
    print('Player is from: ' .. country)

.. function:: Utils.GetIPv6ConnectivityState(eProtocol)

    🤖 **Auto-generated binding**

    :param int eProtocol:
    :returns: (int) Return value
    :SteamWorks: `GetIPv6ConnectivityState <https://partner.steamgames.com/doc/api/ISteamUtils#GetIPv6ConnectivityState>`_

.. function:: Utils.GetImageRGBA(iImage, nDestBufferSize)

    🤖 **Auto-generated binding**

    :param int iImage:
    :param int? nDestBufferSize: size of the buffer to allocate for ``pubDest``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (bool) Return value
    :returns: (str) ``pubDest``
    :SteamWorks: `GetImageRGBA <https://partner.steamgames.com/doc/api/ISteamUtils#GetImageRGBA>`_

    **Signature differences from C++ API:**

    * Parameter ``pubDest`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    local w, h = Steam.Utils.GetImageSize(imageHandle)
    local rgba = Steam.Utils.GetImageRGBA(imageHandle, w * h * 4)
    -- rgba is a string of raw RGBA bytes; upload to a texture
    uploadTexture(rgba, w, h)

.. function:: Utils.GetImageSize(iImage)

    🤖 **Auto-generated binding**

    :param int iImage:
    :returns: (bool) Return value
    :returns: (int) ``pnWidth``
    :returns: (int) ``pnHeight``
    :SteamWorks: `GetImageSize <https://partner.steamgames.com/doc/api/ISteamUtils#GetImageSize>`_

    **Signature differences from C++ API:**

    * Parameter ``pnWidth`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.
    * Parameter ``pnHeight`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    local w, h = Steam.Utils.GetImageSize(imageHandle)
    print(string.format('Image: %dx%d', w, h))

.. function:: Utils.GetSecondsSinceAppActive()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetSecondsSinceAppActive <https://partner.steamgames.com/doc/api/ISteamUtils#GetSecondsSinceAppActive>`_

**Example**::

    local seconds = Steam.Utils.GetSecondsSinceAppActive()
    print('App active for ' .. seconds .. ' seconds')

.. function:: Utils.GetSecondsSinceComputerActive()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetSecondsSinceComputerActive <https://partner.steamgames.com/doc/api/ISteamUtils#GetSecondsSinceComputerActive>`_

.. function:: Utils.GetServerRealTime()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetServerRealTime <https://partner.steamgames.com/doc/api/ISteamUtils#GetServerRealTime>`_

**Example**::

    local realTime = Steam.Utils.GetServerRealTime()
    print('Steam server time: ' .. realTime)

.. function:: Utils.GetSteamUILanguage()

    🤖 **Auto-generated binding**

    :returns: (str) Return value
    :SteamWorks: `GetSteamUILanguage <https://partner.steamgames.com/doc/api/ISteamUtils#GetSteamUILanguage>`_

**Example**::

    local lang = Steam.Utils.GetSteamUILanguage()
    print('Steam UI language: ' .. lang)

.. function:: Utils.InitFilterText(unFilterOptions)

    🤖 **Auto-generated binding**

    :param int unFilterOptions:
    :returns: (bool) Return value
    :SteamWorks: `InitFilterText <https://partner.steamgames.com/doc/api/ISteamUtils#InitFilterText>`_

.. function:: Utils.IsAPICallCompleted(hSteamAPICall)

    🤖 **Auto-generated binding**

    :param uint64 hSteamAPICall:
    :returns: (bool) Return value
    :returns: (bool) ``pbFailed``
    :SteamWorks: `IsAPICallCompleted <https://partner.steamgames.com/doc/api/ISteamUtils#IsAPICallCompleted>`_

    **Signature differences from C++ API:**

    * Parameter ``pbFailed`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: Utils.IsOverlayEnabled()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `IsOverlayEnabled <https://partner.steamgames.com/doc/api/ISteamUtils#IsOverlayEnabled>`_

**Example**::

    if not Steam.Utils.IsOverlayEnabled() then
        print('Steam overlay is disabled')
    end

.. function:: Utils.IsSteamChinaLauncher()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `IsSteamChinaLauncher <https://partner.steamgames.com/doc/api/ISteamUtils#IsSteamChinaLauncher>`_

.. function:: Utils.IsSteamInBigPictureMode()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `IsSteamInBigPictureMode <https://partner.steamgames.com/doc/api/ISteamUtils#IsSteamInBigPictureMode>`_

**Example**::

    if Steam.Utils.IsSteamInBigPictureMode() then
        -- Use controller-friendly UI
    end

.. function:: Utils.IsSteamRunningInVR()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `IsSteamRunningInVR <https://partner.steamgames.com/doc/api/ISteamUtils#IsSteamRunningInVR>`_

**Example**::

    if Steam.Utils.IsSteamRunningInVR() then
        enableVRMode()
    end

.. function:: Utils.IsSteamRunningOnSteamDeck()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `IsSteamRunningOnSteamDeck <https://partner.steamgames.com/doc/api/ISteamUtils#IsSteamRunningOnSteamDeck>`_

**Example**::

    if Steam.Utils.IsSteamRunningOnSteamDeck() then
        -- Enable Steam Deck specific controls
    end

.. function:: Utils.IsVRHeadsetStreamingEnabled()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `IsVRHeadsetStreamingEnabled <https://partner.steamgames.com/doc/api/ISteamUtils#IsVRHeadsetStreamingEnabled>`_

.. function:: Utils.SetGameLauncherMode(bLauncherMode)

    🤖 **Auto-generated binding**

    :param bool bLauncherMode:
    :SteamWorks: `SetGameLauncherMode <https://partner.steamgames.com/doc/api/ISteamUtils#SetGameLauncherMode>`_

.. function:: Utils.SetOverlayNotificationInset(nHorizontalInset, nVerticalInset)

    🤖 **Auto-generated binding**

    :param int nHorizontalInset:
    :param int nVerticalInset:
    :SteamWorks: `SetOverlayNotificationInset <https://partner.steamgames.com/doc/api/ISteamUtils#SetOverlayNotificationInset>`_

**Example**::

    Steam.Utils.SetOverlayNotificationInset(10, 10)

.. function:: Utils.SetOverlayNotificationPosition(eNotificationPosition)

    🤖 **Auto-generated binding**

    :param int eNotificationPosition:
    :SteamWorks: `SetOverlayNotificationPosition <https://partner.steamgames.com/doc/api/ISteamUtils#SetOverlayNotificationPosition>`_

**Example**::

    Steam.Utils.SetOverlayNotificationPosition(Steam.k_EPositionTopRight)

.. function:: Utils.SetVRHeadsetStreamingEnabled(bEnabled)

    🤖 **Auto-generated binding**

    :param bool bEnabled:
    :SteamWorks: `SetVRHeadsetStreamingEnabled <https://partner.steamgames.com/doc/api/ISteamUtils#SetVRHeadsetStreamingEnabled>`_

.. function:: Utils.ShowFloatingGamepadTextInput(eKeyboardMode, nTextFieldXPosition, nTextFieldYPosition, nTextFieldWidth, nTextFieldHeight)

    🤖 **Auto-generated binding**

    :param int eKeyboardMode:
    :param int nTextFieldXPosition:
    :param int nTextFieldYPosition:
    :param int nTextFieldWidth:
    :param int nTextFieldHeight:
    :returns: (bool) Return value
    :SteamWorks: `ShowFloatingGamepadTextInput <https://partner.steamgames.com/doc/api/ISteamUtils#ShowFloatingGamepadTextInput>`_

**Example**::

    -- For bottom of window use 0,0,0,0
    -- For top of window use 0,windowHeight/2,windowWidth,windowHeight/2
    Steam.Utils.ShowFloatingGamepadTextInput('SingleLine', x, y, w, h)

.. function:: Utils.ShowGamepadTextInput(eInputMode, eLineInputMode, pchDescription, unCharMax, pchExistingText)

    🤖 **Auto-generated binding**

    :param int eInputMode:
    :param int eLineInputMode:
    :param str? pchDescription:
    :param int unCharMax:
    :param str? pchExistingText:
    :returns: (bool) Return value
    :SteamWorks: `ShowGamepadTextInput <https://partner.steamgames.com/doc/api/ISteamUtils#ShowGamepadTextInput>`_

**Example**::

    Steam.Utils.ShowGamepadTextInput('Normal', 'SingleLine', 'Enter your name', 64, existing_name)

.. function:: Utils.StartVRDashboard()

    🤖 **Auto-generated binding**

    :SteamWorks: `StartVRDashboard <https://partner.steamgames.com/doc/api/ISteamUtils#StartVRDashboard>`_


Callbacks
---------

.. function:: Utils.OnIPCountry

    Callback for `IPCountry_t <https://partner.steamgames.com/doc/api/ISteamUtils#IPCountry_t>`_

    **callback(data)** receives no fields (notification only).

**Example**::

    function Steam.Utils.OnIPCountry()
        print('IP country changed to: ' .. Steam.Utils.GetIPCountry())
    end

.. function:: Utils.OnLowBatteryPower

    Callback for `LowBatteryPower_t <https://partner.steamgames.com/doc/api/ISteamUtils#LowBatteryPower_t>`_

    **callback(data)** receives:

    * **data.m_nMinutesBatteryLeft** *(int)*

**Example**::

    function Steam.Utils.OnLowBatteryPower(data)
        print('Low battery warning: ' .. data.m_nMinutesBatteryLeft .. ' minutes left')
    end

.. function:: Utils.OnSteamAPICallCompleted

    Callback for `SteamAPICallCompleted_t <https://partner.steamgames.com/doc/api/ISteamUtils#SteamAPICallCompleted_t>`_

    **callback(data)** receives:

    * **data.m_hAsyncCall** *(SteamAPICall_t)*
    * **data.m_iCallback** *(int)*
    * **data.m_cubParam** *(int)*

.. function:: Utils.OnSteamShutdown

    Callback for `SteamShutdown_t <https://partner.steamgames.com/doc/api/ISteamUtils#SteamShutdown_t>`_

    **callback(data)** receives no fields (notification only).

**Example**::

    function Steam.Utils.OnSteamShutdown()
        print('Steam is shutting down, saving game...')
        saveGame()
    end

.. function:: Utils.OnCheckFileSignature

    Callback for `CheckFileSignature_t <https://partner.steamgames.com/doc/api/ISteamUtils#CheckFileSignature_t>`_

    **callback(data)** receives:

    * **data.m_eCheckFileSignature** *(ECheckFileSignature)*

.. function:: Utils.OnGamepadTextInputDismissed

    Callback for `GamepadTextInputDismissed_t <https://partner.steamgames.com/doc/api/ISteamUtils#GamepadTextInputDismissed_t>`_

    **callback(data)** receives:

    * **data.m_bSubmitted** *(bool)*
    * **data.m_unSubmittedText** *(int)*
    * **data.m_unAppID** *(AppId_t)*

**Example**::

    function Steam.Utils.OnGamepadTextInputDismissed(data)
        if not data.m_bSubmitted then return end  -- User canceled
        local length = Steam.Utils.GetEnteredGamepadTextLength()
        local newstring = Steam.Utils.GetEnteredGamepadTextInput(length)
        -- Use the string entered by the user
    end

.. function:: Utils.OnAppResumingFromSuspend

    Callback for `AppResumingFromSuspend_t <https://partner.steamgames.com/doc/api/ISteamUtils#AppResumingFromSuspend_t>`_

    **callback(data)** receives no fields (notification only).

.. function:: Utils.OnFloatingGamepadTextInputDismissed

    Callback for `FloatingGamepadTextInputDismissed_t <https://partner.steamgames.com/doc/api/ISteamUtils#FloatingGamepadTextInputDismissed_t>`_

    **callback(data)** receives no fields (notification only).

**Example**::

    function Steam.Utils.OnFloatingGamepadTextInputDismissed()
        -- Floating keyboard was closed
    end

.. function:: Utils.OnFilterTextDictionaryChanged

    Callback for `FilterTextDictionaryChanged_t <https://partner.steamgames.com/doc/api/ISteamUtils#FilterTextDictionaryChanged_t>`_

    **callback(data)** receives:

    * **data.m_eLanguage** *(int)*

