#include "auto.hpp"

namespace luasteam {

int NetworkingUtils_ref = LUA_NOREF;

namespace {
class NetworkingUtilsCallbackListener {
private:
	STEAM_CALLBACK(NetworkingUtilsCallbackListener, OnSteamRelayNetworkStatus, SteamRelayNetworkStatus_t);
};
void NetworkingUtilsCallbackListener::OnSteamRelayNetworkStatus(SteamRelayNetworkStatus_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::NetworkingUtils_ref);
	lua_getfield(L, -1, "OnSteamRelayNetworkStatus");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamRelayNetworkStatus_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
NetworkingUtilsCallbackListener *NetworkingUtils_listener = nullptr;
} // namespace

void init_NetworkingUtils_auto(lua_State *L) { if (NetworkingUtils_listener != nullptr) return; NetworkingUtils_listener = new NetworkingUtilsCallbackListener(); }
void shutdown_NetworkingUtils_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, NetworkingUtils_ref);
	NetworkingUtils_ref = LUA_NOREF;
	delete NetworkingUtils_listener; NetworkingUtils_listener = nullptr;
}

// In C++:
// void InitRelayNetworkAccess();
// In Lua:
// NetworkingUtils.InitRelayNetworkAccess()
static int luasteam_NetworkingUtils_InitRelayNetworkAccess(lua_State *L) {
	auto *iface = SteamNetworkingUtils_SteamAPI();
	iface->InitRelayNetworkAccess();
	return 0;
}

// In C++:
// ESteamNetworkingAvailability GetRelayNetworkStatus(SteamRelayNetworkStatus_t * pDetails);
// In Lua:
// (int, pDetails: SteamRelayNetworkStatus_t) NetworkingUtils.GetRelayNetworkStatus()
static int luasteam_NetworkingUtils_GetRelayNetworkStatus(lua_State *L) {
	auto *iface = SteamNetworkingUtils_SteamAPI();
	SteamRelayNetworkStatus_t pDetails;
	ESteamNetworkingAvailability __ret = iface->GetRelayNetworkStatus(&pDetails);
	lua_pushinteger(L, __ret);
	luasteam::push_SteamRelayNetworkStatus_t(L, pDetails);
	return 2;
}

