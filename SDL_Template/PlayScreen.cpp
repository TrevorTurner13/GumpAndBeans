#include "PlayScreen.h"



PlayScreen::PlayScreen() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();

	delete mGump;
	mGump = new Gump();
	mGump->Parent(this);
	//mPlayer->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.8f);
	mGump->Active(true);

	delete mBeanz;
	mBeanz = new Beanz();
	mBeanz->Parent(this);
	//mPlayer->Position(Graphics::SCREEN_WIDTH * 0.4f, Graphics::SCREEN_HEIGHT * 0.8f);
	mBeanz->Active(true);

	mFloor = new GLTexture("floor tile 256x256.png", 0, 0, 256, 256);

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
	mGump->Update();
	mBeanz->Update();
}

void PlayScreen::Render() {
	mFloor->RenderRepeatedTexture(mFloor, 256, 256);
	mGump->Render();
	mBeanz->Render();
	
}
