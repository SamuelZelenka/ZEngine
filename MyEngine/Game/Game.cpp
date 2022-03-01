#include <iostream>
#include "Game.h"
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
}

void Game::render()
{
	renderer->render();
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	renderer->clean();
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;

}