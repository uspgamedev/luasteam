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

