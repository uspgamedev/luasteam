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
		lua_pushstring(L, reinterpret_cast<const char*>(data->m_rgchCurrency));
		lua_setfield(L, -2, "m_rgchCurrency");
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
		lua_pushstring(L, reinterpret_cast<const char*>(data->m_rgchCurrency));
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
EXTERN int luasteam_Inventory_GetResultStatus(lua_State *L) {
	SteamInventoryResult_t resultHandle = static_cast<SteamInventoryResult_t>(luaL_checkint(L, 1));
	EResult __ret = SteamInventory()->GetResultStatus(resultHandle);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool GetResultItems(SteamInventoryResult_t resultHandle, SteamItemDetails_t * pOutItemsArray, uint32 * punOutItemsArraySize);
// In Lua:
// (bool, punOutItemsArraySize: int, pOutItemsArray: table[], punOutItemsArraySize: int) Inventory.GetResultItems(resultHandle: int, punOutItemsArraySize: int)
EXTERN int luasteam_Inventory_GetResultItems(lua_State *L) {
	SteamInventoryResult_t resultHandle = static_cast<SteamInventoryResult_t>(luaL_checkint(L, 1));
	uint32 punOutItemsArraySize = luaL_checkint(L, 2);
	std::vector<SteamItemDetails_t> pOutItemsArray(punOutItemsArraySize);
	bool __ret = SteamInventory()->GetResultItems(resultHandle, pOutItemsArray.data(), &punOutItemsArraySize);
	lua_pushboolean(L, __ret);
	lua_createtable(L, punOutItemsArraySize, 0);
	for(decltype(punOutItemsArraySize) i = 0; i < punOutItemsArraySize; i++) {
		push_SteamItemDetails_t(L, pOutItemsArray[i]);
		lua_rawseti(L, -2, i+1);
	}
	lua_pushinteger(L, punOutItemsArraySize);
	return 4;
}

// In C++:
// bool GetResultItemProperty(SteamInventoryResult_t resultHandle, uint32 unItemIndex, const char * pchPropertyName, char * pchValueBuffer, uint32 * punValueBufferSizeOut);
// In Lua:
// (bool, punValueBufferSizeOut: int, pchValueBuffer: str, punValueBufferSizeOut: int) Inventory.GetResultItemProperty(resultHandle: int, unItemIndex: int, pchPropertyName: str, punValueBufferSizeOut: int)
EXTERN int luasteam_Inventory_GetResultItemProperty(lua_State *L) {
	SteamInventoryResult_t resultHandle = static_cast<SteamInventoryResult_t>(luaL_checkint(L, 1));
	uint32 unItemIndex = static_cast<uint32>(luaL_checkint(L, 2));
	const char *pchPropertyName = luaL_checkstring(L, 3);
	uint32 punValueBufferSizeOut = luaL_checkint(L, 4);
	std::vector<char> pchValueBuffer(punValueBufferSizeOut);
	bool __ret = SteamInventory()->GetResultItemProperty(resultHandle, unItemIndex, pchPropertyName, pchValueBuffer.data(), &punValueBufferSizeOut);
	lua_pushboolean(L, __ret);
	lua_pushstring(L, reinterpret_cast<const char*>(pchValueBuffer.data()));
	lua_pushinteger(L, punValueBufferSizeOut);
	return 4;
}

// In C++:
// uint32 GetResultTimestamp(SteamInventoryResult_t resultHandle);
// In Lua:
// int Inventory.GetResultTimestamp(resultHandle: int)
EXTERN int luasteam_Inventory_GetResultTimestamp(lua_State *L) {
	SteamInventoryResult_t resultHandle = static_cast<SteamInventoryResult_t>(luaL_checkint(L, 1));
	uint32 __ret = SteamInventory()->GetResultTimestamp(resultHandle);
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool CheckResultSteamID(SteamInventoryResult_t resultHandle, CSteamID steamIDExpected);
// In Lua:
// bool Inventory.CheckResultSteamID(resultHandle: int, steamIDExpected: uint64)
EXTERN int luasteam_Inventory_CheckResultSteamID(lua_State *L) {
	SteamInventoryResult_t resultHandle = static_cast<SteamInventoryResult_t>(luaL_checkint(L, 1));
	CSteamID steamIDExpected(luasteam::checkuint64(L, 2));
	bool __ret = SteamInventory()->CheckResultSteamID(resultHandle, steamIDExpected);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// void DestroyResult(SteamInventoryResult_t resultHandle);
// In Lua:
// Inventory.DestroyResult(resultHandle: int)
EXTERN int luasteam_Inventory_DestroyResult(lua_State *L) {
	SteamInventoryResult_t resultHandle = static_cast<SteamInventoryResult_t>(luaL_checkint(L, 1));
	SteamInventory()->DestroyResult(resultHandle);
	return 0;
}

// In C++:
// bool GetAllItems(SteamInventoryResult_t * pResultHandle);
// In Lua:
// (bool, pResultHandle: int) Inventory.GetAllItems()
EXTERN int luasteam_Inventory_GetAllItems(lua_State *L) {
	SteamInventoryResult_t pResultHandle;
	bool __ret = SteamInventory()->GetAllItems(&pResultHandle);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pResultHandle);
	return 2;
}

// In C++:
// bool GetItemsByID(SteamInventoryResult_t * pResultHandle, const SteamItemInstanceID_t * pInstanceIDs, uint32 unCountInstanceIDs);
// In Lua:
// (bool, pResultHandle: int) Inventory.GetItemsByID(unCountInstanceIDs: int, pInstanceIDs: uint64[])
EXTERN int luasteam_Inventory_GetItemsByID(lua_State *L) {
	SteamInventoryResult_t pResultHandle;
	uint32 unCountInstanceIDs = luaL_checkint(L, 2);
	luaL_checktype(L, 1, LUA_TTABLE);
	std::vector<SteamItemInstanceID_t> pInstanceIDs(unCountInstanceIDs);
	for(decltype(unCountInstanceIDs) i = 0; i < unCountInstanceIDs; i++) {
		lua_rawgeti(L, -1, i+1);
		pInstanceIDs[i] = luasteam::checkuint64(L, -1);
		lua_pop(L, 1);
	}
	bool __ret = SteamInventory()->GetItemsByID(&pResultHandle, pInstanceIDs.data(), unCountInstanceIDs);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pResultHandle);
	return 2;
}

// In C++:
// bool DeserializeResult(SteamInventoryResult_t * pOutResultHandle, const void * pBuffer, uint32 unBufferSize, bool bRESERVED_MUST_BE_FALSE);
// In Lua:
// (bool, pOutResultHandle: int) Inventory.DeserializeResult(pBuffer: str, unBufferSize: int, bRESERVED_MUST_BE_FALSE: bool)
EXTERN int luasteam_Inventory_DeserializeResult(lua_State *L) {
	SteamInventoryResult_t pOutResultHandle;
	const char *pBuffer = luaL_checkstring(L, 1);
	uint32 unBufferSize = static_cast<uint32>(luaL_checkint(L, 2));
	bool bRESERVED_MUST_BE_FALSE = lua_toboolean(L, 3);
	bool __ret = SteamInventory()->DeserializeResult(&pOutResultHandle, pBuffer, unBufferSize, bRESERVED_MUST_BE_FALSE);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pOutResultHandle);
	return 2;
}

