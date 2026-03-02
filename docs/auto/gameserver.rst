################
ISteamGameServer
################

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✍️ are manually implemented and methods marked with ✋ are currently not implemented.

List of Functions
-----------------

* :func:`GameServer.AssociateWithClan`
* :func:`GameServer.BLoggedOn`
* :func:`GameServer.BSecure`
* :func:`GameServer.BUpdateUserData`
* :func:`GameServer.BeginAuthSession`
* :func:`GameServer.CancelAuthTicket`
* :func:`GameServer.ClearAllKeyValues`
* :func:`GameServer.ComputeNewPlayerCompatibility`
* :func:`GameServer.CreateUnauthenticatedUserConnection`
* :func:`GameServer.EndAuthSession`
* :func:`GameServer.GetAuthSessionTicket`
* :func:`GameServer.GetGameplayStats`
* :func:`GameServer.GetNextOutgoingPacket`
* :func:`GameServer.GetPublicIP`
* :func:`GameServer.GetServerReputation`
* :func:`GameServer.GetSteamID`
* :func:`GameServer.HandleIncomingPacket`
* :func:`GameServer.LogOff`
* :func:`GameServer.LogOn`
* :func:`GameServer.LogOnAnonymous`
* :func:`GameServer.RequestUserGroupStatus`
* :func:`GameServer.SetAdvertiseServerActive`
* :func:`GameServer.SetBotPlayerCount`
* :func:`GameServer.SetDedicatedServer`
* :func:`GameServer.SetGameData`
* :func:`GameServer.SetGameDescription`
* :func:`GameServer.SetGameTags`
* :func:`GameServer.SetKeyValue`
* :func:`GameServer.SetMapName`
* :func:`GameServer.SetMaxPlayerCount`
* :func:`GameServer.SetModDir`
* :func:`GameServer.SetPasswordProtected`
* :func:`GameServer.SetProduct`
* :func:`GameServer.SetRegion`
* :func:`GameServer.SetServerName`
* :func:`GameServer.SetSpectatorPort`
* :func:`GameServer.SetSpectatorServerName`
* :func:`GameServer.UserHasLicenseForApp`
* :func:`GameServer.WasRestartRequested`

List of Callbacks
-----------------

* :func:`GameServer.OnSteamServersConnected`
* :func:`GameServer.OnSteamServerConnectFailure`
* :func:`GameServer.OnSteamServersDisconnected`
* :func:`GameServer.OnValidateAuthTicketResponse`
* :func:`GameServer.OnGSClientApprove`
* :func:`GameServer.OnGSClientDeny`
* :func:`GameServer.OnGSClientKick`
* :func:`GameServer.OnGSClientAchievementStatus`
* :func:`GameServer.OnGSPolicyResponse`
* :func:`GameServer.OnGSGameplayStats`
* :func:`GameServer.OnGSClientGroupStatus`
* :func:`GameServer.OnGSReputation`
* :func:`GameServer.OnAssociateWithClanResult`
* :func:`GameServer.OnComputeNewPlayerCompatibilityResult`

Function Reference
------------------

.. function:: GameServer.AssociateWithClan(steamIDClan, callback)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClan:
    :param function callback: CallResult callback receiving struct `AssociateWithClanResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `AssociateWithClan <https://partner.steamgames.com/doc/api/ISteamGameServer#AssociateWithClan>`_

.. function:: GameServer.BLoggedOn()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BLoggedOn <https://partner.steamgames.com/doc/api/ISteamGameServer#BLoggedOn>`_

**Example**::

    local loggedOn = Steam.GameServer.BLoggedOn()

.. function:: GameServer.BSecure()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BSecure <https://partner.steamgames.com/doc/api/ISteamGameServer#BSecure>`_

**Example**::

    local secure = Steam.GameServer.BSecure()
    if secure then
        print('Server is VAC-secured')
    end

.. function:: GameServer.BUpdateUserData(steamIDUser, pchPlayerName, uScore)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param str pchPlayerName:
    :param int uScore:
    :returns: (bool) Return value
    :SteamWorks: `BUpdateUserData <https://partner.steamgames.com/doc/api/ISteamGameServer#BUpdateUserData>`_

