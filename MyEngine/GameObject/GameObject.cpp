#include "GameObject.h"
#include "../Components/Component.h"

GameObject::~GameObject()
{
	for (Component* component : components)
	{
		delete component;
	}
	delete this;
}

void GameObject::update()
{
	this;
	if (isEnabled)
	{
		for (Component* component : components)
		{
			component->update();
		}
	}
}

void GameObject::add_component(Component* component)
{
	components.push_back(component);
}