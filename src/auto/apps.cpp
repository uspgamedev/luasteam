#include "auto.hpp"

namespace luasteam {

int Apps_ref = LUA_NOREF;

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
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Apps_ref);
    lua_getfield(L, -1, "OnDlcInstalled");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushinteger(L, data->m_nAppID);
        lua_setfield(L, -2, "m_nAppID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnNewUrlLaunchParameters(NewUrlLaunchParameters_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Apps_ref);
    lua_getfield(L, -1, "OnNewUrlLaunchParameters");
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
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Apps_ref);
    lua_getfield(L, -1, "OnAppProofOfPurchaseKeyResponse");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "m_eResult");
        lua_pushinteger(L, data->m_nAppID);
        lua_setfield(L, -2, "m_nAppID");
        lua_pushinteger(L, data->m_cchKeyLength);
        lua_setfield(L, -2, "m_cchKeyLength");
        // Skip unsupported type: char [240]
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnFileDetailsResult(FileDetailsResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Apps_ref);
    lua_getfield(L, -1, "OnFileDetailsResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "m_eResult");
        luasteam::pushuint64(L, data->m_ulFileSize);
        lua_setfield(L, -2, "m_ulFileSize");
        // Skip unsupported type: uint8 [20]
        lua_pushinteger(L, data->m_unFlags);
        lua_setfield(L, -2, "m_unFlags");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnTimedTrialStatus(TimedTrialStatus_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Apps_ref);
    lua_getfield(L, -1, "OnTimedTrialStatus");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        lua_pushinteger(L, data->m_unAppID);
        lua_setfield(L, -2, "m_unAppID");
        lua_pushboolean(L, data->m_bIsOffline);
        lua_setfield(L, -2, "m_bIsOffline");
        lua_pushinteger(L, data->m_unSecondsAllowed);
        lua_setfield(L, -2, "m_unSecondsAllowed");
        lua_pushinteger(L, data->m_unSecondsPlayed);
        lua_setfield(L, -2, "m_unSecondsPlayed");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

CallbackListener *Apps_listener = nullptr;

} // namespace

void init_Apps_auto(lua_State *L) { Apps_listener = new CallbackListener(); }

void shutdown_Apps_auto(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, Apps_ref);
    Apps_ref = LUA_NOREF;
    delete Apps_listener; Apps_listener = nullptr;
}


// bool BIsSubscribed();
EXTERN int luasteam_Apps_BIsSubscribed(lua_State *L) {
    lua_pushboolean(L, SteamApps()->BIsSubscribed());
    return 1;
}

// bool BIsLowViolence();
EXTERN int luasteam_Apps_BIsLowViolence(lua_State *L) {
    lua_pushboolean(L, SteamApps()->BIsLowViolence());
    return 1;
}

// bool BIsCybercafe();
EXTERN int luasteam_Apps_BIsCybercafe(lua_State *L) {
    lua_pushboolean(L, SteamApps()->BIsCybercafe());
    return 1;
}

// bool BIsVACBanned();
EXTERN int luasteam_Apps_BIsVACBanned(lua_State *L) {
    lua_pushboolean(L, SteamApps()->BIsVACBanned());
    return 1;
}

// const char * GetCurrentGameLanguage();
EXTERN int luasteam_Apps_GetCurrentGameLanguage(lua_State *L) {
    lua_pushstring(L, SteamApps()->GetCurrentGameLanguage());
    return 1;
}

// const char * GetAvailableGameLanguages();
EXTERN int luasteam_Apps_GetAvailableGameLanguages(lua_State *L) {
    lua_pushstring(L, SteamApps()->GetAvailableGameLanguages());
    return 1;
}

// bool BIsSubscribedApp(AppId_t appID);
EXTERN int luasteam_Apps_BIsSubscribedApp(lua_State *L) {
    AppId_t appID = static_cast<AppId_t>(luaL_checkint(L, 1));
    lua_pushboolean(L, SteamApps()->BIsSubscribedApp(appID));
    return 1;
}

// bool BIsDlcInstalled(AppId_t appID);
EXTERN int luasteam_Apps_BIsDlcInstalled(lua_State *L) {
    AppId_t appID = static_cast<AppId_t>(luaL_checkint(L, 1));
    lua_pushboolean(L, SteamApps()->BIsDlcInstalled(appID));
    return 1;
}

