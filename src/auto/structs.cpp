#include "auto.hpp"

namespace luasteam {

SteamIPAddress_t check_SteamIPAddress_t(lua_State *L, int index) {
    luaL_checktype(L, index, LUA_TTABLE);
    SteamIPAddress_t res;
    lua_getfield(L, index, "m_rgubIPv6");
    const char *_tmp0 = luaL_checkstring(L, -1); if (strlen(_tmp0) >= 16) luaL_error(L, "String too long"); memcpy(res.m_rgubIPv6, _tmp0, sizeof(res.m_rgubIPv6));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_eType");
    res.m_eType = static_cast<ESteamIPType>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    return res;
}

void push_SteamIPAddress_t(lua_State *L, SteamIPAddress_t val) {
    lua_createtable(L, 0, 2);
    lua_pushstring(L, reinterpret_cast<const char*>(val.m_rgubIPv6));
    lua_setfield(L, -2, "m_rgubIPv6");
    lua_pushinteger(L, val.m_eType);
    lua_setfield(L, -2, "m_eType");
}

FriendGameInfo_t check_FriendGameInfo_t(lua_State *L, int index) {
    luaL_checktype(L, index, LUA_TTABLE);
    FriendGameInfo_t res;
    lua_getfield(L, index, "m_gameID");
    res.m_gameID = CGameID(luasteam::checkuint64(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_unGameIP");
    res.m_unGameIP = static_cast<uint32>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_usGamePort");
    res.m_usGamePort = static_cast<uint16>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_usQueryPort");
    res.m_usQueryPort = static_cast<uint16>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_steamIDLobby");
    res.m_steamIDLobby = CSteamID(luasteam::checkuint64(L, -1));
    lua_pop(L, 1);
    return res;
}

void push_FriendGameInfo_t(lua_State *L, FriendGameInfo_t val) {
    lua_createtable(L, 0, 5);
    luasteam::pushuint64(L, val.m_gameID.ToUint64());
    lua_setfield(L, -2, "m_gameID");
    lua_pushinteger(L, val.m_unGameIP);
    lua_setfield(L, -2, "m_unGameIP");
    lua_pushinteger(L, val.m_usGamePort);
    lua_setfield(L, -2, "m_usGamePort");
    lua_pushinteger(L, val.m_usQueryPort);
    lua_setfield(L, -2, "m_usQueryPort");
    luasteam::pushuint64(L, val.m_steamIDLobby.ConvertToUint64());
    lua_setfield(L, -2, "m_steamIDLobby");
}

MatchMakingKeyValuePair_t check_MatchMakingKeyValuePair_t(lua_State *L, int index) {
    luaL_checktype(L, index, LUA_TTABLE);
    MatchMakingKeyValuePair_t res;
    lua_getfield(L, index, "m_szKey");
    const char *_tmp1 = luaL_checkstring(L, -1); if (strlen(_tmp1) >= 256) luaL_error(L, "String too long"); memcpy(res.m_szKey, _tmp1, sizeof(res.m_szKey));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_szValue");
    const char *_tmp2 = luaL_checkstring(L, -1); if (strlen(_tmp2) >= 256) luaL_error(L, "String too long"); memcpy(res.m_szValue, _tmp2, sizeof(res.m_szValue));
    lua_pop(L, 1);
    return res;
}

void push_MatchMakingKeyValuePair_t(lua_State *L, MatchMakingKeyValuePair_t val) {
    lua_createtable(L, 0, 2);
    lua_pushstring(L, reinterpret_cast<const char*>(val.m_szKey));
    lua_setfield(L, -2, "m_szKey");
    lua_pushstring(L, reinterpret_cast<const char*>(val.m_szValue));
    lua_setfield(L, -2, "m_szValue");
}

SteamPartyBeaconLocation_t check_SteamPartyBeaconLocation_t(lua_State *L, int index) {
    luaL_checktype(L, index, LUA_TTABLE);
    SteamPartyBeaconLocation_t res;
    lua_getfield(L, index, "m_eType");
    res.m_eType = static_cast<ESteamPartyBeaconLocationType>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_ulLocationID");
    res.m_ulLocationID = luasteam::checkuint64(L, -1);
    lua_pop(L, 1);
    return res;
}

void push_SteamPartyBeaconLocation_t(lua_State *L, SteamPartyBeaconLocation_t val) {
    lua_createtable(L, 0, 2);
    lua_pushinteger(L, val.m_eType);
    lua_setfield(L, -2, "m_eType");
    luasteam::pushuint64(L, val.m_ulLocationID);
    lua_setfield(L, -2, "m_ulLocationID");
}

LeaderboardEntry_t check_LeaderboardEntry_t(lua_State *L, int index) {
    luaL_checktype(L, index, LUA_TTABLE);
    LeaderboardEntry_t res;
    lua_getfield(L, index, "m_steamIDUser");
    res.m_steamIDUser = CSteamID(luasteam::checkuint64(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_nGlobalRank");
    res.m_nGlobalRank = static_cast<int32>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_nScore");
    res.m_nScore = static_cast<int32>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_cDetails");
    res.m_cDetails = static_cast<int32>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_hUGC");
    res.m_hUGC = luasteam::checkuint64(L, -1);
    lua_pop(L, 1);
    return res;
}

void push_LeaderboardEntry_t(lua_State *L, LeaderboardEntry_t val) {
    lua_createtable(L, 0, 5);
    luasteam::pushuint64(L, val.m_steamIDUser.ConvertToUint64());
    lua_setfield(L, -2, "m_steamIDUser");
    lua_pushinteger(L, val.m_nGlobalRank);
    lua_setfield(L, -2, "m_nGlobalRank");
    lua_pushinteger(L, val.m_nScore);
    lua_setfield(L, -2, "m_nScore");
    lua_pushinteger(L, val.m_cDetails);
    lua_setfield(L, -2, "m_cDetails");
    luasteam::pushuint64(L, val.m_hUGC);
    lua_setfield(L, -2, "m_hUGC");
}

P2PSessionState_t check_P2PSessionState_t(lua_State *L, int index) {
    luaL_checktype(L, index, LUA_TTABLE);
    P2PSessionState_t res;
    lua_getfield(L, index, "m_bConnectionActive");
    res.m_bConnectionActive = static_cast<uint8>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_bConnecting");
    res.m_bConnecting = static_cast<uint8>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_eP2PSessionError");
    res.m_eP2PSessionError = static_cast<uint8>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_bUsingRelay");
    res.m_bUsingRelay = static_cast<uint8>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_nBytesQueuedForSend");
    res.m_nBytesQueuedForSend = static_cast<int32>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_nPacketsQueuedForSend");
    res.m_nPacketsQueuedForSend = static_cast<int32>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_nRemoteIP");
    res.m_nRemoteIP = static_cast<uint32>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_nRemotePort");
    res.m_nRemotePort = static_cast<uint16>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    return res;
}

void push_P2PSessionState_t(lua_State *L, P2PSessionState_t val) {
    lua_createtable(L, 0, 8);
    lua_pushinteger(L, val.m_bConnectionActive);
    lua_setfield(L, -2, "m_bConnectionActive");
    lua_pushinteger(L, val.m_bConnecting);
    lua_setfield(L, -2, "m_bConnecting");
    lua_pushinteger(L, val.m_eP2PSessionError);
    lua_setfield(L, -2, "m_eP2PSessionError");
    lua_pushinteger(L, val.m_bUsingRelay);
    lua_setfield(L, -2, "m_bUsingRelay");
    lua_pushinteger(L, val.m_nBytesQueuedForSend);
    lua_setfield(L, -2, "m_nBytesQueuedForSend");
    lua_pushinteger(L, val.m_nPacketsQueuedForSend);
    lua_setfield(L, -2, "m_nPacketsQueuedForSend");
    lua_pushinteger(L, val.m_nRemoteIP);
    lua_setfield(L, -2, "m_nRemoteIP");
    lua_pushinteger(L, val.m_nRemotePort);
    lua_setfield(L, -2, "m_nRemotePort");
}

InputAnalogActionData_t check_InputAnalogActionData_t(lua_State *L, int index) {
    luaL_checktype(L, index, LUA_TTABLE);
    InputAnalogActionData_t res;
    lua_getfield(L, index, "eMode");
    res.eMode = static_cast<EInputSourceMode>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "x");
    res.x = static_cast<float>(luaL_checknumber(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "y");
    res.y = static_cast<float>(luaL_checknumber(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "bActive");
    res.bActive = lua_toboolean(L, -1);
    lua_pop(L, 1);
    return res;
}

void push_InputAnalogActionData_t(lua_State *L, InputAnalogActionData_t val) {
    lua_createtable(L, 0, 4);
    lua_pushinteger(L, val.eMode);
    lua_setfield(L, -2, "eMode");
    lua_pushnumber(L, val.x);
    lua_setfield(L, -2, "x");
    lua_pushnumber(L, val.y);
    lua_setfield(L, -2, "y");
    lua_pushboolean(L, val.bActive);
    lua_setfield(L, -2, "bActive");
}

InputDigitalActionData_t check_InputDigitalActionData_t(lua_State *L, int index) {
    luaL_checktype(L, index, LUA_TTABLE);
    InputDigitalActionData_t res;
    lua_getfield(L, index, "bState");
    res.bState = lua_toboolean(L, -1);
    lua_pop(L, 1);
    lua_getfield(L, index, "bActive");
    res.bActive = lua_toboolean(L, -1);
    lua_pop(L, 1);
    return res;
}

void push_InputDigitalActionData_t(lua_State *L, InputDigitalActionData_t val) {
    lua_createtable(L, 0, 2);
    lua_pushboolean(L, val.bState);
    lua_setfield(L, -2, "bState");
    lua_pushboolean(L, val.bActive);
    lua_setfield(L, -2, "bActive");
}

InputMotionData_t check_InputMotionData_t(lua_State *L, int index) {
    luaL_checktype(L, index, LUA_TTABLE);
    InputMotionData_t res;
    lua_getfield(L, index, "rotQuatX");
    res.rotQuatX = static_cast<float>(luaL_checknumber(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "rotQuatY");
    res.rotQuatY = static_cast<float>(luaL_checknumber(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "rotQuatZ");
    res.rotQuatZ = static_cast<float>(luaL_checknumber(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "rotQuatW");
    res.rotQuatW = static_cast<float>(luaL_checknumber(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "posAccelX");
    res.posAccelX = static_cast<float>(luaL_checknumber(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "posAccelY");
    res.posAccelY = static_cast<float>(luaL_checknumber(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "posAccelZ");
    res.posAccelZ = static_cast<float>(luaL_checknumber(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "rotVelX");
    res.rotVelX = static_cast<float>(luaL_checknumber(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "rotVelY");
    res.rotVelY = static_cast<float>(luaL_checknumber(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "rotVelZ");
    res.rotVelZ = static_cast<float>(luaL_checknumber(L, -1));
    lua_pop(L, 1);
    return res;
}

void push_InputMotionData_t(lua_State *L, InputMotionData_t val) {
    lua_createtable(L, 0, 10);
    lua_pushnumber(L, val.rotQuatX);
    lua_setfield(L, -2, "rotQuatX");
    lua_pushnumber(L, val.rotQuatY);
    lua_setfield(L, -2, "rotQuatY");
    lua_pushnumber(L, val.rotQuatZ);
    lua_setfield(L, -2, "rotQuatZ");
    lua_pushnumber(L, val.rotQuatW);
    lua_setfield(L, -2, "rotQuatW");
    lua_pushnumber(L, val.posAccelX);
    lua_setfield(L, -2, "posAccelX");
    lua_pushnumber(L, val.posAccelY);
    lua_setfield(L, -2, "posAccelY");
    lua_pushnumber(L, val.posAccelZ);
    lua_setfield(L, -2, "posAccelZ");
    lua_pushnumber(L, val.rotVelX);
    lua_setfield(L, -2, "rotVelX");
    lua_pushnumber(L, val.rotVelY);
    lua_setfield(L, -2, "rotVelY");
    lua_pushnumber(L, val.rotVelZ);
    lua_setfield(L, -2, "rotVelZ");
}

SteamUGCDetails_t check_SteamUGCDetails_t(lua_State *L, int index) {
    luaL_checktype(L, index, LUA_TTABLE);
    SteamUGCDetails_t res;
    lua_getfield(L, index, "m_nPublishedFileId");
    res.m_nPublishedFileId = luasteam::checkuint64(L, -1);
    lua_pop(L, 1);
    lua_getfield(L, index, "m_eResult");
    res.m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_eFileType");
    res.m_eFileType = static_cast<EWorkshopFileType>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_nCreatorAppID");
    res.m_nCreatorAppID = static_cast<AppId_t>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_nConsumerAppID");
    res.m_nConsumerAppID = static_cast<AppId_t>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_rgchTitle");
    const char *_tmp3 = luaL_checkstring(L, -1); if (strlen(_tmp3) >= 129) luaL_error(L, "String too long"); memcpy(res.m_rgchTitle, _tmp3, sizeof(res.m_rgchTitle));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_rgchDescription");
    const char *_tmp4 = luaL_checkstring(L, -1); if (strlen(_tmp4) >= 8000) luaL_error(L, "String too long"); memcpy(res.m_rgchDescription, _tmp4, sizeof(res.m_rgchDescription));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_ulSteamIDOwner");
    res.m_ulSteamIDOwner = luasteam::checkuint64(L, -1);
    lua_pop(L, 1);
    lua_getfield(L, index, "m_rtimeCreated");
    res.m_rtimeCreated = static_cast<uint32>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_rtimeUpdated");
    res.m_rtimeUpdated = static_cast<uint32>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_rtimeAddedToUserList");
    res.m_rtimeAddedToUserList = static_cast<uint32>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_eVisibility");
    res.m_eVisibility = static_cast<ERemoteStoragePublishedFileVisibility>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_bBanned");
    res.m_bBanned = lua_toboolean(L, -1);
    lua_pop(L, 1);
    lua_getfield(L, index, "m_bAcceptedForUse");
    res.m_bAcceptedForUse = lua_toboolean(L, -1);
    lua_pop(L, 1);
    lua_getfield(L, index, "m_bTagsTruncated");
    res.m_bTagsTruncated = lua_toboolean(L, -1);
    lua_pop(L, 1);
    lua_getfield(L, index, "m_rgchTags");
    const char *_tmp5 = luaL_checkstring(L, -1); if (strlen(_tmp5) >= 1025) luaL_error(L, "String too long"); memcpy(res.m_rgchTags, _tmp5, sizeof(res.m_rgchTags));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_hFile");
    res.m_hFile = luasteam::checkuint64(L, -1);
    lua_pop(L, 1);
    lua_getfield(L, index, "m_hPreviewFile");
    res.m_hPreviewFile = luasteam::checkuint64(L, -1);
    lua_pop(L, 1);
    lua_getfield(L, index, "m_pchFileName");
    const char *_tmp6 = luaL_checkstring(L, -1); if (strlen(_tmp6) >= 260) luaL_error(L, "String too long"); memcpy(res.m_pchFileName, _tmp6, sizeof(res.m_pchFileName));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_nFileSize");
    res.m_nFileSize = static_cast<int32>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_nPreviewFileSize");
    res.m_nPreviewFileSize = static_cast<int32>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_rgchURL");
    const char *_tmp7 = luaL_checkstring(L, -1); if (strlen(_tmp7) >= 256) luaL_error(L, "String too long"); memcpy(res.m_rgchURL, _tmp7, sizeof(res.m_rgchURL));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_unVotesUp");
    res.m_unVotesUp = static_cast<uint32>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_unVotesDown");
    res.m_unVotesDown = static_cast<uint32>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_flScore");
    res.m_flScore = static_cast<float>(luaL_checknumber(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_unNumChildren");
    res.m_unNumChildren = static_cast<uint32>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_ulTotalFilesSize");
    res.m_ulTotalFilesSize = luasteam::checkuint64(L, -1);
    lua_pop(L, 1);
    return res;
}

void push_SteamUGCDetails_t(lua_State *L, SteamUGCDetails_t val) {
    lua_createtable(L, 0, 27);
    luasteam::pushuint64(L, val.m_nPublishedFileId);
    lua_setfield(L, -2, "m_nPublishedFileId");
    lua_pushinteger(L, val.m_eResult);
    lua_setfield(L, -2, "m_eResult");
    lua_pushinteger(L, val.m_eFileType);
    lua_setfield(L, -2, "m_eFileType");
    lua_pushinteger(L, val.m_nCreatorAppID);
    lua_setfield(L, -2, "m_nCreatorAppID");
    lua_pushinteger(L, val.m_nConsumerAppID);
    lua_setfield(L, -2, "m_nConsumerAppID");
    lua_pushstring(L, reinterpret_cast<const char*>(val.m_rgchTitle));
    lua_setfield(L, -2, "m_rgchTitle");
    lua_pushstring(L, reinterpret_cast<const char*>(val.m_rgchDescription));
    lua_setfield(L, -2, "m_rgchDescription");
    luasteam::pushuint64(L, val.m_ulSteamIDOwner);
    lua_setfield(L, -2, "m_ulSteamIDOwner");
    lua_pushinteger(L, val.m_rtimeCreated);
    lua_setfield(L, -2, "m_rtimeCreated");
    lua_pushinteger(L, val.m_rtimeUpdated);
    lua_setfield(L, -2, "m_rtimeUpdated");
    lua_pushinteger(L, val.m_rtimeAddedToUserList);
    lua_setfield(L, -2, "m_rtimeAddedToUserList");
    lua_pushinteger(L, val.m_eVisibility);
    lua_setfield(L, -2, "m_eVisibility");
    lua_pushboolean(L, val.m_bBanned);
    lua_setfield(L, -2, "m_bBanned");
    lua_pushboolean(L, val.m_bAcceptedForUse);
    lua_setfield(L, -2, "m_bAcceptedForUse");
    lua_pushboolean(L, val.m_bTagsTruncated);
    lua_setfield(L, -2, "m_bTagsTruncated");
    lua_pushstring(L, reinterpret_cast<const char*>(val.m_rgchTags));
    lua_setfield(L, -2, "m_rgchTags");
    luasteam::pushuint64(L, val.m_hFile);
    lua_setfield(L, -2, "m_hFile");
    luasteam::pushuint64(L, val.m_hPreviewFile);
    lua_setfield(L, -2, "m_hPreviewFile");
    lua_pushstring(L, reinterpret_cast<const char*>(val.m_pchFileName));
    lua_setfield(L, -2, "m_pchFileName");
    lua_pushinteger(L, val.m_nFileSize);
    lua_setfield(L, -2, "m_nFileSize");
    lua_pushinteger(L, val.m_nPreviewFileSize);
    lua_setfield(L, -2, "m_nPreviewFileSize");
    lua_pushstring(L, reinterpret_cast<const char*>(val.m_rgchURL));
    lua_setfield(L, -2, "m_rgchURL");
    lua_pushinteger(L, val.m_unVotesUp);
    lua_setfield(L, -2, "m_unVotesUp");
    lua_pushinteger(L, val.m_unVotesDown);
    lua_setfield(L, -2, "m_unVotesDown");
    lua_pushnumber(L, val.m_flScore);
    lua_setfield(L, -2, "m_flScore");
    lua_pushinteger(L, val.m_unNumChildren);
    lua_setfield(L, -2, "m_unNumChildren");
    luasteam::pushuint64(L, val.m_ulTotalFilesSize);
    lua_setfield(L, -2, "m_ulTotalFilesSize");
}

SteamItemDetails_t check_SteamItemDetails_t(lua_State *L, int index) {
    luaL_checktype(L, index, LUA_TTABLE);
    SteamItemDetails_t res;
    lua_getfield(L, index, "m_itemId");
    res.m_itemId = luasteam::checkuint64(L, -1);
    lua_pop(L, 1);
    lua_getfield(L, index, "m_iDefinition");
    res.m_iDefinition = static_cast<SteamItemDef_t>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_unQuantity");
    res.m_unQuantity = static_cast<uint16>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_unFlags");
    res.m_unFlags = static_cast<uint16>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    return res;
}

void push_SteamItemDetails_t(lua_State *L, SteamItemDetails_t val) {
    lua_createtable(L, 0, 4);
    luasteam::pushuint64(L, val.m_itemId);
    lua_setfield(L, -2, "m_itemId");
    lua_pushinteger(L, val.m_iDefinition);
    lua_setfield(L, -2, "m_iDefinition");
    lua_pushinteger(L, val.m_unQuantity);
    lua_setfield(L, -2, "m_unQuantity");
    lua_pushinteger(L, val.m_unFlags);
    lua_setfield(L, -2, "m_unFlags");
}

RemotePlayInputMouseMotion_t check_RemotePlayInputMouseMotion_t(lua_State *L, int index) {
    luaL_checktype(L, index, LUA_TTABLE);
    RemotePlayInputMouseMotion_t res;
    lua_getfield(L, index, "m_bAbsolute");
    res.m_bAbsolute = lua_toboolean(L, -1);
    lua_pop(L, 1);
    lua_getfield(L, index, "m_flNormalizedX");
    res.m_flNormalizedX = static_cast<float>(luaL_checknumber(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_flNormalizedY");
    res.m_flNormalizedY = static_cast<float>(luaL_checknumber(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_nDeltaX");
    res.m_nDeltaX = static_cast<int>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_nDeltaY");
    res.m_nDeltaY = static_cast<int>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    return res;
}

void push_RemotePlayInputMouseMotion_t(lua_State *L, RemotePlayInputMouseMotion_t val) {
    lua_createtable(L, 0, 5);
    lua_pushboolean(L, val.m_bAbsolute);
    lua_setfield(L, -2, "m_bAbsolute");
    lua_pushnumber(L, val.m_flNormalizedX);
    lua_setfield(L, -2, "m_flNormalizedX");
    lua_pushnumber(L, val.m_flNormalizedY);
    lua_setfield(L, -2, "m_flNormalizedY");
    lua_pushinteger(L, val.m_nDeltaX);
    lua_setfield(L, -2, "m_nDeltaX");
    lua_pushinteger(L, val.m_nDeltaY);
    lua_setfield(L, -2, "m_nDeltaY");
}

RemotePlayInputMouseWheel_t check_RemotePlayInputMouseWheel_t(lua_State *L, int index) {
    luaL_checktype(L, index, LUA_TTABLE);
    RemotePlayInputMouseWheel_t res;
    lua_getfield(L, index, "m_eDirection");
    res.m_eDirection = static_cast<ERemotePlayMouseWheelDirection>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_flAmount");
    res.m_flAmount = static_cast<float>(luaL_checknumber(L, -1));
    lua_pop(L, 1);
    return res;
}

void push_RemotePlayInputMouseWheel_t(lua_State *L, RemotePlayInputMouseWheel_t val) {
    lua_createtable(L, 0, 2);
    lua_pushinteger(L, val.m_eDirection);
    lua_setfield(L, -2, "m_eDirection");
    lua_pushnumber(L, val.m_flAmount);
    lua_setfield(L, -2, "m_flAmount");
}

RemotePlayInputKey_t check_RemotePlayInputKey_t(lua_State *L, int index) {
    luaL_checktype(L, index, LUA_TTABLE);
    RemotePlayInputKey_t res;
    lua_getfield(L, index, "m_eScancode");
    res.m_eScancode = static_cast<int>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_unModifiers");
    res.m_unModifiers = static_cast<uint32>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_unKeycode");
    res.m_unKeycode = static_cast<uint32>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    return res;
}

void push_RemotePlayInputKey_t(lua_State *L, RemotePlayInputKey_t val) {
    lua_createtable(L, 0, 3);
    lua_pushinteger(L, val.m_eScancode);
    lua_setfield(L, -2, "m_eScancode");
    lua_pushinteger(L, val.m_unModifiers);
    lua_setfield(L, -2, "m_unModifiers");
    lua_pushinteger(L, val.m_unKeycode);
    lua_setfield(L, -2, "m_unKeycode");
}

RemotePlayInput_t check_RemotePlayInput_t(lua_State *L, int index) {
    luaL_checktype(L, index, LUA_TTABLE);
    RemotePlayInput_t res;
    lua_getfield(L, index, "m_unSessionID");
    res.m_unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_eType");
    res.m_eType = static_cast<ERemotePlayInputType>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "padding");
    const char *_tmp8 = luaL_checkstring(L, -1); if (strlen(_tmp8) >= 56) luaL_error(L, "String too long"); memcpy(res.padding, _tmp8, sizeof(res.padding));
    lua_pop(L, 1);
    return res;
}

void push_RemotePlayInput_t(lua_State *L, RemotePlayInput_t val) {
    lua_createtable(L, 0, 3);
    lua_pushinteger(L, val.m_unSessionID);
    lua_setfield(L, -2, "m_unSessionID");
    lua_pushinteger(L, val.m_eType);
    lua_setfield(L, -2, "m_eType");
    lua_pushstring(L, reinterpret_cast<const char*>(val.padding));
    lua_setfield(L, -2, "padding");
}

SteamNetworkingIPAddr check_SteamNetworkingIPAddr(lua_State *L, int index) {
    luaL_checktype(L, index, LUA_TTABLE);
    SteamNetworkingIPAddr res;
    lua_getfield(L, index, "m_ipv6");
    const char *_tmp9 = luaL_checkstring(L, -1); if (strlen(_tmp9) >= 16) luaL_error(L, "String too long"); memcpy(res.m_ipv6, _tmp9, sizeof(res.m_ipv6));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_port");
    res.m_port = static_cast<uint16>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    return res;
}

void push_SteamNetworkingIPAddr(lua_State *L, SteamNetworkingIPAddr val) {
    lua_createtable(L, 0, 2);
    lua_pushstring(L, reinterpret_cast<const char*>(val.m_ipv6));
    lua_setfield(L, -2, "m_ipv6");
    lua_pushinteger(L, val.m_port);
    lua_setfield(L, -2, "m_port");
}

SteamNetworkingIdentity check_SteamNetworkingIdentity(lua_State *L, int index) {
    luaL_checktype(L, index, LUA_TTABLE);
    SteamNetworkingIdentity res;
    lua_getfield(L, index, "m_eType");
    res.m_eType = static_cast<ESteamNetworkingIdentityType>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_cbSize");
    res.m_cbSize = static_cast<int>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_szUnknownRawString");
    const char *_tmp10 = luaL_checkstring(L, -1); if (strlen(_tmp10) >= 128) luaL_error(L, "String too long"); memcpy(res.m_szUnknownRawString, _tmp10, sizeof(res.m_szUnknownRawString));
    lua_pop(L, 1);
    return res;
}

void push_SteamNetworkingIdentity(lua_State *L, SteamNetworkingIdentity val) {
    lua_createtable(L, 0, 3);
    lua_pushinteger(L, val.m_eType);
    lua_setfield(L, -2, "m_eType");
    lua_pushinteger(L, val.m_cbSize);
    lua_setfield(L, -2, "m_cbSize");
    lua_pushstring(L, reinterpret_cast<const char*>(val.m_szUnknownRawString));
    lua_setfield(L, -2, "m_szUnknownRawString");
}

SteamNetConnectionInfo_t check_SteamNetConnectionInfo_t(lua_State *L, int index) {
    luaL_checktype(L, index, LUA_TTABLE);
    SteamNetConnectionInfo_t res;
    lua_getfield(L, index, "m_identityRemote");
    res.m_identityRemote = check_SteamNetworkingIdentity(L, -1);
    lua_pop(L, 1);
    lua_getfield(L, index, "m_nUserData");
    res.m_nUserData = luasteam::checkuint64(L, -1);
    lua_pop(L, 1);
    lua_getfield(L, index, "m_hListenSocket");
    res.m_hListenSocket = static_cast<HSteamListenSocket>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_addrRemote");
    res.m_addrRemote = check_SteamNetworkingIPAddr(L, -1);
    lua_pop(L, 1);
    lua_getfield(L, index, "m__pad1");
    res.m__pad1 = static_cast<uint16>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_idPOPRemote");
    res.m_idPOPRemote = static_cast<SteamNetworkingPOPID>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_idPOPRelay");
    res.m_idPOPRelay = static_cast<SteamNetworkingPOPID>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_eState");
    res.m_eState = static_cast<ESteamNetworkingConnectionState>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_eEndReason");
    res.m_eEndReason = static_cast<int>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_szEndDebug");
    const char *_tmp11 = luaL_checkstring(L, -1); if (strlen(_tmp11) >= 128) luaL_error(L, "String too long"); memcpy(res.m_szEndDebug, _tmp11, sizeof(res.m_szEndDebug));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_szConnectionDescription");
    const char *_tmp12 = luaL_checkstring(L, -1); if (strlen(_tmp12) >= 128) luaL_error(L, "String too long"); memcpy(res.m_szConnectionDescription, _tmp12, sizeof(res.m_szConnectionDescription));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_nFlags");
    res.m_nFlags = static_cast<int>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "reserved");
    luaL_checktype(L, -1, LUA_TTABLE); for(decltype(63) i=0;i<63;i++){ lua_rawgeti(L,-1,i+1); res.reserved[i] = static_cast<int>(luaL_checkint(L, -1)); lua_pop(L, 1); }
    lua_pop(L, 1);
    return res;
}

void push_SteamNetConnectionInfo_t(lua_State *L, SteamNetConnectionInfo_t val) {
    lua_createtable(L, 0, 13);
    push_SteamNetworkingIdentity(L, val.m_identityRemote);
    lua_setfield(L, -2, "m_identityRemote");
    luasteam::pushuint64(L, val.m_nUserData);
    lua_setfield(L, -2, "m_nUserData");
    lua_pushinteger(L, val.m_hListenSocket);
    lua_setfield(L, -2, "m_hListenSocket");
    push_SteamNetworkingIPAddr(L, val.m_addrRemote);
    lua_setfield(L, -2, "m_addrRemote");
    lua_pushinteger(L, val.m__pad1);
    lua_setfield(L, -2, "m__pad1");
    lua_pushinteger(L, val.m_idPOPRemote);
    lua_setfield(L, -2, "m_idPOPRemote");
    lua_pushinteger(L, val.m_idPOPRelay);
    lua_setfield(L, -2, "m_idPOPRelay");
    lua_pushinteger(L, val.m_eState);
    lua_setfield(L, -2, "m_eState");
    lua_pushinteger(L, val.m_eEndReason);
    lua_setfield(L, -2, "m_eEndReason");
    lua_pushstring(L, reinterpret_cast<const char*>(val.m_szEndDebug));
    lua_setfield(L, -2, "m_szEndDebug");
    lua_pushstring(L, reinterpret_cast<const char*>(val.m_szConnectionDescription));
    lua_setfield(L, -2, "m_szConnectionDescription");
    lua_pushinteger(L, val.m_nFlags);
    lua_setfield(L, -2, "m_nFlags");
        lua_createtable(L, 63, 0);
    for(decltype(63) i=0;i<63;i++){
    lua_pushinteger(L, val.reserved[i]);
    lua_rawseti(L, -2, i+1);
    }

    lua_setfield(L, -2, "reserved");
}

SteamNetworkPingLocation_t check_SteamNetworkPingLocation_t(lua_State *L, int index) {
    luaL_checktype(L, index, LUA_TTABLE);
    SteamNetworkPingLocation_t res;
    lua_getfield(L, index, "m_data");
    const char *_tmp13 = luaL_checkstring(L, -1); if (strlen(_tmp13) >= 512) luaL_error(L, "String too long"); memcpy(res.m_data, _tmp13, sizeof(res.m_data));
    lua_pop(L, 1);
    return res;
}

void push_SteamNetworkPingLocation_t(lua_State *L, SteamNetworkPingLocation_t val) {
    lua_createtable(L, 0, 1);
    lua_pushstring(L, reinterpret_cast<const char*>(val.m_data));
    lua_setfield(L, -2, "m_data");
}

SteamNetworkingConfigValue_t check_SteamNetworkingConfigValue_t(lua_State *L, int index) {
    luaL_checktype(L, index, LUA_TTABLE);
    SteamNetworkingConfigValue_t res;
    lua_getfield(L, index, "m_eValue");
    res.m_eValue = static_cast<ESteamNetworkingConfigValue>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_eDataType");
    res.m_eDataType = static_cast<ESteamNetworkingConfigDataType>(luaL_checkint(L, -1));
    lua_pop(L, 1);
    lua_getfield(L, index, "m_val.m_int64");
    res.m_val.m_int64 = luasteam::checkuint64(L, -1);
    lua_pop(L, 1);
    return res;
}

void push_SteamNetworkingConfigValue_t(lua_State *L, SteamNetworkingConfigValue_t val) {
    lua_createtable(L, 0, 3);
    lua_pushinteger(L, val.m_eValue);
    lua_setfield(L, -2, "m_eValue");
    lua_pushinteger(L, val.m_eDataType);
    lua_setfield(L, -2, "m_eDataType");
    luasteam::pushuint64(L, val.m_val.m_int64);
    lua_setfield(L, -2, "m_val.m_int64");
}

} // namespace luasteam
