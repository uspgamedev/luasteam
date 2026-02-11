#include "auto.hpp"

namespace luasteam {

int parties_ref = LUA_NOREF;

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
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::parties_ref);
    lua_getfield(L, -1, "onJoinPartyCallback");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_ulBeaconID);
        lua_setfield(L, -2, "beaconID");
        luasteam::pushuint64(L, data->m_SteamIDBeaconOwner.ConvertToUint64());
        lua_setfield(L, -2, "steamIDBeaconOwner");
        lua_pushstring(L, data->m_rgchConnectString);
        lua_setfield(L, -2, "connectString");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnCreateBeaconCallback(CreateBeaconCallback_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::parties_ref);
    lua_getfield(L, -1, "onCreateBeaconCallback");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_ulBeaconID);
        lua_setfield(L, -2, "beaconID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnReservationNotificationCallback(ReservationNotificationCallback_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::parties_ref);
    lua_getfield(L, -1, "onReservationNotificationCallback");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        luasteam::pushuint64(L, data->m_ulBeaconID);
        lua_setfield(L, -2, "beaconID");
        luasteam::pushuint64(L, data->m_steamIDJoiner.ConvertToUint64());
        lua_setfield(L, -2, "steamIDJoiner");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnChangeNumOpenSlotsCallback(ChangeNumOpenSlotsCallback_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::parties_ref);
    lua_getfield(L, -1, "onChangeNumOpenSlotsCallback");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnAvailableBeaconLocationsUpdated(AvailableBeaconLocationsUpdated_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::parties_ref);
    lua_getfield(L, -1, "onAvailableBeaconLocationsUpdated");
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
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::parties_ref);
    lua_getfield(L, -1, "onActiveBeaconsUpdated");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 0);
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

CallbackListener *parties_listener = nullptr;

} // namespace

void init_parties_auto(lua_State *L) { parties_listener = new CallbackListener(); }

void shutdown_parties_auto(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, parties_ref);
    parties_ref = LUA_NOREF;
    delete parties_listener; parties_listener = nullptr;
}


// uint32 GetNumActiveBeacons();
EXTERN int luasteam_parties_SteamAPI_ISteamParties_GetNumActiveBeacons(lua_State *L) {
    lua_pushinteger(L, SteamParties()->GetNumActiveBeacons());
    return 1;
}

// PartyBeaconID_t GetBeaconByIndex(uint32 unIndex);
EXTERN int luasteam_parties_SteamAPI_ISteamParties_GetBeaconByIndex(lua_State *L) {
    uint32 unIndex = static_cast<uint32>(luaL_checkint(L, 1));
    luasteam::pushuint64(L, SteamParties()->GetBeaconByIndex(unIndex));
    return 1;
}

// SteamAPICall_t JoinParty(PartyBeaconID_t ulBeaconID);
EXTERN int luasteam_parties_SteamAPI_ISteamParties_JoinParty(lua_State *L) {
    PartyBeaconID_t ulBeaconID = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamParties()->JoinParty(ulBeaconID));
    return 1;
}

// void OnReservationCompleted(PartyBeaconID_t ulBeacon, CSteamID steamIDUser);
EXTERN int luasteam_parties_SteamAPI_ISteamParties_OnReservationCompleted(lua_State *L) {
    PartyBeaconID_t ulBeacon = luasteam::checkuint64(L, 1);
    CSteamID steamIDUser(luasteam::checkuint64(L, 2));
    SteamParties()->OnReservationCompleted(ulBeacon, steamIDUser);
    return 0;
}

// void CancelReservation(PartyBeaconID_t ulBeacon, CSteamID steamIDUser);
EXTERN int luasteam_parties_SteamAPI_ISteamParties_CancelReservation(lua_State *L) {
    PartyBeaconID_t ulBeacon = luasteam::checkuint64(L, 1);
    CSteamID steamIDUser(luasteam::checkuint64(L, 2));
    SteamParties()->CancelReservation(ulBeacon, steamIDUser);
    return 0;
}

// SteamAPICall_t ChangeNumOpenSlots(PartyBeaconID_t ulBeacon, uint32 unOpenSlots);
EXTERN int luasteam_parties_SteamAPI_ISteamParties_ChangeNumOpenSlots(lua_State *L) {
    PartyBeaconID_t ulBeacon = luasteam::checkuint64(L, 1);
    uint32 unOpenSlots = static_cast<uint32>(luaL_checkint(L, 2));
    luasteam::pushuint64(L, SteamParties()->ChangeNumOpenSlots(ulBeacon, unOpenSlots));
    return 1;
}

// bool DestroyBeacon(PartyBeaconID_t ulBeacon);
EXTERN int luasteam_parties_SteamAPI_ISteamParties_DestroyBeacon(lua_State *L) {
    PartyBeaconID_t ulBeacon = luasteam::checkuint64(L, 1);
    lua_pushboolean(L, SteamParties()->DestroyBeacon(ulBeacon));
    return 1;
}

void register_parties_auto(lua_State *L) {
    add_func(L, "getNumActiveBeacons", luasteam_parties_SteamAPI_ISteamParties_GetNumActiveBeacons);
    add_func(L, "getBeaconByIndex", luasteam_parties_SteamAPI_ISteamParties_GetBeaconByIndex);
    add_func(L, "joinParty", luasteam_parties_SteamAPI_ISteamParties_JoinParty);
    add_func(L, "onReservationCompleted", luasteam_parties_SteamAPI_ISteamParties_OnReservationCompleted);
    add_func(L, "cancelReservation", luasteam_parties_SteamAPI_ISteamParties_CancelReservation);
    add_func(L, "changeNumOpenSlots", luasteam_parties_SteamAPI_ISteamParties_ChangeNumOpenSlots);
    add_func(L, "destroyBeacon", luasteam_parties_SteamAPI_ISteamParties_DestroyBeacon);
}

void add_parties_auto(lua_State *L) {
    lua_createtable(L, 0, 7);
    register_parties_auto(L);
    lua_pushvalue(L, -1);
    parties_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "parties");
}

} // namespace luasteam
