#pragma once
#include "SDL.h"


extern int keys[SDL_NUM_SCANCODES];

static class Input
{
public :
	static void set_key_down(int scanCode) { keys[scanCode] = true; };
	static void set_key_up(int scanCode) { keys[scanCode] = false; };
	static bool get_key(int scanCode) { return keys[scanCode]; }
};