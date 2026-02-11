#include "auto.hpp"

// bool Init();
EXTERN int luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_Init(lua_State *L) {
    lua_pushboolean(L, SteamHTMLSurface()->Init());
    return 1;
}

// bool Shutdown();
EXTERN int luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_Shutdown(lua_State *L) {
    lua_pushboolean(L, SteamHTMLSurface()->Shutdown());
    return 1;
}

// SteamAPICall_t CreateBrowser(const char * pchUserAgent, const char * pchUserCSS);
EXTERN int luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_CreateBrowser(lua_State *L) {
    const char *pchUserAgent = luaL_checkstring(L, 1);
    const char *pchUserCSS = luaL_checkstring(L, 2);
    luasteam::pushuint64(L, SteamHTMLSurface()->CreateBrowser(pchUserAgent, pchUserCSS));
    return 1;
}

// void RemoveBrowser(HHTMLBrowser unBrowserHandle);
EXTERN int luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_RemoveBrowser(lua_State *L) {
    HHTMLBrowser unBrowserHandle = luaL_checkint(L, 1);
    SteamHTMLSurface()->RemoveBrowser(unBrowserHandle);
    return 0;
}

// void LoadURL(HHTMLBrowser unBrowserHandle, const char * pchURL, const char * pchPostData);
EXTERN int luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_LoadURL(lua_State *L) {
    HHTMLBrowser unBrowserHandle = luaL_checkint(L, 1);
    const char *pchURL = luaL_checkstring(L, 2);
    const char *pchPostData = luaL_checkstring(L, 3);
    SteamHTMLSurface()->LoadURL(unBrowserHandle, pchURL, pchPostData);
    return 0;
}

// void SetSize(HHTMLBrowser unBrowserHandle, uint32 unWidth, uint32 unHeight);
EXTERN int luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_SetSize(lua_State *L) {
    HHTMLBrowser unBrowserHandle = luaL_checkint(L, 1);
    uint32 unWidth = luaL_checkint(L, 2);
    uint32 unHeight = luaL_checkint(L, 3);
    SteamHTMLSurface()->SetSize(unBrowserHandle, unWidth, unHeight);
    return 0;
}

// void StopLoad(HHTMLBrowser unBrowserHandle);
EXTERN int luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_StopLoad(lua_State *L) {
    HHTMLBrowser unBrowserHandle = luaL_checkint(L, 1);
    SteamHTMLSurface()->StopLoad(unBrowserHandle);
    return 0;
}

// void Reload(HHTMLBrowser unBrowserHandle);
EXTERN int luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_Reload(lua_State *L) {
    HHTMLBrowser unBrowserHandle = luaL_checkint(L, 1);
    SteamHTMLSurface()->Reload(unBrowserHandle);
    return 0;
}

// void GoBack(HHTMLBrowser unBrowserHandle);
EXTERN int luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_GoBack(lua_State *L) {
    HHTMLBrowser unBrowserHandle = luaL_checkint(L, 1);
    SteamHTMLSurface()->GoBack(unBrowserHandle);
    return 0;
}

// void GoForward(HHTMLBrowser unBrowserHandle);
EXTERN int luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_GoForward(lua_State *L) {
    HHTMLBrowser unBrowserHandle = luaL_checkint(L, 1);
    SteamHTMLSurface()->GoForward(unBrowserHandle);
    return 0;
}

// void AddHeader(HHTMLBrowser unBrowserHandle, const char * pchKey, const char * pchValue);
EXTERN int luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_AddHeader(lua_State *L) {
    HHTMLBrowser unBrowserHandle = luaL_checkint(L, 1);
    const char *pchKey = luaL_checkstring(L, 2);
    const char *pchValue = luaL_checkstring(L, 3);
    SteamHTMLSurface()->AddHeader(unBrowserHandle, pchKey, pchValue);
    return 0;
}

// void ExecuteJavascript(HHTMLBrowser unBrowserHandle, const char * pchScript);
EXTERN int luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_ExecuteJavascript(lua_State *L) {
    HHTMLBrowser unBrowserHandle = luaL_checkint(L, 1);
    const char *pchScript = luaL_checkstring(L, 2);
    SteamHTMLSurface()->ExecuteJavascript(unBrowserHandle, pchScript);
    return 0;
}

