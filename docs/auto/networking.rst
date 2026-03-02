################
ISteamNetworking
################

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✋ require manual implementation.

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

* :func:`Networking.onP2PSessionRequest`
* :func:`Networking.onP2PSessionConnectFail`
* :func:`Networking.onSocketStatusCallback`

Function Reference
------------------

.. function:: Networking.AcceptP2PSessionWithUser(steamIDRemote)

    🤖 **Auto-generated binding**

    :param uint64 steamIDRemote:
    :returns: (bool) Return value
    :SteamWorks: `AcceptP2PSessionWithUser <https://partner.steamgames.com/doc/api/ISteamNetworking#AcceptP2PSessionWithUser>`_

.. function:: Networking.AllowP2PPacketRelay(bAllow)

    🤖 **Auto-generated binding**

    :param bool bAllow:
    :returns: (bool) Return value
    :SteamWorks: `AllowP2PPacketRelay <https://partner.steamgames.com/doc/api/ISteamNetworking#AllowP2PPacketRelay>`_

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

.. function:: Networking.CreateConnectionSocket(nIP, nPort, nTimeoutSec)

    🤖 **Auto-generated binding**

    :param :ref:`SteamIPAddress_t <struct-SteamIPAddress_t>` nIP:
    :param int nPort:
    :param int nTimeoutSec:
    :returns: (int) Return value
    :SteamWorks: `CreateConnectionSocket <https://partner.steamgames.com/doc/api/ISteamNetworking#CreateConnectionSocket>`_

.. function:: Networking.CreateListenSocket(nVirtualP2PPort, nIP, nPort, bAllowUseOfPacketRelay)

    🤖 **Auto-generated binding**

    :param int nVirtualP2PPort:
    :param :ref:`SteamIPAddress_t <struct-SteamIPAddress_t>` nIP:
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
    :returns: (:ref:`SteamIPAddress_t <struct-SteamIPAddress_t>`) Value for `pnIP`
    :returns: (int) Value for `pnPort`
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
    :returns: (:ref:`P2PSessionState_t <struct-P2PSessionState_t>`) Value for `pConnectionState`
    :SteamWorks: `GetP2PSessionState <https://partner.steamgames.com/doc/api/ISteamNetworking#GetP2PSessionState>`_

    **Signature differences from C++ API:**

    * Parameter ``pConnectionState`` is no longer a paramer, and is instead an additional return value

.. function:: Networking.GetSocketConnectionType(hSocket)

    🤖 **Auto-generated binding**

    :param int hSocket:
    :returns: (int) Return value
    :SteamWorks: `GetSocketConnectionType <https://partner.steamgames.com/doc/api/ISteamNetworking#GetSocketConnectionType>`_

.. function:: Networking.GetSocketInfo(hSocket)

    🤖 **Auto-generated binding**

    :param int hSocket:
    :returns: (bool) Return value
    :returns: (uint64) Value for `pSteamIDRemote`
    :returns: (int) Value for `peSocketStatus`
    :returns: (:ref:`SteamIPAddress_t <struct-SteamIPAddress_t>`) Value for `punIPRemote`
    :returns: (int) Value for `punPortRemote`
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
    :returns: (int) Value for `pcubMsgSize`
    :returns: (int) Value for `phSocket`
    :SteamWorks: `IsDataAvailable <https://partner.steamgames.com/doc/api/ISteamNetworking#IsDataAvailable>`_

    **Signature differences from C++ API:**

    * Parameter ``pcubMsgSize`` is no longer a paramer, and is instead an additional return value
    * Parameter ``phSocket`` is no longer a paramer, and is instead an additional return value

.. function:: Networking.IsDataAvailableOnSocket(hSocket)

    🤖 **Auto-generated binding**

    :param int hSocket:
    :returns: (bool) Return value
    :returns: (int) Value for `pcubMsgSize`
    :SteamWorks: `IsDataAvailableOnSocket <https://partner.steamgames.com/doc/api/ISteamNetworking#IsDataAvailableOnSocket>`_

    **Signature differences from C++ API:**

    * Parameter ``pcubMsgSize`` is no longer a paramer, and is instead an additional return value

.. function:: Networking.IsP2PPacketAvailable(nChannel)

    🤖 **Auto-generated binding**

    :param int nChannel:
    :returns: (bool) Return value
    :returns: (int) Value for `pcubMsgSize`
    :SteamWorks: `IsP2PPacketAvailable <https://partner.steamgames.com/doc/api/ISteamNetworking#IsP2PPacketAvailable>`_

    **Signature differences from C++ API:**

    * Parameter ``pcubMsgSize`` is no longer a paramer, and is instead an additional return value

