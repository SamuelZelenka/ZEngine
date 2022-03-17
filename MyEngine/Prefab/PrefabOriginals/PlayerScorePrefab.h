#pragma once
#include "../Prefab.h"

class GameObject;

class PlayerScorePrefab : public Prefab
{
public:
	PlayerScorePrefab() : Prefab() {};
	void construct_components(GameObject* object) override;
};
