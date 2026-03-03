#############
ISteamParties
#############

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✍️ are manually implemented and methods marked with ✋ are currently not implemented.

List of Functions
-----------------

* :func:`Parties.CancelReservation`
* :func:`Parties.ChangeNumOpenSlots`
* :func:`Parties.DestroyBeacon`
* :func:`Parties.GetAvailableBeaconLocations`
* :func:`Parties.GetBeaconByIndex`
* :func:`Parties.GetBeaconDetails`
* :func:`Parties.GetBeaconLocationData`
* :func:`Parties.GetNumActiveBeacons`
* :func:`Parties.GetNumAvailableBeaconLocations`
* :func:`Parties.JoinParty`
* :func:`Parties.OnReservationCompleted`

List of Callbacks
-----------------

* :func:`Parties.OnJoinPartyCallback`
* :func:`Parties.OnCreateBeaconCallback`
* :func:`Parties.OnReservationNotificationCallback`
* :func:`Parties.OnChangeNumOpenSlotsCallback`
* :func:`Parties.OnAvailableBeaconLocationsUpdated`
* :func:`Parties.OnActiveBeaconsUpdated`

Function Reference
------------------

.. function:: Parties.CancelReservation(ulBeacon, steamIDUser)

    🤖 **Auto-generated binding**

    :param uint64 ulBeacon: ``PartyBeaconID_t``
    :param uint64 steamIDUser:
    :SteamWorks: `CancelReservation <https://partner.steamgames.com/doc/api/ISteamParties#CancelReservation>`_

**Example**::

    -- Called by beacon owner when a reserved player cancels
    Steam.Parties.CancelReservation(beaconHandle, playerSteamID)

.. function:: Parties.ChangeNumOpenSlots(ulBeacon, unOpenSlots, callback)

    🤖 **Auto-generated binding**

    :param uint64 ulBeacon: ``PartyBeaconID_t``
    :param int unOpenSlots:
    :param function callback: CallResult callback receiving struct :func:`ChangeNumOpenSlotsCallback_t <Parties.OnChangeNumOpenSlotsCallback>` and a boolean
    :returns: (uint64) ``SteamAPICall_t`` handle for this async call. The result is delivered via the ``callback`` parameter when :func:`Steam.RunCallbacks` is called.
    :SteamWorks: `ChangeNumOpenSlots <https://partner.steamgames.com/doc/api/ISteamParties#ChangeNumOpenSlots>`_

.. function:: Parties.DestroyBeacon(ulBeacon)

    🤖 **Auto-generated binding**

    :param uint64 ulBeacon: ``PartyBeaconID_t``
    :returns: (bool) Return value
    :SteamWorks: `DestroyBeacon <https://partner.steamgames.com/doc/api/ISteamParties#DestroyBeacon>`_

.. function:: Parties.GetAvailableBeaconLocations(uMaxNumLocations)

    🤖 **Auto-generated binding**

    :param int? uMaxNumLocations: size of the buffer to allocate for ``pLocationList``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (bool) Return value
    :returns: (:ref:`SteamPartyBeaconLocation_t <struct-SteamPartyBeaconLocation_t>`\ []) ``pLocationList``
    :SteamWorks: `GetAvailableBeaconLocations <https://partner.steamgames.com/doc/api/ISteamParties#GetAvailableBeaconLocations>`_

    **Signature differences from C++ API:**

    * Parameter ``pLocationList`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: Parties.GetBeaconByIndex(unIndex)

    🤖 **Auto-generated binding**

    :param int unIndex:
    :returns: (uint64) ``PartyBeaconID_t``
    :SteamWorks: `GetBeaconByIndex <https://partner.steamgames.com/doc/api/ISteamParties#GetBeaconByIndex>`_

    **Notes:**

    * See :func:`Parties.GetNumActiveBeacons`'s example.

.. function:: Parties.GetBeaconDetails(ulBeaconID, cchMetadata)

    🤖 **Auto-generated binding**

    :param uint64 ulBeaconID: ``PartyBeaconID_t``
    :param int? cchMetadata: size of the buffer to allocate for ``pchMetadata``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (bool) Return value
    :returns: (uint64) ``pSteamIDBeaconOwner``
    :returns: (:ref:`SteamPartyBeaconLocation_t <struct-SteamPartyBeaconLocation_t>`) ``pLocation``
    :returns: (str) ``pchMetadata``
    :SteamWorks: `GetBeaconDetails <https://partner.steamgames.com/doc/api/ISteamParties#GetBeaconDetails>`_

    **Signature differences from C++ API:**

    * Parameter ``pSteamIDBeaconOwner`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.
    * Parameter ``pLocation`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.
    * Parameter ``pchMetadata`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

    **Notes:**

    * See :func:`Parties.GetNumActiveBeacons`'s example.

.. function:: Parties.GetBeaconLocationData(BeaconLocation, eData, cchDataStringOut)

    🤖 **Auto-generated binding**

    :param BeaconLocation: (:ref:`SteamPartyBeaconLocation_t <struct-SteamPartyBeaconLocation_t>`) ``SteamPartyBeaconLocation_t``
    :param int eData: ``ESteamPartyBeaconLocationData``
    :param int? cchDataStringOut: size of the buffer to allocate for ``pchDataStringOut``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (bool) Return value
    :returns: (str) ``pchDataStringOut``
    :SteamWorks: `GetBeaconLocationData <https://partner.steamgames.com/doc/api/ISteamParties#GetBeaconLocationData>`_

    **Signature differences from C++ API:**

    * Parameter ``pchDataStringOut`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: Parties.GetNumActiveBeacons()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetNumActiveBeacons <https://partner.steamgames.com/doc/api/ISteamParties#GetNumActiveBeacons>`_

