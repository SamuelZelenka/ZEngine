#pragma once

class GameObject;

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
};