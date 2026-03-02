#################
ISteamMatchmaking
#################

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✋ require manual implementation.

List of Functions
-----------------

* :func:`Matchmaking.AddFavoriteGame`
* :func:`Matchmaking.AddRequestLobbyListCompatibleMembersFilter`
* :func:`Matchmaking.AddRequestLobbyListDistanceFilter`
* :func:`Matchmaking.AddRequestLobbyListFilterSlotsAvailable`
* :func:`Matchmaking.AddRequestLobbyListNearValueFilter`
* :func:`Matchmaking.AddRequestLobbyListNumericalFilter`
* :func:`Matchmaking.AddRequestLobbyListResultCountFilter`
* :func:`Matchmaking.AddRequestLobbyListStringFilter`
* :func:`Matchmaking.CreateLobby`
* :func:`Matchmaking.DeleteLobbyData`
* :func:`Matchmaking.GetFavoriteGame`
* :func:`Matchmaking.GetFavoriteGameCount`
* :func:`Matchmaking.GetLobbyByIndex`
* :func:`Matchmaking.GetLobbyChatEntry`
* :func:`Matchmaking.GetLobbyData`
* :func:`Matchmaking.GetLobbyDataByIndex`
* :func:`Matchmaking.GetLobbyDataCount`
* :func:`Matchmaking.GetLobbyGameServer`
* :func:`Matchmaking.GetLobbyMemberByIndex`
* :func:`Matchmaking.GetLobbyMemberData`
* :func:`Matchmaking.GetLobbyMemberLimit`
* :func:`Matchmaking.GetLobbyOwner`
* :func:`Matchmaking.GetNumLobbyMembers`
* :func:`Matchmaking.InviteUserToLobby`
* :func:`Matchmaking.JoinLobby`
* :func:`Matchmaking.LeaveLobby`
* :func:`Matchmaking.RemoveFavoriteGame`
* :func:`Matchmaking.RequestLobbyData`
* :func:`Matchmaking.RequestLobbyList`
* :func:`Matchmaking.SendLobbyChatMsg`
* :func:`Matchmaking.SetLinkedLobby`
* :func:`Matchmaking.SetLobbyData`
* :func:`Matchmaking.SetLobbyGameServer`
* :func:`Matchmaking.SetLobbyJoinable`
* :func:`Matchmaking.SetLobbyMemberData`
* :func:`Matchmaking.SetLobbyMemberLimit`
* :func:`Matchmaking.SetLobbyOwner`
* :func:`Matchmaking.SetLobbyType`

List of Callbacks
-----------------

* :func:`Matchmaking.OnFavoritesListChanged`
* :func:`Matchmaking.OnLobbyInvite`
* :func:`Matchmaking.OnLobbyEnter`
* :func:`Matchmaking.OnLobbyDataUpdate`
* :func:`Matchmaking.OnLobbyChatUpdate`
* :func:`Matchmaking.OnLobbyChatMsg`
* :func:`Matchmaking.OnLobbyGameCreated`
* :func:`Matchmaking.OnLobbyMatchList`
* :func:`Matchmaking.OnLobbyKicked`
* :func:`Matchmaking.OnLobbyCreated`
* :func:`Matchmaking.OnFavoritesListAccountsUpdated`

Function Reference
------------------

.. function:: Matchmaking.AddFavoriteGame(nAppID, nIP, nConnPort, nQueryPort, unFlags, rTime32LastPlayedOnServer)

    🤖 **Auto-generated binding**

    :param int nAppID:
    :param int nIP:
    :param int nConnPort:
    :param int nQueryPort:
    :param int unFlags:
    :param int rTime32LastPlayedOnServer:
    :returns: (int) Return value
    :SteamWorks: `AddFavoriteGame <https://partner.steamgames.com/doc/api/ISteamMatchmaking#AddFavoriteGame>`_

.. function:: Matchmaking.AddRequestLobbyListCompatibleMembersFilter(steamIDLobby)

    🤖 **Auto-generated binding**

    :param uint64 steamIDLobby:
    :SteamWorks: `AddRequestLobbyListCompatibleMembersFilter <https://partner.steamgames.com/doc/api/ISteamMatchmaking#AddRequestLobbyListCompatibleMembersFilter>`_

