#include "auto.hpp"

namespace luasteam {

int Inventory_ref = LUA_NOREF;

namespace {
class InventoryCallbackListener {
private:
	STEAM_CALLBACK(InventoryCallbackListener, OnSteamInventoryResultReady, SteamInventoryResultReady_t);
	STEAM_CALLBACK(InventoryCallbackListener, OnSteamInventoryFullUpdate, SteamInventoryFullUpdate_t);
	STEAM_CALLBACK(InventoryCallbackListener, OnSteamInventoryDefinitionUpdate, SteamInventoryDefinitionUpdate_t);
	STEAM_CALLBACK(InventoryCallbackListener, OnSteamInventoryEligiblePromoItemDefIDs, SteamInventoryEligiblePromoItemDefIDs_t);
	STEAM_CALLBACK(InventoryCallbackListener, OnSteamInventoryStartPurchaseResult, SteamInventoryStartPurchaseResult_t);
	STEAM_CALLBACK(InventoryCallbackListener, OnSteamInventoryRequestPricesResult, SteamInventoryRequestPricesResult_t);
};
void InventoryCallbackListener::OnSteamInventoryResultReady(SteamInventoryResultReady_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Inventory_ref);
	lua_getfield(L, -1, "OnSteamInventoryResultReady");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamInventoryResultReady_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void InventoryCallbackListener::OnSteamInventoryFullUpdate(SteamInventoryFullUpdate_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Inventory_ref);
	lua_getfield(L, -1, "OnSteamInventoryFullUpdate");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamInventoryFullUpdate_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void InventoryCallbackListener::OnSteamInventoryDefinitionUpdate(SteamInventoryDefinitionUpdate_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Inventory_ref);
	lua_getfield(L, -1, "OnSteamInventoryDefinitionUpdate");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamInventoryDefinitionUpdate_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void InventoryCallbackListener::OnSteamInventoryEligiblePromoItemDefIDs(SteamInventoryEligiblePromoItemDefIDs_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Inventory_ref);
	lua_getfield(L, -1, "OnSteamInventoryEligiblePromoItemDefIDs");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamInventoryEligiblePromoItemDefIDs_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void InventoryCallbackListener::OnSteamInventoryStartPurchaseResult(SteamInventoryStartPurchaseResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Inventory_ref);
	lua_getfield(L, -1, "OnSteamInventoryStartPurchaseResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamInventoryStartPurchaseResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void InventoryCallbackListener::OnSteamInventoryRequestPricesResult(SteamInventoryRequestPricesResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::Inventory_ref);
	lua_getfield(L, -1, "OnSteamInventoryRequestPricesResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamInventoryRequestPricesResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
InventoryCallbackListener *Inventory_listener = nullptr;
} // namespace

void init_Inventory_auto(lua_State *L) { if (Inventory_listener != nullptr) return; Inventory_listener = new InventoryCallbackListener(); }
void shutdown_Inventory_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, Inventory_ref);
	Inventory_ref = LUA_NOREF;
	delete Inventory_listener; Inventory_listener = nullptr;
}

template <> void CallResultListener<SteamInventoryEligiblePromoItemDefIDs_t>::Result(SteamInventoryEligiblePromoItemDefIDs_t *data, bool io_fail) {
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
		lua_pushinteger(L, data->m_result);
		lua_setfield(L, -2, "m_result");
		luasteam::pushuint64(L, data->m_steamID.ConvertToUint64());
		lua_setfield(L, -2, "m_steamID");
		lua_pushinteger(L, data->m_numEligiblePromoItemDefs);
		lua_setfield(L, -2, "m_numEligiblePromoItemDefs");
		lua_pushboolean(L, data->m_bCachedData);
		lua_setfield(L, -2, "m_bCachedData");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<SteamInventoryRequestPricesResult_t>::Result(SteamInventoryRequestPricesResult_t *data, bool io_fail) {
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
		lua_createtable(L, 0, 2);
		lua_pushinteger(L, data->m_result);
		lua_setfield(L, -2, "m_result");
		lua_pushlstring(L, reinterpret_cast<const char*>(data->m_rgchCurrency), 4);
		lua_setfield(L, -2, "m_rgchCurrency");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

template <> void CallResultListener<SteamInventoryStartPurchaseResult_t>::Result(SteamInventoryStartPurchaseResult_t *data, bool io_fail) {
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
		lua_createtable(L, 0, 3);
		lua_pushinteger(L, data->m_result);
		lua_setfield(L, -2, "m_result");
		luasteam::pushuint64(L, data->m_ulOrderID);
		lua_setfield(L, -2, "m_ulOrderID");
		luasteam::pushuint64(L, data->m_ulTransID);
		lua_setfield(L, -2, "m_ulTransID");
	}
	lua_pushboolean(L, io_fail);
	lua_call(L, 2, 0);
	delete this;
}

// In C++:
// EResult GetResultStatus(SteamInventoryResult_t resultHandle);
// In Lua:
// int Inventory.GetResultStatus(resultHandle: int)
static int luasteam_Inventory_GetResultStatus(lua_State *L, ISteamInventory *iface) {
	SteamInventoryResult_t resultHandle = static_cast<SteamInventoryResult_t>(luaL_checkint(L, 1));
	EResult __ret = iface->GetResultStatus(resultHandle);
	lua_pushinteger(L, __ret);
	return 1;
}
static int luasteam_Inventory_GetResultStatus_user(lua_State *L) { return luasteam_Inventory_GetResultStatus(L, SteamInventory()); }
static int luasteam_Inventory_GetResultStatus_gs(lua_State *L) { return luasteam_Inventory_GetResultStatus(L, SteamGameServerInventory()); }

// In C++:
// bool GetResultItems(SteamInventoryResult_t resultHandle, SteamItemDetails_t * pOutItemsArray, uint32 * punOutItemsArraySize);
// In Lua:
// (bool, pOutItemsArray: SteamItemDetails_t[], punOutItemsArraySize: int) Inventory.GetResultItems(resultHandle: int, punOutItemsArraySize: int)
static int luasteam_Inventory_GetResultItems(lua_State *L, ISteamInventory *iface) {
	SteamInventoryResult_t resultHandle = static_cast<SteamInventoryResult_t>(luaL_checkint(L, 1));
	uint32 punOutItemsArraySize = luaL_checkint(L, 2);
	std::vector<SteamItemDetails_t> pOutItemsArray(punOutItemsArraySize);
	bool __ret = iface->GetResultItems(resultHandle, pOutItemsArray.data(), &punOutItemsArraySize);
	lua_pushboolean(L, __ret);
	lua_createtable(L, punOutItemsArraySize, 0);
	for(decltype(punOutItemsArraySize) i = 0; i < punOutItemsArraySize; i++) {
		luasteam::push_SteamItemDetails_t(L, pOutItemsArray[i]);
		lua_rawseti(L, -2, i+1);
	}
	lua_pushinteger(L, punOutItemsArraySize);
	return 3;
}
static int luasteam_Inventory_GetResultItems_user(lua_State *L) { return luasteam_Inventory_GetResultItems(L, SteamInventory()); }
static int luasteam_Inventory_GetResultItems_gs(lua_State *L) { return luasteam_Inventory_GetResultItems(L, SteamGameServerInventory()); }

// In C++:
// bool GetResultItemProperty(SteamInventoryResult_t resultHandle, uint32 unItemIndex, const char * pchPropertyName, char * pchValueBuffer, uint32 * punValueBufferSizeOut);
// In Lua:
// (bool, pchValueBuffer: str, punValueBufferSizeOut: int) Inventory.GetResultItemProperty(resultHandle: int, unItemIndex: int, pchPropertyName: str, punValueBufferSizeOut: int)
static int luasteam_Inventory_GetResultItemProperty(lua_State *L, ISteamInventory *iface) {
	SteamInventoryResult_t resultHandle = static_cast<SteamInventoryResult_t>(luaL_checkint(L, 1));
	uint32 unItemIndex = static_cast<uint32>(luaL_checkint(L, 2));
	const char *pchPropertyName = luaL_checkstring(L, 3);
	uint32 punValueBufferSizeOut = luaL_checkint(L, 4);
	std::vector<char> pchValueBuffer(punValueBufferSizeOut);
	bool __ret = iface->GetResultItemProperty(resultHandle, unItemIndex, pchPropertyName, pchValueBuffer.data(), &punValueBufferSizeOut);
	lua_pushboolean(L, __ret);
	lua_pushstring(L, reinterpret_cast<const char*>(pchValueBuffer.data()));
	lua_pushinteger(L, punValueBufferSizeOut);
	return 3;
}
static int luasteam_Inventory_GetResultItemProperty_user(lua_State *L) { return luasteam_Inventory_GetResultItemProperty(L, SteamInventory()); }
static int luasteam_Inventory_GetResultItemProperty_gs(lua_State *L) { return luasteam_Inventory_GetResultItemProperty(L, SteamGameServerInventory()); }

// In C++:
// uint32 GetResultTimestamp(SteamInventoryResult_t resultHandle);
// In Lua:
// int Inventory.GetResultTimestamp(resultHandle: int)
static int luasteam_Inventory_GetResultTimestamp(lua_State *L, ISteamInventory *iface) {
	SteamInventoryResult_t resultHandle = static_cast<SteamInventoryResult_t>(luaL_checkint(L, 1));
	uint32 __ret = iface->GetResultTimestamp(resultHandle);
	lua_pushinteger(L, __ret);
	return 1;
}
static int luasteam_Inventory_GetResultTimestamp_user(lua_State *L) { return luasteam_Inventory_GetResultTimestamp(L, SteamInventory()); }
static int luasteam_Inventory_GetResultTimestamp_gs(lua_State *L) { return luasteam_Inventory_GetResultTimestamp(L, SteamGameServerInventory()); }

// In C++:
// bool CheckResultSteamID(SteamInventoryResult_t resultHandle, CSteamID steamIDExpected);
// In Lua:
// bool Inventory.CheckResultSteamID(resultHandle: int, steamIDExpected: uint64)
static int luasteam_Inventory_CheckResultSteamID(lua_State *L, ISteamInventory *iface) {
	SteamInventoryResult_t resultHandle = static_cast<SteamInventoryResult_t>(luaL_checkint(L, 1));
	CSteamID steamIDExpected(luasteam::checkuint64(L, 2));
	bool __ret = iface->CheckResultSteamID(resultHandle, steamIDExpected);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_Inventory_CheckResultSteamID_user(lua_State *L) { return luasteam_Inventory_CheckResultSteamID(L, SteamInventory()); }
static int luasteam_Inventory_CheckResultSteamID_gs(lua_State *L) { return luasteam_Inventory_CheckResultSteamID(L, SteamGameServerInventory()); }

// In C++:
// void DestroyResult(SteamInventoryResult_t resultHandle);
// In Lua:
// Inventory.DestroyResult(resultHandle: int)
static int luasteam_Inventory_DestroyResult(lua_State *L, ISteamInventory *iface) {
	SteamInventoryResult_t resultHandle = static_cast<SteamInventoryResult_t>(luaL_checkint(L, 1));
	iface->DestroyResult(resultHandle);
	return 0;
}
static int luasteam_Inventory_DestroyResult_user(lua_State *L) { return luasteam_Inventory_DestroyResult(L, SteamInventory()); }
static int luasteam_Inventory_DestroyResult_gs(lua_State *L) { return luasteam_Inventory_DestroyResult(L, SteamGameServerInventory()); }

// In C++:
// bool GetAllItems(SteamInventoryResult_t * pResultHandle);
// In Lua:
// (bool, pResultHandle: int) Inventory.GetAllItems()
static int luasteam_Inventory_GetAllItems(lua_State *L, ISteamInventory *iface) {
	SteamInventoryResult_t pResultHandle;
	bool __ret = iface->GetAllItems(&pResultHandle);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pResultHandle);
	return 2;
}
static int luasteam_Inventory_GetAllItems_user(lua_State *L) { return luasteam_Inventory_GetAllItems(L, SteamInventory()); }
static int luasteam_Inventory_GetAllItems_gs(lua_State *L) { return luasteam_Inventory_GetAllItems(L, SteamGameServerInventory()); }

// In C++:
// bool GetItemsByID(SteamInventoryResult_t * pResultHandle, const SteamItemInstanceID_t * pInstanceIDs, uint32 unCountInstanceIDs);
// In Lua:
// (bool, pResultHandle: int) Inventory.GetItemsByID(pInstanceIDs: uint64[], unCountInstanceIDs: int)
static int luasteam_Inventory_GetItemsByID(lua_State *L, ISteamInventory *iface) {
	SteamInventoryResult_t pResultHandle;
	uint32 unCountInstanceIDs = luaL_checkint(L, 2);
	luaL_checktype(L, 1, LUA_TTABLE);
	std::vector<SteamItemInstanceID_t> pInstanceIDs(unCountInstanceIDs);
	for(decltype(unCountInstanceIDs) i = 0; i < unCountInstanceIDs; i++) {
		lua_rawgeti(L, 1, i+1);
		pInstanceIDs[i] = luasteam::checkuint64(L, -1);
		lua_pop(L, 1);
	}
	bool __ret = iface->GetItemsByID(&pResultHandle, pInstanceIDs.data(), unCountInstanceIDs);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pResultHandle);
	return 2;
}
static int luasteam_Inventory_GetItemsByID_user(lua_State *L) { return luasteam_Inventory_GetItemsByID(L, SteamInventory()); }
static int luasteam_Inventory_GetItemsByID_gs(lua_State *L) { return luasteam_Inventory_GetItemsByID(L, SteamGameServerInventory()); }

// In C++:
// bool DeserializeResult(SteamInventoryResult_t * pOutResultHandle, const void * pBuffer, uint32 unBufferSize, bool bRESERVED_MUST_BE_FALSE);
// In Lua:
// (bool, pOutResultHandle: int) Inventory.DeserializeResult(pBuffer: str, unBufferSize: int, bRESERVED_MUST_BE_FALSE: bool)
static int luasteam_Inventory_DeserializeResult(lua_State *L, ISteamInventory *iface) {
	SteamInventoryResult_t pOutResultHandle;
	uint32 unBufferSize = luaL_checkint(L, 2);
	size_t _len__tmp100;
	const char *_tmp100 = luaL_checklstring(L, 1, &_len__tmp100);
	const void *pBuffer = reinterpret_cast<const void *>(_tmp100);
	bool bRESERVED_MUST_BE_FALSE = lua_toboolean(L, 3);
	bool __ret = iface->DeserializeResult(&pOutResultHandle, pBuffer, unBufferSize, bRESERVED_MUST_BE_FALSE);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pOutResultHandle);
	return 2;
}
static int luasteam_Inventory_DeserializeResult_user(lua_State *L) { return luasteam_Inventory_DeserializeResult(L, SteamInventory()); }
static int luasteam_Inventory_DeserializeResult_gs(lua_State *L) { return luasteam_Inventory_DeserializeResult(L, SteamGameServerInventory()); }

