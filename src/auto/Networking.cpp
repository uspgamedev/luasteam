#include "auto.hpp"

namespace luasteam {

int Networking_ref = LUA_NOREF;

namespace {
class CallbackListener {
private:
	STEAM_CALLBACK(CallbackListener, OnP2PSessionRequest, P2PSessionRequest_t);
	STEAM_CALLBACK(CallbackListener, OnP2PSessionConnectFail, P2PSessionConnectFail_t);
	STEAM_CALLBACK(CallbackListener, OnSocketStatusCallback, SocketStatusCallback_t);
};
void CallbackListener::OnP2PSessionRequest(P2PSessionRequest_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Networking_ref);
	lua_getfield(L, -1, "OnP2PSessionRequest");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 1);
		luasteam::pushuint64(L, data->m_steamIDRemote.ConvertToUint64());
		lua_setfield(L, -2, "m_steamIDRemote");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnP2PSessionConnectFail(P2PSessionConnectFail_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Networking_ref);
	lua_getfield(L, -1, "OnP2PSessionConnectFail");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 2);
		luasteam::pushuint64(L, data->m_steamIDRemote.ConvertToUint64());
		lua_setfield(L, -2, "m_steamIDRemote");
		lua_pushinteger(L, data->m_eP2PSessionError);
		lua_setfield(L, -2, "m_eP2PSessionError");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnSocketStatusCallback(SocketStatusCallback_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Networking_ref);
	lua_getfield(L, -1, "OnSocketStatusCallback");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 4);
		lua_pushinteger(L, data->m_hSocket);
		lua_setfield(L, -2, "m_hSocket");
		lua_pushinteger(L, data->m_hListenSocket);
		lua_setfield(L, -2, "m_hListenSocket");
		luasteam::pushuint64(L, data->m_steamIDRemote.ConvertToUint64());
		lua_setfield(L, -2, "m_steamIDRemote");
		lua_pushinteger(L, data->m_eSNetSocketState);
		lua_setfield(L, -2, "m_eSNetSocketState");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
CallbackListener *Networking_listener = nullptr;
} // namespace

void init_Networking_auto(lua_State *L) { Networking_listener = new CallbackListener(); }
void shutdown_Networking_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, Networking_ref);
	Networking_ref = LUA_NOREF;
	delete Networking_listener; Networking_listener = nullptr;
}

// In C++:
// bool SendP2PPacket(CSteamID steamIDRemote, const void * pubData, uint32 cubData, EP2PSend eP2PSendType, int nChannel);
// In Lua:
// bool Networking.SendP2PPacket(steamIDRemote: uint64, pubData: str, cubData: int, eP2PSendType: int, nChannel: int)
EXTERN int luasteam_Networking_SendP2PPacket(lua_State *L) {
	CSteamID steamIDRemote(luasteam::checkuint64(L, 1));
	const char *pubData = luaL_checkstring(L, 2);
	uint32 cubData = static_cast<uint32>(luaL_checkint(L, 3));
	EP2PSend eP2PSendType = static_cast<EP2PSend>(luaL_checkint(L, 4));
	int nChannel = static_cast<int>(luaL_checkint(L, 5));
	bool __ret = SteamNetworking()->SendP2PPacket(steamIDRemote, pubData, cubData, eP2PSendType, nChannel);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool IsP2PPacketAvailable(uint32 * pcubMsgSize, int nChannel);
// In Lua:
// (bool, pcubMsgSize: int) Networking.IsP2PPacketAvailable(nChannel: int)
EXTERN int luasteam_Networking_IsP2PPacketAvailable(lua_State *L) {
	uint32 pcubMsgSize;
	int nChannel = static_cast<int>(luaL_checkint(L, 1));
	bool __ret = SteamNetworking()->IsP2PPacketAvailable(&pcubMsgSize, nChannel);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pcubMsgSize);
	return 2;
}

