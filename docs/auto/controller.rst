################
ISteamController
################

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✋ require manual implementation.

List of Functions
-----------------

* :func:`Controller.Init`
* :func:`Controller.Shutdown`
* :func:`Controller.RunFrame`
* :func:`Controller.GetConnectedControllers`
* :func:`Controller.GetActionSetHandle`
* :func:`Controller.ActivateActionSet`
* :func:`Controller.GetCurrentActionSet`
* :func:`Controller.ActivateActionSetLayer`
* :func:`Controller.DeactivateActionSetLayer`
* :func:`Controller.DeactivateAllActionSetLayers`
* :func:`Controller.GetActiveActionSetLayers`
* :func:`Controller.GetDigitalActionHandle`
* :func:`Controller.GetDigitalActionData`
* :func:`Controller.GetDigitalActionOrigins`
* :func:`Controller.GetAnalogActionHandle`
* :func:`Controller.GetAnalogActionData`
* :func:`Controller.GetAnalogActionOrigins`
* :func:`Controller.GetGlyphForActionOrigin`
* :func:`Controller.GetStringForActionOrigin`
* :func:`Controller.StopAnalogActionMomentum`
* :func:`Controller.GetMotionData`
* :func:`Controller.TriggerHapticPulse`
* :func:`Controller.TriggerRepeatedHapticPulse`
* :func:`Controller.TriggerVibration`
* :func:`Controller.SetLEDColor`
* :func:`Controller.ShowBindingPanel`
* :func:`Controller.GetInputTypeForHandle`
* :func:`Controller.GetControllerForGamepadIndex`
* :func:`Controller.GetGamepadIndexForController`
* :func:`Controller.GetStringForXboxOrigin`
* :func:`Controller.GetGlyphForXboxOrigin`
* :func:`Controller.GetActionOriginFromXboxOrigin`
* :func:`Controller.TranslateActionOrigin`
* :func:`Controller.GetControllerBindingRevision`

Function Reference
------------------

.. function:: Controller.Init()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `Init <https://partner.steamgames.com/doc/api/ISteamController#Init>`_

.. function:: Controller.Shutdown()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `Shutdown <https://partner.steamgames.com/doc/api/ISteamController#Shutdown>`_

.. function:: Controller.RunFrame()

    🤖 **Auto-generated binding**

    :SteamWorks: `RunFrame <https://partner.steamgames.com/doc/api/ISteamController#RunFrame>`_

.. function:: Controller.GetConnectedControllers()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :returns: (uint64[]) Value for `handlesOut`
    :SteamWorks: `GetConnectedControllers <https://partner.steamgames.com/doc/api/ISteamController#GetConnectedControllers>`_

    **Signature differences from C++ API:**

    * Parameter ``handlesOut`` is no longer a paramer, and is instead an additional return value

.. function:: Controller.GetActionSetHandle(pszActionSetName)

    🤖 **Auto-generated binding**

    :param str pszActionSetName:
    :returns: (uint64) Return value
    :SteamWorks: `GetActionSetHandle <https://partner.steamgames.com/doc/api/ISteamController#GetActionSetHandle>`_

.. function:: Controller.ActivateActionSet(controllerHandle, actionSetHandle)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :param uint64 actionSetHandle:
    :SteamWorks: `ActivateActionSet <https://partner.steamgames.com/doc/api/ISteamController#ActivateActionSet>`_

.. function:: Controller.GetCurrentActionSet(controllerHandle)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :returns: (uint64) Return value
    :SteamWorks: `GetCurrentActionSet <https://partner.steamgames.com/doc/api/ISteamController#GetCurrentActionSet>`_

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

.. function:: Controller.GetActiveActionSetLayers(controllerHandle)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :returns: (int) Return value
    :returns: (uint64[]) Value for `handlesOut`
    :SteamWorks: `GetActiveActionSetLayers <https://partner.steamgames.com/doc/api/ISteamController#GetActiveActionSetLayers>`_

    **Signature differences from C++ API:**

    * Parameter ``handlesOut`` is no longer a paramer, and is instead an additional return value

.. function:: Controller.GetDigitalActionHandle(pszActionName)

    🤖 **Auto-generated binding**

    :param str pszActionName:
    :returns: (uint64) Return value
    :SteamWorks: `GetDigitalActionHandle <https://partner.steamgames.com/doc/api/ISteamController#GetDigitalActionHandle>`_

.. function:: Controller.GetDigitalActionData(controllerHandle, digitalActionHandle)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :param uint64 digitalActionHandle:
    :returns: (:ref:`InputDigitalActionData_t <struct-InputDigitalActionData_t>`) Return value
    :SteamWorks: `GetDigitalActionData <https://partner.steamgames.com/doc/api/ISteamController#GetDigitalActionData>`_

.. function:: Controller.GetDigitalActionOrigins(controllerHandle, actionSetHandle, digitalActionHandle)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :param uint64 actionSetHandle:
    :param uint64 digitalActionHandle:
    :returns: (int) Return value
    :returns: (int[]) Value for `originsOut`
    :SteamWorks: `GetDigitalActionOrigins <https://partner.steamgames.com/doc/api/ISteamController#GetDigitalActionOrigins>`_

    **Signature differences from C++ API:**

    * Parameter ``originsOut`` is no longer a paramer, and is instead an additional return value

.. function:: Controller.GetAnalogActionHandle(pszActionName)

    🤖 **Auto-generated binding**

    :param str pszActionName:
    :returns: (uint64) Return value
    :SteamWorks: `GetAnalogActionHandle <https://partner.steamgames.com/doc/api/ISteamController#GetAnalogActionHandle>`_

