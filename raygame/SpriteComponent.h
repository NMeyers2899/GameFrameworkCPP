#pragma once
#include "Component.h"
#include <raylib.h>

class SpriteComponent : public Component
{
public:
	SpriteComponent() : Component(nullptr, "") {};

	SpriteComponent(Actor* owner, const char* name, const char* path) : Component(owner, name) 
	{ m_texture = RAYLIB_H::LoadTexture(path); };

	~SpriteComponent();

	int getWidth() { return m_texture.width; }
	void setWidth(int value) { m_texture.width = value; }

	int getHeight() { return m_texture.height; }
	void setHeight(int value) { m_texture.height = value; }

	void draw() override;

private:
	Texture2D m_texture;
};
