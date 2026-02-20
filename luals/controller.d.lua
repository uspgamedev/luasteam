---@class Steam.Controller
local Controller = {}

---@return boolean
function Controller.Init() end

---@return boolean
function Controller.Shutdown() end

function Controller.RunFrame() end

---@return integer
---@return uint64[] -- Value of: handlesOut
function Controller.GetConnectedControllers() end

---@param pszActionSetName string
---@return uint64
function Controller.GetActionSetHandle(pszActionSetName) end

---@param controllerHandle uint64
---@param actionSetHandle uint64
function Controller.ActivateActionSet(controllerHandle, actionSetHandle) end

---@param controllerHandle uint64
---@return uint64
function Controller.GetCurrentActionSet(controllerHandle) end

---@param controllerHandle uint64
---@param actionSetLayerHandle uint64
function Controller.ActivateActionSetLayer(controllerHandle, actionSetLayerHandle) end

---@param controllerHandle uint64
---@param actionSetLayerHandle uint64
function Controller.DeactivateActionSetLayer(controllerHandle, actionSetLayerHandle) end

---@param controllerHandle uint64
function Controller.DeactivateAllActionSetLayers(controllerHandle) end

---@param controllerHandle uint64
---@return integer
---@return uint64[] -- Value of: handlesOut
function Controller.GetActiveActionSetLayers(controllerHandle) end

---@param pszActionName string
---@return uint64
function Controller.GetDigitalActionHandle(pszActionName) end

---@param controllerHandle uint64
---@param digitalActionHandle uint64
---@return table
function Controller.GetDigitalActionData(controllerHandle, digitalActionHandle) end

---@param controllerHandle uint64
---@param actionSetHandle uint64
---@param digitalActionHandle uint64
---@return integer
---@return integer[] -- Value of: originsOut
function Controller.GetDigitalActionOrigins(controllerHandle, actionSetHandle, digitalActionHandle) end

---@param pszActionName string
---@return uint64
function Controller.GetAnalogActionHandle(pszActionName) end

---@param controllerHandle uint64
---@param analogActionHandle uint64
---@return table
function Controller.GetAnalogActionData(controllerHandle, analogActionHandle) end

---@param controllerHandle uint64
---@param actionSetHandle uint64
---@param analogActionHandle uint64
---@return integer
---@return integer[] -- Value of: originsOut
function Controller.GetAnalogActionOrigins(controllerHandle, actionSetHandle, analogActionHandle) end

---@param eOrigin integer
---@return string
function Controller.GetGlyphForActionOrigin(eOrigin) end

---@param eOrigin integer
---@return string
function Controller.GetStringForActionOrigin(eOrigin) end

---@param controllerHandle uint64
---@param eAction uint64
function Controller.StopAnalogActionMomentum(controllerHandle, eAction) end

---@param controllerHandle uint64
---@return table
function Controller.GetMotionData(controllerHandle) end

---@param controllerHandle uint64
---@param eTargetPad integer
---@param usDurationMicroSec integer
function Controller.TriggerHapticPulse(controllerHandle, eTargetPad, usDurationMicroSec) end

---@param controllerHandle uint64
---@param eTargetPad integer
---@param usDurationMicroSec integer
---@param usOffMicroSec integer
---@param unRepeat integer
---@param nFlags integer
function Controller.TriggerRepeatedHapticPulse(controllerHandle, eTargetPad, usDurationMicroSec, usOffMicroSec, unRepeat, nFlags) end

---@param controllerHandle uint64
---@param usLeftSpeed integer
---@param usRightSpeed integer
function Controller.TriggerVibration(controllerHandle, usLeftSpeed, usRightSpeed) end

---@param controllerHandle uint64
---@param nColorR integer
---@param nColorG integer
---@param nColorB integer
---@param nFlags integer
function Controller.SetLEDColor(controllerHandle, nColorR, nColorG, nColorB, nFlags) end

---@param controllerHandle uint64
---@return boolean
function Controller.ShowBindingPanel(controllerHandle) end

---@param controllerHandle uint64
---@return integer
function Controller.GetInputTypeForHandle(controllerHandle) end

---@param nIndex integer
---@return uint64
function Controller.GetControllerForGamepadIndex(nIndex) end

---@param ulControllerHandle uint64
---@return integer
function Controller.GetGamepadIndexForController(ulControllerHandle) end

---@param eOrigin integer
---@return string
function Controller.GetStringForXboxOrigin(eOrigin) end

---@param eOrigin integer
---@return string
function Controller.GetGlyphForXboxOrigin(eOrigin) end

---@param controllerHandle uint64
---@param eOrigin integer
---@return integer
function Controller.GetActionOriginFromXboxOrigin(controllerHandle, eOrigin) end

---@param eDestinationInputType integer
---@param eSourceOrigin integer
---@return integer
function Controller.TranslateActionOrigin(eDestinationInputType, eSourceOrigin) end

---@param controllerHandle uint64
---@return boolean
---@return integer -- Value of: pMajor
---@return integer -- Value of: pMinor
function Controller.GetControllerBindingRevision(controllerHandle) end

Steam.Controller = Controller
