---@class Steam.Music
---@field OnPlaybackStatusHasChanged? fun(data: PlaybackStatusHasChanged_t)
---@field OnVolumeHasChanged? fun(data: VolumeHasChanged_t)
local Music = {}

---@return boolean
function Music.BIsEnabled() end

---@return boolean
function Music.BIsPlaying() end

---@return integer
function Music.GetPlaybackStatus() end

function Music.Play() end

function Music.Pause() end

function Music.PlayPrevious() end

function Music.PlayNext() end

---@param flVolume number
function Music.SetVolume(flVolume) end

---@return number
function Music.GetVolume() end

Steam.Music = Music
