#pragma once
class Transform2D;
class Collider;
class Component;

class Actor
{
public:
    Actor();
    ~Actor();

    /// <param name="x"> Position on the x axis </param>
    /// <param name="y"> Position on the y axis </param>
    /// <param name="name"> The name of this actor. </param>
    Actor(float x, float y, const char* name);

    /// <summary>
    /// Gets if the actors start function has been called.
    /// </summary>
    bool getStarted() { return m_started; }

    /// <returns> The transform attached to this actor. </returns>
    Transform2D* getTransform() { return m_transform; }

    /// <summary>
    /// Gets the collider attached to this actor.
    /// </summary>
    Collider* getCollider() { return m_collider; }

    /// <summary>
    /// Sets this actors collider.
    /// </summary>
    /// <param name="collider"> The new collider to attach to the actor. </param>
    void setCollider(Collider* collider) { m_collider = collider; }

    /// <summary>
    /// Gets the name of this actor.
    /// </summary>
    const char* getName() { return m_name; }

    /// <summary>
    /// Called during the first update after an actor is added to a scene.
    /// </summary>
    virtual void start();

    /// <summary>
    /// Called every frame.
    /// </summary>
    /// <param name="deltaTime"> The time that has passed from the previous frame to the current. </param>
    virtual void update(float deltaTime);

    /// <summary>
    /// Called every loop to update on screen visuals.
    /// </summary>
    virtual void draw();

    /// <summary>
    /// Called when this actor is removed from the scene.
    /// </summary>
    virtual void end();

    /// <summary>
    /// Called when this actor is destroyed.
    /// </summary>
    virtual void onDestroy();

    /// <summary>
    /// Checks if a collision occured between this actor and another.
    /// </summary>
    /// <param name="other"> The actor to check collision against. </param>
    virtual bool checkForCollision(Actor* other);

    /// <summary>
    /// Called when a collision between this actor and another occurs. 
    /// </summary>
    /// <param name="other"> The actor this actor collided with. </param>
    virtual void onCollision(Actor* other);

    /// <summary>
    /// Adds a component to the actor's array of components.
    /// </summary>
    /// <param name="component"> The component being added to the actor. </param>
    template<typename T>
    T* addComponent();

    Component* addComponent(Component* component);

    bool removeComponent(Component* component);

    template<typename T>
    bool removeComponent();

    /// <summary>
    /// Gets the first instance of a component with the given name.
    /// </summary>
    /// <param name="name"> The name of the component. </param>
    /// <returns> The component of the specified name. </returns>
    template<typename T>
    T* getComponent();

protected:
    const char* m_name;

private:
    bool m_started;
    Transform2D* m_transform;
    Collider* m_collider;
    Component** m_components;
    unsigned int m_componentCount;
};

template<typename T>
T* Actor::addComponent()
{
    T* component = new T();

    // Return null if this component already has an owner.
    Actor* owner = component->getOwner();
    if (owner)
        return nullptr;

    component->assignOwner(this);

    //Create a new array with a size one greater than our old array.
    Component** appendedArray = new Component * [m_componentCount + 1];
    //Copy the values from the old array to the new array.
    for (int i = 0; i < m_componentCount; i++)
    {
        appendedArray[i] = m_components[i];
    }

    if (m_componentCount > 1)
        delete[] m_components;
    else if (m_componentCount == 1)
        delete m_components;

    //Set the last value in the new array to be the actor we want to add.
    appendedArray[m_componentCount] = component;
    //Set old array to hold the values of the new array.
    m_components = appendedArray;
    m_componentCount++;

    return (T*)component;
}

template<typename T>
inline bool Actor::removeComponent()
{
    bool componentRemoved = false;
    Component* componentToDelete = nullptr;
    //Create a new array with a size one less than our old array.
    Component** newArray = new Component * [m_componentCount - 1];
    //Create variable to access tempArray index.
    int j = 0;
    //Copy values from the old array to the new array.
    for (int i = 0; i < m_componentCount; i++)
    {
        T* temp = dynamic_cast<T*>(m_components[i]);
        if (!temp)
        {
            newArray[j] = m_components[i];
            j++;
        }
        else
        {
            delete[] m_components;
            componentToDelete = m_components[i];
            componentRemoved = true;
        }
    }
    //Set the old array to the new array.
    if (componentRemoved)
    {
        m_components = newArray;
        m_componentCount--;
        delete componentToDelete;
    }
    else
        delete[] newArray;

    //Return whether or not the removal was successful.
    return componentRemoved;
}

template<typename T>
inline T* Actor::getComponent()
{
     for (int i = 0; i < m_componentCount; i++)
    {
         T* temp = dynamic_cast<T*>(m_components[i]);

        // Check to see if the name given is the same name of the component at the current index.
        if (temp)
            return m_components[i];
    }
}

