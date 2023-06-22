#include "StartScreen.h"

StartScreen::StartScreen() {
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();
	mAudio = AudioManager::Instance();


	// logo entities
	mLogo = new GLTexture("GumpTitle.png", 0, 0, 705, 178);
	mAnimatedLogo = new AnimatedGLTexture("GumpTitle.png", 0, 0, 705, 178, 3, 0.2f, Animation::Layouts::Vertical);

	mLogo->Parent(this);
	mAnimatedLogo->Parent(this);

	mLogo->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.32f);
	mAnimatedLogo->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.32f);

	//play mode entities
	mPlayModes = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.55f);
	mOnePlayerMode = new GLTexture("Play.png", 0, 0, 153, 74);
	mTwoPlayerMode = new GLTexture("HowToPlay.png", 0, 0, 419, 74);

	mPlayHighlight = new GLTexture("PlayHighlight.png", 0, 0, 163, 84);
	mHowToPlayHighlight = new GLTexture("HowToPlayHighLight.png", 0, 0, 429, 84);
	mPlayDefault = new GLTexture("Play.png", 0, 0, 153, 74);
	mHowToPlayDefault = new GLTexture("HowToPlay.png", 0, 0, 419, 74);

	mPlayModes->Parent(this);
	mOnePlayerMode->Parent(mPlayModes);

	mPlayHighlight->Parent(mPlayModes);
	mPlayDefault->Parent(mPlayModes);
	mHowToPlayDefault->Parent(mPlayModes);
	mHowToPlayHighlight->Parent(mPlayModes);

	mOnePlayerMode->Position(0.0f, -35.0f);
	mTwoPlayerMode->Position(0.0f, 35.0f);

	mPlayHighlight->Position(0.0f, -35.0f);
	mPlayDefault->Position(0.0f, -35.0f);
	mHowToPlayDefault->Position(0.0f, 45.0f);
	mHowToPlayHighlight->Position(0.0f, 45.0f);


	mSelectedMode = 0;
	mOnePlayerMode = mPlayHighlight;
	mTwoPlayerMode = mHowToPlayDefault;



	// bottom bar entities
	mBottomBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.85f);
	mNamco = new GLTexture("BRANDVOR", "LavenderLime.ttf", 70, { 255, 165, 0 });
	mDates = new GLTexture("2023-Forever Brandvor LTD.", "LavenderLime.ttf", 32, { 255, 165, 0 });
	mRights = new GLTexture("ALL RIGHTS RESERVED", "LavenderLime.ttf", 32, { 255, 165, 0 });

	mBottomBar->Parent(this);
	mNamco->Parent(mBottomBar);
	mDates->Parent(mBottomBar);
	mRights->Parent(mBottomBar);

	mNamco->Position(0.0f, 26.0f);
	mDates->Position(0.0f, 75.0f);
	mRights->Position(0.0f, 110.0f);

	// screen animation variables
	ResetAnimation();

	
}


StartScreen::~StartScreen() {

	// logo entities
	delete mLogo;
	mLogo = nullptr;
	delete mAnimatedLogo;
	mAnimatedLogo = nullptr;
	delete mTopBar;

	// play mode entities
	delete mPlayModes;
	mPlayModes = nullptr;
	delete mOnePlayerMode;
	mOnePlayerMode = nullptr;
	delete mTwoPlayerMode;
	mTwoPlayerMode = nullptr;
	delete mPlayDefault;
	mPlayDefault = nullptr;

	delete mPlayHighlight;
	mPlayHighlight = nullptr;
	delete mHowToPlayHighlight;
	mHowToPlayHighlight = nullptr;
	delete mHowToPlayDefault;
	mHowToPlayDefault = nullptr;

	// bottom bar entities
	delete mBottomBar;
	mBottomBar = nullptr;
	delete mNamco;
	mNamco = nullptr;
	delete mDates;
	mDates = nullptr;
	delete mRights;
	mRights = nullptr;

	mTimer = nullptr;
	mInput = nullptr;
	mAudio = nullptr;
}

void StartScreen::ResetAnimation() {
	mAnimationStartPos = Vector2(0.0f, Graphics::SCREEN_HEIGHT);
	mAnimationEndPos = Vec2_Zero;
	mAnimationTotalTime = 5.0f;
	mAnimationTimer = 0.0f;
	mAnimationDone = false;

	Position(mAnimationStartPos);
}

int StartScreen::SelectedMode() {
	return mSelectedMode;
}

void StartScreen::ChangeSelectedMode(int change) {
	mSelectedMode += change;
	
	if (mSelectedMode < 0) {
		mSelectedMode = 1;

	}
	else if (mSelectedMode > 1) {
		mSelectedMode = 0;
	}
	if (mSelectedMode == 0) {
		mOnePlayerMode = mPlayHighlight;
		mTwoPlayerMode = mHowToPlayDefault;
	}
	else if (mSelectedMode == 1) {
		mOnePlayerMode = mPlayDefault;
		mTwoPlayerMode = mHowToPlayHighlight;
	}




}

void StartScreen::Update() {
	if (!mAnimationDone) {
		mAnimationTimer += mTimer->DeltaTime();
		Position(Lerp(mAnimationStartPos, mAnimationEndPos, mAnimationTimer / mAnimationTotalTime));

		if (mAnimationTimer >= mAnimationTotalTime) {
			mAnimationDone = true;
			//mStars->Scroll(false);
		}

		if (mInput->KeyPressed(SDL_SCANCODE_DOWN) || mInput->KeyPressed(SDL_SCANCODE_UP)) {
			mAnimationTimer = mAnimationTotalTime;
		}
	}
	else {
		mAnimatedLogo->Update();

		if (mInput->KeyPressed(SDL_SCANCODE_DOWN)) {
			ChangeSelectedMode(1);
		}
		else if (mInput->KeyPressed(SDL_SCANCODE_UP)) {
			ChangeSelectedMode(-1);
		}
	}
	mTimer->Update();
	mOnePlayerMode->Update();
	mTwoPlayerMode->Update();

}

void StartScreen::Render() {

	if (!mAnimationDone) {
		mLogo->Render();
	}
	else {
		mAnimatedLogo->Render();
	}

	mOnePlayerMode->Render();
	mTwoPlayerMode->Render();

	mNamco->Render();
	mDates->Render();
	mRights->Render();
}