###########
ISteamUtils
###########

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✋ require manual implementation.

List of Functions
-----------------

* :func:`Utils.GetSecondsSinceAppActive`
* :func:`Utils.GetSecondsSinceComputerActive`
* :func:`Utils.GetConnectedUniverse`
* :func:`Utils.GetServerRealTime`
* :func:`Utils.GetIPCountry`
* :func:`Utils.GetImageSize`
* :func:`Utils.GetImageRGBA`
* :func:`Utils.GetCurrentBatteryPower`
* :func:`Utils.GetAppID`
* :func:`Utils.SetOverlayNotificationPosition`
* :func:`Utils.IsAPICallCompleted`
* :func:`Utils.GetAPICallFailureReason`
* :func:`Utils.GetAPICallResult`
* :func:`Utils.GetIPCCallCount`
* :func:`Utils.IsOverlayEnabled`
* :func:`Utils.BOverlayNeedsPresent`
* :func:`Utils.CheckFileSignature`
* :func:`Utils.ShowGamepadTextInput`
* :func:`Utils.GetEnteredGamepadTextLength`
* :func:`Utils.GetEnteredGamepadTextInput`
* :func:`Utils.GetSteamUILanguage`
* :func:`Utils.IsSteamRunningInVR`
* :func:`Utils.SetOverlayNotificationInset`
* :func:`Utils.IsSteamInBigPictureMode`
* :func:`Utils.StartVRDashboard`
* :func:`Utils.IsVRHeadsetStreamingEnabled`
* :func:`Utils.SetVRHeadsetStreamingEnabled`
* :func:`Utils.IsSteamChinaLauncher`
* :func:`Utils.InitFilterText`
* :func:`Utils.FilterText`
* :func:`Utils.GetIPv6ConnectivityState`
* :func:`Utils.IsSteamRunningOnSteamDeck`
* :func:`Utils.ShowFloatingGamepadTextInput`
* :func:`Utils.SetGameLauncherMode`
* :func:`Utils.DismissFloatingGamepadTextInput`
* :func:`Utils.DismissGamepadTextInput`

List of Callbacks
-----------------

* :func:`Utils.onIPCountry`
* :func:`Utils.onLowBatteryPower`
* :func:`Utils.onSteamAPICallCompleted`
* :func:`Utils.onSteamShutdown`
* :func:`Utils.onCheckFileSignature`
* :func:`Utils.onGamepadTextInputDismissed`
* :func:`Utils.onAppResumingFromSuspend`
* :func:`Utils.onFloatingGamepadTextInputDismissed`
* :func:`Utils.onFilterTextDictionaryChanged`

Function Reference
------------------

.. function:: Utils.GetSecondsSinceAppActive()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetSecondsSinceAppActive <https://partner.steamgames.com/doc/api/ISteamUtils#GetSecondsSinceAppActive>`_

.. function:: Utils.GetSecondsSinceComputerActive()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetSecondsSinceComputerActive <https://partner.steamgames.com/doc/api/ISteamUtils#GetSecondsSinceComputerActive>`_

.. function:: Utils.GetConnectedUniverse()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetConnectedUniverse <https://partner.steamgames.com/doc/api/ISteamUtils#GetConnectedUniverse>`_

.. function:: Utils.GetServerRealTime()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetServerRealTime <https://partner.steamgames.com/doc/api/ISteamUtils#GetServerRealTime>`_

.. function:: Utils.GetIPCountry()

    🤖 **Auto-generated binding**

    :returns: (str) Return value
    :SteamWorks: `GetIPCountry <https://partner.steamgames.com/doc/api/ISteamUtils#GetIPCountry>`_

.. function:: Utils.GetImageSize(iImage)

    🤖 **Auto-generated binding**

    :param int iImage:
    :returns: (bool) Return value
    :returns: (int) Value for `pnWidth`
    :returns: (int) Value for `pnHeight`
    :SteamWorks: `GetImageSize <https://partner.steamgames.com/doc/api/ISteamUtils#GetImageSize>`_

    **Signature differences from C++ API:**

    * Parameter ``pnWidth`` is returned as an additional return value
    * Parameter ``pnHeight`` is returned as an additional return value

