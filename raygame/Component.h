#pragma once

class Actor;

class Component
{
public:
	Component() { m_owner = nullptr; }
	virtual ~Component() {}

	/// <summary>
	/// Gets the actor that owns this component.
	/// </summary>
	Actor* getOwner() { return m_owner; }

	/// <summary>
	/// Assigns an owner to the component if it does not have one already.
	/// </summary>
	/// <param name="owner"> The potential owner of the component. </param>
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
	virtual void onDestroy() {};

private:
	Actor* m_owner;
	bool m_started = false;
};
