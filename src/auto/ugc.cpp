#include "auto.hpp"

namespace luasteam {

int UGC_ref = LUA_NOREF;

namespace {

class CallbackListener {
  private:
    STEAM_CALLBACK(CallbackListener, OnSteamUGCQueryCompleted, SteamUGCQueryCompleted_t);
    STEAM_CALLBACK(CallbackListener, OnSteamUGCRequestUGCDetailsResult, SteamUGCRequestUGCDetailsResult_t);
    STEAM_CALLBACK(CallbackListener, OnCreateItemResult, CreateItemResult_t);
    STEAM_CALLBACK(CallbackListener, OnSubmitItemUpdateResult, SubmitItemUpdateResult_t);
    STEAM_CALLBACK(CallbackListener, OnItemInstalled, ItemInstalled_t);
    STEAM_CALLBACK(CallbackListener, OnDownloadItemResult, DownloadItemResult_t);
    STEAM_CALLBACK(CallbackListener, OnUserFavoriteItemsListChanged, UserFavoriteItemsListChanged_t);
    STEAM_CALLBACK(CallbackListener, OnSetUserItemVoteResult, SetUserItemVoteResult_t);
    STEAM_CALLBACK(CallbackListener, OnGetUserItemVoteResult, GetUserItemVoteResult_t);
    STEAM_CALLBACK(CallbackListener, OnStartPlaytimeTrackingResult, StartPlaytimeTrackingResult_t);
    STEAM_CALLBACK(CallbackListener, OnStopPlaytimeTrackingResult, StopPlaytimeTrackingResult_t);
    STEAM_CALLBACK(CallbackListener, OnAddUGCDependencyResult, AddUGCDependencyResult_t);
    STEAM_CALLBACK(CallbackListener, OnRemoveUGCDependencyResult, RemoveUGCDependencyResult_t);
    STEAM_CALLBACK(CallbackListener, OnAddAppDependencyResult, AddAppDependencyResult_t);
    STEAM_CALLBACK(CallbackListener, OnRemoveAppDependencyResult, RemoveAppDependencyResult_t);
    STEAM_CALLBACK(CallbackListener, OnGetAppDependenciesResult, GetAppDependenciesResult_t);
    STEAM_CALLBACK(CallbackListener, OnDeleteItemResult, DeleteItemResult_t);
    STEAM_CALLBACK(CallbackListener, OnUserSubscribedItemsListChanged, UserSubscribedItemsListChanged_t);
    STEAM_CALLBACK(CallbackListener, OnWorkshopEULAStatus, WorkshopEULAStatus_t);
};

void CallbackListener::OnSteamUGCQueryCompleted(SteamUGCQueryCompleted_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
    lua_getfield(L, -1, "OnSteamUGCQueryCompleted");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 6);
        luasteam::pushuint64(L, data->m_handle);
        lua_setfield(L, -2, "m_handle");
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "m_eResult");
        lua_pushinteger(L, data->m_unNumResultsReturned);
        lua_setfield(L, -2, "m_unNumResultsReturned");
        lua_pushinteger(L, data->m_unTotalMatchingResults);
        lua_setfield(L, -2, "m_unTotalMatchingResults");
        lua_pushboolean(L, data->m_bCachedData);
        lua_setfield(L, -2, "m_bCachedData");
        // Skip unsupported type: char [256]
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnSteamUGCRequestUGCDetailsResult(SteamUGCRequestUGCDetailsResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
    lua_getfield(L, -1, "OnSteamUGCRequestUGCDetailsResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        // Skip unsupported type: SteamUGCDetails_t
        lua_pushboolean(L, data->m_bCachedData);
        lua_setfield(L, -2, "m_bCachedData");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnCreateItemResult(CreateItemResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
    lua_getfield(L, -1, "OnCreateItemResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "m_eResult");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "m_nPublishedFileId");
        lua_pushboolean(L, data->m_bUserNeedsToAcceptWorkshopLegalAgreement);
        lua_setfield(L, -2, "m_bUserNeedsToAcceptWorkshopLegalAgreement");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnSubmitItemUpdateResult(SubmitItemUpdateResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
    lua_getfield(L, -1, "OnSubmitItemUpdateResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "m_eResult");
        lua_pushboolean(L, data->m_bUserNeedsToAcceptWorkshopLegalAgreement);
        lua_setfield(L, -2, "m_bUserNeedsToAcceptWorkshopLegalAgreement");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "m_nPublishedFileId");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnItemInstalled(ItemInstalled_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
    lua_getfield(L, -1, "OnItemInstalled");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        lua_pushinteger(L, data->m_unAppID);
        lua_setfield(L, -2, "m_unAppID");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "m_nPublishedFileId");
        luasteam::pushuint64(L, data->m_hLegacyContent);
        lua_setfield(L, -2, "m_hLegacyContent");
        luasteam::pushuint64(L, data->m_unManifestID);
        lua_setfield(L, -2, "m_unManifestID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnDownloadItemResult(DownloadItemResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
    lua_getfield(L, -1, "OnDownloadItemResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->m_unAppID);
        lua_setfield(L, -2, "m_unAppID");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "m_nPublishedFileId");
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "m_eResult");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnUserFavoriteItemsListChanged(UserFavoriteItemsListChanged_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
    lua_getfield(L, -1, "OnUserFavoriteItemsListChanged");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "m_nPublishedFileId");
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "m_eResult");
        lua_pushboolean(L, data->m_bWasAddRequest);
        lua_setfield(L, -2, "m_bWasAddRequest");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnSetUserItemVoteResult(SetUserItemVoteResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
    lua_getfield(L, -1, "OnSetUserItemVoteResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "m_nPublishedFileId");
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "m_eResult");
        lua_pushboolean(L, data->m_bVoteUp);
        lua_setfield(L, -2, "m_bVoteUp");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGetUserItemVoteResult(GetUserItemVoteResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
    lua_getfield(L, -1, "OnGetUserItemVoteResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 5);
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "m_nPublishedFileId");
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "m_eResult");
        lua_pushboolean(L, data->m_bVotedUp);
        lua_setfield(L, -2, "m_bVotedUp");
        lua_pushboolean(L, data->m_bVotedDown);
        lua_setfield(L, -2, "m_bVotedDown");
        lua_pushboolean(L, data->m_bVoteSkipped);
        lua_setfield(L, -2, "m_bVoteSkipped");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnStartPlaytimeTrackingResult(StartPlaytimeTrackingResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
    lua_getfield(L, -1, "OnStartPlaytimeTrackingResult");
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

void CallbackListener::OnStopPlaytimeTrackingResult(StopPlaytimeTrackingResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
    lua_getfield(L, -1, "OnStopPlaytimeTrackingResult");
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

void CallbackListener::OnAddUGCDependencyResult(AddUGCDependencyResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
    lua_getfield(L, -1, "OnAddUGCDependencyResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "m_eResult");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "m_nPublishedFileId");
        luasteam::pushuint64(L, data->m_nChildPublishedFileId);
        lua_setfield(L, -2, "m_nChildPublishedFileId");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnRemoveUGCDependencyResult(RemoveUGCDependencyResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
    lua_getfield(L, -1, "OnRemoveUGCDependencyResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "m_eResult");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "m_nPublishedFileId");
        luasteam::pushuint64(L, data->m_nChildPublishedFileId);
        lua_setfield(L, -2, "m_nChildPublishedFileId");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnAddAppDependencyResult(AddAppDependencyResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
    lua_getfield(L, -1, "OnAddAppDependencyResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "m_eResult");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "m_nPublishedFileId");
        lua_pushinteger(L, data->m_nAppID);
        lua_setfield(L, -2, "m_nAppID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnRemoveAppDependencyResult(RemoveAppDependencyResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
    lua_getfield(L, -1, "OnRemoveAppDependencyResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "m_eResult");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "m_nPublishedFileId");
        lua_pushinteger(L, data->m_nAppID);
        lua_setfield(L, -2, "m_nAppID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGetAppDependenciesResult(GetAppDependenciesResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
    lua_getfield(L, -1, "OnGetAppDependenciesResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 5);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "m_eResult");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "m_nPublishedFileId");
        // Skip unsupported type: AppId_t [32]
        lua_pushinteger(L, data->m_nNumAppDependencies);
        lua_setfield(L, -2, "m_nNumAppDependencies");
        lua_pushinteger(L, data->m_nTotalNumAppDependencies);
        lua_setfield(L, -2, "m_nTotalNumAppDependencies");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnDeleteItemResult(DeleteItemResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
    lua_getfield(L, -1, "OnDeleteItemResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "m_eResult");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "m_nPublishedFileId");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnUserSubscribedItemsListChanged(UserSubscribedItemsListChanged_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
    lua_getfield(L, -1, "OnUserSubscribedItemsListChanged");
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

void CallbackListener::OnWorkshopEULAStatus(WorkshopEULAStatus_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::UGC_ref);
    lua_getfield(L, -1, "OnWorkshopEULAStatus");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 6);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "m_eResult");
        lua_pushinteger(L, data->m_nAppID);
        lua_setfield(L, -2, "m_nAppID");
        lua_pushinteger(L, data->m_unVersion);
        lua_setfield(L, -2, "m_unVersion");
        lua_pushinteger(L, data->m_rtAction);
        lua_setfield(L, -2, "m_rtAction");
        lua_pushboolean(L, data->m_bAccepted);
        lua_setfield(L, -2, "m_bAccepted");
        lua_pushboolean(L, data->m_bNeedsAction);
        lua_setfield(L, -2, "m_bNeedsAction");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

CallbackListener *UGC_listener = nullptr;

} // namespace

void init_UGC_auto(lua_State *L) { UGC_listener = new CallbackListener(); }

void shutdown_UGC_auto(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, UGC_ref);
    UGC_ref = LUA_NOREF;
    delete UGC_listener; UGC_listener = nullptr;
}


// UGCQueryHandle_t CreateQueryUserUGCRequest(AccountID_t unAccountID, EUserUGCList eListType, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eSortOrder, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage);
EXTERN int luasteam_UGC_CreateQueryUserUGCRequest(lua_State *L) {
    AccountID_t unAccountID = static_cast<AccountID_t>(luaL_checkint(L, 1));
    EUserUGCList eListType = static_cast<EUserUGCList>(luaL_checkint(L, 2));
    EUGCMatchingUGCType eMatchingUGCType = static_cast<EUGCMatchingUGCType>(luaL_checkint(L, 3));
    EUserUGCListSortOrder eSortOrder = static_cast<EUserUGCListSortOrder>(luaL_checkint(L, 4));
    AppId_t nCreatorAppID = static_cast<AppId_t>(luaL_checkint(L, 5));
    AppId_t nConsumerAppID = static_cast<AppId_t>(luaL_checkint(L, 6));
    uint32 unPage = static_cast<uint32>(luaL_checkint(L, 7));
    luasteam::pushuint64(L, SteamUGC()->CreateQueryUserUGCRequest(unAccountID, eListType, eMatchingUGCType, eSortOrder, nCreatorAppID, nConsumerAppID, unPage));
    return 1;
}

// UGCQueryHandle_t CreateQueryAllUGCRequest(EUGCQuery eQueryType, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage);
EXTERN int luasteam_UGC_CreateQueryAllUGCRequest(lua_State *L) {
    EUGCQuery eQueryType = static_cast<EUGCQuery>(luaL_checkint(L, 1));
    EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType = static_cast<EUGCMatchingUGCType>(luaL_checkint(L, 2));
    AppId_t nCreatorAppID = static_cast<AppId_t>(luaL_checkint(L, 3));
    AppId_t nConsumerAppID = static_cast<AppId_t>(luaL_checkint(L, 4));
    uint32 unPage = static_cast<uint32>(luaL_checkint(L, 5));
    luasteam::pushuint64(L, SteamUGC()->CreateQueryAllUGCRequest(eQueryType, eMatchingeMatchingUGCTypeFileType, nCreatorAppID, nConsumerAppID, unPage));
    return 1;
}

// SteamAPICall_t SendQueryUGCRequest(UGCQueryHandle_t handle);
EXTERN int luasteam_UGC_SendQueryUGCRequest(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamUGC()->SendQueryUGCRequest(handle));
    return 1;
}

// uint32 GetQueryUGCNumTags(UGCQueryHandle_t handle, uint32 index);
EXTERN int luasteam_UGC_GetQueryUGCNumTags(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
    lua_pushinteger(L, SteamUGC()->GetQueryUGCNumTags(handle, index));
    return 1;
}

// bool GetQueryUGCStatistic(UGCQueryHandle_t handle, uint32 index, EItemStatistic eStatType, uint64 * pStatValue);
EXTERN int luasteam_UGC_GetQueryUGCStatistic(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
    EItemStatistic eStatType = static_cast<EItemStatistic>(luaL_checkint(L, 3));
    uint64 pStatValue;    lua_pushboolean(L, SteamUGC()->GetQueryUGCStatistic(handle, index, eStatType, &pStatValue));
    luasteam::pushuint64(L, pStatValue);
    return 2;
}

// uint32 GetQueryUGCNumAdditionalPreviews(UGCQueryHandle_t handle, uint32 index);
EXTERN int luasteam_UGC_GetQueryUGCNumAdditionalPreviews(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
    lua_pushinteger(L, SteamUGC()->GetQueryUGCNumAdditionalPreviews(handle, index));
    return 1;
}

// uint32 GetQueryUGCNumKeyValueTags(UGCQueryHandle_t handle, uint32 index);
EXTERN int luasteam_UGC_GetQueryUGCNumKeyValueTags(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
    lua_pushinteger(L, SteamUGC()->GetQueryUGCNumKeyValueTags(handle, index));
    return 1;
}

// uint32 GetNumSupportedGameVersions(UGCQueryHandle_t handle, uint32 index);
EXTERN int luasteam_UGC_GetNumSupportedGameVersions(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
    lua_pushinteger(L, SteamUGC()->GetNumSupportedGameVersions(handle, index));
    return 1;
}

// bool ReleaseQueryUGCRequest(UGCQueryHandle_t handle);
EXTERN int luasteam_UGC_ReleaseQueryUGCRequest(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    lua_pushboolean(L, SteamUGC()->ReleaseQueryUGCRequest(handle));
    return 1;
}

// bool AddRequiredTag(UGCQueryHandle_t handle, const char * pTagName);
EXTERN int luasteam_UGC_AddRequiredTag(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pTagName = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->AddRequiredTag(handle, pTagName));
    return 1;
}

// bool AddExcludedTag(UGCQueryHandle_t handle, const char * pTagName);
EXTERN int luasteam_UGC_AddExcludedTag(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pTagName = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->AddExcludedTag(handle, pTagName));
    return 1;
}

// bool SetReturnOnlyIDs(UGCQueryHandle_t handle, bool bReturnOnlyIDs);
EXTERN int luasteam_UGC_SetReturnOnlyIDs(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    bool bReturnOnlyIDs = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamUGC()->SetReturnOnlyIDs(handle, bReturnOnlyIDs));
    return 1;
}

// bool SetReturnKeyValueTags(UGCQueryHandle_t handle, bool bReturnKeyValueTags);
EXTERN int luasteam_UGC_SetReturnKeyValueTags(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    bool bReturnKeyValueTags = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamUGC()->SetReturnKeyValueTags(handle, bReturnKeyValueTags));
    return 1;
}

// bool SetReturnLongDescription(UGCQueryHandle_t handle, bool bReturnLongDescription);
EXTERN int luasteam_UGC_SetReturnLongDescription(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    bool bReturnLongDescription = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamUGC()->SetReturnLongDescription(handle, bReturnLongDescription));
    return 1;
}

// bool SetReturnMetadata(UGCQueryHandle_t handle, bool bReturnMetadata);
EXTERN int luasteam_UGC_SetReturnMetadata(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    bool bReturnMetadata = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamUGC()->SetReturnMetadata(handle, bReturnMetadata));
    return 1;
}

// bool SetReturnChildren(UGCQueryHandle_t handle, bool bReturnChildren);
EXTERN int luasteam_UGC_SetReturnChildren(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    bool bReturnChildren = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamUGC()->SetReturnChildren(handle, bReturnChildren));
    return 1;
}

// bool SetReturnAdditionalPreviews(UGCQueryHandle_t handle, bool bReturnAdditionalPreviews);
EXTERN int luasteam_UGC_SetReturnAdditionalPreviews(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    bool bReturnAdditionalPreviews = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamUGC()->SetReturnAdditionalPreviews(handle, bReturnAdditionalPreviews));
    return 1;
}

// bool SetReturnTotalOnly(UGCQueryHandle_t handle, bool bReturnTotalOnly);
EXTERN int luasteam_UGC_SetReturnTotalOnly(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    bool bReturnTotalOnly = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamUGC()->SetReturnTotalOnly(handle, bReturnTotalOnly));
    return 1;
}

// bool SetReturnPlaytimeStats(UGCQueryHandle_t handle, uint32 unDays);
EXTERN int luasteam_UGC_SetReturnPlaytimeStats(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    uint32 unDays = static_cast<uint32>(luaL_checkint(L, 2));
    lua_pushboolean(L, SteamUGC()->SetReturnPlaytimeStats(handle, unDays));
    return 1;
}

// bool SetLanguage(UGCQueryHandle_t handle, const char * pchLanguage);
EXTERN int luasteam_UGC_SetLanguage(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pchLanguage = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->SetLanguage(handle, pchLanguage));
    return 1;
}

// bool SetAllowCachedResponse(UGCQueryHandle_t handle, uint32 unMaxAgeSeconds);
EXTERN int luasteam_UGC_SetAllowCachedResponse(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    uint32 unMaxAgeSeconds = static_cast<uint32>(luaL_checkint(L, 2));
    lua_pushboolean(L, SteamUGC()->SetAllowCachedResponse(handle, unMaxAgeSeconds));
    return 1;
}

// bool SetAdminQuery(UGCUpdateHandle_t handle, bool bAdminQuery);
EXTERN int luasteam_UGC_SetAdminQuery(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    bool bAdminQuery = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamUGC()->SetAdminQuery(handle, bAdminQuery));
    return 1;
}

// bool SetCloudFileNameFilter(UGCQueryHandle_t handle, const char * pMatchCloudFileName);
EXTERN int luasteam_UGC_SetCloudFileNameFilter(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pMatchCloudFileName = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->SetCloudFileNameFilter(handle, pMatchCloudFileName));
    return 1;
}

// bool SetMatchAnyTag(UGCQueryHandle_t handle, bool bMatchAnyTag);
EXTERN int luasteam_UGC_SetMatchAnyTag(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    bool bMatchAnyTag = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamUGC()->SetMatchAnyTag(handle, bMatchAnyTag));
    return 1;
}

// bool SetSearchText(UGCQueryHandle_t handle, const char * pSearchText);
EXTERN int luasteam_UGC_SetSearchText(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pSearchText = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->SetSearchText(handle, pSearchText));
    return 1;
}

// bool SetRankedByTrendDays(UGCQueryHandle_t handle, uint32 unDays);
EXTERN int luasteam_UGC_SetRankedByTrendDays(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    uint32 unDays = static_cast<uint32>(luaL_checkint(L, 2));
    lua_pushboolean(L, SteamUGC()->SetRankedByTrendDays(handle, unDays));
    return 1;
}

// bool SetTimeCreatedDateRange(UGCQueryHandle_t handle, RTime32 rtStart, RTime32 rtEnd);
EXTERN int luasteam_UGC_SetTimeCreatedDateRange(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    RTime32 rtStart = static_cast<RTime32>(luaL_checkint(L, 2));
    RTime32 rtEnd = static_cast<RTime32>(luaL_checkint(L, 3));
    lua_pushboolean(L, SteamUGC()->SetTimeCreatedDateRange(handle, rtStart, rtEnd));
    return 1;
}

// bool SetTimeUpdatedDateRange(UGCQueryHandle_t handle, RTime32 rtStart, RTime32 rtEnd);
EXTERN int luasteam_UGC_SetTimeUpdatedDateRange(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    RTime32 rtStart = static_cast<RTime32>(luaL_checkint(L, 2));
    RTime32 rtEnd = static_cast<RTime32>(luaL_checkint(L, 3));
    lua_pushboolean(L, SteamUGC()->SetTimeUpdatedDateRange(handle, rtStart, rtEnd));
    return 1;
}

// bool AddRequiredKeyValueTag(UGCQueryHandle_t handle, const char * pKey, const char * pValue);
EXTERN int luasteam_UGC_AddRequiredKeyValueTag(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pKey = luaL_checkstring(L, 2);
    const char *pValue = luaL_checkstring(L, 3);
    lua_pushboolean(L, SteamUGC()->AddRequiredKeyValueTag(handle, pKey, pValue));
    return 1;
}

// SteamAPICall_t RequestUGCDetails(PublishedFileId_t nPublishedFileID, uint32 unMaxAgeSeconds);
EXTERN int luasteam_UGC_RequestUGCDetails(lua_State *L) {
    PublishedFileId_t nPublishedFileID = luasteam::checkuint64(L, 1);
    uint32 unMaxAgeSeconds = static_cast<uint32>(luaL_checkint(L, 2));
    luasteam::pushuint64(L, SteamUGC()->RequestUGCDetails(nPublishedFileID, unMaxAgeSeconds));
    return 1;
}

// SteamAPICall_t CreateItem(AppId_t nConsumerAppId, EWorkshopFileType eFileType);
EXTERN int luasteam_UGC_CreateItem(lua_State *L) {
    AppId_t nConsumerAppId = static_cast<AppId_t>(luaL_checkint(L, 1));
    EWorkshopFileType eFileType = static_cast<EWorkshopFileType>(luaL_checkint(L, 2));
    luasteam::pushuint64(L, SteamUGC()->CreateItem(nConsumerAppId, eFileType));
    return 1;
}

// UGCUpdateHandle_t StartItemUpdate(AppId_t nConsumerAppId, PublishedFileId_t nPublishedFileID);
EXTERN int luasteam_UGC_StartItemUpdate(lua_State *L) {
    AppId_t nConsumerAppId = static_cast<AppId_t>(luaL_checkint(L, 1));
    PublishedFileId_t nPublishedFileID = luasteam::checkuint64(L, 2);
    luasteam::pushuint64(L, SteamUGC()->StartItemUpdate(nConsumerAppId, nPublishedFileID));
    return 1;
}

// bool SetItemTitle(UGCUpdateHandle_t handle, const char * pchTitle);
EXTERN int luasteam_UGC_SetItemTitle(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pchTitle = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->SetItemTitle(handle, pchTitle));
    return 1;
}

