#ifndef LUASTEAM_EXTRA
#define LUASTEAM_EXTRA

#include "common.hpp"

namespace luasteam {

// Adds extra functions
void add_extra(lua_State *L);

void init_extra(lua_State *L);
void shutdown_extra(lua_State *L);

} // namespace luasteam

#endif // LUASTEAM_EXTRA