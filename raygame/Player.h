#pragma once
#include "Actor.h"

class Player : public Actor
{
public:
	Player() {};
	Player(float x, float y, const char* name) : Actor(x, y, name) {};
	~Player() {};

	void update(float deltaTime) override;
	
private:

};
