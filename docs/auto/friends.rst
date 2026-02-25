#############
ISteamFriends
#############

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✋ require manual implementation.

List of Functions
-----------------

* :func:`Friends.GetPersonaName`
* :func:`Friends.GetPersonaState`
* :func:`Friends.GetFriendCount`
* :func:`Friends.GetFriendByIndex`
* :func:`Friends.GetFriendRelationship`
* :func:`Friends.GetFriendPersonaState`
* :func:`Friends.GetFriendPersonaName`
* :func:`Friends.GetFriendGamePlayed`
* :func:`Friends.GetFriendPersonaNameHistory`
* :func:`Friends.GetFriendSteamLevel`
* :func:`Friends.GetPlayerNickname`
* :func:`Friends.GetFriendsGroupCount`
* :func:`Friends.GetFriendsGroupIDByIndex`
* :func:`Friends.GetFriendsGroupName`
* :func:`Friends.GetFriendsGroupMembersCount`
* :func:`Friends.GetFriendsGroupMembersList`
* :func:`Friends.HasFriend`
* :func:`Friends.GetClanCount`
* :func:`Friends.GetClanByIndex`
* :func:`Friends.GetClanName`
* :func:`Friends.GetClanTag`
* :func:`Friends.GetClanActivityCounts`
* :func:`Friends.DownloadClanActivityCounts`
* :func:`Friends.GetFriendCountFromSource`
* :func:`Friends.GetFriendFromSourceByIndex`
* :func:`Friends.IsUserInSource`
* :func:`Friends.SetInGameVoiceSpeaking`
* :func:`Friends.ActivateGameOverlay`
* :func:`Friends.ActivateGameOverlayToUser`
* :func:`Friends.ActivateGameOverlayToWebPage`
* :func:`Friends.ActivateGameOverlayToStore`
* :func:`Friends.SetPlayedWith`
* :func:`Friends.ActivateGameOverlayInviteDialog`
* :func:`Friends.GetSmallFriendAvatar`
* :func:`Friends.GetMediumFriendAvatar`
* :func:`Friends.GetLargeFriendAvatar`
* :func:`Friends.RequestUserInformation`
* :func:`Friends.RequestClanOfficerList`
* :func:`Friends.GetClanOwner`
* :func:`Friends.GetClanOfficerCount`
* :func:`Friends.GetClanOfficerByIndex`
* :func:`Friends.SetRichPresence`
* :func:`Friends.ClearRichPresence`
* :func:`Friends.GetFriendRichPresence`
* :func:`Friends.GetFriendRichPresenceKeyCount`
* :func:`Friends.GetFriendRichPresenceKeyByIndex`
* :func:`Friends.RequestFriendRichPresence`
* :func:`Friends.InviteUserToGame`
* :func:`Friends.GetCoplayFriendCount`
* :func:`Friends.GetCoplayFriend`
* :func:`Friends.GetFriendCoplayTime`
* :func:`Friends.GetFriendCoplayGame`
* :func:`Friends.JoinClanChatRoom`
* :func:`Friends.LeaveClanChatRoom`
* :func:`Friends.GetClanChatMemberCount`
* :func:`Friends.GetChatMemberByIndex`
* :func:`Friends.SendClanChatMessage`
* :func:`Friends.GetClanChatMessage`
* :func:`Friends.IsClanChatAdmin`
* :func:`Friends.IsClanChatWindowOpenInSteam`
* :func:`Friends.OpenClanChatWindowInSteam`
* :func:`Friends.CloseClanChatWindowInSteam`
* :func:`Friends.SetListenForFriendsMessages`
* :func:`Friends.ReplyToFriendMessage`
* :func:`Friends.GetFriendMessage`
* :func:`Friends.GetFollowerCount`
* :func:`Friends.IsFollowing`
* :func:`Friends.EnumerateFollowingList`
* :func:`Friends.IsClanPublic`
* :func:`Friends.IsClanOfficialGameGroup`
* :func:`Friends.GetNumChatsWithUnreadPriorityMessages`
* :func:`Friends.ActivateGameOverlayRemotePlayTogetherInviteDialog`
* :func:`Friends.RegisterProtocolInOverlayBrowser`
* :func:`Friends.ActivateGameOverlayInviteDialogConnectString`
* :func:`Friends.RequestEquippedProfileItems`
* :func:`Friends.BHasEquippedProfileItem`
* :func:`Friends.GetProfileItemPropertyString`
* :func:`Friends.GetProfileItemPropertyUint`

