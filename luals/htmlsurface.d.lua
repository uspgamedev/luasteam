---@class Steam.HTMLSurface
---@field OnHTML_BrowserReady? fun(data: HTML_BrowserReady_t)
---@field OnHTML_NeedsPaint? fun(data: HTML_NeedsPaint_t)
---@field OnHTML_StartRequest? fun(data: HTML_StartRequest_t)
---@field OnHTML_CloseBrowser? fun(data: HTML_CloseBrowser_t)
---@field OnHTML_URLChanged? fun(data: HTML_URLChanged_t)
---@field OnHTML_FinishedRequest? fun(data: HTML_FinishedRequest_t)
---@field OnHTML_OpenLinkInNewTab? fun(data: HTML_OpenLinkInNewTab_t)
---@field OnHTML_ChangedTitle? fun(data: HTML_ChangedTitle_t)
---@field OnHTML_SearchResults? fun(data: HTML_SearchResults_t)
---@field OnHTML_CanGoBackAndForward? fun(data: HTML_CanGoBackAndForward_t)
---@field OnHTML_HorizontalScroll? fun(data: HTML_HorizontalScroll_t)
---@field OnHTML_VerticalScroll? fun(data: HTML_VerticalScroll_t)
---@field OnHTML_LinkAtPosition? fun(data: HTML_LinkAtPosition_t)
---@field OnHTML_JSAlert? fun(data: HTML_JSAlert_t)
---@field OnHTML_JSConfirm? fun(data: HTML_JSConfirm_t)
---@field OnHTML_FileOpenDialog? fun(data: HTML_FileOpenDialog_t)
---@field OnHTML_NewWindow? fun(data: HTML_NewWindow_t)
---@field OnHTML_SetCursor? fun(data: HTML_SetCursor_t)
---@field OnHTML_StatusText? fun(data: HTML_StatusText_t)
---@field OnHTML_ShowToolTip? fun(data: HTML_ShowToolTip_t)
---@field OnHTML_UpdateToolTip? fun(data: HTML_UpdateToolTip_t)
---@field OnHTML_HideToolTip? fun(data: HTML_HideToolTip_t)
---@field OnHTML_BrowserRestarted? fun(data: HTML_BrowserRestarted_t)
local HTMLSurface = {}

---@return boolean
function HTMLSurface.Init() end

---@return boolean
function HTMLSurface.Shutdown() end

---@param pchUserAgent string?
---@param pchUserCSS string?
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function HTMLSurface.CreateBrowser(pchUserAgent, pchUserCSS, callback) end

---@param unBrowserHandle integer -- HHTMLBrowser
function HTMLSurface.RemoveBrowser(unBrowserHandle) end

---@param unBrowserHandle integer -- HHTMLBrowser
---@param pchURL string?
---@param pchPostData string?
function HTMLSurface.LoadURL(unBrowserHandle, pchURL, pchPostData) end

---@param unBrowserHandle integer -- HHTMLBrowser
---@param unWidth integer
---@param unHeight integer
function HTMLSurface.SetSize(unBrowserHandle, unWidth, unHeight) end

---@param unBrowserHandle integer -- HHTMLBrowser
function HTMLSurface.StopLoad(unBrowserHandle) end

---@param unBrowserHandle integer -- HHTMLBrowser
function HTMLSurface.Reload(unBrowserHandle) end

---@param unBrowserHandle integer -- HHTMLBrowser
function HTMLSurface.GoBack(unBrowserHandle) end

---@param unBrowserHandle integer -- HHTMLBrowser
function HTMLSurface.GoForward(unBrowserHandle) end

---@param unBrowserHandle integer -- HHTMLBrowser
---@param pchKey string?
---@param pchValue string?
function HTMLSurface.AddHeader(unBrowserHandle, pchKey, pchValue) end

---@param unBrowserHandle integer -- HHTMLBrowser
---@param pchScript string?
function HTMLSurface.ExecuteJavascript(unBrowserHandle, pchScript) end

---@param unBrowserHandle integer -- HHTMLBrowser
---@param eMouseButton integer -- ISteamHTMLSurface::EHTMLMouseButton
function HTMLSurface.MouseUp(unBrowserHandle, eMouseButton) end

---@param unBrowserHandle integer -- HHTMLBrowser
---@param eMouseButton integer -- ISteamHTMLSurface::EHTMLMouseButton
function HTMLSurface.MouseDown(unBrowserHandle, eMouseButton) end

---@param unBrowserHandle integer -- HHTMLBrowser
---@param eMouseButton integer -- ISteamHTMLSurface::EHTMLMouseButton
function HTMLSurface.MouseDoubleClick(unBrowserHandle, eMouseButton) end

