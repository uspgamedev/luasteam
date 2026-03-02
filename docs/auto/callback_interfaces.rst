====================
Callback Interfaces
====================

.. note::
   These are pure-virtual C++ interfaces that you implement in Lua by providing
   a table of callback functions to the constructor.

**Example** — browsing LAN servers with :func:`MatchmakingServers.RequestLANServerList`:

.. code-block:: lua

    local response_iface = Steam.newISteamMatchmakingServerListResponse {
        ServerResponded = function(hRequest, iServer)
            local info = Steam.MatchmakingServers.GetServerDetails(hRequest, iServer)
            print('Found server:', info.m_szServerName, info.m_nPlayers .. '/' .. info.m_nMaxPlayers)
        end,
        ServerFailedToRespond = function(hRequest, iServer) end,
        RefreshComplete = function(hRequest, response)
            print('Server list refresh complete, response:', response)
        end,
    )
    local hRequest = Steam.MatchmakingServers.RequestLANServerList(Steam.Utils.GetAppID(), response_iface)

.. _struct-ISteamMatchmakingServerListResponse:

-----------------------------------
ISteamMatchmakingServerListResponse
-----------------------------------

.. function:: Steam.newISteamMatchmakingServerListResponse(callbacks)

    🤖 Constructor — creates a new callback interface userdata.

    :param table callbacks: Table of callback functions:

        * **ServerResponded** ``function(hRequest: HServerListRequest, iServer: int)``
        * **ServerFailedToRespond** ``function(hRequest: HServerListRequest, iServer: int)``
        * **RefreshComplete** ``function(hRequest: HServerListRequest, response: int)``

    :returns: (ISteamMatchmakingServerListResponse) New callback interface userdata.

.. _struct-ISteamMatchmakingPingResponse:

-----------------------------
ISteamMatchmakingPingResponse
-----------------------------

.. function:: Steam.newISteamMatchmakingPingResponse(callbacks)

    🤖 Constructor — creates a new callback interface userdata.

    :param table callbacks: Table of callback functions:

        * **ServerResponded** ``function(server: gameserveritem_t)``
        * **ServerFailedToRespond** ``function()``

    :returns: (ISteamMatchmakingPingResponse) New callback interface userdata.

.. _struct-ISteamMatchmakingPlayersResponse:

--------------------------------
ISteamMatchmakingPlayersResponse
--------------------------------

.. function:: Steam.newISteamMatchmakingPlayersResponse(callbacks)

    🤖 Constructor — creates a new callback interface userdata.

    :param table callbacks: Table of callback functions:

        * **AddPlayerToList** ``function(pchName: str, nScore: int, flTimePlayed: float)``
        * **PlayersFailedToRespond** ``function()``
        * **PlayersRefreshComplete** ``function()``

    :returns: (ISteamMatchmakingPlayersResponse) New callback interface userdata.

.. _struct-ISteamMatchmakingRulesResponse:

------------------------------
ISteamMatchmakingRulesResponse
------------------------------

.. function:: Steam.newISteamMatchmakingRulesResponse(callbacks)

    🤖 Constructor — creates a new callback interface userdata.

    :param table callbacks: Table of callback functions:

        * **RulesResponded** ``function(pchRule: str, pchValue: str)``
        * **RulesFailedToRespond** ``function()``
        * **RulesRefreshComplete** ``function()``

    :returns: (ISteamMatchmakingRulesResponse) New callback interface userdata.

