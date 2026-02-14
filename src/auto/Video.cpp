#include "auto.hpp"

namespace luasteam {

int Video_ref = LUA_NOREF;

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
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Video_ref);
    lua_getfield(L, -1, "OnGetVideoURLResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "m_eResult");
        lua_pushinteger(L, data->m_unVideoAppID);
        lua_setfield(L, -2, "m_unVideoAppID");
        lua_pushstring(L, reinterpret_cast<const char*>(data->m_rgchURL));
        lua_setfield(L, -2, "m_rgchURL");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGetOPFSettingsResult(GetOPFSettingsResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Video_ref);
    lua_getfield(L, -1, "OnGetOPFSettingsResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "m_eResult");
        lua_pushinteger(L, data->m_unVideoAppID);
        lua_setfield(L, -2, "m_unVideoAppID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnBroadcastUploadStart(BroadcastUploadStart_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Video_ref);
    lua_getfield(L, -1, "OnBroadcastUploadStart");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushboolean(L, data->m_bIsRTMP);
        lua_setfield(L, -2, "m_bIsRTMP");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnBroadcastUploadStop(BroadcastUploadStop_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Video_ref);
    lua_getfield(L, -1, "OnBroadcastUploadStop");
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

CallbackListener *Video_listener = nullptr;

} // namespace

void init_Video_auto(lua_State *L) { Video_listener = new CallbackListener(); }

void shutdown_Video_auto(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, Video_ref);
    Video_ref = LUA_NOREF;
    delete Video_listener; Video_listener = nullptr;
}


// void GetVideoURL(AppId_t unVideoAppID);
EXTERN int luasteam_Video_GetVideoURL(lua_State *L) {
    AppId_t unVideoAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
    SteamVideo()->GetVideoURL(unVideoAppID);
    return 0;
}

// bool IsBroadcasting(int * pnNumViewers);
EXTERN int luasteam_Video_IsBroadcasting(lua_State *L) {
    int pnNumViewers;    bool __ret = SteamVideo()->IsBroadcasting(&pnNumViewers);
    lua_pushboolean(L, __ret);
    lua_pushinteger(L, pnNumViewers);
    return 2;
}

// void GetOPFSettings(AppId_t unVideoAppID);
EXTERN int luasteam_Video_GetOPFSettings(lua_State *L) {
    AppId_t unVideoAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
    SteamVideo()->GetOPFSettings(unVideoAppID);
    return 0;
}

// bool GetOPFStringForApp(AppId_t unVideoAppID, char * pchBuffer, int32 * pnBufferSize);
EXTERN int luasteam_Video_GetOPFStringForApp(lua_State *L) {
    AppId_t unVideoAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
    int32 * pnBufferSize = luaL_checkint(L, 2);
    std::vector<char> pchBuffer(pnBufferSize);
    bool __ret = SteamVideo()->GetOPFStringForApp(unVideoAppID, pchBuffer.data(), &pnBufferSize);
    lua_pushboolean(L, __ret);
    lua_pushstring(L, reinterpret_cast<const char*>(pchBuffer.data()));
    lua_pushinteger(L, pnBufferSize);
    return 2;
}

void register_Video_auto(lua_State *L) {
    add_func(L, "GetVideoURL", luasteam_Video_GetVideoURL);
    add_func(L, "IsBroadcasting", luasteam_Video_IsBroadcasting);
    add_func(L, "GetOPFSettings", luasteam_Video_GetOPFSettings);
    add_func(L, "GetOPFStringForApp", luasteam_Video_GetOPFStringForApp);
}

void add_Video_auto(lua_State *L) {
    lua_createtable(L, 0, 4);
    register_Video_auto(L);
    lua_pushvalue(L, -1);
    Video_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "Video");
}

} // namespace luasteam
