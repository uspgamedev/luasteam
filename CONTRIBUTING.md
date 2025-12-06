# Contributing

We are open to contributions, either adding new functions, improving documentation or fixing some bugs. See [#23](https://github.com/uspgamedev/luasteam/pull/23) for and example of a pull request from an external user that was interested in more functions.

## Adding new functions

We encourage you to add functions that are currently missing. Follow the style of functions already added in this project, that means, if you're adding `ISteamFriends::ActivateGameOverlayToStore`, follow these guidelines:
- Implement it in file `src/friends.cpp`
- Name it `SteamFriends.activateGameOverlayToStore`
- Try to keep all arguments in the same order, with the same names (in a different naming convention, drop the type prefixes) and of the same type. Enums should be changed to string, for example `k_EOverlayToStoreFlag_AddToCart` becomes `"AddToCart"`.
- Callbacks and CallResults have a special way of being implemented: check [our documentation](https://luasteam.readthedocs.io/en/stable/getting_started.html#callbacks).
- IDs that are actually 64-bit integers should be implemented using [our uint64 userdata](https://github.com/uspgamedev/luasteam/blob/v1.0.1/src/common.hpp#L21-L24).
- It's fine if the functions are a bit different ([example](https://luasteam.readthedocs.io/en/stable/user_stats.html#userStats.downloadLeaderboardEntries)) because stuff in Lua is different than in C++.

Send us PRs even if you're not sure you're following these guidelines correctly. We won't bite. Open an issue if you have any doubts.

## Documentation

If you add new functions, please also document them. Keep the documentation as close as possible to the original Steam API documentation, to minimise developer confusion.
We do our documentation in [ReadTheDocs](https://readthedocs.org/). Everything is in the [docs](docs/) directory, it uses reStructuredText, [this cheatsheet](https://github.com/ralsina/rst-cheatsheet/blob/master/rst-cheatsheet.rst) should help if you don't know it.

Basically all you need is sphinx (`pip install sphinx sphinx-rtd-theme`), and then you can run `make html` from inside the [docs](docs/) directory.

**Pro Tip**: [This Dockerfile](https://hub.docker.com/r/dldl/sphinx-server/) makes it easy to test documentation locally. You won't need to install anything (if you already have docker) and it enables live reload of the documentation when you change anything.

## Building

While developing, we recommend you just worry about compiling to the platform you're using, and let Github Actions deal with the other platforms (since if it compiles in one, it most likely compiles in all, the difficult part is getting the dependencies right).

### For all platforms

1. Download the [SteamWorks SDK](https://partner.steamgames.com/doc/sdk).
2. Unzip it so that the `sdk` folder is in this directory, not `steamworks_sdk_163/sdk`.
3. Make sure the luajit submodule is cloned with `git submodule update --init`.
4. Remember to `make clean` when changing between building for 32 and 64 bits.

### Linux 64

You need `g++`, in Ubuntu-like `sudo apt-get install buildessentials` should be enough. Run `make linux64`.

### Linux 32 (from Linux 64)

You may also need `g++-multilib`. Run `make linux32`.

### OS X

Install luajit (`brew install luajit`). Run `make osx`.

### Windows 32 and 64

1. Install [Git BASH](https://gitforwindows.org/). You likely already have it installed if you've installed git.
   1. Windows Command Prompt and Windows PowerShell do not work.
2. Install `g++` and `make`, the best supported way is using MSYS2.
3. Open a Git Bash terminal.
4. Run `mingw32-make win32` for Windows 32 and `mingw32-make win64` for Windows 64.

## Resources
- [Steam API Reference](https://partner.steamgames.com/doc/api)
- [Lua C API Overview](https://www.lua.org/manual/5.1/manual.html#3)
