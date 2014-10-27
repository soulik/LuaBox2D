local aj = require 'addJoint'
local genJoint = aj.genJoint

for _, name in ipairs {
	'Revolute',
	'Prismatic',
	'Distance',
	'Pulley',
	'Mouse',
	'Gear',
	'Wheel',
	'Weld',
	'Friction',
	'Rope',
	'Motor',
} do
	genJoint(name)
end