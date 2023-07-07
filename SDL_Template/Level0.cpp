#include "Level0.h"

Level0::Level0(Gump* Gump, Beanz* Beanz, Wad* wad, Rumpff* rumpff, int level) {
	mInput = InputManager::Instance();

	mGump = Gump;
	mBeanz = Beanz;
	mWad = wad;
	mRumpff = rumpff;

	SetLevelNumber(level);

	mTurnSpoon = false;

	mSpoon = new Object(new GLTexture("Utensils 256x256.png", 0, 0, 64, 304), new BoxCollider(Vector2(30.0f, 275.0f)), 60, 60);
	mSpoon->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);

	mSpoonTurned = new Object(new GLTexture("Utensils 256x256.png", 0, 0, 64, 304), new BoxCollider(Vector2(275.0f, 30.0f)), 60, 60);
	mSpoonTurned->RotateTexture(90);
	mSpoonTurned->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);

	mWall = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(100.0f, 256.0f)), 100, 100);
	mWall->Position(800.0f, 200.0f);

	mSugarCube = new Object(new GLTexture("sugar cube 64x64.png", 0, 0, 64, 64), new BoxCollider(Vector2(64.0f, 64.0f)), 30, 30);
	mSugarCube->Position(200.0f, 500.0f);
}

Level0::~Level0() {
	
}

void Level0::Update() {

	mBeanz->Update();
	mGump->Update();
	mRumpff->Update();
	mWad->Update();
	
	CollisionHandler();
}

void Level0::Render() {
	mGump->Render();
	mBeanz->Render();
	mWad->Render();
	mRumpff->Render();
	mWall->Render();
	if (!mTurnSpoon) {
		mSpoon->Render();
	}
	else {
		mSpoonTurned->Render();
	}

	mSugarCube->Render();
}

void Level0::CollisionHandler() {
	mGump->HandleCollision(mGump, mSugarCube);
	mGump->HandleCollision(mGump, mWall);

	mSugarCube->HandleCollision(mSugarCube, mWall);
	mSugarCube->HandleCollision(mSugarCube, mSpoon);

	mBeanz->HandleCollision(mBeanz, mSugarCube);
	mBeanz->HandleCollision(mBeanz, mWall);
	if (!mTurnSpoon) {
		mGump->HandleCollision(mGump, mSpoon);
		mBeanz->HandleCollision(mBeanz, mSpoon);
		if (mInput->KeyDown(SDL_SCANCODE_LSHIFT)) {
			if (mBeanz->CheckCollision(mSpoon)) {
				mTurnSpoon = true;
			}
		}
	}
	else {
		mGump->HandleCollision(mGump, mSpoonTurned);
		mBeanz->HandleCollision(mBeanz, mSpoonTurned);
		if (mInput->KeyDown(SDL_SCANCODE_LSHIFT)) {
			if (mBeanz->CheckCollision(mSpoonTurned)) {
				mTurnSpoon = false;
			}
		}
	}
}