// In C++:
// bool ReadP2PPacket(void * pubDest, uint32 cubDest, uint32 * pcubMsgSize, CSteamID * psteamIDRemote, int nChannel);
// In Lua:
// (bool, pubDest: str, pcubMsgSize: int, psteamIDRemote: uint64) Networking.ReadP2PPacket(cubDest: int, nChannel: int)
EXTERN int luasteam_Networking_ReadP2PPacket(lua_State *L) {
	uint32 cubDest = luaL_checkint(L, 1);
	uint32 pcubMsgSize = cubDest;
	std::vector<unsigned char> pubDest(cubDest);
	CSteamID psteamIDRemote;
	int nChannel = static_cast<int>(luaL_checkint(L, 2));
	bool __ret = SteamNetworking()->ReadP2PPacket(pubDest.data(), cubDest, &pcubMsgSize, &psteamIDRemote, nChannel);
	lua_pushboolean(L, __ret);
	lua_pushlstring(L, reinterpret_cast<const char*>(pubDest.data()), pcubMsgSize);
	lua_pushinteger(L, pcubMsgSize);
	luasteam::pushuint64(L, psteamIDRemote.ConvertToUint64());
	return 4;
}

// In C++:
// bool AcceptP2PSessionWithUser(CSteamID steamIDRemote);
// In Lua:
// bool Networking.AcceptP2PSessionWithUser(steamIDRemote: uint64)
EXTERN int luasteam_Networking_AcceptP2PSessionWithUser(lua_State *L) {
	CSteamID steamIDRemote(luasteam::checkuint64(L, 1));
	bool __ret = SteamNetworking()->AcceptP2PSessionWithUser(steamIDRemote);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool CloseP2PSessionWithUser(CSteamID steamIDRemote);
// In Lua:
// bool Networking.CloseP2PSessionWithUser(steamIDRemote: uint64)
EXTERN int luasteam_Networking_CloseP2PSessionWithUser(lua_State *L) {
	CSteamID steamIDRemote(luasteam::checkuint64(L, 1));
	bool __ret = SteamNetworking()->CloseP2PSessionWithUser(steamIDRemote);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool CloseP2PChannelWithUser(CSteamID steamIDRemote, int nChannel);
// In Lua:
// bool Networking.CloseP2PChannelWithUser(steamIDRemote: uint64, nChannel: int)
EXTERN int luasteam_Networking_CloseP2PChannelWithUser(lua_State *L) {
	CSteamID steamIDRemote(luasteam::checkuint64(L, 1));
	int nChannel = static_cast<int>(luaL_checkint(L, 2));
	bool __ret = SteamNetworking()->CloseP2PChannelWithUser(steamIDRemote, nChannel);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool GetP2PSessionState(CSteamID steamIDRemote, P2PSessionState_t * pConnectionState);
// In Lua:
// (bool, pConnectionState: P2PSessionState_t) Networking.GetP2PSessionState(steamIDRemote: uint64)
EXTERN int luasteam_Networking_GetP2PSessionState(lua_State *L) {
	CSteamID steamIDRemote(luasteam::checkuint64(L, 1));
	P2PSessionState_t pConnectionState;
	bool __ret = SteamNetworking()->GetP2PSessionState(steamIDRemote, &pConnectionState);
	lua_pushboolean(L, __ret);
	luasteam::push_P2PSessionState_t(L, pConnectionState);
	return 2;
}

// In C++:
// bool AllowP2PPacketRelay(bool bAllow);
// In Lua:
// bool Networking.AllowP2PPacketRelay(bAllow: bool)
EXTERN int luasteam_Networking_AllowP2PPacketRelay(lua_State *L) {
	bool bAllow = lua_toboolean(L, 1);
	bool __ret = SteamNetworking()->AllowP2PPacketRelay(bAllow);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// SNetListenSocket_t CreateListenSocket(int nVirtualP2PPort, SteamIPAddress_t nIP, uint16 nPort, bool bAllowUseOfPacketRelay);
// In Lua:
// int Networking.CreateListenSocket(nVirtualP2PPort: int, nIP: SteamIPAddress_t, nPort: int, bAllowUseOfPacketRelay: bool)
EXTERN int luasteam_Networking_CreateListenSocket(lua_State *L) {
	int nVirtualP2PPort = static_cast<int>(luaL_checkint(L, 1));
	SteamIPAddress_t nIP = luasteam::check_SteamIPAddress_t(L, 2);
	uint16 nPort = static_cast<uint16>(luaL_checkint(L, 3));
	bool bAllowUseOfPacketRelay = lua_toboolean(L, 4);
	SNetListenSocket_t __ret = SteamNetworking()->CreateListenSocket(nVirtualP2PPort, nIP, nPort, bAllowUseOfPacketRelay);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// SNetSocket_t CreateP2PConnectionSocket(CSteamID steamIDTarget, int nVirtualPort, int nTimeoutSec, bool bAllowUseOfPacketRelay);
// In Lua:
// int Networking.CreateP2PConnectionSocket(steamIDTarget: uint64, nVirtualPort: int, nTimeoutSec: int, bAllowUseOfPacketRelay: bool)
EXTERN int luasteam_Networking_CreateP2PConnectionSocket(lua_State *L) {
	CSteamID steamIDTarget(luasteam::checkuint64(L, 1));
	int nVirtualPort = static_cast<int>(luaL_checkint(L, 2));
	int nTimeoutSec = static_cast<int>(luaL_checkint(L, 3));
	bool bAllowUseOfPacketRelay = lua_toboolean(L, 4);
	SNetSocket_t __ret = SteamNetworking()->CreateP2PConnectionSocket(steamIDTarget, nVirtualPort, nTimeoutSec, bAllowUseOfPacketRelay);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// SNetSocket_t CreateConnectionSocket(SteamIPAddress_t nIP, uint16 nPort, int nTimeoutSec);
// In Lua:
// int Networking.CreateConnectionSocket(nIP: SteamIPAddress_t, nPort: int, nTimeoutSec: int)
EXTERN int luasteam_Networking_CreateConnectionSocket(lua_State *L) {
	SteamIPAddress_t nIP = luasteam::check_SteamIPAddress_t(L, 1);
	uint16 nPort = static_cast<uint16>(luaL_checkint(L, 2));
	int nTimeoutSec = static_cast<int>(luaL_checkint(L, 3));
	SNetSocket_t __ret = SteamNetworking()->CreateConnectionSocket(nIP, nPort, nTimeoutSec);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool DestroySocket(SNetSocket_t hSocket, bool bNotifyRemoteEnd);
// In Lua:
// bool Networking.DestroySocket(hSocket: int, bNotifyRemoteEnd: bool)
EXTERN int luasteam_Networking_DestroySocket(lua_State *L) {
	SNetSocket_t hSocket = static_cast<SNetSocket_t>(luaL_checkint(L, 1));
	bool bNotifyRemoteEnd = lua_toboolean(L, 2);
	bool __ret = SteamNetworking()->DestroySocket(hSocket, bNotifyRemoteEnd);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool DestroyListenSocket(SNetListenSocket_t hSocket, bool bNotifyRemoteEnd);
// In Lua:
// bool Networking.DestroyListenSocket(hSocket: int, bNotifyRemoteEnd: bool)
EXTERN int luasteam_Networking_DestroyListenSocket(lua_State *L) {
	SNetListenSocket_t hSocket = static_cast<SNetListenSocket_t>(luaL_checkint(L, 1));
	bool bNotifyRemoteEnd = lua_toboolean(L, 2);
	bool __ret = SteamNetworking()->DestroyListenSocket(hSocket, bNotifyRemoteEnd);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SendDataOnSocket(SNetSocket_t hSocket, const void * pubData, uint32 cubData, bool bReliable);
// In Lua:
// bool Networking.SendDataOnSocket(hSocket: int, pubData: str, cubData: int, bReliable: bool)
EXTERN int luasteam_Networking_SendDataOnSocket(lua_State *L) {
	SNetSocket_t hSocket = static_cast<SNetSocket_t>(luaL_checkint(L, 1));
	char *pubData = const_cast<char*>(luaL_checkstring(L, 2));
	uint32 cubData = static_cast<uint32>(luaL_checkint(L, 3));
	bool bReliable = lua_toboolean(L, 4);
	bool __ret = SteamNetworking()->SendDataOnSocket(hSocket, pubData, cubData, bReliable);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool IsDataAvailableOnSocket(SNetSocket_t hSocket, uint32 * pcubMsgSize);
// In Lua:
// (bool, pcubMsgSize: int) Networking.IsDataAvailableOnSocket(hSocket: int)
EXTERN int luasteam_Networking_IsDataAvailableOnSocket(lua_State *L) {
	SNetSocket_t hSocket = static_cast<SNetSocket_t>(luaL_checkint(L, 1));
	uint32 pcubMsgSize;
	bool __ret = SteamNetworking()->IsDataAvailableOnSocket(hSocket, &pcubMsgSize);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pcubMsgSize);
	return 2;
}

// In C++:
// bool RetrieveDataFromSocket(SNetSocket_t hSocket, void * pubDest, uint32 cubDest, uint32 * pcubMsgSize);
// In Lua:
// (bool, pubDest: str, pcubMsgSize: int) Networking.RetrieveDataFromSocket(hSocket: int, cubDest: int)
EXTERN int luasteam_Networking_RetrieveDataFromSocket(lua_State *L) {
	SNetSocket_t hSocket = static_cast<SNetSocket_t>(luaL_checkint(L, 1));
	uint32 cubDest = luaL_checkint(L, 2);
	uint32 pcubMsgSize = cubDest;
	std::vector<unsigned char> pubDest(cubDest);
	bool __ret = SteamNetworking()->RetrieveDataFromSocket(hSocket, pubDest.data(), cubDest, &pcubMsgSize);
	lua_pushboolean(L, __ret);
	lua_pushlstring(L, reinterpret_cast<const char*>(pubDest.data()), pcubMsgSize);
	lua_pushinteger(L, pcubMsgSize);
	return 3;
}

// In C++:
// bool IsDataAvailable(SNetListenSocket_t hListenSocket, uint32 * pcubMsgSize, SNetSocket_t * phSocket);
// In Lua:
// (bool, pcubMsgSize: int, phSocket: int) Networking.IsDataAvailable(hListenSocket: int)
EXTERN int luasteam_Networking_IsDataAvailable(lua_State *L) {
	SNetListenSocket_t hListenSocket = static_cast<SNetListenSocket_t>(luaL_checkint(L, 1));
	uint32 pcubMsgSize;
	SNetSocket_t phSocket;
	bool __ret = SteamNetworking()->IsDataAvailable(hListenSocket, &pcubMsgSize, &phSocket);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pcubMsgSize);
	lua_pushinteger(L, phSocket);
	return 3;
}

// In C++:
// bool RetrieveData(SNetListenSocket_t hListenSocket, void * pubDest, uint32 cubDest, uint32 * pcubMsgSize, SNetSocket_t * phSocket);
// In Lua:
// (bool, pubDest: str, pcubMsgSize: int, phSocket: int) Networking.RetrieveData(hListenSocket: int, cubDest: int)
EXTERN int luasteam_Networking_RetrieveData(lua_State *L) {
	SNetListenSocket_t hListenSocket = static_cast<SNetListenSocket_t>(luaL_checkint(L, 1));
	uint32 cubDest = luaL_checkint(L, 2);
	uint32 pcubMsgSize = cubDest;
	std::vector<unsigned char> pubDest(cubDest);
	SNetSocket_t phSocket;
	bool __ret = SteamNetworking()->RetrieveData(hListenSocket, pubDest.data(), cubDest, &pcubMsgSize, &phSocket);
	lua_pushboolean(L, __ret);
	lua_pushlstring(L, reinterpret_cast<const char*>(pubDest.data()), pcubMsgSize);
	lua_pushinteger(L, pcubMsgSize);
	lua_pushinteger(L, phSocket);
	return 4;
}

// In C++:
// bool GetSocketInfo(SNetSocket_t hSocket, CSteamID * pSteamIDRemote, int * peSocketStatus, SteamIPAddress_t * punIPRemote, uint16 * punPortRemote);
// In Lua:
// (bool, pSteamIDRemote: uint64, peSocketStatus: int, punIPRemote: SteamIPAddress_t, punPortRemote: int) Networking.GetSocketInfo(hSocket: int)
EXTERN int luasteam_Networking_GetSocketInfo(lua_State *L) {
	SNetSocket_t hSocket = static_cast<SNetSocket_t>(luaL_checkint(L, 1));
	CSteamID pSteamIDRemote;
	int peSocketStatus;
	SteamIPAddress_t punIPRemote;
	uint16 punPortRemote;
	bool __ret = SteamNetworking()->GetSocketInfo(hSocket, &pSteamIDRemote, &peSocketStatus, &punIPRemote, &punPortRemote);
	lua_pushboolean(L, __ret);
	luasteam::pushuint64(L, pSteamIDRemote.ConvertToUint64());
	lua_pushinteger(L, peSocketStatus);
	luasteam::push_SteamIPAddress_t(L, punIPRemote);
	lua_pushinteger(L, punPortRemote);
	return 5;
}

// In C++:
// bool GetListenSocketInfo(SNetListenSocket_t hListenSocket, SteamIPAddress_t * pnIP, uint16 * pnPort);
// In Lua:
// (bool, pnIP: SteamIPAddress_t, pnPort: int) Networking.GetListenSocketInfo(hListenSocket: int)
EXTERN int luasteam_Networking_GetListenSocketInfo(lua_State *L) {
	SNetListenSocket_t hListenSocket = static_cast<SNetListenSocket_t>(luaL_checkint(L, 1));
	SteamIPAddress_t pnIP;
	uint16 pnPort;
	bool __ret = SteamNetworking()->GetListenSocketInfo(hListenSocket, &pnIP, &pnPort);
	lua_pushboolean(L, __ret);
	luasteam::push_SteamIPAddress_t(L, pnIP);
	lua_pushinteger(L, pnPort);
	return 3;
}

// In C++:
// ESNetSocketConnectionType GetSocketConnectionType(SNetSocket_t hSocket);
// In Lua:
// int Networking.GetSocketConnectionType(hSocket: int)
EXTERN int luasteam_Networking_GetSocketConnectionType(lua_State *L) {
	SNetSocket_t hSocket = static_cast<SNetSocket_t>(luaL_checkint(L, 1));
	ESNetSocketConnectionType __ret = SteamNetworking()->GetSocketConnectionType(hSocket);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// int GetMaxPacketSize(SNetSocket_t hSocket);
// In Lua:
// int Networking.GetMaxPacketSize(hSocket: int)
EXTERN int luasteam_Networking_GetMaxPacketSize(lua_State *L) {
	SNetSocket_t hSocket = static_cast<SNetSocket_t>(luaL_checkint(L, 1));
	int __ret = SteamNetworking()->GetMaxPacketSize(hSocket);
	lua_pushinteger(L, __ret);
	return 1;
}

void register_Networking_auto(lua_State *L) {
	add_func(L, "SendP2PPacket", luasteam_Networking_SendP2PPacket);
	add_func(L, "IsP2PPacketAvailable", luasteam_Networking_IsP2PPacketAvailable);
	add_func(L, "ReadP2PPacket", luasteam_Networking_ReadP2PPacket);
	add_func(L, "AcceptP2PSessionWithUser", luasteam_Networking_AcceptP2PSessionWithUser);
	add_func(L, "CloseP2PSessionWithUser", luasteam_Networking_CloseP2PSessionWithUser);
	add_func(L, "CloseP2PChannelWithUser", luasteam_Networking_CloseP2PChannelWithUser);
	add_func(L, "GetP2PSessionState", luasteam_Networking_GetP2PSessionState);
	add_func(L, "AllowP2PPacketRelay", luasteam_Networking_AllowP2PPacketRelay);
	add_func(L, "CreateListenSocket", luasteam_Networking_CreateListenSocket);
	add_func(L, "CreateP2PConnectionSocket", luasteam_Networking_CreateP2PConnectionSocket);
	add_func(L, "CreateConnectionSocket", luasteam_Networking_CreateConnectionSocket);
	add_func(L, "DestroySocket", luasteam_Networking_DestroySocket);
	add_func(L, "DestroyListenSocket", luasteam_Networking_DestroyListenSocket);
	add_func(L, "SendDataOnSocket", luasteam_Networking_SendDataOnSocket);
	add_func(L, "IsDataAvailableOnSocket", luasteam_Networking_IsDataAvailableOnSocket);
	add_func(L, "RetrieveDataFromSocket", luasteam_Networking_RetrieveDataFromSocket);
	add_func(L, "IsDataAvailable", luasteam_Networking_IsDataAvailable);
	add_func(L, "RetrieveData", luasteam_Networking_RetrieveData);
	add_func(L, "GetSocketInfo", luasteam_Networking_GetSocketInfo);
	add_func(L, "GetListenSocketInfo", luasteam_Networking_GetListenSocketInfo);
	add_func(L, "GetSocketConnectionType", luasteam_Networking_GetSocketConnectionType);
	add_func(L, "GetMaxPacketSize", luasteam_Networking_GetMaxPacketSize);
}

void add_Networking_auto(lua_State *L) {
	lua_createtable(L, 0, 22);
	register_Networking_auto(L);
	lua_pushvalue(L, -1);
	Networking_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "Networking");
}

} // namespace luasteam
