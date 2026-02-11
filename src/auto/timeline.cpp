#include "auto.hpp"

namespace luasteam {

int Timeline_ref = LUA_NOREF;

namespace {

class CallbackListener {
  private:
    STEAM_CALLBACK(CallbackListener, OnSteamTimelineGamePhaseRecordingExists, SteamTimelineGamePhaseRecordingExists_t);
    STEAM_CALLBACK(CallbackListener, OnSteamTimelineEventRecordingExists, SteamTimelineEventRecordingExists_t);
};

void CallbackListener::OnSteamTimelineGamePhaseRecordingExists(SteamTimelineGamePhaseRecordingExists_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Timeline_ref);
    lua_getfield(L, -1, "onSteamTimelineGamePhaseRecordingExists");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 5);
        lua_pushstring(L, data->m_rgchPhaseID);
        lua_setfield(L, -2, "phaseID");
        luasteam::pushuint64(L, data->m_ulRecordingMS);
        lua_setfield(L, -2, "recordingMS");
        luasteam::pushuint64(L, data->m_ulLongestClipMS);
        lua_setfield(L, -2, "longestClipMS");
        lua_pushinteger(L, data->m_unClipCount);
        lua_setfield(L, -2, "clipCount");
        lua_pushinteger(L, data->m_unScreenshotCount);
        lua_setfield(L, -2, "screenshotCount");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnSteamTimelineEventRecordingExists(SteamTimelineEventRecordingExists_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Timeline_ref);
    lua_getfield(L, -1, "onSteamTimelineEventRecordingExists");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        luasteam::pushuint64(L, data->m_ulEventID);
        lua_setfield(L, -2, "eventID");
        lua_pushboolean(L, data->m_bRecordingExists);
        lua_setfield(L, -2, "recordingExists");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

CallbackListener *Timeline_listener = nullptr;

} // namespace

void init_Timeline_auto(lua_State *L) { Timeline_listener = new CallbackListener(); }

void shutdown_Timeline_auto(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, Timeline_ref);
    Timeline_ref = LUA_NOREF;
    delete Timeline_listener; Timeline_listener = nullptr;
}


// void SetTimelineGameMode(ETimelineGameMode eMode);
EXTERN int luasteam_Timeline_SetTimelineGameMode(lua_State *L) {
    ETimelineGameMode eMode = static_cast<ETimelineGameMode>(luaL_checkint(L, 1));
    SteamTimeline()->SetTimelineGameMode(eMode);
    return 0;
}

// void UpdateRangeTimelineEvent(TimelineEventHandle_t ulEvent, const char * pchTitle, const char * pchDescription, const char * pchIcon, uint32 unPriority, ETimelineEventClipPriority ePossibleClip);
EXTERN int luasteam_Timeline_UpdateRangeTimelineEvent(lua_State *L) {
    TimelineEventHandle_t ulEvent = luasteam::checkuint64(L, 1);
    const char *pchTitle = luaL_checkstring(L, 2);
    const char *pchDescription = luaL_checkstring(L, 3);
    const char *pchIcon = luaL_checkstring(L, 4);
    uint32 unPriority = static_cast<uint32>(luaL_checkint(L, 5));
    ETimelineEventClipPriority ePossibleClip = static_cast<ETimelineEventClipPriority>(luaL_checkint(L, 6));
    SteamTimeline()->UpdateRangeTimelineEvent(ulEvent, pchTitle, pchDescription, pchIcon, unPriority, ePossibleClip);
    return 0;
}

// void RemoveTimelineEvent(TimelineEventHandle_t ulEvent);
EXTERN int luasteam_Timeline_RemoveTimelineEvent(lua_State *L) {
    TimelineEventHandle_t ulEvent = luasteam::checkuint64(L, 1);
    SteamTimeline()->RemoveTimelineEvent(ulEvent);
    return 0;
}

// SteamAPICall_t DoesEventRecordingExist(TimelineEventHandle_t ulEvent);
EXTERN int luasteam_Timeline_DoesEventRecordingExist(lua_State *L) {
    TimelineEventHandle_t ulEvent = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamTimeline()->DoesEventRecordingExist(ulEvent));
    return 1;
}

