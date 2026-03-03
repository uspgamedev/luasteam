#################
ISteamHTMLSurface
#################

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✍️ are manually implemented and methods marked with ✋ are currently not implemented.

List of Functions
-----------------

* :func:`HTMLSurface.AddHeader`
* :func:`HTMLSurface.AllowStartRequest`
* :func:`HTMLSurface.CopyToClipboard`
* :func:`HTMLSurface.CreateBrowser`
* :func:`HTMLSurface.ExecuteJavascript`
* :func:`HTMLSurface.Find`
* :func:`HTMLSurface.GetLinkAtPosition`
* :func:`HTMLSurface.GoBack`
* :func:`HTMLSurface.GoForward`
* :func:`HTMLSurface.Init`
* :func:`HTMLSurface.JSDialogResponse`
* :func:`HTMLSurface.KeyChar`
* :func:`HTMLSurface.KeyDown`
* :func:`HTMLSurface.KeyUp`
* :func:`HTMLSurface.LoadURL`
* :func:`HTMLSurface.MouseDoubleClick`
* :func:`HTMLSurface.MouseDown`
* :func:`HTMLSurface.MouseMove`
* :func:`HTMLSurface.MouseUp`
* :func:`HTMLSurface.MouseWheel`
* :func:`HTMLSurface.OpenDeveloperTools`
* :func:`HTMLSurface.PasteFromClipboard`
* :func:`HTMLSurface.Reload`
* :func:`HTMLSurface.RemoveBrowser`
* :func:`HTMLSurface.SetBackgroundMode`
* :func:`HTMLSurface.SetCookie`
* :func:`HTMLSurface.SetDPIScalingFactor`
* :func:`HTMLSurface.SetHorizontalScroll`
* :func:`HTMLSurface.SetKeyFocus`
* :func:`HTMLSurface.SetPageScaleFactor`
* :func:`HTMLSurface.SetSize`
* :func:`HTMLSurface.SetVerticalScroll`
* :func:`HTMLSurface.Shutdown`
* :func:`HTMLSurface.StopFind`
* :func:`HTMLSurface.StopLoad`
* :func:`HTMLSurface.ViewSource`

List of Callbacks
-----------------

* :func:`HTMLSurface.OnHTML_BrowserReady`
* :func:`HTMLSurface.OnHTML_NeedsPaint`
* :func:`HTMLSurface.OnHTML_StartRequest`
* :func:`HTMLSurface.OnHTML_CloseBrowser`
* :func:`HTMLSurface.OnHTML_URLChanged`
* :func:`HTMLSurface.OnHTML_FinishedRequest`
* :func:`HTMLSurface.OnHTML_OpenLinkInNewTab`
* :func:`HTMLSurface.OnHTML_ChangedTitle`
* :func:`HTMLSurface.OnHTML_SearchResults`
* :func:`HTMLSurface.OnHTML_CanGoBackAndForward`
* :func:`HTMLSurface.OnHTML_HorizontalScroll`
* :func:`HTMLSurface.OnHTML_VerticalScroll`
* :func:`HTMLSurface.OnHTML_LinkAtPosition`
* :func:`HTMLSurface.OnHTML_JSAlert`
* :func:`HTMLSurface.OnHTML_JSConfirm`
* :func:`HTMLSurface.OnHTML_FileOpenDialog`
* :func:`HTMLSurface.OnHTML_NewWindow`
* :func:`HTMLSurface.OnHTML_SetCursor`
* :func:`HTMLSurface.OnHTML_StatusText`
* :func:`HTMLSurface.OnHTML_ShowToolTip`
* :func:`HTMLSurface.OnHTML_UpdateToolTip`
* :func:`HTMLSurface.OnHTML_HideToolTip`
* :func:`HTMLSurface.OnHTML_BrowserRestarted`

Function Reference
------------------

.. function:: HTMLSurface.AddHeader(unBrowserHandle, pchKey, pchValue)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param str? pchKey:
    :param str? pchValue:
    :SteamWorks: `AddHeader <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#AddHeader>`_

.. function:: HTMLSurface.AllowStartRequest(unBrowserHandle, bAllowed)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param bool bAllowed:
    :SteamWorks: `AllowStartRequest <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#AllowStartRequest>`_

.. function:: HTMLSurface.CopyToClipboard(unBrowserHandle)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :SteamWorks: `CopyToClipboard <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#CopyToClipboard>`_

