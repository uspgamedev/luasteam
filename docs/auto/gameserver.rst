################
ISteamGameServer
################

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✋ require manual implementation.

List of Functions
-----------------

* :func:`GameServer.SetProduct`
* :func:`GameServer.SetGameDescription`
* :func:`GameServer.SetModDir`
* :func:`GameServer.SetDedicatedServer`
* :func:`GameServer.LogOn`
* :func:`GameServer.LogOnAnonymous`
* :func:`GameServer.LogOff`
* :func:`GameServer.BLoggedOn`
* :func:`GameServer.BSecure`
* :func:`GameServer.GetSteamID`
* :func:`GameServer.WasRestartRequested`
* :func:`GameServer.SetMaxPlayerCount`
* :func:`GameServer.SetBotPlayerCount`
* :func:`GameServer.SetServerName`
* :func:`GameServer.SetMapName`
* :func:`GameServer.SetPasswordProtected`
* :func:`GameServer.SetSpectatorPort`
* :func:`GameServer.SetSpectatorServerName`
* :func:`GameServer.ClearAllKeyValues`
* :func:`GameServer.SetKeyValue`
* :func:`GameServer.SetGameTags`
* :func:`GameServer.SetGameData`
* :func:`GameServer.SetRegion`
* :func:`GameServer.SetAdvertiseServerActive`
* :func:`GameServer.GetAuthSessionTicket`
* :func:`GameServer.EndAuthSession`
* :func:`GameServer.CancelAuthTicket`
* :func:`GameServer.UserHasLicenseForApp`
* :func:`GameServer.RequestUserGroupStatus`
* :func:`GameServer.GetGameplayStats`
* :func:`GameServer.GetServerReputation`
* :func:`GameServer.GetPublicIP`
* :func:`GameServer.GetNextOutgoingPacket`
* :func:`GameServer.AssociateWithClan`
* :func:`GameServer.ComputeNewPlayerCompatibility`
* :func:`GameServer.CreateUnauthenticatedUserConnection`
* :func:`GameServer.BUpdateUserData`

List of Callbacks
-----------------

* :func:`GameServer.onSteamServersConnected`
* :func:`GameServer.onSteamServerConnectFailure`
* :func:`GameServer.onSteamServersDisconnected`
* :func:`GameServer.onValidateAuthTicketResponse`
* :func:`GameServer.onGSClientApprove`
* :func:`GameServer.onGSClientDeny`
* :func:`GameServer.onGSClientKick`
* :func:`GameServer.onGSClientAchievementStatus`
* :func:`GameServer.onGSPolicyResponse`
* :func:`GameServer.onGSGameplayStats`
* :func:`GameServer.onGSClientGroupStatus`
* :func:`GameServer.onGSReputation`
* :func:`GameServer.onAssociateWithClanResult`
* :func:`GameServer.onComputeNewPlayerCompatibilityResult`

Function Reference
------------------

.. function:: GameServer.SetProduct(pszProduct)

    🤖 **Auto-generated binding**

    :param str pszProduct:
    :SteamWorks: `SetProduct <https://partner.steamgames.com/doc/api/ISteamGameServer#SetProduct>`_

.. function:: GameServer.SetGameDescription(pszGameDescription)

    🤖 **Auto-generated binding**

    :param str pszGameDescription:
    :SteamWorks: `SetGameDescription <https://partner.steamgames.com/doc/api/ISteamGameServer#SetGameDescription>`_

.. function:: GameServer.SetModDir(pszModDir)

    🤖 **Auto-generated binding**

    :param str pszModDir:
    :SteamWorks: `SetModDir <https://partner.steamgames.com/doc/api/ISteamGameServer#SetModDir>`_

.. function:: GameServer.SetDedicatedServer(bDedicated)

    🤖 **Auto-generated binding**

    :param bool bDedicated:
    :SteamWorks: `SetDedicatedServer <https://partner.steamgames.com/doc/api/ISteamGameServer#SetDedicatedServer>`_

.. function:: GameServer.LogOn(pszToken)

    🤖 **Auto-generated binding**

    :param str pszToken:
    :SteamWorks: `LogOn <https://partner.steamgames.com/doc/api/ISteamGameServer#LogOn>`_

.. function:: GameServer.LogOnAnonymous()

    🤖 **Auto-generated binding**

    :SteamWorks: `LogOnAnonymous <https://partner.steamgames.com/doc/api/ISteamGameServer#LogOnAnonymous>`_

.. function:: GameServer.LogOff()

    🤖 **Auto-generated binding**

    :SteamWorks: `LogOff <https://partner.steamgames.com/doc/api/ISteamGameServer#LogOff>`_

