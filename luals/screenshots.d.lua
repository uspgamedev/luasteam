---@class Steam.Screenshots
local Screenshots = {}

---@param pubRGB string
---@param cubRGB integer
---@param nWidth integer
---@param nHeight integer
---@return integer
function Screenshots.WriteScreenshot(pubRGB, cubRGB, nWidth, nHeight) end

---@param pchFilename string
---@param pchThumbnailFilename string
---@param nWidth integer
---@param nHeight integer
---@return integer
function Screenshots.AddScreenshotToLibrary(pchFilename, pchThumbnailFilename, nWidth, nHeight) end

function Screenshots.TriggerScreenshot() end

---@param bHook boolean
function Screenshots.HookScreenshots(bHook) end

---@param hScreenshot integer
---@param pchLocation string
---@return boolean
function Screenshots.SetLocation(hScreenshot, pchLocation) end

---@param hScreenshot integer
---@param steamID uint64
---@return boolean
function Screenshots.TagUser(hScreenshot, steamID) end

---@param hScreenshot integer
---@param unPublishedFileID uint64
---@return boolean
function Screenshots.TagPublishedFile(hScreenshot, unPublishedFileID) end

---@return boolean
function Screenshots.IsScreenshotsHooked() end

---@param eType integer
---@param pchFilename string
---@param pchVRFilename string
---@return integer
function Screenshots.AddVRScreenshotToLibrary(eType, pchFilename, pchVRFilename) end

Steam.Screenshots = Screenshots
