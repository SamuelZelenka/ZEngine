#pragma once
#include "../Prefab.h"

class GameObject;

class BallPrefab : public Prefab
{
public:

	BallPrefab() : Prefab() {};
	void construct_components(GameObject* object) override;
};

