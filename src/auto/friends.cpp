#include "auto.hpp"

// const char * GetPersonaName();
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetPersonaName(lua_State *L) {
    lua_pushstring(L, SteamFriends()->GetPersonaName());
    return 1;
}

// int GetFriendCount(int iFriendFlags);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetFriendCount(lua_State *L) {
    int iFriendFlags = luaL_checkint(L, 1);
    lua_pushinteger(L, SteamFriends()->GetFriendCount(iFriendFlags));
    return 1;
}

// CSteamID GetFriendByIndex(int iFriend, int iFriendFlags);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetFriendByIndex(lua_State *L) {
    int iFriend = luaL_checkint(L, 1);
    int iFriendFlags = luaL_checkint(L, 2);
    luasteam::pushuint64(L, (SteamFriends()->GetFriendByIndex(iFriend, iFriendFlags)).ConvertToUint64());
    return 1;
}

// const char * GetFriendPersonaName(CSteamID steamIDFriend);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetFriendPersonaName(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    lua_pushstring(L, SteamFriends()->GetFriendPersonaName(steamIDFriend));
    return 1;
}

// const char * GetFriendPersonaNameHistory(CSteamID steamIDFriend, int iPersonaName);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetFriendPersonaNameHistory(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    int iPersonaName = luaL_checkint(L, 2);
    lua_pushstring(L, SteamFriends()->GetFriendPersonaNameHistory(steamIDFriend, iPersonaName));
    return 1;
}

// int GetFriendSteamLevel(CSteamID steamIDFriend);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetFriendSteamLevel(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    lua_pushinteger(L, SteamFriends()->GetFriendSteamLevel(steamIDFriend));
    return 1;
}

// const char * GetPlayerNickname(CSteamID steamIDPlayer);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetPlayerNickname(lua_State *L) {
    CSteamID steamIDPlayer(luasteam::checkuint64(L, 1));
    lua_pushstring(L, SteamFriends()->GetPlayerNickname(steamIDPlayer));
    return 1;
}

// int GetFriendsGroupCount();
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetFriendsGroupCount(lua_State *L) {
    lua_pushinteger(L, SteamFriends()->GetFriendsGroupCount());
    return 1;
}

// bool HasFriend(CSteamID steamIDFriend, int iFriendFlags);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_HasFriend(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    int iFriendFlags = luaL_checkint(L, 2);
    lua_pushboolean(L, SteamFriends()->HasFriend(steamIDFriend, iFriendFlags));
    return 1;
}

// int GetClanCount();
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetClanCount(lua_State *L) {
    lua_pushinteger(L, SteamFriends()->GetClanCount());
    return 1;
}

// CSteamID GetClanByIndex(int iClan);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetClanByIndex(lua_State *L) {
    int iClan = luaL_checkint(L, 1);
    luasteam::pushuint64(L, (SteamFriends()->GetClanByIndex(iClan)).ConvertToUint64());
    return 1;
}

// const char * GetClanName(CSteamID steamIDClan);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetClanName(lua_State *L) {
    CSteamID steamIDClan(luasteam::checkuint64(L, 1));
    lua_pushstring(L, SteamFriends()->GetClanName(steamIDClan));
    return 1;
}

// const char * GetClanTag(CSteamID steamIDClan);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetClanTag(lua_State *L) {
    CSteamID steamIDClan(luasteam::checkuint64(L, 1));
    lua_pushstring(L, SteamFriends()->GetClanTag(steamIDClan));
    return 1;
}

// int GetFriendCountFromSource(CSteamID steamIDSource);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetFriendCountFromSource(lua_State *L) {
    CSteamID steamIDSource(luasteam::checkuint64(L, 1));
    lua_pushinteger(L, SteamFriends()->GetFriendCountFromSource(steamIDSource));
    return 1;
}

