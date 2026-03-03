################
ISteamController
################

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✍️ are manually implemented and methods marked with ✋ are currently not implemented.

List of Functions
-----------------

* :func:`Controller.ActivateActionSet`
* :func:`Controller.ActivateActionSetLayer`
* :func:`Controller.DeactivateActionSetLayer`
* :func:`Controller.DeactivateAllActionSetLayers`
* :func:`Controller.GetActionOriginFromXboxOrigin`
* :func:`Controller.GetActionSetHandle`
* :func:`Controller.GetActiveActionSetLayers`
* :func:`Controller.GetAnalogActionData`
* :func:`Controller.GetAnalogActionHandle`
* :func:`Controller.GetAnalogActionOrigins`
* :func:`Controller.GetConnectedControllers`
* :func:`Controller.GetControllerBindingRevision`
* :func:`Controller.GetControllerForGamepadIndex`
* :func:`Controller.GetCurrentActionSet`
* :func:`Controller.GetDigitalActionData`
* :func:`Controller.GetDigitalActionHandle`
* :func:`Controller.GetDigitalActionOrigins`
* :func:`Controller.GetGamepadIndexForController`
* :func:`Controller.GetGlyphForActionOrigin`
* :func:`Controller.GetGlyphForXboxOrigin`
* :func:`Controller.GetInputTypeForHandle`
* :func:`Controller.GetMotionData`
* :func:`Controller.GetStringForActionOrigin`
* :func:`Controller.GetStringForXboxOrigin`
* :func:`Controller.Init`
* :func:`Controller.RunFrame`
* :func:`Controller.SetLEDColor`
* :func:`Controller.ShowBindingPanel`
* :func:`Controller.Shutdown`
* :func:`Controller.StopAnalogActionMomentum`
* :func:`Controller.TranslateActionOrigin`
* :func:`Controller.TriggerHapticPulse`
* :func:`Controller.TriggerRepeatedHapticPulse`
* :func:`Controller.TriggerVibration`

Function Reference
------------------

.. function:: Controller.ActivateActionSet(controllerHandle, actionSetHandle)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :param uint64 actionSetHandle:
    :SteamWorks: `ActivateActionSet <https://partner.steamgames.com/doc/api/ISteamController#ActivateActionSet>`_

**Example**::

    local gameplaySet = Steam.Controller.GetActionSetHandle('GameControls')
    Steam.Controller.ActivateActionSet(controllerHandle, gameplaySet)

.. function:: Controller.ActivateActionSetLayer(controllerHandle, actionSetLayerHandle)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :param uint64 actionSetLayerHandle:
    :SteamWorks: `ActivateActionSetLayer <https://partner.steamgames.com/doc/api/ISteamController#ActivateActionSetLayer>`_

.. function:: Controller.DeactivateActionSetLayer(controllerHandle, actionSetLayerHandle)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :param uint64 actionSetLayerHandle:
    :SteamWorks: `DeactivateActionSetLayer <https://partner.steamgames.com/doc/api/ISteamController#DeactivateActionSetLayer>`_

.. function:: Controller.DeactivateAllActionSetLayers(controllerHandle)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :SteamWorks: `DeactivateAllActionSetLayers <https://partner.steamgames.com/doc/api/ISteamController#DeactivateAllActionSetLayers>`_

.. function:: Controller.GetActionOriginFromXboxOrigin(controllerHandle, eOrigin)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :param int eOrigin:
    :returns: (int) Return value
    :SteamWorks: `GetActionOriginFromXboxOrigin <https://partner.steamgames.com/doc/api/ISteamController#GetActionOriginFromXboxOrigin>`_

.. function:: Controller.GetActionSetHandle(pszActionSetName)

    🤖 **Auto-generated binding**

    :param str? pszActionSetName:
    :returns: (uint64) Return value
    :SteamWorks: `GetActionSetHandle <https://partner.steamgames.com/doc/api/ISteamController#GetActionSetHandle>`_

**Example**::

    local gameplaySet = Steam.Controller.GetActionSetHandle('GameControls')

.. function:: Controller.GetActiveActionSetLayers(controllerHandle)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :returns: (int) Return value
    :returns: (uint64[]) ``handlesOut``
    :SteamWorks: `GetActiveActionSetLayers <https://partner.steamgames.com/doc/api/ISteamController#GetActiveActionSetLayers>`_

    **Signature differences from C++ API:**

    * Parameter ``handlesOut`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: Controller.GetAnalogActionData(controllerHandle, analogActionHandle)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :param uint64 analogActionHandle:
    :returns: (:ref:`InputAnalogActionData_t <struct-InputAnalogActionData_t>`) Return value
    :SteamWorks: `GetAnalogActionData <https://partner.steamgames.com/doc/api/ISteamController#GetAnalogActionData>`_

**Example**::

    local moveHandle = Steam.Controller.GetAnalogActionHandle('Move')
    local data = Steam.Controller.GetAnalogActionData(controllerHandle, moveHandle)
    player.setVelocity(data.x * speed, data.y * speed)

