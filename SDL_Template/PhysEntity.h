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

	int mVerticalStrength;
	int mHorizontalStrength;

public:
	PhysEntity();
	virtual ~PhysEntity();

	unsigned long GetId();

	bool CheckCollision(PhysEntity * other);
	bool VerticallyAligned(PhysEntity* other);
	bool HorizontallyAligned(PhysEntity* other);
	void ResolveCollision(PhysEntity* first, PhysEntity* other);
	void ResolveVerticalPushCollision(PhysEntity* other);
	void ResolveHorizontalPushCollision(PhysEntity* other);
	void HandleCollision(PhysEntity* first, PhysEntity* other);

	void SetStrength(int vertStrength, int horizStrength);
	int GetVerticalStrength() { return mVerticalStrength; }
	int GetHorizontalStrength() { return mHorizontalStrength; }

	virtual void Hit(PhysEntity * other) { }

	virtual void Render() override;
};
#endif