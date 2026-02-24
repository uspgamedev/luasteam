#include "auto.hpp"

namespace luasteam {

int NetworkingMessages_ref = LUA_NOREF;

namespace {
class CallbackListener {
private:
	STEAM_CALLBACK(CallbackListener, OnSteamNetworkingMessagesSessionRequest, SteamNetworkingMessagesSessionRequest_t);
	STEAM_CALLBACK(CallbackListener, OnSteamNetworkingMessagesSessionFailed, SteamNetworkingMessagesSessionFailed_t);
};
void CallbackListener::OnSteamNetworkingMessagesSessionRequest(SteamNetworkingMessagesSessionRequest_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::NetworkingMessages_ref);
	lua_getfield(L, -1, "OnSteamNetworkingMessagesSessionRequest");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 1);
		luasteam::push_SteamNetworkingIdentity(L, data->m_identityRemote);
		lua_setfield(L, -2, "m_identityRemote");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnSteamNetworkingMessagesSessionFailed(SteamNetworkingMessagesSessionFailed_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::NetworkingMessages_ref);
	lua_getfield(L, -1, "OnSteamNetworkingMessagesSessionFailed");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 1);
		luasteam::push_SteamNetConnectionInfo_t(L, data->m_info);
		lua_setfield(L, -2, "m_info");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
CallbackListener *NetworkingMessages_listener = nullptr;
} // namespace

void init_NetworkingMessages_auto(lua_State *L) { NetworkingMessages_listener = new CallbackListener(); }
void shutdown_NetworkingMessages_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, NetworkingMessages_ref);
	NetworkingMessages_ref = LUA_NOREF;
	delete NetworkingMessages_listener; NetworkingMessages_listener = nullptr;
}

// In C++:
// EResult SendMessageToUser(const SteamNetworkingIdentity & identityRemote, const void * pubData, uint32 cubData, int nSendFlags, int nRemoteChannel);
// In Lua:
// int NetworkingMessages.SendMessageToUser(identityRemote: SteamNetworkingIdentity, pubData: str, cubData: int, nSendFlags: int, nRemoteChannel: int)
EXTERN int luasteam_NetworkingMessages_SendMessageToUser(lua_State *L) {
	const SteamNetworkingIdentity &identityRemote = *luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	const char *pubData = luaL_checkstring(L, 2);
	uint32 cubData = static_cast<uint32>(luaL_checkint(L, 3));
	int nSendFlags = static_cast<int>(luaL_checkint(L, 4));
	int nRemoteChannel = static_cast<int>(luaL_checkint(L, 5));
	EResult __ret = SteamNetworkingMessages_SteamAPI()->SendMessageToUser(identityRemote, pubData, cubData, nSendFlags, nRemoteChannel);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool AcceptSessionWithUser(const SteamNetworkingIdentity & identityRemote);
// In Lua:
// bool NetworkingMessages.AcceptSessionWithUser(identityRemote: SteamNetworkingIdentity)
EXTERN int luasteam_NetworkingMessages_AcceptSessionWithUser(lua_State *L) {
	const SteamNetworkingIdentity &identityRemote = *luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	bool __ret = SteamNetworkingMessages_SteamAPI()->AcceptSessionWithUser(identityRemote);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool CloseSessionWithUser(const SteamNetworkingIdentity & identityRemote);
// In Lua:
// bool NetworkingMessages.CloseSessionWithUser(identityRemote: SteamNetworkingIdentity)
EXTERN int luasteam_NetworkingMessages_CloseSessionWithUser(lua_State *L) {
	const SteamNetworkingIdentity &identityRemote = *luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	bool __ret = SteamNetworkingMessages_SteamAPI()->CloseSessionWithUser(identityRemote);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool CloseChannelWithUser(const SteamNetworkingIdentity & identityRemote, int nLocalChannel);
// In Lua:
// bool NetworkingMessages.CloseChannelWithUser(identityRemote: SteamNetworkingIdentity, nLocalChannel: int)
EXTERN int luasteam_NetworkingMessages_CloseChannelWithUser(lua_State *L) {
	const SteamNetworkingIdentity &identityRemote = *luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	int nLocalChannel = static_cast<int>(luaL_checkint(L, 2));
	bool __ret = SteamNetworkingMessages_SteamAPI()->CloseChannelWithUser(identityRemote, nLocalChannel);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// ESteamNetworkingConnectionState GetSessionConnectionInfo(const SteamNetworkingIdentity & identityRemote, SteamNetConnectionInfo_t * pConnectionInfo, SteamNetConnectionRealTimeStatus_t * pQuickStatus);
// In Lua:
// (int, pConnectionInfo: SteamNetConnectionInfo_t, pQuickStatus: SteamNetConnectionRealTimeStatus_t) NetworkingMessages.GetSessionConnectionInfo(identityRemote: SteamNetworkingIdentity)
EXTERN int luasteam_NetworkingMessages_GetSessionConnectionInfo(lua_State *L) {
	const SteamNetworkingIdentity &identityRemote = *luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	SteamNetConnectionInfo_t pConnectionInfo;
	SteamNetConnectionRealTimeStatus_t pQuickStatus;
	ESteamNetworkingConnectionState __ret = SteamNetworkingMessages_SteamAPI()->GetSessionConnectionInfo(identityRemote, &pConnectionInfo, &pQuickStatus);
	lua_pushinteger(L, __ret);
	luasteam::push_SteamNetConnectionInfo_t(L, pConnectionInfo);
	luasteam::push_SteamNetConnectionRealTimeStatus_t(L, pQuickStatus);
	return 3;
}

void register_NetworkingMessages_auto(lua_State *L) {
	add_func(L, "SendMessageToUser", luasteam_NetworkingMessages_SendMessageToUser);
	add_func(L, "AcceptSessionWithUser", luasteam_NetworkingMessages_AcceptSessionWithUser);
	add_func(L, "CloseSessionWithUser", luasteam_NetworkingMessages_CloseSessionWithUser);
	add_func(L, "CloseChannelWithUser", luasteam_NetworkingMessages_CloseChannelWithUser);
	add_func(L, "GetSessionConnectionInfo", luasteam_NetworkingMessages_GetSessionConnectionInfo);
}

void add_NetworkingMessages_auto(lua_State *L) {
	lua_createtable(L, 0, 5);
	register_NetworkingMessages_auto(L);
	lua_pushvalue(L, -1);
	NetworkingMessages_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "NetworkingMessages");
}

} // namespace luasteam
