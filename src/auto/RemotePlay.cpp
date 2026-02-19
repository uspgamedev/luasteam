#include "auto.hpp"

namespace luasteam {

int RemotePlay_ref = LUA_NOREF;

namespace {
class CallbackListener {
private:
	STEAM_CALLBACK(CallbackListener, OnSteamRemotePlaySessionConnected, SteamRemotePlaySessionConnected_t);
	STEAM_CALLBACK(CallbackListener, OnSteamRemotePlaySessionDisconnected, SteamRemotePlaySessionDisconnected_t);
	STEAM_CALLBACK(CallbackListener, OnSteamRemotePlayTogetherGuestInvite, SteamRemotePlayTogetherGuestInvite_t);
};
void CallbackListener::OnSteamRemotePlaySessionConnected(SteamRemotePlaySessionConnected_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemotePlay_ref);
	lua_getfield(L, -1, "OnSteamRemotePlaySessionConnected");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 1);
		lua_pushinteger(L, data->m_unSessionID);
		lua_setfield(L, -2, "m_unSessionID");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnSteamRemotePlaySessionDisconnected(SteamRemotePlaySessionDisconnected_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemotePlay_ref);
	lua_getfield(L, -1, "OnSteamRemotePlaySessionDisconnected");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 1);
		lua_pushinteger(L, data->m_unSessionID);
		lua_setfield(L, -2, "m_unSessionID");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnSteamRemotePlayTogetherGuestInvite(SteamRemotePlayTogetherGuestInvite_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::RemotePlay_ref);
	lua_getfield(L, -1, "OnSteamRemotePlayTogetherGuestInvite");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 1);
		lua_pushstring(L, reinterpret_cast<const char*>(data->m_szConnectURL));
		lua_setfield(L, -2, "m_szConnectURL");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
CallbackListener *RemotePlay_listener = nullptr;
} // namespace

void init_RemotePlay_auto(lua_State *L) { RemotePlay_listener = new CallbackListener(); }
void shutdown_RemotePlay_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, RemotePlay_ref);
	RemotePlay_ref = LUA_NOREF;
	delete RemotePlay_listener; RemotePlay_listener = nullptr;
}

// uint32 GetSessionCount();
EXTERN int luasteam_RemotePlay_GetSessionCount(lua_State *L) {
	uint32 __ret = SteamRemotePlay()->GetSessionCount();
	lua_pushinteger(L, __ret);
	return 1;
}

// RemotePlaySessionID_t GetSessionID(int iSessionIndex);
EXTERN int luasteam_RemotePlay_GetSessionID(lua_State *L) {
	int iSessionIndex = static_cast<int>(luaL_checkint(L, 1));
	RemotePlaySessionID_t __ret = SteamRemotePlay()->GetSessionID(iSessionIndex);
	lua_pushinteger(L, __ret);
	return 1;
}

// CSteamID GetSessionSteamID(RemotePlaySessionID_t unSessionID);
EXTERN int luasteam_RemotePlay_GetSessionSteamID(lua_State *L) {
	RemotePlaySessionID_t unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, 1));
	CSteamID __ret = SteamRemotePlay()->GetSessionSteamID(unSessionID);
	luasteam::pushuint64(L, __ret.ConvertToUint64());
	return 1;
}

// const char * GetSessionClientName(RemotePlaySessionID_t unSessionID);
EXTERN int luasteam_RemotePlay_GetSessionClientName(lua_State *L) {
	RemotePlaySessionID_t unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, 1));
	const char * __ret = SteamRemotePlay()->GetSessionClientName(unSessionID);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// ESteamDeviceFormFactor GetSessionClientFormFactor(RemotePlaySessionID_t unSessionID);
EXTERN int luasteam_RemotePlay_GetSessionClientFormFactor(lua_State *L) {
	RemotePlaySessionID_t unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, 1));
	ESteamDeviceFormFactor __ret = SteamRemotePlay()->GetSessionClientFormFactor(unSessionID);
	lua_pushinteger(L, __ret);
	return 1;
}

// bool BGetSessionClientResolution(RemotePlaySessionID_t unSessionID, int * pnResolutionX, int * pnResolutionY);
EXTERN int luasteam_RemotePlay_BGetSessionClientResolution(lua_State *L) {
	RemotePlaySessionID_t unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, 1));
	int pnResolutionX;
	int pnResolutionY;
	bool __ret = SteamRemotePlay()->BGetSessionClientResolution(unSessionID, &pnResolutionX, &pnResolutionY);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pnResolutionX);
	lua_pushinteger(L, pnResolutionY);
	return 3;
}

