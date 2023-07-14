#####################
ISteamNetworkingUtils 
#####################

List of Functions
-----------------
* :func:`networkingUtils.initRelayNetworkAccess`
* :func:`networkingUtils.getRelayNetworkStatus`

Function Reference
------------------
.. function:: networkingUtils.initRelayNetworkAccess()

    :returns: nothing
    :SteamWorks: `InitRelayNetworkAccess <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#InitRelayNetworkAccess>`_

    If you know that you are going to be using the relay network (for example, because you anticipate making P2P connections), call this to initialize the relay network. If you do not call this, the initialization will be delayed until the first time you use a feature that requires access to the relay network, which will delay that first access.

    You can also call this to force a retry if the previous attempt has failed. Performing any action that requires access to the relay network will also trigger a retry, and so calling this function is never strictly necessary, but it can be useful to call it a program launch time, if access to the relay network is anticipated. Use GetRelayNetworkStatus or listen for SteamRelayNetworkStatus_t callbacks to know when initialization has completed. Typically initialization completes in a few seconds.

    Note: dedicated servers hosted in known data centers do *not* need to call this, since they do not make routing decisions. However, if the dedicated server will be using P2P functionality, it will act as a "client" and this should be called.

**Example**::

    Steam.networkingUtils.initRelayNetworkAccess()

.. function:: networkingUtils.getRelayNetworkStatus()

    :returns: (`int`) status. See the callback :func:`networkingSockets.onAuthenticationStatus` callback for a detailed description.
    :SteamWorks: `GetRelayNetworkStatus <https://partner.steamgames.com/doc/api/ISteamNetworkingUtils#GetRelayNetworkStatus>`_

    Fetch current status of the relay network.

**Example**::

    local status = Steam.networkingUtils.getRelayNetworkStatus()
