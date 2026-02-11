#include "auto.hpp"

namespace luasteam {

int HTMLSurface_ref = LUA_NOREF;

namespace {

class CallbackListener {
  private:
    STEAM_CALLBACK(CallbackListener, OnHTML_BrowserReady, HTML_BrowserReady_t);
    STEAM_CALLBACK(CallbackListener, OnHTML_NeedsPaint, HTML_NeedsPaint_t);
    STEAM_CALLBACK(CallbackListener, OnHTML_StartRequest, HTML_StartRequest_t);
    STEAM_CALLBACK(CallbackListener, OnHTML_CloseBrowser, HTML_CloseBrowser_t);
    STEAM_CALLBACK(CallbackListener, OnHTML_URLChanged, HTML_URLChanged_t);
    STEAM_CALLBACK(CallbackListener, OnHTML_FinishedRequest, HTML_FinishedRequest_t);
    STEAM_CALLBACK(CallbackListener, OnHTML_OpenLinkInNewTab, HTML_OpenLinkInNewTab_t);
    STEAM_CALLBACK(CallbackListener, OnHTML_ChangedTitle, HTML_ChangedTitle_t);
    STEAM_CALLBACK(CallbackListener, OnHTML_SearchResults, HTML_SearchResults_t);
    STEAM_CALLBACK(CallbackListener, OnHTML_CanGoBackAndForward, HTML_CanGoBackAndForward_t);
    STEAM_CALLBACK(CallbackListener, OnHTML_HorizontalScroll, HTML_HorizontalScroll_t);
    STEAM_CALLBACK(CallbackListener, OnHTML_VerticalScroll, HTML_VerticalScroll_t);
    STEAM_CALLBACK(CallbackListener, OnHTML_LinkAtPosition, HTML_LinkAtPosition_t);
    STEAM_CALLBACK(CallbackListener, OnHTML_JSAlert, HTML_JSAlert_t);
    STEAM_CALLBACK(CallbackListener, OnHTML_JSConfirm, HTML_JSConfirm_t);
    STEAM_CALLBACK(CallbackListener, OnHTML_FileOpenDialog, HTML_FileOpenDialog_t);
    STEAM_CALLBACK(CallbackListener, OnHTML_NewWindow, HTML_NewWindow_t);
    STEAM_CALLBACK(CallbackListener, OnHTML_SetCursor, HTML_SetCursor_t);
    STEAM_CALLBACK(CallbackListener, OnHTML_StatusText, HTML_StatusText_t);
    STEAM_CALLBACK(CallbackListener, OnHTML_ShowToolTip, HTML_ShowToolTip_t);
    STEAM_CALLBACK(CallbackListener, OnHTML_UpdateToolTip, HTML_UpdateToolTip_t);
    STEAM_CALLBACK(CallbackListener, OnHTML_HideToolTip, HTML_HideToolTip_t);
    STEAM_CALLBACK(CallbackListener, OnHTML_BrowserRestarted, HTML_BrowserRestarted_t);
};

void CallbackListener::OnHTML_BrowserReady(HTML_BrowserReady_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "onHTML_BrowserReady");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "browserHandle");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_NeedsPaint(HTML_NeedsPaint_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "onHTML_NeedsPaint");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 12);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "browserHandle");
        lua_pushstring(L, data->pBGRA);
        lua_setfield(L, -2, "bGRA");
        lua_pushinteger(L, data->unWide);
        lua_setfield(L, -2, "wide");
        lua_pushinteger(L, data->unTall);
        lua_setfield(L, -2, "tall");
        lua_pushinteger(L, data->unUpdateX);
        lua_setfield(L, -2, "updateX");
        lua_pushinteger(L, data->unUpdateY);
        lua_setfield(L, -2, "updateY");
        lua_pushinteger(L, data->unUpdateWide);
        lua_setfield(L, -2, "updateWide");
        lua_pushinteger(L, data->unUpdateTall);
        lua_setfield(L, -2, "updateTall");
        lua_pushinteger(L, data->unScrollX);
        lua_setfield(L, -2, "scrollX");
        lua_pushinteger(L, data->unScrollY);
        lua_setfield(L, -2, "scrollY");
        lua_pushinteger(L, data->unPageSerial);
        lua_setfield(L, -2, "pageSerial");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_StartRequest(HTML_StartRequest_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "onHTML_StartRequest");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 5);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "browserHandle");
        lua_pushstring(L, data->pchURL);
        lua_setfield(L, -2, "pchURL");
        lua_pushstring(L, data->pchTarget);
        lua_setfield(L, -2, "pchTarget");
        lua_pushstring(L, data->pchPostData);
        lua_setfield(L, -2, "pchPostData");
        lua_pushboolean(L, data->bIsRedirect);
        lua_setfield(L, -2, "isRedirect");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_CloseBrowser(HTML_CloseBrowser_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "onHTML_CloseBrowser");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "browserHandle");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_URLChanged(HTML_URLChanged_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "onHTML_URLChanged");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 6);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "browserHandle");
        lua_pushstring(L, data->pchURL);
        lua_setfield(L, -2, "pchURL");
        lua_pushstring(L, data->pchPostData);
        lua_setfield(L, -2, "pchPostData");
        lua_pushboolean(L, data->bIsRedirect);
        lua_setfield(L, -2, "isRedirect");
        lua_pushstring(L, data->pchPageTitle);
        lua_setfield(L, -2, "pchPageTitle");
        lua_pushboolean(L, data->bNewNavigation);
        lua_setfield(L, -2, "newNavigation");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_FinishedRequest(HTML_FinishedRequest_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "onHTML_FinishedRequest");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "browserHandle");
        lua_pushstring(L, data->pchURL);
        lua_setfield(L, -2, "pchURL");
        lua_pushstring(L, data->pchPageTitle);
        lua_setfield(L, -2, "pchPageTitle");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_OpenLinkInNewTab(HTML_OpenLinkInNewTab_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "onHTML_OpenLinkInNewTab");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "browserHandle");
        lua_pushstring(L, data->pchURL);
        lua_setfield(L, -2, "pchURL");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_ChangedTitle(HTML_ChangedTitle_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "onHTML_ChangedTitle");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "browserHandle");
        lua_pushstring(L, data->pchTitle);
        lua_setfield(L, -2, "pchTitle");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_SearchResults(HTML_SearchResults_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "onHTML_SearchResults");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "browserHandle");
        lua_pushinteger(L, data->unResults);
        lua_setfield(L, -2, "results");
        lua_pushinteger(L, data->unCurrentMatch);
        lua_setfield(L, -2, "currentMatch");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_CanGoBackAndForward(HTML_CanGoBackAndForward_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "onHTML_CanGoBackAndForward");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "browserHandle");
        lua_pushboolean(L, data->bCanGoBack);
        lua_setfield(L, -2, "canGoBack");
        lua_pushboolean(L, data->bCanGoForward);
        lua_setfield(L, -2, "canGoForward");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_HorizontalScroll(HTML_HorizontalScroll_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "onHTML_HorizontalScroll");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 6);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "browserHandle");
        lua_pushinteger(L, data->unScrollMax);
        lua_setfield(L, -2, "scrollMax");
        lua_pushinteger(L, data->unScrollCurrent);
        lua_setfield(L, -2, "scrollCurrent");
        lua_pushboolean(L, data->bVisible);
        lua_setfield(L, -2, "visible");
        lua_pushinteger(L, data->unPageSize);
        lua_setfield(L, -2, "pageSize");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_VerticalScroll(HTML_VerticalScroll_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "onHTML_VerticalScroll");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 6);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "browserHandle");
        lua_pushinteger(L, data->unScrollMax);
        lua_setfield(L, -2, "scrollMax");
        lua_pushinteger(L, data->unScrollCurrent);
        lua_setfield(L, -2, "scrollCurrent");
        lua_pushboolean(L, data->bVisible);
        lua_setfield(L, -2, "visible");
        lua_pushinteger(L, data->unPageSize);
        lua_setfield(L, -2, "pageSize");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_LinkAtPosition(HTML_LinkAtPosition_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "onHTML_LinkAtPosition");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 6);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "browserHandle");
        lua_pushinteger(L, data->x);
        lua_setfield(L, -2, "x");
        lua_pushinteger(L, data->y);
        lua_setfield(L, -2, "y");
        lua_pushstring(L, data->pchURL);
        lua_setfield(L, -2, "pchURL");
        lua_pushboolean(L, data->bInput);
        lua_setfield(L, -2, "input");
        lua_pushboolean(L, data->bLiveLink);
        lua_setfield(L, -2, "liveLink");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_JSAlert(HTML_JSAlert_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "onHTML_JSAlert");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "browserHandle");
        lua_pushstring(L, data->pchMessage);
        lua_setfield(L, -2, "pchMessage");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_JSConfirm(HTML_JSConfirm_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "onHTML_JSConfirm");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "browserHandle");
        lua_pushstring(L, data->pchMessage);
        lua_setfield(L, -2, "pchMessage");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_FileOpenDialog(HTML_FileOpenDialog_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "onHTML_FileOpenDialog");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "browserHandle");
        lua_pushstring(L, data->pchTitle);
        lua_setfield(L, -2, "pchTitle");
        lua_pushstring(L, data->pchInitialFile);
        lua_setfield(L, -2, "pchInitialFile");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_NewWindow(HTML_NewWindow_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "onHTML_NewWindow");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 7);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "browserHandle");
        lua_pushstring(L, data->pchURL);
        lua_setfield(L, -2, "pchURL");
        lua_pushinteger(L, data->unX);
        lua_setfield(L, -2, "x");
        lua_pushinteger(L, data->unY);
        lua_setfield(L, -2, "y");
        lua_pushinteger(L, data->unWide);
        lua_setfield(L, -2, "wide");
        lua_pushinteger(L, data->unTall);
        lua_setfield(L, -2, "tall");
        lua_pushinteger(L, data->unNewWindow_BrowserHandle_IGNORE);
        lua_setfield(L, -2, "newWindow_BrowserHandle_IGNORE");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_SetCursor(HTML_SetCursor_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "onHTML_SetCursor");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "browserHandle");
        lua_pushinteger(L, data->eMouseCursor);
        lua_setfield(L, -2, "mouseCursor");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_StatusText(HTML_StatusText_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "onHTML_StatusText");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "browserHandle");
        lua_pushstring(L, data->pchMsg);
        lua_setfield(L, -2, "pchMsg");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_ShowToolTip(HTML_ShowToolTip_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "onHTML_ShowToolTip");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "browserHandle");
        lua_pushstring(L, data->pchMsg);
        lua_setfield(L, -2, "pchMsg");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_UpdateToolTip(HTML_UpdateToolTip_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "onHTML_UpdateToolTip");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "browserHandle");
        lua_pushstring(L, data->pchMsg);
        lua_setfield(L, -2, "pchMsg");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_HideToolTip(HTML_HideToolTip_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "onHTML_HideToolTip");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "browserHandle");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_BrowserRestarted(HTML_BrowserRestarted_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "onHTML_BrowserRestarted");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "browserHandle");
        lua_pushinteger(L, data->unOldBrowserHandle);
        lua_setfield(L, -2, "oldBrowserHandle");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

