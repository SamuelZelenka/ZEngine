#include "GameObject/GameObject.h"

class Component
{
public:
	Component();
	~Component();
	virtual void awake();
	virtual void update();
	GameObject gameObject;
private:

};