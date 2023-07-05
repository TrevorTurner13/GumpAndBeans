#include "PlayScreen.h"

PlayScreen::PlayScreen() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();
	mInput = InputManager::Instance();

	mLevel1 = new Level1;

	mGameOver = false;
	
	mLevel = 0;

	delete mGump;
	mGump = new Gump();
	mGump->Parent(this);
	mGump->Position(Graphics::SCREEN_WIDTH * 0.2f, Graphics::SCREEN_HEIGHT * 0.2f);
	mGump->Active(true);

	delete mBeanz;
	mBeanz = new Beanz(mGump);
	mBeanz->Parent(this);
	mBeanz->Position(Graphics::SCREEN_WIDTH * 0.2f, Graphics::SCREEN_HEIGHT * 0.5f);
	mBeanz->Active(true);

	delete mWad;
	mWad = new Wad();
	mWad->Parent(this);
	mWad->Position(Graphics::SCREEN_WIDTH * 0.6f, Graphics::SCREEN_HEIGHT * 0.6f);
	mWad->Active(true);

	delete mRumpff;
	mRumpff = new Rumpff();
	mRumpff->Parent(this);
	mRumpff->Position(Graphics::SCREEN_WIDTH * 0.3f, Graphics::SCREEN_HEIGHT * 0.6f);
	mRumpff->Active(true);

	mFloor = new GLTexture("floor tile 256x256.png", 0, 0, 256, 256);

	mSpoon = new Object(new GLTexture("Utensils 256x256.png", 0, 0, 64, 304), new BoxCollider(Vector2(30.0f, 275.0f)), 60, 60);
	mSpoon->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);

	mTurnSpoon = false;

	mSpoonTurned = new Object(new GLTexture("Utensils 256x256.png", 0, 0, 64, 304), new BoxCollider(Vector2(275.0f, 30.0f)), 60, 60);
	mSpoonTurned->RotateTexture();
	mSpoonTurned->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);

	mWall = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256),  new BoxCollider(Vector2(100.0f,256.0f)), 100, 100);
	mWall->Position(800.0f, 200.0f);

	mSugarCube = new Object(new GLTexture("sugar cube 64x64.png", 0, 0, 64, 64), new BoxCollider(Vector2(64.0f, 64.0f)), 30, 30);
	mSugarCube->Position(200.0f, 500.0f);

	mBeanzJumpScare = new GLTexture("JumpScareBeanz.png", 0, 0, 128, 172);
	mBeanzJumpScare->Parent(this);
	mBeanzJumpScare->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);
	
	mRumpffJumpScare = new GLTexture("JumpScareRumpff.png", 0, 0, 160, 220);
	mRumpffJumpScare->Parent(this);
	mRumpffJumpScare->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);

	mWadJumpScare = new GLTexture("JumpScareWad.png", 0, 0, 128, 188);
	mWadJumpScare->Parent(this);
	mWadJumpScare->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);

	mJumpScareTotalTime = 1.25f;
	mJumpScareTimer = 0.0f;
	mJumpScareScale = 0.0f;
	mJumpScareDone = false;
}

PlayScreen::~PlayScreen() {
	mTimer = nullptr;
	mAudio = nullptr;

	delete mBeanz;
	mBeanz = nullptr;

	delete mGump;
	mGump = nullptr;

	delete mFloor;
	mFloor = nullptr;
}

void PlayScreen::Update() {
	if (!mGameOver) {
		mGump->Update();
		mBeanz->Update();
		mWad->Update();
		mRumpff->Update();

		//Handle Collision
		
		
		switch (mLevel) {
		case 0:
			CollisionHandler();
			break;

		case 1:
			mLevel1->Update();
			break;
		}

		if (mGump->CheckCollision(mBeanz)) {
			mGameOver = true;
			mAudio->PauseMusic();
			mAudio->PlaySFX("SFX/BEANZZZ.wav", 0);	
		}
		if (mGump->CheckCollision(mWad)) {
			mGameOver = true;
			mAudio->PauseMusic();
			mAudio->PlaySFX("SFX/EW.wav", 0);
		}
		if (mGump->CheckCollision(mRumpff)) {
			mGameOver = true;
			mAudio->PauseMusic();
			
		}
		if (mGump->Position().x > Graphics::SCREEN_WIDTH && mBeanz->Position().x > Graphics::SCREEN_WIDTH) {
			// Increase level by 1
			mLevel++;
		}
		
	}
	else {
		JumpScareHandler();
	}
}

