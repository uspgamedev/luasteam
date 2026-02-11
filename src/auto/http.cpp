#include "auto.hpp"

namespace luasteam {

int http_ref = LUA_NOREF;

namespace {

class CallbackListener {
  private:
    STEAM_CALLBACK(CallbackListener, OnHTTPRequestCompleted, HTTPRequestCompleted_t);
    STEAM_CALLBACK(CallbackListener, OnHTTPRequestHeadersReceived, HTTPRequestHeadersReceived_t);
    STEAM_CALLBACK(CallbackListener, OnHTTPRequestDataReceived, HTTPRequestDataReceived_t);
};

void CallbackListener::OnHTTPRequestCompleted(HTTPRequestCompleted_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::http_ref);
    lua_getfield(L, -1, "onHTTPRequestCompleted");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 5);
        lua_pushinteger(L, data->m_hRequest);
        lua_setfield(L, -2, "request");
        luasteam::pushuint64(L, data->m_ulContextValue);
        lua_setfield(L, -2, "contextValue");
        lua_pushboolean(L, data->m_bRequestSuccessful);
        lua_setfield(L, -2, "requestSuccessful");
        lua_pushinteger(L, data->m_eStatusCode);
        lua_setfield(L, -2, "statusCode");
        lua_pushinteger(L, data->m_unBodySize);
        lua_setfield(L, -2, "bodySize");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTTPRequestHeadersReceived(HTTPRequestHeadersReceived_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::http_ref);
    lua_getfield(L, -1, "onHTTPRequestHeadersReceived");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->m_hRequest);
        lua_setfield(L, -2, "request");
        luasteam::pushuint64(L, data->m_ulContextValue);
        lua_setfield(L, -2, "contextValue");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnHTTPRequestDataReceived(HTTPRequestDataReceived_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::http_ref);
    lua_getfield(L, -1, "onHTTPRequestDataReceived");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        lua_pushinteger(L, data->m_hRequest);
        lua_setfield(L, -2, "request");
        luasteam::pushuint64(L, data->m_ulContextValue);
        lua_setfield(L, -2, "contextValue");
        lua_pushinteger(L, data->m_cOffset);
        lua_setfield(L, -2, "cOffset");
        lua_pushinteger(L, data->m_cBytesReceived);
        lua_setfield(L, -2, "cBytesReceived");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

CallbackListener *http_listener = nullptr;

} // namespace

void init_http_auto(lua_State *L) { http_listener = new CallbackListener(); }

void shutdown_http_auto(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, http_ref);
    http_ref = LUA_NOREF;
    delete http_listener; http_listener = nullptr;
}


// HTTPRequestHandle CreateHTTPRequest(EHTTPMethod eHTTPRequestMethod, const char * pchAbsoluteURL);
EXTERN int luasteam_http_SteamAPI_ISteamHTTP_CreateHTTPRequest(lua_State *L) {
    EHTTPMethod eHTTPRequestMethod = static_cast<EHTTPMethod>(luaL_checkint(L, 1));
    const char *pchAbsoluteURL = luaL_checkstring(L, 2);
    lua_pushinteger(L, SteamHTTP()->CreateHTTPRequest(eHTTPRequestMethod, pchAbsoluteURL));
    return 1;
}

// bool SetHTTPRequestContextValue(HTTPRequestHandle hRequest, uint64 ulContextValue);
EXTERN int luasteam_http_SteamAPI_ISteamHTTP_SetHTTPRequestContextValue(lua_State *L) {
    HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
    uint64 ulContextValue = luasteam::checkuint64(L, 2);
    lua_pushboolean(L, SteamHTTP()->SetHTTPRequestContextValue(hRequest, ulContextValue));
    return 1;
}

// bool SetHTTPRequestNetworkActivityTimeout(HTTPRequestHandle hRequest, uint32 unTimeoutSeconds);
EXTERN int luasteam_http_SteamAPI_ISteamHTTP_SetHTTPRequestNetworkActivityTimeout(lua_State *L) {
    HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
    uint32 unTimeoutSeconds = static_cast<uint32>(luaL_checkint(L, 2));
    lua_pushboolean(L, SteamHTTP()->SetHTTPRequestNetworkActivityTimeout(hRequest, unTimeoutSeconds));
    return 1;
}

