#############
ISteamFriends
#############

List of Functions
-----------------

* :func:`friends.activateGameOverlay`
* :func:`friends.activateGameOverlayToWebPage`
* :func:`friends.getFriendPersonaName`
* :func:`friends.setRichPresence`
* :func:`friends.inviteUserToGame`
* :func:`friends.getFriendCount`
* :func:`friends.getFriendByIndex`

List of Callbacks
-----------------

* :func:`friends.onGameOverlayActivated`
* :func:`friends.onGameRichPresenceJoinRequested`


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

    :param uint64 steam_id: The Steam ID of the other user.
    :returns: (`string`) The current users persona name. Returns an empty string (""), or "[unknown]" if the Steam ID is invalid or not known to the caller.
    :SteamWorks: `GetFriendPersonaName <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendPersonaName>`_

    Gets the specified user's persona (display) name.

    This will only be known to the current user if the other user is in their friends list, on the same game server, in a chat room or lobby, or in a small Steam group with the local user.

..   (This is not implemented yet) **NOTE**: Upon on first joining a lobby, chat room, or game server the current user will not known the name of the other users automatically; that information will arrive asynchronously via PersonaStateChange_t callbacks.
    To get the persona name of the current user use GetPersonaName.

**Example**::

    steam_id = getSteamIdSomehow()
    print("Friend's name is:", Steam.friends.getFriendPersonaName(steam_id))

.. function:: friends.setRichPresence(key, value)

    :param string key: The rich presence key to set. Maximum length is 64 characters.

        Valve has a few special keys which you can read about in their `documentation <https://partner.steamgames.com/doc/api/ISteamFriends#SetRichPresence>`_.

        Besides those special keys, you can also use any arbitrary key for `substition <https://partner.steamgames.com/doc/api/ISteamFriends#richpresencelocalization>`_ in `steam_display`.

    :param string value: The value to associate with the rich presence key. Maximum length is 256 characters. If this is set to ``''`` then the key is removed if it's set.

    :returns: (`boolean`) This function returns **true** if the rich presence was was set successfully.

        It returns **false** under the following conditions:

        * The key or the value were too long.
        * The user has reached maximum amount of rich presence keys: 20.

    :SteamWorks: `SetRichPresence <https://partner.steamgames.com/doc/api/ISteamFriends#SetRichPresence>`_

    Sets a Rich Presence key/value for the current user that is shared with friends. You can use the `Rich Presence Tester <https://steamcommunity.com/dev/testrichpresence>`_ to test whether or not this is working.

**Example**::

    local success = Steam.friends.setRichPresence('steam_display', '#StatusFull')
    local success = Steam.friends.setRichPresence('text', 'Fighting the Last Boss')

**Localization**

    To get the most out of this feature, you'll want to set up some `Localization <https://partner.steamgames.com/doc/api/ISteamFriends#richpresencelocalization>`_ options.

    You may find that Valve's suggestion of how to use localization is more difficult to use than it needs to be. In this case, I suggest using a setup like this where you can manage all of the text yourself:

**rich_presence_localization.vdf**::

    "lang"
    {
        "english"
        {
            "tokens"
            {
                "#StatusFull" "%text%"
            }
        }
    }

.. function:: friends.inviteUserToGame(steamIDFriend, connect_string)

    :param uint64 steamIDFriend: The Steam ID of the friend to invite.
    :param string connect_string: A string that lets the friend know how to join the game (I.E. the game server IP). This can not be longer than 256 characters.
    :returns: (`boolean`) **true** if invite was sent successfully, **false** under the following conditions:

        * The Steam ID provided to `steamIDFriend`` was invalid.
        * The Steam ID provided to `steamIDFriend`` is not a friend or does not share the same Steam Group as the current user.
        * The value provided to `connect_string` was too long.
    :SteamWorks: `InviteUserToGame <https://partner.steamgames.com/doc/api/ISteamFriends#InviteUserToGame>`_

    Invites the given user `steamIDFriend` to the game identified by `connect_string`

    The `connect_string` can be received by the application on the joining player in two ways depending on whether the game is already running or it is being launched.

    You should implement the callback :func:`friends.onGameRichPresenceJoinRequested` to receive the `connect_string` on the invitee and ultimately establish the connection on an already running application.

    You should also call :func:`apps.getLaunchCommandLineParams` on game launch and check if the game was launched with the `connect_string`, and immediately take steps to establish the connection.

    To add UI elements to invite or join the game over the Steam overlay or friends menu, also set the rich presence key `connect` with the `connect_string` value and clear it when the game is no longer available to join.

