#include "auto.hpp"

namespace luasteam {

int inventory_ref = LUA_NOREF;

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
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::inventory_ref);
    lua_getfield(L, -1, "onSteamInventoryResultReady");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->m_handle);
        lua_setfield(L, -2, "handle");
        lua_pushinteger(L, data->m_result);
        lua_setfield(L, -2, "result");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnSteamInventoryFullUpdate(SteamInventoryFullUpdate_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::inventory_ref);
    lua_getfield(L, -1, "onSteamInventoryFullUpdate");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushinteger(L, data->m_handle);
        lua_setfield(L, -2, "handle");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnSteamInventoryDefinitionUpdate(SteamInventoryDefinitionUpdate_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::inventory_ref);
    lua_getfield(L, -1, "onSteamInventoryDefinitionUpdate");
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
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::inventory_ref);
    lua_getfield(L, -1, "onSteamInventoryEligiblePromoItemDefIDs");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 4);
        lua_pushinteger(L, data->m_result);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_steamID.ConvertToUint64());
        lua_setfield(L, -2, "steamID");
        lua_pushinteger(L, data->m_numEligiblePromoItemDefs);
        lua_setfield(L, -2, "numEligiblePromoItemDefs");
        lua_pushboolean(L, data->m_bCachedData);
        lua_setfield(L, -2, "cachedData");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnSteamInventoryStartPurchaseResult(SteamInventoryStartPurchaseResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::inventory_ref);
    lua_getfield(L, -1, "onSteamInventoryStartPurchaseResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 3);
        lua_pushinteger(L, data->m_result);
        lua_setfield(L, -2, "result");
        luasteam::pushuint64(L, data->m_ulOrderID);
        lua_setfield(L, -2, "orderID");
        luasteam::pushuint64(L, data->m_ulTransID);
        lua_setfield(L, -2, "transID");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnSteamInventoryRequestPricesResult(SteamInventoryRequestPricesResult_t *data) {
    if (data == nullptr) return;
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) return;
    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::inventory_ref);
    lua_getfield(L, -1, "onSteamInventoryRequestPricesResult");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        lua_pushinteger(L, data->m_result);
        lua_setfield(L, -2, "result");
        lua_pushstring(L, data->m_rgchCurrency);
        lua_setfield(L, -2, "currency");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

CallbackListener *inventory_listener = nullptr;

} // namespace

void init_inventory_auto(lua_State *L) { inventory_listener = new CallbackListener(); }

void shutdown_inventory_auto(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, inventory_ref);
    inventory_ref = LUA_NOREF;
    delete inventory_listener; inventory_listener = nullptr;
}


// EResult GetResultStatus(SteamInventoryResult_t resultHandle);
EXTERN int luasteam_inventory_SteamAPI_ISteamInventory_GetResultStatus(lua_State *L) {
    SteamInventoryResult_t resultHandle = static_cast<SteamInventoryResult_t>(luaL_checkint(L, 1));
    lua_pushinteger(L, SteamInventory()->GetResultStatus(resultHandle));
    return 1;
}

// uint32 GetResultTimestamp(SteamInventoryResult_t resultHandle);
EXTERN int luasteam_inventory_SteamAPI_ISteamInventory_GetResultTimestamp(lua_State *L) {
    SteamInventoryResult_t resultHandle = static_cast<SteamInventoryResult_t>(luaL_checkint(L, 1));
    lua_pushinteger(L, SteamInventory()->GetResultTimestamp(resultHandle));
    return 1;
}

// bool CheckResultSteamID(SteamInventoryResult_t resultHandle, CSteamID steamIDExpected);
EXTERN int luasteam_inventory_SteamAPI_ISteamInventory_CheckResultSteamID(lua_State *L) {
    SteamInventoryResult_t resultHandle = static_cast<SteamInventoryResult_t>(luaL_checkint(L, 1));
    CSteamID steamIDExpected(luasteam::checkuint64(L, 2));
    lua_pushboolean(L, SteamInventory()->CheckResultSteamID(resultHandle, steamIDExpected));
    return 1;
}

// void DestroyResult(SteamInventoryResult_t resultHandle);
EXTERN int luasteam_inventory_SteamAPI_ISteamInventory_DestroyResult(lua_State *L) {
    SteamInventoryResult_t resultHandle = static_cast<SteamInventoryResult_t>(luaL_checkint(L, 1));
    SteamInventory()->DestroyResult(resultHandle);
    return 0;
}

// void SendItemDropHeartbeat();
EXTERN int luasteam_inventory_SteamAPI_ISteamInventory_SendItemDropHeartbeat(lua_State *L) {
    SteamInventory()->SendItemDropHeartbeat();
    return 0;
}

// bool LoadItemDefinitions();
EXTERN int luasteam_inventory_SteamAPI_ISteamInventory_LoadItemDefinitions(lua_State *L) {
    lua_pushboolean(L, SteamInventory()->LoadItemDefinitions());
    return 1;
}

