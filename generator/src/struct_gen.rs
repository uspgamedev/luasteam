use super::Generator;
use crate::code_builder::CodeBuilder;

use crate::doc_generator::StructDocInfo;
use crate::lua_type_info::{LType, LuaMethodSignature};
use crate::schema::{Field, Method, SkipReason, Stats, Struct};
use crate::{MANUAL_STRUCTS, MANUAL_STRUCTS_WITH_PTR, StructGenOutput};

use std::fs;
use std::path::Path;

impl Generator {
    pub(crate) fn generate_structs(&mut self, stats: &mut Stats) {
        let incomplete_structs = [
            "SteamDatagramHostedAddress",
            "SteamDatagramGameCoordinatorServerLogin",
        ];
        stats.structs_total = self.api.structs.len() + self.api.callback_structs.len();
        let mut outputs: Vec<StructGenOutput> = Vec::new();

        // Build a combined list: regular structs first, then callback_structs (converted to Struct)
        let structs = self.api.structs.clone();
        let callback_structs_as_structs: Vec<Struct> = self
            .api
            .callback_structs
            .iter()
            .map(|cb| Struct {
                name: cb.name.clone(),
                fields: cb.fields.clone(),
                methods: vec![],
            })
            .collect();
        let all_structs = structs.iter().chain(callback_structs_as_structs.iter());

        for st in all_structs {
            if incomplete_structs.contains(&st.name.as_str()) {
                stats
                    .skipped_structs
                    .push((st.name.clone(), SkipReason::Incomplete));
                continue;
            }
            if MANUAL_STRUCTS.iter().any(|(n, _)| *n == st.name.as_str()) {
                stats.structs_manual += 1;
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
                    stats.skipped_struct_methods.extend(output.skipped_methods.iter().cloned());
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

    fn generate_struct_method(
        &self,
        struct_name: &str,
        method: &Method,
    ) -> Result<(String, String, String, LuaMethodSignature), SkipReason> {
        if method.methodname == "Construct" {
            return Err(SkipReason::ManualBlocklist("internal constructor".to_string()));
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
        let mut sig = LuaMethodSignature::default();
        self.generate_method_body(method, &mut s, &mut sig, "self", 2)?;
        Ok((lua_name, c_func_name, s.finish(), sig))
    }

    fn generate_struct(&self, st: &Struct) -> Option<StructGenOutput> {
        let name = &st.name;

        // Separate accessible vs private fields
        let accessible_fields: Vec<&Field> = st.fields.iter().filter(|f| !f.private).collect();

        // Generate method C functions
        let mut methods: Vec<(String, String)> = Vec::new(); // (lua_name, c_func_name)
        let mut method_cpp = String::new();
        let mut method_signatures: Vec<(String, LuaMethodSignature)> = Vec::new();
        let mut skipped_methods: Vec<(String, SkipReason)> = Vec::new();
        for method in &st.methods {
            match self.generate_struct_method(name, method) {
                Ok((lua_name, c_func_name, cpp_code, sig)) => {
                    method_signatures.push((lua_name.clone(), sig));
                    methods.push((lua_name, c_func_name));
                    method_cpp.push_str(&cpp_code);
                }
                Err(reason) => {
                    if !matches!(reason, SkipReason::ManualBlocklist(_)) {
                        skipped_methods.push((
                            format!("{}::{}", name, method.methodname),
                            reason,
                        ));
                    }
                }
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
                readable_field_types.push((
                    field.fieldname.clone(),
                    LType::Array(Box::new(LType::String)),
                ));
                string_array_fields.push((field, count_field));
                continue;
            }

            let (push_ok, push_code, ltype) =
                self.generate_push(&field.fieldtype, &format!("self->{}", field.fieldname), 2);
            if push_ok {
                readable_field_types.push((field.fieldname.clone(), ltype));
                readable_fields.push((field, push_code));
            }

            let newindex = self.generate_check(
                &field.fieldtype,
                self.type_resolver.resolve_type(&field.fieldtype),
                false,
                &format!("self->{}", field.fieldname),
                "3",
                2,
            );
            let ctor = self.generate_check(
                &field.fieldtype,
                self.type_resolver.resolve_type(&field.fieldtype),
                false,
                &format!("ptr->{}", field.fieldname),
                "-1",
                3,
            );
            if let Some(((check_code_newindex, _), (check_code_ctor, _))) = newindex.zip(ctor) {
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
            cpp.line(&format!(
                "{} *self = ({}*)lua_touserdata(L, 1);",
                name, name
            ));
            for (field, push_code) in &readable_fields {
                cpp.line(&format!(
                    "if (strcmp(key, \"{}\") == 0) {{",
                    field.fieldname
                ));
                cpp.indent_right();
                cpp.raw(push_code);
                cpp.line("return 1;");
                cpp.indent_left();
                cpp.line("}");
            }
            for (field, count_field) in &string_array_fields {
                cpp.line(&format!(
                    "if (strcmp(key, \"{}\") == 0) {{",
                    field.fieldname
                ));
                cpp.indent_right();
                cpp.line("lua_newtable(L);");
                cpp.line(&format!(
                    "for (int32 _i = 0; _i < self->{}; _i++) {{",
                    count_field
                ));
                cpp.indent_right();
                cpp.line(&format!(
                    "lua_pushstring(L, self->{}[_i]);",
                    field.fieldname
                ));
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
            cpp.line(&format!(
                "{} *self = ({}*)lua_touserdata(L, 1);",
                name, name
            ));
            for (field, check_code, _) in &writable_fields {
                cpp.line(&format!(
                    "if (strcmp(key, \"{}\") == 0) {{",
                    field.fieldname
                ));
                cpp.indent_right();
                cpp.raw(check_code);
                cpp.line("return 0;");
                cpp.indent_left();
                cpp.line("}");
            }
            for (field, count_field) in &string_array_fields {
                cpp.line(&format!(
                    "if (strcmp(key, \"{}\") == 0) {{",
                    field.fieldname
                ));
                cpp.indent_right();
                cpp.line("luaL_checktype(L, 3, LUA_TTABLE);");
                cpp.line(&format!("if (self->{} != nullptr) {{", field.fieldname));
                cpp.indent_right();
                cpp.line(&format!(
                    "for (int32 _i = 0; _i < self->{}; _i++)",
                    count_field
                ));
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
            cpp.line(&format!(
                "{} *self = ({}*)lua_touserdata(L, 1);",
                name, name
            ));
            for (field, count_field) in &string_array_fields {
                cpp.line(&format!("if (self->{} != nullptr) {{", field.fieldname));
                cpp.indent_right();
                cpp.line(&format!(
                    "for (int32 _i = 0; _i < self->{}; _i++)",
                    count_field
                ));
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
        ns.line(&format!(
            "void push_{}(lua_State *L, {} val) {{",
            name, name
        ));
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
            skipped_methods,
        })
    }
}
