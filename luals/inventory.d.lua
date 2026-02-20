---@class Steam.Inventory
local Inventory = {}

---@param resultHandle integer
---@return integer
function Inventory.GetResultStatus(resultHandle) end

---@param resultHandle integer
---@return boolean
---@return table
---@return integer
function Inventory.GetResultItems(resultHandle) end

---@param resultHandle integer
---@param unItemIndex integer
---@param pchPropertyName string
---@param pchValueBuffer string
---@return boolean
---@return integer
function Inventory.GetResultItemProperty(resultHandle, unItemIndex, pchPropertyName, pchValueBuffer) end

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
---@return integer
function Inventory.GetAllItems() end

---@param pInstanceIDs table
---@param unCountInstanceIDs integer
---@return boolean
---@return integer
function Inventory.GetItemsByID(pInstanceIDs, unCountInstanceIDs) end

---@param pBuffer table
---@param unBufferSize integer
---@param bRESERVED_MUST_BE_FALSE boolean
---@return boolean
---@return integer
function Inventory.DeserializeResult(pBuffer, unBufferSize, bRESERVED_MUST_BE_FALSE) end

---@param pArrayItemDefs table
---@param punArrayQuantity table
---@param unArrayLength integer
---@return boolean
---@return integer
function Inventory.GenerateItems(pArrayItemDefs, punArrayQuantity, unArrayLength) end

---@return boolean
---@return integer
function Inventory.GrantPromoItems() end

---@param itemDef integer
---@return boolean
---@return integer
function Inventory.AddPromoItem(itemDef) end

---@param pArrayItemDefs table
---@param unArrayLength integer
---@return boolean
---@return integer
function Inventory.AddPromoItems(pArrayItemDefs, unArrayLength) end

---@param itemConsume table
---@param unQuantity integer
---@return boolean
---@return integer
function Inventory.ConsumeItem(itemConsume, unQuantity) end

---@param pArrayGenerate table
---@param punArrayGenerateQuantity table
---@param unArrayGenerateLength integer
---@param pArrayDestroy table
---@param punArrayDestroyQuantity table
---@param unArrayDestroyLength integer
---@return boolean
---@return integer
function Inventory.ExchangeItems(pArrayGenerate, punArrayGenerateQuantity, unArrayGenerateLength, pArrayDestroy, punArrayDestroyQuantity, unArrayDestroyLength) end

---@param itemIdSource table
---@param unQuantity integer
---@param itemIdDest table
---@return boolean
---@return integer
function Inventory.TransferItemQuantity(itemIdSource, unQuantity, itemIdDest) end

function Inventory.SendItemDropHeartbeat() end

---@param dropListDefinition integer
---@return boolean
---@return integer
function Inventory.TriggerItemDrop(dropListDefinition) end

---@param steamIDTradePartner uint64
---@param pArrayGive table
---@param pArrayGiveQuantity table
---@param nArrayGiveLength integer
---@param pArrayGet table
---@param pArrayGetQuantity table
---@param nArrayGetLength integer
---@return boolean
---@return integer
function Inventory.TradeItems(steamIDTradePartner, pArrayGive, pArrayGiveQuantity, nArrayGiveLength, pArrayGet, pArrayGetQuantity, nArrayGetLength) end

---@return boolean
function Inventory.LoadItemDefinitions() end

---@return boolean
---@return integer
---@return integer
function Inventory.GetItemDefinitionIDs() end

---@param iDefinition integer
---@param pchPropertyName string
---@param pchValueBuffer string
---@return boolean
---@return integer
function Inventory.GetItemDefinitionProperty(iDefinition, pchPropertyName, pchValueBuffer) end

---@param steamID uint64
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function Inventory.RequestEligiblePromoItemDefinitionsIDs(steamID, callback) end

---@param steamID uint64
---@return boolean
---@return integer
---@return integer
function Inventory.GetEligiblePromoItemDefinitionIDs(steamID) end

---@param pArrayItemDefs table
---@param punArrayQuantity table
---@param unArrayLength integer
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function Inventory.StartPurchase(pArrayItemDefs, punArrayQuantity, unArrayLength, callback) end

---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function Inventory.RequestPrices(callback) end

---@return integer
function Inventory.GetNumItemsWithPrices() end

---@param iDefinition integer
---@return boolean
---@return table
---@return table
function Inventory.GetItemPrice(iDefinition) end

---@return table
function Inventory.StartUpdateProperties() end

---@param handle table
---@param nItemID table
---@param pchPropertyName string
---@return boolean
function Inventory.RemoveProperty(handle, nItemID, pchPropertyName) end

---@param handle table
---@param nItemID table
---@param pchPropertyName string
---@param pchPropertyValue string
---@return boolean
function Inventory.SetPropertyString(handle, nItemID, pchPropertyName, pchPropertyValue) end

---@param handle table
---@param nItemID table
---@param pchPropertyName string
---@param bValue boolean
---@return boolean
function Inventory.SetPropertyBool(handle, nItemID, pchPropertyName, bValue) end

---@param handle table
---@param nItemID table
---@param pchPropertyName string
---@param nValue table
---@return boolean
function Inventory.SetPropertyInt64(handle, nItemID, pchPropertyName, nValue) end

---@param handle table
---@param nItemID table
---@param pchPropertyName string
---@param flValue number
---@return boolean
function Inventory.SetPropertyFloat(handle, nItemID, pchPropertyName, flValue) end

---@param handle table
---@return boolean
---@return integer
function Inventory.SubmitUpdateProperties(handle) end

---@param pchItemToken string
---@return boolean
---@return integer
function Inventory.InspectItem(pchItemToken) end

Steam.Inventory = Inventory
