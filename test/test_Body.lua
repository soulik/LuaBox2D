local box2d = require 'LuaBox2D'
local Vec2 = box2d.Vec2
local VA = box2d.VertexArray
local W = box2d.World
local BD = box2d.BodyDef
local ES = box2d.EdgeShape
local FD = box2d.FixtureDef

do
	local w1 = W(Vec2(0, -1))
	local bd1 = BD()
	bd1.type = 'static'
	local b1 = w1.createBody(bd1)

	local s1 = ES()
	s1.set(Vec2(-1, 0), Vec2(1, 0))

	local fd1 = FD()
	fd1.shape = s1

	local f1 = b1.createFixture(fd1)

	print(f1.type)

end
