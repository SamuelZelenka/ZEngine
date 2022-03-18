#pragma once
#include "SDL.h"
#include <iostream>

extern double delta_time;

class GameTime
{
public :
	
	GameTime() {};
	~GameTime() {};
	
	double time;

	void update_delta_time()
	{
		currentTick = SDL_GetPerformanceCounter();
		deltaTicks = (currentTick - previousTick);
		previousTick = currentTick;
		delta_time = (double)(deltaTicks / (double)SDL_GetPerformanceFrequency());
	}
private : 
	Uint64 previousTick = 0;
	Uint64 currentTick = SDL_GetPerformanceCounter();
	Uint64 deltaTicks = 0;
};
