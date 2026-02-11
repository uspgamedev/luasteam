#include "auto.hpp"

// void CancelServerQuery(HServerQuery hServerQuery);
EXTERN int luasteam_matchmakingservers_SteamAPI_ISteamMatchmakingServers_CancelServerQuery(lua_State *L) {
    HServerQuery hServerQuery = static_cast<HServerQuery>(luaL_checkint(L, 1));
    SteamMatchmakingServers()->CancelServerQuery(hServerQuery);
    return 0;
}

namespace luasteam {

void add_matchmakingservers_auto(lua_State *L) {
    add_func(L, "cancelServerQuery", luasteam_matchmakingservers_SteamAPI_ISteamMatchmakingServers_CancelServerQuery);
}

} // namespace luasteam