CallbackListener *HTMLSurface_listener = nullptr;

} // namespace

void init_HTMLSurface_auto(lua_State *L) { HTMLSurface_listener = new CallbackListener(); }

void shutdown_HTMLSurface_auto(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, HTMLSurface_ref);
    HTMLSurface_ref = LUA_NOREF;
    delete HTMLSurface_listener; HTMLSurface_listener = nullptr;
}


// bool Init();
EXTERN int luasteam_HTMLSurface_Init(lua_State *L) {
    lua_pushboolean(L, SteamHTMLSurface()->Init());
    return 1;
}

// bool Shutdown();
EXTERN int luasteam_HTMLSurface_Shutdown(lua_State *L) {
    lua_pushboolean(L, SteamHTMLSurface()->Shutdown());
    return 1;
}

// SteamAPICall_t CreateBrowser(const char * pchUserAgent, const char * pchUserCSS);
EXTERN int luasteam_HTMLSurface_CreateBrowser(lua_State *L) {
    const char *pchUserAgent = luaL_checkstring(L, 1);
    const char *pchUserCSS = luaL_checkstring(L, 2);
    luasteam::pushuint64(L, SteamHTMLSurface()->CreateBrowser(pchUserAgent, pchUserCSS));
    return 1;
}

// void RemoveBrowser(HHTMLBrowser unBrowserHandle);
EXTERN int luasteam_HTMLSurface_RemoveBrowser(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    SteamHTMLSurface()->RemoveBrowser(unBrowserHandle);
    return 0;
}

