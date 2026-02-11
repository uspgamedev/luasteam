#include "auto.hpp"

namespace luasteam {

int ugc_ref = LUA_NOREF;

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
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::ugc_ref);
    lua_getfield(L, -1, "onSteamUGCQueryCompleted");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 6);
        luasteam::pushuint64(L, data->m_handle);
        lua_setfield(L, -2, "handle");
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        lua_pushinteger(L, data->m_unNumResultsReturned);
        lua_setfield(L, -2, "numResultsReturned");
        lua_pushinteger(L, data->m_unTotalMatchingResults);
        lua_setfield(L, -2, "totalMatchingResults");
        lua_pushboolean(L, data->m_bCachedData);
        lua_setfield(L, -2, "cachedData");
        lua_pushstring(L, data->m_rgchNextCursor);
        lua_setfield(L, -2, "nextCursor");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnSteamUGCRequestUGCDetailsResult(SteamUGCRequestUGCDetailsResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::ugc_ref);
    lua_getfield(L, -1, "onSteamUGCRequestUGCDetailsResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushboolean(L, data->m_bCachedData);
        lua_setfield(L, -2, "cachedData");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnCreateItemResult(CreateItemResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::ugc_ref);
    lua_getfield(L, -1, "onCreateItemResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "publishedFileId");
        lua_pushboolean(L, data->m_bUserNeedsToAcceptWorkshopLegalAgreement);
        lua_setfield(L, -2, "userNeedsToAcceptWorkshopLegalAgreement");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnSubmitItemUpdateResult(SubmitItemUpdateResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::ugc_ref);
    lua_getfield(L, -1, "onSubmitItemUpdateResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        lua_pushboolean(L, data->m_bUserNeedsToAcceptWorkshopLegalAgreement);
        lua_setfield(L, -2, "userNeedsToAcceptWorkshopLegalAgreement");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "publishedFileId");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnItemInstalled(ItemInstalled_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::ugc_ref);
    lua_getfield(L, -1, "onItemInstalled");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        lua_pushinteger(L, data->m_unAppID);
        lua_setfield(L, -2, "appID");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "publishedFileId");
        luasteam::pushuint64(L, data->m_hLegacyContent);
        lua_setfield(L, -2, "legacyContent");
        luasteam::pushuint64(L, data->m_unManifestID);
        lua_setfield(L, -2, "manifestID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnDownloadItemResult(DownloadItemResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::ugc_ref);
    lua_getfield(L, -1, "onDownloadItemResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->m_unAppID);
        lua_setfield(L, -2, "appID");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "publishedFileId");
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnUserFavoriteItemsListChanged(UserFavoriteItemsListChanged_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::ugc_ref);
    lua_getfield(L, -1, "onUserFavoriteItemsListChanged");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "publishedFileId");
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        lua_pushboolean(L, data->m_bWasAddRequest);
        lua_setfield(L, -2, "wasAddRequest");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnSetUserItemVoteResult(SetUserItemVoteResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::ugc_ref);
    lua_getfield(L, -1, "onSetUserItemVoteResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "publishedFileId");
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        lua_pushboolean(L, data->m_bVoteUp);
        lua_setfield(L, -2, "voteUp");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGetUserItemVoteResult(GetUserItemVoteResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::ugc_ref);
    lua_getfield(L, -1, "onGetUserItemVoteResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 5);
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "publishedFileId");
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        lua_pushboolean(L, data->m_bVotedUp);
        lua_setfield(L, -2, "votedUp");
        lua_pushboolean(L, data->m_bVotedDown);
        lua_setfield(L, -2, "votedDown");
        lua_pushboolean(L, data->m_bVoteSkipped);
        lua_setfield(L, -2, "voteSkipped");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnStartPlaytimeTrackingResult(StartPlaytimeTrackingResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::ugc_ref);
    lua_getfield(L, -1, "onStartPlaytimeTrackingResult");
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

void CallbackListener::OnStopPlaytimeTrackingResult(StopPlaytimeTrackingResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::ugc_ref);
    lua_getfield(L, -1, "onStopPlaytimeTrackingResult");
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

void CallbackListener::OnAddUGCDependencyResult(AddUGCDependencyResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::ugc_ref);
    lua_getfield(L, -1, "onAddUGCDependencyResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "publishedFileId");
        luasteam::pushuint64(L, data->m_nChildPublishedFileId);
        lua_setfield(L, -2, "childPublishedFileId");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnRemoveUGCDependencyResult(RemoveUGCDependencyResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::ugc_ref);
    lua_getfield(L, -1, "onRemoveUGCDependencyResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "publishedFileId");
        luasteam::pushuint64(L, data->m_nChildPublishedFileId);
        lua_setfield(L, -2, "childPublishedFileId");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnAddAppDependencyResult(AddAppDependencyResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::ugc_ref);
    lua_getfield(L, -1, "onAddAppDependencyResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "publishedFileId");
        lua_pushinteger(L, data->m_nAppID);
        lua_setfield(L, -2, "appID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnRemoveAppDependencyResult(RemoveAppDependencyResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::ugc_ref);
    lua_getfield(L, -1, "onRemoveAppDependencyResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "publishedFileId");
        lua_pushinteger(L, data->m_nAppID);
        lua_setfield(L, -2, "appID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGetAppDependenciesResult(GetAppDependenciesResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::ugc_ref);
    lua_getfield(L, -1, "onGetAppDependenciesResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 5);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "publishedFileId");
        lua_pushinteger(L, data->m_nNumAppDependencies);
        lua_setfield(L, -2, "numAppDependencies");
        lua_pushinteger(L, data->m_nTotalNumAppDependencies);
        lua_setfield(L, -2, "totalNumAppDependencies");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnDeleteItemResult(DeleteItemResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::ugc_ref);
    lua_getfield(L, -1, "onDeleteItemResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "publishedFileId");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnUserSubscribedItemsListChanged(UserSubscribedItemsListChanged_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::ugc_ref);
    lua_getfield(L, -1, "onUserSubscribedItemsListChanged");
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

void CallbackListener::OnWorkshopEULAStatus(WorkshopEULAStatus_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::ugc_ref);
    lua_getfield(L, -1, "onWorkshopEULAStatus");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 6);
        lua_pushinteger(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        lua_pushinteger(L, data->m_nAppID);
        lua_setfield(L, -2, "appID");
        lua_pushinteger(L, data->m_unVersion);
        lua_setfield(L, -2, "version");
        lua_pushinteger(L, data->m_rtAction);
        lua_setfield(L, -2, "rtAction");
        lua_pushboolean(L, data->m_bAccepted);
        lua_setfield(L, -2, "accepted");
        lua_pushboolean(L, data->m_bNeedsAction);
        lua_setfield(L, -2, "needsAction");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

CallbackListener *ugc_listener = nullptr;

} // namespace

void init_ugc_auto(lua_State *L) { ugc_listener = new CallbackListener(); }

void shutdown_ugc_auto(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, ugc_ref);
    ugc_ref = LUA_NOREF;
    delete ugc_listener; ugc_listener = nullptr;
}


// UGCQueryHandle_t CreateQueryUserUGCRequest(AccountID_t unAccountID, EUserUGCList eListType, EUGCMatchingUGCType eMatchingUGCType, EUserUGCListSortOrder eSortOrder, AppId_t nCreatorAppID, AppId_t nConsumerAppID, uint32 unPage);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_CreateQueryUserUGCRequest(lua_State *L) {
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
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_CreateQueryAllUGCRequestPage(lua_State *L) {
    EUGCQuery eQueryType = static_cast<EUGCQuery>(luaL_checkint(L, 1));
    EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType = static_cast<EUGCMatchingUGCType>(luaL_checkint(L, 2));
    AppId_t nCreatorAppID = static_cast<AppId_t>(luaL_checkint(L, 3));
    AppId_t nConsumerAppID = static_cast<AppId_t>(luaL_checkint(L, 4));
    uint32 unPage = static_cast<uint32>(luaL_checkint(L, 5));
    luasteam::pushuint64(L, SteamUGC()->CreateQueryAllUGCRequest(eQueryType, eMatchingeMatchingUGCTypeFileType, nCreatorAppID, nConsumerAppID, unPage));
    return 1;
}

// UGCQueryHandle_t CreateQueryAllUGCRequest(EUGCQuery eQueryType, EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType, AppId_t nCreatorAppID, AppId_t nConsumerAppID, const char * pchCursor);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_CreateQueryAllUGCRequestCursor(lua_State *L) {
    EUGCQuery eQueryType = static_cast<EUGCQuery>(luaL_checkint(L, 1));
    EUGCMatchingUGCType eMatchingeMatchingUGCTypeFileType = static_cast<EUGCMatchingUGCType>(luaL_checkint(L, 2));
    AppId_t nCreatorAppID = static_cast<AppId_t>(luaL_checkint(L, 3));
    AppId_t nConsumerAppID = static_cast<AppId_t>(luaL_checkint(L, 4));
    const char *pchCursor = luaL_checkstring(L, 5);
    luasteam::pushuint64(L, SteamUGC()->CreateQueryAllUGCRequest(eQueryType, eMatchingeMatchingUGCTypeFileType, nCreatorAppID, nConsumerAppID, pchCursor));
    return 1;
}

// SteamAPICall_t SendQueryUGCRequest(UGCQueryHandle_t handle);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SendQueryUGCRequest(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamUGC()->SendQueryUGCRequest(handle));
    return 1;
}

// uint32 GetQueryUGCNumTags(UGCQueryHandle_t handle, uint32 index);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_GetQueryUGCNumTags(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
    lua_pushinteger(L, SteamUGC()->GetQueryUGCNumTags(handle, index));
    return 1;
}

// uint32 GetQueryUGCNumAdditionalPreviews(UGCQueryHandle_t handle, uint32 index);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_GetQueryUGCNumAdditionalPreviews(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
    lua_pushinteger(L, SteamUGC()->GetQueryUGCNumAdditionalPreviews(handle, index));
    return 1;
}

// uint32 GetQueryUGCNumKeyValueTags(UGCQueryHandle_t handle, uint32 index);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_GetQueryUGCNumKeyValueTags(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
    lua_pushinteger(L, SteamUGC()->GetQueryUGCNumKeyValueTags(handle, index));
    return 1;
}

// uint32 GetNumSupportedGameVersions(UGCQueryHandle_t handle, uint32 index);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_GetNumSupportedGameVersions(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
    lua_pushinteger(L, SteamUGC()->GetNumSupportedGameVersions(handle, index));
    return 1;
}

// bool ReleaseQueryUGCRequest(UGCQueryHandle_t handle);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_ReleaseQueryUGCRequest(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    lua_pushboolean(L, SteamUGC()->ReleaseQueryUGCRequest(handle));
    return 1;
}

// bool AddRequiredTag(UGCQueryHandle_t handle, const char * pTagName);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_AddRequiredTag(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pTagName = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->AddRequiredTag(handle, pTagName));
    return 1;
}

