use std::collections::{HashMap, HashSet};
use std::fs;
use std::path::Path;

mod code_builder;
mod cpp_type;
mod schema;

use code_builder::CodeBuilder;
use cpp_type::CppType;
use schema::{CallbackStruct, Interface, Method, Param, Stats, SteamApi, Struct};

static COUNTER: std::sync::atomic::AtomicUsize = std::sync::atomic::AtomicUsize::new(0);

struct Generator {
    api: SteamApi,
    type_map: HashMap<String, String>,
    interface_callbacks: HashMap<String, Vec<CallbackStruct>>,
    added_structs: HashSet<String>,
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
        for interface in &api.interfaces {
            for enm in &interface.enums {
                type_map.insert(enm.enumname.clone(), "int".to_string());
                if !enm.fqname.is_empty() {
                    type_map.insert(enm.fqname.clone(), "int".to_string());
                }
            }
        }
        // Basic types
        type_map.insert("int".to_string(), "int".to_string());
        type_map.insert("int32".to_string(), "int".to_string());
        type_map.insert("uint32".to_string(), "int".to_string());
        type_map.insert("unsigned int".to_string(), "int".to_string());
        type_map.insert("uint16".to_string(), "int".to_string());
        type_map.insert("short".to_string(), "int".to_string());
        type_map.insert("unsigned short".to_string(), "int".to_string());
        // type_map.insert("unsigned char".to_string(), "int".to_string());
        // type_map.insert("uint8".to_string(), "int".to_string());
        type_map.insert("uint64".to_string(), "uint64".to_string());
        // int64 -> uint64 is a bit of a hack
        type_map.insert("int64_t".to_string(), "uint64".to_string());
        type_map.insert("int64".to_string(), "uint64".to_string());
        type_map.insert("bool".to_string(), "bool".to_string());
        type_map.insert("const char *".to_string(), "const char *".to_string());
        // type_map.insert("float".to_string(), "double".to_string());
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
            added_structs: HashSet::new(),
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

    fn resolve_type<'a>(&'a self, t: &'a str) -> CppType<'a> {
        if t.ends_with("]") {
            let start_bracket = t.rfind('[').expect("Malformed array type");
            let size_str = &t[start_bracket + 1..t.len() - 1];
            let _size = size_str.parse::<usize>().expect("Malformed size");
            let (ttype, is_const) = if t.starts_with("const ") {
                (t["const ".len()..start_bracket].trim(), true)
            } else {
                (t[..start_bracket].trim(), false)
            };
            return CppType::Array {
                ttype: self.resolve_base_type(ttype),
                size: &size_str,
                is_const,
            };
        }

        if t.ends_with("*") {
            let (ttype, is_const) = if t.starts_with("const ") {
                (t["const ".len()..t.len() - 1].trim(), true)
            } else {
                (t[..t.len() - 1].trim(), false)
            };
            return CppType::Pointer {
                ttype: self.resolve_base_type(ttype),
                is_const,
            };
        }

        CppType::Normal(self.resolve_base_type(t))
    }

    fn resolve_base_type<'a>(&'a self, mut t: &'a str) -> &'a str {
        while let Some(resolved) = self.type_map.get(t) {
            if *resolved == t {
                break;
            }
            t = resolved;
        }
        t
    }

    fn manual_method_blocklist(&self) -> HashSet<String> {
        [
            "SteamAPI_ISteamInventory_SetPropertyString",
            "SteamAPI_ISteamInventory_SetPropertyBool",
            "SteamAPI_ISteamInventory_SetPropertyInt64",
            "SteamAPI_ISteamInventory_SetPropertyFloat",
            "SteamAPI_ISteamUserStats_GetGlobalStatInt64",
            "SteamAPI_ISteamUserStats_GetGlobalStatDouble",
            "SteamAPI_ISteamUserStats_GetGlobalStatHistoryInt64",
            "SteamAPI_ISteamUserStats_GetGlobalStatHistoryDouble",
            "SteamAPI_ISteamUserStats_SetStatInt32",
            "SteamAPI_ISteamUserStats_SetStatFloat",
            "SteamAPI_ISteamUserStats_GetStatInt32",
            "SteamAPI_ISteamUserStats_GetStatFloat",
            "SteamAPI_ISteamUserStats_SetUserStatInt32",
            "SteamAPI_ISteamUserStats_SetUserStatFloat",
            "SteamAPI_ISteamUserStats_GetUserStatInt32",
            "SteamAPI_ISteamUserStats_GetUserStatFloat",
            "SteamAPI_ISteamGameServerStats_SetUserStatInt32",
            "SteamAPI_ISteamGameServerStats_SetUserStatFloat",
            "SteamAPI_ISteamGameServerStats_GetUserStatInt32",
            "SteamAPI_ISteamGameServerStats_GetUserStatFloat",
            "SteamAPI_ISteamUserStats_GetAchievementProgressLimitsInt32",
            "SteamAPI_ISteamUserStats_GetAchievementProgressLimitsFloat",
            "SteamAPI_ISteamUGC_CreateQueryAllUGCRequestCursor",
            "SteamAPI_ISteamUGC_GetQueryFirstUGCKeyValueTag",
            "SteamAPI_ISteamInventory_GetItemsWithPrices",
            "SteamAPI_ISteamRemoteStorage_GetUGCDetails",
            "SteamAPI_ISteamUser_GetVoice",
            "SteamAPI_ISteamUser_DecompressVoice",
            "SteamAPI_ISteamUser_GetAuthSessionTicket",
            "SteamAPI_ISteamGameServer_GetAuthSessionTicket",
            "SteamAPI_ISteamUser_GetEncryptedAppTicket",
            "SteamAPI_ISteamUtils_SetWarningMessageHook",
            "SteamAPI_ISteamParties_CreateBeacon",
        ]
        .into_iter()
        .map(str::to_string)
        .collect()
    }

