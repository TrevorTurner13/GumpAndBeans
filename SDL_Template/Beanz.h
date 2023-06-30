#ifndef __BEANZ_H
#define __BEANZ_H
#include "Player.h"
#include "Gump.h"

using namespace SDLFramework;

class Beanz : public PhysEntity {
private:
	InputManager* mInput;
	AudioManager* mAudio;
	Timer* mTimer;
	Gump* mGump;

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
	Beanz(Gump* gump);
	~Beanz();

	Vector2 DirectionToGump();

	void Update() override;
	void Render() override;
};

#endif