.. function:: HTMLSurface.CreateBrowser(pchUserAgent, pchUserCSS, callback)

    🤖 **Auto-generated binding**

    :param str? pchUserAgent:
    :param str? pchUserCSS:
    :param function callback: CallResult callback receiving struct :func:`HTML_BrowserReady_t <HTMLSurface.OnHTML_BrowserReady>` and a boolean
    :returns: (uint64) ``SteamAPICall_t`` handle for this async call. The result is delivered via the ``callback`` parameter when :func:`Steam.RunCallbacks` is called.
    :SteamWorks: `CreateBrowser <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#CreateBrowser>`_

**Example**::

    Steam.HTMLSurface.CreateBrowser(nil, nil, function(data, err)
        if not err then
            local hBrowser = data.unBrowserHandle
            Steam.HTMLSurface.SetSize(hBrowser, 1280, 720)
            Steam.HTMLSurface.LoadURL(hBrowser, 'https://store.steampowered.com', nil)
        end
    end)

.. function:: HTMLSurface.ExecuteJavascript(unBrowserHandle, pchScript)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param str? pchScript:
    :SteamWorks: `ExecuteJavascript <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#ExecuteJavascript>`_

**Example**::

    Steam.HTMLSurface.ExecuteJavascript(hBrowser, 'document.title = "Hello from Lua";')

.. function:: HTMLSurface.Find(unBrowserHandle, pchSearchStr, bCurrentlyInFind, bReverse)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param str? pchSearchStr:
    :param bool bCurrentlyInFind:
    :param bool bReverse:
    :SteamWorks: `Find <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#Find>`_

**Example**::

    Steam.HTMLSurface.Find(hBrowser, 'search term', false, false)

.. function:: HTMLSurface.GetLinkAtPosition(unBrowserHandle, x, y)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param int x:
    :param int y:
    :SteamWorks: `GetLinkAtPosition <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#GetLinkAtPosition>`_

.. function:: HTMLSurface.GoBack(unBrowserHandle)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :SteamWorks: `GoBack <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#GoBack>`_

**Example**::

    Steam.HTMLSurface.GoBack(hBrowser)

.. function:: HTMLSurface.GoForward(unBrowserHandle)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :SteamWorks: `GoForward <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#GoForward>`_

**Example**::

    Steam.HTMLSurface.GoForward(hBrowser)

.. function:: HTMLSurface.Init()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `Init <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#Init>`_

**Example**::

    Steam.HTMLSurface.Init()

.. function:: HTMLSurface.JSDialogResponse(unBrowserHandle, bResult)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param bool bResult:
    :SteamWorks: `JSDialogResponse <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#JSDialogResponse>`_

.. function:: HTMLSurface.KeyChar(unBrowserHandle, cUnicodeChar, eHTMLKeyModifiers)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param int cUnicodeChar:
    :param int eHTMLKeyModifiers:
    :SteamWorks: `KeyChar <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#KeyChar>`_

**Example**::

    Steam.HTMLSurface.KeyChar(hBrowser, string.byte(char), 0)

.. function:: HTMLSurface.KeyDown(unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers, bIsSystemKey)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param int nNativeKeyCode:
    :param int eHTMLKeyModifiers:
    :param bool bIsSystemKey:
    :SteamWorks: `KeyDown <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#KeyDown>`_

**Example**::

    Steam.HTMLSurface.KeyDown(hBrowser, nativeKeyCode, 0, false)

.. function:: HTMLSurface.KeyUp(unBrowserHandle, nNativeKeyCode, eHTMLKeyModifiers)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param int nNativeKeyCode:
    :param int eHTMLKeyModifiers:
    :SteamWorks: `KeyUp <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#KeyUp>`_

**Example**::

    Steam.HTMLSurface.KeyUp(hBrowser, nativeKeyCode, 0)

.. function:: HTMLSurface.LoadURL(unBrowserHandle, pchURL, pchPostData)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param str? pchURL:
    :param str? pchPostData:
    :SteamWorks: `LoadURL <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#LoadURL>`_

    **Notes:**

    * See :func:`HTMLSurface.CreateBrowser`'s example.

.. function:: HTMLSurface.MouseDoubleClick(unBrowserHandle, eMouseButton)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param int eMouseButton:
    :SteamWorks: `MouseDoubleClick <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#MouseDoubleClick>`_

.. function:: HTMLSurface.MouseDown(unBrowserHandle, eMouseButton)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param int eMouseButton:
    :SteamWorks: `MouseDown <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#MouseDown>`_