List of Callbacks
-----------------

* :func:`Friends.onPersonaStateChange`
* :func:`Friends.onGameOverlayActivated`
* :func:`Friends.onGameServerChangeRequested`
* :func:`Friends.onGameLobbyJoinRequested`
* :func:`Friends.onAvatarImageLoaded`
* :func:`Friends.onClanOfficerListResponse`
* :func:`Friends.onFriendRichPresenceUpdate`
* :func:`Friends.onGameRichPresenceJoinRequested`
* :func:`Friends.onGameConnectedClanChatMsg`
* :func:`Friends.onGameConnectedChatJoin`
* :func:`Friends.onGameConnectedChatLeave`
* :func:`Friends.onDownloadClanActivityCountsResult`
* :func:`Friends.onJoinClanChatRoomCompletionResult`
* :func:`Friends.onGameConnectedFriendChatMsg`
* :func:`Friends.onFriendsGetFollowerCount`
* :func:`Friends.onFriendsIsFollowing`
* :func:`Friends.onFriendsEnumerateFollowingList`
* :func:`Friends.onUnreadChatMessagesChanged`
* :func:`Friends.onOverlayBrowserProtocolNavigation`
* :func:`Friends.onEquippedProfileItemsChanged`
* :func:`Friends.onEquippedProfileItems`

Function Reference
------------------

.. function:: Friends.GetPersonaName()

    🤖 **Auto-generated binding**

    :returns: (str) Return value
    :SteamWorks: `GetPersonaName <https://partner.steamgames.com/doc/api/ISteamFriends#GetPersonaName>`_

.. function:: Friends.GetPersonaState()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetPersonaState <https://partner.steamgames.com/doc/api/ISteamFriends#GetPersonaState>`_

.. function:: Friends.GetFriendCount(iFriendFlags)

    🤖 **Auto-generated binding**

    :param int iFriendFlags:
    :returns: (int) Return value
    :SteamWorks: `GetFriendCount <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendCount>`_

.. function:: Friends.GetFriendByIndex(iFriend, iFriendFlags)

    🤖 **Auto-generated binding**

    :param int iFriend:
    :param int iFriendFlags:
    :returns: (uint64) Return value
    :SteamWorks: `GetFriendByIndex <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendByIndex>`_

.. function:: Friends.GetFriendRelationship(steamIDFriend)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :returns: (int) Return value
    :SteamWorks: `GetFriendRelationship <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendRelationship>`_

.. function:: Friends.GetFriendPersonaState(steamIDFriend)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :returns: (int) Return value
    :SteamWorks: `GetFriendPersonaState <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendPersonaState>`_

.. function:: Friends.GetFriendPersonaName(steamIDFriend)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :returns: (str) Return value
    :SteamWorks: `GetFriendPersonaName <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendPersonaName>`_

.. function:: Friends.GetFriendGamePlayed(steamIDFriend)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :returns: (bool) Return value
    :returns: (:ref:`FriendGameInfo_t <struct-FriendGameInfo_t>`) Value for `pFriendGameInfo`
    :SteamWorks: `GetFriendGamePlayed <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendGamePlayed>`_

    **Signature differences from C++ API:**

    * Parameter ``pFriendGameInfo`` is no longer a paramer, and is instead an additional return value

.. function:: Friends.GetFriendPersonaNameHistory(steamIDFriend, iPersonaName)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :param int iPersonaName:
    :returns: (str) Return value
    :SteamWorks: `GetFriendPersonaNameHistory <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendPersonaNameHistory>`_

.. function:: Friends.GetFriendSteamLevel(steamIDFriend)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :returns: (int) Return value
    :SteamWorks: `GetFriendSteamLevel <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendSteamLevel>`_

