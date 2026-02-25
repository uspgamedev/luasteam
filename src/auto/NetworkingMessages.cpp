#include "auto.hpp"

namespace luasteam {

int NetworkingMessages_ref = LUA_NOREF;
typedef ISteamNetworkingMessages *(*NetworkingMessagesAccessor)();

namespace {
class NetworkingMessagesCallbackListener {
private:
	STEAM_CALLBACK(NetworkingMessagesCallbackListener, OnSteamNetworkingMessagesSessionRequest, SteamNetworkingMessagesSessionRequest_t);
	STEAM_CALLBACK(NetworkingMessagesCallbackListener, OnSteamNetworkingMessagesSessionFailed, SteamNetworkingMessagesSessionFailed_t);
};
void NetworkingMessagesCallbackListener::OnSteamNetworkingMessagesSessionRequest(SteamNetworkingMessagesSessionRequest_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::NetworkingMessages_ref);
	lua_getfield(L, -1, "OnSteamNetworkingMessagesSessionRequest");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamNetworkingMessagesSessionRequest_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void NetworkingMessagesCallbackListener::OnSteamNetworkingMessagesSessionFailed(SteamNetworkingMessagesSessionFailed_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::NetworkingMessages_ref);
	lua_getfield(L, -1, "OnSteamNetworkingMessagesSessionFailed");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamNetworkingMessagesSessionFailed_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
NetworkingMessagesCallbackListener *NetworkingMessages_listener = nullptr;
} // namespace

void init_NetworkingMessages_auto(lua_State *L) { if (NetworkingMessages_listener != nullptr) return; NetworkingMessages_listener = new NetworkingMessagesCallbackListener(); }
void shutdown_NetworkingMessages_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, NetworkingMessages_ref);
	NetworkingMessages_ref = LUA_NOREF;
	delete NetworkingMessages_listener; NetworkingMessages_listener = nullptr;
}

