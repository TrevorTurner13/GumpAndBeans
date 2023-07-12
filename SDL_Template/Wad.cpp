#include "Wad.h"
#include "BoxCollider.h"
#include "CircleCollider.h"
#include "PhysicsManager.h"

void Wad::WadMovement() {
	mMoveTime += mTimer->DeltaTime();
	if (mMoveTime >= mMoveTimeMax) {  // 3 seconds has passed
		mMoveDirection *= -1;  // reverse direction
		mMoveTime = 0.0f;  // reset timer
	}
	// move in the current direction
	Translate(mMoveDirection * Vec2_Up * mMoveSpeed * mTimer->DeltaTime(), World);
	Vector2 currentPos = Position();
	mWad = (mMoveDirection == 1) ? mWadDown : mWadUp;
	mWad->Position(currentPos);
}



Wad::Wad() {
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();
	mAudio = AudioManager::Instance();

	mWadUp = new AnimatedGLTexture("Wad.png", 0, 192, 64, 64, 1, 1.0f, Animation::Layouts::Horizontal);
	mWadDown = new AnimatedGLTexture("Wad.png", 0, 64, 64, 64, 1, 1.0f, Animation::Layouts::Horizontal);

	mWad= new AnimatedGLTexture("Wad.png", 0, 64, 64, 64, 1, 1.0f, Animation::Layouts::Horizontal);
	mWad->Parent(this);

	AddCollider(new CircleCollider(27.5f), true);
	
	mMoveSpeed = 100.0f;
	mMoveTime = 0.0f;
	mMoveTimeMax = 1.0f;
	mMoveDirection = 1;
}

Wad::~Wad() {
	mTimer = nullptr;
	mInput = nullptr;
	mAudio = nullptr;

	delete mWadDown;
	mWadDown = nullptr;

	delete mWadUp;
	mWadUp = nullptr;

}

void Wad::Update() {
	if (Active()) {
		WadMovement();
	}
	mWad->Update();
}

void Wad::Render() {
	mWad->Render();

	//PhysEntity::Render();
}

void Wad::SetMoveTimeMax(float change) {
	mMoveTimeMax = change;
}