// CSteamID GetFriendFromSourceByIndex(CSteamID steamIDSource, int iFriend);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetFriendFromSourceByIndex(lua_State *L) {
    CSteamID steamIDSource(luasteam::checkuint64(L, 1));
    int iFriend = luaL_checkint(L, 2);
    luasteam::pushuint64(L, (SteamFriends()->GetFriendFromSourceByIndex(steamIDSource, iFriend)).ConvertToUint64());
    return 1;
}

// bool IsUserInSource(CSteamID steamIDUser, CSteamID steamIDSource);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_IsUserInSource(lua_State *L) {
    CSteamID steamIDUser(luasteam::checkuint64(L, 1));
    CSteamID steamIDSource(luasteam::checkuint64(L, 2));
    lua_pushboolean(L, SteamFriends()->IsUserInSource(steamIDUser, steamIDSource));
    return 1;
}

// void SetInGameVoiceSpeaking(CSteamID steamIDUser, bool bSpeaking);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_SetInGameVoiceSpeaking(lua_State *L) {
    CSteamID steamIDUser(luasteam::checkuint64(L, 1));
    bool bSpeaking = lua_toboolean(L, 2);
    SteamFriends()->SetInGameVoiceSpeaking(steamIDUser, bSpeaking);
    return 0;
}

// void ActivateGameOverlay(const char * pchDialog);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_ActivateGameOverlay(lua_State *L) {
    const char *pchDialog = luaL_checkstring(L, 1);
    SteamFriends()->ActivateGameOverlay(pchDialog);
    return 0;
}

// void ActivateGameOverlayToUser(const char * pchDialog, CSteamID steamID);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_ActivateGameOverlayToUser(lua_State *L) {
    const char *pchDialog = luaL_checkstring(L, 1);
    CSteamID steamID(luasteam::checkuint64(L, 2));
    SteamFriends()->ActivateGameOverlayToUser(pchDialog, steamID);
    return 0;
}

// void SetPlayedWith(CSteamID steamIDUserPlayedWith);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_SetPlayedWith(lua_State *L) {
    CSteamID steamIDUserPlayedWith(luasteam::checkuint64(L, 1));
    SteamFriends()->SetPlayedWith(steamIDUserPlayedWith);
    return 0;
}

// void ActivateGameOverlayInviteDialog(CSteamID steamIDLobby);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialog(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    SteamFriends()->ActivateGameOverlayInviteDialog(steamIDLobby);
    return 0;
}

// int GetSmallFriendAvatar(CSteamID steamIDFriend);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetSmallFriendAvatar(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    lua_pushinteger(L, SteamFriends()->GetSmallFriendAvatar(steamIDFriend));
    return 1;
}

// int GetMediumFriendAvatar(CSteamID steamIDFriend);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetMediumFriendAvatar(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    lua_pushinteger(L, SteamFriends()->GetMediumFriendAvatar(steamIDFriend));
    return 1;
}

// int GetLargeFriendAvatar(CSteamID steamIDFriend);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetLargeFriendAvatar(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    lua_pushinteger(L, SteamFriends()->GetLargeFriendAvatar(steamIDFriend));
    return 1;
}

// bool RequestUserInformation(CSteamID steamIDUser, bool bRequireNameOnly);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_RequestUserInformation(lua_State *L) {
    CSteamID steamIDUser(luasteam::checkuint64(L, 1));
    bool bRequireNameOnly = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamFriends()->RequestUserInformation(steamIDUser, bRequireNameOnly));
    return 1;
}

// SteamAPICall_t RequestClanOfficerList(CSteamID steamIDClan);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_RequestClanOfficerList(lua_State *L) {
    CSteamID steamIDClan(luasteam::checkuint64(L, 1));
    luasteam::pushuint64(L, SteamFriends()->RequestClanOfficerList(steamIDClan));
    return 1;
}

