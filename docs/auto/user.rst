##########
ISteamUser
##########

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✋ require manual implementation.

List of Functions
-----------------

* :func:`User.AdvertiseGame`
* :func:`User.BIsBehindNAT`
* :func:`User.BIsPhoneIdentifying`
* :func:`User.BIsPhoneRequiringVerification`
* :func:`User.BIsPhoneVerified`
* :func:`User.BIsTwoFactorEnabled`
* :func:`User.BLoggedOn`
* :func:`User.BSetDurationControlOnlineState`
* :func:`User.BeginAuthSession`
* :func:`User.CancelAuthTicket`
* :func:`User.DecompressVoice`
* :func:`User.EndAuthSession`
* :func:`User.GetAuthSessionTicket`
* :func:`User.GetAuthTicketForWebApi`
* :func:`User.GetAvailableVoice`
* :func:`User.GetDurationControl`
* :func:`User.GetEncryptedAppTicket`
* :func:`User.GetGameBadgeLevel`
* :func:`User.GetHSteamUser`
* :func:`User.GetMarketEligibility`
* :func:`User.GetPlayerSteamLevel`
* :func:`User.GetSteamID`
* :func:`User.GetUserDataFolder`
* :func:`User.GetVoice`
* :func:`User.GetVoiceOptimalSampleRate`
* :func:`User.RequestEncryptedAppTicket`
* :func:`User.RequestStoreAuthURL`
* :func:`User.StartVoiceRecording`
* :func:`User.StopVoiceRecording`
* :func:`User.TrackAppUsageEvent`
* :func:`User.UserHasLicenseForApp`

List of Callbacks
-----------------

* :func:`User.onSteamServersConnected`
* :func:`User.onSteamServerConnectFailure`
* :func:`User.onSteamServersDisconnected`
* :func:`User.onClientGameServerDeny`
* :func:`User.onIPCFailure`
* :func:`User.onLicensesUpdated`
* :func:`User.onValidateAuthTicketResponse`
* :func:`User.onMicroTxnAuthorizationResponse`
* :func:`User.onEncryptedAppTicketResponse`
* :func:`User.onGetAuthSessionTicketResponse`
* :func:`User.onGameWebCallback`
* :func:`User.onStoreAuthURLResponse`
* :func:`User.onMarketEligibilityResponse`
* :func:`User.onDurationControl`
* :func:`User.onGetTicketForWebApiResponse`
* :func:`User.onGSPolicyResponse`

Function Reference
------------------

.. function:: User.AdvertiseGame(steamIDGameServer, unIPServer, usPortServer)

    🤖 **Auto-generated binding**

    :param uint64 steamIDGameServer:
    :param int unIPServer:
    :param int usPortServer:
    :SteamWorks: `AdvertiseGame <https://partner.steamgames.com/doc/api/ISteamUser#AdvertiseGame>`_

.. function:: User.BIsBehindNAT()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BIsBehindNAT <https://partner.steamgames.com/doc/api/ISteamUser#BIsBehindNAT>`_

.. function:: User.BIsPhoneIdentifying()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BIsPhoneIdentifying <https://partner.steamgames.com/doc/api/ISteamUser#BIsPhoneIdentifying>`_

.. function:: User.BIsPhoneRequiringVerification()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BIsPhoneRequiringVerification <https://partner.steamgames.com/doc/api/ISteamUser#BIsPhoneRequiringVerification>`_

.. function:: User.BIsPhoneVerified()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BIsPhoneVerified <https://partner.steamgames.com/doc/api/ISteamUser#BIsPhoneVerified>`_

.. function:: User.BIsTwoFactorEnabled()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BIsTwoFactorEnabled <https://partner.steamgames.com/doc/api/ISteamUser#BIsTwoFactorEnabled>`_

.. function:: User.BLoggedOn()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BLoggedOn <https://partner.steamgames.com/doc/api/ISteamUser#BLoggedOn>`_

.. function:: User.BSetDurationControlOnlineState(eNewState)

    🤖 **Auto-generated binding**

    :param int eNewState:
    :returns: (bool) Return value
    :SteamWorks: `BSetDurationControlOnlineState <https://partner.steamgames.com/doc/api/ISteamUser#BSetDurationControlOnlineState>`_

.. function:: User.BeginAuthSession(pAuthTicket, cbAuthTicket, steamID)

    🤖 **Auto-generated binding**

    :param str pAuthTicket:
    :param int cbAuthTicket:
    :param uint64 steamID:
    :returns: (int) Return value
    :SteamWorks: `BeginAuthSession <https://partner.steamgames.com/doc/api/ISteamUser#BeginAuthSession>`_

