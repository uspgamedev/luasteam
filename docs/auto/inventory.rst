###############
ISteamInventory
###############

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✍️ are manually implemented and methods marked with ✋ are currently not implemented.

.. note::
   Overloaded Steam methods are exposed as distinct Lua functions using a type suffix (for example ``GetStatInt32`` and ``SetStatFloat``).

List of Functions
-----------------

* :func:`Inventory.AddPromoItem`
* :func:`Inventory.AddPromoItems`
* :func:`Inventory.CheckResultSteamID`
* :func:`Inventory.ConsumeItem`
* :func:`Inventory.DeserializeResult`
* :func:`Inventory.DestroyResult`
* :func:`Inventory.ExchangeItems`
* :func:`Inventory.GenerateItems`
* :func:`Inventory.GetAllItems`
* :func:`Inventory.GetEligiblePromoItemDefinitionIDs`
* :func:`Inventory.GetItemDefinitionIDs`
* :func:`Inventory.GetItemDefinitionProperty`
* :func:`Inventory.GetItemPrice`
* :func:`Inventory.GetItemsByID`
* :func:`Inventory.GetItemsWithPrices`
* :func:`Inventory.GetNumItemsWithPrices`
* :func:`Inventory.GetResultItemProperty`
* :func:`Inventory.GetResultItems`
* :func:`Inventory.GetResultStatus`
* :func:`Inventory.GetResultTimestamp`
* :func:`Inventory.GrantPromoItems`
* :func:`Inventory.InspectItem`
* :func:`Inventory.LoadItemDefinitions`
* :func:`Inventory.RemoveProperty`
* :func:`Inventory.RequestEligiblePromoItemDefinitionsIDs`
* :func:`Inventory.RequestPrices`
* :func:`Inventory.SendItemDropHeartbeat`
* :func:`Inventory.SetPropertyBool`
* :func:`Inventory.SetPropertyFloat`
* :func:`Inventory.SetPropertyInt64`
* :func:`Inventory.SetPropertyString`
* :func:`Inventory.StartPurchase`
* :func:`Inventory.StartUpdateProperties`
* :func:`Inventory.SubmitUpdateProperties`
* :func:`Inventory.TradeItems`
* :func:`Inventory.TransferItemQuantity`
* :func:`Inventory.TriggerItemDrop`

List of Callbacks
-----------------

* :func:`Inventory.OnSteamInventoryResultReady`
* :func:`Inventory.OnSteamInventoryFullUpdate`
* :func:`Inventory.OnSteamInventoryDefinitionUpdate`
* :func:`Inventory.OnSteamInventoryEligiblePromoItemDefIDs`
* :func:`Inventory.OnSteamInventoryStartPurchaseResult`
* :func:`Inventory.OnSteamInventoryRequestPricesResult`

Function Reference
------------------

.. function:: Inventory.AddPromoItem(itemDef)

    🤖 **Auto-generated binding**

    :param int itemDef:
    :returns: (bool) Return value
    :returns: (int) ``pResultHandle``
    :SteamWorks: `AddPromoItem <https://partner.steamgames.com/doc/api/ISteamInventory#AddPromoItem>`_

    **Signature differences from C++ API:**

    * Parameter ``pResultHandle`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    local ok, resultHandle = Steam.Inventory.AddPromoItem(promoItemDefID)

.. function:: Inventory.AddPromoItems(pArrayItemDefs, unArrayLength)

    🤖 **Auto-generated binding**

    :param int[]? pArrayItemDefs:
    :param int unArrayLength: size of the input array ``pArrayItemDefs``
    :returns: (bool) Return value
    :returns: (int) ``pResultHandle``
    :SteamWorks: `AddPromoItems <https://partner.steamgames.com/doc/api/ISteamInventory#AddPromoItems>`_

    **Signature differences from C++ API:**

    * Parameter ``pResultHandle`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    local ok, resultHandle = Steam.Inventory.AddPromoItems({item1, item2}, 2)

.. function:: Inventory.CheckResultSteamID(resultHandle, steamIDExpected)

    🤖 **Auto-generated binding**

    :param int resultHandle:
    :param uint64 steamIDExpected:
    :returns: (bool) Return value
    :SteamWorks: `CheckResultSteamID <https://partner.steamgames.com/doc/api/ISteamInventory#CheckResultSteamID>`_

