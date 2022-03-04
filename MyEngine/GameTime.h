#pragma once
#include "SDL.h"
#include <iostream>

extern float deltatime;

class GameTime
{
public :
	
	GameTime() {};
	~GameTime() {};
	
	double time;
	float fps;

	float delta_time()
	{
		Uint64 ticks = SDL_GetPerformanceCounter();
		Uint64 deltaTicks = ticks - previousTick;
		previousTick = ticks;
		deltatime = (float)deltaTicks / SDL_GetPerformanceFrequency();
		fps = 1.0f / deltatime;
		cout << deltatime<<endl;
		return deltatime;
	}
private : 
	Uint64 startTick;
	Uint64 previousTick;
};
