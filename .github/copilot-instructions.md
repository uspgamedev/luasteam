# luasteam Copilot Instructions

luasteam is a LuaJIT binding for the Steamworks API, compiled as a shared library (`.dll`/`.so`). It uses a **hybrid architecture**: most bindings are auto-generated from `steam_api.json` via a Rust generator, while complex cases are implemented manually in C++.

## Build Commands

Prerequisites: Steamworks SDK in `sdk/`, LuaJIT submodule (`git submodule update --init`), Rust (for generator).

```sh
# Regenerate C++ bindings from steam_api.json
cd generator && cargo run

# Compile (run from repo root)
make linux64          # Linux 64-bit
make osx              # macOS universal binary
mingw32-make win64    # Windows 64-bit (MSYS2/MinGW)

# Run integration test (after build)
make test-linux64
make test-win64
make test-osx
```

The test target runs `mwe/main-nolove.lua` via LuaJIT, which verifies the library loads and key enums/interfaces exist.

## Architecture

```
generator/          Rust code — reads sdk/steam_api.json, emits src/auto/*.cpp
src/auto/           AUTO-GENERATED C++ — never edit manually
src/*.cpp           Manual bindings for complex/unsupported cases
mwe/                Minimal working example used as integration test
docs/               Sphinx documentation
```

**Data flow:** `sdk/steam_api.json` → `generator/src/main.rs` → `src/auto/*.cpp` → compiled into `luasteam.dll`/`luasteam.so`.

**Module registration:** `src/main.cpp` → `luaopen_luasteam` is the DLL entry point. Every interface module has three functions called in lifecycle order: `add_*` (register Lua functions), `init_*` (called after `SteamAPI_Init`), `shutdown_*` (called before `SteamAPI_Shutdown`).

**Manual vs auto modules:** Manual modules (e.g., `src/friends.cpp`) call `register_Friends_auto(L)` inside their `add_*` function to blend auto-generated and manual functions into the same Lua table.

## Key Conventions

**Lua API naming:** 1:1 mapping to C++. `ISteamFriends::GetFriendCount` → `Steam.friends.GetFriendCount`. Interface name is lowercased as the Lua subtable key (e.g., `friends`, `user`, `userStats`).

**uint64 handling:** Lua numbers can't safely hold 64-bit integers. `uint64` values are represented as Lua userdata with `__eq` and `__tostring` metamethods. Use `luasteam::pushuint64` / `luasteam::checkuint64` in C++ code. Never pass them as plain numbers.

**Output parameters:** C++ out-params become multiple Lua return values. The return order mirrors the C++ parameter order for out-params.

**Callbacks vs CallResults:** Persistent callbacks use `STEAM_CALLBACK` macro (stored in interface structs). One-shot async results use `CCallResult<CallResultListener<T>, T>` — the listener `delete this` after firing.

**Adding a manual binding when the generator can't handle it:**
1. Add the flat API method name to `manual_method_blocklist()` in `generator/src/main.rs`.
2. Implement it in a `src/*.cpp` file.
3. Register it in the relevant `add_*` function.

**Clang-format:** 4-space indent, no column limit, `IndentPPDirectives: AfterHash`. Run clang-format before committing C++ changes.

**Generator extension points:**
- Missing array size metadata → add to `fix_missing_array_count` in `main.rs`.
- New C++ type support → implement in `resolve_type`, `generate_check`, and `generate_push`.
