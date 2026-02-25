#include "auto.hpp"

namespace luasteam {

int Client_ref = LUA_NOREF;
typedef ISteamClient *(*ClientAccessor)();

void init_Client_auto(lua_State *L) {}
void shutdown_Client_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, Client_ref);
	Client_ref = LUA_NOREF;
}

// In C++:
// HSteamPipe CreateSteamPipe();
// In Lua:
// int Client.CreateSteamPipe()
static int luasteam_Client_CreateSteamPipe(lua_State *L) {
	auto *iface = ((ClientAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	HSteamPipe __ret = iface->CreateSteamPipe();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool BReleaseSteamPipe(HSteamPipe hSteamPipe);
// In Lua:
// bool Client.BReleaseSteamPipe(hSteamPipe: int)
static int luasteam_Client_BReleaseSteamPipe(lua_State *L) {
	auto *iface = ((ClientAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	HSteamPipe hSteamPipe = static_cast<HSteamPipe>(luaL_checkint(L, 1));
	bool __ret = iface->BReleaseSteamPipe(hSteamPipe);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// HSteamUser ConnectToGlobalUser(HSteamPipe hSteamPipe);
// In Lua:
// int Client.ConnectToGlobalUser(hSteamPipe: int)
static int luasteam_Client_ConnectToGlobalUser(lua_State *L) {
	auto *iface = ((ClientAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	HSteamPipe hSteamPipe = static_cast<HSteamPipe>(luaL_checkint(L, 1));
	HSteamUser __ret = iface->ConnectToGlobalUser(hSteamPipe);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// HSteamUser CreateLocalUser(HSteamPipe * phSteamPipe, EAccountType eAccountType);
// In Lua:
// (int, phSteamPipe: int) Client.CreateLocalUser(eAccountType: int)
static int luasteam_Client_CreateLocalUser(lua_State *L) {
	auto *iface = ((ClientAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	HSteamPipe phSteamPipe;
	EAccountType eAccountType = static_cast<EAccountType>(luaL_checkint(L, 1));
	HSteamUser __ret = iface->CreateLocalUser(&phSteamPipe, eAccountType);
	lua_pushinteger(L, __ret);
	lua_pushinteger(L, phSteamPipe);
	return 2;
}

// In C++:
// void ReleaseUser(HSteamPipe hSteamPipe, HSteamUser hUser);
// In Lua:
// Client.ReleaseUser(hSteamPipe: int, hUser: int)
static int luasteam_Client_ReleaseUser(lua_State *L) {
	auto *iface = ((ClientAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	HSteamPipe hSteamPipe = static_cast<HSteamPipe>(luaL_checkint(L, 1));
	HSteamUser hUser = static_cast<HSteamUser>(luaL_checkint(L, 2));
	iface->ReleaseUser(hSteamPipe, hUser);
	return 0;
}

// In C++:
// void SetLocalIPBinding(const SteamIPAddress_t & unIP, uint16 usPort);
// In Lua:
// Client.SetLocalIPBinding(unIP: SteamIPAddress_t, usPort: int)
static int luasteam_Client_SetLocalIPBinding(lua_State *L) {
	auto *iface = ((ClientAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	const SteamIPAddress_t &unIP = *luasteam::check_SteamIPAddress_t_ptr(L, 1);
	uint16 usPort = static_cast<uint16>(luaL_checkint(L, 2));
	iface->SetLocalIPBinding(unIP, usPort);
	return 0;
}

// In C++:
// void * GetISteamGenericInterface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion);
// In Lua:
// str Client.GetISteamGenericInterface(hSteamUser: int, hSteamPipe: int, pchVersion: str)
static int luasteam_Client_GetISteamGenericInterface(lua_State *L) {
	auto *iface = ((ClientAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	HSteamUser hSteamUser = static_cast<HSteamUser>(luaL_checkint(L, 1));
	HSteamPipe hSteamPipe = static_cast<HSteamPipe>(luaL_checkint(L, 2));
	const char *pchVersion = luaL_checkstring(L, 3);
	void * __ret = iface->GetISteamGenericInterface(hSteamUser, hSteamPipe, pchVersion);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// uint32 GetIPCCallCount();
// In Lua:
// int Client.GetIPCCallCount()
static int luasteam_Client_GetIPCCallCount(lua_State *L) {
	auto *iface = ((ClientAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	uint32 __ret = iface->GetIPCCallCount();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool BShutdownIfAllPipesClosed();
// In Lua:
// bool Client.BShutdownIfAllPipesClosed()
static int luasteam_Client_BShutdownIfAllPipesClosed(lua_State *L) {
	auto *iface = ((ClientAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	bool __ret = iface->BShutdownIfAllPipesClosed();
	lua_pushboolean(L, __ret);
	return 1;
}

void register_Client_auto(lua_State *L, ClientAccessor accessor) {
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_Client_CreateSteamPipe, 1);
	lua_setfield(L, -2, "CreateSteamPipe");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_Client_BReleaseSteamPipe, 1);
	lua_setfield(L, -2, "BReleaseSteamPipe");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_Client_ConnectToGlobalUser, 1);
	lua_setfield(L, -2, "ConnectToGlobalUser");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_Client_CreateLocalUser, 1);
	lua_setfield(L, -2, "CreateLocalUser");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_Client_ReleaseUser, 1);
	lua_setfield(L, -2, "ReleaseUser");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_Client_SetLocalIPBinding, 1);
	lua_setfield(L, -2, "SetLocalIPBinding");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_Client_GetISteamGenericInterface, 1);
	lua_setfield(L, -2, "GetISteamGenericInterface");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_Client_GetIPCCallCount, 1);
	lua_setfield(L, -2, "GetIPCCallCount");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_Client_BShutdownIfAllPipesClosed, 1);
	lua_setfield(L, -2, "BShutdownIfAllPipesClosed");
}

void add_Client_auto(lua_State *L) {
	lua_createtable(L, 0, 9);
	register_Client_auto(L, &SteamClient);
	lua_pushvalue(L, -1);
	Client_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "Client");
}

int GameServerClient_ref = LUA_NOREF;

void init_GameServerClient_auto(lua_State *L) {}
void shutdown_GameServerClient_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, GameServerClient_ref);
	GameServerClient_ref = LUA_NOREF;
}

void add_GameServerClient_auto(lua_State *L) {
	lua_createtable(L, 0, 9);
	register_Client_auto(L, &SteamGameServerClient);
	lua_pushvalue(L, -1);
	GameServerClient_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "GameServerClient");
}

} // namespace luasteam
