#include "PhysEntity.h"
#include "PhysicsHelper.h"
#include "PhysicsManager.h"

void PhysEntity::AddCollider(Collider * collider, Vector2 localPos) {
	collider->Parent(this);
	collider->Position(localPos);
	mColliders.push_back(collider);

	if (mColliders.size() > 1 || mColliders[0]->GetType() != Collider::ColliderType::Circle) {
		float furthestDistance = mColliders[0]->GetFurthestPoint().Magnitude();
		float dist = 0.0f;

		for (int i = 1; i < mColliders.size(); i++) {
			dist = mColliders[i]->GetFurthestPoint().Magnitude();

			if (dist > furthestDistance) {
				furthestDistance = dist;
			}
		}

		delete mBroadPhaseCollider;
		mBroadPhaseCollider = new CircleCollider(furthestDistance, true);
		mBroadPhaseCollider->Parent(this);
		mBroadPhaseCollider->Position(Vec2_Zero);
	}
}

bool PhysEntity::IgnoreCollisions() {
	return false;
}

void PhysEntity::SetStrength(int vertStrength, int horizStrength) {
	mVerticalStrength = vertStrength;
	mHorizontalStrength = horizStrength;
}

PhysEntity::PhysEntity() {
	mBroadPhaseCollider = nullptr;
	mId = 0;
	mVerticalStrength = 0;
	mHorizontalStrength = 0;
}

PhysEntity::~PhysEntity() {
	for (auto c : mColliders) {
		delete c;
	}
	mColliders.clear();

	delete mBroadPhaseCollider;

	if (mId != 0) {
		PhysicsManager::Instance()->UnregisterEntity(mId);
	}
}

unsigned long PhysEntity::GetId() {
	return mId;
}

bool PhysEntity::CheckCollision(PhysEntity * other) {
	if (IgnoreCollisions() || other->IgnoreCollisions()) {
		return false;
	}

	bool narrowPhaseCheck = false;

	if (mBroadPhaseCollider && other->mBroadPhaseCollider) {
		narrowPhaseCheck = ColliderVsColliderCheck(mBroadPhaseCollider, other->mBroadPhaseCollider);
	}
	else {
		narrowPhaseCheck = true;
	}
	
	if (narrowPhaseCheck) {
		for (int i = 0; i < mColliders.size(); i++) {
			for (int j = 0; j < other->mColliders.size(); j++) {
				if (ColliderVsColliderCheck(mColliders[i], other->mColliders[j])) {
					return true;
				}
			}
		}
	}

	return false;
}

bool PhysEntity::VerticallyAligned(PhysEntity* other) {
	float offset = 10.0f;
	if (IgnoreCollisions() || other->IgnoreCollisions()) {
		return false;
	}

	bool narrowPhaseCheck = false;

	if (mBroadPhaseCollider && other->mBroadPhaseCollider) {
		narrowPhaseCheck = ColliderVsColliderCheck(mBroadPhaseCollider, other->mBroadPhaseCollider);
	}
	else {
		narrowPhaseCheck = true;
	}

	if (narrowPhaseCheck) {
		for (int i = 0; i < mColliders.size(); i++) {
			for (int j = 0; j < other->mColliders.size(); j++) {
				
					float playerTop = mColliders[i]->Position().y - mColliders[i]->GetDimensions().y / 2 + offset;
					float playerBottom = mColliders[i]->Position().y + mColliders[i]->GetDimensions().y / 2 - offset;
					float objectTop = other->mColliders[j]->Position().y - other->mColliders[j]->GetDimensions().y / 2 + offset;
					float objectBottom = other->mColliders[j]->Position().y + other->mColliders[j]->GetDimensions().y / 2 - offset;
					if (playerBottom > objectTop && playerTop < objectBottom) {
						return true;
					}
					else {
						return false;
					}
				}
			
		}
	}
	return false;
}

bool PhysEntity::HorizontallyAligned(PhysEntity* other) {
	float offset = 10.0f;
	if (IgnoreCollisions() || other->IgnoreCollisions()) {
		return false;
	}

	bool narrowPhaseCheck = false;

	if (mBroadPhaseCollider && other->mBroadPhaseCollider) {
		narrowPhaseCheck = ColliderVsColliderCheck(mBroadPhaseCollider, other->mBroadPhaseCollider);
	}
	else {
		narrowPhaseCheck = true;
	}

	if (narrowPhaseCheck) {
		for (int i = 0; i < mColliders.size(); i++) {
			for (int j = 0; j < other->mColliders.size(); j++) {
				
				float playerLeft = mColliders[i]->Position().x - mColliders[i]->GetDimensions().x / 2 + offset;
				float playerRight = mColliders[i]->Position().x + mColliders[i]->GetDimensions().x / 2 - offset;
				float objectLeft = other->mColliders[j]->Position().x - other->mColliders[j]->GetDimensions().x / 2 + offset;
				float objectRight = other->mColliders[j]->Position().x + other->mColliders[j]->GetDimensions().x / 2 - offset;
				
				if (playerLeft < objectRight && playerRight > objectLeft) {
					return true;
					}
				else {
					return false;
				}
			}
		}
	}
	return false;
}

