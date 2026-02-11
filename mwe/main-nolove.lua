package.cpath = package.cpath .. ";./?.dll"
local before = os.clock()
local luasteam = require('luasteam')
print("luasteam loaded in " .. (os.clock() - before) .. " seconds!")

assert(luasteam ~= nil, "luasteam module not found")
assert(type(luasteam) == "table", "luasteam is not a table")

-- Test some enums
assert(luasteam.Universe ~= nil, "Universe enum table not found")
assert(luasteam.Universe.Public == 1, "Universe.Public mismatch (expected 1, got " .. tostring(luasteam.Universe.Public) .. ")")

assert(luasteam.Result ~= nil, "Result enum table not found")
assert(luasteam.Result.OK == 1, "Result.OK mismatch (expected 1, got " .. tostring(luasteam.Result.OK) .. ")")

assert(luasteam.InputSourceMode ~= nil, "InputSourceMode enum table not found")
assert(luasteam.InputSourceMode.Trigger == 10, "InputSourceMode.Trigger mismatch (expected 10, got " .. tostring(luasteam.InputSourceMode.Trigger) .. ")")

-- Test some of the new interfaces
assert(luasteam.matchmaking ~= nil, "matchmaking interface not found")
assert(luasteam.http ~= nil, "http interface not found")
assert(luasteam.inventory ~= nil, "inventory interface not found")
assert(luasteam.gameServerStats ~= nil, "gameServerStats interface not found")
assert(luasteam.networking ~= nil, "networking interface not found")
assert(luasteam.screenshots ~= nil, "screenshots interface not found")

print("API import test passed successfully in " .. (os.clock() - before) .. " seconds!")