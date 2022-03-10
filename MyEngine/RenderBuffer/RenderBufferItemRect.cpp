#include "../RenderBuffer/RenderBufferItem.h"
#include "../GameRenderer.h"

void RenderBufferItemRect::render()
{
	SDL_SetRenderDrawColor(renderer->scene, color.r, color.g, color.b, color.a);
	SDL_RenderFillRectF(renderer->scene, &rect);
	delete this;
}