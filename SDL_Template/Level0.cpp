#include "Level0.h"

Level0::Level0(Gump* Gump, Beanz* Beanz) {
	mInput = InputManager::Instance();

	mCurrentLore = START;

	mGump = Gump;
	mBeanz = Beanz;

	mGump->Active(false);
	mBeanz->Active(false);

	mMighteeSpeech = new GLTexture("Speech Bubbles.png", 0, 0, 512, 112);
	mBeanzSpeech = new GLTexture("Speech Bubbles.png", 0, 112, 512, 112);
	mGumpSpeech = new GLTexture("Speech Bubbles.png", 0, 224, 512, 112);

	mMighteeSpeech->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.9f));
	mBeanzSpeech->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.9f));
	mGumpSpeech->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.9f));

	mPressSpace = new GLTexture("Press Space to Continue", "ARCADE.TTF", 25, { 250,250,250 });
	mPressSpace->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.95f));

	mText1 = new GLTexture("Migthtee: Gump, Beanz, Why you here?", "ARCADE.TTF", 20, { 250, 250, 250 });
	mText1->Position(Vector2(Graphics::SCREEN_WIDTH * 0.55f, Graphics::SCREEN_HEIGHT * 0.87f));

	mText2 = new GLTexture("You come to add to The Pile?", "ARCADE.TTF", 20, { 250, 250, 250 });
	mText2->Position(Vector2(Graphics::SCREEN_WIDTH * 0.55f, Graphics::SCREEN_HEIGHT * 0.89f));

	mText3 = new GLTexture("Great Oombra demands gifts!", "ARCADE.TTF", 20, { 250, 250, 250 });
	mText3->Position(Vector2(Graphics::SCREEN_WIDTH * 0.55f, Graphics::SCREEN_HEIGHT * 0.91f));

	mText4 = new GLTexture("Gump: We'z seeks path beyond OondaFreej", "ARCADE.TTF", 20, { 250, 250, 250 });
	mText4->Position(Vector2(Graphics::SCREEN_WIDTH * 0.52f, Graphics::SCREEN_HEIGHT * 0.89f));
	
	mText5 = new GLTexture("Into lights of Keechin", "ARCADE.TTF", 20, { 250, 250, 250 });
	mText5->Position(Vector2(Graphics::SCREEN_WIDTH * 0.52f, Graphics::SCREEN_HEIGHT * 0.91f));

	mText6 = new GLTexture("Beanz: Heh Heh, Yeah Boi", "ARCADE.TTF", 20, { 250, 250, 250 });
	mText6->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.9f));

	mText7 = new GLTexture("Gump: Great Mightee of Mites", "ARCADE.TTF", 20, { 250, 250, 250 });
	mText7->Position(Vector2(Graphics::SCREEN_WIDTH * 0.52f, Graphics::SCREEN_HEIGHT * 0.89f));
	
	mText8 = new GLTexture("will show way beyond?", "ARCADE.TTF", 20, { 250, 250, 250 });
	mText8->Position(Vector2(Graphics::SCREEN_WIDTH * 0.52f, Graphics::SCREEN_HEIGHT * 0.91f));

	mMightee = new AnimatedGLTexture("Mightee.png", 0, 64, 64, 64, 1, 1.0f, Animation::Layouts::Horizontal);
	mMightee->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.3f));
	mMightee->Scale(Vector2(1.5f, 1.5f));

	mLesserMite1 = new AnimatedGLTexture("Mightee.png", 0, 64, 64, 64, 1, 1.0f, Animation::Layouts::Horizontal);
	mLesserMite2 = new AnimatedGLTexture("Mightee.png", 0, 64, 64, 64, 1, 1.0f, Animation::Layouts::Horizontal);
	mLesserMite3 = new AnimatedGLTexture("Mightee.png", 0, 64, 64, 64, 1, 1.0f, Animation::Layouts::Horizontal);
	mLesserMite4 = new AnimatedGLTexture("Mightee.png", 0, 64, 64, 64, 1, 1.0f, Animation::Layouts::Horizontal);
	mLesserMite5 = new AnimatedGLTexture("Mightee.png", 0, 64, 64, 64, 1, 1.0f, Animation::Layouts::Horizontal);
	mLesserMite6 = new AnimatedGLTexture("Mightee.png", 0, 64, 64, 64, 1, 1.0f, Animation::Layouts::Horizontal);
	mLesserMite7 = new AnimatedGLTexture("Mightee.png", 0, 64, 64, 64, 1, 1.0f, Animation::Layouts::Horizontal);
	mLesserMite8 = new AnimatedGLTexture("Mightee.png", 0, 64, 64, 64, 1, 1.0f, Animation::Layouts::Horizontal);

	mLesserMite1->Position(Vector2(Graphics::SCREEN_WIDTH * 0.3f, Graphics::SCREEN_HEIGHT * 0.4f));
	mLesserMite2->Position(Vector2(Graphics::SCREEN_WIDTH * 0.7f, Graphics::SCREEN_HEIGHT * 0.4f));
	mLesserMite3->Position(Vector2(Graphics::SCREEN_WIDTH * 0.9f, Graphics::SCREEN_HEIGHT * 0.9f));
	mLesserMite4->Position(Vector2(Graphics::SCREEN_WIDTH * 0.1f, Graphics::SCREEN_HEIGHT * 0.9f));
	mLesserMite5->Position(Vector2(Graphics::SCREEN_WIDTH * 0.28f, Graphics::SCREEN_HEIGHT * 0.6f));
	mLesserMite6->Position(Vector2(Graphics::SCREEN_WIDTH * 0.72f, Graphics::SCREEN_HEIGHT * 0.6f));
	mLesserMite7->Position(Vector2(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.8f));
	mLesserMite8->Position(Vector2(Graphics::SCREEN_WIDTH * 0.75f, Graphics::SCREEN_HEIGHT * 0.8f));

	mTopWall1 = new Object(new GLTexture("Walls 128x128.png", 128, 0, 128, 128), new BoxCollider(Vector2(128.0f, 128.0f)), 1000, 1000);
	mTopWall2 = new Object(new GLTexture("Walls 128x128.png", 128, 0, 128, 128), new BoxCollider(Vector2(128.0f, 128.0f)), 1000, 1000);
	mTopWall3 = new Object(new GLTexture("Walls 128x128.png", 128, 0, 128, 128), new BoxCollider(Vector2(128.0f, 128.0f)), 1000, 1000);
	mTopWall4 = new Object(new GLTexture("Walls 128x128.png", 128, 0, 128, 128), new BoxCollider(Vector2(128.0f, 128.0f)), 1000, 1000);
	mTopWall5 = new Object(new GLTexture("Walls 128x128.png", 128, 0, 128, 128), new BoxCollider(Vector2(128.0f, 128.0f)), 1000, 1000);
	mTopWall6 = new Object(new GLTexture("Walls 128x128.png", 128, 0, 128, 128), new BoxCollider(Vector2(128.0f, 128.0f)), 1000, 1000);
	mTopWall7 = new Object(new GLTexture("Walls 128x128.png", 128, 0, 128, 128), new BoxCollider(Vector2(128.0f, 128.0f)), 1000, 1000);
	mTopWall8 = new Object(new GLTexture("Walls 128x128.png", 128, 0, 128, 128), new BoxCollider(Vector2(128.0f, 128.0f)), 1000, 1000);
	mWallLeftCorner = new Object(new GLTexture("Walls 128x128.png", 0, 0, 128, 128), new BoxCollider(Vector2(128.0f, 128.0f)), 1000, 1000);
	mSideWall1 = new Object(new GLTexture("Walls 128x128.png", 0, 128, 128, 128), new BoxCollider(Vector2(128.0f, 128.0f)), 1000, 1000);
	mSideWall2 = new Object(new GLTexture("Walls 128x128.png", 0, 128, 128, 128), new BoxCollider(Vector2(128.0f, 128.0f)), 1000, 1000);
	mSideWall3 = new Object(new GLTexture("Walls 128x128.png", 0, 128, 128, 128), new BoxCollider(Vector2(128.0f, 128.0f)), 1000, 1000);
	mSideWall4 = new Object(new GLTexture("Walls 128x128.png", 0, 128, 128, 128), new BoxCollider(Vector2(128.0f, 128.0f)), 1000, 1000);
	mSideWall5 = new Object(new GLTexture("Walls 128x128.png", 0, 128, 128, 128), new BoxCollider(Vector2(128.0f, 128.0f)), 1000, 1000);
	mSideWall6 = new Object(new GLTexture("Walls 128x128.png", 0, 128, 128, 128), new BoxCollider(Vector2(128.0f, 128.0f)), 1000, 1000);
	mSideWall7 = new Object(new GLTexture("Walls 128x128.png", 0, 128, 128, 128), new BoxCollider(Vector2(128.0f, 128.0f)), 1000, 1000);

	mTopWall1->Position(Vector2(128.0f, 0.0f));
	mTopWall2->Position(Vector2(256.0f, 0.0f));
	mTopWall3->Position(Vector2(384.0f, 0.0f));
	mTopWall4->Position(Vector2(512.0f, 0.0f));
	mTopWall5->Position(Vector2(640.0f, 0.0f));
	mTopWall6->Position(Vector2(768.0f, 0.0f));
	mTopWall7->Position(Vector2(895.0f, 0.0f));
	mTopWall8->Position(Vector2(1023.0f, 0.0f));
	mWallLeftCorner->Position(Vector2(0.0f, 0.0f));
	mSideWall1->Position(Vector2(0.0f, 128.0f));
	mSideWall2->Position(Vector2(0.0f, 256.0f));
	mSideWall3->Position(Vector2(0.0f, 384.0f));
	mSideWall4->Position(Vector2(0.0f, 512.0f));
	mSideWall5->Position(Vector2(0.0f, 640.0f));
	mSideWall6->Position(Vector2(0.0f, 768.0f));
	mSideWall7->Position(Vector2(0.0f, 895.0f));

	mDustBlob1 = new Object(new GLTexture("DustWallBlob1 256x256.png", 0, 0, 320, 160), new BoxCollider(Vector2(220.0f, 200.0f)), 1000, 1000);
	mDustBlob2 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(200.0f, 256.0f)), 1000, 1000);
	mDustBlob3 = new Object(new GLTexture("DustWallBlob1 256x256.png", 0, 0, 320, 160), new BoxCollider(Vector2(220.0f, 200.0f)), 1000, 1000);
	mDustBlob4 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(200.0f, 256.0f)), 1000, 1000);
	mDustBlob5 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(200.0f, 256.0f)), 1000, 1000);
	mDustBlob6 = new Object(new GLTexture("DustWallVertical1 256x256.png", 0, 0, 256, 256), new BoxCollider(Vector2(200.0f, 256.0f)), 1000, 1000);

	mDustBlob1->Position(Vector2(180.0f, 100.0f));
	mDustBlob2->Position(Vector2(130.0f, 250.0f));
	mDustBlob3->Position(Vector2(900.0f, 100.0f));
	mDustBlob4->Position(Vector2(950.0f, 250.0f));
	mDustBlob5->Position(Vector2(130.0f, 500.0f));
	mDustBlob6->Position(Vector2(950.0f, 500.0f));

	mThePile = new GLTexture("ThePile.png", 0, 0, 768, 272);
	mThePile->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.3f));


	mToyCar1 = new Object(new GLTexture("ToyCar.png", 0, 0, 128, 128), new BoxCollider(Vector2(100.0f, 100.0f)), 1000, 1000);
	mToyCar2 = new Object(new GLTexture("ToyCar.png", 128, 0, 128, 128), new BoxCollider(Vector2(100.0f, 100.0f)), 1000, 1000);;

	mToyCar1->Position(Vector2(384.0f, 256.0f));
	mToyCar2->Position(Vector2(640.0f, 256.0f));
	mToyCar1->RotateTexture(180.0f);

	mCandle1 = new AnimatedGLTexture("Lit Candles 64x64.png", 0, 0, 64, 64, 5, 1.0f, Animation::Layouts::Vertical);
	mCandle2 = new AnimatedGLTexture("Lit Candles 64x64.png", 64, 0, 64, 64, 5, 1.0f, Animation::Layouts::Vertical);
	mCandle3 = new AnimatedGLTexture("Lit Candles 64x64.png", 0, 0, 64, 64, 5, 1.0f, Animation::Layouts::Vertical);
	mCandle4 = new AnimatedGLTexture("Lit Candles 64x64.png", 64, 0, 64, 64, 5, 1.0f, Animation::Layouts::Vertical);
	mCandle5 = new AnimatedGLTexture("Lit Candles 64x64.png", 0, 0, 64, 64, 5, 1.0f, Animation::Layouts::Vertical);
	mCandle6 = new AnimatedGLTexture("Lit Candles 64x64.png", 64, 0, 64, 64, 5, 1.0f, Animation::Layouts::Vertical);
	mCandle7 = new AnimatedGLTexture("Lit Candles 64x64.png", 0, 0, 64, 64, 5, 1.0f, Animation::Layouts::Vertical);
	mCandle8 = new AnimatedGLTexture("Lit Candles 64x64.png", 64, 0, 64, 64, 5, 1.0f, Animation::Layouts::Vertical);

	mBottleCap1 = new GLTexture("Crumbs.png", 640, 64, 64, 64);
	mBottleCap2 = new GLTexture("Crumbs.png", 640, 64, 64, 64);
	mBottleCap3 = new GLTexture("Crumbs.png", 640, 64, 64, 64);
	mBottleCap4 = new GLTexture("Crumbs.png", 640, 64, 64, 64);

	mCandle1->Position(Vector2(Graphics::SCREEN_WIDTH * 0.45f, Graphics::SCREEN_HEIGHT * 0.2f));
	mCandle2->Position(Vector2(Graphics::SCREEN_WIDTH * 0.55f, Graphics::SCREEN_HEIGHT * 0.2f));
	mCandle3->Position(Vector2(Graphics::SCREEN_WIDTH * 0.48f, Graphics::SCREEN_HEIGHT * 0.15f));
	mCandle4->Position(Vector2(Graphics::SCREEN_WIDTH * 0.52f, Graphics::SCREEN_HEIGHT * 0.15f));
	mCandle5->Position(Vector2(Graphics::SCREEN_WIDTH * 0.28f, Graphics::SCREEN_HEIGHT * 0.5f));
	mCandle6->Position(Vector2(Graphics::SCREEN_WIDTH * 0.72f, Graphics::SCREEN_HEIGHT * 0.5f));
	mCandle7->Position(Vector2(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.7f));
	mCandle8->Position(Vector2(Graphics::SCREEN_WIDTH * 0.75f, Graphics::SCREEN_HEIGHT * 0.7f));

	mBottleCap1->Position(Vector2(Graphics::SCREEN_WIDTH * 0.28f, Graphics::SCREEN_HEIGHT * 0.53f));
	mBottleCap2->Position(Vector2(Graphics::SCREEN_WIDTH * 0.72f, Graphics::SCREEN_HEIGHT * 0.53f));
	mBottleCap3->Position(Vector2(Graphics::SCREEN_WIDTH * 0.25f, Graphics::SCREEN_HEIGHT * 0.73f));
	mBottleCap4->Position(Vector2(Graphics::SCREEN_WIDTH * 0.75f, Graphics::SCREEN_HEIGHT * 0.73f));

	mSugarCube1 = new Object(new GLTexture("sugar cube 64x64.png", 0, 0, 64, 64), new BoxCollider(Vector2(64.0f, 64.0f)), 30, 30);
	mBottleCap = new GLTexture("Crumbs.png", 640, 64, 64, 64);
	mMarble = new GLTexture("Crumbs.png", 448, 0, 64, 64);

	mSugarCube1->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.2f));
	mBottleCap->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f - 2.0f, Graphics::SCREEN_HEIGHT * 0.2f - 20.0f));
	mMarble->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f - 1.0f, Graphics::SCREEN_HEIGHT * 0.2f - 30.0f));
	mBottleCap->Parent(mSugarCube1);
	mMarble->Parent(mSugarCube1);

}