.. function:: Inventory.ConsumeItem(itemConsume, unQuantity)

    🤖 **Auto-generated binding**

    :param uint64 itemConsume:
    :param int unQuantity:
    :returns: (bool) Return value
    :returns: (int) ``pResultHandle``
    :SteamWorks: `ConsumeItem <https://partner.steamgames.com/doc/api/ISteamInventory#ConsumeItem>`_

    **Signature differences from C++ API:**

    * Parameter ``pResultHandle`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    local ok, resultHandle = Steam.Inventory.ConsumeItem(itemInstanceID, 1)
    -- Wait for OnSteamInventoryResultReady to confirm

.. function:: Inventory.DeserializeResult(pBuffer, unBufferSize, bRESERVED_MUST_BE_FALSE)

    🤖 **Auto-generated binding**

    :param str? pBuffer:
    :param int unBufferSize: size of the input array ``pBuffer``
    :param bool bRESERVED_MUST_BE_FALSE:
    :returns: (bool) Return value
    :returns: (int) ``pOutResultHandle``
    :SteamWorks: `DeserializeResult <https://partner.steamgames.com/doc/api/ISteamInventory#DeserializeResult>`_

    **Signature differences from C++ API:**

    * Parameter ``pOutResultHandle`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: Inventory.DestroyResult(resultHandle)

    🤖 **Auto-generated binding**

    :param int resultHandle:
    :SteamWorks: `DestroyResult <https://partner.steamgames.com/doc/api/ISteamInventory#DestroyResult>`_

    **Notes:**

    * See :func:`Inventory.GetResultItems`'s example.