**Example**::

    local count = Steam.Parties.GetNumActiveBeacons()
    for i = 0, count - 1 do
        local beaconID = Steam.Parties.GetBeaconByIndex(i)
        local ok, ownerID, loc, meta = Steam.Parties.GetBeaconDetails(beaconID, 256)
        if ok then
            print('Beacon owner:', Steam.Friends.GetFriendPersonaName(ownerID))
        end
    end

.. function:: Parties.GetNumAvailableBeaconLocations()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :returns: (int) ``puNumLocations``
    :SteamWorks: `GetNumAvailableBeaconLocations <https://partner.steamgames.com/doc/api/ISteamParties#GetNumAvailableBeaconLocations>`_

    **Signature differences from C++ API:**

    * Parameter ``puNumLocations`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    local count = Steam.Parties.GetNumAvailableBeaconLocations()
    local locations = Steam.Parties.GetAvailableBeaconLocations(count)
    for _, loc in ipairs(locations) do
        print('Beacon location type:', loc.m_eType)
    end

.. function:: Parties.JoinParty(ulBeaconID, callback)

    🤖 **Auto-generated binding**

    :param uint64 ulBeaconID: ``PartyBeaconID_t``
    :param function callback: CallResult callback receiving struct :func:`JoinPartyCallback_t <Parties.OnJoinPartyCallback>` and a boolean
    :returns: (uint64) ``SteamAPICall_t`` handle for this async call. The result is delivered via the ``callback`` parameter when :func:`Steam.RunCallbacks` is called.
    :SteamWorks: `JoinParty <https://partner.steamgames.com/doc/api/ISteamParties#JoinParty>`_

**Example**::

    Steam.Parties.JoinParty(beaconID, function(data, err)
        if not err and data.m_eResult == Steam.k_EResultOK then
            print('Joined party, connect string:', data.m_rgchConnectString)
            connectToGame(data.m_rgchConnectString)
        end
    end)

.. function:: Parties.OnReservationCompleted(ulBeacon, steamIDUser)

    🤖 **Auto-generated binding**

    :param uint64 ulBeacon: ``PartyBeaconID_t``
    :param uint64 steamIDUser:
    :SteamWorks: `OnReservationCompleted <https://partner.steamgames.com/doc/api/ISteamParties#OnReservationCompleted>`_


Unimplemented Methods
---------------------

.. function:: Parties.createBeacon

    ✋ **Not implemented** - blocklist: requires custom implementation
    
    :SteamWorks: `CreateBeacon <https://partner.steamgames.com/doc/api/ISteamParties#CreateBeacon>`_


Callbacks
---------

.. function:: Parties.OnJoinPartyCallback

    Callback for `JoinPartyCallback_t <https://partner.steamgames.com/doc/api/ISteamParties#JoinPartyCallback_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(EResult)*
    * **data.m_ulBeaconID** *(PartyBeaconID_t)*
    * **data.m_SteamIDBeaconOwner** *(uint64)*
    * **data.m_rgchConnectString** *(string)*

**Example**::

    function Steam.Parties.OnJoinPartyCallback(data)
        if data.m_eResult == Steam.k_EResultOK then
            connectToGame(data.m_rgchConnectString)
        end
    end

.. function:: Parties.OnCreateBeaconCallback

    Callback for `CreateBeaconCallback_t <https://partner.steamgames.com/doc/api/ISteamParties#CreateBeaconCallback_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(EResult)*
    * **data.m_ulBeaconID** *(PartyBeaconID_t)*

.. function:: Parties.OnReservationNotificationCallback

    Callback for `ReservationNotificationCallback_t <https://partner.steamgames.com/doc/api/ISteamParties#ReservationNotificationCallback_t>`_

    **callback(data)** receives:

    * **data.m_ulBeaconID** *(PartyBeaconID_t)*
    * **data.m_steamIDJoiner** *(uint64)*

.. function:: Parties.OnChangeNumOpenSlotsCallback

    Callback for `ChangeNumOpenSlotsCallback_t <https://partner.steamgames.com/doc/api/ISteamParties#ChangeNumOpenSlotsCallback_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(EResult)*

.. function:: Parties.OnAvailableBeaconLocationsUpdated

    Callback for `AvailableBeaconLocationsUpdated_t <https://partner.steamgames.com/doc/api/ISteamParties#AvailableBeaconLocationsUpdated_t>`_

    **callback(data)** receives no fields (notification only).

.. function:: Parties.OnActiveBeaconsUpdated

    Callback for `ActiveBeaconsUpdated_t <https://partner.steamgames.com/doc/api/ISteamParties#ActiveBeaconsUpdated_t>`_

    **callback(data)** receives no fields (notification only).

**Example**::

    function Steam.Parties.OnActiveBeaconsUpdated()
        local count = Steam.Parties.GetNumActiveBeacons()
        print('Active beacons updated, count:', count)
    end