**Example**::

    -- Update a connected player's display name and score
    Steam.GameServer.BUpdateUserData(playerSteamID, playerName, playerScore)

.. function:: GameServer.BeginAuthSession(pAuthTicket, cbAuthTicket, steamID)

    🤖 **Auto-generated binding**

    :param str pAuthTicket:
    :param int cbAuthTicket: size of the input array ``pAuthTicket``
    :param uint64 steamID:
    :returns: (int) Return value
    :SteamWorks: `BeginAuthSession <https://partner.steamgames.com/doc/api/ISteamGameServer#BeginAuthSession>`_

**Example**::

    -- Validate an auth ticket received from a client
    Steam.GameServer.BeginAuthSession(authTicket, steamID)

.. function:: GameServer.CancelAuthTicket(hAuthTicket)

    🤖 **Auto-generated binding**

    :param int hAuthTicket:
    :SteamWorks: `CancelAuthTicket <https://partner.steamgames.com/doc/api/ISteamGameServer#CancelAuthTicket>`_

.. function:: GameServer.ClearAllKeyValues()

    🤖 **Auto-generated binding**

    :SteamWorks: `ClearAllKeyValues <https://partner.steamgames.com/doc/api/ISteamGameServer#ClearAllKeyValues>`_

**Example**::

    Steam.GameServer.ClearAllKeyValues()
    -- Reset and re-add updated values
    Steam.GameServer.SetKeyValue('version', '1.6.0')

.. function:: GameServer.ComputeNewPlayerCompatibility(steamIDNewPlayer, callback)

    🤖 **Auto-generated binding**

    :param uint64 steamIDNewPlayer:
    :param function callback: CallResult callback receiving struct `ComputeNewPlayerCompatibilityResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `ComputeNewPlayerCompatibility <https://partner.steamgames.com/doc/api/ISteamGameServer#ComputeNewPlayerCompatibility>`_

.. function:: GameServer.CreateUnauthenticatedUserConnection()

    🤖 **Auto-generated binding**

    :returns: (uint64) Return value
    :SteamWorks: `CreateUnauthenticatedUserConnection <https://partner.steamgames.com/doc/api/ISteamGameServer#CreateUnauthenticatedUserConnection>`_

.. function:: GameServer.EndAuthSession(steamID)

    🤖 **Auto-generated binding**

    :param uint64 steamID:
    :SteamWorks: `EndAuthSession <https://partner.steamgames.com/doc/api/ISteamGameServer#EndAuthSession>`_

**Example**::

    Steam.GameServer.EndAuthSession(steamID)

.. function:: GameServer.GetAuthSessionTicket(cbMaxTicket, pSnid)

    🤖 **Auto-generated binding**

    :param int cbMaxTicket: size of the buffer to be allocated to hold the return value ``pTicket``
    :param :ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>` pSnid:
    :returns: (int) Return value
    :returns: (str) Value for `pTicket`
    :returns: (int) Value for `pcbTicket`
    :SteamWorks: `GetAuthSessionTicket <https://partner.steamgames.com/doc/api/ISteamGameServer#GetAuthSessionTicket>`_

    **Signature differences from C++ API:**

    * Parameter ``pTicket`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pcbTicket`` is no longer a paramer, and is instead an additional return value

.. function:: GameServer.GetGameplayStats()

    🤖 **Auto-generated binding**

    :SteamWorks: `GetGameplayStats <https://partner.steamgames.com/doc/api/ISteamGameServer#GetGameplayStats>`_

.. function:: GameServer.GetNextOutgoingPacket(cbMaxOut)

    🤖 **Auto-generated binding**

    :param int cbMaxOut: size of the buffer to be allocated to hold the return value ``pOut``
    :returns: (int) Return value
    :returns: (str) Value for `pOut`
    :returns: (int) Value for `pNetAdr`
    :returns: (int) Value for `pPort`
    :SteamWorks: `GetNextOutgoingPacket <https://partner.steamgames.com/doc/api/ISteamGameServer#GetNextOutgoingPacket>`_

    **Signature differences from C++ API:**

    * Parameter ``pOut`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pNetAdr`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pPort`` is no longer a paramer, and is instead an additional return value

