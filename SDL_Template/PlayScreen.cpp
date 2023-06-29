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
	mBeanz = new Beanz();
	mBeanz->Parent(this);
	mBeanz->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);
	mBeanz->Active(true);

	mFloor = new GLTexture("floor tile 256x256.png", 0, 0, 256, 256);

	mBeanzJumpScare = new GLTexture("Beanz 128x128.png", 128, 128, 128, 128);
	mBeanzJumpScare->Parent(this);
	mBeanzJumpScare->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);
	

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
	}
	else {

	}
	if (mGump->CheckCollision(mBeanz)) {
		mGameOver = true;
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
