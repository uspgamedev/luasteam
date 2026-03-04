#######################
ISteamNetworkingSockets
#######################

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✍️ are manually implemented and methods marked with ✋ are currently not implemented.

List of Functions
-----------------

* :func:`NetworkingSockets.AcceptConnection`
* :func:`NetworkingSockets.BeginAsyncRequestFakeIP`
* :func:`NetworkingSockets.CloseConnection`
* :func:`NetworkingSockets.CloseListenSocket`
* :func:`NetworkingSockets.ConfigureConnectionLanes`
* :func:`NetworkingSockets.ConnectByIPAddress`
* :func:`NetworkingSockets.ConnectP2P`
* :func:`NetworkingSockets.ConnectToHostedDedicatedServer`
* :func:`NetworkingSockets.CreateHostedDedicatedServerListenSocket`
* :func:`NetworkingSockets.CreateListenSocketIP`
* :func:`NetworkingSockets.CreateListenSocketP2P`
* :func:`NetworkingSockets.CreateListenSocketP2PFakeIP`
* :func:`NetworkingSockets.CreatePollGroup`
* :func:`NetworkingSockets.CreateSocketPair`
* :func:`NetworkingSockets.DestroyPollGroup`
* :func:`NetworkingSockets.FlushMessagesOnConnection`
* :func:`NetworkingSockets.GetAuthenticationStatus`
* :func:`NetworkingSockets.GetConnectionInfo`
* :func:`NetworkingSockets.GetConnectionName`
* :func:`NetworkingSockets.GetConnectionRealTimeStatus`
* :func:`NetworkingSockets.GetConnectionUserData`
* :func:`NetworkingSockets.GetDetailedConnectionStatus`
* :func:`NetworkingSockets.GetFakeIP`
* :func:`NetworkingSockets.GetHostedDedicatedServerPOPID`
* :func:`NetworkingSockets.GetHostedDedicatedServerPort`
* :func:`NetworkingSockets.GetIdentity`
* :func:`NetworkingSockets.GetListenSocketAddress`
* :func:`NetworkingSockets.GetRemoteFakeIPForConnection`
* :func:`NetworkingSockets.InitAuthentication`
* :func:`NetworkingSockets.ReceiveMessagesOnConnection`
* :func:`NetworkingSockets.ReceiveMessagesOnPollGroup`
* :func:`NetworkingSockets.ResetIdentity`
* :func:`NetworkingSockets.RunCallbacks`
* :func:`NetworkingSockets.SendMessageToConnection`
* :func:`NetworkingSockets.SendMessages`
* :func:`NetworkingSockets.SetConnectionName`
* :func:`NetworkingSockets.SetConnectionPollGroup`
* :func:`NetworkingSockets.SetConnectionUserData`

List of Callbacks
-----------------

* :func:`NetworkingSockets.OnSteamNetConnectionStatusChangedCallback`
* :func:`NetworkingSockets.OnSteamNetAuthenticationStatus`
* :func:`NetworkingSockets.OnSteamNetworkingFakeIPResult`

Function Reference
------------------

.. function:: NetworkingSockets.AcceptConnection(hConn)

    🤖 **Auto-generated binding**

    :param int - HSteamNetConnection hConn:
    :returns: (int - EResult) Return value
    :SteamWorks: `AcceptConnection <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#AcceptConnection>`_

**Example**::

    local result = Steam.NetworkingSockets.AcceptConnection(hConn)
    if result ~= Steam.k_EResultOK then
        print('Failed to accept connection:', result)
    end

.. function:: NetworkingSockets.BeginAsyncRequestFakeIP(nNumPorts)

    🤖 **Auto-generated binding**

    :param int nNumPorts:
    :returns: (bool) Return value
    :SteamWorks: `BeginAsyncRequestFakeIP <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#BeginAsyncRequestFakeIP>`_

