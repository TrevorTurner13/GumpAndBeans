#include "Rumpff.h"
#include "BoxCollider.h"
#include "CircleCollider.h"
#include "PhysicsManager.h"


void Rumpff::RumpffMovement() {
	mMoveTime += mTimer->DeltaTime();
	if (mMoveTime >= 5.0f) {  // 5 seconds has passed
		mMoveDirection *= -1;  // reverse direction
		mMoveTime = 0.0f;  // reset timer
	}
	// move in the current direction
	Translate(mMoveDirection * Vec2_Right * mMoveSpeed * mTimer->DeltaTime(), World);
	Vector2 currentPos = Position();
	mRumpff = (mMoveDirection == 1) ? mRumpffRight : mRumpffLeft;
	mRumpff->Position(currentPos);
}


Rumpff::Rumpff() {
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();
	mAudio = AudioManager::Instance();

	mRumpffLeft = new AnimatedGLTexture("Rumpff.png", 0, 0, 160, 160, 1, 1.0f, Animation::Layouts::Horizontal);
	mRumpffRight = new AnimatedGLTexture("Rumpff.png", 0, 320, 160, 160, 1, 1.0f, Animation::Layouts::Horizontal);

	mRumpff = new AnimatedGLTexture("Rumpff.png", 0, 320, 160, 160, 1, 1.0f, Animation::Layouts::Horizontal);
	mRumpff->Parent(this);

	AddCollider(new BoxCollider(Vector2(100.0f,175.0f)), Vector2(Local));

	mMoveSpeed = 65.0f;
	mMoveTime = 0.0f;
	mMoveDirection = 1;
}

Rumpff::~Rumpff() {
	mTimer = nullptr;
	mInput = nullptr;
	mAudio = nullptr;

	delete mRumpffLeft;
	mRumpffLeft = nullptr;

	delete mRumpffRight;
	mRumpffRight = nullptr;
}

void Rumpff::Update() {
	if (Active()) {
		RumpffMovement();
	}
	mRumpff->Update();
}

void Rumpff::Render() {
	mRumpff->Render();

	PhysEntity::Render();
}