// void LoadURL(HHTMLBrowser unBrowserHandle, const char * pchURL, const char * pchPostData);
EXTERN int luasteam_HTMLSurface_LoadURL(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    const char *pchURL = luaL_checkstring(L, 2);
    const char *pchPostData = luaL_checkstring(L, 3);
    SteamHTMLSurface()->LoadURL(unBrowserHandle, pchURL, pchPostData);
    return 0;
}

// void SetSize(HHTMLBrowser unBrowserHandle, uint32 unWidth, uint32 unHeight);
EXTERN int luasteam_HTMLSurface_SetSize(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    uint32 unWidth = static_cast<uint32>(luaL_checkint(L, 2));
    uint32 unHeight = static_cast<uint32>(luaL_checkint(L, 3));
    SteamHTMLSurface()->SetSize(unBrowserHandle, unWidth, unHeight);
    return 0;
}

// void StopLoad(HHTMLBrowser unBrowserHandle);
EXTERN int luasteam_HTMLSurface_StopLoad(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    SteamHTMLSurface()->StopLoad(unBrowserHandle);
    return 0;
}

// void Reload(HHTMLBrowser unBrowserHandle);
EXTERN int luasteam_HTMLSurface_Reload(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    SteamHTMLSurface()->Reload(unBrowserHandle);
    return 0;
}