.. function:: Inventory.ExchangeItems(pArrayGenerate, punArrayGenerateQuantity, unArrayGenerateLength, pArrayDestroy, punArrayDestroyQuantity, unArrayDestroyLength)

    🤖 **Auto-generated binding**

    :param int[]? pArrayGenerate:
    :param int[]? punArrayGenerateQuantity:
    :param int unArrayGenerateLength: size of the input arrays ``pArrayGenerate`` and ``punArrayGenerateQuantity``
    :param uint64[]? pArrayDestroy:
    :param int[]? punArrayDestroyQuantity:
    :param int unArrayDestroyLength: size of the input arrays ``pArrayDestroy`` and ``punArrayDestroyQuantity``
    :returns: (bool) Return value
    :returns: (int) ``pResultHandle``
    :SteamWorks: `ExchangeItems <https://partner.steamgames.com/doc/api/ISteamInventory#ExchangeItems>`_

    **Signature differences from C++ API:**

    * Parameter ``pResultHandle`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: Inventory.GenerateItems(pArrayItemDefs, punArrayQuantity, unArrayLength)

    🤖 **Auto-generated binding**

    :param int[]? pArrayItemDefs:
    :param int[]? punArrayQuantity:
    :param int unArrayLength: size of the input arrays ``pArrayItemDefs`` and ``punArrayQuantity``
    :returns: (bool) Return value
    :returns: (int) ``pResultHandle``
    :SteamWorks: `GenerateItems <https://partner.steamgames.com/doc/api/ISteamInventory#GenerateItems>`_

    **Signature differences from C++ API:**

    * Parameter ``pResultHandle`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: Inventory.GetAllItems()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :returns: (int) ``pResultHandle``
    :SteamWorks: `GetAllItems <https://partner.steamgames.com/doc/api/ISteamInventory#GetAllItems>`_

    **Signature differences from C++ API:**

    * Parameter ``pResultHandle`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    -- Request all items the current user owns
    local ok, resultHandle = Steam.Inventory.GetAllItems()
    -- Wait for OnSteamInventoryResultReady callback

.. function:: Inventory.GetEligiblePromoItemDefinitionIDs(steamID, punItemDefIDsArraySize)

    🤖 **Auto-generated binding**

    :param uint64 steamID:
    :param int? punItemDefIDsArraySize: size of the buffer to allocate for ``pItemDefIDs``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (bool) Return value
    :returns: (int[]) ``pItemDefIDs``
    :returns: (int) ``punItemDefIDsArraySize``
    :SteamWorks: `GetEligiblePromoItemDefinitionIDs <https://partner.steamgames.com/doc/api/ISteamInventory#GetEligiblePromoItemDefinitionIDs>`_

    **Signature differences from C++ API:**

    * Parameter ``pItemDefIDs`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.
    * Parameter ``punItemDefIDsArraySize`` is both an input and an output in C++: you pass the buffer size, and Steam writes the actual count back. luasteam returns it as an additional return value.

.. function:: Inventory.GetItemDefinitionIDs(punItemDefIDsArraySize)

    🤖 **Auto-generated binding**

    :param int? punItemDefIDsArraySize: size of the buffer to allocate for ``pItemDefIDs``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (bool) Return value
    :returns: (int[]) ``pItemDefIDs``
    :returns: (int) ``punItemDefIDsArraySize``
    :SteamWorks: `GetItemDefinitionIDs <https://partner.steamgames.com/doc/api/ISteamInventory#GetItemDefinitionIDs>`_

    **Signature differences from C++ API:**

    * Parameter ``pItemDefIDs`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.
    * Parameter ``punItemDefIDsArraySize`` is both an input and an output in C++: you pass the buffer size, and Steam writes the actual count back. luasteam returns it as an additional return value.

**Example**::

    local ids = Steam.Inventory.GetItemDefinitionIDs(256)
    for _, defID in ipairs(ids) do
        local ok, name = Steam.Inventory.GetItemDefinitionProperty(defID, 'name', 128)
        print('Item def:', defID, name)
    end

.. function:: Inventory.GetItemDefinitionProperty(iDefinition, pchPropertyName, punValueBufferSizeOut)

    🤖 **Auto-generated binding**

    :param int iDefinition:
    :param str? pchPropertyName:
    :param int? punValueBufferSizeOut: size of the buffer to allocate for ``pchValueBuffer``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (bool) Return value
    :returns: (str) ``pchValueBuffer``
    :returns: (int) ``punValueBufferSizeOut``
    :SteamWorks: `GetItemDefinitionProperty <https://partner.steamgames.com/doc/api/ISteamInventory#GetItemDefinitionProperty>`_

    **Signature differences from C++ API:**

    * Parameter ``pchValueBuffer`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.
    * Parameter ``punValueBufferSizeOut`` is both an input and an output in C++: you pass the buffer size, and Steam writes the actual count back. luasteam returns it as an additional return value.

    **Notes:**

    * See :func:`Inventory.GetItemDefinitionIDs`'s example.

.. function:: Inventory.GetItemPrice(iDefinition)

    🤖 **Auto-generated binding**

    :param int iDefinition:
    :returns: (bool) Return value
    :returns: (uint64) ``pCurrentPrice``
    :returns: (uint64) ``pBasePrice``
    :SteamWorks: `GetItemPrice <https://partner.steamgames.com/doc/api/ISteamInventory#GetItemPrice>`_

    **Signature differences from C++ API:**

    * Parameter ``pCurrentPrice`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.
    * Parameter ``pBasePrice`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: Inventory.GetItemsByID(pInstanceIDs, unCountInstanceIDs)

    🤖 **Auto-generated binding**

    :param uint64[]? pInstanceIDs:
    :param int unCountInstanceIDs: size of the input array ``pInstanceIDs``
    :returns: (bool) Return value
    :returns: (int) ``pResultHandle``
    :SteamWorks: `GetItemsByID <https://partner.steamgames.com/doc/api/ISteamInventory#GetItemsByID>`_

    **Signature differences from C++ API:**

    * Parameter ``pResultHandle`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    local ok, resultHandle = Steam.Inventory.GetItemsByID({itemInstanceID1, itemInstanceID2}, 2)
    -- Wait for OnSteamInventoryResultReady

.. function:: Inventory.GetItemsWithPrices(unArrayLength)

    🤖 **Auto-generated binding**

    :param int? unArrayLength: size of the buffer to allocate for the output arrays ``pArrayItemDefs``, ``pCurrentPrices``, ``pBasePrices``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (bool) Return value
    :returns: (int[]) ``pArrayItemDefs``
    :returns: (uint64[]) ``pCurrentPrices``
    :returns: (uint64[]) ``pBasePrices``
    :SteamWorks: `GetItemsWithPrices <https://partner.steamgames.com/doc/api/ISteamInventory#GetItemsWithPrices>`_

    **Signature differences from C++ API:**

    * Parameter ``pArrayItemDefs`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.
    * Parameter ``pCurrentPrices`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.
    * Parameter ``pBasePrices`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: Inventory.GetNumItemsWithPrices()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetNumItemsWithPrices <https://partner.steamgames.com/doc/api/ISteamInventory#GetNumItemsWithPrices>`_

