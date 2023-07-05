#ifndef __FOREGROUND_H
#define __FOREGROUND_H
#include "GLTexture.h"
#include "AnimatedGLTexture.h"
#include "Player.h"
#include "Beanz.h"
#include "Gump.h"


using namespace SDLFramework;

class Level1 : public PhysEntity {
private:
	static Level1* sInstance;

	

public:

	static Level1* Instance();
	
	static void Release();
	
	Level1();
	
	~Level1();

	void Update();
	
	void Render();
	


};


#endif
