---@class Steam.Matchmaking
local Matchmaking = {}

---@return integer
function Matchmaking.GetFavoriteGameCount() end

---@param iGame integer
---@return boolean
---@return integer
---@return integer
---@return integer
---@return integer
---@return integer
---@return integer
function Matchmaking.GetFavoriteGame(iGame) end

---@param nAppID integer
---@param nIP integer
---@param nConnPort integer
---@param nQueryPort integer
---@param unFlags integer
---@param rTime32LastPlayedOnServer integer
---@return integer
function Matchmaking.AddFavoriteGame(nAppID, nIP, nConnPort, nQueryPort, unFlags, rTime32LastPlayedOnServer) end

---@param nAppID integer
---@param nIP integer
---@param nConnPort integer
---@param nQueryPort integer
---@param unFlags integer
---@return boolean
function Matchmaking.RemoveFavoriteGame(nAppID, nIP, nConnPort, nQueryPort, unFlags) end

---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function Matchmaking.RequestLobbyList(callback) end

---@param pchKeyToMatch string
---@param pchValueToMatch string
---@param eComparisonType integer
function Matchmaking.AddRequestLobbyListStringFilter(pchKeyToMatch, pchValueToMatch, eComparisonType) end

---@param pchKeyToMatch string
---@param nValueToMatch integer
---@param eComparisonType integer
function Matchmaking.AddRequestLobbyListNumericalFilter(pchKeyToMatch, nValueToMatch, eComparisonType) end

---@param pchKeyToMatch string
---@param nValueToBeCloseTo integer
function Matchmaking.AddRequestLobbyListNearValueFilter(pchKeyToMatch, nValueToBeCloseTo) end

---@param nSlotsAvailable integer
function Matchmaking.AddRequestLobbyListFilterSlotsAvailable(nSlotsAvailable) end

---@param eLobbyDistanceFilter integer
function Matchmaking.AddRequestLobbyListDistanceFilter(eLobbyDistanceFilter) end

---@param cMaxResults integer
function Matchmaking.AddRequestLobbyListResultCountFilter(cMaxResults) end

---@param steamIDLobby uint64
function Matchmaking.AddRequestLobbyListCompatibleMembersFilter(steamIDLobby) end

---@param iLobby integer
---@return uint64
function Matchmaking.GetLobbyByIndex(iLobby) end

---@param eLobbyType integer
---@param cMaxMembers integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function Matchmaking.CreateLobby(eLobbyType, cMaxMembers, callback) end

---@param steamIDLobby uint64
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function Matchmaking.JoinLobby(steamIDLobby, callback) end

---@param steamIDLobby uint64
function Matchmaking.LeaveLobby(steamIDLobby) end

---@param steamIDLobby uint64
---@param steamIDInvitee uint64
---@return boolean
function Matchmaking.InviteUserToLobby(steamIDLobby, steamIDInvitee) end

---@param steamIDLobby uint64
---@return integer
function Matchmaking.GetNumLobbyMembers(steamIDLobby) end

---@param steamIDLobby uint64
---@param iMember integer
---@return uint64
function Matchmaking.GetLobbyMemberByIndex(steamIDLobby, iMember) end

---@param steamIDLobby uint64
---@param pchKey string
---@return string
function Matchmaking.GetLobbyData(steamIDLobby, pchKey) end

---@param steamIDLobby uint64
---@param pchKey string
---@param pchValue string
---@return boolean
function Matchmaking.SetLobbyData(steamIDLobby, pchKey, pchValue) end

---@param steamIDLobby uint64
---@return integer
function Matchmaking.GetLobbyDataCount(steamIDLobby) end

---@param steamIDLobby uint64
---@param iLobbyData integer
---@param pchKey string
---@param cchKeyBufferSize integer
---@param pchValue string
---@param cchValueBufferSize integer
---@return boolean
function Matchmaking.GetLobbyDataByIndex(steamIDLobby, iLobbyData, pchKey, cchKeyBufferSize, pchValue, cchValueBufferSize) end

---@param steamIDLobby uint64
---@param pchKey string
---@return boolean
function Matchmaking.DeleteLobbyData(steamIDLobby, pchKey) end

---@param steamIDLobby uint64
---@param steamIDUser uint64
---@param pchKey string
---@return string
function Matchmaking.GetLobbyMemberData(steamIDLobby, steamIDUser, pchKey) end

---@param steamIDLobby uint64
---@param pchKey string
---@param pchValue string
function Matchmaking.SetLobbyMemberData(steamIDLobby, pchKey, pchValue) end

---@param steamIDLobby uint64
---@param pvMsgBody table
---@param cubMsgBody integer
---@return boolean
function Matchmaking.SendLobbyChatMsg(steamIDLobby, pvMsgBody, cubMsgBody) end

---@param steamIDLobby uint64
---@param iChatID integer
---@param cubData integer
---@return integer
---@return uint64
---@return table
---@return integer
function Matchmaking.GetLobbyChatEntry(steamIDLobby, iChatID, cubData) end

---@param steamIDLobby uint64
---@return boolean
function Matchmaking.RequestLobbyData(steamIDLobby) end

---@param steamIDLobby uint64
---@param unGameServerIP integer
---@param unGameServerPort integer
---@param steamIDGameServer uint64
function Matchmaking.SetLobbyGameServer(steamIDLobby, unGameServerIP, unGameServerPort, steamIDGameServer) end

---@param steamIDLobby uint64
---@return boolean
---@return integer
---@return integer
---@return uint64
function Matchmaking.GetLobbyGameServer(steamIDLobby) end

---@param steamIDLobby uint64
---@param cMaxMembers integer
---@return boolean
function Matchmaking.SetLobbyMemberLimit(steamIDLobby, cMaxMembers) end

---@param steamIDLobby uint64
---@return integer
function Matchmaking.GetLobbyMemberLimit(steamIDLobby) end

---@param steamIDLobby uint64
---@param eLobbyType integer
---@return boolean
function Matchmaking.SetLobbyType(steamIDLobby, eLobbyType) end

---@param steamIDLobby uint64
---@param bLobbyJoinable boolean
---@return boolean
function Matchmaking.SetLobbyJoinable(steamIDLobby, bLobbyJoinable) end

---@param steamIDLobby uint64
---@return uint64
function Matchmaking.GetLobbyOwner(steamIDLobby) end

---@param steamIDLobby uint64
---@param steamIDNewOwner uint64
---@return boolean
function Matchmaking.SetLobbyOwner(steamIDLobby, steamIDNewOwner) end

---@param steamIDLobby uint64
---@param steamIDLobbyDependent uint64
---@return boolean
function Matchmaking.SetLinkedLobby(steamIDLobby, steamIDLobbyDependent) end

Steam.Matchmaking = Matchmaking
