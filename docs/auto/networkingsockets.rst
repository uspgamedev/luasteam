#######################
ISteamNetworkingSockets
#######################

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✋ require manual implementation.

.. note::
   Overloaded Steam methods are exposed as distinct Lua functions using a type suffix (for example ``GetStatInt32`` and ``SetStatFloat``).

List of Functions
-----------------

* :func:`NetworkingSockets.CreateListenSocketIP`
* :func:`NetworkingSockets.ConnectByIPAddress`
* :func:`NetworkingSockets.CreateListenSocketP2P`
* :func:`NetworkingSockets.ConnectP2P`
* :func:`NetworkingSockets.AcceptConnection`
* :func:`NetworkingSockets.CloseConnection`
* :func:`NetworkingSockets.CloseListenSocket`
* :func:`NetworkingSockets.SetConnectionUserData`
* :func:`NetworkingSockets.GetConnectionUserData`
* :func:`NetworkingSockets.SetConnectionName`
* :func:`NetworkingSockets.SendMessageToConnection`
* :func:`NetworkingSockets.FlushMessagesOnConnection`
* :func:`NetworkingSockets.GetConnectionInfo`
* :func:`NetworkingSockets.GetConnectionRealTimeStatus`
* :func:`NetworkingSockets.GetListenSocketAddress`
* :func:`NetworkingSockets.CreateSocketPair`
* :func:`NetworkingSockets.GetIdentity`
* :func:`NetworkingSockets.InitAuthentication`
* :func:`NetworkingSockets.CreatePollGroup`
* :func:`NetworkingSockets.DestroyPollGroup`
* :func:`NetworkingSockets.SetConnectionPollGroup`
* :func:`NetworkingSockets.ConnectToHostedDedicatedServer`
* :func:`NetworkingSockets.GetHostedDedicatedServerPort`
* :func:`NetworkingSockets.GetHostedDedicatedServerPOPID`
* :func:`NetworkingSockets.CreateHostedDedicatedServerListenSocket`
* :func:`NetworkingSockets.ResetIdentity`
* :func:`NetworkingSockets.RunCallbacks`
* :func:`NetworkingSockets.BeginAsyncRequestFakeIP`
* :func:`NetworkingSockets.CreateListenSocketP2PFakeIP`
* :func:`NetworkingSockets.GetRemoteFakeIPForConnection`

List of Callbacks
-----------------

* :func:`NetworkingSockets.onSteamNetConnectionStatusChangedCallback`
* :func:`NetworkingSockets.onSteamNetAuthenticationStatus`
* :func:`NetworkingSockets.onSteamNetworkingFakeIPResult`

Function Reference
------------------

.. function:: NetworkingSockets.CreateListenSocketIP(localAddress, nOptions, pOptions)

    🤖 **Auto-generated binding**

    :param :ref:`SteamNetworkingIPAddr <struct-SteamNetworkingIPAddr>` localAddress:
    :param int nOptions:
    :param :ref:`SteamNetworkingConfigValue_t <struct-SteamNetworkingConfigValue_t>` pOptions:
    :returns: (int) Return value
    :SteamWorks: `CreateListenSocketIP <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CreateListenSocketIP>`_

.. function:: NetworkingSockets.ConnectByIPAddress(address, nOptions, pOptions)

    🤖 **Auto-generated binding**

    :param :ref:`SteamNetworkingIPAddr <struct-SteamNetworkingIPAddr>` address:
    :param int nOptions:
    :param :ref:`SteamNetworkingConfigValue_t <struct-SteamNetworkingConfigValue_t>` pOptions:
    :returns: (int) Return value
    :SteamWorks: `ConnectByIPAddress <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#ConnectByIPAddress>`_

.. function:: NetworkingSockets.CreateListenSocketP2P(nLocalVirtualPort, nOptions, pOptions)

    🤖 **Auto-generated binding**

    :param int nLocalVirtualPort:
    :param int nOptions:
    :param :ref:`SteamNetworkingConfigValue_t <struct-SteamNetworkingConfigValue_t>` pOptions:
    :returns: (int) Return value
    :SteamWorks: `CreateListenSocketP2P <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CreateListenSocketP2P>`_

.. function:: NetworkingSockets.ConnectP2P(identityRemote, nRemoteVirtualPort, nOptions, pOptions)

    🤖 **Auto-generated binding**

    :param :ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>` identityRemote:
    :param int nRemoteVirtualPort:
    :param int nOptions:
    :param :ref:`SteamNetworkingConfigValue_t <struct-SteamNetworkingConfigValue_t>` pOptions:
    :returns: (int) Return value
    :SteamWorks: `ConnectP2P <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#ConnectP2P>`_

.. function:: NetworkingSockets.AcceptConnection(hConn)

    🤖 **Auto-generated binding**

    :param int hConn:
    :returns: (int) Return value
    :SteamWorks: `AcceptConnection <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#AcceptConnection>`_

