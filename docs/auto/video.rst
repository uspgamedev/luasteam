###########
ISteamVideo
###########

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✍️ are manually implemented and methods marked with ✋ are currently not implemented.

List of Functions
-----------------

* :func:`Video.GetOPFSettings`
* :func:`Video.GetOPFStringForApp`
* :func:`Video.GetVideoURL`
* :func:`Video.IsBroadcasting`

List of Callbacks
-----------------

* :func:`Video.OnGetVideoURLResult`
* :func:`Video.OnGetOPFSettingsResult`
* :func:`Video.OnBroadcastUploadStart`
* :func:`Video.OnBroadcastUploadStop`

Function Reference
------------------

.. function:: Video.GetOPFSettings(unVideoAppID)

    🤖 **Auto-generated binding**

    :param int - AppId_t unVideoAppID:
    :SteamWorks: `GetOPFSettings <https://partner.steamgames.com/doc/api/ISteamVideo#GetOPFSettings>`_

.. function:: Video.GetOPFStringForApp(unVideoAppID, pnBufferSize)

    🤖 **Auto-generated binding**

    :param int - AppId_t unVideoAppID:
    :param int? pnBufferSize: size of the buffer to allocate for ``pchBuffer``. If ``nil`` then the buffer will be ``NULL``.
    :returns: (bool) Return value
    :returns: (str) ``pchBuffer``
    :returns: (int) ``pnBufferSize``
    :SteamWorks: `GetOPFStringForApp <https://partner.steamgames.com/doc/api/ISteamVideo#GetOPFStringForApp>`_

    **Signature differences from C++ API:**

    * Parameter ``pchBuffer`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.
    * Parameter ``pnBufferSize`` is both an input and an output in C++: you pass the buffer size, and Steam writes the actual count back. luasteam returns it as an additional return value.

.. function:: Video.GetVideoURL(unVideoAppID)

    🤖 **Auto-generated binding**

    :param int - AppId_t unVideoAppID:
    :SteamWorks: `GetVideoURL <https://partner.steamgames.com/doc/api/ISteamVideo#GetVideoURL>`_

**Example**::

    Steam.Video.GetVideoURL(videoAppID)
    -- Wait for OnGetVideoURLResult callback

.. function:: Video.IsBroadcasting()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :returns: (int) ``pnNumViewers``
    :SteamWorks: `IsBroadcasting <https://partner.steamgames.com/doc/api/ISteamVideo#IsBroadcasting>`_

    **Signature differences from C++ API:**

    * Parameter ``pnNumViewers`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    local broadcasting, viewers = Steam.Video.IsBroadcasting()
    if broadcasting then
        print('Broadcasting to', viewers, 'viewers')
    end


Callbacks
---------

.. function:: Video.OnGetVideoURLResult

    Callback for `GetVideoURLResult_t <https://partner.steamgames.com/doc/api/ISteamVideo#GetVideoURLResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(int - EResult)*
    * **data.m_unVideoAppID** *(int - AppId_t)*
    * **data.m_rgchURL** *(string)*

**Example**::

    function Steam.Video.OnGetVideoURLResult(data)
        if data.m_eResult == Steam.k_EResultOK then
            print('Video URL:', data.m_rgchURL)
            openVideoPlayer(data.m_rgchURL)
        end
    end

.. function:: Video.OnGetOPFSettingsResult

    Callback for `GetOPFSettingsResult_t <https://partner.steamgames.com/doc/api/ISteamVideo#GetOPFSettingsResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(int - EResult)*
    * **data.m_unVideoAppID** *(int - AppId_t)*

.. function:: Video.OnBroadcastUploadStart

    Callback for `BroadcastUploadStart_t <https://partner.steamgames.com/doc/api/ISteamVideo#BroadcastUploadStart_t>`_

    **callback(data)** receives:

    * **data.m_bIsRTMP** *(bool)*

**Example**::

    function Steam.Video.OnBroadcastUploadStart()
        print('Broadcast started')
    end

.. function:: Video.OnBroadcastUploadStop

    Callback for `BroadcastUploadStop_t <https://partner.steamgames.com/doc/api/ISteamVideo#BroadcastUploadStop_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(int - EBroadcastUploadResult)*

