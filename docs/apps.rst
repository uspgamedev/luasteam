###########
ISteamApps
###########

List of Functions
-----------------

* :func:`apps.getCurrentGameLanguage`
* :func:`apps.isDlcInstalled`


Function Reference
------------------

.. function:: apps.getCurrentGameLanguage()

    :returns: (`string`) The language that the user has set.
    :SteamWorks: `GetCurrentGameLanguage <https://partner.steamgames.com/doc/api/ISteamApps#GetCurrentGameLanguage>`_

	Gets the current language that the user has set. This falls back to the Steam UI language if the user hasn't explicitly picked a language for the title.

  For the full list of languages see `Supported Languages <https://partner.steamgames.com/doc/store/localization#supported_languages>`_


**Example**::

    print("The games current language is " .. Steam.apps.getCurrentGameLanguage())


.. function:: apps.isDlcInstalled(appID)

    :param number appID: The App ID of the DLC to check.
    :returns: (`boolean`) true if the user owns the DLC and it's currently installed, otherwise false.
    :SteamWorks: `GetCurrentGameLanguage <https://partner.steamgames.com/doc/api/ISteamApps#BIsDlcInstalled>`_

	Checks if the user owns a specific DLC and if the DLC is installed.


**Example**::

    if Steam.apps.isDlcInstalled(12345) then
        -- Unlock game content
    end