#include "../GameObject/GameObject.h"
#include "../RenderBuffer/RenderBuffer.h"
#include "../RenderBuffer/RenderBufferItem.h"
#include "../Components/RectRenderer.h"
#include "../GameRenderer.h"
#include "../Game/Game.H"

void RectRenderer::update()
{
	GameRenderer* renderer = gameObject->game->renderer;

	float posX = gameObject->position.x;
	float posY = gameObject->position.y;

	SDL_FRect rect = { posX, posY, width, height };
	RenderBufferItemRect* rectBufferItem = new RenderBufferItemRect(renderer, layer, &rect, color);

	renderer->renderBuffer->queue(rectBufferItem);
}