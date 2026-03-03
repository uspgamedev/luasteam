use std::fs;
use std::path::Path;

use crate::code_builder::CodeBuilder;
use crate::doc_generator::{CallbackInterfaceDocInfo, StructDocInfo};
use crate::lua_type_info::LuaMethodSignature;
use crate::schema::{CallbackStruct, Const, Enum, Interface};

pub struct LuaLsGenerator;

impl LuaLsGenerator {
    pub fn new() -> Self {
        Self
    }

    pub fn write_index(
        &self,
        output_dir: &Path,
        interface_names: &[String],
        opaque_handles: &std::collections::HashSet<String>,
    ) {
        let path = output_dir.join("luasteam.d.lua");
        let content = self.generate_index(interface_names, opaque_handles);
        fs::write(path, content).expect("Unable to write LuaLS index file");
    }

    pub fn write_structs(&self, output_dir: &Path, structs: &[StructDocInfo<'_>]) {
        let path = output_dir.join("structs.d.lua");
        let content = self.generate_structs(structs);
        fs::write(path, content).expect("Unable to write LuaLS structs file");
    }

    pub fn write_interface(
        &self,
        output_dir: &Path,
        interface: &Interface,
        method_signatures: &[(String, LuaMethodSignature)],
        callbacks: &[CallbackStruct],
    ) {
        let name = &interface.classname["ISteam".len()..];
        let file_name = format!("{}.d.lua", name.to_lowercase());
        let path = output_dir.join(file_name);
        let content = self.generate_interface(name, method_signatures, callbacks);
        fs::write(path, content).expect("Unable to write LuaLS interface file");
    }

    /// Write a combined enums + constants file so IDE can autocomplete Steam.k_* values.
    pub fn write_enums_consts(&self, output_dir: &Path, enums: &[Enum], consts: &[Const]) {
        let path = output_dir.join("enums_consts.d.lua");
        let mut cb = CodeBuilder::new();

        // Extend the Steam class with all enum/const fields
        cb.line("---@class Steam");
        for enm in enums {
            for val in &enm.values {
                cb.line(&format!("---@field {} integer", val.name));
            }
        }
        for c in consts {
            cb.line(&format!("---@field {} integer", c.constname));
        }
        cb.preceeding_blank_line();

        fs::write(path, cb.finish()).expect("Unable to write LuaLS enums_consts file");
    }

    /// Write the Extra interface definition file.
    pub fn write_extra(&self, output_dir: &Path) {
        let path = output_dir.join("extra.d.lua");
        let mut cb = CodeBuilder::new();
        cb.line("---@class Steam.Extra");
        cb.line("local Extra = {}");
        cb.preceeding_blank_line();
        cb.line("---@param value integer|string");
        cb.line("---@return uint64");
        cb.line("function Extra.ParseUint64(value) end");
        cb.preceeding_blank_line();
        cb.line("Steam.Extra = Extra");
        fs::write(path, cb.finish()).expect("Unable to write LuaLS extra file");
    }

    fn generate_index(
        &self,
        interface_names: &[String],
        opaque_handles: &std::collections::HashSet<String>,
    ) -> String {
        let mut cb = CodeBuilder::new();

        cb.line("---@alias uint64 userdata");
        cb.line("---@alias SteamAPICall_t userdata");
        let mut sorted_handles: Vec<&String> = opaque_handles.iter().collect();
        sorted_handles.sort();
        for handle in sorted_handles {
            cb.line(&format!("---@alias {} userdata", handle));
        }
        cb.preceeding_blank_line();
        cb.line("---@class Steam");
        cb.line("Steam = {}");
        cb.preceeding_blank_line();

        // Core functions (manually implemented in Core.cpp and GameServer.cpp)
        cb.line("---@return boolean");
        cb.line("function Steam.Init() end");
        cb.preceeding_blank_line();
        cb.line("function Steam.Shutdown() end");
        cb.preceeding_blank_line();
        cb.line("function Steam.RunCallbacks() end");
        cb.preceeding_blank_line();
        cb.line("---@param unIP integer");
        cb.line("---@param usGamePort integer");
        cb.line("---@param usQueryPort integer");
        cb.line("---@param eServerMode integer");
        cb.line("---@param pchVersionString string");
        cb.line("---@return boolean");
        cb.line("function Steam.GameServerInit(unIP, usGamePort, usQueryPort, eServerMode, pchVersionString) end");
        cb.preceeding_blank_line();
        cb.line("function Steam.GameServerShutdown() end");
        cb.preceeding_blank_line();
        cb.line("function Steam.GameServerRunCallbacks() end");
        cb.preceeding_blank_line();

        // Extra interface (manually implemented)
        cb.line("Steam.Extra = {}");
        cb.preceeding_blank_line();

        for name in interface_names {
            cb.line(&format!("Steam.{} = {{}}", name));
        }

        cb.finish()
    }

    fn generate_structs(&self, structs: &[StructDocInfo<'_>]) -> String {
        let mut cb = CodeBuilder::new();

        for st in structs {
            // Class definition with fields
            cb.line(&format!("---@class {}", st.name));
            for (fieldname, ltype) in st.readable_fields {
                cb.line(&format!(
                    "---@field {} {}",
                    fieldname,
                    ltype.to_luals_string()
                ));
            }
            // local declaration only needed if there are methods attached to it
            if !st.method_signatures.is_empty() {
                cb.line(&format!("local {} = {{}}", st.name));
            }
            cb.preceeding_blank_line();

            // Methods on the class
            for (lua_name, sig) in st.method_signatures {
                for param in &sig.params {
                    cb.line(&format!(
                        "---@param {} {}",
                        param.name,
                        param.ltype.to_luals_string()
                    ));
                }
                if let Some(ret) = &sig.return_type {
                    cb.line(&format!("---@return {}", ret.to_luals_string()));
                }
                let params = sig
                    .params
                    .iter()
                    .map(|p| p.name.as_str())
                    .collect::<Vec<_>>()
                    .join(", ");
                cb.line(&format!(
                    "function {}:{}({}) end",
                    st.name, lua_name, params
                ));
                cb.preceeding_blank_line();
            }

            // Constructor on Steam global
            cb.line("---@param table table?");
            cb.line(&format!("---@return {}", st.name));
            cb.line(&format!("function Steam.new{}(table) end", st.name));
            cb.preceeding_blank_line();
        }

        cb.finish()
    }

    fn generate_interface(
        &self,
        name: &str,
        method_signatures: &[(String, LuaMethodSignature)],
        callbacks: &[CallbackStruct],
    ) -> String {
        let mut cb = CodeBuilder::new();

        cb.line(&format!("---@class Steam.{}", name));

        // Callback fields: users set these to functions to receive Steam callbacks.
        // They are optional (nil by default).
        for cb_struct in callbacks {
            let lua_name = Self::callback_field_name(&cb_struct.name);
            cb.line(&format!(
                "---@field {}? fun(data: {})",
                lua_name, cb_struct.name
            ));
        }

        cb.line(&format!("local {} = {{}}", name));
        cb.preceeding_blank_line();

        // Manual extra methods not emitted by the auto-generator
        if name == "Client" {
            cb.line("---@param hook fun(severity: integer, message: string)?");
            cb.line("function Client.SetWarningMessageHook(hook) end");
            cb.preceeding_blank_line();
        }

        for (lua_method_name, signature) in method_signatures {
            self.write_method(&mut cb, name, lua_method_name, signature);
        }

        cb.line(&format!("Steam.{} = {}", name, name));
        cb.finish()
    }

    /// Derive the Lua callback field name from the C++ callback struct name.
    /// E.g. `GameOverlayActivated_t` → `OnGameOverlayActivated`
    fn callback_field_name(struct_name: &str) -> String {
        format!("On{}", &struct_name[..struct_name.len() - 2])
    }

    fn write_method(
        &self,
        cb: &mut CodeBuilder,
        name: &str,
        lua_method_name: &str,
        signature: &LuaMethodSignature,
    ) {
        for param in signature.params.iter() {
            let type_str = if param.is_optional {
                format!("{}?", param.ltype.to_luals_string())
            } else {
                param.ltype.to_luals_string()
            };
            if let Some((array_names, is_output)) = &param.size_of {
                let desc = if *is_output {
                    let names_str = if array_names.len() == 1 {
                        array_names[0].clone()
                    } else {
                        array_names.join(", ")
                    };
                    if param.is_optional {
                        format!(
                            "size of the buffer for {}; if nil then the buffer will be NULL",
                            names_str
                        )
                    } else {
                        format!(
                            "size of the buffer to allocate for return value {}",
                            names_str
                        )
                    }
                } else if array_names.len() == 1 {
                    format!("size of the input array {}", array_names[0])
                } else {
                    format!("size of the input arrays {}", array_names.join(" and "))
                };
                cb.line(&format!("---@param {} {} {}", param.name, type_str, desc));
            } else if let Some(cpp_name) = &param.cpp_type_name {
                cb.line(&format!("---@param {} {} -- {}", param.name, type_str, cpp_name));
            } else {
                cb.line(&format!("---@param {} {}", param.name, type_str));
            }
        }

        if let Some(ret) = &signature.return_type {
            if signature.returns_steam_api_call {
                cb.line(&format!("---@return {} -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called", ret.to_luals_string()));
            } else if let Some(cpp_name) = &signature.return_cpp_type {
                cb.line(&format!("---@return {} -- {}", ret.to_luals_string(), cpp_name));
            } else {
                cb.line(&format!("---@return {}", ret.to_luals_string()));
            }
        }

        // Use signature data for output params if available
        for output_param in &signature.output_params {
            cb.line(&format!(
                "---@return {} -- Value of: {}",
                output_param.ltype.to_luals_string(),
                output_param.name
            ));
        }

        let params = signature
            .params
            .iter()
            .map(|p| p.name.as_str())
            .collect::<Vec<_>>()
            .join(", ");
        cb.line(&format!(
            "function {}.{}({}) end",
            name, lua_method_name, params
        ));
        cb.preceeding_blank_line();
    }

    pub fn write_callback_interfaces(
        &self,
        output_dir: &Path,
        interfaces: &[CallbackInterfaceDocInfo],
    ) {
        if interfaces.is_empty() {
            return;
        }
        let path = output_dir.join("callback_interfaces.d.lua");
        let mut cb = CodeBuilder::new();

        for iface in interfaces {
            let name = &iface.name;
            cb.line(&format!("---@class {}", name));
            for method in &iface.methods {
                let params_str: Vec<String> = method
                    .params
                    .iter()
                    .map(|p| format!("{}: {}", p.name, p.ltype.to_luals_string()))
                    .collect();
                cb.line(&format!(
                    "---@field {} fun({})",
                    method.name,
                    params_str.join(", ")
                ));
            }
            cb.line(&format!("local {} = {{}}", name));
            cb.preceeding_blank_line();

            // Constructor
            cb.line(&format!("---@param callbacks {}", name));
            cb.line(&format!("---@return {}", name));
            cb.line(&format!("function Steam.new{}(callbacks) end", name));
            cb.preceeding_blank_line();
        }

        fs::write(path, cb.finish()).expect("Unable to write LuaLS callback_interfaces file");
    }
}
