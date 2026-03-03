---@class Steam.Input
---@field OnSteamInputDeviceConnected? fun(data: SteamInputDeviceConnected_t)
---@field OnSteamInputDeviceDisconnected? fun(data: SteamInputDeviceDisconnected_t)
---@field OnSteamInputConfigurationLoaded? fun(data: SteamInputConfigurationLoaded_t)
---@field OnSteamInputGamepadSlotChange? fun(data: SteamInputGamepadSlotChange_t)
local Input = {}

---@param bExplicitlyCallRunFrame boolean
---@return boolean
function Input.Init(bExplicitlyCallRunFrame) end

---@return boolean
function Input.Shutdown() end

---@param pchInputActionManifestAbsolutePath string?
---@return boolean
function Input.SetInputActionManifestFilePath(pchInputActionManifestAbsolutePath) end

---@param bReservedValue boolean
function Input.RunFrame(bReservedValue) end

---@param bWaitForever boolean
---@param unTimeout integer
---@return boolean
function Input.BWaitForData(bWaitForever, unTimeout) end

---@return boolean
function Input.BNewDataAvailable() end

---@return integer
---@return uint64[] -- Value of: handlesOut
function Input.GetConnectedControllers() end

function Input.EnableDeviceCallbacks() end

---@param pszActionSetName string?
---@return uint64 -- InputActionSetHandle_t
function Input.GetActionSetHandle(pszActionSetName) end

---@param inputHandle uint64 -- InputHandle_t
---@param actionSetHandle uint64 -- InputActionSetHandle_t
function Input.ActivateActionSet(inputHandle, actionSetHandle) end

---@param inputHandle uint64 -- InputHandle_t
---@return uint64 -- InputActionSetHandle_t
function Input.GetCurrentActionSet(inputHandle) end

---@param inputHandle uint64 -- InputHandle_t
---@param actionSetLayerHandle uint64 -- InputActionSetHandle_t
function Input.ActivateActionSetLayer(inputHandle, actionSetLayerHandle) end

---@param inputHandle uint64 -- InputHandle_t
---@param actionSetLayerHandle uint64 -- InputActionSetHandle_t
function Input.DeactivateActionSetLayer(inputHandle, actionSetLayerHandle) end

---@param inputHandle uint64 -- InputHandle_t
function Input.DeactivateAllActionSetLayers(inputHandle) end

---@param inputHandle uint64 -- InputHandle_t
---@return integer
---@return uint64[] -- Value of: handlesOut
function Input.GetActiveActionSetLayers(inputHandle) end

---@param pszActionName string?
---@return uint64 -- InputDigitalActionHandle_t
function Input.GetDigitalActionHandle(pszActionName) end

---@param inputHandle uint64 -- InputHandle_t
---@param digitalActionHandle uint64 -- InputDigitalActionHandle_t
---@return InputDigitalActionData_t -- InputDigitalActionData_t
function Input.GetDigitalActionData(inputHandle, digitalActionHandle) end

---@param inputHandle uint64 -- InputHandle_t
---@param actionSetHandle uint64 -- InputActionSetHandle_t
---@param digitalActionHandle uint64 -- InputDigitalActionHandle_t
---@return integer
---@return integer[] -- Value of: originsOut
function Input.GetDigitalActionOrigins(inputHandle, actionSetHandle, digitalActionHandle) end

---@param eActionHandle uint64 -- InputDigitalActionHandle_t
---@return string
function Input.GetStringForDigitalActionName(eActionHandle) end

---@param pszActionName string?
---@return uint64 -- InputAnalogActionHandle_t
function Input.GetAnalogActionHandle(pszActionName) end

---@param inputHandle uint64 -- InputHandle_t
---@param analogActionHandle uint64 -- InputAnalogActionHandle_t
---@return InputAnalogActionData_t -- InputAnalogActionData_t
function Input.GetAnalogActionData(inputHandle, analogActionHandle) end

---@param inputHandle uint64 -- InputHandle_t
---@param actionSetHandle uint64 -- InputActionSetHandle_t
---@param analogActionHandle uint64 -- InputAnalogActionHandle_t
---@return integer
---@return integer[] -- Value of: originsOut
function Input.GetAnalogActionOrigins(inputHandle, actionSetHandle, analogActionHandle) end

---@param eOrigin integer -- EInputActionOrigin
---@param eSize integer -- ESteamInputGlyphSize
---@param unFlags integer
---@return string
function Input.GetGlyphPNGForActionOrigin(eOrigin, eSize, unFlags) end

---@param eOrigin integer -- EInputActionOrigin
---@param unFlags integer
---@return string
function Input.GetGlyphSVGForActionOrigin(eOrigin, unFlags) end

