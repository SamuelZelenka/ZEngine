#include "Component.h"
#include "../SDL2/include/SDL.h"

class RectRenderer : Component
{
public :

	RectRenderer(GameObject* gameObject, double width, double height) : Component(gameObject)
	{
		this->gameObject = gameObject;
		this->width = width;
		this->height = height;
	}
	~RectRenderer();

	void update() override
	{
		SDL_Rect rect = { gameObject->position.x, gameObject->position.y, width, height };
		GameRenderer* renderer = (*gameObject).game.renderer;
		renderer->render_rect(&rect);
	}
private:
	GameObject* gameObject;
	double width;
	double height;
};