// void GoBack(HHTMLBrowser unBrowserHandle);
EXTERN int luasteam_HTMLSurface_GoBack(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    SteamHTMLSurface()->GoBack(unBrowserHandle);
    return 0;
}

// void GoForward(HHTMLBrowser unBrowserHandle);
EXTERN int luasteam_HTMLSurface_GoForward(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    SteamHTMLSurface()->GoForward(unBrowserHandle);
    return 0;
}

// void AddHeader(HHTMLBrowser unBrowserHandle, const char * pchKey, const char * pchValue);
EXTERN int luasteam_HTMLSurface_AddHeader(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    const char *pchKey = luaL_checkstring(L, 2);
    const char *pchValue = luaL_checkstring(L, 3);
    SteamHTMLSurface()->AddHeader(unBrowserHandle, pchKey, pchValue);
    return 0;
}

// void ExecuteJavascript(HHTMLBrowser unBrowserHandle, const char * pchScript);
EXTERN int luasteam_HTMLSurface_ExecuteJavascript(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    const char *pchScript = luaL_checkstring(L, 2);
    SteamHTMLSurface()->ExecuteJavascript(unBrowserHandle, pchScript);
    return 0;
}

// void MouseMove(HHTMLBrowser unBrowserHandle, int x, int y);
EXTERN int luasteam_HTMLSurface_MouseMove(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    int x = static_cast<int>(luaL_checkint(L, 2));
    int y = static_cast<int>(luaL_checkint(L, 3));
    SteamHTMLSurface()->MouseMove(unBrowserHandle, x, y);
    return 0;
}

// void MouseWheel(HHTMLBrowser unBrowserHandle, int32 nDelta);
EXTERN int luasteam_HTMLSurface_MouseWheel(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    int32 nDelta = static_cast<int32>(luaL_checkint(L, 2));
    SteamHTMLSurface()->MouseWheel(unBrowserHandle, nDelta);
    return 0;
}

