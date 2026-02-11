#include "UGC.hpp"
#include "auto/auto.hpp"
#include <array>
#include <vector>

// ========================
// ======= SteamUGC =======
// ========================

using luasteam::CallResultListener;

namespace {

const char *update_status[] = {
    "Invalid", "PreparingConfig", "PreparingContent", "UploadingContent", "UploadingPreviewFile", "CommittingChanges",
};

} // namespace

namespace luasteam {

template <> void CallResultListener<CreateItemResult_t>::Result(CreateItemResult_t *data, bool io_fail) {
    lua_State *L = luasteam::global_lua_state;
    // getting stored callback function
    lua_rawgeti(L, LUA_REGISTRYINDEX, callback_ref);
    luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);
    // calling function
    if (io_fail) {
        lua_pushnil(L);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushnumber(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "publishedFileId");
        lua_pushboolean(L, data->m_bUserNeedsToAcceptWorkshopLegalAgreement);
        lua_setfield(L, -2, "userNeedsToAcceptWorkshopLegalAgreement");
    }
    lua_pushboolean(L, io_fail);
    lua_call(L, 2, 0);
    delete this; // DELET THIS
}

template <> void CallResultListener<SubmitItemUpdateResult_t>::Result(SubmitItemUpdateResult_t *data, bool io_fail) {
    lua_State *L = luasteam::global_lua_state;
    // getting stored callback function
    lua_rawgeti(L, LUA_REGISTRYINDEX, callback_ref);
    luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);
    // calling function
    if (io_fail)
        lua_pushnil(L);
    else {
        lua_createtable(L, 0, 2);
        lua_pushnumber(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        lua_pushboolean(L, data->m_bUserNeedsToAcceptWorkshopLegalAgreement);
        lua_setfield(L, -2, "userNeedsToAcceptWorkshopLegalAgreement");
    }
    lua_pushboolean(L, io_fail);
    lua_call(L, 2, 0);
    delete this;
}

static void SimpleResultListener(int callback_ref, int result, bool io_fail) {
    lua_State *L = luasteam::global_lua_state;
    // getting stored callback function
    lua_rawgeti(L, LUA_REGISTRYINDEX, callback_ref);
    luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);
    // calling function
    if (io_fail) {
        lua_pushnil(L);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushnumber(L, result);
        lua_setfield(L, -2, "result");
    }
    lua_pushboolean(L, io_fail);
    lua_call(L, 2, 0);
}

template <> void CallResultListener<StartPlaytimeTrackingResult_t>::Result(StartPlaytimeTrackingResult_t *data, bool io_fail) {
    SimpleResultListener(callback_ref, io_fail ? -1 : data->m_eResult, io_fail);
    delete this;
}

template <> void CallResultListener<StopPlaytimeTrackingResult_t>::Result(StopPlaytimeTrackingResult_t *data, bool io_fail) {
    SimpleResultListener(callback_ref, io_fail ? -1 : data->m_eResult, io_fail);
    delete this;
}

template <> void CallResultListener<RemoteStorageSubscribePublishedFileResult_t>::Result(RemoteStorageSubscribePublishedFileResult_t *data, bool io_fail) {
    lua_State *L = luasteam::global_lua_state;
    // getting stored callback function
    lua_rawgeti(L, LUA_REGISTRYINDEX, callback_ref);
    luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);
    // calling function
    if (io_fail)
        lua_pushnil(L);
    else {
        lua_createtable(L, 0, 2);
        lua_pushnumber(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "publishedFileId");
    }
    lua_pushboolean(L, io_fail);
    lua_call(L, 2, 0);
    delete this;
}

template <> void CallResultListener<RemoteStorageUnsubscribePublishedFileResult_t>::Result(RemoteStorageUnsubscribePublishedFileResult_t *data, bool io_fail) {
    lua_State *L = luasteam::global_lua_state;
    // getting stored callback function
    lua_rawgeti(L, LUA_REGISTRYINDEX, callback_ref);
    luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);
    // calling function
    if (io_fail)
        lua_pushnil(L);
    else {
        lua_createtable(L, 0, 2);
        lua_pushnumber(L, data->m_eResult);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_nPublishedFileId);
        lua_setfield(L, -2, "publishedFileId");
    }
    lua_pushboolean(L, io_fail);
    lua_call(L, 2, 0);
    delete this;
}

} // namespace luasteam

// Manually implemented to handle CallResult
// SteamAPICall_t CreateItem( AppId_t nConsumerAppId, EWorkshopFileType eFileType );
EXTERN int luasteam_createItem(lua_State *L) {
    int consumerAppID = luaL_checkint(L, 1);
    EWorkshopFileType fileType = static_cast<EWorkshopFileType>(luaL_checkint(L, 2));
    luaL_checktype(L, 3, LUA_TFUNCTION);
    auto *listener = new CallResultListener<CreateItemResult_t>();
    lua_settop(L, 3);
    listener->callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    SteamAPICall_t call = SteamUGC()->CreateItem(consumerAppID, fileType);
    listener->call_result.Set(call, listener, &CallResultListener<CreateItemResult_t>::Result);
    return 0;
}

