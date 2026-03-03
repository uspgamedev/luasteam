#####################
ISteamNetworkingUtils
#####################

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✍️ are manually implemented and methods marked with ✋ are currently not implemented.

List of Functions
-----------------

* :func:`NetworkingUtils.AllocateMessage`
* :func:`NetworkingUtils.CheckPingDataUpToDate`
* :func:`NetworkingUtils.ConvertPingLocationToString`
* :func:`NetworkingUtils.EstimatePingTimeBetweenTwoLocations`
* :func:`NetworkingUtils.EstimatePingTimeFromLocalHost`
* :func:`NetworkingUtils.GetConfigValueInfo`
* :func:`NetworkingUtils.GetDirectPingToPOP`
* :func:`NetworkingUtils.GetIPv4FakeIPType`
* :func:`NetworkingUtils.GetPOPCount`
* :func:`NetworkingUtils.GetPOPList`
* :func:`NetworkingUtils.GetPingToDataCenter`
* :func:`NetworkingUtils.GetRealIdentityForFakeIP`
* :func:`NetworkingUtils.GetRelayNetworkStatus`
* :func:`NetworkingUtils.InitRelayNetworkAccess`
* :func:`NetworkingUtils.IsFakeIPv4`
* :func:`NetworkingUtils.IterateGenericEditableConfigValues`
* :func:`NetworkingUtils.SetConnectionConfigValueFloat`
* :func:`NetworkingUtils.SetConnectionConfigValueInt32`
* :func:`NetworkingUtils.SetConnectionConfigValueString`
* :func:`NetworkingUtils.SetGlobalCallback_FakeIPResult`
* :func:`NetworkingUtils.SetGlobalCallback_MessagesSessionFailed`
* :func:`NetworkingUtils.SetGlobalCallback_MessagesSessionRequest`
* :func:`NetworkingUtils.SetGlobalCallback_SteamNetAuthenticationStatusChanged`
* :func:`NetworkingUtils.SetGlobalCallback_SteamNetConnectionStatusChanged`
* :func:`NetworkingUtils.SetGlobalCallback_SteamRelayNetworkStatusChanged`
* :func:`NetworkingUtils.SetGlobalConfigValueFloat`
* :func:`NetworkingUtils.SetGlobalConfigValueInt32`
* :func:`NetworkingUtils.SetGlobalConfigValueString`
* :func:`NetworkingUtils.SteamNetworkingIPAddr_GetFakeIPType`
* :func:`NetworkingUtils.SteamNetworkingIPAddr_ParseString`
* :func:`NetworkingUtils.SteamNetworkingIPAddr_ToString`
* :func:`NetworkingUtils.SteamNetworkingIdentity_ParseString`
* :func:`NetworkingUtils.SteamNetworkingIdentity_ToString`

List of Callbacks
-----------------

* :func:`NetworkingUtils.OnSteamRelayNetworkStatus`

Function Reference
------------------

.. function:: NetworkingUtils.AllocateMessage()

    ✍️ **Manually implemented**

    :returns: (SteamNetworkingMessage_t) New message userdata with an empty payload buffer.
    :SteamWorks: `AllocateMessage <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#AllocateMessage>`_

    Allocates a SteamNetworkingMessage_t for use with SendMessages.

    **Signature differences from C++ API:**

    * The ``cbAllocateBuffer`` parameter is not supported. Set ``m_pData`` and ``m_cbSize`` manually.

    **Notes:**

    * Assigning to ``m_pData`` creates a new string in C++, and frees the old one, but does not modify ``m_cbSize`` automatically, so keep it in sync manually.

.. function:: NetworkingUtils.CheckPingDataUpToDate(flMaxAgeSeconds)

    🤖 **Auto-generated binding**

    :param float flMaxAgeSeconds:
    :returns: (bool) Return value
    :SteamWorks: `CheckPingDataUpToDate <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#CheckPingDataUpToDate>`_

**Example**::

    local ok = Steam.NetworkingUtils.CheckPingDataUpToDate(60.0)
    if not ok then
        print('Ping data is stale; refreshing...')
    end

.. function:: NetworkingUtils.ConvertPingLocationToString(location, cchBufSize)

    🤖 **Auto-generated binding**

    :param location: (:ref:`SteamNetworkPingLocation_t <struct-SteamNetworkPingLocation_t>`)
    :param int? cchBufSize: size of the buffer to allocate for ``pszBuf``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (str) ``pszBuf``
    :SteamWorks: `ConvertPingLocationToString <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#ConvertPingLocationToString>`_

    **Signature differences from C++ API:**

    * Parameter ``pszBuf`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: NetworkingUtils.EstimatePingTimeBetweenTwoLocations(location1, location2)

    🤖 **Auto-generated binding**

    :param location1: (:ref:`SteamNetworkPingLocation_t <struct-SteamNetworkPingLocation_t>`)
    :param location2: (:ref:`SteamNetworkPingLocation_t <struct-SteamNetworkPingLocation_t>`)
    :returns: (int) Return value
    :SteamWorks: `EstimatePingTimeBetweenTwoLocations <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#EstimatePingTimeBetweenTwoLocations>`_