void PlayScreen::Render() {
	mFloor->RenderRepeatedTexture(mFloor, 256, 256);
	if (mLevel == 0) {
		mGump->Render();
		mBeanz->Render();
		mWad->Render();
		mRumpff->Render();
		mWall->Render();
		if (!mTurnSpoon) {
			mSpoon->Render();
		}
		else {
			mSpoonTurned->Render();
		}
		
		mSugarCube->Render();
	}
	if (mLevel == 1) {
		mLevel1->Render();
	}

	if (mGameOver) {
		if (mGump->CheckCollision(mBeanz)) {
			mBeanzJumpScare->Render();
		}
		else if (mGump->CheckCollision(mRumpff)) {
			mRumpffJumpScare->Render();
		}
		else if (mGump->CheckCollision(mWad)) {
			mWadJumpScare->Render();
		}
	}
}

void PlayScreen::CollisionHandler() {
	mGump->HandleCollision(mGump, mSugarCube);
	mGump->HandleCollision(mGump, mWall);

	mBeanz->HandleCollision(mBeanz, mSugarCube);
	mBeanz->HandleCollision(mBeanz, mWall);
	if (!mTurnSpoon) {
		mGump->HandleCollision(mGump, mSpoon);
		mBeanz->HandleCollision(mBeanz, mSpoon);
		if (mInput->KeyDown(SDL_SCANCODE_LSHIFT)) {
			if (mBeanz->CheckCollision(mSpoon)) {
				mTurnSpoon = true;
			}
		}
	}
	else {
		mGump->HandleCollision(mGump, mSpoonTurned);
		mBeanz->HandleCollision(mBeanz, mSpoonTurned);
		if (mInput->KeyDown(SDL_SCANCODE_LSHIFT)) {
			if (mBeanz->CheckCollision(mSpoonTurned)) {
				mTurnSpoon = false;
			}
		}
	}
}

void PlayScreen::JumpScareHandler() {
	if (mGump->CheckCollision(mBeanz)) {
		mBeanzJumpScare->Update();
		if (!mJumpScareDone) {
			mJumpScareTimer += mTimer->DeltaTime();
			mJumpScareScale += 0.75f;
			mBeanzJumpScare->Translate(-Vec2_Up * 50.0f * mTimer->DeltaTime(), World);
			mBeanzJumpScare->Scale(Vector2(mJumpScareScale, mJumpScareScale));

			if (mJumpScareTimer >= mJumpScareTotalTime) {
				mJumpScareDone = true;
			}
		}
	}
	else if (mGump->CheckCollision(mRumpff)) {
		mRumpffJumpScare->Update();
		if (!mJumpScareDone) {
			mJumpScareTimer += mTimer->DeltaTime();
			mJumpScareScale += 0.75f;
			mRumpffJumpScare->Translate(-Vec2_Up * 50.0f * mTimer->DeltaTime(), World);
			mRumpffJumpScare->Scale(Vector2(mJumpScareScale, mJumpScareScale));

			if (mJumpScareTimer >= mJumpScareTotalTime) {
				mJumpScareDone = true;
			}
		}
	}
	else if (mGump->CheckCollision(mWad)) {
		mWadJumpScare->Update();
		if (!mJumpScareDone) {
			mJumpScareTimer += mTimer->DeltaTime();
			mJumpScareScale += 0.75f;
			mWadJumpScare->Translate(-Vec2_Up * 50.0f * mTimer->DeltaTime(), World);
			mWadJumpScare->Scale(Vector2(mJumpScareScale, mJumpScareScale));

			if (mJumpScareTimer >= mJumpScareTotalTime) {
				mJumpScareDone = true;
			}
		}
	}
}




