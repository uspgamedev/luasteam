#include "auto.hpp"

// void GetVideoURL(AppId_t unVideoAppID);
EXTERN int luasteam_video_SteamAPI_ISteamVideo_GetVideoURL(lua_State *L) {
    AppId_t unVideoAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
    SteamVideo()->GetVideoURL(unVideoAppID);
    return 0;
}

// void GetOPFSettings(AppId_t unVideoAppID);
EXTERN int luasteam_video_SteamAPI_ISteamVideo_GetOPFSettings(lua_State *L) {
    AppId_t unVideoAppID = static_cast<AppId_t>(luaL_checkint(L, 1));
    SteamVideo()->GetOPFSettings(unVideoAppID);
    return 0;
}

namespace luasteam {

void add_video_auto(lua_State *L) {
    add_func(L, "getVideoURL", luasteam_video_SteamAPI_ISteamVideo_GetVideoURL);
    add_func(L, "getOPFSettings", luasteam_video_SteamAPI_ISteamVideo_GetOPFSettings);
}

} // namespace luasteam