// bool AddExcludedTag(UGCQueryHandle_t handle, const char * pTagName);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_AddExcludedTag(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pTagName = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->AddExcludedTag(handle, pTagName));
    return 1;
}

// bool SetReturnOnlyIDs(UGCQueryHandle_t handle, bool bReturnOnlyIDs);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SetReturnOnlyIDs(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    bool bReturnOnlyIDs = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamUGC()->SetReturnOnlyIDs(handle, bReturnOnlyIDs));
    return 1;
}

// bool SetReturnKeyValueTags(UGCQueryHandle_t handle, bool bReturnKeyValueTags);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SetReturnKeyValueTags(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    bool bReturnKeyValueTags = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamUGC()->SetReturnKeyValueTags(handle, bReturnKeyValueTags));
    return 1;
}

// bool SetReturnLongDescription(UGCQueryHandle_t handle, bool bReturnLongDescription);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SetReturnLongDescription(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    bool bReturnLongDescription = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamUGC()->SetReturnLongDescription(handle, bReturnLongDescription));
    return 1;
}

// bool SetReturnMetadata(UGCQueryHandle_t handle, bool bReturnMetadata);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SetReturnMetadata(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    bool bReturnMetadata = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamUGC()->SetReturnMetadata(handle, bReturnMetadata));
    return 1;
}

