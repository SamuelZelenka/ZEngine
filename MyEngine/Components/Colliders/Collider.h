#pragma once
class Collider
{
public :
	enum BodyType { Static, Dynamic};

	BodyType bodyType;
	bool trigger;
	bool OnCollision();
	virtual bool CheckCollision(Collider other);
};

class AABBCollider : Collider
{
public : 
	AABBCollider(int width, int height, BodyType type);
	bool CheckCollision(Collider other) override;
};