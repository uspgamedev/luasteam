---@class Steam.Controller
local Controller = {}

---@return boolean
function Controller.Init() end

---@return boolean
function Controller.Shutdown() end

function Controller.RunFrame() end

---@return integer
---@return table
function Controller.GetConnectedControllers() end

---@param pszActionSetName string
---@return table
function Controller.GetActionSetHandle(pszActionSetName) end

---@param controllerHandle table
---@param actionSetHandle table
function Controller.ActivateActionSet(controllerHandle, actionSetHandle) end

---@param controllerHandle table
---@return table
function Controller.GetCurrentActionSet(controllerHandle) end

---@param controllerHandle table
---@param actionSetLayerHandle table
function Controller.ActivateActionSetLayer(controllerHandle, actionSetLayerHandle) end

---@param controllerHandle table
---@param actionSetLayerHandle table
function Controller.DeactivateActionSetLayer(controllerHandle, actionSetLayerHandle) end

---@param controllerHandle table
function Controller.DeactivateAllActionSetLayers(controllerHandle) end

---@param controllerHandle table
---@return integer
---@return table
function Controller.GetActiveActionSetLayers(controllerHandle) end

---@param pszActionName string
---@return table
function Controller.GetDigitalActionHandle(pszActionName) end

---@param controllerHandle table
---@param digitalActionHandle table
---@return table
function Controller.GetDigitalActionData(controllerHandle, digitalActionHandle) end

---@param controllerHandle table
---@param actionSetHandle table
---@param digitalActionHandle table
---@return integer
---@return integer
function Controller.GetDigitalActionOrigins(controllerHandle, actionSetHandle, digitalActionHandle) end

---@param pszActionName string
---@return table
function Controller.GetAnalogActionHandle(pszActionName) end

---@param controllerHandle table
---@param analogActionHandle table
---@return table
function Controller.GetAnalogActionData(controllerHandle, analogActionHandle) end

---@param controllerHandle table
---@param actionSetHandle table
---@param analogActionHandle table
---@return integer
---@return integer
function Controller.GetAnalogActionOrigins(controllerHandle, actionSetHandle, analogActionHandle) end

---@param eOrigin integer
---@return string
function Controller.GetGlyphForActionOrigin(eOrigin) end

---@param eOrigin integer
---@return string
function Controller.GetStringForActionOrigin(eOrigin) end

---@param controllerHandle table
---@param eAction table
function Controller.StopAnalogActionMomentum(controllerHandle, eAction) end

---@param controllerHandle table
---@return table
function Controller.GetMotionData(controllerHandle) end

---@param controllerHandle table
---@param eTargetPad integer
---@param usDurationMicroSec integer
function Controller.TriggerHapticPulse(controllerHandle, eTargetPad, usDurationMicroSec) end

---@param controllerHandle table
---@param eTargetPad integer
---@param usDurationMicroSec integer
---@param usOffMicroSec integer
---@param unRepeat integer
---@param nFlags integer
function Controller.TriggerRepeatedHapticPulse(controllerHandle, eTargetPad, usDurationMicroSec, usOffMicroSec, unRepeat, nFlags) end

---@param controllerHandle table
---@param usLeftSpeed integer
---@param usRightSpeed integer
function Controller.TriggerVibration(controllerHandle, usLeftSpeed, usRightSpeed) end

---@param controllerHandle table
---@param nColorR table
---@param nColorG table
---@param nColorB table
---@param nFlags integer
function Controller.SetLEDColor(controllerHandle, nColorR, nColorG, nColorB, nFlags) end

---@param controllerHandle table
---@return boolean
function Controller.ShowBindingPanel(controllerHandle) end

---@param controllerHandle table
---@return integer
function Controller.GetInputTypeForHandle(controllerHandle) end

---@param nIndex integer
---@return table
function Controller.GetControllerForGamepadIndex(nIndex) end

---@param ulControllerHandle table
---@return integer
function Controller.GetGamepadIndexForController(ulControllerHandle) end

---@param eOrigin integer
---@return string
function Controller.GetStringForXboxOrigin(eOrigin) end

---@param eOrigin integer
---@return string
function Controller.GetGlyphForXboxOrigin(eOrigin) end

---@param controllerHandle table
---@param eOrigin integer
---@return integer
function Controller.GetActionOriginFromXboxOrigin(controllerHandle, eOrigin) end

---@param eDestinationInputType integer
---@param eSourceOrigin integer
---@return integer
function Controller.TranslateActionOrigin(eDestinationInputType, eSourceOrigin) end

---@param controllerHandle table
---@return boolean
---@return integer
---@return integer
function Controller.GetControllerBindingRevision(controllerHandle) end

Steam.Controller = Controller
