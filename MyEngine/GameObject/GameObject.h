#pragma once
#include "../Game/Game.h"
#include "../Vector/Vector2.h"

class Game;
class Component;

class GameObject
{
public:

	GameObject(Game* game)
	{
		this->game = game;
	}
	~GameObject();

	Game* game;
	Vector2 position;
	bool* enabled = &isEnabled;
	void set_active(bool isActive) { isEnabled = isActive;};
	void destroy();
	void update();
	void render();
	void add_component(Component* component);

	template <typename T> T get_component() 
	{
		T component = nullptr;

		for (int i = 0; i < components.size(); i++)
		{
			if (typeid(components[i]) == typeid(T))
			{
				component = components[i];
			}
		}
		return component;
	};
	template <typename T> vector<T&> get_components() 
	{
		vector<T&> components = nullptr;

		for (int i = 0; i < components.size(); i++)
		{
			if (typeid(components[i]) == typeid(T))
			{
				components.push_back(components[i]);
			}
		}
		return components;
	};

private:
	
	bool isEnabled;
	std::vector<Component*> components;
};
