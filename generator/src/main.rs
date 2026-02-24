use std::collections::{HashMap, HashSet};
use std::fs;
use std::path::Path;

mod code_builder;
mod cpp_type;
mod doc_generator;
mod lua_type_info;
mod luals_generator;
mod schema;
mod type_resolver;

use code_builder::CodeBuilder;
use cpp_type::CppType;
use doc_generator::{CallbackInterfaceDocInfo, CallbackMethodDocInfo, CallbackParamDocInfo, DocGenerator, StructDocInfo};
use lua_type_info::{LType, LuaMethodSignature};
use luals_generator::LuaLsGenerator;
use schema::{CallbackStruct, Field, Interface, Method, Param, SkipReason, Stats, SteamApi, Struct};
use type_resolver::TypeResolver;

static COUNTER: std::sync::atomic::AtomicUsize = std::sync::atomic::AtomicUsize::new(0);
//
// Structs with custom manual implementations — skip auto-generation
const MANUAL_STRUCTS: [&str; 0] = [];
// Subset of MANUAL_STRUCTS that also provide a check_{}_ptr function returning a pointer,
// avoiding a copy when passing as const pointer/reference in method params.
const MANUAL_STRUCTS_WITH_PTR: [&str; 0] = [];

pub struct StructGenOutput {
    pub name: String,
    pub cpp_code: String,
    pub namespace_code: String,
    pub init_code: String,
    pub shutdown_code: String,
    pub add_code: String,
    // For documentation
    pub readable_fields: Vec<(String, LType)>,     // (fieldname, ltype)
    pub method_signatures: Vec<(String, LuaMethodSignature)>, // (lua_name, sig)
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

        // Has function pointers, can't be implemented automatically
        blocklist.insert(
            "SteamAPI_ISteamUtils_SetWarningMessageHook".to_string(),
            SkipReason::ManualBlocklist("has function pointers".to_string()),
        );

        blocklist.insert(
            "SteamAPI_ISteamParties_CreateBeacon".to_string(),
            SkipReason::ManualBlocklist("requires custom implementation".to_string()),
        );