// CSteamID GetClanOwner(CSteamID steamIDClan);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetClanOwner(lua_State *L) {
    CSteamID steamIDClan(luasteam::checkuint64(L, 1));
    luasteam::pushuint64(L, (SteamFriends()->GetClanOwner(steamIDClan)).ConvertToUint64());
    return 1;
}

// int GetClanOfficerCount(CSteamID steamIDClan);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetClanOfficerCount(lua_State *L) {
    CSteamID steamIDClan(luasteam::checkuint64(L, 1));
    lua_pushinteger(L, SteamFriends()->GetClanOfficerCount(steamIDClan));
    return 1;
}

// CSteamID GetClanOfficerByIndex(CSteamID steamIDClan, int iOfficer);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetClanOfficerByIndex(lua_State *L) {
    CSteamID steamIDClan(luasteam::checkuint64(L, 1));
    int iOfficer = luaL_checkint(L, 2);
    luasteam::pushuint64(L, (SteamFriends()->GetClanOfficerByIndex(steamIDClan, iOfficer)).ConvertToUint64());
    return 1;
}

// bool SetRichPresence(const char * pchKey, const char * pchValue);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_SetRichPresence(lua_State *L) {
    const char *pchKey = luaL_checkstring(L, 1);
    const char *pchValue = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamFriends()->SetRichPresence(pchKey, pchValue));
    return 1;
}

// void ClearRichPresence();
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_ClearRichPresence(lua_State *L) {
    SteamFriends()->ClearRichPresence();
    return 0;
}

// const char * GetFriendRichPresence(CSteamID steamIDFriend, const char * pchKey);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetFriendRichPresence(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    const char *pchKey = luaL_checkstring(L, 2);
    lua_pushstring(L, SteamFriends()->GetFriendRichPresence(steamIDFriend, pchKey));
    return 1;
}

// int GetFriendRichPresenceKeyCount(CSteamID steamIDFriend);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetFriendRichPresenceKeyCount(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    lua_pushinteger(L, SteamFriends()->GetFriendRichPresenceKeyCount(steamIDFriend));
    return 1;
}

// const char * GetFriendRichPresenceKeyByIndex(CSteamID steamIDFriend, int iKey);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetFriendRichPresenceKeyByIndex(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    int iKey = luaL_checkint(L, 2);
    lua_pushstring(L, SteamFriends()->GetFriendRichPresenceKeyByIndex(steamIDFriend, iKey));
    return 1;
}

// void RequestFriendRichPresence(CSteamID steamIDFriend);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_RequestFriendRichPresence(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    SteamFriends()->RequestFriendRichPresence(steamIDFriend);
    return 0;
}

// bool InviteUserToGame(CSteamID steamIDFriend, const char * pchConnectString);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_InviteUserToGame(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    const char *pchConnectString = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamFriends()->InviteUserToGame(steamIDFriend, pchConnectString));
    return 1;
}

// int GetCoplayFriendCount();
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetCoplayFriendCount(lua_State *L) {
    lua_pushinteger(L, SteamFriends()->GetCoplayFriendCount());
    return 1;
}

// CSteamID GetCoplayFriend(int iCoplayFriend);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetCoplayFriend(lua_State *L) {
    int iCoplayFriend = luaL_checkint(L, 1);
    luasteam::pushuint64(L, (SteamFriends()->GetCoplayFriend(iCoplayFriend)).ConvertToUint64());
    return 1;
}

// int GetFriendCoplayTime(CSteamID steamIDFriend);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetFriendCoplayTime(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    lua_pushinteger(L, SteamFriends()->GetFriendCoplayTime(steamIDFriend));
    return 1;
}

// AppId_t GetFriendCoplayGame(CSteamID steamIDFriend);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetFriendCoplayGame(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    lua_pushinteger(L, SteamFriends()->GetFriendCoplayGame(steamIDFriend));
    return 1;
}

