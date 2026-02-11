#ifndef LUASTEAM_AUTO_HPP
#define LUASTEAM_AUTO_HPP

#include "../common.hpp"

namespace luasteam {

void add_user_auto(lua_State *L);
void add_friends_auto(lua_State *L);
void add_utils_auto(lua_State *L);
void add_matchmaking_auto(lua_State *L);
void add_matchmakingservers_auto(lua_State *L);
void add_parties_auto(lua_State *L);
void add_remotestorage_auto(lua_State *L);
void add_userstats_auto(lua_State *L);
void add_apps_auto(lua_State *L);
void add_networking_auto(lua_State *L);
void add_screenshots_auto(lua_State *L);
void add_music_auto(lua_State *L);
void add_http_auto(lua_State *L);
void add_input_auto(lua_State *L);
void add_controller_auto(lua_State *L);
void add_ugc_auto(lua_State *L);
void add_htmlsurface_auto(lua_State *L);
void add_inventory_auto(lua_State *L);
void add_timeline_auto(lua_State *L);
void add_video_auto(lua_State *L);
void add_parentalsettings_auto(lua_State *L);
void add_remoteplay_auto(lua_State *L);
void add_networkingmessages_auto(lua_State *L);
void add_networkingsockets_auto(lua_State *L);
void add_networkingutils_auto(lua_State *L);
void add_gameserver_auto(lua_State *L);
void add_gameserverstats_auto(lua_State *L);

} // namespace luasteam

#endif // LUASTEAM_AUTO_HPP