.. function:: Utils.GetImageRGBA(iImage, nDestBufferSize)

    🤖 **Auto-generated binding**

    :param int iImage:
    :param int nDestBufferSize:
    :returns: (bool) Return value
    :returns: (str) Value for `pubDest`
    :SteamWorks: `GetImageRGBA <https://partner.steamgames.com/doc/api/ISteamUtils#GetImageRGBA>`_

    **Signature differences from C++ API:**

    * Parameter ``pubDest`` is returned as an additional return value

.. function:: Utils.GetCurrentBatteryPower()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetCurrentBatteryPower <https://partner.steamgames.com/doc/api/ISteamUtils#GetCurrentBatteryPower>`_

.. function:: Utils.GetAppID()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetAppID <https://partner.steamgames.com/doc/api/ISteamUtils#GetAppID>`_

.. function:: Utils.SetOverlayNotificationPosition(eNotificationPosition)

    🤖 **Auto-generated binding**

    :param int eNotificationPosition:
    :SteamWorks: `SetOverlayNotificationPosition <https://partner.steamgames.com/doc/api/ISteamUtils#SetOverlayNotificationPosition>`_

.. function:: Utils.IsAPICallCompleted(hSteamAPICall)

    🤖 **Auto-generated binding**

    :param uint64 hSteamAPICall:
    :returns: (bool) Return value
    :returns: (bool) Value for `pbFailed`
    :SteamWorks: `IsAPICallCompleted <https://partner.steamgames.com/doc/api/ISteamUtils#IsAPICallCompleted>`_

    **Signature differences from C++ API:**

    * Parameter ``pbFailed`` is returned as an additional return value

.. function:: Utils.GetAPICallFailureReason(hSteamAPICall)

    🤖 **Auto-generated binding**

    :param uint64 hSteamAPICall:
    :returns: (int) Return value
    :SteamWorks: `GetAPICallFailureReason <https://partner.steamgames.com/doc/api/ISteamUtils#GetAPICallFailureReason>`_

.. function:: Utils.GetAPICallResult(hSteamAPICall, cubCallback, iCallbackExpected)

    🤖 **Auto-generated binding**

    :param uint64 hSteamAPICall:
    :param int cubCallback:
    :param int iCallbackExpected:
    :returns: (bool) Return value
    :returns: (str) Value for `pCallback`
    :returns: (bool) Value for `pbFailed`
    :SteamWorks: `GetAPICallResult <https://partner.steamgames.com/doc/api/ISteamUtils#GetAPICallResult>`_

    **Signature differences from C++ API:**

    * Parameter ``pCallback`` is returned as an additional return value
    * Parameter ``pbFailed`` is returned as an additional return value

.. function:: Utils.GetIPCCallCount()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetIPCCallCount <https://partner.steamgames.com/doc/api/ISteamUtils#GetIPCCallCount>`_

.. function:: Utils.IsOverlayEnabled()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `IsOverlayEnabled <https://partner.steamgames.com/doc/api/ISteamUtils#IsOverlayEnabled>`_

.. function:: Utils.BOverlayNeedsPresent()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BOverlayNeedsPresent <https://partner.steamgames.com/doc/api/ISteamUtils#BOverlayNeedsPresent>`_

.. function:: Utils.CheckFileSignature(szFileName, callback)

    🤖 **Auto-generated binding**

    :param str szFileName:
    :param function callback: CallResult callback receiving struct `CheckFileSignature_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `CheckFileSignature <https://partner.steamgames.com/doc/api/ISteamUtils#CheckFileSignature>`_

.. function:: Utils.ShowGamepadTextInput(eInputMode, eLineInputMode, pchDescription, unCharMax, pchExistingText)

    🤖 **Auto-generated binding**

    :param int eInputMode:
    :param int eLineInputMode:
    :param str pchDescription:
    :param int unCharMax:
    :param str pchExistingText:
    :returns: (bool) Return value
    :SteamWorks: `ShowGamepadTextInput <https://partner.steamgames.com/doc/api/ISteamUtils#ShowGamepadTextInput>`_

