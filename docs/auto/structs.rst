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

