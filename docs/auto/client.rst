############
ISteamClient
############

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✍️ are manually implemented and methods marked with ✋ are currently not implemented.

.. note::
    This interface can be accessed has multiple accessors (e.g. a GameServer variant), the documentation shows ``Client`` everywhere but it can also be accessed with ``GameServerClient``.

List of Functions
-----------------

* :func:`Client.BReleaseSteamPipe`
* :func:`Client.BShutdownIfAllPipesClosed`
* :func:`Client.ConnectToGlobalUser`
* :func:`Client.CreateLocalUser`
* :func:`Client.CreateSteamPipe`
* :func:`Client.GetIPCCallCount`
* :func:`Client.ReleaseUser`
* :func:`Client.SetLocalIPBinding`
* :func:`Client.SetWarningMessageHook`

Function Reference
------------------

.. function:: Client.BReleaseSteamPipe(hSteamPipe)

    🤖 **Auto-generated binding**

    :param int - HSteamPipe hSteamPipe:
    :returns: (bool) Return value
    :SteamWorks: `BReleaseSteamPipe <https://partner.steamgames.com/doc/api/ISteamClient#BReleaseSteamPipe>`_

**Example**::

    Steam.Client.BReleaseSteamPipe(hPipe)

.. function:: Client.BShutdownIfAllPipesClosed()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BShutdownIfAllPipesClosed <https://partner.steamgames.com/doc/api/ISteamClient#BShutdownIfAllPipesClosed>`_

**Example**::

    Steam.Client.BShutdownIfAllPipesClosed()

.. function:: Client.ConnectToGlobalUser(hSteamPipe)

    🤖 **Auto-generated binding**

    :param int - HSteamPipe hSteamPipe:
    :returns: (int - HSteamUser) Return value
    :SteamWorks: `ConnectToGlobalUser <https://partner.steamgames.com/doc/api/ISteamClient#ConnectToGlobalUser>`_

**Example**::

    local hUser = Steam.Client.ConnectToGlobalUser(hPipe)

.. function:: Client.CreateLocalUser(eAccountType)

    🤖 **Auto-generated binding**

    :param int - EAccountType eAccountType:
    :returns: (int - HSteamUser) Return value
    :returns: (int) ``phSteamPipe``
    :SteamWorks: `CreateLocalUser <https://partner.steamgames.com/doc/api/ISteamClient#CreateLocalUser>`_

    **Signature differences from C++ API:**

    * Parameter ``phSteamPipe`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    local hUser, hPipe = Steam.Client.CreateLocalUser(Steam.k_EAccountTypeIndividual)

.. function:: Client.CreateSteamPipe()

    🤖 **Auto-generated binding**

    :returns: (int - HSteamPipe) Return value
    :SteamWorks: `CreateSteamPipe <https://partner.steamgames.com/doc/api/ISteamClient#CreateSteamPipe>`_

**Example**::

    local hPipe = Steam.Client.CreateSteamPipe()

.. function:: Client.GetIPCCallCount()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetIPCCallCount <https://partner.steamgames.com/doc/api/ISteamClient#GetIPCCallCount>`_

.. function:: Client.ReleaseUser(hSteamPipe, hUser)

    🤖 **Auto-generated binding**

    :param int - HSteamPipe hSteamPipe:
    :param int - HSteamUser hUser:
    :SteamWorks: `ReleaseUser <https://partner.steamgames.com/doc/api/ISteamClient#ReleaseUser>`_

**Example**::

    Steam.Client.ReleaseUser(hPipe, hUser)

.. function:: Client.SetLocalIPBinding(unIP, usPort)

    🤖 **Auto-generated binding**

    :param unIP: (:ref:`SteamIPAddress_t <struct-SteamIPAddress_t>`)
    :param int usPort:
    :SteamWorks: `SetLocalIPBinding <https://partner.steamgames.com/doc/api/ISteamClient#SetLocalIPBinding>`_

.. function:: Client.SetWarningMessageHook(callback)

    ✍️ **Manually implemented**

    :param function? callback: Function receiving ``(severity: integer, message: string)``. Pass ``nil`` to clear the hook.
    :returns: nothing
    :SteamWorks: `SetWarningMessageHook <https://partner.steamgames.com/doc/api/ISteamClient#SetWarningMessageHook>`_

    Sets a callback to receive Steam API warning and info messages.

    **Notes:**

    * Also available as ``Steam.GameServerClient.SetWarningMessageHook`` with identical signature.


Unimplemented Methods
---------------------

.. function:: Client.GetISteamUser

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamUser <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamUser>`_

.. function:: Client.GetISteamGameServer

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamGameServer <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamGameServer>`_

.. function:: Client.GetISteamFriends

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamFriends <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamFriends>`_

.. function:: Client.GetISteamUtils

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamUtils <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamUtils>`_

.. function:: Client.GetISteamMatchmaking

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamMatchmaking <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamMatchmaking>`_

.. function:: Client.GetISteamMatchmakingServers

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamMatchmakingServers <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamMatchmakingServers>`_

.. function:: Client.GetISteamGenericInterface

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamGenericInterface <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamGenericInterface>`_

.. function:: Client.GetISteamUserStats

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamUserStats <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamUserStats>`_

.. function:: Client.GetISteamGameServerStats

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamGameServerStats <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamGameServerStats>`_

.. function:: Client.GetISteamApps

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamApps <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamApps>`_

.. function:: Client.GetISteamNetworking

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamNetworking <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamNetworking>`_

.. function:: Client.GetISteamRemoteStorage

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamRemoteStorage <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamRemoteStorage>`_

.. function:: Client.GetISteamScreenshots

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamScreenshots <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamScreenshots>`_

.. function:: Client.GetISteamHTTP

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamHTTP <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamHTTP>`_

.. function:: Client.GetISteamController

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamController <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamController>`_

.. function:: Client.GetISteamUGC

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamUGC <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamUGC>`_

.. function:: Client.GetISteamMusic

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamMusic <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamMusic>`_

.. function:: Client.GetISteamHTMLSurface

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamHTMLSurface <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamHTMLSurface>`_

.. function:: Client.GetISteamInventory

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamInventory <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamInventory>`_

.. function:: Client.GetISteamVideo

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamVideo <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamVideo>`_

.. function:: Client.GetISteamParentalSettings

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamParentalSettings <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamParentalSettings>`_

.. function:: Client.GetISteamInput

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamInput <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamInput>`_

.. function:: Client.GetISteamParties

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamParties <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamParties>`_

.. function:: Client.GetISteamRemotePlay

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamRemotePlay <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamRemotePlay>`_

