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
    lua_getfield(L, -1, "onScreenshotReady");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->m_hLocal);
        lua_setfield(L, -2, "local");
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnScreenshotRequested(ScreenshotRequested_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Screenshots_ref);
    lua_getfield(L, -1, "onScreenshotRequested");
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


// ScreenshotHandle AddScreenshotToLibrary(const char * pchFilename, const char * pchThumbnailFilename, int nWidth, int nHeight);
EXTERN int luasteam_Screenshots_AddScreenshotToLibrary(lua_State *L) {
    const char *pchFilename = luaL_checkstring(L, 1);
    const char *pchThumbnailFilename = luaL_checkstring(L, 2);
    int nWidth = static_cast<int>(luaL_checkint(L, 3));
    int nHeight = static_cast<int>(luaL_checkint(L, 4));
    lua_pushinteger(L, SteamScreenshots()->AddScreenshotToLibrary(pchFilename, pchThumbnailFilename, nWidth, nHeight));
    return 1;
}

// void TriggerScreenshot();
EXTERN int luasteam_Screenshots_TriggerScreenshot(lua_State *L) {
    SteamScreenshots()->TriggerScreenshot();
    return 0;
}

// void HookScreenshots(bool bHook);
EXTERN int luasteam_Screenshots_HookScreenshots(lua_State *L) {
    bool bHook = lua_toboolean(L, 1);
    SteamScreenshots()->HookScreenshots(bHook);
    return 0;
}

// bool SetLocation(ScreenshotHandle hScreenshot, const char * pchLocation);
EXTERN int luasteam_Screenshots_SetLocation(lua_State *L) {
    ScreenshotHandle hScreenshot = static_cast<ScreenshotHandle>(luaL_checkint(L, 1));
    const char *pchLocation = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamScreenshots()->SetLocation(hScreenshot, pchLocation));
    return 1;
}

// bool TagUser(ScreenshotHandle hScreenshot, CSteamID steamID);
EXTERN int luasteam_Screenshots_TagUser(lua_State *L) {
    ScreenshotHandle hScreenshot = static_cast<ScreenshotHandle>(luaL_checkint(L, 1));
    CSteamID steamID(luasteam::checkuint64(L, 2));
    lua_pushboolean(L, SteamScreenshots()->TagUser(hScreenshot, steamID));
    return 1;
}

// bool TagPublishedFile(ScreenshotHandle hScreenshot, PublishedFileId_t unPublishedFileID);
EXTERN int luasteam_Screenshots_TagPublishedFile(lua_State *L) {
    ScreenshotHandle hScreenshot = static_cast<ScreenshotHandle>(luaL_checkint(L, 1));
    PublishedFileId_t unPublishedFileID = luasteam::checkuint64(L, 2);
    lua_pushboolean(L, SteamScreenshots()->TagPublishedFile(hScreenshot, unPublishedFileID));
    return 1;
}

// bool IsScreenshotsHooked();
EXTERN int luasteam_Screenshots_IsScreenshotsHooked(lua_State *L) {
    lua_pushboolean(L, SteamScreenshots()->IsScreenshotsHooked());
    return 1;
}

// ScreenshotHandle AddVRScreenshotToLibrary(EVRScreenshotType eType, const char * pchFilename, const char * pchVRFilename);
EXTERN int luasteam_Screenshots_AddVRScreenshotToLibrary(lua_State *L) {
    EVRScreenshotType eType = static_cast<EVRScreenshotType>(luaL_checkint(L, 1));
    const char *pchFilename = luaL_checkstring(L, 2);
    const char *pchVRFilename = luaL_checkstring(L, 3);
    lua_pushinteger(L, SteamScreenshots()->AddVRScreenshotToLibrary(eType, pchFilename, pchVRFilename));
    return 1;
}

void register_Screenshots_auto(lua_State *L) {
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
    lua_createtable(L, 0, 8);
    register_Screenshots_auto(L);
    lua_pushvalue(L, -1);
    Screenshots_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "Screenshots");
}

} // namespace luasteam
