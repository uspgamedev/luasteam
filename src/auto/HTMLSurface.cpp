#include "auto.hpp"

namespace luasteam {

int HTMLSurface_ref = LUA_NOREF;

namespace {
class HTMLSurfaceCallbackListener {
private:
	STEAM_CALLBACK(HTMLSurfaceCallbackListener, OnHTML_BrowserReady, HTML_BrowserReady_t);
	STEAM_CALLBACK(HTMLSurfaceCallbackListener, OnHTML_NeedsPaint, HTML_NeedsPaint_t);
	STEAM_CALLBACK(HTMLSurfaceCallbackListener, OnHTML_StartRequest, HTML_StartRequest_t);
	STEAM_CALLBACK(HTMLSurfaceCallbackListener, OnHTML_CloseBrowser, HTML_CloseBrowser_t);
	STEAM_CALLBACK(HTMLSurfaceCallbackListener, OnHTML_URLChanged, HTML_URLChanged_t);
	STEAM_CALLBACK(HTMLSurfaceCallbackListener, OnHTML_FinishedRequest, HTML_FinishedRequest_t);
	STEAM_CALLBACK(HTMLSurfaceCallbackListener, OnHTML_OpenLinkInNewTab, HTML_OpenLinkInNewTab_t);
	STEAM_CALLBACK(HTMLSurfaceCallbackListener, OnHTML_ChangedTitle, HTML_ChangedTitle_t);
	STEAM_CALLBACK(HTMLSurfaceCallbackListener, OnHTML_SearchResults, HTML_SearchResults_t);
	STEAM_CALLBACK(HTMLSurfaceCallbackListener, OnHTML_CanGoBackAndForward, HTML_CanGoBackAndForward_t);
	STEAM_CALLBACK(HTMLSurfaceCallbackListener, OnHTML_HorizontalScroll, HTML_HorizontalScroll_t);
	STEAM_CALLBACK(HTMLSurfaceCallbackListener, OnHTML_VerticalScroll, HTML_VerticalScroll_t);
	STEAM_CALLBACK(HTMLSurfaceCallbackListener, OnHTML_LinkAtPosition, HTML_LinkAtPosition_t);
	STEAM_CALLBACK(HTMLSurfaceCallbackListener, OnHTML_JSAlert, HTML_JSAlert_t);
	STEAM_CALLBACK(HTMLSurfaceCallbackListener, OnHTML_JSConfirm, HTML_JSConfirm_t);
	STEAM_CALLBACK(HTMLSurfaceCallbackListener, OnHTML_FileOpenDialog, HTML_FileOpenDialog_t);
	STEAM_CALLBACK(HTMLSurfaceCallbackListener, OnHTML_NewWindow, HTML_NewWindow_t);
	STEAM_CALLBACK(HTMLSurfaceCallbackListener, OnHTML_SetCursor, HTML_SetCursor_t);
	STEAM_CALLBACK(HTMLSurfaceCallbackListener, OnHTML_StatusText, HTML_StatusText_t);
	STEAM_CALLBACK(HTMLSurfaceCallbackListener, OnHTML_ShowToolTip, HTML_ShowToolTip_t);
	STEAM_CALLBACK(HTMLSurfaceCallbackListener, OnHTML_UpdateToolTip, HTML_UpdateToolTip_t);
	STEAM_CALLBACK(HTMLSurfaceCallbackListener, OnHTML_HideToolTip, HTML_HideToolTip_t);
	STEAM_CALLBACK(HTMLSurfaceCallbackListener, OnHTML_BrowserRestarted, HTML_BrowserRestarted_t);
};
void HTMLSurfaceCallbackListener::OnHTML_BrowserReady(HTML_BrowserReady_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
	lua_getfield(L, -1, "OnHTML_BrowserReady");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_HTML_BrowserReady_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void HTMLSurfaceCallbackListener::OnHTML_NeedsPaint(HTML_NeedsPaint_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
	lua_getfield(L, -1, "OnHTML_NeedsPaint");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_HTML_NeedsPaint_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void HTMLSurfaceCallbackListener::OnHTML_StartRequest(HTML_StartRequest_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
	lua_getfield(L, -1, "OnHTML_StartRequest");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_HTML_StartRequest_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void HTMLSurfaceCallbackListener::OnHTML_CloseBrowser(HTML_CloseBrowser_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
	lua_getfield(L, -1, "OnHTML_CloseBrowser");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_HTML_CloseBrowser_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void HTMLSurfaceCallbackListener::OnHTML_URLChanged(HTML_URLChanged_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
	lua_getfield(L, -1, "OnHTML_URLChanged");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_HTML_URLChanged_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void HTMLSurfaceCallbackListener::OnHTML_FinishedRequest(HTML_FinishedRequest_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
	lua_getfield(L, -1, "OnHTML_FinishedRequest");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_HTML_FinishedRequest_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void HTMLSurfaceCallbackListener::OnHTML_OpenLinkInNewTab(HTML_OpenLinkInNewTab_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
	lua_getfield(L, -1, "OnHTML_OpenLinkInNewTab");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_HTML_OpenLinkInNewTab_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void HTMLSurfaceCallbackListener::OnHTML_ChangedTitle(HTML_ChangedTitle_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
	lua_getfield(L, -1, "OnHTML_ChangedTitle");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_HTML_ChangedTitle_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void HTMLSurfaceCallbackListener::OnHTML_SearchResults(HTML_SearchResults_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
	lua_getfield(L, -1, "OnHTML_SearchResults");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_HTML_SearchResults_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void HTMLSurfaceCallbackListener::OnHTML_CanGoBackAndForward(HTML_CanGoBackAndForward_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
	lua_getfield(L, -1, "OnHTML_CanGoBackAndForward");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_HTML_CanGoBackAndForward_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void HTMLSurfaceCallbackListener::OnHTML_HorizontalScroll(HTML_HorizontalScroll_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
	lua_getfield(L, -1, "OnHTML_HorizontalScroll");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_HTML_HorizontalScroll_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void HTMLSurfaceCallbackListener::OnHTML_VerticalScroll(HTML_VerticalScroll_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
	lua_getfield(L, -1, "OnHTML_VerticalScroll");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_HTML_VerticalScroll_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void HTMLSurfaceCallbackListener::OnHTML_LinkAtPosition(HTML_LinkAtPosition_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
	lua_getfield(L, -1, "OnHTML_LinkAtPosition");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_HTML_LinkAtPosition_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void HTMLSurfaceCallbackListener::OnHTML_JSAlert(HTML_JSAlert_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
	lua_getfield(L, -1, "OnHTML_JSAlert");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_HTML_JSAlert_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void HTMLSurfaceCallbackListener::OnHTML_JSConfirm(HTML_JSConfirm_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
	lua_getfield(L, -1, "OnHTML_JSConfirm");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_HTML_JSConfirm_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void HTMLSurfaceCallbackListener::OnHTML_FileOpenDialog(HTML_FileOpenDialog_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
	lua_getfield(L, -1, "OnHTML_FileOpenDialog");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_HTML_FileOpenDialog_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void HTMLSurfaceCallbackListener::OnHTML_NewWindow(HTML_NewWindow_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
	lua_getfield(L, -1, "OnHTML_NewWindow");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_HTML_NewWindow_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void HTMLSurfaceCallbackListener::OnHTML_SetCursor(HTML_SetCursor_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
	lua_getfield(L, -1, "OnHTML_SetCursor");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_HTML_SetCursor_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void HTMLSurfaceCallbackListener::OnHTML_StatusText(HTML_StatusText_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
	lua_getfield(L, -1, "OnHTML_StatusText");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_HTML_StatusText_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void HTMLSurfaceCallbackListener::OnHTML_ShowToolTip(HTML_ShowToolTip_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
	lua_getfield(L, -1, "OnHTML_ShowToolTip");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_HTML_ShowToolTip_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void HTMLSurfaceCallbackListener::OnHTML_UpdateToolTip(HTML_UpdateToolTip_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
	lua_getfield(L, -1, "OnHTML_UpdateToolTip");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_HTML_UpdateToolTip_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void HTMLSurfaceCallbackListener::OnHTML_HideToolTip(HTML_HideToolTip_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
	lua_getfield(L, -1, "OnHTML_HideToolTip");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_HTML_HideToolTip_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void HTMLSurfaceCallbackListener::OnHTML_BrowserRestarted(HTML_BrowserRestarted_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTMLSurface_ref);
	lua_getfield(L, -1, "OnHTML_BrowserRestarted");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_HTML_BrowserRestarted_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
HTMLSurfaceCallbackListener *HTMLSurface_listener = nullptr;
} // namespace

void init_HTMLSurface_auto(lua_State *L) { HTMLSurface_listener = new HTMLSurfaceCallbackListener(); }
void shutdown_HTMLSurface_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, HTMLSurface_ref);
	HTMLSurface_ref = LUA_NOREF;
	delete HTMLSurface_listener; HTMLSurface_listener = nullptr;
}

template <> void CallResultListener<HTML_BrowserReady_t>::Result(HTML_BrowserReady_t *data, bool io_fail) {
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) {
		luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);
		delete this;
		return;
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, callback_ref);
	luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);
	if (io_fail || data == nullptr) {
		lua_pushnil(L);
	} else {
		lua_createtable(L, 0, 1);
		lua_pushinteger(L, data->unBrowserHandle);
		lua_setfield(L, -2, "unBrowserHandle");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

// In C++:
// bool Init();
// In Lua:
// bool HTMLSurface.Init()
static int luasteam_HTMLSurface_Init(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	bool __ret = iface->Init();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool Shutdown();
// In Lua:
// bool HTMLSurface.Shutdown()
static int luasteam_HTMLSurface_Shutdown(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	bool __ret = iface->Shutdown();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t CreateBrowser(const char * pchUserAgent, const char * pchUserCSS);
// In Lua:
// uint64 HTMLSurface.CreateBrowser(pchUserAgent: str, pchUserCSS: str, callback: function)
static int luasteam_HTMLSurface_CreateBrowser(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	const char *pchUserAgent = luaL_checkstring(L, 1);
	const char *pchUserCSS = luaL_checkstring(L, 2);
	SteamAPICall_t __ret = iface->CreateBrowser(pchUserAgent, pchUserCSS);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<HTML_BrowserReady_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<HTML_BrowserReady_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// void RemoveBrowser(HHTMLBrowser unBrowserHandle);
// In Lua:
// HTMLSurface.RemoveBrowser(unBrowserHandle: int)
static int luasteam_HTMLSurface_RemoveBrowser(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	iface->RemoveBrowser(unBrowserHandle);
	return 0;
}

// In C++:
// void LoadURL(HHTMLBrowser unBrowserHandle, const char * pchURL, const char * pchPostData);
// In Lua:
// HTMLSurface.LoadURL(unBrowserHandle: int, pchURL: str, pchPostData: str)
static int luasteam_HTMLSurface_LoadURL(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	const char *pchURL = luaL_checkstring(L, 2);
	const char *pchPostData = luaL_checkstring(L, 3);
	iface->LoadURL(unBrowserHandle, pchURL, pchPostData);
	return 0;
}

// In C++:
// void SetSize(HHTMLBrowser unBrowserHandle, uint32 unWidth, uint32 unHeight);
// In Lua:
// HTMLSurface.SetSize(unBrowserHandle: int, unWidth: int, unHeight: int)
static int luasteam_HTMLSurface_SetSize(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	uint32 unWidth = static_cast<uint32>(luaL_checkint(L, 2));
	uint32 unHeight = static_cast<uint32>(luaL_checkint(L, 3));
	iface->SetSize(unBrowserHandle, unWidth, unHeight);
	return 0;
}

// In C++:
// void StopLoad(HHTMLBrowser unBrowserHandle);
// In Lua:
// HTMLSurface.StopLoad(unBrowserHandle: int)
static int luasteam_HTMLSurface_StopLoad(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	iface->StopLoad(unBrowserHandle);
	return 0;
}

// In C++:
// void Reload(HHTMLBrowser unBrowserHandle);
// In Lua:
// HTMLSurface.Reload(unBrowserHandle: int)
static int luasteam_HTMLSurface_Reload(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	iface->Reload(unBrowserHandle);
	return 0;
}

// In C++:
// void GoBack(HHTMLBrowser unBrowserHandle);
// In Lua:
// HTMLSurface.GoBack(unBrowserHandle: int)
static int luasteam_HTMLSurface_GoBack(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	iface->GoBack(unBrowserHandle);
	return 0;
}

// In C++:
// void GoForward(HHTMLBrowser unBrowserHandle);
// In Lua:
// HTMLSurface.GoForward(unBrowserHandle: int)
static int luasteam_HTMLSurface_GoForward(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	iface->GoForward(unBrowserHandle);
	return 0;
}

// In C++:
// void AddHeader(HHTMLBrowser unBrowserHandle, const char * pchKey, const char * pchValue);
// In Lua:
// HTMLSurface.AddHeader(unBrowserHandle: int, pchKey: str, pchValue: str)
static int luasteam_HTMLSurface_AddHeader(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	const char *pchKey = luaL_checkstring(L, 2);
	const char *pchValue = luaL_checkstring(L, 3);
	iface->AddHeader(unBrowserHandle, pchKey, pchValue);
	return 0;
}

// In C++:
// void ExecuteJavascript(HHTMLBrowser unBrowserHandle, const char * pchScript);
// In Lua:
// HTMLSurface.ExecuteJavascript(unBrowserHandle: int, pchScript: str)
static int luasteam_HTMLSurface_ExecuteJavascript(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	const char *pchScript = luaL_checkstring(L, 2);
	iface->ExecuteJavascript(unBrowserHandle, pchScript);
	return 0;
}

// In C++:
// void MouseUp(HHTMLBrowser unBrowserHandle, ISteamHTMLSurface::EHTMLMouseButton eMouseButton);
// In Lua:
// HTMLSurface.MouseUp(unBrowserHandle: int, eMouseButton: int)
static int luasteam_HTMLSurface_MouseUp(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	ISteamHTMLSurface::EHTMLMouseButton eMouseButton = static_cast<ISteamHTMLSurface::EHTMLMouseButton>(luaL_checkint(L, 2));
	iface->MouseUp(unBrowserHandle, eMouseButton);
	return 0;
}

// In C++:
// void MouseDown(HHTMLBrowser unBrowserHandle, ISteamHTMLSurface::EHTMLMouseButton eMouseButton);
// In Lua:
// HTMLSurface.MouseDown(unBrowserHandle: int, eMouseButton: int)
static int luasteam_HTMLSurface_MouseDown(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	ISteamHTMLSurface::EHTMLMouseButton eMouseButton = static_cast<ISteamHTMLSurface::EHTMLMouseButton>(luaL_checkint(L, 2));
	iface->MouseDown(unBrowserHandle, eMouseButton);
	return 0;
}

// In C++:
// void MouseDoubleClick(HHTMLBrowser unBrowserHandle, ISteamHTMLSurface::EHTMLMouseButton eMouseButton);
// In Lua:
// HTMLSurface.MouseDoubleClick(unBrowserHandle: int, eMouseButton: int)
static int luasteam_HTMLSurface_MouseDoubleClick(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	ISteamHTMLSurface::EHTMLMouseButton eMouseButton = static_cast<ISteamHTMLSurface::EHTMLMouseButton>(luaL_checkint(L, 2));
	iface->MouseDoubleClick(unBrowserHandle, eMouseButton);
	return 0;
}

// In C++:
// void MouseMove(HHTMLBrowser unBrowserHandle, int x, int y);
// In Lua:
// HTMLSurface.MouseMove(unBrowserHandle: int, x: int, y: int)
static int luasteam_HTMLSurface_MouseMove(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	int x = static_cast<int>(luaL_checkint(L, 2));
	int y = static_cast<int>(luaL_checkint(L, 3));
	iface->MouseMove(unBrowserHandle, x, y);
	return 0;
}

// In C++:
// void MouseWheel(HHTMLBrowser unBrowserHandle, int32 nDelta);
// In Lua:
// HTMLSurface.MouseWheel(unBrowserHandle: int, nDelta: int)
static int luasteam_HTMLSurface_MouseWheel(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	int32 nDelta = static_cast<int32>(luaL_checkint(L, 2));
	iface->MouseWheel(unBrowserHandle, nDelta);
	return 0;
}

// In C++:
// void KeyDown(HHTMLBrowser unBrowserHandle, uint32 nNativeKeyCode, ISteamHTMLSurface::EHTMLKeyModifiers eHTMLKeyModifiers, bool bIsSystemKey);
// In Lua:
// HTMLSurface.KeyDown(unBrowserHandle: int, nNativeKeyCode: int, eHTMLKeyModifiers: int, bIsSystemKey: bool)
static int luasteam_HTMLSurface_KeyDown(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	uint32 nNativeKeyCode = static_cast<uint32>(luaL_checkint(L, 2));
	ISteamHTMLSurface::EHTMLKeyModifiers eHTMLKeyModifiers = static_cast<ISteamHTMLSurface::EHTMLKeyModifiers>(luaL_checkint(L, 3));
	bool bIsSystemKey = lua_toboolean(L, 4);
	iface->KeyDown(unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers, bIsSystemKey);
	return 0;
}

// In C++:
// void KeyUp(HHTMLBrowser unBrowserHandle, uint32 nNativeKeyCode, ISteamHTMLSurface::EHTMLKeyModifiers eHTMLKeyModifiers);
// In Lua:
// HTMLSurface.KeyUp(unBrowserHandle: int, nNativeKeyCode: int, eHTMLKeyModifiers: int)
static int luasteam_HTMLSurface_KeyUp(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	uint32 nNativeKeyCode = static_cast<uint32>(luaL_checkint(L, 2));
	ISteamHTMLSurface::EHTMLKeyModifiers eHTMLKeyModifiers = static_cast<ISteamHTMLSurface::EHTMLKeyModifiers>(luaL_checkint(L, 3));
	iface->KeyUp(unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers);
	return 0;
}

// In C++:
// void KeyChar(HHTMLBrowser unBrowserHandle, uint32 cUnicodeChar, ISteamHTMLSurface::EHTMLKeyModifiers eHTMLKeyModifiers);
// In Lua:
// HTMLSurface.KeyChar(unBrowserHandle: int, cUnicodeChar: int, eHTMLKeyModifiers: int)
static int luasteam_HTMLSurface_KeyChar(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	uint32 cUnicodeChar = static_cast<uint32>(luaL_checkint(L, 2));
	ISteamHTMLSurface::EHTMLKeyModifiers eHTMLKeyModifiers = static_cast<ISteamHTMLSurface::EHTMLKeyModifiers>(luaL_checkint(L, 3));
	iface->KeyChar(unBrowserHandle, cUnicodeChar, eHTMLKeyModifiers);
	return 0;
}

// In C++:
// void SetHorizontalScroll(HHTMLBrowser unBrowserHandle, uint32 nAbsolutePixelScroll);
// In Lua:
// HTMLSurface.SetHorizontalScroll(unBrowserHandle: int, nAbsolutePixelScroll: int)
static int luasteam_HTMLSurface_SetHorizontalScroll(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	uint32 nAbsolutePixelScroll = static_cast<uint32>(luaL_checkint(L, 2));
	iface->SetHorizontalScroll(unBrowserHandle, nAbsolutePixelScroll);
	return 0;
}

// In C++:
// void SetVerticalScroll(HHTMLBrowser unBrowserHandle, uint32 nAbsolutePixelScroll);
// In Lua:
// HTMLSurface.SetVerticalScroll(unBrowserHandle: int, nAbsolutePixelScroll: int)
static int luasteam_HTMLSurface_SetVerticalScroll(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	uint32 nAbsolutePixelScroll = static_cast<uint32>(luaL_checkint(L, 2));
	iface->SetVerticalScroll(unBrowserHandle, nAbsolutePixelScroll);
	return 0;
}

// In C++:
// void SetKeyFocus(HHTMLBrowser unBrowserHandle, bool bHasKeyFocus);
// In Lua:
// HTMLSurface.SetKeyFocus(unBrowserHandle: int, bHasKeyFocus: bool)
static int luasteam_HTMLSurface_SetKeyFocus(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	bool bHasKeyFocus = lua_toboolean(L, 2);
	iface->SetKeyFocus(unBrowserHandle, bHasKeyFocus);
	return 0;
}

// In C++:
// void ViewSource(HHTMLBrowser unBrowserHandle);
// In Lua:
// HTMLSurface.ViewSource(unBrowserHandle: int)
static int luasteam_HTMLSurface_ViewSource(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	iface->ViewSource(unBrowserHandle);
	return 0;
}

// In C++:
// void CopyToClipboard(HHTMLBrowser unBrowserHandle);
// In Lua:
// HTMLSurface.CopyToClipboard(unBrowserHandle: int)
static int luasteam_HTMLSurface_CopyToClipboard(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	iface->CopyToClipboard(unBrowserHandle);
	return 0;
}

// In C++:
// void PasteFromClipboard(HHTMLBrowser unBrowserHandle);
// In Lua:
// HTMLSurface.PasteFromClipboard(unBrowserHandle: int)
static int luasteam_HTMLSurface_PasteFromClipboard(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	iface->PasteFromClipboard(unBrowserHandle);
	return 0;
}

// In C++:
// void Find(HHTMLBrowser unBrowserHandle, const char * pchSearchStr, bool bCurrentlyInFind, bool bReverse);
// In Lua:
// HTMLSurface.Find(unBrowserHandle: int, pchSearchStr: str, bCurrentlyInFind: bool, bReverse: bool)
static int luasteam_HTMLSurface_Find(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	const char *pchSearchStr = luaL_checkstring(L, 2);
	bool bCurrentlyInFind = lua_toboolean(L, 3);
	bool bReverse = lua_toboolean(L, 4);
	iface->Find(unBrowserHandle, pchSearchStr, bCurrentlyInFind, bReverse);
	return 0;
}

// In C++:
// void StopFind(HHTMLBrowser unBrowserHandle);
// In Lua:
// HTMLSurface.StopFind(unBrowserHandle: int)
static int luasteam_HTMLSurface_StopFind(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	iface->StopFind(unBrowserHandle);
	return 0;
}

// In C++:
// void GetLinkAtPosition(HHTMLBrowser unBrowserHandle, int x, int y);
// In Lua:
// HTMLSurface.GetLinkAtPosition(unBrowserHandle: int, x: int, y: int)
static int luasteam_HTMLSurface_GetLinkAtPosition(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	int x = static_cast<int>(luaL_checkint(L, 2));
	int y = static_cast<int>(luaL_checkint(L, 3));
	iface->GetLinkAtPosition(unBrowserHandle, x, y);
	return 0;
}

// In C++:
// void SetCookie(const char * pchHostname, const char * pchKey, const char * pchValue, const char * pchPath, RTime32 nExpires, bool bSecure, bool bHTTPOnly);
// In Lua:
// HTMLSurface.SetCookie(pchHostname: str, pchKey: str, pchValue: str, pchPath: str, nExpires: int, bSecure: bool, bHTTPOnly: bool)
static int luasteam_HTMLSurface_SetCookie(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	const char *pchHostname = luaL_checkstring(L, 1);
	const char *pchKey = luaL_checkstring(L, 2);
	const char *pchValue = luaL_checkstring(L, 3);
	const char *pchPath = luaL_checkstring(L, 4);
	RTime32 nExpires = static_cast<RTime32>(luaL_checkint(L, 5));
	bool bSecure = lua_toboolean(L, 6);
	bool bHTTPOnly = lua_toboolean(L, 7);
	iface->SetCookie(pchHostname, pchKey, pchValue, pchPath, nExpires, bSecure, bHTTPOnly);
	return 0;
}

// In C++:
// void SetPageScaleFactor(HHTMLBrowser unBrowserHandle, float flZoom, int nPointX, int nPointY);
// In Lua:
// HTMLSurface.SetPageScaleFactor(unBrowserHandle: int, flZoom: float, nPointX: int, nPointY: int)
static int luasteam_HTMLSurface_SetPageScaleFactor(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	float flZoom = luaL_checknumber(L, 2);
	int nPointX = static_cast<int>(luaL_checkint(L, 3));
	int nPointY = static_cast<int>(luaL_checkint(L, 4));
	iface->SetPageScaleFactor(unBrowserHandle, flZoom, nPointX, nPointY);
	return 0;
}

// In C++:
// void SetBackgroundMode(HHTMLBrowser unBrowserHandle, bool bBackgroundMode);
// In Lua:
// HTMLSurface.SetBackgroundMode(unBrowserHandle: int, bBackgroundMode: bool)
static int luasteam_HTMLSurface_SetBackgroundMode(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	bool bBackgroundMode = lua_toboolean(L, 2);
	iface->SetBackgroundMode(unBrowserHandle, bBackgroundMode);
	return 0;
}

// In C++:
// void SetDPIScalingFactor(HHTMLBrowser unBrowserHandle, float flDPIScaling);
// In Lua:
// HTMLSurface.SetDPIScalingFactor(unBrowserHandle: int, flDPIScaling: float)
static int luasteam_HTMLSurface_SetDPIScalingFactor(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	float flDPIScaling = luaL_checknumber(L, 2);
	iface->SetDPIScalingFactor(unBrowserHandle, flDPIScaling);
	return 0;
}

// In C++:
// void OpenDeveloperTools(HHTMLBrowser unBrowserHandle);
// In Lua:
// HTMLSurface.OpenDeveloperTools(unBrowserHandle: int)
static int luasteam_HTMLSurface_OpenDeveloperTools(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	iface->OpenDeveloperTools(unBrowserHandle);
	return 0;
}

// In C++:
// void AllowStartRequest(HHTMLBrowser unBrowserHandle, bool bAllowed);
// In Lua:
// HTMLSurface.AllowStartRequest(unBrowserHandle: int, bAllowed: bool)
static int luasteam_HTMLSurface_AllowStartRequest(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	bool bAllowed = lua_toboolean(L, 2);
	iface->AllowStartRequest(unBrowserHandle, bAllowed);
	return 0;
}

// In C++:
// void JSDialogResponse(HHTMLBrowser unBrowserHandle, bool bResult);
// In Lua:
// HTMLSurface.JSDialogResponse(unBrowserHandle: int, bResult: bool)
static int luasteam_HTMLSurface_JSDialogResponse(lua_State *L) {
	auto *iface = SteamHTMLSurface();
	HHTMLBrowser unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 1));
	bool bResult = lua_toboolean(L, 2);
	iface->JSDialogResponse(unBrowserHandle, bResult);
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