.. function:: Friends.GetPlayerNickname(steamIDPlayer)

    🤖 **Auto-generated binding**

    :param uint64 steamIDPlayer:
    :returns: (str) Return value
    :SteamWorks: `GetPlayerNickname <https://partner.steamgames.com/doc/api/ISteamFriends#GetPlayerNickname>`_

.. function:: Friends.GetFriendsGroupCount()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetFriendsGroupCount <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendsGroupCount>`_

.. function:: Friends.GetFriendsGroupIDByIndex(iFG)

    🤖 **Auto-generated binding**

    :param int iFG:
    :returns: (int) Return value
    :SteamWorks: `GetFriendsGroupIDByIndex <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendsGroupIDByIndex>`_

.. function:: Friends.GetFriendsGroupName(friendsGroupID)

    🤖 **Auto-generated binding**

    :param int friendsGroupID:
    :returns: (str) Return value
    :SteamWorks: `GetFriendsGroupName <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendsGroupName>`_

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

.. function:: Friends.HasFriend(steamIDFriend, iFriendFlags)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :param int iFriendFlags:
    :returns: (bool) Return value
    :SteamWorks: `HasFriend <https://partner.steamgames.com/doc/api/ISteamFriends#HasFriend>`_

.. function:: Friends.GetClanCount()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetClanCount <https://partner.steamgames.com/doc/api/ISteamFriends#GetClanCount>`_

.. function:: Friends.GetClanByIndex(iClan)

    🤖 **Auto-generated binding**

    :param int iClan:
    :returns: (uint64) Return value
    :SteamWorks: `GetClanByIndex <https://partner.steamgames.com/doc/api/ISteamFriends#GetClanByIndex>`_

.. function:: Friends.GetClanName(steamIDClan)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClan:
    :returns: (str) Return value
    :SteamWorks: `GetClanName <https://partner.steamgames.com/doc/api/ISteamFriends#GetClanName>`_

.. function:: Friends.GetClanTag(steamIDClan)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClan:
    :returns: (str) Return value
    :SteamWorks: `GetClanTag <https://partner.steamgames.com/doc/api/ISteamFriends#GetClanTag>`_

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

.. function:: Friends.DownloadClanActivityCounts(cClansToRequest, callback)

    🤖 **Auto-generated binding**

    :param int cClansToRequest:
    :param function callback: CallResult callback receiving struct `DownloadClanActivityCountsResult_t` and a boolean
    :returns: (uint64) Return value
    :returns: (uint64[]) Value for `psteamIDClans`
    :SteamWorks: `DownloadClanActivityCounts <https://partner.steamgames.com/doc/api/ISteamFriends#DownloadClanActivityCounts>`_

    **Signature differences from C++ API:**

    * Parameter ``psteamIDClans`` is no longer a paramer, and is instead an additional return value

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

.. function:: Friends.IsUserInSource(steamIDUser, steamIDSource)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param uint64 steamIDSource:
    :returns: (bool) Return value
    :SteamWorks: `IsUserInSource <https://partner.steamgames.com/doc/api/ISteamFriends#IsUserInSource>`_

.. function:: Friends.SetInGameVoiceSpeaking(steamIDUser, bSpeaking)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param bool bSpeaking:
    :SteamWorks: `SetInGameVoiceSpeaking <https://partner.steamgames.com/doc/api/ISteamFriends#SetInGameVoiceSpeaking>`_

.. function:: Friends.ActivateGameOverlay(pchDialog)

    🤖 **Auto-generated binding**

    :param str pchDialog:
    :SteamWorks: `ActivateGameOverlay <https://partner.steamgames.com/doc/api/ISteamFriends#ActivateGameOverlay>`_

.. function:: Friends.ActivateGameOverlayToUser(pchDialog, steamID)

    🤖 **Auto-generated binding**

    :param str pchDialog:
    :param uint64 steamID:
    :SteamWorks: `ActivateGameOverlayToUser <https://partner.steamgames.com/doc/api/ISteamFriends#ActivateGameOverlayToUser>`_

