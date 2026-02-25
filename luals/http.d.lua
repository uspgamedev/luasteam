---@class Steam.HTTP
local HTTP = {}

---@param eHTTPRequestMethod integer
---@param pchAbsoluteURL string
---@return integer
function HTTP.CreateHTTPRequest(eHTTPRequestMethod, pchAbsoluteURL) end

---@param hRequest integer
---@param ulContextValue uint64
---@return boolean
function HTTP.SetHTTPRequestContextValue(hRequest, ulContextValue) end

---@param hRequest integer
---@param unTimeoutSeconds integer
---@return boolean
function HTTP.SetHTTPRequestNetworkActivityTimeout(hRequest, unTimeoutSeconds) end

---@param hRequest integer
---@param pchHeaderName string
---@param pchHeaderValue string
---@return boolean
function HTTP.SetHTTPRequestHeaderValue(hRequest, pchHeaderName, pchHeaderValue) end

---@param hRequest integer
---@param pchParamName string
---@param pchParamValue string
---@return boolean
function HTTP.SetHTTPRequestGetOrPostParameter(hRequest, pchParamName, pchParamValue) end

---@param hRequest integer
---@return boolean
---@return uint64 -- Value of: pCallHandle
function HTTP.SendHTTPRequest(hRequest) end

---@param hRequest integer
---@return boolean
---@return uint64 -- Value of: pCallHandle
function HTTP.SendHTTPRequestAndStreamResponse(hRequest) end

---@param hRequest integer
---@return boolean
function HTTP.DeferHTTPRequest(hRequest) end

---@param hRequest integer
---@return boolean
function HTTP.PrioritizeHTTPRequest(hRequest) end

---@param hRequest integer
---@param pchHeaderName string
---@return boolean
---@return integer -- Value of: unResponseHeaderSize
function HTTP.GetHTTPResponseHeaderSize(hRequest, pchHeaderName) end

---@param hRequest integer
---@param pchHeaderName string
---@param unBufferSize integer
---@return boolean
---@return integer -- Value of: pHeaderValueBuffer
function HTTP.GetHTTPResponseHeaderValue(hRequest, pchHeaderName, unBufferSize) end

---@param hRequest integer
---@return boolean
---@return integer -- Value of: unBodySize
function HTTP.GetHTTPResponseBodySize(hRequest) end

---@param hRequest integer
---@param unBufferSize integer
---@return boolean
---@return integer -- Value of: pBodyDataBuffer
function HTTP.GetHTTPResponseBodyData(hRequest, unBufferSize) end

---@param hRequest integer
---@param cOffset integer
---@param unBufferSize integer
---@return boolean
---@return integer -- Value of: pBodyDataBuffer
function HTTP.GetHTTPStreamingResponseBodyData(hRequest, cOffset, unBufferSize) end

---@param hRequest integer
---@return boolean
function HTTP.ReleaseHTTPRequest(hRequest) end

---@param hRequest integer
---@return boolean
---@return number -- Value of: pflPercentOut
function HTTP.GetHTTPDownloadProgressPct(hRequest) end

---@param hRequest integer
---@param pchContentType string
---@param unBodyLen integer
---@return boolean
---@return integer -- Value of: pubBody
function HTTP.SetHTTPRequestRawPostBody(hRequest, pchContentType, unBodyLen) end

---@param bAllowResponsesToModify boolean
---@return integer
function HTTP.CreateCookieContainer(bAllowResponsesToModify) end

---@param hCookieContainer integer
---@return boolean
function HTTP.ReleaseCookieContainer(hCookieContainer) end

---@param hCookieContainer integer
---@param pchHost string
---@param pchUrl string
---@param pchCookie string
---@return boolean
function HTTP.SetCookie(hCookieContainer, pchHost, pchUrl, pchCookie) end

---@param hRequest integer
---@param hCookieContainer integer
---@return boolean
function HTTP.SetHTTPRequestCookieContainer(hRequest, hCookieContainer) end

---@param hRequest integer
---@param pchUserAgentInfo string
---@return boolean
function HTTP.SetHTTPRequestUserAgentInfo(hRequest, pchUserAgentInfo) end

---@param hRequest integer
---@param bRequireVerifiedCertificate boolean
---@return boolean
function HTTP.SetHTTPRequestRequiresVerifiedCertificate(hRequest, bRequireVerifiedCertificate) end

---@param hRequest integer
---@param unMilliseconds integer
---@return boolean
function HTTP.SetHTTPRequestAbsoluteTimeoutMS(hRequest, unMilliseconds) end

---@param hRequest integer
---@return boolean
---@return boolean -- Value of: pbWasTimedOut
function HTTP.GetHTTPRequestWasTimedOut(hRequest) end

Steam.HTTP = HTTP