.. function:: GameServer.BLoggedOn()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BLoggedOn <https://partner.steamgames.com/doc/api/ISteamGameServer#BLoggedOn>`_

.. function:: GameServer.BSecure()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BSecure <https://partner.steamgames.com/doc/api/ISteamGameServer#BSecure>`_

.. function:: GameServer.GetSteamID()

    🤖 **Auto-generated binding**

    :returns: (uint64) Return value
    :SteamWorks: `GetSteamID <https://partner.steamgames.com/doc/api/ISteamGameServer#GetSteamID>`_

.. function:: GameServer.WasRestartRequested()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `WasRestartRequested <https://partner.steamgames.com/doc/api/ISteamGameServer#WasRestartRequested>`_

.. function:: GameServer.SetMaxPlayerCount(cPlayersMax)

    🤖 **Auto-generated binding**

    :param int cPlayersMax:
    :SteamWorks: `SetMaxPlayerCount <https://partner.steamgames.com/doc/api/ISteamGameServer#SetMaxPlayerCount>`_

.. function:: GameServer.SetBotPlayerCount(cBotplayers)

    🤖 **Auto-generated binding**

    :param int cBotplayers:
    :SteamWorks: `SetBotPlayerCount <https://partner.steamgames.com/doc/api/ISteamGameServer#SetBotPlayerCount>`_

.. function:: GameServer.SetServerName(pszServerName)

    🤖 **Auto-generated binding**

    :param str pszServerName:
    :SteamWorks: `SetServerName <https://partner.steamgames.com/doc/api/ISteamGameServer#SetServerName>`_

.. function:: GameServer.SetMapName(pszMapName)

    🤖 **Auto-generated binding**

    :param str pszMapName:
    :SteamWorks: `SetMapName <https://partner.steamgames.com/doc/api/ISteamGameServer#SetMapName>`_

.. function:: GameServer.SetPasswordProtected(bPasswordProtected)

    🤖 **Auto-generated binding**

    :param bool bPasswordProtected:
    :SteamWorks: `SetPasswordProtected <https://partner.steamgames.com/doc/api/ISteamGameServer#SetPasswordProtected>`_

.. function:: GameServer.SetSpectatorPort(unSpectatorPort)

    🤖 **Auto-generated binding**

    :param int unSpectatorPort:
    :SteamWorks: `SetSpectatorPort <https://partner.steamgames.com/doc/api/ISteamGameServer#SetSpectatorPort>`_

.. function:: GameServer.SetSpectatorServerName(pszSpectatorServerName)

    🤖 **Auto-generated binding**

    :param str pszSpectatorServerName:
    :SteamWorks: `SetSpectatorServerName <https://partner.steamgames.com/doc/api/ISteamGameServer#SetSpectatorServerName>`_

.. function:: GameServer.ClearAllKeyValues()

    🤖 **Auto-generated binding**

    :SteamWorks: `ClearAllKeyValues <https://partner.steamgames.com/doc/api/ISteamGameServer#ClearAllKeyValues>`_

.. function:: GameServer.SetKeyValue(pKey, pValue)

    🤖 **Auto-generated binding**

    :param str pKey:
    :param str pValue:
    :SteamWorks: `SetKeyValue <https://partner.steamgames.com/doc/api/ISteamGameServer#SetKeyValue>`_

.. function:: GameServer.SetGameTags(pchGameTags)

    🤖 **Auto-generated binding**

    :param str pchGameTags:
    :SteamWorks: `SetGameTags <https://partner.steamgames.com/doc/api/ISteamGameServer#SetGameTags>`_

.. function:: GameServer.SetGameData(pchGameData)

    🤖 **Auto-generated binding**

    :param str pchGameData:
    :SteamWorks: `SetGameData <https://partner.steamgames.com/doc/api/ISteamGameServer#SetGameData>`_

.. function:: GameServer.SetRegion(pszRegion)

    🤖 **Auto-generated binding**

    :param str pszRegion:
    :SteamWorks: `SetRegion <https://partner.steamgames.com/doc/api/ISteamGameServer#SetRegion>`_

.. function:: GameServer.SetAdvertiseServerActive(bActive)

    🤖 **Auto-generated binding**

    :param bool bActive:
    :SteamWorks: `SetAdvertiseServerActive <https://partner.steamgames.com/doc/api/ISteamGameServer#SetAdvertiseServerActive>`_

