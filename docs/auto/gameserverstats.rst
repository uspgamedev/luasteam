#####################
ISteamGameServerStats
#####################

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✋ require manual implementation.

List of Functions
-----------------

* :func:`GameServerStats.RequestUserStats`
* :func:`GameServerStats.GetUserStatInt32`
* :func:`GameServerStats.GetUserStatFloat`
* :func:`GameServerStats.GetUserAchievement`
* :func:`GameServerStats.SetUserStatInt32`
* :func:`GameServerStats.SetUserStatFloat`
* :func:`GameServerStats.UpdateUserAvgRateStat`
* :func:`GameServerStats.SetUserAchievement`
* :func:`GameServerStats.ClearUserAchievement`
* :func:`GameServerStats.StoreUserStats`

List of Callbacks
-----------------

* :func:`GameServerStats.onGSStatsReceived`
* :func:`GameServerStats.onGSStatsStored`

Function Reference
------------------

.. function:: GameServerStats.RequestUserStats(steamIDUser, callback)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param function callback: CallResult callback receiving struct `GSStatsReceived_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `RequestUserStats <https://partner.steamgames.com/doc/api/ISteamGameServerStats#RequestUserStats>`_

.. function:: GameServerStats.GetUserStatInt32(steamIDUser, pchName)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param str pchName:
    :returns: (bool) Return value
    :returns: (int) Value for `pData`
    :SteamWorks: `GetUserStatInt32 <https://partner.steamgames.com/doc/api/ISteamGameServerStats#GetUserStatInt32>`_

    **Signature differences from C++ API:**

    * Parameter ``pData`` is returned as an additional return value

.. function:: GameServerStats.GetUserStatFloat(steamIDUser, pchName)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param str pchName:
    :returns: (bool) Return value
    :returns: (float) Value for `pData`
    :SteamWorks: `GetUserStatFloat <https://partner.steamgames.com/doc/api/ISteamGameServerStats#GetUserStatFloat>`_

    **Signature differences from C++ API:**

    * Parameter ``pData`` is returned as an additional return value

.. function:: GameServerStats.GetUserAchievement(steamIDUser, pchName)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param str pchName:
    :returns: (bool) Return value
    :returns: (bool) Value for `pbAchieved`
    :SteamWorks: `GetUserAchievement <https://partner.steamgames.com/doc/api/ISteamGameServerStats#GetUserAchievement>`_

    **Signature differences from C++ API:**

    * Parameter ``pbAchieved`` is returned as an additional return value

.. function:: GameServerStats.SetUserStatInt32(steamIDUser, pchName, nData)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param str pchName:
    :param int nData:
    :returns: (bool) Return value
    :SteamWorks: `SetUserStatInt32 <https://partner.steamgames.com/doc/api/ISteamGameServerStats#SetUserStatInt32>`_

.. function:: GameServerStats.SetUserStatFloat(steamIDUser, pchName, fData)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param str pchName:
    :param float fData:
    :returns: (bool) Return value
    :SteamWorks: `SetUserStatFloat <https://partner.steamgames.com/doc/api/ISteamGameServerStats#SetUserStatFloat>`_

.. function:: GameServerStats.UpdateUserAvgRateStat(steamIDUser, pchName, flCountThisSession, dSessionLength)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param str pchName:
    :param float flCountThisSession:
    :param float dSessionLength:
    :returns: (bool) Return value
    :SteamWorks: `UpdateUserAvgRateStat <https://partner.steamgames.com/doc/api/ISteamGameServerStats#UpdateUserAvgRateStat>`_

.. function:: GameServerStats.SetUserAchievement(steamIDUser, pchName)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param str pchName:
    :returns: (bool) Return value
    :SteamWorks: `SetUserAchievement <https://partner.steamgames.com/doc/api/ISteamGameServerStats#SetUserAchievement>`_

.. function:: GameServerStats.ClearUserAchievement(steamIDUser, pchName)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param str pchName:
    :returns: (bool) Return value
    :SteamWorks: `ClearUserAchievement <https://partner.steamgames.com/doc/api/ISteamGameServerStats#ClearUserAchievement>`_

.. function:: GameServerStats.StoreUserStats(steamIDUser, callback)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param function callback: CallResult callback receiving struct `GSStatsStored_t` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `StoreUserStats <https://partner.steamgames.com/doc/api/ISteamGameServerStats#StoreUserStats>`_


Callbacks
---------

.. function:: GameServerStats.onGSStatsReceived

    Callback for `GSStatsReceived_t <https://partner.steamgames.com/doc/api/steam_api#GSStatsReceived_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_steamIDUser** -- m_steamIDUser

.. function:: GameServerStats.onGSStatsStored

    Callback for `GSStatsStored_t <https://partner.steamgames.com/doc/api/steam_api#GSStatsStored_t>`_

    **callback(data)** receives:

    * **data.m_eResult** -- m_eResult
    * **data.m_steamIDUser** -- m_steamIDUser

