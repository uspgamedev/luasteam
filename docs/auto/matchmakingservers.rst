########################
ISteamMatchmakingServers
########################

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✍️ are manually implemented and methods marked with ✋ are currently not implemented.

List of Functions
-----------------

* :func:`MatchmakingServers.CancelQuery`
* :func:`MatchmakingServers.CancelServerQuery`
* :func:`MatchmakingServers.GetServerCount`
* :func:`MatchmakingServers.IsRefreshing`
* :func:`MatchmakingServers.PingServer`
* :func:`MatchmakingServers.PlayerDetails`
* :func:`MatchmakingServers.RefreshQuery`
* :func:`MatchmakingServers.RefreshServer`
* :func:`MatchmakingServers.ReleaseRequest`
* :func:`MatchmakingServers.RequestFavoritesServerList`
* :func:`MatchmakingServers.RequestFriendsServerList`
* :func:`MatchmakingServers.RequestHistoryServerList`
* :func:`MatchmakingServers.RequestInternetServerList`
* :func:`MatchmakingServers.RequestLANServerList`
* :func:`MatchmakingServers.RequestSpectatorServerList`
* :func:`MatchmakingServers.ServerRules`

Function Reference
------------------

.. function:: MatchmakingServers.CancelQuery(hRequest)

    🤖 **Auto-generated binding**

    :param HServerListRequest hRequest:
    :SteamWorks: `CancelQuery <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#CancelQuery>`_

**Example**::

    Steam.MatchmakingServers.CancelQuery(serverListRequest)

.. function:: MatchmakingServers.CancelServerQuery(hServerQuery)

    🤖 **Auto-generated binding**

    :param int hServerQuery: ``HServerQuery``
    :SteamWorks: `CancelServerQuery <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#CancelServerQuery>`_

.. function:: MatchmakingServers.GetServerCount(hRequest)

    🤖 **Auto-generated binding**

    :param HServerListRequest hRequest:
    :returns: (int) Return value
    :SteamWorks: `GetServerCount <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#GetServerCount>`_

**Example**::

    local count = Steam.MatchmakingServers.GetServerCount(serverListRequest)
    print('Found', count, 'servers')

.. function:: MatchmakingServers.IsRefreshing(hRequest)

    🤖 **Auto-generated binding**

    :param HServerListRequest hRequest:
    :returns: (bool) Return value
    :SteamWorks: `IsRefreshing <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#IsRefreshing>`_

**Example**::

    if Steam.MatchmakingServers.IsRefreshing(serverListRequest) then
        showLoadingSpinner()
    end

.. function:: MatchmakingServers.PingServer(unIP, usPort, pRequestServersResponse)

    🤖 **Auto-generated binding**

    :param int unIP:
    :param int usPort:
    :param pRequestServersResponse: (:ref:`ISteamMatchmakingPingResponse <struct-ISteamMatchmakingPingResponse>`)
    :returns: (int) ``HServerQuery``
    :SteamWorks: `PingServer <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#PingServer>`_

**Example**::

    local pingCallbacks = Steam.newISteamMatchmakingPingResponse {
        ServerResponded = function(server)
            print('Server:', server.m_szServerName, 'Ping:', server.m_nPing)
        end,
        ServerFailedToRespond = function()
            print('Server did not respond to ping')
        end,
    }
    Steam.MatchmakingServers.PingServer(serverIP, serverPort, pingCallbacks)

.. function:: MatchmakingServers.PlayerDetails(unIP, usPort, pRequestServersResponse)

    🤖 **Auto-generated binding**

    :param int unIP:
    :param int usPort:
    :param pRequestServersResponse: (:ref:`ISteamMatchmakingPlayersResponse <struct-ISteamMatchmakingPlayersResponse>`)
    :returns: (int) ``HServerQuery``
    :SteamWorks: `PlayerDetails <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#PlayerDetails>`_

.. function:: MatchmakingServers.RefreshQuery(hRequest)

    🤖 **Auto-generated binding**

    :param HServerListRequest hRequest:
    :SteamWorks: `RefreshQuery <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#RefreshQuery>`_

**Example**::

    Steam.MatchmakingServers.RefreshQuery(serverListRequest)

.. function:: MatchmakingServers.RefreshServer(hRequest, iServer)

    🤖 **Auto-generated binding**

    :param HServerListRequest hRequest:
    :param int iServer:
    :SteamWorks: `RefreshServer <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#RefreshServer>`_

.. function:: MatchmakingServers.ReleaseRequest(hServerListRequest)

    🤖 **Auto-generated binding**

    :param HServerListRequest hServerListRequest:
    :SteamWorks: `ReleaseRequest <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#ReleaseRequest>`_

**Example**::

    Steam.MatchmakingServers.ReleaseRequest(serverListRequest)
    serverListRequest = nil

.. function:: MatchmakingServers.RequestFavoritesServerList(iApp, ppchFilters, nFilters, pRequestServersResponse)

    🤖 **Auto-generated binding**

    :param int iApp: ``AppId_t``
    :param ppchFilters: (:ref:`MatchMakingKeyValuePair_t <struct-MatchMakingKeyValuePair_t>`\ [])
    :param int nFilters: size of the input array ``ppchFilters``
    :param pRequestServersResponse: (:ref:`ISteamMatchmakingServerListResponse <struct-ISteamMatchmakingServerListResponse>`)
    :returns: (HServerListRequest) Return value
    :SteamWorks: `RequestFavoritesServerList <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#RequestFavoritesServerList>`_

