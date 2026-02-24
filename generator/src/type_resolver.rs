use crate::cpp_type::CppType;
use crate::schema::{Enum, Typedef};
use std::collections::{HashMap, HashSet};

#[derive(Clone)]
pub struct TypeResolver {
    type_map: HashMap<String, String>,
    opaque_handles: HashSet<String>,
}

impl TypeResolver {
    /// Creates a TypeResolver from scratch, building the type_map from API data.
    pub fn from_api(
        typedefs: &[Typedef],
        enums: &[Enum],
        interface_enums: &[(String, Vec<Enum>)],
    ) -> Self {
        let mut type_map = HashMap::new();
        let mut opaque_handles = HashSet::new();

        // Add typedefs — void* typedefs become opaque handles (self-referential, break the chain)
        for td in typedefs {
            if td.type_name == "void *" {
                type_map.insert(td.typedef.clone(), td.typedef.clone());
                opaque_handles.insert(td.typedef.clone());
            } else {
                type_map.insert(td.typedef.clone(), td.type_name.clone());
            }
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
        type_map.insert("unsigned long long".to_string(), "uint64".to_string());
        type_map.insert("int64".to_string(), "uint64".to_string());
        type_map.insert("bool".to_string(), "bool".to_string());
        type_map.insert("const char *".to_string(), "const char *".to_string());
        type_map.insert("double".to_string(), "double".to_string());

        Self {
            type_map,
            opaque_handles,
        }
    }

    /// Returns the set of opaque handle type names (void* typedefs).
    pub fn opaque_handles(&self) -> &HashSet<String> {
        &self.opaque_handles
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

        if let Some(stripped) = t.strip_suffix(" &") {
            let (ttype, is_const) = if let Some(const_stripped) = stripped.strip_prefix("const ") {
                (const_stripped.trim(), true)
            } else {
                (stripped.trim(), false)
            };
            return CppType::Reference {
                ttype: self.resolve_base_type(ttype),
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
