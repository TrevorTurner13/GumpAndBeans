#pragma once
 #ifndef __RUMPFF_H
#define __RUMPFF_H

#include "AnimatedGLTexture.h"
#include "PhysEntity.h"
#include "InputManager.h"
#include "Timer.h"
#include "AudioManager.h"

using namespace SDLFramework;

class Rumpff : public PhysEntity {
private:

	InputManager* mInput;
	AudioManager* mAudio;
	Timer* mTimer;

	AnimatedGLTexture* mRumpffRight;
	AnimatedGLTexture* mRumpffLeft;
	AnimatedGLTexture* mRumpff;

	float mMoveSpeed;
	float mMoveTime;
	int mMoveDirection;

	Vector2 mMoveBounds;

private:
	

public:
	Rumpff();
	~Rumpff();

	void RumpffMovement();

	void Update() override;
	void Render() override;
};

#endif