###########
ISteamUtils
###########

List of Functions
-----------------

* :func:`utils.getAppID`


Function Reference
------------------

.. function:: utils.getAppID ()

    :returns: (`number`) The AppID.
    :SteamWorks: `GetAppID <https://partner.steamgames.com/doc/api/ISteamUtils#GetAppID>`_

	Gets the App ID of the current process.

**Example**::

    print("My app id is " .. Steam.utils.getAppID())

.. function:: utils.isSteamRunningOnSteamDeck ()

    :returns: (`boolean`) ``true`` if Steam itself is running on a Steam Deck device; otherwise, ``false``.
    :SteamWorks: `IsSteamRunningOnSteamDeck <https://partner.steamgames.com/doc/api/ISteamUtils#IsSteamRunningInVR>`_

	Checks if Steam is running on a Steam Deck, or any other SteamOS device.

**Example**::

    if Steam.utils.isSteamRunningOnSteamDeck() then
        -- some special logic
    end