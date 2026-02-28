#include "auto.hpp"

namespace luasteam {

int Screenshots_ref = LUA_NOREF;

namespace {
class ScreenshotsCallbackListener {
private:
	STEAM_CALLBACK(ScreenshotsCallbackListener, OnScreenshotReady, ScreenshotReady_t);
	STEAM_CALLBACK(ScreenshotsCallbackListener, OnScreenshotRequested, ScreenshotRequested_t);
};
void ScreenshotsCallbackListener::OnScreenshotReady(ScreenshotReady_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Screenshots_ref);
	lua_getfield(L, -1, "OnScreenshotReady");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_ScreenshotReady_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void ScreenshotsCallbackListener::OnScreenshotRequested(ScreenshotRequested_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Screenshots_ref);
	lua_getfield(L, -1, "OnScreenshotRequested");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_ScreenshotRequested_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
ScreenshotsCallbackListener *Screenshots_listener = nullptr;
} // namespace

void init_Screenshots_auto(lua_State *L) { if (Screenshots_listener != nullptr) return; Screenshots_listener = new ScreenshotsCallbackListener(); }
void shutdown_Screenshots_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, Screenshots_ref);
	Screenshots_ref = LUA_NOREF;
	delete Screenshots_listener; Screenshots_listener = nullptr;
}

// In C++:
// ScreenshotHandle WriteScreenshot(const void * pubRGB, uint32 cubRGB, int nWidth, int nHeight);
// In Lua:
// int Screenshots.WriteScreenshot(pubRGB: str, cubRGB: int, nWidth: int, nHeight: int)
static int luasteam_Screenshots_WriteScreenshot(lua_State *L) {
	auto *iface = SteamScreenshots();
	uint32 cubRGB = luaL_checkint(L, 2);
	size_t _len__tmp0;
	const char *_tmp0 = luaL_checklstring(L, 1, &_len__tmp0);
	void *pubRGB = const_cast<void *>(reinterpret_cast<const void *>(_tmp0));
	int nWidth = static_cast<int>(luaL_checkint(L, 3));
	int nHeight = static_cast<int>(luaL_checkint(L, 4));
	ScreenshotHandle __ret = iface->WriteScreenshot(pubRGB, cubRGB, nWidth, nHeight);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// ScreenshotHandle AddScreenshotToLibrary(const char * pchFilename, const char * pchThumbnailFilename, int nWidth, int nHeight);
// In Lua:
// int Screenshots.AddScreenshotToLibrary(pchFilename: str, pchThumbnailFilename: str, nWidth: int, nHeight: int)
static int luasteam_Screenshots_AddScreenshotToLibrary(lua_State *L) {
	auto *iface = SteamScreenshots();
	const char *pchFilename = luaL_checkstring(L, 1);
	const char *pchThumbnailFilename = luaL_checkstring(L, 2);
	int nWidth = static_cast<int>(luaL_checkint(L, 3));
	int nHeight = static_cast<int>(luaL_checkint(L, 4));
	ScreenshotHandle __ret = iface->AddScreenshotToLibrary(pchFilename, pchThumbnailFilename, nWidth, nHeight);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// void TriggerScreenshot();
// In Lua:
// Screenshots.TriggerScreenshot()
static int luasteam_Screenshots_TriggerScreenshot(lua_State *L) {
	auto *iface = SteamScreenshots();
	iface->TriggerScreenshot();
	return 0;
}

// In C++:
// void HookScreenshots(bool bHook);
// In Lua:
// Screenshots.HookScreenshots(bHook: bool)
static int luasteam_Screenshots_HookScreenshots(lua_State *L) {
	auto *iface = SteamScreenshots();
	bool bHook = lua_toboolean(L, 1);
	iface->HookScreenshots(bHook);
	return 0;
}

// In C++:
// bool SetLocation(ScreenshotHandle hScreenshot, const char * pchLocation);
// In Lua:
// bool Screenshots.SetLocation(hScreenshot: int, pchLocation: str)
static int luasteam_Screenshots_SetLocation(lua_State *L) {
	auto *iface = SteamScreenshots();
	ScreenshotHandle hScreenshot = static_cast<ScreenshotHandle>(luaL_checkint(L, 1));
	const char *pchLocation = luaL_checkstring(L, 2);
	bool __ret = iface->SetLocation(hScreenshot, pchLocation);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool TagUser(ScreenshotHandle hScreenshot, CSteamID steamID);
// In Lua:
// bool Screenshots.TagUser(hScreenshot: int, steamID: uint64)
static int luasteam_Screenshots_TagUser(lua_State *L) {
	auto *iface = SteamScreenshots();
	ScreenshotHandle hScreenshot = static_cast<ScreenshotHandle>(luaL_checkint(L, 1));
	CSteamID steamID = CSteamID(luasteam::checkuint64(L, 2));
	bool __ret = iface->TagUser(hScreenshot, steamID);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool TagPublishedFile(ScreenshotHandle hScreenshot, PublishedFileId_t unPublishedFileID);
// In Lua:
// bool Screenshots.TagPublishedFile(hScreenshot: int, unPublishedFileID: uint64)
static int luasteam_Screenshots_TagPublishedFile(lua_State *L) {
	auto *iface = SteamScreenshots();
	ScreenshotHandle hScreenshot = static_cast<ScreenshotHandle>(luaL_checkint(L, 1));
	PublishedFileId_t unPublishedFileID = luasteam::checkuint64(L, 2);
	bool __ret = iface->TagPublishedFile(hScreenshot, unPublishedFileID);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool IsScreenshotsHooked();
// In Lua:
// bool Screenshots.IsScreenshotsHooked()
static int luasteam_Screenshots_IsScreenshotsHooked(lua_State *L) {
	auto *iface = SteamScreenshots();
	bool __ret = iface->IsScreenshotsHooked();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// ScreenshotHandle AddVRScreenshotToLibrary(EVRScreenshotType eType, const char * pchFilename, const char * pchVRFilename);
// In Lua:
// int Screenshots.AddVRScreenshotToLibrary(eType: int, pchFilename: str, pchVRFilename: str)
static int luasteam_Screenshots_AddVRScreenshotToLibrary(lua_State *L) {
	auto *iface = SteamScreenshots();
	EVRScreenshotType eType = static_cast<EVRScreenshotType>(luaL_checkint(L, 1));
	const char *pchFilename = luaL_checkstring(L, 2);
	const char *pchVRFilename = luaL_checkstring(L, 3);
	ScreenshotHandle __ret = iface->AddVRScreenshotToLibrary(eType, pchFilename, pchVRFilename);
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
