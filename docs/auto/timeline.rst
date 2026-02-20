##############
ISteamTimeline
##############

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✋ require manual implementation.

List of Functions
-----------------

* :func:`Timeline.SetTimelineTooltip`
* :func:`Timeline.ClearTimelineTooltip`
* :func:`Timeline.SetTimelineGameMode`
* :func:`Timeline.AddInstantaneousTimelineEvent`
* :func:`Timeline.AddRangeTimelineEvent`
* :func:`Timeline.StartRangeTimelineEvent`
* :func:`Timeline.UpdateRangeTimelineEvent`
* :func:`Timeline.EndRangeTimelineEvent`
* :func:`Timeline.RemoveTimelineEvent`
* :func:`Timeline.DoesEventRecordingExist`
* :func:`Timeline.StartGamePhase`
* :func:`Timeline.EndGamePhase`
* :func:`Timeline.SetGamePhaseID`
* :func:`Timeline.DoesGamePhaseRecordingExist`
* :func:`Timeline.AddGamePhaseTag`
* :func:`Timeline.SetGamePhaseAttribute`
* :func:`Timeline.OpenOverlayToGamePhase`
* :func:`Timeline.OpenOverlayToTimelineEvent`

List of Callbacks
-----------------

* :func:`Timeline.onSteamTimelineGamePhaseRecordingExists`
* :func:`Timeline.onSteamTimelineEventRecordingExists`

Function Reference
------------------

.. function:: Timeline.SetTimelineTooltip(pchDescription, flTimeDelta)

    🤖 **Auto-generated binding**

    :param str pchDescription:
    :param float flTimeDelta:
    :SteamWorks: `SetTimelineTooltip <https://partner.steamgames.com/doc/api/ISteamTimeline#SetTimelineTooltip>`_

.. function:: Timeline.ClearTimelineTooltip(flTimeDelta)

    🤖 **Auto-generated binding**

    :param float flTimeDelta:
    :SteamWorks: `ClearTimelineTooltip <https://partner.steamgames.com/doc/api/ISteamTimeline#ClearTimelineTooltip>`_

.. function:: Timeline.SetTimelineGameMode(eMode)

    🤖 **Auto-generated binding**

    :param int eMode:
    :SteamWorks: `SetTimelineGameMode <https://partner.steamgames.com/doc/api/ISteamTimeline#SetTimelineGameMode>`_

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

.. function:: Timeline.UpdateRangeTimelineEvent(ulEvent, pchTitle, pchDescription, pchIcon, unPriority, ePossibleClip)

    🤖 **Auto-generated binding**

    :param uint64 ulEvent:
    :param str pchTitle:
    :param str pchDescription:
    :param str pchIcon:
    :param int unPriority:
    :param int ePossibleClip:
    :SteamWorks: `UpdateRangeTimelineEvent <https://partner.steamgames.com/doc/api/ISteamTimeline#UpdateRangeTimelineEvent>`_

.. function:: Timeline.EndRangeTimelineEvent(ulEvent, flEndOffsetSeconds)

    🤖 **Auto-generated binding**

    :param uint64 ulEvent:
    :param float flEndOffsetSeconds:
    :SteamWorks: `EndRangeTimelineEvent <https://partner.steamgames.com/doc/api/ISteamTimeline#EndRangeTimelineEvent>`_

.. function:: Timeline.RemoveTimelineEvent(ulEvent)

    🤖 **Auto-generated binding**

    :param uint64 ulEvent:
    :SteamWorks: `RemoveTimelineEvent <https://partner.steamgames.com/doc/api/ISteamTimeline#RemoveTimelineEvent>`_

.. function:: Timeline.DoesEventRecordingExist(ulEvent, callback)

    🤖 **Auto-generated binding**

    :param uint64 ulEvent:
    :param function callback: CallResult callback receiving struct `SteamTimelineEventRecordingExists_t` and a boolean)
    :returns: (uint64) Return value
    :SteamWorks: `DoesEventRecordingExist <https://partner.steamgames.com/doc/api/ISteamTimeline#DoesEventRecordingExist>`_

