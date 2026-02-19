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
    lua_getfield(L, -1, "OnHTML_BrowserReady");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "unBrowserHandle");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_NeedsPaint(HTML_NeedsPaint_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "OnHTML_NeedsPaint");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 12);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "unBrowserHandle");
        lua_pushstring(L, reinterpret_cast<const char*>(data->pBGRA));
        lua_setfield(L, -2, "pBGRA");
        lua_pushinteger(L, data->unWide);
        lua_setfield(L, -2, "unWide");
        lua_pushinteger(L, data->unTall);
        lua_setfield(L, -2, "unTall");
        lua_pushinteger(L, data->unUpdateX);
        lua_setfield(L, -2, "unUpdateX");
        lua_pushinteger(L, data->unUpdateY);
        lua_setfield(L, -2, "unUpdateY");
        lua_pushinteger(L, data->unUpdateWide);
        lua_setfield(L, -2, "unUpdateWide");
        lua_pushinteger(L, data->unUpdateTall);
        lua_setfield(L, -2, "unUpdateTall");
        lua_pushinteger(L, data->unScrollX);
        lua_setfield(L, -2, "unScrollX");
        lua_pushinteger(L, data->unScrollY);
        lua_setfield(L, -2, "unScrollY");
        lua_pushnumber(L, data->flPageScale);
        lua_setfield(L, -2, "flPageScale");
        lua_pushinteger(L, data->unPageSerial);
        lua_setfield(L, -2, "unPageSerial");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_StartRequest(HTML_StartRequest_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "OnHTML_StartRequest");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 5);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "unBrowserHandle");
        lua_pushstring(L, reinterpret_cast<const char*>(data->pchURL));
        lua_setfield(L, -2, "pchURL");
        lua_pushstring(L, reinterpret_cast<const char*>(data->pchTarget));
        lua_setfield(L, -2, "pchTarget");
        lua_pushstring(L, reinterpret_cast<const char*>(data->pchPostData));
        lua_setfield(L, -2, "pchPostData");
        lua_pushboolean(L, data->bIsRedirect);
        lua_setfield(L, -2, "bIsRedirect");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_CloseBrowser(HTML_CloseBrowser_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "OnHTML_CloseBrowser");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "unBrowserHandle");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_URLChanged(HTML_URLChanged_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "OnHTML_URLChanged");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 6);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "unBrowserHandle");
        lua_pushstring(L, reinterpret_cast<const char*>(data->pchURL));
        lua_setfield(L, -2, "pchURL");
        lua_pushstring(L, reinterpret_cast<const char*>(data->pchPostData));
        lua_setfield(L, -2, "pchPostData");
        lua_pushboolean(L, data->bIsRedirect);
        lua_setfield(L, -2, "bIsRedirect");
        lua_pushstring(L, reinterpret_cast<const char*>(data->pchPageTitle));
        lua_setfield(L, -2, "pchPageTitle");
        lua_pushboolean(L, data->bNewNavigation);
        lua_setfield(L, -2, "bNewNavigation");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_FinishedRequest(HTML_FinishedRequest_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "OnHTML_FinishedRequest");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "unBrowserHandle");
        lua_pushstring(L, reinterpret_cast<const char*>(data->pchURL));
        lua_setfield(L, -2, "pchURL");
        lua_pushstring(L, reinterpret_cast<const char*>(data->pchPageTitle));
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
    lua_getfield(L, -1, "OnHTML_OpenLinkInNewTab");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "unBrowserHandle");
        lua_pushstring(L, reinterpret_cast<const char*>(data->pchURL));
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
    lua_getfield(L, -1, "OnHTML_ChangedTitle");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "unBrowserHandle");
        lua_pushstring(L, reinterpret_cast<const char*>(data->pchTitle));
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
    lua_getfield(L, -1, "OnHTML_SearchResults");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "unBrowserHandle");
        lua_pushinteger(L, data->unResults);
        lua_setfield(L, -2, "unResults");
        lua_pushinteger(L, data->unCurrentMatch);
        lua_setfield(L, -2, "unCurrentMatch");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_CanGoBackAndForward(HTML_CanGoBackAndForward_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "OnHTML_CanGoBackAndForward");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "unBrowserHandle");
        lua_pushboolean(L, data->bCanGoBack);
        lua_setfield(L, -2, "bCanGoBack");
        lua_pushboolean(L, data->bCanGoForward);
        lua_setfield(L, -2, "bCanGoForward");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_HorizontalScroll(HTML_HorizontalScroll_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "OnHTML_HorizontalScroll");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 6);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "unBrowserHandle");
        lua_pushinteger(L, data->unScrollMax);
        lua_setfield(L, -2, "unScrollMax");
        lua_pushinteger(L, data->unScrollCurrent);
        lua_setfield(L, -2, "unScrollCurrent");
        lua_pushnumber(L, data->flPageScale);
        lua_setfield(L, -2, "flPageScale");
        lua_pushboolean(L, data->bVisible);
        lua_setfield(L, -2, "bVisible");
        lua_pushinteger(L, data->unPageSize);
        lua_setfield(L, -2, "unPageSize");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_VerticalScroll(HTML_VerticalScroll_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "OnHTML_VerticalScroll");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 6);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "unBrowserHandle");
        lua_pushinteger(L, data->unScrollMax);
        lua_setfield(L, -2, "unScrollMax");
        lua_pushinteger(L, data->unScrollCurrent);
        lua_setfield(L, -2, "unScrollCurrent");
        lua_pushnumber(L, data->flPageScale);
        lua_setfield(L, -2, "flPageScale");
        lua_pushboolean(L, data->bVisible);
        lua_setfield(L, -2, "bVisible");
        lua_pushinteger(L, data->unPageSize);
        lua_setfield(L, -2, "unPageSize");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_LinkAtPosition(HTML_LinkAtPosition_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "OnHTML_LinkAtPosition");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 6);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "unBrowserHandle");
        lua_pushinteger(L, data->x);
        lua_setfield(L, -2, "x");
        lua_pushinteger(L, data->y);
        lua_setfield(L, -2, "y");
        lua_pushstring(L, reinterpret_cast<const char*>(data->pchURL));
        lua_setfield(L, -2, "pchURL");
        lua_pushboolean(L, data->bInput);
        lua_setfield(L, -2, "bInput");
        lua_pushboolean(L, data->bLiveLink);
        lua_setfield(L, -2, "bLiveLink");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_JSAlert(HTML_JSAlert_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "OnHTML_JSAlert");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "unBrowserHandle");
        lua_pushstring(L, reinterpret_cast<const char*>(data->pchMessage));
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
    lua_getfield(L, -1, "OnHTML_JSConfirm");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "unBrowserHandle");
        lua_pushstring(L, reinterpret_cast<const char*>(data->pchMessage));
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
    lua_getfield(L, -1, "OnHTML_FileOpenDialog");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "unBrowserHandle");
        lua_pushstring(L, reinterpret_cast<const char*>(data->pchTitle));
        lua_setfield(L, -2, "pchTitle");
        lua_pushstring(L, reinterpret_cast<const char*>(data->pchInitialFile));
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
    lua_getfield(L, -1, "OnHTML_NewWindow");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 7);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "unBrowserHandle");
        lua_pushstring(L, reinterpret_cast<const char*>(data->pchURL));
        lua_setfield(L, -2, "pchURL");
        lua_pushinteger(L, data->unX);
        lua_setfield(L, -2, "unX");
        lua_pushinteger(L, data->unY);
        lua_setfield(L, -2, "unY");
        lua_pushinteger(L, data->unWide);
        lua_setfield(L, -2, "unWide");
        lua_pushinteger(L, data->unTall);
        lua_setfield(L, -2, "unTall");
        lua_pushinteger(L, data->unNewWindow_BrowserHandle_IGNORE);
        lua_setfield(L, -2, "unNewWindow_BrowserHandle_IGNORE");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_SetCursor(HTML_SetCursor_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "OnHTML_SetCursor");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "unBrowserHandle");
        lua_pushinteger(L, data->eMouseCursor);
        lua_setfield(L, -2, "eMouseCursor");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_StatusText(HTML_StatusText_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "OnHTML_StatusText");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "unBrowserHandle");
        lua_pushstring(L, reinterpret_cast<const char*>(data->pchMsg));
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
    lua_getfield(L, -1, "OnHTML_ShowToolTip");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "unBrowserHandle");
        lua_pushstring(L, reinterpret_cast<const char*>(data->pchMsg));
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
    lua_getfield(L, -1, "OnHTML_UpdateToolTip");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "unBrowserHandle");
        lua_pushstring(L, reinterpret_cast<const char*>(data->pchMsg));
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
    lua_getfield(L, -1, "OnHTML_HideToolTip");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "unBrowserHandle");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTML_BrowserRestarted(HTML_BrowserRestarted_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
    lua_getfield(L, -1, "OnHTML_BrowserRestarted");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->unBrowserHandle);
        lua_setfield(L, -2, "unBrowserHandle");
        lua_pushinteger(L, data->unOldBrowserHandle);
        lua_setfield(L, -2, "unOldBrowserHandle");
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
    bool __ret = SteamHTMLSurface()->Init();
    lua_pushboolean(L, __ret);
    return 1;
}

