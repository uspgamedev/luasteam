# Auto-Generated Documentation Feature

## Overview
The generator now automatically creates RST documentation for all Steam API interfaces during code generation.

## Files Created

### Generator Files
- `generator/src/doc_generator.rs` - Core documentation generator module
- `generator/custom_docs.toml` - Custom documentation snippets (descriptions, examples, notes)

### Generated Output
- `docs/auto/*.rst` - Auto-generated RST files for each interface

## How It Works

1. **During Code Generation**: When running `cargo run` in the generator directory, the system:
   - Generates C++ bindings in `src/auto/`
   - Generates RST documentation in `docs/auto/`

2. **Documentation Includes**:
   - Function signatures with Lua-style parameters
   - Parameter types and descriptions
   - Return value documentation
   - Links to official SteamWorks API documentation
   - Signature differences from C++ API (automatically detected)
   - Coverage tracking (implemented vs. unimplemented methods)
   - Callback documentation

3. **Customization**: Edit `generator/custom_docs.toml` to add:
   - Method descriptions
   - Usage examples
   - Custom notes
   - Parameter descriptions

## Usage

### Running the Generator
```batch
# From repository root
.\run_generator.bat

# Or manually
cd generator
cargo build
cargo run
```

### Adding Custom Documentation
Edit `generator/custom_docs.toml`:

```toml
[ISteamUserStats.GetStat]
description = "Gets the current value of a stat for the current user."
notes = [
    "The stat must exist in App Admin on Steamworks",
    "For float stats, use GetStatFloat"
]
example = """
local success, value = Steam.userStats.getStat('kills')
if success then
    print('Total kills:', value)
end
"""
param_descriptions = { pchName = "The 'API Name' of the stat" }
```

### Building Documentation
```batch
cd docs
make html
# Or on Windows
.\make.bat html
```

## Features

### Automatic Signature Detection
The generator automatically detects and documents:
- Output parameters that become return values
- Array parameters that become Lua tables
- Multiple return values

### Example Generated Documentation
```rst
.. function:: userStats.getStat(name)

    🤖 **Auto-generated binding**
    
    :param string name: The 'API Name' of the stat
    :returns: (boolean) Success indicator
    :returns: (number) Value for pData
    :SteamWorks: `GetStat <https://partner.steamgames.com/doc/api/ISteamUserStats#GetStat>`_
    
    **Signature differences from C++ API:**
    
    * Parameter ``pData`` is returned as an additional return value (number)
```

## Integration with Sphinx

The auto-generated documentation integrates seamlessly with existing Sphinx documentation. 
The `docs/index.rst` file includes a new section for auto-generated docs.

## Benefits

- ✅ **Always up-to-date** - Regenerates with code
- ✅ **Consistent format** - All interfaces documented uniformly
- ✅ **Signature clarity** - Automatically documents Lua vs C++ differences
- ✅ **Coverage tracking** - Shows implementation status
- ✅ **Customizable** - Add examples and notes via TOML
