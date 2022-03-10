#pragma once
#include <concepts>
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
	template <typename T> vector<T*> get_components() 
	{
		vector<T*> foundComponents;

		for (int i = 0; i < components.size(); i++)
		{
			cout << "Component: " << typeid(*components[i]).name() << std::endl;
			cout << "T: " << typeid(T).name() << std::endl;
			if ((T) == typeid(*components[i]) || std:derived_from<T,decltype(*components[i])>())
			{
				T* matchingComponent = (T*)components[i];
				foundComponents.push_back(matchingComponent);
			}
		}
		return foundComponents;
	};

private:
	
	bool isEnabled;
	std::vector<Component*> components;
};
