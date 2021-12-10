#include "MoveComponent.h"
#include "Actor.h"

void MoveComponent::update(float deltaTime)
{
	m_velocity = m_moveDirection.normalize() * m_speed * deltaTime;

	m_position = getOwner()->getTransform()->getLocalPosition();

	m_position = m_position + m_velocity;

	getOwner()->getTransform()->setLocalPosition(m_position);
}
