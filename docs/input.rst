###############
ISteamInput
###############


List of Functions
-----------------
* :func:`input.init`
* :func:`input.shutdown`
* :func:`input.activateActionSet`
* :func:`input.activateActionSetLayer`
* :func:`input.deactivateActionSetLayer`
* :func:`input.deactivateAllActionSetLayers`
* :func:`input.getActiveActionSetLayers`
* :func:`input.getActionSetHandle`
* :func:`input.getAnalogActionData`
* :func:`input.getAnalogActionHandle`
* :func:`input.getAnalogActionOrigins`
* :func:`input.getConnectedControllers`
* :func:`input.getControllerForGamepadIndex`
* :func:`input.getCurrentActionSet`
* :func:`input.getDigitalActionData`
* :func:`input.getDigitalActionHandle`
* :func:`input.getDigitalActionOrigins`
* :func:`input.getGlyphForActionOrigin_Legacy`
* :func:`input.getInputTypeForHandle`
* :func:`input.getMotionData`
* :func:`input.getStringForActionOrigin`
* :func:`input.runFrame`
* :func:`input.setLEDColor`
* :func:`input.showBindingPanel`
* :func:`input.stopAnalogActionMomentum`
* :func:`input.legacy_triggerHapticPulse`
* :func:`input.legacy_triggerRepeatedHapticPulse`
* :func:`input.triggerVibration`
* :func:`input.getActionOriginFromXboxOrigin`
* :func:`input.translateActionOrigin`
* :func:`input.getDeviceBindingRevision`
* :func:`input.getRemotePlaySessionID`

Function Reference
------------------

.. function:: input.init()
    
    Must be called when starting use of the `ISteamInput` interface.

    :param boolean explicitlyCallRunFrame: If `true`, you will need to manually call input.runFrame() each frame, otherwise Steam Input will call it automatically when Steam.runCallbacks() is called.
    :returns: (`boolean`) Always returns `true`.
    :SteamWorks: `Init <https://partner.steamgames.com/doc/api/isteaminput#Init>`_
    
.. function:: input.shutdown()
    
    Must be called when ending use of the `ISteamInput` interface.

    :returns: (`boolean`) Always returns `true`.
    :SteamWorks: `Shutdown <https://partner.steamgames.com/doc/api/isteaminput#Shutdown>`_

.. function:: input.activateActionSet()
    
    :param uint64 inputHandle: The handle of the controller you want to activate an action set for. Alternatively, pass the string **"all"** to activate all the controllers at once. Obtained from :func:`input.getConnectedControllers`.
    :param uint64 actionSetHandle: The handle of the action set you want to activate. Obtained from :func:`input.getActionSetHandle`. 
    :returns: nothing
    :SteamWorks: `ActivateActionSet <https://partner.steamgames.com/doc/api/isteaminput#ActivateActionSet>`_
    
.. function:: input.activateActionSetLayer()
    
    :param uint64 inputHandle: The handle of the controller you want to activate an action set layer for. Obtained from :func:`input.getConnectedControllers`.
    :param uint64 actionSetLayerHandle: The handle of the action set layer you want to activate. Obtained from :func:`input.getActiveActionSetLayers`. 
    :returns: nothing
    :SteamWorks: `ActivateActionSetLayer <https://partner.steamgames.com/doc/api/isteaminput#ActivateActionSetLayer>`_

.. function:: input.deactivateActionSetLayer()
    
    :param uint64 inputHandle: The handle of the controller you want to deactivate an action set layer for. Obtained from :func:`input.getConnectedControllers`.
    :param uint64 actionSetLayerHandle: The handle of the action set layer you want to deactivate. Obtained from :func:`input.getActiveActionSetLayers`. 
    :returns: nothing
    :SteamWorks: `DeactivateActionSetLayer <https://partner.steamgames.com/doc/api/isteaminput#DeactivateActionSetLayer>`_

