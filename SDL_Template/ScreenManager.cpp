#include "ScreenManager.h"


ScreenManager * ScreenManager::sInstance = nullptr;


ScreenManager * ScreenManager::Instance() {
	if (sInstance == nullptr) {
		sInstance = new ScreenManager();
	}

	return sInstance;
}

void ScreenManager::Release() {
	delete sInstance;
	sInstance = nullptr;
}

void ScreenManager::Update() {

	switch (mCurrentScreen) {
	case Start:
		mStartScreen->Update();

		if (mInput->KeyPressed(SDL_SCANCODE_RETURN)&& mStartScreen->SelectedMode()==0) {
			mCurrentScreen = Play;
			mAudio->PlayMusic("MUS/Game Music.mp3");
		}
		else if (mInput->KeyPressed(SDL_SCANCODE_RETURN) && mStartScreen->SelectedMode()== 1) {
			mCurrentScreen = Tutorial;
		}
		break;
	case Play:
		mPlayScreen->Update();
		if (mInput->KeyPressed(SDL_SCANCODE_RETURN)) {
			mAudio->PauseMusic();
			mAudio->PlayMusic("MUS/Game Start.mp3");
			mCurrentScreen = Start;
		}
		if (mPlayScreen->GetGameOver() && mPlayScreen->GetJumpScareDone()) {
			mCurrentScreen = GameOver;
			mAudio->PauseMusic();
			mAudio->PlayMusic("MUS/RICKMEMED.mp3");
		}
		break;

	case Tutorial:
		mTutorialScreen->Update();
		
		if (mInput->KeyPressed(SDL_SCANCODE_ESCAPE)) {
			mCurrentScreen = Start;
		}
		break;
	case GameOver:
		mGameOver->Update();
		if (mInput->KeyPressed(SDL_SCANCODE_RETURN) && mGameOver->SelectedMode() == 0) {
			delete mPlayScreen;
			mPlayScreen = new PlayScreen();
			delete mGameOver;
			mGameOver = new GameOverScreen(mPlayScreen);
			mCurrentScreen = Play;
			mAudio->PlayMusic("MUS/Game Music.mp3");
		}
		else if (mInput->KeyPressed(SDL_SCANCODE_RETURN) && mGameOver->SelectedMode() == 1) {
			std::exit(0);
		}
		break;
	
	}

}

void ScreenManager::Render() {

	switch (mCurrentScreen) {
	case Start:
		mStartScreen->Render();
		break;
	case Play:
		mPlayScreen->Render();
		break;

	case Tutorial:
		mTutorialScreen->Render();
		break;

	case GameOver:
		mGameOver->Render();
		break;
	}
}

ScreenManager::ScreenManager() {
	mInput = InputManager::Instance();
	mAudio = AudioManager::Instance();


	mStartScreen = new StartScreen();
	mPlayScreen = new PlayScreen();
	mTutorialScreen = new TutorialScreen();
	mGameOver = new GameOverScreen(mPlayScreen);

	mCurrentScreen = Start;
}

ScreenManager::~ScreenManager() {
	mInput = nullptr;

	delete mStartScreen;
	mStartScreen = nullptr;

	delete mPlayScreen;
	mPlayScreen = nullptr;

	delete mTutorialScreen;
	mTutorialScreen = nullptr;

	delete mGameOver;
	mGameOver = nullptr;

}

void ScreenManager::RenderRepeatedTexture(Texture* texture, int textureWidth, int textureHeight) {
	int offsetX = textureWidth / 2;
	int offsetY = textureHeight / 2;

	for (int y = -offsetY; y < Graphics::SCREEN_HEIGHT; y += textureHeight) {
		for (int x = -offsetX; x < Graphics::SCREEN_WIDTH; x += textureWidth) {
			texture->Position(x, y);
			texture->Render();
		}
	}
}