// uint32 GetEarliestPurchaseUnixTime(AppId_t nAppID);
EXTERN int luasteam_Apps_GetEarliestPurchaseUnixTime(lua_State *L) {
    AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
    lua_pushinteger(L, SteamApps()->GetEarliestPurchaseUnixTime(nAppID));
    return 1;
}

// bool BIsSubscribedFromFreeWeekend();
EXTERN int luasteam_Apps_BIsSubscribedFromFreeWeekend(lua_State *L) {
    lua_pushboolean(L, SteamApps()->BIsSubscribedFromFreeWeekend());
    return 1;
}

// int GetDLCCount();
EXTERN int luasteam_Apps_GetDLCCount(lua_State *L) {
    lua_pushinteger(L, SteamApps()->GetDLCCount());
    return 1;
}

// void InstallDLC(AppId_t nAppID);
EXTERN int luasteam_Apps_InstallDLC(lua_State *L) {
    AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
    SteamApps()->InstallDLC(nAppID);
    return 0;
}

// void UninstallDLC(AppId_t nAppID);
EXTERN int luasteam_Apps_UninstallDLC(lua_State *L) {
    AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
    SteamApps()->UninstallDLC(nAppID);
    return 0;
}

// void RequestAppProofOfPurchaseKey(AppId_t nAppID);
EXTERN int luasteam_Apps_RequestAppProofOfPurchaseKey(lua_State *L) {
    AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
    SteamApps()->RequestAppProofOfPurchaseKey(nAppID);
    return 0;
}

// bool MarkContentCorrupt(bool bMissingFilesOnly);
EXTERN int luasteam_Apps_MarkContentCorrupt(lua_State *L) {
    bool bMissingFilesOnly = lua_toboolean(L, 1);
    lua_pushboolean(L, SteamApps()->MarkContentCorrupt(bMissingFilesOnly));
    return 1;
}

// bool BIsAppInstalled(AppId_t appID);
EXTERN int luasteam_Apps_BIsAppInstalled(lua_State *L) {
    AppId_t appID = static_cast<AppId_t>(luaL_checkint(L, 1));
    lua_pushboolean(L, SteamApps()->BIsAppInstalled(appID));
    return 1;
}

// CSteamID GetAppOwner();
EXTERN int luasteam_Apps_GetAppOwner(lua_State *L) {
    luasteam::pushuint64(L, SteamApps()->GetAppOwner().ConvertToUint64());
    return 1;
}

// const char * GetLaunchQueryParam(const char * pchKey);
EXTERN int luasteam_Apps_GetLaunchQueryParam(lua_State *L) {
    const char *pchKey = luaL_checkstring(L, 1);
    lua_pushstring(L, SteamApps()->GetLaunchQueryParam(pchKey));
    return 1;
}

// bool GetDlcDownloadProgress(AppId_t nAppID, uint64 * punBytesDownloaded, uint64 * punBytesTotal);
EXTERN int luasteam_Apps_GetDlcDownloadProgress(lua_State *L) {
    AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
    uint64 punBytesDownloaded;    uint64 punBytesTotal;    lua_pushboolean(L, SteamApps()->GetDlcDownloadProgress(nAppID, &punBytesDownloaded, &punBytesTotal));
    luasteam::pushuint64(L, punBytesDownloaded);
    luasteam::pushuint64(L, punBytesTotal);
    return 3;
}

// int GetAppBuildId();
EXTERN int luasteam_Apps_GetAppBuildId(lua_State *L) {
    lua_pushinteger(L, SteamApps()->GetAppBuildId());
    return 1;
}

// void RequestAllProofOfPurchaseKeys();
EXTERN int luasteam_Apps_RequestAllProofOfPurchaseKeys(lua_State *L) {
    SteamApps()->RequestAllProofOfPurchaseKeys();
    return 0;
}

// SteamAPICall_t GetFileDetails(const char * pszFileName);
EXTERN int luasteam_Apps_GetFileDetails(lua_State *L) {
    const char *pszFileName = luaL_checkstring(L, 1);
    luasteam::pushuint64(L, SteamApps()->GetFileDetails(pszFileName));
    return 1;
}

// bool BIsSubscribedFromFamilySharing();
EXTERN int luasteam_Apps_BIsSubscribedFromFamilySharing(lua_State *L) {
    lua_pushboolean(L, SteamApps()->BIsSubscribedFromFamilySharing());
    return 1;
}

