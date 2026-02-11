# luasteam Generator

This is a Rust-based tool to automatically generate C++ bindings for the Steam API.
It parses `sdk/public/steam/steam_api.json` and produces C++ wrapper functions and registration logic.

## How to use

1.  Make sure you have Rust installed.
2.  Run the generator:
    ```bash
    cargo run
    ```
3.  The generator will update the files in `src/auto/`.
4.  Build the project as usual using the top-level `Makefile`.

## How it works

The generator maps Steam API types to Lua-compatible types.
For each interface (e.g., `ISteamApps`), it generates:
-   A C++ file `src/auto/apps.cpp` containing wrapper functions for all supported methods.
-   An `add_apps_auto(lua_State *L)` function that registers these functions in Lua.

Existing manual bindings in `src/` are preserved and will overwrite auto-generated ones if they have the same name, because they are registered after the auto-generated ones.

## Supported Types

Currently, the generator supports:
-   `int`, `uint32`, `bool`, `const char *`
-   `uint64`, `CSteamID`, `CGameID` (via `luasteam::checkuint64` and `luasteam::pushuint64`)
-   `void` return type

Methods with unsupported parameter or return types are skipped and must be implemented manually.