.. function:: GameServer.GetAuthSessionTicket(cbMaxTicket, pSnid)

    🤖 **Auto-generated binding**

    :param int cbMaxTicket:
    :param :ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>` pSnid:
    :returns: (int) Return value
    :returns: (str) Value for `pTicket`
    :returns: (int) Value for `pcbTicket`
    :SteamWorks: `GetAuthSessionTicket <https://partner.steamgames.com/doc/api/ISteamGameServer#GetAuthSessionTicket>`_

    **Signature differences from C++ API:**

    * Parameter ``pTicket`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pcbTicket`` is no longer a paramer, and is instead an additional return value

.. function:: GameServer.EndAuthSession(steamID)

    🤖 **Auto-generated binding**

    :param uint64 steamID:
    :SteamWorks: `EndAuthSession <https://partner.steamgames.com/doc/api/ISteamGameServer#EndAuthSession>`_

.. function:: GameServer.CancelAuthTicket(hAuthTicket)

    🤖 **Auto-generated binding**

    :param int hAuthTicket:
    :SteamWorks: `CancelAuthTicket <https://partner.steamgames.com/doc/api/ISteamGameServer#CancelAuthTicket>`_

.. function:: GameServer.UserHasLicenseForApp(steamID, appID)

    🤖 **Auto-generated binding**

    :param uint64 steamID:
    :param int appID:
    :returns: (int) Return value
    :SteamWorks: `UserHasLicenseForApp <https://partner.steamgames.com/doc/api/ISteamGameServer#UserHasLicenseForApp>`_

.. function:: GameServer.RequestUserGroupStatus(steamIDUser, steamIDGroup)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param uint64 steamIDGroup:
    :returns: (bool) Return value
    :SteamWorks: `RequestUserGroupStatus <https://partner.steamgames.com/doc/api/ISteamGameServer#RequestUserGroupStatus>`_

.. function:: GameServer.GetGameplayStats()

    🤖 **Auto-generated binding**

    :SteamWorks: `GetGameplayStats <https://partner.steamgames.com/doc/api/ISteamGameServer#GetGameplayStats>`_

.. function:: GameServer.GetServerReputation(callback)

    🤖 **Auto-generated binding**

    :param function callback: CallResult callback receiving struct `GSReputation_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `GetServerReputation <https://partner.steamgames.com/doc/api/ISteamGameServer#GetServerReputation>`_

.. function:: GameServer.GetPublicIP()

    🤖 **Auto-generated binding**

    :returns: (:ref:`SteamIPAddress_t <struct-SteamIPAddress_t>`) Return value
    :SteamWorks: `GetPublicIP <https://partner.steamgames.com/doc/api/ISteamGameServer#GetPublicIP>`_

.. function:: GameServer.GetNextOutgoingPacket(cbMaxOut)

    🤖 **Auto-generated binding**

    :param int cbMaxOut:
    :returns: (int) Return value
    :returns: (str) Value for `pOut`
    :returns: (int) Value for `pNetAdr`
    :returns: (int) Value for `pPort`
    :SteamWorks: `GetNextOutgoingPacket <https://partner.steamgames.com/doc/api/ISteamGameServer#GetNextOutgoingPacket>`_

    **Signature differences from C++ API:**

    * Parameter ``pOut`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pNetAdr`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pPort`` is no longer a paramer, and is instead an additional return value

.. function:: GameServer.AssociateWithClan(steamIDClan, callback)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClan:
    :param function callback: CallResult callback receiving struct `AssociateWithClanResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `AssociateWithClan <https://partner.steamgames.com/doc/api/ISteamGameServer#AssociateWithClan>`_

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

.. function:: GameServer.BUpdateUserData(steamIDUser, pchPlayerName, uScore)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param str pchPlayerName:
    :param int uScore:
    :returns: (bool) Return value
    :SteamWorks: `BUpdateUserData <https://partner.steamgames.com/doc/api/ISteamGameServer#BUpdateUserData>`_


Unimplemented Methods
---------------------

.. function:: GameServer.beginAuthSession

    ✋ **Not implemented** - unsupported type: const void *
    
    :SteamWorks: `BeginAuthSession <https://partner.steamgames.com/doc/api/ISteamGameServer#BeginAuthSession>`_

.. function:: GameServer.handleIncomingPacket

    ✋ **Not implemented** - unsupported type: const void *
    
    :SteamWorks: `HandleIncomingPacket <https://partner.steamgames.com/doc/api/ISteamGameServer#HandleIncomingPacket>`_


Callbacks
---------

.. function:: GameServer.onSteamServersConnected

    Callback for `SteamServersConnected_t <https://partner.steamgames.com/doc/api/ISteamGameServer#SteamServersConnected_t>`_

    **callback(data)** receives:


.. function:: GameServer.onSteamServerConnectFailure

    Callback for `SteamServerConnectFailure_t <https://partner.steamgames.com/doc/api/ISteamGameServer#SteamServerConnectFailure_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_bStillRetrying** -- m_bStillRetrying

.. function:: GameServer.onSteamServersDisconnected

    Callback for `SteamServersDisconnected_t <https://partner.steamgames.com/doc/api/ISteamGameServer#SteamServersDisconnected_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult

.. function:: GameServer.onValidateAuthTicketResponse

    Callback for `ValidateAuthTicketResponse_t <https://partner.steamgames.com/doc/api/ISteamGameServer#ValidateAuthTicketResponse_t>`_

    **callback(data)** receives:

    * **data.m_SteamID** -- m_SteamID
    * **data.m_eAuthSessionResponse** -- m_eAuthSessionResponse
    * **data.m_OwnerSteamID** -- m_OwnerSteamID

.. function:: GameServer.onGSClientApprove

    Callback for `GSClientApprove_t <https://partner.steamgames.com/doc/api/ISteamGameServer#GSClientApprove_t>`_

    **callback(data)** receives:

    * **data.m_SteamID** -- m_SteamID
    * **data.m_OwnerSteamID** -- m_OwnerSteamID

.. function:: GameServer.onGSClientDeny

    Callback for `GSClientDeny_t <https://partner.steamgames.com/doc/api/ISteamGameServer#GSClientDeny_t>`_

    **callback(data)** receives:

    * **data.m_SteamID** -- m_SteamID
    * **data.m_eDenyReason** -- m_eDenyReason
    * **data.m_rgchOptionalText** -- m_rgchOptionalText

.. function:: GameServer.onGSClientKick

    Callback for `GSClientKick_t <https://partner.steamgames.com/doc/api/ISteamGameServer#GSClientKick_t>`_

    **callback(data)** receives:

    * **data.m_SteamID** -- m_SteamID
    * **data.m_eDenyReason** -- m_eDenyReason

.. function:: GameServer.onGSClientAchievementStatus

    Callback for `GSClientAchievementStatus_t <https://partner.steamgames.com/doc/api/ISteamGameServer#GSClientAchievementStatus_t>`_

    **callback(data)** receives:

    * **data.m_SteamID** -- m_SteamID
    * **data.m_pchAchievement** -- m_pchAchievement
    * **data.m_bUnlocked** -- m_bUnlocked

.. function:: GameServer.onGSPolicyResponse

    Callback for `GSPolicyResponse_t <https://partner.steamgames.com/doc/api/ISteamGameServer#GSPolicyResponse_t>`_

    **callback(data)** receives:

    * **data.m_bSecure** -- m_bSecure

.. function:: GameServer.onGSGameplayStats

    Callback for `GSGameplayStats_t <https://partner.steamgames.com/doc/api/ISteamGameServer#GSGameplayStats_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_nRank** -- m_nRank
    * **data.m_unTotalConnects** -- m_unTotalConnects
    * **data.m_unTotalMinutesPlayed** -- m_unTotalMinutesPlayed

.. function:: GameServer.onGSClientGroupStatus

    Callback for `GSClientGroupStatus_t <https://partner.steamgames.com/doc/api/ISteamGameServer#GSClientGroupStatus_t>`_

    **callback(data)** receives:

    * **data.m_SteamIDUser** -- m_SteamIDUser
    * **data.m_SteamIDGroup** -- m_SteamIDGroup
    * **data.m_bMember** -- m_bMember
    * **data.m_bOfficer** -- m_bOfficer

.. function:: GameServer.onGSReputation

    Callback for `GSReputation_t <https://partner.steamgames.com/doc/api/ISteamGameServer#GSReputation_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_unReputationScore** -- m_unReputationScore
    * **data.m_bBanned** -- m_bBanned
    * **data.m_unBannedIP** -- m_unBannedIP
    * **data.m_usBannedPort** -- m_usBannedPort
    * **data.m_ulBannedGameID** -- m_ulBannedGameID
    * **data.m_unBanExpires** -- m_unBanExpires

.. function:: GameServer.onAssociateWithClanResult

    Callback for `AssociateWithClanResult_t <https://partner.steamgames.com/doc/api/ISteamGameServer#AssociateWithClanResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult

.. function:: GameServer.onComputeNewPlayerCompatibilityResult

    Callback for `ComputeNewPlayerCompatibilityResult_t <https://partner.steamgames.com/doc/api/ISteamGameServer#ComputeNewPlayerCompatibilityResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_cPlayersThatDontLikeCandidate** -- m_cPlayersThatDontLikeCandidate
    * **data.m_cPlayersThatCandidateDoesntLike** -- m_cPlayersThatCandidateDoesntLike
    * **data.m_cClanPlayersThatDontLikeCandidate** -- m_cClanPlayersThatDontLikeCandidate
    * **data.m_SteamIDCandidate** -- m_SteamIDCandidate

