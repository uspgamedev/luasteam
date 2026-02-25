#ifndef LUASTEAM_STEAM_NETWORKING_MESSAGE
#define LUASTEAM_STEAM_NETWORKING_MESSAGE

#include "common.hpp"

namespace luasteam {

// push_SteamNetworkingMessage_t wraps a pointer — the userdata stores the pointer, NOT a copy.
// The caller must not free the message after pushing; ownership is transferred to Lua.
void push_SteamNetworkingMessage_t(lua_State *L, SteamNetworkingMessage_t *msg);
SteamNetworkingMessage_t *check_SteamNetworkingMessage_t(lua_State *L, int nParam);

void init_SteamNetworkingMessage_t(lua_State *L);
void shutdown_SteamNetworkingMessage_t(lua_State *L);

} // namespace luasteam

#endif // LUASTEAM_STEAM_NETWORKING_MESSAGE