// In C++:
// bool GenerateItems(SteamInventoryResult_t * pResultHandle, const SteamItemDef_t * pArrayItemDefs, const uint32 * punArrayQuantity, uint32 unArrayLength);
// In Lua:
// (bool, pResultHandle: int) Inventory.GenerateItems(pArrayItemDefs: int[], unArrayLength: int, punArrayQuantity: int[])
static int luasteam_Inventory_GenerateItems(lua_State *L, ISteamInventory *iface) {
	SteamInventoryResult_t pResultHandle;
	uint32 unArrayLength = luaL_checkint(L, 2);
	luaL_checktype(L, 1, LUA_TTABLE);
	std::vector<SteamItemDef_t> pArrayItemDefs(unArrayLength);
	for(decltype(unArrayLength) i = 0; i < unArrayLength; i++) {
		lua_rawgeti(L, 1, i+1);
		pArrayItemDefs[i] = static_cast<SteamItemDef_t>(luaL_checkint(L, -1));
		lua_pop(L, 1);
	}
	luaL_checktype(L, 3, LUA_TTABLE);
	std::vector<uint32> punArrayQuantity(unArrayLength);
	for(decltype(unArrayLength) i = 0; i < unArrayLength; i++) {
		lua_rawgeti(L, 3, i+1);
		punArrayQuantity[i] = static_cast<uint32>(luaL_checkint(L, -1));
		lua_pop(L, 1);
	}
	bool __ret = iface->GenerateItems(&pResultHandle, pArrayItemDefs.data(), punArrayQuantity.data(), unArrayLength);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pResultHandle);
	return 2;
}
static int luasteam_Inventory_GenerateItems_user(lua_State *L) { return luasteam_Inventory_GenerateItems(L, SteamInventory()); }
static int luasteam_Inventory_GenerateItems_gs(lua_State *L) { return luasteam_Inventory_GenerateItems(L, SteamGameServerInventory()); }

