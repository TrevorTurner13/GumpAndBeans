#ifndef __LEVEL1_H
#define __Level1_H
#include "InputManager.h"
#include "GLTexture.h"
#include "AnimatedGLTexture.h"
#include "Beanz.h"
#include "Gump.h"
#include "Object.h";
#include "Wad.h"


using namespace SDLFramework;

class Level1 : public PhysEntity {
private:
	InputManager* mInput;

	Object* mSugarCube;
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

	Object* mCenterWall;
	Object* mCenterWall2;
	Object* mCenterWall3;
	Object* mCenterWall4;

	Object* mPen;

	Gump* mGump;
	Beanz* mBeanz;

	Wad* mWad;
	
	Vector2 mWallScale;

public:
	Level1(Gump* Gump, Beanz* Beanz, Wad* Wad);
	~Level1();

	void Update();
	void Render();
	
	void CollisionHandler();

};


#endif
