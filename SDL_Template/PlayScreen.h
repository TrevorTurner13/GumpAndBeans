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

	Gump * mGump;
	Beanz* mBeanz;
	Texture* mFloor;

public:
	PlayScreen();
	~PlayScreen();

	void Update() override;
	void Render() override;
};
#endif