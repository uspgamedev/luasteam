---@class Steam.Utils
local Utils = {}

---@return integer
function Utils.GetSecondsSinceAppActive() end

---@return integer
function Utils.GetSecondsSinceComputerActive() end

---@return integer
function Utils.GetConnectedUniverse() end

---@return integer
function Utils.GetServerRealTime() end

---@return string
function Utils.GetIPCountry() end

---@param iImage integer
---@return boolean
---@return integer -- Value of: pnWidth
---@return integer -- Value of: pnHeight
function Utils.GetImageSize(iImage) end

---@param iImage integer
---@param nDestBufferSize integer
---@return boolean
---@return string -- Value of: pubDest
function Utils.GetImageRGBA(iImage, nDestBufferSize) end

---@return integer
function Utils.GetCurrentBatteryPower() end

---@return integer
function Utils.GetAppID() end

---@param eNotificationPosition integer
function Utils.SetOverlayNotificationPosition(eNotificationPosition) end

---@param hSteamAPICall uint64
---@return boolean
---@return boolean -- Value of: pbFailed
function Utils.IsAPICallCompleted(hSteamAPICall) end

---@param hSteamAPICall uint64
---@return integer
function Utils.GetAPICallFailureReason(hSteamAPICall) end

---@param hSteamAPICall uint64
---@param cubCallback integer
---@param iCallbackExpected integer
---@return boolean
---@return string -- Value of: pCallback
---@return boolean -- Value of: pbFailed
function Utils.GetAPICallResult(hSteamAPICall, cubCallback, iCallbackExpected) end

---@return integer
function Utils.GetIPCCallCount() end

---@return boolean
function Utils.IsOverlayEnabled() end

---@return boolean
function Utils.BOverlayNeedsPresent() end

---@param szFileName string
---@param callback fun(data: CheckFileSignature_t?, io_fail: boolean)?
---@return uint64
function Utils.CheckFileSignature(szFileName, callback) end

---@param eInputMode integer
---@param eLineInputMode integer
---@param pchDescription string
---@param unCharMax integer
---@param pchExistingText string
---@return boolean
function Utils.ShowGamepadTextInput(eInputMode, eLineInputMode, pchDescription, unCharMax, pchExistingText) end

---@return integer
function Utils.GetEnteredGamepadTextLength() end

---@param cchText integer
---@return boolean
---@return string -- Value of: pchText
function Utils.GetEnteredGamepadTextInput(cchText) end

---@return string
function Utils.GetSteamUILanguage() end

---@return boolean
function Utils.IsSteamRunningInVR() end

---@param nHorizontalInset integer
---@param nVerticalInset integer
function Utils.SetOverlayNotificationInset(nHorizontalInset, nVerticalInset) end

---@return boolean
function Utils.IsSteamInBigPictureMode() end

function Utils.StartVRDashboard() end

---@return boolean
function Utils.IsVRHeadsetStreamingEnabled() end

---@param bEnabled boolean
function Utils.SetVRHeadsetStreamingEnabled(bEnabled) end

---@return boolean
function Utils.IsSteamChinaLauncher() end

---@param unFilterOptions integer
---@return boolean
function Utils.InitFilterText(unFilterOptions) end

---@param eContext integer
---@param sourceSteamID uint64
---@param pchInputMessage string
---@param nByteSizeOutFilteredText integer
---@return integer
---@return string -- Value of: pchOutFilteredText
function Utils.FilterText(eContext, sourceSteamID, pchInputMessage, nByteSizeOutFilteredText) end

---@param eProtocol integer
---@return integer
function Utils.GetIPv6ConnectivityState(eProtocol) end

---@return boolean
function Utils.IsSteamRunningOnSteamDeck() end

---@param eKeyboardMode integer
---@param nTextFieldXPosition integer
---@param nTextFieldYPosition integer
---@param nTextFieldWidth integer
---@param nTextFieldHeight integer
---@return boolean
function Utils.ShowFloatingGamepadTextInput(eKeyboardMode, nTextFieldXPosition, nTextFieldYPosition, nTextFieldWidth, nTextFieldHeight) end

---@param bLauncherMode boolean
function Utils.SetGameLauncherMode(bLauncherMode) end

---@return boolean
function Utils.DismissFloatingGamepadTextInput() end

---@return boolean
function Utils.DismissGamepadTextInput() end

Steam.Utils = Utils
