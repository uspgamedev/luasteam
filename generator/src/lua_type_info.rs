/// Represents the Lua type of a parameter or return value.
#[derive(Debug, Clone, PartialEq, Eq)]
pub enum LType {
    /// Integer type (int, uint32, enums, etc.)
    Integer,
    /// Floating-point type (float, double)
    Float,
    /// Boolean type
    Boolean,
    /// String type
    String,
    /// String with a single character
    Char,
    /// Table/struct type
    Table,
    /// 64-bit unsigned integer (CSteamID, CGameID, uint64)
    Uint64,
    /// Array type
    Array(Box<LType>),
    CallresultCallback {
        struct_t: String,
    }, // Represents a callback parameter for callresult methods
    /// Arbitrary userdata (e.g. SteamNetworkingIdentity)
    Userdata(String),
    /// Opaque pointer handle (e.g. HServerListRequest) — Lua lightuserdata
    LightUserdata(String),
}

impl LType {
    /// Returns the LuaLS type annotation string
    pub fn to_luals_string(&self) -> String {
        match self {
            LType::Integer => "integer".to_string(),
            LType::Float => "number".to_string(),
            LType::Boolean => "boolean".to_string(),
            LType::String => "string".to_string(),
            LType::Char => "string".to_string(),
            LType::Table => "table".to_string(),
            LType::Uint64 => "uint64".to_string(),
            LType::Array(inner) => format!("{}[]", inner.to_luals_string()),
            LType::CallresultCallback { struct_t: _ } => {
                // We can use the struct_t name once we have those types
                "fun(data: table?, io_fail: boolean)?".to_string()
            }
            LType::Userdata(name) => name.to_string(),
            LType::LightUserdata(name) => name.to_string(),
        }
    }

    /// Returns the Lua documentation reference string as an RST link (for Sphinx docs).
    /// Struct types become :ref: cross-references; other types are plain text.
    pub fn to_rst_link(&self, structs: &[crate::schema::Struct]) -> String {
        match self {
            LType::Userdata(name) => format!(":ref:`{} <struct-{}>`", name, name),
            // Use `\ ` between the role and `[]` to avoid docutils inline-markup parser confusion
            // when `[]` immediately follows a `:ref:` closing backtick.
            LType::Array(inner) => {
                let inner_str = inner.to_rst_link(structs);
                if inner_str.contains(":ref:") {
                    format!("{}\\ []", inner_str)
                } else {
                    format!("{}[]", inner_str)
                }
            }
            _ => self.to_lua_doc_reference(structs),
        }
    }

    /// Returns the Lua documentation reference string (for Sphinx docs)
    pub fn to_lua_doc_reference(&self, _structs: &[crate::schema::Struct]) -> String {
        match self {
            LType::Integer => "int".to_string(),
            LType::Float => "float".to_string(),
            LType::Boolean => "bool".to_string(),
            LType::String => "str".to_string(),
            LType::Char => "str".to_string(),
            LType::Table => {
                // Check if this is a struct type
                "table".to_string()
            }
            LType::Uint64 => "uint64".to_string(),
            LType::Array(inner) => format!("{}[]", inner.to_lua_doc_reference(_structs)),
            LType::CallresultCallback { struct_t: _ } => "function".to_string(),
            LType::Userdata(name) => name.to_string(),
            LType::LightUserdata(name) => name.to_string(),
        }
    }
}

/// Metadata about a single parameter or return value type in Lua.
#[derive(Debug, Clone)]
pub struct LuaTypeInfo {
    /// The Lua type
    pub ltype: LType,
    /// The name of the parameter
    pub name: String,
    /// If this param is a size/count for array param(s), stores (array_param_names, is_output).
    /// is_output=true: sizes an output buffer (return value); is_output=false: sizes input array(s).
    pub size_of: Option<(Vec<String>, bool)>,
    /// Whether this parameter accepts nil (mapped to nullptr / 0 in C++).
    pub is_optional: bool,
    /// Original C++ type name when it's a named typedef (e.g. AppId_t, EResult) mapped to a
    /// simpler Lua type. None for primitive types that need no further clarification.
    pub cpp_type_name: Option<String>,
}

