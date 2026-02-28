use super::Generator;
use crate::code_builder::CodeBuilder;
use crate::cpp_type::CppType;
use crate::lua_type_info::LType;
use crate::COUNTER;

impl Generator {
    /// Generate code to check a lua value and convert it to a C++ type, returning the generated code and the Lua type info.
    pub(crate) fn generate_check(
        &self,
        original_type: &str,
        resolved: CppType<'_>,
        create_var: bool,
        value_accessor: &str,
        lua_idx: &str,
        indent: usize,
    ) -> Option<(String, LType)> {
        let mut out = CodeBuilder::with_indent(indent);
        let type_prefix = if create_var {
            format!("{} ", original_type)
        } else {
            String::new()
        };
        let ltype = match resolved {
            CppType::Normal(type_name) => match type_name {
                "int" | "unsigned char" => {
                    out.line(&format!(
                        "{}{} = static_cast<{}>(luaL_checkint(L, {}));",
                        type_prefix, value_accessor, original_type, lua_idx
                    ));
                    LType::Integer
                }
                "char" => {
                    out.line(&format!(
                        "{}{} = static_cast<{}>(luaL_checkstring(L, {})[0]);",
                        type_prefix, value_accessor, original_type, lua_idx
                    ));
                    LType::String
                }
                "bool" => {
                    out.line(&format!(
                        "{}{} = lua_toboolean(L, {});",
                        type_prefix, value_accessor, lua_idx
                    ));
                    LType::Boolean
                }
                "double" | "float" => {
                    out.line(&format!(
                        "{}{} = static_cast<{}>(luaL_checknumber(L, {}));",
                        type_prefix, value_accessor, original_type, lua_idx
                    ));
                    LType::Float
                }
                "uint64" | "unsigned long long" | "CSteamID" | "CGameID" => {
                    let mut get = format!("luasteam::checkuint64(L, {})", lua_idx);
                    if type_name == "CSteamID" || type_name == "CGameID" {
                        get = format!("{}({})", type_name, get);
                    }
                    out.line(&format!("{}{} = {};", type_prefix, value_accessor, get));
                    LType::Uint64
                }
                _ => {
                    if self.opaque_handles.contains(type_name) {
                        out.line(&format!(
                            "{}{} = ({})lua_touserdata(L, {});",
                            type_prefix, value_accessor, type_name, lua_idx
                        ));
                        LType::LightUserdata(type_name.to_string())
                    } else if self.added_structs.contains(type_name) {
                        out.line(&format!(
                            "{}{} = luasteam::check_{}(L, {});",
                            type_prefix, value_accessor, type_name, lua_idx
                        ));
                        LType::Userdata(type_name.to_string())
                    } else {
                        return None;
                    }
                }
            },
            CppType::Pointer {
                ttype,
                is_const: true,
            } if resolved.is_buffer() => {
                let mut get = format!("luaL_checkstring(L, {lua_idx})");
                if ttype != "char" {
                    get = format!("reinterpret_cast<const {ttype} *>({get})");
                }
                if create_var {
                    out.line(&format!("const {ttype} *{value_accessor} = {get};",));
                } else {
                    // If not creating a var, we need to copy the existing string to a new buffer.
                    out.line(&format!(
                        "luasteam::copy_str_into({value_accessor}, {get});"
                    ));
                }
                LType::String
            }
            CppType::Array {
                ttype,
                size,
                is_const: _,
            } => {
                return self.generate_array_check(
                    ttype,
                    resolved.is_buffer(),
                    create_var,
                    value_accessor,
                    lua_idx,
                    out,
                    size,
                    false,
                );
            }
            _ => {
                out.line(&format!("// Unsupported check type: {:?}", resolved));
                return None;
            }
        };
        Some((out.finish(), ltype))
    }

    pub(crate) fn generate_array_check(
        &self,
        ttype: &str,
        is_buffer: bool,
        create_var: bool,
        value_accessor: &str,
        lua_idx: &str,
        mut out: CodeBuilder,
        size: &str,
        non_const_exception: bool,
    ) -> Option<(String, LType)> {
        let ltype = if is_buffer {
            let var = format!(
                "_tmp{}",
                COUNTER.fetch_add(1, std::sync::atomic::Ordering::SeqCst)
            );
            let len_var = format!("_len_{}", var);
            out.line(&format!("size_t {};", len_var));
            out.line(&format!(
                "const char *{} = luaL_checklstring(L, {}, &{});",
                var, lua_idx, len_var
            ));

            if create_var {
                // Method input buffer: use lua_tolstring for the actual byte length.
                // This avoids reading past the end of the Lua string (which memcpy would
                // do if cubData > actual string length) and handles binary data (embedded
                // nulls that strlen would miss). The pointer is passed directly to Steam —
                // no copy needed since Lua keeps strings alive on the stack.
                // We use const_cast to a non-const pointer so this works for both
                // `const T*` and `T*` method signatures (some Steam APIs lack const).
                if ttype == "char" {
                    assert!(!non_const_exception);
                    out.line(&format!("const char *{} = {};", value_accessor, var));
                } else {
                    if non_const_exception {
                        out.line(&format!(
                            "{t} *{n} = const_cast<{t} *>(reinterpret_cast<const {t} *>({v}));",
                            t = ttype,
                            n = value_accessor,
                            v = var
                        ));
                    } else {
                        out.line(&format!(
                            "const {t} *{n} = reinterpret_cast<const {t} *>({v});",
                            t = ttype,
                            n = value_accessor,
                            v = var
                        ));
                    }
                }
            } else {
                out.line(&format!(
                    "if ({} > sizeof({})) luaL_error(L, \"String too long\");",
                    len_var, value_accessor
                ));
                out.line(&format!(
                    "memcpy({}, {}, std::min({} + 1, sizeof({})));",
                    value_accessor, var, len_var, value_accessor
                ));
            }
            LType::String
        } else {
            assert!(!size.is_empty());
            out.line(&format!("luaL_checktype(L, {}, LUA_TTABLE);", lua_idx));
            if create_var {
                out.line(&format!(
                    "std::vector<{}> {}({});",
                    ttype, value_accessor, size
                ));
            }
            out.line(&format!(
                "for(decltype({}) i = 0; i < {}; i++) {{",
                size, size
            ));
            out.indent_right();
            out.line(&format!("lua_rawgeti(L, {lua_idx}, i+1);"));
            let (check, elem_ltype) = self.generate_check(
                ttype,
                self.type_resolver.resolve_type(ttype),
                false,
                &format!("{}[i]", value_accessor),
                "-1",
                out.indent(),
            )?;
            out.raw(&check);
            out.line("lua_pop(L, 1);");
            out.indent_left();
            out.line("}");
            LType::Array(Box::new(elem_ltype))
        };
        Some((out.finish(), ltype))
    }

