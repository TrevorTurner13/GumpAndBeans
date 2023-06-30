#ifndef __GUMP_H
#define __GUMP_H
#include "Player.h"
#include "InputManager.h"
#include "Timer.h"
#include "AudioManager.h"

using namespace SDLFramework;

class Gump : public Player {
private:
	InputManager* mInput;
	AudioManager* mAudio;
	Timer* mTimer;

	AnimatedGLTexture* mGump;
	AnimatedGLTexture* mGumpRight;
	AnimatedGLTexture* mGumpLeft;
	AnimatedGLTexture* mGumpUp;
	AnimatedGLTexture* mGumpDown;

	int mGumpStrength;

	Vector2 mLastPosition;

	float mMoveSpeed;
	Vector2 mMoveBounds;

private:
	void HandleMovement();

public:
	Gump();
	~Gump();

	void Update() override;
	void Render() override;
};

#endif
