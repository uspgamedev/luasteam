##############
ISteamTimeline
##############

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✍️ are manually implemented and methods marked with ✋ are currently not implemented.

List of Functions
-----------------

* :func:`Timeline.AddGamePhaseTag`
* :func:`Timeline.AddInstantaneousTimelineEvent`
* :func:`Timeline.AddRangeTimelineEvent`
* :func:`Timeline.ClearTimelineTooltip`
* :func:`Timeline.DoesEventRecordingExist`
* :func:`Timeline.DoesGamePhaseRecordingExist`
* :func:`Timeline.EndGamePhase`
* :func:`Timeline.EndRangeTimelineEvent`
* :func:`Timeline.OpenOverlayToGamePhase`
* :func:`Timeline.OpenOverlayToTimelineEvent`
* :func:`Timeline.RemoveTimelineEvent`
* :func:`Timeline.SetGamePhaseAttribute`
* :func:`Timeline.SetGamePhaseID`
* :func:`Timeline.SetTimelineGameMode`
* :func:`Timeline.SetTimelineTooltip`
* :func:`Timeline.StartGamePhase`
* :func:`Timeline.StartRangeTimelineEvent`
* :func:`Timeline.UpdateRangeTimelineEvent`

List of Callbacks
-----------------

* :func:`Timeline.OnSteamTimelineGamePhaseRecordingExists`
* :func:`Timeline.OnSteamTimelineEventRecordingExists`

Function Reference
------------------

.. function:: Timeline.AddGamePhaseTag(pchTagName, pchTagIcon, pchTagGroup, unPriority)

    🤖 **Auto-generated binding**

    :param str pchTagName:
    :param str pchTagIcon:
    :param str pchTagGroup:
    :param int unPriority:
    :SteamWorks: `AddGamePhaseTag <https://partner.steamgames.com/doc/api/ISteamTimeline#AddGamePhaseTag>`_

.. function:: Timeline.AddInstantaneousTimelineEvent(pchTitle, pchDescription, pchIcon, unIconPriority, flStartOffsetSeconds, ePossibleClip)

    🤖 **Auto-generated binding**

    :param str pchTitle:
    :param str pchDescription:
    :param str pchIcon:
    :param int unIconPriority:
    :param float flStartOffsetSeconds:
    :param int ePossibleClip:
    :returns: (uint64) Return value
    :SteamWorks: `AddInstantaneousTimelineEvent <https://partner.steamgames.com/doc/api/ISteamTimeline#AddInstantaneousTimelineEvent>`_

**Example**::

    -- Mark when player gets an achievement
    Steam.Timeline.AddInstantaneousTimelineEvent(
        'Achievement Unlocked', 'First Blood', 'achievement_icon', 1, 0, 'RecordAtFarther')

.. function:: Timeline.AddRangeTimelineEvent(pchTitle, pchDescription, pchIcon, unIconPriority, flStartOffsetSeconds, flDuration, ePossibleClip)

    🤖 **Auto-generated binding**

    :param str pchTitle:
    :param str pchDescription:
    :param str pchIcon:
    :param int unIconPriority:
    :param float flStartOffsetSeconds:
    :param float flDuration:
    :param int ePossibleClip:
    :returns: (uint64) Return value
    :SteamWorks: `AddRangeTimelineEvent <https://partner.steamgames.com/doc/api/ISteamTimeline#AddRangeTimelineEvent>`_

**Example**::

    -- Mark an entire boss fight after it ends
    Steam.Timeline.AddRangeTimelineEvent(
        'Boss Fight', 'Dragon Battle', 'sword_icon', 1, -bossFightDuration, bossFightDuration, 'RecordAtFarther')

.. function:: Timeline.ClearTimelineTooltip(flTimeDelta)

    🤖 **Auto-generated binding**

    :param float flTimeDelta:
    :SteamWorks: `ClearTimelineTooltip <https://partner.steamgames.com/doc/api/ISteamTimeline#ClearTimelineTooltip>`_

**Example**::

    Steam.Timeline.ClearTimelineTooltip(0)

.. function:: Timeline.DoesEventRecordingExist(ulEvent, callback)

    🤖 **Auto-generated binding**

    :param uint64 ulEvent:
    :param function callback: CallResult callback receiving struct :func:`SteamTimelineEventRecordingExists_t <Timeline.OnSteamTimelineEventRecordingExists>` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `DoesEventRecordingExist <https://partner.steamgames.com/doc/api/ISteamTimeline#DoesEventRecordingExist>`_

.. function:: Timeline.DoesGamePhaseRecordingExist(pchPhaseID, callback)

    🤖 **Auto-generated binding**

    :param str pchPhaseID:
    :param function callback: CallResult callback receiving struct :func:`SteamTimelineGamePhaseRecordingExists_t <Timeline.OnSteamTimelineGamePhaseRecordingExists>` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `DoesGamePhaseRecordingExist <https://partner.steamgames.com/doc/api/ISteamTimeline#DoesGamePhaseRecordingExist>`_

.. function:: Timeline.EndGamePhase()

    🤖 **Auto-generated binding**

    :SteamWorks: `EndGamePhase <https://partner.steamgames.com/doc/api/ISteamTimeline#EndGamePhase>`_

**Example**::

    Steam.Timeline.EndGamePhase()

.. function:: Timeline.EndRangeTimelineEvent(ulEvent, flEndOffsetSeconds)

    🤖 **Auto-generated binding**

    :param uint64 ulEvent:
    :param float flEndOffsetSeconds:
    :SteamWorks: `EndRangeTimelineEvent <https://partner.steamgames.com/doc/api/ISteamTimeline#EndRangeTimelineEvent>`_

