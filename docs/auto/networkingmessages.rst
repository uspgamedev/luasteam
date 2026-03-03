########################
ISteamNetworkingMessages
########################

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✍️ are manually implemented and methods marked with ✋ are currently not implemented.

List of Functions
-----------------

* :func:`NetworkingMessages.AcceptSessionWithUser`
* :func:`NetworkingMessages.CloseChannelWithUser`
* :func:`NetworkingMessages.CloseSessionWithUser`
* :func:`NetworkingMessages.GetSessionConnectionInfo`
* :func:`NetworkingMessages.ReceiveMessagesOnChannel`
* :func:`NetworkingMessages.SendMessageToUser`

List of Callbacks
-----------------

* :func:`NetworkingMessages.OnSteamNetworkingMessagesSessionRequest`
* :func:`NetworkingMessages.OnSteamNetworkingMessagesSessionFailed`

Function Reference
------------------

.. function:: NetworkingMessages.AcceptSessionWithUser(identityRemote)

    🤖 **Auto-generated binding**

    :param identityRemote: (:ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>`)
    :returns: (bool) Return value
    :SteamWorks: `AcceptSessionWithUser <https://partner.steamgames.com/doc/api/ISteamNetworkingMessages#AcceptSessionWithUser>`_

**Example**::

    function Steam.NetworkingMessages.OnSteamNetworkingMessagesSessionRequest(data)
        Steam.NetworkingMessages.AcceptSessionWithUser(data.m_identityRemote)
    end

.. function:: NetworkingMessages.CloseChannelWithUser(identityRemote, nLocalChannel)

    🤖 **Auto-generated binding**

    :param identityRemote: (:ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>`)
    :param int nLocalChannel:
    :returns: (bool) Return value
    :SteamWorks: `CloseChannelWithUser <https://partner.steamgames.com/doc/api/ISteamNetworkingMessages#CloseChannelWithUser>`_

.. function:: NetworkingMessages.CloseSessionWithUser(identityRemote)

    🤖 **Auto-generated binding**

    :param identityRemote: (:ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>`)
    :returns: (bool) Return value
    :SteamWorks: `CloseSessionWithUser <https://partner.steamgames.com/doc/api/ISteamNetworkingMessages#CloseSessionWithUser>`_

**Example**::

    local identity = Steam.newSteamNetworkingIdentity {}
    identity:SetSteamID(steam_id)
    Steam.NetworkingMessages.CloseSessionWithUser(identity)

.. function:: NetworkingMessages.GetSessionConnectionInfo(identityRemote)

    🤖 **Auto-generated binding**

    :param identityRemote: (:ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>`)
    :returns: (int) ``ESteamNetworkingConnectionState``
    :returns: (:ref:`SteamNetConnectionInfo_t <struct-SteamNetConnectionInfo_t>`) ``pConnectionInfo``
    :returns: (:ref:`SteamNetConnectionRealTimeStatus_t <struct-SteamNetConnectionRealTimeStatus_t>`) ``pQuickStatus``
    :SteamWorks: `GetSessionConnectionInfo <https://partner.steamgames.com/doc/api/ISteamNetworkingMessages#GetSessionConnectionInfo>`_

    **Signature differences from C++ API:**

    * Parameter ``pConnectionInfo`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.
    * Parameter ``pQuickStatus`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: NetworkingMessages.ReceiveMessagesOnChannel(nLocalChannel, nMaxMessages)

    ✍️ **Manually implemented**

    :param int nLocalChannel: Local channel number to receive messages from.
    :param int nMaxMessages: size of the buffer to allocate for ``ppOutMessages``
    :returns: (int) Number of messages received.
    :returns: (SteamNetworkingMessage_t[]) Table of received messages, ``ppOutMessages``. Remember to call ``Release`` on all of them after using.
    :SteamWorks: `ReceiveMessagesOnChannel <https://partner.steamgames.com/doc/api/ISteamNetworkingMessages#ReceiveMessagesOnChannel>`_

    Receives messages sent via SendMessageToUser on the given channel number.

    **Signature differences from C++ API:**

    * Parameter ``ppOutMessages`` is not a parameter in Lua — it is an output-only array in C++ and is returned as a second return value.

**Example**::

    local count, msgs = Steam.NetworkingMessages.ReceiveMessagesOnChannel(0, 32)
    for i = 1, count do
        local msg = msgs[i]
        processMessage(msg.m_identityPeer, msg.m_pData, msg.m_cbSize)
        msg:Release()
    end

.. function:: NetworkingMessages.SendMessageToUser(identityRemote, pubData, cubData, nSendFlags, nRemoteChannel)

    🤖 **Auto-generated binding**

    :param identityRemote: (:ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>`)
    :param str? pubData:
    :param int cubData: size of the input array ``pubData``
    :param int nSendFlags:
    :param int nRemoteChannel:
    :returns: (int) ``EResult``
    :SteamWorks: `SendMessageToUser <https://partner.steamgames.com/doc/api/ISteamNetworkingMessages#SendMessageToUser>`_

**Example**::

    local identity = Steam.newSteamNetworkingIdentity {}
    identity:ParseString(send_to)
    local data = serializePacket(send_data)
    local result = Steam.NetworkingMessages.SendMessageToUser(
        identity, data, #data, Steam.k_nSteamNetworkingSend_Reliable, 0)
    if result ~= Steam.k_EResultOK then
        print('Send failed:', result)
    end


Unimplemented Methods
---------------------

.. function:: NetworkingMessages.receiveMessagesOnChannel

    ✋ **Not implemented** - blocklist: SteamNetworkingMessage_t out-array; not yet implemented
    
    :SteamWorks: `ReceiveMessagesOnChannel <https://partner.steamgames.com/doc/api/ISteamNetworkingMessages#ReceiveMessagesOnChannel>`_


Callbacks
---------

.. function:: NetworkingMessages.OnSteamNetworkingMessagesSessionRequest

    Callback for `SteamNetworkingMessagesSessionRequest_t <https://partner.steamgames.com/doc/api/ISteamNetworkingMessages#SteamNetworkingMessagesSessionRequest_t>`_

    **callback(data)** receives:

    * **data.m_identityRemote** *(SteamNetworkingIdentity)*

.. function:: NetworkingMessages.OnSteamNetworkingMessagesSessionFailed

    Callback for `SteamNetworkingMessagesSessionFailed_t <https://partner.steamgames.com/doc/api/ISteamNetworkingMessages#SteamNetworkingMessagesSessionFailed_t>`_

    **callback(data)** receives:

    * **data.m_info** *(SteamNetConnectionInfo_t)*

**Example**::

    function Steam.NetworkingMessages.OnSteamNetworkingMessagesSessionFailed(data)
        print('Messages session failed:', data.m_info.m_eEndReason)
    end