// bool SetItemDescription(UGCUpdateHandle_t handle, const char * pchDescription);
EXTERN int luasteam_UGC_SetItemDescription(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pchDescription = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->SetItemDescription(handle, pchDescription));
    return 1;
}

// bool SetItemUpdateLanguage(UGCUpdateHandle_t handle, const char * pchLanguage);
EXTERN int luasteam_UGC_SetItemUpdateLanguage(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pchLanguage = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->SetItemUpdateLanguage(handle, pchLanguage));
    return 1;
}

// bool SetItemMetadata(UGCUpdateHandle_t handle, const char * pchMetaData);
EXTERN int luasteam_UGC_SetItemMetadata(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pchMetaData = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->SetItemMetadata(handle, pchMetaData));
    return 1;
}

// bool SetItemVisibility(UGCUpdateHandle_t handle, ERemoteStoragePublishedFileVisibility eVisibility);
EXTERN int luasteam_UGC_SetItemVisibility(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    ERemoteStoragePublishedFileVisibility eVisibility = static_cast<ERemoteStoragePublishedFileVisibility>(luaL_checkint(L, 2));
    lua_pushboolean(L, SteamUGC()->SetItemVisibility(handle, eVisibility));
    return 1;
}

// bool SetItemContent(UGCUpdateHandle_t handle, const char * pszContentFolder);
EXTERN int luasteam_UGC_SetItemContent(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pszContentFolder = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->SetItemContent(handle, pszContentFolder));
    return 1;
}

