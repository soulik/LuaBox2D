﻿local box2d = require 'LuaBox2D'
local v1 = box2d.Vec2(1,2)
local v2 = box2d.Vec2(3,5)
local v3 = v1 + v2
local v4 = v1 - v2
local v5 = v1 * v2
local v6 = v1 / v2
local v7 = v1 * 5
local v8 = 5 * v2
local v9 = v1.normalizeTo()
local v10 = v1.skew()

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