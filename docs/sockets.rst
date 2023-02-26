###############
ISteamNetworkingSockets
###############


List of Functions
-----------------
* :func:`sockets.createListenSocketIP`


Function Reference
------------------

.. function:: sockets.createListenSocketIP()

    :param string localAdress: The adress to bind to in string format. E.g. to bind to localhost on port 55556, use **"[::]:55556"**.
    :param table options: Table with key value pairs to override default SteamNetworkingSockets options. **NOT IMPLEMENTED YET**
    :returns: a string representation of the adress/port connected to
    :SteamWorks: `CreateListenSocketIP <https://partner.steamgames.com/doc/api/ISteamNetworkingSockets#CreateListenSocketIP>`_

    Bind to an adress and accept connections as a "server". If you want to change any networking settings, you need pass these options on creation. Implement the callback **TODO** to be notified about connection events.