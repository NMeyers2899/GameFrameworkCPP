#pragma once

class Actor;

class Component
{
public:
	Component() { m_owner = nullptr; m_name = ""; }
	Component(Actor* owner, const char* name) { m_owner = owner; m_name = name; }
	virtual ~Component() {}

	/// <summary>
	/// Gets the name of the componenet.
	/// </summary>
	const char* getName() { return m_name; }

	/// <summary>
	/// Sets the name of the component.
	/// </summary>
	/// <param name="name"> The new name of the component. </param>
	void setName(const char* name) { m_name = name; }

	/// <summary>
	/// Gets the actor that owns this component.
	/// </summary>
	Actor* getOwner() { return m_owner; }

	void assignOwner(Actor* owner);

	/// <summary>
	/// Removes the current owner of the component.
	/// </summary>
	void removeOwner() { m_owner = nullptr; }

	/// <summary>
	/// Gets whether or not the component has started.
	/// </summary>
	bool getStarted() { return m_started; }

	// Functions called by actor class.
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