Level0::~Level0() {
	delete mMarble;
	mMarble = nullptr;

	delete mBottleCap;
	mBottleCap = nullptr;

	delete mSugarCube1;
	mSugarCube1 = nullptr;

	delete mBottleCap1;
	mBottleCap1 = nullptr;
	delete mBottleCap2;
	mBottleCap2 = nullptr;
	delete mBottleCap3;
	mBottleCap3 = nullptr;
	delete mBottleCap4;
	mBottleCap4 = nullptr;

	delete mCandle1;
	mCandle1 = nullptr;
	delete mCandle2;
	mCandle2 = nullptr;
	delete mCandle3;
	mCandle3 = nullptr;
	delete mCandle4;
	mCandle4 = nullptr;
	delete mCandle5;
	mCandle5 = nullptr;
	delete mCandle6;
	mCandle6 = nullptr;
	delete mCandle7;
	mCandle7 = nullptr;
	delete mCandle8;
	mCandle8 = nullptr;

	delete mToyCar1;
	mToyCar1 = nullptr;
	delete mToyCar2;
	mToyCar2 = nullptr;

	delete mThePile;
	mThePile = nullptr;

	delete mDustBlob1;
	mDustBlob1 = nullptr;
	delete mDustBlob2;
	mDustBlob2 = nullptr;
	delete mDustBlob3;
	mDustBlob3 = nullptr;
	delete mDustBlob4;
	mDustBlob4 = nullptr;
	delete mDustBlob5;
	mDustBlob5 = nullptr;
	delete mDustBlob6;
	mDustBlob6 = nullptr;

	delete mSideWall1;
	mSideWall1 = nullptr;
	delete mSideWall2;
	mSideWall2 = nullptr;
	delete mSideWall3;
	mSideWall3 = nullptr;
	delete mSideWall4;
	mSideWall4 = nullptr;
	delete mSideWall5;
	mSideWall5 = nullptr;
	delete mSideWall6;
	mSideWall6 = nullptr;
	delete mSideWall7;
	mSideWall7 = nullptr;

	delete mWallLeftCorner;
	mWallLeftCorner = nullptr;

	delete mTopWall1;
	mTopWall1 = nullptr;
	delete mTopWall2;
	mTopWall2 = nullptr;
	delete mTopWall3;
	mTopWall3 = nullptr;
	delete mTopWall4;
	mTopWall4 = nullptr;
	delete mTopWall5;
	mTopWall5 = nullptr;
	delete mTopWall6;
	mTopWall6 = nullptr;
	delete mTopWall7;
	mTopWall7 = nullptr;
	delete mTopWall8;
	mTopWall8 = nullptr;

	delete mLesserMite1;
	mLesserMite1 = nullptr;
	delete mLesserMite2;
	mLesserMite2 = nullptr;
	delete mLesserMite3;
	mLesserMite3 = nullptr;
	delete mLesserMite4;
	mLesserMite4 = nullptr;
	delete mLesserMite5;
	mLesserMite5 = nullptr;
	delete mLesserMite6;
	mLesserMite6 = nullptr;
	delete mLesserMite7;
	mLesserMite7 = nullptr;
	delete mLesserMite8;
	mLesserMite8 = nullptr;

	delete mMightee;
	mMightee = nullptr;

	delete mMighteeSpeech;
	mMighteeSpeech = nullptr;
	delete mBeanzSpeech;
	mBeanzSpeech = nullptr;
	delete mGumpSpeech;
	mGumpSpeech = nullptr;
}

