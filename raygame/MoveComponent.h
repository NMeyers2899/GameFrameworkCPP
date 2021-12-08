#pragma once
#include "Component.h"

class MoveComponent : public Component
{
public:
	MoveComponent();
	MoveComponent(Actor* owner, const char* name);
	~MoveComponent();

	float getSpeed() { return m_speed; }
	void setSpeed(float value) { m_speed = value; }

private:
	float m_speed;
	
};
