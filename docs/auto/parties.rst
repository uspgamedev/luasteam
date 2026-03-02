#############
ISteamParties
#############

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✋ require manual implementation.

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

* :func:`Parties.onJoinPartyCallback`
* :func:`Parties.onCreateBeaconCallback`
* :func:`Parties.onReservationNotificationCallback`
* :func:`Parties.onChangeNumOpenSlotsCallback`
* :func:`Parties.onAvailableBeaconLocationsUpdated`
* :func:`Parties.onActiveBeaconsUpdated`

Function Reference
------------------

.. function:: Parties.CancelReservation(ulBeacon, steamIDUser)

    🤖 **Auto-generated binding**

    :param uint64 ulBeacon:
    :param uint64 steamIDUser:
    :SteamWorks: `CancelReservation <https://partner.steamgames.com/doc/api/ISteamParties#CancelReservation>`_

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

.. function:: Parties.GetNumAvailableBeaconLocations()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :returns: (int) Value for `puNumLocations`
    :SteamWorks: `GetNumAvailableBeaconLocations <https://partner.steamgames.com/doc/api/ISteamParties#GetNumAvailableBeaconLocations>`_

    **Signature differences from C++ API:**

    * Parameter ``puNumLocations`` is no longer a paramer, and is instead an additional return value

.. function:: Parties.JoinParty(ulBeaconID, callback)

    🤖 **Auto-generated binding**

    :param uint64 ulBeaconID:
    :param function callback: CallResult callback receiving struct `JoinPartyCallback_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `JoinParty <https://partner.steamgames.com/doc/api/ISteamParties#JoinParty>`_

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

.. function:: Parties.onJoinPartyCallback

    Callback for `JoinPartyCallback_t <https://partner.steamgames.com/doc/api/ISteamParties#JoinPartyCallback_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_ulBeaconID** -- m_ulBeaconID
    * **data.m_SteamIDBeaconOwner** -- m_SteamIDBeaconOwner
    * **data.m_rgchConnectString** -- m_rgchConnectString

.. function:: Parties.onCreateBeaconCallback

    Callback for `CreateBeaconCallback_t <https://partner.steamgames.com/doc/api/ISteamParties#CreateBeaconCallback_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_ulBeaconID** -- m_ulBeaconID

.. function:: Parties.onReservationNotificationCallback

    Callback for `ReservationNotificationCallback_t <https://partner.steamgames.com/doc/api/ISteamParties#ReservationNotificationCallback_t>`_

    **callback(data)** receives:

    * **data.m_ulBeaconID** -- m_ulBeaconID
    * **data.m_steamIDJoiner** -- m_steamIDJoiner

.. function:: Parties.onChangeNumOpenSlotsCallback

    Callback for `ChangeNumOpenSlotsCallback_t <https://partner.steamgames.com/doc/api/ISteamParties#ChangeNumOpenSlotsCallback_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult

.. function:: Parties.onAvailableBeaconLocationsUpdated

    Callback for `AvailableBeaconLocationsUpdated_t <https://partner.steamgames.com/doc/api/ISteamParties#AvailableBeaconLocationsUpdated_t>`_

    **callback(data)** receives:


.. function:: Parties.onActiveBeaconsUpdated

    Callback for `ActiveBeaconsUpdated_t <https://partner.steamgames.com/doc/api/ISteamParties#ActiveBeaconsUpdated_t>`_

    **callback(data)** receives:


