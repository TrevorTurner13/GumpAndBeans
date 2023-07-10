#include "Level3.h"

Level3::Level3(Gump* Gump, Beanz* Beanz, Rumpff* Rumpff, Wad* Wad) {
	mInput = InputManager::Instance();

	mWallScale = (1, 4);

	mGump = Gump;
	mBeanz = Beanz;
	mRumpff = Rumpff;
	mWad = Wad;

	mGump->Position(300.0f, 730.0f);
	mBeanz->Position(200.0f, 200.0f);
	mRumpff->Position(550.f, 320.0f);
	mWad->Position()

	mRumpff->SetMoveTimeMax(3.0f);

	mSpoon = new Object(new GLTexture("Utensils 256x256.png", 0, 0, 64, 304), new BoxCollider(Vector2(275.0f, 30.0f)), 90, 90);
	mSpoon->Position(Graphics::SCREEN_WIDTH * 0.2f, Graphics::SCREEN_HEIGHT * 0.58f);
	mSpoon->RotateTexture(90);

	mKnife1 = new Object(new GLTexture("Utensils 256x256.png", 64, 0, 64, 304), new BoxCollider(Vector2(30.0f, 275.0f)), 90, 90);
	mKnife1->Position(Graphics::SCREEN_WIDTH * 0.82f, Graphics::SCREEN_HEIGHT * 0.43f);
	mKnife1->RotateTexture(0);

	mKnife2 = new Object(new GLTexture("Utensils 256x256.png", 64, 0, 64, 304), new BoxCollider(Vector2(275.0f, 30.0f)), 90, 90);
	mKnife2->Position(Graphics::SCREEN_WIDTH * 1.05f, Graphics::SCREEN_HEIGHT * 0.58f);
	mKnife2->RotateTexture(90);

	mFork = new Object(new GLTexture("Utensils 256x256.png", 128, 0, 64, 304), new BoxCollider(Vector2(275.0f, 30.0f)), 90, 90);
	mFork->Position(Graphics::SCREEN_WIDTH * 0.7f, Graphics::SCREEN_HEIGHT * 0.26f);
	mFork->RotateTexture(90);

	mCar1 = new Object(new GLTexture("ToyCar.png", 128, 0, 128, 128), new BoxCollider(Vector2(120.0f, 63.0f)), 14, 14);
	mCar1->Position(Graphics::SCREEN_WIDTH * 0.40f, Graphics::SCREEN_HEIGHT * 0.65f);
	mCar1->RotateTexture(90);

	mCar2 = new Object(new GLTexture("ToyCar.png", 0, 0, 128, 128), new BoxCollider(Vector2(63.0f, 120.0f)), 14, 90);
	mCar2->Position(Graphics::SCREEN_WIDTH * 0.88f, Graphics::SCREEN_HEIGHT * 0.6f);
	mCar2->RotateTexture(0);

	mWall1 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall1->Position(25, 90);

	mWall2 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall2->Position(25, 346);

	mWall3 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall3->Position(25, 432);

	mWall4 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall4->Position(25, 758);

	mWall5 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(256.0f, 128.0f)), 1000, 1000);
	mWall5->Position(215, 890);
	mWall5->RotateTexture(90);

	mWall6 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(256.0f, 128.0f)), 1000, 1000);
	mWall6->Position(471, 890);
	mWall6->RotateTexture(90);

	mWall7 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(256.0f, 128.0f)), 1000, 1000);
	mWall7->Position(727, 890);
	mWall7->RotateTexture(270);

	mWall8 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(256.0f, 128.0f)), 1000, 1000);
	mWall8->Position(983, 890);
	mWall8->RotateTexture(90);

	mWall9 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall9->Position(1010, 708);

	mWall10 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall10->Position(1010, 249);

	mWall11 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall11->Position(1010, 155);

	mWall12 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall12->Position(1010, -100);

	mWall13 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(256.0f, 128.0f)), 1000, 1000);
	mWall13->Position(820, -35);
	mWall13->RotateTexture(90);

	mWall14 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(256.0f, 128.0f)), 1000, 1000);
	mWall14->Position(564, -35);
	mWall14->RotateTexture(270);

	mWall15 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(256.0f, 128.0f)), 1000, 1000);
	mWall15->Position(308, -35);
	mWall15->RotateTexture(90);

	mWall16 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(256.0f, 128.0f)), 1000, 1000);
	mWall16->Position(52, -35);
	mWall16->RotateTexture(90);

	mWall17 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(256.0f, 128.0f)), 1000, 1000);
	mWall17->Position(695, 600);
	mWall17->RotateTexture(90);

	mWall18 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall18->Position(500, 765);
	mWall18->RotateTexture(0);

	mWall19 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall19->Position(400, 380);
	mWall19->RotateTexture(0);


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
	mCar2->Render();
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
	mRumpff->Render();
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

	mGump->HandleCollision(mGump, mCar2);
	mBeanz->HandleCollision(mBeanz, mCar2);

	mGump->HandleCollision(mGump, mCar2);
	mBeanz->HandleCollision(mBeanz, mCar2);

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
}