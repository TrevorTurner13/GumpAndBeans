#include "PlayScreen.h"

PlayScreen::PlayScreen() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();

	mGameOver = false;

	delete mGump;
	mGump = new Gump();
	mGump->Parent(this);
	mGump->Position(Graphics::SCREEN_WIDTH * 0.2f, Graphics::SCREEN_HEIGHT * 0.2f);
	mGump->Active(true);

	delete mBeanz;
	mBeanz = new Beanz(mGump);
	mBeanz->Parent(this);
	mBeanz->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);
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

	mSpoon = new Object(new GLTexture("Utensils 256x256.png", 0, 0, 64, 304), new BoxCollider(Vector2(30.0f, 275.0f)), 30, 30);
	mSpoon->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);

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

		mGump->HandleCollision(mGump, mSugarCube);
		mGump->HandleCollision(mGump, mWall);
		mGump->HandleCollision(mGump, mSpoon);

		mBeanz->HandleCollision(mBeanz, mSugarCube);
		mBeanz->HandleCollision(mBeanz, mWall);
		mBeanz->HandleCollision(mBeanz, mSpoon);

		if (mGump->CheckCollision(mBeanz)) {
			mGameOver = true;
			mAudio->PauseMusic();
			mAudio->PlaySFX("SFX/BEANZZZ.wav", 0);	
		}
		if (mGump->CheckCollision(mWad)) {
			mGameOver = true;
			mAudio->PauseMusic();
		}
		if (mGump->CheckCollision(mRumpff)) {
			mGameOver = true;
			mAudio->PauseMusic();
		}
	}
	else {
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
}

void PlayScreen::Render() {

		mFloor->RenderRepeatedTexture(mFloor, 256, 256);
		mGump->Render();
		mBeanz->Render();
		mWad->Render();
		mRumpff->Render();
		mWall->Render();
		mSpoon->Render();
		mSugarCube->Render();
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




