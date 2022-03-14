#pragma once

class GameObject;
class Collider;

class Component
{
protected:

	Component(GameObject* gameObject)
	{
		this->gameObject = gameObject;
		init();
	}
	GameObject* gameObject;

public:
	~Component();
	virtual void init();
	virtual void awake();
	virtual void update();
	virtual void on_collision(Collider* other);
	virtual void on_collision_enter(Collider* other);
	virtual void on_collision_exit();
};