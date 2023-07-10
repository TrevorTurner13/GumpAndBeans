#include "Level1.h"

Level1::Level1(Gump* Gump, Beanz* Beanz, Wad* Wad) {
	mInput = InputManager::Instance();

	
	mWallScale = Vector2(1.0f, 4.0f);

	mGump = Gump;
	mBeanz = Beanz;
	mWad = Wad;

	mWad->SetMoveTimeMax(3.0f);
	
	mSugarCube = new Object(new GLTexture("sugar cube 64x64.png", 0, 0, 64, 64), new BoxCollider(Vector2(64.0f, 64.0f)), 30, 30);
	mSugarCube->Position(200.0f, 500.0f);
	mWall1 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall1->Position(25.0f, 90.0f);
	
	mWall2 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall2->Position(25.0f, 346.0f);
	
	mWall3 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall3->Position(25.0f, 602.0f);
	
	mWall4 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall4->Position(25.0f, 858.0f);
	
	mWall5 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(256.0f, 128.0f)), 1000, 1000);
	mWall5->Position(215.0f, 890.0f);
	mWall5->RotateTexture(90.0f);
	
	mWall6 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(256.0f, 128.0f)), 1000, 1000);
	mWall6->Position(471.0f, 890.0f);
	mWall6->RotateTexture(90.0f);
	
	mWall7 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(256.0f, 128.0f)), 1000, 1000);
	mWall7->Position(727.0f, 890.0f);
	mWall7->RotateTexture(270.0f);
	
	mWall8 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(256.0f, 128.0f)), 1000, 1000);
	mWall8->Position(983.0f, 890.0f);
	mWall8->RotateTexture(90.0f);

	mWall9 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall9->Position(1010.0f, 725.0f);

	mWall10 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall10->Position(1010.0f, 419.0f);
	
	mWall11 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall11->Position(1010.0f, 285.0f);

	mWall12 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(128.0f, 256.0f)), 1000, 1000);
	mWall12->Position(1010.0f, -100.0f);

	mWall13 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(256.0f, 128.0f)), 1000, 1000);
	mWall13->Position(820.0f, -35.0f);
	mWall13->RotateTexture(90.0f);

	mWall14 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(256.0f, 128.0f)), 1000, 1000);
	mWall14->Position(564.0f, -35.0f);
	mWall14->RotateTexture(270.0f);

	mWall15 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(256.0f, 128.0f)), 1000, 1000);
	mWall15->Position(308.0f, -35.0f);
	mWall15->RotateTexture(90.0f);

	mWall16 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(256.0f, 128.0f)), 1000, 1000);
	mWall16->Position(52.0f, -35.0f);
	mWall16->RotateTexture(90.0f);

	mCenterWall = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(256.0f, 128.0f)), 1000, 1000);
	mCenterWall->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);
	mCenterWall->RotateTexture(90.0f);

	mCenterWall2 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(256.0f, 128.0f)), 1000, 1000);
	mCenterWall2->Position(Graphics::SCREEN_WIDTH * 0.5f-256.0f, Graphics::SCREEN_HEIGHT * 0.5f);
	mCenterWall2->RotateTexture(90.0f);

	mCenterWall3 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(256.0f, 128.0f)), 1000, 1000);
	mCenterWall3->Position(Graphics::SCREEN_WIDTH * 0.5f - 512.0f, Graphics::SCREEN_HEIGHT * 0.5f);
	mCenterWall3->RotateTexture(90.0f);

	mCenterWall4 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(256.0f, 128.0f)), 1000, 1000);
	mCenterWall4->Position(Graphics::SCREEN_WIDTH * 0.5f + 260.0f, Graphics::SCREEN_HEIGHT * 0.5f);
	mCenterWall4->RotateTexture(90.0f);

	mPen = new Object(new GLTexture("Pen.png", 0, 0, 64,256), new BoxCollider(Vector2(20.0f, 256.0f)), 30, 30);
	mPen->Position(Graphics::SCREEN_WIDTH * 0.5+410.0f, Graphics::SCREEN_HEIGHT *0.5+50.0f);
	
	
	mWad->Position(Graphics::SCREEN_WIDTH * 0.7f, Graphics::SCREEN_HEIGHT * 0.6f);
	
	mGump->Position(Graphics::SCREEN_WIDTH * 0.1f, Graphics::SCREEN_HEIGHT * 0.6f);
	mBeanz->Position(Graphics::SCREEN_WIDTH * 0.1f, Graphics::SCREEN_HEIGHT * 0.3f);
	
	
}

Level1::~Level1() {

}

void Level1::Update() {
	mGump->Update();
	mBeanz->Update();

	CollisionHandler();
	mWad->Update();
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

	mCenterWall->Render();
	mCenterWall2->Render();
	mCenterWall3->Render();
	mCenterWall4->Render();

	mPen->Render();

	mWad->Render();

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

	mGump->HandleCollision(mGump, mCenterWall);
	mBeanz->HandleCollision(mBeanz, mCenterWall);

	mGump->HandleCollision(mGump, mCenterWall2);
	mBeanz->HandleCollision(mBeanz, mCenterWall2);

	mGump->HandleCollision(mGump, mCenterWall3);
	mBeanz->HandleCollision(mBeanz, mCenterWall3);

	mGump->HandleCollision(mGump, mCenterWall4);
	mBeanz->HandleCollision(mBeanz, mCenterWall4);

	mGump->HandleCollision(mGump, mPen);
	mBeanz->HandleCollision(mBeanz, mPen);

	mWad->HandleCollision(mWad, mCenterWall4);
	mWad->HandleCollision(mWad, mWall7);
}