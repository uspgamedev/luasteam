#include "UGC.hpp"

// ========================
// ======= SteamUGC =======
// ========================

using luasteam::CallResultListener;

namespace {

const char *workshop_file_types[] = {
    "Community", "Microtransaction", "Collection", "Art", "Video", "Screenshot", "WebGuide", "IntegratedGuide", "Merch", "ControllerBinding", "SteamVideo", "GameManagedItem", nullptr,
};

const EWorkshopFileType file_type_to_enum[] = {
    k_EWorkshopFileTypeCommunity, k_EWorkshopFileTypeMicrotransaction, k_EWorkshopFileTypeCollection, k_EWorkshopFileTypeArt, k_EWorkshopFileTypeVideo, k_EWorkshopFileTypeScreenshot, k_EWorkshopFileTypeWebGuide, k_EWorkshopFileTypeIntegratedGuide, k_EWorkshopFileTypeMerch, k_EWorkshopFileTypeControllerBinding, k_EWorkshopFileTypeSteamVideo, k_EWorkshopFileTypeGameManagedItem,
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

} // namespace luasteam

// SteamAPICall_t CreateItem( AppId_t nConsumerAppId, EWorkshopFileType eFileType );
EXTERN int luasteam_createItem(lua_State *L) {
    int consumerAppID = luaL_checkint(L, 1);
    EWorkshopFileType fileType = file_type_to_enum[luaL_checkoption(L, 2, nullptr, workshop_file_types)];
    luaL_checktype(L, 3, LUA_TFUNCTION);
    auto *listener = new CallResultListener<CreateItemResult_t>();
    listener->callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    SteamAPICall_t call = SteamUGC()->CreateItem(consumerAppID, fileType);
    listener->call_result.Set(call, listener, &CallResultListener<CreateItemResult_t>::Result);
    return 0;
}

// UGCUpdateHandle_t StartItemUpdate( AppId_t nConsumerAppId, PublishedFileId_t nPublishedFileID );
EXTERN int luasteam_startItemUpdate(lua_State *L) {
    int consumerAppID = luaL_checkint(L, 1);
    uint64 publishedFileId = luasteam::checkuint64(L, 2);
    luasteam::pushuint64(L, SteamUGC()->StartItemUpdate(consumerAppID, publishedFileId));
    return 1;
}

// bool SetItemContent( UGCUpdateHandle_t handle, const char *pszContentFolder );
EXTERN int luasteam_setItemContent(lua_State *L) {
    uint64 handle = luasteam::checkuint64(L, 1);
    const char *contentFolder = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->SetItemContent(handle, contentFolder));
    return 1;
}

// bool SetItemDescription( UGCUpdateHandle_t handle, const char *pchDescription );
EXTERN int luasteam_setItemDescription(lua_State *L) {
    uint64 handle = luasteam::checkuint64(L, 1);
    const char *description = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->SetItemDescription(handle, description));
    return 1;
}

// bool SetItemPreview( UGCUpdateHandle_t handle, const char *pszPreviewFile );
EXTERN int luasteam_setItemPreview(lua_State *L) {
    uint64 handle = luasteam::checkuint64(L, 1);
    const char *previewFile = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->SetItemPreview(handle, previewFile));
    return 1;
}

// bool SetItemTitle( UGCUpdateHandle_t handle, const char *pchTitle );
EXTERN int luasteam_setItemTitle(lua_State *L) {
    uint64 handle = luasteam::checkuint64(L, 1);
    const char *title = luaL_checkstring(L, 2);
    lua_pushboolean(L, SteamUGC()->SetItemTitle(handle, title));
    return 1;
}

// SteamAPICall_t SubmitItemUpdate( UGCUpdateHandle_t handle, const char *pchChangeNote );
EXTERN int luasteam_submitItemUpdate(lua_State *L) {
    uint64 handle = luasteam::checkuint64(L, 1);
    const char *changeNote = luaL_optstring(L, 2, nullptr);
    luaL_checktype(L, 3, LUA_TFUNCTION);
    auto *listener = new CallResultListener<SubmitItemUpdateResult_t>();
    listener->callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    SteamAPICall_t call = SteamUGC()->SubmitItemUpdate(handle, changeNote);
    listener->call_result.Set(call, listener, &CallResultListener<SubmitItemUpdateResult_t>::Result);
    return 0;
}

// uint32 GetNumSubscribedItems();
EXTERN int luasteam_getNumSubscribedItems(lua_State *L) {
    lua_pushnumber(L, SteamUGC()->GetNumSubscribedItems());
    return 1;
}

// uint32 GetSubscribedItems( PublishedFileId_t*pvecPublishedFileID, uint32 cMaxEntries );
EXTERN int luasteam_getSubscribedItems(lua_State *L) {
    int sz = SteamUGC()->GetNumSubscribedItems();
    PublishedFileId_t *vec = new PublishedFileId_t[sz];
    sz = SteamUGC()->GetSubscribedItems(vec, sz);
    lua_createtable(L, sz, 0);
    for(int i = 0; i < sz; i++) {
        luasteam::pushuint64(L, vec[i]);
        lua_rawseti(L, -2, i + 1);
    }
    delete vec;
    return 1;
}

namespace luasteam {

void add_UGC(lua_State *L) {
    lua_createtable(L, 0, 9);
    add_func(L, "createItem", luasteam_createItem);
    add_func(L, "startItemUpdate", luasteam_startItemUpdate);
    add_func(L, "setItemContent", luasteam_setItemContent);
    add_func(L, "setItemDescription", luasteam_setItemDescription);
    add_func(L, "setItemPreview", luasteam_setItemPreview);
    add_func(L, "setItemTitle", luasteam_setItemTitle);
    add_func(L, "submitItemUpdate", luasteam_submitItemUpdate);
    add_func(L, "getNumSubscribedItems", luasteam_getNumSubscribedItems);
    add_func(L, "getSubscribedItems", luasteam_getSubscribedItems);
    lua_setfield(L, -2, "UGC");
}

void init_UGC(lua_State *L) {}

void shutdown_UGC(lua_State *L) {}

} // namespace luasteam