// void MouseMove(HHTMLBrowser unBrowserHandle, int x, int y);
EXTERN int luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_MouseMove(lua_State *L) {
    HHTMLBrowser unBrowserHandle = luaL_checkint(L, 1);
    int x = luaL_checkint(L, 2);
    int y = luaL_checkint(L, 3);
    SteamHTMLSurface()->MouseMove(unBrowserHandle, x, y);
    return 0;
}

// void MouseWheel(HHTMLBrowser unBrowserHandle, int32 nDelta);
EXTERN int luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_MouseWheel(lua_State *L) {
    HHTMLBrowser unBrowserHandle = luaL_checkint(L, 1);
    int32 nDelta = luaL_checkint(L, 2);
    SteamHTMLSurface()->MouseWheel(unBrowserHandle, nDelta);
    return 0;
}

// void SetHorizontalScroll(HHTMLBrowser unBrowserHandle, uint32 nAbsolutePixelScroll);
EXTERN int luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_SetHorizontalScroll(lua_State *L) {
    HHTMLBrowser unBrowserHandle = luaL_checkint(L, 1);
    uint32 nAbsolutePixelScroll = luaL_checkint(L, 2);
    SteamHTMLSurface()->SetHorizontalScroll(unBrowserHandle, nAbsolutePixelScroll);
    return 0;
}

// void SetVerticalScroll(HHTMLBrowser unBrowserHandle, uint32 nAbsolutePixelScroll);
EXTERN int luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_SetVerticalScroll(lua_State *L) {
    HHTMLBrowser unBrowserHandle = luaL_checkint(L, 1);
    uint32 nAbsolutePixelScroll = luaL_checkint(L, 2);
    SteamHTMLSurface()->SetVerticalScroll(unBrowserHandle, nAbsolutePixelScroll);
    return 0;
}

// void SetKeyFocus(HHTMLBrowser unBrowserHandle, bool bHasKeyFocus);
EXTERN int luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_SetKeyFocus(lua_State *L) {
    HHTMLBrowser unBrowserHandle = luaL_checkint(L, 1);
    bool bHasKeyFocus = lua_toboolean(L, 2);
    SteamHTMLSurface()->SetKeyFocus(unBrowserHandle, bHasKeyFocus);
    return 0;
}

// void ViewSource(HHTMLBrowser unBrowserHandle);
EXTERN int luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_ViewSource(lua_State *L) {
    HHTMLBrowser unBrowserHandle = luaL_checkint(L, 1);
    SteamHTMLSurface()->ViewSource(unBrowserHandle);
    return 0;
}

// void CopyToClipboard(HHTMLBrowser unBrowserHandle);
EXTERN int luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_CopyToClipboard(lua_State *L) {
    HHTMLBrowser unBrowserHandle = luaL_checkint(L, 1);
    SteamHTMLSurface()->CopyToClipboard(unBrowserHandle);
    return 0;
}

// void PasteFromClipboard(HHTMLBrowser unBrowserHandle);
EXTERN int luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_PasteFromClipboard(lua_State *L) {
    HHTMLBrowser unBrowserHandle = luaL_checkint(L, 1);
    SteamHTMLSurface()->PasteFromClipboard(unBrowserHandle);
    return 0;
}

// void Find(HHTMLBrowser unBrowserHandle, const char * pchSearchStr, bool bCurrentlyInFind, bool bReverse);
EXTERN int luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_Find(lua_State *L) {
    HHTMLBrowser unBrowserHandle = luaL_checkint(L, 1);
    const char *pchSearchStr = luaL_checkstring(L, 2);
    bool bCurrentlyInFind = lua_toboolean(L, 3);
    bool bReverse = lua_toboolean(L, 4);
    SteamHTMLSurface()->Find(unBrowserHandle, pchSearchStr, bCurrentlyInFind, bReverse);
    return 0;
}

// void StopFind(HHTMLBrowser unBrowserHandle);
EXTERN int luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_StopFind(lua_State *L) {
    HHTMLBrowser unBrowserHandle = luaL_checkint(L, 1);
    SteamHTMLSurface()->StopFind(unBrowserHandle);
    return 0;
}

// void GetLinkAtPosition(HHTMLBrowser unBrowserHandle, int x, int y);
EXTERN int luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_GetLinkAtPosition(lua_State *L) {
    HHTMLBrowser unBrowserHandle = luaL_checkint(L, 1);
    int x = luaL_checkint(L, 2);
    int y = luaL_checkint(L, 3);
    SteamHTMLSurface()->GetLinkAtPosition(unBrowserHandle, x, y);
    return 0;
}