// In C++:
// bool GrantPromoItems(SteamInventoryResult_t * pResultHandle);
// In Lua:
// (bool, pResultHandle: int) Inventory.GrantPromoItems()
static int luasteam_Inventory_GrantPromoItems(lua_State *L, ISteamInventory *iface) {
	SteamInventoryResult_t pResultHandle;
	bool __ret = iface->GrantPromoItems(&pResultHandle);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pResultHandle);
	return 2;
}
static int luasteam_Inventory_GrantPromoItems_user(lua_State *L) { return luasteam_Inventory_GrantPromoItems(L, SteamInventory()); }
static int luasteam_Inventory_GrantPromoItems_gs(lua_State *L) { return luasteam_Inventory_GrantPromoItems(L, SteamGameServerInventory()); }

// In C++:
// bool AddPromoItem(SteamInventoryResult_t * pResultHandle, SteamItemDef_t itemDef);
// In Lua:
// (bool, pResultHandle: int) Inventory.AddPromoItem(itemDef: int)
static int luasteam_Inventory_AddPromoItem(lua_State *L, ISteamInventory *iface) {
	SteamInventoryResult_t pResultHandle;
	SteamItemDef_t itemDef = static_cast<SteamItemDef_t>(luaL_checkint(L, 1));
	bool __ret = iface->AddPromoItem(&pResultHandle, itemDef);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pResultHandle);
	return 2;
}
static int luasteam_Inventory_AddPromoItem_user(lua_State *L) { return luasteam_Inventory_AddPromoItem(L, SteamInventory()); }
static int luasteam_Inventory_AddPromoItem_gs(lua_State *L) { return luasteam_Inventory_AddPromoItem(L, SteamGameServerInventory()); }

// In C++:
// bool AddPromoItems(SteamInventoryResult_t * pResultHandle, const SteamItemDef_t * pArrayItemDefs, uint32 unArrayLength);
// In Lua:
// (bool, pResultHandle: int) Inventory.AddPromoItems(pArrayItemDefs: int[], unArrayLength: int)
static int luasteam_Inventory_AddPromoItems(lua_State *L, ISteamInventory *iface) {
	SteamInventoryResult_t pResultHandle;
	uint32 unArrayLength = luaL_checkint(L, 2);
	luaL_checktype(L, 1, LUA_TTABLE);
	std::vector<SteamItemDef_t> pArrayItemDefs(unArrayLength);
	for(decltype(unArrayLength) i = 0; i < unArrayLength; i++) {
		lua_rawgeti(L, 1, i+1);
		pArrayItemDefs[i] = static_cast<SteamItemDef_t>(luaL_checkint(L, -1));
		lua_pop(L, 1);
	}
	bool __ret = iface->AddPromoItems(&pResultHandle, pArrayItemDefs.data(), unArrayLength);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pResultHandle);
	return 2;
}
static int luasteam_Inventory_AddPromoItems_user(lua_State *L) { return luasteam_Inventory_AddPromoItems(L, SteamInventory()); }
static int luasteam_Inventory_AddPromoItems_gs(lua_State *L) { return luasteam_Inventory_AddPromoItems(L, SteamGameServerInventory()); }

// In C++:
// bool ConsumeItem(SteamInventoryResult_t * pResultHandle, SteamItemInstanceID_t itemConsume, uint32 unQuantity);
// In Lua:
// (bool, pResultHandle: int) Inventory.ConsumeItem(itemConsume: uint64, unQuantity: int)
static int luasteam_Inventory_ConsumeItem(lua_State *L, ISteamInventory *iface) {
	SteamInventoryResult_t pResultHandle;
	SteamItemInstanceID_t itemConsume(luasteam::checkuint64(L, 1));
	uint32 unQuantity = static_cast<uint32>(luaL_checkint(L, 2));
	bool __ret = iface->ConsumeItem(&pResultHandle, itemConsume, unQuantity);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pResultHandle);
	return 2;
}
static int luasteam_Inventory_ConsumeItem_user(lua_State *L) { return luasteam_Inventory_ConsumeItem(L, SteamInventory()); }
static int luasteam_Inventory_ConsumeItem_gs(lua_State *L) { return luasteam_Inventory_ConsumeItem(L, SteamGameServerInventory()); }

