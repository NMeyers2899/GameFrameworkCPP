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
	MoveComponent() : Component("MoveComponent") { m_maxSpeed = 0; }
	///<summary>
	/// Creates a basic MoveComponent with an owner, name, and speed.
	///</summary>
	MoveComponent(const char* name, float speed) : Component(name) { m_maxSpeed = speed; };
	///<summary>
	/// Is called upon the deletion of the MoveComponent
	///</summary>
	~MoveComponent() {}

	MathLibrary::Vector2 getVelocity() { return m_velocity; }
	void setVelocity(MathLibrary::Vector2 velocity) { m_velocity = velocity; }

	float getMaxSpeed() { return m_maxSpeed; }
	void setMaxSpeed(float maxSpeed) { m_maxSpeed = maxSpeed; }

	void update(float deltaTime) override;

private:
	float m_maxSpeed;
	MathLibrary::Vector2 m_velocity;
};
