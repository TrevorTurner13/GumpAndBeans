#ifndef __LEVEL1_H
#define __Level1_H
#include "InputManager.h"
#include "GLTexture.h"
#include "AnimatedGLTexture.h"
#include "Beanz.h"
#include "Gump.h"
#include "Object.h";

using namespace SDLFramework;

class Level1 : public PhysEntity {
private:
	InputManager* mInput;

	static Level1* sInstance;

	Object* mSugarCube;

	Gump* mGump;
	Beanz* mBeanz;
	

public:
	Level1(Gump* Gump, Beanz* Beanz);
	Level1();
	~Level1();

	static Level1* Instance();
	static void Release();

	void Update();
	void Render();
	
	void CollisionHandler();

};


#endif
