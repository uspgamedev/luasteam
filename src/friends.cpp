#include "friends.hpp"

// ============================
// ======= SteamFriends =======
// ============================

namespace {

class CallbackListener;
CallbackListener *friends_listener = nullptr;
int friends_ref = LUA_NOREF;

const char *dialog_types[] = {"friends", "community", "players", "settings", "officialgamegroup", "stats", "achievements", NULL};

class CallbackListener {
  private:
    STEAM_CALLBACK(CallbackListener, OnGameLobbyJoinRequested, GameLobbyJoinRequested_t);
    STEAM_CALLBACK(CallbackListener, OnGameOverlayActivated, GameOverlayActivated_t);
    STEAM_CALLBACK(CallbackListener, OnGameRichPresenceJoinRequested, GameRichPresenceJoinRequested_t);
};

void CallbackListener::OnGameLobbyJoinRequested(GameLobbyJoinRequested_t *data) {
    if (data == nullptr) {
        return;
    }
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) {
        return;
    }
    lua_rawgeti(L, LUA_REGISTRYINDEX, friends_ref);
    lua_getfield(L, -1, "onGameLobbyJoinRequested");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        luasteam::pushuint64(L, data->m_steamIDLobby.ConvertToUint64());
        lua_setfield(L, -2, "lobby");
        luasteam::pushuint64(L, data->m_steamIDFriend.ConvertToUint64());
        lua_setfield(L, -2, "friend");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGameOverlayActivated(GameOverlayActivated_t *data) {
    if (data == nullptr) {
        return;
    }
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) {
        return;
    }
    lua_rawgeti(L, LUA_REGISTRYINDEX, friends_ref);
    lua_getfield(L, -1, "onGameOverlayActivated");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 1);
        lua_pushboolean(L, data->m_bActive);
        lua_setfield(L, -2, "active");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

void CallbackListener::OnGameRichPresenceJoinRequested(GameRichPresenceJoinRequested_t *data) {
    if (data == nullptr) {
        return;
    }
    lua_State *L = luasteam::global_lua_state;
    if (!lua_checkstack(L, 4)) {
        return;
    }

    lua_rawgeti(L, LUA_REGISTRYINDEX, friends_ref);
    lua_getfield(L, -1, "onGameRichPresenceJoinRequested");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 2);
    } else {
        lua_createtable(L, 0, 2);
        luasteam::pushuint64(L, data->m_steamIDFriend.ConvertToUint64());
        lua_setfield(L, -2, "steamIDFriend");
        lua_pushstring(L, data->m_rgchConnect);
        lua_setfield(L, -2, "connect");
        lua_call(L, 1, 0);
        lua_pop(L, 1);
    }
}

} // namespace

// void ActivateGameOverlay( const char *pchDialog );
EXTERN int luasteam_activateGameOverlay(lua_State *L) {
    const char *dialog = dialog_types[luaL_checkoption(L, 1, NULL, dialog_types)];
    SteamFriends()->ActivateGameOverlay(dialog);
    return 0;
}

// void ActivateGameOverlayInviteDialog( CSteamID steamIDLobby );
EXTERN int luasteam_activateGameOverlayInviteDialog(lua_State *L) {
    CSteamID lobby(luasteam::checkuint64(L, 1));
    SteamFriends()->ActivateGameOverlayInviteDialog(lobby);
    return 0;
}

// void ActivateGameOverlayToWebPage( const char *pchURL );
EXTERN int luasteam_activateGameOverlayToWebPage(lua_State *L) {
    const char *url = luaL_checkstring(L, 1);
    SteamFriends()->ActivateGameOverlayToWebPage(url);
    return 0;
}

// const char * GetFriendPersonaName( CSteamID steamIDFriend );
EXTERN int luasteam_getFriendPersonaName(lua_State *L) {
    CSteamID id(luasteam::checkuint64(L, 1));
    const char *name = SteamFriends()->GetFriendPersonaName(id);
    lua_pushstring(L, name);
    return 1;
}

// const char * GetPersonaName();
EXTERN int luasteam_getPersonaName(lua_State *L) {
    const char *name = SteamFriends()->GetPersonaName();
    lua_pushstring(L, name);
    return 1;
}

