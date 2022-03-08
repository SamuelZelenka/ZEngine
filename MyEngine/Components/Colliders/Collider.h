#pragma once
#include "../../Vector/Vector2.h"

class Collider
{
public :
	enum BodyType { Static, Dynamic};

	Collider(Vector2 pos, BodyType type);
	Vector2 position;
	BodyType bodyType;
	bool trigger;
	bool OnCollision();
	virtual bool CheckCollision(Collider other);
};

class AABBCollider : Collider
{
public : 

	AABBCollider(Vector2 pos, int width, int height, BodyType type) : Collider(pos, type)
	{
		position = pos;
		this->width = width;
		this->height = height;
	}
	bool CheckCollision(Collider other) override;
private :
	int width;
	int height;
};