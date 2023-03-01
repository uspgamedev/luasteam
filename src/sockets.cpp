#include "sockets.hpp"

// ======================================
// ======= SteamNetworkingSockets =======
// ======================================

namespace {

//ESteamNetworkingConnectionState
const char *steam_networking_connection_state[] = {
    "None", "Connecting", "FindingRoute", "Connected", "ClosedByPeer", "ProblemDetectedLocally", nullptr,
};

const char *steam_result_code[] = {
 "None", "OK", "Fail", "NoConnection", "NoConnectionRetry", "InvalidPassword", "LoggedInElsewhere", "InvalidProtocolVer", "InvalidParam", "FileNotFound", "Busy", "InvalidState", "InvalidName", "InvalidEmail", "DuplicateName", "AccessDenied", "Timeout", "Banned", "AccountNotFound", "InvalidSteamID", "ServiceUnavailable", "NotLoggedOn", "Pending", "EncryptionFailure", "InsufficientPrivilege", "LimitExceeded", "Revoked", "Expired", "AlreadyRedeemed", "DuplicateRequest", "AlreadyOwned", "IPNotFound", "PersistFailed", "LockingFailed", "LogonSessionReplaced", "ConnectFailed", "HandshakeFailed", "IOFailure", "RemoteDisconnect", "ShoppingCartNotFound", "Blocked", "Ignored", "NoMatch", "AccountDisabled", "ServiceReadOnly", "AccountNotFeatured", "AdministratorOK", "ContentVersion", "TryAnotherCM", "PasswordRequiredToKickSession", "AlreadyLoggedInElsewhere", "Suspended", "Cancelled", "DataCorruption", "DiskFull", "RemoteCallFailed", "PasswordUnset", "ExternalAccountUnlinked", "PSNTicketInvalid", "ExternalAccountAlreadyLinked", "RemoteFileConflict", "IllegalPassword", "SameAsPreviousValue", "AccountLogonDenied", "CannotUseOldPassword", "InvalidLoginAuthCode", "AccountLogonDeniedNoMail", "HardwareNotCapableOfIPT", "IPTInitError", "ParentalControlRestricted", "FacebookQueryError", "ExpiredLoginAuthCode", "IPLoginRestrictionFailed", "AccountLockedDown", "AccountLogonDeniedVerifiedEmailRequired", "NoMatchingURL", "BadResponse", "RequirePasswordReEntry", "ValueOutOfRange", "UnexpectedError", "Disabled", "InvalidCEGSubmission", "RestrictedDevice", "RegionLocked", "RateLimitExceeded", "AccountLoginDeniedNeedTwoFactor", "ItemDeleted", "AccountLoginDeniedThrottle", "TwoFactorCodeMismatch", "TwoFactorActivationCodeMismatch", "AccountAssociatedToMultiplePartners", "NotModified", "NoMobileDevice", "TimeNotSynced", "SmsCodeFailed", "AccountLimitExceeded", "AccountActivityLimitExceeded", "PhoneActivityLimitExceeded", "RefundToWallet", "EmailSendFailure", "NotSettled", "NeedCaptcha", "GSLTDenied", "GSOwnerDenied", "InvalidItemType", "IPBanned", "GSLTExpired", "InsufficientFunds", "TooManyPending", "NoSiteLicensesFound", "WGNetworkSendExceeded", "AccountNotFriends", "LimitedUserAccount", "CantRemoveItem", "AccountDeleted", "ExistingUserCancelledLicense", "CommunityCooldown", "NoLauncherSpecified", "MustAgreeToSSA", "LauncherMigrated", "SteamRealmMismatch", "InvalidSignature", "ParseFailure", "NoVerifiedPhone", "InsufficientBattery", "ChargerRequired", "CachedCredentialInvalid", "PhoneNumberIsVOIP", nullptr,
};

class CallbackListener;
CallbackListener *connection_listener = nullptr;
int sockets_ref = LUA_NOREF;

class CallbackListener {
  private:
    STEAM_CALLBACK(CallbackListener, OnConnectionChanged, SteamNetConnectionStatusChangedCallback_t);
};

void CallbackListener::OnConnectionChanged(SteamNetConnectionStatusChangedCallback_t *data) {
    if (data == nullptr) {
        return;
    }
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) {
        return;
    }
    lua_rawgeti(L, LUA_REGISTRYINDEX, sockets_ref);
    lua_getfield(L, -1, "onConnectionChanged");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);

        // first save current and old state
        lua_pushstring(L, steam_networking_connection_state[data->m_info.m_eState]);
        lua_setfield(L, -2, "state");
        lua_pushstring(L, steam_networking_connection_state[data->m_eOldState]);
        lua_setfield(L, -2, "state_old");
        lua_pushinteger(L, data->m_hConn);
        lua_setfield(L, -2, "connection");

        //int64 steamIDNumber = -1;
        //CSteamID steamID = data->m_info.m_identityRemote.GetSteamID();
        //if (steamID.IsValid()) {
        //    steamIDNumber = steamID.ConvertToUint64();
        //}
        //char *steamIDString = nullptr;
        //sprintf(steamIDString, "%lld", steamIDNumber);
        //lua_pushstring(L, steamIDString);
        //lua_setfield(L, -2, "steam_id");
        //fprintf(stderr, "enable linger: %d\n", bEnableLinger);
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

} // namespace

