---@class Steam.Inventory
local Inventory = {}

---@param resultHandle integer
---@return integer
function Inventory.GetResultStatus(resultHandle) end

---@param resultHandle integer
---@param punOutItemsArraySize integer
---@return boolean
---@return integer -- Value of: punOutItemsArraySize
---@return table[] -- Value of: pOutItemsArray
---@return integer -- Value of: punOutItemsArraySize
function Inventory.GetResultItems(resultHandle, punOutItemsArraySize) end

---@param resultHandle integer
---@param unItemIndex integer
---@param pchPropertyName string
---@param punValueBufferSizeOut integer
---@return boolean
---@return integer -- Value of: punValueBufferSizeOut
---@return string -- Value of: pchValueBuffer
---@return integer -- Value of: punValueBufferSizeOut
function Inventory.GetResultItemProperty(resultHandle, unItemIndex, pchPropertyName, punValueBufferSizeOut) end

---@param resultHandle integer
---@return integer
function Inventory.GetResultTimestamp(resultHandle) end

---@param resultHandle integer
---@param steamIDExpected uint64
---@return boolean
function Inventory.CheckResultSteamID(resultHandle, steamIDExpected) end

---@param resultHandle integer
function Inventory.DestroyResult(resultHandle) end

---@return boolean
---@return integer -- Value of: pResultHandle
function Inventory.GetAllItems() end

---@param unCountInstanceIDs integer
---@param pInstanceIDs uint64[]
---@return boolean
---@return integer -- Value of: pResultHandle
function Inventory.GetItemsByID(unCountInstanceIDs, pInstanceIDs) end

---@param pBuffer string
---@param unBufferSize integer
---@param bRESERVED_MUST_BE_FALSE boolean
---@return boolean
---@return integer -- Value of: pOutResultHandle
function Inventory.DeserializeResult(pBuffer, unBufferSize, bRESERVED_MUST_BE_FALSE) end

---@param unArrayLength integer
---@param pArrayItemDefs integer[]
---@param punArrayQuantity integer[]
---@return boolean
---@return integer -- Value of: pResultHandle
function Inventory.GenerateItems(unArrayLength, pArrayItemDefs, punArrayQuantity) end

---@return boolean
---@return integer -- Value of: pResultHandle
function Inventory.GrantPromoItems() end

---@param itemDef integer
---@return boolean
---@return integer -- Value of: pResultHandle
function Inventory.AddPromoItem(itemDef) end

---@param unArrayLength integer
---@param pArrayItemDefs integer[]
---@return boolean
---@return integer -- Value of: pResultHandle
function Inventory.AddPromoItems(unArrayLength, pArrayItemDefs) end

---@param itemConsume uint64
---@param unQuantity integer
---@return boolean
---@return integer -- Value of: pResultHandle
function Inventory.ConsumeItem(itemConsume, unQuantity) end

---@param unArrayGenerateLength integer
---@param pArrayGenerate integer[]
---@param punArrayGenerateQuantity integer[]
---@param unArrayDestroyLength integer
---@param pArrayDestroy uint64[]
---@param punArrayDestroyQuantity integer[]
---@return boolean
---@return integer -- Value of: pResultHandle
function Inventory.ExchangeItems(unArrayGenerateLength, pArrayGenerate, punArrayGenerateQuantity, unArrayDestroyLength, pArrayDestroy, punArrayDestroyQuantity) end

---@param itemIdSource uint64
---@param unQuantity integer
---@param itemIdDest uint64
---@return boolean
---@return integer -- Value of: pResultHandle
function Inventory.TransferItemQuantity(itemIdSource, unQuantity, itemIdDest) end

function Inventory.SendItemDropHeartbeat() end

---@param dropListDefinition integer
---@return boolean
---@return integer -- Value of: pResultHandle
function Inventory.TriggerItemDrop(dropListDefinition) end

