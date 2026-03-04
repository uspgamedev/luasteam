package.cpath = package.cpath .. ";./?.dll"
local Steam = require("luasteam")
function love.draw()
    love.graphics.print("luasteam loaded!", 100, 100)
end