// bool SetReturnChildren(UGCQueryHandle_t handle, bool bReturnChildren);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SetReturnChildren(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    bool bReturnChildren = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamUGC()->SetReturnChildren(handle, bReturnChildren));
    return 1;
}

// bool SetReturnAdditionalPreviews(UGCQueryHandle_t handle, bool bReturnAdditionalPreviews);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SetReturnAdditionalPreviews(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    bool bReturnAdditionalPreviews = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamUGC()->SetReturnAdditionalPreviews(handle, bReturnAdditionalPreviews));
    return 1;
}

// bool SetReturnTotalOnly(UGCQueryHandle_t handle, bool bReturnTotalOnly);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SetReturnTotalOnly(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    bool bReturnTotalOnly = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamUGC()->SetReturnTotalOnly(handle, bReturnTotalOnly));
    return 1;
}

// bool SetReturnPlaytimeStats(UGCQueryHandle_t handle, uint32 unDays);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SetReturnPlaytimeStats(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    uint32 unDays = static_cast<uint32>(luaL_checkint(L, 2));
    lua_pushboolean(L, SteamUGC()->SetReturnPlaytimeStats(handle, unDays));
    return 1;
}

// bool SetLanguage(UGCQueryHandle_t handle, const char * pchLanguage);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SetLanguage(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pchLanguage = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->SetLanguage(handle, pchLanguage));
    return 1;
}

// bool SetAllowCachedResponse(UGCQueryHandle_t handle, uint32 unMaxAgeSeconds);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SetAllowCachedResponse(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    uint32 unMaxAgeSeconds = static_cast<uint32>(luaL_checkint(L, 2));
    lua_pushboolean(L, SteamUGC()->SetAllowCachedResponse(handle, unMaxAgeSeconds));
    return 1;
}

// bool SetAdminQuery(UGCUpdateHandle_t handle, bool bAdminQuery);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SetAdminQuery(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    bool bAdminQuery = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamUGC()->SetAdminQuery(handle, bAdminQuery));
    return 1;
}

// bool SetCloudFileNameFilter(UGCQueryHandle_t handle, const char * pMatchCloudFileName);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SetCloudFileNameFilter(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pMatchCloudFileName = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->SetCloudFileNameFilter(handle, pMatchCloudFileName));
    return 1;
}

// bool SetMatchAnyTag(UGCQueryHandle_t handle, bool bMatchAnyTag);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SetMatchAnyTag(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    bool bMatchAnyTag = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamUGC()->SetMatchAnyTag(handle, bMatchAnyTag));
    return 1;
}

// bool SetSearchText(UGCQueryHandle_t handle, const char * pSearchText);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SetSearchText(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pSearchText = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->SetSearchText(handle, pSearchText));
    return 1;
}

// bool SetRankedByTrendDays(UGCQueryHandle_t handle, uint32 unDays);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SetRankedByTrendDays(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    uint32 unDays = static_cast<uint32>(luaL_checkint(L, 2));
    lua_pushboolean(L, SteamUGC()->SetRankedByTrendDays(handle, unDays));
    return 1;
}

// bool SetTimeCreatedDateRange(UGCQueryHandle_t handle, RTime32 rtStart, RTime32 rtEnd);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SetTimeCreatedDateRange(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    RTime32 rtStart = static_cast<RTime32>(luaL_checkint(L, 2));
    RTime32 rtEnd = static_cast<RTime32>(luaL_checkint(L, 3));
    lua_pushboolean(L, SteamUGC()->SetTimeCreatedDateRange(handle, rtStart, rtEnd));
    return 1;
}