.. function:: input.deactivateAllActionSetLayers()
    
    :param uint64 inputHandle: The handle of the controller you want to deactivate all action set layers for. Obtained from :func:`input.getConnectedControllers`.
    :returns: nothing
    :SteamWorks: `DeactivateAllActionSetLayers <https://partner.steamgames.com/doc/api/isteaminput#DeactivateAllActionSetLayers>`_

.. function:: input.getActiveActionSetLayers()
    
    :param uint64 inputHandle: The handle of the controller you want to get active action set layers for. Obtained from :func:`input.getConnectedControllers`.
    :returns: (`table`) An array of `InputActionSetHandle` (more precisely, `uint64`) with all of the currently active action set layers for a specified controller handle.
    :SteamWorks: `GetActiveActionSetLayers <https://partner.steamgames.com/doc/api/isteaminput#GetActiveActionSetLayers>`_

.. function:: input.getActionSetHandle()
    
    :param string actionSetName: The string identifier of an action set defined in the game's VDF file.
    :returns: (`number`) The handle (`InputActionSetHandle`, ie `uint64`) of the specified action set.
    :SteamWorks: `GetActionSetHandle <https://partner.steamgames.com/doc/api/isteaminput#GetActionSetHandle>`_

.. function:: input.getAnalogActionData()
    
    :param uint64 inputHandle: The handle of the controller you want to query. Obtained from :func:`input.getConnectedControllers`.
    :param uint64 analogActionHandle: A handle to an analog action. This can be obtained from :func:`input.getAnalogActionHandle`.
    :returns: (`table`) A table with fields filled with `InputAnalogActionData`; see `InputAnalogActionData_t <https://partner.steamgames.com/doc/api/ISteamInput#InputAnalogActionData_t>`_
    :SteamWorks: `GetAnalogActionData <https://partner.steamgames.com/doc/api/isteaminput#GetAnalogActionData>`_

.. function:: input.getAnalogActionHandle()
    
    :param string actionName: The string identifier of the analog action defined in the game's VDF file.
    :returns: (`number`) The handle (`InputAnalogActionHandle`, ie `uint64`)  of the specified analog action.
    :SteamWorks: `GetAnalogActionHandle <https://partner.steamgames.com/doc/api/isteaminput#GetAnalogActionHandle>`_

.. function:: input.getAnalogActionOrigins()
    
    :param uint64 inputHandle: The handle of the controller you want to query. Obtained from :func:`input.getConnectedControllers`.
    :param uint64 actionSetHandle: The handle of the action set you want to query. This can be obtained from :func:`input.getActionSetHandle`.
    :param uint64 analogActionHandle: The handle of the analog action you want to query. This can be obtained from :func:`input.getAnalogActionHandle`.
    :returns: (`table`) An array filled with origins (`EInputActionOrigin`, ie `string`; see `EInputActionOrigin <https://partner.steamgames.com/doc/api/ISteamInput#EInputActionOrigin>`_) for an analog action within an action set. Use this to display the appropriate on-screen prompt for the action.
    :SteamWorks: `GetAnalogActionOrigins <https://partner.steamgames.com/doc/api/isteaminput#GetAnalogActionOrigins>`_

.. function:: input.getConnectedControllers()
    
    :returns: (`table`) An array filled with the `inputHandles` (`uint64`) of currently connected controllers.
    :SteamWorks: `GetConnectedControllers <https://partner.steamgames.com/doc/api/isteaminput#GetConnectedControllers>`_

.. function:: input.getControllerForGamepadIndex()
    
    :param int index: The index of the emulated gamepad you want to get a controller handle for.
    :returns: (`number`) The `inputHandle` (`uint64`) of the associated controller handle for the specified emulated gamepad. Can be used with GetInputTypeForHandle to determine the controller type of a controller using Steam Input Gamepad Emulation.
    :SteamWorks: `GetControllerForGamepadIndex <https://partner.steamgames.com/doc/api/isteaminput#GetControllerForGamepadIndex>`_

