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

---@param pszActionSetName string?
---@return uint64 -- ControllerActionSetHandle_t
function Controller.GetActionSetHandle(pszActionSetName) end

---@param controllerHandle uint64 -- ControllerHandle_t
---@param actionSetHandle uint64 -- ControllerActionSetHandle_t
function Controller.ActivateActionSet(controllerHandle, actionSetHandle) end

---@param controllerHandle uint64 -- ControllerHandle_t
---@return uint64 -- ControllerActionSetHandle_t
function Controller.GetCurrentActionSet(controllerHandle) end

---@param controllerHandle uint64 -- ControllerHandle_t
---@param actionSetLayerHandle uint64 -- ControllerActionSetHandle_t
function Controller.ActivateActionSetLayer(controllerHandle, actionSetLayerHandle) end

---@param controllerHandle uint64 -- ControllerHandle_t
---@param actionSetLayerHandle uint64 -- ControllerActionSetHandle_t
function Controller.DeactivateActionSetLayer(controllerHandle, actionSetLayerHandle) end

---@param controllerHandle uint64 -- ControllerHandle_t
function Controller.DeactivateAllActionSetLayers(controllerHandle) end

---@param controllerHandle uint64 -- ControllerHandle_t
---@return integer
---@return uint64[] -- Value of: handlesOut
function Controller.GetActiveActionSetLayers(controllerHandle) end

---@param pszActionName string?
---@return uint64 -- ControllerDigitalActionHandle_t
function Controller.GetDigitalActionHandle(pszActionName) end

---@param controllerHandle uint64 -- ControllerHandle_t
---@param digitalActionHandle uint64 -- ControllerDigitalActionHandle_t
---@return InputDigitalActionData_t -- InputDigitalActionData_t
function Controller.GetDigitalActionData(controllerHandle, digitalActionHandle) end

---@param controllerHandle uint64 -- ControllerHandle_t
---@param actionSetHandle uint64 -- ControllerActionSetHandle_t
---@param digitalActionHandle uint64 -- ControllerDigitalActionHandle_t
---@return integer
---@return integer[] -- Value of: originsOut
function Controller.GetDigitalActionOrigins(controllerHandle, actionSetHandle, digitalActionHandle) end

---@param pszActionName string?
---@return uint64 -- ControllerAnalogActionHandle_t
function Controller.GetAnalogActionHandle(pszActionName) end

---@param controllerHandle uint64 -- ControllerHandle_t
---@param analogActionHandle uint64 -- ControllerAnalogActionHandle_t
---@return InputAnalogActionData_t -- InputAnalogActionData_t
function Controller.GetAnalogActionData(controllerHandle, analogActionHandle) end

---@param controllerHandle uint64 -- ControllerHandle_t
---@param actionSetHandle uint64 -- ControllerActionSetHandle_t
---@param analogActionHandle uint64 -- ControllerAnalogActionHandle_t
---@return integer
---@return integer[] -- Value of: originsOut
function Controller.GetAnalogActionOrigins(controllerHandle, actionSetHandle, analogActionHandle) end

---@param eOrigin integer -- EControllerActionOrigin
---@return string
function Controller.GetGlyphForActionOrigin(eOrigin) end

---@param eOrigin integer -- EControllerActionOrigin
---@return string
function Controller.GetStringForActionOrigin(eOrigin) end

---@param controllerHandle uint64 -- ControllerHandle_t
---@param eAction uint64 -- ControllerAnalogActionHandle_t
function Controller.StopAnalogActionMomentum(controllerHandle, eAction) end

---@param controllerHandle uint64 -- ControllerHandle_t
---@return InputMotionData_t -- InputMotionData_t
function Controller.GetMotionData(controllerHandle) end

---@param controllerHandle uint64 -- ControllerHandle_t
---@param eTargetPad integer -- ESteamControllerPad
---@param usDurationMicroSec integer -- unsigned short
function Controller.TriggerHapticPulse(controllerHandle, eTargetPad, usDurationMicroSec) end

---@param controllerHandle uint64 -- ControllerHandle_t
---@param eTargetPad integer -- ESteamControllerPad
---@param usDurationMicroSec integer -- unsigned short
---@param usOffMicroSec integer -- unsigned short
---@param unRepeat integer -- unsigned short
---@param nFlags integer -- unsigned int
function Controller.TriggerRepeatedHapticPulse(controllerHandle, eTargetPad, usDurationMicroSec, usOffMicroSec, unRepeat, nFlags) end

---@param controllerHandle uint64 -- ControllerHandle_t
---@param usLeftSpeed integer -- unsigned short
---@param usRightSpeed integer -- unsigned short
function Controller.TriggerVibration(controllerHandle, usLeftSpeed, usRightSpeed) end

---@param controllerHandle uint64 -- ControllerHandle_t
---@param nColorR integer
---@param nColorG integer
---@param nColorB integer
---@param nFlags integer -- unsigned int
function Controller.SetLEDColor(controllerHandle, nColorR, nColorG, nColorB, nFlags) end

---@param controllerHandle uint64 -- ControllerHandle_t
---@return boolean
function Controller.ShowBindingPanel(controllerHandle) end

---@param controllerHandle uint64 -- ControllerHandle_t
---@return integer -- ESteamInputType
function Controller.GetInputTypeForHandle(controllerHandle) end

---@param nIndex integer
---@return uint64 -- ControllerHandle_t
function Controller.GetControllerForGamepadIndex(nIndex) end

---@param ulControllerHandle uint64 -- ControllerHandle_t
---@return integer
function Controller.GetGamepadIndexForController(ulControllerHandle) end

---@param eOrigin integer -- EXboxOrigin
---@return string
function Controller.GetStringForXboxOrigin(eOrigin) end

---@param eOrigin integer -- EXboxOrigin
---@return string
function Controller.GetGlyphForXboxOrigin(eOrigin) end

---@param controllerHandle uint64 -- ControllerHandle_t
---@param eOrigin integer -- EXboxOrigin
---@return integer -- EControllerActionOrigin
function Controller.GetActionOriginFromXboxOrigin(controllerHandle, eOrigin) end

---@param eDestinationInputType integer -- ESteamInputType
---@param eSourceOrigin integer -- EControllerActionOrigin
---@return integer -- EControllerActionOrigin
function Controller.TranslateActionOrigin(eDestinationInputType, eSourceOrigin) end

---@param controllerHandle uint64 -- ControllerHandle_t
---@return boolean
---@return integer -- Value of: pMajor
---@return integer -- Value of: pMinor
function Controller.GetControllerBindingRevision(controllerHandle) end

Steam.Controller = Controller
