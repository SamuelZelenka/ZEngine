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

private:
	
	bool isEnabled;
	std::vector<Component*> components;
};