// Manually implemented to handle CallResult
// SteamAPICall_t SubmitItemUpdate( UGCUpdateHandle_t handle, const char *pchChangeNote );
EXTERN int luasteam_submitItemUpdate(lua_State *L) {
    uint64 handle = luasteam::checkuint64(L, 1);
    const char *changeNote = luaL_optstring(L, 2, nullptr);
    luaL_checktype(L, 3, LUA_TFUNCTION);
    auto *listener = new CallResultListener<SubmitItemUpdateResult_t>();
    lua_settop(L, 3);
    listener->callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    SteamAPICall_t call = SteamUGC()->SubmitItemUpdate(handle, changeNote);
    listener->call_result.Set(call, listener, &CallResultListener<SubmitItemUpdateResult_t>::Result);
    return 0;
}

// Manually implemented to return a table of IDs
// uint32 GetSubscribedItems( PublishedFileId_t*pvecPublishedFileID, uint32 cMaxEntries );
EXTERN int luasteam_getSubscribedItems(lua_State *L) {
    int sz = SteamUGC()->GetNumSubscribedItems();
    std::vector<PublishedFileId_t> vec(sz);
    sz = SteamUGC()->GetSubscribedItems(vec.data(), sz);
    lua_createtable(L, sz, 0);
    for (int i = 0; i < sz; i++) {
        luasteam::pushuint64(L, vec[i]);
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}

// Manually implemented to return a table of flags
// uint32 GetItemState( PublishedFileId_t nPublishedFileID );
EXTERN int luasteam_getItemState(lua_State *L) {
    PublishedFileId_t id = luasteam::checkuint64(L, 1);
    uint32 flags = SteamUGC()->GetItemState(id);
    if (flags == 0)
        lua_pushnil(L);
    else {
        lua_createtable(L, 0, 6);
        lua_pushboolean(L, !!(flags & k_EItemStateSubscribed));
        lua_setfield(L, -2, "subscribed");
        lua_pushboolean(L, !!(flags & k_EItemStateLegacyItem));
        lua_setfield(L, -2, "legacyItem");
        lua_pushboolean(L, !!(flags & k_EItemStateInstalled));
        lua_setfield(L, -2, "installed");
        lua_pushboolean(L, !!(flags & k_EItemStateNeedsUpdate));
        lua_setfield(L, -2, "needsUpdate");
        lua_pushboolean(L, !!(flags & k_EItemStateDownloading));
        lua_setfield(L, -2, "downloading");
        lua_pushboolean(L, !!(flags & k_EItemStateDownloadPending));
        lua_setfield(L, -2, "downloadPending");
    }
    return 1;
}

// Manually implemented to handle multiple output parameters
// bool GetItemInstallInfo( PublishedFileId_t nPublishedFileID, uint64 *punSizeOnDisk, char *pchFolder, uint32 cchFolderSize, uint32 *punTimeStamp );
EXTERN int luasteam_getItemInstallInfo(lua_State *L) {
    PublishedFileId_t id = luasteam::checkuint64(L, 1);
    uint64 sizeOnDisk;
    const int size = 256;
    std::array<char, size> folder;
    uint32 timestamp;
    bool success = SteamUGC()->GetItemInstallInfo(id, &sizeOnDisk, folder.data(), size, &timestamp);
    lua_pushboolean(L, success);
    if (success) {
        // This is an uint64 and can't exactly fit into a double
        // But I think it's better to use a number than the uint64 functions in common.hpp
        // Since the exact integer value isn't that important
        lua_pushnumber(L, sizeOnDisk);
        lua_pushstring(L, folder.data());
        lua_pushnumber(L, timestamp);
        return 4;
    } else
        return 1;
}

// Manually implemented to handle multiple output parameters
// EItemUpdateStatus GetItemUpdateProgress( UGCUpdateHandle_t handle, uint64 *punBytesProcessed, uint64*punBytesTotal );
EXTERN int luasteam_getItemUpdateProgress(lua_State *L) {
    uint64 handle = luasteam::checkuint64(L, 1);
    uint64 processed, total;
    EItemUpdateStatus st = SteamUGC()->GetItemUpdateProgress(handle, &processed, &total);
    lua_pushstring(L, update_status[st]);
    lua_pushnumber(L, processed);
    lua_pushnumber(L, total);
    return 3;
}

// the table should be on index
static std::vector<PublishedFileId_t> getFileIdList(lua_State *L, int index) {
    luaL_checktype(L, index, LUA_TTABLE);
    const int size = lua_objlen(L, index);
    if (size < 1 || size > 100) {
        return {};
    }
    std::vector<PublishedFileId_t> vec(size);
    for (int i = 0; i < size; i++) {
        lua_rawgeti(L, index, i + 1);
        vec[i] = luasteam::assertuint64(L, lua_gettop(L), "Index %d of argument #%d is invalid", i + 1, index);
        lua_pop(L, 1);
    }
    return vec;
}

// Manually implemented to handle array input and CallResult
// SteamAPICall_t StartPlaytimeTracking( PublishedFileId_t *pvecPublishedFileID, uint32 unNumPublishedFileIDs );
EXTERN int luasteam_startPlaytimeTracking(lua_State *L) {
    luaL_checktype(L, 2, LUA_TFUNCTION);
    std::vector<PublishedFileId_t> vec(getFileIdList(L, 1));
    if (vec.empty()) {
        return 0;
    }
    SteamAPICall_t call = SteamUGC()->StartPlaytimeTracking(&vec[0], vec.size());
    auto *listener = new CallResultListener<StartPlaytimeTrackingResult_t>();
    lua_settop(L, 2);
    listener->callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    listener->call_result.Set(call, listener, &CallResultListener<StartPlaytimeTrackingResult_t>::Result);
    return 0;
}

// Manually implemented to handle array input and CallResult
// SteamAPICall_t StopPlaytimeTracking( PublishedFileId_t *pvecPublishedFileID, uint32 unNumPublishedFileIDs );
EXTERN int luasteam_stopPlaytimeTracking(lua_State *L) {
    luaL_checktype(L, 2, LUA_TFUNCTION);
    auto vec = getFileIdList(L, 1);
    if (vec.empty()) {
        return 0;
    }
    SteamAPICall_t call = SteamUGC()->StopPlaytimeTracking(&vec[0], vec.size());
    auto *listener = new CallResultListener<StopPlaytimeTrackingResult_t>();
    lua_settop(L, 2);
    listener->callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    listener->call_result.Set(call, listener, &CallResultListener<StopPlaytimeTrackingResult_t>::Result);
    return 0;
}

// Manually implemented to handle CallResult
// SteamAPICall_t StopPlaytimeTrackingForAllItems();
EXTERN int luasteam_stopPlaytimeTrackingForAllItems(lua_State *L) {
    luaL_checktype(L, 1, LUA_TFUNCTION);
    SteamAPICall_t call = SteamUGC()->StopPlaytimeTrackingForAllItems();
    auto *listener = new CallResultListener<StopPlaytimeTrackingResult_t>();
    lua_settop(L, 1);
    listener->callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    listener->call_result.Set(call, listener, &CallResultListener<StopPlaytimeTrackingResult_t>::Result);
    return 0;
}

// Manually implemented to handle CallResult
// SteamAPICall_t SubscribeItem( PublishedFileId_t nPublishedFileID );
EXTERN int luasteam_subscribeItem(lua_State *L) {
    uint64 itemId = luasteam::checkuint64(L, 1);
    luaL_checktype(L, 2, LUA_TFUNCTION);
    auto *listener = new CallResultListener<RemoteStorageSubscribePublishedFileResult_t>();
    lua_settop(L, 2);
    listener->callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    SteamAPICall_t call = SteamUGC()->SubscribeItem(itemId);
    listener->call_result.Set(call, listener, &CallResultListener<RemoteStorageSubscribePublishedFileResult_t>::Result);
    return 0;
}

// Manually implemented to handle CallResult
// SteamAPICall_t UnsubscribeItem( PublishedFileId_t nPublishedFileID );
EXTERN int luasteam_unsubscribeItem(lua_State *L) {
    uint64 itemId = luasteam::checkuint64(L, 1);
    luaL_checktype(L, 2, LUA_TFUNCTION);
    auto *listener = new CallResultListener<RemoteStorageUnsubscribePublishedFileResult_t>();
    lua_settop(L, 2);
    listener->callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    SteamAPICall_t call = SteamUGC()->UnsubscribeItem(itemId);
    listener->call_result.Set(call, listener, &CallResultListener<RemoteStorageUnsubscribePublishedFileResult_t>::Result);
    return 0;
}

namespace luasteam {

void add_UGC(lua_State *L) {
    lua_createtable(L, 0, 11);
    add_ugc_auto(L);
    add_func(L, "createItem", luasteam_createItem);
    add_func(L, "submitItemUpdate", luasteam_submitItemUpdate);
    add_func(L, "getSubscribedItems", luasteam_getSubscribedItems);
    add_func(L, "getItemState", luasteam_getItemState);
    add_func(L, "getItemInstallInfo", luasteam_getItemInstallInfo);
    add_func(L, "getItemUpdateProgress", luasteam_getItemUpdateProgress);
    add_func(L, "startPlaytimeTracking", luasteam_startPlaytimeTracking);
    add_func(L, "stopPlaytimeTracking", luasteam_stopPlaytimeTracking);
    add_func(L, "stopPlaytimeTrackingForAllItems", luasteam_stopPlaytimeTrackingForAllItems);
    add_func(L, "subscribeItem", luasteam_subscribeItem);
    add_func(L, "unsubscribeItem", luasteam_unsubscribeItem);
    lua_setfield(L, -2, "UGC");
}

void init_UGC(lua_State *L) {}

void shutdown_UGC(lua_State *L) {}

} // namespace luasteam
