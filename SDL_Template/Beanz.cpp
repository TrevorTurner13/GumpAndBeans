#include "Beanz.h"
#include "BoxCollider.h"
#include "CircleCollider.h"
#include "PhysicsManager.h"

void Beanz::HandleMovement() {
	if (mInput->KeyDown(SDL_SCANCODE_RIGHT)) {
		Translate(Vec2_Right * mMoveSpeed * mTimer->DeltaTime(), World);
		Vector2 currentPos = Position();
		mBeanz = mBeanzRight;
		mBeanz->Position(currentPos);
	}
	if (mInput->KeyDown(SDL_SCANCODE_LEFT)) {
		Translate(-Vec2_Right * mMoveSpeed * mTimer->DeltaTime(), World);
		Vector2 currentPos = Position();
		mBeanz = mBeanzLeft;
		mBeanz->Position(currentPos);
	}
	if (mInput->KeyDown(SDL_SCANCODE_UP)) {
		Translate(-Vec2_Up * mMoveSpeed * mTimer->DeltaTime(), World);
		Vector2 currentPos = Position();
		mBeanz = mBeanzUp;
		mBeanz->Position(currentPos);
	}
	if (mInput->KeyDown(SDL_SCANCODE_DOWN)) {
		Translate(Vec2_Up * mMoveSpeed * mTimer->DeltaTime(), World);
		Vector2 currentPos = Position();
		mBeanz = mBeanzDown;
		mBeanz->Position(currentPos);
	}
	Vector2 pos = Position(Local);
	Position(pos);
}

Beanz::Beanz() {
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();
	mAudio = AudioManager::Instance();

	mBeanzRight = new AnimatedGLTexture("Beanz 128x128.png", 0, 0, 128, 128, 1, 1.0f, Animation::Layouts::Horizontal);
	mBeanzLeft = new AnimatedGLTexture("Beanz 128x128.png", 0, 256, 128, 128, 1, 1.0f, Animation::Layouts::Horizontal);
	mBeanzUp = new AnimatedGLTexture("Beanz 128x128.png", 0, 384, 128, 128, 1, 1.0f, Animation::Layouts::Horizontal);
	mBeanzDown = new AnimatedGLTexture("Beanz 128x128.png", 0, 128, 128, 128, 1, 1.0f, Animation::Layouts::Horizontal);
	mBeanz = new AnimatedGLTexture("Beanz 128x128.png", 0, 0, 128, 128, 1, 1.0f, Animation::Layouts::Horizontal);

	mBeanz->Parent(this);

	//AddCollider(new CircleCollider(50.0f), false);
	AddCollider(new BoxCollider(Vector2(50.0f, 128.0f)), Vector2(Local));

	//mBeanz->Position(Local);

	mMoveSpeed = 200.0f;
	mMoveBounds = Vector2(0.0f, 800.0f);
}

Beanz::~Beanz() {
	mTimer = nullptr;
	mInput = nullptr;
	mAudio = nullptr;

	delete mBeanz;
	mBeanz = nullptr;
	delete mBeanzRight;
	mBeanzRight = nullptr;
	delete mBeanzLeft;
	mBeanzLeft = nullptr;
	delete mBeanzUp;
	mBeanzUp = nullptr;
	delete mBeanzDown;
	mBeanzDown = nullptr;
}

void Beanz::Update() {
	if (Active()) {
		HandleMovement();
	}

	mBeanz->Update();
}

void Beanz::Render() {
	mBeanz->Render();

	PhysEntity::Render();
}