// In C++:
// bool GenerateItems(SteamInventoryResult_t * pResultHandle, const SteamItemDef_t * pArrayItemDefs, const uint32 * punArrayQuantity, uint32 unArrayLength);
// In Lua:
// (bool, pResultHandle: int) Inventory.GenerateItems(unArrayLength: int, pArrayItemDefs: int[], punArrayQuantity: int[])
EXTERN int luasteam_Inventory_GenerateItems(lua_State *L) {
	SteamInventoryResult_t pResultHandle;
	uint32 unArrayLength = luaL_checkint(L, 2);
	luaL_checktype(L, 1, LUA_TTABLE);
	std::vector<SteamItemDef_t> pArrayItemDefs(unArrayLength);
	for(decltype(unArrayLength) i = 0; i < unArrayLength; i++) {
		lua_rawgeti(L, -1, i+1);
		pArrayItemDefs[i] = static_cast<SteamItemDef_t>(luaL_checkint(L, -1));
		lua_pop(L, 1);
	}
	luaL_checktype(L, 3, LUA_TTABLE);
	std::vector<uint32> punArrayQuantity(unArrayLength);
	for(decltype(unArrayLength) i = 0; i < unArrayLength; i++) {
		lua_rawgeti(L, -1, i+1);
		punArrayQuantity[i] = static_cast<uint32>(luaL_checkint(L, -1));
		lua_pop(L, 1);
	}
	bool __ret = SteamInventory()->GenerateItems(&pResultHandle, pArrayItemDefs.data(), punArrayQuantity.data(), unArrayLength);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pResultHandle);
	return 2;
}

// In C++:
// bool GrantPromoItems(SteamInventoryResult_t * pResultHandle);
// In Lua:
// (bool, pResultHandle: int) Inventory.GrantPromoItems()
EXTERN int luasteam_Inventory_GrantPromoItems(lua_State *L) {
	SteamInventoryResult_t pResultHandle;
	bool __ret = SteamInventory()->GrantPromoItems(&pResultHandle);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pResultHandle);
	return 2;
}

