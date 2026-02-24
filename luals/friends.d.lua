---@class Steam.Friends
local Friends = {}

---@return string
function Friends.GetPersonaName() end

---@return integer
function Friends.GetPersonaState() end

---@param iFriendFlags integer
---@return integer
function Friends.GetFriendCount(iFriendFlags) end

---@param iFriend integer
---@param iFriendFlags integer
---@return uint64
function Friends.GetFriendByIndex(iFriend, iFriendFlags) end

---@param steamIDFriend uint64
---@return integer
function Friends.GetFriendRelationship(steamIDFriend) end

---@param steamIDFriend uint64
---@return integer
function Friends.GetFriendPersonaState(steamIDFriend) end

---@param steamIDFriend uint64
---@return string
function Friends.GetFriendPersonaName(steamIDFriend) end

---@param steamIDFriend uint64
---@return boolean
---@return FriendGameInfo_t -- Value of: pFriendGameInfo
function Friends.GetFriendGamePlayed(steamIDFriend) end

---@param steamIDFriend uint64
---@param iPersonaName integer
---@return string
function Friends.GetFriendPersonaNameHistory(steamIDFriend, iPersonaName) end

---@param steamIDFriend uint64
---@return integer
function Friends.GetFriendSteamLevel(steamIDFriend) end

---@param steamIDPlayer uint64
---@return string
function Friends.GetPlayerNickname(steamIDPlayer) end

---@return integer
function Friends.GetFriendsGroupCount() end

---@param iFG integer
---@return integer
function Friends.GetFriendsGroupIDByIndex(iFG) end

---@param friendsGroupID integer
---@return string
function Friends.GetFriendsGroupName(friendsGroupID) end

---@param friendsGroupID integer
---@return integer
function Friends.GetFriendsGroupMembersCount(friendsGroupID) end

---@param friendsGroupID integer
---@param nMembersCount integer
---@return uint64[] -- Value of: pOutSteamIDMembers
function Friends.GetFriendsGroupMembersList(friendsGroupID, nMembersCount) end

---@param steamIDFriend uint64
---@param iFriendFlags integer
---@return boolean
function Friends.HasFriend(steamIDFriend, iFriendFlags) end

---@return integer
function Friends.GetClanCount() end

---@param iClan integer
---@return uint64
function Friends.GetClanByIndex(iClan) end

---@param steamIDClan uint64
---@return string
function Friends.GetClanName(steamIDClan) end

---@param steamIDClan uint64
---@return string
function Friends.GetClanTag(steamIDClan) end

---@param steamIDClan uint64
---@return boolean
---@return integer -- Value of: pnOnline
---@return integer -- Value of: pnInGame
---@return integer -- Value of: pnChatting
function Friends.GetClanActivityCounts(steamIDClan) end

---@param cClansToRequest integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
---@return uint64[] -- Value of: psteamIDClans
function Friends.DownloadClanActivityCounts(cClansToRequest, callback) end

---@param steamIDSource uint64
---@return integer
function Friends.GetFriendCountFromSource(steamIDSource) end

---@param steamIDSource uint64
---@param iFriend integer
---@return uint64
function Friends.GetFriendFromSourceByIndex(steamIDSource, iFriend) end

---@param steamIDUser uint64
---@param steamIDSource uint64
---@return boolean
function Friends.IsUserInSource(steamIDUser, steamIDSource) end

---@param steamIDUser uint64
---@param bSpeaking boolean
function Friends.SetInGameVoiceSpeaking(steamIDUser, bSpeaking) end

---@param pchDialog string
function Friends.ActivateGameOverlay(pchDialog) end

---@param pchDialog string
---@param steamID uint64
function Friends.ActivateGameOverlayToUser(pchDialog, steamID) end

---@param pchURL string
---@param eMode integer
function Friends.ActivateGameOverlayToWebPage(pchURL, eMode) end

---@param nAppID integer
---@param eFlag integer
function Friends.ActivateGameOverlayToStore(nAppID, eFlag) end

---@param steamIDUserPlayedWith uint64
function Friends.SetPlayedWith(steamIDUserPlayedWith) end

---@param steamIDLobby uint64
function Friends.ActivateGameOverlayInviteDialog(steamIDLobby) end

---@param steamIDFriend uint64
---@return integer
function Friends.GetSmallFriendAvatar(steamIDFriend) end

---@param steamIDFriend uint64
---@return integer
function Friends.GetMediumFriendAvatar(steamIDFriend) end

---@param steamIDFriend uint64
---@return integer
function Friends.GetLargeFriendAvatar(steamIDFriend) end

---@param steamIDUser uint64
---@param bRequireNameOnly boolean
---@return boolean
function Friends.RequestUserInformation(steamIDUser, bRequireNameOnly) end

---@param steamIDClan uint64
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function Friends.RequestClanOfficerList(steamIDClan, callback) end

---@param steamIDClan uint64
---@return uint64
function Friends.GetClanOwner(steamIDClan) end

---@param steamIDClan uint64
---@return integer
function Friends.GetClanOfficerCount(steamIDClan) end

