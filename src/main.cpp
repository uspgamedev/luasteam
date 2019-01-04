#include "UGC.hpp"
#include "common.hpp"
#include "core.hpp"
#include "extra.hpp"
#include "friends.hpp"
#include "user.hpp"
#include "user_stats.hpp"
#include "utils.hpp"

// Creates and returns a table with all functions
EXTERN int luaopen_luasteam(lua_State *L) {
    lua_createtable(L, 0, 9);
    luasteam::add_core(L);
    luasteam::add_friends(L);
    luasteam::add_user(L);
    luasteam::add_user_stats(L);
    luasteam::add_utils(L);
    luasteam::add_UGC(L);
    luasteam::add_extra(L);
    return 1;
}