.. function:: Matchmaking.AddRequestLobbyListDistanceFilter(eLobbyDistanceFilter)

    🤖 **Auto-generated binding**

    :param int eLobbyDistanceFilter:
    :SteamWorks: `AddRequestLobbyListDistanceFilter <https://partner.steamgames.com/doc/api/ISteamMatchmaking#AddRequestLobbyListDistanceFilter>`_

.. function:: Matchmaking.AddRequestLobbyListFilterSlotsAvailable(nSlotsAvailable)

    🤖 **Auto-generated binding**

    :param int nSlotsAvailable:
    :SteamWorks: `AddRequestLobbyListFilterSlotsAvailable <https://partner.steamgames.com/doc/api/ISteamMatchmaking#AddRequestLobbyListFilterSlotsAvailable>`_

.. function:: Matchmaking.AddRequestLobbyListNearValueFilter(pchKeyToMatch, nValueToBeCloseTo)

    🤖 **Auto-generated binding**

    :param str pchKeyToMatch:
    :param int nValueToBeCloseTo:
    :SteamWorks: `AddRequestLobbyListNearValueFilter <https://partner.steamgames.com/doc/api/ISteamMatchmaking#AddRequestLobbyListNearValueFilter>`_

.. function:: Matchmaking.AddRequestLobbyListNumericalFilter(pchKeyToMatch, nValueToMatch, eComparisonType)

    🤖 **Auto-generated binding**

    :param str pchKeyToMatch:
    :param int nValueToMatch:
    :param int eComparisonType:
    :SteamWorks: `AddRequestLobbyListNumericalFilter <https://partner.steamgames.com/doc/api/ISteamMatchmaking#AddRequestLobbyListNumericalFilter>`_

.. function:: Matchmaking.AddRequestLobbyListResultCountFilter(cMaxResults)

    🤖 **Auto-generated binding**

    :param int cMaxResults:
    :SteamWorks: `AddRequestLobbyListResultCountFilter <https://partner.steamgames.com/doc/api/ISteamMatchmaking#AddRequestLobbyListResultCountFilter>`_

.. function:: Matchmaking.AddRequestLobbyListStringFilter(pchKeyToMatch, pchValueToMatch, eComparisonType)

    🤖 **Auto-generated binding**

    :param str pchKeyToMatch:
    :param str pchValueToMatch:
    :param int eComparisonType:
    :SteamWorks: `AddRequestLobbyListStringFilter <https://partner.steamgames.com/doc/api/ISteamMatchmaking#AddRequestLobbyListStringFilter>`_

.. function:: Matchmaking.CreateLobby(eLobbyType, cMaxMembers, callback)

    🤖 **Auto-generated binding**

    :param int eLobbyType:
    :param int cMaxMembers:
    :param function callback: CallResult callback receiving struct `LobbyCreated_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `CreateLobby <https://partner.steamgames.com/doc/api/ISteamMatchmaking#CreateLobby>`_

**Example**::

    Steam.Matchmaking.CreateLobby('Public', 8, function(data, err)
        if err or data.m_eResult ~= Steam.k_EResultOK then
            print('Failed to create lobby')
            return
        end
        local lobbyID = data.m_ulSteamIDLobby
        Steam.Matchmaking.SetLobbyData(lobbyID, 'map', 'level_01')
        Steam.Matchmaking.SetLobbyData(lobbyID, 'mode', 'deathmatch')
    end)

.. function:: Matchmaking.DeleteLobbyData(steamIDLobby, pchKey)

    🤖 **Auto-generated binding**

    :param uint64 steamIDLobby:
    :param str pchKey:
    :returns: (bool) Return value
    :SteamWorks: `DeleteLobbyData <https://partner.steamgames.com/doc/api/ISteamMatchmaking#DeleteLobbyData>`_

.. function:: Matchmaking.GetFavoriteGame(iGame)

    🤖 **Auto-generated binding**

    :param int iGame:
    :returns: (bool) Return value
    :returns: (int) Value for `pnAppID`
    :returns: (int) Value for `pnIP`
    :returns: (int) Value for `pnConnPort`
    :returns: (int) Value for `pnQueryPort`
    :returns: (int) Value for `punFlags`
    :returns: (int) Value for `pRTime32LastPlayedOnServer`
    :SteamWorks: `GetFavoriteGame <https://partner.steamgames.com/doc/api/ISteamMatchmaking#GetFavoriteGame>`_

    **Signature differences from C++ API:**

    * Parameter ``pnAppID`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pnIP`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pnConnPort`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pnQueryPort`` is no longer a paramer, and is instead an additional return value
    * Parameter ``punFlags`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pRTime32LastPlayedOnServer`` is no longer a paramer, and is instead an additional return value

