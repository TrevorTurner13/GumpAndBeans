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
		}
		else if (mInput->KeyPressed(SDL_SCANCODE_RETURN) && mStartScreen->SelectedMode()== 1) {
			mCurrentScreen = Tutorial;
		}
		break;
	case Play:
		mPlayScreen->Update();
		break;

	case Tutorial:
		mTutorialScreen->Update();
		
		if (mInput->KeyPressed(SDL_SCANCODE_ESCAPE)) {
			mCurrentScreen = Start;
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
	}
}

ScreenManager::ScreenManager() {
	mInput = InputManager::Instance();


	mStartScreen = new StartScreen();
	mPlayScreen = new PlayScreen();
	mTutorialScreen = new TutorialScreen();

	mCurrentScreen = Start;
}

ScreenManager::~ScreenManager() {
	mInput = nullptr;

	delete mStartScreen;
	mStartScreen = nullptr;

	delete mPlayScreen;
	mPlayScreen = nullptr;
}