.. function:: NetworkingUtils.EstimatePingTimeFromLocalHost(remoteLocation)

    🤖 **Auto-generated binding**

    :param remoteLocation: (:ref:`SteamNetworkPingLocation_t <struct-SteamNetworkPingLocation_t>`)
    :returns: (int) Return value
    :SteamWorks: `EstimatePingTimeFromLocalHost <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#EstimatePingTimeFromLocalHost>`_

.. function:: NetworkingUtils.GetConfigValueInfo(eValue)

    🤖 **Auto-generated binding**

    :param int eValue: ``ESteamNetworkingConfigValue``
    :returns: (str) Return value
    :returns: (int) ``pOutDataType``
    :returns: (int) ``pOutScope``
    :SteamWorks: `GetConfigValueInfo <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#GetConfigValueInfo>`_

    **Signature differences from C++ API:**

    * Parameter ``pOutDataType`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.
    * Parameter ``pOutScope`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: NetworkingUtils.GetDirectPingToPOP(popID)

    🤖 **Auto-generated binding**

    :param int popID: ``SteamNetworkingPOPID``
    :returns: (int) Return value
    :SteamWorks: `GetDirectPingToPOP <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#GetDirectPingToPOP>`_

**Example**::

    local ping = Steam.NetworkingUtils.GetDirectPingToPOP(popID)
    print('Ping to POP:', ping, 'ms')

.. function:: NetworkingUtils.GetIPv4FakeIPType(nIPv4)

    🤖 **Auto-generated binding**

    :param int nIPv4:
    :returns: (int) ``ESteamNetworkingFakeIPType``
    :SteamWorks: `GetIPv4FakeIPType <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#GetIPv4FakeIPType>`_

.. function:: NetworkingUtils.GetPOPCount()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetPOPCount <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#GetPOPCount>`_

**Example**::

    local count = Steam.NetworkingUtils.GetPOPCount()
    print('Steam relay POPs available:', count)

.. function:: NetworkingUtils.GetPOPList(nListSz)

    🤖 **Auto-generated binding**

    :param int? nListSz: size of the buffer to allocate for ``list``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (int) Return value
    :returns: (int[]) ``list``
    :SteamWorks: `GetPOPList <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#GetPOPList>`_

    **Signature differences from C++ API:**

    * Parameter ``list`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: NetworkingUtils.GetPingToDataCenter(popID)

    🤖 **Auto-generated binding**

    :param int popID: ``SteamNetworkingPOPID``
    :returns: (int) Return value
    :returns: (int) ``pViaRelayPoP``
    :SteamWorks: `GetPingToDataCenter <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#GetPingToDataCenter>`_

    **Signature differences from C++ API:**

    * Parameter ``pViaRelayPoP`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: NetworkingUtils.GetRealIdentityForFakeIP(fakeIP)

    🤖 **Auto-generated binding**

    :param fakeIP: (:ref:`SteamNetworkingIPAddr <struct-SteamNetworkingIPAddr>`)
    :returns: (int) ``EResult``
    :returns: (:ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>`) ``pOutRealIdentity``
    :SteamWorks: `GetRealIdentityForFakeIP <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#GetRealIdentityForFakeIP>`_

    **Signature differences from C++ API:**

    * Parameter ``pOutRealIdentity`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: NetworkingUtils.GetRelayNetworkStatus()

    🤖 **Auto-generated binding**

    :returns: (int) ``ESteamNetworkingAvailability``
    :returns: (:ref:`SteamRelayNetworkStatus_t <struct-SteamRelayNetworkStatus_t>`) ``pDetails``
    :SteamWorks: `GetRelayNetworkStatus <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#GetRelayNetworkStatus>`_

    **Signature differences from C++ API:**

    * Parameter ``pDetails`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    local status = Steam.NetworkingUtils.GetRelayNetworkStatus()
    if status == Steam.k_ESteamNetworkingAvailability_Current then
        print('Relay network ready')
    end

.. function:: NetworkingUtils.InitRelayNetworkAccess()

    🤖 **Auto-generated binding**

    :SteamWorks: `InitRelayNetworkAccess <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#InitRelayNetworkAccess>`_

