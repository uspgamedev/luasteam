---@class Steam.Video
---@field OnGetVideoURLResult? fun(data: GetVideoURLResult_t)
---@field OnGetOPFSettingsResult? fun(data: GetOPFSettingsResult_t)
---@field OnBroadcastUploadStart? fun(data: BroadcastUploadStart_t)
---@field OnBroadcastUploadStop? fun(data: BroadcastUploadStop_t)
local Video = {}

---@param unVideoAppID integer
function Video.GetVideoURL(unVideoAppID) end

---@return boolean
---@return integer -- Value of: pnNumViewers
function Video.IsBroadcasting() end

---@param unVideoAppID integer
function Video.GetOPFSettings(unVideoAppID) end

---@param unVideoAppID integer
---@param pnBufferSize integer
---@return boolean
---@return string -- Value of: pchBuffer
---@return integer -- Value of: pnBufferSize
function Video.GetOPFStringForApp(unVideoAppID, pnBufferSize) end

Steam.Video = Video