// bool SetTimeUpdatedDateRange(UGCQueryHandle_t handle, RTime32 rtStart, RTime32 rtEnd);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SetTimeUpdatedDateRange(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    RTime32 rtStart = static_cast<RTime32>(luaL_checkint(L, 2));
    RTime32 rtEnd = static_cast<RTime32>(luaL_checkint(L, 3));
    lua_pushboolean(L, SteamUGC()->SetTimeUpdatedDateRange(handle, rtStart, rtEnd));
    return 1;
}

// bool AddRequiredKeyValueTag(UGCQueryHandle_t handle, const char * pKey, const char * pValue);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_AddRequiredKeyValueTag(lua_State *L) {
    UGCQueryHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pKey = luaL_checkstring(L, 2);
    const char *pValue = luaL_checkstring(L, 3);
    lua_pushboolean(L, SteamUGC()->AddRequiredKeyValueTag(handle, pKey, pValue));
    return 1;
}

// SteamAPICall_t RequestUGCDetails(PublishedFileId_t nPublishedFileID, uint32 unMaxAgeSeconds);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_RequestUGCDetails(lua_State *L) {
    PublishedFileId_t nPublishedFileID = luasteam::checkuint64(L, 1);
    uint32 unMaxAgeSeconds = static_cast<uint32>(luaL_checkint(L, 2));
    luasteam::pushuint64(L, SteamUGC()->RequestUGCDetails(nPublishedFileID, unMaxAgeSeconds));
    return 1;
}

// SteamAPICall_t CreateItem(AppId_t nConsumerAppId, EWorkshopFileType eFileType);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_CreateItem(lua_State *L) {
    AppId_t nConsumerAppId = static_cast<AppId_t>(luaL_checkint(L, 1));
    EWorkshopFileType eFileType = static_cast<EWorkshopFileType>(luaL_checkint(L, 2));
    luasteam::pushuint64(L, SteamUGC()->CreateItem(nConsumerAppId, eFileType));
    return 1;
}

// UGCUpdateHandle_t StartItemUpdate(AppId_t nConsumerAppId, PublishedFileId_t nPublishedFileID);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_StartItemUpdate(lua_State *L) {
    AppId_t nConsumerAppId = static_cast<AppId_t>(luaL_checkint(L, 1));
    PublishedFileId_t nPublishedFileID = luasteam::checkuint64(L, 2);
    luasteam::pushuint64(L, SteamUGC()->StartItemUpdate(nConsumerAppId, nPublishedFileID));
    return 1;
}

// bool SetItemTitle(UGCUpdateHandle_t handle, const char * pchTitle);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SetItemTitle(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pchTitle = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->SetItemTitle(handle, pchTitle));
    return 1;
}

// bool SetItemDescription(UGCUpdateHandle_t handle, const char * pchDescription);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SetItemDescription(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pchDescription = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->SetItemDescription(handle, pchDescription));
    return 1;
}

// bool SetItemUpdateLanguage(UGCUpdateHandle_t handle, const char * pchLanguage);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SetItemUpdateLanguage(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pchLanguage = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->SetItemUpdateLanguage(handle, pchLanguage));
    return 1;
}

// bool SetItemMetadata(UGCUpdateHandle_t handle, const char * pchMetaData);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SetItemMetadata(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pchMetaData = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->SetItemMetadata(handle, pchMetaData));
    return 1;
}

// bool SetItemVisibility(UGCUpdateHandle_t handle, ERemoteStoragePublishedFileVisibility eVisibility);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SetItemVisibility(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    ERemoteStoragePublishedFileVisibility eVisibility = static_cast<ERemoteStoragePublishedFileVisibility>(luaL_checkint(L, 2));
    lua_pushboolean(L, SteamUGC()->SetItemVisibility(handle, eVisibility));
    return 1;
}

// bool SetItemContent(UGCUpdateHandle_t handle, const char * pszContentFolder);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SetItemContent(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pszContentFolder = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->SetItemContent(handle, pszContentFolder));
    return 1;
}

// bool SetItemPreview(UGCUpdateHandle_t handle, const char * pszPreviewFile);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SetItemPreview(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pszPreviewFile = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->SetItemPreview(handle, pszPreviewFile));
    return 1;
}

// bool SetAllowLegacyUpload(UGCUpdateHandle_t handle, bool bAllowLegacyUpload);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SetAllowLegacyUpload(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    bool bAllowLegacyUpload = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamUGC()->SetAllowLegacyUpload(handle, bAllowLegacyUpload));
    return 1;
}

// bool RemoveAllItemKeyValueTags(UGCUpdateHandle_t handle);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_RemoveAllItemKeyValueTags(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    lua_pushboolean(L, SteamUGC()->RemoveAllItemKeyValueTags(handle));
    return 1;
}

// bool RemoveItemKeyValueTags(UGCUpdateHandle_t handle, const char * pchKey);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_RemoveItemKeyValueTags(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pchKey = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->RemoveItemKeyValueTags(handle, pchKey));
    return 1;
}