// bool SetItemPreview(UGCUpdateHandle_t handle, const char * pszPreviewFile);
EXTERN int luasteam_UGC_SetItemPreview(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pszPreviewFile = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->SetItemPreview(handle, pszPreviewFile));
    return 1;
}

// bool SetAllowLegacyUpload(UGCUpdateHandle_t handle, bool bAllowLegacyUpload);
EXTERN int luasteam_UGC_SetAllowLegacyUpload(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    bool bAllowLegacyUpload = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamUGC()->SetAllowLegacyUpload(handle, bAllowLegacyUpload));
    return 1;
}

// bool RemoveAllItemKeyValueTags(UGCUpdateHandle_t handle);
EXTERN int luasteam_UGC_RemoveAllItemKeyValueTags(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    lua_pushboolean(L, SteamUGC()->RemoveAllItemKeyValueTags(handle));
    return 1;
}

// bool RemoveItemKeyValueTags(UGCUpdateHandle_t handle, const char * pchKey);
EXTERN int luasteam_UGC_RemoveItemKeyValueTags(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pchKey = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->RemoveItemKeyValueTags(handle, pchKey));
    return 1;
}

// bool AddItemKeyValueTag(UGCUpdateHandle_t handle, const char * pchKey, const char * pchValue);
EXTERN int luasteam_UGC_AddItemKeyValueTag(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pchKey = luaL_checkstring(L, 2);
    const char *pchValue = luaL_checkstring(L, 3);
    lua_pushboolean(L, SteamUGC()->AddItemKeyValueTag(handle, pchKey, pchValue));
    return 1;
}

