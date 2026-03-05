package.cpath = package.cpath .. ";./?.dll"
local before = os.clock()
local Steam = require('luasteam')
print("luasteam loaded in " .. (os.clock() - before) .. " seconds!")

assert(Steam ~= nil, "luasteam module not found")
assert(type(Steam) == "table", "luasteam is not a table")

-- Test some enums
assert(Steam.k_EUniversePublic == 1, "k_EUniversePublic mismatch (expected 1, got " .. tostring(Steam.k_EUniversePublic) .. ")")

assert(Steam.k_EResultOK == 1, "k_EResultOK mismatch (expected 1, got " .. tostring(Steam.k_EResultOK) .. ")")

assert(Steam.k_EInputSourceMode_Trigger == 10, "k_EInputSourceMode_Trigger mismatch (expected 10, got " .. tostring(Steam.k_EInputSourceMode_Trigger) .. ")")

-- Test some of the new interfaces
assert(Steam.Matchmaking ~= nil, "matchmaking interface not found")
assert(Steam.GameServerStats ~= nil, "gameServerStats interface not found")
assert(Steam.Screenshots ~= nil, "screenshots interface not found")

x, y = Steam.Extra.ParseUint64("1234"), Steam.Extra.ParseUint64("4444")
assert(tostring(x) == "1234" and y:tostring() == "4444")
assert(x:tonumber() + y:tonumber() == 5678)


print("API import test passed successfully in " .. (os.clock() - before) .. " seconds!")
