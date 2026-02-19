use serde::{Deserialize, Serialize};
use std::collections::{BTreeSet, HashMap, HashSet};
use std::fs;
use std::path::Path;

static COUNTER: std::sync::atomic::AtomicUsize = std::sync::atomic::AtomicUsize::new(0);
const BASE_INDENT: &str = "\t";

#[derive(Debug, Default)]
struct Stats {
    interfaces_total: usize,
    interfaces_generated: usize,
    methods_total: usize,
    methods_generated: usize,
    enum_values_total: usize,
    enum_values_generated: usize,
    consts_total: usize,
    const_generated: usize,
    structs_total: usize,
    structs_generated: usize,
    unsupported_types: BTreeSet<String>,
}

impl Stats {
    fn print_summary(&self) {
        println!("--- Generation Summary ---");
        println!(
            "Interfaces:  {} total, {} generated, {} skipped",
            self.interfaces_total,
            self.interfaces_generated,
            self.interfaces_total - self.interfaces_generated
        );
        println!(
            "Methods:     {} total, {} generated, {} skipped",
            self.methods_total,
            self.methods_generated,
            self.methods_total - self.methods_generated
        );
        println!(
            "Enum Values: {} total, {} generated, {} skipped",
            self.enum_values_total,
            self.enum_values_generated,
            self.enum_values_total - self.enum_values_generated
        );
        println!(
            "Consts:      {} total, {} generated, {} skipped",
            self.consts_total,
            self.const_generated,
            self.consts_total - self.const_generated
        );
        println!(
            "Structs:     {} total, {} generated, {} skipped",
            self.structs_total,
            self.structs_generated,
            self.structs_total - self.structs_generated
        );

        println!("--------------------------");
    }
}

#[derive(Debug, Deserialize, Serialize)]
struct SteamApi {
    callback_structs: Vec<CallbackStruct>,
    enums: Vec<Enum>,
    interfaces: Vec<Interface>,
    typedefs: Vec<Typedef>,
    // TODO: support structs
    structs: Vec<Struct>,
    consts: Vec<Const>,
}

impl SteamApi {
    fn interface_mut(&mut self, name: &str) -> &mut Interface {
        self.interfaces
            .iter_mut()
            .find(|i| i.classname == name)
            .expect("Missing interface")
    }
    fn struct_mut(&mut self, name: &str) -> &mut Struct {
        self.structs
            .iter_mut()
            .find(|s| s.name == name)
            .expect("Missing struct")
    }
}

