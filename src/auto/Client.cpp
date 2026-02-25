#include "auto.hpp"

namespace luasteam {

int Client_ref = LUA_NOREF;

void init_Client_auto(lua_State *L) {}
void shutdown_Client_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, Client_ref);
	Client_ref = LUA_NOREF;
}

// In C++:
// HSteamPipe CreateSteamPipe();
// In Lua:
// int Client.CreateSteamPipe()
static int luasteam_Client_CreateSteamPipe(lua_State *L, ISteamClient *iface) {
	HSteamPipe __ret = iface->CreateSteamPipe();
	lua_pushinteger(L, __ret);
	return 1;
}
static int luasteam_Client_CreateSteamPipe_user(lua_State *L) { return luasteam_Client_CreateSteamPipe(L, SteamClient()); }
static int luasteam_Client_CreateSteamPipe_gs(lua_State *L) { return luasteam_Client_CreateSteamPipe(L, SteamGameServerClient()); }

// In C++:
// bool BReleaseSteamPipe(HSteamPipe hSteamPipe);
// In Lua:
// bool Client.BReleaseSteamPipe(hSteamPipe: int)
static int luasteam_Client_BReleaseSteamPipe(lua_State *L, ISteamClient *iface) {
	HSteamPipe hSteamPipe = static_cast<HSteamPipe>(luaL_checkint(L, 1));
	bool __ret = iface->BReleaseSteamPipe(hSteamPipe);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_Client_BReleaseSteamPipe_user(lua_State *L) { return luasteam_Client_BReleaseSteamPipe(L, SteamClient()); }
static int luasteam_Client_BReleaseSteamPipe_gs(lua_State *L) { return luasteam_Client_BReleaseSteamPipe(L, SteamGameServerClient()); }

// In C++:
// HSteamUser ConnectToGlobalUser(HSteamPipe hSteamPipe);
// In Lua:
// int Client.ConnectToGlobalUser(hSteamPipe: int)
static int luasteam_Client_ConnectToGlobalUser(lua_State *L, ISteamClient *iface) {
	HSteamPipe hSteamPipe = static_cast<HSteamPipe>(luaL_checkint(L, 1));
	HSteamUser __ret = iface->ConnectToGlobalUser(hSteamPipe);
	lua_pushinteger(L, __ret);
	return 1;
}
static int luasteam_Client_ConnectToGlobalUser_user(lua_State *L) { return luasteam_Client_ConnectToGlobalUser(L, SteamClient()); }
static int luasteam_Client_ConnectToGlobalUser_gs(lua_State *L) { return luasteam_Client_ConnectToGlobalUser(L, SteamGameServerClient()); }

// In C++:
// HSteamUser CreateLocalUser(HSteamPipe * phSteamPipe, EAccountType eAccountType);
// In Lua:
// (int, phSteamPipe: int) Client.CreateLocalUser(eAccountType: int)
static int luasteam_Client_CreateLocalUser(lua_State *L, ISteamClient *iface) {
	HSteamPipe phSteamPipe;
	EAccountType eAccountType = static_cast<EAccountType>(luaL_checkint(L, 1));
	HSteamUser __ret = iface->CreateLocalUser(&phSteamPipe, eAccountType);
	lua_pushinteger(L, __ret);
	lua_pushinteger(L, phSteamPipe);
	return 2;
}
static int luasteam_Client_CreateLocalUser_user(lua_State *L) { return luasteam_Client_CreateLocalUser(L, SteamClient()); }
static int luasteam_Client_CreateLocalUser_gs(lua_State *L) { return luasteam_Client_CreateLocalUser(L, SteamGameServerClient()); }

// In C++:
// void ReleaseUser(HSteamPipe hSteamPipe, HSteamUser hUser);
// In Lua:
// Client.ReleaseUser(hSteamPipe: int, hUser: int)
static int luasteam_Client_ReleaseUser(lua_State *L, ISteamClient *iface) {
	HSteamPipe hSteamPipe = static_cast<HSteamPipe>(luaL_checkint(L, 1));
	HSteamUser hUser = static_cast<HSteamUser>(luaL_checkint(L, 2));
	iface->ReleaseUser(hSteamPipe, hUser);
	return 0;
}
static int luasteam_Client_ReleaseUser_user(lua_State *L) { return luasteam_Client_ReleaseUser(L, SteamClient()); }
static int luasteam_Client_ReleaseUser_gs(lua_State *L) { return luasteam_Client_ReleaseUser(L, SteamGameServerClient()); }

// In C++:
// void SetLocalIPBinding(const SteamIPAddress_t & unIP, uint16 usPort);
// In Lua:
// Client.SetLocalIPBinding(unIP: SteamIPAddress_t, usPort: int)
static int luasteam_Client_SetLocalIPBinding(lua_State *L, ISteamClient *iface) {
	const SteamIPAddress_t &unIP = *luasteam::check_SteamIPAddress_t_ptr(L, 1);
	uint16 usPort = static_cast<uint16>(luaL_checkint(L, 2));
	iface->SetLocalIPBinding(unIP, usPort);
	return 0;
}
static int luasteam_Client_SetLocalIPBinding_user(lua_State *L) { return luasteam_Client_SetLocalIPBinding(L, SteamClient()); }
static int luasteam_Client_SetLocalIPBinding_gs(lua_State *L) { return luasteam_Client_SetLocalIPBinding(L, SteamGameServerClient()); }

// In C++:
// void * GetISteamGenericInterface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion);
// In Lua:
// str Client.GetISteamGenericInterface(hSteamUser: int, hSteamPipe: int, pchVersion: str)
static int luasteam_Client_GetISteamGenericInterface(lua_State *L, ISteamClient *iface) {
	HSteamUser hSteamUser = static_cast<HSteamUser>(luaL_checkint(L, 1));
	HSteamPipe hSteamPipe = static_cast<HSteamPipe>(luaL_checkint(L, 2));
	const char *pchVersion = luaL_checkstring(L, 3);
	void * __ret = iface->GetISteamGenericInterface(hSteamUser, hSteamPipe, pchVersion);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}
static int luasteam_Client_GetISteamGenericInterface_user(lua_State *L) { return luasteam_Client_GetISteamGenericInterface(L, SteamClient()); }
static int luasteam_Client_GetISteamGenericInterface_gs(lua_State *L) { return luasteam_Client_GetISteamGenericInterface(L, SteamGameServerClient()); }

// In C++:
// uint32 GetIPCCallCount();
// In Lua:
// int Client.GetIPCCallCount()
static int luasteam_Client_GetIPCCallCount(lua_State *L, ISteamClient *iface) {
	uint32 __ret = iface->GetIPCCallCount();
	lua_pushinteger(L, __ret);
	return 1;
}
static int luasteam_Client_GetIPCCallCount_user(lua_State *L) { return luasteam_Client_GetIPCCallCount(L, SteamClient()); }
static int luasteam_Client_GetIPCCallCount_gs(lua_State *L) { return luasteam_Client_GetIPCCallCount(L, SteamGameServerClient()); }

// In C++:
// bool BShutdownIfAllPipesClosed();
// In Lua:
// bool Client.BShutdownIfAllPipesClosed()
static int luasteam_Client_BShutdownIfAllPipesClosed(lua_State *L, ISteamClient *iface) {
	bool __ret = iface->BShutdownIfAllPipesClosed();
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_Client_BShutdownIfAllPipesClosed_user(lua_State *L) { return luasteam_Client_BShutdownIfAllPipesClosed(L, SteamClient()); }
static int luasteam_Client_BShutdownIfAllPipesClosed_gs(lua_State *L) { return luasteam_Client_BShutdownIfAllPipesClosed(L, SteamGameServerClient()); }

void register_Client_auto(lua_State *L, bool is_gs) {
	add_func(L, "CreateSteamPipe", is_gs ? luasteam_Client_CreateSteamPipe_gs : luasteam_Client_CreateSteamPipe_user);
	add_func(L, "BReleaseSteamPipe", is_gs ? luasteam_Client_BReleaseSteamPipe_gs : luasteam_Client_BReleaseSteamPipe_user);
	add_func(L, "ConnectToGlobalUser", is_gs ? luasteam_Client_ConnectToGlobalUser_gs : luasteam_Client_ConnectToGlobalUser_user);
	add_func(L, "CreateLocalUser", is_gs ? luasteam_Client_CreateLocalUser_gs : luasteam_Client_CreateLocalUser_user);
	add_func(L, "ReleaseUser", is_gs ? luasteam_Client_ReleaseUser_gs : luasteam_Client_ReleaseUser_user);
	add_func(L, "SetLocalIPBinding", is_gs ? luasteam_Client_SetLocalIPBinding_gs : luasteam_Client_SetLocalIPBinding_user);
	add_func(L, "GetISteamGenericInterface", is_gs ? luasteam_Client_GetISteamGenericInterface_gs : luasteam_Client_GetISteamGenericInterface_user);
	add_func(L, "GetIPCCallCount", is_gs ? luasteam_Client_GetIPCCallCount_gs : luasteam_Client_GetIPCCallCount_user);
	add_func(L, "BShutdownIfAllPipesClosed", is_gs ? luasteam_Client_BShutdownIfAllPipesClosed_gs : luasteam_Client_BShutdownIfAllPipesClosed_user);
}

void add_Client_auto(lua_State *L) {
	lua_createtable(L, 0, 9);
	register_Client_auto(L, false);
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
	register_Client_auto(L, true);
	lua_pushvalue(L, -1);
	GameServerClient_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "GameServerClient");
}

} // namespace luasteam
