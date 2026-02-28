use std::fmt;

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
    Reference {
        ttype: &'a str,
        is_const: bool,
    },
}

impl<'a> fmt::Display for CppType<'a> {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            CppType::Normal(s) => write!(f, "{}", s),
            CppType::Array {
                ttype,
                size,
                is_const,
            } => {
                if size.parse::<usize>().is_ok() {
                    if *is_const {
                        write!(f, "const {}[{}]", ttype, size)
                    } else {
                        write!(f, "{}[{}]", ttype, size)
                    }
                } else if *is_const {
                    write!(f, "const {} *", ttype)
                } else {
                    write!(f, "{} *", ttype)
                }
            }
            CppType::Pointer { ttype, is_const } => {
                if *is_const {
                    write!(f, "const {}", ttype)
                } else {
                    write!(f, "{}", ttype)
                }
            }
            CppType::Reference { ttype, is_const } => {
                if *is_const {
                    write!(f, "const {} &", ttype)
                } else {
                    write!(f, "{} &", ttype)
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
        matches!(
            self,
            CppType::Array {
                ttype: "void" | "char" | "uint8" | "unsigned char",
                ..
            } | CppType::Pointer {
                ttype: "void" | "char" | "uint8" | "unsigned char",
                ..
            }
        )
    }
}