        blocklist
    }

    fn lua_method_public_name(method: &Method) -> String {
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
            fs::remove_dir_all(luals_dir).expect("Unable to delete luals");
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

        let method_blocklist = self.manual_method_blocklist();

        let interfaces = self.api.interfaces.clone();
        for interface in &interfaces {
            match self.generate_interface(interface, &method_blocklist, &mut stats, &luals_dir) {
                Ok(name) => {
                    interface_names.push(name);
                    stats.interfaces_generated += 1;
                }
                Err(reason) => {
                    stats
                        .skipped_interfaces
                        .push((interface.classname.clone(), reason));
                    // Track coverage for skipped interfaces too
                    stats
                        .interface_coverage
                        .insert(interface.classname.clone(), (interface.methods.len(), 0));
                }
            }
        }

        self.generate_consts(&mut stats);
        self.generate_enums(&mut stats);
        self.generate_auto_header(&interface_names);
        self.luals_generator
            .write_index(&luals_dir, &interface_names, &self.opaque_handles);
        stats.print_summary();
    }

    fn generate_structs(&mut self, stats: &mut Stats) {
        let incomplete_structs = [
            "SteamDatagramHostedAddress",
            "SteamDatagramGameCoordinatorServerLogin",
            "SteamNetworkingMessage_t", // has protected destructor and function-pointer fields; not user-constructible
        ];
        stats.structs_total = self.api.structs.len();
        let mut outputs: Vec<StructGenOutput> = Vec::new();

        let structs = self.api.structs.clone();
        for st in &structs {
            if incomplete_structs.contains(&st.name.as_str()) {
                stats
                    .skipped_structs
                    .push((st.name.clone(), SkipReason::Incomplete));
                continue;
            }
            if MANUAL_STRUCTS.contains(&st.name.as_str()) {
                stats.skipped_structs.push((
                    st.name.clone(),
                    SkipReason::ManualBlocklist("has private fields; use accessor API".to_string()),
                ));
                // Still add to added_structs so generate_check/push normal path works
                self.added_structs.insert(st.name.clone());
                if MANUAL_STRUCTS_WITH_PTR.contains(&st.name.as_str()) {
                    self.added_structs_with_ptr.insert(st.name.clone());
                }
                continue;
            }
            match self.generate_struct(st) {
                Some(output) => {
                    // We are assuming a struct does not depend on one not yet declared
                    self.added_structs.insert(output.name.clone());
                    self.added_structs_with_ptr.insert(output.name.clone());
                    outputs.push(output);
                    stats.structs_generated += 1;
                }
                None => {
                    stats
                        .skipped_structs
                        .push((st.name.clone(), SkipReason::Incomplete));
                }
            }
        }

        let mut cpp = CodeBuilder::new();
        cpp.line("#include \"auto.hpp\"");
        cpp.line("#include <cstdlib>");
        cpp.line("#include <new>");
        cpp.preceeding_blank_line();

        // Code outside namespace (metatable refs, method funcs, index/newindex, constructors)
        for output in &outputs {
            cpp.raw(&output.cpp_code);
        }

        // Code inside namespace luasteam
        cpp.line("namespace luasteam {");
        cpp.preceeding_blank_line();

        // push / check / check_ptr functions
        for output in &outputs {
            cpp.raw(&output.namespace_code);
        }

        // Lifecycle functions
        cpp.line("void init_structs_auto(lua_State *L) {");
        for output in &outputs {
            cpp.raw(&output.init_code);
        }
        cpp.line("}");
        cpp.preceeding_blank_line();

        cpp.line("void shutdown_structs_auto(lua_State *L) {");
        for output in &outputs {
            cpp.raw(&output.shutdown_code);
        }
        cpp.line("}");
        cpp.preceeding_blank_line();

        cpp.line("void add_structs_auto(lua_State *L) {");
        for output in &outputs {
            cpp.raw(&output.add_code);
        }
        cpp.line("}");
        cpp.preceeding_blank_line();

        cpp.line("} // namespace luasteam");
        fs::write("../src/auto/structs.cpp", cpp.finish()).expect("Unable to write structs.cpp");

        // Generate RST documentation
        let doc_infos: Vec<StructDocInfo<'_>> = outputs
            .iter()
            .map(|o| StructDocInfo {
                name: &o.name,
                readable_fields: &o.readable_fields,
                method_signatures: &o.method_signatures,
            })
            .collect();
        let doc_content = self.doc_generator.generate_structs_doc(&doc_infos);
        fs::write("../docs/auto/structs.rst", doc_content).expect("Unable to write structs.rst");

        // Generate LuaLS definitions
        let luals_dir = Path::new("../luals");
        self.luals_generator.write_structs(luals_dir, &doc_infos);
    }

    fn generate_callback_interfaces(&mut self) {
        let interfaces = self.api.interfaces.clone();

        // Detect callback interfaces: no accessors and all methods return void.
        // These are pure-virtual C++ interfaces the user must implement (e.g. ISteamMatchmakingServerListResponse).
        let callback_interfaces: Vec<&Interface> = interfaces
            .iter()
            .filter(|iface| {
                iface.accessors.is_empty()
                    && !iface.methods.is_empty()
                    && iface.methods.iter().all(|m| m.returntype == "void")
            })
            .collect();

        if callback_interfaces.is_empty() {
            return;
        }

        // Populate added_callback_interfaces so generate_method can use them
        for iface in &callback_interfaces {
            self.added_callback_interfaces.insert(iface.classname.clone());
        }

        let mut cpp = CodeBuilder::new();
        cpp.line("#include \"auto.hpp\"");
        cpp.line("#include <new>");
        cpp.preceeding_blank_line();

        // For each callback interface, generate outside namespace: Impl struct, metatable ref,
        // constructor, and __gc.
        for iface in &callback_interfaces {
            let name = &iface.classname;

            // Static metatable ref
            cpp.line(&format!("static int {}Metatable_ref = LUA_NOREF;", name));
            cpp.preceeding_blank_line();

            // Impl struct
            cpp.line(&format!("struct {}Impl : public {} {{", name, name));
            cpp.indent_right();
            cpp.line("lua_State *L;");
            for method in &iface.methods {
                cpp.line(&format!("int ref_{};", method.methodname));
            }
            cpp.preceeding_blank_line();

            // Destructor
            cpp.line(&format!("~{}Impl() {{", name));
            cpp.indent_right();
            for method in &iface.methods {
                cpp.line(&format!("luaL_unref(L, LUA_REGISTRYINDEX, ref_{});", method.methodname));
            }
            cpp.indent_left();
            cpp.line("}");
            cpp.preceeding_blank_line();

            // Method overrides
            for method in &iface.methods {
                let params_decl: String = method
                    .params
                    .iter()
                    .map(|p| format!("{} {}", p.paramtype, p.paramname))
                    .collect::<Vec<_>>()
                    .join(", ");
                cpp.line(&format!("void {}({}) override {{", method.methodname, params_decl));
                cpp.indent_right();
                cpp.line(&format!("lua_rawgeti(L, LUA_REGISTRYINDEX, ref_{});", method.methodname));
                for param in &method.params {
                    let (ok, code, _) = self.generate_push(&param.paramtype, &param.paramname, cpp.indent());
                    if ok {
                        cpp.raw(&code);
                    } else {
                        cpp.line("lua_pushnil(L); // unsupported param type");
                    }
                }
                cpp.line(&format!("lua_call(L, {}, 0);", method.params.len()));
                cpp.indent_left();
                cpp.line("}");
            }

            cpp.indent_left();
            cpp.line("};");
            cpp.preceeding_blank_line();

            // Constructor: newISteamFooResponse({MethodName = fn, ...})
            cpp.line(&format!("static int lua_new{}(lua_State *L) {{", name));
            cpp.indent_right();
            cpp.line("luaL_checktype(L, 1, LUA_TTABLE);");
            cpp.line(&format!("auto *impl = ({}Impl*)lua_newuserdata(L, sizeof({}Impl));", name, name));
            cpp.line(&format!("new (impl) {}Impl();", name));
            cpp.line("impl->L = L;");
            for method in &iface.methods {
                cpp.line(&format!("lua_getfield(L, 1, \"{}\");", method.methodname));
                cpp.line(&format!("impl->ref_{} = luaL_ref(L, LUA_REGISTRYINDEX);", method.methodname));
            }
            cpp.line(&format!("lua_rawgeti(L, LUA_REGISTRYINDEX, {}Metatable_ref);", name));
            cpp.line("lua_setmetatable(L, -2);");
            cpp.line("return 1;");
            cpp.indent_left();
            cpp.line("}");
            cpp.preceeding_blank_line();

            // __gc
            cpp.line(&format!("static int {}_gc(lua_State *L) {{", name));
            cpp.indent_right();
            cpp.line(&format!("auto *impl = ({}Impl*)luaL_checkudata(L, 1, \"{}\");", name, name));
            cpp.line(&format!("impl->~{}Impl();", name));
            cpp.line("return 0;");
            cpp.indent_left();
            cpp.line("}");
            cpp.preceeding_blank_line();
        }

        // Namespace
        cpp.line("namespace luasteam {");
        cpp.preceeding_blank_line();

        // check_* functions
        for iface in &callback_interfaces {
            let name = &iface.classname;
            cpp.line(&format!("{} *check_{}(lua_State *L, int idx) {{", name, name));
            cpp.indent_right();
            cpp.line(&format!("return ({}Impl*)luaL_checkudata(L, idx, \"{}\");", name, name));
            cpp.indent_left();
            cpp.line("}");
            cpp.preceeding_blank_line();
        }

        // Lifecycle functions
        cpp.line("void init_callback_interfaces_auto(lua_State *L) {");
        cpp.indent_right();
        for iface in &callback_interfaces {
            let name = &iface.classname;
            cpp.line(&format!("luaL_newmetatable(L, \"{}\");", name));
            cpp.line(&format!("add_func(L, \"__gc\", {}_gc);", name));
            cpp.line(&format!("{0}Metatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);", name));
        }
        cpp.indent_left();
        cpp.line("}");
        cpp.preceeding_blank_line();

        cpp.line("void shutdown_callback_interfaces_auto(lua_State *L) {");
        cpp.indent_right();
        for iface in &callback_interfaces {
            let name = &iface.classname;
            cpp.line(&format!("luaL_unref(L, LUA_REGISTRYINDEX, {}Metatable_ref);", name));
            cpp.line(&format!("{}Metatable_ref = LUA_NOREF;", name));
        }
        cpp.indent_left();
        cpp.line("}");
        cpp.preceeding_blank_line();

        cpp.line("void add_callback_interfaces_auto(lua_State *L) {");
        cpp.indent_right();
        for iface in &callback_interfaces {
            let name = &iface.classname;
            cpp.line(&format!("add_func(L, \"new{}\", lua_new{});", name, name));
        }
        cpp.indent_left();
        cpp.line("}");
        cpp.preceeding_blank_line();

        cpp.line("} // namespace luasteam");

        fs::write("../src/auto/callback_interfaces.cpp", cpp.finish())
            .expect("Unable to write callback_interfaces.cpp");

        // Collect doc info by resolving param types
        let doc_infos: Vec<CallbackInterfaceDocInfo> = callback_interfaces
            .iter()
            .map(|iface| {
                let methods = iface
                    .methods
                    .iter()
                    .map(|method| {
                        let params = method
                            .params
                            .iter()
                            .map(|p| {
                                let (_, _, ltype) = self.generate_push(&p.paramtype, &p.paramname, 0);
                                CallbackParamDocInfo {
                                    name: p.paramname.clone(),
                                    ltype,
                                }
                            })
                            .collect();
                        CallbackMethodDocInfo {
                            name: method.methodname.clone(),
                            params,
                        }
                    })
                    .collect();
                CallbackInterfaceDocInfo {
                    name: iface.classname.clone(),
                    methods,
                }
            })
            .collect();

        let doc_content = self.doc_generator.generate_callback_interfaces_doc(&doc_infos);
        fs::write("../docs/auto/callback_interfaces.rst", doc_content)
            .expect("Unable to write callback_interfaces.rst");

        let luals_dir = Path::new("../luals");
        self.luals_generator.write_callback_interfaces(luals_dir, &doc_infos);
    }

    fn generate_struct_method(
        &self,
        struct_name: &str,
        method: &Method,
    ) -> Option<(String, String, String, LuaMethodSignature)> {
        if method.methodname == "Construct" {
            return None;
        }
        let lua_name = Self::lua_method_public_name(method);
        let c_func_name = format!("luasteam_{}_{}", struct_name, lua_name);
        let mut s = CodeBuilder::new();
        s.line(&format!("static int {}(lua_State *L) {{", c_func_name));
        s.indent_right();
        s.line(&format!(
            "{} *self = luasteam::check_{}_ptr(L, 1);",
            struct_name, struct_name
        ));

        let mut cpp_call_params = Vec::new();
        let mut lua_idx: usize = 2;
        let mut sig = LuaMethodSignature::default();

        for param in &method.params {
            let resolved = self.type_resolver.resolve_type(&param.paramtype);
            use CppType::*;
            if resolved.is_double_pointer() {
                return None;
            }
            let n = &param.paramname;
            let t = &param.paramtype;
            let idx = lua_idx.to_string();

            let ltype = match resolved {
                Normal("char") => {
                    s.line(&format!("char {} = luaL_checkstring(L, {})[0];", n, idx));
                    LType::Char
                }
                Normal("double" | "float") => {
                    s.line(&format!("{} {} = luaL_checknumber(L, {});", t, n, idx));
                    LType::Float
                }
                Normal("int" | "unsigned char") => {
                    s.line(&format!(
                        "{} {} = static_cast<{}>(luaL_checkint(L, {}));",
                        t, n, t, idx
                    ));
                    LType::Integer
                }
                Normal("bool") => {
                    s.line(&format!("bool {} = lua_toboolean(L, {});", n, idx));
                    LType::Boolean
                }
                Normal("uint64") | Normal("unsigned long long") | Normal("CSteamID") | Normal("CGameID") => {
                    s.line(&format!("{} {}(luasteam::checkuint64(L, {}));", t, n, idx));
                    LType::Uint64
                }
                _ if resolved.is_buffer() && resolved.is_const() => {
                    // For buffers, get the actual element type (char or unsigned char)
                    let buffer_elem_type = if let CppType::Pointer { ttype, .. } = resolved {
                        ttype
                    } else {
                        "char"
                    };
                    if buffer_elem_type == "char" {
                        s.line(&format!("const char *{} = luaL_checkstring(L, {});", n, idx));
                    } else {
                        s.line(&format!(
                            "const {t} *{n} = reinterpret_cast<const {t} *>(luaL_checkstring(L, {idx}));",
                            t = buffer_elem_type, n = n, idx = idx
                        ));
                    }
                    LType::String
                }
                Normal(type_name) => {
                    if self.opaque_handles.contains(type_name) {
                        s.line(&format!(
                            "{} {} = ({})lua_touserdata(L, {});",
                            type_name, n, type_name, idx
                        ));
                        LType::LightUserdata(type_name.to_string())
                    } else if self.added_structs.contains(type_name) {
                        s.line(&format!(
                            "{} {} = luasteam::check_{}(L, {});",
                            type_name, n, type_name, idx
                        ));
                        LType::Userdata(type_name.to_string())
                    } else {
                        return None;
                    }
                }
                Pointer { is_const: true, ttype } => {
                    if self.added_structs_with_ptr.contains(ttype) {
                        s.line(&format!(
                            "const {} *{} = luasteam::check_{}_ptr(L, {});",
                            ttype, n, ttype, idx
                        ));
                    } else if self.added_structs.contains(ttype) {
                        s.line(&format!(
                            "{} {}_val = luasteam::check_{}(L, {});",
                            ttype, n, ttype, idx
                        ));
                        s.line(&format!("const {} *{} = &{}_val;", ttype, n, n));
                    } else {
                        return None;
                    }
                    LType::Userdata(ttype.to_string())
                }
                Reference { is_const: true, ttype } => {
                    if self.added_structs_with_ptr.contains(ttype) {
                        s.line(&format!(
                            "const {} &{} = *luasteam::check_{}_ptr(L, {});",
                            ttype, n, ttype, idx
                        ));
                    } else if self.added_structs.contains(ttype) {
                        s.line(&format!(
                            "{} {} = luasteam::check_{}(L, {});",
                            ttype, n, ttype, idx
                        ));
                    } else {
                        return None;
                    }
                    LType::Userdata(ttype.to_string())
                }
                _ => return None,
            };

            sig.add_param(n.to_string(), ltype);
            cpp_call_params.push(n.clone());
            lua_idx += 1;
        }

        let call = if cpp_call_params.is_empty() {
            format!("self->{}()", method.methodname)
        } else {
            format!("self->{}({})", method.methodname, cpp_call_params.join(", "))
        };

        let return_count;
        if method.returntype == "void" {
            s.line(&format!("{};", call));
            return_count = 0;
        } else {
            let resolved_ret = self.type_resolver.resolve_type(&method.returntype);
            match resolved_ret {
                CppType::Pointer { ttype, is_const: true } if self.added_structs.contains(ttype) => {
                    s.line(&format!("const {} *__ret = {};", ttype, call));
                    s.line("if (__ret != nullptr) {");
                    s.indent_right();
                    s.line(&format!("luasteam::push_{}(L, *__ret);", ttype));
                    s.indent_left();
                    s.line("} else {");
                    s.indent_right();
                    s.line("lua_pushnil(L);");
                    s.indent_left();
                    s.line("}");
                    sig.set_return_type(LType::Userdata(ttype.to_string()));
                    return_count = 1;
                }
                _ => {
                    let (ok, push, ret_ltype) = self.generate_push(&method.returntype, "__ret", 1);
                    if !ok {
                        return None;
                    }
                    s.line(&format!("{} __ret = {};", method.returntype, call));
                    s.raw(&push);
                    sig.set_return_type(ret_ltype);
                    return_count = 1;
                }
            }
        }

        s.line(&format!("return {};", return_count));
        s.indent_left();
        s.line("}");

        Some((lua_name, c_func_name, s.finish(), sig))
    }

    fn generate_struct(&self, st: &Struct) -> Option<StructGenOutput> {
        let name = &st.name;

        // Separate accessible vs private fields
        let accessible_fields: Vec<&Field> =
            st.fields.iter().filter(|f| !f.private).collect();

        // Generate method C functions
        let mut methods: Vec<(String, String)> = Vec::new(); // (lua_name, c_func_name)
        let mut method_cpp = String::new();
        let mut method_signatures: Vec<(String, LuaMethodSignature)> = Vec::new();
        for method in &st.methods {
            if let Some((lua_name, c_func_name, cpp_code, sig)) =
                self.generate_struct_method(name, method)
            {
                method_signatures.push((lua_name.clone(), sig));
                methods.push((lua_name, c_func_name));
                method_cpp.push_str(&cpp_code);
            }
        }

        // Determine readable fields (generate_push succeeds) and writable fields
        // (generate_check succeeds).
        let mut readable_fields: Vec<(&Field, String)> = Vec::new();
        let mut readable_field_types: Vec<(String, LType)> = Vec::new();
        let mut writable_fields: Vec<(&Field, String, String)> = Vec::new();
        // Fields with string_count: const char** arrays managed by Lua.
        let mut string_array_fields: Vec<(&Field, String)> = Vec::new(); // (field, count_fieldname)

        for field in &accessible_fields {
            // Special case: const char ** with string_count metadata
            if let Some(count_field) = &field.string_count {
                let count_field = count_field.clone();
                readable_field_types.push((field.fieldname.clone(), LType::Array(Box::new(LType::String))));
                string_array_fields.push((field, count_field));
                continue;
            }

            let (push_ok, push_code, ltype) =
                self.generate_push(&field.fieldtype, &format!("self->{}", field.fieldname), 2);
            if push_ok {
                readable_field_types.push((field.fieldname.clone(), ltype));
                readable_fields.push((field, push_code));
            }

            let (check_ok, check_code_newindex, _) = self.generate_check(
                &field.fieldtype,
                self.type_resolver.resolve_type(&field.fieldtype),
                false,
                &format!("self->{}", field.fieldname),
                "3",
                2,
            );
            let (_, check_code_ctor, _) = self.generate_check(
                &field.fieldtype,
                self.type_resolver.resolve_type(&field.fieldtype),
                false,
                &format!("ptr->{}", field.fieldname),
                "-1",
                3,
            );
            if check_ok {
                writable_fields.push((field, check_code_newindex, check_code_ctor));
            }
        }

        let has_methods = !methods.is_empty();
        let has_readable = !readable_fields.is_empty() || !string_array_fields.is_empty();
        let has_writable = !writable_fields.is_empty() || !string_array_fields.is_empty();
        let has_gc = !string_array_fields.is_empty();

        // Build cpp_code: outside namespace
        let mut cpp = CodeBuilder::new();

        // Static metatable ref
        cpp.line(&format!("static int {}Metatable_ref = LUA_NOREF;", name));
        cpp.preceeding_blank_line();

        // Method C functions
        if !method_cpp.is_empty() {
            cpp.raw(&method_cpp);
        }

        // __index function
        cpp.line(&format!("static int {}_index(lua_State *L) {{", name));
        cpp.indent_right();
        if has_methods {
            cpp.line("lua_getmetatable(L, 1);");
            cpp.line("lua_pushvalue(L, 2);");
            cpp.line("lua_rawget(L, -2);");
            cpp.line("if (!lua_isnil(L, -1)) return 1;");
            cpp.line("lua_pop(L, 2);");
        }
        if has_readable {
            cpp.line("if (lua_type(L, 2) != LUA_TSTRING) { lua_pushnil(L); return 1; }");
            cpp.line("const char *key = lua_tostring(L, 2);");
            cpp.line(&format!("{} *self = ({}*)lua_touserdata(L, 1);", name, name));
            for (field, push_code) in &readable_fields {
                cpp.line(&format!("if (strcmp(key, \"{}\") == 0) {{", field.fieldname));
                cpp.indent_right();
                cpp.raw(push_code);
                cpp.line("return 1;");
                cpp.indent_left();
                cpp.line("}");
            }
            for (field, count_field) in &string_array_fields {
                cpp.line(&format!("if (strcmp(key, \"{}\") == 0) {{", field.fieldname));
                cpp.indent_right();
                cpp.line("lua_newtable(L);");
                cpp.line(&format!("for (int32 _i = 0; _i < self->{}; _i++) {{", count_field));
                cpp.indent_right();
                cpp.line(&format!("lua_pushstring(L, self->{}[_i]);", field.fieldname));
                cpp.line("lua_rawseti(L, -2, _i + 1);");
                cpp.indent_left();
                cpp.line("}");
                cpp.line("return 1;");
                cpp.indent_left();
                cpp.line("}");
            }
        }
        cpp.line("lua_pushnil(L);");
        cpp.line("return 1;");
        cpp.indent_left();
        cpp.line("}");
        cpp.preceeding_blank_line();

        // __newindex function
        if has_writable {
            cpp.line(&format!("static int {}_newindex(lua_State *L) {{", name));
            cpp.indent_right();
            cpp.line("if (lua_type(L, 2) != LUA_TSTRING) { return 0; }");
            cpp.line("const char *key = lua_tostring(L, 2);");
            cpp.line(&format!("{} *self = ({}*)lua_touserdata(L, 1);", name, name));
            for (field, check_code, _) in &writable_fields {
                cpp.line(&format!("if (strcmp(key, \"{}\") == 0) {{", field.fieldname));
                cpp.indent_right();
                cpp.raw(check_code);
                cpp.line("return 0;");
                cpp.indent_left();
                cpp.line("}");
            }
            for (field, count_field) in &string_array_fields {
                cpp.line(&format!("if (strcmp(key, \"{}\") == 0) {{", field.fieldname));
                cpp.indent_right();
                cpp.line("luaL_checktype(L, 3, LUA_TTABLE);");
                cpp.line(&format!("if (self->{} != nullptr) {{", field.fieldname));
                cpp.indent_right();
                cpp.line(&format!("for (int32 _i = 0; _i < self->{}; _i++)", count_field));
                cpp.line(&format!("    free((void*)self->{}[_i]);", field.fieldname));
                cpp.line(&format!("delete[] self->{};", field.fieldname));
                cpp.indent_left();
                cpp.line("}");
                cpp.line(&format!("int32 _n = (int32)lua_objlen(L, 3);"));
                cpp.line("const char **_arr = new const char*[_n];");
                cpp.line("for (int32 _i = 0; _i < _n; _i++) {");
                cpp.indent_right();
                cpp.line("lua_rawgeti(L, 3, _i + 1);");
                cpp.line("_arr[_i] = strdup(luaL_checkstring(L, -1));");
                cpp.line("lua_pop(L, 1);");
                cpp.indent_left();
                cpp.line("}");
                cpp.line(&format!("self->{} = _arr;", field.fieldname));
                cpp.line(&format!("self->{} = _n;", count_field));
                cpp.line("return 0;");
                cpp.indent_left();
                cpp.line("}");
            }
            cpp.line(&format!(
                "return luaL_error(L, \"{} has no field '%%s'\", key);",
                name
            ));
            cpp.indent_left();
            cpp.line("}");
            cpp.preceeding_blank_line();
        }

        // __gc function (only for structs with managed string arrays)
        if has_gc {
            cpp.line(&format!("static int {}_gc(lua_State *L) {{", name));
            cpp.indent_right();
            cpp.line(&format!("{} *self = ({}*)lua_touserdata(L, 1);", name, name));
            for (field, count_field) in &string_array_fields {
                cpp.line(&format!("if (self->{} != nullptr) {{", field.fieldname));
                cpp.indent_right();
                cpp.line(&format!("for (int32 _i = 0; _i < self->{}; _i++)", count_field));
                cpp.line(&format!("    free((void*)self->{}[_i]);", field.fieldname));
                cpp.line(&format!("delete[] self->{};", field.fieldname));
                cpp.indent_left();
                cpp.line("}");
            }
            cpp.line("return 0;");
            cpp.indent_left();
            cpp.line("}");
            cpp.preceeding_blank_line();
        }

        // Constructor
        cpp.line(&format!("EXTERN int luasteam_new{}(lua_State *L) {{", name));
        cpp.indent_right();
        cpp.line(&format!(
            "{} *ptr = ({}*)lua_newuserdata(L, sizeof({}));",
            name, name, name
        ));
        cpp.line(&format!("new (ptr) {}();", name));
        if has_writable {
            cpp.line("if (!lua_isnoneornil(L, 1)) {");
            cpp.indent_right();
            cpp.line("luaL_checktype(L, 1, LUA_TTABLE);");
            for (field, _, check_code_ctor) in &writable_fields {
                cpp.line(&format!("lua_getfield(L, 1, \"{}\");", field.fieldname));
                cpp.line("if (!lua_isnil(L, -1)) {");
                cpp.indent_right();
                cpp.raw(check_code_ctor);
                cpp.indent_left();
                cpp.line("}");
                cpp.line("lua_pop(L, 1);");
            }
            for (field, count_field) in &string_array_fields {
                cpp.line(&format!("lua_getfield(L, 1, \"{}\");", field.fieldname));
                cpp.line("if (lua_istable(L, -1)) {");
                cpp.indent_right();
                cpp.line("int32 _n = (int32)lua_objlen(L, -1);");
                cpp.line("const char **_arr = new const char*[_n];");
                cpp.line("for (int32 _i = 0; _i < _n; _i++) {");
                cpp.indent_right();
                cpp.line("lua_rawgeti(L, -1, _i + 1);");
                cpp.line("_arr[_i] = strdup(luaL_checkstring(L, -1));");
                cpp.line("lua_pop(L, 1);");
                cpp.indent_left();
                cpp.line("}");
                cpp.line(&format!("ptr->{} = _arr;", field.fieldname));
                cpp.line(&format!("ptr->{} = _n;", count_field));
                cpp.indent_left();
                cpp.line("}");
                cpp.line("lua_pop(L, 1);");
            }
            cpp.indent_left();
            cpp.line("}");
        }
        cpp.line(&format!(
            "lua_rawgeti(L, LUA_REGISTRYINDEX, {}Metatable_ref);",
            name
        ));
        cpp.line("lua_setmetatable(L, -2);");
        cpp.line("return 1;");
        cpp.indent_left();
        cpp.line("}");
        cpp.preceeding_blank_line();

        let cpp_code = cpp.finish();

        // Build namespace_code: inside namespace luasteam
        let mut ns = CodeBuilder::new();

        // push function
        ns.line(&format!("void push_{}(lua_State *L, {} val) {{", name, name));
        ns.indent_right();
        ns.line(&format!(
            "{} *ptr = ({}*)lua_newuserdata(L, sizeof({}));",
            name, name, name
        ));
        ns.line("*ptr = val;");
        ns.line(&format!(
            "lua_rawgeti(L, LUA_REGISTRYINDEX, {}Metatable_ref);",
            name
        ));
        ns.line("lua_setmetatable(L, -2);");
        ns.indent_left();
        ns.line("}");
        ns.preceeding_blank_line();

        // check_ptr function
        ns.line(&format!(
            "{} *check_{}_ptr(lua_State *L, int nParam) {{",
            name, name
        ));
        ns.indent_right();
        ns.line(&format!(
            "luaL_argcheck(L, lua_isuserdata(L, nParam), nParam, \"{} expected\");",
            name
        ));
        ns.line(&format!(
            "lua_rawgeti(L, LUA_REGISTRYINDEX, {}Metatable_ref);",
            name
        ));
        ns.line("lua_getmetatable(L, nParam);");
        ns.line("bool ok = lua_rawequal(L, -1, -2);");
        ns.line("lua_pop(L, 2);");
        ns.line(&format!(
            "luaL_argcheck(L, ok, nParam, \"{} expected\");",
            name
        ));
        ns.line(&format!("return ({}*)lua_touserdata(L, nParam);", name));
        ns.indent_left();
        ns.line("}");
        ns.preceeding_blank_line();

        // check function (inline one-liner)
        ns.line(&format!(
            "{} check_{}(lua_State *L, int nParam) {{ return *check_{}_ptr(L, nParam); }}",
            name, name, name
        ));
        ns.preceeding_blank_line();

        let namespace_code = ns.finish();

        // Build init_code (indent 1, for inside init_structs_auto)
        let mut init = CodeBuilder::with_indent(1);
        init.line(&format!("// {} metatable", name));
        let table_size = methods.len() + 1 + has_writable as usize + has_gc as usize;
        init.line(&format!("lua_createtable(L, 0, {});", table_size));
        for (lua_name, c_func_name) in &methods {
            init.line(&format!("add_func(L, \"{}\", {});", lua_name, c_func_name));
        }
        init.line(&format!("add_func(L, \"__index\", {}_index);", name));
        if has_writable {
            init.line(&format!("add_func(L, \"__newindex\", {}_newindex);", name));
        }
        if has_gc {
            init.line(&format!("add_func(L, \"__gc\", {}_gc);", name));
        }
        init.line(&format!(
            "{}Metatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);",
            name
        ));
        let init_code = init.finish();

        // Build shutdown_code (indent 1)
        let mut shutdown = CodeBuilder::with_indent(1);
        shutdown.line(&format!(
            "luaL_unref(L, LUA_REGISTRYINDEX, {}Metatable_ref);",
            name
        ));
        shutdown.line(&format!("{}Metatable_ref = LUA_NOREF;", name));
        let shutdown_code = shutdown.finish();

        // Build add_code (indent 1)
        let mut add = CodeBuilder::with_indent(1);
        add.line(&format!(
            "add_func(L, \"new{}\", luasteam_new{});",
            name, name
        ));
        let add_code = add.finish();

        Some(StructGenOutput {
            name: name.clone(),
            cpp_code,
            namespace_code,
            init_code,
            shutdown_code,
            add_code,
            readable_fields: readable_field_types,
            method_signatures,
        })
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
            if MANUAL_STRUCTS.contains(&st.as_str()) {
                continue;
            }
            h.line(&format!("{} check_{}(lua_State *L, int index);", st, st));
            h.line(&format!("void push_{}(lua_State *L, {} val);", st, st));
        }
        let mut structs_with_ptr_sorted: Vec<_> = self.added_structs_with_ptr.iter().collect();
        structs_with_ptr_sorted.sort();
        for st in structs_with_ptr_sorted {
            if MANUAL_STRUCTS.contains(&st.as_str()) {
                continue; // declared in common.hpp
            }
            h.line(&format!("{} *check_{}_ptr(lua_State *L, int index);", st, st));
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
    ) -> (bool, String, LType) {
        let mut out = CodeBuilder::with_indent(indent);
        let type_prefix = if create_var {
            format!("{} ", original_type)
        } else {
            String::new()
        };
        match resolved {
            CppType::Normal(type_name) => match type_name {
                "int" | "unsigned char" => {
                    out.line(&format!(
                        "{}{} = static_cast<{}>(luaL_checkint(L, {}));",
                        type_prefix, value_accessor, original_type, lua_idx
                    ));
                    (true, out.finish(), LType::Integer)
                }
                "bool" => {
                    out.line(&format!(
                        "{}{} = lua_toboolean(L, {});",
                        type_prefix, value_accessor, lua_idx
                    ));
                    (true, out.finish(), LType::Boolean)
                }
                "double" | "float" => {
                    out.line(&format!(
                        "{}{} = static_cast<{}>(luaL_checknumber(L, {}));",
                        type_prefix, value_accessor, original_type, lua_idx
                    ));
                    (true, out.finish(), LType::Float)
                }
                "uint64" | "unsigned long long" | "CSteamID" | "CGameID" => {
                    let mut get = format!("luasteam::checkuint64(L, {})", lua_idx);
                    if type_name == "CSteamID" || type_name == "CGameID" {
                        get = format!("{}({})", type_name, get);
                    }
                    out.line(&format!("{}{} = {};", type_prefix, value_accessor, get));
                    (true, out.finish(), LType::Uint64)
                }
                _ => {
                    if self.opaque_handles.contains(type_name) {
                        out.line(&format!(
                            "{}{} = ({})lua_touserdata(L, {});",
                            type_prefix, value_accessor, type_name, lua_idx
                        ));
                        (true, out.finish(), LType::LightUserdata(type_name.to_string()))
                    } else if self.added_structs.contains(type_name) {
                        out.line(&format!(
                            "{}{} = luasteam::check_{}(L, {});",
                            type_prefix, value_accessor, type_name, lua_idx
                        ));
                        (true, out.finish(), LType::Userdata(type_name.to_string()))
                    } else {
                        out.line(&format!(
                            "// Unsupported check type: {} ({})",
                            original_type, type_name
                        ));
                        (false, out.finish(), LType::Integer)
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
                    out.line(&format!(
                        "const char *{} = luaL_checkstring(L, {});",
                        var, lua_idx
                    ));
                    out.line(&format!(
                        "if (strlen({}) >= {}) luaL_error(L, \"String too long\");",
                        var, size
                    ));

                    if create_var {
                        out.line(&format!("char {}[{}];", value_accessor, size));
                    }
                    out.line(&format!(
                        "memcpy({}, {}, sizeof({}));",
                        value_accessor, var, value_accessor
                    ));
                    (true, out.finish(), LType::String)
                } else {
                    out.line(&format!("luaL_checktype(L, {}, LUA_TTABLE);", lua_idx));
                    if create_var {
                        out.line(&format!(
                            "std::vector<{}> {}({});",
                            ttype, value_accessor, size
                        ));
                    }
                    out.line(&format!(
                        "for(decltype({}) i = 0; i < {}; i++) {{",
                        size, size
                    ));
                    out.indent_right();
                    out.line(&format!("lua_rawgeti(L, {lua_idx}, i+1);"));
                    let (ok, check, elem_ltype) = self.generate_check(
                        ttype,
                        self.type_resolver.resolve_type(ttype),
                        false,
                        &format!("{}[i]", value_accessor),
                        "-1",
                        out.indent(),
                    );
                    if ok {
                        out.raw(&check);
                        out.line("lua_pop(L, 1);");
                        out.indent_left();
                        out.line("}");
                        (true, out.finish(), LType::Array(Box::new(elem_ltype)))
                    } else {
                        out.line(&format!(
                            "// Unsupported check array type: {} [{}]",
                            ttype, size
                        ));
                        (false, out.finish(), LType::Integer)
                    }
                }
            }
            CppType::Pointer {
                ttype: "void",
                is_const: false,
            } => {
                out.line(&format!(
                    "{}{} = static_cast<void*>(luasteam::checkvoid_ptr(L, {}));",
                    type_prefix, value_accessor, lua_idx
                ));
                (true, out.finish(), LType::Table)
            }
            _ => {
                out.line(&format!("// Unsupported check type: {:?}", resolved));
                (false, out.finish(), LType::Integer)
            }
        }
    }

    fn generate_push(
        &self,
        ftype: &str,
        value_accessor: &str,
        indent: usize,
    ) -> (bool, String, LType) {
        let resolved = self.type_resolver.resolve_type(ftype);

        let (push, ltype) = match resolved {
            CppType::Normal(s) => match s {
                "double" | "float" => (
                    format!("lua_pushnumber(L, {});", value_accessor),
                    LType::Float,
                ),
                "bool" => (
                    format!("lua_pushboolean(L, {});", value_accessor),
                    LType::Boolean,
                ),
                "int" | "unsigned char" => (
                    format!("lua_pushinteger(L, {});", value_accessor),
                    LType::Integer,
                ),
                "uint64" | "unsigned long long" | "CSteamID" | "CGameID" => {
                    let push = if ftype == "CSteamID" {
                        format!(
                            "luasteam::pushuint64(L, {}.ConvertToUint64());",
                            value_accessor
                        )
                    } else if ftype == "CGameID" {
                        format!("luasteam::pushuint64(L, {}.ToUint64());", value_accessor)
                    } else {
                        format!("luasteam::pushuint64(L, {});", value_accessor)
                    };
                    (push, LType::Uint64)
                }
                _ => {
                    if self.opaque_handles.contains(s) {
                        (
                            format!("lua_pushlightuserdata(L, (void*){});", value_accessor),
                            LType::LightUserdata(s.to_string()),
                        )
                    } else if self.added_structs.contains(s) {
                        (format!("luasteam::push_{}(L, {});", s, value_accessor), LType::Userdata(s.to_string()))
                    } else {
                        (
                            format!("// Skip unsupported type: {}", ftype),
                            LType::Integer, // ignored
                        )
                    }
                }
            },
            _ if resolved.is_buffer() => (
                format!(
                    "lua_pushstring(L, reinterpret_cast<const char*>({}));",
                    value_accessor
                ),
                LType::String,
            ),
            CppType::Array {
                ttype,
                size,
                is_const: _,
            } => {
                if resolved.is_buffer() {
                    (
                        format!(
                            "lua_pushlstring(L, reinterpret_cast<const char*>({}), {});",
                            value_accessor, size
                        ),
                        LType::String,
                    )
                } else if let Some((code, ltype)) =
                    self.push_array(ttype, value_accessor, size.to_string().as_str(), indent)
                {
                    return (true, code, ltype);
                } else {
                    (
                        format!("// Skip unsupported array type: {}", ftype),
                        LType::Integer, // ignored
                    )
                }
            }
            CppType::Pointer {
                ttype: "void",
                is_const: false,
            } => (
                format!("luasteam::pushvoid_ptr(L, {});", value_accessor),
                LType::Table, // Wrong, should be something else
            ),
            CppType::Reference { ttype, .. } => {
                if self.added_structs.contains(ttype) {
                    (format!("luasteam::push_{}(L, {});", ttype, value_accessor), LType::Userdata(ttype.to_string()))
                } else {
                    (format!("// Skip unsupported reference type: {}", ftype), LType::Integer)
                }
            }
            _ => (
                format!("// Skip unsupported type: {}", ftype),
                LType::Integer, // ignored
            ),
        };
        let ok = !push.starts_with("//");
        let mut out = CodeBuilder::with_indent(indent);
        out.line(&push);
        (ok, out.finish(), ltype)
    }

    fn generate_callback_listener(
        &self,
        name_lower: &str,
        classname: &str,
        callbacks: &[CallbackStruct],
    ) -> String {
        let mut s = CodeBuilder::new();
        if callbacks.is_empty() {
            s.line(&format!("void init_{}_auto(lua_State *L) {{}}", name_lower));
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
            s.line(&format!("lua_getfield(L, -1, \"{}\");", lua_func_name));
            s.line("if (lua_isnil(L, -1)) {");
            s.indent_right();
            s.line("lua_pop(L, 2);");
            s.indent_left();
            s.line("} else {");
            s.indent_right();
            s.line(&format!("lua_createtable(L, 0, {});", cb.fields.len()));
            for field in &cb.fields {
                let (ok, push, _) = self.generate_push(
                    &field.fieldtype,
                    &format!("data->{}", field.fieldname),
                    s.indent(),
                );
                s.raw(&push);
                if ok {
                    s.line(&format!("lua_setfield(L, -2, \"{}\");", field.fieldname));
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

    fn get_callresult_struct(&self, name: &str) -> &CallbackStruct {
        self.api
            .callback_structs
            .iter()
            .find(|cb| cb.name == name)
            .expect("missing callresult struct")
    }

    fn generate_callresult_listeners(&self, callresults: &[String]) -> Result<String, SkipReason> {
        let mut s = CodeBuilder::new();
        for callresult in callresults {
            let cb = self.get_callresult_struct(callresult);
            s.line(&format!(
                "template <> void CallResultListener<{}>::Result({} *data, bool io_fail) {{",
                cb.name, cb.name
            ));
            s.indent_right();
            s.line("lua_State *L = luasteam::global_lua_state;");
            s.line("if (!lua_checkstack(L, 4)) {");
            s.indent_right();
            s.line("luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);");
            s.line("delete this;");
            s.line("return;");
            s.indent_left();
            s.line("}");
            s.line("lua_rawgeti(L, LUA_REGISTRYINDEX, callback_ref);");
            s.line("luaL_unref(L, LUA_REGISTRYINDEX, callback_ref);");
            s.line("if (io_fail || data == nullptr) {");
            s.indent_right();
            s.line("lua_pushnil(L);");
            s.indent_left();
            s.line("} else {");
            s.indent_right();
            s.line(&format!("lua_createtable(L, 0, {});", cb.fields.len()));
            for field in &cb.fields {
                let (ok, push, _) = self.generate_push(
                    &field.fieldtype,
                    &format!("data->{}", field.fieldname),
                    s.indent(),
                );
                s.raw(&push);
                if ok {
                    s.line(&format!("lua_setfield(L, -2, \"{}\");", field.fieldname));
                }
            }
            s.indent_left();
            s.line("}");
            s.line("lua_pushboolean(L, io_fail);");
            s.line("lua_call(L, 2, 0);");
            s.line("delete this;");
            s.indent_left();
            s.line("}");
            s.preceeding_blank_line();
        }
        Ok(s.finish())
    }

    fn generate_interface(
        &mut self,
        interface: &Interface,
        method_blocklist: &HashMap<String, SkipReason>,
        stats: &mut Stats,
        luals_dir: &Path,
    ) -> Result<String, SkipReason> {
        let mut cpp = CodeBuilder::new();
        let name = &interface.classname["ISteam".len()..];
        if interface.accessors.is_empty() {
            return Err(SkipReason::NoAccessors);
        }
        if interface.classname.starts_with("ISteamNetworking")
            || interface.classname == "ISteamHTTP"
        {
            return Err(SkipReason::RequiresCustomCode);
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
        cpp.raw(&self.generate_callback_listener(name, &interface.classname, callbacks));
        cpp.preceeding_blank_line();

        let mut callresults = HashSet::new();
        for method in &interface.methods {
            if let Some(callresult) = &method.callresult {
                callresults.insert(callresult.clone());
            }
        }
        if !callresults.is_empty() {
            let mut callresults_sorted: Vec<String> = callresults.into_iter().collect();
            callresults_sorted.sort();
            callresults_sorted.retain(|name| !self.generated_callresults.contains(name));
            if !callresults_sorted.is_empty() {
                cpp.raw(&self.generate_callresult_listeners(&callresults_sorted)?);
                cpp.preceeding_blank_line();
                for name in &callresults_sorted {
                    self.generated_callresults.insert(name.clone());
                }
            }
            cpp.preceeding_blank_line();
        }

        let mut generated_methods = Vec::new();
        let mut method_signatures = Vec::new();
        let interface_methods_total = interface.methods.len();
        let mut interface_methods_generated = 0;

        stats.methods_total += interface.methods.len();
        for method in &interface.methods {
            let full_method_name = format!("{}::{}", interface.classname, method.methodname);

            if let Some(reason) = method_blocklist.get(&method.methodname_flat) {
                stats
                    .skipped_methods
                    .push((full_method_name, reason.clone()));
                continue;
            }

            match self.generate_method(name, method, accessor_name) {
                Ok((lua_method_name, generated, signature)) => {
                    let params_str = method
                        .params
                        .iter()
                        .map(|p| format!("{} {}", p.paramtype, p.paramname))
                        .collect::<Vec<_>>()
                        .join(", ");
                    cpp.line("// In C++:");
                    cpp.line(&format!(
                        "// {} {}({});",
                        method.returntype, method.methodname, params_str
                    ));
                    cpp.line("// In Lua:");
                    cpp.line(&signature.to_lua_comment(name, &lua_method_name));
                    cpp.raw(&generated);
                    cpp.preceeding_blank_line();
                    generated_methods.push((method, lua_method_name.clone()));
                    method_signatures.push((lua_method_name, signature));
                    stats.methods_generated += 1;
                    interface_methods_generated += 1;
                }
                Err(reason) => {
                    stats.skipped_methods.push((full_method_name, reason));
                }
            }
        }

        // Track per-interface coverage
        stats.interface_coverage.insert(
            interface.classname.clone(),
            (interface_methods_total, interface_methods_generated),
        );

        self.luals_generator
            .write_interface(luals_dir, interface, &method_signatures, callbacks);

        // Generate register_..._auto function
        cpp.line(&format!("void register_{}_auto(lua_State *L) {{", name));
        cpp.indent_right();
        for (_, lua_name) in &generated_methods {
            let c_name = format!("luasteam_{}_{}", name, lua_name);
            cpp.line(&format!("add_func(L, \"{}\", {});", lua_name, c_name));
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
                cpp.line(&format!(
                    "lua_pushinteger(L, {}::{});",
                    interface.classname, val.name
                ));
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

        // Generate documentation
        let skipped_for_interface: Vec<(String, SkipReason)> = stats
            .skipped_methods
            .iter()
            .filter(|(method_name, _)| {
                method_name.starts_with(&format!("{}::", interface.classname))
            })
            .cloned()
            .collect();

        let doc_content = self.doc_generator.generate_interface_doc(
            interface,
            &method_signatures,
            &skipped_for_interface,
            callbacks,
        );

        let doc_path = format!("../docs/auto/{}.rst", name.to_lowercase());
        fs::write(doc_path, doc_content).expect("Unable to write doc file");

        Ok(name.to_owned())
    }

    fn push_array(
        &self,
        ttype: &str,
        value_accessor: &str,
        size: &str,
        indent: usize,
    ) -> Option<(String, LType)> {
        let mut s = CodeBuilder::with_indent(indent);

        s.line(&format!("lua_createtable(L, {}, 0);", size));
        s.indent_right();
        let (ok, push, ltype) =
            self.generate_push(ttype, &format!("{}[i]", value_accessor), s.indent());
        s.indent_left();
        if ok {
            s.line(&format!(
                "for(decltype({}) i = 0; i < {}; i++) {{",
                size, size
            ));
            s.indent_right();
            if !push.is_empty() {
                s.raw(&push);
            }
            s.line("lua_rawseti(L, -2, i+1);");
            s.indent_left();
            s.line("}");
        } else {
            // Don't print, just return None
            return None;
        }
        Some((s.finish(), LType::Array(Box::new(ltype))))
    }

    fn generate_method(
        &self,
        interface: &str,
        method: &Method,
        accessor_name: &str,
    ) -> Result<(String, String, LuaMethodSignature), SkipReason> {
        // Tricky ones to support:
        // GetItemDefinitionProperty - has a pointer that must have a value and returns another
        // GetItemsWithPrices - The JSON looks different from the API
        // AddPromoItems - Input arrays with counts
        // Most PublishedFileId_t * should be const, also pubBody in HTTP
        // GetImageRGBA - uint8* should be a byte buffer, probably
        let mut s = CodeBuilder::new();

        let interface_getter = format!("{}()", accessor_name);

        let lua_method_name = Self::lua_method_public_name(method);
        let c_method_name = format!("luasteam_{}_{}", interface, lua_method_name);
        s.line(&format!("EXTERN int {}(lua_State *L) {{", c_method_name));
        s.indent_right();

        if method.callresult.is_some() {
            s.line("int callback_ref = LUA_NOREF;");
            s.line("if (lua_isfunction(L, lua_gettop(L))) {");
            s.indent_right();
            s.line("lua_pushvalue(L, lua_gettop(L));");
            s.line("callback_ref = luaL_ref(L, LUA_REGISTRYINDEX);");
            s.indent_left();
            s.line("}");
        }

        // params used to call the function in C
        let mut cpp_call_params = Vec::new();
        // Pointer params that are returned as output: (param_info, custom_push_code)
        let mut pointer_params: Vec<(&Param, bool)> = Vec::new();
        let mut size_params_to_ignore: HashSet<String> = HashSet::new();

        let mut sig = LuaMethodSignature::default();

        let mut i = 0;
        let mut lua_idx = 1;
        while i < method.params.len() {
            let param = &method.params[i];
            let resolved = self.type_resolver.resolve_type(&param.paramtype);
            use CppType::*;
            if resolved.is_double_pointer() {
                // Case 1: char ** with out_string annotation — Steam sets *param to an internal string.
                if param.out_string.is_some() {
                    if let CppType::Pointer { ttype, .. } = &resolved
                        && ttype.contains("char")
                    {
                        s.line(&format!("char *{} = nullptr;", param.paramname));
                        cpp_call_params.push(format!("&{}", param.paramname));
                        pointer_params.push((param, false));
                        i += 1;
                        continue;
                    }
                }
                // Case 2: T** input array where T is an auto-generated struct with array_count.
                if let Some(sz) = &param.array_count {
                    if let CppType::Pointer { ttype, .. } = &resolved {
                        if let Some(struct_name) = ttype.strip_suffix(" *") {
                            if self.added_structs_with_ptr.contains(struct_name) {
                                let struct_name = struct_name.to_string();
                                let sz = sz.clone();
                                s.line(&format!("int {} = (int)lua_objlen(L, {});", sz, lua_idx));
                                s.line(&format!("std::vector<{} *> {}_vec({});", struct_name, param.paramname, sz));
                                s.line(&format!("for (int _i = 0; _i < {}; _i++) {{", sz));
                                s.indent_right();
                                s.line(&format!("lua_rawgeti(L, {}, _i + 1);", lua_idx));
                                s.line(&format!("{}_vec[_i] = luasteam::check_{}_ptr(L, -1);", param.paramname, struct_name));
                                s.line("lua_pop(L, 1);");
                                s.indent_left();
                                s.line("}");
                                s.line(&format!("{} **{} = {}_vec.data();", struct_name, param.paramname, param.paramname));
                                cpp_call_params.push(param.paramname.clone());
                                sig.add_param(param.paramname.clone(), LType::Array(Box::new(LType::Userdata(struct_name))));
                                size_params_to_ignore.insert(sz);
                                lua_idx += 1;
                                i += 1;
                                continue;
                            }
                        }
                    }
                }
                return Err(SkipReason::UnsupportedType(param.paramtype.clone()));
            }

            if size_params_to_ignore.remove(&param.paramname) {
                // This parameter is just the size for a previous string array, skip it
                match resolved {
                    CppType::Normal(_) => {
                        cpp_call_params.push(param.paramname.clone());
                    }
                    CppType::Pointer { .. } => {
                        // It is a value returned as well as the size passed in.
                        pointer_params.push((param, false));
                        cpp_call_params.push(format!("&{}", param.paramname.clone()));
                    }
                    _ => unreachable!("No array sizes"),
                }
                i += 1;
                continue;
            }

            // This is probably somewhat duplicated with generate_check. Though this needs to deal with output pointers as well.
            match resolved {
                Normal("char") => {
                    s.line(&format!(
                        "char {} = luaL_checkstring(L, {})[0];",
                        param.paramname, lua_idx
                    ));
                    cpp_call_params.push(param.paramname.clone());
                    sig.add_param(param.paramname.clone(), LType::Char);
                    lua_idx += 1;
                }
                Normal("double" | "float") => {
                    s.line(&format!(
                        "{} {} = luaL_checknumber(L, {});",
                        param.paramtype, param.paramname, lua_idx
                    ));
                    cpp_call_params.push(param.paramname.clone());
                    sig.add_param(param.paramname.clone(), LType::Float);
                    lua_idx += 1;
                }
                Normal("int" | "unsigned char") => {
                    s.line(&format!(
                        "{} {} = static_cast<{}>(luaL_checkint(L, {}));",
                        param.paramtype, param.paramname, param.paramtype, lua_idx
                    ));
                    cpp_call_params.push(param.paramname.clone());
                    sig.add_param(param.paramname.clone(), LType::Integer);
                    lua_idx += 1;
                }
                Normal("bool") => {
                    s.line(&format!(
                        "bool {} = lua_toboolean(L, {});",
                        param.paramname, lua_idx
                    ));
                    cpp_call_params.push(param.paramname.clone());
                    sig.add_param(param.paramname.clone(), LType::Boolean);
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
                    cpp_call_params.push(param.paramname.clone());
                    sig.add_param(param.paramname.clone(), LType::String);
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
                    cpp_call_params.push(param.paramname.clone());
                    sig.add_param(param.paramname.clone(), LType::Uint64);
                    lua_idx += 1;
                }
                Normal(handle_name) if self.opaque_handles.contains(handle_name) => {
                    s.line(&format!(
                        "{0} {1} = ({0})lua_touserdata(L, {2});",
                        param.paramtype, param.paramname, lua_idx
                    ));
                    cpp_call_params.push(param.paramname.clone());
                    sig.add_param(param.paramname.clone(), LType::LightUserdata(handle_name.to_string()));
                    lua_idx += 1;
                }
                Normal(_) => {
                    // Skip methods with unknown types for now
                    return Err(SkipReason::UnsupportedType(param.paramtype.clone()));
                }
                CppType::Array { .. } => {
                    unreachable!()
                }
                Pointer {
                    ttype: _,
                    is_const: false,
                } => {
                    // Callback interfaces are input pointers, not output pointers
                    if let Pointer { ttype, .. } = resolved
                        && self.added_callback_interfaces.contains(ttype)
                    {
                        s.line(&format!(
                            "{} *{} = luasteam::check_{}(L, {});",
                            ttype, param.paramname, ttype, lua_idx
                        ));
                        cpp_call_params.push(param.paramname.clone());
                        sig.add_param(param.paramname.clone(), LType::Userdata(ttype.to_string()));
                        lua_idx += 1;
                        i += 1;
                        continue;
                    }
                    if let Some(size_param) = param.input_array_size_param() {
                        let p = method.params.iter().find(|p| p.paramname == size_param);
                        if let Some(p) = p {
                            if !size_params_to_ignore.contains(size_param) {
                                size_params_to_ignore.insert(size_param.to_string());
                                s.line(&format!(
                                    "{} {} = luaL_checkint(L, {});",
                                    p.paramtype
                                        .strip_suffix(" *")
                                        .unwrap_or(p.paramtype.as_str()),
                                    size_param,
                                    lua_idx
                                ));
                                sig.add_param(size_param.to_string(), LType::Integer);
                                lua_idx += 1;
                            }
                        } else if let Some(c) =
                            self.api.consts.iter().find(|c| c.constname == size_param)
                        {
                            let _ = c;
                        } else {
                            return Err(SkipReason::UnsupportedType(format!(
                                "unknown size param: {}",
                                size_param
                            )));
                        }

                        if let Some(out_size_param) = param.out_array_count.as_deref()
                            && out_size_param != size_param
                        {
                            let out_param = method
                                .params
                                .iter()
                                .find(|p| p.paramname == out_size_param)
                                .ok_or_else(|| {
                                    SkipReason::UnsupportedType(format!(
                                        "unknown out size param: {}",
                                        out_size_param
                                    ))
                                })?;
                            if !size_params_to_ignore.contains(out_size_param) {
                                size_params_to_ignore.insert(out_size_param.to_string());
                                s.line(&format!(
                                    "{} {} = {};",
                                    out_param
                                        .paramtype
                                        .strip_suffix(" *")
                                        .unwrap_or(out_param.paramtype.as_str()),
                                    out_size_param,
                                    size_param
                                ));
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
                        cpp_call_params.push(format!("{}.data()", param.paramname));
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
                        cpp_call_params.push(format!("&{}", param.paramname));
                        pointer_params.push((param, false));
                    }
                }
                Pointer {
                    is_const: true,
                    ttype,
                } => {
                    if let Some(sz) = param.input_array_size_param() {
                        let p = method
                            .params
                            .iter()
                            .find(|p| p.paramname == sz)
                            .expect("Size param not found");
                        let lua_idx_str = lua_idx.to_string();
                        let (ok, code, ltype) = self.generate_check(
                            &param.paramtype,
                            CppType::Array {
                                ttype: param
                                    .paramtype
                                    .strip_suffix(" *")
                                    .and_then(|p| p.strip_prefix("const "))
                                    .expect("Malformed pointer type"),
                                size: sz,
                                is_const: true,
                            },
                            true,
                            &param.paramname,
                            &lua_idx_str,
                            1,
                        );
                        if ok {
                            sig.add_param(param.paramname.clone(), ltype);
                            if !size_params_to_ignore.contains(sz) {
                                size_params_to_ignore.insert(sz.to_string());
                                lua_idx += 1;
                                s.line(&format!(
                                    "{} {} = luaL_checkint(L, {});",
                                    p.paramtype
                                        .strip_suffix(" *")
                                        .unwrap_or(p.paramtype.as_str()),
                                    sz,
                                    lua_idx
                                ));
                                sig.add_param(sz.to_string(), LType::Integer);
                                lua_idx += 1;
                            }

                            s.raw(&code);
                            cpp_call_params.push(format!("{}.data()", param.paramname));
                        } else {
                            return Err(SkipReason::UnsupportedType(format!(
                                "size param {} not found",
                                sz
                            )));
                        }
                    } else {
                        // Non-array const pointer — treat as optional input (nil → nullptr).
                        // If the type has a _ptr check function, use it to avoid a copy.
                        if self.added_structs_with_ptr.contains(ttype) {
                            s.line(&format!(
                                "const {t} *{n} = lua_isnil(L, {idx}) ? nullptr : luasteam::check_{t}_ptr(L, {idx});",
                                t = ttype, n = param.paramname, idx = lua_idx
                            ));
                            cpp_call_params.push(param.paramname.clone());
                            sig.add_param(param.paramname.clone(), LType::Userdata(ttype.to_string()));
                            lua_idx += 1;
                        } else if self.added_structs.contains(ttype) {
                            s.line(&format!("{t} {n}_val;", t = ttype, n = param.paramname));
                            s.line(&format!(
                                "if (!lua_isnil(L, {idx})) {n}_val = luasteam::check_{t}(L, {idx});",
                                n = param.paramname, idx = lua_idx, t = ttype
                            ));
                            s.line(&format!(
                                "const {t} *{n} = lua_isnil(L, {idx}) ? nullptr : &{n}_val;",
                                t = ttype, n = param.paramname, idx = lua_idx
                            ));
                            cpp_call_params.push(param.paramname.clone());
                            sig.add_param(param.paramname.clone(), LType::Userdata(ttype.to_string()));
                            lua_idx += 1;
                        } else {
                            return Err(SkipReason::UnsupportedType(param.paramtype.clone()));
                        }
                    }
                }
                CppType::Reference {
                    ttype,
                    is_const: true,
                } => {
                    // Const reference — treat as required input.
                    // If the type has a _ptr check function, use it to avoid a copy.
                    if self.added_structs_with_ptr.contains(ttype) {
                        s.line(&format!(
                            "const {t} &{n} = *luasteam::check_{t}_ptr(L, {idx});",
                            t = ttype, n = param.paramname, idx = lua_idx
                        ));
                        cpp_call_params.push(param.paramname.clone());
                        sig.add_param(param.paramname.clone(), LType::Userdata(ttype.to_string()));
                        lua_idx += 1;
                    } else if self.added_structs.contains(ttype) {
                        s.line(&format!(
                            "{t} {n} = luasteam::check_{t}(L, {idx});",
                            t = ttype, n = param.paramname, idx = lua_idx
                        ));
                        cpp_call_params.push(param.paramname.clone());
                        sig.add_param(param.paramname.clone(), LType::Userdata(ttype.to_string()));
                        lua_idx += 1;
                    } else {
                        return Err(SkipReason::UnsupportedType(param.paramtype.clone()));
                    }
                }
                CppType::Reference { .. } => {
                    return Err(SkipReason::UnsupportedType(param.paramtype.clone()));
                }
            }
            i += 1;
        }

        let call = format!(
            "{}->{}({})",
            interface_getter,
            method.methodname,
            cpp_call_params.join(", ")
        );

        if method.returntype == "void" {
            assert!(
                method.callresult.is_none(),
                "void methods should not have callresults"
            );
            s.line(&format!("{};", call));
        } else {
            s.line(&format!("{} __ret = {};", method.returntype, call));
            if let Some(callresult) = &method.callresult {
                sig.add_param(
                    "callback".to_string(),
                    LType::CallresultCallback {
                        struct_t: callresult.clone(),
                    },
                );
                s.line("if (callback_ref != LUA_NOREF) {");
                s.indent_right();
                s.line(&format!(
                    "auto *listener = new luasteam::CallResultListener<{}>();",
                    callresult
                ));
                s.line("listener->callback_ref = callback_ref;");
                s.line(&format!(
                    "listener->call_result.Set(__ret, listener, &luasteam::CallResultListener<{}>::Result);",
                    callresult
                ));
                s.indent_left();
                s.line("}");
            }
            let (ok, push, ltype) = self.generate_push(&method.returntype, "__ret", 1);
            if !ok {
                // Skip methods with unknown return types
                return Err(SkipReason::UnsupportedType(method.returntype.clone()));
            }
            s.raw(&push);
            sig.set_return_type(ltype);
        }

        // Push pointer output values onto stack
        for (param, is_array) in pointer_params {
            let resolved = self.type_resolver.resolve_type(&param.paramtype);
            if is_array {
                if resolved.is_buffer() {
                    if matches!(resolved, CppType::Pointer { ttype: "char", .. }) {
                        // A string with variable size
                        s.line(&format!(
                            "lua_pushstring(L, reinterpret_cast<const char*>({}.data()));",
                            param.paramname
                        ));
                        sig.add_output_param(param.paramname.clone(), LType::String);
                    } else {
                        // This should probably go somewhere in the JSON and thus in the fix_* functions
                        let size = if let Some(sz) = param.output_array_size_param()
                            && method.param(sz).paramtype.ends_with(" *")
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
                            param.output_array_size_param().unwrap()
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
                            return Err(SkipReason::UnsupportedType(
                                "void* with unknown size".to_string(),
                            ));
                        };
                        // A buffer with fixed size
                        s.line(&format!(
                            "lua_pushlstring(L, reinterpret_cast<const char*>({}.data()), {});",
                            param.paramname, size
                        ));
                        sig.add_output_param(param.paramname.clone(), LType::String);
                    }
                } else {
                    let size = if [
                        "SteamAPI_ISteamApps_GetInstalledDepots",
                        "SteamAPI_ISteamRemotePlay_GetInput",
                        "SteamAPI_ISteamUserStats_GetGlobalStatHistoryInt64",
                        "SteamAPI_ISteamUserStats_GetGlobalStatHistoryDouble",
                        "SteamAPI_ISteamUGC_GetSubscribedItems",
                    ]
                    .contains(&method.methodname_flat.as_str())
                    {
                        // Some special case where the size is returned
                        "__ret"
                    } else if let Some(oac) = param.output_array_size_param() {
                        if self.api.consts.iter().any(|c| c.constname == oac) {
                            // If the size is a constant, simply use the same size
                            oac
                        } else if let Some(p) = method.params.iter().find(|p| p.paramname == oac)
                            && p.paramtype.ends_with(" *")
                        {
                            // If the size is a pointer, it is updated, use that
                            oac
                        } else if [
                            "SteamAPI_ISteamFriends_GetFriendsGroupMembersList",
                            "SteamAPI_ISteamFriends_DownloadClanActivityCounts",
                            "SteamAPI_ISteamParties_GetAvailableBeaconLocations",
                            "SteamAPI_ISteamUserStats_GetDownloadedLeaderboardEntry",
                        ]
                        .contains(&method.methodname_flat.as_str())
                        {
                            // Some special case where the size is returned in a parameter that is not the one you sent
                            oac
                        } else {
                            return Err(SkipReason::UnsupportedType(format!(
                                "unknown array size: {}",
                                param.paramtype
                            )));
                        }
                    } else {
                        // Not sure about the size, will it always be the one you sent?
                        return Err(SkipReason::UnsupportedType(format!(
                            "unknown array size: {}",
                            param.paramtype
                        )));
                    };
                    if let Some((code, ltype)) = self.push_array(
                        param.paramtype.strip_suffix(" *").expect("Invalid pointer"),
                        &param.paramname,
                        size,
                        1,
                    ) {
                        s.raw(&code);
                        sig.add_output_param(param.paramname.clone(), ltype);
                    } else {
                        return Err(SkipReason::UnsupportedType(param.paramtype.clone()));
                    }
                }
            } else {
                // char ** out_string: param holds a const char* set by Steam
                if param.paramtype == "char **" {
                    let mut out = CodeBuilder::with_indent(1);
                    out.line(&format!("lua_pushstring(L, {});", param.paramname));
                    s.raw(&out.finish());
                    sig.add_output_param(param.paramname.clone(), LType::String);
                } else {
                    let (ok, push, ltype) = self.generate_push(
                        param.paramtype.strip_suffix(" *").expect("Invalid pointer"),
                        &param.paramname,
                        1,
                    );
                    if !ok {
                        return Err(SkipReason::UnsupportedType(param.paramtype.clone()));
                    }
                    s.raw(&push);
                    sig.add_output_param(param.paramname.clone(), ltype);
                }
            }
        }

        s.line(&format!(
            "return {};",
            sig.output_params.len() + if sig.return_type.is_some() { 1 } else { 0 }
        ));
        s.indent_left();
        s.line("}");

        Ok((lua_method_name, s.finish(), sig))
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
