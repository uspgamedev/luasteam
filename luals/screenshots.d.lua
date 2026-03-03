---@class Steam.Screenshots
---@field OnScreenshotReady? fun(data: ScreenshotReady_t)
---@field OnScreenshotRequested? fun(data: ScreenshotRequested_t)
local Screenshots = {}

---@param pubRGB string?
---@param cubRGB integer size of the input array pubRGB
---@param nWidth integer
---@param nHeight integer
---@return integer -- ScreenshotHandle
function Screenshots.WriteScreenshot(pubRGB, cubRGB, nWidth, nHeight) end

---@param pchFilename string?
---@param pchThumbnailFilename string?
---@param nWidth integer
---@param nHeight integer
---@return integer -- ScreenshotHandle
function Screenshots.AddScreenshotToLibrary(pchFilename, pchThumbnailFilename, nWidth, nHeight) end

function Screenshots.TriggerScreenshot() end

---@param bHook boolean
function Screenshots.HookScreenshots(bHook) end

---@param hScreenshot integer -- ScreenshotHandle
---@param pchLocation string?
---@return boolean
function Screenshots.SetLocation(hScreenshot, pchLocation) end

---@param hScreenshot integer -- ScreenshotHandle
---@param steamID uint64
---@return boolean
function Screenshots.TagUser(hScreenshot, steamID) end

---@param hScreenshot integer -- ScreenshotHandle
---@param unPublishedFileID uint64 -- PublishedFileId_t
---@return boolean
function Screenshots.TagPublishedFile(hScreenshot, unPublishedFileID) end

---@return boolean
function Screenshots.IsScreenshotsHooked() end

---@param eType integer -- EVRScreenshotType
---@param pchFilename string?
---@param pchVRFilename string?
---@return integer -- ScreenshotHandle
function Screenshots.AddVRScreenshotToLibrary(eType, pchFilename, pchVRFilename) end

Steam.Screenshots = Screenshots
