#include "auto.hpp"

// ScreenshotHandle AddScreenshotToLibrary(const char * pchFilename, const char * pchThumbnailFilename, int nWidth, int nHeight);
EXTERN int luasteam_screenshots_SteamAPI_ISteamScreenshots_AddScreenshotToLibrary(lua_State *L) {
    const char *pchFilename = luaL_checkstring(L, 1);
    const char *pchThumbnailFilename = luaL_checkstring(L, 2);
    int nWidth = static_cast<int>(luaL_checkint(L, 3));
    int nHeight = static_cast<int>(luaL_checkint(L, 4));
    lua_pushinteger(L, SteamScreenshots()->AddScreenshotToLibrary(pchFilename, pchThumbnailFilename, nWidth, nHeight));
    return 1;
}

// void TriggerScreenshot();
EXTERN int luasteam_screenshots_SteamAPI_ISteamScreenshots_TriggerScreenshot(lua_State *L) {
    SteamScreenshots()->TriggerScreenshot();
    return 0;
}

// void HookScreenshots(bool bHook);
EXTERN int luasteam_screenshots_SteamAPI_ISteamScreenshots_HookScreenshots(lua_State *L) {
    bool bHook = lua_toboolean(L, 1);
    SteamScreenshots()->HookScreenshots(bHook);
    return 0;
}

// bool SetLocation(ScreenshotHandle hScreenshot, const char * pchLocation);
EXTERN int luasteam_screenshots_SteamAPI_ISteamScreenshots_SetLocation(lua_State *L) {
    ScreenshotHandle hScreenshot = static_cast<ScreenshotHandle>(luaL_checkint(L, 1));
    const char *pchLocation = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamScreenshots()->SetLocation(hScreenshot, pchLocation));
    return 1;
}

// bool TagUser(ScreenshotHandle hScreenshot, CSteamID steamID);
EXTERN int luasteam_screenshots_SteamAPI_ISteamScreenshots_TagUser(lua_State *L) {
    ScreenshotHandle hScreenshot = static_cast<ScreenshotHandle>(luaL_checkint(L, 1));
    CSteamID steamID(luasteam::checkuint64(L, 2));
    lua_pushboolean(L, SteamScreenshots()->TagUser(hScreenshot, steamID));
    return 1;
}

// bool TagPublishedFile(ScreenshotHandle hScreenshot, PublishedFileId_t unPublishedFileID);
EXTERN int luasteam_screenshots_SteamAPI_ISteamScreenshots_TagPublishedFile(lua_State *L) {
    ScreenshotHandle hScreenshot = static_cast<ScreenshotHandle>(luaL_checkint(L, 1));
    PublishedFileId_t unPublishedFileID = luasteam::checkuint64(L, 2);
    lua_pushboolean(L, SteamScreenshots()->TagPublishedFile(hScreenshot, unPublishedFileID));
    return 1;
}

// bool IsScreenshotsHooked();
EXTERN int luasteam_screenshots_SteamAPI_ISteamScreenshots_IsScreenshotsHooked(lua_State *L) {
    lua_pushboolean(L, SteamScreenshots()->IsScreenshotsHooked());
    return 1;
}

// ScreenshotHandle AddVRScreenshotToLibrary(EVRScreenshotType eType, const char * pchFilename, const char * pchVRFilename);
EXTERN int luasteam_screenshots_SteamAPI_ISteamScreenshots_AddVRScreenshotToLibrary(lua_State *L) {
    EVRScreenshotType eType = static_cast<EVRScreenshotType>(luaL_checkint(L, 1));
    const char *pchFilename = luaL_checkstring(L, 2);
    const char *pchVRFilename = luaL_checkstring(L, 3);
    lua_pushinteger(L, SteamScreenshots()->AddVRScreenshotToLibrary(eType, pchFilename, pchVRFilename));
    return 1;
}

namespace luasteam {

void add_screenshots_auto(lua_State *L) {
    add_func(L, "addScreenshotToLibrary", luasteam_screenshots_SteamAPI_ISteamScreenshots_AddScreenshotToLibrary);
    add_func(L, "triggerScreenshot", luasteam_screenshots_SteamAPI_ISteamScreenshots_TriggerScreenshot);
    add_func(L, "hookScreenshots", luasteam_screenshots_SteamAPI_ISteamScreenshots_HookScreenshots);
    add_func(L, "setLocation", luasteam_screenshots_SteamAPI_ISteamScreenshots_SetLocation);
    add_func(L, "tagUser", luasteam_screenshots_SteamAPI_ISteamScreenshots_TagUser);
    add_func(L, "tagPublishedFile", luasteam_screenshots_SteamAPI_ISteamScreenshots_TagPublishedFile);
    add_func(L, "isScreenshotsHooked", luasteam_screenshots_SteamAPI_ISteamScreenshots_IsScreenshotsHooked);
    add_func(L, "addVRScreenshotToLibrary", luasteam_screenshots_SteamAPI_ISteamScreenshots_AddVRScreenshotToLibrary);
}

} // namespace luasteam
