#pragma once
#ifndef __TUTORIALSCREEN_H
#define __TUTORIALSCREEN_H
#include "AnimatedGLTexture.h"
#include "InputManager.h"
#include "AudioManager.h"

using namespace SDLFramework;

class TutorialScreen : public GameEntity {

private:
	Texture* mMoveLeft;
	Texture* mMoveRight;
	Texture* mMoveUp;
	Texture* mMoveDown;
	

	Texture* mA;
	Texture* mD;
	Texture* mW;
	Texture* mS;
	
	GameEntity* mBottomBar;
	Texture* mNamco;
	Texture* mDates;
	Texture* mRights;

public:
	TutorialScreen();
	~TutorialScreen();

	void Update() override;
	void Render() override;
};
#endif