// bool BIsTimedTrial(uint32 * punSecondsAllowed, uint32 * punSecondsPlayed);
EXTERN int luasteam_Apps_BIsTimedTrial(lua_State *L) {
    uint32 punSecondsAllowed;    uint32 punSecondsPlayed;    lua_pushboolean(L, SteamApps()->BIsTimedTrial(&punSecondsAllowed, &punSecondsPlayed));
    lua_pushinteger(L, punSecondsAllowed);
    lua_pushinteger(L, punSecondsPlayed);
    return 3;
}

// bool SetDlcContext(AppId_t nAppID);
EXTERN int luasteam_Apps_SetDlcContext(lua_State *L) {
    AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
    lua_pushboolean(L, SteamApps()->SetDlcContext(nAppID));
    return 1;
}

// int GetNumBetas(int * pnAvailable, int * pnPrivate);
EXTERN int luasteam_Apps_GetNumBetas(lua_State *L) {
    int pnAvailable;    int pnPrivate;    lua_pushinteger(L, SteamApps()->GetNumBetas(&pnAvailable, &pnPrivate));
    lua_pushinteger(L, pnAvailable);
    lua_pushinteger(L, pnPrivate);
    return 3;
}

// bool SetActiveBeta(const char * pchBetaName);
EXTERN int luasteam_Apps_SetActiveBeta(lua_State *L) {
    const char *pchBetaName = luaL_checkstring(L, 1);
    lua_pushboolean(L, SteamApps()->SetActiveBeta(pchBetaName));
    return 1;
}

void register_Apps_auto(lua_State *L) {
    add_func(L, "BIsSubscribed", luasteam_Apps_BIsSubscribed);
    add_func(L, "BIsLowViolence", luasteam_Apps_BIsLowViolence);
    add_func(L, "BIsCybercafe", luasteam_Apps_BIsCybercafe);
    add_func(L, "BIsVACBanned", luasteam_Apps_BIsVACBanned);
    add_func(L, "GetCurrentGameLanguage", luasteam_Apps_GetCurrentGameLanguage);
    add_func(L, "GetAvailableGameLanguages", luasteam_Apps_GetAvailableGameLanguages);
    add_func(L, "BIsSubscribedApp", luasteam_Apps_BIsSubscribedApp);
    add_func(L, "BIsDlcInstalled", luasteam_Apps_BIsDlcInstalled);
    add_func(L, "GetEarliestPurchaseUnixTime", luasteam_Apps_GetEarliestPurchaseUnixTime);
    add_func(L, "BIsSubscribedFromFreeWeekend", luasteam_Apps_BIsSubscribedFromFreeWeekend);
    add_func(L, "GetDLCCount", luasteam_Apps_GetDLCCount);
    add_func(L, "InstallDLC", luasteam_Apps_InstallDLC);
    add_func(L, "UninstallDLC", luasteam_Apps_UninstallDLC);
    add_func(L, "RequestAppProofOfPurchaseKey", luasteam_Apps_RequestAppProofOfPurchaseKey);
    add_func(L, "MarkContentCorrupt", luasteam_Apps_MarkContentCorrupt);
    add_func(L, "BIsAppInstalled", luasteam_Apps_BIsAppInstalled);
    add_func(L, "GetAppOwner", luasteam_Apps_GetAppOwner);
    add_func(L, "GetLaunchQueryParam", luasteam_Apps_GetLaunchQueryParam);
    add_func(L, "GetDlcDownloadProgress", luasteam_Apps_GetDlcDownloadProgress);
    add_func(L, "GetAppBuildId", luasteam_Apps_GetAppBuildId);
    add_func(L, "RequestAllProofOfPurchaseKeys", luasteam_Apps_RequestAllProofOfPurchaseKeys);
    add_func(L, "GetFileDetails", luasteam_Apps_GetFileDetails);
    add_func(L, "BIsSubscribedFromFamilySharing", luasteam_Apps_BIsSubscribedFromFamilySharing);
    add_func(L, "BIsTimedTrial", luasteam_Apps_BIsTimedTrial);
    add_func(L, "SetDlcContext", luasteam_Apps_SetDlcContext);
    add_func(L, "GetNumBetas", luasteam_Apps_GetNumBetas);
    add_func(L, "SetActiveBeta", luasteam_Apps_SetActiveBeta);
}

void add_Apps_auto(lua_State *L) {
    lua_createtable(L, 0, 27);
    register_Apps_auto(L);
    lua_pushvalue(L, -1);
    Apps_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "Apps");
}

} // namespace luasteam
