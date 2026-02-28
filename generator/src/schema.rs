use serde::{Deserialize, Serialize};
use std::collections::{HashMap, HashSet};

#[derive(Debug, Clone, PartialEq, Eq)]
pub enum SkipReason {
    ManualBlocklist(String), // Blocked with no manual implementation
    ManualImpl(String),      // Blocked because a manual C++ implementation exists
    UnsupportedType(String),
    NoAccessors,
    Incomplete,
}

impl SkipReason {
    pub fn description(&self) -> String {
        match self {
            SkipReason::ManualBlocklist(reason) => format!("blocklist: {}", reason),
            SkipReason::ManualImpl(reason) => format!("manual impl: {}", reason),
            SkipReason::UnsupportedType(t) => format!("unsupported type: {}", t),
            SkipReason::NoAccessors => "no accessors".to_string(),
            SkipReason::Incomplete => "incomplete".to_string(),
        }
    }

    /// Returns true if this method has a manual implementation and should count as covered.
    pub fn is_manual_impl(&self) -> bool {
        matches!(self, SkipReason::ManualImpl(_))
    }
}

#[derive(Debug, Default)]
pub struct Stats {
    pub interfaces_total: usize,
    pub interfaces_generated: usize,
    pub methods_total: usize,
    pub methods_generated: usize,
    pub methods_manual: usize,
    pub enum_values_total: usize,
    pub enum_values_generated: usize,
    pub consts_total: usize,
    pub const_generated: usize,
    pub structs_total: usize,
    pub structs_generated: usize,
    pub structs_manual: usize,

    // Track skipped items with reasons
    pub skipped_interfaces: Vec<(String, SkipReason)>,
    pub skipped_methods: Vec<(String, SkipReason)>,
    pub skipped_structs: Vec<(String, SkipReason)>,

    // Per-interface coverage: (total_methods, auto_generated_methods, manual_impl_methods)
    pub interface_coverage: HashMap<String, (usize, usize, usize)>,
}

impl Stats {
    pub fn print_summary(&self) {
        println!("\n╔═══════════════════════════════════════════════════════════════╗");
        println!("║                    Generation Summary                        ║");
        println!("╚═══════════════════════════════════════════════════════════════╝");

        println!(
            "\nInterfaces:  {} total, {} generated, {} skipped",
            self.interfaces_total,
            self.interfaces_generated,
            self.interfaces_total - self.interfaces_generated
        );
        println!(
            "Methods:     {} total, {} generated, {} manual, {} skipped",
            self.methods_total,
            self.methods_generated - self.methods_manual,
            self.methods_manual,
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
            "Structs:     {} total, {} generated, {} manual, {} skipped",
            self.structs_total,
            self.structs_generated,
            self.structs_manual,
            self.structs_total - self.structs_generated - self.structs_manual
        );

        // Print per-interface coverage
        if !self.interface_coverage.is_empty() {
            println!("\n┌─────────────────────────────────────────────────────────────┐");
            println!("│ Interface Coverage");
            println!("└─────────────────────────────────────────────────────────────┘");

            let mut interfaces: Vec<_> = self.interface_coverage.iter().collect();
            interfaces.sort_by_key(|(name, _)| *name); // Sort by interface name alphabetically
            interfaces.sort_by(|(_, (a, b, c)), (_, (d, e, f))| {
                let cov_a = (*b + *c) as f64 / (*a as f64).max(1.0);
                let cov_d = (*e + *f) as f64 / (*d as f64).max(1.0);
                cov_d.partial_cmp(&cov_a).unwrap() // Sort by coverage percentage descending
            });

            for (name, (total, auto_gen, manual)) in interfaces {
                let total_covered = auto_gen + manual;
                let percentage = if *total > 0 {
                    (total_covered as f64 / *total as f64) * 100.0
                } else {
                    0.0
                };
                let bar_width = 30;
                let auto_filled =
                    ((*auto_gen as f64 / *total as f64).min(1.0) * bar_width as f64) as usize;
                let manual_filled = ((total_covered as f64 / *total as f64).min(1.0)
                    * bar_width as f64) as usize
                    - auto_filled;
                let empty = bar_width - auto_filled - manual_filled;
                // █ = auto-generated, ▓ = manual impl, ░ = not covered
                let bar: String =
                    "█".repeat(auto_filled) + &"▓".repeat(manual_filled) + &"░".repeat(empty);

                println!(
                    "  {:35} [{:3}/{:3}] {:5.1}% {}",
                    name, total_covered, total, percentage, bar
                );
            }
        }

        // Print skipped interfaces
        if !self.skipped_interfaces.is_empty() {
            println!("\n┌─────────────────────────────────────────────────────────────┐");
            println!("│ Skipped Interfaces ({})", self.skipped_interfaces.len());
            println!("└─────────────────────────────────────────────────────────────┘");
            for (name, reason) in &self.skipped_interfaces {
                println!("  • {} — {}", name, reason.description());
            }
        }

        // Print skipped methods grouped by reason
        if !self.skipped_methods.is_empty() {
            println!("\n┌─────────────────────────────────────────────────────────────┐");
            println!(
                "│ Skipped Methods ({}) — Grouped by Reason",
                self.skipped_methods.len()
            );
            println!("└─────────────────────────────────────────────────────────────┘");

            // Group by reason
            let mut by_reason: HashMap<String, Vec<&String>> = HashMap::new();
            for (name, reason) in &self.skipped_methods {
                by_reason
                    .entry(reason.description())
                    .or_default()
                    .push(name);
            }

            // Sort and display
            let mut reasons: Vec<_> = by_reason.keys().collect();
            reasons.sort();

            for reason_desc in reasons {
                let methods = by_reason.get(reason_desc).unwrap();
                println!("\n  [{}] ({} methods)", reason_desc, methods.len());
                for method_name in methods {
                    println!("    • {}", method_name);
                }
            }
        }

        // Print skipped structs (exclude ManualImpl — those are covered)
        let truly_skipped_structs: Vec<_> = self
            .skipped_structs
            .iter()
            .filter(|(_, r)| !r.is_manual_impl())
            .collect();
        if !truly_skipped_structs.is_empty() {
            println!("\n┌─────────────────────────────────────────────────────────────┐");
            println!("│ Skipped Structs ({})", truly_skipped_structs.len());
            println!("└─────────────────────────────────────────────────────────────┘");
            for (name, reason) in &truly_skipped_structs {
                println!("  • {} — {}", name, reason.description());
            }
        }

        println!("\n═══════════════════════════════════════════════════════════════\n");
    }
}

