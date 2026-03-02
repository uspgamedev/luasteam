#############
ISteamFriends
#############

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✋ require manual implementation.

List of Functions
-----------------

* :func:`Friends.ActivateGameOverlay`
* :func:`Friends.ActivateGameOverlayInviteDialog`
* :func:`Friends.ActivateGameOverlayInviteDialogConnectString`
* :func:`Friends.ActivateGameOverlayRemotePlayTogetherInviteDialog`
* :func:`Friends.ActivateGameOverlayToStore`
* :func:`Friends.ActivateGameOverlayToUser`
* :func:`Friends.ActivateGameOverlayToWebPage`
* :func:`Friends.BHasEquippedProfileItem`
* :func:`Friends.ClearRichPresence`
* :func:`Friends.CloseClanChatWindowInSteam`
* :func:`Friends.DownloadClanActivityCounts`
* :func:`Friends.EnumerateFollowingList`
* :func:`Friends.GetChatMemberByIndex`
* :func:`Friends.GetClanActivityCounts`
* :func:`Friends.GetClanByIndex`
* :func:`Friends.GetClanChatMemberCount`
* :func:`Friends.GetClanChatMessage`
* :func:`Friends.GetClanCount`
* :func:`Friends.GetClanName`
* :func:`Friends.GetClanOfficerByIndex`
* :func:`Friends.GetClanOfficerCount`
* :func:`Friends.GetClanOwner`
* :func:`Friends.GetClanTag`
* :func:`Friends.GetCoplayFriend`
* :func:`Friends.GetCoplayFriendCount`
* :func:`Friends.GetFollowerCount`
* :func:`Friends.GetFriendByIndex`
* :func:`Friends.GetFriendCoplayGame`
* :func:`Friends.GetFriendCoplayTime`
* :func:`Friends.GetFriendCount`
* :func:`Friends.GetFriendCountFromSource`
* :func:`Friends.GetFriendFromSourceByIndex`
* :func:`Friends.GetFriendGamePlayed`
* :func:`Friends.GetFriendMessage`
* :func:`Friends.GetFriendPersonaName`
* :func:`Friends.GetFriendPersonaNameHistory`
* :func:`Friends.GetFriendPersonaState`
* :func:`Friends.GetFriendRelationship`
* :func:`Friends.GetFriendRichPresence`
* :func:`Friends.GetFriendRichPresenceKeyByIndex`
* :func:`Friends.GetFriendRichPresenceKeyCount`
* :func:`Friends.GetFriendSteamLevel`
* :func:`Friends.GetFriendsGroupCount`
* :func:`Friends.GetFriendsGroupIDByIndex`
* :func:`Friends.GetFriendsGroupMembersCount`
* :func:`Friends.GetFriendsGroupMembersList`
* :func:`Friends.GetFriendsGroupName`
* :func:`Friends.GetLargeFriendAvatar`
* :func:`Friends.GetMediumFriendAvatar`
* :func:`Friends.GetNumChatsWithUnreadPriorityMessages`
* :func:`Friends.GetPersonaName`
* :func:`Friends.GetPersonaState`
* :func:`Friends.GetPlayerNickname`
* :func:`Friends.GetProfileItemPropertyString`
* :func:`Friends.GetProfileItemPropertyUint`
* :func:`Friends.GetSmallFriendAvatar`
* :func:`Friends.HasFriend`
* :func:`Friends.InviteUserToGame`
* :func:`Friends.IsClanChatAdmin`
* :func:`Friends.IsClanChatWindowOpenInSteam`
* :func:`Friends.IsClanOfficialGameGroup`
* :func:`Friends.IsClanPublic`
* :func:`Friends.IsFollowing`
* :func:`Friends.IsUserInSource`
* :func:`Friends.JoinClanChatRoom`
* :func:`Friends.LeaveClanChatRoom`
* :func:`Friends.OpenClanChatWindowInSteam`
* :func:`Friends.RegisterProtocolInOverlayBrowser`
* :func:`Friends.ReplyToFriendMessage`
* :func:`Friends.RequestClanOfficerList`
* :func:`Friends.RequestEquippedProfileItems`
* :func:`Friends.RequestFriendRichPresence`
* :func:`Friends.RequestUserInformation`
* :func:`Friends.SendClanChatMessage`
* :func:`Friends.SetInGameVoiceSpeaking`
* :func:`Friends.SetListenForFriendsMessages`
* :func:`Friends.SetPlayedWith`
* :func:`Friends.SetRichPresence`

List of Callbacks
-----------------

* :func:`Friends.OnPersonaStateChange`
* :func:`Friends.OnGameOverlayActivated`
* :func:`Friends.OnGameServerChangeRequested`
* :func:`Friends.OnGameLobbyJoinRequested`
* :func:`Friends.OnAvatarImageLoaded`
* :func:`Friends.OnClanOfficerListResponse`
* :func:`Friends.OnFriendRichPresenceUpdate`
* :func:`Friends.OnGameRichPresenceJoinRequested`
* :func:`Friends.OnGameConnectedClanChatMsg`
* :func:`Friends.OnGameConnectedChatJoin`
* :func:`Friends.OnGameConnectedChatLeave`
* :func:`Friends.OnDownloadClanActivityCountsResult`
* :func:`Friends.OnJoinClanChatRoomCompletionResult`
* :func:`Friends.OnGameConnectedFriendChatMsg`
* :func:`Friends.OnFriendsGetFollowerCount`
* :func:`Friends.OnFriendsIsFollowing`
* :func:`Friends.OnFriendsEnumerateFollowingList`
* :func:`Friends.OnUnreadChatMessagesChanged`
* :func:`Friends.OnOverlayBrowserProtocolNavigation`
* :func:`Friends.OnEquippedProfileItemsChanged`
* :func:`Friends.OnEquippedProfileItems`

Function Reference
------------------

