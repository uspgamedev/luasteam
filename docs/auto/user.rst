##########
ISteamUser
##########

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✍️ are manually implemented and methods marked with ✋ are currently not implemented.

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

* :func:`User.OnSteamServersConnected`
* :func:`User.OnSteamServerConnectFailure`
* :func:`User.OnSteamServersDisconnected`
* :func:`User.OnClientGameServerDeny`
* :func:`User.OnIPCFailure`
* :func:`User.OnLicensesUpdated`
* :func:`User.OnValidateAuthTicketResponse`
* :func:`User.OnMicroTxnAuthorizationResponse`
* :func:`User.OnEncryptedAppTicketResponse`
* :func:`User.OnGetAuthSessionTicketResponse`
* :func:`User.OnGameWebCallback`
* :func:`User.OnStoreAuthURLResponse`
* :func:`User.OnMarketEligibilityResponse`
* :func:`User.OnDurationControl`
* :func:`User.OnGetTicketForWebApiResponse`
* :func:`User.OnGSPolicyResponse`

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

**Example**::

    if Steam.User.BIsTwoFactorEnabled() then
        print('Steam Guard Mobile Authenticator is enabled')
    end

.. function:: User.BLoggedOn()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BLoggedOn <https://partner.steamgames.com/doc/api/ISteamUser#BLoggedOn>`_

**Example**::

    if not Steam.User.BLoggedOn() then
        print('User is not logged in to Steam')
    end

.. function:: User.BSetDurationControlOnlineState(eNewState)

    🤖 **Auto-generated binding**

    :param int eNewState:
    :returns: (bool) Return value
    :SteamWorks: `BSetDurationControlOnlineState <https://partner.steamgames.com/doc/api/ISteamUser#BSetDurationControlOnlineState>`_

.. function:: User.BeginAuthSession(pAuthTicket, cbAuthTicket, steamID)

    🤖 **Auto-generated binding**

    :param str pAuthTicket:
    :param int cbAuthTicket: size of the input array ``pAuthTicket``
    :param uint64 steamID:
    :returns: (int) Return value
    :SteamWorks: `BeginAuthSession <https://partner.steamgames.com/doc/api/ISteamUser#BeginAuthSession>`_

