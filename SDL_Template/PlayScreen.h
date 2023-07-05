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

class PlayScreen : public GameEntity {
private:
	Level0* mLevel0;
	Level1* mLevel1;
	
	Timer * mTimer;
	AudioManager * mAudio;
	InputManager* mInput;

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