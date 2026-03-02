################
ISteamNetworking
################

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✍️ are manually implemented and methods marked with ✋ are currently not implemented.

.. note::
   Overloaded Steam methods are exposed as distinct Lua functions using a type suffix (for example ``GetStatInt32`` and ``SetStatFloat``).

List of Functions
-----------------

* :func:`Networking.AcceptP2PSessionWithUser`
* :func:`Networking.AllowP2PPacketRelay`
* :func:`Networking.CloseP2PChannelWithUser`
* :func:`Networking.CloseP2PSessionWithUser`
* :func:`Networking.CreateConnectionSocket`
* :func:`Networking.CreateListenSocket`
* :func:`Networking.CreateP2PConnectionSocket`
* :func:`Networking.DestroyListenSocket`
* :func:`Networking.DestroySocket`
* :func:`Networking.GetListenSocketInfo`
* :func:`Networking.GetMaxPacketSize`
* :func:`Networking.GetP2PSessionState`
* :func:`Networking.GetSocketConnectionType`
* :func:`Networking.GetSocketInfo`
* :func:`Networking.IsDataAvailable`
* :func:`Networking.IsDataAvailableOnSocket`
* :func:`Networking.IsP2PPacketAvailable`
* :func:`Networking.ReadP2PPacket`
* :func:`Networking.RetrieveData`
* :func:`Networking.RetrieveDataFromSocket`
* :func:`Networking.SendDataOnSocket`
* :func:`Networking.SendP2PPacket`

List of Callbacks
-----------------

* :func:`Networking.OnP2PSessionRequest`
* :func:`Networking.OnP2PSessionConnectFail`
* :func:`Networking.OnSocketStatusCallback`

Function Reference
------------------

.. function:: Networking.AcceptP2PSessionWithUser(steamIDRemote)

    🤖 **Auto-generated binding**

    :param uint64 steamIDRemote:
    :returns: (bool) Return value
    :SteamWorks: `AcceptP2PSessionWithUser <https://partner.steamgames.com/doc/api/ISteamNetworking#AcceptP2PSessionWithUser>`_

**Example**::

    function Steam.Networking.OnP2PSessionRequest(data)
        -- Accept connection from known players only
        if isKnownPlayer(data.m_steamIDRemote) then
            Steam.Networking.AcceptP2PSessionWithUser(data.m_steamIDRemote)
        end
    end

.. function:: Networking.AllowP2PPacketRelay(bAllow)

    🤖 **Auto-generated binding**

    :param bool bAllow:
    :returns: (bool) Return value
    :SteamWorks: `AllowP2PPacketRelay <https://partner.steamgames.com/doc/api/ISteamNetworking#AllowP2PPacketRelay>`_

**Example**::

    Steam.Networking.AllowP2PPacketRelay(true)

.. function:: Networking.CloseP2PChannelWithUser(steamIDRemote, nChannel)

    🤖 **Auto-generated binding**

    :param uint64 steamIDRemote:
    :param int nChannel:
    :returns: (bool) Return value
    :SteamWorks: `CloseP2PChannelWithUser <https://partner.steamgames.com/doc/api/ISteamNetworking#CloseP2PChannelWithUser>`_

.. function:: Networking.CloseP2PSessionWithUser(steamIDRemote)

    🤖 **Auto-generated binding**

    :param uint64 steamIDRemote:
    :returns: (bool) Return value
    :SteamWorks: `CloseP2PSessionWithUser <https://partner.steamgames.com/doc/api/ISteamNetworking#CloseP2PSessionWithUser>`_

**Example**::

    -- Clean up when a player leaves
    Steam.Networking.CloseP2PSessionWithUser(playerSteamID)

.. function:: Networking.CreateConnectionSocket(nIP, nPort, nTimeoutSec)

    🤖 **Auto-generated binding**

    :param nIP: (:ref:`SteamIPAddress_t <struct-SteamIPAddress_t>`)
    :param int nPort:
    :param int nTimeoutSec:
    :returns: (int) Return value
    :SteamWorks: `CreateConnectionSocket <https://partner.steamgames.com/doc/api/ISteamNetworking#CreateConnectionSocket>`_

