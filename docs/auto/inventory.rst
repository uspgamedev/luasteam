###############
ISteamInventory
###############

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✋ require manual implementation.

List of Functions
-----------------

* :func:`Inventory.GetResultStatus`
* :func:`Inventory.GetResultItems`
* :func:`Inventory.GetResultItemProperty`
* :func:`Inventory.GetResultTimestamp`
* :func:`Inventory.CheckResultSteamID`
* :func:`Inventory.DestroyResult`
* :func:`Inventory.GetAllItems`
* :func:`Inventory.GetItemsByID`
* :func:`Inventory.DeserializeResult`
* :func:`Inventory.GenerateItems`
* :func:`Inventory.GrantPromoItems`
* :func:`Inventory.AddPromoItem`
* :func:`Inventory.AddPromoItems`
* :func:`Inventory.ConsumeItem`
* :func:`Inventory.ExchangeItems`
* :func:`Inventory.TransferItemQuantity`
* :func:`Inventory.SendItemDropHeartbeat`
* :func:`Inventory.TriggerItemDrop`
* :func:`Inventory.TradeItems`
* :func:`Inventory.LoadItemDefinitions`
* :func:`Inventory.GetItemDefinitionIDs`
* :func:`Inventory.GetItemDefinitionProperty`
* :func:`Inventory.RequestEligiblePromoItemDefinitionsIDs`
* :func:`Inventory.GetEligiblePromoItemDefinitionIDs`
* :func:`Inventory.StartPurchase`
* :func:`Inventory.RequestPrices`
* :func:`Inventory.GetNumItemsWithPrices`
* :func:`Inventory.GetItemPrice`
* :func:`Inventory.StartUpdateProperties`
* :func:`Inventory.RemoveProperty`
* :func:`Inventory.SetPropertyString`
* :func:`Inventory.SetPropertyBool`
* :func:`Inventory.SetPropertyInt64`
* :func:`Inventory.SetPropertyFloat`
* :func:`Inventory.SubmitUpdateProperties`
* :func:`Inventory.InspectItem`

List of Callbacks
-----------------

* :func:`Inventory.onSteamInventoryResultReady`
* :func:`Inventory.onSteamInventoryFullUpdate`
* :func:`Inventory.onSteamInventoryDefinitionUpdate`
* :func:`Inventory.onSteamInventoryEligiblePromoItemDefIDs`
* :func:`Inventory.onSteamInventoryStartPurchaseResult`
* :func:`Inventory.onSteamInventoryRequestPricesResult`

Function Reference
------------------

.. function:: Inventory.GetResultStatus(resultHandle)

    🤖 **Auto-generated binding**

    :param int resultHandle:
    :returns: (int) Return value
    :SteamWorks: `GetResultStatus <https://partner.steamgames.com/doc/api/ISteamInventory#GetResultStatus>`_

.. function:: Inventory.GetResultItems(resultHandle, punOutItemsArraySize)

    🤖 **Auto-generated binding**

    :param int resultHandle:
    :param int punOutItemsArraySize:
    :returns: (bool) Return value
    :returns: (table[]) Value for `pOutItemsArray`
    :returns: (int) Value for `punOutItemsArraySize`
    :SteamWorks: `GetResultItems <https://partner.steamgames.com/doc/api/ISteamInventory#GetResultItems>`_

    **Signature differences from C++ API:**

    * Parameter ``pOutItemsArray`` is returned as an additional return value
    * Parameter ``punOutItemsArraySize`` is returned as an additional return value

.. function:: Inventory.GetResultItemProperty(resultHandle, unItemIndex, pchPropertyName, punValueBufferSizeOut)

    🤖 **Auto-generated binding**

    :param int resultHandle:
    :param int unItemIndex:
    :param str pchPropertyName:
    :param int punValueBufferSizeOut:
    :returns: (bool) Return value
    :returns: (str) Value for `pchValueBuffer`
    :returns: (int) Value for `punValueBufferSizeOut`
    :SteamWorks: `GetResultItemProperty <https://partner.steamgames.com/doc/api/ISteamInventory#GetResultItemProperty>`_

    **Signature differences from C++ API:**

    * Parameter ``pchValueBuffer`` is returned as an additional return value
    * Parameter ``punValueBufferSizeOut`` is returned as an additional return value

.. function:: Inventory.GetResultTimestamp(resultHandle)

    🤖 **Auto-generated binding**

    :param int resultHandle:
    :returns: (int) Return value
    :SteamWorks: `GetResultTimestamp <https://partner.steamgames.com/doc/api/ISteamInventory#GetResultTimestamp>`_