.. function:: Matchmaking.GetFavoriteGameCount()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetFavoriteGameCount <https://partner.steamgames.com/doc/api/ISteamMatchmaking#GetFavoriteGameCount>`_

.. function:: Matchmaking.GetLobbyByIndex(iLobby)

    🤖 **Auto-generated binding**

    :param int iLobby:
    :returns: (uint64) Return value
    :SteamWorks: `GetLobbyByIndex <https://partner.steamgames.com/doc/api/ISteamMatchmaking#GetLobbyByIndex>`_

.. function:: Matchmaking.GetLobbyChatEntry(steamIDLobby, iChatID, cubData)

    🤖 **Auto-generated binding**

    :param uint64 steamIDLobby:
    :param int iChatID:
    :param int cubData:
    :returns: (int) Return value
    :returns: (uint64) Value for `pSteamIDUser`
    :returns: (str) Value for `pvData`
    :returns: (int) Value for `peChatEntryType`
    :SteamWorks: `GetLobbyChatEntry <https://partner.steamgames.com/doc/api/ISteamMatchmaking#GetLobbyChatEntry>`_

    **Signature differences from C++ API:**

    * Parameter ``pSteamIDUser`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pvData`` is no longer a paramer, and is instead an additional return value
    * Parameter ``peChatEntryType`` is no longer a paramer, and is instead an additional return value

.. function:: Matchmaking.GetLobbyData(steamIDLobby, pchKey)

    🤖 **Auto-generated binding**

    :param uint64 steamIDLobby:
    :param str pchKey:
    :returns: (str) Return value
    :SteamWorks: `GetLobbyData <https://partner.steamgames.com/doc/api/ISteamMatchmaking#GetLobbyData>`_

**Example**::

    local map = Steam.Matchmaking.GetLobbyData(lobbyID, 'map')
    print('Current map:', map)

.. function:: Matchmaking.GetLobbyDataByIndex(steamIDLobby, iLobbyData, cchKeyBufferSize, cchValueBufferSize)

    🤖 **Auto-generated binding**

    :param uint64 steamIDLobby:
    :param int iLobbyData:
    :param int cchKeyBufferSize:
    :param int cchValueBufferSize:
    :returns: (bool) Return value
    :returns: (str) Value for `pchKey`
    :returns: (str) Value for `pchValue`
    :SteamWorks: `GetLobbyDataByIndex <https://partner.steamgames.com/doc/api/ISteamMatchmaking#GetLobbyDataByIndex>`_

    **Signature differences from C++ API:**

    * Parameter ``pchKey`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pchValue`` is no longer a paramer, and is instead an additional return value

.. function:: Matchmaking.GetLobbyDataCount(steamIDLobby)

    🤖 **Auto-generated binding**

    :param uint64 steamIDLobby:
    :returns: (int) Return value
    :SteamWorks: `GetLobbyDataCount <https://partner.steamgames.com/doc/api/ISteamMatchmaking#GetLobbyDataCount>`_

.. function:: Matchmaking.GetLobbyGameServer(steamIDLobby)

    🤖 **Auto-generated binding**

    :param uint64 steamIDLobby:
    :returns: (bool) Return value
    :returns: (int) Value for `punGameServerIP`
    :returns: (int) Value for `punGameServerPort`
    :returns: (uint64) Value for `psteamIDGameServer`
    :SteamWorks: `GetLobbyGameServer <https://partner.steamgames.com/doc/api/ISteamMatchmaking#GetLobbyGameServer>`_

    **Signature differences from C++ API:**

    * Parameter ``punGameServerIP`` is no longer a paramer, and is instead an additional return value
    * Parameter ``punGameServerPort`` is no longer a paramer, and is instead an additional return value
    * Parameter ``psteamIDGameServer`` is no longer a paramer, and is instead an additional return value

**Example**::

    local hasServer, ip, port, steamID = Steam.Matchmaking.GetLobbyGameServer(lobbyID)
    if hasServer then
        connectToGameServer(ip, port)
    end

