#include "auto.hpp"

namespace luasteam {

int HTTP_ref = LUA_NOREF;
typedef ISteamHTTP *(*HTTPAccessor)();

namespace {
class HTTPCallbackListener {
private:
	STEAM_CALLBACK(HTTPCallbackListener, OnHTTPRequestCompleted, HTTPRequestCompleted_t);
	STEAM_CALLBACK(HTTPCallbackListener, OnHTTPRequestHeadersReceived, HTTPRequestHeadersReceived_t);
	STEAM_CALLBACK(HTTPCallbackListener, OnHTTPRequestDataReceived, HTTPRequestDataReceived_t);
};
void HTTPCallbackListener::OnHTTPRequestCompleted(HTTPRequestCompleted_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTTP_ref);
	lua_getfield(L, -1, "OnHTTPRequestCompleted");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_HTTPRequestCompleted_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void HTTPCallbackListener::OnHTTPRequestHeadersReceived(HTTPRequestHeadersReceived_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTTP_ref);
	lua_getfield(L, -1, "OnHTTPRequestHeadersReceived");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_HTTPRequestHeadersReceived_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void HTTPCallbackListener::OnHTTPRequestDataReceived(HTTPRequestDataReceived_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::HTTP_ref);
	lua_getfield(L, -1, "OnHTTPRequestDataReceived");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_HTTPRequestDataReceived_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
HTTPCallbackListener *HTTP_listener = nullptr;
} // namespace

void init_HTTP_auto(lua_State *L) { if (HTTP_listener != nullptr) return; HTTP_listener = new HTTPCallbackListener(); }
void shutdown_HTTP_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, HTTP_ref);
	HTTP_ref = LUA_NOREF;
	delete HTTP_listener; HTTP_listener = nullptr;
}