.. function:: GameServer.GetPublicIP()

    🤖 **Auto-generated binding**

    :returns: (:ref:`SteamIPAddress_t <struct-SteamIPAddress_t>`) Return value
    :SteamWorks: `GetPublicIP <https://partner.steamgames.com/doc/api/ISteamGameServer#GetPublicIP>`_

**Example**::

    local ip = Steam.GameServer.GetPublicIP()
    print('Server public IP:', ip)

.. function:: GameServer.GetServerReputation(callback)

    🤖 **Auto-generated binding**

    :param function callback: CallResult callback receiving struct `GSReputation_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `GetServerReputation <https://partner.steamgames.com/doc/api/ISteamGameServer#GetServerReputation>`_

.. function:: GameServer.GetSteamID()

    🤖 **Auto-generated binding**

    :returns: (uint64) Return value
    :SteamWorks: `GetSteamID <https://partner.steamgames.com/doc/api/ISteamGameServer#GetSteamID>`_

**Example**::

    local server_id = Steam.GameServer.GetSteamID()
    print('Server Steam ID:', tostring(server_id))

.. function:: GameServer.HandleIncomingPacket(pData, cbData, srcIP, srcPort)

    🤖 **Auto-generated binding**

    :param str pData:
    :param int cbData: size of the input array ``pData``
    :param int srcIP:
    :param int srcPort:
    :returns: (bool) Return value
    :SteamWorks: `HandleIncomingPacket <https://partner.steamgames.com/doc/api/ISteamGameServer#HandleIncomingPacket>`_

.. function:: GameServer.LogOff()

    🤖 **Auto-generated binding**

    :SteamWorks: `LogOff <https://partner.steamgames.com/doc/api/ISteamGameServer#LogOff>`_

**Example**::

    Steam.GameServer.LogOff()

.. function:: GameServer.LogOn(pszToken)

    🤖 **Auto-generated binding**

    :param str pszToken:
    :SteamWorks: `LogOn <https://partner.steamgames.com/doc/api/ISteamGameServer#LogOn>`_

**Example**::

    local accessToken = 'abcdef123456'  -- Access token from Steam partner site
    Steam.GameServer.LogOn(accessToken)

.. function:: GameServer.LogOnAnonymous()

    🤖 **Auto-generated binding**

    :SteamWorks: `LogOnAnonymous <https://partner.steamgames.com/doc/api/ISteamGameServer#LogOnAnonymous>`_

**Example**::

    Steam.GameServer.LogOnAnonymous()

.. function:: GameServer.RequestUserGroupStatus(steamIDUser, steamIDGroup)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param uint64 steamIDGroup:
    :returns: (bool) Return value
    :SteamWorks: `RequestUserGroupStatus <https://partner.steamgames.com/doc/api/ISteamGameServer#RequestUserGroupStatus>`_

**Example**::

    -- Check if a player is in a Steam group (e.g. for whitelist)
    Steam.GameServer.RequestUserGroupStatus(playerSteamID, groupSteamID)

.. function:: GameServer.SetAdvertiseServerActive(bActive)

    🤖 **Auto-generated binding**

    :param bool bActive:
    :SteamWorks: `SetAdvertiseServerActive <https://partner.steamgames.com/doc/api/ISteamGameServer#SetAdvertiseServerActive>`_

**Example**::

    -- Make the server visible in the server browser
    Steam.GameServer.SetAdvertiseServerActive(true)

.. function:: GameServer.SetBotPlayerCount(cBotplayers)

    🤖 **Auto-generated binding**

    :param int cBotplayers:
    :SteamWorks: `SetBotPlayerCount <https://partner.steamgames.com/doc/api/ISteamGameServer#SetBotPlayerCount>`_

**Example**::

    Steam.GameServer.SetBotPlayerCount(0)

