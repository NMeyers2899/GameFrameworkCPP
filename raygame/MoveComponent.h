#pragma once
#include "Component.h"
#include "Transform2D.h"
#include <Vector2.h>

class MoveComponent : public Component
{
public:
	///<summary>
	/// Creates a basic MoveComponent with no owner, name, or speed.
	///</summary>
	MoveComponent() : Component(nullptr, "") { m_speed = 0; }
	///<summary>
	/// Creates a basic MoveComponent with an owner, name, and speed.
	///</summary>
	MoveComponent(Actor* owner, const char* name, float speed) : Component(owner, name) { m_speed = speed; };
	///<summary>
	/// Is called upon the deletion of the MoveComponent
	///</summary>
	~MoveComponent() {}

	float getSpeed() { return m_speed; }
	void setSpeed(float value) { m_speed = value; }

	MathLibrary::Vector2 getDirection() { return m_moveDirection; }
	void setDirection(MathLibrary::Vector2 value) { m_moveDirection = value; }

	void update(float deltaTime) override;

private:
	float m_speed;
	MathLibrary::Vector2 m_moveDirection;
	MathLibrary::Vector2 m_position;
	MathLibrary::Vector2 m_velocity;
};
