#include "auto.hpp"

namespace luasteam {

int video_ref = LUA_NOREF;

namespace {

class CallbackListener {
  private:
    STEAM_CALLBACK(CallbackListener, OnGetVideoURLResult, GetVideoURLResult_t);
    STEAM_CALLBACK(CallbackListener, OnGetOPFSettingsResult, GetOPFSettingsResult_t);
    STEAM_CALLBACK(CallbackListener, OnBroadcastUploadStart, BroadcastUploadStart_t);
    STEAM_CALLBACK(CallbackListener, OnBroadcastUploadStop, BroadcastUploadStop_t);
};

void CallbackListener::OnGetVideoURLResult(GetVideoURLResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::video_ref);
    lua_getfield(L, -1, "onGetVideoURLResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        lua_pushinteger(L, data->m_unVideoAppID);
        lua_setfield(L, -2, "videoAppID");
        lua_pushstring(L, data->m_rgchURL);
        lua_setfield(L, -2, "uRL");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGetOPFSettingsResult(GetOPFSettingsResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::video_ref);
    lua_getfield(L, -1, "onGetOPFSettingsResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        lua_pushinteger(L, data->m_unVideoAppID);
        lua_setfield(L, -2, "videoAppID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnBroadcastUploadStart(BroadcastUploadStart_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::video_ref);
    lua_getfield(L, -1, "onBroadcastUploadStart");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushboolean(L, data->m_bIsRTMP);
        lua_setfield(L, -2, "isRTMP");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnBroadcastUploadStop(BroadcastUploadStop_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::video_ref);
    lua_getfield(L, -1, "onBroadcastUploadStop");
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

CallbackListener *video_listener = nullptr;

} // namespace

void init_video_auto(lua_State *L) { video_listener = new CallbackListener(); }

void shutdown_video_auto(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, video_ref);
    video_ref = LUA_NOREF;
    delete video_listener; video_listener = nullptr;
}


// void GetVideoURL(AppId_t unVideoAppID);
EXTERN int luasteam_video_SteamAPI_ISteamVideo_GetVideoURL(lua_State *L) {
    AppId_t unVideoAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
    SteamVideo()->GetVideoURL(unVideoAppID);
    return 0;
}

// void GetOPFSettings(AppId_t unVideoAppID);
EXTERN int luasteam_video_SteamAPI_ISteamVideo_GetOPFSettings(lua_State *L) {
    AppId_t unVideoAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
    SteamVideo()->GetOPFSettings(unVideoAppID);
    return 0;
}

void register_video_auto(lua_State *L) {
    add_func(L, "getVideoURL", luasteam_video_SteamAPI_ISteamVideo_GetVideoURL);
    add_func(L, "getOPFSettings", luasteam_video_SteamAPI_ISteamVideo_GetOPFSettings);
}

void add_video_auto(lua_State *L) {
    lua_createtable(L, 0, 2);
    register_video_auto(L);
    lua_pushvalue(L, -1);
    video_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "video");
}

} // namespace luasteam
