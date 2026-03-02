######################
ISteamParentalSettings
######################

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✍️ are manually implemented and methods marked with ✋ are currently not implemented.

List of Functions
-----------------

* :func:`ParentalSettings.BIsAppBlocked`
* :func:`ParentalSettings.BIsAppInBlockList`
* :func:`ParentalSettings.BIsFeatureBlocked`
* :func:`ParentalSettings.BIsFeatureInBlockList`
* :func:`ParentalSettings.BIsParentalLockEnabled`
* :func:`ParentalSettings.BIsParentalLockLocked`

List of Callbacks
-----------------

* :func:`ParentalSettings.OnSteamParentalSettingsChanged`

Function Reference
------------------

.. function:: ParentalSettings.BIsAppBlocked(nAppID)

    🤖 **Auto-generated binding**

    :param int nAppID:
    :returns: (bool) Return value
    :SteamWorks: `BIsAppBlocked <https://partner.steamgames.com/doc/api/ISteamParentalSettings#BIsAppBlocked>`_

**Example**::

    if Steam.ParentalSettings.BIsAppBlocked(targetAppID) then
        print('This app is blocked by parental controls')
    end

.. function:: ParentalSettings.BIsAppInBlockList(nAppID)

    🤖 **Auto-generated binding**

    :param int nAppID:
    :returns: (bool) Return value
    :SteamWorks: `BIsAppInBlockList <https://partner.steamgames.com/doc/api/ISteamParentalSettings#BIsAppInBlockList>`_

.. function:: ParentalSettings.BIsFeatureBlocked(eFeature)

    🤖 **Auto-generated binding**

    :param int eFeature:
    :returns: (bool) Return value
    :SteamWorks: `BIsFeatureBlocked <https://partner.steamgames.com/doc/api/ISteamParentalSettings#BIsFeatureBlocked>`_

**Example**::

    if Steam.ParentalSettings.BIsFeatureBlocked(Steam.k_EParentalFeature_OnlineMultiplayer) then
        print('Online multiplayer is restricted')
    end

.. function:: ParentalSettings.BIsFeatureInBlockList(eFeature)

    🤖 **Auto-generated binding**

    :param int eFeature:
    :returns: (bool) Return value
    :SteamWorks: `BIsFeatureInBlockList <https://partner.steamgames.com/doc/api/ISteamParentalSettings#BIsFeatureInBlockList>`_

.. function:: ParentalSettings.BIsParentalLockEnabled()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BIsParentalLockEnabled <https://partner.steamgames.com/doc/api/ISteamParentalSettings#BIsParentalLockEnabled>`_

**Example**::

    if Steam.ParentalSettings.BIsParentalLockEnabled() then
        print('Parental controls are active')
    end

.. function:: ParentalSettings.BIsParentalLockLocked()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BIsParentalLockLocked <https://partner.steamgames.com/doc/api/ISteamParentalSettings#BIsParentalLockLocked>`_


Callbacks
---------

.. function:: ParentalSettings.OnSteamParentalSettingsChanged

    Callback for `SteamParentalSettingsChanged_t <https://partner.steamgames.com/doc/api/ISteamParentalSettings#SteamParentalSettingsChanged_t>`_

    **callback(data)** receives:


**Example**::

    function Steam.ParentalSettings.OnSteamParentalSettingsChanged()
        updateFeatureAvailability()
    end