.. function:: User.CancelAuthTicket(hAuthTicket)

    🤖 **Auto-generated binding**

    :param int hAuthTicket:
    :SteamWorks: `CancelAuthTicket <https://partner.steamgames.com/doc/api/ISteamUser#CancelAuthTicket>`_

.. function:: User.DecompressVoice(pCompressed, cbCompressed, cbDestBufferSize, nDesiredSampleRate)

    🤖 **Auto-generated binding**

    :param str pCompressed:
    :param int cbCompressed:
    :param int cbDestBufferSize:
    :param int nDesiredSampleRate:
    :returns: (int) Return value
    :returns: (str) Value for `pDestBuffer`
    :returns: (int) Value for `nBytesWritten`
    :SteamWorks: `DecompressVoice <https://partner.steamgames.com/doc/api/ISteamUser#DecompressVoice>`_

    **Signature differences from C++ API:**

    * Parameter ``pDestBuffer`` is no longer a paramer, and is instead an additional return value
    * Parameter ``nBytesWritten`` is no longer a paramer, and is instead an additional return value

.. function:: User.EndAuthSession(steamID)

    🤖 **Auto-generated binding**

    :param uint64 steamID:
    :SteamWorks: `EndAuthSession <https://partner.steamgames.com/doc/api/ISteamUser#EndAuthSession>`_

.. function:: User.GetAuthSessionTicket(cbMaxTicket, pSteamNetworkingIdentity)

    🤖 **Auto-generated binding**

    :param int cbMaxTicket:
    :param :ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>` pSteamNetworkingIdentity:
    :returns: (int) Return value
    :returns: (str) Value for `pTicket`
    :returns: (int) Value for `pcbTicket`
    :SteamWorks: `GetAuthSessionTicket <https://partner.steamgames.com/doc/api/ISteamUser#GetAuthSessionTicket>`_

    **Signature differences from C++ API:**

    * Parameter ``pTicket`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pcbTicket`` is no longer a paramer, and is instead an additional return value

.. function:: User.GetAuthTicketForWebApi(pchIdentity)

    🤖 **Auto-generated binding**

    :param str pchIdentity:
    :returns: (int) Return value
    :SteamWorks: `GetAuthTicketForWebApi <https://partner.steamgames.com/doc/api/ISteamUser#GetAuthTicketForWebApi>`_

.. function:: User.GetAvailableVoice()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :returns: (int) Value for `pcbCompressed`
    :SteamWorks: `GetAvailableVoice <https://partner.steamgames.com/doc/api/ISteamUser#GetAvailableVoice>`_

    **Signature differences from C++ API:**

    * Parameter ``pcbCompressed`` is no longer a paramer, and is instead an additional return value

.. function:: User.GetDurationControl(callback)

    🤖 **Auto-generated binding**

    :param function callback: CallResult callback receiving struct `DurationControl_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `GetDurationControl <https://partner.steamgames.com/doc/api/ISteamUser#GetDurationControl>`_

.. function:: User.GetEncryptedAppTicket(cbMaxTicket)

    🤖 **Auto-generated binding**

    :param int cbMaxTicket:
    :returns: (bool) Return value
    :returns: (str) Value for `pTicket`
    :returns: (int) Value for `pcbTicket`
    :SteamWorks: `GetEncryptedAppTicket <https://partner.steamgames.com/doc/api/ISteamUser#GetEncryptedAppTicket>`_

    **Signature differences from C++ API:**

    * Parameter ``pTicket`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pcbTicket`` is no longer a paramer, and is instead an additional return value

.. function:: User.GetGameBadgeLevel(nSeries, bFoil)

    🤖 **Auto-generated binding**

    :param int nSeries:
    :param bool bFoil:
    :returns: (int) Return value
    :SteamWorks: `GetGameBadgeLevel <https://partner.steamgames.com/doc/api/ISteamUser#GetGameBadgeLevel>`_

.. function:: User.GetHSteamUser()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetHSteamUser <https://partner.steamgames.com/doc/api/ISteamUser#GetHSteamUser>`_

.. function:: User.GetMarketEligibility(callback)

    🤖 **Auto-generated binding**

    :param function callback: CallResult callback receiving struct `MarketEligibilityResponse_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `GetMarketEligibility <https://partner.steamgames.com/doc/api/ISteamUser#GetMarketEligibility>`_

.. function:: User.GetPlayerSteamLevel()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetPlayerSteamLevel <https://partner.steamgames.com/doc/api/ISteamUser#GetPlayerSteamLevel>`_

