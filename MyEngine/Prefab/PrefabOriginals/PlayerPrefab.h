#pragma once
#include "../Prefab.h"

class GameObject;

class PlayerPrefab : public Prefab
{
public :
	PlayerPrefab() : Prefab() {};
	void construct_components(GameObject* object) override;
};
