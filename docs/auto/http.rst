##########
ISteamHTTP
##########

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✋ require manual implementation.

List of Functions
-----------------

* :func:`HTTP.CreateHTTPRequest`
* :func:`HTTP.SetHTTPRequestContextValue`
* :func:`HTTP.SetHTTPRequestNetworkActivityTimeout`
* :func:`HTTP.SetHTTPRequestHeaderValue`
* :func:`HTTP.SetHTTPRequestGetOrPostParameter`
* :func:`HTTP.SendHTTPRequest`
* :func:`HTTP.SendHTTPRequestAndStreamResponse`
* :func:`HTTP.DeferHTTPRequest`
* :func:`HTTP.PrioritizeHTTPRequest`
* :func:`HTTP.GetHTTPResponseHeaderSize`
* :func:`HTTP.GetHTTPResponseHeaderValue`
* :func:`HTTP.GetHTTPResponseBodySize`
* :func:`HTTP.GetHTTPResponseBodyData`
* :func:`HTTP.GetHTTPStreamingResponseBodyData`
* :func:`HTTP.ReleaseHTTPRequest`
* :func:`HTTP.GetHTTPDownloadProgressPct`
* :func:`HTTP.SetHTTPRequestRawPostBody`
* :func:`HTTP.CreateCookieContainer`
* :func:`HTTP.ReleaseCookieContainer`
* :func:`HTTP.SetCookie`
* :func:`HTTP.SetHTTPRequestCookieContainer`
* :func:`HTTP.SetHTTPRequestUserAgentInfo`
* :func:`HTTP.SetHTTPRequestRequiresVerifiedCertificate`
* :func:`HTTP.SetHTTPRequestAbsoluteTimeoutMS`
* :func:`HTTP.GetHTTPRequestWasTimedOut`

List of Callbacks
-----------------

* :func:`HTTP.onHTTPRequestCompleted`
* :func:`HTTP.onHTTPRequestHeadersReceived`
* :func:`HTTP.onHTTPRequestDataReceived`

Function Reference
------------------

.. function:: HTTP.CreateHTTPRequest(eHTTPRequestMethod, pchAbsoluteURL)

    🤖 **Auto-generated binding**

    :param int eHTTPRequestMethod:
    :param str pchAbsoluteURL:
    :returns: (int) Return value
    :SteamWorks: `CreateHTTPRequest <https://partner.steamgames.com/doc/api/ISteamHTTP#CreateHTTPRequest>`_

.. function:: HTTP.SetHTTPRequestContextValue(hRequest, ulContextValue)

    🤖 **Auto-generated binding**

    :param int hRequest:
    :param uint64 ulContextValue:
    :returns: (bool) Return value
    :SteamWorks: `SetHTTPRequestContextValue <https://partner.steamgames.com/doc/api/ISteamHTTP#SetHTTPRequestContextValue>`_

.. function:: HTTP.SetHTTPRequestNetworkActivityTimeout(hRequest, unTimeoutSeconds)

    🤖 **Auto-generated binding**

    :param int hRequest:
    :param int unTimeoutSeconds:
    :returns: (bool) Return value
    :SteamWorks: `SetHTTPRequestNetworkActivityTimeout <https://partner.steamgames.com/doc/api/ISteamHTTP#SetHTTPRequestNetworkActivityTimeout>`_

.. function:: HTTP.SetHTTPRequestHeaderValue(hRequest, pchHeaderName, pchHeaderValue)

    🤖 **Auto-generated binding**

    :param int hRequest:
    :param str pchHeaderName:
    :param str pchHeaderValue:
    :returns: (bool) Return value
    :SteamWorks: `SetHTTPRequestHeaderValue <https://partner.steamgames.com/doc/api/ISteamHTTP#SetHTTPRequestHeaderValue>`_

.. function:: HTTP.SetHTTPRequestGetOrPostParameter(hRequest, pchParamName, pchParamValue)

    🤖 **Auto-generated binding**

    :param int hRequest:
    :param str pchParamName:
    :param str pchParamValue:
    :returns: (bool) Return value
    :SteamWorks: `SetHTTPRequestGetOrPostParameter <https://partner.steamgames.com/doc/api/ISteamHTTP#SetHTTPRequestGetOrPostParameter>`_

.. function:: HTTP.SendHTTPRequest(hRequest)

    🤖 **Auto-generated binding**

    :param int hRequest:
    :returns: (bool) Return value
    :returns: (uint64) Value for `pCallHandle`
    :SteamWorks: `SendHTTPRequest <https://partner.steamgames.com/doc/api/ISteamHTTP#SendHTTPRequest>`_

    **Signature differences from C++ API:**

    * Parameter ``pCallHandle`` is no longer a paramer, and is instead an additional return value

.. function:: HTTP.SendHTTPRequestAndStreamResponse(hRequest)

    🤖 **Auto-generated binding**

    :param int hRequest:
    :returns: (bool) Return value
    :returns: (uint64) Value for `pCallHandle`
    :SteamWorks: `SendHTTPRequestAndStreamResponse <https://partner.steamgames.com/doc/api/ISteamHTTP#SendHTTPRequestAndStreamResponse>`_

    **Signature differences from C++ API:**

    * Parameter ``pCallHandle`` is no longer a paramer, and is instead an additional return value

