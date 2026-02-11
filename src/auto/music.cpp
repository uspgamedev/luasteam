#include "auto.hpp"

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

namespace luasteam {

void add_music_auto(lua_State *L) {
    add_func(L, "isEnabled", luasteam_music_SteamAPI_ISteamMusic_BIsEnabled);
    add_func(L, "isPlaying", luasteam_music_SteamAPI_ISteamMusic_BIsPlaying);
    add_func(L, "getPlaybackStatus", luasteam_music_SteamAPI_ISteamMusic_GetPlaybackStatus);
    add_func(L, "play", luasteam_music_SteamAPI_ISteamMusic_Play);
    add_func(L, "pause", luasteam_music_SteamAPI_ISteamMusic_Pause);
    add_func(L, "playPrevious", luasteam_music_SteamAPI_ISteamMusic_PlayPrevious);
    add_func(L, "playNext", luasteam_music_SteamAPI_ISteamMusic_PlayNext);
}

} // namespace luasteam
