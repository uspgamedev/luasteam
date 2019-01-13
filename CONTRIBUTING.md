# Contributing

We are open to contributions, either adding new functions, improving documentation or fixing some bugs.

## Documentation

If you add new functions, please also document them.
We do our documentation in [ReadTheDocs](https://readthedocs.org/). Everything is in the [docs](docs/) directory, it uses reStructuredText, [this cheatsheet](https://github.com/ralsina/rst-cheatsheet/blob/master/rst-cheatsheet.rst) should help if you don't know it.

Basically all you need is sphinx (`pip install sphinx sphinx-rtd-theme`), and then you can run `make html` from inside the [docs](docs/) directory.

**Pro Tip**: [This Dockerfile](https://hub.docker.com/r/dldl/sphinx-server/) makes it easy to test documentation locally. You won't need to install anything (if you already have docker) and it enables live reload of the documentation when you change anything.

## Building on all platforms

**First, download the SteamWorks SDK, and unzip it on this directory.**

While developing, we recommend you just worry about compiling to the platform you're using, and let Travis deal with the other platforms (since if it compiles in one, it most likely compiles in all, the difficult part is getting the dependencies right).

### Linux 64

Install package `libluajit-5.1-dev`. Run `make linux64`.

### Linux 32

Install package `libluajit-5.1-dev:i386` (you may also need `g++-multilib`). Run `make linux32`. This assumes you're using a 64 bit OS.

### OS X

Install luajit (`brew install luajit`). Run `make osx`.

### Windows 32 and 64

We'll use [chocolatey](https://chocolatey.org). Install VS and mingw (`choco install visualstudio20127community visualstudio2017-workload-nativecrossplat mingw`). Then run `mingw32-make windows32` for Windows 32 and `mingw32-make windows64` for Windows 64.
