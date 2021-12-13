#pragma once
#include "Component.h"
#include "raylib.h"

class SpriteComponent : public Component
{
public:
	SpriteComponent() : Component("SpriteComponent") {};

	SpriteComponent(const char* name, const char* path) : Component(name) 
	{ m_texture = new Texture2D(RAYLIB_H::LoadTexture(path)); };

	SpriteComponent(const char* name, Texture2D* texture) : Component(name) { m_texture = texture; }

	~SpriteComponent() override;

	int getWidth() { return m_width; }
	void setWidth(int width) { m_width = width; }

	int getHeight() { return m_height; }
	void setHeight(int height) { m_height = height; }

	void draw() override;

private:
	Texture2D* m_texture;
	int m_width;
	int m_height;
};