.. function:: NetworkingSockets.CloseConnection(hPeer, nReason, pszDebug, bEnableLinger)

    🤖 **Auto-generated binding**

    :param int hPeer:
    :param int nReason:
    :param str pszDebug:
    :param bool bEnableLinger:
    :returns: (bool) Return value
    :SteamWorks: `CloseConnection <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CloseConnection>`_

.. function:: NetworkingSockets.CloseListenSocket(hSocket)

    🤖 **Auto-generated binding**

    :param int hSocket:
    :returns: (bool) Return value
    :SteamWorks: `CloseListenSocket <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CloseListenSocket>`_

.. function:: NetworkingSockets.SetConnectionUserData(hPeer, nUserData)

    🤖 **Auto-generated binding**

    :param int hPeer:
    :param uint64 nUserData:
    :returns: (bool) Return value
    :SteamWorks: `SetConnectionUserData <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#SetConnectionUserData>`_

.. function:: NetworkingSockets.GetConnectionUserData(hPeer)

    🤖 **Auto-generated binding**

    :param int hPeer:
    :returns: (uint64) Return value
    :SteamWorks: `GetConnectionUserData <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetConnectionUserData>`_

.. function:: NetworkingSockets.SetConnectionName(hPeer, pszName)

    🤖 **Auto-generated binding**

    :param int hPeer:
    :param str pszName:
    :SteamWorks: `SetConnectionName <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#SetConnectionName>`_

.. function:: NetworkingSockets.SendMessageToConnection(hConn, pData, cbData, nSendFlags)

    🤖 **Auto-generated binding**

    :param int hConn:
    :param str pData:
    :param int cbData:
    :param int nSendFlags:
    :returns: (int) Return value
    :returns: (uint64) Value for `pOutMessageNumber`
    :SteamWorks: `SendMessageToConnection <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#SendMessageToConnection>`_

    **Signature differences from C++ API:**

    * Parameter ``pOutMessageNumber`` is returned as an additional return value

.. function:: NetworkingSockets.FlushMessagesOnConnection(hConn)

    🤖 **Auto-generated binding**

    :param int hConn:
    :returns: (int) Return value
    :SteamWorks: `FlushMessagesOnConnection <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#FlushMessagesOnConnection>`_

.. function:: NetworkingSockets.GetConnectionInfo(hConn)

    🤖 **Auto-generated binding**

    :param int hConn:
    :returns: (bool) Return value
    :returns: (:ref:`SteamNetConnectionInfo_t <struct-SteamNetConnectionInfo_t>`) Value for `pInfo`
    :SteamWorks: `GetConnectionInfo <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetConnectionInfo>`_

    **Signature differences from C++ API:**

    * Parameter ``pInfo`` is returned as an additional return value

.. function:: NetworkingSockets.GetConnectionRealTimeStatus(hConn, nLanes)

    🤖 **Auto-generated binding**

    :param int hConn:
    :param int nLanes:
    :returns: (int) Return value
    :returns: (:ref:`SteamNetConnectionRealTimeStatus_t <struct-SteamNetConnectionRealTimeStatus_t>`) Value for `pStatus`
    :returns: (:ref:`SteamNetConnectionRealTimeLaneStatus_t <struct-SteamNetConnectionRealTimeLaneStatus_t>`) Value for `pLanes`
    :SteamWorks: `GetConnectionRealTimeStatus <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetConnectionRealTimeStatus>`_

    **Signature differences from C++ API:**

    * Parameter ``pStatus`` is returned as an additional return value
    * Parameter ``pLanes`` is returned as an additional return value

.. function:: NetworkingSockets.GetListenSocketAddress(hSocket)

    🤖 **Auto-generated binding**

    :param int hSocket:
    :returns: (bool) Return value
    :returns: (:ref:`SteamNetworkingIPAddr <struct-SteamNetworkingIPAddr>`) Value for `address`
    :SteamWorks: `GetListenSocketAddress <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetListenSocketAddress>`_

    **Signature differences from C++ API:**

    * Parameter ``address`` is returned as an additional return value

.. function:: NetworkingSockets.CreateSocketPair(bUseNetworkLoopback, pIdentity1, pIdentity2)

    🤖 **Auto-generated binding**

    :param bool bUseNetworkLoopback:
    :param :ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>` pIdentity1:
    :param :ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>` pIdentity2:
    :returns: (bool) Return value
    :returns: (int) Value for `pOutConnection1`
    :returns: (int) Value for `pOutConnection2`
    :SteamWorks: `CreateSocketPair <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CreateSocketPair>`_

    **Signature differences from C++ API:**

    * Parameter ``pOutConnection1`` is returned as an additional return value
    * Parameter ``pOutConnection2`` is returned as an additional return value

