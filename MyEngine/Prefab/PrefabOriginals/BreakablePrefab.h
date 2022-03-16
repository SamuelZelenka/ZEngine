#pragma once
#include "../Prefab.h"


class BreakablePrefab : public Prefab
{
public: 
	BreakablePrefab() : Prefab() {};
	void construct_components(GameObject* object) override;
};