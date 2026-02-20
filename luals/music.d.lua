---@class Steam.Music
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
