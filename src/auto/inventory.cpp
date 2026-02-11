#include "auto.hpp"

namespace luasteam {

int Inventory_ref = LUA_NOREF;

namespace {

class CallbackListener {
  private:
    STEAM_CALLBACK(CallbackListener, OnSteamInventoryResultReady, SteamInventoryResultReady_t);
    STEAM_CALLBACK(CallbackListener, OnSteamInventoryFullUpdate, SteamInventoryFullUpdate_t);
    STEAM_CALLBACK(CallbackListener, OnSteamInventoryDefinitionUpdate, SteamInventoryDefinitionUpdate_t);
    STEAM_CALLBACK(CallbackListener, OnSteamInventoryEligiblePromoItemDefIDs, SteamInventoryEligiblePromoItemDefIDs_t);
    STEAM_CALLBACK(CallbackListener, OnSteamInventoryStartPurchaseResult, SteamInventoryStartPurchaseResult_t);
    STEAM_CALLBACK(CallbackListener, OnSteamInventoryRequestPricesResult, SteamInventoryRequestPricesResult_t);
};

void CallbackListener::OnSteamInventoryResultReady(SteamInventoryResultReady_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Inventory_ref);
    lua_getfield(L, -1, "OnSteamInventoryResultReady");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->m_handle);
        lua_setfield(L, -2, "m_handle");
        lua_pushinteger(L, data->m_result);
        lua_setfield(L, -2, "m_result");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnSteamInventoryFullUpdate(SteamInventoryFullUpdate_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Inventory_ref);
    lua_getfield(L, -1, "OnSteamInventoryFullUpdate");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushinteger(L, data->m_handle);
        lua_setfield(L, -2, "m_handle");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnSteamInventoryDefinitionUpdate(SteamInventoryDefinitionUpdate_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Inventory_ref);
    lua_getfield(L, -1, "OnSteamInventoryDefinitionUpdate");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 0);
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnSteamInventoryEligiblePromoItemDefIDs(SteamInventoryEligiblePromoItemDefIDs_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Inventory_ref);
    lua_getfield(L, -1, "OnSteamInventoryEligiblePromoItemDefIDs");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        lua_pushinteger(L, data->m_result);
        lua_setfield(L, -2, "m_result");
        luasteam::pushuint64(L, data->m_steamID.ConvertToUint64());
        lua_setfield(L, -2, "m_steamID");
        lua_pushinteger(L, data->m_numEligiblePromoItemDefs);
        lua_setfield(L, -2, "m_numEligiblePromoItemDefs");
        lua_pushboolean(L, data->m_bCachedData);
        lua_setfield(L, -2, "m_bCachedData");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnSteamInventoryStartPurchaseResult(SteamInventoryStartPurchaseResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Inventory_ref);
    lua_getfield(L, -1, "OnSteamInventoryStartPurchaseResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->m_result);
        lua_setfield(L, -2, "m_result");
        luasteam::pushuint64(L, data->m_ulOrderID);
        lua_setfield(L, -2, "m_ulOrderID");
        luasteam::pushuint64(L, data->m_ulTransID);
        lua_setfield(L, -2, "m_ulTransID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnSteamInventoryRequestPricesResult(SteamInventoryRequestPricesResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Inventory_ref);
    lua_getfield(L, -1, "OnSteamInventoryRequestPricesResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->m_result);
        lua_setfield(L, -2, "m_result");
        // Skip unsupported type: char [4]
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

CallbackListener *Inventory_listener = nullptr;

} // namespace

void init_Inventory_auto(lua_State *L) { Inventory_listener = new CallbackListener(); }

void shutdown_Inventory_auto(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, Inventory_ref);
    Inventory_ref = LUA_NOREF;
    delete Inventory_listener; Inventory_listener = nullptr;
}


// EResult GetResultStatus(SteamInventoryResult_t resultHandle);
EXTERN int luasteam_Inventory_GetResultStatus(lua_State *L) {
    SteamInventoryResult_t resultHandle = static_cast<SteamInventoryResult_t>(luaL_checkint(L, 1));
    lua_pushinteger(L, SteamInventory()->GetResultStatus(resultHandle));
    return 1;
}

// uint32 GetResultTimestamp(SteamInventoryResult_t resultHandle);
EXTERN int luasteam_Inventory_GetResultTimestamp(lua_State *L) {
    SteamInventoryResult_t resultHandle = static_cast<SteamInventoryResult_t>(luaL_checkint(L, 1));
    lua_pushinteger(L, SteamInventory()->GetResultTimestamp(resultHandle));
    return 1;
}

// bool CheckResultSteamID(SteamInventoryResult_t resultHandle, CSteamID steamIDExpected);
EXTERN int luasteam_Inventory_CheckResultSteamID(lua_State *L) {
    SteamInventoryResult_t resultHandle = static_cast<SteamInventoryResult_t>(luaL_checkint(L, 1));
    CSteamID steamIDExpected(luasteam::checkuint64(L, 2));
    lua_pushboolean(L, SteamInventory()->CheckResultSteamID(resultHandle, steamIDExpected));
    return 1;
}

// void DestroyResult(SteamInventoryResult_t resultHandle);
EXTERN int luasteam_Inventory_DestroyResult(lua_State *L) {
    SteamInventoryResult_t resultHandle = static_cast<SteamInventoryResult_t>(luaL_checkint(L, 1));
    SteamInventory()->DestroyResult(resultHandle);
    return 0;
}

// bool GetAllItems(SteamInventoryResult_t * pResultHandle);
EXTERN int luasteam_Inventory_GetAllItems(lua_State *L) {
    SteamInventoryResult_t pResultHandle;    lua_pushboolean(L, SteamInventory()->GetAllItems(&pResultHandle));
    lua_pushinteger(L, pResultHandle);
    return 2;
}

// bool GrantPromoItems(SteamInventoryResult_t * pResultHandle);
EXTERN int luasteam_Inventory_GrantPromoItems(lua_State *L) {
    SteamInventoryResult_t pResultHandle;    lua_pushboolean(L, SteamInventory()->GrantPromoItems(&pResultHandle));
    lua_pushinteger(L, pResultHandle);
    return 2;
}

// void SendItemDropHeartbeat();
EXTERN int luasteam_Inventory_SendItemDropHeartbeat(lua_State *L) {
    SteamInventory()->SendItemDropHeartbeat();
    return 0;
}

// bool LoadItemDefinitions();
EXTERN int luasteam_Inventory_LoadItemDefinitions(lua_State *L) {
    lua_pushboolean(L, SteamInventory()->LoadItemDefinitions());
    return 1;
}

// bool GetItemDefinitionIDs(SteamItemDef_t * pItemDefIDs, uint32 * punItemDefIDsArraySize);
EXTERN int luasteam_Inventory_GetItemDefinitionIDs(lua_State *L) {
    SteamItemDef_t pItemDefIDs;    uint32 punItemDefIDsArraySize;    lua_pushboolean(L, SteamInventory()->GetItemDefinitionIDs(&pItemDefIDs, &punItemDefIDsArraySize));
    lua_pushinteger(L, pItemDefIDs);
    lua_pushinteger(L, punItemDefIDsArraySize);
    return 3;
}

// SteamAPICall_t RequestEligiblePromoItemDefinitionsIDs(CSteamID steamID);
EXTERN int luasteam_Inventory_RequestEligiblePromoItemDefinitionsIDs(lua_State *L) {
    CSteamID steamID(luasteam::checkuint64(L, 1));
    luasteam::pushuint64(L, SteamInventory()->RequestEligiblePromoItemDefinitionsIDs(steamID));
    return 1;
}

// bool GetEligiblePromoItemDefinitionIDs(CSteamID steamID, SteamItemDef_t * pItemDefIDs, uint32 * punItemDefIDsArraySize);
EXTERN int luasteam_Inventory_GetEligiblePromoItemDefinitionIDs(lua_State *L) {
    CSteamID steamID(luasteam::checkuint64(L, 1));
    SteamItemDef_t pItemDefIDs;    uint32 punItemDefIDsArraySize;    lua_pushboolean(L, SteamInventory()->GetEligiblePromoItemDefinitionIDs(steamID, &pItemDefIDs, &punItemDefIDsArraySize));
    lua_pushinteger(L, pItemDefIDs);
    lua_pushinteger(L, punItemDefIDsArraySize);
    return 3;
}

// SteamAPICall_t RequestPrices();
EXTERN int luasteam_Inventory_RequestPrices(lua_State *L) {
    luasteam::pushuint64(L, SteamInventory()->RequestPrices());
    return 1;
}

// uint32 GetNumItemsWithPrices();
EXTERN int luasteam_Inventory_GetNumItemsWithPrices(lua_State *L) {
    lua_pushinteger(L, SteamInventory()->GetNumItemsWithPrices());
    return 1;
}

// bool GetItemPrice(SteamItemDef_t iDefinition, uint64 * pCurrentPrice, uint64 * pBasePrice);
EXTERN int luasteam_Inventory_GetItemPrice(lua_State *L) {
    SteamItemDef_t iDefinition = static_cast<SteamItemDef_t>(luaL_checkint(L, 1));
    uint64 pCurrentPrice;    uint64 pBasePrice;    lua_pushboolean(L, SteamInventory()->GetItemPrice(iDefinition, &pCurrentPrice, &pBasePrice));
    luasteam::pushuint64(L, pCurrentPrice);
    luasteam::pushuint64(L, pBasePrice);
    return 3;
}

// SteamInventoryUpdateHandle_t StartUpdateProperties();
EXTERN int luasteam_Inventory_StartUpdateProperties(lua_State *L) {
    luasteam::pushuint64(L, SteamInventory()->StartUpdateProperties());
    return 1;
}

// bool RemoveProperty(SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, const char * pchPropertyName);
EXTERN int luasteam_Inventory_RemoveProperty(lua_State *L) {
    SteamInventoryUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    SteamItemInstanceID_t nItemID = luasteam::checkuint64(L, 2);
    const char *pchPropertyName = luaL_checkstring(L, 3);
    lua_pushboolean(L, SteamInventory()->RemoveProperty(handle, nItemID, pchPropertyName));
    return 1;
}

// bool SubmitUpdateProperties(SteamInventoryUpdateHandle_t handle, SteamInventoryResult_t * pResultHandle);
EXTERN int luasteam_Inventory_SubmitUpdateProperties(lua_State *L) {
    SteamInventoryUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    SteamInventoryResult_t pResultHandle;    lua_pushboolean(L, SteamInventory()->SubmitUpdateProperties(handle, &pResultHandle));
    lua_pushinteger(L, pResultHandle);
    return 2;
}

void register_Inventory_auto(lua_State *L) {
    add_func(L, "GetResultStatus", luasteam_Inventory_GetResultStatus);
    add_func(L, "GetResultTimestamp", luasteam_Inventory_GetResultTimestamp);
    add_func(L, "CheckResultSteamID", luasteam_Inventory_CheckResultSteamID);
    add_func(L, "DestroyResult", luasteam_Inventory_DestroyResult);
    add_func(L, "GetAllItems", luasteam_Inventory_GetAllItems);
    add_func(L, "GrantPromoItems", luasteam_Inventory_GrantPromoItems);
    add_func(L, "SendItemDropHeartbeat", luasteam_Inventory_SendItemDropHeartbeat);
    add_func(L, "LoadItemDefinitions", luasteam_Inventory_LoadItemDefinitions);
    add_func(L, "GetItemDefinitionIDs", luasteam_Inventory_GetItemDefinitionIDs);
    add_func(L, "RequestEligiblePromoItemDefinitionsIDs", luasteam_Inventory_RequestEligiblePromoItemDefinitionsIDs);
    add_func(L, "GetEligiblePromoItemDefinitionIDs", luasteam_Inventory_GetEligiblePromoItemDefinitionIDs);
    add_func(L, "RequestPrices", luasteam_Inventory_RequestPrices);
    add_func(L, "GetNumItemsWithPrices", luasteam_Inventory_GetNumItemsWithPrices);
    add_func(L, "GetItemPrice", luasteam_Inventory_GetItemPrice);
    add_func(L, "StartUpdateProperties", luasteam_Inventory_StartUpdateProperties);
    add_func(L, "RemoveProperty", luasteam_Inventory_RemoveProperty);
    add_func(L, "SubmitUpdateProperties", luasteam_Inventory_SubmitUpdateProperties);
}

void add_Inventory_auto(lua_State *L) {
    lua_createtable(L, 0, 17);
    register_Inventory_auto(L);
    lua_pushvalue(L, -1);
    Inventory_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "Inventory");
}

} // namespace luasteam