    fn auto_blocklist_overloads(&self, method_blocklist: &mut HashSet<String>) -> usize {
        let mut auto_blocklisted_conflicts = 0;
        for interface in &self.api.interfaces {
            let mut method_counts: HashMap<&str, usize> = HashMap::new();
            for method in &interface.methods {
                *method_counts.entry(method.methodname.as_str()).or_default() += 1;
            }
            for method in &interface.methods {
                if method_counts
                    .get(method.methodname.as_str())
                    .copied()
                    .unwrap_or(0)
                    > 1
                    && method_blocklist.insert(method.methodname_flat.clone())
                {
                    auto_blocklisted_conflicts += 1;
                }
            }
        }
        auto_blocklisted_conflicts
    }

    fn generate(&mut self) {
        let mut stats = Stats::default();
        stats.interfaces_total = self.api.interfaces.len();

        let auto_dir = Path::new("../src/auto");
        if auto_dir.exists() {
            fs::remove_dir_all(auto_dir).expect("Unable to delete src/auto");
        }
        fs::create_dir_all(auto_dir).expect("Unable to create src/auto");
        // Start with structs to populate added_structs
        self.generate_structs(&mut stats);

        let mut interface_names = Vec::new();

        let mut method_blocklist = self.manual_method_blocklist();
        let auto_blocklisted_conflicts = self.auto_blocklist_overloads(&mut method_blocklist);
        if auto_blocklisted_conflicts > 0 {
            println!(
                "Added {} overloaded methods to blocklist for custom implementation",
                auto_blocklisted_conflicts
            );
        }

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

        self.generate_consts(&mut stats);
        self.generate_enums(&mut stats);
        self.generate_auto_header(&interface_names);
        stats.print_summary();
    }

    fn generate_structs(&mut self, stats: &mut Stats) {
        let incomplete_structs = [
            "SteamDatagramHostedAddress",
            "SteamDatagramGameCoordinatorServerLogin",
            "SteamDatagramGameCoordinatorServerLogin",
        ];
        stats.structs_total = self.api.structs.len();
        let mut cpp = CodeBuilder::new();
        cpp.line("#include \"auto.hpp\"");
        cpp.preceeding_blank_line();
        cpp.line("namespace luasteam {");
        cpp.preceeding_blank_line();

        for st in &self.api.structs {
            if incomplete_structs.contains(&st.name.as_str()) {
                println!("Skipping struct {} because it is incomplete", st.name);
                continue;
            }
            if let Some(code) = self.generate_struct(st) {
                cpp.raw(&code);
                // We are assuming a struct does not depend on one not yet declared
                self.added_structs.insert(st.name.clone());
                stats.structs_generated += 1;
            }
        }

        cpp.line("} // namespace luasteam");
        fs::write("../src/auto/structs.cpp", cpp.finish()).expect("Unable to write structs.cpp");
    }

    fn generate_struct(&self, st: &Struct) -> Option<String> {
        let mut cpp = CodeBuilder::new();
        // Generate check function
        cpp.line(&format!("{} check_{}(lua_State *L, int index) {{", st.name, st.name));
        cpp.indent_right();
        cpp.line("luaL_checktype(L, index, LUA_TTABLE);");
        cpp.line(&format!("{} res;", st.name));
        for field in &st.fields {
            if field.private {
                println!(
                    "Skipping struct {} because field {} is private",
                    st.name, field.fieldname
                );
                return None;
            }
            cpp.line(&format!("lua_getfield(L, index, \"{}\");", field.fieldname));
            let (ok, check) = self.generate_check(
                &field.fieldtype,
                self.resolve_type(&field.fieldtype),
                false,
                &format!("res.{}", field.fieldname),
                "-1",
                1,
            );
            if ok {
                cpp.raw(&check);
            } else {
                cpp.line(&format!("// Unsupported field type: {}", field.fieldtype));
                println!(
                    "Unsupported field type in check for struct {}: {}",
                    st.name, field.fieldtype
                );
                return None;
            }
            cpp.line("lua_pop(L, 1);");
        }
        cpp.line("return res;");
        cpp.indent_left();
        cpp.line("}");
        cpp.preceeding_blank_line();

        // Generate push function
        cpp.line(&format!("void push_{}(lua_State *L, {} val) {{", st.name, st.name));
        cpp.indent_right();
        cpp.line(&format!("lua_createtable(L, 0, {});", st.fields.len()));
        for field in &st.fields {
            let (ok, push) = self.generate_push(
                &field.fieldtype,
                &format!("val.{}", field.fieldname),
                1,
            );
            cpp.raw(&push);
            if ok {
                cpp.line(&format!("lua_setfield(L, -2, \"{}\");", field.fieldname));
            } else {
                println!(
                    "Unsupported field type in push for struct {}: {}",
                    st.name, field.fieldtype
                );
            }
        }
        cpp.indent_left();
        cpp.line("}");
        cpp.preceeding_blank_line();
        Some(cpp.finish())
    }

