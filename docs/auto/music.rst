###########
ISteamMusic
###########

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✍️ are manually implemented and methods marked with ✋ are currently not implemented.

List of Functions
-----------------

* :func:`Music.BIsEnabled`
* :func:`Music.BIsPlaying`
* :func:`Music.GetPlaybackStatus`
* :func:`Music.GetVolume`
* :func:`Music.Pause`
* :func:`Music.Play`
* :func:`Music.PlayNext`
* :func:`Music.PlayPrevious`
* :func:`Music.SetVolume`

List of Callbacks
-----------------

* :func:`Music.OnPlaybackStatusHasChanged`
* :func:`Music.OnVolumeHasChanged`

Function Reference
------------------

.. function:: Music.BIsEnabled()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BIsEnabled <https://partner.steamgames.com/doc/api/ISteamMusic#BIsEnabled>`_

**Example**::

    if Steam.Music.BIsEnabled() then
        print('Steam Music is enabled')
    end

.. function:: Music.BIsPlaying()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BIsPlaying <https://partner.steamgames.com/doc/api/ISteamMusic#BIsPlaying>`_

**Example**::

    if Steam.Music.BIsPlaying() then
        print('Current status: ' .. Steam.Music.GetPlaybackStatus())
    end

.. function:: Music.GetPlaybackStatus()

    🤖 **Auto-generated binding**

    :returns: (int) ``AudioPlayback_Status``
    :SteamWorks: `GetPlaybackStatus <https://partner.steamgames.com/doc/api/ISteamMusic#GetPlaybackStatus>`_

**Example**::

    local status = Steam.Music.GetPlaybackStatus()
    -- 0=Undefined, 1=Playing, 2=Paused, 3=Idle
    if status == 1 then
        print('Music is playing')
    end

.. function:: Music.GetVolume()

    🤖 **Auto-generated binding**

    :returns: (float) Return value
    :SteamWorks: `GetVolume <https://partner.steamgames.com/doc/api/ISteamMusic#GetVolume>`_

.. function:: Music.Pause()

    🤖 **Auto-generated binding**

    :SteamWorks: `Pause <https://partner.steamgames.com/doc/api/ISteamMusic#Pause>`_

**Example**::

    if Steam.Music.BIsPlaying() then
        Steam.Music.Pause()
    end

.. function:: Music.Play()

    🤖 **Auto-generated binding**

    :SteamWorks: `Play <https://partner.steamgames.com/doc/api/ISteamMusic#Play>`_

**Example**::

    if not Steam.Music.BIsPlaying() then
        Steam.Music.Play()
    end

.. function:: Music.PlayNext()

    🤖 **Auto-generated binding**

    :SteamWorks: `PlayNext <https://partner.steamgames.com/doc/api/ISteamMusic#PlayNext>`_

**Example**::

    Steam.Music.PlayNext()

.. function:: Music.PlayPrevious()

    🤖 **Auto-generated binding**

    :SteamWorks: `PlayPrevious <https://partner.steamgames.com/doc/api/ISteamMusic#PlayPrevious>`_

.. function:: Music.SetVolume(flVolume)

    🤖 **Auto-generated binding**

    :param float flVolume:
    :SteamWorks: `SetVolume <https://partner.steamgames.com/doc/api/ISteamMusic#SetVolume>`_

**Example**::

    Steam.Music.SetVolume(0.5)  -- Set to 50%


Callbacks
---------

.. function:: Music.OnPlaybackStatusHasChanged

    Callback for `PlaybackStatusHasChanged_t <https://partner.steamgames.com/doc/api/ISteamMusic#PlaybackStatusHasChanged_t>`_

    **callback(data)** receives no fields (notification only).

**Example**::

    function Steam.Music.OnPlaybackStatusHasChanged()
        local status = Steam.Music.GetPlaybackStatus()
        print('Music status changed:', status)
    end

.. function:: Music.OnVolumeHasChanged

    Callback for `VolumeHasChanged_t <https://partner.steamgames.com/doc/api/ISteamMusic#VolumeHasChanged_t>`_

    **callback(data)** receives:

    * **data.m_flNewVolume** *(float)*

**Example**::

    function Steam.Music.OnVolumeHasChanged(data)
        print('Music volume changed to:', data.m_flNewVolume)
    end

