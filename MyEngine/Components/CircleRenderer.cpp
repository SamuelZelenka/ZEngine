#include "../GameObject/GameObject.h"
#include "../RenderBuffer/RenderBuffer.h"
#include "../RenderBuffer/RenderBufferItem.h"
#include "../Components/CircleRenderer.h"
#include "../GameRenderer/GameRenderer.h"
#include "../Game/Game.H"

void CircleRenderer::update()
{
	GameRenderer* renderer = gameObject->game->renderer;

	RenderBufferItemCircle* rectBufferItem = new RenderBufferItemCircle(renderer, layer, gameObject->position, radius, color);

	renderer->renderBuffer->queue(rectBufferItem);
}