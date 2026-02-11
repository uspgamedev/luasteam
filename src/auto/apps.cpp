#include "auto.hpp"

namespace luasteam {

int apps_ref = LUA_NOREF;

namespace {

class CallbackListener {
  private:
    STEAM_CALLBACK(CallbackListener, OnDlcInstalled, DlcInstalled_t);
    STEAM_CALLBACK(CallbackListener, OnNewUrlLaunchParameters, NewUrlLaunchParameters_t);
    STEAM_CALLBACK(CallbackListener, OnAppProofOfPurchaseKeyResponse, AppProofOfPurchaseKeyResponse_t);
    STEAM_CALLBACK(CallbackListener, OnFileDetailsResult, FileDetailsResult_t);
    STEAM_CALLBACK(CallbackListener, OnTimedTrialStatus, TimedTrialStatus_t);
};

void CallbackListener::OnDlcInstalled(DlcInstalled_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::apps_ref);
    lua_getfield(L, -1, "onDlcInstalled");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushinteger(L, data->m_nAppID);
        lua_setfield(L, -2, "appID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnNewUrlLaunchParameters(NewUrlLaunchParameters_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::apps_ref);
    lua_getfield(L, -1, "onNewUrlLaunchParameters");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 0);
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnAppProofOfPurchaseKeyResponse(AppProofOfPurchaseKeyResponse_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::apps_ref);
    lua_getfield(L, -1, "onAppProofOfPurchaseKeyResponse");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        lua_pushinteger(L, data->m_nAppID);
        lua_setfield(L, -2, "appID");
        lua_pushinteger(L, data->m_cchKeyLength);
        lua_setfield(L, -2, "cchKeyLength");
        lua_pushstring(L, data->m_rgchKey);
        lua_setfield(L, -2, "key");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnFileDetailsResult(FileDetailsResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::apps_ref);
    lua_getfield(L, -1, "onFileDetailsResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_ulFileSize);
        lua_setfield(L, -2, "fileSize");
        lua_pushinteger(L, data->m_unFlags);
        lua_setfield(L, -2, "flags");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnTimedTrialStatus(TimedTrialStatus_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::apps_ref);
    lua_getfield(L, -1, "onTimedTrialStatus");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        lua_pushinteger(L, data->m_unAppID);
        lua_setfield(L, -2, "appID");
        lua_pushboolean(L, data->m_bIsOffline);
        lua_setfield(L, -2, "isOffline");
        lua_pushinteger(L, data->m_unSecondsAllowed);
        lua_setfield(L, -2, "secondsAllowed");
        lua_pushinteger(L, data->m_unSecondsPlayed);
        lua_setfield(L, -2, "secondsPlayed");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

CallbackListener *apps_listener = nullptr;

} // namespace

void init_apps_auto(lua_State *L) { apps_listener = new CallbackListener(); }

void shutdown_apps_auto(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, apps_ref);
    apps_ref = LUA_NOREF;
    delete apps_listener; apps_listener = nullptr;
}


// bool BIsSubscribed();
EXTERN int luasteam_apps_SteamAPI_ISteamApps_BIsSubscribed(lua_State *L) {
    lua_pushboolean(L, SteamApps()->BIsSubscribed());
    return 1;
}

// bool BIsLowViolence();
EXTERN int luasteam_apps_SteamAPI_ISteamApps_BIsLowViolence(lua_State *L) {
    lua_pushboolean(L, SteamApps()->BIsLowViolence());
    return 1;
}

// bool BIsCybercafe();
EXTERN int luasteam_apps_SteamAPI_ISteamApps_BIsCybercafe(lua_State *L) {
    lua_pushboolean(L, SteamApps()->BIsCybercafe());
    return 1;
}

// bool BIsVACBanned();
EXTERN int luasteam_apps_SteamAPI_ISteamApps_BIsVACBanned(lua_State *L) {
    lua_pushboolean(L, SteamApps()->BIsVACBanned());
    return 1;
}

// const char * GetCurrentGameLanguage();
EXTERN int luasteam_apps_SteamAPI_ISteamApps_GetCurrentGameLanguage(lua_State *L) {
    lua_pushstring(L, SteamApps()->GetCurrentGameLanguage());
    return 1;
}

// const char * GetAvailableGameLanguages();
EXTERN int luasteam_apps_SteamAPI_ISteamApps_GetAvailableGameLanguages(lua_State *L) {
    lua_pushstring(L, SteamApps()->GetAvailableGameLanguages());
    return 1;
}

// bool BIsSubscribedApp(AppId_t appID);
EXTERN int luasteam_apps_SteamAPI_ISteamApps_BIsSubscribedApp(lua_State *L) {
    AppId_t appID = static_cast<AppId_t>(luaL_checkint(L, 1));
    lua_pushboolean(L, SteamApps()->BIsSubscribedApp(appID));
    return 1;
}

// bool BIsDlcInstalled(AppId_t appID);
EXTERN int luasteam_apps_SteamAPI_ISteamApps_BIsDlcInstalled(lua_State *L) {
    AppId_t appID = static_cast<AppId_t>(luaL_checkint(L, 1));
    lua_pushboolean(L, SteamApps()->BIsDlcInstalled(appID));
    return 1;
}

// uint32 GetEarliestPurchaseUnixTime(AppId_t nAppID);
EXTERN int luasteam_apps_SteamAPI_ISteamApps_GetEarliestPurchaseUnixTime(lua_State *L) {
    AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
    lua_pushinteger(L, SteamApps()->GetEarliestPurchaseUnixTime(nAppID));
    return 1;
}

// bool BIsSubscribedFromFreeWeekend();
EXTERN int luasteam_apps_SteamAPI_ISteamApps_BIsSubscribedFromFreeWeekend(lua_State *L) {
    lua_pushboolean(L, SteamApps()->BIsSubscribedFromFreeWeekend());
    return 1;
}

// int GetDLCCount();
EXTERN int luasteam_apps_SteamAPI_ISteamApps_GetDLCCount(lua_State *L) {
    lua_pushinteger(L, SteamApps()->GetDLCCount());
    return 1;
}

// void InstallDLC(AppId_t nAppID);
EXTERN int luasteam_apps_SteamAPI_ISteamApps_InstallDLC(lua_State *L) {
    AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
    SteamApps()->InstallDLC(nAppID);
    return 0;
}

// void UninstallDLC(AppId_t nAppID);
EXTERN int luasteam_apps_SteamAPI_ISteamApps_UninstallDLC(lua_State *L) {
    AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
    SteamApps()->UninstallDLC(nAppID);
    return 0;
}

// void RequestAppProofOfPurchaseKey(AppId_t nAppID);
EXTERN int luasteam_apps_SteamAPI_ISteamApps_RequestAppProofOfPurchaseKey(lua_State *L) {
    AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
    SteamApps()->RequestAppProofOfPurchaseKey(nAppID);
    return 0;
}

// bool MarkContentCorrupt(bool bMissingFilesOnly);
EXTERN int luasteam_apps_SteamAPI_ISteamApps_MarkContentCorrupt(lua_State *L) {
    bool bMissingFilesOnly = lua_toboolean(L, 1);
    lua_pushboolean(L, SteamApps()->MarkContentCorrupt(bMissingFilesOnly));
    return 1;
}

// bool BIsAppInstalled(AppId_t appID);
EXTERN int luasteam_apps_SteamAPI_ISteamApps_BIsAppInstalled(lua_State *L) {
    AppId_t appID = static_cast<AppId_t>(luaL_checkint(L, 1));
    lua_pushboolean(L, SteamApps()->BIsAppInstalled(appID));
    return 1;
}

// CSteamID GetAppOwner();
EXTERN int luasteam_apps_SteamAPI_ISteamApps_GetAppOwner(lua_State *L) {
    luasteam::pushuint64(L, (SteamApps()->GetAppOwner()).ConvertToUint64());
    return 1;
}

// const char * GetLaunchQueryParam(const char * pchKey);
EXTERN int luasteam_apps_SteamAPI_ISteamApps_GetLaunchQueryParam(lua_State *L) {
    const char *pchKey = luaL_checkstring(L, 1);
    lua_pushstring(L, SteamApps()->GetLaunchQueryParam(pchKey));
    return 1;
}

// int GetAppBuildId();
EXTERN int luasteam_apps_SteamAPI_ISteamApps_GetAppBuildId(lua_State *L) {
    lua_pushinteger(L, SteamApps()->GetAppBuildId());
    return 1;
}

// void RequestAllProofOfPurchaseKeys();
EXTERN int luasteam_apps_SteamAPI_ISteamApps_RequestAllProofOfPurchaseKeys(lua_State *L) {
    SteamApps()->RequestAllProofOfPurchaseKeys();
    return 0;
}

// SteamAPICall_t GetFileDetails(const char * pszFileName);
EXTERN int luasteam_apps_SteamAPI_ISteamApps_GetFileDetails(lua_State *L) {
    const char *pszFileName = luaL_checkstring(L, 1);
    luasteam::pushuint64(L, SteamApps()->GetFileDetails(pszFileName));
    return 1;
}

// bool BIsSubscribedFromFamilySharing();
EXTERN int luasteam_apps_SteamAPI_ISteamApps_BIsSubscribedFromFamilySharing(lua_State *L) {
    lua_pushboolean(L, SteamApps()->BIsSubscribedFromFamilySharing());
    return 1;
}

// bool SetDlcContext(AppId_t nAppID);
EXTERN int luasteam_apps_SteamAPI_ISteamApps_SetDlcContext(lua_State *L) {
    AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
    lua_pushboolean(L, SteamApps()->SetDlcContext(nAppID));
    return 1;
}

// bool SetActiveBeta(const char * pchBetaName);
EXTERN int luasteam_apps_SteamAPI_ISteamApps_SetActiveBeta(lua_State *L) {
    const char *pchBetaName = luaL_checkstring(L, 1);
    lua_pushboolean(L, SteamApps()->SetActiveBeta(pchBetaName));
    return 1;
}

void register_apps_auto(lua_State *L) {
    add_func(L, "isSubscribed", luasteam_apps_SteamAPI_ISteamApps_BIsSubscribed);
    add_func(L, "isLowViolence", luasteam_apps_SteamAPI_ISteamApps_BIsLowViolence);
    add_func(L, "isCybercafe", luasteam_apps_SteamAPI_ISteamApps_BIsCybercafe);
    add_func(L, "isVACBanned", luasteam_apps_SteamAPI_ISteamApps_BIsVACBanned);
    add_func(L, "getCurrentGameLanguage", luasteam_apps_SteamAPI_ISteamApps_GetCurrentGameLanguage);
    add_func(L, "getAvailableGameLanguages", luasteam_apps_SteamAPI_ISteamApps_GetAvailableGameLanguages);
    add_func(L, "isSubscribedApp", luasteam_apps_SteamAPI_ISteamApps_BIsSubscribedApp);
    add_func(L, "isDlcInstalled", luasteam_apps_SteamAPI_ISteamApps_BIsDlcInstalled);
    add_func(L, "getEarliestPurchaseUnixTime", luasteam_apps_SteamAPI_ISteamApps_GetEarliestPurchaseUnixTime);
    add_func(L, "isSubscribedFromFreeWeekend", luasteam_apps_SteamAPI_ISteamApps_BIsSubscribedFromFreeWeekend);
    add_func(L, "getDLCCount", luasteam_apps_SteamAPI_ISteamApps_GetDLCCount);
    add_func(L, "installDLC", luasteam_apps_SteamAPI_ISteamApps_InstallDLC);
    add_func(L, "uninstallDLC", luasteam_apps_SteamAPI_ISteamApps_UninstallDLC);
    add_func(L, "requestAppProofOfPurchaseKey", luasteam_apps_SteamAPI_ISteamApps_RequestAppProofOfPurchaseKey);
    add_func(L, "markContentCorrupt", luasteam_apps_SteamAPI_ISteamApps_MarkContentCorrupt);
    add_func(L, "isAppInstalled", luasteam_apps_SteamAPI_ISteamApps_BIsAppInstalled);
    add_func(L, "getAppOwner", luasteam_apps_SteamAPI_ISteamApps_GetAppOwner);
    add_func(L, "getLaunchQueryParam", luasteam_apps_SteamAPI_ISteamApps_GetLaunchQueryParam);
    add_func(L, "getAppBuildId", luasteam_apps_SteamAPI_ISteamApps_GetAppBuildId);
    add_func(L, "requestAllProofOfPurchaseKeys", luasteam_apps_SteamAPI_ISteamApps_RequestAllProofOfPurchaseKeys);
    add_func(L, "getFileDetails", luasteam_apps_SteamAPI_ISteamApps_GetFileDetails);
    add_func(L, "isSubscribedFromFamilySharing", luasteam_apps_SteamAPI_ISteamApps_BIsSubscribedFromFamilySharing);
    add_func(L, "setDlcContext", luasteam_apps_SteamAPI_ISteamApps_SetDlcContext);
    add_func(L, "setActiveBeta", luasteam_apps_SteamAPI_ISteamApps_SetActiveBeta);
}

void add_apps_auto(lua_State *L) {
    lua_createtable(L, 0, 24);
    register_apps_auto(L);
    lua_pushvalue(L, -1);
    apps_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "apps");
}

} // namespace luasteam
