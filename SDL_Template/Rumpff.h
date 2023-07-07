#ifndef __RUMPFF_H
#define __RUMPFF_H

#include "AnimatedGLTexture.h"
#include "PhysEntity.h"
#include "InputManager.h"
#include "Timer.h"
#include "AudioManager.h"

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
	float mMoveTimeMax;
	int mMoveDirection;

	Vector2 mMoveBounds;

private:
	

public:
	Rumpff();
	~Rumpff();

	void RumpffMovement();
	void SetMoveTimeMax(float change);

	void Update() override;
	void Render() override;
};

#endif