#include "auto.hpp"

namespace luasteam {

int Timeline_ref = LUA_NOREF;

namespace {
class TimelineCallbackListener {
private:
	STEAM_CALLBACK(TimelineCallbackListener, OnSteamTimelineGamePhaseRecordingExists, SteamTimelineGamePhaseRecordingExists_t);
	STEAM_CALLBACK(TimelineCallbackListener, OnSteamTimelineEventRecordingExists, SteamTimelineEventRecordingExists_t);
};
void TimelineCallbackListener::OnSteamTimelineGamePhaseRecordingExists(SteamTimelineGamePhaseRecordingExists_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Timeline_ref);
	lua_getfield(L, -1, "OnSteamTimelineGamePhaseRecordingExists");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamTimelineGamePhaseRecordingExists_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void TimelineCallbackListener::OnSteamTimelineEventRecordingExists(SteamTimelineEventRecordingExists_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Timeline_ref);
	lua_getfield(L, -1, "OnSteamTimelineEventRecordingExists");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamTimelineEventRecordingExists_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
TimelineCallbackListener *Timeline_listener = nullptr;
} // namespace

void init_Timeline_auto(lua_State *L) { if (Timeline_listener != nullptr) return; Timeline_listener = new TimelineCallbackListener(); }
void shutdown_Timeline_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, Timeline_ref);
	Timeline_ref = LUA_NOREF;
	delete Timeline_listener; Timeline_listener = nullptr;
}

