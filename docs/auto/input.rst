###########
ISteamInput
###########

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✋ require manual implementation.

.. note::
   Overloaded Steam methods are exposed as distinct Lua functions using a type suffix (for example ``GetStatInt32`` and ``SetStatFloat``).

List of Functions
-----------------

* :func:`Input.Init`
* :func:`Input.Shutdown`
* :func:`Input.SetInputActionManifestFilePath`
* :func:`Input.RunFrame`
* :func:`Input.BWaitForData`
* :func:`Input.BNewDataAvailable`
* :func:`Input.GetConnectedControllers`
* :func:`Input.EnableDeviceCallbacks`
* :func:`Input.GetActionSetHandle`
* :func:`Input.ActivateActionSet`
* :func:`Input.GetCurrentActionSet`
* :func:`Input.ActivateActionSetLayer`
* :func:`Input.DeactivateActionSetLayer`
* :func:`Input.DeactivateAllActionSetLayers`
* :func:`Input.GetActiveActionSetLayers`
* :func:`Input.GetDigitalActionHandle`
* :func:`Input.GetDigitalActionData`
* :func:`Input.GetDigitalActionOrigins`
* :func:`Input.GetStringForDigitalActionName`
* :func:`Input.GetAnalogActionHandle`
* :func:`Input.GetAnalogActionData`
* :func:`Input.GetAnalogActionOrigins`
* :func:`Input.GetGlyphPNGForActionOrigin`
* :func:`Input.GetGlyphSVGForActionOrigin`
* :func:`Input.GetGlyphForActionOrigin_Legacy`
* :func:`Input.GetStringForActionOrigin`
* :func:`Input.GetStringForAnalogActionName`
* :func:`Input.StopAnalogActionMomentum`
* :func:`Input.GetMotionData`
* :func:`Input.TriggerVibration`
* :func:`Input.TriggerVibrationExtended`
* :func:`Input.TriggerSimpleHapticEvent`
* :func:`Input.SetLEDColor`
* :func:`Input.Legacy_TriggerHapticPulse`
* :func:`Input.Legacy_TriggerRepeatedHapticPulse`
* :func:`Input.ShowBindingPanel`
* :func:`Input.GetInputTypeForHandle`
* :func:`Input.GetControllerForGamepadIndex`
* :func:`Input.GetGamepadIndexForController`
* :func:`Input.GetStringForXboxOrigin`
* :func:`Input.GetGlyphForXboxOrigin`
* :func:`Input.GetActionOriginFromXboxOrigin`
* :func:`Input.TranslateActionOrigin`
* :func:`Input.GetDeviceBindingRevision`
* :func:`Input.GetRemotePlaySessionID`
* :func:`Input.GetSessionInputConfigurationSettings`

List of Callbacks
-----------------

* :func:`Input.onSteamInputDeviceConnected`
* :func:`Input.onSteamInputDeviceDisconnected`
* :func:`Input.onSteamInputConfigurationLoaded`
* :func:`Input.onSteamInputGamepadSlotChange`

Function Reference
------------------

.. function:: Input.Init(bExplicitlyCallRunFrame)

    🤖 **Auto-generated binding**

    :param bool bExplicitlyCallRunFrame:
    :returns: (bool) Return value
    :SteamWorks: `Init <https://partner.steamgames.com/doc/api/ISteamInput#Init>`_

.. function:: Input.Shutdown()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `Shutdown <https://partner.steamgames.com/doc/api/ISteamInput#Shutdown>`_

.. function:: Input.SetInputActionManifestFilePath(pchInputActionManifestAbsolutePath)

    🤖 **Auto-generated binding**

    :param str pchInputActionManifestAbsolutePath:
    :returns: (bool) Return value
    :SteamWorks: `SetInputActionManifestFilePath <https://partner.steamgames.com/doc/api/ISteamInput#SetInputActionManifestFilePath>`_

.. function:: Input.RunFrame(bReservedValue)

    🤖 **Auto-generated binding**

    :param bool bReservedValue:
    :SteamWorks: `RunFrame <https://partner.steamgames.com/doc/api/ISteamInput#RunFrame>`_

.. function:: Input.BWaitForData(bWaitForever, unTimeout)

    🤖 **Auto-generated binding**

    :param bool bWaitForever:
    :param int unTimeout:
    :returns: (bool) Return value
    :SteamWorks: `BWaitForData <https://partner.steamgames.com/doc/api/ISteamInput#BWaitForData>`_

.. function:: Input.BNewDataAvailable()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BNewDataAvailable <https://partner.steamgames.com/doc/api/ISteamInput#BNewDataAvailable>`_

