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
                format!("fun(data: table?, io_fail: boolean)?")
            }
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
}

impl LuaMethodSignature {
    pub fn add_param(&mut self, name: String, ltype: LType) {
        self.params.push(LuaTypeInfo { name, ltype });
    }
    pub fn set_return_type(&mut self, ltype: LType) {
        assert!(self.return_type.is_none(), "Return type already set");
        self.return_type = Some(ltype);
    }
    pub fn add_output_param(&mut self, name: String, ltype: LType) {
        self.output_params.push(LuaTypeInfo { name, ltype });
    }
}