.. function:: Inventory.GetResultItemProperty(resultHandle, unItemIndex, pchPropertyName, punValueBufferSizeOut)

    🤖 **Auto-generated binding**

    :param int resultHandle:
    :param int unItemIndex:
    :param str? pchPropertyName:
    :param int? punValueBufferSizeOut: size of the buffer to allocate for ``pchValueBuffer``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (bool) Return value
    :returns: (str) ``pchValueBuffer``
    :returns: (int) ``punValueBufferSizeOut``
    :SteamWorks: `GetResultItemProperty <https://partner.steamgames.com/doc/api/ISteamInventory#GetResultItemProperty>`_

    **Signature differences from C++ API:**

    * Parameter ``pchValueBuffer`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.
    * Parameter ``punValueBufferSizeOut`` is both an input and an output in C++: you pass the buffer size, and Steam writes the actual count back. luasteam returns it as an additional return value.

.. function:: Inventory.GetResultItems(resultHandle, punOutItemsArraySize)

    🤖 **Auto-generated binding**

    :param int resultHandle:
    :param int? punOutItemsArraySize: size of the buffer to allocate for ``pOutItemsArray``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (bool) Return value
    :returns: (:ref:`SteamItemDetails_t <struct-SteamItemDetails_t>`\ []) ``pOutItemsArray``
    :returns: (int) ``punOutItemsArraySize``
    :SteamWorks: `GetResultItems <https://partner.steamgames.com/doc/api/ISteamInventory#GetResultItems>`_

    **Signature differences from C++ API:**

    * Parameter ``pOutItemsArray`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.
    * Parameter ``punOutItemsArraySize`` is both an input and an output in C++: you pass the buffer size, and Steam writes the actual count back. luasteam returns it as an additional return value.

**Example**::

    function Steam.Inventory.OnSteamInventoryResultReady(data)
        if data.m_result ~= Steam.k_EResultOK then return end
        local _, items = Steam.Inventory.GetResultItems(data.m_handle, 256)
        for _, item in ipairs(items) do
            print('Item:', item.m_iDefinition, 'Qty:', item.m_unQuantity)
        end
        Steam.Inventory.DestroyResult(data.m_handle)
    end

.. function:: Inventory.GetResultStatus(resultHandle)

    🤖 **Auto-generated binding**

    :param int resultHandle:
    :returns: (int) Return value
    :SteamWorks: `GetResultStatus <https://partner.steamgames.com/doc/api/ISteamInventory#GetResultStatus>`_

**Example**::

    local status = Steam.Inventory.GetResultStatus(resultHandle)
    if status == Steam.k_EResultOK then
        processInventoryResult(resultHandle)
    end

.. function:: Inventory.GetResultTimestamp(resultHandle)

    🤖 **Auto-generated binding**

    :param int resultHandle:
    :returns: (int) Return value
    :SteamWorks: `GetResultTimestamp <https://partner.steamgames.com/doc/api/ISteamInventory#GetResultTimestamp>`_