.. function:: Inventory.CheckResultSteamID(resultHandle, steamIDExpected)

    🤖 **Auto-generated binding**

    :param int resultHandle:
    :param uint64 steamIDExpected:
    :returns: (bool) Return value
    :SteamWorks: `CheckResultSteamID <https://partner.steamgames.com/doc/api/ISteamInventory#CheckResultSteamID>`_

.. function:: Inventory.DestroyResult(resultHandle)

    🤖 **Auto-generated binding**

    :param int resultHandle:
    :SteamWorks: `DestroyResult <https://partner.steamgames.com/doc/api/ISteamInventory#DestroyResult>`_

.. function:: Inventory.GetAllItems()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :returns: (int) Value for `pResultHandle`
    :SteamWorks: `GetAllItems <https://partner.steamgames.com/doc/api/ISteamInventory#GetAllItems>`_

    **Signature differences from C++ API:**

    * Parameter ``pResultHandle`` is returned as an additional return value

.. function:: Inventory.GetItemsByID(pInstanceIDs, unCountInstanceIDs)

    🤖 **Auto-generated binding**

    :param uint64[] pInstanceIDs:
    :param int unCountInstanceIDs:
    :returns: (bool) Return value
    :returns: (int) Value for `pResultHandle`
    :SteamWorks: `GetItemsByID <https://partner.steamgames.com/doc/api/ISteamInventory#GetItemsByID>`_

    **Signature differences from C++ API:**

    * Parameter ``pResultHandle`` is returned as an additional return value

.. function:: Inventory.DeserializeResult(pBuffer, unBufferSize, bRESERVED_MUST_BE_FALSE)

    🤖 **Auto-generated binding**

    :param str pBuffer:
    :param int unBufferSize:
    :param bool bRESERVED_MUST_BE_FALSE:
    :returns: (bool) Return value
    :returns: (int) Value for `pOutResultHandle`
    :SteamWorks: `DeserializeResult <https://partner.steamgames.com/doc/api/ISteamInventory#DeserializeResult>`_

    **Signature differences from C++ API:**

    * Parameter ``pOutResultHandle`` is returned as an additional return value

.. function:: Inventory.GenerateItems(pArrayItemDefs, unArrayLength, punArrayQuantity)

    🤖 **Auto-generated binding**

    :param int[] pArrayItemDefs:
    :param int unArrayLength:
    :param int[] punArrayQuantity:
    :returns: (bool) Return value
    :returns: (int) Value for `pResultHandle`
    :SteamWorks: `GenerateItems <https://partner.steamgames.com/doc/api/ISteamInventory#GenerateItems>`_

    **Signature differences from C++ API:**

    * Parameter ``pResultHandle`` is returned as an additional return value

.. function:: Inventory.GrantPromoItems()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :returns: (int) Value for `pResultHandle`
    :SteamWorks: `GrantPromoItems <https://partner.steamgames.com/doc/api/ISteamInventory#GrantPromoItems>`_

    **Signature differences from C++ API:**

    * Parameter ``pResultHandle`` is returned as an additional return value

.. function:: Inventory.AddPromoItem(itemDef)

    🤖 **Auto-generated binding**

    :param int itemDef:
    :returns: (bool) Return value
    :returns: (int) Value for `pResultHandle`
    :SteamWorks: `AddPromoItem <https://partner.steamgames.com/doc/api/ISteamInventory#AddPromoItem>`_

    **Signature differences from C++ API:**

    * Parameter ``pResultHandle`` is returned as an additional return value

.. function:: Inventory.AddPromoItems(pArrayItemDefs, unArrayLength)

    🤖 **Auto-generated binding**

    :param int[] pArrayItemDefs:
    :param int unArrayLength:
    :returns: (bool) Return value
    :returns: (int) Value for `pResultHandle`
    :SteamWorks: `AddPromoItems <https://partner.steamgames.com/doc/api/ISteamInventory#AddPromoItems>`_

    **Signature differences from C++ API:**

    * Parameter ``pResultHandle`` is returned as an additional return value

.. function:: Inventory.ConsumeItem(itemConsume, unQuantity)

    🤖 **Auto-generated binding**

    :param uint64 itemConsume:
    :param int unQuantity:
    :returns: (bool) Return value
    :returns: (int) Value for `pResultHandle`
    :SteamWorks: `ConsumeItem <https://partner.steamgames.com/doc/api/ISteamInventory#ConsumeItem>`_

    **Signature differences from C++ API:**

    * Parameter ``pResultHandle`` is returned as an additional return value

