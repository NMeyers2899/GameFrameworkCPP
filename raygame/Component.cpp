#include "Component.h"

void Component::assignOwner(Actor* owner)
{
	if (getOwner())
		return;

	m_owner = owner;
}

void Component::update(float deltaTime)
{
}

void Component::draw()
{
}

void Component::onCollision(Actor* target)
{
}
