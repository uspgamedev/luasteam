#include "auto.hpp"

namespace luasteam {

int HTTP_ref = LUA_NOREF;

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
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTTP_ref);
	lua_getfield(L, -1, "OnHTTPRequestCompleted");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 5);
		lua_pushinteger(L, data->m_hRequest);
		lua_setfield(L, -2, "m_hRequest");
		luasteam::pushuint64(L, data->m_ulContextValue);
		lua_setfield(L, -2, "m_ulContextValue");
		lua_pushboolean(L, data->m_bRequestSuccessful);
		lua_setfield(L, -2, "m_bRequestSuccessful");
		lua_pushinteger(L, data->m_eStatusCode);
		lua_setfield(L, -2, "m_eStatusCode");
		lua_pushinteger(L, data->m_unBodySize);
		lua_setfield(L, -2, "m_unBodySize");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnHTTPRequestHeadersReceived(HTTPRequestHeadersReceived_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTTP_ref);
	lua_getfield(L, -1, "OnHTTPRequestHeadersReceived");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 2);
		lua_pushinteger(L, data->m_hRequest);
		lua_setfield(L, -2, "m_hRequest");
		luasteam::pushuint64(L, data->m_ulContextValue);
		lua_setfield(L, -2, "m_ulContextValue");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnHTTPRequestDataReceived(HTTPRequestDataReceived_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTTP_ref);
	lua_getfield(L, -1, "OnHTTPRequestDataReceived");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 4);
		lua_pushinteger(L, data->m_hRequest);
		lua_setfield(L, -2, "m_hRequest");
		luasteam::pushuint64(L, data->m_ulContextValue);
		lua_setfield(L, -2, "m_ulContextValue");
		lua_pushinteger(L, data->m_cOffset);
		lua_setfield(L, -2, "m_cOffset");
		lua_pushinteger(L, data->m_cBytesReceived);
		lua_setfield(L, -2, "m_cBytesReceived");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
CallbackListener *HTTP_listener = nullptr;
} // namespace

void init_HTTP_auto(lua_State *L) { HTTP_listener = new CallbackListener(); }
void shutdown_HTTP_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, HTTP_ref);
	HTTP_ref = LUA_NOREF;
	delete HTTP_listener; HTTP_listener = nullptr;
}

