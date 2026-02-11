#include "auto.hpp"

// bool SetHTTPRequestContextValue(HTTPRequestHandle hRequest, uint64 ulContextValue);
EXTERN int luasteam_http_SteamAPI_ISteamHTTP_SetHTTPRequestContextValue(lua_State *L) {
    HTTPRequestHandle hRequest = luaL_checkint(L, 1);
    uint64 ulContextValue = luasteam::checkuint64(L, 2);
    lua_pushboolean(L, SteamHTTP()->SetHTTPRequestContextValue(hRequest, ulContextValue));
    return 1;
}

// bool SetHTTPRequestNetworkActivityTimeout(HTTPRequestHandle hRequest, uint32 unTimeoutSeconds);
EXTERN int luasteam_http_SteamAPI_ISteamHTTP_SetHTTPRequestNetworkActivityTimeout(lua_State *L) {
    HTTPRequestHandle hRequest = luaL_checkint(L, 1);
    uint32 unTimeoutSeconds = luaL_checkint(L, 2);
    lua_pushboolean(L, SteamHTTP()->SetHTTPRequestNetworkActivityTimeout(hRequest, unTimeoutSeconds));
    return 1;
}

// bool SetHTTPRequestHeaderValue(HTTPRequestHandle hRequest, const char * pchHeaderName, const char * pchHeaderValue);
EXTERN int luasteam_http_SteamAPI_ISteamHTTP_SetHTTPRequestHeaderValue(lua_State *L) {
    HTTPRequestHandle hRequest = luaL_checkint(L, 1);
    const char *pchHeaderName = luaL_checkstring(L, 2);
    const char *pchHeaderValue = luaL_checkstring(L, 3);
    lua_pushboolean(L, SteamHTTP()->SetHTTPRequestHeaderValue(hRequest, pchHeaderName, pchHeaderValue));
    return 1;
}

// bool SetHTTPRequestGetOrPostParameter(HTTPRequestHandle hRequest, const char * pchParamName, const char * pchParamValue);
EXTERN int luasteam_http_SteamAPI_ISteamHTTP_SetHTTPRequestGetOrPostParameter(lua_State *L) {
    HTTPRequestHandle hRequest = luaL_checkint(L, 1);
    const char *pchParamName = luaL_checkstring(L, 2);
    const char *pchParamValue = luaL_checkstring(L, 3);
    lua_pushboolean(L, SteamHTTP()->SetHTTPRequestGetOrPostParameter(hRequest, pchParamName, pchParamValue));
    return 1;
}

// bool DeferHTTPRequest(HTTPRequestHandle hRequest);
EXTERN int luasteam_http_SteamAPI_ISteamHTTP_DeferHTTPRequest(lua_State *L) {
    HTTPRequestHandle hRequest = luaL_checkint(L, 1);
    lua_pushboolean(L, SteamHTTP()->DeferHTTPRequest(hRequest));
    return 1;
}

// bool PrioritizeHTTPRequest(HTTPRequestHandle hRequest);
EXTERN int luasteam_http_SteamAPI_ISteamHTTP_PrioritizeHTTPRequest(lua_State *L) {
    HTTPRequestHandle hRequest = luaL_checkint(L, 1);
    lua_pushboolean(L, SteamHTTP()->PrioritizeHTTPRequest(hRequest));
    return 1;
}

// bool ReleaseHTTPRequest(HTTPRequestHandle hRequest);
EXTERN int luasteam_http_SteamAPI_ISteamHTTP_ReleaseHTTPRequest(lua_State *L) {
    HTTPRequestHandle hRequest = luaL_checkint(L, 1);
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
    HTTPCookieContainerHandle hCookieContainer = luaL_checkint(L, 1);
    lua_pushboolean(L, SteamHTTP()->ReleaseCookieContainer(hCookieContainer));
    return 1;
}

// bool SetCookie(HTTPCookieContainerHandle hCookieContainer, const char * pchHost, const char * pchUrl, const char * pchCookie);
EXTERN int luasteam_http_SteamAPI_ISteamHTTP_SetCookie(lua_State *L) {
    HTTPCookieContainerHandle hCookieContainer = luaL_checkint(L, 1);
    const char *pchHost = luaL_checkstring(L, 2);
    const char *pchUrl = luaL_checkstring(L, 3);
    const char *pchCookie = luaL_checkstring(L, 4);
    lua_pushboolean(L, SteamHTTP()->SetCookie(hCookieContainer, pchHost, pchUrl, pchCookie));
    return 1;
}

// bool SetHTTPRequestCookieContainer(HTTPRequestHandle hRequest, HTTPCookieContainerHandle hCookieContainer);
EXTERN int luasteam_http_SteamAPI_ISteamHTTP_SetHTTPRequestCookieContainer(lua_State *L) {
    HTTPRequestHandle hRequest = luaL_checkint(L, 1);
    HTTPCookieContainerHandle hCookieContainer = luaL_checkint(L, 2);
    lua_pushboolean(L, SteamHTTP()->SetHTTPRequestCookieContainer(hRequest, hCookieContainer));
    return 1;
}

// bool SetHTTPRequestUserAgentInfo(HTTPRequestHandle hRequest, const char * pchUserAgentInfo);
EXTERN int luasteam_http_SteamAPI_ISteamHTTP_SetHTTPRequestUserAgentInfo(lua_State *L) {
    HTTPRequestHandle hRequest = luaL_checkint(L, 1);
    const char *pchUserAgentInfo = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamHTTP()->SetHTTPRequestUserAgentInfo(hRequest, pchUserAgentInfo));
    return 1;
}

// bool SetHTTPRequestRequiresVerifiedCertificate(HTTPRequestHandle hRequest, bool bRequireVerifiedCertificate);
EXTERN int luasteam_http_SteamAPI_ISteamHTTP_SetHTTPRequestRequiresVerifiedCertificate(lua_State *L) {
    HTTPRequestHandle hRequest = luaL_checkint(L, 1);
    bool bRequireVerifiedCertificate = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamHTTP()->SetHTTPRequestRequiresVerifiedCertificate(hRequest, bRequireVerifiedCertificate));
    return 1;
}

// bool SetHTTPRequestAbsoluteTimeoutMS(HTTPRequestHandle hRequest, uint32 unMilliseconds);
EXTERN int luasteam_http_SteamAPI_ISteamHTTP_SetHTTPRequestAbsoluteTimeoutMS(lua_State *L) {
    HTTPRequestHandle hRequest = luaL_checkint(L, 1);
    uint32 unMilliseconds = luaL_checkint(L, 2);
    lua_pushboolean(L, SteamHTTP()->SetHTTPRequestAbsoluteTimeoutMS(hRequest, unMilliseconds));
    return 1;
}

namespace luasteam {

void add_http_auto(lua_State *L) {
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

} // namespace luasteam