.. function:: Input.GetConnectedControllers()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :returns: (uint64[]) Value for `handlesOut`
    :SteamWorks: `GetConnectedControllers <https://partner.steamgames.com/doc/api/ISteamInput#GetConnectedControllers>`_

    **Signature differences from C++ API:**

    * Parameter ``handlesOut`` is returned as an additional return value

.. function:: Input.EnableDeviceCallbacks()

    🤖 **Auto-generated binding**

    :SteamWorks: `EnableDeviceCallbacks <https://partner.steamgames.com/doc/api/ISteamInput#EnableDeviceCallbacks>`_

.. function:: Input.GetActionSetHandle(pszActionSetName)

    🤖 **Auto-generated binding**

    :param str pszActionSetName:
    :returns: (uint64) Return value
    :SteamWorks: `GetActionSetHandle <https://partner.steamgames.com/doc/api/ISteamInput#GetActionSetHandle>`_

.. function:: Input.ActivateActionSet(inputHandle, actionSetHandle)

    🤖 **Auto-generated binding**

    :param uint64 inputHandle:
    :param uint64 actionSetHandle:
    :SteamWorks: `ActivateActionSet <https://partner.steamgames.com/doc/api/ISteamInput#ActivateActionSet>`_

.. function:: Input.GetCurrentActionSet(inputHandle)

    🤖 **Auto-generated binding**

    :param uint64 inputHandle:
    :returns: (uint64) Return value
    :SteamWorks: `GetCurrentActionSet <https://partner.steamgames.com/doc/api/ISteamInput#GetCurrentActionSet>`_

.. function:: Input.ActivateActionSetLayer(inputHandle, actionSetLayerHandle)

    🤖 **Auto-generated binding**

    :param uint64 inputHandle:
    :param uint64 actionSetLayerHandle:
    :SteamWorks: `ActivateActionSetLayer <https://partner.steamgames.com/doc/api/ISteamInput#ActivateActionSetLayer>`_

.. function:: Input.DeactivateActionSetLayer(inputHandle, actionSetLayerHandle)

    🤖 **Auto-generated binding**

    :param uint64 inputHandle:
    :param uint64 actionSetLayerHandle:
    :SteamWorks: `DeactivateActionSetLayer <https://partner.steamgames.com/doc/api/ISteamInput#DeactivateActionSetLayer>`_

.. function:: Input.DeactivateAllActionSetLayers(inputHandle)

    🤖 **Auto-generated binding**

    :param uint64 inputHandle:
    :SteamWorks: `DeactivateAllActionSetLayers <https://partner.steamgames.com/doc/api/ISteamInput#DeactivateAllActionSetLayers>`_

.. function:: Input.GetActiveActionSetLayers(inputHandle)

    🤖 **Auto-generated binding**

    :param uint64 inputHandle:
    :returns: (int) Return value
    :returns: (uint64[]) Value for `handlesOut`
    :SteamWorks: `GetActiveActionSetLayers <https://partner.steamgames.com/doc/api/ISteamInput#GetActiveActionSetLayers>`_

    **Signature differences from C++ API:**

    * Parameter ``handlesOut`` is returned as an additional return value

.. function:: Input.GetDigitalActionHandle(pszActionName)

    🤖 **Auto-generated binding**

    :param str pszActionName:
    :returns: (uint64) Return value
    :SteamWorks: `GetDigitalActionHandle <https://partner.steamgames.com/doc/api/ISteamInput#GetDigitalActionHandle>`_

.. function:: Input.GetDigitalActionData(inputHandle, digitalActionHandle)

    🤖 **Auto-generated binding**

    :param uint64 inputHandle:
    :param uint64 digitalActionHandle:
    :returns: (:ref:`InputDigitalActionData_t <struct-InputDigitalActionData_t>`) Return value
    :SteamWorks: `GetDigitalActionData <https://partner.steamgames.com/doc/api/ISteamInput#GetDigitalActionData>`_

.. function:: Input.GetDigitalActionOrigins(inputHandle, actionSetHandle, digitalActionHandle)

    🤖 **Auto-generated binding**

    :param uint64 inputHandle:
    :param uint64 actionSetHandle:
    :param uint64 digitalActionHandle:
    :returns: (int) Return value
    :returns: (int[]) Value for `originsOut`
    :SteamWorks: `GetDigitalActionOrigins <https://partner.steamgames.com/doc/api/ISteamInput#GetDigitalActionOrigins>`_

    **Signature differences from C++ API:**

    * Parameter ``originsOut`` is returned as an additional return value