// In C++:
// HTTPRequestHandle CreateHTTPRequest(EHTTPMethod eHTTPRequestMethod, const char * pchAbsoluteURL);
// In Lua:
// int HTTP.CreateHTTPRequest(eHTTPRequestMethod: int, pchAbsoluteURL: str)
EXTERN int luasteam_HTTP_CreateHTTPRequest(lua_State *L) {
	EHTTPMethod eHTTPRequestMethod = static_cast<EHTTPMethod>(luaL_checkint(L, 1));
	const char *pchAbsoluteURL = luaL_checkstring(L, 2);
	HTTPRequestHandle __ret = SteamHTTP()->CreateHTTPRequest(eHTTPRequestMethod, pchAbsoluteURL);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool SetHTTPRequestContextValue(HTTPRequestHandle hRequest, uint64 ulContextValue);
// In Lua:
// bool HTTP.SetHTTPRequestContextValue(hRequest: int, ulContextValue: uint64)
EXTERN int luasteam_HTTP_SetHTTPRequestContextValue(lua_State *L) {
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	uint64 ulContextValue(luasteam::checkuint64(L, 2));
	bool __ret = SteamHTTP()->SetHTTPRequestContextValue(hRequest, ulContextValue);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetHTTPRequestNetworkActivityTimeout(HTTPRequestHandle hRequest, uint32 unTimeoutSeconds);
// In Lua:
// bool HTTP.SetHTTPRequestNetworkActivityTimeout(hRequest: int, unTimeoutSeconds: int)
EXTERN int luasteam_HTTP_SetHTTPRequestNetworkActivityTimeout(lua_State *L) {
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	uint32 unTimeoutSeconds = static_cast<uint32>(luaL_checkint(L, 2));
	bool __ret = SteamHTTP()->SetHTTPRequestNetworkActivityTimeout(hRequest, unTimeoutSeconds);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetHTTPRequestHeaderValue(HTTPRequestHandle hRequest, const char * pchHeaderName, const char * pchHeaderValue);
// In Lua:
// bool HTTP.SetHTTPRequestHeaderValue(hRequest: int, pchHeaderName: str, pchHeaderValue: str)
EXTERN int luasteam_HTTP_SetHTTPRequestHeaderValue(lua_State *L) {
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	const char *pchHeaderName = luaL_checkstring(L, 2);
	const char *pchHeaderValue = luaL_checkstring(L, 3);
	bool __ret = SteamHTTP()->SetHTTPRequestHeaderValue(hRequest, pchHeaderName, pchHeaderValue);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetHTTPRequestGetOrPostParameter(HTTPRequestHandle hRequest, const char * pchParamName, const char * pchParamValue);
// In Lua:
// bool HTTP.SetHTTPRequestGetOrPostParameter(hRequest: int, pchParamName: str, pchParamValue: str)
EXTERN int luasteam_HTTP_SetHTTPRequestGetOrPostParameter(lua_State *L) {
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	const char *pchParamName = luaL_checkstring(L, 2);
	const char *pchParamValue = luaL_checkstring(L, 3);
	bool __ret = SteamHTTP()->SetHTTPRequestGetOrPostParameter(hRequest, pchParamName, pchParamValue);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SendHTTPRequest(HTTPRequestHandle hRequest, SteamAPICall_t * pCallHandle);
// In Lua:
// (bool, pCallHandle: uint64) HTTP.SendHTTPRequest(hRequest: int)
EXTERN int luasteam_HTTP_SendHTTPRequest(lua_State *L) {
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	SteamAPICall_t pCallHandle;
	bool __ret = SteamHTTP()->SendHTTPRequest(hRequest, &pCallHandle);
	lua_pushboolean(L, __ret);
	luasteam::pushuint64(L, pCallHandle);
	return 2;
}

// In C++:
// bool SendHTTPRequestAndStreamResponse(HTTPRequestHandle hRequest, SteamAPICall_t * pCallHandle);
// In Lua:
// (bool, pCallHandle: uint64) HTTP.SendHTTPRequestAndStreamResponse(hRequest: int)
EXTERN int luasteam_HTTP_SendHTTPRequestAndStreamResponse(lua_State *L) {
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	SteamAPICall_t pCallHandle;
	bool __ret = SteamHTTP()->SendHTTPRequestAndStreamResponse(hRequest, &pCallHandle);
	lua_pushboolean(L, __ret);
	luasteam::pushuint64(L, pCallHandle);
	return 2;
}

// In C++:
// bool DeferHTTPRequest(HTTPRequestHandle hRequest);
// In Lua:
// bool HTTP.DeferHTTPRequest(hRequest: int)
EXTERN int luasteam_HTTP_DeferHTTPRequest(lua_State *L) {
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	bool __ret = SteamHTTP()->DeferHTTPRequest(hRequest);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool PrioritizeHTTPRequest(HTTPRequestHandle hRequest);
// In Lua:
// bool HTTP.PrioritizeHTTPRequest(hRequest: int)
EXTERN int luasteam_HTTP_PrioritizeHTTPRequest(lua_State *L) {
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	bool __ret = SteamHTTP()->PrioritizeHTTPRequest(hRequest);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool GetHTTPResponseHeaderSize(HTTPRequestHandle hRequest, const char * pchHeaderName, uint32 * unResponseHeaderSize);
// In Lua:
// (bool, unResponseHeaderSize: int) HTTP.GetHTTPResponseHeaderSize(hRequest: int, pchHeaderName: str)
EXTERN int luasteam_HTTP_GetHTTPResponseHeaderSize(lua_State *L) {
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	const char *pchHeaderName = luaL_checkstring(L, 2);
	uint32 unResponseHeaderSize;
	bool __ret = SteamHTTP()->GetHTTPResponseHeaderSize(hRequest, pchHeaderName, &unResponseHeaderSize);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, unResponseHeaderSize);
	return 2;
}

// In C++:
// bool GetHTTPResponseHeaderValue(HTTPRequestHandle hRequest, const char * pchHeaderName, uint8 * pHeaderValueBuffer, uint32 unBufferSize);
// In Lua:
// (bool, pHeaderValueBuffer: int) HTTP.GetHTTPResponseHeaderValue(hRequest: int, pchHeaderName: str, unBufferSize: int)
EXTERN int luasteam_HTTP_GetHTTPResponseHeaderValue(lua_State *L) {
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	const char *pchHeaderName = luaL_checkstring(L, 2);
	uint8 pHeaderValueBuffer;
	uint32 unBufferSize = static_cast<uint32>(luaL_checkint(L, 3));
	bool __ret = SteamHTTP()->GetHTTPResponseHeaderValue(hRequest, pchHeaderName, &pHeaderValueBuffer, unBufferSize);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pHeaderValueBuffer);
	return 2;
}

// In C++:
// bool GetHTTPResponseBodySize(HTTPRequestHandle hRequest, uint32 * unBodySize);
// In Lua:
// (bool, unBodySize: int) HTTP.GetHTTPResponseBodySize(hRequest: int)
EXTERN int luasteam_HTTP_GetHTTPResponseBodySize(lua_State *L) {
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	uint32 unBodySize;
	bool __ret = SteamHTTP()->GetHTTPResponseBodySize(hRequest, &unBodySize);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, unBodySize);
	return 2;
}

// In C++:
// bool GetHTTPResponseBodyData(HTTPRequestHandle hRequest, uint8 * pBodyDataBuffer, uint32 unBufferSize);
// In Lua:
// (bool, pBodyDataBuffer: int) HTTP.GetHTTPResponseBodyData(hRequest: int, unBufferSize: int)
EXTERN int luasteam_HTTP_GetHTTPResponseBodyData(lua_State *L) {
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	uint8 pBodyDataBuffer;
	uint32 unBufferSize = static_cast<uint32>(luaL_checkint(L, 2));
	bool __ret = SteamHTTP()->GetHTTPResponseBodyData(hRequest, &pBodyDataBuffer, unBufferSize);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pBodyDataBuffer);
	return 2;
}

// In C++:
// bool GetHTTPStreamingResponseBodyData(HTTPRequestHandle hRequest, uint32 cOffset, uint8 * pBodyDataBuffer, uint32 unBufferSize);
// In Lua:
// (bool, pBodyDataBuffer: int) HTTP.GetHTTPStreamingResponseBodyData(hRequest: int, cOffset: int, unBufferSize: int)
EXTERN int luasteam_HTTP_GetHTTPStreamingResponseBodyData(lua_State *L) {
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	uint32 cOffset = static_cast<uint32>(luaL_checkint(L, 2));
	uint8 pBodyDataBuffer;
	uint32 unBufferSize = static_cast<uint32>(luaL_checkint(L, 3));
	bool __ret = SteamHTTP()->GetHTTPStreamingResponseBodyData(hRequest, cOffset, &pBodyDataBuffer, unBufferSize);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pBodyDataBuffer);
	return 2;
}

// In C++:
// bool ReleaseHTTPRequest(HTTPRequestHandle hRequest);
// In Lua:
// bool HTTP.ReleaseHTTPRequest(hRequest: int)
EXTERN int luasteam_HTTP_ReleaseHTTPRequest(lua_State *L) {
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	bool __ret = SteamHTTP()->ReleaseHTTPRequest(hRequest);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool GetHTTPDownloadProgressPct(HTTPRequestHandle hRequest, float * pflPercentOut);
// In Lua:
// (bool, pflPercentOut: float) HTTP.GetHTTPDownloadProgressPct(hRequest: int)
EXTERN int luasteam_HTTP_GetHTTPDownloadProgressPct(lua_State *L) {
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	float pflPercentOut;
	bool __ret = SteamHTTP()->GetHTTPDownloadProgressPct(hRequest, &pflPercentOut);
	lua_pushboolean(L, __ret);
	lua_pushnumber(L, pflPercentOut);
	return 2;
}

// In C++:
// bool SetHTTPRequestRawPostBody(HTTPRequestHandle hRequest, const char * pchContentType, uint8 * pubBody, uint32 unBodyLen);
// In Lua:
// (bool, pubBody: int) HTTP.SetHTTPRequestRawPostBody(hRequest: int, pchContentType: str, unBodyLen: int)
EXTERN int luasteam_HTTP_SetHTTPRequestRawPostBody(lua_State *L) {
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	const char *pchContentType = luaL_checkstring(L, 2);
	uint8 pubBody;
	uint32 unBodyLen = static_cast<uint32>(luaL_checkint(L, 3));
	bool __ret = SteamHTTP()->SetHTTPRequestRawPostBody(hRequest, pchContentType, &pubBody, unBodyLen);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pubBody);
	return 2;
}

// In C++:
// HTTPCookieContainerHandle CreateCookieContainer(bool bAllowResponsesToModify);
// In Lua:
// int HTTP.CreateCookieContainer(bAllowResponsesToModify: bool)
EXTERN int luasteam_HTTP_CreateCookieContainer(lua_State *L) {
	bool bAllowResponsesToModify = lua_toboolean(L, 1);
	HTTPCookieContainerHandle __ret = SteamHTTP()->CreateCookieContainer(bAllowResponsesToModify);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool ReleaseCookieContainer(HTTPCookieContainerHandle hCookieContainer);
// In Lua:
// bool HTTP.ReleaseCookieContainer(hCookieContainer: int)
EXTERN int luasteam_HTTP_ReleaseCookieContainer(lua_State *L) {
	HTTPCookieContainerHandle hCookieContainer = static_cast<HTTPCookieContainerHandle>(luaL_checkint(L, 1));
	bool __ret = SteamHTTP()->ReleaseCookieContainer(hCookieContainer);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetCookie(HTTPCookieContainerHandle hCookieContainer, const char * pchHost, const char * pchUrl, const char * pchCookie);
// In Lua:
// bool HTTP.SetCookie(hCookieContainer: int, pchHost: str, pchUrl: str, pchCookie: str)
EXTERN int luasteam_HTTP_SetCookie(lua_State *L) {
	HTTPCookieContainerHandle hCookieContainer = static_cast<HTTPCookieContainerHandle>(luaL_checkint(L, 1));
	const char *pchHost = luaL_checkstring(L, 2);
	const char *pchUrl = luaL_checkstring(L, 3);
	const char *pchCookie = luaL_checkstring(L, 4);
	bool __ret = SteamHTTP()->SetCookie(hCookieContainer, pchHost, pchUrl, pchCookie);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetHTTPRequestCookieContainer(HTTPRequestHandle hRequest, HTTPCookieContainerHandle hCookieContainer);
// In Lua:
// bool HTTP.SetHTTPRequestCookieContainer(hRequest: int, hCookieContainer: int)
EXTERN int luasteam_HTTP_SetHTTPRequestCookieContainer(lua_State *L) {
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	HTTPCookieContainerHandle hCookieContainer = static_cast<HTTPCookieContainerHandle>(luaL_checkint(L, 2));
	bool __ret = SteamHTTP()->SetHTTPRequestCookieContainer(hRequest, hCookieContainer);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetHTTPRequestUserAgentInfo(HTTPRequestHandle hRequest, const char * pchUserAgentInfo);
// In Lua:
// bool HTTP.SetHTTPRequestUserAgentInfo(hRequest: int, pchUserAgentInfo: str)
EXTERN int luasteam_HTTP_SetHTTPRequestUserAgentInfo(lua_State *L) {
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	const char *pchUserAgentInfo = luaL_checkstring(L, 2);
	bool __ret = SteamHTTP()->SetHTTPRequestUserAgentInfo(hRequest, pchUserAgentInfo);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetHTTPRequestRequiresVerifiedCertificate(HTTPRequestHandle hRequest, bool bRequireVerifiedCertificate);
// In Lua:
// bool HTTP.SetHTTPRequestRequiresVerifiedCertificate(hRequest: int, bRequireVerifiedCertificate: bool)
EXTERN int luasteam_HTTP_SetHTTPRequestRequiresVerifiedCertificate(lua_State *L) {
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	bool bRequireVerifiedCertificate = lua_toboolean(L, 2);
	bool __ret = SteamHTTP()->SetHTTPRequestRequiresVerifiedCertificate(hRequest, bRequireVerifiedCertificate);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetHTTPRequestAbsoluteTimeoutMS(HTTPRequestHandle hRequest, uint32 unMilliseconds);
// In Lua:
// bool HTTP.SetHTTPRequestAbsoluteTimeoutMS(hRequest: int, unMilliseconds: int)
EXTERN int luasteam_HTTP_SetHTTPRequestAbsoluteTimeoutMS(lua_State *L) {
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	uint32 unMilliseconds = static_cast<uint32>(luaL_checkint(L, 2));
	bool __ret = SteamHTTP()->SetHTTPRequestAbsoluteTimeoutMS(hRequest, unMilliseconds);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool GetHTTPRequestWasTimedOut(HTTPRequestHandle hRequest, bool * pbWasTimedOut);
// In Lua:
// (bool, pbWasTimedOut: bool) HTTP.GetHTTPRequestWasTimedOut(hRequest: int)
EXTERN int luasteam_HTTP_GetHTTPRequestWasTimedOut(lua_State *L) {
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	bool pbWasTimedOut;
	bool __ret = SteamHTTP()->GetHTTPRequestWasTimedOut(hRequest, &pbWasTimedOut);
	lua_pushboolean(L, __ret);
	lua_pushboolean(L, pbWasTimedOut);
	return 2;
}

void register_HTTP_auto(lua_State *L) {
	add_func(L, "CreateHTTPRequest", luasteam_HTTP_CreateHTTPRequest);
	add_func(L, "SetHTTPRequestContextValue", luasteam_HTTP_SetHTTPRequestContextValue);
	add_func(L, "SetHTTPRequestNetworkActivityTimeout", luasteam_HTTP_SetHTTPRequestNetworkActivityTimeout);
	add_func(L, "SetHTTPRequestHeaderValue", luasteam_HTTP_SetHTTPRequestHeaderValue);
	add_func(L, "SetHTTPRequestGetOrPostParameter", luasteam_HTTP_SetHTTPRequestGetOrPostParameter);
	add_func(L, "SendHTTPRequest", luasteam_HTTP_SendHTTPRequest);
	add_func(L, "SendHTTPRequestAndStreamResponse", luasteam_HTTP_SendHTTPRequestAndStreamResponse);
	add_func(L, "DeferHTTPRequest", luasteam_HTTP_DeferHTTPRequest);
	add_func(L, "PrioritizeHTTPRequest", luasteam_HTTP_PrioritizeHTTPRequest);
	add_func(L, "GetHTTPResponseHeaderSize", luasteam_HTTP_GetHTTPResponseHeaderSize);
	add_func(L, "GetHTTPResponseHeaderValue", luasteam_HTTP_GetHTTPResponseHeaderValue);
	add_func(L, "GetHTTPResponseBodySize", luasteam_HTTP_GetHTTPResponseBodySize);
	add_func(L, "GetHTTPResponseBodyData", luasteam_HTTP_GetHTTPResponseBodyData);
	add_func(L, "GetHTTPStreamingResponseBodyData", luasteam_HTTP_GetHTTPStreamingResponseBodyData);
	add_func(L, "ReleaseHTTPRequest", luasteam_HTTP_ReleaseHTTPRequest);
	add_func(L, "GetHTTPDownloadProgressPct", luasteam_HTTP_GetHTTPDownloadProgressPct);
	add_func(L, "SetHTTPRequestRawPostBody", luasteam_HTTP_SetHTTPRequestRawPostBody);
	add_func(L, "CreateCookieContainer", luasteam_HTTP_CreateCookieContainer);
	add_func(L, "ReleaseCookieContainer", luasteam_HTTP_ReleaseCookieContainer);
	add_func(L, "SetCookie", luasteam_HTTP_SetCookie);
	add_func(L, "SetHTTPRequestCookieContainer", luasteam_HTTP_SetHTTPRequestCookieContainer);
	add_func(L, "SetHTTPRequestUserAgentInfo", luasteam_HTTP_SetHTTPRequestUserAgentInfo);
	add_func(L, "SetHTTPRequestRequiresVerifiedCertificate", luasteam_HTTP_SetHTTPRequestRequiresVerifiedCertificate);
	add_func(L, "SetHTTPRequestAbsoluteTimeoutMS", luasteam_HTTP_SetHTTPRequestAbsoluteTimeoutMS);
	add_func(L, "GetHTTPRequestWasTimedOut", luasteam_HTTP_GetHTTPRequestWasTimedOut);
}

void add_HTTP_auto(lua_State *L) {
	lua_createtable(L, 0, 25);
	register_HTTP_auto(L);
	lua_pushvalue(L, -1);
	HTTP_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "HTTP");
}

} // namespace luasteam
