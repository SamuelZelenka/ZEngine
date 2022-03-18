#include "GameObject.h"
#include "../Components/Component.h"
#include "../Game/Game.h"

GameObject::~GameObject()
{
	int gameObjectCount = game->gameObjects.size();
	for (int i = 0; i < gameObjectCount; i++)
	{
		if (game->gameObjects[i] == this)
		{
			game->gameObjects[i] = game->gameObjects[gameObjectCount - 1];
			game->gameObjects.pop_back();
			break;
		}
	}

	for (Component* component : components)
	{
		delete component;
	}
}

void GameObject::set_active(bool isActive) 
{
	isEnabled = isActive; 
	if (isEnabled)
	{
		awake();
	}
};

void GameObject::awake()
{
	if (isEnabled)
	{
		for (Component* component : components)
		{
			component->awake();
		}
	}
}

void GameObject::update()
{
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