.. function:: GameServer.SetDedicatedServer(bDedicated)

    🤖 **Auto-generated binding**

    :param bool bDedicated:
    :SteamWorks: `SetDedicatedServer <https://partner.steamgames.com/doc/api/ISteamGameServer#SetDedicatedServer>`_

**Example**::

    Steam.GameServer.SetDedicatedServer(true)

.. function:: GameServer.SetGameData(pchGameData)

    🤖 **Auto-generated binding**

    :param str pchGameData:
    :SteamWorks: `SetGameData <https://partner.steamgames.com/doc/api/ISteamGameServer#SetGameData>`_

.. function:: GameServer.SetGameDescription(pszGameDescription)

    🤖 **Auto-generated binding**

    :param str pszGameDescription:
    :SteamWorks: `SetGameDescription <https://partner.steamgames.com/doc/api/ISteamGameServer#SetGameDescription>`_

**Example**::

    Steam.GameServer.SetGameDescription('A competitive FPS game')

.. function:: GameServer.SetGameTags(pchGameTags)

    🤖 **Auto-generated binding**

    :param str pchGameTags:
    :SteamWorks: `SetGameTags <https://partner.steamgames.com/doc/api/ISteamGameServer#SetGameTags>`_

**Example**::

    Steam.GameServer.SetGameTags('ranked,competitive')

.. function:: GameServer.SetKeyValue(pKey, pValue)

    🤖 **Auto-generated binding**

    :param str pKey:
    :param str pValue:
    :SteamWorks: `SetKeyValue <https://partner.steamgames.com/doc/api/ISteamGameServer#SetKeyValue>`_

**Example**::

    -- Set server rules visible in the server browser
    Steam.GameServer.SetKeyValue('version', '1.5.0')
    Steam.GameServer.SetKeyValue('region', 'us-east')

.. function:: GameServer.SetMapName(pszMapName)

    🤖 **Auto-generated binding**

    :param str pszMapName:
    :SteamWorks: `SetMapName <https://partner.steamgames.com/doc/api/ISteamGameServer#SetMapName>`_

**Example**::

    Steam.GameServer.SetMapName('de_dust2')

.. function:: GameServer.SetMaxPlayerCount(cPlayersMax)

    🤖 **Auto-generated binding**

    :param int cPlayersMax:
    :SteamWorks: `SetMaxPlayerCount <https://partner.steamgames.com/doc/api/ISteamGameServer#SetMaxPlayerCount>`_

**Example**::

    Steam.GameServer.SetMaxPlayerCount(16)

.. function:: GameServer.SetModDir(pszModDir)

    🤖 **Auto-generated binding**

    :param str pszModDir:
    :SteamWorks: `SetModDir <https://partner.steamgames.com/doc/api/ISteamGameServer#SetModDir>`_

.. function:: GameServer.SetPasswordProtected(bPasswordProtected)

    🤖 **Auto-generated binding**

    :param bool bPasswordProtected:
    :SteamWorks: `SetPasswordProtected <https://partner.steamgames.com/doc/api/ISteamGameServer#SetPasswordProtected>`_

**Example**::

    Steam.GameServer.SetPasswordProtected(false)

.. function:: GameServer.SetProduct(pszProduct)

    🤖 **Auto-generated binding**

    :param str pszProduct:
    :SteamWorks: `SetProduct <https://partner.steamgames.com/doc/api/ISteamGameServer#SetProduct>`_

.. function:: GameServer.SetRegion(pszRegion)

    🤖 **Auto-generated binding**

    :param str pszRegion:
    :SteamWorks: `SetRegion <https://partner.steamgames.com/doc/api/ISteamGameServer#SetRegion>`_

.. function:: GameServer.SetServerName(pszServerName)

    🤖 **Auto-generated binding**

    :param str pszServerName:
    :SteamWorks: `SetServerName <https://partner.steamgames.com/doc/api/ISteamGameServer#SetServerName>`_

**Example**::

    Steam.GameServer.SetServerName('My Awesome Server')

