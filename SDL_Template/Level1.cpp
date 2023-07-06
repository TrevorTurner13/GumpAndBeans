#include "Level1.h"

Level1* Level1::sInstance = nullptr;

Level1* Level1::Instance() {
	if (sInstance == nullptr) {
		sInstance = new Level1();
	}

	return sInstance;
}

void Level1::Release() {
	delete sInstance;
	sInstance = nullptr;
}

Level1::Level1() {
	mInput = InputManager::Instance();

	mGump = new Gump();
	mBeanz = new Beanz(mGump);
	mSugarCube = new Object(new GLTexture("sugar cube 64x64.png", 0, 0, 64, 64), new BoxCollider(Vector2(64.0f, 64.0f)), 30, 30);
	

}

Level1::Level1(Gump* Gump, Beanz* Beanz) {
	mInput = InputManager::Instance();

	mWallScale = (1, 4);

	mGump = Gump;
	mBeanz = Beanz;
	
	mSugarCube = new Object(new GLTexture("sugar cube 64x64.png", 0, 0, 64, 64), new BoxCollider(Vector2(64.0f, 64.0f)), 30, 30);
	mSugarCube->Position(200.0f, 500.0f);
	mWall1 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall1->Position(25, 90);
	
	mWall2 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall2->Position(25, 346);
	
	mWall3 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall3->Position(25, 602);
	
	mWall4 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall4->Position(25, 858);
	
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
	mWall9->Position(1010, 725);

	mWall10 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall10->Position(1010, 419);
	
	mWall11 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall11->Position(1010, 285);

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

}

Level1::~Level1() {

}

void Level1::Update() {
	mGump->Update();
	mBeanz->Update();

	CollisionHandler();
}

void Level1::Render() {
	mSugarCube->Render();
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
}

void Level1::CollisionHandler() {
	mGump->HandleCollision(mGump, mSugarCube);
	mBeanz->HandleCollision(mBeanz, mSugarCube);

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
}