use crate::cpp_type::CppType;
use crate::schema::{Enum, Typedef};
use std::collections::HashMap;

#[derive(Clone)]
pub struct TypeResolver {
    type_map: HashMap<String, String>,
}

impl TypeResolver {
    /// Creates a TypeResolver from scratch, building the type_map from API data.
    pub fn from_api(
        typedefs: &[Typedef],
        enums: &[Enum],
        interface_enums: &[(String, Vec<Enum>)],
    ) -> Self {
        let mut type_map = HashMap::new();

        // Add typedefs
        for td in typedefs {
            type_map.insert(td.typedef.clone(), td.type_name.clone());
        }

        // Add global enums
        for enm in enums {
            type_map.insert(enm.enumname.clone(), "int".to_string());
        }

        // Add interface enums
        for (_, enums) in interface_enums {
            for enm in enums {
                type_map.insert(enm.enumname.clone(), "int".to_string());
                for value in &enm.values {
                    if !value.fqname.is_empty() {
                        type_map.insert(value.fqname.clone(), "int".to_string());
                    }
                }
            }
        }

        // Add basic types
        type_map.insert("int".to_string(), "int".to_string());
        type_map.insert("int32".to_string(), "int".to_string());
        type_map.insert("uint32".to_string(), "int".to_string());
        type_map.insert("unsigned int".to_string(), "int".to_string());
        type_map.insert("uint16".to_string(), "int".to_string());
        type_map.insert("short".to_string(), "int".to_string());
        type_map.insert("unsigned short".to_string(), "int".to_string());
        type_map.insert("uint64".to_string(), "uint64".to_string());
        type_map.insert("int64_t".to_string(), "uint64".to_string());
        type_map.insert("int64".to_string(), "uint64".to_string());
        type_map.insert("bool".to_string(), "bool".to_string());
        type_map.insert("const char *".to_string(), "const char *".to_string());
        type_map.insert("double".to_string(), "double".to_string());

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

    /// Resolves a C++ type to a structured CppType, handling arrays and pointers.
    pub fn resolve_type<'a>(&'a self, t: &'a str) -> CppType<'a> {
        if t.ends_with("]") {
            let start_bracket = t.rfind('[').expect("Malformed array type");
            let size_str = &t[start_bracket + 1..t.len() - 1];
            let _size = size_str.parse::<usize>().expect("Malformed size");
            let (ttype, is_const) = if t.starts_with("const ") {
                (t["const ".len()..start_bracket].trim(), true)
            } else {
                (t[..start_bracket].trim(), false)
            };
            return CppType::Array {
                ttype: self.resolve_base_type(ttype),
                size: size_str,
                is_const,
            };
        }

        if let Some(stripped) = t.strip_suffix("*") {
            let (ttype, is_const) = if let Some(const_stripped) = stripped.strip_prefix("const ") {
                (const_stripped.trim(), true)
            } else {
                (stripped.trim(), false)
            };
            return CppType::Pointer {
                ttype: self.resolve_base_type(ttype),
                is_const,
            };
        }

        CppType::Normal(self.resolve_base_type(t))
    }
}
