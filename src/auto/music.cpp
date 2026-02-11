#include "auto.hpp"

namespace luasteam {

int music_ref = LUA_NOREF;

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
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::music_ref);
    lua_getfield(L, -1, "onPlaybackStatusHasChanged");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 0);
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnVolumeHasChanged(VolumeHasChanged_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::music_ref);
    lua_getfield(L, -1, "onVolumeHasChanged");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

CallbackListener *music_listener = nullptr;

} // namespace

void init_music_auto(lua_State *L) { music_listener = new CallbackListener(); }

void shutdown_music_auto(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, music_ref);
    music_ref = LUA_NOREF;
    delete music_listener; music_listener = nullptr;
}


// bool BIsEnabled();
EXTERN int luasteam_music_SteamAPI_ISteamMusic_BIsEnabled(lua_State *L) {
    lua_pushboolean(L, SteamMusic()->BIsEnabled());
    return 1;
}

// bool BIsPlaying();
EXTERN int luasteam_music_SteamAPI_ISteamMusic_BIsPlaying(lua_State *L) {
    lua_pushboolean(L, SteamMusic()->BIsPlaying());
    return 1;
}

// AudioPlayback_Status GetPlaybackStatus();
EXTERN int luasteam_music_SteamAPI_ISteamMusic_GetPlaybackStatus(lua_State *L) {
    lua_pushinteger(L, SteamMusic()->GetPlaybackStatus());
    return 1;
}

// void Play();
EXTERN int luasteam_music_SteamAPI_ISteamMusic_Play(lua_State *L) {
    SteamMusic()->Play();
    return 0;
}

// void Pause();
EXTERN int luasteam_music_SteamAPI_ISteamMusic_Pause(lua_State *L) {
    SteamMusic()->Pause();
    return 0;
}

// void PlayPrevious();
EXTERN int luasteam_music_SteamAPI_ISteamMusic_PlayPrevious(lua_State *L) {
    SteamMusic()->PlayPrevious();
    return 0;
}

// void PlayNext();
EXTERN int luasteam_music_SteamAPI_ISteamMusic_PlayNext(lua_State *L) {
    SteamMusic()->PlayNext();
    return 0;
}

void register_music_auto(lua_State *L) {
    add_func(L, "isEnabled", luasteam_music_SteamAPI_ISteamMusic_BIsEnabled);
    add_func(L, "isPlaying", luasteam_music_SteamAPI_ISteamMusic_BIsPlaying);
    add_func(L, "getPlaybackStatus", luasteam_music_SteamAPI_ISteamMusic_GetPlaybackStatus);
    add_func(L, "play", luasteam_music_SteamAPI_ISteamMusic_Play);
    add_func(L, "pause", luasteam_music_SteamAPI_ISteamMusic_Pause);
    add_func(L, "playPrevious", luasteam_music_SteamAPI_ISteamMusic_PlayPrevious);
    add_func(L, "playNext", luasteam_music_SteamAPI_ISteamMusic_PlayNext);
}

void add_music_auto(lua_State *L) {
    lua_createtable(L, 0, 7);
    register_music_auto(L);
    lua_pushvalue(L, -1);
    music_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "music");
}

} // namespace luasteam
