##########
ISteamApps
##########

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✍️ are manually implemented and methods marked with ✋ are currently not implemented.

List of Functions
-----------------

* :func:`Apps.BGetDLCDataByIndex`
* :func:`Apps.BIsAppInstalled`
* :func:`Apps.BIsCybercafe`
* :func:`Apps.BIsDlcInstalled`
* :func:`Apps.BIsLowViolence`
* :func:`Apps.BIsSubscribed`
* :func:`Apps.BIsSubscribedApp`
* :func:`Apps.BIsSubscribedFromFamilySharing`
* :func:`Apps.BIsSubscribedFromFreeWeekend`
* :func:`Apps.BIsTimedTrial`
* :func:`Apps.BIsVACBanned`
* :func:`Apps.GetAppBuildId`
* :func:`Apps.GetAppInstallDir`
* :func:`Apps.GetAppOwner`
* :func:`Apps.GetAvailableGameLanguages`
* :func:`Apps.GetBetaInfo`
* :func:`Apps.GetCurrentBetaName`
* :func:`Apps.GetCurrentGameLanguage`
* :func:`Apps.GetDLCCount`
* :func:`Apps.GetDlcDownloadProgress`
* :func:`Apps.GetEarliestPurchaseUnixTime`
* :func:`Apps.GetFileDetails`
* :func:`Apps.GetInstalledDepots`
* :func:`Apps.GetLaunchCommandLine`
* :func:`Apps.GetLaunchQueryParam`
* :func:`Apps.GetNumBetas`
* :func:`Apps.InstallDLC`
* :func:`Apps.MarkContentCorrupt`
* :func:`Apps.RequestAllProofOfPurchaseKeys`
* :func:`Apps.RequestAppProofOfPurchaseKey`
* :func:`Apps.SetActiveBeta`
* :func:`Apps.SetDlcContext`
* :func:`Apps.UninstallDLC`

List of Callbacks
-----------------

* :func:`Apps.OnDlcInstalled`
* :func:`Apps.OnNewUrlLaunchParameters`
* :func:`Apps.OnAppProofOfPurchaseKeyResponse`
* :func:`Apps.OnFileDetailsResult`
* :func:`Apps.OnTimedTrialStatus`

Function Reference
------------------

.. function:: Apps.BGetDLCDataByIndex(iDLC, cchNameBufferSize)

    🤖 **Auto-generated binding**

    :param int iDLC:
    :param int? cchNameBufferSize: size of the buffer to allocate for ``pchName``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (bool) Return value
    :returns: (int) ``pAppID``
    :returns: (bool) ``pbAvailable``
    :returns: (str) ``pchName``
    :SteamWorks: `BGetDLCDataByIndex <https://partner.steamgames.com/doc/api/ISteamApps#BGetDLCDataByIndex>`_

    **Signature differences from C++ API:**

    * Parameter ``pAppID`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.
    * Parameter ``pbAvailable`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.
    * Parameter ``pchName`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: Apps.BIsAppInstalled(appID)

    🤖 **Auto-generated binding**

    :param int appID: ``AppId_t``
    :returns: (bool) Return value
    :SteamWorks: `BIsAppInstalled <https://partner.steamgames.com/doc/api/ISteamApps#BIsAppInstalled>`_

**Example**::

    if Steam.Apps.BIsAppInstalled(440) then
        print('Team Fortress 2 is installed')
    end

.. function:: Apps.BIsCybercafe()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BIsCybercafe <https://partner.steamgames.com/doc/api/ISteamApps#BIsCybercafe>`_

.. function:: Apps.BIsDlcInstalled(appID)

    🤖 **Auto-generated binding**

    :param int appID: ``AppId_t``
    :returns: (bool) Return value
    :SteamWorks: `BIsDlcInstalled <https://partner.steamgames.com/doc/api/ISteamApps#BIsDlcInstalled>`_

**Example**::

    if Steam.Apps.BIsDlcInstalled(12345) then
        -- Unlock game content
    end

.. function:: Apps.BIsLowViolence()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BIsLowViolence <https://partner.steamgames.com/doc/api/ISteamApps#BIsLowViolence>`_

.. function:: Apps.BIsSubscribed()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BIsSubscribed <https://partner.steamgames.com/doc/api/ISteamApps#BIsSubscribed>`_

.. function:: Apps.BIsSubscribedApp(appID)

    🤖 **Auto-generated binding**

    :param int appID: The App ID of the DLC
    :returns: (bool) Return value
    :SteamWorks: `BIsSubscribedApp <https://partner.steamgames.com/doc/api/ISteamApps#BIsSubscribedApp>`_

    Checks if the user owns a specific piece of Downloadable Content (DLC).