// In C++:
// bool ExchangeItems(SteamInventoryResult_t * pResultHandle, const SteamItemDef_t * pArrayGenerate, const uint32 * punArrayGenerateQuantity, uint32 unArrayGenerateLength, const SteamItemInstanceID_t * pArrayDestroy, const uint32 * punArrayDestroyQuantity, uint32 unArrayDestroyLength);
// In Lua:
// (bool, pResultHandle: int) Inventory.ExchangeItems(pArrayGenerate: int[], unArrayGenerateLength: int, punArrayGenerateQuantity: int[], pArrayDestroy: uint64[], unArrayDestroyLength: int, punArrayDestroyQuantity: int[])
static int luasteam_Inventory_ExchangeItems(lua_State *L, ISteamInventory *iface) {
	SteamInventoryResult_t pResultHandle;
	uint32 unArrayGenerateLength = luaL_checkint(L, 2);
	luaL_checktype(L, 1, LUA_TTABLE);
	std::vector<SteamItemDef_t> pArrayGenerate(unArrayGenerateLength);
	for(decltype(unArrayGenerateLength) i = 0; i < unArrayGenerateLength; i++) {
		lua_rawgeti(L, 1, i+1);
		pArrayGenerate[i] = static_cast<SteamItemDef_t>(luaL_checkint(L, -1));
		lua_pop(L, 1);
	}
	luaL_checktype(L, 3, LUA_TTABLE);
	std::vector<uint32> punArrayGenerateQuantity(unArrayGenerateLength);
	for(decltype(unArrayGenerateLength) i = 0; i < unArrayGenerateLength; i++) {
		lua_rawgeti(L, 3, i+1);
		punArrayGenerateQuantity[i] = static_cast<uint32>(luaL_checkint(L, -1));
		lua_pop(L, 1);
	}
	uint32 unArrayDestroyLength = luaL_checkint(L, 4);
	luaL_checktype(L, 3, LUA_TTABLE);
	std::vector<SteamItemInstanceID_t> pArrayDestroy(unArrayDestroyLength);
	for(decltype(unArrayDestroyLength) i = 0; i < unArrayDestroyLength; i++) {
		lua_rawgeti(L, 3, i+1);
		pArrayDestroy[i] = luasteam::checkuint64(L, -1);
		lua_pop(L, 1);
	}
	luaL_checktype(L, 5, LUA_TTABLE);
	std::vector<uint32> punArrayDestroyQuantity(unArrayDestroyLength);
	for(decltype(unArrayDestroyLength) i = 0; i < unArrayDestroyLength; i++) {
		lua_rawgeti(L, 5, i+1);
		punArrayDestroyQuantity[i] = static_cast<uint32>(luaL_checkint(L, -1));
		lua_pop(L, 1);
	}
	bool __ret = iface->ExchangeItems(&pResultHandle, pArrayGenerate.data(), punArrayGenerateQuantity.data(), unArrayGenerateLength, pArrayDestroy.data(), punArrayDestroyQuantity.data(), unArrayDestroyLength);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pResultHandle);
	return 2;
}
static int luasteam_Inventory_ExchangeItems_user(lua_State *L) { return luasteam_Inventory_ExchangeItems(L, SteamInventory()); }
static int luasteam_Inventory_ExchangeItems_gs(lua_State *L) { return luasteam_Inventory_ExchangeItems(L, SteamGameServerInventory()); }

// In C++:
// bool TransferItemQuantity(SteamInventoryResult_t * pResultHandle, SteamItemInstanceID_t itemIdSource, uint32 unQuantity, SteamItemInstanceID_t itemIdDest);
// In Lua:
// (bool, pResultHandle: int) Inventory.TransferItemQuantity(itemIdSource: uint64, unQuantity: int, itemIdDest: uint64)
static int luasteam_Inventory_TransferItemQuantity(lua_State *L, ISteamInventory *iface) {
	SteamInventoryResult_t pResultHandle;
	SteamItemInstanceID_t itemIdSource(luasteam::checkuint64(L, 1));
	uint32 unQuantity = static_cast<uint32>(luaL_checkint(L, 2));
	SteamItemInstanceID_t itemIdDest(luasteam::checkuint64(L, 3));
	bool __ret = iface->TransferItemQuantity(&pResultHandle, itemIdSource, unQuantity, itemIdDest);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pResultHandle);
	return 2;
}
static int luasteam_Inventory_TransferItemQuantity_user(lua_State *L) { return luasteam_Inventory_TransferItemQuantity(L, SteamInventory()); }
static int luasteam_Inventory_TransferItemQuantity_gs(lua_State *L) { return luasteam_Inventory_TransferItemQuantity(L, SteamGameServerInventory()); }

// In C++:
// void SendItemDropHeartbeat();
// In Lua:
// Inventory.SendItemDropHeartbeat()
static int luasteam_Inventory_SendItemDropHeartbeat(lua_State *L, ISteamInventory *iface) {
	iface->SendItemDropHeartbeat();
	return 0;
}
static int luasteam_Inventory_SendItemDropHeartbeat_user(lua_State *L) { return luasteam_Inventory_SendItemDropHeartbeat(L, SteamInventory()); }
static int luasteam_Inventory_SendItemDropHeartbeat_gs(lua_State *L) { return luasteam_Inventory_SendItemDropHeartbeat(L, SteamGameServerInventory()); }

// In C++:
// bool TriggerItemDrop(SteamInventoryResult_t * pResultHandle, SteamItemDef_t dropListDefinition);
// In Lua:
// (bool, pResultHandle: int) Inventory.TriggerItemDrop(dropListDefinition: int)
static int luasteam_Inventory_TriggerItemDrop(lua_State *L, ISteamInventory *iface) {
	SteamInventoryResult_t pResultHandle;
	SteamItemDef_t dropListDefinition = static_cast<SteamItemDef_t>(luaL_checkint(L, 1));
	bool __ret = iface->TriggerItemDrop(&pResultHandle, dropListDefinition);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pResultHandle);
	return 2;
}
static int luasteam_Inventory_TriggerItemDrop_user(lua_State *L) { return luasteam_Inventory_TriggerItemDrop(L, SteamInventory()); }
static int luasteam_Inventory_TriggerItemDrop_gs(lua_State *L) { return luasteam_Inventory_TriggerItemDrop(L, SteamGameServerInventory()); }

// In C++:
// bool TradeItems(SteamInventoryResult_t * pResultHandle, CSteamID steamIDTradePartner, const SteamItemInstanceID_t * pArrayGive, const uint32 * pArrayGiveQuantity, uint32 nArrayGiveLength, const SteamItemInstanceID_t * pArrayGet, const uint32 * pArrayGetQuantity, uint32 nArrayGetLength);
// In Lua:
// (bool, pResultHandle: int) Inventory.TradeItems(steamIDTradePartner: uint64, pArrayGive: uint64[], nArrayGiveLength: int, pArrayGiveQuantity: int[], pArrayGet: uint64[], nArrayGetLength: int, pArrayGetQuantity: int[])
static int luasteam_Inventory_TradeItems(lua_State *L, ISteamInventory *iface) {
	SteamInventoryResult_t pResultHandle;
	CSteamID steamIDTradePartner(luasteam::checkuint64(L, 1));
	uint32 nArrayGiveLength = luaL_checkint(L, 3);
	luaL_checktype(L, 2, LUA_TTABLE);
	std::vector<SteamItemInstanceID_t> pArrayGive(nArrayGiveLength);
	for(decltype(nArrayGiveLength) i = 0; i < nArrayGiveLength; i++) {
		lua_rawgeti(L, 2, i+1);
		pArrayGive[i] = luasteam::checkuint64(L, -1);
		lua_pop(L, 1);
	}
	luaL_checktype(L, 4, LUA_TTABLE);
	std::vector<uint32> pArrayGiveQuantity(nArrayGiveLength);
	for(decltype(nArrayGiveLength) i = 0; i < nArrayGiveLength; i++) {
		lua_rawgeti(L, 4, i+1);
		pArrayGiveQuantity[i] = static_cast<uint32>(luaL_checkint(L, -1));
		lua_pop(L, 1);
	}
	uint32 nArrayGetLength = luaL_checkint(L, 5);
	luaL_checktype(L, 4, LUA_TTABLE);
	std::vector<SteamItemInstanceID_t> pArrayGet(nArrayGetLength);
	for(decltype(nArrayGetLength) i = 0; i < nArrayGetLength; i++) {
		lua_rawgeti(L, 4, i+1);
		pArrayGet[i] = luasteam::checkuint64(L, -1);
		lua_pop(L, 1);
	}
	luaL_checktype(L, 6, LUA_TTABLE);
	std::vector<uint32> pArrayGetQuantity(nArrayGetLength);
	for(decltype(nArrayGetLength) i = 0; i < nArrayGetLength; i++) {
		lua_rawgeti(L, 6, i+1);
		pArrayGetQuantity[i] = static_cast<uint32>(luaL_checkint(L, -1));
		lua_pop(L, 1);
	}
	bool __ret = iface->TradeItems(&pResultHandle, steamIDTradePartner, pArrayGive.data(), pArrayGiveQuantity.data(), nArrayGiveLength, pArrayGet.data(), pArrayGetQuantity.data(), nArrayGetLength);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pResultHandle);
	return 2;
}
static int luasteam_Inventory_TradeItems_user(lua_State *L) { return luasteam_Inventory_TradeItems(L, SteamInventory()); }
static int luasteam_Inventory_TradeItems_gs(lua_State *L) { return luasteam_Inventory_TradeItems(L, SteamGameServerInventory()); }

