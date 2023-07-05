#ifndef __PLAYSCREEN_H
#define __PLAYSCREEN_H
#include "Timer.h"
#include "AudioManager.h"
#include "Gump.h"
#include "Beanz.h"
#include "Wad.h"
#include "Rumpff.h"

#include "Level1.h"

class PlayScreen : public GameEntity {
private:
	Level1* mLevel1;
	
	Timer * mTimer;
	AudioManager * mAudio;
	InputManager* mInput;

	bool mGameOver;
	bool mTurnSpoon;

	Gump * mGump;
	Beanz* mBeanz;
	Wad* mWad;
	Rumpff* mRumpff;

	Texture* mFloor;

	Object* mSpoon;
	Object* mSpoonTurned;
	Object* mWall;
	Object* mSugarCube;

	Texture* mBeanzJumpScare;
	Texture* mWadJumpScare;
	Texture* mRumpffJumpScare;
	float mJumpScareTimer;
	float mJumpScareTotalTime;
	float mJumpScareScale;
	bool mJumpScareDone;

	int mLevel;


public:
	PlayScreen();
	~PlayScreen();

	void CollisionHandler();
	void JumpScareHandler();

	void Update() override;
	void Render() override;
};
#endif