##########
ISteamApps
##########

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✋ require manual implementation.

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

* :func:`Apps.onDlcInstalled`
* :func:`Apps.onNewUrlLaunchParameters`
* :func:`Apps.onAppProofOfPurchaseKeyResponse`
* :func:`Apps.onFileDetailsResult`
* :func:`Apps.onTimedTrialStatus`

Function Reference
------------------

.. function:: Apps.BGetDLCDataByIndex(iDLC, cchNameBufferSize)

    🤖 **Auto-generated binding**

    :param int iDLC:
    :param int cchNameBufferSize:
    :returns: (bool) Return value
    :returns: (int) Value for `pAppID`
    :returns: (bool) Value for `pbAvailable`
    :returns: (str) Value for `pchName`
    :SteamWorks: `BGetDLCDataByIndex <https://partner.steamgames.com/doc/api/ISteamApps#BGetDLCDataByIndex>`_

    **Signature differences from C++ API:**

    * Parameter ``pAppID`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pbAvailable`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pchName`` is no longer a paramer, and is instead an additional return value

.. function:: Apps.BIsAppInstalled(appID)

    🤖 **Auto-generated binding**

    :param int appID:
    :returns: (bool) Return value
    :SteamWorks: `BIsAppInstalled <https://partner.steamgames.com/doc/api/ISteamApps#BIsAppInstalled>`_

.. function:: Apps.BIsCybercafe()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BIsCybercafe <https://partner.steamgames.com/doc/api/ISteamApps#BIsCybercafe>`_

.. function:: Apps.BIsDlcInstalled(appID)

    🤖 **Auto-generated binding**

    :param int appID:
    :returns: (bool) Return value
    :SteamWorks: `BIsDlcInstalled <https://partner.steamgames.com/doc/api/ISteamApps#BIsDlcInstalled>`_

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

    :param int appID:
    :returns: (bool) Return value
    :SteamWorks: `BIsSubscribedApp <https://partner.steamgames.com/doc/api/ISteamApps#BIsSubscribedApp>`_

.. function:: Apps.BIsSubscribedFromFamilySharing()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BIsSubscribedFromFamilySharing <https://partner.steamgames.com/doc/api/ISteamApps#BIsSubscribedFromFamilySharing>`_

.. function:: Apps.BIsSubscribedFromFreeWeekend()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BIsSubscribedFromFreeWeekend <https://partner.steamgames.com/doc/api/ISteamApps#BIsSubscribedFromFreeWeekend>`_

.. function:: Apps.BIsTimedTrial()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :returns: (int) Value for `punSecondsAllowed`
    :returns: (int) Value for `punSecondsPlayed`
    :SteamWorks: `BIsTimedTrial <https://partner.steamgames.com/doc/api/ISteamApps#BIsTimedTrial>`_

    **Signature differences from C++ API:**

    * Parameter ``punSecondsAllowed`` is no longer a paramer, and is instead an additional return value
    * Parameter ``punSecondsPlayed`` is no longer a paramer, and is instead an additional return value

.. function:: Apps.BIsVACBanned()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BIsVACBanned <https://partner.steamgames.com/doc/api/ISteamApps#BIsVACBanned>`_

.. function:: Apps.GetAppBuildId()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetAppBuildId <https://partner.steamgames.com/doc/api/ISteamApps#GetAppBuildId>`_

.. function:: Apps.GetAppInstallDir(appID, cchFolderBufferSize)

    🤖 **Auto-generated binding**

    :param int appID:
    :param int cchFolderBufferSize:
    :returns: (int) Return value
    :returns: (str) Value for `pchFolder`
    :SteamWorks: `GetAppInstallDir <https://partner.steamgames.com/doc/api/ISteamApps#GetAppInstallDir>`_

    **Signature differences from C++ API:**

    * Parameter ``pchFolder`` is no longer a paramer, and is instead an additional return value

.. function:: Apps.GetAppOwner()

    🤖 **Auto-generated binding**

    :returns: (uint64) Return value
    :SteamWorks: `GetAppOwner <https://partner.steamgames.com/doc/api/ISteamApps#GetAppOwner>`_

.. function:: Apps.GetAvailableGameLanguages()

    🤖 **Auto-generated binding**

    :returns: (str) Return value
    :SteamWorks: `GetAvailableGameLanguages <https://partner.steamgames.com/doc/api/ISteamApps#GetAvailableGameLanguages>`_

