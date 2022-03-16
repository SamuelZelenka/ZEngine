#include "Game.h"
#include "../GameRenderer.h"
#include "../Input/Input.h"
#include "../GameObject/GameObject.h"
#include "../GameTime.h"
#include "../Physics/PhysicsManager.h"

#include "../Components/Component.h"

#include "../Prefab/Prefab.h"
#include "../Prefab/PrefabOriginals/Ball.h"
#include "../Prefab/PrefabOriginals/PlayerPrefab.h"
#include "../Prefab/PrefabOriginals/CollisionBoxPrefab.h"
#include "../Prefab/PrefabOriginals/BreakablePrefab.h"

int keys[SDL_NUM_SCANCODES] = { 0 };
double delta_time = 0;

Game::Game(int width, int height)
{
	windowWidth = width;
	windowHeight = height;
	isRunning = false;
	renderer = nullptr;
	window = nullptr;
}

Game::~Game()
{
	
}

void Game::init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen)
{
	instantiate(new Ball(), { 450, 450 });
	instantiate(new PlayerPrefab(), {400, 500});
	instantiate(new CollisionBoxPrefab(), { 100, 0 });
	instantiate(new CollisionBoxPrefab(), { 700, 0 });
	instantiate(new BreakablePrefab, { 100, 100 });
	instantiate(new BreakablePrefab, { 160, 100 });
	instantiate(new BreakablePrefab, { 220, 320 });
	instantiate(new BreakablePrefab, { 280, 300 });
	instantiate(new BreakablePrefab, { 340, 200 });
	instantiate(new BreakablePrefab, { 400, 100 });
	instantiate(new BreakablePrefab, { 460, 160 });
	instantiate(new BreakablePrefab, { 520, 120 });

	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		renderer = new GameRenderer(window);
		gameTime = new GameTime();
		physicsManager = new PhysicsManager();
		for (GameObject* gameObject : gameObjects)
		{
			for (Component* component : gameObject->get_components<Component>())
			{
				component->init();
			}
		}
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
	gameLoop();
}

void Game::gameLoop()
{
	while (running())
	{
		gameTime->update_delta_time();
		handleEvents();
		update();
		render();
		
	}
	clean();
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
			Input::setKeyDown(scancode);
			break;
		case SDL_KEYUP:
			Input::setKeyUp(scancode);
			break;
		}
	}
}

void Game::update()
{
	for (GameObject* object : gameObjects)
	{
		object->update();
	}
}

void Game::render()
{
	renderer->render();
}

GameObject* Game::instantiate(Prefab* prefab, Vector2 pos)
{
	GameObject* newObject = prefab->construct(this, pos);
	delete prefab;
	gameObjects.push_back(newObject);
	return newObject;
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	renderer->clean();
	cleanup_game_objects();
	delete gameTime;
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