.. function:: Input.GetStringForDigitalActionName(eActionHandle)

    🤖 **Auto-generated binding**

    :param uint64 eActionHandle:
    :returns: (str) Return value
    :SteamWorks: `GetStringForDigitalActionName <https://partner.steamgames.com/doc/api/ISteamInput#GetStringForDigitalActionName>`_

.. function:: Input.GetAnalogActionHandle(pszActionName)

    🤖 **Auto-generated binding**

    :param str pszActionName:
    :returns: (uint64) Return value
    :SteamWorks: `GetAnalogActionHandle <https://partner.steamgames.com/doc/api/ISteamInput#GetAnalogActionHandle>`_

.. function:: Input.GetAnalogActionData(inputHandle, analogActionHandle)

    🤖 **Auto-generated binding**

    :param uint64 inputHandle:
    :param uint64 analogActionHandle:
    :returns: (:ref:`InputAnalogActionData_t <struct-InputAnalogActionData_t>`) Return value
    :SteamWorks: `GetAnalogActionData <https://partner.steamgames.com/doc/api/ISteamInput#GetAnalogActionData>`_

.. function:: Input.GetAnalogActionOrigins(inputHandle, actionSetHandle, analogActionHandle)

    🤖 **Auto-generated binding**

    :param uint64 inputHandle:
    :param uint64 actionSetHandle:
    :param uint64 analogActionHandle:
    :returns: (int) Return value
    :returns: (int[]) Value for `originsOut`
    :SteamWorks: `GetAnalogActionOrigins <https://partner.steamgames.com/doc/api/ISteamInput#GetAnalogActionOrigins>`_

    **Signature differences from C++ API:**

    * Parameter ``originsOut`` is returned as an additional return value

.. function:: Input.GetGlyphPNGForActionOrigin(eOrigin, eSize, unFlags)

    🤖 **Auto-generated binding**

    :param int eOrigin:
    :param int eSize:
    :param int unFlags:
    :returns: (str) Return value
    :SteamWorks: `GetGlyphPNGForActionOrigin <https://partner.steamgames.com/doc/api/ISteamInput#GetGlyphPNGForActionOrigin>`_

.. function:: Input.GetGlyphSVGForActionOrigin(eOrigin, unFlags)

    🤖 **Auto-generated binding**

    :param int eOrigin:
    :param int unFlags:
    :returns: (str) Return value
    :SteamWorks: `GetGlyphSVGForActionOrigin <https://partner.steamgames.com/doc/api/ISteamInput#GetGlyphSVGForActionOrigin>`_

.. function:: Input.GetGlyphForActionOrigin_Legacy(eOrigin)

    🤖 **Auto-generated binding**

    :param int eOrigin:
    :returns: (str) Return value
    :SteamWorks: `GetGlyphForActionOrigin_Legacy <https://partner.steamgames.com/doc/api/ISteamInput#GetGlyphForActionOrigin_Legacy>`_

.. function:: Input.GetStringForActionOrigin(eOrigin)

    🤖 **Auto-generated binding**

    :param int eOrigin:
    :returns: (str) Return value
    :SteamWorks: `GetStringForActionOrigin <https://partner.steamgames.com/doc/api/ISteamInput#GetStringForActionOrigin>`_

.. function:: Input.GetStringForAnalogActionName(eActionHandle)

    🤖 **Auto-generated binding**

    :param uint64 eActionHandle:
    :returns: (str) Return value
    :SteamWorks: `GetStringForAnalogActionName <https://partner.steamgames.com/doc/api/ISteamInput#GetStringForAnalogActionName>`_

.. function:: Input.StopAnalogActionMomentum(inputHandle, eAction)

    🤖 **Auto-generated binding**

    :param uint64 inputHandle:
    :param uint64 eAction:
    :SteamWorks: `StopAnalogActionMomentum <https://partner.steamgames.com/doc/api/ISteamInput#StopAnalogActionMomentum>`_

.. function:: Input.GetMotionData(inputHandle)

    🤖 **Auto-generated binding**

    :param uint64 inputHandle:
    :returns: (:ref:`InputMotionData_t <struct-InputMotionData_t>`) Return value
    :SteamWorks: `GetMotionData <https://partner.steamgames.com/doc/api/ISteamInput#GetMotionData>`_

.. function:: Input.TriggerVibration(inputHandle, usLeftSpeed, usRightSpeed)

    🤖 **Auto-generated binding**

    :param uint64 inputHandle:
    :param int usLeftSpeed:
    :param int usRightSpeed:
    :SteamWorks: `TriggerVibration <https://partner.steamgames.com/doc/api/ISteamInput#TriggerVibration>`_

