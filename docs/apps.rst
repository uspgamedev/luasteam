###########
ISteamApps
###########

List of Functions
-----------------

* :func:`apps.getCurrentGameLanguage`
* :func:`apps.isDlcInstalled`
* :func:`apps.getLaunchCommandLineParam`


List of Callbacks
-----------------

* :func:`apps.onNewUrlLaunchParameters`

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

.. function:: apps.getLaunchCommandLine()

    :returns: (`string`) The launch command line parameters
    :SteamWorks: `GetLaunchCommandLine <https://partner.steamgames.com/doc/api/ISteamApps#GetLaunchCommandLine>`_

    Gets the launch command line parameters. Use it to for example parse it for a connect string when implementing game invite functionality using :func:`friends.inviteUserToGame`.

    If Steam is installed, you can request launching a Steam game by navigating to a `steam://run/<appid>//<params>` URL.


**Example**::

    local params = Steam.apps.getLaunchCommandLine()
    local connect_string = tryParseConnectString(params)
    if connect_string then
        initiateJoinGame(connect_string)
    end

.. warning::

    This is currently hardcoded in luasteam to a 1024 characters maximum.



Callbacks Reference
-------------------

.. function:: apps.onNewUrlLaunchParameters()

    :returns: nothing
    :SteamWorks: `NewUrlLaunchParameters_t <https://partner.steamgames.com/doc/api/ISteamApps#NewUrlLaunchParameters_t>`_

    Called by Steam when a `steam://run/<appid>//<params>` URL is navigated to when the game is already running. This callback has no data, use :func:`apps.getLaunchCommandLine` to get the launch parameters from the most recently used URL.

    The callback that gets called when you join another player's game inside Steam while the game is running is :func:`friends.onGameRichPresenceJoinRequested`.
