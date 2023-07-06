#include "GameOverScreen.h"

GameOverScreen::GameOverScreen() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();
	mInput = InputManager::Instance();

	mGameOverBeanz = new AnimatedGLTexture("GameOverBeanz.png", 0, 0, 416, 416, 16, 4.0f, Animation::Layouts::Horizontal);
	mGameOverBeanz->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);
	mGameOverBeanz->Scale(Vector2(1.5f, 1.5f));
	
	mGameOverText = new GLTexture("GameOver.png", 0, 0, 236, 175);
	mGameOverText->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.15f);

	mRetry = new GLTexture("Restart.png", 0, 0, 303, 66);
	mRetry->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.8f);
	mRetry->Scale(Vector2(0.5f, 0.5f));
	mRetryHighlight = new GLTexture("RestartHighlight.png", 0, 0, 318, 82);
	mRetryHighlight->Position(mRetry->Position());
	mRetryHighlight->Scale(Vector2(0.5f, 0.5f));

	mQuit = new GLTexture("Quit.png", 0, 0, 159, 69);
	mQuit->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.85f);
	mQuit->Scale(Vector2(0.5f, 0.5f));
	mQuitHighlight = new GLTexture("QuitHighlight.png", 0, 0, 176, 85);
	mQuitHighlight->Position(mQuit->Position());
	mQuitHighlight->Scale(Vector2(0.5f, 0.5f));

	mSelectedMode = 0;
	mOnePlayerMode = mRetryHighlight;
	mTwoPlayerMode = mQuit;
}

GameOverScreen::~GameOverScreen() {

}

void GameOverScreen::Update() {
	if (mInput->KeyPressed(SDL_SCANCODE_DOWN)) {
		ChangeSelectedMode(1);
	}
	else if (mInput->KeyPressed(SDL_SCANCODE_UP)) {
		ChangeSelectedMode(-1);
	}
	mGameOverBeanz->Update();
	mOnePlayerMode->Update();
	mTwoPlayerMode->Update();
}

void GameOverScreen::Render() {
	mGameOverBeanz->Render();
	mGameOverText->Render();
	mOnePlayerMode->Render();
	mTwoPlayerMode->Render();
}

int GameOverScreen::SelectedMode() {
	return mSelectedMode;
}

void GameOverScreen::ChangeSelectedMode(int change) {
	mSelectedMode += change;

	mAudio->PlaySFX("SFX/menuselect.mp3", 0);

	if (mSelectedMode < 0) {
		mSelectedMode = 1;

	}
	else if (mSelectedMode > 1) {
		mSelectedMode = 0;
	}
	if (mSelectedMode == 0) {
		mOnePlayerMode = mRetryHighlight;
		mTwoPlayerMode = mQuit;
	}
	else if (mSelectedMode == 1) {
		mOnePlayerMode = mRetry;
		mTwoPlayerMode = mQuitHighlight;
	}
}