##########
ISteamUser
##########

List of Functions
-----------------

* :func:`user.getPlayerSteamLevel`
* :func:`user.getSteamID`


Function Reference
------------------

.. function:: user.getPlayerSteamLevel ()

    :returns: (`number`) The level of the current user.
    :SteamWorks: `GetPlayerSteamLevel <https://partner.steamgames.com/doc/api/ISteamUser#GetPlayerSteamLevel>`_

    Gets the Steam level of the user, as shown on their Steam community profile.

**Example**::

    print('Let me show you some magic')
    print('Your Steam Level is...')
    print(Steam.user.getPlayerSteamLevel() .. '!!!')

.. function:: user.getSteamID ()

    :returns: (`steamID`) The SteamID of the current user.
    :SteamWorks: `GetSteamID <https://partner.steamgames.com/doc/api/ISteamUser#GetSteamID>`_

    Gets the Steam ID of the account currently logged into the Steam client. This is commonly called the 'current user', or 'local user'.

    A Steam ID is a unique identifier for a Steam accounts, Steam groups, Lobbies and Chat rooms, and used to differentiate users in all parts of the Steamworks API.

**Example**::

    local my_id = Steam.user.getSteamID()
    function isSteamIDFromUser(steam_id)
        return steam_id == my_id
    end
