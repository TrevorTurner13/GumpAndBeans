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

	GLTexture* mSpoon;

	Texture* mBeanzJumpScare;
	float mJumpScareTimer;
	float mJumpScareTotalTime;
	float mJumpScareScale;
	bool mJumpScareDone;


public:
	PlayScreen();
	~PlayScreen();

	bool CheckGumpCollision(Gump* player, GLTexture* object);
	bool CheckBeanzCollision(Beanz* player, GLTexture* object);
	void ResolvePushCollision(Player* player, GLTexture* block);
	bool VerticallyAligned(Player* player, GLTexture* object);
	bool HorizontallyAligned(Player* player, GLTexture* object);

	void Update() override;
	void Render() override;
};
#endif