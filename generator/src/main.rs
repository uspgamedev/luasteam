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
            "Interfaces: {} total, {} generated, {} skipped (non-whitelist)",
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

#[derive(Debug, Deserialize, Serialize)]
struct CallbackStruct {
    #[serde(rename = "struct")]
    name: String,
    callback_id: i32,
    fields: Vec<Field>,
}

#[derive(Debug, Deserialize, Serialize)]
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
        
        Self { api, type_map }
    }

    fn resolve_type<'a>(&'a self, t: &'a str) -> &'a str {
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

        let whitelist = vec![
            "ISteamUser", "ISteamFriends", "ISteamUtils", "ISteamMatchmaking",
            "ISteamMatchmakingServers", "ISteamUserStats", "ISteamApps", "ISteamNetworking",
            "ISteamScreenshots", "ISteamMusic", "ISteamMusicRemote", "ISteamHTTP",
            "ISteamInput", "ISteamController", "ISteamUGC", "ISteamHTMLSurface",
            "ISteamInventory", "ISteamVideo", "ISteamParentalSettings", "ISteamRemotePlay",
            "ISteamNetworkingMessages", "ISteamNetworkingSockets", "ISteamNetworkingUtils",
            "ISteamGameServer", "ISteamGameServerStats", "ISteamTimeline", "ISteamParties",
            "ISteamRemoteStorage"
        ];

        for interface in &self.api.interfaces {
            if !whitelist.contains(&interface.classname.as_str()) {
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
            h.push_str(&format!("void add_{}_auto(lua_State *L);\n", name));
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

    fn generate_interface(&self, interface: &Interface, stats: &mut Stats) -> Option<String> {
        let mut cpp = String::new();
        let name_lower = if interface.classname.starts_with("ISteam") {
            &interface.classname[6..]
        } else {
            &interface.classname
        }.to_lowercase();

        cpp.push_str(&format!("#include \"auto.hpp\"\n"));
        if interface.classname == "ISteamGameServer" || interface.classname == "ISteamGameServerStats" {
            cpp.push_str("#include \"../../sdk/public/steam/steam_gameserver.h\"\n");
        }
        cpp.push_str("\n");

        let mut generated_methods = Vec::new();

        for method in &interface.methods {
            stats.methods_total += 1;
            if let Some(generated) = self.generate_method(interface, method, stats) {
                cpp.push_str(&generated);
                cpp.push_str("\n");
                generated_methods.push(method);
                stats.methods_generated += 1;
            } else {
                stats.methods_skipped += 1;
            }
        }

        // Generate add_..._auto function
        let func_name = format!("add_{}_auto", name_lower);
        cpp.push_str(&format!("namespace luasteam {{\n\n"));
        cpp.push_str(&format!("void {}(lua_State *L) {{\n", func_name));
        for method in generated_methods {
             let lua_name = Self::to_lua_name(&method.methodname);
             cpp.push_str(&format!("    add_func(L, \"{}\", luasteam_{}_{});\n", lua_name, name_lower, method.methodname_flat));
        }
        cpp.push_str("}\n\n} // namespace luasteam\n");

        let path = format!("../src/auto/{}.cpp", name_lower);
        fs::write(path, cpp).expect("Unable to write generated file");
        Some(name_lower)
    }

    fn generate_method(&self, interface: &Interface, method: &Method, stats: &mut Stats) -> Option<String> {
        let mut s = String::new();
        let name_lower = if interface.classname.starts_with("ISteam") {
            &interface.classname[6..]
        } else {
            &interface.classname
        }.to_lowercase();
        
        let interface_getter = format!("{}()", &interface.classname[1..]);

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
                if ret_type == "CSteamID" || ret_type == "CGameID" {
                    s.push_str(&format!("    luasteam::pushuint64(L, ({}).ConvertToUint64());\n", call));
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
