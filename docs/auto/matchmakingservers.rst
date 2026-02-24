########################
ISteamMatchmakingServers
########################

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✋ require manual implementation.

List of Functions
-----------------

* :func:`MatchmakingServers.RequestInternetServerList`
* :func:`MatchmakingServers.RequestLANServerList`
* :func:`MatchmakingServers.RequestFriendsServerList`
* :func:`MatchmakingServers.RequestFavoritesServerList`
* :func:`MatchmakingServers.RequestHistoryServerList`
* :func:`MatchmakingServers.RequestSpectatorServerList`
* :func:`MatchmakingServers.ReleaseRequest`
* :func:`MatchmakingServers.CancelQuery`
* :func:`MatchmakingServers.RefreshQuery`
* :func:`MatchmakingServers.IsRefreshing`
* :func:`MatchmakingServers.GetServerCount`
* :func:`MatchmakingServers.RefreshServer`
* :func:`MatchmakingServers.PingServer`
* :func:`MatchmakingServers.PlayerDetails`
* :func:`MatchmakingServers.ServerRules`
* :func:`MatchmakingServers.CancelServerQuery`

Function Reference
------------------

.. function:: MatchmakingServers.RequestInternetServerList(iApp, ppchFilters, pRequestServersResponse)

    🤖 **Auto-generated binding**

    :param int iApp:
    :param :ref:`MatchMakingKeyValuePair_t <struct-MatchMakingKeyValuePair_t>`[] ppchFilters:
    :param :ref:`ISteamMatchmakingServerListResponse <struct-ISteamMatchmakingServerListResponse>` pRequestServersResponse:
    :returns: (HServerListRequest) Return value
    :SteamWorks: `RequestInternetServerList <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#RequestInternetServerList>`_

.. function:: MatchmakingServers.RequestLANServerList(iApp, pRequestServersResponse)

    🤖 **Auto-generated binding**

    :param int iApp:
    :param :ref:`ISteamMatchmakingServerListResponse <struct-ISteamMatchmakingServerListResponse>` pRequestServersResponse:
    :returns: (HServerListRequest) Return value
    :SteamWorks: `RequestLANServerList <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#RequestLANServerList>`_

.. function:: MatchmakingServers.RequestFriendsServerList(iApp, ppchFilters, pRequestServersResponse)

    🤖 **Auto-generated binding**

    :param int iApp:
    :param :ref:`MatchMakingKeyValuePair_t <struct-MatchMakingKeyValuePair_t>`[] ppchFilters:
    :param :ref:`ISteamMatchmakingServerListResponse <struct-ISteamMatchmakingServerListResponse>` pRequestServersResponse:
    :returns: (HServerListRequest) Return value
    :SteamWorks: `RequestFriendsServerList <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#RequestFriendsServerList>`_

.. function:: MatchmakingServers.RequestFavoritesServerList(iApp, ppchFilters, pRequestServersResponse)

    🤖 **Auto-generated binding**

    :param int iApp:
    :param :ref:`MatchMakingKeyValuePair_t <struct-MatchMakingKeyValuePair_t>`[] ppchFilters:
    :param :ref:`ISteamMatchmakingServerListResponse <struct-ISteamMatchmakingServerListResponse>` pRequestServersResponse:
    :returns: (HServerListRequest) Return value
    :SteamWorks: `RequestFavoritesServerList <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#RequestFavoritesServerList>`_

.. function:: MatchmakingServers.RequestHistoryServerList(iApp, ppchFilters, pRequestServersResponse)

    🤖 **Auto-generated binding**

    :param int iApp:
    :param :ref:`MatchMakingKeyValuePair_t <struct-MatchMakingKeyValuePair_t>`[] ppchFilters:
    :param :ref:`ISteamMatchmakingServerListResponse <struct-ISteamMatchmakingServerListResponse>` pRequestServersResponse:
    :returns: (HServerListRequest) Return value
    :SteamWorks: `RequestHistoryServerList <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#RequestHistoryServerList>`_

