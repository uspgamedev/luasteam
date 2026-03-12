# Examples

This can be used to easily test if things are working with luasteam.

To test, copy the `luasteam.dll` or `luasteam.so`, and the Steam SDK .dll or .so to a directory, then run the game with `/path/to/your/love.exec .` or `../../luajit/src/luajit main.lua` from that directory. The examples with a `steam_appid.txt` file actually need Steam to be up and running to work.

## List of Examples

- `basic`: Tests luasteam can be imported without crashing, and has some basic interfaces and enums set up. Does not need Steam running.
- `basic_love`: Tests luasteam can be imported without crashing, and prints to the screen using LOVE2D. Does not need Steam running.
- `socket_client`/`socket_server`: By running both, you can test the socket API.