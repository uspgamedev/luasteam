use std::fs;
use std::path::Path;

use crate::code_builder::CodeBuilder;
use crate::schema::{CallbackStruct, Interface, Method, Param};
use crate::type_resolver::TypeResolver;

pub struct LuaLsGenerator {
    type_resolver: TypeResolver,
}

impl LuaLsGenerator {
    pub fn new(type_resolver: TypeResolver) -> Self {
        Self { type_resolver }
    }

    pub fn write_index(&self, output_dir: &Path, interface_names: &[String]) {
        let path = output_dir.join("luasteam.d.lua");
        let content = self.generate_index(interface_names);
        fs::write(path, content).expect("Unable to write LuaLS index file");
    }

    pub fn write_interface(
        &self,
        output_dir: &Path,
        interface: &Interface,
        generated_methods: &[(&Method, String)],
        _callbacks: &[CallbackStruct],
    ) {
        let name = &interface.classname["ISteam".len()..];
        let file_name = format!("{}.d.lua", name.to_lowercase());
        let path = output_dir.join(file_name);
        let content = self.generate_interface(name, generated_methods);
        fs::write(path, content).expect("Unable to write LuaLS interface file");
    }

    fn generate_index(&self, interface_names: &[String]) -> String {
        let mut cb = CodeBuilder::new();

        cb.line("---@alias uint64 userdata");
        cb.line("---@alias SteamAPICall_t userdata");
        cb.preceeding_blank_line();
        cb.line("---@class Steam");
        cb.line("Steam = {}");
        cb.preceeding_blank_line();

        for name in interface_names {
            cb.line(&format!("Steam.{} = {{}}", name));
        }

        cb.finish()
    }

    fn generate_interface(&self, name: &str, generated_methods: &[(&Method, String)]) -> String {
        let mut cb = CodeBuilder::new();

        cb.line(&format!("---@class Steam.{}", name));
        cb.line(&format!("local {} = {{}}", name));
        cb.preceeding_blank_line();

        for (method, lua_method_name) in generated_methods {
            self.write_method(&mut cb, name, method, lua_method_name);
        }

        cb.line(&format!("Steam.{} = {}", name, name));
        cb.finish()
    }

    fn write_method(&self, cb: &mut CodeBuilder, name: &str, method: &Method, lua_method_name: &str) {
        for param in method.params.iter().filter(|p| !p.is_output_param()) {
            let lua_type = self.type_resolver.to_luals_type(&param.paramtype);
            cb.line(&format!("---@param {} {}", param.paramname, lua_type));
        }
        if let Some(callresult) = &method.callresult {
            let callback_type = self.callresult_callback_type(callresult);
            cb.line(&format!("---@param callback {}?", callback_type));
        }

        if method.returntype != "void" {
            let ret_type = self.type_resolver.to_luals_type(&method.returntype);
            cb.line(&format!("---@return {}", ret_type));
        }

        for param in method.params.iter().filter(|p| p.is_output_param()) {
            let out_type = self.output_param_type(param);
            cb.line(&format!("---@return {}", out_type));
        }

        let mut param_names = method
            .params
            .iter()
            .filter(|p| !p.is_output_param())
            .map(|p| p.paramname.as_str())
            .collect::<Vec<_>>();
        if method.callresult.is_some() {
            param_names.push("callback");
        }
        let params = param_names.join(", ");
        cb.line(&format!("function {}.{}({}) end", name, lua_method_name, params));
        cb.preceeding_blank_line();
    }

    fn callresult_callback_type(&self, callresult: &str) -> String {
        let data_type = self.type_resolver.to_luals_type(callresult);
        format!("fun(data: {}?, io_fail: boolean)", data_type)
    }

    fn output_param_type(&self, param: &Param) -> String {
        let base_type = param
            .paramtype
            .trim_start_matches("const ")
            .trim_end_matches(" *")
            .trim();
        self.type_resolver.to_luals_type(base_type).to_string()
    }

}