// In C++:
// bool LoadItemDefinitions();
// In Lua:
// bool Inventory.LoadItemDefinitions()
static int luasteam_Inventory_LoadItemDefinitions(lua_State *L, ISteamInventory *iface) {
	bool __ret = iface->LoadItemDefinitions();
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_Inventory_LoadItemDefinitions_user(lua_State *L) { return luasteam_Inventory_LoadItemDefinitions(L, SteamInventory()); }
static int luasteam_Inventory_LoadItemDefinitions_gs(lua_State *L) { return luasteam_Inventory_LoadItemDefinitions(L, SteamGameServerInventory()); }

// In C++:
// bool GetItemDefinitionIDs(SteamItemDef_t * pItemDefIDs, uint32 * punItemDefIDsArraySize);
// In Lua:
// (bool, pItemDefIDs: int[], punItemDefIDsArraySize: int) Inventory.GetItemDefinitionIDs(punItemDefIDsArraySize: int)
static int luasteam_Inventory_GetItemDefinitionIDs(lua_State *L, ISteamInventory *iface) {
	uint32 punItemDefIDsArraySize = luaL_checkint(L, 1);
	std::vector<SteamItemDef_t> pItemDefIDs(punItemDefIDsArraySize);
	bool __ret = iface->GetItemDefinitionIDs(pItemDefIDs.data(), &punItemDefIDsArraySize);
	lua_pushboolean(L, __ret);
	lua_createtable(L, punItemDefIDsArraySize, 0);
	for(decltype(punItemDefIDsArraySize) i = 0; i < punItemDefIDsArraySize; i++) {
		lua_pushinteger(L, pItemDefIDs[i]);
		lua_rawseti(L, -2, i+1);
	}
	lua_pushinteger(L, punItemDefIDsArraySize);
	return 3;
}
static int luasteam_Inventory_GetItemDefinitionIDs_user(lua_State *L) { return luasteam_Inventory_GetItemDefinitionIDs(L, SteamInventory()); }
static int luasteam_Inventory_GetItemDefinitionIDs_gs(lua_State *L) { return luasteam_Inventory_GetItemDefinitionIDs(L, SteamGameServerInventory()); }

// In C++:
// bool GetItemDefinitionProperty(SteamItemDef_t iDefinition, const char * pchPropertyName, char * pchValueBuffer, uint32 * punValueBufferSizeOut);
// In Lua:
// (bool, pchValueBuffer: str, punValueBufferSizeOut: int) Inventory.GetItemDefinitionProperty(iDefinition: int, pchPropertyName: str, punValueBufferSizeOut: int)
static int luasteam_Inventory_GetItemDefinitionProperty(lua_State *L, ISteamInventory *iface) {
	SteamItemDef_t iDefinition = static_cast<SteamItemDef_t>(luaL_checkint(L, 1));
	const char *pchPropertyName = luaL_checkstring(L, 2);
	uint32 punValueBufferSizeOut = luaL_checkint(L, 3);
	std::vector<char> pchValueBuffer(punValueBufferSizeOut);
	bool __ret = iface->GetItemDefinitionProperty(iDefinition, pchPropertyName, pchValueBuffer.data(), &punValueBufferSizeOut);
	lua_pushboolean(L, __ret);
	lua_pushstring(L, reinterpret_cast<const char*>(pchValueBuffer.data()));
	lua_pushinteger(L, punValueBufferSizeOut);
	return 3;
}
static int luasteam_Inventory_GetItemDefinitionProperty_user(lua_State *L) { return luasteam_Inventory_GetItemDefinitionProperty(L, SteamInventory()); }
static int luasteam_Inventory_GetItemDefinitionProperty_gs(lua_State *L) { return luasteam_Inventory_GetItemDefinitionProperty(L, SteamGameServerInventory()); }

// In C++:
// SteamAPICall_t RequestEligiblePromoItemDefinitionsIDs(CSteamID steamID);
// In Lua:
// uint64 Inventory.RequestEligiblePromoItemDefinitionsIDs(steamID: uint64, callback: function)
static int luasteam_Inventory_RequestEligiblePromoItemDefinitionsIDs(lua_State *L, ISteamInventory *iface) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	CSteamID steamID(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = iface->RequestEligiblePromoItemDefinitionsIDs(steamID);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<SteamInventoryEligiblePromoItemDefIDs_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<SteamInventoryEligiblePromoItemDefIDs_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}
static int luasteam_Inventory_RequestEligiblePromoItemDefinitionsIDs_user(lua_State *L) { return luasteam_Inventory_RequestEligiblePromoItemDefinitionsIDs(L, SteamInventory()); }
static int luasteam_Inventory_RequestEligiblePromoItemDefinitionsIDs_gs(lua_State *L) { return luasteam_Inventory_RequestEligiblePromoItemDefinitionsIDs(L, SteamGameServerInventory()); }

// In C++:
// bool GetEligiblePromoItemDefinitionIDs(CSteamID steamID, SteamItemDef_t * pItemDefIDs, uint32 * punItemDefIDsArraySize);
// In Lua:
// (bool, pItemDefIDs: int[], punItemDefIDsArraySize: int) Inventory.GetEligiblePromoItemDefinitionIDs(steamID: uint64, punItemDefIDsArraySize: int)
static int luasteam_Inventory_GetEligiblePromoItemDefinitionIDs(lua_State *L, ISteamInventory *iface) {
	CSteamID steamID(luasteam::checkuint64(L, 1));
	uint32 punItemDefIDsArraySize = luaL_checkint(L, 2);
	std::vector<SteamItemDef_t> pItemDefIDs(punItemDefIDsArraySize);
	bool __ret = iface->GetEligiblePromoItemDefinitionIDs(steamID, pItemDefIDs.data(), &punItemDefIDsArraySize);
	lua_pushboolean(L, __ret);
	lua_createtable(L, punItemDefIDsArraySize, 0);
	for(decltype(punItemDefIDsArraySize) i = 0; i < punItemDefIDsArraySize; i++) {
		lua_pushinteger(L, pItemDefIDs[i]);
		lua_rawseti(L, -2, i+1);
	}
	lua_pushinteger(L, punItemDefIDsArraySize);
	return 3;
}
static int luasteam_Inventory_GetEligiblePromoItemDefinitionIDs_user(lua_State *L) { return luasteam_Inventory_GetEligiblePromoItemDefinitionIDs(L, SteamInventory()); }
static int luasteam_Inventory_GetEligiblePromoItemDefinitionIDs_gs(lua_State *L) { return luasteam_Inventory_GetEligiblePromoItemDefinitionIDs(L, SteamGameServerInventory()); }

// In C++:
// SteamAPICall_t StartPurchase(const SteamItemDef_t * pArrayItemDefs, const uint32 * punArrayQuantity, uint32 unArrayLength);
// In Lua:
// uint64 Inventory.StartPurchase(pArrayItemDefs: int[], unArrayLength: int, punArrayQuantity: int[], callback: function)
static int luasteam_Inventory_StartPurchase(lua_State *L, ISteamInventory *iface) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	uint32 unArrayLength = luaL_checkint(L, 2);
	luaL_checktype(L, 1, LUA_TTABLE);
	std::vector<SteamItemDef_t> pArrayItemDefs(unArrayLength);
	for(decltype(unArrayLength) i = 0; i < unArrayLength; i++) {
		lua_rawgeti(L, 1, i+1);
		pArrayItemDefs[i] = static_cast<SteamItemDef_t>(luaL_checkint(L, -1));
		lua_pop(L, 1);
	}
	luaL_checktype(L, 3, LUA_TTABLE);
	std::vector<uint32> punArrayQuantity(unArrayLength);
	for(decltype(unArrayLength) i = 0; i < unArrayLength; i++) {
		lua_rawgeti(L, 3, i+1);
		punArrayQuantity[i] = static_cast<uint32>(luaL_checkint(L, -1));
		lua_pop(L, 1);
	}
	SteamAPICall_t __ret = iface->StartPurchase(pArrayItemDefs.data(), punArrayQuantity.data(), unArrayLength);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<SteamInventoryStartPurchaseResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<SteamInventoryStartPurchaseResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}