---@param eOrigin integer -- EInputActionOrigin
---@return string
function Input.GetGlyphForActionOrigin_Legacy(eOrigin) end

---@param eOrigin integer -- EInputActionOrigin
---@return string
function Input.GetStringForActionOrigin(eOrigin) end

---@param eActionHandle uint64 -- InputAnalogActionHandle_t
---@return string
function Input.GetStringForAnalogActionName(eActionHandle) end

---@param inputHandle uint64 -- InputHandle_t
---@param eAction uint64 -- InputAnalogActionHandle_t
function Input.StopAnalogActionMomentum(inputHandle, eAction) end

---@param inputHandle uint64 -- InputHandle_t
---@return InputMotionData_t -- InputMotionData_t
function Input.GetMotionData(inputHandle) end

---@param inputHandle uint64 -- InputHandle_t
---@param usLeftSpeed integer -- unsigned short
---@param usRightSpeed integer -- unsigned short
function Input.TriggerVibration(inputHandle, usLeftSpeed, usRightSpeed) end

---@param inputHandle uint64 -- InputHandle_t
---@param usLeftSpeed integer -- unsigned short
---@param usRightSpeed integer -- unsigned short
---@param usLeftTriggerSpeed integer -- unsigned short
---@param usRightTriggerSpeed integer -- unsigned short
function Input.TriggerVibrationExtended(inputHandle, usLeftSpeed, usRightSpeed, usLeftTriggerSpeed, usRightTriggerSpeed) end

---@param inputHandle uint64 -- InputHandle_t
---@param eHapticLocation integer -- EControllerHapticLocation
---@param nIntensity integer
---@param nGainDB string -- char
---@param nOtherIntensity integer
---@param nOtherGainDB string -- char
function Input.TriggerSimpleHapticEvent(inputHandle, eHapticLocation, nIntensity, nGainDB, nOtherIntensity, nOtherGainDB) end

---@param inputHandle uint64 -- InputHandle_t
---@param nColorR integer
---@param nColorG integer
---@param nColorB integer
---@param nFlags integer -- unsigned int
function Input.SetLEDColor(inputHandle, nColorR, nColorG, nColorB, nFlags) end

---@param inputHandle uint64 -- InputHandle_t
---@param eTargetPad integer -- ESteamControllerPad
---@param usDurationMicroSec integer -- unsigned short
function Input.Legacy_TriggerHapticPulse(inputHandle, eTargetPad, usDurationMicroSec) end

---@param inputHandle uint64 -- InputHandle_t
---@param eTargetPad integer -- ESteamControllerPad
---@param usDurationMicroSec integer -- unsigned short
---@param usOffMicroSec integer -- unsigned short
---@param unRepeat integer -- unsigned short
---@param nFlags integer -- unsigned int
function Input.Legacy_TriggerRepeatedHapticPulse(inputHandle, eTargetPad, usDurationMicroSec, usOffMicroSec, unRepeat, nFlags) end

---@param inputHandle uint64 -- InputHandle_t
---@return boolean
function Input.ShowBindingPanel(inputHandle) end

---@param inputHandle uint64 -- InputHandle_t
---@return integer -- ESteamInputType
function Input.GetInputTypeForHandle(inputHandle) end

---@param nIndex integer
---@return uint64 -- InputHandle_t
function Input.GetControllerForGamepadIndex(nIndex) end

---@param ulinputHandle uint64 -- InputHandle_t
---@return integer
function Input.GetGamepadIndexForController(ulinputHandle) end

---@param eOrigin integer -- EXboxOrigin
---@return string
function Input.GetStringForXboxOrigin(eOrigin) end

---@param eOrigin integer -- EXboxOrigin
---@return string
function Input.GetGlyphForXboxOrigin(eOrigin) end

---@param inputHandle uint64 -- InputHandle_t
---@param eOrigin integer -- EXboxOrigin
---@return integer -- EInputActionOrigin
function Input.GetActionOriginFromXboxOrigin(inputHandle, eOrigin) end

---@param eDestinationInputType integer -- ESteamInputType
---@param eSourceOrigin integer -- EInputActionOrigin
---@return integer -- EInputActionOrigin
function Input.TranslateActionOrigin(eDestinationInputType, eSourceOrigin) end

---@param inputHandle uint64 -- InputHandle_t
---@return boolean
---@return integer -- Value of: pMajor
---@return integer -- Value of: pMinor
function Input.GetDeviceBindingRevision(inputHandle) end

---@param inputHandle uint64 -- InputHandle_t
---@return integer
function Input.GetRemotePlaySessionID(inputHandle) end

---@return integer
function Input.GetSessionInputConfigurationSettings() end

Steam.Input = Input