.. function:: HTTP.DeferHTTPRequest(hRequest)

    🤖 **Auto-generated binding**

    :param int hRequest:
    :returns: (bool) Return value
    :SteamWorks: `DeferHTTPRequest <https://partner.steamgames.com/doc/api/ISteamHTTP#DeferHTTPRequest>`_

.. function:: HTTP.PrioritizeHTTPRequest(hRequest)

    🤖 **Auto-generated binding**

    :param int hRequest:
    :returns: (bool) Return value
    :SteamWorks: `PrioritizeHTTPRequest <https://partner.steamgames.com/doc/api/ISteamHTTP#PrioritizeHTTPRequest>`_

.. function:: HTTP.GetHTTPResponseHeaderSize(hRequest, pchHeaderName)

    🤖 **Auto-generated binding**

    :param int hRequest:
    :param str pchHeaderName:
    :returns: (bool) Return value
    :returns: (int) Value for `unResponseHeaderSize`
    :SteamWorks: `GetHTTPResponseHeaderSize <https://partner.steamgames.com/doc/api/ISteamHTTP#GetHTTPResponseHeaderSize>`_

    **Signature differences from C++ API:**

    * Parameter ``unResponseHeaderSize`` is no longer a paramer, and is instead an additional return value

.. function:: HTTP.GetHTTPResponseHeaderValue(hRequest, pchHeaderName, unBufferSize)

    🤖 **Auto-generated binding**

    :param int hRequest:
    :param str pchHeaderName:
    :param int unBufferSize:
    :returns: (bool) Return value
    :returns: (int) Value for `pHeaderValueBuffer`
    :SteamWorks: `GetHTTPResponseHeaderValue <https://partner.steamgames.com/doc/api/ISteamHTTP#GetHTTPResponseHeaderValue>`_

    **Signature differences from C++ API:**

    * Parameter ``pHeaderValueBuffer`` is no longer a paramer, and is instead an additional return value

.. function:: HTTP.GetHTTPResponseBodySize(hRequest)

    🤖 **Auto-generated binding**

    :param int hRequest:
    :returns: (bool) Return value
    :returns: (int) Value for `unBodySize`
    :SteamWorks: `GetHTTPResponseBodySize <https://partner.steamgames.com/doc/api/ISteamHTTP#GetHTTPResponseBodySize>`_

    **Signature differences from C++ API:**

    * Parameter ``unBodySize`` is no longer a paramer, and is instead an additional return value

.. function:: HTTP.GetHTTPResponseBodyData(hRequest, unBufferSize)

    🤖 **Auto-generated binding**

    :param int hRequest:
    :param int unBufferSize:
    :returns: (bool) Return value
    :returns: (int) Value for `pBodyDataBuffer`
    :SteamWorks: `GetHTTPResponseBodyData <https://partner.steamgames.com/doc/api/ISteamHTTP#GetHTTPResponseBodyData>`_

    **Signature differences from C++ API:**

    * Parameter ``pBodyDataBuffer`` is no longer a paramer, and is instead an additional return value

.. function:: HTTP.GetHTTPStreamingResponseBodyData(hRequest, cOffset, unBufferSize)

    🤖 **Auto-generated binding**

    :param int hRequest:
    :param int cOffset:
    :param int unBufferSize:
    :returns: (bool) Return value
    :returns: (int) Value for `pBodyDataBuffer`
    :SteamWorks: `GetHTTPStreamingResponseBodyData <https://partner.steamgames.com/doc/api/ISteamHTTP#GetHTTPStreamingResponseBodyData>`_

    **Signature differences from C++ API:**

    * Parameter ``pBodyDataBuffer`` is no longer a paramer, and is instead an additional return value

.. function:: HTTP.ReleaseHTTPRequest(hRequest)

    🤖 **Auto-generated binding**

    :param int hRequest:
    :returns: (bool) Return value
    :SteamWorks: `ReleaseHTTPRequest <https://partner.steamgames.com/doc/api/ISteamHTTP#ReleaseHTTPRequest>`_

.. function:: HTTP.GetHTTPDownloadProgressPct(hRequest)

    🤖 **Auto-generated binding**

    :param int hRequest:
    :returns: (bool) Return value
    :returns: (float) Value for `pflPercentOut`
    :SteamWorks: `GetHTTPDownloadProgressPct <https://partner.steamgames.com/doc/api/ISteamHTTP#GetHTTPDownloadProgressPct>`_

    **Signature differences from C++ API:**

    * Parameter ``pflPercentOut`` is no longer a paramer, and is instead an additional return value

.. function:: HTTP.SetHTTPRequestRawPostBody(hRequest, pchContentType, unBodyLen)

    🤖 **Auto-generated binding**

    :param int hRequest:
    :param str pchContentType:
    :param int unBodyLen:
    :returns: (bool) Return value
    :returns: (int) Value for `pubBody`
    :SteamWorks: `SetHTTPRequestRawPostBody <https://partner.steamgames.com/doc/api/ISteamHTTP#SetHTTPRequestRawPostBody>`_

    **Signature differences from C++ API:**

    * Parameter ``pubBody`` is no longer a paramer, and is instead an additional return value

