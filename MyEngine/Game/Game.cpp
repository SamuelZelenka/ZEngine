#include "Game.h"
#include "../GameRenderer.h"
#include "../Input/Input.h"
#include "../Components/RectRenderer.h"
#include "../Components/PlayerMovement.h"
#include "../GameObject/GameObject.h"
#include "../GameTime.h"
#include "../Physics/PhysicsManager.h"
#include "../Physics/RigidBody.h"
#include "../Components/Colliders/Collider.h"

int keys[SDL_NUM_SCANCODES] = { 0 };
double delta_time = 0;

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

	//player object
	GameObject* player = new GameObject(this);
	player->position.Set(400,500);
	SDL_Color color = { 255,0,0,255 };
	RectRenderer* rectRendererComponent = new RectRenderer(player, 75, 25, color, 1);
	PlayerMovement* movementComponent = new PlayerMovement(player);
	RigidBody* rigidBody = new RigidBody(player);
	Collider* collider = new AABBCollider(player, player->position, 75,25, false);

	player->add_component(collider);
	player->add_component(rigidBody);
	player->add_component(movementComponent);
	player->add_component(rectRendererComponent);

	//Left bar object
	GameObject* leftBar = new GameObject(this);
	leftBar->position.Set(100, 0);
	SDL_Color leftBarColor = { 0,0,255,255 };
	RectRenderer* leftBarRenderer = new RectRenderer(leftBar, 25, 600, leftBarColor, 2);
	Collider* leftBarCollider = new AABBCollider(leftBar, leftBar->position, 25, 600, true);
	leftBar->add_component(leftBarCollider);
	leftBar->add_component(leftBarRenderer);

	// right bar object
	GameObject* rightBar = new GameObject(this);
	rightBar->position.Set(675, 0);
	RectRenderer* rightBarRenderer = new RectRenderer(rightBar, 25, 600, leftBarColor, 2);
	Collider* rightBarCollider = new AABBCollider(rightBar, rightBar->position, 25, 600, true);
	rightBar->add_component(rightBarCollider);
	rightBar->add_component(rightBarRenderer);

	instantiate(player);
	instantiate(leftBar);
	instantiate(rightBar);

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

