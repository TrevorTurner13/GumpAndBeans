#ifndef __LEVEL0_H
#define __LEVEL0_H
#include "InputManager.h"
#include "GLTexture.h"
#include "AnimatedGLTexture.h"
#include "Beanz.h"
#include "Gump.h"
#include "Wad.h"
#include "Rumpff.h"
#include "Object.h";

using namespace SDLFramework;

class Level0 : public PhysEntity {
private:
	static Level0* sInstance;
	InputManager* mInput;

	Gump* mGump;
	Beanz* mBeanz;
	Wad* mWad;
	Rumpff* mRumpff;

	Object* mSpoon;
	Object* mSpoonTurned;
	Object* mWall;
	Object* mSugarCube;

	bool mTurnSpoon;

public:
	Level0();
	~Level0();

	static Level0* Instance();
	static void Release();

	Level0(Gump* Gump, Beanz* Beanz, Wad* wad, Rumpff* rumpff);

	void Update() override;
	void Render() override;

	void CollisionHandler();
};

#endif