// bool SetHTTPRequestHeaderValue(HTTPRequestHandle hRequest, const char * pchHeaderName, const char * pchHeaderValue);
EXTERN int luasteam_http_SteamAPI_ISteamHTTP_SetHTTPRequestHeaderValue(lua_State *L) {
    HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
    const char *pchHeaderName = luaL_checkstring(L, 2);
    const char *pchHeaderValue = luaL_checkstring(L, 3);
    lua_pushboolean(L, SteamHTTP()->SetHTTPRequestHeaderValue(hRequest, pchHeaderName, pchHeaderValue));
    return 1;
}

// bool SetHTTPRequestGetOrPostParameter(HTTPRequestHandle hRequest, const char * pchParamName, const char * pchParamValue);
EXTERN int luasteam_http_SteamAPI_ISteamHTTP_SetHTTPRequestGetOrPostParameter(lua_State *L) {
    HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
    const char *pchParamName = luaL_checkstring(L, 2);
    const char *pchParamValue = luaL_checkstring(L, 3);
    lua_pushboolean(L, SteamHTTP()->SetHTTPRequestGetOrPostParameter(hRequest, pchParamName, pchParamValue));
    return 1;
}

// bool DeferHTTPRequest(HTTPRequestHandle hRequest);
EXTERN int luasteam_http_SteamAPI_ISteamHTTP_DeferHTTPRequest(lua_State *L) {
    HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
    lua_pushboolean(L, SteamHTTP()->DeferHTTPRequest(hRequest));
    return 1;
}

// bool PrioritizeHTTPRequest(HTTPRequestHandle hRequest);
EXTERN int luasteam_http_SteamAPI_ISteamHTTP_PrioritizeHTTPRequest(lua_State *L) {
    HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
    lua_pushboolean(L, SteamHTTP()->PrioritizeHTTPRequest(hRequest));
    return 1;
}

// bool ReleaseHTTPRequest(HTTPRequestHandle hRequest);
EXTERN int luasteam_http_SteamAPI_ISteamHTTP_ReleaseHTTPRequest(lua_State *L) {
    HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
    lua_pushboolean(L, SteamHTTP()->ReleaseHTTPRequest(hRequest));
    return 1;
}

// HTTPCookieContainerHandle CreateCookieContainer(bool bAllowResponsesToModify);
EXTERN int luasteam_http_SteamAPI_ISteamHTTP_CreateCookieContainer(lua_State *L) {
    bool bAllowResponsesToModify = lua_toboolean(L, 1);
    lua_pushinteger(L, SteamHTTP()->CreateCookieContainer(bAllowResponsesToModify));
    return 1;
}

// bool ReleaseCookieContainer(HTTPCookieContainerHandle hCookieContainer);
EXTERN int luasteam_http_SteamAPI_ISteamHTTP_ReleaseCookieContainer(lua_State *L) {
    HTTPCookieContainerHandle hCookieContainer = static_cast<HTTPCookieContainerHandle>(luaL_checkint(L, 1));
    lua_pushboolean(L, SteamHTTP()->ReleaseCookieContainer(hCookieContainer));
    return 1;
}

// bool SetCookie(HTTPCookieContainerHandle hCookieContainer, const char * pchHost, const char * pchUrl, const char * pchCookie);
EXTERN int luasteam_http_SteamAPI_ISteamHTTP_SetCookie(lua_State *L) {
    HTTPCookieContainerHandle hCookieContainer = static_cast<HTTPCookieContainerHandle>(luaL_checkint(L, 1));
    const char *pchHost = luaL_checkstring(L, 2);
    const char *pchUrl = luaL_checkstring(L, 3);
    const char *pchCookie = luaL_checkstring(L, 4);
    lua_pushboolean(L, SteamHTTP()->SetCookie(hCookieContainer, pchHost, pchUrl, pchCookie));
    return 1;
}

// bool SetHTTPRequestCookieContainer(HTTPRequestHandle hRequest, HTTPCookieContainerHandle hCookieContainer);
EXTERN int luasteam_http_SteamAPI_ISteamHTTP_SetHTTPRequestCookieContainer(lua_State *L) {
    HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
    HTTPCookieContainerHandle hCookieContainer = static_cast<HTTPCookieContainerHandle>(luaL_checkint(L, 2));
    lua_pushboolean(L, SteamHTTP()->SetHTTPRequestCookieContainer(hRequest, hCookieContainer));
    return 1;
}