// SteamAPICall_t JoinClanChatRoom(CSteamID steamIDClan);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_JoinClanChatRoom(lua_State *L) {
    CSteamID steamIDClan(luasteam::checkuint64(L, 1));
    luasteam::pushuint64(L, SteamFriends()->JoinClanChatRoom(steamIDClan));
    return 1;
}

// bool LeaveClanChatRoom(CSteamID steamIDClan);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_LeaveClanChatRoom(lua_State *L) {
    CSteamID steamIDClan(luasteam::checkuint64(L, 1));
    lua_pushboolean(L, SteamFriends()->LeaveClanChatRoom(steamIDClan));
    return 1;
}

// int GetClanChatMemberCount(CSteamID steamIDClan);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetClanChatMemberCount(lua_State *L) {
    CSteamID steamIDClan(luasteam::checkuint64(L, 1));
    lua_pushinteger(L, SteamFriends()->GetClanChatMemberCount(steamIDClan));
    return 1;
}

// CSteamID GetChatMemberByIndex(CSteamID steamIDClan, int iUser);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetChatMemberByIndex(lua_State *L) {
    CSteamID steamIDClan(luasteam::checkuint64(L, 1));
    int iUser = luaL_checkint(L, 2);
    luasteam::pushuint64(L, (SteamFriends()->GetChatMemberByIndex(steamIDClan, iUser)).ConvertToUint64());
    return 1;
}

// bool SendClanChatMessage(CSteamID steamIDClanChat, const char * pchText);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_SendClanChatMessage(lua_State *L) {
    CSteamID steamIDClanChat(luasteam::checkuint64(L, 1));
    const char *pchText = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamFriends()->SendClanChatMessage(steamIDClanChat, pchText));
    return 1;
}

// bool IsClanChatAdmin(CSteamID steamIDClanChat, CSteamID steamIDUser);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_IsClanChatAdmin(lua_State *L) {
    CSteamID steamIDClanChat(luasteam::checkuint64(L, 1));
    CSteamID steamIDUser(luasteam::checkuint64(L, 2));
    lua_pushboolean(L, SteamFriends()->IsClanChatAdmin(steamIDClanChat, steamIDUser));
    return 1;
}

// bool IsClanChatWindowOpenInSteam(CSteamID steamIDClanChat);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_IsClanChatWindowOpenInSteam(lua_State *L) {
    CSteamID steamIDClanChat(luasteam::checkuint64(L, 1));
    lua_pushboolean(L, SteamFriends()->IsClanChatWindowOpenInSteam(steamIDClanChat));
    return 1;
}

// bool OpenClanChatWindowInSteam(CSteamID steamIDClanChat);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_OpenClanChatWindowInSteam(lua_State *L) {
    CSteamID steamIDClanChat(luasteam::checkuint64(L, 1));
    lua_pushboolean(L, SteamFriends()->OpenClanChatWindowInSteam(steamIDClanChat));
    return 1;
}

// bool CloseClanChatWindowInSteam(CSteamID steamIDClanChat);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_CloseClanChatWindowInSteam(lua_State *L) {
    CSteamID steamIDClanChat(luasteam::checkuint64(L, 1));
    lua_pushboolean(L, SteamFriends()->CloseClanChatWindowInSteam(steamIDClanChat));
    return 1;
}

// bool SetListenForFriendsMessages(bool bInterceptEnabled);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_SetListenForFriendsMessages(lua_State *L) {
    bool bInterceptEnabled = lua_toboolean(L, 1);
    lua_pushboolean(L, SteamFriends()->SetListenForFriendsMessages(bInterceptEnabled));
    return 1;
}

// bool ReplyToFriendMessage(CSteamID steamIDFriend, const char * pchMsgToSend);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_ReplyToFriendMessage(lua_State *L) {
    CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
    const char *pchMsgToSend = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamFriends()->ReplyToFriendMessage(steamIDFriend, pchMsgToSend));
    return 1;
}