.. function:: User.GetSteamID()

    🤖 **Auto-generated binding**

    :returns: (uint64) Return value
    :SteamWorks: `GetSteamID <https://partner.steamgames.com/doc/api/ISteamUser#GetSteamID>`_

.. function:: User.GetUserDataFolder(cubBuffer)

    🤖 **Auto-generated binding**

    :param int cubBuffer:
    :returns: (bool) Return value
    :returns: (str) Value for `pchBuffer`
    :SteamWorks: `GetUserDataFolder <https://partner.steamgames.com/doc/api/ISteamUser#GetUserDataFolder>`_

    **Signature differences from C++ API:**

    * Parameter ``pchBuffer`` is no longer a paramer, and is instead an additional return value

.. function:: User.GetVoice(bWantCompressed, cbDestBufferSize)

    🤖 **Auto-generated binding**

    :param bool bWantCompressed:
    :param int cbDestBufferSize:
    :returns: (int) Return value
    :returns: (str) Value for `pDestBuffer`
    :returns: (int) Value for `nBytesWritten`
    :SteamWorks: `GetVoice <https://partner.steamgames.com/doc/api/ISteamUser#GetVoice>`_

    **Signature differences from C++ API:**

    * Parameter ``pDestBuffer`` is no longer a paramer, and is instead an additional return value
    * Parameter ``nBytesWritten`` is no longer a paramer, and is instead an additional return value

.. function:: User.GetVoiceOptimalSampleRate()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetVoiceOptimalSampleRate <https://partner.steamgames.com/doc/api/ISteamUser#GetVoiceOptimalSampleRate>`_

.. function:: User.RequestEncryptedAppTicket(pDataToInclude, cbDataToInclude, callback)

    🤖 **Auto-generated binding**

    :param str pDataToInclude:
    :param int cbDataToInclude:
    :param function callback: CallResult callback receiving struct `EncryptedAppTicketResponse_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `RequestEncryptedAppTicket <https://partner.steamgames.com/doc/api/ISteamUser#RequestEncryptedAppTicket>`_

.. function:: User.RequestStoreAuthURL(pchRedirectURL, callback)

    🤖 **Auto-generated binding**

    :param str pchRedirectURL:
    :param function callback: CallResult callback receiving struct `StoreAuthURLResponse_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `RequestStoreAuthURL <https://partner.steamgames.com/doc/api/ISteamUser#RequestStoreAuthURL>`_

.. function:: User.StartVoiceRecording()

    🤖 **Auto-generated binding**

    :SteamWorks: `StartVoiceRecording <https://partner.steamgames.com/doc/api/ISteamUser#StartVoiceRecording>`_

.. function:: User.StopVoiceRecording()

    🤖 **Auto-generated binding**

    :SteamWorks: `StopVoiceRecording <https://partner.steamgames.com/doc/api/ISteamUser#StopVoiceRecording>`_

.. function:: User.TrackAppUsageEvent(gameID, eAppUsageEvent, pchExtraInfo)

    🤖 **Auto-generated binding**

    :param uint64 gameID:
    :param int eAppUsageEvent:
    :param str pchExtraInfo:
    :SteamWorks: `TrackAppUsageEvent <https://partner.steamgames.com/doc/api/ISteamUser#TrackAppUsageEvent>`_

.. function:: User.UserHasLicenseForApp(steamID, appID)

    🤖 **Auto-generated binding**

    :param uint64 steamID:
    :param int appID:
    :returns: (int) Return value
    :SteamWorks: `UserHasLicenseForApp <https://partner.steamgames.com/doc/api/ISteamUser#UserHasLicenseForApp>`_


Callbacks
---------

.. function:: User.onSteamServersConnected

    Callback for `SteamServersConnected_t <https://partner.steamgames.com/doc/api/ISteamUser#SteamServersConnected_t>`_

    **callback(data)** receives:


.. function:: User.onSteamServerConnectFailure

    Callback for `SteamServerConnectFailure_t <https://partner.steamgames.com/doc/api/ISteamUser#SteamServerConnectFailure_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_bStillRetrying** -- m_bStillRetrying

.. function:: User.onSteamServersDisconnected

    Callback for `SteamServersDisconnected_t <https://partner.steamgames.com/doc/api/ISteamUser#SteamServersDisconnected_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult

.. function:: User.onClientGameServerDeny

    Callback for `ClientGameServerDeny_t <https://partner.steamgames.com/doc/api/ISteamUser#ClientGameServerDeny_t>`_

    **callback(data)** receives:

    * **data.m_uAppID** -- m_uAppID
    * **data.m_unGameServerIP** -- m_unGameServerIP
    * **data.m_usGameServerPort** -- m_usGameServerPort
    * **data.m_bSecure** -- m_bSecure
    * **data.m_uReason** -- m_uReason