void Level0::Update() {

	mBeanz->Update();
	mGump->Update();

	mCandle1->Update();
	mCandle2->Update();
	mCandle3->Update();
	mCandle4->Update();
	mCandle5->Update();
	mCandle6->Update();
	mCandle7->Update();
	mCandle8->Update();

	switch (mCurrentLore) {
	case START:
		if (mInput->KeyPressed(SDL_SCANCODE_SPACE)) {
			mCurrentLore = ONE;
		}
		break;
	case ONE:
		if (mInput->KeyPressed(SDL_SCANCODE_SPACE)) {
			mCurrentLore = TWO;
		}
		break;
	case TWO:
		if (mInput->KeyPressed(SDL_SCANCODE_SPACE)) {
			mCurrentLore = THREE;
		}
		break;
	case THREE:
		if (mInput->KeyPressed(SDL_SCANCODE_SPACE)) {
			mCurrentLore = FOUR;
		}
		break;
	case FOUR:
		if (mInput->KeyPressed(SDL_SCANCODE_SPACE)) {
			mCurrentLore = FIVE;
		}
		break;
	case FIVE:
		if (mInput->KeyPressed(SDL_SCANCODE_SPACE)) {
			mCurrentLore = SIX;
		}
		break;
	case SIX:
		if (mInput->KeyPressed(SDL_SCANCODE_SPACE)) {
			mCurrentLore = SEVEN;
		}
		break;
	case SEVEN:
		if (mInput->KeyPressed(SDL_SCANCODE_SPACE)) {
			mCurrentLore = EIGHT;
		}
		break;
	case EIGHT:
		if (mInput->KeyPressed(SDL_SCANCODE_SPACE)) {
			mCurrentLore = NINE;
		}
		break;
	case NINE:
		if (mInput->KeyPressed(SDL_SCANCODE_SPACE)) {
			mCurrentLore = TEN;
		}
		break;
	case TEN:
		if (mInput->KeyPressed(SDL_SCANCODE_SPACE)) {
			mCurrentLore = END;
		}
		break;
	}

}