.. function:: Inventory.ExchangeItems(pArrayGenerate, unArrayGenerateLength, punArrayGenerateQuantity, pArrayDestroy, unArrayDestroyLength, punArrayDestroyQuantity)

    🤖 **Auto-generated binding**

    :param int[] pArrayGenerate:
    :param int unArrayGenerateLength:
    :param int[] punArrayGenerateQuantity:
    :param uint64[] pArrayDestroy:
    :param int unArrayDestroyLength:
    :param int[] punArrayDestroyQuantity:
    :returns: (bool) Return value
    :returns: (int) Value for `pResultHandle`
    :SteamWorks: `ExchangeItems <https://partner.steamgames.com/doc/api/ISteamInventory#ExchangeItems>`_

    **Signature differences from C++ API:**

    * Parameter ``pResultHandle`` is returned as an additional return value

.. function:: Inventory.TransferItemQuantity(itemIdSource, unQuantity, itemIdDest)

    🤖 **Auto-generated binding**

    :param uint64 itemIdSource:
    :param int unQuantity:
    :param uint64 itemIdDest:
    :returns: (bool) Return value
    :returns: (int) Value for `pResultHandle`
    :SteamWorks: `TransferItemQuantity <https://partner.steamgames.com/doc/api/ISteamInventory#TransferItemQuantity>`_

    **Signature differences from C++ API:**

    * Parameter ``pResultHandle`` is returned as an additional return value

.. function:: Inventory.SendItemDropHeartbeat()

    🤖 **Auto-generated binding**

    :SteamWorks: `SendItemDropHeartbeat <https://partner.steamgames.com/doc/api/ISteamInventory#SendItemDropHeartbeat>`_

.. function:: Inventory.TriggerItemDrop(dropListDefinition)

    🤖 **Auto-generated binding**

    :param int dropListDefinition:
    :returns: (bool) Return value
    :returns: (int) Value for `pResultHandle`
    :SteamWorks: `TriggerItemDrop <https://partner.steamgames.com/doc/api/ISteamInventory#TriggerItemDrop>`_

    **Signature differences from C++ API:**

    * Parameter ``pResultHandle`` is returned as an additional return value

.. function:: Inventory.TradeItems(steamIDTradePartner, pArrayGive, nArrayGiveLength, pArrayGiveQuantity, pArrayGet, nArrayGetLength, pArrayGetQuantity)

    🤖 **Auto-generated binding**

    :param uint64 steamIDTradePartner:
    :param uint64[] pArrayGive:
    :param int nArrayGiveLength:
    :param int[] pArrayGiveQuantity:
    :param uint64[] pArrayGet:
    :param int nArrayGetLength:
    :param int[] pArrayGetQuantity:
    :returns: (bool) Return value
    :returns: (int) Value for `pResultHandle`
    :SteamWorks: `TradeItems <https://partner.steamgames.com/doc/api/ISteamInventory#TradeItems>`_

    **Signature differences from C++ API:**

    * Parameter ``pResultHandle`` is returned as an additional return value

.. function:: Inventory.LoadItemDefinitions()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `LoadItemDefinitions <https://partner.steamgames.com/doc/api/ISteamInventory#LoadItemDefinitions>`_

.. function:: Inventory.GetItemDefinitionIDs(punItemDefIDsArraySize)

    🤖 **Auto-generated binding**

    :param int punItemDefIDsArraySize:
    :returns: (bool) Return value
    :returns: (int[]) Value for `pItemDefIDs`
    :returns: (int) Value for `punItemDefIDsArraySize`
    :SteamWorks: `GetItemDefinitionIDs <https://partner.steamgames.com/doc/api/ISteamInventory#GetItemDefinitionIDs>`_

    **Signature differences from C++ API:**

    * Parameter ``pItemDefIDs`` is returned as an additional return value
    * Parameter ``punItemDefIDsArraySize`` is returned as an additional return value