.. function:: HTTP.CreateCookieContainer(bAllowResponsesToModify)

    🤖 **Auto-generated binding**

    :param bool bAllowResponsesToModify:
    :returns: (int) Return value
    :SteamWorks: `CreateCookieContainer <https://partner.steamgames.com/doc/api/ISteamHTTP#CreateCookieContainer>`_

.. function:: HTTP.ReleaseCookieContainer(hCookieContainer)

    🤖 **Auto-generated binding**

    :param int hCookieContainer:
    :returns: (bool) Return value
    :SteamWorks: `ReleaseCookieContainer <https://partner.steamgames.com/doc/api/ISteamHTTP#ReleaseCookieContainer>`_

.. function:: HTTP.SetCookie(hCookieContainer, pchHost, pchUrl, pchCookie)

    🤖 **Auto-generated binding**

    :param int hCookieContainer:
    :param str pchHost:
    :param str pchUrl:
    :param str pchCookie:
    :returns: (bool) Return value
    :SteamWorks: `SetCookie <https://partner.steamgames.com/doc/api/ISteamHTTP#SetCookie>`_

.. function:: HTTP.SetHTTPRequestCookieContainer(hRequest, hCookieContainer)

    🤖 **Auto-generated binding**

    :param int hRequest:
    :param int hCookieContainer:
    :returns: (bool) Return value
    :SteamWorks: `SetHTTPRequestCookieContainer <https://partner.steamgames.com/doc/api/ISteamHTTP#SetHTTPRequestCookieContainer>`_

.. function:: HTTP.SetHTTPRequestUserAgentInfo(hRequest, pchUserAgentInfo)

    🤖 **Auto-generated binding**

    :param int hRequest:
    :param str pchUserAgentInfo:
    :returns: (bool) Return value
    :SteamWorks: `SetHTTPRequestUserAgentInfo <https://partner.steamgames.com/doc/api/ISteamHTTP#SetHTTPRequestUserAgentInfo>`_

.. function:: HTTP.SetHTTPRequestRequiresVerifiedCertificate(hRequest, bRequireVerifiedCertificate)

    🤖 **Auto-generated binding**

    :param int hRequest:
    :param bool bRequireVerifiedCertificate:
    :returns: (bool) Return value
    :SteamWorks: `SetHTTPRequestRequiresVerifiedCertificate <https://partner.steamgames.com/doc/api/ISteamHTTP#SetHTTPRequestRequiresVerifiedCertificate>`_

.. function:: HTTP.SetHTTPRequestAbsoluteTimeoutMS(hRequest, unMilliseconds)

    🤖 **Auto-generated binding**

    :param int hRequest:
    :param int unMilliseconds:
    :returns: (bool) Return value
    :SteamWorks: `SetHTTPRequestAbsoluteTimeoutMS <https://partner.steamgames.com/doc/api/ISteamHTTP#SetHTTPRequestAbsoluteTimeoutMS>`_

.. function:: HTTP.GetHTTPRequestWasTimedOut(hRequest)

    🤖 **Auto-generated binding**

    :param int hRequest:
    :returns: (bool) Return value
    :returns: (bool) Value for `pbWasTimedOut`
    :SteamWorks: `GetHTTPRequestWasTimedOut <https://partner.steamgames.com/doc/api/ISteamHTTP#GetHTTPRequestWasTimedOut>`_

    **Signature differences from C++ API:**

    * Parameter ``pbWasTimedOut`` is no longer a paramer, and is instead an additional return value


Callbacks
---------

.. function:: HTTP.onHTTPRequestCompleted

    Callback for `HTTPRequestCompleted_t <https://partner.steamgames.com/doc/api/ISteamHTTP#HTTPRequestCompleted_t>`_

    **callback(data)** receives:

    * **data.m_hRequest** -- m_hRequest
    * **data.m_ulContextValue** -- m_ulContextValue
    * **data.m_bRequestSuccessful** -- m_bRequestSuccessful
    * **data.m_eStatusCode** -- m_eStatusCode
    * **data.m_unBodySize** -- m_unBodySize

.. function:: HTTP.onHTTPRequestHeadersReceived

    Callback for `HTTPRequestHeadersReceived_t <https://partner.steamgames.com/doc/api/ISteamHTTP#HTTPRequestHeadersReceived_t>`_

    **callback(data)** receives:

    * **data.m_hRequest** -- m_hRequest
    * **data.m_ulContextValue** -- m_ulContextValue

.. function:: HTTP.onHTTPRequestDataReceived

    Callback for `HTTPRequestDataReceived_t <https://partner.steamgames.com/doc/api/ISteamHTTP#HTTPRequestDataReceived_t>`_

    **callback(data)** receives:

    * **data.m_hRequest** -- m_hRequest
    * **data.m_ulContextValue** -- m_ulContextValue
    * **data.m_cOffset** -- m_cOffset
    * **data.m_cBytesReceived** -- m_cBytesReceived