.. function:: MatchmakingServers.RequestFriendsServerList(iApp, ppchFilters, nFilters, pRequestServersResponse)

    🤖 **Auto-generated binding**

    :param int iApp: ``AppId_t``
    :param ppchFilters: (:ref:`MatchMakingKeyValuePair_t <struct-MatchMakingKeyValuePair_t>`\ [])
    :param int nFilters: size of the input array ``ppchFilters``
    :param pRequestServersResponse: (:ref:`ISteamMatchmakingServerListResponse <struct-ISteamMatchmakingServerListResponse>`)
    :returns: (HServerListRequest) Return value
    :SteamWorks: `RequestFriendsServerList <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#RequestFriendsServerList>`_

**Example**::

    local callbacks = Steam.newISteamMatchmakingServerListResponse {
        ServerResponded = function(req, idx)
            local info = Steam.MatchmakingServers.getServerDetails(req, idx)
            print('Friend server:', info.m_szServerName)
        end,
        RefreshComplete = function(req, resp)
            Steam.MatchmakingServers.ReleaseRequest(req)
        end,
    }
    local req = Steam.MatchmakingServers.RequestFriendsServerList(appID, {}, 0, callbacks)

.. function:: MatchmakingServers.RequestHistoryServerList(iApp, ppchFilters, nFilters, pRequestServersResponse)

    🤖 **Auto-generated binding**

    :param int iApp: ``AppId_t``
    :param ppchFilters: (:ref:`MatchMakingKeyValuePair_t <struct-MatchMakingKeyValuePair_t>`\ [])
    :param int nFilters: size of the input array ``ppchFilters``
    :param pRequestServersResponse: (:ref:`ISteamMatchmakingServerListResponse <struct-ISteamMatchmakingServerListResponse>`)
    :returns: (HServerListRequest) Return value
    :SteamWorks: `RequestHistoryServerList <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#RequestHistoryServerList>`_

.. function:: MatchmakingServers.RequestInternetServerList(iApp, ppchFilters, nFilters, pRequestServersResponse)

    🤖 **Auto-generated binding**

    :param int iApp: ``AppId_t``
    :param ppchFilters: (:ref:`MatchMakingKeyValuePair_t <struct-MatchMakingKeyValuePair_t>`\ [])
    :param int nFilters: size of the input array ``ppchFilters``
    :param pRequestServersResponse: (:ref:`ISteamMatchmakingServerListResponse <struct-ISteamMatchmakingServerListResponse>`)
    :returns: (HServerListRequest) Return value
    :SteamWorks: `RequestInternetServerList <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#RequestInternetServerList>`_

**Example**::

    local filters = {{'gamedir', 'mygame'}, {'map', 'de_dust2'}}
    local callbacks = Steam.newISteamMatchmakingServerListResponse {
        ServerResponded = function(request, index)
            local info = Steam.MatchmakingServers.getServerDetails(request, index)
            print(info.m_szServerName .. ' - ' .. info.m_nPlayers .. '/' .. info.m_nMaxPlayers)
        end,
        RefreshComplete = function(request, response)
            print('Server list refresh complete')
            Steam.MatchmakingServers.ReleaseRequest(request)
        end,
    }
    local request = Steam.MatchmakingServers.RequestInternetServerList(appID, filters, #filters, callbacks)

.. function:: MatchmakingServers.RequestLANServerList(iApp, pRequestServersResponse)

    🤖 **Auto-generated binding**

    :param int iApp: ``AppId_t``
    :param pRequestServersResponse: (:ref:`ISteamMatchmakingServerListResponse <struct-ISteamMatchmakingServerListResponse>`)
    :returns: (HServerListRequest) Return value
    :SteamWorks: `RequestLANServerList <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#RequestLANServerList>`_

.. function:: MatchmakingServers.RequestSpectatorServerList(iApp, ppchFilters, nFilters, pRequestServersResponse)

    🤖 **Auto-generated binding**

    :param int iApp: ``AppId_t``
    :param ppchFilters: (:ref:`MatchMakingKeyValuePair_t <struct-MatchMakingKeyValuePair_t>`\ [])
    :param int nFilters: size of the input array ``ppchFilters``
    :param pRequestServersResponse: (:ref:`ISteamMatchmakingServerListResponse <struct-ISteamMatchmakingServerListResponse>`)
    :returns: (HServerListRequest) Return value
    :SteamWorks: `RequestSpectatorServerList <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#RequestSpectatorServerList>`_

.. function:: MatchmakingServers.ServerRules(unIP, usPort, pRequestServersResponse)

    🤖 **Auto-generated binding**

    :param int unIP:
    :param int usPort:
    :param pRequestServersResponse: (:ref:`ISteamMatchmakingRulesResponse <struct-ISteamMatchmakingRulesResponse>`)
    :returns: (int) ``HServerQuery``
    :SteamWorks: `ServerRules <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#ServerRules>`_


Unimplemented Methods
---------------------

.. function:: MatchmakingServers.GetServerDetails

    ✋ **Not implemented** - unsupported type: gameserveritem_t *
    
    :SteamWorks: `GetServerDetails <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#GetServerDetails>`_

