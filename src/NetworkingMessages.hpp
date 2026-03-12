#ifndef LUASTEAM_NETWORKINGMESSAGES
#define LUASTEAM_NETWORKINGMESSAGES

#include "Common.hpp"

namespace luasteam {

// Adds functions from ISteamNetworkingMessages
void add_NetworkingMessages(lua_State *L);
void add_GameServerNetworkingMessages(lua_State *L);

} // namespace luasteam

#endif // LUASTEAM_NETWORKINGMESSAGES
