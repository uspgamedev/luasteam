# Contributing

We are open to contributions! Our goal is to provide a comprehensive, 1:1 binding of the Steamworks API for Lua.

## Architecture

This project now uses a **hybrid architecture**:

1.  **Auto-generated Bindings:** The vast majority of the API (Interfaces, Methods, Structs, Enums, Constants) is automatically generated from `steam_api.json` using a Rust generator.
    *   Source: `generator/` (Rust code)
    *   Output: `src/auto/` (C++ code)
    *   **Do not edit files in `src/auto/` manually.** They will be overwritten.

2.  **Manual Bindings:** Complex edge cases (double pointers, tricky callbacks, custom behavior) are implemented manually.
    *   Location: `src/` (e.g., `src/extra.cpp`, `src/callbacks.cpp`).

## How to Contribute

### 1. Fixing/Improving Auto-generation
If you find a missing method or a bug in a generated function, try to fix it in the **Generator** first.

1.  Navigate to `generator/`.
2.  Modify `src/main.rs`.
3.  Run `cargo run` to regenerate the C++ code.
4.  Recompile `luasteam` to test.

Common generator tasks:
*   **Missing Array Counts:** If a method returns an array but lacks size metadata, add it to `fix_missing_array_count` in `main.rs`.
*   **Unsupported Types:** Implement support for new types in `resolve_type`, `generate_check` (input), and `generate_push` (output).

### 2. Adding Manual Bindings
If a method is too complex for the generator (e.g., requires custom logic or unsupported types like function pointers), you can implement it manually.

1.  **Blocklist it:** Add the method name to `method_blocklist` in `generator/src/main.rs` to prevent auto-generation attempts.
2.  **Implement it:** Add the C++ implementation in a file in `src/` (e.g., `src/manual.cpp`).
3.  **Register it:** Ensure your new function is registered in `src/main.cpp` or the relevant initialization function.

### 3. Documentation
The documentation is built with Sphinx. Since the API now closely mirrors the Steamworks C++ API:
*   Function names match the C++ names (e.g., `ISteamFriends::GetFriendGamePlayed`).
*   Structs match the C++ struct names.
*   Enums and Constants are available as `luasteam.EnumName` / `luasteam.ConstantName`.

Please help us keep the docs updated in `docs/`.

## Building

### Prerequisites
*   **Rust:** Required to run the generator.
*   **Steamworks SDK:** Download and extract into the project root (folder `sdk`).
*   **LuaJIT:** Clone the submodule (`git submodule update --init`).

### Steps
1.  **Generate:** `cd generator && cargo run`
2.  **Compile:**
    *   **Linux:** `make linux64`
    *   **Windows:** `mingw32-make win64` (using MSYS2/MinGW)
    *   **macOS:** `make osx`

## Style Guide
*   **Lua API:** 1:1 mapping to C++. If C++ is `ISteamUser::GetAuthSessionTicket`, Lua is `Steam.User.GetAuthSessionTicket`.
*   **Parameters:** Match C++ order and types.
*   **Outputs:** Output parameters in C++ are returned as multiple return values in Lua.
    *   Example: `GetAuthSessionTicket` returns `handle, ticket_buffer, ticket_size`.

## Resources
*   [Steam API Reference](https://partner.steamgames.com/doc/api)
*   [Lua C API Overview](https://www.lua.org/manual/5.1/manual.html#3)