.. function:: Networking.ReadP2PPacket(cubDest, nChannel)

    🤖 **Auto-generated binding**

    :param int cubDest:
    :param int nChannel:
    :returns: (bool) Return value
    :returns: (str) Value for `pubDest`
    :returns: (int) Value for `pcubMsgSize`
    :returns: (uint64) Value for `psteamIDRemote`
    :SteamWorks: `ReadP2PPacket <https://partner.steamgames.com/doc/api/ISteamNetworking#ReadP2PPacket>`_

    **Signature differences from C++ API:**

    * Parameter ``pubDest`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pcubMsgSize`` is no longer a paramer, and is instead an additional return value
    * Parameter ``psteamIDRemote`` is no longer a paramer, and is instead an additional return value

.. function:: Networking.RetrieveData(hListenSocket, cubDest)

    🤖 **Auto-generated binding**

    :param int hListenSocket:
    :param int cubDest:
    :returns: (bool) Return value
    :returns: (str) Value for `pubDest`
    :returns: (int) Value for `pcubMsgSize`
    :returns: (int) Value for `phSocket`
    :SteamWorks: `RetrieveData <https://partner.steamgames.com/doc/api/ISteamNetworking#RetrieveData>`_

    **Signature differences from C++ API:**

    * Parameter ``pubDest`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pcubMsgSize`` is no longer a paramer, and is instead an additional return value
    * Parameter ``phSocket`` is no longer a paramer, and is instead an additional return value

.. function:: Networking.RetrieveDataFromSocket(hSocket, cubDest)

    🤖 **Auto-generated binding**

    :param int hSocket:
    :param int cubDest:
    :returns: (bool) Return value
    :returns: (str) Value for `pubDest`
    :returns: (int) Value for `pcubMsgSize`
    :SteamWorks: `RetrieveDataFromSocket <https://partner.steamgames.com/doc/api/ISteamNetworking#RetrieveDataFromSocket>`_

    **Signature differences from C++ API:**

    * Parameter ``pubDest`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pcubMsgSize`` is no longer a paramer, and is instead an additional return value

.. function:: Networking.SendDataOnSocket(hSocket, pubData, cubData, bReliable)

    🤖 **Auto-generated binding**

    :param int hSocket:
    :param str pubData:
    :param int cubData:
    :param bool bReliable:
    :returns: (bool) Return value
    :SteamWorks: `SendDataOnSocket <https://partner.steamgames.com/doc/api/ISteamNetworking#SendDataOnSocket>`_

.. function:: Networking.SendP2PPacket(steamIDRemote, pubData, cubData, eP2PSendType, nChannel)

    🤖 **Auto-generated binding**

    :param uint64 steamIDRemote:
    :param str pubData:
    :param int cubData:
    :param int eP2PSendType:
    :param int nChannel:
    :returns: (bool) Return value
    :SteamWorks: `SendP2PPacket <https://partner.steamgames.com/doc/api/ISteamNetworking#SendP2PPacket>`_


Callbacks
---------

.. function:: Networking.onP2PSessionRequest

    Callback for `P2PSessionRequest_t <https://partner.steamgames.com/doc/api/ISteamNetworking#P2PSessionRequest_t>`_

    **callback(data)** receives:

    * **data.m_steamIDRemote** -- m_steamIDRemote

.. function:: Networking.onP2PSessionConnectFail

    Callback for `P2PSessionConnectFail_t <https://partner.steamgames.com/doc/api/ISteamNetworking#P2PSessionConnectFail_t>`_

    **callback(data)** receives:

    * **data.m_steamIDRemote** -- m_steamIDRemote
    * **data.m_eP2PSessionError** -- m_eP2PSessionError

.. function:: Networking.onSocketStatusCallback

    Callback for `SocketStatusCallback_t <https://partner.steamgames.com/doc/api/ISteamNetworking#SocketStatusCallback_t>`_

    **callback(data)** receives:

    * **data.m_hSocket** -- m_hSocket
    * **data.m_hListenSocket** -- m_hListenSocket
    * **data.m_steamIDRemote** -- m_steamIDRemote
    * **data.m_eSNetSocketState** -- m_eSNetSocketState

