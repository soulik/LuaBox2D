local box2d = require 'LuaBox2D'
local Vec2 = box2d.Vec2
local VA = box2d.VertexArray

do
	print('Array 1')
	local a = VA({
		{123.45, 67.89}, {2, 4}
	})

	a[4] = {7, 8}

	print(#a)

	local v1 = a[1]
	local v2 = a[2]
	local v3 = a[3]

	print(v1.x, v1.y)
	print(v2.x, v2.y)
	print(v3.x, v3.y)
end

do
	print('Array 2')
	local a = VA({
		Vec2(123.45, 67.89),
		Vec2(2, 4),
	})
	a[4] = Vec2 {7, 8}

	print(#a)

	local v1 = a[1]
	local v2 = a[2]
	local v3 = a[3]

	print(v1.x, v1.y)
	print(v2.x, v2.y)
	print(v3.x, v3.y)
end