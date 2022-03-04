#pragma once

class GameObject;

class Component
{
protected:

	Component(GameObject* gameObject)
	{
		this->gameObject = gameObject;
	}
	GameObject* gameObject;

public:
	~Component();
	virtual void awake();
	virtual void update();
};