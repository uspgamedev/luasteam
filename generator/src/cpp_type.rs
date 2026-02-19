#[derive(Debug)]
pub enum CppType<'a> {
    Normal(&'a str),
    Array {
        ttype: &'a str,
        size: &'a str,
        is_const: bool,
    },
    Pointer {
        ttype: &'a str,
        is_const: bool,
    },
}

impl<'a> ToString for CppType<'a> {
    fn to_string(&self) -> String {
        match self {
            CppType::Normal(s) => s.to_string(),
            CppType::Array {
                ttype,
                size,
                is_const,
            } => {
                if size.parse::<usize>().is_ok() {
                    if *is_const {
                        format!("const {}[{}]", ttype, size)
                    } else {
                        format!("{}[{}]", ttype, size)
                    }
                } else {
                    if *is_const {
                        format!("const {} *", ttype)
                    } else {
                        format!("{} *", ttype)
                    }
                }
            }
            CppType::Pointer { ttype, is_const } => {
                if *is_const {
                    format!("const {}", ttype)
                } else {
                    ttype.to_string()
                }
            }
        }
    }
}

impl<'a> CppType<'a> {
    pub fn is_double_pointer(&self) -> bool {
        matches!(self, CppType::Pointer { ttype, .. } if ttype.ends_with('*') || ttype.ends_with("]"))
    }

    pub fn is_buffer(&self) -> bool {
        match self {
            CppType::Array {
                ttype: "void" | "char" | "uint8" | "unsigned char",
                ..
            } => true,
            CppType::Pointer {
                ttype: "void" | "char" | "uint8" | "unsigned char",
                ..
            } => true,
            _ => false,
        }
    }

    pub fn is_const(&self) -> bool {
        match self {
            CppType::Normal(_) => true,
            CppType::Array { is_const, .. } => *is_const,
            CppType::Pointer { is_const, .. } => *is_const,
        }
    }
}
