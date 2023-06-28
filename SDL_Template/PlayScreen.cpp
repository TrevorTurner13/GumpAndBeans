#include "PlayScreen.h"



PlayScreen::PlayScreen() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();

	delete mPlayer;
	mPlayer = new Player();
	mPlayer->Parent(this);
	//mPlayer->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.8f);
	mPlayer->Active(true);

	mFloor = new GLTexture("floor tile 256x256.png", 0, 0, 256, 256);

}

PlayScreen::~PlayScreen() {
	mTimer = nullptr;
	mAudio = nullptr;

	delete mPlayer;
	mPlayer = nullptr;
}

void PlayScreen::Update() {
	mPlayer->Update();	
}

void PlayScreen::Render() {
	
	mFloor->RenderRepeatedTexture(mFloor, 256, 256);
	mPlayer->Render();
	
}