impl SteamApi {
    /// Remove deprecated methods and parameters
    fn fix_deprecated(&mut self) {
        self.interfaces.iter_mut().for_each(|i| {
            i.methods.retain_mut(|m| {
                // remove deprecated parameters
                m.params.retain(|p| !p.paramname.ends_with("_Deprecated"));
                // remove deprecated methods
                !m.methodname.ends_with("_DEPRECATED")
            })
        });
    }
    /// It should be const void * because it is input, not output.
    fn fix_missing_const(&mut self) {
        let data = [
            (
                "ISteamUser",
                vec![("RequestEncryptedAppTicket", vec!["pDataToInclude"])],
            ),
            (
                "ISteamParties",
                vec![("CreateBeacon", vec!["pBeaconLocation"])],
            ),
            (
                "ISteamScreenshots",
                vec![("WriteScreenshot", vec!["pubRGB"])],
            ),
            (
                "ISteamUserStats",
                vec![("DownloadLeaderboardEntriesForUsers", vec!["prgUsers"])],
            ),
        ];

        for (i_name, methods) in data {
            let i = self
                .interfaces
                .iter_mut()
                .find(|i| i.classname == i_name)
                .expect("Missing interface");
            for (m_name, p_names) in methods {
                let m = i
                    .methods
                    .iter_mut()
                    .find(|m| m.methodname == m_name)
                    .expect("Missing method");
                for p_name in p_names {
                    let p = m
                        .params
                        .iter_mut()
                        .find(|p| p.paramname == p_name)
                        .expect("missing param");
                    assert!(p.paramtype.ends_with(" *"));
                    assert!(!p.paramtype.starts_with("const "));
                    p.paramtype = format!("const {}", p.paramtype);
                }
            }
        }
    }
    /// Missing constants
    fn fix_missing_constants(&mut self) {
        let data = [
            ("STEAM_INPUT_HANDLE_ALL_CONTROLLERS", "uint64", "UINT64_MAX"),
            ("STEAM_INPUT_MAX_ANALOG_ACTIONS", "int", "16"),
            ("STEAM_INPUT_MAX_ANALOG_ACTION_DATA", "float", "1.0f"),
            ("STEAM_INPUT_MAX_COUNT", "int", "16"),
            ("STEAM_INPUT_MAX_ACTIVE_LAYERS", "int", "16"), // being replaced by the one above, but still present
            ("STEAM_INPUT_MAX_DIGITAL_ACTIONS", "int", "128"),
            ("STEAM_INPUT_MAX_ORIGINS", "int", "8"),
            ("STEAM_INPUT_MIN_ANALOG_ACTION_DATA", "float", "-8"),
        ];
        let all_names = self
            .consts
            .iter()
            .map(|c| c.constname.to_string())
            .collect::<HashSet<_>>();
        for (const_name, const_type, const_val) in data {
            assert!(
                !all_names.contains(const_name),
                "Constant {} already exists",
                const_name
            );
            self.consts.push(Const {
                constname: const_name.to_string(),
                consttype: const_type.to_string(),
                constval: const_val.to_string(),
            });
        }
        let mut changes = 0;
        // Furthermore, some constants in the data use STEAM_CONTROLLER_* instead of STEAM_INPUT_*
        for i in &mut self.interfaces {
            for m in &mut i.methods {
                for p in &mut m.params {
                    if let Some(oac) = p.out_array_count.as_mut() {
                        if oac.starts_with("STEAM_CONTROLLER_") {
                            *oac = oac.replacen("STEAM_CONTROLLER_", "STEAM_INPUT_", 1);
                            changes += 1;
                        }
                    }
                }
            }
        }
        assert!(changes == 4);
    }
    /// Methods that do not use out_string_count or out_array_count when they should
    fn fix_missing_array_count(&mut self) {
        let to_mark_counters = [
            (
                "ISteamUser",
                vec![("GetUserDataFolder", "pchBuffer", "cubBuffer")],
            ),
            (
                "ISteamRemotePlay",
                vec![("GetInput", "pInput", "unMaxEvents")],
            ),
            (
                "ISteamApps",
                vec![
                    ("GetCurrentBetaName", "pchName", "cchNameBufferSize"),
                    ("GetLaunchCommandLine", "pszCommandLine", "cubCommandLine"),
                    ("GetAppInstallDir", "pchFolder", "cchFolderBufferSize"),
                    ("GetInstalledDepots", "pvecDepots", "cMaxDepots"),
                    ("BGetDLCDataByIndex", "pchName", "cchNameBufferSize"),
                    ("GetBetaInfo", "pchBetaName", "cchBetaName"),
                    ("GetBetaInfo", "pchDescription", "cchDescription"),
                ],
            ),
            (
                "ISteamUserStats",
                vec![
                    (
                        "GetNextMostAchievedAchievementInfo",
                        "pchName",
                        "unNameBufLen",
                    ),
                    ("GetMostAchievedAchievementInfo", "pchName", "unNameBufLen"),
                    ("GetDownloadedLeaderboardEntry", "pDetails", "cDetailsMax"),
                    (
                        "UploadLeaderboardScore",
                        "pScoreDetails",
                        "cScoreDetailsCount",
                    ),
                ],
            ),
            (
                "ISteamParties",
                vec![(
                    "GetAvailableBeaconLocations",
                    "pLocationList",
                    "uMaxNumLocations",
                )],
            ),
            (
                "ISteamMatchmaking",
                vec![
                    ("GetLobbyDataByIndex", "pchKey", "cchKeyBufferSize"),
                    ("GetLobbyDataByIndex", "pchValue", "cchValueBufferSize"),
                    ("GetLobbyChatEntry", "pvData", "cubData"),
                ],
            ),
            (
                "ISteamUtils",
                vec![
                    (
                        "FilterText",
                        "pchOutFilteredText",
                        "nByteSizeOutFilteredText",
                    ),
                    ("GetEnteredGamepadTextInput", "pchText", "cchText"),
                    ("GetImageRGBA", "pubDest", "nDestBufferSize"),
                    ("GetAPICallResult", "pCallback", "cubCallback"),
                ],
            ),
            (
                "ISteamRemoteStorage",
                vec![
                    ("FileRead", "pvData", "cubDataToRead"),
                    ("FileReadAsyncComplete", "pvBuffer", "cubToRead"),
                    ("UGCRead", "pvData", "cubDataToRead"),
                ],
            ),
            (
                "ISteamScreenshots",
                vec![("WriteScreenshot", "pubRGB", "cubRGB")],
            ),
            (
                "ISteamFriends",
                vec![
                    ("GetClanChatMessage", "prgchText", "cchTextMax"),
                    ("GetFriendMessage", "pvData", "cubData"),
                ],
            ),
            (
                "ISteamGameServer",
                vec![("GetNextOutgoingPacket", "pOut", "cbMaxOut")],
            ),
            (
                "ISteamVideo",
                vec![("GetOPFStringForApp", "pchBuffer", "pnBufferSize")],
            ),
        ];
        for (i_name, data) in to_mark_counters {
            let i = self
                .interfaces
                .iter_mut()
                .find(|i| i.classname == i_name)
                .expect("Interface not found");
            for (m_name, p_name, count_name) in data {
                let m = i
                    .methods
                    .iter_mut()
                    .find(|m| m.methodname == m_name)
                    .expect("Method not found");
                let p = m
                    .params
                    .iter_mut()
                    .find(|p| p.paramname == p_name)
                    .expect("Parameter not found");
                assert!(p.paramtype.ends_with(" *"));
                assert!(p.out_string_count.is_none());
                assert!(p.out_array_count.is_none());
                let field = if p.paramtype == "char *" {
                    &mut p.out_string_count
                } else {
                    &mut p.out_array_count
                };
                *field = Some(count_name.to_string());
                assert!(
                    m.params.iter().any(|p| p.paramname == count_name),
                    "Count parameter not found"
                );
            }
        }
        let p = self
            .interface_mut("ISteamUser")
            .method_mut("GetVoice")
            .param_mut("pDestBuffer");
        assert!(
            p.out_array_count.is_none()
                && p.out_string_count.is_none()
                && p.out_array_call.is_none()
                && p.array_count.is_none()
        );
        p.out_array_count = Some("nBytesWritten".to_owned());
        p.array_count = Some("cbDestBufferSize".to_owned());
    }

