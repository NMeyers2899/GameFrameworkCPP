#include "Player.h"
#include "Transform2D.h"
#include "MoveComponent.h"
#include "raylib.h"
#include "InputComponent.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"

void Player::start()
{
	Actor::start();

	m_inputComponent = addComponent<InputComponent>();
	m_moveComponent = addComponent<MoveComponent>();
	m_moveComponent->setMaxSpeed(500);
	m_spriteComponent = addComponent<SpriteComponent>();


	// Set spawn point.
	// Set move speed.
	// Set position clamps.
}

void Player::update(float deltaTime)
{
	MathLibrary::Vector2 moveDirection = m_inputComponent->getMoveAxis();

	m_moveComponent->setVelocity(moveDirection * 500);

	Actor::update(deltaTime);
}