.. function:: Inventory.GrantPromoItems()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :returns: (int) ``pResultHandle``
    :SteamWorks: `GrantPromoItems <https://partner.steamgames.com/doc/api/ISteamInventory#GrantPromoItems>`_

    **Signature differences from C++ API:**

    * Parameter ``pResultHandle`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: Inventory.InspectItem(pchItemToken)

    🤖 **Auto-generated binding**

    :param str? pchItemToken:
    :returns: (bool) Return value
    :returns: (int) ``pResultHandle``
    :SteamWorks: `InspectItem <https://partner.steamgames.com/doc/api/ISteamInventory#InspectItem>`_

    **Signature differences from C++ API:**

    * Parameter ``pResultHandle`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: Inventory.LoadItemDefinitions()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `LoadItemDefinitions <https://partner.steamgames.com/doc/api/ISteamInventory#LoadItemDefinitions>`_

**Example**::

    -- Trigger loading of item definitions; wait for OnSteamInventoryDefinitionUpdate
    Steam.Inventory.LoadItemDefinitions()

.. function:: Inventory.RemoveProperty(handle, nItemID, pchPropertyName)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param uint64 nItemID:
    :param str? pchPropertyName:
    :returns: (bool) Return value
    :SteamWorks: `RemoveProperty <https://partner.steamgames.com/doc/api/ISteamInventory#RemoveProperty>`_

.. function:: Inventory.RequestEligiblePromoItemDefinitionsIDs(steamID, callback)

    🤖 **Auto-generated binding**

    :param uint64 steamID:
    :param function callback: CallResult callback receiving struct :func:`SteamInventoryEligiblePromoItemDefIDs_t <Inventory.OnSteamInventoryEligiblePromoItemDefIDs>` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `RequestEligiblePromoItemDefinitionsIDs <https://partner.steamgames.com/doc/api/ISteamInventory#RequestEligiblePromoItemDefinitionsIDs>`_

.. function:: Inventory.RequestPrices(callback)

    🤖 **Auto-generated binding**

    :param function callback: CallResult callback receiving struct :func:`SteamInventoryRequestPricesResult_t <Inventory.OnSteamInventoryRequestPricesResult>` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `RequestPrices <https://partner.steamgames.com/doc/api/ISteamInventory#RequestPrices>`_

**Example**::

    Steam.Inventory.RequestPrices(function(data, err)
        if not err and data.m_result == Steam.k_EResultOK then
            local numItems = Steam.Inventory.GetNumItemsWithPrices()
            local ok, items, curPrices, basePrices = Steam.Inventory.GetItemsWithPrices(numItems)
            if ok then
                for i = 1, numItems do
                    print('Item', items[i], 'prices', curPrices[i], basePrices[i])
                end
            end
        end
    end)

.. function:: Inventory.SendItemDropHeartbeat()

    🤖 **Auto-generated binding**

    :SteamWorks: `SendItemDropHeartbeat <https://partner.steamgames.com/doc/api/ISteamInventory#SendItemDropHeartbeat>`_

.. function:: Inventory.SetPropertyBool(handle, nItemID, pchPropertyName, bValue)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param uint64 nItemID:
    :param str? pchPropertyName:
    :param bool bValue:
    :returns: (bool) Return value
    :SteamWorks: `SetProperty <https://partner.steamgames.com/doc/api/ISteamInventory#SetProperty>`_

    **Signature differences from C++ API:**

    * In C++, this is an overloaded method called ``SetProperty``. luasteam exposes each overload as a distinct function with a type suffix.

.. function:: Inventory.SetPropertyFloat(handle, nItemID, pchPropertyName, flValue)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param uint64 nItemID:
    :param str? pchPropertyName:
    :param float flValue:
    :returns: (bool) Return value
    :SteamWorks: `SetProperty <https://partner.steamgames.com/doc/api/ISteamInventory#SetProperty>`_

    **Signature differences from C++ API:**

    * In C++, this is an overloaded method called ``SetProperty``. luasteam exposes each overload as a distinct function with a type suffix.