.. function:: Friends.ActivateGameOverlayToWebPage(pchURL, eMode)

    🤖 **Auto-generated binding**

    :param str pchURL:
    :param int eMode:
    :SteamWorks: `ActivateGameOverlayToWebPage <https://partner.steamgames.com/doc/api/ISteamFriends#ActivateGameOverlayToWebPage>`_

.. function:: Friends.ActivateGameOverlayToStore(nAppID, eFlag)

    🤖 **Auto-generated binding**

    :param int nAppID:
    :param int eFlag:
    :SteamWorks: `ActivateGameOverlayToStore <https://partner.steamgames.com/doc/api/ISteamFriends#ActivateGameOverlayToStore>`_

.. function:: Friends.SetPlayedWith(steamIDUserPlayedWith)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUserPlayedWith:
    :SteamWorks: `SetPlayedWith <https://partner.steamgames.com/doc/api/ISteamFriends#SetPlayedWith>`_

.. function:: Friends.ActivateGameOverlayInviteDialog(steamIDLobby)

    🤖 **Auto-generated binding**

    :param uint64 steamIDLobby:
    :SteamWorks: `ActivateGameOverlayInviteDialog <https://partner.steamgames.com/doc/api/ISteamFriends#ActivateGameOverlayInviteDialog>`_

.. function:: Friends.GetSmallFriendAvatar(steamIDFriend)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :returns: (int) Return value
    :SteamWorks: `GetSmallFriendAvatar <https://partner.steamgames.com/doc/api/ISteamFriends#GetSmallFriendAvatar>`_

.. function:: Friends.GetMediumFriendAvatar(steamIDFriend)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :returns: (int) Return value
    :SteamWorks: `GetMediumFriendAvatar <https://partner.steamgames.com/doc/api/ISteamFriends#GetMediumFriendAvatar>`_

.. function:: Friends.GetLargeFriendAvatar(steamIDFriend)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :returns: (int) Return value
    :SteamWorks: `GetLargeFriendAvatar <https://partner.steamgames.com/doc/api/ISteamFriends#GetLargeFriendAvatar>`_

.. function:: Friends.RequestUserInformation(steamIDUser, bRequireNameOnly)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param bool bRequireNameOnly:
    :returns: (bool) Return value
    :SteamWorks: `RequestUserInformation <https://partner.steamgames.com/doc/api/ISteamFriends#RequestUserInformation>`_

.. function:: Friends.RequestClanOfficerList(steamIDClan, callback)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClan:
    :param function callback: CallResult callback receiving struct `ClanOfficerListResponse_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `RequestClanOfficerList <https://partner.steamgames.com/doc/api/ISteamFriends#RequestClanOfficerList>`_

.. function:: Friends.GetClanOwner(steamIDClan)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClan:
    :returns: (uint64) Return value
    :SteamWorks: `GetClanOwner <https://partner.steamgames.com/doc/api/ISteamFriends#GetClanOwner>`_

.. function:: Friends.GetClanOfficerCount(steamIDClan)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClan:
    :returns: (int) Return value
    :SteamWorks: `GetClanOfficerCount <https://partner.steamgames.com/doc/api/ISteamFriends#GetClanOfficerCount>`_

.. function:: Friends.GetClanOfficerByIndex(steamIDClan, iOfficer)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClan:
    :param int iOfficer:
    :returns: (uint64) Return value
    :SteamWorks: `GetClanOfficerByIndex <https://partner.steamgames.com/doc/api/ISteamFriends#GetClanOfficerByIndex>`_

.. function:: Friends.SetRichPresence(pchKey, pchValue)

    🤖 **Auto-generated binding**

    :param str pchKey:
    :param str pchValue:
    :returns: (bool) Return value
    :SteamWorks: `SetRichPresence <https://partner.steamgames.com/doc/api/ISteamFriends#SetRichPresence>`_

.. function:: Friends.ClearRichPresence()

    🤖 **Auto-generated binding**

    :SteamWorks: `ClearRichPresence <https://partner.steamgames.com/doc/api/ISteamFriends#ClearRichPresence>`_

