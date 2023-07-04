#ifndef __PLAYSCREEN_H
#define __PLAYSCREEN_H
#include "Timer.h"
#include "AudioManager.h"
#include "Gump.h"
#include "Beanz.h"
#include "Wad.h"
#include "Rumpff.h"

class PlayScreen : public GameEntity {
private:
	Timer * mTimer;
	AudioManager * mAudio;

	bool mGameOver;

	Gump * mGump;
	Beanz* mBeanz;
	Wad* mWad;
	Rumpff* mRumpff;

	Texture* mFloor;

	GLTexture* mSpoon;

	Texture* mBeanzJumpScare;
	Texture* mWadJumpScare;
	Texture* mRumpffJumpScare;
	float mJumpScareTimer;
	float mJumpScareTotalTime;
	float mJumpScareScale;
	bool mJumpScareDone;


public:
	PlayScreen();
	~PlayScreen();

	void Update() override;
	void Render() override;
};
#endif