.. function:: NetworkingSockets.CloseConnection(hPeer, nReason, pszDebug, bEnableLinger)

    🤖 **Auto-generated binding**

    :param int - HSteamNetConnection hPeer:
    :param int nReason:
    :param str? pszDebug:
    :param bool bEnableLinger:
    :returns: (bool) Return value
    :SteamWorks: `CloseConnection <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CloseConnection>`_

**Example**::

    Steam.NetworkingSockets.CloseConnection(hConn, 0, 'Player left', false)

.. function:: NetworkingSockets.CloseListenSocket(hSocket)

    🤖 **Auto-generated binding**

    :param int - HSteamListenSocket hSocket:
    :returns: (bool) Return value
    :SteamWorks: `CloseListenSocket <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CloseListenSocket>`_

**Example**::

    Steam.NetworkingSockets.CloseListenSocket(hListenSocket)

.. function:: NetworkingSockets.ConfigureConnectionLanes(hConn, nNumLanes, pLanePriorities, pLaneWeights)

    🤖 **Auto-generated binding**

    :param int - HSteamNetConnection hConn:
    :param int nNumLanes: size of the input arrays ``pLanePriorities`` and ``pLaneWeights``
    :param int[]? pLanePriorities:
    :param int[]? pLaneWeights:
    :returns: (int - EResult) Return value
    :SteamWorks: `ConfigureConnectionLanes <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#ConfigureConnectionLanes>`_

.. function:: NetworkingSockets.ConnectByIPAddress(address, nOptions, pOptions)

    🤖 **Auto-generated binding**

    :param address: (:ref:`SteamNetworkingIPAddr <struct-SteamNetworkingIPAddr>`)
    :param int nOptions:
    :param pOptions: (:ref:`SteamNetworkingConfigValue_t <struct-SteamNetworkingConfigValue_t>`)
    :returns: (int - HSteamNetConnection) Return value
    :SteamWorks: `ConnectByIPAddress <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#ConnectByIPAddress>`_

**Example**::

    local addr = Steam.newSteamNetworkingIPAddr {}
    addr:ParseString("192.168.1.100:27015")
    local hConn = Steam.NetworkingSockets.ConnectByIPAddress(addr, 0, nil)

