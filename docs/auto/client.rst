############
ISteamClient
############

.. note::
   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.
   Methods marked with ✋ require manual implementation.

List of Functions
-----------------

* :func:`Client.CreateSteamPipe`
* :func:`Client.BReleaseSteamPipe`
* :func:`Client.ConnectToGlobalUser`
* :func:`Client.CreateLocalUser`
* :func:`Client.ReleaseUser`
* :func:`Client.SetLocalIPBinding`
* :func:`Client.GetISteamGenericInterface`
* :func:`Client.GetIPCCallCount`
* :func:`Client.BShutdownIfAllPipesClosed`

Function Reference
------------------

.. function:: Client.CreateSteamPipe()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `CreateSteamPipe <https://partner.steamgames.com/doc/api/ISteamClient#CreateSteamPipe>`_

.. function:: Client.BReleaseSteamPipe(hSteamPipe)

    🤖 **Auto-generated binding**

    :param int hSteamPipe:
    :returns: (bool) Return value
    :SteamWorks: `BReleaseSteamPipe <https://partner.steamgames.com/doc/api/ISteamClient#BReleaseSteamPipe>`_

.. function:: Client.ConnectToGlobalUser(hSteamPipe)

    🤖 **Auto-generated binding**

    :param int hSteamPipe:
    :returns: (int) Return value
    :SteamWorks: `ConnectToGlobalUser <https://partner.steamgames.com/doc/api/ISteamClient#ConnectToGlobalUser>`_

.. function:: Client.CreateLocalUser(eAccountType)

    🤖 **Auto-generated binding**

    :param int eAccountType:
    :returns: (int) Return value
    :returns: (int) Value for `phSteamPipe`
    :SteamWorks: `CreateLocalUser <https://partner.steamgames.com/doc/api/ISteamClient#CreateLocalUser>`_

    **Signature differences from C++ API:**

    * Parameter ``phSteamPipe`` is no longer a paramer, and is instead an additional return value

.. function:: Client.ReleaseUser(hSteamPipe, hUser)

    🤖 **Auto-generated binding**

    :param int hSteamPipe:
    :param int hUser:
    :SteamWorks: `ReleaseUser <https://partner.steamgames.com/doc/api/ISteamClient#ReleaseUser>`_

.. function:: Client.SetLocalIPBinding(unIP, usPort)

    🤖 **Auto-generated binding**

    :param :ref:`SteamIPAddress_t <struct-SteamIPAddress_t>` unIP:
    :param int usPort:
    :SteamWorks: `SetLocalIPBinding <https://partner.steamgames.com/doc/api/ISteamClient#SetLocalIPBinding>`_

.. function:: Client.GetISteamGenericInterface(hSteamUser, hSteamPipe, pchVersion)

    🤖 **Auto-generated binding**

    :param int hSteamUser:
    :param int hSteamPipe:
    :param str pchVersion:
    :returns: (str) Return value
    :SteamWorks: `GetISteamGenericInterface <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamGenericInterface>`_

.. function:: Client.GetIPCCallCount()

    🤖 **Auto-generated binding**

    :returns: (int) Return value
    :SteamWorks: `GetIPCCallCount <https://partner.steamgames.com/doc/api/ISteamClient#GetIPCCallCount>`_

.. function:: Client.BShutdownIfAllPipesClosed()

    🤖 **Auto-generated binding**

    :returns: (bool) Return value
    :SteamWorks: `BShutdownIfAllPipesClosed <https://partner.steamgames.com/doc/api/ISteamClient#BShutdownIfAllPipesClosed>`_


Unimplemented Methods
---------------------

.. function:: Client.getISteamUser

    ✋ **Not implemented** - unsupported type: ISteamUser *
    
    :SteamWorks: `GetISteamUser <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamUser>`_

.. function:: Client.getISteamGameServer

    ✋ **Not implemented** - unsupported type: ISteamGameServer *
    
    :SteamWorks: `GetISteamGameServer <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamGameServer>`_

.. function:: Client.getISteamFriends

    ✋ **Not implemented** - unsupported type: ISteamFriends *
    
    :SteamWorks: `GetISteamFriends <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamFriends>`_

