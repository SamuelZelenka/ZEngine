#include "../Game/Game.h"
#include "../Vector/Vector2.h"
#include <vector>

class Component;

class GameObject
{
public:

	GameObject(Game game)
	{
		this->game = game;
	}
	~GameObject();

	Game game;
	Vector2 position;
	bool* enabled = &isEnabled;
	void set_active(bool isActive) { isEnabled = isActive;};
	void destroy();
	void update();
	void add_component(Component* component);

private:
	
	bool isEnabled;
	std::vector<Component*> components;
};
