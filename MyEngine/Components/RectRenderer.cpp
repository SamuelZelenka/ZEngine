#include "../GameObject/GameObject.h"
#include "../RenderBuffer/RenderBuffer.h"
#include "../RenderBuffer/RenderBufferItem.h"
#include "../Components/RectRenderer.h"

void RectRenderer::update()
{
	GameRenderer* renderer = gameObject->game->renderer;

	int posX = gameObject->position.x;
	int posY = gameObject->position.y;

	SDL_Rect rect = { posX, posY, width, height };
	RenderBufferItemRect* rectBufferItem = new RenderBufferItemRect(renderer, layer, &rect, color);

	renderer->renderBuffer->queue(rectBufferItem);
}