#include "SpriteComponent.h"
#include <Vector2.h>
#include "Transform2D.h"
#include "Actor.h"

void SpriteComponent::draw()
{
	float ownerPositionX = getOwner()->getTransform()->getWorldPosition().x;
	float ownerPositionY = getOwner()->getTransform()->getWorldPosition().y;

	Vector2 ownerPosition = Vector2{ ownerPositionX, ownerPositionY };


	DrawTexture(m_texture, ownerPosition.x, ownerPosition.y, WHITE);
}
