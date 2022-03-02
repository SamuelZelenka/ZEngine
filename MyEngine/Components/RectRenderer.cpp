#include "../Components/RectRenderer.h"
#include "../GameObject/GameObject.h"

RectRenderer::~RectRenderer()
{
}

void RectRenderer::update()
{
	SDL_Rect rect = { gameObject->position.x, gameObject->position.y, width, height };
	GameRenderer* renderer = gameObject->game->renderer;
	renderer->render_rect(&rect);
}