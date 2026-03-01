pub struct CodeBuilder {
    out: String,
    indent_level: usize,
}

const BASE_INDENT: &str = "\t";

impl CodeBuilder {
    pub fn new() -> Self {
        Self {
            out: String::new(),
            indent_level: 0,
        }
    }

    pub fn with_indent(indent: usize) -> Self {
        Self {
            out: String::new(),
            indent_level: indent,
        }
    }

    pub fn indent(&self) -> usize {
        self.indent_level
    }

    pub fn indent_right(&mut self) {
        self.indent_level += 1;
    }

    pub fn indent_left(&mut self) {
        if self.indent_level > 0 {
            self.indent_level -= 1;
        }
    }

    pub fn line(&mut self, line: &str) {
        self.out
            .push_str(BASE_INDENT.repeat(self.indent_level).as_str());
        self.out.push_str(line);
        self.out.push('\n');
    }

    pub fn preceeding_blank_line(&mut self) {
        if !self.out.is_empty() && !self.out.ends_with("\n\n") {
            self.out.push('\n');
        }
    }

    pub fn raw(&mut self, block: &str) {
        self.out.push_str(block);
    }

    pub fn finish(self) -> String {
        self.out
    }

    // Lua registry metatable helpers
    pub fn metatable_ref_decl(&mut self, name: &str) {
        self.line(&format!("static int {}Metatable_ref = LUA_NOREF;", name));
    }

    pub fn set_metatable_from_ref(&mut self, name: &str) {
        self.line(&format!(
            "lua_rawgeti(L, LUA_REGISTRYINDEX, {}Metatable_ref);",
            name
        ));
        self.line("lua_setmetatable(L, -2);");
    }

    pub fn store_metatable_ref(&mut self, name: &str) {
        self.line(&format!(
            "{}Metatable_ref = luaL_ref(L, LUA_REGISTRYINDEX);",
            name
        ));
    }

    pub fn release_metatable_ref(&mut self, name: &str) {
        self.line(&format!(
            "luaL_unref(L, LUA_REGISTRYINDEX, {}Metatable_ref);",
            name
        ));
        self.line(&format!("{}Metatable_ref = LUA_NOREF;", name));
    }
}
