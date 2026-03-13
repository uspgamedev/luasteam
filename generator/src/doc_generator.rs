use crate::lua_type_info::{LType, LuaMethodSignature};
use crate::schema::{CallbackStruct, Interface, SkipReason, Struct};
use crate::type_resolver::TypeResolver;
use serde::Deserialize;
use std::collections::{BTreeSet, HashMap};
use std::fs;

/// Minimal doc info for an auto-generated struct, passed from main.rs to the generators.
pub struct StructDocInfo<'a> {
    pub name: &'a str,
    pub readable_fields: &'a [(String, LType)],
    pub writable_field_names: &'a std::collections::HashSet<String>,
    pub unsupported_fields: &'a [String],
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

#[derive(Debug, Deserialize, Default, Clone)]
pub struct ManualParamDoc {
    pub name: String,
    pub ptype: String,
    #[serde(default)]
    pub description: String,
}

#[derive(Debug, Deserialize, Default, Clone)]
pub struct ManualReturnDoc {
    pub ptype: String,
    #[serde(default)]
    pub description: String,
}

#[derive(Debug, Deserialize, Default, Clone)]
pub struct ManualFunctionDoc {
    #[serde(default)]
    pub description: String,
    #[serde(default)]
    pub steamworks: String,
    #[serde(default)]
    pub params: Vec<ManualParamDoc>,
    #[serde(default)]
    pub returns: Vec<ManualReturnDoc>,
    #[serde(default)]
    pub signature_differences: Vec<String>,
    #[serde(default)]
    pub notes: Vec<String>,
    #[serde(default)]
    pub example: Option<String>,
}

#[derive(Debug, Deserialize, Default)]
pub struct InterfaceDoc {
    #[serde(default)]
    pub notes: Vec<String>,
}

#[derive(Debug, Deserialize, Default)]
pub struct CustomDocs {
    #[serde(flatten)]
    pub methods: HashMap<String, HashMap<String, CustomDoc>>,
    #[serde(default)]
    pub manual: HashMap<String, HashMap<String, ManualFunctionDoc>>,
    #[serde(default)]
    pub interface: HashMap<String, InterfaceDoc>,
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
    type_resolver: TypeResolver,
    /// Maps C++ callback struct name (e.g. "FooResult_t") → RST :func: label (e.g. "Foo.OnFooResult")
    callresult_to_func: HashMap<String, String>,
}

impl DocGenerator {
    pub fn new() -> Self {
        let custom_docs: CustomDocs = if let Ok(content) = fs::read_to_string("custom_docs.toml") {
            match toml::from_str(&content) {
                Ok(v) => v,
                Err(e) => {
                    eprintln!("Warning: failed to parse custom_docs.toml: {}", e);
                    CustomDocs::default()
                }
            }
        } else {
            CustomDocs::default()
        };

        Self {
            custom_docs,
            structs: Vec::new(),
            type_resolver: TypeResolver::empty(),
            callresult_to_func: HashMap::new(),
        }
    }

    pub fn with_structs(mut self, structs: Vec<Struct>) -> Self {
        self.structs = structs;
        self
    }

    pub fn with_type_resolver(mut self, type_resolver: TypeResolver) -> Self {
        self.type_resolver = type_resolver;
        self
    }

