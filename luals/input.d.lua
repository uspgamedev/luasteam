---@class Steam.Input
local Input = {}

---@param bExplicitlyCallRunFrame boolean
---@return boolean
function Input.Init(bExplicitlyCallRunFrame) end

---@return boolean
function Input.Shutdown() end

---@param pchInputActionManifestAbsolutePath string
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

---@param pszActionSetName string
---@return uint64
function Input.GetActionSetHandle(pszActionSetName) end

---@param inputHandle uint64
---@param actionSetHandle uint64
function Input.ActivateActionSet(inputHandle, actionSetHandle) end

---@param inputHandle uint64
---@return uint64
function Input.GetCurrentActionSet(inputHandle) end

---@param inputHandle uint64
---@param actionSetLayerHandle uint64
function Input.ActivateActionSetLayer(inputHandle, actionSetLayerHandle) end

---@param inputHandle uint64
---@param actionSetLayerHandle uint64
function Input.DeactivateActionSetLayer(inputHandle, actionSetLayerHandle) end

---@param inputHandle uint64
function Input.DeactivateAllActionSetLayers(inputHandle) end

---@param inputHandle uint64
---@return integer
---@return uint64[] -- Value of: handlesOut
function Input.GetActiveActionSetLayers(inputHandle) end

---@param pszActionName string
---@return uint64
function Input.GetDigitalActionHandle(pszActionName) end

---@param inputHandle uint64
---@param digitalActionHandle uint64
---@return InputDigitalActionData_t
function Input.GetDigitalActionData(inputHandle, digitalActionHandle) end

---@param inputHandle uint64
---@param actionSetHandle uint64
---@param digitalActionHandle uint64
---@return integer
---@return integer[] -- Value of: originsOut
function Input.GetDigitalActionOrigins(inputHandle, actionSetHandle, digitalActionHandle) end

---@param eActionHandle uint64
---@return string
function Input.GetStringForDigitalActionName(eActionHandle) end

---@param pszActionName string
---@return uint64
function Input.GetAnalogActionHandle(pszActionName) end

---@param inputHandle uint64
---@param analogActionHandle uint64
---@return InputAnalogActionData_t
function Input.GetAnalogActionData(inputHandle, analogActionHandle) end

---@param inputHandle uint64
---@param actionSetHandle uint64
---@param analogActionHandle uint64
---@return integer
---@return integer[] -- Value of: originsOut
function Input.GetAnalogActionOrigins(inputHandle, actionSetHandle, analogActionHandle) end

---@param eOrigin integer
---@param eSize integer
---@param unFlags integer
---@return string
function Input.GetGlyphPNGForActionOrigin(eOrigin, eSize, unFlags) end

---@param eOrigin integer
---@param unFlags integer
---@return string
function Input.GetGlyphSVGForActionOrigin(eOrigin, unFlags) end

---@param eOrigin integer
---@return string
function Input.GetGlyphForActionOrigin_Legacy(eOrigin) end

---@param eOrigin integer
---@return string
function Input.GetStringForActionOrigin(eOrigin) end

---@param eActionHandle uint64
---@return string
function Input.GetStringForAnalogActionName(eActionHandle) end

---@param inputHandle uint64
---@param eAction uint64
function Input.StopAnalogActionMomentum(inputHandle, eAction) end

---@param inputHandle uint64
---@return InputMotionData_t
function Input.GetMotionData(inputHandle) end

---@param inputHandle uint64
---@param usLeftSpeed integer
---@param usRightSpeed integer
function Input.TriggerVibration(inputHandle, usLeftSpeed, usRightSpeed) end

---@param inputHandle uint64
---@param usLeftSpeed integer
---@param usRightSpeed integer
---@param usLeftTriggerSpeed integer
---@param usRightTriggerSpeed integer
function Input.TriggerVibrationExtended(inputHandle, usLeftSpeed, usRightSpeed, usLeftTriggerSpeed, usRightTriggerSpeed) end

---@param inputHandle uint64
---@param eHapticLocation integer
---@param nIntensity integer
---@param nGainDB string
---@param nOtherIntensity integer
---@param nOtherGainDB string
function Input.TriggerSimpleHapticEvent(inputHandle, eHapticLocation, nIntensity, nGainDB, nOtherIntensity, nOtherGainDB) end

---@param inputHandle uint64
---@param nColorR integer
---@param nColorG integer
---@param nColorB integer
---@param nFlags integer
function Input.SetLEDColor(inputHandle, nColorR, nColorG, nColorB, nFlags) end

---@param inputHandle uint64
---@param eTargetPad integer
---@param usDurationMicroSec integer
function Input.Legacy_TriggerHapticPulse(inputHandle, eTargetPad, usDurationMicroSec) end

---@param inputHandle uint64
---@param eTargetPad integer
---@param usDurationMicroSec integer
---@param usOffMicroSec integer
---@param unRepeat integer
---@param nFlags integer
function Input.Legacy_TriggerRepeatedHapticPulse(inputHandle, eTargetPad, usDurationMicroSec, usOffMicroSec, unRepeat, nFlags) end

---@param inputHandle uint64
---@return boolean
function Input.ShowBindingPanel(inputHandle) end

---@param inputHandle uint64
---@return integer
function Input.GetInputTypeForHandle(inputHandle) end

---@param nIndex integer
---@return uint64
function Input.GetControllerForGamepadIndex(nIndex) end

---@param ulinputHandle uint64
---@return integer
function Input.GetGamepadIndexForController(ulinputHandle) end

---@param eOrigin integer
---@return string
function Input.GetStringForXboxOrigin(eOrigin) end

---@param eOrigin integer
---@return string
function Input.GetGlyphForXboxOrigin(eOrigin) end

---@param inputHandle uint64
---@param eOrigin integer
---@return integer
function Input.GetActionOriginFromXboxOrigin(inputHandle, eOrigin) end

---@param eDestinationInputType integer
---@param eSourceOrigin integer
---@return integer
function Input.TranslateActionOrigin(eDestinationInputType, eSourceOrigin) end

---@param inputHandle uint64
---@return boolean
---@return integer -- Value of: pMajor
---@return integer -- Value of: pMinor
function Input.GetDeviceBindingRevision(inputHandle) end

---@param inputHandle uint64
---@return integer
function Input.GetRemotePlaySessionID(inputHandle) end

---@return integer
function Input.GetSessionInputConfigurationSettings() end

Steam.Input = Input
