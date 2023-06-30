#ifndef __PHYSENTITY_H
#define __PHYSENTITY_H
#include <vector>
#include "Collider.h"

class PhysEntity : public GameEntity {
protected:
	unsigned long mId;

	std::vector<Collider *> mColliders;

	Collider * mBroadPhaseCollider;

	void AddCollider(Collider * collider, Vector2 localPos = Vec2_Zero);

	virtual bool IgnoreCollisions();

	int mStrength;

public:
	PhysEntity();
	virtual ~PhysEntity();

	unsigned long GetId();

	bool CheckCollision(PhysEntity * other);
	bool VerticallyAligned(PhysEntity* other);
	bool HorizontallyAligned(PhysEntity* other);
	void ResolveCollision(PhysEntity* first, PhysEntity* other);
	void HandleCollision(PhysEntity* first, PhysEntity* other);

	void SetStrength(int strength);
	int GetStrength() { return mStrength; }

	virtual void Hit(PhysEntity * other) { }

	virtual void Render() override;
};
#endif