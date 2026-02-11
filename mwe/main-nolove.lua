package.cpath = package.cpath .. ";./?.dll"
local before = os.clock()
local luasteam = require('luasteam')
print("luasteam loaded in " .. (os.clock() - before) .. " seconds!")

assert(luasteam ~= nil, "luasteam module not found")
assert(type(luasteam) == "table", "luasteam is not a table")

-- Test some enums
assert(luasteam.k_EUniversePublic == 1, "k_EUniversePublic mismatch (expected 1, got " .. tostring(luasteam.k_EUniversePublic) .. ")")

assert(luasteam.k_EResultOK == 1, "k_EResultOK mismatch (expected 1, got " .. tostring(luasteam.k_EResultOK) .. ")")

assert(luasteam.k_EInputSourceMode_Trigger == 10, "k_EInputSourceMode_Trigger mismatch (expected 10, got " .. tostring(luasteam.k_EInputSourceMode_Trigger) .. ")")

-- Test some of the new interfaces
assert(luasteam.Matchmaking ~= nil, "matchmaking interface not found")
assert(luasteam.HTTP ~= nil, "HTTP interface not found")
assert(luasteam.Inventory ~= nil, "inventory interface not found")
assert(luasteam.GameServerStats ~= nil, "gameServerStats interface not found")
assert(luasteam.Networking ~= nil, "networking interface not found")
assert(luasteam.Screenshots ~= nil, "screenshots interface not found")

print("API import test passed successfully in " .. (os.clock() - before) .. " seconds!")