**Example**::

    if Steam.Apps.BIsSubscribedApp(dlcAppID) then
        unlockDLCContent()
    end

.. function:: Apps.BIsSubscribedFromFamilySharing()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BIsSubscribedFromFamilySharing <https://partner.steamgames.com/doc/api/ISteamApps#BIsSubscribedFromFamilySharing>`_

**Example**::

    if Steam.Apps.BIsSubscribedFromFamilySharing() then
        print('Playing via Family Sharing')
    end

.. function:: Apps.BIsSubscribedFromFreeWeekend()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BIsSubscribedFromFreeWeekend <https://partner.steamgames.com/doc/api/ISteamApps#BIsSubscribedFromFreeWeekend>`_

.. function:: Apps.BIsTimedTrial()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :returns: (int) ``punSecondsAllowed``
    :returns: (int) ``punSecondsPlayed``
    :SteamWorks: `BIsTimedTrial <https://partner.steamgames.com/doc/api/ISteamApps#BIsTimedTrial>`_

    **Signature differences from C++ API:**

    * Parameter ``punSecondsAllowed`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.
    * Parameter ``punSecondsPlayed`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    local isTrial, secondsAllowed, secondsPlayed = Steam.Apps.BIsTimedTrial()
    if isTrial then
        print(string.format('Trial: %d/%d seconds played', secondsPlayed, secondsAllowed))
    end

.. function:: Apps.BIsVACBanned()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BIsVACBanned <https://partner.steamgames.com/doc/api/ISteamApps#BIsVACBanned>`_

.. function:: Apps.GetAppBuildId()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetAppBuildId <https://partner.steamgames.com/doc/api/ISteamApps#GetAppBuildId>`_

**Example**::

    print('Current build ID: ' .. Steam.Apps.GetAppBuildId())

.. function:: Apps.GetAppInstallDir(appID, cchFolderBufferSize)

    🤖 **Auto-generated binding**

    :param int appID: ``AppId_t``
    :param int? cchFolderBufferSize: size of the buffer to allocate for ``pchFolder``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (int) Return value
    :returns: (str) ``pchFolder``
    :SteamWorks: `GetAppInstallDir <https://partner.steamgames.com/doc/api/ISteamApps#GetAppInstallDir>`_

    **Signature differences from C++ API:**

    * Parameter ``pchFolder`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    local size, path = Steam.Apps.GetAppInstallDir(Steam.Utils.GetAppID(), 512)
    if size > 0 then
        print('Game installed at: ' .. path)
    end

.. function:: Apps.GetAppOwner()

    🤖 **Auto-generated binding**

    :returns: (uint64) Return value
    :SteamWorks: `GetAppOwner <https://partner.steamgames.com/doc/api/ISteamApps#GetAppOwner>`_

**Example**::

    local ownerID = Steam.Apps.GetAppOwner()
    local myID = Steam.User.GetSteamID()
    if ownerID ~= myID then
        print('Playing via Family Sharing from: ' .. tostring(ownerID))
    end

.. function:: Apps.GetAvailableGameLanguages()

    🤖 **Auto-generated binding**

    :returns: (str) Return value
    :SteamWorks: `GetAvailableGameLanguages <https://partner.steamgames.com/doc/api/ISteamApps#GetAvailableGameLanguages>`_

**Example**::

    local langs = Steam.Apps.GetAvailableGameLanguages()
    print('Supported languages: ' .. langs)

.. function:: Apps.GetBetaInfo(iBetaIndex, cchBetaName, cchDescription)

    🤖 **Auto-generated binding**

    :param int iBetaIndex:
    :param int? cchBetaName: size of the buffer to allocate for ``pchBetaName``. If ``nil`` then the buffer will be ``NULL``.
    :param int? cchDescription: size of the buffer to allocate for ``pchDescription``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (bool) Return value
    :returns: (int) ``punFlags``
    :returns: (int) ``punBuildID``
    :returns: (str) ``pchBetaName``
    :returns: (str) ``pchDescription``
    :SteamWorks: `GetBetaInfo <https://partner.steamgames.com/doc/api/ISteamApps#GetBetaInfo>`_

    **Signature differences from C++ API:**

    * Parameter ``punFlags`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.
    * Parameter ``punBuildID`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.
    * Parameter ``pchBetaName`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.
    * Parameter ``pchDescription`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: Apps.GetCurrentBetaName(cchNameBufferSize)

    🤖 **Auto-generated binding**

    :param int? cchNameBufferSize: size of the buffer to allocate for ``pchName``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (bool) Return value
    :returns: (str) ``pchName``
    :SteamWorks: `GetCurrentBetaName <https://partner.steamgames.com/doc/api/ISteamApps#GetCurrentBetaName>`_

    **Signature differences from C++ API:**

    * Parameter ``pchName`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: Apps.GetCurrentGameLanguage()

    🤖 **Auto-generated binding**

    :returns: (str) Return value
    :SteamWorks: `GetCurrentGameLanguage <https://partner.steamgames.com/doc/api/ISteamApps#GetCurrentGameLanguage>`_

