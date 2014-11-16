local box2d = require 'LuaBox2D'
local Vec2 = box2d.Vec2
local VA = box2d.VertexArray
local W = box2d.World
local BD = box2d.BodyDef
local ES = box2d.EdgeShape
local PS = box2d.PolygonShape
local FD = box2d.FixtureDef

do
	local w1 = W(Vec2(0, -1))

	local ground = (function()
		local bd1 = BD()
		local b1 = w1.createBody(bd1)

		local s1 = ES(Vec2(-20, 0), Vec2(20, 0))

		local fd1 = FD()
		fd1.shape = s1
		local mt = getmetatable(fd1)

		print("OK", mt.typename)
		local f1 = b1.createFixture(fd1)
		return b1
	end)

	local attachment = (function()
		local bd1 = BD()
		bd1.type = 'dynamic'
		bd1.position = Vec2(0, 3)
		local b1 = w1.createBody(bd1)

		local s1 = PS(0.5, 2)

		local f1 = b1.createFixture(s1, 2)
		return b1
	end)

	local platform = (function()
		local bd1 = BD()
		bd1.type = 'dynamic'
		bd1.position = Vec2(-4, 5)
		local b1 = w1.createBody(bd1)

		local s1 = PS(0.5, 4, Vec2(4, 0), 0.5 * math.pi)
		
		local fd = FD()
		fd.shape = s1
		fd.friction = 0.6
		fd.density = 2
		local f1 = b1.createFixture(fd)

		local jd1 = box2d.RevoluteJointDef()
		jd1.initialize(attachment, b1, Vec2(0, 5))
		jd1.maxMotorTorque = 50
		jd1.enableMotor = true
		local j1 = w1.createJoint(jd1)

		local jd2 = box2d.PrismaticJointDef()
		jd2.initialize(ground, b1, Vec2(0, 5), Vec2(1, 0))

		jd2.maxMotorForce = 1000
		jd2.enableMotor = true
		jd2.lowerTranslation = -10
		jd2.upperTranslation = 10
		jd2.enableLimit = true

		local j2 = w1.createJoint(jd2)

		return b1
	end)

--[[
	local step = function()
		if platform.type == 'kinematicBody' then
			local p = platform.getTransform().p
			local v = platform.getLinearVelocity()

			if ((p.x < -10 and v.x < 0) or (p.x > 10 and v.x > 0)) then
				v.x = -v.x;
				platform.linearVelocity = v;
			end
		end

		w1.step(30, 4, 4)
	end

	for i=1,30 do
		step()
	end
	]]--
	local G = ground()
end
