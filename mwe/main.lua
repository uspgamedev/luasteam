package.cpath = package.cpath .. ";./?.dll"
local luasteam = require("luasteam")
function love.draw()
    love.graphics.print("luasteam loaded!", 100, 100)
end
