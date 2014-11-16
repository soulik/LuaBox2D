local box2d = require 'LuaBox2D'
local Vec2 = box2d.Vec2

local gravity = Vec2(0, -10)

local world = box2d.World(gravity)

local bodyDef = box2d.BodyDef()
bodyDef.position = Vec2(0, -1)
local groundBody = world.createBody(bodyDef)
local groundBox = box2d.PolygonShape()
groundBox.setAsBox(50, 2)
local groundFixture = groundBody.createFixture(groundBox, 0)

local bodyDef = box2d.BodyDef()
bodyDef.type = 'dynamic'
bodyDef.position = Vec2(0, 4)
local body = world.createBody(bodyDef)
local dynamicBox = box2d.PolygonShape()
dynamicBox.setAsBox(1, 1)
local fixtureDef = box2d.FixtureDef()
fixtureDef.shape = dynamicBox
fixtureDef.density = 1
fixtureDef.friction = 0.3
local dynamicFixture = groundBody.createFixture(fixtureDef)

local timeStep = 1/30
local velocityIterations = 6
local positionIterations = 2

for i=1,60 do
	world.step(timeStep, velocityIterations, positionIterations)
	local position = body.position
	local angle = body.angle
	io.write(("%4.2f %4.2f %4.2f\n"):format(position.x, position.y, angle))
end