    /// Fix some known issues in the JSON data
    fn apply_fixes(&mut self) {
        self.fix_deprecated();
        self.fix_missing_constants();
        self.fix_missing_const();
        self.fix_missing_array_count();
        // Inside a named union
        self.struct_mut("SteamNetworkingConfigValue_t")
            .field_mut("m_int64")
            .fieldname = "m_val.m_int64".to_string();
    }
}

#[derive(Debug, Deserialize, Serialize)]
struct Const {
    constname: String,
    consttype: String,
    constval: String,
}

#[derive(Debug, Deserialize, Serialize, Clone)]
struct CallbackStruct {
    #[serde(rename = "struct")]
    name: String,
    callback_id: i32,
    fields: Vec<Field>,
}

#[derive(Debug, Deserialize, Serialize, Clone)]
struct Field {
    fieldname: String,
    fieldtype: String,
    #[serde(default)]
    private: bool,
}

#[derive(Debug, Deserialize, Serialize)]
struct Struct {
    #[serde(rename = "struct")]
    name: String,
    fields: Vec<Field>,
    #[serde(default)]
    methods: Vec<Method>,
}

impl Struct {
    fn field_mut(&mut self, name: &str) -> &mut Field {
        self.fields
            .iter_mut()
            .find(|f| f.fieldname == name)
            .expect("Missing field")
    }
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
    #[serde(default)]
    accessors: Vec<Accessor>,
    #[serde(default)]
    enums: Vec<InterfaceEnum>,
}

#[derive(Debug, Deserialize, Serialize)]
struct InterfaceEnum {
    enumname: String,
    #[serde(default)]
    fqname: String,
    values: Vec<EnumValue>,
}

impl Interface {
    fn method_mut(&mut self, name: &str) -> &mut Method {
        self.methods
            .iter_mut()
            .find(|m| m.methodname == name)
            .expect("Missing method")
    }
}

#[derive(Debug, Deserialize, Serialize)]
struct Accessor {
    kind: String,
    name: String,
    name_flat: String,
}

#[derive(Debug, Deserialize, Serialize)]
struct Method {
    methodname: String,
    methodname_flat: String,
    params: Vec<Param>,
    returntype: String,
}

impl Method {
    fn param(&self, name: &str) -> &Param {
        self.params
            .iter()
            .find(|p| p.paramname == name)
            .expect("Missing param")
    }
    fn param_mut(&mut self, name: &str) -> &mut Param {
        self.params
            .iter_mut()
            .find(|p| p.paramname == name)
            .expect("Missing param")
    }
}

#[derive(Debug, Deserialize, Serialize)]
struct Param {
    paramname: String,
    paramtype: String,
    /// Only present for pointer params that represent arrays, indicates the name of the parameter that contains the size of the array.
    out_string_count: Option<String>,
    /// If present, indicates that this pointer param is an output array and the name of the parameter that contains the size of the array (might be the next parameter, or a constant)
    out_array_count: Option<String>,
    array_count: Option<String>,
    // Like out_array_count, but has the name of the function to call to get the count
    out_array_call: Option<String>,
    desc: Option<String>,
}

impl Param {
    /// What parameter has the size should (maybe) output the size. We are assuming they are never different.
    fn array_size_param(&self) -> Option<&str> {
        match (
            self.out_string_count.as_deref(),
            self.out_array_count.as_deref(),
            self.array_count.as_deref(),
            self.out_array_call.as_deref(),
        ) {
            (None, None, None, None) => None,
            (Some(s), None, None, None) => Some(s),
            (None, Some(s), None, None) => Some(s),
            (None, None, Some(s), None) => Some(s),
            (None, None, None, Some(oac)) => Some(oac.split_once(',').unwrap().0),
            _ => unreachable!(),
        }
    }
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
    interface_callbacks: HashMap<String, Vec<CallbackStruct>>,
    added_structs: HashSet<String>,
}

