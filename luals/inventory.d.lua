---@class Steam.Inventory
local Inventory = {}

---@param resultHandle integer
---@return integer
function Inventory.GetResultStatus(resultHandle) end

---@param resultHandle integer
---@param punOutItemsArraySize integer
---@return boolean
---@return SteamItemDetails_t[] -- Value of: pOutItemsArray
---@return integer -- Value of: punOutItemsArraySize
function Inventory.GetResultItems(resultHandle, punOutItemsArraySize) end

---@param resultHandle integer
---@param unItemIndex integer
---@param pchPropertyName string
---@param punValueBufferSizeOut integer
---@return boolean
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

---@param pInstanceIDs uint64[]
---@param unCountInstanceIDs integer
---@return boolean
---@return integer -- Value of: pResultHandle
function Inventory.GetItemsByID(pInstanceIDs, unCountInstanceIDs) end

---@param pBuffer string
---@param unBufferSize integer
---@param bRESERVED_MUST_BE_FALSE boolean
---@return boolean
---@return integer -- Value of: pOutResultHandle
function Inventory.DeserializeResult(pBuffer, unBufferSize, bRESERVED_MUST_BE_FALSE) end

---@param pArrayItemDefs integer[]
---@param unArrayLength integer
---@param punArrayQuantity integer[]
---@return boolean
---@return integer -- Value of: pResultHandle
function Inventory.GenerateItems(pArrayItemDefs, unArrayLength, punArrayQuantity) end

---@return boolean
---@return integer -- Value of: pResultHandle
function Inventory.GrantPromoItems() end

---@param itemDef integer
---@return boolean
---@return integer -- Value of: pResultHandle
function Inventory.AddPromoItem(itemDef) end

---@param pArrayItemDefs integer[]
---@param unArrayLength integer
---@return boolean
---@return integer -- Value of: pResultHandle
function Inventory.AddPromoItems(pArrayItemDefs, unArrayLength) end

---@param itemConsume uint64
---@param unQuantity integer
---@return boolean
---@return integer -- Value of: pResultHandle
function Inventory.ConsumeItem(itemConsume, unQuantity) end

---@param pArrayGenerate integer[]
---@param unArrayGenerateLength integer
---@param punArrayGenerateQuantity integer[]
---@param pArrayDestroy uint64[]
---@param unArrayDestroyLength integer
---@param punArrayDestroyQuantity integer[]
---@return boolean
---@return integer -- Value of: pResultHandle
function Inventory.ExchangeItems(pArrayGenerate, unArrayGenerateLength, punArrayGenerateQuantity, pArrayDestroy, unArrayDestroyLength, punArrayDestroyQuantity) end

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
---@param pArrayGive uint64[]
---@param nArrayGiveLength integer
---@param pArrayGiveQuantity integer[]
---@param pArrayGet uint64[]
---@param nArrayGetLength integer
---@param pArrayGetQuantity integer[]
---@return boolean
---@return integer -- Value of: pResultHandle
function Inventory.TradeItems(steamIDTradePartner, pArrayGive, nArrayGiveLength, pArrayGiveQuantity, pArrayGet, nArrayGetLength, pArrayGetQuantity) end

---@return boolean
function Inventory.LoadItemDefinitions() end

---@param punItemDefIDsArraySize integer
---@return boolean
---@return integer[] -- Value of: pItemDefIDs
---@return integer -- Value of: punItemDefIDsArraySize
function Inventory.GetItemDefinitionIDs(punItemDefIDsArraySize) end

---@param iDefinition integer
---@param pchPropertyName string
---@param punValueBufferSizeOut integer
---@return boolean
---@return string -- Value of: pchValueBuffer
---@return integer -- Value of: punValueBufferSizeOut
function Inventory.GetItemDefinitionProperty(iDefinition, pchPropertyName, punValueBufferSizeOut) end

---@param steamID uint64
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function Inventory.RequestEligiblePromoItemDefinitionsIDs(steamID, callback) end

---@param steamID uint64
---@param punItemDefIDsArraySize integer
---@return boolean
---@return integer[] -- Value of: pItemDefIDs
---@return integer -- Value of: punItemDefIDsArraySize
function Inventory.GetEligiblePromoItemDefinitionIDs(steamID, punItemDefIDsArraySize) end

---@param pArrayItemDefs integer[]
---@param unArrayLength integer
---@param punArrayQuantity integer[]
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function Inventory.StartPurchase(pArrayItemDefs, unArrayLength, punArrayQuantity, callback) end

---@param callback fun(data: table?, io_fail: boolean)?
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
