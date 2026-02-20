---@class Steam.Timeline
local Timeline = {}

---@param pchDescription string
---@param flTimeDelta number
function Timeline.SetTimelineTooltip(pchDescription, flTimeDelta) end

---@param flTimeDelta number
function Timeline.ClearTimelineTooltip(flTimeDelta) end

---@param eMode integer
function Timeline.SetTimelineGameMode(eMode) end

---@param pchTitle string
---@param pchDescription string
---@param pchIcon string
---@param unIconPriority integer
---@param flStartOffsetSeconds number
---@param ePossibleClip integer
---@return uint64
function Timeline.AddInstantaneousTimelineEvent(pchTitle, pchDescription, pchIcon, unIconPriority, flStartOffsetSeconds, ePossibleClip) end

---@param pchTitle string
---@param pchDescription string
---@param pchIcon string
---@param unIconPriority integer
---@param flStartOffsetSeconds number
---@param flDuration number
---@param ePossibleClip integer
---@return uint64
function Timeline.AddRangeTimelineEvent(pchTitle, pchDescription, pchIcon, unIconPriority, flStartOffsetSeconds, flDuration, ePossibleClip) end

---@param pchTitle string
---@param pchDescription string
---@param pchIcon string
---@param unPriority integer
---@param flStartOffsetSeconds number
---@param ePossibleClip integer
---@return uint64
function Timeline.StartRangeTimelineEvent(pchTitle, pchDescription, pchIcon, unPriority, flStartOffsetSeconds, ePossibleClip) end

---@param ulEvent uint64
---@param pchTitle string
---@param pchDescription string
---@param pchIcon string
---@param unPriority integer
---@param ePossibleClip integer
function Timeline.UpdateRangeTimelineEvent(ulEvent, pchTitle, pchDescription, pchIcon, unPriority, ePossibleClip) end

---@param ulEvent uint64
---@param flEndOffsetSeconds number
function Timeline.EndRangeTimelineEvent(ulEvent, flEndOffsetSeconds) end

---@param ulEvent uint64
function Timeline.RemoveTimelineEvent(ulEvent) end

---@param ulEvent uint64
---@param callback fun(data: SteamTimelineEventRecordingExists_t?, io_fail: boolean)?
---@return uint64
function Timeline.DoesEventRecordingExist(ulEvent, callback) end

function Timeline.StartGamePhase() end

function Timeline.EndGamePhase() end

---@param pchPhaseID string
function Timeline.SetGamePhaseID(pchPhaseID) end

---@param pchPhaseID string
---@param callback fun(data: SteamTimelineGamePhaseRecordingExists_t?, io_fail: boolean)?
---@return uint64
function Timeline.DoesGamePhaseRecordingExist(pchPhaseID, callback) end

---@param pchTagName string
---@param pchTagIcon string
---@param pchTagGroup string
---@param unPriority integer
function Timeline.AddGamePhaseTag(pchTagName, pchTagIcon, pchTagGroup, unPriority) end

---@param pchAttributeGroup string
---@param pchAttributeValue string
---@param unPriority integer
function Timeline.SetGamePhaseAttribute(pchAttributeGroup, pchAttributeValue, unPriority) end

---@param pchPhaseID string
function Timeline.OpenOverlayToGamePhase(pchPhaseID) end

---@param ulEvent uint64
function Timeline.OpenOverlayToTimelineEvent(ulEvent) end

Steam.Timeline = Timeline