.. function:: input.getCurrentActionSet()
    
    :param uint64 inputHandle: The handle of the controller you want to query. Obtained from :func:`input.getConnectedControllers`.
    :returns: (`number`) The `InputActionSetHandle` (`uint64`) handle of the action set activated for the specified controller.
    :SteamWorks: `GetCurrentActionSet <https://partner.steamgames.com/doc/api/isteaminput#GetCurrentActionSet>`_

.. function:: input.getDigitalActionData()
    
    :param uint64 inputHandle: The handle of the controller you want to query. Obtained from :func:`input.getConnectedControllers`.
    :param uint64 digitalActionHandle: The handle of the controller you want to query.  This can be obtained from :func:`input.getDigitalActionHandle`.
    :returns: (`table`) The current state (`InputDigitalActionData`, see `InputDigitalActionData_t <https://partner.steamgames.com/doc/api/isteaminput#InputDigitalActionData_t>`_) of the supplied digital game action.
    :SteamWorks: `GetDigitalActionData <https://partner.steamgames.com/doc/api/isteaminput#GetDigitalActionData>`_

.. function:: input.getDigitalActionHandle()
    
    :param string actionName: The string identifier of the digital action defined in the game's VDF file.
    :returns: (`number`) The handle (`InputDigitalActionHandle`, ie `uint64`)  of the specified digital action.
    :SteamWorks: `GetDigitalActionHandle <https://partner.steamgames.com/doc/api/isteaminput#GetDigitalActionHandle>`_

.. function:: input.getDigitalActionOrigins()
    
    :param uint64 inputHandle: The handle of the controller you want to query. Obtained from :func:`input.getConnectedControllers`.
    :param uint64 actionSetHandle: The handle of the action set you want to query. This can be obtained from :func:`input.getActionSetHandle`.
    :param uint64 digitalActionHandle: The handle of the digital action you want to query. This can be obtained from :func:`input.getDigitalActionHandle`.
    :returns: (`table`) An array filled with origins (`EInputActionOrigin`, ie `string`; see `EInputActionOrigin <https://partner.steamgames.com/doc/api/ISteamInput#EInputActionOrigin>`_) for an :func:`input.getDigitalActionHandle` action within an action set. Use this to display the appropriate on-screen prompt for the action.
    :SteamWorks: `GetDigitalActionOrigins <https://partner.steamgames.com/doc/api/isteaminput#GetDigitalActionOrigins>`_

.. function:: input.getGamepadIndexForController()
    
    :param uint64 inputHandle: The handle of the controller you want to get a gamepad index for. Obtained from :func:`input.getConnectedControllers`.
    :returns: (`number`) The associated gamepad index for the specified controller, if emulating a gamepad.
    :SteamWorks: `GetGamepadIndexForController <https://partner.steamgames.com/doc/api/isteaminput#GetGamepadIndexForController>`_

.. function:: input.getGlyphForActionOrigin_Legacy()
    
    :param string origin: For example, `LeftStick_Click`, `X`, `B`. See `EInputActionOrigin <https://partner.steamgames.com/doc/api/isteaminput#EInputActionOrigin>`_ for reference.
    :returns: (`string`) A local path to art for on-screen glyph for a particular origin.
    :SteamWorks: `GetGlyphForActionOrigin <https://partner.steamgames.com/doc/api/isteaminput#GetGlyphForActionOrigin>`_

.. function:: input.getInputTypeForHandle()
    
    :param uint64 inputHandle: The handle of the controller whose input type (device model) you want to query. Obtained from :func:`input.getConnectedControllers`.
    :returns: (`string`) The input type (device model; see `ESteamInputType <https://partner.steamgames.com/doc/api/isteaminput#ESteamInputType>`_) for the specified controller. This tells you if a given controller is a Steam controller, XBox 360 controller, PS4 controller, etc.
    :SteamWorks: `GetInputTypeForHandle <https://partner.steamgames.com/doc/api/isteaminput#GetInputTypeForHandle>`_

