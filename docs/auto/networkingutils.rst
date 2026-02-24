#####################
ISteamNetworkingUtils
#####################

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✋ require manual implementation.

.. note::
   Overloaded Steam methods are exposed as distinct Lua functions using a type suffix (for example ``GetStatInt32`` and ``SetStatFloat``).

List of Functions
-----------------

* :func:`NetworkingUtils.InitRelayNetworkAccess`
* :func:`NetworkingUtils.EstimatePingTimeBetweenTwoLocations`
* :func:`NetworkingUtils.EstimatePingTimeFromLocalHost`
* :func:`NetworkingUtils.ConvertPingLocationToString`
* :func:`NetworkingUtils.CheckPingDataUpToDate`
* :func:`NetworkingUtils.GetPingToDataCenter`
* :func:`NetworkingUtils.GetDirectPingToPOP`
* :func:`NetworkingUtils.GetPOPCount`
* :func:`NetworkingUtils.GetPOPList`
* :func:`NetworkingUtils.IsFakeIPv4`
* :func:`NetworkingUtils.GetIPv4FakeIPType`
* :func:`NetworkingUtils.GetRealIdentityForFakeIP`
* :func:`NetworkingUtils.SetGlobalConfigValueInt32`
* :func:`NetworkingUtils.SetGlobalConfigValueFloat`
* :func:`NetworkingUtils.SetGlobalConfigValueString`
* :func:`NetworkingUtils.SetConnectionConfigValueInt32`
* :func:`NetworkingUtils.SetConnectionConfigValueFloat`
* :func:`NetworkingUtils.SetConnectionConfigValueString`
* :func:`NetworkingUtils.GetConfigValueInfo`
* :func:`NetworkingUtils.IterateGenericEditableConfigValues`
* :func:`NetworkingUtils.SteamNetworkingIPAddr_ToString`
* :func:`NetworkingUtils.SteamNetworkingIPAddr_ParseString`
* :func:`NetworkingUtils.SteamNetworkingIPAddr_GetFakeIPType`
* :func:`NetworkingUtils.SteamNetworkingIdentity_ToString`
* :func:`NetworkingUtils.SteamNetworkingIdentity_ParseString`

List of Callbacks
-----------------

* :func:`NetworkingUtils.onSteamRelayNetworkStatus`

Function Reference
------------------

.. function:: NetworkingUtils.InitRelayNetworkAccess()

    🤖 **Auto-generated binding**

    :SteamWorks: `InitRelayNetworkAccess <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#InitRelayNetworkAccess>`_

.. function:: NetworkingUtils.EstimatePingTimeBetweenTwoLocations(location1, location2)

    🤖 **Auto-generated binding**

    :param :ref:`SteamNetworkPingLocation_t <struct-SteamNetworkPingLocation_t>` location1:
    :param :ref:`SteamNetworkPingLocation_t <struct-SteamNetworkPingLocation_t>` location2:
    :returns: (int) Return value
    :SteamWorks: `EstimatePingTimeBetweenTwoLocations <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#EstimatePingTimeBetweenTwoLocations>`_

.. function:: NetworkingUtils.EstimatePingTimeFromLocalHost(remoteLocation)

    🤖 **Auto-generated binding**

    :param :ref:`SteamNetworkPingLocation_t <struct-SteamNetworkPingLocation_t>` remoteLocation:
    :returns: (int) Return value
    :SteamWorks: `EstimatePingTimeFromLocalHost <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#EstimatePingTimeFromLocalHost>`_

.. function:: NetworkingUtils.ConvertPingLocationToString(location, cchBufSize)

    🤖 **Auto-generated binding**

    :param :ref:`SteamNetworkPingLocation_t <struct-SteamNetworkPingLocation_t>` location:
    :param int cchBufSize:
    :returns: (str) Value for `pszBuf`
    :SteamWorks: `ConvertPingLocationToString <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#ConvertPingLocationToString>`_

    **Signature differences from C++ API:**

    * Parameter ``pszBuf`` is returned as an additional return value

.. function:: NetworkingUtils.CheckPingDataUpToDate(flMaxAgeSeconds)

    🤖 **Auto-generated binding**

    :param float flMaxAgeSeconds:
    :returns: (bool) Return value
    :SteamWorks: `CheckPingDataUpToDate <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#CheckPingDataUpToDate>`_

.. function:: NetworkingUtils.GetPingToDataCenter(popID)

    🤖 **Auto-generated binding**

    :param int popID:
    :returns: (int) Return value
    :returns: (int) Value for `pViaRelayPoP`
    :SteamWorks: `GetPingToDataCenter <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#GetPingToDataCenter>`_

    **Signature differences from C++ API:**

    * Parameter ``pViaRelayPoP`` is returned as an additional return value

