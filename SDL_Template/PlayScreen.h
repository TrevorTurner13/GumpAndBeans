#ifndef __PLAYSCREEN_H
#define __PLAYSCREEN_H
#include "Timer.h"
#include "AudioManager.h"
#include "Gump.h"
#include "Beanz.h"

class PlayScreen : public GameEntity {
private:
	Timer * mTimer;
	AudioManager * mAudio;

	bool mGameOver;

	Gump * mGump;
	Beanz* mBeanz;
	Texture* mFloor;

	Texture* mBeanzJumpScare;

public:
	PlayScreen();
	~PlayScreen();

	void Update() override;
	void Render() override;
};
#endif