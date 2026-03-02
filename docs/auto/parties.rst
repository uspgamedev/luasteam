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

    :param uint64 ulBeacon:
    :param uint64 steamIDUser:
    :SteamWorks: `CancelReservation <https://partner.steamgames.com/doc/api/ISteamParties#CancelReservation>`_

**Example**::

    -- Called by beacon owner when a reserved player cancels
    Steam.Parties.CancelReservation(beaconHandle, playerSteamID)

.. function:: Parties.ChangeNumOpenSlots(ulBeacon, unOpenSlots, callback)

    🤖 **Auto-generated binding**

    :param uint64 ulBeacon:
    :param int unOpenSlots:
    :param function callback: CallResult callback receiving struct `ChangeNumOpenSlotsCallback_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `ChangeNumOpenSlots <https://partner.steamgames.com/doc/api/ISteamParties#ChangeNumOpenSlots>`_

.. function:: Parties.DestroyBeacon(ulBeacon)

    🤖 **Auto-generated binding**

    :param uint64 ulBeacon:
    :returns: (bool) Return value
    :SteamWorks: `DestroyBeacon <https://partner.steamgames.com/doc/api/ISteamParties#DestroyBeacon>`_

.. function:: Parties.GetAvailableBeaconLocations(uMaxNumLocations)

    🤖 **Auto-generated binding**

    :param int uMaxNumLocations:
    :returns: (bool) Return value
    :returns: (:ref:`SteamPartyBeaconLocation_t <struct-SteamPartyBeaconLocation_t>`[]) Value for `pLocationList`
    :SteamWorks: `GetAvailableBeaconLocations <https://partner.steamgames.com/doc/api/ISteamParties#GetAvailableBeaconLocations>`_

    **Signature differences from C++ API:**

    * Parameter ``pLocationList`` is no longer a paramer, and is instead an additional return value

.. function:: Parties.GetBeaconByIndex(unIndex)

    🤖 **Auto-generated binding**

    :param int unIndex:
    :returns: (uint64) Return value
    :SteamWorks: `GetBeaconByIndex <https://partner.steamgames.com/doc/api/ISteamParties#GetBeaconByIndex>`_

    **Notes:**

    * See :func:`Parties.GetNumActiveBeacons`'s example.

.. function:: Parties.GetBeaconDetails(ulBeaconID, cchMetadata)

    🤖 **Auto-generated binding**

    :param uint64 ulBeaconID:
    :param int cchMetadata:
    :returns: (bool) Return value
    :returns: (uint64) Value for `pSteamIDBeaconOwner`
    :returns: (:ref:`SteamPartyBeaconLocation_t <struct-SteamPartyBeaconLocation_t>`) Value for `pLocation`
    :returns: (str) Value for `pchMetadata`
    :SteamWorks: `GetBeaconDetails <https://partner.steamgames.com/doc/api/ISteamParties#GetBeaconDetails>`_

    **Signature differences from C++ API:**

    * Parameter ``pSteamIDBeaconOwner`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pLocation`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pchMetadata`` is no longer a paramer, and is instead an additional return value

    **Notes:**

    * See :func:`Parties.GetNumActiveBeacons`'s example.

.. function:: Parties.GetBeaconLocationData(BeaconLocation, eData, cchDataStringOut)

    🤖 **Auto-generated binding**

    :param :ref:`SteamPartyBeaconLocation_t <struct-SteamPartyBeaconLocation_t>` BeaconLocation:
    :param int eData:
    :param int cchDataStringOut:
    :returns: (bool) Return value
    :returns: (str) Value for `pchDataStringOut`
    :SteamWorks: `GetBeaconLocationData <https://partner.steamgames.com/doc/api/ISteamParties#GetBeaconLocationData>`_

    **Signature differences from C++ API:**

    * Parameter ``pchDataStringOut`` is no longer a paramer, and is instead an additional return value

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
    :returns: (int) Value for `puNumLocations`
    :SteamWorks: `GetNumAvailableBeaconLocations <https://partner.steamgames.com/doc/api/ISteamParties#GetNumAvailableBeaconLocations>`_

    **Signature differences from C++ API:**

    * Parameter ``puNumLocations`` is no longer a paramer, and is instead an additional return value

**Example**::

    local count = Steam.Parties.GetNumAvailableBeaconLocations()
    local locations = Steam.Parties.GetAvailableBeaconLocations(count)
    for _, loc in ipairs(locations) do
        print('Beacon location type:', loc.m_eType)
    end

.. function:: Parties.JoinParty(ulBeaconID, callback)

    🤖 **Auto-generated binding**

    :param uint64 ulBeaconID:
    :param function callback: CallResult callback receiving struct `JoinPartyCallback_t` and a boolean
    :returns: (uint64) Return value
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

    :param uint64 ulBeacon:
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

    * **data.m_eResult** -- m_eResult
    * **data.m_ulBeaconID** -- m_ulBeaconID
    * **data.m_SteamIDBeaconOwner** -- m_SteamIDBeaconOwner
    * **data.m_rgchConnectString** -- m_rgchConnectString

**Example**::

    function Steam.Parties.OnJoinPartyCallback(data)
        if data.m_eResult == Steam.k_EResultOK then
            connectToGame(data.m_rgchConnectString)
        end
    end

.. function:: Parties.OnCreateBeaconCallback

    Callback for `CreateBeaconCallback_t <https://partner.steamgames.com/doc/api/ISteamParties#CreateBeaconCallback_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_ulBeaconID** -- m_ulBeaconID

.. function:: Parties.OnReservationNotificationCallback

    Callback for `ReservationNotificationCallback_t <https://partner.steamgames.com/doc/api/ISteamParties#ReservationNotificationCallback_t>`_

    **callback(data)** receives:

    * **data.m_ulBeaconID** -- m_ulBeaconID
    * **data.m_steamIDJoiner** -- m_steamIDJoiner

.. function:: Parties.OnChangeNumOpenSlotsCallback

    Callback for `ChangeNumOpenSlotsCallback_t <https://partner.steamgames.com/doc/api/ISteamParties#ChangeNumOpenSlotsCallback_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult

.. function:: Parties.OnAvailableBeaconLocationsUpdated

    Callback for `AvailableBeaconLocationsUpdated_t <https://partner.steamgames.com/doc/api/ISteamParties#AvailableBeaconLocationsUpdated_t>`_

    **callback(data)** receives:


.. function:: Parties.OnActiveBeaconsUpdated

    Callback for `ActiveBeaconsUpdated_t <https://partner.steamgames.com/doc/api/ISteamParties#ActiveBeaconsUpdated_t>`_

    **callback(data)** receives:


**Example**::

    function Steam.Parties.OnActiveBeaconsUpdated()
        local count = Steam.Parties.GetNumActiveBeacons()
        print('Active beacons updated, count:', count)
    end