.. function:: Friends.ActivateGameOverlay(pchDialog)

    🤖 **Auto-generated binding**

    :param str pchDialog:
    :SteamWorks: `ActivateGameOverlay <https://partner.steamgames.com/doc/api/ISteamFriends#ActivateGameOverlay>`_

**Example**::

    Steam.Friends.ActivateGameOverlay('stats')

.. function:: Friends.ActivateGameOverlayInviteDialog(steamIDLobby)

    🤖 **Auto-generated binding**

    :param uint64 steamIDLobby:
    :SteamWorks: `ActivateGameOverlayInviteDialog <https://partner.steamgames.com/doc/api/ISteamFriends#ActivateGameOverlayInviteDialog>`_

**Example**::

    -- Open the Steam overlay invite dialog for a lobby
    Steam.Friends.ActivateGameOverlayInviteDialog(lobbyID)

.. function:: Friends.ActivateGameOverlayInviteDialogConnectString(pchConnectString)

    🤖 **Auto-generated binding**

    :param str pchConnectString:
    :SteamWorks: `ActivateGameOverlayInviteDialogConnectString <https://partner.steamgames.com/doc/api/ISteamFriends#ActivateGameOverlayInviteDialogConnectString>`_

.. function:: Friends.ActivateGameOverlayRemotePlayTogetherInviteDialog(steamIDLobby)

    🤖 **Auto-generated binding**

    :param uint64 steamIDLobby:
    :SteamWorks: `ActivateGameOverlayRemotePlayTogetherInviteDialog <https://partner.steamgames.com/doc/api/ISteamFriends#ActivateGameOverlayRemotePlayTogetherInviteDialog>`_

.. function:: Friends.ActivateGameOverlayToStore(nAppID, eFlag)

    🤖 **Auto-generated binding**

    :param int nAppID:
    :param int eFlag:
    :SteamWorks: `ActivateGameOverlayToStore <https://partner.steamgames.com/doc/api/ISteamFriends#ActivateGameOverlayToStore>`_

**Example**::

    Steam.Friends.ActivateGameOverlayToStore(Steam.Utils.GetAppID(), 'None')

.. function:: Friends.ActivateGameOverlayToUser(pchDialog, steamID)

    🤖 **Auto-generated binding**

    :param str pchDialog:
    :param uint64 steamID:
    :SteamWorks: `ActivateGameOverlayToUser <https://partner.steamgames.com/doc/api/ISteamFriends#ActivateGameOverlayToUser>`_

**Example**::

    Steam.Friends.ActivateGameOverlayToUser('steamid', friendSteamID)

.. function:: Friends.ActivateGameOverlayToWebPage(pchURL, eMode)

    🤖 **Auto-generated binding**

    :param str pchURL:
    :param int eMode:
    :SteamWorks: `ActivateGameOverlayToWebPage <https://partner.steamgames.com/doc/api/ISteamFriends#ActivateGameOverlayToWebPage>`_

**Example**::

    Steam.Friends.ActivateGameOverlayToWebPage('https://www.google.com')

.. function:: Friends.BHasEquippedProfileItem(steamID, itemType)

    🤖 **Auto-generated binding**

    :param uint64 steamID:
    :param int itemType:
    :returns: (bool) Return value
    :SteamWorks: `BHasEquippedProfileItem <https://partner.steamgames.com/doc/api/ISteamFriends#BHasEquippedProfileItem>`_

.. function:: Friends.ClearRichPresence()

    🤖 **Auto-generated binding**

    :SteamWorks: `ClearRichPresence <https://partner.steamgames.com/doc/api/ISteamFriends#ClearRichPresence>`_

**Example**::

    Steam.Friends.ClearRichPresence()

.. function:: Friends.CloseClanChatWindowInSteam(steamIDClanChat)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClanChat:
    :returns: (bool) Return value
    :SteamWorks: `CloseClanChatWindowInSteam <https://partner.steamgames.com/doc/api/ISteamFriends#CloseClanChatWindowInSteam>`_

.. function:: Friends.DownloadClanActivityCounts(cClansToRequest, callback)

    🤖 **Auto-generated binding**

    :param int cClansToRequest:
    :param function callback: CallResult callback receiving struct `DownloadClanActivityCountsResult_t` and a boolean
    :returns: (uint64) Return value
    :returns: (uint64[]) Value for `psteamIDClans`
    :SteamWorks: `DownloadClanActivityCounts <https://partner.steamgames.com/doc/api/ISteamFriends#DownloadClanActivityCounts>`_

    **Signature differences from C++ API:**

    * Parameter ``psteamIDClans`` is no longer a paramer, and is instead an additional return value

.. function:: Friends.EnumerateFollowingList(unStartIndex, callback)

    🤖 **Auto-generated binding**

    :param int unStartIndex:
    :param function callback: CallResult callback receiving struct `FriendsEnumerateFollowingList_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `EnumerateFollowingList <https://partner.steamgames.com/doc/api/ISteamFriends#EnumerateFollowingList>`_

.. function:: Friends.GetChatMemberByIndex(steamIDClan, iUser)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClan:
    :param int iUser:
    :returns: (uint64) Return value
    :SteamWorks: `GetChatMemberByIndex <https://partner.steamgames.com/doc/api/ISteamFriends#GetChatMemberByIndex>`_

.. function:: Friends.GetClanActivityCounts(steamIDClan)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClan:
    :returns: (bool) Return value
    :returns: (int) Value for `pnOnline`
    :returns: (int) Value for `pnInGame`
    :returns: (int) Value for `pnChatting`
    :SteamWorks: `GetClanActivityCounts <https://partner.steamgames.com/doc/api/ISteamFriends#GetClanActivityCounts>`_

    **Signature differences from C++ API:**

    * Parameter ``pnOnline`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pnInGame`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pnChatting`` is no longer a paramer, and is instead an additional return value