**Example**::

    Steam.Timeline.EndRangeTimelineEvent(eventHandle, 0)

.. function:: Timeline.OpenOverlayToGamePhase(pchPhaseID)

    🤖 **Auto-generated binding**

    :param str pchPhaseID:
    :SteamWorks: `OpenOverlayToGamePhase <https://partner.steamgames.com/doc/api/ISteamTimeline#OpenOverlayToGamePhase>`_

.. function:: Timeline.OpenOverlayToTimelineEvent(ulEvent)

    🤖 **Auto-generated binding**

    :param uint64 ulEvent:
    :SteamWorks: `OpenOverlayToTimelineEvent <https://partner.steamgames.com/doc/api/ISteamTimeline#OpenOverlayToTimelineEvent>`_

**Example**::

    -- Let the player review the clip for this event
    Steam.Timeline.OpenOverlayToTimelineEvent(eventHandle)

.. function:: Timeline.RemoveTimelineEvent(ulEvent)

    🤖 **Auto-generated binding**

    :param uint64 ulEvent:
    :SteamWorks: `RemoveTimelineEvent <https://partner.steamgames.com/doc/api/ISteamTimeline#RemoveTimelineEvent>`_

.. function:: Timeline.SetGamePhaseAttribute(pchAttributeGroup, pchAttributeValue, unPriority)

    🤖 **Auto-generated binding**

    :param str pchAttributeGroup:
    :param str pchAttributeValue:
    :param int unPriority:
    :SteamWorks: `SetGamePhaseAttribute <https://partner.steamgames.com/doc/api/ISteamTimeline#SetGamePhaseAttribute>`_

.. function:: Timeline.SetGamePhaseID(pchPhaseID)

    🤖 **Auto-generated binding**

    :param str pchPhaseID:
    :SteamWorks: `SetGamePhaseID <https://partner.steamgames.com/doc/api/ISteamTimeline#SetGamePhaseID>`_

    **Notes:**

    * See :func:`Timeline.StartGamePhase`'s example.

.. function:: Timeline.SetTimelineGameMode(eMode)

    🤖 **Auto-generated binding**

    :param int eMode:
    :SteamWorks: `SetTimelineGameMode <https://partner.steamgames.com/doc/api/ISteamTimeline#SetTimelineGameMode>`_

**Example**::

    -- Set mode to show what the player is doing
    Steam.Timeline.SetTimelineGameMode('Playing')

.. function:: Timeline.SetTimelineTooltip(pchDescription, flTimeDelta)

    🤖 **Auto-generated binding**

    :param str pchDescription:
    :param float flTimeDelta:
    :SteamWorks: `SetTimelineTooltip <https://partner.steamgames.com/doc/api/ISteamTimeline#SetTimelineTooltip>`_

**Example**::

    Steam.Timeline.SetTimelineTooltip('Fighting the final boss', 0)

.. function:: Timeline.StartGamePhase()

    🤖 **Auto-generated binding**

    :SteamWorks: `StartGamePhase <https://partner.steamgames.com/doc/api/ISteamTimeline#StartGamePhase>`_

**Example**::

    Steam.Timeline.StartGamePhase()
    Steam.Timeline.SetGamePhaseID('level_3')

.. function:: Timeline.StartRangeTimelineEvent(pchTitle, pchDescription, pchIcon, unPriority, flStartOffsetSeconds, ePossibleClip)

    🤖 **Auto-generated binding**

    :param str pchTitle:
    :param str pchDescription:
    :param str pchIcon:
    :param int unPriority:
    :param float flStartOffsetSeconds:
    :param int ePossibleClip:
    :returns: (uint64) Return value
    :SteamWorks: `StartRangeTimelineEvent <https://partner.steamgames.com/doc/api/ISteamTimeline#StartRangeTimelineEvent>`_

**Example**::

    -- Start tracking a ranged event
    local eventHandle = Steam.Timeline.StartRangeTimelineEvent(
        'Boss Fight', 'Dragon Battle', 'sword_icon', 1, 0, 'RecordAtFarther')

.. function:: Timeline.UpdateRangeTimelineEvent(ulEvent, pchTitle, pchDescription, pchIcon, unPriority, ePossibleClip)

    🤖 **Auto-generated binding**

    :param uint64 ulEvent:
    :param str pchTitle:
    :param str pchDescription:
    :param str pchIcon:
    :param int unPriority:
    :param int ePossibleClip:
    :SteamWorks: `UpdateRangeTimelineEvent <https://partner.steamgames.com/doc/api/ISteamTimeline#UpdateRangeTimelineEvent>`_


Callbacks
---------

.. function:: Timeline.OnSteamTimelineGamePhaseRecordingExists

    Callback for `SteamTimelineGamePhaseRecordingExists_t <https://partner.steamgames.com/doc/api/ISteamTimeline#SteamTimelineGamePhaseRecordingExists_t>`_

    **callback(data)** receives:

    * **data.m_rgchPhaseID** *(string)*
    * **data.m_ulRecordingMS** *(uint64)*
    * **data.m_ulLongestClipMS** *(uint64)*
    * **data.m_unClipCount** *(int)*
    * **data.m_unScreenshotCount** *(int)*

.. function:: Timeline.OnSteamTimelineEventRecordingExists

    Callback for `SteamTimelineEventRecordingExists_t <https://partner.steamgames.com/doc/api/ISteamTimeline#SteamTimelineEventRecordingExists_t>`_

    **callback(data)** receives:

    * **data.m_ulEventID** *(uint64)*
    * **data.m_bRecordingExists** *(bool)*