// bool AddItemPreviewFile(UGCUpdateHandle_t handle, const char * pszPreviewFile, EItemPreviewType type);
EXTERN int luasteam_UGC_AddItemPreviewFile(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pszPreviewFile = luaL_checkstring(L, 2);
    EItemPreviewType type = static_cast<EItemPreviewType>(luaL_checkint(L, 3));
    lua_pushboolean(L, SteamUGC()->AddItemPreviewFile(handle, pszPreviewFile, type));
    return 1;
}

// bool AddItemPreviewVideo(UGCUpdateHandle_t handle, const char * pszVideoID);
EXTERN int luasteam_UGC_AddItemPreviewVideo(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pszVideoID = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->AddItemPreviewVideo(handle, pszVideoID));
    return 1;
}

// bool UpdateItemPreviewFile(UGCUpdateHandle_t handle, uint32 index, const char * pszPreviewFile);
EXTERN int luasteam_UGC_UpdateItemPreviewFile(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
    const char *pszPreviewFile = luaL_checkstring(L, 3);
    lua_pushboolean(L, SteamUGC()->UpdateItemPreviewFile(handle, index, pszPreviewFile));
    return 1;
}

// bool UpdateItemPreviewVideo(UGCUpdateHandle_t handle, uint32 index, const char * pszVideoID);
EXTERN int luasteam_UGC_UpdateItemPreviewVideo(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
    const char *pszVideoID = luaL_checkstring(L, 3);
    lua_pushboolean(L, SteamUGC()->UpdateItemPreviewVideo(handle, index, pszVideoID));
    return 1;
}