.. function:: Inventory.GetItemDefinitionProperty(iDefinition, pchPropertyName, punValueBufferSizeOut)

    🤖 **Auto-generated binding**

    :param int iDefinition:
    :param str pchPropertyName:
    :param int punValueBufferSizeOut:
    :returns: (bool) Return value
    :returns: (str) Value for `pchValueBuffer`
    :returns: (int) Value for `punValueBufferSizeOut`
    :SteamWorks: `GetItemDefinitionProperty <https://partner.steamgames.com/doc/api/ISteamInventory#GetItemDefinitionProperty>`_

    **Signature differences from C++ API:**

    * Parameter ``pchValueBuffer`` is returned as an additional return value
    * Parameter ``punValueBufferSizeOut`` is returned as an additional return value

.. function:: Inventory.RequestEligiblePromoItemDefinitionsIDs(steamID, callback)

    🤖 **Auto-generated binding**

    :param uint64 steamID:
    :param function callback: CallResult callback receiving struct `SteamInventoryEligiblePromoItemDefIDs_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `RequestEligiblePromoItemDefinitionsIDs <https://partner.steamgames.com/doc/api/ISteamInventory#RequestEligiblePromoItemDefinitionsIDs>`_

.. function:: Inventory.GetEligiblePromoItemDefinitionIDs(steamID, punItemDefIDsArraySize)

    🤖 **Auto-generated binding**

    :param uint64 steamID:
    :param int punItemDefIDsArraySize:
    :returns: (bool) Return value
    :returns: (int[]) Value for `pItemDefIDs`
    :returns: (int) Value for `punItemDefIDsArraySize`
    :SteamWorks: `GetEligiblePromoItemDefinitionIDs <https://partner.steamgames.com/doc/api/ISteamInventory#GetEligiblePromoItemDefinitionIDs>`_

    **Signature differences from C++ API:**

    * Parameter ``pItemDefIDs`` is returned as an additional return value
    * Parameter ``punItemDefIDsArraySize`` is returned as an additional return value

.. function:: Inventory.StartPurchase(pArrayItemDefs, unArrayLength, punArrayQuantity, callback)

    🤖 **Auto-generated binding**

    :param int[] pArrayItemDefs:
    :param int unArrayLength:
    :param int[] punArrayQuantity:
    :param function callback: CallResult callback receiving struct `SteamInventoryStartPurchaseResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `StartPurchase <https://partner.steamgames.com/doc/api/ISteamInventory#StartPurchase>`_

.. function:: Inventory.RequestPrices(callback)

    🤖 **Auto-generated binding**

    :param function callback: CallResult callback receiving struct `SteamInventoryRequestPricesResult_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `RequestPrices <https://partner.steamgames.com/doc/api/ISteamInventory#RequestPrices>`_

.. function:: Inventory.GetNumItemsWithPrices()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetNumItemsWithPrices <https://partner.steamgames.com/doc/api/ISteamInventory#GetNumItemsWithPrices>`_

.. function:: Inventory.GetItemPrice(iDefinition)

    🤖 **Auto-generated binding**

    :param int iDefinition:
    :returns: (bool) Return value
    :returns: (uint64) Value for `pCurrentPrice`
    :returns: (uint64) Value for `pBasePrice`
    :SteamWorks: `GetItemPrice <https://partner.steamgames.com/doc/api/ISteamInventory#GetItemPrice>`_

    **Signature differences from C++ API:**

    * Parameter ``pCurrentPrice`` is returned as an additional return value
    * Parameter ``pBasePrice`` is returned as an additional return value

.. function:: Inventory.StartUpdateProperties()

    🤖 **Auto-generated binding**

    :returns: (uint64) Return value
    :SteamWorks: `StartUpdateProperties <https://partner.steamgames.com/doc/api/ISteamInventory#StartUpdateProperties>`_

.. function:: Inventory.RemoveProperty(handle, nItemID, pchPropertyName)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param uint64 nItemID:
    :param str pchPropertyName:
    :returns: (bool) Return value
    :SteamWorks: `RemoveProperty <https://partner.steamgames.com/doc/api/ISteamInventory#RemoveProperty>`_

.. function:: Inventory.SetPropertyString(handle, nItemID, pchPropertyName, pchPropertyValue)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param uint64 nItemID:
    :param str pchPropertyName:
    :param str pchPropertyValue:
    :returns: (bool) Return value
    :SteamWorks: `SetPropertyString <https://partner.steamgames.com/doc/api/ISteamInventory#SetPropertyString>`_

.. function:: Inventory.SetPropertyBool(handle, nItemID, pchPropertyName, bValue)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param uint64 nItemID:
    :param str pchPropertyName:
    :param bool bValue:
    :returns: (bool) Return value
    :SteamWorks: `SetPropertyBool <https://partner.steamgames.com/doc/api/ISteamInventory#SetPropertyBool>`_

