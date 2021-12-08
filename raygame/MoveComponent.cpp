#include "MoveComponent.h"
#include "Actor.h"

void MoveComponent::update(float deltaTime)
{
	m_velocity = m_moveDirection.getNormalized() * m_speed * deltaTime;

	m_position = getOwner()->getTransform()->getWorldPosition();

	m_position = m_position + m_velocity;
}
