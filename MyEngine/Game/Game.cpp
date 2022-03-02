#include "Game.h"
#include "../Components/RectRenderer.h"
#include "../GameTime.h"

Game::Game()
{
	isRunning = false;
	renderer = nullptr;
	window = nullptr;
}

Game::~Game()
{

}

void Game::init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen)
{
	GameObject* player = new GameObject(this);
	RectRenderer* rectRendererComponent = new RectRenderer(player, 25,25);

	player->add_component(rectRendererComponent);
	instantiate(player);

	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		renderer = new GameRenderer(window);

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
}

void Game::handleEvents()
{
	SDL_Event sdlEvent;

	if (SDL_PollEvent(&sdlEvent))
	{
		switch (sdlEvent.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			int scancode = sdlEvent.key.keysym.scancode;
			if (scancode == SDL_SCANCODE_ESCAPE)
			{
				isRunning = false;
			}
			break;
		}
	}
}

void Game::update()
{
	GameTime::delta_time();
	for (GameObject* object : gameObjects)
	{
		object->update();
	}
}

void Game::render()
{
	renderer->render();
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	renderer->clean();
	cleanup_game_objects();
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}
void Game::instantiate(GameObject* object)
{
	gameObjects.push_back(object);
}
void Game::cleanup_game_objects()
{
	for (GameObject* object : gameObjects)
	{
		delete object;
	}
}