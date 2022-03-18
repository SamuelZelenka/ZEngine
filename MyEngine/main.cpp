#include "Game/Game.h"
#include <stdio.h>
#include <string>


// PRESS SPACE TO SPAWN MORE BALLS
// PRESS A/D TO MOVE THE PLATFORM
int main(int argc, char* argv[])
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;
	const std::string title = "MyGame";

	Game game{ WINDOW_WIDTH, WINDOW_HEIGHT };

	game.init(&title[0], SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false);
	return 0;
}