// In C++:
// int EstimatePingTimeBetweenTwoLocations(const SteamNetworkPingLocation_t & location1, const SteamNetworkPingLocation_t & location2);
// In Lua:
// int NetworkingUtils.EstimatePingTimeBetweenTwoLocations(location1: SteamNetworkPingLocation_t, location2: SteamNetworkPingLocation_t)
static int luasteam_NetworkingUtils_EstimatePingTimeBetweenTwoLocations(lua_State *L) {
	auto *iface = SteamNetworkingUtils_SteamAPI();
	const SteamNetworkPingLocation_t &location1 = *luasteam::check_SteamNetworkPingLocation_t_ptr(L, 1);
	const SteamNetworkPingLocation_t &location2 = *luasteam::check_SteamNetworkPingLocation_t_ptr(L, 2);
	int __ret = iface->EstimatePingTimeBetweenTwoLocations(location1, location2);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// int EstimatePingTimeFromLocalHost(const SteamNetworkPingLocation_t & remoteLocation);
// In Lua:
// int NetworkingUtils.EstimatePingTimeFromLocalHost(remoteLocation: SteamNetworkPingLocation_t)
static int luasteam_NetworkingUtils_EstimatePingTimeFromLocalHost(lua_State *L) {
	auto *iface = SteamNetworkingUtils_SteamAPI();
	const SteamNetworkPingLocation_t &remoteLocation = *luasteam::check_SteamNetworkPingLocation_t_ptr(L, 1);
	int __ret = iface->EstimatePingTimeFromLocalHost(remoteLocation);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// void ConvertPingLocationToString(const SteamNetworkPingLocation_t & location, char * pszBuf, int cchBufSize);
// In Lua:
// pszBuf: str NetworkingUtils.ConvertPingLocationToString(location: SteamNetworkPingLocation_t, cchBufSize: int)
static int luasteam_NetworkingUtils_ConvertPingLocationToString(lua_State *L) {
	auto *iface = SteamNetworkingUtils_SteamAPI();
	const SteamNetworkPingLocation_t &location = *luasteam::check_SteamNetworkPingLocation_t_ptr(L, 1);
	int cchBufSize = luaL_checkint(L, 2);
	std::vector<char> pszBuf(cchBufSize);
	iface->ConvertPingLocationToString(location, pszBuf.data(), cchBufSize);
	lua_pushstring(L, reinterpret_cast<const char*>(pszBuf.data()));
	return 1;
}

// In C++:
// bool CheckPingDataUpToDate(float flMaxAgeSeconds);
// In Lua:
// bool NetworkingUtils.CheckPingDataUpToDate(flMaxAgeSeconds: float)
static int luasteam_NetworkingUtils_CheckPingDataUpToDate(lua_State *L) {
	auto *iface = SteamNetworkingUtils_SteamAPI();
	float flMaxAgeSeconds = static_cast<float>(luaL_checknumber(L, 1));
	bool __ret = iface->CheckPingDataUpToDate(flMaxAgeSeconds);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// int GetPingToDataCenter(SteamNetworkingPOPID popID, SteamNetworkingPOPID * pViaRelayPoP);
// In Lua:
// (int, pViaRelayPoP: int) NetworkingUtils.GetPingToDataCenter(popID: int)
static int luasteam_NetworkingUtils_GetPingToDataCenter(lua_State *L) {
	auto *iface = SteamNetworkingUtils_SteamAPI();
	SteamNetworkingPOPID popID = static_cast<SteamNetworkingPOPID>(luaL_checkint(L, 1));
	SteamNetworkingPOPID pViaRelayPoP;
	int __ret = iface->GetPingToDataCenter(popID, &pViaRelayPoP);
	lua_pushinteger(L, __ret);
	lua_pushinteger(L, pViaRelayPoP);
	return 2;
}

// In C++:
// int GetDirectPingToPOP(SteamNetworkingPOPID popID);
// In Lua:
// int NetworkingUtils.GetDirectPingToPOP(popID: int)
static int luasteam_NetworkingUtils_GetDirectPingToPOP(lua_State *L) {
	auto *iface = SteamNetworkingUtils_SteamAPI();
	SteamNetworkingPOPID popID = static_cast<SteamNetworkingPOPID>(luaL_checkint(L, 1));
	int __ret = iface->GetDirectPingToPOP(popID);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// int GetPOPCount();
// In Lua:
// int NetworkingUtils.GetPOPCount()
static int luasteam_NetworkingUtils_GetPOPCount(lua_State *L) {
	auto *iface = SteamNetworkingUtils_SteamAPI();
	int __ret = iface->GetPOPCount();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// int GetPOPList(SteamNetworkingPOPID * list, int nListSz);
// In Lua:
// (int, list: int) NetworkingUtils.GetPOPList(nListSz: int)
static int luasteam_NetworkingUtils_GetPOPList(lua_State *L) {
	auto *iface = SteamNetworkingUtils_SteamAPI();
	SteamNetworkingPOPID list;
	int nListSz = static_cast<int>(luaL_checkint(L, 1));
	int __ret = iface->GetPOPList(&list, nListSz);
	lua_pushinteger(L, __ret);
	lua_pushinteger(L, list);
	return 2;
}

// In C++:
// bool IsFakeIPv4(uint32 nIPv4);
// In Lua:
// bool NetworkingUtils.IsFakeIPv4(nIPv4: int)
static int luasteam_NetworkingUtils_IsFakeIPv4(lua_State *L) {
	auto *iface = SteamNetworkingUtils_SteamAPI();
	uint32 nIPv4 = static_cast<uint32>(luaL_checkint(L, 1));
	bool __ret = iface->IsFakeIPv4(nIPv4);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// ESteamNetworkingFakeIPType GetIPv4FakeIPType(uint32 nIPv4);
// In Lua:
// int NetworkingUtils.GetIPv4FakeIPType(nIPv4: int)
static int luasteam_NetworkingUtils_GetIPv4FakeIPType(lua_State *L) {
	auto *iface = SteamNetworkingUtils_SteamAPI();
	uint32 nIPv4 = static_cast<uint32>(luaL_checkint(L, 1));
	ESteamNetworkingFakeIPType __ret = iface->GetIPv4FakeIPType(nIPv4);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// EResult GetRealIdentityForFakeIP(const SteamNetworkingIPAddr & fakeIP, SteamNetworkingIdentity * pOutRealIdentity);
// In Lua:
// (int, pOutRealIdentity: SteamNetworkingIdentity) NetworkingUtils.GetRealIdentityForFakeIP(fakeIP: SteamNetworkingIPAddr)
static int luasteam_NetworkingUtils_GetRealIdentityForFakeIP(lua_State *L) {
	auto *iface = SteamNetworkingUtils_SteamAPI();
	const SteamNetworkingIPAddr &fakeIP = *luasteam::check_SteamNetworkingIPAddr_ptr(L, 1);
	SteamNetworkingIdentity pOutRealIdentity;
	EResult __ret = iface->GetRealIdentityForFakeIP(fakeIP, &pOutRealIdentity);
	lua_pushinteger(L, __ret);
	luasteam::push_SteamNetworkingIdentity(L, pOutRealIdentity);
	return 2;
}

// In C++:
// bool SetGlobalConfigValueInt32(ESteamNetworkingConfigValue eValue, int32 val);
// In Lua:
// bool NetworkingUtils.SetGlobalConfigValueInt32(eValue: int, val: int)
static int luasteam_NetworkingUtils_SetGlobalConfigValueInt32(lua_State *L) {
	auto *iface = SteamNetworkingUtils_SteamAPI();
	ESteamNetworkingConfigValue eValue = static_cast<ESteamNetworkingConfigValue>(luaL_checkint(L, 1));
	int32 val = static_cast<int32>(luaL_checkint(L, 2));
	bool __ret = iface->SetGlobalConfigValueInt32(eValue, val);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetGlobalConfigValueFloat(ESteamNetworkingConfigValue eValue, float val);
// In Lua:
// bool NetworkingUtils.SetGlobalConfigValueFloat(eValue: int, val: float)
static int luasteam_NetworkingUtils_SetGlobalConfigValueFloat(lua_State *L) {
	auto *iface = SteamNetworkingUtils_SteamAPI();
	ESteamNetworkingConfigValue eValue = static_cast<ESteamNetworkingConfigValue>(luaL_checkint(L, 1));
	float val = static_cast<float>(luaL_checknumber(L, 2));
	bool __ret = iface->SetGlobalConfigValueFloat(eValue, val);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetGlobalConfigValueString(ESteamNetworkingConfigValue eValue, const char * val);
// In Lua:
// bool NetworkingUtils.SetGlobalConfigValueString(eValue: int, val: str)
static int luasteam_NetworkingUtils_SetGlobalConfigValueString(lua_State *L) {
	auto *iface = SteamNetworkingUtils_SteamAPI();
	ESteamNetworkingConfigValue eValue = static_cast<ESteamNetworkingConfigValue>(luaL_checkint(L, 1));
	const char *val = luaL_checkstring(L, 2);
	bool __ret = iface->SetGlobalConfigValueString(eValue, val);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetConnectionConfigValueInt32(HSteamNetConnection hConn, ESteamNetworkingConfigValue eValue, int32 val);
// In Lua:
// bool NetworkingUtils.SetConnectionConfigValueInt32(hConn: int, eValue: int, val: int)
static int luasteam_NetworkingUtils_SetConnectionConfigValueInt32(lua_State *L) {
	auto *iface = SteamNetworkingUtils_SteamAPI();
	HSteamNetConnection hConn = static_cast<HSteamNetConnection>(luaL_checkint(L, 1));
	ESteamNetworkingConfigValue eValue = static_cast<ESteamNetworkingConfigValue>(luaL_checkint(L, 2));
	int32 val = static_cast<int32>(luaL_checkint(L, 3));
	bool __ret = iface->SetConnectionConfigValueInt32(hConn, eValue, val);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetConnectionConfigValueFloat(HSteamNetConnection hConn, ESteamNetworkingConfigValue eValue, float val);
// In Lua:
// bool NetworkingUtils.SetConnectionConfigValueFloat(hConn: int, eValue: int, val: float)
static int luasteam_NetworkingUtils_SetConnectionConfigValueFloat(lua_State *L) {
	auto *iface = SteamNetworkingUtils_SteamAPI();
	HSteamNetConnection hConn = static_cast<HSteamNetConnection>(luaL_checkint(L, 1));
	ESteamNetworkingConfigValue eValue = static_cast<ESteamNetworkingConfigValue>(luaL_checkint(L, 2));
	float val = static_cast<float>(luaL_checknumber(L, 3));
	bool __ret = iface->SetConnectionConfigValueFloat(hConn, eValue, val);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetConnectionConfigValueString(HSteamNetConnection hConn, ESteamNetworkingConfigValue eValue, const char * val);
// In Lua:
// bool NetworkingUtils.SetConnectionConfigValueString(hConn: int, eValue: int, val: str)
static int luasteam_NetworkingUtils_SetConnectionConfigValueString(lua_State *L) {
	auto *iface = SteamNetworkingUtils_SteamAPI();
	HSteamNetConnection hConn = static_cast<HSteamNetConnection>(luaL_checkint(L, 1));
	ESteamNetworkingConfigValue eValue = static_cast<ESteamNetworkingConfigValue>(luaL_checkint(L, 2));
	const char *val = luaL_checkstring(L, 3);
	bool __ret = iface->SetConnectionConfigValueString(hConn, eValue, val);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// const char * GetConfigValueInfo(ESteamNetworkingConfigValue eValue, ESteamNetworkingConfigDataType * pOutDataType, ESteamNetworkingConfigScope * pOutScope);
// In Lua:
// (str, pOutDataType: int, pOutScope: int) NetworkingUtils.GetConfigValueInfo(eValue: int)
static int luasteam_NetworkingUtils_GetConfigValueInfo(lua_State *L) {
	auto *iface = SteamNetworkingUtils_SteamAPI();
	ESteamNetworkingConfigValue eValue = static_cast<ESteamNetworkingConfigValue>(luaL_checkint(L, 1));
	ESteamNetworkingConfigDataType pOutDataType;
	ESteamNetworkingConfigScope pOutScope;
	const char * __ret = iface->GetConfigValueInfo(eValue, &pOutDataType, &pOutScope);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	lua_pushinteger(L, pOutDataType);
	lua_pushinteger(L, pOutScope);
	return 3;
}

// In C++:
// ESteamNetworkingConfigValue IterateGenericEditableConfigValues(ESteamNetworkingConfigValue eCurrent, bool bEnumerateDevVars);
// In Lua:
// int NetworkingUtils.IterateGenericEditableConfigValues(eCurrent: int, bEnumerateDevVars: bool)
static int luasteam_NetworkingUtils_IterateGenericEditableConfigValues(lua_State *L) {
	auto *iface = SteamNetworkingUtils_SteamAPI();
	ESteamNetworkingConfigValue eCurrent = static_cast<ESteamNetworkingConfigValue>(luaL_checkint(L, 1));
	bool bEnumerateDevVars = lua_toboolean(L, 2);
	ESteamNetworkingConfigValue __ret = iface->IterateGenericEditableConfigValues(eCurrent, bEnumerateDevVars);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// void SteamNetworkingIPAddr_ToString(const SteamNetworkingIPAddr & addr, char * buf, uint32 cbBuf, bool bWithPort);
// In Lua:
// buf: str NetworkingUtils.SteamNetworkingIPAddr_ToString(addr: SteamNetworkingIPAddr, cbBuf: int, bWithPort: bool)
static int luasteam_NetworkingUtils_SteamNetworkingIPAddr_ToString(lua_State *L) {
	auto *iface = SteamNetworkingUtils_SteamAPI();
	const SteamNetworkingIPAddr &addr = *luasteam::check_SteamNetworkingIPAddr_ptr(L, 1);
	uint32 cbBuf = luaL_checkint(L, 2);
	std::vector<char> buf(cbBuf);
	bool bWithPort = lua_toboolean(L, 3);
	iface->SteamNetworkingIPAddr_ToString(addr, buf.data(), cbBuf, bWithPort);
	lua_pushstring(L, reinterpret_cast<const char*>(buf.data()));
	return 1;
}

// In C++:
// bool SteamNetworkingIPAddr_ParseString(SteamNetworkingIPAddr * pAddr, const char * pszStr);
// In Lua:
// (bool, pAddr: SteamNetworkingIPAddr) NetworkingUtils.SteamNetworkingIPAddr_ParseString(pszStr: str)
static int luasteam_NetworkingUtils_SteamNetworkingIPAddr_ParseString(lua_State *L) {
	auto *iface = SteamNetworkingUtils_SteamAPI();
	SteamNetworkingIPAddr pAddr;
	const char *pszStr = luaL_checkstring(L, 1);
	bool __ret = iface->SteamNetworkingIPAddr_ParseString(&pAddr, pszStr);
	lua_pushboolean(L, __ret);
	luasteam::push_SteamNetworkingIPAddr(L, pAddr);
	return 2;
}

// In C++:
// ESteamNetworkingFakeIPType SteamNetworkingIPAddr_GetFakeIPType(const SteamNetworkingIPAddr & addr);
// In Lua:
// int NetworkingUtils.SteamNetworkingIPAddr_GetFakeIPType(addr: SteamNetworkingIPAddr)
static int luasteam_NetworkingUtils_SteamNetworkingIPAddr_GetFakeIPType(lua_State *L) {
	auto *iface = SteamNetworkingUtils_SteamAPI();
	const SteamNetworkingIPAddr &addr = *luasteam::check_SteamNetworkingIPAddr_ptr(L, 1);
	ESteamNetworkingFakeIPType __ret = iface->SteamNetworkingIPAddr_GetFakeIPType(addr);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// void SteamNetworkingIdentity_ToString(const SteamNetworkingIdentity & identity, char * buf, uint32 cbBuf);
// In Lua:
// buf: str NetworkingUtils.SteamNetworkingIdentity_ToString(identity: SteamNetworkingIdentity, cbBuf: int)
static int luasteam_NetworkingUtils_SteamNetworkingIdentity_ToString(lua_State *L) {
	auto *iface = SteamNetworkingUtils_SteamAPI();
	const SteamNetworkingIdentity &identity = *luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	uint32 cbBuf = luaL_checkint(L, 2);
	std::vector<char> buf(cbBuf);
	iface->SteamNetworkingIdentity_ToString(identity, buf.data(), cbBuf);
	lua_pushstring(L, reinterpret_cast<const char*>(buf.data()));
	return 1;
}

// In C++:
// bool SteamNetworkingIdentity_ParseString(SteamNetworkingIdentity * pIdentity, const char * pszStr);
// In Lua:
// (bool, pIdentity: SteamNetworkingIdentity) NetworkingUtils.SteamNetworkingIdentity_ParseString(pszStr: str)
static int luasteam_NetworkingUtils_SteamNetworkingIdentity_ParseString(lua_State *L) {
	auto *iface = SteamNetworkingUtils_SteamAPI();
	SteamNetworkingIdentity pIdentity;
	const char *pszStr = luaL_checkstring(L, 1);
	bool __ret = iface->SteamNetworkingIdentity_ParseString(&pIdentity, pszStr);
	lua_pushboolean(L, __ret);
	luasteam::push_SteamNetworkingIdentity(L, pIdentity);
	return 2;
}

void register_NetworkingUtils_auto(lua_State *L) {
	add_func(L, "InitRelayNetworkAccess", luasteam_NetworkingUtils_InitRelayNetworkAccess);
	add_func(L, "GetRelayNetworkStatus", luasteam_NetworkingUtils_GetRelayNetworkStatus);
	add_func(L, "EstimatePingTimeBetweenTwoLocations", luasteam_NetworkingUtils_EstimatePingTimeBetweenTwoLocations);
	add_func(L, "EstimatePingTimeFromLocalHost", luasteam_NetworkingUtils_EstimatePingTimeFromLocalHost);
	add_func(L, "ConvertPingLocationToString", luasteam_NetworkingUtils_ConvertPingLocationToString);
	add_func(L, "CheckPingDataUpToDate", luasteam_NetworkingUtils_CheckPingDataUpToDate);
	add_func(L, "GetPingToDataCenter", luasteam_NetworkingUtils_GetPingToDataCenter);
	add_func(L, "GetDirectPingToPOP", luasteam_NetworkingUtils_GetDirectPingToPOP);
	add_func(L, "GetPOPCount", luasteam_NetworkingUtils_GetPOPCount);
	add_func(L, "GetPOPList", luasteam_NetworkingUtils_GetPOPList);
	add_func(L, "IsFakeIPv4", luasteam_NetworkingUtils_IsFakeIPv4);
	add_func(L, "GetIPv4FakeIPType", luasteam_NetworkingUtils_GetIPv4FakeIPType);
	add_func(L, "GetRealIdentityForFakeIP", luasteam_NetworkingUtils_GetRealIdentityForFakeIP);
	add_func(L, "SetGlobalConfigValueInt32", luasteam_NetworkingUtils_SetGlobalConfigValueInt32);
	add_func(L, "SetGlobalConfigValueFloat", luasteam_NetworkingUtils_SetGlobalConfigValueFloat);
	add_func(L, "SetGlobalConfigValueString", luasteam_NetworkingUtils_SetGlobalConfigValueString);
	add_func(L, "SetConnectionConfigValueInt32", luasteam_NetworkingUtils_SetConnectionConfigValueInt32);
	add_func(L, "SetConnectionConfigValueFloat", luasteam_NetworkingUtils_SetConnectionConfigValueFloat);
	add_func(L, "SetConnectionConfigValueString", luasteam_NetworkingUtils_SetConnectionConfigValueString);
	add_func(L, "GetConfigValueInfo", luasteam_NetworkingUtils_GetConfigValueInfo);
	add_func(L, "IterateGenericEditableConfigValues", luasteam_NetworkingUtils_IterateGenericEditableConfigValues);
	add_func(L, "SteamNetworkingIPAddr_ToString", luasteam_NetworkingUtils_SteamNetworkingIPAddr_ToString);
	add_func(L, "SteamNetworkingIPAddr_ParseString", luasteam_NetworkingUtils_SteamNetworkingIPAddr_ParseString);
	add_func(L, "SteamNetworkingIPAddr_GetFakeIPType", luasteam_NetworkingUtils_SteamNetworkingIPAddr_GetFakeIPType);
	add_func(L, "SteamNetworkingIdentity_ToString", luasteam_NetworkingUtils_SteamNetworkingIdentity_ToString);
	add_func(L, "SteamNetworkingIdentity_ParseString", luasteam_NetworkingUtils_SteamNetworkingIdentity_ParseString);
}

void add_NetworkingUtils_auto(lua_State *L) {
	lua_createtable(L, 0, 26);
	register_NetworkingUtils_auto(L);
	lua_pushvalue(L, -1);
	NetworkingUtils_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "NetworkingUtils");
}

} // namespace luasteam
