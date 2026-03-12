##########################
Networking Sockets Example
##########################

--------

These examples send a simple message from server to client and back, and should run with LuaJIT or LOVE2D. They can be found in the ``examples/socket_client/`` and ``examples/socket_server/`` folders of the repository. To run them, copy the luasteam and Steam API dlls into the folder and run with luajit, like ``../../luajit/src/luajit main.lua`` from inside their folder.

Read more about how Steam networking works at `their documentation <https://partner.steamgames.com/doc/features/multiplayer/steamdatagramrelay>`_.
For the complete function reference, see :doc:`auto/networkingsockets`.

.. literalinclude:: ../examples/socket_client/main.lua
    :caption: Socket Client Example
    :language: lua
    :linenos:
   
.. literalinclude:: ../examples/socket_server/main.lua
    :caption: Socket Server Example
    :language: lua
    :linenos:
