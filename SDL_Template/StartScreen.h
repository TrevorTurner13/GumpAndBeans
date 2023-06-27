#ifndef __STARTSCREEN_H
#define __STARTSCREEN_H
#include "AnimatedGLTexture.h"
#include "InputManager.h"
#include "Scoreboard.h"
#include "AudioManager.h"

using namespace SDLFramework;

class StartScreen : public GameEntity {

private:
	Timer* mTimer;
	InputManager* mInput;
	AudioManager* mAudio;


	GLTexture* mFloor;

	// Top Bar Entities
	GameEntity* mTopBar;

	// Logo Entities
	Texture* mLogo;
	AnimatedGLTexture* mAnimatedLogo;
	AnimatedGLTexture* mGump;
	AnimatedGLTexture* mBeanz;

	// Play Mode Entities
	GameEntity* mPlayModes;
	Texture* mOnePlayerMode;
	Texture* mTwoPlayerMode;
	Texture* mPlayDefault;
	Texture* mPlayHighlight;
	Texture* mHowToPlayHighlight;
	Texture* mHowToPlayDefault;
	int mSelectedMode;

	// Bottom Bar Entities
	GameEntity* mBottomBar;
	Texture* mNamco;
	Texture* mDates;
	Texture* mRights;
	Texture* mNamcoOutline;
	Texture* mDatesOutline;
	Texture* mRightsOutline;

	// Screen Animation Variables
	Vector2 mAnimationStartPos;
	Vector2 mAnimationEndPos;
	float mAnimationTotalTime;
	float mAnimationTimer;
	bool mAnimationDone;

	// stars
	//BackgroundStars* mStars;

	float mBackgroundColor;


public:
	StartScreen();
	~StartScreen();

	void ResetAnimation();

	int SelectedMode();

	void ChangeSelectedMode(int change);

	void Update() override;
	void Render() override;

};
#endif