.. function:: Friends.GetClanByIndex(iClan)

    🤖 **Auto-generated binding**

    :param int iClan:
    :returns: (uint64) Return value
    :SteamWorks: `GetClanByIndex <https://partner.steamgames.com/doc/api/ISteamFriends#GetClanByIndex>`_

**Example**::

    See :func:`Friends.GetClanCount`'s example.

.. function:: Friends.GetClanChatMemberCount(steamIDClan)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClan:
    :returns: (int) Return value
    :SteamWorks: `GetClanChatMemberCount <https://partner.steamgames.com/doc/api/ISteamFriends#GetClanChatMemberCount>`_

.. function:: Friends.GetClanChatMessage(steamIDClanChat, iMessage, cchTextMax)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClanChat:
    :param int iMessage:
    :param int cchTextMax:
    :returns: (int) Return value
    :returns: (str) Value for `prgchText`
    :returns: (int) Value for `peChatEntryType`
    :returns: (uint64) Value for `psteamidChatter`
    :SteamWorks: `GetClanChatMessage <https://partner.steamgames.com/doc/api/ISteamFriends#GetClanChatMessage>`_

    **Signature differences from C++ API:**

    * Parameter ``prgchText`` is no longer a paramer, and is instead an additional return value
    * Parameter ``peChatEntryType`` is no longer a paramer, and is instead an additional return value
    * Parameter ``psteamidChatter`` is no longer a paramer, and is instead an additional return value

.. function:: Friends.GetClanCount()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetClanCount <https://partner.steamgames.com/doc/api/ISteamFriends#GetClanCount>`_

**Example**::

    local count = Steam.Friends.GetClanCount()
    for i = 0, count - 1 do
        local clanID = Steam.Friends.GetClanByIndex(i)
        print('Clan: ' .. Steam.Friends.GetClanName(clanID))
    end

.. function:: Friends.GetClanName(steamIDClan)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClan:
    :returns: (str) Return value
    :SteamWorks: `GetClanName <https://partner.steamgames.com/doc/api/ISteamFriends#GetClanName>`_

**Example**::

    See :func:`Friends.GetClanCount`'s example.

.. function:: Friends.GetClanOfficerByIndex(steamIDClan, iOfficer)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClan:
    :param int iOfficer:
    :returns: (uint64) Return value
    :SteamWorks: `GetClanOfficerByIndex <https://partner.steamgames.com/doc/api/ISteamFriends#GetClanOfficerByIndex>`_

.. function:: Friends.GetClanOfficerCount(steamIDClan)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClan:
    :returns: (int) Return value
    :SteamWorks: `GetClanOfficerCount <https://partner.steamgames.com/doc/api/ISteamFriends#GetClanOfficerCount>`_

**Example**::

    local count = Steam.Friends.GetClanOfficerCount(clanID)
    for i = 0, count - 1 do
        local officerID = Steam.Friends.GetClanOfficerByIndex(clanID, i)
        print('Officer:', Steam.Friends.GetFriendPersonaName(officerID))
    end

.. function:: Friends.GetClanOwner(steamIDClan)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClan:
    :returns: (uint64) Return value
    :SteamWorks: `GetClanOwner <https://partner.steamgames.com/doc/api/ISteamFriends#GetClanOwner>`_

**Example**::

    local ownerID = Steam.Friends.GetClanOwner(clanID)
    print('Clan owner:', Steam.Friends.GetFriendPersonaName(ownerID))

.. function:: Friends.GetClanTag(steamIDClan)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClan:
    :returns: (str) Return value
    :SteamWorks: `GetClanTag <https://partner.steamgames.com/doc/api/ISteamFriends#GetClanTag>`_

.. function:: Friends.GetCoplayFriend(iCoplayFriend)

    🤖 **Auto-generated binding**

    :param int iCoplayFriend:
    :returns: (uint64) Return value
    :SteamWorks: `GetCoplayFriend <https://partner.steamgames.com/doc/api/ISteamFriends#GetCoplayFriend>`_

.. function:: Friends.GetCoplayFriendCount()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetCoplayFriendCount <https://partner.steamgames.com/doc/api/ISteamFriends#GetCoplayFriendCount>`_

.. function:: Friends.GetFollowerCount(steamID, callback)

    🤖 **Auto-generated binding**

    :param uint64 steamID:
    :param function callback: CallResult callback receiving struct `FriendsGetFollowerCount_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `GetFollowerCount <https://partner.steamgames.com/doc/api/ISteamFriends#GetFollowerCount>`_

**Example**::

    Steam.Friends.GetFollowerCount(playerID, function(data, err)
        if not err then
            print('Follower count:', data.m_nCount)
        end
    end)

.. function:: Friends.GetFriendByIndex(iFriend, iFriendFlags)

    🤖 **Auto-generated binding**

    :param int iFriend:
    :param int iFriendFlags:
    :returns: (uint64) Return value
    :SteamWorks: `GetFriendByIndex <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendByIndex>`_

**Example**::

    local count = Steam.Friends.GetFriendCount(Steam.k_EFriendFlagAll)
    for i = 0, count - 1 do
        local friend_id = Steam.Friends.GetFriendByIndex(i, Steam.k_EFriendFlagAll)
        print(Steam.Friends.GetFriendPersonaName(friend_id))
    end

.. function:: Friends.GetFriendCoplayGame(steamIDFriend)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :returns: (int) Return value
    :SteamWorks: `GetFriendCoplayGame <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendCoplayGame>`_

**Example**::

    local gameID = Steam.Friends.GetFriendCoplayGame(friendID)
    print('Friend last co-op game:', tostring(gameID))

.. function:: Friends.GetFriendCoplayTime(steamIDFriend)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :returns: (int) Return value
    :SteamWorks: `GetFriendCoplayTime <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendCoplayTime>`_

.. function:: Friends.GetFriendCount(iFriendFlags)

    🤖 **Auto-generated binding**

    :param int iFriendFlags:
    :returns: (int) Return value
    :SteamWorks: `GetFriendCount <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendCount>`_

**Example**::

    local count = Steam.Friends.GetFriendCount(Steam.k_EFriendFlagAll)
    print('You have ' .. count .. ' friends')

.. function:: Friends.GetFriendCountFromSource(steamIDSource)

    🤖 **Auto-generated binding**

    :param uint64 steamIDSource:
    :returns: (int) Return value
    :SteamWorks: `GetFriendCountFromSource <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendCountFromSource>`_

.. function:: Friends.GetFriendFromSourceByIndex(steamIDSource, iFriend)

    🤖 **Auto-generated binding**

    :param uint64 steamIDSource:
    :param int iFriend:
    :returns: (uint64) Return value
    :SteamWorks: `GetFriendFromSourceByIndex <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendFromSourceByIndex>`_

.. function:: Friends.GetFriendGamePlayed(steamIDFriend)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :returns: (bool) Return value
    :returns: (:ref:`FriendGameInfo_t <struct-FriendGameInfo_t>`) Value for `pFriendGameInfo`
    :SteamWorks: `GetFriendGamePlayed <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendGamePlayed>`_

    **Signature differences from C++ API:**

    * Parameter ``pFriendGameInfo`` is no longer a paramer, and is instead an additional return value

**Example**::

    local playing, gameID, ip, port, queryPort = Steam.Friends.GetFriendGamePlayed(friendID)
    if playing then
        print('Friend is playing game:', tostring(gameID))
    end

.. function:: Friends.GetFriendMessage(steamIDFriend, iMessageID, cubData)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :param int iMessageID:
    :param int cubData:
    :returns: (int) Return value
    :returns: (str) Value for `pvData`
    :returns: (int) Value for `peChatEntryType`
    :SteamWorks: `GetFriendMessage <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendMessage>`_

    **Signature differences from C++ API:**

    * Parameter ``pvData`` is no longer a paramer, and is instead an additional return value
    * Parameter ``peChatEntryType`` is no longer a paramer, and is instead an additional return value

.. function:: Friends.GetFriendPersonaName(steamIDFriend)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :returns: (str) Return value
    :SteamWorks: `GetFriendPersonaName <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendPersonaName>`_

**Example**::

    local friend_id = getSteamIdSomehow()
    print("Friend's name is: " .. Steam.Friends.GetFriendPersonaName(friend_id))

.. function:: Friends.GetFriendPersonaNameHistory(steamIDFriend, iPersonaName)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :param int iPersonaName:
    :returns: (str) Return value
    :SteamWorks: `GetFriendPersonaNameHistory <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendPersonaNameHistory>`_

.. function:: Friends.GetFriendPersonaState(steamIDFriend)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :returns: (int) Return value
    :SteamWorks: `GetFriendPersonaState <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendPersonaState>`_

**Example**::

    local state = Steam.Friends.GetFriendPersonaState(friendID)
    if state == Steam.k_EPersonaStateOnline then
        print('Friend is online')
    end

.. function:: Friends.GetFriendRelationship(steamIDFriend)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :returns: (int) Return value
    :SteamWorks: `GetFriendRelationship <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendRelationship>`_

**Example**::

    local rel = Steam.Friends.GetFriendRelationship(playerID)
    if rel == Steam.k_EFriendRelationshipFriend then
        print('This player is your friend')
    end

.. function:: Friends.GetFriendRichPresence(steamIDFriend, pchKey)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :param str pchKey:
    :returns: (str) Return value
    :SteamWorks: `GetFriendRichPresence <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendRichPresence>`_

**Example**::

    local value = Steam.Friends.GetFriendRichPresence(friend_id, 'steam_display')
    print('Rich presence: ' .. value)

.. function:: Friends.GetFriendRichPresenceKeyByIndex(steamIDFriend, iKey)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :param int iKey:
    :returns: (str) Return value
    :SteamWorks: `GetFriendRichPresenceKeyByIndex <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendRichPresenceKeyByIndex>`_

.. function:: Friends.GetFriendRichPresenceKeyCount(steamIDFriend)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :returns: (int) Return value
    :SteamWorks: `GetFriendRichPresenceKeyCount <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendRichPresenceKeyCount>`_

**Example**::

    local count = Steam.Friends.GetFriendRichPresenceKeyCount(friendID)
    for i = 0, count - 1 do
        local key = Steam.Friends.GetFriendRichPresenceKeyByIndex(friendID, i)
        local val = Steam.Friends.GetFriendRichPresence(friendID, key)
        print(key .. ' = ' .. val)
    end

.. function:: Friends.GetFriendSteamLevel(steamIDFriend)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :returns: (int) Return value
    :SteamWorks: `GetFriendSteamLevel <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendSteamLevel>`_

**Example**::

    local level = Steam.Friends.GetFriendSteamLevel(friendID)
    print('Friend Steam level:', level)

