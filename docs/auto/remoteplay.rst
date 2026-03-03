################
ISteamRemotePlay
################

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✍️ are manually implemented and methods marked with ✋ are currently not implemented.

List of Functions
-----------------

* :func:`RemotePlay.BEnableRemotePlayTogetherDirectInput`
* :func:`RemotePlay.BGetSessionClientResolution`
* :func:`RemotePlay.BSendRemotePlayTogetherInvite`
* :func:`RemotePlay.CreateMouseCursor`
* :func:`RemotePlay.DisableRemotePlayTogetherDirectInput`
* :func:`RemotePlay.GetInput`
* :func:`RemotePlay.GetSessionClientFormFactor`
* :func:`RemotePlay.GetSessionClientName`
* :func:`RemotePlay.GetSessionCount`
* :func:`RemotePlay.GetSessionID`
* :func:`RemotePlay.GetSessionSteamID`
* :func:`RemotePlay.SetMouseCursor`
* :func:`RemotePlay.SetMousePosition`
* :func:`RemotePlay.SetMouseVisibility`
* :func:`RemotePlay.ShowRemotePlayTogetherUI`

List of Callbacks
-----------------

* :func:`RemotePlay.OnSteamRemotePlaySessionConnected`
* :func:`RemotePlay.OnSteamRemotePlaySessionDisconnected`
* :func:`RemotePlay.OnSteamRemotePlayTogetherGuestInvite`

Function Reference
------------------

.. function:: RemotePlay.BEnableRemotePlayTogetherDirectInput()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BEnableRemotePlayTogetherDirectInput <https://partner.steamgames.com/doc/api/ISteamRemotePlay#BEnableRemotePlayTogetherDirectInput>`_

.. function:: RemotePlay.BGetSessionClientResolution(unSessionID)

    🤖 **Auto-generated binding**

    :param int unSessionID:
    :returns: (bool) Return value
    :returns: (int) ``pnResolutionX``
    :returns: (int) ``pnResolutionY``
    :SteamWorks: `BGetSessionClientResolution <https://partner.steamgames.com/doc/api/ISteamRemotePlay#BGetSessionClientResolution>`_

    **Signature differences from C++ API:**

    * Parameter ``pnResolutionX`` is no longer a parameter, and is instead an additional return value
    * Parameter ``pnResolutionY`` is no longer a parameter, and is instead an additional return value

.. function:: RemotePlay.BSendRemotePlayTogetherInvite(steamIDFriend)

    🤖 **Auto-generated binding**

    :param uint64 steamIDFriend:
    :returns: (bool) Return value
    :SteamWorks: `BSendRemotePlayTogetherInvite <https://partner.steamgames.com/doc/api/ISteamRemotePlay#BSendRemotePlayTogetherInvite>`_

**Example**::

    if Steam.RemotePlay.BSendRemotePlayTogetherInvite(friendSteamID) then
        print('Remote Play Together invite sent')
    end

.. function:: RemotePlay.CreateMouseCursor(nWidth, nHeight, nHotX, nHotY, pBGRA, nPitch)

    🤖 **Auto-generated binding**

    :param int nWidth:
    :param int nHeight:
    :param int nHotX:
    :param int nHotY:
    :param str? pBGRA:
    :param int nPitch:
    :returns: (int) Return value
    :SteamWorks: `CreateMouseCursor <https://partner.steamgames.com/doc/api/ISteamRemotePlay#CreateMouseCursor>`_

.. function:: RemotePlay.DisableRemotePlayTogetherDirectInput()

    🤖 **Auto-generated binding**

    :SteamWorks: `DisableRemotePlayTogetherDirectInput <https://partner.steamgames.com/doc/api/ISteamRemotePlay#DisableRemotePlayTogetherDirectInput>`_

.. function:: RemotePlay.GetInput(unMaxEvents)

    🤖 **Auto-generated binding**

    :param int? unMaxEvents: size of the buffer to allocate for ``pInput``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (int) Return value
    :returns: (:ref:`RemotePlayInput_t <struct-RemotePlayInput_t>`\ []) ``pInput``
    :SteamWorks: `GetInput <https://partner.steamgames.com/doc/api/ISteamRemotePlay#GetInput>`_

    **Signature differences from C++ API:**

    * Parameter ``pInput`` is no longer a parameter, and is instead an additional return value

.. function:: RemotePlay.GetSessionClientFormFactor(unSessionID)

    🤖 **Auto-generated binding**

    :param int unSessionID:
    :returns: (int) Return value
    :SteamWorks: `GetSessionClientFormFactor <https://partner.steamgames.com/doc/api/ISteamRemotePlay#GetSessionClientFormFactor>`_