**Example**::

    local friend_id = getSteamIdSomehow()
    local success = Steam.friends.inviteUserToGame(friend_id, 'serverID=birthday_party')

.. function:: friends.getFriendCount(flags)

    :param number flags: A combined union (binary "or") of one or more "friend flags".
    :returns: (`number`) The number of users that meet the specified criteria. -1 if the current user is not logged on.
    :SteamWorks: `GetFriendCount <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendCount>`_

    For the `flags` parameter, see the `steam docs <https://partner.steamgames.com/doc/api/ISteamFriends#EFriendFlags>`_ about possible values, they are not duplicated in luasteam. Most of the time, you want to use `0x4`, which means "all that user's friends". With LuaJIT, you can use `bit.bor` to do bitwise or.

    Gets the number of users the client knows about who meet a specified criteria. (Friends, blocked, users on the same server, etc)

    This can be used to iterate over all of the users by calling :func:`friends.getFriendByIndex` to get the Steam IDs of each user.

**Example**::

    -- This will print all your friends' name
    local count = luasteam.friends.getFriendCount(0x4)
    for i = 1, count do
        local id = luasteam.friends.getFriendByIndex(i - 1, 0x4)
        print(luasteam.friends.getFriendPersonaName(id))
    end

.. function:: friends.getFriendByIndex(index, flags)

    :param number index: An index between 0 and :func:`friends.getFriendCount` (this is not 1-indexed!!)
    :param number flags: A combined union (binary "or") of one or more "friend flags". This must be the same value as used in the previous call to :func:`friends.getFriendCount`
    :returns: (`uint64`) SteamID of the user at the given index. 0 on invalid indices.
    :SteamWorks: `GetFriendByIndex <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendByIndex>`_

    Gets the Steam ID of the user at the given index.

    See :func:`friends.getFriendCount` for an example usage.

.. note::

    You must call :func:`friends.getFriendCount` before calling this.

Callbacks Reference
-------------------

.. warning::

    Remember callbacks are functions that you should override in order to receive the events, and not call directly.

    Also, you **must** constantly call ``Steam.runCallbacks()`` (preferably in your game loop) in order for your callbacks to be called.

.. function:: friends.onGameOverlayActivated(data)

    :param table data: A table similar to `GameOverlayActivated_t <https://partner.steamgames.com/doc/api/ISteamFriends#GameOverlayActivated_t>`_

		* **data.active** (`boolean`)  -- true if it's just been activated, otherwise false.
    :returns: nothing
    :SteamWorks: `GameOverlayActivated_t <https://partner.steamgames.com/doc/api/ISteamFriends#GameOverlayActivated_t>`_

    Posted when the Steam Overlay activates or deactivates. The game can use this to be pause or resume single player games.

**Example**::

    function Steam.friends.onGameOverlayActivated(data)
        print('Overlay active is', data.active)
    end

.. function:: friends.onGameRichPresenceJoinRequested(data)

    :param table data: A table similar to `GameRichPresenceJoinRequested_t <https://partner.steamgames.com/doc/api/ISteamFriends#GameRichPresenceJoinRequested_t>`_

        * **data.steamIDFriend** (`uint64`) -- The friend they joined through. This will be invalid if not directly via a friend.
        * **data.connect** (`string`) -- The value associated with the "connect" Rich Presence key.

    :returns: nothing
    :SteamWorks: `GameRichPresenceJoinRequested_t <https://partner.steamgames.com/doc/api/ISteamFriends#GameRichPresenceJoinRequested_t>`_
    
    Called when the user tries to join a game from their friends list or after a user accepts an invite by a friend with :func:`friends.inviteUserToGame`.


**Example**::

    function Steam.friends.onGameRichPresenceJoinRequested(data)
        if game_state == 'main_menu' then
            initiateJoinGame(data.connect)
        else
            showDialog("you can only join a game from the main menu")
        end
    end