.. function:: GameServer.SetSpectatorPort(unSpectatorPort)

    🤖 **Auto-generated binding**

    :param int unSpectatorPort:
    :SteamWorks: `SetSpectatorPort <https://partner.steamgames.com/doc/api/ISteamGameServer#SetSpectatorPort>`_

.. function:: GameServer.SetSpectatorServerName(pszSpectatorServerName)

    🤖 **Auto-generated binding**

    :param str pszSpectatorServerName:
    :SteamWorks: `SetSpectatorServerName <https://partner.steamgames.com/doc/api/ISteamGameServer#SetSpectatorServerName>`_

.. function:: GameServer.UserHasLicenseForApp(steamID, appID)

    🤖 **Auto-generated binding**

    :param uint64 steamID:
    :param int appID:
    :returns: (int) Return value
    :SteamWorks: `UserHasLicenseForApp <https://partner.steamgames.com/doc/api/ISteamGameServer#UserHasLicenseForApp>`_

.. function:: GameServer.WasRestartRequested()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `WasRestartRequested <https://partner.steamgames.com/doc/api/ISteamGameServer#WasRestartRequested>`_

**Example**::

    if Steam.GameServer.WasRestartRequested() then
        print('Steam requested server restart for update')
        scheduleRestart()
    end


Callbacks
---------

.. function:: GameServer.OnSteamServersConnected

    Callback for `SteamServersConnected_t <https://partner.steamgames.com/doc/api/ISteamGameServer#SteamServersConnected_t>`_

    **callback(data)** receives:


**Example**::

    function Steam.GameServer.OnSteamServersConnected()
        print('Connected to Steam servers')
    end

.. function:: GameServer.OnSteamServerConnectFailure

    Callback for `SteamServerConnectFailure_t <https://partner.steamgames.com/doc/api/ISteamGameServer#SteamServerConnectFailure_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_bStillRetrying** -- m_bStillRetrying

**Example**::

    function Steam.GameServer.OnSteamServerConnectFailure(data)
        print('Connection to Steam failed:', data.m_eResult, 'retrying:', data.m_bStillRetrying)
    end

.. function:: GameServer.OnSteamServersDisconnected

    Callback for `SteamServersDisconnected_t <https://partner.steamgames.com/doc/api/ISteamGameServer#SteamServersDisconnected_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult

**Example**::

    function Steam.GameServer.OnSteamServersDisconnected(data)
        print('Disconnected from Steam servers:', data.m_eResult)
    end

.. function:: GameServer.OnValidateAuthTicketResponse

    Callback for `ValidateAuthTicketResponse_t <https://partner.steamgames.com/doc/api/ISteamGameServer#ValidateAuthTicketResponse_t>`_

    **callback(data)** receives:

    * **data.m_SteamID** -- m_SteamID
    * **data.m_eAuthSessionResponse** -- m_eAuthSessionResponse
    * **data.m_OwnerSteamID** -- m_OwnerSteamID

**Example**::

    function Steam.GameServer.OnValidateAuthTicketResponse(data)
        if data.m_eAuthSessionResponse == Steam.k_EAuthSessionResponseOK then
            print('User authenticated:', tostring(data.m_SteamID))
        else
            print('Authentication failed:', data.m_eAuthSessionResponse)
        end
    end

.. function:: GameServer.OnGSClientApprove

    Callback for `GSClientApprove_t <https://partner.steamgames.com/doc/api/ISteamGameServer#GSClientApprove_t>`_

    **callback(data)** receives:

    * **data.m_SteamID** -- m_SteamID
    * **data.m_OwnerSteamID** -- m_OwnerSteamID

**Example**::

    function Steam.GameServer.OnGSClientApprove(data)
        print('Client approved:', tostring(data.m_SteamID))
        allowPlayerToJoin(data.m_SteamID)
    end

.. function:: GameServer.OnGSClientDeny

    Callback for `GSClientDeny_t <https://partner.steamgames.com/doc/api/ISteamGameServer#GSClientDeny_t>`_

    **callback(data)** receives:

    * **data.m_SteamID** -- m_SteamID
    * **data.m_eDenyReason** -- m_eDenyReason
    * **data.m_rgchOptionalText** -- m_rgchOptionalText