---@param unBrowserHandle integer -- HHTMLBrowser
---@param x integer
---@param y integer
function HTMLSurface.MouseMove(unBrowserHandle, x, y) end

---@param unBrowserHandle integer -- HHTMLBrowser
---@param nDelta integer
function HTMLSurface.MouseWheel(unBrowserHandle, nDelta) end

---@param unBrowserHandle integer -- HHTMLBrowser
---@param nNativeKeyCode integer
---@param eHTMLKeyModifiers integer -- ISteamHTMLSurface::EHTMLKeyModifiers
---@param bIsSystemKey boolean
function HTMLSurface.KeyDown(unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers, bIsSystemKey) end

---@param unBrowserHandle integer -- HHTMLBrowser
---@param nNativeKeyCode integer
---@param eHTMLKeyModifiers integer -- ISteamHTMLSurface::EHTMLKeyModifiers
function HTMLSurface.KeyUp(unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers) end

---@param unBrowserHandle integer -- HHTMLBrowser
---@param cUnicodeChar integer
---@param eHTMLKeyModifiers integer -- ISteamHTMLSurface::EHTMLKeyModifiers
function HTMLSurface.KeyChar(unBrowserHandle, cUnicodeChar, eHTMLKeyModifiers) end

---@param unBrowserHandle integer -- HHTMLBrowser
---@param nAbsolutePixelScroll integer
function HTMLSurface.SetHorizontalScroll(unBrowserHandle, nAbsolutePixelScroll) end

---@param unBrowserHandle integer -- HHTMLBrowser
---@param nAbsolutePixelScroll integer
function HTMLSurface.SetVerticalScroll(unBrowserHandle, nAbsolutePixelScroll) end

---@param unBrowserHandle integer -- HHTMLBrowser
---@param bHasKeyFocus boolean
function HTMLSurface.SetKeyFocus(unBrowserHandle, bHasKeyFocus) end

---@param unBrowserHandle integer -- HHTMLBrowser
function HTMLSurface.ViewSource(unBrowserHandle) end

---@param unBrowserHandle integer -- HHTMLBrowser
function HTMLSurface.CopyToClipboard(unBrowserHandle) end

---@param unBrowserHandle integer -- HHTMLBrowser
function HTMLSurface.PasteFromClipboard(unBrowserHandle) end

---@param unBrowserHandle integer -- HHTMLBrowser
---@param pchSearchStr string?
---@param bCurrentlyInFind boolean
---@param bReverse boolean
function HTMLSurface.Find(unBrowserHandle, pchSearchStr, bCurrentlyInFind, bReverse) end

---@param unBrowserHandle integer -- HHTMLBrowser
function HTMLSurface.StopFind(unBrowserHandle) end

---@param unBrowserHandle integer -- HHTMLBrowser
---@param x integer
---@param y integer
function HTMLSurface.GetLinkAtPosition(unBrowserHandle, x, y) end

---@param pchHostname string?
---@param pchKey string?
---@param pchValue string?
---@param pchPath string?
---@param nExpires integer -- RTime32
---@param bSecure boolean
---@param bHTTPOnly boolean
function HTMLSurface.SetCookie(pchHostname, pchKey, pchValue, pchPath, nExpires, bSecure, bHTTPOnly) end

---@param unBrowserHandle integer -- HHTMLBrowser
---@param flZoom number
---@param nPointX integer
---@param nPointY integer
function HTMLSurface.SetPageScaleFactor(unBrowserHandle, flZoom, nPointX, nPointY) end

---@param unBrowserHandle integer -- HHTMLBrowser
---@param bBackgroundMode boolean
function HTMLSurface.SetBackgroundMode(unBrowserHandle, bBackgroundMode) end

---@param unBrowserHandle integer -- HHTMLBrowser
---@param flDPIScaling number
function HTMLSurface.SetDPIScalingFactor(unBrowserHandle, flDPIScaling) end

---@param unBrowserHandle integer -- HHTMLBrowser
function HTMLSurface.OpenDeveloperTools(unBrowserHandle) end

---@param unBrowserHandle integer -- HHTMLBrowser
---@param bAllowed boolean
function HTMLSurface.AllowStartRequest(unBrowserHandle, bAllowed) end

---@param unBrowserHandle integer -- HHTMLBrowser
---@param bResult boolean
function HTMLSurface.JSDialogResponse(unBrowserHandle, bResult) end

Steam.HTMLSurface = HTMLSurface
