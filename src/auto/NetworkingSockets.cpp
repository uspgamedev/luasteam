#include "auto.hpp"

namespace luasteam {

int NetworkingSockets_ref = LUA_NOREF;

namespace {
class NetworkingSocketsCallbackListener {
private:
	STEAM_CALLBACK(NetworkingSocketsCallbackListener, OnSteamNetConnectionStatusChangedCallback, SteamNetConnectionStatusChangedCallback_t);
	STEAM_CALLBACK(NetworkingSocketsCallbackListener, OnSteamNetAuthenticationStatus, SteamNetAuthenticationStatus_t);
	STEAM_CALLBACK(NetworkingSocketsCallbackListener, OnSteamNetworkingFakeIPResult, SteamNetworkingFakeIPResult_t);
};
void NetworkingSocketsCallbackListener::OnSteamNetConnectionStatusChangedCallback(SteamNetConnectionStatusChangedCallback_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::NetworkingSockets_ref);
	lua_getfield(L, -1, "OnSteamNetConnectionStatusChangedCallback");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamNetConnectionStatusChangedCallback_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void NetworkingSocketsCallbackListener::OnSteamNetAuthenticationStatus(SteamNetAuthenticationStatus_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::NetworkingSockets_ref);
	lua_getfield(L, -1, "OnSteamNetAuthenticationStatus");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamNetAuthenticationStatus_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void NetworkingSocketsCallbackListener::OnSteamNetworkingFakeIPResult(SteamNetworkingFakeIPResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::NetworkingSockets_ref);
	lua_getfield(L, -1, "OnSteamNetworkingFakeIPResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamNetworkingFakeIPResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
NetworkingSocketsCallbackListener *NetworkingSockets_listener = nullptr;
} // namespace

void init_NetworkingSockets_auto(lua_State *L) { NetworkingSockets_listener = new NetworkingSocketsCallbackListener(); }
void shutdown_NetworkingSockets_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, NetworkingSockets_ref);
	NetworkingSockets_ref = LUA_NOREF;
	delete NetworkingSockets_listener; NetworkingSockets_listener = nullptr;
}

