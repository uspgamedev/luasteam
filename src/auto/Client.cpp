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
EXTERN int luasteam_Client_CreateSteamPipe(lua_State *L) {
	HSteamPipe __ret = SteamClient()->CreateSteamPipe();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool BReleaseSteamPipe(HSteamPipe hSteamPipe);
// In Lua:
// bool Client.BReleaseSteamPipe(hSteamPipe: int)
EXTERN int luasteam_Client_BReleaseSteamPipe(lua_State *L) {
	HSteamPipe hSteamPipe = static_cast<HSteamPipe>(luaL_checkint(L, 1));
	bool __ret = SteamClient()->BReleaseSteamPipe(hSteamPipe);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// HSteamUser ConnectToGlobalUser(HSteamPipe hSteamPipe);
// In Lua:
// int Client.ConnectToGlobalUser(hSteamPipe: int)
EXTERN int luasteam_Client_ConnectToGlobalUser(lua_State *L) {
	HSteamPipe hSteamPipe = static_cast<HSteamPipe>(luaL_checkint(L, 1));
	HSteamUser __ret = SteamClient()->ConnectToGlobalUser(hSteamPipe);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// HSteamUser CreateLocalUser(HSteamPipe * phSteamPipe, EAccountType eAccountType);
// In Lua:
// (int, phSteamPipe: int) Client.CreateLocalUser(eAccountType: int)
EXTERN int luasteam_Client_CreateLocalUser(lua_State *L) {
	HSteamPipe phSteamPipe;
	EAccountType eAccountType = static_cast<EAccountType>(luaL_checkint(L, 1));
	HSteamUser __ret = SteamClient()->CreateLocalUser(&phSteamPipe, eAccountType);
	lua_pushinteger(L, __ret);
	lua_pushinteger(L, phSteamPipe);
	return 2;
}

// In C++:
// void ReleaseUser(HSteamPipe hSteamPipe, HSteamUser hUser);
// In Lua:
// Client.ReleaseUser(hSteamPipe: int, hUser: int)
EXTERN int luasteam_Client_ReleaseUser(lua_State *L) {
	HSteamPipe hSteamPipe = static_cast<HSteamPipe>(luaL_checkint(L, 1));
	HSteamUser hUser = static_cast<HSteamUser>(luaL_checkint(L, 2));
	SteamClient()->ReleaseUser(hSteamPipe, hUser);
	return 0;
}

// In C++:
// void SetLocalIPBinding(const SteamIPAddress_t & unIP, uint16 usPort);
// In Lua:
// Client.SetLocalIPBinding(unIP: SteamIPAddress_t, usPort: int)
EXTERN int luasteam_Client_SetLocalIPBinding(lua_State *L) {
	const SteamIPAddress_t &unIP = *luasteam::check_SteamIPAddress_t_ptr(L, 1);
	uint16 usPort = static_cast<uint16>(luaL_checkint(L, 2));
	SteamClient()->SetLocalIPBinding(unIP, usPort);
	return 0;
}

// In C++:
// void * GetISteamGenericInterface(HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char * pchVersion);
// In Lua:
// str Client.GetISteamGenericInterface(hSteamUser: int, hSteamPipe: int, pchVersion: str)
EXTERN int luasteam_Client_GetISteamGenericInterface(lua_State *L) {
	HSteamUser hSteamUser = static_cast<HSteamUser>(luaL_checkint(L, 1));
	HSteamPipe hSteamPipe = static_cast<HSteamPipe>(luaL_checkint(L, 2));
	const char *pchVersion = luaL_checkstring(L, 3);
	void * __ret = SteamClient()->GetISteamGenericInterface(hSteamUser, hSteamPipe, pchVersion);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// uint32 GetIPCCallCount();
// In Lua:
// int Client.GetIPCCallCount()
EXTERN int luasteam_Client_GetIPCCallCount(lua_State *L) {
	uint32 __ret = SteamClient()->GetIPCCallCount();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool BShutdownIfAllPipesClosed();
// In Lua:
// bool Client.BShutdownIfAllPipesClosed()
EXTERN int luasteam_Client_BShutdownIfAllPipesClosed(lua_State *L) {
	bool __ret = SteamClient()->BShutdownIfAllPipesClosed();
	lua_pushboolean(L, __ret);
	return 1;
}

void register_Client_auto(lua_State *L) {
	add_func(L, "CreateSteamPipe", luasteam_Client_CreateSteamPipe);
	add_func(L, "BReleaseSteamPipe", luasteam_Client_BReleaseSteamPipe);
	add_func(L, "ConnectToGlobalUser", luasteam_Client_ConnectToGlobalUser);
	add_func(L, "CreateLocalUser", luasteam_Client_CreateLocalUser);
	add_func(L, "ReleaseUser", luasteam_Client_ReleaseUser);
	add_func(L, "SetLocalIPBinding", luasteam_Client_SetLocalIPBinding);
	add_func(L, "GetISteamGenericInterface", luasteam_Client_GetISteamGenericInterface);
	add_func(L, "GetIPCCallCount", luasteam_Client_GetIPCCallCount);
	add_func(L, "BShutdownIfAllPipesClosed", luasteam_Client_BShutdownIfAllPipesClosed);
}

void add_Client_auto(lua_State *L) {
	lua_createtable(L, 0, 9);
	register_Client_auto(L);
	lua_pushvalue(L, -1);
	Client_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "Client");
}

} // namespace luasteam