.. function:: MatchmakingServers.RequestSpectatorServerList(iApp, ppchFilters, pRequestServersResponse)

    🤖 **Auto-generated binding**

    :param int iApp:
    :param :ref:`MatchMakingKeyValuePair_t <struct-MatchMakingKeyValuePair_t>`[] ppchFilters:
    :param :ref:`ISteamMatchmakingServerListResponse <struct-ISteamMatchmakingServerListResponse>` pRequestServersResponse:
    :returns: (HServerListRequest) Return value
    :SteamWorks: `RequestSpectatorServerList <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#RequestSpectatorServerList>`_

.. function:: MatchmakingServers.ReleaseRequest(hServerListRequest)

    🤖 **Auto-generated binding**

    :param HServerListRequest hServerListRequest:
    :SteamWorks: `ReleaseRequest <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#ReleaseRequest>`_

.. function:: MatchmakingServers.CancelQuery(hRequest)

    🤖 **Auto-generated binding**

    :param HServerListRequest hRequest:
    :SteamWorks: `CancelQuery <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#CancelQuery>`_

.. function:: MatchmakingServers.RefreshQuery(hRequest)

    🤖 **Auto-generated binding**

    :param HServerListRequest hRequest:
    :SteamWorks: `RefreshQuery <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#RefreshQuery>`_

.. function:: MatchmakingServers.IsRefreshing(hRequest)

    🤖 **Auto-generated binding**

    :param HServerListRequest hRequest:
    :returns: (bool) Return value
    :SteamWorks: `IsRefreshing <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#IsRefreshing>`_

.. function:: MatchmakingServers.GetServerCount(hRequest)

    🤖 **Auto-generated binding**

    :param HServerListRequest hRequest:
    :returns: (int) Return value
    :SteamWorks: `GetServerCount <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#GetServerCount>`_

.. function:: MatchmakingServers.RefreshServer(hRequest, iServer)

    🤖 **Auto-generated binding**

    :param HServerListRequest hRequest:
    :param int iServer:
    :SteamWorks: `RefreshServer <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#RefreshServer>`_

.. function:: MatchmakingServers.PingServer(unIP, usPort, pRequestServersResponse)

    🤖 **Auto-generated binding**

    :param int unIP:
    :param int usPort:
    :param :ref:`ISteamMatchmakingPingResponse <struct-ISteamMatchmakingPingResponse>` pRequestServersResponse:
    :returns: (int) Return value
    :SteamWorks: `PingServer <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#PingServer>`_

.. function:: MatchmakingServers.PlayerDetails(unIP, usPort, pRequestServersResponse)

    🤖 **Auto-generated binding**

    :param int unIP:
    :param int usPort:
    :param :ref:`ISteamMatchmakingPlayersResponse <struct-ISteamMatchmakingPlayersResponse>` pRequestServersResponse:
    :returns: (int) Return value
    :SteamWorks: `PlayerDetails <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#PlayerDetails>`_

.. function:: MatchmakingServers.ServerRules(unIP, usPort, pRequestServersResponse)

    🤖 **Auto-generated binding**

    :param int unIP:
    :param int usPort:
    :param :ref:`ISteamMatchmakingRulesResponse <struct-ISteamMatchmakingRulesResponse>` pRequestServersResponse:
    :returns: (int) Return value
    :SteamWorks: `ServerRules <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#ServerRules>`_

.. function:: MatchmakingServers.CancelServerQuery(hServerQuery)

    🤖 **Auto-generated binding**

    :param int hServerQuery:
    :SteamWorks: `CancelServerQuery <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#CancelServerQuery>`_


Unimplemented Methods
---------------------

.. function:: MatchmakingServers.getServerDetails

    ✋ **Not implemented** - unsupported type: gameserveritem_t *
    
    :SteamWorks: `GetServerDetails <https://partner.steamgames.com/doc/api/ISteamMatchmakingServers#GetServerDetails>`_

