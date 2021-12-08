#pragma once

class Actor;

class Component
{
public:
	Component() { m_owner = nullptr; m_name = ""; }
	Component(Actor* owner, const char* name) { m_owner = owner; m_name = name; }
	virtual ~Component() {}

	const char* getName() { return m_name; }
	Actor* getOwner() { return m_owner; }
	void removeOwner() { m_owner = nullptr; }

	virtual void start() { m_started = true; }
	virtual void update(float deltaTime);
	virtual void draw();
	virtual void end() { m_started = false; }

	virtual void onCollision(Actor* target);

private:
	Actor* m_owner;
	const char* m_name;
	bool m_started = false;
};