// bool AddItemKeyValueTag(UGCUpdateHandle_t handle, const char * pchKey, const char * pchValue);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_AddItemKeyValueTag(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pchKey = luaL_checkstring(L, 2);
    const char *pchValue = luaL_checkstring(L, 3);
    lua_pushboolean(L, SteamUGC()->AddItemKeyValueTag(handle, pchKey, pchValue));
    return 1;
}

// bool AddItemPreviewFile(UGCUpdateHandle_t handle, const char * pszPreviewFile, EItemPreviewType type);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_AddItemPreviewFile(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pszPreviewFile = luaL_checkstring(L, 2);
    EItemPreviewType type = static_cast<EItemPreviewType>(luaL_checkint(L, 3));
    lua_pushboolean(L, SteamUGC()->AddItemPreviewFile(handle, pszPreviewFile, type));
    return 1;
}

// bool AddItemPreviewVideo(UGCUpdateHandle_t handle, const char * pszVideoID);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_AddItemPreviewVideo(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pszVideoID = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->AddItemPreviewVideo(handle, pszVideoID));
    return 1;
}

// bool UpdateItemPreviewFile(UGCUpdateHandle_t handle, uint32 index, const char * pszPreviewFile);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_UpdateItemPreviewFile(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
    const char *pszPreviewFile = luaL_checkstring(L, 3);
    lua_pushboolean(L, SteamUGC()->UpdateItemPreviewFile(handle, index, pszPreviewFile));
    return 1;
}

// bool UpdateItemPreviewVideo(UGCUpdateHandle_t handle, uint32 index, const char * pszVideoID);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_UpdateItemPreviewVideo(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
    const char *pszVideoID = luaL_checkstring(L, 3);
    lua_pushboolean(L, SteamUGC()->UpdateItemPreviewVideo(handle, index, pszVideoID));
    return 1;
}

// bool RemoveItemPreview(UGCUpdateHandle_t handle, uint32 index);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_RemoveItemPreview(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    uint32 index = static_cast<uint32>(luaL_checkint(L, 2));
    lua_pushboolean(L, SteamUGC()->RemoveItemPreview(handle, index));
    return 1;
}

// bool AddContentDescriptor(UGCUpdateHandle_t handle, EUGCContentDescriptorID descid);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_AddContentDescriptor(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    EUGCContentDescriptorID descid = static_cast<EUGCContentDescriptorID>(luaL_checkint(L, 2));
    lua_pushboolean(L, SteamUGC()->AddContentDescriptor(handle, descid));
    return 1;
}

// bool RemoveContentDescriptor(UGCUpdateHandle_t handle, EUGCContentDescriptorID descid);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_RemoveContentDescriptor(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    EUGCContentDescriptorID descid = static_cast<EUGCContentDescriptorID>(luaL_checkint(L, 2));
    lua_pushboolean(L, SteamUGC()->RemoveContentDescriptor(handle, descid));
    return 1;
}

// bool SetRequiredGameVersions(UGCUpdateHandle_t handle, const char * pszGameBranchMin, const char * pszGameBranchMax);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SetRequiredGameVersions(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pszGameBranchMin = luaL_checkstring(L, 2);
    const char *pszGameBranchMax = luaL_checkstring(L, 3);
    lua_pushboolean(L, SteamUGC()->SetRequiredGameVersions(handle, pszGameBranchMin, pszGameBranchMax));
    return 1;
}

// SteamAPICall_t SubmitItemUpdate(UGCUpdateHandle_t handle, const char * pchChangeNote);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SubmitItemUpdate(lua_State *L) {
    UGCUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    const char *pchChangeNote = luaL_checkstring(L, 2);
    luasteam::pushuint64(L, SteamUGC()->SubmitItemUpdate(handle, pchChangeNote));
    return 1;
}

// SteamAPICall_t SetUserItemVote(PublishedFileId_t nPublishedFileID, bool bVoteUp);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SetUserItemVote(lua_State *L) {
    PublishedFileId_t nPublishedFileID = luasteam::checkuint64(L, 1);
    bool bVoteUp = lua_toboolean(L, 2);
    luasteam::pushuint64(L, SteamUGC()->SetUserItemVote(nPublishedFileID, bVoteUp));
    return 1;
}

// SteamAPICall_t GetUserItemVote(PublishedFileId_t nPublishedFileID);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_GetUserItemVote(lua_State *L) {
    PublishedFileId_t nPublishedFileID = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamUGC()->GetUserItemVote(nPublishedFileID));
    return 1;
}

// SteamAPICall_t AddItemToFavorites(AppId_t nAppId, PublishedFileId_t nPublishedFileID);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_AddItemToFavorites(lua_State *L) {
    AppId_t nAppId = static_cast<AppId_t>(luaL_checkint(L, 1));
    PublishedFileId_t nPublishedFileID = luasteam::checkuint64(L, 2);
    luasteam::pushuint64(L, SteamUGC()->AddItemToFavorites(nAppId, nPublishedFileID));
    return 1;
}

// SteamAPICall_t RemoveItemFromFavorites(AppId_t nAppId, PublishedFileId_t nPublishedFileID);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_RemoveItemFromFavorites(lua_State *L) {
    AppId_t nAppId = static_cast<AppId_t>(luaL_checkint(L, 1));
    PublishedFileId_t nPublishedFileID = luasteam::checkuint64(L, 2);
    luasteam::pushuint64(L, SteamUGC()->RemoveItemFromFavorites(nAppId, nPublishedFileID));
    return 1;
}