**Example**::

    Steam.HTMLSurface.MouseDown(hBrowser, Steam.eHTMLMouseButton_Left)

.. function:: HTMLSurface.MouseMove(unBrowserHandle, x, y)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param int x:
    :param int y:
    :SteamWorks: `MouseMove <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#MouseMove>`_

**Example**::

    -- Pass mouse events to the HTML surface
    Steam.HTMLSurface.MouseMove(hBrowser, mouseX, mouseY)

.. function:: HTMLSurface.MouseUp(unBrowserHandle, eMouseButton)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param int eMouseButton:
    :SteamWorks: `MouseUp <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#MouseUp>`_

**Example**::

    Steam.HTMLSurface.MouseUp(hBrowser, Steam.eHTMLMouseButton_Left)

.. function:: HTMLSurface.MouseWheel(unBrowserHandle, nDelta)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param int nDelta:
    :SteamWorks: `MouseWheel <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#MouseWheel>`_

**Example**::

    Steam.HTMLSurface.MouseWheel(hBrowser, -120)  -- scroll down

.. function:: HTMLSurface.OpenDeveloperTools(unBrowserHandle)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :SteamWorks: `OpenDeveloperTools <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#OpenDeveloperTools>`_

.. function:: HTMLSurface.PasteFromClipboard(unBrowserHandle)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :SteamWorks: `PasteFromClipboard <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#PasteFromClipboard>`_

.. function:: HTMLSurface.Reload(unBrowserHandle)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :SteamWorks: `Reload <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#Reload>`_

**Example**::

    Steam.HTMLSurface.Reload(hBrowser)

.. function:: HTMLSurface.RemoveBrowser(unBrowserHandle)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :SteamWorks: `RemoveBrowser <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#RemoveBrowser>`_

**Example**::

    Steam.HTMLSurface.RemoveBrowser(hBrowser)

.. function:: HTMLSurface.SetBackgroundMode(unBrowserHandle, bBackgroundMode)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param bool bBackgroundMode:
    :SteamWorks: `SetBackgroundMode <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#SetBackgroundMode>`_

.. function:: HTMLSurface.SetCookie(pchHostname, pchKey, pchValue, pchPath, nExpires, bSecure, bHTTPOnly)

    🤖 **Auto-generated binding**

    :param str? pchHostname:
    :param str? pchKey:
    :param str? pchValue:
    :param str? pchPath:
    :param int nExpires:
    :param bool bSecure:
    :param bool bHTTPOnly:
    :SteamWorks: `SetCookie <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#SetCookie>`_

.. function:: HTMLSurface.SetDPIScalingFactor(unBrowserHandle, flDPIScaling)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param float flDPIScaling:
    :SteamWorks: `SetDPIScalingFactor <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#SetDPIScalingFactor>`_

.. function:: HTMLSurface.SetHorizontalScroll(unBrowserHandle, nAbsolutePixelScroll)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param int nAbsolutePixelScroll:
    :SteamWorks: `SetHorizontalScroll <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#SetHorizontalScroll>`_

**Example**::

    Steam.HTMLSurface.SetHorizontalScroll(hBrowser, 0)

.. function:: HTMLSurface.SetKeyFocus(unBrowserHandle, bHasKeyFocus)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param bool bHasKeyFocus:
    :SteamWorks: `SetKeyFocus <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#SetKeyFocus>`_

.. function:: HTMLSurface.SetPageScaleFactor(unBrowserHandle, flZoom, nPointX, nPointY)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param float flZoom:
    :param int nPointX:
    :param int nPointY:
    :SteamWorks: `SetPageScaleFactor <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#SetPageScaleFactor>`_

.. function:: HTMLSurface.SetSize(unBrowserHandle, unWidth, unHeight)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param int unWidth:
    :param int unHeight:
    :SteamWorks: `SetSize <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#SetSize>`_

    **Notes:**

    * See :func:`HTMLSurface.CreateBrowser`'s example.

.. function:: HTMLSurface.SetVerticalScroll(unBrowserHandle, nAbsolutePixelScroll)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :param int nAbsolutePixelScroll:
    :SteamWorks: `SetVerticalScroll <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#SetVerticalScroll>`_

**Example**::

    Steam.HTMLSurface.SetVerticalScroll(hBrowser, scrollPos)

.. function:: HTMLSurface.Shutdown()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `Shutdown <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#Shutdown>`_

**Example**::

    Steam.HTMLSurface.Shutdown()

.. function:: HTMLSurface.StopFind(unBrowserHandle)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :SteamWorks: `StopFind <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#StopFind>`_