.. function:: Friends.GetFriendsGroupCount()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetFriendsGroupCount <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendsGroupCount>`_

**Example**::

    local groupCount = Steam.Friends.GetFriendsGroupCount()
    for i = 0, groupCount - 1 do
        local groupID = Steam.Friends.GetFriendsGroupIDByIndex(i)
        print('Group: ' .. Steam.Friends.GetFriendsGroupName(groupID))
    end

.. function:: Friends.GetFriendsGroupIDByIndex(iFG)

    🤖 **Auto-generated binding**

    :param int iFG:
    :returns: (int) Return value
    :SteamWorks: `GetFriendsGroupIDByIndex <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendsGroupIDByIndex>`_

.. function:: Friends.GetFriendsGroupMembersCount(friendsGroupID)

    🤖 **Auto-generated binding**

    :param int friendsGroupID:
    :returns: (int) Return value
    :SteamWorks: `GetFriendsGroupMembersCount <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendsGroupMembersCount>`_

.. function:: Friends.GetFriendsGroupMembersList(friendsGroupID, nMembersCount)

    🤖 **Auto-generated binding**

    :param int friendsGroupID:
    :param int nMembersCount:
    :returns: (uint64[]) Value for `pOutSteamIDMembers`
    :SteamWorks: `GetFriendsGroupMembersList <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendsGroupMembersList>`_

    **Signature differences from C++ API:**

    * Parameter ``pOutSteamIDMembers`` is no longer a paramer, and is instead an additional return value

.. function:: Friends.GetFriendsGroupName(friendsGroupID)

    🤖 **Auto-generated binding**

    :param int friendsGroupID:
    :returns: (str) Return value
    :SteamWorks: `GetFriendsGroupName <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendsGroupName>`_

.. function:: Friends.GetLargeFriendAvatar(steamIDFriend)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :returns: (int) Return value
    :SteamWorks: `GetLargeFriendAvatar <https://partner.steamgames.com/doc/api/ISteamFriends#GetLargeFriendAvatar>`_

.. function:: Friends.GetMediumFriendAvatar(steamIDFriend)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :returns: (int) Return value
    :SteamWorks: `GetMediumFriendAvatar <https://partner.steamgames.com/doc/api/ISteamFriends#GetMediumFriendAvatar>`_

**Example**::

    -- Returns an image handle; use Utils.GetImageRGBA to get pixel data
    local imageHandle = Steam.Friends.GetMediumFriendAvatar(friendID)

.. function:: Friends.GetNumChatsWithUnreadPriorityMessages()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetNumChatsWithUnreadPriorityMessages <https://partner.steamgames.com/doc/api/ISteamFriends#GetNumChatsWithUnreadPriorityMessages>`_

.. function:: Friends.GetPersonaName()

    🤖 **Auto-generated binding**

    :returns: (str) Return value
    :SteamWorks: `GetPersonaName <https://partner.steamgames.com/doc/api/ISteamFriends#GetPersonaName>`_

    Gets the current user's persona (display) name.

**Example**::

    print('My name is: ' .. Steam.Friends.GetPersonaName())

.. function:: Friends.GetPersonaState()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetPersonaState <https://partner.steamgames.com/doc/api/ISteamFriends#GetPersonaState>`_

**Example**::

    local state = Steam.Friends.GetPersonaState()
    if state == Steam.k_EPersonaStateOnline then
        print('User is online')
    end

.. function:: Friends.GetPlayerNickname(steamIDPlayer)

    🤖 **Auto-generated binding**

    :param uint64 steamIDPlayer:
    :returns: (str) Return value
    :SteamWorks: `GetPlayerNickname <https://partner.steamgames.com/doc/api/ISteamFriends#GetPlayerNickname>`_

**Example**::

    local nick = Steam.Friends.GetPlayerNickname(friendID)
    if nick then
        print('Your nickname for this friend: ' .. nick)
    end

.. function:: Friends.GetProfileItemPropertyString(steamID, itemType, prop)

    🤖 **Auto-generated binding**

    :param uint64 steamID:
    :param int itemType:
    :param int prop:
    :returns: (str) Return value
    :SteamWorks: `GetProfileItemPropertyString <https://partner.steamgames.com/doc/api/ISteamFriends#GetProfileItemPropertyString>`_

.. function:: Friends.GetProfileItemPropertyUint(steamID, itemType, prop)

    🤖 **Auto-generated binding**

    :param uint64 steamID:
    :param int itemType:
    :param int prop:
    :returns: (int) Return value
    :SteamWorks: `GetProfileItemPropertyUint <https://partner.steamgames.com/doc/api/ISteamFriends#GetProfileItemPropertyUint>`_

.. function:: Friends.GetSmallFriendAvatar(steamIDFriend)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :returns: (int) Return value
    :SteamWorks: `GetSmallFriendAvatar <https://partner.steamgames.com/doc/api/ISteamFriends#GetSmallFriendAvatar>`_

**Example**::

    local imageHandle = Steam.Friends.GetSmallFriendAvatar(friendID)
    if imageHandle > 0 then
        local w, h = Steam.Utils.GetImageSize(imageHandle)
        local rgba = Steam.Utils.GetImageRGBA(imageHandle, w * h * 4)
        renderAvatar(rgba, w, h)
    end

.. function:: Friends.HasFriend(steamIDFriend, iFriendFlags)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :param int iFriendFlags:
    :returns: (bool) Return value
    :SteamWorks: `HasFriend <https://partner.steamgames.com/doc/api/ISteamFriends#HasFriend>`_

**Example**::

    if Steam.Friends.HasFriend(playerID, Steam.k_EFriendFlagImmediate) then
        print('This player is a direct friend')
    end

.. function:: Friends.InviteUserToGame(steamIDFriend, pchConnectString)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :param str pchConnectString:
    :returns: (bool) Return value
    :SteamWorks: `InviteUserToGame <https://partner.steamgames.com/doc/api/ISteamFriends#InviteUserToGame>`_

**Example**::

    -- Invite a friend to your server
    Steam.Friends.InviteUserToGame(friend_id, '+connect 1.2.3.4:27015')

.. function:: Friends.IsClanChatAdmin(steamIDClanChat, steamIDUser)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClanChat:
    :param uint64 steamIDUser:
    :returns: (bool) Return value
    :SteamWorks: `IsClanChatAdmin <https://partner.steamgames.com/doc/api/ISteamFriends#IsClanChatAdmin>`_

.. function:: Friends.IsClanChatWindowOpenInSteam(steamIDClanChat)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClanChat:
    :returns: (bool) Return value
    :SteamWorks: `IsClanChatWindowOpenInSteam <https://partner.steamgames.com/doc/api/ISteamFriends#IsClanChatWindowOpenInSteam>`_