static int luasteam_Inventory_StartPurchase_user(lua_State *L) { return luasteam_Inventory_StartPurchase(L, SteamInventory()); }
static int luasteam_Inventory_StartPurchase_gs(lua_State *L) { return luasteam_Inventory_StartPurchase(L, SteamGameServerInventory()); }

// In C++:
// SteamAPICall_t RequestPrices();
// In Lua:
// uint64 Inventory.RequestPrices(callback: function)
static int luasteam_Inventory_RequestPrices(lua_State *L, ISteamInventory *iface) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	SteamAPICall_t __ret = iface->RequestPrices();
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<SteamInventoryRequestPricesResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<SteamInventoryRequestPricesResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}
static int luasteam_Inventory_RequestPrices_user(lua_State *L) { return luasteam_Inventory_RequestPrices(L, SteamInventory()); }
static int luasteam_Inventory_RequestPrices_gs(lua_State *L) { return luasteam_Inventory_RequestPrices(L, SteamGameServerInventory()); }

// In C++:
// uint32 GetNumItemsWithPrices();
// In Lua:
// int Inventory.GetNumItemsWithPrices()
static int luasteam_Inventory_GetNumItemsWithPrices(lua_State *L, ISteamInventory *iface) {
	uint32 __ret = iface->GetNumItemsWithPrices();
	lua_pushinteger(L, __ret);
	return 1;
}
static int luasteam_Inventory_GetNumItemsWithPrices_user(lua_State *L) { return luasteam_Inventory_GetNumItemsWithPrices(L, SteamInventory()); }
static int luasteam_Inventory_GetNumItemsWithPrices_gs(lua_State *L) { return luasteam_Inventory_GetNumItemsWithPrices(L, SteamGameServerInventory()); }

// In C++:
// bool GetItemPrice(SteamItemDef_t iDefinition, uint64 * pCurrentPrice, uint64 * pBasePrice);
// In Lua:
// (bool, pCurrentPrice: uint64, pBasePrice: uint64) Inventory.GetItemPrice(iDefinition: int)
static int luasteam_Inventory_GetItemPrice(lua_State *L, ISteamInventory *iface) {
	SteamItemDef_t iDefinition = static_cast<SteamItemDef_t>(luaL_checkint(L, 1));
	uint64 pCurrentPrice;
	uint64 pBasePrice;
	bool __ret = iface->GetItemPrice(iDefinition, &pCurrentPrice, &pBasePrice);
	lua_pushboolean(L, __ret);
	luasteam::pushuint64(L, pCurrentPrice);
	luasteam::pushuint64(L, pBasePrice);
	return 3;
}
static int luasteam_Inventory_GetItemPrice_user(lua_State *L) { return luasteam_Inventory_GetItemPrice(L, SteamInventory()); }
static int luasteam_Inventory_GetItemPrice_gs(lua_State *L) { return luasteam_Inventory_GetItemPrice(L, SteamGameServerInventory()); }

// In C++:
// SteamInventoryUpdateHandle_t StartUpdateProperties();
// In Lua:
// uint64 Inventory.StartUpdateProperties()
static int luasteam_Inventory_StartUpdateProperties(lua_State *L, ISteamInventory *iface) {
	SteamInventoryUpdateHandle_t __ret = iface->StartUpdateProperties();
	luasteam::pushuint64(L, __ret);
	return 1;
}
static int luasteam_Inventory_StartUpdateProperties_user(lua_State *L) { return luasteam_Inventory_StartUpdateProperties(L, SteamInventory()); }
static int luasteam_Inventory_StartUpdateProperties_gs(lua_State *L) { return luasteam_Inventory_StartUpdateProperties(L, SteamGameServerInventory()); }