// SteamAPICall_t RequestEligiblePromoItemDefinitionsIDs(CSteamID steamID);
EXTERN int luasteam_inventory_SteamAPI_ISteamInventory_RequestEligiblePromoItemDefinitionsIDs(lua_State *L) {
    CSteamID steamID(luasteam::checkuint64(L, 1));
    luasteam::pushuint64(L, SteamInventory()->RequestEligiblePromoItemDefinitionsIDs(steamID));
    return 1;
}

// SteamAPICall_t RequestPrices();
EXTERN int luasteam_inventory_SteamAPI_ISteamInventory_RequestPrices(lua_State *L) {
    luasteam::pushuint64(L, SteamInventory()->RequestPrices());
    return 1;
}

// uint32 GetNumItemsWithPrices();
EXTERN int luasteam_inventory_SteamAPI_ISteamInventory_GetNumItemsWithPrices(lua_State *L) {
    lua_pushinteger(L, SteamInventory()->GetNumItemsWithPrices());
    return 1;
}

// SteamInventoryUpdateHandle_t StartUpdateProperties();
EXTERN int luasteam_inventory_SteamAPI_ISteamInventory_StartUpdateProperties(lua_State *L) {
    luasteam::pushuint64(L, SteamInventory()->StartUpdateProperties());
    return 1;
}

// bool RemoveProperty(SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, const char * pchPropertyName);
EXTERN int luasteam_inventory_SteamAPI_ISteamInventory_RemoveProperty(lua_State *L) {
    SteamInventoryUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    SteamItemInstanceID_t nItemID = luasteam::checkuint64(L, 2);
    const char *pchPropertyName = luaL_checkstring(L, 3);
    lua_pushboolean(L, SteamInventory()->RemoveProperty(handle, nItemID, pchPropertyName));
    return 1;
}

// bool SetProperty(SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, const char * pchPropertyName, const char * pchPropertyValue);
EXTERN int luasteam_inventory_SteamAPI_ISteamInventory_SetPropertyString(lua_State *L) {
    SteamInventoryUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    SteamItemInstanceID_t nItemID = luasteam::checkuint64(L, 2);
    const char *pchPropertyName = luaL_checkstring(L, 3);
    const char *pchPropertyValue = luaL_checkstring(L, 4);
    lua_pushboolean(L, SteamInventory()->SetProperty(handle, nItemID, pchPropertyName, pchPropertyValue));
    return 1;
}

// bool SetProperty(SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, const char * pchPropertyName, bool bValue);
EXTERN int luasteam_inventory_SteamAPI_ISteamInventory_SetPropertyBool(lua_State *L) {
    SteamInventoryUpdateHandle_t handle = luasteam::checkuint64(L, 1);
    SteamItemInstanceID_t nItemID = luasteam::checkuint64(L, 2);
    const char *pchPropertyName = luaL_checkstring(L, 3);
    bool bValue = lua_toboolean(L, 4);
    lua_pushboolean(L, SteamInventory()->SetProperty(handle, nItemID, pchPropertyName, bValue));
    return 1;
}

void register_inventory_auto(lua_State *L) {
    add_func(L, "getResultStatus", luasteam_inventory_SteamAPI_ISteamInventory_GetResultStatus);
    add_func(L, "getResultTimestamp", luasteam_inventory_SteamAPI_ISteamInventory_GetResultTimestamp);
    add_func(L, "checkResultSteamID", luasteam_inventory_SteamAPI_ISteamInventory_CheckResultSteamID);
    add_func(L, "destroyResult", luasteam_inventory_SteamAPI_ISteamInventory_DestroyResult);
    add_func(L, "sendItemDropHeartbeat", luasteam_inventory_SteamAPI_ISteamInventory_SendItemDropHeartbeat);
    add_func(L, "loadItemDefinitions", luasteam_inventory_SteamAPI_ISteamInventory_LoadItemDefinitions);
    add_func(L, "requestEligiblePromoItemDefinitionsIDs", luasteam_inventory_SteamAPI_ISteamInventory_RequestEligiblePromoItemDefinitionsIDs);
    add_func(L, "requestPrices", luasteam_inventory_SteamAPI_ISteamInventory_RequestPrices);
    add_func(L, "getNumItemsWithPrices", luasteam_inventory_SteamAPI_ISteamInventory_GetNumItemsWithPrices);
    add_func(L, "startUpdateProperties", luasteam_inventory_SteamAPI_ISteamInventory_StartUpdateProperties);
    add_func(L, "removeProperty", luasteam_inventory_SteamAPI_ISteamInventory_RemoveProperty);
    add_func(L, "setProperty", luasteam_inventory_SteamAPI_ISteamInventory_SetPropertyString);
    add_func(L, "setProperty", luasteam_inventory_SteamAPI_ISteamInventory_SetPropertyBool);
}

void add_inventory_auto(lua_State *L) {
    lua_createtable(L, 0, 13);
    register_inventory_auto(L);
    lua_pushvalue(L, -1);
    inventory_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "inventory");
}

} // namespace luasteam