.. function:: Utils.GetEnteredGamepadTextLength()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetEnteredGamepadTextLength <https://partner.steamgames.com/doc/api/ISteamUtils#GetEnteredGamepadTextLength>`_

.. function:: Utils.GetEnteredGamepadTextInput(cchText)

    🤖 **Auto-generated binding**

    :param int cchText:
    :returns: (bool) Return value
    :returns: (str) Value for `pchText`
    :SteamWorks: `GetEnteredGamepadTextInput <https://partner.steamgames.com/doc/api/ISteamUtils#GetEnteredGamepadTextInput>`_

    **Signature differences from C++ API:**

    * Parameter ``pchText`` is returned as an additional return value

.. function:: Utils.GetSteamUILanguage()

    🤖 **Auto-generated binding**

    :returns: (str) Return value
    :SteamWorks: `GetSteamUILanguage <https://partner.steamgames.com/doc/api/ISteamUtils#GetSteamUILanguage>`_

.. function:: Utils.IsSteamRunningInVR()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `IsSteamRunningInVR <https://partner.steamgames.com/doc/api/ISteamUtils#IsSteamRunningInVR>`_

.. function:: Utils.SetOverlayNotificationInset(nHorizontalInset, nVerticalInset)

    🤖 **Auto-generated binding**

    :param int nHorizontalInset:
    :param int nVerticalInset:
    :SteamWorks: `SetOverlayNotificationInset <https://partner.steamgames.com/doc/api/ISteamUtils#SetOverlayNotificationInset>`_

.. function:: Utils.IsSteamInBigPictureMode()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `IsSteamInBigPictureMode <https://partner.steamgames.com/doc/api/ISteamUtils#IsSteamInBigPictureMode>`_

.. function:: Utils.StartVRDashboard()

    🤖 **Auto-generated binding**

    :SteamWorks: `StartVRDashboard <https://partner.steamgames.com/doc/api/ISteamUtils#StartVRDashboard>`_

.. function:: Utils.IsVRHeadsetStreamingEnabled()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `IsVRHeadsetStreamingEnabled <https://partner.steamgames.com/doc/api/ISteamUtils#IsVRHeadsetStreamingEnabled>`_

.. function:: Utils.SetVRHeadsetStreamingEnabled(bEnabled)

    🤖 **Auto-generated binding**

    :param bool bEnabled:
    :SteamWorks: `SetVRHeadsetStreamingEnabled <https://partner.steamgames.com/doc/api/ISteamUtils#SetVRHeadsetStreamingEnabled>`_

.. function:: Utils.IsSteamChinaLauncher()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `IsSteamChinaLauncher <https://partner.steamgames.com/doc/api/ISteamUtils#IsSteamChinaLauncher>`_

.. function:: Utils.InitFilterText(unFilterOptions)

    🤖 **Auto-generated binding**

    :param int unFilterOptions:
    :returns: (bool) Return value
    :SteamWorks: `InitFilterText <https://partner.steamgames.com/doc/api/ISteamUtils#InitFilterText>`_

.. function:: Utils.FilterText(eContext, sourceSteamID, pchInputMessage, nByteSizeOutFilteredText)

    🤖 **Auto-generated binding**

    :param int eContext:
    :param uint64 sourceSteamID:
    :param str pchInputMessage:
    :param int nByteSizeOutFilteredText:
    :returns: (int) Return value
    :returns: (str) Value for `pchOutFilteredText`
    :SteamWorks: `FilterText <https://partner.steamgames.com/doc/api/ISteamUtils#FilterText>`_

    **Signature differences from C++ API:**

    * Parameter ``pchOutFilteredText`` is returned as an additional return value

.. function:: Utils.GetIPv6ConnectivityState(eProtocol)

    🤖 **Auto-generated binding**

    :param int eProtocol:
    :returns: (int) Return value
    :SteamWorks: `GetIPv6ConnectivityState <https://partner.steamgames.com/doc/api/ISteamUtils#GetIPv6ConnectivityState>`_

.. function:: Utils.IsSteamRunningOnSteamDeck()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `IsSteamRunningOnSteamDeck <https://partner.steamgames.com/doc/api/ISteamUtils#IsSteamRunningOnSteamDeck>`_

