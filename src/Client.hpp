#ifndef LUASTEAM_CLIENT
#define LUASTEAM_CLIENT

#include "Common.hpp"

EXTERN int luasteam_Client_SetWarningMessageHook(lua_State *L);
EXTERN int luasteam_GameServerClient_SetWarningMessageHook(lua_State *L);

namespace luasteam {

void add_Client(lua_State *L);
void init_Client(lua_State *L);
void shutdown_Client(lua_State *L);

void add_GameServerClient(lua_State *L);

} // namespace luasteam

#endif // LUASTEAM_CLIENT