// HSteamListenSocket CreateListenSocketIP( const SteamNetworkingIPAddr &localAddress, int nOptions, const SteamNetworkingConfigValue_t *pOptions )
EXTERN int luasteam_createListenSocketIP(lua_State *L) {
    SteamNetworkingIPAddr localAdress;
    localAdress.ParseString(luaL_checkstring(L, 1));
    // TODO read options from state
    HSteamListenSocket connectingSocket = SteamNetworkingSockets()->CreateListenSocketIP(localAdress, 0, nullptr);
    lua_pushlightuserdata(L, &connectingSocket);
    return 1;
}

// HSteamNetConnection ConnectByIPAddress( const SteamNetworkingIPAddr &address, int nOptions, const SteamNetworkingConfigValue_t *pOptions )
EXTERN int luasteam_connectByIPAddress(lua_State *L) {
    SteamNetworkingIPAddr address;
    address.ParseString(luaL_checkstring(L, 1));
    // TODO read options from state
    HSteamListenSocket connectingSocket = SteamNetworkingSockets()->ConnectByIPAddress(address, 0, nullptr);
    lua_pushlightuserdata(L, &connectingSocket);
    return 1;
}

// EResult AcceptConnection( HSteamNetConnection hConn )
EXTERN int luasteam_acceptConnection(lua_State *L) {
    HSteamNetConnection hConn = luaL_checkinteger(L, 1);
    EResult result = SteamNetworkingSockets()->AcceptConnection(hConn);
    lua_pushstring(L, steam_result_code[result]);
    return 1;
}

// CloseConnection( HSteamNetConnection hPeer, int nReason, const char *pszDebug, bool bEnableLinger )
EXTERN int luasteam_closeConnection(lua_State *L) {
    HSteamNetConnection hConn = luaL_checkinteger(L, 1);
    bool bEnableLinger = lua_toboolean(L, 2);
    SteamNetworkingSockets()->CloseConnection(hConn, 0, nullptr, false);
    return 0;
}

// CloseListenSocket( HSteamListenSocket hSocket )
EXTERN int luasteam_closeListenSocket(lua_State *L) {
    bool is_user_data = lua_islightuserdata(L, 1) == 1;
    if (is_user_data) {
        HSteamListenSocket *connectingSocket = (HSteamListenSocket*)lua_touserdata(L, 1);
        SteamNetworkingSockets()->CloseListenSocket(*connectingSocket);
    }
    return 0;
}

namespace luasteam {

void add_sockets(lua_State *L) {
    lua_createtable(L, 0, 5);
    add_func(L, "createListenSocketIP", luasteam_createListenSocketIP);
    add_func(L, "connectByIPAddress", luasteam_connectByIPAddress);
    add_func(L, "acceptConnection", luasteam_acceptConnection);
    add_func(L, "closeConnection", luasteam_closeConnection);
    add_func(L, "closeListenSocket", luasteam_closeListenSocket);
    lua_pushvalue(L, -1);
    sockets_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "sockets");
}

void init_sockets(lua_State *L) {
    connection_listener = new CallbackListener();
}

void shutdown_sockets(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, sockets_ref);
    sockets_ref = LUA_NOREF;

    delete connection_listener;
    connection_listener = nullptr;
}

} // namespace luasteam
