##########
ISteamHTTP
##########

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✍️ are manually implemented and methods marked with ✋ are currently not implemented.

List of Functions
-----------------

* :func:`HTTP.CreateCookieContainer`
* :func:`HTTP.CreateHTTPRequest`
* :func:`HTTP.DeferHTTPRequest`
* :func:`HTTP.GetHTTPDownloadProgressPct`
* :func:`HTTP.GetHTTPRequestWasTimedOut`
* :func:`HTTP.GetHTTPResponseBodyData`
* :func:`HTTP.GetHTTPResponseBodySize`
* :func:`HTTP.GetHTTPResponseHeaderSize`
* :func:`HTTP.GetHTTPResponseHeaderValue`
* :func:`HTTP.GetHTTPStreamingResponseBodyData`
* :func:`HTTP.PrioritizeHTTPRequest`
* :func:`HTTP.ReleaseCookieContainer`
* :func:`HTTP.ReleaseHTTPRequest`
* :func:`HTTP.SendHTTPRequest`
* :func:`HTTP.SendHTTPRequestAndStreamResponse`
* :func:`HTTP.SetCookie`
* :func:`HTTP.SetHTTPRequestAbsoluteTimeoutMS`
* :func:`HTTP.SetHTTPRequestContextValue`
* :func:`HTTP.SetHTTPRequestCookieContainer`
* :func:`HTTP.SetHTTPRequestGetOrPostParameter`
* :func:`HTTP.SetHTTPRequestHeaderValue`
* :func:`HTTP.SetHTTPRequestNetworkActivityTimeout`
* :func:`HTTP.SetHTTPRequestRawPostBody`
* :func:`HTTP.SetHTTPRequestRequiresVerifiedCertificate`
* :func:`HTTP.SetHTTPRequestUserAgentInfo`

List of Callbacks
-----------------

* :func:`HTTP.OnHTTPRequestCompleted`
* :func:`HTTP.OnHTTPRequestHeadersReceived`
* :func:`HTTP.OnHTTPRequestDataReceived`

Function Reference
------------------

.. function:: HTTP.CreateCookieContainer(bAllowResponsesToModify)

    🤖 **Auto-generated binding**

    :param bool bAllowResponsesToModify:
    :returns: (int - HTTPCookieContainerHandle) Return value
    :SteamWorks: `CreateCookieContainer <https://partner.steamgames.com/doc/api/ISteamHTTP#CreateCookieContainer>`_

.. function:: HTTP.CreateHTTPRequest(eHTTPRequestMethod, pchAbsoluteURL)

    🤖 **Auto-generated binding**

    :param int - EHTTPMethod eHTTPRequestMethod:
    :param str? pchAbsoluteURL:
    :returns: (int - HTTPRequestHandle) Return value
    :SteamWorks: `CreateHTTPRequest <https://partner.steamgames.com/doc/api/ISteamHTTP#CreateHTTPRequest>`_

**Example**::

    local hReq = Steam.HTTP.CreateHTTPRequest('GET', 'https://api.example.com/leaderboard')
    Steam.HTTP.SetHTTPRequestHeaderValue(hReq, 'Accept', 'application/json')
    Steam.HTTP.SendHTTPRequest(hReq)

.. function:: HTTP.DeferHTTPRequest(hRequest)

    🤖 **Auto-generated binding**

    :param int - HTTPRequestHandle hRequest:
    :returns: (bool) Return value
    :SteamWorks: `DeferHTTPRequest <https://partner.steamgames.com/doc/api/ISteamHTTP#DeferHTTPRequest>`_