// SteamAPICall_t SubscribeItem(PublishedFileId_t nPublishedFileID);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SubscribeItem(lua_State *L) {
    PublishedFileId_t nPublishedFileID = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamUGC()->SubscribeItem(nPublishedFileID));
    return 1;
}

// SteamAPICall_t UnsubscribeItem(PublishedFileId_t nPublishedFileID);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_UnsubscribeItem(lua_State *L) {
    PublishedFileId_t nPublishedFileID = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamUGC()->UnsubscribeItem(nPublishedFileID));
    return 1;
}

// uint32 GetNumSubscribedItems(bool bIncludeLocallyDisabled);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_GetNumSubscribedItems(lua_State *L) {
    bool bIncludeLocallyDisabled = lua_toboolean(L, 1);
    lua_pushinteger(L, SteamUGC()->GetNumSubscribedItems(bIncludeLocallyDisabled));
    return 1;
}

// uint32 GetItemState(PublishedFileId_t nPublishedFileID);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_GetItemState(lua_State *L) {
    PublishedFileId_t nPublishedFileID = luasteam::checkuint64(L, 1);
    lua_pushinteger(L, SteamUGC()->GetItemState(nPublishedFileID));
    return 1;
}

// bool DownloadItem(PublishedFileId_t nPublishedFileID, bool bHighPriority);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_DownloadItem(lua_State *L) {
    PublishedFileId_t nPublishedFileID = luasteam::checkuint64(L, 1);
    bool bHighPriority = lua_toboolean(L, 2);
    lua_pushboolean(L, SteamUGC()->DownloadItem(nPublishedFileID, bHighPriority));
    return 1;
}

// bool BInitWorkshopForGameServer(DepotId_t unWorkshopDepotID, const char * pszFolder);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_BInitWorkshopForGameServer(lua_State *L) {
    DepotId_t unWorkshopDepotID = static_cast<DepotId_t>(luaL_checkint(L, 1));
    const char *pszFolder = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->BInitWorkshopForGameServer(unWorkshopDepotID, pszFolder));
    return 1;
}

// void SuspendDownloads(bool bSuspend);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_SuspendDownloads(lua_State *L) {
    bool bSuspend = lua_toboolean(L, 1);
    SteamUGC()->SuspendDownloads(bSuspend);
    return 0;
}

// SteamAPICall_t StopPlaytimeTrackingForAllItems();
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_StopPlaytimeTrackingForAllItems(lua_State *L) {
    luasteam::pushuint64(L, SteamUGC()->StopPlaytimeTrackingForAllItems());
    return 1;
}

// SteamAPICall_t AddDependency(PublishedFileId_t nParentPublishedFileID, PublishedFileId_t nChildPublishedFileID);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_AddDependency(lua_State *L) {
    PublishedFileId_t nParentPublishedFileID = luasteam::checkuint64(L, 1);
    PublishedFileId_t nChildPublishedFileID = luasteam::checkuint64(L, 2);
    luasteam::pushuint64(L, SteamUGC()->AddDependency(nParentPublishedFileID, nChildPublishedFileID));
    return 1;
}

// SteamAPICall_t RemoveDependency(PublishedFileId_t nParentPublishedFileID, PublishedFileId_t nChildPublishedFileID);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_RemoveDependency(lua_State *L) {
    PublishedFileId_t nParentPublishedFileID = luasteam::checkuint64(L, 1);
    PublishedFileId_t nChildPublishedFileID = luasteam::checkuint64(L, 2);
    luasteam::pushuint64(L, SteamUGC()->RemoveDependency(nParentPublishedFileID, nChildPublishedFileID));
    return 1;
}

// SteamAPICall_t AddAppDependency(PublishedFileId_t nPublishedFileID, AppId_t nAppID);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_AddAppDependency(lua_State *L) {
    PublishedFileId_t nPublishedFileID = luasteam::checkuint64(L, 1);
    AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 2));
    luasteam::pushuint64(L, SteamUGC()->AddAppDependency(nPublishedFileID, nAppID));
    return 1;
}

// SteamAPICall_t RemoveAppDependency(PublishedFileId_t nPublishedFileID, AppId_t nAppID);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_RemoveAppDependency(lua_State *L) {
    PublishedFileId_t nPublishedFileID = luasteam::checkuint64(L, 1);
    AppId_t nAppID = static_cast<AppId_t>(luaL_checkint(L, 2));
    luasteam::pushuint64(L, SteamUGC()->RemoveAppDependency(nPublishedFileID, nAppID));
    return 1;
}

// SteamAPICall_t GetAppDependencies(PublishedFileId_t nPublishedFileID);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_GetAppDependencies(lua_State *L) {
    PublishedFileId_t nPublishedFileID = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamUGC()->GetAppDependencies(nPublishedFileID));
    return 1;
}

// SteamAPICall_t DeleteItem(PublishedFileId_t nPublishedFileID);
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_DeleteItem(lua_State *L) {
    PublishedFileId_t nPublishedFileID = luasteam::checkuint64(L, 1);
    luasteam::pushuint64(L, SteamUGC()->DeleteItem(nPublishedFileID));
    return 1;
}