**Example**::

    Steam.HTMLSurface.StopFind(hBrowser)

.. function:: HTMLSurface.StopLoad(unBrowserHandle)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :SteamWorks: `StopLoad <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#StopLoad>`_

**Example**::

    Steam.HTMLSurface.StopLoad(hBrowser)

.. function:: HTMLSurface.ViewSource(unBrowserHandle)

    🤖 **Auto-generated binding**

    :param int unBrowserHandle:
    :SteamWorks: `ViewSource <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#ViewSource>`_


Unimplemented Methods
---------------------

.. function:: HTMLSurface.fileLoadDialogResponse

    ✋ **Not implemented** - unsupported type: const char **
    
    :SteamWorks: `FileLoadDialogResponse <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#FileLoadDialogResponse>`_


Callbacks
---------

.. function:: HTMLSurface.OnHTML_BrowserReady

    Callback for `HTML_BrowserReady_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_BrowserReady_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** *(HHTMLBrowser)*

.. function:: HTMLSurface.OnHTML_NeedsPaint

    Callback for `HTML_NeedsPaint_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_NeedsPaint_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** *(HHTMLBrowser)*
    * **data.pBGRA** *(string)*
    * **data.unWide** *(int)*
    * **data.unTall** *(int)*
    * **data.unUpdateX** *(int)*
    * **data.unUpdateY** *(int)*
    * **data.unUpdateWide** *(int)*
    * **data.unUpdateTall** *(int)*
    * **data.unScrollX** *(int)*
    * **data.unScrollY** *(int)*
    * **data.flPageScale** *(float)*
    * **data.unPageSerial** *(int)*

**Example**::

    function Steam.HTMLSurface.OnHTML_NeedsPaint(data)
        -- data.pBGRA contains raw BGRA pixel data
        -- data.unWide, data.unTall = dimensions
        updateBrowserTexture(data.pBGRA, data.unWide, data.unTall)
    end

.. function:: HTMLSurface.OnHTML_StartRequest

    Callback for `HTML_StartRequest_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_StartRequest_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** *(HHTMLBrowser)*
    * **data.pchURL** *(string)*
    * **data.pchTarget** *(string)*
    * **data.pchPostData** *(string)*
    * **data.bIsRedirect** *(bool)*

**Example**::

    function Steam.HTMLSurface.OnHTML_StartRequest(data)
        print('Navigating to:', data.pchURL)
        -- Call AllowStartRequest to allow or block navigation
        Steam.HTMLSurface.AllowStartRequest(data.unBrowserHandle, true)
    end

.. function:: HTMLSurface.OnHTML_CloseBrowser

    Callback for `HTML_CloseBrowser_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_CloseBrowser_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** *(HHTMLBrowser)*

.. function:: HTMLSurface.OnHTML_URLChanged

    Callback for `HTML_URLChanged_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_URLChanged_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** *(HHTMLBrowser)*
    * **data.pchURL** *(string)*
    * **data.pchPostData** *(string)*
    * **data.bIsRedirect** *(bool)*
    * **data.pchPageTitle** *(string)*
    * **data.bNewNavigation** *(bool)*

**Example**::

    function Steam.HTMLSurface.OnHTML_URLChanged(data)
        print('URL changed to:', data.pchURL)
        updateAddressBar(data.pchURL)
    end

.. function:: HTMLSurface.OnHTML_FinishedRequest

    Callback for `HTML_FinishedRequest_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_FinishedRequest_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** *(HHTMLBrowser)*
    * **data.pchURL** *(string)*
    * **data.pchPageTitle** *(string)*

**Example**::

    function Steam.HTMLSurface.OnHTML_FinishedRequest(data)
        print('Page loaded:', data.pchURL)
        hideLoadingSpinner()
    end

.. function:: HTMLSurface.OnHTML_OpenLinkInNewTab

    Callback for `HTML_OpenLinkInNewTab_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_OpenLinkInNewTab_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** *(HHTMLBrowser)*
    * **data.pchURL** *(string)*

.. function:: HTMLSurface.OnHTML_ChangedTitle

    Callback for `HTML_ChangedTitle_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_ChangedTitle_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** *(HHTMLBrowser)*
    * **data.pchTitle** *(string)*

**Example**::

    function Steam.HTMLSurface.OnHTML_ChangedTitle(data)
        windowTitle = data.pchTitle
    end

