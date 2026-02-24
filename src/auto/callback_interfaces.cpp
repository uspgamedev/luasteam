#include "auto.hpp"
#include <new>

static int ISteamMatchmakingServerListResponseMetatable_ref = LUA_NOREF;

struct ISteamMatchmakingServerListResponseImpl : public ISteamMatchmakingServerListResponse {
	lua_State *L;
	int ref_ServerResponded;
	int ref_ServerFailedToRespond;
	int ref_RefreshComplete;

	~ISteamMatchmakingServerListResponseImpl() {
		luaL_unref(L, LUA_REGISTRYINDEX, ref_ServerResponded);
		luaL_unref(L, LUA_REGISTRYINDEX, ref_ServerFailedToRespond);
		luaL_unref(L, LUA_REGISTRYINDEX, ref_RefreshComplete);
	}

	void ServerResponded(HServerListRequest hRequest, int iServer) override {
		lua_rawgeti(L, LUA_REGISTRYINDEX, ref_ServerResponded);
		lua_pushlightuserdata(L, (void*)hRequest);
		lua_pushinteger(L, iServer);
		lua_call(L, 2, 0);
	}
	void ServerFailedToRespond(HServerListRequest hRequest, int iServer) override {
		lua_rawgeti(L, LUA_REGISTRYINDEX, ref_ServerFailedToRespond);
		lua_pushlightuserdata(L, (void*)hRequest);
		lua_pushinteger(L, iServer);
		lua_call(L, 2, 0);
	}
	void RefreshComplete(HServerListRequest hRequest, EMatchMakingServerResponse response) override {
		lua_rawgeti(L, LUA_REGISTRYINDEX, ref_RefreshComplete);
		lua_pushlightuserdata(L, (void*)hRequest);
		lua_pushinteger(L, response);
		lua_call(L, 2, 0);
	}
};

