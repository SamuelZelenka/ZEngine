#pragma once
#include "../../Vector/Vector2.h"
#include "../../Components/Component.h"
#include "../../GameObject/GameObject.h"

class Collider : public Component
{
public :
	
	Collider(GameObject* gameObject, bool isStatic) : Component(gameObject) 
	{
		this->isStatic = isStatic;
	};

	~Collider() {};
	Vector2 position;
	bool isStatic;
	bool trigger;
	bool OnCollision();

	virtual void init() override;
	virtual bool CheckCollision(Collider* other) { return false; }
};

class AABBCollider : public Collider
{
public : 
	AABBCollider(GameObject* gameObject, Vector2 pos, int width, int height, bool isStatic) : Collider(gameObject, isStatic)
	{
		position = pos;
		this->width = width;
		this->height = height;
	}
	bool CheckCollision(Collider* other) override;
private :
	int width;
	int height;
};