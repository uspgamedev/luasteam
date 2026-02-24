use crate::lua_type_info::{LType, LuaMethodSignature};
use crate::schema::{CallbackStruct, Interface, SkipReason, Struct};
use serde::Deserialize;
use std::collections::HashMap;
use std::fs;

/// Minimal doc info for an auto-generated struct, passed from main.rs to the generators.
pub struct StructDocInfo<'a> {
    pub name: &'a str,
    pub readable_fields: &'a [(String, LType)],
    pub method_signatures: &'a [(String, LuaMethodSignature)],
}

/// Doc info for a single param in a callback interface method.
pub struct CallbackParamDocInfo {
    pub name: String,
    pub ltype: LType,
}

/// Doc info for a method in a callback interface.
pub struct CallbackMethodDocInfo {
    pub name: String,
    pub params: Vec<CallbackParamDocInfo>,
}

/// Doc info for a callback interface (user-implemented pure-virtual C++ interface).
pub struct CallbackInterfaceDocInfo {
    pub name: String,
    pub methods: Vec<CallbackMethodDocInfo>,
}

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
    structs: Vec<Struct>,
}

impl DocGenerator {
    pub fn new() -> Self {
        let custom_docs = if let Ok(content) = fs::read_to_string("custom_docs.toml") {
            toml::from_str(&content).unwrap_or_default()
        } else {
            CustomDocs::default()
        };

        Self {
            custom_docs,
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
        method_signatures: &[(String, LuaMethodSignature)],
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
        // Check if any methods have multiple overloads (detected by searching for similar names)
        let has_overloads = !method_signatures.is_empty() && {
            let mut name_counts: HashMap<String, usize> = HashMap::new();
            for (lua_method_name, _) in method_signatures {
                let base_name = lua_method_name
                    .chars()
                    .take_while(|c| c.is_alphabetic())
                    .collect::<String>();
                *name_counts.entry(base_name).or_insert(0) += 1;
            }
            name_counts.values().any(|&count| count > 1)
        };
        if has_overloads {
            doc.push_str(".. note::\n");
            doc.push_str("   Overloaded Steam methods are exposed as distinct Lua functions using a type suffix (for example ``GetStatInt32`` and ``SetStatFloat``).\n\n");
        }

        // List of Functions
        doc.push_str("List of Functions\n");
        doc.push_str("-----------------\n\n");
        for (lua_method_name, _) in method_signatures {
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

        for (lua_method_name, signature) in method_signatures {
            doc.push_str(&self.generate_function_doc_from_signature(
                lua_method_name,
                signature,
                lua_namespace,
                &interface.classname,
            ));
        }

        // Struct Reference (only structs used by this interface)
        let used_structs =
            self.get_structs_for_interface_from_signatures(interface, method_signatures);
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

    fn generate_function_doc_from_signature(
        &self,
        lua_method_name: &str,
        signature: &LuaMethodSignature,
        lua_namespace: &str,
        interface_name: &str,
    ) -> String {
        let custom_key = format!("{}.{}", interface_name, lua_method_name);
        let custom_doc = self.custom_docs.methods.get(&custom_key);

        let mut doc = String::new();

        // Build parameter list from signature
        let params: Vec<String> = signature.params.iter().map(|p| p.name.clone()).collect();

        doc.push_str(&format!(
            ".. function:: {}.{}({})\n\n",
            lua_namespace,
            lua_method_name,
            params.join(", ")
        ));

        // Auto-generated marker
        doc.push_str("    🤖 **Auto-generated binding**\n\n");

        // Parameters with types from signature
        for param in &signature.params {
            let param_desc = custom_doc
                .and_then(|cd| cd.param_descriptions.get(&param.name))
                .map(|s| s.as_str())
                .unwrap_or("");

            if let LType::CallresultCallback { struct_t } = &param.ltype {
                doc.push_str(&format!("    :param function {}: CallResult callback receiving struct `{struct_t}` and a boolean\n", param.name));
            } else if param_desc.is_empty() {
                doc.push_str(&format!("    :param {} {}:\n", param.ltype.to_rst_link(&self.structs), param.name));
            } else {
                doc.push_str(&format!(
                    "    :param {} {}: {}\n",
                    param.ltype.to_rst_link(&self.structs), param.name, param_desc
                ));
            }
        }

        // Return values from signature
        if let Some(ret_type) = &signature.return_type {
            doc.push_str(&format!("    :returns: ({}) Return value\n", ret_type.to_rst_link(&self.structs)));
        }

        // Output parameters become additional return values
        for output_param in &signature.output_params {
            doc.push_str(&format!(
                "    :returns: ({}) Value for `{}`\n",
                output_param.ltype.to_rst_link(&self.structs), output_param.name
            ));
        }

        // SteamWorks link (extract method name from lua_method_name for URL)
        let method_name_for_url = lua_method_name;
        doc.push_str(&format!(
            "    :SteamWorks: `{} <https://partner.steamgames.com/doc/api/{}#{}>`_\n\n",
            method_name_for_url, interface_name, method_name_for_url
        ));

        // Description from custom docs
        if let Some(custom) = custom_doc
            && !custom.description.is_empty()
        {
            doc.push_str(&format!("    {}\n\n", custom.description));
        }

        // Signature differences notes
        if !signature.output_params.is_empty() {
            doc.push_str("    **Signature differences from C++ API:**\n\n");
            for output_param in &signature.output_params {
                doc.push_str(&format!(
                    "    * Parameter ``{}`` is returned as an additional return value\n",
                    output_param.name
                ));
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
            "    Callback for `{} <https://partner.steamgames.com/doc/api/ISteam{}#{}>`_\n\n",
            callback.name, lua_namespace, callback.name
        ));
        doc.push_str("    **callback(data)** receives:\n\n");

        for field in &callback.fields {
            doc.push_str(&format!(
                "    * **data.{}** -- {}\n",
                field.fieldname, field.fieldname
            ));
        }
        doc.push('\n');

        doc
    }

    fn get_structs_for_interface_from_signatures(
        &self,
        _interface: &Interface,
        method_signatures: &[(String, LuaMethodSignature)],
    ) -> Vec<&Struct> {
        let mut used_structs = Vec::new();
        let mut seen = std::collections::HashSet::new();

        // Find all table/struct types used in parameters and return values
        for (_, signature) in method_signatures {
            // Check parameters
            for param in &signature.params {
                if self.is_struct_type_in_ltype(&param.ltype)
                    && let Some(struct_name) = self.extract_struct_name_from_ltype(&param.ltype)
                    && let Some(strct) = self.get_struct_by_name(&struct_name)
                    && seen.insert(&strct.name)
                {
                    used_structs.push(strct);
                }
            }
            // Check return type
            if let Some(ret_type) = &signature.return_type
                && self.is_struct_type_in_ltype(ret_type)
                && let Some(struct_name) = self.extract_struct_name_from_ltype(ret_type)
                && let Some(strct) = self.get_struct_by_name(&struct_name)
                && seen.insert(&strct.name)
            {
                used_structs.push(strct);
            }
            // Check output parameters
            for output_param in &signature.output_params {
                if self.is_struct_type_in_ltype(&output_param.ltype)
                    && let Some(struct_name) =
                        self.extract_struct_name_from_ltype(&output_param.ltype)
                    && let Some(strct) = self.get_struct_by_name(&struct_name)
                    && seen.insert(&strct.name)
                {
                    used_structs.push(strct);
                }
            }
        }

        used_structs
    }

    fn is_struct_type_in_ltype(&self, ltype: &crate::lua_type_info::LType) -> bool {
        use crate::lua_type_info::LType;
        match ltype {
            LType::Table => true,
            LType::Array(inner) => self.is_struct_type_in_ltype(inner),
            _ => false,
        }
    }

    fn extract_struct_name_from_ltype(
        &self,
        ltype: &crate::lua_type_info::LType,
    ) -> Option<String> {
        use crate::lua_type_info::LType;
        match ltype {
            LType::Table => {
                // For now, we can't determine struct name from LType::Table
                // This would need to be extended if we want struct type tracking
                None
            }
            LType::Array(inner) => self.extract_struct_name_from_ltype(inner),
            _ => None,
        }
    }

    fn get_struct_by_name(&self, name: &str) -> Option<&Struct> {
        self.structs.iter().find(|s| s.name == name)
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
                    doc.push_str(&format!("    * **{}**\n", field.fieldname));
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

    pub fn generate_structs_doc(&self, structs: &[StructDocInfo<'_>]) -> String {
        let mut doc = String::new();

        doc.push_str("=======\nStructs\n=======\n\n");
        doc.push_str(".. note::\n");
        doc.push_str("   These structs are auto-generated as Lua userdata objects.\n");
        doc.push_str("   Create them with the ``Steam.new<StructName>()`` constructor.\n\n");

        for st in structs {
            // Section header with RST label for cross-referencing
            let bar = "-".repeat(st.name.len());
            doc.push_str(&format!(".. _struct-{}:\n\n", st.name));
            doc.push_str(&format!("{}\n{}\n{}\n\n", bar, st.name, bar));

            // Constructor
            doc.push_str(&format!(".. function:: Steam.new{}([table])\n\n", st.name));
            doc.push_str("    🤖 Constructor — creates a new userdata instance.\n\n");
            doc.push_str(&format!(
                "    :param table table: *(optional)* Initial field values as a table.\n"
            ));
            doc.push_str(&format!(
                "    :returns: ({}) New userdata instance.\n\n",
                st.name
            ));

            // Fields
            if !st.readable_fields.is_empty() {
                doc.push_str("    **Fields** (readable and writable):\n\n");
                for (fieldname, ltype) in st.readable_fields {
                    let type_str = ltype.to_rst_link(&self.structs);
                    doc.push_str(&format!("    * **{}** ({})\n", fieldname, type_str));
                }
                doc.push('\n');
            }

            // Methods
            if !st.method_signatures.is_empty() {
                for (lua_name, sig) in st.method_signatures {
                    let params: Vec<String> =
                        sig.params.iter().map(|p| p.name.clone()).collect();
                    doc.push_str(&format!(
                        ".. function:: {}:{}({})\n\n",
                        st.name,
                        lua_name,
                        params.join(", ")
                    ));
                    doc.push_str("    🤖 **Auto-generated binding**\n\n");

                    for param in &sig.params {
                        doc.push_str(&format!("    :param {} {}:\n", param.ltype.to_rst_link(&self.structs), param.name));
                    }
                    if let Some(ret) = &sig.return_type {
                        doc.push_str(&format!("    :returns: ({})\n", ret.to_rst_link(&self.structs)));
                    }
                    doc.push('\n');
                }
            }
        }

        doc
    }

    pub fn generate_callback_interfaces_doc(&self, interfaces: &[CallbackInterfaceDocInfo]) -> String {
        let mut doc = String::new();

        doc.push_str("====================\nCallback Interfaces\n====================\n\n");
        doc.push_str(".. note::\n");
        doc.push_str("   These are pure-virtual C++ interfaces that you implement in Lua by providing\n");
        doc.push_str("   a table of callback functions to the constructor.\n\n");

        for iface in interfaces {
            let name = &iface.name;
            let bar = "-".repeat(name.len());
            // Use struct- prefix so cross-references from interface docs work
            doc.push_str(&format!(".. _struct-{}:\n\n", name));
            doc.push_str(&format!("{}\n{}\n{}\n\n", bar, name, bar));

            let param_names: Vec<&str> = iface.methods.iter().map(|m| m.name.as_str()).collect();
            doc.push_str(&format!(
                ".. function:: Steam.new{}(callbacks)\n\n",
                name
            ));
            doc.push_str("    🤖 Constructor — creates a new callback interface userdata.\n\n");
            doc.push_str("    :param table callbacks: Table of callback functions:\n\n");

            for method in &iface.methods {
                let params_str: Vec<String> = method.params.iter()
                    .map(|p| format!("{}: {}", p.name, p.ltype.to_lua_doc_reference(&self.structs)))
                    .collect();
                doc.push_str(&format!(
                    "        * **{}** ``function({})``\n",
                    method.name,
                    params_str.join(", ")
                ));
            }
            doc.push('\n');
            doc.push_str(&format!("    :returns: ({}) New callback interface userdata.\n\n", name));

            let _ = param_names;
        }

        doc
    }
}
