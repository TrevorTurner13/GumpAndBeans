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
	mGump = new Gump();
	mBeanz = new Beanz(mGump);

	Level1(mGump, mBeanz);
}

Level1::Level1(Gump* Gump, Beanz* Beanz) {
	mGump = Gump;
	mBeanz = Beanz;
	
	mSugarCube = new Object(new GLTexture("sugar cube 64x64.png", 0, 0, 64, 64), new BoxCollider(Vector2(64.0f, 64.0f)), 30, 30);
	mSugarCube->Position(200.0f, 500.0f);

}

Level1::~Level1() {

}

void Level1::Update() {
	mGump->HandleCollision(mGump, mSugarCube);
}

void Level1::Render() {
	mSugarCube->Render();
}