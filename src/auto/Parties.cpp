#include "auto.hpp"

namespace luasteam {

int Parties_ref = LUA_NOREF;

namespace {
class PartiesCallbackListener {
private:
	STEAM_CALLBACK(PartiesCallbackListener, OnJoinPartyCallback, JoinPartyCallback_t);
	STEAM_CALLBACK(PartiesCallbackListener, OnCreateBeaconCallback, CreateBeaconCallback_t);
	STEAM_CALLBACK(PartiesCallbackListener, OnReservationNotificationCallback, ReservationNotificationCallback_t);
	STEAM_CALLBACK(PartiesCallbackListener, OnChangeNumOpenSlotsCallback, ChangeNumOpenSlotsCallback_t);
	STEAM_CALLBACK(PartiesCallbackListener, OnAvailableBeaconLocationsUpdated, AvailableBeaconLocationsUpdated_t);
	STEAM_CALLBACK(PartiesCallbackListener, OnActiveBeaconsUpdated, ActiveBeaconsUpdated_t);
};
void PartiesCallbackListener::OnJoinPartyCallback(JoinPartyCallback_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Parties_ref);
	lua_getfield(L, -1, "OnJoinPartyCallback");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_JoinPartyCallback_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void PartiesCallbackListener::OnCreateBeaconCallback(CreateBeaconCallback_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Parties_ref);
	lua_getfield(L, -1, "OnCreateBeaconCallback");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_CreateBeaconCallback_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void PartiesCallbackListener::OnReservationNotificationCallback(ReservationNotificationCallback_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Parties_ref);
	lua_getfield(L, -1, "OnReservationNotificationCallback");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_ReservationNotificationCallback_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void PartiesCallbackListener::OnChangeNumOpenSlotsCallback(ChangeNumOpenSlotsCallback_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Parties_ref);
	lua_getfield(L, -1, "OnChangeNumOpenSlotsCallback");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_ChangeNumOpenSlotsCallback_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void PartiesCallbackListener::OnAvailableBeaconLocationsUpdated(AvailableBeaconLocationsUpdated_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Parties_ref);
	lua_getfield(L, -1, "OnAvailableBeaconLocationsUpdated");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_AvailableBeaconLocationsUpdated_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void PartiesCallbackListener::OnActiveBeaconsUpdated(ActiveBeaconsUpdated_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Parties_ref);
	lua_getfield(L, -1, "OnActiveBeaconsUpdated");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_ActiveBeaconsUpdated_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
PartiesCallbackListener *Parties_listener = nullptr;
} // namespace

void init_Parties_auto(lua_State *L) { if (Parties_listener != nullptr) return; Parties_listener = new PartiesCallbackListener(); }
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
		lua_pushlstring(L, reinterpret_cast<const char*>(data->m_rgchConnectString), 256);
		lua_setfield(L, -2, "m_rgchConnectString");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

// In C++:
// uint32 GetNumActiveBeacons();
// In Lua:
// int Parties.GetNumActiveBeacons()
static int luasteam_Parties_GetNumActiveBeacons(lua_State *L) {
	auto *iface = SteamParties();
	uint32 __ret = iface->GetNumActiveBeacons();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// PartyBeaconID_t GetBeaconByIndex(uint32 unIndex);
// In Lua:
// uint64 Parties.GetBeaconByIndex(unIndex: int)
static int luasteam_Parties_GetBeaconByIndex(lua_State *L) {
	auto *iface = SteamParties();
	uint32 unIndex = static_cast<uint32>(luaL_checkint(L, 1));
	PartyBeaconID_t __ret = iface->GetBeaconByIndex(unIndex);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// bool GetBeaconDetails(PartyBeaconID_t ulBeaconID, CSteamID * pSteamIDBeaconOwner, SteamPartyBeaconLocation_t * pLocation, char * pchMetadata, int cchMetadata);
// In Lua:
// (bool, pSteamIDBeaconOwner: uint64, pLocation: SteamPartyBeaconLocation_t, pchMetadata: str) Parties.GetBeaconDetails(ulBeaconID: uint64, cchMetadata: int)
static int luasteam_Parties_GetBeaconDetails(lua_State *L) {
	auto *iface = SteamParties();
	PartyBeaconID_t ulBeaconID(luasteam::checkuint64(L, 1));
	CSteamID pSteamIDBeaconOwner;
	SteamPartyBeaconLocation_t pLocation;
	int cchMetadata = luaL_checkint(L, 2);
	std::vector<char> pchMetadata(cchMetadata);
	bool __ret = iface->GetBeaconDetails(ulBeaconID, &pSteamIDBeaconOwner, &pLocation, pchMetadata.data(), cchMetadata);
	lua_pushboolean(L, __ret);
	luasteam::pushuint64(L, pSteamIDBeaconOwner.ConvertToUint64());
	luasteam::push_SteamPartyBeaconLocation_t(L, pLocation);
	lua_pushstring(L, reinterpret_cast<const char*>(pchMetadata.data()));
	return 4;
}

// In C++:
// SteamAPICall_t JoinParty(PartyBeaconID_t ulBeaconID);
// In Lua:
// uint64 Parties.JoinParty(ulBeaconID: uint64, callback: function)
static int luasteam_Parties_JoinParty(lua_State *L) {
	auto *iface = SteamParties();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	PartyBeaconID_t ulBeaconID(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = iface->JoinParty(ulBeaconID);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<JoinPartyCallback_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<JoinPartyCallback_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// bool GetNumAvailableBeaconLocations(uint32 * puNumLocations);
// In Lua:
// (bool, puNumLocations: int) Parties.GetNumAvailableBeaconLocations()
static int luasteam_Parties_GetNumAvailableBeaconLocations(lua_State *L) {
	auto *iface = SteamParties();
	uint32 puNumLocations;
	bool __ret = iface->GetNumAvailableBeaconLocations(&puNumLocations);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, puNumLocations);
	return 2;
}

// In C++:
// bool GetAvailableBeaconLocations(SteamPartyBeaconLocation_t * pLocationList, uint32 uMaxNumLocations);
// In Lua:
// (bool, pLocationList: SteamPartyBeaconLocation_t[]) Parties.GetAvailableBeaconLocations(uMaxNumLocations: int)
static int luasteam_Parties_GetAvailableBeaconLocations(lua_State *L) {
	auto *iface = SteamParties();
	uint32 uMaxNumLocations = luaL_checkint(L, 1);
	std::vector<SteamPartyBeaconLocation_t> pLocationList(uMaxNumLocations);
	bool __ret = iface->GetAvailableBeaconLocations(pLocationList.data(), uMaxNumLocations);
	lua_pushboolean(L, __ret);
	lua_createtable(L, uMaxNumLocations, 0);
	for(decltype(uMaxNumLocations) i = 0; i < uMaxNumLocations; i++) {
		luasteam::push_SteamPartyBeaconLocation_t(L, pLocationList[i]);
		lua_rawseti(L, -2, i+1);
	}
	return 2;
}

// In C++:
// void OnReservationCompleted(PartyBeaconID_t ulBeacon, CSteamID steamIDUser);
// In Lua:
// Parties.OnReservationCompleted(ulBeacon: uint64, steamIDUser: uint64)
static int luasteam_Parties_OnReservationCompleted(lua_State *L) {
	auto *iface = SteamParties();
	PartyBeaconID_t ulBeacon(luasteam::checkuint64(L, 1));
	CSteamID steamIDUser(luasteam::checkuint64(L, 2));
	iface->OnReservationCompleted(ulBeacon, steamIDUser);
	return 0;
}

// In C++:
// void CancelReservation(PartyBeaconID_t ulBeacon, CSteamID steamIDUser);
// In Lua:
// Parties.CancelReservation(ulBeacon: uint64, steamIDUser: uint64)
static int luasteam_Parties_CancelReservation(lua_State *L) {
	auto *iface = SteamParties();
	PartyBeaconID_t ulBeacon(luasteam::checkuint64(L, 1));
	CSteamID steamIDUser(luasteam::checkuint64(L, 2));
	iface->CancelReservation(ulBeacon, steamIDUser);
	return 0;
}

// In C++:
// SteamAPICall_t ChangeNumOpenSlots(PartyBeaconID_t ulBeacon, uint32 unOpenSlots);
// In Lua:
// uint64 Parties.ChangeNumOpenSlots(ulBeacon: uint64, unOpenSlots: int, callback: function)
static int luasteam_Parties_ChangeNumOpenSlots(lua_State *L) {
	auto *iface = SteamParties();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	PartyBeaconID_t ulBeacon(luasteam::checkuint64(L, 1));
	uint32 unOpenSlots = static_cast<uint32>(luaL_checkint(L, 2));
	SteamAPICall_t __ret = iface->ChangeNumOpenSlots(ulBeacon, unOpenSlots);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<ChangeNumOpenSlotsCallback_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<ChangeNumOpenSlotsCallback_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// bool DestroyBeacon(PartyBeaconID_t ulBeacon);
// In Lua:
// bool Parties.DestroyBeacon(ulBeacon: uint64)
static int luasteam_Parties_DestroyBeacon(lua_State *L) {
	auto *iface = SteamParties();
	PartyBeaconID_t ulBeacon(luasteam::checkuint64(L, 1));
	bool __ret = iface->DestroyBeacon(ulBeacon);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool GetBeaconLocationData(SteamPartyBeaconLocation_t BeaconLocation, ESteamPartyBeaconLocationData eData, char * pchDataStringOut, int cchDataStringOut);
// In Lua:
// (bool, pchDataStringOut: str) Parties.GetBeaconLocationData(BeaconLocation: SteamPartyBeaconLocation_t, eData: int, cchDataStringOut: int)
static int luasteam_Parties_GetBeaconLocationData(lua_State *L) {
	auto *iface = SteamParties();
	SteamPartyBeaconLocation_t BeaconLocation = luasteam::check_SteamPartyBeaconLocation_t(L, 1);
	ESteamPartyBeaconLocationData eData = static_cast<ESteamPartyBeaconLocationData>(luaL_checkint(L, 2));
	int cchDataStringOut = luaL_checkint(L, 3);
	std::vector<char> pchDataStringOut(cchDataStringOut);
	bool __ret = iface->GetBeaconLocationData(BeaconLocation, eData, pchDataStringOut.data(), cchDataStringOut);
	lua_pushboolean(L, __ret);
	lua_pushstring(L, reinterpret_cast<const char*>(pchDataStringOut.data()));
	return 2;
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
	add_func(L, "GetBeaconLocationData", luasteam_Parties_GetBeaconLocationData);
}

void add_Parties_auto(lua_State *L) {
	lua_createtable(L, 0, 11);
	register_Parties_auto(L);
	lua_pushvalue(L, -1);
	Parties_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "Parties");
}

} // namespace luasteam