.. function:: HTMLSurface.OnHTML_SearchResults

    Callback for `HTML_SearchResults_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_SearchResults_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** *(HHTMLBrowser)*
    * **data.unResults** *(int)*
    * **data.unCurrentMatch** *(int)*

.. function:: HTMLSurface.OnHTML_CanGoBackAndForward

    Callback for `HTML_CanGoBackAndForward_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_CanGoBackAndForward_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** *(HHTMLBrowser)*
    * **data.bCanGoBack** *(bool)*
    * **data.bCanGoForward** *(bool)*

.. function:: HTMLSurface.OnHTML_HorizontalScroll

    Callback for `HTML_HorizontalScroll_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_HorizontalScroll_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** *(HHTMLBrowser)*
    * **data.unScrollMax** *(int)*
    * **data.unScrollCurrent** *(int)*
    * **data.flPageScale** *(float)*
    * **data.bVisible** *(bool)*
    * **data.unPageSize** *(int)*

.. function:: HTMLSurface.OnHTML_VerticalScroll

    Callback for `HTML_VerticalScroll_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_VerticalScroll_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** *(HHTMLBrowser)*
    * **data.unScrollMax** *(int)*
    * **data.unScrollCurrent** *(int)*
    * **data.flPageScale** *(float)*
    * **data.bVisible** *(bool)*
    * **data.unPageSize** *(int)*

.. function:: HTMLSurface.OnHTML_LinkAtPosition

    Callback for `HTML_LinkAtPosition_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_LinkAtPosition_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** *(HHTMLBrowser)*
    * **data.x** *(int)*
    * **data.y** *(int)*
    * **data.pchURL** *(string)*
    * **data.bInput** *(bool)*
    * **data.bLiveLink** *(bool)*

.. function:: HTMLSurface.OnHTML_JSAlert

    Callback for `HTML_JSAlert_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_JSAlert_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** *(HHTMLBrowser)*
    * **data.pchMessage** *(string)*

**Example**::

    function Steam.HTMLSurface.OnHTML_JSAlert(data)
        showAlertDialog(data.pchMessage)
        Steam.HTMLSurface.JSDialogResponse(data.unBrowserHandle, true)
    end

.. function:: HTMLSurface.OnHTML_JSConfirm

    Callback for `HTML_JSConfirm_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_JSConfirm_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** *(HHTMLBrowser)*
    * **data.pchMessage** *(string)*

.. function:: HTMLSurface.OnHTML_FileOpenDialog

    Callback for `HTML_FileOpenDialog_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_FileOpenDialog_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** *(HHTMLBrowser)*
    * **data.pchTitle** *(string)*
    * **data.pchInitialFile** *(string)*

.. function:: HTMLSurface.OnHTML_NewWindow

    Callback for `HTML_NewWindow_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_NewWindow_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** *(HHTMLBrowser)*
    * **data.pchURL** *(string)*
    * **data.unX** *(int)*
    * **data.unY** *(int)*
    * **data.unWide** *(int)*
    * **data.unTall** *(int)*
    * **data.unNewWindow_BrowserHandle_IGNORE** *(HHTMLBrowser)*

.. function:: HTMLSurface.OnHTML_SetCursor

    Callback for `HTML_SetCursor_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_SetCursor_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** *(HHTMLBrowser)*
    * **data.eMouseCursor** *(int)*

.. function:: HTMLSurface.OnHTML_StatusText

    Callback for `HTML_StatusText_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_StatusText_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** *(HHTMLBrowser)*
    * **data.pchMsg** *(string)*

.. function:: HTMLSurface.OnHTML_ShowToolTip

    Callback for `HTML_ShowToolTip_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_ShowToolTip_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** *(HHTMLBrowser)*
    * **data.pchMsg** *(string)*

.. function:: HTMLSurface.OnHTML_UpdateToolTip

    Callback for `HTML_UpdateToolTip_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_UpdateToolTip_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** *(HHTMLBrowser)*
    * **data.pchMsg** *(string)*

.. function:: HTMLSurface.OnHTML_HideToolTip

    Callback for `HTML_HideToolTip_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_HideToolTip_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** *(HHTMLBrowser)*

.. function:: HTMLSurface.OnHTML_BrowserRestarted

    Callback for `HTML_BrowserRestarted_t <https://partner.steamgames.com/doc/api/ISteamHTMLSurface#HTML_BrowserRestarted_t>`_

    **callback(data)** receives:

    * **data.unBrowserHandle** *(HHTMLBrowser)*
    * **data.unOldBrowserHandle** *(HHTMLBrowser)*

