#include "Game.h"
#include "../Components/RectRenderer.h"
#include "../GameTime.h"
#include "../Components/PlayerMovement.h"

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
	player->position.Set(25,25);
	SDL_Color color = { 255,0,0,255 };
	RectRenderer* rectRendererComponent = new RectRenderer(player, 25, 25, color, 1);
	PlayerMovement* movementComponent = new PlayerMovement(player);
	player->add_component(movementComponent);
	player->add_component(rectRendererComponent);

	GameObject* someObject = new GameObject(this);
	someObject->position.Set(0, 0);
	SDL_Color colorOther = { 0,0,255,255 };
	RectRenderer* newComponent = new RectRenderer(someObject, 25, 25, colorOther, 0);
	someObject->add_component(newComponent);	

	instantiate(player);
	instantiate(someObject);

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
		int scancode = sdlEvent.key.keysym.scancode;

		switch (sdlEvent.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			Input::keys[scancode] = true;
			break;
		case SDL_KEYUP:
			Input::keys[scancode] = false;
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

GameObject* Game::instantiate(GameObject* object)
{
	gameObjects.push_back(object);
	return object;
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	renderer->clean();
	cleanup_game_objects();
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}



void Game::cleanup_game_objects()
{
	for (GameObject* object : gameObjects)
	{
		delete object;
	}
}