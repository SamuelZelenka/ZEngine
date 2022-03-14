#pragma once
#include "../../Vector/Vector2.h"
#include "../../Components/Component.h"
#include "../../GameObject/GameObject.h"

class AABBCollider;
class CircleCollider;

class Collider : public Component
{
	
public :
	enum class ColliderType { AABB = 1 << 0, Circle = 1 << 1 };

	Collider(GameObject* gameObject, bool isStatic) : Component(gameObject), isStatic(isStatic) {};
	~Collider() {};

	bool isStatic;

	Vector2 position;
	ColliderType colliderTypeID;

	bool OnCollision();

	virtual void init() override;

	static bool CheckCollision(Collider* collider1, Collider* collider2, Collider* hitCollider);
	static bool CheckAABBvsCircle(AABBCollider* AABB, CircleCollider* Circle);
	static bool CheckAABBvsAABB(AABBCollider* collider1, AABBCollider* collider2);
	static bool CheckCirclevsCircle(CircleCollider* collider1, CircleCollider* collider2);
};

