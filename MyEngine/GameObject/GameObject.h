#include "../Game/Game.h"

class GameObject
{
public:

	GameObject();
	~GameObject();

	bool enabled;
	void set_active(bool isActive) { isEnabled = isActive;};
	void update();
	void on_enable();
	void on_disable();
	void destroy();
	void render();

private:
	bool isEnabled;

};
