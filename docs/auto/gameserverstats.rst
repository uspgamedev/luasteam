#####################
ISteamGameServerStats
#####################

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✍️ are manually implemented and methods marked with ✋ are currently not implemented.

.. note::
   Overloaded Steam methods are exposed as distinct Lua functions using a type suffix (for example ``GetStatInt32`` and ``SetStatFloat``).

List of Functions
-----------------

* :func:`GameServerStats.ClearUserAchievement`
* :func:`GameServerStats.GetUserAchievement`
* :func:`GameServerStats.GetUserStatFloat`
* :func:`GameServerStats.GetUserStatInt32`
* :func:`GameServerStats.RequestUserStats`
* :func:`GameServerStats.SetUserAchievement`
* :func:`GameServerStats.SetUserStatFloat`
* :func:`GameServerStats.SetUserStatInt32`
* :func:`GameServerStats.StoreUserStats`
* :func:`GameServerStats.UpdateUserAvgRateStat`

List of Callbacks
-----------------

* :func:`GameServerStats.OnGSStatsReceived`
* :func:`GameServerStats.OnGSStatsStored`

Function Reference
------------------

.. function:: GameServerStats.ClearUserAchievement(steamIDUser, pchName)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param str? pchName:
    :returns: (bool) Return value
    :SteamWorks: `ClearUserAchievement <https://partner.steamgames.com/doc/api/ISteamGameServerStats#ClearUserAchievement>`_

.. function:: GameServerStats.GetUserAchievement(steamIDUser, pchName)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param str? pchName:
    :returns: (bool) Return value
    :returns: (bool) ``pbAchieved``
    :SteamWorks: `GetUserAchievement <https://partner.steamgames.com/doc/api/ISteamGameServerStats#GetUserAchievement>`_

    **Signature differences from C++ API:**

    * Parameter ``pbAchieved`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    local ok, achieved = Steam.GameServerStats.GetUserAchievement(playerSteamID, 'first_blood')
    if ok and not achieved then
        Steam.GameServerStats.SetUserAchievement(playerSteamID, 'first_blood')
    end

.. function:: GameServerStats.GetUserStatFloat(steamIDUser, pchName)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param str? pchName:
    :returns: (bool) Return value
    :returns: (float) ``pData``
    :SteamWorks: `GetUserStat <https://partner.steamgames.com/doc/api/ISteamGameServerStats#GetUserStat>`_

    **Signature differences from C++ API:**

    * In C++, this is an overloaded method called ``GetUserStat``. luasteam exposes each overload as a distinct function with a type suffix.
    * Parameter ``pData`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

.. function:: GameServerStats.GetUserStatInt32(steamIDUser, pchName)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param str? pchName:
    :returns: (bool) Return value
    :returns: (int) ``pData``
    :SteamWorks: `GetUserStat <https://partner.steamgames.com/doc/api/ISteamGameServerStats#GetUserStat>`_

    **Signature differences from C++ API:**

    * In C++, this is an overloaded method called ``GetUserStat``. luasteam exposes each overload as a distinct function with a type suffix.
    * Parameter ``pData`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    local ok, value = Steam.GameServerStats.GetUserStatInt32(playerSteamID, 'kills')
    if ok then
        print('Kills:', value)
    end

.. function:: GameServerStats.RequestUserStats(steamIDUser, callback)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param function callback: CallResult callback receiving struct :func:`GSStatsReceived_t <GameServerStats.OnGSStatsReceived>` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `RequestUserStats <https://partner.steamgames.com/doc/api/ISteamGameServerStats#RequestUserStats>`_

**Example**::

    Steam.GameServerStats.RequestUserStats(playerSteamID, function(data, err)
        if not err and data.m_eResult == Steam.k_EResultOK then
            local ok, kills = Steam.GameServerStats.GetUserStatInt32(playerSteamID, 'kills')
            print('Player kills:', kills)
        end
    end)

.. function:: GameServerStats.SetUserAchievement(steamIDUser, pchName)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param str? pchName:
    :returns: (bool) Return value
    :SteamWorks: `SetUserAchievement <https://partner.steamgames.com/doc/api/ISteamGameServerStats#SetUserAchievement>`_

.. function:: GameServerStats.SetUserStatFloat(steamIDUser, pchName, fData)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param str? pchName:
    :param float fData:
    :returns: (bool) Return value
    :SteamWorks: `SetUserStat <https://partner.steamgames.com/doc/api/ISteamGameServerStats#SetUserStat>`_

    **Signature differences from C++ API:**

    * In C++, this is an overloaded method called ``SetUserStat``. luasteam exposes each overload as a distinct function with a type suffix.

.. function:: GameServerStats.SetUserStatInt32(steamIDUser, pchName, nData)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param str? pchName:
    :param int nData:
    :returns: (bool) Return value
    :SteamWorks: `SetUserStat <https://partner.steamgames.com/doc/api/ISteamGameServerStats#SetUserStat>`_

    **Signature differences from C++ API:**

    * In C++, this is an overloaded method called ``SetUserStat``. luasteam exposes each overload as a distinct function with a type suffix.

**Example**::

    Steam.GameServerStats.SetUserStatInt32(playerSteamID, 'kills', newKillCount)
    Steam.GameServerStats.StoreUserStats(playerSteamID, function(data, err) end)

.. function:: GameServerStats.StoreUserStats(steamIDUser, callback)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param function callback: CallResult callback receiving struct :func:`GSStatsStored_t <GameServerStats.OnGSStatsStored>` and a boolean
    :returns: (uint64) Return value
    :SteamWorks: `StoreUserStats <https://partner.steamgames.com/doc/api/ISteamGameServerStats#StoreUserStats>`_

**Example**::

    Steam.GameServerStats.StoreUserStats(playerSteamID, function(data, err)
        if not err and data.m_eResult == Steam.k_EResultOK then
            print('Stats saved for player:', tostring(data.m_steamIDUser))
        end
    end)

.. function:: GameServerStats.UpdateUserAvgRateStat(steamIDUser, pchName, flCountThisSession, dSessionLength)

    🤖 **Auto-generated binding**

    :param uint64 steamIDUser:
    :param str? pchName:
    :param float flCountThisSession:
    :param float dSessionLength:
    :returns: (bool) Return value
    :SteamWorks: `UpdateUserAvgRateStat <https://partner.steamgames.com/doc/api/ISteamGameServerStats#UpdateUserAvgRateStat>`_


Callbacks
---------

.. function:: GameServerStats.OnGSStatsReceived

    Callback for `GSStatsReceived_t <https://partner.steamgames.com/doc/api/ISteamGameServerStats#GSStatsReceived_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(EResult)*
    * **data.m_steamIDUser** *(uint64)*

.. function:: GameServerStats.OnGSStatsStored

    Callback for `GSStatsStored_t <https://partner.steamgames.com/doc/api/ISteamGameServerStats#GSStatsStored_t>`_

    **callback(data)** receives:

    * **data.m_eResult** *(EResult)*
    * **data.m_steamIDUser** *(uint64)*