.. function:: Friends.IsClanOfficialGameGroup(steamIDClan)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClan:
    :returns: (bool) Return value
    :SteamWorks: `IsClanOfficialGameGroup <https://partner.steamgames.com/doc/api/ISteamFriends#IsClanOfficialGameGroup>`_

.. function:: Friends.IsClanPublic(steamIDClan)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClan:
    :returns: (bool) Return value
    :SteamWorks: `IsClanPublic <https://partner.steamgames.com/doc/api/ISteamFriends#IsClanPublic>`_

.. function:: Friends.IsFollowing(steamID, callback)

    🤖 **Auto-generated binding**

    :param uint64 steamID:
    :param function callback: CallResult callback receiving struct `FriendsIsFollowing_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `IsFollowing <https://partner.steamgames.com/doc/api/ISteamFriends#IsFollowing>`_

**Example**::

    Steam.Friends.IsFollowing(playerID, function(data, err)
        if not err then
            print('Following:', data.m_bIsFollowing ~= 0)
        end
    end)

.. function:: Friends.IsUserInSource(steamIDUser, steamIDSource)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param uint64 steamIDSource:
    :returns: (bool) Return value
    :SteamWorks: `IsUserInSource <https://partner.steamgames.com/doc/api/ISteamFriends#IsUserInSource>`_

.. function:: Friends.JoinClanChatRoom(steamIDClan, callback)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClan:
    :param function callback: CallResult callback receiving struct `JoinClanChatRoomCompletionResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `JoinClanChatRoom <https://partner.steamgames.com/doc/api/ISteamFriends#JoinClanChatRoom>`_

**Example**::

    Steam.Friends.JoinClanChatRoom(clanID, function(data, err)
        if not err and data.m_eChatRoomEnterResponse == 1 then
            print('Joined clan chat')
        end
    end)

.. function:: Friends.LeaveClanChatRoom(steamIDClan)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClan:
    :returns: (bool) Return value
    :SteamWorks: `LeaveClanChatRoom <https://partner.steamgames.com/doc/api/ISteamFriends#LeaveClanChatRoom>`_

.. function:: Friends.OpenClanChatWindowInSteam(steamIDClanChat)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClanChat:
    :returns: (bool) Return value
    :SteamWorks: `OpenClanChatWindowInSteam <https://partner.steamgames.com/doc/api/ISteamFriends#OpenClanChatWindowInSteam>`_

.. function:: Friends.RegisterProtocolInOverlayBrowser(pchProtocol)

    🤖 **Auto-generated binding**

    :param str pchProtocol:
    :returns: (bool) Return value
    :SteamWorks: `RegisterProtocolInOverlayBrowser <https://partner.steamgames.com/doc/api/ISteamFriends#RegisterProtocolInOverlayBrowser>`_

.. function:: Friends.ReplyToFriendMessage(steamIDFriend, pchMsgToSend)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :param str pchMsgToSend:
    :returns: (bool) Return value
    :SteamWorks: `ReplyToFriendMessage <https://partner.steamgames.com/doc/api/ISteamFriends#ReplyToFriendMessage>`_

.. function:: Friends.RequestClanOfficerList(steamIDClan, callback)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClan:
    :param function callback: CallResult callback receiving struct `ClanOfficerListResponse_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `RequestClanOfficerList <https://partner.steamgames.com/doc/api/ISteamFriends#RequestClanOfficerList>`_

.. function:: Friends.RequestEquippedProfileItems(steamID, callback)

    🤖 **Auto-generated binding**

    :param uint64 steamID:
    :param function callback: CallResult callback receiving struct `EquippedProfileItems_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `RequestEquippedProfileItems <https://partner.steamgames.com/doc/api/ISteamFriends#RequestEquippedProfileItems>`_

.. function:: Friends.RequestFriendRichPresence(steamIDFriend)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :SteamWorks: `RequestFriendRichPresence <https://partner.steamgames.com/doc/api/ISteamFriends#RequestFriendRichPresence>`_

**Example**::

    -- Request fresh rich presence data for a friend
    Steam.Friends.RequestFriendRichPresence(friendID)

.. function:: Friends.RequestUserInformation(steamIDUser, bRequireNameOnly)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param bool bRequireNameOnly:
    :returns: (bool) Return value
    :SteamWorks: `RequestUserInformation <https://partner.steamgames.com/doc/api/ISteamFriends#RequestUserInformation>`_

**Example**::

    -- Request the player name and avatar; returns true if data needs to be fetched
    local needsData = Steam.Friends.RequestUserInformation(playerID, true)
    if needsData then
        -- Wait for OnPersonaStateChange callback
    end

.. function:: Friends.SendClanChatMessage(steamIDClanChat, pchText)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClanChat:
    :param str pchText:
    :returns: (bool) Return value
    :SteamWorks: `SendClanChatMessage <https://partner.steamgames.com/doc/api/ISteamFriends#SendClanChatMessage>`_

**Example**::

    Steam.Friends.SendClanChatMessage(clanChatID, 'Hello clan!')

.. function:: Friends.SetInGameVoiceSpeaking(steamIDUser, bSpeaking)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param bool bSpeaking:
    :SteamWorks: `SetInGameVoiceSpeaking <https://partner.steamgames.com/doc/api/ISteamFriends#SetInGameVoiceSpeaking>`_

**Example**::

    -- Notify Steam that this user is speaking in-game
    Steam.Friends.SetInGameVoiceSpeaking(Steam.User.GetSteamID(), true)

.. function:: Friends.SetListenForFriendsMessages(bInterceptEnabled)

    🤖 **Auto-generated binding**

    :param bool bInterceptEnabled:
    :returns: (bool) Return value
    :SteamWorks: `SetListenForFriendsMessages <https://partner.steamgames.com/doc/api/ISteamFriends#SetListenForFriendsMessages>`_

