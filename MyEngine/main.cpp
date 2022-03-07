#include "Game/Game.h"
#include <stdio.h>
#include <string>



Game *game = nullptr;

int main(int argc, char* argv[])
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	const std::string title = "MyGame";
	game = new Game();

	game->init(&title[0], SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false);


	return 0;
}