// bool RemoveItemPreview(UGCUpdateHandle_t handle, uint32 index);
EXTERN int luasteam_UGC_RemoveItemPreview(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
    lua_pushboolean(L, SteamUGC()->RemoveItemPreview(handle, index));
    return 1;
}

// bool AddContentDescriptor(UGCUpdateHandle_t handle, EUGCContentDescriptorID descid);
EXTERN int luasteam_UGC_AddContentDescriptor(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    EUGCContentDescriptorID descid = static_cast<EUGCContentDescriptorID>(luaL_checkint(L, 2));
    lua_pushboolean(L, SteamUGC()->AddContentDescriptor(handle, descid));
    return 1;
}

// bool RemoveContentDescriptor(UGCUpdateHandle_t handle, EUGCContentDescriptorID descid);
EXTERN int luasteam_UGC_RemoveContentDescriptor(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    EUGCContentDescriptorID descid = static_cast<EUGCContentDescriptorID>(luaL_checkint(L, 2));
    lua_pushboolean(L, SteamUGC()->RemoveContentDescriptor(handle, descid));
    return 1;
}

// bool SetRequiredGameVersions(UGCUpdateHandle_t handle, const char * pszGameBranchMin, const char * pszGameBranchMax);
EXTERN int luasteam_UGC_SetRequiredGameVersions(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pszGameBranchMin = luaL_checkstring(L, 2);
    const char *pszGameBranchMax = luaL_checkstring(L, 3);
    lua_pushboolean(L, SteamUGC()->SetRequiredGameVersions(handle, pszGameBranchMin, pszGameBranchMax));
    return 1;
}

