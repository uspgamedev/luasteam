#include "auto.hpp"

namespace luasteam {

int RemotePlay_ref = LUA_NOREF;

namespace {
class RemotePlayCallbackListener {
private:
	STEAM_CALLBACK(RemotePlayCallbackListener, OnSteamRemotePlaySessionConnected, SteamRemotePlaySessionConnected_t);
	STEAM_CALLBACK(RemotePlayCallbackListener, OnSteamRemotePlaySessionDisconnected, SteamRemotePlaySessionDisconnected_t);
	STEAM_CALLBACK(RemotePlayCallbackListener, OnSteamRemotePlayTogetherGuestInvite, SteamRemotePlayTogetherGuestInvite_t);
};
void RemotePlayCallbackListener::OnSteamRemotePlaySessionConnected(SteamRemotePlaySessionConnected_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemotePlay_ref);
	lua_getfield(L, -1, "OnSteamRemotePlaySessionConnected");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamRemotePlaySessionConnected_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void RemotePlayCallbackListener::OnSteamRemotePlaySessionDisconnected(SteamRemotePlaySessionDisconnected_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemotePlay_ref);
	lua_getfield(L, -1, "OnSteamRemotePlaySessionDisconnected");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamRemotePlaySessionDisconnected_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void RemotePlayCallbackListener::OnSteamRemotePlayTogetherGuestInvite(SteamRemotePlayTogetherGuestInvite_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemotePlay_ref);
	lua_getfield(L, -1, "OnSteamRemotePlayTogetherGuestInvite");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamRemotePlayTogetherGuestInvite_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
RemotePlayCallbackListener *RemotePlay_listener = nullptr;
} // namespace

void init_RemotePlay_auto(lua_State *L) { if (RemotePlay_listener != nullptr) return; RemotePlay_listener = new RemotePlayCallbackListener(); }
void shutdown_RemotePlay_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, RemotePlay_ref);
	RemotePlay_ref = LUA_NOREF;
	delete RemotePlay_listener; RemotePlay_listener = nullptr;
}

// In C++:
// uint32 GetSessionCount();
// In Lua:
// int RemotePlay.GetSessionCount()
static int luasteam_RemotePlay_GetSessionCount(lua_State *L) {
	auto *iface = SteamRemotePlay();
	uint32 __ret = iface->GetSessionCount();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// RemotePlaySessionID_t GetSessionID(int iSessionIndex);
// In Lua:
// int RemotePlay.GetSessionID(iSessionIndex: int)
static int luasteam_RemotePlay_GetSessionID(lua_State *L) {
	auto *iface = SteamRemotePlay();
	int iSessionIndex = static_cast<int>(luaL_checkint(L, 1));
	RemotePlaySessionID_t __ret = iface->GetSessionID(iSessionIndex);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// CSteamID GetSessionSteamID(RemotePlaySessionID_t unSessionID);
// In Lua:
// uint64 RemotePlay.GetSessionSteamID(unSessionID: int)
static int luasteam_RemotePlay_GetSessionSteamID(lua_State *L) {
	auto *iface = SteamRemotePlay();
	RemotePlaySessionID_t unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, 1));
	CSteamID __ret = iface->GetSessionSteamID(unSessionID);
	luasteam::pushuint64(L, __ret.ConvertToUint64());
	return 1;
}

// In C++:
// const char * GetSessionClientName(RemotePlaySessionID_t unSessionID);
// In Lua:
// str RemotePlay.GetSessionClientName(unSessionID: int)
static int luasteam_RemotePlay_GetSessionClientName(lua_State *L) {
	auto *iface = SteamRemotePlay();
	RemotePlaySessionID_t unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, 1));
	const char * __ret = iface->GetSessionClientName(unSessionID);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// ESteamDeviceFormFactor GetSessionClientFormFactor(RemotePlaySessionID_t unSessionID);
// In Lua:
// int RemotePlay.GetSessionClientFormFactor(unSessionID: int)
static int luasteam_RemotePlay_GetSessionClientFormFactor(lua_State *L) {
	auto *iface = SteamRemotePlay();
	RemotePlaySessionID_t unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, 1));
	ESteamDeviceFormFactor __ret = iface->GetSessionClientFormFactor(unSessionID);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool BGetSessionClientResolution(RemotePlaySessionID_t unSessionID, int * pnResolutionX, int * pnResolutionY);
