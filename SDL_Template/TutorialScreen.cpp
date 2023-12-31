#include "TutorialScreen.h"

TutorialScreen::TutorialScreen() {
	mMoveLeft = new GLTexture("Move Left", "emulogic.ttf", 25, { 0,0,0 });
	mMoveRight = new GLTexture("Move Right", "emulogic.ttf", 25, { 0,0,0 });
	mMoveUp = new GLTexture("Move Up", "emulogic.ttf", 25, { 0,0,0 });
	mMoveDown = new GLTexture("Move Down", "emulogic.ttf", 25, { 0,0,0 });
	
	mA = new GLTexture("A", "Key.ttf", 75, { 0,0,0 });
	mD = new GLTexture("D", "Key.ttf", 75, { 0,0,0 });
	mW = new GLTexture("W", "Key.ttf", 75, { 0,0,0 });
	mS = new GLTexture("S", "Key.ttf", 75, { 0,0,0 });

	mLeftArrow = new GLTexture("s", "Key.ttf", 75, { 0,0,0 });
	mRightArrow = new GLTexture("t", "Key.ttf", 75, { 0,0,0 });
	mUpArrow = new GLTexture("q", "Key.ttf", 75, { 0,0,0 });
	mDownArrow = new GLTexture("r", "Key.ttf", 75, { 0,0,0 });

	mBeanz = new GLTexture("Beanz.png", 28, 129, 72, 60);
	mGump = new GLTexture("Gump.png", 26, 168, 72, 60);
	
	mFloor = new GLTexture("floor tile 256x256.png", 0, 0, 256, 256);
	
	mBeanz->Position(750, 225);
	mGump->Position(650, 225);

	mMoveLeft->Position(350, 300.0f);
	mA->Position(650, 300);
	mLeftArrow->Position(750, 300);

	mMoveRight->Position(350, 375);
	mD->Position(650, 375);
	mRightArrow->Position(750, 375);

	mMoveUp->Position(350, 450);
	mW->Position(650, 450);
	mUpArrow->Position(750, 450);

	mMoveDown->Position(350, 525);
	mS->Position(650, 525);
	mDownArrow->Position(750, 525);


	// bottom bar entities
	mBottomBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.85f);
	mNamco = new GLTexture("BRANDVOR", "LavenderLime.ttf", 70, { 0, 182, 250 });
	mDates = new GLTexture("2023-Forever Brandvor LTD.", "LavenderLime.ttf", 32, { 0, 182, 250 });
	mRights = new GLTexture("ALL RIGHTS RESERVED", "LavenderLime.ttf", 32, { 0, 182, 250 });
	mNamcoOutline = new GLTexture("BRANDVOR", "LavenderLime.ttf", 70, { 0, 0, 0 });
	mDatesOutline = new GLTexture("2023-Forever Brandvor LTD.", "LavenderLime.ttf", 32, { 0, 0, 0 });
	mRightsOutline = new GLTexture("ALL RIGHTS RESERVED", "LavenderLime.ttf", 32, { 0, 0, 0 });
	
	mBottomBar->Parent(this);
	mNamco->Parent(mBottomBar);
	mDates->Parent(mBottomBar);
	mRights->Parent(mBottomBar);
	mNamcoOutline->Parent(mBottomBar);
	mDatesOutline->Parent(mBottomBar);
	mRightsOutline->Parent(mBottomBar);

	mNamco->Position(0.0f, 26.0f);
	mDates->Position(0.0f, 75.0f);
	mRights->Position(0.0f, 110.0f);
	mNamcoOutline->Position(0.0f, 26.0f);
	mDatesOutline->Position(0.0f, 75.0f);
	mRightsOutline->Position(0.0f, 110.0f);

	mNamcoOutline->Scale(Vector2(1.015f, 1.1f));
	mDatesOutline->Scale(Vector2(1.015f, 1.1f));
	mRightsOutline->Scale(Vector2(1.015f, 1.1f));

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

	delete mLeftArrow;
	mLeftArrow = nullptr;

	delete mUpArrow;
	mUpArrow = nullptr;

	delete mRightArrow;
	mRightArrow = nullptr;

	delete mDownArrow;
	mDownArrow = nullptr;

}


void TutorialScreen::Update() {

}

void TutorialScreen::Render() {
	
	mFloor->RenderRepeatedTexture(mFloor, 256, 256);

	mMoveLeft->Render();
	mMoveRight->Render();
	mW->Render();
	mS->Render();
	mA->Render();
	mD->Render();
	mMoveUp->Render();
	mMoveDown->Render();
	mLeftArrow->Render();
	mRightArrow->Render();
	mDownArrow->Render();
	mUpArrow->Render();

	mNamcoOutline->Render();
	mDatesOutline->Render();
	mRightsOutline->Render();
	mNamco->Render();
	mDates->Render();
	mRights->Render();

	mBeanz->Render();
	mGump->Render();

	
	
}

