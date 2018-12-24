#include "UGC.hpp"

// ========================
// ======= SteamUGC =======
// ========================

using luasteam::CallResultListener;

namespace {

const char *workshop_file_types[] = {"Community", "Microtransaction", "Collection", "Art", "Video", "Screenshot", "WebGuide", "IntegratedGuide", "Merch", "ControllerBinding", "SteamVideo", "GameManagedItem", nullptr};

// This is used since not all file types are valid
const EWorkshopFileType file_type_to_enum[] = {k_EWorkshopFileTypeCommunity, k_EWorkshopFileTypeMicrotransaction, k_EWorkshopFileTypeCollection, k_EWorkshopFileTypeArt, k_EWorkshopFileTypeVideo, k_EWorkshopFileTypeScreenshot, k_EWorkshopFileTypeWebGuide, k_EWorkshopFileTypeIntegratedGuide, k_EWorkshopFileTypeMerch, k_EWorkshopFileTypeControllerBinding, k_EWorkshopFileTypeSteamVideo, k_EWorkshopFileTypeGameManagedItem};

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

} // namespace luasteam

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

namespace luasteam {

void add_UGC(lua_State *L) {
    lua_createtable(L, 0, 1);
    add_func(L, "createItem", luasteam_createItem);
    lua_setfield(L, -2, "UGC");
}

void init_UGC(lua_State *L) {}

void shutdown_UGC(lua_State *L) {}

} // namespace luasteam
