#include "auto.hpp"
#include <cstdlib>
#include <new>

static int SteamIPAddress_tMetatable_ref = LUA_NOREF;

static int luasteam_SteamIPAddress_t_IsSet(lua_State *L) {
	SteamIPAddress_t *self = luasteam::check_SteamIPAddress_t_ptr(L, 1);
	bool __ret = self->IsSet();
	lua_pushboolean(L, __ret);
	return 1;
}
static int SteamIPAddress_t_index(lua_State *L) {
	lua_getmetatable(L, 1);
	lua_pushvalue(L, 2);
	lua_rawget(L, -2);
	if (!lua_isnil(L, -1)) return 1;
	lua_pop(L, 2);
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamIPAddress_t *self = (SteamIPAddress_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_rgubIPv6") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->m_rgubIPv6));
		return 1;
	}
	if (strcmp(key, "m_eType") == 0) {
		lua_pushinteger(L, self->m_eType);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamIPAddress_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamIPAddress_t *self = (SteamIPAddress_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_rgubIPv6") == 0) {
		const char *_tmp0 = luaL_checkstring(L, 3);
		if (strlen(_tmp0) >= 16) luaL_error(L, "String too long");
		memcpy(self->m_rgubIPv6, _tmp0, sizeof(self->m_rgubIPv6));
		return 0;
	}
	if (strcmp(key, "m_eType") == 0) {
		self->m_eType = static_cast<ESteamIPType>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "SteamIPAddress_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamIPAddress_t(lua_State *L) {
	SteamIPAddress_t *ptr = (SteamIPAddress_t*)lua_newuserdata(L, sizeof(SteamIPAddress_t));
	new (ptr) SteamIPAddress_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_rgubIPv6");
		if (!lua_isnil(L, -1)) {
			const char *_tmp1 = luaL_checkstring(L, -1);
			if (strlen(_tmp1) >= 16) luaL_error(L, "String too long");
			memcpy(ptr->m_rgubIPv6, _tmp1, sizeof(ptr->m_rgubIPv6));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eType");
		if (!lua_isnil(L, -1)) {
			ptr->m_eType = static_cast<ESteamIPType>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamIPAddress_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int FriendGameInfo_tMetatable_ref = LUA_NOREF;

static int FriendGameInfo_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	FriendGameInfo_t *self = (FriendGameInfo_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_gameID") == 0) {
		luasteam::pushuint64(L, self->m_gameID.ToUint64());
		return 1;
	}
	if (strcmp(key, "m_unGameIP") == 0) {
		lua_pushinteger(L, self->m_unGameIP);
		return 1;
	}
	if (strcmp(key, "m_usGamePort") == 0) {
		lua_pushinteger(L, self->m_usGamePort);
		return 1;
	}
	if (strcmp(key, "m_usQueryPort") == 0) {
		lua_pushinteger(L, self->m_usQueryPort);
		return 1;
	}
	if (strcmp(key, "m_steamIDLobby") == 0) {
		luasteam::pushuint64(L, self->m_steamIDLobby.ConvertToUint64());
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int FriendGameInfo_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	FriendGameInfo_t *self = (FriendGameInfo_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_gameID") == 0) {
		self->m_gameID = CGameID(luasteam::checkuint64(L, 3));
		return 0;
	}
	if (strcmp(key, "m_unGameIP") == 0) {
		self->m_unGameIP = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_usGamePort") == 0) {
		self->m_usGamePort = static_cast<uint16>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_usQueryPort") == 0) {
		self->m_usQueryPort = static_cast<uint16>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_steamIDLobby") == 0) {
		self->m_steamIDLobby = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	return luaL_error(L, "FriendGameInfo_t has no field '%%s'", key);
}

EXTERN int luasteam_newFriendGameInfo_t(lua_State *L) {
	FriendGameInfo_t *ptr = (FriendGameInfo_t*)lua_newuserdata(L, sizeof(FriendGameInfo_t));
	new (ptr) FriendGameInfo_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_gameID");
		if (!lua_isnil(L, -1)) {
			ptr->m_gameID = CGameID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unGameIP");
		if (!lua_isnil(L, -1)) {
			ptr->m_unGameIP = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_usGamePort");
		if (!lua_isnil(L, -1)) {
			ptr->m_usGamePort = static_cast<uint16>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_usQueryPort");
		if (!lua_isnil(L, -1)) {
			ptr->m_usQueryPort = static_cast<uint16>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_steamIDLobby");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamIDLobby = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, FriendGameInfo_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int MatchMakingKeyValuePair_tMetatable_ref = LUA_NOREF;

static int MatchMakingKeyValuePair_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	MatchMakingKeyValuePair_t *self = (MatchMakingKeyValuePair_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_szKey") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->m_szKey));
		return 1;
	}
	if (strcmp(key, "m_szValue") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->m_szValue));
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int MatchMakingKeyValuePair_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	MatchMakingKeyValuePair_t *self = (MatchMakingKeyValuePair_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_szKey") == 0) {
		const char *_tmp2 = luaL_checkstring(L, 3);
		if (strlen(_tmp2) >= 256) luaL_error(L, "String too long");
		memcpy(self->m_szKey, _tmp2, sizeof(self->m_szKey));
		return 0;
	}
	if (strcmp(key, "m_szValue") == 0) {
		const char *_tmp4 = luaL_checkstring(L, 3);
		if (strlen(_tmp4) >= 256) luaL_error(L, "String too long");
		memcpy(self->m_szValue, _tmp4, sizeof(self->m_szValue));
		return 0;
	}
	return luaL_error(L, "MatchMakingKeyValuePair_t has no field '%%s'", key);
}

EXTERN int luasteam_newMatchMakingKeyValuePair_t(lua_State *L) {
	MatchMakingKeyValuePair_t *ptr = (MatchMakingKeyValuePair_t*)lua_newuserdata(L, sizeof(MatchMakingKeyValuePair_t));
	new (ptr) MatchMakingKeyValuePair_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_szKey");
		if (!lua_isnil(L, -1)) {
			const char *_tmp3 = luaL_checkstring(L, -1);
			if (strlen(_tmp3) >= 256) luaL_error(L, "String too long");
			memcpy(ptr->m_szKey, _tmp3, sizeof(ptr->m_szKey));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_szValue");
		if (!lua_isnil(L, -1)) {
			const char *_tmp5 = luaL_checkstring(L, -1);
			if (strlen(_tmp5) >= 256) luaL_error(L, "String too long");
			memcpy(ptr->m_szValue, _tmp5, sizeof(ptr->m_szValue));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, MatchMakingKeyValuePair_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int servernetadr_tMetatable_ref = LUA_NOREF;

static int luasteam_servernetadr_t_Init(lua_State *L) {
	servernetadr_t *self = luasteam::check_servernetadr_t_ptr(L, 1);
	unsigned int ip = static_cast<unsigned int>(luaL_checkint(L, 2));
	uint16 usQueryPort = static_cast<uint16>(luaL_checkint(L, 3));
	uint16 usConnectionPort = static_cast<uint16>(luaL_checkint(L, 4));
	self->Init(ip, usQueryPort, usConnectionPort);
	return 0;
}
static int luasteam_servernetadr_t_GetQueryPort(lua_State *L) {
	servernetadr_t *self = luasteam::check_servernetadr_t_ptr(L, 1);
	uint16 __ret = self->GetQueryPort();
	lua_pushinteger(L, __ret);
	return 1;
}
static int luasteam_servernetadr_t_SetQueryPort(lua_State *L) {
	servernetadr_t *self = luasteam::check_servernetadr_t_ptr(L, 1);
	uint16 usPort = static_cast<uint16>(luaL_checkint(L, 2));
	self->SetQueryPort(usPort);
	return 0;
}
static int luasteam_servernetadr_t_GetConnectionPort(lua_State *L) {
	servernetadr_t *self = luasteam::check_servernetadr_t_ptr(L, 1);
	uint16 __ret = self->GetConnectionPort();
	lua_pushinteger(L, __ret);
	return 1;
}
static int luasteam_servernetadr_t_SetConnectionPort(lua_State *L) {
	servernetadr_t *self = luasteam::check_servernetadr_t_ptr(L, 1);
	uint16 usPort = static_cast<uint16>(luaL_checkint(L, 2));
	self->SetConnectionPort(usPort);
	return 0;
}
static int luasteam_servernetadr_t_GetIP(lua_State *L) {
	servernetadr_t *self = luasteam::check_servernetadr_t_ptr(L, 1);
	uint32 __ret = self->GetIP();
	lua_pushinteger(L, __ret);
	return 1;
}
static int luasteam_servernetadr_t_SetIP(lua_State *L) {
	servernetadr_t *self = luasteam::check_servernetadr_t_ptr(L, 1);
	uint32 unIP = static_cast<uint32>(luaL_checkint(L, 2));
	self->SetIP(unIP);
	return 0;
}
static int luasteam_servernetadr_t_GetConnectionAddressString(lua_State *L) {
	servernetadr_t *self = luasteam::check_servernetadr_t_ptr(L, 1);
	const char * __ret = self->GetConnectionAddressString();
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}
static int luasteam_servernetadr_t_GetQueryAddressString(lua_State *L) {
	servernetadr_t *self = luasteam::check_servernetadr_t_ptr(L, 1);
	const char * __ret = self->GetQueryAddressString();
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}
static int servernetadr_t_index(lua_State *L) {
	lua_getmetatable(L, 1);
	lua_pushvalue(L, 2);
	lua_rawget(L, -2);
	if (!lua_isnil(L, -1)) return 1;
	lua_pop(L, 2);
	lua_pushnil(L);
	return 1;
}

EXTERN int luasteam_newservernetadr_t(lua_State *L) {
	servernetadr_t *ptr = (servernetadr_t*)lua_newuserdata(L, sizeof(servernetadr_t));
	new (ptr) servernetadr_t();
	lua_rawgeti(L, LUA_REGISTRYINDEX, servernetadr_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int gameserveritem_tMetatable_ref = LUA_NOREF;

static int luasteam_gameserveritem_t_GetName(lua_State *L) {
	gameserveritem_t *self = luasteam::check_gameserveritem_t_ptr(L, 1);
	const char * __ret = self->GetName();
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}
static int luasteam_gameserveritem_t_SetName(lua_State *L) {
	gameserveritem_t *self = luasteam::check_gameserveritem_t_ptr(L, 1);
	const char *pName = luaL_checkstring(L, 2);
	self->SetName(pName);
	return 0;
}
static int gameserveritem_t_index(lua_State *L) {
	lua_getmetatable(L, 1);
	lua_pushvalue(L, 2);
	lua_rawget(L, -2);
	if (!lua_isnil(L, -1)) return 1;
	lua_pop(L, 2);
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	gameserveritem_t *self = (gameserveritem_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_NetAdr") == 0) {
		luasteam::push_servernetadr_t(L, self->m_NetAdr);
		return 1;
	}
	if (strcmp(key, "m_nPing") == 0) {
		lua_pushinteger(L, self->m_nPing);
		return 1;
	}
	if (strcmp(key, "m_bHadSuccessfulResponse") == 0) {
		lua_pushboolean(L, self->m_bHadSuccessfulResponse);
		return 1;
	}
	if (strcmp(key, "m_bDoNotRefresh") == 0) {
		lua_pushboolean(L, self->m_bDoNotRefresh);
		return 1;
	}
	if (strcmp(key, "m_szGameDir") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->m_szGameDir));
		return 1;
	}
	if (strcmp(key, "m_szMap") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->m_szMap));
		return 1;
	}
	if (strcmp(key, "m_szGameDescription") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->m_szGameDescription));
		return 1;
	}
	if (strcmp(key, "m_nAppID") == 0) {
		lua_pushinteger(L, self->m_nAppID);
		return 1;
	}
	if (strcmp(key, "m_nPlayers") == 0) {
		lua_pushinteger(L, self->m_nPlayers);
		return 1;
	}
	if (strcmp(key, "m_nMaxPlayers") == 0) {
		lua_pushinteger(L, self->m_nMaxPlayers);
		return 1;
	}
	if (strcmp(key, "m_nBotPlayers") == 0) {
		lua_pushinteger(L, self->m_nBotPlayers);
		return 1;
	}
	if (strcmp(key, "m_bPassword") == 0) {
		lua_pushboolean(L, self->m_bPassword);
		return 1;
	}
	if (strcmp(key, "m_bSecure") == 0) {
		lua_pushboolean(L, self->m_bSecure);
		return 1;
	}
	if (strcmp(key, "m_ulTimeLastPlayed") == 0) {
		lua_pushinteger(L, self->m_ulTimeLastPlayed);
		return 1;
	}
	if (strcmp(key, "m_nServerVersion") == 0) {
		lua_pushinteger(L, self->m_nServerVersion);
		return 1;
	}
	if (strcmp(key, "m_szGameTags") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->m_szGameTags));
		return 1;
	}
	if (strcmp(key, "m_steamID") == 0) {
		luasteam::pushuint64(L, self->m_steamID.ConvertToUint64());
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int gameserveritem_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	gameserveritem_t *self = (gameserveritem_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_NetAdr") == 0) {
		self->m_NetAdr = luasteam::check_servernetadr_t(L, 3);
		return 0;
	}
	if (strcmp(key, "m_nPing") == 0) {
		self->m_nPing = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bHadSuccessfulResponse") == 0) {
		self->m_bHadSuccessfulResponse = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_bDoNotRefresh") == 0) {
		self->m_bDoNotRefresh = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_szGameDir") == 0) {
		const char *_tmp6 = luaL_checkstring(L, 3);
		if (strlen(_tmp6) >= 32) luaL_error(L, "String too long");
		memcpy(self->m_szGameDir, _tmp6, sizeof(self->m_szGameDir));
		return 0;
	}
	if (strcmp(key, "m_szMap") == 0) {
		const char *_tmp8 = luaL_checkstring(L, 3);
		if (strlen(_tmp8) >= 32) luaL_error(L, "String too long");
		memcpy(self->m_szMap, _tmp8, sizeof(self->m_szMap));
		return 0;
	}
	if (strcmp(key, "m_szGameDescription") == 0) {
		const char *_tmp10 = luaL_checkstring(L, 3);
		if (strlen(_tmp10) >= 64) luaL_error(L, "String too long");
		memcpy(self->m_szGameDescription, _tmp10, sizeof(self->m_szGameDescription));
		return 0;
	}
	if (strcmp(key, "m_nAppID") == 0) {
		self->m_nAppID = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nPlayers") == 0) {
		self->m_nPlayers = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nMaxPlayers") == 0) {
		self->m_nMaxPlayers = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nBotPlayers") == 0) {
		self->m_nBotPlayers = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bPassword") == 0) {
		self->m_bPassword = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_bSecure") == 0) {
		self->m_bSecure = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_ulTimeLastPlayed") == 0) {
		self->m_ulTimeLastPlayed = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nServerVersion") == 0) {
		self->m_nServerVersion = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_szGameTags") == 0) {
		const char *_tmp12 = luaL_checkstring(L, 3);
		if (strlen(_tmp12) >= 128) luaL_error(L, "String too long");
		memcpy(self->m_szGameTags, _tmp12, sizeof(self->m_szGameTags));
		return 0;
	}
	if (strcmp(key, "m_steamID") == 0) {
		self->m_steamID = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	return luaL_error(L, "gameserveritem_t has no field '%%s'", key);
}

EXTERN int luasteam_newgameserveritem_t(lua_State *L) {
	gameserveritem_t *ptr = (gameserveritem_t*)lua_newuserdata(L, sizeof(gameserveritem_t));
	new (ptr) gameserveritem_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_NetAdr");
		if (!lua_isnil(L, -1)) {
			ptr->m_NetAdr = luasteam::check_servernetadr_t(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nPing");
		if (!lua_isnil(L, -1)) {
			ptr->m_nPing = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bHadSuccessfulResponse");
		if (!lua_isnil(L, -1)) {
			ptr->m_bHadSuccessfulResponse = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bDoNotRefresh");
		if (!lua_isnil(L, -1)) {
			ptr->m_bDoNotRefresh = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_szGameDir");
		if (!lua_isnil(L, -1)) {
			const char *_tmp7 = luaL_checkstring(L, -1);
			if (strlen(_tmp7) >= 32) luaL_error(L, "String too long");
			memcpy(ptr->m_szGameDir, _tmp7, sizeof(ptr->m_szGameDir));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_szMap");
		if (!lua_isnil(L, -1)) {
			const char *_tmp9 = luaL_checkstring(L, -1);
			if (strlen(_tmp9) >= 32) luaL_error(L, "String too long");
			memcpy(ptr->m_szMap, _tmp9, sizeof(ptr->m_szMap));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_szGameDescription");
		if (!lua_isnil(L, -1)) {
			const char *_tmp11 = luaL_checkstring(L, -1);
			if (strlen(_tmp11) >= 64) luaL_error(L, "String too long");
			memcpy(ptr->m_szGameDescription, _tmp11, sizeof(ptr->m_szGameDescription));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nAppID");
		if (!lua_isnil(L, -1)) {
			ptr->m_nAppID = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nPlayers");
		if (!lua_isnil(L, -1)) {
			ptr->m_nPlayers = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nMaxPlayers");
		if (!lua_isnil(L, -1)) {
			ptr->m_nMaxPlayers = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nBotPlayers");
		if (!lua_isnil(L, -1)) {
			ptr->m_nBotPlayers = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bPassword");
		if (!lua_isnil(L, -1)) {
			ptr->m_bPassword = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bSecure");
		if (!lua_isnil(L, -1)) {
			ptr->m_bSecure = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_ulTimeLastPlayed");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulTimeLastPlayed = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nServerVersion");
		if (!lua_isnil(L, -1)) {
			ptr->m_nServerVersion = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_szGameTags");
		if (!lua_isnil(L, -1)) {
			const char *_tmp13 = luaL_checkstring(L, -1);
			if (strlen(_tmp13) >= 128) luaL_error(L, "String too long");
			memcpy(ptr->m_szGameTags, _tmp13, sizeof(ptr->m_szGameTags));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_steamID");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamID = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, gameserveritem_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamPartyBeaconLocation_tMetatable_ref = LUA_NOREF;

static int SteamPartyBeaconLocation_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamPartyBeaconLocation_t *self = (SteamPartyBeaconLocation_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eType") == 0) {
		lua_pushinteger(L, self->m_eType);
		return 1;
	}
	if (strcmp(key, "m_ulLocationID") == 0) {
		luasteam::pushuint64(L, self->m_ulLocationID);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamPartyBeaconLocation_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamPartyBeaconLocation_t *self = (SteamPartyBeaconLocation_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eType") == 0) {
		self->m_eType = static_cast<ESteamPartyBeaconLocationType>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_ulLocationID") == 0) {
		self->m_ulLocationID = luasteam::checkuint64(L, 3);
		return 0;
	}
	return luaL_error(L, "SteamPartyBeaconLocation_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamPartyBeaconLocation_t(lua_State *L) {
	SteamPartyBeaconLocation_t *ptr = (SteamPartyBeaconLocation_t*)lua_newuserdata(L, sizeof(SteamPartyBeaconLocation_t));
	new (ptr) SteamPartyBeaconLocation_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eType");
		if (!lua_isnil(L, -1)) {
			ptr->m_eType = static_cast<ESteamPartyBeaconLocationType>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_ulLocationID");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulLocationID = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamPartyBeaconLocation_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamParamStringArray_tMetatable_ref = LUA_NOREF;

static int SteamParamStringArray_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamParamStringArray_t *self = (SteamParamStringArray_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_ppStrings") == 0) {
		lua_newtable(L);
		for (int32 _i = 0; _i < self->m_nNumStrings; _i++) {
			lua_pushstring(L, self->m_ppStrings[_i]);
			lua_rawseti(L, -2, _i + 1);
		}
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamParamStringArray_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamParamStringArray_t *self = (SteamParamStringArray_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_ppStrings") == 0) {
		luaL_checktype(L, 3, LUA_TTABLE);
		if (self->m_ppStrings != nullptr) {
			for (int32 _i = 0; _i < self->m_nNumStrings; _i++)
			    free((void*)self->m_ppStrings[_i]);
			delete[] self->m_ppStrings;
		}
		int32 _n = (int32)lua_objlen(L, 3);
		const char **_arr = new const char*[_n];
		for (int32 _i = 0; _i < _n; _i++) {
			lua_rawgeti(L, 3, _i + 1);
			_arr[_i] = strdup(luaL_checkstring(L, -1));
			lua_pop(L, 1);
		}
		self->m_ppStrings = _arr;
		self->m_nNumStrings = _n;
		return 0;
	}
	return luaL_error(L, "SteamParamStringArray_t has no field '%%s'", key);
}

static int SteamParamStringArray_t_gc(lua_State *L) {
	SteamParamStringArray_t *self = (SteamParamStringArray_t*)lua_touserdata(L, 1);
	if (self->m_ppStrings != nullptr) {
		for (int32 _i = 0; _i < self->m_nNumStrings; _i++)
		    free((void*)self->m_ppStrings[_i]);
		delete[] self->m_ppStrings;
	}
	return 0;
}

EXTERN int luasteam_newSteamParamStringArray_t(lua_State *L) {
	SteamParamStringArray_t *ptr = (SteamParamStringArray_t*)lua_newuserdata(L, sizeof(SteamParamStringArray_t));
	new (ptr) SteamParamStringArray_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_ppStrings");
		if (lua_istable(L, -1)) {
			int32 _n = (int32)lua_objlen(L, -1);
			const char **_arr = new const char*[_n];
			for (int32 _i = 0; _i < _n; _i++) {
				lua_rawgeti(L, -1, _i + 1);
				_arr[_i] = strdup(luaL_checkstring(L, -1));
				lua_pop(L, 1);
			}
			ptr->m_ppStrings = _arr;
			ptr->m_nNumStrings = _n;
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamParamStringArray_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int LeaderboardEntry_tMetatable_ref = LUA_NOREF;

static int LeaderboardEntry_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	LeaderboardEntry_t *self = (LeaderboardEntry_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamIDUser") == 0) {
		luasteam::pushuint64(L, self->m_steamIDUser.ConvertToUint64());
		return 1;
	}
	if (strcmp(key, "m_nGlobalRank") == 0) {
		lua_pushinteger(L, self->m_nGlobalRank);
		return 1;
	}
	if (strcmp(key, "m_nScore") == 0) {
		lua_pushinteger(L, self->m_nScore);
		return 1;
	}
	if (strcmp(key, "m_cDetails") == 0) {
		lua_pushinteger(L, self->m_cDetails);
		return 1;
	}
	if (strcmp(key, "m_hUGC") == 0) {
		luasteam::pushuint64(L, self->m_hUGC);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int LeaderboardEntry_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	LeaderboardEntry_t *self = (LeaderboardEntry_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamIDUser") == 0) {
		self->m_steamIDUser = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nGlobalRank") == 0) {
		self->m_nGlobalRank = static_cast<int32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nScore") == 0) {
		self->m_nScore = static_cast<int32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_cDetails") == 0) {
		self->m_cDetails = static_cast<int32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_hUGC") == 0) {
		self->m_hUGC = luasteam::checkuint64(L, 3);
		return 0;
	}
	return luaL_error(L, "LeaderboardEntry_t has no field '%%s'", key);
}

EXTERN int luasteam_newLeaderboardEntry_t(lua_State *L) {
	LeaderboardEntry_t *ptr = (LeaderboardEntry_t*)lua_newuserdata(L, sizeof(LeaderboardEntry_t));
	new (ptr) LeaderboardEntry_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_steamIDUser");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamIDUser = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nGlobalRank");
		if (!lua_isnil(L, -1)) {
			ptr->m_nGlobalRank = static_cast<int32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nScore");
		if (!lua_isnil(L, -1)) {
			ptr->m_nScore = static_cast<int32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_cDetails");
		if (!lua_isnil(L, -1)) {
			ptr->m_cDetails = static_cast<int32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_hUGC");
		if (!lua_isnil(L, -1)) {
			ptr->m_hUGC = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, LeaderboardEntry_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int P2PSessionState_tMetatable_ref = LUA_NOREF;

static int P2PSessionState_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	P2PSessionState_t *self = (P2PSessionState_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_bConnectionActive") == 0) {
		lua_pushinteger(L, self->m_bConnectionActive);
		return 1;
	}
	if (strcmp(key, "m_bConnecting") == 0) {
		lua_pushinteger(L, self->m_bConnecting);
		return 1;
	}
	if (strcmp(key, "m_eP2PSessionError") == 0) {
		lua_pushinteger(L, self->m_eP2PSessionError);
		return 1;
	}
	if (strcmp(key, "m_bUsingRelay") == 0) {
		lua_pushinteger(L, self->m_bUsingRelay);
		return 1;
	}
	if (strcmp(key, "m_nBytesQueuedForSend") == 0) {
		lua_pushinteger(L, self->m_nBytesQueuedForSend);
		return 1;
	}
	if (strcmp(key, "m_nPacketsQueuedForSend") == 0) {
		lua_pushinteger(L, self->m_nPacketsQueuedForSend);
		return 1;
	}
	if (strcmp(key, "m_nRemoteIP") == 0) {
		lua_pushinteger(L, self->m_nRemoteIP);
		return 1;
	}
	if (strcmp(key, "m_nRemotePort") == 0) {
		lua_pushinteger(L, self->m_nRemotePort);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int P2PSessionState_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	P2PSessionState_t *self = (P2PSessionState_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_bConnectionActive") == 0) {
		self->m_bConnectionActive = static_cast<uint8>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bConnecting") == 0) {
		self->m_bConnecting = static_cast<uint8>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_eP2PSessionError") == 0) {
		self->m_eP2PSessionError = static_cast<uint8>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bUsingRelay") == 0) {
		self->m_bUsingRelay = static_cast<uint8>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nBytesQueuedForSend") == 0) {
		self->m_nBytesQueuedForSend = static_cast<int32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nPacketsQueuedForSend") == 0) {
		self->m_nPacketsQueuedForSend = static_cast<int32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nRemoteIP") == 0) {
		self->m_nRemoteIP = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nRemotePort") == 0) {
		self->m_nRemotePort = static_cast<uint16>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "P2PSessionState_t has no field '%%s'", key);
}

EXTERN int luasteam_newP2PSessionState_t(lua_State *L) {
	P2PSessionState_t *ptr = (P2PSessionState_t*)lua_newuserdata(L, sizeof(P2PSessionState_t));
	new (ptr) P2PSessionState_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_bConnectionActive");
		if (!lua_isnil(L, -1)) {
			ptr->m_bConnectionActive = static_cast<uint8>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bConnecting");
		if (!lua_isnil(L, -1)) {
			ptr->m_bConnecting = static_cast<uint8>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eP2PSessionError");
		if (!lua_isnil(L, -1)) {
			ptr->m_eP2PSessionError = static_cast<uint8>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bUsingRelay");
		if (!lua_isnil(L, -1)) {
			ptr->m_bUsingRelay = static_cast<uint8>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nBytesQueuedForSend");
		if (!lua_isnil(L, -1)) {
			ptr->m_nBytesQueuedForSend = static_cast<int32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nPacketsQueuedForSend");
		if (!lua_isnil(L, -1)) {
			ptr->m_nPacketsQueuedForSend = static_cast<int32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nRemoteIP");
		if (!lua_isnil(L, -1)) {
			ptr->m_nRemoteIP = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nRemotePort");
		if (!lua_isnil(L, -1)) {
			ptr->m_nRemotePort = static_cast<uint16>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, P2PSessionState_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int InputAnalogActionData_tMetatable_ref = LUA_NOREF;

static int InputAnalogActionData_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	InputAnalogActionData_t *self = (InputAnalogActionData_t*)lua_touserdata(L, 1);
	if (strcmp(key, "eMode") == 0) {
		lua_pushinteger(L, self->eMode);
		return 1;
	}
	if (strcmp(key, "x") == 0) {
		lua_pushnumber(L, self->x);
		return 1;
	}
	if (strcmp(key, "y") == 0) {
		lua_pushnumber(L, self->y);
		return 1;
	}
	if (strcmp(key, "bActive") == 0) {
		lua_pushboolean(L, self->bActive);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int InputAnalogActionData_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	InputAnalogActionData_t *self = (InputAnalogActionData_t*)lua_touserdata(L, 1);
	if (strcmp(key, "eMode") == 0) {
		self->eMode = static_cast<EInputSourceMode>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "x") == 0) {
		self->x = static_cast<float>(luaL_checknumber(L, 3));
		return 0;
	}
	if (strcmp(key, "y") == 0) {
		self->y = static_cast<float>(luaL_checknumber(L, 3));
		return 0;
	}
	if (strcmp(key, "bActive") == 0) {
		self->bActive = lua_toboolean(L, 3);
		return 0;
	}
	return luaL_error(L, "InputAnalogActionData_t has no field '%%s'", key);
}

EXTERN int luasteam_newInputAnalogActionData_t(lua_State *L) {
	InputAnalogActionData_t *ptr = (InputAnalogActionData_t*)lua_newuserdata(L, sizeof(InputAnalogActionData_t));
	new (ptr) InputAnalogActionData_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "eMode");
		if (!lua_isnil(L, -1)) {
			ptr->eMode = static_cast<EInputSourceMode>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "x");
		if (!lua_isnil(L, -1)) {
			ptr->x = static_cast<float>(luaL_checknumber(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "y");
		if (!lua_isnil(L, -1)) {
			ptr->y = static_cast<float>(luaL_checknumber(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "bActive");
		if (!lua_isnil(L, -1)) {
			ptr->bActive = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, InputAnalogActionData_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int InputDigitalActionData_tMetatable_ref = LUA_NOREF;

static int InputDigitalActionData_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	InputDigitalActionData_t *self = (InputDigitalActionData_t*)lua_touserdata(L, 1);
	if (strcmp(key, "bState") == 0) {
		lua_pushboolean(L, self->bState);
		return 1;
	}
	if (strcmp(key, "bActive") == 0) {
		lua_pushboolean(L, self->bActive);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int InputDigitalActionData_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	InputDigitalActionData_t *self = (InputDigitalActionData_t*)lua_touserdata(L, 1);
	if (strcmp(key, "bState") == 0) {
		self->bState = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "bActive") == 0) {
		self->bActive = lua_toboolean(L, 3);
		return 0;
	}
	return luaL_error(L, "InputDigitalActionData_t has no field '%%s'", key);
}

EXTERN int luasteam_newInputDigitalActionData_t(lua_State *L) {
	InputDigitalActionData_t *ptr = (InputDigitalActionData_t*)lua_newuserdata(L, sizeof(InputDigitalActionData_t));
	new (ptr) InputDigitalActionData_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "bState");
		if (!lua_isnil(L, -1)) {
			ptr->bState = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "bActive");
		if (!lua_isnil(L, -1)) {
			ptr->bActive = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, InputDigitalActionData_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int InputMotionData_tMetatable_ref = LUA_NOREF;

static int InputMotionData_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	InputMotionData_t *self = (InputMotionData_t*)lua_touserdata(L, 1);
	if (strcmp(key, "rotQuatX") == 0) {
		lua_pushnumber(L, self->rotQuatX);
		return 1;
	}
	if (strcmp(key, "rotQuatY") == 0) {
		lua_pushnumber(L, self->rotQuatY);
		return 1;
	}
	if (strcmp(key, "rotQuatZ") == 0) {
		lua_pushnumber(L, self->rotQuatZ);
		return 1;
	}
	if (strcmp(key, "rotQuatW") == 0) {
		lua_pushnumber(L, self->rotQuatW);
		return 1;
	}
	if (strcmp(key, "posAccelX") == 0) {
		lua_pushnumber(L, self->posAccelX);
		return 1;
	}
	if (strcmp(key, "posAccelY") == 0) {
		lua_pushnumber(L, self->posAccelY);
		return 1;
	}
	if (strcmp(key, "posAccelZ") == 0) {
		lua_pushnumber(L, self->posAccelZ);
		return 1;
	}
	if (strcmp(key, "rotVelX") == 0) {
		lua_pushnumber(L, self->rotVelX);
		return 1;
	}
	if (strcmp(key, "rotVelY") == 0) {
		lua_pushnumber(L, self->rotVelY);
		return 1;
	}
	if (strcmp(key, "rotVelZ") == 0) {
		lua_pushnumber(L, self->rotVelZ);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int InputMotionData_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	InputMotionData_t *self = (InputMotionData_t*)lua_touserdata(L, 1);
	if (strcmp(key, "rotQuatX") == 0) {
		self->rotQuatX = static_cast<float>(luaL_checknumber(L, 3));
		return 0;
	}
	if (strcmp(key, "rotQuatY") == 0) {
		self->rotQuatY = static_cast<float>(luaL_checknumber(L, 3));
		return 0;
	}
	if (strcmp(key, "rotQuatZ") == 0) {
		self->rotQuatZ = static_cast<float>(luaL_checknumber(L, 3));
		return 0;
	}
	if (strcmp(key, "rotQuatW") == 0) {
		self->rotQuatW = static_cast<float>(luaL_checknumber(L, 3));
		return 0;
	}
	if (strcmp(key, "posAccelX") == 0) {
		self->posAccelX = static_cast<float>(luaL_checknumber(L, 3));
		return 0;
	}
	if (strcmp(key, "posAccelY") == 0) {
		self->posAccelY = static_cast<float>(luaL_checknumber(L, 3));
		return 0;
	}
	if (strcmp(key, "posAccelZ") == 0) {
		self->posAccelZ = static_cast<float>(luaL_checknumber(L, 3));
		return 0;
	}
	if (strcmp(key, "rotVelX") == 0) {
		self->rotVelX = static_cast<float>(luaL_checknumber(L, 3));
		return 0;
	}
	if (strcmp(key, "rotVelY") == 0) {
		self->rotVelY = static_cast<float>(luaL_checknumber(L, 3));
		return 0;
	}
	if (strcmp(key, "rotVelZ") == 0) {
		self->rotVelZ = static_cast<float>(luaL_checknumber(L, 3));
		return 0;
	}
	return luaL_error(L, "InputMotionData_t has no field '%%s'", key);
}

EXTERN int luasteam_newInputMotionData_t(lua_State *L) {
	InputMotionData_t *ptr = (InputMotionData_t*)lua_newuserdata(L, sizeof(InputMotionData_t));
	new (ptr) InputMotionData_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "rotQuatX");
		if (!lua_isnil(L, -1)) {
			ptr->rotQuatX = static_cast<float>(luaL_checknumber(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "rotQuatY");
		if (!lua_isnil(L, -1)) {
			ptr->rotQuatY = static_cast<float>(luaL_checknumber(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "rotQuatZ");
		if (!lua_isnil(L, -1)) {
			ptr->rotQuatZ = static_cast<float>(luaL_checknumber(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "rotQuatW");
		if (!lua_isnil(L, -1)) {
			ptr->rotQuatW = static_cast<float>(luaL_checknumber(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "posAccelX");
		if (!lua_isnil(L, -1)) {
			ptr->posAccelX = static_cast<float>(luaL_checknumber(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "posAccelY");
		if (!lua_isnil(L, -1)) {
			ptr->posAccelY = static_cast<float>(luaL_checknumber(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "posAccelZ");
		if (!lua_isnil(L, -1)) {
			ptr->posAccelZ = static_cast<float>(luaL_checknumber(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "rotVelX");
		if (!lua_isnil(L, -1)) {
			ptr->rotVelX = static_cast<float>(luaL_checknumber(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "rotVelY");
		if (!lua_isnil(L, -1)) {
			ptr->rotVelY = static_cast<float>(luaL_checknumber(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "rotVelZ");
		if (!lua_isnil(L, -1)) {
			ptr->rotVelZ = static_cast<float>(luaL_checknumber(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, InputMotionData_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamInputActionEvent_tMetatable_ref = LUA_NOREF;

static int SteamInputActionEvent_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamInputActionEvent_t *self = (SteamInputActionEvent_t*)lua_touserdata(L, 1);
	if (strcmp(key, "controllerHandle") == 0) {
		luasteam::pushuint64(L, self->controllerHandle);
		return 1;
	}
	if (strcmp(key, "eEventType") == 0) {
		lua_pushinteger(L, self->eEventType);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamInputActionEvent_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamInputActionEvent_t *self = (SteamInputActionEvent_t*)lua_touserdata(L, 1);
	if (strcmp(key, "controllerHandle") == 0) {
		self->controllerHandle = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "eEventType") == 0) {
		self->eEventType = static_cast<ESteamInputActionEventType>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "SteamInputActionEvent_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamInputActionEvent_t(lua_State *L) {
	SteamInputActionEvent_t *ptr = (SteamInputActionEvent_t*)lua_newuserdata(L, sizeof(SteamInputActionEvent_t));
	new (ptr) SteamInputActionEvent_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "controllerHandle");
		if (!lua_isnil(L, -1)) {
			ptr->controllerHandle = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "eEventType");
		if (!lua_isnil(L, -1)) {
			ptr->eEventType = static_cast<ESteamInputActionEventType>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInputActionEvent_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamUGCDetails_tMetatable_ref = LUA_NOREF;

static int SteamUGCDetails_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamUGCDetails_t *self = (SteamUGCDetails_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		luasteam::pushuint64(L, self->m_nPublishedFileId);
		return 1;
	}
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_eFileType") == 0) {
		lua_pushinteger(L, self->m_eFileType);
		return 1;
	}
	if (strcmp(key, "m_nCreatorAppID") == 0) {
		lua_pushinteger(L, self->m_nCreatorAppID);
		return 1;
	}
	if (strcmp(key, "m_nConsumerAppID") == 0) {
		lua_pushinteger(L, self->m_nConsumerAppID);
		return 1;
	}
	if (strcmp(key, "m_rgchTitle") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->m_rgchTitle));
		return 1;
	}
	if (strcmp(key, "m_rgchDescription") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->m_rgchDescription));
		return 1;
	}
	if (strcmp(key, "m_ulSteamIDOwner") == 0) {
		luasteam::pushuint64(L, self->m_ulSteamIDOwner);
		return 1;
	}
	if (strcmp(key, "m_rtimeCreated") == 0) {
		lua_pushinteger(L, self->m_rtimeCreated);
		return 1;
	}
	if (strcmp(key, "m_rtimeUpdated") == 0) {
		lua_pushinteger(L, self->m_rtimeUpdated);
		return 1;
	}
	if (strcmp(key, "m_rtimeAddedToUserList") == 0) {
		lua_pushinteger(L, self->m_rtimeAddedToUserList);
		return 1;
	}
	if (strcmp(key, "m_eVisibility") == 0) {
		lua_pushinteger(L, self->m_eVisibility);
		return 1;
	}
	if (strcmp(key, "m_bBanned") == 0) {
		lua_pushboolean(L, self->m_bBanned);
		return 1;
	}
	if (strcmp(key, "m_bAcceptedForUse") == 0) {
		lua_pushboolean(L, self->m_bAcceptedForUse);
		return 1;
	}
	if (strcmp(key, "m_bTagsTruncated") == 0) {
		lua_pushboolean(L, self->m_bTagsTruncated);
		return 1;
	}
	if (strcmp(key, "m_rgchTags") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->m_rgchTags));
		return 1;
	}
	if (strcmp(key, "m_hFile") == 0) {
		luasteam::pushuint64(L, self->m_hFile);
		return 1;
	}
	if (strcmp(key, "m_hPreviewFile") == 0) {
		luasteam::pushuint64(L, self->m_hPreviewFile);
		return 1;
	}
	if (strcmp(key, "m_pchFileName") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->m_pchFileName));
		return 1;
	}
	if (strcmp(key, "m_nFileSize") == 0) {
		lua_pushinteger(L, self->m_nFileSize);
		return 1;
	}
	if (strcmp(key, "m_nPreviewFileSize") == 0) {
		lua_pushinteger(L, self->m_nPreviewFileSize);
		return 1;
	}
	if (strcmp(key, "m_rgchURL") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->m_rgchURL));
		return 1;
	}
	if (strcmp(key, "m_unVotesUp") == 0) {
		lua_pushinteger(L, self->m_unVotesUp);
		return 1;
	}
	if (strcmp(key, "m_unVotesDown") == 0) {
		lua_pushinteger(L, self->m_unVotesDown);
		return 1;
	}
	if (strcmp(key, "m_flScore") == 0) {
		lua_pushnumber(L, self->m_flScore);
		return 1;
	}
	if (strcmp(key, "m_unNumChildren") == 0) {
		lua_pushinteger(L, self->m_unNumChildren);
		return 1;
	}
	if (strcmp(key, "m_ulTotalFilesSize") == 0) {
		luasteam::pushuint64(L, self->m_ulTotalFilesSize);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamUGCDetails_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamUGCDetails_t *self = (SteamUGCDetails_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		self->m_nPublishedFileId = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_eFileType") == 0) {
		self->m_eFileType = static_cast<EWorkshopFileType>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nCreatorAppID") == 0) {
		self->m_nCreatorAppID = static_cast<AppId_t>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nConsumerAppID") == 0) {
		self->m_nConsumerAppID = static_cast<AppId_t>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_rgchTitle") == 0) {
		const char *_tmp14 = luaL_checkstring(L, 3);
		if (strlen(_tmp14) >= 129) luaL_error(L, "String too long");
		memcpy(self->m_rgchTitle, _tmp14, sizeof(self->m_rgchTitle));
		return 0;
	}
	if (strcmp(key, "m_rgchDescription") == 0) {
		const char *_tmp16 = luaL_checkstring(L, 3);
		if (strlen(_tmp16) >= 8000) luaL_error(L, "String too long");
		memcpy(self->m_rgchDescription, _tmp16, sizeof(self->m_rgchDescription));
		return 0;
	}
	if (strcmp(key, "m_ulSteamIDOwner") == 0) {
		self->m_ulSteamIDOwner = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_rtimeCreated") == 0) {
		self->m_rtimeCreated = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_rtimeUpdated") == 0) {
		self->m_rtimeUpdated = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_rtimeAddedToUserList") == 0) {
		self->m_rtimeAddedToUserList = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_eVisibility") == 0) {
		self->m_eVisibility = static_cast<ERemoteStoragePublishedFileVisibility>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bBanned") == 0) {
		self->m_bBanned = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_bAcceptedForUse") == 0) {
		self->m_bAcceptedForUse = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_bTagsTruncated") == 0) {
		self->m_bTagsTruncated = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_rgchTags") == 0) {
		const char *_tmp18 = luaL_checkstring(L, 3);
		if (strlen(_tmp18) >= 1025) luaL_error(L, "String too long");
		memcpy(self->m_rgchTags, _tmp18, sizeof(self->m_rgchTags));
		return 0;
	}
	if (strcmp(key, "m_hFile") == 0) {
		self->m_hFile = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_hPreviewFile") == 0) {
		self->m_hPreviewFile = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_pchFileName") == 0) {
		const char *_tmp20 = luaL_checkstring(L, 3);
		if (strlen(_tmp20) >= 260) luaL_error(L, "String too long");
		memcpy(self->m_pchFileName, _tmp20, sizeof(self->m_pchFileName));
		return 0;
	}
	if (strcmp(key, "m_nFileSize") == 0) {
		self->m_nFileSize = static_cast<int32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nPreviewFileSize") == 0) {
		self->m_nPreviewFileSize = static_cast<int32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_rgchURL") == 0) {
		const char *_tmp22 = luaL_checkstring(L, 3);
		if (strlen(_tmp22) >= 256) luaL_error(L, "String too long");
		memcpy(self->m_rgchURL, _tmp22, sizeof(self->m_rgchURL));
		return 0;
	}
	if (strcmp(key, "m_unVotesUp") == 0) {
		self->m_unVotesUp = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_unVotesDown") == 0) {
		self->m_unVotesDown = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_flScore") == 0) {
		self->m_flScore = static_cast<float>(luaL_checknumber(L, 3));
		return 0;
	}
	if (strcmp(key, "m_unNumChildren") == 0) {
		self->m_unNumChildren = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_ulTotalFilesSize") == 0) {
		self->m_ulTotalFilesSize = luasteam::checkuint64(L, 3);
		return 0;
	}
	return luaL_error(L, "SteamUGCDetails_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamUGCDetails_t(lua_State *L) {
	SteamUGCDetails_t *ptr = (SteamUGCDetails_t*)lua_newuserdata(L, sizeof(SteamUGCDetails_t));
	new (ptr) SteamUGCDetails_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_nPublishedFileId");
		if (!lua_isnil(L, -1)) {
			ptr->m_nPublishedFileId = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eFileType");
		if (!lua_isnil(L, -1)) {
			ptr->m_eFileType = static_cast<EWorkshopFileType>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nCreatorAppID");
		if (!lua_isnil(L, -1)) {
			ptr->m_nCreatorAppID = static_cast<AppId_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nConsumerAppID");
		if (!lua_isnil(L, -1)) {
			ptr->m_nConsumerAppID = static_cast<AppId_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rgchTitle");
		if (!lua_isnil(L, -1)) {
			const char *_tmp15 = luaL_checkstring(L, -1);
			if (strlen(_tmp15) >= 129) luaL_error(L, "String too long");
			memcpy(ptr->m_rgchTitle, _tmp15, sizeof(ptr->m_rgchTitle));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rgchDescription");
		if (!lua_isnil(L, -1)) {
			const char *_tmp17 = luaL_checkstring(L, -1);
			if (strlen(_tmp17) >= 8000) luaL_error(L, "String too long");
			memcpy(ptr->m_rgchDescription, _tmp17, sizeof(ptr->m_rgchDescription));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_ulSteamIDOwner");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulSteamIDOwner = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rtimeCreated");
		if (!lua_isnil(L, -1)) {
			ptr->m_rtimeCreated = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rtimeUpdated");
		if (!lua_isnil(L, -1)) {
			ptr->m_rtimeUpdated = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rtimeAddedToUserList");
		if (!lua_isnil(L, -1)) {
			ptr->m_rtimeAddedToUserList = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eVisibility");
		if (!lua_isnil(L, -1)) {
			ptr->m_eVisibility = static_cast<ERemoteStoragePublishedFileVisibility>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bBanned");
		if (!lua_isnil(L, -1)) {
			ptr->m_bBanned = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bAcceptedForUse");
		if (!lua_isnil(L, -1)) {
			ptr->m_bAcceptedForUse = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bTagsTruncated");
		if (!lua_isnil(L, -1)) {
			ptr->m_bTagsTruncated = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rgchTags");
		if (!lua_isnil(L, -1)) {
			const char *_tmp19 = luaL_checkstring(L, -1);
			if (strlen(_tmp19) >= 1025) luaL_error(L, "String too long");
			memcpy(ptr->m_rgchTags, _tmp19, sizeof(ptr->m_rgchTags));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_hFile");
		if (!lua_isnil(L, -1)) {
			ptr->m_hFile = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_hPreviewFile");
		if (!lua_isnil(L, -1)) {
			ptr->m_hPreviewFile = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_pchFileName");
		if (!lua_isnil(L, -1)) {
			const char *_tmp21 = luaL_checkstring(L, -1);
			if (strlen(_tmp21) >= 260) luaL_error(L, "String too long");
			memcpy(ptr->m_pchFileName, _tmp21, sizeof(ptr->m_pchFileName));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nFileSize");
		if (!lua_isnil(L, -1)) {
			ptr->m_nFileSize = static_cast<int32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nPreviewFileSize");
		if (!lua_isnil(L, -1)) {
			ptr->m_nPreviewFileSize = static_cast<int32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rgchURL");
		if (!lua_isnil(L, -1)) {
			const char *_tmp23 = luaL_checkstring(L, -1);
			if (strlen(_tmp23) >= 256) luaL_error(L, "String too long");
			memcpy(ptr->m_rgchURL, _tmp23, sizeof(ptr->m_rgchURL));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unVotesUp");
		if (!lua_isnil(L, -1)) {
			ptr->m_unVotesUp = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unVotesDown");
		if (!lua_isnil(L, -1)) {
			ptr->m_unVotesDown = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_flScore");
		if (!lua_isnil(L, -1)) {
			ptr->m_flScore = static_cast<float>(luaL_checknumber(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unNumChildren");
		if (!lua_isnil(L, -1)) {
			ptr->m_unNumChildren = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_ulTotalFilesSize");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulTotalFilesSize = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamUGCDetails_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamItemDetails_tMetatable_ref = LUA_NOREF;

static int SteamItemDetails_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamItemDetails_t *self = (SteamItemDetails_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_itemId") == 0) {
		luasteam::pushuint64(L, self->m_itemId);
		return 1;
	}
	if (strcmp(key, "m_iDefinition") == 0) {
		lua_pushinteger(L, self->m_iDefinition);
		return 1;
	}
	if (strcmp(key, "m_unQuantity") == 0) {
		lua_pushinteger(L, self->m_unQuantity);
		return 1;
	}
	if (strcmp(key, "m_unFlags") == 0) {
		lua_pushinteger(L, self->m_unFlags);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamItemDetails_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamItemDetails_t *self = (SteamItemDetails_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_itemId") == 0) {
		self->m_itemId = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_iDefinition") == 0) {
		self->m_iDefinition = static_cast<SteamItemDef_t>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_unQuantity") == 0) {
		self->m_unQuantity = static_cast<uint16>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_unFlags") == 0) {
		self->m_unFlags = static_cast<uint16>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "SteamItemDetails_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamItemDetails_t(lua_State *L) {
	SteamItemDetails_t *ptr = (SteamItemDetails_t*)lua_newuserdata(L, sizeof(SteamItemDetails_t));
	new (ptr) SteamItemDetails_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_itemId");
		if (!lua_isnil(L, -1)) {
			ptr->m_itemId = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_iDefinition");
		if (!lua_isnil(L, -1)) {
			ptr->m_iDefinition = static_cast<SteamItemDef_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unQuantity");
		if (!lua_isnil(L, -1)) {
			ptr->m_unQuantity = static_cast<uint16>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unFlags");
		if (!lua_isnil(L, -1)) {
			ptr->m_unFlags = static_cast<uint16>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamItemDetails_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemotePlayInputMouseMotion_tMetatable_ref = LUA_NOREF;

static int RemotePlayInputMouseMotion_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	RemotePlayInputMouseMotion_t *self = (RemotePlayInputMouseMotion_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_bAbsolute") == 0) {
		lua_pushboolean(L, self->m_bAbsolute);
		return 1;
	}
	if (strcmp(key, "m_flNormalizedX") == 0) {
		lua_pushnumber(L, self->m_flNormalizedX);
		return 1;
	}
	if (strcmp(key, "m_flNormalizedY") == 0) {
		lua_pushnumber(L, self->m_flNormalizedY);
		return 1;
	}
	if (strcmp(key, "m_nDeltaX") == 0) {
		lua_pushinteger(L, self->m_nDeltaX);
		return 1;
	}
	if (strcmp(key, "m_nDeltaY") == 0) {
		lua_pushinteger(L, self->m_nDeltaY);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int RemotePlayInputMouseMotion_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	RemotePlayInputMouseMotion_t *self = (RemotePlayInputMouseMotion_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_bAbsolute") == 0) {
		self->m_bAbsolute = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_flNormalizedX") == 0) {
		self->m_flNormalizedX = static_cast<float>(luaL_checknumber(L, 3));
		return 0;
	}
	if (strcmp(key, "m_flNormalizedY") == 0) {
		self->m_flNormalizedY = static_cast<float>(luaL_checknumber(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nDeltaX") == 0) {
		self->m_nDeltaX = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nDeltaY") == 0) {
		self->m_nDeltaY = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "RemotePlayInputMouseMotion_t has no field '%%s'", key);
}

EXTERN int luasteam_newRemotePlayInputMouseMotion_t(lua_State *L) {
	RemotePlayInputMouseMotion_t *ptr = (RemotePlayInputMouseMotion_t*)lua_newuserdata(L, sizeof(RemotePlayInputMouseMotion_t));
	new (ptr) RemotePlayInputMouseMotion_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_bAbsolute");
		if (!lua_isnil(L, -1)) {
			ptr->m_bAbsolute = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_flNormalizedX");
		if (!lua_isnil(L, -1)) {
			ptr->m_flNormalizedX = static_cast<float>(luaL_checknumber(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_flNormalizedY");
		if (!lua_isnil(L, -1)) {
			ptr->m_flNormalizedY = static_cast<float>(luaL_checknumber(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nDeltaX");
		if (!lua_isnil(L, -1)) {
			ptr->m_nDeltaX = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nDeltaY");
		if (!lua_isnil(L, -1)) {
			ptr->m_nDeltaY = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemotePlayInputMouseMotion_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemotePlayInputMouseWheel_tMetatable_ref = LUA_NOREF;

static int RemotePlayInputMouseWheel_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	RemotePlayInputMouseWheel_t *self = (RemotePlayInputMouseWheel_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eDirection") == 0) {
		lua_pushinteger(L, self->m_eDirection);
		return 1;
	}
	if (strcmp(key, "m_flAmount") == 0) {
		lua_pushnumber(L, self->m_flAmount);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int RemotePlayInputMouseWheel_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	RemotePlayInputMouseWheel_t *self = (RemotePlayInputMouseWheel_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eDirection") == 0) {
		self->m_eDirection = static_cast<ERemotePlayMouseWheelDirection>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_flAmount") == 0) {
		self->m_flAmount = static_cast<float>(luaL_checknumber(L, 3));
		return 0;
	}
	return luaL_error(L, "RemotePlayInputMouseWheel_t has no field '%%s'", key);
}

EXTERN int luasteam_newRemotePlayInputMouseWheel_t(lua_State *L) {
	RemotePlayInputMouseWheel_t *ptr = (RemotePlayInputMouseWheel_t*)lua_newuserdata(L, sizeof(RemotePlayInputMouseWheel_t));
	new (ptr) RemotePlayInputMouseWheel_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eDirection");
		if (!lua_isnil(L, -1)) {
			ptr->m_eDirection = static_cast<ERemotePlayMouseWheelDirection>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_flAmount");
		if (!lua_isnil(L, -1)) {
			ptr->m_flAmount = static_cast<float>(luaL_checknumber(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemotePlayInputMouseWheel_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemotePlayInputKey_tMetatable_ref = LUA_NOREF;

static int RemotePlayInputKey_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	RemotePlayInputKey_t *self = (RemotePlayInputKey_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eScancode") == 0) {
		lua_pushinteger(L, self->m_eScancode);
		return 1;
	}
	if (strcmp(key, "m_unModifiers") == 0) {
		lua_pushinteger(L, self->m_unModifiers);
		return 1;
	}
	if (strcmp(key, "m_unKeycode") == 0) {
		lua_pushinteger(L, self->m_unKeycode);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int RemotePlayInputKey_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	RemotePlayInputKey_t *self = (RemotePlayInputKey_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eScancode") == 0) {
		self->m_eScancode = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_unModifiers") == 0) {
		self->m_unModifiers = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_unKeycode") == 0) {
		self->m_unKeycode = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "RemotePlayInputKey_t has no field '%%s'", key);
}

EXTERN int luasteam_newRemotePlayInputKey_t(lua_State *L) {
	RemotePlayInputKey_t *ptr = (RemotePlayInputKey_t*)lua_newuserdata(L, sizeof(RemotePlayInputKey_t));
	new (ptr) RemotePlayInputKey_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eScancode");
		if (!lua_isnil(L, -1)) {
			ptr->m_eScancode = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unModifiers");
		if (!lua_isnil(L, -1)) {
			ptr->m_unModifiers = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unKeycode");
		if (!lua_isnil(L, -1)) {
			ptr->m_unKeycode = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemotePlayInputKey_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemotePlayInput_tMetatable_ref = LUA_NOREF;

static int RemotePlayInput_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	RemotePlayInput_t *self = (RemotePlayInput_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_unSessionID") == 0) {
		lua_pushinteger(L, self->m_unSessionID);
		return 1;
	}
	if (strcmp(key, "m_eType") == 0) {
		lua_pushinteger(L, self->m_eType);
		return 1;
	}
	if (strcmp(key, "padding") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->padding));
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int RemotePlayInput_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	RemotePlayInput_t *self = (RemotePlayInput_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_unSessionID") == 0) {
		self->m_unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_eType") == 0) {
		self->m_eType = static_cast<ERemotePlayInputType>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "padding") == 0) {
		const char *_tmp24 = luaL_checkstring(L, 3);
		if (strlen(_tmp24) >= 56) luaL_error(L, "String too long");
		memcpy(self->padding, _tmp24, sizeof(self->padding));
		return 0;
	}
	return luaL_error(L, "RemotePlayInput_t has no field '%%s'", key);
}

EXTERN int luasteam_newRemotePlayInput_t(lua_State *L) {
	RemotePlayInput_t *ptr = (RemotePlayInput_t*)lua_newuserdata(L, sizeof(RemotePlayInput_t));
	new (ptr) RemotePlayInput_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_unSessionID");
		if (!lua_isnil(L, -1)) {
			ptr->m_unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eType");
		if (!lua_isnil(L, -1)) {
			ptr->m_eType = static_cast<ERemotePlayInputType>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "padding");
		if (!lua_isnil(L, -1)) {
			const char *_tmp25 = luaL_checkstring(L, -1);
			if (strlen(_tmp25) >= 56) luaL_error(L, "String too long");
			memcpy(ptr->padding, _tmp25, sizeof(ptr->padding));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemotePlayInput_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamNetworkingIPAddrMetatable_ref = LUA_NOREF;

static int luasteam_SteamNetworkingIPAddr_Clear(lua_State *L) {
	SteamNetworkingIPAddr *self = luasteam::check_SteamNetworkingIPAddr_ptr(L, 1);
	self->Clear();
	return 0;
}
static int luasteam_SteamNetworkingIPAddr_IsIPv6AllZeros(lua_State *L) {
	SteamNetworkingIPAddr *self = luasteam::check_SteamNetworkingIPAddr_ptr(L, 1);
	bool __ret = self->IsIPv6AllZeros();
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_SteamNetworkingIPAddr_SetIPv6(lua_State *L) {
	SteamNetworkingIPAddr *self = luasteam::check_SteamNetworkingIPAddr_ptr(L, 1);
	const unsigned char *ipv6 = reinterpret_cast<const unsigned char *>(luaL_checkstring(L, 2));
	uint16 nPort = static_cast<uint16>(luaL_checkint(L, 3));
	self->SetIPv6(ipv6, nPort);
	return 0;
}
static int luasteam_SteamNetworkingIPAddr_SetIPv4(lua_State *L) {
	SteamNetworkingIPAddr *self = luasteam::check_SteamNetworkingIPAddr_ptr(L, 1);
	uint32 nIP = static_cast<uint32>(luaL_checkint(L, 2));
	uint16 nPort = static_cast<uint16>(luaL_checkint(L, 3));
	self->SetIPv4(nIP, nPort);
	return 0;
}
static int luasteam_SteamNetworkingIPAddr_IsIPv4(lua_State *L) {
	SteamNetworkingIPAddr *self = luasteam::check_SteamNetworkingIPAddr_ptr(L, 1);
	bool __ret = self->IsIPv4();
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_SteamNetworkingIPAddr_GetIPv4(lua_State *L) {
	SteamNetworkingIPAddr *self = luasteam::check_SteamNetworkingIPAddr_ptr(L, 1);
	uint32 __ret = self->GetIPv4();
	lua_pushinteger(L, __ret);
	return 1;
}
static int luasteam_SteamNetworkingIPAddr_SetIPv6LocalHost(lua_State *L) {
	SteamNetworkingIPAddr *self = luasteam::check_SteamNetworkingIPAddr_ptr(L, 1);
	uint16 nPort = static_cast<uint16>(luaL_checkint(L, 2));
	self->SetIPv6LocalHost(nPort);
	return 0;
}
static int luasteam_SteamNetworkingIPAddr_IsLocalHost(lua_State *L) {
	SteamNetworkingIPAddr *self = luasteam::check_SteamNetworkingIPAddr_ptr(L, 1);
	bool __ret = self->IsLocalHost();
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_SteamNetworkingIPAddr_ParseString(lua_State *L) {
	SteamNetworkingIPAddr *self = luasteam::check_SteamNetworkingIPAddr_ptr(L, 1);
	const char *pszStr = luaL_checkstring(L, 2);
	bool __ret = self->ParseString(pszStr);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_SteamNetworkingIPAddr_GetFakeIPType(lua_State *L) {
	SteamNetworkingIPAddr *self = luasteam::check_SteamNetworkingIPAddr_ptr(L, 1);
	ESteamNetworkingFakeIPType __ret = self->GetFakeIPType();
	lua_pushinteger(L, __ret);
	return 1;
}
static int luasteam_SteamNetworkingIPAddr_IsFakeIP(lua_State *L) {
	SteamNetworkingIPAddr *self = luasteam::check_SteamNetworkingIPAddr_ptr(L, 1);
	bool __ret = self->IsFakeIP();
	lua_pushboolean(L, __ret);
	return 1;
}
static int SteamNetworkingIPAddr_index(lua_State *L) {
	lua_getmetatable(L, 1);
	lua_pushvalue(L, 2);
	lua_rawget(L, -2);
	if (!lua_isnil(L, -1)) return 1;
	lua_pop(L, 2);
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamNetworkingIPAddr *self = (SteamNetworkingIPAddr*)lua_touserdata(L, 1);
	if (strcmp(key, "m_ipv6") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->m_ipv6));
		return 1;
	}
	if (strcmp(key, "m_port") == 0) {
		lua_pushinteger(L, self->m_port);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamNetworkingIPAddr_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamNetworkingIPAddr *self = (SteamNetworkingIPAddr*)lua_touserdata(L, 1);
	if (strcmp(key, "m_ipv6") == 0) {
		const char *_tmp26 = luaL_checkstring(L, 3);
		if (strlen(_tmp26) >= 16) luaL_error(L, "String too long");
		memcpy(self->m_ipv6, _tmp26, sizeof(self->m_ipv6));
		return 0;
	}
	if (strcmp(key, "m_port") == 0) {
		self->m_port = static_cast<uint16>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "SteamNetworkingIPAddr has no field '%%s'", key);
}

EXTERN int luasteam_newSteamNetworkingIPAddr(lua_State *L) {
	SteamNetworkingIPAddr *ptr = (SteamNetworkingIPAddr*)lua_newuserdata(L, sizeof(SteamNetworkingIPAddr));
	new (ptr) SteamNetworkingIPAddr();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_ipv6");
		if (!lua_isnil(L, -1)) {
			const char *_tmp27 = luaL_checkstring(L, -1);
			if (strlen(_tmp27) >= 16) luaL_error(L, "String too long");
			memcpy(ptr->m_ipv6, _tmp27, sizeof(ptr->m_ipv6));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_port");
		if (!lua_isnil(L, -1)) {
			ptr->m_port = static_cast<uint16>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetworkingIPAddrMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamNetworkingIdentityMetatable_ref = LUA_NOREF;

static int luasteam_SteamNetworkingIdentity_Clear(lua_State *L) {
	SteamNetworkingIdentity *self = luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	self->Clear();
	return 0;
}
static int luasteam_SteamNetworkingIdentity_IsInvalid(lua_State *L) {
	SteamNetworkingIdentity *self = luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	bool __ret = self->IsInvalid();
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_SteamNetworkingIdentity_SetSteamID(lua_State *L) {
	SteamNetworkingIdentity *self = luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	CSteamID steamID(luasteam::checkuint64(L, 2));
	self->SetSteamID(steamID);
	return 0;
}
static int luasteam_SteamNetworkingIdentity_GetSteamID(lua_State *L) {
	SteamNetworkingIdentity *self = luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	CSteamID __ret = self->GetSteamID();
	luasteam::pushuint64(L, __ret.ConvertToUint64());
	return 1;
}
static int luasteam_SteamNetworkingIdentity_SetSteamID64(lua_State *L) {
	SteamNetworkingIdentity *self = luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	uint64 steamID(luasteam::checkuint64(L, 2));
	self->SetSteamID64(steamID);
	return 0;
}
static int luasteam_SteamNetworkingIdentity_GetSteamID64(lua_State *L) {
	SteamNetworkingIdentity *self = luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	uint64 __ret = self->GetSteamID64();
	luasteam::pushuint64(L, __ret);
	return 1;
}
static int luasteam_SteamNetworkingIdentity_SetXboxPairwiseID(lua_State *L) {
	SteamNetworkingIdentity *self = luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	const char *pszString = luaL_checkstring(L, 2);
	bool __ret = self->SetXboxPairwiseID(pszString);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_SteamNetworkingIdentity_GetXboxPairwiseID(lua_State *L) {
	SteamNetworkingIdentity *self = luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	const char * __ret = self->GetXboxPairwiseID();
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}
static int luasteam_SteamNetworkingIdentity_SetPSNID(lua_State *L) {
	SteamNetworkingIdentity *self = luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	uint64 id(luasteam::checkuint64(L, 2));
	self->SetPSNID(id);
	return 0;
}
static int luasteam_SteamNetworkingIdentity_GetPSNID(lua_State *L) {
	SteamNetworkingIdentity *self = luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	uint64 __ret = self->GetPSNID();
	luasteam::pushuint64(L, __ret);
	return 1;
}
static int luasteam_SteamNetworkingIdentity_SetIPAddr(lua_State *L) {
	SteamNetworkingIdentity *self = luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	const SteamNetworkingIPAddr &addr = *luasteam::check_SteamNetworkingIPAddr_ptr(L, 2);
	self->SetIPAddr(addr);
	return 0;
}
static int luasteam_SteamNetworkingIdentity_GetIPAddr(lua_State *L) {
	SteamNetworkingIdentity *self = luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	const SteamNetworkingIPAddr *__ret = self->GetIPAddr();
	if (__ret != nullptr) {
		luasteam::push_SteamNetworkingIPAddr(L, *__ret);
	} else {
		lua_pushnil(L);
	}
	return 1;
}
static int luasteam_SteamNetworkingIdentity_SetIPv4Addr(lua_State *L) {
	SteamNetworkingIdentity *self = luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	uint32 nIPv4 = static_cast<uint32>(luaL_checkint(L, 2));
	uint16 nPort = static_cast<uint16>(luaL_checkint(L, 3));
	self->SetIPv4Addr(nIPv4, nPort);
	return 0;
}
static int luasteam_SteamNetworkingIdentity_GetIPv4(lua_State *L) {
	SteamNetworkingIdentity *self = luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	uint32 __ret = self->GetIPv4();
	lua_pushinteger(L, __ret);
	return 1;
}
static int luasteam_SteamNetworkingIdentity_GetFakeIPType(lua_State *L) {
	SteamNetworkingIdentity *self = luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	ESteamNetworkingFakeIPType __ret = self->GetFakeIPType();
	lua_pushinteger(L, __ret);
	return 1;
}
static int luasteam_SteamNetworkingIdentity_IsFakeIP(lua_State *L) {
	SteamNetworkingIdentity *self = luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	bool __ret = self->IsFakeIP();
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_SteamNetworkingIdentity_SetLocalHost(lua_State *L) {
	SteamNetworkingIdentity *self = luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	self->SetLocalHost();
	return 0;
}
static int luasteam_SteamNetworkingIdentity_IsLocalHost(lua_State *L) {
	SteamNetworkingIdentity *self = luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	bool __ret = self->IsLocalHost();
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_SteamNetworkingIdentity_SetGenericString(lua_State *L) {
	SteamNetworkingIdentity *self = luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	const char *pszString = luaL_checkstring(L, 2);
	bool __ret = self->SetGenericString(pszString);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_SteamNetworkingIdentity_GetGenericString(lua_State *L) {
	SteamNetworkingIdentity *self = luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	const char * __ret = self->GetGenericString();
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}
static int luasteam_SteamNetworkingIdentity_SetGenericBytes(lua_State *L) {
	SteamNetworkingIdentity *self = luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	const void *data = reinterpret_cast<const void *>(luaL_checkstring(L, 2));
	uint32 cbLen = static_cast<uint32>(luaL_checkint(L, 3));
	bool __ret = self->SetGenericBytes(data, cbLen);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_SteamNetworkingIdentity_ParseString(lua_State *L) {
	SteamNetworkingIdentity *self = luasteam::check_SteamNetworkingIdentity_ptr(L, 1);
	const char *pszStr = luaL_checkstring(L, 2);
	bool __ret = self->ParseString(pszStr);
	lua_pushboolean(L, __ret);
	return 1;
}
static int SteamNetworkingIdentity_index(lua_State *L) {
	lua_getmetatable(L, 1);
	lua_pushvalue(L, 2);
	lua_rawget(L, -2);
	if (!lua_isnil(L, -1)) return 1;
	lua_pop(L, 2);
	lua_pushnil(L);
	return 1;
}

EXTERN int luasteam_newSteamNetworkingIdentity(lua_State *L) {
	SteamNetworkingIdentity *ptr = (SteamNetworkingIdentity*)lua_newuserdata(L, sizeof(SteamNetworkingIdentity));
	new (ptr) SteamNetworkingIdentity();
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetworkingIdentityMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamNetConnectionInfo_tMetatable_ref = LUA_NOREF;

static int SteamNetConnectionInfo_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamNetConnectionInfo_t *self = (SteamNetConnectionInfo_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_identityRemote") == 0) {
		luasteam::push_SteamNetworkingIdentity(L, self->m_identityRemote);
		return 1;
	}
	if (strcmp(key, "m_nUserData") == 0) {
		luasteam::pushuint64(L, self->m_nUserData);
		return 1;
	}
	if (strcmp(key, "m_hListenSocket") == 0) {
		lua_pushinteger(L, self->m_hListenSocket);
		return 1;
	}
	if (strcmp(key, "m_addrRemote") == 0) {
		luasteam::push_SteamNetworkingIPAddr(L, self->m_addrRemote);
		return 1;
	}
	if (strcmp(key, "m__pad1") == 0) {
		lua_pushinteger(L, self->m__pad1);
		return 1;
	}
	if (strcmp(key, "m_idPOPRemote") == 0) {
		lua_pushinteger(L, self->m_idPOPRemote);
		return 1;
	}
	if (strcmp(key, "m_idPOPRelay") == 0) {
		lua_pushinteger(L, self->m_idPOPRelay);
		return 1;
	}
	if (strcmp(key, "m_eState") == 0) {
		lua_pushinteger(L, self->m_eState);
		return 1;
	}
	if (strcmp(key, "m_eEndReason") == 0) {
		lua_pushinteger(L, self->m_eEndReason);
		return 1;
	}
	if (strcmp(key, "m_szEndDebug") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->m_szEndDebug));
		return 1;
	}
	if (strcmp(key, "m_szConnectionDescription") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->m_szConnectionDescription));
		return 1;
	}
	if (strcmp(key, "m_nFlags") == 0) {
		lua_pushinteger(L, self->m_nFlags);
		return 1;
	}
	if (strcmp(key, "reserved") == 0) {
		lua_createtable(L, 63, 0);
		for(decltype(63) i = 0; i < 63; i++) {
			lua_pushinteger(L, self->reserved[i]);
			lua_rawseti(L, -2, i+1);
		}
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamNetConnectionInfo_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamNetConnectionInfo_t *self = (SteamNetConnectionInfo_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_identityRemote") == 0) {
		self->m_identityRemote = luasteam::check_SteamNetworkingIdentity(L, 3);
		return 0;
	}
	if (strcmp(key, "m_nUserData") == 0) {
		self->m_nUserData = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_hListenSocket") == 0) {
		self->m_hListenSocket = static_cast<HSteamListenSocket>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_addrRemote") == 0) {
		self->m_addrRemote = luasteam::check_SteamNetworkingIPAddr(L, 3);
		return 0;
	}
	if (strcmp(key, "m__pad1") == 0) {
		self->m__pad1 = static_cast<uint16>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_idPOPRemote") == 0) {
		self->m_idPOPRemote = static_cast<SteamNetworkingPOPID>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_idPOPRelay") == 0) {
		self->m_idPOPRelay = static_cast<SteamNetworkingPOPID>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_eState") == 0) {
		self->m_eState = static_cast<ESteamNetworkingConnectionState>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_eEndReason") == 0) {
		self->m_eEndReason = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_szEndDebug") == 0) {
		const char *_tmp28 = luaL_checkstring(L, 3);
		if (strlen(_tmp28) >= 128) luaL_error(L, "String too long");
		memcpy(self->m_szEndDebug, _tmp28, sizeof(self->m_szEndDebug));
		return 0;
	}
	if (strcmp(key, "m_szConnectionDescription") == 0) {
		const char *_tmp30 = luaL_checkstring(L, 3);
		if (strlen(_tmp30) >= 128) luaL_error(L, "String too long");
		memcpy(self->m_szConnectionDescription, _tmp30, sizeof(self->m_szConnectionDescription));
		return 0;
	}
	if (strcmp(key, "m_nFlags") == 0) {
		self->m_nFlags = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "reserved") == 0) {
		luaL_checktype(L, 3, LUA_TTABLE);
		for(decltype(63) i = 0; i < 63; i++) {
			lua_rawgeti(L, 3, i+1);
			self->reserved[i] = static_cast<int>(luaL_checkint(L, -1));
			lua_pop(L, 1);
		}
		return 0;
	}
	return luaL_error(L, "SteamNetConnectionInfo_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamNetConnectionInfo_t(lua_State *L) {
	SteamNetConnectionInfo_t *ptr = (SteamNetConnectionInfo_t*)lua_newuserdata(L, sizeof(SteamNetConnectionInfo_t));
	new (ptr) SteamNetConnectionInfo_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_identityRemote");
		if (!lua_isnil(L, -1)) {
			ptr->m_identityRemote = luasteam::check_SteamNetworkingIdentity(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nUserData");
		if (!lua_isnil(L, -1)) {
			ptr->m_nUserData = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_hListenSocket");
		if (!lua_isnil(L, -1)) {
			ptr->m_hListenSocket = static_cast<HSteamListenSocket>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_addrRemote");
		if (!lua_isnil(L, -1)) {
			ptr->m_addrRemote = luasteam::check_SteamNetworkingIPAddr(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m__pad1");
		if (!lua_isnil(L, -1)) {
			ptr->m__pad1 = static_cast<uint16>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_idPOPRemote");
		if (!lua_isnil(L, -1)) {
			ptr->m_idPOPRemote = static_cast<SteamNetworkingPOPID>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_idPOPRelay");
		if (!lua_isnil(L, -1)) {
			ptr->m_idPOPRelay = static_cast<SteamNetworkingPOPID>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eState");
		if (!lua_isnil(L, -1)) {
			ptr->m_eState = static_cast<ESteamNetworkingConnectionState>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eEndReason");
		if (!lua_isnil(L, -1)) {
			ptr->m_eEndReason = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_szEndDebug");
		if (!lua_isnil(L, -1)) {
			const char *_tmp29 = luaL_checkstring(L, -1);
			if (strlen(_tmp29) >= 128) luaL_error(L, "String too long");
			memcpy(ptr->m_szEndDebug, _tmp29, sizeof(ptr->m_szEndDebug));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_szConnectionDescription");
		if (!lua_isnil(L, -1)) {
			const char *_tmp31 = luaL_checkstring(L, -1);
			if (strlen(_tmp31) >= 128) luaL_error(L, "String too long");
			memcpy(ptr->m_szConnectionDescription, _tmp31, sizeof(ptr->m_szConnectionDescription));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nFlags");
		if (!lua_isnil(L, -1)) {
			ptr->m_nFlags = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "reserved");
		if (!lua_isnil(L, -1)) {
			luaL_checktype(L, -1, LUA_TTABLE);
			for(decltype(63) i = 0; i < 63; i++) {
				lua_rawgeti(L, -1, i+1);
				ptr->reserved[i] = static_cast<int>(luaL_checkint(L, -1));
				lua_pop(L, 1);
			}
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetConnectionInfo_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamNetConnectionRealTimeStatus_tMetatable_ref = LUA_NOREF;

static int SteamNetConnectionRealTimeStatus_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamNetConnectionRealTimeStatus_t *self = (SteamNetConnectionRealTimeStatus_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eState") == 0) {
		lua_pushinteger(L, self->m_eState);
		return 1;
	}
	if (strcmp(key, "m_nPing") == 0) {
		lua_pushinteger(L, self->m_nPing);
		return 1;
	}
	if (strcmp(key, "m_flConnectionQualityLocal") == 0) {
		lua_pushnumber(L, self->m_flConnectionQualityLocal);
		return 1;
	}
	if (strcmp(key, "m_flConnectionQualityRemote") == 0) {
		lua_pushnumber(L, self->m_flConnectionQualityRemote);
		return 1;
	}
	if (strcmp(key, "m_flOutPacketsPerSec") == 0) {
		lua_pushnumber(L, self->m_flOutPacketsPerSec);
		return 1;
	}
	if (strcmp(key, "m_flOutBytesPerSec") == 0) {
		lua_pushnumber(L, self->m_flOutBytesPerSec);
		return 1;
	}
	if (strcmp(key, "m_flInPacketsPerSec") == 0) {
		lua_pushnumber(L, self->m_flInPacketsPerSec);
		return 1;
	}
	if (strcmp(key, "m_flInBytesPerSec") == 0) {
		lua_pushnumber(L, self->m_flInBytesPerSec);
		return 1;
	}
	if (strcmp(key, "m_nSendRateBytesPerSecond") == 0) {
		lua_pushinteger(L, self->m_nSendRateBytesPerSecond);
		return 1;
	}
	if (strcmp(key, "m_cbPendingUnreliable") == 0) {
		lua_pushinteger(L, self->m_cbPendingUnreliable);
		return 1;
	}
	if (strcmp(key, "m_cbPendingReliable") == 0) {
		lua_pushinteger(L, self->m_cbPendingReliable);
		return 1;
	}
	if (strcmp(key, "m_cbSentUnackedReliable") == 0) {
		lua_pushinteger(L, self->m_cbSentUnackedReliable);
		return 1;
	}
	if (strcmp(key, "reserved") == 0) {
		lua_createtable(L, 16, 0);
		for(decltype(16) i = 0; i < 16; i++) {
			lua_pushinteger(L, self->reserved[i]);
			lua_rawseti(L, -2, i+1);
		}
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamNetConnectionRealTimeStatus_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamNetConnectionRealTimeStatus_t *self = (SteamNetConnectionRealTimeStatus_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eState") == 0) {
		self->m_eState = static_cast<ESteamNetworkingConnectionState>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nPing") == 0) {
		self->m_nPing = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_flConnectionQualityLocal") == 0) {
		self->m_flConnectionQualityLocal = static_cast<float>(luaL_checknumber(L, 3));
		return 0;
	}
	if (strcmp(key, "m_flConnectionQualityRemote") == 0) {
		self->m_flConnectionQualityRemote = static_cast<float>(luaL_checknumber(L, 3));
		return 0;
	}
	if (strcmp(key, "m_flOutPacketsPerSec") == 0) {
		self->m_flOutPacketsPerSec = static_cast<float>(luaL_checknumber(L, 3));
		return 0;
	}
	if (strcmp(key, "m_flOutBytesPerSec") == 0) {
		self->m_flOutBytesPerSec = static_cast<float>(luaL_checknumber(L, 3));
		return 0;
	}
	if (strcmp(key, "m_flInPacketsPerSec") == 0) {
		self->m_flInPacketsPerSec = static_cast<float>(luaL_checknumber(L, 3));
		return 0;
	}
	if (strcmp(key, "m_flInBytesPerSec") == 0) {
		self->m_flInBytesPerSec = static_cast<float>(luaL_checknumber(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nSendRateBytesPerSecond") == 0) {
		self->m_nSendRateBytesPerSecond = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_cbPendingUnreliable") == 0) {
		self->m_cbPendingUnreliable = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_cbPendingReliable") == 0) {
		self->m_cbPendingReliable = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_cbSentUnackedReliable") == 0) {
		self->m_cbSentUnackedReliable = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "reserved") == 0) {
		luaL_checktype(L, 3, LUA_TTABLE);
		for(decltype(16) i = 0; i < 16; i++) {
			lua_rawgeti(L, 3, i+1);
			self->reserved[i] = static_cast<int>(luaL_checkint(L, -1));
			lua_pop(L, 1);
		}
		return 0;
	}
	return luaL_error(L, "SteamNetConnectionRealTimeStatus_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamNetConnectionRealTimeStatus_t(lua_State *L) {
	SteamNetConnectionRealTimeStatus_t *ptr = (SteamNetConnectionRealTimeStatus_t*)lua_newuserdata(L, sizeof(SteamNetConnectionRealTimeStatus_t));
	new (ptr) SteamNetConnectionRealTimeStatus_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eState");
		if (!lua_isnil(L, -1)) {
			ptr->m_eState = static_cast<ESteamNetworkingConnectionState>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nPing");
		if (!lua_isnil(L, -1)) {
			ptr->m_nPing = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_flConnectionQualityLocal");
		if (!lua_isnil(L, -1)) {
			ptr->m_flConnectionQualityLocal = static_cast<float>(luaL_checknumber(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_flConnectionQualityRemote");
		if (!lua_isnil(L, -1)) {
			ptr->m_flConnectionQualityRemote = static_cast<float>(luaL_checknumber(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_flOutPacketsPerSec");
		if (!lua_isnil(L, -1)) {
			ptr->m_flOutPacketsPerSec = static_cast<float>(luaL_checknumber(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_flOutBytesPerSec");
		if (!lua_isnil(L, -1)) {
			ptr->m_flOutBytesPerSec = static_cast<float>(luaL_checknumber(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_flInPacketsPerSec");
		if (!lua_isnil(L, -1)) {
			ptr->m_flInPacketsPerSec = static_cast<float>(luaL_checknumber(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_flInBytesPerSec");
		if (!lua_isnil(L, -1)) {
			ptr->m_flInBytesPerSec = static_cast<float>(luaL_checknumber(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nSendRateBytesPerSecond");
		if (!lua_isnil(L, -1)) {
			ptr->m_nSendRateBytesPerSecond = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_cbPendingUnreliable");
		if (!lua_isnil(L, -1)) {
			ptr->m_cbPendingUnreliable = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_cbPendingReliable");
		if (!lua_isnil(L, -1)) {
			ptr->m_cbPendingReliable = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_cbSentUnackedReliable");
		if (!lua_isnil(L, -1)) {
			ptr->m_cbSentUnackedReliable = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "reserved");
		if (!lua_isnil(L, -1)) {
			luaL_checktype(L, -1, LUA_TTABLE);
			for(decltype(16) i = 0; i < 16; i++) {
				lua_rawgeti(L, -1, i+1);
				ptr->reserved[i] = static_cast<int>(luaL_checkint(L, -1));
				lua_pop(L, 1);
			}
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetConnectionRealTimeStatus_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamNetConnectionRealTimeLaneStatus_tMetatable_ref = LUA_NOREF;

static int SteamNetConnectionRealTimeLaneStatus_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamNetConnectionRealTimeLaneStatus_t *self = (SteamNetConnectionRealTimeLaneStatus_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_cbPendingUnreliable") == 0) {
		lua_pushinteger(L, self->m_cbPendingUnreliable);
		return 1;
	}
	if (strcmp(key, "m_cbPendingReliable") == 0) {
		lua_pushinteger(L, self->m_cbPendingReliable);
		return 1;
	}
	if (strcmp(key, "m_cbSentUnackedReliable") == 0) {
		lua_pushinteger(L, self->m_cbSentUnackedReliable);
		return 1;
	}
	if (strcmp(key, "_reservePad1") == 0) {
		lua_pushinteger(L, self->_reservePad1);
		return 1;
	}
	if (strcmp(key, "reserved") == 0) {
		lua_createtable(L, 10, 0);
		for(decltype(10) i = 0; i < 10; i++) {
			lua_pushinteger(L, self->reserved[i]);
			lua_rawseti(L, -2, i+1);
		}
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamNetConnectionRealTimeLaneStatus_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamNetConnectionRealTimeLaneStatus_t *self = (SteamNetConnectionRealTimeLaneStatus_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_cbPendingUnreliable") == 0) {
		self->m_cbPendingUnreliable = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_cbPendingReliable") == 0) {
		self->m_cbPendingReliable = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_cbSentUnackedReliable") == 0) {
		self->m_cbSentUnackedReliable = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "_reservePad1") == 0) {
		self->_reservePad1 = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "reserved") == 0) {
		luaL_checktype(L, 3, LUA_TTABLE);
		for(decltype(10) i = 0; i < 10; i++) {
			lua_rawgeti(L, 3, i+1);
			self->reserved[i] = static_cast<int>(luaL_checkint(L, -1));
			lua_pop(L, 1);
		}
		return 0;
	}
	return luaL_error(L, "SteamNetConnectionRealTimeLaneStatus_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamNetConnectionRealTimeLaneStatus_t(lua_State *L) {
	SteamNetConnectionRealTimeLaneStatus_t *ptr = (SteamNetConnectionRealTimeLaneStatus_t*)lua_newuserdata(L, sizeof(SteamNetConnectionRealTimeLaneStatus_t));
	new (ptr) SteamNetConnectionRealTimeLaneStatus_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_cbPendingUnreliable");
		if (!lua_isnil(L, -1)) {
			ptr->m_cbPendingUnreliable = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_cbPendingReliable");
		if (!lua_isnil(L, -1)) {
			ptr->m_cbPendingReliable = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_cbSentUnackedReliable");
		if (!lua_isnil(L, -1)) {
			ptr->m_cbSentUnackedReliable = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "_reservePad1");
		if (!lua_isnil(L, -1)) {
			ptr->_reservePad1 = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "reserved");
		if (!lua_isnil(L, -1)) {
			luaL_checktype(L, -1, LUA_TTABLE);
			for(decltype(10) i = 0; i < 10; i++) {
				lua_rawgeti(L, -1, i+1);
				ptr->reserved[i] = static_cast<int>(luaL_checkint(L, -1));
				lua_pop(L, 1);
			}
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetConnectionRealTimeLaneStatus_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamNetworkPingLocation_tMetatable_ref = LUA_NOREF;

static int SteamNetworkPingLocation_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamNetworkPingLocation_t *self = (SteamNetworkPingLocation_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_data") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->m_data));
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamNetworkPingLocation_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamNetworkPingLocation_t *self = (SteamNetworkPingLocation_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_data") == 0) {
		const char *_tmp32 = luaL_checkstring(L, 3);
		if (strlen(_tmp32) >= 512) luaL_error(L, "String too long");
		memcpy(self->m_data, _tmp32, sizeof(self->m_data));
		return 0;
	}
	return luaL_error(L, "SteamNetworkPingLocation_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamNetworkPingLocation_t(lua_State *L) {
	SteamNetworkPingLocation_t *ptr = (SteamNetworkPingLocation_t*)lua_newuserdata(L, sizeof(SteamNetworkPingLocation_t));
	new (ptr) SteamNetworkPingLocation_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_data");
		if (!lua_isnil(L, -1)) {
			const char *_tmp33 = luaL_checkstring(L, -1);
			if (strlen(_tmp33) >= 512) luaL_error(L, "String too long");
			memcpy(ptr->m_data, _tmp33, sizeof(ptr->m_data));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetworkPingLocation_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamNetworkingConfigValue_tMetatable_ref = LUA_NOREF;

static int luasteam_SteamNetworkingConfigValue_t_SetInt64(lua_State *L) {
	SteamNetworkingConfigValue_t *self = luasteam::check_SteamNetworkingConfigValue_t_ptr(L, 1);
	ESteamNetworkingConfigValue eVal = static_cast<ESteamNetworkingConfigValue>(luaL_checkint(L, 2));
	int64_t data(luasteam::checkuint64(L, 3));
	self->SetInt64(eVal, data);
	return 0;
}
static int luasteam_SteamNetworkingConfigValue_t_SetFloat(lua_State *L) {
	SteamNetworkingConfigValue_t *self = luasteam::check_SteamNetworkingConfigValue_t_ptr(L, 1);
	ESteamNetworkingConfigValue eVal = static_cast<ESteamNetworkingConfigValue>(luaL_checkint(L, 2));
	float data = luaL_checknumber(L, 3);
	self->SetFloat(eVal, data);
	return 0;
}
static int luasteam_SteamNetworkingConfigValue_t_SetString(lua_State *L) {
	SteamNetworkingConfigValue_t *self = luasteam::check_SteamNetworkingConfigValue_t_ptr(L, 1);
	ESteamNetworkingConfigValue eVal = static_cast<ESteamNetworkingConfigValue>(luaL_checkint(L, 2));
	const char *data = luaL_checkstring(L, 3);
	self->SetString(eVal, data);
	return 0;
}
static int SteamNetworkingConfigValue_t_index(lua_State *L) {
	lua_getmetatable(L, 1);
	lua_pushvalue(L, 2);
	lua_rawget(L, -2);
	if (!lua_isnil(L, -1)) return 1;
	lua_pop(L, 2);
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamNetworkingConfigValue_t *self = (SteamNetworkingConfigValue_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eValue") == 0) {
		lua_pushinteger(L, self->m_eValue);
		return 1;
	}
	if (strcmp(key, "m_eDataType") == 0) {
		lua_pushinteger(L, self->m_eDataType);
		return 1;
	}
	if (strcmp(key, "m_val.m_int64") == 0) {
		luasteam::pushuint64(L, self->m_val.m_int64);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamNetworkingConfigValue_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamNetworkingConfigValue_t *self = (SteamNetworkingConfigValue_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eValue") == 0) {
		self->m_eValue = static_cast<ESteamNetworkingConfigValue>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_eDataType") == 0) {
		self->m_eDataType = static_cast<ESteamNetworkingConfigDataType>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_val.m_int64") == 0) {
		self->m_val.m_int64 = luasteam::checkuint64(L, 3);
		return 0;
	}
	return luaL_error(L, "SteamNetworkingConfigValue_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamNetworkingConfigValue_t(lua_State *L) {
	SteamNetworkingConfigValue_t *ptr = (SteamNetworkingConfigValue_t*)lua_newuserdata(L, sizeof(SteamNetworkingConfigValue_t));
	new (ptr) SteamNetworkingConfigValue_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eValue");
		if (!lua_isnil(L, -1)) {
			ptr->m_eValue = static_cast<ESteamNetworkingConfigValue>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eDataType");
		if (!lua_isnil(L, -1)) {
			ptr->m_eDataType = static_cast<ESteamNetworkingConfigDataType>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_val.m_int64");
		if (!lua_isnil(L, -1)) {
			ptr->m_val.m_int64 = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetworkingConfigValue_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

namespace luasteam {

void push_SteamIPAddress_t(lua_State *L, SteamIPAddress_t val) {
	SteamIPAddress_t *ptr = (SteamIPAddress_t*)lua_newuserdata(L, sizeof(SteamIPAddress_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamIPAddress_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamIPAddress_t *check_SteamIPAddress_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamIPAddress_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamIPAddress_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamIPAddress_t expected");
	return (SteamIPAddress_t*)lua_touserdata(L, nParam);
}

SteamIPAddress_t check_SteamIPAddress_t(lua_State *L, int nParam) { return *check_SteamIPAddress_t_ptr(L, nParam); }

void push_FriendGameInfo_t(lua_State *L, FriendGameInfo_t val) {
	FriendGameInfo_t *ptr = (FriendGameInfo_t*)lua_newuserdata(L, sizeof(FriendGameInfo_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, FriendGameInfo_tMetatable_ref);
	lua_setmetatable(L, -2);
}

FriendGameInfo_t *check_FriendGameInfo_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "FriendGameInfo_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, FriendGameInfo_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "FriendGameInfo_t expected");
	return (FriendGameInfo_t*)lua_touserdata(L, nParam);
}

FriendGameInfo_t check_FriendGameInfo_t(lua_State *L, int nParam) { return *check_FriendGameInfo_t_ptr(L, nParam); }

void push_MatchMakingKeyValuePair_t(lua_State *L, MatchMakingKeyValuePair_t val) {
	MatchMakingKeyValuePair_t *ptr = (MatchMakingKeyValuePair_t*)lua_newuserdata(L, sizeof(MatchMakingKeyValuePair_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, MatchMakingKeyValuePair_tMetatable_ref);
	lua_setmetatable(L, -2);
}

MatchMakingKeyValuePair_t *check_MatchMakingKeyValuePair_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "MatchMakingKeyValuePair_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, MatchMakingKeyValuePair_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "MatchMakingKeyValuePair_t expected");
	return (MatchMakingKeyValuePair_t*)lua_touserdata(L, nParam);
}

MatchMakingKeyValuePair_t check_MatchMakingKeyValuePair_t(lua_State *L, int nParam) { return *check_MatchMakingKeyValuePair_t_ptr(L, nParam); }

void push_servernetadr_t(lua_State *L, servernetadr_t val) {
	servernetadr_t *ptr = (servernetadr_t*)lua_newuserdata(L, sizeof(servernetadr_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, servernetadr_tMetatable_ref);
	lua_setmetatable(L, -2);
}

servernetadr_t *check_servernetadr_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "servernetadr_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, servernetadr_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "servernetadr_t expected");
	return (servernetadr_t*)lua_touserdata(L, nParam);
}

servernetadr_t check_servernetadr_t(lua_State *L, int nParam) { return *check_servernetadr_t_ptr(L, nParam); }

void push_gameserveritem_t(lua_State *L, gameserveritem_t val) {
	gameserveritem_t *ptr = (gameserveritem_t*)lua_newuserdata(L, sizeof(gameserveritem_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, gameserveritem_tMetatable_ref);
	lua_setmetatable(L, -2);
}

gameserveritem_t *check_gameserveritem_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "gameserveritem_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, gameserveritem_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "gameserveritem_t expected");
	return (gameserveritem_t*)lua_touserdata(L, nParam);
}

gameserveritem_t check_gameserveritem_t(lua_State *L, int nParam) { return *check_gameserveritem_t_ptr(L, nParam); }

void push_SteamPartyBeaconLocation_t(lua_State *L, SteamPartyBeaconLocation_t val) {
	SteamPartyBeaconLocation_t *ptr = (SteamPartyBeaconLocation_t*)lua_newuserdata(L, sizeof(SteamPartyBeaconLocation_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamPartyBeaconLocation_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamPartyBeaconLocation_t *check_SteamPartyBeaconLocation_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamPartyBeaconLocation_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamPartyBeaconLocation_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamPartyBeaconLocation_t expected");
	return (SteamPartyBeaconLocation_t*)lua_touserdata(L, nParam);
}

SteamPartyBeaconLocation_t check_SteamPartyBeaconLocation_t(lua_State *L, int nParam) { return *check_SteamPartyBeaconLocation_t_ptr(L, nParam); }

void push_SteamParamStringArray_t(lua_State *L, SteamParamStringArray_t val) {
	SteamParamStringArray_t *ptr = (SteamParamStringArray_t*)lua_newuserdata(L, sizeof(SteamParamStringArray_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamParamStringArray_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamParamStringArray_t *check_SteamParamStringArray_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamParamStringArray_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamParamStringArray_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamParamStringArray_t expected");
	return (SteamParamStringArray_t*)lua_touserdata(L, nParam);
}

SteamParamStringArray_t check_SteamParamStringArray_t(lua_State *L, int nParam) { return *check_SteamParamStringArray_t_ptr(L, nParam); }

void push_LeaderboardEntry_t(lua_State *L, LeaderboardEntry_t val) {
	LeaderboardEntry_t *ptr = (LeaderboardEntry_t*)lua_newuserdata(L, sizeof(LeaderboardEntry_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, LeaderboardEntry_tMetatable_ref);
	lua_setmetatable(L, -2);
}

LeaderboardEntry_t *check_LeaderboardEntry_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "LeaderboardEntry_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, LeaderboardEntry_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "LeaderboardEntry_t expected");
	return (LeaderboardEntry_t*)lua_touserdata(L, nParam);
}

LeaderboardEntry_t check_LeaderboardEntry_t(lua_State *L, int nParam) { return *check_LeaderboardEntry_t_ptr(L, nParam); }

void push_P2PSessionState_t(lua_State *L, P2PSessionState_t val) {
	P2PSessionState_t *ptr = (P2PSessionState_t*)lua_newuserdata(L, sizeof(P2PSessionState_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, P2PSessionState_tMetatable_ref);
	lua_setmetatable(L, -2);
}

P2PSessionState_t *check_P2PSessionState_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "P2PSessionState_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, P2PSessionState_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "P2PSessionState_t expected");
	return (P2PSessionState_t*)lua_touserdata(L, nParam);
}

P2PSessionState_t check_P2PSessionState_t(lua_State *L, int nParam) { return *check_P2PSessionState_t_ptr(L, nParam); }

void push_InputAnalogActionData_t(lua_State *L, InputAnalogActionData_t val) {
	InputAnalogActionData_t *ptr = (InputAnalogActionData_t*)lua_newuserdata(L, sizeof(InputAnalogActionData_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, InputAnalogActionData_tMetatable_ref);
	lua_setmetatable(L, -2);
}

InputAnalogActionData_t *check_InputAnalogActionData_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "InputAnalogActionData_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, InputAnalogActionData_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "InputAnalogActionData_t expected");
	return (InputAnalogActionData_t*)lua_touserdata(L, nParam);
}

InputAnalogActionData_t check_InputAnalogActionData_t(lua_State *L, int nParam) { return *check_InputAnalogActionData_t_ptr(L, nParam); }

void push_InputDigitalActionData_t(lua_State *L, InputDigitalActionData_t val) {
	InputDigitalActionData_t *ptr = (InputDigitalActionData_t*)lua_newuserdata(L, sizeof(InputDigitalActionData_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, InputDigitalActionData_tMetatable_ref);
	lua_setmetatable(L, -2);
}

InputDigitalActionData_t *check_InputDigitalActionData_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "InputDigitalActionData_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, InputDigitalActionData_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "InputDigitalActionData_t expected");
	return (InputDigitalActionData_t*)lua_touserdata(L, nParam);
}

InputDigitalActionData_t check_InputDigitalActionData_t(lua_State *L, int nParam) { return *check_InputDigitalActionData_t_ptr(L, nParam); }

void push_InputMotionData_t(lua_State *L, InputMotionData_t val) {
	InputMotionData_t *ptr = (InputMotionData_t*)lua_newuserdata(L, sizeof(InputMotionData_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, InputMotionData_tMetatable_ref);
	lua_setmetatable(L, -2);
}

InputMotionData_t *check_InputMotionData_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "InputMotionData_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, InputMotionData_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "InputMotionData_t expected");
	return (InputMotionData_t*)lua_touserdata(L, nParam);
}

InputMotionData_t check_InputMotionData_t(lua_State *L, int nParam) { return *check_InputMotionData_t_ptr(L, nParam); }

void push_SteamInputActionEvent_t(lua_State *L, SteamInputActionEvent_t val) {
	SteamInputActionEvent_t *ptr = (SteamInputActionEvent_t*)lua_newuserdata(L, sizeof(SteamInputActionEvent_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInputActionEvent_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamInputActionEvent_t *check_SteamInputActionEvent_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamInputActionEvent_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInputActionEvent_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamInputActionEvent_t expected");
	return (SteamInputActionEvent_t*)lua_touserdata(L, nParam);
}

SteamInputActionEvent_t check_SteamInputActionEvent_t(lua_State *L, int nParam) { return *check_SteamInputActionEvent_t_ptr(L, nParam); }

void push_SteamUGCDetails_t(lua_State *L, SteamUGCDetails_t val) {
	SteamUGCDetails_t *ptr = (SteamUGCDetails_t*)lua_newuserdata(L, sizeof(SteamUGCDetails_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamUGCDetails_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamUGCDetails_t *check_SteamUGCDetails_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamUGCDetails_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamUGCDetails_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamUGCDetails_t expected");
	return (SteamUGCDetails_t*)lua_touserdata(L, nParam);
}

SteamUGCDetails_t check_SteamUGCDetails_t(lua_State *L, int nParam) { return *check_SteamUGCDetails_t_ptr(L, nParam); }

void push_SteamItemDetails_t(lua_State *L, SteamItemDetails_t val) {
	SteamItemDetails_t *ptr = (SteamItemDetails_t*)lua_newuserdata(L, sizeof(SteamItemDetails_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamItemDetails_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamItemDetails_t *check_SteamItemDetails_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamItemDetails_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamItemDetails_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamItemDetails_t expected");
	return (SteamItemDetails_t*)lua_touserdata(L, nParam);
}

SteamItemDetails_t check_SteamItemDetails_t(lua_State *L, int nParam) { return *check_SteamItemDetails_t_ptr(L, nParam); }

void push_RemotePlayInputMouseMotion_t(lua_State *L, RemotePlayInputMouseMotion_t val) {
	RemotePlayInputMouseMotion_t *ptr = (RemotePlayInputMouseMotion_t*)lua_newuserdata(L, sizeof(RemotePlayInputMouseMotion_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemotePlayInputMouseMotion_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemotePlayInputMouseMotion_t *check_RemotePlayInputMouseMotion_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemotePlayInputMouseMotion_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemotePlayInputMouseMotion_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemotePlayInputMouseMotion_t expected");
	return (RemotePlayInputMouseMotion_t*)lua_touserdata(L, nParam);
}

RemotePlayInputMouseMotion_t check_RemotePlayInputMouseMotion_t(lua_State *L, int nParam) { return *check_RemotePlayInputMouseMotion_t_ptr(L, nParam); }

void push_RemotePlayInputMouseWheel_t(lua_State *L, RemotePlayInputMouseWheel_t val) {
	RemotePlayInputMouseWheel_t *ptr = (RemotePlayInputMouseWheel_t*)lua_newuserdata(L, sizeof(RemotePlayInputMouseWheel_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemotePlayInputMouseWheel_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemotePlayInputMouseWheel_t *check_RemotePlayInputMouseWheel_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemotePlayInputMouseWheel_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemotePlayInputMouseWheel_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemotePlayInputMouseWheel_t expected");
	return (RemotePlayInputMouseWheel_t*)lua_touserdata(L, nParam);
}

RemotePlayInputMouseWheel_t check_RemotePlayInputMouseWheel_t(lua_State *L, int nParam) { return *check_RemotePlayInputMouseWheel_t_ptr(L, nParam); }

void push_RemotePlayInputKey_t(lua_State *L, RemotePlayInputKey_t val) {
	RemotePlayInputKey_t *ptr = (RemotePlayInputKey_t*)lua_newuserdata(L, sizeof(RemotePlayInputKey_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemotePlayInputKey_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemotePlayInputKey_t *check_RemotePlayInputKey_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemotePlayInputKey_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemotePlayInputKey_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemotePlayInputKey_t expected");
	return (RemotePlayInputKey_t*)lua_touserdata(L, nParam);
}

RemotePlayInputKey_t check_RemotePlayInputKey_t(lua_State *L, int nParam) { return *check_RemotePlayInputKey_t_ptr(L, nParam); }

void push_RemotePlayInput_t(lua_State *L, RemotePlayInput_t val) {
	RemotePlayInput_t *ptr = (RemotePlayInput_t*)lua_newuserdata(L, sizeof(RemotePlayInput_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemotePlayInput_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemotePlayInput_t *check_RemotePlayInput_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemotePlayInput_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemotePlayInput_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemotePlayInput_t expected");
	return (RemotePlayInput_t*)lua_touserdata(L, nParam);
}

RemotePlayInput_t check_RemotePlayInput_t(lua_State *L, int nParam) { return *check_RemotePlayInput_t_ptr(L, nParam); }

void push_SteamNetworkingIPAddr(lua_State *L, SteamNetworkingIPAddr val) {
	SteamNetworkingIPAddr *ptr = (SteamNetworkingIPAddr*)lua_newuserdata(L, sizeof(SteamNetworkingIPAddr));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetworkingIPAddrMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamNetworkingIPAddr *check_SteamNetworkingIPAddr_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamNetworkingIPAddr expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetworkingIPAddrMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamNetworkingIPAddr expected");
	return (SteamNetworkingIPAddr*)lua_touserdata(L, nParam);
}

SteamNetworkingIPAddr check_SteamNetworkingIPAddr(lua_State *L, int nParam) { return *check_SteamNetworkingIPAddr_ptr(L, nParam); }

void push_SteamNetworkingIdentity(lua_State *L, SteamNetworkingIdentity val) {
	SteamNetworkingIdentity *ptr = (SteamNetworkingIdentity*)lua_newuserdata(L, sizeof(SteamNetworkingIdentity));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetworkingIdentityMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamNetworkingIdentity *check_SteamNetworkingIdentity_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamNetworkingIdentity expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetworkingIdentityMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamNetworkingIdentity expected");
	return (SteamNetworkingIdentity*)lua_touserdata(L, nParam);
}

SteamNetworkingIdentity check_SteamNetworkingIdentity(lua_State *L, int nParam) { return *check_SteamNetworkingIdentity_ptr(L, nParam); }

void push_SteamNetConnectionInfo_t(lua_State *L, SteamNetConnectionInfo_t val) {
	SteamNetConnectionInfo_t *ptr = (SteamNetConnectionInfo_t*)lua_newuserdata(L, sizeof(SteamNetConnectionInfo_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetConnectionInfo_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamNetConnectionInfo_t *check_SteamNetConnectionInfo_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamNetConnectionInfo_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetConnectionInfo_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamNetConnectionInfo_t expected");
	return (SteamNetConnectionInfo_t*)lua_touserdata(L, nParam);
}

SteamNetConnectionInfo_t check_SteamNetConnectionInfo_t(lua_State *L, int nParam) { return *check_SteamNetConnectionInfo_t_ptr(L, nParam); }

void push_SteamNetConnectionRealTimeStatus_t(lua_State *L, SteamNetConnectionRealTimeStatus_t val) {
	SteamNetConnectionRealTimeStatus_t *ptr = (SteamNetConnectionRealTimeStatus_t*)lua_newuserdata(L, sizeof(SteamNetConnectionRealTimeStatus_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetConnectionRealTimeStatus_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamNetConnectionRealTimeStatus_t *check_SteamNetConnectionRealTimeStatus_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamNetConnectionRealTimeStatus_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetConnectionRealTimeStatus_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamNetConnectionRealTimeStatus_t expected");
	return (SteamNetConnectionRealTimeStatus_t*)lua_touserdata(L, nParam);
}

SteamNetConnectionRealTimeStatus_t check_SteamNetConnectionRealTimeStatus_t(lua_State *L, int nParam) { return *check_SteamNetConnectionRealTimeStatus_t_ptr(L, nParam); }

void push_SteamNetConnectionRealTimeLaneStatus_t(lua_State *L, SteamNetConnectionRealTimeLaneStatus_t val) {
	SteamNetConnectionRealTimeLaneStatus_t *ptr = (SteamNetConnectionRealTimeLaneStatus_t*)lua_newuserdata(L, sizeof(SteamNetConnectionRealTimeLaneStatus_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetConnectionRealTimeLaneStatus_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamNetConnectionRealTimeLaneStatus_t *check_SteamNetConnectionRealTimeLaneStatus_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamNetConnectionRealTimeLaneStatus_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetConnectionRealTimeLaneStatus_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamNetConnectionRealTimeLaneStatus_t expected");
	return (SteamNetConnectionRealTimeLaneStatus_t*)lua_touserdata(L, nParam);
}

SteamNetConnectionRealTimeLaneStatus_t check_SteamNetConnectionRealTimeLaneStatus_t(lua_State *L, int nParam) { return *check_SteamNetConnectionRealTimeLaneStatus_t_ptr(L, nParam); }

void push_SteamNetworkPingLocation_t(lua_State *L, SteamNetworkPingLocation_t val) {
	SteamNetworkPingLocation_t *ptr = (SteamNetworkPingLocation_t*)lua_newuserdata(L, sizeof(SteamNetworkPingLocation_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetworkPingLocation_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamNetworkPingLocation_t *check_SteamNetworkPingLocation_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamNetworkPingLocation_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetworkPingLocation_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamNetworkPingLocation_t expected");
	return (SteamNetworkPingLocation_t*)lua_touserdata(L, nParam);
}

SteamNetworkPingLocation_t check_SteamNetworkPingLocation_t(lua_State *L, int nParam) { return *check_SteamNetworkPingLocation_t_ptr(L, nParam); }

void push_SteamNetworkingConfigValue_t(lua_State *L, SteamNetworkingConfigValue_t val) {
	SteamNetworkingConfigValue_t *ptr = (SteamNetworkingConfigValue_t*)lua_newuserdata(L, sizeof(SteamNetworkingConfigValue_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetworkingConfigValue_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamNetworkingConfigValue_t *check_SteamNetworkingConfigValue_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamNetworkingConfigValue_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetworkingConfigValue_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamNetworkingConfigValue_t expected");
	return (SteamNetworkingConfigValue_t*)lua_touserdata(L, nParam);
}

SteamNetworkingConfigValue_t check_SteamNetworkingConfigValue_t(lua_State *L, int nParam) { return *check_SteamNetworkingConfigValue_t_ptr(L, nParam); }

void init_structs_auto(lua_State *L) {
	// SteamIPAddress_t metatable
	lua_createtable(L, 0, 3);
	add_func(L, "IsSet", luasteam_SteamIPAddress_t_IsSet);
	add_func(L, "__index", SteamIPAddress_t_index);
	add_func(L, "__newindex", SteamIPAddress_t_newindex);
	SteamIPAddress_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// FriendGameInfo_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", FriendGameInfo_t_index);
	add_func(L, "__newindex", FriendGameInfo_t_newindex);
	FriendGameInfo_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// MatchMakingKeyValuePair_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", MatchMakingKeyValuePair_t_index);
	add_func(L, "__newindex", MatchMakingKeyValuePair_t_newindex);
	MatchMakingKeyValuePair_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// servernetadr_t metatable
	lua_createtable(L, 0, 10);
	add_func(L, "Init", luasteam_servernetadr_t_Init);
	add_func(L, "GetQueryPort", luasteam_servernetadr_t_GetQueryPort);
	add_func(L, "SetQueryPort", luasteam_servernetadr_t_SetQueryPort);
	add_func(L, "GetConnectionPort", luasteam_servernetadr_t_GetConnectionPort);
	add_func(L, "SetConnectionPort", luasteam_servernetadr_t_SetConnectionPort);
	add_func(L, "GetIP", luasteam_servernetadr_t_GetIP);
	add_func(L, "SetIP", luasteam_servernetadr_t_SetIP);
	add_func(L, "GetConnectionAddressString", luasteam_servernetadr_t_GetConnectionAddressString);
	add_func(L, "GetQueryAddressString", luasteam_servernetadr_t_GetQueryAddressString);
	add_func(L, "__index", servernetadr_t_index);
	servernetadr_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// gameserveritem_t metatable
	lua_createtable(L, 0, 4);
	add_func(L, "GetName", luasteam_gameserveritem_t_GetName);
	add_func(L, "SetName", luasteam_gameserveritem_t_SetName);
	add_func(L, "__index", gameserveritem_t_index);
	add_func(L, "__newindex", gameserveritem_t_newindex);
	gameserveritem_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamPartyBeaconLocation_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamPartyBeaconLocation_t_index);
	add_func(L, "__newindex", SteamPartyBeaconLocation_t_newindex);
	SteamPartyBeaconLocation_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamParamStringArray_t metatable
	lua_createtable(L, 0, 3);
	add_func(L, "__index", SteamParamStringArray_t_index);
	add_func(L, "__newindex", SteamParamStringArray_t_newindex);
	add_func(L, "__gc", SteamParamStringArray_t_gc);
	SteamParamStringArray_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// LeaderboardEntry_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", LeaderboardEntry_t_index);
	add_func(L, "__newindex", LeaderboardEntry_t_newindex);
	LeaderboardEntry_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// P2PSessionState_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", P2PSessionState_t_index);
	add_func(L, "__newindex", P2PSessionState_t_newindex);
	P2PSessionState_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// InputAnalogActionData_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", InputAnalogActionData_t_index);
	add_func(L, "__newindex", InputAnalogActionData_t_newindex);
	InputAnalogActionData_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// InputDigitalActionData_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", InputDigitalActionData_t_index);
	add_func(L, "__newindex", InputDigitalActionData_t_newindex);
	InputDigitalActionData_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// InputMotionData_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", InputMotionData_t_index);
	add_func(L, "__newindex", InputMotionData_t_newindex);
	InputMotionData_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamInputActionEvent_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamInputActionEvent_t_index);
	add_func(L, "__newindex", SteamInputActionEvent_t_newindex);
	SteamInputActionEvent_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamUGCDetails_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamUGCDetails_t_index);
	add_func(L, "__newindex", SteamUGCDetails_t_newindex);
	SteamUGCDetails_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamItemDetails_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamItemDetails_t_index);
	add_func(L, "__newindex", SteamItemDetails_t_newindex);
	SteamItemDetails_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemotePlayInputMouseMotion_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", RemotePlayInputMouseMotion_t_index);
	add_func(L, "__newindex", RemotePlayInputMouseMotion_t_newindex);
	RemotePlayInputMouseMotion_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemotePlayInputMouseWheel_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", RemotePlayInputMouseWheel_t_index);
	add_func(L, "__newindex", RemotePlayInputMouseWheel_t_newindex);
	RemotePlayInputMouseWheel_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemotePlayInputKey_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", RemotePlayInputKey_t_index);
	add_func(L, "__newindex", RemotePlayInputKey_t_newindex);
	RemotePlayInputKey_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemotePlayInput_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", RemotePlayInput_t_index);
	add_func(L, "__newindex", RemotePlayInput_t_newindex);
	RemotePlayInput_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamNetworkingIPAddr metatable
	lua_createtable(L, 0, 13);
	add_func(L, "Clear", luasteam_SteamNetworkingIPAddr_Clear);
	add_func(L, "IsIPv6AllZeros", luasteam_SteamNetworkingIPAddr_IsIPv6AllZeros);
	add_func(L, "SetIPv6", luasteam_SteamNetworkingIPAddr_SetIPv6);
	add_func(L, "SetIPv4", luasteam_SteamNetworkingIPAddr_SetIPv4);
	add_func(L, "IsIPv4", luasteam_SteamNetworkingIPAddr_IsIPv4);
	add_func(L, "GetIPv4", luasteam_SteamNetworkingIPAddr_GetIPv4);
	add_func(L, "SetIPv6LocalHost", luasteam_SteamNetworkingIPAddr_SetIPv6LocalHost);
	add_func(L, "IsLocalHost", luasteam_SteamNetworkingIPAddr_IsLocalHost);
	add_func(L, "ParseString", luasteam_SteamNetworkingIPAddr_ParseString);
	add_func(L, "GetFakeIPType", luasteam_SteamNetworkingIPAddr_GetFakeIPType);
	add_func(L, "IsFakeIP", luasteam_SteamNetworkingIPAddr_IsFakeIP);
	add_func(L, "__index", SteamNetworkingIPAddr_index);
	add_func(L, "__newindex", SteamNetworkingIPAddr_newindex);
	SteamNetworkingIPAddrMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamNetworkingIdentity metatable
	lua_createtable(L, 0, 23);
	add_func(L, "Clear", luasteam_SteamNetworkingIdentity_Clear);
	add_func(L, "IsInvalid", luasteam_SteamNetworkingIdentity_IsInvalid);
	add_func(L, "SetSteamID", luasteam_SteamNetworkingIdentity_SetSteamID);
	add_func(L, "GetSteamID", luasteam_SteamNetworkingIdentity_GetSteamID);
	add_func(L, "SetSteamID64", luasteam_SteamNetworkingIdentity_SetSteamID64);
	add_func(L, "GetSteamID64", luasteam_SteamNetworkingIdentity_GetSteamID64);
	add_func(L, "SetXboxPairwiseID", luasteam_SteamNetworkingIdentity_SetXboxPairwiseID);
	add_func(L, "GetXboxPairwiseID", luasteam_SteamNetworkingIdentity_GetXboxPairwiseID);
	add_func(L, "SetPSNID", luasteam_SteamNetworkingIdentity_SetPSNID);
	add_func(L, "GetPSNID", luasteam_SteamNetworkingIdentity_GetPSNID);
	add_func(L, "SetIPAddr", luasteam_SteamNetworkingIdentity_SetIPAddr);
	add_func(L, "GetIPAddr", luasteam_SteamNetworkingIdentity_GetIPAddr);
	add_func(L, "SetIPv4Addr", luasteam_SteamNetworkingIdentity_SetIPv4Addr);
	add_func(L, "GetIPv4", luasteam_SteamNetworkingIdentity_GetIPv4);
	add_func(L, "GetFakeIPType", luasteam_SteamNetworkingIdentity_GetFakeIPType);
	add_func(L, "IsFakeIP", luasteam_SteamNetworkingIdentity_IsFakeIP);
	add_func(L, "SetLocalHost", luasteam_SteamNetworkingIdentity_SetLocalHost);
	add_func(L, "IsLocalHost", luasteam_SteamNetworkingIdentity_IsLocalHost);
	add_func(L, "SetGenericString", luasteam_SteamNetworkingIdentity_SetGenericString);
	add_func(L, "GetGenericString", luasteam_SteamNetworkingIdentity_GetGenericString);
	add_func(L, "SetGenericBytes", luasteam_SteamNetworkingIdentity_SetGenericBytes);
	add_func(L, "ParseString", luasteam_SteamNetworkingIdentity_ParseString);
	add_func(L, "__index", SteamNetworkingIdentity_index);
	SteamNetworkingIdentityMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamNetConnectionInfo_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamNetConnectionInfo_t_index);
	add_func(L, "__newindex", SteamNetConnectionInfo_t_newindex);
	SteamNetConnectionInfo_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamNetConnectionRealTimeStatus_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamNetConnectionRealTimeStatus_t_index);
	add_func(L, "__newindex", SteamNetConnectionRealTimeStatus_t_newindex);
	SteamNetConnectionRealTimeStatus_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamNetConnectionRealTimeLaneStatus_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamNetConnectionRealTimeLaneStatus_t_index);
	add_func(L, "__newindex", SteamNetConnectionRealTimeLaneStatus_t_newindex);
	SteamNetConnectionRealTimeLaneStatus_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamNetworkPingLocation_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamNetworkPingLocation_t_index);
	add_func(L, "__newindex", SteamNetworkPingLocation_t_newindex);
	SteamNetworkPingLocation_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamNetworkingConfigValue_t metatable
	lua_createtable(L, 0, 5);
	add_func(L, "SetInt64", luasteam_SteamNetworkingConfigValue_t_SetInt64);
	add_func(L, "SetFloat", luasteam_SteamNetworkingConfigValue_t_SetFloat);
	add_func(L, "SetString", luasteam_SteamNetworkingConfigValue_t_SetString);
	add_func(L, "__index", SteamNetworkingConfigValue_t_index);
	add_func(L, "__newindex", SteamNetworkingConfigValue_t_newindex);
	SteamNetworkingConfigValue_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
}

void shutdown_structs_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, SteamIPAddress_tMetatable_ref);
	SteamIPAddress_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, FriendGameInfo_tMetatable_ref);
	FriendGameInfo_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, MatchMakingKeyValuePair_tMetatable_ref);
	MatchMakingKeyValuePair_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, servernetadr_tMetatable_ref);
	servernetadr_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, gameserveritem_tMetatable_ref);
	gameserveritem_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamPartyBeaconLocation_tMetatable_ref);
	SteamPartyBeaconLocation_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamParamStringArray_tMetatable_ref);
	SteamParamStringArray_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, LeaderboardEntry_tMetatable_ref);
	LeaderboardEntry_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, P2PSessionState_tMetatable_ref);
	P2PSessionState_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, InputAnalogActionData_tMetatable_ref);
	InputAnalogActionData_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, InputDigitalActionData_tMetatable_ref);
	InputDigitalActionData_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, InputMotionData_tMetatable_ref);
	InputMotionData_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamInputActionEvent_tMetatable_ref);
	SteamInputActionEvent_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamUGCDetails_tMetatable_ref);
	SteamUGCDetails_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamItemDetails_tMetatable_ref);
	SteamItemDetails_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemotePlayInputMouseMotion_tMetatable_ref);
	RemotePlayInputMouseMotion_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemotePlayInputMouseWheel_tMetatable_ref);
	RemotePlayInputMouseWheel_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemotePlayInputKey_tMetatable_ref);
	RemotePlayInputKey_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemotePlayInput_tMetatable_ref);
	RemotePlayInput_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamNetworkingIPAddrMetatable_ref);
	SteamNetworkingIPAddrMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamNetworkingIdentityMetatable_ref);
	SteamNetworkingIdentityMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamNetConnectionInfo_tMetatable_ref);
	SteamNetConnectionInfo_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamNetConnectionRealTimeStatus_tMetatable_ref);
	SteamNetConnectionRealTimeStatus_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamNetConnectionRealTimeLaneStatus_tMetatable_ref);
	SteamNetConnectionRealTimeLaneStatus_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamNetworkPingLocation_tMetatable_ref);
	SteamNetworkPingLocation_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamNetworkingConfigValue_tMetatable_ref);
	SteamNetworkingConfigValue_tMetatable_ref = LUA_NOREF;
}

void add_structs_auto(lua_State *L) {
	add_func(L, "newSteamIPAddress_t", luasteam_newSteamIPAddress_t);
	add_func(L, "newFriendGameInfo_t", luasteam_newFriendGameInfo_t);
	add_func(L, "newMatchMakingKeyValuePair_t", luasteam_newMatchMakingKeyValuePair_t);
	add_func(L, "newservernetadr_t", luasteam_newservernetadr_t);
	add_func(L, "newgameserveritem_t", luasteam_newgameserveritem_t);
	add_func(L, "newSteamPartyBeaconLocation_t", luasteam_newSteamPartyBeaconLocation_t);
	add_func(L, "newSteamParamStringArray_t", luasteam_newSteamParamStringArray_t);
	add_func(L, "newLeaderboardEntry_t", luasteam_newLeaderboardEntry_t);
	add_func(L, "newP2PSessionState_t", luasteam_newP2PSessionState_t);
	add_func(L, "newInputAnalogActionData_t", luasteam_newInputAnalogActionData_t);
	add_func(L, "newInputDigitalActionData_t", luasteam_newInputDigitalActionData_t);
	add_func(L, "newInputMotionData_t", luasteam_newInputMotionData_t);
	add_func(L, "newSteamInputActionEvent_t", luasteam_newSteamInputActionEvent_t);
	add_func(L, "newSteamUGCDetails_t", luasteam_newSteamUGCDetails_t);
	add_func(L, "newSteamItemDetails_t", luasteam_newSteamItemDetails_t);
	add_func(L, "newRemotePlayInputMouseMotion_t", luasteam_newRemotePlayInputMouseMotion_t);
	add_func(L, "newRemotePlayInputMouseWheel_t", luasteam_newRemotePlayInputMouseWheel_t);
	add_func(L, "newRemotePlayInputKey_t", luasteam_newRemotePlayInputKey_t);
	add_func(L, "newRemotePlayInput_t", luasteam_newRemotePlayInput_t);
	add_func(L, "newSteamNetworkingIPAddr", luasteam_newSteamNetworkingIPAddr);
	add_func(L, "newSteamNetworkingIdentity", luasteam_newSteamNetworkingIdentity);
	add_func(L, "newSteamNetConnectionInfo_t", luasteam_newSteamNetConnectionInfo_t);
	add_func(L, "newSteamNetConnectionRealTimeStatus_t", luasteam_newSteamNetConnectionRealTimeStatus_t);
	add_func(L, "newSteamNetConnectionRealTimeLaneStatus_t", luasteam_newSteamNetConnectionRealTimeLaneStatus_t);
	add_func(L, "newSteamNetworkPingLocation_t", luasteam_newSteamNetworkPingLocation_t);
	add_func(L, "newSteamNetworkingConfigValue_t", luasteam_newSteamNetworkingConfigValue_t);
}

} // namespace luasteam
