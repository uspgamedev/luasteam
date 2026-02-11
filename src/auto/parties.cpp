#include "auto.hpp"

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

namespace luasteam {

void add_parties_auto(lua_State *L) {
    add_func(L, "getNumActiveBeacons", luasteam_parties_SteamAPI_ISteamParties_GetNumActiveBeacons);
    add_func(L, "getBeaconByIndex", luasteam_parties_SteamAPI_ISteamParties_GetBeaconByIndex);
    add_func(L, "joinParty", luasteam_parties_SteamAPI_ISteamParties_JoinParty);
    add_func(L, "onReservationCompleted", luasteam_parties_SteamAPI_ISteamParties_OnReservationCompleted);
    add_func(L, "cancelReservation", luasteam_parties_SteamAPI_ISteamParties_CancelReservation);
    add_func(L, "changeNumOpenSlots", luasteam_parties_SteamAPI_ISteamParties_ChangeNumOpenSlots);
    add_func(L, "destroyBeacon", luasteam_parties_SteamAPI_ISteamParties_DestroyBeacon);
}

} // namespace luasteam
