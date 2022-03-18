#pragma once
#include "SDL.h"
#include "../Vector/Vector2.h"

class GameRenderer;
class Vector2;

class RenderBufferItem
{
public :
	RenderBufferItem(GameRenderer* renderer, Uint8 layer) 
	{
		this->renderer = renderer;
		this->layer = layer;
	};
	~RenderBufferItem() {};
	
	Uint8 layer;
	virtual void render() {};

protected :
	GameRenderer* renderer;
};