.. function:: HTTP.GetHTTPDownloadProgressPct(hRequest)

    🤖 **Auto-generated binding**

    :param int - HTTPRequestHandle hRequest:
    :returns: (bool) Return value
    :returns: (float) ``pflPercentOut``
    :SteamWorks: `GetHTTPDownloadProgressPct <https://partner.steamgames.com/doc/api/ISteamHTTP#GetHTTPDownloadProgressPct>`_

    **Signature differences from C++ API:**

    * Parameter ``pflPercentOut`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    -- Poll progress for a large download
    local pct = Steam.HTTP.GetHTTPDownloadProgressPct(hReq)
    print(string.format('Download: %.1f%%', pct * 100))

.. function:: HTTP.GetHTTPRequestWasTimedOut(hRequest)

    🤖 **Auto-generated binding**

    :param int - HTTPRequestHandle hRequest:
    :returns: (bool) Return value
    :returns: (bool) ``pbWasTimedOut``
    :SteamWorks: `GetHTTPRequestWasTimedOut <https://partner.steamgames.com/doc/api/ISteamHTTP#GetHTTPRequestWasTimedOut>`_

    **Signature differences from C++ API:**

    * Parameter ``pbWasTimedOut`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: HTTP.GetHTTPResponseBodyData(hRequest, unBufferSize)

    🤖 **Auto-generated binding**

    :param int - HTTPRequestHandle hRequest:
    :param int? unBufferSize: size of the buffer to allocate for ``pBodyDataBuffer``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (bool) Return value
    :returns: (str) ``pBodyDataBuffer``
    :SteamWorks: `GetHTTPResponseBodyData <https://partner.steamgames.com/doc/api/ISteamHTTP#GetHTTPResponseBodyData>`_

    **Signature differences from C++ API:**

    * Parameter ``pBodyDataBuffer`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

    **Notes:**

    * See :func:`HTTP.GetHTTPResponseBodySize`'s example.

.. function:: HTTP.GetHTTPResponseBodySize(hRequest)

    🤖 **Auto-generated binding**

    :param int - HTTPRequestHandle hRequest:
    :returns: (bool) Return value
    :returns: (int) ``unBodySize``
    :SteamWorks: `GetHTTPResponseBodySize <https://partner.steamgames.com/doc/api/ISteamHTTP#GetHTTPResponseBodySize>`_

    **Signature differences from C++ API:**

    * Parameter ``unBodySize`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    function Steam.HTTP.OnHTTPRequestCompleted(data)
        if data.m_eStatusCode == 200 then
            local size = Steam.HTTP.GetHTTPResponseBodySize(data.m_hRequest)
            local ok, body = Steam.HTTP.GetHTTPResponseBodyData(data.m_hRequest, size)
            if ok then
                handleResponse(body)
            end
        end
        Steam.HTTP.ReleaseHTTPRequest(data.m_hRequest)
    end

.. function:: HTTP.GetHTTPResponseHeaderSize(hRequest, pchHeaderName)

    🤖 **Auto-generated binding**

    :param int - HTTPRequestHandle hRequest:
    :param str? pchHeaderName:
    :returns: (bool) Return value
    :returns: (int) ``unResponseHeaderSize``
    :SteamWorks: `GetHTTPResponseHeaderSize <https://partner.steamgames.com/doc/api/ISteamHTTP#GetHTTPResponseHeaderSize>`_

    **Signature differences from C++ API:**

    * Parameter ``unResponseHeaderSize`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: HTTP.GetHTTPResponseHeaderValue(hRequest, pchHeaderName, unBufferSize)

    🤖 **Auto-generated binding**

    :param int - HTTPRequestHandle hRequest:
    :param str? pchHeaderName:
    :param int? unBufferSize: size of the buffer to allocate for ``pHeaderValueBuffer``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (bool) Return value
    :returns: (str) ``pHeaderValueBuffer``
    :SteamWorks: `GetHTTPResponseHeaderValue <https://partner.steamgames.com/doc/api/ISteamHTTP#GetHTTPResponseHeaderValue>`_

    **Signature differences from C++ API:**

    * Parameter ``pHeaderValueBuffer`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    function Steam.HTTP.OnHTTPRequestCompleted(data)
        local size = Steam.HTTP.GetHTTPResponseHeaderSize(data.m_hRequest, 'Content-Type')
        if size > 0 then
            local ok, ct = Steam.HTTP.GetHTTPResponseHeaderValue(data.m_hRequest, 'Content-Type', size)
            if ok then
                print('Content-Type:', ct)
            end
        end
        Steam.HTTP.ReleaseHTTPRequest(data.m_hRequest)
    end

.. function:: HTTP.GetHTTPStreamingResponseBodyData(hRequest, cOffset, unBufferSize)

    🤖 **Auto-generated binding**

    :param int - HTTPRequestHandle hRequest:
    :param int cOffset:
    :param int? unBufferSize: size of the buffer to allocate for ``pBodyDataBuffer``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (bool) Return value
    :returns: (str) ``pBodyDataBuffer``
    :SteamWorks: `GetHTTPStreamingResponseBodyData <https://partner.steamgames.com/doc/api/ISteamHTTP#GetHTTPStreamingResponseBodyData>`_

    **Signature differences from C++ API:**

    * Parameter ``pBodyDataBuffer`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: HTTP.PrioritizeHTTPRequest(hRequest)

    🤖 **Auto-generated binding**

    :param int - HTTPRequestHandle hRequest:
    :returns: (bool) Return value
    :SteamWorks: `PrioritizeHTTPRequest <https://partner.steamgames.com/doc/api/ISteamHTTP#PrioritizeHTTPRequest>`_

