#ifndef LUASTEAM_COMMON
#define LUASTEAM_COMMON

#include "../sdk/public/steam/steam_api.h"
extern "C" {
#include <lauxlib.h>
#include <lua.h>
}

#ifdef _WIN32
#    define EXTERN extern "C" __declspec(dllexport)
#else
#    define EXTERN extern "C"
#endif

static const char *steam_result_code[] = {
    "None", "OK", "Fail", "NoConnection", "NoConnectionRetry", "InvalidPassword", "LoggedInElsewhere", "InvalidProtocolVer", "InvalidParam", "FileNotFound", "Busy", "InvalidState", "InvalidName", "InvalidEmail", "DuplicateName", "AccessDenied", "Timeout", "Banned", "AccountNotFound", "InvalidSteamID", "ServiceUnavailable", "NotLoggedOn", "Pending", "EncryptionFailure", "InsufficientPrivilege", "LimitExceeded", "Revoked", "Expired", "AlreadyRedeemed", "DuplicateRequest", "AlreadyOwned", "IPNotFound", "PersistFailed", "LockingFailed", "LogonSessionReplaced", "ConnectFailed", "HandshakeFailed", "IOFailure", "RemoteDisconnect", "ShoppingCartNotFound", "Blocked", "Ignored", "NoMatch", "AccountDisabled", "ServiceReadOnly", "AccountNotFeatured", "AdministratorOK", "ContentVersion", "TryAnotherCM", "PasswordRequiredToKickSession", "AlreadyLoggedInElsewhere", "Suspended", "Cancelled", "DataCorruption", "DiskFull", "RemoteCallFailed", "PasswordUnset", "ExternalAccountUnlinked", "PSNTicketInvalid", "ExternalAccountAlreadyLinked", "RemoteFileConflict", "IllegalPassword", "SameAsPreviousValue", "AccountLogonDenied", "CannotUseOldPassword", "InvalidLoginAuthCode", "AccountLogonDeniedNoMail", "HardwareNotCapableOfIPT", "IPTInitError", "ParentalControlRestricted", "FacebookQueryError", "ExpiredLoginAuthCode", "IPLoginRestrictionFailed", "AccountLockedDown", "AccountLogonDeniedVerifiedEmailRequired", "NoMatchingURL", "BadResponse", "RequirePasswordReEntry", "ValueOutOfRange", "UnexpectedError", "Disabled", "InvalidCEGSubmission", "RestrictedDevice", "RegionLocked", "RateLimitExceeded", "AccountLoginDeniedNeedTwoFactor", "ItemDeleted", "AccountLoginDeniedThrottle", "TwoFactorCodeMismatch", "TwoFactorActivationCodeMismatch", "AccountAssociatedToMultiplePartners", "NotModified", "NoMobileDevice", "TimeNotSynced", "SmsCodeFailed", "AccountLimitExceeded", "AccountActivityLimitExceeded", "PhoneActivityLimitExceeded", "RefundToWallet", "EmailSendFailure", "NotSettled", "NeedCaptcha", "GSLTDenied", "GSOwnerDenied", "InvalidItemType", "IPBanned", "GSLTExpired", "InsufficientFunds", "TooManyPending", "NoSiteLicensesFound", "WGNetworkSendExceeded", "AccountNotFriends", "LimitedUserAccount", "CantRemoveItem", "AccountDeleted", "ExistingUserCancelledLicense", "CommunityCooldown", "NoLauncherSpecified", "MustAgreeToSSA", "LauncherMigrated", "SteamRealmMismatch", "InvalidSignature", "ParseFailure", "NoVerifiedPhone", "InsufficientBattery", "ChargerRequired", "CachedCredentialInvalid", "PhoneNumberIsVOIP", nullptr,
};

namespace luasteam {

// Use this with care. Should only be used for Callbacks and CallResults.
extern lua_State *global_lua_state;

// using userdata since Lua's number can't safely hold 64-bit integers
void pushuint64(lua_State *L, uint64 v);
uint64 checkuint64(lua_State *L, int nParam);
uint64 assertuint64(lua_State *L, int index, const char *fmt, ...);

// Adds a C function to the table on top of the stack, with given name
void add_func(lua_State *L, const char *name, lua_CFunction func);

template <typename T> class CallResultListener {
  public:
    int callback_ref = LUA_NOREF;
    void Result(T *data, bool io_fail);
    CCallResult<CallResultListener, T> call_result;
};

void init_common(lua_State *L);
void shutdown_common(lua_State *L);

} // namespace luasteam

#endif // LUASTEAM_COMMON
