#################
ISteamHTMLSurface
#################

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✋ require manual implementation.

List of Functions
-----------------

* :func:`HTMLSurface.Init`
* :func:`HTMLSurface.Shutdown`
* :func:`HTMLSurface.CreateBrowser`
* :func:`HTMLSurface.RemoveBrowser`
* :func:`HTMLSurface.LoadURL`
* :func:`HTMLSurface.SetSize`
* :func:`HTMLSurface.StopLoad`
* :func:`HTMLSurface.Reload`
* :func:`HTMLSurface.GoBack`
* :func:`HTMLSurface.GoForward`
* :func:`HTMLSurface.AddHeader`
* :func:`HTMLSurface.ExecuteJavascript`
* :func:`HTMLSurface.MouseMove`
* :func:`HTMLSurface.MouseWheel`
* :func:`HTMLSurface.SetHorizontalScroll`
* :func:`HTMLSurface.SetVerticalScroll`
* :func:`HTMLSurface.SetKeyFocus`
* :func:`HTMLSurface.ViewSource`
* :func:`HTMLSurface.CopyToClipboard`
* :func:`HTMLSurface.PasteFromClipboard`
* :func:`HTMLSurface.Find`
* :func:`HTMLSurface.StopFind`
* :func:`HTMLSurface.GetLinkAtPosition`
* :func:`HTMLSurface.SetCookie`
* :func:`HTMLSurface.SetPageScaleFactor`
* :func:`HTMLSurface.SetBackgroundMode`
* :func:`HTMLSurface.SetDPIScalingFactor`
* :func:`HTMLSurface.OpenDeveloperTools`
* :func:`HTMLSurface.AllowStartRequest`
* :func:`HTMLSurface.JSDialogResponse`

List of Callbacks
-----------------

* :func:`HTMLSurface.onHTML_BrowserReady`
* :func:`HTMLSurface.onHTML_NeedsPaint`
* :func:`HTMLSurface.onHTML_StartRequest`
* :func:`HTMLSurface.onHTML_CloseBrowser`
* :func:`HTMLSurface.onHTML_URLChanged`
* :func:`HTMLSurface.onHTML_FinishedRequest`
* :func:`HTMLSurface.onHTML_OpenLinkInNewTab`
* :func:`HTMLSurface.onHTML_ChangedTitle`
* :func:`HTMLSurface.onHTML_SearchResults`
* :func:`HTMLSurface.onHTML_CanGoBackAndForward`
* :func:`HTMLSurface.onHTML_HorizontalScroll`
* :func:`HTMLSurface.onHTML_VerticalScroll`
* :func:`HTMLSurface.onHTML_LinkAtPosition`
* :func:`HTMLSurface.onHTML_JSAlert`
* :func:`HTMLSurface.onHTML_JSConfirm`
* :func:`HTMLSurface.onHTML_FileOpenDialog`
* :func:`HTMLSurface.onHTML_NewWindow`
* :func:`HTMLSurface.onHTML_SetCursor`
* :func:`HTMLSurface.onHTML_StatusText`
* :func:`HTMLSurface.onHTML_ShowToolTip`
* :func:`HTMLSurface.onHTML_UpdateToolTip`
* :func:`HTMLSurface.onHTML_HideToolTip`
* :func:`HTMLSurface.onHTML_BrowserRestarted`

Function Reference
------------------

.. function:: HTMLSurface.Init()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `Init <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#Init>`_

.. function:: HTMLSurface.Shutdown()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `Shutdown <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#Shutdown>`_

.. function:: HTMLSurface.CreateBrowser(pchUserAgent, pchUserCSS, callback)

    🤖 **Auto-generated binding**

    :param str pchUserAgent:
    :param str pchUserCSS:
    :param function callback: CallResult callback receiving struct `HTML_BrowserReady_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `CreateBrowser <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#CreateBrowser>`_

.. function:: HTMLSurface.RemoveBrowser(unBrowserHandle)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :SteamWorks: `RemoveBrowser <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#RemoveBrowser>`_

.. function:: HTMLSurface.LoadURL(unBrowserHandle, pchURL, pchPostData)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param str pchURL:
    :param str pchPostData:
    :SteamWorks: `LoadURL <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#LoadURL>`_

.. function:: HTMLSurface.SetSize(unBrowserHandle, unWidth, unHeight)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param int unWidth:
    :param int unHeight:
    :SteamWorks: `SetSize <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#SetSize>`_