void PhysEntity::ResolveHorizontalPushCollision(PhysEntity* other) {
	for (int i = 0; i < mColliders.size(); i++) {
		for (int j = 0; j < other->mColliders.size(); j++) {

			if (VerticallyAligned(other)) {
				if (mColliders[i]->Position().x < other->mColliders[j]->Position().x) {
					float pushback = (mColliders[i]->Position().x + mColliders[i]->GetDimensions().x / 2) - (other->mColliders[j]->Position().x - other->mColliders[j]->GetDimensions().x / 2);
					Position(Position().x - pushback, Position().y);
				}
				else {
					float pushback = (other->mColliders[j]->Position().x + other->mColliders[j]->GetDimensions().x / 2) - (mColliders[i]->Position().x - mColliders[i]->GetDimensions().x / 2);
					Position(Position().x + pushback, Position().y);
				}
			}
		}
	}
}

void PhysEntity::ResolveVerticalPushCollision(PhysEntity* other) {
	for (int i = 0; i < mColliders.size(); i++) {
		for (int j = 0; j < other->mColliders.size(); j++) {
			if (HorizontallyAligned(other)) {
				if (mColliders[i]->Position().y < other->mColliders[j]->Position().y) {
					float pushback = (mColliders[i]->Position().y + mColliders[i]->GetDimensions().y / 2) - (other->mColliders[j]->Position().y - other->mColliders[i]->GetDimensions().y / 2);
					Position(Position().x, Position().y - pushback);
				}
				else {
					float pushback = (other->mColliders[j]->Position().y + other->mColliders[j]->GetDimensions().y / 2) - (mColliders[i]->Position().y - mColliders[i]->GetDimensions().y / 2);
					Position(Position().x, Position().y + pushback);
				}
			}
		}
	}
}

void PhysEntity::ResolveCollision(PhysEntity* first, PhysEntity* other) {
	if (GetHorizontalStrength() > other->GetHorizontalStrength() && GetVerticalStrength() < other->GetVerticalStrength()) {
		other->ResolveHorizontalPushCollision(first);
		ResolveVerticalPushCollision(other);
	}
	else if (GetVerticalStrength() > other->GetVerticalStrength() && GetHorizontalStrength() < other->GetHorizontalStrength()) {
		other->ResolveVerticalPushCollision(first);
		ResolveHorizontalPushCollision(other);
	}
	else if (GetVerticalStrength() > other->GetVerticalStrength() && GetHorizontalStrength() > other->GetHorizontalStrength()) {
		other->ResolveCollision(other, first);
	}
	else {
		for (int i = 0; i < mColliders.size(); i++) {
			for (int j = 0; j < other->mColliders.size(); j++) {

				if (VerticallyAligned(other)) {
					if (mColliders[i]->Position().x < other->mColliders[j]->Position().x) {
						float pushback = (mColliders[i]->Position().x + mColliders[i]->GetDimensions().x / 2) - (other->mColliders[j]->Position().x - other->mColliders[j]->GetDimensions().x / 2);
						Position(Position().x - pushback, Position().y);
					}
					else {
						float pushback = (other->mColliders[j]->Position().x + other->mColliders[j]->GetDimensions().x / 2) - (mColliders[i]->Position().x - mColliders[i]->GetDimensions().x / 2);
						Position(Position().x + pushback, Position().y);
					}
				}
				if (HorizontallyAligned(other)) {
					if (mColliders[i]->Position().y < other->mColliders[j]->Position().y) {
						float pushback = (mColliders[i]->Position().y + mColliders[i]->GetDimensions().y / 2) - (other->mColliders[j]->Position().y - other->mColliders[i]->GetDimensions().y / 2);
						Position(Position().x, Position().y - pushback);
					}
					else {
						float pushback = (other->mColliders[j]->Position().y + other->mColliders[j]->GetDimensions().y / 2) - (mColliders[i]->Position().y - mColliders[i]->GetDimensions().y / 2);
						Position(Position().x, Position().y + pushback);
					}
				}
			}
		}
	}
}


void PhysEntity::HandleCollision(PhysEntity* first, PhysEntity* other) {
	if (CheckCollision(other)) {
		ResolveCollision(first, other);
	}
}

void PhysEntity::Render() {
	for (auto c : mColliders) {
		c->Render();
	}

	if (mBroadPhaseCollider) {
		mBroadPhaseCollider->Render();
	}
}