// bool ShowRemotePlayTogetherUI();
EXTERN int luasteam_RemotePlay_ShowRemotePlayTogetherUI(lua_State *L) {
	bool __ret = SteamRemotePlay()->ShowRemotePlayTogetherUI();
	lua_pushboolean(L, __ret);
	return 1;
}

// bool BSendRemotePlayTogetherInvite(CSteamID steamIDFriend);
EXTERN int luasteam_RemotePlay_BSendRemotePlayTogetherInvite(lua_State *L) {
	CSteamID steamIDFriend(luasteam::checkuint64(L, 1));
	bool __ret = SteamRemotePlay()->BSendRemotePlayTogetherInvite(steamIDFriend);
	lua_pushboolean(L, __ret);
	return 1;
}

// bool BEnableRemotePlayTogetherDirectInput();
EXTERN int luasteam_RemotePlay_BEnableRemotePlayTogetherDirectInput(lua_State *L) {
	bool __ret = SteamRemotePlay()->BEnableRemotePlayTogetherDirectInput();
	lua_pushboolean(L, __ret);
	return 1;
}

// void DisableRemotePlayTogetherDirectInput();
EXTERN int luasteam_RemotePlay_DisableRemotePlayTogetherDirectInput(lua_State *L) {
	SteamRemotePlay()->DisableRemotePlayTogetherDirectInput();
	return 0;
}

// void SetMouseVisibility(RemotePlaySessionID_t unSessionID, bool bVisible);
EXTERN int luasteam_RemotePlay_SetMouseVisibility(lua_State *L) {
	RemotePlaySessionID_t unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, 1));
	bool bVisible = lua_toboolean(L, 2);
	SteamRemotePlay()->SetMouseVisibility(unSessionID, bVisible);
	return 0;
}

// void SetMousePosition(RemotePlaySessionID_t unSessionID, float flNormalizedX, float flNormalizedY);
EXTERN int luasteam_RemotePlay_SetMousePosition(lua_State *L) {
	RemotePlaySessionID_t unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, 1));
	float flNormalizedX = luaL_checknumber(L, 2);
	float flNormalizedY = luaL_checknumber(L, 3);
	SteamRemotePlay()->SetMousePosition(unSessionID, flNormalizedX, flNormalizedY);
	return 0;
}

// RemotePlayCursorID_t CreateMouseCursor(int nWidth, int nHeight, int nHotX, int nHotY, const void * pBGRA, int nPitch);
EXTERN int luasteam_RemotePlay_CreateMouseCursor(lua_State *L) {
	int nWidth = static_cast<int>(luaL_checkint(L, 1));
	int nHeight = static_cast<int>(luaL_checkint(L, 2));
	int nHotX = static_cast<int>(luaL_checkint(L, 3));
	int nHotY = static_cast<int>(luaL_checkint(L, 4));
	const char *pBGRA = luaL_checkstring(L, 5);
	int nPitch = static_cast<int>(luaL_checkint(L, 6));
	RemotePlayCursorID_t __ret = SteamRemotePlay()->CreateMouseCursor(nWidth, nHeight, nHotX, nHotY, pBGRA, nPitch);
	lua_pushinteger(L, __ret);
	return 1;
}

// void SetMouseCursor(RemotePlaySessionID_t unSessionID, RemotePlayCursorID_t unCursorID);
EXTERN int luasteam_RemotePlay_SetMouseCursor(lua_State *L) {
	RemotePlaySessionID_t unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, 1));
	RemotePlayCursorID_t unCursorID = static_cast<RemotePlayCursorID_t>(luaL_checkint(L, 2));
	SteamRemotePlay()->SetMouseCursor(unSessionID, unCursorID);
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
	add_func(L, "SetMouseVisibility", luasteam_RemotePlay_SetMouseVisibility);
	add_func(L, "SetMousePosition", luasteam_RemotePlay_SetMousePosition);
	add_func(L, "CreateMouseCursor", luasteam_RemotePlay_CreateMouseCursor);
	add_func(L, "SetMouseCursor", luasteam_RemotePlay_SetMouseCursor);
}

void add_RemotePlay_auto(lua_State *L) {
	lua_createtable(L, 0, 14);
	register_RemotePlay_auto(L);
	lua_pushvalue(L, -1);
	RemotePlay_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "RemotePlay");
}

} // namespace luasteam
