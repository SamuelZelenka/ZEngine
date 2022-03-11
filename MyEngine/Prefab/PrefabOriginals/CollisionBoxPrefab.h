#pragma once
#include "../Prefab.h"

class GameObject;


class CollisionBoxPrefab : public Prefab
{
public:
	CollisionBoxPrefab() : Prefab() {};
	void construct_components(GameObject* object) override;
};