.. function:: NetworkingSockets.ConnectP2P(identityRemote, nRemoteVirtualPort, nOptions, pOptions)

    🤖 **Auto-generated binding**

    :param identityRemote: (:ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>`)
    :param int nRemoteVirtualPort:
    :param int nOptions:
    :param pOptions: (:ref:`SteamNetworkingConfigValue_t <struct-SteamNetworkingConfigValue_t>`)
    :returns: (int - HSteamNetConnection) Return value
    :SteamWorks: `ConnectP2P <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#ConnectP2P>`_

**Example**::

    -- Connect to another player using their Steam identity
    local id = Steam.newSteamNetworkingIdentity {}
    id:setSteamID(friendSteamID)
    local hConn = Steam.NetworkingSockets.ConnectP2P(id, 0, 0, nil)

.. function:: NetworkingSockets.ConnectToHostedDedicatedServer(identityTarget, nRemoteVirtualPort, nOptions, pOptions)

    🤖 **Auto-generated binding**

    :param identityTarget: (:ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>`)
    :param int nRemoteVirtualPort:
    :param int nOptions:
    :param pOptions: (:ref:`SteamNetworkingConfigValue_t <struct-SteamNetworkingConfigValue_t>`)
    :returns: (int - HSteamNetConnection) Return value
    :SteamWorks: `ConnectToHostedDedicatedServer <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#ConnectToHostedDedicatedServer>`_

.. function:: NetworkingSockets.CreateHostedDedicatedServerListenSocket(nLocalVirtualPort, nOptions, pOptions)

    🤖 **Auto-generated binding**

    :param int nLocalVirtualPort:
    :param int nOptions:
    :param pOptions: (:ref:`SteamNetworkingConfigValue_t <struct-SteamNetworkingConfigValue_t>`)
    :returns: (int - HSteamListenSocket) Return value
    :SteamWorks: `CreateHostedDedicatedServerListenSocket <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CreateHostedDedicatedServerListenSocket>`_

.. function:: NetworkingSockets.CreateListenSocketIP(localAddress, nOptions, pOptions)

    🤖 **Auto-generated binding**

    :param localAddress: (:ref:`SteamNetworkingIPAddr <struct-SteamNetworkingIPAddr>`)
    :param int nOptions:
    :param pOptions: (:ref:`SteamNetworkingConfigValue_t <struct-SteamNetworkingConfigValue_t>`)
    :returns: (int - HSteamListenSocket) Return value
    :SteamWorks: `CreateListenSocketIP <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CreateListenSocketIP>`_

**Example**::

    -- Listen on all interfaces, port 27015
    local addr = Steam.newSteamNetworkingIPAddr {}
    addr:SetIPv6LocalHost(27015)
    local hSocket = Steam.NetworkingSockets.CreateListenSocketIP(addr, 0, nil)

.. function:: NetworkingSockets.CreateListenSocketP2P(nLocalVirtualPort, nOptions, pOptions)

    🤖 **Auto-generated binding**

    :param int nLocalVirtualPort:
    :param int nOptions:
    :param pOptions: (:ref:`SteamNetworkingConfigValue_t <struct-SteamNetworkingConfigValue_t>`)
    :returns: (int - HSteamListenSocket) Return value
    :SteamWorks: `CreateListenSocketP2P <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CreateListenSocketP2P>`_

**Example**::

    -- Create a P2P listen socket on virtual port 0
    local hSocket = Steam.NetworkingSockets.CreateListenSocketP2P(0, 0, nil)

.. function:: NetworkingSockets.CreateListenSocketP2PFakeIP(idxFakePort, nOptions, pOptions)

    🤖 **Auto-generated binding**

    :param int idxFakePort:
    :param int nOptions:
    :param pOptions: (:ref:`SteamNetworkingConfigValue_t <struct-SteamNetworkingConfigValue_t>`)
    :returns: (int - HSteamListenSocket) Return value
    :SteamWorks: `CreateListenSocketP2PFakeIP <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CreateListenSocketP2PFakeIP>`_

.. function:: NetworkingSockets.CreatePollGroup()

    🤖 **Auto-generated binding**

    :returns: (int - HSteamNetPollGroup) Return value
    :SteamWorks: `CreatePollGroup <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CreatePollGroup>`_

**Example**::

    local hPollGroup = Steam.NetworkingSockets.CreatePollGroup()
    -- Add connections to the poll group
    Steam.NetworkingSockets.SetConnectionPollGroup(hConn, hPollGroup)

.. function:: NetworkingSockets.CreateSocketPair(bUseNetworkLoopback, pIdentity1, pIdentity2)

    🤖 **Auto-generated binding**

    :param bool bUseNetworkLoopback:
    :param pIdentity1: (:ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>`)
    :param pIdentity2: (:ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>`)
    :returns: (bool) Return value
    :returns: (int) ``pOutConnection1``
    :returns: (int) ``pOutConnection2``
    :SteamWorks: `CreateSocketPair <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CreateSocketPair>`_

    **Signature differences from C++ API:**

    * Parameter ``pOutConnection1`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.
    * Parameter ``pOutConnection2`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: NetworkingSockets.DestroyPollGroup(hPollGroup)

    🤖 **Auto-generated binding**

    :param int - HSteamNetPollGroup hPollGroup:
    :returns: (bool) Return value
    :SteamWorks: `DestroyPollGroup <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#DestroyPollGroup>`_

**Example**::

    Steam.NetworkingSockets.DestroyPollGroup(hPollGroup)

.. function:: NetworkingSockets.FlushMessagesOnConnection(hConn)

    🤖 **Auto-generated binding**

    :param int - HSteamNetConnection hConn:
    :returns: (int - EResult) Return value
    :SteamWorks: `FlushMessagesOnConnection <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#FlushMessagesOnConnection>`_

**Example**::

    Steam.NetworkingSockets.FlushMessagesOnConnection(hConn)

.. function:: NetworkingSockets.GetAuthenticationStatus()

    🤖 **Auto-generated binding**

    :returns: (int - ESteamNetworkingAvailability) Return value
    :returns: (:ref:`SteamNetAuthenticationStatus_t <struct-SteamNetAuthenticationStatus_t>`) ``pDetails``
    :SteamWorks: `GetAuthenticationStatus <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetAuthenticationStatus>`_

    **Signature differences from C++ API:**

    * Parameter ``pDetails`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: NetworkingSockets.GetConnectionInfo(hConn)

    🤖 **Auto-generated binding**

    :param int - HSteamNetConnection hConn:
    :returns: (bool) Return value
    :returns: (:ref:`SteamNetConnectionInfo_t <struct-SteamNetConnectionInfo_t>`) ``pInfo``
    :SteamWorks: `GetConnectionInfo <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetConnectionInfo>`_

    **Signature differences from C++ API:**

    * Parameter ``pInfo`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    local ok, info = Steam.NetworkingSockets.GetConnectionInfo(hConn)
    if ok then
        print('Connection state:', info.m_eState)
    end

.. function:: NetworkingSockets.GetConnectionName(hPeer, nMaxLen)

    🤖 **Auto-generated binding**

    :param int - HSteamNetConnection hPeer:
    :param int? nMaxLen: size of the buffer to allocate for ``pszName``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (bool) Return value
    :returns: (str) ``pszName``
    :SteamWorks: `GetConnectionName <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetConnectionName>`_

    **Signature differences from C++ API:**

    * Parameter ``pszName`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: NetworkingSockets.GetConnectionRealTimeStatus(hConn, nLanes)

    🤖 **Auto-generated binding**

    :param int - HSteamNetConnection hConn:
    :param int nLanes:
    :returns: (int - EResult) Return value
    :returns: (:ref:`SteamNetConnectionRealTimeStatus_t <struct-SteamNetConnectionRealTimeStatus_t>`) ``pStatus``
    :returns: (:ref:`SteamNetConnectionRealTimeLaneStatus_t <struct-SteamNetConnectionRealTimeLaneStatus_t>`) ``pLanes``
    :SteamWorks: `GetConnectionRealTimeStatus <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetConnectionRealTimeStatus>`_

    **Signature differences from C++ API:**

    * Parameter ``pStatus`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.
    * Parameter ``pLanes`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: NetworkingSockets.GetConnectionUserData(hPeer)

    🤖 **Auto-generated binding**

    :param int - HSteamNetConnection hPeer:
    :returns: (uint64) Return value
    :SteamWorks: `GetConnectionUserData <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetConnectionUserData>`_

**Example**::

    local playerIndex = Steam.NetworkingSockets.GetConnectionUserData(hConn)

.. function:: NetworkingSockets.GetDetailedConnectionStatus(hConn, cbBuf)

    🤖 **Auto-generated binding**

    :param int - HSteamNetConnection hConn:
    :param int? cbBuf: size of the buffer to allocate for ``pszBuf``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (int) Return value
    :returns: (str) ``pszBuf``
    :SteamWorks: `GetDetailedConnectionStatus <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetDetailedConnectionStatus>`_

    **Signature differences from C++ API:**

    * Parameter ``pszBuf`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: NetworkingSockets.GetFakeIP(idxFirstPort)

    🤖 **Auto-generated binding**

    :param int idxFirstPort:
    :returns: (:ref:`SteamNetworkingFakeIPResult_t <struct-SteamNetworkingFakeIPResult_t>`) ``pInfo``
    :SteamWorks: `GetFakeIP <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetFakeIP>`_

    **Signature differences from C++ API:**

    * Parameter ``pInfo`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: NetworkingSockets.GetHostedDedicatedServerPOPID()

    🤖 **Auto-generated binding**

    :returns: (int - SteamNetworkingPOPID) Return value
    :SteamWorks: `GetHostedDedicatedServerPOPID <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetHostedDedicatedServerPOPID>`_

.. function:: NetworkingSockets.GetHostedDedicatedServerPort()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetHostedDedicatedServerPort <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetHostedDedicatedServerPort>`_

.. function:: NetworkingSockets.GetIdentity()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :returns: (:ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>`) ``pIdentity``
    :SteamWorks: `GetIdentity <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetIdentity>`_

    **Signature differences from C++ API:**

    * Parameter ``pIdentity`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    local ok, identity = Steam.NetworkingSockets.GetIdentity()
    if ok then
        print('Local identity:', identity)
    end

.. function:: NetworkingSockets.GetListenSocketAddress(hSocket)

    🤖 **Auto-generated binding**

    :param int - HSteamListenSocket hSocket:
    :returns: (bool) Return value
    :returns: (:ref:`SteamNetworkingIPAddr <struct-SteamNetworkingIPAddr>`) ``address``
    :SteamWorks: `GetListenSocketAddress <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetListenSocketAddress>`_

    **Signature differences from C++ API:**

    * Parameter ``address`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: NetworkingSockets.GetRemoteFakeIPForConnection(hConn)

    🤖 **Auto-generated binding**

    :param int - HSteamNetConnection hConn:
    :returns: (int - EResult) Return value
    :returns: (:ref:`SteamNetworkingIPAddr <struct-SteamNetworkingIPAddr>`) ``pOutAddr``
    :SteamWorks: `GetRemoteFakeIPForConnection <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetRemoteFakeIPForConnection>`_

    **Signature differences from C++ API:**

    * Parameter ``pOutAddr`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: NetworkingSockets.InitAuthentication()

    🤖 **Auto-generated binding**

    :returns: (int - ESteamNetworkingAvailability) Return value
    :SteamWorks: `InitAuthentication <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#InitAuthentication>`_

**Example**::

    local status = Steam.NetworkingSockets.InitAuthentication()
    print('Auth init status:', status)

.. function:: NetworkingSockets.ReceiveMessagesOnConnection(hConn, nMaxMessages)

    ✍️ **Manually implemented**

    :param int hConn: Connection handle.
    :param int nMaxMessages: size of the buffer to allocate for ``ppOutMessages``
    :returns: (int) Number of messages received, or -1 if the handle is invalid.
    :returns: (SteamNetworkingMessage_t[]) Table of received messages, ``ppOutMessages``. Remember to call ``Release`` on all of them after using.
    :SteamWorks: `ReceiveMessagesOnConnection <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#ReceiveMessagesOnConnection>`_

    Receives messages that have been sent to a connection.

    **Signature differences from C++ API:**

    * Parameter ``ppOutMessages`` is not a parameter in Lua — it is an output-only array in C++ and is returned as a second return value.

**Example**::

    local count, msgs = Steam.NetworkingSockets.ReceiveMessagesOnConnection(hConn, 32)
    for i = 1, count do
        local msg = msgs[i]
        processMessage(msg.m_pData, msg.m_cbSize)
        msg:Release()
    end

.. function:: NetworkingSockets.ReceiveMessagesOnPollGroup(hPollGroup, nMaxMessages)

    ✍️ **Manually implemented**

    :param int hPollGroup: Poll group handle.
    :param int nMaxMessages: size of the buffer to allocate for ``ppOutMessages``
    :returns: (int) Number of messages received, or -1 if the handle is invalid.
    :returns: (SteamNetworkingMessage_t[]) Table of received messages, ``ppOutMessages``. Remember to call ``Release`` on all of them after using.
    :SteamWorks: `ReceiveMessagesOnPollGroup <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#ReceiveMessagesOnPollGroup>`_

    Receives messages that have arrived on any connection in a poll group.

    **Signature differences from C++ API:**

    * Parameter ``ppOutMessages`` is not a parameter in Lua — it is an output-only array in C++ and is returned as a second return value.

**Example**::

    local count, msgs = Steam.NetworkingSockets.ReceiveMessagesOnPollGroup(hPollGroup, 64)
    for i = 1, count do
        local msg = msgs[i]
        handleMessage(msg.m_conn, msg.m_pData, msg.m_cbSize)
        msg:Release()
    end

.. function:: NetworkingSockets.ResetIdentity(pIdentity)

    🤖 **Auto-generated binding**

    :param pIdentity: (:ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>`)
    :SteamWorks: `ResetIdentity <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#ResetIdentity>`_

.. function:: NetworkingSockets.RunCallbacks()

    🤖 **Auto-generated binding**

    :SteamWorks: `RunCallbacks <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#RunCallbacks>`_

.. function:: NetworkingSockets.SendMessageToConnection(hConn, pData, cbData, nSendFlags)

    🤖 **Auto-generated binding**

    :param int - HSteamNetConnection hConn:
    :param str? pData:
    :param int cbData: size of the input array ``pData``
    :param int nSendFlags:
    :returns: (int - EResult) Return value
    :returns: (uint64) ``pOutMessageNumber``
    :SteamWorks: `SendMessageToConnection <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#SendMessageToConnection>`_

    **Signature differences from C++ API:**

    * Parameter ``pOutMessageNumber`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    local data = serializePacket(packet)
    local result = Steam.NetworkingSockets.SendMessageToConnection(
        hConn, data, #data, Steam.k_nSteamNetworkingSend_Reliable)
    if result < 0 then
        print('Send failed:', result)
    end

.. function:: NetworkingSockets.SendMessages(nMessages, pMessages)

    ✍️ **Manually implemented**

    :param int nMessages: size of the array ``pMessages``
    :param SteamNetworkingMessage_t[] pMessages: array of SteamNetworkingMessage_t userdata objects to send.
    :returns: (int[]) array of per-message results: positive = message number assigned, negative = EResult error code.
    :SteamWorks: `SendMessages <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#SendMessages>`_

    Sends one or more messages to one or more connections in a single call.

    **Signature differences from C++ API:**

    * Parameter ``pOutMessageNumberOrResult`` is not a parameter in Lua — it is an output-only array in C++ and is returned as the only return value.

**Example**::

    local msg = Steam.NetworkingUtils.AllocateMessage(#payload)
    msg.m_conn = hConn
    msg.m_nFlags = Steam.k_nSteamNetworkingSend_Reliable
    msg.m_pData = payload
    local results = Steam.NetworkingSockets.SendMessages(1, {msg})
    if results[1] < 0 then
        print('Send failed, EResult:', results[1])
    end

.. function:: NetworkingSockets.SetConnectionName(hPeer, pszName)

    🤖 **Auto-generated binding**

    :param int - HSteamNetConnection hPeer:
    :param str? pszName:
    :SteamWorks: `SetConnectionName <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#SetConnectionName>`_

**Example**::

    Steam.NetworkingSockets.SetConnectionName(hConn, 'Player_' .. playerName)

.. function:: NetworkingSockets.SetConnectionPollGroup(hConn, hPollGroup)

    🤖 **Auto-generated binding**

    :param int - HSteamNetConnection hConn:
    :param int - HSteamNetPollGroup hPollGroup:
    :returns: (bool) Return value
    :SteamWorks: `SetConnectionPollGroup <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#SetConnectionPollGroup>`_

**Example**::

    Steam.NetworkingSockets.SetConnectionPollGroup(hConn, hPollGroup)

.. function:: NetworkingSockets.SetConnectionUserData(hPeer, nUserData)

    🤖 **Auto-generated binding**

    :param int - HSteamNetConnection hPeer:
    :param uint64 nUserData:
    :returns: (bool) Return value
    :SteamWorks: `SetConnectionUserData <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#SetConnectionUserData>`_

**Example**::

    -- Associate a player index with this connection for quick lookup
    Steam.NetworkingSockets.SetConnectionUserData(hConn, playerIndex)


Unimplemented Methods
---------------------

.. function:: NetworkingSockets.ReceivedRelayAuthTicket

    ✋ **Not implemented** - unsupported type: SteamDatagramRelayAuthTicket *
    
    :SteamWorks: `ReceivedRelayAuthTicket <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#ReceivedRelayAuthTicket>`_

.. function:: NetworkingSockets.FindRelayAuthTicketForServer

    ✋ **Not implemented** - unsupported type: SteamDatagramRelayAuthTicket *
    
    :SteamWorks: `FindRelayAuthTicketForServer <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#FindRelayAuthTicketForServer>`_

.. function:: NetworkingSockets.GetHostedDedicatedServerAddress

    ✋ **Not implemented** - unsupported type: SteamDatagramHostedAddress *
    
    :SteamWorks: `GetHostedDedicatedServerAddress <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetHostedDedicatedServerAddress>`_

.. function:: NetworkingSockets.GetGameCoordinatorServerLogin

    ✋ **Not implemented** - unsupported type: SteamDatagramGameCoordinatorServerLogin *
    
    :SteamWorks: `GetGameCoordinatorServerLogin <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetGameCoordinatorServerLogin>`_

.. function:: NetworkingSockets.ConnectP2PCustomSignaling

    ✋ **Not implemented** - unsupported type: ISteamNetworkingConnectionSignaling *
    
    :SteamWorks: `ConnectP2PCustomSignaling <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#ConnectP2PCustomSignaling>`_

.. function:: NetworkingSockets.ReceivedP2PCustomSignal

    ✋ **Not implemented** - unsupported type: ISteamNetworkingSignalingRecvContext *
    
    :SteamWorks: `ReceivedP2PCustomSignal <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#ReceivedP2PCustomSignal>`_

.. function:: NetworkingSockets.GetCertificateRequest

    ✋ **Not implemented** - unsupported type: SteamNetworkingErrMsg &
    
    :SteamWorks: `GetCertificateRequest <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#GetCertificateRequest>`_

.. function:: NetworkingSockets.SetCertificate

    ✋ **Not implemented** - unsupported type: SteamNetworkingErrMsg &
    
    :SteamWorks: `SetCertificate <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#SetCertificate>`_

.. function:: NetworkingSockets.CreateFakeUDPPort

    ✋ **Not implemented** - unsupported type: ISteamNetworkingFakeUDPPort *
    
    :SteamWorks: `CreateFakeUDPPort <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CreateFakeUDPPort>`_


Callbacks
---------

.. function:: NetworkingSockets.OnSteamNetConnectionStatusChangedCallback

    Callback for `SteamNetConnectionStatusChangedCallback_t <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#SteamNetConnectionStatusChangedCallback_t>`_

    **callback(data)** receives:

    * **data.m_hConn** *(int - HSteamNetConnection)*
    * **data.m_info** *(SteamNetConnectionInfo_t)*
    * **data.m_eOldState** *(int - ESteamNetworkingConnectionState)*

**Example**::

    function Steam.NetworkingSockets.OnSteamNetConnectionStatusChangedCallback(data)
        local state = data.m_info.m_eState
        if state == Steam.k_ESteamNetworkingConnectionState_Connected then
            print('Connected:', data.m_hConn)
        elseif state == Steam.k_ESteamNetworkingConnectionState_ClosedByPeer then
            print('Disconnected:', data.m_hConn)
            Steam.NetworkingSockets.CloseConnection(data.m_hConn, 0, nil, false)
        end
    end

.. function:: NetworkingSockets.OnSteamNetAuthenticationStatus

    Callback for `SteamNetAuthenticationStatus_t <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#SteamNetAuthenticationStatus_t>`_

    **callback(data)** receives:

    * **data.m_eAvail** *(int - ESteamNetworkingAvailability)*
    * **data.m_debugMsg** *(string)*

.. function:: NetworkingSockets.OnSteamNetworkingFakeIPResult

    Callback for `SteamNetworkingFakeIPResult_t <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#SteamNetworkingFakeIPResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(int - EResult)*
    * **data.m_identity** *(SteamNetworkingIdentity)*
    * **data.m_unIP** *(int)*
    * **data.m_unPorts** *(int)*