// In Lua:
// (bool, pnResolutionX: int, pnResolutionY: int) RemotePlay.BGetSessionClientResolution(unSessionID: int)
static int luasteam_RemotePlay_BGetSessionClientResolution(lua_State *L) {
	auto *iface = SteamRemotePlay();
	RemotePlaySessionID_t unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, 1));
	int pnResolutionX;
	int pnResolutionY;
	bool __ret = iface->BGetSessionClientResolution(unSessionID, &pnResolutionX, &pnResolutionY);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pnResolutionX);
	lua_pushinteger(L, pnResolutionY);
	return 3;
}

// In C++:
// bool ShowRemotePlayTogetherUI();
// In Lua:
// bool RemotePlay.ShowRemotePlayTogetherUI()
static int luasteam_RemotePlay_ShowRemotePlayTogetherUI(lua_State *L) {
	auto *iface = SteamRemotePlay();
	bool __ret = iface->ShowRemotePlayTogetherUI();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool BSendRemotePlayTogetherInvite(CSteamID steamIDFriend);
// In Lua:
// bool RemotePlay.BSendRemotePlayTogetherInvite(steamIDFriend: uint64)
static int luasteam_RemotePlay_BSendRemotePlayTogetherInvite(lua_State *L) {
	auto *iface = SteamRemotePlay();
	CSteamID steamIDFriend = CSteamID(luasteam::checkuint64(L, 1));
	bool __ret = iface->BSendRemotePlayTogetherInvite(steamIDFriend);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool BEnableRemotePlayTogetherDirectInput();
// In Lua:
// bool RemotePlay.BEnableRemotePlayTogetherDirectInput()
static int luasteam_RemotePlay_BEnableRemotePlayTogetherDirectInput(lua_State *L) {
	auto *iface = SteamRemotePlay();
	bool __ret = iface->BEnableRemotePlayTogetherDirectInput();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// void DisableRemotePlayTogetherDirectInput();
// In Lua:
// RemotePlay.DisableRemotePlayTogetherDirectInput()
static int luasteam_RemotePlay_DisableRemotePlayTogetherDirectInput(lua_State *L) {
	auto *iface = SteamRemotePlay();
	iface->DisableRemotePlayTogetherDirectInput();
	return 0;
}

// In C++:
// uint32 GetInput(RemotePlayInput_t * pInput, uint32 unMaxEvents);
// In Lua:
// (int, pInput: RemotePlayInput_t[]) RemotePlay.GetInput(unMaxEvents: int)
static int luasteam_RemotePlay_GetInput(lua_State *L) {
	auto *iface = SteamRemotePlay();
	uint32 unMaxEvents = luaL_checkint(L, 1);
	std::vector<RemotePlayInput_t> pInput(unMaxEvents);
	uint32 __ret = iface->GetInput(pInput.data(), unMaxEvents);
	lua_pushinteger(L, __ret);
	lua_createtable(L, __ret, 0);
	for(decltype(__ret) i = 0; i < __ret; i++) {
		luasteam::push_RemotePlayInput_t(L, pInput[i]);
		lua_rawseti(L, -2, i+1);
	}
	return 2;
}

// In C++:
// void SetMouseVisibility(RemotePlaySessionID_t unSessionID, bool bVisible);
// In Lua:
// RemotePlay.SetMouseVisibility(unSessionID: int, bVisible: bool)
static int luasteam_RemotePlay_SetMouseVisibility(lua_State *L) {
	auto *iface = SteamRemotePlay();
	RemotePlaySessionID_t unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, 1));
	bool bVisible = lua_toboolean(L, 2);
	iface->SetMouseVisibility(unSessionID, bVisible);
	return 0;
}

// In C++:
// void SetMousePosition(RemotePlaySessionID_t unSessionID, float flNormalizedX, float flNormalizedY);
// In Lua:
// RemotePlay.SetMousePosition(unSessionID: int, flNormalizedX: float, flNormalizedY: float)
static int luasteam_RemotePlay_SetMousePosition(lua_State *L) {
	auto *iface = SteamRemotePlay();
	RemotePlaySessionID_t unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, 1));
	float flNormalizedX = static_cast<float>(luaL_checknumber(L, 2));
	float flNormalizedY = static_cast<float>(luaL_checknumber(L, 3));
	iface->SetMousePosition(unSessionID, flNormalizedX, flNormalizedY);
	return 0;
}