// bool ShowWorkshopEULA();
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_ShowWorkshopEULA(lua_State *L) {
    lua_pushboolean(L, SteamUGC()->ShowWorkshopEULA());
    return 1;
}

// SteamAPICall_t GetWorkshopEULAStatus();
EXTERN int luasteam_ugc_SteamAPI_ISteamUGC_GetWorkshopEULAStatus(lua_State *L) {
    luasteam::pushuint64(L, SteamUGC()->GetWorkshopEULAStatus());
    return 1;
}

void register_ugc_auto(lua_State *L) {
    add_func(L, "createQueryUserUGCRequest", luasteam_ugc_SteamAPI_ISteamUGC_CreateQueryUserUGCRequest);
    add_func(L, "createQueryAllUGCRequest", luasteam_ugc_SteamAPI_ISteamUGC_CreateQueryAllUGCRequestPage);
    add_func(L, "createQueryAllUGCRequest", luasteam_ugc_SteamAPI_ISteamUGC_CreateQueryAllUGCRequestCursor);
    add_func(L, "sendQueryUGCRequest", luasteam_ugc_SteamAPI_ISteamUGC_SendQueryUGCRequest);
    add_func(L, "getQueryUGCNumTags", luasteam_ugc_SteamAPI_ISteamUGC_GetQueryUGCNumTags);
    add_func(L, "getQueryUGCNumAdditionalPreviews", luasteam_ugc_SteamAPI_ISteamUGC_GetQueryUGCNumAdditionalPreviews);
    add_func(L, "getQueryUGCNumKeyValueTags", luasteam_ugc_SteamAPI_ISteamUGC_GetQueryUGCNumKeyValueTags);
    add_func(L, "getNumSupportedGameVersions", luasteam_ugc_SteamAPI_ISteamUGC_GetNumSupportedGameVersions);
    add_func(L, "releaseQueryUGCRequest", luasteam_ugc_SteamAPI_ISteamUGC_ReleaseQueryUGCRequest);
    add_func(L, "addRequiredTag", luasteam_ugc_SteamAPI_ISteamUGC_AddRequiredTag);
    add_func(L, "addExcludedTag", luasteam_ugc_SteamAPI_ISteamUGC_AddExcludedTag);
    add_func(L, "setReturnOnlyIDs", luasteam_ugc_SteamAPI_ISteamUGC_SetReturnOnlyIDs);
    add_func(L, "setReturnKeyValueTags", luasteam_ugc_SteamAPI_ISteamUGC_SetReturnKeyValueTags);
    add_func(L, "setReturnLongDescription", luasteam_ugc_SteamAPI_ISteamUGC_SetReturnLongDescription);
    add_func(L, "setReturnMetadata", luasteam_ugc_SteamAPI_ISteamUGC_SetReturnMetadata);
    add_func(L, "setReturnChildren", luasteam_ugc_SteamAPI_ISteamUGC_SetReturnChildren);
    add_func(L, "setReturnAdditionalPreviews", luasteam_ugc_SteamAPI_ISteamUGC_SetReturnAdditionalPreviews);
    add_func(L, "setReturnTotalOnly", luasteam_ugc_SteamAPI_ISteamUGC_SetReturnTotalOnly);
    add_func(L, "setReturnPlaytimeStats", luasteam_ugc_SteamAPI_ISteamUGC_SetReturnPlaytimeStats);
    add_func(L, "setLanguage", luasteam_ugc_SteamAPI_ISteamUGC_SetLanguage);
    add_func(L, "setAllowCachedResponse", luasteam_ugc_SteamAPI_ISteamUGC_SetAllowCachedResponse);
    add_func(L, "setAdminQuery", luasteam_ugc_SteamAPI_ISteamUGC_SetAdminQuery);
    add_func(L, "setCloudFileNameFilter", luasteam_ugc_SteamAPI_ISteamUGC_SetCloudFileNameFilter);
    add_func(L, "setMatchAnyTag", luasteam_ugc_SteamAPI_ISteamUGC_SetMatchAnyTag);
    add_func(L, "setSearchText", luasteam_ugc_SteamAPI_ISteamUGC_SetSearchText);
    add_func(L, "setRankedByTrendDays", luasteam_ugc_SteamAPI_ISteamUGC_SetRankedByTrendDays);
    add_func(L, "setTimeCreatedDateRange", luasteam_ugc_SteamAPI_ISteamUGC_SetTimeCreatedDateRange);
    add_func(L, "setTimeUpdatedDateRange", luasteam_ugc_SteamAPI_ISteamUGC_SetTimeUpdatedDateRange);
    add_func(L, "addRequiredKeyValueTag", luasteam_ugc_SteamAPI_ISteamUGC_AddRequiredKeyValueTag);
    add_func(L, "requestUGCDetails", luasteam_ugc_SteamAPI_ISteamUGC_RequestUGCDetails);
    add_func(L, "createItem", luasteam_ugc_SteamAPI_ISteamUGC_CreateItem);
    add_func(L, "startItemUpdate", luasteam_ugc_SteamAPI_ISteamUGC_StartItemUpdate);
    add_func(L, "setItemTitle", luasteam_ugc_SteamAPI_ISteamUGC_SetItemTitle);
    add_func(L, "setItemDescription", luasteam_ugc_SteamAPI_ISteamUGC_SetItemDescription);
    add_func(L, "setItemUpdateLanguage", luasteam_ugc_SteamAPI_ISteamUGC_SetItemUpdateLanguage);
    add_func(L, "setItemMetadata", luasteam_ugc_SteamAPI_ISteamUGC_SetItemMetadata);
    add_func(L, "setItemVisibility", luasteam_ugc_SteamAPI_ISteamUGC_SetItemVisibility);
    add_func(L, "setItemContent", luasteam_ugc_SteamAPI_ISteamUGC_SetItemContent);
    add_func(L, "setItemPreview", luasteam_ugc_SteamAPI_ISteamUGC_SetItemPreview);
    add_func(L, "setAllowLegacyUpload", luasteam_ugc_SteamAPI_ISteamUGC_SetAllowLegacyUpload);
    add_func(L, "removeAllItemKeyValueTags", luasteam_ugc_SteamAPI_ISteamUGC_RemoveAllItemKeyValueTags);
    add_func(L, "removeItemKeyValueTags", luasteam_ugc_SteamAPI_ISteamUGC_RemoveItemKeyValueTags);
    add_func(L, "addItemKeyValueTag", luasteam_ugc_SteamAPI_ISteamUGC_AddItemKeyValueTag);
    add_func(L, "addItemPreviewFile", luasteam_ugc_SteamAPI_ISteamUGC_AddItemPreviewFile);
    add_func(L, "addItemPreviewVideo", luasteam_ugc_SteamAPI_ISteamUGC_AddItemPreviewVideo);
    add_func(L, "updateItemPreviewFile", luasteam_ugc_SteamAPI_ISteamUGC_UpdateItemPreviewFile);
    add_func(L, "updateItemPreviewVideo", luasteam_ugc_SteamAPI_ISteamUGC_UpdateItemPreviewVideo);
    add_func(L, "removeItemPreview", luasteam_ugc_SteamAPI_ISteamUGC_RemoveItemPreview);
    add_func(L, "addContentDescriptor", luasteam_ugc_SteamAPI_ISteamUGC_AddContentDescriptor);
    add_func(L, "removeContentDescriptor", luasteam_ugc_SteamAPI_ISteamUGC_RemoveContentDescriptor);
    add_func(L, "setRequiredGameVersions", luasteam_ugc_SteamAPI_ISteamUGC_SetRequiredGameVersions);
    add_func(L, "submitItemUpdate", luasteam_ugc_SteamAPI_ISteamUGC_SubmitItemUpdate);
    add_func(L, "setUserItemVote", luasteam_ugc_SteamAPI_ISteamUGC_SetUserItemVote);
    add_func(L, "getUserItemVote", luasteam_ugc_SteamAPI_ISteamUGC_GetUserItemVote);
    add_func(L, "addItemToFavorites", luasteam_ugc_SteamAPI_ISteamUGC_AddItemToFavorites);
    add_func(L, "removeItemFromFavorites", luasteam_ugc_SteamAPI_ISteamUGC_RemoveItemFromFavorites);
    add_func(L, "subscribeItem", luasteam_ugc_SteamAPI_ISteamUGC_SubscribeItem);
    add_func(L, "unsubscribeItem", luasteam_ugc_SteamAPI_ISteamUGC_UnsubscribeItem);
    add_func(L, "getNumSubscribedItems", luasteam_ugc_SteamAPI_ISteamUGC_GetNumSubscribedItems);
    add_func(L, "getItemState", luasteam_ugc_SteamAPI_ISteamUGC_GetItemState);
    add_func(L, "downloadItem", luasteam_ugc_SteamAPI_ISteamUGC_DownloadItem);
    add_func(L, "initWorkshopForGameServer", luasteam_ugc_SteamAPI_ISteamUGC_BInitWorkshopForGameServer);
    add_func(L, "suspendDownloads", luasteam_ugc_SteamAPI_ISteamUGC_SuspendDownloads);
    add_func(L, "stopPlaytimeTrackingForAllItems", luasteam_ugc_SteamAPI_ISteamUGC_StopPlaytimeTrackingForAllItems);
    add_func(L, "addDependency", luasteam_ugc_SteamAPI_ISteamUGC_AddDependency);
    add_func(L, "removeDependency", luasteam_ugc_SteamAPI_ISteamUGC_RemoveDependency);
    add_func(L, "addAppDependency", luasteam_ugc_SteamAPI_ISteamUGC_AddAppDependency);
    add_func(L, "removeAppDependency", luasteam_ugc_SteamAPI_ISteamUGC_RemoveAppDependency);
    add_func(L, "getAppDependencies", luasteam_ugc_SteamAPI_ISteamUGC_GetAppDependencies);
    add_func(L, "deleteItem", luasteam_ugc_SteamAPI_ISteamUGC_DeleteItem);
    add_func(L, "showWorkshopEULA", luasteam_ugc_SteamAPI_ISteamUGC_ShowWorkshopEULA);
    add_func(L, "getWorkshopEULAStatus", luasteam_ugc_SteamAPI_ISteamUGC_GetWorkshopEULAStatus);
}

void add_ugc_auto(lua_State *L) {
    lua_createtable(L, 0, 72);
    register_ugc_auto(L);
    lua_pushvalue(L, -1);
    ugc_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "UGC");
}

} // namespace luasteam