.. function:: User.onIPCFailure

    Callback for `IPCFailure_t <https://partner.steamgames.com/doc/api/ISteamUser#IPCFailure_t>`_

    **callback(data)** receives:

    * **data.m_eFailureType** -- m_eFailureType

.. function:: User.onLicensesUpdated

    Callback for `LicensesUpdated_t <https://partner.steamgames.com/doc/api/ISteamUser#LicensesUpdated_t>`_

    **callback(data)** receives:


.. function:: User.onValidateAuthTicketResponse

    Callback for `ValidateAuthTicketResponse_t <https://partner.steamgames.com/doc/api/ISteamUser#ValidateAuthTicketResponse_t>`_

    **callback(data)** receives:

    * **data.m_SteamID** -- m_SteamID
    * **data.m_eAuthSessionResponse** -- m_eAuthSessionResponse
    * **data.m_OwnerSteamID** -- m_OwnerSteamID

.. function:: User.onMicroTxnAuthorizationResponse

    Callback for `MicroTxnAuthorizationResponse_t <https://partner.steamgames.com/doc/api/ISteamUser#MicroTxnAuthorizationResponse_t>`_

    **callback(data)** receives:

    * **data.m_unAppID** -- m_unAppID
    * **data.m_ulOrderID** -- m_ulOrderID
    * **data.m_bAuthorized** -- m_bAuthorized

.. function:: User.onEncryptedAppTicketResponse

    Callback for `EncryptedAppTicketResponse_t <https://partner.steamgames.com/doc/api/ISteamUser#EncryptedAppTicketResponse_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult

.. function:: User.onGetAuthSessionTicketResponse

    Callback for `GetAuthSessionTicketResponse_t <https://partner.steamgames.com/doc/api/ISteamUser#GetAuthSessionTicketResponse_t>`_

    **callback(data)** receives:

    * **data.m_hAuthTicket** -- m_hAuthTicket
    * **data.m_eResult** -- m_eResult

.. function:: User.onGameWebCallback

    Callback for `GameWebCallback_t <https://partner.steamgames.com/doc/api/ISteamUser#GameWebCallback_t>`_

    **callback(data)** receives:

    * **data.m_szURL** -- m_szURL

.. function:: User.onStoreAuthURLResponse

    Callback for `StoreAuthURLResponse_t <https://partner.steamgames.com/doc/api/ISteamUser#StoreAuthURLResponse_t>`_

    **callback(data)** receives:

    * **data.m_szURL** -- m_szURL

.. function:: User.onMarketEligibilityResponse

    Callback for `MarketEligibilityResponse_t <https://partner.steamgames.com/doc/api/ISteamUser#MarketEligibilityResponse_t>`_

    **callback(data)** receives:

    * **data.m_bAllowed** -- m_bAllowed
    * **data.m_eNotAllowedReason** -- m_eNotAllowedReason
    * **data.m_rtAllowedAtTime** -- m_rtAllowedAtTime
    * **data.m_cdaySteamGuardRequiredDays** -- m_cdaySteamGuardRequiredDays
    * **data.m_cdayNewDeviceCooldown** -- m_cdayNewDeviceCooldown

.. function:: User.onDurationControl

    Callback for `DurationControl_t <https://partner.steamgames.com/doc/api/ISteamUser#DurationControl_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_appid** -- m_appid
    * **data.m_bApplicable** -- m_bApplicable
    * **data.m_csecsLast5h** -- m_csecsLast5h
    * **data.m_progress** -- m_progress
    * **data.m_notification** -- m_notification
    * **data.m_csecsToday** -- m_csecsToday
    * **data.m_csecsRemaining** -- m_csecsRemaining

.. function:: User.onGetTicketForWebApiResponse

    Callback for `GetTicketForWebApiResponse_t <https://partner.steamgames.com/doc/api/ISteamUser#GetTicketForWebApiResponse_t>`_

    **callback(data)** receives:

    * **data.m_hAuthTicket** -- m_hAuthTicket
    * **data.m_eResult** -- m_eResult
    * **data.m_cubTicket** -- m_cubTicket
    * **data.m_rgubTicket** -- m_rgubTicket

.. function:: User.onGSPolicyResponse

    Callback for `GSPolicyResponse_t <https://partner.steamgames.com/doc/api/ISteamUser#GSPolicyResponse_t>`_

    **callback(data)** receives:

    * **data.m_bSecure** -- m_bSecure