**Example**::

    print("The game's current language is " .. Steam.Apps.GetCurrentGameLanguage())

.. function:: Apps.GetDLCCount()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetDLCCount <https://partner.steamgames.com/doc/api/ISteamApps#GetDLCCount>`_

**Example**::

    local count = Steam.Apps.GetDLCCount()
    for i = 0, count - 1 do
        local appID, available, name = Steam.Apps.BGetDLCDataByIndex(i, 256)
        if available then
            print('DLC: ' .. name .. ' (' .. appID .. ')')
        end
    end

.. function:: Apps.GetDlcDownloadProgress(nAppID)

    🤖 **Auto-generated binding**

    :param int nAppID: ``AppId_t``
    :returns: (bool) Return value
    :returns: (uint64) ``punBytesDownloaded``
    :returns: (uint64) ``punBytesTotal``
    :SteamWorks: `GetDlcDownloadProgress <https://partner.steamgames.com/doc/api/ISteamApps#GetDlcDownloadProgress>`_

    **Signature differences from C++ API:**

    * Parameter ``punBytesDownloaded`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.
    * Parameter ``punBytesTotal`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: Apps.GetEarliestPurchaseUnixTime(nAppID)

    🤖 **Auto-generated binding**

    :param int nAppID: ``AppId_t``
    :returns: (int) Return value
    :SteamWorks: `GetEarliestPurchaseUnixTime <https://partner.steamgames.com/doc/api/ISteamApps#GetEarliestPurchaseUnixTime>`_

**Example**::

    local ts = Steam.Apps.GetEarliestPurchaseUnixTime(Steam.Utils.GetAppID())
    print('Game purchased at unix time: ' .. ts)

.. function:: Apps.GetFileDetails(pszFileName, callback)

    🤖 **Auto-generated binding**

    :param str? pszFileName:
    :param function callback: CallResult callback receiving struct :func:`FileDetailsResult_t <Apps.OnFileDetailsResult>` and a boolean
    :returns: (uint64) ``SteamAPICall_t`` handle for this async call. The result is delivered via the ``callback`` parameter when :func:`Steam.RunCallbacks` is called.
    :SteamWorks: `GetFileDetails <https://partner.steamgames.com/doc/api/ISteamApps#GetFileDetails>`_

.. function:: Apps.GetInstalledDepots(appID, cMaxDepots)

    🤖 **Auto-generated binding**

    :param int appID: ``AppId_t``
    :param int? cMaxDepots: size of the buffer to allocate for ``pvecDepots``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (int) Return value
    :returns: (int[]) ``pvecDepots``
    :SteamWorks: `GetInstalledDepots <https://partner.steamgames.com/doc/api/ISteamApps#GetInstalledDepots>`_

    **Signature differences from C++ API:**

    * Parameter ``pvecDepots`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    local depots = Steam.Apps.GetInstalledDepots(Steam.Utils.GetAppID(), 16)
    for _, depotID in ipairs(depots) do
        print('Installed depot: ' .. depotID)
    end

.. function:: Apps.GetLaunchCommandLine(cubCommandLine)

    🤖 **Auto-generated binding**

    :param int? cubCommandLine: size of the buffer to allocate for ``pszCommandLine``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (int) Return value
    :returns: (str) ``pszCommandLine``
    :SteamWorks: `GetLaunchCommandLine <https://partner.steamgames.com/doc/api/ISteamApps#GetLaunchCommandLine>`_

    **Signature differences from C++ API:**

    * Parameter ``pszCommandLine`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    local params = Steam.Apps.GetLaunchCommandLine(1024)
    local connect_string = tryParseConnectString(params)
    if connect_string then
        initiateJoinGame(connect_string)
    end

.. function:: Apps.GetLaunchQueryParam(pchKey)

    🤖 **Auto-generated binding**

    :param str? pchKey:
    :returns: (str) Return value
    :SteamWorks: `GetLaunchQueryParam <https://partner.steamgames.com/doc/api/ISteamApps#GetLaunchQueryParam>`_

**Example**::

    local connect = Steam.Apps.GetLaunchQueryParam('connect')
    if connect ~= '' then
        connectToServer(connect)
    end

