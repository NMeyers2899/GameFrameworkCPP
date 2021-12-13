#include "MoveComponent.h"
#include "Actor.h"

void MoveComponent::update(float deltaTime)
{
	// Add the new velocity to the old position to get the new position.
	MathLibrary::Vector2 newPosition = getOwner()->getTransform()->getLocalPosition() + getVelocity() * deltaTime;

	// Set the actors position to the new one.
	getOwner()->getTransform()->setLocalPosition(newPosition);
}
