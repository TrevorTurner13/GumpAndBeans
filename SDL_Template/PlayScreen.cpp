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

	mFloor = new GLTexture("floor tile 256x256.png", 0, 0, 256, 256);

	mBeanzJumpScare = new GLTexture("JumpScareBeanz.png", 0, 0, 128, 172);
	mBeanzJumpScare->Parent(this);
	mBeanzJumpScare->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);
	
	mJumpScareTotalTime = 1.25f;
	mJumpScareTimer = 0.0f;
	mJumpScareScale += 0.5f;
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

		if (mGump->CheckCollision(mBeanz)) {
			mGameOver = true;
			mAudio->PauseMusic();
			mAudio->PlaySFX("SFX/BEANZZZ.wav", 0);
		}
	}
	else {
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

	
}

void PlayScreen::Render() {
	mFloor->RenderRepeatedTexture(mFloor, 256, 256);
	mGump->Render();
	mBeanz->Render();
	if (mGameOver) {
		mBeanzJumpScare->Render();
	}
}
