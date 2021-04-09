###########
ISteamApps
###########

List of Functions
-----------------

* :func:`apps.getCurrentGameLanguage`


Function Reference
------------------

.. function:: apps.getCurrentGameLanguage()

    :returns: (`string`) The language that the user has set.
    :SteamWorks: `GetCurrentGameLanguage <https://partner.steamgames.com/doc/api/ISteamApps#GetCurrentGameLanguage>`_

	Gets the current language that the user has set. This falls back to the Steam UI language if the user hasn't explicitly picked a language for the title.

  For the full list of languages see `Supported Languages <https://partner.steamgames.com/doc/store/localization#supported_languages>`_


**Example**::

    print("The games current language is " .. Steam.apps.getCurrentGameLanguage())

