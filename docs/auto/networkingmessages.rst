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

    -- Clean up when a player leaves
    Steam.NetworkingMessages.CloseSessionWithUser(tostring(playerSteamID))

.. function:: NetworkingMessages.GetSessionConnectionInfo(identityRemote)

    🤖 **Auto-generated binding**

    :param identityRemote: (:ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>`)
    :returns: (int) Return value
    :returns: (:ref:`SteamNetConnectionInfo_t <struct-SteamNetConnectionInfo_t>`) ``pConnectionInfo``
    :returns: (:ref:`SteamNetConnectionRealTimeStatus_t <struct-SteamNetConnectionRealTimeStatus_t>`) ``pQuickStatus``
    :SteamWorks: `GetSessionConnectionInfo <https://partner.steamgames.com/doc/api/ISteamNetworkingMessages#GetSessionConnectionInfo>`_

    **Signature differences from C++ API:**

    * Parameter ``pConnectionInfo`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.
    * Parameter ``pQuickStatus`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: NetworkingMessages.SendMessageToUser(identityRemote, pubData, cubData, nSendFlags, nRemoteChannel)

    🤖 **Auto-generated binding**

    :param identityRemote: (:ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>`)
    :param str? pubData:
    :param int cubData: size of the input array ``pubData``
    :param int nSendFlags:
    :param int nRemoteChannel:
    :returns: (int) Return value
    :SteamWorks: `SendMessageToUser <https://partner.steamgames.com/doc/api/ISteamNetworkingMessages#SendMessageToUser>`_

**Example**::

    local data = serializePacket(packet)
    local result = Steam.NetworkingMessages.SendMessageToUser(
        tostring(targetSteamID), data, #data, Steam.k_nSteamNetworkingSend_Reliable, 0)
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

