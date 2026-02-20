#include "auto.hpp"

namespace luasteam {

int Parties_ref = LUA_NOREF;

namespace {
class CallbackListener {
private:
	STEAM_CALLBACK(CallbackListener, OnJoinPartyCallback, JoinPartyCallback_t);
	STEAM_CALLBACK(CallbackListener, OnCreateBeaconCallback, CreateBeaconCallback_t);
	STEAM_CALLBACK(CallbackListener, OnReservationNotificationCallback, ReservationNotificationCallback_t);
	STEAM_CALLBACK(CallbackListener, OnChangeNumOpenSlotsCallback, ChangeNumOpenSlotsCallback_t);
	STEAM_CALLBACK(CallbackListener, OnAvailableBeaconLocationsUpdated, AvailableBeaconLocationsUpdated_t);
	STEAM_CALLBACK(CallbackListener, OnActiveBeaconsUpdated, ActiveBeaconsUpdated_t);
};
void CallbackListener::OnJoinPartyCallback(JoinPartyCallback_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Parties_ref);
	lua_getfield(L, -1, "OnJoinPartyCallback");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 4);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		luasteam::pushuint64(L, data->m_ulBeaconID);
		lua_setfield(L, -2, "m_ulBeaconID");
		luasteam::pushuint64(L, data->m_SteamIDBeaconOwner.ConvertToUint64());
		lua_setfield(L, -2, "m_SteamIDBeaconOwner");
		lua_pushstring(L, reinterpret_cast<const char*>(data->m_rgchConnectString));
		lua_setfield(L, -2, "m_rgchConnectString");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnCreateBeaconCallback(CreateBeaconCallback_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Parties_ref);
	lua_getfield(L, -1, "OnCreateBeaconCallback");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 2);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		luasteam::pushuint64(L, data->m_ulBeaconID);
		lua_setfield(L, -2, "m_ulBeaconID");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnReservationNotificationCallback(ReservationNotificationCallback_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Parties_ref);
	lua_getfield(L, -1, "OnReservationNotificationCallback");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 2);
		luasteam::pushuint64(L, data->m_ulBeaconID);
		lua_setfield(L, -2, "m_ulBeaconID");
		luasteam::pushuint64(L, data->m_steamIDJoiner.ConvertToUint64());
		lua_setfield(L, -2, "m_steamIDJoiner");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnChangeNumOpenSlotsCallback(ChangeNumOpenSlotsCallback_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Parties_ref);
	lua_getfield(L, -1, "OnChangeNumOpenSlotsCallback");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 1);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnAvailableBeaconLocationsUpdated(AvailableBeaconLocationsUpdated_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Parties_ref);
	lua_getfield(L, -1, "OnAvailableBeaconLocationsUpdated");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 0);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnActiveBeaconsUpdated(ActiveBeaconsUpdated_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Parties_ref);
	lua_getfield(L, -1, "OnActiveBeaconsUpdated");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		lua_createtable(L, 0, 0);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
CallbackListener *Parties_listener = nullptr;
} // namespace

void init_Parties_auto(lua_State *L) { Parties_listener = new CallbackListener(); }
void shutdown_Parties_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, Parties_ref);
	Parties_ref = LUA_NOREF;
	delete Parties_listener; Parties_listener = nullptr;
}