.. function:: Inventory.SetPropertyInt64(handle, nItemID, pchPropertyName, nValue)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param uint64 nItemID:
    :param str pchPropertyName:
    :param uint64 nValue:
    :returns: (bool) Return value
    :SteamWorks: `SetPropertyInt64 <https://partner.steamgames.com/doc/api/ISteamInventory#SetPropertyInt64>`_

.. function:: Inventory.SetPropertyFloat(handle, nItemID, pchPropertyName, flValue)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param uint64 nItemID:
    :param str pchPropertyName:
    :param float flValue:
    :returns: (bool) Return value
    :SteamWorks: `SetPropertyFloat <https://partner.steamgames.com/doc/api/ISteamInventory#SetPropertyFloat>`_

.. function:: Inventory.SubmitUpdateProperties(handle)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :returns: (bool) Return value
    :returns: (int) Value for `pResultHandle`
    :SteamWorks: `SubmitUpdateProperties <https://partner.steamgames.com/doc/api/ISteamInventory#SubmitUpdateProperties>`_

    **Signature differences from C++ API:**

    * Parameter ``pResultHandle`` is returned as an additional return value

.. function:: Inventory.InspectItem(pchItemToken)

    🤖 **Auto-generated binding**

    :param str pchItemToken:
    :returns: (bool) Return value
    :returns: (int) Value for `pResultHandle`
    :SteamWorks: `InspectItem <https://partner.steamgames.com/doc/api/ISteamInventory#InspectItem>`_

    **Signature differences from C++ API:**

    * Parameter ``pResultHandle`` is returned as an additional return value


Unimplemented Methods
---------------------

.. function:: Inventory.serializeResult

    ✋ **Not implemented** - unsupported type: void *
    
    :SteamWorks: `SerializeResult <https://partner.steamgames.com/doc/api/ISteamInventory#SerializeResult>`_

.. function:: Inventory.getItemsWithPrices

    ✋ **Not implemented** - manual: out_array_count seems to be wrong
    
    :SteamWorks: `GetItemsWithPrices <https://partner.steamgames.com/doc/api/ISteamInventory#GetItemsWithPrices>`_


Callbacks
---------

.. function:: Inventory.onSteamInventoryResultReady

    Callback for `SteamInventoryResultReady_t <https://partner.steamgames.com/doc/api/steam_api#SteamInventoryResultReady_t>`_

    **callback(data)** receives:

    * **data.m_handle** -- m_handle
    * **data.m_result** -- m_result

.. function:: Inventory.onSteamInventoryFullUpdate

    Callback for `SteamInventoryFullUpdate_t <https://partner.steamgames.com/doc/api/steam_api#SteamInventoryFullUpdate_t>`_

    **callback(data)** receives:

    * **data.m_handle** -- m_handle

.. function:: Inventory.onSteamInventoryDefinitionUpdate

    Callback for `SteamInventoryDefinitionUpdate_t <https://partner.steamgames.com/doc/api/steam_api#SteamInventoryDefinitionUpdate_t>`_

    **callback(data)** receives:


.. function:: Inventory.onSteamInventoryEligiblePromoItemDefIDs

    Callback for `SteamInventoryEligiblePromoItemDefIDs_t <https://partner.steamgames.com/doc/api/steam_api#SteamInventoryEligiblePromoItemDefIDs_t>`_

    **callback(data)** receives:

    * **data.m_result** -- m_result
    * **data.m_steamID** -- m_steamID
    * **data.m_numEligiblePromoItemDefs** -- m_numEligiblePromoItemDefs
    * **data.m_bCachedData** -- m_bCachedData

.. function:: Inventory.onSteamInventoryStartPurchaseResult

    Callback for `SteamInventoryStartPurchaseResult_t <https://partner.steamgames.com/doc/api/steam_api#SteamInventoryStartPurchaseResult_t>`_

    **callback(data)** receives:

    * **data.m_result** -- m_result
    * **data.m_ulOrderID** -- m_ulOrderID
    * **data.m_ulTransID** -- m_ulTransID

.. function:: Inventory.onSteamInventoryRequestPricesResult

    Callback for `SteamInventoryRequestPricesResult_t <https://partner.steamgames.com/doc/api/steam_api#SteamInventoryRequestPricesResult_t>`_

    **callback(data)** receives:

    * **data.m_result** -- m_result
    * **data.m_rgchCurrency** -- m_rgchCurrency