.. function:: HTTP.ReleaseCookieContainer(hCookieContainer)

    🤖 **Auto-generated binding**

    :param int - HTTPCookieContainerHandle hCookieContainer:
    :returns: (bool) Return value
    :SteamWorks: `ReleaseCookieContainer <https://partner.steamgames.com/doc/api/ISteamHTTP#ReleaseCookieContainer>`_

.. function:: HTTP.ReleaseHTTPRequest(hRequest)

    🤖 **Auto-generated binding**

    :param int - HTTPRequestHandle hRequest:
    :returns: (bool) Return value
    :SteamWorks: `ReleaseHTTPRequest <https://partner.steamgames.com/doc/api/ISteamHTTP#ReleaseHTTPRequest>`_

**Example**::

    -- Always release the request handle when done
    Steam.HTTP.ReleaseHTTPRequest(hReq)

.. function:: HTTP.SendHTTPRequest(hRequest)

    🤖 **Auto-generated binding**

    :param int - HTTPRequestHandle hRequest:
    :returns: (bool) Return value
    :returns: (uint64) ``pCallHandle``
    :SteamWorks: `SendHTTPRequest <https://partner.steamgames.com/doc/api/ISteamHTTP#SendHTTPRequest>`_

    **Signature differences from C++ API:**

    * Parameter ``pCallHandle`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    local hReq = Steam.HTTP.CreateHTTPRequest('GET', 'https://example.com/data.json')
    Steam.HTTP.SetHTTPRequestNetworkActivityTimeout(hReq, 10)
    Steam.HTTP.SendHTTPRequest(hReq)

.. function:: HTTP.SendHTTPRequestAndStreamResponse(hRequest)

    🤖 **Auto-generated binding**

    :param int - HTTPRequestHandle hRequest:
    :returns: (bool) Return value
    :returns: (uint64) ``pCallHandle``
    :SteamWorks: `SendHTTPRequestAndStreamResponse <https://partner.steamgames.com/doc/api/ISteamHTTP#SendHTTPRequestAndStreamResponse>`_

    **Signature differences from C++ API:**

    * Parameter ``pCallHandle`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: HTTP.SetCookie(hCookieContainer, pchHost, pchUrl, pchCookie)

    🤖 **Auto-generated binding**

    :param int - HTTPCookieContainerHandle hCookieContainer:
    :param str? pchHost:
    :param str? pchUrl:
    :param str? pchCookie:
    :returns: (bool) Return value
    :SteamWorks: `SetCookie <https://partner.steamgames.com/doc/api/ISteamHTTP#SetCookie>`_

.. function:: HTTP.SetHTTPRequestAbsoluteTimeoutMS(hRequest, unMilliseconds)

    🤖 **Auto-generated binding**

    :param int - HTTPRequestHandle hRequest:
    :param int unMilliseconds:
    :returns: (bool) Return value
    :SteamWorks: `SetHTTPRequestAbsoluteTimeoutMS <https://partner.steamgames.com/doc/api/ISteamHTTP#SetHTTPRequestAbsoluteTimeoutMS>`_

.. function:: HTTP.SetHTTPRequestContextValue(hRequest, ulContextValue)

    🤖 **Auto-generated binding**

    :param int - HTTPRequestHandle hRequest:
    :param uint64 ulContextValue:
    :returns: (bool) Return value
    :SteamWorks: `SetHTTPRequestContextValue <https://partner.steamgames.com/doc/api/ISteamHTTP#SetHTTPRequestContextValue>`_

.. function:: HTTP.SetHTTPRequestCookieContainer(hRequest, hCookieContainer)

    🤖 **Auto-generated binding**

    :param int - HTTPRequestHandle hRequest:
    :param int - HTTPCookieContainerHandle hCookieContainer:
    :returns: (bool) Return value
    :SteamWorks: `SetHTTPRequestCookieContainer <https://partner.steamgames.com/doc/api/ISteamHTTP#SetHTTPRequestCookieContainer>`_

.. function:: HTTP.SetHTTPRequestGetOrPostParameter(hRequest, pchParamName, pchParamValue)

    🤖 **Auto-generated binding**

    :param int - HTTPRequestHandle hRequest:
    :param str? pchParamName:
    :param str? pchParamValue:
    :returns: (bool) Return value
    :SteamWorks: `SetHTTPRequestGetOrPostParameter <https://partner.steamgames.com/doc/api/ISteamHTTP#SetHTTPRequestGetOrPostParameter>`_

**Example**::

    local hReq = Steam.HTTP.CreateHTTPRequest('POST', 'https://api.example.com/score')
    Steam.HTTP.SetHTTPRequestGetOrPostParameter(hReq, 'score', tostring(playerScore))
    Steam.HTTP.SetHTTPRequestGetOrPostParameter(hReq, 'player', playerName)
    Steam.HTTP.SendHTTPRequest(hReq)