// SteamAPICall_t SubmitItemUpdate(UGCUpdateHandle_t handle, const char * pchChangeNote);
EXTERN int luasteam_UGC_SubmitItemUpdate(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pchChangeNote = luaL_checkstring(L, 2);
    luasteam::pushuint64(L, SteamUGC()->SubmitItemUpdate(handle, pchChangeNote));
    return 1;
}

// EItemUpdateStatus GetItemUpdateProgress(UGCUpdateHandle_t handle, uint64 * punBytesProcessed, uint64 * punBytesTotal);
EXTERN int luasteam_UGC_GetItemUpdateProgress(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    uint64 punBytesProcessed;    uint64 punBytesTotal;    lua_pushinteger(L, SteamUGC()->GetItemUpdateProgress(handle, &punBytesProcessed, &punBytesTotal));
    luasteam::pushuint64(L, punBytesProcessed);
    luasteam::pushuint64(L, punBytesTotal);
    return 3;
}

// SteamAPICall_t SetUserItemVote(PublishedFileId_t nPublishedFileID, bool bVoteUp);
EXTERN int luasteam_UGC_SetUserItemVote(lua_State *L) {
    PublishedFileId_t nPublishedFileID = luasteam::checkuint64(L, 1);
    bool bVoteUp = lua_toboolean(L, 2);
    luasteam::pushuint64(L, SteamUGC()->SetUserItemVote(nPublishedFileID, bVoteUp));
    return 1;
}

// SteamAPICall_t GetUserItemVote(PublishedFileId_t nPublishedFileID);
EXTERN int luasteam_UGC_GetUserItemVote(lua_State *L) {
    PublishedFileId_t nPublishedFileID = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamUGC()->GetUserItemVote(nPublishedFileID));
    return 1;
}

// SteamAPICall_t AddItemToFavorites(AppId_t nAppId, PublishedFileId_t nPublishedFileID);
EXTERN int luasteam_UGC_AddItemToFavorites(lua_State *L) {
    AppId_t nAppId = static_cast<AppId_t>(luaL_checkint(L, 1));
    PublishedFileId_t nPublishedFileID = luasteam::checkuint64(L, 2);
    luasteam::pushuint64(L, SteamUGC()->AddItemToFavorites(nAppId, nPublishedFileID));
    return 1;
}

// SteamAPICall_t RemoveItemFromFavorites(AppId_t nAppId, PublishedFileId_t nPublishedFileID);
EXTERN int luasteam_UGC_RemoveItemFromFavorites(lua_State *L) {
    AppId_t nAppId = static_cast<AppId_t>(luaL_checkint(L, 1));
    PublishedFileId_t nPublishedFileID = luasteam::checkuint64(L, 2);
    luasteam::pushuint64(L, SteamUGC()->RemoveItemFromFavorites(nAppId, nPublishedFileID));
    return 1;
}

// SteamAPICall_t SubscribeItem(PublishedFileId_t nPublishedFileID);
EXTERN int luasteam_UGC_SubscribeItem(lua_State *L) {
    PublishedFileId_t nPublishedFileID = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamUGC()->SubscribeItem(nPublishedFileID));
    return 1;
}

// SteamAPICall_t UnsubscribeItem(PublishedFileId_t nPublishedFileID);
EXTERN int luasteam_UGC_UnsubscribeItem(lua_State *L) {
    PublishedFileId_t nPublishedFileID = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamUGC()->UnsubscribeItem(nPublishedFileID));
    return 1;
}

// uint32 GetNumSubscribedItems(bool bIncludeLocallyDisabled);
EXTERN int luasteam_UGC_GetNumSubscribedItems(lua_State *L) {
    bool bIncludeLocallyDisabled = lua_toboolean(L, 1);
    lua_pushinteger(L, SteamUGC()->GetNumSubscribedItems(bIncludeLocallyDisabled));
    return 1;
}

// uint32 GetItemState(PublishedFileId_t nPublishedFileID);
EXTERN int luasteam_UGC_GetItemState(lua_State *L) {
    PublishedFileId_t nPublishedFileID = luasteam::checkuint64(L, 1);
    lua_pushinteger(L, SteamUGC()->GetItemState(nPublishedFileID));
    return 1;
}

// bool GetItemDownloadInfo(PublishedFileId_t nPublishedFileID, uint64 * punBytesDownloaded, uint64 * punBytesTotal);
EXTERN int luasteam_UGC_GetItemDownloadInfo(lua_State *L) {
    PublishedFileId_t nPublishedFileID = luasteam::checkuint64(L, 1);
    uint64 punBytesDownloaded;    uint64 punBytesTotal;    lua_pushboolean(L, SteamUGC()->GetItemDownloadInfo(nPublishedFileID, &punBytesDownloaded, &punBytesTotal));
    luasteam::pushuint64(L, punBytesDownloaded);
    luasteam::pushuint64(L, punBytesTotal);
    return 3;
}

// bool DownloadItem(PublishedFileId_t nPublishedFileID, bool bHighPriority);
EXTERN int luasteam_UGC_DownloadItem(lua_State *L) {
    PublishedFileId_t nPublishedFileID = luasteam::checkuint64(L, 1);
    bool bHighPriority = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamUGC()->DownloadItem(nPublishedFileID, bHighPriority));
    return 1;
}

// bool BInitWorkshopForGameServer(DepotId_t unWorkshopDepotID, const char * pszFolder);
EXTERN int luasteam_UGC_BInitWorkshopForGameServer(lua_State *L) {
    DepotId_t unWorkshopDepotID = static_cast<DepotId_t>(luaL_checkint(L, 1));
    const char *pszFolder = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->BInitWorkshopForGameServer(unWorkshopDepotID, pszFolder));
    return 1;
}