**Example**::

    function Steam.GameServer.OnGSClientDeny(data)
        print('Client denied:', tostring(data.m_SteamID), 'reason:', data.m_eDenyReason)
        kickPlayer(data.m_SteamID)
    end

.. function:: GameServer.OnGSClientKick

    Callback for `GSClientKick_t <https://partner.steamgames.com/doc/api/ISteamGameServer#GSClientKick_t>`_

    **callback(data)** receives:

    * **data.m_SteamID** -- m_SteamID
    * **data.m_eDenyReason** -- m_eDenyReason

.. function:: GameServer.OnGSClientAchievementStatus

    Callback for `GSClientAchievementStatus_t <https://partner.steamgames.com/doc/api/ISteamGameServer#GSClientAchievementStatus_t>`_

    **callback(data)** receives:

    * **data.m_SteamID** -- m_SteamID
    * **data.m_pchAchievement** -- m_pchAchievement
    * **data.m_bUnlocked** -- m_bUnlocked

.. function:: GameServer.OnGSPolicyResponse

    Callback for `GSPolicyResponse_t <https://partner.steamgames.com/doc/api/ISteamGameServer#GSPolicyResponse_t>`_

    **callback(data)** receives:

    * **data.m_bSecure** -- m_bSecure

**Example**::

    function Steam.GameServer.OnGSPolicyResponse(data)
        if Steam.GameServer.BSecure() then
            print('Server is VAC secured')
        end
    end

.. function:: GameServer.OnGSGameplayStats

    Callback for `GSGameplayStats_t <https://partner.steamgames.com/doc/api/ISteamGameServer#GSGameplayStats_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nRank** -- m_nRank
    * **data.m_unTotalConnects** -- m_unTotalConnects
    * **data.m_unTotalMinutesPlayed** -- m_unTotalMinutesPlayed

.. function:: GameServer.OnGSClientGroupStatus

    Callback for `GSClientGroupStatus_t <https://partner.steamgames.com/doc/api/ISteamGameServer#GSClientGroupStatus_t>`_

    **callback(data)** receives:

    * **data.m_SteamIDUser** -- m_SteamIDUser
    * **data.m_SteamIDGroup** -- m_SteamIDGroup
    * **data.m_bMember** -- m_bMember
    * **data.m_bOfficer** -- m_bOfficer

**Example**::

    function Steam.GameServer.OnGSClientGroupStatus(data)
        if data.m_bMember ~= 0 then
            print('Player is a member of the required group:', tostring(data.m_SteamIDUser))
        end
    end

.. function:: GameServer.OnGSReputation

    Callback for `GSReputation_t <https://partner.steamgames.com/doc/api/ISteamGameServer#GSReputation_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_unReputationScore** -- m_unReputationScore
    * **data.m_bBanned** -- m_bBanned
    * **data.m_unBannedIP** -- m_unBannedIP
    * **data.m_usBannedPort** -- m_usBannedPort
    * **data.m_ulBannedGameID** -- m_ulBannedGameID
    * **data.m_unBanExpires** -- m_unBanExpires

.. function:: GameServer.OnAssociateWithClanResult

    Callback for `AssociateWithClanResult_t <https://partner.steamgames.com/doc/api/ISteamGameServer#AssociateWithClanResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult

.. function:: GameServer.OnComputeNewPlayerCompatibilityResult

    Callback for `ComputeNewPlayerCompatibilityResult_t <https://partner.steamgames.com/doc/api/ISteamGameServer#ComputeNewPlayerCompatibilityResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_cPlayersThatDontLikeCandidate** -- m_cPlayersThatDontLikeCandidate
    * **data.m_cPlayersThatCandidateDoesntLike** -- m_cPlayersThatCandidateDoesntLike
    * **data.m_cClanPlayersThatDontLikeCandidate** -- m_cClanPlayersThatDontLikeCandidate
    * **data.m_SteamIDCandidate** -- m_SteamIDCandidate