// In C++:
// RemotePlayCursorID_t CreateMouseCursor(int nWidth, int nHeight, int nHotX, int nHotY, const void * pBGRA, int nPitch);
// In Lua:
// int RemotePlay.CreateMouseCursor(nWidth: int, nHeight: int, nHotX: int, nHotY: int, pBGRA: str, nPitch: int)
static int luasteam_RemotePlay_CreateMouseCursor(lua_State *L) {
	auto *iface = SteamRemotePlay();
	int nWidth = static_cast<int>(luaL_checkint(L, 1));
	int nHeight = static_cast<int>(luaL_checkint(L, 2));
	int nHotX = static_cast<int>(luaL_checkint(L, 3));
	int nHotY = static_cast<int>(luaL_checkint(L, 4));
	size_t _len__tmp0;
	const char *_tmp0 = luaL_checklstring(L, 5, &_len__tmp0);
	const void *pBGRA = reinterpret_cast<const void *>(_tmp0);
	int nPitch = static_cast<int>(luaL_checkint(L, 5));
	RemotePlayCursorID_t __ret = iface->CreateMouseCursor(nWidth, nHeight, nHotX, nHotY, pBGRA, nPitch);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// void SetMouseCursor(RemotePlaySessionID_t unSessionID, RemotePlayCursorID_t unCursorID);
// In Lua:
// RemotePlay.SetMouseCursor(unSessionID: int, unCursorID: int)
static int luasteam_RemotePlay_SetMouseCursor(lua_State *L) {
	auto *iface = SteamRemotePlay();
	RemotePlaySessionID_t unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, 1));
	RemotePlayCursorID_t unCursorID = static_cast<RemotePlayCursorID_t>(luaL_checkint(L, 2));
	iface->SetMouseCursor(unSessionID, unCursorID);
	return 0;
}

void register_RemotePlay_auto(lua_State *L) {
	add_func(L, "GetSessionCount", luasteam_RemotePlay_GetSessionCount);
	add_func(L, "GetSessionID", luasteam_RemotePlay_GetSessionID);
	add_func(L, "GetSessionSteamID", luasteam_RemotePlay_GetSessionSteamID);
	add_func(L, "GetSessionClientName", luasteam_RemotePlay_GetSessionClientName);
	add_func(L, "GetSessionClientFormFactor", luasteam_RemotePlay_GetSessionClientFormFactor);
	add_func(L, "BGetSessionClientResolution", luasteam_RemotePlay_BGetSessionClientResolution);
	add_func(L, "ShowRemotePlayTogetherUI", luasteam_RemotePlay_ShowRemotePlayTogetherUI);
	add_func(L, "BSendRemotePlayTogetherInvite", luasteam_RemotePlay_BSendRemotePlayTogetherInvite);
	add_func(L, "BEnableRemotePlayTogetherDirectInput", luasteam_RemotePlay_BEnableRemotePlayTogetherDirectInput);
	add_func(L, "DisableRemotePlayTogetherDirectInput", luasteam_RemotePlay_DisableRemotePlayTogetherDirectInput);
	add_func(L, "GetInput", luasteam_RemotePlay_GetInput);
	add_func(L, "SetMouseVisibility", luasteam_RemotePlay_SetMouseVisibility);
	add_func(L, "SetMousePosition", luasteam_RemotePlay_SetMousePosition);
	add_func(L, "CreateMouseCursor", luasteam_RemotePlay_CreateMouseCursor);
	add_func(L, "SetMouseCursor", luasteam_RemotePlay_SetMouseCursor);
}

void add_RemotePlay_auto(lua_State *L) {
	lua_createtable(L, 0, 15);
	register_RemotePlay_auto(L);
	lua_pushvalue(L, -1);
	RemotePlay_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "RemotePlay");
}

} // namespace luasteam