// void SuspendDownloads(bool bSuspend);
EXTERN int luasteam_UGC_SuspendDownloads(lua_State *L) {
    bool bSuspend = lua_toboolean(L, 1);
    SteamUGC()->SuspendDownloads(bSuspend);
    return 0;
}

// SteamAPICall_t StopPlaytimeTrackingForAllItems();
EXTERN int luasteam_UGC_StopPlaytimeTrackingForAllItems(lua_State *L) {
    luasteam::pushuint64(L, SteamUGC()->StopPlaytimeTrackingForAllItems());
    return 1;
}

// SteamAPICall_t AddDependency(PublishedFileId_t nParentPublishedFileID, PublishedFileId_t nChildPublishedFileID);
EXTERN int luasteam_UGC_AddDependency(lua_State *L) {
    PublishedFileId_t nParentPublishedFileID = luasteam::checkuint64(L, 1);
    PublishedFileId_t nChildPublishedFileID = luasteam::checkuint64(L, 2);
    luasteam::pushuint64(L, SteamUGC()->AddDependency(nParentPublishedFileID, nChildPublishedFileID));
    return 1;
}

// SteamAPICall_t RemoveDependency(PublishedFileId_t nParentPublishedFileID, PublishedFileId_t nChildPublishedFileID);
EXTERN int luasteam_UGC_RemoveDependency(lua_State *L) {
    PublishedFileId_t nParentPublishedFileID = luasteam::checkuint64(L, 1);
    PublishedFileId_t nChildPublishedFileID = luasteam::checkuint64(L, 2);
    luasteam::pushuint64(L, SteamUGC()->RemoveDependency(nParentPublishedFileID, nChildPublishedFileID));
    return 1;
}

// SteamAPICall_t AddAppDependency(PublishedFileId_t nPublishedFileID, AppId_t nAppID);
EXTERN int luasteam_UGC_AddAppDependency(lua_State *L) {
    PublishedFileId_t nPublishedFileID = luasteam::checkuint64(L, 1);
    AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 2));
    luasteam::pushuint64(L, SteamUGC()->AddAppDependency(nPublishedFileID, nAppID));
    return 1;
}

// SteamAPICall_t RemoveAppDependency(PublishedFileId_t nPublishedFileID, AppId_t nAppID);
EXTERN int luasteam_UGC_RemoveAppDependency(lua_State *L) {
    PublishedFileId_t nPublishedFileID = luasteam::checkuint64(L, 1);
    AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 2));
    luasteam::pushuint64(L, SteamUGC()->RemoveAppDependency(nPublishedFileID, nAppID));
    return 1;
}

// SteamAPICall_t GetAppDependencies(PublishedFileId_t nPublishedFileID);
EXTERN int luasteam_UGC_GetAppDependencies(lua_State *L) {
    PublishedFileId_t nPublishedFileID = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamUGC()->GetAppDependencies(nPublishedFileID));
    return 1;
}

// SteamAPICall_t DeleteItem(PublishedFileId_t nPublishedFileID);
EXTERN int luasteam_UGC_DeleteItem(lua_State *L) {
    PublishedFileId_t nPublishedFileID = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamUGC()->DeleteItem(nPublishedFileID));
    return 1;
}

// bool ShowWorkshopEULA();
EXTERN int luasteam_UGC_ShowWorkshopEULA(lua_State *L) {
    lua_pushboolean(L, SteamUGC()->ShowWorkshopEULA());
    return 1;
}

// SteamAPICall_t GetWorkshopEULAStatus();
EXTERN int luasteam_UGC_GetWorkshopEULAStatus(lua_State *L) {
    luasteam::pushuint64(L, SteamUGC()->GetWorkshopEULAStatus());
    return 1;
}