.. function:: HTMLSurface.StopLoad(unBrowserHandle)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :SteamWorks: `StopLoad <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#StopLoad>`_

.. function:: HTMLSurface.Reload(unBrowserHandle)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :SteamWorks: `Reload <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#Reload>`_

.. function:: HTMLSurface.GoBack(unBrowserHandle)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :SteamWorks: `GoBack <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#GoBack>`_

.. function:: HTMLSurface.GoForward(unBrowserHandle)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :SteamWorks: `GoForward <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#GoForward>`_

.. function:: HTMLSurface.AddHeader(unBrowserHandle, pchKey, pchValue)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param str pchKey:
    :param str pchValue:
    :SteamWorks: `AddHeader <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#AddHeader>`_

.. function:: HTMLSurface.ExecuteJavascript(unBrowserHandle, pchScript)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param str pchScript:
    :SteamWorks: `ExecuteJavascript <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#ExecuteJavascript>`_

.. function:: HTMLSurface.MouseMove(unBrowserHandle, x, y)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param int x:
    :param int y:
    :SteamWorks: `MouseMove <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#MouseMove>`_

.. function:: HTMLSurface.MouseWheel(unBrowserHandle, nDelta)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param int nDelta:
    :SteamWorks: `MouseWheel <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#MouseWheel>`_

.. function:: HTMLSurface.SetHorizontalScroll(unBrowserHandle, nAbsolutePixelScroll)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param int nAbsolutePixelScroll:
    :SteamWorks: `SetHorizontalScroll <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#SetHorizontalScroll>`_

.. function:: HTMLSurface.SetVerticalScroll(unBrowserHandle, nAbsolutePixelScroll)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param int nAbsolutePixelScroll:
    :SteamWorks: `SetVerticalScroll <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#SetVerticalScroll>`_

.. function:: HTMLSurface.SetKeyFocus(unBrowserHandle, bHasKeyFocus)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param bool bHasKeyFocus:
    :SteamWorks: `SetKeyFocus <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#SetKeyFocus>`_

.. function:: HTMLSurface.ViewSource(unBrowserHandle)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :SteamWorks: `ViewSource <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#ViewSource>`_

.. function:: HTMLSurface.CopyToClipboard(unBrowserHandle)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :SteamWorks: `CopyToClipboard <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#CopyToClipboard>`_

.. function:: HTMLSurface.PasteFromClipboard(unBrowserHandle)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :SteamWorks: `PasteFromClipboard <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#PasteFromClipboard>`_

.. function:: HTMLSurface.Find(unBrowserHandle, pchSearchStr, bCurrentlyInFind, bReverse)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param str pchSearchStr:
    :param bool bCurrentlyInFind:
    :param bool bReverse:
    :SteamWorks: `Find <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#Find>`_

.. function:: HTMLSurface.StopFind(unBrowserHandle)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :SteamWorks: `StopFind <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#StopFind>`_

.. function:: HTMLSurface.GetLinkAtPosition(unBrowserHandle, x, y)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param int x:
    :param int y:
    :SteamWorks: `GetLinkAtPosition <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#GetLinkAtPosition>`_

.. function:: HTMLSurface.SetCookie(pchHostname, pchKey, pchValue, pchPath, nExpires, bSecure, bHTTPOnly)

    🤖 **Auto-generated binding**

    :param str pchHostname:
    :param str pchKey:
    :param str pchValue:
    :param str pchPath:
    :param int nExpires:
    :param bool bSecure:
    :param bool bHTTPOnly:
    :SteamWorks: `SetCookie <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#SetCookie>`_

.. function:: HTMLSurface.SetPageScaleFactor(unBrowserHandle, flZoom, nPointX, nPointY)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param float flZoom:
    :param int nPointX:
    :param int nPointY:
    :SteamWorks: `SetPageScaleFactor <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#SetPageScaleFactor>`_

.. function:: HTMLSurface.SetBackgroundMode(unBrowserHandle, bBackgroundMode)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param bool bBackgroundMode:
    :SteamWorks: `SetBackgroundMode <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#SetBackgroundMode>`_

.. function:: HTMLSurface.SetDPIScalingFactor(unBrowserHandle, flDPIScaling)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param float flDPIScaling:
    :SteamWorks: `SetDPIScalingFactor <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#SetDPIScalingFactor>`_

.. function:: HTMLSurface.OpenDeveloperTools(unBrowserHandle)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :SteamWorks: `OpenDeveloperTools <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#OpenDeveloperTools>`_

