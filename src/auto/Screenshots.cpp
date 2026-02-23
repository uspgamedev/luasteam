#include "auto.hpp"

namespace luasteam {

int Screenshots_ref = LUA_NOREF;

namespace {
class CallbackListener {
private:
	STEAM_CALLBACK(CallbackListener, OnScreenshotReady, ScreenshotReady_t);
	STEAM_CALLBACK(CallbackListener, OnScreenshotRequested, ScreenshotRequested_t);
};
void CallbackListener::OnScreenshotReady(ScreenshotReady_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Screenshots_ref);
	lua_getfield(L, -1, "OnScreenshotReady");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 2);
		lua_pushinteger(L, data->m_hLocal);
		lua_setfield(L, -2, "m_hLocal");
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnScreenshotRequested(ScreenshotRequested_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Screenshots_ref);
	lua_getfield(L, -1, "OnScreenshotRequested");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 0);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
CallbackListener *Screenshots_listener = nullptr;
} // namespace

void init_Screenshots_auto(lua_State *L) { Screenshots_listener = new CallbackListener(); }
void shutdown_Screenshots_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, Screenshots_ref);
	Screenshots_ref = LUA_NOREF;
	delete Screenshots_listener; Screenshots_listener = nullptr;
}

// In C++:
// ScreenshotHandle WriteScreenshot(const void * pubRGB, uint32 cubRGB, int nWidth, int nHeight);
// In Lua:
// int Screenshots.WriteScreenshot(pubRGB: str, cubRGB: int, nWidth: int, nHeight: int)
EXTERN int luasteam_Screenshots_WriteScreenshot(lua_State *L) {
	char *pubRGB = const_cast<char*>(luaL_checkstring(L, 1));
	uint32 cubRGB = static_cast<uint32>(luaL_checkint(L, 2));
	int nWidth = static_cast<int>(luaL_checkint(L, 3));
	int nHeight = static_cast<int>(luaL_checkint(L, 4));
	ScreenshotHandle __ret = SteamScreenshots()->WriteScreenshot(pubRGB, cubRGB, nWidth, nHeight);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// ScreenshotHandle AddScreenshotToLibrary(const char * pchFilename, const char * pchThumbnailFilename, int nWidth, int nHeight);
// In Lua:
// int Screenshots.AddScreenshotToLibrary(pchFilename: str, pchThumbnailFilename: str, nWidth: int, nHeight: int)
EXTERN int luasteam_Screenshots_AddScreenshotToLibrary(lua_State *L) {
	const char *pchFilename = luaL_checkstring(L, 1);
	const char *pchThumbnailFilename = luaL_checkstring(L, 2);
	int nWidth = static_cast<int>(luaL_checkint(L, 3));
	int nHeight = static_cast<int>(luaL_checkint(L, 4));
	ScreenshotHandle __ret = SteamScreenshots()->AddScreenshotToLibrary(pchFilename, pchThumbnailFilename, nWidth, nHeight);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// void TriggerScreenshot();
// In Lua:
// Screenshots.TriggerScreenshot()
EXTERN int luasteam_Screenshots_TriggerScreenshot(lua_State *L) {
	SteamScreenshots()->TriggerScreenshot();
	return 0;
}

// In C++:
// void HookScreenshots(bool bHook);
// In Lua:
// Screenshots.HookScreenshots(bHook: bool)
EXTERN int luasteam_Screenshots_HookScreenshots(lua_State *L) {
	bool bHook = lua_toboolean(L, 1);
	SteamScreenshots()->HookScreenshots(bHook);
	return 0;
}

// In C++:
// bool SetLocation(ScreenshotHandle hScreenshot, const char * pchLocation);
// In Lua:
// bool Screenshots.SetLocation(hScreenshot: int, pchLocation: str)
EXTERN int luasteam_Screenshots_SetLocation(lua_State *L) {
	ScreenshotHandle hScreenshot = static_cast<ScreenshotHandle>(luaL_checkint(L, 1));
	const char *pchLocation = luaL_checkstring(L, 2);
	bool __ret = SteamScreenshots()->SetLocation(hScreenshot, pchLocation);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool TagUser(ScreenshotHandle hScreenshot, CSteamID steamID);
// In Lua:
// bool Screenshots.TagUser(hScreenshot: int, steamID: uint64)
EXTERN int luasteam_Screenshots_TagUser(lua_State *L) {
	ScreenshotHandle hScreenshot = static_cast<ScreenshotHandle>(luaL_checkint(L, 1));
	CSteamID steamID(luasteam::checkuint64(L, 2));
	bool __ret = SteamScreenshots()->TagUser(hScreenshot, steamID);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool TagPublishedFile(ScreenshotHandle hScreenshot, PublishedFileId_t unPublishedFileID);
// In Lua:
// bool Screenshots.TagPublishedFile(hScreenshot: int, unPublishedFileID: uint64)
EXTERN int luasteam_Screenshots_TagPublishedFile(lua_State *L) {
	ScreenshotHandle hScreenshot = static_cast<ScreenshotHandle>(luaL_checkint(L, 1));
	PublishedFileId_t unPublishedFileID(luasteam::checkuint64(L, 2));
	bool __ret = SteamScreenshots()->TagPublishedFile(hScreenshot, unPublishedFileID);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool IsScreenshotsHooked();
// In Lua:
// bool Screenshots.IsScreenshotsHooked()
EXTERN int luasteam_Screenshots_IsScreenshotsHooked(lua_State *L) {
	bool __ret = SteamScreenshots()->IsScreenshotsHooked();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// ScreenshotHandle AddVRScreenshotToLibrary(EVRScreenshotType eType, const char * pchFilename, const char * pchVRFilename);
// In Lua:
// int Screenshots.AddVRScreenshotToLibrary(eType: int, pchFilename: str, pchVRFilename: str)
EXTERN int luasteam_Screenshots_AddVRScreenshotToLibrary(lua_State *L) {
	EVRScreenshotType eType = static_cast<EVRScreenshotType>(luaL_checkint(L, 1));
	const char *pchFilename = luaL_checkstring(L, 2);
	const char *pchVRFilename = luaL_checkstring(L, 3);
	ScreenshotHandle __ret = SteamScreenshots()->AddVRScreenshotToLibrary(eType, pchFilename, pchVRFilename);
	lua_pushinteger(L, __ret);
	return 1;
}

void register_Screenshots_auto(lua_State *L) {
	add_func(L, "WriteScreenshot", luasteam_Screenshots_WriteScreenshot);
	add_func(L, "AddScreenshotToLibrary", luasteam_Screenshots_AddScreenshotToLibrary);
	add_func(L, "TriggerScreenshot", luasteam_Screenshots_TriggerScreenshot);
	add_func(L, "HookScreenshots", luasteam_Screenshots_HookScreenshots);
	add_func(L, "SetLocation", luasteam_Screenshots_SetLocation);
	add_func(L, "TagUser", luasteam_Screenshots_TagUser);
	add_func(L, "TagPublishedFile", luasteam_Screenshots_TagPublishedFile);
	add_func(L, "IsScreenshotsHooked", luasteam_Screenshots_IsScreenshotsHooked);
	add_func(L, "AddVRScreenshotToLibrary", luasteam_Screenshots_AddVRScreenshotToLibrary);
}

void add_Screenshots_auto(lua_State *L) {
	lua_createtable(L, 0, 9);
	register_Screenshots_auto(L);
	lua_pushvalue(L, -1);
	Screenshots_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "Screenshots");
}

} // namespace luasteam