.. function:: Friends.GetFriendRichPresence(steamIDFriend, pchKey)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :param str pchKey:
    :returns: (str) Return value
    :SteamWorks: `GetFriendRichPresence <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendRichPresence>`_

.. function:: Friends.GetFriendRichPresenceKeyCount(steamIDFriend)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :returns: (int) Return value
    :SteamWorks: `GetFriendRichPresenceKeyCount <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendRichPresenceKeyCount>`_

.. function:: Friends.GetFriendRichPresenceKeyByIndex(steamIDFriend, iKey)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :param int iKey:
    :returns: (str) Return value
    :SteamWorks: `GetFriendRichPresenceKeyByIndex <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendRichPresenceKeyByIndex>`_

.. function:: Friends.RequestFriendRichPresence(steamIDFriend)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :SteamWorks: `RequestFriendRichPresence <https://partner.steamgames.com/doc/api/ISteamFriends#RequestFriendRichPresence>`_

.. function:: Friends.InviteUserToGame(steamIDFriend, pchConnectString)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :param str pchConnectString:
    :returns: (bool) Return value
    :SteamWorks: `InviteUserToGame <https://partner.steamgames.com/doc/api/ISteamFriends#InviteUserToGame>`_

.. function:: Friends.GetCoplayFriendCount()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetCoplayFriendCount <https://partner.steamgames.com/doc/api/ISteamFriends#GetCoplayFriendCount>`_

.. function:: Friends.GetCoplayFriend(iCoplayFriend)

    🤖 **Auto-generated binding**

    :param int iCoplayFriend:
    :returns: (uint64) Return value
    :SteamWorks: `GetCoplayFriend <https://partner.steamgames.com/doc/api/ISteamFriends#GetCoplayFriend>`_

.. function:: Friends.GetFriendCoplayTime(steamIDFriend)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :returns: (int) Return value
    :SteamWorks: `GetFriendCoplayTime <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendCoplayTime>`_

.. function:: Friends.GetFriendCoplayGame(steamIDFriend)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :returns: (int) Return value
    :SteamWorks: `GetFriendCoplayGame <https://partner.steamgames.com/doc/api/ISteamFriends#GetFriendCoplayGame>`_

.. function:: Friends.JoinClanChatRoom(steamIDClan, callback)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClan:
    :param function callback: CallResult callback receiving struct `JoinClanChatRoomCompletionResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `JoinClanChatRoom <https://partner.steamgames.com/doc/api/ISteamFriends#JoinClanChatRoom>`_

.. function:: Friends.LeaveClanChatRoom(steamIDClan)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClan:
    :returns: (bool) Return value
    :SteamWorks: `LeaveClanChatRoom <https://partner.steamgames.com/doc/api/ISteamFriends#LeaveClanChatRoom>`_

.. function:: Friends.GetClanChatMemberCount(steamIDClan)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClan:
    :returns: (int) Return value
    :SteamWorks: `GetClanChatMemberCount <https://partner.steamgames.com/doc/api/ISteamFriends#GetClanChatMemberCount>`_

.. function:: Friends.GetChatMemberByIndex(steamIDClan, iUser)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClan:
    :param int iUser:
    :returns: (uint64) Return value
    :SteamWorks: `GetChatMemberByIndex <https://partner.steamgames.com/doc/api/ISteamFriends#GetChatMemberByIndex>`_

.. function:: Friends.SendClanChatMessage(steamIDClanChat, pchText)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClanChat:
    :param str pchText:
    :returns: (bool) Return value
    :SteamWorks: `SendClanChatMessage <https://partner.steamgames.com/doc/api/ISteamFriends#SendClanChatMessage>`_

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

.. function:: Friends.OpenClanChatWindowInSteam(steamIDClanChat)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClanChat:
    :returns: (bool) Return value
    :SteamWorks: `OpenClanChatWindowInSteam <https://partner.steamgames.com/doc/api/ISteamFriends#OpenClanChatWindowInSteam>`_