// In C++:
// HTTPRequestHandle CreateHTTPRequest(EHTTPMethod eHTTPRequestMethod, const char * pchAbsoluteURL);
// In Lua:
// int HTTP.CreateHTTPRequest(eHTTPRequestMethod: int, pchAbsoluteURL: str)
static int luasteam_HTTP_CreateHTTPRequest(lua_State *L) {
	auto *iface = ((HTTPAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	EHTTPMethod eHTTPRequestMethod = static_cast<EHTTPMethod>(luaL_checkint(L, 1));
	const char *pchAbsoluteURL = luaL_checkstring(L, 2);
	HTTPRequestHandle __ret = iface->CreateHTTPRequest(eHTTPRequestMethod, pchAbsoluteURL);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool SetHTTPRequestContextValue(HTTPRequestHandle hRequest, uint64 ulContextValue);
// In Lua:
// bool HTTP.SetHTTPRequestContextValue(hRequest: int, ulContextValue: uint64)
static int luasteam_HTTP_SetHTTPRequestContextValue(lua_State *L) {
	auto *iface = ((HTTPAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	uint64 ulContextValue(luasteam::checkuint64(L, 2));
	bool __ret = iface->SetHTTPRequestContextValue(hRequest, ulContextValue);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetHTTPRequestNetworkActivityTimeout(HTTPRequestHandle hRequest, uint32 unTimeoutSeconds);
// In Lua:
// bool HTTP.SetHTTPRequestNetworkActivityTimeout(hRequest: int, unTimeoutSeconds: int)
static int luasteam_HTTP_SetHTTPRequestNetworkActivityTimeout(lua_State *L) {
	auto *iface = ((HTTPAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	uint32 unTimeoutSeconds = static_cast<uint32>(luaL_checkint(L, 2));
	bool __ret = iface->SetHTTPRequestNetworkActivityTimeout(hRequest, unTimeoutSeconds);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetHTTPRequestHeaderValue(HTTPRequestHandle hRequest, const char * pchHeaderName, const char * pchHeaderValue);
// In Lua:
// bool HTTP.SetHTTPRequestHeaderValue(hRequest: int, pchHeaderName: str, pchHeaderValue: str)
static int luasteam_HTTP_SetHTTPRequestHeaderValue(lua_State *L) {
	auto *iface = ((HTTPAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	const char *pchHeaderName = luaL_checkstring(L, 2);
	const char *pchHeaderValue = luaL_checkstring(L, 3);
	bool __ret = iface->SetHTTPRequestHeaderValue(hRequest, pchHeaderName, pchHeaderValue);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetHTTPRequestGetOrPostParameter(HTTPRequestHandle hRequest, const char * pchParamName, const char * pchParamValue);
// In Lua:
// bool HTTP.SetHTTPRequestGetOrPostParameter(hRequest: int, pchParamName: str, pchParamValue: str)
static int luasteam_HTTP_SetHTTPRequestGetOrPostParameter(lua_State *L) {
	auto *iface = ((HTTPAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	const char *pchParamName = luaL_checkstring(L, 2);
	const char *pchParamValue = luaL_checkstring(L, 3);
	bool __ret = iface->SetHTTPRequestGetOrPostParameter(hRequest, pchParamName, pchParamValue);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SendHTTPRequest(HTTPRequestHandle hRequest, SteamAPICall_t * pCallHandle);
// In Lua:
// (bool, pCallHandle: uint64) HTTP.SendHTTPRequest(hRequest: int)
static int luasteam_HTTP_SendHTTPRequest(lua_State *L) {
	auto *iface = ((HTTPAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	SteamAPICall_t pCallHandle;
	bool __ret = iface->SendHTTPRequest(hRequest, &pCallHandle);
	lua_pushboolean(L, __ret);
	luasteam::pushuint64(L, pCallHandle);
	return 2;
}

// In C++:
// bool SendHTTPRequestAndStreamResponse(HTTPRequestHandle hRequest, SteamAPICall_t * pCallHandle);
// In Lua:
// (bool, pCallHandle: uint64) HTTP.SendHTTPRequestAndStreamResponse(hRequest: int)
static int luasteam_HTTP_SendHTTPRequestAndStreamResponse(lua_State *L) {
	auto *iface = ((HTTPAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	SteamAPICall_t pCallHandle;
	bool __ret = iface->SendHTTPRequestAndStreamResponse(hRequest, &pCallHandle);
	lua_pushboolean(L, __ret);
	luasteam::pushuint64(L, pCallHandle);
	return 2;
}

// In C++:
// bool DeferHTTPRequest(HTTPRequestHandle hRequest);
// In Lua:
// bool HTTP.DeferHTTPRequest(hRequest: int)
static int luasteam_HTTP_DeferHTTPRequest(lua_State *L) {
	auto *iface = ((HTTPAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	bool __ret = iface->DeferHTTPRequest(hRequest);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool PrioritizeHTTPRequest(HTTPRequestHandle hRequest);
// In Lua:
// bool HTTP.PrioritizeHTTPRequest(hRequest: int)
static int luasteam_HTTP_PrioritizeHTTPRequest(lua_State *L) {
	auto *iface = ((HTTPAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	bool __ret = iface->PrioritizeHTTPRequest(hRequest);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool GetHTTPResponseHeaderSize(HTTPRequestHandle hRequest, const char * pchHeaderName, uint32 * unResponseHeaderSize);
// In Lua:
// (bool, unResponseHeaderSize: int) HTTP.GetHTTPResponseHeaderSize(hRequest: int, pchHeaderName: str)
static int luasteam_HTTP_GetHTTPResponseHeaderSize(lua_State *L) {
	auto *iface = ((HTTPAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	const char *pchHeaderName = luaL_checkstring(L, 2);
	uint32 unResponseHeaderSize;
	bool __ret = iface->GetHTTPResponseHeaderSize(hRequest, pchHeaderName, &unResponseHeaderSize);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, unResponseHeaderSize);
	return 2;
}

// In C++:
// bool GetHTTPResponseHeaderValue(HTTPRequestHandle hRequest, const char * pchHeaderName, uint8 * pHeaderValueBuffer, uint32 unBufferSize);
// In Lua:
// (bool, pHeaderValueBuffer: int) HTTP.GetHTTPResponseHeaderValue(hRequest: int, pchHeaderName: str, unBufferSize: int)
static int luasteam_HTTP_GetHTTPResponseHeaderValue(lua_State *L) {
	auto *iface = ((HTTPAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	const char *pchHeaderName = luaL_checkstring(L, 2);
	uint8 pHeaderValueBuffer;
	uint32 unBufferSize = static_cast<uint32>(luaL_checkint(L, 3));
	bool __ret = iface->GetHTTPResponseHeaderValue(hRequest, pchHeaderName, &pHeaderValueBuffer, unBufferSize);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pHeaderValueBuffer);
	return 2;
}

// In C++:
// bool GetHTTPResponseBodySize(HTTPRequestHandle hRequest, uint32 * unBodySize);
// In Lua:
// (bool, unBodySize: int) HTTP.GetHTTPResponseBodySize(hRequest: int)
static int luasteam_HTTP_GetHTTPResponseBodySize(lua_State *L) {
	auto *iface = ((HTTPAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	uint32 unBodySize;
	bool __ret = iface->GetHTTPResponseBodySize(hRequest, &unBodySize);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, unBodySize);
	return 2;
}

// In C++:
// bool GetHTTPResponseBodyData(HTTPRequestHandle hRequest, uint8 * pBodyDataBuffer, uint32 unBufferSize);
// In Lua:
// (bool, pBodyDataBuffer: int) HTTP.GetHTTPResponseBodyData(hRequest: int, unBufferSize: int)
static int luasteam_HTTP_GetHTTPResponseBodyData(lua_State *L) {
	auto *iface = ((HTTPAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	uint8 pBodyDataBuffer;
	uint32 unBufferSize = static_cast<uint32>(luaL_checkint(L, 2));
	bool __ret = iface->GetHTTPResponseBodyData(hRequest, &pBodyDataBuffer, unBufferSize);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pBodyDataBuffer);
	return 2;
}

// In C++:
// bool GetHTTPStreamingResponseBodyData(HTTPRequestHandle hRequest, uint32 cOffset, uint8 * pBodyDataBuffer, uint32 unBufferSize);
// In Lua:
// (bool, pBodyDataBuffer: int) HTTP.GetHTTPStreamingResponseBodyData(hRequest: int, cOffset: int, unBufferSize: int)
static int luasteam_HTTP_GetHTTPStreamingResponseBodyData(lua_State *L) {
	auto *iface = ((HTTPAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	uint32 cOffset = static_cast<uint32>(luaL_checkint(L, 2));
	uint8 pBodyDataBuffer;
	uint32 unBufferSize = static_cast<uint32>(luaL_checkint(L, 3));
	bool __ret = iface->GetHTTPStreamingResponseBodyData(hRequest, cOffset, &pBodyDataBuffer, unBufferSize);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pBodyDataBuffer);
	return 2;
}

// In C++:
// bool ReleaseHTTPRequest(HTTPRequestHandle hRequest);
// In Lua:
// bool HTTP.ReleaseHTTPRequest(hRequest: int)
static int luasteam_HTTP_ReleaseHTTPRequest(lua_State *L) {
	auto *iface = ((HTTPAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	bool __ret = iface->ReleaseHTTPRequest(hRequest);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool GetHTTPDownloadProgressPct(HTTPRequestHandle hRequest, float * pflPercentOut);
// In Lua:
// (bool, pflPercentOut: float) HTTP.GetHTTPDownloadProgressPct(hRequest: int)
static int luasteam_HTTP_GetHTTPDownloadProgressPct(lua_State *L) {
	auto *iface = ((HTTPAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	float pflPercentOut;
	bool __ret = iface->GetHTTPDownloadProgressPct(hRequest, &pflPercentOut);
	lua_pushboolean(L, __ret);
	lua_pushnumber(L, pflPercentOut);
	return 2;
}

// In C++:
// bool SetHTTPRequestRawPostBody(HTTPRequestHandle hRequest, const char * pchContentType, uint8 * pubBody, uint32 unBodyLen);
// In Lua:
// (bool, pubBody: int) HTTP.SetHTTPRequestRawPostBody(hRequest: int, pchContentType: str, unBodyLen: int)
static int luasteam_HTTP_SetHTTPRequestRawPostBody(lua_State *L) {
	auto *iface = ((HTTPAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	const char *pchContentType = luaL_checkstring(L, 2);
	uint8 pubBody;
	uint32 unBodyLen = static_cast<uint32>(luaL_checkint(L, 3));
	bool __ret = iface->SetHTTPRequestRawPostBody(hRequest, pchContentType, &pubBody, unBodyLen);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pubBody);
	return 2;
}

// In C++:
// HTTPCookieContainerHandle CreateCookieContainer(bool bAllowResponsesToModify);
// In Lua:
// int HTTP.CreateCookieContainer(bAllowResponsesToModify: bool)
static int luasteam_HTTP_CreateCookieContainer(lua_State *L) {
	auto *iface = ((HTTPAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	bool bAllowResponsesToModify = lua_toboolean(L, 1);
	HTTPCookieContainerHandle __ret = iface->CreateCookieContainer(bAllowResponsesToModify);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool ReleaseCookieContainer(HTTPCookieContainerHandle hCookieContainer);
// In Lua:
// bool HTTP.ReleaseCookieContainer(hCookieContainer: int)
static int luasteam_HTTP_ReleaseCookieContainer(lua_State *L) {
	auto *iface = ((HTTPAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	HTTPCookieContainerHandle hCookieContainer = static_cast<HTTPCookieContainerHandle>(luaL_checkint(L, 1));
	bool __ret = iface->ReleaseCookieContainer(hCookieContainer);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetCookie(HTTPCookieContainerHandle hCookieContainer, const char * pchHost, const char * pchUrl, const char * pchCookie);
// In Lua:
// bool HTTP.SetCookie(hCookieContainer: int, pchHost: str, pchUrl: str, pchCookie: str)
static int luasteam_HTTP_SetCookie(lua_State *L) {
	auto *iface = ((HTTPAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	HTTPCookieContainerHandle hCookieContainer = static_cast<HTTPCookieContainerHandle>(luaL_checkint(L, 1));
	const char *pchHost = luaL_checkstring(L, 2);
	const char *pchUrl = luaL_checkstring(L, 3);
	const char *pchCookie = luaL_checkstring(L, 4);
	bool __ret = iface->SetCookie(hCookieContainer, pchHost, pchUrl, pchCookie);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetHTTPRequestCookieContainer(HTTPRequestHandle hRequest, HTTPCookieContainerHandle hCookieContainer);
// In Lua:
// bool HTTP.SetHTTPRequestCookieContainer(hRequest: int, hCookieContainer: int)
static int luasteam_HTTP_SetHTTPRequestCookieContainer(lua_State *L) {
	auto *iface = ((HTTPAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	HTTPCookieContainerHandle hCookieContainer = static_cast<HTTPCookieContainerHandle>(luaL_checkint(L, 2));
	bool __ret = iface->SetHTTPRequestCookieContainer(hRequest, hCookieContainer);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetHTTPRequestUserAgentInfo(HTTPRequestHandle hRequest, const char * pchUserAgentInfo);
// In Lua:
// bool HTTP.SetHTTPRequestUserAgentInfo(hRequest: int, pchUserAgentInfo: str)
static int luasteam_HTTP_SetHTTPRequestUserAgentInfo(lua_State *L) {
	auto *iface = ((HTTPAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	const char *pchUserAgentInfo = luaL_checkstring(L, 2);
	bool __ret = iface->SetHTTPRequestUserAgentInfo(hRequest, pchUserAgentInfo);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetHTTPRequestRequiresVerifiedCertificate(HTTPRequestHandle hRequest, bool bRequireVerifiedCertificate);
// In Lua:
// bool HTTP.SetHTTPRequestRequiresVerifiedCertificate(hRequest: int, bRequireVerifiedCertificate: bool)
static int luasteam_HTTP_SetHTTPRequestRequiresVerifiedCertificate(lua_State *L) {
	auto *iface = ((HTTPAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	bool bRequireVerifiedCertificate = lua_toboolean(L, 2);
	bool __ret = iface->SetHTTPRequestRequiresVerifiedCertificate(hRequest, bRequireVerifiedCertificate);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetHTTPRequestAbsoluteTimeoutMS(HTTPRequestHandle hRequest, uint32 unMilliseconds);
// In Lua:
// bool HTTP.SetHTTPRequestAbsoluteTimeoutMS(hRequest: int, unMilliseconds: int)
static int luasteam_HTTP_SetHTTPRequestAbsoluteTimeoutMS(lua_State *L) {
	auto *iface = ((HTTPAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	uint32 unMilliseconds = static_cast<uint32>(luaL_checkint(L, 2));
	bool __ret = iface->SetHTTPRequestAbsoluteTimeoutMS(hRequest, unMilliseconds);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool GetHTTPRequestWasTimedOut(HTTPRequestHandle hRequest, bool * pbWasTimedOut);
// In Lua:
// (bool, pbWasTimedOut: bool) HTTP.GetHTTPRequestWasTimedOut(hRequest: int)
static int luasteam_HTTP_GetHTTPRequestWasTimedOut(lua_State *L) {
	auto *iface = ((HTTPAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	HTTPRequestHandle hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 1));
	bool pbWasTimedOut;
	bool __ret = iface->GetHTTPRequestWasTimedOut(hRequest, &pbWasTimedOut);
	lua_pushboolean(L, __ret);
	lua_pushboolean(L, pbWasTimedOut);
	return 2;
}

void register_HTTP_auto(lua_State *L, HTTPAccessor accessor) {
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_HTTP_CreateHTTPRequest, 1);
	lua_setfield(L, -2, "CreateHTTPRequest");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_HTTP_SetHTTPRequestContextValue, 1);
	lua_setfield(L, -2, "SetHTTPRequestContextValue");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_HTTP_SetHTTPRequestNetworkActivityTimeout, 1);
	lua_setfield(L, -2, "SetHTTPRequestNetworkActivityTimeout");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_HTTP_SetHTTPRequestHeaderValue, 1);
	lua_setfield(L, -2, "SetHTTPRequestHeaderValue");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_HTTP_SetHTTPRequestGetOrPostParameter, 1);
	lua_setfield(L, -2, "SetHTTPRequestGetOrPostParameter");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_HTTP_SendHTTPRequest, 1);
	lua_setfield(L, -2, "SendHTTPRequest");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_HTTP_SendHTTPRequestAndStreamResponse, 1);
	lua_setfield(L, -2, "SendHTTPRequestAndStreamResponse");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_HTTP_DeferHTTPRequest, 1);
	lua_setfield(L, -2, "DeferHTTPRequest");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_HTTP_PrioritizeHTTPRequest, 1);
	lua_setfield(L, -2, "PrioritizeHTTPRequest");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_HTTP_GetHTTPResponseHeaderSize, 1);
	lua_setfield(L, -2, "GetHTTPResponseHeaderSize");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_HTTP_GetHTTPResponseHeaderValue, 1);
	lua_setfield(L, -2, "GetHTTPResponseHeaderValue");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_HTTP_GetHTTPResponseBodySize, 1);
	lua_setfield(L, -2, "GetHTTPResponseBodySize");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_HTTP_GetHTTPResponseBodyData, 1);
	lua_setfield(L, -2, "GetHTTPResponseBodyData");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_HTTP_GetHTTPStreamingResponseBodyData, 1);
	lua_setfield(L, -2, "GetHTTPStreamingResponseBodyData");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_HTTP_ReleaseHTTPRequest, 1);
	lua_setfield(L, -2, "ReleaseHTTPRequest");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_HTTP_GetHTTPDownloadProgressPct, 1);
	lua_setfield(L, -2, "GetHTTPDownloadProgressPct");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_HTTP_SetHTTPRequestRawPostBody, 1);
	lua_setfield(L, -2, "SetHTTPRequestRawPostBody");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_HTTP_CreateCookieContainer, 1);
	lua_setfield(L, -2, "CreateCookieContainer");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_HTTP_ReleaseCookieContainer, 1);
	lua_setfield(L, -2, "ReleaseCookieContainer");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_HTTP_SetCookie, 1);
	lua_setfield(L, -2, "SetCookie");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_HTTP_SetHTTPRequestCookieContainer, 1);
	lua_setfield(L, -2, "SetHTTPRequestCookieContainer");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_HTTP_SetHTTPRequestUserAgentInfo, 1);
	lua_setfield(L, -2, "SetHTTPRequestUserAgentInfo");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_HTTP_SetHTTPRequestRequiresVerifiedCertificate, 1);
	lua_setfield(L, -2, "SetHTTPRequestRequiresVerifiedCertificate");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_HTTP_SetHTTPRequestAbsoluteTimeoutMS, 1);
	lua_setfield(L, -2, "SetHTTPRequestAbsoluteTimeoutMS");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_HTTP_GetHTTPRequestWasTimedOut, 1);
	lua_setfield(L, -2, "GetHTTPRequestWasTimedOut");
}

void add_HTTP_auto(lua_State *L) {
	lua_createtable(L, 0, 25);
	register_HTTP_auto(L, &SteamHTTP);
	lua_pushvalue(L, -1);
	HTTP_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "HTTP");
}

int GameServerHTTP_ref = LUA_NOREF;

namespace {
class GameServerHTTPCallbackListener {
private:
	STEAM_GAMESERVER_CALLBACK(GameServerHTTPCallbackListener, OnHTTPRequestCompleted, HTTPRequestCompleted_t);
	STEAM_GAMESERVER_CALLBACK(GameServerHTTPCallbackListener, OnHTTPRequestHeadersReceived, HTTPRequestHeadersReceived_t);
	STEAM_GAMESERVER_CALLBACK(GameServerHTTPCallbackListener, OnHTTPRequestDataReceived, HTTPRequestDataReceived_t);
};
void GameServerHTTPCallbackListener::OnHTTPRequestCompleted(HTTPRequestCompleted_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerHTTP_ref);
	lua_getfield(L, -1, "OnHTTPRequestCompleted");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_HTTPRequestCompleted_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerHTTPCallbackListener::OnHTTPRequestHeadersReceived(HTTPRequestHeadersReceived_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerHTTP_ref);
	lua_getfield(L, -1, "OnHTTPRequestHeadersReceived");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_HTTPRequestHeadersReceived_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerHTTPCallbackListener::OnHTTPRequestDataReceived(HTTPRequestDataReceived_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerHTTP_ref);
	lua_getfield(L, -1, "OnHTTPRequestDataReceived");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_HTTPRequestDataReceived_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
GameServerHTTPCallbackListener *GameServerHTTP_listener = nullptr;
} // namespace

void init_GameServerHTTP_auto(lua_State *L) { if (GameServerHTTP_listener != nullptr) return; GameServerHTTP_listener = new GameServerHTTPCallbackListener(); }
void shutdown_GameServerHTTP_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, GameServerHTTP_ref);
	GameServerHTTP_ref = LUA_NOREF;
	delete GameServerHTTP_listener; GameServerHTTP_listener = nullptr;
}

void add_GameServerHTTP_auto(lua_State *L) {
	lua_createtable(L, 0, 25);
	register_HTTP_auto(L, &SteamGameServerHTTP);
	lua_pushvalue(L, -1);
	GameServerHTTP_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "GameServerHTTP");
}

} // namespace luasteam