// In C++:
// bool AddPromoItem(SteamInventoryResult_t * pResultHandle, SteamItemDef_t itemDef);
// In Lua:
// (bool, pResultHandle: int) Inventory.AddPromoItem(itemDef: int)
EXTERN int luasteam_Inventory_AddPromoItem(lua_State *L) {
	SteamInventoryResult_t pResultHandle;
	SteamItemDef_t itemDef = static_cast<SteamItemDef_t>(luaL_checkint(L, 1));
	bool __ret = SteamInventory()->AddPromoItem(&pResultHandle, itemDef);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pResultHandle);
	return 2;
}

// In C++:
// bool AddPromoItems(SteamInventoryResult_t * pResultHandle, const SteamItemDef_t * pArrayItemDefs, uint32 unArrayLength);
// In Lua:
// (bool, pResultHandle: int) Inventory.AddPromoItems(unArrayLength: int, pArrayItemDefs: int[])
EXTERN int luasteam_Inventory_AddPromoItems(lua_State *L) {
	SteamInventoryResult_t pResultHandle;
	uint32 unArrayLength = luaL_checkint(L, 2);
	luaL_checktype(L, 1, LUA_TTABLE);
	std::vector<SteamItemDef_t> pArrayItemDefs(unArrayLength);
	for(decltype(unArrayLength) i = 0; i < unArrayLength; i++) {
		lua_rawgeti(L, -1, i+1);
		pArrayItemDefs[i] = static_cast<SteamItemDef_t>(luaL_checkint(L, -1));
		lua_pop(L, 1);
	}
	bool __ret = SteamInventory()->AddPromoItems(&pResultHandle, pArrayItemDefs.data(), unArrayLength);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pResultHandle);
	return 2;
}

// In C++:
// bool ConsumeItem(SteamInventoryResult_t * pResultHandle, SteamItemInstanceID_t itemConsume, uint32 unQuantity);
// In Lua:
// (bool, pResultHandle: int) Inventory.ConsumeItem(itemConsume: uint64, unQuantity: int)
EXTERN int luasteam_Inventory_ConsumeItem(lua_State *L) {
	SteamInventoryResult_t pResultHandle;
	SteamItemInstanceID_t itemConsume(luasteam::checkuint64(L, 1));
	uint32 unQuantity = static_cast<uint32>(luaL_checkint(L, 2));
	bool __ret = SteamInventory()->ConsumeItem(&pResultHandle, itemConsume, unQuantity);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pResultHandle);
	return 2;
}

// In C++:
// bool ExchangeItems(SteamInventoryResult_t * pResultHandle, const SteamItemDef_t * pArrayGenerate, const uint32 * punArrayGenerateQuantity, uint32 unArrayGenerateLength, const SteamItemInstanceID_t * pArrayDestroy, const uint32 * punArrayDestroyQuantity, uint32 unArrayDestroyLength);
// In Lua:
// (bool, pResultHandle: int) Inventory.ExchangeItems(unArrayGenerateLength: int, pArrayGenerate: int[], punArrayGenerateQuantity: int[], unArrayDestroyLength: int, pArrayDestroy: uint64[], punArrayDestroyQuantity: int[])
EXTERN int luasteam_Inventory_ExchangeItems(lua_State *L) {
	SteamInventoryResult_t pResultHandle;
	uint32 unArrayGenerateLength = luaL_checkint(L, 2);
	luaL_checktype(L, 1, LUA_TTABLE);
	std::vector<SteamItemDef_t> pArrayGenerate(unArrayGenerateLength);
	for(decltype(unArrayGenerateLength) i = 0; i < unArrayGenerateLength; i++) {
		lua_rawgeti(L, -1, i+1);
		pArrayGenerate[i] = static_cast<SteamItemDef_t>(luaL_checkint(L, -1));
		lua_pop(L, 1);
	}
	luaL_checktype(L, 3, LUA_TTABLE);
	std::vector<uint32> punArrayGenerateQuantity(unArrayGenerateLength);
	for(decltype(unArrayGenerateLength) i = 0; i < unArrayGenerateLength; i++) {
		lua_rawgeti(L, -1, i+1);
		punArrayGenerateQuantity[i] = static_cast<uint32>(luaL_checkint(L, -1));
		lua_pop(L, 1);
	}
	uint32 unArrayDestroyLength = luaL_checkint(L, 4);
	luaL_checktype(L, 3, LUA_TTABLE);
	std::vector<SteamItemInstanceID_t> pArrayDestroy(unArrayDestroyLength);
	for(decltype(unArrayDestroyLength) i = 0; i < unArrayDestroyLength; i++) {
		lua_rawgeti(L, -1, i+1);
		pArrayDestroy[i] = luasteam::checkuint64(L, -1);
		lua_pop(L, 1);
	}
	luaL_checktype(L, 5, LUA_TTABLE);
	std::vector<uint32> punArrayDestroyQuantity(unArrayDestroyLength);
	for(decltype(unArrayDestroyLength) i = 0; i < unArrayDestroyLength; i++) {
		lua_rawgeti(L, -1, i+1);
		punArrayDestroyQuantity[i] = static_cast<uint32>(luaL_checkint(L, -1));
		lua_pop(L, 1);
	}
	bool __ret = SteamInventory()->ExchangeItems(&pResultHandle, pArrayGenerate.data(), punArrayGenerateQuantity.data(), unArrayGenerateLength, pArrayDestroy.data(), punArrayDestroyQuantity.data(), unArrayDestroyLength);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pResultHandle);
	return 2;
}