    fn generate_consts(&self, stats: &mut Stats) {
        let mut cpp = CodeBuilder::new();
        cpp.line("#include \"auto.hpp\"");
        cpp.preceeding_blank_line();
        cpp.line("namespace luasteam {");
        cpp.preceeding_blank_line();
        cpp.line("void add_consts_auto(lua_State *L) {");
        cpp.indent_right();
        stats.consts_total = self.api.consts.len();

        for enm in &self.api.consts {
            let (ok, push) = self.generate_push(&enm.consttype, &enm.constval, 1);
            cpp.raw(&push);
            if ok {
                cpp.line(&format!("lua_setfield(L, -2, \"{}\");", enm.constname));
                stats.const_generated += 1;
            }
        }

        cpp.indent_left();
        cpp.line("}");
        cpp.preceeding_blank_line();
        cpp.line("} // namespace luasteam");
        fs::write("../src/auto/consts.cpp", cpp.finish()).expect("Unable to write consts.cpp");
    }

    fn generate_enums(&self, stats: &mut Stats) {
        let mut cpp = CodeBuilder::new();
        cpp.line("#include \"auto.hpp\"");
        cpp.preceeding_blank_line();
        cpp.line("namespace luasteam {");
        cpp.preceeding_blank_line();
        cpp.line("void add_enums_auto(lua_State *L) {");
        cpp.indent_right();

        for enm in &self.api.enums {
            for val in &enm.values {
                cpp.line(&format!("lua_pushinteger(L, {});", val.name));
                cpp.line(&format!("lua_setfield(L, -2, \"{}\");", val.name));
                stats.enum_values_generated += 1;
            }
            stats.enum_values_total += enm.values.len();
        }

        cpp.indent_left();
        cpp.line("}");
        cpp.preceeding_blank_line();
        cpp.line("} // namespace luasteam");
        fs::write("../src/auto/enums.cpp", cpp.finish()).expect("Unable to write enums.cpp");
    }

    fn generate_auto_header(&self, interfaces: &[String]) {
        let mut h = CodeBuilder::new();
        h.line("#ifndef LUASTEAM_AUTO_HPP");
        h.line("#define LUASTEAM_AUTO_HPP");
        h.preceeding_blank_line();
        h.line("#include \"../common.hpp\"");
        h.line("#include <vector>");
        h.preceeding_blank_line();
        h.line("namespace luasteam {");
        h.preceeding_blank_line();
        h.line("void add_enums_auto(lua_State *L);");
        h.line("void add_consts_auto(lua_State *L);");
        let mut structs_sorted: Vec<_> = self.added_structs.iter().collect();
        structs_sorted.sort();
        for st in structs_sorted {
            h.line(&format!("{} check_{}(lua_State *L, int index);", st, st));
            h.line(&format!("void push_{}(lua_State *L, {} val);", st, st));
        }
        for name in interfaces {
            h.line(&format!("void register_{}_auto(lua_State *L);", name));
            h.line(&format!("void add_{}_auto(lua_State *L);", name));
            h.line(&format!("void init_{}_auto(lua_State *L);", name));
            h.line(&format!("void shutdown_{}_auto(lua_State *L);", name));
            h.line(&format!("extern int {}_ref;", name));
        }
        h.preceeding_blank_line();
        h.line("} // namespace luasteam");
        h.preceeding_blank_line();
        h.line("#endif // LUASTEAM_AUTO_HPP");
        fs::write("../src/auto/auto.hpp", h.finish()).expect("Unable to write auto.hpp");
    }

    fn to_lua_callback_name(struct_name: &str) -> String {
        assert!(struct_name.ends_with("_t"));
        format!("On{}", &struct_name[..struct_name.len() - 2])
    }