.. function:: NetworkingUtils.GetDirectPingToPOP(popID)

    🤖 **Auto-generated binding**

    :param int popID:
    :returns: (int) Return value
    :SteamWorks: `GetDirectPingToPOP <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#GetDirectPingToPOP>`_

.. function:: NetworkingUtils.GetPOPCount()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetPOPCount <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#GetPOPCount>`_

.. function:: NetworkingUtils.GetPOPList(nListSz)

    🤖 **Auto-generated binding**

    :param int nListSz:
    :returns: (int) Return value
    :returns: (int) Value for `list`
    :SteamWorks: `GetPOPList <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#GetPOPList>`_

    **Signature differences from C++ API:**

    * Parameter ``list`` is returned as an additional return value

.. function:: NetworkingUtils.IsFakeIPv4(nIPv4)

    🤖 **Auto-generated binding**

    :param int nIPv4:
    :returns: (bool) Return value
    :SteamWorks: `IsFakeIPv4 <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#IsFakeIPv4>`_

.. function:: NetworkingUtils.GetIPv4FakeIPType(nIPv4)

    🤖 **Auto-generated binding**

    :param int nIPv4:
    :returns: (int) Return value
    :SteamWorks: `GetIPv4FakeIPType <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#GetIPv4FakeIPType>`_