// In C++:
// bool RemoveProperty(SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, const char * pchPropertyName);
// In Lua:
// bool Inventory.RemoveProperty(handle: uint64, nItemID: uint64, pchPropertyName: str)
static int luasteam_Inventory_RemoveProperty(lua_State *L, ISteamInventory *iface) {
	SteamInventoryUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	SteamItemInstanceID_t nItemID(luasteam::checkuint64(L, 2));
	const char *pchPropertyName = luaL_checkstring(L, 3);
	bool __ret = iface->RemoveProperty(handle, nItemID, pchPropertyName);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_Inventory_RemoveProperty_user(lua_State *L) { return luasteam_Inventory_RemoveProperty(L, SteamInventory()); }
static int luasteam_Inventory_RemoveProperty_gs(lua_State *L) { return luasteam_Inventory_RemoveProperty(L, SteamGameServerInventory()); }

// In C++:
// bool SetProperty(SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, const char * pchPropertyName, const char * pchPropertyValue);
// In Lua:
// bool Inventory.SetPropertyString(handle: uint64, nItemID: uint64, pchPropertyName: str, pchPropertyValue: str)
static int luasteam_Inventory_SetPropertyString(lua_State *L, ISteamInventory *iface) {
	SteamInventoryUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	SteamItemInstanceID_t nItemID(luasteam::checkuint64(L, 2));
	const char *pchPropertyName = luaL_checkstring(L, 3);
	const char *pchPropertyValue = luaL_checkstring(L, 4);
	bool __ret = iface->SetProperty(handle, nItemID, pchPropertyName, pchPropertyValue);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_Inventory_SetPropertyString_user(lua_State *L) { return luasteam_Inventory_SetPropertyString(L, SteamInventory()); }
static int luasteam_Inventory_SetPropertyString_gs(lua_State *L) { return luasteam_Inventory_SetPropertyString(L, SteamGameServerInventory()); }

// In C++:
// bool SetProperty(SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, const char * pchPropertyName, bool bValue);
// In Lua:
// bool Inventory.SetPropertyBool(handle: uint64, nItemID: uint64, pchPropertyName: str, bValue: bool)
static int luasteam_Inventory_SetPropertyBool(lua_State *L, ISteamInventory *iface) {
	SteamInventoryUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	SteamItemInstanceID_t nItemID(luasteam::checkuint64(L, 2));
	const char *pchPropertyName = luaL_checkstring(L, 3);
	bool bValue = lua_toboolean(L, 4);
	bool __ret = iface->SetProperty(handle, nItemID, pchPropertyName, bValue);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_Inventory_SetPropertyBool_user(lua_State *L) { return luasteam_Inventory_SetPropertyBool(L, SteamInventory()); }
static int luasteam_Inventory_SetPropertyBool_gs(lua_State *L) { return luasteam_Inventory_SetPropertyBool(L, SteamGameServerInventory()); }

// In C++:
// bool SetProperty(SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, const char * pchPropertyName, int64 nValue);
// In Lua:
// bool Inventory.SetPropertyInt64(handle: uint64, nItemID: uint64, pchPropertyName: str, nValue: uint64)
static int luasteam_Inventory_SetPropertyInt64(lua_State *L, ISteamInventory *iface) {
	SteamInventoryUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	SteamItemInstanceID_t nItemID(luasteam::checkuint64(L, 2));
	const char *pchPropertyName = luaL_checkstring(L, 3);
	int64 nValue(luasteam::checkuint64(L, 4));
	bool __ret = iface->SetProperty(handle, nItemID, pchPropertyName, nValue);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_Inventory_SetPropertyInt64_user(lua_State *L) { return luasteam_Inventory_SetPropertyInt64(L, SteamInventory()); }
static int luasteam_Inventory_SetPropertyInt64_gs(lua_State *L) { return luasteam_Inventory_SetPropertyInt64(L, SteamGameServerInventory()); }

// In C++:
// bool SetProperty(SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, const char * pchPropertyName, float flValue);
// In Lua:
// bool Inventory.SetPropertyFloat(handle: uint64, nItemID: uint64, pchPropertyName: str, flValue: float)
static int luasteam_Inventory_SetPropertyFloat(lua_State *L, ISteamInventory *iface) {
	SteamInventoryUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	SteamItemInstanceID_t nItemID(luasteam::checkuint64(L, 2));
	const char *pchPropertyName = luaL_checkstring(L, 3);
	float flValue = luaL_checknumber(L, 4);
	bool __ret = iface->SetProperty(handle, nItemID, pchPropertyName, flValue);
	lua_pushboolean(L, __ret);
	return 1;
}
static int luasteam_Inventory_SetPropertyFloat_user(lua_State *L) { return luasteam_Inventory_SetPropertyFloat(L, SteamInventory()); }
static int luasteam_Inventory_SetPropertyFloat_gs(lua_State *L) { return luasteam_Inventory_SetPropertyFloat(L, SteamGameServerInventory()); }

// In C++:
// bool SubmitUpdateProperties(SteamInventoryUpdateHandle_t handle, SteamInventoryResult_t * pResultHandle);
// In Lua:
// (bool, pResultHandle: int) Inventory.SubmitUpdateProperties(handle: uint64)
static int luasteam_Inventory_SubmitUpdateProperties(lua_State *L, ISteamInventory *iface) {
	SteamInventoryUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	SteamInventoryResult_t pResultHandle;
	bool __ret = iface->SubmitUpdateProperties(handle, &pResultHandle);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pResultHandle);
	return 2;
}
static int luasteam_Inventory_SubmitUpdateProperties_user(lua_State *L) { return luasteam_Inventory_SubmitUpdateProperties(L, SteamInventory()); }
static int luasteam_Inventory_SubmitUpdateProperties_gs(lua_State *L) { return luasteam_Inventory_SubmitUpdateProperties(L, SteamGameServerInventory()); }

// In C++:
// bool InspectItem(SteamInventoryResult_t * pResultHandle, const char * pchItemToken);
// In Lua:
// (bool, pResultHandle: int) Inventory.InspectItem(pchItemToken: str)
static int luasteam_Inventory_InspectItem(lua_State *L, ISteamInventory *iface) {
	SteamInventoryResult_t pResultHandle;
	const char *pchItemToken = luaL_checkstring(L, 1);
	bool __ret = iface->InspectItem(&pResultHandle, pchItemToken);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pResultHandle);
	return 2;
}
static int luasteam_Inventory_InspectItem_user(lua_State *L) { return luasteam_Inventory_InspectItem(L, SteamInventory()); }
static int luasteam_Inventory_InspectItem_gs(lua_State *L) { return luasteam_Inventory_InspectItem(L, SteamGameServerInventory()); }

void register_Inventory_auto(lua_State *L, bool is_gs) {
	add_func(L, "GetResultStatus", is_gs ? luasteam_Inventory_GetResultStatus_gs : luasteam_Inventory_GetResultStatus_user);
	add_func(L, "GetResultItems", is_gs ? luasteam_Inventory_GetResultItems_gs : luasteam_Inventory_GetResultItems_user);
	add_func(L, "GetResultItemProperty", is_gs ? luasteam_Inventory_GetResultItemProperty_gs : luasteam_Inventory_GetResultItemProperty_user);
	add_func(L, "GetResultTimestamp", is_gs ? luasteam_Inventory_GetResultTimestamp_gs : luasteam_Inventory_GetResultTimestamp_user);
	add_func(L, "CheckResultSteamID", is_gs ? luasteam_Inventory_CheckResultSteamID_gs : luasteam_Inventory_CheckResultSteamID_user);
	add_func(L, "DestroyResult", is_gs ? luasteam_Inventory_DestroyResult_gs : luasteam_Inventory_DestroyResult_user);
	add_func(L, "GetAllItems", is_gs ? luasteam_Inventory_GetAllItems_gs : luasteam_Inventory_GetAllItems_user);
	add_func(L, "GetItemsByID", is_gs ? luasteam_Inventory_GetItemsByID_gs : luasteam_Inventory_GetItemsByID_user);
	add_func(L, "DeserializeResult", is_gs ? luasteam_Inventory_DeserializeResult_gs : luasteam_Inventory_DeserializeResult_user);
	add_func(L, "GenerateItems", is_gs ? luasteam_Inventory_GenerateItems_gs : luasteam_Inventory_GenerateItems_user);
	add_func(L, "GrantPromoItems", is_gs ? luasteam_Inventory_GrantPromoItems_gs : luasteam_Inventory_GrantPromoItems_user);
	add_func(L, "AddPromoItem", is_gs ? luasteam_Inventory_AddPromoItem_gs : luasteam_Inventory_AddPromoItem_user);
	add_func(L, "AddPromoItems", is_gs ? luasteam_Inventory_AddPromoItems_gs : luasteam_Inventory_AddPromoItems_user);
	add_func(L, "ConsumeItem", is_gs ? luasteam_Inventory_ConsumeItem_gs : luasteam_Inventory_ConsumeItem_user);
	add_func(L, "ExchangeItems", is_gs ? luasteam_Inventory_ExchangeItems_gs : luasteam_Inventory_ExchangeItems_user);
	add_func(L, "TransferItemQuantity", is_gs ? luasteam_Inventory_TransferItemQuantity_gs : luasteam_Inventory_TransferItemQuantity_user);
	add_func(L, "SendItemDropHeartbeat", is_gs ? luasteam_Inventory_SendItemDropHeartbeat_gs : luasteam_Inventory_SendItemDropHeartbeat_user);
	add_func(L, "TriggerItemDrop", is_gs ? luasteam_Inventory_TriggerItemDrop_gs : luasteam_Inventory_TriggerItemDrop_user);
	add_func(L, "TradeItems", is_gs ? luasteam_Inventory_TradeItems_gs : luasteam_Inventory_TradeItems_user);
	add_func(L, "LoadItemDefinitions", is_gs ? luasteam_Inventory_LoadItemDefinitions_gs : luasteam_Inventory_LoadItemDefinitions_user);
	add_func(L, "GetItemDefinitionIDs", is_gs ? luasteam_Inventory_GetItemDefinitionIDs_gs : luasteam_Inventory_GetItemDefinitionIDs_user);
	add_func(L, "GetItemDefinitionProperty", is_gs ? luasteam_Inventory_GetItemDefinitionProperty_gs : luasteam_Inventory_GetItemDefinitionProperty_user);
	add_func(L, "RequestEligiblePromoItemDefinitionsIDs", is_gs ? luasteam_Inventory_RequestEligiblePromoItemDefinitionsIDs_gs : luasteam_Inventory_RequestEligiblePromoItemDefinitionsIDs_user);
	add_func(L, "GetEligiblePromoItemDefinitionIDs", is_gs ? luasteam_Inventory_GetEligiblePromoItemDefinitionIDs_gs : luasteam_Inventory_GetEligiblePromoItemDefinitionIDs_user);
	add_func(L, "StartPurchase", is_gs ? luasteam_Inventory_StartPurchase_gs : luasteam_Inventory_StartPurchase_user);
	add_func(L, "RequestPrices", is_gs ? luasteam_Inventory_RequestPrices_gs : luasteam_Inventory_RequestPrices_user);
	add_func(L, "GetNumItemsWithPrices", is_gs ? luasteam_Inventory_GetNumItemsWithPrices_gs : luasteam_Inventory_GetNumItemsWithPrices_user);
	add_func(L, "GetItemPrice", is_gs ? luasteam_Inventory_GetItemPrice_gs : luasteam_Inventory_GetItemPrice_user);
	add_func(L, "StartUpdateProperties", is_gs ? luasteam_Inventory_StartUpdateProperties_gs : luasteam_Inventory_StartUpdateProperties_user);
	add_func(L, "RemoveProperty", is_gs ? luasteam_Inventory_RemoveProperty_gs : luasteam_Inventory_RemoveProperty_user);
	add_func(L, "SetPropertyString", is_gs ? luasteam_Inventory_SetPropertyString_gs : luasteam_Inventory_SetPropertyString_user);
	add_func(L, "SetPropertyBool", is_gs ? luasteam_Inventory_SetPropertyBool_gs : luasteam_Inventory_SetPropertyBool_user);
	add_func(L, "SetPropertyInt64", is_gs ? luasteam_Inventory_SetPropertyInt64_gs : luasteam_Inventory_SetPropertyInt64_user);
	add_func(L, "SetPropertyFloat", is_gs ? luasteam_Inventory_SetPropertyFloat_gs : luasteam_Inventory_SetPropertyFloat_user);
	add_func(L, "SubmitUpdateProperties", is_gs ? luasteam_Inventory_SubmitUpdateProperties_gs : luasteam_Inventory_SubmitUpdateProperties_user);
	add_func(L, "InspectItem", is_gs ? luasteam_Inventory_InspectItem_gs : luasteam_Inventory_InspectItem_user);
}

void add_Inventory_auto(lua_State *L) {
	lua_createtable(L, 0, 36);
	register_Inventory_auto(L, false);
	lua_pushvalue(L, -1);
	Inventory_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "Inventory");
}

int GameServerInventory_ref = LUA_NOREF;

namespace {
class GameServerInventoryCallbackListener {
private:
	STEAM_GAMESERVER_CALLBACK(GameServerInventoryCallbackListener, OnSteamInventoryResultReady, SteamInventoryResultReady_t);
	STEAM_GAMESERVER_CALLBACK(GameServerInventoryCallbackListener, OnSteamInventoryFullUpdate, SteamInventoryFullUpdate_t);
	STEAM_GAMESERVER_CALLBACK(GameServerInventoryCallbackListener, OnSteamInventoryDefinitionUpdate, SteamInventoryDefinitionUpdate_t);
	STEAM_GAMESERVER_CALLBACK(GameServerInventoryCallbackListener, OnSteamInventoryEligiblePromoItemDefIDs, SteamInventoryEligiblePromoItemDefIDs_t);
	STEAM_GAMESERVER_CALLBACK(GameServerInventoryCallbackListener, OnSteamInventoryStartPurchaseResult, SteamInventoryStartPurchaseResult_t);
	STEAM_GAMESERVER_CALLBACK(GameServerInventoryCallbackListener, OnSteamInventoryRequestPricesResult, SteamInventoryRequestPricesResult_t);
};
void GameServerInventoryCallbackListener::OnSteamInventoryResultReady(SteamInventoryResultReady_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerInventory_ref);
	lua_getfield(L, -1, "OnSteamInventoryResultReady");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamInventoryResultReady_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerInventoryCallbackListener::OnSteamInventoryFullUpdate(SteamInventoryFullUpdate_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerInventory_ref);
	lua_getfield(L, -1, "OnSteamInventoryFullUpdate");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamInventoryFullUpdate_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerInventoryCallbackListener::OnSteamInventoryDefinitionUpdate(SteamInventoryDefinitionUpdate_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerInventory_ref);
	lua_getfield(L, -1, "OnSteamInventoryDefinitionUpdate");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamInventoryDefinitionUpdate_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerInventoryCallbackListener::OnSteamInventoryEligiblePromoItemDefIDs(SteamInventoryEligiblePromoItemDefIDs_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerInventory_ref);
	lua_getfield(L, -1, "OnSteamInventoryEligiblePromoItemDefIDs");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamInventoryEligiblePromoItemDefIDs_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerInventoryCallbackListener::OnSteamInventoryStartPurchaseResult(SteamInventoryStartPurchaseResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerInventory_ref);
	lua_getfield(L, -1, "OnSteamInventoryStartPurchaseResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamInventoryStartPurchaseResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
void GameServerInventoryCallbackListener::OnSteamInventoryRequestPricesResult(SteamInventoryRequestPricesResult_t *data) {
	if (data == nullptr) return;
	lua_State *L = luasteam::global_lua_state;
	if (!lua_checkstack(L, 4)) return;
	lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::GameServerInventory_ref);
	lua_getfield(L, -1, "OnSteamInventoryRequestPricesResult");
	if (lua_isnil(L, -1)) {
		lua_pop(L, 2);
	} else {
		luasteam::push_SteamInventoryRequestPricesResult_t(L, *data);
		lua_call(L, 1, 0);
		lua_pop(L, 1);
	}
}
GameServerInventoryCallbackListener *GameServerInventory_listener = nullptr;
} // namespace

void init_GameServerInventory_auto(lua_State *L) { if (GameServerInventory_listener != nullptr) return; GameServerInventory_listener = new GameServerInventoryCallbackListener(); }
void shutdown_GameServerInventory_auto(lua_State *L) {
	luaL_unref(L, LUA_REGISTRYINDEX, GameServerInventory_ref);
	GameServerInventory_ref = LUA_NOREF;
	delete GameServerInventory_listener; GameServerInventory_listener = nullptr;
}

void add_GameServerInventory_auto(lua_State *L) {
	lua_createtable(L, 0, 36);
	register_Inventory_auto(L, true);
	lua_pushvalue(L, -1);
	GameServerInventory_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "GameServerInventory");
}

} // namespace luasteam
