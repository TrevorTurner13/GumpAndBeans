#ifndef __SCREENMANAGER_H
#define __SCREENMANAGER_H
#include "StartScreen.h"
#include "PlayScreen.h"
#include "TutorialScreen.h"

class ScreenManager {
private:
	static ScreenManager * sInstance;

	enum Screens { Start, Play, Tutorial };
	Screens mCurrentScreen;

	InputManager * mInput;

	StartScreen * mStartScreen;
	PlayScreen * mPlayScreen;
	TutorialScreen* mTutorialScreen; 

public:
	static ScreenManager * Instance();
	static void Release();

	void Update();
	void Render();
	void RenderRepeatedTexture(Texture* texture, int textureWidth, int textureHeight);

private:
	ScreenManager();
	~ScreenManager();
};
#endif