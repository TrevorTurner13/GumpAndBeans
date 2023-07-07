#ifndef __LEVEL2_H
#define __Level2_H
#include "InputManager.h"
#include "GLTexture.h"
#include "AnimatedGLTexture.h"
#include "Beanz.h"
#include "Gump.h"
#include "Wad.h"
#include "Rumpff.h"
#include "Object.h"

using namespace SDLFramework;

class Level2 : public PhysEntity {
private:
	InputManager* mInput;

	Object* mWall1;
	Object* mWall2;
	Object* mWall3;
	Object* mWall4;
	Object* mWall5;
	Object* mWall6;
	Object* mWall7;
	Object* mWall8;
	Object* mWall9;
	Object* mWall10;
	Object* mWall11;
	Object* mWall12;
	Object* mWall13;
	Object* mWall14;
	Object* mWall15;
	Object* mWall16;
	Object* mWall17;
	Object* mWall18;
	Object* mWall19;
	Object* mSpoon;
	Object* mKnife1;
	Object* mKnife2;
	Object* mFork;
	Object* mCar1;
	Object* mCar2;
    Gump* mGump;
	Beanz* mBeanz;
	Wad* mWad;
	Rumpff* mRumpff;

	Vector2 mWallScale;

public:
	Level2(Gump* Gump, Beanz* Beanz, Wad* Wad, Rumpff* Rumpff);
	~Level2();

	void Update();
	void Render();

	void CollisionHandler();

};


#endif