.. function:: Utils.ShowFloatingGamepadTextInput(eKeyboardMode, nTextFieldXPosition, nTextFieldYPosition, nTextFieldWidth, nTextFieldHeight)

    🤖 **Auto-generated binding**

    :param int eKeyboardMode:
    :param int nTextFieldXPosition:
    :param int nTextFieldYPosition:
    :param int nTextFieldWidth:
    :param int nTextFieldHeight:
    :returns: (bool) Return value
    :SteamWorks: `ShowFloatingGamepadTextInput <https://partner.steamgames.com/doc/api/ISteamUtils#ShowFloatingGamepadTextInput>`_

.. function:: Utils.SetGameLauncherMode(bLauncherMode)

    🤖 **Auto-generated binding**

    :param bool bLauncherMode:
    :SteamWorks: `SetGameLauncherMode <https://partner.steamgames.com/doc/api/ISteamUtils#SetGameLauncherMode>`_

.. function:: Utils.DismissFloatingGamepadTextInput()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `DismissFloatingGamepadTextInput <https://partner.steamgames.com/doc/api/ISteamUtils#DismissFloatingGamepadTextInput>`_

.. function:: Utils.DismissGamepadTextInput()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `DismissGamepadTextInput <https://partner.steamgames.com/doc/api/ISteamUtils#DismissGamepadTextInput>`_


Callbacks
---------

.. function:: Utils.onIPCountry

    Callback for `IPCountry_t <https://partner.steamgames.com/doc/api/ISteamUtils#IPCountry_t>`_

    **callback(data)** receives:


.. function:: Utils.onLowBatteryPower

    Callback for `LowBatteryPower_t <https://partner.steamgames.com/doc/api/ISteamUtils#LowBatteryPower_t>`_

    **callback(data)** receives:

    * **data.m_nMinutesBatteryLeft** -- m_nMinutesBatteryLeft

.. function:: Utils.onSteamAPICallCompleted

    Callback for `SteamAPICallCompleted_t <https://partner.steamgames.com/doc/api/ISteamUtils#SteamAPICallCompleted_t>`_

    **callback(data)** receives:

    * **data.m_hAsyncCall** -- m_hAsyncCall
    * **data.m_iCallback** -- m_iCallback
    * **data.m_cubParam** -- m_cubParam

.. function:: Utils.onSteamShutdown

    Callback for `SteamShutdown_t <https://partner.steamgames.com/doc/api/ISteamUtils#SteamShutdown_t>`_

    **callback(data)** receives:


.. function:: Utils.onCheckFileSignature

    Callback for `CheckFileSignature_t <https://partner.steamgames.com/doc/api/ISteamUtils#CheckFileSignature_t>`_

    **callback(data)** receives:

    * **data.m_eCheckFileSignature** -- m_eCheckFileSignature

.. function:: Utils.onGamepadTextInputDismissed

    Callback for `GamepadTextInputDismissed_t <https://partner.steamgames.com/doc/api/ISteamUtils#GamepadTextInputDismissed_t>`_

    **callback(data)** receives:

    * **data.m_bSubmitted** -- m_bSubmitted
    * **data.m_unSubmittedText** -- m_unSubmittedText
    * **data.m_unAppID** -- m_unAppID

.. function:: Utils.onAppResumingFromSuspend

    Callback for `AppResumingFromSuspend_t <https://partner.steamgames.com/doc/api/ISteamUtils#AppResumingFromSuspend_t>`_

    **callback(data)** receives:


.. function:: Utils.onFloatingGamepadTextInputDismissed

    Callback for `FloatingGamepadTextInputDismissed_t <https://partner.steamgames.com/doc/api/ISteamUtils#FloatingGamepadTextInputDismissed_t>`_

    **callback(data)** receives:


.. function:: Utils.onFilterTextDictionaryChanged

    Callback for `FilterTextDictionaryChanged_t <https://partner.steamgames.com/doc/api/ISteamUtils#FilterTextDictionaryChanged_t>`_

    **callback(data)** receives:

    * **data.m_eLanguage** -- m_eLanguage