.. function:: Controller.GetAnalogActionHandle(pszActionName)

    🤖 **Auto-generated binding**

    :param str? pszActionName:
    :returns: (uint64) Return value
    :SteamWorks: `GetAnalogActionHandle <https://partner.steamgames.com/doc/api/ISteamController#GetAnalogActionHandle>`_

**Example**::

    local moveHandle = Steam.Controller.GetAnalogActionHandle('Move')

.. function:: Controller.GetAnalogActionOrigins(controllerHandle, actionSetHandle, analogActionHandle)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :param uint64 actionSetHandle:
    :param uint64 analogActionHandle:
    :returns: (int) Return value
    :returns: (int[]) ``originsOut``
    :SteamWorks: `GetAnalogActionOrigins <https://partner.steamgames.com/doc/api/ISteamController#GetAnalogActionOrigins>`_

    **Signature differences from C++ API:**

    * Parameter ``originsOut`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: Controller.GetConnectedControllers()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :returns: (uint64[]) ``handlesOut``
    :SteamWorks: `GetConnectedControllers <https://partner.steamgames.com/doc/api/ISteamController#GetConnectedControllers>`_

    **Signature differences from C++ API:**

    * Parameter ``handlesOut`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    local _, controllers = Steam.Controller.GetConnectedControllers()
    print('Connected controllers:', #controllers)

.. function:: Controller.GetControllerBindingRevision(controllerHandle)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :returns: (bool) Return value
    :returns: (int) ``pMajor``
    :returns: (int) ``pMinor``
    :SteamWorks: `GetControllerBindingRevision <https://partner.steamgames.com/doc/api/ISteamController#GetControllerBindingRevision>`_

    **Signature differences from C++ API:**

    * Parameter ``pMajor`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.
    * Parameter ``pMinor`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: Controller.GetControllerForGamepadIndex(nIndex)

    🤖 **Auto-generated binding**

    :param int nIndex:
    :returns: (uint64) Return value
    :SteamWorks: `GetControllerForGamepadIndex <https://partner.steamgames.com/doc/api/ISteamController#GetControllerForGamepadIndex>`_

.. function:: Controller.GetCurrentActionSet(controllerHandle)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :returns: (uint64) Return value
    :SteamWorks: `GetCurrentActionSet <https://partner.steamgames.com/doc/api/ISteamController#GetCurrentActionSet>`_

.. function:: Controller.GetDigitalActionData(controllerHandle, digitalActionHandle)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :param uint64 digitalActionHandle:
    :returns: (:ref:`InputDigitalActionData_t <struct-InputDigitalActionData_t>`) Return value
    :SteamWorks: `GetDigitalActionData <https://partner.steamgames.com/doc/api/ISteamController#GetDigitalActionData>`_

**Example**::

    local jumpHandle = Steam.Controller.GetDigitalActionHandle('Jump')
    local data = Steam.Controller.GetDigitalActionData(controllerHandle, jumpHandle)
    if data.bState then
        player.jump()
    end

.. function:: Controller.GetDigitalActionHandle(pszActionName)

    🤖 **Auto-generated binding**

    :param str? pszActionName:
    :returns: (uint64) Return value
    :SteamWorks: `GetDigitalActionHandle <https://partner.steamgames.com/doc/api/ISteamController#GetDigitalActionHandle>`_

**Example**::

    local jumpHandle = Steam.Controller.GetDigitalActionHandle('Jump')

.. function:: Controller.GetDigitalActionOrigins(controllerHandle, actionSetHandle, digitalActionHandle)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :param uint64 actionSetHandle:
    :param uint64 digitalActionHandle:
    :returns: (int) Return value
    :returns: (int[]) ``originsOut``
    :SteamWorks: `GetDigitalActionOrigins <https://partner.steamgames.com/doc/api/ISteamController#GetDigitalActionOrigins>`_

    **Signature differences from C++ API:**

    * Parameter ``originsOut`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: Controller.GetGamepadIndexForController(ulControllerHandle)

    🤖 **Auto-generated binding**

    :param uint64 ulControllerHandle:
    :returns: (int) Return value
    :SteamWorks: `GetGamepadIndexForController <https://partner.steamgames.com/doc/api/ISteamController#GetGamepadIndexForController>`_

.. function:: Controller.GetGlyphForActionOrigin(eOrigin)

    🤖 **Auto-generated binding**

    :param int eOrigin:
    :returns: (str) Return value
    :SteamWorks: `GetGlyphForActionOrigin <https://partner.steamgames.com/doc/api/ISteamController#GetGlyphForActionOrigin>`_

.. function:: Controller.GetGlyphForXboxOrigin(eOrigin)

    🤖 **Auto-generated binding**

    :param int eOrigin:
    :returns: (str) Return value
    :SteamWorks: `GetGlyphForXboxOrigin <https://partner.steamgames.com/doc/api/ISteamController#GetGlyphForXboxOrigin>`_

