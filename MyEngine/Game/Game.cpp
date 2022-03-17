#include "Game.h"
#include "../GameRenderer.h"
#include "../Input/Input.h"
#include "../GameObject/GameObject.h"
#include "../GameTime.h"
#include "../Physics/PhysicsManager.h"

#include "../Components/Component.h"

#include "../Prefab/Prefab.h"
#include "../Prefab/PrefabOriginals/PlayerScorePrefab.h"
#include "../Prefab/PrefabOriginals/BallPrefab.h"
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
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
	instantiate(new PlayerScorePrefab, { 0,0 });
	instantiate(new PlayerPrefab, { 400, 580 });


	for (int i = 0; i < windowWidth/60; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			instantiate(new BreakablePrefab, { 10 + (float)(60 * i), 10 + (float)(35 * j) });
		}
	}

	game_loop();
}

void Game::game_loop()
{
	awake();
	while (running())
	{
		gameTime->update_delta_time();
		handle_events();
		update();
		render();
	}
	clean();
}

void Game::handle_events()
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
void Game::awake()
{
	for (GameObject* object : gameObjects)
	{
		object->awake();
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
	for (Component* component : newObject->get_components<Component>())
	{
		component->init();
	}
	return newObject;
}

template <typename T> T* Game::find_with_component()
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		if (dynamic_cast<T*>(gameObjects[i]))
		{
			return (T*)gameObjects[i]->components[i];
		}
	}
	return nullptr;
}

void Game::add_score(int score)
{
	scoreTracker.add_score(score);
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