// bool Shutdown();
EXTERN int luasteam_HTMLSurface_Shutdown(lua_State *L) {
    bool __ret = SteamHTMLSurface()->Shutdown();
    lua_pushboolean(L, __ret);
    return 1;
}

// SteamAPICall_t CreateBrowser(const char * pchUserAgent, const char * pchUserCSS);
EXTERN int luasteam_HTMLSurface_CreateBrowser(lua_State *L) {
    const char *pchUserAgent = luaL_checkstring(L, 1);
    const char *pchUserCSS = luaL_checkstring(L, 2);
    SteamAPICall_t __ret = SteamHTMLSurface()->CreateBrowser(pchUserAgent, pchUserCSS);
    luasteam::pushuint64(L, __ret);
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

// void MouseUp(HHTMLBrowser unBrowserHandle, ISteamHTMLSurface::EHTMLMouseButton eMouseButton);
EXTERN int luasteam_HTMLSurface_MouseUp(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    ISteamHTMLSurface::EHTMLMouseButton eMouseButton = static_cast<ISteamHTMLSurface::EHTMLMouseButton>(luaL_checkint(L, 2));
    SteamHTMLSurface()->MouseUp(unBrowserHandle, eMouseButton);
    return 0;
}

// void MouseDown(HHTMLBrowser unBrowserHandle, ISteamHTMLSurface::EHTMLMouseButton eMouseButton);
EXTERN int luasteam_HTMLSurface_MouseDown(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    ISteamHTMLSurface::EHTMLMouseButton eMouseButton = static_cast<ISteamHTMLSurface::EHTMLMouseButton>(luaL_checkint(L, 2));
    SteamHTMLSurface()->MouseDown(unBrowserHandle, eMouseButton);
    return 0;
}

// void MouseDoubleClick(HHTMLBrowser unBrowserHandle, ISteamHTMLSurface::EHTMLMouseButton eMouseButton);
EXTERN int luasteam_HTMLSurface_MouseDoubleClick(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    ISteamHTMLSurface::EHTMLMouseButton eMouseButton = static_cast<ISteamHTMLSurface::EHTMLMouseButton>(luaL_checkint(L, 2));
    SteamHTMLSurface()->MouseDoubleClick(unBrowserHandle, eMouseButton);
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

// void KeyDown(HHTMLBrowser unBrowserHandle, uint32 nNativeKeyCode, ISteamHTMLSurface::EHTMLKeyModifiers eHTMLKeyModifiers, bool bIsSystemKey);
EXTERN int luasteam_HTMLSurface_KeyDown(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    uint32 nNativeKeyCode = static_cast<uint32>(luaL_checkint(L, 2));
    ISteamHTMLSurface::EHTMLKeyModifiers eHTMLKeyModifiers = static_cast<ISteamHTMLSurface::EHTMLKeyModifiers>(luaL_checkint(L, 3));
    bool bIsSystemKey = lua_toboolean(L, 4);
    SteamHTMLSurface()->KeyDown(unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers, bIsSystemKey);
    return 0;
}

// void KeyUp(HHTMLBrowser unBrowserHandle, uint32 nNativeKeyCode, ISteamHTMLSurface::EHTMLKeyModifiers eHTMLKeyModifiers);
EXTERN int luasteam_HTMLSurface_KeyUp(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    uint32 nNativeKeyCode = static_cast<uint32>(luaL_checkint(L, 2));
    ISteamHTMLSurface::EHTMLKeyModifiers eHTMLKeyModifiers = static_cast<ISteamHTMLSurface::EHTMLKeyModifiers>(luaL_checkint(L, 3));
    SteamHTMLSurface()->KeyUp(unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers);
    return 0;
}

// void KeyChar(HHTMLBrowser unBrowserHandle, uint32 cUnicodeChar, ISteamHTMLSurface::EHTMLKeyModifiers eHTMLKeyModifiers);
EXTERN int luasteam_HTMLSurface_KeyChar(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    uint32 cUnicodeChar = static_cast<uint32>(luaL_checkint(L, 2));
    ISteamHTMLSurface::EHTMLKeyModifiers eHTMLKeyModifiers = static_cast<ISteamHTMLSurface::EHTMLKeyModifiers>(luaL_checkint(L, 3));
    SteamHTMLSurface()->KeyChar(unBrowserHandle, cUnicodeChar, eHTMLKeyModifiers);
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

// void SetPageScaleFactor(HHTMLBrowser unBrowserHandle, float flZoom, int nPointX, int nPointY);
EXTERN int luasteam_HTMLSurface_SetPageScaleFactor(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    float flZoom = luaL_checknumber(L, 2);
    int nPointX = static_cast<int>(luaL_checkint(L, 3));
    int nPointY = static_cast<int>(luaL_checkint(L, 4));
    SteamHTMLSurface()->SetPageScaleFactor(unBrowserHandle, flZoom, nPointX, nPointY);
    return 0;
}

// void SetBackgroundMode(HHTMLBrowser unBrowserHandle, bool bBackgroundMode);
EXTERN int luasteam_HTMLSurface_SetBackgroundMode(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    bool bBackgroundMode = lua_toboolean(L, 2);
    SteamHTMLSurface()->SetBackgroundMode(unBrowserHandle, bBackgroundMode);
    return 0;
}

// void SetDPIScalingFactor(HHTMLBrowser unBrowserHandle, float flDPIScaling);
EXTERN int luasteam_HTMLSurface_SetDPIScalingFactor(lua_State *L) {
    HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
    float flDPIScaling = luaL_checknumber(L, 2);
    SteamHTMLSurface()->SetDPIScalingFactor(unBrowserHandle, flDPIScaling);
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
    add_func(L, "MouseUp", luasteam_HTMLSurface_MouseUp);
    add_func(L, "MouseDown", luasteam_HTMLSurface_MouseDown);
    add_func(L, "MouseDoubleClick", luasteam_HTMLSurface_MouseDoubleClick);
    add_func(L, "MouseMove", luasteam_HTMLSurface_MouseMove);
    add_func(L, "MouseWheel", luasteam_HTMLSurface_MouseWheel);
    add_func(L, "KeyDown", luasteam_HTMLSurface_KeyDown);
    add_func(L, "KeyUp", luasteam_HTMLSurface_KeyUp);
    add_func(L, "KeyChar", luasteam_HTMLSurface_KeyChar);
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
    add_func(L, "SetPageScaleFactor", luasteam_HTMLSurface_SetPageScaleFactor);
    add_func(L, "SetBackgroundMode", luasteam_HTMLSurface_SetBackgroundMode);
    add_func(L, "SetDPIScalingFactor", luasteam_HTMLSurface_SetDPIScalingFactor);
    add_func(L, "OpenDeveloperTools", luasteam_HTMLSurface_OpenDeveloperTools);
    add_func(L, "AllowStartRequest", luasteam_HTMLSurface_AllowStartRequest);
    add_func(L, "JSDialogResponse", luasteam_HTMLSurface_JSDialogResponse);
}

void add_HTMLSurface_auto(lua_State *L) {
    lua_createtable(L, 0, 87);
    register_HTMLSurface_auto(L);
    lua_pushinteger(L, ISteamHTMLSurface::eHTMLMouseButton_Left);
    lua_setfield(L, -2, "eHTMLMouseButton_Left");
    lua_pushinteger(L, ISteamHTMLSurface::eHTMLMouseButton_Right);
    lua_setfield(L, -2, "eHTMLMouseButton_Right");
    lua_pushinteger(L, ISteamHTMLSurface::eHTMLMouseButton_Middle);
    lua_setfield(L, -2, "eHTMLMouseButton_Middle");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_User);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_User");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_None);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_None");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_Arrow);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_Arrow");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_IBeam);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_IBeam");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_Hourglass);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_Hourglass");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_WaitArrow);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_WaitArrow");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_Crosshair);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_Crosshair");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_Up);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_Up");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_SizeNW);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_SizeNW");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_SizeSE);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_SizeSE");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_SizeNE);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_SizeNE");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_SizeSW);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_SizeSW");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_SizeW);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_SizeW");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_SizeE);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_SizeE");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_SizeN);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_SizeN");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_SizeS);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_SizeS");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_SizeWE);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_SizeWE");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_SizeNS);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_SizeNS");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_SizeAll);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_SizeAll");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_No);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_No");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_Hand);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_Hand");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_Blank);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_Blank");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_MiddlePan);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_MiddlePan");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_NorthPan);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_NorthPan");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_NorthEastPan);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_NorthEastPan");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_EastPan);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_EastPan");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_SouthEastPan);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_SouthEastPan");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_SouthPan);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_SouthPan");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_SouthWestPan);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_SouthWestPan");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_WestPan);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_WestPan");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_NorthWestPan);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_NorthWestPan");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_Alias);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_Alias");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_Cell);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_Cell");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_ColResize);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_ColResize");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_CopyCur);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_CopyCur");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_VerticalText);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_VerticalText");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_RowResize);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_RowResize");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_ZoomIn);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_ZoomIn");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_ZoomOut);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_ZoomOut");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_Help);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_Help");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_Custom);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_Custom");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_SizeNWSE);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_SizeNWSE");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_SizeNESW);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_SizeNESW");
    lua_pushinteger(L, ISteamHTMLSurface::k_EHTMLMouseCursor_last);
    lua_setfield(L, -2, "k_EHTMLMouseCursor_last");
    lua_pushinteger(L, ISteamHTMLSurface::k_eHTMLKeyModifier_None);
    lua_setfield(L, -2, "k_eHTMLKeyModifier_None");
    lua_pushinteger(L, ISteamHTMLSurface::k_eHTMLKeyModifier_AltDown);
    lua_setfield(L, -2, "k_eHTMLKeyModifier_AltDown");
    lua_pushinteger(L, ISteamHTMLSurface::k_eHTMLKeyModifier_CtrlDown);
    lua_setfield(L, -2, "k_eHTMLKeyModifier_CtrlDown");
    lua_pushinteger(L, ISteamHTMLSurface::k_eHTMLKeyModifier_ShiftDown);
    lua_setfield(L, -2, "k_eHTMLKeyModifier_ShiftDown");
    lua_pushvalue(L, -1);
    HTMLSurface_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "HTMLSurface");
}

} // namespace luasteam
