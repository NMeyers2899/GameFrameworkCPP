#include "SpriteComponent.h"
#include <Vector2.h>
#include "Transform2D.h"
#include "Actor.h"

void SpriteComponent::draw()
{
	float ownerPositionX = getOwner()->getTransform()->getWorldPosition().x;
	float ownerPositionY = getOwner()->getTransform()->getWorldPosition().y;

	Vector2 ownerPosition = Vector2{ ownerPositionX, ownerPositionY };

	setWidth((int)ownerPosition.x);
	setHeight((int)ownerPosition.y);

	DrawTextureEx(m_texture, ownerPosition, 0, 0.5, WHITE);
}
