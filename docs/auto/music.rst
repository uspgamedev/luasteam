###########
ISteamMusic
###########

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✋ require manual implementation.

List of Functions
-----------------

* :func:`Music.BIsEnabled`
* :func:`Music.BIsPlaying`
* :func:`Music.GetPlaybackStatus`
* :func:`Music.Play`
* :func:`Music.Pause`
* :func:`Music.PlayPrevious`
* :func:`Music.PlayNext`
* :func:`Music.SetVolume`
* :func:`Music.GetVolume`

List of Callbacks
-----------------

* :func:`Music.onPlaybackStatusHasChanged`
* :func:`Music.onVolumeHasChanged`

Function Reference
------------------

.. function:: Music.BIsEnabled()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BIsEnabled <https://partner.steamgames.com/doc/api/ISteamMusic#BIsEnabled>`_

.. function:: Music.BIsPlaying()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BIsPlaying <https://partner.steamgames.com/doc/api/ISteamMusic#BIsPlaying>`_

.. function:: Music.GetPlaybackStatus()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetPlaybackStatus <https://partner.steamgames.com/doc/api/ISteamMusic#GetPlaybackStatus>`_

.. function:: Music.Play()

    🤖 **Auto-generated binding**

    :SteamWorks: `Play <https://partner.steamgames.com/doc/api/ISteamMusic#Play>`_

.. function:: Music.Pause()

    🤖 **Auto-generated binding**

    :SteamWorks: `Pause <https://partner.steamgames.com/doc/api/ISteamMusic#Pause>`_

.. function:: Music.PlayPrevious()

    🤖 **Auto-generated binding**

    :SteamWorks: `PlayPrevious <https://partner.steamgames.com/doc/api/ISteamMusic#PlayPrevious>`_

.. function:: Music.PlayNext()

    🤖 **Auto-generated binding**

    :SteamWorks: `PlayNext <https://partner.steamgames.com/doc/api/ISteamMusic#PlayNext>`_

.. function:: Music.SetVolume(flVolume)

    🤖 **Auto-generated binding**

    :param float flVolume:
    :SteamWorks: `SetVolume <https://partner.steamgames.com/doc/api/ISteamMusic#SetVolume>`_

.. function:: Music.GetVolume()

    🤖 **Auto-generated binding**

    :returns: (float) Return value
    :SteamWorks: `GetVolume <https://partner.steamgames.com/doc/api/ISteamMusic#GetVolume>`_


Callbacks
---------

.. function:: Music.onPlaybackStatusHasChanged

    Callback for `PlaybackStatusHasChanged_t <https://partner.steamgames.com/doc/api/ISteamMusic#PlaybackStatusHasChanged_t>`_

    **callback(data)** receives:


.. function:: Music.onVolumeHasChanged

    Callback for `VolumeHasChanged_t <https://partner.steamgames.com/doc/api/ISteamMusic#VolumeHasChanged_t>`_

    **callback(data)** receives:

    * **data.m_flNewVolume** -- m_flNewVolume

