#include "Player.h"
#include "BoxCollider.h"
#include "PhysicsManager.h"

void Player::HandleMovement() {
	if (mInput->KeyDown(SDL_SCANCODE_D)) {
		mGump->Translate(Vec2_Right * mMoveSpeed * mTimer->DeltaTime(), World);
		Vector2 currentPos = mGump->Position();
		mGump = mGumpRight;
		mGump->Position(currentPos);
	}
	 if (mInput->KeyDown(SDL_SCANCODE_A)) {
		mGump->Translate(-Vec2_Right * mMoveSpeed * mTimer->DeltaTime(), World);
		Vector2 currentPos = mGump->Position();
		mGump = mGumpLeft;
		mGump->Position(currentPos);
	}
	 if (mInput->KeyDown(SDL_SCANCODE_W)) {
		mGump->Translate(-Vec2_Up * mMoveSpeed * mTimer->DeltaTime(), World);
		Vector2 currentPos = mGump->Position();
		mGump = mGumpUp;
		mGump->Position(currentPos);
	}
	 if (mInput->KeyDown(SDL_SCANCODE_S)) {
		mGump->Translate(Vec2_Up * mMoveSpeed * mTimer->DeltaTime(), World);
		Vector2 currentPos = mGump->Position();
		mGump = mGumpDown;
		mGump->Position(currentPos);
	}
	 if (mInput->KeyDown(SDL_SCANCODE_RIGHT)) {
		 mBeanz->Translate(Vec2_Right * mMoveSpeed * mTimer->DeltaTime(), World);
		 Vector2 currentPos = mBeanz->Position();
		 mBeanz = mBeanzRight;
		 mBeanz->Position(currentPos);
	 }
	 if (mInput->KeyDown(SDL_SCANCODE_LEFT)) {
		 mBeanz->Translate(-Vec2_Right * mMoveSpeed * mTimer->DeltaTime(), World);
		 Vector2 currentPos = mBeanz->Position();
		 mBeanz = mBeanzLeft;
		 mBeanz->Position(currentPos);
	 }
	 if (mInput->KeyDown(SDL_SCANCODE_UP)) {
		 mBeanz->Translate(-Vec2_Up * mMoveSpeed * mTimer->DeltaTime(), World);
		 Vector2 currentPos = mBeanz->Position();
		 mBeanz = mBeanzUp;
		 mBeanz->Position(currentPos);
	 }
	 if (mInput->KeyDown(SDL_SCANCODE_DOWN)) {
		 mBeanz->Translate(Vec2_Up * mMoveSpeed * mTimer->DeltaTime(), World);
		 Vector2 currentPos = mBeanz->Position();
		 mBeanz = mBeanzDown;
		 mBeanz->Position(currentPos);
	 }
	Vector2 pos = Position(Local);
	Position(pos);
}

void Player::HandleFiring() {
	if (mInput->KeyPressed(SDL_SCANCODE_SPACE)) {
		/*for (int i = 0; i < MAX_BULLETS; ++i) {
			if (!mBullets[i]->Active()) {
				mBullets[i]->Fire(Position());
				mAudio->PlaySFX("SFX/Fire.wav");
				break;
			}
		}*/
	}
}

