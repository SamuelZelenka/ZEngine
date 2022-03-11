#pragma once
#include <vector>
#include "../Vector/Vector2.h"

class Game;
class GameObject;
class Component;

using namespace std;

class Prefab
{
public:
	Prefab() {};
	~Prefab() {};
	GameObject* construct(Game* game, Vector2 pos);
protected:
	virtual void construct_components(GameObject* object) { };
};