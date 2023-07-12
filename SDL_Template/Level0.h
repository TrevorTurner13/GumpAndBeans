#ifndef __LEVEL0_H
#define __LEVEL0_H
#include "InputManager.h"
#include "AudioManager.h"
#include "GLTexture.h"
#include "AnimatedGLTexture.h"
#include "Beanz.h"
#include "Gump.h"
#include "Object.h"

using namespace SDLFramework;

class Level0 : public PhysEntity {
public:
	enum Lore{ START = 0, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, END };
	Lore mCurrentLore;
private:
	InputManager* mInput;
	AudioManager* mAudio;

	Gump* mGump;
	Beanz* mBeanz;

	GLTexture* mMighteeSpeech;
	GLTexture* mBeanzSpeech;
	GLTexture* mGumpSpeech;

	GLTexture* mMiteDark;

	GLTexture* mPressSpace;
	GLTexture* mText1;
	GLTexture* mText2;
	GLTexture* mText3;
	GLTexture* mText4;
	GLTexture* mText5;
	GLTexture* mText6;
	GLTexture* mText7;
	GLTexture* mText8;
	GLTexture* mText9;
	GLTexture* mText10;
	GLTexture* mText11;
	GLTexture* mText12;
	GLTexture* mText13;
	GLTexture* mText14;
	GLTexture* mText15;
	GLTexture* mText16;
	GLTexture* mText17;
	GLTexture* mText18;
	GLTexture* mText19;
	GLTexture* mText20;

	AnimatedGLTexture* mMightee;
	AnimatedGLTexture* mLesserMite1;
	AnimatedGLTexture* mLesserMite2;
	AnimatedGLTexture* mLesserMite3;
	AnimatedGLTexture* mLesserMite4;
	AnimatedGLTexture* mLesserMite5;
	AnimatedGLTexture* mLesserMite6;
	AnimatedGLTexture* mLesserMite7;
	AnimatedGLTexture* mLesserMite8;

	Object* mTopWall1;
	Object* mTopWall2;
	Object* mTopWall3;
	Object* mTopWall4;
	Object* mTopWall5;
	Object* mTopWall6;
	Object* mTopWall7;
	Object* mTopWall8;
	Object* mWallLeftCorner;
	Object* mSideWall1;
	Object* mSideWall2;
	Object* mSideWall3;
	Object* mSideWall4;
	Object* mSideWall5;
	Object* mSideWall6;
	Object* mSideWall7;

	Object* mDustBlob1;
	Object* mDustBlob2;
	Object* mDustBlob3;
	Object* mDustBlob4;
	Object* mDustBlob5;
	Object* mDustBlob6;

	GLTexture* mThePile;

	Object* mToyCar1;
	Object* mToyCar2;

	AnimatedGLTexture* mCandle1;
	AnimatedGLTexture* mCandle2;
	AnimatedGLTexture* mCandle3;
	AnimatedGLTexture* mCandle4;
	AnimatedGLTexture* mCandle5;
	AnimatedGLTexture* mCandle6;
	AnimatedGLTexture* mCandle7;
	AnimatedGLTexture* mCandle8;

	GLTexture* mBottleCap1;
	GLTexture* mBottleCap2;
	GLTexture* mBottleCap3;
	GLTexture* mBottleCap4;

	Object* mSugarCube1;
	GLTexture* mBottleCap;
	GLTexture*mMarble;

public:
	~Level0();

	Level0(Gump* Gump, Beanz* Beanz);

	void Update() override;
	void Render() override;

	void CollisionHandler();
};

#endif