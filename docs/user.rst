##########
ISteamUser
##########

List of Functions
-----------------

* :func:`user.getPlayerSteamLevel`
* :func:`user.getSteamID`
* :func:`user.getAuthSessionTicket`
* :func:`user.cancelAuthTicket`

List of Callbacks
-----------------

* :func:`user.onAuthSessionTicketResponse`


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

    :returns: (`uint64`) The SteamID of the current user.
    :SteamWorks: `GetSteamID <https://partner.steamgames.com/doc/api/ISteamUser#GetSteamID>`_

    Gets the Steam ID of the account currently logged into the Steam client. This is commonly called the 'current user', or 'local user'.

    A Steam ID is a unique identifier for a Steam accounts, Steam groups, Lobbies and Chat rooms, and used to differentiate users in all parts of the Steamworks API.

**Example**::

    local my_id = Steam.user.getSteamID()
    function isSteamIDFromUser(steam_id)
        return steam_id == my_id
    end

.. function:: user.getAuthSessionTicket ()

    :returns: (`data`) A result table if successful, otherwise nil

		* **data.ticket** (`number`) The handle for the auth session ticket (only has meaning on the client on where you called this, is NOT an auth ticket)
		* **data.hexTicket** (`string`) The ticket data as a hexadeximal formatted string. This is the ticket that you need to send to the server/authenticating instance.
      
    :SteamWorks: `GetAuthSessionTicket <https://partner.steamgames.com/doc/api/ISteamUser#GetAuthSessionTicket>`_

    Retrieve an authentication ticket from steam. You can use this to authenticate yourself with a third party server. You should wait for a successful callback to :func:`user.onAuthSessionTicketResponse` (indicating that Steam has accepted your request for a ticket) before using this ticket.
    
    When you're done with the ticket **you must call** :func:`user.cancelAuthTicket` on the handle.

**Example**::

    local data = Steam.user.getAuthSessionTicket() -- keep the ticket handle around
    if data then
       local ticketHandle = data.ticket
       local ticketData = data.hexTicket
       -- Now do something with it
    end

.. function:: user.cancelAuthTicket ()

    :param number ticketHandle: The ticket handle to cancel the auth ticket for. You need to call this once you are done using a requested or scheduled ticket. Make sure to call this for any open ticket handles when quitting your application.
    :returns: nothing
    :SteamWorks: `CancelAuthTicket <https://partner.steamgames.com/doc/api/ISteamUser#CancelAuthTicket>`_

**Example**::

    Steam.user.cancelAuthTicket(ticketHandle)

Callbacks Reference
-------------------

.. warning::

    Remember callbacks are functions that you should override in order to receive the events, and not call directly.

    Also, you **must** constantly call ``Steam.runCallbacks()`` (preferably in your game loop) in order for your callbacks to be called.

.. function:: user.onAuthSessionTicketResponse(data)

    :param table data: A result table for when creating an auth session ticket.

		* **data.handle** (`number`) The handle for the auth session ticket or 0 if the call failed
		* **data.result** (`string`) A steam result, ``OK`` if the ticket was created successfully, otherwise an error message
    :returns: nothing
    :SteamWorks: `GetAuthSessionTicketResponse_t <https://partner.steamgames.com/doc/api/ISteamUser#GetAuthSessionTicketResponse_t>`_

    Posted when an auth session ticket has been accepted or declined by the steam servers. This is in response to a call to :func:`user.getAuthSessionTicket`.

**Example**::

    function Steam.user.onAuthSessionTicketResponse(data)
        print('Auth ticket issue status:', data.handle, data.result)
    end