**Example**::

    -- Server-side: validate a ticket received from a client
    local result = Steam.User.BeginAuthSession(authTicketData, #authTicketData, clientSteamID)
    if result ~= Steam.k_EBeginAuthSessionResultOK then
        print('Auth session failed to start:', result)
    end

.. function:: User.CancelAuthTicket(hAuthTicket)

    🤖 **Auto-generated binding**

    :param int hAuthTicket:
    :SteamWorks: `CancelAuthTicket <https://partner.steamgames.com/doc/api/ISteamUser#CancelAuthTicket>`_

**Example**::

    Steam.User.CancelAuthTicket(ticketHandle)

.. function:: User.DecompressVoice(pCompressed, cbCompressed, cbDestBufferSize, nDesiredSampleRate)

    🤖 **Auto-generated binding**

    :param str pCompressed:
    :param int cbCompressed: size of the input array ``pCompressed``
    :param int cbDestBufferSize: size of the buffer to be allocated to hold the return value ``pDestBuffer``
    :param int nDesiredSampleRate:
    :returns: (int) Return value
    :returns: (str) ``pDestBuffer``
    :returns: (int) ``nBytesWritten``
    :SteamWorks: `DecompressVoice <https://partner.steamgames.com/doc/api/ISteamUser#DecompressVoice>`_

    **Signature differences from C++ API:**

    * Parameter ``pDestBuffer`` is no longer a parameter, and is instead an additional return value
    * Parameter ``nBytesWritten`` is no longer a parameter, and is instead an additional return value

**Example**::

    local SAMPLE_RATE = 24000
    local decompressed = Steam.User.DecompressVoice(compressedData, #compressedData, 65536, SAMPLE_RATE)
    if decompressed then
        playAudio(decompressed, SAMPLE_RATE)
    end

.. function:: User.EndAuthSession(steamID)

    🤖 **Auto-generated binding**

    :param uint64 steamID:
    :SteamWorks: `EndAuthSession <https://partner.steamgames.com/doc/api/ISteamUser#EndAuthSession>`_

**Example**::

    -- End auth session when client disconnects
    Steam.User.EndAuthSession(clientSteamID)

.. function:: User.GetAuthSessionTicket(cbMaxTicket, pSteamNetworkingIdentity)

    🤖 **Auto-generated binding**

    :param int cbMaxTicket: size of the buffer to be allocated to hold the return value ``pTicket``
    :param pSteamNetworkingIdentity: (:ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>`)
    :returns: (int) Return value
    :returns: (str) ``pTicket``
    :returns: (int) ``pcbTicket``
    :SteamWorks: `GetAuthSessionTicket <https://partner.steamgames.com/doc/api/ISteamUser#GetAuthSessionTicket>`_

    **Signature differences from C++ API:**

    * Parameter ``pTicket`` is no longer a parameter, and is instead an additional return value
    * Parameter ``pcbTicket`` is no longer a parameter, and is instead an additional return value

**Example**::

    local data = Steam.User.GetAuthSessionTicket('webapi:myservice')
    if data then
        local ticketHandle = data.m_hAuthTicket
        local ticketData = data.hexTicket
        -- Send ticketData to your server for verification
    end

.. function:: User.GetAuthTicketForWebApi(pchIdentity)

    🤖 **Auto-generated binding**

    :param str pchIdentity:
    :returns: (int) Return value
    :SteamWorks: `GetAuthTicketForWebApi <https://partner.steamgames.com/doc/api/ISteamUser#GetAuthTicketForWebApi>`_

.. function:: User.GetAvailableVoice()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :returns: (int) ``pcbCompressed``
    :SteamWorks: `GetAvailableVoice <https://partner.steamgames.com/doc/api/ISteamUser#GetAvailableVoice>`_

    **Signature differences from C++ API:**

    * Parameter ``pcbCompressed`` is no longer a parameter, and is instead an additional return value

**Example**::

    local compressed, raw, sampleRate = Steam.User.GetAvailableVoice()
    if compressed > 0 then
        local data = Steam.User.GetVoice(true, compressed)
        sendVoiceToNetwork(data)
    end

.. function:: User.GetDurationControl(callback)

    🤖 **Auto-generated binding**

    :param function callback: CallResult callback receiving struct :func:`DurationControl_t <User.OnDurationControl>` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `GetDurationControl <https://partner.steamgames.com/doc/api/ISteamUser#GetDurationControl>`_

.. function:: User.GetEncryptedAppTicket(cbMaxTicket)

    🤖 **Auto-generated binding**

    :param int cbMaxTicket: size of the buffer to be allocated to hold the return value ``pTicket``
    :returns: (bool) Return value
    :returns: (str) ``pTicket``
    :returns: (int) ``pcbTicket``
    :SteamWorks: `GetEncryptedAppTicket <https://partner.steamgames.com/doc/api/ISteamUser#GetEncryptedAppTicket>`_

    **Signature differences from C++ API:**

    * Parameter ``pTicket`` is no longer a parameter, and is instead an additional return value
    * Parameter ``pcbTicket`` is no longer a parameter, and is instead an additional return value

.. function:: User.GetGameBadgeLevel(nSeries, bFoil)

    🤖 **Auto-generated binding**

    :param int nSeries:
    :param bool bFoil:
    :returns: (int) Return value
    :SteamWorks: `GetGameBadgeLevel <https://partner.steamgames.com/doc/api/ISteamUser#GetGameBadgeLevel>`_

**Example**::

    local level = Steam.User.GetGameBadgeLevel(1, false)
    print('Badge level:', level)

.. function:: User.GetHSteamUser()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetHSteamUser <https://partner.steamgames.com/doc/api/ISteamUser#GetHSteamUser>`_

.. function:: User.GetMarketEligibility(callback)

    🤖 **Auto-generated binding**

    :param function callback: CallResult callback receiving struct :func:`MarketEligibilityResponse_t <User.OnMarketEligibilityResponse>` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `GetMarketEligibility <https://partner.steamgames.com/doc/api/ISteamUser#GetMarketEligibility>`_

.. function:: User.GetPlayerSteamLevel()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetPlayerSteamLevel <https://partner.steamgames.com/doc/api/ISteamUser#GetPlayerSteamLevel>`_

**Example**::

    print('Let me show you some magic')
    print('Your Steam Level is...')
    print(tostring(Steam.User.GetPlayerSteamLevel()) .. '!!!')

.. function:: User.GetSteamID()

    🤖 **Auto-generated binding**

    :returns: (uint64) Return value
    :SteamWorks: `GetSteamID <https://partner.steamgames.com/doc/api/ISteamUser#GetSteamID>`_

    Returns the CSteamID of the account currently logged in to the Steam client.

**Example**::

    local my_id = Steam.User.GetSteamID()
    local function isSteamIDFromUser(steam_id)
        return steam_id == my_id
    end

.. function:: User.GetUserDataFolder(cubBuffer)

    🤖 **Auto-generated binding**

    :param int cubBuffer: size of the buffer to be allocated to hold the return value ``pchBuffer``
    :returns: (bool) Return value
    :returns: (str) ``pchBuffer``
    :SteamWorks: `GetUserDataFolder <https://partner.steamgames.com/doc/api/ISteamUser#GetUserDataFolder>`_

    **Signature differences from C++ API:**

    * Parameter ``pchBuffer`` is no longer a parameter, and is instead an additional return value

**Example**::

    local success, path = Steam.User.GetUserDataFolder(512)
    if success then
        print('User data folder: ' .. path)
    end

.. function:: User.GetVoice(bWantCompressed, cbDestBufferSize)

    🤖 **Auto-generated binding**

    :param bool bWantCompressed:
    :param int cbDestBufferSize: size of the buffer to be allocated to hold the return value ``pDestBuffer``
    :returns: (int) Return value
    :returns: (str) ``pDestBuffer``
    :returns: (int) ``nBytesWritten``
    :SteamWorks: `GetVoice <https://partner.steamgames.com/doc/api/ISteamUser#GetVoice>`_

    **Signature differences from C++ API:**

    * Parameter ``pDestBuffer`` is no longer a parameter, and is instead an additional return value
    * Parameter ``nBytesWritten`` is no longer a parameter, and is instead an additional return value

**Example**::

    local available, _, _ = Steam.User.GetAvailableVoice()
    if available > 0 then
        local voiceData = Steam.User.GetVoice(true, available)
        if voiceData then
            sendVoiceToNetwork(voiceData)
        end
    end

.. function:: User.GetVoiceOptimalSampleRate()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetVoiceOptimalSampleRate <https://partner.steamgames.com/doc/api/ISteamUser#GetVoiceOptimalSampleRate>`_

**Example**::

    local sampleRate = Steam.User.GetVoiceOptimalSampleRate()
    print('Optimal voice sample rate: ' .. sampleRate .. ' Hz')

.. function:: User.RequestEncryptedAppTicket(pDataToInclude, cbDataToInclude, callback)

    🤖 **Auto-generated binding**

    :param str pDataToInclude:
    :param int cbDataToInclude: size of the input array ``pDataToInclude``
    :param function callback: CallResult callback receiving struct :func:`EncryptedAppTicketResponse_t <User.OnEncryptedAppTicketResponse>` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `RequestEncryptedAppTicket <https://partner.steamgames.com/doc/api/ISteamUser#RequestEncryptedAppTicket>`_

**Example**::

    local userData = 'extra_data'
    Steam.User.RequestEncryptedAppTicket(userData, #userData, function(data, err)
        if err or data.m_eResult ~= Steam.k_EResultOK then
            print('Failed to get encrypted app ticket')
        end
    end)

.. function:: User.RequestStoreAuthURL(pchRedirectURL, callback)

    🤖 **Auto-generated binding**

    :param str pchRedirectURL:
    :param function callback: CallResult callback receiving struct :func:`StoreAuthURLResponse_t <User.OnStoreAuthURLResponse>` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `RequestStoreAuthURL <https://partner.steamgames.com/doc/api/ISteamUser#RequestStoreAuthURL>`_

.. function:: User.StartVoiceRecording()

    🤖 **Auto-generated binding**

    :SteamWorks: `StartVoiceRecording <https://partner.steamgames.com/doc/api/ISteamUser#StartVoiceRecording>`_

**Example**::

    -- Call when push-to-talk key is pressed
    Steam.User.StartVoiceRecording()

.. function:: User.StopVoiceRecording()

    🤖 **Auto-generated binding**

    :SteamWorks: `StopVoiceRecording <https://partner.steamgames.com/doc/api/ISteamUser#StopVoiceRecording>`_

**Example**::

    -- Call when push-to-talk key is released
    Steam.User.StopVoiceRecording()

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

**Example**::

    local status = Steam.User.UserHasLicenseForApp(playerSteamID, dlcAppID)
    if status == Steam.k_EUserHasLicenseResultHasLicense then
        print('Player owns the DLC')
    end


Callbacks
---------

.. function:: User.OnSteamServersConnected

    Callback for `SteamServersConnected_t <https://partner.steamgames.com/doc/api/ISteamUser#SteamServersConnected_t>`_

    **callback(data)** receives no fields (notification only).

**Example**::

    function Steam.User.OnSteamServersConnected()
        print('Connected to Steam servers')
    end

.. function:: User.OnSteamServerConnectFailure

    Callback for `SteamServerConnectFailure_t <https://partner.steamgames.com/doc/api/ISteamUser#SteamServerConnectFailure_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(EResult)*
    * **data.m_bStillRetrying** *(bool)*

.. function:: User.OnSteamServersDisconnected

    Callback for `SteamServersDisconnected_t <https://partner.steamgames.com/doc/api/ISteamUser#SteamServersDisconnected_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(EResult)*

**Example**::

    function Steam.User.OnSteamServersDisconnected(data)
        print('Disconnected from Steam servers, result:', data.m_eResult)
    end

.. function:: User.OnClientGameServerDeny

    Callback for `ClientGameServerDeny_t <https://partner.steamgames.com/doc/api/ISteamUser#ClientGameServerDeny_t>`_

    **callback(data)** receives:

    * **data.m_uAppID** *(int)*
    * **data.m_unGameServerIP** *(int)*
    * **data.m_usGameServerPort** *(int)*
    * **data.m_bSecure** *(int)*
    * **data.m_uReason** *(int)*

.. function:: User.OnIPCFailure

    Callback for `IPCFailure_t <https://partner.steamgames.com/doc/api/ISteamUser#IPCFailure_t>`_

    **callback(data)** receives:

    * **data.m_eFailureType** *(int)*

.. function:: User.OnLicensesUpdated

    Callback for `LicensesUpdated_t <https://partner.steamgames.com/doc/api/ISteamUser#LicensesUpdated_t>`_

    **callback(data)** receives no fields (notification only).

.. function:: User.OnValidateAuthTicketResponse

    Callback for `ValidateAuthTicketResponse_t <https://partner.steamgames.com/doc/api/ISteamUser#ValidateAuthTicketResponse_t>`_

    **callback(data)** receives:

    * **data.m_SteamID** *(uint64)*
    * **data.m_eAuthSessionResponse** *(EAuthSessionResponse)*
    * **data.m_OwnerSteamID** *(uint64)*

**Example**::

    function Steam.User.OnValidateAuthTicketResponse(data)
        if data.m_eAuthSessionResponse == Steam.k_EAuthSessionResponseOK then
            print('User validated:', tostring(data.m_SteamID))
        else
            kickPlayer(data.m_SteamID)
        end
    end

.. function:: User.OnMicroTxnAuthorizationResponse

    Callback for `MicroTxnAuthorizationResponse_t <https://partner.steamgames.com/doc/api/ISteamUser#MicroTxnAuthorizationResponse_t>`_

    **callback(data)** receives:

    * **data.m_unAppID** *(int)*
    * **data.m_ulOrderID** *(uint64)*
    * **data.m_bAuthorized** *(int)*

**Example**::

    function Steam.User.OnMicroTxnAuthorizationResponse(data)
        if data.m_bAuthorized ~= 0 then
            print('Purchase authorized, orderID:', tostring(data.m_ulOrderID))
            completePurchase(data.m_ulOrderID)
        else
            print('Purchase cancelled by user')
        end
    end

.. function:: User.OnEncryptedAppTicketResponse

    Callback for `EncryptedAppTicketResponse_t <https://partner.steamgames.com/doc/api/ISteamUser#EncryptedAppTicketResponse_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(EResult)*

**Example**::

    function Steam.User.OnEncryptedAppTicketResponse(data)
        if data.m_eResult == Steam.k_EResultOK then
            local ticket = Steam.User.GetEncryptedAppTicket(1024)
            sendTicketToServer(ticket)
        end
    end

.. function:: User.OnGetAuthSessionTicketResponse

    Callback for `GetAuthSessionTicketResponse_t <https://partner.steamgames.com/doc/api/ISteamUser#GetAuthSessionTicketResponse_t>`_

    **callback(data)** receives:

    * **data.m_hAuthTicket** *(HAuthTicket)*
    * **data.m_eResult** *(EResult)*

**Example**::

    function Steam.User.OnGetAuthSessionTicketResponse(data)
        if data.m_eResult == Steam.k_EResultOK then
            print('Auth ticket ready, handle:', tostring(data.m_hAuthTicket))
        else
            print('Auth ticket failed:', data.m_eResult)
        end
    end

.. function:: User.OnGameWebCallback

    Callback for `GameWebCallback_t <https://partner.steamgames.com/doc/api/ISteamUser#GameWebCallback_t>`_

    **callback(data)** receives:

    * **data.m_szURL** *(string)*

.. function:: User.OnStoreAuthURLResponse

    Callback for `StoreAuthURLResponse_t <https://partner.steamgames.com/doc/api/ISteamUser#StoreAuthURLResponse_t>`_

    **callback(data)** receives:

    * **data.m_szURL** *(string)*

.. function:: User.OnMarketEligibilityResponse

    Callback for `MarketEligibilityResponse_t <https://partner.steamgames.com/doc/api/ISteamUser#MarketEligibilityResponse_t>`_

    **callback(data)** receives:

    * **data.m_bAllowed** *(bool)*
    * **data.m_eNotAllowedReason** *(EMarketNotAllowedReasonFlags)*
    * **data.m_rtAllowedAtTime** *(RTime32)*
    * **data.m_cdaySteamGuardRequiredDays** *(int)*
    * **data.m_cdayNewDeviceCooldown** *(int)*

.. function:: User.OnDurationControl

    Callback for `DurationControl_t <https://partner.steamgames.com/doc/api/ISteamUser#DurationControl_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(EResult)*
    * **data.m_appid** *(AppId_t)*
    * **data.m_bApplicable** *(bool)*
    * **data.m_csecsLast5h** *(int)*
    * **data.m_progress** *(EDurationControlProgress)*
    * **data.m_notification** *(EDurationControlNotification)*
    * **data.m_csecsToday** *(int)*
    * **data.m_csecsRemaining** *(int)*

.. function:: User.OnGetTicketForWebApiResponse

    Callback for `GetTicketForWebApiResponse_t <https://partner.steamgames.com/doc/api/ISteamUser#GetTicketForWebApiResponse_t>`_

    **callback(data)** receives:

    * **data.m_hAuthTicket** *(HAuthTicket)*
    * **data.m_eResult** *(EResult)*
    * **data.m_cubTicket** *(int)*
    * **data.m_rgubTicket** *(string)*

.. function:: User.OnGSPolicyResponse

    Callback for `GSPolicyResponse_t <https://partner.steamgames.com/doc/api/ISteamUser#GSPolicyResponse_t>`_

    **callback(data)** receives:

    * **data.m_bSecure** *(int)*

