use std::collections::{HashMap, HashSet};
use std::fs;
use std::path::Path;

mod code_builder;
mod cpp_type;
mod doc_generator;
mod interface_gen;
mod lua_type_info;
mod luals_generator;
mod schema;
mod struct_gen;
mod type_codegen;
mod type_resolver;

use code_builder::CodeBuilder;
use doc_generator::DocGenerator;
use lua_type_info::{LType, LuaMethodSignature};
use luals_generator::LuaLsGenerator;
use schema::{CallbackStruct, Method, SkipReason, Stats, SteamApi};
use type_resolver::TypeResolver;

pub(crate) static COUNTER: std::sync::atomic::AtomicUsize = std::sync::atomic::AtomicUsize::new(0);
//
// Structs with custom manual implementations — skip auto-generation but register push/check.
// Format: (name, reason_for_manual_impl)
pub(crate) const MANUAL_STRUCTS: [(&str, &str); 1] = [(
    "SteamNetworkingMessage_t",
    "manually implemented in SteamNetworkingMessage.cpp; not in steam_api.json; pointer-based push/check",
)];
// Subset of MANUAL_STRUCTS that also provide a check_{}_ptr function returning a pointer,
// avoiding a copy when passing as const pointer/reference in method params.
pub(crate) const MANUAL_STRUCTS_WITH_PTR: [&str; 0] = [];

pub struct StructGenOutput {
    pub name: String,
    pub cpp_code: String,
    pub namespace_code: String,
    pub init_code: String,
    pub shutdown_code: String,
    pub add_code: String,
    // For documentation
    pub readable_fields: Vec<(String, LType)>, // (fieldname, ltype)
    pub method_signatures: Vec<(String, LuaMethodSignature)>, // (lua_name, sig)
    pub skipped_methods: Vec<(String, SkipReason)>, // (StructName::MethodName, reason)
}

struct Generator {
    api: SteamApi,
    type_resolver: TypeResolver,
    interface_callbacks: HashMap<String, Vec<CallbackStruct>>,
    added_structs: HashSet<String>,
    added_structs_with_ptr: HashSet<String>,
    added_callback_interfaces: HashSet<String>,
    opaque_handles: HashSet<String>,
    generated_callresults: HashSet<String>,
    doc_generator: DocGenerator,
    luals_generator: LuaLsGenerator,
}

