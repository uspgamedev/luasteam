#include "auto.hpp"

namespace luasteam {

int Apps_ref = LUA_NOREF;

namespace {
class AppsCallbackListener {
private:
	STEAM_CALLBACK(AppsCallbackListener, OnDlcInstalled, DlcInstalled_t);
	STEAM_CALLBACK(AppsCallbackListener, OnNewUrlLaunchParameters, NewUrlLaunchParameters_t);
	STEAM_CALLBACK(AppsCallbackListener, OnAppProofOfPurchaseKeyResponse, AppProofOfPurchaseKeyResponse_t);
	STEAM_CALLBACK(AppsCallbackListener, OnFileDetailsResult, FileDetailsResult_t);
	STEAM_CALLBACK(AppsCallbackListener, OnTimedTrialStatus, TimedTrialStatus_t);
};
void AppsCallbackListener::OnDlcInstalled(DlcInstalled_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Apps_ref);
	lua_getfield(L, -1, "OnDlcInstalled");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_DlcInstalled_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void AppsCallbackListener::OnNewUrlLaunchParameters(NewUrlLaunchParameters_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Apps_ref);
	lua_getfield(L, -1, "OnNewUrlLaunchParameters");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_NewUrlLaunchParameters_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void AppsCallbackListener::OnAppProofOfPurchaseKeyResponse(AppProofOfPurchaseKeyResponse_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Apps_ref);
	lua_getfield(L, -1, "OnAppProofOfPurchaseKeyResponse");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_AppProofOfPurchaseKeyResponse_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void AppsCallbackListener::OnFileDetailsResult(FileDetailsResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Apps_ref);
	lua_getfield(L, -1, "OnFileDetailsResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_FileDetailsResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void AppsCallbackListener::OnTimedTrialStatus(TimedTrialStatus_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Apps_ref);
	lua_getfield(L, -1, "OnTimedTrialStatus");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_TimedTrialStatus_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
AppsCallbackListener *Apps_listener = nullptr;
} // namespace

void init_Apps_auto(lua_State *L) { Apps_listener = new AppsCallbackListener(); }
void shutdown_Apps_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, Apps_ref);
	Apps_ref = LUA_NOREF;
	delete Apps_listener; Apps_listener = nullptr;
}

