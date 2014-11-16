local box2d = require 'LuaBox2D'
local Vec2 = box2d.Vec2
local VA = box2d.VertexArray
local W = box2d.World

do
	local w1 = W(Vec2(0, -1))
	print(w1)
	print(w1.treeHeight, w1.treeQuality, w1.treeBalance)
end
