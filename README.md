# luasteam

Lua bindings for SteamWorks API

## Usage

To use luasteam in your game, you just need to place the appropriate library files together with your lua files.

Download the SteamWorks SDK, then copy the following files to the same directory as your lua files. The files needed from this repository can be found in the [Releases page](https://github.com/uspgamedev/luasteam/releases).
- Linux 32: `luasteam.so` from this repository and `sdk\redistributable_bin\linux32\libsteam_api.so` from the SDK.
- Linux 64: `luasteam.so` from this repository and `sdk\redistributable_bin\linux64\libsteam_api.so` from the SDK.
- Windows 32: `luasteam.dll` from this repository and `sdk\redistributable_bin\steam_api.dll` from the SDK.
- Windows 64: `luasteam.dll` from this repository and `sdk\redistributable_bin\win64\steam_api64.dll` from the SDK.
- OSX: **TODO**

Then, you can use luasteam as an usual lua library. For example:

```lua
local luasteam = require('luasteam') -- You must do this before OpenGL is loaded!
-- ...
luasteam.resetAllStats(true) -- resetting everything for the user
-- ...
luasteam.shutdown() -- Don't forget to shutdown the API when your game is closed
```

## Building from scratch

First, download the SteamWorks SDK. Then copy recursively all files from `sdk/public/steam/` to `./include`.

### Linux 32 and 64

Install package `libluajit-5.1-dev`. Copy `sdk/redistributable_bin/linux64/libsteam_api.so` to this directory (or the one in `linux32`). Run `make linux64` (or `make linux32`). This assumes you're using a 64 bit OS.

### OS X

**TODO**

### Windows 32 and 64

Download VSCode and [LuaJIT source](http://luajit.org/download.html). Build it using "x64\_86 Cross Tools Command Prompt for VS 2017" (or similar, depending if you want x86 or x64 and what platform you have) ([instructions](http://luajit.org/install.html#windows)).

Copy source files from `LuaJIT-2.0.5\src` to a `luajit` directory inside this directory. Copy `LuaJIT-2.0.5\src\lua51.lib` and `sdk\redisbutable_bin\steam_api.lib` to this directory (or the one inside `windows64` directory if you're targeting x64). Then run `nmake windows32` or `nmake windows64`, this will create the `luasteam.dll` file.

If you're building for both Windows 32 and 64, remember to rebuild LuaJIT and copy `lua51.lib` again for the correct platform.
