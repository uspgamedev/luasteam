################
ISteamRemotePlay
################

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✋ require manual implementation.

List of Functions
-----------------

* :func:`RemotePlay.GetSessionCount`
* :func:`RemotePlay.GetSessionID`
* :func:`RemotePlay.GetSessionSteamID`
* :func:`RemotePlay.GetSessionClientName`
* :func:`RemotePlay.GetSessionClientFormFactor`
* :func:`RemotePlay.BGetSessionClientResolution`
* :func:`RemotePlay.ShowRemotePlayTogetherUI`
* :func:`RemotePlay.BSendRemotePlayTogetherInvite`
* :func:`RemotePlay.BEnableRemotePlayTogetherDirectInput`
* :func:`RemotePlay.DisableRemotePlayTogetherDirectInput`
* :func:`RemotePlay.GetInput`
* :func:`RemotePlay.SetMouseVisibility`
* :func:`RemotePlay.SetMousePosition`
* :func:`RemotePlay.SetMouseCursor`

List of Callbacks
-----------------

* :func:`RemotePlay.onSteamRemotePlaySessionConnected`
* :func:`RemotePlay.onSteamRemotePlaySessionDisconnected`
* :func:`RemotePlay.onSteamRemotePlayTogetherGuestInvite`

Function Reference
------------------

.. function:: RemotePlay.GetSessionCount()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetSessionCount <https://partner.steamgames.com/doc/api/ISteamRemotePlay#GetSessionCount>`_

.. function:: RemotePlay.GetSessionID(iSessionIndex)

    🤖 **Auto-generated binding**

    :param int iSessionIndex:
    :returns: (int) Return value
    :SteamWorks: `GetSessionID <https://partner.steamgames.com/doc/api/ISteamRemotePlay#GetSessionID>`_

.. function:: RemotePlay.GetSessionSteamID(unSessionID)

    🤖 **Auto-generated binding**

    :param int unSessionID:
    :returns: (uint64) Return value
    :SteamWorks: `GetSessionSteamID <https://partner.steamgames.com/doc/api/ISteamRemotePlay#GetSessionSteamID>`_

.. function:: RemotePlay.GetSessionClientName(unSessionID)

    🤖 **Auto-generated binding**

    :param int unSessionID:
    :returns: (str) Return value
    :SteamWorks: `GetSessionClientName <https://partner.steamgames.com/doc/api/ISteamRemotePlay#GetSessionClientName>`_

.. function:: RemotePlay.GetSessionClientFormFactor(unSessionID)

    🤖 **Auto-generated binding**

    :param int unSessionID:
    :returns: (int) Return value
    :SteamWorks: `GetSessionClientFormFactor <https://partner.steamgames.com/doc/api/ISteamRemotePlay#GetSessionClientFormFactor>`_

.. function:: RemotePlay.BGetSessionClientResolution(unSessionID)

    🤖 **Auto-generated binding**

    :param int unSessionID:
    :returns: (bool) Return value
    :returns: (int) Value for `pnResolutionX`
    :returns: (int) Value for `pnResolutionY`
    :SteamWorks: `BGetSessionClientResolution <https://partner.steamgames.com/doc/api/ISteamRemotePlay#BGetSessionClientResolution>`_

    **Signature differences from C++ API:**

    * Parameter ``pnResolutionX`` is no longer a paramer, and is instead an additional return value
    * Parameter ``pnResolutionY`` is no longer a paramer, and is instead an additional return value

.. function:: RemotePlay.ShowRemotePlayTogetherUI()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `ShowRemotePlayTogetherUI <https://partner.steamgames.com/doc/api/ISteamRemotePlay#ShowRemotePlayTogetherUI>`_

.. function:: RemotePlay.BSendRemotePlayTogetherInvite(steamIDFriend)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :returns: (bool) Return value
    :SteamWorks: `BSendRemotePlayTogetherInvite <https://partner.steamgames.com/doc/api/ISteamRemotePlay#BSendRemotePlayTogetherInvite>`_

.. function:: RemotePlay.BEnableRemotePlayTogetherDirectInput()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BEnableRemotePlayTogetherDirectInput <https://partner.steamgames.com/doc/api/ISteamRemotePlay#BEnableRemotePlayTogetherDirectInput>`_

.. function:: RemotePlay.DisableRemotePlayTogetherDirectInput()

    🤖 **Auto-generated binding**

    :SteamWorks: `DisableRemotePlayTogetherDirectInput <https://partner.steamgames.com/doc/api/ISteamRemotePlay#DisableRemotePlayTogetherDirectInput>`_

.. function:: RemotePlay.GetInput(unMaxEvents)

    🤖 **Auto-generated binding**

    :param int unMaxEvents:
    :returns: (int) Return value
    :returns: (:ref:`RemotePlayInput_t <struct-RemotePlayInput_t>`[]) Value for `pInput`
    :SteamWorks: `GetInput <https://partner.steamgames.com/doc/api/ISteamRemotePlay#GetInput>`_

    **Signature differences from C++ API:**

    * Parameter ``pInput`` is no longer a paramer, and is instead an additional return value

.. function:: RemotePlay.SetMouseVisibility(unSessionID, bVisible)

    🤖 **Auto-generated binding**

    :param int unSessionID:
    :param bool bVisible:
    :SteamWorks: `SetMouseVisibility <https://partner.steamgames.com/doc/api/ISteamRemotePlay#SetMouseVisibility>`_

.. function:: RemotePlay.SetMousePosition(unSessionID, flNormalizedX, flNormalizedY)

    🤖 **Auto-generated binding**

    :param int unSessionID:
    :param float flNormalizedX:
    :param float flNormalizedY:
    :SteamWorks: `SetMousePosition <https://partner.steamgames.com/doc/api/ISteamRemotePlay#SetMousePosition>`_

.. function:: RemotePlay.SetMouseCursor(unSessionID, unCursorID)

    🤖 **Auto-generated binding**

    :param int unSessionID:
    :param int unCursorID:
    :SteamWorks: `SetMouseCursor <https://partner.steamgames.com/doc/api/ISteamRemotePlay#SetMouseCursor>`_


Unimplemented Methods
---------------------

.. function:: RemotePlay.createMouseCursor

    ✋ **Not implemented** - unsupported type: const void *
    
    :SteamWorks: `CreateMouseCursor <https://partner.steamgames.com/doc/api/ISteamRemotePlay#CreateMouseCursor>`_


Callbacks
---------

.. function:: RemotePlay.onSteamRemotePlaySessionConnected

    Callback for `SteamRemotePlaySessionConnected_t <https://partner.steamgames.com/doc/api/ISteamRemotePlay#SteamRemotePlaySessionConnected_t>`_

    **callback(data)** receives:

    * **data.m_unSessionID** -- m_unSessionID

.. function:: RemotePlay.onSteamRemotePlaySessionDisconnected

    Callback for `SteamRemotePlaySessionDisconnected_t <https://partner.steamgames.com/doc/api/ISteamRemotePlay#SteamRemotePlaySessionDisconnected_t>`_

    **callback(data)** receives:

    * **data.m_unSessionID** -- m_unSessionID

.. function:: RemotePlay.onSteamRemotePlayTogetherGuestInvite

    Callback for `SteamRemotePlayTogetherGuestInvite_t <https://partner.steamgames.com/doc/api/ISteamRemotePlay#SteamRemotePlayTogetherGuestInvite_t>`_

    **callback(data)** receives:

    * **data.m_szConnectURL** -- m_szConnectURL

