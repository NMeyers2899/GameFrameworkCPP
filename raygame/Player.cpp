#include "Player.h"
#include "Transform2D.h"
#include "MoveComponent.h"
#include "raylib.h"

void Player::update(float deltaTime)
{
	MoveComponent* moveComponent = (MoveComponent*)getComponent("Move Component");

	MathLibrary::Vector2 moveDirection;

	float xDirection, yDirection;

	xDirection = RAYLIB_H::IsKeyPressed(KEY_A) + RAYLIB_H::IsKeyDown(KEY_D);
	yDirection = RAYLIB_H::IsKeyPressed(KEY_W) + RAYLIB_H::IsKeyDown(KEY_S);
	moveDirection = MathLibrary::Vector2{ xDirection, yDirection };

	moveComponent->setDirection(moveDirection);

	Actor::update(deltaTime);
}
