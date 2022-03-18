#pragma once
#include "../RenderBuffer/RenderBufferItem.h"

class RenderBufferItemRect : public RenderBufferItem
{
public:
	RenderBufferItemRect(GameRenderer* renderer, Uint8 layer, const SDL_FRect* rect, SDL_Color color) : RenderBufferItem(renderer, layer)
	{
		this->rect = *rect;
		this->color = color;
	}
	void render() override;
private:
	SDL_FRect rect;
	SDL_Color color;
};