// void SetCookie(const char * pchHostname, const char * pchKey, const char * pchValue, const char * pchPath, RTime32 nExpires, bool bSecure, bool bHTTPOnly);
EXTERN int luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_SetCookie(lua_State *L) {
    const char *pchHostname = luaL_checkstring(L, 1);
    const char *pchKey = luaL_checkstring(L, 2);
    const char *pchValue = luaL_checkstring(L, 3);
    const char *pchPath = luaL_checkstring(L, 4);
    RTime32 nExpires = luaL_checkint(L, 5);
    bool bSecure = lua_toboolean(L, 6);
    bool bHTTPOnly = lua_toboolean(L, 7);
    SteamHTMLSurface()->SetCookie(pchHostname, pchKey, pchValue, pchPath, nExpires, bSecure, bHTTPOnly);
    return 0;
}

// void SetBackgroundMode(HHTMLBrowser unBrowserHandle, bool bBackgroundMode);
EXTERN int luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_SetBackgroundMode(lua_State *L) {
    HHTMLBrowser unBrowserHandle = luaL_checkint(L, 1);
    bool bBackgroundMode = lua_toboolean(L, 2);
    SteamHTMLSurface()->SetBackgroundMode(unBrowserHandle, bBackgroundMode);
    return 0;
}

// void OpenDeveloperTools(HHTMLBrowser unBrowserHandle);
EXTERN int luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_OpenDeveloperTools(lua_State *L) {
    HHTMLBrowser unBrowserHandle = luaL_checkint(L, 1);
    SteamHTMLSurface()->OpenDeveloperTools(unBrowserHandle);
    return 0;
}

// void AllowStartRequest(HHTMLBrowser unBrowserHandle, bool bAllowed);
EXTERN int luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_AllowStartRequest(lua_State *L) {
    HHTMLBrowser unBrowserHandle = luaL_checkint(L, 1);
    bool bAllowed = lua_toboolean(L, 2);
    SteamHTMLSurface()->AllowStartRequest(unBrowserHandle, bAllowed);
    return 0;
}

// void JSDialogResponse(HHTMLBrowser unBrowserHandle, bool bResult);
EXTERN int luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_JSDialogResponse(lua_State *L) {
    HHTMLBrowser unBrowserHandle = luaL_checkint(L, 1);
    bool bResult = lua_toboolean(L, 2);
    SteamHTMLSurface()->JSDialogResponse(unBrowserHandle, bResult);
    return 0;
}

namespace luasteam {

void add_htmlsurface_auto(lua_State *L) {
    add_func(L, "init", luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_Init);
    add_func(L, "shutdown", luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_Shutdown);
    add_func(L, "createBrowser", luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_CreateBrowser);
    add_func(L, "removeBrowser", luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_RemoveBrowser);
    add_func(L, "loadURL", luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_LoadURL);
    add_func(L, "setSize", luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_SetSize);
    add_func(L, "stopLoad", luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_StopLoad);
    add_func(L, "reload", luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_Reload);
    add_func(L, "goBack", luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_GoBack);
    add_func(L, "goForward", luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_GoForward);
    add_func(L, "addHeader", luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_AddHeader);
    add_func(L, "executeJavascript", luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_ExecuteJavascript);
    add_func(L, "mouseMove", luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_MouseMove);
    add_func(L, "mouseWheel", luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_MouseWheel);
    add_func(L, "setHorizontalScroll", luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_SetHorizontalScroll);
    add_func(L, "setVerticalScroll", luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_SetVerticalScroll);
    add_func(L, "setKeyFocus", luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_SetKeyFocus);
    add_func(L, "viewSource", luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_ViewSource);
    add_func(L, "copyToClipboard", luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_CopyToClipboard);
    add_func(L, "pasteFromClipboard", luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_PasteFromClipboard);
    add_func(L, "find", luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_Find);
    add_func(L, "stopFind", luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_StopFind);
    add_func(L, "getLinkAtPosition", luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_GetLinkAtPosition);
    add_func(L, "setCookie", luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_SetCookie);
    add_func(L, "setBackgroundMode", luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_SetBackgroundMode);
    add_func(L, "openDeveloperTools", luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_OpenDeveloperTools);
    add_func(L, "allowStartRequest", luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_AllowStartRequest);
    add_func(L, "jSDialogResponse", luasteam_htmlsurface_SteamAPI_ISteamHTMLSurface_JSDialogResponse);
}

} // namespace luasteam
