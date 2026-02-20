use crate::schema::{CallbackStruct, Interface, Method, SkipReason, Struct};
use crate::type_resolver::TypeResolver;
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
    type_resolver: TypeResolver,
    structs: Vec<Struct>,
}

impl DocGenerator {
    pub fn new(type_resolver: TypeResolver) -> Self {
        let custom_docs = if let Ok(content) = fs::read_to_string("custom_docs.toml") {
            toml::from_str(&content).unwrap_or_default()
        } else {
            CustomDocs::default()
        };

        Self {
            custom_docs,
            type_resolver,
            structs: Vec::new(),
        }
    }

    pub fn with_structs(mut self, structs: Vec<Struct>) -> Self {
        self.structs = structs;
        self
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
        if generated_methods
            .iter()
            .any(|(method, lua_method_name)| self.is_overload_renamed(method, lua_method_name))
        {
            doc.push_str(".. note::\n");
            doc.push_str("   Overloaded Steam methods are exposed as distinct Lua functions using a type suffix (for example ``GetStatInt32`` and ``SetStatFloat``).\n\n");
        }

        // List of Functions
        doc.push_str("List of Functions\n");
        doc.push_str("-----------------\n\n");
        for (_, lua_method_name) in generated_methods {
            doc.push_str(&format!(
                "* :func:`{}.{}`\n",
                lua_namespace, lua_method_name
            ));
        }
        doc.push('\n');

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
            doc.push('\n');
        }

        // Function Reference
        doc.push_str("Function Reference\n");
        doc.push_str("------------------\n\n");

        for (method, lua_method_name) in generated_methods {
            doc.push_str(&self.generate_function_doc(
                method,
                lua_method_name,
                lua_namespace,
                &interface.classname,
                true,
            ));
        }