    /// Pre-populate the callresult → RST label map from all interface callbacks.
    /// Must be called before generating interface docs.
    pub fn with_interface_callbacks(
        mut self,
        interface_callbacks: &HashMap<String, Vec<CallbackStruct>>,
    ) -> Self {
        for (classname, callbacks) in interface_callbacks {
            // "ISteamGameServer" → "GameServer"
            let namespace = &classname["ISteam".len()..];
            for cb in callbacks {
                // "ComputeNewPlayerCompatibilityResult_t" → strip "_t" → prepend "On"
                let lua_cb_name = format!("On{}", &cb.name[..cb.name.len() - 2]);
                let label = format!("{}.{}", namespace, lua_cb_name);
                self.callresult_to_func.insert(cb.name.clone(), label);
            }
        }
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
        doc.push_str("   Methods marked with ✍️ are manually implemented and methods marked with ✋ are currently not implemented.\n\n");
        // Check if any methods are overloads (C++ method exposed with a type suffix).
        // original_cpp_name is set precisely for these cases.
        let has_overloads = method_signatures
            .iter()
            .any(|(_, sig)| sig.original_cpp_name.is_some());
        if has_overloads {
            doc.push_str(".. note::\n");
            doc.push_str("   Overloaded Steam methods are exposed as distinct Lua functions using a type suffix (for example ``GetStatInt32`` and ``SetStatFloat``).\n\n");
        }
        if interface.accessors.len() > 1 {
            doc.push_str(".. note::\n");
            doc.push_str(&format!("    This interface can be accessed has multiple accessors (e.g. a GameServer variant), the documentation shows ``{}`` everywhere but it can also be accessed with {}.\n\n", interface.accessors[0].pretty_name(), interface.accessors.iter().skip(1).map(|s| format!("``{}``", s.pretty_name())).collect::<Vec<_>>().join(", ")));
        }

        if let Some(interface_doc) = self.custom_docs.interface.get(&interface.classname)
            && !interface_doc.notes.is_empty()
        {
            doc.push_str(".. note::\n");
            for note in &interface_doc.notes {
                doc.push_str(&format!("   * {}\n", note));
            }
            doc.push('\n');
        }

        // Collect manual methods for this interface (if any)
        let manual_methods: Vec<(&String, &ManualFunctionDoc)> = self
            .custom_docs
            .manual
            .get(&interface.classname)
            .map(|m| {
                let mut v: Vec<_> = m.iter().collect();
                v.sort_by_key(|(k, _)| k.as_str());
                v
            })
            .unwrap_or_default();

        // List of Functions — auto + manual merged and sorted by name
        doc.push_str("List of Functions\n");
        doc.push_str("-----------------\n\n");
        {
            let mut all_names: Vec<&str> = method_signatures
                .iter()
                .map(|(n, _)| n.as_str())
                .chain(manual_methods.iter().map(|(n, _)| n.as_str()))
                .collect();
            all_names.sort_unstable();
            for name in all_names {
                doc.push_str(&format!("* :func:`{}.{}`\n", lua_namespace, name));
            }
        }
        doc.push('\n');

        // List of Callbacks
        if !callbacks.is_empty() {
            doc.push_str("List of Callbacks\n");
            doc.push_str("-----------------\n\n");
            for callback in callbacks {
                let callback_name = &callback.name.replace("_t", "");
                doc.push_str(&format!(
                    "* :func:`{}.On{}`\n",
                    lua_namespace, callback_name
                ));
            }
            doc.push('\n');
        }

        // Function Reference — auto + manual merged and sorted by name
        doc.push_str("Function Reference\n");
        doc.push_str("------------------\n\n");

        // Build a merged sorted list: each entry is either auto or manual
        enum FuncEntry<'a> {
            Auto(&'a str, &'a crate::lua_type_info::LuaMethodSignature),
            Manual(&'a str, &'a ManualFunctionDoc),
        }
        let mut entries: Vec<FuncEntry> = method_signatures
            .iter()
            .map(|(n, s)| FuncEntry::Auto(n.as_str(), s))
            .chain(
                manual_methods
                    .iter()
                    .map(|(n, d)| FuncEntry::Manual(n.as_str(), d)),
            )
            .collect();
        entries.sort_by_key(|e| match e {
            FuncEntry::Auto(n, _) => *n,
            FuncEntry::Manual(n, _) => *n,
        });