.. function:: Input.TriggerVibrationExtended(inputHandle, usLeftSpeed, usRightSpeed, usLeftTriggerSpeed, usRightTriggerSpeed)

    🤖 **Auto-generated binding**

    :param uint64 inputHandle:
    :param int usLeftSpeed:
    :param int usRightSpeed:
    :param int usLeftTriggerSpeed:
    :param int usRightTriggerSpeed:
    :SteamWorks: `TriggerVibrationExtended <https://partner.steamgames.com/doc/api/ISteamInput#TriggerVibrationExtended>`_

.. function:: Input.TriggerSimpleHapticEvent(inputHandle, eHapticLocation, nIntensity, nGainDB, nOtherIntensity, nOtherGainDB)

    🤖 **Auto-generated binding**

    :param uint64 inputHandle:
    :param int eHapticLocation:
    :param int nIntensity:
    :param str nGainDB:
    :param int nOtherIntensity:
    :param str nOtherGainDB:
    :SteamWorks: `TriggerSimpleHapticEvent <https://partner.steamgames.com/doc/api/ISteamInput#TriggerSimpleHapticEvent>`_

.. function:: Input.SetLEDColor(inputHandle, nColorR, nColorG, nColorB, nFlags)

    🤖 **Auto-generated binding**

    :param uint64 inputHandle:
    :param int nColorR:
    :param int nColorG:
    :param int nColorB:
    :param int nFlags:
    :SteamWorks: `SetLEDColor <https://partner.steamgames.com/doc/api/ISteamInput#SetLEDColor>`_

.. function:: Input.Legacy_TriggerHapticPulse(inputHandle, eTargetPad, usDurationMicroSec)

    🤖 **Auto-generated binding**

    :param uint64 inputHandle:
    :param int eTargetPad:
    :param int usDurationMicroSec:
    :SteamWorks: `Legacy_TriggerHapticPulse <https://partner.steamgames.com/doc/api/ISteamInput#Legacy_TriggerHapticPulse>`_

.. function:: Input.Legacy_TriggerRepeatedHapticPulse(inputHandle, eTargetPad, usDurationMicroSec, usOffMicroSec, unRepeat, nFlags)

    🤖 **Auto-generated binding**

    :param uint64 inputHandle:
    :param int eTargetPad:
    :param int usDurationMicroSec:
    :param int usOffMicroSec:
    :param int unRepeat:
    :param int nFlags:
    :SteamWorks: `Legacy_TriggerRepeatedHapticPulse <https://partner.steamgames.com/doc/api/ISteamInput#Legacy_TriggerRepeatedHapticPulse>`_

.. function:: Input.ShowBindingPanel(inputHandle)

    🤖 **Auto-generated binding**

    :param uint64 inputHandle:
    :returns: (bool) Return value
    :SteamWorks: `ShowBindingPanel <https://partner.steamgames.com/doc/api/ISteamInput#ShowBindingPanel>`_

.. function:: Input.GetInputTypeForHandle(inputHandle)

    🤖 **Auto-generated binding**

    :param uint64 inputHandle:
    :returns: (int) Return value
    :SteamWorks: `GetInputTypeForHandle <https://partner.steamgames.com/doc/api/ISteamInput#GetInputTypeForHandle>`_

.. function:: Input.GetControllerForGamepadIndex(nIndex)

    🤖 **Auto-generated binding**

    :param int nIndex:
    :returns: (uint64) Return value
    :SteamWorks: `GetControllerForGamepadIndex <https://partner.steamgames.com/doc/api/ISteamInput#GetControllerForGamepadIndex>`_

.. function:: Input.GetGamepadIndexForController(ulinputHandle)

    🤖 **Auto-generated binding**

    :param uint64 ulinputHandle:
    :returns: (int) Return value
    :SteamWorks: `GetGamepadIndexForController <https://partner.steamgames.com/doc/api/ISteamInput#GetGamepadIndexForController>`_

.. function:: Input.GetStringForXboxOrigin(eOrigin)

    🤖 **Auto-generated binding**

    :param int eOrigin:
    :returns: (str) Return value
    :SteamWorks: `GetStringForXboxOrigin <https://partner.steamgames.com/doc/api/ISteamInput#GetStringForXboxOrigin>`_

.. function:: Input.GetGlyphForXboxOrigin(eOrigin)

    🤖 **Auto-generated binding**

    :param int eOrigin:
    :returns: (str) Return value
    :SteamWorks: `GetGlyphForXboxOrigin <https://partner.steamgames.com/doc/api/ISteamInput#GetGlyphForXboxOrigin>`_