.. function:: Matchmaking.GetLobbyMemberByIndex(steamIDLobby, iMember)

    🤖 **Auto-generated binding**

    :param uint64 steamIDLobby:
    :param int iMember:
    :returns: (uint64) Return value
    :SteamWorks: `GetLobbyMemberByIndex <https://partner.steamgames.com/doc/api/ISteamMatchmaking#GetLobbyMemberByIndex>`_

.. function:: Matchmaking.GetLobbyMemberData(steamIDLobby, steamIDUser, pchKey)

    🤖 **Auto-generated binding**

    :param uint64 steamIDLobby:
    :param uint64 steamIDUser:
    :param str pchKey:
    :returns: (str) Return value
    :SteamWorks: `GetLobbyMemberData <https://partner.steamgames.com/doc/api/ISteamMatchmaking#GetLobbyMemberData>`_

**Example**::

    local team = Steam.Matchmaking.GetLobbyMemberData(lobbyID, memberSteamID, 'team')
    print('Member team:', team)

.. function:: Matchmaking.GetLobbyMemberLimit(steamIDLobby)

    🤖 **Auto-generated binding**

    :param uint64 steamIDLobby:
    :returns: (int) Return value
    :SteamWorks: `GetLobbyMemberLimit <https://partner.steamgames.com/doc/api/ISteamMatchmaking#GetLobbyMemberLimit>`_

.. function:: Matchmaking.GetLobbyOwner(steamIDLobby)

    🤖 **Auto-generated binding**

    :param uint64 steamIDLobby:
    :returns: (uint64) Return value
    :SteamWorks: `GetLobbyOwner <https://partner.steamgames.com/doc/api/ISteamMatchmaking#GetLobbyOwner>`_

**Example**::

    local ownerID = Steam.Matchmaking.GetLobbyOwner(lobbyID)
    local isOwner = ownerID == Steam.User.GetSteamID()

.. function:: Matchmaking.GetNumLobbyMembers(steamIDLobby)

    🤖 **Auto-generated binding**

    :param uint64 steamIDLobby:
    :returns: (int) Return value
    :SteamWorks: `GetNumLobbyMembers <https://partner.steamgames.com/doc/api/ISteamMatchmaking#GetNumLobbyMembers>`_

**Example**::

    local count = Steam.Matchmaking.GetNumLobbyMembers(lobbyID)
    for i = 0, count - 1 do
        local memberID = Steam.Matchmaking.GetLobbyMemberByIndex(lobbyID, i)
        print('Member:', Steam.Friends.GetFriendPersonaName(memberID))
    end

.. function:: Matchmaking.InviteUserToLobby(steamIDLobby, steamIDInvitee)

    🤖 **Auto-generated binding**

    :param uint64 steamIDLobby:
    :param uint64 steamIDInvitee:
    :returns: (bool) Return value
    :SteamWorks: `InviteUserToLobby <https://partner.steamgames.com/doc/api/ISteamMatchmaking#InviteUserToLobby>`_

**Example**::

    Steam.Matchmaking.InviteUserToLobby(lobbyID, friendSteamID)

.. function:: Matchmaking.JoinLobby(steamIDLobby, callback)

    🤖 **Auto-generated binding**

    :param uint64 steamIDLobby:
    :param function callback: CallResult callback receiving struct `LobbyEnter_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `JoinLobby <https://partner.steamgames.com/doc/api/ISteamMatchmaking#JoinLobby>`_

**Example**::

    Steam.Matchmaking.JoinLobby(lobbyID, function(data, err)
        if err or data.m_EChatRoomEnterResponse ~= 1 then
            print('Failed to join lobby')
        else
            print('Joined lobby:', tostring(data.m_ulSteamIDLobby))
        end
    end)

.. function:: Matchmaking.LeaveLobby(steamIDLobby)

    🤖 **Auto-generated binding**

    :param uint64 steamIDLobby:
    :SteamWorks: `LeaveLobby <https://partner.steamgames.com/doc/api/ISteamMatchmaking#LeaveLobby>`_

**Example**::

    Steam.Matchmaking.LeaveLobby(lobbyID)

.. function:: Matchmaking.RemoveFavoriteGame(nAppID, nIP, nConnPort, nQueryPort, unFlags)

    🤖 **Auto-generated binding**

    :param int nAppID:
    :param int nIP:
    :param int nConnPort:
    :param int nQueryPort:
    :param int unFlags:
    :returns: (bool) Return value
    :SteamWorks: `RemoveFavoriteGame <https://partner.steamgames.com/doc/api/ISteamMatchmaking#RemoveFavoriteGame>`_

