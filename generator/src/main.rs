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

        if !self.unsupported_types.is_empty() {
            println!("\nUnsupported types ({}):", self.unsupported_types.len());
            for t in &self.unsupported_types {
                println!("  - {}", t);
            }
        }
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

        let mut blocklist = HashMap::new();
        blocklist.insert(
            "ISteamClient",
            "Specialized interface for context initialization.",
        );
        blocklist.insert(
            "ISteamMatchmakingPingResponse",
            "Callback response interface.",
        );
        blocklist.insert(
            "ISteamMatchmakingPlayersResponse",
            "Callback response interface.",
        );
        blocklist.insert(
            "ISteamMatchmakingRulesResponse",
            "Callback response interface.",
        );
        blocklist.insert(
            "ISteamMatchmakingServerListResponse",
            "Callback response interface.",
        );
        blocklist.insert("ISteamNetworkingFakeUDPPort", "Internal/specialized.");

        let mut method_blocklist = HashMap::new();
        // TODO: Add a custom one for these
        method_blocklist.insert("SteamAPI_ISteamInventory_SetPropertyString", "Overloading");
        method_blocklist.insert("SteamAPI_ISteamInventory_SetPropertyBool", "Overloading");
        method_blocklist.insert("SteamAPI_ISteamInventory_SetPropertyInt64", "Overloading");
        method_blocklist.insert("SteamAPI_ISteamInventory_SetPropertyFloat", "Overloading");
        // TODO: Add a custom one for these too
        method_blocklist.insert(
            "SteamAPI_ISteamGameServerStats_SetUserStatInt32",
            "Overloading",
        );
        method_blocklist.insert(
            "SteamAPI_ISteamGameServerStats_SetUserStatFloat",
            "Overloading",
        );
        method_blocklist.insert("SteamAPI_ISteamUserStats_SetStatInt32", "Overloading");
        method_blocklist.insert("SteamAPI_ISteamUserStats_SetStatFloat", "Overloading");
        method_blocklist.insert(
            "SteamAPI_ISteamUGC_CreateQueryAllUGCRequestCursor",
            "Cursor method is not used",
        );

        for interface in &self.api.interfaces {
            if blocklist.contains_key(interface.classname.as_str()) {
                continue;
            }
            if interface.accessors.is_empty() {
                continue;
            }
            if let Some(name) = self.generate_interface(interface, &method_blocklist, &mut stats) {
                interface_names.push(name);
                stats.interfaces_generated += 1;
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
        h.push_str("#include \"../common.hpp\"\n\n");
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
        method_blocklist: &HashMap<&str, &str>,
        stats: &mut Stats,
    ) -> Option<String> {
        let mut cpp = String::new();
        let name = &interface.classname["ISteam".len()..];
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
                if method_blocklist.contains_key(method.methodname_flat.as_str()) {
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
        Some(name.to_owned())
    }

    fn generate_method(
        &self,
        interface: &str,
        method: &Method,
        stats: &mut Stats,
        accessor_name: &str,
    ) -> Option<(String, String)> {
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

        let mut arg_names = Vec::new();
        for (
            i,
            Param {
                paramtype,
                paramname,
            },
        ) in method
            .params
            .iter()
            .filter(|p| !p.paramname.ends_with("_Deprecated"))
            .enumerate()
        {
            let lua_idx = i + 1;
            let resolved = self.resolve_type(paramtype);

            match resolved {
                "char" => {
                    s.push_str(&format!(
                        "    char {} = luaL_checkstring(L, {})[0];\n",
                        paramname, lua_idx
                    ));
                }
                "double" => {
                    s.push_str(&format!(
                        "    {} {} = luaL_checknumber(L, {});\n",
                        paramtype, paramname, lua_idx
                    ));
                }
                "int" => {
                    s.push_str(&format!(
                        "    {} {} = static_cast<{}>(luaL_checkint(L, {}));\n",
                        paramtype, paramname, paramtype, lua_idx
                    ));
                }
                "bool" => {
                    s.push_str(&format!(
                        "    bool {} = lua_toboolean(L, {});\n",
                        paramname, lua_idx
                    ));
                }
                "const char *" => {
                    s.push_str(&format!(
                        "    const char *{} = luaL_checkstring(L, {});\n",
                        paramname, lua_idx
                    ));
                }
                "uint64" | "unsigned long long" | "CSteamID" | "CGameID" => {
                    let param_type = paramtype
                        .replace("const ", "")
                        .replace(" &", "")
                        .replace("class ", "");
                    if param_type == "CSteamID" || param_type == "CGameID" {
                        s.push_str(&format!(
                            "    {} {}(luasteam::checkuint64(L, {}));\n",
                            param_type, paramname, lua_idx
                        ));
                    } else {
                        s.push_str(&format!(
                            "    {} {} = luasteam::checkuint64(L, {});\n",
                            paramtype, paramname, lua_idx
                        ));
                    }
                }
                _ => {
                    // Skip methods with unknown types for now
                    println!("Unsupported param type: {}", paramtype);
                    stats.unsupported_types.insert(paramtype.clone());
                    return None;
                }
            }
            arg_names.push(paramname.clone());
        }

        let call = format!(
            "{}->{}({})",
            interface_getter,
            method.methodname,
            arg_names.join(", ")
        );

        if method.returntype == "void" {
            s.push_str(&format!("    {};\n", call));
            s.push_str("    return 0;\n");
        } else {
            let (ok, push) = self.generate_push(&method.returntype, &call);
            if !ok {
                // Skip methods with unknown return types
                stats.unsupported_types.insert(method.returntype.clone());
                return None;
            }
            s.push_str(&format!("    {}\n", push));
            s.push_str("    return 1;\n");
        }

        s.push_str("}\n");
        Some((lua_method_name, s))
    }
}

fn main() {
    let json_path = "../sdk/public/steam/steam_api.json";
    let json_str = fs::read_to_string(json_path).expect("Unable to read steam_api.json");
    let api: SteamApi = serde_json::from_str(&json_str).expect("Unable to parse JSON");

    let generator = Generator::new(api);
    generator.generate();
}
