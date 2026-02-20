---@class Steam.RemotePlay
local RemotePlay = {}

---@return integer
function RemotePlay.GetSessionCount() end

---@param iSessionIndex integer
---@return integer
function RemotePlay.GetSessionID(iSessionIndex) end

---@param unSessionID integer
---@return uint64
function RemotePlay.GetSessionSteamID(unSessionID) end

---@param unSessionID integer
---@return string
function RemotePlay.GetSessionClientName(unSessionID) end

---@param unSessionID integer
---@return integer
function RemotePlay.GetSessionClientFormFactor(unSessionID) end

---@param unSessionID integer
---@return boolean
---@return integer
---@return integer
function RemotePlay.BGetSessionClientResolution(unSessionID) end

---@return boolean
function RemotePlay.ShowRemotePlayTogetherUI() end

---@param steamIDFriend uint64
---@return boolean
function RemotePlay.BSendRemotePlayTogetherInvite(steamIDFriend) end

---@return boolean
function RemotePlay.BEnableRemotePlayTogetherDirectInput() end

function RemotePlay.DisableRemotePlayTogetherDirectInput() end

---@param unMaxEvents integer
---@return integer
---@return table
function RemotePlay.GetInput(unMaxEvents) end

---@param unSessionID integer
---@param bVisible boolean
function RemotePlay.SetMouseVisibility(unSessionID, bVisible) end

---@param unSessionID integer
---@param flNormalizedX number
---@param flNormalizedY number
function RemotePlay.SetMousePosition(unSessionID, flNormalizedX, flNormalizedY) end

---@param nWidth integer
---@param nHeight integer
---@param nHotX integer
---@param nHotY integer
---@param pBGRA table
---@param nPitch integer
---@return integer
function RemotePlay.CreateMouseCursor(nWidth, nHeight, nHotX, nHotY, pBGRA, nPitch) end

---@param unSessionID integer
---@param unCursorID integer
function RemotePlay.SetMouseCursor(unSessionID, unCursorID) end

Steam.RemotePlay = RemotePlay