// In C++:
// bool TransferItemQuantity(SteamInventoryResult_t * pResultHandle, SteamItemInstanceID_t itemIdSource, uint32 unQuantity, SteamItemInstanceID_t itemIdDest);
// In Lua:
// (bool, pResultHandle: int) Inventory.TransferItemQuantity(itemIdSource: uint64, unQuantity: int, itemIdDest: uint64)
EXTERN int luasteam_Inventory_TransferItemQuantity(lua_State *L) {
	SteamInventoryResult_t pResultHandle;
	SteamItemInstanceID_t itemIdSource(luasteam::checkuint64(L, 1));
	uint32 unQuantity = static_cast<uint32>(luaL_checkint(L, 2));
	SteamItemInstanceID_t itemIdDest(luasteam::checkuint64(L, 3));
	bool __ret = SteamInventory()->TransferItemQuantity(&pResultHandle, itemIdSource, unQuantity, itemIdDest);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pResultHandle);
	return 2;
}

// In C++:
// void SendItemDropHeartbeat();
// In Lua:
// Inventory.SendItemDropHeartbeat()
EXTERN int luasteam_Inventory_SendItemDropHeartbeat(lua_State *L) {
	SteamInventory()->SendItemDropHeartbeat();
	return 0;
}

// In C++:
// bool TriggerItemDrop(SteamInventoryResult_t * pResultHandle, SteamItemDef_t dropListDefinition);
// In Lua:
// (bool, pResultHandle: int) Inventory.TriggerItemDrop(dropListDefinition: int)
EXTERN int luasteam_Inventory_TriggerItemDrop(lua_State *L) {
	SteamInventoryResult_t pResultHandle;
	SteamItemDef_t dropListDefinition = static_cast<SteamItemDef_t>(luaL_checkint(L, 1));
	bool __ret = SteamInventory()->TriggerItemDrop(&pResultHandle, dropListDefinition);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pResultHandle);
	return 2;
}

// In C++:
// bool TradeItems(SteamInventoryResult_t * pResultHandle, CSteamID steamIDTradePartner, const SteamItemInstanceID_t * pArrayGive, const uint32 * pArrayGiveQuantity, uint32 nArrayGiveLength, const SteamItemInstanceID_t * pArrayGet, const uint32 * pArrayGetQuantity, uint32 nArrayGetLength);
// In Lua:
// (bool, pResultHandle: int) Inventory.TradeItems(steamIDTradePartner: uint64, nArrayGiveLength: int, pArrayGive: uint64[], pArrayGiveQuantity: int[], nArrayGetLength: int, pArrayGet: uint64[], pArrayGetQuantity: int[])
EXTERN int luasteam_Inventory_TradeItems(lua_State *L) {
	SteamInventoryResult_t pResultHandle;
	CSteamID steamIDTradePartner(luasteam::checkuint64(L, 1));
	uint32 nArrayGiveLength = luaL_checkint(L, 3);
	luaL_checktype(L, 2, LUA_TTABLE);
	std::vector<SteamItemInstanceID_t> pArrayGive(nArrayGiveLength);
	for(decltype(nArrayGiveLength) i = 0; i < nArrayGiveLength; i++) {
		lua_rawgeti(L, -1, i+1);
		pArrayGive[i] = luasteam::checkuint64(L, -1);
		lua_pop(L, 1);
	}
	luaL_checktype(L, 4, LUA_TTABLE);
	std::vector<uint32> pArrayGiveQuantity(nArrayGiveLength);
	for(decltype(nArrayGiveLength) i = 0; i < nArrayGiveLength; i++) {
		lua_rawgeti(L, -1, i+1);
		pArrayGiveQuantity[i] = static_cast<uint32>(luaL_checkint(L, -1));
		lua_pop(L, 1);
	}
	uint32 nArrayGetLength = luaL_checkint(L, 5);
	luaL_checktype(L, 4, LUA_TTABLE);
	std::vector<SteamItemInstanceID_t> pArrayGet(nArrayGetLength);
	for(decltype(nArrayGetLength) i = 0; i < nArrayGetLength; i++) {
		lua_rawgeti(L, -1, i+1);
		pArrayGet[i] = luasteam::checkuint64(L, -1);
		lua_pop(L, 1);
	}
	luaL_checktype(L, 6, LUA_TTABLE);
	std::vector<uint32> pArrayGetQuantity(nArrayGetLength);
	for(decltype(nArrayGetLength) i = 0; i < nArrayGetLength; i++) {
		lua_rawgeti(L, -1, i+1);
		pArrayGetQuantity[i] = static_cast<uint32>(luaL_checkint(L, -1));
		lua_pop(L, 1);
	}
	bool __ret = SteamInventory()->TradeItems(&pResultHandle, steamIDTradePartner, pArrayGive.data(), pArrayGiveQuantity.data(), nArrayGiveLength, pArrayGet.data(), pArrayGetQuantity.data(), nArrayGetLength);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pResultHandle);
	return 2;
}