.. function:: Client.getISteamUtils

    ✋ **Not implemented** - unsupported type: ISteamUtils *
    
    :SteamWorks: `GetISteamUtils <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamUtils>`_

.. function:: Client.getISteamMatchmaking

    ✋ **Not implemented** - unsupported type: ISteamMatchmaking *
    
    :SteamWorks: `GetISteamMatchmaking <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamMatchmaking>`_

.. function:: Client.getISteamMatchmakingServers

    ✋ **Not implemented** - unsupported type: ISteamMatchmakingServers *
    
    :SteamWorks: `GetISteamMatchmakingServers <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamMatchmakingServers>`_

.. function:: Client.getISteamUserStats

    ✋ **Not implemented** - unsupported type: ISteamUserStats *
    
    :SteamWorks: `GetISteamUserStats <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamUserStats>`_

.. function:: Client.getISteamGameServerStats

    ✋ **Not implemented** - unsupported type: ISteamGameServerStats *
    
    :SteamWorks: `GetISteamGameServerStats <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamGameServerStats>`_

.. function:: Client.getISteamApps

    ✋ **Not implemented** - unsupported type: ISteamApps *
    
    :SteamWorks: `GetISteamApps <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamApps>`_

.. function:: Client.getISteamNetworking

    ✋ **Not implemented** - unsupported type: ISteamNetworking *
    
    :SteamWorks: `GetISteamNetworking <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamNetworking>`_

.. function:: Client.getISteamRemoteStorage

    ✋ **Not implemented** - unsupported type: ISteamRemoteStorage *
    
    :SteamWorks: `GetISteamRemoteStorage <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamRemoteStorage>`_

.. function:: Client.getISteamScreenshots

    ✋ **Not implemented** - unsupported type: ISteamScreenshots *
    
    :SteamWorks: `GetISteamScreenshots <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamScreenshots>`_

.. function:: Client.getISteamHTTP

    ✋ **Not implemented** - unsupported type: ISteamHTTP *
    
    :SteamWorks: `GetISteamHTTP <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamHTTP>`_

.. function:: Client.getISteamController

    ✋ **Not implemented** - unsupported type: ISteamController *
    
    :SteamWorks: `GetISteamController <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamController>`_

.. function:: Client.getISteamUGC

    ✋ **Not implemented** - unsupported type: ISteamUGC *
    
    :SteamWorks: `GetISteamUGC <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamUGC>`_

.. function:: Client.getISteamMusic

    ✋ **Not implemented** - unsupported type: ISteamMusic *
    
    :SteamWorks: `GetISteamMusic <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamMusic>`_

.. function:: Client.getISteamHTMLSurface

    ✋ **Not implemented** - unsupported type: ISteamHTMLSurface *
    
    :SteamWorks: `GetISteamHTMLSurface <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamHTMLSurface>`_

.. function:: Client.getISteamInventory

    ✋ **Not implemented** - unsupported type: ISteamInventory *
    
    :SteamWorks: `GetISteamInventory <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamInventory>`_

.. function:: Client.getISteamVideo

    ✋ **Not implemented** - unsupported type: ISteamVideo *
    
    :SteamWorks: `GetISteamVideo <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamVideo>`_

.. function:: Client.getISteamParentalSettings

    ✋ **Not implemented** - unsupported type: ISteamParentalSettings *
    
    :SteamWorks: `GetISteamParentalSettings <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamParentalSettings>`_

.. function:: Client.getISteamInput

    ✋ **Not implemented** - unsupported type: ISteamInput *
    
    :SteamWorks: `GetISteamInput <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamInput>`_

.. function:: Client.getISteamParties

    ✋ **Not implemented** - unsupported type: ISteamParties *
    
    :SteamWorks: `GetISteamParties <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamParties>`_

.. function:: Client.getISteamRemotePlay

    ✋ **Not implemented** - unsupported type: ISteamRemotePlay *
    
    :SteamWorks: `GetISteamRemotePlay <https://partner.steamgames.com/doc/api/ISteamClient#GetISteamRemotePlay>`_

