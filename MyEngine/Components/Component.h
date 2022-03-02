#pragma once

class GameObject;

class Component
{
protected:

	Component(GameObject* gameObject)
	{
		this->gameObject = gameObject;
	}

public:
	~Component();
	virtual void awake();
	virtual void update();

private:
		GameObject* gameObject;
};