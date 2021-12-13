#include "Player.h"
#include "Transform2D.h"
#include "MoveComponent.h"
#include "raylib.h"

void Player::update(float deltaTime)
{
	MoveComponent* moveComponent = (MoveComponent*)getComponent("Move Component");

	MathLibrary::Vector2 moveDirection;

	float xDirection, yDirection;

	xDirection = (int)IsKeyPressed(KEY_D) - (int)IsKeyDown(KEY_A);
	yDirection = (int)IsKeyPressed(KEY_S) - (int)IsKeyDown(KEY_W);
	moveDirection = MathLibrary::Vector2{ xDirection, yDirection };

	Actor::update(deltaTime);
}