.. function:: Friends.CloseClanChatWindowInSteam(steamIDClanChat)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClanChat:
    :returns: (bool) Return value
    :SteamWorks: `CloseClanChatWindowInSteam <https://partner.steamgames.com/doc/api/ISteamFriends#CloseClanChatWindowInSteam>`_

.. function:: Friends.SetListenForFriendsMessages(bInterceptEnabled)

    🤖 **Auto-generated binding**

    :param bool bInterceptEnabled:
    :returns: (bool) Return value
    :SteamWorks: `SetListenForFriendsMessages <https://partner.steamgames.com/doc/api/ISteamFriends#SetListenForFriendsMessages>`_

.. function:: Friends.ReplyToFriendMessage(steamIDFriend, pchMsgToSend)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :param str pchMsgToSend:
    :returns: (bool) Return value
    :SteamWorks: `ReplyToFriendMessage <https://partner.steamgames.com/doc/api/ISteamFriends#ReplyToFriendMessage>`_

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

.. function:: Friends.GetFollowerCount(steamID, callback)

    🤖 **Auto-generated binding**

    :param uint64 steamID:
    :param function callback: CallResult callback receiving struct `FriendsGetFollowerCount_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `GetFollowerCount <https://partner.steamgames.com/doc/api/ISteamFriends#GetFollowerCount>`_

.. function:: Friends.IsFollowing(steamID, callback)

    🤖 **Auto-generated binding**

    :param uint64 steamID:
    :param function callback: CallResult callback receiving struct `FriendsIsFollowing_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `IsFollowing <https://partner.steamgames.com/doc/api/ISteamFriends#IsFollowing>`_

.. function:: Friends.EnumerateFollowingList(unStartIndex, callback)

    🤖 **Auto-generated binding**

    :param int unStartIndex:
    :param function callback: CallResult callback receiving struct `FriendsEnumerateFollowingList_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `EnumerateFollowingList <https://partner.steamgames.com/doc/api/ISteamFriends#EnumerateFollowingList>`_

.. function:: Friends.IsClanPublic(steamIDClan)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClan:
    :returns: (bool) Return value
    :SteamWorks: `IsClanPublic <https://partner.steamgames.com/doc/api/ISteamFriends#IsClanPublic>`_

.. function:: Friends.IsClanOfficialGameGroup(steamIDClan)

    🤖 **Auto-generated binding**

    :param uint64 steamIDClan:
    :returns: (bool) Return value
    :SteamWorks: `IsClanOfficialGameGroup <https://partner.steamgames.com/doc/api/ISteamFriends#IsClanOfficialGameGroup>`_

.. function:: Friends.GetNumChatsWithUnreadPriorityMessages()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetNumChatsWithUnreadPriorityMessages <https://partner.steamgames.com/doc/api/ISteamFriends#GetNumChatsWithUnreadPriorityMessages>`_

.. function:: Friends.ActivateGameOverlayRemotePlayTogetherInviteDialog(steamIDLobby)

    🤖 **Auto-generated binding**

    :param uint64 steamIDLobby:
    :SteamWorks: `ActivateGameOverlayRemotePlayTogetherInviteDialog <https://partner.steamgames.com/doc/api/ISteamFriends#ActivateGameOverlayRemotePlayTogetherInviteDialog>`_

.. function:: Friends.RegisterProtocolInOverlayBrowser(pchProtocol)

    🤖 **Auto-generated binding**

    :param str pchProtocol:
    :returns: (bool) Return value
    :SteamWorks: `RegisterProtocolInOverlayBrowser <https://partner.steamgames.com/doc/api/ISteamFriends#RegisterProtocolInOverlayBrowser>`_

.. function:: Friends.ActivateGameOverlayInviteDialogConnectString(pchConnectString)

    🤖 **Auto-generated binding**

    :param str pchConnectString:
    :SteamWorks: `ActivateGameOverlayInviteDialogConnectString <https://partner.steamgames.com/doc/api/ISteamFriends#ActivateGameOverlayInviteDialogConnectString>`_

