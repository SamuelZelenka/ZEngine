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

	bool on_collision();

	virtual void init() override;
	virtual bool check_collision(Collider* collider2, Collider* hitCollider);

	virtual bool check_vs_circle(AABBCollider* AABB, CircleCollider* Circle);
	virtual bool check_vs_AABB(AABBCollider* collider1, AABBCollider* collider2);
};

