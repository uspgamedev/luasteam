---@class Steam.Apps
---@field OnDlcInstalled? fun(data: DlcInstalled_t)
---@field OnNewUrlLaunchParameters? fun(data: NewUrlLaunchParameters_t)
---@field OnAppProofOfPurchaseKeyResponse? fun(data: AppProofOfPurchaseKeyResponse_t)
---@field OnFileDetailsResult? fun(data: FileDetailsResult_t)
---@field OnTimedTrialStatus? fun(data: TimedTrialStatus_t)
local Apps = {}

---@return boolean
function Apps.BIsSubscribed() end

---@return boolean
function Apps.BIsLowViolence() end

---@return boolean
function Apps.BIsCybercafe() end

---@return boolean
function Apps.BIsVACBanned() end

---@return string
function Apps.GetCurrentGameLanguage() end

---@return string
function Apps.GetAvailableGameLanguages() end

---@param appID integer -- AppId_t
---@return boolean
function Apps.BIsSubscribedApp(appID) end

---@param appID integer -- AppId_t
---@return boolean
function Apps.BIsDlcInstalled(appID) end

---@param nAppID integer -- AppId_t
---@return integer
function Apps.GetEarliestPurchaseUnixTime(nAppID) end

---@return boolean
function Apps.BIsSubscribedFromFreeWeekend() end

---@return integer
function Apps.GetDLCCount() end

---@param iDLC integer
---@param cchNameBufferSize integer? size of the buffer for pchName; if nil then the buffer will be NULL
---@return boolean
---@return integer -- Value of: pAppID
---@return boolean -- Value of: pbAvailable
---@return string -- Value of: pchName
function Apps.BGetDLCDataByIndex(iDLC, cchNameBufferSize) end

---@param nAppID integer -- AppId_t
function Apps.InstallDLC(nAppID) end

---@param nAppID integer -- AppId_t
function Apps.UninstallDLC(nAppID) end

---@param nAppID integer -- AppId_t
function Apps.RequestAppProofOfPurchaseKey(nAppID) end

---@param cchNameBufferSize integer? size of the buffer for pchName; if nil then the buffer will be NULL
---@return boolean
---@return string -- Value of: pchName
function Apps.GetCurrentBetaName(cchNameBufferSize) end

---@param bMissingFilesOnly boolean
---@return boolean
function Apps.MarkContentCorrupt(bMissingFilesOnly) end

---@param appID integer -- AppId_t
---@param cMaxDepots integer? size of the buffer for pvecDepots; if nil then the buffer will be NULL
---@return integer
---@return integer[] -- Value of: pvecDepots
function Apps.GetInstalledDepots(appID, cMaxDepots) end

---@param appID integer -- AppId_t
---@param cchFolderBufferSize integer? size of the buffer for pchFolder; if nil then the buffer will be NULL
---@return integer
---@return string -- Value of: pchFolder
function Apps.GetAppInstallDir(appID, cchFolderBufferSize) end

---@param appID integer -- AppId_t
---@return boolean
function Apps.BIsAppInstalled(appID) end

---@return uint64 -- CSteamID
function Apps.GetAppOwner() end

---@param pchKey string?
---@return string
function Apps.GetLaunchQueryParam(pchKey) end

---@param nAppID integer -- AppId_t
---@return boolean
---@return uint64 -- Value of: punBytesDownloaded
---@return uint64 -- Value of: punBytesTotal
function Apps.GetDlcDownloadProgress(nAppID) end

---@return integer
function Apps.GetAppBuildId() end

function Apps.RequestAllProofOfPurchaseKeys() end

---@param pszFileName string?
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64 -- SteamAPICall_t handle; result delivered via the callback when Steam.RunCallbacks() is called
function Apps.GetFileDetails(pszFileName, callback) end

---@param cubCommandLine integer? size of the buffer for pszCommandLine; if nil then the buffer will be NULL
---@return integer
---@return string -- Value of: pszCommandLine
function Apps.GetLaunchCommandLine(cubCommandLine) end

---@return boolean
function Apps.BIsSubscribedFromFamilySharing() end

---@return boolean
---@return integer -- Value of: punSecondsAllowed
---@return integer -- Value of: punSecondsPlayed
function Apps.BIsTimedTrial() end

---@param nAppID integer -- AppId_t
---@return boolean
function Apps.SetDlcContext(nAppID) end

---@return integer
---@return integer -- Value of: pnAvailable
---@return integer -- Value of: pnPrivate
function Apps.GetNumBetas() end

---@param iBetaIndex integer
---@param cchBetaName integer? size of the buffer for pchBetaName; if nil then the buffer will be NULL
---@param cchDescription integer? size of the buffer for pchDescription; if nil then the buffer will be NULL
---@return boolean
---@return integer -- Value of: punFlags
---@return integer -- Value of: punBuildID
---@return string -- Value of: pchBetaName
---@return string -- Value of: pchDescription
function Apps.GetBetaInfo(iBetaIndex, cchBetaName, cchDescription) end

---@param pchBetaName string?
---@return boolean
function Apps.SetActiveBeta(pchBetaName) end

Steam.Apps = Apps