---@param steamIDClan uint64
---@param iOfficer integer
---@return uint64
function Friends.GetClanOfficerByIndex(steamIDClan, iOfficer) end

---@param pchKey string
---@param pchValue string
---@return boolean
function Friends.SetRichPresence(pchKey, pchValue) end

function Friends.ClearRichPresence() end

---@param steamIDFriend uint64
---@param pchKey string
---@return string
function Friends.GetFriendRichPresence(steamIDFriend, pchKey) end

---@param steamIDFriend uint64
---@return integer
function Friends.GetFriendRichPresenceKeyCount(steamIDFriend) end

---@param steamIDFriend uint64
---@param iKey integer
---@return string
function Friends.GetFriendRichPresenceKeyByIndex(steamIDFriend, iKey) end

---@param steamIDFriend uint64
function Friends.RequestFriendRichPresence(steamIDFriend) end

---@param steamIDFriend uint64
---@param pchConnectString string
---@return boolean
function Friends.InviteUserToGame(steamIDFriend, pchConnectString) end

---@return integer
function Friends.GetCoplayFriendCount() end

---@param iCoplayFriend integer
---@return uint64
function Friends.GetCoplayFriend(iCoplayFriend) end

---@param steamIDFriend uint64
---@return integer
function Friends.GetFriendCoplayTime(steamIDFriend) end

---@param steamIDFriend uint64
---@return integer
function Friends.GetFriendCoplayGame(steamIDFriend) end

---@param steamIDClan uint64
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function Friends.JoinClanChatRoom(steamIDClan, callback) end

---@param steamIDClan uint64
---@return boolean
function Friends.LeaveClanChatRoom(steamIDClan) end

---@param steamIDClan uint64
---@return integer
function Friends.GetClanChatMemberCount(steamIDClan) end

---@param steamIDClan uint64
---@param iUser integer
---@return uint64
function Friends.GetChatMemberByIndex(steamIDClan, iUser) end

---@param steamIDClanChat uint64
---@param pchText string
---@return boolean
function Friends.SendClanChatMessage(steamIDClanChat, pchText) end

---@param steamIDClanChat uint64
---@param iMessage integer
---@param cchTextMax integer
---@return integer
---@return string -- Value of: prgchText
---@return integer -- Value of: peChatEntryType
---@return uint64 -- Value of: psteamidChatter
function Friends.GetClanChatMessage(steamIDClanChat, iMessage, cchTextMax) end

---@param steamIDClanChat uint64
---@param steamIDUser uint64
---@return boolean
function Friends.IsClanChatAdmin(steamIDClanChat, steamIDUser) end

---@param steamIDClanChat uint64
---@return boolean
function Friends.IsClanChatWindowOpenInSteam(steamIDClanChat) end

---@param steamIDClanChat uint64
---@return boolean
function Friends.OpenClanChatWindowInSteam(steamIDClanChat) end

---@param steamIDClanChat uint64
---@return boolean
function Friends.CloseClanChatWindowInSteam(steamIDClanChat) end

---@param bInterceptEnabled boolean
---@return boolean
function Friends.SetListenForFriendsMessages(bInterceptEnabled) end

---@param steamIDFriend uint64
---@param pchMsgToSend string
---@return boolean
function Friends.ReplyToFriendMessage(steamIDFriend, pchMsgToSend) end

---@param steamIDFriend uint64
---@param iMessageID integer
---@param cubData integer
---@return integer
---@return string -- Value of: pvData
---@return integer -- Value of: peChatEntryType
function Friends.GetFriendMessage(steamIDFriend, iMessageID, cubData) end

---@param steamID uint64
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function Friends.GetFollowerCount(steamID, callback) end

---@param steamID uint64
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function Friends.IsFollowing(steamID, callback) end

---@param unStartIndex integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function Friends.EnumerateFollowingList(unStartIndex, callback) end

---@param steamIDClan uint64
---@return boolean
function Friends.IsClanPublic(steamIDClan) end

---@param steamIDClan uint64
---@return boolean
function Friends.IsClanOfficialGameGroup(steamIDClan) end

---@return integer
function Friends.GetNumChatsWithUnreadPriorityMessages() end

---@param steamIDLobby uint64
function Friends.ActivateGameOverlayRemotePlayTogetherInviteDialog(steamIDLobby) end

---@param pchProtocol string
---@return boolean
function Friends.RegisterProtocolInOverlayBrowser(pchProtocol) end

---@param pchConnectString string
function Friends.ActivateGameOverlayInviteDialogConnectString(pchConnectString) end

---@param steamID uint64
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function Friends.RequestEquippedProfileItems(steamID, callback) end

---@param steamID uint64
---@param itemType integer
---@return boolean
function Friends.BHasEquippedProfileItem(steamID, itemType) end

---@param steamID uint64
---@param itemType integer
---@param prop integer
---@return string
function Friends.GetProfileItemPropertyString(steamID, itemType, prop) end

---@param steamID uint64
---@param itemType integer
---@param prop integer
---@return integer
function Friends.GetProfileItemPropertyUint(steamID, itemType, prop) end

Steam.Friends = Friends