// SteamAPICall_t GetFollowerCount(CSteamID steamID);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetFollowerCount(lua_State *L) {
    CSteamID steamID(luasteam::checkuint64(L, 1));
    luasteam::pushuint64(L, SteamFriends()->GetFollowerCount(steamID));
    return 1;
}

// SteamAPICall_t IsFollowing(CSteamID steamID);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_IsFollowing(lua_State *L) {
    CSteamID steamID(luasteam::checkuint64(L, 1));
    luasteam::pushuint64(L, SteamFriends()->IsFollowing(steamID));
    return 1;
}

// SteamAPICall_t EnumerateFollowingList(uint32 unStartIndex);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_EnumerateFollowingList(lua_State *L) {
    uint32 unStartIndex = luaL_checkint(L, 1);
    luasteam::pushuint64(L, SteamFriends()->EnumerateFollowingList(unStartIndex));
    return 1;
}

// bool IsClanPublic(CSteamID steamIDClan);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_IsClanPublic(lua_State *L) {
    CSteamID steamIDClan(luasteam::checkuint64(L, 1));
    lua_pushboolean(L, SteamFriends()->IsClanPublic(steamIDClan));
    return 1;
}

// bool IsClanOfficialGameGroup(CSteamID steamIDClan);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_IsClanOfficialGameGroup(lua_State *L) {
    CSteamID steamIDClan(luasteam::checkuint64(L, 1));
    lua_pushboolean(L, SteamFriends()->IsClanOfficialGameGroup(steamIDClan));
    return 1;
}

// int GetNumChatsWithUnreadPriorityMessages();
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_GetNumChatsWithUnreadPriorityMessages(lua_State *L) {
    lua_pushinteger(L, SteamFriends()->GetNumChatsWithUnreadPriorityMessages());
    return 1;
}

// void ActivateGameOverlayRemotePlayTogetherInviteDialog(CSteamID steamIDLobby);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_ActivateGameOverlayRemotePlayTogetherInviteDialog(lua_State *L) {
    CSteamID steamIDLobby(luasteam::checkuint64(L, 1));
    SteamFriends()->ActivateGameOverlayRemotePlayTogetherInviteDialog(steamIDLobby);
    return 0;
}

// bool RegisterProtocolInOverlayBrowser(const char * pchProtocol);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_RegisterProtocolInOverlayBrowser(lua_State *L) {
    const char *pchProtocol = luaL_checkstring(L, 1);
    lua_pushboolean(L, SteamFriends()->RegisterProtocolInOverlayBrowser(pchProtocol));
    return 1;
}

// void ActivateGameOverlayInviteDialogConnectString(const char * pchConnectString);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialogConnectString(lua_State *L) {
    const char *pchConnectString = luaL_checkstring(L, 1);
    SteamFriends()->ActivateGameOverlayInviteDialogConnectString(pchConnectString);
    return 0;
}

// SteamAPICall_t RequestEquippedProfileItems(CSteamID steamID);
EXTERN int luasteam_friends_SteamAPI_ISteamFriends_RequestEquippedProfileItems(lua_State *L) {
    CSteamID steamID(luasteam::checkuint64(L, 1));
    luasteam::pushuint64(L, SteamFriends()->RequestEquippedProfileItems(steamID));
    return 1;
}

