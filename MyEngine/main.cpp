#include "Game/Game.h"
#include <stdio.h>
#include <string>


Game *game = nullptr;


int main(int argc, char* argv[])
{
	const std::string title = "MyGame";
	game = new Game();

	game->init(&title[0], SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);


	return 0;
}