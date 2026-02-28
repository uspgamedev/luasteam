=======
Structs
=======

.. note::
   These structs are auto-generated as Lua userdata objects.
   Create them with the ``Steam.new<StructName>()`` constructor.

.. _struct-SteamIPAddress_t:

----------------
SteamIPAddress_t
----------------

.. function:: Steam.newSteamIPAddress_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamIPAddress_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_rgubIPv6** (str)
    * **m_eType** (int)

.. function:: SteamIPAddress_t:IsSet()

    🤖 **Auto-generated binding**

    :returns: (bool)

.. _struct-FriendGameInfo_t:

----------------
FriendGameInfo_t
----------------

.. function:: Steam.newFriendGameInfo_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (FriendGameInfo_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_gameID** (uint64)
    * **m_unGameIP** (int)
    * **m_usGamePort** (int)
    * **m_usQueryPort** (int)
    * **m_steamIDLobby** (uint64)

.. _struct-MatchMakingKeyValuePair_t:

-------------------------
MatchMakingKeyValuePair_t
-------------------------

.. function:: Steam.newMatchMakingKeyValuePair_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (MatchMakingKeyValuePair_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_szKey** (str)
    * **m_szValue** (str)

.. _struct-servernetadr_t:

--------------
servernetadr_t
--------------

.. function:: Steam.newservernetadr_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (servernetadr_t) New userdata instance.

.. function:: servernetadr_t:Init(ip, usQueryPort, usConnectionPort)

    🤖 **Auto-generated binding**

    :param int ip:
    :param int usQueryPort:
    :param int usConnectionPort:

.. function:: servernetadr_t:GetQueryPort()

    🤖 **Auto-generated binding**

    :returns: (int)

.. function:: servernetadr_t:SetQueryPort(usPort)

    🤖 **Auto-generated binding**

    :param int usPort:

.. function:: servernetadr_t:GetConnectionPort()

    🤖 **Auto-generated binding**

    :returns: (int)

.. function:: servernetadr_t:SetConnectionPort(usPort)

    🤖 **Auto-generated binding**

    :param int usPort:

.. function:: servernetadr_t:GetIP()

    🤖 **Auto-generated binding**

    :returns: (int)

.. function:: servernetadr_t:SetIP(unIP)

    🤖 **Auto-generated binding**

    :param int unIP:

.. function:: servernetadr_t:GetConnectionAddressString()

    🤖 **Auto-generated binding**

    :returns: (str)

.. function:: servernetadr_t:GetQueryAddressString()

    🤖 **Auto-generated binding**

    :returns: (str)

.. _struct-gameserveritem_t:

----------------
gameserveritem_t
----------------

.. function:: Steam.newgameserveritem_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (gameserveritem_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_NetAdr** (:ref:`servernetadr_t <struct-servernetadr_t>`)
    * **m_nPing** (int)
    * **m_bHadSuccessfulResponse** (bool)
    * **m_bDoNotRefresh** (bool)
    * **m_szGameDir** (str)
    * **m_szMap** (str)
    * **m_szGameDescription** (str)
    * **m_nAppID** (int)
    * **m_nPlayers** (int)
    * **m_nMaxPlayers** (int)
    * **m_nBotPlayers** (int)
    * **m_bPassword** (bool)
    * **m_bSecure** (bool)
    * **m_ulTimeLastPlayed** (int)
    * **m_nServerVersion** (int)
    * **m_szGameTags** (str)
    * **m_steamID** (uint64)

.. function:: gameserveritem_t:GetName()

    🤖 **Auto-generated binding**

    :returns: (str)

.. function:: gameserveritem_t:SetName(pName)

    🤖 **Auto-generated binding**

    :param str pName:

.. _struct-SteamPartyBeaconLocation_t:

--------------------------
SteamPartyBeaconLocation_t
--------------------------

.. function:: Steam.newSteamPartyBeaconLocation_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamPartyBeaconLocation_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eType** (int)
    * **m_ulLocationID** (uint64)

.. _struct-SteamParamStringArray_t:

-----------------------
SteamParamStringArray_t
-----------------------

.. function:: Steam.newSteamParamStringArray_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamParamStringArray_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_ppStrings** (str[])

.. _struct-LeaderboardEntry_t:

------------------
LeaderboardEntry_t
------------------

.. function:: Steam.newLeaderboardEntry_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (LeaderboardEntry_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_steamIDUser** (uint64)
    * **m_nGlobalRank** (int)
    * **m_nScore** (int)
    * **m_cDetails** (int)
    * **m_hUGC** (uint64)

.. _struct-P2PSessionState_t:

-----------------
P2PSessionState_t
-----------------

.. function:: Steam.newP2PSessionState_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (P2PSessionState_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_bConnectionActive** (int)
    * **m_bConnecting** (int)
    * **m_eP2PSessionError** (int)
    * **m_bUsingRelay** (int)
    * **m_nBytesQueuedForSend** (int)
    * **m_nPacketsQueuedForSend** (int)
    * **m_nRemoteIP** (int)
    * **m_nRemotePort** (int)

.. _struct-InputAnalogActionData_t:

-----------------------
InputAnalogActionData_t
-----------------------

.. function:: Steam.newInputAnalogActionData_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (InputAnalogActionData_t) New userdata instance.

    **Fields** (readable and writable):

    * **eMode** (int)
    * **x** (float)
    * **y** (float)
    * **bActive** (bool)

.. _struct-InputDigitalActionData_t:

------------------------
InputDigitalActionData_t
------------------------

.. function:: Steam.newInputDigitalActionData_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (InputDigitalActionData_t) New userdata instance.

    **Fields** (readable and writable):

    * **bState** (bool)
    * **bActive** (bool)

.. _struct-InputMotionData_t:

-----------------
InputMotionData_t
-----------------

.. function:: Steam.newInputMotionData_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (InputMotionData_t) New userdata instance.

    **Fields** (readable and writable):

    * **rotQuatX** (float)
    * **rotQuatY** (float)
    * **rotQuatZ** (float)
    * **rotQuatW** (float)
    * **posAccelX** (float)
    * **posAccelY** (float)
    * **posAccelZ** (float)
    * **rotVelX** (float)
    * **rotVelY** (float)
    * **rotVelZ** (float)

.. _struct-SteamInputActionEvent_t:

-----------------------
SteamInputActionEvent_t
-----------------------

.. function:: Steam.newSteamInputActionEvent_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamInputActionEvent_t) New userdata instance.

    **Fields** (readable and writable):

    * **controllerHandle** (uint64)
    * **eEventType** (int)

.. _struct-SteamUGCDetails_t:

-----------------
SteamUGCDetails_t
-----------------

.. function:: Steam.newSteamUGCDetails_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamUGCDetails_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_nPublishedFileId** (uint64)
    * **m_eResult** (int)
    * **m_eFileType** (int)
    * **m_nCreatorAppID** (int)
    * **m_nConsumerAppID** (int)
    * **m_rgchTitle** (str)
    * **m_rgchDescription** (str)
    * **m_ulSteamIDOwner** (uint64)
    * **m_rtimeCreated** (int)
    * **m_rtimeUpdated** (int)
    * **m_rtimeAddedToUserList** (int)
    * **m_eVisibility** (int)
    * **m_bBanned** (bool)
    * **m_bAcceptedForUse** (bool)
    * **m_bTagsTruncated** (bool)
    * **m_rgchTags** (str)
    * **m_hFile** (uint64)
    * **m_hPreviewFile** (uint64)
    * **m_pchFileName** (str)
    * **m_nFileSize** (int)
    * **m_nPreviewFileSize** (int)
    * **m_rgchURL** (str)
    * **m_unVotesUp** (int)
    * **m_unVotesDown** (int)
    * **m_flScore** (float)
    * **m_unNumChildren** (int)
    * **m_ulTotalFilesSize** (uint64)

.. _struct-SteamItemDetails_t:

------------------
SteamItemDetails_t
------------------

.. function:: Steam.newSteamItemDetails_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamItemDetails_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_itemId** (uint64)
    * **m_iDefinition** (int)
    * **m_unQuantity** (int)
    * **m_unFlags** (int)

.. _struct-RemotePlayInputMouseMotion_t:

----------------------------
RemotePlayInputMouseMotion_t
----------------------------

.. function:: Steam.newRemotePlayInputMouseMotion_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemotePlayInputMouseMotion_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_bAbsolute** (bool)
    * **m_flNormalizedX** (float)
    * **m_flNormalizedY** (float)
    * **m_nDeltaX** (int)
    * **m_nDeltaY** (int)

.. _struct-RemotePlayInputMouseWheel_t:

---------------------------
RemotePlayInputMouseWheel_t
---------------------------

.. function:: Steam.newRemotePlayInputMouseWheel_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemotePlayInputMouseWheel_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eDirection** (int)
    * **m_flAmount** (float)

.. _struct-RemotePlayInputKey_t:

--------------------
RemotePlayInputKey_t
--------------------

.. function:: Steam.newRemotePlayInputKey_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemotePlayInputKey_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eScancode** (int)
    * **m_unModifiers** (int)
    * **m_unKeycode** (int)

.. _struct-RemotePlayInput_t:

-----------------
RemotePlayInput_t
-----------------

.. function:: Steam.newRemotePlayInput_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemotePlayInput_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_unSessionID** (int)
    * **m_eType** (int)
    * **padding** (str)

.. _struct-SteamNetworkingIPAddr:

---------------------
SteamNetworkingIPAddr
---------------------

.. function:: Steam.newSteamNetworkingIPAddr([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamNetworkingIPAddr) New userdata instance.

    **Fields** (readable and writable):

    * **m_ipv6** (str)
    * **m_port** (int)

.. function:: SteamNetworkingIPAddr:Clear()

    🤖 **Auto-generated binding**


.. function:: SteamNetworkingIPAddr:IsIPv6AllZeros()

    🤖 **Auto-generated binding**

    :returns: (bool)

.. function:: SteamNetworkingIPAddr:SetIPv6(ipv6, nPort)

    🤖 **Auto-generated binding**

    :param str ipv6:
    :param int nPort:

.. function:: SteamNetworkingIPAddr:SetIPv4(nIP, nPort)

    🤖 **Auto-generated binding**

    :param int nIP:
    :param int nPort:

.. function:: SteamNetworkingIPAddr:IsIPv4()

    🤖 **Auto-generated binding**

    :returns: (bool)

.. function:: SteamNetworkingIPAddr:GetIPv4()

    🤖 **Auto-generated binding**

    :returns: (int)

.. function:: SteamNetworkingIPAddr:SetIPv6LocalHost(nPort)

    🤖 **Auto-generated binding**

    :param int nPort:

.. function:: SteamNetworkingIPAddr:IsLocalHost()

    🤖 **Auto-generated binding**

    :returns: (bool)

.. function:: SteamNetworkingIPAddr:ToString(cbBuf, bWithPort)

    🤖 **Auto-generated binding**

    :param int cbBuf:
    :param bool bWithPort:

.. function:: SteamNetworkingIPAddr:ParseString(pszStr)

    🤖 **Auto-generated binding**

    :param str pszStr:
    :returns: (bool)

.. function:: SteamNetworkingIPAddr:GetFakeIPType()

    🤖 **Auto-generated binding**

    :returns: (int)

.. function:: SteamNetworkingIPAddr:IsFakeIP()

    🤖 **Auto-generated binding**

    :returns: (bool)

.. _struct-SteamNetworkingIdentity:

-----------------------
SteamNetworkingIdentity
-----------------------

.. function:: Steam.newSteamNetworkingIdentity([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamNetworkingIdentity) New userdata instance.

.. function:: SteamNetworkingIdentity:Clear()

    🤖 **Auto-generated binding**


.. function:: SteamNetworkingIdentity:IsInvalid()

    🤖 **Auto-generated binding**

    :returns: (bool)

.. function:: SteamNetworkingIdentity:SetSteamID(steamID)

    🤖 **Auto-generated binding**

    :param uint64 steamID:

.. function:: SteamNetworkingIdentity:GetSteamID()

    🤖 **Auto-generated binding**

    :returns: (uint64)

.. function:: SteamNetworkingIdentity:SetSteamID64(steamID)

    🤖 **Auto-generated binding**

    :param uint64 steamID:

.. function:: SteamNetworkingIdentity:GetSteamID64()

    🤖 **Auto-generated binding**

    :returns: (uint64)

.. function:: SteamNetworkingIdentity:SetXboxPairwiseID(pszString)

    🤖 **Auto-generated binding**

    :param str pszString:
    :returns: (bool)

.. function:: SteamNetworkingIdentity:GetXboxPairwiseID()

    🤖 **Auto-generated binding**

    :returns: (str)

.. function:: SteamNetworkingIdentity:SetPSNID(id)

    🤖 **Auto-generated binding**

    :param uint64 id:

.. function:: SteamNetworkingIdentity:GetPSNID()

    🤖 **Auto-generated binding**

    :returns: (uint64)

.. function:: SteamNetworkingIdentity:SetIPAddr(addr)

    🤖 **Auto-generated binding**

    :param :ref:`SteamNetworkingIPAddr <struct-SteamNetworkingIPAddr>` addr:

.. function:: SteamNetworkingIdentity:GetIPAddr()

    🤖 **Auto-generated binding**

    :returns: (:ref:`SteamNetworkingIPAddr <struct-SteamNetworkingIPAddr>`)

.. function:: SteamNetworkingIdentity:SetIPv4Addr(nIPv4, nPort)

    🤖 **Auto-generated binding**

    :param int nIPv4:
    :param int nPort:

.. function:: SteamNetworkingIdentity:GetIPv4()

    🤖 **Auto-generated binding**

    :returns: (int)

.. function:: SteamNetworkingIdentity:GetFakeIPType()

    🤖 **Auto-generated binding**

    :returns: (int)

.. function:: SteamNetworkingIdentity:IsFakeIP()

    🤖 **Auto-generated binding**

    :returns: (bool)

.. function:: SteamNetworkingIdentity:SetLocalHost()

    🤖 **Auto-generated binding**


.. function:: SteamNetworkingIdentity:IsLocalHost()

    🤖 **Auto-generated binding**

    :returns: (bool)

.. function:: SteamNetworkingIdentity:SetGenericString(pszString)

    🤖 **Auto-generated binding**

    :param str pszString:
    :returns: (bool)

.. function:: SteamNetworkingIdentity:GetGenericString()

    🤖 **Auto-generated binding**

    :returns: (str)

.. function:: SteamNetworkingIdentity:SetGenericBytes(data, cbLen)

    🤖 **Auto-generated binding**

    :param str data:
    :param int cbLen:
    :returns: (bool)

.. function:: SteamNetworkingIdentity:ToString(cbBuf)

    🤖 **Auto-generated binding**

    :param int cbBuf:

.. function:: SteamNetworkingIdentity:ParseString(pszStr)

    🤖 **Auto-generated binding**

    :param str pszStr:
    :returns: (bool)

.. _struct-SteamNetConnectionInfo_t:

------------------------
SteamNetConnectionInfo_t
------------------------

.. function:: Steam.newSteamNetConnectionInfo_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamNetConnectionInfo_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_identityRemote** (:ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>`)
    * **m_nUserData** (uint64)
    * **m_hListenSocket** (int)
    * **m_addrRemote** (:ref:`SteamNetworkingIPAddr <struct-SteamNetworkingIPAddr>`)
    * **m__pad1** (int)
    * **m_idPOPRemote** (int)
    * **m_idPOPRelay** (int)
    * **m_eState** (int)
    * **m_eEndReason** (int)
    * **m_szEndDebug** (str)
    * **m_szConnectionDescription** (str)
    * **m_nFlags** (int)
    * **reserved** (int[])

.. _struct-SteamNetConnectionRealTimeStatus_t:

----------------------------------
SteamNetConnectionRealTimeStatus_t
----------------------------------

.. function:: Steam.newSteamNetConnectionRealTimeStatus_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamNetConnectionRealTimeStatus_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eState** (int)
    * **m_nPing** (int)
    * **m_flConnectionQualityLocal** (float)
    * **m_flConnectionQualityRemote** (float)
    * **m_flOutPacketsPerSec** (float)
    * **m_flOutBytesPerSec** (float)
    * **m_flInPacketsPerSec** (float)
    * **m_flInBytesPerSec** (float)
    * **m_nSendRateBytesPerSecond** (int)
    * **m_cbPendingUnreliable** (int)
    * **m_cbPendingReliable** (int)
    * **m_cbSentUnackedReliable** (int)
    * **reserved** (int[])

.. _struct-SteamNetConnectionRealTimeLaneStatus_t:

--------------------------------------
SteamNetConnectionRealTimeLaneStatus_t
--------------------------------------

.. function:: Steam.newSteamNetConnectionRealTimeLaneStatus_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamNetConnectionRealTimeLaneStatus_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_cbPendingUnreliable** (int)
    * **m_cbPendingReliable** (int)
    * **m_cbSentUnackedReliable** (int)
    * **_reservePad1** (int)
    * **reserved** (int[])

.. _struct-SteamNetworkPingLocation_t:

--------------------------
SteamNetworkPingLocation_t
--------------------------

.. function:: Steam.newSteamNetworkPingLocation_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamNetworkPingLocation_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_data** (str)

.. _struct-SteamNetworkingConfigValue_t:

----------------------------
SteamNetworkingConfigValue_t
----------------------------

.. function:: Steam.newSteamNetworkingConfigValue_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamNetworkingConfigValue_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eValue** (int)
    * **m_eDataType** (int)
    * **m_val.m_int64** (uint64)

.. function:: SteamNetworkingConfigValue_t:SetInt64(eVal, data)

    🤖 **Auto-generated binding**

    :param int eVal:
    :param uint64 data:

.. function:: SteamNetworkingConfigValue_t:SetFloat(eVal, data)

    🤖 **Auto-generated binding**

    :param int eVal:
    :param float data:

.. function:: SteamNetworkingConfigValue_t:SetString(eVal, data)

    🤖 **Auto-generated binding**

    :param int eVal:
    :param str data:

.. _struct-SteamServersConnected_t:

-----------------------
SteamServersConnected_t
-----------------------

.. function:: Steam.newSteamServersConnected_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamServersConnected_t) New userdata instance.

.. _struct-SteamServerConnectFailure_t:

---------------------------
SteamServerConnectFailure_t
---------------------------

.. function:: Steam.newSteamServerConnectFailure_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamServerConnectFailure_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_bStillRetrying** (bool)

.. _struct-SteamServersDisconnected_t:

--------------------------
SteamServersDisconnected_t
--------------------------

.. function:: Steam.newSteamServersDisconnected_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamServersDisconnected_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)

.. _struct-ClientGameServerDeny_t:

----------------------
ClientGameServerDeny_t
----------------------

.. function:: Steam.newClientGameServerDeny_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (ClientGameServerDeny_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_uAppID** (int)
    * **m_unGameServerIP** (int)
    * **m_usGameServerPort** (int)
    * **m_bSecure** (int)
    * **m_uReason** (int)

.. _struct-IPCFailure_t:

------------
IPCFailure_t
------------

.. function:: Steam.newIPCFailure_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (IPCFailure_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eFailureType** (int)

.. _struct-LicensesUpdated_t:

-----------------
LicensesUpdated_t
-----------------

.. function:: Steam.newLicensesUpdated_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (LicensesUpdated_t) New userdata instance.

.. _struct-ValidateAuthTicketResponse_t:

----------------------------
ValidateAuthTicketResponse_t
----------------------------

.. function:: Steam.newValidateAuthTicketResponse_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (ValidateAuthTicketResponse_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_SteamID** (uint64)
    * **m_eAuthSessionResponse** (int)
    * **m_OwnerSteamID** (uint64)

.. _struct-MicroTxnAuthorizationResponse_t:

-------------------------------
MicroTxnAuthorizationResponse_t
-------------------------------

.. function:: Steam.newMicroTxnAuthorizationResponse_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (MicroTxnAuthorizationResponse_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_unAppID** (int)
    * **m_ulOrderID** (uint64)
    * **m_bAuthorized** (int)

.. _struct-EncryptedAppTicketResponse_t:

----------------------------
EncryptedAppTicketResponse_t
----------------------------

.. function:: Steam.newEncryptedAppTicketResponse_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (EncryptedAppTicketResponse_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)

.. _struct-GetAuthSessionTicketResponse_t:

------------------------------
GetAuthSessionTicketResponse_t
------------------------------

.. function:: Steam.newGetAuthSessionTicketResponse_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (GetAuthSessionTicketResponse_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_hAuthTicket** (int)
    * **m_eResult** (int)

.. _struct-GameWebCallback_t:

-----------------
GameWebCallback_t
-----------------

.. function:: Steam.newGameWebCallback_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (GameWebCallback_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_szURL** (str)

.. _struct-StoreAuthURLResponse_t:

----------------------
StoreAuthURLResponse_t
----------------------

.. function:: Steam.newStoreAuthURLResponse_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (StoreAuthURLResponse_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_szURL** (str)

.. _struct-MarketEligibilityResponse_t:

---------------------------
MarketEligibilityResponse_t
---------------------------

.. function:: Steam.newMarketEligibilityResponse_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (MarketEligibilityResponse_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_bAllowed** (bool)
    * **m_eNotAllowedReason** (int)
    * **m_rtAllowedAtTime** (int)
    * **m_cdaySteamGuardRequiredDays** (int)
    * **m_cdayNewDeviceCooldown** (int)

.. _struct-DurationControl_t:

-----------------
DurationControl_t
-----------------

.. function:: Steam.newDurationControl_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (DurationControl_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_appid** (int)
    * **m_bApplicable** (bool)
    * **m_csecsLast5h** (int)
    * **m_progress** (int)
    * **m_notification** (int)
    * **m_csecsToday** (int)
    * **m_csecsRemaining** (int)

.. _struct-GetTicketForWebApiResponse_t:

----------------------------
GetTicketForWebApiResponse_t
----------------------------

.. function:: Steam.newGetTicketForWebApiResponse_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (GetTicketForWebApiResponse_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_hAuthTicket** (int)
    * **m_eResult** (int)
    * **m_cubTicket** (int)
    * **m_rgubTicket** (str)

.. _struct-PersonaStateChange_t:

--------------------
PersonaStateChange_t
--------------------

.. function:: Steam.newPersonaStateChange_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (PersonaStateChange_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_ulSteamID** (uint64)
    * **m_nChangeFlags** (int)

.. _struct-GameOverlayActivated_t:

----------------------
GameOverlayActivated_t
----------------------

.. function:: Steam.newGameOverlayActivated_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (GameOverlayActivated_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_bActive** (int)
    * **m_bUserInitiated** (bool)
    * **m_nAppID** (int)
    * **m_dwOverlayPID** (int)

.. _struct-GameServerChangeRequested_t:

---------------------------
GameServerChangeRequested_t
---------------------------

.. function:: Steam.newGameServerChangeRequested_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (GameServerChangeRequested_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_rgchServer** (str)
    * **m_rgchPassword** (str)

.. _struct-GameLobbyJoinRequested_t:

------------------------
GameLobbyJoinRequested_t
------------------------

.. function:: Steam.newGameLobbyJoinRequested_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (GameLobbyJoinRequested_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_steamIDLobby** (uint64)
    * **m_steamIDFriend** (uint64)

.. _struct-AvatarImageLoaded_t:

-------------------
AvatarImageLoaded_t
-------------------

.. function:: Steam.newAvatarImageLoaded_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (AvatarImageLoaded_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_steamID** (uint64)
    * **m_iImage** (int)
    * **m_iWide** (int)
    * **m_iTall** (int)

.. _struct-ClanOfficerListResponse_t:

-------------------------
ClanOfficerListResponse_t
-------------------------

.. function:: Steam.newClanOfficerListResponse_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (ClanOfficerListResponse_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_steamIDClan** (uint64)
    * **m_cOfficers** (int)
    * **m_bSuccess** (int)

.. _struct-FriendRichPresenceUpdate_t:

--------------------------
FriendRichPresenceUpdate_t
--------------------------

.. function:: Steam.newFriendRichPresenceUpdate_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (FriendRichPresenceUpdate_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_steamIDFriend** (uint64)
    * **m_nAppID** (int)

.. _struct-GameRichPresenceJoinRequested_t:

-------------------------------
GameRichPresenceJoinRequested_t
-------------------------------

.. function:: Steam.newGameRichPresenceJoinRequested_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (GameRichPresenceJoinRequested_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_steamIDFriend** (uint64)
    * **m_rgchConnect** (str)

.. _struct-GameConnectedClanChatMsg_t:

--------------------------
GameConnectedClanChatMsg_t
--------------------------

.. function:: Steam.newGameConnectedClanChatMsg_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (GameConnectedClanChatMsg_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_steamIDClanChat** (uint64)
    * **m_steamIDUser** (uint64)
    * **m_iMessageID** (int)

.. _struct-GameConnectedChatJoin_t:

-----------------------
GameConnectedChatJoin_t
-----------------------

.. function:: Steam.newGameConnectedChatJoin_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (GameConnectedChatJoin_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_steamIDClanChat** (uint64)
    * **m_steamIDUser** (uint64)

.. _struct-GameConnectedChatLeave_t:

------------------------
GameConnectedChatLeave_t
------------------------

.. function:: Steam.newGameConnectedChatLeave_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (GameConnectedChatLeave_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_steamIDClanChat** (uint64)
    * **m_steamIDUser** (uint64)
    * **m_bKicked** (bool)
    * **m_bDropped** (bool)

.. _struct-DownloadClanActivityCountsResult_t:

----------------------------------
DownloadClanActivityCountsResult_t
----------------------------------

.. function:: Steam.newDownloadClanActivityCountsResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (DownloadClanActivityCountsResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_bSuccess** (bool)

.. _struct-JoinClanChatRoomCompletionResult_t:

----------------------------------
JoinClanChatRoomCompletionResult_t
----------------------------------

.. function:: Steam.newJoinClanChatRoomCompletionResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (JoinClanChatRoomCompletionResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_steamIDClanChat** (uint64)
    * **m_eChatRoomEnterResponse** (int)

.. _struct-GameConnectedFriendChatMsg_t:

----------------------------
GameConnectedFriendChatMsg_t
----------------------------

.. function:: Steam.newGameConnectedFriendChatMsg_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (GameConnectedFriendChatMsg_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_steamIDUser** (uint64)
    * **m_iMessageID** (int)

.. _struct-FriendsGetFollowerCount_t:

-------------------------
FriendsGetFollowerCount_t
-------------------------

.. function:: Steam.newFriendsGetFollowerCount_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (FriendsGetFollowerCount_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_steamID** (uint64)
    * **m_nCount** (int)

.. _struct-FriendsIsFollowing_t:

--------------------
FriendsIsFollowing_t
--------------------

.. function:: Steam.newFriendsIsFollowing_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (FriendsIsFollowing_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_steamID** (uint64)
    * **m_bIsFollowing** (bool)

.. _struct-FriendsEnumerateFollowingList_t:

-------------------------------
FriendsEnumerateFollowingList_t
-------------------------------

.. function:: Steam.newFriendsEnumerateFollowingList_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (FriendsEnumerateFollowingList_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_rgSteamID** (uint64[])
    * **m_nResultsReturned** (int)
    * **m_nTotalResultCount** (int)

.. _struct-UnreadChatMessagesChanged_t:

---------------------------
UnreadChatMessagesChanged_t
---------------------------

.. function:: Steam.newUnreadChatMessagesChanged_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (UnreadChatMessagesChanged_t) New userdata instance.

.. _struct-OverlayBrowserProtocolNavigation_t:

----------------------------------
OverlayBrowserProtocolNavigation_t
----------------------------------

.. function:: Steam.newOverlayBrowserProtocolNavigation_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (OverlayBrowserProtocolNavigation_t) New userdata instance.

    **Fields** (readable and writable):

    * **rgchURI** (str)

.. _struct-EquippedProfileItemsChanged_t:

-----------------------------
EquippedProfileItemsChanged_t
-----------------------------

.. function:: Steam.newEquippedProfileItemsChanged_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (EquippedProfileItemsChanged_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_steamID** (uint64)

.. _struct-EquippedProfileItems_t:

----------------------
EquippedProfileItems_t
----------------------

.. function:: Steam.newEquippedProfileItems_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (EquippedProfileItems_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_steamID** (uint64)
    * **m_bHasAnimatedAvatar** (bool)
    * **m_bHasAvatarFrame** (bool)
    * **m_bHasProfileModifier** (bool)
    * **m_bHasProfileBackground** (bool)
    * **m_bHasMiniProfileBackground** (bool)
    * **m_bFromCache** (bool)

.. _struct-IPCountry_t:

-----------
IPCountry_t
-----------

.. function:: Steam.newIPCountry_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (IPCountry_t) New userdata instance.

.. _struct-LowBatteryPower_t:

-----------------
LowBatteryPower_t
-----------------

.. function:: Steam.newLowBatteryPower_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (LowBatteryPower_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_nMinutesBatteryLeft** (int)

.. _struct-SteamAPICallCompleted_t:

-----------------------
SteamAPICallCompleted_t
-----------------------

.. function:: Steam.newSteamAPICallCompleted_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamAPICallCompleted_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_hAsyncCall** (uint64)
    * **m_iCallback** (int)
    * **m_cubParam** (int)

.. _struct-SteamShutdown_t:

---------------
SteamShutdown_t
---------------

.. function:: Steam.newSteamShutdown_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamShutdown_t) New userdata instance.

.. _struct-CheckFileSignature_t:

--------------------
CheckFileSignature_t
--------------------

.. function:: Steam.newCheckFileSignature_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (CheckFileSignature_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eCheckFileSignature** (int)

.. _struct-GamepadTextInputDismissed_t:

---------------------------
GamepadTextInputDismissed_t
---------------------------

.. function:: Steam.newGamepadTextInputDismissed_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (GamepadTextInputDismissed_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_bSubmitted** (bool)
    * **m_unSubmittedText** (int)
    * **m_unAppID** (int)

.. _struct-AppResumingFromSuspend_t:

------------------------
AppResumingFromSuspend_t
------------------------

.. function:: Steam.newAppResumingFromSuspend_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (AppResumingFromSuspend_t) New userdata instance.

.. _struct-FloatingGamepadTextInputDismissed_t:

-----------------------------------
FloatingGamepadTextInputDismissed_t
-----------------------------------

.. function:: Steam.newFloatingGamepadTextInputDismissed_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (FloatingGamepadTextInputDismissed_t) New userdata instance.

.. _struct-FilterTextDictionaryChanged_t:

-----------------------------
FilterTextDictionaryChanged_t
-----------------------------

.. function:: Steam.newFilterTextDictionaryChanged_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (FilterTextDictionaryChanged_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eLanguage** (int)

.. _struct-FavoritesListChanged_t:

----------------------
FavoritesListChanged_t
----------------------

.. function:: Steam.newFavoritesListChanged_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (FavoritesListChanged_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_nIP** (int)
    * **m_nQueryPort** (int)
    * **m_nConnPort** (int)
    * **m_nAppID** (int)
    * **m_nFlags** (int)
    * **m_bAdd** (bool)
    * **m_unAccountId** (int)

.. _struct-LobbyInvite_t:

-------------
LobbyInvite_t
-------------

.. function:: Steam.newLobbyInvite_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (LobbyInvite_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_ulSteamIDUser** (uint64)
    * **m_ulSteamIDLobby** (uint64)
    * **m_ulGameID** (uint64)

.. _struct-LobbyEnter_t:

------------
LobbyEnter_t
------------

.. function:: Steam.newLobbyEnter_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (LobbyEnter_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_ulSteamIDLobby** (uint64)
    * **m_rgfChatPermissions** (int)
    * **m_bLocked** (bool)
    * **m_EChatRoomEnterResponse** (int)

.. _struct-LobbyDataUpdate_t:

-----------------
LobbyDataUpdate_t
-----------------

.. function:: Steam.newLobbyDataUpdate_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (LobbyDataUpdate_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_ulSteamIDLobby** (uint64)
    * **m_ulSteamIDMember** (uint64)
    * **m_bSuccess** (int)

.. _struct-LobbyChatUpdate_t:

-----------------
LobbyChatUpdate_t
-----------------

.. function:: Steam.newLobbyChatUpdate_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (LobbyChatUpdate_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_ulSteamIDLobby** (uint64)
    * **m_ulSteamIDUserChanged** (uint64)
    * **m_ulSteamIDMakingChange** (uint64)
    * **m_rgfChatMemberStateChange** (int)

.. _struct-LobbyChatMsg_t:

--------------
LobbyChatMsg_t
--------------

.. function:: Steam.newLobbyChatMsg_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (LobbyChatMsg_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_ulSteamIDLobby** (uint64)
    * **m_ulSteamIDUser** (uint64)
    * **m_eChatEntryType** (int)
    * **m_iChatID** (int)

.. _struct-LobbyGameCreated_t:

------------------
LobbyGameCreated_t
------------------

.. function:: Steam.newLobbyGameCreated_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (LobbyGameCreated_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_ulSteamIDLobby** (uint64)
    * **m_ulSteamIDGameServer** (uint64)
    * **m_unIP** (int)
    * **m_usPort** (int)

.. _struct-LobbyMatchList_t:

----------------
LobbyMatchList_t
----------------

.. function:: Steam.newLobbyMatchList_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (LobbyMatchList_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_nLobbiesMatching** (int)

.. _struct-LobbyKicked_t:

-------------
LobbyKicked_t
-------------

.. function:: Steam.newLobbyKicked_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (LobbyKicked_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_ulSteamIDLobby** (uint64)
    * **m_ulSteamIDAdmin** (uint64)
    * **m_bKickedDueToDisconnect** (int)

.. _struct-LobbyCreated_t:

--------------
LobbyCreated_t
--------------

.. function:: Steam.newLobbyCreated_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (LobbyCreated_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_ulSteamIDLobby** (uint64)

.. _struct-FavoritesListAccountsUpdated_t:

------------------------------
FavoritesListAccountsUpdated_t
------------------------------

.. function:: Steam.newFavoritesListAccountsUpdated_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (FavoritesListAccountsUpdated_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)

.. _struct-JoinPartyCallback_t:

-------------------
JoinPartyCallback_t
-------------------

.. function:: Steam.newJoinPartyCallback_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (JoinPartyCallback_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_ulBeaconID** (uint64)
    * **m_SteamIDBeaconOwner** (uint64)
    * **m_rgchConnectString** (str)

.. _struct-CreateBeaconCallback_t:

----------------------
CreateBeaconCallback_t
----------------------

.. function:: Steam.newCreateBeaconCallback_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (CreateBeaconCallback_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_ulBeaconID** (uint64)

.. _struct-ReservationNotificationCallback_t:

---------------------------------
ReservationNotificationCallback_t
---------------------------------

.. function:: Steam.newReservationNotificationCallback_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (ReservationNotificationCallback_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_ulBeaconID** (uint64)
    * **m_steamIDJoiner** (uint64)

.. _struct-ChangeNumOpenSlotsCallback_t:

----------------------------
ChangeNumOpenSlotsCallback_t
----------------------------

.. function:: Steam.newChangeNumOpenSlotsCallback_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (ChangeNumOpenSlotsCallback_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)

.. _struct-AvailableBeaconLocationsUpdated_t:

---------------------------------
AvailableBeaconLocationsUpdated_t
---------------------------------

.. function:: Steam.newAvailableBeaconLocationsUpdated_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (AvailableBeaconLocationsUpdated_t) New userdata instance.

.. _struct-ActiveBeaconsUpdated_t:

----------------------
ActiveBeaconsUpdated_t
----------------------

.. function:: Steam.newActiveBeaconsUpdated_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (ActiveBeaconsUpdated_t) New userdata instance.

.. _struct-RemoteStorageFileShareResult_t:

------------------------------
RemoteStorageFileShareResult_t
------------------------------

.. function:: Steam.newRemoteStorageFileShareResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemoteStorageFileShareResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_hFile** (uint64)
    * **m_rgchFilename** (str)

.. _struct-RemoteStoragePublishFileResult_t:

--------------------------------
RemoteStoragePublishFileResult_t
--------------------------------

.. function:: Steam.newRemoteStoragePublishFileResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemoteStoragePublishFileResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_nPublishedFileId** (uint64)
    * **m_bUserNeedsToAcceptWorkshopLegalAgreement** (bool)

.. _struct-RemoteStorageDeletePublishedFileResult_t:

----------------------------------------
RemoteStorageDeletePublishedFileResult_t
----------------------------------------

.. function:: Steam.newRemoteStorageDeletePublishedFileResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemoteStorageDeletePublishedFileResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_nPublishedFileId** (uint64)

.. _struct-RemoteStorageEnumerateUserPublishedFilesResult_t:

------------------------------------------------
RemoteStorageEnumerateUserPublishedFilesResult_t
------------------------------------------------

.. function:: Steam.newRemoteStorageEnumerateUserPublishedFilesResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemoteStorageEnumerateUserPublishedFilesResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_nResultsReturned** (int)
    * **m_nTotalResultCount** (int)
    * **m_rgPublishedFileId** (uint64[])

.. _struct-RemoteStorageSubscribePublishedFileResult_t:

-------------------------------------------
RemoteStorageSubscribePublishedFileResult_t
-------------------------------------------

.. function:: Steam.newRemoteStorageSubscribePublishedFileResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemoteStorageSubscribePublishedFileResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_nPublishedFileId** (uint64)

.. _struct-RemoteStorageEnumerateUserSubscribedFilesResult_t:

-------------------------------------------------
RemoteStorageEnumerateUserSubscribedFilesResult_t
-------------------------------------------------

.. function:: Steam.newRemoteStorageEnumerateUserSubscribedFilesResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemoteStorageEnumerateUserSubscribedFilesResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_nResultsReturned** (int)
    * **m_nTotalResultCount** (int)
    * **m_rgPublishedFileId** (uint64[])
    * **m_rgRTimeSubscribed** (int[])

.. _struct-RemoteStorageUnsubscribePublishedFileResult_t:

---------------------------------------------
RemoteStorageUnsubscribePublishedFileResult_t
---------------------------------------------

.. function:: Steam.newRemoteStorageUnsubscribePublishedFileResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemoteStorageUnsubscribePublishedFileResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_nPublishedFileId** (uint64)

.. _struct-RemoteStorageUpdatePublishedFileResult_t:

----------------------------------------
RemoteStorageUpdatePublishedFileResult_t
----------------------------------------

.. function:: Steam.newRemoteStorageUpdatePublishedFileResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemoteStorageUpdatePublishedFileResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_nPublishedFileId** (uint64)
    * **m_bUserNeedsToAcceptWorkshopLegalAgreement** (bool)

.. _struct-RemoteStorageDownloadUGCResult_t:

--------------------------------
RemoteStorageDownloadUGCResult_t
--------------------------------

.. function:: Steam.newRemoteStorageDownloadUGCResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemoteStorageDownloadUGCResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_hFile** (uint64)
    * **m_nAppID** (int)
    * **m_nSizeInBytes** (int)
    * **m_pchFileName** (str)
    * **m_ulSteamIDOwner** (uint64)

.. _struct-RemoteStorageGetPublishedFileDetailsResult_t:

--------------------------------------------
RemoteStorageGetPublishedFileDetailsResult_t
--------------------------------------------

.. function:: Steam.newRemoteStorageGetPublishedFileDetailsResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemoteStorageGetPublishedFileDetailsResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_nPublishedFileId** (uint64)
    * **m_nCreatorAppID** (int)
    * **m_nConsumerAppID** (int)
    * **m_rgchTitle** (str)
    * **m_rgchDescription** (str)
    * **m_hFile** (uint64)
    * **m_hPreviewFile** (uint64)
    * **m_ulSteamIDOwner** (uint64)
    * **m_rtimeCreated** (int)
    * **m_rtimeUpdated** (int)
    * **m_eVisibility** (int)
    * **m_bBanned** (bool)
    * **m_rgchTags** (str)
    * **m_bTagsTruncated** (bool)
    * **m_pchFileName** (str)
    * **m_nFileSize** (int)
    * **m_nPreviewFileSize** (int)
    * **m_rgchURL** (str)
    * **m_eFileType** (int)
    * **m_bAcceptedForUse** (bool)

.. _struct-RemoteStorageEnumerateWorkshopFilesResult_t:

-------------------------------------------
RemoteStorageEnumerateWorkshopFilesResult_t
-------------------------------------------

.. function:: Steam.newRemoteStorageEnumerateWorkshopFilesResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemoteStorageEnumerateWorkshopFilesResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_nResultsReturned** (int)
    * **m_nTotalResultCount** (int)
    * **m_rgPublishedFileId** (uint64[])
    * **m_rgScore** (float[])
    * **m_nAppId** (int)
    * **m_unStartIndex** (int)

.. _struct-RemoteStorageGetPublishedItemVoteDetailsResult_t:

------------------------------------------------
RemoteStorageGetPublishedItemVoteDetailsResult_t
------------------------------------------------

.. function:: Steam.newRemoteStorageGetPublishedItemVoteDetailsResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemoteStorageGetPublishedItemVoteDetailsResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_unPublishedFileId** (uint64)
    * **m_nVotesFor** (int)
    * **m_nVotesAgainst** (int)
    * **m_nReports** (int)
    * **m_fScore** (float)

.. _struct-RemoteStoragePublishedFileSubscribed_t:

--------------------------------------
RemoteStoragePublishedFileSubscribed_t
--------------------------------------

.. function:: Steam.newRemoteStoragePublishedFileSubscribed_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemoteStoragePublishedFileSubscribed_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_nPublishedFileId** (uint64)
    * **m_nAppID** (int)

.. _struct-RemoteStoragePublishedFileUnsubscribed_t:

----------------------------------------
RemoteStoragePublishedFileUnsubscribed_t
----------------------------------------

.. function:: Steam.newRemoteStoragePublishedFileUnsubscribed_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemoteStoragePublishedFileUnsubscribed_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_nPublishedFileId** (uint64)
    * **m_nAppID** (int)

.. _struct-RemoteStoragePublishedFileDeleted_t:

-----------------------------------
RemoteStoragePublishedFileDeleted_t
-----------------------------------

.. function:: Steam.newRemoteStoragePublishedFileDeleted_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemoteStoragePublishedFileDeleted_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_nPublishedFileId** (uint64)
    * **m_nAppID** (int)

.. _struct-RemoteStorageUpdateUserPublishedItemVoteResult_t:

------------------------------------------------
RemoteStorageUpdateUserPublishedItemVoteResult_t
------------------------------------------------

.. function:: Steam.newRemoteStorageUpdateUserPublishedItemVoteResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemoteStorageUpdateUserPublishedItemVoteResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_nPublishedFileId** (uint64)

.. _struct-RemoteStorageUserVoteDetails_t:

------------------------------
RemoteStorageUserVoteDetails_t
------------------------------

.. function:: Steam.newRemoteStorageUserVoteDetails_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemoteStorageUserVoteDetails_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_nPublishedFileId** (uint64)
    * **m_eVote** (int)

.. _struct-RemoteStorageEnumerateUserSharedWorkshopFilesResult_t:

-----------------------------------------------------
RemoteStorageEnumerateUserSharedWorkshopFilesResult_t
-----------------------------------------------------

.. function:: Steam.newRemoteStorageEnumerateUserSharedWorkshopFilesResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemoteStorageEnumerateUserSharedWorkshopFilesResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_nResultsReturned** (int)
    * **m_nTotalResultCount** (int)
    * **m_rgPublishedFileId** (uint64[])

.. _struct-RemoteStorageSetUserPublishedFileActionResult_t:

-----------------------------------------------
RemoteStorageSetUserPublishedFileActionResult_t
-----------------------------------------------

.. function:: Steam.newRemoteStorageSetUserPublishedFileActionResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemoteStorageSetUserPublishedFileActionResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_nPublishedFileId** (uint64)
    * **m_eAction** (int)

.. _struct-RemoteStorageEnumeratePublishedFilesByUserActionResult_t:

--------------------------------------------------------
RemoteStorageEnumeratePublishedFilesByUserActionResult_t
--------------------------------------------------------

.. function:: Steam.newRemoteStorageEnumeratePublishedFilesByUserActionResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemoteStorageEnumeratePublishedFilesByUserActionResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_eAction** (int)
    * **m_nResultsReturned** (int)
    * **m_nTotalResultCount** (int)
    * **m_rgPublishedFileId** (uint64[])
    * **m_rgRTimeUpdated** (int[])

.. _struct-RemoteStoragePublishFileProgress_t:

----------------------------------
RemoteStoragePublishFileProgress_t
----------------------------------

.. function:: Steam.newRemoteStoragePublishFileProgress_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemoteStoragePublishFileProgress_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_dPercentFile** (float)
    * **m_bPreview** (bool)

.. _struct-RemoteStoragePublishedFileUpdated_t:

-----------------------------------
RemoteStoragePublishedFileUpdated_t
-----------------------------------

.. function:: Steam.newRemoteStoragePublishedFileUpdated_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemoteStoragePublishedFileUpdated_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_nPublishedFileId** (uint64)
    * **m_nAppID** (int)
    * **m_ulUnused** (uint64)

.. _struct-RemoteStorageFileWriteAsyncComplete_t:

-------------------------------------
RemoteStorageFileWriteAsyncComplete_t
-------------------------------------

.. function:: Steam.newRemoteStorageFileWriteAsyncComplete_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemoteStorageFileWriteAsyncComplete_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)

.. _struct-RemoteStorageFileReadAsyncComplete_t:

------------------------------------
RemoteStorageFileReadAsyncComplete_t
------------------------------------

.. function:: Steam.newRemoteStorageFileReadAsyncComplete_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemoteStorageFileReadAsyncComplete_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_hFileReadAsync** (uint64)
    * **m_eResult** (int)
    * **m_nOffset** (int)
    * **m_cubRead** (int)

.. _struct-RemoteStorageLocalFileChange_t:

------------------------------
RemoteStorageLocalFileChange_t
------------------------------

.. function:: Steam.newRemoteStorageLocalFileChange_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemoteStorageLocalFileChange_t) New userdata instance.

.. _struct-UserStatsReceived_t:

-------------------
UserStatsReceived_t
-------------------

.. function:: Steam.newUserStatsReceived_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (UserStatsReceived_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_nGameID** (uint64)
    * **m_eResult** (int)
    * **m_steamIDUser** (uint64)

.. _struct-UserStatsStored_t:

-----------------
UserStatsStored_t
-----------------

.. function:: Steam.newUserStatsStored_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (UserStatsStored_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_nGameID** (uint64)
    * **m_eResult** (int)

.. _struct-UserAchievementStored_t:

-----------------------
UserAchievementStored_t
-----------------------

.. function:: Steam.newUserAchievementStored_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (UserAchievementStored_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_nGameID** (uint64)
    * **m_bGroupAchievement** (bool)
    * **m_rgchAchievementName** (str)
    * **m_nCurProgress** (int)
    * **m_nMaxProgress** (int)

.. _struct-LeaderboardFindResult_t:

-----------------------
LeaderboardFindResult_t
-----------------------

.. function:: Steam.newLeaderboardFindResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (LeaderboardFindResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_hSteamLeaderboard** (uint64)
    * **m_bLeaderboardFound** (int)

.. _struct-LeaderboardScoresDownloaded_t:

-----------------------------
LeaderboardScoresDownloaded_t
-----------------------------

.. function:: Steam.newLeaderboardScoresDownloaded_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (LeaderboardScoresDownloaded_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_hSteamLeaderboard** (uint64)
    * **m_hSteamLeaderboardEntries** (uint64)
    * **m_cEntryCount** (int)

.. _struct-LeaderboardScoreUploaded_t:

--------------------------
LeaderboardScoreUploaded_t
--------------------------

.. function:: Steam.newLeaderboardScoreUploaded_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (LeaderboardScoreUploaded_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_bSuccess** (int)
    * **m_hSteamLeaderboard** (uint64)
    * **m_nScore** (int)
    * **m_bScoreChanged** (int)
    * **m_nGlobalRankNew** (int)
    * **m_nGlobalRankPrevious** (int)

.. _struct-NumberOfCurrentPlayers_t:

------------------------
NumberOfCurrentPlayers_t
------------------------

.. function:: Steam.newNumberOfCurrentPlayers_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (NumberOfCurrentPlayers_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_bSuccess** (int)
    * **m_cPlayers** (int)

.. _struct-UserStatsUnloaded_t:

-------------------
UserStatsUnloaded_t
-------------------

.. function:: Steam.newUserStatsUnloaded_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (UserStatsUnloaded_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_steamIDUser** (uint64)

.. _struct-UserAchievementIconFetched_t:

----------------------------
UserAchievementIconFetched_t
----------------------------

.. function:: Steam.newUserAchievementIconFetched_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (UserAchievementIconFetched_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_nGameID** (uint64)
    * **m_rgchAchievementName** (str)
    * **m_bAchieved** (bool)
    * **m_nIconHandle** (int)

.. _struct-GlobalAchievementPercentagesReady_t:

-----------------------------------
GlobalAchievementPercentagesReady_t
-----------------------------------

.. function:: Steam.newGlobalAchievementPercentagesReady_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (GlobalAchievementPercentagesReady_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_nGameID** (uint64)
    * **m_eResult** (int)

.. _struct-LeaderboardUGCSet_t:

-------------------
LeaderboardUGCSet_t
-------------------

.. function:: Steam.newLeaderboardUGCSet_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (LeaderboardUGCSet_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_hSteamLeaderboard** (uint64)

.. _struct-GlobalStatsReceived_t:

---------------------
GlobalStatsReceived_t
---------------------

.. function:: Steam.newGlobalStatsReceived_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (GlobalStatsReceived_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_nGameID** (uint64)
    * **m_eResult** (int)

.. _struct-DlcInstalled_t:

--------------
DlcInstalled_t
--------------

.. function:: Steam.newDlcInstalled_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (DlcInstalled_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_nAppID** (int)

.. _struct-NewUrlLaunchParameters_t:

------------------------
NewUrlLaunchParameters_t
------------------------

.. function:: Steam.newNewUrlLaunchParameters_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (NewUrlLaunchParameters_t) New userdata instance.

.. _struct-AppProofOfPurchaseKeyResponse_t:

-------------------------------
AppProofOfPurchaseKeyResponse_t
-------------------------------

.. function:: Steam.newAppProofOfPurchaseKeyResponse_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (AppProofOfPurchaseKeyResponse_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_nAppID** (int)
    * **m_cchKeyLength** (int)
    * **m_rgchKey** (str)

.. _struct-FileDetailsResult_t:

-------------------
FileDetailsResult_t
-------------------

.. function:: Steam.newFileDetailsResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (FileDetailsResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_ulFileSize** (uint64)
    * **m_FileSHA** (str)
    * **m_unFlags** (int)

.. _struct-TimedTrialStatus_t:

------------------
TimedTrialStatus_t
------------------

.. function:: Steam.newTimedTrialStatus_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (TimedTrialStatus_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_unAppID** (int)
    * **m_bIsOffline** (bool)
    * **m_unSecondsAllowed** (int)
    * **m_unSecondsPlayed** (int)

.. _struct-P2PSessionRequest_t:

-------------------
P2PSessionRequest_t
-------------------

.. function:: Steam.newP2PSessionRequest_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (P2PSessionRequest_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_steamIDRemote** (uint64)

.. _struct-P2PSessionConnectFail_t:

-----------------------
P2PSessionConnectFail_t
-----------------------

.. function:: Steam.newP2PSessionConnectFail_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (P2PSessionConnectFail_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_steamIDRemote** (uint64)
    * **m_eP2PSessionError** (int)

.. _struct-SocketStatusCallback_t:

----------------------
SocketStatusCallback_t
----------------------

.. function:: Steam.newSocketStatusCallback_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SocketStatusCallback_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_hSocket** (int)
    * **m_hListenSocket** (int)
    * **m_steamIDRemote** (uint64)
    * **m_eSNetSocketState** (int)

.. _struct-ScreenshotReady_t:

-----------------
ScreenshotReady_t
-----------------

.. function:: Steam.newScreenshotReady_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (ScreenshotReady_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_hLocal** (int)
    * **m_eResult** (int)

.. _struct-ScreenshotRequested_t:

---------------------
ScreenshotRequested_t
---------------------

.. function:: Steam.newScreenshotRequested_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (ScreenshotRequested_t) New userdata instance.

.. _struct-PlaybackStatusHasChanged_t:

--------------------------
PlaybackStatusHasChanged_t
--------------------------

.. function:: Steam.newPlaybackStatusHasChanged_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (PlaybackStatusHasChanged_t) New userdata instance.

.. _struct-VolumeHasChanged_t:

------------------
VolumeHasChanged_t
------------------

.. function:: Steam.newVolumeHasChanged_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (VolumeHasChanged_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_flNewVolume** (float)

.. _struct-HTTPRequestCompleted_t:

----------------------
HTTPRequestCompleted_t
----------------------

.. function:: Steam.newHTTPRequestCompleted_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (HTTPRequestCompleted_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_hRequest** (int)
    * **m_ulContextValue** (uint64)
    * **m_bRequestSuccessful** (bool)
    * **m_eStatusCode** (int)
    * **m_unBodySize** (int)

.. _struct-HTTPRequestHeadersReceived_t:

----------------------------
HTTPRequestHeadersReceived_t
----------------------------

.. function:: Steam.newHTTPRequestHeadersReceived_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (HTTPRequestHeadersReceived_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_hRequest** (int)
    * **m_ulContextValue** (uint64)

.. _struct-HTTPRequestDataReceived_t:

-------------------------
HTTPRequestDataReceived_t
-------------------------

.. function:: Steam.newHTTPRequestDataReceived_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (HTTPRequestDataReceived_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_hRequest** (int)
    * **m_ulContextValue** (uint64)
    * **m_cOffset** (int)
    * **m_cBytesReceived** (int)

.. _struct-SteamInputDeviceConnected_t:

---------------------------
SteamInputDeviceConnected_t
---------------------------

.. function:: Steam.newSteamInputDeviceConnected_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamInputDeviceConnected_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_ulConnectedDeviceHandle** (uint64)

.. _struct-SteamInputDeviceDisconnected_t:

------------------------------
SteamInputDeviceDisconnected_t
------------------------------

.. function:: Steam.newSteamInputDeviceDisconnected_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamInputDeviceDisconnected_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_ulDisconnectedDeviceHandle** (uint64)

.. _struct-SteamInputConfigurationLoaded_t:

-------------------------------
SteamInputConfigurationLoaded_t
-------------------------------

.. function:: Steam.newSteamInputConfigurationLoaded_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamInputConfigurationLoaded_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_unAppID** (int)
    * **m_ulDeviceHandle** (uint64)
    * **m_ulMappingCreator** (uint64)
    * **m_unMajorRevision** (int)
    * **m_unMinorRevision** (int)
    * **m_bUsesSteamInputAPI** (bool)
    * **m_bUsesGamepadAPI** (bool)

.. _struct-SteamInputGamepadSlotChange_t:

-----------------------------
SteamInputGamepadSlotChange_t
-----------------------------

.. function:: Steam.newSteamInputGamepadSlotChange_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamInputGamepadSlotChange_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_unAppID** (int)
    * **m_ulDeviceHandle** (uint64)
    * **m_eDeviceType** (int)
    * **m_nOldGamepadSlot** (int)
    * **m_nNewGamepadSlot** (int)

.. _struct-SteamUGCQueryCompleted_t:

------------------------
SteamUGCQueryCompleted_t
------------------------

.. function:: Steam.newSteamUGCQueryCompleted_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamUGCQueryCompleted_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_handle** (uint64)
    * **m_eResult** (int)
    * **m_unNumResultsReturned** (int)
    * **m_unTotalMatchingResults** (int)
    * **m_bCachedData** (bool)
    * **m_rgchNextCursor** (str)

.. _struct-SteamUGCRequestUGCDetailsResult_t:

---------------------------------
SteamUGCRequestUGCDetailsResult_t
---------------------------------

.. function:: Steam.newSteamUGCRequestUGCDetailsResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamUGCRequestUGCDetailsResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_details** (:ref:`SteamUGCDetails_t <struct-SteamUGCDetails_t>`)
    * **m_bCachedData** (bool)

.. _struct-CreateItemResult_t:

------------------
CreateItemResult_t
------------------

.. function:: Steam.newCreateItemResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (CreateItemResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_nPublishedFileId** (uint64)
    * **m_bUserNeedsToAcceptWorkshopLegalAgreement** (bool)

.. _struct-SubmitItemUpdateResult_t:

------------------------
SubmitItemUpdateResult_t
------------------------

.. function:: Steam.newSubmitItemUpdateResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SubmitItemUpdateResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_bUserNeedsToAcceptWorkshopLegalAgreement** (bool)
    * **m_nPublishedFileId** (uint64)

.. _struct-ItemInstalled_t:

---------------
ItemInstalled_t
---------------

.. function:: Steam.newItemInstalled_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (ItemInstalled_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_unAppID** (int)
    * **m_nPublishedFileId** (uint64)
    * **m_hLegacyContent** (uint64)
    * **m_unManifestID** (uint64)

.. _struct-DownloadItemResult_t:

--------------------
DownloadItemResult_t
--------------------

.. function:: Steam.newDownloadItemResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (DownloadItemResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_unAppID** (int)
    * **m_nPublishedFileId** (uint64)
    * **m_eResult** (int)

.. _struct-UserFavoriteItemsListChanged_t:

------------------------------
UserFavoriteItemsListChanged_t
------------------------------

.. function:: Steam.newUserFavoriteItemsListChanged_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (UserFavoriteItemsListChanged_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_nPublishedFileId** (uint64)
    * **m_eResult** (int)
    * **m_bWasAddRequest** (bool)

.. _struct-SetUserItemVoteResult_t:

-----------------------
SetUserItemVoteResult_t
-----------------------

.. function:: Steam.newSetUserItemVoteResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SetUserItemVoteResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_nPublishedFileId** (uint64)
    * **m_eResult** (int)
    * **m_bVoteUp** (bool)

.. _struct-GetUserItemVoteResult_t:

-----------------------
GetUserItemVoteResult_t
-----------------------

.. function:: Steam.newGetUserItemVoteResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (GetUserItemVoteResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_nPublishedFileId** (uint64)
    * **m_eResult** (int)
    * **m_bVotedUp** (bool)
    * **m_bVotedDown** (bool)
    * **m_bVoteSkipped** (bool)

.. _struct-StartPlaytimeTrackingResult_t:

-----------------------------
StartPlaytimeTrackingResult_t
-----------------------------

.. function:: Steam.newStartPlaytimeTrackingResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (StartPlaytimeTrackingResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)

.. _struct-StopPlaytimeTrackingResult_t:

----------------------------
StopPlaytimeTrackingResult_t
----------------------------

.. function:: Steam.newStopPlaytimeTrackingResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (StopPlaytimeTrackingResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)

.. _struct-AddUGCDependencyResult_t:

------------------------
AddUGCDependencyResult_t
------------------------

.. function:: Steam.newAddUGCDependencyResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (AddUGCDependencyResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_nPublishedFileId** (uint64)
    * **m_nChildPublishedFileId** (uint64)

.. _struct-RemoveUGCDependencyResult_t:

---------------------------
RemoveUGCDependencyResult_t
---------------------------

.. function:: Steam.newRemoveUGCDependencyResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemoveUGCDependencyResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_nPublishedFileId** (uint64)
    * **m_nChildPublishedFileId** (uint64)

.. _struct-AddAppDependencyResult_t:

------------------------
AddAppDependencyResult_t
------------------------

.. function:: Steam.newAddAppDependencyResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (AddAppDependencyResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_nPublishedFileId** (uint64)
    * **m_nAppID** (int)

.. _struct-RemoveAppDependencyResult_t:

---------------------------
RemoveAppDependencyResult_t
---------------------------

.. function:: Steam.newRemoveAppDependencyResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (RemoveAppDependencyResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_nPublishedFileId** (uint64)
    * **m_nAppID** (int)

.. _struct-GetAppDependenciesResult_t:

--------------------------
GetAppDependenciesResult_t
--------------------------

.. function:: Steam.newGetAppDependenciesResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (GetAppDependenciesResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_nPublishedFileId** (uint64)
    * **m_rgAppIDs** (int[])
    * **m_nNumAppDependencies** (int)
    * **m_nTotalNumAppDependencies** (int)

.. _struct-DeleteItemResult_t:

------------------
DeleteItemResult_t
------------------

.. function:: Steam.newDeleteItemResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (DeleteItemResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_nPublishedFileId** (uint64)

.. _struct-UserSubscribedItemsListChanged_t:

--------------------------------
UserSubscribedItemsListChanged_t
--------------------------------

.. function:: Steam.newUserSubscribedItemsListChanged_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (UserSubscribedItemsListChanged_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_nAppID** (int)

.. _struct-WorkshopEULAStatus_t:

--------------------
WorkshopEULAStatus_t
--------------------

.. function:: Steam.newWorkshopEULAStatus_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (WorkshopEULAStatus_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_nAppID** (int)
    * **m_unVersion** (int)
    * **m_rtAction** (int)
    * **m_bAccepted** (bool)
    * **m_bNeedsAction** (bool)

.. _struct-HTML_BrowserReady_t:

-------------------
HTML_BrowserReady_t
-------------------

.. function:: Steam.newHTML_BrowserReady_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (HTML_BrowserReady_t) New userdata instance.

    **Fields** (readable and writable):

    * **unBrowserHandle** (int)

.. _struct-HTML_NeedsPaint_t:

-----------------
HTML_NeedsPaint_t
-----------------

.. function:: Steam.newHTML_NeedsPaint_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (HTML_NeedsPaint_t) New userdata instance.

    **Fields** (readable and writable):

    * **unBrowserHandle** (int)
    * **pBGRA** (str)
    * **unWide** (int)
    * **unTall** (int)
    * **unUpdateX** (int)
    * **unUpdateY** (int)
    * **unUpdateWide** (int)
    * **unUpdateTall** (int)
    * **unScrollX** (int)
    * **unScrollY** (int)
    * **flPageScale** (float)
    * **unPageSerial** (int)

.. _struct-HTML_StartRequest_t:

-------------------
HTML_StartRequest_t
-------------------

.. function:: Steam.newHTML_StartRequest_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (HTML_StartRequest_t) New userdata instance.

    **Fields** (readable and writable):

    * **unBrowserHandle** (int)
    * **pchURL** (str)
    * **pchTarget** (str)
    * **pchPostData** (str)
    * **bIsRedirect** (bool)

.. _struct-HTML_CloseBrowser_t:

-------------------
HTML_CloseBrowser_t
-------------------

.. function:: Steam.newHTML_CloseBrowser_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (HTML_CloseBrowser_t) New userdata instance.

    **Fields** (readable and writable):

    * **unBrowserHandle** (int)

.. _struct-HTML_URLChanged_t:

-----------------
HTML_URLChanged_t
-----------------

.. function:: Steam.newHTML_URLChanged_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (HTML_URLChanged_t) New userdata instance.

    **Fields** (readable and writable):

    * **unBrowserHandle** (int)
    * **pchURL** (str)
    * **pchPostData** (str)
    * **bIsRedirect** (bool)
    * **pchPageTitle** (str)
    * **bNewNavigation** (bool)

.. _struct-HTML_FinishedRequest_t:

----------------------
HTML_FinishedRequest_t
----------------------

.. function:: Steam.newHTML_FinishedRequest_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (HTML_FinishedRequest_t) New userdata instance.

    **Fields** (readable and writable):

    * **unBrowserHandle** (int)
    * **pchURL** (str)
    * **pchPageTitle** (str)

.. _struct-HTML_OpenLinkInNewTab_t:

-----------------------
HTML_OpenLinkInNewTab_t
-----------------------

.. function:: Steam.newHTML_OpenLinkInNewTab_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (HTML_OpenLinkInNewTab_t) New userdata instance.

    **Fields** (readable and writable):

    * **unBrowserHandle** (int)
    * **pchURL** (str)

.. _struct-HTML_ChangedTitle_t:

-------------------
HTML_ChangedTitle_t
-------------------

.. function:: Steam.newHTML_ChangedTitle_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (HTML_ChangedTitle_t) New userdata instance.

    **Fields** (readable and writable):

    * **unBrowserHandle** (int)
    * **pchTitle** (str)

.. _struct-HTML_SearchResults_t:

--------------------
HTML_SearchResults_t
--------------------

.. function:: Steam.newHTML_SearchResults_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (HTML_SearchResults_t) New userdata instance.

    **Fields** (readable and writable):

    * **unBrowserHandle** (int)
    * **unResults** (int)
    * **unCurrentMatch** (int)

.. _struct-HTML_CanGoBackAndForward_t:

--------------------------
HTML_CanGoBackAndForward_t
--------------------------

.. function:: Steam.newHTML_CanGoBackAndForward_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (HTML_CanGoBackAndForward_t) New userdata instance.

    **Fields** (readable and writable):

    * **unBrowserHandle** (int)
    * **bCanGoBack** (bool)
    * **bCanGoForward** (bool)

.. _struct-HTML_HorizontalScroll_t:

-----------------------
HTML_HorizontalScroll_t
-----------------------

.. function:: Steam.newHTML_HorizontalScroll_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (HTML_HorizontalScroll_t) New userdata instance.

    **Fields** (readable and writable):

    * **unBrowserHandle** (int)
    * **unScrollMax** (int)
    * **unScrollCurrent** (int)
    * **flPageScale** (float)
    * **bVisible** (bool)
    * **unPageSize** (int)

.. _struct-HTML_VerticalScroll_t:

---------------------
HTML_VerticalScroll_t
---------------------

.. function:: Steam.newHTML_VerticalScroll_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (HTML_VerticalScroll_t) New userdata instance.

    **Fields** (readable and writable):

    * **unBrowserHandle** (int)
    * **unScrollMax** (int)
    * **unScrollCurrent** (int)
    * **flPageScale** (float)
    * **bVisible** (bool)
    * **unPageSize** (int)

.. _struct-HTML_LinkAtPosition_t:

---------------------
HTML_LinkAtPosition_t
---------------------

.. function:: Steam.newHTML_LinkAtPosition_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (HTML_LinkAtPosition_t) New userdata instance.

    **Fields** (readable and writable):

    * **unBrowserHandle** (int)
    * **x** (int)
    * **y** (int)
    * **pchURL** (str)
    * **bInput** (bool)
    * **bLiveLink** (bool)

.. _struct-HTML_JSAlert_t:

--------------
HTML_JSAlert_t
--------------

.. function:: Steam.newHTML_JSAlert_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (HTML_JSAlert_t) New userdata instance.

    **Fields** (readable and writable):

    * **unBrowserHandle** (int)
    * **pchMessage** (str)

.. _struct-HTML_JSConfirm_t:

----------------
HTML_JSConfirm_t
----------------

.. function:: Steam.newHTML_JSConfirm_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (HTML_JSConfirm_t) New userdata instance.

    **Fields** (readable and writable):

    * **unBrowserHandle** (int)
    * **pchMessage** (str)

.. _struct-HTML_FileOpenDialog_t:

---------------------
HTML_FileOpenDialog_t
---------------------

.. function:: Steam.newHTML_FileOpenDialog_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (HTML_FileOpenDialog_t) New userdata instance.

    **Fields** (readable and writable):

    * **unBrowserHandle** (int)
    * **pchTitle** (str)
    * **pchInitialFile** (str)

.. _struct-HTML_NewWindow_t:

----------------
HTML_NewWindow_t
----------------

.. function:: Steam.newHTML_NewWindow_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (HTML_NewWindow_t) New userdata instance.

    **Fields** (readable and writable):

    * **unBrowserHandle** (int)
    * **pchURL** (str)
    * **unX** (int)
    * **unY** (int)
    * **unWide** (int)
    * **unTall** (int)
    * **unNewWindow_BrowserHandle_IGNORE** (int)

.. _struct-HTML_SetCursor_t:

----------------
HTML_SetCursor_t
----------------

.. function:: Steam.newHTML_SetCursor_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (HTML_SetCursor_t) New userdata instance.

    **Fields** (readable and writable):

    * **unBrowserHandle** (int)
    * **eMouseCursor** (int)

.. _struct-HTML_StatusText_t:

-----------------
HTML_StatusText_t
-----------------

.. function:: Steam.newHTML_StatusText_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (HTML_StatusText_t) New userdata instance.

    **Fields** (readable and writable):

    * **unBrowserHandle** (int)
    * **pchMsg** (str)

.. _struct-HTML_ShowToolTip_t:

------------------
HTML_ShowToolTip_t
------------------

.. function:: Steam.newHTML_ShowToolTip_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (HTML_ShowToolTip_t) New userdata instance.

    **Fields** (readable and writable):

    * **unBrowserHandle** (int)
    * **pchMsg** (str)

.. _struct-HTML_UpdateToolTip_t:

--------------------
HTML_UpdateToolTip_t
--------------------

.. function:: Steam.newHTML_UpdateToolTip_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (HTML_UpdateToolTip_t) New userdata instance.

    **Fields** (readable and writable):

    * **unBrowserHandle** (int)
    * **pchMsg** (str)

.. _struct-HTML_HideToolTip_t:

------------------
HTML_HideToolTip_t
------------------

.. function:: Steam.newHTML_HideToolTip_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (HTML_HideToolTip_t) New userdata instance.

    **Fields** (readable and writable):

    * **unBrowserHandle** (int)

.. _struct-HTML_BrowserRestarted_t:

-----------------------
HTML_BrowserRestarted_t
-----------------------

.. function:: Steam.newHTML_BrowserRestarted_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (HTML_BrowserRestarted_t) New userdata instance.

    **Fields** (readable and writable):

    * **unBrowserHandle** (int)
    * **unOldBrowserHandle** (int)

.. _struct-SteamInventoryResultReady_t:

---------------------------
SteamInventoryResultReady_t
---------------------------

.. function:: Steam.newSteamInventoryResultReady_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamInventoryResultReady_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_handle** (int)
    * **m_result** (int)

.. _struct-SteamInventoryFullUpdate_t:

--------------------------
SteamInventoryFullUpdate_t
--------------------------

.. function:: Steam.newSteamInventoryFullUpdate_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamInventoryFullUpdate_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_handle** (int)

.. _struct-SteamInventoryDefinitionUpdate_t:

--------------------------------
SteamInventoryDefinitionUpdate_t
--------------------------------

.. function:: Steam.newSteamInventoryDefinitionUpdate_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamInventoryDefinitionUpdate_t) New userdata instance.

.. _struct-SteamInventoryEligiblePromoItemDefIDs_t:

---------------------------------------
SteamInventoryEligiblePromoItemDefIDs_t
---------------------------------------

.. function:: Steam.newSteamInventoryEligiblePromoItemDefIDs_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamInventoryEligiblePromoItemDefIDs_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_result** (int)
    * **m_steamID** (uint64)
    * **m_numEligiblePromoItemDefs** (int)
    * **m_bCachedData** (bool)

.. _struct-SteamInventoryStartPurchaseResult_t:

-----------------------------------
SteamInventoryStartPurchaseResult_t
-----------------------------------

.. function:: Steam.newSteamInventoryStartPurchaseResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamInventoryStartPurchaseResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_result** (int)
    * **m_ulOrderID** (uint64)
    * **m_ulTransID** (uint64)

.. _struct-SteamInventoryRequestPricesResult_t:

-----------------------------------
SteamInventoryRequestPricesResult_t
-----------------------------------

.. function:: Steam.newSteamInventoryRequestPricesResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamInventoryRequestPricesResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_result** (int)
    * **m_rgchCurrency** (str)

.. _struct-SteamTimelineGamePhaseRecordingExists_t:

---------------------------------------
SteamTimelineGamePhaseRecordingExists_t
---------------------------------------

.. function:: Steam.newSteamTimelineGamePhaseRecordingExists_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamTimelineGamePhaseRecordingExists_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_rgchPhaseID** (str)
    * **m_ulRecordingMS** (uint64)
    * **m_ulLongestClipMS** (uint64)
    * **m_unClipCount** (int)
    * **m_unScreenshotCount** (int)

.. _struct-SteamTimelineEventRecordingExists_t:

-----------------------------------
SteamTimelineEventRecordingExists_t
-----------------------------------

.. function:: Steam.newSteamTimelineEventRecordingExists_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamTimelineEventRecordingExists_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_ulEventID** (uint64)
    * **m_bRecordingExists** (bool)

.. _struct-GetVideoURLResult_t:

-------------------
GetVideoURLResult_t
-------------------

.. function:: Steam.newGetVideoURLResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (GetVideoURLResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_unVideoAppID** (int)
    * **m_rgchURL** (str)

.. _struct-GetOPFSettingsResult_t:

----------------------
GetOPFSettingsResult_t
----------------------

.. function:: Steam.newGetOPFSettingsResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (GetOPFSettingsResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_unVideoAppID** (int)

.. _struct-BroadcastUploadStart_t:

----------------------
BroadcastUploadStart_t
----------------------

.. function:: Steam.newBroadcastUploadStart_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (BroadcastUploadStart_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_bIsRTMP** (bool)

.. _struct-BroadcastUploadStop_t:

---------------------
BroadcastUploadStop_t
---------------------

.. function:: Steam.newBroadcastUploadStop_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (BroadcastUploadStop_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)

.. _struct-SteamParentalSettingsChanged_t:

------------------------------
SteamParentalSettingsChanged_t
------------------------------

.. function:: Steam.newSteamParentalSettingsChanged_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamParentalSettingsChanged_t) New userdata instance.

.. _struct-SteamRemotePlaySessionConnected_t:

---------------------------------
SteamRemotePlaySessionConnected_t
---------------------------------

.. function:: Steam.newSteamRemotePlaySessionConnected_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamRemotePlaySessionConnected_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_unSessionID** (int)

.. _struct-SteamRemotePlaySessionDisconnected_t:

------------------------------------
SteamRemotePlaySessionDisconnected_t
------------------------------------

.. function:: Steam.newSteamRemotePlaySessionDisconnected_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamRemotePlaySessionDisconnected_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_unSessionID** (int)

.. _struct-SteamRemotePlayTogetherGuestInvite_t:

------------------------------------
SteamRemotePlayTogetherGuestInvite_t
------------------------------------

.. function:: Steam.newSteamRemotePlayTogetherGuestInvite_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamRemotePlayTogetherGuestInvite_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_szConnectURL** (str)

.. _struct-SteamNetworkingMessagesSessionRequest_t:

---------------------------------------
SteamNetworkingMessagesSessionRequest_t
---------------------------------------

.. function:: Steam.newSteamNetworkingMessagesSessionRequest_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamNetworkingMessagesSessionRequest_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_identityRemote** (:ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>`)

.. _struct-SteamNetworkingMessagesSessionFailed_t:

--------------------------------------
SteamNetworkingMessagesSessionFailed_t
--------------------------------------

.. function:: Steam.newSteamNetworkingMessagesSessionFailed_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamNetworkingMessagesSessionFailed_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_info** (:ref:`SteamNetConnectionInfo_t <struct-SteamNetConnectionInfo_t>`)

.. _struct-SteamNetConnectionStatusChangedCallback_t:

-----------------------------------------
SteamNetConnectionStatusChangedCallback_t
-----------------------------------------

.. function:: Steam.newSteamNetConnectionStatusChangedCallback_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamNetConnectionStatusChangedCallback_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_hConn** (int)
    * **m_info** (:ref:`SteamNetConnectionInfo_t <struct-SteamNetConnectionInfo_t>`)
    * **m_eOldState** (int)

.. _struct-SteamNetAuthenticationStatus_t:

------------------------------
SteamNetAuthenticationStatus_t
------------------------------

.. function:: Steam.newSteamNetAuthenticationStatus_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamNetAuthenticationStatus_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eAvail** (int)
    * **m_debugMsg** (str)

.. _struct-SteamRelayNetworkStatus_t:

-------------------------
SteamRelayNetworkStatus_t
-------------------------

.. function:: Steam.newSteamRelayNetworkStatus_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamRelayNetworkStatus_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eAvail** (int)
    * **m_bPingMeasurementInProgress** (int)
    * **m_eAvailNetworkConfig** (int)
    * **m_eAvailAnyRelay** (int)
    * **m_debugMsg** (str)

.. _struct-GSClientApprove_t:

-----------------
GSClientApprove_t
-----------------

.. function:: Steam.newGSClientApprove_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (GSClientApprove_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_SteamID** (uint64)
    * **m_OwnerSteamID** (uint64)

.. _struct-GSClientDeny_t:

--------------
GSClientDeny_t
--------------

.. function:: Steam.newGSClientDeny_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (GSClientDeny_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_SteamID** (uint64)
    * **m_eDenyReason** (int)
    * **m_rgchOptionalText** (str)

.. _struct-GSClientKick_t:

--------------
GSClientKick_t
--------------

.. function:: Steam.newGSClientKick_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (GSClientKick_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_SteamID** (uint64)
    * **m_eDenyReason** (int)

.. _struct-GSClientAchievementStatus_t:

---------------------------
GSClientAchievementStatus_t
---------------------------

.. function:: Steam.newGSClientAchievementStatus_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (GSClientAchievementStatus_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_SteamID** (uint64)
    * **m_pchAchievement** (str)
    * **m_bUnlocked** (bool)

.. _struct-GSPolicyResponse_t:

------------------
GSPolicyResponse_t
------------------

.. function:: Steam.newGSPolicyResponse_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (GSPolicyResponse_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_bSecure** (int)

.. _struct-GSGameplayStats_t:

-----------------
GSGameplayStats_t
-----------------

.. function:: Steam.newGSGameplayStats_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (GSGameplayStats_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_nRank** (int)
    * **m_unTotalConnects** (int)
    * **m_unTotalMinutesPlayed** (int)

.. _struct-GSClientGroupStatus_t:

---------------------
GSClientGroupStatus_t
---------------------

.. function:: Steam.newGSClientGroupStatus_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (GSClientGroupStatus_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_SteamIDUser** (uint64)
    * **m_SteamIDGroup** (uint64)
    * **m_bMember** (bool)
    * **m_bOfficer** (bool)

.. _struct-GSReputation_t:

--------------
GSReputation_t
--------------

.. function:: Steam.newGSReputation_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (GSReputation_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_unReputationScore** (int)
    * **m_bBanned** (bool)
    * **m_unBannedIP** (int)
    * **m_usBannedPort** (int)
    * **m_ulBannedGameID** (uint64)
    * **m_unBanExpires** (int)

.. _struct-AssociateWithClanResult_t:

-------------------------
AssociateWithClanResult_t
-------------------------

.. function:: Steam.newAssociateWithClanResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (AssociateWithClanResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)

.. _struct-ComputeNewPlayerCompatibilityResult_t:

-------------------------------------
ComputeNewPlayerCompatibilityResult_t
-------------------------------------

.. function:: Steam.newComputeNewPlayerCompatibilityResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (ComputeNewPlayerCompatibilityResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_cPlayersThatDontLikeCandidate** (int)
    * **m_cPlayersThatCandidateDoesntLike** (int)
    * **m_cClanPlayersThatDontLikeCandidate** (int)
    * **m_SteamIDCandidate** (uint64)

.. _struct-GSStatsReceived_t:

-----------------
GSStatsReceived_t
-----------------

.. function:: Steam.newGSStatsReceived_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (GSStatsReceived_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_steamIDUser** (uint64)

.. _struct-GSStatsStored_t:

---------------
GSStatsStored_t
---------------

.. function:: Steam.newGSStatsStored_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (GSStatsStored_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_steamIDUser** (uint64)

.. _struct-GSStatsUnloaded_t:

-----------------
GSStatsUnloaded_t
-----------------

.. function:: Steam.newGSStatsUnloaded_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (GSStatsUnloaded_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_steamIDUser** (uint64)

.. _struct-SteamNetworkingFakeIPResult_t:

-----------------------------
SteamNetworkingFakeIPResult_t
-----------------------------

.. function:: Steam.newSteamNetworkingFakeIPResult_t([table])

    🤖 Constructor — creates a new userdata instance.

    :param table table: *(optional)* Initial field values as a table.
    :returns: (SteamNetworkingFakeIPResult_t) New userdata instance.

    **Fields** (readable and writable):

    * **m_eResult** (int)
    * **m_identity** (:ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>`)
    * **m_unIP** (int)
    * **m_unPorts** (int[])

