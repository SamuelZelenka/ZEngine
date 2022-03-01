#include "SDL.h"
#include "../GameRenderer.h"

class Game
{
public:
	Game();
	~Game();

	GameRenderer* renderer;

	void init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();
	bool running() { return isRunning; };

private:

	bool isRunning;
	SDL_Window* window;
};