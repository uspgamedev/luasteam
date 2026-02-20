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
---@param cchNameBufferSize integer
---@return boolean
---@return integer -- Value of: pAppID
---@return boolean -- Value of: pbAvailable
---@return string -- Value of: pchName
function Apps.BGetDLCDataByIndex(iDLC, cchNameBufferSize) end

---@param nAppID integer
function Apps.InstallDLC(nAppID) end

---@param nAppID integer
function Apps.UninstallDLC(nAppID) end

---@param nAppID integer
function Apps.RequestAppProofOfPurchaseKey(nAppID) end

---@param cchNameBufferSize integer
---@return boolean
---@return string -- Value of: pchName
function Apps.GetCurrentBetaName(cchNameBufferSize) end

---@param bMissingFilesOnly boolean
---@return boolean
function Apps.MarkContentCorrupt(bMissingFilesOnly) end

---@param appID integer
---@param cMaxDepots integer
---@return integer
---@return integer[] -- Value of: pvecDepots
function Apps.GetInstalledDepots(appID, cMaxDepots) end

---@param appID integer
---@param cchFolderBufferSize integer
---@return integer
---@return string -- Value of: pchFolder
function Apps.GetAppInstallDir(appID, cchFolderBufferSize) end

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
---@return uint64 -- Value of: punBytesDownloaded
---@return uint64 -- Value of: punBytesTotal
function Apps.GetDlcDownloadProgress(nAppID) end

---@return integer
function Apps.GetAppBuildId() end

function Apps.RequestAllProofOfPurchaseKeys() end

---@param pszFileName string
---@param callback fun(data: table?, io_fail: boolean)?
---@return uint64
function Apps.GetFileDetails(pszFileName, callback) end

---@param cubCommandLine integer
---@return integer
---@return string -- Value of: pszCommandLine
function Apps.GetLaunchCommandLine(cubCommandLine) end

---@return boolean
function Apps.BIsSubscribedFromFamilySharing() end

---@return boolean
---@return integer -- Value of: punSecondsAllowed
---@return integer -- Value of: punSecondsPlayed
function Apps.BIsTimedTrial() end

---@param nAppID integer
---@return boolean
function Apps.SetDlcContext(nAppID) end

---@return integer
---@return integer -- Value of: pnAvailable
---@return integer -- Value of: pnPrivate
function Apps.GetNumBetas() end

---@param iBetaIndex integer
---@param cchBetaName integer
---@param cchDescription integer
---@return boolean
---@return integer -- Value of: punFlags
---@return integer -- Value of: punBuildID
---@return string -- Value of: pchBetaName
---@return string -- Value of: pchDescription
function Apps.GetBetaInfo(iBetaIndex, cchBetaName, cchDescription) end

---@param pchBetaName string
---@return boolean
function Apps.SetActiveBeta(pchBetaName) end

Steam.Apps = Apps
