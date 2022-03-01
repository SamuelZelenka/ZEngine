#include "SDL.h"

class GameRenderer
{
public :
	GameRenderer(SDL_Window* window);
	~GameRenderer();

	void render();
	void clean();
	void render_rect(SDL_Rect* rect);
private:
	SDL_Renderer* scene = nullptr;
	SDL_Renderer* UI = nullptr;
	
};