// In C++:
// bool AcceptSessionWithUser(const SteamNetworkingIdentity & identityRemote);
// In Lua:
// bool NetworkingMessages.AcceptSessionWithUser(identityRemote: SteamNetworkingIdentity)
static int luasteam_NetworkingMessages_AcceptSessionWithUser(lua_State *L) {
	auto *iface = ((NetworkingMessagesAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	const SteamNetworkingIdentity &identityRemote = *luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	bool __ret = iface->AcceptSessionWithUser(identityRemote);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool CloseSessionWithUser(const SteamNetworkingIdentity & identityRemote);
// In Lua:
// bool NetworkingMessages.CloseSessionWithUser(identityRemote: SteamNetworkingIdentity)
static int luasteam_NetworkingMessages_CloseSessionWithUser(lua_State *L) {
	auto *iface = ((NetworkingMessagesAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	const SteamNetworkingIdentity &identityRemote = *luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	bool __ret = iface->CloseSessionWithUser(identityRemote);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool CloseChannelWithUser(const SteamNetworkingIdentity & identityRemote, int nLocalChannel);
// In Lua:
// bool NetworkingMessages.CloseChannelWithUser(identityRemote: SteamNetworkingIdentity, nLocalChannel: int)
static int luasteam_NetworkingMessages_CloseChannelWithUser(lua_State *L) {
	auto *iface = ((NetworkingMessagesAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	const SteamNetworkingIdentity &identityRemote = *luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	int nLocalChannel = static_cast<int>(luaL_checkint(L, 2));
	bool __ret = iface->CloseChannelWithUser(identityRemote, nLocalChannel);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// ESteamNetworkingConnectionState GetSessionConnectionInfo(const SteamNetworkingIdentity & identityRemote, SteamNetConnectionInfo_t * pConnectionInfo, SteamNetConnectionRealTimeStatus_t * pQuickStatus);
// In Lua:
// (int, pConnectionInfo: SteamNetConnectionInfo_t, pQuickStatus: SteamNetConnectionRealTimeStatus_t) NetworkingMessages.GetSessionConnectionInfo(identityRemote: SteamNetworkingIdentity)
static int luasteam_NetworkingMessages_GetSessionConnectionInfo(lua_State *L) {
	auto *iface = ((NetworkingMessagesAccessor)lua_touserdata(L, lua_upvalueindex(1)))();
	const SteamNetworkingIdentity &identityRemote = *luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	SteamNetConnectionInfo_t pConnectionInfo;
	SteamNetConnectionRealTimeStatus_t pQuickStatus;
	ESteamNetworkingConnectionState __ret = iface->GetSessionConnectionInfo(identityRemote, &pConnectionInfo, &pQuickStatus);
	lua_pushinteger(L, __ret);
	luasteam::push_SteamNetConnectionInfo_t(L, pConnectionInfo);
	luasteam::push_SteamNetConnectionRealTimeStatus_t(L, pQuickStatus);
	return 3;
}

void register_NetworkingMessages_auto(lua_State *L, NetworkingMessagesAccessor accessor) {
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_NetworkingMessages_AcceptSessionWithUser, 1);
	lua_setfield(L, -2, "AcceptSessionWithUser");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_NetworkingMessages_CloseSessionWithUser, 1);
	lua_setfield(L, -2, "CloseSessionWithUser");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_NetworkingMessages_CloseChannelWithUser, 1);
	lua_setfield(L, -2, "CloseChannelWithUser");
	lua_pushlightuserdata(L, (void*)accessor);
	lua_pushcclosure(L, luasteam_NetworkingMessages_GetSessionConnectionInfo, 1);
	lua_setfield(L, -2, "GetSessionConnectionInfo");
}

void add_NetworkingMessages_auto(lua_State *L) {
	lua_createtable(L, 0, 4);
	register_NetworkingMessages_auto(L, &SteamNetworkingMessages_SteamAPI);
	lua_pushvalue(L, -1);
	NetworkingMessages_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "NetworkingMessages");
}

int GameServerNetworkingMessages_ref = LUA_NOREF;

namespace {
class GameServerNetworkingMessagesCallbackListener {
private:
	STEAM_GAMESERVER_CALLBACK(GameServerNetworkingMessagesCallbackListener, OnSteamNetworkingMessagesSessionRequest, SteamNetworkingMessagesSessionRequest_t);
	STEAM_GAMESERVER_CALLBACK(GameServerNetworkingMessagesCallbackListener, OnSteamNetworkingMessagesSessionFailed, SteamNetworkingMessagesSessionFailed_t);
};
void GameServerNetworkingMessagesCallbackListener::OnSteamNetworkingMessagesSessionRequest(SteamNetworkingMessagesSessionRequest_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerNetworkingMessages_ref);
	lua_getfield(L, -1, "OnSteamNetworkingMessagesSessionRequest");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamNetworkingMessagesSessionRequest_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerNetworkingMessagesCallbackListener::OnSteamNetworkingMessagesSessionFailed(SteamNetworkingMessagesSessionFailed_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerNetworkingMessages_ref);
	lua_getfield(L, -1, "OnSteamNetworkingMessagesSessionFailed");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamNetworkingMessagesSessionFailed_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
GameServerNetworkingMessagesCallbackListener *GameServerNetworkingMessages_listener = nullptr;
} // namespace

void init_GameServerNetworkingMessages_auto(lua_State *L) { if (GameServerNetworkingMessages_listener != nullptr) return; GameServerNetworkingMessages_listener = new GameServerNetworkingMessagesCallbackListener(); }
void shutdown_GameServerNetworkingMessages_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, GameServerNetworkingMessages_ref);
	GameServerNetworkingMessages_ref = LUA_NOREF;
	delete GameServerNetworkingMessages_listener; GameServerNetworkingMessages_listener = nullptr;
}

void add_GameServerNetworkingMessages_auto(lua_State *L) {
	lua_createtable(L, 0, 4);
	register_NetworkingMessages_auto(L, &SteamGameServerNetworkingMessages_SteamAPI);
	lua_pushvalue(L, -1);
	GameServerNetworkingMessages_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "GameServerNetworkingMessages");
}

} // namespace luasteam