**Example**::

    -- Enable friend message interception
    Steam.Friends.SetListenForFriendsMessages(true)

.. function:: Friends.SetPlayedWith(steamIDUserPlayedWith)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUserPlayedWith:
    :SteamWorks: `SetPlayedWith <https://partner.steamgames.com/doc/api/ISteamFriends#SetPlayedWith>`_

**Example**::

    for _, playerID in ipairs(currentPlayers) do
        Steam.Friends.SetPlayedWith(playerID)
    end

.. function:: Friends.SetRichPresence(pchKey, pchValue)

    🤖 **Auto-generated binding**

    :param str pchKey: The Rich Presence key to set
    :param str pchValue: The value to associate with the key
    :returns: (bool) Return value
    :SteamWorks: `SetRichPresence <https://partner.steamgames.com/doc/api/ISteamFriends#SetRichPresence>`_

    Sets a Rich Presence key/value for the current user that is shared with friends.

**Example**::

    Steam.Friends.SetRichPresence('steam_display', '#StatusWithScore')
    Steam.Friends.SetRichPresence('score', tostring(myScore))


Callbacks
---------

.. function:: Friends.OnPersonaStateChange

    Callback for `PersonaStateChange_t <https://partner.steamgames.com/doc/api/ISteamFriends#PersonaStateChange_t>`_

    **callback(data)** receives:

    * **data.m_ulSteamID** -- m_ulSteamID
    * **data.m_nChangeFlags** -- m_nChangeFlags

**Example**::

    function Steam.Friends.OnPersonaStateChange(data)
        local name = Steam.Friends.GetFriendPersonaName(data.m_ulSteamID)
        print('Persona changed for:', name)
    end

.. function:: Friends.OnGameOverlayActivated

    Callback for `GameOverlayActivated_t <https://partner.steamgames.com/doc/api/ISteamFriends#GameOverlayActivated_t>`_

    **callback(data)** receives:

    * **data.m_bActive** -- m_bActive
    * **data.m_bUserInitiated** -- m_bUserInitiated
    * **data.m_nAppID** -- m_nAppID
    * **data.m_dwOverlayPID** -- m_dwOverlayPID

**Example**::

    function Steam.Friends.OnGameOverlayActivated(data)
        if data.m_bActive == 1 then
            print('Game overlay opened, pausing game')
        else
            print('Game overlay closed, resuming game')
        end
    end

.. function:: Friends.OnGameServerChangeRequested

    Callback for `GameServerChangeRequested_t <https://partner.steamgames.com/doc/api/ISteamFriends#GameServerChangeRequested_t>`_

    **callback(data)** receives:

    * **data.m_rgchServer** -- m_rgchServer
    * **data.m_rgchPassword** -- m_rgchPassword

**Example**::

    function Steam.Friends.OnGameServerChangeRequested(data)
        print('Friend invites you to server:', data.m_rgchServer)
        connectToServer(data.m_rgchServer, data.m_rgchPassword)
    end

.. function:: Friends.OnGameLobbyJoinRequested

    Callback for `GameLobbyJoinRequested_t <https://partner.steamgames.com/doc/api/ISteamFriends#GameLobbyJoinRequested_t>`_

    **callback(data)** receives:

    * **data.m_steamIDLobby** -- m_steamIDLobby
    * **data.m_steamIDFriend** -- m_steamIDFriend

**Example**::

    function Steam.Friends.OnGameLobbyJoinRequested(data)
        Steam.Matchmaking.JoinLobby(data.m_steamIDLobby, function(result, err)
            if not err and result.m_EChatRoomEnterResponse == 1 then
                print('Joined lobby from friend invite')
            end
        end)
    end

.. function:: Friends.OnAvatarImageLoaded

    Callback for `AvatarImageLoaded_t <https://partner.steamgames.com/doc/api/ISteamFriends#AvatarImageLoaded_t>`_

    **callback(data)** receives:

    * **data.m_steamID** -- m_steamID
    * **data.m_iImage** -- m_iImage
    * **data.m_iWide** -- m_iWide
    * **data.m_iTall** -- m_iTall

**Example**::

    function Steam.Friends.OnAvatarImageLoaded(data)
        local w, h = Steam.Utils.GetImageSize(data.m_iImage)
        local rgba = Steam.Utils.GetImageRGBA(data.m_iImage, w * h * 4)
        updateAvatarTexture(data.m_steamID, rgba, w, h)
    end

.. function:: Friends.OnClanOfficerListResponse

    Callback for `ClanOfficerListResponse_t <https://partner.steamgames.com/doc/api/ISteamFriends#ClanOfficerListResponse_t>`_

    **callback(data)** receives:

    * **data.m_steamIDClan** -- m_steamIDClan
    * **data.m_cOfficers** -- m_cOfficers
    * **data.m_bSuccess** -- m_bSuccess

.. function:: Friends.OnFriendRichPresenceUpdate

    Callback for `FriendRichPresenceUpdate_t <https://partner.steamgames.com/doc/api/ISteamFriends#FriendRichPresenceUpdate_t>`_

    **callback(data)** receives:

    * **data.m_steamIDFriend** -- m_steamIDFriend
    * **data.m_nAppID** -- m_nAppID

**Example**::

    function Steam.Friends.OnFriendRichPresenceUpdate(data)
        local status = Steam.Friends.GetFriendRichPresence(data.m_steamIDFriend, 'status')
        print('Friend presence updated:', status)
    end

.. function:: Friends.OnGameRichPresenceJoinRequested

    Callback for `GameRichPresenceJoinRequested_t <https://partner.steamgames.com/doc/api/ISteamFriends#GameRichPresenceJoinRequested_t>`_

    **callback(data)** receives:

    * **data.m_steamIDFriend** -- m_steamIDFriend
    * **data.m_rgchConnect** -- m_rgchConnect