// void SetHorizontalScroll(HHTMLBrowser unBrowserHandle, uint32 nAbsolutePixelScroll);
EXTERN int luasteam_HTMLSurface_SetHorizontalScroll(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    uint32 nAbsolutePixelScroll = static_cast<uint32>(luaL_checkint(L, 2));
    SteamHTMLSurface()->SetHorizontalScroll(unBrowserHandle, nAbsolutePixelScroll);
    return 0;
}

// void SetVerticalScroll(HHTMLBrowser unBrowserHandle, uint32 nAbsolutePixelScroll);
EXTERN int luasteam_HTMLSurface_SetVerticalScroll(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    uint32 nAbsolutePixelScroll = static_cast<uint32>(luaL_checkint(L, 2));
    SteamHTMLSurface()->SetVerticalScroll(unBrowserHandle, nAbsolutePixelScroll);
    return 0;
}

// void SetKeyFocus(HHTMLBrowser unBrowserHandle, bool bHasKeyFocus);
EXTERN int luasteam_HTMLSurface_SetKeyFocus(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    bool bHasKeyFocus = lua_toboolean(L, 2);
    SteamHTMLSurface()->SetKeyFocus(unBrowserHandle, bHasKeyFocus);
    return 0;
}

// void ViewSource(HHTMLBrowser unBrowserHandle);
EXTERN int luasteam_HTMLSurface_ViewSource(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    SteamHTMLSurface()->ViewSource(unBrowserHandle);
    return 0;
}

// void CopyToClipboard(HHTMLBrowser unBrowserHandle);
EXTERN int luasteam_HTMLSurface_CopyToClipboard(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    SteamHTMLSurface()->CopyToClipboard(unBrowserHandle);
    return 0;
}

// void PasteFromClipboard(HHTMLBrowser unBrowserHandle);
EXTERN int luasteam_HTMLSurface_PasteFromClipboard(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    SteamHTMLSurface()->PasteFromClipboard(unBrowserHandle);
    return 0;
}

// void Find(HHTMLBrowser unBrowserHandle, const char * pchSearchStr, bool bCurrentlyInFind, bool bReverse);
EXTERN int luasteam_HTMLSurface_Find(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    const char *pchSearchStr = luaL_checkstring(L, 2);
    bool bCurrentlyInFind = lua_toboolean(L, 3);
    bool bReverse = lua_toboolean(L, 4);
    SteamHTMLSurface()->Find(unBrowserHandle, pchSearchStr, bCurrentlyInFind, bReverse);
    return 0;
}

// void StopFind(HHTMLBrowser unBrowserHandle);
EXTERN int luasteam_HTMLSurface_StopFind(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    SteamHTMLSurface()->StopFind(unBrowserHandle);
    return 0;
}

// void GetLinkAtPosition(HHTMLBrowser unBrowserHandle, int x, int y);
EXTERN int luasteam_HTMLSurface_GetLinkAtPosition(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    int x = static_cast<int>(luaL_checkint(L, 2));
    int y = static_cast<int>(luaL_checkint(L, 3));
    SteamHTMLSurface()->GetLinkAtPosition(unBrowserHandle, x, y);
    return 0;
}

// void SetCookie(const char * pchHostname, const char * pchKey, const char * pchValue, const char * pchPath, RTime32 nExpires, bool bSecure, bool bHTTPOnly);
EXTERN int luasteam_HTMLSurface_SetCookie(lua_State *L) {
    const char *pchHostname = luaL_checkstring(L, 1);
    const char *pchKey = luaL_checkstring(L, 2);
    const char *pchValue = luaL_checkstring(L, 3);
    const char *pchPath = luaL_checkstring(L, 4);
    RTime32 nExpires = static_cast<RTime32>(luaL_checkint(L, 5));
    bool bSecure = lua_toboolean(L, 6);
    bool bHTTPOnly = lua_toboolean(L, 7);
    SteamHTMLSurface()->SetCookie(pchHostname, pchKey, pchValue, pchPath, nExpires, bSecure, bHTTPOnly);
    return 0;
}