.. function:: HTMLSurface.AllowStartRequest(unBrowserHandle, bAllowed)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param bool bAllowed:
    :SteamWorks: `AllowStartRequest <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#AllowStartRequest>`_

.. function:: HTMLSurface.JSDialogResponse(unBrowserHandle, bResult)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param bool bResult:
    :SteamWorks: `JSDialogResponse <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#JSDialogResponse>`_


Unimplemented Methods
---------------------

.. function:: HTMLSurface.mouseUp

    ✋ **Not implemented** - unsupported type: ISteamHTMLSurface::EHTMLMouseButton
    
    :SteamWorks: `MouseUp <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#MouseUp>`_

.. function:: HTMLSurface.mouseDown

    ✋ **Not implemented** - unsupported type: ISteamHTMLSurface::EHTMLMouseButton
    
    :SteamWorks: `MouseDown <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#MouseDown>`_

.. function:: HTMLSurface.mouseDoubleClick

    ✋ **Not implemented** - unsupported type: ISteamHTMLSurface::EHTMLMouseButton
    
    :SteamWorks: `MouseDoubleClick <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#MouseDoubleClick>`_

.. function:: HTMLSurface.keyDown

    ✋ **Not implemented** - unsupported type: ISteamHTMLSurface::EHTMLKeyModifiers
    
    :SteamWorks: `KeyDown <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#KeyDown>`_

.. function:: HTMLSurface.keyUp

    ✋ **Not implemented** - unsupported type: ISteamHTMLSurface::EHTMLKeyModifiers
    
    :SteamWorks: `KeyUp <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#KeyUp>`_

.. function:: HTMLSurface.keyChar

    ✋ **Not implemented** - unsupported type: ISteamHTMLSurface::EHTMLKeyModifiers
    
    :SteamWorks: `KeyChar <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#KeyChar>`_

.. function:: HTMLSurface.fileLoadDialogResponse

    ✋ **Not implemented** - unsupported type: const char **
    
    :SteamWorks: `FileLoadDialogResponse <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#FileLoadDialogResponse>`_


Callbacks
---------

.. function:: HTMLSurface.onHTML_BrowserReady

    Callback for `HTML_BrowserReady_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_BrowserReady_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** -- unBrowserHandle

.. function:: HTMLSurface.onHTML_NeedsPaint

    Callback for `HTML_NeedsPaint_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_NeedsPaint_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** -- unBrowserHandle
    * **data.pBGRA** -- pBGRA
    * **data.unWide** -- unWide
    * **data.unTall** -- unTall
    * **data.unUpdateX** -- unUpdateX
    * **data.unUpdateY** -- unUpdateY
    * **data.unUpdateWide** -- unUpdateWide
    * **data.unUpdateTall** -- unUpdateTall
    * **data.unScrollX** -- unScrollX
    * **data.unScrollY** -- unScrollY
    * **data.flPageScale** -- flPageScale
    * **data.unPageSerial** -- unPageSerial

.. function:: HTMLSurface.onHTML_StartRequest

    Callback for `HTML_StartRequest_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_StartRequest_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** -- unBrowserHandle
    * **data.pchURL** -- pchURL
    * **data.pchTarget** -- pchTarget
    * **data.pchPostData** -- pchPostData
    * **data.bIsRedirect** -- bIsRedirect

.. function:: HTMLSurface.onHTML_CloseBrowser

    Callback for `HTML_CloseBrowser_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_CloseBrowser_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** -- unBrowserHandle

.. function:: HTMLSurface.onHTML_URLChanged

    Callback for `HTML_URLChanged_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_URLChanged_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** -- unBrowserHandle
    * **data.pchURL** -- pchURL
    * **data.pchPostData** -- pchPostData
    * **data.bIsRedirect** -- bIsRedirect
    * **data.pchPageTitle** -- pchPageTitle
    * **data.bNewNavigation** -- bNewNavigation

.. function:: HTMLSurface.onHTML_FinishedRequest

    Callback for `HTML_FinishedRequest_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_FinishedRequest_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** -- unBrowserHandle
    * **data.pchURL** -- pchURL
    * **data.pchPageTitle** -- pchPageTitle