.. function:: Matchmaking.RequestLobbyData(steamIDLobby)

    🤖 **Auto-generated binding**

    :param uint64 steamIDLobby:
    :returns: (bool) Return value
    :SteamWorks: `RequestLobbyData <https://partner.steamgames.com/doc/api/ISteamMatchmaking#RequestLobbyData>`_

.. function:: Matchmaking.RequestLobbyList(callback)

    🤖 **Auto-generated binding**

    :param function callback: CallResult callback receiving struct `LobbyMatchList_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `RequestLobbyList <https://partner.steamgames.com/doc/api/ISteamMatchmaking#RequestLobbyList>`_

**Example**::

    Steam.Matchmaking.AddRequestLobbyListStringFilter('map', 'level_01', 'EqualToOrLessThan')
    Steam.Matchmaking.AddRequestLobbyListResultCountFilter(20)
    Steam.Matchmaking.RequestLobbyList(function(data, err)
        if not err then
            for i = 0, data.m_nLobbiesMatching - 1 do
                local id = Steam.Matchmaking.GetLobbyByIndex(i)
                local map = Steam.Matchmaking.GetLobbyData(id, 'map')
                print('Lobby: ' .. map .. ' (' .. Steam.Matchmaking.GetNumLobbyMembers(id) .. ' players)')
            end
        end
    end)

.. function:: Matchmaking.SendLobbyChatMsg(steamIDLobby, pvMsgBody, cubMsgBody)

    🤖 **Auto-generated binding**

    :param uint64 steamIDLobby:
    :param str pvMsgBody:
    :param int cubMsgBody:
    :returns: (bool) Return value
    :SteamWorks: `SendLobbyChatMsg <https://partner.steamgames.com/doc/api/ISteamMatchmaking#SendLobbyChatMsg>`_