void register_UGC_auto(lua_State *L) {
    add_func(L, "CreateQueryUserUGCRequest", luasteam_UGC_CreateQueryUserUGCRequest);
    add_func(L, "CreateQueryAllUGCRequest", luasteam_UGC_CreateQueryAllUGCRequest);
    add_func(L, "SendQueryUGCRequest", luasteam_UGC_SendQueryUGCRequest);
    add_func(L, "GetQueryUGCNumTags", luasteam_UGC_GetQueryUGCNumTags);
    add_func(L, "GetQueryUGCStatistic", luasteam_UGC_GetQueryUGCStatistic);
    add_func(L, "GetQueryUGCNumAdditionalPreviews", luasteam_UGC_GetQueryUGCNumAdditionalPreviews);
    add_func(L, "GetQueryUGCNumKeyValueTags", luasteam_UGC_GetQueryUGCNumKeyValueTags);
    add_func(L, "GetNumSupportedGameVersions", luasteam_UGC_GetNumSupportedGameVersions);
    add_func(L, "ReleaseQueryUGCRequest", luasteam_UGC_ReleaseQueryUGCRequest);
    add_func(L, "AddRequiredTag", luasteam_UGC_AddRequiredTag);
    add_func(L, "AddExcludedTag", luasteam_UGC_AddExcludedTag);
    add_func(L, "SetReturnOnlyIDs", luasteam_UGC_SetReturnOnlyIDs);
    add_func(L, "SetReturnKeyValueTags", luasteam_UGC_SetReturnKeyValueTags);
    add_func(L, "SetReturnLongDescription", luasteam_UGC_SetReturnLongDescription);
    add_func(L, "SetReturnMetadata", luasteam_UGC_SetReturnMetadata);
    add_func(L, "SetReturnChildren", luasteam_UGC_SetReturnChildren);
    add_func(L, "SetReturnAdditionalPreviews", luasteam_UGC_SetReturnAdditionalPreviews);
    add_func(L, "SetReturnTotalOnly", luasteam_UGC_SetReturnTotalOnly);
    add_func(L, "SetReturnPlaytimeStats", luasteam_UGC_SetReturnPlaytimeStats);
    add_func(L, "SetLanguage", luasteam_UGC_SetLanguage);
    add_func(L, "SetAllowCachedResponse", luasteam_UGC_SetAllowCachedResponse);
    add_func(L, "SetAdminQuery", luasteam_UGC_SetAdminQuery);
    add_func(L, "SetCloudFileNameFilter", luasteam_UGC_SetCloudFileNameFilter);
    add_func(L, "SetMatchAnyTag", luasteam_UGC_SetMatchAnyTag);
    add_func(L, "SetSearchText", luasteam_UGC_SetSearchText);
    add_func(L, "SetRankedByTrendDays", luasteam_UGC_SetRankedByTrendDays);
    add_func(L, "SetTimeCreatedDateRange", luasteam_UGC_SetTimeCreatedDateRange);
    add_func(L, "SetTimeUpdatedDateRange", luasteam_UGC_SetTimeUpdatedDateRange);
    add_func(L, "AddRequiredKeyValueTag", luasteam_UGC_AddRequiredKeyValueTag);
    add_func(L, "RequestUGCDetails", luasteam_UGC_RequestUGCDetails);
    add_func(L, "CreateItem", luasteam_UGC_CreateItem);
    add_func(L, "StartItemUpdate", luasteam_UGC_StartItemUpdate);
    add_func(L, "SetItemTitle", luasteam_UGC_SetItemTitle);
    add_func(L, "SetItemDescription", luasteam_UGC_SetItemDescription);
    add_func(L, "SetItemUpdateLanguage", luasteam_UGC_SetItemUpdateLanguage);
    add_func(L, "SetItemMetadata", luasteam_UGC_SetItemMetadata);
    add_func(L, "SetItemVisibility", luasteam_UGC_SetItemVisibility);
    add_func(L, "SetItemContent", luasteam_UGC_SetItemContent);
    add_func(L, "SetItemPreview", luasteam_UGC_SetItemPreview);
    add_func(L, "SetAllowLegacyUpload", luasteam_UGC_SetAllowLegacyUpload);
    add_func(L, "RemoveAllItemKeyValueTags", luasteam_UGC_RemoveAllItemKeyValueTags);
    add_func(L, "RemoveItemKeyValueTags", luasteam_UGC_RemoveItemKeyValueTags);
    add_func(L, "AddItemKeyValueTag", luasteam_UGC_AddItemKeyValueTag);
    add_func(L, "AddItemPreviewFile", luasteam_UGC_AddItemPreviewFile);
    add_func(L, "AddItemPreviewVideo", luasteam_UGC_AddItemPreviewVideo);
    add_func(L, "UpdateItemPreviewFile", luasteam_UGC_UpdateItemPreviewFile);
    add_func(L, "UpdateItemPreviewVideo", luasteam_UGC_UpdateItemPreviewVideo);
    add_func(L, "RemoveItemPreview", luasteam_UGC_RemoveItemPreview);
    add_func(L, "AddContentDescriptor", luasteam_UGC_AddContentDescriptor);
    add_func(L, "RemoveContentDescriptor", luasteam_UGC_RemoveContentDescriptor);
    add_func(L, "SetRequiredGameVersions", luasteam_UGC_SetRequiredGameVersions);
    add_func(L, "SubmitItemUpdate", luasteam_UGC_SubmitItemUpdate);
    add_func(L, "GetItemUpdateProgress", luasteam_UGC_GetItemUpdateProgress);
    add_func(L, "SetUserItemVote", luasteam_UGC_SetUserItemVote);
    add_func(L, "GetUserItemVote", luasteam_UGC_GetUserItemVote);
    add_func(L, "AddItemToFavorites", luasteam_UGC_AddItemToFavorites);
    add_func(L, "RemoveItemFromFavorites", luasteam_UGC_RemoveItemFromFavorites);
    add_func(L, "SubscribeItem", luasteam_UGC_SubscribeItem);
    add_func(L, "UnsubscribeItem", luasteam_UGC_UnsubscribeItem);
    add_func(L, "GetNumSubscribedItems", luasteam_UGC_GetNumSubscribedItems);
    add_func(L, "GetItemState", luasteam_UGC_GetItemState);
    add_func(L, "GetItemDownloadInfo", luasteam_UGC_GetItemDownloadInfo);
    add_func(L, "DownloadItem", luasteam_UGC_DownloadItem);
    add_func(L, "BInitWorkshopForGameServer", luasteam_UGC_BInitWorkshopForGameServer);
    add_func(L, "SuspendDownloads", luasteam_UGC_SuspendDownloads);
    add_func(L, "StopPlaytimeTrackingForAllItems", luasteam_UGC_StopPlaytimeTrackingForAllItems);
    add_func(L, "AddDependency", luasteam_UGC_AddDependency);
    add_func(L, "RemoveDependency", luasteam_UGC_RemoveDependency);
    add_func(L, "AddAppDependency", luasteam_UGC_AddAppDependency);
    add_func(L, "RemoveAppDependency", luasteam_UGC_RemoveAppDependency);
    add_func(L, "GetAppDependencies", luasteam_UGC_GetAppDependencies);
    add_func(L, "DeleteItem", luasteam_UGC_DeleteItem);
    add_func(L, "ShowWorkshopEULA", luasteam_UGC_ShowWorkshopEULA);
    add_func(L, "GetWorkshopEULAStatus", luasteam_UGC_GetWorkshopEULAStatus);
}

void add_UGC_auto(lua_State *L) {
    lua_createtable(L, 0, 74);
    register_UGC_auto(L);
    lua_pushvalue(L, -1);
    UGC_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "UGC");
}

} // namespace luasteam
