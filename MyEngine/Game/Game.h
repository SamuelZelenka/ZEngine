#pragma once
#include <vector>
#include <iostream>
#include "SDL.h"
#include "../GameRenderer.h"
#include "../GameObject/GameObject.h"

using namespace std;

class GameObject;

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
	void cleanup_game_objects();
	GameObject* instantiate(GameObject* object);

private:

	bool isRunning;
	SDL_Window* window;
	vector<GameObject*> gameObjects;
};