template <> void CallResultListener<SteamTimelineEventRecordingExists_t>::Result(SteamTimelineEventRecordingExists_t *data, bool io_fail) {
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
		luasteam::pushuint64(L, data->m_ulEventID);
		lua_setfield(L, -2, "m_ulEventID");
		lua_pushboolean(L, data->m_bRecordingExists);
		lua_setfield(L, -2, "m_bRecordingExists");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<SteamTimelineGamePhaseRecordingExists_t>::Result(SteamTimelineGamePhaseRecordingExists_t *data, bool io_fail) {
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
		lua_createtable(L, 0, 5);
		lua_pushlstring(L, reinterpret_cast<const char*>(data->m_rgchPhaseID), 64);
		lua_setfield(L, -2, "m_rgchPhaseID");
		luasteam::pushuint64(L, data->m_ulRecordingMS);
		lua_setfield(L, -2, "m_ulRecordingMS");
		luasteam::pushuint64(L, data->m_ulLongestClipMS);
		lua_setfield(L, -2, "m_ulLongestClipMS");
		lua_pushinteger(L, data->m_unClipCount);
		lua_setfield(L, -2, "m_unClipCount");
		lua_pushinteger(L, data->m_unScreenshotCount);
		lua_setfield(L, -2, "m_unScreenshotCount");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

// In C++:
// void SetTimelineTooltip(const char * pchDescription, float flTimeDelta);
// In Lua:
// Timeline.SetTimelineTooltip(pchDescription: str, flTimeDelta: float)
static int luasteam_Timeline_SetTimelineTooltip(lua_State *L) {
	auto *iface = SteamTimeline();
	const char *pchDescription = luaL_checkstring(L, 1);
	float flTimeDelta = static_cast<float>(luaL_checknumber(L, 2));
	iface->SetTimelineTooltip(pchDescription, flTimeDelta);
	return 0;
}

// In C++:
// void ClearTimelineTooltip(float flTimeDelta);
// In Lua:
// Timeline.ClearTimelineTooltip(flTimeDelta: float)
static int luasteam_Timeline_ClearTimelineTooltip(lua_State *L) {
	auto *iface = SteamTimeline();
	float flTimeDelta = static_cast<float>(luaL_checknumber(L, 1));
	iface->ClearTimelineTooltip(flTimeDelta);
	return 0;
}

// In C++:
// void SetTimelineGameMode(ETimelineGameMode eMode);
// In Lua:
// Timeline.SetTimelineGameMode(eMode: int)
static int luasteam_Timeline_SetTimelineGameMode(lua_State *L) {
	auto *iface = SteamTimeline();
	ETimelineGameMode eMode = static_cast<ETimelineGameMode>(luaL_checkint(L, 1));
	iface->SetTimelineGameMode(eMode);
	return 0;
}

// In C++:
// TimelineEventHandle_t AddInstantaneousTimelineEvent(const char * pchTitle, const char * pchDescription, const char * pchIcon, uint32 unIconPriority, float flStartOffsetSeconds, ETimelineEventClipPriority ePossibleClip);
// In Lua:
// uint64 Timeline.AddInstantaneousTimelineEvent(pchTitle: str, pchDescription: str, pchIcon: str, unIconPriority: int, flStartOffsetSeconds: float, ePossibleClip: int)
static int luasteam_Timeline_AddInstantaneousTimelineEvent(lua_State *L) {
	auto *iface = SteamTimeline();
	const char *pchTitle = luaL_checkstring(L, 1);
	const char *pchDescription = luaL_checkstring(L, 2);
	const char *pchIcon = luaL_checkstring(L, 3);
	uint32 unIconPriority = static_cast<uint32>(luaL_checkint(L, 4));
	float flStartOffsetSeconds = static_cast<float>(luaL_checknumber(L, 5));
	ETimelineEventClipPriority ePossibleClip = static_cast<ETimelineEventClipPriority>(luaL_checkint(L, 6));
	TimelineEventHandle_t __ret = iface->AddInstantaneousTimelineEvent(pchTitle, pchDescription, pchIcon, unIconPriority, flStartOffsetSeconds, ePossibleClip);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// TimelineEventHandle_t AddRangeTimelineEvent(const char * pchTitle, const char * pchDescription, const char * pchIcon, uint32 unIconPriority, float flStartOffsetSeconds, float flDuration, ETimelineEventClipPriority ePossibleClip);
// In Lua:
// uint64 Timeline.AddRangeTimelineEvent(pchTitle: str, pchDescription: str, pchIcon: str, unIconPriority: int, flStartOffsetSeconds: float, flDuration: float, ePossibleClip: int)
static int luasteam_Timeline_AddRangeTimelineEvent(lua_State *L) {
	auto *iface = SteamTimeline();
	const char *pchTitle = luaL_checkstring(L, 1);
	const char *pchDescription = luaL_checkstring(L, 2);
	const char *pchIcon = luaL_checkstring(L, 3);
	uint32 unIconPriority = static_cast<uint32>(luaL_checkint(L, 4));
	float flStartOffsetSeconds = static_cast<float>(luaL_checknumber(L, 5));
	float flDuration = static_cast<float>(luaL_checknumber(L, 6));
	ETimelineEventClipPriority ePossibleClip = static_cast<ETimelineEventClipPriority>(luaL_checkint(L, 7));
	TimelineEventHandle_t __ret = iface->AddRangeTimelineEvent(pchTitle, pchDescription, pchIcon, unIconPriority, flStartOffsetSeconds, flDuration, ePossibleClip);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// TimelineEventHandle_t StartRangeTimelineEvent(const char * pchTitle, const char * pchDescription, const char * pchIcon, uint32 unPriority, float flStartOffsetSeconds, ETimelineEventClipPriority ePossibleClip);
// In Lua:
// uint64 Timeline.StartRangeTimelineEvent(pchTitle: str, pchDescription: str, pchIcon: str, unPriority: int, flStartOffsetSeconds: float, ePossibleClip: int)
static int luasteam_Timeline_StartRangeTimelineEvent(lua_State *L) {
	auto *iface = SteamTimeline();
	const char *pchTitle = luaL_checkstring(L, 1);
	const char *pchDescription = luaL_checkstring(L, 2);
	const char *pchIcon = luaL_checkstring(L, 3);
	uint32 unPriority = static_cast<uint32>(luaL_checkint(L, 4));
	float flStartOffsetSeconds = static_cast<float>(luaL_checknumber(L, 5));
	ETimelineEventClipPriority ePossibleClip = static_cast<ETimelineEventClipPriority>(luaL_checkint(L, 6));
	TimelineEventHandle_t __ret = iface->StartRangeTimelineEvent(pchTitle, pchDescription, pchIcon, unPriority, flStartOffsetSeconds, ePossibleClip);
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// void UpdateRangeTimelineEvent(TimelineEventHandle_t ulEvent, const char * pchTitle, const char * pchDescription, const char * pchIcon, uint32 unPriority, ETimelineEventClipPriority ePossibleClip);
// In Lua:
// Timeline.UpdateRangeTimelineEvent(ulEvent: uint64, pchTitle: str, pchDescription: str, pchIcon: str, unPriority: int, ePossibleClip: int)
static int luasteam_Timeline_UpdateRangeTimelineEvent(lua_State *L) {
	auto *iface = SteamTimeline();
	TimelineEventHandle_t ulEvent = luasteam::checkuint64(L, 1);
	const char *pchTitle = luaL_checkstring(L, 2);
	const char *pchDescription = luaL_checkstring(L, 3);
	const char *pchIcon = luaL_checkstring(L, 4);
	uint32 unPriority = static_cast<uint32>(luaL_checkint(L, 5));
	ETimelineEventClipPriority ePossibleClip = static_cast<ETimelineEventClipPriority>(luaL_checkint(L, 6));
	iface->UpdateRangeTimelineEvent(ulEvent, pchTitle, pchDescription, pchIcon, unPriority, ePossibleClip);
	return 0;
}

// In C++:
// void EndRangeTimelineEvent(TimelineEventHandle_t ulEvent, float flEndOffsetSeconds);
// In Lua:
// Timeline.EndRangeTimelineEvent(ulEvent: uint64, flEndOffsetSeconds: float)
static int luasteam_Timeline_EndRangeTimelineEvent(lua_State *L) {
	auto *iface = SteamTimeline();
	TimelineEventHandle_t ulEvent = luasteam::checkuint64(L, 1);
	float flEndOffsetSeconds = static_cast<float>(luaL_checknumber(L, 2));
	iface->EndRangeTimelineEvent(ulEvent, flEndOffsetSeconds);
	return 0;
}

// In C++:
// void RemoveTimelineEvent(TimelineEventHandle_t ulEvent);
// In Lua:
// Timeline.RemoveTimelineEvent(ulEvent: uint64)
static int luasteam_Timeline_RemoveTimelineEvent(lua_State *L) {
	auto *iface = SteamTimeline();
	TimelineEventHandle_t ulEvent = luasteam::checkuint64(L, 1);
	iface->RemoveTimelineEvent(ulEvent);
	return 0;
}

// In C++:
// SteamAPICall_t DoesEventRecordingExist(TimelineEventHandle_t ulEvent);
// In Lua:
// uint64 Timeline.DoesEventRecordingExist(ulEvent: uint64, callback: function)
static int luasteam_Timeline_DoesEventRecordingExist(lua_State *L) {
	auto *iface = SteamTimeline();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	TimelineEventHandle_t ulEvent = luasteam::checkuint64(L, 1);
	SteamAPICall_t __ret = iface->DoesEventRecordingExist(ulEvent);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<SteamTimelineEventRecordingExists_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<SteamTimelineEventRecordingExists_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// void StartGamePhase();
// In Lua:
// Timeline.StartGamePhase()
static int luasteam_Timeline_StartGamePhase(lua_State *L) {
	auto *iface = SteamTimeline();
	iface->StartGamePhase();
	return 0;
}

// In C++:
// void EndGamePhase();
// In Lua:
// Timeline.EndGamePhase()
static int luasteam_Timeline_EndGamePhase(lua_State *L) {
	auto *iface = SteamTimeline();
	iface->EndGamePhase();
	return 0;
}

// In C++:
// void SetGamePhaseID(const char * pchPhaseID);
// In Lua:
// Timeline.SetGamePhaseID(pchPhaseID: str)
static int luasteam_Timeline_SetGamePhaseID(lua_State *L) {
	auto *iface = SteamTimeline();
	const char *pchPhaseID = luaL_checkstring(L, 1);
	iface->SetGamePhaseID(pchPhaseID);
	return 0;
}

// In C++:
// SteamAPICall_t DoesGamePhaseRecordingExist(const char * pchPhaseID);
// In Lua:
// uint64 Timeline.DoesGamePhaseRecordingExist(pchPhaseID: str, callback: function)
static int luasteam_Timeline_DoesGamePhaseRecordingExist(lua_State *L) {
	auto *iface = SteamTimeline();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	const char *pchPhaseID = luaL_checkstring(L, 1);
	SteamAPICall_t __ret = iface->DoesGamePhaseRecordingExist(pchPhaseID);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<SteamTimelineGamePhaseRecordingExists_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<SteamTimelineGamePhaseRecordingExists_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// void AddGamePhaseTag(const char * pchTagName, const char * pchTagIcon, const char * pchTagGroup, uint32 unPriority);
// In Lua:
// Timeline.AddGamePhaseTag(pchTagName: str, pchTagIcon: str, pchTagGroup: str, unPriority: int)
static int luasteam_Timeline_AddGamePhaseTag(lua_State *L) {
	auto *iface = SteamTimeline();
	const char *pchTagName = luaL_checkstring(L, 1);
	const char *pchTagIcon = luaL_checkstring(L, 2);
	const char *pchTagGroup = luaL_checkstring(L, 3);
	uint32 unPriority = static_cast<uint32>(luaL_checkint(L, 4));
	iface->AddGamePhaseTag(pchTagName, pchTagIcon, pchTagGroup, unPriority);
	return 0;
}

// In C++:
// void SetGamePhaseAttribute(const char * pchAttributeGroup, const char * pchAttributeValue, uint32 unPriority);
// In Lua:
// Timeline.SetGamePhaseAttribute(pchAttributeGroup: str, pchAttributeValue: str, unPriority: int)
static int luasteam_Timeline_SetGamePhaseAttribute(lua_State *L) {
	auto *iface = SteamTimeline();
	const char *pchAttributeGroup = luaL_checkstring(L, 1);
	const char *pchAttributeValue = luaL_checkstring(L, 2);
	uint32 unPriority = static_cast<uint32>(luaL_checkint(L, 3));
	iface->SetGamePhaseAttribute(pchAttributeGroup, pchAttributeValue, unPriority);
	return 0;
}

// In C++:
// void OpenOverlayToGamePhase(const char * pchPhaseID);
// In Lua:
// Timeline.OpenOverlayToGamePhase(pchPhaseID: str)
static int luasteam_Timeline_OpenOverlayToGamePhase(lua_State *L) {
	auto *iface = SteamTimeline();
	const char *pchPhaseID = luaL_checkstring(L, 1);
	iface->OpenOverlayToGamePhase(pchPhaseID);
	return 0;
}

// In C++:
// void OpenOverlayToTimelineEvent(const TimelineEventHandle_t ulEvent);
// In Lua:
// Timeline.OpenOverlayToTimelineEvent(ulEvent: uint64)
static int luasteam_Timeline_OpenOverlayToTimelineEvent(lua_State *L) {
	auto *iface = SteamTimeline();
	const TimelineEventHandle_t ulEvent = luasteam::checkuint64(L, 1);
	iface->OpenOverlayToTimelineEvent(ulEvent);
	return 0;
}

void register_Timeline_auto(lua_State *L) {
	add_func(L, "SetTimelineTooltip", luasteam_Timeline_SetTimelineTooltip);
	add_func(L, "ClearTimelineTooltip", luasteam_Timeline_ClearTimelineTooltip);
	add_func(L, "SetTimelineGameMode", luasteam_Timeline_SetTimelineGameMode);
	add_func(L, "AddInstantaneousTimelineEvent", luasteam_Timeline_AddInstantaneousTimelineEvent);
	add_func(L, "AddRangeTimelineEvent", luasteam_Timeline_AddRangeTimelineEvent);
	add_func(L, "StartRangeTimelineEvent", luasteam_Timeline_StartRangeTimelineEvent);
	add_func(L, "UpdateRangeTimelineEvent", luasteam_Timeline_UpdateRangeTimelineEvent);
	add_func(L, "EndRangeTimelineEvent", luasteam_Timeline_EndRangeTimelineEvent);
	add_func(L, "RemoveTimelineEvent", luasteam_Timeline_RemoveTimelineEvent);
	add_func(L, "DoesEventRecordingExist", luasteam_Timeline_DoesEventRecordingExist);
	add_func(L, "StartGamePhase", luasteam_Timeline_StartGamePhase);
	add_func(L, "EndGamePhase", luasteam_Timeline_EndGamePhase);
	add_func(L, "SetGamePhaseID", luasteam_Timeline_SetGamePhaseID);
	add_func(L, "DoesGamePhaseRecordingExist", luasteam_Timeline_DoesGamePhaseRecordingExist);
	add_func(L, "AddGamePhaseTag", luasteam_Timeline_AddGamePhaseTag);
	add_func(L, "SetGamePhaseAttribute", luasteam_Timeline_SetGamePhaseAttribute);
	add_func(L, "OpenOverlayToGamePhase", luasteam_Timeline_OpenOverlayToGamePhase);
	add_func(L, "OpenOverlayToTimelineEvent", luasteam_Timeline_OpenOverlayToTimelineEvent);
}

void add_Timeline_auto(lua_State *L) {
	lua_createtable(L, 0, 18);
	register_Timeline_auto(L);
	lua_pushvalue(L, -1);
	Timeline_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "Timeline");
}

} // namespace luasteam
