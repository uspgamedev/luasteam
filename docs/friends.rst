ISteamFriends
=============

List of Functions
-----------------

* :func:`friends.activateGameOverlay`
* :func:`friends.activateGameOverlayToWebPage`
* :func:`friends.getFriendPersonaName`

List of Callbacks
-----------------

* :func:`friends.onGameOverlayActivated`


Function Reference
------------------

.. function:: friends.activateGameOverlay (dialog)

    :param string dialog: The dialog to open. Valid options are: "friends", "community", "players", "settings", "officialgamegroup", "stats", "achievements".
    :returns: nothing
    :SteamWorks: `ActivateGameOverlay <https://partner.steamgames.com/doc/api/ISteamFriends#ActivateGameOverlay>`_

    Activates the Steam Overlay to a specific dialog.

**Example**::

    Steam.friends.activateGameOverlay('stats')

.. function:: friends.activateGameOverlayToWebPage(url)

    :param string url: The webpage to open. (A fully qualified address with the protocol is required, e.g. "http://www.steampowered.com")
    :returns: nothing
    :SteamWorks: `ActivateGameOverlayToWebPage <https://partner.steamgames.com/doc/api/ISteamFriends#ActivateGameOverlayToWebPage>`_

    Activates Steam Overlay web browser directly to the specified URL.

**Example**::

    Steam.friends.activateGameOverlayToWebPage('https://www.google.com')


.. function:: friends.getFriendPersonaName(steam_id)

    :param steam_id: The Steam ID of the other user.
    :returns: The current users persona name. Returns an empty string (""), or "[unknown]" if the Steam ID is invalid or not known to the caller.
    :SteamWorks: `GetFriendPersonaName <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendPersonaName>`_

    Gets the specified user's persona (display) name.

    This will only be known to the current user if the other user is in their friends list, on the same game server, in a chat room or lobby, or in a small Steam group with the local user.

..   (This is not implemented yet) **NOTE**: Upon on first joining a lobby, chat room, or game server the current user will not known the name of the other users automatically; that information will arrive asynchronously via PersonaStateChange_t callbacks.
    To get the persona name of the current user use GetPersonaName.

**Example**::

    steam_id = getSteamIdSomehow()
    print("Friend's name is:", Steam.friends.getFriendPersonaName(steam_id))

Callbacks Reference
-------------------

.. warning::

    Remember callbacks are functions that you should override in order to receive the events, and not call directly.

    Also, you **must** constantly call ``Steam.runCallbacks()`` (preferably in your game loop) in order for your callbacks to be called.

.. function:: friends.onGameOverlayActivated(data)

    :param table data: A table with a single
    :returns: nothing
    :SteamWorks: `GameOverlayActivated_t <https://partner.steamgames.com/doc/api/ISteamFriends#GameOverlayActivated_t>`_

    Posted when the Steam Overlay activates or deactivates. The game can use this to be pause or resume single player games.

**Example**::

    function Steam.friends.onGameOverlayActivated(data)
        print('Overlay active is', data.active)
    end