#include "friends.hpp"
#include "auto/auto.hpp"

// ============================
// ======= SteamFriends =======
// ============================

namespace {

const char *dialog_types[] = {"friends", "community", "players", "settings", "officialgamegroup", "stats", "achievements", NULL};

} // namespace

// Manually implemented to use luaL_checkoption for string constants
// void ActivateGameOverlay( const char *pchDialog );
EXTERN int luasteam_activateGameOverlay(lua_State *L) {
    const char *dialog = dialog_types[luaL_checkoption(L, 1, NULL, dialog_types)];
    SteamFriends()->ActivateGameOverlay(dialog);
    return 0;
}

// Manually implemented because EActivateGameOverlayToWebPageMode is not yet supported by the generator
// void ActivateGameOverlayToWebPage( const char *pchURL );
EXTERN int luasteam_activateGameOverlayToWebPage(lua_State *L) {
    const char *url = luaL_checkstring(L, 1);
    SteamFriends()->ActivateGameOverlayToWebPage(url);
    return 0;
}

// Manually implemented to handle null return value and return an empty string instead
// const char * GetFriendRichPresence( CSteamID steamIDFriend, const char *pchKey );
EXTERN int luasteam_getFriendRichPresence(lua_State *L) {
    CSteamID id(luasteam::checkuint64(L, 1));
    const char *key = luaL_checkstring(L, 2);
    const char *value = SteamFriends()->GetFriendRichPresence(id, key);
    lua_pushstring(L, value ? value : "");
    return 1;
}

namespace luasteam {

void add_friends(lua_State *L) {
    lua_createtable(L, 0, 3);
    register_friends_auto(L);
    add_func(L, "activateGameOverlay", luasteam_activateGameOverlay);
    add_func(L, "activateGameOverlayToWebPage", luasteam_activateGameOverlayToWebPage);
    add_func(L, "getFriendRichPresence", luasteam_getFriendRichPresence);
    lua_pushvalue(L, -1);
    friends_ref = luaL_ref(L, LUA_REGISTRYINDEX);
    lua_setfield(L, -2, "friends");
}

void init_friends(lua_State *L) { init_friends_auto(L); }

void shutdown_friends(lua_State *L) {
    shutdown_friends_auto(L);
}

} // namespace luasteam