#[derive(Debug, Deserialize, Serialize)]
pub struct SteamApi {
    pub callback_structs: Vec<CallbackStruct>,
    pub enums: Vec<Enum>,
    pub interfaces: Vec<Interface>,
    pub typedefs: Vec<Typedef>,
    pub structs: Vec<Struct>,
    pub consts: Vec<Const>,
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

    fn fix_deprecated(&mut self) {
        self.interfaces.iter_mut().for_each(|i| {
            i.methods.retain_mut(|m| {
                m.params.retain(|p| !p.paramname.ends_with("_Deprecated"));
                !m.methodname.ends_with("_DEPRECATED")
            })
        });
    }

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
            (
                "ISteamUGC",
                vec![
                    ("StartPlaytimeTracking", vec!["pvecPublishedFileID"]),
                    ("StopPlaytimeTracking", vec!["pvecPublishedFileID"]),
                ],
            ),
            (
                "ISteamNetworking",
                vec![("SendDataOnSocket", vec!["pubData"])],
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

    fn fix_missing_constants(&mut self) {
        let data = [
            ("STEAM_INPUT_HANDLE_ALL_CONTROLLERS", "uint64", "UINT64_MAX"),
            ("STEAM_INPUT_MAX_ANALOG_ACTIONS", "int", "16"),
            ("STEAM_INPUT_MAX_ANALOG_ACTION_DATA", "float", "1.0f"),
            ("STEAM_INPUT_MAX_COUNT", "int", "16"),
            ("STEAM_INPUT_MAX_ACTIVE_LAYERS", "int", "16"),
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
        for i in &mut self.interfaces {
            for m in &mut i.methods {
                for p in &mut m.params {
                    if let Some(oac) = p.out_array_count.as_mut()
                        && oac.starts_with("STEAM_CONTROLLER_")
                    {
                        *oac = oac.replacen("STEAM_CONTROLLER_", "STEAM_INPUT_", 1);
                        changes += 1;
                    }
                }
            }
        }
        assert!(changes == 4);
    }

    fn fix_missing_array_count(&mut self) {
        // it has a name but is wrong
        let param = self
            .interface_mut("ISteamInventory")
            .method_mut("DeserializeResult")
            .param_mut("pBuffer");
        assert!(param.array_count == Some("punOutBufferSize".to_string()));
        param.array_count = Some("unBufferSize".to_string());
        let to_mark_counters = [
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
                "ISteamFriends",
                vec![
                    ("GetClanChatMessage", "prgchText", "cchTextMax"),
                    ("GetFriendMessage", "pvData", "cubData"),
                ],
            ),
            (
                "ISteamGameServer",
                vec![
                    ("GetNextOutgoingPacket", "pOut", "cbMaxOut"),
                    ("BeginAuthSession", "pAuthTicket", "cbAuthTicket"),
                    ("HandleIncomingPacket", "pData", "cbData"),
                ],
            ),
            ("ISteamInventory", vec![]),
            (
                "ISteamMatchmaking",
                vec![
                    ("GetLobbyDataByIndex", "pchKey", "cchKeyBufferSize"),
                    ("GetLobbyDataByIndex", "pchValue", "cchValueBufferSize"),
                    ("GetLobbyChatEntry", "pvData", "cubData"),
                    ("SendLobbyChatMsg", "pvMsgBody", "cubMsgBody"),
                ],
            ),
            (
                "ISteamNetworking",
                vec![
                    ("SendDataOnSocket", "pubData", "cubData"),
                    ("SendP2PPacket", "pubData", "cubData"),
                ],
            ),
            (
                "ISteamNetworkingUtils",
                vec![
                    ("ConvertPingLocationToString", "pszBuf", "cchBufSize"),
                    ("SteamNetworkingIPAddr_ToString", "buf", "cbBuf"),
                    ("SteamNetworkingIdentity_ToString", "buf", "cbBuf"),
                ],
            ),
            (
                "ISteamNetworkingMessages",
                vec![("SendMessageToUser", "pubData", "cubData")],
            ),
            (
                "ISteamNetworkingSockets",
                vec![
                    ("GetConnectionName", "pszName", "nMaxLen"),
                    ("GetDetailedConnectionStatus", "pszBuf", "cbBuf"),
                    ("SendMessageToConnection", "pData", "cbData"),
                    ("ReceivedRelayAuthTicket", "pvTicket", "cbTicket"),
                    ("ReceivedP2PCustomSignal", "pMsg", "cbMsg"),
                    ("SetCertificate", "pCertificate", "cbCertificate"),
                    ("ConfigureConnectionLanes", "pLanePriorities", "nNumLanes"),
                    ("ConfigureConnectionLanes", "pLaneWeights", "nNumLanes"),
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
                "ISteamRemotePlay",
                vec![
                    ("GetInput", "pInput", "unMaxEvents"),
                    // The size is not given explicitly, but instead is calculated from other arguments. Anyhow, it's all input, so it Just Works.
                    ("CreateMouseCursor", "pBGRA", ""),
                ],
            ),
            (
                "ISteamRemoteStorage",
                vec![
                    ("FileRead", "pvData", "cubDataToRead"),
                    ("FileReadAsyncComplete", "pvBuffer", "cubToRead"),
                    ("FileWrite", "pvData", "cubData"),
                    ("FileWriteAsync", "pvData", "cubData"),
                    ("FileWriteStreamWriteChunk", "pvData", "cubData"),
                    ("UGCRead", "pvData", "cubDataToRead"),
                ],
            ),
            (
                "ISteamScreenshots",
                vec![("WriteScreenshot", "pubRGB", "cubRGB")],
            ),
            (
                "ISteamUser",
                vec![
                    ("GetUserDataFolder", "pchBuffer", "cubBuffer"),
                    ("BeginAuthSession", "pAuthTicket", "cbAuthTicket"),
                    ("DecompressVoice", "pCompressed", "cbCompressed"),
                    (
                        "RequestEncryptedAppTicket",
                        "pDataToInclude",
                        "cbDataToInclude",
                    ),
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
                "ISteamUGC",
                vec![
                    ("GetSubscribedItems", "pvecPublishedFileID", "cMaxEntries"),
                    (
                        "StartPlaytimeTracking",
                        "pvecPublishedFileID",
                        "unNumPublishedFileIDs",
                    ),
                    (
                        "StopPlaytimeTracking",
                        "pvecPublishedFileID",
                        "unNumPublishedFileIDs",
                    ),
                ],
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
                assert!(p.array_count.is_none());
                let field = if p.paramtype == "char *" {
                    &mut p.out_string_count
                } else {
                    &mut p.out_array_count
                };
                *field = Some(count_name.to_string());
                if !count_name.is_empty() {
                    assert!(
                        m.params.iter().any(|p| p.paramname == count_name),
                        "Count parameter not found"
                    );
                }
            }
        }
        for (interface_name, method_name, param_name, in_name, out_name) in [
            (
                "ISteamUser",
                "GetVoice",
                "pDestBuffer",
                "cbDestBufferSize",
                "nBytesWritten",
            ),
            (
                "ISteamUser",
                "DecompressVoice",
                "pDestBuffer",
                "cbDestBufferSize",
                "nBytesWritten",
            ),
            (
                "ISteamUser",
                "GetAuthSessionTicket",
                "pTicket",
                "cbMaxTicket",
                "pcbTicket",
            ),
            (
                "ISteamUser",
                "GetEncryptedAppTicket",
                "pTicket",
                "cbMaxTicket",
                "pcbTicket",
            ),
            (
                "ISteamGameServer",
                "GetAuthSessionTicket",
                "pTicket",
                "cbMaxTicket",
                "pcbTicket",
            ),
            (
                "ISteamNetworking",
                "ReadP2PPacket",
                "pubDest",
                "cubDest",
                "pcubMsgSize",
            ),
            (
                "ISteamNetworking",
                "RetrieveData",
                "pubDest",
                "cubDest",
                "pcubMsgSize",
            ),
            (
                "ISteamNetworking",
                "RetrieveDataFromSocket",
                "pubDest",
                "cubDest",
                "pcubMsgSize",
            ),
        ] {
            let p = self
                .interface_mut(interface_name)
                .method_mut(method_name)
                .param_mut(param_name);
            assert!(p.array_count.is_none());
            assert!(p.out_array_count.is_none());
            p.array_count = Some(in_name.to_owned());
            p.out_array_count = Some(out_name.to_owned());
        }
        // Struct methods with output string buffers
        for (s_name, m_name, p_name, count_name) in [
            ("SteamNetworkingIPAddr", "ToString", "buf", "cbBuf"),
            ("SteamNetworkingIdentity", "ToString", "buf", "cbBuf"),
        ] {
            let st = self
                .structs
                .iter_mut()
                .find(|s| s.name == s_name)
                .expect("Struct not found");
            let m = st
                .methods
                .iter_mut()
                .find(|m| m.methodname == m_name)
                .expect("Method not found");
            let p = m
                .params
                .iter_mut()
                .find(|p| p.paramname == p_name)
                .expect("Param not found");
            assert!(p.paramtype == "char *");
            assert!(p.out_string_count.is_none());
            p.out_string_count = Some(count_name.to_string());
        }
    }

    fn fix_steam_client(&mut self) {
        let client = self.interface_mut("ISteamClient");
        // Steam client does have this accessor, not sure why it's missing from the JSON.
        assert!(client.accessors.is_empty());
        client.accessors.push(Accessor {
            kind: "user".to_string(),
            name: "SteamClient".to_string(),
            name_flat: "unknown".to_string(),
        });
        client.accessors.push(Accessor {
            kind: "gameserver".to_string(),
            name: "SteamGameServerClient".to_string(),
            name_flat: "unknown".to_string(),
        });
    }

    pub fn apply_fixes(&mut self) {
        self.fix_deprecated();
        self.fix_missing_constants();
        self.fix_missing_const();
        self.fix_missing_array_count();
        self.struct_mut("SteamNetworkingConfigValue_t")
            .field_mut("m_int64")
            .fieldname = "m_val.m_int64".to_string();
        // SteamNetworkingIdentity fields are internal; the C++ SDK comment says
        // "Don't access this directly, use the accessors!". Mark them private so
        // the auto-generator skips field access and only exposes the methods.
        for field_name in ["m_eType", "m_cbSize", "m_szUnknownRawString"] {
            self.struct_mut("SteamNetworkingIdentity")
                .field_mut(field_name)
                .private = true;
        }
        // TODO: change this, it shouldn't be managed automatically
        // SteamParamStringArray_t::m_ppStrings is a const char** managed by Lua.
        // m_nNumStrings is managed alongside it (set/freed atomically), so mark it private.
        {
            let st = self.struct_mut("SteamParamStringArray_t");
            st.field_mut("m_ppStrings").string_count = Some("m_nNumStrings".to_string());
            st.field_mut("m_nNumStrings").private = true;
        }
        self.fix_steam_client();
    }
}

#[derive(Debug, Deserialize, Serialize)]
pub struct Const {
    pub constname: String,
    pub consttype: String,
    pub constval: String,
}

#[derive(Debug, Deserialize, Serialize, Clone)]
pub struct CallbackStruct {
    #[serde(rename = "struct")]
    pub name: String,
    pub callback_id: i32,
    pub fields: Vec<Field>,
}

#[derive(Debug, Deserialize, Serialize, Clone)]
pub struct Field {
    pub fieldname: String,
    pub fieldtype: String,
    #[serde(default)]
    pub private: bool,
    /// For `const char **` fields: names the sibling field that holds the count.
    /// The generator will produce a string-array __index/__newindex/__gc for this field.
    #[serde(default)]
    pub string_count: Option<String>,
}

#[derive(Debug, Deserialize, Serialize, Clone)]
pub struct Struct {
    #[serde(rename = "struct")]
    pub name: String,
    pub fields: Vec<Field>,
    #[serde(default)]
    pub methods: Vec<Method>,
}

impl Struct {
    fn field_mut(&mut self, name: &str) -> &mut Field {
        self.fields
            .iter_mut()
            .find(|f| f.fieldname == name)
            .expect("Missing field")
    }
}

#[derive(Debug, Deserialize, Serialize, Clone)]
pub struct Enum {
    pub enumname: String,
    #[serde(default)]
    pub fqname: String,
    pub values: Vec<EnumValue>,
}

#[derive(Debug, Deserialize, Serialize, Clone)]
pub struct EnumValue {
    pub name: String,
    pub value: String,
}

#[derive(Debug, Deserialize, Serialize, Clone)]
pub struct Interface {
    pub classname: String,
    pub methods: Vec<Method>,
    #[serde(default)]
    pub accessors: Vec<Accessor>,
    #[serde(default)]
    pub enums: Vec<Enum>,
}

impl Interface {
    fn method_mut(&mut self, name: &str) -> &mut Method {
        self.methods
            .iter_mut()
            .find(|m| m.methodname == name)
            .expect("Missing method")
    }
}

#[derive(Debug, Deserialize, Serialize, Clone)]
pub struct Accessor {
    pub kind: String,
    pub name: String,
    pub name_flat: String,
}

#[derive(Debug, Deserialize, Serialize, Clone)]
pub struct Method {
    pub methodname: String,
    pub methodname_flat: String,
    pub params: Vec<Param>,
    pub returntype: String,
    #[serde(default)]
    pub callresult: Option<String>,
}

impl Method {
    pub fn param(&self, name: &str) -> &Param {
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

#[derive(Debug, Deserialize, Serialize, Clone)]
pub struct Param {
    pub paramname: String,
    pub paramtype: String,
    pub out_string_count: Option<String>,
    #[serde(alias = "out_buffer_count")]
    pub out_array_count: Option<String>,
    #[serde(alias = "buffer_count")]
    pub array_count: Option<String>,
    pub out_array_call: Option<String>,
    pub desc: Option<String>,
    /// Present on `char **` output params: Steam sets `*param` to an internal string.
    #[serde(default)]
    pub out_string: Option<String>,
}

impl Param {
    pub fn input_array_size_param(&self) -> Option<&str> {
        match (
            self.out_string_count.as_deref(),
            self.array_count.as_deref(),
            self.out_array_count.as_deref(),
            self.out_array_call.as_deref(),
        ) {
            (None, None, None, None) => None,
            (Some(s), None, None, None) => Some(s),
            (None, Some(s), None, None) => Some(s),
            (None, None, Some(s), None) => Some(s),
            (None, None, None, Some(oac)) => Some(oac.split_once(',').unwrap().0),
            (Some(s), Some(_), _, _) => Some(s),
            (None, Some(s), Some(_), _) => Some(s),
            (None, None, Some(s), Some(_)) => Some(s),
            _ => unreachable!(),
        }
    }

    pub fn output_array_size_param(&self) -> Option<&str> {
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
            (Some(s), Some(_), _, _) => Some(s),
            (None, Some(s), Some(_), _) => Some(s),
            (None, Some(s), None, Some(_)) => Some(s),
            _ => unreachable!(),
        }
    }
}

#[derive(Debug, Deserialize, Serialize, Clone)]
pub struct Typedef {
    pub typedef: String,
    #[serde(rename = "type")]
    pub type_name: String,
}
