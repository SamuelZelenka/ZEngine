#pragma once
#include "../../Vector/Vector2.h"
#include "../../Components/Component.h"

class SDL_FRect;
class AABBCollider;

class Collider : public Component
{
	
public :
	enum class ColliderType { AABB = 1 << 0, Circle = 1 << 1 };

	Collider(GameObject* gameObject, bool isStatic) : Component(gameObject), isStatic(isStatic) {};
	~Collider() {};

	bool isStatic;

	Vector2 position;
	ColliderType colliderType;

	bool on_collision();

	virtual void init() override;

	virtual bool check_collision(Collider* collider2, CollisionInfo& hitCollider) { return false; };

	virtual bool check_vs_AABB(AABBCollider& other, CollisionInfo& collisionInfo) { return false; };
};

