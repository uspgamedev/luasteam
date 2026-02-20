use std::collections::HashMap;

pub struct TypeResolver {
    type_map: HashMap<String, String>,
}

impl TypeResolver {
    pub fn new(type_map: HashMap<String, String>) -> Self {
        Self { type_map }
    }

    /// Resolves a C++ type to its base type through the type_map.
    /// Handles const qualifiers and follows typedef chains.
    pub fn resolve_base_type<'a>(&'a self, mut t: &'a str) -> &'a str {
        // Strip const prefix
        t = t.strip_prefix("const ").unwrap_or(t).trim();
        
        // Follow the typedef chain
        while let Some(resolved) = self.type_map.get(t) {
            if *resolved == t {
                break;
            }
            t = resolved;
        }
        t
    }

    /// Maps a C++ type to its Lua representation.
    pub fn to_lua_type(&self, cpp_type: &str) -> &str {
        let resolved = self.resolve_base_type(cpp_type);

        match resolved {
            "bool" => "boolean",
            "int" | "int32" | "uint32" | "unsigned int" | "uint16" | "short" | "unsigned short" => {
                "number"
            }
            "uint64" | "int64" | "int64_t" | "unsigned long long" | "long long" => "uint64",
            "const char *" => "string",
            "float" | "double" => "number",
            _ => {
                if resolved.ends_with(" *") {
                    "table"
                } else if resolved.starts_with("E") {
                    "number" // Enums
                } else {
                    "table"
                }
            }
        }
    }
}