.. function:: Apps.GetNumBetas()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :returns: (int) ``pnAvailable``
    :returns: (int) ``pnPrivate``
    :SteamWorks: `GetNumBetas <https://partner.steamgames.com/doc/api/ISteamApps#GetNumBetas>`_

    **Signature differences from C++ API:**

    * Parameter ``pnAvailable`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.
    * Parameter ``pnPrivate`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: Apps.InstallDLC(nAppID)

    🤖 **Auto-generated binding**

    :param int nAppID: ``AppId_t``
    :SteamWorks: `InstallDLC <https://partner.steamgames.com/doc/api/ISteamApps#InstallDLC>`_

.. function:: Apps.MarkContentCorrupt(bMissingFilesOnly)

    🤖 **Auto-generated binding**

    :param bool bMissingFilesOnly:
    :returns: (bool) Return value
    :SteamWorks: `MarkContentCorrupt <https://partner.steamgames.com/doc/api/ISteamApps#MarkContentCorrupt>`_

**Example**::

    -- Trigger a Steam file integrity check
    Steam.Apps.MarkContentCorrupt(false)

.. function:: Apps.RequestAllProofOfPurchaseKeys()

    🤖 **Auto-generated binding**

    :SteamWorks: `RequestAllProofOfPurchaseKeys <https://partner.steamgames.com/doc/api/ISteamApps#RequestAllProofOfPurchaseKeys>`_

.. function:: Apps.RequestAppProofOfPurchaseKey(nAppID)

    🤖 **Auto-generated binding**

    :param int nAppID: ``AppId_t``
    :SteamWorks: `RequestAppProofOfPurchaseKey <https://partner.steamgames.com/doc/api/ISteamApps#RequestAppProofOfPurchaseKey>`_

.. function:: Apps.SetActiveBeta(pchBetaName)

    🤖 **Auto-generated binding**

    :param str? pchBetaName:
    :returns: (bool) Return value
    :SteamWorks: `SetActiveBeta <https://partner.steamgames.com/doc/api/ISteamApps#SetActiveBeta>`_

.. function:: Apps.SetDlcContext(nAppID)

    🤖 **Auto-generated binding**

    :param int nAppID: ``AppId_t``
    :returns: (bool) Return value
    :SteamWorks: `SetDlcContext <https://partner.steamgames.com/doc/api/ISteamApps#SetDlcContext>`_

.. function:: Apps.UninstallDLC(nAppID)

    🤖 **Auto-generated binding**

    :param int nAppID: ``AppId_t``
    :SteamWorks: `UninstallDLC <https://partner.steamgames.com/doc/api/ISteamApps#UninstallDLC>`_


Callbacks
---------

.. function:: Apps.OnDlcInstalled

    Callback for `DlcInstalled_t <https://partner.steamgames.com/doc/api/ISteamApps#DlcInstalled_t>`_

    **callback(data)** receives:

    * **data.m_nAppID** *(AppId_t)*

**Example**::

    function Steam.Apps.OnDlcInstalled(data)
        print('DLC installed: appID =', data.m_nAppID)
        unlockDLCContent(data.m_nAppID)
    end

.. function:: Apps.OnNewUrlLaunchParameters

    Callback for `NewUrlLaunchParameters_t <https://partner.steamgames.com/doc/api/ISteamApps#NewUrlLaunchParameters_t>`_

    **callback(data)** receives no fields (notification only).

**Example**::

    function Steam.Apps.OnNewUrlLaunchParameters()
        local params = Steam.Apps.GetLaunchCommandLine(1024)
        handleLaunchParams(params)
    end

.. function:: Apps.OnAppProofOfPurchaseKeyResponse

    Callback for `AppProofOfPurchaseKeyResponse_t <https://partner.steamgames.com/doc/api/ISteamApps#AppProofOfPurchaseKeyResponse_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(EResult)*
    * **data.m_nAppID** *(int)*
    * **data.m_cchKeyLength** *(int)*
    * **data.m_rgchKey** *(string)*

.. function:: Apps.OnFileDetailsResult

    Callback for `FileDetailsResult_t <https://partner.steamgames.com/doc/api/ISteamApps#FileDetailsResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(EResult)*
    * **data.m_ulFileSize** *(uint64)*
    * **data.m_FileSHA** *(string)*
    * **data.m_unFlags** *(int)*

.. function:: Apps.OnTimedTrialStatus

    Callback for `TimedTrialStatus_t <https://partner.steamgames.com/doc/api/ISteamApps#TimedTrialStatus_t>`_

    **callback(data)** receives:

    * **data.m_unAppID** *(AppId_t)*
    * **data.m_bIsOffline** *(bool)*
    * **data.m_unSecondsAllowed** *(int)*
    * **data.m_unSecondsPlayed** *(int)*

**Example**::

    function Steam.Apps.OnTimedTrialStatus(data)
        if data.m_bIsOffline ~= 0 then return end
        local remaining = data.m_unSecondsAllowed - data.m_unSecondsPlayed
        print('Trial time remaining: ' .. remaining .. 's')
    end