static int lua_newISteamMatchmakingServerListResponse(lua_State *L) {
	luaL_checktype(L, 1, LUA_TTABLE);
	auto *impl = (ISteamMatchmakingServerListResponseImpl*)lua_newuserdata(L, sizeof(ISteamMatchmakingServerListResponseImpl));
	new (impl) ISteamMatchmakingServerListResponseImpl();
	impl->L = L;
	lua_getfield(L, 1, "ServerResponded");
	impl->ref_ServerResponded = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_getfield(L, 1, "ServerFailedToRespond");
	impl->ref_ServerFailedToRespond = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_getfield(L, 1, "RefreshComplete");
	impl->ref_RefreshComplete = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_rawgeti(L, LUA_REGISTRYINDEX, ISteamMatchmakingServerListResponseMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int ISteamMatchmakingServerListResponse_gc(lua_State *L) {
	auto *impl = (ISteamMatchmakingServerListResponseImpl*)luaL_checkudata(L, 1, "ISteamMatchmakingServerListResponse");
	impl->~ISteamMatchmakingServerListResponseImpl();
	return 0;
}

static int ISteamMatchmakingPingResponseMetatable_ref = LUA_NOREF;

struct ISteamMatchmakingPingResponseImpl : public ISteamMatchmakingPingResponse {
	lua_State *L;
	int ref_ServerResponded;
	int ref_ServerFailedToRespond;

	~ISteamMatchmakingPingResponseImpl() {
		luaL_unref(L, LUA_REGISTRYINDEX, ref_ServerResponded);
		luaL_unref(L, LUA_REGISTRYINDEX, ref_ServerFailedToRespond);
	}

	void ServerResponded(gameserveritem_t & server) override {
		lua_rawgeti(L, LUA_REGISTRYINDEX, ref_ServerResponded);
		luasteam::push_gameserveritem_t(L, server);
		lua_call(L, 1, 0);
	}
	void ServerFailedToRespond() override {
		lua_rawgeti(L, LUA_REGISTRYINDEX, ref_ServerFailedToRespond);
		lua_call(L, 0, 0);
	}
};

static int lua_newISteamMatchmakingPingResponse(lua_State *L) {
	luaL_checktype(L, 1, LUA_TTABLE);
	auto *impl = (ISteamMatchmakingPingResponseImpl*)lua_newuserdata(L, sizeof(ISteamMatchmakingPingResponseImpl));
	new (impl) ISteamMatchmakingPingResponseImpl();
	impl->L = L;
	lua_getfield(L, 1, "ServerResponded");
	impl->ref_ServerResponded = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_getfield(L, 1, "ServerFailedToRespond");
	impl->ref_ServerFailedToRespond = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_rawgeti(L, LUA_REGISTRYINDEX, ISteamMatchmakingPingResponseMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int ISteamMatchmakingPingResponse_gc(lua_State *L) {
	auto *impl = (ISteamMatchmakingPingResponseImpl*)luaL_checkudata(L, 1, "ISteamMatchmakingPingResponse");
	impl->~ISteamMatchmakingPingResponseImpl();
	return 0;
}

static int ISteamMatchmakingPlayersResponseMetatable_ref = LUA_NOREF;

struct ISteamMatchmakingPlayersResponseImpl : public ISteamMatchmakingPlayersResponse {
	lua_State *L;
	int ref_AddPlayerToList;
	int ref_PlayersFailedToRespond;
	int ref_PlayersRefreshComplete;

	~ISteamMatchmakingPlayersResponseImpl() {
		luaL_unref(L, LUA_REGISTRYINDEX, ref_AddPlayerToList);
		luaL_unref(L, LUA_REGISTRYINDEX, ref_PlayersFailedToRespond);
		luaL_unref(L, LUA_REGISTRYINDEX, ref_PlayersRefreshComplete);
	}

	void AddPlayerToList(const char * pchName, int nScore, float flTimePlayed) override {
		lua_rawgeti(L, LUA_REGISTRYINDEX, ref_AddPlayerToList);
		lua_pushstring(L, reinterpret_cast<const char*>(pchName));
		lua_pushinteger(L, nScore);
		lua_pushnumber(L, flTimePlayed);
		lua_call(L, 3, 0);
	}
	void PlayersFailedToRespond() override {
		lua_rawgeti(L, LUA_REGISTRYINDEX, ref_PlayersFailedToRespond);
		lua_call(L, 0, 0);
	}
	void PlayersRefreshComplete() override {
		lua_rawgeti(L, LUA_REGISTRYINDEX, ref_PlayersRefreshComplete);
		lua_call(L, 0, 0);
	}
};

static int lua_newISteamMatchmakingPlayersResponse(lua_State *L) {
	luaL_checktype(L, 1, LUA_TTABLE);
	auto *impl = (ISteamMatchmakingPlayersResponseImpl*)lua_newuserdata(L, sizeof(ISteamMatchmakingPlayersResponseImpl));
	new (impl) ISteamMatchmakingPlayersResponseImpl();
	impl->L = L;
	lua_getfield(L, 1, "AddPlayerToList");
	impl->ref_AddPlayerToList = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_getfield(L, 1, "PlayersFailedToRespond");
	impl->ref_PlayersFailedToRespond = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_getfield(L, 1, "PlayersRefreshComplete");
	impl->ref_PlayersRefreshComplete = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_rawgeti(L, LUA_REGISTRYINDEX, ISteamMatchmakingPlayersResponseMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int ISteamMatchmakingPlayersResponse_gc(lua_State *L) {
	auto *impl = (ISteamMatchmakingPlayersResponseImpl*)luaL_checkudata(L, 1, "ISteamMatchmakingPlayersResponse");
	impl->~ISteamMatchmakingPlayersResponseImpl();
	return 0;
}

static int ISteamMatchmakingRulesResponseMetatable_ref = LUA_NOREF;

struct ISteamMatchmakingRulesResponseImpl : public ISteamMatchmakingRulesResponse {
	lua_State *L;
	int ref_RulesResponded;
	int ref_RulesFailedToRespond;
	int ref_RulesRefreshComplete;

	~ISteamMatchmakingRulesResponseImpl() {
		luaL_unref(L, LUA_REGISTRYINDEX, ref_RulesResponded);
		luaL_unref(L, LUA_REGISTRYINDEX, ref_RulesFailedToRespond);
		luaL_unref(L, LUA_REGISTRYINDEX, ref_RulesRefreshComplete);
	}

	void RulesResponded(const char * pchRule, const char * pchValue) override {
		lua_rawgeti(L, LUA_REGISTRYINDEX, ref_RulesResponded);
		lua_pushstring(L, reinterpret_cast<const char*>(pchRule));
		lua_pushstring(L, reinterpret_cast<const char*>(pchValue));
		lua_call(L, 2, 0);
	}
	void RulesFailedToRespond() override {
		lua_rawgeti(L, LUA_REGISTRYINDEX, ref_RulesFailedToRespond);
		lua_call(L, 0, 0);
	}
	void RulesRefreshComplete() override {
		lua_rawgeti(L, LUA_REGISTRYINDEX, ref_RulesRefreshComplete);
		lua_call(L, 0, 0);
	}
};

static int lua_newISteamMatchmakingRulesResponse(lua_State *L) {
	luaL_checktype(L, 1, LUA_TTABLE);
	auto *impl = (ISteamMatchmakingRulesResponseImpl*)lua_newuserdata(L, sizeof(ISteamMatchmakingRulesResponseImpl));
	new (impl) ISteamMatchmakingRulesResponseImpl();
	impl->L = L;
	lua_getfield(L, 1, "RulesResponded");
	impl->ref_RulesResponded = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_getfield(L, 1, "RulesFailedToRespond");
	impl->ref_RulesFailedToRespond = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_getfield(L, 1, "RulesRefreshComplete");
	impl->ref_RulesRefreshComplete = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_rawgeti(L, LUA_REGISTRYINDEX, ISteamMatchmakingRulesResponseMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int ISteamMatchmakingRulesResponse_gc(lua_State *L) {
	auto *impl = (ISteamMatchmakingRulesResponseImpl*)luaL_checkudata(L, 1, "ISteamMatchmakingRulesResponse");
	impl->~ISteamMatchmakingRulesResponseImpl();
	return 0;
}

namespace luasteam {

ISteamMatchmakingServerListResponse *check_ISteamMatchmakingServerListResponse(lua_State *L, int idx) {
	return (ISteamMatchmakingServerListResponseImpl*)luaL_checkudata(L, idx, "ISteamMatchmakingServerListResponse");
}

ISteamMatchmakingPingResponse *check_ISteamMatchmakingPingResponse(lua_State *L, int idx) {
	return (ISteamMatchmakingPingResponseImpl*)luaL_checkudata(L, idx, "ISteamMatchmakingPingResponse");
}

ISteamMatchmakingPlayersResponse *check_ISteamMatchmakingPlayersResponse(lua_State *L, int idx) {
	return (ISteamMatchmakingPlayersResponseImpl*)luaL_checkudata(L, idx, "ISteamMatchmakingPlayersResponse");
}

ISteamMatchmakingRulesResponse *check_ISteamMatchmakingRulesResponse(lua_State *L, int idx) {
	return (ISteamMatchmakingRulesResponseImpl*)luaL_checkudata(L, idx, "ISteamMatchmakingRulesResponse");
}

void init_callback_interfaces_auto(lua_State *L) {
	luaL_newmetatable(L, "ISteamMatchmakingServerListResponse");
	add_func(L, "__gc", ISteamMatchmakingServerListResponse_gc);
	ISteamMatchmakingServerListResponseMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	luaL_newmetatable(L, "ISteamMatchmakingPingResponse");
	add_func(L, "__gc", ISteamMatchmakingPingResponse_gc);
	ISteamMatchmakingPingResponseMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	luaL_newmetatable(L, "ISteamMatchmakingPlayersResponse");
	add_func(L, "__gc", ISteamMatchmakingPlayersResponse_gc);
	ISteamMatchmakingPlayersResponseMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	luaL_newmetatable(L, "ISteamMatchmakingRulesResponse");
	add_func(L, "__gc", ISteamMatchmakingRulesResponse_gc);
	ISteamMatchmakingRulesResponseMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
}

void shutdown_callback_interfaces_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, ISteamMatchmakingServerListResponseMetatable_ref);
	ISteamMatchmakingServerListResponseMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, ISteamMatchmakingPingResponseMetatable_ref);
	ISteamMatchmakingPingResponseMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, ISteamMatchmakingPlayersResponseMetatable_ref);
	ISteamMatchmakingPlayersResponseMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, ISteamMatchmakingRulesResponseMetatable_ref);
	ISteamMatchmakingRulesResponseMetatable_ref = LUA_NOREF;
}

void add_callback_interfaces_auto(lua_State *L) {
	add_func(L, "newISteamMatchmakingServerListResponse", lua_newISteamMatchmakingServerListResponse);
	add_func(L, "newISteamMatchmakingPingResponse", lua_newISteamMatchmakingPingResponse);
	add_func(L, "newISteamMatchmakingPlayersResponse", lua_newISteamMatchmakingPlayersResponse);
	add_func(L, "newISteamMatchmakingRulesResponse", lua_newISteamMatchmakingRulesResponse);
}

} // namespace luasteam
