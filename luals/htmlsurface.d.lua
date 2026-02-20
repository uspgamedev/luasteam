---@class Steam.HTMLSurface
local HTMLSurface = {}

---@return boolean
function HTMLSurface.Init() end

---@return boolean
function HTMLSurface.Shutdown() end

---@param pchUserAgent string
---@param pchUserCSS string
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function HTMLSurface.CreateBrowser(pchUserAgent, pchUserCSS, callback) end

---@param unBrowserHandle integer
function HTMLSurface.RemoveBrowser(unBrowserHandle) end

---@param unBrowserHandle integer
---@param pchURL string
---@param pchPostData string
function HTMLSurface.LoadURL(unBrowserHandle, pchURL, pchPostData) end

---@param unBrowserHandle integer
---@param unWidth integer
---@param unHeight integer
function HTMLSurface.SetSize(unBrowserHandle, unWidth, unHeight) end

---@param unBrowserHandle integer
function HTMLSurface.StopLoad(unBrowserHandle) end

---@param unBrowserHandle integer
function HTMLSurface.Reload(unBrowserHandle) end

---@param unBrowserHandle integer
function HTMLSurface.GoBack(unBrowserHandle) end

---@param unBrowserHandle integer
function HTMLSurface.GoForward(unBrowserHandle) end

---@param unBrowserHandle integer
---@param pchKey string
---@param pchValue string
function HTMLSurface.AddHeader(unBrowserHandle, pchKey, pchValue) end

---@param unBrowserHandle integer
---@param pchScript string
function HTMLSurface.ExecuteJavascript(unBrowserHandle, pchScript) end

---@param unBrowserHandle integer
---@param x integer
---@param y integer
function HTMLSurface.MouseMove(unBrowserHandle, x, y) end

---@param unBrowserHandle integer
---@param nDelta integer
function HTMLSurface.MouseWheel(unBrowserHandle, nDelta) end

---@param unBrowserHandle integer
---@param nAbsolutePixelScroll integer
function HTMLSurface.SetHorizontalScroll(unBrowserHandle, nAbsolutePixelScroll) end

---@param unBrowserHandle integer
---@param nAbsolutePixelScroll integer
function HTMLSurface.SetVerticalScroll(unBrowserHandle, nAbsolutePixelScroll) end

---@param unBrowserHandle integer
---@param bHasKeyFocus boolean
function HTMLSurface.SetKeyFocus(unBrowserHandle, bHasKeyFocus) end

---@param unBrowserHandle integer
function HTMLSurface.ViewSource(unBrowserHandle) end

---@param unBrowserHandle integer
function HTMLSurface.CopyToClipboard(unBrowserHandle) end

---@param unBrowserHandle integer
function HTMLSurface.PasteFromClipboard(unBrowserHandle) end

---@param unBrowserHandle integer
---@param pchSearchStr string
---@param bCurrentlyInFind boolean
---@param bReverse boolean
function HTMLSurface.Find(unBrowserHandle, pchSearchStr, bCurrentlyInFind, bReverse) end

---@param unBrowserHandle integer
function HTMLSurface.StopFind(unBrowserHandle) end

---@param unBrowserHandle integer
---@param x integer
---@param y integer
function HTMLSurface.GetLinkAtPosition(unBrowserHandle, x, y) end

---@param pchHostname string
---@param pchKey string
---@param pchValue string
---@param pchPath string
---@param nExpires integer
---@param bSecure boolean
---@param bHTTPOnly boolean
function HTMLSurface.SetCookie(pchHostname, pchKey, pchValue, pchPath, nExpires, bSecure, bHTTPOnly) end

---@param unBrowserHandle integer
---@param flZoom number
---@param nPointX integer
---@param nPointY integer
function HTMLSurface.SetPageScaleFactor(unBrowserHandle, flZoom, nPointX, nPointY) end

---@param unBrowserHandle integer
---@param bBackgroundMode boolean
function HTMLSurface.SetBackgroundMode(unBrowserHandle, bBackgroundMode) end

---@param unBrowserHandle integer
---@param flDPIScaling number
function HTMLSurface.SetDPIScalingFactor(unBrowserHandle, flDPIScaling) end

---@param unBrowserHandle integer
function HTMLSurface.OpenDeveloperTools(unBrowserHandle) end

---@param unBrowserHandle integer
---@param bAllowed boolean
function HTMLSurface.AllowStartRequest(unBrowserHandle, bAllowed) end

---@param unBrowserHandle integer
---@param bResult boolean
function HTMLSurface.JSDialogResponse(unBrowserHandle, bResult) end

Steam.HTMLSurface = HTMLSurface