        // Struct Reference (only structs used by this interface)
        let used_structs = self.get_structs_for_interface(interface, generated_methods);
        if !used_structs.is_empty() {
            doc.push_str("\nData Structures\n");
            doc.push_str("---------------\n\n");
            for strct in used_structs {
                doc.push_str(&self.generate_struct_doc(strct, lua_namespace));
            }
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
                doc.push_str(&self.generate_callback_doc(callback, lua_namespace));
            }
        }

        doc
    }

    fn generate_function_doc(
        &self,
        method: &Method,
        lua_method_name: &str,
        lua_namespace: &str,
        interface_name: &str,
        is_auto: bool,
    ) -> String {
        let custom_key = format!("{}.{}", interface_name, method.methodname);
        let custom_doc = self.custom_docs.methods.get(&custom_key);

        let mut doc = String::new();

        // Build parameter list
        let params: Vec<String> = method
            .params
            .iter()
            .filter(|p| !p.is_output_param())
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
            if param.is_output_param() {
                continue;
            }
            let lua_type = self.get_type_reference(&param.paramtype);

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
        for (ret_type, ret_desc) in &return_values {
            doc.push_str(&format!("    :returns: ({}) {}\n", ret_type, ret_desc));
        }

        // SteamWorks link
        doc.push_str(&format!(
            "    :SteamWorks: `{} <https://partner.steamgames.com/doc/api/{}#{}>`_\n\n",
            method.methodname, interface_name, method.methodname
        ));

        // Description
        if let Some(custom) = custom_doc
            && !custom.description.is_empty()
        {
            doc.push_str(&format!("    {}\n\n", custom.description));
        }

        // Signature differences
        let differences = self.detect_signature_differences(method, lua_method_name);
        if !differences.is_empty() {
            doc.push_str("    **Signature differences from C++ API:**\n\n");
            for diff in &differences {
                doc.push_str(&format!("    * {}\n", diff));
            }
            doc.push('\n');
        }

        // Custom notes
        if let Some(custom) = custom_doc
            && !custom.notes.is_empty()
        {
            doc.push_str("    **Notes:**\n\n");
            for note in &custom.notes {
                doc.push_str(&format!("    * {}\n", note));
            }
            doc.push('\n');
        }

        // Example
        if let Some(custom) = custom_doc
            && let Some(example) = &custom.example
        {
            doc.push_str("**Example**::\n\n");
            for line in example.lines() {
                doc.push_str(&format!("    {}\n", line));
            }
            doc.push('\n');
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
        doc.push('\n');

        doc
    }

    fn detect_return_values(&self, method: &Method) -> Vec<(String, String)> {
        let mut returns = Vec::new();

        // Main return value
        if method.returntype != "void" {
            let lua_type = self.get_type_reference(&method.returntype);
            returns.push((lua_type, "Return value".to_string()));
        }

        // Output parameters become additional return values
        for param in &method.params {
            if param.is_output_param() {
                let base_type = param.paramtype.trim_end_matches(" *");
                let lua_type = self.get_type_reference(base_type);
                returns.push((lua_type, format!("Value for `{}`", param.paramname)));
            }
        }

        returns
    }

    fn detect_signature_differences(&self, method: &Method, lua_method_name: &str) -> Vec<String> {
        let mut differences = Vec::new();

        if self.is_overload_renamed(method, lua_method_name) {
            differences.push(format!(
                "This overload is exposed as ``{}`` in Lua (instead of ``{}``) to avoid naming collisions between C++ overloads",
                lua_method_name, method.methodname
            ));
        }

        // Check for output parameters that become return values
        for param in &method.params {
            if param.is_output_param() {
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

    fn is_overload_renamed(&self, method: &Method, lua_method_name: &str) -> bool {
        let flat_tail = method
            .methodname_flat
            .rsplit('_')
            .next()
            .unwrap_or(method.methodname.as_str());

        if let Some(suffix) = flat_tail.strip_prefix(&method.methodname)
            && !suffix.is_empty()
        {
            return lua_method_name == format!("{}{}", method.methodname, suffix);
        }

        false
    }

    fn lua_type_name(&self, cpp_type: &str) -> &str {
        self.type_resolver.to_lua_type(cpp_type)
    }

    fn get_type_reference(&self, cpp_type: &str) -> String {
        // Check if this is a struct type
        if let Some(strct) = self.get_struct_for_type(cpp_type) {
            format!(":data:`{}`", strct.name)
        } else {
            self.lua_type_name(cpp_type).to_string()
        }
    }

    fn get_structs_for_interface(
        &self,
        _interface: &Interface,
        generated_methods: &[(&Method, String)],
    ) -> Vec<&Struct> {
        let mut used_structs = Vec::new();
        let mut seen = std::collections::HashSet::new();

        // Find all struct types used in parameters
        for (method, _) in generated_methods {
            for param in &method.params {
                if let Some(strct) = self.get_struct_for_type(&param.paramtype)
                    && seen.insert(&strct.name)
                {
                    used_structs.push(strct);
                }
            }
            // Also check return type
            if let Some(strct) = self.get_struct_for_type(&method.returntype)
                && seen.insert(&strct.name)
            {
                used_structs.push(strct);
            }
        }

        used_structs
    }

    fn get_struct_for_type(&self, cpp_type: &str) -> Option<&Struct> {
        // Extract base type from pointers and const
        let base_type = cpp_type
            .trim_start_matches("const ")
            .trim_end_matches(" *")
            .trim();

        self.structs.iter().find(|s| s.name == base_type)
    }

    fn generate_struct_doc(&self, strct: &Struct, _lua_namespace: &str) -> String {
        let mut doc = String::new();

        doc.push_str(&format!(".. data:: {}\n\n", strct.name));
        doc.push_str(&format!(
            "    A table representing a **{}** structure from the SteamWorks API.\n\n",
            strct.name
        ));

        if !strct.fields.is_empty() {
            doc.push_str("    **Fields:**\n\n");
            for field in &strct.fields {
                if !field.private {
                    let lua_type = self.lua_type_name(&field.fieldtype);
                    doc.push_str(&format!("    * **{}** ({})\n", field.fieldname, lua_type));
                }
            }
            doc.push('\n');
        }

        doc
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