    pub(crate) fn generate_push(
        &self,
        ftype: &str,
        value_accessor: &str,
        indent: usize,
    ) -> (bool, String, LType) {
        let resolved = self.type_resolver.resolve_type(ftype);

        let (push, ltype) = match resolved {
            CppType::Normal(s) => match s {
                "double" | "float" => (
                    format!("lua_pushnumber(L, {});", value_accessor),
                    LType::Float,
                ),
                "bool" => (
                    format!("lua_pushboolean(L, {});", value_accessor),
                    LType::Boolean,
                ),
                "int" | "unsigned char" => (
                    format!("lua_pushinteger(L, {});", value_accessor),
                    LType::Integer,
                ),
                "uint64" | "unsigned long long" | "CSteamID" | "CGameID" => {
                    let push = if ftype == "CSteamID" {
                        format!(
                            "luasteam::pushuint64(L, {}.ConvertToUint64());",
                            value_accessor
                        )
                    } else if ftype == "CGameID" {
                        format!("luasteam::pushuint64(L, {}.ToUint64());", value_accessor)
                    } else {
                        format!("luasteam::pushuint64(L, {});", value_accessor)
                    };
                    (push, LType::Uint64)
                }
                _ => {
                    if self.opaque_handles.contains(s) {
                        (
                            format!("lua_pushlightuserdata(L, (void*){});", value_accessor),
                            LType::LightUserdata(s.to_string()),
                        )
                    } else if self.added_structs.contains(s) {
                        (
                            format!("luasteam::push_{}(L, {});", s, value_accessor),
                            LType::Userdata(s.to_string()),
                        )
                    } else {
                        (
                            format!("// Skip unsupported type: {}", ftype),
                            LType::Integer, // ignored
                        )
                    }
                }
            },
            CppType::Array {
                ttype,
                size,
                is_const: _,
            } => {
                if resolved.is_buffer() {
                    (
                        format!(
                            "lua_pushlstring(L, reinterpret_cast<const char*>({}), {});",
                            value_accessor, size
                        ),
                        LType::String,
                    )
                } else if let Some((code, ltype)) =
                    self.push_array(ttype, value_accessor, size.to_string().as_str(), indent)
                {
                    return (true, code, ltype);
                } else {
                    (
                        format!("// Skip unsupported array type: {}", ftype),
                        LType::Integer, // ignored
                    )
                }
            }
            _ if resolved.is_buffer() => (
                format!(
                    "lua_pushstring(L, reinterpret_cast<const char*>({}));",
                    value_accessor
                ),
                LType::String,
            ),
            CppType::Pointer {
                ttype: "void",
                is_const: false,
            } => (
                format!("luasteam::pushvoid_ptr(L, {});", value_accessor),
                LType::Table, // Wrong, should be something else
            ),
            CppType::Reference { ttype, .. } => {
                if self.added_structs.contains(ttype) {
                    (
                        format!("luasteam::push_{}(L, {});", ttype, value_accessor),
                        LType::Userdata(ttype.to_string()),
                    )
                } else {
                    (
                        format!("// Skip unsupported reference type: {}", ftype),
                        LType::Integer,
                    )
                }
            }
            _ => (
                format!("// Skip unsupported type: {}", ftype),
                LType::Integer, // ignored
            ),
        };
        let ok = !push.starts_with("//");
        let mut out = CodeBuilder::with_indent(indent);
        out.line(&push);
        (ok, out.finish(), ltype)
    }

    pub(crate) fn push_array(
        &self,
        ttype: &str,
        value_accessor: &str,
        size: &str,
        indent: usize,
    ) -> Option<(String, LType)> {
        let mut s = CodeBuilder::with_indent(indent);

        s.line(&format!("lua_createtable(L, {}, 0);", size));
        s.indent_right();
        let (ok, push, ltype) =
            self.generate_push(ttype, &format!("{}[i]", value_accessor), s.indent());
        s.indent_left();
        if ok {
            s.line(&format!(
                "for(decltype({}) i = 0; i < {}; i++) {{",
                size, size
            ));
            s.indent_right();
            if !push.is_empty() {
                s.raw(&push);
            }
            s.line("lua_rawseti(L, -2, i+1);");
            s.indent_left();
            s.line("}");
        } else {
            // Don't print, just return None
            return None;
        }
        Some((s.finish(), LType::Array(Box::new(ltype))))
    }
}
