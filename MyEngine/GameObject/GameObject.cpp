#include "GameObject.h"
#include "../Components/Component.h"

GameObject::~GameObject()
{
}

void GameObject::destroy()
{

}
void GameObject::update()
{
	for (Component* component : components)
	{
		component->update();
	}
}

void GameObject::add_component(Component* component)
{
	components.push_back(component);
}