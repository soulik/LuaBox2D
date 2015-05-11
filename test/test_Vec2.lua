local box2d = require 'LuaBox2D'
local Vec2 = box2d.Vec2

local v1 = Vec2(1,2)
local v2 = Vec2(3,5)
local v3 = v1 + v2
local v4 = v1 - v2
local v5 = v1 * v2
local v6 = v1 / v2
local v7 = v1 * 5
local v8 = 5 * v2
local v9 = v1.normalizeTo()
local v10 = v1.skew()
local v11 = v1.clamp(Vec2(0,0), Vec2(1,1))
local v12 = v1 % v2

print(v1, v1.x, v1.y)
print(v2, v2.x, v2.y)
print(v3, v3.x, v3.y)
print(v4, v4.x, v4.y)
print(v5)
print(v6)
print(v7, v7.x, v7.y)
print(v8, v8.x, v8.y)
print(v9, v9.x, v9.y)
v1.normalize()
print(v1, v1.x, v1.y)
print(v10, v10.x, v10.y)
print(v1.valid)
v2.zero()
print(v2, v2.x, v2.y)
print(#v1, v1.length, v1.lengthSquared)
print(v11, v11.x, v11.y)
print(v12)

local v0 = Vec2(1,1)
for i=1,100000 do
	local v = Vec2(i, i)
	local vOut = v0 + v
	vOut.x = v0.x
end