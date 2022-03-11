#pragma once
#include "../Prefab.h"

class GameObject;


class Ball : public Prefab
{
public:
	Ball() : Prefab() {};
	void construct_components(GameObject* object) override;
};