.. function:: Timeline.StartGamePhase()

    🤖 **Auto-generated binding**

    :SteamWorks: `StartGamePhase <https://partner.steamgames.com/doc/api/ISteamTimeline#StartGamePhase>`_

.. function:: Timeline.EndGamePhase()

    🤖 **Auto-generated binding**

    :SteamWorks: `EndGamePhase <https://partner.steamgames.com/doc/api/ISteamTimeline#EndGamePhase>`_

.. function:: Timeline.SetGamePhaseID(pchPhaseID)

    🤖 **Auto-generated binding**

    :param str pchPhaseID:
    :SteamWorks: `SetGamePhaseID <https://partner.steamgames.com/doc/api/ISteamTimeline#SetGamePhaseID>`_

.. function:: Timeline.DoesGamePhaseRecordingExist(pchPhaseID, callback)

    🤖 **Auto-generated binding**

    :param str pchPhaseID:
    :param function callback: CallResult callback receiving struct `SteamTimelineGamePhaseRecordingExists_t` and a boolean)
    :returns: (uint64) Return value
    :SteamWorks: `DoesGamePhaseRecordingExist <https://partner.steamgames.com/doc/api/ISteamTimeline#DoesGamePhaseRecordingExist>`_

.. function:: Timeline.AddGamePhaseTag(pchTagName, pchTagIcon, pchTagGroup, unPriority)

    🤖 **Auto-generated binding**

    :param str pchTagName:
    :param str pchTagIcon:
    :param str pchTagGroup:
    :param int unPriority:
    :SteamWorks: `AddGamePhaseTag <https://partner.steamgames.com/doc/api/ISteamTimeline#AddGamePhaseTag>`_

.. function:: Timeline.SetGamePhaseAttribute(pchAttributeGroup, pchAttributeValue, unPriority)

    🤖 **Auto-generated binding**

    :param str pchAttributeGroup:
    :param str pchAttributeValue:
    :param int unPriority:
    :SteamWorks: `SetGamePhaseAttribute <https://partner.steamgames.com/doc/api/ISteamTimeline#SetGamePhaseAttribute>`_

.. function:: Timeline.OpenOverlayToGamePhase(pchPhaseID)

    🤖 **Auto-generated binding**

    :param str pchPhaseID:
    :SteamWorks: `OpenOverlayToGamePhase <https://partner.steamgames.com/doc/api/ISteamTimeline#OpenOverlayToGamePhase>`_

.. function:: Timeline.OpenOverlayToTimelineEvent(ulEvent)

    🤖 **Auto-generated binding**

    :param uint64 ulEvent:
    :SteamWorks: `OpenOverlayToTimelineEvent <https://partner.steamgames.com/doc/api/ISteamTimeline#OpenOverlayToTimelineEvent>`_


Callbacks
---------

.. function:: Timeline.onSteamTimelineGamePhaseRecordingExists

    Callback for `SteamTimelineGamePhaseRecordingExists_t <https://partner.steamgames.com/doc/api/steam_api#SteamTimelineGamePhaseRecordingExists_t>`_

    **callback(data)** receives:

    * **data.m_rgchPhaseID** -- m_rgchPhaseID
    * **data.m_ulRecordingMS** -- m_ulRecordingMS
    * **data.m_ulLongestClipMS** -- m_ulLongestClipMS
    * **data.m_unClipCount** -- m_unClipCount
    * **data.m_unScreenshotCount** -- m_unScreenshotCount

.. function:: Timeline.onSteamTimelineEventRecordingExists

    Callback for `SteamTimelineEventRecordingExists_t <https://partner.steamgames.com/doc/api/steam_api#SteamTimelineEventRecordingExists_t>`_

    **callback(data)** receives:

    * **data.m_ulEventID** -- m_ulEventID
    * **data.m_bRecordingExists** -- m_bRecordingExists

