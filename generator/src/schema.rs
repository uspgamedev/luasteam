use serde::{Deserialize, Serialize};
use std::collections::{BTreeSet, HashSet};

#[derive(Debug, Default)]
pub struct Stats {
    pub interfaces_total: usize,
    pub interfaces_generated: usize,
    pub methods_total: usize,
    pub methods_generated: usize,
    pub enum_values_total: usize,
    pub enum_values_generated: usize,
    pub consts_total: usize,
    pub const_generated: usize,
    pub structs_total: usize,
    pub structs_generated: usize,
    pub unsupported_types: BTreeSet<String>,
}

impl Stats {
    pub fn print_summary(&self) {
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

    pub fn apply_fixes(&mut self) {
        self.fix_deprecated();
        self.fix_missing_constants();
        self.fix_missing_const();
        self.fix_missing_array_count();
        self.struct_mut("SteamNetworkingConfigValue_t")
            .field_mut("m_int64")
            .fieldname = "m_val.m_int64".to_string();
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
}

#[derive(Debug, Deserialize, Serialize)]
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

#[derive(Debug, Deserialize, Serialize)]
pub struct Enum {
    pub enumname: String,
    pub values: Vec<EnumValue>,
}

#[derive(Debug, Deserialize, Serialize)]
pub struct EnumValue {
    pub name: String,
    pub value: String,
}

#[derive(Debug, Deserialize, Serialize)]
pub struct Interface {
    pub classname: String,
    pub methods: Vec<Method>,
    #[serde(default)]
    pub accessors: Vec<Accessor>,
    #[serde(default)]
    pub enums: Vec<InterfaceEnum>,
}

#[derive(Debug, Deserialize, Serialize)]
pub struct InterfaceEnum {
    pub enumname: String,
    #[serde(default)]
    pub fqname: String,
    pub values: Vec<EnumValue>,
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
pub struct Accessor {
    pub kind: String,
    pub name: String,
    pub name_flat: String,
}

#[derive(Debug, Deserialize, Serialize)]
pub struct Method {
    pub methodname: String,
    pub methodname_flat: String,
    pub params: Vec<Param>,
    pub returntype: String,
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

#[derive(Debug, Deserialize, Serialize)]
pub struct Param {
    pub paramname: String,
    pub paramtype: String,
    pub out_string_count: Option<String>,
    pub out_array_count: Option<String>,
    pub array_count: Option<String>,
    pub out_array_call: Option<String>,
    pub desc: Option<String>,
}

impl Param {
    pub fn array_size_param(&self) -> Option<&str> {
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
pub struct Typedef {
    pub typedef: String,
    #[serde(rename = "type")]
    pub type_name: String,
}
