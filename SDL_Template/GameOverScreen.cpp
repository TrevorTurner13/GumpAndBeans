#include "GameOverScreen.h"

GameOverScreen::GameOverScreen() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();
	mInput = InputManager::Instance();

	mGameOverBeanz = new AnimatedGLTexture("GameOverBeanz.png", 0, 0, 416, 416, 9, 2.0f, Animation::Layouts::Horizontal);
	mGameOverBeanz->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);
	mGameOverBeanz->Scale(Vector2(1.5f, 1.5f));
	
}

GameOverScreen::~GameOverScreen() {

}

void GameOverScreen::Update() {
	mGameOverBeanz->Update();
}

void GameOverScreen::Render() {
	mGameOverBeanz->Render();
}
