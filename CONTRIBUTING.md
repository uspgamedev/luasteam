# Contributing

We are open to contributions, either adding new functions, improving documentation or fixing some bugs.

## Documentation

If you add new functions, please also document them.
We do our documentation in [ReadTheDocs](https://readthedocs.org/). Everything is in the [docs](docs/) directory, it uses reStructuredText, [this cheatsheet](https://github.com/ralsina/rst-cheatsheet/blob/master/rst-cheatsheet.rst) should help if you don't know it.

Basically all you need is sphinx (`pip install sphinx sphinx-rtd-theme`), and then you can run `make html` from inside the [docs](docs/) directory.

**Pro Tip**: [This Dockerfile](https://hub.docker.com/r/dldl/sphinx-server/) makes it easy to test documentation locally. You won't need to install anything (if you already have docker) and it enables live reload of the documentation when you change anything.

## Building on all platforms

**First, download the SteamWorks SDK, and unzip it on this directory.**

### Linux 64

Install package `libluajit-5.1-dev`. Run `make linux64`.

### Linux 32

Install package `libluajit-5.1-dev:i386`. Run `make linux32`. This assumes you're using a 64 bit OS.

### OS X

Install luajit (`brew install luajit`). Run `make osx`.

### Windows 32 and 64

Download VSCode and [LuaJIT source](http://luajit.org/download.html). Build it using "x64_86 Cross Tools Command Prompt for VS 2017" (or similar, depending if you want x86 or x64 and what platform you have) ([instructions](http://luajit.org/install.html#windows)).

Copy source files from `LuaJIT-2.0.5\src` to a `luajit` directory inside this directory. Copy `LuaJIT-2.0.5\src\lua51.lib` to this directory. Then run `nmake windows32` or `nmake windows64`, this will create the `luasteam.dll` file.

If you're building for both Windows 32 and 64, remember to rebuild LuaJIT and copy `lua51.lib` again for the correct platform.