#include "auto.hpp"

namespace luasteam {

int Music_ref = LUA_NOREF;

namespace {
class CallbackListener {
private:
	STEAM_CALLBACK(CallbackListener, OnPlaybackStatusHasChanged, PlaybackStatusHasChanged_t);
	STEAM_CALLBACK(CallbackListener, OnVolumeHasChanged, VolumeHasChanged_t);
};
void CallbackListener::OnPlaybackStatusHasChanged(PlaybackStatusHasChanged_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Music_ref);
	lua_getfield(L, -1, "OnPlaybackStatusHasChanged");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_PlaybackStatusHasChanged_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void CallbackListener::OnVolumeHasChanged(VolumeHasChanged_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Music_ref);
	lua_getfield(L, -1, "OnVolumeHasChanged");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_VolumeHasChanged_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
CallbackListener *Music_listener = nullptr;
} // namespace

void init_Music_auto(lua_State *L) { Music_listener = new CallbackListener(); }
void shutdown_Music_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, Music_ref);
	Music_ref = LUA_NOREF;
	delete Music_listener; Music_listener = nullptr;
}

// In C++:
// bool BIsEnabled();
// In Lua:
// bool Music.BIsEnabled()
EXTERN int luasteam_Music_BIsEnabled(lua_State *L) {
	bool __ret = SteamMusic()->BIsEnabled();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool BIsPlaying();
// In Lua:
// bool Music.BIsPlaying()
EXTERN int luasteam_Music_BIsPlaying(lua_State *L) {
	bool __ret = SteamMusic()->BIsPlaying();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// AudioPlayback_Status GetPlaybackStatus();
// In Lua:
// int Music.GetPlaybackStatus()
EXTERN int luasteam_Music_GetPlaybackStatus(lua_State *L) {
	AudioPlayback_Status __ret = SteamMusic()->GetPlaybackStatus();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// void Play();
// In Lua:
// Music.Play()
EXTERN int luasteam_Music_Play(lua_State *L) {
	SteamMusic()->Play();
	return 0;
}

// In C++:
// void Pause();
// In Lua:
// Music.Pause()
EXTERN int luasteam_Music_Pause(lua_State *L) {
	SteamMusic()->Pause();
	return 0;
}

// In C++:
// void PlayPrevious();
// In Lua:
// Music.PlayPrevious()
EXTERN int luasteam_Music_PlayPrevious(lua_State *L) {
	SteamMusic()->PlayPrevious();
	return 0;
}

// In C++:
// void PlayNext();
// In Lua:
// Music.PlayNext()
EXTERN int luasteam_Music_PlayNext(lua_State *L) {
	SteamMusic()->PlayNext();
	return 0;
}

// In C++:
// void SetVolume(float flVolume);
// In Lua:
// Music.SetVolume(flVolume: float)
EXTERN int luasteam_Music_SetVolume(lua_State *L) {
	float flVolume = luaL_checknumber(L, 1);
	SteamMusic()->SetVolume(flVolume);
	return 0;
}

// In C++:
// float GetVolume();
// In Lua:
// float Music.GetVolume()
EXTERN int luasteam_Music_GetVolume(lua_State *L) {
	float __ret = SteamMusic()->GetVolume();
	lua_pushnumber(L, __ret);
	return 1;
}

void register_Music_auto(lua_State *L) {
	add_func(L, "BIsEnabled", luasteam_Music_BIsEnabled);
	add_func(L, "BIsPlaying", luasteam_Music_BIsPlaying);
	add_func(L, "GetPlaybackStatus", luasteam_Music_GetPlaybackStatus);
	add_func(L, "Play", luasteam_Music_Play);
	add_func(L, "Pause", luasteam_Music_Pause);
	add_func(L, "PlayPrevious", luasteam_Music_PlayPrevious);
	add_func(L, "PlayNext", luasteam_Music_PlayNext);
	add_func(L, "SetVolume", luasteam_Music_SetVolume);
	add_func(L, "GetVolume", luasteam_Music_GetVolume);
}

void add_Music_auto(lua_State *L) {
	lua_createtable(L, 0, 9);
	register_Music_auto(L);
	lua_pushvalue(L, -1);
	Music_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "Music");
}

} // namespace luasteam
