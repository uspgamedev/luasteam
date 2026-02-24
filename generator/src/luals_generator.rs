use std::fs;
use std::path::Path;

use crate::code_builder::CodeBuilder;
use crate::doc_generator::{CallbackInterfaceDocInfo, StructDocInfo};
use crate::lua_type_info::LuaMethodSignature;
use crate::schema::{CallbackStruct, Interface};

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
        _callbacks: &[CallbackStruct],
    ) {
        let name = &interface.classname["ISteam".len()..];
        let file_name = format!("{}.d.lua", name.to_lowercase());
        let path = output_dir.join(file_name);
        let content = self.generate_interface(name, method_signatures);
        fs::write(path, content).expect("Unable to write LuaLS interface file");
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
            cb.line(&format!("local {} = {{}}", st.name));
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
            cb.line(&format!("---@param table table?"));
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
    ) -> String {
        let mut cb = CodeBuilder::new();

        cb.line(&format!("---@class Steam.{}", name));
        cb.line(&format!("local {} = {{}}", name));
        cb.preceeding_blank_line();

        for (lua_method_name, signature) in method_signatures {
            self.write_method(&mut cb, name, lua_method_name, signature);
        }

        cb.line(&format!("Steam.{} = {}", name, name));
        cb.finish()
    }

    fn write_method(
        &self,
        cb: &mut CodeBuilder,
        name: &str,
        lua_method_name: &str,
        signature: &LuaMethodSignature,
    ) {
        for param in signature.params.iter() {
            cb.line(&format!(
                "---@param {} {}",
                param.name,
                param.ltype.to_luals_string()
            ));
        }

        if let Some(ret) = &signature.return_type {
            cb.line(&format!("---@return {}", ret.to_luals_string()));
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
