use std::collections::{BTreeMap, BTreeSet};
use std::fs;
use std::path::{Path, PathBuf};
use std::process::Command;

struct AutoDirRestoreGuard {
    root: PathBuf,
    baseline: BTreeMap<PathBuf, String>,
}

impl AutoDirRestoreGuard {
    fn new(root: PathBuf, baseline: BTreeMap<PathBuf, String>) -> Self {
        Self { root, baseline }
    }
}

impl Drop for AutoDirRestoreGuard {
    fn drop(&mut self) {
        let current = collect_files(&self.root).unwrap_or_default();
        let baseline_paths: BTreeSet<PathBuf> = self.baseline.keys().cloned().collect();
        let current_paths: BTreeSet<PathBuf> = current.keys().cloned().collect();

        for removed in baseline_paths.difference(&current_paths) {
            if let Some(content) = self.baseline.get(removed) {
                if let Some(parent) = removed.parent() {
                    let _ = fs::create_dir_all(parent);
                }
                let _ = fs::write(removed, content);
            }
        }

        for extra in current_paths.difference(&baseline_paths) {
            let _ = fs::remove_file(extra);
        }

        for (path, content) in &self.baseline {
            let _ = fs::write(path, content);
        }
    }
}

fn collect_files(root: &Path) -> Result<BTreeMap<PathBuf, String>, String> {
    let mut map = BTreeMap::new();
    collect_files_recursive(root, &mut map)?;
    Ok(map)
}

fn collect_files_recursive(dir: &Path, map: &mut BTreeMap<PathBuf, String>) -> Result<(), String> {
    let entries =
        fs::read_dir(dir).map_err(|e| format!("Failed to read {}: {e}", dir.display()))?;
    for entry in entries {
        let entry =
            entry.map_err(|e| format!("Failed to read dir entry in {}: {e}", dir.display()))?;
        let path = entry.path();
        let file_type = entry
            .file_type()
            .map_err(|e| format!("Failed to read file type for {}: {e}", path.display()))?;

        if file_type.is_dir() {
            collect_files_recursive(&path, map)?;
            continue;
        }

        if file_type.is_file() {
            let content = fs::read_to_string(&path)
                .map_err(|e| format!("Failed to read file {}: {e}", path.display()))?;
            map.insert(path, content);
        }
    }
    Ok(())
}

fn canonicalize_auto_hpp(content: &str) -> String {
    let mut sortable = Vec::new();
    let mut kept = Vec::new();

    for line in content.lines() {
        let trimmed = line.trim();
        if trimmed.contains(" check_")
            && trimmed.starts_with("void ") == false
            && trimmed.ends_with("(lua_State *L, int index);")
        {
            sortable.push(trimmed.to_string());
        } else if trimmed.contains(" push_") && trimmed.ends_with(" val);") {
            sortable.push(trimmed.to_string());
        } else {
            kept.push(line.to_string());
        }
    }

    sortable.sort();

    let mut out = String::new();
    for line in kept {
        out.push_str(&line);
        out.push('\n');
    }
    out.push_str("// __SORTED_STRUCT_DECLS_BEGIN__\n");
    for line in sortable {
        out.push_str(&line);
        out.push('\n');
    }
    out.push_str("// __SORTED_STRUCT_DECLS_END__\n");
    out
}

fn normalize_file(path: &Path, content: &str) -> String {
    let canonical = if path
        .file_name()
        .and_then(|f| f.to_str())
        .is_some_and(|name| name == "auto.hpp")
    {
        canonicalize_auto_hpp(content)
    } else {
        content.to_string()
    };
    canonical.chars().filter(|ch| !ch.is_whitespace()).collect()
}

fn has_same_line_rawseti(content: &str) -> bool {
    content
        .lines()
        .any(|line| line.contains("lua_rawseti(L, -2, i+1);") && line.contains(';'))
        && content.lines().any(|line| {
            line.contains("; lua_rawseti(L, -2, i+1);")
                || line.contains(";\tlua_rawseti(L, -2, i+1);")
        })
}

#[test]
fn generated_auto_files_are_whitespace_stable() {
    let generator_root = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    let auto_root = generator_root
        .parent()
        .expect("generator has no parent")
        .join("src")
        .join("auto");

    let baseline = collect_files(&auto_root)
        .unwrap_or_else(|e| panic!("Unable to snapshot baseline src/auto files: {e}"));
    let _restore_guard = AutoDirRestoreGuard::new(auto_root.clone(), baseline.clone());

    let exe = env!("CARGO_BIN_EXE_generator");
    let output = Command::new(exe)
        .current_dir(&generator_root)
        .output()
        .unwrap_or_else(|e| panic!("Failed to execute generator binary: {e}"));

    if !output.status.success() {
        let stdout = String::from_utf8_lossy(&output.stdout);
        let stderr = String::from_utf8_lossy(&output.stderr);
        panic!(
            "Generator failed with status {}\nstdout:\n{}\nstderr:\n{}",
            output.status, stdout, stderr
        );
    }

    let after = collect_files(&auto_root)
        .unwrap_or_else(|e| panic!("Unable to snapshot generated src/auto files: {e}"));

    let baseline_paths: BTreeSet<PathBuf> = baseline.keys().cloned().collect();
    let after_paths: BTreeSet<PathBuf> = after.keys().cloned().collect();

    let mut problems = Vec::new();

    for missing in baseline_paths.difference(&after_paths) {
        problems.push(format!("Missing generated file: {}", missing.display()));
    }
    for extra in after_paths.difference(&baseline_paths) {
        problems.push(format!("Unexpected generated file: {}", extra.display()));
    }

    for path in baseline_paths.intersection(&after_paths) {
        if path
            .extension()
            .and_then(|e| e.to_str())
            .is_some_and(|e| e == "cpp")
            && has_same_line_rawseti(
                after
                    .get(path)
                    .expect("Path exists in after path set but not map"),
            )
        {
            let rel = path
                .strip_prefix(generator_root.parent().expect("generator has no parent"))
                .unwrap_or(path);
            problems.push(format!(
                "Formatting issue in {}: lua_rawseti appears on the same line as a previous statement",
                rel.display()
            ));
        }

        let before_norm = normalize_file(
            path,
            baseline
                .get(path)
                .expect("Path exists in baseline path set but not map"),
        );
        let after_norm = normalize_file(
            path,
            after
                .get(path)
                .expect("Path exists in after path set but not map"),
        );

        if before_norm != after_norm {
            let rel = path
                .strip_prefix(generator_root.parent().expect("generator has no parent"))
                .unwrap_or(path);
            problems.push(format!("Behavioral difference in {}", rel.display()));
        }
    }

    assert!(
        problems.is_empty(),
        "Generated files changed beyond whitespace:\n{}",
        problems.join("\n")
    );
}