// void SetBackgroundMode(HHTMLBrowser unBrowserHandle, bool bBackgroundMode);
EXTERN int luasteam_HTMLSurface_SetBackgroundMode(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    bool bBackgroundMode = lua_toboolean(L, 2);
    SteamHTMLSurface()->SetBackgroundMode(unBrowserHandle, bBackgroundMode);
    return 0;
}

// void OpenDeveloperTools(HHTMLBrowser unBrowserHandle);
EXTERN int luasteam_HTMLSurface_OpenDeveloperTools(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    SteamHTMLSurface()->OpenDeveloperTools(unBrowserHandle);
    return 0;
}

// void AllowStartRequest(HHTMLBrowser unBrowserHandle, bool bAllowed);
EXTERN int luasteam_HTMLSurface_AllowStartRequest(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    bool bAllowed = lua_toboolean(L, 2);
    SteamHTMLSurface()->AllowStartRequest(unBrowserHandle, bAllowed);
    return 0;
}

// void JSDialogResponse(HHTMLBrowser unBrowserHandle, bool bResult);
EXTERN int luasteam_HTMLSurface_JSDialogResponse(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    bool bResult = lua_toboolean(L, 2);
    SteamHTMLSurface()->JSDialogResponse(unBrowserHandle, bResult);
    return 0;
}

void register_HTMLSurface_auto(lua_State *L) {
    add_func(L, "Init", luasteam_HTMLSurface_Init);
    add_func(L, "Shutdown", luasteam_HTMLSurface_Shutdown);
    add_func(L, "CreateBrowser", luasteam_HTMLSurface_CreateBrowser);
    add_func(L, "RemoveBrowser", luasteam_HTMLSurface_RemoveBrowser);
    add_func(L, "LoadURL", luasteam_HTMLSurface_LoadURL);
    add_func(L, "SetSize", luasteam_HTMLSurface_SetSize);
    add_func(L, "StopLoad", luasteam_HTMLSurface_StopLoad);
    add_func(L, "Reload", luasteam_HTMLSurface_Reload);
    add_func(L, "GoBack", luasteam_HTMLSurface_GoBack);
    add_func(L, "GoForward", luasteam_HTMLSurface_GoForward);
    add_func(L, "AddHeader", luasteam_HTMLSurface_AddHeader);
    add_func(L, "ExecuteJavascript", luasteam_HTMLSurface_ExecuteJavascript);
    add_func(L, "MouseMove", luasteam_HTMLSurface_MouseMove);
    add_func(L, "MouseWheel", luasteam_HTMLSurface_MouseWheel);
    add_func(L, "SetHorizontalScroll", luasteam_HTMLSurface_SetHorizontalScroll);
    add_func(L, "SetVerticalScroll", luasteam_HTMLSurface_SetVerticalScroll);
    add_func(L, "SetKeyFocus", luasteam_HTMLSurface_SetKeyFocus);
    add_func(L, "ViewSource", luasteam_HTMLSurface_ViewSource);
    add_func(L, "CopyToClipboard", luasteam_HTMLSurface_CopyToClipboard);
    add_func(L, "PasteFromClipboard", luasteam_HTMLSurface_PasteFromClipboard);
    add_func(L, "Find", luasteam_HTMLSurface_Find);
    add_func(L, "StopFind", luasteam_HTMLSurface_StopFind);
    add_func(L, "GetLinkAtPosition", luasteam_HTMLSurface_GetLinkAtPosition);
    add_func(L, "SetCookie", luasteam_HTMLSurface_SetCookie);
    add_func(L, "SetBackgroundMode", luasteam_HTMLSurface_SetBackgroundMode);
    add_func(L, "OpenDeveloperTools", luasteam_HTMLSurface_OpenDeveloperTools);
    add_func(L, "AllowStartRequest", luasteam_HTMLSurface_AllowStartRequest);
    add_func(L, "JSDialogResponse", luasteam_HTMLSurface_JSDialogResponse);
}

void add_HTMLSurface_auto(lua_State *L) {
    lua_createtable(L, 0, 28);
    register_HTMLSurface_auto(L);
    lua_pushvalue(L, -1);
    HTMLSurface_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "HTMLSurface");
}

} // namespace luasteam
