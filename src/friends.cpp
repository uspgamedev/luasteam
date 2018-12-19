#include "friends.hpp"

// ============================
// ======= SteamFriends =======
// ============================

namespace {

class SteamFriendsListener;
SteamFriendsListener *friends_listener = nullptr;
int friends_ref = LUA_NOREF;

const char *dialog_types[] = {"friends", "community", "players", "settings", "officialgamegroup", "stats", "achievements", NULL};

class SteamFriendsListener {
  private:
    STEAM_CALLBACK(SteamFriendsListener, OnGameOverlayActivated, GameOverlayActivated_t);
};

void SteamFriendsListener::OnGameOverlayActivated(GameOverlayActivated_t *data) {
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

} // namespace

// void ActivateGameOverlay( const char *pchDialog );
EXTERN int luasteam_activateGameOverlay(lua_State *L) {
    const char *dialog = dialog_types[luaL_checkoption(L, 1, NULL, dialog_types)];
    SteamFriends()->ActivateGameOverlay(dialog);
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

namespace luasteam {

void add_friends(lua_State *L) {
    lua_createtable(L, 0, 3);
    add_func(L, "activateGameOverlay", luasteam_activateGameOverlay);
    add_func(L, "activateGameOverlayToWebPage", luasteam_activateGameOverlayToWebPage);
    add_func(L, "getFriendPersonaName", luasteam_getFriendPersonaName);
    lua_pushvalue(L, -1);
    friends_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    friends_listener = new SteamFriendsListener();
    lua_setfield(L, -2, "friends");
}

} // namespace luasteam