**Example**::

    Steam.NetworkingUtils.InitRelayNetworkAccess()

.. function:: NetworkingUtils.IsFakeIPv4(nIPv4)

    🤖 **Auto-generated binding**

    :param int nIPv4:
    :returns: (bool) Return value
    :SteamWorks: `IsFakeIPv4 <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#IsFakeIPv4>`_

.. function:: NetworkingUtils.IterateGenericEditableConfigValues(eCurrent, bEnumerateDevVars)

    🤖 **Auto-generated binding**

    :param int eCurrent: ``ESteamNetworkingConfigValue``
    :param bool bEnumerateDevVars:
    :returns: (int) ``ESteamNetworkingConfigValue``
    :SteamWorks: `IterateGenericEditableConfigValues <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#IterateGenericEditableConfigValues>`_

.. function:: NetworkingUtils.SetConnectionConfigValueFloat(hConn, eValue, val)

    🤖 **Auto-generated binding**

    :param int hConn: ``HSteamNetConnection``
    :param int eValue: ``ESteamNetworkingConfigValue``
    :param float val:
    :returns: (bool) Return value
    :SteamWorks: `SetConnectionConfigValueFloat <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SetConnectionConfigValueFloat>`_

.. function:: NetworkingUtils.SetConnectionConfigValueInt32(hConn, eValue, val)

    🤖 **Auto-generated binding**

    :param int hConn: ``HSteamNetConnection``
    :param int eValue: ``ESteamNetworkingConfigValue``
    :param int val:
    :returns: (bool) Return value
    :SteamWorks: `SetConnectionConfigValueInt32 <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SetConnectionConfigValueInt32>`_

**Example**::

    -- Override timeout for a specific connection
    Steam.NetworkingUtils.SetConnectionConfigValueInt32(
        hConn, Steam.k_ESteamNetworkingConfig_TimeoutConnected, 60000)

.. function:: NetworkingUtils.SetConnectionConfigValueString(hConn, eValue, val)

    🤖 **Auto-generated binding**

    :param int hConn: ``HSteamNetConnection``
    :param int eValue: ``ESteamNetworkingConfigValue``
    :param str? val:
    :returns: (bool) Return value
    :SteamWorks: `SetConnectionConfigValueString <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SetConnectionConfigValueString>`_

.. function:: NetworkingUtils.SetGlobalCallback_FakeIPResult(callback)

    ✍️ **Manually implemented**

    :param function? callback: Function receiving a :ref:`SteamNetworkingFakeIPResult_t <struct-SteamNetworkingFakeIPResult_t>`. Pass ``nil`` to clear.
    :returns: (bool)
    :SteamWorks: `SetGlobalCallback_FakeIPResult <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SetGlobalCallback_FakeIPResult>`_

    Sets or clears the global callback for fake IP result events.

    **Signature differences from C++ API:**

    * The C++ ``FnSteamNetworkingFakeIPResult`` function pointer is replaced by a Lua function.

.. function:: NetworkingUtils.SetGlobalCallback_MessagesSessionFailed(callback)

    ✍️ **Manually implemented**

    :param function? callback: Function receiving a :ref:`SteamNetworkingMessagesSessionFailed_t <struct-SteamNetworkingMessagesSessionFailed_t>`. Pass ``nil`` to clear.
    :returns: (bool)
    :SteamWorks: `SetGlobalCallback_MessagesSessionFailed <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SetGlobalCallback_MessagesSessionFailed>`_

    Sets or clears the global callback for messages session failed events.

    **Signature differences from C++ API:**

    * The C++ ``FnSteamNetworkingMessagesSessionFailed`` function pointer is replaced by a Lua function.

.. function:: NetworkingUtils.SetGlobalCallback_MessagesSessionRequest(callback)

    ✍️ **Manually implemented**

    :param function? callback: Function receiving a :ref:`SteamNetworkingMessagesSessionRequest_t <struct-SteamNetworkingMessagesSessionRequest_t>`. Pass ``nil`` to clear.
    :returns: (bool)
    :SteamWorks: `SetGlobalCallback_MessagesSessionRequest <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SetGlobalCallback_MessagesSessionRequest>`_

    Sets or clears the global callback for messages session request events.

    **Signature differences from C++ API:**

    * The C++ ``FnSteamNetworkingMessagesSessionRequest`` function pointer is replaced by a Lua function.