.. function:: input.getMotionData()
    
    :param uint64 inputHandle: 	The handle of the controller you want to get motion data for. Obtained from :func:`input.getConnectedControllers`.
    :returns: (`table`) A table (see `InputMotionData_t <https://partner.steamgames.com/doc/api/isteaminput#InputMotionData_t>`_) filled with raw motion data for the specified controller.
    :SteamWorks: `GetMotionData <https://partner.steamgames.com/doc/api/isteaminput#GetMotionData>`_

.. function:: input.getStringForActionOrigin()
    
    :param string origin: For example, `LeftStick_Click`, `X`, `B`. See `EInputActionOrigin <https://partner.steamgames.com/doc/api/isteaminput#EInputActionOrigin>`_ for reference.
    :returns: (`string`) Returns a localized string (from Steam's language setting) for the specified origin.
    :SteamWorks: `GetStringForActionOrigin <https://partner.steamgames.com/doc/api/isteaminput#GetStringForActionOrigin>`_

.. function:: input.runFrame()
    
    Synchronize API state with the latest Steam Controller inputs available. This is performed automatically by SteamAPI_RunCallbacks, but for the absolute lowest possible latency, you can call this directly before reading controller state.
    
    :returns: nothing
    :SteamWorks: `RunFrame <https://partner.steamgames.com/doc/api/isteaminput#RunFrame>`_

.. function:: input.setLEDColor()
    
    :param uint64 inputHandle: 	The handle of the controller to affect. Obtained from :func:`input.getConnectedControllers`.
    :param uint8 colorR: 	The red component of the color to set (0-255).
    :param uint8 colorG: 	The green component of the color to set (0-255).
    :param uint8 colorB: 	The blue component of the color to set (0-255).
    :param boolean resetColor: If `true`, restores the color to default (out-of-game) settings. Otherwise, set to the presented RGB color.
    :returns: nothing
    :SteamWorks: `SetLEDColor <https://partner.steamgames.com/doc/api/isteaminput#SetLEDColor>`_

.. function:: input.showBindingPanel()
    
    :param uint64 inputHandle: The handle of the controller you want to bring up the binding screen for. Obtained from :func:`input.getConnectedControllers`.
    :returns: (`boolean`) `true` for success; `false` if overlay is disabled/unavailable, or the user is not in Big Picture Mode.
    :SteamWorks: `ShowBindingPanel <https://partner.steamgames.com/doc/api/isteaminput#ShowBindingPanel>`_

.. function:: input.stopAnalogActionMomentum()
    
    :param uint64 inputHandle: The handle of the controller to affect. Obtained from :func:`input.getConnectedControllers`.
    :param uint64 action: The analog action to stop momentum for. This can be obtained from :func:`input.getAnalogActionHandle`.
    :returns: nothing
    :SteamWorks: `StopAnalogActionMomentum <https://partner.steamgames.com/doc/api/isteaminput#StopAnalogActionMomentum>`_

.. function:: input.legacy_triggerHapticPulse()
    
    :param uint64 inputHandle: The handle of the controller to affect. Obtained from :func:`input.getConnectedControllers`.
    :param string targetPad: `Left` or `Right` depending on which haptic touch pad to affect. See `ESteamControllerPad <https://partner.steamgames.com/doc/api/isteaminput#ESteamControllerPad>`_.
    :param short usDurationMicroSec: Duration of the pulse, in microseconds (1/1,000,000th of a second)
    :returns: nothing
    :SteamWorks: `TriggerHapticPulse <https://partner.steamgames.com/doc/api/isteaminput#TriggerHapticPulse>`_

.. function:: input.legacy_triggerRepeatedHapticPulse()
    
    :param uint64 inputHandle: The handle of the controller to affect. Obtained from :func:`input.getConnectedControllers`.
    :param string targetPad: `Left` or `Right` depending on which haptic touch pad to affect. See `ESteamControllerPad <https://partner.steamgames.com/doc/api/isteaminput#ESteamControllerPad>`_.
    :param short usDurationMicroSec: Duration of the pulse, in microseconds (1/1,000,000th of a second)
    :param short usOffMicroSec: Duration of the pause between pulses, in microseconds.
    :param short unRepeat: 	Number of times to repeat the `usDurationMicroSec / usOffMicroSec` duty cycle.
    :returns: nothing
    :SteamWorks: `TriggerRepeatedHapticPulse <https://partner.steamgames.com/doc/api/isteaminput#TriggerRepeatedHapticPulse>`_

.. function:: input.triggerVibration()
    
    :param uint64 inputHandle: The handle of the controller to affect. Obtained from :func:`input.getConnectedControllers`.
    :param short usLeftSpeed: The intensity value for the left rumble motor.
    :param short usRightSpeed: The intensity value for the right rumble motor.
    :returns: nothing
    :SteamWorks: `TriggerVibration <https://partner.steamgames.com/doc/api/isteaminput#TriggerVibration>`_

.. function:: input.getActionOriginFromXboxOrigin()
    
    :param uint64 inputHandle: The handle of the controller to affect. Obtained from :func:`input.getConnectedControllers`, or from :func:`input.getControllerForGamepadIndex`.
    :param string origin: This is the button you want to get the image for example: `A`, `B`, `LeftTrigger_Click`, `LeftStick_DPadWest`. See `EInputActionOrigin <https://partner.steamgames.com/doc/api/ISteamInput#EInputActionOrigin>`_ for reference.
    :returns: nothing
    :SteamWorks: `GetActionOriginFromXboxOrigin <https://partner.steamgames.com/doc/api/isteaminput#GetActionOriginFromXboxOrigin>`_

.. function:: input.translateActionOrigin()
    
    :param uint64 inputHandle: The handle of the controller to affect. Obtained from :func:`input.getConnectedControllers`, or from :func:`input.getControllerForGamepadIndex`.
    :param string destinationInputType: The controller type (see `ESteamInputType <https://partner.steamgames.com/doc/api/isteaminput#ESteamInputType>`_) you want to translate to.
    :param string sourceOrigin: This is the button you want to translate. For example, `LeftStick_Click`, `X`, `B`. See `EInputActionOrigin <https://partner.steamgames.com/doc/api/ISteamInput#EInputActionOrigin>`_ for all options.
    :returns: (`string`) The equivalent origin (`EInputActionOrigin`) for a given controller type or the closest controller type that existed in the SDK you built into your game if `eDestinationInputType` is `Unknown`. This action origin can be used in your glyph look up table or passed into :func:`input.getGlyphForActionOrigin` or :func:`input.getStringForActionOrigin`.
    :SteamWorks: `TranslateActionOrigin <https://partner.steamgames.com/doc/api/isteaminput#TranslateActionOrigin>`_

.. function:: input.getDeviceBindingRevision()
    
    :param uint64 inputHandle: The handle of the controller to query. Obtained from :func:`input.getConnectedControllers`.
    :returns: (`boolean`) Returns `true` if a device binding was successfully found and `false` if the binding is still loading
    :returns: (`number?`) If call was successful, returns the `major` binding revision for Steam Input API configurations.
    :returns: (`number?`) If call was successful, returns the `minor` binding revision for Steam Input API configurations.
    :SteamWorks: `GetDeviceBindingRevision <https://partner.steamgames.com/doc/api/isteaminput#GetDeviceBindingRevision>`_

.. function:: input.getRemotePlaySessionID()
    
    :param uint64 inputHandle: The handle of the controller to query. Obtained from :func:`input.getConnectedControllers`.
    :returns: (`number`) Steam Remote Play session ID
    :SteamWorks: `GetRemotePlaySessionID <https://partner.steamgames.com/doc/api/isteaminput#GetRemotePlaySessionID>`_
