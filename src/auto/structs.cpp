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
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_rgubIPv6), 16);
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
		size_t _len__tmp0;
		const char *_tmp0 = luaL_checklstring(L, 3, &_len__tmp0);
		if (_len__tmp0 > sizeof(self->m_rgubIPv6)) luaL_error(L, "String too long");
		memcpy(self->m_rgubIPv6, _tmp0, std::min(_len__tmp0 + 1, sizeof(self->m_rgubIPv6)));
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
			size_t _len__tmp1;
			const char *_tmp1 = luaL_checklstring(L, -1, &_len__tmp1);
			if (_len__tmp1 > sizeof(ptr->m_rgubIPv6)) luaL_error(L, "String too long");
			memcpy(ptr->m_rgubIPv6, _tmp1, std::min(_len__tmp1 + 1, sizeof(ptr->m_rgubIPv6)));
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
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_szKey), 256);
		return 1;
	}
	if (strcmp(key, "m_szValue") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_szValue), 256);
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
		size_t _len__tmp2;
		const char *_tmp2 = luaL_checklstring(L, 3, &_len__tmp2);
		if (_len__tmp2 > sizeof(self->m_szKey)) luaL_error(L, "String too long");
		memcpy(self->m_szKey, _tmp2, std::min(_len__tmp2 + 1, sizeof(self->m_szKey)));
		return 0;
	}
	if (strcmp(key, "m_szValue") == 0) {
		size_t _len__tmp4;
		const char *_tmp4 = luaL_checklstring(L, 3, &_len__tmp4);
		if (_len__tmp4 > sizeof(self->m_szValue)) luaL_error(L, "String too long");
		memcpy(self->m_szValue, _tmp4, std::min(_len__tmp4 + 1, sizeof(self->m_szValue)));
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
			size_t _len__tmp3;
			const char *_tmp3 = luaL_checklstring(L, -1, &_len__tmp3);
			if (_len__tmp3 > sizeof(ptr->m_szKey)) luaL_error(L, "String too long");
			memcpy(ptr->m_szKey, _tmp3, std::min(_len__tmp3 + 1, sizeof(ptr->m_szKey)));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_szValue");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp5;
			const char *_tmp5 = luaL_checklstring(L, -1, &_len__tmp5);
			if (_len__tmp5 > sizeof(ptr->m_szValue)) luaL_error(L, "String too long");
			memcpy(ptr->m_szValue, _tmp5, std::min(_len__tmp5 + 1, sizeof(ptr->m_szValue)));
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
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_szGameDir), 32);
		return 1;
	}
	if (strcmp(key, "m_szMap") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_szMap), 32);
		return 1;
	}
	if (strcmp(key, "m_szGameDescription") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_szGameDescription), 64);
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
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_szGameTags), 128);
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
		size_t _len__tmp6;
		const char *_tmp6 = luaL_checklstring(L, 3, &_len__tmp6);
		if (_len__tmp6 > sizeof(self->m_szGameDir)) luaL_error(L, "String too long");
		memcpy(self->m_szGameDir, _tmp6, std::min(_len__tmp6 + 1, sizeof(self->m_szGameDir)));
		return 0;
	}
	if (strcmp(key, "m_szMap") == 0) {
		size_t _len__tmp8;
		const char *_tmp8 = luaL_checklstring(L, 3, &_len__tmp8);
		if (_len__tmp8 > sizeof(self->m_szMap)) luaL_error(L, "String too long");
		memcpy(self->m_szMap, _tmp8, std::min(_len__tmp8 + 1, sizeof(self->m_szMap)));
		return 0;
	}
	if (strcmp(key, "m_szGameDescription") == 0) {
		size_t _len__tmp10;
		const char *_tmp10 = luaL_checklstring(L, 3, &_len__tmp10);
		if (_len__tmp10 > sizeof(self->m_szGameDescription)) luaL_error(L, "String too long");
		memcpy(self->m_szGameDescription, _tmp10, std::min(_len__tmp10 + 1, sizeof(self->m_szGameDescription)));
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
		size_t _len__tmp12;
		const char *_tmp12 = luaL_checklstring(L, 3, &_len__tmp12);
		if (_len__tmp12 > sizeof(self->m_szGameTags)) luaL_error(L, "String too long");
		memcpy(self->m_szGameTags, _tmp12, std::min(_len__tmp12 + 1, sizeof(self->m_szGameTags)));
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
			size_t _len__tmp7;
			const char *_tmp7 = luaL_checklstring(L, -1, &_len__tmp7);
			if (_len__tmp7 > sizeof(ptr->m_szGameDir)) luaL_error(L, "String too long");
			memcpy(ptr->m_szGameDir, _tmp7, std::min(_len__tmp7 + 1, sizeof(ptr->m_szGameDir)));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_szMap");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp9;
			const char *_tmp9 = luaL_checklstring(L, -1, &_len__tmp9);
			if (_len__tmp9 > sizeof(ptr->m_szMap)) luaL_error(L, "String too long");
			memcpy(ptr->m_szMap, _tmp9, std::min(_len__tmp9 + 1, sizeof(ptr->m_szMap)));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_szGameDescription");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp11;
			const char *_tmp11 = luaL_checklstring(L, -1, &_len__tmp11);
			if (_len__tmp11 > sizeof(ptr->m_szGameDescription)) luaL_error(L, "String too long");
			memcpy(ptr->m_szGameDescription, _tmp11, std::min(_len__tmp11 + 1, sizeof(ptr->m_szGameDescription)));
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
			size_t _len__tmp13;
			const char *_tmp13 = luaL_checklstring(L, -1, &_len__tmp13);
			if (_len__tmp13 > sizeof(ptr->m_szGameTags)) luaL_error(L, "String too long");
			memcpy(ptr->m_szGameTags, _tmp13, std::min(_len__tmp13 + 1, sizeof(ptr->m_szGameTags)));
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
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_rgchTitle), 129);
		return 1;
	}
	if (strcmp(key, "m_rgchDescription") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_rgchDescription), 8000);
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
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_rgchTags), 1025);
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
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_pchFileName), 260);
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
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_rgchURL), 256);
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
		size_t _len__tmp14;
		const char *_tmp14 = luaL_checklstring(L, 3, &_len__tmp14);
		if (_len__tmp14 > sizeof(self->m_rgchTitle)) luaL_error(L, "String too long");
		memcpy(self->m_rgchTitle, _tmp14, std::min(_len__tmp14 + 1, sizeof(self->m_rgchTitle)));
		return 0;
	}
	if (strcmp(key, "m_rgchDescription") == 0) {
		size_t _len__tmp16;
		const char *_tmp16 = luaL_checklstring(L, 3, &_len__tmp16);
		if (_len__tmp16 > sizeof(self->m_rgchDescription)) luaL_error(L, "String too long");
		memcpy(self->m_rgchDescription, _tmp16, std::min(_len__tmp16 + 1, sizeof(self->m_rgchDescription)));
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
		size_t _len__tmp18;
		const char *_tmp18 = luaL_checklstring(L, 3, &_len__tmp18);
		if (_len__tmp18 > sizeof(self->m_rgchTags)) luaL_error(L, "String too long");
		memcpy(self->m_rgchTags, _tmp18, std::min(_len__tmp18 + 1, sizeof(self->m_rgchTags)));
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
		size_t _len__tmp20;
		const char *_tmp20 = luaL_checklstring(L, 3, &_len__tmp20);
		if (_len__tmp20 > sizeof(self->m_pchFileName)) luaL_error(L, "String too long");
		memcpy(self->m_pchFileName, _tmp20, std::min(_len__tmp20 + 1, sizeof(self->m_pchFileName)));
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
		size_t _len__tmp22;
		const char *_tmp22 = luaL_checklstring(L, 3, &_len__tmp22);
		if (_len__tmp22 > sizeof(self->m_rgchURL)) luaL_error(L, "String too long");
		memcpy(self->m_rgchURL, _tmp22, std::min(_len__tmp22 + 1, sizeof(self->m_rgchURL)));
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
			size_t _len__tmp15;
			const char *_tmp15 = luaL_checklstring(L, -1, &_len__tmp15);
			if (_len__tmp15 > sizeof(ptr->m_rgchTitle)) luaL_error(L, "String too long");
			memcpy(ptr->m_rgchTitle, _tmp15, std::min(_len__tmp15 + 1, sizeof(ptr->m_rgchTitle)));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rgchDescription");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp17;
			const char *_tmp17 = luaL_checklstring(L, -1, &_len__tmp17);
			if (_len__tmp17 > sizeof(ptr->m_rgchDescription)) luaL_error(L, "String too long");
			memcpy(ptr->m_rgchDescription, _tmp17, std::min(_len__tmp17 + 1, sizeof(ptr->m_rgchDescription)));
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
			size_t _len__tmp19;
			const char *_tmp19 = luaL_checklstring(L, -1, &_len__tmp19);
			if (_len__tmp19 > sizeof(ptr->m_rgchTags)) luaL_error(L, "String too long");
			memcpy(ptr->m_rgchTags, _tmp19, std::min(_len__tmp19 + 1, sizeof(ptr->m_rgchTags)));
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
			size_t _len__tmp21;
			const char *_tmp21 = luaL_checklstring(L, -1, &_len__tmp21);
			if (_len__tmp21 > sizeof(ptr->m_pchFileName)) luaL_error(L, "String too long");
			memcpy(ptr->m_pchFileName, _tmp21, std::min(_len__tmp21 + 1, sizeof(ptr->m_pchFileName)));
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
			size_t _len__tmp23;
			const char *_tmp23 = luaL_checklstring(L, -1, &_len__tmp23);
			if (_len__tmp23 > sizeof(ptr->m_rgchURL)) luaL_error(L, "String too long");
			memcpy(ptr->m_rgchURL, _tmp23, std::min(_len__tmp23 + 1, sizeof(ptr->m_rgchURL)));
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
		lua_pushlstring(L, reinterpret_cast<const char*>(self->padding), 56);
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
		size_t _len__tmp24;
		const char *_tmp24 = luaL_checklstring(L, 3, &_len__tmp24);
		if (_len__tmp24 > sizeof(self->padding)) luaL_error(L, "String too long");
		memcpy(self->padding, _tmp24, std::min(_len__tmp24 + 1, sizeof(self->padding)));
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
			size_t _len__tmp25;
			const char *_tmp25 = luaL_checklstring(L, -1, &_len__tmp25);
			if (_len__tmp25 > sizeof(ptr->padding)) luaL_error(L, "String too long");
			memcpy(ptr->padding, _tmp25, std::min(_len__tmp25 + 1, sizeof(ptr->padding)));
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
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_ipv6), 16);
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
		size_t _len__tmp26;
		const char *_tmp26 = luaL_checklstring(L, 3, &_len__tmp26);
		if (_len__tmp26 > sizeof(self->m_ipv6)) luaL_error(L, "String too long");
		memcpy(self->m_ipv6, _tmp26, std::min(_len__tmp26 + 1, sizeof(self->m_ipv6)));
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
			size_t _len__tmp27;
			const char *_tmp27 = luaL_checklstring(L, -1, &_len__tmp27);
			if (_len__tmp27 > sizeof(ptr->m_ipv6)) luaL_error(L, "String too long");
			memcpy(ptr->m_ipv6, _tmp27, std::min(_len__tmp27 + 1, sizeof(ptr->m_ipv6)));
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
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_szEndDebug), 128);
		return 1;
	}
	if (strcmp(key, "m_szConnectionDescription") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_szConnectionDescription), 128);
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
		size_t _len__tmp28;
		const char *_tmp28 = luaL_checklstring(L, 3, &_len__tmp28);
		if (_len__tmp28 > sizeof(self->m_szEndDebug)) luaL_error(L, "String too long");
		memcpy(self->m_szEndDebug, _tmp28, std::min(_len__tmp28 + 1, sizeof(self->m_szEndDebug)));
		return 0;
	}
	if (strcmp(key, "m_szConnectionDescription") == 0) {
		size_t _len__tmp30;
		const char *_tmp30 = luaL_checklstring(L, 3, &_len__tmp30);
		if (_len__tmp30 > sizeof(self->m_szConnectionDescription)) luaL_error(L, "String too long");
		memcpy(self->m_szConnectionDescription, _tmp30, std::min(_len__tmp30 + 1, sizeof(self->m_szConnectionDescription)));
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
			size_t _len__tmp29;
			const char *_tmp29 = luaL_checklstring(L, -1, &_len__tmp29);
			if (_len__tmp29 > sizeof(ptr->m_szEndDebug)) luaL_error(L, "String too long");
			memcpy(ptr->m_szEndDebug, _tmp29, std::min(_len__tmp29 + 1, sizeof(ptr->m_szEndDebug)));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_szConnectionDescription");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp31;
			const char *_tmp31 = luaL_checklstring(L, -1, &_len__tmp31);
			if (_len__tmp31 > sizeof(ptr->m_szConnectionDescription)) luaL_error(L, "String too long");
			memcpy(ptr->m_szConnectionDescription, _tmp31, std::min(_len__tmp31 + 1, sizeof(ptr->m_szConnectionDescription)));
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
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_data), 512);
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
		size_t _len__tmp32;
		const char *_tmp32 = luaL_checklstring(L, 3, &_len__tmp32);
		if (_len__tmp32 > sizeof(self->m_data)) luaL_error(L, "String too long");
		memcpy(self->m_data, _tmp32, std::min(_len__tmp32 + 1, sizeof(self->m_data)));
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
			size_t _len__tmp33;
			const char *_tmp33 = luaL_checklstring(L, -1, &_len__tmp33);
			if (_len__tmp33 > sizeof(ptr->m_data)) luaL_error(L, "String too long");
			memcpy(ptr->m_data, _tmp33, std::min(_len__tmp33 + 1, sizeof(ptr->m_data)));
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

static int SteamServersConnected_tMetatable_ref = LUA_NOREF;

static int SteamServersConnected_t_index(lua_State *L) {
	lua_pushnil(L);
	return 1;
}

EXTERN int luasteam_newSteamServersConnected_t(lua_State *L) {
	SteamServersConnected_t *ptr = (SteamServersConnected_t*)lua_newuserdata(L, sizeof(SteamServersConnected_t));
	new (ptr) SteamServersConnected_t();
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamServersConnected_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamServerConnectFailure_tMetatable_ref = LUA_NOREF;

static int SteamServerConnectFailure_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamServerConnectFailure_t *self = (SteamServerConnectFailure_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_bStillRetrying") == 0) {
		lua_pushboolean(L, self->m_bStillRetrying);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamServerConnectFailure_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamServerConnectFailure_t *self = (SteamServerConnectFailure_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bStillRetrying") == 0) {
		self->m_bStillRetrying = lua_toboolean(L, 3);
		return 0;
	}
	return luaL_error(L, "SteamServerConnectFailure_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamServerConnectFailure_t(lua_State *L) {
	SteamServerConnectFailure_t *ptr = (SteamServerConnectFailure_t*)lua_newuserdata(L, sizeof(SteamServerConnectFailure_t));
	new (ptr) SteamServerConnectFailure_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bStillRetrying");
		if (!lua_isnil(L, -1)) {
			ptr->m_bStillRetrying = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamServerConnectFailure_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamServersDisconnected_tMetatable_ref = LUA_NOREF;

static int SteamServersDisconnected_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamServersDisconnected_t *self = (SteamServersDisconnected_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamServersDisconnected_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamServersDisconnected_t *self = (SteamServersDisconnected_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "SteamServersDisconnected_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamServersDisconnected_t(lua_State *L) {
	SteamServersDisconnected_t *ptr = (SteamServersDisconnected_t*)lua_newuserdata(L, sizeof(SteamServersDisconnected_t));
	new (ptr) SteamServersDisconnected_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamServersDisconnected_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int ClientGameServerDeny_tMetatable_ref = LUA_NOREF;

static int ClientGameServerDeny_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	ClientGameServerDeny_t *self = (ClientGameServerDeny_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_uAppID") == 0) {
		lua_pushinteger(L, self->m_uAppID);
		return 1;
	}
	if (strcmp(key, "m_unGameServerIP") == 0) {
		lua_pushinteger(L, self->m_unGameServerIP);
		return 1;
	}
	if (strcmp(key, "m_usGameServerPort") == 0) {
		lua_pushinteger(L, self->m_usGameServerPort);
		return 1;
	}
	if (strcmp(key, "m_bSecure") == 0) {
		lua_pushinteger(L, self->m_bSecure);
		return 1;
	}
	if (strcmp(key, "m_uReason") == 0) {
		lua_pushinteger(L, self->m_uReason);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int ClientGameServerDeny_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	ClientGameServerDeny_t *self = (ClientGameServerDeny_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_uAppID") == 0) {
		self->m_uAppID = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_unGameServerIP") == 0) {
		self->m_unGameServerIP = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_usGameServerPort") == 0) {
		self->m_usGameServerPort = static_cast<uint16>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bSecure") == 0) {
		self->m_bSecure = static_cast<uint16>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_uReason") == 0) {
		self->m_uReason = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "ClientGameServerDeny_t has no field '%%s'", key);
}

EXTERN int luasteam_newClientGameServerDeny_t(lua_State *L) {
	ClientGameServerDeny_t *ptr = (ClientGameServerDeny_t*)lua_newuserdata(L, sizeof(ClientGameServerDeny_t));
	new (ptr) ClientGameServerDeny_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_uAppID");
		if (!lua_isnil(L, -1)) {
			ptr->m_uAppID = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unGameServerIP");
		if (!lua_isnil(L, -1)) {
			ptr->m_unGameServerIP = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_usGameServerPort");
		if (!lua_isnil(L, -1)) {
			ptr->m_usGameServerPort = static_cast<uint16>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bSecure");
		if (!lua_isnil(L, -1)) {
			ptr->m_bSecure = static_cast<uint16>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_uReason");
		if (!lua_isnil(L, -1)) {
			ptr->m_uReason = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, ClientGameServerDeny_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int IPCFailure_tMetatable_ref = LUA_NOREF;

static int IPCFailure_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	IPCFailure_t *self = (IPCFailure_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eFailureType") == 0) {
		lua_pushinteger(L, self->m_eFailureType);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int IPCFailure_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	IPCFailure_t *self = (IPCFailure_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eFailureType") == 0) {
		self->m_eFailureType = static_cast<uint8>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "IPCFailure_t has no field '%%s'", key);
}

EXTERN int luasteam_newIPCFailure_t(lua_State *L) {
	IPCFailure_t *ptr = (IPCFailure_t*)lua_newuserdata(L, sizeof(IPCFailure_t));
	new (ptr) IPCFailure_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eFailureType");
		if (!lua_isnil(L, -1)) {
			ptr->m_eFailureType = static_cast<uint8>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, IPCFailure_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int LicensesUpdated_tMetatable_ref = LUA_NOREF;

static int LicensesUpdated_t_index(lua_State *L) {
	lua_pushnil(L);
	return 1;
}

EXTERN int luasteam_newLicensesUpdated_t(lua_State *L) {
	LicensesUpdated_t *ptr = (LicensesUpdated_t*)lua_newuserdata(L, sizeof(LicensesUpdated_t));
	new (ptr) LicensesUpdated_t();
	lua_rawgeti(L, LUA_REGISTRYINDEX, LicensesUpdated_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int ValidateAuthTicketResponse_tMetatable_ref = LUA_NOREF;

static int ValidateAuthTicketResponse_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	ValidateAuthTicketResponse_t *self = (ValidateAuthTicketResponse_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_SteamID") == 0) {
		luasteam::pushuint64(L, self->m_SteamID.ConvertToUint64());
		return 1;
	}
	if (strcmp(key, "m_eAuthSessionResponse") == 0) {
		lua_pushinteger(L, self->m_eAuthSessionResponse);
		return 1;
	}
	if (strcmp(key, "m_OwnerSteamID") == 0) {
		luasteam::pushuint64(L, self->m_OwnerSteamID.ConvertToUint64());
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int ValidateAuthTicketResponse_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	ValidateAuthTicketResponse_t *self = (ValidateAuthTicketResponse_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_SteamID") == 0) {
		self->m_SteamID = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	if (strcmp(key, "m_eAuthSessionResponse") == 0) {
		self->m_eAuthSessionResponse = static_cast<EAuthSessionResponse>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_OwnerSteamID") == 0) {
		self->m_OwnerSteamID = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	return luaL_error(L, "ValidateAuthTicketResponse_t has no field '%%s'", key);
}

EXTERN int luasteam_newValidateAuthTicketResponse_t(lua_State *L) {
	ValidateAuthTicketResponse_t *ptr = (ValidateAuthTicketResponse_t*)lua_newuserdata(L, sizeof(ValidateAuthTicketResponse_t));
	new (ptr) ValidateAuthTicketResponse_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_SteamID");
		if (!lua_isnil(L, -1)) {
			ptr->m_SteamID = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eAuthSessionResponse");
		if (!lua_isnil(L, -1)) {
			ptr->m_eAuthSessionResponse = static_cast<EAuthSessionResponse>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_OwnerSteamID");
		if (!lua_isnil(L, -1)) {
			ptr->m_OwnerSteamID = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, ValidateAuthTicketResponse_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int MicroTxnAuthorizationResponse_tMetatable_ref = LUA_NOREF;

static int MicroTxnAuthorizationResponse_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	MicroTxnAuthorizationResponse_t *self = (MicroTxnAuthorizationResponse_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_unAppID") == 0) {
		lua_pushinteger(L, self->m_unAppID);
		return 1;
	}
	if (strcmp(key, "m_ulOrderID") == 0) {
		luasteam::pushuint64(L, self->m_ulOrderID);
		return 1;
	}
	if (strcmp(key, "m_bAuthorized") == 0) {
		lua_pushinteger(L, self->m_bAuthorized);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int MicroTxnAuthorizationResponse_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	MicroTxnAuthorizationResponse_t *self = (MicroTxnAuthorizationResponse_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_unAppID") == 0) {
		self->m_unAppID = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_ulOrderID") == 0) {
		self->m_ulOrderID = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_bAuthorized") == 0) {
		self->m_bAuthorized = static_cast<uint8>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "MicroTxnAuthorizationResponse_t has no field '%%s'", key);
}

EXTERN int luasteam_newMicroTxnAuthorizationResponse_t(lua_State *L) {
	MicroTxnAuthorizationResponse_t *ptr = (MicroTxnAuthorizationResponse_t*)lua_newuserdata(L, sizeof(MicroTxnAuthorizationResponse_t));
	new (ptr) MicroTxnAuthorizationResponse_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_unAppID");
		if (!lua_isnil(L, -1)) {
			ptr->m_unAppID = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_ulOrderID");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulOrderID = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bAuthorized");
		if (!lua_isnil(L, -1)) {
			ptr->m_bAuthorized = static_cast<uint8>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, MicroTxnAuthorizationResponse_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int EncryptedAppTicketResponse_tMetatable_ref = LUA_NOREF;

static int EncryptedAppTicketResponse_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	EncryptedAppTicketResponse_t *self = (EncryptedAppTicketResponse_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int EncryptedAppTicketResponse_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	EncryptedAppTicketResponse_t *self = (EncryptedAppTicketResponse_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "EncryptedAppTicketResponse_t has no field '%%s'", key);
}

EXTERN int luasteam_newEncryptedAppTicketResponse_t(lua_State *L) {
	EncryptedAppTicketResponse_t *ptr = (EncryptedAppTicketResponse_t*)lua_newuserdata(L, sizeof(EncryptedAppTicketResponse_t));
	new (ptr) EncryptedAppTicketResponse_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, EncryptedAppTicketResponse_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int GetAuthSessionTicketResponse_tMetatable_ref = LUA_NOREF;

static int GetAuthSessionTicketResponse_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	GetAuthSessionTicketResponse_t *self = (GetAuthSessionTicketResponse_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_hAuthTicket") == 0) {
		lua_pushinteger(L, self->m_hAuthTicket);
		return 1;
	}
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int GetAuthSessionTicketResponse_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	GetAuthSessionTicketResponse_t *self = (GetAuthSessionTicketResponse_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_hAuthTicket") == 0) {
		self->m_hAuthTicket = static_cast<HAuthTicket>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "GetAuthSessionTicketResponse_t has no field '%%s'", key);
}

EXTERN int luasteam_newGetAuthSessionTicketResponse_t(lua_State *L) {
	GetAuthSessionTicketResponse_t *ptr = (GetAuthSessionTicketResponse_t*)lua_newuserdata(L, sizeof(GetAuthSessionTicketResponse_t));
	new (ptr) GetAuthSessionTicketResponse_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_hAuthTicket");
		if (!lua_isnil(L, -1)) {
			ptr->m_hAuthTicket = static_cast<HAuthTicket>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, GetAuthSessionTicketResponse_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int GameWebCallback_tMetatable_ref = LUA_NOREF;

static int GameWebCallback_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	GameWebCallback_t *self = (GameWebCallback_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_szURL") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_szURL), 256);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int GameWebCallback_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	GameWebCallback_t *self = (GameWebCallback_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_szURL") == 0) {
		size_t _len__tmp34;
		const char *_tmp34 = luaL_checklstring(L, 3, &_len__tmp34);
		if (_len__tmp34 > sizeof(self->m_szURL)) luaL_error(L, "String too long");
		memcpy(self->m_szURL, _tmp34, std::min(_len__tmp34 + 1, sizeof(self->m_szURL)));
		return 0;
	}
	return luaL_error(L, "GameWebCallback_t has no field '%%s'", key);
}

EXTERN int luasteam_newGameWebCallback_t(lua_State *L) {
	GameWebCallback_t *ptr = (GameWebCallback_t*)lua_newuserdata(L, sizeof(GameWebCallback_t));
	new (ptr) GameWebCallback_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_szURL");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp35;
			const char *_tmp35 = luaL_checklstring(L, -1, &_len__tmp35);
			if (_len__tmp35 > sizeof(ptr->m_szURL)) luaL_error(L, "String too long");
			memcpy(ptr->m_szURL, _tmp35, std::min(_len__tmp35 + 1, sizeof(ptr->m_szURL)));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, GameWebCallback_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int StoreAuthURLResponse_tMetatable_ref = LUA_NOREF;

static int StoreAuthURLResponse_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	StoreAuthURLResponse_t *self = (StoreAuthURLResponse_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_szURL") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_szURL), 512);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int StoreAuthURLResponse_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	StoreAuthURLResponse_t *self = (StoreAuthURLResponse_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_szURL") == 0) {
		size_t _len__tmp36;
		const char *_tmp36 = luaL_checklstring(L, 3, &_len__tmp36);
		if (_len__tmp36 > sizeof(self->m_szURL)) luaL_error(L, "String too long");
		memcpy(self->m_szURL, _tmp36, std::min(_len__tmp36 + 1, sizeof(self->m_szURL)));
		return 0;
	}
	return luaL_error(L, "StoreAuthURLResponse_t has no field '%%s'", key);
}

EXTERN int luasteam_newStoreAuthURLResponse_t(lua_State *L) {
	StoreAuthURLResponse_t *ptr = (StoreAuthURLResponse_t*)lua_newuserdata(L, sizeof(StoreAuthURLResponse_t));
	new (ptr) StoreAuthURLResponse_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_szURL");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp37;
			const char *_tmp37 = luaL_checklstring(L, -1, &_len__tmp37);
			if (_len__tmp37 > sizeof(ptr->m_szURL)) luaL_error(L, "String too long");
			memcpy(ptr->m_szURL, _tmp37, std::min(_len__tmp37 + 1, sizeof(ptr->m_szURL)));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, StoreAuthURLResponse_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int MarketEligibilityResponse_tMetatable_ref = LUA_NOREF;

static int MarketEligibilityResponse_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	MarketEligibilityResponse_t *self = (MarketEligibilityResponse_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_bAllowed") == 0) {
		lua_pushboolean(L, self->m_bAllowed);
		return 1;
	}
	if (strcmp(key, "m_eNotAllowedReason") == 0) {
		lua_pushinteger(L, self->m_eNotAllowedReason);
		return 1;
	}
	if (strcmp(key, "m_rtAllowedAtTime") == 0) {
		lua_pushinteger(L, self->m_rtAllowedAtTime);
		return 1;
	}
	if (strcmp(key, "m_cdaySteamGuardRequiredDays") == 0) {
		lua_pushinteger(L, self->m_cdaySteamGuardRequiredDays);
		return 1;
	}
	if (strcmp(key, "m_cdayNewDeviceCooldown") == 0) {
		lua_pushinteger(L, self->m_cdayNewDeviceCooldown);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int MarketEligibilityResponse_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	MarketEligibilityResponse_t *self = (MarketEligibilityResponse_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_bAllowed") == 0) {
		self->m_bAllowed = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_eNotAllowedReason") == 0) {
		self->m_eNotAllowedReason = static_cast<EMarketNotAllowedReasonFlags>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_rtAllowedAtTime") == 0) {
		self->m_rtAllowedAtTime = static_cast<RTime32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_cdaySteamGuardRequiredDays") == 0) {
		self->m_cdaySteamGuardRequiredDays = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_cdayNewDeviceCooldown") == 0) {
		self->m_cdayNewDeviceCooldown = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "MarketEligibilityResponse_t has no field '%%s'", key);
}

EXTERN int luasteam_newMarketEligibilityResponse_t(lua_State *L) {
	MarketEligibilityResponse_t *ptr = (MarketEligibilityResponse_t*)lua_newuserdata(L, sizeof(MarketEligibilityResponse_t));
	new (ptr) MarketEligibilityResponse_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_bAllowed");
		if (!lua_isnil(L, -1)) {
			ptr->m_bAllowed = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eNotAllowedReason");
		if (!lua_isnil(L, -1)) {
			ptr->m_eNotAllowedReason = static_cast<EMarketNotAllowedReasonFlags>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rtAllowedAtTime");
		if (!lua_isnil(L, -1)) {
			ptr->m_rtAllowedAtTime = static_cast<RTime32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_cdaySteamGuardRequiredDays");
		if (!lua_isnil(L, -1)) {
			ptr->m_cdaySteamGuardRequiredDays = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_cdayNewDeviceCooldown");
		if (!lua_isnil(L, -1)) {
			ptr->m_cdayNewDeviceCooldown = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, MarketEligibilityResponse_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int DurationControl_tMetatable_ref = LUA_NOREF;

static int DurationControl_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	DurationControl_t *self = (DurationControl_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_appid") == 0) {
		lua_pushinteger(L, self->m_appid);
		return 1;
	}
	if (strcmp(key, "m_bApplicable") == 0) {
		lua_pushboolean(L, self->m_bApplicable);
		return 1;
	}
	if (strcmp(key, "m_csecsLast5h") == 0) {
		lua_pushinteger(L, self->m_csecsLast5h);
		return 1;
	}
	if (strcmp(key, "m_progress") == 0) {
		lua_pushinteger(L, self->m_progress);
		return 1;
	}
	if (strcmp(key, "m_notification") == 0) {
		lua_pushinteger(L, self->m_notification);
		return 1;
	}
	if (strcmp(key, "m_csecsToday") == 0) {
		lua_pushinteger(L, self->m_csecsToday);
		return 1;
	}
	if (strcmp(key, "m_csecsRemaining") == 0) {
		lua_pushinteger(L, self->m_csecsRemaining);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int DurationControl_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	DurationControl_t *self = (DurationControl_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_appid") == 0) {
		self->m_appid = static_cast<AppId_t>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bApplicable") == 0) {
		self->m_bApplicable = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_csecsLast5h") == 0) {
		self->m_csecsLast5h = static_cast<int32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_progress") == 0) {
		self->m_progress = static_cast<EDurationControlProgress>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_notification") == 0) {
		self->m_notification = static_cast<EDurationControlNotification>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_csecsToday") == 0) {
		self->m_csecsToday = static_cast<int32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_csecsRemaining") == 0) {
		self->m_csecsRemaining = static_cast<int32>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "DurationControl_t has no field '%%s'", key);
}

EXTERN int luasteam_newDurationControl_t(lua_State *L) {
	DurationControl_t *ptr = (DurationControl_t*)lua_newuserdata(L, sizeof(DurationControl_t));
	new (ptr) DurationControl_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_appid");
		if (!lua_isnil(L, -1)) {
			ptr->m_appid = static_cast<AppId_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bApplicable");
		if (!lua_isnil(L, -1)) {
			ptr->m_bApplicable = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_csecsLast5h");
		if (!lua_isnil(L, -1)) {
			ptr->m_csecsLast5h = static_cast<int32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_progress");
		if (!lua_isnil(L, -1)) {
			ptr->m_progress = static_cast<EDurationControlProgress>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_notification");
		if (!lua_isnil(L, -1)) {
			ptr->m_notification = static_cast<EDurationControlNotification>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_csecsToday");
		if (!lua_isnil(L, -1)) {
			ptr->m_csecsToday = static_cast<int32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_csecsRemaining");
		if (!lua_isnil(L, -1)) {
			ptr->m_csecsRemaining = static_cast<int32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, DurationControl_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int GetTicketForWebApiResponse_tMetatable_ref = LUA_NOREF;

static int GetTicketForWebApiResponse_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	GetTicketForWebApiResponse_t *self = (GetTicketForWebApiResponse_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_hAuthTicket") == 0) {
		lua_pushinteger(L, self->m_hAuthTicket);
		return 1;
	}
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_cubTicket") == 0) {
		lua_pushinteger(L, self->m_cubTicket);
		return 1;
	}
	if (strcmp(key, "m_rgubTicket") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_rgubTicket), 2560);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int GetTicketForWebApiResponse_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	GetTicketForWebApiResponse_t *self = (GetTicketForWebApiResponse_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_hAuthTicket") == 0) {
		self->m_hAuthTicket = static_cast<HAuthTicket>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_cubTicket") == 0) {
		self->m_cubTicket = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_rgubTicket") == 0) {
		size_t _len__tmp38;
		const char *_tmp38 = luaL_checklstring(L, 3, &_len__tmp38);
		if (_len__tmp38 > sizeof(self->m_rgubTicket)) luaL_error(L, "String too long");
		memcpy(self->m_rgubTicket, _tmp38, std::min(_len__tmp38 + 1, sizeof(self->m_rgubTicket)));
		return 0;
	}
	return luaL_error(L, "GetTicketForWebApiResponse_t has no field '%%s'", key);
}

EXTERN int luasteam_newGetTicketForWebApiResponse_t(lua_State *L) {
	GetTicketForWebApiResponse_t *ptr = (GetTicketForWebApiResponse_t*)lua_newuserdata(L, sizeof(GetTicketForWebApiResponse_t));
	new (ptr) GetTicketForWebApiResponse_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_hAuthTicket");
		if (!lua_isnil(L, -1)) {
			ptr->m_hAuthTicket = static_cast<HAuthTicket>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_cubTicket");
		if (!lua_isnil(L, -1)) {
			ptr->m_cubTicket = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rgubTicket");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp39;
			const char *_tmp39 = luaL_checklstring(L, -1, &_len__tmp39);
			if (_len__tmp39 > sizeof(ptr->m_rgubTicket)) luaL_error(L, "String too long");
			memcpy(ptr->m_rgubTicket, _tmp39, std::min(_len__tmp39 + 1, sizeof(ptr->m_rgubTicket)));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, GetTicketForWebApiResponse_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int PersonaStateChange_tMetatable_ref = LUA_NOREF;

static int PersonaStateChange_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	PersonaStateChange_t *self = (PersonaStateChange_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_ulSteamID") == 0) {
		luasteam::pushuint64(L, self->m_ulSteamID);
		return 1;
	}
	if (strcmp(key, "m_nChangeFlags") == 0) {
		lua_pushinteger(L, self->m_nChangeFlags);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int PersonaStateChange_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	PersonaStateChange_t *self = (PersonaStateChange_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_ulSteamID") == 0) {
		self->m_ulSteamID = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_nChangeFlags") == 0) {
		self->m_nChangeFlags = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "PersonaStateChange_t has no field '%%s'", key);
}

EXTERN int luasteam_newPersonaStateChange_t(lua_State *L) {
	PersonaStateChange_t *ptr = (PersonaStateChange_t*)lua_newuserdata(L, sizeof(PersonaStateChange_t));
	new (ptr) PersonaStateChange_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_ulSteamID");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulSteamID = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nChangeFlags");
		if (!lua_isnil(L, -1)) {
			ptr->m_nChangeFlags = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, PersonaStateChange_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int GameOverlayActivated_tMetatable_ref = LUA_NOREF;

static int GameOverlayActivated_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	GameOverlayActivated_t *self = (GameOverlayActivated_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_bActive") == 0) {
		lua_pushinteger(L, self->m_bActive);
		return 1;
	}
	if (strcmp(key, "m_bUserInitiated") == 0) {
		lua_pushboolean(L, self->m_bUserInitiated);
		return 1;
	}
	if (strcmp(key, "m_nAppID") == 0) {
		lua_pushinteger(L, self->m_nAppID);
		return 1;
	}
	if (strcmp(key, "m_dwOverlayPID") == 0) {
		lua_pushinteger(L, self->m_dwOverlayPID);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int GameOverlayActivated_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	GameOverlayActivated_t *self = (GameOverlayActivated_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_bActive") == 0) {
		self->m_bActive = static_cast<uint8>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bUserInitiated") == 0) {
		self->m_bUserInitiated = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_nAppID") == 0) {
		self->m_nAppID = static_cast<AppId_t>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_dwOverlayPID") == 0) {
		self->m_dwOverlayPID = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "GameOverlayActivated_t has no field '%%s'", key);
}

EXTERN int luasteam_newGameOverlayActivated_t(lua_State *L) {
	GameOverlayActivated_t *ptr = (GameOverlayActivated_t*)lua_newuserdata(L, sizeof(GameOverlayActivated_t));
	new (ptr) GameOverlayActivated_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_bActive");
		if (!lua_isnil(L, -1)) {
			ptr->m_bActive = static_cast<uint8>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bUserInitiated");
		if (!lua_isnil(L, -1)) {
			ptr->m_bUserInitiated = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nAppID");
		if (!lua_isnil(L, -1)) {
			ptr->m_nAppID = static_cast<AppId_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_dwOverlayPID");
		if (!lua_isnil(L, -1)) {
			ptr->m_dwOverlayPID = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, GameOverlayActivated_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int GameServerChangeRequested_tMetatable_ref = LUA_NOREF;

static int GameServerChangeRequested_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	GameServerChangeRequested_t *self = (GameServerChangeRequested_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_rgchServer") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_rgchServer), 64);
		return 1;
	}
	if (strcmp(key, "m_rgchPassword") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_rgchPassword), 64);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int GameServerChangeRequested_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	GameServerChangeRequested_t *self = (GameServerChangeRequested_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_rgchServer") == 0) {
		size_t _len__tmp40;
		const char *_tmp40 = luaL_checklstring(L, 3, &_len__tmp40);
		if (_len__tmp40 > sizeof(self->m_rgchServer)) luaL_error(L, "String too long");
		memcpy(self->m_rgchServer, _tmp40, std::min(_len__tmp40 + 1, sizeof(self->m_rgchServer)));
		return 0;
	}
	if (strcmp(key, "m_rgchPassword") == 0) {
		size_t _len__tmp42;
		const char *_tmp42 = luaL_checklstring(L, 3, &_len__tmp42);
		if (_len__tmp42 > sizeof(self->m_rgchPassword)) luaL_error(L, "String too long");
		memcpy(self->m_rgchPassword, _tmp42, std::min(_len__tmp42 + 1, sizeof(self->m_rgchPassword)));
		return 0;
	}
	return luaL_error(L, "GameServerChangeRequested_t has no field '%%s'", key);
}

EXTERN int luasteam_newGameServerChangeRequested_t(lua_State *L) {
	GameServerChangeRequested_t *ptr = (GameServerChangeRequested_t*)lua_newuserdata(L, sizeof(GameServerChangeRequested_t));
	new (ptr) GameServerChangeRequested_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_rgchServer");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp41;
			const char *_tmp41 = luaL_checklstring(L, -1, &_len__tmp41);
			if (_len__tmp41 > sizeof(ptr->m_rgchServer)) luaL_error(L, "String too long");
			memcpy(ptr->m_rgchServer, _tmp41, std::min(_len__tmp41 + 1, sizeof(ptr->m_rgchServer)));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rgchPassword");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp43;
			const char *_tmp43 = luaL_checklstring(L, -1, &_len__tmp43);
			if (_len__tmp43 > sizeof(ptr->m_rgchPassword)) luaL_error(L, "String too long");
			memcpy(ptr->m_rgchPassword, _tmp43, std::min(_len__tmp43 + 1, sizeof(ptr->m_rgchPassword)));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, GameServerChangeRequested_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int GameLobbyJoinRequested_tMetatable_ref = LUA_NOREF;

static int GameLobbyJoinRequested_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	GameLobbyJoinRequested_t *self = (GameLobbyJoinRequested_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamIDLobby") == 0) {
		luasteam::pushuint64(L, self->m_steamIDLobby.ConvertToUint64());
		return 1;
	}
	if (strcmp(key, "m_steamIDFriend") == 0) {
		luasteam::pushuint64(L, self->m_steamIDFriend.ConvertToUint64());
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int GameLobbyJoinRequested_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	GameLobbyJoinRequested_t *self = (GameLobbyJoinRequested_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamIDLobby") == 0) {
		self->m_steamIDLobby = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	if (strcmp(key, "m_steamIDFriend") == 0) {
		self->m_steamIDFriend = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	return luaL_error(L, "GameLobbyJoinRequested_t has no field '%%s'", key);
}

EXTERN int luasteam_newGameLobbyJoinRequested_t(lua_State *L) {
	GameLobbyJoinRequested_t *ptr = (GameLobbyJoinRequested_t*)lua_newuserdata(L, sizeof(GameLobbyJoinRequested_t));
	new (ptr) GameLobbyJoinRequested_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_steamIDLobby");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamIDLobby = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_steamIDFriend");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamIDFriend = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, GameLobbyJoinRequested_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int AvatarImageLoaded_tMetatable_ref = LUA_NOREF;

static int AvatarImageLoaded_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	AvatarImageLoaded_t *self = (AvatarImageLoaded_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamID") == 0) {
		luasteam::pushuint64(L, self->m_steamID.ConvertToUint64());
		return 1;
	}
	if (strcmp(key, "m_iImage") == 0) {
		lua_pushinteger(L, self->m_iImage);
		return 1;
	}
	if (strcmp(key, "m_iWide") == 0) {
		lua_pushinteger(L, self->m_iWide);
		return 1;
	}
	if (strcmp(key, "m_iTall") == 0) {
		lua_pushinteger(L, self->m_iTall);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int AvatarImageLoaded_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	AvatarImageLoaded_t *self = (AvatarImageLoaded_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamID") == 0) {
		self->m_steamID = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	if (strcmp(key, "m_iImage") == 0) {
		self->m_iImage = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_iWide") == 0) {
		self->m_iWide = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_iTall") == 0) {
		self->m_iTall = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "AvatarImageLoaded_t has no field '%%s'", key);
}

EXTERN int luasteam_newAvatarImageLoaded_t(lua_State *L) {
	AvatarImageLoaded_t *ptr = (AvatarImageLoaded_t*)lua_newuserdata(L, sizeof(AvatarImageLoaded_t));
	new (ptr) AvatarImageLoaded_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_steamID");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamID = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_iImage");
		if (!lua_isnil(L, -1)) {
			ptr->m_iImage = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_iWide");
		if (!lua_isnil(L, -1)) {
			ptr->m_iWide = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_iTall");
		if (!lua_isnil(L, -1)) {
			ptr->m_iTall = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, AvatarImageLoaded_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int ClanOfficerListResponse_tMetatable_ref = LUA_NOREF;

static int ClanOfficerListResponse_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	ClanOfficerListResponse_t *self = (ClanOfficerListResponse_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamIDClan") == 0) {
		luasteam::pushuint64(L, self->m_steamIDClan.ConvertToUint64());
		return 1;
	}
	if (strcmp(key, "m_cOfficers") == 0) {
		lua_pushinteger(L, self->m_cOfficers);
		return 1;
	}
	if (strcmp(key, "m_bSuccess") == 0) {
		lua_pushinteger(L, self->m_bSuccess);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int ClanOfficerListResponse_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	ClanOfficerListResponse_t *self = (ClanOfficerListResponse_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamIDClan") == 0) {
		self->m_steamIDClan = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	if (strcmp(key, "m_cOfficers") == 0) {
		self->m_cOfficers = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bSuccess") == 0) {
		self->m_bSuccess = static_cast<uint8>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "ClanOfficerListResponse_t has no field '%%s'", key);
}

EXTERN int luasteam_newClanOfficerListResponse_t(lua_State *L) {
	ClanOfficerListResponse_t *ptr = (ClanOfficerListResponse_t*)lua_newuserdata(L, sizeof(ClanOfficerListResponse_t));
	new (ptr) ClanOfficerListResponse_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_steamIDClan");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamIDClan = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_cOfficers");
		if (!lua_isnil(L, -1)) {
			ptr->m_cOfficers = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bSuccess");
		if (!lua_isnil(L, -1)) {
			ptr->m_bSuccess = static_cast<uint8>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, ClanOfficerListResponse_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int FriendRichPresenceUpdate_tMetatable_ref = LUA_NOREF;

static int FriendRichPresenceUpdate_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	FriendRichPresenceUpdate_t *self = (FriendRichPresenceUpdate_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamIDFriend") == 0) {
		luasteam::pushuint64(L, self->m_steamIDFriend.ConvertToUint64());
		return 1;
	}
	if (strcmp(key, "m_nAppID") == 0) {
		lua_pushinteger(L, self->m_nAppID);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int FriendRichPresenceUpdate_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	FriendRichPresenceUpdate_t *self = (FriendRichPresenceUpdate_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamIDFriend") == 0) {
		self->m_steamIDFriend = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nAppID") == 0) {
		self->m_nAppID = static_cast<AppId_t>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "FriendRichPresenceUpdate_t has no field '%%s'", key);
}

EXTERN int luasteam_newFriendRichPresenceUpdate_t(lua_State *L) {
	FriendRichPresenceUpdate_t *ptr = (FriendRichPresenceUpdate_t*)lua_newuserdata(L, sizeof(FriendRichPresenceUpdate_t));
	new (ptr) FriendRichPresenceUpdate_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_steamIDFriend");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamIDFriend = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nAppID");
		if (!lua_isnil(L, -1)) {
			ptr->m_nAppID = static_cast<AppId_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, FriendRichPresenceUpdate_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int GameRichPresenceJoinRequested_tMetatable_ref = LUA_NOREF;

static int GameRichPresenceJoinRequested_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	GameRichPresenceJoinRequested_t *self = (GameRichPresenceJoinRequested_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamIDFriend") == 0) {
		luasteam::pushuint64(L, self->m_steamIDFriend.ConvertToUint64());
		return 1;
	}
	if (strcmp(key, "m_rgchConnect") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_rgchConnect), 256);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int GameRichPresenceJoinRequested_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	GameRichPresenceJoinRequested_t *self = (GameRichPresenceJoinRequested_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamIDFriend") == 0) {
		self->m_steamIDFriend = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	if (strcmp(key, "m_rgchConnect") == 0) {
		size_t _len__tmp44;
		const char *_tmp44 = luaL_checklstring(L, 3, &_len__tmp44);
		if (_len__tmp44 > sizeof(self->m_rgchConnect)) luaL_error(L, "String too long");
		memcpy(self->m_rgchConnect, _tmp44, std::min(_len__tmp44 + 1, sizeof(self->m_rgchConnect)));
		return 0;
	}
	return luaL_error(L, "GameRichPresenceJoinRequested_t has no field '%%s'", key);
}

EXTERN int luasteam_newGameRichPresenceJoinRequested_t(lua_State *L) {
	GameRichPresenceJoinRequested_t *ptr = (GameRichPresenceJoinRequested_t*)lua_newuserdata(L, sizeof(GameRichPresenceJoinRequested_t));
	new (ptr) GameRichPresenceJoinRequested_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_steamIDFriend");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamIDFriend = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rgchConnect");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp45;
			const char *_tmp45 = luaL_checklstring(L, -1, &_len__tmp45);
			if (_len__tmp45 > sizeof(ptr->m_rgchConnect)) luaL_error(L, "String too long");
			memcpy(ptr->m_rgchConnect, _tmp45, std::min(_len__tmp45 + 1, sizeof(ptr->m_rgchConnect)));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, GameRichPresenceJoinRequested_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int GameConnectedClanChatMsg_tMetatable_ref = LUA_NOREF;

static int GameConnectedClanChatMsg_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	GameConnectedClanChatMsg_t *self = (GameConnectedClanChatMsg_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamIDClanChat") == 0) {
		luasteam::pushuint64(L, self->m_steamIDClanChat.ConvertToUint64());
		return 1;
	}
	if (strcmp(key, "m_steamIDUser") == 0) {
		luasteam::pushuint64(L, self->m_steamIDUser.ConvertToUint64());
		return 1;
	}
	if (strcmp(key, "m_iMessageID") == 0) {
		lua_pushinteger(L, self->m_iMessageID);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int GameConnectedClanChatMsg_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	GameConnectedClanChatMsg_t *self = (GameConnectedClanChatMsg_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamIDClanChat") == 0) {
		self->m_steamIDClanChat = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	if (strcmp(key, "m_steamIDUser") == 0) {
		self->m_steamIDUser = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	if (strcmp(key, "m_iMessageID") == 0) {
		self->m_iMessageID = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "GameConnectedClanChatMsg_t has no field '%%s'", key);
}

EXTERN int luasteam_newGameConnectedClanChatMsg_t(lua_State *L) {
	GameConnectedClanChatMsg_t *ptr = (GameConnectedClanChatMsg_t*)lua_newuserdata(L, sizeof(GameConnectedClanChatMsg_t));
	new (ptr) GameConnectedClanChatMsg_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_steamIDClanChat");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamIDClanChat = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_steamIDUser");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamIDUser = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_iMessageID");
		if (!lua_isnil(L, -1)) {
			ptr->m_iMessageID = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, GameConnectedClanChatMsg_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int GameConnectedChatJoin_tMetatable_ref = LUA_NOREF;

static int GameConnectedChatJoin_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	GameConnectedChatJoin_t *self = (GameConnectedChatJoin_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamIDClanChat") == 0) {
		luasteam::pushuint64(L, self->m_steamIDClanChat.ConvertToUint64());
		return 1;
	}
	if (strcmp(key, "m_steamIDUser") == 0) {
		luasteam::pushuint64(L, self->m_steamIDUser.ConvertToUint64());
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int GameConnectedChatJoin_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	GameConnectedChatJoin_t *self = (GameConnectedChatJoin_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamIDClanChat") == 0) {
		self->m_steamIDClanChat = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	if (strcmp(key, "m_steamIDUser") == 0) {
		self->m_steamIDUser = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	return luaL_error(L, "GameConnectedChatJoin_t has no field '%%s'", key);
}

EXTERN int luasteam_newGameConnectedChatJoin_t(lua_State *L) {
	GameConnectedChatJoin_t *ptr = (GameConnectedChatJoin_t*)lua_newuserdata(L, sizeof(GameConnectedChatJoin_t));
	new (ptr) GameConnectedChatJoin_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_steamIDClanChat");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamIDClanChat = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_steamIDUser");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamIDUser = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, GameConnectedChatJoin_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int GameConnectedChatLeave_tMetatable_ref = LUA_NOREF;

static int GameConnectedChatLeave_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	GameConnectedChatLeave_t *self = (GameConnectedChatLeave_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamIDClanChat") == 0) {
		luasteam::pushuint64(L, self->m_steamIDClanChat.ConvertToUint64());
		return 1;
	}
	if (strcmp(key, "m_steamIDUser") == 0) {
		luasteam::pushuint64(L, self->m_steamIDUser.ConvertToUint64());
		return 1;
	}
	if (strcmp(key, "m_bKicked") == 0) {
		lua_pushboolean(L, self->m_bKicked);
		return 1;
	}
	if (strcmp(key, "m_bDropped") == 0) {
		lua_pushboolean(L, self->m_bDropped);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int GameConnectedChatLeave_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	GameConnectedChatLeave_t *self = (GameConnectedChatLeave_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamIDClanChat") == 0) {
		self->m_steamIDClanChat = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	if (strcmp(key, "m_steamIDUser") == 0) {
		self->m_steamIDUser = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bKicked") == 0) {
		self->m_bKicked = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_bDropped") == 0) {
		self->m_bDropped = lua_toboolean(L, 3);
		return 0;
	}
	return luaL_error(L, "GameConnectedChatLeave_t has no field '%%s'", key);
}

EXTERN int luasteam_newGameConnectedChatLeave_t(lua_State *L) {
	GameConnectedChatLeave_t *ptr = (GameConnectedChatLeave_t*)lua_newuserdata(L, sizeof(GameConnectedChatLeave_t));
	new (ptr) GameConnectedChatLeave_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_steamIDClanChat");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamIDClanChat = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_steamIDUser");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamIDUser = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bKicked");
		if (!lua_isnil(L, -1)) {
			ptr->m_bKicked = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bDropped");
		if (!lua_isnil(L, -1)) {
			ptr->m_bDropped = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, GameConnectedChatLeave_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int DownloadClanActivityCountsResult_tMetatable_ref = LUA_NOREF;

static int DownloadClanActivityCountsResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	DownloadClanActivityCountsResult_t *self = (DownloadClanActivityCountsResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_bSuccess") == 0) {
		lua_pushboolean(L, self->m_bSuccess);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int DownloadClanActivityCountsResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	DownloadClanActivityCountsResult_t *self = (DownloadClanActivityCountsResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_bSuccess") == 0) {
		self->m_bSuccess = lua_toboolean(L, 3);
		return 0;
	}
	return luaL_error(L, "DownloadClanActivityCountsResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newDownloadClanActivityCountsResult_t(lua_State *L) {
	DownloadClanActivityCountsResult_t *ptr = (DownloadClanActivityCountsResult_t*)lua_newuserdata(L, sizeof(DownloadClanActivityCountsResult_t));
	new (ptr) DownloadClanActivityCountsResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_bSuccess");
		if (!lua_isnil(L, -1)) {
			ptr->m_bSuccess = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, DownloadClanActivityCountsResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int JoinClanChatRoomCompletionResult_tMetatable_ref = LUA_NOREF;

static int JoinClanChatRoomCompletionResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	JoinClanChatRoomCompletionResult_t *self = (JoinClanChatRoomCompletionResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamIDClanChat") == 0) {
		luasteam::pushuint64(L, self->m_steamIDClanChat.ConvertToUint64());
		return 1;
	}
	if (strcmp(key, "m_eChatRoomEnterResponse") == 0) {
		lua_pushinteger(L, self->m_eChatRoomEnterResponse);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int JoinClanChatRoomCompletionResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	JoinClanChatRoomCompletionResult_t *self = (JoinClanChatRoomCompletionResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamIDClanChat") == 0) {
		self->m_steamIDClanChat = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	if (strcmp(key, "m_eChatRoomEnterResponse") == 0) {
		self->m_eChatRoomEnterResponse = static_cast<EChatRoomEnterResponse>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "JoinClanChatRoomCompletionResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newJoinClanChatRoomCompletionResult_t(lua_State *L) {
	JoinClanChatRoomCompletionResult_t *ptr = (JoinClanChatRoomCompletionResult_t*)lua_newuserdata(L, sizeof(JoinClanChatRoomCompletionResult_t));
	new (ptr) JoinClanChatRoomCompletionResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_steamIDClanChat");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamIDClanChat = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eChatRoomEnterResponse");
		if (!lua_isnil(L, -1)) {
			ptr->m_eChatRoomEnterResponse = static_cast<EChatRoomEnterResponse>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, JoinClanChatRoomCompletionResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int GameConnectedFriendChatMsg_tMetatable_ref = LUA_NOREF;

static int GameConnectedFriendChatMsg_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	GameConnectedFriendChatMsg_t *self = (GameConnectedFriendChatMsg_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamIDUser") == 0) {
		luasteam::pushuint64(L, self->m_steamIDUser.ConvertToUint64());
		return 1;
	}
	if (strcmp(key, "m_iMessageID") == 0) {
		lua_pushinteger(L, self->m_iMessageID);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int GameConnectedFriendChatMsg_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	GameConnectedFriendChatMsg_t *self = (GameConnectedFriendChatMsg_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamIDUser") == 0) {
		self->m_steamIDUser = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	if (strcmp(key, "m_iMessageID") == 0) {
		self->m_iMessageID = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "GameConnectedFriendChatMsg_t has no field '%%s'", key);
}

EXTERN int luasteam_newGameConnectedFriendChatMsg_t(lua_State *L) {
	GameConnectedFriendChatMsg_t *ptr = (GameConnectedFriendChatMsg_t*)lua_newuserdata(L, sizeof(GameConnectedFriendChatMsg_t));
	new (ptr) GameConnectedFriendChatMsg_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_steamIDUser");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamIDUser = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_iMessageID");
		if (!lua_isnil(L, -1)) {
			ptr->m_iMessageID = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, GameConnectedFriendChatMsg_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int FriendsGetFollowerCount_tMetatable_ref = LUA_NOREF;

static int FriendsGetFollowerCount_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	FriendsGetFollowerCount_t *self = (FriendsGetFollowerCount_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_steamID") == 0) {
		luasteam::pushuint64(L, self->m_steamID.ConvertToUint64());
		return 1;
	}
	if (strcmp(key, "m_nCount") == 0) {
		lua_pushinteger(L, self->m_nCount);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int FriendsGetFollowerCount_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	FriendsGetFollowerCount_t *self = (FriendsGetFollowerCount_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_steamID") == 0) {
		self->m_steamID = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nCount") == 0) {
		self->m_nCount = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "FriendsGetFollowerCount_t has no field '%%s'", key);
}

EXTERN int luasteam_newFriendsGetFollowerCount_t(lua_State *L) {
	FriendsGetFollowerCount_t *ptr = (FriendsGetFollowerCount_t*)lua_newuserdata(L, sizeof(FriendsGetFollowerCount_t));
	new (ptr) FriendsGetFollowerCount_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_steamID");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamID = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nCount");
		if (!lua_isnil(L, -1)) {
			ptr->m_nCount = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, FriendsGetFollowerCount_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int FriendsIsFollowing_tMetatable_ref = LUA_NOREF;

static int FriendsIsFollowing_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	FriendsIsFollowing_t *self = (FriendsIsFollowing_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_steamID") == 0) {
		luasteam::pushuint64(L, self->m_steamID.ConvertToUint64());
		return 1;
	}
	if (strcmp(key, "m_bIsFollowing") == 0) {
		lua_pushboolean(L, self->m_bIsFollowing);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int FriendsIsFollowing_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	FriendsIsFollowing_t *self = (FriendsIsFollowing_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_steamID") == 0) {
		self->m_steamID = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bIsFollowing") == 0) {
		self->m_bIsFollowing = lua_toboolean(L, 3);
		return 0;
	}
	return luaL_error(L, "FriendsIsFollowing_t has no field '%%s'", key);
}

EXTERN int luasteam_newFriendsIsFollowing_t(lua_State *L) {
	FriendsIsFollowing_t *ptr = (FriendsIsFollowing_t*)lua_newuserdata(L, sizeof(FriendsIsFollowing_t));
	new (ptr) FriendsIsFollowing_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_steamID");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamID = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bIsFollowing");
		if (!lua_isnil(L, -1)) {
			ptr->m_bIsFollowing = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, FriendsIsFollowing_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int FriendsEnumerateFollowingList_tMetatable_ref = LUA_NOREF;

static int FriendsEnumerateFollowingList_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	FriendsEnumerateFollowingList_t *self = (FriendsEnumerateFollowingList_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_rgSteamID") == 0) {
		lua_createtable(L, 50, 0);
		for(decltype(50) i = 0; i < 50; i++) {
			luasteam::pushuint64(L, self->m_rgSteamID[i].ConvertToUint64());
			lua_rawseti(L, -2, i+1);
		}
		return 1;
	}
	if (strcmp(key, "m_nResultsReturned") == 0) {
		lua_pushinteger(L, self->m_nResultsReturned);
		return 1;
	}
	if (strcmp(key, "m_nTotalResultCount") == 0) {
		lua_pushinteger(L, self->m_nTotalResultCount);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int FriendsEnumerateFollowingList_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	FriendsEnumerateFollowingList_t *self = (FriendsEnumerateFollowingList_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_rgSteamID") == 0) {
		luaL_checktype(L, 3, LUA_TTABLE);
		for(decltype(50) i = 0; i < 50; i++) {
			lua_rawgeti(L, 3, i+1);
			self->m_rgSteamID[i] = CSteamID(luasteam::checkuint64(L, -1));
			lua_pop(L, 1);
		}
		return 0;
	}
	if (strcmp(key, "m_nResultsReturned") == 0) {
		self->m_nResultsReturned = static_cast<int32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nTotalResultCount") == 0) {
		self->m_nTotalResultCount = static_cast<int32>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "FriendsEnumerateFollowingList_t has no field '%%s'", key);
}

EXTERN int luasteam_newFriendsEnumerateFollowingList_t(lua_State *L) {
	FriendsEnumerateFollowingList_t *ptr = (FriendsEnumerateFollowingList_t*)lua_newuserdata(L, sizeof(FriendsEnumerateFollowingList_t));
	new (ptr) FriendsEnumerateFollowingList_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rgSteamID");
		if (!lua_isnil(L, -1)) {
			luaL_checktype(L, -1, LUA_TTABLE);
			for(decltype(50) i = 0; i < 50; i++) {
				lua_rawgeti(L, -1, i+1);
				ptr->m_rgSteamID[i] = CSteamID(luasteam::checkuint64(L, -1));
				lua_pop(L, 1);
			}
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nResultsReturned");
		if (!lua_isnil(L, -1)) {
			ptr->m_nResultsReturned = static_cast<int32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nTotalResultCount");
		if (!lua_isnil(L, -1)) {
			ptr->m_nTotalResultCount = static_cast<int32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, FriendsEnumerateFollowingList_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int UnreadChatMessagesChanged_tMetatable_ref = LUA_NOREF;

static int UnreadChatMessagesChanged_t_index(lua_State *L) {
	lua_pushnil(L);
	return 1;
}

EXTERN int luasteam_newUnreadChatMessagesChanged_t(lua_State *L) {
	UnreadChatMessagesChanged_t *ptr = (UnreadChatMessagesChanged_t*)lua_newuserdata(L, sizeof(UnreadChatMessagesChanged_t));
	new (ptr) UnreadChatMessagesChanged_t();
	lua_rawgeti(L, LUA_REGISTRYINDEX, UnreadChatMessagesChanged_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int OverlayBrowserProtocolNavigation_tMetatable_ref = LUA_NOREF;

static int OverlayBrowserProtocolNavigation_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	OverlayBrowserProtocolNavigation_t *self = (OverlayBrowserProtocolNavigation_t*)lua_touserdata(L, 1);
	if (strcmp(key, "rgchURI") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->rgchURI), 1024);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int OverlayBrowserProtocolNavigation_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	OverlayBrowserProtocolNavigation_t *self = (OverlayBrowserProtocolNavigation_t*)lua_touserdata(L, 1);
	if (strcmp(key, "rgchURI") == 0) {
		size_t _len__tmp46;
		const char *_tmp46 = luaL_checklstring(L, 3, &_len__tmp46);
		if (_len__tmp46 > sizeof(self->rgchURI)) luaL_error(L, "String too long");
		memcpy(self->rgchURI, _tmp46, std::min(_len__tmp46 + 1, sizeof(self->rgchURI)));
		return 0;
	}
	return luaL_error(L, "OverlayBrowserProtocolNavigation_t has no field '%%s'", key);
}

EXTERN int luasteam_newOverlayBrowserProtocolNavigation_t(lua_State *L) {
	OverlayBrowserProtocolNavigation_t *ptr = (OverlayBrowserProtocolNavigation_t*)lua_newuserdata(L, sizeof(OverlayBrowserProtocolNavigation_t));
	new (ptr) OverlayBrowserProtocolNavigation_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "rgchURI");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp47;
			const char *_tmp47 = luaL_checklstring(L, -1, &_len__tmp47);
			if (_len__tmp47 > sizeof(ptr->rgchURI)) luaL_error(L, "String too long");
			memcpy(ptr->rgchURI, _tmp47, std::min(_len__tmp47 + 1, sizeof(ptr->rgchURI)));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, OverlayBrowserProtocolNavigation_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int EquippedProfileItemsChanged_tMetatable_ref = LUA_NOREF;

static int EquippedProfileItemsChanged_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	EquippedProfileItemsChanged_t *self = (EquippedProfileItemsChanged_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamID") == 0) {
		luasteam::pushuint64(L, self->m_steamID.ConvertToUint64());
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int EquippedProfileItemsChanged_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	EquippedProfileItemsChanged_t *self = (EquippedProfileItemsChanged_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamID") == 0) {
		self->m_steamID = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	return luaL_error(L, "EquippedProfileItemsChanged_t has no field '%%s'", key);
}

EXTERN int luasteam_newEquippedProfileItemsChanged_t(lua_State *L) {
	EquippedProfileItemsChanged_t *ptr = (EquippedProfileItemsChanged_t*)lua_newuserdata(L, sizeof(EquippedProfileItemsChanged_t));
	new (ptr) EquippedProfileItemsChanged_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_steamID");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamID = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, EquippedProfileItemsChanged_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int EquippedProfileItems_tMetatable_ref = LUA_NOREF;

static int EquippedProfileItems_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	EquippedProfileItems_t *self = (EquippedProfileItems_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_steamID") == 0) {
		luasteam::pushuint64(L, self->m_steamID.ConvertToUint64());
		return 1;
	}
	if (strcmp(key, "m_bHasAnimatedAvatar") == 0) {
		lua_pushboolean(L, self->m_bHasAnimatedAvatar);
		return 1;
	}
	if (strcmp(key, "m_bHasAvatarFrame") == 0) {
		lua_pushboolean(L, self->m_bHasAvatarFrame);
		return 1;
	}
	if (strcmp(key, "m_bHasProfileModifier") == 0) {
		lua_pushboolean(L, self->m_bHasProfileModifier);
		return 1;
	}
	if (strcmp(key, "m_bHasProfileBackground") == 0) {
		lua_pushboolean(L, self->m_bHasProfileBackground);
		return 1;
	}
	if (strcmp(key, "m_bHasMiniProfileBackground") == 0) {
		lua_pushboolean(L, self->m_bHasMiniProfileBackground);
		return 1;
	}
	if (strcmp(key, "m_bFromCache") == 0) {
		lua_pushboolean(L, self->m_bFromCache);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int EquippedProfileItems_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	EquippedProfileItems_t *self = (EquippedProfileItems_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_steamID") == 0) {
		self->m_steamID = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bHasAnimatedAvatar") == 0) {
		self->m_bHasAnimatedAvatar = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_bHasAvatarFrame") == 0) {
		self->m_bHasAvatarFrame = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_bHasProfileModifier") == 0) {
		self->m_bHasProfileModifier = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_bHasProfileBackground") == 0) {
		self->m_bHasProfileBackground = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_bHasMiniProfileBackground") == 0) {
		self->m_bHasMiniProfileBackground = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_bFromCache") == 0) {
		self->m_bFromCache = lua_toboolean(L, 3);
		return 0;
	}
	return luaL_error(L, "EquippedProfileItems_t has no field '%%s'", key);
}

EXTERN int luasteam_newEquippedProfileItems_t(lua_State *L) {
	EquippedProfileItems_t *ptr = (EquippedProfileItems_t*)lua_newuserdata(L, sizeof(EquippedProfileItems_t));
	new (ptr) EquippedProfileItems_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_steamID");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamID = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bHasAnimatedAvatar");
		if (!lua_isnil(L, -1)) {
			ptr->m_bHasAnimatedAvatar = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bHasAvatarFrame");
		if (!lua_isnil(L, -1)) {
			ptr->m_bHasAvatarFrame = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bHasProfileModifier");
		if (!lua_isnil(L, -1)) {
			ptr->m_bHasProfileModifier = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bHasProfileBackground");
		if (!lua_isnil(L, -1)) {
			ptr->m_bHasProfileBackground = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bHasMiniProfileBackground");
		if (!lua_isnil(L, -1)) {
			ptr->m_bHasMiniProfileBackground = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bFromCache");
		if (!lua_isnil(L, -1)) {
			ptr->m_bFromCache = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, EquippedProfileItems_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int IPCountry_tMetatable_ref = LUA_NOREF;

static int IPCountry_t_index(lua_State *L) {
	lua_pushnil(L);
	return 1;
}

EXTERN int luasteam_newIPCountry_t(lua_State *L) {
	IPCountry_t *ptr = (IPCountry_t*)lua_newuserdata(L, sizeof(IPCountry_t));
	new (ptr) IPCountry_t();
	lua_rawgeti(L, LUA_REGISTRYINDEX, IPCountry_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int LowBatteryPower_tMetatable_ref = LUA_NOREF;

static int LowBatteryPower_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	LowBatteryPower_t *self = (LowBatteryPower_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nMinutesBatteryLeft") == 0) {
		lua_pushinteger(L, self->m_nMinutesBatteryLeft);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int LowBatteryPower_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	LowBatteryPower_t *self = (LowBatteryPower_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nMinutesBatteryLeft") == 0) {
		self->m_nMinutesBatteryLeft = static_cast<uint8>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "LowBatteryPower_t has no field '%%s'", key);
}

EXTERN int luasteam_newLowBatteryPower_t(lua_State *L) {
	LowBatteryPower_t *ptr = (LowBatteryPower_t*)lua_newuserdata(L, sizeof(LowBatteryPower_t));
	new (ptr) LowBatteryPower_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_nMinutesBatteryLeft");
		if (!lua_isnil(L, -1)) {
			ptr->m_nMinutesBatteryLeft = static_cast<uint8>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, LowBatteryPower_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamAPICallCompleted_tMetatable_ref = LUA_NOREF;

static int SteamAPICallCompleted_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamAPICallCompleted_t *self = (SteamAPICallCompleted_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_hAsyncCall") == 0) {
		luasteam::pushuint64(L, self->m_hAsyncCall);
		return 1;
	}
	if (strcmp(key, "m_iCallback") == 0) {
		lua_pushinteger(L, self->m_iCallback);
		return 1;
	}
	if (strcmp(key, "m_cubParam") == 0) {
		lua_pushinteger(L, self->m_cubParam);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamAPICallCompleted_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamAPICallCompleted_t *self = (SteamAPICallCompleted_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_hAsyncCall") == 0) {
		self->m_hAsyncCall = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_iCallback") == 0) {
		self->m_iCallback = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_cubParam") == 0) {
		self->m_cubParam = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "SteamAPICallCompleted_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamAPICallCompleted_t(lua_State *L) {
	SteamAPICallCompleted_t *ptr = (SteamAPICallCompleted_t*)lua_newuserdata(L, sizeof(SteamAPICallCompleted_t));
	new (ptr) SteamAPICallCompleted_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_hAsyncCall");
		if (!lua_isnil(L, -1)) {
			ptr->m_hAsyncCall = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_iCallback");
		if (!lua_isnil(L, -1)) {
			ptr->m_iCallback = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_cubParam");
		if (!lua_isnil(L, -1)) {
			ptr->m_cubParam = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamAPICallCompleted_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamShutdown_tMetatable_ref = LUA_NOREF;

static int SteamShutdown_t_index(lua_State *L) {
	lua_pushnil(L);
	return 1;
}

EXTERN int luasteam_newSteamShutdown_t(lua_State *L) {
	SteamShutdown_t *ptr = (SteamShutdown_t*)lua_newuserdata(L, sizeof(SteamShutdown_t));
	new (ptr) SteamShutdown_t();
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamShutdown_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int CheckFileSignature_tMetatable_ref = LUA_NOREF;

static int CheckFileSignature_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	CheckFileSignature_t *self = (CheckFileSignature_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eCheckFileSignature") == 0) {
		lua_pushinteger(L, self->m_eCheckFileSignature);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int CheckFileSignature_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	CheckFileSignature_t *self = (CheckFileSignature_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eCheckFileSignature") == 0) {
		self->m_eCheckFileSignature = static_cast<ECheckFileSignature>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "CheckFileSignature_t has no field '%%s'", key);
}

EXTERN int luasteam_newCheckFileSignature_t(lua_State *L) {
	CheckFileSignature_t *ptr = (CheckFileSignature_t*)lua_newuserdata(L, sizeof(CheckFileSignature_t));
	new (ptr) CheckFileSignature_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eCheckFileSignature");
		if (!lua_isnil(L, -1)) {
			ptr->m_eCheckFileSignature = static_cast<ECheckFileSignature>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, CheckFileSignature_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int GamepadTextInputDismissed_tMetatable_ref = LUA_NOREF;

static int GamepadTextInputDismissed_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	GamepadTextInputDismissed_t *self = (GamepadTextInputDismissed_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_bSubmitted") == 0) {
		lua_pushboolean(L, self->m_bSubmitted);
		return 1;
	}
	if (strcmp(key, "m_unSubmittedText") == 0) {
		lua_pushinteger(L, self->m_unSubmittedText);
		return 1;
	}
	if (strcmp(key, "m_unAppID") == 0) {
		lua_pushinteger(L, self->m_unAppID);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int GamepadTextInputDismissed_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	GamepadTextInputDismissed_t *self = (GamepadTextInputDismissed_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_bSubmitted") == 0) {
		self->m_bSubmitted = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_unSubmittedText") == 0) {
		self->m_unSubmittedText = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_unAppID") == 0) {
		self->m_unAppID = static_cast<AppId_t>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "GamepadTextInputDismissed_t has no field '%%s'", key);
}

EXTERN int luasteam_newGamepadTextInputDismissed_t(lua_State *L) {
	GamepadTextInputDismissed_t *ptr = (GamepadTextInputDismissed_t*)lua_newuserdata(L, sizeof(GamepadTextInputDismissed_t));
	new (ptr) GamepadTextInputDismissed_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_bSubmitted");
		if (!lua_isnil(L, -1)) {
			ptr->m_bSubmitted = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unSubmittedText");
		if (!lua_isnil(L, -1)) {
			ptr->m_unSubmittedText = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unAppID");
		if (!lua_isnil(L, -1)) {
			ptr->m_unAppID = static_cast<AppId_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, GamepadTextInputDismissed_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int AppResumingFromSuspend_tMetatable_ref = LUA_NOREF;

static int AppResumingFromSuspend_t_index(lua_State *L) {
	lua_pushnil(L);
	return 1;
}

EXTERN int luasteam_newAppResumingFromSuspend_t(lua_State *L) {
	AppResumingFromSuspend_t *ptr = (AppResumingFromSuspend_t*)lua_newuserdata(L, sizeof(AppResumingFromSuspend_t));
	new (ptr) AppResumingFromSuspend_t();
	lua_rawgeti(L, LUA_REGISTRYINDEX, AppResumingFromSuspend_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int FloatingGamepadTextInputDismissed_tMetatable_ref = LUA_NOREF;

static int FloatingGamepadTextInputDismissed_t_index(lua_State *L) {
	lua_pushnil(L);
	return 1;
}

EXTERN int luasteam_newFloatingGamepadTextInputDismissed_t(lua_State *L) {
	FloatingGamepadTextInputDismissed_t *ptr = (FloatingGamepadTextInputDismissed_t*)lua_newuserdata(L, sizeof(FloatingGamepadTextInputDismissed_t));
	new (ptr) FloatingGamepadTextInputDismissed_t();
	lua_rawgeti(L, LUA_REGISTRYINDEX, FloatingGamepadTextInputDismissed_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int FilterTextDictionaryChanged_tMetatable_ref = LUA_NOREF;

static int FilterTextDictionaryChanged_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	FilterTextDictionaryChanged_t *self = (FilterTextDictionaryChanged_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eLanguage") == 0) {
		lua_pushinteger(L, self->m_eLanguage);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int FilterTextDictionaryChanged_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	FilterTextDictionaryChanged_t *self = (FilterTextDictionaryChanged_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eLanguage") == 0) {
		self->m_eLanguage = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "FilterTextDictionaryChanged_t has no field '%%s'", key);
}

EXTERN int luasteam_newFilterTextDictionaryChanged_t(lua_State *L) {
	FilterTextDictionaryChanged_t *ptr = (FilterTextDictionaryChanged_t*)lua_newuserdata(L, sizeof(FilterTextDictionaryChanged_t));
	new (ptr) FilterTextDictionaryChanged_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eLanguage");
		if (!lua_isnil(L, -1)) {
			ptr->m_eLanguage = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, FilterTextDictionaryChanged_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int FavoritesListChanged_tMetatable_ref = LUA_NOREF;

static int FavoritesListChanged_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	FavoritesListChanged_t *self = (FavoritesListChanged_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nIP") == 0) {
		lua_pushinteger(L, self->m_nIP);
		return 1;
	}
	if (strcmp(key, "m_nQueryPort") == 0) {
		lua_pushinteger(L, self->m_nQueryPort);
		return 1;
	}
	if (strcmp(key, "m_nConnPort") == 0) {
		lua_pushinteger(L, self->m_nConnPort);
		return 1;
	}
	if (strcmp(key, "m_nAppID") == 0) {
		lua_pushinteger(L, self->m_nAppID);
		return 1;
	}
	if (strcmp(key, "m_nFlags") == 0) {
		lua_pushinteger(L, self->m_nFlags);
		return 1;
	}
	if (strcmp(key, "m_bAdd") == 0) {
		lua_pushboolean(L, self->m_bAdd);
		return 1;
	}
	if (strcmp(key, "m_unAccountId") == 0) {
		lua_pushinteger(L, self->m_unAccountId);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int FavoritesListChanged_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	FavoritesListChanged_t *self = (FavoritesListChanged_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nIP") == 0) {
		self->m_nIP = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nQueryPort") == 0) {
		self->m_nQueryPort = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nConnPort") == 0) {
		self->m_nConnPort = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nAppID") == 0) {
		self->m_nAppID = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nFlags") == 0) {
		self->m_nFlags = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bAdd") == 0) {
		self->m_bAdd = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_unAccountId") == 0) {
		self->m_unAccountId = static_cast<AccountID_t>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "FavoritesListChanged_t has no field '%%s'", key);
}

EXTERN int luasteam_newFavoritesListChanged_t(lua_State *L) {
	FavoritesListChanged_t *ptr = (FavoritesListChanged_t*)lua_newuserdata(L, sizeof(FavoritesListChanged_t));
	new (ptr) FavoritesListChanged_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_nIP");
		if (!lua_isnil(L, -1)) {
			ptr->m_nIP = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nQueryPort");
		if (!lua_isnil(L, -1)) {
			ptr->m_nQueryPort = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nConnPort");
		if (!lua_isnil(L, -1)) {
			ptr->m_nConnPort = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nAppID");
		if (!lua_isnil(L, -1)) {
			ptr->m_nAppID = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nFlags");
		if (!lua_isnil(L, -1)) {
			ptr->m_nFlags = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bAdd");
		if (!lua_isnil(L, -1)) {
			ptr->m_bAdd = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unAccountId");
		if (!lua_isnil(L, -1)) {
			ptr->m_unAccountId = static_cast<AccountID_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, FavoritesListChanged_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int LobbyInvite_tMetatable_ref = LUA_NOREF;

static int LobbyInvite_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	LobbyInvite_t *self = (LobbyInvite_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_ulSteamIDUser") == 0) {
		luasteam::pushuint64(L, self->m_ulSteamIDUser);
		return 1;
	}
	if (strcmp(key, "m_ulSteamIDLobby") == 0) {
		luasteam::pushuint64(L, self->m_ulSteamIDLobby);
		return 1;
	}
	if (strcmp(key, "m_ulGameID") == 0) {
		luasteam::pushuint64(L, self->m_ulGameID);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int LobbyInvite_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	LobbyInvite_t *self = (LobbyInvite_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_ulSteamIDUser") == 0) {
		self->m_ulSteamIDUser = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_ulSteamIDLobby") == 0) {
		self->m_ulSteamIDLobby = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_ulGameID") == 0) {
		self->m_ulGameID = luasteam::checkuint64(L, 3);
		return 0;
	}
	return luaL_error(L, "LobbyInvite_t has no field '%%s'", key);
}

EXTERN int luasteam_newLobbyInvite_t(lua_State *L) {
	LobbyInvite_t *ptr = (LobbyInvite_t*)lua_newuserdata(L, sizeof(LobbyInvite_t));
	new (ptr) LobbyInvite_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_ulSteamIDUser");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulSteamIDUser = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_ulSteamIDLobby");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulSteamIDLobby = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_ulGameID");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulGameID = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, LobbyInvite_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int LobbyEnter_tMetatable_ref = LUA_NOREF;

static int LobbyEnter_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	LobbyEnter_t *self = (LobbyEnter_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_ulSteamIDLobby") == 0) {
		luasteam::pushuint64(L, self->m_ulSteamIDLobby);
		return 1;
	}
	if (strcmp(key, "m_rgfChatPermissions") == 0) {
		lua_pushinteger(L, self->m_rgfChatPermissions);
		return 1;
	}
	if (strcmp(key, "m_bLocked") == 0) {
		lua_pushboolean(L, self->m_bLocked);
		return 1;
	}
	if (strcmp(key, "m_EChatRoomEnterResponse") == 0) {
		lua_pushinteger(L, self->m_EChatRoomEnterResponse);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int LobbyEnter_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	LobbyEnter_t *self = (LobbyEnter_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_ulSteamIDLobby") == 0) {
		self->m_ulSteamIDLobby = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_rgfChatPermissions") == 0) {
		self->m_rgfChatPermissions = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bLocked") == 0) {
		self->m_bLocked = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_EChatRoomEnterResponse") == 0) {
		self->m_EChatRoomEnterResponse = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "LobbyEnter_t has no field '%%s'", key);
}

EXTERN int luasteam_newLobbyEnter_t(lua_State *L) {
	LobbyEnter_t *ptr = (LobbyEnter_t*)lua_newuserdata(L, sizeof(LobbyEnter_t));
	new (ptr) LobbyEnter_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_ulSteamIDLobby");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulSteamIDLobby = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rgfChatPermissions");
		if (!lua_isnil(L, -1)) {
			ptr->m_rgfChatPermissions = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bLocked");
		if (!lua_isnil(L, -1)) {
			ptr->m_bLocked = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_EChatRoomEnterResponse");
		if (!lua_isnil(L, -1)) {
			ptr->m_EChatRoomEnterResponse = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, LobbyEnter_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int LobbyDataUpdate_tMetatable_ref = LUA_NOREF;

static int LobbyDataUpdate_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	LobbyDataUpdate_t *self = (LobbyDataUpdate_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_ulSteamIDLobby") == 0) {
		luasteam::pushuint64(L, self->m_ulSteamIDLobby);
		return 1;
	}
	if (strcmp(key, "m_ulSteamIDMember") == 0) {
		luasteam::pushuint64(L, self->m_ulSteamIDMember);
		return 1;
	}
	if (strcmp(key, "m_bSuccess") == 0) {
		lua_pushinteger(L, self->m_bSuccess);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int LobbyDataUpdate_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	LobbyDataUpdate_t *self = (LobbyDataUpdate_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_ulSteamIDLobby") == 0) {
		self->m_ulSteamIDLobby = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_ulSteamIDMember") == 0) {
		self->m_ulSteamIDMember = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_bSuccess") == 0) {
		self->m_bSuccess = static_cast<uint8>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "LobbyDataUpdate_t has no field '%%s'", key);
}

EXTERN int luasteam_newLobbyDataUpdate_t(lua_State *L) {
	LobbyDataUpdate_t *ptr = (LobbyDataUpdate_t*)lua_newuserdata(L, sizeof(LobbyDataUpdate_t));
	new (ptr) LobbyDataUpdate_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_ulSteamIDLobby");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulSteamIDLobby = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_ulSteamIDMember");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulSteamIDMember = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bSuccess");
		if (!lua_isnil(L, -1)) {
			ptr->m_bSuccess = static_cast<uint8>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, LobbyDataUpdate_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int LobbyChatUpdate_tMetatable_ref = LUA_NOREF;

static int LobbyChatUpdate_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	LobbyChatUpdate_t *self = (LobbyChatUpdate_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_ulSteamIDLobby") == 0) {
		luasteam::pushuint64(L, self->m_ulSteamIDLobby);
		return 1;
	}
	if (strcmp(key, "m_ulSteamIDUserChanged") == 0) {
		luasteam::pushuint64(L, self->m_ulSteamIDUserChanged);
		return 1;
	}
	if (strcmp(key, "m_ulSteamIDMakingChange") == 0) {
		luasteam::pushuint64(L, self->m_ulSteamIDMakingChange);
		return 1;
	}
	if (strcmp(key, "m_rgfChatMemberStateChange") == 0) {
		lua_pushinteger(L, self->m_rgfChatMemberStateChange);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int LobbyChatUpdate_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	LobbyChatUpdate_t *self = (LobbyChatUpdate_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_ulSteamIDLobby") == 0) {
		self->m_ulSteamIDLobby = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_ulSteamIDUserChanged") == 0) {
		self->m_ulSteamIDUserChanged = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_ulSteamIDMakingChange") == 0) {
		self->m_ulSteamIDMakingChange = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_rgfChatMemberStateChange") == 0) {
		self->m_rgfChatMemberStateChange = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "LobbyChatUpdate_t has no field '%%s'", key);
}

EXTERN int luasteam_newLobbyChatUpdate_t(lua_State *L) {
	LobbyChatUpdate_t *ptr = (LobbyChatUpdate_t*)lua_newuserdata(L, sizeof(LobbyChatUpdate_t));
	new (ptr) LobbyChatUpdate_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_ulSteamIDLobby");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulSteamIDLobby = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_ulSteamIDUserChanged");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulSteamIDUserChanged = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_ulSteamIDMakingChange");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulSteamIDMakingChange = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rgfChatMemberStateChange");
		if (!lua_isnil(L, -1)) {
			ptr->m_rgfChatMemberStateChange = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, LobbyChatUpdate_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int LobbyChatMsg_tMetatable_ref = LUA_NOREF;

static int LobbyChatMsg_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	LobbyChatMsg_t *self = (LobbyChatMsg_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_ulSteamIDLobby") == 0) {
		luasteam::pushuint64(L, self->m_ulSteamIDLobby);
		return 1;
	}
	if (strcmp(key, "m_ulSteamIDUser") == 0) {
		luasteam::pushuint64(L, self->m_ulSteamIDUser);
		return 1;
	}
	if (strcmp(key, "m_eChatEntryType") == 0) {
		lua_pushinteger(L, self->m_eChatEntryType);
		return 1;
	}
	if (strcmp(key, "m_iChatID") == 0) {
		lua_pushinteger(L, self->m_iChatID);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int LobbyChatMsg_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	LobbyChatMsg_t *self = (LobbyChatMsg_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_ulSteamIDLobby") == 0) {
		self->m_ulSteamIDLobby = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_ulSteamIDUser") == 0) {
		self->m_ulSteamIDUser = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_eChatEntryType") == 0) {
		self->m_eChatEntryType = static_cast<uint8>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_iChatID") == 0) {
		self->m_iChatID = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "LobbyChatMsg_t has no field '%%s'", key);
}

EXTERN int luasteam_newLobbyChatMsg_t(lua_State *L) {
	LobbyChatMsg_t *ptr = (LobbyChatMsg_t*)lua_newuserdata(L, sizeof(LobbyChatMsg_t));
	new (ptr) LobbyChatMsg_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_ulSteamIDLobby");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulSteamIDLobby = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_ulSteamIDUser");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulSteamIDUser = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eChatEntryType");
		if (!lua_isnil(L, -1)) {
			ptr->m_eChatEntryType = static_cast<uint8>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_iChatID");
		if (!lua_isnil(L, -1)) {
			ptr->m_iChatID = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, LobbyChatMsg_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int LobbyGameCreated_tMetatable_ref = LUA_NOREF;

static int LobbyGameCreated_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	LobbyGameCreated_t *self = (LobbyGameCreated_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_ulSteamIDLobby") == 0) {
		luasteam::pushuint64(L, self->m_ulSteamIDLobby);
		return 1;
	}
	if (strcmp(key, "m_ulSteamIDGameServer") == 0) {
		luasteam::pushuint64(L, self->m_ulSteamIDGameServer);
		return 1;
	}
	if (strcmp(key, "m_unIP") == 0) {
		lua_pushinteger(L, self->m_unIP);
		return 1;
	}
	if (strcmp(key, "m_usPort") == 0) {
		lua_pushinteger(L, self->m_usPort);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int LobbyGameCreated_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	LobbyGameCreated_t *self = (LobbyGameCreated_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_ulSteamIDLobby") == 0) {
		self->m_ulSteamIDLobby = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_ulSteamIDGameServer") == 0) {
		self->m_ulSteamIDGameServer = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_unIP") == 0) {
		self->m_unIP = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_usPort") == 0) {
		self->m_usPort = static_cast<uint16>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "LobbyGameCreated_t has no field '%%s'", key);
}

EXTERN int luasteam_newLobbyGameCreated_t(lua_State *L) {
	LobbyGameCreated_t *ptr = (LobbyGameCreated_t*)lua_newuserdata(L, sizeof(LobbyGameCreated_t));
	new (ptr) LobbyGameCreated_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_ulSteamIDLobby");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulSteamIDLobby = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_ulSteamIDGameServer");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulSteamIDGameServer = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unIP");
		if (!lua_isnil(L, -1)) {
			ptr->m_unIP = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_usPort");
		if (!lua_isnil(L, -1)) {
			ptr->m_usPort = static_cast<uint16>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, LobbyGameCreated_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int LobbyMatchList_tMetatable_ref = LUA_NOREF;

static int LobbyMatchList_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	LobbyMatchList_t *self = (LobbyMatchList_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nLobbiesMatching") == 0) {
		lua_pushinteger(L, self->m_nLobbiesMatching);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int LobbyMatchList_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	LobbyMatchList_t *self = (LobbyMatchList_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nLobbiesMatching") == 0) {
		self->m_nLobbiesMatching = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "LobbyMatchList_t has no field '%%s'", key);
}

EXTERN int luasteam_newLobbyMatchList_t(lua_State *L) {
	LobbyMatchList_t *ptr = (LobbyMatchList_t*)lua_newuserdata(L, sizeof(LobbyMatchList_t));
	new (ptr) LobbyMatchList_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_nLobbiesMatching");
		if (!lua_isnil(L, -1)) {
			ptr->m_nLobbiesMatching = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, LobbyMatchList_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int LobbyKicked_tMetatable_ref = LUA_NOREF;

static int LobbyKicked_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	LobbyKicked_t *self = (LobbyKicked_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_ulSteamIDLobby") == 0) {
		luasteam::pushuint64(L, self->m_ulSteamIDLobby);
		return 1;
	}
	if (strcmp(key, "m_ulSteamIDAdmin") == 0) {
		luasteam::pushuint64(L, self->m_ulSteamIDAdmin);
		return 1;
	}
	if (strcmp(key, "m_bKickedDueToDisconnect") == 0) {
		lua_pushinteger(L, self->m_bKickedDueToDisconnect);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int LobbyKicked_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	LobbyKicked_t *self = (LobbyKicked_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_ulSteamIDLobby") == 0) {
		self->m_ulSteamIDLobby = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_ulSteamIDAdmin") == 0) {
		self->m_ulSteamIDAdmin = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_bKickedDueToDisconnect") == 0) {
		self->m_bKickedDueToDisconnect = static_cast<uint8>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "LobbyKicked_t has no field '%%s'", key);
}

EXTERN int luasteam_newLobbyKicked_t(lua_State *L) {
	LobbyKicked_t *ptr = (LobbyKicked_t*)lua_newuserdata(L, sizeof(LobbyKicked_t));
	new (ptr) LobbyKicked_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_ulSteamIDLobby");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulSteamIDLobby = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_ulSteamIDAdmin");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulSteamIDAdmin = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bKickedDueToDisconnect");
		if (!lua_isnil(L, -1)) {
			ptr->m_bKickedDueToDisconnect = static_cast<uint8>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, LobbyKicked_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int LobbyCreated_tMetatable_ref = LUA_NOREF;

static int LobbyCreated_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	LobbyCreated_t *self = (LobbyCreated_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_ulSteamIDLobby") == 0) {
		luasteam::pushuint64(L, self->m_ulSteamIDLobby);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int LobbyCreated_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	LobbyCreated_t *self = (LobbyCreated_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_ulSteamIDLobby") == 0) {
		self->m_ulSteamIDLobby = luasteam::checkuint64(L, 3);
		return 0;
	}
	return luaL_error(L, "LobbyCreated_t has no field '%%s'", key);
}

EXTERN int luasteam_newLobbyCreated_t(lua_State *L) {
	LobbyCreated_t *ptr = (LobbyCreated_t*)lua_newuserdata(L, sizeof(LobbyCreated_t));
	new (ptr) LobbyCreated_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_ulSteamIDLobby");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulSteamIDLobby = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, LobbyCreated_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int FavoritesListAccountsUpdated_tMetatable_ref = LUA_NOREF;

static int FavoritesListAccountsUpdated_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	FavoritesListAccountsUpdated_t *self = (FavoritesListAccountsUpdated_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int FavoritesListAccountsUpdated_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	FavoritesListAccountsUpdated_t *self = (FavoritesListAccountsUpdated_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "FavoritesListAccountsUpdated_t has no field '%%s'", key);
}

EXTERN int luasteam_newFavoritesListAccountsUpdated_t(lua_State *L) {
	FavoritesListAccountsUpdated_t *ptr = (FavoritesListAccountsUpdated_t*)lua_newuserdata(L, sizeof(FavoritesListAccountsUpdated_t));
	new (ptr) FavoritesListAccountsUpdated_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, FavoritesListAccountsUpdated_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int JoinPartyCallback_tMetatable_ref = LUA_NOREF;

static int JoinPartyCallback_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	JoinPartyCallback_t *self = (JoinPartyCallback_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_ulBeaconID") == 0) {
		luasteam::pushuint64(L, self->m_ulBeaconID);
		return 1;
	}
	if (strcmp(key, "m_SteamIDBeaconOwner") == 0) {
		luasteam::pushuint64(L, self->m_SteamIDBeaconOwner.ConvertToUint64());
		return 1;
	}
	if (strcmp(key, "m_rgchConnectString") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_rgchConnectString), 256);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int JoinPartyCallback_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	JoinPartyCallback_t *self = (JoinPartyCallback_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_ulBeaconID") == 0) {
		self->m_ulBeaconID = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_SteamIDBeaconOwner") == 0) {
		self->m_SteamIDBeaconOwner = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	if (strcmp(key, "m_rgchConnectString") == 0) {
		size_t _len__tmp48;
		const char *_tmp48 = luaL_checklstring(L, 3, &_len__tmp48);
		if (_len__tmp48 > sizeof(self->m_rgchConnectString)) luaL_error(L, "String too long");
		memcpy(self->m_rgchConnectString, _tmp48, std::min(_len__tmp48 + 1, sizeof(self->m_rgchConnectString)));
		return 0;
	}
	return luaL_error(L, "JoinPartyCallback_t has no field '%%s'", key);
}

EXTERN int luasteam_newJoinPartyCallback_t(lua_State *L) {
	JoinPartyCallback_t *ptr = (JoinPartyCallback_t*)lua_newuserdata(L, sizeof(JoinPartyCallback_t));
	new (ptr) JoinPartyCallback_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_ulBeaconID");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulBeaconID = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_SteamIDBeaconOwner");
		if (!lua_isnil(L, -1)) {
			ptr->m_SteamIDBeaconOwner = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rgchConnectString");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp49;
			const char *_tmp49 = luaL_checklstring(L, -1, &_len__tmp49);
			if (_len__tmp49 > sizeof(ptr->m_rgchConnectString)) luaL_error(L, "String too long");
			memcpy(ptr->m_rgchConnectString, _tmp49, std::min(_len__tmp49 + 1, sizeof(ptr->m_rgchConnectString)));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, JoinPartyCallback_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int CreateBeaconCallback_tMetatable_ref = LUA_NOREF;

static int CreateBeaconCallback_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	CreateBeaconCallback_t *self = (CreateBeaconCallback_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_ulBeaconID") == 0) {
		luasteam::pushuint64(L, self->m_ulBeaconID);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int CreateBeaconCallback_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	CreateBeaconCallback_t *self = (CreateBeaconCallback_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_ulBeaconID") == 0) {
		self->m_ulBeaconID = luasteam::checkuint64(L, 3);
		return 0;
	}
	return luaL_error(L, "CreateBeaconCallback_t has no field '%%s'", key);
}

EXTERN int luasteam_newCreateBeaconCallback_t(lua_State *L) {
	CreateBeaconCallback_t *ptr = (CreateBeaconCallback_t*)lua_newuserdata(L, sizeof(CreateBeaconCallback_t));
	new (ptr) CreateBeaconCallback_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_ulBeaconID");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulBeaconID = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, CreateBeaconCallback_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int ReservationNotificationCallback_tMetatable_ref = LUA_NOREF;

static int ReservationNotificationCallback_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	ReservationNotificationCallback_t *self = (ReservationNotificationCallback_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_ulBeaconID") == 0) {
		luasteam::pushuint64(L, self->m_ulBeaconID);
		return 1;
	}
	if (strcmp(key, "m_steamIDJoiner") == 0) {
		luasteam::pushuint64(L, self->m_steamIDJoiner.ConvertToUint64());
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int ReservationNotificationCallback_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	ReservationNotificationCallback_t *self = (ReservationNotificationCallback_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_ulBeaconID") == 0) {
		self->m_ulBeaconID = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_steamIDJoiner") == 0) {
		self->m_steamIDJoiner = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	return luaL_error(L, "ReservationNotificationCallback_t has no field '%%s'", key);
}

EXTERN int luasteam_newReservationNotificationCallback_t(lua_State *L) {
	ReservationNotificationCallback_t *ptr = (ReservationNotificationCallback_t*)lua_newuserdata(L, sizeof(ReservationNotificationCallback_t));
	new (ptr) ReservationNotificationCallback_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_ulBeaconID");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulBeaconID = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_steamIDJoiner");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamIDJoiner = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, ReservationNotificationCallback_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int ChangeNumOpenSlotsCallback_tMetatable_ref = LUA_NOREF;

static int ChangeNumOpenSlotsCallback_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	ChangeNumOpenSlotsCallback_t *self = (ChangeNumOpenSlotsCallback_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int ChangeNumOpenSlotsCallback_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	ChangeNumOpenSlotsCallback_t *self = (ChangeNumOpenSlotsCallback_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "ChangeNumOpenSlotsCallback_t has no field '%%s'", key);
}

EXTERN int luasteam_newChangeNumOpenSlotsCallback_t(lua_State *L) {
	ChangeNumOpenSlotsCallback_t *ptr = (ChangeNumOpenSlotsCallback_t*)lua_newuserdata(L, sizeof(ChangeNumOpenSlotsCallback_t));
	new (ptr) ChangeNumOpenSlotsCallback_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, ChangeNumOpenSlotsCallback_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int AvailableBeaconLocationsUpdated_tMetatable_ref = LUA_NOREF;

static int AvailableBeaconLocationsUpdated_t_index(lua_State *L) {
	lua_pushnil(L);
	return 1;
}

EXTERN int luasteam_newAvailableBeaconLocationsUpdated_t(lua_State *L) {
	AvailableBeaconLocationsUpdated_t *ptr = (AvailableBeaconLocationsUpdated_t*)lua_newuserdata(L, sizeof(AvailableBeaconLocationsUpdated_t));
	new (ptr) AvailableBeaconLocationsUpdated_t();
	lua_rawgeti(L, LUA_REGISTRYINDEX, AvailableBeaconLocationsUpdated_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int ActiveBeaconsUpdated_tMetatable_ref = LUA_NOREF;

static int ActiveBeaconsUpdated_t_index(lua_State *L) {
	lua_pushnil(L);
	return 1;
}

EXTERN int luasteam_newActiveBeaconsUpdated_t(lua_State *L) {
	ActiveBeaconsUpdated_t *ptr = (ActiveBeaconsUpdated_t*)lua_newuserdata(L, sizeof(ActiveBeaconsUpdated_t));
	new (ptr) ActiveBeaconsUpdated_t();
	lua_rawgeti(L, LUA_REGISTRYINDEX, ActiveBeaconsUpdated_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemoteStorageFileShareResult_tMetatable_ref = LUA_NOREF;

static int RemoteStorageFileShareResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageFileShareResult_t *self = (RemoteStorageFileShareResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_hFile") == 0) {
		luasteam::pushuint64(L, self->m_hFile);
		return 1;
	}
	if (strcmp(key, "m_rgchFilename") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_rgchFilename), 260);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int RemoteStorageFileShareResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageFileShareResult_t *self = (RemoteStorageFileShareResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_hFile") == 0) {
		self->m_hFile = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_rgchFilename") == 0) {
		size_t _len__tmp50;
		const char *_tmp50 = luaL_checklstring(L, 3, &_len__tmp50);
		if (_len__tmp50 > sizeof(self->m_rgchFilename)) luaL_error(L, "String too long");
		memcpy(self->m_rgchFilename, _tmp50, std::min(_len__tmp50 + 1, sizeof(self->m_rgchFilename)));
		return 0;
	}
	return luaL_error(L, "RemoteStorageFileShareResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newRemoteStorageFileShareResult_t(lua_State *L) {
	RemoteStorageFileShareResult_t *ptr = (RemoteStorageFileShareResult_t*)lua_newuserdata(L, sizeof(RemoteStorageFileShareResult_t));
	new (ptr) RemoteStorageFileShareResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_hFile");
		if (!lua_isnil(L, -1)) {
			ptr->m_hFile = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rgchFilename");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp51;
			const char *_tmp51 = luaL_checklstring(L, -1, &_len__tmp51);
			if (_len__tmp51 > sizeof(ptr->m_rgchFilename)) luaL_error(L, "String too long");
			memcpy(ptr->m_rgchFilename, _tmp51, std::min(_len__tmp51 + 1, sizeof(ptr->m_rgchFilename)));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageFileShareResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemoteStoragePublishFileResult_tMetatable_ref = LUA_NOREF;

static int RemoteStoragePublishFileResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	RemoteStoragePublishFileResult_t *self = (RemoteStoragePublishFileResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		luasteam::pushuint64(L, self->m_nPublishedFileId);
		return 1;
	}
	if (strcmp(key, "m_bUserNeedsToAcceptWorkshopLegalAgreement") == 0) {
		lua_pushboolean(L, self->m_bUserNeedsToAcceptWorkshopLegalAgreement);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int RemoteStoragePublishFileResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	RemoteStoragePublishFileResult_t *self = (RemoteStoragePublishFileResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		self->m_nPublishedFileId = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_bUserNeedsToAcceptWorkshopLegalAgreement") == 0) {
		self->m_bUserNeedsToAcceptWorkshopLegalAgreement = lua_toboolean(L, 3);
		return 0;
	}
	return luaL_error(L, "RemoteStoragePublishFileResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newRemoteStoragePublishFileResult_t(lua_State *L) {
	RemoteStoragePublishFileResult_t *ptr = (RemoteStoragePublishFileResult_t*)lua_newuserdata(L, sizeof(RemoteStoragePublishFileResult_t));
	new (ptr) RemoteStoragePublishFileResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nPublishedFileId");
		if (!lua_isnil(L, -1)) {
			ptr->m_nPublishedFileId = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bUserNeedsToAcceptWorkshopLegalAgreement");
		if (!lua_isnil(L, -1)) {
			ptr->m_bUserNeedsToAcceptWorkshopLegalAgreement = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStoragePublishFileResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemoteStorageDeletePublishedFileResult_tMetatable_ref = LUA_NOREF;

static int RemoteStorageDeletePublishedFileResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageDeletePublishedFileResult_t *self = (RemoteStorageDeletePublishedFileResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		luasteam::pushuint64(L, self->m_nPublishedFileId);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int RemoteStorageDeletePublishedFileResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageDeletePublishedFileResult_t *self = (RemoteStorageDeletePublishedFileResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		self->m_nPublishedFileId = luasteam::checkuint64(L, 3);
		return 0;
	}
	return luaL_error(L, "RemoteStorageDeletePublishedFileResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newRemoteStorageDeletePublishedFileResult_t(lua_State *L) {
	RemoteStorageDeletePublishedFileResult_t *ptr = (RemoteStorageDeletePublishedFileResult_t*)lua_newuserdata(L, sizeof(RemoteStorageDeletePublishedFileResult_t));
	new (ptr) RemoteStorageDeletePublishedFileResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nPublishedFileId");
		if (!lua_isnil(L, -1)) {
			ptr->m_nPublishedFileId = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageDeletePublishedFileResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemoteStorageEnumerateUserPublishedFilesResult_tMetatable_ref = LUA_NOREF;

static int RemoteStorageEnumerateUserPublishedFilesResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageEnumerateUserPublishedFilesResult_t *self = (RemoteStorageEnumerateUserPublishedFilesResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_nResultsReturned") == 0) {
		lua_pushinteger(L, self->m_nResultsReturned);
		return 1;
	}
	if (strcmp(key, "m_nTotalResultCount") == 0) {
		lua_pushinteger(L, self->m_nTotalResultCount);
		return 1;
	}
	if (strcmp(key, "m_rgPublishedFileId") == 0) {
		lua_createtable(L, 50, 0);
		for(decltype(50) i = 0; i < 50; i++) {
			luasteam::pushuint64(L, self->m_rgPublishedFileId[i]);
			lua_rawseti(L, -2, i+1);
		}
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int RemoteStorageEnumerateUserPublishedFilesResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageEnumerateUserPublishedFilesResult_t *self = (RemoteStorageEnumerateUserPublishedFilesResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nResultsReturned") == 0) {
		self->m_nResultsReturned = static_cast<int32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nTotalResultCount") == 0) {
		self->m_nTotalResultCount = static_cast<int32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_rgPublishedFileId") == 0) {
		luaL_checktype(L, 3, LUA_TTABLE);
		for(decltype(50) i = 0; i < 50; i++) {
			lua_rawgeti(L, 3, i+1);
			self->m_rgPublishedFileId[i] = luasteam::checkuint64(L, -1);
			lua_pop(L, 1);
		}
		return 0;
	}
	return luaL_error(L, "RemoteStorageEnumerateUserPublishedFilesResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newRemoteStorageEnumerateUserPublishedFilesResult_t(lua_State *L) {
	RemoteStorageEnumerateUserPublishedFilesResult_t *ptr = (RemoteStorageEnumerateUserPublishedFilesResult_t*)lua_newuserdata(L, sizeof(RemoteStorageEnumerateUserPublishedFilesResult_t));
	new (ptr) RemoteStorageEnumerateUserPublishedFilesResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nResultsReturned");
		if (!lua_isnil(L, -1)) {
			ptr->m_nResultsReturned = static_cast<int32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nTotalResultCount");
		if (!lua_isnil(L, -1)) {
			ptr->m_nTotalResultCount = static_cast<int32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rgPublishedFileId");
		if (!lua_isnil(L, -1)) {
			luaL_checktype(L, -1, LUA_TTABLE);
			for(decltype(50) i = 0; i < 50; i++) {
				lua_rawgeti(L, -1, i+1);
				ptr->m_rgPublishedFileId[i] = luasteam::checkuint64(L, -1);
				lua_pop(L, 1);
			}
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageEnumerateUserPublishedFilesResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemoteStorageSubscribePublishedFileResult_tMetatable_ref = LUA_NOREF;

static int RemoteStorageSubscribePublishedFileResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageSubscribePublishedFileResult_t *self = (RemoteStorageSubscribePublishedFileResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		luasteam::pushuint64(L, self->m_nPublishedFileId);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int RemoteStorageSubscribePublishedFileResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageSubscribePublishedFileResult_t *self = (RemoteStorageSubscribePublishedFileResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		self->m_nPublishedFileId = luasteam::checkuint64(L, 3);
		return 0;
	}
	return luaL_error(L, "RemoteStorageSubscribePublishedFileResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newRemoteStorageSubscribePublishedFileResult_t(lua_State *L) {
	RemoteStorageSubscribePublishedFileResult_t *ptr = (RemoteStorageSubscribePublishedFileResult_t*)lua_newuserdata(L, sizeof(RemoteStorageSubscribePublishedFileResult_t));
	new (ptr) RemoteStorageSubscribePublishedFileResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nPublishedFileId");
		if (!lua_isnil(L, -1)) {
			ptr->m_nPublishedFileId = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageSubscribePublishedFileResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemoteStorageEnumerateUserSubscribedFilesResult_tMetatable_ref = LUA_NOREF;

static int RemoteStorageEnumerateUserSubscribedFilesResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageEnumerateUserSubscribedFilesResult_t *self = (RemoteStorageEnumerateUserSubscribedFilesResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_nResultsReturned") == 0) {
		lua_pushinteger(L, self->m_nResultsReturned);
		return 1;
	}
	if (strcmp(key, "m_nTotalResultCount") == 0) {
		lua_pushinteger(L, self->m_nTotalResultCount);
		return 1;
	}
	if (strcmp(key, "m_rgPublishedFileId") == 0) {
		lua_createtable(L, 50, 0);
		for(decltype(50) i = 0; i < 50; i++) {
			luasteam::pushuint64(L, self->m_rgPublishedFileId[i]);
			lua_rawseti(L, -2, i+1);
		}
		return 1;
	}
	if (strcmp(key, "m_rgRTimeSubscribed") == 0) {
		lua_createtable(L, 50, 0);
		for(decltype(50) i = 0; i < 50; i++) {
			lua_pushinteger(L, self->m_rgRTimeSubscribed[i]);
			lua_rawseti(L, -2, i+1);
		}
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int RemoteStorageEnumerateUserSubscribedFilesResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageEnumerateUserSubscribedFilesResult_t *self = (RemoteStorageEnumerateUserSubscribedFilesResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nResultsReturned") == 0) {
		self->m_nResultsReturned = static_cast<int32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nTotalResultCount") == 0) {
		self->m_nTotalResultCount = static_cast<int32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_rgPublishedFileId") == 0) {
		luaL_checktype(L, 3, LUA_TTABLE);
		for(decltype(50) i = 0; i < 50; i++) {
			lua_rawgeti(L, 3, i+1);
			self->m_rgPublishedFileId[i] = luasteam::checkuint64(L, -1);
			lua_pop(L, 1);
		}
		return 0;
	}
	if (strcmp(key, "m_rgRTimeSubscribed") == 0) {
		luaL_checktype(L, 3, LUA_TTABLE);
		for(decltype(50) i = 0; i < 50; i++) {
			lua_rawgeti(L, 3, i+1);
			self->m_rgRTimeSubscribed[i] = static_cast<int>(luaL_checkint(L, -1));
			lua_pop(L, 1);
		}
		return 0;
	}
	return luaL_error(L, "RemoteStorageEnumerateUserSubscribedFilesResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newRemoteStorageEnumerateUserSubscribedFilesResult_t(lua_State *L) {
	RemoteStorageEnumerateUserSubscribedFilesResult_t *ptr = (RemoteStorageEnumerateUserSubscribedFilesResult_t*)lua_newuserdata(L, sizeof(RemoteStorageEnumerateUserSubscribedFilesResult_t));
	new (ptr) RemoteStorageEnumerateUserSubscribedFilesResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nResultsReturned");
		if (!lua_isnil(L, -1)) {
			ptr->m_nResultsReturned = static_cast<int32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nTotalResultCount");
		if (!lua_isnil(L, -1)) {
			ptr->m_nTotalResultCount = static_cast<int32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rgPublishedFileId");
		if (!lua_isnil(L, -1)) {
			luaL_checktype(L, -1, LUA_TTABLE);
			for(decltype(50) i = 0; i < 50; i++) {
				lua_rawgeti(L, -1, i+1);
				ptr->m_rgPublishedFileId[i] = luasteam::checkuint64(L, -1);
				lua_pop(L, 1);
			}
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rgRTimeSubscribed");
		if (!lua_isnil(L, -1)) {
			luaL_checktype(L, -1, LUA_TTABLE);
			for(decltype(50) i = 0; i < 50; i++) {
				lua_rawgeti(L, -1, i+1);
				ptr->m_rgRTimeSubscribed[i] = static_cast<int>(luaL_checkint(L, -1));
				lua_pop(L, 1);
			}
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageEnumerateUserSubscribedFilesResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemoteStorageUnsubscribePublishedFileResult_tMetatable_ref = LUA_NOREF;

static int RemoteStorageUnsubscribePublishedFileResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageUnsubscribePublishedFileResult_t *self = (RemoteStorageUnsubscribePublishedFileResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		luasteam::pushuint64(L, self->m_nPublishedFileId);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int RemoteStorageUnsubscribePublishedFileResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageUnsubscribePublishedFileResult_t *self = (RemoteStorageUnsubscribePublishedFileResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		self->m_nPublishedFileId = luasteam::checkuint64(L, 3);
		return 0;
	}
	return luaL_error(L, "RemoteStorageUnsubscribePublishedFileResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newRemoteStorageUnsubscribePublishedFileResult_t(lua_State *L) {
	RemoteStorageUnsubscribePublishedFileResult_t *ptr = (RemoteStorageUnsubscribePublishedFileResult_t*)lua_newuserdata(L, sizeof(RemoteStorageUnsubscribePublishedFileResult_t));
	new (ptr) RemoteStorageUnsubscribePublishedFileResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nPublishedFileId");
		if (!lua_isnil(L, -1)) {
			ptr->m_nPublishedFileId = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageUnsubscribePublishedFileResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemoteStorageUpdatePublishedFileResult_tMetatable_ref = LUA_NOREF;

static int RemoteStorageUpdatePublishedFileResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageUpdatePublishedFileResult_t *self = (RemoteStorageUpdatePublishedFileResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		luasteam::pushuint64(L, self->m_nPublishedFileId);
		return 1;
	}
	if (strcmp(key, "m_bUserNeedsToAcceptWorkshopLegalAgreement") == 0) {
		lua_pushboolean(L, self->m_bUserNeedsToAcceptWorkshopLegalAgreement);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int RemoteStorageUpdatePublishedFileResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageUpdatePublishedFileResult_t *self = (RemoteStorageUpdatePublishedFileResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		self->m_nPublishedFileId = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_bUserNeedsToAcceptWorkshopLegalAgreement") == 0) {
		self->m_bUserNeedsToAcceptWorkshopLegalAgreement = lua_toboolean(L, 3);
		return 0;
	}
	return luaL_error(L, "RemoteStorageUpdatePublishedFileResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newRemoteStorageUpdatePublishedFileResult_t(lua_State *L) {
	RemoteStorageUpdatePublishedFileResult_t *ptr = (RemoteStorageUpdatePublishedFileResult_t*)lua_newuserdata(L, sizeof(RemoteStorageUpdatePublishedFileResult_t));
	new (ptr) RemoteStorageUpdatePublishedFileResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nPublishedFileId");
		if (!lua_isnil(L, -1)) {
			ptr->m_nPublishedFileId = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bUserNeedsToAcceptWorkshopLegalAgreement");
		if (!lua_isnil(L, -1)) {
			ptr->m_bUserNeedsToAcceptWorkshopLegalAgreement = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageUpdatePublishedFileResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemoteStorageDownloadUGCResult_tMetatable_ref = LUA_NOREF;

static int RemoteStorageDownloadUGCResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageDownloadUGCResult_t *self = (RemoteStorageDownloadUGCResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_hFile") == 0) {
		luasteam::pushuint64(L, self->m_hFile);
		return 1;
	}
	if (strcmp(key, "m_nAppID") == 0) {
		lua_pushinteger(L, self->m_nAppID);
		return 1;
	}
	if (strcmp(key, "m_nSizeInBytes") == 0) {
		lua_pushinteger(L, self->m_nSizeInBytes);
		return 1;
	}
	if (strcmp(key, "m_pchFileName") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_pchFileName), 260);
		return 1;
	}
	if (strcmp(key, "m_ulSteamIDOwner") == 0) {
		luasteam::pushuint64(L, self->m_ulSteamIDOwner);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int RemoteStorageDownloadUGCResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageDownloadUGCResult_t *self = (RemoteStorageDownloadUGCResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_hFile") == 0) {
		self->m_hFile = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_nAppID") == 0) {
		self->m_nAppID = static_cast<AppId_t>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nSizeInBytes") == 0) {
		self->m_nSizeInBytes = static_cast<int32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_pchFileName") == 0) {
		size_t _len__tmp52;
		const char *_tmp52 = luaL_checklstring(L, 3, &_len__tmp52);
		if (_len__tmp52 > sizeof(self->m_pchFileName)) luaL_error(L, "String too long");
		memcpy(self->m_pchFileName, _tmp52, std::min(_len__tmp52 + 1, sizeof(self->m_pchFileName)));
		return 0;
	}
	if (strcmp(key, "m_ulSteamIDOwner") == 0) {
		self->m_ulSteamIDOwner = luasteam::checkuint64(L, 3);
		return 0;
	}
	return luaL_error(L, "RemoteStorageDownloadUGCResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newRemoteStorageDownloadUGCResult_t(lua_State *L) {
	RemoteStorageDownloadUGCResult_t *ptr = (RemoteStorageDownloadUGCResult_t*)lua_newuserdata(L, sizeof(RemoteStorageDownloadUGCResult_t));
	new (ptr) RemoteStorageDownloadUGCResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_hFile");
		if (!lua_isnil(L, -1)) {
			ptr->m_hFile = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nAppID");
		if (!lua_isnil(L, -1)) {
			ptr->m_nAppID = static_cast<AppId_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nSizeInBytes");
		if (!lua_isnil(L, -1)) {
			ptr->m_nSizeInBytes = static_cast<int32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_pchFileName");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp53;
			const char *_tmp53 = luaL_checklstring(L, -1, &_len__tmp53);
			if (_len__tmp53 > sizeof(ptr->m_pchFileName)) luaL_error(L, "String too long");
			memcpy(ptr->m_pchFileName, _tmp53, std::min(_len__tmp53 + 1, sizeof(ptr->m_pchFileName)));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_ulSteamIDOwner");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulSteamIDOwner = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageDownloadUGCResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemoteStorageGetPublishedFileDetailsResult_tMetatable_ref = LUA_NOREF;

static int RemoteStorageGetPublishedFileDetailsResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageGetPublishedFileDetailsResult_t *self = (RemoteStorageGetPublishedFileDetailsResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		luasteam::pushuint64(L, self->m_nPublishedFileId);
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
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_rgchTitle), 129);
		return 1;
	}
	if (strcmp(key, "m_rgchDescription") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_rgchDescription), 8000);
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
	if (strcmp(key, "m_eVisibility") == 0) {
		lua_pushinteger(L, self->m_eVisibility);
		return 1;
	}
	if (strcmp(key, "m_bBanned") == 0) {
		lua_pushboolean(L, self->m_bBanned);
		return 1;
	}
	if (strcmp(key, "m_rgchTags") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_rgchTags), 1025);
		return 1;
	}
	if (strcmp(key, "m_bTagsTruncated") == 0) {
		lua_pushboolean(L, self->m_bTagsTruncated);
		return 1;
	}
	if (strcmp(key, "m_pchFileName") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_pchFileName), 260);
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
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_rgchURL), 256);
		return 1;
	}
	if (strcmp(key, "m_eFileType") == 0) {
		lua_pushinteger(L, self->m_eFileType);
		return 1;
	}
	if (strcmp(key, "m_bAcceptedForUse") == 0) {
		lua_pushboolean(L, self->m_bAcceptedForUse);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int RemoteStorageGetPublishedFileDetailsResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageGetPublishedFileDetailsResult_t *self = (RemoteStorageGetPublishedFileDetailsResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		self->m_nPublishedFileId = luasteam::checkuint64(L, 3);
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
		size_t _len__tmp54;
		const char *_tmp54 = luaL_checklstring(L, 3, &_len__tmp54);
		if (_len__tmp54 > sizeof(self->m_rgchTitle)) luaL_error(L, "String too long");
		memcpy(self->m_rgchTitle, _tmp54, std::min(_len__tmp54 + 1, sizeof(self->m_rgchTitle)));
		return 0;
	}
	if (strcmp(key, "m_rgchDescription") == 0) {
		size_t _len__tmp56;
		const char *_tmp56 = luaL_checklstring(L, 3, &_len__tmp56);
		if (_len__tmp56 > sizeof(self->m_rgchDescription)) luaL_error(L, "String too long");
		memcpy(self->m_rgchDescription, _tmp56, std::min(_len__tmp56 + 1, sizeof(self->m_rgchDescription)));
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
	if (strcmp(key, "m_eVisibility") == 0) {
		self->m_eVisibility = static_cast<ERemoteStoragePublishedFileVisibility>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bBanned") == 0) {
		self->m_bBanned = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_rgchTags") == 0) {
		size_t _len__tmp58;
		const char *_tmp58 = luaL_checklstring(L, 3, &_len__tmp58);
		if (_len__tmp58 > sizeof(self->m_rgchTags)) luaL_error(L, "String too long");
		memcpy(self->m_rgchTags, _tmp58, std::min(_len__tmp58 + 1, sizeof(self->m_rgchTags)));
		return 0;
	}
	if (strcmp(key, "m_bTagsTruncated") == 0) {
		self->m_bTagsTruncated = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_pchFileName") == 0) {
		size_t _len__tmp60;
		const char *_tmp60 = luaL_checklstring(L, 3, &_len__tmp60);
		if (_len__tmp60 > sizeof(self->m_pchFileName)) luaL_error(L, "String too long");
		memcpy(self->m_pchFileName, _tmp60, std::min(_len__tmp60 + 1, sizeof(self->m_pchFileName)));
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
		size_t _len__tmp62;
		const char *_tmp62 = luaL_checklstring(L, 3, &_len__tmp62);
		if (_len__tmp62 > sizeof(self->m_rgchURL)) luaL_error(L, "String too long");
		memcpy(self->m_rgchURL, _tmp62, std::min(_len__tmp62 + 1, sizeof(self->m_rgchURL)));
		return 0;
	}
	if (strcmp(key, "m_eFileType") == 0) {
		self->m_eFileType = static_cast<EWorkshopFileType>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bAcceptedForUse") == 0) {
		self->m_bAcceptedForUse = lua_toboolean(L, 3);
		return 0;
	}
	return luaL_error(L, "RemoteStorageGetPublishedFileDetailsResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newRemoteStorageGetPublishedFileDetailsResult_t(lua_State *L) {
	RemoteStorageGetPublishedFileDetailsResult_t *ptr = (RemoteStorageGetPublishedFileDetailsResult_t*)lua_newuserdata(L, sizeof(RemoteStorageGetPublishedFileDetailsResult_t));
	new (ptr) RemoteStorageGetPublishedFileDetailsResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nPublishedFileId");
		if (!lua_isnil(L, -1)) {
			ptr->m_nPublishedFileId = luasteam::checkuint64(L, -1);
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
			size_t _len__tmp55;
			const char *_tmp55 = luaL_checklstring(L, -1, &_len__tmp55);
			if (_len__tmp55 > sizeof(ptr->m_rgchTitle)) luaL_error(L, "String too long");
			memcpy(ptr->m_rgchTitle, _tmp55, std::min(_len__tmp55 + 1, sizeof(ptr->m_rgchTitle)));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rgchDescription");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp57;
			const char *_tmp57 = luaL_checklstring(L, -1, &_len__tmp57);
			if (_len__tmp57 > sizeof(ptr->m_rgchDescription)) luaL_error(L, "String too long");
			memcpy(ptr->m_rgchDescription, _tmp57, std::min(_len__tmp57 + 1, sizeof(ptr->m_rgchDescription)));
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
		lua_getfield(L, 1, "m_rgchTags");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp59;
			const char *_tmp59 = luaL_checklstring(L, -1, &_len__tmp59);
			if (_len__tmp59 > sizeof(ptr->m_rgchTags)) luaL_error(L, "String too long");
			memcpy(ptr->m_rgchTags, _tmp59, std::min(_len__tmp59 + 1, sizeof(ptr->m_rgchTags)));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bTagsTruncated");
		if (!lua_isnil(L, -1)) {
			ptr->m_bTagsTruncated = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_pchFileName");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp61;
			const char *_tmp61 = luaL_checklstring(L, -1, &_len__tmp61);
			if (_len__tmp61 > sizeof(ptr->m_pchFileName)) luaL_error(L, "String too long");
			memcpy(ptr->m_pchFileName, _tmp61, std::min(_len__tmp61 + 1, sizeof(ptr->m_pchFileName)));
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
			size_t _len__tmp63;
			const char *_tmp63 = luaL_checklstring(L, -1, &_len__tmp63);
			if (_len__tmp63 > sizeof(ptr->m_rgchURL)) luaL_error(L, "String too long");
			memcpy(ptr->m_rgchURL, _tmp63, std::min(_len__tmp63 + 1, sizeof(ptr->m_rgchURL)));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eFileType");
		if (!lua_isnil(L, -1)) {
			ptr->m_eFileType = static_cast<EWorkshopFileType>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bAcceptedForUse");
		if (!lua_isnil(L, -1)) {
			ptr->m_bAcceptedForUse = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageGetPublishedFileDetailsResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemoteStorageEnumerateWorkshopFilesResult_tMetatable_ref = LUA_NOREF;

static int RemoteStorageEnumerateWorkshopFilesResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageEnumerateWorkshopFilesResult_t *self = (RemoteStorageEnumerateWorkshopFilesResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_nResultsReturned") == 0) {
		lua_pushinteger(L, self->m_nResultsReturned);
		return 1;
	}
	if (strcmp(key, "m_nTotalResultCount") == 0) {
		lua_pushinteger(L, self->m_nTotalResultCount);
		return 1;
	}
	if (strcmp(key, "m_rgPublishedFileId") == 0) {
		lua_createtable(L, 50, 0);
		for(decltype(50) i = 0; i < 50; i++) {
			luasteam::pushuint64(L, self->m_rgPublishedFileId[i]);
			lua_rawseti(L, -2, i+1);
		}
		return 1;
	}
	if (strcmp(key, "m_rgScore") == 0) {
		lua_createtable(L, 50, 0);
		for(decltype(50) i = 0; i < 50; i++) {
			lua_pushnumber(L, self->m_rgScore[i]);
			lua_rawseti(L, -2, i+1);
		}
		return 1;
	}
	if (strcmp(key, "m_nAppId") == 0) {
		lua_pushinteger(L, self->m_nAppId);
		return 1;
	}
	if (strcmp(key, "m_unStartIndex") == 0) {
		lua_pushinteger(L, self->m_unStartIndex);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int RemoteStorageEnumerateWorkshopFilesResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageEnumerateWorkshopFilesResult_t *self = (RemoteStorageEnumerateWorkshopFilesResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nResultsReturned") == 0) {
		self->m_nResultsReturned = static_cast<int32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nTotalResultCount") == 0) {
		self->m_nTotalResultCount = static_cast<int32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_rgPublishedFileId") == 0) {
		luaL_checktype(L, 3, LUA_TTABLE);
		for(decltype(50) i = 0; i < 50; i++) {
			lua_rawgeti(L, 3, i+1);
			self->m_rgPublishedFileId[i] = luasteam::checkuint64(L, -1);
			lua_pop(L, 1);
		}
		return 0;
	}
	if (strcmp(key, "m_rgScore") == 0) {
		luaL_checktype(L, 3, LUA_TTABLE);
		for(decltype(50) i = 0; i < 50; i++) {
			lua_rawgeti(L, 3, i+1);
			self->m_rgScore[i] = static_cast<float>(luaL_checknumber(L, -1));
			lua_pop(L, 1);
		}
		return 0;
	}
	if (strcmp(key, "m_nAppId") == 0) {
		self->m_nAppId = static_cast<AppId_t>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_unStartIndex") == 0) {
		self->m_unStartIndex = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "RemoteStorageEnumerateWorkshopFilesResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newRemoteStorageEnumerateWorkshopFilesResult_t(lua_State *L) {
	RemoteStorageEnumerateWorkshopFilesResult_t *ptr = (RemoteStorageEnumerateWorkshopFilesResult_t*)lua_newuserdata(L, sizeof(RemoteStorageEnumerateWorkshopFilesResult_t));
	new (ptr) RemoteStorageEnumerateWorkshopFilesResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nResultsReturned");
		if (!lua_isnil(L, -1)) {
			ptr->m_nResultsReturned = static_cast<int32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nTotalResultCount");
		if (!lua_isnil(L, -1)) {
			ptr->m_nTotalResultCount = static_cast<int32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rgPublishedFileId");
		if (!lua_isnil(L, -1)) {
			luaL_checktype(L, -1, LUA_TTABLE);
			for(decltype(50) i = 0; i < 50; i++) {
				lua_rawgeti(L, -1, i+1);
				ptr->m_rgPublishedFileId[i] = luasteam::checkuint64(L, -1);
				lua_pop(L, 1);
			}
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rgScore");
		if (!lua_isnil(L, -1)) {
			luaL_checktype(L, -1, LUA_TTABLE);
			for(decltype(50) i = 0; i < 50; i++) {
				lua_rawgeti(L, -1, i+1);
				ptr->m_rgScore[i] = static_cast<float>(luaL_checknumber(L, -1));
				lua_pop(L, 1);
			}
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nAppId");
		if (!lua_isnil(L, -1)) {
			ptr->m_nAppId = static_cast<AppId_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unStartIndex");
		if (!lua_isnil(L, -1)) {
			ptr->m_unStartIndex = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageEnumerateWorkshopFilesResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemoteStorageGetPublishedItemVoteDetailsResult_tMetatable_ref = LUA_NOREF;

static int RemoteStorageGetPublishedItemVoteDetailsResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageGetPublishedItemVoteDetailsResult_t *self = (RemoteStorageGetPublishedItemVoteDetailsResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_unPublishedFileId") == 0) {
		luasteam::pushuint64(L, self->m_unPublishedFileId);
		return 1;
	}
	if (strcmp(key, "m_nVotesFor") == 0) {
		lua_pushinteger(L, self->m_nVotesFor);
		return 1;
	}
	if (strcmp(key, "m_nVotesAgainst") == 0) {
		lua_pushinteger(L, self->m_nVotesAgainst);
		return 1;
	}
	if (strcmp(key, "m_nReports") == 0) {
		lua_pushinteger(L, self->m_nReports);
		return 1;
	}
	if (strcmp(key, "m_fScore") == 0) {
		lua_pushnumber(L, self->m_fScore);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int RemoteStorageGetPublishedItemVoteDetailsResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageGetPublishedItemVoteDetailsResult_t *self = (RemoteStorageGetPublishedItemVoteDetailsResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_unPublishedFileId") == 0) {
		self->m_unPublishedFileId = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_nVotesFor") == 0) {
		self->m_nVotesFor = static_cast<int32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nVotesAgainst") == 0) {
		self->m_nVotesAgainst = static_cast<int32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nReports") == 0) {
		self->m_nReports = static_cast<int32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_fScore") == 0) {
		self->m_fScore = static_cast<float>(luaL_checknumber(L, 3));
		return 0;
	}
	return luaL_error(L, "RemoteStorageGetPublishedItemVoteDetailsResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newRemoteStorageGetPublishedItemVoteDetailsResult_t(lua_State *L) {
	RemoteStorageGetPublishedItemVoteDetailsResult_t *ptr = (RemoteStorageGetPublishedItemVoteDetailsResult_t*)lua_newuserdata(L, sizeof(RemoteStorageGetPublishedItemVoteDetailsResult_t));
	new (ptr) RemoteStorageGetPublishedItemVoteDetailsResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unPublishedFileId");
		if (!lua_isnil(L, -1)) {
			ptr->m_unPublishedFileId = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nVotesFor");
		if (!lua_isnil(L, -1)) {
			ptr->m_nVotesFor = static_cast<int32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nVotesAgainst");
		if (!lua_isnil(L, -1)) {
			ptr->m_nVotesAgainst = static_cast<int32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nReports");
		if (!lua_isnil(L, -1)) {
			ptr->m_nReports = static_cast<int32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_fScore");
		if (!lua_isnil(L, -1)) {
			ptr->m_fScore = static_cast<float>(luaL_checknumber(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageGetPublishedItemVoteDetailsResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemoteStoragePublishedFileSubscribed_tMetatable_ref = LUA_NOREF;

static int RemoteStoragePublishedFileSubscribed_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	RemoteStoragePublishedFileSubscribed_t *self = (RemoteStoragePublishedFileSubscribed_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		luasteam::pushuint64(L, self->m_nPublishedFileId);
		return 1;
	}
	if (strcmp(key, "m_nAppID") == 0) {
		lua_pushinteger(L, self->m_nAppID);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int RemoteStoragePublishedFileSubscribed_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	RemoteStoragePublishedFileSubscribed_t *self = (RemoteStoragePublishedFileSubscribed_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		self->m_nPublishedFileId = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_nAppID") == 0) {
		self->m_nAppID = static_cast<AppId_t>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "RemoteStoragePublishedFileSubscribed_t has no field '%%s'", key);
}

EXTERN int luasteam_newRemoteStoragePublishedFileSubscribed_t(lua_State *L) {
	RemoteStoragePublishedFileSubscribed_t *ptr = (RemoteStoragePublishedFileSubscribed_t*)lua_newuserdata(L, sizeof(RemoteStoragePublishedFileSubscribed_t));
	new (ptr) RemoteStoragePublishedFileSubscribed_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_nPublishedFileId");
		if (!lua_isnil(L, -1)) {
			ptr->m_nPublishedFileId = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nAppID");
		if (!lua_isnil(L, -1)) {
			ptr->m_nAppID = static_cast<AppId_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStoragePublishedFileSubscribed_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemoteStoragePublishedFileUnsubscribed_tMetatable_ref = LUA_NOREF;

static int RemoteStoragePublishedFileUnsubscribed_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	RemoteStoragePublishedFileUnsubscribed_t *self = (RemoteStoragePublishedFileUnsubscribed_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		luasteam::pushuint64(L, self->m_nPublishedFileId);
		return 1;
	}
	if (strcmp(key, "m_nAppID") == 0) {
		lua_pushinteger(L, self->m_nAppID);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int RemoteStoragePublishedFileUnsubscribed_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	RemoteStoragePublishedFileUnsubscribed_t *self = (RemoteStoragePublishedFileUnsubscribed_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		self->m_nPublishedFileId = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_nAppID") == 0) {
		self->m_nAppID = static_cast<AppId_t>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "RemoteStoragePublishedFileUnsubscribed_t has no field '%%s'", key);
}

EXTERN int luasteam_newRemoteStoragePublishedFileUnsubscribed_t(lua_State *L) {
	RemoteStoragePublishedFileUnsubscribed_t *ptr = (RemoteStoragePublishedFileUnsubscribed_t*)lua_newuserdata(L, sizeof(RemoteStoragePublishedFileUnsubscribed_t));
	new (ptr) RemoteStoragePublishedFileUnsubscribed_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_nPublishedFileId");
		if (!lua_isnil(L, -1)) {
			ptr->m_nPublishedFileId = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nAppID");
		if (!lua_isnil(L, -1)) {
			ptr->m_nAppID = static_cast<AppId_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStoragePublishedFileUnsubscribed_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemoteStoragePublishedFileDeleted_tMetatable_ref = LUA_NOREF;

static int RemoteStoragePublishedFileDeleted_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	RemoteStoragePublishedFileDeleted_t *self = (RemoteStoragePublishedFileDeleted_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		luasteam::pushuint64(L, self->m_nPublishedFileId);
		return 1;
	}
	if (strcmp(key, "m_nAppID") == 0) {
		lua_pushinteger(L, self->m_nAppID);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int RemoteStoragePublishedFileDeleted_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	RemoteStoragePublishedFileDeleted_t *self = (RemoteStoragePublishedFileDeleted_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		self->m_nPublishedFileId = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_nAppID") == 0) {
		self->m_nAppID = static_cast<AppId_t>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "RemoteStoragePublishedFileDeleted_t has no field '%%s'", key);
}

EXTERN int luasteam_newRemoteStoragePublishedFileDeleted_t(lua_State *L) {
	RemoteStoragePublishedFileDeleted_t *ptr = (RemoteStoragePublishedFileDeleted_t*)lua_newuserdata(L, sizeof(RemoteStoragePublishedFileDeleted_t));
	new (ptr) RemoteStoragePublishedFileDeleted_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_nPublishedFileId");
		if (!lua_isnil(L, -1)) {
			ptr->m_nPublishedFileId = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nAppID");
		if (!lua_isnil(L, -1)) {
			ptr->m_nAppID = static_cast<AppId_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStoragePublishedFileDeleted_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemoteStorageUpdateUserPublishedItemVoteResult_tMetatable_ref = LUA_NOREF;

static int RemoteStorageUpdateUserPublishedItemVoteResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageUpdateUserPublishedItemVoteResult_t *self = (RemoteStorageUpdateUserPublishedItemVoteResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		luasteam::pushuint64(L, self->m_nPublishedFileId);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int RemoteStorageUpdateUserPublishedItemVoteResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageUpdateUserPublishedItemVoteResult_t *self = (RemoteStorageUpdateUserPublishedItemVoteResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		self->m_nPublishedFileId = luasteam::checkuint64(L, 3);
		return 0;
	}
	return luaL_error(L, "RemoteStorageUpdateUserPublishedItemVoteResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newRemoteStorageUpdateUserPublishedItemVoteResult_t(lua_State *L) {
	RemoteStorageUpdateUserPublishedItemVoteResult_t *ptr = (RemoteStorageUpdateUserPublishedItemVoteResult_t*)lua_newuserdata(L, sizeof(RemoteStorageUpdateUserPublishedItemVoteResult_t));
	new (ptr) RemoteStorageUpdateUserPublishedItemVoteResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nPublishedFileId");
		if (!lua_isnil(L, -1)) {
			ptr->m_nPublishedFileId = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageUpdateUserPublishedItemVoteResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemoteStorageUserVoteDetails_tMetatable_ref = LUA_NOREF;

static int RemoteStorageUserVoteDetails_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageUserVoteDetails_t *self = (RemoteStorageUserVoteDetails_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		luasteam::pushuint64(L, self->m_nPublishedFileId);
		return 1;
	}
	if (strcmp(key, "m_eVote") == 0) {
		lua_pushinteger(L, self->m_eVote);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int RemoteStorageUserVoteDetails_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageUserVoteDetails_t *self = (RemoteStorageUserVoteDetails_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		self->m_nPublishedFileId = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_eVote") == 0) {
		self->m_eVote = static_cast<EWorkshopVote>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "RemoteStorageUserVoteDetails_t has no field '%%s'", key);
}

EXTERN int luasteam_newRemoteStorageUserVoteDetails_t(lua_State *L) {
	RemoteStorageUserVoteDetails_t *ptr = (RemoteStorageUserVoteDetails_t*)lua_newuserdata(L, sizeof(RemoteStorageUserVoteDetails_t));
	new (ptr) RemoteStorageUserVoteDetails_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nPublishedFileId");
		if (!lua_isnil(L, -1)) {
			ptr->m_nPublishedFileId = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eVote");
		if (!lua_isnil(L, -1)) {
			ptr->m_eVote = static_cast<EWorkshopVote>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageUserVoteDetails_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemoteStorageEnumerateUserSharedWorkshopFilesResult_tMetatable_ref = LUA_NOREF;

static int RemoteStorageEnumerateUserSharedWorkshopFilesResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageEnumerateUserSharedWorkshopFilesResult_t *self = (RemoteStorageEnumerateUserSharedWorkshopFilesResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_nResultsReturned") == 0) {
		lua_pushinteger(L, self->m_nResultsReturned);
		return 1;
	}
	if (strcmp(key, "m_nTotalResultCount") == 0) {
		lua_pushinteger(L, self->m_nTotalResultCount);
		return 1;
	}
	if (strcmp(key, "m_rgPublishedFileId") == 0) {
		lua_createtable(L, 50, 0);
		for(decltype(50) i = 0; i < 50; i++) {
			luasteam::pushuint64(L, self->m_rgPublishedFileId[i]);
			lua_rawseti(L, -2, i+1);
		}
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int RemoteStorageEnumerateUserSharedWorkshopFilesResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageEnumerateUserSharedWorkshopFilesResult_t *self = (RemoteStorageEnumerateUserSharedWorkshopFilesResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nResultsReturned") == 0) {
		self->m_nResultsReturned = static_cast<int32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nTotalResultCount") == 0) {
		self->m_nTotalResultCount = static_cast<int32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_rgPublishedFileId") == 0) {
		luaL_checktype(L, 3, LUA_TTABLE);
		for(decltype(50) i = 0; i < 50; i++) {
			lua_rawgeti(L, 3, i+1);
			self->m_rgPublishedFileId[i] = luasteam::checkuint64(L, -1);
			lua_pop(L, 1);
		}
		return 0;
	}
	return luaL_error(L, "RemoteStorageEnumerateUserSharedWorkshopFilesResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newRemoteStorageEnumerateUserSharedWorkshopFilesResult_t(lua_State *L) {
	RemoteStorageEnumerateUserSharedWorkshopFilesResult_t *ptr = (RemoteStorageEnumerateUserSharedWorkshopFilesResult_t*)lua_newuserdata(L, sizeof(RemoteStorageEnumerateUserSharedWorkshopFilesResult_t));
	new (ptr) RemoteStorageEnumerateUserSharedWorkshopFilesResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nResultsReturned");
		if (!lua_isnil(L, -1)) {
			ptr->m_nResultsReturned = static_cast<int32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nTotalResultCount");
		if (!lua_isnil(L, -1)) {
			ptr->m_nTotalResultCount = static_cast<int32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rgPublishedFileId");
		if (!lua_isnil(L, -1)) {
			luaL_checktype(L, -1, LUA_TTABLE);
			for(decltype(50) i = 0; i < 50; i++) {
				lua_rawgeti(L, -1, i+1);
				ptr->m_rgPublishedFileId[i] = luasteam::checkuint64(L, -1);
				lua_pop(L, 1);
			}
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageEnumerateUserSharedWorkshopFilesResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemoteStorageSetUserPublishedFileActionResult_tMetatable_ref = LUA_NOREF;

static int RemoteStorageSetUserPublishedFileActionResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageSetUserPublishedFileActionResult_t *self = (RemoteStorageSetUserPublishedFileActionResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		luasteam::pushuint64(L, self->m_nPublishedFileId);
		return 1;
	}
	if (strcmp(key, "m_eAction") == 0) {
		lua_pushinteger(L, self->m_eAction);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int RemoteStorageSetUserPublishedFileActionResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageSetUserPublishedFileActionResult_t *self = (RemoteStorageSetUserPublishedFileActionResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		self->m_nPublishedFileId = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_eAction") == 0) {
		self->m_eAction = static_cast<EWorkshopFileAction>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "RemoteStorageSetUserPublishedFileActionResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newRemoteStorageSetUserPublishedFileActionResult_t(lua_State *L) {
	RemoteStorageSetUserPublishedFileActionResult_t *ptr = (RemoteStorageSetUserPublishedFileActionResult_t*)lua_newuserdata(L, sizeof(RemoteStorageSetUserPublishedFileActionResult_t));
	new (ptr) RemoteStorageSetUserPublishedFileActionResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nPublishedFileId");
		if (!lua_isnil(L, -1)) {
			ptr->m_nPublishedFileId = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eAction");
		if (!lua_isnil(L, -1)) {
			ptr->m_eAction = static_cast<EWorkshopFileAction>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageSetUserPublishedFileActionResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemoteStorageEnumeratePublishedFilesByUserActionResult_tMetatable_ref = LUA_NOREF;

static int RemoteStorageEnumeratePublishedFilesByUserActionResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageEnumeratePublishedFilesByUserActionResult_t *self = (RemoteStorageEnumeratePublishedFilesByUserActionResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_eAction") == 0) {
		lua_pushinteger(L, self->m_eAction);
		return 1;
	}
	if (strcmp(key, "m_nResultsReturned") == 0) {
		lua_pushinteger(L, self->m_nResultsReturned);
		return 1;
	}
	if (strcmp(key, "m_nTotalResultCount") == 0) {
		lua_pushinteger(L, self->m_nTotalResultCount);
		return 1;
	}
	if (strcmp(key, "m_rgPublishedFileId") == 0) {
		lua_createtable(L, 50, 0);
		for(decltype(50) i = 0; i < 50; i++) {
			luasteam::pushuint64(L, self->m_rgPublishedFileId[i]);
			lua_rawseti(L, -2, i+1);
		}
		return 1;
	}
	if (strcmp(key, "m_rgRTimeUpdated") == 0) {
		lua_createtable(L, 50, 0);
		for(decltype(50) i = 0; i < 50; i++) {
			lua_pushinteger(L, self->m_rgRTimeUpdated[i]);
			lua_rawseti(L, -2, i+1);
		}
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int RemoteStorageEnumeratePublishedFilesByUserActionResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageEnumeratePublishedFilesByUserActionResult_t *self = (RemoteStorageEnumeratePublishedFilesByUserActionResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_eAction") == 0) {
		self->m_eAction = static_cast<EWorkshopFileAction>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nResultsReturned") == 0) {
		self->m_nResultsReturned = static_cast<int32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nTotalResultCount") == 0) {
		self->m_nTotalResultCount = static_cast<int32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_rgPublishedFileId") == 0) {
		luaL_checktype(L, 3, LUA_TTABLE);
		for(decltype(50) i = 0; i < 50; i++) {
			lua_rawgeti(L, 3, i+1);
			self->m_rgPublishedFileId[i] = luasteam::checkuint64(L, -1);
			lua_pop(L, 1);
		}
		return 0;
	}
	if (strcmp(key, "m_rgRTimeUpdated") == 0) {
		luaL_checktype(L, 3, LUA_TTABLE);
		for(decltype(50) i = 0; i < 50; i++) {
			lua_rawgeti(L, 3, i+1);
			self->m_rgRTimeUpdated[i] = static_cast<int>(luaL_checkint(L, -1));
			lua_pop(L, 1);
		}
		return 0;
	}
	return luaL_error(L, "RemoteStorageEnumeratePublishedFilesByUserActionResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newRemoteStorageEnumeratePublishedFilesByUserActionResult_t(lua_State *L) {
	RemoteStorageEnumeratePublishedFilesByUserActionResult_t *ptr = (RemoteStorageEnumeratePublishedFilesByUserActionResult_t*)lua_newuserdata(L, sizeof(RemoteStorageEnumeratePublishedFilesByUserActionResult_t));
	new (ptr) RemoteStorageEnumeratePublishedFilesByUserActionResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eAction");
		if (!lua_isnil(L, -1)) {
			ptr->m_eAction = static_cast<EWorkshopFileAction>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nResultsReturned");
		if (!lua_isnil(L, -1)) {
			ptr->m_nResultsReturned = static_cast<int32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nTotalResultCount");
		if (!lua_isnil(L, -1)) {
			ptr->m_nTotalResultCount = static_cast<int32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rgPublishedFileId");
		if (!lua_isnil(L, -1)) {
			luaL_checktype(L, -1, LUA_TTABLE);
			for(decltype(50) i = 0; i < 50; i++) {
				lua_rawgeti(L, -1, i+1);
				ptr->m_rgPublishedFileId[i] = luasteam::checkuint64(L, -1);
				lua_pop(L, 1);
			}
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rgRTimeUpdated");
		if (!lua_isnil(L, -1)) {
			luaL_checktype(L, -1, LUA_TTABLE);
			for(decltype(50) i = 0; i < 50; i++) {
				lua_rawgeti(L, -1, i+1);
				ptr->m_rgRTimeUpdated[i] = static_cast<int>(luaL_checkint(L, -1));
				lua_pop(L, 1);
			}
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageEnumeratePublishedFilesByUserActionResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemoteStoragePublishFileProgress_tMetatable_ref = LUA_NOREF;

static int RemoteStoragePublishFileProgress_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	RemoteStoragePublishFileProgress_t *self = (RemoteStoragePublishFileProgress_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_dPercentFile") == 0) {
		lua_pushnumber(L, self->m_dPercentFile);
		return 1;
	}
	if (strcmp(key, "m_bPreview") == 0) {
		lua_pushboolean(L, self->m_bPreview);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int RemoteStoragePublishFileProgress_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	RemoteStoragePublishFileProgress_t *self = (RemoteStoragePublishFileProgress_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_dPercentFile") == 0) {
		self->m_dPercentFile = static_cast<double>(luaL_checknumber(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bPreview") == 0) {
		self->m_bPreview = lua_toboolean(L, 3);
		return 0;
	}
	return luaL_error(L, "RemoteStoragePublishFileProgress_t has no field '%%s'", key);
}

EXTERN int luasteam_newRemoteStoragePublishFileProgress_t(lua_State *L) {
	RemoteStoragePublishFileProgress_t *ptr = (RemoteStoragePublishFileProgress_t*)lua_newuserdata(L, sizeof(RemoteStoragePublishFileProgress_t));
	new (ptr) RemoteStoragePublishFileProgress_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_dPercentFile");
		if (!lua_isnil(L, -1)) {
			ptr->m_dPercentFile = static_cast<double>(luaL_checknumber(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bPreview");
		if (!lua_isnil(L, -1)) {
			ptr->m_bPreview = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStoragePublishFileProgress_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemoteStoragePublishedFileUpdated_tMetatable_ref = LUA_NOREF;

static int RemoteStoragePublishedFileUpdated_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	RemoteStoragePublishedFileUpdated_t *self = (RemoteStoragePublishedFileUpdated_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		luasteam::pushuint64(L, self->m_nPublishedFileId);
		return 1;
	}
	if (strcmp(key, "m_nAppID") == 0) {
		lua_pushinteger(L, self->m_nAppID);
		return 1;
	}
	if (strcmp(key, "m_ulUnused") == 0) {
		luasteam::pushuint64(L, self->m_ulUnused);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int RemoteStoragePublishedFileUpdated_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	RemoteStoragePublishedFileUpdated_t *self = (RemoteStoragePublishedFileUpdated_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		self->m_nPublishedFileId = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_nAppID") == 0) {
		self->m_nAppID = static_cast<AppId_t>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_ulUnused") == 0) {
		self->m_ulUnused = luasteam::checkuint64(L, 3);
		return 0;
	}
	return luaL_error(L, "RemoteStoragePublishedFileUpdated_t has no field '%%s'", key);
}

EXTERN int luasteam_newRemoteStoragePublishedFileUpdated_t(lua_State *L) {
	RemoteStoragePublishedFileUpdated_t *ptr = (RemoteStoragePublishedFileUpdated_t*)lua_newuserdata(L, sizeof(RemoteStoragePublishedFileUpdated_t));
	new (ptr) RemoteStoragePublishedFileUpdated_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_nPublishedFileId");
		if (!lua_isnil(L, -1)) {
			ptr->m_nPublishedFileId = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nAppID");
		if (!lua_isnil(L, -1)) {
			ptr->m_nAppID = static_cast<AppId_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_ulUnused");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulUnused = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStoragePublishedFileUpdated_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemoteStorageFileWriteAsyncComplete_tMetatable_ref = LUA_NOREF;

static int RemoteStorageFileWriteAsyncComplete_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageFileWriteAsyncComplete_t *self = (RemoteStorageFileWriteAsyncComplete_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int RemoteStorageFileWriteAsyncComplete_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageFileWriteAsyncComplete_t *self = (RemoteStorageFileWriteAsyncComplete_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "RemoteStorageFileWriteAsyncComplete_t has no field '%%s'", key);
}

EXTERN int luasteam_newRemoteStorageFileWriteAsyncComplete_t(lua_State *L) {
	RemoteStorageFileWriteAsyncComplete_t *ptr = (RemoteStorageFileWriteAsyncComplete_t*)lua_newuserdata(L, sizeof(RemoteStorageFileWriteAsyncComplete_t));
	new (ptr) RemoteStorageFileWriteAsyncComplete_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageFileWriteAsyncComplete_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemoteStorageFileReadAsyncComplete_tMetatable_ref = LUA_NOREF;

static int RemoteStorageFileReadAsyncComplete_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageFileReadAsyncComplete_t *self = (RemoteStorageFileReadAsyncComplete_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_hFileReadAsync") == 0) {
		luasteam::pushuint64(L, self->m_hFileReadAsync);
		return 1;
	}
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_nOffset") == 0) {
		lua_pushinteger(L, self->m_nOffset);
		return 1;
	}
	if (strcmp(key, "m_cubRead") == 0) {
		lua_pushinteger(L, self->m_cubRead);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int RemoteStorageFileReadAsyncComplete_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	RemoteStorageFileReadAsyncComplete_t *self = (RemoteStorageFileReadAsyncComplete_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_hFileReadAsync") == 0) {
		self->m_hFileReadAsync = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nOffset") == 0) {
		self->m_nOffset = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_cubRead") == 0) {
		self->m_cubRead = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "RemoteStorageFileReadAsyncComplete_t has no field '%%s'", key);
}

EXTERN int luasteam_newRemoteStorageFileReadAsyncComplete_t(lua_State *L) {
	RemoteStorageFileReadAsyncComplete_t *ptr = (RemoteStorageFileReadAsyncComplete_t*)lua_newuserdata(L, sizeof(RemoteStorageFileReadAsyncComplete_t));
	new (ptr) RemoteStorageFileReadAsyncComplete_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_hFileReadAsync");
		if (!lua_isnil(L, -1)) {
			ptr->m_hFileReadAsync = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nOffset");
		if (!lua_isnil(L, -1)) {
			ptr->m_nOffset = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_cubRead");
		if (!lua_isnil(L, -1)) {
			ptr->m_cubRead = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageFileReadAsyncComplete_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemoteStorageLocalFileChange_tMetatable_ref = LUA_NOREF;

static int RemoteStorageLocalFileChange_t_index(lua_State *L) {
	lua_pushnil(L);
	return 1;
}

EXTERN int luasteam_newRemoteStorageLocalFileChange_t(lua_State *L) {
	RemoteStorageLocalFileChange_t *ptr = (RemoteStorageLocalFileChange_t*)lua_newuserdata(L, sizeof(RemoteStorageLocalFileChange_t));
	new (ptr) RemoteStorageLocalFileChange_t();
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageLocalFileChange_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int UserStatsReceived_tMetatable_ref = LUA_NOREF;

static int UserStatsReceived_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	UserStatsReceived_t *self = (UserStatsReceived_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nGameID") == 0) {
		luasteam::pushuint64(L, self->m_nGameID);
		return 1;
	}
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_steamIDUser") == 0) {
		luasteam::pushuint64(L, self->m_steamIDUser.ConvertToUint64());
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int UserStatsReceived_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	UserStatsReceived_t *self = (UserStatsReceived_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nGameID") == 0) {
		self->m_nGameID = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_steamIDUser") == 0) {
		self->m_steamIDUser = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	return luaL_error(L, "UserStatsReceived_t has no field '%%s'", key);
}

EXTERN int luasteam_newUserStatsReceived_t(lua_State *L) {
	UserStatsReceived_t *ptr = (UserStatsReceived_t*)lua_newuserdata(L, sizeof(UserStatsReceived_t));
	new (ptr) UserStatsReceived_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_nGameID");
		if (!lua_isnil(L, -1)) {
			ptr->m_nGameID = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_steamIDUser");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamIDUser = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, UserStatsReceived_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int UserStatsStored_tMetatable_ref = LUA_NOREF;

static int UserStatsStored_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	UserStatsStored_t *self = (UserStatsStored_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nGameID") == 0) {
		luasteam::pushuint64(L, self->m_nGameID);
		return 1;
	}
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int UserStatsStored_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	UserStatsStored_t *self = (UserStatsStored_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nGameID") == 0) {
		self->m_nGameID = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "UserStatsStored_t has no field '%%s'", key);
}

EXTERN int luasteam_newUserStatsStored_t(lua_State *L) {
	UserStatsStored_t *ptr = (UserStatsStored_t*)lua_newuserdata(L, sizeof(UserStatsStored_t));
	new (ptr) UserStatsStored_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_nGameID");
		if (!lua_isnil(L, -1)) {
			ptr->m_nGameID = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, UserStatsStored_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int UserAchievementStored_tMetatable_ref = LUA_NOREF;

static int UserAchievementStored_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	UserAchievementStored_t *self = (UserAchievementStored_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nGameID") == 0) {
		luasteam::pushuint64(L, self->m_nGameID);
		return 1;
	}
	if (strcmp(key, "m_bGroupAchievement") == 0) {
		lua_pushboolean(L, self->m_bGroupAchievement);
		return 1;
	}
	if (strcmp(key, "m_rgchAchievementName") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_rgchAchievementName), 128);
		return 1;
	}
	if (strcmp(key, "m_nCurProgress") == 0) {
		lua_pushinteger(L, self->m_nCurProgress);
		return 1;
	}
	if (strcmp(key, "m_nMaxProgress") == 0) {
		lua_pushinteger(L, self->m_nMaxProgress);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int UserAchievementStored_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	UserAchievementStored_t *self = (UserAchievementStored_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nGameID") == 0) {
		self->m_nGameID = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_bGroupAchievement") == 0) {
		self->m_bGroupAchievement = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_rgchAchievementName") == 0) {
		size_t _len__tmp64;
		const char *_tmp64 = luaL_checklstring(L, 3, &_len__tmp64);
		if (_len__tmp64 > sizeof(self->m_rgchAchievementName)) luaL_error(L, "String too long");
		memcpy(self->m_rgchAchievementName, _tmp64, std::min(_len__tmp64 + 1, sizeof(self->m_rgchAchievementName)));
		return 0;
	}
	if (strcmp(key, "m_nCurProgress") == 0) {
		self->m_nCurProgress = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nMaxProgress") == 0) {
		self->m_nMaxProgress = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "UserAchievementStored_t has no field '%%s'", key);
}

EXTERN int luasteam_newUserAchievementStored_t(lua_State *L) {
	UserAchievementStored_t *ptr = (UserAchievementStored_t*)lua_newuserdata(L, sizeof(UserAchievementStored_t));
	new (ptr) UserAchievementStored_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_nGameID");
		if (!lua_isnil(L, -1)) {
			ptr->m_nGameID = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bGroupAchievement");
		if (!lua_isnil(L, -1)) {
			ptr->m_bGroupAchievement = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rgchAchievementName");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp65;
			const char *_tmp65 = luaL_checklstring(L, -1, &_len__tmp65);
			if (_len__tmp65 > sizeof(ptr->m_rgchAchievementName)) luaL_error(L, "String too long");
			memcpy(ptr->m_rgchAchievementName, _tmp65, std::min(_len__tmp65 + 1, sizeof(ptr->m_rgchAchievementName)));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nCurProgress");
		if (!lua_isnil(L, -1)) {
			ptr->m_nCurProgress = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nMaxProgress");
		if (!lua_isnil(L, -1)) {
			ptr->m_nMaxProgress = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, UserAchievementStored_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int LeaderboardFindResult_tMetatable_ref = LUA_NOREF;

static int LeaderboardFindResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	LeaderboardFindResult_t *self = (LeaderboardFindResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_hSteamLeaderboard") == 0) {
		luasteam::pushuint64(L, self->m_hSteamLeaderboard);
		return 1;
	}
	if (strcmp(key, "m_bLeaderboardFound") == 0) {
		lua_pushinteger(L, self->m_bLeaderboardFound);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int LeaderboardFindResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	LeaderboardFindResult_t *self = (LeaderboardFindResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_hSteamLeaderboard") == 0) {
		self->m_hSteamLeaderboard = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_bLeaderboardFound") == 0) {
		self->m_bLeaderboardFound = static_cast<uint8>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "LeaderboardFindResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newLeaderboardFindResult_t(lua_State *L) {
	LeaderboardFindResult_t *ptr = (LeaderboardFindResult_t*)lua_newuserdata(L, sizeof(LeaderboardFindResult_t));
	new (ptr) LeaderboardFindResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_hSteamLeaderboard");
		if (!lua_isnil(L, -1)) {
			ptr->m_hSteamLeaderboard = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bLeaderboardFound");
		if (!lua_isnil(L, -1)) {
			ptr->m_bLeaderboardFound = static_cast<uint8>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, LeaderboardFindResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int LeaderboardScoresDownloaded_tMetatable_ref = LUA_NOREF;

static int LeaderboardScoresDownloaded_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	LeaderboardScoresDownloaded_t *self = (LeaderboardScoresDownloaded_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_hSteamLeaderboard") == 0) {
		luasteam::pushuint64(L, self->m_hSteamLeaderboard);
		return 1;
	}
	if (strcmp(key, "m_hSteamLeaderboardEntries") == 0) {
		luasteam::pushuint64(L, self->m_hSteamLeaderboardEntries);
		return 1;
	}
	if (strcmp(key, "m_cEntryCount") == 0) {
		lua_pushinteger(L, self->m_cEntryCount);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int LeaderboardScoresDownloaded_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	LeaderboardScoresDownloaded_t *self = (LeaderboardScoresDownloaded_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_hSteamLeaderboard") == 0) {
		self->m_hSteamLeaderboard = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_hSteamLeaderboardEntries") == 0) {
		self->m_hSteamLeaderboardEntries = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_cEntryCount") == 0) {
		self->m_cEntryCount = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "LeaderboardScoresDownloaded_t has no field '%%s'", key);
}

EXTERN int luasteam_newLeaderboardScoresDownloaded_t(lua_State *L) {
	LeaderboardScoresDownloaded_t *ptr = (LeaderboardScoresDownloaded_t*)lua_newuserdata(L, sizeof(LeaderboardScoresDownloaded_t));
	new (ptr) LeaderboardScoresDownloaded_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_hSteamLeaderboard");
		if (!lua_isnil(L, -1)) {
			ptr->m_hSteamLeaderboard = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_hSteamLeaderboardEntries");
		if (!lua_isnil(L, -1)) {
			ptr->m_hSteamLeaderboardEntries = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_cEntryCount");
		if (!lua_isnil(L, -1)) {
			ptr->m_cEntryCount = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, LeaderboardScoresDownloaded_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int LeaderboardScoreUploaded_tMetatable_ref = LUA_NOREF;

static int LeaderboardScoreUploaded_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	LeaderboardScoreUploaded_t *self = (LeaderboardScoreUploaded_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_bSuccess") == 0) {
		lua_pushinteger(L, self->m_bSuccess);
		return 1;
	}
	if (strcmp(key, "m_hSteamLeaderboard") == 0) {
		luasteam::pushuint64(L, self->m_hSteamLeaderboard);
		return 1;
	}
	if (strcmp(key, "m_nScore") == 0) {
		lua_pushinteger(L, self->m_nScore);
		return 1;
	}
	if (strcmp(key, "m_bScoreChanged") == 0) {
		lua_pushinteger(L, self->m_bScoreChanged);
		return 1;
	}
	if (strcmp(key, "m_nGlobalRankNew") == 0) {
		lua_pushinteger(L, self->m_nGlobalRankNew);
		return 1;
	}
	if (strcmp(key, "m_nGlobalRankPrevious") == 0) {
		lua_pushinteger(L, self->m_nGlobalRankPrevious);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int LeaderboardScoreUploaded_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	LeaderboardScoreUploaded_t *self = (LeaderboardScoreUploaded_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_bSuccess") == 0) {
		self->m_bSuccess = static_cast<uint8>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_hSteamLeaderboard") == 0) {
		self->m_hSteamLeaderboard = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_nScore") == 0) {
		self->m_nScore = static_cast<int32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bScoreChanged") == 0) {
		self->m_bScoreChanged = static_cast<uint8>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nGlobalRankNew") == 0) {
		self->m_nGlobalRankNew = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nGlobalRankPrevious") == 0) {
		self->m_nGlobalRankPrevious = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "LeaderboardScoreUploaded_t has no field '%%s'", key);
}

EXTERN int luasteam_newLeaderboardScoreUploaded_t(lua_State *L) {
	LeaderboardScoreUploaded_t *ptr = (LeaderboardScoreUploaded_t*)lua_newuserdata(L, sizeof(LeaderboardScoreUploaded_t));
	new (ptr) LeaderboardScoreUploaded_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_bSuccess");
		if (!lua_isnil(L, -1)) {
			ptr->m_bSuccess = static_cast<uint8>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_hSteamLeaderboard");
		if (!lua_isnil(L, -1)) {
			ptr->m_hSteamLeaderboard = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nScore");
		if (!lua_isnil(L, -1)) {
			ptr->m_nScore = static_cast<int32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bScoreChanged");
		if (!lua_isnil(L, -1)) {
			ptr->m_bScoreChanged = static_cast<uint8>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nGlobalRankNew");
		if (!lua_isnil(L, -1)) {
			ptr->m_nGlobalRankNew = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nGlobalRankPrevious");
		if (!lua_isnil(L, -1)) {
			ptr->m_nGlobalRankPrevious = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, LeaderboardScoreUploaded_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int NumberOfCurrentPlayers_tMetatable_ref = LUA_NOREF;

static int NumberOfCurrentPlayers_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	NumberOfCurrentPlayers_t *self = (NumberOfCurrentPlayers_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_bSuccess") == 0) {
		lua_pushinteger(L, self->m_bSuccess);
		return 1;
	}
	if (strcmp(key, "m_cPlayers") == 0) {
		lua_pushinteger(L, self->m_cPlayers);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int NumberOfCurrentPlayers_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	NumberOfCurrentPlayers_t *self = (NumberOfCurrentPlayers_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_bSuccess") == 0) {
		self->m_bSuccess = static_cast<uint8>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_cPlayers") == 0) {
		self->m_cPlayers = static_cast<int32>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "NumberOfCurrentPlayers_t has no field '%%s'", key);
}

EXTERN int luasteam_newNumberOfCurrentPlayers_t(lua_State *L) {
	NumberOfCurrentPlayers_t *ptr = (NumberOfCurrentPlayers_t*)lua_newuserdata(L, sizeof(NumberOfCurrentPlayers_t));
	new (ptr) NumberOfCurrentPlayers_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_bSuccess");
		if (!lua_isnil(L, -1)) {
			ptr->m_bSuccess = static_cast<uint8>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_cPlayers");
		if (!lua_isnil(L, -1)) {
			ptr->m_cPlayers = static_cast<int32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, NumberOfCurrentPlayers_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int UserStatsUnloaded_tMetatable_ref = LUA_NOREF;

static int UserStatsUnloaded_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	UserStatsUnloaded_t *self = (UserStatsUnloaded_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamIDUser") == 0) {
		luasteam::pushuint64(L, self->m_steamIDUser.ConvertToUint64());
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int UserStatsUnloaded_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	UserStatsUnloaded_t *self = (UserStatsUnloaded_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamIDUser") == 0) {
		self->m_steamIDUser = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	return luaL_error(L, "UserStatsUnloaded_t has no field '%%s'", key);
}

EXTERN int luasteam_newUserStatsUnloaded_t(lua_State *L) {
	UserStatsUnloaded_t *ptr = (UserStatsUnloaded_t*)lua_newuserdata(L, sizeof(UserStatsUnloaded_t));
	new (ptr) UserStatsUnloaded_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_steamIDUser");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamIDUser = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, UserStatsUnloaded_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int UserAchievementIconFetched_tMetatable_ref = LUA_NOREF;

static int UserAchievementIconFetched_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	UserAchievementIconFetched_t *self = (UserAchievementIconFetched_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nGameID") == 0) {
		luasteam::pushuint64(L, self->m_nGameID.ToUint64());
		return 1;
	}
	if (strcmp(key, "m_rgchAchievementName") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_rgchAchievementName), 128);
		return 1;
	}
	if (strcmp(key, "m_bAchieved") == 0) {
		lua_pushboolean(L, self->m_bAchieved);
		return 1;
	}
	if (strcmp(key, "m_nIconHandle") == 0) {
		lua_pushinteger(L, self->m_nIconHandle);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int UserAchievementIconFetched_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	UserAchievementIconFetched_t *self = (UserAchievementIconFetched_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nGameID") == 0) {
		self->m_nGameID = CGameID(luasteam::checkuint64(L, 3));
		return 0;
	}
	if (strcmp(key, "m_rgchAchievementName") == 0) {
		size_t _len__tmp66;
		const char *_tmp66 = luaL_checklstring(L, 3, &_len__tmp66);
		if (_len__tmp66 > sizeof(self->m_rgchAchievementName)) luaL_error(L, "String too long");
		memcpy(self->m_rgchAchievementName, _tmp66, std::min(_len__tmp66 + 1, sizeof(self->m_rgchAchievementName)));
		return 0;
	}
	if (strcmp(key, "m_bAchieved") == 0) {
		self->m_bAchieved = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_nIconHandle") == 0) {
		self->m_nIconHandle = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "UserAchievementIconFetched_t has no field '%%s'", key);
}

EXTERN int luasteam_newUserAchievementIconFetched_t(lua_State *L) {
	UserAchievementIconFetched_t *ptr = (UserAchievementIconFetched_t*)lua_newuserdata(L, sizeof(UserAchievementIconFetched_t));
	new (ptr) UserAchievementIconFetched_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_nGameID");
		if (!lua_isnil(L, -1)) {
			ptr->m_nGameID = CGameID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rgchAchievementName");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp67;
			const char *_tmp67 = luaL_checklstring(L, -1, &_len__tmp67);
			if (_len__tmp67 > sizeof(ptr->m_rgchAchievementName)) luaL_error(L, "String too long");
			memcpy(ptr->m_rgchAchievementName, _tmp67, std::min(_len__tmp67 + 1, sizeof(ptr->m_rgchAchievementName)));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bAchieved");
		if (!lua_isnil(L, -1)) {
			ptr->m_bAchieved = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nIconHandle");
		if (!lua_isnil(L, -1)) {
			ptr->m_nIconHandle = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, UserAchievementIconFetched_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int GlobalAchievementPercentagesReady_tMetatable_ref = LUA_NOREF;

static int GlobalAchievementPercentagesReady_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	GlobalAchievementPercentagesReady_t *self = (GlobalAchievementPercentagesReady_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nGameID") == 0) {
		luasteam::pushuint64(L, self->m_nGameID);
		return 1;
	}
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int GlobalAchievementPercentagesReady_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	GlobalAchievementPercentagesReady_t *self = (GlobalAchievementPercentagesReady_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nGameID") == 0) {
		self->m_nGameID = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "GlobalAchievementPercentagesReady_t has no field '%%s'", key);
}

EXTERN int luasteam_newGlobalAchievementPercentagesReady_t(lua_State *L) {
	GlobalAchievementPercentagesReady_t *ptr = (GlobalAchievementPercentagesReady_t*)lua_newuserdata(L, sizeof(GlobalAchievementPercentagesReady_t));
	new (ptr) GlobalAchievementPercentagesReady_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_nGameID");
		if (!lua_isnil(L, -1)) {
			ptr->m_nGameID = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, GlobalAchievementPercentagesReady_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int LeaderboardUGCSet_tMetatable_ref = LUA_NOREF;

static int LeaderboardUGCSet_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	LeaderboardUGCSet_t *self = (LeaderboardUGCSet_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_hSteamLeaderboard") == 0) {
		luasteam::pushuint64(L, self->m_hSteamLeaderboard);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int LeaderboardUGCSet_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	LeaderboardUGCSet_t *self = (LeaderboardUGCSet_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_hSteamLeaderboard") == 0) {
		self->m_hSteamLeaderboard = luasteam::checkuint64(L, 3);
		return 0;
	}
	return luaL_error(L, "LeaderboardUGCSet_t has no field '%%s'", key);
}

EXTERN int luasteam_newLeaderboardUGCSet_t(lua_State *L) {
	LeaderboardUGCSet_t *ptr = (LeaderboardUGCSet_t*)lua_newuserdata(L, sizeof(LeaderboardUGCSet_t));
	new (ptr) LeaderboardUGCSet_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_hSteamLeaderboard");
		if (!lua_isnil(L, -1)) {
			ptr->m_hSteamLeaderboard = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, LeaderboardUGCSet_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int GlobalStatsReceived_tMetatable_ref = LUA_NOREF;

static int GlobalStatsReceived_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	GlobalStatsReceived_t *self = (GlobalStatsReceived_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nGameID") == 0) {
		luasteam::pushuint64(L, self->m_nGameID);
		return 1;
	}
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int GlobalStatsReceived_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	GlobalStatsReceived_t *self = (GlobalStatsReceived_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nGameID") == 0) {
		self->m_nGameID = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "GlobalStatsReceived_t has no field '%%s'", key);
}

EXTERN int luasteam_newGlobalStatsReceived_t(lua_State *L) {
	GlobalStatsReceived_t *ptr = (GlobalStatsReceived_t*)lua_newuserdata(L, sizeof(GlobalStatsReceived_t));
	new (ptr) GlobalStatsReceived_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_nGameID");
		if (!lua_isnil(L, -1)) {
			ptr->m_nGameID = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, GlobalStatsReceived_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int DlcInstalled_tMetatable_ref = LUA_NOREF;

static int DlcInstalled_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	DlcInstalled_t *self = (DlcInstalled_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nAppID") == 0) {
		lua_pushinteger(L, self->m_nAppID);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int DlcInstalled_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	DlcInstalled_t *self = (DlcInstalled_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nAppID") == 0) {
		self->m_nAppID = static_cast<AppId_t>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "DlcInstalled_t has no field '%%s'", key);
}

EXTERN int luasteam_newDlcInstalled_t(lua_State *L) {
	DlcInstalled_t *ptr = (DlcInstalled_t*)lua_newuserdata(L, sizeof(DlcInstalled_t));
	new (ptr) DlcInstalled_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_nAppID");
		if (!lua_isnil(L, -1)) {
			ptr->m_nAppID = static_cast<AppId_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, DlcInstalled_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int NewUrlLaunchParameters_tMetatable_ref = LUA_NOREF;

static int NewUrlLaunchParameters_t_index(lua_State *L) {
	lua_pushnil(L);
	return 1;
}

EXTERN int luasteam_newNewUrlLaunchParameters_t(lua_State *L) {
	NewUrlLaunchParameters_t *ptr = (NewUrlLaunchParameters_t*)lua_newuserdata(L, sizeof(NewUrlLaunchParameters_t));
	new (ptr) NewUrlLaunchParameters_t();
	lua_rawgeti(L, LUA_REGISTRYINDEX, NewUrlLaunchParameters_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int AppProofOfPurchaseKeyResponse_tMetatable_ref = LUA_NOREF;

static int AppProofOfPurchaseKeyResponse_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	AppProofOfPurchaseKeyResponse_t *self = (AppProofOfPurchaseKeyResponse_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_nAppID") == 0) {
		lua_pushinteger(L, self->m_nAppID);
		return 1;
	}
	if (strcmp(key, "m_cchKeyLength") == 0) {
		lua_pushinteger(L, self->m_cchKeyLength);
		return 1;
	}
	if (strcmp(key, "m_rgchKey") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_rgchKey), 240);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int AppProofOfPurchaseKeyResponse_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	AppProofOfPurchaseKeyResponse_t *self = (AppProofOfPurchaseKeyResponse_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nAppID") == 0) {
		self->m_nAppID = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_cchKeyLength") == 0) {
		self->m_cchKeyLength = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_rgchKey") == 0) {
		size_t _len__tmp68;
		const char *_tmp68 = luaL_checklstring(L, 3, &_len__tmp68);
		if (_len__tmp68 > sizeof(self->m_rgchKey)) luaL_error(L, "String too long");
		memcpy(self->m_rgchKey, _tmp68, std::min(_len__tmp68 + 1, sizeof(self->m_rgchKey)));
		return 0;
	}
	return luaL_error(L, "AppProofOfPurchaseKeyResponse_t has no field '%%s'", key);
}

EXTERN int luasteam_newAppProofOfPurchaseKeyResponse_t(lua_State *L) {
	AppProofOfPurchaseKeyResponse_t *ptr = (AppProofOfPurchaseKeyResponse_t*)lua_newuserdata(L, sizeof(AppProofOfPurchaseKeyResponse_t));
	new (ptr) AppProofOfPurchaseKeyResponse_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nAppID");
		if (!lua_isnil(L, -1)) {
			ptr->m_nAppID = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_cchKeyLength");
		if (!lua_isnil(L, -1)) {
			ptr->m_cchKeyLength = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rgchKey");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp69;
			const char *_tmp69 = luaL_checklstring(L, -1, &_len__tmp69);
			if (_len__tmp69 > sizeof(ptr->m_rgchKey)) luaL_error(L, "String too long");
			memcpy(ptr->m_rgchKey, _tmp69, std::min(_len__tmp69 + 1, sizeof(ptr->m_rgchKey)));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, AppProofOfPurchaseKeyResponse_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int FileDetailsResult_tMetatable_ref = LUA_NOREF;

static int FileDetailsResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	FileDetailsResult_t *self = (FileDetailsResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_ulFileSize") == 0) {
		luasteam::pushuint64(L, self->m_ulFileSize);
		return 1;
	}
	if (strcmp(key, "m_FileSHA") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_FileSHA), 20);
		return 1;
	}
	if (strcmp(key, "m_unFlags") == 0) {
		lua_pushinteger(L, self->m_unFlags);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int FileDetailsResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	FileDetailsResult_t *self = (FileDetailsResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_ulFileSize") == 0) {
		self->m_ulFileSize = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_FileSHA") == 0) {
		size_t _len__tmp70;
		const char *_tmp70 = luaL_checklstring(L, 3, &_len__tmp70);
		if (_len__tmp70 > sizeof(self->m_FileSHA)) luaL_error(L, "String too long");
		memcpy(self->m_FileSHA, _tmp70, std::min(_len__tmp70 + 1, sizeof(self->m_FileSHA)));
		return 0;
	}
	if (strcmp(key, "m_unFlags") == 0) {
		self->m_unFlags = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "FileDetailsResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newFileDetailsResult_t(lua_State *L) {
	FileDetailsResult_t *ptr = (FileDetailsResult_t*)lua_newuserdata(L, sizeof(FileDetailsResult_t));
	new (ptr) FileDetailsResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_ulFileSize");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulFileSize = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_FileSHA");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp71;
			const char *_tmp71 = luaL_checklstring(L, -1, &_len__tmp71);
			if (_len__tmp71 > sizeof(ptr->m_FileSHA)) luaL_error(L, "String too long");
			memcpy(ptr->m_FileSHA, _tmp71, std::min(_len__tmp71 + 1, sizeof(ptr->m_FileSHA)));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unFlags");
		if (!lua_isnil(L, -1)) {
			ptr->m_unFlags = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, FileDetailsResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int TimedTrialStatus_tMetatable_ref = LUA_NOREF;

static int TimedTrialStatus_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	TimedTrialStatus_t *self = (TimedTrialStatus_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_unAppID") == 0) {
		lua_pushinteger(L, self->m_unAppID);
		return 1;
	}
	if (strcmp(key, "m_bIsOffline") == 0) {
		lua_pushboolean(L, self->m_bIsOffline);
		return 1;
	}
	if (strcmp(key, "m_unSecondsAllowed") == 0) {
		lua_pushinteger(L, self->m_unSecondsAllowed);
		return 1;
	}
	if (strcmp(key, "m_unSecondsPlayed") == 0) {
		lua_pushinteger(L, self->m_unSecondsPlayed);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int TimedTrialStatus_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	TimedTrialStatus_t *self = (TimedTrialStatus_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_unAppID") == 0) {
		self->m_unAppID = static_cast<AppId_t>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bIsOffline") == 0) {
		self->m_bIsOffline = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_unSecondsAllowed") == 0) {
		self->m_unSecondsAllowed = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_unSecondsPlayed") == 0) {
		self->m_unSecondsPlayed = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "TimedTrialStatus_t has no field '%%s'", key);
}

EXTERN int luasteam_newTimedTrialStatus_t(lua_State *L) {
	TimedTrialStatus_t *ptr = (TimedTrialStatus_t*)lua_newuserdata(L, sizeof(TimedTrialStatus_t));
	new (ptr) TimedTrialStatus_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_unAppID");
		if (!lua_isnil(L, -1)) {
			ptr->m_unAppID = static_cast<AppId_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bIsOffline");
		if (!lua_isnil(L, -1)) {
			ptr->m_bIsOffline = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unSecondsAllowed");
		if (!lua_isnil(L, -1)) {
			ptr->m_unSecondsAllowed = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unSecondsPlayed");
		if (!lua_isnil(L, -1)) {
			ptr->m_unSecondsPlayed = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, TimedTrialStatus_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int P2PSessionRequest_tMetatable_ref = LUA_NOREF;

static int P2PSessionRequest_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	P2PSessionRequest_t *self = (P2PSessionRequest_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamIDRemote") == 0) {
		luasteam::pushuint64(L, self->m_steamIDRemote.ConvertToUint64());
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int P2PSessionRequest_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	P2PSessionRequest_t *self = (P2PSessionRequest_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamIDRemote") == 0) {
		self->m_steamIDRemote = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	return luaL_error(L, "P2PSessionRequest_t has no field '%%s'", key);
}

EXTERN int luasteam_newP2PSessionRequest_t(lua_State *L) {
	P2PSessionRequest_t *ptr = (P2PSessionRequest_t*)lua_newuserdata(L, sizeof(P2PSessionRequest_t));
	new (ptr) P2PSessionRequest_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_steamIDRemote");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamIDRemote = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, P2PSessionRequest_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int P2PSessionConnectFail_tMetatable_ref = LUA_NOREF;

static int P2PSessionConnectFail_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	P2PSessionConnectFail_t *self = (P2PSessionConnectFail_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamIDRemote") == 0) {
		luasteam::pushuint64(L, self->m_steamIDRemote.ConvertToUint64());
		return 1;
	}
	if (strcmp(key, "m_eP2PSessionError") == 0) {
		lua_pushinteger(L, self->m_eP2PSessionError);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int P2PSessionConnectFail_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	P2PSessionConnectFail_t *self = (P2PSessionConnectFail_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamIDRemote") == 0) {
		self->m_steamIDRemote = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	if (strcmp(key, "m_eP2PSessionError") == 0) {
		self->m_eP2PSessionError = static_cast<uint8>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "P2PSessionConnectFail_t has no field '%%s'", key);
}

EXTERN int luasteam_newP2PSessionConnectFail_t(lua_State *L) {
	P2PSessionConnectFail_t *ptr = (P2PSessionConnectFail_t*)lua_newuserdata(L, sizeof(P2PSessionConnectFail_t));
	new (ptr) P2PSessionConnectFail_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_steamIDRemote");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamIDRemote = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eP2PSessionError");
		if (!lua_isnil(L, -1)) {
			ptr->m_eP2PSessionError = static_cast<uint8>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, P2PSessionConnectFail_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SocketStatusCallback_tMetatable_ref = LUA_NOREF;

static int SocketStatusCallback_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SocketStatusCallback_t *self = (SocketStatusCallback_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_hSocket") == 0) {
		lua_pushinteger(L, self->m_hSocket);
		return 1;
	}
	if (strcmp(key, "m_hListenSocket") == 0) {
		lua_pushinteger(L, self->m_hListenSocket);
		return 1;
	}
	if (strcmp(key, "m_steamIDRemote") == 0) {
		luasteam::pushuint64(L, self->m_steamIDRemote.ConvertToUint64());
		return 1;
	}
	if (strcmp(key, "m_eSNetSocketState") == 0) {
		lua_pushinteger(L, self->m_eSNetSocketState);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SocketStatusCallback_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SocketStatusCallback_t *self = (SocketStatusCallback_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_hSocket") == 0) {
		self->m_hSocket = static_cast<SNetSocket_t>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_hListenSocket") == 0) {
		self->m_hListenSocket = static_cast<SNetListenSocket_t>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_steamIDRemote") == 0) {
		self->m_steamIDRemote = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	if (strcmp(key, "m_eSNetSocketState") == 0) {
		self->m_eSNetSocketState = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "SocketStatusCallback_t has no field '%%s'", key);
}

EXTERN int luasteam_newSocketStatusCallback_t(lua_State *L) {
	SocketStatusCallback_t *ptr = (SocketStatusCallback_t*)lua_newuserdata(L, sizeof(SocketStatusCallback_t));
	new (ptr) SocketStatusCallback_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_hSocket");
		if (!lua_isnil(L, -1)) {
			ptr->m_hSocket = static_cast<SNetSocket_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_hListenSocket");
		if (!lua_isnil(L, -1)) {
			ptr->m_hListenSocket = static_cast<SNetListenSocket_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_steamIDRemote");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamIDRemote = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eSNetSocketState");
		if (!lua_isnil(L, -1)) {
			ptr->m_eSNetSocketState = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SocketStatusCallback_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int ScreenshotReady_tMetatable_ref = LUA_NOREF;

static int ScreenshotReady_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	ScreenshotReady_t *self = (ScreenshotReady_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_hLocal") == 0) {
		lua_pushinteger(L, self->m_hLocal);
		return 1;
	}
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int ScreenshotReady_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	ScreenshotReady_t *self = (ScreenshotReady_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_hLocal") == 0) {
		self->m_hLocal = static_cast<ScreenshotHandle>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "ScreenshotReady_t has no field '%%s'", key);
}

EXTERN int luasteam_newScreenshotReady_t(lua_State *L) {
	ScreenshotReady_t *ptr = (ScreenshotReady_t*)lua_newuserdata(L, sizeof(ScreenshotReady_t));
	new (ptr) ScreenshotReady_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_hLocal");
		if (!lua_isnil(L, -1)) {
			ptr->m_hLocal = static_cast<ScreenshotHandle>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, ScreenshotReady_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int ScreenshotRequested_tMetatable_ref = LUA_NOREF;

static int ScreenshotRequested_t_index(lua_State *L) {
	lua_pushnil(L);
	return 1;
}

EXTERN int luasteam_newScreenshotRequested_t(lua_State *L) {
	ScreenshotRequested_t *ptr = (ScreenshotRequested_t*)lua_newuserdata(L, sizeof(ScreenshotRequested_t));
	new (ptr) ScreenshotRequested_t();
	lua_rawgeti(L, LUA_REGISTRYINDEX, ScreenshotRequested_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int PlaybackStatusHasChanged_tMetatable_ref = LUA_NOREF;

static int PlaybackStatusHasChanged_t_index(lua_State *L) {
	lua_pushnil(L);
	return 1;
}

EXTERN int luasteam_newPlaybackStatusHasChanged_t(lua_State *L) {
	PlaybackStatusHasChanged_t *ptr = (PlaybackStatusHasChanged_t*)lua_newuserdata(L, sizeof(PlaybackStatusHasChanged_t));
	new (ptr) PlaybackStatusHasChanged_t();
	lua_rawgeti(L, LUA_REGISTRYINDEX, PlaybackStatusHasChanged_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int VolumeHasChanged_tMetatable_ref = LUA_NOREF;

static int VolumeHasChanged_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	VolumeHasChanged_t *self = (VolumeHasChanged_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_flNewVolume") == 0) {
		lua_pushnumber(L, self->m_flNewVolume);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int VolumeHasChanged_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	VolumeHasChanged_t *self = (VolumeHasChanged_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_flNewVolume") == 0) {
		self->m_flNewVolume = static_cast<float>(luaL_checknumber(L, 3));
		return 0;
	}
	return luaL_error(L, "VolumeHasChanged_t has no field '%%s'", key);
}

EXTERN int luasteam_newVolumeHasChanged_t(lua_State *L) {
	VolumeHasChanged_t *ptr = (VolumeHasChanged_t*)lua_newuserdata(L, sizeof(VolumeHasChanged_t));
	new (ptr) VolumeHasChanged_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_flNewVolume");
		if (!lua_isnil(L, -1)) {
			ptr->m_flNewVolume = static_cast<float>(luaL_checknumber(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, VolumeHasChanged_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int HTTPRequestCompleted_tMetatable_ref = LUA_NOREF;

static int HTTPRequestCompleted_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	HTTPRequestCompleted_t *self = (HTTPRequestCompleted_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_hRequest") == 0) {
		lua_pushinteger(L, self->m_hRequest);
		return 1;
	}
	if (strcmp(key, "m_ulContextValue") == 0) {
		luasteam::pushuint64(L, self->m_ulContextValue);
		return 1;
	}
	if (strcmp(key, "m_bRequestSuccessful") == 0) {
		lua_pushboolean(L, self->m_bRequestSuccessful);
		return 1;
	}
	if (strcmp(key, "m_eStatusCode") == 0) {
		lua_pushinteger(L, self->m_eStatusCode);
		return 1;
	}
	if (strcmp(key, "m_unBodySize") == 0) {
		lua_pushinteger(L, self->m_unBodySize);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int HTTPRequestCompleted_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	HTTPRequestCompleted_t *self = (HTTPRequestCompleted_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_hRequest") == 0) {
		self->m_hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_ulContextValue") == 0) {
		self->m_ulContextValue = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_bRequestSuccessful") == 0) {
		self->m_bRequestSuccessful = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_eStatusCode") == 0) {
		self->m_eStatusCode = static_cast<EHTTPStatusCode>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_unBodySize") == 0) {
		self->m_unBodySize = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "HTTPRequestCompleted_t has no field '%%s'", key);
}

EXTERN int luasteam_newHTTPRequestCompleted_t(lua_State *L) {
	HTTPRequestCompleted_t *ptr = (HTTPRequestCompleted_t*)lua_newuserdata(L, sizeof(HTTPRequestCompleted_t));
	new (ptr) HTTPRequestCompleted_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_hRequest");
		if (!lua_isnil(L, -1)) {
			ptr->m_hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_ulContextValue");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulContextValue = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bRequestSuccessful");
		if (!lua_isnil(L, -1)) {
			ptr->m_bRequestSuccessful = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eStatusCode");
		if (!lua_isnil(L, -1)) {
			ptr->m_eStatusCode = static_cast<EHTTPStatusCode>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unBodySize");
		if (!lua_isnil(L, -1)) {
			ptr->m_unBodySize = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTTPRequestCompleted_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int HTTPRequestHeadersReceived_tMetatable_ref = LUA_NOREF;

static int HTTPRequestHeadersReceived_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	HTTPRequestHeadersReceived_t *self = (HTTPRequestHeadersReceived_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_hRequest") == 0) {
		lua_pushinteger(L, self->m_hRequest);
		return 1;
	}
	if (strcmp(key, "m_ulContextValue") == 0) {
		luasteam::pushuint64(L, self->m_ulContextValue);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int HTTPRequestHeadersReceived_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	HTTPRequestHeadersReceived_t *self = (HTTPRequestHeadersReceived_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_hRequest") == 0) {
		self->m_hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_ulContextValue") == 0) {
		self->m_ulContextValue = luasteam::checkuint64(L, 3);
		return 0;
	}
	return luaL_error(L, "HTTPRequestHeadersReceived_t has no field '%%s'", key);
}

EXTERN int luasteam_newHTTPRequestHeadersReceived_t(lua_State *L) {
	HTTPRequestHeadersReceived_t *ptr = (HTTPRequestHeadersReceived_t*)lua_newuserdata(L, sizeof(HTTPRequestHeadersReceived_t));
	new (ptr) HTTPRequestHeadersReceived_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_hRequest");
		if (!lua_isnil(L, -1)) {
			ptr->m_hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_ulContextValue");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulContextValue = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTTPRequestHeadersReceived_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int HTTPRequestDataReceived_tMetatable_ref = LUA_NOREF;

static int HTTPRequestDataReceived_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	HTTPRequestDataReceived_t *self = (HTTPRequestDataReceived_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_hRequest") == 0) {
		lua_pushinteger(L, self->m_hRequest);
		return 1;
	}
	if (strcmp(key, "m_ulContextValue") == 0) {
		luasteam::pushuint64(L, self->m_ulContextValue);
		return 1;
	}
	if (strcmp(key, "m_cOffset") == 0) {
		lua_pushinteger(L, self->m_cOffset);
		return 1;
	}
	if (strcmp(key, "m_cBytesReceived") == 0) {
		lua_pushinteger(L, self->m_cBytesReceived);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int HTTPRequestDataReceived_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	HTTPRequestDataReceived_t *self = (HTTPRequestDataReceived_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_hRequest") == 0) {
		self->m_hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_ulContextValue") == 0) {
		self->m_ulContextValue = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_cOffset") == 0) {
		self->m_cOffset = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_cBytesReceived") == 0) {
		self->m_cBytesReceived = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "HTTPRequestDataReceived_t has no field '%%s'", key);
}

EXTERN int luasteam_newHTTPRequestDataReceived_t(lua_State *L) {
	HTTPRequestDataReceived_t *ptr = (HTTPRequestDataReceived_t*)lua_newuserdata(L, sizeof(HTTPRequestDataReceived_t));
	new (ptr) HTTPRequestDataReceived_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_hRequest");
		if (!lua_isnil(L, -1)) {
			ptr->m_hRequest = static_cast<HTTPRequestHandle>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_ulContextValue");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulContextValue = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_cOffset");
		if (!lua_isnil(L, -1)) {
			ptr->m_cOffset = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_cBytesReceived");
		if (!lua_isnil(L, -1)) {
			ptr->m_cBytesReceived = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTTPRequestDataReceived_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamInputDeviceConnected_tMetatable_ref = LUA_NOREF;

static int SteamInputDeviceConnected_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamInputDeviceConnected_t *self = (SteamInputDeviceConnected_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_ulConnectedDeviceHandle") == 0) {
		luasteam::pushuint64(L, self->m_ulConnectedDeviceHandle);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamInputDeviceConnected_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamInputDeviceConnected_t *self = (SteamInputDeviceConnected_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_ulConnectedDeviceHandle") == 0) {
		self->m_ulConnectedDeviceHandle = luasteam::checkuint64(L, 3);
		return 0;
	}
	return luaL_error(L, "SteamInputDeviceConnected_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamInputDeviceConnected_t(lua_State *L) {
	SteamInputDeviceConnected_t *ptr = (SteamInputDeviceConnected_t*)lua_newuserdata(L, sizeof(SteamInputDeviceConnected_t));
	new (ptr) SteamInputDeviceConnected_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_ulConnectedDeviceHandle");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulConnectedDeviceHandle = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInputDeviceConnected_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamInputDeviceDisconnected_tMetatable_ref = LUA_NOREF;

static int SteamInputDeviceDisconnected_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamInputDeviceDisconnected_t *self = (SteamInputDeviceDisconnected_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_ulDisconnectedDeviceHandle") == 0) {
		luasteam::pushuint64(L, self->m_ulDisconnectedDeviceHandle);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamInputDeviceDisconnected_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamInputDeviceDisconnected_t *self = (SteamInputDeviceDisconnected_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_ulDisconnectedDeviceHandle") == 0) {
		self->m_ulDisconnectedDeviceHandle = luasteam::checkuint64(L, 3);
		return 0;
	}
	return luaL_error(L, "SteamInputDeviceDisconnected_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamInputDeviceDisconnected_t(lua_State *L) {
	SteamInputDeviceDisconnected_t *ptr = (SteamInputDeviceDisconnected_t*)lua_newuserdata(L, sizeof(SteamInputDeviceDisconnected_t));
	new (ptr) SteamInputDeviceDisconnected_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_ulDisconnectedDeviceHandle");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulDisconnectedDeviceHandle = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInputDeviceDisconnected_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamInputConfigurationLoaded_tMetatable_ref = LUA_NOREF;

static int SteamInputConfigurationLoaded_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamInputConfigurationLoaded_t *self = (SteamInputConfigurationLoaded_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_unAppID") == 0) {
		lua_pushinteger(L, self->m_unAppID);
		return 1;
	}
	if (strcmp(key, "m_ulDeviceHandle") == 0) {
		luasteam::pushuint64(L, self->m_ulDeviceHandle);
		return 1;
	}
	if (strcmp(key, "m_ulMappingCreator") == 0) {
		luasteam::pushuint64(L, self->m_ulMappingCreator.ConvertToUint64());
		return 1;
	}
	if (strcmp(key, "m_unMajorRevision") == 0) {
		lua_pushinteger(L, self->m_unMajorRevision);
		return 1;
	}
	if (strcmp(key, "m_unMinorRevision") == 0) {
		lua_pushinteger(L, self->m_unMinorRevision);
		return 1;
	}
	if (strcmp(key, "m_bUsesSteamInputAPI") == 0) {
		lua_pushboolean(L, self->m_bUsesSteamInputAPI);
		return 1;
	}
	if (strcmp(key, "m_bUsesGamepadAPI") == 0) {
		lua_pushboolean(L, self->m_bUsesGamepadAPI);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamInputConfigurationLoaded_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamInputConfigurationLoaded_t *self = (SteamInputConfigurationLoaded_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_unAppID") == 0) {
		self->m_unAppID = static_cast<AppId_t>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_ulDeviceHandle") == 0) {
		self->m_ulDeviceHandle = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_ulMappingCreator") == 0) {
		self->m_ulMappingCreator = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	if (strcmp(key, "m_unMajorRevision") == 0) {
		self->m_unMajorRevision = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_unMinorRevision") == 0) {
		self->m_unMinorRevision = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bUsesSteamInputAPI") == 0) {
		self->m_bUsesSteamInputAPI = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_bUsesGamepadAPI") == 0) {
		self->m_bUsesGamepadAPI = lua_toboolean(L, 3);
		return 0;
	}
	return luaL_error(L, "SteamInputConfigurationLoaded_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamInputConfigurationLoaded_t(lua_State *L) {
	SteamInputConfigurationLoaded_t *ptr = (SteamInputConfigurationLoaded_t*)lua_newuserdata(L, sizeof(SteamInputConfigurationLoaded_t));
	new (ptr) SteamInputConfigurationLoaded_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_unAppID");
		if (!lua_isnil(L, -1)) {
			ptr->m_unAppID = static_cast<AppId_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_ulDeviceHandle");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulDeviceHandle = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_ulMappingCreator");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulMappingCreator = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unMajorRevision");
		if (!lua_isnil(L, -1)) {
			ptr->m_unMajorRevision = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unMinorRevision");
		if (!lua_isnil(L, -1)) {
			ptr->m_unMinorRevision = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bUsesSteamInputAPI");
		if (!lua_isnil(L, -1)) {
			ptr->m_bUsesSteamInputAPI = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bUsesGamepadAPI");
		if (!lua_isnil(L, -1)) {
			ptr->m_bUsesGamepadAPI = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInputConfigurationLoaded_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamInputGamepadSlotChange_tMetatable_ref = LUA_NOREF;

static int SteamInputGamepadSlotChange_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamInputGamepadSlotChange_t *self = (SteamInputGamepadSlotChange_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_unAppID") == 0) {
		lua_pushinteger(L, self->m_unAppID);
		return 1;
	}
	if (strcmp(key, "m_ulDeviceHandle") == 0) {
		luasteam::pushuint64(L, self->m_ulDeviceHandle);
		return 1;
	}
	if (strcmp(key, "m_eDeviceType") == 0) {
		lua_pushinteger(L, self->m_eDeviceType);
		return 1;
	}
	if (strcmp(key, "m_nOldGamepadSlot") == 0) {
		lua_pushinteger(L, self->m_nOldGamepadSlot);
		return 1;
	}
	if (strcmp(key, "m_nNewGamepadSlot") == 0) {
		lua_pushinteger(L, self->m_nNewGamepadSlot);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamInputGamepadSlotChange_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamInputGamepadSlotChange_t *self = (SteamInputGamepadSlotChange_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_unAppID") == 0) {
		self->m_unAppID = static_cast<AppId_t>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_ulDeviceHandle") == 0) {
		self->m_ulDeviceHandle = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_eDeviceType") == 0) {
		self->m_eDeviceType = static_cast<ESteamInputType>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nOldGamepadSlot") == 0) {
		self->m_nOldGamepadSlot = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nNewGamepadSlot") == 0) {
		self->m_nNewGamepadSlot = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "SteamInputGamepadSlotChange_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamInputGamepadSlotChange_t(lua_State *L) {
	SteamInputGamepadSlotChange_t *ptr = (SteamInputGamepadSlotChange_t*)lua_newuserdata(L, sizeof(SteamInputGamepadSlotChange_t));
	new (ptr) SteamInputGamepadSlotChange_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_unAppID");
		if (!lua_isnil(L, -1)) {
			ptr->m_unAppID = static_cast<AppId_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_ulDeviceHandle");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulDeviceHandle = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eDeviceType");
		if (!lua_isnil(L, -1)) {
			ptr->m_eDeviceType = static_cast<ESteamInputType>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nOldGamepadSlot");
		if (!lua_isnil(L, -1)) {
			ptr->m_nOldGamepadSlot = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nNewGamepadSlot");
		if (!lua_isnil(L, -1)) {
			ptr->m_nNewGamepadSlot = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInputGamepadSlotChange_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamUGCQueryCompleted_tMetatable_ref = LUA_NOREF;

static int SteamUGCQueryCompleted_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamUGCQueryCompleted_t *self = (SteamUGCQueryCompleted_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_handle") == 0) {
		luasteam::pushuint64(L, self->m_handle);
		return 1;
	}
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_unNumResultsReturned") == 0) {
		lua_pushinteger(L, self->m_unNumResultsReturned);
		return 1;
	}
	if (strcmp(key, "m_unTotalMatchingResults") == 0) {
		lua_pushinteger(L, self->m_unTotalMatchingResults);
		return 1;
	}
	if (strcmp(key, "m_bCachedData") == 0) {
		lua_pushboolean(L, self->m_bCachedData);
		return 1;
	}
	if (strcmp(key, "m_rgchNextCursor") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_rgchNextCursor), 256);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamUGCQueryCompleted_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamUGCQueryCompleted_t *self = (SteamUGCQueryCompleted_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_handle") == 0) {
		self->m_handle = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_unNumResultsReturned") == 0) {
		self->m_unNumResultsReturned = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_unTotalMatchingResults") == 0) {
		self->m_unTotalMatchingResults = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bCachedData") == 0) {
		self->m_bCachedData = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_rgchNextCursor") == 0) {
		size_t _len__tmp72;
		const char *_tmp72 = luaL_checklstring(L, 3, &_len__tmp72);
		if (_len__tmp72 > sizeof(self->m_rgchNextCursor)) luaL_error(L, "String too long");
		memcpy(self->m_rgchNextCursor, _tmp72, std::min(_len__tmp72 + 1, sizeof(self->m_rgchNextCursor)));
		return 0;
	}
	return luaL_error(L, "SteamUGCQueryCompleted_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamUGCQueryCompleted_t(lua_State *L) {
	SteamUGCQueryCompleted_t *ptr = (SteamUGCQueryCompleted_t*)lua_newuserdata(L, sizeof(SteamUGCQueryCompleted_t));
	new (ptr) SteamUGCQueryCompleted_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_handle");
		if (!lua_isnil(L, -1)) {
			ptr->m_handle = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unNumResultsReturned");
		if (!lua_isnil(L, -1)) {
			ptr->m_unNumResultsReturned = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unTotalMatchingResults");
		if (!lua_isnil(L, -1)) {
			ptr->m_unTotalMatchingResults = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bCachedData");
		if (!lua_isnil(L, -1)) {
			ptr->m_bCachedData = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rgchNextCursor");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp73;
			const char *_tmp73 = luaL_checklstring(L, -1, &_len__tmp73);
			if (_len__tmp73 > sizeof(ptr->m_rgchNextCursor)) luaL_error(L, "String too long");
			memcpy(ptr->m_rgchNextCursor, _tmp73, std::min(_len__tmp73 + 1, sizeof(ptr->m_rgchNextCursor)));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamUGCQueryCompleted_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamUGCRequestUGCDetailsResult_tMetatable_ref = LUA_NOREF;

static int SteamUGCRequestUGCDetailsResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamUGCRequestUGCDetailsResult_t *self = (SteamUGCRequestUGCDetailsResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_details") == 0) {
		luasteam::push_SteamUGCDetails_t(L, self->m_details);
		return 1;
	}
	if (strcmp(key, "m_bCachedData") == 0) {
		lua_pushboolean(L, self->m_bCachedData);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamUGCRequestUGCDetailsResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamUGCRequestUGCDetailsResult_t *self = (SteamUGCRequestUGCDetailsResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_details") == 0) {
		self->m_details = luasteam::check_SteamUGCDetails_t(L, 3);
		return 0;
	}
	if (strcmp(key, "m_bCachedData") == 0) {
		self->m_bCachedData = lua_toboolean(L, 3);
		return 0;
	}
	return luaL_error(L, "SteamUGCRequestUGCDetailsResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamUGCRequestUGCDetailsResult_t(lua_State *L) {
	SteamUGCRequestUGCDetailsResult_t *ptr = (SteamUGCRequestUGCDetailsResult_t*)lua_newuserdata(L, sizeof(SteamUGCRequestUGCDetailsResult_t));
	new (ptr) SteamUGCRequestUGCDetailsResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_details");
		if (!lua_isnil(L, -1)) {
			ptr->m_details = luasteam::check_SteamUGCDetails_t(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bCachedData");
		if (!lua_isnil(L, -1)) {
			ptr->m_bCachedData = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamUGCRequestUGCDetailsResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int CreateItemResult_tMetatable_ref = LUA_NOREF;

static int CreateItemResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	CreateItemResult_t *self = (CreateItemResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		luasteam::pushuint64(L, self->m_nPublishedFileId);
		return 1;
	}
	if (strcmp(key, "m_bUserNeedsToAcceptWorkshopLegalAgreement") == 0) {
		lua_pushboolean(L, self->m_bUserNeedsToAcceptWorkshopLegalAgreement);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int CreateItemResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	CreateItemResult_t *self = (CreateItemResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		self->m_nPublishedFileId = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_bUserNeedsToAcceptWorkshopLegalAgreement") == 0) {
		self->m_bUserNeedsToAcceptWorkshopLegalAgreement = lua_toboolean(L, 3);
		return 0;
	}
	return luaL_error(L, "CreateItemResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newCreateItemResult_t(lua_State *L) {
	CreateItemResult_t *ptr = (CreateItemResult_t*)lua_newuserdata(L, sizeof(CreateItemResult_t));
	new (ptr) CreateItemResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nPublishedFileId");
		if (!lua_isnil(L, -1)) {
			ptr->m_nPublishedFileId = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bUserNeedsToAcceptWorkshopLegalAgreement");
		if (!lua_isnil(L, -1)) {
			ptr->m_bUserNeedsToAcceptWorkshopLegalAgreement = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, CreateItemResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SubmitItemUpdateResult_tMetatable_ref = LUA_NOREF;

static int SubmitItemUpdateResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SubmitItemUpdateResult_t *self = (SubmitItemUpdateResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_bUserNeedsToAcceptWorkshopLegalAgreement") == 0) {
		lua_pushboolean(L, self->m_bUserNeedsToAcceptWorkshopLegalAgreement);
		return 1;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		luasteam::pushuint64(L, self->m_nPublishedFileId);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SubmitItemUpdateResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SubmitItemUpdateResult_t *self = (SubmitItemUpdateResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bUserNeedsToAcceptWorkshopLegalAgreement") == 0) {
		self->m_bUserNeedsToAcceptWorkshopLegalAgreement = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		self->m_nPublishedFileId = luasteam::checkuint64(L, 3);
		return 0;
	}
	return luaL_error(L, "SubmitItemUpdateResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newSubmitItemUpdateResult_t(lua_State *L) {
	SubmitItemUpdateResult_t *ptr = (SubmitItemUpdateResult_t*)lua_newuserdata(L, sizeof(SubmitItemUpdateResult_t));
	new (ptr) SubmitItemUpdateResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bUserNeedsToAcceptWorkshopLegalAgreement");
		if (!lua_isnil(L, -1)) {
			ptr->m_bUserNeedsToAcceptWorkshopLegalAgreement = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nPublishedFileId");
		if (!lua_isnil(L, -1)) {
			ptr->m_nPublishedFileId = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SubmitItemUpdateResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int ItemInstalled_tMetatable_ref = LUA_NOREF;

static int ItemInstalled_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	ItemInstalled_t *self = (ItemInstalled_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_unAppID") == 0) {
		lua_pushinteger(L, self->m_unAppID);
		return 1;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		luasteam::pushuint64(L, self->m_nPublishedFileId);
		return 1;
	}
	if (strcmp(key, "m_hLegacyContent") == 0) {
		luasteam::pushuint64(L, self->m_hLegacyContent);
		return 1;
	}
	if (strcmp(key, "m_unManifestID") == 0) {
		luasteam::pushuint64(L, self->m_unManifestID);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int ItemInstalled_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	ItemInstalled_t *self = (ItemInstalled_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_unAppID") == 0) {
		self->m_unAppID = static_cast<AppId_t>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		self->m_nPublishedFileId = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_hLegacyContent") == 0) {
		self->m_hLegacyContent = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_unManifestID") == 0) {
		self->m_unManifestID = luasteam::checkuint64(L, 3);
		return 0;
	}
	return luaL_error(L, "ItemInstalled_t has no field '%%s'", key);
}

EXTERN int luasteam_newItemInstalled_t(lua_State *L) {
	ItemInstalled_t *ptr = (ItemInstalled_t*)lua_newuserdata(L, sizeof(ItemInstalled_t));
	new (ptr) ItemInstalled_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_unAppID");
		if (!lua_isnil(L, -1)) {
			ptr->m_unAppID = static_cast<AppId_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nPublishedFileId");
		if (!lua_isnil(L, -1)) {
			ptr->m_nPublishedFileId = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_hLegacyContent");
		if (!lua_isnil(L, -1)) {
			ptr->m_hLegacyContent = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unManifestID");
		if (!lua_isnil(L, -1)) {
			ptr->m_unManifestID = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, ItemInstalled_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int DownloadItemResult_tMetatable_ref = LUA_NOREF;

static int DownloadItemResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	DownloadItemResult_t *self = (DownloadItemResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_unAppID") == 0) {
		lua_pushinteger(L, self->m_unAppID);
		return 1;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		luasteam::pushuint64(L, self->m_nPublishedFileId);
		return 1;
	}
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int DownloadItemResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	DownloadItemResult_t *self = (DownloadItemResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_unAppID") == 0) {
		self->m_unAppID = static_cast<AppId_t>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		self->m_nPublishedFileId = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "DownloadItemResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newDownloadItemResult_t(lua_State *L) {
	DownloadItemResult_t *ptr = (DownloadItemResult_t*)lua_newuserdata(L, sizeof(DownloadItemResult_t));
	new (ptr) DownloadItemResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_unAppID");
		if (!lua_isnil(L, -1)) {
			ptr->m_unAppID = static_cast<AppId_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
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
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, DownloadItemResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int UserFavoriteItemsListChanged_tMetatable_ref = LUA_NOREF;

static int UserFavoriteItemsListChanged_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	UserFavoriteItemsListChanged_t *self = (UserFavoriteItemsListChanged_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		luasteam::pushuint64(L, self->m_nPublishedFileId);
		return 1;
	}
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_bWasAddRequest") == 0) {
		lua_pushboolean(L, self->m_bWasAddRequest);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int UserFavoriteItemsListChanged_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	UserFavoriteItemsListChanged_t *self = (UserFavoriteItemsListChanged_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		self->m_nPublishedFileId = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bWasAddRequest") == 0) {
		self->m_bWasAddRequest = lua_toboolean(L, 3);
		return 0;
	}
	return luaL_error(L, "UserFavoriteItemsListChanged_t has no field '%%s'", key);
}

EXTERN int luasteam_newUserFavoriteItemsListChanged_t(lua_State *L) {
	UserFavoriteItemsListChanged_t *ptr = (UserFavoriteItemsListChanged_t*)lua_newuserdata(L, sizeof(UserFavoriteItemsListChanged_t));
	new (ptr) UserFavoriteItemsListChanged_t();
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
		lua_getfield(L, 1, "m_bWasAddRequest");
		if (!lua_isnil(L, -1)) {
			ptr->m_bWasAddRequest = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, UserFavoriteItemsListChanged_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SetUserItemVoteResult_tMetatable_ref = LUA_NOREF;

static int SetUserItemVoteResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SetUserItemVoteResult_t *self = (SetUserItemVoteResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		luasteam::pushuint64(L, self->m_nPublishedFileId);
		return 1;
	}
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_bVoteUp") == 0) {
		lua_pushboolean(L, self->m_bVoteUp);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SetUserItemVoteResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SetUserItemVoteResult_t *self = (SetUserItemVoteResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		self->m_nPublishedFileId = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bVoteUp") == 0) {
		self->m_bVoteUp = lua_toboolean(L, 3);
		return 0;
	}
	return luaL_error(L, "SetUserItemVoteResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newSetUserItemVoteResult_t(lua_State *L) {
	SetUserItemVoteResult_t *ptr = (SetUserItemVoteResult_t*)lua_newuserdata(L, sizeof(SetUserItemVoteResult_t));
	new (ptr) SetUserItemVoteResult_t();
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
		lua_getfield(L, 1, "m_bVoteUp");
		if (!lua_isnil(L, -1)) {
			ptr->m_bVoteUp = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SetUserItemVoteResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int GetUserItemVoteResult_tMetatable_ref = LUA_NOREF;

static int GetUserItemVoteResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	GetUserItemVoteResult_t *self = (GetUserItemVoteResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		luasteam::pushuint64(L, self->m_nPublishedFileId);
		return 1;
	}
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_bVotedUp") == 0) {
		lua_pushboolean(L, self->m_bVotedUp);
		return 1;
	}
	if (strcmp(key, "m_bVotedDown") == 0) {
		lua_pushboolean(L, self->m_bVotedDown);
		return 1;
	}
	if (strcmp(key, "m_bVoteSkipped") == 0) {
		lua_pushboolean(L, self->m_bVoteSkipped);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int GetUserItemVoteResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	GetUserItemVoteResult_t *self = (GetUserItemVoteResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		self->m_nPublishedFileId = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bVotedUp") == 0) {
		self->m_bVotedUp = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_bVotedDown") == 0) {
		self->m_bVotedDown = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_bVoteSkipped") == 0) {
		self->m_bVoteSkipped = lua_toboolean(L, 3);
		return 0;
	}
	return luaL_error(L, "GetUserItemVoteResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newGetUserItemVoteResult_t(lua_State *L) {
	GetUserItemVoteResult_t *ptr = (GetUserItemVoteResult_t*)lua_newuserdata(L, sizeof(GetUserItemVoteResult_t));
	new (ptr) GetUserItemVoteResult_t();
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
		lua_getfield(L, 1, "m_bVotedUp");
		if (!lua_isnil(L, -1)) {
			ptr->m_bVotedUp = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bVotedDown");
		if (!lua_isnil(L, -1)) {
			ptr->m_bVotedDown = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bVoteSkipped");
		if (!lua_isnil(L, -1)) {
			ptr->m_bVoteSkipped = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, GetUserItemVoteResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int StartPlaytimeTrackingResult_tMetatable_ref = LUA_NOREF;

static int StartPlaytimeTrackingResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	StartPlaytimeTrackingResult_t *self = (StartPlaytimeTrackingResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int StartPlaytimeTrackingResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	StartPlaytimeTrackingResult_t *self = (StartPlaytimeTrackingResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "StartPlaytimeTrackingResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newStartPlaytimeTrackingResult_t(lua_State *L) {
	StartPlaytimeTrackingResult_t *ptr = (StartPlaytimeTrackingResult_t*)lua_newuserdata(L, sizeof(StartPlaytimeTrackingResult_t));
	new (ptr) StartPlaytimeTrackingResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, StartPlaytimeTrackingResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int StopPlaytimeTrackingResult_tMetatable_ref = LUA_NOREF;

static int StopPlaytimeTrackingResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	StopPlaytimeTrackingResult_t *self = (StopPlaytimeTrackingResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int StopPlaytimeTrackingResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	StopPlaytimeTrackingResult_t *self = (StopPlaytimeTrackingResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "StopPlaytimeTrackingResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newStopPlaytimeTrackingResult_t(lua_State *L) {
	StopPlaytimeTrackingResult_t *ptr = (StopPlaytimeTrackingResult_t*)lua_newuserdata(L, sizeof(StopPlaytimeTrackingResult_t));
	new (ptr) StopPlaytimeTrackingResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, StopPlaytimeTrackingResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int AddUGCDependencyResult_tMetatable_ref = LUA_NOREF;

static int AddUGCDependencyResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	AddUGCDependencyResult_t *self = (AddUGCDependencyResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		luasteam::pushuint64(L, self->m_nPublishedFileId);
		return 1;
	}
	if (strcmp(key, "m_nChildPublishedFileId") == 0) {
		luasteam::pushuint64(L, self->m_nChildPublishedFileId);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int AddUGCDependencyResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	AddUGCDependencyResult_t *self = (AddUGCDependencyResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		self->m_nPublishedFileId = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_nChildPublishedFileId") == 0) {
		self->m_nChildPublishedFileId = luasteam::checkuint64(L, 3);
		return 0;
	}
	return luaL_error(L, "AddUGCDependencyResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newAddUGCDependencyResult_t(lua_State *L) {
	AddUGCDependencyResult_t *ptr = (AddUGCDependencyResult_t*)lua_newuserdata(L, sizeof(AddUGCDependencyResult_t));
	new (ptr) AddUGCDependencyResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nPublishedFileId");
		if (!lua_isnil(L, -1)) {
			ptr->m_nPublishedFileId = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nChildPublishedFileId");
		if (!lua_isnil(L, -1)) {
			ptr->m_nChildPublishedFileId = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, AddUGCDependencyResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemoveUGCDependencyResult_tMetatable_ref = LUA_NOREF;

static int RemoveUGCDependencyResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	RemoveUGCDependencyResult_t *self = (RemoveUGCDependencyResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		luasteam::pushuint64(L, self->m_nPublishedFileId);
		return 1;
	}
	if (strcmp(key, "m_nChildPublishedFileId") == 0) {
		luasteam::pushuint64(L, self->m_nChildPublishedFileId);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int RemoveUGCDependencyResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	RemoveUGCDependencyResult_t *self = (RemoveUGCDependencyResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		self->m_nPublishedFileId = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_nChildPublishedFileId") == 0) {
		self->m_nChildPublishedFileId = luasteam::checkuint64(L, 3);
		return 0;
	}
	return luaL_error(L, "RemoveUGCDependencyResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newRemoveUGCDependencyResult_t(lua_State *L) {
	RemoveUGCDependencyResult_t *ptr = (RemoveUGCDependencyResult_t*)lua_newuserdata(L, sizeof(RemoveUGCDependencyResult_t));
	new (ptr) RemoveUGCDependencyResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nPublishedFileId");
		if (!lua_isnil(L, -1)) {
			ptr->m_nPublishedFileId = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nChildPublishedFileId");
		if (!lua_isnil(L, -1)) {
			ptr->m_nChildPublishedFileId = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoveUGCDependencyResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int AddAppDependencyResult_tMetatable_ref = LUA_NOREF;

static int AddAppDependencyResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	AddAppDependencyResult_t *self = (AddAppDependencyResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		luasteam::pushuint64(L, self->m_nPublishedFileId);
		return 1;
	}
	if (strcmp(key, "m_nAppID") == 0) {
		lua_pushinteger(L, self->m_nAppID);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int AddAppDependencyResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	AddAppDependencyResult_t *self = (AddAppDependencyResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		self->m_nPublishedFileId = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_nAppID") == 0) {
		self->m_nAppID = static_cast<AppId_t>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "AddAppDependencyResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newAddAppDependencyResult_t(lua_State *L) {
	AddAppDependencyResult_t *ptr = (AddAppDependencyResult_t*)lua_newuserdata(L, sizeof(AddAppDependencyResult_t));
	new (ptr) AddAppDependencyResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nPublishedFileId");
		if (!lua_isnil(L, -1)) {
			ptr->m_nPublishedFileId = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nAppID");
		if (!lua_isnil(L, -1)) {
			ptr->m_nAppID = static_cast<AppId_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, AddAppDependencyResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int RemoveAppDependencyResult_tMetatable_ref = LUA_NOREF;

static int RemoveAppDependencyResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	RemoveAppDependencyResult_t *self = (RemoveAppDependencyResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		luasteam::pushuint64(L, self->m_nPublishedFileId);
		return 1;
	}
	if (strcmp(key, "m_nAppID") == 0) {
		lua_pushinteger(L, self->m_nAppID);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int RemoveAppDependencyResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	RemoveAppDependencyResult_t *self = (RemoveAppDependencyResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		self->m_nPublishedFileId = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_nAppID") == 0) {
		self->m_nAppID = static_cast<AppId_t>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "RemoveAppDependencyResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newRemoveAppDependencyResult_t(lua_State *L) {
	RemoveAppDependencyResult_t *ptr = (RemoveAppDependencyResult_t*)lua_newuserdata(L, sizeof(RemoveAppDependencyResult_t));
	new (ptr) RemoveAppDependencyResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nPublishedFileId");
		if (!lua_isnil(L, -1)) {
			ptr->m_nPublishedFileId = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nAppID");
		if (!lua_isnil(L, -1)) {
			ptr->m_nAppID = static_cast<AppId_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoveAppDependencyResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int GetAppDependenciesResult_tMetatable_ref = LUA_NOREF;

static int GetAppDependenciesResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	GetAppDependenciesResult_t *self = (GetAppDependenciesResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		luasteam::pushuint64(L, self->m_nPublishedFileId);
		return 1;
	}
	if (strcmp(key, "m_rgAppIDs") == 0) {
		lua_createtable(L, 32, 0);
		for(decltype(32) i = 0; i < 32; i++) {
			lua_pushinteger(L, self->m_rgAppIDs[i]);
			lua_rawseti(L, -2, i+1);
		}
		return 1;
	}
	if (strcmp(key, "m_nNumAppDependencies") == 0) {
		lua_pushinteger(L, self->m_nNumAppDependencies);
		return 1;
	}
	if (strcmp(key, "m_nTotalNumAppDependencies") == 0) {
		lua_pushinteger(L, self->m_nTotalNumAppDependencies);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int GetAppDependenciesResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	GetAppDependenciesResult_t *self = (GetAppDependenciesResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		self->m_nPublishedFileId = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_rgAppIDs") == 0) {
		luaL_checktype(L, 3, LUA_TTABLE);
		for(decltype(32) i = 0; i < 32; i++) {
			lua_rawgeti(L, 3, i+1);
			self->m_rgAppIDs[i] = static_cast<int>(luaL_checkint(L, -1));
			lua_pop(L, 1);
		}
		return 0;
	}
	if (strcmp(key, "m_nNumAppDependencies") == 0) {
		self->m_nNumAppDependencies = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nTotalNumAppDependencies") == 0) {
		self->m_nTotalNumAppDependencies = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "GetAppDependenciesResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newGetAppDependenciesResult_t(lua_State *L) {
	GetAppDependenciesResult_t *ptr = (GetAppDependenciesResult_t*)lua_newuserdata(L, sizeof(GetAppDependenciesResult_t));
	new (ptr) GetAppDependenciesResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nPublishedFileId");
		if (!lua_isnil(L, -1)) {
			ptr->m_nPublishedFileId = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rgAppIDs");
		if (!lua_isnil(L, -1)) {
			luaL_checktype(L, -1, LUA_TTABLE);
			for(decltype(32) i = 0; i < 32; i++) {
				lua_rawgeti(L, -1, i+1);
				ptr->m_rgAppIDs[i] = static_cast<int>(luaL_checkint(L, -1));
				lua_pop(L, 1);
			}
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nNumAppDependencies");
		if (!lua_isnil(L, -1)) {
			ptr->m_nNumAppDependencies = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nTotalNumAppDependencies");
		if (!lua_isnil(L, -1)) {
			ptr->m_nTotalNumAppDependencies = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, GetAppDependenciesResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int DeleteItemResult_tMetatable_ref = LUA_NOREF;

static int DeleteItemResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	DeleteItemResult_t *self = (DeleteItemResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		luasteam::pushuint64(L, self->m_nPublishedFileId);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int DeleteItemResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	DeleteItemResult_t *self = (DeleteItemResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nPublishedFileId") == 0) {
		self->m_nPublishedFileId = luasteam::checkuint64(L, 3);
		return 0;
	}
	return luaL_error(L, "DeleteItemResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newDeleteItemResult_t(lua_State *L) {
	DeleteItemResult_t *ptr = (DeleteItemResult_t*)lua_newuserdata(L, sizeof(DeleteItemResult_t));
	new (ptr) DeleteItemResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nPublishedFileId");
		if (!lua_isnil(L, -1)) {
			ptr->m_nPublishedFileId = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, DeleteItemResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int UserSubscribedItemsListChanged_tMetatable_ref = LUA_NOREF;

static int UserSubscribedItemsListChanged_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	UserSubscribedItemsListChanged_t *self = (UserSubscribedItemsListChanged_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nAppID") == 0) {
		lua_pushinteger(L, self->m_nAppID);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int UserSubscribedItemsListChanged_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	UserSubscribedItemsListChanged_t *self = (UserSubscribedItemsListChanged_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_nAppID") == 0) {
		self->m_nAppID = static_cast<AppId_t>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "UserSubscribedItemsListChanged_t has no field '%%s'", key);
}

EXTERN int luasteam_newUserSubscribedItemsListChanged_t(lua_State *L) {
	UserSubscribedItemsListChanged_t *ptr = (UserSubscribedItemsListChanged_t*)lua_newuserdata(L, sizeof(UserSubscribedItemsListChanged_t));
	new (ptr) UserSubscribedItemsListChanged_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_nAppID");
		if (!lua_isnil(L, -1)) {
			ptr->m_nAppID = static_cast<AppId_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, UserSubscribedItemsListChanged_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int WorkshopEULAStatus_tMetatable_ref = LUA_NOREF;

static int WorkshopEULAStatus_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	WorkshopEULAStatus_t *self = (WorkshopEULAStatus_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_nAppID") == 0) {
		lua_pushinteger(L, self->m_nAppID);
		return 1;
	}
	if (strcmp(key, "m_unVersion") == 0) {
		lua_pushinteger(L, self->m_unVersion);
		return 1;
	}
	if (strcmp(key, "m_rtAction") == 0) {
		lua_pushinteger(L, self->m_rtAction);
		return 1;
	}
	if (strcmp(key, "m_bAccepted") == 0) {
		lua_pushboolean(L, self->m_bAccepted);
		return 1;
	}
	if (strcmp(key, "m_bNeedsAction") == 0) {
		lua_pushboolean(L, self->m_bNeedsAction);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int WorkshopEULAStatus_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	WorkshopEULAStatus_t *self = (WorkshopEULAStatus_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nAppID") == 0) {
		self->m_nAppID = static_cast<AppId_t>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_unVersion") == 0) {
		self->m_unVersion = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_rtAction") == 0) {
		self->m_rtAction = static_cast<RTime32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bAccepted") == 0) {
		self->m_bAccepted = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_bNeedsAction") == 0) {
		self->m_bNeedsAction = lua_toboolean(L, 3);
		return 0;
	}
	return luaL_error(L, "WorkshopEULAStatus_t has no field '%%s'", key);
}

EXTERN int luasteam_newWorkshopEULAStatus_t(lua_State *L) {
	WorkshopEULAStatus_t *ptr = (WorkshopEULAStatus_t*)lua_newuserdata(L, sizeof(WorkshopEULAStatus_t));
	new (ptr) WorkshopEULAStatus_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nAppID");
		if (!lua_isnil(L, -1)) {
			ptr->m_nAppID = static_cast<AppId_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unVersion");
		if (!lua_isnil(L, -1)) {
			ptr->m_unVersion = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rtAction");
		if (!lua_isnil(L, -1)) {
			ptr->m_rtAction = static_cast<RTime32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bAccepted");
		if (!lua_isnil(L, -1)) {
			ptr->m_bAccepted = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bNeedsAction");
		if (!lua_isnil(L, -1)) {
			ptr->m_bNeedsAction = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, WorkshopEULAStatus_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int HTML_BrowserReady_tMetatable_ref = LUA_NOREF;

static int HTML_BrowserReady_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	HTML_BrowserReady_t *self = (HTML_BrowserReady_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		lua_pushinteger(L, self->unBrowserHandle);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int HTML_BrowserReady_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	HTML_BrowserReady_t *self = (HTML_BrowserReady_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		self->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "HTML_BrowserReady_t has no field '%%s'", key);
}

EXTERN int luasteam_newHTML_BrowserReady_t(lua_State *L) {
	HTML_BrowserReady_t *ptr = (HTML_BrowserReady_t*)lua_newuserdata(L, sizeof(HTML_BrowserReady_t));
	new (ptr) HTML_BrowserReady_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "unBrowserHandle");
		if (!lua_isnil(L, -1)) {
			ptr->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_BrowserReady_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int HTML_NeedsPaint_tMetatable_ref = LUA_NOREF;

static int HTML_NeedsPaint_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	HTML_NeedsPaint_t *self = (HTML_NeedsPaint_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		lua_pushinteger(L, self->unBrowserHandle);
		return 1;
	}
	if (strcmp(key, "pBGRA") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->pBGRA));
		return 1;
	}
	if (strcmp(key, "unWide") == 0) {
		lua_pushinteger(L, self->unWide);
		return 1;
	}
	if (strcmp(key, "unTall") == 0) {
		lua_pushinteger(L, self->unTall);
		return 1;
	}
	if (strcmp(key, "unUpdateX") == 0) {
		lua_pushinteger(L, self->unUpdateX);
		return 1;
	}
	if (strcmp(key, "unUpdateY") == 0) {
		lua_pushinteger(L, self->unUpdateY);
		return 1;
	}
	if (strcmp(key, "unUpdateWide") == 0) {
		lua_pushinteger(L, self->unUpdateWide);
		return 1;
	}
	if (strcmp(key, "unUpdateTall") == 0) {
		lua_pushinteger(L, self->unUpdateTall);
		return 1;
	}
	if (strcmp(key, "unScrollX") == 0) {
		lua_pushinteger(L, self->unScrollX);
		return 1;
	}
	if (strcmp(key, "unScrollY") == 0) {
		lua_pushinteger(L, self->unScrollY);
		return 1;
	}
	if (strcmp(key, "flPageScale") == 0) {
		lua_pushnumber(L, self->flPageScale);
		return 1;
	}
	if (strcmp(key, "unPageSerial") == 0) {
		lua_pushinteger(L, self->unPageSerial);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int HTML_NeedsPaint_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	HTML_NeedsPaint_t *self = (HTML_NeedsPaint_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		self->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "unWide") == 0) {
		self->unWide = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "unTall") == 0) {
		self->unTall = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "unUpdateX") == 0) {
		self->unUpdateX = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "unUpdateY") == 0) {
		self->unUpdateY = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "unUpdateWide") == 0) {
		self->unUpdateWide = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "unUpdateTall") == 0) {
		self->unUpdateTall = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "unScrollX") == 0) {
		self->unScrollX = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "unScrollY") == 0) {
		self->unScrollY = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "flPageScale") == 0) {
		self->flPageScale = static_cast<float>(luaL_checknumber(L, 3));
		return 0;
	}
	if (strcmp(key, "unPageSerial") == 0) {
		self->unPageSerial = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "HTML_NeedsPaint_t has no field '%%s'", key);
}

EXTERN int luasteam_newHTML_NeedsPaint_t(lua_State *L) {
	HTML_NeedsPaint_t *ptr = (HTML_NeedsPaint_t*)lua_newuserdata(L, sizeof(HTML_NeedsPaint_t));
	new (ptr) HTML_NeedsPaint_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "unBrowserHandle");
		if (!lua_isnil(L, -1)) {
			ptr->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "unWide");
		if (!lua_isnil(L, -1)) {
			ptr->unWide = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "unTall");
		if (!lua_isnil(L, -1)) {
			ptr->unTall = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "unUpdateX");
		if (!lua_isnil(L, -1)) {
			ptr->unUpdateX = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "unUpdateY");
		if (!lua_isnil(L, -1)) {
			ptr->unUpdateY = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "unUpdateWide");
		if (!lua_isnil(L, -1)) {
			ptr->unUpdateWide = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "unUpdateTall");
		if (!lua_isnil(L, -1)) {
			ptr->unUpdateTall = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "unScrollX");
		if (!lua_isnil(L, -1)) {
			ptr->unScrollX = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "unScrollY");
		if (!lua_isnil(L, -1)) {
			ptr->unScrollY = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "flPageScale");
		if (!lua_isnil(L, -1)) {
			ptr->flPageScale = static_cast<float>(luaL_checknumber(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "unPageSerial");
		if (!lua_isnil(L, -1)) {
			ptr->unPageSerial = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_NeedsPaint_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int HTML_StartRequest_tMetatable_ref = LUA_NOREF;

static int HTML_StartRequest_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	HTML_StartRequest_t *self = (HTML_StartRequest_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		lua_pushinteger(L, self->unBrowserHandle);
		return 1;
	}
	if (strcmp(key, "pchURL") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->pchURL));
		return 1;
	}
	if (strcmp(key, "pchTarget") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->pchTarget));
		return 1;
	}
	if (strcmp(key, "pchPostData") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->pchPostData));
		return 1;
	}
	if (strcmp(key, "bIsRedirect") == 0) {
		lua_pushboolean(L, self->bIsRedirect);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int HTML_StartRequest_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	HTML_StartRequest_t *self = (HTML_StartRequest_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		self->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "bIsRedirect") == 0) {
		self->bIsRedirect = lua_toboolean(L, 3);
		return 0;
	}
	return luaL_error(L, "HTML_StartRequest_t has no field '%%s'", key);
}

EXTERN int luasteam_newHTML_StartRequest_t(lua_State *L) {
	HTML_StartRequest_t *ptr = (HTML_StartRequest_t*)lua_newuserdata(L, sizeof(HTML_StartRequest_t));
	new (ptr) HTML_StartRequest_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "unBrowserHandle");
		if (!lua_isnil(L, -1)) {
			ptr->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "bIsRedirect");
		if (!lua_isnil(L, -1)) {
			ptr->bIsRedirect = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_StartRequest_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int HTML_CloseBrowser_tMetatable_ref = LUA_NOREF;

static int HTML_CloseBrowser_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	HTML_CloseBrowser_t *self = (HTML_CloseBrowser_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		lua_pushinteger(L, self->unBrowserHandle);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int HTML_CloseBrowser_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	HTML_CloseBrowser_t *self = (HTML_CloseBrowser_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		self->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "HTML_CloseBrowser_t has no field '%%s'", key);
}

EXTERN int luasteam_newHTML_CloseBrowser_t(lua_State *L) {
	HTML_CloseBrowser_t *ptr = (HTML_CloseBrowser_t*)lua_newuserdata(L, sizeof(HTML_CloseBrowser_t));
	new (ptr) HTML_CloseBrowser_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "unBrowserHandle");
		if (!lua_isnil(L, -1)) {
			ptr->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_CloseBrowser_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int HTML_URLChanged_tMetatable_ref = LUA_NOREF;

static int HTML_URLChanged_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	HTML_URLChanged_t *self = (HTML_URLChanged_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		lua_pushinteger(L, self->unBrowserHandle);
		return 1;
	}
	if (strcmp(key, "pchURL") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->pchURL));
		return 1;
	}
	if (strcmp(key, "pchPostData") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->pchPostData));
		return 1;
	}
	if (strcmp(key, "bIsRedirect") == 0) {
		lua_pushboolean(L, self->bIsRedirect);
		return 1;
	}
	if (strcmp(key, "pchPageTitle") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->pchPageTitle));
		return 1;
	}
	if (strcmp(key, "bNewNavigation") == 0) {
		lua_pushboolean(L, self->bNewNavigation);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int HTML_URLChanged_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	HTML_URLChanged_t *self = (HTML_URLChanged_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		self->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "bIsRedirect") == 0) {
		self->bIsRedirect = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "bNewNavigation") == 0) {
		self->bNewNavigation = lua_toboolean(L, 3);
		return 0;
	}
	return luaL_error(L, "HTML_URLChanged_t has no field '%%s'", key);
}

EXTERN int luasteam_newHTML_URLChanged_t(lua_State *L) {
	HTML_URLChanged_t *ptr = (HTML_URLChanged_t*)lua_newuserdata(L, sizeof(HTML_URLChanged_t));
	new (ptr) HTML_URLChanged_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "unBrowserHandle");
		if (!lua_isnil(L, -1)) {
			ptr->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "bIsRedirect");
		if (!lua_isnil(L, -1)) {
			ptr->bIsRedirect = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "bNewNavigation");
		if (!lua_isnil(L, -1)) {
			ptr->bNewNavigation = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_URLChanged_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int HTML_FinishedRequest_tMetatable_ref = LUA_NOREF;

static int HTML_FinishedRequest_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	HTML_FinishedRequest_t *self = (HTML_FinishedRequest_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		lua_pushinteger(L, self->unBrowserHandle);
		return 1;
	}
	if (strcmp(key, "pchURL") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->pchURL));
		return 1;
	}
	if (strcmp(key, "pchPageTitle") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->pchPageTitle));
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int HTML_FinishedRequest_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	HTML_FinishedRequest_t *self = (HTML_FinishedRequest_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		self->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "HTML_FinishedRequest_t has no field '%%s'", key);
}

EXTERN int luasteam_newHTML_FinishedRequest_t(lua_State *L) {
	HTML_FinishedRequest_t *ptr = (HTML_FinishedRequest_t*)lua_newuserdata(L, sizeof(HTML_FinishedRequest_t));
	new (ptr) HTML_FinishedRequest_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "unBrowserHandle");
		if (!lua_isnil(L, -1)) {
			ptr->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_FinishedRequest_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int HTML_OpenLinkInNewTab_tMetatable_ref = LUA_NOREF;

static int HTML_OpenLinkInNewTab_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	HTML_OpenLinkInNewTab_t *self = (HTML_OpenLinkInNewTab_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		lua_pushinteger(L, self->unBrowserHandle);
		return 1;
	}
	if (strcmp(key, "pchURL") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->pchURL));
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int HTML_OpenLinkInNewTab_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	HTML_OpenLinkInNewTab_t *self = (HTML_OpenLinkInNewTab_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		self->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "HTML_OpenLinkInNewTab_t has no field '%%s'", key);
}

EXTERN int luasteam_newHTML_OpenLinkInNewTab_t(lua_State *L) {
	HTML_OpenLinkInNewTab_t *ptr = (HTML_OpenLinkInNewTab_t*)lua_newuserdata(L, sizeof(HTML_OpenLinkInNewTab_t));
	new (ptr) HTML_OpenLinkInNewTab_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "unBrowserHandle");
		if (!lua_isnil(L, -1)) {
			ptr->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_OpenLinkInNewTab_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int HTML_ChangedTitle_tMetatable_ref = LUA_NOREF;

static int HTML_ChangedTitle_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	HTML_ChangedTitle_t *self = (HTML_ChangedTitle_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		lua_pushinteger(L, self->unBrowserHandle);
		return 1;
	}
	if (strcmp(key, "pchTitle") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->pchTitle));
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int HTML_ChangedTitle_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	HTML_ChangedTitle_t *self = (HTML_ChangedTitle_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		self->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "HTML_ChangedTitle_t has no field '%%s'", key);
}

EXTERN int luasteam_newHTML_ChangedTitle_t(lua_State *L) {
	HTML_ChangedTitle_t *ptr = (HTML_ChangedTitle_t*)lua_newuserdata(L, sizeof(HTML_ChangedTitle_t));
	new (ptr) HTML_ChangedTitle_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "unBrowserHandle");
		if (!lua_isnil(L, -1)) {
			ptr->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_ChangedTitle_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int HTML_SearchResults_tMetatable_ref = LUA_NOREF;

static int HTML_SearchResults_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	HTML_SearchResults_t *self = (HTML_SearchResults_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		lua_pushinteger(L, self->unBrowserHandle);
		return 1;
	}
	if (strcmp(key, "unResults") == 0) {
		lua_pushinteger(L, self->unResults);
		return 1;
	}
	if (strcmp(key, "unCurrentMatch") == 0) {
		lua_pushinteger(L, self->unCurrentMatch);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int HTML_SearchResults_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	HTML_SearchResults_t *self = (HTML_SearchResults_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		self->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "unResults") == 0) {
		self->unResults = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "unCurrentMatch") == 0) {
		self->unCurrentMatch = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "HTML_SearchResults_t has no field '%%s'", key);
}

EXTERN int luasteam_newHTML_SearchResults_t(lua_State *L) {
	HTML_SearchResults_t *ptr = (HTML_SearchResults_t*)lua_newuserdata(L, sizeof(HTML_SearchResults_t));
	new (ptr) HTML_SearchResults_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "unBrowserHandle");
		if (!lua_isnil(L, -1)) {
			ptr->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "unResults");
		if (!lua_isnil(L, -1)) {
			ptr->unResults = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "unCurrentMatch");
		if (!lua_isnil(L, -1)) {
			ptr->unCurrentMatch = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_SearchResults_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int HTML_CanGoBackAndForward_tMetatable_ref = LUA_NOREF;

static int HTML_CanGoBackAndForward_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	HTML_CanGoBackAndForward_t *self = (HTML_CanGoBackAndForward_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		lua_pushinteger(L, self->unBrowserHandle);
		return 1;
	}
	if (strcmp(key, "bCanGoBack") == 0) {
		lua_pushboolean(L, self->bCanGoBack);
		return 1;
	}
	if (strcmp(key, "bCanGoForward") == 0) {
		lua_pushboolean(L, self->bCanGoForward);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int HTML_CanGoBackAndForward_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	HTML_CanGoBackAndForward_t *self = (HTML_CanGoBackAndForward_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		self->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "bCanGoBack") == 0) {
		self->bCanGoBack = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "bCanGoForward") == 0) {
		self->bCanGoForward = lua_toboolean(L, 3);
		return 0;
	}
	return luaL_error(L, "HTML_CanGoBackAndForward_t has no field '%%s'", key);
}

EXTERN int luasteam_newHTML_CanGoBackAndForward_t(lua_State *L) {
	HTML_CanGoBackAndForward_t *ptr = (HTML_CanGoBackAndForward_t*)lua_newuserdata(L, sizeof(HTML_CanGoBackAndForward_t));
	new (ptr) HTML_CanGoBackAndForward_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "unBrowserHandle");
		if (!lua_isnil(L, -1)) {
			ptr->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "bCanGoBack");
		if (!lua_isnil(L, -1)) {
			ptr->bCanGoBack = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "bCanGoForward");
		if (!lua_isnil(L, -1)) {
			ptr->bCanGoForward = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_CanGoBackAndForward_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int HTML_HorizontalScroll_tMetatable_ref = LUA_NOREF;

static int HTML_HorizontalScroll_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	HTML_HorizontalScroll_t *self = (HTML_HorizontalScroll_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		lua_pushinteger(L, self->unBrowserHandle);
		return 1;
	}
	if (strcmp(key, "unScrollMax") == 0) {
		lua_pushinteger(L, self->unScrollMax);
		return 1;
	}
	if (strcmp(key, "unScrollCurrent") == 0) {
		lua_pushinteger(L, self->unScrollCurrent);
		return 1;
	}
	if (strcmp(key, "flPageScale") == 0) {
		lua_pushnumber(L, self->flPageScale);
		return 1;
	}
	if (strcmp(key, "bVisible") == 0) {
		lua_pushboolean(L, self->bVisible);
		return 1;
	}
	if (strcmp(key, "unPageSize") == 0) {
		lua_pushinteger(L, self->unPageSize);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int HTML_HorizontalScroll_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	HTML_HorizontalScroll_t *self = (HTML_HorizontalScroll_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		self->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "unScrollMax") == 0) {
		self->unScrollMax = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "unScrollCurrent") == 0) {
		self->unScrollCurrent = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "flPageScale") == 0) {
		self->flPageScale = static_cast<float>(luaL_checknumber(L, 3));
		return 0;
	}
	if (strcmp(key, "bVisible") == 0) {
		self->bVisible = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "unPageSize") == 0) {
		self->unPageSize = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "HTML_HorizontalScroll_t has no field '%%s'", key);
}

EXTERN int luasteam_newHTML_HorizontalScroll_t(lua_State *L) {
	HTML_HorizontalScroll_t *ptr = (HTML_HorizontalScroll_t*)lua_newuserdata(L, sizeof(HTML_HorizontalScroll_t));
	new (ptr) HTML_HorizontalScroll_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "unBrowserHandle");
		if (!lua_isnil(L, -1)) {
			ptr->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "unScrollMax");
		if (!lua_isnil(L, -1)) {
			ptr->unScrollMax = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "unScrollCurrent");
		if (!lua_isnil(L, -1)) {
			ptr->unScrollCurrent = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "flPageScale");
		if (!lua_isnil(L, -1)) {
			ptr->flPageScale = static_cast<float>(luaL_checknumber(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "bVisible");
		if (!lua_isnil(L, -1)) {
			ptr->bVisible = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "unPageSize");
		if (!lua_isnil(L, -1)) {
			ptr->unPageSize = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_HorizontalScroll_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int HTML_VerticalScroll_tMetatable_ref = LUA_NOREF;

static int HTML_VerticalScroll_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	HTML_VerticalScroll_t *self = (HTML_VerticalScroll_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		lua_pushinteger(L, self->unBrowserHandle);
		return 1;
	}
	if (strcmp(key, "unScrollMax") == 0) {
		lua_pushinteger(L, self->unScrollMax);
		return 1;
	}
	if (strcmp(key, "unScrollCurrent") == 0) {
		lua_pushinteger(L, self->unScrollCurrent);
		return 1;
	}
	if (strcmp(key, "flPageScale") == 0) {
		lua_pushnumber(L, self->flPageScale);
		return 1;
	}
	if (strcmp(key, "bVisible") == 0) {
		lua_pushboolean(L, self->bVisible);
		return 1;
	}
	if (strcmp(key, "unPageSize") == 0) {
		lua_pushinteger(L, self->unPageSize);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int HTML_VerticalScroll_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	HTML_VerticalScroll_t *self = (HTML_VerticalScroll_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		self->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "unScrollMax") == 0) {
		self->unScrollMax = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "unScrollCurrent") == 0) {
		self->unScrollCurrent = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "flPageScale") == 0) {
		self->flPageScale = static_cast<float>(luaL_checknumber(L, 3));
		return 0;
	}
	if (strcmp(key, "bVisible") == 0) {
		self->bVisible = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "unPageSize") == 0) {
		self->unPageSize = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "HTML_VerticalScroll_t has no field '%%s'", key);
}

EXTERN int luasteam_newHTML_VerticalScroll_t(lua_State *L) {
	HTML_VerticalScroll_t *ptr = (HTML_VerticalScroll_t*)lua_newuserdata(L, sizeof(HTML_VerticalScroll_t));
	new (ptr) HTML_VerticalScroll_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "unBrowserHandle");
		if (!lua_isnil(L, -1)) {
			ptr->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "unScrollMax");
		if (!lua_isnil(L, -1)) {
			ptr->unScrollMax = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "unScrollCurrent");
		if (!lua_isnil(L, -1)) {
			ptr->unScrollCurrent = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "flPageScale");
		if (!lua_isnil(L, -1)) {
			ptr->flPageScale = static_cast<float>(luaL_checknumber(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "bVisible");
		if (!lua_isnil(L, -1)) {
			ptr->bVisible = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "unPageSize");
		if (!lua_isnil(L, -1)) {
			ptr->unPageSize = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_VerticalScroll_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int HTML_LinkAtPosition_tMetatable_ref = LUA_NOREF;

static int HTML_LinkAtPosition_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	HTML_LinkAtPosition_t *self = (HTML_LinkAtPosition_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		lua_pushinteger(L, self->unBrowserHandle);
		return 1;
	}
	if (strcmp(key, "x") == 0) {
		lua_pushinteger(L, self->x);
		return 1;
	}
	if (strcmp(key, "y") == 0) {
		lua_pushinteger(L, self->y);
		return 1;
	}
	if (strcmp(key, "pchURL") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->pchURL));
		return 1;
	}
	if (strcmp(key, "bInput") == 0) {
		lua_pushboolean(L, self->bInput);
		return 1;
	}
	if (strcmp(key, "bLiveLink") == 0) {
		lua_pushboolean(L, self->bLiveLink);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int HTML_LinkAtPosition_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	HTML_LinkAtPosition_t *self = (HTML_LinkAtPosition_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		self->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "x") == 0) {
		self->x = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "y") == 0) {
		self->y = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "bInput") == 0) {
		self->bInput = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "bLiveLink") == 0) {
		self->bLiveLink = lua_toboolean(L, 3);
		return 0;
	}
	return luaL_error(L, "HTML_LinkAtPosition_t has no field '%%s'", key);
}

EXTERN int luasteam_newHTML_LinkAtPosition_t(lua_State *L) {
	HTML_LinkAtPosition_t *ptr = (HTML_LinkAtPosition_t*)lua_newuserdata(L, sizeof(HTML_LinkAtPosition_t));
	new (ptr) HTML_LinkAtPosition_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "unBrowserHandle");
		if (!lua_isnil(L, -1)) {
			ptr->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "x");
		if (!lua_isnil(L, -1)) {
			ptr->x = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "y");
		if (!lua_isnil(L, -1)) {
			ptr->y = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "bInput");
		if (!lua_isnil(L, -1)) {
			ptr->bInput = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "bLiveLink");
		if (!lua_isnil(L, -1)) {
			ptr->bLiveLink = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_LinkAtPosition_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int HTML_JSAlert_tMetatable_ref = LUA_NOREF;

static int HTML_JSAlert_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	HTML_JSAlert_t *self = (HTML_JSAlert_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		lua_pushinteger(L, self->unBrowserHandle);
		return 1;
	}
	if (strcmp(key, "pchMessage") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->pchMessage));
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int HTML_JSAlert_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	HTML_JSAlert_t *self = (HTML_JSAlert_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		self->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "HTML_JSAlert_t has no field '%%s'", key);
}

EXTERN int luasteam_newHTML_JSAlert_t(lua_State *L) {
	HTML_JSAlert_t *ptr = (HTML_JSAlert_t*)lua_newuserdata(L, sizeof(HTML_JSAlert_t));
	new (ptr) HTML_JSAlert_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "unBrowserHandle");
		if (!lua_isnil(L, -1)) {
			ptr->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_JSAlert_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int HTML_JSConfirm_tMetatable_ref = LUA_NOREF;

static int HTML_JSConfirm_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	HTML_JSConfirm_t *self = (HTML_JSConfirm_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		lua_pushinteger(L, self->unBrowserHandle);
		return 1;
	}
	if (strcmp(key, "pchMessage") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->pchMessage));
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int HTML_JSConfirm_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	HTML_JSConfirm_t *self = (HTML_JSConfirm_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		self->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "HTML_JSConfirm_t has no field '%%s'", key);
}

EXTERN int luasteam_newHTML_JSConfirm_t(lua_State *L) {
	HTML_JSConfirm_t *ptr = (HTML_JSConfirm_t*)lua_newuserdata(L, sizeof(HTML_JSConfirm_t));
	new (ptr) HTML_JSConfirm_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "unBrowserHandle");
		if (!lua_isnil(L, -1)) {
			ptr->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_JSConfirm_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int HTML_FileOpenDialog_tMetatable_ref = LUA_NOREF;

static int HTML_FileOpenDialog_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	HTML_FileOpenDialog_t *self = (HTML_FileOpenDialog_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		lua_pushinteger(L, self->unBrowserHandle);
		return 1;
	}
	if (strcmp(key, "pchTitle") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->pchTitle));
		return 1;
	}
	if (strcmp(key, "pchInitialFile") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->pchInitialFile));
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int HTML_FileOpenDialog_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	HTML_FileOpenDialog_t *self = (HTML_FileOpenDialog_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		self->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "HTML_FileOpenDialog_t has no field '%%s'", key);
}

EXTERN int luasteam_newHTML_FileOpenDialog_t(lua_State *L) {
	HTML_FileOpenDialog_t *ptr = (HTML_FileOpenDialog_t*)lua_newuserdata(L, sizeof(HTML_FileOpenDialog_t));
	new (ptr) HTML_FileOpenDialog_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "unBrowserHandle");
		if (!lua_isnil(L, -1)) {
			ptr->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_FileOpenDialog_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int HTML_NewWindow_tMetatable_ref = LUA_NOREF;

static int HTML_NewWindow_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	HTML_NewWindow_t *self = (HTML_NewWindow_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		lua_pushinteger(L, self->unBrowserHandle);
		return 1;
	}
	if (strcmp(key, "pchURL") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->pchURL));
		return 1;
	}
	if (strcmp(key, "unX") == 0) {
		lua_pushinteger(L, self->unX);
		return 1;
	}
	if (strcmp(key, "unY") == 0) {
		lua_pushinteger(L, self->unY);
		return 1;
	}
	if (strcmp(key, "unWide") == 0) {
		lua_pushinteger(L, self->unWide);
		return 1;
	}
	if (strcmp(key, "unTall") == 0) {
		lua_pushinteger(L, self->unTall);
		return 1;
	}
	if (strcmp(key, "unNewWindow_BrowserHandle_IGNORE") == 0) {
		lua_pushinteger(L, self->unNewWindow_BrowserHandle_IGNORE);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int HTML_NewWindow_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	HTML_NewWindow_t *self = (HTML_NewWindow_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		self->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "unX") == 0) {
		self->unX = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "unY") == 0) {
		self->unY = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "unWide") == 0) {
		self->unWide = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "unTall") == 0) {
		self->unTall = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "unNewWindow_BrowserHandle_IGNORE") == 0) {
		self->unNewWindow_BrowserHandle_IGNORE = static_cast<HHTMLBrowser>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "HTML_NewWindow_t has no field '%%s'", key);
}

EXTERN int luasteam_newHTML_NewWindow_t(lua_State *L) {
	HTML_NewWindow_t *ptr = (HTML_NewWindow_t*)lua_newuserdata(L, sizeof(HTML_NewWindow_t));
	new (ptr) HTML_NewWindow_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "unBrowserHandle");
		if (!lua_isnil(L, -1)) {
			ptr->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "unX");
		if (!lua_isnil(L, -1)) {
			ptr->unX = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "unY");
		if (!lua_isnil(L, -1)) {
			ptr->unY = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "unWide");
		if (!lua_isnil(L, -1)) {
			ptr->unWide = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "unTall");
		if (!lua_isnil(L, -1)) {
			ptr->unTall = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "unNewWindow_BrowserHandle_IGNORE");
		if (!lua_isnil(L, -1)) {
			ptr->unNewWindow_BrowserHandle_IGNORE = static_cast<HHTMLBrowser>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_NewWindow_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int HTML_SetCursor_tMetatable_ref = LUA_NOREF;

static int HTML_SetCursor_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	HTML_SetCursor_t *self = (HTML_SetCursor_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		lua_pushinteger(L, self->unBrowserHandle);
		return 1;
	}
	if (strcmp(key, "eMouseCursor") == 0) {
		lua_pushinteger(L, self->eMouseCursor);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int HTML_SetCursor_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	HTML_SetCursor_t *self = (HTML_SetCursor_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		self->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "eMouseCursor") == 0) {
		self->eMouseCursor = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "HTML_SetCursor_t has no field '%%s'", key);
}

EXTERN int luasteam_newHTML_SetCursor_t(lua_State *L) {
	HTML_SetCursor_t *ptr = (HTML_SetCursor_t*)lua_newuserdata(L, sizeof(HTML_SetCursor_t));
	new (ptr) HTML_SetCursor_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "unBrowserHandle");
		if (!lua_isnil(L, -1)) {
			ptr->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "eMouseCursor");
		if (!lua_isnil(L, -1)) {
			ptr->eMouseCursor = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_SetCursor_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int HTML_StatusText_tMetatable_ref = LUA_NOREF;

static int HTML_StatusText_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	HTML_StatusText_t *self = (HTML_StatusText_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		lua_pushinteger(L, self->unBrowserHandle);
		return 1;
	}
	if (strcmp(key, "pchMsg") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->pchMsg));
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int HTML_StatusText_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	HTML_StatusText_t *self = (HTML_StatusText_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		self->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "HTML_StatusText_t has no field '%%s'", key);
}

EXTERN int luasteam_newHTML_StatusText_t(lua_State *L) {
	HTML_StatusText_t *ptr = (HTML_StatusText_t*)lua_newuserdata(L, sizeof(HTML_StatusText_t));
	new (ptr) HTML_StatusText_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "unBrowserHandle");
		if (!lua_isnil(L, -1)) {
			ptr->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_StatusText_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int HTML_ShowToolTip_tMetatable_ref = LUA_NOREF;

static int HTML_ShowToolTip_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	HTML_ShowToolTip_t *self = (HTML_ShowToolTip_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		lua_pushinteger(L, self->unBrowserHandle);
		return 1;
	}
	if (strcmp(key, "pchMsg") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->pchMsg));
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int HTML_ShowToolTip_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	HTML_ShowToolTip_t *self = (HTML_ShowToolTip_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		self->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "HTML_ShowToolTip_t has no field '%%s'", key);
}

EXTERN int luasteam_newHTML_ShowToolTip_t(lua_State *L) {
	HTML_ShowToolTip_t *ptr = (HTML_ShowToolTip_t*)lua_newuserdata(L, sizeof(HTML_ShowToolTip_t));
	new (ptr) HTML_ShowToolTip_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "unBrowserHandle");
		if (!lua_isnil(L, -1)) {
			ptr->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_ShowToolTip_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int HTML_UpdateToolTip_tMetatable_ref = LUA_NOREF;

static int HTML_UpdateToolTip_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	HTML_UpdateToolTip_t *self = (HTML_UpdateToolTip_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		lua_pushinteger(L, self->unBrowserHandle);
		return 1;
	}
	if (strcmp(key, "pchMsg") == 0) {
		lua_pushstring(L, reinterpret_cast<const char*>(self->pchMsg));
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int HTML_UpdateToolTip_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	HTML_UpdateToolTip_t *self = (HTML_UpdateToolTip_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		self->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "HTML_UpdateToolTip_t has no field '%%s'", key);
}

EXTERN int luasteam_newHTML_UpdateToolTip_t(lua_State *L) {
	HTML_UpdateToolTip_t *ptr = (HTML_UpdateToolTip_t*)lua_newuserdata(L, sizeof(HTML_UpdateToolTip_t));
	new (ptr) HTML_UpdateToolTip_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "unBrowserHandle");
		if (!lua_isnil(L, -1)) {
			ptr->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_UpdateToolTip_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int HTML_HideToolTip_tMetatable_ref = LUA_NOREF;

static int HTML_HideToolTip_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	HTML_HideToolTip_t *self = (HTML_HideToolTip_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		lua_pushinteger(L, self->unBrowserHandle);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int HTML_HideToolTip_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	HTML_HideToolTip_t *self = (HTML_HideToolTip_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		self->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "HTML_HideToolTip_t has no field '%%s'", key);
}

EXTERN int luasteam_newHTML_HideToolTip_t(lua_State *L) {
	HTML_HideToolTip_t *ptr = (HTML_HideToolTip_t*)lua_newuserdata(L, sizeof(HTML_HideToolTip_t));
	new (ptr) HTML_HideToolTip_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "unBrowserHandle");
		if (!lua_isnil(L, -1)) {
			ptr->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_HideToolTip_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int HTML_BrowserRestarted_tMetatable_ref = LUA_NOREF;

static int HTML_BrowserRestarted_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	HTML_BrowserRestarted_t *self = (HTML_BrowserRestarted_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		lua_pushinteger(L, self->unBrowserHandle);
		return 1;
	}
	if (strcmp(key, "unOldBrowserHandle") == 0) {
		lua_pushinteger(L, self->unOldBrowserHandle);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int HTML_BrowserRestarted_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	HTML_BrowserRestarted_t *self = (HTML_BrowserRestarted_t*)lua_touserdata(L, 1);
	if (strcmp(key, "unBrowserHandle") == 0) {
		self->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "unOldBrowserHandle") == 0) {
		self->unOldBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "HTML_BrowserRestarted_t has no field '%%s'", key);
}

EXTERN int luasteam_newHTML_BrowserRestarted_t(lua_State *L) {
	HTML_BrowserRestarted_t *ptr = (HTML_BrowserRestarted_t*)lua_newuserdata(L, sizeof(HTML_BrowserRestarted_t));
	new (ptr) HTML_BrowserRestarted_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "unBrowserHandle");
		if (!lua_isnil(L, -1)) {
			ptr->unBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "unOldBrowserHandle");
		if (!lua_isnil(L, -1)) {
			ptr->unOldBrowserHandle = static_cast<HHTMLBrowser>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_BrowserRestarted_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamInventoryResultReady_tMetatable_ref = LUA_NOREF;

static int SteamInventoryResultReady_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamInventoryResultReady_t *self = (SteamInventoryResultReady_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_handle") == 0) {
		lua_pushinteger(L, self->m_handle);
		return 1;
	}
	if (strcmp(key, "m_result") == 0) {
		lua_pushinteger(L, self->m_result);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamInventoryResultReady_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamInventoryResultReady_t *self = (SteamInventoryResultReady_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_handle") == 0) {
		self->m_handle = static_cast<SteamInventoryResult_t>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_result") == 0) {
		self->m_result = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "SteamInventoryResultReady_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamInventoryResultReady_t(lua_State *L) {
	SteamInventoryResultReady_t *ptr = (SteamInventoryResultReady_t*)lua_newuserdata(L, sizeof(SteamInventoryResultReady_t));
	new (ptr) SteamInventoryResultReady_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_handle");
		if (!lua_isnil(L, -1)) {
			ptr->m_handle = static_cast<SteamInventoryResult_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_result");
		if (!lua_isnil(L, -1)) {
			ptr->m_result = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInventoryResultReady_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamInventoryFullUpdate_tMetatable_ref = LUA_NOREF;

static int SteamInventoryFullUpdate_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamInventoryFullUpdate_t *self = (SteamInventoryFullUpdate_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_handle") == 0) {
		lua_pushinteger(L, self->m_handle);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamInventoryFullUpdate_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamInventoryFullUpdate_t *self = (SteamInventoryFullUpdate_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_handle") == 0) {
		self->m_handle = static_cast<SteamInventoryResult_t>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "SteamInventoryFullUpdate_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamInventoryFullUpdate_t(lua_State *L) {
	SteamInventoryFullUpdate_t *ptr = (SteamInventoryFullUpdate_t*)lua_newuserdata(L, sizeof(SteamInventoryFullUpdate_t));
	new (ptr) SteamInventoryFullUpdate_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_handle");
		if (!lua_isnil(L, -1)) {
			ptr->m_handle = static_cast<SteamInventoryResult_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInventoryFullUpdate_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamInventoryDefinitionUpdate_tMetatable_ref = LUA_NOREF;

static int SteamInventoryDefinitionUpdate_t_index(lua_State *L) {
	lua_pushnil(L);
	return 1;
}

EXTERN int luasteam_newSteamInventoryDefinitionUpdate_t(lua_State *L) {
	SteamInventoryDefinitionUpdate_t *ptr = (SteamInventoryDefinitionUpdate_t*)lua_newuserdata(L, sizeof(SteamInventoryDefinitionUpdate_t));
	new (ptr) SteamInventoryDefinitionUpdate_t();
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInventoryDefinitionUpdate_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamInventoryEligiblePromoItemDefIDs_tMetatable_ref = LUA_NOREF;

static int SteamInventoryEligiblePromoItemDefIDs_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamInventoryEligiblePromoItemDefIDs_t *self = (SteamInventoryEligiblePromoItemDefIDs_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_result") == 0) {
		lua_pushinteger(L, self->m_result);
		return 1;
	}
	if (strcmp(key, "m_steamID") == 0) {
		luasteam::pushuint64(L, self->m_steamID.ConvertToUint64());
		return 1;
	}
	if (strcmp(key, "m_numEligiblePromoItemDefs") == 0) {
		lua_pushinteger(L, self->m_numEligiblePromoItemDefs);
		return 1;
	}
	if (strcmp(key, "m_bCachedData") == 0) {
		lua_pushboolean(L, self->m_bCachedData);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamInventoryEligiblePromoItemDefIDs_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamInventoryEligiblePromoItemDefIDs_t *self = (SteamInventoryEligiblePromoItemDefIDs_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_result") == 0) {
		self->m_result = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_steamID") == 0) {
		self->m_steamID = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	if (strcmp(key, "m_numEligiblePromoItemDefs") == 0) {
		self->m_numEligiblePromoItemDefs = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bCachedData") == 0) {
		self->m_bCachedData = lua_toboolean(L, 3);
		return 0;
	}
	return luaL_error(L, "SteamInventoryEligiblePromoItemDefIDs_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamInventoryEligiblePromoItemDefIDs_t(lua_State *L) {
	SteamInventoryEligiblePromoItemDefIDs_t *ptr = (SteamInventoryEligiblePromoItemDefIDs_t*)lua_newuserdata(L, sizeof(SteamInventoryEligiblePromoItemDefIDs_t));
	new (ptr) SteamInventoryEligiblePromoItemDefIDs_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_result");
		if (!lua_isnil(L, -1)) {
			ptr->m_result = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_steamID");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamID = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_numEligiblePromoItemDefs");
		if (!lua_isnil(L, -1)) {
			ptr->m_numEligiblePromoItemDefs = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bCachedData");
		if (!lua_isnil(L, -1)) {
			ptr->m_bCachedData = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInventoryEligiblePromoItemDefIDs_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamInventoryStartPurchaseResult_tMetatable_ref = LUA_NOREF;

static int SteamInventoryStartPurchaseResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamInventoryStartPurchaseResult_t *self = (SteamInventoryStartPurchaseResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_result") == 0) {
		lua_pushinteger(L, self->m_result);
		return 1;
	}
	if (strcmp(key, "m_ulOrderID") == 0) {
		luasteam::pushuint64(L, self->m_ulOrderID);
		return 1;
	}
	if (strcmp(key, "m_ulTransID") == 0) {
		luasteam::pushuint64(L, self->m_ulTransID);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamInventoryStartPurchaseResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamInventoryStartPurchaseResult_t *self = (SteamInventoryStartPurchaseResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_result") == 0) {
		self->m_result = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_ulOrderID") == 0) {
		self->m_ulOrderID = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_ulTransID") == 0) {
		self->m_ulTransID = luasteam::checkuint64(L, 3);
		return 0;
	}
	return luaL_error(L, "SteamInventoryStartPurchaseResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamInventoryStartPurchaseResult_t(lua_State *L) {
	SteamInventoryStartPurchaseResult_t *ptr = (SteamInventoryStartPurchaseResult_t*)lua_newuserdata(L, sizeof(SteamInventoryStartPurchaseResult_t));
	new (ptr) SteamInventoryStartPurchaseResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_result");
		if (!lua_isnil(L, -1)) {
			ptr->m_result = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_ulOrderID");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulOrderID = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_ulTransID");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulTransID = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInventoryStartPurchaseResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamInventoryRequestPricesResult_tMetatable_ref = LUA_NOREF;

static int SteamInventoryRequestPricesResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamInventoryRequestPricesResult_t *self = (SteamInventoryRequestPricesResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_result") == 0) {
		lua_pushinteger(L, self->m_result);
		return 1;
	}
	if (strcmp(key, "m_rgchCurrency") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_rgchCurrency), 4);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamInventoryRequestPricesResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamInventoryRequestPricesResult_t *self = (SteamInventoryRequestPricesResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_result") == 0) {
		self->m_result = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_rgchCurrency") == 0) {
		size_t _len__tmp74;
		const char *_tmp74 = luaL_checklstring(L, 3, &_len__tmp74);
		if (_len__tmp74 > sizeof(self->m_rgchCurrency)) luaL_error(L, "String too long");
		memcpy(self->m_rgchCurrency, _tmp74, std::min(_len__tmp74 + 1, sizeof(self->m_rgchCurrency)));
		return 0;
	}
	return luaL_error(L, "SteamInventoryRequestPricesResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamInventoryRequestPricesResult_t(lua_State *L) {
	SteamInventoryRequestPricesResult_t *ptr = (SteamInventoryRequestPricesResult_t*)lua_newuserdata(L, sizeof(SteamInventoryRequestPricesResult_t));
	new (ptr) SteamInventoryRequestPricesResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_result");
		if (!lua_isnil(L, -1)) {
			ptr->m_result = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rgchCurrency");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp75;
			const char *_tmp75 = luaL_checklstring(L, -1, &_len__tmp75);
			if (_len__tmp75 > sizeof(ptr->m_rgchCurrency)) luaL_error(L, "String too long");
			memcpy(ptr->m_rgchCurrency, _tmp75, std::min(_len__tmp75 + 1, sizeof(ptr->m_rgchCurrency)));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInventoryRequestPricesResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamTimelineGamePhaseRecordingExists_tMetatable_ref = LUA_NOREF;

static int SteamTimelineGamePhaseRecordingExists_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamTimelineGamePhaseRecordingExists_t *self = (SteamTimelineGamePhaseRecordingExists_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_rgchPhaseID") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_rgchPhaseID), 64);
		return 1;
	}
	if (strcmp(key, "m_ulRecordingMS") == 0) {
		luasteam::pushuint64(L, self->m_ulRecordingMS);
		return 1;
	}
	if (strcmp(key, "m_ulLongestClipMS") == 0) {
		luasteam::pushuint64(L, self->m_ulLongestClipMS);
		return 1;
	}
	if (strcmp(key, "m_unClipCount") == 0) {
		lua_pushinteger(L, self->m_unClipCount);
		return 1;
	}
	if (strcmp(key, "m_unScreenshotCount") == 0) {
		lua_pushinteger(L, self->m_unScreenshotCount);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamTimelineGamePhaseRecordingExists_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamTimelineGamePhaseRecordingExists_t *self = (SteamTimelineGamePhaseRecordingExists_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_rgchPhaseID") == 0) {
		size_t _len__tmp76;
		const char *_tmp76 = luaL_checklstring(L, 3, &_len__tmp76);
		if (_len__tmp76 > sizeof(self->m_rgchPhaseID)) luaL_error(L, "String too long");
		memcpy(self->m_rgchPhaseID, _tmp76, std::min(_len__tmp76 + 1, sizeof(self->m_rgchPhaseID)));
		return 0;
	}
	if (strcmp(key, "m_ulRecordingMS") == 0) {
		self->m_ulRecordingMS = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_ulLongestClipMS") == 0) {
		self->m_ulLongestClipMS = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_unClipCount") == 0) {
		self->m_unClipCount = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_unScreenshotCount") == 0) {
		self->m_unScreenshotCount = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "SteamTimelineGamePhaseRecordingExists_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamTimelineGamePhaseRecordingExists_t(lua_State *L) {
	SteamTimelineGamePhaseRecordingExists_t *ptr = (SteamTimelineGamePhaseRecordingExists_t*)lua_newuserdata(L, sizeof(SteamTimelineGamePhaseRecordingExists_t));
	new (ptr) SteamTimelineGamePhaseRecordingExists_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_rgchPhaseID");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp77;
			const char *_tmp77 = luaL_checklstring(L, -1, &_len__tmp77);
			if (_len__tmp77 > sizeof(ptr->m_rgchPhaseID)) luaL_error(L, "String too long");
			memcpy(ptr->m_rgchPhaseID, _tmp77, std::min(_len__tmp77 + 1, sizeof(ptr->m_rgchPhaseID)));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_ulRecordingMS");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulRecordingMS = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_ulLongestClipMS");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulLongestClipMS = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unClipCount");
		if (!lua_isnil(L, -1)) {
			ptr->m_unClipCount = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unScreenshotCount");
		if (!lua_isnil(L, -1)) {
			ptr->m_unScreenshotCount = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamTimelineGamePhaseRecordingExists_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamTimelineEventRecordingExists_tMetatable_ref = LUA_NOREF;

static int SteamTimelineEventRecordingExists_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamTimelineEventRecordingExists_t *self = (SteamTimelineEventRecordingExists_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_ulEventID") == 0) {
		luasteam::pushuint64(L, self->m_ulEventID);
		return 1;
	}
	if (strcmp(key, "m_bRecordingExists") == 0) {
		lua_pushboolean(L, self->m_bRecordingExists);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamTimelineEventRecordingExists_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamTimelineEventRecordingExists_t *self = (SteamTimelineEventRecordingExists_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_ulEventID") == 0) {
		self->m_ulEventID = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_bRecordingExists") == 0) {
		self->m_bRecordingExists = lua_toboolean(L, 3);
		return 0;
	}
	return luaL_error(L, "SteamTimelineEventRecordingExists_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamTimelineEventRecordingExists_t(lua_State *L) {
	SteamTimelineEventRecordingExists_t *ptr = (SteamTimelineEventRecordingExists_t*)lua_newuserdata(L, sizeof(SteamTimelineEventRecordingExists_t));
	new (ptr) SteamTimelineEventRecordingExists_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_ulEventID");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulEventID = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bRecordingExists");
		if (!lua_isnil(L, -1)) {
			ptr->m_bRecordingExists = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamTimelineEventRecordingExists_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int GetVideoURLResult_tMetatable_ref = LUA_NOREF;

static int GetVideoURLResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	GetVideoURLResult_t *self = (GetVideoURLResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_unVideoAppID") == 0) {
		lua_pushinteger(L, self->m_unVideoAppID);
		return 1;
	}
	if (strcmp(key, "m_rgchURL") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_rgchURL), 256);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int GetVideoURLResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	GetVideoURLResult_t *self = (GetVideoURLResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_unVideoAppID") == 0) {
		self->m_unVideoAppID = static_cast<AppId_t>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_rgchURL") == 0) {
		size_t _len__tmp78;
		const char *_tmp78 = luaL_checklstring(L, 3, &_len__tmp78);
		if (_len__tmp78 > sizeof(self->m_rgchURL)) luaL_error(L, "String too long");
		memcpy(self->m_rgchURL, _tmp78, std::min(_len__tmp78 + 1, sizeof(self->m_rgchURL)));
		return 0;
	}
	return luaL_error(L, "GetVideoURLResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newGetVideoURLResult_t(lua_State *L) {
	GetVideoURLResult_t *ptr = (GetVideoURLResult_t*)lua_newuserdata(L, sizeof(GetVideoURLResult_t));
	new (ptr) GetVideoURLResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unVideoAppID");
		if (!lua_isnil(L, -1)) {
			ptr->m_unVideoAppID = static_cast<AppId_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rgchURL");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp79;
			const char *_tmp79 = luaL_checklstring(L, -1, &_len__tmp79);
			if (_len__tmp79 > sizeof(ptr->m_rgchURL)) luaL_error(L, "String too long");
			memcpy(ptr->m_rgchURL, _tmp79, std::min(_len__tmp79 + 1, sizeof(ptr->m_rgchURL)));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, GetVideoURLResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int GetOPFSettingsResult_tMetatable_ref = LUA_NOREF;

static int GetOPFSettingsResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	GetOPFSettingsResult_t *self = (GetOPFSettingsResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_unVideoAppID") == 0) {
		lua_pushinteger(L, self->m_unVideoAppID);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int GetOPFSettingsResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	GetOPFSettingsResult_t *self = (GetOPFSettingsResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_unVideoAppID") == 0) {
		self->m_unVideoAppID = static_cast<AppId_t>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "GetOPFSettingsResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newGetOPFSettingsResult_t(lua_State *L) {
	GetOPFSettingsResult_t *ptr = (GetOPFSettingsResult_t*)lua_newuserdata(L, sizeof(GetOPFSettingsResult_t));
	new (ptr) GetOPFSettingsResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unVideoAppID");
		if (!lua_isnil(L, -1)) {
			ptr->m_unVideoAppID = static_cast<AppId_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, GetOPFSettingsResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int BroadcastUploadStart_tMetatable_ref = LUA_NOREF;

static int BroadcastUploadStart_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	BroadcastUploadStart_t *self = (BroadcastUploadStart_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_bIsRTMP") == 0) {
		lua_pushboolean(L, self->m_bIsRTMP);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int BroadcastUploadStart_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	BroadcastUploadStart_t *self = (BroadcastUploadStart_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_bIsRTMP") == 0) {
		self->m_bIsRTMP = lua_toboolean(L, 3);
		return 0;
	}
	return luaL_error(L, "BroadcastUploadStart_t has no field '%%s'", key);
}

EXTERN int luasteam_newBroadcastUploadStart_t(lua_State *L) {
	BroadcastUploadStart_t *ptr = (BroadcastUploadStart_t*)lua_newuserdata(L, sizeof(BroadcastUploadStart_t));
	new (ptr) BroadcastUploadStart_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_bIsRTMP");
		if (!lua_isnil(L, -1)) {
			ptr->m_bIsRTMP = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, BroadcastUploadStart_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int BroadcastUploadStop_tMetatable_ref = LUA_NOREF;

static int BroadcastUploadStop_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	BroadcastUploadStop_t *self = (BroadcastUploadStop_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int BroadcastUploadStop_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	BroadcastUploadStop_t *self = (BroadcastUploadStop_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EBroadcastUploadResult>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "BroadcastUploadStop_t has no field '%%s'", key);
}

EXTERN int luasteam_newBroadcastUploadStop_t(lua_State *L) {
	BroadcastUploadStop_t *ptr = (BroadcastUploadStop_t*)lua_newuserdata(L, sizeof(BroadcastUploadStop_t));
	new (ptr) BroadcastUploadStop_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EBroadcastUploadResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, BroadcastUploadStop_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamParentalSettingsChanged_tMetatable_ref = LUA_NOREF;

static int SteamParentalSettingsChanged_t_index(lua_State *L) {
	lua_pushnil(L);
	return 1;
}

EXTERN int luasteam_newSteamParentalSettingsChanged_t(lua_State *L) {
	SteamParentalSettingsChanged_t *ptr = (SteamParentalSettingsChanged_t*)lua_newuserdata(L, sizeof(SteamParentalSettingsChanged_t));
	new (ptr) SteamParentalSettingsChanged_t();
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamParentalSettingsChanged_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamRemotePlaySessionConnected_tMetatable_ref = LUA_NOREF;

static int SteamRemotePlaySessionConnected_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamRemotePlaySessionConnected_t *self = (SteamRemotePlaySessionConnected_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_unSessionID") == 0) {
		lua_pushinteger(L, self->m_unSessionID);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamRemotePlaySessionConnected_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamRemotePlaySessionConnected_t *self = (SteamRemotePlaySessionConnected_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_unSessionID") == 0) {
		self->m_unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "SteamRemotePlaySessionConnected_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamRemotePlaySessionConnected_t(lua_State *L) {
	SteamRemotePlaySessionConnected_t *ptr = (SteamRemotePlaySessionConnected_t*)lua_newuserdata(L, sizeof(SteamRemotePlaySessionConnected_t));
	new (ptr) SteamRemotePlaySessionConnected_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_unSessionID");
		if (!lua_isnil(L, -1)) {
			ptr->m_unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamRemotePlaySessionConnected_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamRemotePlaySessionDisconnected_tMetatable_ref = LUA_NOREF;

static int SteamRemotePlaySessionDisconnected_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamRemotePlaySessionDisconnected_t *self = (SteamRemotePlaySessionDisconnected_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_unSessionID") == 0) {
		lua_pushinteger(L, self->m_unSessionID);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamRemotePlaySessionDisconnected_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamRemotePlaySessionDisconnected_t *self = (SteamRemotePlaySessionDisconnected_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_unSessionID") == 0) {
		self->m_unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "SteamRemotePlaySessionDisconnected_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamRemotePlaySessionDisconnected_t(lua_State *L) {
	SteamRemotePlaySessionDisconnected_t *ptr = (SteamRemotePlaySessionDisconnected_t*)lua_newuserdata(L, sizeof(SteamRemotePlaySessionDisconnected_t));
	new (ptr) SteamRemotePlaySessionDisconnected_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_unSessionID");
		if (!lua_isnil(L, -1)) {
			ptr->m_unSessionID = static_cast<RemotePlaySessionID_t>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamRemotePlaySessionDisconnected_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamRemotePlayTogetherGuestInvite_tMetatable_ref = LUA_NOREF;

static int SteamRemotePlayTogetherGuestInvite_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamRemotePlayTogetherGuestInvite_t *self = (SteamRemotePlayTogetherGuestInvite_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_szConnectURL") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_szConnectURL), 1024);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamRemotePlayTogetherGuestInvite_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamRemotePlayTogetherGuestInvite_t *self = (SteamRemotePlayTogetherGuestInvite_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_szConnectURL") == 0) {
		size_t _len__tmp80;
		const char *_tmp80 = luaL_checklstring(L, 3, &_len__tmp80);
		if (_len__tmp80 > sizeof(self->m_szConnectURL)) luaL_error(L, "String too long");
		memcpy(self->m_szConnectURL, _tmp80, std::min(_len__tmp80 + 1, sizeof(self->m_szConnectURL)));
		return 0;
	}
	return luaL_error(L, "SteamRemotePlayTogetherGuestInvite_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamRemotePlayTogetherGuestInvite_t(lua_State *L) {
	SteamRemotePlayTogetherGuestInvite_t *ptr = (SteamRemotePlayTogetherGuestInvite_t*)lua_newuserdata(L, sizeof(SteamRemotePlayTogetherGuestInvite_t));
	new (ptr) SteamRemotePlayTogetherGuestInvite_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_szConnectURL");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp81;
			const char *_tmp81 = luaL_checklstring(L, -1, &_len__tmp81);
			if (_len__tmp81 > sizeof(ptr->m_szConnectURL)) luaL_error(L, "String too long");
			memcpy(ptr->m_szConnectURL, _tmp81, std::min(_len__tmp81 + 1, sizeof(ptr->m_szConnectURL)));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamRemotePlayTogetherGuestInvite_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamNetworkingMessagesSessionRequest_tMetatable_ref = LUA_NOREF;

static int SteamNetworkingMessagesSessionRequest_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamNetworkingMessagesSessionRequest_t *self = (SteamNetworkingMessagesSessionRequest_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_identityRemote") == 0) {
		luasteam::push_SteamNetworkingIdentity(L, self->m_identityRemote);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamNetworkingMessagesSessionRequest_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamNetworkingMessagesSessionRequest_t *self = (SteamNetworkingMessagesSessionRequest_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_identityRemote") == 0) {
		self->m_identityRemote = luasteam::check_SteamNetworkingIdentity(L, 3);
		return 0;
	}
	return luaL_error(L, "SteamNetworkingMessagesSessionRequest_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamNetworkingMessagesSessionRequest_t(lua_State *L) {
	SteamNetworkingMessagesSessionRequest_t *ptr = (SteamNetworkingMessagesSessionRequest_t*)lua_newuserdata(L, sizeof(SteamNetworkingMessagesSessionRequest_t));
	new (ptr) SteamNetworkingMessagesSessionRequest_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_identityRemote");
		if (!lua_isnil(L, -1)) {
			ptr->m_identityRemote = luasteam::check_SteamNetworkingIdentity(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetworkingMessagesSessionRequest_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamNetworkingMessagesSessionFailed_tMetatable_ref = LUA_NOREF;

static int SteamNetworkingMessagesSessionFailed_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamNetworkingMessagesSessionFailed_t *self = (SteamNetworkingMessagesSessionFailed_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_info") == 0) {
		luasteam::push_SteamNetConnectionInfo_t(L, self->m_info);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamNetworkingMessagesSessionFailed_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamNetworkingMessagesSessionFailed_t *self = (SteamNetworkingMessagesSessionFailed_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_info") == 0) {
		self->m_info = luasteam::check_SteamNetConnectionInfo_t(L, 3);
		return 0;
	}
	return luaL_error(L, "SteamNetworkingMessagesSessionFailed_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamNetworkingMessagesSessionFailed_t(lua_State *L) {
	SteamNetworkingMessagesSessionFailed_t *ptr = (SteamNetworkingMessagesSessionFailed_t*)lua_newuserdata(L, sizeof(SteamNetworkingMessagesSessionFailed_t));
	new (ptr) SteamNetworkingMessagesSessionFailed_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_info");
		if (!lua_isnil(L, -1)) {
			ptr->m_info = luasteam::check_SteamNetConnectionInfo_t(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetworkingMessagesSessionFailed_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamNetConnectionStatusChangedCallback_tMetatable_ref = LUA_NOREF;

static int SteamNetConnectionStatusChangedCallback_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamNetConnectionStatusChangedCallback_t *self = (SteamNetConnectionStatusChangedCallback_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_hConn") == 0) {
		lua_pushinteger(L, self->m_hConn);
		return 1;
	}
	if (strcmp(key, "m_info") == 0) {
		luasteam::push_SteamNetConnectionInfo_t(L, self->m_info);
		return 1;
	}
	if (strcmp(key, "m_eOldState") == 0) {
		lua_pushinteger(L, self->m_eOldState);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamNetConnectionStatusChangedCallback_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamNetConnectionStatusChangedCallback_t *self = (SteamNetConnectionStatusChangedCallback_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_hConn") == 0) {
		self->m_hConn = static_cast<HSteamNetConnection>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_info") == 0) {
		self->m_info = luasteam::check_SteamNetConnectionInfo_t(L, 3);
		return 0;
	}
	if (strcmp(key, "m_eOldState") == 0) {
		self->m_eOldState = static_cast<ESteamNetworkingConnectionState>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "SteamNetConnectionStatusChangedCallback_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamNetConnectionStatusChangedCallback_t(lua_State *L) {
	SteamNetConnectionStatusChangedCallback_t *ptr = (SteamNetConnectionStatusChangedCallback_t*)lua_newuserdata(L, sizeof(SteamNetConnectionStatusChangedCallback_t));
	new (ptr) SteamNetConnectionStatusChangedCallback_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_hConn");
		if (!lua_isnil(L, -1)) {
			ptr->m_hConn = static_cast<HSteamNetConnection>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_info");
		if (!lua_isnil(L, -1)) {
			ptr->m_info = luasteam::check_SteamNetConnectionInfo_t(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eOldState");
		if (!lua_isnil(L, -1)) {
			ptr->m_eOldState = static_cast<ESteamNetworkingConnectionState>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetConnectionStatusChangedCallback_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamNetAuthenticationStatus_tMetatable_ref = LUA_NOREF;

static int SteamNetAuthenticationStatus_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamNetAuthenticationStatus_t *self = (SteamNetAuthenticationStatus_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eAvail") == 0) {
		lua_pushinteger(L, self->m_eAvail);
		return 1;
	}
	if (strcmp(key, "m_debugMsg") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_debugMsg), 256);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamNetAuthenticationStatus_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamNetAuthenticationStatus_t *self = (SteamNetAuthenticationStatus_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eAvail") == 0) {
		self->m_eAvail = static_cast<ESteamNetworkingAvailability>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_debugMsg") == 0) {
		size_t _len__tmp82;
		const char *_tmp82 = luaL_checklstring(L, 3, &_len__tmp82);
		if (_len__tmp82 > sizeof(self->m_debugMsg)) luaL_error(L, "String too long");
		memcpy(self->m_debugMsg, _tmp82, std::min(_len__tmp82 + 1, sizeof(self->m_debugMsg)));
		return 0;
	}
	return luaL_error(L, "SteamNetAuthenticationStatus_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamNetAuthenticationStatus_t(lua_State *L) {
	SteamNetAuthenticationStatus_t *ptr = (SteamNetAuthenticationStatus_t*)lua_newuserdata(L, sizeof(SteamNetAuthenticationStatus_t));
	new (ptr) SteamNetAuthenticationStatus_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eAvail");
		if (!lua_isnil(L, -1)) {
			ptr->m_eAvail = static_cast<ESteamNetworkingAvailability>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_debugMsg");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp83;
			const char *_tmp83 = luaL_checklstring(L, -1, &_len__tmp83);
			if (_len__tmp83 > sizeof(ptr->m_debugMsg)) luaL_error(L, "String too long");
			memcpy(ptr->m_debugMsg, _tmp83, std::min(_len__tmp83 + 1, sizeof(ptr->m_debugMsg)));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetAuthenticationStatus_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamRelayNetworkStatus_tMetatable_ref = LUA_NOREF;

static int SteamRelayNetworkStatus_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamRelayNetworkStatus_t *self = (SteamRelayNetworkStatus_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eAvail") == 0) {
		lua_pushinteger(L, self->m_eAvail);
		return 1;
	}
	if (strcmp(key, "m_bPingMeasurementInProgress") == 0) {
		lua_pushinteger(L, self->m_bPingMeasurementInProgress);
		return 1;
	}
	if (strcmp(key, "m_eAvailNetworkConfig") == 0) {
		lua_pushinteger(L, self->m_eAvailNetworkConfig);
		return 1;
	}
	if (strcmp(key, "m_eAvailAnyRelay") == 0) {
		lua_pushinteger(L, self->m_eAvailAnyRelay);
		return 1;
	}
	if (strcmp(key, "m_debugMsg") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_debugMsg), 256);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamRelayNetworkStatus_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamRelayNetworkStatus_t *self = (SteamRelayNetworkStatus_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eAvail") == 0) {
		self->m_eAvail = static_cast<ESteamNetworkingAvailability>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bPingMeasurementInProgress") == 0) {
		self->m_bPingMeasurementInProgress = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_eAvailNetworkConfig") == 0) {
		self->m_eAvailNetworkConfig = static_cast<ESteamNetworkingAvailability>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_eAvailAnyRelay") == 0) {
		self->m_eAvailAnyRelay = static_cast<ESteamNetworkingAvailability>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_debugMsg") == 0) {
		size_t _len__tmp84;
		const char *_tmp84 = luaL_checklstring(L, 3, &_len__tmp84);
		if (_len__tmp84 > sizeof(self->m_debugMsg)) luaL_error(L, "String too long");
		memcpy(self->m_debugMsg, _tmp84, std::min(_len__tmp84 + 1, sizeof(self->m_debugMsg)));
		return 0;
	}
	return luaL_error(L, "SteamRelayNetworkStatus_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamRelayNetworkStatus_t(lua_State *L) {
	SteamRelayNetworkStatus_t *ptr = (SteamRelayNetworkStatus_t*)lua_newuserdata(L, sizeof(SteamRelayNetworkStatus_t));
	new (ptr) SteamRelayNetworkStatus_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eAvail");
		if (!lua_isnil(L, -1)) {
			ptr->m_eAvail = static_cast<ESteamNetworkingAvailability>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bPingMeasurementInProgress");
		if (!lua_isnil(L, -1)) {
			ptr->m_bPingMeasurementInProgress = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eAvailNetworkConfig");
		if (!lua_isnil(L, -1)) {
			ptr->m_eAvailNetworkConfig = static_cast<ESteamNetworkingAvailability>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eAvailAnyRelay");
		if (!lua_isnil(L, -1)) {
			ptr->m_eAvailAnyRelay = static_cast<ESteamNetworkingAvailability>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_debugMsg");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp85;
			const char *_tmp85 = luaL_checklstring(L, -1, &_len__tmp85);
			if (_len__tmp85 > sizeof(ptr->m_debugMsg)) luaL_error(L, "String too long");
			memcpy(ptr->m_debugMsg, _tmp85, std::min(_len__tmp85 + 1, sizeof(ptr->m_debugMsg)));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamRelayNetworkStatus_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int GSClientApprove_tMetatable_ref = LUA_NOREF;

static int GSClientApprove_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	GSClientApprove_t *self = (GSClientApprove_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_SteamID") == 0) {
		luasteam::pushuint64(L, self->m_SteamID.ConvertToUint64());
		return 1;
	}
	if (strcmp(key, "m_OwnerSteamID") == 0) {
		luasteam::pushuint64(L, self->m_OwnerSteamID.ConvertToUint64());
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int GSClientApprove_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	GSClientApprove_t *self = (GSClientApprove_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_SteamID") == 0) {
		self->m_SteamID = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	if (strcmp(key, "m_OwnerSteamID") == 0) {
		self->m_OwnerSteamID = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	return luaL_error(L, "GSClientApprove_t has no field '%%s'", key);
}

EXTERN int luasteam_newGSClientApprove_t(lua_State *L) {
	GSClientApprove_t *ptr = (GSClientApprove_t*)lua_newuserdata(L, sizeof(GSClientApprove_t));
	new (ptr) GSClientApprove_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_SteamID");
		if (!lua_isnil(L, -1)) {
			ptr->m_SteamID = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_OwnerSteamID");
		if (!lua_isnil(L, -1)) {
			ptr->m_OwnerSteamID = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSClientApprove_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int GSClientDeny_tMetatable_ref = LUA_NOREF;

static int GSClientDeny_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	GSClientDeny_t *self = (GSClientDeny_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_SteamID") == 0) {
		luasteam::pushuint64(L, self->m_SteamID.ConvertToUint64());
		return 1;
	}
	if (strcmp(key, "m_eDenyReason") == 0) {
		lua_pushinteger(L, self->m_eDenyReason);
		return 1;
	}
	if (strcmp(key, "m_rgchOptionalText") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_rgchOptionalText), 128);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int GSClientDeny_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	GSClientDeny_t *self = (GSClientDeny_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_SteamID") == 0) {
		self->m_SteamID = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	if (strcmp(key, "m_eDenyReason") == 0) {
		self->m_eDenyReason = static_cast<EDenyReason>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_rgchOptionalText") == 0) {
		size_t _len__tmp86;
		const char *_tmp86 = luaL_checklstring(L, 3, &_len__tmp86);
		if (_len__tmp86 > sizeof(self->m_rgchOptionalText)) luaL_error(L, "String too long");
		memcpy(self->m_rgchOptionalText, _tmp86, std::min(_len__tmp86 + 1, sizeof(self->m_rgchOptionalText)));
		return 0;
	}
	return luaL_error(L, "GSClientDeny_t has no field '%%s'", key);
}

EXTERN int luasteam_newGSClientDeny_t(lua_State *L) {
	GSClientDeny_t *ptr = (GSClientDeny_t*)lua_newuserdata(L, sizeof(GSClientDeny_t));
	new (ptr) GSClientDeny_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_SteamID");
		if (!lua_isnil(L, -1)) {
			ptr->m_SteamID = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eDenyReason");
		if (!lua_isnil(L, -1)) {
			ptr->m_eDenyReason = static_cast<EDenyReason>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_rgchOptionalText");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp87;
			const char *_tmp87 = luaL_checklstring(L, -1, &_len__tmp87);
			if (_len__tmp87 > sizeof(ptr->m_rgchOptionalText)) luaL_error(L, "String too long");
			memcpy(ptr->m_rgchOptionalText, _tmp87, std::min(_len__tmp87 + 1, sizeof(ptr->m_rgchOptionalText)));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSClientDeny_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int GSClientKick_tMetatable_ref = LUA_NOREF;

static int GSClientKick_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	GSClientKick_t *self = (GSClientKick_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_SteamID") == 0) {
		luasteam::pushuint64(L, self->m_SteamID.ConvertToUint64());
		return 1;
	}
	if (strcmp(key, "m_eDenyReason") == 0) {
		lua_pushinteger(L, self->m_eDenyReason);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int GSClientKick_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	GSClientKick_t *self = (GSClientKick_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_SteamID") == 0) {
		self->m_SteamID = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	if (strcmp(key, "m_eDenyReason") == 0) {
		self->m_eDenyReason = static_cast<EDenyReason>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "GSClientKick_t has no field '%%s'", key);
}

EXTERN int luasteam_newGSClientKick_t(lua_State *L) {
	GSClientKick_t *ptr = (GSClientKick_t*)lua_newuserdata(L, sizeof(GSClientKick_t));
	new (ptr) GSClientKick_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_SteamID");
		if (!lua_isnil(L, -1)) {
			ptr->m_SteamID = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_eDenyReason");
		if (!lua_isnil(L, -1)) {
			ptr->m_eDenyReason = static_cast<EDenyReason>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSClientKick_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int GSClientAchievementStatus_tMetatable_ref = LUA_NOREF;

static int GSClientAchievementStatus_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	GSClientAchievementStatus_t *self = (GSClientAchievementStatus_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_SteamID") == 0) {
		luasteam::pushuint64(L, self->m_SteamID);
		return 1;
	}
	if (strcmp(key, "m_pchAchievement") == 0) {
		lua_pushlstring(L, reinterpret_cast<const char*>(self->m_pchAchievement), 128);
		return 1;
	}
	if (strcmp(key, "m_bUnlocked") == 0) {
		lua_pushboolean(L, self->m_bUnlocked);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int GSClientAchievementStatus_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	GSClientAchievementStatus_t *self = (GSClientAchievementStatus_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_SteamID") == 0) {
		self->m_SteamID = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_pchAchievement") == 0) {
		size_t _len__tmp88;
		const char *_tmp88 = luaL_checklstring(L, 3, &_len__tmp88);
		if (_len__tmp88 > sizeof(self->m_pchAchievement)) luaL_error(L, "String too long");
		memcpy(self->m_pchAchievement, _tmp88, std::min(_len__tmp88 + 1, sizeof(self->m_pchAchievement)));
		return 0;
	}
	if (strcmp(key, "m_bUnlocked") == 0) {
		self->m_bUnlocked = lua_toboolean(L, 3);
		return 0;
	}
	return luaL_error(L, "GSClientAchievementStatus_t has no field '%%s'", key);
}

EXTERN int luasteam_newGSClientAchievementStatus_t(lua_State *L) {
	GSClientAchievementStatus_t *ptr = (GSClientAchievementStatus_t*)lua_newuserdata(L, sizeof(GSClientAchievementStatus_t));
	new (ptr) GSClientAchievementStatus_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_SteamID");
		if (!lua_isnil(L, -1)) {
			ptr->m_SteamID = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_pchAchievement");
		if (!lua_isnil(L, -1)) {
			size_t _len__tmp89;
			const char *_tmp89 = luaL_checklstring(L, -1, &_len__tmp89);
			if (_len__tmp89 > sizeof(ptr->m_pchAchievement)) luaL_error(L, "String too long");
			memcpy(ptr->m_pchAchievement, _tmp89, std::min(_len__tmp89 + 1, sizeof(ptr->m_pchAchievement)));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bUnlocked");
		if (!lua_isnil(L, -1)) {
			ptr->m_bUnlocked = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSClientAchievementStatus_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int GSPolicyResponse_tMetatable_ref = LUA_NOREF;

static int GSPolicyResponse_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	GSPolicyResponse_t *self = (GSPolicyResponse_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_bSecure") == 0) {
		lua_pushinteger(L, self->m_bSecure);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int GSPolicyResponse_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	GSPolicyResponse_t *self = (GSPolicyResponse_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_bSecure") == 0) {
		self->m_bSecure = static_cast<uint8>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "GSPolicyResponse_t has no field '%%s'", key);
}

EXTERN int luasteam_newGSPolicyResponse_t(lua_State *L) {
	GSPolicyResponse_t *ptr = (GSPolicyResponse_t*)lua_newuserdata(L, sizeof(GSPolicyResponse_t));
	new (ptr) GSPolicyResponse_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_bSecure");
		if (!lua_isnil(L, -1)) {
			ptr->m_bSecure = static_cast<uint8>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSPolicyResponse_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int GSGameplayStats_tMetatable_ref = LUA_NOREF;

static int GSGameplayStats_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	GSGameplayStats_t *self = (GSGameplayStats_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_nRank") == 0) {
		lua_pushinteger(L, self->m_nRank);
		return 1;
	}
	if (strcmp(key, "m_unTotalConnects") == 0) {
		lua_pushinteger(L, self->m_unTotalConnects);
		return 1;
	}
	if (strcmp(key, "m_unTotalMinutesPlayed") == 0) {
		lua_pushinteger(L, self->m_unTotalMinutesPlayed);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int GSGameplayStats_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	GSGameplayStats_t *self = (GSGameplayStats_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_nRank") == 0) {
		self->m_nRank = static_cast<int32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_unTotalConnects") == 0) {
		self->m_unTotalConnects = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_unTotalMinutesPlayed") == 0) {
		self->m_unTotalMinutesPlayed = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "GSGameplayStats_t has no field '%%s'", key);
}

EXTERN int luasteam_newGSGameplayStats_t(lua_State *L) {
	GSGameplayStats_t *ptr = (GSGameplayStats_t*)lua_newuserdata(L, sizeof(GSGameplayStats_t));
	new (ptr) GSGameplayStats_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_nRank");
		if (!lua_isnil(L, -1)) {
			ptr->m_nRank = static_cast<int32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unTotalConnects");
		if (!lua_isnil(L, -1)) {
			ptr->m_unTotalConnects = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unTotalMinutesPlayed");
		if (!lua_isnil(L, -1)) {
			ptr->m_unTotalMinutesPlayed = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSGameplayStats_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int GSClientGroupStatus_tMetatable_ref = LUA_NOREF;

static int GSClientGroupStatus_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	GSClientGroupStatus_t *self = (GSClientGroupStatus_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_SteamIDUser") == 0) {
		luasteam::pushuint64(L, self->m_SteamIDUser.ConvertToUint64());
		return 1;
	}
	if (strcmp(key, "m_SteamIDGroup") == 0) {
		luasteam::pushuint64(L, self->m_SteamIDGroup.ConvertToUint64());
		return 1;
	}
	if (strcmp(key, "m_bMember") == 0) {
		lua_pushboolean(L, self->m_bMember);
		return 1;
	}
	if (strcmp(key, "m_bOfficer") == 0) {
		lua_pushboolean(L, self->m_bOfficer);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int GSClientGroupStatus_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	GSClientGroupStatus_t *self = (GSClientGroupStatus_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_SteamIDUser") == 0) {
		self->m_SteamIDUser = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	if (strcmp(key, "m_SteamIDGroup") == 0) {
		self->m_SteamIDGroup = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bMember") == 0) {
		self->m_bMember = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_bOfficer") == 0) {
		self->m_bOfficer = lua_toboolean(L, 3);
		return 0;
	}
	return luaL_error(L, "GSClientGroupStatus_t has no field '%%s'", key);
}

EXTERN int luasteam_newGSClientGroupStatus_t(lua_State *L) {
	GSClientGroupStatus_t *ptr = (GSClientGroupStatus_t*)lua_newuserdata(L, sizeof(GSClientGroupStatus_t));
	new (ptr) GSClientGroupStatus_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_SteamIDUser");
		if (!lua_isnil(L, -1)) {
			ptr->m_SteamIDUser = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_SteamIDGroup");
		if (!lua_isnil(L, -1)) {
			ptr->m_SteamIDGroup = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bMember");
		if (!lua_isnil(L, -1)) {
			ptr->m_bMember = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bOfficer");
		if (!lua_isnil(L, -1)) {
			ptr->m_bOfficer = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSClientGroupStatus_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int GSReputation_tMetatable_ref = LUA_NOREF;

static int GSReputation_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	GSReputation_t *self = (GSReputation_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_unReputationScore") == 0) {
		lua_pushinteger(L, self->m_unReputationScore);
		return 1;
	}
	if (strcmp(key, "m_bBanned") == 0) {
		lua_pushboolean(L, self->m_bBanned);
		return 1;
	}
	if (strcmp(key, "m_unBannedIP") == 0) {
		lua_pushinteger(L, self->m_unBannedIP);
		return 1;
	}
	if (strcmp(key, "m_usBannedPort") == 0) {
		lua_pushinteger(L, self->m_usBannedPort);
		return 1;
	}
	if (strcmp(key, "m_ulBannedGameID") == 0) {
		luasteam::pushuint64(L, self->m_ulBannedGameID);
		return 1;
	}
	if (strcmp(key, "m_unBanExpires") == 0) {
		lua_pushinteger(L, self->m_unBanExpires);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int GSReputation_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	GSReputation_t *self = (GSReputation_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_unReputationScore") == 0) {
		self->m_unReputationScore = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_bBanned") == 0) {
		self->m_bBanned = lua_toboolean(L, 3);
		return 0;
	}
	if (strcmp(key, "m_unBannedIP") == 0) {
		self->m_unBannedIP = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_usBannedPort") == 0) {
		self->m_usBannedPort = static_cast<uint16>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_ulBannedGameID") == 0) {
		self->m_ulBannedGameID = luasteam::checkuint64(L, 3);
		return 0;
	}
	if (strcmp(key, "m_unBanExpires") == 0) {
		self->m_unBanExpires = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "GSReputation_t has no field '%%s'", key);
}

EXTERN int luasteam_newGSReputation_t(lua_State *L) {
	GSReputation_t *ptr = (GSReputation_t*)lua_newuserdata(L, sizeof(GSReputation_t));
	new (ptr) GSReputation_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unReputationScore");
		if (!lua_isnil(L, -1)) {
			ptr->m_unReputationScore = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_bBanned");
		if (!lua_isnil(L, -1)) {
			ptr->m_bBanned = lua_toboolean(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unBannedIP");
		if (!lua_isnil(L, -1)) {
			ptr->m_unBannedIP = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_usBannedPort");
		if (!lua_isnil(L, -1)) {
			ptr->m_usBannedPort = static_cast<uint16>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_ulBannedGameID");
		if (!lua_isnil(L, -1)) {
			ptr->m_ulBannedGameID = luasteam::checkuint64(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unBanExpires");
		if (!lua_isnil(L, -1)) {
			ptr->m_unBanExpires = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSReputation_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int AssociateWithClanResult_tMetatable_ref = LUA_NOREF;

static int AssociateWithClanResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	AssociateWithClanResult_t *self = (AssociateWithClanResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int AssociateWithClanResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	AssociateWithClanResult_t *self = (AssociateWithClanResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	return luaL_error(L, "AssociateWithClanResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newAssociateWithClanResult_t(lua_State *L) {
	AssociateWithClanResult_t *ptr = (AssociateWithClanResult_t*)lua_newuserdata(L, sizeof(AssociateWithClanResult_t));
	new (ptr) AssociateWithClanResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, AssociateWithClanResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int ComputeNewPlayerCompatibilityResult_tMetatable_ref = LUA_NOREF;

static int ComputeNewPlayerCompatibilityResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	ComputeNewPlayerCompatibilityResult_t *self = (ComputeNewPlayerCompatibilityResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_cPlayersThatDontLikeCandidate") == 0) {
		lua_pushinteger(L, self->m_cPlayersThatDontLikeCandidate);
		return 1;
	}
	if (strcmp(key, "m_cPlayersThatCandidateDoesntLike") == 0) {
		lua_pushinteger(L, self->m_cPlayersThatCandidateDoesntLike);
		return 1;
	}
	if (strcmp(key, "m_cClanPlayersThatDontLikeCandidate") == 0) {
		lua_pushinteger(L, self->m_cClanPlayersThatDontLikeCandidate);
		return 1;
	}
	if (strcmp(key, "m_SteamIDCandidate") == 0) {
		luasteam::pushuint64(L, self->m_SteamIDCandidate.ConvertToUint64());
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int ComputeNewPlayerCompatibilityResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	ComputeNewPlayerCompatibilityResult_t *self = (ComputeNewPlayerCompatibilityResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_cPlayersThatDontLikeCandidate") == 0) {
		self->m_cPlayersThatDontLikeCandidate = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_cPlayersThatCandidateDoesntLike") == 0) {
		self->m_cPlayersThatCandidateDoesntLike = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_cClanPlayersThatDontLikeCandidate") == 0) {
		self->m_cClanPlayersThatDontLikeCandidate = static_cast<int>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_SteamIDCandidate") == 0) {
		self->m_SteamIDCandidate = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	return luaL_error(L, "ComputeNewPlayerCompatibilityResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newComputeNewPlayerCompatibilityResult_t(lua_State *L) {
	ComputeNewPlayerCompatibilityResult_t *ptr = (ComputeNewPlayerCompatibilityResult_t*)lua_newuserdata(L, sizeof(ComputeNewPlayerCompatibilityResult_t));
	new (ptr) ComputeNewPlayerCompatibilityResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_cPlayersThatDontLikeCandidate");
		if (!lua_isnil(L, -1)) {
			ptr->m_cPlayersThatDontLikeCandidate = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_cPlayersThatCandidateDoesntLike");
		if (!lua_isnil(L, -1)) {
			ptr->m_cPlayersThatCandidateDoesntLike = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_cClanPlayersThatDontLikeCandidate");
		if (!lua_isnil(L, -1)) {
			ptr->m_cClanPlayersThatDontLikeCandidate = static_cast<int>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_SteamIDCandidate");
		if (!lua_isnil(L, -1)) {
			ptr->m_SteamIDCandidate = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, ComputeNewPlayerCompatibilityResult_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int GSStatsReceived_tMetatable_ref = LUA_NOREF;

static int GSStatsReceived_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	GSStatsReceived_t *self = (GSStatsReceived_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_steamIDUser") == 0) {
		luasteam::pushuint64(L, self->m_steamIDUser.ConvertToUint64());
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int GSStatsReceived_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	GSStatsReceived_t *self = (GSStatsReceived_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_steamIDUser") == 0) {
		self->m_steamIDUser = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	return luaL_error(L, "GSStatsReceived_t has no field '%%s'", key);
}

EXTERN int luasteam_newGSStatsReceived_t(lua_State *L) {
	GSStatsReceived_t *ptr = (GSStatsReceived_t*)lua_newuserdata(L, sizeof(GSStatsReceived_t));
	new (ptr) GSStatsReceived_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_steamIDUser");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamIDUser = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSStatsReceived_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int GSStatsStored_tMetatable_ref = LUA_NOREF;

static int GSStatsStored_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	GSStatsStored_t *self = (GSStatsStored_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_steamIDUser") == 0) {
		luasteam::pushuint64(L, self->m_steamIDUser.ConvertToUint64());
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int GSStatsStored_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	GSStatsStored_t *self = (GSStatsStored_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_steamIDUser") == 0) {
		self->m_steamIDUser = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	return luaL_error(L, "GSStatsStored_t has no field '%%s'", key);
}

EXTERN int luasteam_newGSStatsStored_t(lua_State *L) {
	GSStatsStored_t *ptr = (GSStatsStored_t*)lua_newuserdata(L, sizeof(GSStatsStored_t));
	new (ptr) GSStatsStored_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_steamIDUser");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamIDUser = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSStatsStored_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int GSStatsUnloaded_tMetatable_ref = LUA_NOREF;

static int GSStatsUnloaded_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	GSStatsUnloaded_t *self = (GSStatsUnloaded_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamIDUser") == 0) {
		luasteam::pushuint64(L, self->m_steamIDUser.ConvertToUint64());
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int GSStatsUnloaded_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	GSStatsUnloaded_t *self = (GSStatsUnloaded_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_steamIDUser") == 0) {
		self->m_steamIDUser = CSteamID(luasteam::checkuint64(L, 3));
		return 0;
	}
	return luaL_error(L, "GSStatsUnloaded_t has no field '%%s'", key);
}

EXTERN int luasteam_newGSStatsUnloaded_t(lua_State *L) {
	GSStatsUnloaded_t *ptr = (GSStatsUnloaded_t*)lua_newuserdata(L, sizeof(GSStatsUnloaded_t));
	new (ptr) GSStatsUnloaded_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_steamIDUser");
		if (!lua_isnil(L, -1)) {
			ptr->m_steamIDUser = CSteamID(luasteam::checkuint64(L, -1));
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSStatsUnloaded_tMetatable_ref);
	lua_setmetatable(L, -2);
	return 1;
}

static int SteamNetworkingFakeIPResult_tMetatable_ref = LUA_NOREF;

static int SteamNetworkingFakeIPResult_t_index(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }
	const char *key = lua_tostring(L, 2);
	SteamNetworkingFakeIPResult_t *self = (SteamNetworkingFakeIPResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		lua_pushinteger(L, self->m_eResult);
		return 1;
	}
	if (strcmp(key, "m_identity") == 0) {
		luasteam::push_SteamNetworkingIdentity(L, self->m_identity);
		return 1;
	}
	if (strcmp(key, "m_unIP") == 0) {
		lua_pushinteger(L, self->m_unIP);
		return 1;
	}
	if (strcmp(key, "m_unPorts") == 0) {
		lua_createtable(L, 8, 0);
		for(decltype(8) i = 0; i < 8; i++) {
			lua_pushinteger(L, self->m_unPorts[i]);
			lua_rawseti(L, -2, i+1);
		}
		return 1;
	}
	lua_pushnil(L);
	return 1;
}

static int SteamNetworkingFakeIPResult_t_newindex(lua_State *L) {
	if (lua_type(L, 2) != LUA_TSTRING) { return 0; }
	const char *key = lua_tostring(L, 2);
	SteamNetworkingFakeIPResult_t *self = (SteamNetworkingFakeIPResult_t*)lua_touserdata(L, 1);
	if (strcmp(key, "m_eResult") == 0) {
		self->m_eResult = static_cast<EResult>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_identity") == 0) {
		self->m_identity = luasteam::check_SteamNetworkingIdentity(L, 3);
		return 0;
	}
	if (strcmp(key, "m_unIP") == 0) {
		self->m_unIP = static_cast<uint32>(luaL_checkint(L, 3));
		return 0;
	}
	if (strcmp(key, "m_unPorts") == 0) {
		luaL_checktype(L, 3, LUA_TTABLE);
		for(decltype(8) i = 0; i < 8; i++) {
			lua_rawgeti(L, 3, i+1);
			self->m_unPorts[i] = static_cast<int>(luaL_checkint(L, -1));
			lua_pop(L, 1);
		}
		return 0;
	}
	return luaL_error(L, "SteamNetworkingFakeIPResult_t has no field '%%s'", key);
}

EXTERN int luasteam_newSteamNetworkingFakeIPResult_t(lua_State *L) {
	SteamNetworkingFakeIPResult_t *ptr = (SteamNetworkingFakeIPResult_t*)lua_newuserdata(L, sizeof(SteamNetworkingFakeIPResult_t));
	new (ptr) SteamNetworkingFakeIPResult_t();
	if (!lua_isnoneornil(L, 1)) {
		luaL_checktype(L, 1, LUA_TTABLE);
		lua_getfield(L, 1, "m_eResult");
		if (!lua_isnil(L, -1)) {
			ptr->m_eResult = static_cast<EResult>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_identity");
		if (!lua_isnil(L, -1)) {
			ptr->m_identity = luasteam::check_SteamNetworkingIdentity(L, -1);
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unIP");
		if (!lua_isnil(L, -1)) {
			ptr->m_unIP = static_cast<uint32>(luaL_checkint(L, -1));
		}
		lua_pop(L, 1);
		lua_getfield(L, 1, "m_unPorts");
		if (!lua_isnil(L, -1)) {
			luaL_checktype(L, -1, LUA_TTABLE);
			for(decltype(8) i = 0; i < 8; i++) {
				lua_rawgeti(L, -1, i+1);
				ptr->m_unPorts[i] = static_cast<int>(luaL_checkint(L, -1));
				lua_pop(L, 1);
			}
		}
		lua_pop(L, 1);
	}
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetworkingFakeIPResult_tMetatable_ref);
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

void push_SteamServersConnected_t(lua_State *L, SteamServersConnected_t val) {
	SteamServersConnected_t *ptr = (SteamServersConnected_t*)lua_newuserdata(L, sizeof(SteamServersConnected_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamServersConnected_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamServersConnected_t *check_SteamServersConnected_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamServersConnected_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamServersConnected_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamServersConnected_t expected");
	return (SteamServersConnected_t*)lua_touserdata(L, nParam);
}

SteamServersConnected_t check_SteamServersConnected_t(lua_State *L, int nParam) { return *check_SteamServersConnected_t_ptr(L, nParam); }

void push_SteamServerConnectFailure_t(lua_State *L, SteamServerConnectFailure_t val) {
	SteamServerConnectFailure_t *ptr = (SteamServerConnectFailure_t*)lua_newuserdata(L, sizeof(SteamServerConnectFailure_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamServerConnectFailure_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamServerConnectFailure_t *check_SteamServerConnectFailure_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamServerConnectFailure_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamServerConnectFailure_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamServerConnectFailure_t expected");
	return (SteamServerConnectFailure_t*)lua_touserdata(L, nParam);
}

SteamServerConnectFailure_t check_SteamServerConnectFailure_t(lua_State *L, int nParam) { return *check_SteamServerConnectFailure_t_ptr(L, nParam); }

void push_SteamServersDisconnected_t(lua_State *L, SteamServersDisconnected_t val) {
	SteamServersDisconnected_t *ptr = (SteamServersDisconnected_t*)lua_newuserdata(L, sizeof(SteamServersDisconnected_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamServersDisconnected_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamServersDisconnected_t *check_SteamServersDisconnected_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamServersDisconnected_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamServersDisconnected_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamServersDisconnected_t expected");
	return (SteamServersDisconnected_t*)lua_touserdata(L, nParam);
}

SteamServersDisconnected_t check_SteamServersDisconnected_t(lua_State *L, int nParam) { return *check_SteamServersDisconnected_t_ptr(L, nParam); }

void push_ClientGameServerDeny_t(lua_State *L, ClientGameServerDeny_t val) {
	ClientGameServerDeny_t *ptr = (ClientGameServerDeny_t*)lua_newuserdata(L, sizeof(ClientGameServerDeny_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, ClientGameServerDeny_tMetatable_ref);
	lua_setmetatable(L, -2);
}

ClientGameServerDeny_t *check_ClientGameServerDeny_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "ClientGameServerDeny_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, ClientGameServerDeny_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "ClientGameServerDeny_t expected");
	return (ClientGameServerDeny_t*)lua_touserdata(L, nParam);
}

ClientGameServerDeny_t check_ClientGameServerDeny_t(lua_State *L, int nParam) { return *check_ClientGameServerDeny_t_ptr(L, nParam); }

void push_IPCFailure_t(lua_State *L, IPCFailure_t val) {
	IPCFailure_t *ptr = (IPCFailure_t*)lua_newuserdata(L, sizeof(IPCFailure_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, IPCFailure_tMetatable_ref);
	lua_setmetatable(L, -2);
}

IPCFailure_t *check_IPCFailure_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "IPCFailure_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, IPCFailure_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "IPCFailure_t expected");
	return (IPCFailure_t*)lua_touserdata(L, nParam);
}

IPCFailure_t check_IPCFailure_t(lua_State *L, int nParam) { return *check_IPCFailure_t_ptr(L, nParam); }

void push_LicensesUpdated_t(lua_State *L, LicensesUpdated_t val) {
	LicensesUpdated_t *ptr = (LicensesUpdated_t*)lua_newuserdata(L, sizeof(LicensesUpdated_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, LicensesUpdated_tMetatable_ref);
	lua_setmetatable(L, -2);
}

LicensesUpdated_t *check_LicensesUpdated_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "LicensesUpdated_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, LicensesUpdated_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "LicensesUpdated_t expected");
	return (LicensesUpdated_t*)lua_touserdata(L, nParam);
}

LicensesUpdated_t check_LicensesUpdated_t(lua_State *L, int nParam) { return *check_LicensesUpdated_t_ptr(L, nParam); }

void push_ValidateAuthTicketResponse_t(lua_State *L, ValidateAuthTicketResponse_t val) {
	ValidateAuthTicketResponse_t *ptr = (ValidateAuthTicketResponse_t*)lua_newuserdata(L, sizeof(ValidateAuthTicketResponse_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, ValidateAuthTicketResponse_tMetatable_ref);
	lua_setmetatable(L, -2);
}

ValidateAuthTicketResponse_t *check_ValidateAuthTicketResponse_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "ValidateAuthTicketResponse_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, ValidateAuthTicketResponse_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "ValidateAuthTicketResponse_t expected");
	return (ValidateAuthTicketResponse_t*)lua_touserdata(L, nParam);
}

ValidateAuthTicketResponse_t check_ValidateAuthTicketResponse_t(lua_State *L, int nParam) { return *check_ValidateAuthTicketResponse_t_ptr(L, nParam); }

void push_MicroTxnAuthorizationResponse_t(lua_State *L, MicroTxnAuthorizationResponse_t val) {
	MicroTxnAuthorizationResponse_t *ptr = (MicroTxnAuthorizationResponse_t*)lua_newuserdata(L, sizeof(MicroTxnAuthorizationResponse_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, MicroTxnAuthorizationResponse_tMetatable_ref);
	lua_setmetatable(L, -2);
}

MicroTxnAuthorizationResponse_t *check_MicroTxnAuthorizationResponse_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "MicroTxnAuthorizationResponse_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, MicroTxnAuthorizationResponse_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "MicroTxnAuthorizationResponse_t expected");
	return (MicroTxnAuthorizationResponse_t*)lua_touserdata(L, nParam);
}

MicroTxnAuthorizationResponse_t check_MicroTxnAuthorizationResponse_t(lua_State *L, int nParam) { return *check_MicroTxnAuthorizationResponse_t_ptr(L, nParam); }

void push_EncryptedAppTicketResponse_t(lua_State *L, EncryptedAppTicketResponse_t val) {
	EncryptedAppTicketResponse_t *ptr = (EncryptedAppTicketResponse_t*)lua_newuserdata(L, sizeof(EncryptedAppTicketResponse_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, EncryptedAppTicketResponse_tMetatable_ref);
	lua_setmetatable(L, -2);
}

EncryptedAppTicketResponse_t *check_EncryptedAppTicketResponse_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "EncryptedAppTicketResponse_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, EncryptedAppTicketResponse_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "EncryptedAppTicketResponse_t expected");
	return (EncryptedAppTicketResponse_t*)lua_touserdata(L, nParam);
}

EncryptedAppTicketResponse_t check_EncryptedAppTicketResponse_t(lua_State *L, int nParam) { return *check_EncryptedAppTicketResponse_t_ptr(L, nParam); }

void push_GetAuthSessionTicketResponse_t(lua_State *L, GetAuthSessionTicketResponse_t val) {
	GetAuthSessionTicketResponse_t *ptr = (GetAuthSessionTicketResponse_t*)lua_newuserdata(L, sizeof(GetAuthSessionTicketResponse_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, GetAuthSessionTicketResponse_tMetatable_ref);
	lua_setmetatable(L, -2);
}

GetAuthSessionTicketResponse_t *check_GetAuthSessionTicketResponse_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "GetAuthSessionTicketResponse_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, GetAuthSessionTicketResponse_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "GetAuthSessionTicketResponse_t expected");
	return (GetAuthSessionTicketResponse_t*)lua_touserdata(L, nParam);
}

GetAuthSessionTicketResponse_t check_GetAuthSessionTicketResponse_t(lua_State *L, int nParam) { return *check_GetAuthSessionTicketResponse_t_ptr(L, nParam); }

void push_GameWebCallback_t(lua_State *L, GameWebCallback_t val) {
	GameWebCallback_t *ptr = (GameWebCallback_t*)lua_newuserdata(L, sizeof(GameWebCallback_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, GameWebCallback_tMetatable_ref);
	lua_setmetatable(L, -2);
}

GameWebCallback_t *check_GameWebCallback_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "GameWebCallback_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, GameWebCallback_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "GameWebCallback_t expected");
	return (GameWebCallback_t*)lua_touserdata(L, nParam);
}

GameWebCallback_t check_GameWebCallback_t(lua_State *L, int nParam) { return *check_GameWebCallback_t_ptr(L, nParam); }

void push_StoreAuthURLResponse_t(lua_State *L, StoreAuthURLResponse_t val) {
	StoreAuthURLResponse_t *ptr = (StoreAuthURLResponse_t*)lua_newuserdata(L, sizeof(StoreAuthURLResponse_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, StoreAuthURLResponse_tMetatable_ref);
	lua_setmetatable(L, -2);
}

StoreAuthURLResponse_t *check_StoreAuthURLResponse_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "StoreAuthURLResponse_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, StoreAuthURLResponse_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "StoreAuthURLResponse_t expected");
	return (StoreAuthURLResponse_t*)lua_touserdata(L, nParam);
}

StoreAuthURLResponse_t check_StoreAuthURLResponse_t(lua_State *L, int nParam) { return *check_StoreAuthURLResponse_t_ptr(L, nParam); }

void push_MarketEligibilityResponse_t(lua_State *L, MarketEligibilityResponse_t val) {
	MarketEligibilityResponse_t *ptr = (MarketEligibilityResponse_t*)lua_newuserdata(L, sizeof(MarketEligibilityResponse_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, MarketEligibilityResponse_tMetatable_ref);
	lua_setmetatable(L, -2);
}

MarketEligibilityResponse_t *check_MarketEligibilityResponse_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "MarketEligibilityResponse_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, MarketEligibilityResponse_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "MarketEligibilityResponse_t expected");
	return (MarketEligibilityResponse_t*)lua_touserdata(L, nParam);
}

MarketEligibilityResponse_t check_MarketEligibilityResponse_t(lua_State *L, int nParam) { return *check_MarketEligibilityResponse_t_ptr(L, nParam); }

void push_DurationControl_t(lua_State *L, DurationControl_t val) {
	DurationControl_t *ptr = (DurationControl_t*)lua_newuserdata(L, sizeof(DurationControl_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, DurationControl_tMetatable_ref);
	lua_setmetatable(L, -2);
}

DurationControl_t *check_DurationControl_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "DurationControl_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, DurationControl_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "DurationControl_t expected");
	return (DurationControl_t*)lua_touserdata(L, nParam);
}

DurationControl_t check_DurationControl_t(lua_State *L, int nParam) { return *check_DurationControl_t_ptr(L, nParam); }

void push_GetTicketForWebApiResponse_t(lua_State *L, GetTicketForWebApiResponse_t val) {
	GetTicketForWebApiResponse_t *ptr = (GetTicketForWebApiResponse_t*)lua_newuserdata(L, sizeof(GetTicketForWebApiResponse_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, GetTicketForWebApiResponse_tMetatable_ref);
	lua_setmetatable(L, -2);
}

GetTicketForWebApiResponse_t *check_GetTicketForWebApiResponse_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "GetTicketForWebApiResponse_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, GetTicketForWebApiResponse_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "GetTicketForWebApiResponse_t expected");
	return (GetTicketForWebApiResponse_t*)lua_touserdata(L, nParam);
}

GetTicketForWebApiResponse_t check_GetTicketForWebApiResponse_t(lua_State *L, int nParam) { return *check_GetTicketForWebApiResponse_t_ptr(L, nParam); }

void push_PersonaStateChange_t(lua_State *L, PersonaStateChange_t val) {
	PersonaStateChange_t *ptr = (PersonaStateChange_t*)lua_newuserdata(L, sizeof(PersonaStateChange_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, PersonaStateChange_tMetatable_ref);
	lua_setmetatable(L, -2);
}

PersonaStateChange_t *check_PersonaStateChange_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "PersonaStateChange_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, PersonaStateChange_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "PersonaStateChange_t expected");
	return (PersonaStateChange_t*)lua_touserdata(L, nParam);
}

PersonaStateChange_t check_PersonaStateChange_t(lua_State *L, int nParam) { return *check_PersonaStateChange_t_ptr(L, nParam); }

void push_GameOverlayActivated_t(lua_State *L, GameOverlayActivated_t val) {
	GameOverlayActivated_t *ptr = (GameOverlayActivated_t*)lua_newuserdata(L, sizeof(GameOverlayActivated_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, GameOverlayActivated_tMetatable_ref);
	lua_setmetatable(L, -2);
}

GameOverlayActivated_t *check_GameOverlayActivated_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "GameOverlayActivated_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, GameOverlayActivated_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "GameOverlayActivated_t expected");
	return (GameOverlayActivated_t*)lua_touserdata(L, nParam);
}

GameOverlayActivated_t check_GameOverlayActivated_t(lua_State *L, int nParam) { return *check_GameOverlayActivated_t_ptr(L, nParam); }

void push_GameServerChangeRequested_t(lua_State *L, GameServerChangeRequested_t val) {
	GameServerChangeRequested_t *ptr = (GameServerChangeRequested_t*)lua_newuserdata(L, sizeof(GameServerChangeRequested_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, GameServerChangeRequested_tMetatable_ref);
	lua_setmetatable(L, -2);
}

GameServerChangeRequested_t *check_GameServerChangeRequested_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "GameServerChangeRequested_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, GameServerChangeRequested_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "GameServerChangeRequested_t expected");
	return (GameServerChangeRequested_t*)lua_touserdata(L, nParam);
}

GameServerChangeRequested_t check_GameServerChangeRequested_t(lua_State *L, int nParam) { return *check_GameServerChangeRequested_t_ptr(L, nParam); }

void push_GameLobbyJoinRequested_t(lua_State *L, GameLobbyJoinRequested_t val) {
	GameLobbyJoinRequested_t *ptr = (GameLobbyJoinRequested_t*)lua_newuserdata(L, sizeof(GameLobbyJoinRequested_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, GameLobbyJoinRequested_tMetatable_ref);
	lua_setmetatable(L, -2);
}

GameLobbyJoinRequested_t *check_GameLobbyJoinRequested_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "GameLobbyJoinRequested_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, GameLobbyJoinRequested_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "GameLobbyJoinRequested_t expected");
	return (GameLobbyJoinRequested_t*)lua_touserdata(L, nParam);
}

GameLobbyJoinRequested_t check_GameLobbyJoinRequested_t(lua_State *L, int nParam) { return *check_GameLobbyJoinRequested_t_ptr(L, nParam); }

void push_AvatarImageLoaded_t(lua_State *L, AvatarImageLoaded_t val) {
	AvatarImageLoaded_t *ptr = (AvatarImageLoaded_t*)lua_newuserdata(L, sizeof(AvatarImageLoaded_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, AvatarImageLoaded_tMetatable_ref);
	lua_setmetatable(L, -2);
}

AvatarImageLoaded_t *check_AvatarImageLoaded_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "AvatarImageLoaded_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, AvatarImageLoaded_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "AvatarImageLoaded_t expected");
	return (AvatarImageLoaded_t*)lua_touserdata(L, nParam);
}

AvatarImageLoaded_t check_AvatarImageLoaded_t(lua_State *L, int nParam) { return *check_AvatarImageLoaded_t_ptr(L, nParam); }

void push_ClanOfficerListResponse_t(lua_State *L, ClanOfficerListResponse_t val) {
	ClanOfficerListResponse_t *ptr = (ClanOfficerListResponse_t*)lua_newuserdata(L, sizeof(ClanOfficerListResponse_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, ClanOfficerListResponse_tMetatable_ref);
	lua_setmetatable(L, -2);
}

ClanOfficerListResponse_t *check_ClanOfficerListResponse_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "ClanOfficerListResponse_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, ClanOfficerListResponse_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "ClanOfficerListResponse_t expected");
	return (ClanOfficerListResponse_t*)lua_touserdata(L, nParam);
}

ClanOfficerListResponse_t check_ClanOfficerListResponse_t(lua_State *L, int nParam) { return *check_ClanOfficerListResponse_t_ptr(L, nParam); }

void push_FriendRichPresenceUpdate_t(lua_State *L, FriendRichPresenceUpdate_t val) {
	FriendRichPresenceUpdate_t *ptr = (FriendRichPresenceUpdate_t*)lua_newuserdata(L, sizeof(FriendRichPresenceUpdate_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, FriendRichPresenceUpdate_tMetatable_ref);
	lua_setmetatable(L, -2);
}

FriendRichPresenceUpdate_t *check_FriendRichPresenceUpdate_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "FriendRichPresenceUpdate_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, FriendRichPresenceUpdate_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "FriendRichPresenceUpdate_t expected");
	return (FriendRichPresenceUpdate_t*)lua_touserdata(L, nParam);
}

FriendRichPresenceUpdate_t check_FriendRichPresenceUpdate_t(lua_State *L, int nParam) { return *check_FriendRichPresenceUpdate_t_ptr(L, nParam); }

void push_GameRichPresenceJoinRequested_t(lua_State *L, GameRichPresenceJoinRequested_t val) {
	GameRichPresenceJoinRequested_t *ptr = (GameRichPresenceJoinRequested_t*)lua_newuserdata(L, sizeof(GameRichPresenceJoinRequested_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, GameRichPresenceJoinRequested_tMetatable_ref);
	lua_setmetatable(L, -2);
}

GameRichPresenceJoinRequested_t *check_GameRichPresenceJoinRequested_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "GameRichPresenceJoinRequested_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, GameRichPresenceJoinRequested_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "GameRichPresenceJoinRequested_t expected");
	return (GameRichPresenceJoinRequested_t*)lua_touserdata(L, nParam);
}

GameRichPresenceJoinRequested_t check_GameRichPresenceJoinRequested_t(lua_State *L, int nParam) { return *check_GameRichPresenceJoinRequested_t_ptr(L, nParam); }

void push_GameConnectedClanChatMsg_t(lua_State *L, GameConnectedClanChatMsg_t val) {
	GameConnectedClanChatMsg_t *ptr = (GameConnectedClanChatMsg_t*)lua_newuserdata(L, sizeof(GameConnectedClanChatMsg_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, GameConnectedClanChatMsg_tMetatable_ref);
	lua_setmetatable(L, -2);
}

GameConnectedClanChatMsg_t *check_GameConnectedClanChatMsg_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "GameConnectedClanChatMsg_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, GameConnectedClanChatMsg_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "GameConnectedClanChatMsg_t expected");
	return (GameConnectedClanChatMsg_t*)lua_touserdata(L, nParam);
}

GameConnectedClanChatMsg_t check_GameConnectedClanChatMsg_t(lua_State *L, int nParam) { return *check_GameConnectedClanChatMsg_t_ptr(L, nParam); }

void push_GameConnectedChatJoin_t(lua_State *L, GameConnectedChatJoin_t val) {
	GameConnectedChatJoin_t *ptr = (GameConnectedChatJoin_t*)lua_newuserdata(L, sizeof(GameConnectedChatJoin_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, GameConnectedChatJoin_tMetatable_ref);
	lua_setmetatable(L, -2);
}

GameConnectedChatJoin_t *check_GameConnectedChatJoin_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "GameConnectedChatJoin_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, GameConnectedChatJoin_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "GameConnectedChatJoin_t expected");
	return (GameConnectedChatJoin_t*)lua_touserdata(L, nParam);
}

GameConnectedChatJoin_t check_GameConnectedChatJoin_t(lua_State *L, int nParam) { return *check_GameConnectedChatJoin_t_ptr(L, nParam); }

void push_GameConnectedChatLeave_t(lua_State *L, GameConnectedChatLeave_t val) {
	GameConnectedChatLeave_t *ptr = (GameConnectedChatLeave_t*)lua_newuserdata(L, sizeof(GameConnectedChatLeave_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, GameConnectedChatLeave_tMetatable_ref);
	lua_setmetatable(L, -2);
}

GameConnectedChatLeave_t *check_GameConnectedChatLeave_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "GameConnectedChatLeave_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, GameConnectedChatLeave_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "GameConnectedChatLeave_t expected");
	return (GameConnectedChatLeave_t*)lua_touserdata(L, nParam);
}

GameConnectedChatLeave_t check_GameConnectedChatLeave_t(lua_State *L, int nParam) { return *check_GameConnectedChatLeave_t_ptr(L, nParam); }

void push_DownloadClanActivityCountsResult_t(lua_State *L, DownloadClanActivityCountsResult_t val) {
	DownloadClanActivityCountsResult_t *ptr = (DownloadClanActivityCountsResult_t*)lua_newuserdata(L, sizeof(DownloadClanActivityCountsResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, DownloadClanActivityCountsResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

DownloadClanActivityCountsResult_t *check_DownloadClanActivityCountsResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "DownloadClanActivityCountsResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, DownloadClanActivityCountsResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "DownloadClanActivityCountsResult_t expected");
	return (DownloadClanActivityCountsResult_t*)lua_touserdata(L, nParam);
}

DownloadClanActivityCountsResult_t check_DownloadClanActivityCountsResult_t(lua_State *L, int nParam) { return *check_DownloadClanActivityCountsResult_t_ptr(L, nParam); }

void push_JoinClanChatRoomCompletionResult_t(lua_State *L, JoinClanChatRoomCompletionResult_t val) {
	JoinClanChatRoomCompletionResult_t *ptr = (JoinClanChatRoomCompletionResult_t*)lua_newuserdata(L, sizeof(JoinClanChatRoomCompletionResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, JoinClanChatRoomCompletionResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

JoinClanChatRoomCompletionResult_t *check_JoinClanChatRoomCompletionResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "JoinClanChatRoomCompletionResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, JoinClanChatRoomCompletionResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "JoinClanChatRoomCompletionResult_t expected");
	return (JoinClanChatRoomCompletionResult_t*)lua_touserdata(L, nParam);
}

JoinClanChatRoomCompletionResult_t check_JoinClanChatRoomCompletionResult_t(lua_State *L, int nParam) { return *check_JoinClanChatRoomCompletionResult_t_ptr(L, nParam); }

void push_GameConnectedFriendChatMsg_t(lua_State *L, GameConnectedFriendChatMsg_t val) {
	GameConnectedFriendChatMsg_t *ptr = (GameConnectedFriendChatMsg_t*)lua_newuserdata(L, sizeof(GameConnectedFriendChatMsg_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, GameConnectedFriendChatMsg_tMetatable_ref);
	lua_setmetatable(L, -2);
}

GameConnectedFriendChatMsg_t *check_GameConnectedFriendChatMsg_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "GameConnectedFriendChatMsg_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, GameConnectedFriendChatMsg_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "GameConnectedFriendChatMsg_t expected");
	return (GameConnectedFriendChatMsg_t*)lua_touserdata(L, nParam);
}

GameConnectedFriendChatMsg_t check_GameConnectedFriendChatMsg_t(lua_State *L, int nParam) { return *check_GameConnectedFriendChatMsg_t_ptr(L, nParam); }

void push_FriendsGetFollowerCount_t(lua_State *L, FriendsGetFollowerCount_t val) {
	FriendsGetFollowerCount_t *ptr = (FriendsGetFollowerCount_t*)lua_newuserdata(L, sizeof(FriendsGetFollowerCount_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, FriendsGetFollowerCount_tMetatable_ref);
	lua_setmetatable(L, -2);
}

FriendsGetFollowerCount_t *check_FriendsGetFollowerCount_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "FriendsGetFollowerCount_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, FriendsGetFollowerCount_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "FriendsGetFollowerCount_t expected");
	return (FriendsGetFollowerCount_t*)lua_touserdata(L, nParam);
}

FriendsGetFollowerCount_t check_FriendsGetFollowerCount_t(lua_State *L, int nParam) { return *check_FriendsGetFollowerCount_t_ptr(L, nParam); }

void push_FriendsIsFollowing_t(lua_State *L, FriendsIsFollowing_t val) {
	FriendsIsFollowing_t *ptr = (FriendsIsFollowing_t*)lua_newuserdata(L, sizeof(FriendsIsFollowing_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, FriendsIsFollowing_tMetatable_ref);
	lua_setmetatable(L, -2);
}

FriendsIsFollowing_t *check_FriendsIsFollowing_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "FriendsIsFollowing_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, FriendsIsFollowing_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "FriendsIsFollowing_t expected");
	return (FriendsIsFollowing_t*)lua_touserdata(L, nParam);
}

FriendsIsFollowing_t check_FriendsIsFollowing_t(lua_State *L, int nParam) { return *check_FriendsIsFollowing_t_ptr(L, nParam); }

void push_FriendsEnumerateFollowingList_t(lua_State *L, FriendsEnumerateFollowingList_t val) {
	FriendsEnumerateFollowingList_t *ptr = (FriendsEnumerateFollowingList_t*)lua_newuserdata(L, sizeof(FriendsEnumerateFollowingList_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, FriendsEnumerateFollowingList_tMetatable_ref);
	lua_setmetatable(L, -2);
}

FriendsEnumerateFollowingList_t *check_FriendsEnumerateFollowingList_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "FriendsEnumerateFollowingList_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, FriendsEnumerateFollowingList_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "FriendsEnumerateFollowingList_t expected");
	return (FriendsEnumerateFollowingList_t*)lua_touserdata(L, nParam);
}

FriendsEnumerateFollowingList_t check_FriendsEnumerateFollowingList_t(lua_State *L, int nParam) { return *check_FriendsEnumerateFollowingList_t_ptr(L, nParam); }

void push_UnreadChatMessagesChanged_t(lua_State *L, UnreadChatMessagesChanged_t val) {
	UnreadChatMessagesChanged_t *ptr = (UnreadChatMessagesChanged_t*)lua_newuserdata(L, sizeof(UnreadChatMessagesChanged_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, UnreadChatMessagesChanged_tMetatable_ref);
	lua_setmetatable(L, -2);
}

UnreadChatMessagesChanged_t *check_UnreadChatMessagesChanged_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "UnreadChatMessagesChanged_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, UnreadChatMessagesChanged_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "UnreadChatMessagesChanged_t expected");
	return (UnreadChatMessagesChanged_t*)lua_touserdata(L, nParam);
}

UnreadChatMessagesChanged_t check_UnreadChatMessagesChanged_t(lua_State *L, int nParam) { return *check_UnreadChatMessagesChanged_t_ptr(L, nParam); }

void push_OverlayBrowserProtocolNavigation_t(lua_State *L, OverlayBrowserProtocolNavigation_t val) {
	OverlayBrowserProtocolNavigation_t *ptr = (OverlayBrowserProtocolNavigation_t*)lua_newuserdata(L, sizeof(OverlayBrowserProtocolNavigation_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, OverlayBrowserProtocolNavigation_tMetatable_ref);
	lua_setmetatable(L, -2);
}

OverlayBrowserProtocolNavigation_t *check_OverlayBrowserProtocolNavigation_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "OverlayBrowserProtocolNavigation_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, OverlayBrowserProtocolNavigation_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "OverlayBrowserProtocolNavigation_t expected");
	return (OverlayBrowserProtocolNavigation_t*)lua_touserdata(L, nParam);
}

OverlayBrowserProtocolNavigation_t check_OverlayBrowserProtocolNavigation_t(lua_State *L, int nParam) { return *check_OverlayBrowserProtocolNavigation_t_ptr(L, nParam); }

void push_EquippedProfileItemsChanged_t(lua_State *L, EquippedProfileItemsChanged_t val) {
	EquippedProfileItemsChanged_t *ptr = (EquippedProfileItemsChanged_t*)lua_newuserdata(L, sizeof(EquippedProfileItemsChanged_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, EquippedProfileItemsChanged_tMetatable_ref);
	lua_setmetatable(L, -2);
}

EquippedProfileItemsChanged_t *check_EquippedProfileItemsChanged_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "EquippedProfileItemsChanged_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, EquippedProfileItemsChanged_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "EquippedProfileItemsChanged_t expected");
	return (EquippedProfileItemsChanged_t*)lua_touserdata(L, nParam);
}

EquippedProfileItemsChanged_t check_EquippedProfileItemsChanged_t(lua_State *L, int nParam) { return *check_EquippedProfileItemsChanged_t_ptr(L, nParam); }

void push_EquippedProfileItems_t(lua_State *L, EquippedProfileItems_t val) {
	EquippedProfileItems_t *ptr = (EquippedProfileItems_t*)lua_newuserdata(L, sizeof(EquippedProfileItems_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, EquippedProfileItems_tMetatable_ref);
	lua_setmetatable(L, -2);
}

EquippedProfileItems_t *check_EquippedProfileItems_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "EquippedProfileItems_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, EquippedProfileItems_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "EquippedProfileItems_t expected");
	return (EquippedProfileItems_t*)lua_touserdata(L, nParam);
}

EquippedProfileItems_t check_EquippedProfileItems_t(lua_State *L, int nParam) { return *check_EquippedProfileItems_t_ptr(L, nParam); }

void push_IPCountry_t(lua_State *L, IPCountry_t val) {
	IPCountry_t *ptr = (IPCountry_t*)lua_newuserdata(L, sizeof(IPCountry_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, IPCountry_tMetatable_ref);
	lua_setmetatable(L, -2);
}

IPCountry_t *check_IPCountry_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "IPCountry_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, IPCountry_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "IPCountry_t expected");
	return (IPCountry_t*)lua_touserdata(L, nParam);
}

IPCountry_t check_IPCountry_t(lua_State *L, int nParam) { return *check_IPCountry_t_ptr(L, nParam); }

void push_LowBatteryPower_t(lua_State *L, LowBatteryPower_t val) {
	LowBatteryPower_t *ptr = (LowBatteryPower_t*)lua_newuserdata(L, sizeof(LowBatteryPower_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, LowBatteryPower_tMetatable_ref);
	lua_setmetatable(L, -2);
}

LowBatteryPower_t *check_LowBatteryPower_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "LowBatteryPower_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, LowBatteryPower_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "LowBatteryPower_t expected");
	return (LowBatteryPower_t*)lua_touserdata(L, nParam);
}

LowBatteryPower_t check_LowBatteryPower_t(lua_State *L, int nParam) { return *check_LowBatteryPower_t_ptr(L, nParam); }

void push_SteamAPICallCompleted_t(lua_State *L, SteamAPICallCompleted_t val) {
	SteamAPICallCompleted_t *ptr = (SteamAPICallCompleted_t*)lua_newuserdata(L, sizeof(SteamAPICallCompleted_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamAPICallCompleted_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamAPICallCompleted_t *check_SteamAPICallCompleted_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamAPICallCompleted_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamAPICallCompleted_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamAPICallCompleted_t expected");
	return (SteamAPICallCompleted_t*)lua_touserdata(L, nParam);
}

SteamAPICallCompleted_t check_SteamAPICallCompleted_t(lua_State *L, int nParam) { return *check_SteamAPICallCompleted_t_ptr(L, nParam); }

void push_SteamShutdown_t(lua_State *L, SteamShutdown_t val) {
	SteamShutdown_t *ptr = (SteamShutdown_t*)lua_newuserdata(L, sizeof(SteamShutdown_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamShutdown_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamShutdown_t *check_SteamShutdown_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamShutdown_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamShutdown_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamShutdown_t expected");
	return (SteamShutdown_t*)lua_touserdata(L, nParam);
}

SteamShutdown_t check_SteamShutdown_t(lua_State *L, int nParam) { return *check_SteamShutdown_t_ptr(L, nParam); }

void push_CheckFileSignature_t(lua_State *L, CheckFileSignature_t val) {
	CheckFileSignature_t *ptr = (CheckFileSignature_t*)lua_newuserdata(L, sizeof(CheckFileSignature_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, CheckFileSignature_tMetatable_ref);
	lua_setmetatable(L, -2);
}

CheckFileSignature_t *check_CheckFileSignature_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "CheckFileSignature_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, CheckFileSignature_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "CheckFileSignature_t expected");
	return (CheckFileSignature_t*)lua_touserdata(L, nParam);
}

CheckFileSignature_t check_CheckFileSignature_t(lua_State *L, int nParam) { return *check_CheckFileSignature_t_ptr(L, nParam); }

void push_GamepadTextInputDismissed_t(lua_State *L, GamepadTextInputDismissed_t val) {
	GamepadTextInputDismissed_t *ptr = (GamepadTextInputDismissed_t*)lua_newuserdata(L, sizeof(GamepadTextInputDismissed_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, GamepadTextInputDismissed_tMetatable_ref);
	lua_setmetatable(L, -2);
}

GamepadTextInputDismissed_t *check_GamepadTextInputDismissed_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "GamepadTextInputDismissed_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, GamepadTextInputDismissed_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "GamepadTextInputDismissed_t expected");
	return (GamepadTextInputDismissed_t*)lua_touserdata(L, nParam);
}

GamepadTextInputDismissed_t check_GamepadTextInputDismissed_t(lua_State *L, int nParam) { return *check_GamepadTextInputDismissed_t_ptr(L, nParam); }

void push_AppResumingFromSuspend_t(lua_State *L, AppResumingFromSuspend_t val) {
	AppResumingFromSuspend_t *ptr = (AppResumingFromSuspend_t*)lua_newuserdata(L, sizeof(AppResumingFromSuspend_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, AppResumingFromSuspend_tMetatable_ref);
	lua_setmetatable(L, -2);
}

AppResumingFromSuspend_t *check_AppResumingFromSuspend_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "AppResumingFromSuspend_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, AppResumingFromSuspend_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "AppResumingFromSuspend_t expected");
	return (AppResumingFromSuspend_t*)lua_touserdata(L, nParam);
}

AppResumingFromSuspend_t check_AppResumingFromSuspend_t(lua_State *L, int nParam) { return *check_AppResumingFromSuspend_t_ptr(L, nParam); }

void push_FloatingGamepadTextInputDismissed_t(lua_State *L, FloatingGamepadTextInputDismissed_t val) {
	FloatingGamepadTextInputDismissed_t *ptr = (FloatingGamepadTextInputDismissed_t*)lua_newuserdata(L, sizeof(FloatingGamepadTextInputDismissed_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, FloatingGamepadTextInputDismissed_tMetatable_ref);
	lua_setmetatable(L, -2);
}

FloatingGamepadTextInputDismissed_t *check_FloatingGamepadTextInputDismissed_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "FloatingGamepadTextInputDismissed_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, FloatingGamepadTextInputDismissed_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "FloatingGamepadTextInputDismissed_t expected");
	return (FloatingGamepadTextInputDismissed_t*)lua_touserdata(L, nParam);
}

FloatingGamepadTextInputDismissed_t check_FloatingGamepadTextInputDismissed_t(lua_State *L, int nParam) { return *check_FloatingGamepadTextInputDismissed_t_ptr(L, nParam); }

void push_FilterTextDictionaryChanged_t(lua_State *L, FilterTextDictionaryChanged_t val) {
	FilterTextDictionaryChanged_t *ptr = (FilterTextDictionaryChanged_t*)lua_newuserdata(L, sizeof(FilterTextDictionaryChanged_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, FilterTextDictionaryChanged_tMetatable_ref);
	lua_setmetatable(L, -2);
}

FilterTextDictionaryChanged_t *check_FilterTextDictionaryChanged_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "FilterTextDictionaryChanged_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, FilterTextDictionaryChanged_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "FilterTextDictionaryChanged_t expected");
	return (FilterTextDictionaryChanged_t*)lua_touserdata(L, nParam);
}

FilterTextDictionaryChanged_t check_FilterTextDictionaryChanged_t(lua_State *L, int nParam) { return *check_FilterTextDictionaryChanged_t_ptr(L, nParam); }

void push_FavoritesListChanged_t(lua_State *L, FavoritesListChanged_t val) {
	FavoritesListChanged_t *ptr = (FavoritesListChanged_t*)lua_newuserdata(L, sizeof(FavoritesListChanged_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, FavoritesListChanged_tMetatable_ref);
	lua_setmetatable(L, -2);
}

FavoritesListChanged_t *check_FavoritesListChanged_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "FavoritesListChanged_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, FavoritesListChanged_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "FavoritesListChanged_t expected");
	return (FavoritesListChanged_t*)lua_touserdata(L, nParam);
}

FavoritesListChanged_t check_FavoritesListChanged_t(lua_State *L, int nParam) { return *check_FavoritesListChanged_t_ptr(L, nParam); }

void push_LobbyInvite_t(lua_State *L, LobbyInvite_t val) {
	LobbyInvite_t *ptr = (LobbyInvite_t*)lua_newuserdata(L, sizeof(LobbyInvite_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, LobbyInvite_tMetatable_ref);
	lua_setmetatable(L, -2);
}

LobbyInvite_t *check_LobbyInvite_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "LobbyInvite_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, LobbyInvite_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "LobbyInvite_t expected");
	return (LobbyInvite_t*)lua_touserdata(L, nParam);
}

LobbyInvite_t check_LobbyInvite_t(lua_State *L, int nParam) { return *check_LobbyInvite_t_ptr(L, nParam); }

void push_LobbyEnter_t(lua_State *L, LobbyEnter_t val) {
	LobbyEnter_t *ptr = (LobbyEnter_t*)lua_newuserdata(L, sizeof(LobbyEnter_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, LobbyEnter_tMetatable_ref);
	lua_setmetatable(L, -2);
}

LobbyEnter_t *check_LobbyEnter_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "LobbyEnter_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, LobbyEnter_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "LobbyEnter_t expected");
	return (LobbyEnter_t*)lua_touserdata(L, nParam);
}

LobbyEnter_t check_LobbyEnter_t(lua_State *L, int nParam) { return *check_LobbyEnter_t_ptr(L, nParam); }

void push_LobbyDataUpdate_t(lua_State *L, LobbyDataUpdate_t val) {
	LobbyDataUpdate_t *ptr = (LobbyDataUpdate_t*)lua_newuserdata(L, sizeof(LobbyDataUpdate_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, LobbyDataUpdate_tMetatable_ref);
	lua_setmetatable(L, -2);
}

LobbyDataUpdate_t *check_LobbyDataUpdate_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "LobbyDataUpdate_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, LobbyDataUpdate_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "LobbyDataUpdate_t expected");
	return (LobbyDataUpdate_t*)lua_touserdata(L, nParam);
}

LobbyDataUpdate_t check_LobbyDataUpdate_t(lua_State *L, int nParam) { return *check_LobbyDataUpdate_t_ptr(L, nParam); }

void push_LobbyChatUpdate_t(lua_State *L, LobbyChatUpdate_t val) {
	LobbyChatUpdate_t *ptr = (LobbyChatUpdate_t*)lua_newuserdata(L, sizeof(LobbyChatUpdate_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, LobbyChatUpdate_tMetatable_ref);
	lua_setmetatable(L, -2);
}

LobbyChatUpdate_t *check_LobbyChatUpdate_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "LobbyChatUpdate_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, LobbyChatUpdate_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "LobbyChatUpdate_t expected");
	return (LobbyChatUpdate_t*)lua_touserdata(L, nParam);
}

LobbyChatUpdate_t check_LobbyChatUpdate_t(lua_State *L, int nParam) { return *check_LobbyChatUpdate_t_ptr(L, nParam); }

void push_LobbyChatMsg_t(lua_State *L, LobbyChatMsg_t val) {
	LobbyChatMsg_t *ptr = (LobbyChatMsg_t*)lua_newuserdata(L, sizeof(LobbyChatMsg_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, LobbyChatMsg_tMetatable_ref);
	lua_setmetatable(L, -2);
}

LobbyChatMsg_t *check_LobbyChatMsg_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "LobbyChatMsg_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, LobbyChatMsg_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "LobbyChatMsg_t expected");
	return (LobbyChatMsg_t*)lua_touserdata(L, nParam);
}

LobbyChatMsg_t check_LobbyChatMsg_t(lua_State *L, int nParam) { return *check_LobbyChatMsg_t_ptr(L, nParam); }

void push_LobbyGameCreated_t(lua_State *L, LobbyGameCreated_t val) {
	LobbyGameCreated_t *ptr = (LobbyGameCreated_t*)lua_newuserdata(L, sizeof(LobbyGameCreated_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, LobbyGameCreated_tMetatable_ref);
	lua_setmetatable(L, -2);
}

LobbyGameCreated_t *check_LobbyGameCreated_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "LobbyGameCreated_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, LobbyGameCreated_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "LobbyGameCreated_t expected");
	return (LobbyGameCreated_t*)lua_touserdata(L, nParam);
}

LobbyGameCreated_t check_LobbyGameCreated_t(lua_State *L, int nParam) { return *check_LobbyGameCreated_t_ptr(L, nParam); }

void push_LobbyMatchList_t(lua_State *L, LobbyMatchList_t val) {
	LobbyMatchList_t *ptr = (LobbyMatchList_t*)lua_newuserdata(L, sizeof(LobbyMatchList_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, LobbyMatchList_tMetatable_ref);
	lua_setmetatable(L, -2);
}

LobbyMatchList_t *check_LobbyMatchList_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "LobbyMatchList_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, LobbyMatchList_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "LobbyMatchList_t expected");
	return (LobbyMatchList_t*)lua_touserdata(L, nParam);
}

LobbyMatchList_t check_LobbyMatchList_t(lua_State *L, int nParam) { return *check_LobbyMatchList_t_ptr(L, nParam); }

void push_LobbyKicked_t(lua_State *L, LobbyKicked_t val) {
	LobbyKicked_t *ptr = (LobbyKicked_t*)lua_newuserdata(L, sizeof(LobbyKicked_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, LobbyKicked_tMetatable_ref);
	lua_setmetatable(L, -2);
}

LobbyKicked_t *check_LobbyKicked_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "LobbyKicked_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, LobbyKicked_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "LobbyKicked_t expected");
	return (LobbyKicked_t*)lua_touserdata(L, nParam);
}

LobbyKicked_t check_LobbyKicked_t(lua_State *L, int nParam) { return *check_LobbyKicked_t_ptr(L, nParam); }

void push_LobbyCreated_t(lua_State *L, LobbyCreated_t val) {
	LobbyCreated_t *ptr = (LobbyCreated_t*)lua_newuserdata(L, sizeof(LobbyCreated_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, LobbyCreated_tMetatable_ref);
	lua_setmetatable(L, -2);
}

LobbyCreated_t *check_LobbyCreated_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "LobbyCreated_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, LobbyCreated_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "LobbyCreated_t expected");
	return (LobbyCreated_t*)lua_touserdata(L, nParam);
}

LobbyCreated_t check_LobbyCreated_t(lua_State *L, int nParam) { return *check_LobbyCreated_t_ptr(L, nParam); }

void push_FavoritesListAccountsUpdated_t(lua_State *L, FavoritesListAccountsUpdated_t val) {
	FavoritesListAccountsUpdated_t *ptr = (FavoritesListAccountsUpdated_t*)lua_newuserdata(L, sizeof(FavoritesListAccountsUpdated_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, FavoritesListAccountsUpdated_tMetatable_ref);
	lua_setmetatable(L, -2);
}

FavoritesListAccountsUpdated_t *check_FavoritesListAccountsUpdated_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "FavoritesListAccountsUpdated_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, FavoritesListAccountsUpdated_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "FavoritesListAccountsUpdated_t expected");
	return (FavoritesListAccountsUpdated_t*)lua_touserdata(L, nParam);
}

FavoritesListAccountsUpdated_t check_FavoritesListAccountsUpdated_t(lua_State *L, int nParam) { return *check_FavoritesListAccountsUpdated_t_ptr(L, nParam); }

void push_JoinPartyCallback_t(lua_State *L, JoinPartyCallback_t val) {
	JoinPartyCallback_t *ptr = (JoinPartyCallback_t*)lua_newuserdata(L, sizeof(JoinPartyCallback_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, JoinPartyCallback_tMetatable_ref);
	lua_setmetatable(L, -2);
}

JoinPartyCallback_t *check_JoinPartyCallback_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "JoinPartyCallback_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, JoinPartyCallback_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "JoinPartyCallback_t expected");
	return (JoinPartyCallback_t*)lua_touserdata(L, nParam);
}

JoinPartyCallback_t check_JoinPartyCallback_t(lua_State *L, int nParam) { return *check_JoinPartyCallback_t_ptr(L, nParam); }

void push_CreateBeaconCallback_t(lua_State *L, CreateBeaconCallback_t val) {
	CreateBeaconCallback_t *ptr = (CreateBeaconCallback_t*)lua_newuserdata(L, sizeof(CreateBeaconCallback_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, CreateBeaconCallback_tMetatable_ref);
	lua_setmetatable(L, -2);
}

CreateBeaconCallback_t *check_CreateBeaconCallback_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "CreateBeaconCallback_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, CreateBeaconCallback_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "CreateBeaconCallback_t expected");
	return (CreateBeaconCallback_t*)lua_touserdata(L, nParam);
}

CreateBeaconCallback_t check_CreateBeaconCallback_t(lua_State *L, int nParam) { return *check_CreateBeaconCallback_t_ptr(L, nParam); }

void push_ReservationNotificationCallback_t(lua_State *L, ReservationNotificationCallback_t val) {
	ReservationNotificationCallback_t *ptr = (ReservationNotificationCallback_t*)lua_newuserdata(L, sizeof(ReservationNotificationCallback_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, ReservationNotificationCallback_tMetatable_ref);
	lua_setmetatable(L, -2);
}

ReservationNotificationCallback_t *check_ReservationNotificationCallback_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "ReservationNotificationCallback_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, ReservationNotificationCallback_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "ReservationNotificationCallback_t expected");
	return (ReservationNotificationCallback_t*)lua_touserdata(L, nParam);
}

ReservationNotificationCallback_t check_ReservationNotificationCallback_t(lua_State *L, int nParam) { return *check_ReservationNotificationCallback_t_ptr(L, nParam); }

void push_ChangeNumOpenSlotsCallback_t(lua_State *L, ChangeNumOpenSlotsCallback_t val) {
	ChangeNumOpenSlotsCallback_t *ptr = (ChangeNumOpenSlotsCallback_t*)lua_newuserdata(L, sizeof(ChangeNumOpenSlotsCallback_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, ChangeNumOpenSlotsCallback_tMetatable_ref);
	lua_setmetatable(L, -2);
}

ChangeNumOpenSlotsCallback_t *check_ChangeNumOpenSlotsCallback_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "ChangeNumOpenSlotsCallback_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, ChangeNumOpenSlotsCallback_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "ChangeNumOpenSlotsCallback_t expected");
	return (ChangeNumOpenSlotsCallback_t*)lua_touserdata(L, nParam);
}

ChangeNumOpenSlotsCallback_t check_ChangeNumOpenSlotsCallback_t(lua_State *L, int nParam) { return *check_ChangeNumOpenSlotsCallback_t_ptr(L, nParam); }

void push_AvailableBeaconLocationsUpdated_t(lua_State *L, AvailableBeaconLocationsUpdated_t val) {
	AvailableBeaconLocationsUpdated_t *ptr = (AvailableBeaconLocationsUpdated_t*)lua_newuserdata(L, sizeof(AvailableBeaconLocationsUpdated_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, AvailableBeaconLocationsUpdated_tMetatable_ref);
	lua_setmetatable(L, -2);
}

AvailableBeaconLocationsUpdated_t *check_AvailableBeaconLocationsUpdated_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "AvailableBeaconLocationsUpdated_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, AvailableBeaconLocationsUpdated_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "AvailableBeaconLocationsUpdated_t expected");
	return (AvailableBeaconLocationsUpdated_t*)lua_touserdata(L, nParam);
}

AvailableBeaconLocationsUpdated_t check_AvailableBeaconLocationsUpdated_t(lua_State *L, int nParam) { return *check_AvailableBeaconLocationsUpdated_t_ptr(L, nParam); }

void push_ActiveBeaconsUpdated_t(lua_State *L, ActiveBeaconsUpdated_t val) {
	ActiveBeaconsUpdated_t *ptr = (ActiveBeaconsUpdated_t*)lua_newuserdata(L, sizeof(ActiveBeaconsUpdated_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, ActiveBeaconsUpdated_tMetatable_ref);
	lua_setmetatable(L, -2);
}

ActiveBeaconsUpdated_t *check_ActiveBeaconsUpdated_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "ActiveBeaconsUpdated_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, ActiveBeaconsUpdated_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "ActiveBeaconsUpdated_t expected");
	return (ActiveBeaconsUpdated_t*)lua_touserdata(L, nParam);
}

ActiveBeaconsUpdated_t check_ActiveBeaconsUpdated_t(lua_State *L, int nParam) { return *check_ActiveBeaconsUpdated_t_ptr(L, nParam); }

void push_RemoteStorageFileShareResult_t(lua_State *L, RemoteStorageFileShareResult_t val) {
	RemoteStorageFileShareResult_t *ptr = (RemoteStorageFileShareResult_t*)lua_newuserdata(L, sizeof(RemoteStorageFileShareResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageFileShareResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemoteStorageFileShareResult_t *check_RemoteStorageFileShareResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemoteStorageFileShareResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageFileShareResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemoteStorageFileShareResult_t expected");
	return (RemoteStorageFileShareResult_t*)lua_touserdata(L, nParam);
}

RemoteStorageFileShareResult_t check_RemoteStorageFileShareResult_t(lua_State *L, int nParam) { return *check_RemoteStorageFileShareResult_t_ptr(L, nParam); }

void push_RemoteStoragePublishFileResult_t(lua_State *L, RemoteStoragePublishFileResult_t val) {
	RemoteStoragePublishFileResult_t *ptr = (RemoteStoragePublishFileResult_t*)lua_newuserdata(L, sizeof(RemoteStoragePublishFileResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStoragePublishFileResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemoteStoragePublishFileResult_t *check_RemoteStoragePublishFileResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemoteStoragePublishFileResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStoragePublishFileResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemoteStoragePublishFileResult_t expected");
	return (RemoteStoragePublishFileResult_t*)lua_touserdata(L, nParam);
}

RemoteStoragePublishFileResult_t check_RemoteStoragePublishFileResult_t(lua_State *L, int nParam) { return *check_RemoteStoragePublishFileResult_t_ptr(L, nParam); }

void push_RemoteStorageDeletePublishedFileResult_t(lua_State *L, RemoteStorageDeletePublishedFileResult_t val) {
	RemoteStorageDeletePublishedFileResult_t *ptr = (RemoteStorageDeletePublishedFileResult_t*)lua_newuserdata(L, sizeof(RemoteStorageDeletePublishedFileResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageDeletePublishedFileResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemoteStorageDeletePublishedFileResult_t *check_RemoteStorageDeletePublishedFileResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemoteStorageDeletePublishedFileResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageDeletePublishedFileResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemoteStorageDeletePublishedFileResult_t expected");
	return (RemoteStorageDeletePublishedFileResult_t*)lua_touserdata(L, nParam);
}

RemoteStorageDeletePublishedFileResult_t check_RemoteStorageDeletePublishedFileResult_t(lua_State *L, int nParam) { return *check_RemoteStorageDeletePublishedFileResult_t_ptr(L, nParam); }

void push_RemoteStorageEnumerateUserPublishedFilesResult_t(lua_State *L, RemoteStorageEnumerateUserPublishedFilesResult_t val) {
	RemoteStorageEnumerateUserPublishedFilesResult_t *ptr = (RemoteStorageEnumerateUserPublishedFilesResult_t*)lua_newuserdata(L, sizeof(RemoteStorageEnumerateUserPublishedFilesResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageEnumerateUserPublishedFilesResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemoteStorageEnumerateUserPublishedFilesResult_t *check_RemoteStorageEnumerateUserPublishedFilesResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemoteStorageEnumerateUserPublishedFilesResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageEnumerateUserPublishedFilesResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemoteStorageEnumerateUserPublishedFilesResult_t expected");
	return (RemoteStorageEnumerateUserPublishedFilesResult_t*)lua_touserdata(L, nParam);
}

RemoteStorageEnumerateUserPublishedFilesResult_t check_RemoteStorageEnumerateUserPublishedFilesResult_t(lua_State *L, int nParam) { return *check_RemoteStorageEnumerateUserPublishedFilesResult_t_ptr(L, nParam); }

void push_RemoteStorageSubscribePublishedFileResult_t(lua_State *L, RemoteStorageSubscribePublishedFileResult_t val) {
	RemoteStorageSubscribePublishedFileResult_t *ptr = (RemoteStorageSubscribePublishedFileResult_t*)lua_newuserdata(L, sizeof(RemoteStorageSubscribePublishedFileResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageSubscribePublishedFileResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemoteStorageSubscribePublishedFileResult_t *check_RemoteStorageSubscribePublishedFileResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemoteStorageSubscribePublishedFileResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageSubscribePublishedFileResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemoteStorageSubscribePublishedFileResult_t expected");
	return (RemoteStorageSubscribePublishedFileResult_t*)lua_touserdata(L, nParam);
}

RemoteStorageSubscribePublishedFileResult_t check_RemoteStorageSubscribePublishedFileResult_t(lua_State *L, int nParam) { return *check_RemoteStorageSubscribePublishedFileResult_t_ptr(L, nParam); }

void push_RemoteStorageEnumerateUserSubscribedFilesResult_t(lua_State *L, RemoteStorageEnumerateUserSubscribedFilesResult_t val) {
	RemoteStorageEnumerateUserSubscribedFilesResult_t *ptr = (RemoteStorageEnumerateUserSubscribedFilesResult_t*)lua_newuserdata(L, sizeof(RemoteStorageEnumerateUserSubscribedFilesResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageEnumerateUserSubscribedFilesResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemoteStorageEnumerateUserSubscribedFilesResult_t *check_RemoteStorageEnumerateUserSubscribedFilesResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemoteStorageEnumerateUserSubscribedFilesResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageEnumerateUserSubscribedFilesResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemoteStorageEnumerateUserSubscribedFilesResult_t expected");
	return (RemoteStorageEnumerateUserSubscribedFilesResult_t*)lua_touserdata(L, nParam);
}

RemoteStorageEnumerateUserSubscribedFilesResult_t check_RemoteStorageEnumerateUserSubscribedFilesResult_t(lua_State *L, int nParam) { return *check_RemoteStorageEnumerateUserSubscribedFilesResult_t_ptr(L, nParam); }

void push_RemoteStorageUnsubscribePublishedFileResult_t(lua_State *L, RemoteStorageUnsubscribePublishedFileResult_t val) {
	RemoteStorageUnsubscribePublishedFileResult_t *ptr = (RemoteStorageUnsubscribePublishedFileResult_t*)lua_newuserdata(L, sizeof(RemoteStorageUnsubscribePublishedFileResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageUnsubscribePublishedFileResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemoteStorageUnsubscribePublishedFileResult_t *check_RemoteStorageUnsubscribePublishedFileResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemoteStorageUnsubscribePublishedFileResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageUnsubscribePublishedFileResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemoteStorageUnsubscribePublishedFileResult_t expected");
	return (RemoteStorageUnsubscribePublishedFileResult_t*)lua_touserdata(L, nParam);
}

RemoteStorageUnsubscribePublishedFileResult_t check_RemoteStorageUnsubscribePublishedFileResult_t(lua_State *L, int nParam) { return *check_RemoteStorageUnsubscribePublishedFileResult_t_ptr(L, nParam); }

void push_RemoteStorageUpdatePublishedFileResult_t(lua_State *L, RemoteStorageUpdatePublishedFileResult_t val) {
	RemoteStorageUpdatePublishedFileResult_t *ptr = (RemoteStorageUpdatePublishedFileResult_t*)lua_newuserdata(L, sizeof(RemoteStorageUpdatePublishedFileResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageUpdatePublishedFileResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemoteStorageUpdatePublishedFileResult_t *check_RemoteStorageUpdatePublishedFileResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemoteStorageUpdatePublishedFileResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageUpdatePublishedFileResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemoteStorageUpdatePublishedFileResult_t expected");
	return (RemoteStorageUpdatePublishedFileResult_t*)lua_touserdata(L, nParam);
}

RemoteStorageUpdatePublishedFileResult_t check_RemoteStorageUpdatePublishedFileResult_t(lua_State *L, int nParam) { return *check_RemoteStorageUpdatePublishedFileResult_t_ptr(L, nParam); }

void push_RemoteStorageDownloadUGCResult_t(lua_State *L, RemoteStorageDownloadUGCResult_t val) {
	RemoteStorageDownloadUGCResult_t *ptr = (RemoteStorageDownloadUGCResult_t*)lua_newuserdata(L, sizeof(RemoteStorageDownloadUGCResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageDownloadUGCResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemoteStorageDownloadUGCResult_t *check_RemoteStorageDownloadUGCResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemoteStorageDownloadUGCResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageDownloadUGCResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemoteStorageDownloadUGCResult_t expected");
	return (RemoteStorageDownloadUGCResult_t*)lua_touserdata(L, nParam);
}

RemoteStorageDownloadUGCResult_t check_RemoteStorageDownloadUGCResult_t(lua_State *L, int nParam) { return *check_RemoteStorageDownloadUGCResult_t_ptr(L, nParam); }

void push_RemoteStorageGetPublishedFileDetailsResult_t(lua_State *L, RemoteStorageGetPublishedFileDetailsResult_t val) {
	RemoteStorageGetPublishedFileDetailsResult_t *ptr = (RemoteStorageGetPublishedFileDetailsResult_t*)lua_newuserdata(L, sizeof(RemoteStorageGetPublishedFileDetailsResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageGetPublishedFileDetailsResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemoteStorageGetPublishedFileDetailsResult_t *check_RemoteStorageGetPublishedFileDetailsResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemoteStorageGetPublishedFileDetailsResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageGetPublishedFileDetailsResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemoteStorageGetPublishedFileDetailsResult_t expected");
	return (RemoteStorageGetPublishedFileDetailsResult_t*)lua_touserdata(L, nParam);
}

RemoteStorageGetPublishedFileDetailsResult_t check_RemoteStorageGetPublishedFileDetailsResult_t(lua_State *L, int nParam) { return *check_RemoteStorageGetPublishedFileDetailsResult_t_ptr(L, nParam); }

void push_RemoteStorageEnumerateWorkshopFilesResult_t(lua_State *L, RemoteStorageEnumerateWorkshopFilesResult_t val) {
	RemoteStorageEnumerateWorkshopFilesResult_t *ptr = (RemoteStorageEnumerateWorkshopFilesResult_t*)lua_newuserdata(L, sizeof(RemoteStorageEnumerateWorkshopFilesResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageEnumerateWorkshopFilesResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemoteStorageEnumerateWorkshopFilesResult_t *check_RemoteStorageEnumerateWorkshopFilesResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemoteStorageEnumerateWorkshopFilesResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageEnumerateWorkshopFilesResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemoteStorageEnumerateWorkshopFilesResult_t expected");
	return (RemoteStorageEnumerateWorkshopFilesResult_t*)lua_touserdata(L, nParam);
}

RemoteStorageEnumerateWorkshopFilesResult_t check_RemoteStorageEnumerateWorkshopFilesResult_t(lua_State *L, int nParam) { return *check_RemoteStorageEnumerateWorkshopFilesResult_t_ptr(L, nParam); }

void push_RemoteStorageGetPublishedItemVoteDetailsResult_t(lua_State *L, RemoteStorageGetPublishedItemVoteDetailsResult_t val) {
	RemoteStorageGetPublishedItemVoteDetailsResult_t *ptr = (RemoteStorageGetPublishedItemVoteDetailsResult_t*)lua_newuserdata(L, sizeof(RemoteStorageGetPublishedItemVoteDetailsResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageGetPublishedItemVoteDetailsResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemoteStorageGetPublishedItemVoteDetailsResult_t *check_RemoteStorageGetPublishedItemVoteDetailsResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemoteStorageGetPublishedItemVoteDetailsResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageGetPublishedItemVoteDetailsResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemoteStorageGetPublishedItemVoteDetailsResult_t expected");
	return (RemoteStorageGetPublishedItemVoteDetailsResult_t*)lua_touserdata(L, nParam);
}

RemoteStorageGetPublishedItemVoteDetailsResult_t check_RemoteStorageGetPublishedItemVoteDetailsResult_t(lua_State *L, int nParam) { return *check_RemoteStorageGetPublishedItemVoteDetailsResult_t_ptr(L, nParam); }

void push_RemoteStoragePublishedFileSubscribed_t(lua_State *L, RemoteStoragePublishedFileSubscribed_t val) {
	RemoteStoragePublishedFileSubscribed_t *ptr = (RemoteStoragePublishedFileSubscribed_t*)lua_newuserdata(L, sizeof(RemoteStoragePublishedFileSubscribed_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStoragePublishedFileSubscribed_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemoteStoragePublishedFileSubscribed_t *check_RemoteStoragePublishedFileSubscribed_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemoteStoragePublishedFileSubscribed_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStoragePublishedFileSubscribed_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemoteStoragePublishedFileSubscribed_t expected");
	return (RemoteStoragePublishedFileSubscribed_t*)lua_touserdata(L, nParam);
}

RemoteStoragePublishedFileSubscribed_t check_RemoteStoragePublishedFileSubscribed_t(lua_State *L, int nParam) { return *check_RemoteStoragePublishedFileSubscribed_t_ptr(L, nParam); }

void push_RemoteStoragePublishedFileUnsubscribed_t(lua_State *L, RemoteStoragePublishedFileUnsubscribed_t val) {
	RemoteStoragePublishedFileUnsubscribed_t *ptr = (RemoteStoragePublishedFileUnsubscribed_t*)lua_newuserdata(L, sizeof(RemoteStoragePublishedFileUnsubscribed_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStoragePublishedFileUnsubscribed_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemoteStoragePublishedFileUnsubscribed_t *check_RemoteStoragePublishedFileUnsubscribed_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemoteStoragePublishedFileUnsubscribed_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStoragePublishedFileUnsubscribed_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemoteStoragePublishedFileUnsubscribed_t expected");
	return (RemoteStoragePublishedFileUnsubscribed_t*)lua_touserdata(L, nParam);
}

RemoteStoragePublishedFileUnsubscribed_t check_RemoteStoragePublishedFileUnsubscribed_t(lua_State *L, int nParam) { return *check_RemoteStoragePublishedFileUnsubscribed_t_ptr(L, nParam); }

void push_RemoteStoragePublishedFileDeleted_t(lua_State *L, RemoteStoragePublishedFileDeleted_t val) {
	RemoteStoragePublishedFileDeleted_t *ptr = (RemoteStoragePublishedFileDeleted_t*)lua_newuserdata(L, sizeof(RemoteStoragePublishedFileDeleted_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStoragePublishedFileDeleted_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemoteStoragePublishedFileDeleted_t *check_RemoteStoragePublishedFileDeleted_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemoteStoragePublishedFileDeleted_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStoragePublishedFileDeleted_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemoteStoragePublishedFileDeleted_t expected");
	return (RemoteStoragePublishedFileDeleted_t*)lua_touserdata(L, nParam);
}

RemoteStoragePublishedFileDeleted_t check_RemoteStoragePublishedFileDeleted_t(lua_State *L, int nParam) { return *check_RemoteStoragePublishedFileDeleted_t_ptr(L, nParam); }

void push_RemoteStorageUpdateUserPublishedItemVoteResult_t(lua_State *L, RemoteStorageUpdateUserPublishedItemVoteResult_t val) {
	RemoteStorageUpdateUserPublishedItemVoteResult_t *ptr = (RemoteStorageUpdateUserPublishedItemVoteResult_t*)lua_newuserdata(L, sizeof(RemoteStorageUpdateUserPublishedItemVoteResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageUpdateUserPublishedItemVoteResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemoteStorageUpdateUserPublishedItemVoteResult_t *check_RemoteStorageUpdateUserPublishedItemVoteResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemoteStorageUpdateUserPublishedItemVoteResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageUpdateUserPublishedItemVoteResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemoteStorageUpdateUserPublishedItemVoteResult_t expected");
	return (RemoteStorageUpdateUserPublishedItemVoteResult_t*)lua_touserdata(L, nParam);
}

RemoteStorageUpdateUserPublishedItemVoteResult_t check_RemoteStorageUpdateUserPublishedItemVoteResult_t(lua_State *L, int nParam) { return *check_RemoteStorageUpdateUserPublishedItemVoteResult_t_ptr(L, nParam); }

void push_RemoteStorageUserVoteDetails_t(lua_State *L, RemoteStorageUserVoteDetails_t val) {
	RemoteStorageUserVoteDetails_t *ptr = (RemoteStorageUserVoteDetails_t*)lua_newuserdata(L, sizeof(RemoteStorageUserVoteDetails_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageUserVoteDetails_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemoteStorageUserVoteDetails_t *check_RemoteStorageUserVoteDetails_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemoteStorageUserVoteDetails_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageUserVoteDetails_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemoteStorageUserVoteDetails_t expected");
	return (RemoteStorageUserVoteDetails_t*)lua_touserdata(L, nParam);
}

RemoteStorageUserVoteDetails_t check_RemoteStorageUserVoteDetails_t(lua_State *L, int nParam) { return *check_RemoteStorageUserVoteDetails_t_ptr(L, nParam); }

void push_RemoteStorageEnumerateUserSharedWorkshopFilesResult_t(lua_State *L, RemoteStorageEnumerateUserSharedWorkshopFilesResult_t val) {
	RemoteStorageEnumerateUserSharedWorkshopFilesResult_t *ptr = (RemoteStorageEnumerateUserSharedWorkshopFilesResult_t*)lua_newuserdata(L, sizeof(RemoteStorageEnumerateUserSharedWorkshopFilesResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageEnumerateUserSharedWorkshopFilesResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemoteStorageEnumerateUserSharedWorkshopFilesResult_t *check_RemoteStorageEnumerateUserSharedWorkshopFilesResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemoteStorageEnumerateUserSharedWorkshopFilesResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageEnumerateUserSharedWorkshopFilesResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemoteStorageEnumerateUserSharedWorkshopFilesResult_t expected");
	return (RemoteStorageEnumerateUserSharedWorkshopFilesResult_t*)lua_touserdata(L, nParam);
}

RemoteStorageEnumerateUserSharedWorkshopFilesResult_t check_RemoteStorageEnumerateUserSharedWorkshopFilesResult_t(lua_State *L, int nParam) { return *check_RemoteStorageEnumerateUserSharedWorkshopFilesResult_t_ptr(L, nParam); }

void push_RemoteStorageSetUserPublishedFileActionResult_t(lua_State *L, RemoteStorageSetUserPublishedFileActionResult_t val) {
	RemoteStorageSetUserPublishedFileActionResult_t *ptr = (RemoteStorageSetUserPublishedFileActionResult_t*)lua_newuserdata(L, sizeof(RemoteStorageSetUserPublishedFileActionResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageSetUserPublishedFileActionResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemoteStorageSetUserPublishedFileActionResult_t *check_RemoteStorageSetUserPublishedFileActionResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemoteStorageSetUserPublishedFileActionResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageSetUserPublishedFileActionResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemoteStorageSetUserPublishedFileActionResult_t expected");
	return (RemoteStorageSetUserPublishedFileActionResult_t*)lua_touserdata(L, nParam);
}

RemoteStorageSetUserPublishedFileActionResult_t check_RemoteStorageSetUserPublishedFileActionResult_t(lua_State *L, int nParam) { return *check_RemoteStorageSetUserPublishedFileActionResult_t_ptr(L, nParam); }

void push_RemoteStorageEnumeratePublishedFilesByUserActionResult_t(lua_State *L, RemoteStorageEnumeratePublishedFilesByUserActionResult_t val) {
	RemoteStorageEnumeratePublishedFilesByUserActionResult_t *ptr = (RemoteStorageEnumeratePublishedFilesByUserActionResult_t*)lua_newuserdata(L, sizeof(RemoteStorageEnumeratePublishedFilesByUserActionResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageEnumeratePublishedFilesByUserActionResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemoteStorageEnumeratePublishedFilesByUserActionResult_t *check_RemoteStorageEnumeratePublishedFilesByUserActionResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemoteStorageEnumeratePublishedFilesByUserActionResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageEnumeratePublishedFilesByUserActionResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemoteStorageEnumeratePublishedFilesByUserActionResult_t expected");
	return (RemoteStorageEnumeratePublishedFilesByUserActionResult_t*)lua_touserdata(L, nParam);
}

RemoteStorageEnumeratePublishedFilesByUserActionResult_t check_RemoteStorageEnumeratePublishedFilesByUserActionResult_t(lua_State *L, int nParam) { return *check_RemoteStorageEnumeratePublishedFilesByUserActionResult_t_ptr(L, nParam); }

void push_RemoteStoragePublishFileProgress_t(lua_State *L, RemoteStoragePublishFileProgress_t val) {
	RemoteStoragePublishFileProgress_t *ptr = (RemoteStoragePublishFileProgress_t*)lua_newuserdata(L, sizeof(RemoteStoragePublishFileProgress_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStoragePublishFileProgress_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemoteStoragePublishFileProgress_t *check_RemoteStoragePublishFileProgress_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemoteStoragePublishFileProgress_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStoragePublishFileProgress_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemoteStoragePublishFileProgress_t expected");
	return (RemoteStoragePublishFileProgress_t*)lua_touserdata(L, nParam);
}

RemoteStoragePublishFileProgress_t check_RemoteStoragePublishFileProgress_t(lua_State *L, int nParam) { return *check_RemoteStoragePublishFileProgress_t_ptr(L, nParam); }

void push_RemoteStoragePublishedFileUpdated_t(lua_State *L, RemoteStoragePublishedFileUpdated_t val) {
	RemoteStoragePublishedFileUpdated_t *ptr = (RemoteStoragePublishedFileUpdated_t*)lua_newuserdata(L, sizeof(RemoteStoragePublishedFileUpdated_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStoragePublishedFileUpdated_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemoteStoragePublishedFileUpdated_t *check_RemoteStoragePublishedFileUpdated_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemoteStoragePublishedFileUpdated_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStoragePublishedFileUpdated_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemoteStoragePublishedFileUpdated_t expected");
	return (RemoteStoragePublishedFileUpdated_t*)lua_touserdata(L, nParam);
}

RemoteStoragePublishedFileUpdated_t check_RemoteStoragePublishedFileUpdated_t(lua_State *L, int nParam) { return *check_RemoteStoragePublishedFileUpdated_t_ptr(L, nParam); }

void push_RemoteStorageFileWriteAsyncComplete_t(lua_State *L, RemoteStorageFileWriteAsyncComplete_t val) {
	RemoteStorageFileWriteAsyncComplete_t *ptr = (RemoteStorageFileWriteAsyncComplete_t*)lua_newuserdata(L, sizeof(RemoteStorageFileWriteAsyncComplete_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageFileWriteAsyncComplete_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemoteStorageFileWriteAsyncComplete_t *check_RemoteStorageFileWriteAsyncComplete_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemoteStorageFileWriteAsyncComplete_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageFileWriteAsyncComplete_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemoteStorageFileWriteAsyncComplete_t expected");
	return (RemoteStorageFileWriteAsyncComplete_t*)lua_touserdata(L, nParam);
}

RemoteStorageFileWriteAsyncComplete_t check_RemoteStorageFileWriteAsyncComplete_t(lua_State *L, int nParam) { return *check_RemoteStorageFileWriteAsyncComplete_t_ptr(L, nParam); }

void push_RemoteStorageFileReadAsyncComplete_t(lua_State *L, RemoteStorageFileReadAsyncComplete_t val) {
	RemoteStorageFileReadAsyncComplete_t *ptr = (RemoteStorageFileReadAsyncComplete_t*)lua_newuserdata(L, sizeof(RemoteStorageFileReadAsyncComplete_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageFileReadAsyncComplete_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemoteStorageFileReadAsyncComplete_t *check_RemoteStorageFileReadAsyncComplete_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemoteStorageFileReadAsyncComplete_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageFileReadAsyncComplete_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemoteStorageFileReadAsyncComplete_t expected");
	return (RemoteStorageFileReadAsyncComplete_t*)lua_touserdata(L, nParam);
}

RemoteStorageFileReadAsyncComplete_t check_RemoteStorageFileReadAsyncComplete_t(lua_State *L, int nParam) { return *check_RemoteStorageFileReadAsyncComplete_t_ptr(L, nParam); }

void push_RemoteStorageLocalFileChange_t(lua_State *L, RemoteStorageLocalFileChange_t val) {
	RemoteStorageLocalFileChange_t *ptr = (RemoteStorageLocalFileChange_t*)lua_newuserdata(L, sizeof(RemoteStorageLocalFileChange_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageLocalFileChange_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemoteStorageLocalFileChange_t *check_RemoteStorageLocalFileChange_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemoteStorageLocalFileChange_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoteStorageLocalFileChange_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemoteStorageLocalFileChange_t expected");
	return (RemoteStorageLocalFileChange_t*)lua_touserdata(L, nParam);
}

RemoteStorageLocalFileChange_t check_RemoteStorageLocalFileChange_t(lua_State *L, int nParam) { return *check_RemoteStorageLocalFileChange_t_ptr(L, nParam); }

void push_UserStatsReceived_t(lua_State *L, UserStatsReceived_t val) {
	UserStatsReceived_t *ptr = (UserStatsReceived_t*)lua_newuserdata(L, sizeof(UserStatsReceived_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, UserStatsReceived_tMetatable_ref);
	lua_setmetatable(L, -2);
}

UserStatsReceived_t *check_UserStatsReceived_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "UserStatsReceived_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, UserStatsReceived_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "UserStatsReceived_t expected");
	return (UserStatsReceived_t*)lua_touserdata(L, nParam);
}

UserStatsReceived_t check_UserStatsReceived_t(lua_State *L, int nParam) { return *check_UserStatsReceived_t_ptr(L, nParam); }

void push_UserStatsStored_t(lua_State *L, UserStatsStored_t val) {
	UserStatsStored_t *ptr = (UserStatsStored_t*)lua_newuserdata(L, sizeof(UserStatsStored_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, UserStatsStored_tMetatable_ref);
	lua_setmetatable(L, -2);
}

UserStatsStored_t *check_UserStatsStored_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "UserStatsStored_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, UserStatsStored_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "UserStatsStored_t expected");
	return (UserStatsStored_t*)lua_touserdata(L, nParam);
}

UserStatsStored_t check_UserStatsStored_t(lua_State *L, int nParam) { return *check_UserStatsStored_t_ptr(L, nParam); }

void push_UserAchievementStored_t(lua_State *L, UserAchievementStored_t val) {
	UserAchievementStored_t *ptr = (UserAchievementStored_t*)lua_newuserdata(L, sizeof(UserAchievementStored_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, UserAchievementStored_tMetatable_ref);
	lua_setmetatable(L, -2);
}

UserAchievementStored_t *check_UserAchievementStored_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "UserAchievementStored_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, UserAchievementStored_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "UserAchievementStored_t expected");
	return (UserAchievementStored_t*)lua_touserdata(L, nParam);
}

UserAchievementStored_t check_UserAchievementStored_t(lua_State *L, int nParam) { return *check_UserAchievementStored_t_ptr(L, nParam); }

void push_LeaderboardFindResult_t(lua_State *L, LeaderboardFindResult_t val) {
	LeaderboardFindResult_t *ptr = (LeaderboardFindResult_t*)lua_newuserdata(L, sizeof(LeaderboardFindResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, LeaderboardFindResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

LeaderboardFindResult_t *check_LeaderboardFindResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "LeaderboardFindResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, LeaderboardFindResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "LeaderboardFindResult_t expected");
	return (LeaderboardFindResult_t*)lua_touserdata(L, nParam);
}

LeaderboardFindResult_t check_LeaderboardFindResult_t(lua_State *L, int nParam) { return *check_LeaderboardFindResult_t_ptr(L, nParam); }

void push_LeaderboardScoresDownloaded_t(lua_State *L, LeaderboardScoresDownloaded_t val) {
	LeaderboardScoresDownloaded_t *ptr = (LeaderboardScoresDownloaded_t*)lua_newuserdata(L, sizeof(LeaderboardScoresDownloaded_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, LeaderboardScoresDownloaded_tMetatable_ref);
	lua_setmetatable(L, -2);
}

LeaderboardScoresDownloaded_t *check_LeaderboardScoresDownloaded_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "LeaderboardScoresDownloaded_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, LeaderboardScoresDownloaded_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "LeaderboardScoresDownloaded_t expected");
	return (LeaderboardScoresDownloaded_t*)lua_touserdata(L, nParam);
}

LeaderboardScoresDownloaded_t check_LeaderboardScoresDownloaded_t(lua_State *L, int nParam) { return *check_LeaderboardScoresDownloaded_t_ptr(L, nParam); }

void push_LeaderboardScoreUploaded_t(lua_State *L, LeaderboardScoreUploaded_t val) {
	LeaderboardScoreUploaded_t *ptr = (LeaderboardScoreUploaded_t*)lua_newuserdata(L, sizeof(LeaderboardScoreUploaded_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, LeaderboardScoreUploaded_tMetatable_ref);
	lua_setmetatable(L, -2);
}

LeaderboardScoreUploaded_t *check_LeaderboardScoreUploaded_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "LeaderboardScoreUploaded_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, LeaderboardScoreUploaded_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "LeaderboardScoreUploaded_t expected");
	return (LeaderboardScoreUploaded_t*)lua_touserdata(L, nParam);
}

LeaderboardScoreUploaded_t check_LeaderboardScoreUploaded_t(lua_State *L, int nParam) { return *check_LeaderboardScoreUploaded_t_ptr(L, nParam); }

void push_NumberOfCurrentPlayers_t(lua_State *L, NumberOfCurrentPlayers_t val) {
	NumberOfCurrentPlayers_t *ptr = (NumberOfCurrentPlayers_t*)lua_newuserdata(L, sizeof(NumberOfCurrentPlayers_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, NumberOfCurrentPlayers_tMetatable_ref);
	lua_setmetatable(L, -2);
}

NumberOfCurrentPlayers_t *check_NumberOfCurrentPlayers_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "NumberOfCurrentPlayers_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, NumberOfCurrentPlayers_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "NumberOfCurrentPlayers_t expected");
	return (NumberOfCurrentPlayers_t*)lua_touserdata(L, nParam);
}

NumberOfCurrentPlayers_t check_NumberOfCurrentPlayers_t(lua_State *L, int nParam) { return *check_NumberOfCurrentPlayers_t_ptr(L, nParam); }

void push_UserStatsUnloaded_t(lua_State *L, UserStatsUnloaded_t val) {
	UserStatsUnloaded_t *ptr = (UserStatsUnloaded_t*)lua_newuserdata(L, sizeof(UserStatsUnloaded_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, UserStatsUnloaded_tMetatable_ref);
	lua_setmetatable(L, -2);
}

UserStatsUnloaded_t *check_UserStatsUnloaded_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "UserStatsUnloaded_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, UserStatsUnloaded_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "UserStatsUnloaded_t expected");
	return (UserStatsUnloaded_t*)lua_touserdata(L, nParam);
}

UserStatsUnloaded_t check_UserStatsUnloaded_t(lua_State *L, int nParam) { return *check_UserStatsUnloaded_t_ptr(L, nParam); }

void push_UserAchievementIconFetched_t(lua_State *L, UserAchievementIconFetched_t val) {
	UserAchievementIconFetched_t *ptr = (UserAchievementIconFetched_t*)lua_newuserdata(L, sizeof(UserAchievementIconFetched_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, UserAchievementIconFetched_tMetatable_ref);
	lua_setmetatable(L, -2);
}

UserAchievementIconFetched_t *check_UserAchievementIconFetched_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "UserAchievementIconFetched_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, UserAchievementIconFetched_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "UserAchievementIconFetched_t expected");
	return (UserAchievementIconFetched_t*)lua_touserdata(L, nParam);
}

UserAchievementIconFetched_t check_UserAchievementIconFetched_t(lua_State *L, int nParam) { return *check_UserAchievementIconFetched_t_ptr(L, nParam); }

void push_GlobalAchievementPercentagesReady_t(lua_State *L, GlobalAchievementPercentagesReady_t val) {
	GlobalAchievementPercentagesReady_t *ptr = (GlobalAchievementPercentagesReady_t*)lua_newuserdata(L, sizeof(GlobalAchievementPercentagesReady_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, GlobalAchievementPercentagesReady_tMetatable_ref);
	lua_setmetatable(L, -2);
}

GlobalAchievementPercentagesReady_t *check_GlobalAchievementPercentagesReady_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "GlobalAchievementPercentagesReady_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, GlobalAchievementPercentagesReady_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "GlobalAchievementPercentagesReady_t expected");
	return (GlobalAchievementPercentagesReady_t*)lua_touserdata(L, nParam);
}

GlobalAchievementPercentagesReady_t check_GlobalAchievementPercentagesReady_t(lua_State *L, int nParam) { return *check_GlobalAchievementPercentagesReady_t_ptr(L, nParam); }

void push_LeaderboardUGCSet_t(lua_State *L, LeaderboardUGCSet_t val) {
	LeaderboardUGCSet_t *ptr = (LeaderboardUGCSet_t*)lua_newuserdata(L, sizeof(LeaderboardUGCSet_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, LeaderboardUGCSet_tMetatable_ref);
	lua_setmetatable(L, -2);
}

LeaderboardUGCSet_t *check_LeaderboardUGCSet_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "LeaderboardUGCSet_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, LeaderboardUGCSet_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "LeaderboardUGCSet_t expected");
	return (LeaderboardUGCSet_t*)lua_touserdata(L, nParam);
}

LeaderboardUGCSet_t check_LeaderboardUGCSet_t(lua_State *L, int nParam) { return *check_LeaderboardUGCSet_t_ptr(L, nParam); }

void push_GlobalStatsReceived_t(lua_State *L, GlobalStatsReceived_t val) {
	GlobalStatsReceived_t *ptr = (GlobalStatsReceived_t*)lua_newuserdata(L, sizeof(GlobalStatsReceived_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, GlobalStatsReceived_tMetatable_ref);
	lua_setmetatable(L, -2);
}

GlobalStatsReceived_t *check_GlobalStatsReceived_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "GlobalStatsReceived_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, GlobalStatsReceived_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "GlobalStatsReceived_t expected");
	return (GlobalStatsReceived_t*)lua_touserdata(L, nParam);
}

GlobalStatsReceived_t check_GlobalStatsReceived_t(lua_State *L, int nParam) { return *check_GlobalStatsReceived_t_ptr(L, nParam); }

void push_DlcInstalled_t(lua_State *L, DlcInstalled_t val) {
	DlcInstalled_t *ptr = (DlcInstalled_t*)lua_newuserdata(L, sizeof(DlcInstalled_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, DlcInstalled_tMetatable_ref);
	lua_setmetatable(L, -2);
}

DlcInstalled_t *check_DlcInstalled_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "DlcInstalled_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, DlcInstalled_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "DlcInstalled_t expected");
	return (DlcInstalled_t*)lua_touserdata(L, nParam);
}

DlcInstalled_t check_DlcInstalled_t(lua_State *L, int nParam) { return *check_DlcInstalled_t_ptr(L, nParam); }

void push_NewUrlLaunchParameters_t(lua_State *L, NewUrlLaunchParameters_t val) {
	NewUrlLaunchParameters_t *ptr = (NewUrlLaunchParameters_t*)lua_newuserdata(L, sizeof(NewUrlLaunchParameters_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, NewUrlLaunchParameters_tMetatable_ref);
	lua_setmetatable(L, -2);
}

NewUrlLaunchParameters_t *check_NewUrlLaunchParameters_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "NewUrlLaunchParameters_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, NewUrlLaunchParameters_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "NewUrlLaunchParameters_t expected");
	return (NewUrlLaunchParameters_t*)lua_touserdata(L, nParam);
}

NewUrlLaunchParameters_t check_NewUrlLaunchParameters_t(lua_State *L, int nParam) { return *check_NewUrlLaunchParameters_t_ptr(L, nParam); }

void push_AppProofOfPurchaseKeyResponse_t(lua_State *L, AppProofOfPurchaseKeyResponse_t val) {
	AppProofOfPurchaseKeyResponse_t *ptr = (AppProofOfPurchaseKeyResponse_t*)lua_newuserdata(L, sizeof(AppProofOfPurchaseKeyResponse_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, AppProofOfPurchaseKeyResponse_tMetatable_ref);
	lua_setmetatable(L, -2);
}

AppProofOfPurchaseKeyResponse_t *check_AppProofOfPurchaseKeyResponse_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "AppProofOfPurchaseKeyResponse_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, AppProofOfPurchaseKeyResponse_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "AppProofOfPurchaseKeyResponse_t expected");
	return (AppProofOfPurchaseKeyResponse_t*)lua_touserdata(L, nParam);
}

AppProofOfPurchaseKeyResponse_t check_AppProofOfPurchaseKeyResponse_t(lua_State *L, int nParam) { return *check_AppProofOfPurchaseKeyResponse_t_ptr(L, nParam); }

void push_FileDetailsResult_t(lua_State *L, FileDetailsResult_t val) {
	FileDetailsResult_t *ptr = (FileDetailsResult_t*)lua_newuserdata(L, sizeof(FileDetailsResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, FileDetailsResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

FileDetailsResult_t *check_FileDetailsResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "FileDetailsResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, FileDetailsResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "FileDetailsResult_t expected");
	return (FileDetailsResult_t*)lua_touserdata(L, nParam);
}

FileDetailsResult_t check_FileDetailsResult_t(lua_State *L, int nParam) { return *check_FileDetailsResult_t_ptr(L, nParam); }

void push_TimedTrialStatus_t(lua_State *L, TimedTrialStatus_t val) {
	TimedTrialStatus_t *ptr = (TimedTrialStatus_t*)lua_newuserdata(L, sizeof(TimedTrialStatus_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, TimedTrialStatus_tMetatable_ref);
	lua_setmetatable(L, -2);
}

TimedTrialStatus_t *check_TimedTrialStatus_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "TimedTrialStatus_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, TimedTrialStatus_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "TimedTrialStatus_t expected");
	return (TimedTrialStatus_t*)lua_touserdata(L, nParam);
}

TimedTrialStatus_t check_TimedTrialStatus_t(lua_State *L, int nParam) { return *check_TimedTrialStatus_t_ptr(L, nParam); }

void push_P2PSessionRequest_t(lua_State *L, P2PSessionRequest_t val) {
	P2PSessionRequest_t *ptr = (P2PSessionRequest_t*)lua_newuserdata(L, sizeof(P2PSessionRequest_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, P2PSessionRequest_tMetatable_ref);
	lua_setmetatable(L, -2);
}

P2PSessionRequest_t *check_P2PSessionRequest_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "P2PSessionRequest_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, P2PSessionRequest_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "P2PSessionRequest_t expected");
	return (P2PSessionRequest_t*)lua_touserdata(L, nParam);
}

P2PSessionRequest_t check_P2PSessionRequest_t(lua_State *L, int nParam) { return *check_P2PSessionRequest_t_ptr(L, nParam); }

void push_P2PSessionConnectFail_t(lua_State *L, P2PSessionConnectFail_t val) {
	P2PSessionConnectFail_t *ptr = (P2PSessionConnectFail_t*)lua_newuserdata(L, sizeof(P2PSessionConnectFail_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, P2PSessionConnectFail_tMetatable_ref);
	lua_setmetatable(L, -2);
}

P2PSessionConnectFail_t *check_P2PSessionConnectFail_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "P2PSessionConnectFail_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, P2PSessionConnectFail_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "P2PSessionConnectFail_t expected");
	return (P2PSessionConnectFail_t*)lua_touserdata(L, nParam);
}

P2PSessionConnectFail_t check_P2PSessionConnectFail_t(lua_State *L, int nParam) { return *check_P2PSessionConnectFail_t_ptr(L, nParam); }

void push_SocketStatusCallback_t(lua_State *L, SocketStatusCallback_t val) {
	SocketStatusCallback_t *ptr = (SocketStatusCallback_t*)lua_newuserdata(L, sizeof(SocketStatusCallback_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SocketStatusCallback_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SocketStatusCallback_t *check_SocketStatusCallback_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SocketStatusCallback_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SocketStatusCallback_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SocketStatusCallback_t expected");
	return (SocketStatusCallback_t*)lua_touserdata(L, nParam);
}

SocketStatusCallback_t check_SocketStatusCallback_t(lua_State *L, int nParam) { return *check_SocketStatusCallback_t_ptr(L, nParam); }

void push_ScreenshotReady_t(lua_State *L, ScreenshotReady_t val) {
	ScreenshotReady_t *ptr = (ScreenshotReady_t*)lua_newuserdata(L, sizeof(ScreenshotReady_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, ScreenshotReady_tMetatable_ref);
	lua_setmetatable(L, -2);
}

ScreenshotReady_t *check_ScreenshotReady_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "ScreenshotReady_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, ScreenshotReady_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "ScreenshotReady_t expected");
	return (ScreenshotReady_t*)lua_touserdata(L, nParam);
}

ScreenshotReady_t check_ScreenshotReady_t(lua_State *L, int nParam) { return *check_ScreenshotReady_t_ptr(L, nParam); }

void push_ScreenshotRequested_t(lua_State *L, ScreenshotRequested_t val) {
	ScreenshotRequested_t *ptr = (ScreenshotRequested_t*)lua_newuserdata(L, sizeof(ScreenshotRequested_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, ScreenshotRequested_tMetatable_ref);
	lua_setmetatable(L, -2);
}

ScreenshotRequested_t *check_ScreenshotRequested_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "ScreenshotRequested_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, ScreenshotRequested_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "ScreenshotRequested_t expected");
	return (ScreenshotRequested_t*)lua_touserdata(L, nParam);
}

ScreenshotRequested_t check_ScreenshotRequested_t(lua_State *L, int nParam) { return *check_ScreenshotRequested_t_ptr(L, nParam); }

void push_PlaybackStatusHasChanged_t(lua_State *L, PlaybackStatusHasChanged_t val) {
	PlaybackStatusHasChanged_t *ptr = (PlaybackStatusHasChanged_t*)lua_newuserdata(L, sizeof(PlaybackStatusHasChanged_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, PlaybackStatusHasChanged_tMetatable_ref);
	lua_setmetatable(L, -2);
}

PlaybackStatusHasChanged_t *check_PlaybackStatusHasChanged_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "PlaybackStatusHasChanged_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, PlaybackStatusHasChanged_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "PlaybackStatusHasChanged_t expected");
	return (PlaybackStatusHasChanged_t*)lua_touserdata(L, nParam);
}

PlaybackStatusHasChanged_t check_PlaybackStatusHasChanged_t(lua_State *L, int nParam) { return *check_PlaybackStatusHasChanged_t_ptr(L, nParam); }

void push_VolumeHasChanged_t(lua_State *L, VolumeHasChanged_t val) {
	VolumeHasChanged_t *ptr = (VolumeHasChanged_t*)lua_newuserdata(L, sizeof(VolumeHasChanged_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, VolumeHasChanged_tMetatable_ref);
	lua_setmetatable(L, -2);
}

VolumeHasChanged_t *check_VolumeHasChanged_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "VolumeHasChanged_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, VolumeHasChanged_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "VolumeHasChanged_t expected");
	return (VolumeHasChanged_t*)lua_touserdata(L, nParam);
}

VolumeHasChanged_t check_VolumeHasChanged_t(lua_State *L, int nParam) { return *check_VolumeHasChanged_t_ptr(L, nParam); }

void push_HTTPRequestCompleted_t(lua_State *L, HTTPRequestCompleted_t val) {
	HTTPRequestCompleted_t *ptr = (HTTPRequestCompleted_t*)lua_newuserdata(L, sizeof(HTTPRequestCompleted_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTTPRequestCompleted_tMetatable_ref);
	lua_setmetatable(L, -2);
}

HTTPRequestCompleted_t *check_HTTPRequestCompleted_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "HTTPRequestCompleted_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTTPRequestCompleted_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "HTTPRequestCompleted_t expected");
	return (HTTPRequestCompleted_t*)lua_touserdata(L, nParam);
}

HTTPRequestCompleted_t check_HTTPRequestCompleted_t(lua_State *L, int nParam) { return *check_HTTPRequestCompleted_t_ptr(L, nParam); }

void push_HTTPRequestHeadersReceived_t(lua_State *L, HTTPRequestHeadersReceived_t val) {
	HTTPRequestHeadersReceived_t *ptr = (HTTPRequestHeadersReceived_t*)lua_newuserdata(L, sizeof(HTTPRequestHeadersReceived_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTTPRequestHeadersReceived_tMetatable_ref);
	lua_setmetatable(L, -2);
}

HTTPRequestHeadersReceived_t *check_HTTPRequestHeadersReceived_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "HTTPRequestHeadersReceived_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTTPRequestHeadersReceived_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "HTTPRequestHeadersReceived_t expected");
	return (HTTPRequestHeadersReceived_t*)lua_touserdata(L, nParam);
}

HTTPRequestHeadersReceived_t check_HTTPRequestHeadersReceived_t(lua_State *L, int nParam) { return *check_HTTPRequestHeadersReceived_t_ptr(L, nParam); }

void push_HTTPRequestDataReceived_t(lua_State *L, HTTPRequestDataReceived_t val) {
	HTTPRequestDataReceived_t *ptr = (HTTPRequestDataReceived_t*)lua_newuserdata(L, sizeof(HTTPRequestDataReceived_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTTPRequestDataReceived_tMetatable_ref);
	lua_setmetatable(L, -2);
}

HTTPRequestDataReceived_t *check_HTTPRequestDataReceived_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "HTTPRequestDataReceived_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTTPRequestDataReceived_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "HTTPRequestDataReceived_t expected");
	return (HTTPRequestDataReceived_t*)lua_touserdata(L, nParam);
}

HTTPRequestDataReceived_t check_HTTPRequestDataReceived_t(lua_State *L, int nParam) { return *check_HTTPRequestDataReceived_t_ptr(L, nParam); }

void push_SteamInputDeviceConnected_t(lua_State *L, SteamInputDeviceConnected_t val) {
	SteamInputDeviceConnected_t *ptr = (SteamInputDeviceConnected_t*)lua_newuserdata(L, sizeof(SteamInputDeviceConnected_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInputDeviceConnected_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamInputDeviceConnected_t *check_SteamInputDeviceConnected_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamInputDeviceConnected_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInputDeviceConnected_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamInputDeviceConnected_t expected");
	return (SteamInputDeviceConnected_t*)lua_touserdata(L, nParam);
}

SteamInputDeviceConnected_t check_SteamInputDeviceConnected_t(lua_State *L, int nParam) { return *check_SteamInputDeviceConnected_t_ptr(L, nParam); }

void push_SteamInputDeviceDisconnected_t(lua_State *L, SteamInputDeviceDisconnected_t val) {
	SteamInputDeviceDisconnected_t *ptr = (SteamInputDeviceDisconnected_t*)lua_newuserdata(L, sizeof(SteamInputDeviceDisconnected_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInputDeviceDisconnected_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamInputDeviceDisconnected_t *check_SteamInputDeviceDisconnected_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamInputDeviceDisconnected_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInputDeviceDisconnected_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamInputDeviceDisconnected_t expected");
	return (SteamInputDeviceDisconnected_t*)lua_touserdata(L, nParam);
}

SteamInputDeviceDisconnected_t check_SteamInputDeviceDisconnected_t(lua_State *L, int nParam) { return *check_SteamInputDeviceDisconnected_t_ptr(L, nParam); }

void push_SteamInputConfigurationLoaded_t(lua_State *L, SteamInputConfigurationLoaded_t val) {
	SteamInputConfigurationLoaded_t *ptr = (SteamInputConfigurationLoaded_t*)lua_newuserdata(L, sizeof(SteamInputConfigurationLoaded_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInputConfigurationLoaded_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamInputConfigurationLoaded_t *check_SteamInputConfigurationLoaded_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamInputConfigurationLoaded_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInputConfigurationLoaded_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamInputConfigurationLoaded_t expected");
	return (SteamInputConfigurationLoaded_t*)lua_touserdata(L, nParam);
}

SteamInputConfigurationLoaded_t check_SteamInputConfigurationLoaded_t(lua_State *L, int nParam) { return *check_SteamInputConfigurationLoaded_t_ptr(L, nParam); }

void push_SteamInputGamepadSlotChange_t(lua_State *L, SteamInputGamepadSlotChange_t val) {
	SteamInputGamepadSlotChange_t *ptr = (SteamInputGamepadSlotChange_t*)lua_newuserdata(L, sizeof(SteamInputGamepadSlotChange_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInputGamepadSlotChange_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamInputGamepadSlotChange_t *check_SteamInputGamepadSlotChange_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamInputGamepadSlotChange_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInputGamepadSlotChange_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamInputGamepadSlotChange_t expected");
	return (SteamInputGamepadSlotChange_t*)lua_touserdata(L, nParam);
}

SteamInputGamepadSlotChange_t check_SteamInputGamepadSlotChange_t(lua_State *L, int nParam) { return *check_SteamInputGamepadSlotChange_t_ptr(L, nParam); }

void push_SteamUGCQueryCompleted_t(lua_State *L, SteamUGCQueryCompleted_t val) {
	SteamUGCQueryCompleted_t *ptr = (SteamUGCQueryCompleted_t*)lua_newuserdata(L, sizeof(SteamUGCQueryCompleted_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamUGCQueryCompleted_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamUGCQueryCompleted_t *check_SteamUGCQueryCompleted_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamUGCQueryCompleted_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamUGCQueryCompleted_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamUGCQueryCompleted_t expected");
	return (SteamUGCQueryCompleted_t*)lua_touserdata(L, nParam);
}

SteamUGCQueryCompleted_t check_SteamUGCQueryCompleted_t(lua_State *L, int nParam) { return *check_SteamUGCQueryCompleted_t_ptr(L, nParam); }

void push_SteamUGCRequestUGCDetailsResult_t(lua_State *L, SteamUGCRequestUGCDetailsResult_t val) {
	SteamUGCRequestUGCDetailsResult_t *ptr = (SteamUGCRequestUGCDetailsResult_t*)lua_newuserdata(L, sizeof(SteamUGCRequestUGCDetailsResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamUGCRequestUGCDetailsResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamUGCRequestUGCDetailsResult_t *check_SteamUGCRequestUGCDetailsResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamUGCRequestUGCDetailsResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamUGCRequestUGCDetailsResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamUGCRequestUGCDetailsResult_t expected");
	return (SteamUGCRequestUGCDetailsResult_t*)lua_touserdata(L, nParam);
}

SteamUGCRequestUGCDetailsResult_t check_SteamUGCRequestUGCDetailsResult_t(lua_State *L, int nParam) { return *check_SteamUGCRequestUGCDetailsResult_t_ptr(L, nParam); }

void push_CreateItemResult_t(lua_State *L, CreateItemResult_t val) {
	CreateItemResult_t *ptr = (CreateItemResult_t*)lua_newuserdata(L, sizeof(CreateItemResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, CreateItemResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

CreateItemResult_t *check_CreateItemResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "CreateItemResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, CreateItemResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "CreateItemResult_t expected");
	return (CreateItemResult_t*)lua_touserdata(L, nParam);
}

CreateItemResult_t check_CreateItemResult_t(lua_State *L, int nParam) { return *check_CreateItemResult_t_ptr(L, nParam); }

void push_SubmitItemUpdateResult_t(lua_State *L, SubmitItemUpdateResult_t val) {
	SubmitItemUpdateResult_t *ptr = (SubmitItemUpdateResult_t*)lua_newuserdata(L, sizeof(SubmitItemUpdateResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SubmitItemUpdateResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SubmitItemUpdateResult_t *check_SubmitItemUpdateResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SubmitItemUpdateResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SubmitItemUpdateResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SubmitItemUpdateResult_t expected");
	return (SubmitItemUpdateResult_t*)lua_touserdata(L, nParam);
}

SubmitItemUpdateResult_t check_SubmitItemUpdateResult_t(lua_State *L, int nParam) { return *check_SubmitItemUpdateResult_t_ptr(L, nParam); }

void push_ItemInstalled_t(lua_State *L, ItemInstalled_t val) {
	ItemInstalled_t *ptr = (ItemInstalled_t*)lua_newuserdata(L, sizeof(ItemInstalled_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, ItemInstalled_tMetatable_ref);
	lua_setmetatable(L, -2);
}

ItemInstalled_t *check_ItemInstalled_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "ItemInstalled_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, ItemInstalled_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "ItemInstalled_t expected");
	return (ItemInstalled_t*)lua_touserdata(L, nParam);
}

ItemInstalled_t check_ItemInstalled_t(lua_State *L, int nParam) { return *check_ItemInstalled_t_ptr(L, nParam); }

void push_DownloadItemResult_t(lua_State *L, DownloadItemResult_t val) {
	DownloadItemResult_t *ptr = (DownloadItemResult_t*)lua_newuserdata(L, sizeof(DownloadItemResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, DownloadItemResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

DownloadItemResult_t *check_DownloadItemResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "DownloadItemResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, DownloadItemResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "DownloadItemResult_t expected");
	return (DownloadItemResult_t*)lua_touserdata(L, nParam);
}

DownloadItemResult_t check_DownloadItemResult_t(lua_State *L, int nParam) { return *check_DownloadItemResult_t_ptr(L, nParam); }

void push_UserFavoriteItemsListChanged_t(lua_State *L, UserFavoriteItemsListChanged_t val) {
	UserFavoriteItemsListChanged_t *ptr = (UserFavoriteItemsListChanged_t*)lua_newuserdata(L, sizeof(UserFavoriteItemsListChanged_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, UserFavoriteItemsListChanged_tMetatable_ref);
	lua_setmetatable(L, -2);
}

UserFavoriteItemsListChanged_t *check_UserFavoriteItemsListChanged_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "UserFavoriteItemsListChanged_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, UserFavoriteItemsListChanged_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "UserFavoriteItemsListChanged_t expected");
	return (UserFavoriteItemsListChanged_t*)lua_touserdata(L, nParam);
}

UserFavoriteItemsListChanged_t check_UserFavoriteItemsListChanged_t(lua_State *L, int nParam) { return *check_UserFavoriteItemsListChanged_t_ptr(L, nParam); }

void push_SetUserItemVoteResult_t(lua_State *L, SetUserItemVoteResult_t val) {
	SetUserItemVoteResult_t *ptr = (SetUserItemVoteResult_t*)lua_newuserdata(L, sizeof(SetUserItemVoteResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SetUserItemVoteResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SetUserItemVoteResult_t *check_SetUserItemVoteResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SetUserItemVoteResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SetUserItemVoteResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SetUserItemVoteResult_t expected");
	return (SetUserItemVoteResult_t*)lua_touserdata(L, nParam);
}

SetUserItemVoteResult_t check_SetUserItemVoteResult_t(lua_State *L, int nParam) { return *check_SetUserItemVoteResult_t_ptr(L, nParam); }

void push_GetUserItemVoteResult_t(lua_State *L, GetUserItemVoteResult_t val) {
	GetUserItemVoteResult_t *ptr = (GetUserItemVoteResult_t*)lua_newuserdata(L, sizeof(GetUserItemVoteResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, GetUserItemVoteResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

GetUserItemVoteResult_t *check_GetUserItemVoteResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "GetUserItemVoteResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, GetUserItemVoteResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "GetUserItemVoteResult_t expected");
	return (GetUserItemVoteResult_t*)lua_touserdata(L, nParam);
}

GetUserItemVoteResult_t check_GetUserItemVoteResult_t(lua_State *L, int nParam) { return *check_GetUserItemVoteResult_t_ptr(L, nParam); }

void push_StartPlaytimeTrackingResult_t(lua_State *L, StartPlaytimeTrackingResult_t val) {
	StartPlaytimeTrackingResult_t *ptr = (StartPlaytimeTrackingResult_t*)lua_newuserdata(L, sizeof(StartPlaytimeTrackingResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, StartPlaytimeTrackingResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

StartPlaytimeTrackingResult_t *check_StartPlaytimeTrackingResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "StartPlaytimeTrackingResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, StartPlaytimeTrackingResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "StartPlaytimeTrackingResult_t expected");
	return (StartPlaytimeTrackingResult_t*)lua_touserdata(L, nParam);
}

StartPlaytimeTrackingResult_t check_StartPlaytimeTrackingResult_t(lua_State *L, int nParam) { return *check_StartPlaytimeTrackingResult_t_ptr(L, nParam); }

void push_StopPlaytimeTrackingResult_t(lua_State *L, StopPlaytimeTrackingResult_t val) {
	StopPlaytimeTrackingResult_t *ptr = (StopPlaytimeTrackingResult_t*)lua_newuserdata(L, sizeof(StopPlaytimeTrackingResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, StopPlaytimeTrackingResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

StopPlaytimeTrackingResult_t *check_StopPlaytimeTrackingResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "StopPlaytimeTrackingResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, StopPlaytimeTrackingResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "StopPlaytimeTrackingResult_t expected");
	return (StopPlaytimeTrackingResult_t*)lua_touserdata(L, nParam);
}

StopPlaytimeTrackingResult_t check_StopPlaytimeTrackingResult_t(lua_State *L, int nParam) { return *check_StopPlaytimeTrackingResult_t_ptr(L, nParam); }

void push_AddUGCDependencyResult_t(lua_State *L, AddUGCDependencyResult_t val) {
	AddUGCDependencyResult_t *ptr = (AddUGCDependencyResult_t*)lua_newuserdata(L, sizeof(AddUGCDependencyResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, AddUGCDependencyResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

AddUGCDependencyResult_t *check_AddUGCDependencyResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "AddUGCDependencyResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, AddUGCDependencyResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "AddUGCDependencyResult_t expected");
	return (AddUGCDependencyResult_t*)lua_touserdata(L, nParam);
}

AddUGCDependencyResult_t check_AddUGCDependencyResult_t(lua_State *L, int nParam) { return *check_AddUGCDependencyResult_t_ptr(L, nParam); }

void push_RemoveUGCDependencyResult_t(lua_State *L, RemoveUGCDependencyResult_t val) {
	RemoveUGCDependencyResult_t *ptr = (RemoveUGCDependencyResult_t*)lua_newuserdata(L, sizeof(RemoveUGCDependencyResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoveUGCDependencyResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemoveUGCDependencyResult_t *check_RemoveUGCDependencyResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemoveUGCDependencyResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoveUGCDependencyResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemoveUGCDependencyResult_t expected");
	return (RemoveUGCDependencyResult_t*)lua_touserdata(L, nParam);
}

RemoveUGCDependencyResult_t check_RemoveUGCDependencyResult_t(lua_State *L, int nParam) { return *check_RemoveUGCDependencyResult_t_ptr(L, nParam); }

void push_AddAppDependencyResult_t(lua_State *L, AddAppDependencyResult_t val) {
	AddAppDependencyResult_t *ptr = (AddAppDependencyResult_t*)lua_newuserdata(L, sizeof(AddAppDependencyResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, AddAppDependencyResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

AddAppDependencyResult_t *check_AddAppDependencyResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "AddAppDependencyResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, AddAppDependencyResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "AddAppDependencyResult_t expected");
	return (AddAppDependencyResult_t*)lua_touserdata(L, nParam);
}

AddAppDependencyResult_t check_AddAppDependencyResult_t(lua_State *L, int nParam) { return *check_AddAppDependencyResult_t_ptr(L, nParam); }

void push_RemoveAppDependencyResult_t(lua_State *L, RemoveAppDependencyResult_t val) {
	RemoveAppDependencyResult_t *ptr = (RemoveAppDependencyResult_t*)lua_newuserdata(L, sizeof(RemoveAppDependencyResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoveAppDependencyResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

RemoveAppDependencyResult_t *check_RemoveAppDependencyResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "RemoveAppDependencyResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, RemoveAppDependencyResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "RemoveAppDependencyResult_t expected");
	return (RemoveAppDependencyResult_t*)lua_touserdata(L, nParam);
}

RemoveAppDependencyResult_t check_RemoveAppDependencyResult_t(lua_State *L, int nParam) { return *check_RemoveAppDependencyResult_t_ptr(L, nParam); }

void push_GetAppDependenciesResult_t(lua_State *L, GetAppDependenciesResult_t val) {
	GetAppDependenciesResult_t *ptr = (GetAppDependenciesResult_t*)lua_newuserdata(L, sizeof(GetAppDependenciesResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, GetAppDependenciesResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

GetAppDependenciesResult_t *check_GetAppDependenciesResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "GetAppDependenciesResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, GetAppDependenciesResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "GetAppDependenciesResult_t expected");
	return (GetAppDependenciesResult_t*)lua_touserdata(L, nParam);
}

GetAppDependenciesResult_t check_GetAppDependenciesResult_t(lua_State *L, int nParam) { return *check_GetAppDependenciesResult_t_ptr(L, nParam); }

void push_DeleteItemResult_t(lua_State *L, DeleteItemResult_t val) {
	DeleteItemResult_t *ptr = (DeleteItemResult_t*)lua_newuserdata(L, sizeof(DeleteItemResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, DeleteItemResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

DeleteItemResult_t *check_DeleteItemResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "DeleteItemResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, DeleteItemResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "DeleteItemResult_t expected");
	return (DeleteItemResult_t*)lua_touserdata(L, nParam);
}

DeleteItemResult_t check_DeleteItemResult_t(lua_State *L, int nParam) { return *check_DeleteItemResult_t_ptr(L, nParam); }

void push_UserSubscribedItemsListChanged_t(lua_State *L, UserSubscribedItemsListChanged_t val) {
	UserSubscribedItemsListChanged_t *ptr = (UserSubscribedItemsListChanged_t*)lua_newuserdata(L, sizeof(UserSubscribedItemsListChanged_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, UserSubscribedItemsListChanged_tMetatable_ref);
	lua_setmetatable(L, -2);
}

UserSubscribedItemsListChanged_t *check_UserSubscribedItemsListChanged_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "UserSubscribedItemsListChanged_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, UserSubscribedItemsListChanged_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "UserSubscribedItemsListChanged_t expected");
	return (UserSubscribedItemsListChanged_t*)lua_touserdata(L, nParam);
}

UserSubscribedItemsListChanged_t check_UserSubscribedItemsListChanged_t(lua_State *L, int nParam) { return *check_UserSubscribedItemsListChanged_t_ptr(L, nParam); }

void push_WorkshopEULAStatus_t(lua_State *L, WorkshopEULAStatus_t val) {
	WorkshopEULAStatus_t *ptr = (WorkshopEULAStatus_t*)lua_newuserdata(L, sizeof(WorkshopEULAStatus_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, WorkshopEULAStatus_tMetatable_ref);
	lua_setmetatable(L, -2);
}

WorkshopEULAStatus_t *check_WorkshopEULAStatus_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "WorkshopEULAStatus_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, WorkshopEULAStatus_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "WorkshopEULAStatus_t expected");
	return (WorkshopEULAStatus_t*)lua_touserdata(L, nParam);
}

WorkshopEULAStatus_t check_WorkshopEULAStatus_t(lua_State *L, int nParam) { return *check_WorkshopEULAStatus_t_ptr(L, nParam); }

void push_HTML_BrowserReady_t(lua_State *L, HTML_BrowserReady_t val) {
	HTML_BrowserReady_t *ptr = (HTML_BrowserReady_t*)lua_newuserdata(L, sizeof(HTML_BrowserReady_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_BrowserReady_tMetatable_ref);
	lua_setmetatable(L, -2);
}

HTML_BrowserReady_t *check_HTML_BrowserReady_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "HTML_BrowserReady_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_BrowserReady_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "HTML_BrowserReady_t expected");
	return (HTML_BrowserReady_t*)lua_touserdata(L, nParam);
}

HTML_BrowserReady_t check_HTML_BrowserReady_t(lua_State *L, int nParam) { return *check_HTML_BrowserReady_t_ptr(L, nParam); }

void push_HTML_NeedsPaint_t(lua_State *L, HTML_NeedsPaint_t val) {
	HTML_NeedsPaint_t *ptr = (HTML_NeedsPaint_t*)lua_newuserdata(L, sizeof(HTML_NeedsPaint_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_NeedsPaint_tMetatable_ref);
	lua_setmetatable(L, -2);
}

HTML_NeedsPaint_t *check_HTML_NeedsPaint_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "HTML_NeedsPaint_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_NeedsPaint_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "HTML_NeedsPaint_t expected");
	return (HTML_NeedsPaint_t*)lua_touserdata(L, nParam);
}

HTML_NeedsPaint_t check_HTML_NeedsPaint_t(lua_State *L, int nParam) { return *check_HTML_NeedsPaint_t_ptr(L, nParam); }

void push_HTML_StartRequest_t(lua_State *L, HTML_StartRequest_t val) {
	HTML_StartRequest_t *ptr = (HTML_StartRequest_t*)lua_newuserdata(L, sizeof(HTML_StartRequest_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_StartRequest_tMetatable_ref);
	lua_setmetatable(L, -2);
}

HTML_StartRequest_t *check_HTML_StartRequest_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "HTML_StartRequest_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_StartRequest_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "HTML_StartRequest_t expected");
	return (HTML_StartRequest_t*)lua_touserdata(L, nParam);
}

HTML_StartRequest_t check_HTML_StartRequest_t(lua_State *L, int nParam) { return *check_HTML_StartRequest_t_ptr(L, nParam); }

void push_HTML_CloseBrowser_t(lua_State *L, HTML_CloseBrowser_t val) {
	HTML_CloseBrowser_t *ptr = (HTML_CloseBrowser_t*)lua_newuserdata(L, sizeof(HTML_CloseBrowser_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_CloseBrowser_tMetatable_ref);
	lua_setmetatable(L, -2);
}

HTML_CloseBrowser_t *check_HTML_CloseBrowser_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "HTML_CloseBrowser_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_CloseBrowser_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "HTML_CloseBrowser_t expected");
	return (HTML_CloseBrowser_t*)lua_touserdata(L, nParam);
}

HTML_CloseBrowser_t check_HTML_CloseBrowser_t(lua_State *L, int nParam) { return *check_HTML_CloseBrowser_t_ptr(L, nParam); }

void push_HTML_URLChanged_t(lua_State *L, HTML_URLChanged_t val) {
	HTML_URLChanged_t *ptr = (HTML_URLChanged_t*)lua_newuserdata(L, sizeof(HTML_URLChanged_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_URLChanged_tMetatable_ref);
	lua_setmetatable(L, -2);
}

HTML_URLChanged_t *check_HTML_URLChanged_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "HTML_URLChanged_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_URLChanged_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "HTML_URLChanged_t expected");
	return (HTML_URLChanged_t*)lua_touserdata(L, nParam);
}

HTML_URLChanged_t check_HTML_URLChanged_t(lua_State *L, int nParam) { return *check_HTML_URLChanged_t_ptr(L, nParam); }

void push_HTML_FinishedRequest_t(lua_State *L, HTML_FinishedRequest_t val) {
	HTML_FinishedRequest_t *ptr = (HTML_FinishedRequest_t*)lua_newuserdata(L, sizeof(HTML_FinishedRequest_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_FinishedRequest_tMetatable_ref);
	lua_setmetatable(L, -2);
}

HTML_FinishedRequest_t *check_HTML_FinishedRequest_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "HTML_FinishedRequest_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_FinishedRequest_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "HTML_FinishedRequest_t expected");
	return (HTML_FinishedRequest_t*)lua_touserdata(L, nParam);
}

HTML_FinishedRequest_t check_HTML_FinishedRequest_t(lua_State *L, int nParam) { return *check_HTML_FinishedRequest_t_ptr(L, nParam); }

void push_HTML_OpenLinkInNewTab_t(lua_State *L, HTML_OpenLinkInNewTab_t val) {
	HTML_OpenLinkInNewTab_t *ptr = (HTML_OpenLinkInNewTab_t*)lua_newuserdata(L, sizeof(HTML_OpenLinkInNewTab_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_OpenLinkInNewTab_tMetatable_ref);
	lua_setmetatable(L, -2);
}

HTML_OpenLinkInNewTab_t *check_HTML_OpenLinkInNewTab_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "HTML_OpenLinkInNewTab_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_OpenLinkInNewTab_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "HTML_OpenLinkInNewTab_t expected");
	return (HTML_OpenLinkInNewTab_t*)lua_touserdata(L, nParam);
}

HTML_OpenLinkInNewTab_t check_HTML_OpenLinkInNewTab_t(lua_State *L, int nParam) { return *check_HTML_OpenLinkInNewTab_t_ptr(L, nParam); }

void push_HTML_ChangedTitle_t(lua_State *L, HTML_ChangedTitle_t val) {
	HTML_ChangedTitle_t *ptr = (HTML_ChangedTitle_t*)lua_newuserdata(L, sizeof(HTML_ChangedTitle_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_ChangedTitle_tMetatable_ref);
	lua_setmetatable(L, -2);
}

HTML_ChangedTitle_t *check_HTML_ChangedTitle_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "HTML_ChangedTitle_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_ChangedTitle_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "HTML_ChangedTitle_t expected");
	return (HTML_ChangedTitle_t*)lua_touserdata(L, nParam);
}

HTML_ChangedTitle_t check_HTML_ChangedTitle_t(lua_State *L, int nParam) { return *check_HTML_ChangedTitle_t_ptr(L, nParam); }

void push_HTML_SearchResults_t(lua_State *L, HTML_SearchResults_t val) {
	HTML_SearchResults_t *ptr = (HTML_SearchResults_t*)lua_newuserdata(L, sizeof(HTML_SearchResults_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_SearchResults_tMetatable_ref);
	lua_setmetatable(L, -2);
}

HTML_SearchResults_t *check_HTML_SearchResults_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "HTML_SearchResults_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_SearchResults_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "HTML_SearchResults_t expected");
	return (HTML_SearchResults_t*)lua_touserdata(L, nParam);
}

HTML_SearchResults_t check_HTML_SearchResults_t(lua_State *L, int nParam) { return *check_HTML_SearchResults_t_ptr(L, nParam); }

void push_HTML_CanGoBackAndForward_t(lua_State *L, HTML_CanGoBackAndForward_t val) {
	HTML_CanGoBackAndForward_t *ptr = (HTML_CanGoBackAndForward_t*)lua_newuserdata(L, sizeof(HTML_CanGoBackAndForward_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_CanGoBackAndForward_tMetatable_ref);
	lua_setmetatable(L, -2);
}

HTML_CanGoBackAndForward_t *check_HTML_CanGoBackAndForward_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "HTML_CanGoBackAndForward_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_CanGoBackAndForward_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "HTML_CanGoBackAndForward_t expected");
	return (HTML_CanGoBackAndForward_t*)lua_touserdata(L, nParam);
}

HTML_CanGoBackAndForward_t check_HTML_CanGoBackAndForward_t(lua_State *L, int nParam) { return *check_HTML_CanGoBackAndForward_t_ptr(L, nParam); }

void push_HTML_HorizontalScroll_t(lua_State *L, HTML_HorizontalScroll_t val) {
	HTML_HorizontalScroll_t *ptr = (HTML_HorizontalScroll_t*)lua_newuserdata(L, sizeof(HTML_HorizontalScroll_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_HorizontalScroll_tMetatable_ref);
	lua_setmetatable(L, -2);
}

HTML_HorizontalScroll_t *check_HTML_HorizontalScroll_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "HTML_HorizontalScroll_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_HorizontalScroll_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "HTML_HorizontalScroll_t expected");
	return (HTML_HorizontalScroll_t*)lua_touserdata(L, nParam);
}

HTML_HorizontalScroll_t check_HTML_HorizontalScroll_t(lua_State *L, int nParam) { return *check_HTML_HorizontalScroll_t_ptr(L, nParam); }

void push_HTML_VerticalScroll_t(lua_State *L, HTML_VerticalScroll_t val) {
	HTML_VerticalScroll_t *ptr = (HTML_VerticalScroll_t*)lua_newuserdata(L, sizeof(HTML_VerticalScroll_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_VerticalScroll_tMetatable_ref);
	lua_setmetatable(L, -2);
}

HTML_VerticalScroll_t *check_HTML_VerticalScroll_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "HTML_VerticalScroll_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_VerticalScroll_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "HTML_VerticalScroll_t expected");
	return (HTML_VerticalScroll_t*)lua_touserdata(L, nParam);
}

HTML_VerticalScroll_t check_HTML_VerticalScroll_t(lua_State *L, int nParam) { return *check_HTML_VerticalScroll_t_ptr(L, nParam); }

void push_HTML_LinkAtPosition_t(lua_State *L, HTML_LinkAtPosition_t val) {
	HTML_LinkAtPosition_t *ptr = (HTML_LinkAtPosition_t*)lua_newuserdata(L, sizeof(HTML_LinkAtPosition_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_LinkAtPosition_tMetatable_ref);
	lua_setmetatable(L, -2);
}

HTML_LinkAtPosition_t *check_HTML_LinkAtPosition_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "HTML_LinkAtPosition_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_LinkAtPosition_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "HTML_LinkAtPosition_t expected");
	return (HTML_LinkAtPosition_t*)lua_touserdata(L, nParam);
}

HTML_LinkAtPosition_t check_HTML_LinkAtPosition_t(lua_State *L, int nParam) { return *check_HTML_LinkAtPosition_t_ptr(L, nParam); }

void push_HTML_JSAlert_t(lua_State *L, HTML_JSAlert_t val) {
	HTML_JSAlert_t *ptr = (HTML_JSAlert_t*)lua_newuserdata(L, sizeof(HTML_JSAlert_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_JSAlert_tMetatable_ref);
	lua_setmetatable(L, -2);
}

HTML_JSAlert_t *check_HTML_JSAlert_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "HTML_JSAlert_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_JSAlert_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "HTML_JSAlert_t expected");
	return (HTML_JSAlert_t*)lua_touserdata(L, nParam);
}

HTML_JSAlert_t check_HTML_JSAlert_t(lua_State *L, int nParam) { return *check_HTML_JSAlert_t_ptr(L, nParam); }

void push_HTML_JSConfirm_t(lua_State *L, HTML_JSConfirm_t val) {
	HTML_JSConfirm_t *ptr = (HTML_JSConfirm_t*)lua_newuserdata(L, sizeof(HTML_JSConfirm_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_JSConfirm_tMetatable_ref);
	lua_setmetatable(L, -2);
}

HTML_JSConfirm_t *check_HTML_JSConfirm_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "HTML_JSConfirm_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_JSConfirm_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "HTML_JSConfirm_t expected");
	return (HTML_JSConfirm_t*)lua_touserdata(L, nParam);
}

HTML_JSConfirm_t check_HTML_JSConfirm_t(lua_State *L, int nParam) { return *check_HTML_JSConfirm_t_ptr(L, nParam); }

void push_HTML_FileOpenDialog_t(lua_State *L, HTML_FileOpenDialog_t val) {
	HTML_FileOpenDialog_t *ptr = (HTML_FileOpenDialog_t*)lua_newuserdata(L, sizeof(HTML_FileOpenDialog_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_FileOpenDialog_tMetatable_ref);
	lua_setmetatable(L, -2);
}

HTML_FileOpenDialog_t *check_HTML_FileOpenDialog_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "HTML_FileOpenDialog_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_FileOpenDialog_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "HTML_FileOpenDialog_t expected");
	return (HTML_FileOpenDialog_t*)lua_touserdata(L, nParam);
}

HTML_FileOpenDialog_t check_HTML_FileOpenDialog_t(lua_State *L, int nParam) { return *check_HTML_FileOpenDialog_t_ptr(L, nParam); }

void push_HTML_NewWindow_t(lua_State *L, HTML_NewWindow_t val) {
	HTML_NewWindow_t *ptr = (HTML_NewWindow_t*)lua_newuserdata(L, sizeof(HTML_NewWindow_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_NewWindow_tMetatable_ref);
	lua_setmetatable(L, -2);
}

HTML_NewWindow_t *check_HTML_NewWindow_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "HTML_NewWindow_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_NewWindow_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "HTML_NewWindow_t expected");
	return (HTML_NewWindow_t*)lua_touserdata(L, nParam);
}

HTML_NewWindow_t check_HTML_NewWindow_t(lua_State *L, int nParam) { return *check_HTML_NewWindow_t_ptr(L, nParam); }

void push_HTML_SetCursor_t(lua_State *L, HTML_SetCursor_t val) {
	HTML_SetCursor_t *ptr = (HTML_SetCursor_t*)lua_newuserdata(L, sizeof(HTML_SetCursor_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_SetCursor_tMetatable_ref);
	lua_setmetatable(L, -2);
}

HTML_SetCursor_t *check_HTML_SetCursor_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "HTML_SetCursor_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_SetCursor_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "HTML_SetCursor_t expected");
	return (HTML_SetCursor_t*)lua_touserdata(L, nParam);
}

HTML_SetCursor_t check_HTML_SetCursor_t(lua_State *L, int nParam) { return *check_HTML_SetCursor_t_ptr(L, nParam); }

void push_HTML_StatusText_t(lua_State *L, HTML_StatusText_t val) {
	HTML_StatusText_t *ptr = (HTML_StatusText_t*)lua_newuserdata(L, sizeof(HTML_StatusText_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_StatusText_tMetatable_ref);
	lua_setmetatable(L, -2);
}

HTML_StatusText_t *check_HTML_StatusText_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "HTML_StatusText_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_StatusText_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "HTML_StatusText_t expected");
	return (HTML_StatusText_t*)lua_touserdata(L, nParam);
}

HTML_StatusText_t check_HTML_StatusText_t(lua_State *L, int nParam) { return *check_HTML_StatusText_t_ptr(L, nParam); }

void push_HTML_ShowToolTip_t(lua_State *L, HTML_ShowToolTip_t val) {
	HTML_ShowToolTip_t *ptr = (HTML_ShowToolTip_t*)lua_newuserdata(L, sizeof(HTML_ShowToolTip_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_ShowToolTip_tMetatable_ref);
	lua_setmetatable(L, -2);
}

HTML_ShowToolTip_t *check_HTML_ShowToolTip_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "HTML_ShowToolTip_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_ShowToolTip_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "HTML_ShowToolTip_t expected");
	return (HTML_ShowToolTip_t*)lua_touserdata(L, nParam);
}

HTML_ShowToolTip_t check_HTML_ShowToolTip_t(lua_State *L, int nParam) { return *check_HTML_ShowToolTip_t_ptr(L, nParam); }

void push_HTML_UpdateToolTip_t(lua_State *L, HTML_UpdateToolTip_t val) {
	HTML_UpdateToolTip_t *ptr = (HTML_UpdateToolTip_t*)lua_newuserdata(L, sizeof(HTML_UpdateToolTip_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_UpdateToolTip_tMetatable_ref);
	lua_setmetatable(L, -2);
}

HTML_UpdateToolTip_t *check_HTML_UpdateToolTip_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "HTML_UpdateToolTip_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_UpdateToolTip_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "HTML_UpdateToolTip_t expected");
	return (HTML_UpdateToolTip_t*)lua_touserdata(L, nParam);
}

HTML_UpdateToolTip_t check_HTML_UpdateToolTip_t(lua_State *L, int nParam) { return *check_HTML_UpdateToolTip_t_ptr(L, nParam); }

void push_HTML_HideToolTip_t(lua_State *L, HTML_HideToolTip_t val) {
	HTML_HideToolTip_t *ptr = (HTML_HideToolTip_t*)lua_newuserdata(L, sizeof(HTML_HideToolTip_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_HideToolTip_tMetatable_ref);
	lua_setmetatable(L, -2);
}

HTML_HideToolTip_t *check_HTML_HideToolTip_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "HTML_HideToolTip_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_HideToolTip_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "HTML_HideToolTip_t expected");
	return (HTML_HideToolTip_t*)lua_touserdata(L, nParam);
}

HTML_HideToolTip_t check_HTML_HideToolTip_t(lua_State *L, int nParam) { return *check_HTML_HideToolTip_t_ptr(L, nParam); }

void push_HTML_BrowserRestarted_t(lua_State *L, HTML_BrowserRestarted_t val) {
	HTML_BrowserRestarted_t *ptr = (HTML_BrowserRestarted_t*)lua_newuserdata(L, sizeof(HTML_BrowserRestarted_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_BrowserRestarted_tMetatable_ref);
	lua_setmetatable(L, -2);
}

HTML_BrowserRestarted_t *check_HTML_BrowserRestarted_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "HTML_BrowserRestarted_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, HTML_BrowserRestarted_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "HTML_BrowserRestarted_t expected");
	return (HTML_BrowserRestarted_t*)lua_touserdata(L, nParam);
}

HTML_BrowserRestarted_t check_HTML_BrowserRestarted_t(lua_State *L, int nParam) { return *check_HTML_BrowserRestarted_t_ptr(L, nParam); }

void push_SteamInventoryResultReady_t(lua_State *L, SteamInventoryResultReady_t val) {
	SteamInventoryResultReady_t *ptr = (SteamInventoryResultReady_t*)lua_newuserdata(L, sizeof(SteamInventoryResultReady_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInventoryResultReady_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamInventoryResultReady_t *check_SteamInventoryResultReady_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamInventoryResultReady_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInventoryResultReady_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamInventoryResultReady_t expected");
	return (SteamInventoryResultReady_t*)lua_touserdata(L, nParam);
}

SteamInventoryResultReady_t check_SteamInventoryResultReady_t(lua_State *L, int nParam) { return *check_SteamInventoryResultReady_t_ptr(L, nParam); }

void push_SteamInventoryFullUpdate_t(lua_State *L, SteamInventoryFullUpdate_t val) {
	SteamInventoryFullUpdate_t *ptr = (SteamInventoryFullUpdate_t*)lua_newuserdata(L, sizeof(SteamInventoryFullUpdate_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInventoryFullUpdate_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamInventoryFullUpdate_t *check_SteamInventoryFullUpdate_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamInventoryFullUpdate_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInventoryFullUpdate_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamInventoryFullUpdate_t expected");
	return (SteamInventoryFullUpdate_t*)lua_touserdata(L, nParam);
}

SteamInventoryFullUpdate_t check_SteamInventoryFullUpdate_t(lua_State *L, int nParam) { return *check_SteamInventoryFullUpdate_t_ptr(L, nParam); }

void push_SteamInventoryDefinitionUpdate_t(lua_State *L, SteamInventoryDefinitionUpdate_t val) {
	SteamInventoryDefinitionUpdate_t *ptr = (SteamInventoryDefinitionUpdate_t*)lua_newuserdata(L, sizeof(SteamInventoryDefinitionUpdate_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInventoryDefinitionUpdate_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamInventoryDefinitionUpdate_t *check_SteamInventoryDefinitionUpdate_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamInventoryDefinitionUpdate_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInventoryDefinitionUpdate_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamInventoryDefinitionUpdate_t expected");
	return (SteamInventoryDefinitionUpdate_t*)lua_touserdata(L, nParam);
}

SteamInventoryDefinitionUpdate_t check_SteamInventoryDefinitionUpdate_t(lua_State *L, int nParam) { return *check_SteamInventoryDefinitionUpdate_t_ptr(L, nParam); }

void push_SteamInventoryEligiblePromoItemDefIDs_t(lua_State *L, SteamInventoryEligiblePromoItemDefIDs_t val) {
	SteamInventoryEligiblePromoItemDefIDs_t *ptr = (SteamInventoryEligiblePromoItemDefIDs_t*)lua_newuserdata(L, sizeof(SteamInventoryEligiblePromoItemDefIDs_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInventoryEligiblePromoItemDefIDs_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamInventoryEligiblePromoItemDefIDs_t *check_SteamInventoryEligiblePromoItemDefIDs_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamInventoryEligiblePromoItemDefIDs_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInventoryEligiblePromoItemDefIDs_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamInventoryEligiblePromoItemDefIDs_t expected");
	return (SteamInventoryEligiblePromoItemDefIDs_t*)lua_touserdata(L, nParam);
}

SteamInventoryEligiblePromoItemDefIDs_t check_SteamInventoryEligiblePromoItemDefIDs_t(lua_State *L, int nParam) { return *check_SteamInventoryEligiblePromoItemDefIDs_t_ptr(L, nParam); }

void push_SteamInventoryStartPurchaseResult_t(lua_State *L, SteamInventoryStartPurchaseResult_t val) {
	SteamInventoryStartPurchaseResult_t *ptr = (SteamInventoryStartPurchaseResult_t*)lua_newuserdata(L, sizeof(SteamInventoryStartPurchaseResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInventoryStartPurchaseResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamInventoryStartPurchaseResult_t *check_SteamInventoryStartPurchaseResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamInventoryStartPurchaseResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInventoryStartPurchaseResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamInventoryStartPurchaseResult_t expected");
	return (SteamInventoryStartPurchaseResult_t*)lua_touserdata(L, nParam);
}

SteamInventoryStartPurchaseResult_t check_SteamInventoryStartPurchaseResult_t(lua_State *L, int nParam) { return *check_SteamInventoryStartPurchaseResult_t_ptr(L, nParam); }

void push_SteamInventoryRequestPricesResult_t(lua_State *L, SteamInventoryRequestPricesResult_t val) {
	SteamInventoryRequestPricesResult_t *ptr = (SteamInventoryRequestPricesResult_t*)lua_newuserdata(L, sizeof(SteamInventoryRequestPricesResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInventoryRequestPricesResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamInventoryRequestPricesResult_t *check_SteamInventoryRequestPricesResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamInventoryRequestPricesResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamInventoryRequestPricesResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamInventoryRequestPricesResult_t expected");
	return (SteamInventoryRequestPricesResult_t*)lua_touserdata(L, nParam);
}

SteamInventoryRequestPricesResult_t check_SteamInventoryRequestPricesResult_t(lua_State *L, int nParam) { return *check_SteamInventoryRequestPricesResult_t_ptr(L, nParam); }

void push_SteamTimelineGamePhaseRecordingExists_t(lua_State *L, SteamTimelineGamePhaseRecordingExists_t val) {
	SteamTimelineGamePhaseRecordingExists_t *ptr = (SteamTimelineGamePhaseRecordingExists_t*)lua_newuserdata(L, sizeof(SteamTimelineGamePhaseRecordingExists_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamTimelineGamePhaseRecordingExists_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamTimelineGamePhaseRecordingExists_t *check_SteamTimelineGamePhaseRecordingExists_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamTimelineGamePhaseRecordingExists_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamTimelineGamePhaseRecordingExists_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamTimelineGamePhaseRecordingExists_t expected");
	return (SteamTimelineGamePhaseRecordingExists_t*)lua_touserdata(L, nParam);
}

SteamTimelineGamePhaseRecordingExists_t check_SteamTimelineGamePhaseRecordingExists_t(lua_State *L, int nParam) { return *check_SteamTimelineGamePhaseRecordingExists_t_ptr(L, nParam); }

void push_SteamTimelineEventRecordingExists_t(lua_State *L, SteamTimelineEventRecordingExists_t val) {
	SteamTimelineEventRecordingExists_t *ptr = (SteamTimelineEventRecordingExists_t*)lua_newuserdata(L, sizeof(SteamTimelineEventRecordingExists_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamTimelineEventRecordingExists_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamTimelineEventRecordingExists_t *check_SteamTimelineEventRecordingExists_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamTimelineEventRecordingExists_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamTimelineEventRecordingExists_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamTimelineEventRecordingExists_t expected");
	return (SteamTimelineEventRecordingExists_t*)lua_touserdata(L, nParam);
}

SteamTimelineEventRecordingExists_t check_SteamTimelineEventRecordingExists_t(lua_State *L, int nParam) { return *check_SteamTimelineEventRecordingExists_t_ptr(L, nParam); }

void push_GetVideoURLResult_t(lua_State *L, GetVideoURLResult_t val) {
	GetVideoURLResult_t *ptr = (GetVideoURLResult_t*)lua_newuserdata(L, sizeof(GetVideoURLResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, GetVideoURLResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

GetVideoURLResult_t *check_GetVideoURLResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "GetVideoURLResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, GetVideoURLResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "GetVideoURLResult_t expected");
	return (GetVideoURLResult_t*)lua_touserdata(L, nParam);
}

GetVideoURLResult_t check_GetVideoURLResult_t(lua_State *L, int nParam) { return *check_GetVideoURLResult_t_ptr(L, nParam); }

void push_GetOPFSettingsResult_t(lua_State *L, GetOPFSettingsResult_t val) {
	GetOPFSettingsResult_t *ptr = (GetOPFSettingsResult_t*)lua_newuserdata(L, sizeof(GetOPFSettingsResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, GetOPFSettingsResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

GetOPFSettingsResult_t *check_GetOPFSettingsResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "GetOPFSettingsResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, GetOPFSettingsResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "GetOPFSettingsResult_t expected");
	return (GetOPFSettingsResult_t*)lua_touserdata(L, nParam);
}

GetOPFSettingsResult_t check_GetOPFSettingsResult_t(lua_State *L, int nParam) { return *check_GetOPFSettingsResult_t_ptr(L, nParam); }

void push_BroadcastUploadStart_t(lua_State *L, BroadcastUploadStart_t val) {
	BroadcastUploadStart_t *ptr = (BroadcastUploadStart_t*)lua_newuserdata(L, sizeof(BroadcastUploadStart_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, BroadcastUploadStart_tMetatable_ref);
	lua_setmetatable(L, -2);
}

BroadcastUploadStart_t *check_BroadcastUploadStart_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "BroadcastUploadStart_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, BroadcastUploadStart_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "BroadcastUploadStart_t expected");
	return (BroadcastUploadStart_t*)lua_touserdata(L, nParam);
}

BroadcastUploadStart_t check_BroadcastUploadStart_t(lua_State *L, int nParam) { return *check_BroadcastUploadStart_t_ptr(L, nParam); }

void push_BroadcastUploadStop_t(lua_State *L, BroadcastUploadStop_t val) {
	BroadcastUploadStop_t *ptr = (BroadcastUploadStop_t*)lua_newuserdata(L, sizeof(BroadcastUploadStop_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, BroadcastUploadStop_tMetatable_ref);
	lua_setmetatable(L, -2);
}

BroadcastUploadStop_t *check_BroadcastUploadStop_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "BroadcastUploadStop_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, BroadcastUploadStop_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "BroadcastUploadStop_t expected");
	return (BroadcastUploadStop_t*)lua_touserdata(L, nParam);
}

BroadcastUploadStop_t check_BroadcastUploadStop_t(lua_State *L, int nParam) { return *check_BroadcastUploadStop_t_ptr(L, nParam); }

void push_SteamParentalSettingsChanged_t(lua_State *L, SteamParentalSettingsChanged_t val) {
	SteamParentalSettingsChanged_t *ptr = (SteamParentalSettingsChanged_t*)lua_newuserdata(L, sizeof(SteamParentalSettingsChanged_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamParentalSettingsChanged_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamParentalSettingsChanged_t *check_SteamParentalSettingsChanged_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamParentalSettingsChanged_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamParentalSettingsChanged_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamParentalSettingsChanged_t expected");
	return (SteamParentalSettingsChanged_t*)lua_touserdata(L, nParam);
}

SteamParentalSettingsChanged_t check_SteamParentalSettingsChanged_t(lua_State *L, int nParam) { return *check_SteamParentalSettingsChanged_t_ptr(L, nParam); }

void push_SteamRemotePlaySessionConnected_t(lua_State *L, SteamRemotePlaySessionConnected_t val) {
	SteamRemotePlaySessionConnected_t *ptr = (SteamRemotePlaySessionConnected_t*)lua_newuserdata(L, sizeof(SteamRemotePlaySessionConnected_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamRemotePlaySessionConnected_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamRemotePlaySessionConnected_t *check_SteamRemotePlaySessionConnected_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamRemotePlaySessionConnected_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamRemotePlaySessionConnected_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamRemotePlaySessionConnected_t expected");
	return (SteamRemotePlaySessionConnected_t*)lua_touserdata(L, nParam);
}

SteamRemotePlaySessionConnected_t check_SteamRemotePlaySessionConnected_t(lua_State *L, int nParam) { return *check_SteamRemotePlaySessionConnected_t_ptr(L, nParam); }

void push_SteamRemotePlaySessionDisconnected_t(lua_State *L, SteamRemotePlaySessionDisconnected_t val) {
	SteamRemotePlaySessionDisconnected_t *ptr = (SteamRemotePlaySessionDisconnected_t*)lua_newuserdata(L, sizeof(SteamRemotePlaySessionDisconnected_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamRemotePlaySessionDisconnected_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamRemotePlaySessionDisconnected_t *check_SteamRemotePlaySessionDisconnected_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamRemotePlaySessionDisconnected_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamRemotePlaySessionDisconnected_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamRemotePlaySessionDisconnected_t expected");
	return (SteamRemotePlaySessionDisconnected_t*)lua_touserdata(L, nParam);
}

SteamRemotePlaySessionDisconnected_t check_SteamRemotePlaySessionDisconnected_t(lua_State *L, int nParam) { return *check_SteamRemotePlaySessionDisconnected_t_ptr(L, nParam); }

void push_SteamRemotePlayTogetherGuestInvite_t(lua_State *L, SteamRemotePlayTogetherGuestInvite_t val) {
	SteamRemotePlayTogetherGuestInvite_t *ptr = (SteamRemotePlayTogetherGuestInvite_t*)lua_newuserdata(L, sizeof(SteamRemotePlayTogetherGuestInvite_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamRemotePlayTogetherGuestInvite_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamRemotePlayTogetherGuestInvite_t *check_SteamRemotePlayTogetherGuestInvite_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamRemotePlayTogetherGuestInvite_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamRemotePlayTogetherGuestInvite_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamRemotePlayTogetherGuestInvite_t expected");
	return (SteamRemotePlayTogetherGuestInvite_t*)lua_touserdata(L, nParam);
}

SteamRemotePlayTogetherGuestInvite_t check_SteamRemotePlayTogetherGuestInvite_t(lua_State *L, int nParam) { return *check_SteamRemotePlayTogetherGuestInvite_t_ptr(L, nParam); }

void push_SteamNetworkingMessagesSessionRequest_t(lua_State *L, SteamNetworkingMessagesSessionRequest_t val) {
	SteamNetworkingMessagesSessionRequest_t *ptr = (SteamNetworkingMessagesSessionRequest_t*)lua_newuserdata(L, sizeof(SteamNetworkingMessagesSessionRequest_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetworkingMessagesSessionRequest_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamNetworkingMessagesSessionRequest_t *check_SteamNetworkingMessagesSessionRequest_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamNetworkingMessagesSessionRequest_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetworkingMessagesSessionRequest_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamNetworkingMessagesSessionRequest_t expected");
	return (SteamNetworkingMessagesSessionRequest_t*)lua_touserdata(L, nParam);
}

SteamNetworkingMessagesSessionRequest_t check_SteamNetworkingMessagesSessionRequest_t(lua_State *L, int nParam) { return *check_SteamNetworkingMessagesSessionRequest_t_ptr(L, nParam); }

void push_SteamNetworkingMessagesSessionFailed_t(lua_State *L, SteamNetworkingMessagesSessionFailed_t val) {
	SteamNetworkingMessagesSessionFailed_t *ptr = (SteamNetworkingMessagesSessionFailed_t*)lua_newuserdata(L, sizeof(SteamNetworkingMessagesSessionFailed_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetworkingMessagesSessionFailed_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamNetworkingMessagesSessionFailed_t *check_SteamNetworkingMessagesSessionFailed_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamNetworkingMessagesSessionFailed_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetworkingMessagesSessionFailed_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamNetworkingMessagesSessionFailed_t expected");
	return (SteamNetworkingMessagesSessionFailed_t*)lua_touserdata(L, nParam);
}

SteamNetworkingMessagesSessionFailed_t check_SteamNetworkingMessagesSessionFailed_t(lua_State *L, int nParam) { return *check_SteamNetworkingMessagesSessionFailed_t_ptr(L, nParam); }

void push_SteamNetConnectionStatusChangedCallback_t(lua_State *L, SteamNetConnectionStatusChangedCallback_t val) {
	SteamNetConnectionStatusChangedCallback_t *ptr = (SteamNetConnectionStatusChangedCallback_t*)lua_newuserdata(L, sizeof(SteamNetConnectionStatusChangedCallback_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetConnectionStatusChangedCallback_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamNetConnectionStatusChangedCallback_t *check_SteamNetConnectionStatusChangedCallback_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamNetConnectionStatusChangedCallback_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetConnectionStatusChangedCallback_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamNetConnectionStatusChangedCallback_t expected");
	return (SteamNetConnectionStatusChangedCallback_t*)lua_touserdata(L, nParam);
}

SteamNetConnectionStatusChangedCallback_t check_SteamNetConnectionStatusChangedCallback_t(lua_State *L, int nParam) { return *check_SteamNetConnectionStatusChangedCallback_t_ptr(L, nParam); }

void push_SteamNetAuthenticationStatus_t(lua_State *L, SteamNetAuthenticationStatus_t val) {
	SteamNetAuthenticationStatus_t *ptr = (SteamNetAuthenticationStatus_t*)lua_newuserdata(L, sizeof(SteamNetAuthenticationStatus_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetAuthenticationStatus_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamNetAuthenticationStatus_t *check_SteamNetAuthenticationStatus_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamNetAuthenticationStatus_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetAuthenticationStatus_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamNetAuthenticationStatus_t expected");
	return (SteamNetAuthenticationStatus_t*)lua_touserdata(L, nParam);
}

SteamNetAuthenticationStatus_t check_SteamNetAuthenticationStatus_t(lua_State *L, int nParam) { return *check_SteamNetAuthenticationStatus_t_ptr(L, nParam); }

void push_SteamRelayNetworkStatus_t(lua_State *L, SteamRelayNetworkStatus_t val) {
	SteamRelayNetworkStatus_t *ptr = (SteamRelayNetworkStatus_t*)lua_newuserdata(L, sizeof(SteamRelayNetworkStatus_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamRelayNetworkStatus_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamRelayNetworkStatus_t *check_SteamRelayNetworkStatus_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamRelayNetworkStatus_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamRelayNetworkStatus_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamRelayNetworkStatus_t expected");
	return (SteamRelayNetworkStatus_t*)lua_touserdata(L, nParam);
}

SteamRelayNetworkStatus_t check_SteamRelayNetworkStatus_t(lua_State *L, int nParam) { return *check_SteamRelayNetworkStatus_t_ptr(L, nParam); }

void push_GSClientApprove_t(lua_State *L, GSClientApprove_t val) {
	GSClientApprove_t *ptr = (GSClientApprove_t*)lua_newuserdata(L, sizeof(GSClientApprove_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSClientApprove_tMetatable_ref);
	lua_setmetatable(L, -2);
}

GSClientApprove_t *check_GSClientApprove_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "GSClientApprove_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSClientApprove_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "GSClientApprove_t expected");
	return (GSClientApprove_t*)lua_touserdata(L, nParam);
}

GSClientApprove_t check_GSClientApprove_t(lua_State *L, int nParam) { return *check_GSClientApprove_t_ptr(L, nParam); }

void push_GSClientDeny_t(lua_State *L, GSClientDeny_t val) {
	GSClientDeny_t *ptr = (GSClientDeny_t*)lua_newuserdata(L, sizeof(GSClientDeny_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSClientDeny_tMetatable_ref);
	lua_setmetatable(L, -2);
}

GSClientDeny_t *check_GSClientDeny_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "GSClientDeny_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSClientDeny_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "GSClientDeny_t expected");
	return (GSClientDeny_t*)lua_touserdata(L, nParam);
}

GSClientDeny_t check_GSClientDeny_t(lua_State *L, int nParam) { return *check_GSClientDeny_t_ptr(L, nParam); }

void push_GSClientKick_t(lua_State *L, GSClientKick_t val) {
	GSClientKick_t *ptr = (GSClientKick_t*)lua_newuserdata(L, sizeof(GSClientKick_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSClientKick_tMetatable_ref);
	lua_setmetatable(L, -2);
}

GSClientKick_t *check_GSClientKick_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "GSClientKick_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSClientKick_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "GSClientKick_t expected");
	return (GSClientKick_t*)lua_touserdata(L, nParam);
}

GSClientKick_t check_GSClientKick_t(lua_State *L, int nParam) { return *check_GSClientKick_t_ptr(L, nParam); }

void push_GSClientAchievementStatus_t(lua_State *L, GSClientAchievementStatus_t val) {
	GSClientAchievementStatus_t *ptr = (GSClientAchievementStatus_t*)lua_newuserdata(L, sizeof(GSClientAchievementStatus_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSClientAchievementStatus_tMetatable_ref);
	lua_setmetatable(L, -2);
}

GSClientAchievementStatus_t *check_GSClientAchievementStatus_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "GSClientAchievementStatus_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSClientAchievementStatus_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "GSClientAchievementStatus_t expected");
	return (GSClientAchievementStatus_t*)lua_touserdata(L, nParam);
}

GSClientAchievementStatus_t check_GSClientAchievementStatus_t(lua_State *L, int nParam) { return *check_GSClientAchievementStatus_t_ptr(L, nParam); }

void push_GSPolicyResponse_t(lua_State *L, GSPolicyResponse_t val) {
	GSPolicyResponse_t *ptr = (GSPolicyResponse_t*)lua_newuserdata(L, sizeof(GSPolicyResponse_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSPolicyResponse_tMetatable_ref);
	lua_setmetatable(L, -2);
}

GSPolicyResponse_t *check_GSPolicyResponse_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "GSPolicyResponse_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSPolicyResponse_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "GSPolicyResponse_t expected");
	return (GSPolicyResponse_t*)lua_touserdata(L, nParam);
}

GSPolicyResponse_t check_GSPolicyResponse_t(lua_State *L, int nParam) { return *check_GSPolicyResponse_t_ptr(L, nParam); }

void push_GSGameplayStats_t(lua_State *L, GSGameplayStats_t val) {
	GSGameplayStats_t *ptr = (GSGameplayStats_t*)lua_newuserdata(L, sizeof(GSGameplayStats_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSGameplayStats_tMetatable_ref);
	lua_setmetatable(L, -2);
}

GSGameplayStats_t *check_GSGameplayStats_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "GSGameplayStats_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSGameplayStats_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "GSGameplayStats_t expected");
	return (GSGameplayStats_t*)lua_touserdata(L, nParam);
}

GSGameplayStats_t check_GSGameplayStats_t(lua_State *L, int nParam) { return *check_GSGameplayStats_t_ptr(L, nParam); }

void push_GSClientGroupStatus_t(lua_State *L, GSClientGroupStatus_t val) {
	GSClientGroupStatus_t *ptr = (GSClientGroupStatus_t*)lua_newuserdata(L, sizeof(GSClientGroupStatus_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSClientGroupStatus_tMetatable_ref);
	lua_setmetatable(L, -2);
}

GSClientGroupStatus_t *check_GSClientGroupStatus_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "GSClientGroupStatus_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSClientGroupStatus_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "GSClientGroupStatus_t expected");
	return (GSClientGroupStatus_t*)lua_touserdata(L, nParam);
}

GSClientGroupStatus_t check_GSClientGroupStatus_t(lua_State *L, int nParam) { return *check_GSClientGroupStatus_t_ptr(L, nParam); }

void push_GSReputation_t(lua_State *L, GSReputation_t val) {
	GSReputation_t *ptr = (GSReputation_t*)lua_newuserdata(L, sizeof(GSReputation_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSReputation_tMetatable_ref);
	lua_setmetatable(L, -2);
}

GSReputation_t *check_GSReputation_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "GSReputation_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSReputation_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "GSReputation_t expected");
	return (GSReputation_t*)lua_touserdata(L, nParam);
}

GSReputation_t check_GSReputation_t(lua_State *L, int nParam) { return *check_GSReputation_t_ptr(L, nParam); }

void push_AssociateWithClanResult_t(lua_State *L, AssociateWithClanResult_t val) {
	AssociateWithClanResult_t *ptr = (AssociateWithClanResult_t*)lua_newuserdata(L, sizeof(AssociateWithClanResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, AssociateWithClanResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

AssociateWithClanResult_t *check_AssociateWithClanResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "AssociateWithClanResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, AssociateWithClanResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "AssociateWithClanResult_t expected");
	return (AssociateWithClanResult_t*)lua_touserdata(L, nParam);
}

AssociateWithClanResult_t check_AssociateWithClanResult_t(lua_State *L, int nParam) { return *check_AssociateWithClanResult_t_ptr(L, nParam); }

void push_ComputeNewPlayerCompatibilityResult_t(lua_State *L, ComputeNewPlayerCompatibilityResult_t val) {
	ComputeNewPlayerCompatibilityResult_t *ptr = (ComputeNewPlayerCompatibilityResult_t*)lua_newuserdata(L, sizeof(ComputeNewPlayerCompatibilityResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, ComputeNewPlayerCompatibilityResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

ComputeNewPlayerCompatibilityResult_t *check_ComputeNewPlayerCompatibilityResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "ComputeNewPlayerCompatibilityResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, ComputeNewPlayerCompatibilityResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "ComputeNewPlayerCompatibilityResult_t expected");
	return (ComputeNewPlayerCompatibilityResult_t*)lua_touserdata(L, nParam);
}

ComputeNewPlayerCompatibilityResult_t check_ComputeNewPlayerCompatibilityResult_t(lua_State *L, int nParam) { return *check_ComputeNewPlayerCompatibilityResult_t_ptr(L, nParam); }

void push_GSStatsReceived_t(lua_State *L, GSStatsReceived_t val) {
	GSStatsReceived_t *ptr = (GSStatsReceived_t*)lua_newuserdata(L, sizeof(GSStatsReceived_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSStatsReceived_tMetatable_ref);
	lua_setmetatable(L, -2);
}

GSStatsReceived_t *check_GSStatsReceived_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "GSStatsReceived_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSStatsReceived_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "GSStatsReceived_t expected");
	return (GSStatsReceived_t*)lua_touserdata(L, nParam);
}

GSStatsReceived_t check_GSStatsReceived_t(lua_State *L, int nParam) { return *check_GSStatsReceived_t_ptr(L, nParam); }

void push_GSStatsStored_t(lua_State *L, GSStatsStored_t val) {
	GSStatsStored_t *ptr = (GSStatsStored_t*)lua_newuserdata(L, sizeof(GSStatsStored_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSStatsStored_tMetatable_ref);
	lua_setmetatable(L, -2);
}

GSStatsStored_t *check_GSStatsStored_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "GSStatsStored_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSStatsStored_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "GSStatsStored_t expected");
	return (GSStatsStored_t*)lua_touserdata(L, nParam);
}

GSStatsStored_t check_GSStatsStored_t(lua_State *L, int nParam) { return *check_GSStatsStored_t_ptr(L, nParam); }

void push_GSStatsUnloaded_t(lua_State *L, GSStatsUnloaded_t val) {
	GSStatsUnloaded_t *ptr = (GSStatsUnloaded_t*)lua_newuserdata(L, sizeof(GSStatsUnloaded_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSStatsUnloaded_tMetatable_ref);
	lua_setmetatable(L, -2);
}

GSStatsUnloaded_t *check_GSStatsUnloaded_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "GSStatsUnloaded_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, GSStatsUnloaded_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "GSStatsUnloaded_t expected");
	return (GSStatsUnloaded_t*)lua_touserdata(L, nParam);
}

GSStatsUnloaded_t check_GSStatsUnloaded_t(lua_State *L, int nParam) { return *check_GSStatsUnloaded_t_ptr(L, nParam); }

void push_SteamNetworkingFakeIPResult_t(lua_State *L, SteamNetworkingFakeIPResult_t val) {
	SteamNetworkingFakeIPResult_t *ptr = (SteamNetworkingFakeIPResult_t*)lua_newuserdata(L, sizeof(SteamNetworkingFakeIPResult_t));
	*ptr = val;
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetworkingFakeIPResult_tMetatable_ref);
	lua_setmetatable(L, -2);
}

SteamNetworkingFakeIPResult_t *check_SteamNetworkingFakeIPResult_t_ptr(lua_State *L, int nParam) {
	luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, "SteamNetworkingFakeIPResult_t expected");
	lua_rawgeti(L, LUA_REGISTRYINDEX, SteamNetworkingFakeIPResult_tMetatable_ref);
	lua_getmetatable(L, nParam);
	bool ok = lua_rawequal(L, -1, -2);
	lua_pop(L, 2);
	luaL_argcheck(L, ok, nParam, "SteamNetworkingFakeIPResult_t expected");
	return (SteamNetworkingFakeIPResult_t*)lua_touserdata(L, nParam);
}

SteamNetworkingFakeIPResult_t check_SteamNetworkingFakeIPResult_t(lua_State *L, int nParam) { return *check_SteamNetworkingFakeIPResult_t_ptr(L, nParam); }

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
	// SteamServersConnected_t metatable
	lua_createtable(L, 0, 1);
	add_func(L, "__index", SteamServersConnected_t_index);
	SteamServersConnected_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamServerConnectFailure_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamServerConnectFailure_t_index);
	add_func(L, "__newindex", SteamServerConnectFailure_t_newindex);
	SteamServerConnectFailure_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamServersDisconnected_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamServersDisconnected_t_index);
	add_func(L, "__newindex", SteamServersDisconnected_t_newindex);
	SteamServersDisconnected_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// ClientGameServerDeny_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", ClientGameServerDeny_t_index);
	add_func(L, "__newindex", ClientGameServerDeny_t_newindex);
	ClientGameServerDeny_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// IPCFailure_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", IPCFailure_t_index);
	add_func(L, "__newindex", IPCFailure_t_newindex);
	IPCFailure_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// LicensesUpdated_t metatable
	lua_createtable(L, 0, 1);
	add_func(L, "__index", LicensesUpdated_t_index);
	LicensesUpdated_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// ValidateAuthTicketResponse_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", ValidateAuthTicketResponse_t_index);
	add_func(L, "__newindex", ValidateAuthTicketResponse_t_newindex);
	ValidateAuthTicketResponse_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// MicroTxnAuthorizationResponse_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", MicroTxnAuthorizationResponse_t_index);
	add_func(L, "__newindex", MicroTxnAuthorizationResponse_t_newindex);
	MicroTxnAuthorizationResponse_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// EncryptedAppTicketResponse_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", EncryptedAppTicketResponse_t_index);
	add_func(L, "__newindex", EncryptedAppTicketResponse_t_newindex);
	EncryptedAppTicketResponse_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// GetAuthSessionTicketResponse_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", GetAuthSessionTicketResponse_t_index);
	add_func(L, "__newindex", GetAuthSessionTicketResponse_t_newindex);
	GetAuthSessionTicketResponse_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// GameWebCallback_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", GameWebCallback_t_index);
	add_func(L, "__newindex", GameWebCallback_t_newindex);
	GameWebCallback_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// StoreAuthURLResponse_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", StoreAuthURLResponse_t_index);
	add_func(L, "__newindex", StoreAuthURLResponse_t_newindex);
	StoreAuthURLResponse_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// MarketEligibilityResponse_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", MarketEligibilityResponse_t_index);
	add_func(L, "__newindex", MarketEligibilityResponse_t_newindex);
	MarketEligibilityResponse_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// DurationControl_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", DurationControl_t_index);
	add_func(L, "__newindex", DurationControl_t_newindex);
	DurationControl_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// GetTicketForWebApiResponse_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", GetTicketForWebApiResponse_t_index);
	add_func(L, "__newindex", GetTicketForWebApiResponse_t_newindex);
	GetTicketForWebApiResponse_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// PersonaStateChange_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", PersonaStateChange_t_index);
	add_func(L, "__newindex", PersonaStateChange_t_newindex);
	PersonaStateChange_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// GameOverlayActivated_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", GameOverlayActivated_t_index);
	add_func(L, "__newindex", GameOverlayActivated_t_newindex);
	GameOverlayActivated_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// GameServerChangeRequested_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", GameServerChangeRequested_t_index);
	add_func(L, "__newindex", GameServerChangeRequested_t_newindex);
	GameServerChangeRequested_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// GameLobbyJoinRequested_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", GameLobbyJoinRequested_t_index);
	add_func(L, "__newindex", GameLobbyJoinRequested_t_newindex);
	GameLobbyJoinRequested_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// AvatarImageLoaded_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", AvatarImageLoaded_t_index);
	add_func(L, "__newindex", AvatarImageLoaded_t_newindex);
	AvatarImageLoaded_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// ClanOfficerListResponse_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", ClanOfficerListResponse_t_index);
	add_func(L, "__newindex", ClanOfficerListResponse_t_newindex);
	ClanOfficerListResponse_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// FriendRichPresenceUpdate_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", FriendRichPresenceUpdate_t_index);
	add_func(L, "__newindex", FriendRichPresenceUpdate_t_newindex);
	FriendRichPresenceUpdate_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// GameRichPresenceJoinRequested_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", GameRichPresenceJoinRequested_t_index);
	add_func(L, "__newindex", GameRichPresenceJoinRequested_t_newindex);
	GameRichPresenceJoinRequested_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// GameConnectedClanChatMsg_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", GameConnectedClanChatMsg_t_index);
	add_func(L, "__newindex", GameConnectedClanChatMsg_t_newindex);
	GameConnectedClanChatMsg_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// GameConnectedChatJoin_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", GameConnectedChatJoin_t_index);
	add_func(L, "__newindex", GameConnectedChatJoin_t_newindex);
	GameConnectedChatJoin_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// GameConnectedChatLeave_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", GameConnectedChatLeave_t_index);
	add_func(L, "__newindex", GameConnectedChatLeave_t_newindex);
	GameConnectedChatLeave_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// DownloadClanActivityCountsResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", DownloadClanActivityCountsResult_t_index);
	add_func(L, "__newindex", DownloadClanActivityCountsResult_t_newindex);
	DownloadClanActivityCountsResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// JoinClanChatRoomCompletionResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", JoinClanChatRoomCompletionResult_t_index);
	add_func(L, "__newindex", JoinClanChatRoomCompletionResult_t_newindex);
	JoinClanChatRoomCompletionResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// GameConnectedFriendChatMsg_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", GameConnectedFriendChatMsg_t_index);
	add_func(L, "__newindex", GameConnectedFriendChatMsg_t_newindex);
	GameConnectedFriendChatMsg_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// FriendsGetFollowerCount_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", FriendsGetFollowerCount_t_index);
	add_func(L, "__newindex", FriendsGetFollowerCount_t_newindex);
	FriendsGetFollowerCount_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// FriendsIsFollowing_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", FriendsIsFollowing_t_index);
	add_func(L, "__newindex", FriendsIsFollowing_t_newindex);
	FriendsIsFollowing_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// FriendsEnumerateFollowingList_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", FriendsEnumerateFollowingList_t_index);
	add_func(L, "__newindex", FriendsEnumerateFollowingList_t_newindex);
	FriendsEnumerateFollowingList_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// UnreadChatMessagesChanged_t metatable
	lua_createtable(L, 0, 1);
	add_func(L, "__index", UnreadChatMessagesChanged_t_index);
	UnreadChatMessagesChanged_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// OverlayBrowserProtocolNavigation_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", OverlayBrowserProtocolNavigation_t_index);
	add_func(L, "__newindex", OverlayBrowserProtocolNavigation_t_newindex);
	OverlayBrowserProtocolNavigation_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// EquippedProfileItemsChanged_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", EquippedProfileItemsChanged_t_index);
	add_func(L, "__newindex", EquippedProfileItemsChanged_t_newindex);
	EquippedProfileItemsChanged_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// EquippedProfileItems_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", EquippedProfileItems_t_index);
	add_func(L, "__newindex", EquippedProfileItems_t_newindex);
	EquippedProfileItems_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// IPCountry_t metatable
	lua_createtable(L, 0, 1);
	add_func(L, "__index", IPCountry_t_index);
	IPCountry_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// LowBatteryPower_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", LowBatteryPower_t_index);
	add_func(L, "__newindex", LowBatteryPower_t_newindex);
	LowBatteryPower_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamAPICallCompleted_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamAPICallCompleted_t_index);
	add_func(L, "__newindex", SteamAPICallCompleted_t_newindex);
	SteamAPICallCompleted_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamShutdown_t metatable
	lua_createtable(L, 0, 1);
	add_func(L, "__index", SteamShutdown_t_index);
	SteamShutdown_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// CheckFileSignature_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", CheckFileSignature_t_index);
	add_func(L, "__newindex", CheckFileSignature_t_newindex);
	CheckFileSignature_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// GamepadTextInputDismissed_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", GamepadTextInputDismissed_t_index);
	add_func(L, "__newindex", GamepadTextInputDismissed_t_newindex);
	GamepadTextInputDismissed_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// AppResumingFromSuspend_t metatable
	lua_createtable(L, 0, 1);
	add_func(L, "__index", AppResumingFromSuspend_t_index);
	AppResumingFromSuspend_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// FloatingGamepadTextInputDismissed_t metatable
	lua_createtable(L, 0, 1);
	add_func(L, "__index", FloatingGamepadTextInputDismissed_t_index);
	FloatingGamepadTextInputDismissed_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// FilterTextDictionaryChanged_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", FilterTextDictionaryChanged_t_index);
	add_func(L, "__newindex", FilterTextDictionaryChanged_t_newindex);
	FilterTextDictionaryChanged_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// FavoritesListChanged_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", FavoritesListChanged_t_index);
	add_func(L, "__newindex", FavoritesListChanged_t_newindex);
	FavoritesListChanged_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// LobbyInvite_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", LobbyInvite_t_index);
	add_func(L, "__newindex", LobbyInvite_t_newindex);
	LobbyInvite_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// LobbyEnter_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", LobbyEnter_t_index);
	add_func(L, "__newindex", LobbyEnter_t_newindex);
	LobbyEnter_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// LobbyDataUpdate_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", LobbyDataUpdate_t_index);
	add_func(L, "__newindex", LobbyDataUpdate_t_newindex);
	LobbyDataUpdate_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// LobbyChatUpdate_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", LobbyChatUpdate_t_index);
	add_func(L, "__newindex", LobbyChatUpdate_t_newindex);
	LobbyChatUpdate_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// LobbyChatMsg_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", LobbyChatMsg_t_index);
	add_func(L, "__newindex", LobbyChatMsg_t_newindex);
	LobbyChatMsg_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// LobbyGameCreated_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", LobbyGameCreated_t_index);
	add_func(L, "__newindex", LobbyGameCreated_t_newindex);
	LobbyGameCreated_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// LobbyMatchList_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", LobbyMatchList_t_index);
	add_func(L, "__newindex", LobbyMatchList_t_newindex);
	LobbyMatchList_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// LobbyKicked_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", LobbyKicked_t_index);
	add_func(L, "__newindex", LobbyKicked_t_newindex);
	LobbyKicked_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// LobbyCreated_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", LobbyCreated_t_index);
	add_func(L, "__newindex", LobbyCreated_t_newindex);
	LobbyCreated_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// FavoritesListAccountsUpdated_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", FavoritesListAccountsUpdated_t_index);
	add_func(L, "__newindex", FavoritesListAccountsUpdated_t_newindex);
	FavoritesListAccountsUpdated_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// JoinPartyCallback_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", JoinPartyCallback_t_index);
	add_func(L, "__newindex", JoinPartyCallback_t_newindex);
	JoinPartyCallback_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// CreateBeaconCallback_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", CreateBeaconCallback_t_index);
	add_func(L, "__newindex", CreateBeaconCallback_t_newindex);
	CreateBeaconCallback_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// ReservationNotificationCallback_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", ReservationNotificationCallback_t_index);
	add_func(L, "__newindex", ReservationNotificationCallback_t_newindex);
	ReservationNotificationCallback_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// ChangeNumOpenSlotsCallback_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", ChangeNumOpenSlotsCallback_t_index);
	add_func(L, "__newindex", ChangeNumOpenSlotsCallback_t_newindex);
	ChangeNumOpenSlotsCallback_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// AvailableBeaconLocationsUpdated_t metatable
	lua_createtable(L, 0, 1);
	add_func(L, "__index", AvailableBeaconLocationsUpdated_t_index);
	AvailableBeaconLocationsUpdated_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// ActiveBeaconsUpdated_t metatable
	lua_createtable(L, 0, 1);
	add_func(L, "__index", ActiveBeaconsUpdated_t_index);
	ActiveBeaconsUpdated_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemoteStorageFileShareResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", RemoteStorageFileShareResult_t_index);
	add_func(L, "__newindex", RemoteStorageFileShareResult_t_newindex);
	RemoteStorageFileShareResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemoteStoragePublishFileResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", RemoteStoragePublishFileResult_t_index);
	add_func(L, "__newindex", RemoteStoragePublishFileResult_t_newindex);
	RemoteStoragePublishFileResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemoteStorageDeletePublishedFileResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", RemoteStorageDeletePublishedFileResult_t_index);
	add_func(L, "__newindex", RemoteStorageDeletePublishedFileResult_t_newindex);
	RemoteStorageDeletePublishedFileResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemoteStorageEnumerateUserPublishedFilesResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", RemoteStorageEnumerateUserPublishedFilesResult_t_index);
	add_func(L, "__newindex", RemoteStorageEnumerateUserPublishedFilesResult_t_newindex);
	RemoteStorageEnumerateUserPublishedFilesResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemoteStorageSubscribePublishedFileResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", RemoteStorageSubscribePublishedFileResult_t_index);
	add_func(L, "__newindex", RemoteStorageSubscribePublishedFileResult_t_newindex);
	RemoteStorageSubscribePublishedFileResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemoteStorageEnumerateUserSubscribedFilesResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", RemoteStorageEnumerateUserSubscribedFilesResult_t_index);
	add_func(L, "__newindex", RemoteStorageEnumerateUserSubscribedFilesResult_t_newindex);
	RemoteStorageEnumerateUserSubscribedFilesResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemoteStorageUnsubscribePublishedFileResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", RemoteStorageUnsubscribePublishedFileResult_t_index);
	add_func(L, "__newindex", RemoteStorageUnsubscribePublishedFileResult_t_newindex);
	RemoteStorageUnsubscribePublishedFileResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemoteStorageUpdatePublishedFileResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", RemoteStorageUpdatePublishedFileResult_t_index);
	add_func(L, "__newindex", RemoteStorageUpdatePublishedFileResult_t_newindex);
	RemoteStorageUpdatePublishedFileResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemoteStorageDownloadUGCResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", RemoteStorageDownloadUGCResult_t_index);
	add_func(L, "__newindex", RemoteStorageDownloadUGCResult_t_newindex);
	RemoteStorageDownloadUGCResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemoteStorageGetPublishedFileDetailsResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", RemoteStorageGetPublishedFileDetailsResult_t_index);
	add_func(L, "__newindex", RemoteStorageGetPublishedFileDetailsResult_t_newindex);
	RemoteStorageGetPublishedFileDetailsResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemoteStorageEnumerateWorkshopFilesResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", RemoteStorageEnumerateWorkshopFilesResult_t_index);
	add_func(L, "__newindex", RemoteStorageEnumerateWorkshopFilesResult_t_newindex);
	RemoteStorageEnumerateWorkshopFilesResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemoteStorageGetPublishedItemVoteDetailsResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", RemoteStorageGetPublishedItemVoteDetailsResult_t_index);
	add_func(L, "__newindex", RemoteStorageGetPublishedItemVoteDetailsResult_t_newindex);
	RemoteStorageGetPublishedItemVoteDetailsResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemoteStoragePublishedFileSubscribed_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", RemoteStoragePublishedFileSubscribed_t_index);
	add_func(L, "__newindex", RemoteStoragePublishedFileSubscribed_t_newindex);
	RemoteStoragePublishedFileSubscribed_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemoteStoragePublishedFileUnsubscribed_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", RemoteStoragePublishedFileUnsubscribed_t_index);
	add_func(L, "__newindex", RemoteStoragePublishedFileUnsubscribed_t_newindex);
	RemoteStoragePublishedFileUnsubscribed_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemoteStoragePublishedFileDeleted_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", RemoteStoragePublishedFileDeleted_t_index);
	add_func(L, "__newindex", RemoteStoragePublishedFileDeleted_t_newindex);
	RemoteStoragePublishedFileDeleted_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemoteStorageUpdateUserPublishedItemVoteResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", RemoteStorageUpdateUserPublishedItemVoteResult_t_index);
	add_func(L, "__newindex", RemoteStorageUpdateUserPublishedItemVoteResult_t_newindex);
	RemoteStorageUpdateUserPublishedItemVoteResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemoteStorageUserVoteDetails_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", RemoteStorageUserVoteDetails_t_index);
	add_func(L, "__newindex", RemoteStorageUserVoteDetails_t_newindex);
	RemoteStorageUserVoteDetails_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemoteStorageEnumerateUserSharedWorkshopFilesResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", RemoteStorageEnumerateUserSharedWorkshopFilesResult_t_index);
	add_func(L, "__newindex", RemoteStorageEnumerateUserSharedWorkshopFilesResult_t_newindex);
	RemoteStorageEnumerateUserSharedWorkshopFilesResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemoteStorageSetUserPublishedFileActionResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", RemoteStorageSetUserPublishedFileActionResult_t_index);
	add_func(L, "__newindex", RemoteStorageSetUserPublishedFileActionResult_t_newindex);
	RemoteStorageSetUserPublishedFileActionResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemoteStorageEnumeratePublishedFilesByUserActionResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", RemoteStorageEnumeratePublishedFilesByUserActionResult_t_index);
	add_func(L, "__newindex", RemoteStorageEnumeratePublishedFilesByUserActionResult_t_newindex);
	RemoteStorageEnumeratePublishedFilesByUserActionResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemoteStoragePublishFileProgress_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", RemoteStoragePublishFileProgress_t_index);
	add_func(L, "__newindex", RemoteStoragePublishFileProgress_t_newindex);
	RemoteStoragePublishFileProgress_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemoteStoragePublishedFileUpdated_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", RemoteStoragePublishedFileUpdated_t_index);
	add_func(L, "__newindex", RemoteStoragePublishedFileUpdated_t_newindex);
	RemoteStoragePublishedFileUpdated_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemoteStorageFileWriteAsyncComplete_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", RemoteStorageFileWriteAsyncComplete_t_index);
	add_func(L, "__newindex", RemoteStorageFileWriteAsyncComplete_t_newindex);
	RemoteStorageFileWriteAsyncComplete_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemoteStorageFileReadAsyncComplete_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", RemoteStorageFileReadAsyncComplete_t_index);
	add_func(L, "__newindex", RemoteStorageFileReadAsyncComplete_t_newindex);
	RemoteStorageFileReadAsyncComplete_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemoteStorageLocalFileChange_t metatable
	lua_createtable(L, 0, 1);
	add_func(L, "__index", RemoteStorageLocalFileChange_t_index);
	RemoteStorageLocalFileChange_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// UserStatsReceived_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", UserStatsReceived_t_index);
	add_func(L, "__newindex", UserStatsReceived_t_newindex);
	UserStatsReceived_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// UserStatsStored_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", UserStatsStored_t_index);
	add_func(L, "__newindex", UserStatsStored_t_newindex);
	UserStatsStored_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// UserAchievementStored_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", UserAchievementStored_t_index);
	add_func(L, "__newindex", UserAchievementStored_t_newindex);
	UserAchievementStored_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// LeaderboardFindResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", LeaderboardFindResult_t_index);
	add_func(L, "__newindex", LeaderboardFindResult_t_newindex);
	LeaderboardFindResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// LeaderboardScoresDownloaded_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", LeaderboardScoresDownloaded_t_index);
	add_func(L, "__newindex", LeaderboardScoresDownloaded_t_newindex);
	LeaderboardScoresDownloaded_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// LeaderboardScoreUploaded_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", LeaderboardScoreUploaded_t_index);
	add_func(L, "__newindex", LeaderboardScoreUploaded_t_newindex);
	LeaderboardScoreUploaded_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// NumberOfCurrentPlayers_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", NumberOfCurrentPlayers_t_index);
	add_func(L, "__newindex", NumberOfCurrentPlayers_t_newindex);
	NumberOfCurrentPlayers_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// UserStatsUnloaded_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", UserStatsUnloaded_t_index);
	add_func(L, "__newindex", UserStatsUnloaded_t_newindex);
	UserStatsUnloaded_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// UserAchievementIconFetched_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", UserAchievementIconFetched_t_index);
	add_func(L, "__newindex", UserAchievementIconFetched_t_newindex);
	UserAchievementIconFetched_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// GlobalAchievementPercentagesReady_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", GlobalAchievementPercentagesReady_t_index);
	add_func(L, "__newindex", GlobalAchievementPercentagesReady_t_newindex);
	GlobalAchievementPercentagesReady_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// LeaderboardUGCSet_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", LeaderboardUGCSet_t_index);
	add_func(L, "__newindex", LeaderboardUGCSet_t_newindex);
	LeaderboardUGCSet_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// GlobalStatsReceived_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", GlobalStatsReceived_t_index);
	add_func(L, "__newindex", GlobalStatsReceived_t_newindex);
	GlobalStatsReceived_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// DlcInstalled_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", DlcInstalled_t_index);
	add_func(L, "__newindex", DlcInstalled_t_newindex);
	DlcInstalled_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// NewUrlLaunchParameters_t metatable
	lua_createtable(L, 0, 1);
	add_func(L, "__index", NewUrlLaunchParameters_t_index);
	NewUrlLaunchParameters_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// AppProofOfPurchaseKeyResponse_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", AppProofOfPurchaseKeyResponse_t_index);
	add_func(L, "__newindex", AppProofOfPurchaseKeyResponse_t_newindex);
	AppProofOfPurchaseKeyResponse_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// FileDetailsResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", FileDetailsResult_t_index);
	add_func(L, "__newindex", FileDetailsResult_t_newindex);
	FileDetailsResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// TimedTrialStatus_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", TimedTrialStatus_t_index);
	add_func(L, "__newindex", TimedTrialStatus_t_newindex);
	TimedTrialStatus_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// P2PSessionRequest_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", P2PSessionRequest_t_index);
	add_func(L, "__newindex", P2PSessionRequest_t_newindex);
	P2PSessionRequest_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// P2PSessionConnectFail_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", P2PSessionConnectFail_t_index);
	add_func(L, "__newindex", P2PSessionConnectFail_t_newindex);
	P2PSessionConnectFail_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SocketStatusCallback_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SocketStatusCallback_t_index);
	add_func(L, "__newindex", SocketStatusCallback_t_newindex);
	SocketStatusCallback_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// ScreenshotReady_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", ScreenshotReady_t_index);
	add_func(L, "__newindex", ScreenshotReady_t_newindex);
	ScreenshotReady_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// ScreenshotRequested_t metatable
	lua_createtable(L, 0, 1);
	add_func(L, "__index", ScreenshotRequested_t_index);
	ScreenshotRequested_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// PlaybackStatusHasChanged_t metatable
	lua_createtable(L, 0, 1);
	add_func(L, "__index", PlaybackStatusHasChanged_t_index);
	PlaybackStatusHasChanged_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// VolumeHasChanged_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", VolumeHasChanged_t_index);
	add_func(L, "__newindex", VolumeHasChanged_t_newindex);
	VolumeHasChanged_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// HTTPRequestCompleted_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", HTTPRequestCompleted_t_index);
	add_func(L, "__newindex", HTTPRequestCompleted_t_newindex);
	HTTPRequestCompleted_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// HTTPRequestHeadersReceived_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", HTTPRequestHeadersReceived_t_index);
	add_func(L, "__newindex", HTTPRequestHeadersReceived_t_newindex);
	HTTPRequestHeadersReceived_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// HTTPRequestDataReceived_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", HTTPRequestDataReceived_t_index);
	add_func(L, "__newindex", HTTPRequestDataReceived_t_newindex);
	HTTPRequestDataReceived_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamInputDeviceConnected_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamInputDeviceConnected_t_index);
	add_func(L, "__newindex", SteamInputDeviceConnected_t_newindex);
	SteamInputDeviceConnected_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamInputDeviceDisconnected_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamInputDeviceDisconnected_t_index);
	add_func(L, "__newindex", SteamInputDeviceDisconnected_t_newindex);
	SteamInputDeviceDisconnected_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamInputConfigurationLoaded_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamInputConfigurationLoaded_t_index);
	add_func(L, "__newindex", SteamInputConfigurationLoaded_t_newindex);
	SteamInputConfigurationLoaded_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamInputGamepadSlotChange_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamInputGamepadSlotChange_t_index);
	add_func(L, "__newindex", SteamInputGamepadSlotChange_t_newindex);
	SteamInputGamepadSlotChange_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamUGCQueryCompleted_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamUGCQueryCompleted_t_index);
	add_func(L, "__newindex", SteamUGCQueryCompleted_t_newindex);
	SteamUGCQueryCompleted_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamUGCRequestUGCDetailsResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamUGCRequestUGCDetailsResult_t_index);
	add_func(L, "__newindex", SteamUGCRequestUGCDetailsResult_t_newindex);
	SteamUGCRequestUGCDetailsResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// CreateItemResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", CreateItemResult_t_index);
	add_func(L, "__newindex", CreateItemResult_t_newindex);
	CreateItemResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SubmitItemUpdateResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SubmitItemUpdateResult_t_index);
	add_func(L, "__newindex", SubmitItemUpdateResult_t_newindex);
	SubmitItemUpdateResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// ItemInstalled_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", ItemInstalled_t_index);
	add_func(L, "__newindex", ItemInstalled_t_newindex);
	ItemInstalled_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// DownloadItemResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", DownloadItemResult_t_index);
	add_func(L, "__newindex", DownloadItemResult_t_newindex);
	DownloadItemResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// UserFavoriteItemsListChanged_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", UserFavoriteItemsListChanged_t_index);
	add_func(L, "__newindex", UserFavoriteItemsListChanged_t_newindex);
	UserFavoriteItemsListChanged_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SetUserItemVoteResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SetUserItemVoteResult_t_index);
	add_func(L, "__newindex", SetUserItemVoteResult_t_newindex);
	SetUserItemVoteResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// GetUserItemVoteResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", GetUserItemVoteResult_t_index);
	add_func(L, "__newindex", GetUserItemVoteResult_t_newindex);
	GetUserItemVoteResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// StartPlaytimeTrackingResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", StartPlaytimeTrackingResult_t_index);
	add_func(L, "__newindex", StartPlaytimeTrackingResult_t_newindex);
	StartPlaytimeTrackingResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// StopPlaytimeTrackingResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", StopPlaytimeTrackingResult_t_index);
	add_func(L, "__newindex", StopPlaytimeTrackingResult_t_newindex);
	StopPlaytimeTrackingResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// AddUGCDependencyResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", AddUGCDependencyResult_t_index);
	add_func(L, "__newindex", AddUGCDependencyResult_t_newindex);
	AddUGCDependencyResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemoveUGCDependencyResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", RemoveUGCDependencyResult_t_index);
	add_func(L, "__newindex", RemoveUGCDependencyResult_t_newindex);
	RemoveUGCDependencyResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// AddAppDependencyResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", AddAppDependencyResult_t_index);
	add_func(L, "__newindex", AddAppDependencyResult_t_newindex);
	AddAppDependencyResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// RemoveAppDependencyResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", RemoveAppDependencyResult_t_index);
	add_func(L, "__newindex", RemoveAppDependencyResult_t_newindex);
	RemoveAppDependencyResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// GetAppDependenciesResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", GetAppDependenciesResult_t_index);
	add_func(L, "__newindex", GetAppDependenciesResult_t_newindex);
	GetAppDependenciesResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// DeleteItemResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", DeleteItemResult_t_index);
	add_func(L, "__newindex", DeleteItemResult_t_newindex);
	DeleteItemResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// UserSubscribedItemsListChanged_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", UserSubscribedItemsListChanged_t_index);
	add_func(L, "__newindex", UserSubscribedItemsListChanged_t_newindex);
	UserSubscribedItemsListChanged_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// WorkshopEULAStatus_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", WorkshopEULAStatus_t_index);
	add_func(L, "__newindex", WorkshopEULAStatus_t_newindex);
	WorkshopEULAStatus_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// HTML_BrowserReady_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", HTML_BrowserReady_t_index);
	add_func(L, "__newindex", HTML_BrowserReady_t_newindex);
	HTML_BrowserReady_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// HTML_NeedsPaint_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", HTML_NeedsPaint_t_index);
	add_func(L, "__newindex", HTML_NeedsPaint_t_newindex);
	HTML_NeedsPaint_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// HTML_StartRequest_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", HTML_StartRequest_t_index);
	add_func(L, "__newindex", HTML_StartRequest_t_newindex);
	HTML_StartRequest_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// HTML_CloseBrowser_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", HTML_CloseBrowser_t_index);
	add_func(L, "__newindex", HTML_CloseBrowser_t_newindex);
	HTML_CloseBrowser_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// HTML_URLChanged_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", HTML_URLChanged_t_index);
	add_func(L, "__newindex", HTML_URLChanged_t_newindex);
	HTML_URLChanged_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// HTML_FinishedRequest_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", HTML_FinishedRequest_t_index);
	add_func(L, "__newindex", HTML_FinishedRequest_t_newindex);
	HTML_FinishedRequest_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// HTML_OpenLinkInNewTab_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", HTML_OpenLinkInNewTab_t_index);
	add_func(L, "__newindex", HTML_OpenLinkInNewTab_t_newindex);
	HTML_OpenLinkInNewTab_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// HTML_ChangedTitle_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", HTML_ChangedTitle_t_index);
	add_func(L, "__newindex", HTML_ChangedTitle_t_newindex);
	HTML_ChangedTitle_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// HTML_SearchResults_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", HTML_SearchResults_t_index);
	add_func(L, "__newindex", HTML_SearchResults_t_newindex);
	HTML_SearchResults_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// HTML_CanGoBackAndForward_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", HTML_CanGoBackAndForward_t_index);
	add_func(L, "__newindex", HTML_CanGoBackAndForward_t_newindex);
	HTML_CanGoBackAndForward_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// HTML_HorizontalScroll_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", HTML_HorizontalScroll_t_index);
	add_func(L, "__newindex", HTML_HorizontalScroll_t_newindex);
	HTML_HorizontalScroll_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// HTML_VerticalScroll_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", HTML_VerticalScroll_t_index);
	add_func(L, "__newindex", HTML_VerticalScroll_t_newindex);
	HTML_VerticalScroll_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// HTML_LinkAtPosition_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", HTML_LinkAtPosition_t_index);
	add_func(L, "__newindex", HTML_LinkAtPosition_t_newindex);
	HTML_LinkAtPosition_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// HTML_JSAlert_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", HTML_JSAlert_t_index);
	add_func(L, "__newindex", HTML_JSAlert_t_newindex);
	HTML_JSAlert_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// HTML_JSConfirm_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", HTML_JSConfirm_t_index);
	add_func(L, "__newindex", HTML_JSConfirm_t_newindex);
	HTML_JSConfirm_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// HTML_FileOpenDialog_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", HTML_FileOpenDialog_t_index);
	add_func(L, "__newindex", HTML_FileOpenDialog_t_newindex);
	HTML_FileOpenDialog_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// HTML_NewWindow_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", HTML_NewWindow_t_index);
	add_func(L, "__newindex", HTML_NewWindow_t_newindex);
	HTML_NewWindow_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// HTML_SetCursor_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", HTML_SetCursor_t_index);
	add_func(L, "__newindex", HTML_SetCursor_t_newindex);
	HTML_SetCursor_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// HTML_StatusText_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", HTML_StatusText_t_index);
	add_func(L, "__newindex", HTML_StatusText_t_newindex);
	HTML_StatusText_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// HTML_ShowToolTip_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", HTML_ShowToolTip_t_index);
	add_func(L, "__newindex", HTML_ShowToolTip_t_newindex);
	HTML_ShowToolTip_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// HTML_UpdateToolTip_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", HTML_UpdateToolTip_t_index);
	add_func(L, "__newindex", HTML_UpdateToolTip_t_newindex);
	HTML_UpdateToolTip_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// HTML_HideToolTip_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", HTML_HideToolTip_t_index);
	add_func(L, "__newindex", HTML_HideToolTip_t_newindex);
	HTML_HideToolTip_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// HTML_BrowserRestarted_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", HTML_BrowserRestarted_t_index);
	add_func(L, "__newindex", HTML_BrowserRestarted_t_newindex);
	HTML_BrowserRestarted_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamInventoryResultReady_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamInventoryResultReady_t_index);
	add_func(L, "__newindex", SteamInventoryResultReady_t_newindex);
	SteamInventoryResultReady_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamInventoryFullUpdate_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamInventoryFullUpdate_t_index);
	add_func(L, "__newindex", SteamInventoryFullUpdate_t_newindex);
	SteamInventoryFullUpdate_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamInventoryDefinitionUpdate_t metatable
	lua_createtable(L, 0, 1);
	add_func(L, "__index", SteamInventoryDefinitionUpdate_t_index);
	SteamInventoryDefinitionUpdate_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamInventoryEligiblePromoItemDefIDs_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamInventoryEligiblePromoItemDefIDs_t_index);
	add_func(L, "__newindex", SteamInventoryEligiblePromoItemDefIDs_t_newindex);
	SteamInventoryEligiblePromoItemDefIDs_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamInventoryStartPurchaseResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamInventoryStartPurchaseResult_t_index);
	add_func(L, "__newindex", SteamInventoryStartPurchaseResult_t_newindex);
	SteamInventoryStartPurchaseResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamInventoryRequestPricesResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamInventoryRequestPricesResult_t_index);
	add_func(L, "__newindex", SteamInventoryRequestPricesResult_t_newindex);
	SteamInventoryRequestPricesResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamTimelineGamePhaseRecordingExists_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamTimelineGamePhaseRecordingExists_t_index);
	add_func(L, "__newindex", SteamTimelineGamePhaseRecordingExists_t_newindex);
	SteamTimelineGamePhaseRecordingExists_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamTimelineEventRecordingExists_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamTimelineEventRecordingExists_t_index);
	add_func(L, "__newindex", SteamTimelineEventRecordingExists_t_newindex);
	SteamTimelineEventRecordingExists_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// GetVideoURLResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", GetVideoURLResult_t_index);
	add_func(L, "__newindex", GetVideoURLResult_t_newindex);
	GetVideoURLResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// GetOPFSettingsResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", GetOPFSettingsResult_t_index);
	add_func(L, "__newindex", GetOPFSettingsResult_t_newindex);
	GetOPFSettingsResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// BroadcastUploadStart_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", BroadcastUploadStart_t_index);
	add_func(L, "__newindex", BroadcastUploadStart_t_newindex);
	BroadcastUploadStart_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// BroadcastUploadStop_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", BroadcastUploadStop_t_index);
	add_func(L, "__newindex", BroadcastUploadStop_t_newindex);
	BroadcastUploadStop_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamParentalSettingsChanged_t metatable
	lua_createtable(L, 0, 1);
	add_func(L, "__index", SteamParentalSettingsChanged_t_index);
	SteamParentalSettingsChanged_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamRemotePlaySessionConnected_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamRemotePlaySessionConnected_t_index);
	add_func(L, "__newindex", SteamRemotePlaySessionConnected_t_newindex);
	SteamRemotePlaySessionConnected_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamRemotePlaySessionDisconnected_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamRemotePlaySessionDisconnected_t_index);
	add_func(L, "__newindex", SteamRemotePlaySessionDisconnected_t_newindex);
	SteamRemotePlaySessionDisconnected_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamRemotePlayTogetherGuestInvite_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamRemotePlayTogetherGuestInvite_t_index);
	add_func(L, "__newindex", SteamRemotePlayTogetherGuestInvite_t_newindex);
	SteamRemotePlayTogetherGuestInvite_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamNetworkingMessagesSessionRequest_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamNetworkingMessagesSessionRequest_t_index);
	add_func(L, "__newindex", SteamNetworkingMessagesSessionRequest_t_newindex);
	SteamNetworkingMessagesSessionRequest_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamNetworkingMessagesSessionFailed_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamNetworkingMessagesSessionFailed_t_index);
	add_func(L, "__newindex", SteamNetworkingMessagesSessionFailed_t_newindex);
	SteamNetworkingMessagesSessionFailed_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamNetConnectionStatusChangedCallback_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamNetConnectionStatusChangedCallback_t_index);
	add_func(L, "__newindex", SteamNetConnectionStatusChangedCallback_t_newindex);
	SteamNetConnectionStatusChangedCallback_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamNetAuthenticationStatus_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamNetAuthenticationStatus_t_index);
	add_func(L, "__newindex", SteamNetAuthenticationStatus_t_newindex);
	SteamNetAuthenticationStatus_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamRelayNetworkStatus_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamRelayNetworkStatus_t_index);
	add_func(L, "__newindex", SteamRelayNetworkStatus_t_newindex);
	SteamRelayNetworkStatus_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// GSClientApprove_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", GSClientApprove_t_index);
	add_func(L, "__newindex", GSClientApprove_t_newindex);
	GSClientApprove_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// GSClientDeny_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", GSClientDeny_t_index);
	add_func(L, "__newindex", GSClientDeny_t_newindex);
	GSClientDeny_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// GSClientKick_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", GSClientKick_t_index);
	add_func(L, "__newindex", GSClientKick_t_newindex);
	GSClientKick_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// GSClientAchievementStatus_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", GSClientAchievementStatus_t_index);
	add_func(L, "__newindex", GSClientAchievementStatus_t_newindex);
	GSClientAchievementStatus_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// GSPolicyResponse_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", GSPolicyResponse_t_index);
	add_func(L, "__newindex", GSPolicyResponse_t_newindex);
	GSPolicyResponse_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// GSGameplayStats_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", GSGameplayStats_t_index);
	add_func(L, "__newindex", GSGameplayStats_t_newindex);
	GSGameplayStats_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// GSClientGroupStatus_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", GSClientGroupStatus_t_index);
	add_func(L, "__newindex", GSClientGroupStatus_t_newindex);
	GSClientGroupStatus_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// GSReputation_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", GSReputation_t_index);
	add_func(L, "__newindex", GSReputation_t_newindex);
	GSReputation_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// AssociateWithClanResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", AssociateWithClanResult_t_index);
	add_func(L, "__newindex", AssociateWithClanResult_t_newindex);
	AssociateWithClanResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// ComputeNewPlayerCompatibilityResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", ComputeNewPlayerCompatibilityResult_t_index);
	add_func(L, "__newindex", ComputeNewPlayerCompatibilityResult_t_newindex);
	ComputeNewPlayerCompatibilityResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// GSStatsReceived_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", GSStatsReceived_t_index);
	add_func(L, "__newindex", GSStatsReceived_t_newindex);
	GSStatsReceived_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// GSStatsStored_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", GSStatsStored_t_index);
	add_func(L, "__newindex", GSStatsStored_t_newindex);
	GSStatsStored_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// GSStatsUnloaded_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", GSStatsUnloaded_t_index);
	add_func(L, "__newindex", GSStatsUnloaded_t_newindex);
	GSStatsUnloaded_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	// SteamNetworkingFakeIPResult_t metatable
	lua_createtable(L, 0, 2);
	add_func(L, "__index", SteamNetworkingFakeIPResult_t_index);
	add_func(L, "__newindex", SteamNetworkingFakeIPResult_t_newindex);
	SteamNetworkingFakeIPResult_tMetatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);
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
	luaL_unref(L, LUA_REGISTRYINDEX, SteamServersConnected_tMetatable_ref);
	SteamServersConnected_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamServerConnectFailure_tMetatable_ref);
	SteamServerConnectFailure_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamServersDisconnected_tMetatable_ref);
	SteamServersDisconnected_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, ClientGameServerDeny_tMetatable_ref);
	ClientGameServerDeny_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, IPCFailure_tMetatable_ref);
	IPCFailure_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, LicensesUpdated_tMetatable_ref);
	LicensesUpdated_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, ValidateAuthTicketResponse_tMetatable_ref);
	ValidateAuthTicketResponse_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, MicroTxnAuthorizationResponse_tMetatable_ref);
	MicroTxnAuthorizationResponse_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, EncryptedAppTicketResponse_tMetatable_ref);
	EncryptedAppTicketResponse_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, GetAuthSessionTicketResponse_tMetatable_ref);
	GetAuthSessionTicketResponse_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, GameWebCallback_tMetatable_ref);
	GameWebCallback_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, StoreAuthURLResponse_tMetatable_ref);
	StoreAuthURLResponse_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, MarketEligibilityResponse_tMetatable_ref);
	MarketEligibilityResponse_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, DurationControl_tMetatable_ref);
	DurationControl_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, GetTicketForWebApiResponse_tMetatable_ref);
	GetTicketForWebApiResponse_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, PersonaStateChange_tMetatable_ref);
	PersonaStateChange_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, GameOverlayActivated_tMetatable_ref);
	GameOverlayActivated_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, GameServerChangeRequested_tMetatable_ref);
	GameServerChangeRequested_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, GameLobbyJoinRequested_tMetatable_ref);
	GameLobbyJoinRequested_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, AvatarImageLoaded_tMetatable_ref);
	AvatarImageLoaded_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, ClanOfficerListResponse_tMetatable_ref);
	ClanOfficerListResponse_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, FriendRichPresenceUpdate_tMetatable_ref);
	FriendRichPresenceUpdate_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, GameRichPresenceJoinRequested_tMetatable_ref);
	GameRichPresenceJoinRequested_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, GameConnectedClanChatMsg_tMetatable_ref);
	GameConnectedClanChatMsg_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, GameConnectedChatJoin_tMetatable_ref);
	GameConnectedChatJoin_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, GameConnectedChatLeave_tMetatable_ref);
	GameConnectedChatLeave_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, DownloadClanActivityCountsResult_tMetatable_ref);
	DownloadClanActivityCountsResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, JoinClanChatRoomCompletionResult_tMetatable_ref);
	JoinClanChatRoomCompletionResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, GameConnectedFriendChatMsg_tMetatable_ref);
	GameConnectedFriendChatMsg_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, FriendsGetFollowerCount_tMetatable_ref);
	FriendsGetFollowerCount_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, FriendsIsFollowing_tMetatable_ref);
	FriendsIsFollowing_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, FriendsEnumerateFollowingList_tMetatable_ref);
	FriendsEnumerateFollowingList_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, UnreadChatMessagesChanged_tMetatable_ref);
	UnreadChatMessagesChanged_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, OverlayBrowserProtocolNavigation_tMetatable_ref);
	OverlayBrowserProtocolNavigation_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, EquippedProfileItemsChanged_tMetatable_ref);
	EquippedProfileItemsChanged_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, EquippedProfileItems_tMetatable_ref);
	EquippedProfileItems_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, IPCountry_tMetatable_ref);
	IPCountry_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, LowBatteryPower_tMetatable_ref);
	LowBatteryPower_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamAPICallCompleted_tMetatable_ref);
	SteamAPICallCompleted_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamShutdown_tMetatable_ref);
	SteamShutdown_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, CheckFileSignature_tMetatable_ref);
	CheckFileSignature_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, GamepadTextInputDismissed_tMetatable_ref);
	GamepadTextInputDismissed_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, AppResumingFromSuspend_tMetatable_ref);
	AppResumingFromSuspend_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, FloatingGamepadTextInputDismissed_tMetatable_ref);
	FloatingGamepadTextInputDismissed_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, FilterTextDictionaryChanged_tMetatable_ref);
	FilterTextDictionaryChanged_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, FavoritesListChanged_tMetatable_ref);
	FavoritesListChanged_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, LobbyInvite_tMetatable_ref);
	LobbyInvite_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, LobbyEnter_tMetatable_ref);
	LobbyEnter_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, LobbyDataUpdate_tMetatable_ref);
	LobbyDataUpdate_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, LobbyChatUpdate_tMetatable_ref);
	LobbyChatUpdate_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, LobbyChatMsg_tMetatable_ref);
	LobbyChatMsg_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, LobbyGameCreated_tMetatable_ref);
	LobbyGameCreated_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, LobbyMatchList_tMetatable_ref);
	LobbyMatchList_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, LobbyKicked_tMetatable_ref);
	LobbyKicked_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, LobbyCreated_tMetatable_ref);
	LobbyCreated_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, FavoritesListAccountsUpdated_tMetatable_ref);
	FavoritesListAccountsUpdated_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, JoinPartyCallback_tMetatable_ref);
	JoinPartyCallback_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, CreateBeaconCallback_tMetatable_ref);
	CreateBeaconCallback_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, ReservationNotificationCallback_tMetatable_ref);
	ReservationNotificationCallback_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, ChangeNumOpenSlotsCallback_tMetatable_ref);
	ChangeNumOpenSlotsCallback_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, AvailableBeaconLocationsUpdated_tMetatable_ref);
	AvailableBeaconLocationsUpdated_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, ActiveBeaconsUpdated_tMetatable_ref);
	ActiveBeaconsUpdated_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemoteStorageFileShareResult_tMetatable_ref);
	RemoteStorageFileShareResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemoteStoragePublishFileResult_tMetatable_ref);
	RemoteStoragePublishFileResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemoteStorageDeletePublishedFileResult_tMetatable_ref);
	RemoteStorageDeletePublishedFileResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemoteStorageEnumerateUserPublishedFilesResult_tMetatable_ref);
	RemoteStorageEnumerateUserPublishedFilesResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemoteStorageSubscribePublishedFileResult_tMetatable_ref);
	RemoteStorageSubscribePublishedFileResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemoteStorageEnumerateUserSubscribedFilesResult_tMetatable_ref);
	RemoteStorageEnumerateUserSubscribedFilesResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemoteStorageUnsubscribePublishedFileResult_tMetatable_ref);
	RemoteStorageUnsubscribePublishedFileResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemoteStorageUpdatePublishedFileResult_tMetatable_ref);
	RemoteStorageUpdatePublishedFileResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemoteStorageDownloadUGCResult_tMetatable_ref);
	RemoteStorageDownloadUGCResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemoteStorageGetPublishedFileDetailsResult_tMetatable_ref);
	RemoteStorageGetPublishedFileDetailsResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemoteStorageEnumerateWorkshopFilesResult_tMetatable_ref);
	RemoteStorageEnumerateWorkshopFilesResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemoteStorageGetPublishedItemVoteDetailsResult_tMetatable_ref);
	RemoteStorageGetPublishedItemVoteDetailsResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemoteStoragePublishedFileSubscribed_tMetatable_ref);
	RemoteStoragePublishedFileSubscribed_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemoteStoragePublishedFileUnsubscribed_tMetatable_ref);
	RemoteStoragePublishedFileUnsubscribed_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemoteStoragePublishedFileDeleted_tMetatable_ref);
	RemoteStoragePublishedFileDeleted_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemoteStorageUpdateUserPublishedItemVoteResult_tMetatable_ref);
	RemoteStorageUpdateUserPublishedItemVoteResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemoteStorageUserVoteDetails_tMetatable_ref);
	RemoteStorageUserVoteDetails_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemoteStorageEnumerateUserSharedWorkshopFilesResult_tMetatable_ref);
	RemoteStorageEnumerateUserSharedWorkshopFilesResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemoteStorageSetUserPublishedFileActionResult_tMetatable_ref);
	RemoteStorageSetUserPublishedFileActionResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemoteStorageEnumeratePublishedFilesByUserActionResult_tMetatable_ref);
	RemoteStorageEnumeratePublishedFilesByUserActionResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemoteStoragePublishFileProgress_tMetatable_ref);
	RemoteStoragePublishFileProgress_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemoteStoragePublishedFileUpdated_tMetatable_ref);
	RemoteStoragePublishedFileUpdated_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemoteStorageFileWriteAsyncComplete_tMetatable_ref);
	RemoteStorageFileWriteAsyncComplete_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemoteStorageFileReadAsyncComplete_tMetatable_ref);
	RemoteStorageFileReadAsyncComplete_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemoteStorageLocalFileChange_tMetatable_ref);
	RemoteStorageLocalFileChange_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, UserStatsReceived_tMetatable_ref);
	UserStatsReceived_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, UserStatsStored_tMetatable_ref);
	UserStatsStored_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, UserAchievementStored_tMetatable_ref);
	UserAchievementStored_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, LeaderboardFindResult_tMetatable_ref);
	LeaderboardFindResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, LeaderboardScoresDownloaded_tMetatable_ref);
	LeaderboardScoresDownloaded_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, LeaderboardScoreUploaded_tMetatable_ref);
	LeaderboardScoreUploaded_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, NumberOfCurrentPlayers_tMetatable_ref);
	NumberOfCurrentPlayers_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, UserStatsUnloaded_tMetatable_ref);
	UserStatsUnloaded_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, UserAchievementIconFetched_tMetatable_ref);
	UserAchievementIconFetched_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, GlobalAchievementPercentagesReady_tMetatable_ref);
	GlobalAchievementPercentagesReady_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, LeaderboardUGCSet_tMetatable_ref);
	LeaderboardUGCSet_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, GlobalStatsReceived_tMetatable_ref);
	GlobalStatsReceived_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, DlcInstalled_tMetatable_ref);
	DlcInstalled_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, NewUrlLaunchParameters_tMetatable_ref);
	NewUrlLaunchParameters_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, AppProofOfPurchaseKeyResponse_tMetatable_ref);
	AppProofOfPurchaseKeyResponse_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, FileDetailsResult_tMetatable_ref);
	FileDetailsResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, TimedTrialStatus_tMetatable_ref);
	TimedTrialStatus_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, P2PSessionRequest_tMetatable_ref);
	P2PSessionRequest_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, P2PSessionConnectFail_tMetatable_ref);
	P2PSessionConnectFail_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SocketStatusCallback_tMetatable_ref);
	SocketStatusCallback_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, ScreenshotReady_tMetatable_ref);
	ScreenshotReady_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, ScreenshotRequested_tMetatable_ref);
	ScreenshotRequested_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, PlaybackStatusHasChanged_tMetatable_ref);
	PlaybackStatusHasChanged_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, VolumeHasChanged_tMetatable_ref);
	VolumeHasChanged_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, HTTPRequestCompleted_tMetatable_ref);
	HTTPRequestCompleted_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, HTTPRequestHeadersReceived_tMetatable_ref);
	HTTPRequestHeadersReceived_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, HTTPRequestDataReceived_tMetatable_ref);
	HTTPRequestDataReceived_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamInputDeviceConnected_tMetatable_ref);
	SteamInputDeviceConnected_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamInputDeviceDisconnected_tMetatable_ref);
	SteamInputDeviceDisconnected_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamInputConfigurationLoaded_tMetatable_ref);
	SteamInputConfigurationLoaded_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamInputGamepadSlotChange_tMetatable_ref);
	SteamInputGamepadSlotChange_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamUGCQueryCompleted_tMetatable_ref);
	SteamUGCQueryCompleted_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamUGCRequestUGCDetailsResult_tMetatable_ref);
	SteamUGCRequestUGCDetailsResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, CreateItemResult_tMetatable_ref);
	CreateItemResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SubmitItemUpdateResult_tMetatable_ref);
	SubmitItemUpdateResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, ItemInstalled_tMetatable_ref);
	ItemInstalled_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, DownloadItemResult_tMetatable_ref);
	DownloadItemResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, UserFavoriteItemsListChanged_tMetatable_ref);
	UserFavoriteItemsListChanged_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SetUserItemVoteResult_tMetatable_ref);
	SetUserItemVoteResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, GetUserItemVoteResult_tMetatable_ref);
	GetUserItemVoteResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, StartPlaytimeTrackingResult_tMetatable_ref);
	StartPlaytimeTrackingResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, StopPlaytimeTrackingResult_tMetatable_ref);
	StopPlaytimeTrackingResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, AddUGCDependencyResult_tMetatable_ref);
	AddUGCDependencyResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemoveUGCDependencyResult_tMetatable_ref);
	RemoveUGCDependencyResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, AddAppDependencyResult_tMetatable_ref);
	AddAppDependencyResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, RemoveAppDependencyResult_tMetatable_ref);
	RemoveAppDependencyResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, GetAppDependenciesResult_tMetatable_ref);
	GetAppDependenciesResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, DeleteItemResult_tMetatable_ref);
	DeleteItemResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, UserSubscribedItemsListChanged_tMetatable_ref);
	UserSubscribedItemsListChanged_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, WorkshopEULAStatus_tMetatable_ref);
	WorkshopEULAStatus_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, HTML_BrowserReady_tMetatable_ref);
	HTML_BrowserReady_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, HTML_NeedsPaint_tMetatable_ref);
	HTML_NeedsPaint_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, HTML_StartRequest_tMetatable_ref);
	HTML_StartRequest_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, HTML_CloseBrowser_tMetatable_ref);
	HTML_CloseBrowser_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, HTML_URLChanged_tMetatable_ref);
	HTML_URLChanged_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, HTML_FinishedRequest_tMetatable_ref);
	HTML_FinishedRequest_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, HTML_OpenLinkInNewTab_tMetatable_ref);
	HTML_OpenLinkInNewTab_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, HTML_ChangedTitle_tMetatable_ref);
	HTML_ChangedTitle_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, HTML_SearchResults_tMetatable_ref);
	HTML_SearchResults_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, HTML_CanGoBackAndForward_tMetatable_ref);
	HTML_CanGoBackAndForward_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, HTML_HorizontalScroll_tMetatable_ref);
	HTML_HorizontalScroll_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, HTML_VerticalScroll_tMetatable_ref);
	HTML_VerticalScroll_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, HTML_LinkAtPosition_tMetatable_ref);
	HTML_LinkAtPosition_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, HTML_JSAlert_tMetatable_ref);
	HTML_JSAlert_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, HTML_JSConfirm_tMetatable_ref);
	HTML_JSConfirm_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, HTML_FileOpenDialog_tMetatable_ref);
	HTML_FileOpenDialog_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, HTML_NewWindow_tMetatable_ref);
	HTML_NewWindow_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, HTML_SetCursor_tMetatable_ref);
	HTML_SetCursor_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, HTML_StatusText_tMetatable_ref);
	HTML_StatusText_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, HTML_ShowToolTip_tMetatable_ref);
	HTML_ShowToolTip_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, HTML_UpdateToolTip_tMetatable_ref);
	HTML_UpdateToolTip_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, HTML_HideToolTip_tMetatable_ref);
	HTML_HideToolTip_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, HTML_BrowserRestarted_tMetatable_ref);
	HTML_BrowserRestarted_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamInventoryResultReady_tMetatable_ref);
	SteamInventoryResultReady_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamInventoryFullUpdate_tMetatable_ref);
	SteamInventoryFullUpdate_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamInventoryDefinitionUpdate_tMetatable_ref);
	SteamInventoryDefinitionUpdate_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamInventoryEligiblePromoItemDefIDs_tMetatable_ref);
	SteamInventoryEligiblePromoItemDefIDs_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamInventoryStartPurchaseResult_tMetatable_ref);
	SteamInventoryStartPurchaseResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamInventoryRequestPricesResult_tMetatable_ref);
	SteamInventoryRequestPricesResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamTimelineGamePhaseRecordingExists_tMetatable_ref);
	SteamTimelineGamePhaseRecordingExists_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamTimelineEventRecordingExists_tMetatable_ref);
	SteamTimelineEventRecordingExists_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, GetVideoURLResult_tMetatable_ref);
	GetVideoURLResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, GetOPFSettingsResult_tMetatable_ref);
	GetOPFSettingsResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, BroadcastUploadStart_tMetatable_ref);
	BroadcastUploadStart_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, BroadcastUploadStop_tMetatable_ref);
	BroadcastUploadStop_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamParentalSettingsChanged_tMetatable_ref);
	SteamParentalSettingsChanged_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamRemotePlaySessionConnected_tMetatable_ref);
	SteamRemotePlaySessionConnected_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamRemotePlaySessionDisconnected_tMetatable_ref);
	SteamRemotePlaySessionDisconnected_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamRemotePlayTogetherGuestInvite_tMetatable_ref);
	SteamRemotePlayTogetherGuestInvite_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamNetworkingMessagesSessionRequest_tMetatable_ref);
	SteamNetworkingMessagesSessionRequest_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamNetworkingMessagesSessionFailed_tMetatable_ref);
	SteamNetworkingMessagesSessionFailed_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamNetConnectionStatusChangedCallback_tMetatable_ref);
	SteamNetConnectionStatusChangedCallback_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamNetAuthenticationStatus_tMetatable_ref);
	SteamNetAuthenticationStatus_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamRelayNetworkStatus_tMetatable_ref);
	SteamRelayNetworkStatus_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, GSClientApprove_tMetatable_ref);
	GSClientApprove_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, GSClientDeny_tMetatable_ref);
	GSClientDeny_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, GSClientKick_tMetatable_ref);
	GSClientKick_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, GSClientAchievementStatus_tMetatable_ref);
	GSClientAchievementStatus_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, GSPolicyResponse_tMetatable_ref);
	GSPolicyResponse_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, GSGameplayStats_tMetatable_ref);
	GSGameplayStats_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, GSClientGroupStatus_tMetatable_ref);
	GSClientGroupStatus_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, GSReputation_tMetatable_ref);
	GSReputation_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, AssociateWithClanResult_tMetatable_ref);
	AssociateWithClanResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, ComputeNewPlayerCompatibilityResult_tMetatable_ref);
	ComputeNewPlayerCompatibilityResult_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, GSStatsReceived_tMetatable_ref);
	GSStatsReceived_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, GSStatsStored_tMetatable_ref);
	GSStatsStored_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, GSStatsUnloaded_tMetatable_ref);
	GSStatsUnloaded_tMetatable_ref = LUA_NOREF;
	luaL_unref(L, LUA_REGISTRYINDEX, SteamNetworkingFakeIPResult_tMetatable_ref);
	SteamNetworkingFakeIPResult_tMetatable_ref = LUA_NOREF;
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
	add_func(L, "newSteamServersConnected_t", luasteam_newSteamServersConnected_t);
	add_func(L, "newSteamServerConnectFailure_t", luasteam_newSteamServerConnectFailure_t);
	add_func(L, "newSteamServersDisconnected_t", luasteam_newSteamServersDisconnected_t);
	add_func(L, "newClientGameServerDeny_t", luasteam_newClientGameServerDeny_t);
	add_func(L, "newIPCFailure_t", luasteam_newIPCFailure_t);
	add_func(L, "newLicensesUpdated_t", luasteam_newLicensesUpdated_t);
	add_func(L, "newValidateAuthTicketResponse_t", luasteam_newValidateAuthTicketResponse_t);
	add_func(L, "newMicroTxnAuthorizationResponse_t", luasteam_newMicroTxnAuthorizationResponse_t);
	add_func(L, "newEncryptedAppTicketResponse_t", luasteam_newEncryptedAppTicketResponse_t);
	add_func(L, "newGetAuthSessionTicketResponse_t", luasteam_newGetAuthSessionTicketResponse_t);
	add_func(L, "newGameWebCallback_t", luasteam_newGameWebCallback_t);
	add_func(L, "newStoreAuthURLResponse_t", luasteam_newStoreAuthURLResponse_t);
	add_func(L, "newMarketEligibilityResponse_t", luasteam_newMarketEligibilityResponse_t);
	add_func(L, "newDurationControl_t", luasteam_newDurationControl_t);
	add_func(L, "newGetTicketForWebApiResponse_t", luasteam_newGetTicketForWebApiResponse_t);
	add_func(L, "newPersonaStateChange_t", luasteam_newPersonaStateChange_t);
	add_func(L, "newGameOverlayActivated_t", luasteam_newGameOverlayActivated_t);
	add_func(L, "newGameServerChangeRequested_t", luasteam_newGameServerChangeRequested_t);
	add_func(L, "newGameLobbyJoinRequested_t", luasteam_newGameLobbyJoinRequested_t);
	add_func(L, "newAvatarImageLoaded_t", luasteam_newAvatarImageLoaded_t);
	add_func(L, "newClanOfficerListResponse_t", luasteam_newClanOfficerListResponse_t);
	add_func(L, "newFriendRichPresenceUpdate_t", luasteam_newFriendRichPresenceUpdate_t);
	add_func(L, "newGameRichPresenceJoinRequested_t", luasteam_newGameRichPresenceJoinRequested_t);
	add_func(L, "newGameConnectedClanChatMsg_t", luasteam_newGameConnectedClanChatMsg_t);
	add_func(L, "newGameConnectedChatJoin_t", luasteam_newGameConnectedChatJoin_t);
	add_func(L, "newGameConnectedChatLeave_t", luasteam_newGameConnectedChatLeave_t);
	add_func(L, "newDownloadClanActivityCountsResult_t", luasteam_newDownloadClanActivityCountsResult_t);
	add_func(L, "newJoinClanChatRoomCompletionResult_t", luasteam_newJoinClanChatRoomCompletionResult_t);
	add_func(L, "newGameConnectedFriendChatMsg_t", luasteam_newGameConnectedFriendChatMsg_t);
	add_func(L, "newFriendsGetFollowerCount_t", luasteam_newFriendsGetFollowerCount_t);
	add_func(L, "newFriendsIsFollowing_t", luasteam_newFriendsIsFollowing_t);
	add_func(L, "newFriendsEnumerateFollowingList_t", luasteam_newFriendsEnumerateFollowingList_t);
	add_func(L, "newUnreadChatMessagesChanged_t", luasteam_newUnreadChatMessagesChanged_t);
	add_func(L, "newOverlayBrowserProtocolNavigation_t", luasteam_newOverlayBrowserProtocolNavigation_t);
	add_func(L, "newEquippedProfileItemsChanged_t", luasteam_newEquippedProfileItemsChanged_t);
	add_func(L, "newEquippedProfileItems_t", luasteam_newEquippedProfileItems_t);
	add_func(L, "newIPCountry_t", luasteam_newIPCountry_t);
	add_func(L, "newLowBatteryPower_t", luasteam_newLowBatteryPower_t);
	add_func(L, "newSteamAPICallCompleted_t", luasteam_newSteamAPICallCompleted_t);
	add_func(L, "newSteamShutdown_t", luasteam_newSteamShutdown_t);
	add_func(L, "newCheckFileSignature_t", luasteam_newCheckFileSignature_t);
	add_func(L, "newGamepadTextInputDismissed_t", luasteam_newGamepadTextInputDismissed_t);
	add_func(L, "newAppResumingFromSuspend_t", luasteam_newAppResumingFromSuspend_t);
	add_func(L, "newFloatingGamepadTextInputDismissed_t", luasteam_newFloatingGamepadTextInputDismissed_t);
	add_func(L, "newFilterTextDictionaryChanged_t", luasteam_newFilterTextDictionaryChanged_t);
	add_func(L, "newFavoritesListChanged_t", luasteam_newFavoritesListChanged_t);
	add_func(L, "newLobbyInvite_t", luasteam_newLobbyInvite_t);
	add_func(L, "newLobbyEnter_t", luasteam_newLobbyEnter_t);
	add_func(L, "newLobbyDataUpdate_t", luasteam_newLobbyDataUpdate_t);
	add_func(L, "newLobbyChatUpdate_t", luasteam_newLobbyChatUpdate_t);
	add_func(L, "newLobbyChatMsg_t", luasteam_newLobbyChatMsg_t);
	add_func(L, "newLobbyGameCreated_t", luasteam_newLobbyGameCreated_t);
	add_func(L, "newLobbyMatchList_t", luasteam_newLobbyMatchList_t);
	add_func(L, "newLobbyKicked_t", luasteam_newLobbyKicked_t);
	add_func(L, "newLobbyCreated_t", luasteam_newLobbyCreated_t);
	add_func(L, "newFavoritesListAccountsUpdated_t", luasteam_newFavoritesListAccountsUpdated_t);
	add_func(L, "newJoinPartyCallback_t", luasteam_newJoinPartyCallback_t);
	add_func(L, "newCreateBeaconCallback_t", luasteam_newCreateBeaconCallback_t);
	add_func(L, "newReservationNotificationCallback_t", luasteam_newReservationNotificationCallback_t);
	add_func(L, "newChangeNumOpenSlotsCallback_t", luasteam_newChangeNumOpenSlotsCallback_t);
	add_func(L, "newAvailableBeaconLocationsUpdated_t", luasteam_newAvailableBeaconLocationsUpdated_t);
	add_func(L, "newActiveBeaconsUpdated_t", luasteam_newActiveBeaconsUpdated_t);
	add_func(L, "newRemoteStorageFileShareResult_t", luasteam_newRemoteStorageFileShareResult_t);
	add_func(L, "newRemoteStoragePublishFileResult_t", luasteam_newRemoteStoragePublishFileResult_t);
	add_func(L, "newRemoteStorageDeletePublishedFileResult_t", luasteam_newRemoteStorageDeletePublishedFileResult_t);
	add_func(L, "newRemoteStorageEnumerateUserPublishedFilesResult_t", luasteam_newRemoteStorageEnumerateUserPublishedFilesResult_t);
	add_func(L, "newRemoteStorageSubscribePublishedFileResult_t", luasteam_newRemoteStorageSubscribePublishedFileResult_t);
	add_func(L, "newRemoteStorageEnumerateUserSubscribedFilesResult_t", luasteam_newRemoteStorageEnumerateUserSubscribedFilesResult_t);
	add_func(L, "newRemoteStorageUnsubscribePublishedFileResult_t", luasteam_newRemoteStorageUnsubscribePublishedFileResult_t);
	add_func(L, "newRemoteStorageUpdatePublishedFileResult_t", luasteam_newRemoteStorageUpdatePublishedFileResult_t);
	add_func(L, "newRemoteStorageDownloadUGCResult_t", luasteam_newRemoteStorageDownloadUGCResult_t);
	add_func(L, "newRemoteStorageGetPublishedFileDetailsResult_t", luasteam_newRemoteStorageGetPublishedFileDetailsResult_t);
	add_func(L, "newRemoteStorageEnumerateWorkshopFilesResult_t", luasteam_newRemoteStorageEnumerateWorkshopFilesResult_t);
	add_func(L, "newRemoteStorageGetPublishedItemVoteDetailsResult_t", luasteam_newRemoteStorageGetPublishedItemVoteDetailsResult_t);
	add_func(L, "newRemoteStoragePublishedFileSubscribed_t", luasteam_newRemoteStoragePublishedFileSubscribed_t);
	add_func(L, "newRemoteStoragePublishedFileUnsubscribed_t", luasteam_newRemoteStoragePublishedFileUnsubscribed_t);
	add_func(L, "newRemoteStoragePublishedFileDeleted_t", luasteam_newRemoteStoragePublishedFileDeleted_t);
	add_func(L, "newRemoteStorageUpdateUserPublishedItemVoteResult_t", luasteam_newRemoteStorageUpdateUserPublishedItemVoteResult_t);
	add_func(L, "newRemoteStorageUserVoteDetails_t", luasteam_newRemoteStorageUserVoteDetails_t);
	add_func(L, "newRemoteStorageEnumerateUserSharedWorkshopFilesResult_t", luasteam_newRemoteStorageEnumerateUserSharedWorkshopFilesResult_t);
	add_func(L, "newRemoteStorageSetUserPublishedFileActionResult_t", luasteam_newRemoteStorageSetUserPublishedFileActionResult_t);
	add_func(L, "newRemoteStorageEnumeratePublishedFilesByUserActionResult_t", luasteam_newRemoteStorageEnumeratePublishedFilesByUserActionResult_t);
	add_func(L, "newRemoteStoragePublishFileProgress_t", luasteam_newRemoteStoragePublishFileProgress_t);
	add_func(L, "newRemoteStoragePublishedFileUpdated_t", luasteam_newRemoteStoragePublishedFileUpdated_t);
	add_func(L, "newRemoteStorageFileWriteAsyncComplete_t", luasteam_newRemoteStorageFileWriteAsyncComplete_t);
	add_func(L, "newRemoteStorageFileReadAsyncComplete_t", luasteam_newRemoteStorageFileReadAsyncComplete_t);
	add_func(L, "newRemoteStorageLocalFileChange_t", luasteam_newRemoteStorageLocalFileChange_t);
	add_func(L, "newUserStatsReceived_t", luasteam_newUserStatsReceived_t);
	add_func(L, "newUserStatsStored_t", luasteam_newUserStatsStored_t);
	add_func(L, "newUserAchievementStored_t", luasteam_newUserAchievementStored_t);
	add_func(L, "newLeaderboardFindResult_t", luasteam_newLeaderboardFindResult_t);
	add_func(L, "newLeaderboardScoresDownloaded_t", luasteam_newLeaderboardScoresDownloaded_t);
	add_func(L, "newLeaderboardScoreUploaded_t", luasteam_newLeaderboardScoreUploaded_t);
	add_func(L, "newNumberOfCurrentPlayers_t", luasteam_newNumberOfCurrentPlayers_t);
	add_func(L, "newUserStatsUnloaded_t", luasteam_newUserStatsUnloaded_t);
	add_func(L, "newUserAchievementIconFetched_t", luasteam_newUserAchievementIconFetched_t);
	add_func(L, "newGlobalAchievementPercentagesReady_t", luasteam_newGlobalAchievementPercentagesReady_t);
	add_func(L, "newLeaderboardUGCSet_t", luasteam_newLeaderboardUGCSet_t);
	add_func(L, "newGlobalStatsReceived_t", luasteam_newGlobalStatsReceived_t);
	add_func(L, "newDlcInstalled_t", luasteam_newDlcInstalled_t);
	add_func(L, "newNewUrlLaunchParameters_t", luasteam_newNewUrlLaunchParameters_t);
	add_func(L, "newAppProofOfPurchaseKeyResponse_t", luasteam_newAppProofOfPurchaseKeyResponse_t);
	add_func(L, "newFileDetailsResult_t", luasteam_newFileDetailsResult_t);
	add_func(L, "newTimedTrialStatus_t", luasteam_newTimedTrialStatus_t);
	add_func(L, "newP2PSessionRequest_t", luasteam_newP2PSessionRequest_t);
	add_func(L, "newP2PSessionConnectFail_t", luasteam_newP2PSessionConnectFail_t);
	add_func(L, "newSocketStatusCallback_t", luasteam_newSocketStatusCallback_t);
	add_func(L, "newScreenshotReady_t", luasteam_newScreenshotReady_t);
	add_func(L, "newScreenshotRequested_t", luasteam_newScreenshotRequested_t);
	add_func(L, "newPlaybackStatusHasChanged_t", luasteam_newPlaybackStatusHasChanged_t);
	add_func(L, "newVolumeHasChanged_t", luasteam_newVolumeHasChanged_t);
	add_func(L, "newHTTPRequestCompleted_t", luasteam_newHTTPRequestCompleted_t);
	add_func(L, "newHTTPRequestHeadersReceived_t", luasteam_newHTTPRequestHeadersReceived_t);
	add_func(L, "newHTTPRequestDataReceived_t", luasteam_newHTTPRequestDataReceived_t);
	add_func(L, "newSteamInputDeviceConnected_t", luasteam_newSteamInputDeviceConnected_t);
	add_func(L, "newSteamInputDeviceDisconnected_t", luasteam_newSteamInputDeviceDisconnected_t);
	add_func(L, "newSteamInputConfigurationLoaded_t", luasteam_newSteamInputConfigurationLoaded_t);
	add_func(L, "newSteamInputGamepadSlotChange_t", luasteam_newSteamInputGamepadSlotChange_t);
	add_func(L, "newSteamUGCQueryCompleted_t", luasteam_newSteamUGCQueryCompleted_t);
	add_func(L, "newSteamUGCRequestUGCDetailsResult_t", luasteam_newSteamUGCRequestUGCDetailsResult_t);
	add_func(L, "newCreateItemResult_t", luasteam_newCreateItemResult_t);
	add_func(L, "newSubmitItemUpdateResult_t", luasteam_newSubmitItemUpdateResult_t);
	add_func(L, "newItemInstalled_t", luasteam_newItemInstalled_t);
	add_func(L, "newDownloadItemResult_t", luasteam_newDownloadItemResult_t);
	add_func(L, "newUserFavoriteItemsListChanged_t", luasteam_newUserFavoriteItemsListChanged_t);
	add_func(L, "newSetUserItemVoteResult_t", luasteam_newSetUserItemVoteResult_t);
	add_func(L, "newGetUserItemVoteResult_t", luasteam_newGetUserItemVoteResult_t);
	add_func(L, "newStartPlaytimeTrackingResult_t", luasteam_newStartPlaytimeTrackingResult_t);
	add_func(L, "newStopPlaytimeTrackingResult_t", luasteam_newStopPlaytimeTrackingResult_t);
	add_func(L, "newAddUGCDependencyResult_t", luasteam_newAddUGCDependencyResult_t);
	add_func(L, "newRemoveUGCDependencyResult_t", luasteam_newRemoveUGCDependencyResult_t);
	add_func(L, "newAddAppDependencyResult_t", luasteam_newAddAppDependencyResult_t);
	add_func(L, "newRemoveAppDependencyResult_t", luasteam_newRemoveAppDependencyResult_t);
	add_func(L, "newGetAppDependenciesResult_t", luasteam_newGetAppDependenciesResult_t);
	add_func(L, "newDeleteItemResult_t", luasteam_newDeleteItemResult_t);
	add_func(L, "newUserSubscribedItemsListChanged_t", luasteam_newUserSubscribedItemsListChanged_t);
	add_func(L, "newWorkshopEULAStatus_t", luasteam_newWorkshopEULAStatus_t);
	add_func(L, "newHTML_BrowserReady_t", luasteam_newHTML_BrowserReady_t);
	add_func(L, "newHTML_NeedsPaint_t", luasteam_newHTML_NeedsPaint_t);
	add_func(L, "newHTML_StartRequest_t", luasteam_newHTML_StartRequest_t);
	add_func(L, "newHTML_CloseBrowser_t", luasteam_newHTML_CloseBrowser_t);
	add_func(L, "newHTML_URLChanged_t", luasteam_newHTML_URLChanged_t);
	add_func(L, "newHTML_FinishedRequest_t", luasteam_newHTML_FinishedRequest_t);
	add_func(L, "newHTML_OpenLinkInNewTab_t", luasteam_newHTML_OpenLinkInNewTab_t);
	add_func(L, "newHTML_ChangedTitle_t", luasteam_newHTML_ChangedTitle_t);
	add_func(L, "newHTML_SearchResults_t", luasteam_newHTML_SearchResults_t);
	add_func(L, "newHTML_CanGoBackAndForward_t", luasteam_newHTML_CanGoBackAndForward_t);
	add_func(L, "newHTML_HorizontalScroll_t", luasteam_newHTML_HorizontalScroll_t);
	add_func(L, "newHTML_VerticalScroll_t", luasteam_newHTML_VerticalScroll_t);
	add_func(L, "newHTML_LinkAtPosition_t", luasteam_newHTML_LinkAtPosition_t);
	add_func(L, "newHTML_JSAlert_t", luasteam_newHTML_JSAlert_t);
	add_func(L, "newHTML_JSConfirm_t", luasteam_newHTML_JSConfirm_t);
	add_func(L, "newHTML_FileOpenDialog_t", luasteam_newHTML_FileOpenDialog_t);
	add_func(L, "newHTML_NewWindow_t", luasteam_newHTML_NewWindow_t);
	add_func(L, "newHTML_SetCursor_t", luasteam_newHTML_SetCursor_t);
	add_func(L, "newHTML_StatusText_t", luasteam_newHTML_StatusText_t);
	add_func(L, "newHTML_ShowToolTip_t", luasteam_newHTML_ShowToolTip_t);
	add_func(L, "newHTML_UpdateToolTip_t", luasteam_newHTML_UpdateToolTip_t);
	add_func(L, "newHTML_HideToolTip_t", luasteam_newHTML_HideToolTip_t);
	add_func(L, "newHTML_BrowserRestarted_t", luasteam_newHTML_BrowserRestarted_t);
	add_func(L, "newSteamInventoryResultReady_t", luasteam_newSteamInventoryResultReady_t);
	add_func(L, "newSteamInventoryFullUpdate_t", luasteam_newSteamInventoryFullUpdate_t);
	add_func(L, "newSteamInventoryDefinitionUpdate_t", luasteam_newSteamInventoryDefinitionUpdate_t);
	add_func(L, "newSteamInventoryEligiblePromoItemDefIDs_t", luasteam_newSteamInventoryEligiblePromoItemDefIDs_t);
	add_func(L, "newSteamInventoryStartPurchaseResult_t", luasteam_newSteamInventoryStartPurchaseResult_t);
	add_func(L, "newSteamInventoryRequestPricesResult_t", luasteam_newSteamInventoryRequestPricesResult_t);
	add_func(L, "newSteamTimelineGamePhaseRecordingExists_t", luasteam_newSteamTimelineGamePhaseRecordingExists_t);
	add_func(L, "newSteamTimelineEventRecordingExists_t", luasteam_newSteamTimelineEventRecordingExists_t);
	add_func(L, "newGetVideoURLResult_t", luasteam_newGetVideoURLResult_t);
	add_func(L, "newGetOPFSettingsResult_t", luasteam_newGetOPFSettingsResult_t);
	add_func(L, "newBroadcastUploadStart_t", luasteam_newBroadcastUploadStart_t);
	add_func(L, "newBroadcastUploadStop_t", luasteam_newBroadcastUploadStop_t);
	add_func(L, "newSteamParentalSettingsChanged_t", luasteam_newSteamParentalSettingsChanged_t);
	add_func(L, "newSteamRemotePlaySessionConnected_t", luasteam_newSteamRemotePlaySessionConnected_t);
	add_func(L, "newSteamRemotePlaySessionDisconnected_t", luasteam_newSteamRemotePlaySessionDisconnected_t);
	add_func(L, "newSteamRemotePlayTogetherGuestInvite_t", luasteam_newSteamRemotePlayTogetherGuestInvite_t);
	add_func(L, "newSteamNetworkingMessagesSessionRequest_t", luasteam_newSteamNetworkingMessagesSessionRequest_t);
	add_func(L, "newSteamNetworkingMessagesSessionFailed_t", luasteam_newSteamNetworkingMessagesSessionFailed_t);
	add_func(L, "newSteamNetConnectionStatusChangedCallback_t", luasteam_newSteamNetConnectionStatusChangedCallback_t);
	add_func(L, "newSteamNetAuthenticationStatus_t", luasteam_newSteamNetAuthenticationStatus_t);
	add_func(L, "newSteamRelayNetworkStatus_t", luasteam_newSteamRelayNetworkStatus_t);
	add_func(L, "newGSClientApprove_t", luasteam_newGSClientApprove_t);
	add_func(L, "newGSClientDeny_t", luasteam_newGSClientDeny_t);
	add_func(L, "newGSClientKick_t", luasteam_newGSClientKick_t);
	add_func(L, "newGSClientAchievementStatus_t", luasteam_newGSClientAchievementStatus_t);
	add_func(L, "newGSPolicyResponse_t", luasteam_newGSPolicyResponse_t);
	add_func(L, "newGSGameplayStats_t", luasteam_newGSGameplayStats_t);
	add_func(L, "newGSClientGroupStatus_t", luasteam_newGSClientGroupStatus_t);
	add_func(L, "newGSReputation_t", luasteam_newGSReputation_t);
	add_func(L, "newAssociateWithClanResult_t", luasteam_newAssociateWithClanResult_t);
	add_func(L, "newComputeNewPlayerCompatibilityResult_t", luasteam_newComputeNewPlayerCompatibilityResult_t);
	add_func(L, "newGSStatsReceived_t", luasteam_newGSStatsReceived_t);
	add_func(L, "newGSStatsStored_t", luasteam_newGSStatsStored_t);
	add_func(L, "newGSStatsUnloaded_t", luasteam_newGSStatsUnloaded_t);
	add_func(L, "newSteamNetworkingFakeIPResult_t", luasteam_newSteamNetworkingFakeIPResult_t);
}

} // namespace luasteam