// In C++:
// HSteamListenSocket CreateListenSocketIP(const SteamNetworkingIPAddr & localAddress, int nOptions, const SteamNetworkingConfigValue_t * pOptions);
// In Lua:
// int NetworkingSockets.CreateListenSocketIP(localAddress: SteamNetworkingIPAddr, nOptions: int, pOptions: SteamNetworkingConfigValue_t)
static int luasteam_NetworkingSockets_CreateListenSocketIP(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	const SteamNetworkingIPAddr &localAddress = *luasteam::check_SteamNetworkingIPAddr_ptr(L, 1);
	int nOptions = static_cast<int>(luaL_checkint(L, 2));
	const SteamNetworkingConfigValue_t *pOptions = lua_isnil(L, 3) ? nullptr : luasteam::check_SteamNetworkingConfigValue_t_ptr(L, 3);
	HSteamListenSocket __ret = iface->CreateListenSocketIP(localAddress, nOptions, pOptions);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// HSteamNetConnection ConnectByIPAddress(const SteamNetworkingIPAddr & address, int nOptions, const SteamNetworkingConfigValue_t * pOptions);
// In Lua:
// int NetworkingSockets.ConnectByIPAddress(address: SteamNetworkingIPAddr, nOptions: int, pOptions: SteamNetworkingConfigValue_t)
static int luasteam_NetworkingSockets_ConnectByIPAddress(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	const SteamNetworkingIPAddr &address = *luasteam::check_SteamNetworkingIPAddr_ptr(L, 1);
	int nOptions = static_cast<int>(luaL_checkint(L, 2));
	const SteamNetworkingConfigValue_t *pOptions = lua_isnil(L, 3) ? nullptr : luasteam::check_SteamNetworkingConfigValue_t_ptr(L, 3);
	HSteamNetConnection __ret = iface->ConnectByIPAddress(address, nOptions, pOptions);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// HSteamListenSocket CreateListenSocketP2P(int nLocalVirtualPort, int nOptions, const SteamNetworkingConfigValue_t * pOptions);
// In Lua:
// int NetworkingSockets.CreateListenSocketP2P(nLocalVirtualPort: int, nOptions: int, pOptions: SteamNetworkingConfigValue_t)
static int luasteam_NetworkingSockets_CreateListenSocketP2P(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	int nLocalVirtualPort = static_cast<int>(luaL_checkint(L, 1));
	int nOptions = static_cast<int>(luaL_checkint(L, 2));
	const SteamNetworkingConfigValue_t *pOptions = lua_isnil(L, 3) ? nullptr : luasteam::check_SteamNetworkingConfigValue_t_ptr(L, 3);
	HSteamListenSocket __ret = iface->CreateListenSocketP2P(nLocalVirtualPort, nOptions, pOptions);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// HSteamNetConnection ConnectP2P(const SteamNetworkingIdentity & identityRemote, int nRemoteVirtualPort, int nOptions, const SteamNetworkingConfigValue_t * pOptions);
// In Lua:
// int NetworkingSockets.ConnectP2P(identityRemote: SteamNetworkingIdentity, nRemoteVirtualPort: int, nOptions: int, pOptions: SteamNetworkingConfigValue_t)
static int luasteam_NetworkingSockets_ConnectP2P(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	const SteamNetworkingIdentity &identityRemote = *luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	int nRemoteVirtualPort = static_cast<int>(luaL_checkint(L, 2));
	int nOptions = static_cast<int>(luaL_checkint(L, 3));
	const SteamNetworkingConfigValue_t *pOptions = lua_isnil(L, 4) ? nullptr : luasteam::check_SteamNetworkingConfigValue_t_ptr(L, 4);
	HSteamNetConnection __ret = iface->ConnectP2P(identityRemote, nRemoteVirtualPort, nOptions, pOptions);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// EResult AcceptConnection(HSteamNetConnection hConn);
// In Lua:
// int NetworkingSockets.AcceptConnection(hConn: int)
static int luasteam_NetworkingSockets_AcceptConnection(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	HSteamNetConnection hConn = static_cast<HSteamNetConnection>(luaL_checkint(L, 1));
	EResult __ret = iface->AcceptConnection(hConn);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool CloseConnection(HSteamNetConnection hPeer, int nReason, const char * pszDebug, bool bEnableLinger);
// In Lua:
// bool NetworkingSockets.CloseConnection(hPeer: int, nReason: int, pszDebug: str, bEnableLinger: bool)
static int luasteam_NetworkingSockets_CloseConnection(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	HSteamNetConnection hPeer = static_cast<HSteamNetConnection>(luaL_checkint(L, 1));
	int nReason = static_cast<int>(luaL_checkint(L, 2));
	const char *pszDebug = luaL_checkstring(L, 3);
	bool bEnableLinger = lua_toboolean(L, 4);
	bool __ret = iface->CloseConnection(hPeer, nReason, pszDebug, bEnableLinger);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool CloseListenSocket(HSteamListenSocket hSocket);
// In Lua:
// bool NetworkingSockets.CloseListenSocket(hSocket: int)
static int luasteam_NetworkingSockets_CloseListenSocket(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	HSteamListenSocket hSocket = static_cast<HSteamListenSocket>(luaL_checkint(L, 1));
	bool __ret = iface->CloseListenSocket(hSocket);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetConnectionUserData(HSteamNetConnection hPeer, int64 nUserData);
// In Lua:
// bool NetworkingSockets.SetConnectionUserData(hPeer: int, nUserData: uint64)
static int luasteam_NetworkingSockets_SetConnectionUserData(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	HSteamNetConnection hPeer = static_cast<HSteamNetConnection>(luaL_checkint(L, 1));
	int64 nUserData(luasteam::checkuint64(L, 2));
	bool __ret = iface->SetConnectionUserData(hPeer, nUserData);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// int64 GetConnectionUserData(HSteamNetConnection hPeer);
// In Lua:
// uint64 NetworkingSockets.GetConnectionUserData(hPeer: int)
static int luasteam_NetworkingSockets_GetConnectionUserData(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	HSteamNetConnection hPeer = static_cast<HSteamNetConnection>(luaL_checkint(L, 1));
	int64 __ret = iface->GetConnectionUserData(hPeer);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// void SetConnectionName(HSteamNetConnection hPeer, const char * pszName);
// In Lua:
// NetworkingSockets.SetConnectionName(hPeer: int, pszName: str)
static int luasteam_NetworkingSockets_SetConnectionName(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	HSteamNetConnection hPeer = static_cast<HSteamNetConnection>(luaL_checkint(L, 1));
	const char *pszName = luaL_checkstring(L, 2);
	iface->SetConnectionName(hPeer, pszName);
	return 0;
}

// In C++:
// bool GetConnectionName(HSteamNetConnection hPeer, char * pszName, int nMaxLen);
// In Lua:
// (bool, pszName: str) NetworkingSockets.GetConnectionName(hPeer: int, nMaxLen: int)
static int luasteam_NetworkingSockets_GetConnectionName(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	HSteamNetConnection hPeer = static_cast<HSteamNetConnection>(luaL_checkint(L, 1));
	int nMaxLen = luaL_checkint(L, 2);
	std::vector<char> pszName(nMaxLen);
	bool __ret = iface->GetConnectionName(hPeer, pszName.data(), nMaxLen);
	lua_pushboolean(L, __ret);
	lua_pushstring(L, reinterpret_cast<const char*>(pszName.data()));
	return 2;
}

// In C++:
// EResult SendMessageToConnection(HSteamNetConnection hConn, const void * pData, uint32 cbData, int nSendFlags, int64 * pOutMessageNumber);
// In Lua:
// (int, pOutMessageNumber: uint64) NetworkingSockets.SendMessageToConnection(hConn: int, pData: str, cbData: int, nSendFlags: int)
static int luasteam_NetworkingSockets_SendMessageToConnection(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	HSteamNetConnection hConn = static_cast<HSteamNetConnection>(luaL_checkint(L, 1));
	const char *pData = luaL_checkstring(L, 2);
	uint32 cbData = static_cast<uint32>(luaL_checkint(L, 3));
	int nSendFlags = static_cast<int>(luaL_checkint(L, 4));
	int64 pOutMessageNumber;
	EResult __ret = iface->SendMessageToConnection(hConn, pData, cbData, nSendFlags, &pOutMessageNumber);
	lua_pushinteger(L, __ret);
	luasteam::pushuint64(L, pOutMessageNumber);
	return 2;
}

// In C++:
// EResult FlushMessagesOnConnection(HSteamNetConnection hConn);
// In Lua:
// int NetworkingSockets.FlushMessagesOnConnection(hConn: int)
static int luasteam_NetworkingSockets_FlushMessagesOnConnection(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	HSteamNetConnection hConn = static_cast<HSteamNetConnection>(luaL_checkint(L, 1));
	EResult __ret = iface->FlushMessagesOnConnection(hConn);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool GetConnectionInfo(HSteamNetConnection hConn, SteamNetConnectionInfo_t * pInfo);
// In Lua:
// (bool, pInfo: SteamNetConnectionInfo_t) NetworkingSockets.GetConnectionInfo(hConn: int)
static int luasteam_NetworkingSockets_GetConnectionInfo(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	HSteamNetConnection hConn = static_cast<HSteamNetConnection>(luaL_checkint(L, 1));
	SteamNetConnectionInfo_t pInfo;
	bool __ret = iface->GetConnectionInfo(hConn, &pInfo);
	lua_pushboolean(L, __ret);
	luasteam::push_SteamNetConnectionInfo_t(L, pInfo);
	return 2;
}

// In C++:
// EResult GetConnectionRealTimeStatus(HSteamNetConnection hConn, SteamNetConnectionRealTimeStatus_t * pStatus, int nLanes, SteamNetConnectionRealTimeLaneStatus_t * pLanes);
// In Lua:
// (int, pStatus: SteamNetConnectionRealTimeStatus_t, pLanes: SteamNetConnectionRealTimeLaneStatus_t) NetworkingSockets.GetConnectionRealTimeStatus(hConn: int, nLanes: int)
static int luasteam_NetworkingSockets_GetConnectionRealTimeStatus(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	HSteamNetConnection hConn = static_cast<HSteamNetConnection>(luaL_checkint(L, 1));
	SteamNetConnectionRealTimeStatus_t pStatus;
	int nLanes = static_cast<int>(luaL_checkint(L, 2));
	SteamNetConnectionRealTimeLaneStatus_t pLanes;
	EResult __ret = iface->GetConnectionRealTimeStatus(hConn, &pStatus, nLanes, &pLanes);
	lua_pushinteger(L, __ret);
	luasteam::push_SteamNetConnectionRealTimeStatus_t(L, pStatus);
	luasteam::push_SteamNetConnectionRealTimeLaneStatus_t(L, pLanes);
	return 3;
}

// In C++:
// int GetDetailedConnectionStatus(HSteamNetConnection hConn, char * pszBuf, int cbBuf);
// In Lua:
// (int, pszBuf: str) NetworkingSockets.GetDetailedConnectionStatus(hConn: int, cbBuf: int)
static int luasteam_NetworkingSockets_GetDetailedConnectionStatus(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	HSteamNetConnection hConn = static_cast<HSteamNetConnection>(luaL_checkint(L, 1));
	int cbBuf = luaL_checkint(L, 2);
	std::vector<char> pszBuf(cbBuf);
	int __ret = iface->GetDetailedConnectionStatus(hConn, pszBuf.data(), cbBuf);
	lua_pushinteger(L, __ret);
	lua_pushstring(L, reinterpret_cast<const char*>(pszBuf.data()));
	return 2;
}

// In C++:
// bool GetListenSocketAddress(HSteamListenSocket hSocket, SteamNetworkingIPAddr * address);
// In Lua:
// (bool, address: SteamNetworkingIPAddr) NetworkingSockets.GetListenSocketAddress(hSocket: int)
static int luasteam_NetworkingSockets_GetListenSocketAddress(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	HSteamListenSocket hSocket = static_cast<HSteamListenSocket>(luaL_checkint(L, 1));
	SteamNetworkingIPAddr address;
	bool __ret = iface->GetListenSocketAddress(hSocket, &address);
	lua_pushboolean(L, __ret);
	luasteam::push_SteamNetworkingIPAddr(L, address);
	return 2;
}

// In C++:
// bool CreateSocketPair(HSteamNetConnection * pOutConnection1, HSteamNetConnection * pOutConnection2, bool bUseNetworkLoopback, const SteamNetworkingIdentity * pIdentity1, const SteamNetworkingIdentity * pIdentity2);
// In Lua:
// (bool, pOutConnection1: int, pOutConnection2: int) NetworkingSockets.CreateSocketPair(bUseNetworkLoopback: bool, pIdentity1: SteamNetworkingIdentity, pIdentity2: SteamNetworkingIdentity)
static int luasteam_NetworkingSockets_CreateSocketPair(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	HSteamNetConnection pOutConnection1;
	HSteamNetConnection pOutConnection2;
	bool bUseNetworkLoopback = lua_toboolean(L, 1);
	const SteamNetworkingIdentity *pIdentity1 = lua_isnil(L, 2) ? nullptr : luasteam::check_SteamNetworkingIdentity_ptr(L, 2);
	const SteamNetworkingIdentity *pIdentity2 = lua_isnil(L, 3) ? nullptr : luasteam::check_SteamNetworkingIdentity_ptr(L, 3);
	bool __ret = iface->CreateSocketPair(&pOutConnection1, &pOutConnection2, bUseNetworkLoopback, pIdentity1, pIdentity2);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pOutConnection1);
	lua_pushinteger(L, pOutConnection2);
	return 3;
}

// In C++:
// bool GetIdentity(SteamNetworkingIdentity * pIdentity);
// In Lua:
// (bool, pIdentity: SteamNetworkingIdentity) NetworkingSockets.GetIdentity()
static int luasteam_NetworkingSockets_GetIdentity(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	SteamNetworkingIdentity pIdentity;
	bool __ret = iface->GetIdentity(&pIdentity);
	lua_pushboolean(L, __ret);
	luasteam::push_SteamNetworkingIdentity(L, pIdentity);
	return 2;
}

// In C++:
// ESteamNetworkingAvailability InitAuthentication();
// In Lua:
// int NetworkingSockets.InitAuthentication()
static int luasteam_NetworkingSockets_InitAuthentication(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	ESteamNetworkingAvailability __ret = iface->InitAuthentication();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// ESteamNetworkingAvailability GetAuthenticationStatus(SteamNetAuthenticationStatus_t * pDetails);
// In Lua:
// (int, pDetails: SteamNetAuthenticationStatus_t) NetworkingSockets.GetAuthenticationStatus()
static int luasteam_NetworkingSockets_GetAuthenticationStatus(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	SteamNetAuthenticationStatus_t pDetails;
	ESteamNetworkingAvailability __ret = iface->GetAuthenticationStatus(&pDetails);
	lua_pushinteger(L, __ret);
	luasteam::push_SteamNetAuthenticationStatus_t(L, pDetails);
	return 2;
}

// In C++:
// HSteamNetPollGroup CreatePollGroup();
// In Lua:
// int NetworkingSockets.CreatePollGroup()
static int luasteam_NetworkingSockets_CreatePollGroup(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	HSteamNetPollGroup __ret = iface->CreatePollGroup();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool DestroyPollGroup(HSteamNetPollGroup hPollGroup);
// In Lua:
// bool NetworkingSockets.DestroyPollGroup(hPollGroup: int)
static int luasteam_NetworkingSockets_DestroyPollGroup(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	HSteamNetPollGroup hPollGroup = static_cast<HSteamNetPollGroup>(luaL_checkint(L, 1));
	bool __ret = iface->DestroyPollGroup(hPollGroup);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetConnectionPollGroup(HSteamNetConnection hConn, HSteamNetPollGroup hPollGroup);
// In Lua:
// bool NetworkingSockets.SetConnectionPollGroup(hConn: int, hPollGroup: int)
static int luasteam_NetworkingSockets_SetConnectionPollGroup(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	HSteamNetConnection hConn = static_cast<HSteamNetConnection>(luaL_checkint(L, 1));
	HSteamNetPollGroup hPollGroup = static_cast<HSteamNetPollGroup>(luaL_checkint(L, 2));
	bool __ret = iface->SetConnectionPollGroup(hConn, hPollGroup);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// HSteamNetConnection ConnectToHostedDedicatedServer(const SteamNetworkingIdentity & identityTarget, int nRemoteVirtualPort, int nOptions, const SteamNetworkingConfigValue_t * pOptions);
// In Lua:
// int NetworkingSockets.ConnectToHostedDedicatedServer(identityTarget: SteamNetworkingIdentity, nRemoteVirtualPort: int, nOptions: int, pOptions: SteamNetworkingConfigValue_t)
static int luasteam_NetworkingSockets_ConnectToHostedDedicatedServer(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	const SteamNetworkingIdentity &identityTarget = *luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	int nRemoteVirtualPort = static_cast<int>(luaL_checkint(L, 2));
	int nOptions = static_cast<int>(luaL_checkint(L, 3));
	const SteamNetworkingConfigValue_t *pOptions = lua_isnil(L, 4) ? nullptr : luasteam::check_SteamNetworkingConfigValue_t_ptr(L, 4);
	HSteamNetConnection __ret = iface->ConnectToHostedDedicatedServer(identityTarget, nRemoteVirtualPort, nOptions, pOptions);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// uint16 GetHostedDedicatedServerPort();
// In Lua:
// int NetworkingSockets.GetHostedDedicatedServerPort()
static int luasteam_NetworkingSockets_GetHostedDedicatedServerPort(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	uint16 __ret = iface->GetHostedDedicatedServerPort();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// SteamNetworkingPOPID GetHostedDedicatedServerPOPID();
// In Lua:
// int NetworkingSockets.GetHostedDedicatedServerPOPID()
static int luasteam_NetworkingSockets_GetHostedDedicatedServerPOPID(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	SteamNetworkingPOPID __ret = iface->GetHostedDedicatedServerPOPID();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// HSteamListenSocket CreateHostedDedicatedServerListenSocket(int nLocalVirtualPort, int nOptions, const SteamNetworkingConfigValue_t * pOptions);
// In Lua:
// int NetworkingSockets.CreateHostedDedicatedServerListenSocket(nLocalVirtualPort: int, nOptions: int, pOptions: SteamNetworkingConfigValue_t)
static int luasteam_NetworkingSockets_CreateHostedDedicatedServerListenSocket(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	int nLocalVirtualPort = static_cast<int>(luaL_checkint(L, 1));
	int nOptions = static_cast<int>(luaL_checkint(L, 2));
	const SteamNetworkingConfigValue_t *pOptions = lua_isnil(L, 3) ? nullptr : luasteam::check_SteamNetworkingConfigValue_t_ptr(L, 3);
	HSteamListenSocket __ret = iface->CreateHostedDedicatedServerListenSocket(nLocalVirtualPort, nOptions, pOptions);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// void ResetIdentity(const SteamNetworkingIdentity * pIdentity);
// In Lua:
// NetworkingSockets.ResetIdentity(pIdentity: SteamNetworkingIdentity)
static int luasteam_NetworkingSockets_ResetIdentity(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	const SteamNetworkingIdentity *pIdentity = lua_isnil(L, 1) ? nullptr : luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	iface->ResetIdentity(pIdentity);
	return 0;
}

// In C++:
// void RunCallbacks();
// In Lua:
// NetworkingSockets.RunCallbacks()
static int luasteam_NetworkingSockets_RunCallbacks(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	iface->RunCallbacks();
	return 0;
}

// In C++:
// bool BeginAsyncRequestFakeIP(int nNumPorts);
// In Lua:
// bool NetworkingSockets.BeginAsyncRequestFakeIP(nNumPorts: int)
static int luasteam_NetworkingSockets_BeginAsyncRequestFakeIP(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	int nNumPorts = static_cast<int>(luaL_checkint(L, 1));
	bool __ret = iface->BeginAsyncRequestFakeIP(nNumPorts);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// void GetFakeIP(int idxFirstPort, SteamNetworkingFakeIPResult_t * pInfo);
// In Lua:
// pInfo: SteamNetworkingFakeIPResult_t NetworkingSockets.GetFakeIP(idxFirstPort: int)
static int luasteam_NetworkingSockets_GetFakeIP(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	int idxFirstPort = static_cast<int>(luaL_checkint(L, 1));
	SteamNetworkingFakeIPResult_t pInfo;
	iface->GetFakeIP(idxFirstPort, &pInfo);
	luasteam::push_SteamNetworkingFakeIPResult_t(L, pInfo);
	return 1;
}

// In C++:
// HSteamListenSocket CreateListenSocketP2PFakeIP(int idxFakePort, int nOptions, const SteamNetworkingConfigValue_t * pOptions);
// In Lua:
// int NetworkingSockets.CreateListenSocketP2PFakeIP(idxFakePort: int, nOptions: int, pOptions: SteamNetworkingConfigValue_t)
static int luasteam_NetworkingSockets_CreateListenSocketP2PFakeIP(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	int idxFakePort = static_cast<int>(luaL_checkint(L, 1));
	int nOptions = static_cast<int>(luaL_checkint(L, 2));
	const SteamNetworkingConfigValue_t *pOptions = lua_isnil(L, 3) ? nullptr : luasteam::check_SteamNetworkingConfigValue_t_ptr(L, 3);
	HSteamListenSocket __ret = iface->CreateListenSocketP2PFakeIP(idxFakePort, nOptions, pOptions);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// EResult GetRemoteFakeIPForConnection(HSteamNetConnection hConn, SteamNetworkingIPAddr * pOutAddr);
// In Lua:
// (int, pOutAddr: SteamNetworkingIPAddr) NetworkingSockets.GetRemoteFakeIPForConnection(hConn: int)
static int luasteam_NetworkingSockets_GetRemoteFakeIPForConnection(lua_State *L) {
	auto *iface = SteamNetworkingSockets_SteamAPI();
	HSteamNetConnection hConn = static_cast<HSteamNetConnection>(luaL_checkint(L, 1));
	SteamNetworkingIPAddr pOutAddr;
	EResult __ret = iface->GetRemoteFakeIPForConnection(hConn, &pOutAddr);
	lua_pushinteger(L, __ret);
	luasteam::push_SteamNetworkingIPAddr(L, pOutAddr);
	return 2;
}

void register_NetworkingSockets_auto(lua_State *L) {
	add_func(L, "CreateListenSocketIP", luasteam_NetworkingSockets_CreateListenSocketIP);
	add_func(L, "ConnectByIPAddress", luasteam_NetworkingSockets_ConnectByIPAddress);
	add_func(L, "CreateListenSocketP2P", luasteam_NetworkingSockets_CreateListenSocketP2P);
	add_func(L, "ConnectP2P", luasteam_NetworkingSockets_ConnectP2P);
	add_func(L, "AcceptConnection", luasteam_NetworkingSockets_AcceptConnection);
	add_func(L, "CloseConnection", luasteam_NetworkingSockets_CloseConnection);
	add_func(L, "CloseListenSocket", luasteam_NetworkingSockets_CloseListenSocket);
	add_func(L, "SetConnectionUserData", luasteam_NetworkingSockets_SetConnectionUserData);
	add_func(L, "GetConnectionUserData", luasteam_NetworkingSockets_GetConnectionUserData);
	add_func(L, "SetConnectionName", luasteam_NetworkingSockets_SetConnectionName);
	add_func(L, "GetConnectionName", luasteam_NetworkingSockets_GetConnectionName);
	add_func(L, "SendMessageToConnection", luasteam_NetworkingSockets_SendMessageToConnection);
	add_func(L, "FlushMessagesOnConnection", luasteam_NetworkingSockets_FlushMessagesOnConnection);
	add_func(L, "GetConnectionInfo", luasteam_NetworkingSockets_GetConnectionInfo);
	add_func(L, "GetConnectionRealTimeStatus", luasteam_NetworkingSockets_GetConnectionRealTimeStatus);
	add_func(L, "GetDetailedConnectionStatus", luasteam_NetworkingSockets_GetDetailedConnectionStatus);
	add_func(L, "GetListenSocketAddress", luasteam_NetworkingSockets_GetListenSocketAddress);
	add_func(L, "CreateSocketPair", luasteam_NetworkingSockets_CreateSocketPair);
	add_func(L, "GetIdentity", luasteam_NetworkingSockets_GetIdentity);
	add_func(L, "InitAuthentication", luasteam_NetworkingSockets_InitAuthentication);
	add_func(L, "GetAuthenticationStatus", luasteam_NetworkingSockets_GetAuthenticationStatus);
	add_func(L, "CreatePollGroup", luasteam_NetworkingSockets_CreatePollGroup);
	add_func(L, "DestroyPollGroup", luasteam_NetworkingSockets_DestroyPollGroup);
	add_func(L, "SetConnectionPollGroup", luasteam_NetworkingSockets_SetConnectionPollGroup);
	add_func(L, "ConnectToHostedDedicatedServer", luasteam_NetworkingSockets_ConnectToHostedDedicatedServer);
	add_func(L, "GetHostedDedicatedServerPort", luasteam_NetworkingSockets_GetHostedDedicatedServerPort);
	add_func(L, "GetHostedDedicatedServerPOPID", luasteam_NetworkingSockets_GetHostedDedicatedServerPOPID);
	add_func(L, "CreateHostedDedicatedServerListenSocket", luasteam_NetworkingSockets_CreateHostedDedicatedServerListenSocket);
	add_func(L, "ResetIdentity", luasteam_NetworkingSockets_ResetIdentity);
	add_func(L, "RunCallbacks", luasteam_NetworkingSockets_RunCallbacks);
	add_func(L, "BeginAsyncRequestFakeIP", luasteam_NetworkingSockets_BeginAsyncRequestFakeIP);
	add_func(L, "GetFakeIP", luasteam_NetworkingSockets_GetFakeIP);
	add_func(L, "CreateListenSocketP2PFakeIP", luasteam_NetworkingSockets_CreateListenSocketP2PFakeIP);
	add_func(L, "GetRemoteFakeIPForConnection", luasteam_NetworkingSockets_GetRemoteFakeIPForConnection);
}

void add_NetworkingSockets_auto(lua_State *L) {
	lua_createtable(L, 0, 34);
	register_NetworkingSockets_auto(L);
	lua_pushvalue(L, -1);
	NetworkingSockets_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "NetworkingSockets");
}

} // namespace luasteam
