#pragma once
#include <vector>
#include "../Vector/Vector2.h"

class Game;
class Component;

using namespace std;

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

	template <typename T> T* get_component() 
	{
		for (int i = 0; i < components.size(); i++)
		{
			if (dynamic_cast<T*>(components[i]))
			{
				return (T*)components[i];
			}
		}
		return nullptr;
	};

	template <typename T> vector<T*> get_components() 
	{
		vector<T*> foundComponents;

		for (int i = 0; i < components.size(); i++)
		{
			if (dynamic_cast<T*>(components[i]))
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
