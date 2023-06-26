#include "TutorialScreen.h"

TutorialScreen::TutorialScreen() {
	mMoveLeft = new GLTexture("Move Left", "emulogic.ttf", 25, { 230,230,230 });
	mMoveRight = new GLTexture("Move Right", "emulogic.ttf", 25, { 230,230,230 });
	mMoveUp = new GLTexture("Move Up", "emulogic.ttf", 25, { 230,230,230 });
	mMoveDown = new GLTexture("Move Down", "emulogic.ttf", 25, { 230,230,230 });
	

	mA = new GLTexture("A", "Key.ttf", 75, { 230,230,230 });
	mD = new GLTexture("D", "Key.ttf", 75, { 230,230,230 });
	mW = new GLTexture("W", "Key.ttf", 75, { 230,230,230 });
	mS = new GLTexture("S", "Key.ttf", 75, { 230,230,230 });
	

	mMoveLeft->Position(350, 300.0f);
	mA->Position(650, 300);

	mMoveRight->Position(350, 375);
	mD->Position(650, 375);

	mMoveUp->Position(350, 450);
	mW->Position(650, 450);

	mMoveDown->Position(350, 525);
	mS->Position(650, 525);


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
}


TutorialScreen::~TutorialScreen() {
	delete mMoveLeft;
	mMoveLeft = nullptr;

	delete mMoveRight;
	mMoveRight = nullptr;

	delete mMoveUp;
	mMoveUp = nullptr;

	delete mMoveDown;
	mMoveDown = nullptr;

	delete mA;
	mA = nullptr;

	delete mD;
	mD = nullptr;

	delete mW;
	mW = nullptr;

	delete mS;
	mS = nullptr;

	delete mBottomBar;
	mBottomBar = nullptr;

	delete mNamco;
	mNamco = nullptr;

	delete mDates;
	mDates = nullptr;

	delete mRights;
	mRights = nullptr;


}


void TutorialScreen::Update() {

}

void TutorialScreen::Render() {
	mMoveLeft->Render();
	mMoveRight->Render();
	mW->Render();
	mS->Render();
	mA->Render();
	mD->Render();
	mMoveUp->Render();
	mMoveDown->Render();
	
	mNamco->Render();
	mDates->Render();
	mRights->Render();
}