**Example**::

    function Steam.Friends.OnGameRichPresenceJoinRequested(data)
        local connect_string = data.m_rgchConnect
        initiateJoinGame(connect_string)
    end

.. function:: Friends.OnGameConnectedClanChatMsg

    Callback for `GameConnectedClanChatMsg_t <https://partner.steamgames.com/doc/api/ISteamFriends#GameConnectedClanChatMsg_t>`_

    **callback(data)** receives:

    * **data.m_steamIDClanChat** -- m_steamIDClanChat
    * **data.m_steamIDUser** -- m_steamIDUser
    * **data.m_iMessageID** -- m_iMessageID

.. function:: Friends.OnGameConnectedChatJoin

    Callback for `GameConnectedChatJoin_t <https://partner.steamgames.com/doc/api/ISteamFriends#GameConnectedChatJoin_t>`_

    **callback(data)** receives:

    * **data.m_steamIDClanChat** -- m_steamIDClanChat
    * **data.m_steamIDUser** -- m_steamIDUser

.. function:: Friends.OnGameConnectedChatLeave

    Callback for `GameConnectedChatLeave_t <https://partner.steamgames.com/doc/api/ISteamFriends#GameConnectedChatLeave_t>`_

    **callback(data)** receives:

    * **data.m_steamIDClanChat** -- m_steamIDClanChat
    * **data.m_steamIDUser** -- m_steamIDUser
    * **data.m_bKicked** -- m_bKicked
    * **data.m_bDropped** -- m_bDropped

.. function:: Friends.OnDownloadClanActivityCountsResult

    Callback for `DownloadClanActivityCountsResult_t <https://partner.steamgames.com/doc/api/ISteamFriends#DownloadClanActivityCountsResult_t>`_

    **callback(data)** receives:

    * **data.m_bSuccess** -- m_bSuccess

.. function:: Friends.OnJoinClanChatRoomCompletionResult

    Callback for `JoinClanChatRoomCompletionResult_t <https://partner.steamgames.com/doc/api/ISteamFriends#JoinClanChatRoomCompletionResult_t>`_

    **callback(data)** receives:

    * **data.m_steamIDClanChat** -- m_steamIDClanChat
    * **data.m_eChatRoomEnterResponse** -- m_eChatRoomEnterResponse

.. function:: Friends.OnGameConnectedFriendChatMsg

    Callback for `GameConnectedFriendChatMsg_t <https://partner.steamgames.com/doc/api/ISteamFriends#GameConnectedFriendChatMsg_t>`_

    **callback(data)** receives:

    * **data.m_steamIDUser** -- m_steamIDUser
    * **data.m_iMessageID** -- m_iMessageID

**Example**::

    function Steam.Friends.OnGameConnectedFriendChatMsg(data)
        local msg, chatType = Steam.Friends.GetFriendMessage(data.m_steamIDUser, data.m_iMessageID, 512)
        print('Friend chat:', msg)
    end

.. function:: Friends.OnFriendsGetFollowerCount

    Callback for `FriendsGetFollowerCount_t <https://partner.steamgames.com/doc/api/ISteamFriends#FriendsGetFollowerCount_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_steamID** -- m_steamID
    * **data.m_nCount** -- m_nCount

.. function:: Friends.OnFriendsIsFollowing

    Callback for `FriendsIsFollowing_t <https://partner.steamgames.com/doc/api/ISteamFriends#FriendsIsFollowing_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_steamID** -- m_steamID
    * **data.m_bIsFollowing** -- m_bIsFollowing

.. function:: Friends.OnFriendsEnumerateFollowingList

    Callback for `FriendsEnumerateFollowingList_t <https://partner.steamgames.com/doc/api/ISteamFriends#FriendsEnumerateFollowingList_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_rgSteamID** -- m_rgSteamID
    * **data.m_nResultsReturned** -- m_nResultsReturned
    * **data.m_nTotalResultCount** -- m_nTotalResultCount

.. function:: Friends.OnUnreadChatMessagesChanged

    Callback for `UnreadChatMessagesChanged_t <https://partner.steamgames.com/doc/api/ISteamFriends#UnreadChatMessagesChanged_t>`_

    **callback(data)** receives:


**Example**::

    function Steam.Friends.OnUnreadChatMessagesChanged()
        local count = Steam.Friends.GetNumChatsWithUnreadPriorityMessages()
        if count > 0 then
            print('You have', count, 'unread priority messages')
        end
    end

.. function:: Friends.OnOverlayBrowserProtocolNavigation

    Callback for `OverlayBrowserProtocolNavigation_t <https://partner.steamgames.com/doc/api/ISteamFriends#OverlayBrowserProtocolNavigation_t>`_

    **callback(data)** receives:

    * **data.rgchURI** -- rgchURI

.. function:: Friends.OnEquippedProfileItemsChanged

    Callback for `EquippedProfileItemsChanged_t <https://partner.steamgames.com/doc/api/ISteamFriends#EquippedProfileItemsChanged_t>`_

    **callback(data)** receives:

    * **data.m_steamID** -- m_steamID

.. function:: Friends.OnEquippedProfileItems

    Callback for `EquippedProfileItems_t <https://partner.steamgames.com/doc/api/ISteamFriends#EquippedProfileItems_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_steamID** -- m_steamID
    * **data.m_bHasAnimatedAvatar** -- m_bHasAnimatedAvatar
    * **data.m_bHasAvatarFrame** -- m_bHasAvatarFrame
    * **data.m_bHasProfileModifier** -- m_bHasProfileModifier
    * **data.m_bHasProfileBackground** -- m_bHasProfileBackground
    * **data.m_bHasMiniProfileBackground** -- m_bHasMiniProfileBackground
    * **data.m_bFromCache** -- m_bFromCache

