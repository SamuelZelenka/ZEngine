#include "GameObject.h"

void GameObject::destroy()
{

}
void GameObject::update()
{

}

void GameObject::add_component(Component* component)
{
	components.push_back(component);
}