void Level0::Render() {
	mTopWall1->Render();
	mTopWall2->Render();
	mTopWall3->Render();
	mTopWall4->Render();
	mTopWall5->Render();
	mTopWall6->Render();
	mTopWall7->Render();
	mTopWall8->Render();
	mWallLeftCorner->Render();
	mSideWall1->Render();
	mSideWall2->Render();
	mSideWall3->Render();
	mSideWall4->Render();
	mSideWall5->Render();
	mSideWall6->Render();
	mSideWall7->Render();

	mThePile->Render();

	mDustBlob1->Render();
	mDustBlob2->Render();
	mDustBlob3->Render();
	mDustBlob4->Render();
	mDustBlob5->Render();
	mDustBlob6->Render();

	mToyCar1->Render();
	mToyCar2->Render();

	mBottleCap1->Render();
	mBottleCap2->Render();
	mBottleCap3->Render();
	mBottleCap4->Render();

	mCandle1->Render();
	mCandle2->Render();
	mCandle3->Render();
	mCandle4->Render();
	mCandle5->Render();
	mCandle6->Render();
	mCandle7->Render();
	mCandle8->Render();

	mLesserMite1->Render();
	mLesserMite2->Render();
	mLesserMite3->Render();
	mLesserMite4->Render();
	mLesserMite5->Render();
	mLesserMite6->Render();
	mLesserMite7->Render();
	mLesserMite8->Render();

	mSugarCube1->Render();
	mBottleCap->Render();
	mMarble->Render();

	mGump->Render();
	mBeanz->Render();
	mMightee->Render();
	switch (mCurrentLore) {
	case START:
		mMighteeSpeech->Render();
		mText1->Render();
		mText2->Render();
		mText3->Render();
		break;
	case ONE:
		mGumpSpeech->Render();
		mText4->Render();
		mText5->Render();
		break;
	case TWO:
		mBeanzSpeech->Render();
		mText6->Render();
		break;
	case THREE:
		mGumpSpeech->Render();
		mText7->Render();
		mText8->Render();
		break;
	case FOUR:
		mBeanzSpeech->Render();
		break;
	case FIVE:
		
		break;
	case SIX:
		mMighteeSpeech->Render();
		break;
	case SEVEN:
		mBeanzSpeech->Render();
		break;
	case EIGHT:
		mGumpSpeech->Render();
		break;
	case NINE:
		mMighteeSpeech->Render();
		break;
	case TEN:
		mBeanzSpeech->Render();
		break;
	}
	mPressSpace->Render();
}

void Level0::CollisionHandler() {
	
}