---@param steamIDTradePartner uint64
---@param nArrayGiveLength integer
---@param pArrayGive uint64[]
---@param pArrayGiveQuantity integer[]
---@param nArrayGetLength integer
---@param pArrayGet uint64[]
---@param pArrayGetQuantity integer[]
---@return boolean
---@return integer -- Value of: pResultHandle
function Inventory.TradeItems(steamIDTradePartner, nArrayGiveLength, pArrayGive, pArrayGiveQuantity, nArrayGetLength, pArrayGet, pArrayGetQuantity) end

---@return boolean
function Inventory.LoadItemDefinitions() end

---@param punItemDefIDsArraySize integer
---@return boolean
---@return integer -- Value of: punItemDefIDsArraySize
---@return integer[] -- Value of: pItemDefIDs
---@return integer -- Value of: punItemDefIDsArraySize
function Inventory.GetItemDefinitionIDs(punItemDefIDsArraySize) end

---@param iDefinition integer
---@param pchPropertyName string
---@param punValueBufferSizeOut integer
---@return boolean
---@return integer -- Value of: punValueBufferSizeOut
---@return string -- Value of: pchValueBuffer
---@return integer -- Value of: punValueBufferSizeOut
function Inventory.GetItemDefinitionProperty(iDefinition, pchPropertyName, punValueBufferSizeOut) end

---@param steamID uint64
---@param callback fun(data: SteamInventoryEligiblePromoItemDefIDs_t?, io_fail: boolean)?
---@return uint64
function Inventory.RequestEligiblePromoItemDefinitionsIDs(steamID, callback) end

---@param steamID uint64
---@param punItemDefIDsArraySize integer
---@return boolean
---@return integer -- Value of: punItemDefIDsArraySize
---@return integer[] -- Value of: pItemDefIDs
---@return integer -- Value of: punItemDefIDsArraySize
function Inventory.GetEligiblePromoItemDefinitionIDs(steamID, punItemDefIDsArraySize) end

---@param unArrayLength integer
---@param pArrayItemDefs integer[]
---@param punArrayQuantity integer[]
---@param callback fun(data: SteamInventoryStartPurchaseResult_t?, io_fail: boolean)?
---@return uint64
function Inventory.StartPurchase(unArrayLength, pArrayItemDefs, punArrayQuantity, callback) end

---@param callback fun(data: SteamInventoryRequestPricesResult_t?, io_fail: boolean)?
---@return uint64
function Inventory.RequestPrices(callback) end

---@return integer
function Inventory.GetNumItemsWithPrices() end

---@param iDefinition integer
---@return boolean
---@return uint64 -- Value of: pCurrentPrice
---@return uint64 -- Value of: pBasePrice
function Inventory.GetItemPrice(iDefinition) end

---@return uint64
function Inventory.StartUpdateProperties() end

---@param handle uint64
---@param nItemID uint64
---@param pchPropertyName string
---@return boolean
function Inventory.RemoveProperty(handle, nItemID, pchPropertyName) end

---@param handle uint64
---@param nItemID uint64
---@param pchPropertyName string
---@param pchPropertyValue string
---@return boolean
function Inventory.SetPropertyString(handle, nItemID, pchPropertyName, pchPropertyValue) end

---@param handle uint64
---@param nItemID uint64
---@param pchPropertyName string
---@param bValue boolean
---@return boolean
function Inventory.SetPropertyBool(handle, nItemID, pchPropertyName, bValue) end

---@param handle uint64
---@param nItemID uint64
---@param pchPropertyName string
---@param nValue uint64
---@return boolean
function Inventory.SetPropertyInt64(handle, nItemID, pchPropertyName, nValue) end

---@param handle uint64
---@param nItemID uint64
---@param pchPropertyName string
---@param flValue number
---@return boolean
function Inventory.SetPropertyFloat(handle, nItemID, pchPropertyName, flValue) end

---@param handle uint64
---@return boolean
---@return integer -- Value of: pResultHandle
function Inventory.SubmitUpdateProperties(handle) end

---@param pchItemToken string
---@return boolean
---@return integer -- Value of: pResultHandle
function Inventory.InspectItem(pchItemToken) end

Steam.Inventory = Inventory