.. function:: Apps.GetBetaInfo(iBetaIndex, cchBetaName, cchDescription)

    🤖 **Auto-generated binding**

    :param int iBetaIndex:
    :param int cchBetaName:
    :param int cchDescription:
    :returns: (bool) Return value
    :returns: (int) Value for `punFlags`
    :returns: (int) Value for `punBuildID`
    :returns: (str) Value for `pchBetaName`
    :returns: (str) Value for `pchDescription`
    :SteamWorks: `GetBetaInfo <https://partner.steamgames.com/doc/api/ISteamApps#GetBetaInfo>`_

    **Signature differences from C++ API:**

    * Parameter ``punFlags`` is no longer a paramer, and is instead an additional return value
    * Parameter ``punBuildID`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pchBetaName`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pchDescription`` is no longer a paramer, and is instead an additional return value

.. function:: Apps.GetCurrentBetaName(cchNameBufferSize)

    🤖 **Auto-generated binding**

    :param int cchNameBufferSize:
    :returns: (bool) Return value
    :returns: (str) Value for `pchName`
    :SteamWorks: `GetCurrentBetaName <https://partner.steamgames.com/doc/api/ISteamApps#GetCurrentBetaName>`_

    **Signature differences from C++ API:**

    * Parameter ``pchName`` is no longer a paramer, and is instead an additional return value

.. function:: Apps.GetCurrentGameLanguage()

    🤖 **Auto-generated binding**

    :returns: (str) Return value
    :SteamWorks: `GetCurrentGameLanguage <https://partner.steamgames.com/doc/api/ISteamApps#GetCurrentGameLanguage>`_

.. function:: Apps.GetDLCCount()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetDLCCount <https://partner.steamgames.com/doc/api/ISteamApps#GetDLCCount>`_

.. function:: Apps.GetDlcDownloadProgress(nAppID)

    🤖 **Auto-generated binding**

    :param int nAppID:
    :returns: (bool) Return value
    :returns: (uint64) Value for `punBytesDownloaded`
    :returns: (uint64) Value for `punBytesTotal`
    :SteamWorks: `GetDlcDownloadProgress <https://partner.steamgames.com/doc/api/ISteamApps#GetDlcDownloadProgress>`_

    **Signature differences from C++ API:**

    * Parameter ``punBytesDownloaded`` is no longer a paramer, and is instead an additional return value
    * Parameter ``punBytesTotal`` is no longer a paramer, and is instead an additional return value

.. function:: Apps.GetEarliestPurchaseUnixTime(nAppID)

    🤖 **Auto-generated binding**

    :param int nAppID:
    :returns: (int) Return value
    :SteamWorks: `GetEarliestPurchaseUnixTime <https://partner.steamgames.com/doc/api/ISteamApps#GetEarliestPurchaseUnixTime>`_

.. function:: Apps.GetFileDetails(pszFileName, callback)

    🤖 **Auto-generated binding**

    :param str pszFileName:
    :param function callback: CallResult callback receiving struct `FileDetailsResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `GetFileDetails <https://partner.steamgames.com/doc/api/ISteamApps#GetFileDetails>`_

.. function:: Apps.GetInstalledDepots(appID, cMaxDepots)

    🤖 **Auto-generated binding**

    :param int appID:
    :param int cMaxDepots:
    :returns: (int) Return value
    :returns: (int[]) Value for `pvecDepots`
    :SteamWorks: `GetInstalledDepots <https://partner.steamgames.com/doc/api/ISteamApps#GetInstalledDepots>`_

    **Signature differences from C++ API:**

    * Parameter ``pvecDepots`` is no longer a paramer, and is instead an additional return value

.. function:: Apps.GetLaunchCommandLine(cubCommandLine)

    🤖 **Auto-generated binding**

    :param int cubCommandLine:
    :returns: (int) Return value
    :returns: (str) Value for `pszCommandLine`
    :SteamWorks: `GetLaunchCommandLine <https://partner.steamgames.com/doc/api/ISteamApps#GetLaunchCommandLine>`_

    **Signature differences from C++ API:**

    * Parameter ``pszCommandLine`` is no longer a paramer, and is instead an additional return value

.. function:: Apps.GetLaunchQueryParam(pchKey)

    🤖 **Auto-generated binding**

    :param str pchKey:
    :returns: (str) Return value
    :SteamWorks: `GetLaunchQueryParam <https://partner.steamgames.com/doc/api/ISteamApps#GetLaunchQueryParam>`_