    /// Generate code to check a field from the stack, returns (success, code). Code is indented.
    fn generate_check(
        &self,
        original_type: &str,
        resolved: CppType<'_>,
        create_var: bool,
        value_accessor: &str,
        lua_idx: &str,
        indent: usize,
    ) -> (bool, String) {
        let mut out = CodeBuilder::with_indent(indent);
        let type_prefix = if create_var {
            format!("{} ", original_type)
        } else {
            String::new()
        };
        match resolved {
            CppType::Normal(type_name) => match type_name {
                "int" | "unsigned char" => {
                    out.line(
                        &format!(
                            "{}{} = static_cast<{}>(luaL_checkint(L, {}));",
                            type_prefix, value_accessor, original_type, lua_idx
                        ),
                    );
                    (true, out.finish())
                }
                "bool" => {
                    out.line(
                        &format!("{}{} = lua_toboolean(L, {});", type_prefix, value_accessor, lua_idx),
                    );
                    (true, out.finish())
                }
                "double" | "float" => {
                    out.line(
                        &format!(
                            "{}{} = static_cast<{}>(luaL_checknumber(L, {}));",
                            type_prefix, value_accessor, original_type, lua_idx
                        ),
                    );
                    (true, out.finish())
                }
                "uint64" | "unsigned long long" | "CSteamID" | "CGameID" => {
                    let mut get = format!("luasteam::checkuint64(L, {})", lua_idx);
                    if type_name == "CSteamID" || type_name == "CGameID" {
                        get = format!("{}({})", type_name, get);
                    }
                    out.line(
                        &format!("{}{} = {};", type_prefix, value_accessor, get),
                    );
                    (true, out.finish())
                }
                _ => {
                    if self.added_structs.contains(type_name) {
                        out.line(
                            &format!(
                                "{}{} = check_{}(L, {});",
                                type_prefix, value_accessor, type_name, lua_idx
                            ),
                        );
                        (true, out.finish())
                    } else {
                        out.line(
                            &format!(
                                "// Unsupported check type: {} ({})",
                                original_type, type_name
                            ),
                        );
                        (false, out.finish())
                    }
                }
            },
            CppType::Array {
                ttype,
                size,
                is_const: _,
            } => {
                if resolved.is_buffer() {
                    let var = format!(
                        "_tmp{}",
                        COUNTER.fetch_add(1, std::sync::atomic::Ordering::SeqCst)
                    );
                    out.line(
                        &format!("const char *{} = luaL_checkstring(L, {});", var, lua_idx),
                    );
                    out.line(
                        &format!(
                            "if (strlen({}) >= {}) luaL_error(L, \"String too long\");",
                            var, size
                        ),
                    );

                    if create_var {
                        out.line(
                            &format!("char {}[{}];", value_accessor, size),
                        );
                    }
                    out.line(
                        &format!(
                            "memcpy({}, {}, sizeof({}));",
                            value_accessor, var, value_accessor
                        ),
                    );
                    (true, out.finish())
                } else {
                    out.line(
                        &format!("luaL_checktype(L, {}, LUA_TTABLE);", lua_idx),
                    );
                    if create_var {
                        out.line(
                            &format!("std::vector<{}> {}({});", ttype, value_accessor, size),
                        );
                    }
                    out.line(
                        &format!("for(decltype({}) i=0;i<{};i++){{", size, size),
                    );
                    out.indent_right();
                    out.line("lua_rawgeti(L, -1, i+1);");
                    let (ok, check) = self.generate_check(
                        ttype,
                        self.resolve_type(ttype),
                        false,
                        &format!("{}[i]", value_accessor),
                        "-1",
                        out.indent(),
                    );
                    if ok {
                        out.raw(&check);
                        out.line("lua_pop(L, 1);");
                        out.indent_left();
                        out.line( "}");
                        (true, out.finish())
                    } else {
                        out.line(
                            &format!("// Unsupported check array type: {} [{}]", ttype, size),
                        );
                        (false, out.finish())
                    }
                }
            }
            _ => {
                out.line(
                    &format!("// Unsupported check type: {:?}", resolved),
                );
                (false, out.finish())
            }
        }
    }

    fn generate_push(&self, ftype: &str, value_accessor: &str, indent: usize) -> (bool, String) {
        let resolved = self.resolve_type(ftype);

        let push = match resolved {
            CppType::Normal(s) => match s {
                "double" | "float" => {
                    format!("lua_pushnumber(L, {});", value_accessor)
                }
                "bool" => {
                    format!("lua_pushboolean(L, {});", value_accessor)
                }
                "int" | "unsigned char" => {
                    format!("lua_pushinteger(L, {});", value_accessor)
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
                    if self.added_structs.contains(s) {
                        format!("push_{}(L, {});", s, value_accessor)
                    } else {
                        println!("Unsupported field push type: {} {:?}", ftype, resolved);
                        format!("// Skip unsupported type: {}", ftype)
                    }
                }
            },
            _ if resolved.is_buffer() => {
                format!(
                    "lua_pushstring(L, reinterpret_cast<const char*>({}));",
                    value_accessor
                )
            }
            CppType::Array {
                ttype,
                size,
                is_const: _,
            } => {
                if resolved.is_buffer() {
                    format!(
                        "lua_pushlstring(L, reinterpret_cast<const char*>({}), {});",
                        value_accessor, size
                    )
                } else if let Some(code) =
                    self.push_array(ttype, value_accessor, size.to_string().as_str(), indent)
                {
                    return (true, code);
                } else {
                    println!(
                        "Unsupported field push array type: {} {:?} {}",
                        ftype, resolved, value_accessor
                    );
                    format!("// Skip unsupported array type: {}", ftype)
                }
            }
            _ => {
                println!(
                    "Unsupported field push type: {} {:?} {}",
                    ftype, resolved, value_accessor
                );
                format!("// Skip unsupported type: {}", ftype)
            }
        };
        let ok = !push.starts_with("//");
        let mut out = CodeBuilder::with_indent(indent);
        out.line(&push);
        (ok, out.finish())
    }