#[derive(Debug)]
enum CppType<'a> {
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
    fn is_double_pointer(&self) -> bool {
        matches!(self, CppType::Pointer { ttype, .. } if ttype.ends_with('*') || ttype.ends_with("]"))
    }
    fn is_buffer(&self) -> bool {
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
    fn is_const(&self) -> bool {
        match self {
            CppType::Normal(_) => true,
            CppType::Array { is_const, .. } => *is_const,
            CppType::Pointer { is_const, .. } => *is_const,
        }
    }
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

        let mut method_blocklist: HashSet<String> = HashSet::new();
        // These are added because they have many overloads
        // TODO: Add a custom one for these
        method_blocklist.insert("SteamAPI_ISteamInventory_SetPropertyString".to_string());
        method_blocklist.insert("SteamAPI_ISteamInventory_SetPropertyBool".to_string());
        method_blocklist.insert("SteamAPI_ISteamInventory_SetPropertyInt64".to_string());
        method_blocklist.insert("SteamAPI_ISteamInventory_SetPropertyFloat".to_string());
        method_blocklist.insert("SteamAPI_ISteamUserStats_GetGlobalStatInt64".to_string());
        method_blocklist.insert("SteamAPI_ISteamUserStats_GetGlobalStatDouble".to_string());
        method_blocklist.insert("SteamAPI_ISteamUserStats_GetGlobalStatHistoryInt64".to_string());
        method_blocklist.insert("SteamAPI_ISteamUserStats_GetGlobalStatHistoryDouble".to_string());
        method_blocklist.insert("SteamAPI_ISteamUserStats_SetStatInt32".to_string());
        method_blocklist.insert("SteamAPI_ISteamUserStats_SetStatFloat".to_string());
        method_blocklist.insert("SteamAPI_ISteamUserStats_GetStatInt32".to_string());
        method_blocklist.insert("SteamAPI_ISteamUserStats_GetStatFloat".to_string());
        method_blocklist.insert("SteamAPI_ISteamUserStats_SetUserStatInt32".to_string());
        method_blocklist.insert("SteamAPI_ISteamUserStats_SetUserStatFloat".to_string());
        method_blocklist.insert("SteamAPI_ISteamUserStats_GetUserStatInt32".to_string());
        method_blocklist.insert("SteamAPI_ISteamUserStats_GetUserStatFloat".to_string());
        method_blocklist.insert("SteamAPI_ISteamGameServerStats_SetUserStatInt32".to_string());
        method_blocklist.insert("SteamAPI_ISteamGameServerStats_SetUserStatFloat".to_string());
        method_blocklist.insert("SteamAPI_ISteamGameServerStats_GetUserStatInt32".to_string());
        method_blocklist.insert("SteamAPI_ISteamGameServerStats_GetUserStatFloat".to_string());
        method_blocklist
            .insert("SteamAPI_ISteamUserStats_GetAchievementProgressLimitsInt32".to_string());
        method_blocklist
            .insert("SteamAPI_ISteamUserStats_GetAchievementProgressLimitsFloat".to_string());
        // Cursor method is not used
        method_blocklist.insert("SteamAPI_ISteamUGC_CreateQueryAllUGCRequestCursor".to_string());
        // Unused method, not even in API Reference
        method_blocklist.insert("SteamAPI_ISteamUGC_GetQueryFirstUGCKeyValueTag".to_string());
        // Very weird, out_array_count seems to be all wrong
        method_blocklist.insert("SteamAPI_ISteamInventory_GetItemsWithPrices".to_string());
        // Weird API and no explanation or reference
        method_blocklist.insert("SteamAPI_ISteamRemoteStorage_GetUGCDetails".to_string());
        // Needs support for out_array_count and array_count at the same time, which is not currently supported
        method_blocklist.insert("SteamAPI_ISteamUser_GetVoice".to_string());
        method_blocklist.insert("SteamAPI_ISteamUser_DecompressVoice".to_string());
        method_blocklist.insert("SteamAPI_ISteamUser_GetAuthSessionTicket".to_string());
        method_blocklist.insert("SteamAPI_ISteamGameServer_GetAuthSessionTicket".to_string());
        method_blocklist.insert("SteamAPI_ISteamUser_GetEncryptedAppTicket".to_string());
        // Has function pointers, can't be implemented automatically
        method_blocklist.insert("SteamAPI_ISteamUtils_SetWarningMessageHook".to_string());
        // Uses a pointer as input when it could just use an object
        method_blocklist.insert("SteamAPI_ISteamParties_CreateBeacon".to_string());

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
        let mut cpp = String::new();
        cpp.push_str("#include \"auto.hpp\"\n\n");
        cpp.push_str("namespace luasteam {\n\n");

        for st in &self.api.structs {
            if incomplete_structs.contains(&st.name.as_str()) {
                println!("Skipping struct {} because it is incomplete", st.name);
                continue;
            }
            if let Some(code) = self.generate_struct(st) {
                cpp.push_str(&code);
                // We are assuming a struct does not depend on one not yet declared
                self.added_structs.insert(st.name.clone());
                stats.structs_generated += 1;
            }
        }

        cpp.push_str("} // namespace luasteam\n");
        fs::write("../src/auto/structs.cpp", cpp).expect("Unable to write structs.cpp");
    }

    fn generate_struct(&self, st: &Struct) -> Option<String> {
        let mut cpp = String::new();
        // Generate check function
        cpp.push_str(&format!(
            "{} check_{}(lua_State *L, int index) {{\n",
            st.name, st.name
        ));
        cpp.push_str("    luaL_checktype(L, index, LUA_TTABLE);\n");
        cpp.push_str(&format!("    {} res;\n", st.name));
        for field in &st.fields {
            if field.private {
                println!(
                    "Skipping struct {} because field {} is private",
                    st.name, field.fieldname
                );
                return None;
            }
            cpp.push_str(&format!(
                "    lua_getfield(L, index, \"{}\");\n",
                field.fieldname
            ));
            let (ok, check) = self.generate_check(
                &field.fieldtype,
                self.resolve_type(&field.fieldtype),
                false,
                &format!("res.{}", field.fieldname),
                "-1",
                "    ",
            );
            if ok {
                cpp.push_str(&check);
            } else {
                cpp.push_str(&format!(
                    "    // Unsupported field type: {}\n",
                    field.fieldtype
                ));
                println!(
                    "Unsupported field type in check for struct {}: {}",
                    st.name, field.fieldtype
                );
                return None;
            }
            cpp.push_str("    lua_pop(L, 1);\n");
        }
        cpp.push_str("    return res;\n");
        cpp.push_str("}\n\n");

        // Generate push function
        cpp.push_str(&format!(
            "void push_{}(lua_State *L, {} val) {{\n",
            st.name, st.name
        ));
        cpp.push_str(&format!(
            "    lua_createtable(L, 0, {});\n",
            st.fields.len()
        ));
        for field in &st.fields {
            let (ok, push) = self.generate_push(
                &field.fieldtype,
                &format!("val.{}", field.fieldname),
                "    ",
            );
            cpp.push_str(&format!("{}\n", push));
            if ok {
                cpp.push_str(&format!(
                    "    lua_setfield(L, -2, \"{}\");\n",
                    field.fieldname
                ));
            } else {
                println!(
                    "Unsupported field type in push for struct {}: {}",
                    st.name, field.fieldtype
                );
            }
        }
        cpp.push_str("}\n\n");
        Some(cpp)
    }

    fn generate_consts(&self, stats: &mut Stats) {
        let mut cpp = String::new();
        cpp.push_str("#include \"auto.hpp\"\n\n");
        cpp.push_str("namespace luasteam {\n\n");
        cpp.push_str("void add_consts_auto(lua_State *L) {\n");
        stats.consts_total = self.api.consts.len();

        for enm in &self.api.consts {
            let (ok, push) = self.generate_push(&enm.consttype, &enm.constval, "    ");
            cpp.push_str(&format!("{}\n", push));
            if ok {
                cpp.push_str(&format!(
                    "    lua_setfield(L, -2, \"{}\");\n",
                    enm.constname
                ));
                stats.const_generated += 1;
            }
        }

        cpp.push_str("}\n\n} // namespace luasteam\n");
        fs::write("../src/auto/consts.cpp", cpp).expect("Unable to write consts.cpp");
    }

    fn generate_enums(&self, stats: &mut Stats) {
        let mut cpp = String::new();
        cpp.push_str("#include \"auto.hpp\"\n\n");
        cpp.push_str("namespace luasteam {\n\n");
        cpp.push_str("void add_enums_auto(lua_State *L) {\n");

        for enm in &self.api.enums {
            for val in &enm.values {
                cpp.push_str(&format!("    lua_pushinteger(L, {});\n", val.name));
                cpp.push_str(&format!("    lua_setfield(L, -2, \"{}\");\n", val.name));
                stats.enum_values_generated += 1;
            }
            stats.enum_values_total += enm.values.len();
        }

        cpp.push_str("}\n\n} // namespace luasteam\n");
        fs::write("../src/auto/enums.cpp", cpp).expect("Unable to write enums.cpp");
    }

    fn generate_auto_header(&self, interfaces: &[String]) {
        let mut h = String::new();
        h.push_str("#ifndef LUASTEAM_AUTO_HPP\n");
        h.push_str("#define LUASTEAM_AUTO_HPP\n\n");
        h.push_str("#include \"../common.hpp\"\n");
        h.push_str("#include <vector>\n\n");
        h.push_str("namespace luasteam {\n\n");
        h.push_str("void add_enums_auto(lua_State *L);\n");
        h.push_str("void add_consts_auto(lua_State *L);\n");
        for st in &self.added_structs {
            h.push_str(&format!("{} check_{}(lua_State *L, int index);\n", st, st));
            h.push_str(&format!("void push_{}(lua_State *L, {} val);\n", st, st));
        }
        for name in interfaces {
            h.push_str(&format!("void register_{}_auto(lua_State *L);\n", name));
            h.push_str(&format!("void add_{}_auto(lua_State *L);\n", name));
            h.push_str(&format!("void init_{}_auto(lua_State *L);\n", name));
            h.push_str(&format!("void shutdown_{}_auto(lua_State *L);\n", name));
            h.push_str(&format!("extern int {}_ref;\n", name));
        }
        h.push_str("\n} // namespace luasteam\n\n");
        h.push_str("#endif // LUASTEAM_AUTO_HPP\n");
        fs::write("../src/auto/auto.hpp", h).expect("Unable to write auto.hpp");
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
        indent: &str,
    ) -> (bool, String) {
        let mut out = String::new();
        let i1 = indent;
        let i2 = format!("{}{}", indent, BASE_INDENT);
        macro_rules! add_line {
            ($line_indent:expr, $line:expr $(,)?) => {{
                out.push_str($line_indent);
                out.push_str($line);
                out.push('\n');
            }};
        }
        let type_prefix = if create_var {
            format!("{} ", original_type)
        } else {
            String::new()
        };
        match resolved {
            CppType::Normal(type_name) => match type_name {
                "int" | "unsigned char" => {
                    add_line!(i1,
                        &format!(
                            "{}{} = static_cast<{}>(luaL_checkint(L, {}));",
                            type_prefix, value_accessor, original_type, lua_idx
                        ),
                    );
                    (true, out)
                }
                "bool" => {
                    add_line!(i1,
                        &format!("{}{} = lua_toboolean(L, {});", type_prefix, value_accessor, lua_idx),
                    );
                    (true, out)
                }
                "double" | "float" => {
                    add_line!(i1,
                        &format!(
                            "{}{} = static_cast<{}>(luaL_checknumber(L, {}));",
                            type_prefix, value_accessor, original_type, lua_idx
                        ),
                    );
                    (true, out)
                }
                "uint64" | "unsigned long long" | "CSteamID" | "CGameID" => {
                    let mut get = format!("luasteam::checkuint64(L, {})", lua_idx);
                    if type_name == "CSteamID" || type_name == "CGameID" {
                        get = format!("{}({})", type_name, get);
                    }
                    add_line!(i1,
                        &format!("{}{} = {};", type_prefix, value_accessor, get),
                    );
                    (true, out)
                }
                _ => {
                    if self.added_structs.contains(type_name) {
                        add_line!(i1,
                            &format!(
                                "{}{} = check_{}(L, {});",
                                type_prefix, value_accessor, type_name, lua_idx
                            ),
                        );
                        (true, out)
                    } else {
                        add_line!(i1,
                            &format!(
                                "// Unsupported check type: {} ({})",
                                original_type, type_name
                            ),
                        );
                        (false, out)
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
                    add_line!(i1,
                        &format!("const char *{} = luaL_checkstring(L, {});", var, lua_idx),
                    );
                    add_line!(i1,
                        &format!(
                            "if (strlen({}) >= {}) luaL_error(L, \"String too long\");",
                            var, size
                        ),
                    );

                    if create_var {
                        add_line!(i1,
                            &format!("char {}[{}];", value_accessor, size),
                        );
                    }
                    add_line!(i1,
                        &format!(
                            "memcpy({}, {}, sizeof({}));",
                            value_accessor, var, value_accessor
                        ),
                    );
                    (true, out)
                } else {
                    add_line!(i1,
                        &format!("luaL_checktype(L, {}, LUA_TTABLE);", lua_idx),
                    );
                    if create_var {
                        add_line!(i1,
                            &format!("std::vector<{}> {}({});", ttype, value_accessor, size),
                        );
                    }
                    add_line!(i1,
                        &format!("for(decltype({}) i=0;i<{};i++){{", size, size),
                    );
                    add_line!(&i2, "lua_rawgeti(L, -1, i+1);");
                    let (ok, check) = self.generate_check(
                        ttype,
                        self.resolve_type(ttype),
                        false,
                        &format!("{}[i]", value_accessor),
                        "-1",
                        &i2,
                    );
                    if ok {
                        out.push_str(&check);
                        add_line!(&i2, "lua_pop(L, 1);");
                        add_line!(i1, "}");
                        (true, out)
                    } else {
                        add_line!(
                            i1,
                            &format!("// Unsupported check array type: {} [{}]", ttype, size),
                        );
                        (false, out)
                    }
                }
            }
            _ => {
                add_line!(
                    i1,
                    &format!("// Unsupported check type: {:?}", resolved),
                );
                (false, out)
            }
        }
    }

    fn generate_push(&self, ftype: &str, value_accessor: &str, indent: &str) -> (bool, String) {
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
        (ok, format!("{}{}", indent, push))
    }

    fn generate_callback_listener(
        &self,
        name_lower: &str,
        classname: &str,
        callbacks: &[CallbackStruct],
    ) -> String {
        let mut s = String::new();
        if callbacks.is_empty() {
            s.push_str(&format!(
                "void init_{}_auto(lua_State *L) {{}}\n\n",
                name_lower
            ));
            s.push_str(&format!(
                "void shutdown_{}_auto(lua_State *L) {{\n",
                name_lower
            ));
            s.push_str(&format!(
                "    luaL_unref(L, LUA_REGISTRYINDEX, {}_ref);\n",
                name_lower
            ));
            s.push_str(&format!("    {}_ref = LUA_NOREF;\n", name_lower));
            s.push_str("}\n\n");
            return s;
        }

        s.push_str("namespace {\n\n");
        s.push_str("class CallbackListener {\n");
        s.push_str("  private:\n");
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
            s.push_str(&format!(
                "    {}(CallbackListener, {}, {});\n",
                macro_name, cpp_func_name, cb.name
            ));
        }
        s.push_str("};\n\n");

        for cb in callbacks {
            let lua_func_name = Self::to_lua_callback_name(&cb.name);
            let mut cpp_func_name = cb.name.clone();
            if cpp_func_name.ends_with("_t") {
                cpp_func_name = cpp_func_name[..cpp_func_name.len() - 2].to_string();
            }
            cpp_func_name = format!("On{}", cpp_func_name);
            s.push_str(&format!(
                "void CallbackListener::{}({} *data) {{\n",
                cpp_func_name, cb.name
            ));
            s.push_str("    if (data == nullptr) return;\n");
            s.push_str("    lua_State *L = luasteam::global_lua_state;\n");
            s.push_str("    if (!lua_checkstack(L, 4)) return;\n");
            s.push_str(&format!(
                "    lua_rawgeti(L, LUA_REGISTRYINDEX, luasteam::{}_ref);\n",
                name_lower
            ));
            s.push_str(&format!(
                "    lua_getfield(L, -1, \"{}\");\n",
                lua_func_name
            ));
            s.push_str("    if (lua_isnil(L, -1)) {\n");
            s.push_str("        lua_pop(L, 2);\n");
            s.push_str("    } else {\n");
            s.push_str(&format!(
                "        lua_createtable(L, 0, {});\n",
                cb.fields.len()
            ));
            for field in &cb.fields {
                let (ok, push) = self.generate_push(
                    &field.fieldtype,
                    &format!("data->{}", field.fieldname),
                    "        ",
                );
                s.push_str(&format!("{}\n", push));
                if ok {
                    s.push_str(&format!(
                        "        lua_setfield(L, -2, \"{}\");\n",
                        field.fieldname
                    ));
                }
            }
            s.push_str("        lua_call(L, 1, 0);\n");
            s.push_str("        lua_pop(L, 1);\n");
            s.push_str("    }\n");
            s.push_str("}\n\n");
        }

        s.push_str(&format!(
            "CallbackListener *{}_listener = nullptr;\n\n",
            name_lower
        ));
        s.push_str("} // namespace\n\n");
        s.push_str(&format!(
            "void init_{}_auto(lua_State *L) {{ {}_listener = new CallbackListener(); }}\n\n",
            name_lower, name_lower
        ));
        s.push_str(&format!(
            "void shutdown_{}_auto(lua_State *L) {{\n",
            name_lower
        ));
        s.push_str(&format!(
            "    luaL_unref(L, LUA_REGISTRYINDEX, {}_ref);\n",
            name_lower
        ));
        s.push_str(&format!("    {}_ref = LUA_NOREF;\n", name_lower));
        s.push_str(&format!(
            "    delete {}_listener; {}_listener = nullptr;\n",
            name_lower, name_lower
        ));
        s.push_str("}\n\n");
        s
    }

    fn generate_interface(
        &self,
        interface: &Interface,
        method_blocklist: &HashSet<String>,
        stats: &mut Stats,
    ) -> Result<String, &str> {
        let mut cpp = String::new();
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

        cpp.push_str(&format!("#include \"auto.hpp\"\n\n"));

        cpp.push_str("namespace luasteam {\n\n");

        cpp.push_str(&format!("int {}_ref = LUA_NOREF;\n\n", name));

        let callbacks = self
            .interface_callbacks
            .get(&interface.classname)
            .map(|v| v.as_slice())
            .unwrap_or(&[]);
        cpp.push_str(&self.generate_callback_listener(&name, &interface.classname, callbacks));
        cpp.push_str("\n");

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
                cpp.push_str(&generated);
                cpp.push_str("\n");
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
        cpp.push_str(&format!("void register_{}_auto(lua_State *L) {{\n", name));
        for (m, c_name) in &generated_methods {
            cpp.push_str(&format!(
                "    add_func(L, \"{}\", {});\n",
                m.methodname, c_name
            ));
        }
        cpp.push_str("}\n\n");

        // Generate add_..._auto function
        let interface_enum_values_count: usize =
            interface.enums.iter().map(|enm| enm.values.len()).sum();
        cpp.push_str(&format!("void add_{}_auto(lua_State *L) {{\n", name));
        cpp.push_str(&format!(
            "    lua_createtable(L, 0, {});\n",
            generated_methods.len() + interface_enum_values_count
        ));
        cpp.push_str(&format!("    register_{}_auto(L);\n", name));
        for enm in &interface.enums {
            for val in &enm.values {
                cpp.push_str(&format!(
                    "    lua_pushinteger(L, {}::{});\n",
                    interface.classname, val.name
                ));
                cpp.push_str(&format!("    lua_setfield(L, -2, \"{}\");\n", val.name));
            }
        }
        cpp.push_str(&format!("    lua_pushvalue(L, -1);\n"));
        cpp.push_str(&format!(
            "    {}_ref = luaL_ref(L, LUA_REGISTRYINDEX);\n",
            name
        ));
        cpp.push_str(&format!("    lua_setfield(L, -2, \"{}\");\n", name));
        cpp.push_str("}\n\n} // namespace luasteam\n");

        let path = format!("../src/auto/{}.cpp", name);
        fs::write(path, cpp).expect("Unable to write generated file");
        Ok(name.to_owned())
    }

    fn push_array(&self, ttype: &str, value_accessor: &str, size: &str, indent: &str) -> Option<String> {
        let mut s = String::new();
        let add_line = |s: &mut String, indent: &str, line: &str| {
            if !s.is_empty() {
                s.push('\n');
            }
            s.push_str(indent);
            s.push_str(line);
        };

        add_line(&mut s, indent, &format!("lua_createtable(L, {}, 0);", size));
        let inner_indent = format!("{}    ", indent);
        let (ok, push) =
            self.generate_push(ttype, &format!("{}[i]", value_accessor), &inner_indent);
        if ok {
            add_line(
                &mut s,
                indent,
                &format!("for(decltype({}) i=0;i<{};i++){{", size, size),
            );
            if !push.is_empty() {
                s.push('\n');
                s.push_str(&push);
            }
            add_line(&mut s, &inner_indent, "lua_rawseti(L, -2, i+1);");
            add_line(&mut s, indent, "}");
        } else {
            println!("Unsupported type in array push: {}", ttype);
            return None;
        }
        Some(s)
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
        let mut s = String::new();

        let interface_getter = format!("{}()", accessor_name);

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
        let lua_method_name = format!("luasteam_{}_{}", interface, method.methodname);
        s.push_str(&format!(
            "EXTERN int {}(lua_State *L) {{\n",
            lua_method_name
        ));

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
                    s.push_str(&format!(
                        "    char {} = luaL_checkstring(L, {})[0];\n",
                        param.paramname, lua_idx
                    ));
                    param_names.push(param.paramname.clone());
                    lua_idx += 1;
                }
                Normal("double" | "float") => {
                    s.push_str(&format!(
                        "    {} {} = luaL_checknumber(L, {});\n",
                        param.paramtype, param.paramname, lua_idx
                    ));
                    param_names.push(param.paramname.clone());
                    lua_idx += 1;
                }
                Normal("int" | "unsigned char") => {
                    s.push_str(&format!(
                        "    {} {} = static_cast<{}>(luaL_checkint(L, {}));\n",
                        param.paramtype, param.paramname, param.paramtype, lua_idx
                    ));
                    param_names.push(param.paramname.clone());
                    lua_idx += 1;
                }
                Normal("bool") => {
                    s.push_str(&format!(
                        "    bool {} = lua_toboolean(L, {});\n",
                        param.paramname, lua_idx
                    ));
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
                        s.push_str(&format!(
                            "    char *{} = const_cast<char*>(luaL_checkstring(L, {}));\n",
                            param.paramname, lua_idx
                        ));
                    } else {
                        s.push_str(&format!(
                            "    const char *{} = luaL_checkstring(L, {});\n",
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
                    s.push_str(&format!(
                        "    {} {}(luasteam::checkuint64(L, {}));\n",
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
                                s.push_str(&format!(
                                    "    {} {} = luaL_checkint(L, {});\n",
                                    // remove pointer if it is
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
                        s.push_str(&format!(
                            "    std::vector<{}> {}({});\n",
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
                        s.push_str(&format!(
                            "    {} {};",
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
                            "    ",
                        );
                        if ok {
                            assert!(sz_param_to_ignore.is_none());
                            sz_param_to_ignore = Some(sz.to_string());
                            lua_idx += 1;
                            s.push_str(&format!(
                                "    {} {} = luaL_checkint(L, {});\n",
                                p.paramtype
                                    .strip_suffix(" *")
                                    .unwrap_or(p.paramtype.as_str()),
                                sz,
                                lua_idx
                            ));
                            lua_idx += 1;

                            s.push_str(&format!("{}\n", code));
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
            s.push_str(&format!("    {};\n", call));
        } else {
            s.push_str(&format!("    {} __ret = {};\n", method.returntype, call));
            let (ok, push) = self.generate_push(&method.returntype, "__ret", "    ");
            if !ok {
                // Skip methods with unknown return types
                stats.unsupported_types.insert(method.returntype.clone());
                return None;
            }
            s.push_str(&format!("{}\n", push));
            return_count = 1;
        }

        // Push pointer output values onto stack
        for (param, is_array) in pointer_params {
            let resolved = self.resolve_type(&param.paramtype);
            if is_array {
                if resolved.is_buffer() {
                    if matches!(resolved, CppType::Pointer { ttype: "char", .. }) {
                        // A string with variable size
                        s.push_str(&format!(
                            "    lua_pushstring(L, reinterpret_cast<const char*>({}.data()));\n",
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
                        s.push_str(&format!(
                            "    lua_pushlstring(L, reinterpret_cast<const char*>({}.data()), {});\n",
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
                        "    ",
                    ) {
                        s.push_str(&code);
                    } else {
                        stats.unsupported_types.insert(param.paramtype.clone());
                        return None;
                    }
                }
            } else {
                let (ok, push) = self.generate_push(
                    param.paramtype.strip_suffix(" *").expect("Invalid pointer"),
                    &param.paramname,
                    "    ",
                );
                if !ok {
                    println!(
                        "Unsupported pointer base type in push: '{}'",
                        param.paramtype
                    );
                    stats.unsupported_types.insert(param.paramtype.clone());
                    return None;
                }
                s.push_str(&format!("{}\n", push));
                return_count += 1;
            }
        }

        s.push_str(&format!("    return {};\n", return_count));
        s.push_str("}\n");
        Some((lua_method_name, s))
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
