#include "../GameObject/GameObject.h"

class GameObject;

class Component
{
public:
	Component(GameObject* gameObject)
	{
		this->gameObject = gameObject;
	}
	~Component();
	virtual void awake();
	virtual void update();

private:
		GameObject* gameObject;
};