.. function:: Friends.RequestEquippedProfileItems(steamID, callback)

    🤖 **Auto-generated binding**

    :param uint64 steamID:
    :param function callback: CallResult callback receiving struct `EquippedProfileItems_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `RequestEquippedProfileItems <https://partner.steamgames.com/doc/api/ISteamFriends#RequestEquippedProfileItems>`_

.. function:: Friends.BHasEquippedProfileItem(steamID, itemType)

    🤖 **Auto-generated binding**

    :param uint64 steamID:
    :param int itemType:
    :returns: (bool) Return value
    :SteamWorks: `BHasEquippedProfileItem <https://partner.steamgames.com/doc/api/ISteamFriends#BHasEquippedProfileItem>`_

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


Callbacks
---------

.. function:: Friends.onPersonaStateChange

    Callback for `PersonaStateChange_t <https://partner.steamgames.com/doc/api/ISteamFriends#PersonaStateChange_t>`_

    **callback(data)** receives:

    * **data.m_ulSteamID** -- m_ulSteamID
    * **data.m_nChangeFlags** -- m_nChangeFlags

.. function:: Friends.onGameOverlayActivated

    Callback for `GameOverlayActivated_t <https://partner.steamgames.com/doc/api/ISteamFriends#GameOverlayActivated_t>`_

    **callback(data)** receives:

    * **data.m_bActive** -- m_bActive
    * **data.m_bUserInitiated** -- m_bUserInitiated
    * **data.m_nAppID** -- m_nAppID
    * **data.m_dwOverlayPID** -- m_dwOverlayPID

.. function:: Friends.onGameServerChangeRequested

    Callback for `GameServerChangeRequested_t <https://partner.steamgames.com/doc/api/ISteamFriends#GameServerChangeRequested_t>`_

    **callback(data)** receives:

    * **data.m_rgchServer** -- m_rgchServer
    * **data.m_rgchPassword** -- m_rgchPassword

.. function:: Friends.onGameLobbyJoinRequested

    Callback for `GameLobbyJoinRequested_t <https://partner.steamgames.com/doc/api/ISteamFriends#GameLobbyJoinRequested_t>`_

    **callback(data)** receives:

    * **data.m_steamIDLobby** -- m_steamIDLobby
    * **data.m_steamIDFriend** -- m_steamIDFriend

.. function:: Friends.onAvatarImageLoaded

    Callback for `AvatarImageLoaded_t <https://partner.steamgames.com/doc/api/ISteamFriends#AvatarImageLoaded_t>`_

    **callback(data)** receives:

    * **data.m_steamID** -- m_steamID
    * **data.m_iImage** -- m_iImage
    * **data.m_iWide** -- m_iWide
    * **data.m_iTall** -- m_iTall

.. function:: Friends.onClanOfficerListResponse

    Callback for `ClanOfficerListResponse_t <https://partner.steamgames.com/doc/api/ISteamFriends#ClanOfficerListResponse_t>`_

    **callback(data)** receives:

    * **data.m_steamIDClan** -- m_steamIDClan
    * **data.m_cOfficers** -- m_cOfficers
    * **data.m_bSuccess** -- m_bSuccess

.. function:: Friends.onFriendRichPresenceUpdate

    Callback for `FriendRichPresenceUpdate_t <https://partner.steamgames.com/doc/api/ISteamFriends#FriendRichPresenceUpdate_t>`_

    **callback(data)** receives:

    * **data.m_steamIDFriend** -- m_steamIDFriend
    * **data.m_nAppID** -- m_nAppID

.. function:: Friends.onGameRichPresenceJoinRequested

    Callback for `GameRichPresenceJoinRequested_t <https://partner.steamgames.com/doc/api/ISteamFriends#GameRichPresenceJoinRequested_t>`_

    **callback(data)** receives:

    * **data.m_steamIDFriend** -- m_steamIDFriend
    * **data.m_rgchConnect** -- m_rgchConnect

.. function:: Friends.onGameConnectedClanChatMsg

    Callback for `GameConnectedClanChatMsg_t <https://partner.steamgames.com/doc/api/ISteamFriends#GameConnectedClanChatMsg_t>`_

    **callback(data)** receives:

    * **data.m_steamIDClanChat** -- m_steamIDClanChat
    * **data.m_steamIDUser** -- m_steamIDUser
    * **data.m_iMessageID** -- m_iMessageID

