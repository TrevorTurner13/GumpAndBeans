#ifndef __PLAYSCREEN_H
#define __PLAYSCREEN_H
#include "Timer.h"
#include "AudioManager.h"
#include "Gump.h"
#include "Beanz.h"
#include "Wad.h"
#include "Rumpff.h"
#include "Object.h"
#include "Level0.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"

class PlayScreen : public GameEntity {
private:
	Level0* mLevel0;
	Level1* mLevel1;
	Level2* mLevel2;
	Level3* mLevel3;
	
	Timer * mTimer;
	AudioManager * mAudio;
	InputManager* mInput;

	GLTexture* mCollection;

	AnimatedGLTexture* mFadeOut;
	AnimatedGLTexture* mFadeIn;

	bool mGameOver;
	bool mGameOverBeanz;
	bool mGameOverWad;
	bool mGameOverRumpff;

	Gump * mGump;
	Beanz* mBeanz;
	Wad* mWad;
	Rumpff* mRumpff;

	Texture* mFloor;

	Texture* mBeanzJumpScare;
	Texture* mWadJumpScare;
	Texture* mRumpffJumpScare;
	float mJumpScareTimer;
	float mJumpScareTotalTime;
	float mJumpScareScale;
	bool mJumpScareDone;

	float mFadeTimer;
	float mFadeTotalTime;
	bool mFadeDone;

	int mLevel;

public:
	PlayScreen();
	~PlayScreen();

	void JumpScareHandler();

	bool GetGameOver() { return mGameOver; }
	bool GetGameOverBeanz() { return mGameOverBeanz; }
	bool GetGameOverWad() { return mGameOverWad; }
	bool GetGameOverRumpff() { return mGameOverRumpff; }
	bool GetJumpScareDone() { return mJumpScareDone; }

	void Update() override;
	void Render() override;
};
#endif