.. function:: Networking.CreateListenSocket(nVirtualP2PPort, nIP, nPort, bAllowUseOfPacketRelay)

    🤖 **Auto-generated binding**

    :param int nVirtualP2PPort:
    :param nIP: (:ref:`SteamIPAddress_t <struct-SteamIPAddress_t>`)
    :param int nPort:
    :param bool bAllowUseOfPacketRelay:
    :returns: (int) Return value
    :SteamWorks: `CreateListenSocket <https://partner.steamgames.com/doc/api/ISteamNetworking#CreateListenSocket>`_

.. function:: Networking.CreateP2PConnectionSocket(steamIDTarget, nVirtualPort, nTimeoutSec, bAllowUseOfPacketRelay)

    🤖 **Auto-generated binding**

    :param uint64 steamIDTarget:
    :param int nVirtualPort:
    :param int nTimeoutSec:
    :param bool bAllowUseOfPacketRelay:
    :returns: (int) Return value
    :SteamWorks: `CreateP2PConnectionSocket <https://partner.steamgames.com/doc/api/ISteamNetworking#CreateP2PConnectionSocket>`_

.. function:: Networking.DestroyListenSocket(hSocket, bNotifyRemoteEnd)

    🤖 **Auto-generated binding**

    :param int hSocket:
    :param bool bNotifyRemoteEnd:
    :returns: (bool) Return value
    :SteamWorks: `DestroyListenSocket <https://partner.steamgames.com/doc/api/ISteamNetworking#DestroyListenSocket>`_

.. function:: Networking.DestroySocket(hSocket, bNotifyRemoteEnd)

    🤖 **Auto-generated binding**

    :param int hSocket:
    :param bool bNotifyRemoteEnd:
    :returns: (bool) Return value
    :SteamWorks: `DestroySocket <https://partner.steamgames.com/doc/api/ISteamNetworking#DestroySocket>`_

.. function:: Networking.GetListenSocketInfo(hListenSocket)

    🤖 **Auto-generated binding**

    :param int hListenSocket:
    :returns: (bool) Return value
    :returns: (:ref:`SteamIPAddress_t <struct-SteamIPAddress_t>`) ``pnIP``
    :returns: (int) ``pnPort``
    :SteamWorks: `GetListenSocketInfo <https://partner.steamgames.com/doc/api/ISteamNetworking#GetListenSocketInfo>`_

    **Signature differences from C++ API:**

    * Parameter ``pnIP`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pnPort`` is no longer a paramer, and is instead an additional return value

.. function:: Networking.GetMaxPacketSize(hSocket)

    🤖 **Auto-generated binding**

    :param int hSocket:
    :returns: (int) Return value
    :SteamWorks: `GetMaxPacketSize <https://partner.steamgames.com/doc/api/ISteamNetworking#GetMaxPacketSize>`_

.. function:: Networking.GetP2PSessionState(steamIDRemote)

    🤖 **Auto-generated binding**

    :param uint64 steamIDRemote:
    :returns: (bool) Return value
    :returns: (:ref:`P2PSessionState_t <struct-P2PSessionState_t>`) ``pConnectionState``
    :SteamWorks: `GetP2PSessionState <https://partner.steamgames.com/doc/api/ISteamNetworking#GetP2PSessionState>`_

    **Signature differences from C++ API:**

    * Parameter ``pConnectionState`` is no longer a paramer, and is instead an additional return value

**Example**::

    local ok, state = Steam.Networking.GetP2PSessionState(playerSteamID)
    if ok then
        print('Connecting:', state.m_bConnecting ~= 0)
        print('Connected:', state.m_bConnectionActive ~= 0)
    end