.. function:: Inventory.SetPropertyInt64(handle, nItemID, pchPropertyName, nValue)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param uint64 nItemID:
    :param str? pchPropertyName:
    :param uint64 nValue:
    :returns: (bool) Return value
    :SteamWorks: `SetProperty <https://partner.steamgames.com/doc/api/ISteamInventory#SetProperty>`_

    **Signature differences from C++ API:**

    * In C++, this is an overloaded method called ``SetProperty``. luasteam exposes each overload as a distinct function with a type suffix.

.. function:: Inventory.SetPropertyString(handle, nItemID, pchPropertyName, pchPropertyValue)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :param uint64 nItemID:
    :param str? pchPropertyName:
    :param str? pchPropertyValue:
    :returns: (bool) Return value
    :SteamWorks: `SetProperty <https://partner.steamgames.com/doc/api/ISteamInventory#SetProperty>`_

    **Signature differences from C++ API:**

    * In C++, this is an overloaded method called ``SetProperty``. luasteam exposes each overload as a distinct function with a type suffix.

.. function:: Inventory.StartPurchase(pArrayItemDefs, punArrayQuantity, unArrayLength, callback)

    🤖 **Auto-generated binding**

    :param int[]? pArrayItemDefs:
    :param int[]? punArrayQuantity:
    :param int unArrayLength: size of the input arrays ``pArrayItemDefs`` and ``punArrayQuantity``
    :param function callback: CallResult callback receiving struct :func:`SteamInventoryStartPurchaseResult_t <Inventory.OnSteamInventoryStartPurchaseResult>` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `StartPurchase <https://partner.steamgames.com/doc/api/ISteamInventory#StartPurchase>`_

**Example**::

    Steam.Inventory.StartPurchase({itemDefID}, {1}, 1, function(data, err)
        if not err and data.m_result == Steam.k_EResultOK then
            print('Purchase started, orderID:', tostring(data.m_ulOrderID))
        end
    end)

.. function:: Inventory.StartUpdateProperties()

    🤖 **Auto-generated binding**

    :returns: (uint64) Return value
    :SteamWorks: `StartUpdateProperties <https://partner.steamgames.com/doc/api/ISteamInventory#StartUpdateProperties>`_

.. function:: Inventory.SubmitUpdateProperties(handle)

    🤖 **Auto-generated binding**

    :param uint64 handle:
    :returns: (bool) Return value
    :returns: (int) ``pResultHandle``
    :SteamWorks: `SubmitUpdateProperties <https://partner.steamgames.com/doc/api/ISteamInventory#SubmitUpdateProperties>`_

    **Signature differences from C++ API:**

    * Parameter ``pResultHandle`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: Inventory.TradeItems(steamIDTradePartner, pArrayGive, pArrayGiveQuantity, nArrayGiveLength, pArrayGet, pArrayGetQuantity, nArrayGetLength)

    🤖 **Auto-generated binding**

    :param uint64 steamIDTradePartner:
    :param uint64[]? pArrayGive:
    :param int[]? pArrayGiveQuantity:
    :param int nArrayGiveLength: size of the input arrays ``pArrayGive`` and ``pArrayGiveQuantity``
    :param uint64[]? pArrayGet:
    :param int[]? pArrayGetQuantity:
    :param int nArrayGetLength: size of the input arrays ``pArrayGet`` and ``pArrayGetQuantity``
    :returns: (bool) Return value
    :returns: (int) ``pResultHandle``
    :SteamWorks: `TradeItems <https://partner.steamgames.com/doc/api/ISteamInventory#TradeItems>`_

    **Signature differences from C++ API:**

    * Parameter ``pResultHandle`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: Inventory.TransferItemQuantity(itemIdSource, unQuantity, itemIdDest)

    🤖 **Auto-generated binding**

    :param uint64 itemIdSource:
    :param int unQuantity:
    :param uint64 itemIdDest:
    :returns: (bool) Return value
    :returns: (int) ``pResultHandle``
    :SteamWorks: `TransferItemQuantity <https://partner.steamgames.com/doc/api/ISteamInventory#TransferItemQuantity>`_

    **Signature differences from C++ API:**

    * Parameter ``pResultHandle`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    -- Split a stack: move 5 units to a new stack
    local ok, resultHandle = Steam.Inventory.TransferItemQuantity(sourceItemID, 5, 0)

.. function:: Inventory.TriggerItemDrop(dropListDefinition)

    🤖 **Auto-generated binding**

    :param int dropListDefinition:
    :returns: (bool) Return value
    :returns: (int) ``pResultHandle``
    :SteamWorks: `TriggerItemDrop <https://partner.steamgames.com/doc/api/ISteamInventory#TriggerItemDrop>`_

    **Signature differences from C++ API:**

    * Parameter ``pResultHandle`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    local ok, resultHandle = Steam.Inventory.TriggerItemDrop(dropListDefinitionID)
    -- Triggers a potential item drop for playtime rewards


Unimplemented Methods
---------------------

.. function:: Inventory.serializeResult

    ✋ **Not implemented** - blocklist: Uses nullptr as input, we don't support it
    
    :SteamWorks: `SerializeResult <https://partner.steamgames.com/doc/api/ISteamInventory#SerializeResult>`_