impl Generator {
    fn new(api: SteamApi) -> Self {
        // Build interface enums list for TypeResolver
        let interface_enums: Vec<(String, Vec<schema::Enum>)> = api
            .interfaces
            .iter()
            .map(|iface| (iface.classname.clone(), iface.enums.clone()))
            .collect();

        let type_resolver = TypeResolver::from_api(&api.typedefs, &api.enums, &interface_enums);

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

        let doc_generator = DocGenerator::new().with_structs(api.structs.clone());
        let luals_generator = LuaLsGenerator::new();
        let opaque_handles = type_resolver.opaque_handles().clone();

        Self {
            api,
            type_resolver,
            interface_callbacks,
            added_structs: HashSet::new(),
            added_structs_with_ptr: HashSet::new(),
            added_callback_interfaces: HashSet::new(),
            opaque_handles,
            generated_callresults: HashSet::new(),
            doc_generator,
            luals_generator,
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

    fn manual_method_blocklist(&self) -> HashMap<String, SkipReason> {
        let mut blocklist = HashMap::new();

        // Cursor method is not used
        blocklist.insert(
            "SteamAPI_ISteamUGC_CreateQueryAllUGCRequestCursor".to_string(),
            SkipReason::ManualBlocklist("cursor method is not used".to_string()),
        );

        // Unused method, not even in API Reference
        blocklist.insert(
            "SteamAPI_ISteamUGC_GetQueryFirstUGCKeyValueTag".to_string(),
            SkipReason::ManualBlocklist("unused, not even in API Reference".to_string()),
        );

        // Very weird, out_array_count seems to be all wrong
        blocklist.insert(
            "SteamAPI_ISteamInventory_GetItemsWithPrices".to_string(),
            SkipReason::ManualBlocklist("out_array_count seems to be wrong".to_string()),
        );

        // char** output semantics unclear (Steam sets internal pointer; lifetime is unknown)
        blocklist.insert(
            "SteamAPI_ISteamRemoteStorage_GetUGCDetails".to_string(),
            SkipReason::ManualBlocklist("char** output semantics unclear".to_string()),
        );

        // Has function pointers — manual implementation in Client.cpp shared with Utils
        blocklist.insert(
            "SteamAPI_ISteamUtils_SetWarningMessageHook".to_string(),
            SkipReason::ManualImpl(
                "delegates to Client.SetWarningMessageHook trampoline".to_string(),
            ),
        );

        // Manually implemented in Core.cpp as a Lua function trampoline
        blocklist.insert(
            "SteamAPI_ISteamClient_SetWarningMessageHook".to_string(),
            SkipReason::ManualImpl("Lua function trampoline in Core.cpp".to_string()),
        );

        blocklist.insert(
            "SteamAPI_ISteamParties_CreateBeacon".to_string(),
            SkipReason::ManualBlocklist("requires custom implementation".to_string()),
        );
        blocklist.insert(
            "SteamAPI_ISteamNetworkingUtils_SetConfigValue".to_string(),
            SkipReason::ManualBlocklist("Needs careful dealing with void*".to_string()),
        );
        blocklist.insert(
            "SteamAPI_ISteamNetworkingUtils_SetConfigValueStruct".to_string(),
            SkipReason::ManualBlocklist("Needs careful dealing with void*".to_string()),
        );
        blocklist.insert(
            "SteamAPI_ISteamInventory_SerializeResult".to_string(),
            SkipReason::ManualBlocklist("Uses nullptr as input, we don't support it".to_string()),
        );
        for name in [
            "SteamAPI_ISteamNetworkingUtils_SetGlobalCallback_SteamNetConnectionStatusChanged",
            "SteamAPI_ISteamNetworkingUtils_SetGlobalCallback_SteamNetAuthenticationStatusChanged",
            "SteamAPI_ISteamNetworkingUtils_SetGlobalCallback_SteamRelayNetworkStatusChanged",
            "SteamAPI_ISteamNetworkingUtils_SetGlobalCallback_FakeIPResult",
            "SteamAPI_ISteamNetworkingUtils_SetGlobalCallback_MessagesSessionRequest",
            "SteamAPI_ISteamNetworkingUtils_SetGlobalCallback_MessagesSessionFailed",
        ] {
            blocklist.insert(
                name.to_string(),
                SkipReason::ManualImpl(
                    "Lua function trampoline in networkingUtils.cpp".to_string(),
                ),
            );
        }

        // SteamNetworkingMessage_t is manually implemented (not in steam_api.json, pointer-based)
        for (name, reason) in [
            (
                "SteamAPI_ISteamNetworkingUtils_AllocateMessage",
                "SteamNetworkingMessage_t binding in NetworkingUtils.cpp",
            ),
            (
                "SteamAPI_ISteamNetworkingSockets_ReceiveMessagesOnConnection",
                "SteamNetworkingMessage_t out-array in NetworkingSockets.cpp",
            ),
            (
                "SteamAPI_ISteamNetworkingSockets_ReceiveMessagesOnPollGroup",
                "SteamNetworkingMessage_t out-array in NetworkingSockets.cpp",
            ),
            (
                "SteamAPI_ISteamNetworkingSockets_SendMessages",
                "SteamNetworkingMessage_t input-array in NetworkingSockets.cpp",
            ),
        ] {
            blocklist.insert(name.to_string(), SkipReason::ManualImpl(reason.to_string()));
        }

        // Not yet implemented — blocked until SteamNetworkingMessage_t out-array in NetworkingMessages
        blocklist.insert(
            "SteamAPI_ISteamNetworkingMessages_ReceiveMessagesOnChannel".to_string(),
            SkipReason::ManualBlocklist(
                "SteamNetworkingMessage_t out-array; not yet implemented".to_string(),
            ),
        );

        for m in self
            .api
            .interfaces
            .iter()
            .find(|i| i.classname == "ISteamClient")
            .unwrap()
            .methods
            .iter()
        {
            if m.methodname.starts_with("GetISteam") {
                blocklist.insert(
                    format!("SteamAPI_ISteamClient_{}", m.methodname),
                    SkipReason::ManualBlocklist("Custom acessors are not supported".to_string()),
                );
            }
        }

        blocklist
    }

    pub(crate) fn lua_method_public_name(method: &Method) -> String {
        let flat_tail = method
            .methodname_flat
            .rsplit('_')
            .next()
            .unwrap_or(method.methodname.as_str());

        if let Some(suffix) = flat_tail.strip_prefix(&method.methodname)
            && !suffix.is_empty()
        {
            format!("{}{}", method.methodname, suffix)
        } else {
            method.methodname.clone()
        }
    }

    fn generate(&mut self) {
        let mut stats = Stats {
            interfaces_total: self.api.interfaces.len(),
            ..Default::default()
        };

        let auto_dir = Path::new("../src/auto");
        if auto_dir.exists() {
            fs::remove_dir_all(auto_dir).expect("Unable to delete src/auto");
        }
        fs::create_dir_all(auto_dir).expect("Unable to create src/auto");

        let docs_auto_dir = Path::new("../docs/auto");
        if docs_auto_dir.exists() {
            fs::remove_dir_all(docs_auto_dir).expect("Unable to delete docs/auto");
        }
        fs::create_dir_all(docs_auto_dir).expect("Unable to create docs/auto");

        let luals_dir = Path::new("../luals");
        if luals_dir.exists() {
            for entry in fs::read_dir(luals_dir).expect("Unable to read luals") {
                let entry = entry.expect("Unable to read luals entry");
                let path = entry.path();
                if path.extension().and_then(|e| e.to_str()) == Some("lua") {
                    fs::remove_file(&path).expect("Unable to delete luals file");
                }
            }
        }
        fs::create_dir_all(luals_dir).expect("Unable to create luals");

        let luals_dir = luals_dir.to_path_buf();

        // Start with structs to populate added_structs
        self.generate_structs(&mut stats);

        // Detect and generate callback interfaces (pure-virtual user-implemented interfaces)
        // Must run after generate_structs (to know which struct types are available for param push)
        // and before generate_interfaces (so added_callback_interfaces is populated for method params).
        self.generate_callback_interfaces();

        let mut interface_names = Vec::new();
        let mut gs_names: Vec<String> = Vec::new();
        let mut dual_accessor_names: std::collections::HashSet<String> = Default::default();
        // Maps interface name → table item count (methods + enums for user, methods-only for gs)
        let mut interface_counts: HashMap<String, usize> = Default::default();

        let method_blocklist = self.manual_method_blocklist();

        let interfaces = self.api.interfaces.clone();
        for interface in &interfaces {
            match self.generate_interface(interface, &method_blocklist, &mut stats, &luals_dir) {
                Ok((name, gs_name_opt, user_count, gs_count)) => {
                    if let Some(gs_name) = gs_name_opt {
                        interface_counts.insert(gs_name.clone(), gs_count);
                        gs_names.push(gs_name);
                        dual_accessor_names.insert(name.clone());
                    }
                    interface_counts.insert(name.clone(), user_count);
                    interface_names.push(name);
                    stats.interfaces_generated += 1;
                }
                Err(reason) => {
                    // Don't report callback interfaces as skipped — they are handled separately
                    // by generate_callback_interfaces() above.
                    if self
                        .added_callback_interfaces
                        .contains(&interface.classname)
                    {
                        // Show as fully covered in the coverage table
                        let n = interface.methods.len();
                        stats
                            .interface_coverage
                            .insert(interface.classname.clone(), (n, n, 0));
                        stats.interfaces_generated += 1;
                    } else {
                        stats
                            .skipped_interfaces
                            .push((interface.classname.clone(), reason));
                        // Track coverage for skipped interfaces too
                        stats
                            .interface_coverage
                            .insert(interface.classname.clone(), (interface.methods.len(), 0, 0));
                    }
                }
            }
        }

        self.generate_consts(&mut stats);
        self.generate_enums(&mut stats);
        self.generate_auto_header(
            &interface_names,
            &gs_names,
            &dual_accessor_names,
            &interface_counts,
        );
        self.luals_generator
            .write_index(&luals_dir, &interface_names, &self.opaque_handles);
        stats.print_summary();
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
            let (ok, push, _) = self.generate_push(&enm.consttype, &enm.constval, 1);
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

    fn generate_auto_header(
        &self,
        interfaces: &[String],
        gs_names: &[String],
        dual_accessor_names: &std::collections::HashSet<String>,
        interface_counts: &HashMap<String, usize>,
    ) {
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
        h.line("void init_structs_auto(lua_State *L);");
        h.line("void shutdown_structs_auto(lua_State *L);");
        h.line("void add_structs_auto(lua_State *L);");
        // Callback interface lifecycle + check functions
        if !self.added_callback_interfaces.is_empty() {
            h.line("void init_callback_interfaces_auto(lua_State *L);");
            h.line("void shutdown_callback_interfaces_auto(lua_State *L);");
            h.line("void add_callback_interfaces_auto(lua_State *L);");
            let mut cb_sorted: Vec<_> = self.added_callback_interfaces.iter().collect();
            cb_sorted.sort();
            for name in cb_sorted {
                h.line(&format!("{} *check_{}(lua_State *L, int idx);", name, name));
            }
        }
        let mut structs_sorted: Vec<_> = self.added_structs.iter().collect();
        structs_sorted.sort();
        for st in &structs_sorted {
            if MANUAL_STRUCTS.iter().any(|(n, _)| *n == st.as_str()) {
                continue;
            }
            h.line(&format!("{} check_{}(lua_State *L, int index);", st, st));
            h.line(&format!("void push_{}(lua_State *L, {} val);", st, st));
        }
        let mut structs_with_ptr_sorted: Vec<_> = self.added_structs_with_ptr.iter().collect();
        structs_with_ptr_sorted.sort();
        for st in structs_with_ptr_sorted {
            if MANUAL_STRUCTS.iter().any(|(n, _)| *n == st.as_str()) {
                continue; // declared in common.hpp
            }
            h.line(&format!(
                "{} *check_{}_ptr(lua_State *L, int index);",
                st, st
            ));
        }
        for name in interfaces {
            if dual_accessor_names.contains(name) {
                h.line(&format!(
                    "void register_{}_auto(lua_State *L, bool is_gs);",
                    name
                ));
            } else {
                h.line(&format!("void register_{}_auto(lua_State *L);", name));
            }
            h.line(&format!("void add_{}_auto(lua_State *L);", name));
            h.line(&format!("void init_{}_auto(lua_State *L);", name));
            h.line(&format!("void shutdown_{}_auto(lua_State *L);", name));
            h.line(&format!("extern int {}_ref;", name));
            if let Some(&count) = interface_counts.get(name) {
                h.line(&format!("static constexpr int {}_count = {};", name, count));
            }
        }
        for gs_name in gs_names {
            h.line(&format!("void add_{}_auto(lua_State *L);", gs_name));
            h.line(&format!("void init_{}_auto(lua_State *L);", gs_name));
            h.line(&format!("void shutdown_{}_auto(lua_State *L);", gs_name));
            h.line(&format!("extern int {}_ref;", gs_name));
            if let Some(&count) = interface_counts.get(gs_name) {
                h.line(&format!(
                    "static constexpr int {}_count = {};",
                    gs_name, count
                ));
            }
        }
        h.preceeding_blank_line();
        h.line("} // namespace luasteam");
        h.preceeding_blank_line();
        h.line("#endif // LUASTEAM_AUTO_HPP");
        fs::write("../src/auto/auto.hpp", h.finish()).expect("Unable to write auto.hpp");
        fs::write("../src/auto/.clang-format", "DisableFormat: true\n")
            .expect("Unable to write .clang-format");
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