.. function:: Networking.GetSocketConnectionType(hSocket)

    🤖 **Auto-generated binding**

    :param int hSocket:
    :returns: (int) Return value
    :SteamWorks: `GetSocketConnectionType <https://partner.steamgames.com/doc/api/ISteamNetworking#GetSocketConnectionType>`_

.. function:: Networking.GetSocketInfo(hSocket)

    🤖 **Auto-generated binding**

    :param int hSocket:
    :returns: (bool) Return value
    :returns: (uint64) ``pSteamIDRemote``
    :returns: (int) ``peSocketStatus``
    :returns: (:ref:`SteamIPAddress_t <struct-SteamIPAddress_t>`) ``punIPRemote``
    :returns: (int) ``punPortRemote``
    :SteamWorks: `GetSocketInfo <https://partner.steamgames.com/doc/api/ISteamNetworking#GetSocketInfo>`_

    **Signature differences from C++ API:**

    * Parameter ``pSteamIDRemote`` is no longer a paramer, and is instead an additional return value
    * Parameter ``peSocketStatus`` is no longer a paramer, and is instead an additional return value
    * Parameter ``punIPRemote`` is no longer a paramer, and is instead an additional return value
    * Parameter ``punPortRemote`` is no longer a paramer, and is instead an additional return value

.. function:: Networking.IsDataAvailable(hListenSocket)

    🤖 **Auto-generated binding**

    :param int hListenSocket:
    :returns: (bool) Return value
    :returns: (int) ``pcubMsgSize``
    :returns: (int) ``phSocket``
    :SteamWorks: `IsDataAvailable <https://partner.steamgames.com/doc/api/ISteamNetworking#IsDataAvailable>`_

    **Signature differences from C++ API:**

    * Parameter ``pcubMsgSize`` is no longer a paramer, and is instead an additional return value
    * Parameter ``phSocket`` is no longer a paramer, and is instead an additional return value

.. function:: Networking.IsDataAvailableOnSocket(hSocket)

    🤖 **Auto-generated binding**

    :param int hSocket:
    :returns: (bool) Return value
    :returns: (int) ``pcubMsgSize``
    :SteamWorks: `IsDataAvailableOnSocket <https://partner.steamgames.com/doc/api/ISteamNetworking#IsDataAvailableOnSocket>`_

    **Signature differences from C++ API:**

    * Parameter ``pcubMsgSize`` is no longer a paramer, and is instead an additional return value

.. function:: Networking.IsP2PPacketAvailable(nChannel)

    🤖 **Auto-generated binding**

    :param int nChannel:
    :returns: (bool) Return value
    :returns: (int) ``pcubMsgSize``
    :SteamWorks: `IsP2PPacketAvailable <https://partner.steamgames.com/doc/api/ISteamNetworking#IsP2PPacketAvailable>`_

    **Signature differences from C++ API:**

    * Parameter ``pcubMsgSize`` is no longer a paramer, and is instead an additional return value

**Example**::

    while Steam.Networking.IsP2PPacketAvailable(0) do
        local data, senderID = Steam.Networking.ReadP2PPacket(4096, 0)
        if data then
            handlePacket(senderID, data)
        end
    end

