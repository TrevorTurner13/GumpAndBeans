#include "PlayScreen.h"

PlayScreen::PlayScreen() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();
	mInput = InputManager::Instance();

	mCollection = new GLTexture("Collection.png", 0, 0, 224, 64);
	mCollection->Position(Vector2(150.0f, 50.0f));

	mFadeOut = new AnimatedGLTexture("FadeOut.png", 0, 0, 128, 112, 10, 2.0f, Animation::Layouts::Horizontal);
	mFadeOut->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f));
	mFadeOut->Scale(Vector2(8.0f, 8.0f));
	mFadeOut->SetWrapMode(Animation::WrapModes::Once);

	mFadeIn = new AnimatedGLTexture("FadeIn.png", 0, 0, 128, 112, 10, 2.0f, Animation::Layouts::Horizontal);
	mFadeIn->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f));
	mFadeIn->Scale(Vector2(8.0f, 8.0f));
	mFadeIn->SetWrapMode(Animation::WrapModes::Once);

	mGameOver = false;
	mGameOverBeanz = false;
	mGameOverWad = false;
	mGameOverRumpff = false;
	
	mLevel = 0;

	delete mGump;
	mGump = new Gump();
	mGump->Parent(this);
	mGump->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.5f);
	mGump->Active(true);

	delete mBeanz;
	mBeanz = new Beanz(mGump);
	mBeanz->Parent(this);
	mBeanz->Position(Graphics::SCREEN_WIDTH * 0.6f, Graphics::SCREEN_HEIGHT * 0.5f);
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

	mLevel0 = new Level0(mGump, mBeanz);

	mLevel1 = new Level1(mGump, mBeanz, mWad);

	mLevel2 = new Level2(mGump, mBeanz, mRumpff);
	
	mLevel3 = new Level3(mGump, mBeanz, mRumpff, mWad);

	mFloor = new GLTexture("floor tile 256x256.png", 0, 0, 256, 256);

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

	mFadeTimer = 0.0f;
	mFadeTotalTime = 2.0f;
	mFadeDone = false;
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

	delete mBeanzJumpScare;
	mBeanzJumpScare = nullptr;

	delete mRumpffJumpScare;
	mRumpffJumpScare = nullptr;

	delete mWadJumpScare;
	mWadJumpScare = nullptr;
}

void PlayScreen::Update() {
	if (!mGameOver) {
		if (mGump->CheckCollision(mBeanz)) {
			mGameOver = true;
			mGameOverBeanz = true;
			mGameOverWad = false;
			mGameOverRumpff = false;
			mAudio->PauseMusic();
			mAudio->PlaySFX("SFX/BEANZZZ.wav", 0);
		}
		switch (mLevel) {
		case 0:
			mLevel0->Update();
			if (mLevel0->mCurrentLore == 10 && !mFadeDone) {
				mFadeOut->Update();
				mFadeTimer += mTimer->DeltaTime();
				if (mFadeTimer >= mFadeTotalTime) {
					mFadeDone = true;
				}
			}
			if (mLevel0->mCurrentLore == 10 && mFadeDone) {
				mLevel++;
				mFadeDone = false;
				mFadeTimer = 0.0f;
				mGump->Position(Vector2(Graphics::SCREEN_WIDTH * 0.3f, Graphics::SCREEN_HEIGHT * 0.7f));
				mBeanz->Position(Vector2(Graphics::SCREEN_WIDTH * 0.3f, Graphics::SCREEN_HEIGHT * 0.3f));
			}
			break;

		case 1:
			mLevel1->Update();
			if (!mFadeDone) {
				mFadeIn->Update();
				mFadeTimer += mTimer->DeltaTime();
				if (mFadeTimer >= mFadeTotalTime) {
					mFadeDone = true;
				}
			}
			if (mFadeDone) {
				mGump->Active(true);
				mBeanz->Active(true);
			}
			if (mGump->CheckCollision(mWad) || mBeanz->CheckCollision(mWad)) {
				mGameOver = true;
				mGameOverWad = true;
				mGameOverRumpff = false;
				mGameOverBeanz = false;
				mAudio->PauseMusic();
				mAudio->PlaySFX("SFX/EW.wav", 0);
			}

			break;

		case 2:
			mLevel2->Update();

			if (mGump->CheckCollision(mRumpff) || mBeanz->CheckCollision(mRumpff)) {
				mGameOver = true;
				mGameOverRumpff = true;
				mAudio->PauseMusic();
				mAudio->PlaySFX("SFX/Zombie.mp3", 0);
			}

			break;

		case 3:
			mLevel3->Update();

			if (mGump->CheckCollision(mRumpff) || mBeanz->CheckCollision(mRumpff)) {
				mGameOver = true;
				mGameOverRumpff = true;
				mAudio->PauseMusic();
				mAudio->PlaySFX("SFX/Zombie.mp3", 0);
			}

			break;
		}

		if (mGump->Position().x > Graphics::SCREEN_WIDTH && mBeanz->Position().x > Graphics::SCREEN_WIDTH) {
			// Increase level by 1
			mLevel++;
			mGump->Position(50.0f, mGump->Position().y);
			mBeanz->Position(50.0f, mBeanz->Position().y);
		}
		
	}
	else {
		JumpScareHandler();
	}
}

void PlayScreen::Render() {
	mFloor->RenderRepeatedTexture(mFloor, 256, 256);
	if (mLevel == 0) {
		mLevel0->Render();
		if (mLevel0->mCurrentLore == 10 && !mFadeDone) {
			mFadeOut->Render();			
		}
	}
	if (mLevel == 1) {
		mGump->Render();
		mBeanz->Render();
		mLevel1->Render();
		if (!mFadeDone) {		
			mFadeIn->Render();
		}
	}
	if (mLevel == 2) {
		mGump->Render();
		mBeanz->Render();
		mLevel2->Render();
	}
	if (mLevel == 3) {
		mGump->Render();
		mBeanz->Render();
		mLevel3->Render();
	}
	if (mGameOver) {
		if (mGump->CheckCollision(mBeanz)) {
			mBeanzJumpScare->Render();
		}
		else if (mGump->CheckCollision(mRumpff) || mBeanz->CheckCollision(mRumpff)) {
			mRumpffJumpScare->Render();
		}
		else if (mGump->CheckCollision(mWad) || mBeanz->CheckCollision(mWad)) {
			mWadJumpScare->Render();
		}
	}
	if (mLevel0->mCurrentLore >= 6 ) {
		mCollection->Render();
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
	else if (mGump->CheckCollision(mRumpff) || mBeanz->CheckCollision(mRumpff)) {
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
	else if (mGump->CheckCollision(mWad) || mBeanz->CheckCollision(mWad)) {
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




