############
ISteamClient
############

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✍️ are manually implemented and methods marked with ✋ are currently not implemented.

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

    :param int hSteamPipe:
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

    :param int hSteamPipe:
    :returns: (int) Return value
    :SteamWorks: `ConnectToGlobalUser <https://partner.steamgames.com/doc/api/ISteamClient#ConnectToGlobalUser>`_

**Example**::

    local hUser = Steam.Client.ConnectToGlobalUser(hPipe)

.. function:: Client.CreateLocalUser(eAccountType)

    🤖 **Auto-generated binding**

    :param int eAccountType:
    :returns: (int) Return value
    :returns: (int) ``phSteamPipe``
    :SteamWorks: `CreateLocalUser <https://partner.steamgames.com/doc/api/ISteamClient#CreateLocalUser>`_

    **Signature differences from C++ API:**

    * Parameter ``phSteamPipe`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.

**Example**::

    local hUser, hPipe = Steam.Client.CreateLocalUser(Steam.k_EAccountTypeIndividual)

.. function:: Client.CreateSteamPipe()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `CreateSteamPipe <https://partner.steamgames.com/doc/api/ISteamClient#CreateSteamPipe>`_

**Example**::

    local hPipe = Steam.Client.CreateSteamPipe()

.. function:: Client.GetIPCCallCount()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetIPCCallCount <https://partner.steamgames.com/doc/api/ISteamClient#GetIPCCallCount>`_

.. function:: Client.ReleaseUser(hSteamPipe, hUser)

    🤖 **Auto-generated binding**

    :param int hSteamPipe:
    :param int hUser:
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

    :param function or nil callback: Function receiving ``(severity: integer, message: string)``. Pass ``nil`` to clear the hook.
    :returns: nothing
    :SteamWorks: `SetWarningMessageHook <https://partner.steamgames.com/doc/api/ISteamClient#SetWarningMessageHook>`_

    Sets a callback to receive Steam API warning and info messages.

    **Notes:**

    * Also available as ``Steam.GameServerClient.SetWarningMessageHook`` with identical signature.


Unimplemented Methods
---------------------

.. function:: Client.getISteamUser

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamUser <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamUser>`_

.. function:: Client.getISteamGameServer

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamGameServer <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamGameServer>`_

.. function:: Client.getISteamFriends

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamFriends <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamFriends>`_

.. function:: Client.getISteamUtils

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamUtils <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamUtils>`_

.. function:: Client.getISteamMatchmaking

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamMatchmaking <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamMatchmaking>`_

.. function:: Client.getISteamMatchmakingServers

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamMatchmakingServers <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamMatchmakingServers>`_

.. function:: Client.getISteamGenericInterface

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamGenericInterface <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamGenericInterface>`_

.. function:: Client.getISteamUserStats

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamUserStats <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamUserStats>`_

.. function:: Client.getISteamGameServerStats

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamGameServerStats <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamGameServerStats>`_

.. function:: Client.getISteamApps

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamApps <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamApps>`_

.. function:: Client.getISteamNetworking

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamNetworking <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamNetworking>`_

.. function:: Client.getISteamRemoteStorage

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamRemoteStorage <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamRemoteStorage>`_

.. function:: Client.getISteamScreenshots

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamScreenshots <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamScreenshots>`_

.. function:: Client.getISteamHTTP

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamHTTP <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamHTTP>`_

.. function:: Client.getISteamController

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamController <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamController>`_

.. function:: Client.getISteamUGC

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamUGC <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamUGC>`_

.. function:: Client.getISteamMusic

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamMusic <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamMusic>`_

.. function:: Client.getISteamHTMLSurface

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamHTMLSurface <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamHTMLSurface>`_

.. function:: Client.getISteamInventory

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamInventory <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamInventory>`_

.. function:: Client.getISteamVideo

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamVideo <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamVideo>`_

.. function:: Client.getISteamParentalSettings

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamParentalSettings <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamParentalSettings>`_

.. function:: Client.getISteamInput

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamInput <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamInput>`_

.. function:: Client.getISteamParties

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamParties <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamParties>`_

.. function:: Client.getISteamRemotePlay

    ✋ **Not implemented** - blocklist: Custom acessors are not supported
    
    :SteamWorks: `GetISteamRemotePlay <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamRemotePlay>`_