.. function:: HTTP.SetHTTPRequestHeaderValue(hRequest, pchHeaderName, pchHeaderValue)

    🤖 **Auto-generated binding**

    :param int - HTTPRequestHandle hRequest:
    :param str? pchHeaderName:
    :param str? pchHeaderValue:
    :returns: (bool) Return value
    :SteamWorks: `SetHTTPRequestHeaderValue <https://partner.steamgames.com/doc/api/ISteamHTTP#SetHTTPRequestHeaderValue>`_

    **Notes:**

    * See :func:`HTTP.CreateHTTPRequest`'s example.

.. function:: HTTP.SetHTTPRequestNetworkActivityTimeout(hRequest, unTimeoutSeconds)

    🤖 **Auto-generated binding**

    :param int - HTTPRequestHandle hRequest:
    :param int unTimeoutSeconds:
    :returns: (bool) Return value
    :SteamWorks: `SetHTTPRequestNetworkActivityTimeout <https://partner.steamgames.com/doc/api/ISteamHTTP#SetHTTPRequestNetworkActivityTimeout>`_

**Example**::

    local hReq = Steam.HTTP.CreateHTTPRequest('GET', 'https://example.com/ping')
    Steam.HTTP.SetHTTPRequestNetworkActivityTimeout(hReq, 5)
    Steam.HTTP.SendHTTPRequest(hReq)

.. function:: HTTP.SetHTTPRequestRawPostBody(hRequest, pchContentType, pubBody, unBodyLen)

    🤖 **Auto-generated binding**

    :param int - HTTPRequestHandle hRequest:
    :param str? pchContentType:
    :param str? pubBody:
    :param int unBodyLen: size of the input array ``pubBody``
    :returns: (bool) Return value
    :SteamWorks: `SetHTTPRequestRawPostBody <https://partner.steamgames.com/doc/api/ISteamHTTP#SetHTTPRequestRawPostBody>`_

**Example**::

    local json = '{"action":"submit","data":"value"}'
    local hReq = Steam.HTTP.CreateHTTPRequest('POST', 'https://api.example.com/action')
    Steam.HTTP.SetHTTPRequestRawPostBody(hReq, 'application/json', json, #json)
    Steam.HTTP.SendHTTPRequest(hReq)

.. function:: HTTP.SetHTTPRequestRequiresVerifiedCertificate(hRequest, bRequireVerifiedCertificate)

    🤖 **Auto-generated binding**

    :param int - HTTPRequestHandle hRequest:
    :param bool bRequireVerifiedCertificate:
    :returns: (bool) Return value
    :SteamWorks: `SetHTTPRequestRequiresVerifiedCertificate <https://partner.steamgames.com/doc/api/ISteamHTTP#SetHTTPRequestRequiresVerifiedCertificate>`_

.. function:: HTTP.SetHTTPRequestUserAgentInfo(hRequest, pchUserAgentInfo)

    🤖 **Auto-generated binding**

    :param int - HTTPRequestHandle hRequest:
    :param str? pchUserAgentInfo:
    :returns: (bool) Return value
    :SteamWorks: `SetHTTPRequestUserAgentInfo <https://partner.steamgames.com/doc/api/ISteamHTTP#SetHTTPRequestUserAgentInfo>`_


Callbacks
---------

.. function:: HTTP.OnHTTPRequestCompleted

    Callback for `HTTPRequestCompleted_t <https://partner.steamgames.com/doc/api/ISteamHTTP#HTTPRequestCompleted_t>`_

    **callback(data)** receives:

    * **data.m_hRequest** *(int - HTTPRequestHandle)*
    * **data.m_ulContextValue** *(uint64)*
    * **data.m_bRequestSuccessful** *(bool)*
    * **data.m_eStatusCode** *(int - EHTTPStatusCode)*
    * **data.m_unBodySize** *(int)*

.. function:: HTTP.OnHTTPRequestHeadersReceived

    Callback for `HTTPRequestHeadersReceived_t <https://partner.steamgames.com/doc/api/ISteamHTTP#HTTPRequestHeadersReceived_t>`_

    **callback(data)** receives:

    * **data.m_hRequest** *(int - HTTPRequestHandle)*
    * **data.m_ulContextValue** *(uint64)*

.. function:: HTTP.OnHTTPRequestDataReceived

    Callback for `HTTPRequestDataReceived_t <https://partner.steamgames.com/doc/api/ISteamHTTP#HTTPRequestDataReceived_t>`_

    **callback(data)** receives:

    * **data.m_hRequest** *(int - HTTPRequestHandle)*
    * **data.m_ulContextValue** *(uint64)*
    * **data.m_cOffset** *(int)*
    * **data.m_cBytesReceived** *(int)*

