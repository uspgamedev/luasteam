package.cpath = package.cpath .. ";./?.dll"
local luasteam = require("luasteam")
function love.draw()
    love.graphics.print("Hello World", 100, 100)
end