.. function:: NetworkingSockets.GetIdentity()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :returns: (:ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>`) Value for `pIdentity`
    :SteamWorks: `GetIdentity <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetIdentity>`_

    **Signature differences from C++ API:**

    * Parameter ``pIdentity`` is returned as an additional return value

.. function:: NetworkingSockets.InitAuthentication()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `InitAuthentication <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#InitAuthentication>`_

.. function:: NetworkingSockets.CreatePollGroup()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `CreatePollGroup <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CreatePollGroup>`_

.. function:: NetworkingSockets.DestroyPollGroup(hPollGroup)

    🤖 **Auto-generated binding**

    :param int hPollGroup:
    :returns: (bool) Return value
    :SteamWorks: `DestroyPollGroup <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#DestroyPollGroup>`_

.. function:: NetworkingSockets.SetConnectionPollGroup(hConn, hPollGroup)

    🤖 **Auto-generated binding**

    :param int hConn:
    :param int hPollGroup:
    :returns: (bool) Return value
    :SteamWorks: `SetConnectionPollGroup <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#SetConnectionPollGroup>`_

.. function:: NetworkingSockets.ConnectToHostedDedicatedServer(identityTarget, nRemoteVirtualPort, nOptions, pOptions)

    🤖 **Auto-generated binding**

    :param :ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>` identityTarget:
    :param int nRemoteVirtualPort:
    :param int nOptions:
    :param :ref:`SteamNetworkingConfigValue_t <struct-SteamNetworkingConfigValue_t>` pOptions:
    :returns: (int) Return value
    :SteamWorks: `ConnectToHostedDedicatedServer <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#ConnectToHostedDedicatedServer>`_

.. function:: NetworkingSockets.GetHostedDedicatedServerPort()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetHostedDedicatedServerPort <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetHostedDedicatedServerPort>`_

.. function:: NetworkingSockets.GetHostedDedicatedServerPOPID()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetHostedDedicatedServerPOPID <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetHostedDedicatedServerPOPID>`_

.. function:: NetworkingSockets.CreateHostedDedicatedServerListenSocket(nLocalVirtualPort, nOptions, pOptions)

    🤖 **Auto-generated binding**

    :param int nLocalVirtualPort:
    :param int nOptions:
    :param :ref:`SteamNetworkingConfigValue_t <struct-SteamNetworkingConfigValue_t>` pOptions:
    :returns: (int) Return value
    :SteamWorks: `CreateHostedDedicatedServerListenSocket <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CreateHostedDedicatedServerListenSocket>`_

.. function:: NetworkingSockets.ResetIdentity(pIdentity)

    🤖 **Auto-generated binding**

    :param :ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>` pIdentity:
    :SteamWorks: `ResetIdentity <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#ResetIdentity>`_

.. function:: NetworkingSockets.RunCallbacks()

    🤖 **Auto-generated binding**

    :SteamWorks: `RunCallbacks <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#RunCallbacks>`_

.. function:: NetworkingSockets.BeginAsyncRequestFakeIP(nNumPorts)

    🤖 **Auto-generated binding**

    :param int nNumPorts:
    :returns: (bool) Return value
    :SteamWorks: `BeginAsyncRequestFakeIP <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#BeginAsyncRequestFakeIP>`_

.. function:: NetworkingSockets.CreateListenSocketP2PFakeIP(idxFakePort, nOptions, pOptions)

    🤖 **Auto-generated binding**

    :param int idxFakePort:
    :param int nOptions:
    :param :ref:`SteamNetworkingConfigValue_t <struct-SteamNetworkingConfigValue_t>` pOptions:
    :returns: (int) Return value
    :SteamWorks: `CreateListenSocketP2PFakeIP <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CreateListenSocketP2PFakeIP>`_

.. function:: NetworkingSockets.GetRemoteFakeIPForConnection(hConn)

    🤖 **Auto-generated binding**

    :param int hConn:
    :returns: (int) Return value
    :returns: (:ref:`SteamNetworkingIPAddr <struct-SteamNetworkingIPAddr>`) Value for `pOutAddr`
    :SteamWorks: `GetRemoteFakeIPForConnection <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetRemoteFakeIPForConnection>`_

    **Signature differences from C++ API:**

    * Parameter ``pOutAddr`` is returned as an additional return value


Unimplemented Methods
---------------------

.. function:: NetworkingSockets.getConnectionName

    ✋ **Not implemented** - unsupported type: char *
    
    :SteamWorks: `GetConnectionName <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetConnectionName>`_

.. function:: NetworkingSockets.sendMessages

    ✋ **Not implemented** - unsupported type: SteamNetworkingMessage_t *const *
    
    :SteamWorks: `SendMessages <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#SendMessages>`_

.. function:: NetworkingSockets.receiveMessagesOnConnection

    ✋ **Not implemented** - unsupported type: SteamNetworkingMessage_t **
    
    :SteamWorks: `ReceiveMessagesOnConnection <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#ReceiveMessagesOnConnection>`_

.. function:: NetworkingSockets.getDetailedConnectionStatus

    ✋ **Not implemented** - unsupported type: char *
    
    :SteamWorks: `GetDetailedConnectionStatus <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetDetailedConnectionStatus>`_

.. function:: NetworkingSockets.configureConnectionLanes

    ✋ **Not implemented** - unsupported type: const int *
    
    :SteamWorks: `ConfigureConnectionLanes <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#ConfigureConnectionLanes>`_

.. function:: NetworkingSockets.getAuthenticationStatus

    ✋ **Not implemented** - unsupported type: SteamNetAuthenticationStatus_t *
    
    :SteamWorks: `GetAuthenticationStatus <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetAuthenticationStatus>`_

.. function:: NetworkingSockets.receiveMessagesOnPollGroup

    ✋ **Not implemented** - unsupported type: SteamNetworkingMessage_t **
    
    :SteamWorks: `ReceiveMessagesOnPollGroup <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#ReceiveMessagesOnPollGroup>`_

.. function:: NetworkingSockets.receivedRelayAuthTicket

    ✋ **Not implemented** - unsupported type: SteamDatagramRelayAuthTicket *
    
    :SteamWorks: `ReceivedRelayAuthTicket <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#ReceivedRelayAuthTicket>`_

.. function:: NetworkingSockets.findRelayAuthTicketForServer

    ✋ **Not implemented** - unsupported type: SteamDatagramRelayAuthTicket *
    
    :SteamWorks: `FindRelayAuthTicketForServer <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#FindRelayAuthTicketForServer>`_

.. function:: NetworkingSockets.getHostedDedicatedServerAddress

    ✋ **Not implemented** - unsupported type: SteamDatagramHostedAddress *
    
    :SteamWorks: `GetHostedDedicatedServerAddress <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetHostedDedicatedServerAddress>`_

.. function:: NetworkingSockets.getGameCoordinatorServerLogin

    ✋ **Not implemented** - unsupported type: SteamDatagramGameCoordinatorServerLogin *
    
    :SteamWorks: `GetGameCoordinatorServerLogin <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetGameCoordinatorServerLogin>`_

.. function:: NetworkingSockets.connectP2PCustomSignaling

    ✋ **Not implemented** - unsupported type: ISteamNetworkingConnectionSignaling *
    
    :SteamWorks: `ConnectP2PCustomSignaling <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#ConnectP2PCustomSignaling>`_

.. function:: NetworkingSockets.receivedP2PCustomSignal

    ✋ **Not implemented** - unsupported type: ISteamNetworkingSignalingRecvContext *
    
    :SteamWorks: `ReceivedP2PCustomSignal <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#ReceivedP2PCustomSignal>`_

.. function:: NetworkingSockets.getCertificateRequest

    ✋ **Not implemented** - unsupported type: SteamNetworkingErrMsg &
    
    :SteamWorks: `GetCertificateRequest <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetCertificateRequest>`_

.. function:: NetworkingSockets.setCertificate

    ✋ **Not implemented** - unsupported type: SteamNetworkingErrMsg &
    
    :SteamWorks: `SetCertificate <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#SetCertificate>`_

.. function:: NetworkingSockets.getFakeIP

    ✋ **Not implemented** - unsupported type: SteamNetworkingFakeIPResult_t *
    
    :SteamWorks: `GetFakeIP <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetFakeIP>`_

.. function:: NetworkingSockets.createFakeUDPPort

    ✋ **Not implemented** - unsupported type: ISteamNetworkingFakeUDPPort *
    
    :SteamWorks: `CreateFakeUDPPort <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CreateFakeUDPPort>`_


Callbacks
---------

.. function:: NetworkingSockets.onSteamNetConnectionStatusChangedCallback

    Callback for `SteamNetConnectionStatusChangedCallback_t <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#SteamNetConnectionStatusChangedCallback_t>`_

    **callback(data)** receives:

    * **data.m_hConn** -- m_hConn
    * **data.m_info** -- m_info
    * **data.m_eOldState** -- m_eOldState

.. function:: NetworkingSockets.onSteamNetAuthenticationStatus

    Callback for `SteamNetAuthenticationStatus_t <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#SteamNetAuthenticationStatus_t>`_

    **callback(data)** receives:

    * **data.m_eAvail** -- m_eAvail
    * **data.m_debugMsg** -- m_debugMsg

.. function:: NetworkingSockets.onSteamNetworkingFakeIPResult

    Callback for `SteamNetworkingFakeIPResult_t <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#SteamNetworkingFakeIPResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_identity** -- m_identity
    * **data.m_unIP** -- m_unIP
    * **data.m_unPorts** -- m_unPorts

