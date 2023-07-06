#include "Gump.h"
#include "BoxCollider.h"
#include "CircleCollider.h"
#include "PhysicsManager.h"

void Gump::HandleMovement() {
	if (mInput->KeyDown(SDL_SCANCODE_D)) {
		Translate(Vec2_Right * mMoveSpeed * mTimer->DeltaTime(), World);
		mGump = mGumpRight;
	}
	if (mInput->KeyDown(SDL_SCANCODE_A)) {
		Translate(-Vec2_Right * mMoveSpeed * mTimer->DeltaTime(), World);
		mGump = mGumpLeft;
	}
	if (mInput->KeyDown(SDL_SCANCODE_W)) {
		Translate(-Vec2_Up * mMoveSpeed * mTimer->DeltaTime(), World);
		mGump = mGumpUp;
	}
	if (mInput->KeyDown(SDL_SCANCODE_S)) {
		Translate(Vec2_Up * mMoveSpeed * mTimer->DeltaTime(), World);
		mGump = mGumpDown;
	}

}

Gump::Gump() {

	mTimer = Timer::Instance();
	mInput = InputManager::Instance();
	mAudio = AudioManager::Instance();

	mGumpRight = new AnimatedGLTexture("Gump 128x128.png", 0, 0, 128, 128, 7, 1.0f, Animation::Layouts::Horizontal);
	mGumpLeft = new AnimatedGLTexture("Gump 128x128.png", 0, 256, 128, 128, 7, 1.0f, Animation::Layouts::Horizontal);
	mGumpUp = new AnimatedGLTexture("Gump 128x128.png", 0, 384, 128, 128, 7, 1.0f, Animation::Layouts::Horizontal);
	mGumpDown = new AnimatedGLTexture("Gump 128x128.png", 0, 128, 128, 128, 7, 1.0f, Animation::Layouts::Horizontal);
	mGump = new AnimatedGLTexture("Gump 128x128.png", 0, 0, 128, 128, 7, 1.0f, Animation::Layouts::Horizontal);
	
	mGump->Parent(this);
	mGumpRight->Parent(this);
	mGumpLeft->Parent(this);
	mGumpUp->Parent(this);
	mGumpDown->Parent(this);

	AddCollider(new BoxCollider(Vector2(40.0f, 40.0f)), Vector2(Local));
	//AddCollider(new CircleCollider(20.0f), true);

	mGumpVerticalStrength = 10;
	mGumpHorizontalStrength = 10;
	SetStrength(mGumpVerticalStrength, mGumpHorizontalStrength);

	mMoveSpeed = 300.0f;
	mMoveBounds = Vector2(0.0f, 800.0f);
}

Gump::~Gump() {
	mTimer = nullptr;
	mInput = nullptr;
	mAudio = nullptr;

	delete mGump;
	mGump = nullptr;
	delete mGumpRight;
	mGumpRight = nullptr;
	delete mGumpLeft;
	mGumpLeft = nullptr;
	delete mGumpUp;
	mGumpUp = nullptr;
	//delete mGumpDown;
	//mGumpDown = nullptr;
	
}

void Gump::Update() {
	if (Active()) {
		HandleMovement();
	}
	mGump->Update();
}

void Gump::Render() {
	mGump->Render();

	PhysEntity::Render();
}