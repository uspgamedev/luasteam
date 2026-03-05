---@class Steam.HTTP
---@field OnHTTPRequestCompleted? fun(data: HTTPRequestCompleted_t)
---@field OnHTTPRequestHeadersReceived? fun(data: HTTPRequestHeadersReceived_t)
---@field OnHTTPRequestDataReceived? fun(data: HTTPRequestDataReceived_t)
local HTTP = {}

---@param eHTTPRequestMethod integer -- EHTTPMethod
---@param pchAbsoluteURL string?
---@return integer -- HTTPRequestHandle
function HTTP.CreateHTTPRequest(eHTTPRequestMethod, pchAbsoluteURL) end

---@param hRequest integer -- HTTPRequestHandle
---@param ulContextValue uint64
---@return boolean
function HTTP.SetHTTPRequestContextValue(hRequest, ulContextValue) end

---@param hRequest integer -- HTTPRequestHandle
---@param unTimeoutSeconds integer
---@return boolean
function HTTP.SetHTTPRequestNetworkActivityTimeout(hRequest, unTimeoutSeconds) end

---@param hRequest integer -- HTTPRequestHandle
---@param pchHeaderName string?
---@param pchHeaderValue string?
---@return boolean
function HTTP.SetHTTPRequestHeaderValue(hRequest, pchHeaderName, pchHeaderValue) end

---@param hRequest integer -- HTTPRequestHandle
---@param pchParamName string?
---@param pchParamValue string?
---@return boolean
function HTTP.SetHTTPRequestGetOrPostParameter(hRequest, pchParamName, pchParamValue) end

---@param hRequest integer -- HTTPRequestHandle
---@return boolean
---@return uint64 -- Value of: pCallHandle
function HTTP.SendHTTPRequest(hRequest) end

---@param hRequest integer -- HTTPRequestHandle
---@return boolean
---@return uint64 -- Value of: pCallHandle
function HTTP.SendHTTPRequestAndStreamResponse(hRequest) end

---@param hRequest integer -- HTTPRequestHandle
---@return boolean
function HTTP.DeferHTTPRequest(hRequest) end

---@param hRequest integer -- HTTPRequestHandle
---@return boolean
function HTTP.PrioritizeHTTPRequest(hRequest) end

---@param hRequest integer -- HTTPRequestHandle
---@param pchHeaderName string?
---@return boolean
---@return integer -- Value of: unResponseHeaderSize
function HTTP.GetHTTPResponseHeaderSize(hRequest, pchHeaderName) end

---@param hRequest integer -- HTTPRequestHandle
---@param pchHeaderName string?
---@param unBufferSize integer? size of the buffer for pHeaderValueBuffer; if nil then the buffer will be NULL
---@return boolean
---@return string -- Value of: pHeaderValueBuffer
function HTTP.GetHTTPResponseHeaderValue(hRequest, pchHeaderName, unBufferSize) end

---@param hRequest integer -- HTTPRequestHandle
---@return boolean
---@return integer -- Value of: unBodySize
function HTTP.GetHTTPResponseBodySize(hRequest) end

---@param hRequest integer -- HTTPRequestHandle
---@param unBufferSize integer? size of the buffer for pBodyDataBuffer; if nil then the buffer will be NULL
---@return boolean
---@return string -- Value of: pBodyDataBuffer
function HTTP.GetHTTPResponseBodyData(hRequest, unBufferSize) end

---@param hRequest integer -- HTTPRequestHandle
---@param cOffset integer
---@param unBufferSize integer? size of the buffer for pBodyDataBuffer; if nil then the buffer will be NULL
---@return boolean
---@return string -- Value of: pBodyDataBuffer
function HTTP.GetHTTPStreamingResponseBodyData(hRequest, cOffset, unBufferSize) end

---@param hRequest integer -- HTTPRequestHandle
---@return boolean
function HTTP.ReleaseHTTPRequest(hRequest) end

---@param hRequest integer -- HTTPRequestHandle
---@return boolean
---@return number -- Value of: pflPercentOut
function HTTP.GetHTTPDownloadProgressPct(hRequest) end

---@param hRequest integer -- HTTPRequestHandle
---@param pchContentType string?
---@param pubBody string?
---@param unBodyLen integer size of the input array pubBody
---@return boolean
function HTTP.SetHTTPRequestRawPostBody(hRequest, pchContentType, pubBody, unBodyLen) end

---@param bAllowResponsesToModify boolean
---@return integer -- HTTPCookieContainerHandle
function HTTP.CreateCookieContainer(bAllowResponsesToModify) end

---@param hCookieContainer integer -- HTTPCookieContainerHandle
---@return boolean
function HTTP.ReleaseCookieContainer(hCookieContainer) end

---@param hCookieContainer integer -- HTTPCookieContainerHandle
---@param pchHost string?
---@param pchUrl string?
---@param pchCookie string?
---@return boolean
function HTTP.SetCookie(hCookieContainer, pchHost, pchUrl, pchCookie) end

---@param hRequest integer -- HTTPRequestHandle
---@param hCookieContainer integer -- HTTPCookieContainerHandle
---@return boolean
function HTTP.SetHTTPRequestCookieContainer(hRequest, hCookieContainer) end

---@param hRequest integer -- HTTPRequestHandle
---@param pchUserAgentInfo string?
---@return boolean
function HTTP.SetHTTPRequestUserAgentInfo(hRequest, pchUserAgentInfo) end

---@param hRequest integer -- HTTPRequestHandle
---@param bRequireVerifiedCertificate boolean
---@return boolean
function HTTP.SetHTTPRequestRequiresVerifiedCertificate(hRequest, bRequireVerifiedCertificate) end

---@param hRequest integer -- HTTPRequestHandle
---@param unMilliseconds integer
---@return boolean
function HTTP.SetHTTPRequestAbsoluteTimeoutMS(hRequest, unMilliseconds) end

---@param hRequest integer -- HTTPRequestHandle
---@return boolean
---@return boolean -- Value of: pbWasTimedOut
function HTTP.GetHTTPRequestWasTimedOut(hRequest) end

Steam.HTTP = HTTP
Steam.GameServerHTTP = HTTP