template <> void CallResultListener<ChangeNumOpenSlotsCallback_t>::Result(ChangeNumOpenSlotsCallback_t *data, bool io_fail) {
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
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<CreateBeaconCallback_t>::Result(CreateBeaconCallback_t *data, bool io_fail) {
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
		lua_createtable(L, 0, 2);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		luasteam::pushuint64(L, data->m_ulBeaconID);
		lua_setfield(L, -2, "m_ulBeaconID");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<JoinPartyCallback_t>::Result(JoinPartyCallback_t *data, bool io_fail) {
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
		lua_createtable(L, 0, 4);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		luasteam::pushuint64(L, data->m_ulBeaconID);
		lua_setfield(L, -2, "m_ulBeaconID");
		luasteam::pushuint64(L, data->m_SteamIDBeaconOwner.ConvertToUint64());
		lua_setfield(L, -2, "m_SteamIDBeaconOwner");
		lua_pushstring(L, reinterpret_cast<const char*>(data->m_rgchConnectString));
		lua_setfield(L, -2, "m_rgchConnectString");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

// uint32 GetNumActiveBeacons();
EXTERN int luasteam_Parties_GetNumActiveBeacons(lua_State *L) {
	uint32 __ret = SteamParties()->GetNumActiveBeacons();
	lua_pushinteger(L, __ret);
	return 1;
}

// PartyBeaconID_t GetBeaconByIndex(uint32 unIndex);
EXTERN int luasteam_Parties_GetBeaconByIndex(lua_State *L) {
	uint32 unIndex = static_cast<uint32>(luaL_checkint(L, 1));
	PartyBeaconID_t __ret = SteamParties()->GetBeaconByIndex(unIndex);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// bool GetBeaconDetails(PartyBeaconID_t ulBeaconID, CSteamID * pSteamIDBeaconOwner, SteamPartyBeaconLocation_t * pLocation, char * pchMetadata, int cchMetadata);
EXTERN int luasteam_Parties_GetBeaconDetails(lua_State *L) {
	PartyBeaconID_t ulBeaconID(luasteam::checkuint64(L, 1));
	CSteamID pSteamIDBeaconOwner;
	SteamPartyBeaconLocation_t pLocation;
	int cchMetadata = luaL_checkint(L, 2);
	std::vector<char> pchMetadata(cchMetadata);
	bool __ret = SteamParties()->GetBeaconDetails(ulBeaconID, &pSteamIDBeaconOwner, &pLocation, pchMetadata.data(), cchMetadata);
	lua_pushboolean(L, __ret);
	luasteam::pushuint64(L, pSteamIDBeaconOwner.ConvertToUint64());
	push_SteamPartyBeaconLocation_t(L, pLocation);
	lua_pushstring(L, reinterpret_cast<const char*>(pchMetadata.data()));
	return 3;
}

// SteamAPICall_t JoinParty(PartyBeaconID_t ulBeaconID);
EXTERN int luasteam_Parties_JoinParty(lua_State *L) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	PartyBeaconID_t ulBeaconID(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = SteamParties()->JoinParty(ulBeaconID);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<JoinPartyCallback_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<JoinPartyCallback_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// bool GetNumAvailableBeaconLocations(uint32 * puNumLocations);
EXTERN int luasteam_Parties_GetNumAvailableBeaconLocations(lua_State *L) {
	uint32 puNumLocations;
	bool __ret = SteamParties()->GetNumAvailableBeaconLocations(&puNumLocations);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, puNumLocations);
	return 2;
}

// bool GetAvailableBeaconLocations(SteamPartyBeaconLocation_t * pLocationList, uint32 uMaxNumLocations);
EXTERN int luasteam_Parties_GetAvailableBeaconLocations(lua_State *L) {
	uint32 uMaxNumLocations = luaL_checkint(L, 1);
	std::vector<SteamPartyBeaconLocation_t> pLocationList(uMaxNumLocations);
	bool __ret = SteamParties()->GetAvailableBeaconLocations(pLocationList.data(), uMaxNumLocations);
	lua_pushboolean(L, __ret);
	lua_createtable(L, uMaxNumLocations, 0);
	for(decltype(uMaxNumLocations) i=0;i<uMaxNumLocations;i++){
		push_SteamPartyBeaconLocation_t(L, pLocationList[i]);
		lua_rawseti(L, -2, i+1);
	}
	return 1;
}

// void OnReservationCompleted(PartyBeaconID_t ulBeacon, CSteamID steamIDUser);
EXTERN int luasteam_Parties_OnReservationCompleted(lua_State *L) {
	PartyBeaconID_t ulBeacon(luasteam::checkuint64(L, 1));
	CSteamID steamIDUser(luasteam::checkuint64(L, 2));
	SteamParties()->OnReservationCompleted(ulBeacon, steamIDUser);
	return 0;
}

// void CancelReservation(PartyBeaconID_t ulBeacon, CSteamID steamIDUser);
EXTERN int luasteam_Parties_CancelReservation(lua_State *L) {
	PartyBeaconID_t ulBeacon(luasteam::checkuint64(L, 1));
	CSteamID steamIDUser(luasteam::checkuint64(L, 2));
	SteamParties()->CancelReservation(ulBeacon, steamIDUser);
	return 0;
}

// SteamAPICall_t ChangeNumOpenSlots(PartyBeaconID_t ulBeacon, uint32 unOpenSlots);
EXTERN int luasteam_Parties_ChangeNumOpenSlots(lua_State *L) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	PartyBeaconID_t ulBeacon(luasteam::checkuint64(L, 1));
	uint32 unOpenSlots = static_cast<uint32>(luaL_checkint(L, 2));
	SteamAPICall_t __ret = SteamParties()->ChangeNumOpenSlots(ulBeacon, unOpenSlots);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<ChangeNumOpenSlotsCallback_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<ChangeNumOpenSlotsCallback_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// bool DestroyBeacon(PartyBeaconID_t ulBeacon);
EXTERN int luasteam_Parties_DestroyBeacon(lua_State *L) {
	PartyBeaconID_t ulBeacon(luasteam::checkuint64(L, 1));
	bool __ret = SteamParties()->DestroyBeacon(ulBeacon);
	lua_pushboolean(L, __ret);
	return 1;
}

void register_Parties_auto(lua_State *L) {
	add_func(L, "GetNumActiveBeacons", luasteam_Parties_GetNumActiveBeacons);
	add_func(L, "GetBeaconByIndex", luasteam_Parties_GetBeaconByIndex);
	add_func(L, "GetBeaconDetails", luasteam_Parties_GetBeaconDetails);
	add_func(L, "JoinParty", luasteam_Parties_JoinParty);
	add_func(L, "GetNumAvailableBeaconLocations", luasteam_Parties_GetNumAvailableBeaconLocations);
	add_func(L, "GetAvailableBeaconLocations", luasteam_Parties_GetAvailableBeaconLocations);
	add_func(L, "OnReservationCompleted", luasteam_Parties_OnReservationCompleted);
	add_func(L, "CancelReservation", luasteam_Parties_CancelReservation);
	add_func(L, "ChangeNumOpenSlots", luasteam_Parties_ChangeNumOpenSlots);
	add_func(L, "DestroyBeacon", luasteam_Parties_DestroyBeacon);
}

void add_Parties_auto(lua_State *L) {
	lua_createtable(L, 0, 10);
	register_Parties_auto(L);
	lua_pushvalue(L, -1);
	Parties_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "Parties");
}

} // namespace luasteam