.. function:: HTMLSurface.onHTML_OpenLinkInNewTab

    Callback for `HTML_OpenLinkInNewTab_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_OpenLinkInNewTab_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** -- unBrowserHandle
    * **data.pchURL** -- pchURL

.. function:: HTMLSurface.onHTML_ChangedTitle

    Callback for `HTML_ChangedTitle_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_ChangedTitle_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** -- unBrowserHandle
    * **data.pchTitle** -- pchTitle

.. function:: HTMLSurface.onHTML_SearchResults

    Callback for `HTML_SearchResults_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_SearchResults_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** -- unBrowserHandle
    * **data.unResults** -- unResults
    * **data.unCurrentMatch** -- unCurrentMatch

.. function:: HTMLSurface.onHTML_CanGoBackAndForward

    Callback for `HTML_CanGoBackAndForward_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_CanGoBackAndForward_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** -- unBrowserHandle
    * **data.bCanGoBack** -- bCanGoBack
    * **data.bCanGoForward** -- bCanGoForward

.. function:: HTMLSurface.onHTML_HorizontalScroll

    Callback for `HTML_HorizontalScroll_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_HorizontalScroll_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** -- unBrowserHandle
    * **data.unScrollMax** -- unScrollMax
    * **data.unScrollCurrent** -- unScrollCurrent
    * **data.flPageScale** -- flPageScale
    * **data.bVisible** -- bVisible
    * **data.unPageSize** -- unPageSize

.. function:: HTMLSurface.onHTML_VerticalScroll

    Callback for `HTML_VerticalScroll_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_VerticalScroll_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** -- unBrowserHandle
    * **data.unScrollMax** -- unScrollMax
    * **data.unScrollCurrent** -- unScrollCurrent
    * **data.flPageScale** -- flPageScale
    * **data.bVisible** -- bVisible
    * **data.unPageSize** -- unPageSize

.. function:: HTMLSurface.onHTML_LinkAtPosition

    Callback for `HTML_LinkAtPosition_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_LinkAtPosition_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** -- unBrowserHandle
    * **data.x** -- x
    * **data.y** -- y
    * **data.pchURL** -- pchURL
    * **data.bInput** -- bInput
    * **data.bLiveLink** -- bLiveLink

.. function:: HTMLSurface.onHTML_JSAlert

    Callback for `HTML_JSAlert_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_JSAlert_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** -- unBrowserHandle
    * **data.pchMessage** -- pchMessage

.. function:: HTMLSurface.onHTML_JSConfirm

    Callback for `HTML_JSConfirm_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_JSConfirm_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** -- unBrowserHandle
    * **data.pchMessage** -- pchMessage

.. function:: HTMLSurface.onHTML_FileOpenDialog

    Callback for `HTML_FileOpenDialog_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_FileOpenDialog_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** -- unBrowserHandle
    * **data.pchTitle** -- pchTitle
    * **data.pchInitialFile** -- pchInitialFile

.. function:: HTMLSurface.onHTML_NewWindow

    Callback for `HTML_NewWindow_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_NewWindow_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** -- unBrowserHandle
    * **data.pchURL** -- pchURL
    * **data.unX** -- unX
    * **data.unY** -- unY
    * **data.unWide** -- unWide
    * **data.unTall** -- unTall
    * **data.unNewWindow_BrowserHandle_IGNORE** -- unNewWindow_BrowserHandle_IGNORE

.. function:: HTMLSurface.onHTML_SetCursor

    Callback for `HTML_SetCursor_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_SetCursor_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** -- unBrowserHandle
    * **data.eMouseCursor** -- eMouseCursor

.. function:: HTMLSurface.onHTML_StatusText

    Callback for `HTML_StatusText_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_StatusText_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** -- unBrowserHandle
    * **data.pchMsg** -- pchMsg

.. function:: HTMLSurface.onHTML_ShowToolTip

    Callback for `HTML_ShowToolTip_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_ShowToolTip_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** -- unBrowserHandle
    * **data.pchMsg** -- pchMsg

.. function:: HTMLSurface.onHTML_UpdateToolTip

    Callback for `HTML_UpdateToolTip_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_UpdateToolTip_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** -- unBrowserHandle
    * **data.pchMsg** -- pchMsg

.. function:: HTMLSurface.onHTML_HideToolTip

    Callback for `HTML_HideToolTip_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_HideToolTip_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** -- unBrowserHandle

.. function:: HTMLSurface.onHTML_BrowserRestarted

    Callback for `HTML_BrowserRestarted_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_BrowserRestarted_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** -- unBrowserHandle
    * **data.unOldBrowserHandle** -- unOldBrowserHandle