.. function:: Controller.GetAnalogActionData(controllerHandle, analogActionHandle)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :param uint64 analogActionHandle:
    :returns: (:ref:`InputAnalogActionData_t <struct-InputAnalogActionData_t>`) Return value
    :SteamWorks: `GetAnalogActionData <https://partner.steamgames.com/doc/api/ISteamController#GetAnalogActionData>`_

.. function:: Controller.GetAnalogActionOrigins(controllerHandle, actionSetHandle, analogActionHandle)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :param uint64 actionSetHandle:
    :param uint64 analogActionHandle:
    :returns: (int) Return value
    :returns: (int[]) Value for `originsOut`
    :SteamWorks: `GetAnalogActionOrigins <https://partner.steamgames.com/doc/api/ISteamController#GetAnalogActionOrigins>`_

    **Signature differences from C++ API:**

    * Parameter ``originsOut`` is no longer a paramer, and is instead an additional return value

.. function:: Controller.GetGlyphForActionOrigin(eOrigin)

    🤖 **Auto-generated binding**

    :param int eOrigin:
    :returns: (str) Return value
    :SteamWorks: `GetGlyphForActionOrigin <https://partner.steamgames.com/doc/api/ISteamController#GetGlyphForActionOrigin>`_

.. function:: Controller.GetStringForActionOrigin(eOrigin)

    🤖 **Auto-generated binding**

    :param int eOrigin:
    :returns: (str) Return value
    :SteamWorks: `GetStringForActionOrigin <https://partner.steamgames.com/doc/api/ISteamController#GetStringForActionOrigin>`_

.. function:: Controller.StopAnalogActionMomentum(controllerHandle, eAction)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :param uint64 eAction:
    :SteamWorks: `StopAnalogActionMomentum <https://partner.steamgames.com/doc/api/ISteamController#StopAnalogActionMomentum>`_

.. function:: Controller.GetMotionData(controllerHandle)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :returns: (:ref:`InputMotionData_t <struct-InputMotionData_t>`) Return value
    :SteamWorks: `GetMotionData <https://partner.steamgames.com/doc/api/ISteamController#GetMotionData>`_

.. function:: Controller.TriggerHapticPulse(controllerHandle, eTargetPad, usDurationMicroSec)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :param int eTargetPad:
    :param int usDurationMicroSec:
    :SteamWorks: `TriggerHapticPulse <https://partner.steamgames.com/doc/api/ISteamController#TriggerHapticPulse>`_

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

.. function:: Controller.SetLEDColor(controllerHandle, nColorR, nColorG, nColorB, nFlags)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :param int nColorR:
    :param int nColorG:
    :param int nColorB:
    :param int nFlags:
    :SteamWorks: `SetLEDColor <https://partner.steamgames.com/doc/api/ISteamController#SetLEDColor>`_

.. function:: Controller.ShowBindingPanel(controllerHandle)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :returns: (bool) Return value
    :SteamWorks: `ShowBindingPanel <https://partner.steamgames.com/doc/api/ISteamController#ShowBindingPanel>`_

.. function:: Controller.GetInputTypeForHandle(controllerHandle)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :returns: (int) Return value
    :SteamWorks: `GetInputTypeForHandle <https://partner.steamgames.com/doc/api/ISteamController#GetInputTypeForHandle>`_

.. function:: Controller.GetControllerForGamepadIndex(nIndex)

    🤖 **Auto-generated binding**

    :param int nIndex:
    :returns: (uint64) Return value
    :SteamWorks: `GetControllerForGamepadIndex <https://partner.steamgames.com/doc/api/ISteamController#GetControllerForGamepadIndex>`_

.. function:: Controller.GetGamepadIndexForController(ulControllerHandle)

    🤖 **Auto-generated binding**

    :param uint64 ulControllerHandle:
    :returns: (int) Return value
    :SteamWorks: `GetGamepadIndexForController <https://partner.steamgames.com/doc/api/ISteamController#GetGamepadIndexForController>`_

.. function:: Controller.GetStringForXboxOrigin(eOrigin)

    🤖 **Auto-generated binding**

    :param int eOrigin:
    :returns: (str) Return value
    :SteamWorks: `GetStringForXboxOrigin <https://partner.steamgames.com/doc/api/ISteamController#GetStringForXboxOrigin>`_

.. function:: Controller.GetGlyphForXboxOrigin(eOrigin)

    🤖 **Auto-generated binding**

    :param int eOrigin:
    :returns: (str) Return value
    :SteamWorks: `GetGlyphForXboxOrigin <https://partner.steamgames.com/doc/api/ISteamController#GetGlyphForXboxOrigin>`_

.. function:: Controller.GetActionOriginFromXboxOrigin(controllerHandle, eOrigin)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :param int eOrigin:
    :returns: (int) Return value
    :SteamWorks: `GetActionOriginFromXboxOrigin <https://partner.steamgames.com/doc/api/ISteamController#GetActionOriginFromXboxOrigin>`_

.. function:: Controller.TranslateActionOrigin(eDestinationInputType, eSourceOrigin)

    🤖 **Auto-generated binding**

    :param int eDestinationInputType:
    :param int eSourceOrigin:
    :returns: (int) Return value
    :SteamWorks: `TranslateActionOrigin <https://partner.steamgames.com/doc/api/ISteamController#TranslateActionOrigin>`_

.. function:: Controller.GetControllerBindingRevision(controllerHandle)

    🤖 **Auto-generated binding**

    :param uint64 controllerHandle:
    :returns: (bool) Return value
    :returns: (int) Value for `pMajor`
    :returns: (int) Value for `pMinor`
    :SteamWorks: `GetControllerBindingRevision <https://partner.steamgames.com/doc/api/ISteamController#GetControllerBindingRevision>`_

    **Signature differences from C++ API:**

    * Parameter ``pMajor`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pMinor`` is no longer a paramer, and is instead an additional return value