/// Signature metadata for a Lua method, capturing type information determined during C++ generation.
#[derive(Debug, Clone, Default)]
pub struct LuaMethodSignature {
    /// Type info for each parameter (in order)
    pub params: Vec<LuaTypeInfo>,
    /// Type info for the return value (if method returns non-void)
    pub return_type: Option<LType>,
    /// Which parameters are output parameters (by parameter name)
    pub output_params: Vec<LuaTypeInfo>,
    /// Original C++ method name, if the Lua name differs (e.g. overload with type suffix).
    /// e.g. `GetUserStat` when the Lua name is `GetUserStatInt32`.
    pub original_cpp_name: Option<String>,
    /// True when the C++ return type is SteamAPICall_t (the async call handle).
    pub returns_steam_api_call: bool,
    /// The original C++ return type name when it's a named typedef (e.g. HServerQuery, EResult,
    /// AppId_t) that gets mapped to a simpler Lua type like int or uint64.
    pub return_cpp_type: Option<String>,
}

impl LuaMethodSignature {
    pub fn add_param(&mut self, name: String, ltype: LType) {
        self.params.push(LuaTypeInfo {
            name,
            ltype,
            size_of: None,
            is_optional: false,
            cpp_type_name: None,
        });
    }
    /// Mark the most recently added parameter as optional (accepts nil → nullptr/0).
    pub fn mark_last_param_optional(&mut self) {
        self.params
            .last_mut()
            .expect("No params added yet")
            .is_optional = true;
    }
    /// Set the C++ typedef name on the most recently added parameter.
    pub fn mark_last_param_cpp_type(&mut self, cpp_type: String) {
        self.params
            .last_mut()
            .expect("No params added yet")
            .cpp_type_name = Some(cpp_type);
    }
    pub fn set_return_type(&mut self, ltype: LType) {
        assert!(self.return_type.is_none(), "Return type already set");
        self.return_type = Some(ltype);
    }
    pub fn add_output_param(&mut self, name: String, ltype: LType) {
        self.output_params.push(LuaTypeInfo {
            name,
            ltype,
            size_of: None,
            is_optional: false,
            cpp_type_name: None,
        });
    }
    /// Add a size/count parameter that describes the length of another array param.
    /// `array_names`: names of the array param(s) this sizes (one or more).
    /// `is_output`: true if the array is an output (return value), false if input.
    pub fn add_size_param(
        &mut self,
        name: String,
        ltype: LType,
        array_names: Vec<String>,
        is_output: bool,
    ) {
        self.params.push(LuaTypeInfo {
            name,
            ltype,
            size_of: Some((array_names, is_output)),
            is_optional: false,
            cpp_type_name: None,
        });
    }

    /// Append an array name to an already-registered size param (for output arrays sharing a size).
    pub fn append_to_size_param(&mut self, size_name: &str, array_name: String) {
        let p = self.params.iter_mut().find(|p| p.name == size_name).expect("size param not found");
        p.size_of.as_mut().expect("not a size param").0.push(array_name);
    }

    /// Mark an already-added normal param as the size/count for the given input array.
    /// If already marked as a size param, appends the array name.
    pub fn mark_param_as_size_for(&mut self, size_name: &str, array_name: String) {
        let p = self.params.iter_mut().find(|p| p.name == size_name).expect("param not found");
        match &mut p.size_of {
            None => p.size_of = Some((vec![array_name], false)),
            Some((names, _)) => names.push(array_name),
        }
    }

    /// Formats the Lua method signature as a comment string, e.g.
    /// `// (int, str) apps.GetLaunchCommandLine(cubCommandLine: int)`
    pub fn to_lua_comment(&self, interface: &str, method_name: &str) -> String {
        let structs = [];
        // Build return list: return type first, then output params
        let mut returns: Vec<String> = Vec::new();
        if let Some(rt) = &self.return_type {
            returns.push(rt.to_lua_doc_reference(&structs));
        }
        for p in &self.output_params {
            returns.push(format!(
                "{}: {}",
                p.name,
                p.ltype.to_lua_doc_reference(&structs)
            ));
        }
        let returns_str = if returns.is_empty() {
            String::new()
        } else if returns.len() == 1 {
            format!("{} ", returns[0])
        } else {
            format!("({}) ", returns.join(", "))
        };

        // Build input params list
        let params_str = self
            .params
            .iter()
            .map(|p| format!("{}: {}", p.name, p.ltype.to_lua_doc_reference(&structs)))
            .collect::<Vec<_>>()
            .join(", ");

        format!(
            "// {}{}.{}({})",
            returns_str, interface, method_name, params_str
        )
    }
}