Player::Player() {
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();
	mAudio = AudioManager::Instance();

	mVisible = false;
	mAnimating = false;
	mWasHit = false;

	mScore = 0;
	mLives = 2;

	mGumpRight = new AnimatedGLTexture ("Gump 128x128.png", 0, 0, 128, 128,7,1.0f, Animation::Layouts::Horizontal);
	mGumpLeft = new AnimatedGLTexture("Gump 128x128.png", 0, 256, 128, 128, 7, 1.0f, Animation::Layouts::Horizontal);
	mGumpUp =   new AnimatedGLTexture ("Gump 128x128.png", 0, 384, 128, 128, 7, 1.0f, Animation::Layouts::Horizontal);
	mGumpDown = new AnimatedGLTexture ("Gump 128x128.png", 0, 128, 128, 128, 7, 1.0f, Animation::Layouts::Horizontal);
	mGump = new GLTexture("Gump 128x128.png", 0, 0, 128, 128);
	
	mGump->Position(Vec2_Zero);

	mBeanzRight = new AnimatedGLTexture("Beanz 128x128.png", 0, 0, 128, 128, 1, 1.0f, Animation::Layouts::Horizontal);
	mBeanzLeft = new AnimatedGLTexture("Beanz 128x128.png", 0, 256, 128, 128, 1, 1.0f, Animation::Layouts::Horizontal);
	mBeanzUp = new AnimatedGLTexture("Beanz 128x128.png", 0, 384, 128, 128, 1, 1.0f, Animation::Layouts::Horizontal);
	mBeanzDown = new AnimatedGLTexture("Beanz 128x128.png", 0, 128, 128, 128, 1, 1.0f, Animation::Layouts::Horizontal);
	mBeanz = new GLTexture("Beanz.png", 0, 0, 128, 128);
	
	mBeanz->Position(100, 100);


	mMoveSpeed = 300.0f;
	mMoveBounds = Vector2(0.0f, 800.0f);

	mDeathAnimation = new AnimatedGLTexture("PlayerExplosion.png", 0, 0, 128, 128, 4, 1.0f, Animation::Layouts::Horizontal);
	mDeathAnimation->Parent(this);
	mDeathAnimation->Position(Vec2_Zero);
	mDeathAnimation->SetWrapMode(Animation::WrapModes::Once);

	/*for (int i = 0; i < MAX_BULLETS; ++i) {
		mBullets[i] = new Bullet(true);
	}*/

	AddCollider(new BoxCollider(Vector2(16.0f, 67.0f)));
	AddCollider(new BoxCollider(Vector2(20.0f, 37.0f)), Vector2(18.0f, 10.0f));
	AddCollider(new BoxCollider(Vector2(20.0f, 37.0f)), Vector2(-18.0f, 10.0f));

	mId = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Friendly);

	Visible(true);
}

Player::~Player() {
	mTimer = nullptr;
	mInput = nullptr;
	mAudio = nullptr;

	delete mGump;
	mGump = nullptr;

	delete mBeanz;
	mBeanz = nullptr;

	delete mDeathAnimation;
	mDeathAnimation = nullptr;

	/*for (auto b : mBullets) {
		delete b;
	}*/
}

void Player::Visible(bool visible) {
	mVisible = visible;
}

bool Player::IsAnimating() {
	return mAnimating;
}

int Player::Score() {
	return mScore;
}

int Player::Lives() {
	return mLives;
}

void Player::AddScore(int change) {
	mScore += change;
}

bool Player::IgnoreCollisions()
{
	return !mVisible || mAnimating;
}

void Player::Hit(PhysEntity* other) {
	mLives -= 1;
	mAnimating = true;
	mDeathAnimation->ResetAnimation();
	mAudio->PlaySFX("SFX/PlayerExplosion.wav");
	mWasHit = true;
}

bool Player::WasHit() {
	return mWasHit;
}

void Player::Update() {
	if (mAnimating) {

		if (mWasHit) {
			mWasHit = false;
		}

		mDeathAnimation->Update();
		mAnimating = mDeathAnimation->IsAnimating();
	}
	else {
		if (Active()) {
			HandleMovement();
			HandleFiring();
		}
		mGump->Update();
		mBeanz->Update();
	}

	/*for (int i = 0; i < MAX_BULLETS; ++i) {
		mBullets[i]->Update();
	}*/
}

void Player::Render() {
	if (mVisible) {
		if (mAnimating) {
			mDeathAnimation->Render();
		}
		else {
			mGump->Render();
			mBeanz->Render();
		}
	}

	/*for (int i = 0; i < MAX_BULLETS; ++i) {
		mBullets[i]->Render();
	}*/

	PhysEntity::Render();
}