#include "SDL.h"

namespace GameTime
{
	Uint64 startTick;
	Uint64 previousTick;
	double time;
	float fps;
	float deltatime;

	float delta_time()
	{
		Uint64 ticks = SDL_GetPerformanceCounter();
		Uint64 deltaTicks = ticks - previousTick;
		previousTick = ticks;
		deltatime = (float)deltaTicks / SDL_GetPerformanceFrequency();
		fps = 1.0f / deltatime;
		return deltatime;
	}
};
