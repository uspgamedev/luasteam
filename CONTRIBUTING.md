# Contributing

We are open to contributions! Our goal is to provide a comprehensive, 1:1 binding of the Steamworks API for Lua.

## Architecture

This project uses a **hybrid architecture**:

1.  **Auto-generated Bindings:** The vast majority of the API (Interfaces, Methods, Structs, Enums, Constants) is automatically generated from `steam_api.json` using a Rust generator.
    *   Source: `generator/` (Rust code)
    *   Output: `src/auto/` (C++ code), `docs/auto` (RST documentation), `luals/` (Lua type definitions)
    *   **Do not edit generated files manually.** They will be overwritten.

2.  **Manual Bindings:** Complex edge cases (tricky callbacks, custom behavior) are implemented manually.
    *   Location: `src/` (e.g., `src/Extra.cpp`, `src/NetworkingSockets.cpp`).

## How to Contribute

### 1. Fixing/Improving Auto-generation
If you find a missing method or a bug in a generated function, try to fix it in the **Generator** first.

1.  Modify files under `generator/src`.
2.  Run `make generate`  to regenerate the C++ code (from the top directory).
3.  Recompile `luasteam` (e.g. `make win64`) to test.

Common generator tasks:
*   **Unsupported Types:** Implement support for new types in `resolve_type`, `generate_check` (input), and `generate_push` (output), which unblocks all API functions that use those types.
*   **JSON Inconsistencies:** Though `steam_api.json` is very useful, it is not 100% consistent and has plenty of mistakes that need to be manually fixed, such as missing size indicator for arrays. See `SteamApi::apply_fixes`.

### 2. Adding Manual Bindings
If a method is too complex for the generator (e.g., requires custom logic or unsupported types like function pointers), you can implement it manually.

1.  **Blocklist it:** Add the method name to `method_blocklist` in `generator/src/main.rs` using `SkipReason::ManualImpl` to prevent auto-generation attempts.
2.  **Implement it:** Add the C++ implementation in a file in `src/` (e.g., `src/NetworkingSockets.cpp`).
3.  **Register it:** Ensure your new function is registered in `src/main.cpp` or the relevant initialization function.

### 3. Documentation
The documentation is built with Sphinx, and it is mostly generated automatically, but incremented with manual examples and documentation given in `generator/custom_docs.toml`.

When modifying the generator, the base documentation is added automatically, but do add an example in `custom_docs.toml`. When adding manual bindings, you need to add the full documentation in `custom_docs.toml`.

```toml
# Adding an example
[ISteamInventory.TriggerItemDrop]
example = """
local ok, resultHandle = Steam.Inventory.TriggerItemDrop(dropListDefinitionID)
-- Triggers a potential item drop for playtime rewards
"""

# See [manual.ISteamNetworkingSockets.ReceiveMessagesOnPollGroup] for how to add documentation for a manual binding.
```

To see the documentation, run `make docs` and then open `docs/_build/html/index.html`. You need Sphinx installed as a python package.


## Building

### Prerequisites
*   **Rust:** Required to run the generator.
*   **C++:** Required to compile the bindings. On Windows, I recommend using MSYS2.
*   **Steamworks SDK:** Download and extract into the project root (folder `sdk`).
*   **LuaJIT:** Clone the submodule (`git submodule update --init`). It builds as part of the project.
*   **Sphinx:** Required when building documentation. Use `pip install sphinx sphinx-rtd-theme`.
*   **LuaLS:** Required when validating the `.d.lua` files.

For basic usage, Rust, C++ and the SDK are enough.

### Steps
0.  **Format:** `make fmt`
1.  **Generate:** `make generate`
2.  **Compile:**
    *   **Linux:** `make linux64`
    *   **Windows:** `mingw32-make win64` (using MSYS2/MinGW)
    *   **macOS:** `make osx`
3. **Documentation:** `make docs` (only when testing it manually)


## Testing

### Integration test
When building through make, a basic test in `examples/basic` will run automatically to verify luasteam doesn't crash on import.

### LuaLS type-checking
The `luals/` directory contains (auto-generated) [LuaLS](https://github.com/LuaLS/lua-language-server) type definitions (`.d.lua`) for the entire API. To validate them, run `make check-luals`.

This requires `lua-language-server` to be on your `PATH`. If the binary is not on your PATH you can override it via a `.env` file in the repo root:

```sh
# File .env
LUA_LANGUAGE_SERVER=C:/path/to/lua-language-server.exe
```

## Style Guide (when doing manual binds)
*   **Lua API:** 1:1 mapping to C++. If C++ is `ISteamUser::GetAuthSessionTicket`, Lua is `Steam.User.GetAuthSessionTicket`.
*   **Parameters:** Match C++ order and types.
*   **Outputs:** Output parameters in C++ are returned as multiple return values in Lua.
    *   Example: `GetAuthSessionTicket` returns `handle, ticket_buffer, ticket_size`.

## Resources
*   [Steam API Reference](https://partner.steamgames.com/doc/api)
*   [Lua C API Overview](https://www.lua.org/manual/5.1/manual.html#3)