static int luasteam_getImage(lua_State *L, int handle)
{
    uint32 width, height;
    SteamUtils()->GetImageSize(handle, &width, &height);
    lua_getglobal(L, "love");
    lua_getfield(L, -1, "image");
    lua_getfield(L, -1, "newImageData");
    lua_pushinteger(L, width);
    lua_pushinteger(L, height);
    lua_call(L, 2, 1);
    lua_getfield(L, -1, "getPointer");
    lua_pushvalue(L, -2);
    lua_call(L, 1, 1);
    uint8 *buffer = (uint8*)lua_topointer(L, -1);
    SteamUtils()->GetImageRGBA(handle, buffer, width * height * 4);
    lua_pop(L, 1);
    lua_getfield(L, -3, "graphics");
    lua_getfield(L, -1, "newImage");
    lua_replace(L, -4);
    lua_pop(L, 1);
    lua_call(L, 1, 1);
    lua_replace(L, -2);
    return 1;
}

// int GetLargeFriendAvatar( CSteamID steamIDFriend );
EXTERN int luasteam_getLargeFriendAvatar(lua_State *L) {
    CSteamID id(luasteam::checkuint64(L, 1));
    int handle = SteamFriends()->GetLargeFriendAvatar(id);
    return luasteam_getImage(L, handle);
}

// int GetMediumFriendAvatar( CSteamID steamIDFriend );
EXTERN int luasteam_getMediumFriendAvatar(lua_State *L) {
    CSteamID id(luasteam::checkuint64(L, 1));
    int handle = SteamFriends()->GetMediumFriendAvatar(id);
    return luasteam_getImage(L, handle);
}

// bool SetRichPresence( const char *pchKey, const char *pchValue );
EXTERN int luasteam_setRichPresence(lua_State *L) {
    const char *key = luaL_checkstring(L, 1);
    const char *value = luaL_checkstring(L, 2);
    bool success = SteamFriends()->SetRichPresence(key, value);
    lua_pushboolean(L, success);
    return 1;
}

// bool InviteUserToGame( CSteamID steamIDFriend, const char *pchConnectString );
EXTERN int luasteam_inviteUserToGame(lua_State *L) {
    CSteamID id(luasteam::checkuint64(L, 1));
    const char *connectString = luaL_checkstring(L, 2);

    bool success = SteamFriends()->InviteUserToGame(id, connectString);
    lua_pushboolean(L, success);
    return 1;
}

// int GetFriendCount( int iFriendFlags );
EXTERN int luasteam_getFriendCount(lua_State *L) {
    int flags = luaL_checkint(L, 1);
    int count = SteamFriends()->GetFriendCount(flags);

    lua_pushnumber(L, count);
    return 1;
}

// CSteamID GetFriendByIndex( int iFriend, int iFriendFlags );
EXTERN int luasteam_getFriendByIndex(lua_State *L) {
    int index = luaL_checkint(L, 1);
    int flags = luaL_checkint(L, 2);
    CSteamID id = SteamFriends()->GetFriendByIndex(index, flags);

    luasteam::pushuint64(L, id.ConvertToUint64());
    return 1;
}

namespace luasteam {

void add_friends(lua_State *L) {
    lua_createtable(L, 0, 7);
    add_func(L, "activateGameOverlay", luasteam_activateGameOverlay);
    add_func(L, "activateGameOverlayInviteDialog", luasteam_activateGameOverlayInviteDialog);
    add_func(L, "activateGameOverlayToWebPage", luasteam_activateGameOverlayToWebPage);
    add_func(L, "getFriendPersonaName", luasteam_getFriendPersonaName);
    add_func(L, "getLargeFriendAvatar", luasteam_getLargeFriendAvatar);
    add_func(L, "getMediumFriendAvatar", luasteam_getMediumFriendAvatar);
    add_func(L, "getPersonaName", luasteam_getPersonaName);
    add_func(L, "setRichPresence", luasteam_setRichPresence);
    add_func(L, "inviteUserToGame", luasteam_inviteUserToGame);
    add_func(L, "getFriendCount", luasteam_getFriendCount);
    add_func(L, "getFriendByIndex", luasteam_getFriendByIndex);
    lua_pushvalue(L, -1);
    friends_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "friends");
}

void init_friends(lua_State *L) { friends_listener = new CallbackListener(); }

void shutdown_friends(lua_State *L) {
    luaL_unref(L, LUA_REGISTRYINDEX, friends_ref);
    friends_ref = LUA_NOREF;
    delete friends_listener;
    friends_listener = nullptr;
}

} // namespace luasteam
