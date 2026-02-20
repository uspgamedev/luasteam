use crate::schema::{CallbackStruct, Interface, Method, Param, SkipReason};
use serde::Deserialize;
use std::collections::HashMap;
use std::fs;

#[derive(Debug, Deserialize, Default)]
pub struct CustomDocs {
    #[serde(flatten)]
    pub methods: HashMap<String, CustomDoc>,
}

#[derive(Debug, Deserialize, Clone)]
pub struct CustomDoc {
    #[serde(default)]
    pub description: String,
    #[serde(default)]
    pub example: Option<String>,
    #[serde(default)]
    pub notes: Vec<String>,
    #[serde(default)]
    pub param_descriptions: HashMap<String, String>,
}

pub struct DocGenerator {
    custom_docs: CustomDocs,
    type_map: HashMap<String, String>,
}

impl DocGenerator {
    pub fn new(type_map: HashMap<String, String>) -> Self {
        let custom_docs = if let Ok(content) = fs::read_to_string("custom_docs.toml") {
            toml::from_str(&content).unwrap_or_default()
        } else {
            CustomDocs::default()
        };

        Self {
            custom_docs,
            type_map,
        }
    }

    pub fn generate_interface_doc(
        &self,
        interface: &Interface,
        generated_methods: &[(&Method, String)],
        skipped_methods: &[(String, SkipReason)],
        callbacks: &[CallbackStruct],
    ) -> String {
        let name = &interface.classname["ISteam".len()..];
        let lua_namespace = name;

        let mut doc = String::new();

        // Header
        let header = "#".repeat(interface.classname.len());
        doc.push_str(&format!("{}\n", header));
        doc.push_str(&format!("{}\n", interface.classname));
        doc.push_str(&format!("{}\n\n", header));

        doc.push_str(".. note::\n");
        doc.push_str("   This documentation is auto-generated. Methods marked with 🤖 are automatically generated bindings.\n");
        doc.push_str("   Methods marked with ✋ require manual implementation.\n\n");

        // List of Functions
        doc.push_str("List of Functions\n");
        doc.push_str("-----------------\n\n");
        for (method, _) in generated_methods {
            doc.push_str(&format!(
                "* :func:`{}.{}`\n",
                lua_namespace, method.methodname
            ));
        }
        doc.push_str("\n");

        // List of Callbacks
        if !callbacks.is_empty() {
            doc.push_str("List of Callbacks\n");
            doc.push_str("-----------------\n\n");
            for callback in callbacks {
                let callback_name = &callback.name.replace("_t", "");
                doc.push_str(&format!(
                    "* :func:`{}.on{}`\n",
                    lua_namespace, callback_name
                ));
            }
            doc.push_str("\n");
        }

        // Function Reference
        doc.push_str("Function Reference\n");
        doc.push_str("------------------\n\n");

        for (method, _) in generated_methods {
            doc.push_str(&self.generate_function_doc(
                method,
                &lua_namespace,
                &interface.classname,
                true,
            ));
        }

        // Skipped methods
        if !skipped_methods.is_empty() {
            doc.push_str("\nUnimplemented Methods\n");
            doc.push_str("---------------------\n\n");
            for (method_name, reason) in skipped_methods {
                // Extract just the method name without interface prefix
                let method_name_only = method_name.split("::").last().unwrap_or(method_name);
                let lua_method = Self::to_camel_case(method_name_only);
                doc.push_str(&format!(
                    ".. function:: {}.{}\n\n",
                    lua_namespace, lua_method
                ));
                doc.push_str(&format!(
                    "    ✋ **Not implemented** - {}\n",
                    reason.description()
                ));
                doc.push_str(&format!("    \n    :SteamWorks: `{} <https://partner.steamgames.com/doc/api/{}#{}>`_\n\n", 
                    method_name_only, interface.classname, method_name_only));
            }
        }

        // Callbacks
        if !callbacks.is_empty() {
            doc.push_str("\nCallbacks\n");
            doc.push_str("---------\n\n");
            for callback in callbacks {
                doc.push_str(&self.generate_callback_doc(callback, &lua_namespace));
            }
        }

        doc
    }