    fn generate_callback_listener(
        &self,
        name_lower: &str,
        classname: &str,
        callbacks: &[CallbackStruct],
    ) -> String {
        let mut s = CodeBuilder::new();
        if callbacks.is_empty() {
            s.line(&format!(
                "void init_{}_auto(lua_State *L) {{}}",
                name_lower
            ));
            s.line(&format!(
                "void shutdown_{}_auto(lua_State *L) {{",
                name_lower
            ));
            s.indent_right();
            s.line(&format!(
                "luaL_unref(L, LUA_REGISTRYINDEX, {}_ref);",
                name_lower
            ));
            s.line(&format!("{}_ref = LUA_NOREF;", name_lower));
            s.indent_left();
            s.line("}");
            return s.finish();
        }

        s.line("namespace {");
        s.line("class CallbackListener {");
        s.line("private:");
        s.indent_right();
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
            s.line(&format!(
                "{}(CallbackListener, {}, {});",
                macro_name, cpp_func_name, cb.name
            ));
        }
        s.indent_left();
        s.line("};");

        for cb in callbacks {
            let lua_func_name = Self::to_lua_callback_name(&cb.name);
            let mut cpp_func_name = cb.name.clone();
            if cpp_func_name.ends_with("_t") {
                cpp_func_name = cpp_func_name[..cpp_func_name.len() - 2].to_string();
            }
            cpp_func_name = format!("On{}", cpp_func_name);
            s.line(&format!(
                "void CallbackListener::{}({} *data) {{",
                cpp_func_name, cb.name
            ));
            s.indent_right();
            s.line("if (data == nullptr) return;");
            s.line("lua_State *L = luasteam::global_lua_state;");
            s.line("if (!lua_checkstack(L, 4)) return;");
            s.line(&format!(
                "lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::{}_ref);",
                name_lower
            ));
            s.line(&format!(
                "lua_getfield(L, -1, \"{}\");",
                lua_func_name
            ));
            s.line("if (lua_isnil(L, -1)) {");
            s.indent_right();
            s.line("lua_pop(L, 2);");
            s.indent_left();
            s.line("} else {");
            s.indent_right();
            s.line(&format!("lua_createtable(L, 0, {});", cb.fields.len()));
            for field in &cb.fields {
                let (ok, push) = self.generate_push(
                    &field.fieldtype,
                    &format!("data->{}", field.fieldname),
                    s.indent(),
                );
                s.raw(&push);
                if ok {
                    s.line(&format!(
                        "lua_setfield(L, -2, \"{}\");",
                        field.fieldname
                    ));
                }
            }
            s.line("lua_call(L, 1, 0);");
            s.line("lua_pop(L, 1);");
            s.indent_left();
            s.line("}");
            s.indent_left();
            s.line("}");
        }