// void StartGamePhase();
EXTERN int luasteam_Timeline_StartGamePhase(lua_State *L) {
    SteamTimeline()->StartGamePhase();
    return 0;
}

// void EndGamePhase();
EXTERN int luasteam_Timeline_EndGamePhase(lua_State *L) {
    SteamTimeline()->EndGamePhase();
    return 0;
}

// void SetGamePhaseID(const char * pchPhaseID);
EXTERN int luasteam_Timeline_SetGamePhaseID(lua_State *L) {
    const char *pchPhaseID = luaL_checkstring(L, 1);
    SteamTimeline()->SetGamePhaseID(pchPhaseID);
    return 0;
}

// SteamAPICall_t DoesGamePhaseRecordingExist(const char * pchPhaseID);
EXTERN int luasteam_Timeline_DoesGamePhaseRecordingExist(lua_State *L) {
    const char *pchPhaseID = luaL_checkstring(L, 1);
    luasteam::pushuint64(L, SteamTimeline()->DoesGamePhaseRecordingExist(pchPhaseID));
    return 1;
}

// void AddGamePhaseTag(const char * pchTagName, const char * pchTagIcon, const char * pchTagGroup, uint32 unPriority);
EXTERN int luasteam_Timeline_AddGamePhaseTag(lua_State *L) {
    const char *pchTagName = luaL_checkstring(L, 1);
    const char *pchTagIcon = luaL_checkstring(L, 2);
    const char *pchTagGroup = luaL_checkstring(L, 3);
    uint32 unPriority = static_cast<uint32>(luaL_checkint(L, 4));
    SteamTimeline()->AddGamePhaseTag(pchTagName, pchTagIcon, pchTagGroup, unPriority);
    return 0;
}

// void SetGamePhaseAttribute(const char * pchAttributeGroup, const char * pchAttributeValue, uint32 unPriority);
EXTERN int luasteam_Timeline_SetGamePhaseAttribute(lua_State *L) {
    const char *pchAttributeGroup = luaL_checkstring(L, 1);
    const char *pchAttributeValue = luaL_checkstring(L, 2);
    uint32 unPriority = static_cast<uint32>(luaL_checkint(L, 3));
    SteamTimeline()->SetGamePhaseAttribute(pchAttributeGroup, pchAttributeValue, unPriority);
    return 0;
}

// void OpenOverlayToGamePhase(const char * pchPhaseID);
EXTERN int luasteam_Timeline_OpenOverlayToGamePhase(lua_State *L) {
    const char *pchPhaseID = luaL_checkstring(L, 1);
    SteamTimeline()->OpenOverlayToGamePhase(pchPhaseID);
    return 0;
}

void register_Timeline_auto(lua_State *L) {
    add_func(L, "SetTimelineGameMode", luasteam_Timeline_SetTimelineGameMode);
    add_func(L, "UpdateRangeTimelineEvent", luasteam_Timeline_UpdateRangeTimelineEvent);
    add_func(L, "RemoveTimelineEvent", luasteam_Timeline_RemoveTimelineEvent);
    add_func(L, "DoesEventRecordingExist", luasteam_Timeline_DoesEventRecordingExist);
    add_func(L, "StartGamePhase", luasteam_Timeline_StartGamePhase);
    add_func(L, "EndGamePhase", luasteam_Timeline_EndGamePhase);
    add_func(L, "SetGamePhaseID", luasteam_Timeline_SetGamePhaseID);
    add_func(L, "DoesGamePhaseRecordingExist", luasteam_Timeline_DoesGamePhaseRecordingExist);
    add_func(L, "AddGamePhaseTag", luasteam_Timeline_AddGamePhaseTag);
    add_func(L, "SetGamePhaseAttribute", luasteam_Timeline_SetGamePhaseAttribute);
    add_func(L, "OpenOverlayToGamePhase", luasteam_Timeline_OpenOverlayToGamePhase);
}

void add_Timeline_auto(lua_State *L) {
    lua_createtable(L, 0, 11);
    register_Timeline_auto(L);
    lua_pushvalue(L, -1);
    Timeline_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "Timeline");
}

} // namespace luasteam
