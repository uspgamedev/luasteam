---@class Steam.Video
local Video = {}

---@param unVideoAppID integer
function Video.GetVideoURL(unVideoAppID) end

---@return boolean
---@return integer
function Video.IsBroadcasting() end

---@param unVideoAppID integer
function Video.GetOPFSettings(unVideoAppID) end

---@param unVideoAppID integer
---@param pchBuffer string
---@return boolean
---@return integer
function Video.GetOPFStringForApp(unVideoAppID, pchBuffer) end

Steam.Video = Video
