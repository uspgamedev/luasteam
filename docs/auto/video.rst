###########
ISteamVideo
###########

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✋ require manual implementation.

List of Functions
-----------------

* :func:`Video.GetVideoURL`
* :func:`Video.IsBroadcasting`
* :func:`Video.GetOPFSettings`
* :func:`Video.GetOPFStringForApp`

List of Callbacks
-----------------

* :func:`Video.onGetVideoURLResult`
* :func:`Video.onGetOPFSettingsResult`
* :func:`Video.onBroadcastUploadStart`
* :func:`Video.onBroadcastUploadStop`

Function Reference
------------------

.. function:: Video.GetVideoURL(unVideoAppID)

    🤖 **Auto-generated binding**

    :param int unVideoAppID:
    :SteamWorks: `GetVideoURL <https://partner.steamgames.com/doc/api/ISteamVideo#GetVideoURL>`_

.. function:: Video.IsBroadcasting()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :returns: (int) Value for `pnNumViewers`
    :SteamWorks: `IsBroadcasting <https://partner.steamgames.com/doc/api/ISteamVideo#IsBroadcasting>`_

    **Signature differences from C++ API:**

    * Parameter ``pnNumViewers`` is returned as an additional return value

.. function:: Video.GetOPFSettings(unVideoAppID)

    🤖 **Auto-generated binding**

    :param int unVideoAppID:
    :SteamWorks: `GetOPFSettings <https://partner.steamgames.com/doc/api/ISteamVideo#GetOPFSettings>`_

.. function:: Video.GetOPFStringForApp(unVideoAppID, pnBufferSize)

    🤖 **Auto-generated binding**

    :param int unVideoAppID:
    :param int pnBufferSize:
    :returns: (bool) Return value
    :returns: (int) Value for `pnBufferSize`
    :returns: (str) Value for `pchBuffer`
    :returns: (int) Value for `pnBufferSize`
    :SteamWorks: `GetOPFStringForApp <https://partner.steamgames.com/doc/api/ISteamVideo#GetOPFStringForApp>`_

    **Signature differences from C++ API:**

    * Parameter ``pnBufferSize`` is returned as an additional return value
    * Parameter ``pchBuffer`` is returned as an additional return value
    * Parameter ``pnBufferSize`` is returned as an additional return value


Callbacks
---------

.. function:: Video.onGetVideoURLResult

    Callback for `GetVideoURLResult_t <https://partner.steamgames.com/doc/api/steam_api#GetVideoURLResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_unVideoAppID** -- m_unVideoAppID
    * **data.m_rgchURL** -- m_rgchURL

.. function:: Video.onGetOPFSettingsResult

    Callback for `GetOPFSettingsResult_t <https://partner.steamgames.com/doc/api/steam_api#GetOPFSettingsResult_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_unVideoAppID** -- m_unVideoAppID

.. function:: Video.onBroadcastUploadStart

    Callback for `BroadcastUploadStart_t <https://partner.steamgames.com/doc/api/steam_api#BroadcastUploadStart_t>`_

    **callback(data)** receives:

    * **data.m_bIsRTMP** -- m_bIsRTMP

.. function:: Video.onBroadcastUploadStop

    Callback for `BroadcastUploadStop_t <https://partner.steamgames.com/doc/api/steam_api#BroadcastUploadStop_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult

