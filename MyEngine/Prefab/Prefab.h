#pragma once

class Game;
class GameObject;
class Component;
class Vector2;

using namespace std;

class Prefab
{
public:
	Prefab() {};
	~Prefab() {};
	
	bool enabled;

	GameObject* construct(Game* game, Vector2 pos);
protected:
	virtual void construct_components(GameObject* object) { };
};