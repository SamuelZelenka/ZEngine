#pragma once
#include <vector>
#include <iostream>
#include "SDL.h"
#include "../Vector/Vector2.h"
#include "ScoreTracker.h"

using namespace std;

class GameObject;
class GameRenderer;
class GameTime;
class PhysicsManager;
class Prefab;

class Game
{
public:
	Game(int width, int height);
	~Game();

	int windowWidth;
	int windowHeight;

	GameRenderer* renderer;
	PhysicsManager* physicsManager;

	ScoreTracker scoreTracker;



	void init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);

	void handle_events();
	void awake();
	void update();
	void render();
	void clean();
	bool running() { return isRunning; };
	void game_loop();
	void cleanup_game_objects();

	void add_score(int score);

	GameObject* instantiate(Prefab* prefab, Vector2 pos);

	template <typename T> T* find_with_component();
	vector<GameObject*> gameObjects;
private:

	bool isRunning;

	

	SDL_Window* window;
	
	GameTime* gameTime;
};