#pragma once
#include "SDL.h"


extern int keys[SDL_NUM_SCANCODES];

static class Input
{
public :
	static void setKeyDown(int scanCode) { keys[scanCode] = true; };
	static void setKeyUp(int scanCode) { keys[scanCode] = false; };
	static bool getKey(int scanCode) { return keys[scanCode]; }
};