.. function:: Input.GetActionOriginFromXboxOrigin(inputHandle, eOrigin)

    🤖 **Auto-generated binding**

    :param uint64 inputHandle:
    :param int eOrigin:
    :returns: (int) Return value
    :SteamWorks: `GetActionOriginFromXboxOrigin <https://partner.steamgames.com/doc/api/ISteamInput#GetActionOriginFromXboxOrigin>`_

.. function:: Input.TranslateActionOrigin(eDestinationInputType, eSourceOrigin)

    🤖 **Auto-generated binding**

    :param int eDestinationInputType:
    :param int eSourceOrigin:
    :returns: (int) Return value
    :SteamWorks: `TranslateActionOrigin <https://partner.steamgames.com/doc/api/ISteamInput#TranslateActionOrigin>`_

.. function:: Input.GetDeviceBindingRevision(inputHandle)

    🤖 **Auto-generated binding**

    :param uint64 inputHandle:
    :returns: (bool) Return value
    :returns: (int) Value for `pMajor`
    :returns: (int) Value for `pMinor`
    :SteamWorks: `GetDeviceBindingRevision <https://partner.steamgames.com/doc/api/ISteamInput#GetDeviceBindingRevision>`_

    **Signature differences from C++ API:**

    * Parameter ``pMajor`` is returned as an additional return value
    * Parameter ``pMinor`` is returned as an additional return value

.. function:: Input.GetRemotePlaySessionID(inputHandle)

    🤖 **Auto-generated binding**

    :param uint64 inputHandle:
    :returns: (int) Return value
    :SteamWorks: `GetRemotePlaySessionID <https://partner.steamgames.com/doc/api/ISteamInput#GetRemotePlaySessionID>`_

.. function:: Input.GetSessionInputConfigurationSettings()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetSessionInputConfigurationSettings <https://partner.steamgames.com/doc/api/ISteamInput#GetSessionInputConfigurationSettings>`_


Unimplemented Methods
---------------------

.. function:: Input.enableActionEventCallbacks

    ✋ **Not implemented** - unsupported type: SteamInputActionEventCallbackPointer
    
    :SteamWorks: `EnableActionEventCallbacks <https://partner.steamgames.com/doc/api/ISteamInput#EnableActionEventCallbacks>`_

.. function:: Input.setDualSenseTriggerEffect

    ✋ **Not implemented** - unsupported type: const ScePadTriggerEffectParam *
    
    :SteamWorks: `SetDualSenseTriggerEffect <https://partner.steamgames.com/doc/api/ISteamInput#SetDualSenseTriggerEffect>`_


Callbacks
---------

.. function:: Input.onSteamInputDeviceConnected

    Callback for `SteamInputDeviceConnected_t <https://partner.steamgames.com/doc/api/ISteamInput#SteamInputDeviceConnected_t>`_

    **callback(data)** receives:

    * **data.m_ulConnectedDeviceHandle** -- m_ulConnectedDeviceHandle

.. function:: Input.onSteamInputDeviceDisconnected

    Callback for `SteamInputDeviceDisconnected_t <https://partner.steamgames.com/doc/api/ISteamInput#SteamInputDeviceDisconnected_t>`_

    **callback(data)** receives:

    * **data.m_ulDisconnectedDeviceHandle** -- m_ulDisconnectedDeviceHandle

.. function:: Input.onSteamInputConfigurationLoaded

    Callback for `SteamInputConfigurationLoaded_t <https://partner.steamgames.com/doc/api/ISteamInput#SteamInputConfigurationLoaded_t>`_

    **callback(data)** receives:

    * **data.m_unAppID** -- m_unAppID
    * **data.m_ulDeviceHandle** -- m_ulDeviceHandle
    * **data.m_ulMappingCreator** -- m_ulMappingCreator
    * **data.m_unMajorRevision** -- m_unMajorRevision
    * **data.m_unMinorRevision** -- m_unMinorRevision
    * **data.m_bUsesSteamInputAPI** -- m_bUsesSteamInputAPI
    * **data.m_bUsesGamepadAPI** -- m_bUsesGamepadAPI

.. function:: Input.onSteamInputGamepadSlotChange

    Callback for `SteamInputGamepadSlotChange_t <https://partner.steamgames.com/doc/api/ISteamInput#SteamInputGamepadSlotChange_t>`_

    **callback(data)** receives:

    * **data.m_unAppID** -- m_unAppID
    * **data.m_ulDeviceHandle** -- m_ulDeviceHandle
    * **data.m_eDeviceType** -- m_eDeviceType
    * **data.m_nOldGamepadSlot** -- m_nOldGamepadSlot
    * **data.m_nNewGamepadSlot** -- m_nNewGamepadSlot

