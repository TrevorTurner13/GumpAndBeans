#ifndef __BEANZ_H
#define __BEANZ_H
#include "Player.h"

using namespace SDLFramework;

class Beanz : public PhysEntity {
private:
	InputManager* mInput;
	AudioManager* mAudio;
	Timer* mTimer;

	AnimatedGLTexture* mBeanz;
	AnimatedGLTexture* mBeanzRight;
	AnimatedGLTexture* mBeanzLeft;
	AnimatedGLTexture* mBeanzUp;
	AnimatedGLTexture* mBeanzDown;

	float mMoveSpeed;
	Vector2 mMoveBounds;

private:
	void HandleMovement();
public:
	Beanz();
	~Beanz();

	void Update() override;
	void Render() override;
};

#endif