.. function:: NetworkingUtils.SetGlobalCallback_SteamNetAuthenticationStatusChanged(callback)

    ✍️ **Manually implemented**

    :param function? callback: Function receiving a :ref:`SteamNetAuthenticationStatus_t <struct-SteamNetAuthenticationStatus_t>`. Pass ``nil`` to clear.
    :returns: (bool)
    :SteamWorks: `SetGlobalCallback_SteamNetAuthenticationStatusChanged <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SetGlobalCallback_SteamNetAuthenticationStatusChanged>`_

    Sets or clears the global callback for Steam network authentication status changes.

    **Signature differences from C++ API:**

    * The C++ ``FnSteamNetAuthenticationStatusChanged`` function pointer is replaced by a Lua function.

.. function:: NetworkingUtils.SetGlobalCallback_SteamNetConnectionStatusChanged(callback)

    ✍️ **Manually implemented**

    :param function? callback: Function receiving a :ref:`SteamNetConnectionStatusChangedCallback_t <struct-SteamNetConnectionStatusChangedCallback_t>`. Pass ``nil`` to clear.
    :returns: (bool)
    :SteamWorks: `SetGlobalCallback_SteamNetConnectionStatusChanged <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SetGlobalCallback_SteamNetConnectionStatusChanged>`_

    Sets or clears the global callback for Steam network connection status changes.

    **Signature differences from C++ API:**

    * The C++ ``FnSteamNetConnectionStatusChanged`` function pointer is replaced by a Lua function.

.. function:: NetworkingUtils.SetGlobalCallback_SteamRelayNetworkStatusChanged(callback)

    ✍️ **Manually implemented**

    :param function? callback: Function receiving a :ref:`SteamRelayNetworkStatus_t <struct-SteamRelayNetworkStatus_t>`. Pass ``nil`` to clear.
    :returns: (bool)
    :SteamWorks: `SetGlobalCallback_SteamRelayNetworkStatusChanged <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SetGlobalCallback_SteamRelayNetworkStatusChanged>`_

    Sets or clears the global callback for Steam relay network status changes.

    **Signature differences from C++ API:**

    * The C++ ``FnSteamRelayNetworkStatusChanged`` function pointer is replaced by a Lua function.

.. function:: NetworkingUtils.SetGlobalConfigValueFloat(eValue, val)

    🤖 **Auto-generated binding**

    :param int eValue: ``ESteamNetworkingConfigValue``
    :param float val:
    :returns: (bool) Return value
    :SteamWorks: `SetGlobalConfigValueFloat <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SetGlobalConfigValueFloat>`_

.. function:: NetworkingUtils.SetGlobalConfigValueInt32(eValue, val)

    🤖 **Auto-generated binding**

    :param int eValue: ``ESteamNetworkingConfigValue``
    :param int val:
    :returns: (bool) Return value
    :SteamWorks: `SetGlobalConfigValueInt32 <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SetGlobalConfigValueInt32>`_

**Example**::

    -- Set send buffer size globally
    Steam.NetworkingUtils.SetGlobalConfigValueInt32(
        Steam.k_ESteamNetworkingConfig_SendBufferSize, 524288)

.. function:: NetworkingUtils.SetGlobalConfigValueString(eValue, val)

    🤖 **Auto-generated binding**

    :param int eValue: ``ESteamNetworkingConfigValue``
    :param str? val:
    :returns: (bool) Return value
    :SteamWorks: `SetGlobalConfigValueString <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SetGlobalConfigValueString>`_

.. function:: NetworkingUtils.SteamNetworkingIPAddr_GetFakeIPType(addr)

    🤖 **Auto-generated binding**

    :param addr: (:ref:`SteamNetworkingIPAddr <struct-SteamNetworkingIPAddr>`)
    :returns: (int) ``ESteamNetworkingFakeIPType``
    :SteamWorks: `SteamNetworkingIPAddr_GetFakeIPType <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SteamNetworkingIPAddr_GetFakeIPType>`_

.. function:: NetworkingUtils.SteamNetworkingIPAddr_ParseString(pszStr)

    🤖 **Auto-generated binding**

    :param str? pszStr:
    :returns: (bool) Return value
    :returns: (:ref:`SteamNetworkingIPAddr <struct-SteamNetworkingIPAddr>`) ``pAddr``
    :SteamWorks: `SteamNetworkingIPAddr_ParseString <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SteamNetworkingIPAddr_ParseString>`_

    **Signature differences from C++ API:**

    * Parameter ``pAddr`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    local ok, addr = Steam.NetworkingUtils.SteamNetworkingIPAddr_ParseString('192.168.1.100:27015')
    if ok then
        print('Parsed IP address successfully')
    end

.. function:: NetworkingUtils.SteamNetworkingIPAddr_ToString(addr, cbBuf, bWithPort)

    🤖 **Auto-generated binding**

    :param addr: (:ref:`SteamNetworkingIPAddr <struct-SteamNetworkingIPAddr>`)
    :param int? cbBuf: size of the buffer to allocate for ``buf``. If ``nil`` then the buffer will be ``NULL``.
    :param bool bWithPort:
    :returns: (str) ``buf``
    :SteamWorks: `SteamNetworkingIPAddr_ToString <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SteamNetworkingIPAddr_ToString>`_

    **Signature differences from C++ API:**

    * Parameter ``buf`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    local str = Steam.NetworkingUtils.SteamNetworkingIPAddr_ToString(addr, 64, true)
    print('Address:', str)