.. function:: Apps.GetNumBetas()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :returns: (int) Value for `pnAvailable`
    :returns: (int) Value for `pnPrivate`
    :SteamWorks: `GetNumBetas <https://partner.steamgames.com/doc/api/ISteamApps#GetNumBetas>`_

    **Signature differences from C++ API:**

    * Parameter ``pnAvailable`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pnPrivate`` is no longer a paramer, and is instead an additional return value

.. function:: Apps.InstallDLC(nAppID)

    🤖 **Auto-generated binding**

    :param int nAppID:
    :SteamWorks: `InstallDLC <https://partner.steamgames.com/doc/api/ISteamApps#InstallDLC>`_

.. function:: Apps.MarkContentCorrupt(bMissingFilesOnly)

    🤖 **Auto-generated binding**

    :param bool bMissingFilesOnly:
    :returns: (bool) Return value
    :SteamWorks: `MarkContentCorrupt <https://partner.steamgames.com/doc/api/ISteamApps#MarkContentCorrupt>`_

.. function:: Apps.RequestAllProofOfPurchaseKeys()

    🤖 **Auto-generated binding**

    :SteamWorks: `RequestAllProofOfPurchaseKeys <https://partner.steamgames.com/doc/api/ISteamApps#RequestAllProofOfPurchaseKeys>`_

.. function:: Apps.RequestAppProofOfPurchaseKey(nAppID)

    🤖 **Auto-generated binding**

    :param int nAppID:
    :SteamWorks: `RequestAppProofOfPurchaseKey <https://partner.steamgames.com/doc/api/ISteamApps#RequestAppProofOfPurchaseKey>`_

.. function:: Apps.SetActiveBeta(pchBetaName)

    🤖 **Auto-generated binding**

    :param str pchBetaName:
    :returns: (bool) Return value
    :SteamWorks: `SetActiveBeta <https://partner.steamgames.com/doc/api/ISteamApps#SetActiveBeta>`_

.. function:: Apps.SetDlcContext(nAppID)

    🤖 **Auto-generated binding**

    :param int nAppID:
    :returns: (bool) Return value
    :SteamWorks: `SetDlcContext <https://partner.steamgames.com/doc/api/ISteamApps#SetDlcContext>`_

.. function:: Apps.UninstallDLC(nAppID)

    🤖 **Auto-generated binding**

    :param int nAppID:
    :SteamWorks: `UninstallDLC <https://partner.steamgames.com/doc/api/ISteamApps#UninstallDLC>`_


Callbacks
---------

.. function:: Apps.onDlcInstalled

    Callback for `DlcInstalled_t <https://partner.steamgames.com/doc/api/ISteamApps#DlcInstalled_t>`_

    **callback(data)** receives:

    * **data.m_nAppID** -- m_nAppID

.. function:: Apps.onNewUrlLaunchParameters

    Callback for `NewUrlLaunchParameters_t <https://partner.steamgames.com/doc/api/ISteamApps#NewUrlLaunchParameters_t>`_

    **callback(data)** receives:


.. function:: Apps.onAppProofOfPurchaseKeyResponse

    Callback for `AppProofOfPurchaseKeyResponse_t <https://partner.steamgames.com/doc/api/ISteamApps#AppProofOfPurchaseKeyResponse_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nAppID** -- m_nAppID
    * **data.m_cchKeyLength** -- m_cchKeyLength
    * **data.m_rgchKey** -- m_rgchKey

.. function:: Apps.onFileDetailsResult

    Callback for `FileDetailsResult_t <https://partner.steamgames.com/doc/api/ISteamApps#FileDetailsResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_ulFileSize** -- m_ulFileSize
    * **data.m_FileSHA** -- m_FileSHA
    * **data.m_unFlags** -- m_unFlags

.. function:: Apps.onTimedTrialStatus

    Callback for `TimedTrialStatus_t <https://partner.steamgames.com/doc/api/ISteamApps#TimedTrialStatus_t>`_

    **callback(data)** receives:

    * **data.m_unAppID** -- m_unAppID
    * **data.m_bIsOffline** -- m_bIsOffline
    * **data.m_unSecondsAllowed** -- m_unSecondsAllowed
    * **data.m_unSecondsPlayed** -- m_unSecondsPlayed

