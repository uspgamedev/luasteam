use serde::{Deserialize, Serialize};
use std::collections::{HashMap, HashSet};
use std::fs;
use std::path::Path;

#[derive(Debug, Default)]
struct Stats {
    interfaces_total: usize,
    interfaces_generated: usize,
    methods_total: usize,
    methods_generated: usize,
    methods_skipped: usize,
    unsupported_types: HashSet<String>,
}

impl Stats {
    fn print_summary(&self) {
        println!("--- Generation Summary ---");
        println!(
            "Interfaces: {} total, {} generated, {} skipped",
            self.interfaces_total,
            self.interfaces_generated,
            self.interfaces_total - self.interfaces_generated
        );
        println!(
            "Methods:    {} total, {} generated, {} skipped",
            self.methods_total, self.methods_generated, self.methods_skipped
        );

        if !self.unsupported_types.is_empty() {
            println!("\nUnsupported types ({}):", self.unsupported_types.len());
            let mut sorted_types: Vec<_> = self.unsupported_types.iter().collect();
            sorted_types.sort();
            for t in sorted_types {
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
        type_map.insert("unsigned short".to_string(), "int".to_string());
        type_map.insert("uint8".to_string(), "int".to_string());
        type_map.insert("unsigned char".to_string(), "int".to_string());
        type_map.insert("uint64".to_string(), "uint64".to_string());
        type_map.insert("bool".to_string(), "bool".to_string());
        type_map.insert("const char *".to_string(), "const char *".to_string());

        let mut interface_callbacks: HashMap<String, Vec<CallbackStruct>> = HashMap::new();
        for callback in &api.callback_structs {
            let interface = Self::get_interface_for_callback(callback.callback_id);
            if !interface.is_empty() {
                interface_callbacks.entry(interface.to_string()).or_default().push(callback.clone());
            }
            // Special cases for GameServer
            if [101, 102, 103, 115, 143].contains(&callback.callback_id) {
                interface_callbacks.entry("ISteamGameServer".to_string()).or_default().push(callback.clone());
            }
        }
        
        Self { api, type_map, interface_callbacks }
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
            _ => "",
        }
    }

    fn resolve_type<'a>(&'a self, t: &'a str) -> &'a str {
        if t.starts_with("char [") {
            return "const char *";
        }
        let mut current = t;
        while let Some(resolved) = self.type_map.get(current) {
            if resolved == current { break; }
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
        blocklist.insert("ISteamClient", "Specialized interface for context initialization.");
        blocklist.insert("ISteamMatchmakingPingResponse", "Callback response interface.");
        blocklist.insert("ISteamMatchmakingPlayersResponse", "Callback response interface.");
        blocklist.insert("ISteamMatchmakingRulesResponse", "Callback response interface.");
        blocklist.insert("ISteamMatchmakingServerListResponse", "Callback response interface.");
        blocklist.insert("ISteamNetworkingFakeUDPPort", "Internal/specialized.");

        for interface in &self.api.interfaces {
            if blocklist.contains_key(interface.classname.as_str()) {
                continue;
            }
            if interface.accessors.is_empty() {
                continue;
            }
            if let Some(name) = self.generate_interface(interface, &mut stats) {
                interface_names.push(name);
                stats.interfaces_generated += 1;
            }
        }

        self.generate_enums();
        self.generate_auto_header(&interface_names);
        stats.print_summary();
    }

    fn generate_enums(&self) {
        let mut cpp = String::new();
        cpp.push_str("#include \"auto.hpp\"\n\n");
        cpp.push_str("namespace luasteam {\n\n");
        cpp.push_str("void add_enums_auto(lua_State *L) {\n");

        for enm in &self.api.enums {
            let lua_enum_name = if enm.enumname.starts_with('E') && enm.enumname.len() > 1 && enm.enumname.chars().nth(1).unwrap().is_uppercase() {
                &enm.enumname[1..]
            } else {
                &enm.enumname
            };

            cpp.push_str(&format!("    lua_createtable(L, 0, {});\n", enm.values.len()));
            
            let prefix = format!("k_{}", enm.enumname);
            for val in &enm.values {
                let mut lua_val_name = val.name.as_str();
                if lua_val_name.starts_with(&prefix) {
                    lua_val_name = &lua_val_name[prefix.len()..];
                    if lua_val_name.starts_with('_') {
                        lua_val_name = &lua_val_name[1..];
                    }
                }
                
                cpp.push_str(&format!("    lua_pushinteger(L, {});\n", val.value));
                cpp.push_str(&format!("    lua_setfield(L, -2, \"{}\");\n", lua_val_name));
            }
            cpp.push_str(&format!("    lua_setfield(L, -2, \"{}\");\n", lua_enum_name));
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

    fn to_lua_name(method_name: &str) -> String {
        let mut name = method_name;
        if name.len() > 1 && name.starts_with('B') && name.chars().nth(1).unwrap().is_uppercase() {
            name = &name[1..];
        }
        format!("{}{}", name[..1].to_lowercase(), &name[1..])
    }

    fn to_lua_callback_name(struct_name: &str) -> String {
        let mut name = struct_name;
        if name.ends_with("_t") {
            name = &name[..name.len() - 2];
        }
        format!("on{}", name)
    }

    fn to_lua_field_name(fieldname: &str) -> String {
        let mut name = fieldname;
        if name.starts_with("m_") {
            name = &name[2..];
        }
        // Remove common type prefixes
        let prefixes = ["b", "un", "n", "e", "rgch", "ul", "h", "sz", "fl", "p", "ph"];
        for prefix in prefixes {
            if name.starts_with(prefix) && name.len() > prefix.len() && name.chars().nth(prefix.len()).unwrap().is_uppercase() {
                name = &name[prefix.len()..];
                break;
            }
        }
        format!("{}{}", name[..1].to_lowercase(), &name[1..])
    }

    fn generate_callback_field_push(&self, field: &Field) -> String {
        let lua_name = Self::to_lua_field_name(&field.fieldname);
        let resolved = self.resolve_type(&field.fieldtype);

        let is_bool = resolved == "bool" || (resolved == "int" && field.fieldname.starts_with("m_b") && field.fieldname.len() > 3 && field.fieldname.chars().nth(3).unwrap().is_uppercase());

        let push = if is_bool {
            format!("lua_pushboolean(L, data->{});", field.fieldname)
        } else {
            match resolved {
                "int" | "int32" | "uint32" | "unsigned int" | "uint16" | "unsigned short" | "uint8" | "unsigned char" => {
                    format!("lua_pushinteger(L, data->{});", field.fieldname)
                }
                "const char *" => {
                    format!("lua_pushstring(L, data->{});", field.fieldname)
                }
                "uint64" | "unsigned long long" | "CSteamID" | "CGameID" => {
                    if field.fieldtype == "CSteamID" {
                        format!("luasteam::pushuint64(L, data->{}.ConvertToUint64());", field.fieldname)
                    } else if field.fieldtype == "CGameID" {
                        format!("luasteam::pushuint64(L, data->{}.ToUint64());", field.fieldname)
                    } else {
                        format!("luasteam::pushuint64(L, data->{});", field.fieldname)
                    }
                }
                _ => {
                    format!("// Skip unsupported type: {} {}", field.fieldtype, field.fieldname)
                }
            }
        };
        if push.starts_with("//") {
            "".to_string()
        } else {
            format!("        {}\n        lua_setfield(L, -2, \"{}\");", push, lua_name)
        }
    }

    fn generate_callback_listener(&self, name_lower: &str, classname: &str, callbacks: &[CallbackStruct]) -> String {
        let mut s = String::new();
        if callbacks.is_empty() {
            s.push_str(&format!("void init_{}_auto(lua_State *L) {{}}\n\n", name_lower));
            s.push_str(&format!("void shutdown_{}_auto(lua_State *L) {{\n", name_lower));
            s.push_str(&format!("    luaL_unref(L, LUA_REGISTRYINDEX, {}_ref);\n", name_lower));
            s.push_str(&format!("    {}_ref = LUA_NOREF;\n", name_lower));
            s.push_str("}\n\n");
            return s;
        }

        s.push_str("namespace {\n\n");
        s.push_str("class CallbackListener {\n");
        s.push_str("  private:\n");
        let is_gameserver = classname == "ISteamGameServer" || classname == "ISteamGameServerStats";
        let macro_name = if is_gameserver { "STEAM_GAMESERVER_CALLBACK" } else { "STEAM_CALLBACK" };

        for cb in callbacks {
            let mut cpp_func_name = cb.name.clone();
            if cpp_func_name.ends_with("_t") {
                cpp_func_name = cpp_func_name[..cpp_func_name.len() - 2].to_string();
            }
            cpp_func_name = format!("On{}", cpp_func_name);
            s.push_str(&format!("    {}(CallbackListener, {}, {});\n", macro_name, cpp_func_name, cb.name));
        }
        s.push_str("};\n\n");

        for cb in callbacks {
            let lua_func_name = Self::to_lua_callback_name(&cb.name);
            let mut cpp_func_name = cb.name.clone();
            if cpp_func_name.ends_with("_t") {
                cpp_func_name = cpp_func_name[..cpp_func_name.len() - 2].to_string();
            }
            cpp_func_name = format!("On{}", cpp_func_name);
            s.push_str(&format!("void CallbackListener::{}({} *data) {{\n", cpp_func_name, cb.name));
            s.push_str("    if (data == nullptr) return;\n");
            s.push_str("    lua_State *L = luasteam::global_lua_state;\n");
            s.push_str("    if (!lua_checkstack(L, 4)) return;\n");
            s.push_str(&format!("    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::{}_ref);\n", name_lower));
            s.push_str(&format!("    lua_getfield(L, -1, \"{}\");\n", lua_func_name));
            s.push_str("    if (lua_isnil(L, -1)) {\n");
            s.push_str("        lua_pop(L, 2);\n");
            s.push_str("    } else {\n");
            s.push_str(&format!("        lua_createtable(L, 0, {});\n", cb.fields.len()));
            for field in &cb.fields {
                let push = self.generate_callback_field_push(field);
                if !push.is_empty() {
                    s.push_str(&push);
                    s.push_str("\n");
                }
            }
            s.push_str("        lua_call(L, 1, 0);\n");
            s.push_str("        lua_pop(L, 1);\n");
            s.push_str("    }\n");
            s.push_str("}\n\n");
        }

        s.push_str(&format!("CallbackListener *{}_listener = nullptr;\n\n", name_lower));
        s.push_str("} // namespace\n\n");
        s.push_str(&format!("void init_{}_auto(lua_State *L) {{ {}_listener = new CallbackListener(); }}\n\n", name_lower, name_lower));
        s.push_str(&format!("void shutdown_{}_auto(lua_State *L) {{\n", name_lower));
        s.push_str(&format!("    luaL_unref(L, LUA_REGISTRYINDEX, {}_ref);\n", name_lower));
        s.push_str(&format!("    {}_ref = LUA_NOREF;\n", name_lower));
        s.push_str(&format!("    delete {}_listener; {}_listener = nullptr;\n", name_lower, name_lower));
        s.push_str("}\n\n");
        s
    }

    fn generate_interface(&self, interface: &Interface, stats: &mut Stats) -> Option<String> {
        let mut cpp = String::new();
        let name_lower = if interface.classname.starts_with("ISteam") {
            &interface.classname[6..]
        } else {
            &interface.classname
        }.to_lowercase();

        let accessor_name = &interface.accessors[0].name;

        let lua_field_name = match interface.classname.as_str() {
            "ISteamUser" => "user",
            "ISteamFriends" => "friends",
            "ISteamUtils" => "utils",
            "ISteamMatchmaking" => "matchmaking",
            "ISteamMatchmakingServers" => "matchmakingServers",
            "ISteamUserStats" => "userStats",
            "ISteamApps" => "apps",
            "ISteamNetworking" => "networking",
            "ISteamScreenshots" => "screenshots",
            "ISteamMusic" => "music",
            "ISteamHTTP" => "http",
            "ISteamInput" => "input",
            "ISteamController" => "controller",
            "ISteamUGC" => "UGC",
            "ISteamHTMLSurface" => "htmlSurface",
            "ISteamInventory" => "inventory",
            "ISteamVideo" => "video",
            "ISteamParentalSettings" => "parentalSettings",
            "ISteamRemotePlay" => "remotePlay",
            "ISteamNetworkingMessages" => "networkingMessages",
            "ISteamNetworkingSockets" => "networkingSockets",
            "ISteamNetworkingUtils" => "networkingUtils",
            "ISteamGameServer" => "gameServer",
            "ISteamGameServerStats" => "gameServerStats",
            "ISteamTimeline" => "timeline",
            "ISteamParties" => "parties",
            "ISteamRemoteStorage" => "remoteStorage",
            _ => &name_lower,
        };

        cpp.push_str(&format!("#include \"auto.hpp\"\n\n"));

        cpp.push_str("namespace luasteam {\n\n");

        cpp.push_str(&format!("int {}_ref = LUA_NOREF;\n\n", name_lower));

        let callbacks = self.interface_callbacks.get(&interface.classname).map(|v| v.as_slice()).unwrap_or(&[]);
        cpp.push_str(&self.generate_callback_listener(&name_lower, &interface.classname, callbacks));
        cpp.push_str("\n");

        let mut generated_methods = Vec::new();

        for method in &interface.methods {
            stats.methods_total += 1;
            if let Some(generated) = self.generate_method(interface, method, stats, accessor_name) {
                cpp.push_str(&generated);
                cpp.push_str("\n");
                generated_methods.push(method);
                stats.methods_generated += 1;
            } else {
                stats.methods_skipped += 1;
            }
        }

        // Generate register_..._auto function
        cpp.push_str(&format!("void register_{}_auto(lua_State *L) {{\n", name_lower));
        for method in &generated_methods {
             let lua_name = Self::to_lua_name(&method.methodname);
             cpp.push_str(&format!("    add_func(L, \"{}\", luasteam_{}_{});\n", lua_name, name_lower, method.methodname_flat));
        }
        cpp.push_str("}\n\n");

        // Generate add_..._auto function
        cpp.push_str(&format!("void add_{}_auto(lua_State *L) {{\n", name_lower));
        cpp.push_str(&format!("    lua_createtable(L, 0, {});\n", generated_methods.len()));
        cpp.push_str(&format!("    register_{}_auto(L);\n", name_lower));
        cpp.push_str("    lua_pushvalue(L, -1);\n");
        cpp.push_str(&format!("    {}_ref = luaL_ref(L, LUA_REGISTRYINDEX);\n", name_lower));
        cpp.push_str(&format!("    lua_setfield(L, -2, \"{}\");\n", lua_field_name));
        cpp.push_str("}\n\n} // namespace luasteam\n");

        let path = format!("../src/auto/{}.cpp", name_lower);
        fs::write(path, cpp).expect("Unable to write generated file");
        Some(name_lower)
    }

    fn generate_method(&self, interface: &Interface, method: &Method, stats: &mut Stats, accessor_name: &str) -> Option<String> {
        let mut s = String::new();
        let name_lower = if interface.classname.starts_with("ISteam") {
            &interface.classname[6..]
        } else {
            &interface.classname
        }.to_lowercase();
        
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
        s.push_str(&format!("EXTERN int luasteam_{}_{}(lua_State *L) {{\n", name_lower, method.methodname_flat));

        let mut arg_names = Vec::new();
        for (i, param) in method.params.iter().enumerate() {
            let lua_idx = i + 1;
            let resolved = self.resolve_type(&param.paramtype);
            
            match resolved {
                "int" | "int32" | "uint32" | "unsigned int" | "uint16" | "unsigned short" | "uint8" | "unsigned char" => {
                    s.push_str(&format!("    {} {} = static_cast<{}>(luaL_checkint(L, {}));\n", param.paramtype, param.paramname, param.paramtype, lua_idx));
                }
                "bool" => {
                    s.push_str(&format!("    bool {} = lua_toboolean(L, {});\n", param.paramname, lua_idx));
                }
                "const char *" => {
                    s.push_str(&format!("    const char *{} = luaL_checkstring(L, {});\n", param.paramname, lua_idx));
                }
                "uint64" | "unsigned long long" | "CSteamID" | "CGameID" => {
                    let param_type = param.paramtype.replace("const ", "").replace(" &", "").replace("class ", "");
                    if param_type == "CSteamID" || param_type == "CGameID" {
                         s.push_str(&format!("    {} {}(luasteam::checkuint64(L, {}));\n", param_type, param.paramname, lua_idx));
                    } else {
                         s.push_str(&format!("    {} {} = luasteam::checkuint64(L, {});\n", param.paramtype, param.paramname, lua_idx));
                    }
                }
                _ => {
                    // Skip methods with unknown types for now
                    stats.unsupported_types.insert(param.paramtype.clone());
                    return None;
                }
            }
            arg_names.push(param.paramname.clone());
        }

        let call = format!("{}->{}({})", interface_getter, method.methodname, arg_names.join(", "));
        
        let ret_resolved = self.resolve_type(&method.returntype);
        match ret_resolved {
            "void" => {
                s.push_str(&format!("    {};\n", call));
                s.push_str("    return 0;\n");
            }
            "int" | "int32" | "uint32" | "unsigned int" | "uint16" | "unsigned short" | "uint8" | "unsigned char" => {
                s.push_str(&format!("    lua_pushinteger(L, {});\n", call));
                s.push_str("    return 1;\n");
            }
            "bool" => {
                s.push_str(&format!("    lua_pushboolean(L, {});\n", call));
                s.push_str("    return 1;\n");
            }
            "const char *" => {
                s.push_str(&format!("    lua_pushstring(L, {});\n", call));
                s.push_str("    return 1;\n");
            }
            "uint64" | "unsigned long long" | "CSteamID" | "CGameID" => {
                let ret_type = method.returntype.replace("class ", "");
                if ret_type == "CSteamID" {
                    s.push_str(&format!("    luasteam::pushuint64(L, ({}).ConvertToUint64());\n", call));
                } else if ret_type == "CGameID" {
                    s.push_str(&format!("    luasteam::pushuint64(L, ({}).ToUint64());\n", call));
                } else {
                    s.push_str(&format!("    luasteam::pushuint64(L, {});\n", call));
                }
                s.push_str("    return 1;\n");
            }
            _ => {
                // Skip methods with unknown return types
                stats.unsupported_types.insert(method.returntype.clone());
                return None;
            }
        }

        s.push_str("}\n");
        Some(s)
    }
}

fn main() {
    let json_path = "../sdk/public/steam/steam_api.json";
    let json_str = fs::read_to_string(json_path).expect("Unable to read steam_api.json");
    let api: SteamApi = serde_json::from_str(&json_str).expect("Unable to parse JSON");

    let generator = Generator::new(api);
    generator.generate();
}