.. function:: NetworkingUtils.SteamNetworkingIdentity_ParseString(pszStr)

    🤖 **Auto-generated binding**

    :param str? pszStr:
    :returns: (bool) Return value
    :returns: (:ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>`) ``pIdentity``
    :SteamWorks: `SteamNetworkingIdentity_ParseString <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SteamNetworkingIdentity_ParseString>`_

    **Signature differences from C++ API:**

    * Parameter ``pIdentity`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    local ok, identity = Steam.NetworkingUtils.SteamNetworkingIdentity_ParseString('steamid:76561197960287930')
    if ok then
        print('Parsed identity successfully')
    end

.. function:: NetworkingUtils.SteamNetworkingIdentity_ToString(identity, cbBuf)

    🤖 **Auto-generated binding**

    :param identity: (:ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>`)
    :param int? cbBuf: size of the buffer to allocate for ``buf``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (str) ``buf``
    :SteamWorks: `SteamNetworkingIdentity_ToString <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SteamNetworkingIdentity_ToString>`_

    **Signature differences from C++ API:**

    * Parameter ``buf`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    local str = Steam.NetworkingUtils.SteamNetworkingIdentity_ToString(identity, 128)
    print('Identity:', str)


Unimplemented Methods
---------------------

.. function:: NetworkingUtils.getLocalPingLocation

    ✋ **Not implemented** - unsupported type: SteamNetworkPingLocation_t &
    
    :SteamWorks: `GetLocalPingLocation <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#GetLocalPingLocation>`_

.. function:: NetworkingUtils.parsePingLocationString

    ✋ **Not implemented** - unsupported type: SteamNetworkPingLocation_t &
    
    :SteamWorks: `ParsePingLocationString <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#ParsePingLocationString>`_

.. function:: NetworkingUtils.getLocalTimestamp

    ✋ **Not implemented** - unsupported type: SteamNetworkingMicroseconds
    
    :SteamWorks: `GetLocalTimestamp <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#GetLocalTimestamp>`_

.. function:: NetworkingUtils.setDebugOutputFunction

    ✋ **Not implemented** - unsupported type: FSteamNetworkingSocketsDebugOutput
    
    :SteamWorks: `SetDebugOutputFunction <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SetDebugOutputFunction>`_

.. function:: NetworkingUtils.setGlobalConfigValuePtr

    ✋ **Not implemented** - unsupported type: void *
    
    :SteamWorks: `SetGlobalConfigValuePtr <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SetGlobalConfigValuePtr>`_

.. function:: NetworkingUtils.setConfigValue

    ✋ **Not implemented** - blocklist: Needs careful dealing with void*
    
    :SteamWorks: `SetConfigValue <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SetConfigValue>`_

.. function:: NetworkingUtils.setConfigValueStruct

    ✋ **Not implemented** - blocklist: Needs careful dealing with void*
    
    :SteamWorks: `SetConfigValueStruct <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SetConfigValueStruct>`_

.. function:: NetworkingUtils.getConfigValue

    ✋ **Not implemented** - unsupported type: void *
    
    :SteamWorks: `GetConfigValue <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#GetConfigValue>`_


Callbacks
---------

.. function:: NetworkingUtils.OnSteamRelayNetworkStatus

    Callback for `SteamRelayNetworkStatus_t <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SteamRelayNetworkStatus_t>`_

    **callback(data)** receives:

    * **data.m_eAvail** *(ESteamNetworkingAvailability)*
    * **data.m_bPingMeasurementInProgress** *(int)*
    * **data.m_eAvailNetworkConfig** *(ESteamNetworkingAvailability)*
    * **data.m_eAvailAnyRelay** *(ESteamNetworkingAvailability)*
    * **data.m_debugMsg** *(string)*

**Example**::

    function Steam.NetworkingUtils.OnSteamRelayNetworkStatus(data)
        if data.m_eAvail == Steam.k_ESteamNetworkingAvailability_Current then
            print('Relay network is ready')
        end
    end