namespace luasteam {

void add_friends_auto(lua_State *L) {
    add_func(L, "getPersonaName", luasteam_friends_SteamAPI_ISteamFriends_GetPersonaName);
    add_func(L, "getFriendCount", luasteam_friends_SteamAPI_ISteamFriends_GetFriendCount);
    add_func(L, "getFriendByIndex", luasteam_friends_SteamAPI_ISteamFriends_GetFriendByIndex);
    add_func(L, "getFriendPersonaName", luasteam_friends_SteamAPI_ISteamFriends_GetFriendPersonaName);
    add_func(L, "getFriendPersonaNameHistory", luasteam_friends_SteamAPI_ISteamFriends_GetFriendPersonaNameHistory);
    add_func(L, "getFriendSteamLevel", luasteam_friends_SteamAPI_ISteamFriends_GetFriendSteamLevel);
    add_func(L, "getPlayerNickname", luasteam_friends_SteamAPI_ISteamFriends_GetPlayerNickname);
    add_func(L, "getFriendsGroupCount", luasteam_friends_SteamAPI_ISteamFriends_GetFriendsGroupCount);
    add_func(L, "hasFriend", luasteam_friends_SteamAPI_ISteamFriends_HasFriend);
    add_func(L, "getClanCount", luasteam_friends_SteamAPI_ISteamFriends_GetClanCount);
    add_func(L, "getClanByIndex", luasteam_friends_SteamAPI_ISteamFriends_GetClanByIndex);
    add_func(L, "getClanName", luasteam_friends_SteamAPI_ISteamFriends_GetClanName);
    add_func(L, "getClanTag", luasteam_friends_SteamAPI_ISteamFriends_GetClanTag);
    add_func(L, "getFriendCountFromSource", luasteam_friends_SteamAPI_ISteamFriends_GetFriendCountFromSource);
    add_func(L, "getFriendFromSourceByIndex", luasteam_friends_SteamAPI_ISteamFriends_GetFriendFromSourceByIndex);
    add_func(L, "isUserInSource", luasteam_friends_SteamAPI_ISteamFriends_IsUserInSource);
    add_func(L, "setInGameVoiceSpeaking", luasteam_friends_SteamAPI_ISteamFriends_SetInGameVoiceSpeaking);
    add_func(L, "activateGameOverlay", luasteam_friends_SteamAPI_ISteamFriends_ActivateGameOverlay);
    add_func(L, "activateGameOverlayToUser", luasteam_friends_SteamAPI_ISteamFriends_ActivateGameOverlayToUser);
    add_func(L, "setPlayedWith", luasteam_friends_SteamAPI_ISteamFriends_SetPlayedWith);
    add_func(L, "activateGameOverlayInviteDialog", luasteam_friends_SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialog);
    add_func(L, "getSmallFriendAvatar", luasteam_friends_SteamAPI_ISteamFriends_GetSmallFriendAvatar);
    add_func(L, "getMediumFriendAvatar", luasteam_friends_SteamAPI_ISteamFriends_GetMediumFriendAvatar);
    add_func(L, "getLargeFriendAvatar", luasteam_friends_SteamAPI_ISteamFriends_GetLargeFriendAvatar);
    add_func(L, "requestUserInformation", luasteam_friends_SteamAPI_ISteamFriends_RequestUserInformation);
    add_func(L, "requestClanOfficerList", luasteam_friends_SteamAPI_ISteamFriends_RequestClanOfficerList);
    add_func(L, "getClanOwner", luasteam_friends_SteamAPI_ISteamFriends_GetClanOwner);
    add_func(L, "getClanOfficerCount", luasteam_friends_SteamAPI_ISteamFriends_GetClanOfficerCount);
    add_func(L, "getClanOfficerByIndex", luasteam_friends_SteamAPI_ISteamFriends_GetClanOfficerByIndex);
    add_func(L, "setRichPresence", luasteam_friends_SteamAPI_ISteamFriends_SetRichPresence);
    add_func(L, "clearRichPresence", luasteam_friends_SteamAPI_ISteamFriends_ClearRichPresence);
    add_func(L, "getFriendRichPresence", luasteam_friends_SteamAPI_ISteamFriends_GetFriendRichPresence);
    add_func(L, "getFriendRichPresenceKeyCount", luasteam_friends_SteamAPI_ISteamFriends_GetFriendRichPresenceKeyCount);
    add_func(L, "getFriendRichPresenceKeyByIndex", luasteam_friends_SteamAPI_ISteamFriends_GetFriendRichPresenceKeyByIndex);
    add_func(L, "requestFriendRichPresence", luasteam_friends_SteamAPI_ISteamFriends_RequestFriendRichPresence);
    add_func(L, "inviteUserToGame", luasteam_friends_SteamAPI_ISteamFriends_InviteUserToGame);
    add_func(L, "getCoplayFriendCount", luasteam_friends_SteamAPI_ISteamFriends_GetCoplayFriendCount);
    add_func(L, "getCoplayFriend", luasteam_friends_SteamAPI_ISteamFriends_GetCoplayFriend);
    add_func(L, "getFriendCoplayTime", luasteam_friends_SteamAPI_ISteamFriends_GetFriendCoplayTime);
    add_func(L, "getFriendCoplayGame", luasteam_friends_SteamAPI_ISteamFriends_GetFriendCoplayGame);
    add_func(L, "joinClanChatRoom", luasteam_friends_SteamAPI_ISteamFriends_JoinClanChatRoom);
    add_func(L, "leaveClanChatRoom", luasteam_friends_SteamAPI_ISteamFriends_LeaveClanChatRoom);
    add_func(L, "getClanChatMemberCount", luasteam_friends_SteamAPI_ISteamFriends_GetClanChatMemberCount);
    add_func(L, "getChatMemberByIndex", luasteam_friends_SteamAPI_ISteamFriends_GetChatMemberByIndex);
    add_func(L, "sendClanChatMessage", luasteam_friends_SteamAPI_ISteamFriends_SendClanChatMessage);
    add_func(L, "isClanChatAdmin", luasteam_friends_SteamAPI_ISteamFriends_IsClanChatAdmin);
    add_func(L, "isClanChatWindowOpenInSteam", luasteam_friends_SteamAPI_ISteamFriends_IsClanChatWindowOpenInSteam);
    add_func(L, "openClanChatWindowInSteam", luasteam_friends_SteamAPI_ISteamFriends_OpenClanChatWindowInSteam);
    add_func(L, "closeClanChatWindowInSteam", luasteam_friends_SteamAPI_ISteamFriends_CloseClanChatWindowInSteam);
    add_func(L, "setListenForFriendsMessages", luasteam_friends_SteamAPI_ISteamFriends_SetListenForFriendsMessages);
    add_func(L, "replyToFriendMessage", luasteam_friends_SteamAPI_ISteamFriends_ReplyToFriendMessage);
    add_func(L, "getFollowerCount", luasteam_friends_SteamAPI_ISteamFriends_GetFollowerCount);
    add_func(L, "isFollowing", luasteam_friends_SteamAPI_ISteamFriends_IsFollowing);
    add_func(L, "enumerateFollowingList", luasteam_friends_SteamAPI_ISteamFriends_EnumerateFollowingList);
    add_func(L, "isClanPublic", luasteam_friends_SteamAPI_ISteamFriends_IsClanPublic);
    add_func(L, "isClanOfficialGameGroup", luasteam_friends_SteamAPI_ISteamFriends_IsClanOfficialGameGroup);
    add_func(L, "getNumChatsWithUnreadPriorityMessages", luasteam_friends_SteamAPI_ISteamFriends_GetNumChatsWithUnreadPriorityMessages);
    add_func(L, "activateGameOverlayRemotePlayTogetherInviteDialog", luasteam_friends_SteamAPI_ISteamFriends_ActivateGameOverlayRemotePlayTogetherInviteDialog);
    add_func(L, "registerProtocolInOverlayBrowser", luasteam_friends_SteamAPI_ISteamFriends_RegisterProtocolInOverlayBrowser);
    add_func(L, "activateGameOverlayInviteDialogConnectString", luasteam_friends_SteamAPI_ISteamFriends_ActivateGameOverlayInviteDialogConnectString);
    add_func(L, "requestEquippedProfileItems", luasteam_friends_SteamAPI_ISteamFriends_RequestEquippedProfileItems);
}

} // namespace luasteam
