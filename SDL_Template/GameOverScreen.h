#ifndef __GAMEOVERSCREEN_H
#define __GAMEOVERSCREEN_H
#include "PlayScreen.h"

class GameOverScreen : public GameEntity {
private:
	Timer* mTimer;
	AudioManager* mAudio;
	InputManager* mInput;

	AnimatedGLTexture* mGameOverBeanz;
	//AnimatedGLTexture* mGameOverWad;
	//AnimatedGLTexture* mGameOverRumpff;
public:
	GameOverScreen();
	~GameOverScreen();

	void Update() override;
	void Render() override;
};


#endif