**Example**::

    local formFactor = Steam.RemotePlay.GetSessionClientFormFactor(sessionID)
    if formFactor == Steam.k_ESteamDeviceFormFactor_Phone then
        print('Client is on a mobile device')
    end

.. function:: RemotePlay.GetSessionClientName(unSessionID)

    🤖 **Auto-generated binding**

    :param int unSessionID:
    :returns: (str) Return value
    :SteamWorks: `GetSessionClientName <https://partner.steamgames.com/doc/api/ISteamRemotePlay#GetSessionClientName>`_

    **Notes:**

    * See :func:`RemotePlay.GetSessionID`'s example.

.. function:: RemotePlay.GetSessionCount()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetSessionCount <https://partner.steamgames.com/doc/api/ISteamRemotePlay#GetSessionCount>`_

**Example**::

    local count = Steam.RemotePlay.GetSessionCount()
    print('Active Remote Play sessions:', count)

.. function:: RemotePlay.GetSessionID(iSessionIndex)

    🤖 **Auto-generated binding**

    :param int iSessionIndex:
    :returns: (int) Return value
    :SteamWorks: `GetSessionID <https://partner.steamgames.com/doc/api/ISteamRemotePlay#GetSessionID>`_

**Example**::

    local count = Steam.RemotePlay.GetSessionCount()
    for i = 0, count - 1 do
        local sessionID = Steam.RemotePlay.GetSessionID(i)
        local name = Steam.RemotePlay.GetSessionClientName(sessionID)
        print('Remote Play client:', name)
    end

.. function:: RemotePlay.GetSessionSteamID(unSessionID)

    🤖 **Auto-generated binding**

    :param int unSessionID:
    :returns: (uint64) Return value
    :SteamWorks: `GetSessionSteamID <https://partner.steamgames.com/doc/api/ISteamRemotePlay#GetSessionSteamID>`_

**Example**::

    local steamID = Steam.RemotePlay.GetSessionSteamID(sessionID)
    print('Remote player:', Steam.Friends.GetFriendPersonaName(steamID))

.. function:: RemotePlay.SetMouseCursor(unSessionID, unCursorID)

    🤖 **Auto-generated binding**

    :param int unSessionID:
    :param int unCursorID:
    :SteamWorks: `SetMouseCursor <https://partner.steamgames.com/doc/api/ISteamRemotePlay#SetMouseCursor>`_

.. function:: RemotePlay.SetMousePosition(unSessionID, flNormalizedX, flNormalizedY)

    🤖 **Auto-generated binding**

    :param int unSessionID:
    :param float flNormalizedX:
    :param float flNormalizedY:
    :SteamWorks: `SetMousePosition <https://partner.steamgames.com/doc/api/ISteamRemotePlay#SetMousePosition>`_

.. function:: RemotePlay.SetMouseVisibility(unSessionID, bVisible)

    🤖 **Auto-generated binding**

    :param int unSessionID:
    :param bool bVisible:
    :SteamWorks: `SetMouseVisibility <https://partner.steamgames.com/doc/api/ISteamRemotePlay#SetMouseVisibility>`_

.. function:: RemotePlay.ShowRemotePlayTogetherUI()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `ShowRemotePlayTogetherUI <https://partner.steamgames.com/doc/api/ISteamRemotePlay#ShowRemotePlayTogetherUI>`_


Callbacks
---------

.. function:: RemotePlay.OnSteamRemotePlaySessionConnected

    Callback for `SteamRemotePlaySessionConnected_t <https://partner.steamgames.com/doc/api/ISteamRemotePlay#SteamRemotePlaySessionConnected_t>`_

    **callback(data)** receives:

    * **data.m_unSessionID** *(RemotePlaySessionID_t)*

**Example**::

    function Steam.RemotePlay.OnSteamRemotePlaySessionConnected(data)
        local name = Steam.RemotePlay.GetSessionClientName(data.m_unSessionID)
        print('Remote Play session connected:', name)
    end

.. function:: RemotePlay.OnSteamRemotePlaySessionDisconnected

    Callback for `SteamRemotePlaySessionDisconnected_t <https://partner.steamgames.com/doc/api/ISteamRemotePlay#SteamRemotePlaySessionDisconnected_t>`_

    **callback(data)** receives:

    * **data.m_unSessionID** *(RemotePlaySessionID_t)*

**Example**::

    function Steam.RemotePlay.OnSteamRemotePlaySessionDisconnected(data)
        print('Remote Play session disconnected:', data.m_unSessionID)
    end

.. function:: RemotePlay.OnSteamRemotePlayTogetherGuestInvite

    Callback for `SteamRemotePlayTogetherGuestInvite_t <https://partner.steamgames.com/doc/api/ISteamRemotePlay#SteamRemotePlayTogetherGuestInvite_t>`_

    **callback(data)** receives:

    * **data.m_szConnectURL** *(string)*

