use super::Generator;
use crate::COUNTER;
use crate::code_builder::CodeBuilder;
use crate::cpp_type::CppType;
use crate::doc_generator::{CallbackInterfaceDocInfo, CallbackMethodDocInfo, CallbackParamDocInfo};
use crate::lua_type_info::{LType, LuaMethodSignature};
use crate::schema::{CallbackStruct, Interface, Method, Param, SkipReason, Stats};
use std::collections::{HashMap, HashSet};
use std::fs;
use std::path::Path;

impl Generator {
    fn to_lua_callback_name(struct_name: &str) -> String {
        assert!(struct_name.ends_with("_t"));
        format!("On{}", &struct_name[..struct_name.len() - 2])
    }

    pub(crate) fn generate_callback_interfaces(&mut self) {
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
            self.added_callback_interfaces
                .insert(iface.classname.clone());
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
                cpp.line(&format!(
                    "luaL_unref(L, LUA_REGISTRYINDEX, ref_{});",
                    method.methodname
                ));
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
                cpp.line(&format!(
                    "void {}({}) override {{",
                    method.methodname, params_decl
                ));
                cpp.indent_right();
                cpp.line(&format!(
                    "lua_rawgeti(L, LUA_REGISTRYINDEX, ref_{});",
                    method.methodname
                ));
                for param in &method.params {
                    let (ok, code, _) =
                        self.generate_push(&param.paramtype, &param.paramname, cpp.indent());
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
            cpp.line(&format!(
                "auto *impl = ({}Impl*)lua_newuserdata(L, sizeof({}Impl));",
                name, name
            ));
            cpp.line(&format!("new (impl) {}Impl();", name));
            cpp.line("impl->L = L;");
            for method in &iface.methods {
                cpp.line(&format!("lua_getfield(L, 1, \"{}\");", method.methodname));
                cpp.line(&format!(
                    "impl->ref_{} = luaL_ref(L, LUA_REGISTRYINDEX);",
                    method.methodname
                ));
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

            // __gc
            cpp.line(&format!("static int {}_gc(lua_State *L) {{", name));
            cpp.indent_right();
            cpp.line(&format!(
                "auto *impl = ({}Impl*)luaL_checkudata(L, 1, \"{}\");",
                name, name
            ));
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
            cpp.line(&format!(
                "{} *check_{}(lua_State *L, int idx) {{",
                name, name
            ));
            cpp.indent_right();
            cpp.line(&format!(
                "return ({}Impl*)luaL_checkudata(L, idx, \"{}\");",
                name, name
            ));
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
            cpp.line(&format!(
                "{0}Metatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);",
                name
            ));
        }
        cpp.indent_left();
        cpp.line("}");
        cpp.preceeding_blank_line();

        cpp.line("void shutdown_callback_interfaces_auto(lua_State *L) {");
        cpp.indent_right();
        for iface in &callback_interfaces {
            let name = &iface.classname;
            cpp.line(&format!(
                "luaL_unref(L, LUA_REGISTRYINDEX, {}Metatable_ref);",
                name
            ));
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
                                let (_, _, ltype) =
                                    self.generate_push(&p.paramtype, &p.paramname, 0);
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

        let doc_content = self
            .doc_generator
            .generate_callback_interfaces_doc(&doc_infos);
        fs::write("../docs/auto/callback_interfaces.rst", doc_content)
            .expect("Unable to write callback_interfaces.rst");

        let luals_dir = Path::new("../luals");
        self.luals_generator
            .write_callback_interfaces(luals_dir, &doc_infos);
    }

    fn generate_callback_listener(
        &self,
        name_lower: &str,
        classname: &str,
        callbacks: &[CallbackStruct],
        is_gameserver_pipe: bool,
    ) -> String {
        let mut s = CodeBuilder::new();
        let class_name = format!("{}CallbackListener", name_lower);
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
        s.line(&format!("class {} {{", class_name));
        s.line("private:");
        s.indent_right();
        let is_gameserver = is_gameserver_pipe
            || classname == "ISteamGameServer"
            || classname == "ISteamGameServerStats";
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
                "{}({}, {}, {});",
                macro_name, class_name, cpp_func_name, cb.name
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
                "void {}::{}({} *data) {{",
                class_name, cpp_func_name, cb.name
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
            if self.added_structs.contains(&cb.name) {
                s.line(&format!("luasteam::push_{}(L, *data);", cb.name));
            } else {
                s.line(&format!("lua_createtable(L, 0, {});", cb.fields.len()));
                self.push_struct_fields(&mut s, cb);
            }
            s.line("lua_call(L, 1, 0);");
            s.line("lua_pop(L, 1);");
            s.indent_left();
            s.line("}");
            s.indent_left();
            s.line("}");
        }

        s.line(&format!(
            "{} *{}_listener = nullptr;",
            class_name, name_lower
        ));
        s.line("} // namespace");
        s.preceeding_blank_line();
        s.line(&format!(
            "void init_{}_auto(lua_State *L) {{ if ({}_listener != nullptr) return; {}_listener = new {}(); }}",
            name_lower, name_lower, name_lower, class_name
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

    fn push_struct_fields(&self, s: &mut CodeBuilder, cb: &CallbackStruct) {
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
            self.push_struct_fields(&mut s, cb);
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

    pub(crate) fn generate_interface(
        &mut self,
        interface: &Interface,
        method_blocklist: &HashMap<String, SkipReason>,
        stats: &mut Stats,
        luals_dir: &Path,
    ) -> Result<(String, Option<String>, usize, usize), SkipReason> {
        // Keep counters per file
        COUNTER.store(0, std::sync::atomic::Ordering::SeqCst);
        let mut cpp = CodeBuilder::new();
        let name = &interface.classname["ISteam".len()..];
        if interface.accessors.is_empty() {
            return Err(SkipReason::NoAccessors);
        }
        let accessor_name = &interface.accessors[0].name;
        let is_dual_accessor = interface.accessors.len() >= 2;

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
        cpp.raw(&self.generate_callback_listener(name, &interface.classname, callbacks, false));
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
        let mut interface_methods_manual = 0;

        stats.methods_total += interface.methods.len();
        for method in &interface.methods {
            let full_method_name = format!("{}::{}", interface.classname, method.methodname);

            if let Some(reason) = method_blocklist.get(&method.methodname_flat) {
                if reason.is_manual_impl() {
                    // Counts as implemented — manual C++ impl exists
                    stats.methods_generated += 1;
                    stats.methods_manual += 1;
                    interface_methods_generated += 1;
                    interface_methods_manual += 1;
                } else {
                    stats
                        .skipped_methods
                        .push((full_method_name, reason.clone()));
                }
                continue;
            }

            match self.generate_method(
                name,
                method,
                if is_dual_accessor {
                    None
                } else {
                    Some(accessor_name)
                },
            ) {
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
                    if is_dual_accessor {
                        // Emit two one-line wrappers that supply the accessor
                        let gs_accessor_name = &interface.accessors[1].name;
                        let base = format!("luasteam_{}_{}", name, lua_method_name);
                        cpp.line(&format!(
                            "static int {}_user(lua_State *L) {{ return {}(L, {}()); }}",
                            base, base, accessor_name
                        ));
                        cpp.line(&format!(
                            "static int {}_gs(lua_State *L) {{ return {}(L, {}()); }}",
                            base, base, gs_accessor_name
                        ));
                    }
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
            (
                interface_methods_total,
                interface_methods_generated - interface_methods_manual,
                interface_methods_manual,
            ),
        );

        self.luals_generator
            .write_interface(luals_dir, interface, &method_signatures, callbacks);

        // Generate register_..._auto function
        if is_dual_accessor {
            cpp.line(&format!(
                "void register_{}_auto(lua_State *L, bool is_gs) {{",
                name
            ));
            cpp.indent_right();
            for (_, lua_name) in &generated_methods {
                let c_name = format!("luasteam_{}_{}", name, lua_name);
                cpp.line(&format!(
                    "add_func(L, \"{}\", is_gs ? {}_gs : {}_user);",
                    lua_name, c_name, c_name
                ));
            }
        } else {
            cpp.line(&format!("void register_{}_auto(lua_State *L) {{", name));
            cpp.indent_right();
            for (_, lua_name) in &generated_methods {
                let c_name = format!("luasteam_{}_{}", name, lua_name);
                cpp.line(&format!("add_func(L, \"{}\", {});", lua_name, c_name));
            }
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
        cpp.line(&format!(
            "register_{}_auto({});",
            name,
            if is_dual_accessor {
                "L, false".to_string()
            } else {
                "L".to_string()
            }
        ));
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
        let mut gs_name_opt: Option<String> = None;
        {
            if is_dual_accessor {
                let gs_accessor_name = &interface.accessors[1].name;
                let gs_name = Self::gs_module_name(gs_accessor_name);
                gs_name_opt = Some(gs_name.clone());

                cpp.line(&format!("int {}_ref = LUA_NOREF;", gs_name));
                cpp.preceeding_blank_line();

                cpp.raw(&self.generate_callback_listener(
                    &gs_name,
                    &interface.classname,
                    callbacks,
                    true,
                ));
                cpp.preceeding_blank_line();

                cpp.line(&format!("void add_{}_auto(lua_State *L) {{", gs_name));
                cpp.indent_right();
                cpp.line(&format!(
                    "lua_createtable(L, 0, {});",
                    generated_methods.len()
                ));
                cpp.line(&format!("register_{}_auto(L, true);", name));
                cpp.line("lua_pushvalue(L, -1);");
                cpp.line(&format!(
                    "{}_ref = luaL_ref(L, LUA_REGISTRYINDEX);",
                    gs_name
                ));
                cpp.line(&format!("lua_setfield(L, -2, \"{}\");", gs_name));
                cpp.indent_left();
                cpp.line("}");
                cpp.preceeding_blank_line();
            }
        }
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

        Ok((
            name.to_owned(),
            gs_name_opt,
            generated_methods.len() + interface_enum_values_count,
            generated_methods.len(),
        ))
    }

    pub(crate) fn generate_method_body(
        &self,
        method: &Method,
        s: &mut CodeBuilder,
        sig: &mut LuaMethodSignature,
        call_on: &str,
        lua_idx_start: usize,
    ) -> Result<(), SkipReason> {
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

        let mut i = 0;
        let mut lua_idx = lua_idx_start;
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
                                s.line(&format!(
                                    "std::vector<{} *> {}_vec({});",
                                    struct_name, param.paramname, sz
                                ));
                                s.line(&format!("for (int _i = 0; _i < {}; _i++) {{", sz));
                                s.indent_right();
                                s.line(&format!("lua_rawgeti(L, {}, _i + 1);", lua_idx));
                                s.line(&format!(
                                    "{}_vec[_i] = luasteam::check_{}_ptr(L, -1);",
                                    param.paramname, struct_name
                                ));
                                s.line("lua_pop(L, 1);");
                                s.indent_left();
                                s.line("}");
                                s.line(&format!(
                                    "{} **{} = {}_vec.data();",
                                    struct_name, param.paramname, param.paramname
                                ));
                                cpp_call_params.push(param.paramname.clone());
                                sig.add_param(
                                    param.paramname.clone(),
                                    LType::Array(Box::new(LType::Userdata(struct_name))),
                                );
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

            // Route all Normal input types through the shared helper; only Pointer/Reference
            // variants need special per-context handling below.
            match resolved {
                Normal(_) => {
                    let lua_idx_s = lua_idx.to_string();
                    match {
                        self.generate_check(
                            &param.paramtype,
                            resolved,
                            true,
                            &param.paramname,
                            &lua_idx_s,
                            s.indent(),
                        )
                    } {
                        Some((code, ltype)) => {
                            s.raw(&code);
                            cpp_call_params.push(param.paramname.clone());
                            sig.add_param(param.paramname.clone(), ltype);
                            lua_idx += 1;
                        }
                        None => return Err(SkipReason::UnsupportedType(param.paramtype.clone())),
                    }
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
                    if let Some(size) = param.input_array_size_param() {
                        let lua_idx_str = lua_idx.to_string();
                        let out = CodeBuilder::with_indent(s.indent());
                        let (code, ltype) = self
                            .generate_array_check(
                                param
                                    .paramtype
                                    .strip_prefix("const ")
                                    .unwrap()
                                    .strip_suffix(" *")
                                    .unwrap(),
                                resolved.is_buffer(),
                                true,
                                &param.paramname,
                                &lua_idx_str,
                                out,
                                size,
                                (method.methodname_flat
                                    == "SteamAPI_ISteamUser_RequestEncryptedAppTicket"
                                    && param.paramname == "pDataToInclude")
                                    || (method.methodname_flat
                                        == "SteamAPI_ISteamScreenshots_WriteScreenshot"
                                        && param.paramname == "pubRGB")
                                    || (method.methodname_flat
                                        == "SteamAPI_ISteamNetworking_SendDataOnSocket"
                                        && param.paramname == "pubData"),
                            )
                            .ok_or_else(|| {
                                SkipReason::UnsupportedType(format!(
                                    "size param {} not found",
                                    size
                                ))
                            })?;

                        sig.add_param(param.paramname.clone(), ltype);
                        if !size.is_empty() && !size_params_to_ignore.contains(size) {
                            let p_idx = method
                                .params
                                .iter()
                                .position(|p| p.paramname == size)
                                .expect("Size param not found");
                            let p = &method.params[p_idx];
                            if p_idx > i {
                                size_params_to_ignore.insert(size.to_string());
                                lua_idx += 1;
                                s.line(&format!(
                                    "{} {} = luaL_checkint(L, {});",
                                    p.paramtype
                                        .strip_suffix(" *")
                                        .unwrap_or(p.paramtype.as_str()),
                                    size,
                                    lua_idx
                                ));
                                sig.add_param(size.to_string(), LType::Integer);
                                lua_idx += 1;
                            } else {
                                assert!(
                                    !p.paramtype.ends_with(" *"),
                                    "Size param {} should not be a pointer",
                                    size
                                );
                            }
                        }

                        s.raw(&code);
                        // Buffer types (void*, char*, uint8*, etc.) are now declared as
                        // a typed const pointer directly — no .data() needed.
                        let is_buf = ["void", "char", "uint8", "unsigned char"].contains(&ttype);
                        if is_buf {
                            cpp_call_params.push(param.paramname.clone());
                        } else {
                            cpp_call_params.push(format!("{}.data()", param.paramname));
                        }
                    } else if resolved.is_buffer() {
                        let lua_idx_str = lua_idx.to_string();
                        let (code, ltype) = self
                            .generate_check(
                                &param.paramtype,
                                resolved,
                                true,
                                &param.paramname,
                                &lua_idx_str,
                                s.indent(),
                            )
                            .ok_or_else(|| SkipReason::UnsupportedType(param.paramtype.clone()))?;
                        s.raw(&code);
                        cpp_call_params.push(param.paramname.clone());
                        sig.add_param(param.paramname.clone(), ltype);
                        lua_idx += 1;
                    } else {
                        // Non-array const pointer — treat as optional input (nil → nullptr).
                        // If the type has a _ptr check function, use it to avoid a copy.
                        if self.added_structs_with_ptr.contains(ttype) {
                            s.line(&format!(
                                "const {t} *{n} = lua_isnil(L, {idx}) ? nullptr : luasteam::check_{t}_ptr(L, {idx});",
                                t = ttype, n = param.paramname, idx = lua_idx
                            ));
                            cpp_call_params.push(param.paramname.clone());
                            sig.add_param(
                                param.paramname.clone(),
                                LType::Userdata(ttype.to_string()),
                            );
                            lua_idx += 1;
                        } else if self.added_structs.contains(ttype) {
                            s.line(&format!("{t} {n}_val;", t = ttype, n = param.paramname));
                            s.line(&format!(
                                "if (!lua_isnil(L, {idx})) {n}_val = luasteam::check_{t}(L, {idx});",
                                n = param.paramname, idx = lua_idx, t = ttype
                            ));
                            s.line(&format!(
                                "const {t} *{n} = lua_isnil(L, {idx}) ? nullptr : &{n}_val;",
                                t = ttype,
                                n = param.paramname,
                                idx = lua_idx
                            ));
                            cpp_call_params.push(param.paramname.clone());
                            sig.add_param(
                                param.paramname.clone(),
                                LType::Userdata(ttype.to_string()),
                            );
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
                            t = ttype,
                            n = param.paramname,
                            idx = lua_idx
                        ));
                        cpp_call_params.push(param.paramname.clone());
                        sig.add_param(param.paramname.clone(), LType::Userdata(ttype.to_string()));
                        lua_idx += 1;
                    } else if self.added_structs.contains(ttype) {
                        s.line(&format!(
                            "{t} {n} = luasteam::check_{t}(L, {idx});",
                            t = ttype,
                            n = param.paramname,
                            idx = lua_idx
                        ));
                        cpp_call_params.push(param.paramname.clone());
                        sig.add_param(param.paramname.clone(), LType::Userdata(ttype.to_string()));
                        lua_idx += 1;
                    } else {
                        return Err(SkipReason::UnsupportedType(param.paramtype.clone()));
                    }
                }
                CppType::Reference {
                    ttype: _,
                    is_const: false,
                } => {
                    return Err(SkipReason::UnsupportedType(param.paramtype.clone()));
                }
            }
            i += 1;
        }
        assert!(
            size_params_to_ignore.is_empty(),
            "Some size parameters were not used: {:?}",
            size_params_to_ignore
        );

        let call = format!(
            "{}->{}({})",
            call_on,
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
            let resolved_ret = self.type_resolver.resolve_type(&method.returntype);
            if let CppType::Pointer { ttype, is_const: true } = resolved_ret
                && self.added_structs.contains(ttype)
            {
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
                        "SteamAPI_ISteamInput_GetConnectedControllers",
                        "SteamAPI_ISteamInput_GetActiveActionSetLayers",
                        "SteamAPI_ISteamInput_GetAnalogActionOrigins",
                        "SteamAPI_ISteamInput_GetDigitalActionOrigins",
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

        Ok(())
    }

    fn generate_method(
        &self,
        interface: &str,
        method: &Method,
        direct_accessor: Option<&str>,
    ) -> Result<(String, String, LuaMethodSignature), SkipReason> {
        // Tricky ones to support:
        // GetItemDefinitionProperty - has a pointer that must have a value and returns another
        // GetItemsWithPrices - The JSON looks different from the API
        // AddPromoItems - Input arrays with counts
        // Most PublishedFileId_t * should be const, also pubBody in HTTP
        // GetImageRGBA - uint8* should be a byte buffer, probably
        let mut s = CodeBuilder::new();

        let lua_method_name = Self::lua_method_public_name(method);
        let c_method_name = format!("luasteam_{}_{}", interface, lua_method_name);
        if let Some(accessor) = direct_accessor {
            s.line(&format!("static int {}(lua_State *L) {{", c_method_name));
            s.indent_right();
            s.line(&format!("auto *iface = {}();", accessor));
        } else {
            // Dual-accessor: base function takes iface directly; wrappers added below
            s.line(&format!(
                "static int {}(lua_State *L, ISteam{} *iface) {{",
                c_method_name, interface
            ));
            s.indent_right();
        }

        let mut sig = LuaMethodSignature::default();
        self.generate_method_body(method, &mut s, &mut sig, "iface", 1)?;
        Ok((lua_method_name, s.finish(), sig))
    }

    fn gs_module_name(accessor_name: &str) -> String {
        let s = accessor_name.strip_prefix("Steam").unwrap_or(accessor_name);
        let s = s.strip_suffix("_SteamAPI").unwrap_or(s);
        s.to_string()
    }
}
