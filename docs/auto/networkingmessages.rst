########################
ISteamNetworkingMessages
########################

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✋ require manual implementation.

List of Functions
-----------------

* :func:`NetworkingMessages.SendMessageToUser`
* :func:`NetworkingMessages.AcceptSessionWithUser`
* :func:`NetworkingMessages.CloseSessionWithUser`
* :func:`NetworkingMessages.CloseChannelWithUser`
* :func:`NetworkingMessages.GetSessionConnectionInfo`

List of Callbacks
-----------------

* :func:`NetworkingMessages.onSteamNetworkingMessagesSessionRequest`
* :func:`NetworkingMessages.onSteamNetworkingMessagesSessionFailed`

Function Reference
------------------

.. function:: NetworkingMessages.SendMessageToUser(identityRemote, pubData, cubData, nSendFlags, nRemoteChannel)

    🤖 **Auto-generated binding**

    :param :ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>` identityRemote:
    :param str pubData:
    :param int cubData:
    :param int nSendFlags:
    :param int nRemoteChannel:
    :returns: (int) Return value
    :SteamWorks: `SendMessageToUser <https://partner.steamgames.com/doc/api/ISteamNetworkingMessages#SendMessageToUser>`_

.. function:: NetworkingMessages.AcceptSessionWithUser(identityRemote)

    🤖 **Auto-generated binding**

    :param :ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>` identityRemote:
    :returns: (bool) Return value
    :SteamWorks: `AcceptSessionWithUser <https://partner.steamgames.com/doc/api/ISteamNetworkingMessages#AcceptSessionWithUser>`_

.. function:: NetworkingMessages.CloseSessionWithUser(identityRemote)

    🤖 **Auto-generated binding**

    :param :ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>` identityRemote:
    :returns: (bool) Return value
    :SteamWorks: `CloseSessionWithUser <https://partner.steamgames.com/doc/api/ISteamNetworkingMessages#CloseSessionWithUser>`_

.. function:: NetworkingMessages.CloseChannelWithUser(identityRemote, nLocalChannel)

    🤖 **Auto-generated binding**

    :param :ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>` identityRemote:
    :param int nLocalChannel:
    :returns: (bool) Return value
    :SteamWorks: `CloseChannelWithUser <https://partner.steamgames.com/doc/api/ISteamNetworkingMessages#CloseChannelWithUser>`_

.. function:: NetworkingMessages.GetSessionConnectionInfo(identityRemote)

    🤖 **Auto-generated binding**

    :param :ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>` identityRemote:
    :returns: (int) Return value
    :returns: (:ref:`SteamNetConnectionInfo_t <struct-SteamNetConnectionInfo_t>`) Value for `pConnectionInfo`
    :returns: (:ref:`SteamNetConnectionRealTimeStatus_t <struct-SteamNetConnectionRealTimeStatus_t>`) Value for `pQuickStatus`
    :SteamWorks: `GetSessionConnectionInfo <https://partner.steamgames.com/doc/api/ISteamNetworkingMessages#GetSessionConnectionInfo>`_

    **Signature differences from C++ API:**

    * Parameter ``pConnectionInfo`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pQuickStatus`` is no longer a paramer, and is instead an additional return value


Unimplemented Methods
---------------------

.. function:: NetworkingMessages.receiveMessagesOnChannel

    ✋ **Not implemented** - manual: SteamNetworkingMessage_t out-array; not yet implemented
    
    :SteamWorks: `ReceiveMessagesOnChannel <https://partner.steamgames.com/doc/api/ISteamNetworkingMessages#ReceiveMessagesOnChannel>`_


Callbacks
---------

.. function:: NetworkingMessages.onSteamNetworkingMessagesSessionRequest

    Callback for `SteamNetworkingMessagesSessionRequest_t <https://partner.steamgames.com/doc/api/ISteamNetworkingMessages#SteamNetworkingMessagesSessionRequest_t>`_

    **callback(data)** receives:

    * **data.m_identityRemote** -- m_identityRemote

.. function:: NetworkingMessages.onSteamNetworkingMessagesSessionFailed

    Callback for `SteamNetworkingMessagesSessionFailed_t <https://partner.steamgames.com/doc/api/ISteamNetworkingMessages#SteamNetworkingMessagesSessionFailed_t>`_

    **callback(data)** receives:

    * **data.m_info** -- m_info

