use serde::{Deserialize, Serialize};
use std::collections::{BTreeSet, HashMap, HashSet};
use std::fs;
use std::path::Path;

#[derive(Debug, Default)]
struct Stats {
    interfaces_total: usize,
    interfaces_generated: usize,
    methods_total: usize,
    methods_generated: usize,
    enum_values_total: usize,
    enum_values_generated: usize,
    unsupported_types: BTreeSet<String>,
}

impl Stats {
    fn print_summary(&self) {
        println!("--- Generation Summary ---");
        println!(
            "Interfaces:  {} total, {} generated, {} skipped",
            self.interfaces_total,
            self.interfaces_generated,
            self.interfaces_total - self.interfaces_generated
        );
        println!(
            "Methods:     {} total, {} generated, {} skipped",
            self.methods_total,
            self.methods_generated,
            self.methods_total - self.methods_generated
        );
        println!(
            "Enum Values: {} total, {} generated, {} skipped",
            self.enum_values_total,
            self.enum_values_generated,
            self.enum_values_total - self.enum_values_generated
        );

        println!("--------------------------");
    }
}

#[derive(Debug, Deserialize, Serialize)]
struct SteamApi {
    callback_structs: Vec<CallbackStruct>,
    enums: Vec<Enum>,
    interfaces: Vec<Interface>,
    typedefs: Vec<Typedef>,
}

impl SteamApi {
    /// Remove deprecated methods and parameters
    fn fix_deprecated(&mut self) {
        self.interfaces.iter_mut().for_each(|i| {
            i.methods.retain_mut(|m| {
                // remove deprecated parameters
                m.params.retain(|p| !p.paramname.ends_with("_Deprecated"));
                // remove deprecated methods
                !m.methodname.ends_with("_DEPRECATED")
            })
        });
    }
    /// It should be const void * because it is input, not output.
    fn fix_missing_const(&mut self) {
        let data = [(
            "ISteamUser",
            vec![("RequestEncryptedAppTicket", vec!["pDataToInclude"])],
        )];

        for (i_name, methods) in data {
            let i = self
                .interfaces
                .iter_mut()
                .find(|i| i.classname == i_name)
                .expect("Missing interface");
            for (m_name, p_names) in methods {
                let m = i
                    .methods
                    .iter_mut()
                    .find(|m| m.methodname == m_name)
                    .expect("Missing method");
                for p_name in p_names {
                    let p = m
                        .params
                        .iter_mut()
                        .find(|p| p.paramname == p_name)
                        .expect("missing param");
                    assert!(p.paramtype.ends_with(" *"));
                    assert!(!p.paramtype.starts_with("const "));
                    p.paramtype = format!("const {}", p.paramtype);
                }
            }
        }
    }
    /// Methods that do not use out_string_count or out_array_count when they should
    fn fix_missing_array_count(&mut self) {
        let to_mark_counters = [
            (
                "ISteamUser",
                vec![("GetUserDataFolder", "pchBuffer", "cubBuffer")],
            ),
            (
                "ISteamRemotePlay",
                vec![("GetInput", "pInput", "unMaxEvents")],
            ),
            (
                "ISteamApps",
                vec![
                    ("GetCurrentBetaName", "pchName", "cchNameBufferSize"),
                    ("GetLaunchCommandLine", "pszCommandLine", "cubCommandLine"),
                    ("GetAppInstallDir", "pchFolder", "cchFolderBufferSize"),
                    ("GetInstalledDepots", "pvecDepots", "cMaxDepots"),
                    ("BGetDLCDataByIndex", "pchName", "cchNameBufferSize"),
                ],
            ),
            (
                "ISteamUserStats",
                vec![
                    (
                        "GetNextMostAchievedAchievementInfo",
                        "pchName",
                        "unNameBufLen",
                    ),
                    ("GetMostAchievedAchievementInfo", "pchName", "unNameBufLen"),
                    ("GetDownloadedLeaderboardEntry", "pDetails", "cDetailsMax"),
                ],
            ),
        ];
        for (i_name, data) in to_mark_counters {
            let i = self
                .interfaces
                .iter_mut()
                .find(|i| i.classname == i_name)
                .expect("Interface not found");
            for (m_name, p_name, count_name) in data {
                let m = i
                    .methods
                    .iter_mut()
                    .find(|m| m.methodname == m_name)
                    .expect("Method not found");
                let p = m
                    .params
                    .iter_mut()
                    .find(|p| p.paramname == p_name)
                    .expect("Parameter not found");
                assert!(p.paramtype.ends_with(" *"));
                assert!(p.out_string_count.is_none());
                assert!(p.out_array_count.is_none());
                let field = if p.paramtype == "char *" {
                    &mut p.out_string_count
                } else {
                    &mut p.out_array_count
                };
                *field = Some(count_name.to_string());
                assert!(
                    m.params.iter().any(|p| p.paramname == count_name),
                    "Count parameter not found"
                );
            }
        }
    }

    /// Fix some known issues in the JSON data
    fn apply_fixes(&mut self) {
        self.fix_deprecated();
        self.fix_missing_const();
        self.fix_missing_array_count();
    }
}

#[derive(Debug, Deserialize, Serialize, Clone)]
struct CallbackStruct {
    #[serde(rename = "struct")]
    name: String,
    callback_id: i32,
    fields: Vec<Field>,
}

#[derive(Debug, Deserialize, Serialize, Clone)]
struct Field {
    fieldname: String,
    fieldtype: String,
}

#[derive(Debug, Deserialize, Serialize)]
struct Enum {
    enumname: String,
    values: Vec<EnumValue>,
}

#[derive(Debug, Deserialize, Serialize)]
struct EnumValue {
    name: String,
    value: String,
}

#[derive(Debug, Deserialize, Serialize)]
struct Interface {
    classname: String,
    methods: Vec<Method>,
    #[serde(default)]
    accessors: Vec<Accessor>,
}

#[derive(Debug, Deserialize, Serialize)]
struct Accessor {
    kind: String,
    name: String,
    name_flat: String,
}

#[derive(Debug, Deserialize, Serialize)]
struct Method {
    methodname: String,
    methodname_flat: String,
    params: Vec<Param>,
    returntype: String,
}

#[derive(Debug, Deserialize, Serialize)]
struct Param {
    paramname: String,
    paramtype: String,
    /// Only present for pointer params that represent arrays, indicates the name of the parameter that contains the size of the array.
    out_string_count: Option<String>,
    /// If present, indicates that this pointer param is an output array and the name of the parameter that contains the size of the array (might be the next parameter, or a constant)
    out_array_count: Option<String>,
    array_count: Option<String>,
    // Like out_array_count, but has the name of the function to call to get the count
    out_array_call: Option<String>,
    desc: Option<String>,
}

#[derive(Debug, Deserialize, Serialize)]
struct Typedef {
    typedef: String,
    #[serde(rename = "type")]
    type_name: String,
}

struct Generator {
    api: SteamApi,
    type_map: HashMap<String, String>,
    interface_callbacks: HashMap<String, Vec<CallbackStruct>>,
}

impl Generator {
    fn new(api: SteamApi) -> Self {
        let mut type_map = HashMap::new();
        for td in &api.typedefs {
            type_map.insert(td.typedef.clone(), td.type_name.clone());
        }
        for enm in &api.enums {
            type_map.insert(enm.enumname.clone(), "int".to_string());
        }
        // Basic types
        type_map.insert("int".to_string(), "int".to_string());
        type_map.insert("int32".to_string(), "int".to_string());
        type_map.insert("uint32".to_string(), "int".to_string());
        type_map.insert("unsigned int".to_string(), "int".to_string());
        type_map.insert("uint16".to_string(), "int".to_string());
        type_map.insert("short".to_string(), "int".to_string());
        type_map.insert("unsigned short".to_string(), "int".to_string());
        type_map.insert("uint8".to_string(), "int".to_string());
        type_map.insert("unsigned char".to_string(), "int".to_string());
        type_map.insert("uint64".to_string(), "uint64".to_string());
        // int64 -> uint64 is a bit of a hack
        type_map.insert("int64".to_string(), "uint64".to_string());
        type_map.insert("bool".to_string(), "bool".to_string());
        type_map.insert("const char *".to_string(), "const char *".to_string());
        type_map.insert("float".to_string(), "double".to_string());
        type_map.insert("double".to_string(), "double".to_string());

        let mut interface_callbacks: HashMap<String, Vec<CallbackStruct>> = HashMap::new();
        for callback in &api.callback_structs {
            let interface = Self::get_interface_for_callback(callback.callback_id);
            if !interface.is_empty() {
                interface_callbacks
                    .entry(interface.to_string())
                    .or_default()
                    .push(callback.clone());
            }
            // Special cases for GameServer
            if [101, 102, 103, 115, 143].contains(&callback.callback_id) {
                interface_callbacks
                    .entry("ISteamGameServer".to_string())
                    .or_default()
                    .push(callback.clone());
            }
        }

        Self {
            api,
            type_map,
            interface_callbacks,
        }
    }