.. function:: Networking.ReadP2PPacket(cubDest, nChannel)

    🤖 **Auto-generated binding**

    :param int cubDest: size of the buffer to be allocated to hold the return value ``pubDest``
    :param int nChannel:
    :returns: (bool) Return value
    :returns: (str) ``pubDest``
    :returns: (int) ``pcubMsgSize``
    :returns: (uint64) ``psteamIDRemote``
    :SteamWorks: `ReadP2PPacket <https://partner.steamgames.com/doc/api/ISteamNetworking#ReadP2PPacket>`_

    **Signature differences from C++ API:**

    * Parameter ``pubDest`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pcubMsgSize`` is no longer a paramer, and is instead an additional return value
    * Parameter ``psteamIDRemote`` is no longer a paramer, and is instead an additional return value

    **Notes:**

    * See :func:`Networking.IsP2PPacketAvailable`'s example.

.. function:: Networking.RetrieveData(hListenSocket, cubDest)

    🤖 **Auto-generated binding**

    :param int hListenSocket:
    :param int cubDest: size of the buffer to be allocated to hold the return value ``pubDest``
    :returns: (bool) Return value
    :returns: (str) ``pubDest``
    :returns: (int) ``pcubMsgSize``
    :returns: (int) ``phSocket``
    :SteamWorks: `RetrieveData <https://partner.steamgames.com/doc/api/ISteamNetworking#RetrieveData>`_

    **Signature differences from C++ API:**

    * Parameter ``pubDest`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pcubMsgSize`` is no longer a paramer, and is instead an additional return value
    * Parameter ``phSocket`` is no longer a paramer, and is instead an additional return value

.. function:: Networking.RetrieveDataFromSocket(hSocket, cubDest)

    🤖 **Auto-generated binding**

    :param int hSocket:
    :param int cubDest: size of the buffer to be allocated to hold the return value ``pubDest``
    :returns: (bool) Return value
    :returns: (str) ``pubDest``
    :returns: (int) ``pcubMsgSize``
    :SteamWorks: `RetrieveDataFromSocket <https://partner.steamgames.com/doc/api/ISteamNetworking#RetrieveDataFromSocket>`_

    **Signature differences from C++ API:**

    * Parameter ``pubDest`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pcubMsgSize`` is no longer a paramer, and is instead an additional return value

.. function:: Networking.SendDataOnSocket(hSocket, pubData, cubData, bReliable)

    🤖 **Auto-generated binding**

    :param int hSocket:
    :param str pubData:
    :param int cubData: size of the input array ``pubData``
    :param bool bReliable:
    :returns: (bool) Return value
    :SteamWorks: `SendDataOnSocket <https://partner.steamgames.com/doc/api/ISteamNetworking#SendDataOnSocket>`_

.. function:: Networking.SendP2PPacket(steamIDRemote, pubData, cubData, eP2PSendType, nChannel)

    🤖 **Auto-generated binding**

    :param uint64 steamIDRemote:
    :param str pubData:
    :param int cubData: size of the input array ``pubData``
    :param int eP2PSendType:
    :param int nChannel:
    :returns: (bool) Return value
    :SteamWorks: `SendP2PPacket <https://partner.steamgames.com/doc/api/ISteamNetworking#SendP2PPacket>`_

**Example**::

    local data = serializeGamePacket(packet)
    Steam.Networking.SendP2PPacket(targetSteamID, data, #data, 'Reliable', 0)


Callbacks
---------

.. function:: Networking.OnP2PSessionRequest

    Callback for `P2PSessionRequest_t <https://partner.steamgames.com/doc/api/ISteamNetworking#P2PSessionRequest_t>`_

    **callback(data)** receives:

    * **data.m_steamIDRemote** *(uint64)*

.. function:: Networking.OnP2PSessionConnectFail

    Callback for `P2PSessionConnectFail_t <https://partner.steamgames.com/doc/api/ISteamNetworking#P2PSessionConnectFail_t>`_

    **callback(data)** receives:

    * **data.m_steamIDRemote** *(uint64)*
    * **data.m_eP2PSessionError** *(int)*

**Example**::

    function Steam.Networking.OnP2PSessionConnectFail(data)
        print('P2P connection failed with', tostring(data.m_steamIDRemote),
              'error:', data.m_eP2PSessionError)
    end

.. function:: Networking.OnSocketStatusCallback

    Callback for `SocketStatusCallback_t <https://partner.steamgames.com/doc/api/ISteamNetworking#SocketStatusCallback_t>`_

    **callback(data)** receives:

    * **data.m_hSocket** *(SNetSocket_t)*
    * **data.m_hListenSocket** *(SNetListenSocket_t)*
    * **data.m_steamIDRemote** *(uint64)*
    * **data.m_eSNetSocketState** *(int)*

