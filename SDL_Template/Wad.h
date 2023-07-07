#ifndef __WAD_H
#define __WAD_H

#include "AnimatedGLTexture.h"
#include "PhysEntity.h"
#include "InputManager.h"
#include "Timer.h"
#include "AudioManager.h"

using namespace SDLFramework;

class Wad : public PhysEntity {
private:

	InputManager* mInput;
	AudioManager* mAudio;
	Timer* mTimer;

	AnimatedGLTexture* mWadUp;
	AnimatedGLTexture* mWadDown;
	AnimatedGLTexture* mWad;

	float mMoveSpeed;
	float mMoveTime;
	float mMoveTimeMax;
	int mMoveDirection;

	Vector2 mMoveBounds;

private:
	

public:
	Wad();
	~Wad();

	void WadMovement();
	void SetMoveTimeMax(float change);
	
	void Update() override;
	void Render() override;
};

#endif