.. function:: Controller.GetInputTypeForHandle(controllerHandle)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :returns: (int) Return value
    :SteamWorks: `GetInputTypeForHandle <https://partner.steamgames.com/doc/api/ISteamController#GetInputTypeForHandle>`_

**Example**::

    local inputType = Steam.Controller.GetInputTypeForHandle(controllerHandle)
    if inputType == Steam.k_ESteamInputType_PS4Controller then
        print("PS4 controller!")
    end

.. function:: Controller.GetMotionData(controllerHandle)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :returns: (:ref:`InputMotionData_t <struct-InputMotionData_t>`) Return value
    :SteamWorks: `GetMotionData <https://partner.steamgames.com/doc/api/ISteamController#GetMotionData>`_

.. function:: Controller.GetStringForActionOrigin(eOrigin)

    🤖 **Auto-generated binding**

    :param int eOrigin:
    :returns: (str) Return value
    :SteamWorks: `GetStringForActionOrigin <https://partner.steamgames.com/doc/api/ISteamController#GetStringForActionOrigin>`_

.. function:: Controller.GetStringForXboxOrigin(eOrigin)

    🤖 **Auto-generated binding**

    :param int eOrigin:
    :returns: (str) Return value
    :SteamWorks: `GetStringForXboxOrigin <https://partner.steamgames.com/doc/api/ISteamController#GetStringForXboxOrigin>`_

.. function:: Controller.Init()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `Init <https://partner.steamgames.com/doc/api/ISteamController#Init>`_

**Example**::

    Steam.Controller.Init()

.. function:: Controller.RunFrame()

    🤖 **Auto-generated binding**

    :SteamWorks: `RunFrame <https://partner.steamgames.com/doc/api/ISteamController#RunFrame>`_

**Example**::

    -- Call once per frame in your game loop
    Steam.Controller.RunFrame()

.. function:: Controller.SetLEDColor(controllerHandle, nColorR, nColorG, nColorB, nFlags)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :param int nColorR:
    :param int nColorG:
    :param int nColorB:
    :param int nFlags:
    :SteamWorks: `SetLEDColor <https://partner.steamgames.com/doc/api/ISteamController#SetLEDColor>`_

**Example**::

    -- Red LED for low health
    Steam.Controller.SetLEDColor(controllerHandle, 255, 0, 0, 0)

.. function:: Controller.ShowBindingPanel(controllerHandle)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :returns: (bool) Return value
    :SteamWorks: `ShowBindingPanel <https://partner.steamgames.com/doc/api/ISteamController#ShowBindingPanel>`_

**Example**::

    Steam.Controller.ShowBindingPanel(controllerHandle)

.. function:: Controller.Shutdown()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `Shutdown <https://partner.steamgames.com/doc/api/ISteamController#Shutdown>`_

**Example**::

    Steam.Controller.Shutdown()

.. function:: Controller.StopAnalogActionMomentum(controllerHandle, eAction)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :param uint64 eAction:
    :SteamWorks: `StopAnalogActionMomentum <https://partner.steamgames.com/doc/api/ISteamController#StopAnalogActionMomentum>`_

.. function:: Controller.TranslateActionOrigin(eDestinationInputType, eSourceOrigin)

    🤖 **Auto-generated binding**

    :param int eDestinationInputType:
    :param int eSourceOrigin:
    :returns: (int) Return value
    :SteamWorks: `TranslateActionOrigin <https://partner.steamgames.com/doc/api/ISteamController#TranslateActionOrigin>`_

.. function:: Controller.TriggerHapticPulse(controllerHandle, eTargetPad, usDurationMicroSec)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :param int eTargetPad:
    :param int usDurationMicroSec:
    :SteamWorks: `TriggerHapticPulse <https://partner.steamgames.com/doc/api/ISteamController#TriggerHapticPulse>`_

**Example**::

    Steam.Controller.TriggerHapticPulse(controllerHandle, Steam.k_ESteamControllerPad_Right, 1000)

.. function:: Controller.TriggerRepeatedHapticPulse(controllerHandle, eTargetPad, usDurationMicroSec, usOffMicroSec, unRepeat, nFlags)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :param int eTargetPad:
    :param int usDurationMicroSec:
    :param int usOffMicroSec:
    :param int unRepeat:
    :param int nFlags:
    :SteamWorks: `TriggerRepeatedHapticPulse <https://partner.steamgames.com/doc/api/ISteamController#TriggerRepeatedHapticPulse>`_

.. function:: Controller.TriggerVibration(controllerHandle, usLeftSpeed, usRightSpeed)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :param int usLeftSpeed:
    :param int usRightSpeed:
    :SteamWorks: `TriggerVibration <https://partner.steamgames.com/doc/api/ISteamController#TriggerVibration>`_

**Example**::

    Steam.Controller.TriggerVibration(controllerHandle, 16000, 16000)

