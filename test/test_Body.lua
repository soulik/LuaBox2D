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

		local j1 = box2d.RevoluteJointDef()
		j1.initialize(attachment, b1, Vec2(0, 5))
		j1.maxMotorTorque = 50
		j1.enableMotor = true
		w1.createJoint(j1)

		local j2 = box2d.PrismaticJointDef()
		j2.initialize(ground, b1, Vec2(0, 5), Vec2(1, 0))

		j2.maxMotorForce = 1000
		j2.enableMotor = true
		j2.lowerTranslation = -10
		j2.upperTranslation = 10
		j2.enableLimit = true

		w1.createJoint(j2)
		return b1
	end)()

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
end
