#ifndef __GAMEOVERSCREEN_H
#define __GAMEOVERSCREEN_H
#include "PlayScreen.h"

class GameOverScreen : public GameEntity {
private:
	Timer* mTimer;
	AudioManager* mAudio;
	InputManager* mInput;

	PlayScreen* mPlayScreen;

	AnimatedGLTexture* mGameOverBeanz;
	//AnimatedGLTexture* mGameOverWad;
	AnimatedGLTexture* mGameOverRumpff;

	Texture* mOnePlayerMode;
	Texture* mTwoPlayerMode;
	Texture* mRetry;
	Texture* mRetryHighlight;
	Texture* mQuit;
	Texture* mQuitHighlight;
	Texture* mGameOverText;
	
	int mSelectedMode;
public:
	GameOverScreen(PlayScreen* playScreen);
	~GameOverScreen();

	int SelectedMode();

	void ChangeSelectedMode(int change);

	void Update() override;
	void Render() override;
};


#endif