        s.line(&format!(
            "CallbackListener *{}_listener = nullptr;",
            name_lower
        ));
        s.line("} // namespace");
        s.preceeding_blank_line();
        s.line(&format!(
            "void init_{}_auto(lua_State *L) {{ {}_listener = new CallbackListener(); }}",
            name_lower, name_lower
        ));
        s.line(&format!(
            "void shutdown_{}_auto(lua_State *L) {{",
            name_lower
        ));
        s.indent_right();
        s.line(&format!(
            "luaL_unref(L, LUA_REGISTRYINDEX, {}_ref);",
            name_lower
        ));
        s.line(&format!("{}_ref = LUA_NOREF;", name_lower));
        s.line(&format!(
            "delete {}_listener; {}_listener = nullptr;",
            name_lower, name_lower
        ));
        s.indent_left();
        s.line("}");
        s.finish()
    }

    fn generate_interface(
        &self,
        interface: &Interface,
        method_blocklist: &HashSet<String>,
        stats: &mut Stats,
    ) -> Result<String, &str> {
        let mut cpp = CodeBuilder::new();
        let name = &interface.classname["ISteam".len()..];
        if interface.accessors.is_empty() {
            return Err("No acessors");
        }
        if interface.classname.starts_with("ISteamNetworking")
            || name == "HTTP"
            || name == "UGC"
            || name == "Inventory"
            || name == "MatchmakingServers"
        {
            return Err("It has many unsupported types and would require a lot of custom code");
        }
        let accessor_name = &interface.accessors[0].name;

        cpp.line("#include \"auto.hpp\"");
        cpp.preceeding_blank_line();
        cpp.line("namespace luasteam {");
        cpp.preceeding_blank_line();
        cpp.line(&format!("int {}_ref = LUA_NOREF;", name));
        cpp.preceeding_blank_line();

        let callbacks = self
            .interface_callbacks
            .get(&interface.classname)
            .map(|v| v.as_slice())
            .unwrap_or(&[]);
        cpp.raw(&self.generate_callback_listener(&name, &interface.classname, callbacks));
        cpp.preceeding_blank_line();

        let mut generated_methods = Vec::new();

        stats.methods_total += interface.methods.len();
        for method in &interface.methods {
            // println!(
            //     "Processing method {}::{}",
            //     interface.classname, method.methodname
            // );
            if method_blocklist.contains(method.methodname_flat.as_str()) {
                println!(
                    "Skipped method {}::{} in blocklist",
                    interface.classname, method.methodname
                );
                continue;
            } else if let Some((lua_method_name, generated)) =
                self.generate_method(&name, method, stats, accessor_name)
            {
                cpp.raw(&generated);
                cpp.preceeding_blank_line();
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
        cpp.line(&format!("void register_{}_auto(lua_State *L) {{", name));
        cpp.indent_right();
        for (m, c_name) in &generated_methods {
            cpp.line(&format!("add_func(L, \"{}\", {});", m.methodname, c_name));
        }
        cpp.indent_left();
        cpp.line("}");
        cpp.preceeding_blank_line();

        // Generate add_..._auto function
        let interface_enum_values_count: usize =
            interface.enums.iter().map(|enm| enm.values.len()).sum();
        cpp.line(&format!("void add_{}_auto(lua_State *L) {{", name));
        cpp.indent_right();
        cpp.line(&format!(
            "lua_createtable(L, 0, {});",
            generated_methods.len() + interface_enum_values_count
        ));
        cpp.line(&format!("register_{}_auto(L);", name));
        for enm in &interface.enums {
            for val in &enm.values {
                cpp.line(&format!("lua_pushinteger(L, {}::{});", interface.classname, val.name));
                cpp.line(&format!("lua_setfield(L, -2, \"{}\");", val.name));
            }
        }
        cpp.line("lua_pushvalue(L, -1);");
        cpp.line(&format!("{}_ref = luaL_ref(L, LUA_REGISTRYINDEX);", name));
        cpp.line(&format!("lua_setfield(L, -2, \"{}\");", name));
        cpp.indent_left();
        cpp.line("}");
        cpp.preceeding_blank_line();
        cpp.line("} // namespace luasteam");

        let path = format!("../src/auto/{}.cpp", name);
        fs::write(path, cpp.finish()).expect("Unable to write generated file");
        Ok(name.to_owned())
    }

    fn push_array(
        &self,
        ttype: &str,
        value_accessor: &str,
        size: &str,
        indent: usize,
    ) -> Option<String> {
        let mut s = CodeBuilder::with_indent(indent);

        s.line(&format!("lua_createtable(L, {}, 0);", size));
        s.indent_right();
        let (ok, push) = self.generate_push(ttype, &format!("{}[i]", value_accessor), s.indent());
        s.indent_left();
        if ok {
            s.line(&format!("for(decltype({}) i=0;i<{};i++){{", size, size));
            s.indent_right();
            if !push.is_empty() {
                s.raw(&push);
            }
            s.line("lua_rawseti(L, -2, i+1);");
            s.indent_left();
            s.line("}");
        } else {
            println!("Unsupported type in array push: {}", ttype);
            return None;
        }
        Some(s.finish())
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
        // GetImageRGBA - uint8* should be a byte buffer, probably
        let mut s = CodeBuilder::new();

        let interface_getter = format!("{}()", accessor_name);

        let params_str: Vec<String> = method
            .params
            .iter()
            .map(|p| format!("{} {}", p.paramtype, p.paramname))
            .collect();
        s.line(&format!(
            "// {} {}({});",
            method.returntype,
            method.methodname,
            params_str.join(", ")
        ));
        let lua_method_name = format!("luasteam_{}_{}", interface, method.methodname);
        s.line(&format!("EXTERN int {}(lua_State *L) {{", lua_method_name));
        s.indent_right();

        // params used to call the function in C
        let mut param_names = Vec::new();
        // Pointer params that are returned as output: (param_info, custom_push_code)
        let mut pointer_params: Vec<(&Param, bool)> = Vec::new();
        let mut sz_param_to_ignore = None;

        let mut i = 0;
        let mut lua_idx = 1;
        while i < method.params.len() {
            let param = &method.params[i];
            let resolved = self.resolve_type(&param.paramtype);
            use CppType::*;
            if resolved.is_double_pointer() {
                println!(
                    "Unsupported double pointer parameter '{}' of type '{}'",
                    param.paramname, param.paramtype
                );
                stats.unsupported_types.insert(param.paramtype.clone());
                return None;
            }

            if Some(&param.paramname) == sz_param_to_ignore.as_ref() {
                // This parameter is just the size for a previous string array, skip it
                sz_param_to_ignore = None;
                match resolved {
                    CppType::Normal(_) => {
                        param_names.push(param.paramname.clone());
                    }
                    CppType::Pointer { .. } => {
                        // It is a value returned as well as the size passed in.
                        pointer_params.push((param, false));
                        param_names.push(format!("&{}", param.paramname.clone()));
                    }
                    _ => unreachable!("No array sizes"),
                }
                i += 1;
                continue;
            }

            if sz_param_to_ignore.is_some() && !matches!(resolved, CppType::Pointer { .. }) {
                dbg!(&method.params);
                println!(
                    "Unsupported parameter order: param '{}' comes after a param with out_string_count but is not the count param",
                    param.paramname
                );
                return None;
            }

            // This is probably somewhat duplicated with generate_check. Though this needs to deal with output pointers as well.
            match resolved {
                Normal("char") => {
                    s.line(&format!(
                        "char {} = luaL_checkstring(L, {})[0];",
                        param.paramname, lua_idx
                    ));
                    param_names.push(param.paramname.clone());
                    lua_idx += 1;
                }
                Normal("double" | "float") => {
                    s.line(&format!(
                        "{} {} = luaL_checknumber(L, {});",
                        param.paramtype, param.paramname, lua_idx
                    ));
                    param_names.push(param.paramname.clone());
                    lua_idx += 1;
                }
                Normal("int" | "unsigned char") => {
                    s.line(&format!(
                        "{} {} = static_cast<{}>(luaL_checkint(L, {}));",
                        param.paramtype, param.paramname, param.paramtype, lua_idx
                    ));
                    param_names.push(param.paramname.clone());
                    lua_idx += 1;
                }
                Normal("bool") => {
                    s.line(&format!("bool {} = lua_toboolean(L, {});", param.paramname, lua_idx));
                    param_names.push(param.paramname.clone());
                    lua_idx += 1;
                }
                _ if resolved.is_buffer() && resolved.is_const() => {
                    if (method.methodname_flat == "SteamAPI_ISteamUser_RequestEncryptedAppTicket"
                        && param.paramname == "pDataToInclude")
                        || (method.methodname_flat == "SteamAPI_ISteamScreenshots_WriteScreenshot"
                            && param.paramname == "pubRGB")
                    {
                        // Special case, it is missing the const
                        s.line(&format!(
                            "char *{} = const_cast<char*>(luaL_checkstring(L, {}));",
                            param.paramname, lua_idx
                        ));
                    } else {
                        s.line(&format!(
                            "const char *{} = luaL_checkstring(L, {});",
                            param.paramname, lua_idx
                        ));
                    }
                    param_names.push(param.paramname.clone());
                    lua_idx += 1;
                }
                Normal("uint64")
                | Normal("unsigned long long")
                | Normal("CSteamID")
                | Normal("CGameID") => {
                    s.line(&format!(
                        "{} {}(luasteam::checkuint64(L, {}));",
                        param.paramtype, param.paramname, lua_idx
                    ));
                    param_names.push(param.paramname.clone());
                    lua_idx += 1;
                }
                Normal(_) => {
                    // Skip methods with unknown types for now
                    println!("Unsupported param type: {}", param.paramtype);
                    stats.unsupported_types.insert(param.paramtype.clone());
                    return None;
                }
                CppType::Array { .. } => {
                    unreachable!()
                }
                Pointer {
                    ttype: _,
                    is_const: false,
                } => {
                    if let Some(size_param) = param.array_size_param() {
                        // Assuming it is the next non array parameter (because of lua_idx)
                        // but sometimes it works for two arrays like in GetSupportedGameVersionData (so we store it in sz_param_to_ignore)
                        if sz_param_to_ignore.is_some() {
                            assert!(sz_param_to_ignore.as_ref().unwrap() == size_param);
                        } else {
                            let p = method.params.iter().find(|p| p.paramname == size_param);
                            if let Some(p) = p {
                                sz_param_to_ignore = Some(size_param.to_string());
                                s.line(&format!(
                                    "{} {} = luaL_checkint(L, {});",
                                    p.paramtype
                                        .strip_suffix(" *")
                                        .unwrap_or(p.paramtype.as_str()),
                                    size_param,
                                    lua_idx
                                ));
                                lua_idx += 1;
                            } else if let Some(c) =
                                self.api.consts.iter().find(|c| c.constname == size_param)
                            {
                                let _ = c;
                            } else {
                                println!("Unknown size: {} {}", size_param, param.paramname);
                                return None;
                            }
                        }
                        // Consider the original type, since e.g. we want the enum type, not it
                        let pointee_type = param
                            .paramtype
                            .strip_suffix(" *")
                            .expect("Malformed pointer type");
                        s.line(&format!(
                            "std::vector<{}> {}({});",
                            if pointee_type != "void" {
                                pointee_type
                            } else {
                                "unsigned char"
                            },
                            param.paramname,
                            size_param
                        ));
                        param_names.push(format!("{}.data()", param.paramname));
                        pointer_params.push((param, true));
                    } else {
                        // Create a default variable with that name and type
                        s.line(&format!(
                            "{} {};",
                            param
                                .paramtype
                                .strip_suffix(" *")
                                .expect("Malformed pointer type"),
                            param.paramname
                        ));
                        param_names.push(format!("&{}", param.paramname));
                        pointer_params.push((param, false));
                    }
                }
                Pointer {
                    is_const: true,
                    ttype,
                } => {
                    if let Some(sz) = param.array_size_param() {
                        let p = &method.params[i + 1];
                        assert!(p.paramname == sz, "Unsupported arrays with size param that is not right after the array");
                        let lua_idx_str = lua_idx.to_string();
                        let (ok, code) = self.generate_check(
                            &param.paramtype,
                            CppType::Array {
                                ttype,
                                size: sz,
                                is_const: true,
                            },
                            true,
                            &param.paramname,
                            &lua_idx_str,
                            1,
                        );
                        if ok {
                            assert!(sz_param_to_ignore.is_none());
                            sz_param_to_ignore = Some(sz.to_string());
                            lua_idx += 1;
                            s.line(&format!(
                                "{} {} = luaL_checkint(L, {});",
                                p.paramtype
                                    .strip_suffix(" *")
                                    .unwrap_or(p.paramtype.as_str()),
                                sz,
                                lua_idx
                            ));
                            lua_idx += 1;

                            s.raw(&code);
                            param_names.push(format!("{}.data()", param.paramname));
                        } else {
                            println!("Size param {} not found or unsupported array ({})", sz, ok);
                            return None;
                        }
                    } else {
                        println!(
                            "Unsupported const non-buffer pointer parameter: {} {}",
                            param.paramtype, param.paramname
                        );
                        stats.unsupported_types.insert(param.paramtype.clone());
                        return None;
                    }
                }
            }
            i += 1;
        }
        assert!(sz_param_to_ignore.is_none());

        let call = format!(
            "{}->{}({})",
            interface_getter,
            method.methodname,
            param_names.join(", ")
        );

        // Calculate return count
        let mut return_count = 0;

        if method.returntype == "void" {
            s.line(&format!("{};", call));
        } else {
            s.line(&format!("{} __ret = {};", method.returntype, call));
            let (ok, push) = self.generate_push(&method.returntype, "__ret", 1);
            if !ok {
                // Skip methods with unknown return types
                stats.unsupported_types.insert(method.returntype.clone());
                return None;
            }
            s.raw(&push);
            return_count = 1;
        }

        // Push pointer output values onto stack
        for (param, is_array) in pointer_params {
            let resolved = self.resolve_type(&param.paramtype);
            if is_array {
                if resolved.is_buffer() {
                    if matches!(resolved, CppType::Pointer { ttype: "char", .. }) {
                        // A string with variable size
                        s.line(&format!(
                            "lua_pushstring(L, reinterpret_cast<const char*>({}.data()));",
                            param.paramname
                        ));
                    } else {
                        // This should probably go somewhere in the JSON and thus in the fix_* functions
                        let size = if let Some(sz) = param.array_size_param()
                            && method.param(sz).paramname.ends_with(" *")
                        {
                            // If the size is a pointer, it is updated, use that
                            sz
                        } else if [
                            "SteamAPI_ISteamRemoteStorage_FileReadAsyncComplete",
                            "SteamAPI_ISteamRemoteStorage_UGCRead",
                            "SteamAPI_ISteamUtils_GetImageRGBA",
                            "SteamAPI_ISteamUtils_GetAPICallResult",
                            "SteamAPI_ISteamGameServer_GetNextOutgoingPacket",
                        ]
                        .contains(&method.methodname_flat.as_str())
                        {
                            param.array_size_param().unwrap()
                        } else if [
                            "SteamAPI_ISteamRemoteStorage_FileRead",
                            "SteamAPI_ISteamFriends_GetClanChatMessage",
                            "SteamAPI_ISteamFriends_GetFriendMessage",
                            "SteamAPI_ISteamMatchmaking_GetLobbyChatEntry",
                        ]
                        .contains(&method.methodname_flat.as_str())
                        {
                            "__ret"
                        } else {
                            println!(
                                "Unsupported void* pointer parameter '{}' in method '{}', cannot determine size",
                                param.paramname, method.methodname
                            );
                            return None;
                        };
                        // A buffer with fixed size
                        s.line(&format!(
                            "lua_pushlstring(L, reinterpret_cast<const char*>({}.data()), {});",
                            param.paramname, size
                        ));
                    }
                } else {
                    let size = if let Some(oac) = param.array_size_param()
                        && self.api.consts.iter().any(|c| c.constname == oac)
                    {
                        // If the size is a constant, simply use the same size
                        oac
                    } else if [
                        "SteamAPI_ISteamFriends_GetFriendsGroupMembersList",
                        "SteamAPI_ISteamFriends_DownloadClanActivityCounts",
                        "SteamAPI_ISteamParties_GetAvailableBeaconLocations",
                        "SteamAPI_ISteamUserStats_GetDownloadedLeaderboardEntry",
                    ]
                    .contains(&method.methodname_flat.as_str())
                    {
                        // Some special case where the size is the same as the one you sent
                        param.array_size_param().unwrap()
                    } else if ["SteamAPI_ISteamApps_GetInstalledDepots"]
                        .contains(&method.methodname_flat.as_str())
                    {
                        // Some special case where the size is returned
                        "__ret"
                    } else {
                        // Not sure about the size, will it always be the one you sent?
                        println!("Unknown size for array push: {}", param.paramtype);
                        stats.unsupported_types.insert(param.paramtype.clone());
                        return None;
                    };
                    if let Some(code) = self.push_array(
                        param.paramtype.strip_suffix(" *").expect("Invalid pointer"),
                        &param.paramname,
                        size,
                        1,
                    ) {
                        s.raw(&code);
                    } else {
                        stats.unsupported_types.insert(param.paramtype.clone());
                        return None;
                    }
                }
            } else {
                let (ok, push) = self.generate_push(
                    param.paramtype.strip_suffix(" *").expect("Invalid pointer"),
                    &param.paramname,
                    1,
                );
                if !ok {
                    println!(
                        "Unsupported pointer base type in push: '{}'",
                        param.paramtype
                    );
                    stats.unsupported_types.insert(param.paramtype.clone());
                    return None;
                }
                s.raw(&push);
                return_count += 1;
            }
        }

        s.line(&format!("return {};", return_count));
        s.indent_left();
        s.line("}");
        Some((lua_method_name, s.finish()))
    }
}

fn main() {
    let json_path = "../sdk/public/steam/steam_api.json";
    let json_str = fs::read_to_string(json_path).expect("Unable to read steam_api.json");
    let mut api: SteamApi = serde_json::from_str(&json_str).expect("Unable to parse JSON");
    api.apply_fixes();

    let mut generator = Generator::new(api);
    generator.generate();
}