.. function:: NetworkingUtils.GetRealIdentityForFakeIP(fakeIP)

    🤖 **Auto-generated binding**

    :param :ref:`SteamNetworkingIPAddr <struct-SteamNetworkingIPAddr>` fakeIP:
    :returns: (int) Return value
    :returns: (:ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>`) Value for `pOutRealIdentity`
    :SteamWorks: `GetRealIdentityForFakeIP <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#GetRealIdentityForFakeIP>`_

    **Signature differences from C++ API:**

    * Parameter ``pOutRealIdentity`` is returned as an additional return value

.. function:: NetworkingUtils.SetGlobalConfigValueInt32(eValue, val)

    🤖 **Auto-generated binding**

    :param int eValue:
    :param int val:
    :returns: (bool) Return value
    :SteamWorks: `SetGlobalConfigValueInt32 <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SetGlobalConfigValueInt32>`_

.. function:: NetworkingUtils.SetGlobalConfigValueFloat(eValue, val)

    🤖 **Auto-generated binding**

    :param int eValue:
    :param float val:
    :returns: (bool) Return value
    :SteamWorks: `SetGlobalConfigValueFloat <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SetGlobalConfigValueFloat>`_

.. function:: NetworkingUtils.SetGlobalConfigValueString(eValue, val)

    🤖 **Auto-generated binding**

    :param int eValue:
    :param str val:
    :returns: (bool) Return value
    :SteamWorks: `SetGlobalConfigValueString <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SetGlobalConfigValueString>`_

.. function:: NetworkingUtils.SetConnectionConfigValueInt32(hConn, eValue, val)

    🤖 **Auto-generated binding**

    :param int hConn:
    :param int eValue:
    :param int val:
    :returns: (bool) Return value
    :SteamWorks: `SetConnectionConfigValueInt32 <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SetConnectionConfigValueInt32>`_

.. function:: NetworkingUtils.SetConnectionConfigValueFloat(hConn, eValue, val)

    🤖 **Auto-generated binding**

    :param int hConn:
    :param int eValue:
    :param float val:
    :returns: (bool) Return value
    :SteamWorks: `SetConnectionConfigValueFloat <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SetConnectionConfigValueFloat>`_

.. function:: NetworkingUtils.SetConnectionConfigValueString(hConn, eValue, val)

    🤖 **Auto-generated binding**

    :param int hConn:
    :param int eValue:
    :param str val:
    :returns: (bool) Return value
    :SteamWorks: `SetConnectionConfigValueString <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SetConnectionConfigValueString>`_

.. function:: NetworkingUtils.GetConfigValueInfo(eValue)

    🤖 **Auto-generated binding**

    :param int eValue:
    :returns: (str) Return value
    :returns: (int) Value for `pOutDataType`
    :returns: (int) Value for `pOutScope`
    :SteamWorks: `GetConfigValueInfo <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#GetConfigValueInfo>`_

    **Signature differences from C++ API:**

    * Parameter ``pOutDataType`` is returned as an additional return value
    * Parameter ``pOutScope`` is returned as an additional return value

.. function:: NetworkingUtils.IterateGenericEditableConfigValues(eCurrent, bEnumerateDevVars)

    🤖 **Auto-generated binding**

    :param int eCurrent:
    :param bool bEnumerateDevVars:
    :returns: (int) Return value
    :SteamWorks: `IterateGenericEditableConfigValues <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#IterateGenericEditableConfigValues>`_

.. function:: NetworkingUtils.SteamNetworkingIPAddr_ToString(addr, cbBuf, bWithPort)

    🤖 **Auto-generated binding**

    :param :ref:`SteamNetworkingIPAddr <struct-SteamNetworkingIPAddr>` addr:
    :param int cbBuf:
    :param bool bWithPort:
    :returns: (str) Value for `buf`
    :SteamWorks: `SteamNetworkingIPAddr_ToString <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SteamNetworkingIPAddr_ToString>`_

    **Signature differences from C++ API:**

    * Parameter ``buf`` is returned as an additional return value

.. function:: NetworkingUtils.SteamNetworkingIPAddr_ParseString(pszStr)

    🤖 **Auto-generated binding**

    :param str pszStr:
    :returns: (bool) Return value
    :returns: (:ref:`SteamNetworkingIPAddr <struct-SteamNetworkingIPAddr>`) Value for `pAddr`
    :SteamWorks: `SteamNetworkingIPAddr_ParseString <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SteamNetworkingIPAddr_ParseString>`_

    **Signature differences from C++ API:**

    * Parameter ``pAddr`` is returned as an additional return value

.. function:: NetworkingUtils.SteamNetworkingIPAddr_GetFakeIPType(addr)

    🤖 **Auto-generated binding**

    :param :ref:`SteamNetworkingIPAddr <struct-SteamNetworkingIPAddr>` addr:
    :returns: (int) Return value
    :SteamWorks: `SteamNetworkingIPAddr_GetFakeIPType <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SteamNetworkingIPAddr_GetFakeIPType>`_

.. function:: NetworkingUtils.SteamNetworkingIdentity_ToString(identity, cbBuf)

    🤖 **Auto-generated binding**

    :param :ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>` identity:
    :param int cbBuf:
    :returns: (str) Value for `buf`
    :SteamWorks: `SteamNetworkingIdentity_ToString <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SteamNetworkingIdentity_ToString>`_

    **Signature differences from C++ API:**

    * Parameter ``buf`` is returned as an additional return value

.. function:: NetworkingUtils.SteamNetworkingIdentity_ParseString(pszStr)

    🤖 **Auto-generated binding**

    :param str pszStr:
    :returns: (bool) Return value
    :returns: (:ref:`SteamNetworkingIdentity <struct-SteamNetworkingIdentity>`) Value for `pIdentity`
    :SteamWorks: `SteamNetworkingIdentity_ParseString <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SteamNetworkingIdentity_ParseString>`_

    **Signature differences from C++ API:**

    * Parameter ``pIdentity`` is returned as an additional return value


Unimplemented Methods
---------------------

.. function:: NetworkingUtils.allocateMessage

    ✋ **Not implemented** - unsupported type: SteamNetworkingMessage_t *
    
    :SteamWorks: `AllocateMessage <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#AllocateMessage>`_

.. function:: NetworkingUtils.getRelayNetworkStatus

    ✋ **Not implemented** - unsupported type: SteamRelayNetworkStatus_t *
    
    :SteamWorks: `GetRelayNetworkStatus <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#GetRelayNetworkStatus>`_

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

    ✋ **Not implemented** - manual: Needs careful dealing with void*
    
    :SteamWorks: `SetConfigValue <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SetConfigValue>`_

.. function:: NetworkingUtils.setConfigValueStruct

    ✋ **Not implemented** - manual: Needs careful dealing with void*
    
    :SteamWorks: `SetConfigValueStruct <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SetConfigValueStruct>`_

.. function:: NetworkingUtils.getConfigValue

    ✋ **Not implemented** - unsupported type: void *
    
    :SteamWorks: `GetConfigValue <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#GetConfigValue>`_


Callbacks
---------

.. function:: NetworkingUtils.onSteamRelayNetworkStatus

    Callback for `SteamRelayNetworkStatus_t <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#SteamRelayNetworkStatus_t>`_

    **callback(data)** receives:

    * **data.m_eAvail** -- m_eAvail
    * **data.m_bPingMeasurementInProgress** -- m_bPingMeasurementInProgress
    * **data.m_eAvailNetworkConfig** -- m_eAvailNetworkConfig
    * **data.m_eAvailAnyRelay** -- m_eAvailAnyRelay
    * **data.m_debugMsg** -- m_debugMsg