    fn generate_function_doc(
        &self,
        method: &Method,
        lua_namespace: &str,
        interface_name: &str,
        is_auto: bool,
    ) -> String {
        let lua_method_name = &method.methodname;
        let custom_key = format!("{}.{}", interface_name, method.methodname);
        let custom_doc = self.custom_docs.methods.get(&custom_key);

        let mut doc = String::new();

        // Build parameter list
        let params: Vec<String> = method
            .params
            .iter()
            .filter(|p| !self.is_output_param(p))
            .map(|p| p.paramname.clone())
            .collect();

        doc.push_str(&format!(
            ".. function:: {}.{}({})\n\n",
            lua_namespace,
            lua_method_name,
            params.join(", ")
        ));

        // Auto-generated marker
        if is_auto {
            doc.push_str("    🤖 **Auto-generated binding**\n\n");
        }

        // Parameters
        for param in &method.params {
            if self.is_output_param(param) {
                continue;
            }
            let lua_type = self.lua_type_name(&param.paramtype);

            let param_desc = custom_doc
                .and_then(|cd| cd.param_descriptions.get(&param.paramname))
                .map(|s| s.as_str())
                .unwrap_or("");

            if param_desc.is_empty() {
                doc.push_str(&format!("    :param {} {}:\n", lua_type, param.paramname));
            } else {
                doc.push_str(&format!(
                    "    :param {} {}: {}\n",
                    lua_type, param.paramname, param_desc
                ));
            }
        }

        // Return values
        let return_values = self.detect_return_values(method);
        for (idx, (ret_type, ret_desc)) in return_values.iter().enumerate() {
            if idx == 0 && return_values.len() == 1 {
                doc.push_str(&format!("    :returns: ({}) {}\n", ret_type, ret_desc));
            } else {
                doc.push_str(&format!("    :returns: ({}) {}\n", ret_type, ret_desc));
            }
        }

        // SteamWorks link
        doc.push_str(&format!(
            "    :SteamWorks: `{} <https://partner.steamgames.com/doc/api/{}#{}>`_\n\n",
            method.methodname, interface_name, method.methodname
        ));

        // Description
        if let Some(custom) = custom_doc {
            if !custom.description.is_empty() {
                doc.push_str(&format!("    {}\n\n", custom.description));
            }
        }

        // Signature differences
        let differences = self.detect_signature_differences(method);
        if !differences.is_empty() {
            doc.push_str("    **Signature differences from C++ API:**\n\n");
            for diff in &differences {
                doc.push_str(&format!("    * {}\n", diff));
            }
            doc.push_str("\n");
        }

        // Custom notes
        if let Some(custom) = custom_doc {
            if !custom.notes.is_empty() {
                doc.push_str("    **Notes:**\n\n");
                for note in &custom.notes {
                    doc.push_str(&format!("    * {}\n", note));
                }
                doc.push_str("\n");
            }
        }

        // Example
        if let Some(custom) = custom_doc {
            if let Some(example) = &custom.example {
                doc.push_str("**Example**::\n\n");
                for line in example.lines() {
                    doc.push_str(&format!("    {}\n", line));
                }
                doc.push_str("\n");
            }
        }

        doc
    }

    fn generate_callback_doc(&self, callback: &CallbackStruct, lua_namespace: &str) -> String {
        let callback_name = &callback.name.replace("_t", "");
        let mut doc = String::new();

        doc.push_str(&format!(
            ".. function:: {}.on{}\n\n",
            lua_namespace, callback_name
        ));
        doc.push_str(&format!(
            "    Callback for `{} <https://partner.steamgames.com/doc/api/steam_api#{}>`_\n\n",
            callback.name, callback.name
        ));
        doc.push_str("    **callback(data)** receives:\n\n");

        for field in &callback.fields {
            let lua_type = self.lua_type_name(&field.fieldtype);
            doc.push_str(&format!(
                "    * **data.{}** ({}) -- {}\n",
                field.fieldname, lua_type, field.fieldname
            ));
        }
        doc.push_str("\n");

        doc
    }

    fn is_output_param(&self, param: &Param) -> bool {
        param.paramtype.ends_with(" *")
            && !param.paramtype.starts_with("const")
            && param.out_string_count.is_none()
            && param.array_count.is_none()
    }

    fn detect_return_values(&self, method: &Method) -> Vec<(String, String)> {
        let mut returns = Vec::new();

        // Main return value
        if method.returntype != "void" {
            let lua_type = self.lua_type_name(&method.returntype);
            returns.push((lua_type.to_string(), "Return value".to_string()));
        }

        // Output parameters become additional return values
        for param in &method.params {
            if self.is_output_param(param) {
                let base_type = param.paramtype.trim_end_matches(" *");
                let lua_type = self.lua_type_name(base_type);
                returns.push((
                    lua_type.to_string(),
                    format!("Value for `{}`", param.paramname),
                ));
            }
        }

        returns
    }

    fn detect_signature_differences(&self, method: &Method) -> Vec<String> {
        let mut differences = Vec::new();

        // Check for output parameters that become return values
        for param in &method.params {
            if self.is_output_param(param) {
                let base_type = param.paramtype.trim_end_matches(" *");
                let lua_type = self.lua_type_name(base_type);
                differences.push(format!(
                    "Parameter ``{}`` is returned as an additional return value ({})",
                    param.paramname, lua_type
                ));
            }

            // Check for array parameters
            if param.array_count.is_some() {
                differences.push(format!(
                    "Parameter ``{}`` is passed as a Lua table instead of array+size",
                    param.paramname
                ));
            }

            if param.out_array_count.is_some() {
                differences.push(format!(
                    "Parameter ``{}`` returns as a Lua table",
                    param.paramname
                ));
            }
        }

        differences
    }

    fn lua_type_name(&self, cpp_type: &str) -> &str {
        let resolved = self.resolve_type(cpp_type);

        match resolved {
            "bool" => "boolean",
            "int" | "int32" | "uint32" | "unsigned int" | "uint16" | "short" | "unsigned short" => {
                "number"
            }
            "uint64" | "int64" | "int64_t" => "uint64",
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

    fn resolve_type<'a>(&'a self, ttype: &'a str) -> &'a str {
        self.type_map
            .get(ttype)
            .map(|s| s.as_str())
            .unwrap_or(ttype)
    }

    fn to_camel_case(s: &str) -> String {
        if s.is_empty() {
            return String::new();
        }

        let mut result = String::new();
        let mut capitalize_next = false;
        let mut first_char = true;

        for c in s.chars() {
            if c == '_' {
                capitalize_next = true;
            } else if first_char {
                result.push(c.to_lowercase().next().unwrap());
                first_char = false;
            } else if capitalize_next {
                result.push(c.to_uppercase().next().unwrap());
                capitalize_next = false;
            } else {
                result.push(c);
            }
        }

        result
    }
}