.. function:: Friends.onGameConnectedChatJoin

    Callback for `GameConnectedChatJoin_t <https://partner.steamgames.com/doc/api/ISteamFriends#GameConnectedChatJoin_t>`_

    **callback(data)** receives:

    * **data.m_steamIDClanChat** -- m_steamIDClanChat
    * **data.m_steamIDUser** -- m_steamIDUser

.. function:: Friends.onGameConnectedChatLeave

    Callback for `GameConnectedChatLeave_t <https://partner.steamgames.com/doc/api/ISteamFriends#GameConnectedChatLeave_t>`_

    **callback(data)** receives:

    * **data.m_steamIDClanChat** -- m_steamIDClanChat
    * **data.m_steamIDUser** -- m_steamIDUser
    * **data.m_bKicked** -- m_bKicked
    * **data.m_bDropped** -- m_bDropped

.. function:: Friends.onDownloadClanActivityCountsResult

    Callback for `DownloadClanActivityCountsResult_t <https://partner.steamgames.com/doc/api/ISteamFriends#DownloadClanActivityCountsResult_t>`_

    **callback(data)** receives:

    * **data.m_bSuccess** -- m_bSuccess

.. function:: Friends.onJoinClanChatRoomCompletionResult

    Callback for `JoinClanChatRoomCompletionResult_t <https://partner.steamgames.com/doc/api/ISteamFriends#JoinClanChatRoomCompletionResult_t>`_

    **callback(data)** receives:

    * **data.m_steamIDClanChat** -- m_steamIDClanChat
    * **data.m_eChatRoomEnterResponse** -- m_eChatRoomEnterResponse

.. function:: Friends.onGameConnectedFriendChatMsg

    Callback for `GameConnectedFriendChatMsg_t <https://partner.steamgames.com/doc/api/ISteamFriends#GameConnectedFriendChatMsg_t>`_

    **callback(data)** receives:

    * **data.m_steamIDUser** -- m_steamIDUser
    * **data.m_iMessageID** -- m_iMessageID

.. function:: Friends.onFriendsGetFollowerCount

    Callback for `FriendsGetFollowerCount_t <https://partner.steamgames.com/doc/api/ISteamFriends#FriendsGetFollowerCount_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_steamID** -- m_steamID
    * **data.m_nCount** -- m_nCount

.. function:: Friends.onFriendsIsFollowing

    Callback for `FriendsIsFollowing_t <https://partner.steamgames.com/doc/api/ISteamFriends#FriendsIsFollowing_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_steamID** -- m_steamID
    * **data.m_bIsFollowing** -- m_bIsFollowing

.. function:: Friends.onFriendsEnumerateFollowingList

    Callback for `FriendsEnumerateFollowingList_t <https://partner.steamgames.com/doc/api/ISteamFriends#FriendsEnumerateFollowingList_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_rgSteamID** -- m_rgSteamID
    * **data.m_nResultsReturned** -- m_nResultsReturned
    * **data.m_nTotalResultCount** -- m_nTotalResultCount

.. function:: Friends.onUnreadChatMessagesChanged

    Callback for `UnreadChatMessagesChanged_t <https://partner.steamgames.com/doc/api/ISteamFriends#UnreadChatMessagesChanged_t>`_

    **callback(data)** receives:


.. function:: Friends.onOverlayBrowserProtocolNavigation

    Callback for `OverlayBrowserProtocolNavigation_t <https://partner.steamgames.com/doc/api/ISteamFriends#OverlayBrowserProtocolNavigation_t>`_

    **callback(data)** receives:

    * **data.rgchURI** -- rgchURI

.. function:: Friends.onEquippedProfileItemsChanged

    Callback for `EquippedProfileItemsChanged_t <https://partner.steamgames.com/doc/api/ISteamFriends#EquippedProfileItemsChanged_t>`_

    **callback(data)** receives:

    * **data.m_steamID** -- m_steamID

.. function:: Friends.onEquippedProfileItems

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

