#include "Level3.h"

Level3::Level3(Gump* Gump, Beanz* Beanz, Rumpff* Rumpff, Wad* Wad) {
	mInput = InputManager::Instance();

	mWallScale = (1.0f, 4.0f);

	mGump = Gump;
	mBeanz = Beanz;
	mRumpff = Rumpff;
	mWad = Wad;

	mRumpff->SetMoveTimeMax(3.0f);
	mWad->SetMoveTimeMax(2.0f);

	mSpoon = new Object(new GLTexture("Utensils 256x256.png", 0, 0, 64, 304), new BoxCollider(Vector2(275.0f, 30.0f)), 90, 90);
	mSpoon->Position(Graphics::SCREEN_WIDTH * 0.2f, Graphics::SCREEN_HEIGHT * 0.58f);
	mSpoon->RotateTexture(90);

	mKnife1 = new Object(new GLTexture("Utensils 256x256.png", 64, 0, 64, 304), new BoxCollider(Vector2(30.0f, 275.0f)), 90, 90);
	mKnife1->Position(Graphics::SCREEN_WIDTH * 0.82f, Graphics::SCREEN_HEIGHT * 0.7f);
	mKnife1->RotateTexture(0);

	mKnife2 = new Object(new GLTexture("Utensils 256x256.png", 64, 0, 64, 304), new BoxCollider(Vector2(275.0f, 30.0f)), 90, 90);
	mKnife2->Position(Graphics::SCREEN_WIDTH * 1.05f, Graphics::SCREEN_HEIGHT * 0.1f);
	mKnife2->RotateTexture(90);

	mFork = new Object(new GLTexture("Utensils 256x256.png", 128, 0, 64, 304), new BoxCollider(Vector2(275.0f, 30.0f)), 90, 90);
	mFork->Position(Graphics::SCREEN_WIDTH * 0.7f, Graphics::SCREEN_HEIGHT * 0.63f);
	mFork->RotateTexture(90);

	mCar1 = new Object(new GLTexture("ToyCar.png", 128, 0, 128, 128), new BoxCollider(Vector2(63.0f, 120.0f)), 14, 51);
	mCar1->Position(Graphics::SCREEN_WIDTH * 0.29f, Graphics::SCREEN_HEIGHT * 0.35f);
	mCar1->RotateTexture(0);

	mWall1 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall1->Position(25.0f, 90.0f);

	mWall2 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall2->Position(25.0f, 346.0f);

	mWall3 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall3->Position(25.0f, 432.0f);

	mWall4 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall4->Position(25.0f, 758.0f);

	mWall5 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(256.0f, 128.0f)), 1000, 1000);
	mWall5->Position(215.0f, 890.0f);
	mWall5->RotateTexture(90);

	mWall6 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(256.0f, 128.0f)), 1000, 1000);
	mWall6->Position(471.0f, 890.0f);
	mWall6->RotateTexture(90);

	mWall7 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(256.0f, 128.0f)), 1000, 1000);
	mWall7->Position(727.0f, 890.0f);
	mWall7->RotateTexture(270);

	mWall8 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(256.0f, 128.0f)), 1000, 1000);
	mWall8->Position(983.0f, 890.0f);
	mWall8->RotateTexture(90);

	mWall9 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall9->Position(1010, 740);

	mWall10 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall10->Position(1010, 500);

	mWall11 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall11->Position(1010,370);

	mWall12 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall12->Position(1010.0f, -100.0f);

	mWall13 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(256.0f, 128.0f)), 1000, 1000);
	mWall13->Position(820.0f, -35.0f);
	mWall13->RotateTexture(90);

	mWall14 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(256.0f, 128.0f)), 1000, 1000);
	mWall14->Position(564.0f, -35.0f);
	mWall14->RotateTexture(270);

	mWall15 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(256.0f, 128.0f)), 1000, 1000);
	mWall15->Position(308.0f, -35.0f);
	mWall15->RotateTexture(90);

	mWall16 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(256.0f, 128.0f)), 1000, 1000);
	mWall16->Position(52.0f, -35.0f);
	mWall16->RotateTexture(90);

	mWall17 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(256.0f, 128.0f)), 1000, 1000);
	mWall17->Position(460, 500);
	mWall17->RotateTexture(90);

	mWall18 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall18->Position(680, 765);
	mWall18->RotateTexture(0);

	mWall19 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall19->Position(400, 100);
	mWall19->RotateTexture(0);

	mWall20 = new Object(new GLTexture("DustWallDiagonal1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(200.0f, 256.0f)), 1000, 1000);
	mWall20->Position(650, 150);
	mWall20->RotateTexture(0);


	mSugarCube = new Object(new GLTexture("sugar cube 64x64.png", 0, 0, 64, 64), new BoxCollider(Vector2(64.0f, 64.0f)), 9, 9);
	mSugarCube->Position(900.0f, 700.0f);


}

Level3::~Level3() {

}

void Level3::Update() {
	mGump->Update();
	mBeanz->Update();
	mRumpff->Update();
	mWad->Update();

	CollisionHandler();
}

void Level3::Render() {
	mSpoon->Render();
	mKnife1->Render();
	mKnife2->Render();
	mFork->Render();
	mCar1->Render();
	mWall1->Render();
	mWall2->Render();
	mWall3->Render();
	mWall4->Render();
	mWall5->Render();
	mWall6->Render();
	mWall7->Render();
	mWall8->Render();
	mWall9->Render();
	mWall10->Render();
	mWall11->Render();
	mWall12->Render();
	mWall13->Render();
	mWall14->Render();
	mWall15->Render();
	mWall16->Render();
	mWall17->Render();
	mWall18->Render();
	mWall19->Render();
	mWall20->Render();
	mRumpff->Render();
	mSugarCube->Render();
	mWad->Render();
}

void Level3::CollisionHandler() {

	mGump->HandleCollision(mGump, mSpoon);
	mBeanz->HandleCollision(mBeanz, mSpoon);

	mGump->HandleCollision(mGump, mKnife1);
	mBeanz->HandleCollision(mBeanz, mKnife1);

	mGump->HandleCollision(mGump, mKnife2);
	mBeanz->HandleCollision(mBeanz, mKnife2);

	mGump->HandleCollision(mGump, mFork);
	mBeanz->HandleCollision(mBeanz, mFork);

	mGump->HandleCollision(mGump, mCar1);
	mBeanz->HandleCollision(mBeanz, mCar1);

	mGump->HandleCollision(mGump, mWall1);
	mBeanz->HandleCollision(mBeanz, mWall1);

	mGump->HandleCollision(mGump, mWall2);
	mBeanz->HandleCollision(mBeanz, mWall2);

	mGump->HandleCollision(mGump, mWall3);
	mBeanz->HandleCollision(mBeanz, mWall3);

	mGump->HandleCollision(mGump, mWall4);
	mBeanz->HandleCollision(mBeanz, mWall4);

	mGump->HandleCollision(mGump, mWall5);
	mBeanz->HandleCollision(mBeanz, mWall5);

	mGump->HandleCollision(mGump, mWall6);
	mBeanz->HandleCollision(mBeanz, mWall6);

	mGump->HandleCollision(mGump, mWall7);
	mBeanz->HandleCollision(mBeanz, mWall7);

	mGump->HandleCollision(mGump, mWall8);
	mBeanz->HandleCollision(mBeanz, mWall8);

	mGump->HandleCollision(mGump, mWall9);
	mBeanz->HandleCollision(mBeanz, mWall9);

	mGump->HandleCollision(mGump, mWall10);
	mBeanz->HandleCollision(mBeanz, mWall10);

	mGump->HandleCollision(mGump, mWall11);
	mBeanz->HandleCollision(mBeanz, mWall11);

	mGump->HandleCollision(mGump, mWall12);
	mBeanz->HandleCollision(mBeanz, mWall12);

	mGump->HandleCollision(mGump, mWall13);
	mBeanz->HandleCollision(mBeanz, mWall13);

	mGump->HandleCollision(mGump, mWall14);
	mBeanz->HandleCollision(mBeanz, mWall14);

	mGump->HandleCollision(mGump, mWall15);
	mBeanz->HandleCollision(mBeanz, mWall15);

	mGump->HandleCollision(mGump, mWall16);
	mBeanz->HandleCollision(mBeanz, mWall16);

	mGump->HandleCollision(mGump, mWall17);
	mBeanz->HandleCollision(mBeanz, mWall17);

	mGump->HandleCollision(mGump, mWall18);
	mBeanz->HandleCollision(mBeanz, mWall18);

	mGump->HandleCollision(mGump, mWall19);
	mBeanz->HandleCollision(mBeanz, mWall19);

	mGump->HandleCollision(mGump, mWall20);
	mBeanz->HandleCollision(mBeanz, mWall20);

	mGump->HandleCollision(mGump, mSugarCube);
	mBeanz->HandleCollision(mBeanz, mSugarCube);

	mSugarCube->HandleCollision(mSugarCube, mWall1);

	mSugarCube->HandleCollision(mSugarCube, mWall2);

	mSugarCube->HandleCollision(mSugarCube, mWall3);

	mSugarCube->HandleCollision(mSugarCube, mWall4);

	mSugarCube->HandleCollision(mSugarCube, mWall5);

	mSugarCube->HandleCollision(mSugarCube, mWall6);

	mSugarCube->HandleCollision(mSugarCube, mWall7);

	mSugarCube->HandleCollision(mSugarCube, mWall8);

	mSugarCube->HandleCollision(mSugarCube, mWall9);

	mSugarCube->HandleCollision(mSugarCube, mWall10);

	mSugarCube->HandleCollision(mSugarCube, mWall11);

	mSugarCube->HandleCollision(mSugarCube, mWall12);

	mSugarCube->HandleCollision(mSugarCube, mWall13);

	mSugarCube->HandleCollision(mSugarCube, mWall14);

	mSugarCube->HandleCollision(mSugarCube, mWall15);

	mSugarCube->HandleCollision(mSugarCube, mWall16);

	mSugarCube->HandleCollision(mSugarCube, mWall17);

	mSugarCube->HandleCollision(mSugarCube, mWall18);

	mSugarCube->HandleCollision(mSugarCube, mWall19);

}