Callbacks
---------

.. function:: Inventory.OnSteamInventoryResultReady

    Callback for `SteamInventoryResultReady_t <https://partner.steamgames.com/doc/api/ISteamInventory#SteamInventoryResultReady_t>`_

    **callback(data)** receives:

    * **data.m_handle** *(SteamInventoryResult_t)*
    * **data.m_result** *(EResult)*

.. function:: Inventory.OnSteamInventoryFullUpdate

    Callback for `SteamInventoryFullUpdate_t <https://partner.steamgames.com/doc/api/ISteamInventory#SteamInventoryFullUpdate_t>`_

    **callback(data)** receives:

    * **data.m_handle** *(SteamInventoryResult_t)*

.. function:: Inventory.OnSteamInventoryDefinitionUpdate

    Callback for `SteamInventoryDefinitionUpdate_t <https://partner.steamgames.com/doc/api/ISteamInventory#SteamInventoryDefinitionUpdate_t>`_

    **callback(data)** receives no fields (notification only).

**Example**::

    function Steam.Inventory.OnSteamInventoryDefinitionUpdate()
        print('Item definitions updated')
        local ids = Steam.Inventory.GetItemDefinitionIDs(256)
        print('Loaded', #ids, 'item definitions')
    end

.. function:: Inventory.OnSteamInventoryEligiblePromoItemDefIDs

    Callback for `SteamInventoryEligiblePromoItemDefIDs_t <https://partner.steamgames.com/doc/api/ISteamInventory#SteamInventoryEligiblePromoItemDefIDs_t>`_

    **callback(data)** receives:

    * **data.m_result** *(EResult)*
    * **data.m_steamID** *(uint64)*
    * **data.m_numEligiblePromoItemDefs** *(int)*
    * **data.m_bCachedData** *(bool)*

.. function:: Inventory.OnSteamInventoryStartPurchaseResult

    Callback for `SteamInventoryStartPurchaseResult_t <https://partner.steamgames.com/doc/api/ISteamInventory#SteamInventoryStartPurchaseResult_t>`_

    **callback(data)** receives:

    * **data.m_result** *(EResult)*
    * **data.m_ulOrderID** *(uint64)*
    * **data.m_ulTransID** *(uint64)*

.. function:: Inventory.OnSteamInventoryRequestPricesResult

    Callback for `SteamInventoryRequestPricesResult_t <https://partner.steamgames.com/doc/api/ISteamInventory#SteamInventoryRequestPricesResult_t>`_

    **callback(data)** receives:

    * **data.m_result** *(EResult)*
    * **data.m_rgchCurrency** *(string)*

**Example**::

    function Steam.Inventory.OnSteamInventoryRequestPricesResult(data)
        if data.m_result == Steam.k_EResultOK then
            print('Currency:', data.m_rgchCurrency)
        end
    end