// In C++:
// bool LoadItemDefinitions();
// In Lua:
// bool Inventory.LoadItemDefinitions()
EXTERN int luasteam_Inventory_LoadItemDefinitions(lua_State *L) {
	bool __ret = SteamInventory()->LoadItemDefinitions();
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool GetItemDefinitionIDs(SteamItemDef_t * pItemDefIDs, uint32 * punItemDefIDsArraySize);
// In Lua:
// (bool, punItemDefIDsArraySize: int, pItemDefIDs: int[], punItemDefIDsArraySize: int) Inventory.GetItemDefinitionIDs(punItemDefIDsArraySize: int)
EXTERN int luasteam_Inventory_GetItemDefinitionIDs(lua_State *L) {
	uint32 punItemDefIDsArraySize = luaL_checkint(L, 1);
	std::vector<SteamItemDef_t> pItemDefIDs(punItemDefIDsArraySize);
	bool __ret = SteamInventory()->GetItemDefinitionIDs(pItemDefIDs.data(), &punItemDefIDsArraySize);
	lua_pushboolean(L, __ret);
	lua_createtable(L, punItemDefIDsArraySize, 0);
	for(decltype(punItemDefIDsArraySize) i = 0; i < punItemDefIDsArraySize; i++) {
		lua_pushinteger(L, pItemDefIDs[i]);
		lua_rawseti(L, -2, i+1);
	}
	lua_pushinteger(L, punItemDefIDsArraySize);
	return 4;
}

// In C++:
// bool GetItemDefinitionProperty(SteamItemDef_t iDefinition, const char * pchPropertyName, char * pchValueBuffer, uint32 * punValueBufferSizeOut);
// In Lua:
// (bool, punValueBufferSizeOut: int, pchValueBuffer: str, punValueBufferSizeOut: int) Inventory.GetItemDefinitionProperty(iDefinition: int, pchPropertyName: str, punValueBufferSizeOut: int)
EXTERN int luasteam_Inventory_GetItemDefinitionProperty(lua_State *L) {
	SteamItemDef_t iDefinition = static_cast<SteamItemDef_t>(luaL_checkint(L, 1));
	const char *pchPropertyName = luaL_checkstring(L, 2);
	uint32 punValueBufferSizeOut = luaL_checkint(L, 3);
	std::vector<char> pchValueBuffer(punValueBufferSizeOut);
	bool __ret = SteamInventory()->GetItemDefinitionProperty(iDefinition, pchPropertyName, pchValueBuffer.data(), &punValueBufferSizeOut);
	lua_pushboolean(L, __ret);
	lua_pushstring(L, reinterpret_cast<const char*>(pchValueBuffer.data()));
	lua_pushinteger(L, punValueBufferSizeOut);
	return 4;
}

// In C++:
// SteamAPICall_t RequestEligiblePromoItemDefinitionsIDs(CSteamID steamID);
// In Lua:
// uint64 Inventory.RequestEligiblePromoItemDefinitionsIDs(steamID: uint64, callback: function)
EXTERN int luasteam_Inventory_RequestEligiblePromoItemDefinitionsIDs(lua_State *L) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	CSteamID steamID(luasteam::checkuint64(L, 1));
	SteamAPICall_t __ret = SteamInventory()->RequestEligiblePromoItemDefinitionsIDs(steamID);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<SteamInventoryEligiblePromoItemDefIDs_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<SteamInventoryEligiblePromoItemDefIDs_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// bool GetEligiblePromoItemDefinitionIDs(CSteamID steamID, SteamItemDef_t * pItemDefIDs, uint32 * punItemDefIDsArraySize);
// In Lua:
// (bool, punItemDefIDsArraySize: int, pItemDefIDs: int[], punItemDefIDsArraySize: int) Inventory.GetEligiblePromoItemDefinitionIDs(steamID: uint64, punItemDefIDsArraySize: int)
EXTERN int luasteam_Inventory_GetEligiblePromoItemDefinitionIDs(lua_State *L) {
	CSteamID steamID(luasteam::checkuint64(L, 1));
	uint32 punItemDefIDsArraySize = luaL_checkint(L, 2);
	std::vector<SteamItemDef_t> pItemDefIDs(punItemDefIDsArraySize);
	bool __ret = SteamInventory()->GetEligiblePromoItemDefinitionIDs(steamID, pItemDefIDs.data(), &punItemDefIDsArraySize);
	lua_pushboolean(L, __ret);
	lua_createtable(L, punItemDefIDsArraySize, 0);
	for(decltype(punItemDefIDsArraySize) i = 0; i < punItemDefIDsArraySize; i++) {
		lua_pushinteger(L, pItemDefIDs[i]);
		lua_rawseti(L, -2, i+1);
	}
	lua_pushinteger(L, punItemDefIDsArraySize);
	return 4;
}

// In C++:
// SteamAPICall_t StartPurchase(const SteamItemDef_t * pArrayItemDefs, const uint32 * punArrayQuantity, uint32 unArrayLength);
// In Lua:
// uint64 Inventory.StartPurchase(unArrayLength: int, pArrayItemDefs: int[], punArrayQuantity: int[], callback: function)
EXTERN int luasteam_Inventory_StartPurchase(lua_State *L) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	uint32 unArrayLength = luaL_checkint(L, 2);
	luaL_checktype(L, 1, LUA_TTABLE);
	std::vector<SteamItemDef_t> pArrayItemDefs(unArrayLength);
	for(decltype(unArrayLength) i = 0; i < unArrayLength; i++) {
		lua_rawgeti(L, -1, i+1);
		pArrayItemDefs[i] = static_cast<SteamItemDef_t>(luaL_checkint(L, -1));
		lua_pop(L, 1);
	}
	luaL_checktype(L, 3, LUA_TTABLE);
	std::vector<uint32> punArrayQuantity(unArrayLength);
	for(decltype(unArrayLength) i = 0; i < unArrayLength; i++) {
		lua_rawgeti(L, -1, i+1);
		punArrayQuantity[i] = static_cast<uint32>(luaL_checkint(L, -1));
		lua_pop(L, 1);
	}
	SteamAPICall_t __ret = SteamInventory()->StartPurchase(pArrayItemDefs.data(), punArrayQuantity.data(), unArrayLength);
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<SteamInventoryStartPurchaseResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<SteamInventoryStartPurchaseResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// SteamAPICall_t RequestPrices();
// In Lua:
// uint64 Inventory.RequestPrices(callback: function)
EXTERN int luasteam_Inventory_RequestPrices(lua_State *L) {
	int callback_ref = LUA_NOREF;
	if (lua_isfunction(L, lua_gettop(L))) {
		lua_pushvalue(L, lua_gettop(L));
		callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	}
	SteamAPICall_t __ret = SteamInventory()->RequestPrices();
	if (callback_ref != LUA_NOREF) {
		auto *listener = new luasteam::CallResultListener<SteamInventoryRequestPricesResult_t>();
		listener->callback_ref = callback_ref;
		listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<SteamInventoryRequestPricesResult_t>::Result);
	}
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// uint32 GetNumItemsWithPrices();
// In Lua:
// int Inventory.GetNumItemsWithPrices()
EXTERN int luasteam_Inventory_GetNumItemsWithPrices(lua_State *L) {
	uint32 __ret = SteamInventory()->GetNumItemsWithPrices();
	lua_pushinteger(L, __ret);
	return 1;
}

// In C++:
// bool GetItemPrice(SteamItemDef_t iDefinition, uint64 * pCurrentPrice, uint64 * pBasePrice);
// In Lua:
// (bool, pCurrentPrice: uint64, pBasePrice: uint64) Inventory.GetItemPrice(iDefinition: int)
EXTERN int luasteam_Inventory_GetItemPrice(lua_State *L) {
	SteamItemDef_t iDefinition = static_cast<SteamItemDef_t>(luaL_checkint(L, 1));
	uint64 pCurrentPrice;
	uint64 pBasePrice;
	bool __ret = SteamInventory()->GetItemPrice(iDefinition, &pCurrentPrice, &pBasePrice);
	lua_pushboolean(L, __ret);
	luasteam::pushuint64(L, pCurrentPrice);
	luasteam::pushuint64(L, pBasePrice);
	return 3;
}

// In C++:
// SteamInventoryUpdateHandle_t StartUpdateProperties();
// In Lua:
// uint64 Inventory.StartUpdateProperties()
EXTERN int luasteam_Inventory_StartUpdateProperties(lua_State *L) {
	SteamInventoryUpdateHandle_t __ret = SteamInventory()->StartUpdateProperties();
	luasteam::pushuint64(L, __ret);
	return 1;
}

// In C++:
// bool RemoveProperty(SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, const char * pchPropertyName);
// In Lua:
// bool Inventory.RemoveProperty(handle: uint64, nItemID: uint64, pchPropertyName: str)
EXTERN int luasteam_Inventory_RemoveProperty(lua_State *L) {
	SteamInventoryUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	SteamItemInstanceID_t nItemID(luasteam::checkuint64(L, 2));
	const char *pchPropertyName = luaL_checkstring(L, 3);
	bool __ret = SteamInventory()->RemoveProperty(handle, nItemID, pchPropertyName);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetProperty(SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, const char * pchPropertyName, const char * pchPropertyValue);
// In Lua:
// bool Inventory.SetPropertyString(handle: uint64, nItemID: uint64, pchPropertyName: str, pchPropertyValue: str)
EXTERN int luasteam_Inventory_SetPropertyString(lua_State *L) {
	SteamInventoryUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	SteamItemInstanceID_t nItemID(luasteam::checkuint64(L, 2));
	const char *pchPropertyName = luaL_checkstring(L, 3);
	const char *pchPropertyValue = luaL_checkstring(L, 4);
	bool __ret = SteamInventory()->SetProperty(handle, nItemID, pchPropertyName, pchPropertyValue);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetProperty(SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, const char * pchPropertyName, bool bValue);
// In Lua:
// bool Inventory.SetPropertyBool(handle: uint64, nItemID: uint64, pchPropertyName: str, bValue: bool)
EXTERN int luasteam_Inventory_SetPropertyBool(lua_State *L) {
	SteamInventoryUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	SteamItemInstanceID_t nItemID(luasteam::checkuint64(L, 2));
	const char *pchPropertyName = luaL_checkstring(L, 3);
	bool bValue = lua_toboolean(L, 4);
	bool __ret = SteamInventory()->SetProperty(handle, nItemID, pchPropertyName, bValue);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetProperty(SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, const char * pchPropertyName, int64 nValue);
// In Lua:
// bool Inventory.SetPropertyInt64(handle: uint64, nItemID: uint64, pchPropertyName: str, nValue: uint64)
EXTERN int luasteam_Inventory_SetPropertyInt64(lua_State *L) {
	SteamInventoryUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	SteamItemInstanceID_t nItemID(luasteam::checkuint64(L, 2));
	const char *pchPropertyName = luaL_checkstring(L, 3);
	int64 nValue(luasteam::checkuint64(L, 4));
	bool __ret = SteamInventory()->SetProperty(handle, nItemID, pchPropertyName, nValue);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SetProperty(SteamInventoryUpdateHandle_t handle, SteamItemInstanceID_t nItemID, const char * pchPropertyName, float flValue);
// In Lua:
// bool Inventory.SetPropertyFloat(handle: uint64, nItemID: uint64, pchPropertyName: str, flValue: float)
EXTERN int luasteam_Inventory_SetPropertyFloat(lua_State *L) {
	SteamInventoryUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	SteamItemInstanceID_t nItemID(luasteam::checkuint64(L, 2));
	const char *pchPropertyName = luaL_checkstring(L, 3);
	float flValue = luaL_checknumber(L, 4);
	bool __ret = SteamInventory()->SetProperty(handle, nItemID, pchPropertyName, flValue);
	lua_pushboolean(L, __ret);
	return 1;
}

// In C++:
// bool SubmitUpdateProperties(SteamInventoryUpdateHandle_t handle, SteamInventoryResult_t * pResultHandle);
// In Lua:
// (bool, pResultHandle: int) Inventory.SubmitUpdateProperties(handle: uint64)
EXTERN int luasteam_Inventory_SubmitUpdateProperties(lua_State *L) {
	SteamInventoryUpdateHandle_t handle(luasteam::checkuint64(L, 1));
	SteamInventoryResult_t pResultHandle;
	bool __ret = SteamInventory()->SubmitUpdateProperties(handle, &pResultHandle);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pResultHandle);
	return 2;
}

// In C++:
// bool InspectItem(SteamInventoryResult_t * pResultHandle, const char * pchItemToken);
// In Lua:
// (bool, pResultHandle: int) Inventory.InspectItem(pchItemToken: str)
EXTERN int luasteam_Inventory_InspectItem(lua_State *L) {
	SteamInventoryResult_t pResultHandle;
	const char *pchItemToken = luaL_checkstring(L, 1);
	bool __ret = SteamInventory()->InspectItem(&pResultHandle, pchItemToken);
	lua_pushboolean(L, __ret);
	lua_pushinteger(L, pResultHandle);
	return 2;
}

void register_Inventory_auto(lua_State *L) {
	add_func(L, "GetResultStatus", luasteam_Inventory_GetResultStatus);
	add_func(L, "GetResultItems", luasteam_Inventory_GetResultItems);
	add_func(L, "GetResultItemProperty", luasteam_Inventory_GetResultItemProperty);
	add_func(L, "GetResultTimestamp", luasteam_Inventory_GetResultTimestamp);
	add_func(L, "CheckResultSteamID", luasteam_Inventory_CheckResultSteamID);
	add_func(L, "DestroyResult", luasteam_Inventory_DestroyResult);
	add_func(L, "GetAllItems", luasteam_Inventory_GetAllItems);
	add_func(L, "GetItemsByID", luasteam_Inventory_GetItemsByID);
	add_func(L, "DeserializeResult", luasteam_Inventory_DeserializeResult);
	add_func(L, "GenerateItems", luasteam_Inventory_GenerateItems);
	add_func(L, "GrantPromoItems", luasteam_Inventory_GrantPromoItems);
	add_func(L, "AddPromoItem", luasteam_Inventory_AddPromoItem);
	add_func(L, "AddPromoItems", luasteam_Inventory_AddPromoItems);
	add_func(L, "ConsumeItem", luasteam_Inventory_ConsumeItem);
	add_func(L, "ExchangeItems", luasteam_Inventory_ExchangeItems);
	add_func(L, "TransferItemQuantity", luasteam_Inventory_TransferItemQuantity);
	add_func(L, "SendItemDropHeartbeat", luasteam_Inventory_SendItemDropHeartbeat);
	add_func(L, "TriggerItemDrop", luasteam_Inventory_TriggerItemDrop);
	add_func(L, "TradeItems", luasteam_Inventory_TradeItems);
	add_func(L, "LoadItemDefinitions", luasteam_Inventory_LoadItemDefinitions);
	add_func(L, "GetItemDefinitionIDs", luasteam_Inventory_GetItemDefinitionIDs);
	add_func(L, "GetItemDefinitionProperty", luasteam_Inventory_GetItemDefinitionProperty);
	add_func(L, "RequestEligiblePromoItemDefinitionsIDs", luasteam_Inventory_RequestEligiblePromoItemDefinitionsIDs);
	add_func(L, "GetEligiblePromoItemDefinitionIDs", luasteam_Inventory_GetEligiblePromoItemDefinitionIDs);
	add_func(L, "StartPurchase", luasteam_Inventory_StartPurchase);
	add_func(L, "RequestPrices", luasteam_Inventory_RequestPrices);
	add_func(L, "GetNumItemsWithPrices", luasteam_Inventory_GetNumItemsWithPrices);
	add_func(L, "GetItemPrice", luasteam_Inventory_GetItemPrice);
	add_func(L, "StartUpdateProperties", luasteam_Inventory_StartUpdateProperties);
	add_func(L, "RemoveProperty", luasteam_Inventory_RemoveProperty);
	add_func(L, "SetPropertyString", luasteam_Inventory_SetPropertyString);
	add_func(L, "SetPropertyBool", luasteam_Inventory_SetPropertyBool);
	add_func(L, "SetPropertyInt64", luasteam_Inventory_SetPropertyInt64);
	add_func(L, "SetPropertyFloat", luasteam_Inventory_SetPropertyFloat);
	add_func(L, "SubmitUpdateProperties", luasteam_Inventory_SubmitUpdateProperties);
	add_func(L, "InspectItem", luasteam_Inventory_InspectItem);
}

void add_Inventory_auto(lua_State *L) {
	lua_createtable(L, 0, 36);
	register_Inventory_auto(L);
	lua_pushvalue(L, -1);
	Inventory_ref = luaL_ref(L, LUA_REGISTRYINDEX);
	lua_setfield(L, -2, "Inventory");
}

} // namespace luasteam
