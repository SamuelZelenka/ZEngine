#pragma once

struct CollisionInfo;
class GameObject;

class Component
{
public:
	Component(GameObject* gameObject)
	{
		this->gameObject = gameObject;
		init();
	}
	~Component();

	GameObject* gameObject;

	virtual void init();
	virtual void awake();
	virtual void update();
	virtual void on_collision(CollisionInfo* collisionInfo);
	virtual void on_collision_enter(CollisionInfo* collisionInfo);
	virtual void on_collision_exit();
};