template <> void CallResultListener<FileDetailsResult_t>::Result(FileDetailsResult_t *data, bool io_fail) {
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
		lua_createtable(L, 0, 4);
		lua_pushinteger(L, data->m_eResult);
		lua_setfield(L, -2, "m_eResult");
		luasteam::pushuint64(L, data->m_ulFileSize);
		lua_setfield(L, -2, "m_ulFileSize");
		lua_pushlstring(L, reinterpret_cast<const char*>(data->m_FileSHA), 20);
		lua_setfield(L, -2, "m_FileSHA");
		lua_pushinteger(L, data->m_unFlags);
		lua_setfield(L, -2, "m_unFlags");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

// In C++:
// bool BIsSubscribed();
// In Lua:
// bool Apps.BIsSubscribed()
static int luasteam_Apps_BIsSubscribed(lua_State *L) {
	auto *iface = SteamApps();
	bool __ret = iface->BIsSubscribed();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool BIsLowViolence();
// In Lua:
// bool Apps.BIsLowViolence()
static int luasteam_Apps_BIsLowViolence(lua_State *L) {
	auto *iface = SteamApps();
	bool __ret = iface->BIsLowViolence();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool BIsCybercafe();
// In Lua:
// bool Apps.BIsCybercafe()
static int luasteam_Apps_BIsCybercafe(lua_State *L) {
	auto *iface = SteamApps();
	bool __ret = iface->BIsCybercafe();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool BIsVACBanned();
// In Lua:
// bool Apps.BIsVACBanned()
static int luasteam_Apps_BIsVACBanned(lua_State *L) {
	auto *iface = SteamApps();
	bool __ret = iface->BIsVACBanned();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// const char * GetCurrentGameLanguage();
// In Lua:
// str Apps.GetCurrentGameLanguage()
static int luasteam_Apps_GetCurrentGameLanguage(lua_State *L) {
	auto *iface = SteamApps();
	const char * __ret = iface->GetCurrentGameLanguage();
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// const char * GetAvailableGameLanguages();
// In Lua:
// str Apps.GetAvailableGameLanguages()
static int luasteam_Apps_GetAvailableGameLanguages(lua_State *L) {
	auto *iface = SteamApps();
	const char * __ret = iface->GetAvailableGameLanguages();
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// bool BIsSubscribedApp(AppId_t appID);
// In Lua:
// bool Apps.BIsSubscribedApp(appID: int)
static int luasteam_Apps_BIsSubscribedApp(lua_State *L) {
	auto *iface = SteamApps();
	AppId_t appID = static_cast<AppId_t>(luaL_checkint(L, 1));
	bool __ret = iface->BIsSubscribedApp(appID);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool BIsDlcInstalled(AppId_t appID);
// In Lua:
// bool Apps.BIsDlcInstalled(appID: int)
static int luasteam_Apps_BIsDlcInstalled(lua_State *L) {
	auto *iface = SteamApps();
	AppId_t appID = static_cast<AppId_t>(luaL_checkint(L, 1));
	bool __ret = iface->BIsDlcInstalled(appID);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// uint32 GetEarliestPurchaseUnixTime(AppId_t nAppID);
// In Lua:
// int Apps.GetEarliestPurchaseUnixTime(nAppID: int)
static int luasteam_Apps_GetEarliestPurchaseUnixTime(lua_State *L) {
	auto *iface = SteamApps();
	AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
	uint32 __ret = iface->GetEarliestPurchaseUnixTime(nAppID);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool BIsSubscribedFromFreeWeekend();
// In Lua:
// bool Apps.BIsSubscribedFromFreeWeekend()
static int luasteam_Apps_BIsSubscribedFromFreeWeekend(lua_State *L) {
	auto *iface = SteamApps();
	bool __ret = iface->BIsSubscribedFromFreeWeekend();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// int GetDLCCount();
// In Lua:
// int Apps.GetDLCCount()
static int luasteam_Apps_GetDLCCount(lua_State *L) {
	auto *iface = SteamApps();
	int __ret = iface->GetDLCCount();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool BGetDLCDataByIndex(int iDLC, AppId_t * pAppID, bool * pbAvailable, char * pchName, int cchNameBufferSize);
// In Lua:
// (bool, pAppID: int, pbAvailable: bool, pchName: str) Apps.BGetDLCDataByIndex(iDLC: int, cchNameBufferSize: int)
static int luasteam_Apps_BGetDLCDataByIndex(lua_State *L) {
	auto *iface = SteamApps();
	int iDLC = static_cast<int>(luaL_checkint(L, 1));
	AppId_t pAppID;
	bool pbAvailable;
	int cchNameBufferSize = luaL_checkint(L, 2);
	std::vector<char> pchName(cchNameBufferSize);
	bool __ret = iface->BGetDLCDataByIndex(iDLC, &pAppID, &pbAvailable, pchName.data(), cchNameBufferSize);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pAppID);
	lua_pushboolean(L, pbAvailable);
	lua_pushstring(L, reinterpret_cast<const char*>(pchName.data()));
	return 4;
}

// In C++:
// void InstallDLC(AppId_t nAppID);
// In Lua:
// Apps.InstallDLC(nAppID: int)
static int luasteam_Apps_InstallDLC(lua_State *L) {
	auto *iface = SteamApps();
	AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
	iface->InstallDLC(nAppID);
	return 0;
}

// In C++:
// void UninstallDLC(AppId_t nAppID);
// In Lua:
// Apps.UninstallDLC(nAppID: int)
static int luasteam_Apps_UninstallDLC(lua_State *L) {
	auto *iface = SteamApps();
	AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
	iface->UninstallDLC(nAppID);
	return 0;
}

// In C++:
// void RequestAppProofOfPurchaseKey(AppId_t nAppID);
// In Lua:
// Apps.RequestAppProofOfPurchaseKey(nAppID: int)
static int luasteam_Apps_RequestAppProofOfPurchaseKey(lua_State *L) {
	auto *iface = SteamApps();
	AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
	iface->RequestAppProofOfPurchaseKey(nAppID);
	return 0;
}

// In C++:
// bool GetCurrentBetaName(char * pchName, int cchNameBufferSize);
// In Lua:
// (bool, pchName: str) Apps.GetCurrentBetaName(cchNameBufferSize: int)
static int luasteam_Apps_GetCurrentBetaName(lua_State *L) {
	auto *iface = SteamApps();
	int cchNameBufferSize = luaL_checkint(L, 1);
	std::vector<char> pchName(cchNameBufferSize);
	bool __ret = iface->GetCurrentBetaName(pchName.data(), cchNameBufferSize);
	lua_pushboolean(L, __ret);
	lua_pushstring(L, reinterpret_cast<const char*>(pchName.data()));
	return 2;
}

// In C++:
// bool MarkContentCorrupt(bool bMissingFilesOnly);
// In Lua:
// bool Apps.MarkContentCorrupt(bMissingFilesOnly: bool)
static int luasteam_Apps_MarkContentCorrupt(lua_State *L) {
	auto *iface = SteamApps();
	bool bMissingFilesOnly = lua_toboolean(L, 1);
	bool __ret = iface->MarkContentCorrupt(bMissingFilesOnly);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// uint32 GetInstalledDepots(AppId_t appID, DepotId_t * pvecDepots, uint32 cMaxDepots);
// In Lua:
// (int, pvecDepots: int[]) Apps.GetInstalledDepots(appID: int, cMaxDepots: int)
static int luasteam_Apps_GetInstalledDepots(lua_State *L) {
	auto *iface = SteamApps();
	AppId_t appID = static_cast<AppId_t>(luaL_checkint(L, 1));
	uint32 cMaxDepots = luaL_checkint(L, 2);
	std::vector<DepotId_t> pvecDepots(cMaxDepots);
	uint32 __ret = iface->GetInstalledDepots(appID, pvecDepots.data(), cMaxDepots);
	lua_pushinteger(L, __ret);
	lua_createtable(L, __ret, 0);
	for(decltype(__ret) i = 0; i < __ret; i++) {
		lua_pushinteger(L, pvecDepots[i]);
		lua_rawseti(L, -2, i+1);
	}
	return 2;
}

// In C++:
// uint32 GetAppInstallDir(AppId_t appID, char * pchFolder, uint32 cchFolderBufferSize);
// In Lua:
// (int, pchFolder: str) Apps.GetAppInstallDir(appID: int, cchFolderBufferSize: int)
static int luasteam_Apps_GetAppInstallDir(lua_State *L) {
	auto *iface = SteamApps();
	AppId_t appID = static_cast<AppId_t>(luaL_checkint(L, 1));
	uint32 cchFolderBufferSize = luaL_checkint(L, 2);
	std::vector<char> pchFolder(cchFolderBufferSize);
	uint32 __ret = iface->GetAppInstallDir(appID, pchFolder.data(), cchFolderBufferSize);
	lua_pushinteger(L, __ret);
	lua_pushstring(L, reinterpret_cast<const char*>(pchFolder.data()));
	return 2;
}

// In C++:
// bool BIsAppInstalled(AppId_t appID);
// In Lua:
// bool Apps.BIsAppInstalled(appID: int)
static int luasteam_Apps_BIsAppInstalled(lua_State *L) {
	auto *iface = SteamApps();
	AppId_t appID = static_cast<AppId_t>(luaL_checkint(L, 1));
	bool __ret = iface->BIsAppInstalled(appID);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// CSteamID GetAppOwner();
// In Lua:
// uint64 Apps.GetAppOwner()
static int luasteam_Apps_GetAppOwner(lua_State *L) {
	auto *iface = SteamApps();
	CSteamID __ret = iface->GetAppOwner();
	luasteam::pushuint64(L, __ret.ConvertToUint64());
	return 1;
}

// In C++:
// const char * GetLaunchQueryParam(const char * pchKey);
// In Lua:
// str Apps.GetLaunchQueryParam(pchKey: str)
static int luasteam_Apps_GetLaunchQueryParam(lua_State *L) {
	auto *iface = SteamApps();
	const char *pchKey = luaL_checkstring(L, 1);
	const char * __ret = iface->GetLaunchQueryParam(pchKey);
	lua_pushstring(L, reinterpret_cast<const char*>(__ret));
	return 1;
}

// In C++:
// bool GetDlcDownloadProgress(AppId_t nAppID, uint64 * punBytesDownloaded, uint64 * punBytesTotal);
// In Lua:
// (bool, punBytesDownloaded: uint64, punBytesTotal: uint64) Apps.GetDlcDownloadProgress(nAppID: int)
static int luasteam_Apps_GetDlcDownloadProgress(lua_State *L) {
	auto *iface = SteamApps();
	AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
	uint64 punBytesDownloaded;
	uint64 punBytesTotal;
	bool __ret = iface->GetDlcDownloadProgress(nAppID, &punBytesDownloaded, &punBytesTotal);
	lua_pushboolean(L, __ret);
	luasteam::pushuint64(L, punBytesDownloaded);
	luasteam::pushuint64(L, punBytesTotal);
	return 3;
}

// In C++:
// int GetAppBuildId();
// In Lua:
// int Apps.GetAppBuildId()
static int luasteam_Apps_GetAppBuildId(lua_State *L) {
	auto *iface = SteamApps();
	int __ret = iface->GetAppBuildId();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// void RequestAllProofOfPurchaseKeys();
// In Lua:
// Apps.RequestAllProofOfPurchaseKeys()
static int luasteam_Apps_RequestAllProofOfPurchaseKeys(lua_State *L) {
	auto *iface = SteamApps();
	iface->RequestAllProofOfPurchaseKeys();
	return 0;
}

// In C++:
// SteamAPICall_t GetFileDetails(const char * pszFileName);
// In Lua:
// uint64 Apps.GetFileDetails(pszFileName: str, callback: function)
static int luasteam_Apps_GetFileDetails(lua_State *L) {
	auto *iface = SteamApps();
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	const char *pszFileName = luaL_checkstring(L, 1);
	SteamAPICall_t __ret = iface->GetFileDetails(pszFileName);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<FileDetailsResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<FileDetailsResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// int GetLaunchCommandLine(char * pszCommandLine, int cubCommandLine);
// In Lua:
// (int, pszCommandLine: str) Apps.GetLaunchCommandLine(cubCommandLine: int)
static int luasteam_Apps_GetLaunchCommandLine(lua_State *L) {
	auto *iface = SteamApps();
	int cubCommandLine = luaL_checkint(L, 1);
	std::vector<char> pszCommandLine(cubCommandLine);
	int __ret = iface->GetLaunchCommandLine(pszCommandLine.data(), cubCommandLine);
	lua_pushinteger(L, __ret);
	lua_pushstring(L, reinterpret_cast<const char*>(pszCommandLine.data()));
	return 2;
}

// In C++:
// bool BIsSubscribedFromFamilySharing();
// In Lua:
// bool Apps.BIsSubscribedFromFamilySharing()
static int luasteam_Apps_BIsSubscribedFromFamilySharing(lua_State *L) {
	auto *iface = SteamApps();
	bool __ret = iface->BIsSubscribedFromFamilySharing();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool BIsTimedTrial(uint32 * punSecondsAllowed, uint32 * punSecondsPlayed);
// In Lua:
// (bool, punSecondsAllowed: int, punSecondsPlayed: int) Apps.BIsTimedTrial()
static int luasteam_Apps_BIsTimedTrial(lua_State *L) {
	auto *iface = SteamApps();
	uint32 punSecondsAllowed;
	uint32 punSecondsPlayed;
	bool __ret = iface->BIsTimedTrial(&punSecondsAllowed, &punSecondsPlayed);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, punSecondsAllowed);
	lua_pushinteger(L, punSecondsPlayed);
	return 3;
}

// In C++:
// bool SetDlcContext(AppId_t nAppID);
// In Lua:
// bool Apps.SetDlcContext(nAppID: int)
static int luasteam_Apps_SetDlcContext(lua_State *L) {
	auto *iface = SteamApps();
	AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
	bool __ret = iface->SetDlcContext(nAppID);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// int GetNumBetas(int * pnAvailable, int * pnPrivate);
// In Lua:
// (int, pnAvailable: int, pnPrivate: int) Apps.GetNumBetas()
static int luasteam_Apps_GetNumBetas(lua_State *L) {
	auto *iface = SteamApps();
	int pnAvailable;
	int pnPrivate;
	int __ret = iface->GetNumBetas(&pnAvailable, &pnPrivate);
	lua_pushinteger(L, __ret);
	lua_pushinteger(L, pnAvailable);
	lua_pushinteger(L, pnPrivate);
	return 3;
}

// In C++:
// bool GetBetaInfo(int iBetaIndex, uint32 * punFlags, uint32 * punBuildID, char * pchBetaName, int cchBetaName, char * pchDescription, int cchDescription);
// In Lua:
// (bool, punFlags: int, punBuildID: int, pchBetaName: str, pchDescription: str) Apps.GetBetaInfo(iBetaIndex: int, cchBetaName: int, cchDescription: int)
static int luasteam_Apps_GetBetaInfo(lua_State *L) {
	auto *iface = SteamApps();
	int iBetaIndex = static_cast<int>(luaL_checkint(L, 1));
	uint32 punFlags;
	uint32 punBuildID;
	int cchBetaName = luaL_checkint(L, 2);
	std::vector<char> pchBetaName(cchBetaName);
	int cchDescription = luaL_checkint(L, 3);
	std::vector<char> pchDescription(cchDescription);
	bool __ret = iface->GetBetaInfo(iBetaIndex, &punFlags, &punBuildID, pchBetaName.data(), cchBetaName, pchDescription.data(), cchDescription);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, punFlags);
	lua_pushinteger(L, punBuildID);
	lua_pushstring(L, reinterpret_cast<const char*>(pchBetaName.data()));
	lua_pushstring(L, reinterpret_cast<const char*>(pchDescription.data()));
	return 5;
}

// In C++:
// bool SetActiveBeta(const char * pchBetaName);
// In Lua:
// bool Apps.SetActiveBeta(pchBetaName: str)
static int luasteam_Apps_SetActiveBeta(lua_State *L) {
	auto *iface = SteamApps();
	const char *pchBetaName = luaL_checkstring(L, 1);
	bool __ret = iface->SetActiveBeta(pchBetaName);
	lua_pushboolean(L, __ret);
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
	add_func(L, "BGetDLCDataByIndex", luasteam_Apps_BGetDLCDataByIndex);
	add_func(L, "InstallDLC", luasteam_Apps_InstallDLC);
	add_func(L, "UninstallDLC", luasteam_Apps_UninstallDLC);
	add_func(L, "RequestAppProofOfPurchaseKey", luasteam_Apps_RequestAppProofOfPurchaseKey);
	add_func(L, "GetCurrentBetaName", luasteam_Apps_GetCurrentBetaName);
	add_func(L, "MarkContentCorrupt", luasteam_Apps_MarkContentCorrupt);
	add_func(L, "GetInstalledDepots", luasteam_Apps_GetInstalledDepots);
	add_func(L, "GetAppInstallDir", luasteam_Apps_GetAppInstallDir);
	add_func(L, "BIsAppInstalled", luasteam_Apps_BIsAppInstalled);
	add_func(L, "GetAppOwner", luasteam_Apps_GetAppOwner);
	add_func(L, "GetLaunchQueryParam", luasteam_Apps_GetLaunchQueryParam);
	add_func(L, "GetDlcDownloadProgress", luasteam_Apps_GetDlcDownloadProgress);
	add_func(L, "GetAppBuildId", luasteam_Apps_GetAppBuildId);
	add_func(L, "RequestAllProofOfPurchaseKeys", luasteam_Apps_RequestAllProofOfPurchaseKeys);
	add_func(L, "GetFileDetails", luasteam_Apps_GetFileDetails);
	add_func(L, "GetLaunchCommandLine", luasteam_Apps_GetLaunchCommandLine);
	add_func(L, "BIsSubscribedFromFamilySharing", luasteam_Apps_BIsSubscribedFromFamilySharing);
	add_func(L, "BIsTimedTrial", luasteam_Apps_BIsTimedTrial);
	add_func(L, "SetDlcContext", luasteam_Apps_SetDlcContext);
	add_func(L, "GetNumBetas", luasteam_Apps_GetNumBetas);
	add_func(L, "GetBetaInfo", luasteam_Apps_GetBetaInfo);
	add_func(L, "SetActiveBeta", luasteam_Apps_SetActiveBeta);
}

void add_Apps_auto(lua_State *L) {
	lua_createtable(L, 0, 33);
	register_Apps_auto(L);
	lua_pushvalue(L, -1);
	Apps_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "Apps");
}

} // namespace luasteam