        for entry in entries {
            match entry {
                FuncEntry::Auto(name, signature) => {
                    doc.push_str(&self.generate_function_doc_from_signature(
                        name,
                        signature,
                        lua_namespace,
                        &interface.classname,
                    ));
                }
                FuncEntry::Manual(name, manual_doc) => {
                    doc.push_str(&self.generate_manual_function_doc(
                        name,
                        manual_doc,
                        lua_namespace,
                        &interface.classname,
                    ));
                }
            }
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
            let all_names: BTreeSet<&str> = method_signatures
                .iter()
                .map(|(n, _)| n.as_str())
                .chain(manual_methods.iter().map(|(n, _)| n.as_str()))
                .collect();
            doc.push_str("\nUnimplemented Methods\n");
            doc.push_str("---------------------\n\n");
            for (method_name, reason) in skipped_methods {
                // Extract just the method name without interface prefix
                let method_name_only = method_name.split("::").last().unwrap_or(method_name);
                doc.push_str(&format!(
                    ".. function:: {}.{}\n{}\n",
                    lua_namespace,
                    method_name_only,
                    if all_names.contains(method_name_only) {
                        "    :no-index:\n"
                    } else {
                        ""
                    },
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
                doc.push_str(&self.generate_callback_doc(
                    callback,
                    lua_namespace,
                    &interface.classname,
                ));
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
        let custom_doc = self
            .custom_docs
            .methods
            .get(interface_name)
            .and_then(|m| m.get(lua_method_name));

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
                let struct_ref = if let Some(label) = self.callresult_to_func.get(struct_t) {
                    format!(":func:`{struct_t} <{label}>`")
                } else {
                    format!("`{struct_t}`")
                };
                doc.push_str(&format!("    :param function {}: CallResult callback receiving struct {} and a boolean\n", param.name, struct_ref));
            } else {
                let type_str = Self::rst_type_with_cpp(
                    &param.ltype,
                    param.is_optional,
                    param.cpp_type_name.as_deref(),
                    &self.structs,
                );
                let desc = if !param_desc.is_empty() {
                    param_desc.to_string()
                } else if let Some((array_names, is_output)) = &param.size_of {
                    if *is_output {
                        let names_str = if array_names.len() == 1 {
                            format!("``{}``", array_names[0])
                        } else {
                            let joined = array_names
                                .iter()
                                .map(|n| format!("``{}``", n))
                                .collect::<Vec<_>>()
                                .join(", ");
                            format!("the output arrays {}", joined)
                        };
                        if param.is_optional {
                            format!(
                                "size of the buffer to allocate for {}. If ``nil`` then the buffer will be ``NULL``.",
                                names_str
                            )
                        } else {
                            format!(
                                "size of the buffer to be allocated to hold the return value {}",
                                names_str
                            )
                        }
                    } else if array_names.len() == 1 {
                        format!("size of the input array ``{}``", array_names[0])
                    } else {
                        let names = array_names
                            .iter()
                            .map(|n| format!("``{}``", n))
                            .collect::<Vec<_>>()
                            .join(" and ");
                        format!("size of the input arrays {}", names)
                    }
                } else {
                    String::new()
                };
                doc.push_str(&Self::format_param_field(&type_str, &param.name, &desc));
            }
        }

        // Return values from signature
        if let Some(ret_type) = &signature.return_type {
            let ret_type_str = Self::rst_type_with_cpp(
                ret_type,
                false,
                signature.return_cpp_type.as_deref(),
                &self.structs,
            );
            let ret_desc = if signature.returns_steam_api_call {
                "``SteamAPICall_t`` handle for this async call. The result is delivered via the ``callback`` parameter when :func:`Steam.RunCallbacks` is called.".to_string()
            } else {
                "Return value".to_string()
            };
            doc.push_str(&format!("    :returns: ({}) {}\n", ret_type_str, ret_desc));
        }

        // Output parameters become additional return values
        for output_param in &signature.output_params {
            doc.push_str(&format!(
                "    :returns: ({}) ``{}``\n",
                output_param.ltype.to_rst_link(&self.structs),
                output_param.name
            ));
        }

        // SteamWorks link — use the original C++ method name for the URL anchor when the
        // Lua name has a type suffix (e.g. GetUserStatInt32 → #GetUserStat).
        let cpp_method_name = signature
            .original_cpp_name
            .as_deref()
            .unwrap_or(lua_method_name);
        doc.push_str(&format!(
            "    :SteamWorks: `{} <https://partner.steamgames.com/doc/api/{}#{}>`_\n\n",
            cpp_method_name, interface_name, cpp_method_name
        ));

        // Description from custom docs
        if let Some(custom) = custom_doc
            && !custom.description.is_empty()
        {
            doc.push_str(&format!("    {}\n\n", custom.description));
        }

        // Signature differences notes
        let has_sig_diffs =
            signature.original_cpp_name.is_some() || !signature.output_params.is_empty();
        if has_sig_diffs {
            doc.push_str("    **Signature differences from C++ API:**\n\n");
            if let Some(cpp_name) = &signature.original_cpp_name {
                doc.push_str(&format!(
                    "    * In C++, this is an overloaded method called ``{}``. luasteam exposes each overload as a distinct function with a type suffix.\n",
                    cpp_name
                ));
            }
            for output_param in &signature.output_params {
                let is_also_input = signature.params.iter().any(|p| p.name == output_param.name);
                if is_also_input {
                    doc.push_str(&format!(
                        "    * Parameter ``{}`` is both an input and an output in C++: you pass the buffer size, and Steam writes the actual count back. luasteam returns it as an additional return value.\n",
                        output_param.name
                    ));
                } else {
                    doc.push_str(&format!(
                        "    * Parameter ``{}`` is not a parameter in Lua — it is an output-only pointer in C++ and is returned as an additional return value.\n",
                        output_param.name
                    ));
                }
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

    fn generate_manual_function_doc(
        &self,
        method_name: &str,
        manual_doc: &ManualFunctionDoc,
        lua_namespace: &str,
        interface_name: &str,
    ) -> String {
        let mut doc = String::new();

        let params: Vec<&str> = manual_doc.params.iter().map(|p| p.name.as_str()).collect();
        doc.push_str(&format!(
            ".. function:: {}.{}({})\n\n",
            lua_namespace,
            method_name,
            params.join(", ")
        ));

        doc.push_str("    ✍️ **Manually implemented**\n\n");

        for param in &manual_doc.params {
            if param.description.is_empty() {
                doc.push_str(&format!("    :param {} {}:\n", param.ptype, param.name));
            } else {
                doc.push_str(&format!(
                    "    :param {} {}: {}\n",
                    param.ptype, param.name, param.description
                ));
            }
        }

        if manual_doc.returns.is_empty() {
            doc.push_str("    :returns: nothing\n");
        } else {
            for ret in &manual_doc.returns {
                if ret.description.is_empty() {
                    doc.push_str(&format!("    :returns: ({})\n", ret.ptype));
                } else {
                    doc.push_str(&format!(
                        "    :returns: ({}) {}\n",
                        ret.ptype, ret.description
                    ));
                }
            }
        }

        let steamworks_url = if manual_doc.steamworks.is_empty() {
            format!(
                "https://partner.steamgames.com/doc/api/{}#{}",
                interface_name, method_name
            )
        } else {
            manual_doc.steamworks.clone()
        };
        doc.push_str(&format!(
            "    :SteamWorks: `{} <{}>`_\n\n",
            method_name, steamworks_url
        ));

        if !manual_doc.description.is_empty() {
            doc.push_str(&format!("    {}\n\n", manual_doc.description));
        }

        if !manual_doc.signature_differences.is_empty() {
            doc.push_str("    **Signature differences from C++ API:**\n\n");
            for diff in &manual_doc.signature_differences {
                doc.push_str(&format!("    * {}\n", diff));
            }
            doc.push('\n');
        }

        if !manual_doc.notes.is_empty() {
            doc.push_str("    **Notes:**\n\n");
            for note in &manual_doc.notes {
                doc.push_str(&format!("    * {}\n", note));
            }
            doc.push('\n');
        }

        if let Some(example) = &manual_doc.example {
            doc.push_str("**Example**::\n\n");
            for line in example.lines() {
                doc.push_str(&format!("    {}\n", line));
            }
            doc.push('\n');
        }

        doc
    }

    fn generate_callback_doc(
        &self,
        callback: &CallbackStruct,
        lua_namespace: &str,
        interface_name: &str,
    ) -> String {
        let callback_name = &callback.name.replace("_t", "");
        let mut doc = String::new();

        let custom_doc = self
            .custom_docs
            .methods
            .get(interface_name)
            .and_then(|m| m.get(&format!("On{}", callback_name)));

        doc.push_str(&format!(
            ".. function:: {}.On{}\n\n",
            lua_namespace, callback_name
        ));
        doc.push_str(&format!(
            "    Callback for `{} <https://partner.steamgames.com/doc/api/ISteam{}#{}>`_\n\n",
            callback.name, lua_namespace, callback.name
        ));
        if callback.fields.is_empty() {
            doc.push_str("    **callback(data)** receives no fields (notification only).\n\n");
        } else {
            doc.push_str("    **callback(data)** receives:\n\n");
            for field in &callback.fields {
                let type_str = self.fieldtype_to_doc(&field.fieldtype);
                doc.push_str(&format!(
                    "    * **data.{}** *({})*\n",
                    field.fieldname, type_str
                ));
            }
            doc.push('\n');
        }

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

    /// Build the RST type annotation string, optionally appending the original C++ type name.
    /// Only annotates scalar types (int, uint64, etc.) — struct/array types already encode identity.
    fn rst_type_with_cpp(
        ltype: &LType,
        is_optional: bool,
        cpp_type: Option<&str>,
        structs: &[crate::schema::Struct],
    ) -> String {
        let base = if is_optional {
            format!("{}?", ltype.to_rst_link(structs))
        } else {
            ltype.to_rst_link(structs)
        };
        // Only append C++ type for simple scalar types where it adds semantic meaning.
        let effective_cpp = match ltype {
            LType::Integer
            | LType::Uint64
            | LType::Float
            | LType::Boolean
            | LType::String
            | LType::Char => cpp_type,
            _ => None,
        };
        match effective_cpp {
            Some(name) => format!("{} - {}", base, name),
            None => base,
        }
    }

    /// Emit a `:param` RST field safely. When `type_str` contains RST role markup (e.g. `:ref:`)
    /// it cannot be placed before the parameter name in the Sphinx field syntax because that
    /// breaks the field list parser. In that case the type is placed in the description instead.
    fn format_param_field(type_str: &str, name: &str, desc: &str) -> String {
        // If the type contains RST role markup, embed it in the description
        if type_str.contains(":ref:") || type_str.contains(":func:") || type_str.contains(":class:")
        {
            if desc.is_empty() {
                format!("    :param {}: ({})\n", name, type_str)
            } else {
                format!("    :param {}: ({}) {}\n", name, type_str, desc)
            }
        } else if desc.is_empty() {
            format!("    :param {} {}:\n", type_str, name)
        } else {
            format!("    :param {} {}: {}\n", type_str, name, desc)
        }
    }

    /// Convert a raw C++ field type to a human-readable doc type string.
    /// For named typedefs/enums (AppId_t, EResult, etc.) that map to a scalar Lua type,
    /// returns "lua_type - CppName". For plain primitives, returns just the Lua type name.
    fn fieldtype_to_doc(&self, ctype: &str) -> String {
        // Check for array suffix like [128]
        let is_array = ctype.contains('[');
        let base = if let Some(bracket) = ctype.find('[') {
            ctype[..bracket].trim()
        } else {
            ctype.trim()
        };
        // Strip const and pointer/reference decorators
        let original = base
            .trim_start_matches("const ")
            .trim_end_matches(" *")
            .trim_end_matches(" &")
            .trim();
        match (original, is_array) {
            // Fixed-size byte/char arrays are pushed as Lua strings — no C++ annotation needed
            ("char", true) | ("uint8", true) => "string".to_string(),
            ("bool", _) => "bool".to_string(),
            ("float", _) | ("double", _) => "float".to_string(),
            ("int8", _)
            | ("int16", _)
            | ("int32", _)
            | ("int", _)
            | ("unsigned int", _)
            | ("uint8", _)
            | ("uint16", _)
            | ("uint32", _) => "int".to_string(),
            ("int64", _) | ("uint64", _) | ("int64_t", _) | ("uint64_t", _) => "uint64".to_string(),
            ("char", false) => "string".to_string(),
            (other, _) => {
                // Special case: C++ class types we push as uint64
                if other == "CSteamID" || other == "CGameID" {
                    return if is_array {
                        format!("uint64[] - {}", other)
                    } else {
                        format!("uint64 - {}", other)
                    };
                }
                // Resolve through typedef chain to find the Lua type
                let base_prim = self.type_resolver.resolve_base_type(other);
                let lua_type = match base_prim {
                    "bool" => "bool",
                    "float" | "double" => "float",
                    "int8" | "int16" | "int32" | "int" | "unsigned int" | "uint8" | "uint16"
                    | "uint32" => "int",
                    "int64" | "uint64" | "int64_t" | "uint64_t" => "uint64",
                    _ => return other.to_string(), // unknown — fall back to raw name
                };
                if is_array {
                    format!("{}[] - {}", lua_type, other)
                } else {
                    format!("{} - {}", lua_type, other)
                }
            }
        }
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
            doc.push_str("    :param table table: *(optional)* Initial field values as a table.\n");
            doc.push_str(&format!(
                "    :returns: ({}) New userdata instance.\n\n",
                st.name
            ));

            // Fields
            let read_write: Vec<_> = st
                .readable_fields
                .iter()
                .filter(|(name, _)| st.writable_field_names.contains(name))
                .collect();
            let read_only: Vec<_> = st
                .readable_fields
                .iter()
                .filter(|(name, _)| !st.writable_field_names.contains(name))
                .collect();

            if !read_write.is_empty() {
                doc.push_str("    **Fields** (readable and writable):\n\n");
                for (fieldname, ltype) in &read_write {
                    let type_str = ltype.to_rst_link(&self.structs);
                    doc.push_str(&format!("    * **{}** ({})\n", fieldname, type_str));
                }
                doc.push('\n');
            }

            if !read_only.is_empty() {
                doc.push_str("    **Fields** (read-only):\n\n");
                for (fieldname, ltype) in &read_only {
                    let type_str = ltype.to_rst_link(&self.structs);
                    doc.push_str(&format!("    * **{}** ({})\n", fieldname, type_str));
                }
                doc.push('\n');
            }

            if !st.unsupported_fields.is_empty() {
                doc.push_str("    **Fields** (unsupported — not accessible from Lua):\n\n");
                for fieldname in st.unsupported_fields {
                    doc.push_str(&format!("    * **{}**\n", fieldname));
                }
                doc.push('\n');
            }

            // Methods
            if !st.method_signatures.is_empty() {
                for (lua_name, sig) in st.method_signatures {
                    let params: Vec<String> = sig.params.iter().map(|p| p.name.clone()).collect();
                    doc.push_str(&format!(
                        ".. function:: {}:{}({})\n\n",
                        st.name,
                        lua_name,
                        params.join(", ")
                    ));
                    doc.push_str("    🤖 **Auto-generated binding**\n\n");

                    for param in &sig.params {
                        let type_str = Self::rst_type_with_cpp(
                            &param.ltype,
                            param.is_optional,
                            param.cpp_type_name.as_deref(),
                            &self.structs,
                        );
                        doc.push_str(&Self::format_param_field(&type_str, &param.name, ""));
                    }
                    if let Some(ret) = &sig.return_type {
                        let ret_type_str = Self::rst_type_with_cpp(
                            ret,
                            false,
                            sig.return_cpp_type.as_deref(),
                            &self.structs,
                        );
                        doc.push_str(&format!("    :returns: ({})\n", ret_type_str));
                    }
                    doc.push('\n');
                }
            }
        }

        doc
    }

    pub fn generate_callback_interfaces_doc(
        &self,
        interfaces: &[CallbackInterfaceDocInfo],
    ) -> String {
        let mut doc = String::new();

        doc.push_str("====================\nCallback Interfaces\n====================\n\n");
        doc.push_str(".. note::\n");
        doc.push_str(
            "   These are pure-virtual C++ interfaces that you implement in Lua by providing\n",
        );
        doc.push_str("   a table of callback functions to the constructor.\n\n");
        doc.push_str("**Example** — browsing LAN servers with :func:`MatchmakingServers.RequestLANServerList`:\n\n");
        doc.push_str(".. code-block:: lua\n\n");
        doc.push_str("    local response_iface = Steam.newISteamMatchmakingServerListResponse {\n");
        doc.push_str("        ServerResponded = function(hRequest, iServer)\n");
        doc.push_str("            local info = Steam.MatchmakingServers.GetServerDetails(hRequest, iServer)\n");
        doc.push_str("            print('Found server:', info.m_szServerName, info.m_nPlayers .. '/' .. info.m_nMaxPlayers)\n");
        doc.push_str("        end,\n");
        doc.push_str("        ServerFailedToRespond = function(hRequest, iServer) end,\n");
        doc.push_str("        RefreshComplete = function(hRequest, response)\n");
        doc.push_str("            print('Server list refresh complete, response:', response)\n");
        doc.push_str("        end,\n");
        doc.push_str("    )\n");
        doc.push_str("    local hRequest = Steam.MatchmakingServers.RequestLANServerList(Steam.Utils.GetAppID(), response_iface)\n\n");

        for iface in interfaces {
            let name = &iface.name;
            let bar = "-".repeat(name.len());
            // Use struct- prefix so cross-references from interface docs work
            doc.push_str(&format!(".. _struct-{}:\n\n", name));
            doc.push_str(&format!("{}\n{}\n{}\n\n", bar, name, bar));

            let param_names: Vec<&str> = iface.methods.iter().map(|m| m.name.as_str()).collect();
            doc.push_str(&format!(".. function:: Steam.new{}(callbacks)\n\n", name));
            doc.push_str("    🤖 Constructor — creates a new callback interface userdata.\n\n");
            doc.push_str("    :param table callbacks: Table of callback functions:\n\n");

            for method in &iface.methods {
                let params_str: Vec<String> = method
                    .params
                    .iter()
                    .map(|p| {
                        format!(
                            "{}: {}",
                            p.name,
                            p.ltype.to_lua_doc_reference(&self.structs)
                        )
                    })
                    .collect();
                doc.push_str(&format!(
                    "        * **{}** ``function({})``\n",
                    method.name,
                    params_str.join(", ")
                ));
            }
            doc.push('\n');
            doc.push_str(&format!(
                "    :returns: ({}) New callback interface userdata.\n\n",
                name
            ));

            let _ = param_names;
        }

        doc
    }
}