**Example**::

    local msg = 'Ready!'
    Steam.Matchmaking.SendLobbyChatMsg(lobbyID, msg, #msg)

.. function:: Matchmaking.SetLinkedLobby(steamIDLobby, steamIDLobbyDependent)

    🤖 **Auto-generated binding**

    :param uint64 steamIDLobby:
    :param uint64 steamIDLobbyDependent:
    :returns: (bool) Return value
    :SteamWorks: `SetLinkedLobby <https://partner.steamgames.com/doc/api/ISteamMatchmaking#SetLinkedLobby>`_

.. function:: Matchmaking.SetLobbyData(steamIDLobby, pchKey, pchValue)

    🤖 **Auto-generated binding**

    :param uint64 steamIDLobby:
    :param str pchKey:
    :param str pchValue:
    :returns: (bool) Return value
    :SteamWorks: `SetLobbyData <https://partner.steamgames.com/doc/api/ISteamMatchmaking#SetLobbyData>`_

**Example**::

    Steam.Matchmaking.SetLobbyData(lobbyID, 'map', 'dungeon_01')
    Steam.Matchmaking.SetLobbyData(lobbyID, 'players', tostring(playerCount))

.. function:: Matchmaking.SetLobbyGameServer(steamIDLobby, unGameServerIP, unGameServerPort, steamIDGameServer)

    🤖 **Auto-generated binding**

    :param uint64 steamIDLobby:
    :param int unGameServerIP:
    :param int unGameServerPort:
    :param uint64 steamIDGameServer:
    :SteamWorks: `SetLobbyGameServer <https://partner.steamgames.com/doc/api/ISteamMatchmaking#SetLobbyGameServer>`_

**Example**::

    Steam.Matchmaking.SetLobbyGameServer(lobbyID, serverIP, serverPort, Steam.GameServer.GetSteamID())

.. function:: Matchmaking.SetLobbyJoinable(steamIDLobby, bLobbyJoinable)

    🤖 **Auto-generated binding**

    :param uint64 steamIDLobby:
    :param bool bLobbyJoinable:
    :returns: (bool) Return value
    :SteamWorks: `SetLobbyJoinable <https://partner.steamgames.com/doc/api/ISteamMatchmaking#SetLobbyJoinable>`_

**Example**::

    -- Lock the lobby when the game starts
    Steam.Matchmaking.SetLobbyJoinable(lobbyID, false)

.. function:: Matchmaking.SetLobbyMemberData(steamIDLobby, pchKey, pchValue)

    🤖 **Auto-generated binding**

    :param uint64 steamIDLobby:
    :param str pchKey:
    :param str pchValue:
    :SteamWorks: `SetLobbyMemberData <https://partner.steamgames.com/doc/api/ISteamMatchmaking#SetLobbyMemberData>`_

**Example**::

    -- Set per-player data visible to other lobby members
    Steam.Matchmaking.SetLobbyMemberData(lobbyID, 'team', 'blue')
    Steam.Matchmaking.SetLobbyMemberData(lobbyID, 'ready', '1')

.. function:: Matchmaking.SetLobbyMemberLimit(steamIDLobby, cMaxMembers)

    🤖 **Auto-generated binding**

    :param uint64 steamIDLobby:
    :param int cMaxMembers:
    :returns: (bool) Return value
    :SteamWorks: `SetLobbyMemberLimit <https://partner.steamgames.com/doc/api/ISteamMatchmaking#SetLobbyMemberLimit>`_

.. function:: Matchmaking.SetLobbyOwner(steamIDLobby, steamIDNewOwner)

    🤖 **Auto-generated binding**

    :param uint64 steamIDLobby:
    :param uint64 steamIDNewOwner:
    :returns: (bool) Return value
    :SteamWorks: `SetLobbyOwner <https://partner.steamgames.com/doc/api/ISteamMatchmaking#SetLobbyOwner>`_

.. function:: Matchmaking.SetLobbyType(steamIDLobby, eLobbyType)

    🤖 **Auto-generated binding**

    :param uint64 steamIDLobby:
    :param int eLobbyType:
    :returns: (bool) Return value
    :SteamWorks: `SetLobbyType <https://partner.steamgames.com/doc/api/ISteamMatchmaking#SetLobbyType>`_


Callbacks
---------

.. function:: Matchmaking.OnFavoritesListChanged

    Callback for `FavoritesListChanged_t <https://partner.steamgames.com/doc/api/ISteamMatchmaking#FavoritesListChanged_t>`_

    **callback(data)** receives:

    * **data.m_nIP** -- m_nIP
    * **data.m_nQueryPort** -- m_nQueryPort
    * **data.m_nConnPort** -- m_nConnPort
    * **data.m_nAppID** -- m_nAppID
    * **data.m_nFlags** -- m_nFlags
    * **data.m_bAdd** -- m_bAdd
    * **data.m_unAccountId** -- m_unAccountId

.. function:: Matchmaking.OnLobbyInvite

    Callback for `LobbyInvite_t <https://partner.steamgames.com/doc/api/ISteamMatchmaking#LobbyInvite_t>`_

    **callback(data)** receives:

    * **data.m_ulSteamIDUser** -- m_ulSteamIDUser
    * **data.m_ulSteamIDLobby** -- m_ulSteamIDLobby
    * **data.m_ulGameID** -- m_ulGameID

**Example**::

    function Steam.Matchmaking.OnLobbyInvite(data)
        local name = Steam.Friends.GetFriendPersonaName(data.m_ulSteamIDUser)
        print(name .. ' invited you to a lobby')
        showJoinPrompt(data.m_ulSteamIDLobby)
    end

.. function:: Matchmaking.OnLobbyEnter

    Callback for `LobbyEnter_t <https://partner.steamgames.com/doc/api/ISteamMatchmaking#LobbyEnter_t>`_

    **callback(data)** receives:

    * **data.m_ulSteamIDLobby** -- m_ulSteamIDLobby
    * **data.m_rgfChatPermissions** -- m_rgfChatPermissions
    * **data.m_bLocked** -- m_bLocked
    * **data.m_EChatRoomEnterResponse** -- m_EChatRoomEnterResponse

**Example**::

    function Steam.Matchmaking.OnLobbyEnter(data)
        if data.m_EChatRoomEnterResponse == 1 then
            print('Entered lobby:', tostring(data.m_ulSteamIDLobby))
            updateLobbyUI(data.m_ulSteamIDLobby)
        end
    end

.. function:: Matchmaking.OnLobbyDataUpdate

    Callback for `LobbyDataUpdate_t <https://partner.steamgames.com/doc/api/ISteamMatchmaking#LobbyDataUpdate_t>`_

    **callback(data)** receives:

    * **data.m_ulSteamIDLobby** -- m_ulSteamIDLobby
    * **data.m_ulSteamIDMember** -- m_ulSteamIDMember
    * **data.m_bSuccess** -- m_bSuccess

**Example**::

    function Steam.Matchmaking.OnLobbyDataUpdate(data)
        if data.m_bSuccess ~= 0 then
            local map = Steam.Matchmaking.GetLobbyData(data.m_ulSteamIDLobby, 'map')
            print('Lobby data updated, map:', map)
        end
    end

.. function:: Matchmaking.OnLobbyChatUpdate

    Callback for `LobbyChatUpdate_t <https://partner.steamgames.com/doc/api/ISteamMatchmaking#LobbyChatUpdate_t>`_

    **callback(data)** receives:

    * **data.m_ulSteamIDLobby** -- m_ulSteamIDLobby
    * **data.m_ulSteamIDUserChanged** -- m_ulSteamIDUserChanged
    * **data.m_ulSteamIDMakingChange** -- m_ulSteamIDMakingChange
    * **data.m_rgfChatMemberStateChange** -- m_rgfChatMemberStateChange

**Example**::

    function Steam.Matchmaking.OnLobbyChatUpdate(data)
        local count = Steam.Matchmaking.GetNumLobbyMembers(data.m_ulSteamIDLobby)
        print('Lobby membership changed, now', count, 'players')
    end

.. function:: Matchmaking.OnLobbyChatMsg

    Callback for `LobbyChatMsg_t <https://partner.steamgames.com/doc/api/ISteamMatchmaking#LobbyChatMsg_t>`_

    **callback(data)** receives:

    * **data.m_ulSteamIDLobby** -- m_ulSteamIDLobby
    * **data.m_ulSteamIDUser** -- m_ulSteamIDUser
    * **data.m_eChatEntryType** -- m_eChatEntryType
    * **data.m_iChatID** -- m_iChatID

**Example**::

    function Steam.Matchmaking.OnLobbyChatMsg(data)
        local msg, chatType = Steam.Matchmaking.GetLobbyChatEntry(data.m_ulSteamIDLobby, data.m_iChatID, 512)
        if msg then
            local name = Steam.Friends.GetFriendPersonaName(data.m_ulSteamIDUser)
            print(name .. ': ' .. msg)
        end
    end

.. function:: Matchmaking.OnLobbyGameCreated

    Callback for `LobbyGameCreated_t <https://partner.steamgames.com/doc/api/ISteamMatchmaking#LobbyGameCreated_t>`_

    **callback(data)** receives:

    * **data.m_ulSteamIDLobby** -- m_ulSteamIDLobby
    * **data.m_ulSteamIDGameServer** -- m_ulSteamIDGameServer
    * **data.m_unIP** -- m_unIP
    * **data.m_usPort** -- m_usPort

**Example**::

    function Steam.Matchmaking.OnLobbyGameCreated(data)
        print('Game server created:', data.m_ulSteamIDGameServer)
        connectToGameServer(data.m_unIP, data.m_usPort)
    end

.. function:: Matchmaking.OnLobbyMatchList

    Callback for `LobbyMatchList_t <https://partner.steamgames.com/doc/api/ISteamMatchmaking#LobbyMatchList_t>`_

    **callback(data)** receives:

    * **data.m_nLobbiesMatching** -- m_nLobbiesMatching

.. function:: Matchmaking.OnLobbyKicked

    Callback for `LobbyKicked_t <https://partner.steamgames.com/doc/api/ISteamMatchmaking#LobbyKicked_t>`_

    **callback(data)** receives:

    * **data.m_ulSteamIDLobby** -- m_ulSteamIDLobby
    * **data.m_ulSteamIDAdmin** -- m_ulSteamIDAdmin
    * **data.m_bKickedDueToDisconnect** -- m_bKickedDueToDisconnect

.. function:: Matchmaking.OnLobbyCreated

    Callback for `LobbyCreated_t <https://partner.steamgames.com/doc/api/ISteamMatchmaking#LobbyCreated_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_ulSteamIDLobby** -- m_ulSteamIDLobby

.. function:: Matchmaking.OnFavoritesListAccountsUpdated

    Callback for `FavoritesListAccountsUpdated_t <https://partner.steamgames.com/doc/api/ISteamMatchmaking#FavoritesListAccountsUpdated_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult

