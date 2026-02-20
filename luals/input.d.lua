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
---@return table
function Input.GetConnectedControllers() end

function Input.EnableDeviceCallbacks() end

---@param pszActionSetName string
---@return table
function Input.GetActionSetHandle(pszActionSetName) end

---@param inputHandle table
---@param actionSetHandle table
function Input.ActivateActionSet(inputHandle, actionSetHandle) end

---@param inputHandle table
---@return table
function Input.GetCurrentActionSet(inputHandle) end

---@param inputHandle table
---@param actionSetLayerHandle table
function Input.ActivateActionSetLayer(inputHandle, actionSetLayerHandle) end

---@param inputHandle table
---@param actionSetLayerHandle table
function Input.DeactivateActionSetLayer(inputHandle, actionSetLayerHandle) end

---@param inputHandle table
function Input.DeactivateAllActionSetLayers(inputHandle) end

---@param inputHandle table
---@return integer
---@return table
function Input.GetActiveActionSetLayers(inputHandle) end

---@param pszActionName string
---@return table
function Input.GetDigitalActionHandle(pszActionName) end

---@param inputHandle table
---@param digitalActionHandle table
---@return table
function Input.GetDigitalActionData(inputHandle, digitalActionHandle) end

---@param inputHandle table
---@param actionSetHandle table
---@param digitalActionHandle table
---@return integer
---@return integer
function Input.GetDigitalActionOrigins(inputHandle, actionSetHandle, digitalActionHandle) end

---@param eActionHandle table
---@return string
function Input.GetStringForDigitalActionName(eActionHandle) end

---@param pszActionName string
---@return table
function Input.GetAnalogActionHandle(pszActionName) end

---@param inputHandle table
---@param analogActionHandle table
---@return table
function Input.GetAnalogActionData(inputHandle, analogActionHandle) end

---@param inputHandle table
---@param actionSetHandle table
---@param analogActionHandle table
---@return integer
---@return integer
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

---@param eActionHandle table
---@return string
function Input.GetStringForAnalogActionName(eActionHandle) end

---@param inputHandle table
---@param eAction table
function Input.StopAnalogActionMomentum(inputHandle, eAction) end

---@param inputHandle table
---@return table
function Input.GetMotionData(inputHandle) end

---@param inputHandle table
---@param usLeftSpeed integer
---@param usRightSpeed integer
function Input.TriggerVibration(inputHandle, usLeftSpeed, usRightSpeed) end

---@param inputHandle table
---@param usLeftSpeed integer
---@param usRightSpeed integer
---@param usLeftTriggerSpeed integer
---@param usRightTriggerSpeed integer
function Input.TriggerVibrationExtended(inputHandle, usLeftSpeed, usRightSpeed, usLeftTriggerSpeed, usRightTriggerSpeed) end

---@param inputHandle table
---@param eHapticLocation integer
---@param nIntensity table
---@param nGainDB table
---@param nOtherIntensity table
---@param nOtherGainDB table
function Input.TriggerSimpleHapticEvent(inputHandle, eHapticLocation, nIntensity, nGainDB, nOtherIntensity, nOtherGainDB) end

---@param inputHandle table
---@param nColorR table
---@param nColorG table
---@param nColorB table
---@param nFlags integer
function Input.SetLEDColor(inputHandle, nColorR, nColorG, nColorB, nFlags) end

---@param inputHandle table
---@param eTargetPad integer
---@param usDurationMicroSec integer
function Input.Legacy_TriggerHapticPulse(inputHandle, eTargetPad, usDurationMicroSec) end

---@param inputHandle table
---@param eTargetPad integer
---@param usDurationMicroSec integer
---@param usOffMicroSec integer
---@param unRepeat integer
---@param nFlags integer
function Input.Legacy_TriggerRepeatedHapticPulse(inputHandle, eTargetPad, usDurationMicroSec, usOffMicroSec, unRepeat, nFlags) end

---@param inputHandle table
---@return boolean
function Input.ShowBindingPanel(inputHandle) end

---@param inputHandle table
---@return integer
function Input.GetInputTypeForHandle(inputHandle) end

---@param nIndex integer
---@return table
function Input.GetControllerForGamepadIndex(nIndex) end

---@param ulinputHandle table
---@return integer
function Input.GetGamepadIndexForController(ulinputHandle) end

---@param eOrigin integer
---@return string
function Input.GetStringForXboxOrigin(eOrigin) end

---@param eOrigin integer
---@return string
function Input.GetGlyphForXboxOrigin(eOrigin) end

---@param inputHandle table
---@param eOrigin integer
---@return integer
function Input.GetActionOriginFromXboxOrigin(inputHandle, eOrigin) end

---@param eDestinationInputType integer
---@param eSourceOrigin integer
---@return integer
function Input.TranslateActionOrigin(eDestinationInputType, eSourceOrigin) end

---@param inputHandle table
---@return boolean
---@return integer
---@return integer
function Input.GetDeviceBindingRevision(inputHandle) end

---@param inputHandle table
---@return integer
function Input.GetRemotePlaySessionID(inputHandle) end

---@return integer
function Input.GetSessionInputConfigurationSettings() end

Steam.Input = Input