// bool SetHTTPRequestUserAgentInfo(HTTPRequestHandle hRequest, const char * pchUserAgentInfo);
EXTERN int luasteam_http_SteamAPI_ISteamHTTP_SetHTTPRequestUserAgentInfo(lua_State *L) {
    HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
    const char *pchUserAgentInfo = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamHTTP()->SetHTTPRequestUserAgentInfo(hRequest, pchUserAgentInfo));
    return 1;
}

// bool SetHTTPRequestRequiresVerifiedCertificate(HTTPRequestHandle hRequest, bool bRequireVerifiedCertificate);
EXTERN int luasteam_http_SteamAPI_ISteamHTTP_SetHTTPRequestRequiresVerifiedCertificate(lua_State *L) {
    HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
    bool bRequireVerifiedCertificate = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamHTTP()->SetHTTPRequestRequiresVerifiedCertificate(hRequest, bRequireVerifiedCertificate));
    return 1;
}

// bool SetHTTPRequestAbsoluteTimeoutMS(HTTPRequestHandle hRequest, uint32 unMilliseconds);
EXTERN int luasteam_http_SteamAPI_ISteamHTTP_SetHTTPRequestAbsoluteTimeoutMS(lua_State *L) {
    HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
    uint32 unMilliseconds = static_cast<uint32>(luaL_checkint(L, 2));
    lua_pushboolean(L, SteamHTTP()->SetHTTPRequestAbsoluteTimeoutMS(hRequest, unMilliseconds));
    return 1;
}

void register_http_auto(lua_State *L) {
    add_func(L, "createHTTPRequest", luasteam_http_SteamAPI_ISteamHTTP_CreateHTTPRequest);
    add_func(L, "setHTTPRequestContextValue", luasteam_http_SteamAPI_ISteamHTTP_SetHTTPRequestContextValue);
    add_func(L, "setHTTPRequestNetworkActivityTimeout", luasteam_http_SteamAPI_ISteamHTTP_SetHTTPRequestNetworkActivityTimeout);
    add_func(L, "setHTTPRequestHeaderValue", luasteam_http_SteamAPI_ISteamHTTP_SetHTTPRequestHeaderValue);
    add_func(L, "setHTTPRequestGetOrPostParameter", luasteam_http_SteamAPI_ISteamHTTP_SetHTTPRequestGetOrPostParameter);
    add_func(L, "deferHTTPRequest", luasteam_http_SteamAPI_ISteamHTTP_DeferHTTPRequest);
    add_func(L, "prioritizeHTTPRequest", luasteam_http_SteamAPI_ISteamHTTP_PrioritizeHTTPRequest);
    add_func(L, "releaseHTTPRequest", luasteam_http_SteamAPI_ISteamHTTP_ReleaseHTTPRequest);
    add_func(L, "createCookieContainer", luasteam_http_SteamAPI_ISteamHTTP_CreateCookieContainer);
    add_func(L, "releaseCookieContainer", luasteam_http_SteamAPI_ISteamHTTP_ReleaseCookieContainer);
    add_func(L, "setCookie", luasteam_http_SteamAPI_ISteamHTTP_SetCookie);
    add_func(L, "setHTTPRequestCookieContainer", luasteam_http_SteamAPI_ISteamHTTP_SetHTTPRequestCookieContainer);
    add_func(L, "setHTTPRequestUserAgentInfo", luasteam_http_SteamAPI_ISteamHTTP_SetHTTPRequestUserAgentInfo);
    add_func(L, "setHTTPRequestRequiresVerifiedCertificate", luasteam_http_SteamAPI_ISteamHTTP_SetHTTPRequestRequiresVerifiedCertificate);
    add_func(L, "setHTTPRequestAbsoluteTimeoutMS", luasteam_http_SteamAPI_ISteamHTTP_SetHTTPRequestAbsoluteTimeoutMS);
}

void add_http_auto(lua_State *L) {
    lua_createtable(L, 0, 15);
    register_http_auto(L);
    lua_pushvalue(L, -1);
    http_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "http");
}

} // namespace luasteam