    // Callback IDs are defined in sdk/public/steam/steam_api_internal.h
    fn get_interface_for_callback(id: i32) -> &'static str {
        match id {
            100..200 => "ISteamUser",
            200..300 => "ISteamGameServer",
            300..400 => "ISteamFriends",
            500..600 => "ISteamMatchmaking",
            700..800 => "ISteamUtils",
            1000..1100 => "ISteamApps",
            1100..1200 => "ISteamUserStats",
            1200..1220 => "ISteamNetworking",
            1220..1250 => "ISteamNetworkingSockets",
            1250..1280 => "ISteamNetworkingMessages",
            1280..1300 => "ISteamNetworkingUtils",
            1300..1400 => "ISteamRemoteStorage",
            1800..1900 => "ISteamGameServerStats",
            2100..2200 => "ISteamHTTP",
            2300..2400 => "ISteamScreenshots",
            2800..2900 => "ISteamInput",
            3400..3500 => "ISteamUGC",
            4000..4100 => "ISteamMusic",
            4500..4600 => "ISteamHTMLSurface",
            4600..4700 => "ISteamVideo",
            4700..4800 => "ISteamInventory",
            5000..5100 => "ISteamParentalSettings",
            5300..5400 => "ISteamParties",
            5700..5800 => "ISteamRemotePlay",
            6000..6100 => "ISteamTimeline",
            _ => unreachable!("Unknown callback ID: {}", id),
        }
    }

    fn resolve_type<'a>(&'a self, t: &'a str) -> &'a str {
        let mut current = t;
        while let Some(resolved) = self.type_map.get(current) {
            if resolved == current {
                break;
            }
            current = resolved;
        }
        current
    }

    fn generate(&self) {
        let mut stats = Stats::default();
        stats.interfaces_total = self.api.interfaces.len();

        let auto_dir = Path::new("../src/auto");
        if !auto_dir.exists() {
            fs::create_dir_all(auto_dir).expect("Unable to create src/auto");
        }

        let mut interface_names = Vec::new();

        let mut method_blocklist = HashSet::new();
        // These are added because they have many overloads
        // TODO: Add a custom one for these
        method_blocklist.insert("SteamAPI_ISteamInventory_SetPropertyString");
        method_blocklist.insert("SteamAPI_ISteamInventory_SetPropertyBool");
        method_blocklist.insert("SteamAPI_ISteamInventory_SetPropertyInt64");
        method_blocklist.insert("SteamAPI_ISteamInventory_SetPropertyFloat");
        method_blocklist.insert("SteamAPI_ISteamUserStats_GetGlobalStatInt64");
        method_blocklist.insert("SteamAPI_ISteamUserStats_GetGlobalStatDouble");
        method_blocklist.insert("SteamAPI_ISteamUserStats_GetGlobalStatHistoryInt64");
        method_blocklist.insert("SteamAPI_ISteamUserStats_GetGlobalStatHistoryDouble");
        method_blocklist.insert("SteamAPI_ISteamUserStats_SetStatInt32");
        method_blocklist.insert("SteamAPI_ISteamUserStats_SetStatFloat");
        method_blocklist.insert("SteamAPI_ISteamUserStats_GetStatInt32");
        method_blocklist.insert("SteamAPI_ISteamUserStats_GetStatFloat");
        method_blocklist.insert("SteamAPI_ISteamUserStats_SetUserStatInt32");
        method_blocklist.insert("SteamAPI_ISteamUserStats_SetUserStatFloat");
        method_blocklist.insert("SteamAPI_ISteamUserStats_GetUserStatInt32");
        method_blocklist.insert("SteamAPI_ISteamUserStats_GetUserStatFloat");
        method_blocklist.insert("SteamAPI_ISteamGameServerStats_SetUserStatInt32");
        method_blocklist.insert("SteamAPI_ISteamGameServerStats_SetUserStatFloat");
        method_blocklist.insert("SteamAPI_ISteamGameServerStats_GetUserStatInt32");
        method_blocklist.insert("SteamAPI_ISteamGameServerStats_GetUserStatFloat");
        method_blocklist.insert("SteamAPI_ISteamUserStats_GetAchievementProgressLimitsInt32");
        method_blocklist.insert("SteamAPI_ISteamUserStats_GetAchievementProgressLimitsFloat");
        // Cursor method is not used
        method_blocklist.insert("SteamAPI_ISteamUGC_CreateQueryAllUGCRequestCursor");
        // Unused method, not even in API Reference
        method_blocklist.insert("SteamAPI_ISteamUGC_GetQueryFirstUGCKeyValueTag");
        // Very weird, out_array_count seems to be all wrong
        method_blocklist.insert("SteamAPI_ISteamInventory_GetItemsWithPrices");
        // Weird API and no explanation or reference
        method_blocklist.insert("SteamAPI_ISteamRemoteStorage_GetUGCDetails");

        for interface in &self.api.interfaces {
            match self.generate_interface(interface, &method_blocklist, &mut stats) {
                Ok(name) => {
                    interface_names.push(name);
                    stats.interfaces_generated += 1;
                }
                Err(reason) => {
                    println!(
                        "Error generating interface {}: {}",
                        interface.classname, reason
                    );
                }
            }
        }

        self.generate_enums(&mut stats);
        self.generate_auto_header(&interface_names);
        stats.print_summary();
    }

    fn generate_enums(&self, stats: &mut Stats) {
        let mut cpp = String::new();
        cpp.push_str("#include \"auto.hpp\"\n\n");
        cpp.push_str("namespace luasteam {\n\n");
        cpp.push_str("void add_enums_auto(lua_State *L) {\n");

        for enm in &self.api.enums {
            for val in &enm.values {
                cpp.push_str(&format!("    lua_pushinteger(L, {});\n", val.value));
                cpp.push_str(&format!("    lua_setfield(L, -2, \"{}\");\n", val.name));
                stats.enum_values_generated += 1;
            }
            stats.enum_values_total += enm.values.len();
        }

        cpp.push_str("}\n\n} // namespace luasteam\n");
        fs::write("../src/auto/enums.cpp", cpp).expect("Unable to write enums.cpp");
    }

    fn generate_auto_header(&self, interfaces: &[String]) {
        let mut h = String::new();
        h.push_str("#ifndef LUASTEAM_AUTO_HPP\n");
        h.push_str("#define LUASTEAM_AUTO_HPP\n\n");
        h.push_str("#include \"../common.hpp\"\n");
        h.push_str("#include <vector>\n\n");
        h.push_str("namespace luasteam {\n\n");
        h.push_str("void add_enums_auto(lua_State *L);\n");
        for name in interfaces {
            h.push_str(&format!("void register_{}_auto(lua_State *L);\n", name));
            h.push_str(&format!("void add_{}_auto(lua_State *L);\n", name));
            h.push_str(&format!("void init_{}_auto(lua_State *L);\n", name));
            h.push_str(&format!("void shutdown_{}_auto(lua_State *L);\n", name));
            h.push_str(&format!("extern int {}_ref;\n", name));
        }
        h.push_str("\n} // namespace luasteam\n\n");
        h.push_str("#endif // LUASTEAM_AUTO_HPP\n");
        fs::write("../src/auto/auto.hpp", h).expect("Unable to write auto.hpp");
    }

    fn to_lua_callback_name(struct_name: &str) -> String {
        assert!(struct_name.ends_with("_t"));
        format!("On{}", &struct_name[..struct_name.len() - 2])
    }

    /// Generate code to push a field into the stack, returns (success, code). No trailing space/newline/indent in code.
    fn generate_push(&self, ftype: &str, value_accessor: &str) -> (bool, String) {
        let resolved = self.resolve_type(ftype);

        let push = match resolved {
            "double" => {
                format!("lua_pushnumber(L, {});", value_accessor)
            }
            "bool" => {
                format!("lua_pushboolean(L, {});", value_accessor)
            }
            "int" => {
                format!("lua_pushinteger(L, {});", value_accessor)
            }
            "const char *" => {
                format!("lua_pushstring(L, {});", value_accessor)
            }
            "uint64" | "unsigned long long" | "CSteamID" | "CGameID" => {
                if ftype == "CSteamID" {
                    format!(
                        "luasteam::pushuint64(L, {}.ConvertToUint64());",
                        value_accessor
                    )
                } else if ftype == "CGameID" {
                    format!("luasteam::pushuint64(L, {}.ToUint64());", value_accessor)
                } else {
                    format!("luasteam::pushuint64(L, {});", value_accessor)
                }
            }
            _ => {
                println!("Unsupported field push type: {}", ftype);
                format!("// Skip unsupported type: {}", ftype)
            }
        };
        (!push.starts_with("//"), push)
    }

    fn generate_callback_listener(
        &self,
        name_lower: &str,
        classname: &str,
        callbacks: &[CallbackStruct],
    ) -> String {
        let mut s = String::new();
        if callbacks.is_empty() {
            s.push_str(&format!(
                "void init_{}_auto(lua_State *L) {{}}\n\n",
                name_lower
            ));
            s.push_str(&format!(
                "void shutdown_{}_auto(lua_State *L) {{\n",
                name_lower
            ));
            s.push_str(&format!(
                "    luaL_unref(L, LUA_REGISTRYINDEX, {}_ref);\n",
                name_lower
            ));
            s.push_str(&format!("    {}_ref = LUA_NOREF;\n", name_lower));
            s.push_str("}\n\n");
            return s;
        }

        s.push_str("namespace {\n\n");
        s.push_str("class CallbackListener {\n");
        s.push_str("  private:\n");
        let is_gameserver = classname == "ISteamGameServer" || classname == "ISteamGameServerStats";
        let macro_name = if is_gameserver {
            "STEAM_GAMESERVER_CALLBACK"
        } else {
            "STEAM_CALLBACK"
        };

        for cb in callbacks {
            let mut cpp_func_name = cb.name.clone();
            if cpp_func_name.ends_with("_t") {
                cpp_func_name = cpp_func_name[..cpp_func_name.len() - 2].to_string();
            }
            cpp_func_name = format!("On{}", cpp_func_name);
            s.push_str(&format!(
                "    {}(CallbackListener, {}, {});\n",
                macro_name, cpp_func_name, cb.name
            ));
        }
        s.push_str("};\n\n");

        for cb in callbacks {
            let lua_func_name = Self::to_lua_callback_name(&cb.name);
            let mut cpp_func_name = cb.name.clone();
            if cpp_func_name.ends_with("_t") {
                cpp_func_name = cpp_func_name[..cpp_func_name.len() - 2].to_string();
            }
            cpp_func_name = format!("On{}", cpp_func_name);
            s.push_str(&format!(
                "void CallbackListener::{}({} *data) {{\n",
                cpp_func_name, cb.name
            ));
            s.push_str("    if (data == nullptr) return;\n");
            s.push_str("    lua_State *L = luasteam::global_lua_state;\n");
            s.push_str("    if (!lua_checkstack(L, 4)) return;\n");
            s.push_str(&format!(
                "    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::{}_ref);\n",
                name_lower
            ));
            s.push_str(&format!(
                "    lua_getfield(L, -1, \"{}\");\n",
                lua_func_name
            ));
            s.push_str("    if (lua_isnil(L, -1)) {\n");
            s.push_str("        lua_pop(L, 2);\n");
            s.push_str("    } else {\n");
            s.push_str(&format!(
                "        lua_createtable(L, 0, {});\n",
                cb.fields.len()
            ));
            for field in &cb.fields {
                let (ok, push) =
                    self.generate_push(&field.fieldtype, &format!("data->{}", field.fieldname));
                s.push_str(&format!("        {}\n", push));
                if ok {
                    s.push_str(&format!(
                        "        lua_setfield(L, -2, \"{}\");\n",
                        field.fieldname
                    ));
                }
            }
            s.push_str("        lua_call(L, 1, 0);\n");
            s.push_str("        lua_pop(L, 1);\n");
            s.push_str("    }\n");
            s.push_str("}\n\n");
        }

        s.push_str(&format!(
            "CallbackListener *{}_listener = nullptr;\n\n",
            name_lower
        ));
        s.push_str("} // namespace\n\n");
        s.push_str(&format!(
            "void init_{}_auto(lua_State *L) {{ {}_listener = new CallbackListener(); }}\n\n",
            name_lower, name_lower
        ));
        s.push_str(&format!(
            "void shutdown_{}_auto(lua_State *L) {{\n",
            name_lower
        ));
        s.push_str(&format!(
            "    luaL_unref(L, LUA_REGISTRYINDEX, {}_ref);\n",
            name_lower
        ));
        s.push_str(&format!("    {}_ref = LUA_NOREF;\n", name_lower));
        s.push_str(&format!(
            "    delete {}_listener; {}_listener = nullptr;\n",
            name_lower, name_lower
        ));
        s.push_str("}\n\n");
        s
    }

    fn generate_interface(
        &self,
        interface: &Interface,
        method_blocklist: &HashSet<&str>,
        stats: &mut Stats,
    ) -> Result<String, &str> {
        let mut cpp = String::new();
        let name = &interface.classname["ISteam".len()..];
        if interface.accessors.is_empty() {
            return Err("No acessors");
        }
        if interface.classname.starts_with("ISteamNetworking")
            || name == "HTTP"
            || name == "UGC"
            || name == "Inventory"
        {
            return Err("It has many unsupported types and would require a lot of custom code");
        }
        let accessor_name = &interface.accessors[0].name;

        cpp.push_str(&format!("#include \"auto.hpp\"\n\n"));

        cpp.push_str("namespace luasteam {\n\n");

        cpp.push_str(&format!("int {}_ref = LUA_NOREF;\n\n", name));

        let callbacks = self
            .interface_callbacks
            .get(&interface.classname)
            .map(|v| v.as_slice())
            .unwrap_or(&[]);
        cpp.push_str(&self.generate_callback_listener(&name, &interface.classname, callbacks));
        cpp.push_str("\n");

        let mut generated_methods = Vec::new();

        for method in &interface.methods {
            stats.methods_total += 1;

            if let Some((lua_method_name, generated)) =
                self.generate_method(&name, method, stats, accessor_name)
            {
                if method_blocklist.contains(method.methodname_flat.as_str()) {
                    continue;
                }
                cpp.push_str(&generated);
                cpp.push_str("\n");
                generated_methods.push((method, lua_method_name));
                stats.methods_generated += 1;
            } else {
                println!(
                    "Skipped method {}::{} due to unsupported types",
                    interface.classname, method.methodname
                );
            }
        }

        // Generate register_..._auto function
        cpp.push_str(&format!("void register_{}_auto(lua_State *L) {{\n", name));
        for (m, c_name) in &generated_methods {
            cpp.push_str(&format!(
                "    add_func(L, \"{}\", {});\n",
                m.methodname, c_name
            ));
        }
        cpp.push_str("}\n\n");

        // Generate add_..._auto function
        cpp.push_str(&format!("void add_{}_auto(lua_State *L) {{\n", name));
        cpp.push_str(&format!(
            "    lua_createtable(L, 0, {});\n",
            generated_methods.len()
        ));
        cpp.push_str(&format!("    register_{}_auto(L);\n", name));
        cpp.push_str(&format!("    lua_pushvalue(L, -1);\n"));
        cpp.push_str(&format!(
            "    {}_ref = luaL_ref(L, LUA_REGISTRYINDEX);\n",
            name
        ));
        cpp.push_str(&format!("    lua_setfield(L, -2, \"{}\");\n", name));
        cpp.push_str("}\n\n} // namespace luasteam\n");

        let path = format!("../src/auto/{}.cpp", name);
        fs::write(path, cpp).expect("Unable to write generated file");
        Ok(name.to_owned())
    }

    /// Check if a paramtype is a non-const pointer (e.g., "int *", "uint32 *")
    fn is_non_const_pointer(paramtype: &str) -> bool {
        paramtype.ends_with(" *") && !paramtype.contains("const")
    }

    /// Extract the base type from a pointer type, e.g. "int *" -> "int"
    fn extract_pointer_base_type(paramtype: &str) -> String {
        paramtype.trim_end_matches(" *").to_string()
    }

    fn generate_method(
        &self,
        interface: &str,
        method: &Method,
        stats: &mut Stats,
        accessor_name: &str,
    ) -> Option<(String, String)> {
        // Tricky ones to support:
        // GetItemDefinitionProperty - has a pointer that must have a value and returns another
        // GetItemsWithPrices - The JSON looks different from the API
        // AddPromoItems - Input arrays with counts
        // Most PublishedFileId_t * should be const, also pubBody in HTTP
        let mut s = String::new();

        let interface_getter = format!("{}()", accessor_name);

        let params_str: Vec<String> = method
            .params
            .iter()
            .map(|p| format!("{} {}", p.paramtype, p.paramname))
            .collect();
        s.push_str(&format!(
            "// {} {}({});\n",
            method.returntype,
            method.methodname,
            params_str.join(", ")
        ));
        let lua_method_name = format!("luasteam_{}_{}", interface, method.methodname);
        s.push_str(&format!(
            "EXTERN int {}(lua_State *L) {{\n",
            lua_method_name
        ));

        let mut on_pointers = false;
        // params used to call the function in C
        let mut param_names = Vec::new();
        // Pointer params that are returned as output
        let mut pointer_params = Vec::new();
        let mut string_count_to_ignore = None;

        let mut i = 0;
        let mut lua_idx = 1;
        while i < method.params.len() {
            let param = &method.params[i];
            let is_pointer = Self::is_non_const_pointer(&param.paramtype);
            if Some(&param.paramname) == string_count_to_ignore.as_ref() {
                // This parameter is just the size for a previous string array, skip it
                string_count_to_ignore = None;
                if is_pointer {
                    // It is a value returned as well as the size passed in.
                    pointer_params.push((false, param));
                    param_names.push(format!("&{}", param.paramname.clone()));
                } else {
                    param_names.push(param.paramname.clone());
                }
                i += 1;
                continue;
            }
            if !is_pointer && on_pointers {
                // Pointers must be always at the end.
                // Arrays with size must use out_string_count or out_array_count.
                dbg!(string_count_to_ignore, &method.params);
                println!(
                    "Unsupported parameter order: non-pointer param '{}' comes after pointer params",
                    param.paramname
                );
                return None;
            }
            on_pointers |= is_pointer;
            if !on_pointers {
                if string_count_to_ignore.is_some() {
                    dbg!(&method.params);
                    println!(
                        "Unsupported parameter order: param '{}' comes after a param with out_string_count but is not the count param",
                        param.paramname
                    );
                    return None;
                }
                let resolved = self.resolve_type(&param.paramtype);
                param_names.push(param.paramname.clone());

                match resolved {
                    "char" => {
                        s.push_str(&format!(
                            "    char {} = luaL_checkstring(L, {})[0];\n",
                            param.paramname, lua_idx
                        ));
                    }
                    "double" => {
                        s.push_str(&format!(
                            "    {} {} = luaL_checknumber(L, {});\n",
                            param.paramtype, param.paramname, lua_idx
                        ));
                    }
                    "int" => {
                        s.push_str(&format!(
                            "    {} {} = static_cast<{}>(luaL_checkint(L, {}));\n",
                            param.paramtype, param.paramname, param.paramtype, lua_idx
                        ));
                    }
                    "bool" => {
                        s.push_str(&format!(
                            "    bool {} = lua_toboolean(L, {});\n",
                            param.paramname, lua_idx
                        ));
                    }
                    "const char *" => {
                        s.push_str(&format!(
                            "    const char *{} = luaL_checkstring(L, {});\n",
                            param.paramname, lua_idx
                        ));
                    }
                    "uint64" | "unsigned long long" | "CSteamID" | "CGameID" => {
                        let param_type = param
                            .paramtype
                            .replace("const ", "")
                            .replace(" &", "")
                            .replace("class ", "");
                        if param_type == "CSteamID" || param_type == "CGameID" {
                            s.push_str(&format!(
                                "    {} {}(luasteam::checkuint64(L, {}));\n",
                                param_type, param.paramname, lua_idx
                            ));
                        } else {
                            s.push_str(&format!(
                                "    {} {} = luasteam::checkuint64(L, {});\n",
                                param.paramtype, param.paramname, lua_idx
                            ));
                        }
                    }
                    _ => {
                        // Skip methods with unknown types for now
                        println!("Unsupported param type: {}", param.paramtype);
                        stats.unsupported_types.insert(param.paramtype.clone());
                        return None;
                    }
                }
                lua_idx += 1;
            } else {
                let base_type = Self::extract_pointer_base_type(&param.paramtype);
                if base_type == "void" {
                    println!(
                        "Unsupported pointer parameter with void base type: {} {}",
                        param.paramtype, param.paramname
                    );
                    stats.unsupported_types.insert(param.paramtype.clone());
                    return None;
                }
                if let Some(count_name) = &param.out_string_count {
                    // Assuming it is the next non array parameter (because of lua_idx)
                    // but sometimes it works for two arrays like in GetSupportedGameVersionData (so we store it in string_count_to_ignore)
                    if string_count_to_ignore.is_some() {
                        assert!(string_count_to_ignore.as_ref().unwrap() == count_name);
                    } else {
                        string_count_to_ignore = Some(count_name.to_string());
                        let p = method.params[i + 1..]
                            .iter()
                            .find(|p| &p.paramname == count_name)
                            .expect("Count param not found");
                        s.push_str(&format!(
                            "    {} {} = luaL_checkint(L, {});\n",
                            p.paramtype, count_name, lua_idx
                        ));
                        lua_idx += 1;
                    }
                    s.push_str(&format!(
                        "    std::vector<{}> {}({});\n",
                        base_type, param.paramname, count_name
                    ));
                    param_names.push(format!("{}.data()", param.paramname));
                    pointer_params.push((true, param));
                } else if let Some(count_name) = param
                    .out_array_count
                    .as_deref()
                    .or(param.array_count.as_deref())
                    .or_else(|| {
                        param
                            .out_array_call
                            .as_deref()
                            .map(|s| s.split_once(',').expect("out_array_call must have comma").0)
                    })
                {
                    println!(
                        "Unsupported out array parameter: {} {} with count {} (out_array_count is not supported yet)",
                        param.paramtype, param.paramname, count_name
                    );
                    return None;
                } else {
                    // Create a default variable with that name and type
                    s.push_str(&format!("    {} {};", base_type, param.paramname));
                    param_names.push(format!("&{}", param.paramname));
                    pointer_params.push((false, param));
                }
            }
            i += 1;
        }
        assert!(string_count_to_ignore.is_none());

        let call = format!(
            "{}->{}({})",
            interface_getter,
            method.methodname,
            param_names.join(", ")
        );

        // Calculate return count
        let mut return_count = 0;

        if method.returntype == "void" {
            s.push_str(&format!("    {};\n", call));
        } else {
            let (ok, push) = self.generate_push(&method.returntype, &call);
            if !ok {
                // Skip methods with unknown return types
                stats.unsupported_types.insert(method.returntype.clone());
                return None;
            }
            s.push_str(&format!("    {}\n", push));
            return_count = 1;
        }

        // Push pointer output values onto stack
        for (is_array, param) in pointer_params {
            let base_type = Self::extract_pointer_base_type(&param.paramtype);
            if is_array {
                if base_type == "char" {
                    // A string with variable size
                    s.push_str(&format!(
                        "    lua_pushstring(L, {}.data());\n",
                        param.paramname
                    ));
                } else {
                    // Not sure about the size, will it always be the one you sent?
                    // Also we need to deal with void*, which should probably be treated as bytes.
                    println!("Unsupported pointer base type in array push: {}", base_type);
                    stats.unsupported_types.insert(base_type.clone());
                    return None;
                }
            } else {
                let (ok, push) = self.generate_push(base_type.as_str(), &param.paramname);
                if !ok {
                    println!("Unsupported pointer base type in push: {}", base_type);
                    stats.unsupported_types.insert(base_type.clone());
                    return None;
                }
                s.push_str(&format!("    {}\n", push));
                return_count += 1;
            }
        }

        s.push_str(&format!("    return {};\n", return_count));
        s.push_str("}\n");
        Some((lua_method_name, s))
    }
}

fn main() {
    let json_path = "../sdk/public/steam/steam_api.json";
    let json_str = fs::read_to_string(json_path).expect("Unable to read steam_api.json");
    let mut api: SteamApi = serde_json::from_str(&json_str).expect("Unable to parse JSON");
    api.apply_fixes();

    let generator = Generator::new(api);
    generator.generate();
}
