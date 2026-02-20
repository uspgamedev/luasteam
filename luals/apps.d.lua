---@class Steam.Apps
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

---@param appID integer
---@return boolean
function Apps.BIsSubscribedApp(appID) end

---@param appID integer
---@return boolean
function Apps.BIsDlcInstalled(appID) end

---@param nAppID integer
---@return integer
function Apps.GetEarliestPurchaseUnixTime(nAppID) end

---@return boolean
function Apps.BIsSubscribedFromFreeWeekend() end

---@return integer
function Apps.GetDLCCount() end

---@param iDLC integer
---@param pchName string
---@param cchNameBufferSize integer
---@return boolean
---@return integer
---@return boolean
function Apps.BGetDLCDataByIndex(iDLC, pchName, cchNameBufferSize) end

---@param nAppID integer
function Apps.InstallDLC(nAppID) end

---@param nAppID integer
function Apps.UninstallDLC(nAppID) end

---@param nAppID integer
function Apps.RequestAppProofOfPurchaseKey(nAppID) end

---@param pchName string
---@param cchNameBufferSize integer
---@return boolean
function Apps.GetCurrentBetaName(pchName, cchNameBufferSize) end

---@param bMissingFilesOnly boolean
---@return boolean
function Apps.MarkContentCorrupt(bMissingFilesOnly) end

---@param appID integer
---@param cMaxDepots integer
---@return integer
---@return integer
function Apps.GetInstalledDepots(appID, cMaxDepots) end

---@param appID integer
---@param pchFolder string
---@param cchFolderBufferSize integer
---@return integer
function Apps.GetAppInstallDir(appID, pchFolder, cchFolderBufferSize) end

---@param appID integer
---@return boolean
function Apps.BIsAppInstalled(appID) end

---@return uint64
function Apps.GetAppOwner() end

---@param pchKey string
---@return string
function Apps.GetLaunchQueryParam(pchKey) end

---@param nAppID integer
---@return boolean
---@return table
---@return table
function Apps.GetDlcDownloadProgress(nAppID) end

---@return integer
function Apps.GetAppBuildId() end

function Apps.RequestAllProofOfPurchaseKeys() end

---@param pszFileName string
---@param callback fun(data: table?, io_fail: boolean)?
---@return SteamAPICall_t
function Apps.GetFileDetails(pszFileName, callback) end

---@param pszCommandLine string
---@param cubCommandLine integer
---@return integer
function Apps.GetLaunchCommandLine(pszCommandLine, cubCommandLine) end

---@return boolean
function Apps.BIsSubscribedFromFamilySharing() end

---@return boolean
---@return integer
---@return integer
function Apps.BIsTimedTrial() end

---@param nAppID integer
---@return boolean
function Apps.SetDlcContext(nAppID) end

---@return integer
---@return integer
---@return integer
function Apps.GetNumBetas() end

---@param iBetaIndex integer
---@param pchBetaName string
---@param cchBetaName integer
---@param pchDescription string
---@param cchDescription integer
---@return boolean
---@return integer
---@return integer
function Apps.GetBetaInfo(iBetaIndex, pchBetaName, cchBetaName, pchDescription, cchDescription) end

---@param pchBetaName string
---@return boolean
function Apps.SetActiveBeta(pchBetaName) end

Steam.Apps = Apps
