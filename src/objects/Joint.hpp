#ifndef LUABOX2D_JOINT_H
#define LUABOX2D_JOINT_H

#include "objects/Vec2.hpp"
#include "objects/Body.hpp"

namespace LuaBox2D {
	class Joint : public Object<b2Joint> {
	protected:
		std::forward_list<std::string> validTypes;
	public:
		explicit Joint(State * state) : Object<b2Joint>(state){
			LUTOK_PROPERTY("type", &Joint::getType, &Joint::nullMethod);
			LUTOK_PROPERTY("bodyA", &Joint::getBodyA, &Joint::nullMethod);
			LUTOK_PROPERTY("bodyB", &Joint::getBodyB, &Joint::nullMethod);

			LUTOK_PROPERTY("anchorA", &Joint::getAnchorA, &Joint::nullMethod);
			LUTOK_PROPERTY("anchorB", &Joint::getAnchorB, &Joint::nullMethod);

			LUTOK_METHOD("reactionForce", &Joint::getReactionForce);
			LUTOK_METHOD("reactionTorque", &Joint::getReactionTorque);

			LUTOK_PROPERTY("active", &Joint::getActive, &Joint::nullMethod);
			LUTOK_PROPERTY("collideConnected", &Joint::getCollideConnected, &Joint::nullMethod);

			validTypes.push_front("Joint");
			validTypes.push_front("RevoluteJoint");
			validTypes.push_front("PrismaticJoint");
			validTypes.push_front("DistanceJoint");
			validTypes.push_front("PulleyJoint");
			validTypes.push_front("MouseJoint");
			validTypes.push_front("GearJoint");
			validTypes.push_front("WheelJoint");
			validTypes.push_front("WeldJoint");
			validTypes.push_front("FrictionJoint");
			validTypes.push_front("RopeJoint");
			validTypes.push_front("MotorJoint");
		}

		b2Joint * constructor(State & );

		b2Joint * get(const int index){
			ObjWrapper * wrapper = getWrapped(index, validTypes);
			if (wrapper){
				return wrapper->instance;
			}else{

				return nullptr;
			}
		}

		void destructor(State & state, b2Joint * object){
			object->GetBodyA()->GetWorld()->DestroyJoint(object);
		}

		int getType(State & state, b2Joint * object){
			state.stack->push<int>(static_cast<int>(object->GetType()));
			return 1;
		}

		int getBodyA(State & state, b2Joint *);

		int getBodyB(State & state, b2Joint *);

		int getAnchorA(State & state, b2Joint *);

		int getAnchorB(State & state, b2Joint *);

		int getReactionForce(State & state, b2Joint *);

		int getReactionTorque(State & state, b2Joint *);

		int getActive(State & state, b2Joint * object){
			state.stack->push<bool>(object->IsActive());
			return 1;
		}

		int getCollideConnected(State & state, b2Joint * object){
			state.stack->push<bool>(object->GetCollideConnected());
			return 1;
		}

	};

	void initJoint(State * );
};

#endif	
